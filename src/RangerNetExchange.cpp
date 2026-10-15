#include "RangerNetExchange.hpp"

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "DiskHPTable.hpp"
#include "RangerNetMenu.hpp"
#include "RangerNetMywh.hpp"
#include "SaveManager.hpp"

// RangerNetWireless.cpp init parameter
struct WhId {
    u32 unk_00 : 8;
    u32 unk_08 : 4;
    u32 unk_0C : 4;
    u32 unk_10 : 16;
};

struct WhInitParam {
    WhId id;
    u16 *unk_04;
    u16 *unk_08;
};

extern "C" void DownloadMissionRecord_SetTransferred(DownloadMissionRecord *obj, int bit);

// RangerNetWireless.cpp
int Wireless_GetWorkSize();
void Wireless_Init(WhInitParam *param, u32 buf);
void Wireless_Update();
void Wireless_StartParent();
void Wireless_DisconnectOthers(u32 macLo);
BOOL Wireless_GetConnectedCount();
BOOL ov11_0212669C();
u32 Wireless_GetPartnerMac(int n);
void Wireless_StartSend(void *data, int size, int id);
void ov11_02126770();
void Wireless_StartReceive(void *data);
BOOL Wireless_IsSendDone();
BOOL Wireless_IsReceiveDone();
BOOL ov11_02126890();
BOOL ov11_021268E0();
void Wireless_End();
int Wireless_IsFinished();
void Wireless_SplitNumber(u32 value, u32 *lo, u32 *hi);

static void SplitNumber(u32 value, u32 *lo, u32 *hi);

void RangerNetExchange::Init()
{
}

RangerNetExchange::RangerNetExchange(RangerNetMenu *menu)
{
    Init();
    unk_194 = menu;
    unk_05C = (u8 *)operator new[](Wireless_GetWorkSize());
    unk_060 = new UnkClass_0212CE58_000;
    unk_064 = new UnkClass_0212CE58_000;
    unk_04C = new u8[Mywh_GetWorkSize()];
    unk_050 = new u8[0xF000];
    unk_150 = 0;
    SetState(0);
}

RangerNetExchange::~RangerNetExchange()
{
    if (unk_05C != NULL) {
        delete[] unk_05C;
    }
    if (unk_060 != NULL) {
        delete unk_060;
    }
    if (unk_064 != NULL) {
        delete unk_064;
    }
    if (unk_050 != NULL) {
        delete[] unk_050;
    }
    if (unk_04C != NULL) {
        delete[] unk_04C;
    }
}

int RangerNetExchange::Update()
{
    if (unk_194->CheckCancel() < 0) {
        unk_194->ShowMessage(15, 1, 0, 1);
        unk_194->StopConnecting();
        switch (unk_150) {
        case 2:
        case 3:
        case 4:
            Mywh_Finalize();
            SetState(20);
            break;
        default:
            if (unk_06C != 0) {
                Wireless_End();
            }
            SetState(18);
            break;
        }
        return unk_150;
    }
    if (unk_06C != 0) {
        Wireless_Update();
        if (Wireless_IsFinished()) {
            unk_06C = 0;
        }
    }
    switch (unk_150) {
    default:
    case 0:
    case 1:
    case 5:
    case 6:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 15:
        break;
    case 14:
        UpdateRecruit();
        unk_194->SetLinkIcon(2, -1);
        break;
    case 16:
        UpdateConfirm();
        unk_194->SetLinkIcon(2, -1);
        break;
    case 17:
        UpdateTransfer();
        unk_194->SetLinkIcon(2, -1);
        break;
    case 18:
        unk_194->SetLinkIcon(2, -1);
        if (Wireless_IsFinished() && unk_194->CheckContinue()) {
            return 10;
        }
        break;
    case 2:
        UpdateLocalScan();
        break;
    case 3:
        unk_194->SetLinkIcon(2, Mywh_GetLinkLevel());
        UpdateLocalSelect();
        break;
    case 4:
        unk_194->SetLinkIcon(2, Mywh_GetLinkLevel());
        UpdateLocalReceive();
        break;
    case 7:
        UpdateLocalSave();
        break;
    case 19:
        unk_194->SetLinkIcon(2, -1);
        break;
    case 20:
        unk_194->SetLinkIcon(2, -1);
        if (unk_194->CheckContinue()) {
            return 10;
        }
        break;
    }
    return unk_150;
}

void RangerNetExchange::UpdateRecruit()
{
    switch (unk_152) {
    case 0:
        if (unk_151 == 16) {
            unk_152 = 1;
            break;
        }
        unk_144 = 30;
        unk_152 = 4;
        break;
    case 1:
        if (unk_06C != 0) {
            break;
        }
        unk_144 = 10;
        unk_152 = 6;
        break;
    case 4:
        unk_152 = 5;
        break;
    case 5:
        unk_144 = 10;
        unk_152 = 6;
        break;
    case 6:
        if (--unk_144 != 0) {
            break;
        }
        unk_152 = 7;
        unk_144 = 7200;
        unk_153 = 1;
        StartWireless();
        Wireless_StartParent();
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        unk_06C = 1;
        break;
    case 7:
        switch (unk_153) {
        case 1:
            unk_194->UpdateWaitIcon(1);
            if (Wireless_GetConnectedCount()) {
                unk_153 = 2;
                ov11_02126770();
                unk_144 = 7200;
                unk_153 = 4;
                break;
            }
            if (--unk_144 != 0) {
                break;
            }
            unk_153 = 6;
            unk_144 = 60;
            if (unk_06C != 0) {
                Wireless_End();
            }
            break;
        case 4:
            unk_194->UpdateWaitIcon(1);
            if (--unk_144 == 0 || !ov11_02126890()) {
                unk_153 = 7;
                unk_144 = 60;
                unk_194->UpdateWaitIcon(0);
                if (unk_06C != 0) {
                    Wireless_End();
                }
                break;
            }
            if (!ov11_0212669C()) {
                break;
            }
            unk_144 = 30;
            unk_153 = 5;
            unk_194->UpdateWaitIcon(0);
            break;
        case 5:
            if (ov11_021268E0()) {
                if (unk_144 != 0) {
                    unk_144--;
                    break;
                }
                if (ov11_0212669C() < 1) {
                    break;
                }
                unk_068 = 0;
                Wireless_DisconnectOthers(Wireless_GetPartnerMac(0));
                unk_152 = 8;
                unk_194->ShowMessage(6, 3, 0, 1);
                CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
                CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
                break;
            }
            unk_153 = 7;
            unk_144 = 60;
            if (unk_06C != 0) {
                Wireless_End();
            }
            break;
        case 6:
            if (unk_144 != 0) {
                unk_144--;
                break;
            }
            unk_194->ShowMessage(5, 3, 0, 1);
            unk_194->HideAllButtons();
            unk_152 = 11;
            unk_194->StopConnecting();
            break;
        case 7:
            if (unk_144 != 0) {
                unk_144--;
                break;
            }
            unk_194->ShowMessage(7, 3, 0, 1);
            unk_194->HideAllButtons();
            unk_194->UpdateWaitIcon(0);
            unk_194->StopConnecting();
            unk_152 = 11;
            break;
        }
        break;
    case 8:
        if (!unk_194->CheckContinue()) {
            break;
        }
        MI_CpuClear16(unk_060, 4);
        Wireless_StartReceive(unk_060);
        unk_152 = 10;
        break;
    case 10:
        SetState(16);
        break;
    case 11:
        if (unk_194->CheckContinue()) {
            unk_152 = 12;
        }
        break;
    case 12:
        Finish();
        break;
    }
}

void RangerNetExchange::UpdateConfirm()
{
    u32 lo, hi;

    switch (unk_152) {
    case 0:
        if (ov11_021268E0()) {
            if (!Wireless_IsReceiveDone()) {
                break;
            }
            unk_144 = 30;
            unk_152 = 1;
            break;
        }
        unk_152 = 20;
        break;
    case 1:
        if (--unk_144 == 0) {
            unk_152 = 4;
        }
        break;
    case 4:
        if (!ov11_021268E0()) {
            unk_152 = 20;
        } else {
            unk_152 = 5;
        }
        break;
    case 5:
        unk_152 = 8;
        Wireless_SplitNumber(Wireless_GetPartnerMac(0), &lo, &hi);
        unk_194->ShowMessage(13, 3, 4, 1);
        unk_194->SetNumberArg(0, ParseNumber(unk_060->id));
        unk_194->SetNumberArg(1, lo);
        unk_194->SetNumberArg(2, hi);
        unk_194->ShowButtons(16);
        unk_144 = 3600;
        break;
    case 20:
        if (unk_06C != 0) {
            Wireless_End();
        }
        unk_152 = 21;
        unk_194->ShowMessage(7, 3, 0, 1);
        unk_194->HideAllButtons();
        unk_194->StopConnecting();
        break;
    case 21:
        if (unk_194->CheckContinue()) {
            unk_152 = 23;
        }
        break;
    case 23:
        unk_152 = 25;
        break;
    case 8: {
        if (!ov11_021268E0()) {
            unk_152 = 20;
            break;
        }
        if (--unk_144 == 0) {
            unk_152 = 20;
            break;
        }
        int result = unk_194->UpdateButtonSelect();
        if (result < 0) {
            break;
        }
        if (result != 18) {
            break;
        }
        unk_194->ShowMessage(14, 3, 4, 1);
        unk_194->ShowTopMessage(8, 3, 1);
        unk_194->ShowButtons(11);
        unk_152 = 9;
        unk_144 = 3600;
        break;
    }
    case 9: {
        if (!ov11_021268E0()) {
            unk_152 = 20;
            break;
        }
        if (--unk_144 == 0) {
            unk_152 = 20;
            break;
        }
        int result = unk_194->UpdateButtonSelect();
        if (result < 0) {
            break;
        }
        if (result == 14) {
            unk_194->ShowMessage(20, 3, 2, 0);
            unk_194->AddMessage(21);
            unk_194->ShowTopMessage(9, 3, 3);
            unk_152 = 10;
            unk_194->SetBackButton(3);
            CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
            break;
        }
        Cancel();
        break;
    }
    case 10:
        SetState(17);
        break;
    case 11:
        if (unk_06C != 0) {
            Wireless_End();
        }
        unk_152 = 12;
        break;
    case 12:
    case 25:
        Finish();
        break;
    }
}

void RangerNetExchange::UpdateTransfer()
{
    switch (unk_152) {
    case 0:
        unk_144 = 30;
        unk_152 = 1;
        unk_194->InitSendAnim(0);
        break;
    case 1: {
        if (unk_194->UpdateSendAnim()) {
            break;
        }
        MI_CpuClear16(unk_064, 4);
        int i;
        u32 n = 1111;
        // SJIS "あいうえお"
        const u16 *name = (const u16 *)"\x82\xa0\x82\xa2\x82\xa4\x82\xa6\x82\xa8";
        for (i = 0; name[i] != 0; i++) {
            unk_064->name[i] = name[i];
        }
        for (i = 0; i < 8; i++) {
            unk_064->id[7 - i] = n % 10 + 0xA2;
            n /= 10;
        }
        Wireless_StartSend(unk_064, 4, 1);
        unk_144 = 3600;
        unk_152 = 4;
        unk_194->StartSendFadeOut();
        DownloadMissionRecord_SetTransferred(&MAIN_BSS_020AF5E4[0], 0);
        unk_194->unk_728->StartWriteSteps(0);
        break;
    }
    case 4:
        unk_194->UpdateSendFadeOut();
        if (unk_194->unk_728->UpdateWriteSteps() & 0x80) {
            unk_152 = 20;
            break;
        }
        if (Wireless_IsSendDone()) {
            unk_152 = 13;
            break;
        }
        if (--unk_144 != 0 && ov11_021268E0()) {
            break;
        }
        if (unk_06C != 0) {
            Wireless_End();
        }
        unk_152 = 20;
        break;
    case 13:
        if (unk_194->unk_728->UpdateWriteSteps() & 0x80) {
            unk_152 = 20;
        }
        unk_194->UpdateSendFadeOut();
        unk_152 = 16;
        break;
    case 16: {
        unk_194->UpdateSendFadeOut();
        u8 steps = unk_194->unk_728->UpdateWriteSteps();
        if (steps == 0) {
            break;
        }
        if (steps == 2) {
            Wireless_StartSend(unk_064, 4, 2);
            unk_152 = 17;
            unk_144 = 3600;
            break;
        }
        if (steps & 0x80) {
            unk_152 = 20;
        }
        break;
    }
    case 17:
        unk_194->UpdateSendFadeOut();
        if (Wireless_IsSendDone()) {
            if (unk_06C != 0) {
                Wireless_End();
            }
            unk_152 = 18;
            unk_194->unk_728->FinishWriteSteps();
            break;
        }
        if (--unk_144 != 0) {
            break;
        }
        if (unk_06C != 0) {
            Wireless_End();
        }
        unk_152 = 20;
        break;
    case 18: {
        unk_194->UpdateSendFadeOut();
        u8 steps = unk_194->unk_728->UpdateWriteSteps();
        if (steps == 0) {
            break;
        }
        if (steps & 0x80) {
            unk_152 = 20;
            break;
        }
        CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
        unk_194->ShowMessage(22, 3, 2, 1);
        unk_194->AddMessage(24);
        unk_152 = 10;
        unk_144 = 30;
        unk_152 = 11;
        unk_194->SetLinkIcon(0, -1);
        break;
    }
    case 20:
        unk_144 = 30;
        unk_152 = 21;
        unk_194->ShowMessage(23, 3, 0, 1);
        unk_194->HideAllButtons();
        unk_194->StopConnecting();
        break;
    case 22:
        unk_144 = 30;
        unk_152 = 21;
        unk_194->ShowMessage(23, 3, 0, 1);
        unk_194->HideAllButtons();
        unk_194->StopConnecting();
        break;
    case 21:
        unk_152 = 23;
        break;
    case 23:
        if (unk_194->CheckContinue()) {
            unk_152 = 12;
        }
        break;
    case 11:
        if (unk_194->CheckContinue()) {
            unk_152 = 25;
        }
        break;
    case 12:
        Finish();
        break;
    case 25:
        Finish();
        break;
    }
}

void RangerNetExchange::SetState(int state)
{
    unk_151 = unk_150;
    unk_150 = state;
    unk_152 = 0;
    unk_144 = 0;
    unk_146 = 0;
}

void RangerNetExchange::Finish()
{
    SetState(8);
}

void RangerNetExchange::Cancel()
{
    unk_194->ShowMessage(15, 1, 0, 1);
    unk_194->StopConnecting();
    if (unk_06C != 0) {
        Wireless_End();
    }
    SetState(18);
}

void RangerNetExchange::StartWireless()
{
    u16 name[10] = { 0 };
    // SJIS "かきくけこ"
    u16 *pass = (u16 *)"\x82\xa9\x82\xab\x82\xad\x82\xaf\x82\xb1";
    u32 lo, hi;
    int i;

    SplitNumber(1112, &lo, &hi);
    for (i = 3; i >= 0; i--) {
        name[i] = lo % 10 + 0xA2;
        lo /= 10;
    }
    name[4] = 0xF1;
    for (i = 3; i >= 0; i--) {
        name[5 + i] = hi % 10 + 0xA2;
        hi /= 10;
    }
    WhInitParam param = { { 0x16, 1, 0, 0x15 }, NULL, NULL };
    param.unk_04 = name;
    param.unk_08 = pass;
    Wireless_Init(&param, (u32)unk_05C);
}

static void SplitNumber(u32 value, u32 *lo, u32 *hi)
{
    *lo = value % 10000;
    *hi = (value / 10000) % 10000;
}

int RangerNetExchange::ParseNumber(const u16 *str)
{
    int n = 0;
    while (TRUE) {
        u32 c = *str++;
        if (c < '0') {
            break;
        }
        if (c <= '9') {
            n = n * 10 + (c - '0');
            continue;
        }
        break;
    }
    return n;
}
