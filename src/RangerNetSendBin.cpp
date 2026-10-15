#include "RangerNetSendBin.hpp"

#include <nitro/math.h>
#include <string.h>

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "CryptoRC4.hpp"
#include "DiskHPTable.hpp"
#include "RangerNetMenu.hpp"
#include "SaveManager.hpp"
#include "file/CBinaryFile.hpp"
#include "heap.hpp"

// per-player info entry (RangerNetPlayerInfo.cpp)
struct D3Info {
    u8 unk_00[0x10];
    u32 unk_10;
    u8 unk_14[0x5];
    u8 unk_19;
    u8 unk_1A[0x6];
};

extern "C" void DownloadMissionRecord_SetTransferred(DownloadMissionRecord *obj, int bit);

// RangerNet*.cpp
void Connect_Start(int arg, u8 arg2);
void Connect_SendData(void *data, u16 size);
void Connect_Free();
D3Info *CommInfo_GetPlayerInfo(u16 aid);
BOOL CommManager_IsInitialized();
void CommServerClient_SetBeaconData(const void *src);
void CommTiming_StartSync(u8 v);
BOOL CommTiming_IsSyncState(u8 v);
BOOL CommSys_Update();
BOOL CommSys_IsPlayerConnected(u16 aid);

// declared in reverse: mwcc's size sort of the two equal-size arrays flips them back to the original order
static char sSendBin2[] = "data/sendbin/sendbin2.bin";
static char sSendBin1[] = "data/sendbin/sendbin1.bin";
static const char *sSendBinPaths[] = { sSendBin1, sSendBin2 };

RangerNetSendBin::RangerNetSendBin(CGame *game, RangerNetMenu *menu)
{
    unk_3BC = PTR_CAST(u32, menu->unk_008);
    unk_3C0 = PTR_CAST(u32, menu->unk_00C);
    unk_3C4 = PTR_CAST(u32, menu->unk_010);
    unk_3C8 = PTR_CAST(u32, menu->unk_014);
    unk_3CC = *(u32 *)menu->unk_018;
    unk_3D0 = PTR_CAST(u32, menu->unk_01C);
    unk_3D8 = menu;
    unk_3DC = &menu->unk_002;
    unk_3E0 = (u16 *)&menu->unk_004[0];
    unk_3E4 = (u16 *)&menu->unk_004[2];
    unk_3B4 = menu;
    unk_3E8 = game;
    Init();
}

RangerNetSendBin::~RangerNetSendBin()
{
    if (unk_0 != NULL) {
        delete unk_0;
        unk_0 = NULL;
    }
}

u8 *RangerNetSendBin::LoadData(const char *path)
{
    MI_CpuFill8(unk_004, 0, sizeof(unk_004));
    CBinaryFile *file = new CBinaryFile(path, 1, 0, CGame::GetInstance()->unk_14A8, NULL, 0);
    memcpy(unk_004, file->unk_4C, sizeof(unk_004));
    u8 key[16] = { 0xF9, 0x7D, 0x80, 0xC3, 0x79, 0x4B, 0x2E, 0xA0, 0x95, 0x18, 0x73, 0x85, 0x99, 0x6A, 0x1C, 0x32 };
    CRYPTORC4FastContext ctx;
    CRYPTO_RC4FastInit(&ctx, key, sizeof(key));
    CRYPTO_RC4FastEncrypt(&ctx, unk_004, sizeof(unk_004), unk_004);
    if (file != NULL) {
        delete file;
    }
    return unk_004;
}

void RangerNetSendBin::Init()
{
    unk_0 = (UnkClass_0212CE58Work *)Heap_Alloc(sizeof(UnkClass_0212CE58Work));
    memset(unk_0, 0, sizeof(UnkClass_0212CE58Work));
    unk_0->unk_1AC0 = 1;
    unk_0->unk_1AC4 = 1;
}

void RangerNetSendBin::Start(int v)
{
    unk_0->unk_1AC4 = 4;
    unk_3AC = v;
}

BOOL RangerNetSendBin::Update()
{
    UnkClass_0212CE58Work *work = unk_0;
    if (work == NULL) {
        return FALSE;
    }
    if (unk_3B4->CheckCancel() < 0) {
        unk_0->unk_1AC4 = 19;
    }
    CommSys_Update();
    switch (unk_0->unk_1AC4) {
    default:
    case 1:
    case 2:
    case 3:
    case 21:
        break;
    case 0:
        unk_0->unk_1AC4 = 1;
        break;
    case 4:
        StartComm(work, unk_3AC);
        unk_0->unk_1AC4 = 5;
        unk_3B0 = 18000;
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        break;
    case 5:
        unk_3B4->UpdateWaitIcon(1);
        if (CommSys_IsPlayerConnected(0)) {
            CommServerClient_SetBeaconData(unk_004);
            if (GetPartnerCount(work) > 0) {
                unk_3B8 = CommInfo_GetPlayerInfo(1);
                unk_0->unk_1AC4 = 7;
                unk_3B4->ShowMessage(13, 4, 5, 1);
                unk_3B4->SetNameArg(0, PTR_CAST(int, unk_3B8));
                unk_3B4->SetNumberArg(0, (u16)unk_3B8->unk_10);
                unk_3B4->ShowButtons(16);
                unk_3B4->UpdateWaitIcon(0);
                CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
                CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
                unk_3B0 = 7200;
                break;
            }
        }
        if (--unk_3B0 <= 0) {
            unk_0->unk_1AC4 = 15;
        }
        break;
    case 7:
        unk_3B0--;
        if (CommSys_IsPlayerConnected(0)) {
            CommServerClient_SetBeaconData(unk_004);
            if (GetPartnerCount(work) > 0) {
                int result = unk_3B4->UpdateButtonSelect();
                if (result < 0) {
                    if (unk_3B0 <= 0) {
                        unk_0->unk_1AC4 = 19;
                    }
                } else if (result == 18) {
                    unk_3B8 = CommInfo_GetPlayerInfo(1);
                    unk_0->unk_1AC4 = 7;
                    unk_3B4->ShowMessage(14, 4, 5, 1);
                    unk_3B4->SetNameArg(0, PTR_CAST(int, unk_3B8));
                    unk_3B4->SetNumberArg(0, (u16)unk_3B8->unk_10);
                    unk_3B4->ShowTopMessage(8, 4, 1);
                    unk_3B4->ShowButtons(11);
                    unk_0->unk_1AC4 = 6;
                } else {
                    unk_0->unk_1AC4 = 19;
                }
                break;
            }
        }
        unk_0->unk_1AC4 = 16;
        break;
    case 6:
        if (CommSys_IsPlayerConnected(0)) {
            CommServerClient_SetBeaconData(unk_004);
            if (GetPartnerCount(work) > 0) {
                int result = unk_3B4->UpdateButtonSelect();
                if (result >= 0) {
                    if (result == 14) {
                        CommTiming_StartSync(0xAB);
                        work->unk_1ABC = 1;
                        unk_0->unk_1AC4 = 9;
                        unk_3B4->ShowMessage(19, 4, 2, 0);
                        unk_3B4->AddMessage(20);
                        unk_3B4->ShowTopMessage(9, 4, 4);
                        unk_3B4->SetBackButton(3);
                        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
                        switch (unk_3AC) {
                        case 0:
                            DownloadMissionRecord_SetTransferred(&MAIN_BSS_020AF5E4[1], 1);
                            unk_3B4->InitSendAnim(2);
                            break;
                        case 1:
                            DownloadMissionRecord_SetTransferred(&MAIN_BSS_020AF5E4[2], 2);
                            unk_3B4->InitSendAnim(1);
                            break;
                        default:
                            unk_0->unk_1AC4 = 16;
                            return TRUE;
                        }
                        unk_3B4->unk_728->StartWriteSteps(0);
                    } else {
                        unk_0->unk_1AC4 = 19;
                    }
                }
                break;
            }
        }
        unk_0->unk_1AC4 = 16;
        break;
    case 10:
        if (!CommManager_IsInitialized()) {
            return FALSE;
        }
        break;
    case 8:
        if (CommTiming_IsSyncState(0xAB) == TRUE) {
            unk_0->unk_1AC4 = 9;
        }
        break;
    case 9:
        if (unk_3B4->unk_728->UpdateWriteSteps() & 0x80) {
            unk_0->unk_1AC4 = 18;
        }
        if (CommSys_IsPlayerConnected(0) && !unk_3B4->UpdateSendAnim()) {
            Encrypt(unk_004, work->unk_1AC8);
            Connect_SendData(work->unk_1AC8, 0x358);
            unk_0->unk_1AC4 = 11;
            unk_3B4->StartSendFadeOut();
            unk_3B0 = 18000;
        }
        break;
    case 11:
        unk_3B4->UpdateSendFadeOut();
        if (CommSys_IsPlayerConnected(0)) {
            u8 steps = unk_3B4->unk_728->UpdateWriteSteps();
            if (steps == 2) {
                CommTiming_StartSync(0x93);
                unk_0->unk_1AC4 = 12;
            } else if (steps & 0x80) {
                unk_0->unk_1AC4 = 18;
            }
        }
        break;
    case 12:
        unk_3B4->UpdateSendFadeOut();
        if (GetPartnerCount(work) == 0) {
            unk_0->unk_1AC4 = 17;
        } else if (CommTiming_IsSyncState(0x93) == TRUE) {
            unk_0->unk_1AC4 = 13;
            unk_3B4->unk_728->FinishWriteSteps();
        }
        break;
    case 13: {
        unk_3B4->UpdateSendFadeOut();
        u8 steps = unk_3B4->unk_728->UpdateWriteSteps();
        if (steps != 0) {
            if (steps & 0x80) {
                unk_0->unk_1AC4 = 18;
            } else {
                unk_3B4->ShowMessage(21, 4, 2, 1);
                unk_3B4->AddMessage(23);
                unk_0->unk_1AC4 = 14;
                CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
                CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
                unk_3B4->SetLinkIcon(0, -1);
                Connect_Free();
            }
        }
        break;
    }
    case 14:
        if (unk_3B4->CheckContinue()) {
            return FALSE;
        }
        break;
    case 15:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ShowMessage(5, 4, 0, 1);
        unk_3B4->StopConnecting();
        Connect_Free();
        break;
    case 16:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ShowMessage(7, 4, 0, 1);
        unk_3B4->StopConnecting();
        Connect_Free();
        break;
    case 17:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ShowMessage(22, 4, 0, 1);
        unk_3B4->StopConnecting();
        Connect_Free();
        break;
    case 18:
        unk_0->unk_1AC4 = 21;
        unk_3B4->ShowMessage(5, 5, 0, 1);
        unk_3B4->StopConnecting();
        Connect_Free();
        break;
    case 19:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ShowMessage(15, 1, 0, 1);
        unk_3B4->StopConnecting();
        Connect_Free();
        break;
    case 20:
        if (unk_3B4->CheckContinue()) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL RangerNetSendBin::StartComm(UnkClass_0212CE58Work *work, int index)
{
    LoadData(sSendBinPaths[index]);
    Connect_Start(PTR_CAST(int, work->unk_0004), 0xF);
    return FALSE;
}

int RangerNetSendBin::GetPartnerCount(UnkClass_0212CE58Work *work)
{
    int count = 0;
    if (CommInfo_GetPlayerInfo(1) != NULL) {
        count++;
    }
    return count;
}

void RangerNetSendBin::Encrypt(u8 *data, u8 *out)
{
    u16 *table = (u16 *)Heap_Alloc(0x200);
    MATHi_CRC16InitTableRev((MATHCRC16Table *)table, 0xA001);
    u16 crc = MATH_CalcCRC16((MATHCRC16Table *)table, data, 0x50);
    if (table != NULL) {
        Heap_Free(table);
    }
    u16 key[4];
    OS_GetMacAddress((u8 *)key);
    key[3] = key[1];
    key[1] = crc;
    u16 v = 0xD679;
    for (int i = 0; i < 4; i++) {
        key[i] = v ^ key[i];
        v = key[i];
    }
    CRYPTORC4Context *ctx = (CRYPTORC4Context *)Heap_Alloc(sizeof(CRYPTORC4Context));
    CRYPTO_RC4Init(ctx, key, sizeof(key));
    CRYPTO_RC4Encrypt(ctx, data + 0x50, 0x358, out);
    if (ctx != NULL) {
        Heap_Free(ctx);
    }
}
