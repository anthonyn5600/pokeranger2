// The controls as the DS wires them (GBATEK "DS Keypad", "DS Touch Screen Controller"; what the SDK's ARM7 side does):
// - A, B, Select, Start, the D-pad, R and L drive KEYINPUT, which the ARM9 reads directly (0 = pressed). KEYCNT can
//   request the keypad interrupt for a set of them.
// - X, Y, the debug button and the hinge (lid) reach only the ARM7 (EXTKEYIN). Every 2094 ticks (4 ms) it copies
//   them to shared memory (HW_BUTTON_XY_BUF): X, Y and debug at bits 10, 11, 13 (0 = pressed), the lid at bit 15
//   (1 = closed). PAD_Read and PAD_DetectFold read them there.
// - The touch screen: on request the ARM7 measures the pen with the touch controller (12-bit raw positions) and puts
//   the result in shared memory (OS_GetSystemWork()->touch_panel), where the ARM9 copies it from (tp.cpp).
// The frontend reports the controls with NtrOs_SetInput.
#include <math.h>
#include <string.h>

#include "ntros.h"

#include "internal.hpp"

namespace ntros {
namespace {

    constexpr uint64_t kXYPeriodCycles = 2094 * 64; // the ARM7's X/Y alarm, in system clock cycles
    constexpr u16 kKeyInputMask = 0x03FF; // KEYINPUT: A B Select Start Right Left Up Down R L
    constexpr u16 kXYMask = PAD_BUTTON_X | PAD_BUTTON_Y;

    // The touch panel of this DS: how pen positions map to the controller's raw values. It defines the factory
    // calibration as two points (stored in the firmware's user settings, NVRAMConfigTpCalibData) and is linear
    // between them; positions count from pixel 0, as the SDK's conversion reads them.
    struct PanelPoint {
        u16 rawX, rawY;
        u8 x, y;
    };
    constexpr PanelPoint kPanel1 = { 0x02E0, 0x0330, 32, 32 };
    constexpr PanelPoint kPanel2 = { 0x0D40, 0x0CE0, 224, 160 };

    bool sInitialized;
    NtrOsInput sInput;
    uint64_t sNextXY;

    // A raw value at the middle of the pixel's range
    u16 PanelRaw(int pixel, u16 raw1, u16 raw2, int pixel1, int pixel2)
    {
        double raw = raw1 + (pixel + 0.5 - pixel1) * (double)(raw2 - raw1) / (pixel2 - pixel1);
        return (u16)lround(raw < 0 ? 0 : raw > 0xFFF ? 0xFFF : raw);
    }

    // The buttons' side of the read-only register
    void SetKeyInput(u16 buttons)
    {
        *(vu16 *)&reg_PAD_KEYINPUT = (u16)(kKeyInputMask & ~buttons);
    }

    void CheckKeyIrq()
    {
        u16 cnt = reg_PAD_KEYCNT;
        u16 select = cnt & kKeyInputMask;
        if (!(cnt & REG_PAD_KEYCNT_INTR_MASK) || select == 0) {
            return;
        }
        u16 held = sInput.buttons & select;
        if ((cnt & REG_PAD_KEYCNT_LOGIC_MASK) ? held == select : held != 0) {
            RaiseIrq(OS_IE_KEY);
        }
    }

} // namespace

// The ARM7 is ready (the SDK's PM_Init waits for that): its first X/Y copy, and the factory touch calibration in the
// user settings where these hold none (libntr's settings file leaves it zero)
void Input_Init()
{
    if (sInitialized) {
        return;
    }
    sInitialized = true;
    SetKeyInput(sInput.buttons);
    Input_UpdateXY();
    NVRAMConfig *info = (NVRAMConfig *)OS_GetSystemWork()->nvramUserInfo;
    NVRAMConfigTpCalibData &tp = info->ncd.tp;
    if (tp.raw_x1 == 0 && tp.raw_y1 == 0 && tp.raw_x2 == 0 && tp.raw_y2 == 0) {
        tp.raw_x1 = kPanel1.rawX;
        tp.raw_y1 = kPanel1.rawY;
        tp.dx1 = kPanel1.x;
        tp.dy1 = kPanel1.y;
        tp.raw_x2 = kPanel2.rawX;
        tp.raw_y2 = kPanel2.rawY;
        tp.dx2 = kPanel2.x;
        tp.dy2 = kPanel2.y;
    }
}

// After each timeline step: the ARM7's X/Y alarm
void Input_Step()
{
    if (!sInitialized) {
        return;
    }
    uint64_t now = Cycles();
    if (now >= sNextXY) {
        Input_UpdateXY();
    }
}

void Input_UpdateXY()
{
    u16 xy = (u16)((kXYMask & ~sInput.buttons) | PAD_BUTTON_DEBUG); // no debug button on a retail DS
    if (sInput.lidClosed) {
        xy |= PAD_DETECT_FOLD_MASK;
    }
    *(vu16 *)HW_BUTTON_XY_BUF = xy;
    uint64_t now = Cycles();
    sNextXY = now - now % kXYPeriodCycles + kXYPeriodCycles;
}

// The ARM7 measures the touch screen: raw result into shared memory
void Input_SampleTouch()
{
    SPITpData data;
    data.raw = 0;
    if (sInput.touching && !sInput.lidClosed) {
        int x = sInput.touchX < 0 ? 0 : sInput.touchX > 255 ? 255 : sInput.touchX;
        int y = sInput.touchY < 0 ? 0 : sInput.touchY > 191 ? 191 : sInput.touchY;
        data.e.x = PanelRaw(x, kPanel1.rawX, kPanel2.rawX, kPanel1.x, kPanel2.x);
        data.e.y = PanelRaw(y, kPanel1.rawY, kPanel2.rawY, kPanel1.y, kPanel2.y);
        data.e.touch = SPI_TP_TOUCH_ON;
        data.e.validity = SPI_TP_VALIDITY_VALID;
    }
    memcpy(OS_GetSystemWork()->touch_panel, data.bytes, sizeof(data.bytes));
}

const NtrOsInput &Input_Get()
{
    return sInput;
}

} // namespace ntros

using namespace ntros;

extern "C" void NtrOs_SetInput(const NtrOsInput *input)
{
    sInput = *input;
    if (!sInitialized) {
        return;
    }
    SetKeyInput(sInput.buttons);
    CheckKeyIrq();
}
