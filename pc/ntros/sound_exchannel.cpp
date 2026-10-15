// The driver's channels: allocation by priority, envelopes (attack, decay, sustain, release in centibels), LFO,
// pitch sweep, and the per-frame update that turns them into register values. Changes reach the hardware at the
// start of the next sound frame (UpdateExChannel), through each channel's sync flags.
#include "sound.hpp"

namespace ntros::snd {
namespace {

    constexpr int kSyncStart = SND_EX_CHANNEL_UPDATE_START;
    constexpr int kSyncStop = SND_EX_CHANNEL_UPDATE_STOP;
    constexpr int kSyncTimer = SND_EX_CHANNEL_UPDATE_TIMER;
    constexpr int kSyncVolume = SND_EX_CHANNEL_UPDATE_VOLUME;
    constexpr int kSyncPan = SND_EX_CHANNEL_UPDATE_PAN;

    constexpr s32 kEnvAttackStart = SND_VOLUME_DB_MIN * (1 << SND_EX_CHANNEL_ENV_DECAY_SHIFT); // -72.3 dB, x128
    constexpr int kPsgTimer = 0x1F46; // base timer of square waves and noise (8 samples per period: 261.6 Hz at key 60)

    // Allocation tries channels in this order (PSG-capable 8..13 and noise 14..15 last)
    const u8 kAllocOrder[16] = { 4, 5, 6, 7, 2, 0, 3, 1, 8, 9, 10, 11, 14, 12, 15, 13 };
    // Attack rates 109..127 (lower ones are 255 - rate)
    const u8 kAttackTable[19] = { 0, 1, 5, 14, 26, 38, 51, 63, 73, 84, 92, 100, 109, 116, 123, 127, 132, 137, 143 };
    const int kVolumeShift[4] = { 0, 1, 2, 4 };

    u32 sWeakLocked; // SND_LOCK_IMPLIED_ALLOC_CHANNEL: still given out to strong requests
    u32 sLocked;

    void Finish(SNDExChannel *ch)
    {
        if (ch->callback != NULL) {
            ch->callback(ch, SND_EX_CHANNEL_CALLBACK_FINISH, ch->callback_data);
        } else {
            ch->prio = 0;
        }
        ch->volume = 0;
        ch->active_flag = 0;
    }

    // Decay and release rates (0..127) as centibel steps per frame, x128
    u16 CalcDecayRate(int rate)
    {
        if (rate == 127) {
            return 0xFFFF;
        }
        if (rate == 126) {
            return 0x3C00;
        }
        if (rate < 50) {
            return (u16)(rate * 2 + 1);
        }
        return (u16)(0x1E00 / (126 - rate));
    }

    void StartExChannel(SNDExChannel *ch, s32 length)
    {
        ch->env_decay = kEnvAttackStart;
        ch->env_status = SND_ENV_ATTACK;
        ch->length = length;
        ch->lfo.counter = 0;
        ch->lfo.delay_counter = 0;
        ch->start_flag = 1;
        ch->active_flag = 1;
    }

    // The envelope's level in centibels; doPeriodicProc moves it on by a frame
    s32 UpdateEnvelope(SNDExChannel *ch, bool doPeriodicProc)
    {
        if (doPeriodicProc) {
            switch (ch->env_status) {
            case SND_ENV_ATTACK:
                ch->env_decay = -((-ch->env_decay * ch->attack) >> 8);
                if (ch->env_decay == 0) {
                    ch->env_status = SND_ENV_DECAY;
                }
                break;
            case SND_ENV_DECAY: {
                s32 sustain = SNDi_DecibelSquareTable[ch->sustain] * (1 << SND_EX_CHANNEL_ENV_DECAY_SHIFT);
                ch->env_decay -= ch->decay;
                if (ch->env_decay <= sustain) {
                    ch->env_decay = sustain;
                    ch->env_status = SND_ENV_SUSTAIN;
                }
                break;
            }
            case SND_ENV_SUSTAIN:
                break;
            case SND_ENV_RELEASE:
                ch->env_decay -= ch->release;
                break;
            }
        }
        return ch->env_decay >> SND_EX_CHANNEL_ENV_DECAY_SHIFT;
    }

    void StartLfo(SNDLfo *lfo)
    {
        lfo->counter = 0;
        lfo->delay_counter = 0;
    }

    void UpdateLfo(SNDLfo *lfo)
    {
        if (lfo->delay_counter < lfo->param.delay) {
            lfo->delay_counter++;
            return;
        }
        u32 counter = lfo->counter + (lfo->param.speed << 6);
        u32 index = counter >> 8;
        while (index >= SND_SIN_PERIOD) {
            index -= SND_SIN_PERIOD;
        }
        lfo->counter = (u16)((counter & 0xFF) | index << 8);
    }

    s32 GetLfoValue(SNDLfo *lfo)
    {
        if (lfo->param.depth == 0 || lfo->delay_counter < lfo->param.delay) {
            return 0;
        }
        return SinIdx(lfo->counter >> 8) * lfo->param.depth * lfo->param.range;
    }

    // Effective loudness of a channel's register volume, to choose which one to take away
    int Loudness(const SNDExChannel *ch)
    {
        return ((ch->volume & 0xFF) << 4) >> kVolumeShift[ch->volume >> 8];
    }

    // Stop the channel and give it back (lock, stop unlocked)
    void Kill(SNDExChannel *ch, int chNo)
    {
        if (ch->callback != NULL) {
            ch->callback(ch, SND_EX_CHANNEL_CALLBACK_DROP, ch->callback_data);
        }
        StopChannel(chNo, 0);
        ch->prio = 0;
        FreeExChannel(ch);
        ch->sync_flag = 0;
        ch->active_flag = 0;
    }

} // namespace

void ExChannelInit()
{
    for (int i = 0; i < SND_CHANNEL_NUM; i++) {
        SNDExChannel *ch = &gWork.channel[i];
        ch->myNo = (u8)i;
        ch->sync_flag = 0;
        ch->active_flag = 0;
    }
    sLocked = 0;
    sWeakLocked = 0;
}

// Frame start: hand the channels' pending changes to the hardware; starts last, all at once
void UpdateExChannel()
{
    for (int i = 0; i < SND_CHANNEL_NUM; i++) {
        SNDExChannel *ch = &gWork.channel[i];
        if (ch->sync_flag == 0) {
            continue;
        }
        if (ch->sync_flag & kSyncStop) {
            StopChannel(i, 0);
        }
        if (ch->sync_flag & kSyncStart) {
            switch (ch->type) {
            case SND_EX_CHANNEL_PCM:
                SetupChannelPcm(i, ch->data, ch->wave.format, ch->wave.loopflag ? SND_CHANNEL_LOOP_REPEAT : SND_CHANNEL_LOOP_1SHOT, ch->wave.loopstart, (int)ch->wave.looplen, ch->volume & 0xFF, ch->volume >> 8, ch->timer, ch->pan);
                break;
            case SND_EX_CHANNEL_PSG:
                SetupChannelPsg(i, ch->duty, ch->volume & 0xFF, ch->volume >> 8, ch->timer, ch->pan);
                break;
            case SND_EX_CHANNEL_NOISE:
                SetupChannelNoise(i, ch->volume & 0xFF, ch->volume >> 8, ch->timer, ch->pan);
                break;
            }
        } else {
            if (ch->sync_flag & kSyncTimer) {
                SetChannelTimer(i, ch->timer);
            }
            if (ch->sync_flag & kSyncVolume) {
                SetChannelVolume(i, ch->volume & 0xFF, ch->volume >> 8);
            }
            if (ch->sync_flag & kSyncPan) {
                SetChannelPan(i, ch->pan);
            }
        }
    }
    for (int i = 0; i < SND_CHANNEL_NUM; i++) {
        SNDExChannel *ch = &gWork.channel[i];
        if (ch->sync_flag == 0) {
            continue;
        }
        if (ch->sync_flag & kSyncStart) {
            StartChannel(i);
        }
        ch->sync_flag = 0;
    }
}

// Each frame: envelopes, sweep, LFO -> volume, timer and pan register values (sent at the next frame start).
// doPeriodicProc: a timer frame (envelopes, sweeps and LFOs move on), not a wake-up for commands
void ExChannelMain(bool doPeriodicProc)
{
    for (int i = 0; i < SND_CHANNEL_NUM; i++) {
        SNDExChannel *ch = &gWork.channel[i];
        if (!ch->active_flag) {
            continue;
        }
        if (ch->start_flag) {
            ch->sync_flag |= kSyncStart;
            ch->start_flag = 0;
        } else if (!IsChannelActive(i)) {
            Finish(ch);
            continue;
        }

        s32 volume = SNDi_DecibelSquareTable[ch->velocity];
        s32 pitch = (ch->key - ch->original_key) << 6;
        volume += UpdateEnvelope(ch, doPeriodicProc);

        s32 sweep = 0;
        if (ch->sweep_pitch != 0 && ch->sweep_counter < ch->sweep_length) {
            sweep = (s32)((int64_t)ch->sweep_pitch * (ch->sweep_length - ch->sweep_counter) / ch->sweep_length);
            if (doPeriodicProc && ch->auto_sweep) {
                ch->sweep_counter++;
            }
        }
        volume += ch->user_decay + ch->user_decay2;
        pitch += sweep + ch->user_pitch;

        s32 lfo = GetLfoValue(&ch->lfo);
        if (lfo != 0) {
            int64_t scaled = lfo;
            switch (ch->lfo.param.target) {
            case SND_LFO_PITCH:
            case SND_LFO_PAN:
                scaled <<= 6;
                break;
            case SND_LFO_VOLUME:
                scaled *= 60;
                break;
            }
            lfo = (s32)(scaled >> 14);
        }
        if (doPeriodicProc) {
            UpdateLfo(&ch->lfo);
        }
        s32 lfoPan = 0;
        switch (ch->lfo.param.target) {
        case SND_LFO_PITCH:
            pitch += lfo;
            break;
        case SND_LFO_VOLUME:
            if (volume > -0x8000) {
                volume += lfo;
            }
            break;
        case SND_LFO_PAN:
            lfoPan = lfo;
            break;
        }

        s32 pan = lfoPan + ch->init_pan;
        if (ch->pan_range != 127) {
            pan = (pan * ch->pan_range + 64) >> 7;
        }
        pan += ch->user_pan;

        if (ch->env_status == SND_ENV_RELEASE && volume <= SND_VOLUME_DB_MIN) {
            ch->sync_flag = kSyncStop;
            Finish(ch);
            continue;
        }
        u16 chVolume = SND_CalcChannelVolume(volume);
        u16 timer = SND_CalcTimer(ch->wave.timer, pitch);
        if (ch->type == SND_EX_CHANNEL_PSG) {
            timer &= 0xFFFC;
        }
        pan += 64;
        pan = pan < 0 ? 0 : pan > 127 ? 127
                                      : pan;
        if (chVolume != ch->volume) {
            ch->volume = chVolume;
            ch->sync_flag |= kSyncVolume;
        }
        if (timer != ch->timer) {
            ch->timer = timer;
            ch->sync_flag |= kSyncTimer;
        }
        if (pan != ch->pan) {
            ch->pan = (u8)pan;
            ch->sync_flag |= kSyncPan;
        }
    }
}

// The lowest-priority free channel among chBitMask (equal priority: the quietest); NULL if every one outranks prio
SNDExChannel *AllocExChannel(u32 chBitMask, int prio, bool strongRequest, SNDExChannelCallback callback, void *callbackData)
{
    chBitMask &= ~sLocked;
    if (!strongRequest) {
        chBitMask &= ~sWeakLocked;
    }
    SNDExChannel *best = NULL;
    for (int i = 0; i < SND_CHANNEL_NUM; i++) {
        int chNo = kAllocOrder[i];
        if (!(chBitMask & (1u << chNo))) {
            continue;
        }
        SNDExChannel *ch = &gWork.channel[chNo];
        if (best == NULL || ch->prio < best->prio || (ch->prio == best->prio && Loudness(ch) < Loudness(best))) {
            best = ch;
        }
    }
    if (best == NULL || prio < best->prio) {
        return NULL;
    }
    SNDExChannel *ch = best;
    if (ch->callback != NULL) {
        ch->callback(ch, SND_EX_CHANNEL_CALLBACK_DROP, ch->callback_data);
    }
    ch->sync_flag = kSyncStop;
    ch->active_flag = 0;
    ch->nextLink = NULL;
    ch->callback = callback;
    ch->callback_data = callbackData;
    ch->length = 0;
    ch->prio = (u8)prio;
    ch->volume = 127;
    ch->start_flag = 0;
    ch->auto_sweep = 1;
    ch->key = 60;
    ch->original_key = 60;
    ch->velocity = 127;
    ch->init_pan = 0;
    ch->user_decay = 0;
    ch->user_decay2 = 0;
    ch->user_pitch = 0;
    ch->user_pan = 0;
    ch->pan_range = 127;
    ch->sweep_pitch = 0;
    ch->sweep_length = 0;
    ch->sweep_counter = 0;
    ch->attack = 0;
    ch->decay = 0xFFFF;
    ch->sustain = 127;
    ch->release = 0xFFFF;
    InitLfoParam(&ch->lfo.param);
    return ch;
}

void FreeExChannel(SNDExChannel *ch)
{
    if (ch != NULL) {
        ch->callback = NULL;
        ch->callback_data = NULL;
    }
}

bool StartExChannelPcm(SNDExChannel *ch, const SNDWaveParam *wave, const void *data, s32 length)
{
    ch->type = SND_EX_CHANNEL_PCM;
    ch->wave = *wave;
    ch->data = data;
    StartExChannel(ch, length);
    return true;
}

bool StartExChannelPsg(SNDExChannel *ch, int duty, s32 length)
{
    if (ch->myNo < SND_PSG_CHANNEL_MIN || ch->myNo > SND_PSG_CHANNEL_MAX) {
        return false;
    }
    ch->type = SND_EX_CHANNEL_PSG;
    ch->duty = (SNDDuty)duty;
    ch->wave.timer = kPsgTimer;
    StartExChannel(ch, length);
    return true;
}

bool StartExChannelNoise(SNDExChannel *ch, s32 length)
{
    if (ch->myNo < SND_NOISE_CHANNEL_MIN || ch->myNo > SND_NOISE_CHANNEL_MAX) {
        return false;
    }
    ch->type = SND_EX_CHANNEL_NOISE;
    ch->wave.timer = kPsgTimer;
    StartExChannel(ch, length);
    return true;
}

void ReleaseExChannel(SNDExChannel *ch)
{
    ch->env_status = SND_ENV_RELEASE;
}

bool IsExChannelActive(SNDExChannel *ch)
{
    return ch->active_flag != 0;
}

void SetExChannelAttack(SNDExChannel *ch, int attack)
{
    ch->attack = attack < 109 ? (u8)(255 - attack) : kAttackTable[127 - attack];
}

void SetExChannelDecay(SNDExChannel *ch, int decay)
{
    ch->decay = CalcDecayRate(decay);
}

void SetExChannelSustain(SNDExChannel *ch, int sustain)
{
    ch->sustain = (u8)sustain;
}

void SetExChannelRelease(SNDExChannel *ch, int release)
{
    ch->release = CalcDecayRate(release);
}

void InitLfoParam(SNDLfoParam *lfo)
{
    lfo->target = SND_LFO_PITCH;
    lfo->depth = 0;
    lfo->range = 1;
    lfo->speed = 16;
    lfo->delay = 0;
}

void LockChannel(u32 chBitMask, u32 flags)
{
    u32 mask = chBitMask;
    for (int i = 0; i < SND_CHANNEL_NUM && mask != 0; i++, mask >>= 1) {
        if ((mask & 1) && !(sLocked & (1u << i))) {
            Kill(&gWork.channel[i], i);
        }
    }
    if (flags & SND_LOCK_IMPLIED_ALLOC_CHANNEL) {
        sWeakLocked |= chBitMask;
    } else {
        sLocked |= chBitMask;
    }
}

void UnlockChannel(u32 chBitMask, u32 flags)
{
    if (flags & SND_LOCK_IMPLIED_ALLOC_CHANNEL) {
        sWeakLocked &= ~chBitMask;
    } else {
        sLocked &= ~chBitMask;
    }
}

void StopUnlockedChannel(u32 chBitMask, u32 flags)
{
    (void)flags;
    for (int i = 0; i < SND_CHANNEL_NUM && chBitMask != 0; i++, chBitMask >>= 1) {
        if ((chBitMask & 1) && !(sLocked & (1u << i))) {
            Kill(&gWork.channel[i], i);
        }
    }
}

u32 GetLockedChannel(u32 flags)
{
    return (flags & SND_LOCK_IMPLIED_ALLOC_CHANNEL) ? sWeakLocked : sLocked;
}

// Wave data in [start, end] goes away: stop the channels playing it
void InvalidateWave(const void *start, const void *end)
{
    for (int i = 0; i < SND_CHANNEL_NUM; i++) {
        SNDExChannel *ch = &gWork.channel[i];
        if (ch->active_flag && ch->type == SND_EX_CHANNEL_PCM && start <= ch->data && ch->data <= end) {
            ch->start_flag = 0;
            StopChannel(i, 0);
        }
    }
}

} // namespace ntros::snd
