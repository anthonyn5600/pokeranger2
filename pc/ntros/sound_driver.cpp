// The sound driver's thread (snd_main.c), command processing (snd_command.c), alarms (snd_alarm.c) and shared work
// (snd_work.c), ARM7 side.
//
// On the DS the sound thread wakes for each sound frame (an alarm every SND_PROC_INTERVAL ticks, 5.2 ms; the first
// 0x10000 ticks after it starts) and whenever the game asks it to process its commands now; each time it hands
// pending channel changes to the hardware, runs the command lists the game has sent, steps the sequences and the
// channels' envelopes (frames only), and reports channel and capture status. Here the frames and the driver's alarms
// are events on the DS clock, run from the timeline; a wake-up request runs the thread at once, inside the game's
// send. Sound alarms (the game's timers for streams) send their number back to the game over the FIFO.
#include <deque>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sound.hpp"

namespace ntros::snd {

SNDWork gWork;
SNDSharedWork *gShared;

namespace {

    constexpr uint64_t kTickCycles = 64; // OS ticks: system clock / 64
    constexpr uint64_t kFrameCycles = SND_PROC_INTERVAL * kTickCycles;
    constexpr uint64_t kFirstFrameCycles = 0x10000 * kTickCycles;
    constexpr uPtr kRequestCommandProc = 0; // SND_MSG_REQUEST_COMMAND_PROC
    constexpr uint64_t kNever = ~0ull;

    bool sInitialized;
    uint64_t sNow; // DS time of what the sound thread is doing
    uint64_t sNextFrame = kNever;
    std::deque<const SNDCommand *> sCommandLists; // received, not yet run

    struct AlarmTimer {
        uint64_t next; // kNever: not running
        uint64_t period; // 0: one-shot
        uPtr arg; // id << 8 | alarm number
    };
    AlarmTimer sAlarms[SND_ALARM_NUM];

    u32 Unpack(u64 arg, int shift, int bits)
    {
        return (u32)(arg >> shift) & ((1u << bits) - 1);
    }

    void AlarmInit()
    {
        for (int i = 0; i < SND_ALARM_NUM; i++) {
            gWork.alarm[i].enable = FALSE;
            gWork.alarm[i].id = 0;
            sAlarms[i].next = kNever;
        }
    }

    void SetupAlarm(int alarmNo, OSTick tick, OSTick period, int id)
    {
        SNDAlarm *alarm = &gWork.alarm[alarmNo];
        if (alarm->enable) {
            sAlarms[alarmNo].next = kNever;
            alarm->enable = FALSE;
        }
        alarm->setting.tick = tick;
        alarm->setting.period = period;
        alarm->id = (u8)id;
    }

    void StartAlarm(int alarmNo)
    {
        SNDAlarm *alarm = &gWork.alarm[alarmNo];
        AlarmTimer &timer = sAlarms[alarmNo];
        timer.next = sNow + alarm->setting.tick * kTickCycles;
        timer.period = alarm->setting.period * kTickCycles;
        timer.arg = (uPtr)(alarm->id << 8 | alarmNo);
        alarm->enable = TRUE;
    }

    void StopAlarm(int alarmNo)
    {
        SNDAlarm *alarm = &gWork.alarm[alarmNo];
        if (!alarm->enable) {
            return;
        }
        sAlarms[alarmNo].next = kNever;
        alarm->id++;
        alarm->enable = FALSE;
    }

    void UpdateSharedWork()
    {
        if (gShared == NULL) {
            return;
        }
        u16 channelStatus = 0;
        u16 captureStatus = 0;
        for (int ch = 0; ch < SND_CHANNEL_NUM; ch++) {
            if (IsChannelActive(ch)) {
                channelStatus |= (u16)(1 << ch);
            }
        }
        if (IsCaptureActive(0)) {
            captureStatus |= 1;
        }
        if (IsCaptureActive(1)) {
            captureStatus |= 2;
        }
        gShared->channelStatus = channelStatus;
        gShared->captureStatus = captureStatus;
    }

    void StartTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask)
    {
        for (int i = 0; i < SND_CHANNEL_NUM && chBitMask != 0; i++, chBitMask >>= 1) {
            if (chBitMask & 1) {
                StartChannel(i);
            }
        }
        if (capBitMask & 1) {
            if (capBitMask & 2) {
                StartCaptureBoth();
            } else {
                StartCapture(0);
            }
        } else if (capBitMask & 2) {
            StartCapture(1);
        }
        for (int i = 0; i < SND_ALARM_NUM && alarmBitMask != 0; i++, alarmBitMask >>= 1) {
            if (alarmBitMask & 1) {
                StartAlarm(i);
            }
        }
        UpdateSharedWork();
    }

    void StopTimer(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags)
    {
        for (int i = 0; i < SND_ALARM_NUM && alarmBitMask != 0; i++, alarmBitMask >>= 1) {
            if (alarmBitMask & 1) {
                StopAlarm(i);
            }
        }
        for (int i = 0; i < SND_CHANNEL_NUM && chBitMask != 0; i++, chBitMask >>= 1) {
            if (chBitMask & 1) {
                StopChannel(i, (s32)flags);
            }
        }
        if (capBitMask & 1) {
            StopCapture(0);
        }
        if (capBitMask & 2) {
            StopCapture(1);
        }
        UpdateSharedWork();
    }

    void ReadDriverInfo(SNDDriverInfo *info)
    {
        memcpy(&info->work, &gWork, sizeof(gWork));
        info->workAddress = &gWork;
        for (int ch = 0; ch < SND_CHANNEL_NUM; ch++) {
            info->chCtrl[ch] = GetChannelControl(ch);
        }
        info->lockedChannels = GetLockedChannel(0);
    }

    // NTROS_SND_LOG: the commands the driver runs and the alarms it sends, with their DS cycle, on stderr
    bool LogCommands()
    {
        static const bool sLog = getenv("NTROS_SND_LOG") != NULL;
        return sLog;
    }

    void RunCommand(const SNDCommand &c)
    {
        const u64 *a = c.arg;
        if (LogCommands()) {
            fprintf(stderr, "snd7 %llu: command %d %llx %llx %llx %llx\n", (unsigned long long)sNow, c.id, (unsigned long long)a[0], (unsigned long long)a[1], (unsigned long long)a[2], (unsigned long long)a[3]);
        }
        switch (c.id) {
        case SND_COMMAND_START_SEQ:
            StartSeq((int)a[0], (const void *)(uPtr)a[1], (u32)a[2], (SNDBankData *)(uPtr)a[3]);
            break;
        case SND_COMMAND_STOP_SEQ:
            StopSeq((int)a[0]);
            break;
        case SND_COMMAND_PREPARE_SEQ:
            PrepareSeq((int)a[0], (const void *)(uPtr)a[1], (u32)a[2], (SNDBankData *)(uPtr)a[3]);
            break;
        case SND_COMMAND_START_PREPARED_SEQ:
            StartPreparedSeq((int)a[0]);
            break;
        case SND_COMMAND_PAUSE_SEQ:
            PauseSeq((int)a[0], a[1] != 0);
            break;
        case SND_COMMAND_SKIP_SEQ:
            SkipSeq((int)a[0], (u32)a[1]);
            break;
        case SND_COMMAND_PLAYER_PARAM:
            SetPlayerParam((int)a[0], (u32)a[1], (u32)a[2], (int)a[3]);
            break;
        case SND_COMMAND_TRACK_PARAM:
            SetTrackParam((int)Unpack(a[0], 0, 24), (u32)a[1], (u32)a[2], (u32)a[3], (int)Unpack(a[0], 24, 8));
            break;
        case SND_COMMAND_MUTE_TRACK:
            SetTrackMute((int)a[0], (u32)a[1], (int)a[2]);
            break;
        case SND_COMMAND_ALLOCATABLE_CHANNEL:
            SetTrackAllocatableChannel((int)a[0], (u32)a[1], (u32)a[2]);
            break;
        case SND_COMMAND_PLAYER_LOCAL_VAR:
            SetPlayerLocalVariable((int)a[0], (int)a[1], (s16)a[2]);
            break;
        case SND_COMMAND_PLAYER_GLOBAL_VAR:
            SetPlayerGlobalVariable((int)a[0], (s16)a[1]);
            break;
        case SND_COMMAND_START_TIMER:
            StartTimer((u32)a[0], (u32)a[1], (u32)a[2]);
            break;
        case SND_COMMAND_STOP_TIMER:
            StopTimer((u32)a[0], (u32)a[1], (u32)a[2], (u32)a[3]);
            break;
        case SND_COMMAND_SETUP_CHANNEL_PCM: // the data address is a whole host pointer here
            SetupChannelPcm((int)Unpack(a[0], 0, 16), (const void *)(uPtr)a[1], (int)Unpack(a[3], 24, 2), (int)Unpack(a[3], 26, 2), (int)Unpack(a[3], 0, 16), (int)Unpack(a[2], 0, 22), (int)Unpack(a[2], 24, 7), (int)Unpack(a[2], 22, 2), (int)Unpack(a[0], 16, 16), (int)Unpack(a[3], 16, 7));
            break;
        case SND_COMMAND_SETUP_CHANNEL_PSG:
            SetupChannelPsg((int)a[0], (int)a[3], (int)Unpack(a[1], 0, 7), (int)Unpack(a[1], 8, 2), (int)Unpack(a[2], 8, 16), (int)Unpack(a[2], 0, 7));
            break;
        case SND_COMMAND_SETUP_CHANNEL_NOISE:
            SetupChannelNoise((int)a[0], (int)Unpack(a[1], 0, 7), (int)Unpack(a[1], 8, 2), (int)Unpack(a[2], 8, 16), (int)Unpack(a[2], 0, 7));
            break;
        case SND_COMMAND_SETUP_CAPTURE:
            SetupCapture((int)Unpack(a[2], 31, 1), (int)Unpack(a[2], 30, 1), (void *)(uPtr)a[0], (int)a[1], Unpack(a[2], 29, 1) != 0, (int)Unpack(a[2], 28, 1), (int)Unpack(a[2], 27, 1));
            break;
        case SND_COMMAND_SETUP_ALARM:
            SetupAlarm((int)a[0], (OSTick)(u32)a[1], (OSTick)(u32)a[2], (int)a[3]);
            break;
        case SND_COMMAND_CHANNEL_TIMER:
        case SND_COMMAND_CHANNEL_VOLUME:
        case SND_COMMAND_CHANNEL_PAN: {
            u32 mask = (u32)a[0];
            for (int ch = 0; ch < SND_CHANNEL_NUM && mask != 0; ch++, mask >>= 1) {
                if (!(mask & 1)) {
                    continue;
                }
                if (c.id == SND_COMMAND_CHANNEL_TIMER) {
                    SetChannelTimer(ch, (int)a[1]);
                } else if (c.id == SND_COMMAND_CHANNEL_VOLUME) {
                    SetChannelVolume(ch, (int)a[1], (int)a[2]);
                } else {
                    SetChannelPan(ch, (int)a[1]);
                }
            }
            break;
        }
        case SND_COMMAND_SURROUND_DECAY:
            SetSurroundDecay((int)a[0]);
            break;
        case SND_COMMAND_MASTER_VOLUME:
            SetMasterVolume((int)a[0]);
            break;
        case SND_COMMAND_MASTER_PAN:
            SetMasterPan((int)a[0]);
            break;
        case SND_COMMAND_OUTPUT_SELECTOR:
            SetOutputSelector((int)a[0], (int)a[1], (int)a[2], (int)a[3]);
            break;
        case SND_COMMAND_LOCK_CHANNEL:
            LockChannel((u32)a[0], (u32)a[1]);
            break;
        case SND_COMMAND_UNLOCK_CHANNEL:
            UnlockChannel((u32)a[0], (u32)a[1]);
            break;
        case SND_COMMAND_STOP_UNLOCKED_CHANNEL:
            StopUnlockedChannel((u32)a[0], (u32)a[1]);
            break;
        case SND_COMMAND_INVALIDATE_SEQ:
            InvalidateSeq((const void *)(uPtr)a[0], (const void *)(uPtr)a[1]);
            break;
        case SND_COMMAND_INVALIDATE_BANK:
            InvalidateBank((const void *)(uPtr)a[0], (const void *)(uPtr)a[1]);
            break;
        case SND_COMMAND_INVALIDATE_WAVE:
            InvalidateWave((const void *)(uPtr)a[0], (const void *)(uPtr)a[1]);
            break;
        case SND_COMMAND_SHARED_WORK:
            gShared = (SNDSharedWork *)(uPtr)a[0];
            break;
        case SND_COMMAND_READ_DRIVER_INFO:
            ReadDriverInfo((SNDDriverInfo *)(uPtr)a[0]);
            break;
        }
    }

    // SND_CommandProc: every list the game has sent, in order; each one done counts as a finished command tag
    void CommandProc()
    {
        while (!sCommandLists.empty()) {
            const SNDCommand *list = sCommandLists.front();
            sCommandLists.pop_front();
            while (list != NULL) {
                SNDCommand command = *list;
                RunCommand(command);
                list = command.next;
            }
            if (gShared != NULL) {
                gShared->finishCommandTag++;
            }
        }
    }

    // One pass of the sound thread at DS time `at`
    void ThreadPass(uint64_t at, bool doPeriodicProc)
    {
        sNow = at;
        Spu_RunTo(at);
        UpdateExChannel();
        CommandProc();
        SeqMain(doPeriodicProc);
        ExChannelMain(doPeriodicProc);
        UpdateSharedWork();
        (void)CalcRandom();
    }

    // The game's words for the sound driver: a command list, or a request to process the commands now
    void ReceiveWord(int tag, uPtr data, BOOL err)
    {
        (void)tag;
        (void)err;
        if (data != kRequestCommandProc) {
            sCommandLists.push_back((const SNDCommand *)data);
        } else {
            ThreadPass(Cycles(), false);
        }
    }

} // namespace

void RestartIntervalTimer()
{
    sNextFrame = sNow + kFirstFrameCycles;
}

u16 CalcRandom()
{
    static u32 u = 0x12345678;
    u = u * 1664525 + 1013904223;
    return (u16)(u >> 16);
}

s8 SinIdx(int index)
{
    static const s8 kSinTable[SND_SIN_TABLE_SIZE + 1] = {
        0,
        6,
        12,
        19,
        25,
        31,
        37,
        43,
        49,
        54,
        60,
        65,
        71,
        76,
        81,
        85,
        90,
        94,
        98,
        102,
        106,
        109,
        112,
        115,
        117,
        120,
        122,
        123,
        125,
        126,
        126,
        127,
        127,
    };
    if (index < SND_SIN_TABLE_SIZE) {
        return kSinTable[index];
    }
    if (index < SND_SIN_TABLE_SIZE * 2) {
        return kSinTable[SND_SIN_TABLE_SIZE - (index - SND_SIN_TABLE_SIZE)];
    }
    if (index < SND_SIN_TABLE_SIZE * 3) {
        return (s8)-kSinTable[index - SND_SIN_TABLE_SIZE * 2];
    }
    return (s8)-kSinTable[SND_SIN_TABLE_SIZE - (index - SND_SIN_TABLE_SIZE * 3)];
}

} // namespace ntros::snd

namespace ntros {

using namespace snd;

void Sound_Init()
{
    if (sInitialized) {
        return;
    }
    sInitialized = true;
    sNow = Cycles();
    Spu_Init();
    ExChannelInit();
    SeqInit();
    AlarmInit();
    Enable();
    SetOutputSelector(SND_OUTPUT_MIXER, SND_OUTPUT_MIXER, SND_CHANNEL_OUT_MIXER, SND_CHANNEL_OUT_MIXER);
    SetMasterVolume(SND_MASTER_VOLUME_MAX);
    RestartIntervalTimer();
    Pxi_SetArm7Service(PXI_FIFO_TAG_SOUND, ReceiveWord);
}

void Sound_Step()
{
    if (!sInitialized) {
        return;
    }
    uint64_t now = Cycles();
    for (;;) {
        // The earliest due event: a sound frame or an alarm
        uint64_t at = sNextFrame;
        int alarm = -1;
        for (int i = 0; i < SND_ALARM_NUM; i++) {
            if (sAlarms[i].next < at) {
                at = sAlarms[i].next;
                alarm = i;
            }
        }
        if (at > now) {
            break;
        }
        if (alarm < 0) {
            sNextFrame += kFrameCycles;
            ThreadPass(at, true);
            continue;
        }
        AlarmTimer &timer = sAlarms[alarm];
        if (timer.period != 0) {
            timer.next += timer.period;
        } else {
            timer.next = kNever;
        }
        Spu_RunTo(at);
        if (LogCommands()) {
            fprintf(stderr, "snd7 %llu: alarm %llx\n", (unsigned long long)at, (unsigned long long)timer.arg);
        }
        Pxi_SendToArm9(PXI_FIFO_TAG_SOUND, timer.arg, FALSE);
    }
    Spu_RunTo(now);
}

} // namespace ntros
