// The SDK's power management API (PM_*), with the ARM7's part done here: LCD power (POWCNT), the backlights, sleep
// mode and power off. The battery is always fine.
//
// Sleep (PM_GoSleepMode) as on the DS: the pre-sleep callbacks run, the backlights go off, the displays turn off over
// two frames, then the system stops: no display lines, no interrupts, no ticks. The frontend's sleepFrame keeps the
// window going (dark screens, input) until a wake-up trigger holds: the lid opens, or the buttons match the key
// pattern. Then the LCDs, displays and interrupts come back and the post-sleep callbacks run.
#include <stdio.h>
#include <stdlib.h>

#include "ntros.h"

#include "internal.hpp"

namespace {

constexpr u32 kLCDOnWaitFrames = 7; // after turning the LCDs off, they stay off at least this long (PM_SetLCDPower)

bool sInitialized;
u32 sLCDOffCount; // VBlank count when the LCDs were last turned off
PMBackLightSwitch sBackLight[2] = { PM_BACKLIGHT_ON, PM_BACKLIGHT_ON };
PMSleepCallbackInfo *sPreSleep;
PMSleepCallbackInfo *sPostSleep;

void Prepend(PMSleepCallbackInfo **list, PMSleepCallbackInfo *info)
{
    info->next = *list;
    *list = info;
}

void Append(PMSleepCallbackInfo **list, PMSleepCallbackInfo *info)
{
    info->next = NULL;
    while (*list != NULL) {
        list = &(*list)->next;
    }
    *list = info;
}

void Delete(PMSleepCallbackInfo **list, PMSleepCallbackInfo *info)
{
    for (; *list != NULL; list = &(*list)->next) {
        if (*list == info) {
            *list = info->next;
            return;
        }
    }
}

void Run(PMSleepCallbackInfo *list)
{
    for (; list != NULL; list = list->next) {
        list->callback(list->arg);
    }
}

// The display runs on (with the interrupts as they are set) until the next VBlank starts
void WaitVBlank()
{
    u32 count = OS_GetVBlankCount();
    while (count == OS_GetVBlankCount()) {
        ntros::Step();
    }
}

void SetLCDs(BOOL on)
{
    GXi_PowerLCD(on);
    if (!on) {
        sLCDOffCount = OS_GetVBlankCount();
    }
}

bool KeysWake(PMLogic logic, u16 pattern, u16 buttons)
{
    u16 held = buttons & pattern;
    return pattern != 0 && (logic == PM_PAD_LOGIC_AND ? held == pattern : held != 0);
}

// Asleep: until a wake-up trigger. The lid wakes the DS when it opens (after being closed, as it is when the game
// sleeps on it); the buttons when they match the pattern.
void Sleep(PMWakeUpTrigger trigger, PMLogic logic, u16 keyPattern)
{
    bool closed = ntros::Input_Get().lidClosed != 0;
    for (;;) {
        if (!ntros::SleepFrame()) {
            OS_TPrintf("ntros: sleep mode, but the frontend can't idle: waking at once\n");
            return;
        }
        const NtrOsInput &input = ntros::Input_Get();
        if ((trigger & PM_TRIGGER_COVER_OPEN) && closed && !input.lidClosed) {
            return;
        }
        closed = input.lidClosed != 0;
        if ((trigger & PM_TRIGGER_KEY) && KeysWake(logic, keyPattern, input.buttons)) {
            return;
        }
    }
}

} // namespace

extern "C" {

void PM_Init(void)
{
    if (sInitialized) {
        return;
    }
    sInitialized = true;
    ntros::Input_Init();
    sLCDOffCount = OS_GetVBlankCount();
}

BOOL PM_SetLCDPower(PMLCDPower sw)
{
    if (sw != PM_LCD_POWER_ON) {
        SetLCDs(FALSE);
        return TRUE;
    }
    if (OS_GetVBlankCount() - sLCDOffCount <= kLCDOnWaitFrames) {
        return FALSE;
    }
    SetLCDs(TRUE);
    return TRUE;
}

PMLCDPower PM_GetLCDPower(void)
{
    return (reg_GX_POWCNT & REG_GX_POWCNT_LCD_MASK) ? PM_LCD_POWER_ON : PM_LCD_POWER_OFF;
}

u32 PM_SetBackLight(PMLCDTarget target, PMBackLightSwitch sw)
{
    if (target == PM_LCD_TOP || target == PM_LCD_ALL) {
        sBackLight[0] = sw;
    }
    if (target == PM_LCD_BOTTOM || target == PM_LCD_ALL) {
        sBackLight[1] = sw;
    }
    return PM_SUCCESS;
}

u32 PM_GetBackLight(PMBackLightSwitch *top, PMBackLightSwitch *bottom)
{
    if (top != NULL) {
        *top = sBackLight[0];
    }
    if (bottom != NULL) {
        *bottom = sBackLight[1];
    }
    return PM_SUCCESS;
}

u32 PM_GetBattery(PMBattery *batteryBuf)
{
    *batteryBuf = PM_BATTERY_HIGH;
    return PM_SUCCESS;
}

void PM_GoSleepMode(PMWakeUpTrigger trigger, PMLogic logic, u16 keyPattern)
{
    Run(sPreSleep);

    BOOL prevIrq = OS_DisableIrq();
    OSIntrMode prevIntrMode = OS_DisableInterrupts();
    OSIrqMask prevIrqMask = OS_DisableIrqMask((1 << OS_IRQ_TABLE_MAX) - 1);
    (void)OS_SetIrqMask(OS_IE_FIFO_RECV);
    (void)OS_RestoreInterrupts(prevIntrMode);
    (void)OS_EnableIrq();

    // No Game Pak (GBA slot) on PC; the card is never pulled out
    trigger &= ~PM_TRIGGER_CARTRIDGE;

    u32 prevDispCnt = reg_GX_DISPCNT;
    u32 prevDispCntSub = reg_GXS_DB_DISPCNT;
    PMLCDPower prevLCDPower = PM_GetLCDPower();
    PMBackLightSwitch prevTop, prevBottom;
    (void)PM_GetBackLight(&prevTop, &prevBottom);
    (void)PM_SetBackLight(PM_LCD_ALL, PM_BACKLIGHT_OFF);

    WaitVBlank();
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~REG_GX_DISPCNT_MODE_MASK;
    GXS_DispOff();
    WaitVBlank();
    WaitVBlank();

    Sleep(trigger, logic, keyPattern);

    // Awake: the ARM7 restores the backlights and reads the buttons again
    (void)PM_SetBackLight(PM_LCD_TOP, prevTop);
    (void)PM_SetBackLight(PM_LCD_BOTTOM, prevBottom);
    ntros::Input_UpdateXY();
    if (prevLCDPower == PM_LCD_POWER_ON) {
        GXi_PowerLCD(TRUE); // without PM_SetLCDPower's wait
    }
    reg_GX_DISPCNT = prevDispCnt;
    reg_GXS_DB_DISPCNT = prevDispCntSub;

    (void)OS_DisableInterrupts();
    (void)OS_SetIrqMask(prevIrqMask);
    (void)OS_RestoreInterrupts(prevIntrMode);
    (void)OS_RestoreIrq(prevIrq);

    Run(sPostSleep);
}

// The DS turns off: the program ends
u32 PM_ForceToPowerOff(void)
{
    OS_TPrintf("ntros: power off\n");
    fflush(stdout);
    exit(0);
}

void PM_AppendPreSleepCallback(PMSleepCallbackInfo *info)
{
    Append(&sPreSleep, info);
}

void PM_PrependPreSleepCallback(PMSleepCallbackInfo *info)
{
    Prepend(&sPreSleep, info);
}

void PM_AppendPostSleepCallback(PMSleepCallbackInfo *info)
{
    Append(&sPostSleep, info);
}

void PM_PrependPostSleepCallback(PMSleepCallbackInfo *info)
{
    Prepend(&sPostSleep, info);
}

void PM_DeletePreSleepCallback(PMSleepCallbackInfo *info)
{
    Delete(&sPreSleep, info);
}

void PM_DeletePostSleepCallback(PMSleepCallbackInfo *info)
{
    Delete(&sPostSleep, info);
}

} // extern "C"
