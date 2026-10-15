// Interrupts: IE / IF / IME, the CPU's IRQ disable flag, the interrupt table, and the waits for an interrupt
// (NitroSDK os_interrupt.c, os_irqTable.c, os_irqHandler.c, os_system.c)
#include "internal.hpp"

namespace ntros {
namespace {

    // The CPU's IRQ disable flag (CPSR I). Every thread has its own (the SDK saves CPSR with a thread's context).
    thread_local bool tIrqDisabled;

    // Time passes only while the game waits; this warns when a wait can never end (what the game waits for is off)
    constexpr uint64_t kStuckFrames = 600;

    uint64_t sHandlerRuns; // interrupt handlers run so far (OS_WaitAnyIrq before threads exist)
    int sIrqDepth;

} // namespace

bool &IrqDisabled()
{
    return tIrqDisabled;
}

bool InIrqHandler()
{
    return sIrqDepth > 0;
}

void RaiseIrq(OSIrqMask mask)
{
    reg_OS_IF |= mask;
    DispatchIrqs();
}

// OS_IrqHandler: the lowest pending interrupt first; its IF bit is acknowledged before its handler runs, with IRQs
// disabled in the CPU (a handler that enables them can be interrupted, as on hardware)
void DispatchIrqs()
{
    if (!OnGameThread()) {
        return;
    }
    bool handled = false;
    for (;;) {
        OSIrqMask pending = reg_OS_IE & reg_OS_IF;
        if (tIrqDisabled || !(reg_OS_IME & 1) || pending == 0) {
            break;
        }
        int bit = __builtin_ctz(pending);
        reg_OS_IF &= ~(1u << bit);
        tIrqDisabled = true;
        sIrqDepth++;
        sHandlerRuns++;
        OSIrqFunction handler = bit < OS_IRQ_TABLE_MAX ? OS_IRQTable[bit] : NULL;
        if (handler != NULL) {
            handler();
        }
        if (ThreadsRunning()) {
            WakeIrqWaiters();
        }
        sIrqDepth--;
        tIrqDisabled = false;
        handled = true;
    }
    // Returning from the interrupt switches to a thread it made ready (OS_IrqHandler_ThreadSwitch)
    if (handled && sIrqDepth == 0 && ThreadsRunning()) {
        RescheduleAfterIrq();
    }
}

// Runs the timeline until one of irqFlags is in the interrupt check flags (set by the handlers)
static void WaitForCheckFlag(OSIrqMask irqFlags)
{
    if (ThreadsRunning() && OnGameThread()) {
        // The thread sleeps; others run, or the timeline when none can (the SDK's idle thread)
        while (!(OS_GetIrqCheckFlag() & irqFlags)) {
            OS_SleepThread(&OSi_IrqThreadQueue);
        }
        return;
    }
    if (!OnGameThread()) {
        // Other host threads (libntr's, until ntros has threads) poll; the game thread moves the clock
        while (!(OS_GetIrqCheckFlag() & irqFlags)) {
            OS_Sleep(1);
        }
        return;
    }
    uint64_t start = Cycles();
    bool warned = false;
    while (!(OS_GetIrqCheckFlag() & irqFlags)) {
        Step();
        if (!warned && Cycles() - start > kStuckFrames * kLinesPerFrame * kLineCycles) {
            OS_TPrintf("ntros: waiting %llu frames for interrupt check flags %08x (IE %08x IME %d DISPSTAT %04x)\n",
                (unsigned long long)kStuckFrames,
                irqFlags,
                (u32)reg_OS_IE,
                reg_OS_IME,
                reg_GX_DISPSTAT);
            warned = true;
        }
    }
}

} // namespace ntros

using namespace ntros;

extern "C" {

OSIrqFunction OS_IRQTable[OS_IRQ_TABLE_MAX];
OSIrqCallbackInfo OSi_IrqCallbackInfo[OSi_IRQCALLBACK_NUM];
OSThreadQueue OSi_IrqThreadQueue;

void OS_IrqDummy(void)
{
}

// DMA / timer interrupts call the callback registered for them, once, then flag the interrupt as seen
static void IrqCallback(int index, int bit)
{
    OSIrqCallbackInfo &info = OSi_IrqCallbackInfo[index];
    void (*callback)(void *) = info.func;
    info.func = NULL;
    if (callback != NULL) {
        callback(info.arg);
    }
    OS_SetIrqCheckFlag(1u << bit);
    if (!info.enable) {
        (void)OS_DisableIrqMask(1u << bit);
    }
}

void OSi_IrqDma0(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_DMA0, REG_OS_IE_D0_SHIFT);
}
void OSi_IrqDma1(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_DMA1, REG_OS_IE_D1_SHIFT);
}
void OSi_IrqDma2(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_DMA2, REG_OS_IE_D2_SHIFT);
}
void OSi_IrqDma3(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_DMA3, REG_OS_IE_D3_SHIFT);
}
void OSi_IrqTimer0(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_TIMER0, REG_OS_IE_T0_SHIFT);
}
void OSi_IrqTimer1(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_TIMER1, REG_OS_IE_T1_SHIFT);
}
void OSi_IrqTimer2(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_TIMER2, REG_OS_IE_T2_SHIFT);
}
void OSi_IrqTimer3(void)
{
    IrqCallback(OSi_IRQCALLBACK_NO_TIMER3, REG_OS_IE_T3_SHIFT);
}

void OS_InitIrqTable(void)
{
    for (int i = 0; i < OS_IRQ_TABLE_MAX; i++) {
        OS_IRQTable[i] = OS_IrqDummy;
    }
    OS_IRQTable[REG_OS_IE_D0_SHIFT] = OSi_IrqDma0;
    OS_IRQTable[REG_OS_IE_D1_SHIFT] = OSi_IrqDma1;
    OS_IRQTable[REG_OS_IE_D2_SHIFT] = OSi_IrqDma2;
    OS_IRQTable[REG_OS_IE_D3_SHIFT] = OSi_IrqDma3;
    OS_IRQTable[REG_OS_IE_T0_SHIFT] = OSi_IrqTimer0;
    OS_IRQTable[REG_OS_IE_T1_SHIFT] = OSi_IrqTimer1;
    OS_IRQTable[REG_OS_IE_T2_SHIFT] = OSi_IrqTimer2;
    OS_IRQTable[REG_OS_IE_T3_SHIFT] = OSi_IrqTimer3;
    OS_InitThreadQueue(&OSi_IrqThreadQueue);
}

// DMA and timer interrupts keep their table entry (it calls the callback); the function becomes the callback
static OSIrqCallbackInfo *CallbackSlot(int bit)
{
    if (bit >= REG_OS_IE_D0_SHIFT && bit <= REG_OS_IE_D3_SHIFT) {
        return &OSi_IrqCallbackInfo[OSi_IRQCALLBACK_NO_DMA0 + bit - REG_OS_IE_D0_SHIFT];
    }
    if (bit >= REG_OS_IE_T0_SHIFT && bit <= REG_OS_IE_T3_SHIFT) {
        return &OSi_IrqCallbackInfo[OSi_IRQCALLBACK_NO_TIMER0 + bit - REG_OS_IE_T0_SHIFT];
    }
    return NULL;
}

void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function)
{
    for (int bit = 0; bit < OS_IRQ_TABLE_MAX; bit++) {
        if (!(intrBit & (1u << bit))) {
            continue;
        }
        OSIrqCallbackInfo *info = CallbackSlot(bit);
        if (info != NULL) {
            info->func = (void (*)(void *))function;
            info->arg = NULL;
            info->enable = TRUE;
        } else {
            OS_IRQTable[bit] = function;
        }
    }
}

OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit)
{
    for (int bit = 0; bit < OS_IRQ_TABLE_MAX; bit++) {
        if (intrBit & (1u << bit)) {
            OSIrqCallbackInfo *info = CallbackSlot(bit);
            return info != NULL ? (OSIrqFunction)info->func : OS_IRQTable[bit];
        }
    }
    return NULL;
}

// libntr's DMA copies are done at once and call their callback themselves: only remember it
void OSi_EnterDmaCallback(u32 dmaNo, void (*callback)(void *), void *arg)
{
    OSi_IrqCallbackInfo[dmaNo].func = callback;
    OSi_IrqCallbackInfo[dmaNo].arg = arg;
    OSi_IrqCallbackInfo[dmaNo].enable = (reg_OS_IE >> (REG_OS_IE_D0_SHIFT + dmaNo)) & 1;
}

void OSi_EnterTimerCallback(u32 timerNo, void (*callback)(void *), void *arg)
{
    OSIrqCallbackInfo &info = OSi_IrqCallbackInfo[OSi_IRQCALLBACK_NO_TIMER0 + timerNo];
    info.func = callback;
    info.arg = arg;
    (void)OS_EnableIrqMask(1u << (REG_OS_IE_T0_SHIFT + timerNo));
    info.enable = TRUE;
}

OSIrqMask OS_SetIrqMask(OSIrqMask intr)
{
    OSIrqMask previous = reg_OS_IE;
    reg_OS_IE = intr;
    DispatchIrqs();
    return previous;
}

OSIrqMask OS_EnableIrqMask(OSIrqMask intr)
{
    return OS_SetIrqMask(reg_OS_IE | intr);
}

OSIrqMask OS_DisableIrqMask(OSIrqMask intr)
{
    return OS_SetIrqMask(reg_OS_IE & ~intr);
}

// Acknowledges requests (on hardware writing 1 to an IF bit clears it)
OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr)
{
    OSIrqMask previous = reg_OS_IF;
    reg_OS_IF &= ~intr;
    return previous;
}

BOOL OS_EnableIrq(void)
{
    u16 previous = reg_OS_IME;
    reg_OS_IME = OS_IME_ENABLE;
    DispatchIrqs();
    return (BOOL)previous;
}

BOOL OS_DisableIrq(void)
{
    u16 previous = reg_OS_IME;
    reg_OS_IME = OS_IME_DISABLE;
    return (BOOL)previous;
}

BOOL OS_RestoreIrq(BOOL enable)
{
    u16 previous = reg_OS_IME;
    reg_OS_IME = (u16)enable;
    DispatchIrqs();
    return (BOOL)previous;
}

// IRQ stack checking: the IRQ stack is the host's
void OS_SetIrqStackChecker(void)
{
}

void OS_SetIrqStackWarningOffset(u32)
{
}

OSStackStatus OS_GetIrqStackStatus(void)
{
    return OS_STACK_NO_ERROR;
}

void OS_IrqHandler(void)
{
    DispatchIrqs();
}

void OS_IrqHandler_ThreadSwitch(void)
{
}

// CPSR: IRQ disable flag (FIQs aren't used)
OSIntrMode OS_EnableInterrupts(void)
{
    OSIntrMode previous = tIrqDisabled ? OS_INTRMODE_IRQ_DISABLE : OS_INTRMODE_IRQ_ENABLE;
    tIrqDisabled = false;
    DispatchIrqs();
    return previous;
}

OSIntrMode OS_DisableInterrupts(void)
{
    OSIntrMode previous = tIrqDisabled ? OS_INTRMODE_IRQ_DISABLE : OS_INTRMODE_IRQ_ENABLE;
    tIrqDisabled = true;
    return previous;
}

OSIntrMode OS_RestoreInterrupts(OSIntrMode state)
{
    OSIntrMode previous = tIrqDisabled ? OS_INTRMODE_IRQ_DISABLE : OS_INTRMODE_IRQ_ENABLE;
    tIrqDisabled = (state & OS_INTRMODE_IRQ_DISABLE) != 0;
    DispatchIrqs();
    return previous;
}

OSIntrMode OS_EnableInterrupts_IrqAndFiq(void)
{
    return OS_EnableInterrupts();
}

OSIntrMode OS_DisableInterrupts_IrqAndFiq(void)
{
    return OS_DisableInterrupts();
}

OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state)
{
    return OS_RestoreInterrupts(state);
}

OSIntrMode_Irq OS_GetCpsrIrq(void)
{
    return tIrqDisabled ? OS_INTRMODE_IRQ_DISABLE : OS_INTRMODE_IRQ_ENABLE;
}

OSProcMode OS_GetProcMode(void)
{
    return tIrqDisabled ? OS_PROCMODE_IRQ : OS_PROCMODE_SYS;
}

// Busy waits take no time (game code takes no time)
void OS_SpinWait(u32)
{
}

void OS_WaitIrq(BOOL clear, OSIrqMask irqFlags)
{
    if (clear) {
        OS_ClearIrqCheckFlag(irqFlags);
    }
    WaitForCheckFlag(irqFlags);
}

void OS_WaitInterrupt(BOOL clear, OSIrqMask irqFlags)
{
    OS_WaitIrq(clear, irqFlags);
}

// Until the next interrupt is handled
void OS_WaitAnyIrq(void)
{
    if (!OnGameThread()) {
        OS_Sleep(1);
        return;
    }
    if (ThreadsRunning()) {
        OS_SleepThread(&OSi_IrqThreadQueue);
        return;
    }
    uint64_t runs = sHandlerRuns;
    while (sHandlerRuns == runs) {
        Step();
    }
}

void OS_WaitVBlankIntr(void)
{
    OS_WaitIrq(TRUE, OS_IE_V_BLANK);
}

} // extern "C"
