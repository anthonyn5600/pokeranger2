// ntros internals shared between its files
#ifndef NTROS_INTERNAL_HPP
#define NTROS_INTERNAL_HPP

#include <nitro.h>
#include <stdint.h>

#include "ntros.h"

extern "C" OSThreadQueue OSi_IrqThreadQueue; // threads waiting in OS_WaitIrq (interrupts.cpp)

namespace ntros {

// DS clock: 33.513982 MHz system clock; a display line is 2130 cycles (355 dots of 6 cycles), HBlank starts 1606
// cycles into it; 263 lines per frame
constexpr uint64_t kLineCycles = 2130;
constexpr uint64_t kHBlankCycles = 1606;
constexpr int kLinesPerFrame = 263;
constexpr int kVisibleLines = 192;

// timeline.cpp
uint64_t Cycles(); // DS cycles since start (at the current timeline position)
void Step(); // advance the timeline to its next event (line start or HBlank start)
bool OnGameThread(); // the thread that runs the game's main loop (the only one that runs the timeline / handlers)
bool SleepFrame(); // sleep mode: the frontend shows a dark frame and reads input; false if it can't

// interrupts.cpp
void RaiseIrq(OSIrqMask mask); // set IF bits and run the handlers if they are let through
void DispatchIrqs(); // run the handlers of pending interrupts that IME, IE and the CPU's IRQ flag let through

bool &IrqDisabled(); // the running thread's CPSR I flag (thread.cpp swaps it with the coroutine)
bool InIrqHandler(); // an interrupt handler is running (game thread)

// thread.cpp
void WakeIrqWaiters(); // after an interrupt handler: threads in OS_WaitIrq check their flags again
void RescheduleAfterIrq(); // switch to a thread a handler made ready, if it outranks the running one
bool ThreadsRunning(); // OS_InitThread done

// alarm.cpp
void RunAlarms(); // alarms whose time has come (the SDK runs them from a timer interrupt)

// romfs.cpp
void RomFs_Init(); // build the ROM's header, file name table and file table from the files folder
void RomFs_Read(u32 offset, void *dst, u32 len); // read the virtual ROM

// input.cpp
void Input_Init(); // the ARM7 is ready (PM_Init)
void Input_Step(); // after each timeline step
void Input_UpdateXY(); // the ARM7 copies X, Y and the lid to HW_BUTTON_XY_BUF
void Input_SampleTouch(); // the ARM7 measures the touch screen into OS_GetSystemWork()->touch_panel
const NtrOsInput &Input_Get(); // the controls as the frontend last reported them

} // namespace ntros

#endif // NTROS_INTERNAL_HPP
