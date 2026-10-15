// The sound driver's hardware level: channel registers, master volume and output selection, the surround effect
// (channels other than 1 and 3 get quieter towards the far left and right), master pan, capture units
#include "sound.hpp"

namespace ntros::snd {
namespace {

    constexpr u32 kSurroundChannels = 0xFFF5; // not 1 and 3 (the capture output channels)

    int sMasterPan = -1; // -1: each channel's own pan
    int sSurroundDecay;
    u8 sOrgPan[16];
    u8 sOrgVolume[16];

    u32 ChannelReg(int ch, u32 reg)
    {
        return (u32)ch * 0x10 + reg;
    }

    bool Surround(int ch)
    {
        return sSurroundDecay > 0 && (kSurroundChannels & (1u << ch)) != 0;
    }

    int CalcSurroundDecay(int volume, int pan)
    {
        if (pan < 24) {
            return volume * (sSurroundDecay * (pan + 40) + (0x7FFF - sSurroundDecay) * 64) >> 21;
        }
        if (pan <= 104) {
            return volume;
        }
        return volume * (-sSurroundDecay * (pan - 40) + (sSurroundDecay + 0x7FFF) * 64) >> 21;
    }

} // namespace

void SetupChannelPcm(int ch, const void *data, int format, int loop, int loopStart, int loopLen, int volume, int shift, int timer, int pan)
{
    sOrgPan[ch] = (u8)pan;
    if (sMasterPan >= 0) {
        pan = sMasterPan;
    }
    sOrgVolume[ch] = (u8)volume;
    if (Surround(ch)) {
        volume = CalcSurroundDecay(volume, pan);
    }
    Spu_Write32(ChannelReg(ch, 0x0), (u32)volume | (u32)shift << 8 | (u32)pan << 16 | (u32)loop << 27 | (u32)format << 29);
    Spu_Write16(ChannelReg(ch, 0x8), (u16)-timer);
    Spu_Write16(ChannelReg(ch, 0xA), (u16)loopStart);
    Spu_Write32(ChannelReg(ch, 0xC), (u32)loopLen);
    Spu_SetSource(ch, data);
}

void SetupChannelPsg(int ch, int duty, int volume, int shift, int timer, int pan)
{
    sOrgPan[ch] = (u8)pan;
    if (sMasterPan >= 0) {
        pan = sMasterPan;
    }
    sOrgVolume[ch] = (u8)volume;
    if (Surround(ch)) {
        volume = CalcSurroundDecay(volume, pan);
    }
    Spu_Write32(ChannelReg(ch, 0x0), (u32)volume | (u32)shift << 8 | (u32)pan << 16 | (u32)duty << 24 | 0x60000000u);
    Spu_Write16(ChannelReg(ch, 0x8), (u16)-timer);
}

void SetupChannelNoise(int ch, int volume, int shift, int timer, int pan)
{
    sOrgPan[ch] = (u8)pan;
    if (sMasterPan >= 0) {
        pan = sMasterPan;
    }
    sOrgVolume[ch] = (u8)volume;
    if (Surround(ch)) {
        volume = CalcSurroundDecay(volume, pan);
    }
    Spu_Write32(ChannelReg(ch, 0x0), (u32)volume | (u32)shift << 8 | (u32)pan << 16 | 0x60000000u);
    Spu_Write16(ChannelReg(ch, 0x8), (u16)-timer);
}

void StartChannel(int ch)
{
    Spu_Write8(ChannelReg(ch, 0x3), Spu_Read8(ChannelReg(ch, 0x3)) | 0x80);
}

// flags bit 0: hold the last sample
void StopChannel(int ch, s32 flags)
{
    u32 cnt = Spu_Read32(ChannelReg(ch, 0x0)) & 0x7FFFFFFF;
    if (flags & 1) {
        cnt |= 0x8000;
    }
    Spu_Write32(ChannelReg(ch, 0x0), cnt);
}

void SetChannelTimer(int ch, int timer)
{
    Spu_Write16(ChannelReg(ch, 0x8), (u16)-timer);
}

void SetChannelVolume(int ch, int volume, int shift)
{
    sOrgVolume[ch] = (u8)volume;
    if (Surround(ch)) {
        volume = CalcSurroundDecay(volume, Spu_Read8(ChannelReg(ch, 0x2)));
    }
    Spu_Write16(ChannelReg(ch, 0x0), (u16)(volume | shift << 8));
}

void SetChannelPan(int ch, int pan)
{
    sOrgPan[ch] = (u8)pan;
    if (sMasterPan >= 0) {
        pan = sMasterPan;
    }
    Spu_Write8(ChannelReg(ch, 0x2), (u8)pan);
    if (Surround(ch)) {
        Spu_Write8(ChannelReg(ch, 0x0), (u8)CalcSurroundDecay(sOrgVolume[ch], pan));
    }
}

bool IsChannelActive(int ch)
{
    return (Spu_Read8(ChannelReg(ch, 0x3)) & 0x80) != 0;
}

u32 GetChannelControl(int ch)
{
    return Spu_Read32(ChannelReg(ch, 0x0));
}

void SetMasterVolume(int volume)
{
    Spu_Write8(0x100, (u8)volume);
}

void SetMasterPan(int pan)
{
    sMasterPan = pan;
    for (int ch = 0; ch < SND_CHANNEL_NUM; ch++) {
        Spu_Write8(ChannelReg(ch, 0x2), pan >= 0 ? (u8)pan : sOrgPan[ch]);
    }
}

void SetSurroundDecay(int decay)
{
    sSurroundDecay = decay;
    for (int ch = 0; ch < SND_CHANNEL_NUM; ch++) {
        if (kSurroundChannels & (1u << ch)) {
            Spu_Write8(ChannelReg(ch, 0x0), (u8)CalcSurroundDecay(sOrgVolume[ch], Spu_Read8(ChannelReg(ch, 0x2))));
        }
    }
}

void SetOutputSelector(int left, int right, int channel1, int channel3)
{
    u8 enable = Spu_Read8(0x101) & 0x80;
    Spu_Write8(0x101, (u8)(left | right << 2 | channel1 << 4 | channel3 << 5 | enable));
}

void Enable()
{
    Spu_Write8(0x101, Spu_Read8(0x101) | 0x80);
}

void SetupCapture(int capture, int format, void *buffer, int length, bool repeat, int in, int out)
{
    Spu_Write8(0x108 + capture, (u8)(out | in << 1 | (repeat ? 0 : 1) << 2 | format << 3));
    Spu_SetCaptureDestination(capture, buffer);
    Spu_Write16(0x114 + capture * 8, (u16)length);
}

void StartCapture(int capture)
{
    Spu_Write8(0x108 + capture, Spu_Read8(0x108 + capture) | 0x80);
}

void StartCaptureBoth()
{
    u8 cap0 = Spu_Read8(0x108) | 0x80;
    u8 cap1 = Spu_Read8(0x109) | 0x80;
    Spu_Write8(0x108, cap0);
    Spu_Write8(0x109, cap1);
}

void StopCapture(int capture)
{
    Spu_Write8(0x108 + capture, 0);
}

bool IsCaptureActive(int capture)
{
    return (Spu_Read8(0x108 + capture) & 0x80) != 0;
}

} // namespace ntros::snd
