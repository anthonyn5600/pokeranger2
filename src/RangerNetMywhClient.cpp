#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "DownloadStationScan.hpp"
#include "RangerNetExchange.hpp"
#include "RangerNetMenu.hpp"
#include "RangerNetMywh.hpp"

// Clients of the mywh connection (0212EBCC..0212F648): RangerNetExchange's download states and
// DownloadStationScan, both driving the mywh connection through a state callback.

// RangerNetSession.cpp
void WirelessDriver_Init();
WVRResult WirelessDriver_Shutdown();

static int sLogoState;
static int sDownloadState;

static void Exchange_MywhCallback(int state);
static void LogoDownload_MywhCallback(int state);

void RangerNetExchange::UpdateLocalScan()
{
    switch (unk_152) {
    case 0:
        sDownloadState = 0;
        unk_152 = 1;
        break;
    case 1:
        unk_194->unk_710 = 1;
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        unk_194->ShowMessage(2, 1, 0, 1);
        if (!Mywh_StartDownload(unk_050, Exchange_MywhCallback, unk_04C)) {
            unk_194->ShowMessage(3, 1, 0, 1);
            AbortDownload();
            break;
        }
        unk_152 = 3;
        unk_144 = 7200;
        break;
    case 3:
        if (!Mywh_IsInitialized()) {
            break;
        }
        unk_194->SetBackButton(5);
        unk_152 = 4;
    case 4:
        unk_194->SetLinkIcon(2, Mywh_GetLinkLevel());
        if (sDownloadState == 2 || sDownloadState == 4) {
            if (Mywh_GetHeader() == NULL) {
                break;
            }
            SetState(3);
            CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
            CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
        } else if (sDownloadState == 5 || --unk_144 == 0) {
            unk_194->ShowMessage(3, 1, 0, 1);
            AbortDownload();
        }
        break;
    case 11:
        unk_152 = 12;
        break;
    case 12:
        unk_152 = 25;
        Mywh_Finalize();
        break;
    case 20:
        if (unk_194->CheckContinue()) {
            SetState(8);
        }
        break;
    case 25:
        break;
    }
}

void RangerNetExchange::UpdateLocalSelect()
{
    const char *name = (const char *)Mywh_GetHeader();

    switch (unk_152) {
    case 0:
        unk_152 = 4;
        break;
    case 3:
        unk_152 = 4;
        break;
    case 4:
        unk_188 = unk_194->FindMissionFile(name);
        for (int i = 0; i < 11; i++) {
            unk_15C[i] = -1;
        }
        if (unk_188 < 0) {
            unk_188 = 10;
        }
        unk_15C[unk_188] = 1;
        unk_194->SetupMissionList(unk_15C, TRUE, 7);
        unk_152 = 5;
        break;
    case 5: {
        int sel = unk_194->UpdateMissionSelect();
        if (sel < 0) {
            break;
        }
        unk_188 = sel - 11;
        unk_194->ShowMessage(4, 1, 1, 1);
        unk_152 = 10;
        break;
    }
    case 10:
        SetState(4);
        break;
    case 20:
        if (unk_194->CheckContinue()) {
            SetState(8);
        }
        break;
    case 25:
        break;
    }
}

void RangerNetExchange::UpdateLocalReceive()
{
    if (unk_048 != 0) {
        unk_048--;
    }
    switch (unk_152) {
    case 0:
        unk_048 = 7200;
        unk_152 = 4;
        unk_154 = 0;
        unk_144 = 15;
        unk_194->StartDownloadAnim();
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        break;
    case 3:
        unk_152 = 4;
        break;
    case 4: {
        unk_194->UpdateDownloadAnim();
        u16 n = Mywh_GetChunksReceived();
        if (n == Mywh_GetChunkCount() && sDownloadState == 3) {
            unk_152 = 11;
            Mywh_Finalize();
            break;
        }
        if (sDownloadState == 5 || unk_048 == 0) {
            unk_194->ShowMessage(16, 1, 0, 1);
            AbortDownload();
            break;
        }
        if (Mywh_GetLinkLevel() <= 1) {
            unk_194->ShowMessage(14, 1, 1, 1);
        }
        break;
    }
    case 11:
        unk_194->UpdateDownloadAnim();
        if (sDownloadState == 4 || sDownloadState == 6) {
            Mywh_Decrypt(unk_050, unk_050);
            SetState(7);
        }
        break;
    case 12:
        break;
    case 20:
        if (unk_194->CheckContinue()) {
            SetState(8);
        }
        break;
    case 25:
        break;
    }
}

void RangerNetExchange::UpdateLocalSave()
{
    switch (unk_152) {
    case 0:
        unk_194->unk_710 = 0;
        unk_194->UpdateDownloadAnim();
        unk_144 = 120;
        unk_152 = 13;
        unk_194->ShowMessage(5, 1, 1, 1);
        unk_194->SetBackButton(3);
        unk_194->SetLinkIcon(0, -1);
        break;
    case 13:
        unk_194->UpdateDownloadAnim();
        if (--unk_144 != 0) {
            break;
        }
        unk_152 = 16;
        unk_194->StartSaveMissions(unk_050);
        unk_194->ShowMessage(6, 1, 1, 1);
        break;
    case 16: {
        int ret = unk_194->UpdateSaveMissions();
        if (ret == 0) {
            break;
        }
        if (ret < 0) {
            unk_194->ShowMessage(13, 1, 0, 1);
            unk_152 = 19;
            break;
        }
        unk_194->ShowDownloadedMessage(unk_188, FALSE);
        unk_152 = 25;
        break;
    }
    case 19:
        break;
    case 25:
        if (unk_194->CheckContinue()) {
            SetState(8);
        }
        break;
    case 20:
        if (unk_194->CheckContinue()) {
            SetState(8);
        }
        break;
    }
}

static void Exchange_MywhCallback(int state)
{
    switch (state) {
    case 0:
        sDownloadState = 1;
        break;
    case 1:
        sDownloadState = 2;
        break;
    case 2:
        sDownloadState = 3;
        break;
    case 3:
        if (sDownloadState == 3) {
            sDownloadState = 4;
        } else {
            sDownloadState = 6;
        }
        break;
    case 4:
        sDownloadState = 5;
        break;
    }
}

void RangerNetExchange::AbortDownload()
{
    Mywh_Finalize();
    unk_152 = 20;
    unk_194->StopConnecting();
    unk_194->unk_710 = 0;
}

DownloadStationScan::DownloadStationScan()
{
    unk_0 = new u8[Mywh_GetWorkSize()];
    unk_4 = new u8[0xF000];
    unk_8 = 0;
    sLogoState = 0;
    CGame::GetInstance()->unk_15DC = 0;
}

DownloadStationScan::~DownloadStationScan()
{
    if (unk_0 != NULL) {
        delete[] unk_0;
        unk_0 = NULL;
    }
    if (unk_4 != NULL) {
        delete[] unk_4;
        unk_4 = NULL;
    }
}

BOOL DownloadStationScan::Update()
{
    switch (unk_8) {
    case 0:
        unk_8 = 1;
        WirelessDriver_Init();
        break;
    case 1:
        if (!Mywh_StartDownload(unk_4, LogoDownload_MywhCallback, unk_0)) {
            unk_8 = 25;
        } else {
            unk_8 = 3;
            unk_A = 30;
        }
        break;
    case 3:
        if (sLogoState != 1) {
            break;
        }
        unk_8 = 4;
    case 4:
        if (sLogoState == 2 || sLogoState == 3) {
            CGame::GetInstance()->unk_15DC = 1;
            unk_8 = 25;
        } else if (sLogoState == 5 || --unk_A == 0) {
            unk_8 = 25;
        }
        break;
    case 25:
        Mywh_Finalize();
        unk_8 = 24;
        break;
    case 24:
        switch (sLogoState) {
        case 4:
        case 5:
        case 6:
            WirelessDriver_Shutdown();
            unk_8 = 26;
            break;
        }
        break;
    case 26:
        return FALSE;
    }
    return TRUE;
}

static void LogoDownload_MywhCallback(int state)
{
    switch (state) {
    case 0:
        sLogoState = 1;
        break;
    case 1:
        sLogoState = 2;
        break;
    case 2:
        sLogoState = 3;
        break;
    case 3:
        if (sLogoState == 3) {
            sLogoState = 4;
        } else {
            sLogoState = 6;
        }
        break;
    case 4:
        sLogoState = 5;
        break;
    }
}
