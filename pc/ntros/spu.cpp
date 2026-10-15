// The DS sound hardware (GBATEK "DS Sound"): 16 channels (PCM8, PCM16, IMA-ADPCM on all of them; square waves on
// 8..13, noise on 14..15), two capture units, the mixer with master volume, output selection and bias. Only the
// ARM7's sound driver (sound_*.cpp) touches it, through the Spu_* accessors (register offsets from 0x04000400; the
// source and destination addresses are host pointers).
//
// It runs on the DS clock: Spu_RunTo(cycles) produces the output up to that time, one stereo sample every 1024
// system clock cycles (33513982 / 1024 = 32728.5 Hz). A channel's timer counts at half the system clock; each
// overflow moves it to its next sample. Each output sample takes a channel's average over its 1024 cycles (the
// hardware mixes at 1 MHz; a single sample per output would alias channels that play faster than the output rate).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "internal.hpp"

namespace ntros {
namespace {

    constexpr uint64_t kSampleCycles = 1024;
    constexpr u32 kTicksPerSample = kSampleCycles / 2; // channel timers count at system clock / 2
    constexpr int kFifoWords = 8; // a channel's data FIFO; it fetches 4 words whenever half of it is free

    enum Format {
        kPcm8,
        kPcm16,
        kAdpcm,
        kPsg
    };
    enum Repeat {
        kManual,
        kLoop,
        kOneShot
    };

    const int kAdpcmIndexStep[8] = { -1, -1, -1, -1, 2, 4, 6, 8 };
    u16 sAdpcmTable[89];

    struct Channel {
        u32 cnt;
        const u8 *sad;
        u16 tmr, pnt;
        u32 len;

        u32 counter; // timer: overflows at 0x10000
        s32 pos; // sample being played; negative during the start delay
        s32 sample; // current output, PCM16 range
        s32 average; // average output over the last output sample period
        bool playing; // started and not finished (the output may still hold the last sample)
        s32 adpcmValue, adpcmIndex; // decoder state after sample pos
        s32 loopValue, loopIndex; // decoder state at the loop start
        u16 noise;
        // PCM and ADPCM data reach the channel through a FIFO that reads ahead of playback: words already fetched
        // don't change when the game rewrites memory behind them (streams rewrite a block just as it ends)
        struct {
            u32 word; // word index from SAD
            u32 value;
        } fifo[kFifoWords];
        int fifoHead, fifoCount;
        u32 fetchWord; // next word to read
    };

    struct Capture {
        u8 cnt;
        u8 *dad;
        u16 len;
        u32 counter;
        u32 pos; // bytes written
    };

    Channel sCh[16];
    Capture sCap[2];
    u16 sSoundCnt;
    u16 sBias = 0x200;
    uint64_t sCycles; // output produced up to here
    s32 sMixLast[2]; // last mixer output (16.8, clipped to 16 bits), for capture

    NtrOsAudio sAudio;

    // NTROS_SPU_LOG=file: every register write the driver makes (DS cycle, address, size, value; a source address
    // as a hash of the 16 bytes there), to compare with another emulator's log
    FILE *SpuLog()
    {
        static FILE *sLog = [] {
            const char *path = getenv("NTROS_SPU_LOG");
            FILE *f = path != NULL ? fopen(path, "w") : NULL;
            if (f != NULL) {
                setvbuf(f, NULL, _IOLBF, 0); // the game is often killed, not ended
            }
            return f;
        }();
        return sLog;
    }
    int sLogDepth;
    void LogWrite(u32 offset, u32 value, int size)
    {
        if (sLogDepth == 0 && SpuLog() != NULL) {
            fprintf(SpuLog(), "%llu %03x %d %x\n", (unsigned long long)sCycles, offset + 0x400, size, value);
        }
    }
    constexpr int kOutFrames = 256;
    s16 sOut[kOutFrames * 2];
    int sOutCount;

    Format FormatOf(const Channel &ch)
    {
        return (Format)((ch.cnt >> 29) & 3);
    }

    // Samples in the whole sound and where the loop starts (in samples from the start of the data)
    void Extent(const Channel &ch, s32 *total, s32 *loopStart)
    {
        switch (FormatOf(ch)) {
        case kPcm8:
            *total = (s32)(ch.pnt + ch.len) * 4;
            *loopStart = ch.pnt * 4;
            break;
        case kPcm16:
            *total = (s32)(ch.pnt + ch.len) * 2;
            *loopStart = ch.pnt * 2;
            break;
        default: // ADPCM: the first word is the header
            *total = ((s32)(ch.pnt + ch.len) - 1) * 8;
            *loopStart = ((s32)ch.pnt - 1) * 8;
            break;
        }
    }

    void AdpcmDecode(Channel &ch, int nibble)
    {
        s32 step = sAdpcmTable[ch.adpcmIndex];
        s32 diff = step / 8;
        if (nibble & 1) {
            diff += step / 4;
        }
        if (nibble & 2) {
            diff += step / 2;
        }
        if (nibble & 4) {
            diff += step;
        }
        if (nibble & 8) {
            ch.adpcmValue -= diff;
            if (ch.adpcmValue < -0x7FFF) {
                ch.adpcmValue = -0x7FFF;
            }
        } else {
            ch.adpcmValue += diff;
            if (ch.adpcmValue > 0x7FFF) {
                ch.adpcmValue = 0x7FFF;
            }
        }
        ch.adpcmIndex += kAdpcmIndexStep[nibble & 7];
        ch.adpcmIndex = ch.adpcmIndex < 0 ? 0 : ch.adpcmIndex > 88 ? 88
                                                                   : ch.adpcmIndex;
    }

    u32 ReadWord(const Channel &ch, u32 word)
    {
        const u8 *p = ch.sad + word * 4;
        return (u32)p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24;
    }

    void FifoFetch(Channel &ch, int words)
    {
        u32 total = ch.pnt + ch.len;
        u32 loopWord = ch.pnt;
        bool loop = ((ch.cnt >> 27) & 3) != kOneShot;
        for (int i = 0; i < words && ch.fifoCount < kFifoWords; i++) {
            if (ch.fetchWord >= total) {
                if (!loop || loopWord >= total) {
                    return;
                }
                ch.fetchWord = loopWord;
            }
            int slot = (ch.fifoHead + ch.fifoCount) % kFifoWords;
            ch.fifo[slot].word = ch.fetchWord;
            ch.fifo[slot].value = ch.sad != NULL ? ReadWord(ch, ch.fetchWord) : 0;
            ch.fifoCount++;
            ch.fetchWord++;
        }
    }

    // The byte at this offset from SAD, as the FIFO has it (playback moves forward, or back to the loop start)
    u8 FifoByte(Channel &ch, u32 offset)
    {
        u32 word = offset / 4;
        for (int tries = 0; tries < 2; tries++) {
            while (ch.fifoCount > 0 && ch.fifo[ch.fifoHead].word != word) {
                ch.fifoHead = (ch.fifoHead + 1) % kFifoWords;
                ch.fifoCount--;
            }
            if (ch.fifoCount > 0) {
                u8 b = (u8)(ch.fifo[ch.fifoHead].value >> ((offset & 3) * 8));
                if (ch.fifoCount <= kFifoWords / 2) {
                    FifoFetch(ch, kFifoWords / 2);
                }
                return b;
            }
            ch.fetchWord = word; // nothing fetched for it (a register changed under the channel): read it now
            FifoFetch(ch, kFifoWords / 2);
        }
        return 0;
    }

    void Start(Channel &ch, int index)
    {
        ch.counter = ch.tmr;
        ch.sample = 0;
        ch.playing = true;
        Format format = FormatOf(ch);
        if (format == kPsg) {
            ch.pos = -1;
            ch.noise = 0x7FFF;
        } else if (format == kAdpcm) {
            ch.pos = -11; // 3 dummy samples, then 8 while the header is read
            u32 header = ch.sad != NULL ? (u32)ch.sad[0] | ch.sad[1] << 8 | ch.sad[2] << 16 | ch.sad[3] << 24 : 0;
            ch.adpcmValue = (s16)header;
            ch.adpcmIndex = (header >> 16) & 0x7F;
            if (ch.adpcmIndex > 88) {
                ch.adpcmIndex = 88;
            }
            ch.loopValue = ch.adpcmValue;
            ch.loopIndex = ch.adpcmIndex;
        } else {
            ch.pos = -3;
        }
        ch.fifoHead = 0;
        ch.fifoCount = 0;
        ch.fetchWord = format == kAdpcm ? 1 : 0;
        if (format != kPsg) {
            FifoFetch(ch, kFifoWords); // during the start delay
        }
        (void)index;
    }

    // The channel's timer overflowed: on to the next sample
    void NextSample(Channel &ch, int index)
    {
        ch.pos++;
        if (ch.pos < 0) {
            return;
        }
        Format format = FormatOf(ch);
        if (format == kPsg) {
            if (index >= 14) {
                bool carry = ch.noise & 1;
                ch.noise >>= 1;
                if (carry) {
                    ch.noise ^= 0x6000;
                    ch.sample = -0x7FFF;
                } else {
                    ch.sample = 0x7FFF;
                }
            } else if (index >= 8) {
                int duty = (ch.cnt >> 24) & 7;
                ch.sample = (duty != 7 && (ch.pos & 7) >= 7 - duty) ? 0x7FFF : -0x7FFF;
            } else {
                ch.sample = 0; // no PSG on channels 0..7
            }
            return;
        }
        s32 total, loopStart;
        Extent(ch, &total, &loopStart);
        Repeat repeat = (Repeat)((ch.cnt >> 27) & 3);
        if (ch.pos >= total) {
            if (repeat == kOneShot || total <= loopStart || loopStart < 0) {
                ch.playing = false;
                ch.cnt &= ~0x80000000u;
                if (!(ch.cnt & 0x8000)) {
                    ch.sample = 0;
                }
                return;
            }
            ch.pos = loopStart;
            if (format == kAdpcm) {
                ch.adpcmValue = ch.loopValue;
                ch.adpcmIndex = ch.loopIndex;
            }
        }
        if (ch.sad == NULL) {
            ch.sample = 0;
        } else if (format == kPcm8) {
            ch.sample = (s8)FifoByte(ch, (u32)ch.pos) << 8;
        } else if (format == kPcm16) {
            ch.sample = (s16)(FifoByte(ch, (u32)ch.pos * 2) | FifoByte(ch, (u32)ch.pos * 2 + 1) << 8);
        } else {
            if (ch.pos == loopStart) {
                ch.loopValue = ch.adpcmValue;
                ch.loopIndex = ch.adpcmIndex;
            }
            u8 byte = FifoByte(ch, 4 + (u32)ch.pos / 2);
            AdpcmDecode(ch, (ch.pos & 1) ? byte >> 4 : byte & 15);
            ch.sample = ch.adpcmValue;
        }
        // One-shot sounds: busy clears when the last sample starts
        if (repeat == kOneShot && ch.pos == total - 1) {
            ch.cnt &= ~0x80000000u;
        }
    }

    // 7-bit factors: 0..126 as they are, 127 counts as 128
    s32 Factor(u32 v)
    {
        v &= 0x7F;
        return v == 127 ? 128 : (s32)v;
    }

    void Flush()
    {
        if (sOutCount > 0 && sAudio.samples != NULL) {
            sAudio.samples(sOut, sOutCount);
        }
        sOutCount = 0;
    }

    void WriteCapture(Capture &cap, s32 value)
    {
        if (cap.dad == NULL) {
            return;
        }
        u32 size = (cap.len == 0 ? 1 : cap.len) * 4;
        if (cap.cnt & 0x08) { // PCM8: 16.8 -> 8.16, rounded towards zero
            s32 v = value / 256;
            cap.dad[cap.pos] = (u8)(s8)(v >> 8);
            cap.pos += 1;
        } else {
            s32 v = value / 256;
            cap.dad[cap.pos] = (u8)v;
            cap.dad[cap.pos + 1] = (u8)(v >> 8);
            cap.pos += 2;
        }
        if (cap.pos >= size) {
            cap.pos = 0;
            if (cap.cnt & 0x04) { // one-shot
                cap.cnt &= 0x7F;
            }
        }
    }

    void MixSample()
    {
        s32 chL[16], chR[16];
        s32 mix[2] = { 0, 0 };
        s32 pre[16];
        for (int i = 0; i < 16; i++) {
            Channel &ch = sCh[i];
            static const int kDivShift[4] = { 0, 1, 2, 4 };
            pre[i] = ((ch.average << 4) >> kDivShift[(ch.cnt >> 8) & 3]) * Factor(ch.cnt); // 16.11
        }
        // Capture addition: ch1 into ch0, ch3 into ch2 (SNDCAPxCNT bit 0 with the capture running)
        for (int c = 0; c < 2; c++) {
            if ((sCap[c].cnt & 0x81) == 0x81) {
                pre[c * 2] += pre[c * 2 + 1];
            }
        }
        for (int i = 0; i < 16; i++) {
            s32 pan = Factor(sCh[i].cnt >> 16);
            chL[i] = (s32)(((int64_t)pre[i] * (128 - pan)) >> 10); // 16.8
            chR[i] = (s32)(((int64_t)pre[i] * pan) >> 10);
            if ((i == 1 && (sSoundCnt & 0x1000)) || (i == 3 && (sSoundCnt & 0x2000))) {
                continue;
            }
            mix[0] += chL[i];
            mix[1] += chR[i];
        }
        for (int s = 0; s < 2; s++) {
            sMixLast[s] = mix[s] < -0x800000 ? -0x800000 : mix[s] > 0x7FFFFF ? 0x7FFFFF
                                                                             : mix[s];
        }
        // Captures write at their timer's rate (channel 1 / 3)
        for (int c = 0; c < 2; c++) {
            Capture &cap = sCap[c];
            if (!(cap.cnt & 0x80)) {
                continue;
            }
            cap.counter += kTicksPerSample;
            while (cap.counter >= 0x10000 && (cap.cnt & 0x80)) {
                cap.counter = cap.counter - 0x10000 + sCh[c * 2 + 1].tmr;
                WriteCapture(cap, (cap.cnt & 0x02) ? pre[c * 2] >> 3 : sMixLast[c]);
            }
        }
        s32 out[2];
        for (int s = 0; s < 2; s++) {
            int select = (sSoundCnt >> (8 + s * 2)) & 3;
            const s32 *chOut = s == 0 ? chL : chR;
            s32 v = select == 0 ? mix[s] : select == 1 ? chOut[1]
                : select == 2                          ? chOut[3]
                                                       : chOut[1] + chOut[3];
            s32 level = (sSoundCnt & 0x8000) ? (s32)(((int64_t)v * Factor(sSoundCnt)) >> 21) : 0; // 14.0
            level += sBias & 0x3FF;
            out[s] = level < 0 ? 0 : level > 0x3FF ? 0x3FF
                                                   : level;
        }
        sOut[sOutCount * 2] = (s16)((out[0] - 0x200) << 6);
        sOut[sOutCount * 2 + 1] = (s16)((out[1] - 0x200) << 6);
        if (++sOutCount == kOutFrames) {
            Flush();
        }
    }

    void RunChannels(u32 ticks)
    {
        for (int i = 0; i < 16; i++) {
            Channel &ch = sCh[i];
            if (!ch.playing) {
                ch.average = ch.sample;
                continue;
            }
            int64_t sum = 0;
            u32 left = ticks;
            while (ch.playing) {
                u32 toOverflow = 0x10000 - ch.counter;
                if (toOverflow > left) {
                    ch.counter += left;
                    break;
                }
                sum += (int64_t)ch.sample * toOverflow;
                left -= toOverflow;
                ch.counter = ch.tmr;
                NextSample(ch, i);
            }
            sum += (int64_t)ch.sample * left;
            ch.average = (s32)(sum / (int64_t)ticks);
        }
    }

} // namespace

void Spu_Init()
{
    // AdpcmTable as the hardware has it (GBATEK: X=000776D2h, X=X+X/10; entries 3, 4 and 88 adjusted)
    u32 x = 0x000776D2;
    for (int i = 0; i < 89; i++) {
        sAdpcmTable[i] = (u16)(x >> 16);
        x += x / 10;
    }
    sAdpcmTable[3] = 0x000A;
    sAdpcmTable[4] = 0x000B;
    sAdpcmTable[88] = 0x7FFF;
    memset(sCh, 0, sizeof(sCh));
    memset(sCap, 0, sizeof(sCap));
    sCycles = Cycles() - Cycles() % kSampleCycles;
}

void Spu_RunTo(uint64_t cycles)
{
    while (sCycles + kSampleCycles <= cycles) {
        RunChannels(kTicksPerSample);
        MixSample();
        sCycles += kSampleCycles;
    }
}

void Spu_FlushOutput()
{
    Flush();
}

void Spu_Write8(u32 offset, u8 value)
{
    LogWrite(offset, value, 1);
    if (offset < 0x100) {
        Channel &ch = sCh[offset >> 4];
        int index = offset >> 4;
        switch (offset & 15) {
        case 0:
            ch.cnt = (ch.cnt & ~0x000000FFu) | (value & 0x7F);
            break;
        case 1:
            ch.cnt = (ch.cnt & ~0x0000FF00u) | (u32)(value & 0x83) << 8;
            break;
        case 2:
            ch.cnt = (ch.cnt & ~0x00FF0000u) | (u32)(value & 0x7F) << 16;
            break;
        case 3: {
            bool wasOn = ch.cnt & 0x80000000u;
            ch.cnt = (ch.cnt & ~0xFF000000u) | (u32)value << 24;
            if (!wasOn && (value & 0x80)) {
                Start(ch, index);
            } else if (wasOn && !(value & 0x80)) {
                ch.playing = false;
                ch.sample = 0;
            }
            break;
        }
        case 8:
            ch.tmr = (ch.tmr & 0xFF00) | value;
            break;
        case 9:
            ch.tmr = (ch.tmr & 0x00FF) | value << 8;
            break;
        case 10:
            ch.pnt = (ch.pnt & 0xFF00) | value;
            break;
        case 11:
            ch.pnt = (ch.pnt & 0x00FF) | value << 8;
            break;
        case 12:
        case 13:
        case 14:
        case 15: {
            int shift = (offset & 3) * 8;
            ch.len = ((ch.len & ~(0xFFu << shift)) | (u32)value << shift) & 0x3FFFFF;
            break;
        }
        default: // SAD: Spu_SetSource
            break;
        }
        return;
    }
    switch (offset) {
    case 0x100:
        sSoundCnt = (sSoundCnt & 0xFF00) | (value & 0x7F);
        break;
    case 0x101:
        sSoundCnt = (sSoundCnt & 0x00FF) | (value & 0xBF) << 8;
        break;
    case 0x104:
        sBias = (sBias & 0x300) | value;
        break;
    case 0x105:
        sBias = (sBias & 0x0FF) | (value & 3) << 8;
        break;
    case 0x108:
    case 0x109: {
        Capture &cap = sCap[offset - 0x108];
        bool wasOn = cap.cnt & 0x80;
        cap.cnt = value & 0x8F;
        if (!wasOn && (value & 0x80)) {
            cap.pos = 0;
            cap.counter = sCh[(offset - 0x108) * 2 + 1].tmr;
        }
        break;
    }
    case 0x114:
    case 0x11C:
        sCap[(offset - 0x114) / 8].len = (sCap[(offset - 0x114) / 8].len & 0xFF00) | value;
        break;
    case 0x115:
    case 0x11D:
        sCap[(offset - 0x115) / 8].len = (sCap[(offset - 0x115) / 8].len & 0x00FF) | value << 8;
        break;
    default:
        break;
    }
}

void Spu_Write16(u32 offset, u16 value)
{
    LogWrite(offset, value, 2);
    sLogDepth++;
    Spu_Write8(offset, (u8)value);
    Spu_Write8(offset + 1, (u8)(value >> 8));
    sLogDepth--;
}

void Spu_Write32(u32 offset, u32 value)
{
    LogWrite(offset, value, 4);
    sLogDepth++;
    Spu_Write16(offset, (u16)value);
    Spu_Write16(offset + 2, (u16)(value >> 16));
    sLogDepth--;
}

u8 Spu_Read8(u32 offset)
{
    if (offset < 0x100) {
        const Channel &ch = sCh[offset >> 4];
        switch (offset & 15) {
        case 0:
        case 1:
        case 2:
        case 3:
            return (u8)(ch.cnt >> ((offset & 3) * 8));
        default:
            return 0; // write-only
        }
    }
    switch (offset) {
    case 0x100:
        return (u8)sSoundCnt;
    case 0x101:
        return (u8)(sSoundCnt >> 8);
    case 0x104:
        return (u8)sBias;
    case 0x105:
        return (u8)(sBias >> 8);
    case 0x108:
    case 0x109:
        return sCap[offset - 0x108].cnt;
    default:
        return 0;
    }
}

u32 Spu_Read32(u32 offset)
{
    return Spu_Read8(offset) | Spu_Read8(offset + 1) << 8 | Spu_Read8(offset + 2) << 16
        | (u32)Spu_Read8(offset + 3) << 24;
}

void Spu_SetSource(int ch, const void *address)
{
    if (SpuLog() != NULL) {
        u32 h = 2166136261u;
        for (int i = 0; i < 16 && address != NULL; i++) {
            h = (h ^ ((const u8 *)address)[i]) * 16777619u;
        }
        fprintf(SpuLog(), "%llu %03x 4 %x %08x\n", (unsigned long long)sCycles, 0x404 + ch * 16, (u32)(uintptr_t)address, h);
    }
    sCh[ch].sad = (const u8 *)address;
}

void Spu_SetCaptureDestination(int capture, void *address)
{
    sCap[capture].dad = (u8 *)address;
}

} // namespace ntros

extern "C" void NtrOs_SetAudio(const NtrOsAudio *audio)
{
    ntros::sAudio = *audio;
}
