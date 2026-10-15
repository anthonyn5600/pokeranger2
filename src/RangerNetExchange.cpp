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
int ov11_02125FEC();
void ov11_0212600C(WhInitParam *param, u32 buf);
void ov11_0212641C();
void ov11_02126480();
void ov11_02126620(u32 macLo);
BOOL ov11_02126668();
BOOL ov11_0212669C();
u32 ov11_02126710(int n);
void ov11_02126720(void *data, int size, int id);
void ov11_02126770();
void ov11_021267C4(void *data);
BOOL ov11_02126810();
BOOL ov11_02126850();
BOOL ov11_02126890();
BOOL ov11_021268E0();
void ov11_021268F8();
int ov11_02126954();
void ov11_02126FE4(u32 value, u32 *lo, u32 *hi);

static void ov11_0212EB5C(u32 value, u32 *lo, u32 *hi);

void RangerNetExchange::ov11_0212D978()
{
}

RangerNetExchange::RangerNetExchange(RangerNetMenu *menu)
{
    ov11_0212D978();
    unk_194 = menu;
    unk_05C = (u8 *)operator new[](ov11_02125FEC());
    unk_060 = new UnkClass_0212CE58_000;
    unk_064 = new UnkClass_0212CE58_000;
    unk_04C = new u8[ov11_021301D4()];
    unk_050 = new u8[0xF000];
    unk_150 = 0;
    ov11_0212E9B4(0);
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

int RangerNetExchange::ov11_0212DA48()
{
    if (unk_194->ov11_0212247C() < 0) {
        unk_194->ov11_02122B7C(15, 1, 0, 1);
        unk_194->ov11_02124520();
        switch (unk_150) {
        case 2:
        case 3:
        case 4:
            ov11_0212FD74();
            ov11_0212E9B4(20);
            break;
        default:
            if (unk_06C != 0) {
                ov11_021268F8();
            }
            ov11_0212E9B4(18);
            break;
        }
        return unk_150;
    }
    if (unk_06C != 0) {
        ov11_0212641C();
        if (ov11_02126954()) {
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
        ov11_0212DC84();
        unk_194->ov11_0211FB08(2, -1);
        break;
    case 16:
        ov11_0212E128();
        unk_194->ov11_0211FB08(2, -1);
        break;
    case 17:
        ov11_0212E518();
        unk_194->ov11_0211FB08(2, -1);
        break;
    case 18:
        unk_194->ov11_0211FB08(2, -1);
        if (ov11_02126954() && unk_194->ov11_02122428()) {
            return 10;
        }
        break;
    case 2:
        ov11_0212EBCC();
        break;
    case 3:
        unk_194->ov11_0211FB08(2, ov11_021301BC());
        ov11_0212EE24();
        break;
    case 4:
        unk_194->ov11_0211FB08(2, ov11_021301BC());
        ov11_0212EF94();
        break;
    case 7:
        ov11_0212F158();
        break;
    case 19:
        unk_194->ov11_0211FB08(2, -1);
        break;
    case 20:
        unk_194->ov11_0211FB08(2, -1);
        if (unk_194->ov11_02122428()) {
            return 10;
        }
        break;
    }
    return unk_150;
}

void RangerNetExchange::ov11_0212DC84()
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
        ov11_0212EA38();
        ov11_02126480();
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        unk_06C = 1;
        break;
    case 7:
        switch (unk_153) {
        case 1:
            unk_194->ov11_02124438(1);
            if (ov11_02126668()) {
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
                ov11_021268F8();
            }
            break;
        case 4:
            unk_194->ov11_02124438(1);
            if (--unk_144 == 0 || !ov11_02126890()) {
                unk_153 = 7;
                unk_144 = 60;
                unk_194->ov11_02124438(0);
                if (unk_06C != 0) {
                    ov11_021268F8();
                }
                break;
            }
            if (!ov11_0212669C()) {
                break;
            }
            unk_144 = 30;
            unk_153 = 5;
            unk_194->ov11_02124438(0);
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
                ov11_02126620(ov11_02126710(0));
                unk_152 = 8;
                unk_194->ov11_02122B7C(6, 3, 0, 1);
                CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
                CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
                break;
            }
            unk_153 = 7;
            unk_144 = 60;
            if (unk_06C != 0) {
                ov11_021268F8();
            }
            break;
        case 6:
            if (unk_144 != 0) {
                unk_144--;
                break;
            }
            unk_194->ov11_02122B7C(5, 3, 0, 1);
            unk_194->ov11_0211F96C();
            unk_152 = 11;
            unk_194->ov11_02124520();
            break;
        case 7:
            if (unk_144 != 0) {
                unk_144--;
                break;
            }
            unk_194->ov11_02122B7C(7, 3, 0, 1);
            unk_194->ov11_0211F96C();
            unk_194->ov11_02124438(0);
            unk_194->ov11_02124520();
            unk_152 = 11;
            break;
        }
        break;
    case 8:
        if (!unk_194->ov11_02122428()) {
            break;
        }
        MI_CpuClear16(unk_060, 4);
        ov11_021267C4(unk_060);
        unk_152 = 10;
        break;
    case 10:
        ov11_0212E9B4(16);
        break;
    case 11:
        if (unk_194->ov11_02122428()) {
            unk_152 = 12;
        }
        break;
    case 12:
        ov11_0212E9D8();
        break;
    }
}

void RangerNetExchange::ov11_0212E128()
{
    u32 lo, hi;

    switch (unk_152) {
    case 0:
        if (ov11_021268E0()) {
            if (!ov11_02126850()) {
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
        ov11_02126FE4(ov11_02126710(0), &lo, &hi);
        unk_194->ov11_02122B7C(13, 3, 4, 1);
        unk_194->ov11_02122C08(0, ov11_0212EBA4(unk_060->id));
        unk_194->ov11_02122C08(1, lo);
        unk_194->ov11_02122C08(2, hi);
        unk_194->ov11_021217C0(16);
        unk_144 = 3600;
        break;
    case 20:
        if (unk_06C != 0) {
            ov11_021268F8();
        }
        unk_152 = 21;
        unk_194->ov11_02122B7C(7, 3, 0, 1);
        unk_194->ov11_0211F96C();
        unk_194->ov11_02124520();
        break;
    case 21:
        if (unk_194->ov11_02122428()) {
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
        int result = unk_194->ov11_02121168();
        if (result < 0) {
            break;
        }
        if (result != 18) {
            break;
        }
        unk_194->ov11_02122B7C(14, 3, 4, 1);
        unk_194->ov11_02122C18(8, 3, 1);
        unk_194->ov11_021217C0(11);
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
        int result = unk_194->ov11_02121168();
        if (result < 0) {
            break;
        }
        if (result == 14) {
            unk_194->ov11_02122B7C(20, 3, 2, 0);
            unk_194->ov11_02122BD4(21);
            unk_194->ov11_02122C18(9, 3, 3);
            unk_152 = 10;
            unk_194->ov11_0211FBE4(3);
            CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
            break;
        }
        ov11_0212E9E8();
        break;
    }
    case 10:
        ov11_0212E9B4(17);
        break;
    case 11:
        if (unk_06C != 0) {
            ov11_021268F8();
        }
        unk_152 = 12;
        break;
    case 12:
    case 25:
        ov11_0212E9D8();
        break;
    }
}

void RangerNetExchange::ov11_0212E518()
{
    switch (unk_152) {
    case 0:
        unk_144 = 30;
        unk_152 = 1;
        unk_194->ov11_0211F008(0);
        break;
    case 1: {
        if (unk_194->ov11_0211F0FC()) {
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
        ov11_02126720(unk_064, 4, 1);
        unk_144 = 3600;
        unk_152 = 4;
        unk_194->ov11_0211F32C();
        DownloadMissionRecord_SetTransferred(&MAIN_BSS_020AF5E4[0], 0);
        unk_194->unk_728->StartWriteSteps(0);
        break;
    }
    case 4:
        unk_194->ov11_0211F338();
        if (unk_194->unk_728->UpdateWriteSteps() & 0x80) {
            unk_152 = 20;
            break;
        }
        if (ov11_02126810()) {
            unk_152 = 13;
            break;
        }
        if (--unk_144 != 0 && ov11_021268E0()) {
            break;
        }
        if (unk_06C != 0) {
            ov11_021268F8();
        }
        unk_152 = 20;
        break;
    case 13:
        if (unk_194->unk_728->UpdateWriteSteps() & 0x80) {
            unk_152 = 20;
        }
        unk_194->ov11_0211F338();
        unk_152 = 16;
        break;
    case 16: {
        unk_194->ov11_0211F338();
        u8 steps = unk_194->unk_728->UpdateWriteSteps();
        if (steps == 0) {
            break;
        }
        if (steps == 2) {
            ov11_02126720(unk_064, 4, 2);
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
        unk_194->ov11_0211F338();
        if (ov11_02126810()) {
            if (unk_06C != 0) {
                ov11_021268F8();
            }
            unk_152 = 18;
            unk_194->unk_728->FinishWriteSteps();
            break;
        }
        if (--unk_144 != 0) {
            break;
        }
        if (unk_06C != 0) {
            ov11_021268F8();
        }
        unk_152 = 20;
        break;
    case 18: {
        unk_194->ov11_0211F338();
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
        unk_194->ov11_02122B7C(22, 3, 2, 1);
        unk_194->ov11_02122BD4(24);
        unk_152 = 10;
        unk_144 = 30;
        unk_152 = 11;
        unk_194->ov11_0211FB08(0, -1);
        break;
    }
    case 20:
        unk_144 = 30;
        unk_152 = 21;
        unk_194->ov11_02122B7C(23, 3, 0, 1);
        unk_194->ov11_0211F96C();
        unk_194->ov11_02124520();
        break;
    case 22:
        unk_144 = 30;
        unk_152 = 21;
        unk_194->ov11_02122B7C(23, 3, 0, 1);
        unk_194->ov11_0211F96C();
        unk_194->ov11_02124520();
        break;
    case 21:
        unk_152 = 23;
        break;
    case 23:
        if (unk_194->ov11_02122428()) {
            unk_152 = 12;
        }
        break;
    case 11:
        if (unk_194->ov11_02122428()) {
            unk_152 = 25;
        }
        break;
    case 12:
        ov11_0212E9D8();
        break;
    case 25:
        ov11_0212E9D8();
        break;
    }
}

void RangerNetExchange::ov11_0212E9B4(int state)
{
    unk_151 = unk_150;
    unk_150 = state;
    unk_152 = 0;
    unk_144 = 0;
    unk_146 = 0;
}

void RangerNetExchange::ov11_0212E9D8()
{
    ov11_0212E9B4(8);
}

void RangerNetExchange::ov11_0212E9E8()
{
    unk_194->ov11_02122B7C(15, 1, 0, 1);
    unk_194->ov11_02124520();
    if (unk_06C != 0) {
        ov11_021268F8();
    }
    ov11_0212E9B4(18);
}

void RangerNetExchange::ov11_0212EA38()
{
    u16 name[10] = { 0 };
    // SJIS "かきくけこ"
    u16 *pass = (u16 *)"\x82\xa9\x82\xab\x82\xad\x82\xaf\x82\xb1";
    u32 lo, hi;
    int i;

    ov11_0212EB5C(1112, &lo, &hi);
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
    ov11_0212600C(&param, (u32)unk_05C);
}

static void ov11_0212EB5C(u32 value, u32 *lo, u32 *hi)
{
    *lo = value % 10000;
    *hi = (value / 10000) % 10000;
}

int RangerNetExchange::ov11_0212EBA4(const u16 *str)
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
