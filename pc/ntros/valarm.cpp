// V-alarms: handlers called at a display line (NitroSDK os_valarm.c). The queue's first alarm sets the VCount match
// line; the VCount interrupt runs the alarms that are due. Frames are counted by watching VCOUNT go back down.
#include "internal.hpp"

namespace ntros {
namespace {

    enum {
        kLater,
        kNow,
        kTimeout
    };

    bool sUseVAlarm;
    struct {
        OSVAlarm *head;
        OSVAlarm *tail;
    } sQueue;
    s32 sFrameCount;
    s32 sPreviousVCount;

    s32 GetFrame(s32 vcount)
    {
        if (vcount < sPreviousVCount) {
            sFrameCount++;
        }
        sPreviousVCount = vcount;
        return sFrameCount;
    }

    void VAlarmHandler();

    void SetNextVAlarm(OSVAlarm *alarm)
    {
        OS_SetIrqFunction(OS_IE_V_COUNT, VAlarmHandler);
        GX_SetVCountEqVal(alarm->fire);
        GX_VCountEqIntr(TRUE);
        (void)OS_EnableIrqMask(OS_IE_V_COUNT);
    }

    void AppendVAlarm(OSVAlarm *alarm)
    {
        alarm->prev = sQueue.tail;
        alarm->next = NULL;
        sQueue.tail = alarm;
        if (alarm->prev != NULL) {
            alarm->prev->next = alarm;
        } else {
            sQueue.head = alarm;
            SetNextVAlarm(alarm);
        }
    }

    // Sorted by frame, then line (equal ones keep their order)
    void InsertVAlarm(OSVAlarm *alarm)
    {
        for (OSVAlarm *next = sQueue.head; next != NULL; next = next->next) {
            if (next->frame < alarm->frame || (next->frame == alarm->frame && next->fire <= alarm->fire)) {
                continue;
            }
            alarm->prev = next->prev;
            alarm->next = next;
            next->prev = alarm;
            if (alarm->prev != NULL) {
                alarm->prev->next = alarm;
            } else {
                sQueue.head = alarm;
                SetNextVAlarm(alarm);
            }
            return;
        }
        AppendVAlarm(alarm);
    }

    void DetachVAlarm(OSVAlarm *alarm)
    {
        if (alarm->next != NULL) {
            alarm->next->prev = alarm->prev;
        } else {
            sQueue.tail = alarm->prev;
        }
        if (alarm->prev != NULL) {
            alarm->prev->next = alarm->next;
        } else {
            sQueue.head = alarm->next;
        }
    }

    int CompareVCount(const OSVAlarm *alarm, s32 frame, s32 vcount)
    {
        s32 frameDelay = frame - (s32)alarm->frame;
        s32 lineDelay = vcount - alarm->fire;
        if (frameDelay < 0 || (frameDelay == 0 && lineDelay < 0)) {
            return kLater;
        }
        if (lineDelay < 0) {
            lineDelay += HW_LCD_LINES;
        }
        return lineDelay <= alarm->delay ? kNow : kTimeout;
    }

    void VAlarmHandler()
    {
        (void)OS_DisableIrqMask(OS_IE_V_COUNT);
        GX_VCountEqIntr(FALSE);
        OS_SetIrqCheckFlag(OS_IE_V_COUNT);
        (void)GetFrame(GX_GetVCountEqVal() - 1);
        OSVAlarm *alarm;
        while ((alarm = sQueue.head) != NULL) {
            s32 vcount = GX_GetVCount();
            s32 frame = GetFrame(vcount);
            switch (CompareVCount(alarm, frame, vcount)) {
            case kLater:
                SetNextVAlarm(alarm);
                // Still due now (the line matched already): run it here instead of waiting a frame
                if (alarm->fire != GX_GetVCount() || alarm->frame != (u32)frame) {
                    return;
                }
                (void)OS_DisableIrqMask(OS_IE_V_COUNT);
                GX_VCountEqIntr(FALSE);
                (void)OS_ResetRequestIrqMask(OS_IE_V_COUNT);
                // fall through
            case kNow: {
                OSVAlarmHandler handler = alarm->handler;
                DetachVAlarm(alarm);
                alarm->handler = NULL;
                if (handler != NULL) {
                    handler(alarm->arg);
                }
                if (alarm->period && !alarm->canceled) {
                    alarm->handler = handler;
                    alarm->frame = (u32)sFrameCount + 1;
                    AppendVAlarm(alarm);
                }
                break;
            }
            case kTimeout:
                DetachVAlarm(alarm);
                AppendVAlarm(alarm);
                alarm->frame = (u32)sFrameCount + 1;
                break;
            }
        }
    }

    void SetVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg, BOOL period)
    {
        if (alarm == NULL || alarm->handler != NULL) {
            OS_Panic("v-alarm could be already used.");
            return;
        }
        s32 vcount = GX_GetVCount();
        s32 frame = GetFrame(vcount);
        alarm->period = period;
        alarm->fire = count;
        alarm->frame = (u32)(count > vcount ? frame : frame + 1);
        alarm->delay = delay;
        alarm->handler = handler;
        alarm->arg = arg;
        alarm->canceled = FALSE;
        InsertVAlarm(alarm);
    }

} // namespace
} // namespace ntros

using namespace ntros;

extern "C" {

void OS_InitVAlarm(void)
{
    if (!sUseVAlarm) {
        sUseVAlarm = TRUE;
        sQueue.head = NULL;
        sQueue.tail = NULL;
        (void)OS_DisableIrqMask(OS_IE_V_COUNT);
        sFrameCount = 0;
        sPreviousVCount = 0;
    }
}

void OS_EndVAlarm(void)
{
    sUseVAlarm = FALSE;
}

BOOL OS_IsVAlarmAvailable(void)
{
    return sUseVAlarm;
}

void OS_CreateVAlarm(OSVAlarm *alarm)
{
    alarm->handler = NULL;
    alarm->tag = 0;
    alarm->finish = FALSE;
}

void OS_SetVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg)
{
    SetVAlarm(alarm, count, delay, handler, arg, FALSE);
}

void OS_SetPeriodicVAlarm(OSVAlarm *alarm, s16 count, s16 delay, OSVAlarmHandler handler, void *arg)
{
    SetVAlarm(alarm, count, delay, handler, arg, TRUE);
}

void OS_SetVAlarmTag(OSVAlarm *alarm, u32 tag)
{
    if (alarm != NULL && tag != 0) {
        alarm->tag = tag;
    }
}

void OS_CancelVAlarm(OSVAlarm *alarm)
{
    alarm->canceled = TRUE;
    if (alarm->handler == NULL) {
        return;
    }
    DetachVAlarm(alarm);
    alarm->handler = NULL;
}

void OS_CancelAllVAlarms(void)
{
    for (OSVAlarm *alarm = sQueue.head, *next; alarm != NULL; alarm = next) {
        next = alarm->next;
        OS_CancelVAlarm(alarm);
    }
}

void OS_CancelVAlarms(u32 tag)
{
    if (tag == 0) {
        return;
    }
    for (OSVAlarm *alarm = sQueue.head, *next; alarm != NULL; alarm = next) {
        next = alarm->next;
        if (alarm->tag == tag) {
            OS_CancelVAlarm(alarm);
        }
    }
}

void OS_DumpVAlarm(void)
{
    OS_TPrintf("---------------- current vcount = %d\n", (s16)GX_GetVCount());
    for (OSVAlarm *alarm = sQueue.head; alarm != NULL; alarm = alarm->next) {
        OS_TPrintf("%p fire=%d:%d delay=%d\n", (void *)alarm, alarm->frame, alarm->fire, alarm->delay);
    }
}

} // extern "C"
