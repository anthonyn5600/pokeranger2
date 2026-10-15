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

// pxi.cpp
using PxiService = void (*)(int tag, uPtr data, BOOL err);
void Pxi_SetArm7Service(int tag, PxiService service); // an ARM7 part of ntros takes this tag's words
void Pxi_SendToArm9(int tag, uPtr data, BOOL err); // a word for the game (FIFO receive interrupt)
void Pxi_Step(); // after each timeline step: deliver words sent from other threads

// spu.cpp: the sound hardware. Register offsets from 0x04000400; SAD / DAD are host pointers.
void Spu_Init();
void Spu_RunTo(uint64_t cycles); // produce the output up to this DS time
void Spu_FlushOutput(); // hand buffered output to the frontend
void Spu_Write8(u32 offset, u8 value);
void Spu_Write16(u32 offset, u16 value);
void Spu_Write32(u32 offset, u32 value);
u8 Spu_Read8(u32 offset);
u32 Spu_Read32(u32 offset);
void Spu_SetSource(int ch, const void *address);
void Spu_SetCaptureDestination(int capture, void *address);

// sound_driver.cpp: the ARM7's sound driver
void Sound_Init(); // the ARM7 starts its sound thread
void Sound_Step(); // after each timeline step: sound frames and alarms that are due

} // namespace ntros

#endif // NTROS_INTERNAL_HPP
