#include "SaveDialog.hpp"

#include <nitro.h>

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "SaveData.hpp"
#include "SaveManager.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"

struct UnkStruct_0210C1C0;
struct UnkStruct_0210C228;

extern UnkStruct_0210C1C0 MAIN_BSS_0210C1C0;
extern UnkStruct_0210C228 MAIN_BSS_0210C228;

extern "C" {
void sub_0202A4A0(UnkStruct_0210C1C0 *obj);
void sub_0202A4D8(UnkStruct_0210C228 *obj);
}

UnkStruct_0202773C_Step DAT_0208c0ec[] = {
    { 0x56, 6, 1, -2 },
};

UnkStruct_0202773C_Step DAT_0208c0fc[] = {
    { 0x1E, 4, 1, 0x42 },
    { 0x21, 3, 1, -1 },
    { -1, 5, 1, 0 },
};

UnkStruct_0202773C_Step DAT_0208c12c[] = {
    { 0x1D, 2, 1, 0 },
    { 0x7C, 4, 1, 0x42 },
    { 0x1F, 0, 1, -2 },
    { -1, 5, 1, 0 },
};

SaveDialog *MAIN_BSS_0210C1BC;

SaveDialog::SaveDialog(CGame *game)
{
    unk_14 = game;
    Reset();
}

void SaveDialog::Create()
{
    if (MAIN_BSS_0210C1BC != NULL) {
        return;
    }
    MAIN_BSS_0210C1BC = new SaveDialog(CGame::GetInstance());
}

SaveDialog *SaveDialog::GetInstance()
{
    return MAIN_BSS_0210C1BC;
}

SaveDialog::~SaveDialog()
{
    unk_14->m_textboxData->ResetTextSpeed();
    unk_14->m_textboxData->CloseAndClear(1, 1);
    SAFE_DELETE(unk_08);
}

BOOL SaveDialog::Update()
{
    switch (unk_00) {
    case 2:
        if (!unk_14->m_textboxData->IsActive() && !unk_14->m_textboxData->CloseIfNoPrompt(1)) {
            if (unk_14->m_textboxData->GetYesNoResult() == 0) {
                unk_00 = 1;
            } else {
                GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
                unk_00 = 5;
            }
        }
        break;
    case 3:
        if (!unk_14->m_textboxData->IsActive()) {
            unk_00 = 1;
        }
        break;
    case 4: {
        u32 result = unk_08->Update();
        if (result != 0) {
            if (!(result & 0x80)) {
                unk_00 = 1;
            } else {
                SetStep(DAT_0208c0ec, 1, 0);
                unk_14->m_audioEngine->StopBgm(0);
                unk_14->m_audioEngine->StopJingle(0);
            }
            SAFE_DELETE(unk_08);
        }
        break;
    }
    case 1:
        NextStep();
        break;
    case 7:
        unk_00 = 1;
        break;
    }

    return IsActive();
}

void SaveDialog::Reset()
{
    unk_00 = 0;
    unk_04 = -1;
    unk_08 = NULL;
    unk_0C = NULL;
}

void SaveDialog::Start()
{
    unk_14->m_audioEngine->StopStream2(0);
    unk_14->m_audioEngine->StopStream(0);
    unk_00 = 7;
    unk_04 = 0;
    unk_0C = DAT_0208c12c;
    unk_10 = 1;
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    unk_14->m_audioEngine->AddSeGroup(0x45);
}

void SaveDialog::sub_02027A2C()
{
    unk_14->m_audioEngine->StopStream2(0);
    unk_14->m_audioEngine->StopStream(0);
    unk_00 = 7;
    unk_04 = 0;
    unk_0C = DAT_0208c0fc;
    unk_10 = 0;
    unk_14->m_audioEngine->AddSeGroup(0x45);
}

void SaveDialog::SetStep(UnkStruct_0202773C_Step *step, int arg1, int arg3)
{
    unk_00 = step->state;
    if (step->message < 0) {
        unk_14->m_textboxData->ResetTextSpeed();
        unk_14->m_textboxData->CloseAndClear(1, 1);
        return;
    }
    unk_14->m_textboxData->CloseAndClear(1, 1);
    unk_14->m_textboxData->SetTextSpeed(0);
    unk_14->m_textboxData->ShowSystemMessage(step->message, arg1, step->arg, arg3);
}

void SaveDialog::NextStep()
{
    if (unk_04 < 0) {
        return;
    }

    SetStep(&unk_0C[unk_04], 1, 0);
    if (unk_0C[unk_04].state == 4) {
        RTCTime time;
        RTCDate date;
        RTC_GetTime(&time);
        RTC_GetDate(&date);
        MAIN_BSS_020B26A0.CheckElapsedTime(&time, &date);
        unk_14->SaveBgmState();
        SAFE_DELETE(unk_08);
        unk_08 = new SaveManager(1);
        sub_0202A4A0(&MAIN_BSS_0210C1C0);
        sub_0202A4D8(&MAIN_BSS_0210C228);
        unk_08->Save(unk_10);
    }

    if (unk_0C[unk_04].sound != 0) {
        if (unk_0C[unk_04].sound < 0) {
            unk_14->m_audioEngine->StopJingle(0);
            if (unk_0C[unk_04].sound != -2) {
                unk_14->m_audioEngine->ResumeBgm(0);
            }
        } else {
            unk_14->m_audioEngine->PlayJingle(unk_0C[unk_04].sound, 0, 0x100);
            unk_14->m_audioEngine->StopBgm(0);
        }
    }
    unk_04++;
}

BOOL SaveDialog::IsActive()
{
    return unk_00 != 5;
}
