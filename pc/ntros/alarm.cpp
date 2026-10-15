// Alarms: handlers called at a tick (NitroSDK os_alarm.c). As in the SDK, the queue's first alarm arms timer 1 and
// its interrupt runs the alarms that are due; the timer is our clock compared at every timeline event.
#include <mutex>

#include "internal.hpp"

namespace ntros {
namespace {

    constexpr int kAlarmTimer = 1;

    bool sUseAlarm;
    OSiAlarmQueue sQueue;
    std::recursive_mutex sLock; // libntr's host threads also set alarms (ntros has no threads of its own yet)
    bool sTimerArmed;
    OSTick sTimerFire;

    void ArrangeAlarms(void *);

    void SetTimer(OSAlarm *alarm)
    {
        OSi_EnterTimerCallback(kAlarmTimer, ArrangeAlarms, NULL);
        sTimerFire = alarm->fire;
        sTimerArmed = true;
    }

    void InsertAlarm(OSAlarm *alarm, OSTick fire)
    {
        if (alarm->period > 0) {
            OSTick tick = OS_GetTick();
            fire = alarm->start;
            if (alarm->start < tick) {
                fire += alarm->period * ((tick - alarm->start) / alarm->period + 1);
            }
        }
        alarm->fire = fire;
        for (OSAlarm *next = sQueue.head; next != NULL; next = next->next) {
            if ((s64)(fire - next->fire) >= 0) {
                continue;
            }
            alarm->prev = next->prev;
            next->prev = alarm;
            alarm->next = next;
            if (alarm->prev != NULL) {
                alarm->prev->next = alarm;
            } else {
                sQueue.head = alarm;
                SetTimer(alarm);
            }
            return;
        }
        alarm->next = NULL;
        alarm->prev = sQueue.tail;
        sQueue.tail = alarm;
        if (alarm->prev != NULL) {
            alarm->prev->next = alarm;
        } else {
            sQueue.head = alarm;
            SetTimer(alarm);
        }
    }

    // Timer 1 interrupt: the first alarm, if due (handlers run without the lock: they may set alarms)
    void ArrangeAlarms(void *)
    {
        std::unique_lock<std::recursive_mutex> lock(sLock);
        sTimerArmed = false;
        (void)OS_DisableIrqMask(OS_IE_TIMER1);
        OS_SetIrqCheckFlag(OS_IE_TIMER1);
        OSAlarm *alarm = sQueue.head;
        if (alarm == NULL) {
            return;
        }
        if (OS_GetTick() < alarm->fire) {
            SetTimer(alarm);
            return;
        }
        sQueue.head = alarm->next;
        if (sQueue.head == NULL) {
            sQueue.tail = NULL;
        } else {
            sQueue.head->prev = NULL;
        }
        OSAlarmHandler handler = alarm->handler;
        if (alarm->period == 0) {
            alarm->handler = NULL;
        }
        lock.unlock();
        if (handler != NULL) {
            handler(alarm->arg);
        }
        lock.lock();
        if (alarm->period > 0) {
            alarm->handler = handler;
            InsertAlarm(alarm, 0);
        }
        if (sQueue.head != NULL) {
            SetTimer(sQueue.head);
        }
    }

} // namespace

void RunAlarms()
{
    if (sTimerArmed && OS_GetTick() >= sTimerFire) {
        RaiseIrq(OS_IE_TIMER1);
    }
}

} // namespace ntros

using namespace ntros;

extern "C" {

void OS_InitAlarm(void)
{
    if (!sUseAlarm) {
        sUseAlarm = TRUE;
        sQueue.head = NULL;
        sQueue.tail = NULL;
        (void)OS_DisableIrqMask(OS_IE_TIMER1);
    }
}

void OS_EndAlarm(void)
{
    sUseAlarm = FALSE;
}

BOOL OS_IsAlarmAvailable(void)
{
    return sUseAlarm;
}

void OS_CreateAlarm(OSAlarm *alarm)
{
    alarm->handler = NULL;
    alarm->tag = 0;
}

void OS_SetAlarm(OSAlarm *alarm, OSTick tick, OSAlarmHandler handler, void *arg)
{
    std::lock_guard<std::recursive_mutex> lock(sLock);
    if (alarm == NULL || alarm->handler != NULL) {
        OS_Panic("alarm could be already used.");
        return;
    }
    alarm->period = 0;
    alarm->handler = handler;
    alarm->arg = arg;
    InsertAlarm(alarm, OS_GetTick() + tick);
}

void OS_SetPeriodicAlarm(OSAlarm *alarm, OSTick start, OSTick period, OSAlarmHandler handler, void *arg)
{
    std::lock_guard<std::recursive_mutex> lock(sLock);
    if (alarm == NULL || alarm->handler != NULL) {
        OS_Panic("alarm could be already used.");
        return;
    }
    alarm->period = period;
    alarm->start = start;
    alarm->handler = handler;
    alarm->arg = arg;
    InsertAlarm(alarm, 0);
}

void OS_SetAlarmTag(OSAlarm *alarm, u32 tag)
{
    alarm->tag = tag;
}

void OS_CancelAlarm(OSAlarm *alarm)
{
    std::lock_guard<std::recursive_mutex> lock(sLock);
    if (alarm->handler == NULL) {
        return;
    }
    OSAlarm *next = alarm->next;
    if (next == NULL) {
        sQueue.tail = alarm->prev;
    } else {
        next->prev = alarm->prev;
    }
    if (alarm->prev != NULL) {
        alarm->prev->next = next;
    } else {
        sQueue.head = next;
        if (next != NULL) {
            SetTimer(next);
        } else {
            sTimerArmed = false;
        }
    }
    alarm->handler = NULL;
    alarm->period = 0;
}

void OS_CancelAlarms(u32 tag)
{
    std::lock_guard<std::recursive_mutex> lock(sLock);
    if (tag == 0) {
        return;
    }
    for (OSAlarm *alarm = sQueue.head, *next; alarm != NULL; alarm = next) {
        next = alarm->next;
        if (alarm->tag == tag) {
            OS_CancelAlarm(alarm);
        }
    }
}

void OS_CancelAllAlarms(void)
{
    std::lock_guard<std::recursive_mutex> lock(sLock);
    for (OSAlarm *alarm = sQueue.head, *next; alarm != NULL; alarm = next) {
        next = alarm->next;
        OS_CancelAlarm(alarm);
    }
}

struct OSiAlarmQueue *OSi_GetAlarmQueue(void)
{
    return &sQueue;
}

} // extern "C"
