#include "CPowerManage.hpp"

#include <nitro.h>

#include "SaveData.hpp"

static CPowerManage sPowerManage;

void CPowerManage::Init()
{
    unk_4 = 0;
    unk_8 = 0;
}

void CPowerManage::CheckFold()
{
    if ((!unk_4) == FALSE) {
        return;
    }

    if (PAD_DetectFold()) {
        switch (unk_8) {
        case 0: {
            RTCTime time;
            RTCDate date;

            RTC_GetTime(&time);
            RTC_GetDate(&date);

            MAIN_BSS_020B26A0.CheckElapsedTime(&time, &date);
            PM_GoSleepMode(PM_TRIGGER_COVER_OPEN | PM_TRIGGER_CARD, 0, 0);

            RTC_GetTime(&time);
            RTC_GetDate(&date);

            MAIN_BSS_020B26A0.m_lastTime = time;
            MAIN_BSS_020B26A0.m_lastDate = date;

            return;
        }

        case 1:
            if (PM_GetLCDPower() != PM_LCD_POWER_ON) {
                return;
            }

            PM_SetLCDPower(PM_LCD_POWER_OFF);
            return;

        default:
            return;
        }
    }

    if (PM_GetLCDPower() != PM_LCD_POWER_OFF) {
        return;
    }

    PM_SetLCDPower(PM_LCD_POWER_ON);
}

BOOL CPowerManage::Initialize()
{
    sPowerManage.Init();
    return TRUE;
}

void CPowerManage::Process()
{
    sPowerManage.CheckFold();
}

void CPowerManage::AllowSleep(u32 bit)
{
    sPowerManage.unk_4 &= ~(1 << bit);
}

void CPowerManage::BlockSleep(u32 bit)
{
    sPowerManage.unk_4 |= 1 << bit;
}

void CPowerManage::SetMode(u32 mode)
{
    sPowerManage.unk_8 = mode;
}

CPowerManage::~CPowerManage()
{
}
