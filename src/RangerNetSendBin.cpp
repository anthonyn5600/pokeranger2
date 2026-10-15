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
void ov11_021285E0(int arg, u8 arg2);
void ov11_0212861C(void *data, u16 size);
void ov11_0212868C();
D3Info *ov11_02128A30(u16 aid);
BOOL ov11_02128B80();
void ov11_021298A0(const void *src);
void ov11_02129A54(u8 v);
BOOL ov11_02129AC0(u8 v);
BOOL ov11_0212A83C();
BOOL ov11_0212BEA0(u16 aid);

// declared in reverse: mwcc's size sort of the two equal-size arrays flips them back to the original order
static char sSendBin2[] = "data/sendbin/sendbin2.bin";
static char sSendBin1[] = "data/sendbin/sendbin1.bin";
static const char *sSendBinPaths[] = { sSendBin1, sSendBin2 };

RangerNetSendBin::RangerNetSendBin(CGame *game, RangerNetMenu *menu)
{
    unk_3BC = (u32)menu->unk_008;
    unk_3C0 = (u32)menu->unk_00C;
    unk_3C4 = (u32)menu->unk_010;
    unk_3C8 = (u32)menu->unk_014;
    unk_3CC = *(u32 *)menu->unk_018;
    unk_3D0 = (u32)menu->unk_01C;
    unk_3D8 = menu;
    unk_3DC = &menu->unk_002;
    unk_3E0 = (u16 *)&menu->unk_004[0];
    unk_3E4 = (u16 *)&menu->unk_004[2];
    unk_3B4 = menu;
    unk_3E8 = game;
    ov11_0212CFD4();
}

RangerNetSendBin::~RangerNetSendBin()
{
    if (unk_0 != NULL) {
        delete unk_0;
        unk_0 = NULL;
    }
}

u8 *RangerNetSendBin::ov11_0212CEE8(const char *path)
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

void RangerNetSendBin::ov11_0212CFD4()
{
    unk_0 = (UnkClass_0212CE58Work *)Heap_Alloc(sizeof(UnkClass_0212CE58Work));
    memset(unk_0, 0, sizeof(UnkClass_0212CE58Work));
    unk_0->unk_1AC0 = 1;
    unk_0->unk_1AC4 = 1;
}

void RangerNetSendBin::ov11_0212D018(int v)
{
    unk_0->unk_1AC4 = 4;
    unk_3AC = v;
}

BOOL RangerNetSendBin::ov11_0212D030()
{
    UnkClass_0212CE58Work *work = unk_0;
    if (work == NULL) {
        return FALSE;
    }
    if (unk_3B4->ov11_0212247C() < 0) {
        unk_0->unk_1AC4 = 19;
    }
    ov11_0212A83C();
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
        ov11_0212D854(work, unk_3AC);
        unk_0->unk_1AC4 = 5;
        unk_3B0 = 18000;
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        break;
    case 5:
        unk_3B4->ov11_02124438(1);
        if (ov11_0212BEA0(0)) {
            ov11_021298A0(unk_004);
            if (ov11_0212D880(work) > 0) {
                unk_3B8 = ov11_02128A30(1);
                unk_0->unk_1AC4 = 7;
                unk_3B4->ov11_02122B7C(13, 4, 5, 1);
                unk_3B4->ov11_02122BF8(0, (int)unk_3B8);
                unk_3B4->ov11_02122C08(0, (u16)unk_3B8->unk_10);
                unk_3B4->ov11_021217C0(16);
                unk_3B4->ov11_02124438(0);
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
        if (ov11_0212BEA0(0)) {
            ov11_021298A0(unk_004);
            if (ov11_0212D880(work) > 0) {
                int result = unk_3B4->ov11_02121168();
                if (result < 0) {
                    if (unk_3B0 <= 0) {
                        unk_0->unk_1AC4 = 19;
                    }
                } else if (result == 18) {
                    unk_3B8 = ov11_02128A30(1);
                    unk_0->unk_1AC4 = 7;
                    unk_3B4->ov11_02122B7C(14, 4, 5, 1);
                    unk_3B4->ov11_02122BF8(0, (int)unk_3B8);
                    unk_3B4->ov11_02122C08(0, (u16)unk_3B8->unk_10);
                    unk_3B4->ov11_02122C18(8, 4, 1);
                    unk_3B4->ov11_021217C0(11);
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
        if (ov11_0212BEA0(0)) {
            ov11_021298A0(unk_004);
            if (ov11_0212D880(work) > 0) {
                int result = unk_3B4->ov11_02121168();
                if (result >= 0) {
                    if (result == 14) {
                        ov11_02129A54(0xAB);
                        work->unk_1ABC = 1;
                        unk_0->unk_1AC4 = 9;
                        unk_3B4->ov11_02122B7C(19, 4, 2, 0);
                        unk_3B4->ov11_02122BD4(20);
                        unk_3B4->ov11_02122C18(9, 4, 4);
                        unk_3B4->ov11_0211FBE4(3);
                        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
                        switch (unk_3AC) {
                        case 0:
                            DownloadMissionRecord_SetTransferred(&MAIN_BSS_020AF5E4[1], 1);
                            unk_3B4->ov11_0211F008(2);
                            break;
                        case 1:
                            DownloadMissionRecord_SetTransferred(&MAIN_BSS_020AF5E4[2], 2);
                            unk_3B4->ov11_0211F008(1);
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
        if (!ov11_02128B80()) {
            return FALSE;
        }
        break;
    case 8:
        if (ov11_02129AC0(0xAB) == TRUE) {
            unk_0->unk_1AC4 = 9;
        }
        break;
    case 9:
        if (unk_3B4->unk_728->UpdateWriteSteps() & 0x80) {
            unk_0->unk_1AC4 = 18;
        }
        if (ov11_0212BEA0(0) && !unk_3B4->ov11_0211F0FC()) {
            ov11_0212D8A0(unk_004, work->unk_1AC8);
            ov11_0212861C(work->unk_1AC8, 0x358);
            unk_0->unk_1AC4 = 11;
            unk_3B4->ov11_0211F32C();
            unk_3B0 = 18000;
        }
        break;
    case 11:
        unk_3B4->ov11_0211F338();
        if (ov11_0212BEA0(0)) {
            u8 steps = unk_3B4->unk_728->UpdateWriteSteps();
            if (steps == 2) {
                ov11_02129A54(0x93);
                unk_0->unk_1AC4 = 12;
            } else if (steps & 0x80) {
                unk_0->unk_1AC4 = 18;
            }
        }
        break;
    case 12:
        unk_3B4->ov11_0211F338();
        if (ov11_0212D880(work) == 0) {
            unk_0->unk_1AC4 = 17;
        } else if (ov11_02129AC0(0x93) == TRUE) {
            unk_0->unk_1AC4 = 13;
            unk_3B4->unk_728->FinishWriteSteps();
        }
        break;
    case 13: {
        unk_3B4->ov11_0211F338();
        u8 steps = unk_3B4->unk_728->UpdateWriteSteps();
        if (steps != 0) {
            if (steps & 0x80) {
                unk_0->unk_1AC4 = 18;
            } else {
                unk_3B4->ov11_02122B7C(21, 4, 2, 1);
                unk_3B4->ov11_02122BD4(23);
                unk_0->unk_1AC4 = 14;
                CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
                CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
                unk_3B4->ov11_0211FB08(0, -1);
                ov11_0212868C();
            }
        }
        break;
    }
    case 14:
        if (unk_3B4->ov11_02122428()) {
            return FALSE;
        }
        break;
    case 15:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ov11_02122B7C(5, 4, 0, 1);
        unk_3B4->ov11_02124520();
        ov11_0212868C();
        break;
    case 16:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ov11_02122B7C(7, 4, 0, 1);
        unk_3B4->ov11_02124520();
        ov11_0212868C();
        break;
    case 17:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ov11_02122B7C(22, 4, 0, 1);
        unk_3B4->ov11_02124520();
        ov11_0212868C();
        break;
    case 18:
        unk_0->unk_1AC4 = 21;
        unk_3B4->ov11_02122B7C(5, 5, 0, 1);
        unk_3B4->ov11_02124520();
        ov11_0212868C();
        break;
    case 19:
        unk_0->unk_1AC4 = 20;
        unk_3B4->ov11_02122B7C(15, 1, 0, 1);
        unk_3B4->ov11_02124520();
        ov11_0212868C();
        break;
    case 20:
        if (unk_3B4->ov11_02122428()) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

BOOL RangerNetSendBin::ov11_0212D854(UnkClass_0212CE58Work *work, int index)
{
    ov11_0212CEE8(sSendBinPaths[index]);
    ov11_021285E0((int)work->unk_0004, 0xF);
    return FALSE;
}

int RangerNetSendBin::ov11_0212D880(UnkClass_0212CE58Work *work)
{
    int count = 0;
    if (ov11_02128A30(1) != NULL) {
        count++;
    }
    return count;
}

void RangerNetSendBin::ov11_0212D8A0(u8 *data, u8 *out)
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
