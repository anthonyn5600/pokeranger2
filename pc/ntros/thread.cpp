// Threads, mutexes and message queues (NitroSDK os_thread.c, os_mutex.c, os_message.c)
//
// The game's threads are coroutines on the game's host thread: one runs at a time, the highest-priority ready one,
// switching only where the SDK switches (a thread sleeps or wakes another, yields, exits, changes a priority, or an
// interrupt handler wakes one). When no thread is ready the display timeline runs (the SDK's idle thread waits for
// an interrupt) until one is.
//
// libntr's "ARM7" side threads (created before OS_InitThread, e.g. the wireless thread, or from libntr's own host
// threads) stay host threads running beside the game, as libntr ran them; they block on a condition variable.
//
// One lock guards all thread, queue, mutex and message state. It is held across every coroutine switch (all on the
// same host thread), and never while game code or the timeline runs.
#include <condition_variable>
#include <mutex>
#include <pthread.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <thread>
#include <ucontext.h>
#include <vector>

#include "internal.hpp"

namespace ntros {
namespace {

    constexpr size_t kFiberStackSize = 1 << 20; // host stacks: the game's DS-sized stacks are too small for PC code

    struct Fiber {
        bool host; // a host thread (libntr's ARM7 side) instead of a coroutine
        ucontext_t context;
        void *stack;
        bool irqDisabled; // the thread's CPSR I flag while it is switched out
        void (*func)(void *);
        void *arg;
        std::condition_variable wake; // host threads: wait for READY here
    };

    std::mutex sLock;
    using Lock = std::unique_lock<std::mutex>;

    bool sInitialized;
    OSThread sLauncherThread;
    Fiber sLauncherFiber;
    OSThread sIdleThread; // never runs: the idle loop is in Reschedule
    u32 sNextId = 1;
    int sDisableCount; // OS_DisableScheduler
    bool sScheduling; // the idle loop is running (game thread)
    bool sNeedReschedule; // a switch was due while an interrupt handler ran
    std::vector<Fiber *> sGraveyard; // stacks of exited coroutines, freed once another runs
    Fiber *sStartingFiber;
    thread_local OSThread *tHostThread; // the OSThread of a host thread
    OSSwitchThreadCallback sSwitchCallback;

    Fiber *FiberOf(const OSThread *thread)
    {
        return reinterpret_cast<Fiber *>(thread->win_sdlThread);
    }

    OSThread *Current()
    {
        if (!OnGameThread()) {
            return tHostThread;
        }
        return sInitialized ? OSi_ThreadInfo.current : NULL;
    }

    void InsertToList(OSThread *thread)
    {
        OSThread *t = OSi_ThreadInfo.list, *pre = NULL;
        while (t != NULL && t->priority < thread->priority) {
            pre = t;
            t = t->next;
        }
        if (pre == NULL) {
            thread->next = OSi_ThreadInfo.list;
            OSi_ThreadInfo.list = thread;
        } else {
            thread->next = pre->next;
            pre->next = thread;
        }
    }

    void RemoveFromList(OSThread *thread)
    {
        OSThread *t = OSi_ThreadInfo.list, *pre = NULL;
        while (t != NULL && t != thread) {
            pre = t;
            t = t->next;
        }
        if (t == NULL) {
            return;
        }
        if (pre == NULL) {
            OSi_ThreadInfo.list = thread->next;
        } else {
            pre->next = thread->next;
        }
    }

    void QueueInsert(OSThreadQueue *queue, OSThread *thread)
    {
        thread->queue = queue;
        thread->link.next = NULL;
        thread->link.prev = queue->tail;
        if (queue->tail != NULL) {
            queue->tail->link.next = thread;
        } else {
            queue->head = thread;
        }
        queue->tail = thread;
    }

    void QueueRemove(OSThreadQueue *queue, OSThread *thread)
    {
        if (thread->link.prev != NULL) {
            thread->link.prev->link.next = thread->link.next;
        } else {
            queue->head = thread->link.next;
        }
        if (thread->link.next != NULL) {
            thread->link.next->link.prev = thread->link.prev;
        } else {
            queue->tail = thread->link.prev;
        }
        thread->queue = NULL;
        thread->link.prev = thread->link.next = NULL;
    }

    void MakeReady(OSThread *thread)
    {
        thread->state = OS_THREAD_STATE_READY;
        Fiber *fiber = FiberOf(thread);
        if (fiber != NULL && fiber->host) {
            fiber->wake.notify_all();
        }
    }

    // The highest-priority ready coroutine
    OSThread *Select()
    {
        for (OSThread *t = OSi_ThreadInfo.list; t != NULL; t = t->next) {
            Fiber *fiber = FiberOf(t);
            if (t->state == OS_THREAD_STATE_READY && fiber != NULL && !fiber->host) {
                return t;
            }
        }
        return NULL;
    }

    void FreeGraveyard(Fiber *running)
    {
        for (size_t i = 0; i < sGraveyard.size();) {
            if (sGraveyard[i] != running) {
                munmap(sGraveyard[i]->stack, kFiberStackSize);
                delete sGraveyard[i];
                sGraveyard[i] = sGraveyard.back();
                sGraveyard.pop_back();
            } else {
                i++;
            }
        }
    }

    void FiberEntry()
    {
        Fiber *fiber = sStartingFiber;
        sLock.unlock(); // held by the switch that started us
        fiber->func(fiber->arg);
        OS_ExitThread();
    }

    void SwitchTo(OSThread *from, Fiber *fromFiber, OSThread *to)
    {
        Fiber *toFiber = FiberOf(to);
        if (sSwitchCallback != NULL) {
            sSwitchCallback(from, to);
        }
        OSi_ThreadInfo.current = to;
        fromFiber->irqDisabled = IrqDisabled();
        IrqDisabled() = toFiber->irqDisabled;
        sStartingFiber = toFiber;
        swapcontext(&fromFiber->context, &toFiber->context);
        // Running again (as from)
        FreeGraveyard(fromFiber);
    }

    // No thread can run: the timeline runs until an interrupt (or a host thread) makes one ready. This is the SDK's
    // idle thread, which runs with IRQs enabled whatever the sleeping thread's CPSR was. Lock held.
    OSThread *Idle(Lock &lock)
    {
        OSThread *next;
        bool irqDisabled = IrqDisabled();
        IrqDisabled() = false;
        sScheduling = true;
        while ((next = Select()) == NULL) {
            lock.unlock();
            Step();
            lock.lock();
        }
        sScheduling = false;
        IrqDisabled() = irqDisabled;
        return next;
    }

    // Switches to the highest-priority ready coroutine; with none ready, runs the timeline until one is.
    // Game thread, lock held.
    void Reschedule(Lock &lock)
    {
        if (!sInitialized || !OnGameThread() || sDisableCount > 0) {
            return;
        }
        if (InIrqHandler()) {
            sNeedReschedule = true;
            return;
        }
        if (sScheduling) {
            return; // the idle loop below picks the thread up
        }
        sNeedReschedule = false;
        OSThread *current = OSi_ThreadInfo.current;
        OSThread *next = Select();
        if (next == NULL) {
            next = Idle(lock);
        }
        if (next != current) {
            SwitchTo(current, FiberOf(current), next);
        }
    }

    // Sleeps the current thread on queue (NULL: on nothing) until woken. Lock held.
    void SleepLocked(Lock &lock, OSThreadQueue *queue)
    {
        OSThread *current = Current();
        if (current == NULL) {
            return;
        }
        if (queue != NULL) {
            QueueInsert(queue, current);
        }
        current->state = OS_THREAD_STATE_WAITING;
        Fiber *fiber = FiberOf(current);
        if (fiber != NULL && fiber->host) {
            fiber->wake.wait(lock, [current] { return current->state != OS_THREAD_STATE_WAITING; });
        } else {
            Reschedule(lock);
        }
    }

    void WakeupLocked(Lock &lock, OSThreadQueue *queue)
    {
        if (queue->head == NULL) {
            return;
        }
        while (queue->head != NULL) {
            OSThread *thread = queue->head;
            QueueRemove(queue, thread);
            MakeReady(thread);
        }
        Reschedule(lock);
    }

    void UnlockAllMutexLocked(OSThread *thread)
    {
        while (thread->mutexQueue.head != NULL) {
            OSMutex *mutex = OSi_RemoveMutexLinkFromQueue(&thread->mutexQueue);
            mutex->count = 0;
            mutex->thread = NULL;
            while (mutex->queue.head != NULL) {
                OSThread *t = mutex->queue.head;
                QueueRemove(&mutex->queue, t);
                MakeReady(t);
            }
        }
    }

    // Takes the thread out of the system: it never runs again; joiners wake
    void TerminateLocked(OSThread *thread)
    {
        UnlockAllMutexLocked(thread);
        if (thread->queue != NULL) {
            QueueRemove(thread->queue, thread);
        }
        RemoveFromList(thread);
        thread->state = OS_THREAD_STATE_TERMINATED;
        while (thread->joinQueue.head != NULL) {
            OSThread *t = thread->joinQueue.head;
            QueueRemove(&thread->joinQueue, t);
            MakeReady(t);
        }
    }

    void HostThreadMain(OSThread *thread)
    {
        tHostThread = thread;
        Fiber *fiber = FiberOf(thread);
        {
            Lock lock(sLock);
            fiber->wake.wait(lock, [thread] { return thread->state != OS_THREAD_STATE_WAITING; });
            if (thread->state == OS_THREAD_STATE_TERMINATED) {
                return;
            }
        }
        fiber->func(fiber->arg);
        OS_ExitThread();
    }

    // A host thread the OS never created (libntr's PXI, audio threads) needs a thread record to block
    OSThread *HostSelf()
    {
        if (tHostThread == NULL) {
            OSThread *thread = new OSThread();
            Fiber *fiber = new Fiber();
            fiber->host = true;
            thread->win_sdlThread = reinterpret_cast<SDL_Thread *>(fiber);
            thread->state = OS_THREAD_STATE_READY;
            thread->priority = OS_THREAD_PRIORITY_MAX;
            OS_InitThreadQueue(&thread->joinQueue);
            tHostThread = thread;
        }
        return tHostThread;
    }

} // namespace

void WakeIrqWaiters()
{
    Lock lock(sLock);
    WakeupLocked(lock, &OSi_IrqThreadQueue);
}

void RescheduleAfterIrq()
{
    if (sNeedReschedule) {
        Lock lock(sLock);
        Reschedule(lock);
    }
}

bool ThreadsRunning()
{
    return sInitialized;
}

} // namespace ntros

using namespace ntros;

extern "C" {

OSThreadInfo OSi_ThreadInfo;
OSThread OSi_LauncherThread;
OSThread OSi_IdleThread;
void *OSi_StackForDestructor;
s32 OSi_RescheduleCount;
void *OSi_SystemCallbackInSwitchThread;

// Linker-defined on the DS (stack sizes, DTCM arena start): placeholders, as in libntr
void SDK_SYS_STACKSIZE(void)
{
}
void SDK_IRQ_STACKSIZE(void)
{
}
void SDK_SECTION_ARENA_DTCM_START(void)
{
}
void SDK_AUTOLOAD_DTCM_END(void)
{
}

void OS_InitThread(void)
{
    Lock lock(sLock);
    if (sInitialized) {
        return;
    }
    // The launcher thread: the code running now (NitroMain), on the host's own stack
    OSThread *launcher = &OSi_LauncherThread;
    launcher->priority = OS_THREAD_LAUNCHER_PRIORITY;
    launcher->id = 0;
    launcher->state = OS_THREAD_STATE_READY;
    launcher->next = NULL;
    launcher->win_sdlThread = reinterpret_cast<SDL_Thread *>(&sLauncherFiber);
    OS_InitThreadQueue(&launcher->joinQueue);
    InsertToList(launcher);
    OSi_ThreadInfo.current = launcher;
    OSi_ThreadInfo.isNeedRescheduling = FALSE;
    OSi_ThreadInfo.irqDepth = 0;
    sIdleThread.priority = OS_THREAD_PRIORITY_MAX;
    sIdleThread.state = OS_THREAD_STATE_READY;
    sInitialized = true;
}

BOOL OS_IsThreadAvailable(void)
{
    return sInitialized;
}

OSThread *OSi_GetIdleThread(void)
{
    return &sIdleThread;
}

OSThread *WIN_OS_GetCurrentThread(void)
{
    OSThread *current = Current();
    return current != NULL ? current : (OnGameThread() ? &OSi_LauncherThread : HostSelf());
}

void OS_CreateThreadReal(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio)
{
    Lock lock(sLock);
    bool host = !sInitialized || !OnGameThread();
    thread->priority = prio;
    thread->id = sNextId++;
    thread->state = OS_THREAD_STATE_WAITING;
    thread->profiler = NULL;
    thread->stackBottom = (u64)stack;
    thread->stackTop = (u64)stack - stackSize;
    thread->stackWarningOffset = 0;
    OS_InitThreadQueue(&thread->joinQueue);
    thread->mutex = NULL;
    thread->mutexQueue.head = NULL;
    thread->mutexQueue.tail = NULL;
    thread->destructor = NULL;
    thread->userParameter = NULL;
    thread->systemErrno = 0;
    thread->queue = NULL;
    thread->link.prev = thread->link.next = NULL;
    for (int i = 0; i < OS_THREAD_SPECIFIC_MAX; i++) {
        thread->specific[i] = NULL;
    }
    thread->alarmForSleep = NULL;

    Fiber *fiber = new Fiber();
    fiber->host = host;
    fiber->func = func;
    fiber->arg = arg;
    thread->win_sdlThread = reinterpret_cast<SDL_Thread *>(fiber);
    InsertToList(thread);
    if (host) {
        std::thread(HostThreadMain, thread).detach();
        return;
    }
    fiber->stack = mmap(NULL, kFiberStackSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    getcontext(&fiber->context);
    fiber->context.uc_stack.ss_sp = fiber->stack;
    fiber->context.uc_stack.ss_size = kFiberStackSize;
    fiber->context.uc_link = NULL;
    makecontext(&fiber->context, FiberEntry, 0);
}

void OS_CreateThreadDebug(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio, const char *name, const char *filename, u32 line)
{
    snprintf(thread->funcName, sizeof(thread->funcName), "%s", name);
    snprintf(thread->filename, sizeof(thread->filename), "%s", filename);
    thread->lineno = line;
    OS_CreateThreadReal(thread, func, arg, stack, stackSize, prio);
}

void OS_ExitThread(void)
{
    OSThread *current = WIN_OS_GetCurrentThread();
    if (current->destructor != NULL) {
        OSThreadDestructor destructor = current->destructor;
        current->destructor = NULL;
        destructor(NULL);
    }
    Lock lock(sLock);
    TerminateLocked(current);
    Fiber *fiber = FiberOf(current);
    if (fiber == NULL || fiber->host) {
        lock.unlock();
        pthread_exit(NULL);
    }
    current->win_sdlThread = NULL;
    sGraveyard.push_back(fiber);
    // Never returns: nothing switches back to a terminated thread
    OSThread *next = Select();
    if (next == NULL) {
        next = Idle(lock);
    }
    SwitchTo(current, fiber, next);
    abort();
}

void OS_DestroyThread(OSThread *thread)
{
    if (thread == WIN_OS_GetCurrentThread()) {
        OS_ExitThread();
    }
    if (thread->alarmForSleep != NULL) {
        OS_CancelAlarm(thread->alarmForSleep);
        thread->alarmForSleep = NULL;
    }
    Lock lock(sLock);
    TerminateLocked(thread);
    Fiber *fiber = FiberOf(thread);
    if (fiber != NULL && !fiber->host) {
        thread->win_sdlThread = NULL;
        sGraveyard.push_back(fiber);
    } else if (fiber != NULL) {
        fiber->wake.notify_all(); // a host thread not started yet ends; a running one can't be stopped
    }
    Reschedule(lock);
}

void OS_KillThread(OSThread *thread, void *arg)
{
    (void)arg;
    OS_DestroyThread(thread);
}

void OS_KillThreadWithPriority(OSThread *thread, void *arg, u32 prio)
{
    (void)prio;
    OS_KillThread(thread, arg);
}

void OS_JoinThread(OSThread *thread)
{
    Lock lock(sLock);
    while (thread->state != OS_THREAD_STATE_TERMINATED) {
        SleepLocked(lock, &thread->joinQueue);
    }
}

BOOL OS_IsThreadTerminated(const OSThread *thread)
{
    return thread->state == OS_THREAD_STATE_TERMINATED;
}

void OS_SleepThread(OSThreadQueue *queue)
{
    Lock lock(sLock);
    SleepLocked(lock, queue);
}

void OS_SleepThreadDirect(OSThread *thread, OSThreadQueue *queue)
{
    Lock lock(sLock);
    if (thread == Current()) {
        SleepLocked(lock, queue);
        return;
    }
    if (queue != NULL) {
        QueueInsert(queue, thread);
    }
    thread->state = OS_THREAD_STATE_WAITING;
}

void OS_WakeupThread(OSThreadQueue *queue)
{
    Lock lock(sLock);
    WakeupLocked(lock, queue);
}

void OS_WakeupThreadDirect(OSThread *thread)
{
    Lock lock(sLock);
    MakeReady(thread);
    Reschedule(lock);
}

OSThread *OS_SelectThread(void)
{
    Lock lock(sLock);
    return Select();
}

void OS_RescheduleThread(void)
{
    Lock lock(sLock);
    Reschedule(lock);
}

// Behind the other threads of the same priority
void OS_YieldThread(void)
{
    Lock lock(sLock);
    OSThread *current = Current();
    if (current == NULL || !OnGameThread()) {
        lock.unlock();
        std::this_thread::yield();
        return;
    }
    OSThread *pre = NULL, *last = NULL, *tPre = NULL;
    int same = 0;
    for (OSThread *t = OSi_ThreadInfo.list; t != NULL; tPre = t, t = t->next) {
        if (t == current) {
            pre = tPre;
        }
        if (t->priority == current->priority) {
            last = t;
            same++;
        }
    }
    if (same <= 1 || last == current) {
        return;
    }
    if (pre == NULL) {
        OSi_ThreadInfo.list = current->next;
    } else {
        pre->next = current->next;
    }
    current->next = last->next;
    last->next = current;
    Reschedule(lock);
}

BOOL OS_SetThreadPriority(OSThread *thread, u32 prio)
{
    Lock lock(sLock);
    if (thread == &sIdleThread) {
        return FALSE;
    }
    if (thread->priority != prio) {
        RemoveFromList(thread);
        thread->priority = prio;
        InsertToList(thread);
        Reschedule(lock);
    }
    return TRUE;
}

u32 OS_GetThreadPriority(const OSThread *thread)
{
    return thread->priority;
}

static void SleepAlarmCallback(void *arg)
{
    OSThread **slot = (OSThread **)arg;
    OSThread *thread = *slot;
    *slot = NULL;
    thread->alarmForSleep = NULL;
    OS_WakeupThreadDirect(thread);
}

// A coroutine sleeps on the DS clock (an alarm wakes it); host threads sleep in real time
void OS_Sleep(u32 msec)
{
    OSThread *current = WIN_OS_GetCurrentThread();
    Fiber *fiber = FiberOf(current);
    if (!OnGameThread() || !sInitialized || fiber == NULL || fiber->host) {
        std::this_thread::sleep_for(std::chrono::milliseconds(msec));
        return;
    }
    OSAlarm alarm;
    OS_CreateAlarm(&alarm);
    OSThread *volatile slot = current;
    current->alarmForSleep = &alarm;
    OS_SetAlarm(&alarm, OS_MilliSecondsToTicks(msec), SleepAlarmCallback, (void *)&slot);
    while (slot != NULL) {
        OS_SleepThread(NULL);
    }
}

OSSwitchThreadCallback OS_SetSwitchThreadCallback(OSSwitchThreadCallback callback)
{
    OSSwitchThreadCallback previous = sSwitchCallback;
    sSwitchCallback = callback;
    return previous;
}

void OSi_SetSystemCallbackInSwitchThread(void *callback)
{
    OSi_SystemCallbackInSwitchThread = callback;
}

u32 OS_DisableScheduler(void)
{
    Lock lock(sLock);
    return (u32)sDisableCount++;
}

u32 OS_EnableScheduler(void)
{
    Lock lock(sLock);
    u32 previous = (u32)sDisableCount;
    if (sDisableCount > 0) {
        sDisableCount--;
    }
    return previous;
}

void OS_DumpThreadList(void)
{
    Lock lock(sLock);
    for (OSThread *t = OSi_ThreadInfo.list; t != NULL; t = t->next) {
        OS_TPrintf("thread %u prio %u state %d %s\n", t->id, t->priority, t->state, t->funcName);
    }
}

int OS_GetNumberOfThread(void)
{
    Lock lock(sLock);
    int count = 0;
    for (OSThread *t = OSi_ThreadInfo.list; t != NULL; t = t->next) {
        count++;
    }
    return count;
}

OSThread *OS_GetThread(u32 id)
{
    Lock lock(sLock);
    for (OSThread *t = OSi_ThreadInfo.list; t != NULL; t = t->next) {
        if (t->id == id) {
            return t;
        }
    }
    return NULL;
}

BOOL OS_IsThreadInList(const OSThread *thread)
{
    Lock lock(sLock);
    for (OSThread *t = OSi_ThreadInfo.list; t != NULL; t = t->next) {
        if (t == thread) {
            return TRUE;
        }
    }
    return FALSE;
}

// The host's stacks don't overflow into game memory: nothing to check
OSStackStatus OS_GetStackStatus(const OSThread *)
{
    return OS_STACK_NO_ERROR;
}

void OS_SetThreadStackWarningOffset(OSThread *thread, u32 offset)
{
    thread->stackWarningOffset = offset;
}

void OS_SetThreadDestructor(OSThread *thread, OSThreadDestructor dtor)
{
    thread->destructor = dtor;
}

OSThreadDestructor OS_GetThreadDestructor(const OSThread *thread)
{
    return thread->destructor;
}

void OS_SetThreadDestructorStack(void *stack)
{
    OSi_StackForDestructor = stack;
}

void OS_SetThreadParameter(OSThread *thread, void *parameter)
{
    thread->userParameter = parameter;
}

void *OS_GetThreadParameter(const OSThread *thread)
{
    return thread->userParameter;
}

int OS_GetErrno(void)
{
    return WIN_OS_GetCurrentThread()->systemErrno;
}

void OSi_SetSystemErrno(OSThread *thread, int myErrno)
{
    thread->systemErrno = myErrno;
}

int OSi_GetSystemErrno(const OSThread *thread)
{
    return thread->systemErrno;
}

u32 OSi_GetCurrentStackPointer(void)
{
    return 0;
}

u32 OSi_GetSystemStackPointer(void)
{
    return 0;
}

// Mutexes: recursive, owned by a thread; waiters sleep on the mutex's queue
OSMutex *OSi_RemoveMutexLinkFromQueue(OSMutexQueue *queue)
{
    OSMutex *mutex = queue->head;
    if (mutex != NULL) {
        queue->head = mutex->link.next;
        if (queue->head != NULL) {
            queue->head->link.prev = NULL;
        } else {
            queue->tail = NULL;
        }
    }
    return mutex;
}

static void MutexEnqueue(OSThread *thread, OSMutex *mutex)
{
    OSMutex *prev = thread->mutexQueue.tail;
    if (prev == NULL) {
        thread->mutexQueue.head = mutex;
    } else {
        prev->link.next = mutex;
    }
    mutex->link.prev = prev;
    mutex->link.next = NULL;
    thread->mutexQueue.tail = mutex;
}

static void MutexDequeue(OSThread *thread, OSMutex *mutex)
{
    OSMutex *next = mutex->link.next, *prev = mutex->link.prev;
    if (next == NULL) {
        thread->mutexQueue.tail = prev;
    } else {
        next->link.prev = prev;
    }
    if (prev == NULL) {
        thread->mutexQueue.head = next;
    } else {
        prev->link.next = next;
    }
}

void OS_InitMutex(OSMutex *mutex)
{
    OS_InitThreadQueue(&mutex->queue);
    mutex->thread = NULL;
    mutex->count = 0;
}

void OS_LockMutex(OSMutex *mutex)
{
    Lock lock(sLock);
    OSThread *current = WIN_OS_GetCurrentThread();
    for (;;) {
        if (mutex->thread == NULL) {
            mutex->thread = current;
            mutex->count++;
            MutexEnqueue(current, mutex);
            return;
        }
        if (mutex->thread == current) {
            mutex->count++;
            return;
        }
        current->mutex = mutex;
        SleepLocked(lock, &mutex->queue);
        current->mutex = NULL;
    }
}

void OS_UnlockMutex(OSMutex *mutex)
{
    Lock lock(sLock);
    OSThread *current = WIN_OS_GetCurrentThread();
    if (mutex->thread == current && --mutex->count == 0) {
        MutexDequeue(current, mutex);
        mutex->thread = NULL;
        WakeupLocked(lock, &mutex->queue);
    }
}

BOOL OS_TryLockMutex(OSMutex *mutex)
{
    Lock lock(sLock);
    OSThread *current = WIN_OS_GetCurrentThread();
    if (mutex->thread == NULL) {
        mutex->thread = current;
        mutex->count++;
        MutexEnqueue(current, mutex);
        return TRUE;
    }
    if (mutex->thread == current) {
        mutex->count++;
        return TRUE;
    }
    return FALSE;
}

void OSi_UnlockAllMutex(OSThread *thread)
{
    Lock lock(sLock);
    UnlockAllMutexLocked(thread);
    Reschedule(lock);
}

// Message queues: a ring of msgCount messages; senders wait while it is full, receivers while it is empty
void OS_InitMessageQueue(OSMessageQueue *mq, OSMessage *msgArray, s32 msgCount)
{
    OS_InitThreadQueue(&mq->queueSend);
    OS_InitThreadQueue(&mq->queueReceive);
    mq->msgArray = msgArray;
    mq->msgCount = msgCount;
    mq->firstIndex = 0;
    mq->usedCount = 0;
}

BOOL OS_SendMessage(OSMessageQueue *mq, OSMessage msg, s32 flags)
{
    Lock lock(sLock);
    while (mq->msgCount <= mq->usedCount) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            return FALSE;
        }
        SleepLocked(lock, &mq->queueSend);
    }
    mq->msgArray[(mq->firstIndex + mq->usedCount) % mq->msgCount] = msg;
    mq->usedCount++;
    WakeupLocked(lock, &mq->queueReceive);
    return TRUE;
}

BOOL OS_ReceiveMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags)
{
    Lock lock(sLock);
    while (mq->usedCount == 0) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            return FALSE;
        }
        SleepLocked(lock, &mq->queueReceive);
    }
    if (msg != NULL) {
        *msg = mq->msgArray[mq->firstIndex];
    }
    mq->firstIndex = (mq->firstIndex + 1) % mq->msgCount;
    mq->usedCount--;
    WakeupLocked(lock, &mq->queueSend);
    return TRUE;
}

// In front of the queue (urgent)
BOOL OS_JamMessage(OSMessageQueue *mq, OSMessage msg, s32 flags)
{
    Lock lock(sLock);
    while (mq->msgCount <= mq->usedCount) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            return FALSE;
        }
        SleepLocked(lock, &mq->queueSend);
    }
    mq->firstIndex = (mq->firstIndex + mq->msgCount - 1) % mq->msgCount;
    mq->msgArray[mq->firstIndex] = msg;
    mq->usedCount++;
    WakeupLocked(lock, &mq->queueReceive);
    return TRUE;
}

BOOL OS_ReadMessage(OSMessageQueue *mq, OSMessage *msg, s32 flags)
{
    Lock lock(sLock);
    while (mq->usedCount == 0) {
        if (!(flags & OS_MESSAGE_BLOCK)) {
            return FALSE;
        }
        SleepLocked(lock, &mq->queueReceive);
    }
    if (msg != NULL) {
        *msg = mq->msgArray[mq->firstIndex];
    }
    return TRUE;
}

} // extern "C"
