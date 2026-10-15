// The display timeline (GBATEK "LCD Dimensions and Timings"; event order as melonDS runs it) and the tick clock
#include <atomic>
#include <thread>

#include "ntros.h"

#include "internal.hpp"

namespace ntros {
namespace {

    NtrOsDisplay sDisplay;
    const std::thread::id sGameThread = std::this_thread::get_id(); // static init runs on the thread that runs main()

    // Next event: line sLine starts (phase 0) or reaches HBlank (phase 1)
    int sLine;
    int sPhase;
    uint64_t sFrame;
    std::atomic<uint64_t> sCycles;

    void StartLine()
    {
        OSIrqMask irq = 0;
        reg_GX_VCOUNT = (u16)sLine;
        u16 stat = reg_GX_DISPSTAT & ~0x0002; // HBlank flag off
        int match = (stat >> 8) | ((stat & 0x0080) << 1);
        if (sLine == match) {
            stat |= 0x0004;
            if (stat & 0x0020) {
                irq |= OS_IE_V_COUNT;
            }
        } else {
            stat &= ~0x0004;
        }
        if (sLine == kVisibleLines) {
            stat |= 0x0001;
            if (stat & 0x0008) {
                irq |= OS_IE_V_BLANK;
            }
        } else if (sLine == kLinesPerFrame - 1) {
            stat &= ~0x0001;
        }
        reg_GX_DISPSTAT = stat;
        if (sLine == 0 && sDisplay.beginFrame != NULL) {
            sDisplay.beginFrame();
        }
        if (sLine == kVisibleLines) {
            if (sDisplay.vblank != NULL) {
                sDisplay.vblank();
            }
            OSi_SetVBlankCount(OS_GetVBlankCount() + 1);
        }
        sPhase = 1;
        sCycles = (sFrame * kLinesPerFrame + sLine) * kLineCycles + kHBlankCycles;
        RaiseIrq(irq);
    }

    void StartHBlank()
    {
        u16 stat = reg_GX_DISPSTAT | 0x0002;
        reg_GX_DISPSTAT = stat;
        if (sLine < kVisibleLines && sDisplay.drawLine != NULL) {
            sDisplay.drawLine(sLine);
        }
        if (++sLine == kLinesPerFrame) {
            sLine = 0;
            sFrame++;
        }
        sPhase = 0;
        sCycles = (sFrame * kLinesPerFrame + sLine) * kLineCycles;
        RaiseIrq((stat & 0x0010) ? OS_IE_H_BLANK : 0);
        if (sLine == kVisibleLines && sDisplay.endFrame != NULL) {
            sDisplay.endFrame();
        }
    }

} // namespace

uint64_t Cycles()
{
    return sCycles;
}

bool OnGameThread()
{
    return std::this_thread::get_id() == sGameThread;
}

void Step()
{
    if (sPhase == 0) {
        StartLine();
    } else {
        StartHBlank();
    }
    RunAlarms();
}

} // namespace ntros

using namespace ntros;

extern "C" void NtrOs_SetDisplay(const NtrOsDisplay *display)
{
    sDisplay = *display;
}

extern "C" unsigned long long NtrOs_GetFrame(void)
{
    return sFrame;
}

extern "C" int NtrOs_GetLine(void)
{
    return sLine;
}

// Tick clock: the SDK counts system clock / 64 with timer 0 (OS_InitTick). Ours follows the timeline; each read
// returns a later value than the one before (on hardware, time passes while the game runs), so a loop that waits
// for the tick to change still ends.
namespace {
bool sTickAvailable;
int64_t sTickOffset;
std::atomic<uint64_t> sLastTick;
} // namespace

extern "C" {

vu64 OSi_TickCounter; // upper bits of the tick (os_entropy.c mixes it in)
BOOL OSi_NeedResetTimer;

void OS_InitTick(void)
{
    if (!sTickAvailable) {
        sTickAvailable = TRUE;
        sTickOffset = 0;
        sLastTick = 0;
    }
}

BOOL OS_IsTickAvailable(void)
{
    return sTickAvailable;
}

OSTick OS_GetTick(void)
{
    uint64_t now = (uint64_t)((int64_t)(Cycles() / 64) + sTickOffset);
    uint64_t last = sLastTick.load();
    uint64_t next;
    do {
        next = now > last ? now : last + 1;
    } while (!sLastTick.compare_exchange_weak(last, next));
    OSi_TickCounter = next >> 16;
    return next & 0xFFFFFFFFFFFFull; // 48-bit counter, as the SDK's
}

u16 OS_GetTickLo(void)
{
    return (u16)OS_GetTick();
}

u32 OSi_GetTick_noProfile(void)
{
    return (u32)OS_GetTick();
}

void OS_SetTick(OSTick count)
{
    sTickOffset = (int64_t)count - (int64_t)(Cycles() / 64);
    sLastTick = count > 0 ? count - 1 : 0;
}

} // extern "C"
