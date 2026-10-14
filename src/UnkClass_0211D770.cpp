#include "UnkClass_0211D770.hpp"

#include "CActor.hpp"
#include "UnkClass_0200C38C.hpp"
#include "UnkClass_0201164C.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_020B26A0.hpp"

struct UnkStruct_0211E47C {
    u16 actorId;
    u16 placeId;
};

static UnkStruct_0211E47C sMissionActors[26] = {
    { 0x12, 0x04 },
    { 0x12, 0x06 },
    { 0x12, 0x09 },
    { 0x12, 0x0A },
    { 0x12, 0x0B },
    { 0x12, 0x10 },
    { 0x13, 0x01 },
    { 0x13, 0x12 },
    { 0x1D, 0x17 },
    { 0x1A, 0x1A },
    { 0x1A, 0x12 },
    { 0x00, 0x1D },
    { 0x1E, 0x1E },
    { 0x00, 0x24 },
    { 0x00, 0x11 },
    { 0x1A, 0x26 },
    { 0x1A, 0x26 },
    { 0x12, 0x08 },
    { 0x1A, 0x26 },
    { 0x12, 0x08 },
    { 0x12, 0x04 },
    { 0x12, 0x1E },
    { 0x1D, 0x27 },
    { 0x1A, 0x1C },
    { 0x1A, 0x24 },
    { 0x1A, 0x0A },
};

static UnkStruct_0211E47C sQuestActors[61] = {
    { 0x39, 0x04 },
    { 0x2B, 0x04 },
    { 0x2E, 0x04 },
    { 0x58, 0x09 },
    { 0x54, 0x0A },
    { 0x2B, 0x0A },
    { 0x2B, 0x09 },
    { 0x2D, 0x0A },
    { 0x24, 0x0E },
    { 0x2C, 0x01 },
    { 0x3B, 0x04 },
    { 0x28, 0x0F },
    { 0x57, 0x12 },
    { 0x30, 0x12 },
    { 0x2A, 0x0A },
    { 0x58, 0x0F },
    { 0x2C, 0x0A },
    { 0x24, 0x19 },
    { 0x66, 0x19 },
    { 0x5A, 0x0A },
    { 0x31, 0x12 },
    { 0x35, 0x1A },
    { 0x31, 0x0A },
    { 0x31, 0x0A },
    { 0x24, 0x21 },
    { 0x30, 0x21 },
    { 0x34, 0x21 },
    { 0x37, 0x04 },
    { 0x1C, 0x11 },
    { 0x20, 0x11 },
    { 0x24, 0x11 },
    { 0x86, 0x1A },
    { 0x02, 0x08 },
    { 0x28, 0x0E },
    { 0x56, 0x09 },
    { 0x27, 0x0F },
    { 0x30, 0x15 },
    { 0x86, 0x1A },
    { 0x30, 0x13 },
    { 0x30, 0x16 },
    { 0x04, 0x01 },
    { 0x03, 0x08 },
    { 0x30, 0x23 },
    { 0x2D, 0x11 },
    { 0x36, 0x1A },
    { 0x25, 0x08 },
    { 0x52, 0x21 },
    { 0x2E, 0x12 },
    { 0x26, 0x08 },
    { 0x54, 0x04 },
    { 0x64, 0x0E },
    { 0x01, 0x08 },
    { 0x2E, 0x21 },
    { 0x2C, 0x08 },
    { 0x05, 0x01 },
    { 0x57, 0x12 },
    { 0x38, 0x04 },
    { 0x66, 0x19 },
    { 0x1F, 0x11 },
    { 0x3A, 0x0A },
    { 0x3E, 0x16 },
};

UnkClass_0211D770::UnkClass_0211D770(CGame *game)
{
    unk_21C = game;
    ov8_0211D7E0();
}

UnkClass_0211D770::~UnkClass_0211D770()
{
    ov8_0211D8EC();
}

void UnkClass_0211D770::ov8_0211D7E0()
{
    unk_00 = 0;
    unk_18 = NULL;
    unk_10 = NULL;
    unk_3C = NULL;
    unk_40 = NULL;
    unk_04 = 0;
    unk_210 = 1;
    unk_214 = 0;
    unk_218 = 0;
    unk_4A = 0;
    unk_4C = 0;
}

void UnkClass_0211D770::ov8_0211D818()
{
    G2_SetBG1Offset(0, -((int)unk_21C->unk_15D0 >> FX32_SHIFT));
    if (unk_18 == NULL) {
        return;
    }
    unk_18->sub_0200F64C();
    if (unk_210) {
        if (unk_214) {
            unk_50[0].sub_0203C87C(NULL);
        }
    } else if (unk_218) {
        unk_50[1].sub_0203C87C(NULL);
    }
}

void UnkClass_0211D770::ov8_0211D8A0()
{
    ov8_0211D9E8();
}

void UnkClass_0211D770::ov8_0211D8AC()
{
    ov8_0211E170();
}

void UnkClass_0211D770::ov8_0211D8B8()
{
    if (unk_18 != NULL) {
        ov8_0211E0A4(TRUE, 0);
        unk_21C->unk_1494->sub_0200C588();
    }
}

void UnkClass_0211D770::ov8_0211D8EC()
{
    SAFE_DELETE(unk_08);
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_3C);
    SAFE_DELETE(unk_40);
    SAFE_DELETE(unk_10);
}

static inline void DrawActor(CFieldActor *actor, Camera2D *camera)
{
    if (actor->unk_08 != NULL) {
        actor->unk_08->sub_020091D4(camera, 0);
    }
}

void UnkClass_0211D770::ov8_0211D9E8()
{
    if (unk_18 == NULL) {
        return;
    }
    unk_18->sub_0200F71C();
    if (unk_08 == NULL) {
        return;
    }
    unk_08->SetOffset(0x41000, -0x17000);
    unk_08->sub_020037B4();
    unk_08->sub_0200381C();
    G3_StoreMtx(0);
    if (unk_210) {
        if (unk_214) {
            DrawActor(&unk_50[0], unk_08);
        }
    } else if (unk_218) {
        DrawActor(&unk_50[1], unk_08);
    }
}

void UnkClass_0211D770::ov8_0211DA98()
{
    char path[0x40];
    GX_SetVisiblePlane(GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1800, GX_BG_CHARBASE_0x10000);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(2);
    G2_SetBG2Priority(3);
    G2_SetBG3Priority(0);
    BGS_LoadCharAndPltt("menu/", "mmq000_bg_", 1, "mmq000", 0, "mmq000", 1);
    BGS_LoadScr("menu/", "mmq000_bg_", 2, "mmq000_02", 1, 0, 0, 0);
    BGS_LoadScr("menu/", "mmq000_bg_", 1, "mmq000_01", 1, 0, 0, 0);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG1, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2, 8, 7);

    unk_18 = new UnkClass_0200ECD0((GXOamAttr *)&unk_21C->unk_0024[0x0A], unk_21C->unk_14A8, FALSE, 0x40);
    unk_18->sub_0200EE14("data/menu", "mmq000_00", 0, 1);
    unk_1C[5] = unk_18->sub_0200F4FC(5, 0x80, 0x60, 1);
    unk_1C[0] = unk_18->sub_0200F4FC(1, 0x16, 0x17, 1);
    unk_34[0] = unk_18->unk_24;
    unk_1C[1] = unk_18->sub_0200F4FC(2, 0xEA, 0x17, 1);
    unk_34[1] = unk_18->unk_24;
    unk_1C[2] = unk_18->sub_0200F4FC(0, 0x80, 0x18, 1);
    unk_1C[3] = unk_18->sub_0200F4FC(3, 0x80, 0x90, 1);
    unk_1C[4] = unk_18->sub_0200F4FC(4, 0x7C, 0x38, 1);
    if (ov8_0211E380() < 0) {
        for (int i = 0; i < 6; i++) {
            if (i != 5 && unk_1C[i] != NULL) {
                unk_1C[i]->unk_14 = 0;
            }
        }
        return;
    }

    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    unk_21C->unk_1494->sub_0200C3D0();
    unk_21C->unk_1494->sub_0200C408(3, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    unk_21C->unk_1494->sub_0200C680(4);
    unk_21C->unk_1494->sub_0200C6C8(0, 0x18, 2, 4, 2, 8, 0, 2);
    unk_21C->unk_1494->sub_0200C6C8(1, 0x11, 2, 5, 6, 0x38, 0, 2);
    unk_21C->unk_1494->sub_0200C6C8(2, 0xF, 2, 6, 8, 0x5A, 0, 2);
    unk_21C->unk_1494->sub_0200C6C8(3, 0x1E, 0xA, 1, 0xC, 0x78, 0, 2);
    unk_0C = new UnkClass_02040F34();
    unk_08 = new Camera2D();
    unk_08->sub_02003788(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);

    for (int i = 0; i < 2; i++) {
        u16 id;
        switch (i) {
        case 0: {
            int mission = ov8_0211E380();
            if (mission < 0) {
                continue;
            }
            if (mission >= 0x45) {
                mission -= 0x31;
            }
            unk_214 = 1;
            id = sMissionActors[mission].actorId;
            int info = ov8_0211E380();
            if (info == 9 && unk_21C->m_missionQuestData->unk_08 >= 0x30) {
                info = 0x14;
            }
            OS_SPrintf(path, "data/message/etc/mission_info_%02d", info);
            unk_3C = new UnkClass_02021404(path);
            break;
        }
        case 1: {
            int quest = ov8_0211E3A4();
            if (quest < 0) {
                continue;
            }
            unk_218 = 1;
            id = sQuestActors[quest].actorId;
            OS_SPrintf(path, "data/message/etc/quest_info_%02d", quest);
            unk_40 = new UnkClass_02021404(path);
            break;
        }
        default:
            break;
        }
        int type = 1;
        if (id == 0) {
            type = 4;
            if (MAIN_BSS_020B26A0.unk_0000 == 0) {
                id = 3;
            } else {
                id = 4;
            }
        }
        unk_50[i].sub_0203C4BC(type, id, 0, 2, 0);
        if (unk_50[i].unk_08 != NULL && unk_50[i].unk_08->unk_0C != NULL) {
            unk_50[i].unk_08->unk_0C->sub_020128EC(0x4000);
        }
    }
}

BOOL UnkClass_0211D770::ov8_0211E0A4(int mode, int arg1)
{
    unk_00 = 0;
    if (mode) {
        if (ov8_0211E380() < 0) {
            return FALSE;
        }
    } else {
        if (ov8_0211E3A4() < 0) {
            return FALSE;
        }
    }
    unk_210 = mode;
    ov8_0211E0FC();
    ov8_0211E164();
    return TRUE;
}

void UnkClass_0211D770::ov8_0211E0FC()
{
    if (unk_18 == NULL) {
        return;
    }
    int anim = 2;
    if (unk_210) {
        anim = 1;
    }
    for (int i = 0; i < 2; i++) {
        unk_18->sub_0200F628(unk_34[i], anim);
    }
}

BOOL UnkClass_0211D770::ov8_0211E148()
{
    ov8_0211DA98();
    ov8_0211D8B8();
    return TRUE;
}

void UnkClass_0211D770::ov8_0211E164()
{
    unk_04 = 1;
}

void UnkClass_0211D770::ov8_0211E170()
{
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    unk_21C->unk_1494->sub_0200C980(0);
    unk_21C->unk_1494->sub_0200C980(1);
    unk_21C->unk_1494->sub_0200C980(2);
    unk_21C->unk_1494->sub_0200C980(3);
    UnkClass_02021404 *info;
    if (unk_210) {
        if (!unk_214) {
            return;
        }
        info = unk_3C;
    } else {
        if (!unk_218) {
            return;
        }
        info = unk_40;
    }
    UnkClass_0200C38C *text = unk_21C->unk_1494;
    text->sub_0200C7A4(0, 0, 2, 3, (u8 *)info->GetString(1), TRUE, 0);
    text = unk_21C->unk_1494;
    text->sub_0200C7A4(1, 0, 0, 3, (u8 *)info->GetString(2), TRUE, 0);
    text = unk_21C->unk_1494;
    text->sub_0200C7A4(2, 0, 0, 3, (u8 *)info->GetString(3), TRUE, 0);
    text = unk_21C->unk_1494;
    text->sub_0200C7A4(3, 2, 6, 1, (u8 *)info->GetString(4), FALSE, 0);
}

int UnkClass_0211D770::ov8_0211E32C()
{
    int mission = ov8_0211E380();
    if (mission < 0) {
        return -1;
    }
    if (mission >= 0x45) {
        mission -= 0x31;
    }
    u16 place = sMissionActors[mission].placeId;
    if (mission == 9 && unk_21C->m_missionQuestData->unk_08 >= 0x30) {
        place = 0x1C;
    }
    return place;
}

int UnkClass_0211D770::ov8_0211E380()
{
    UnkClass_0201164C *data = unk_21C->m_missionQuestData;
    if (data->unk_00 == 0) {
        return -1;
    }
    return data->unk_02 - 1;
}

int UnkClass_0211D770::ov8_0211E3A4()
{
    UnkClass_0201164C *data = unk_21C->m_missionQuestData;
    if (data->unk_01 == 0) {
        return -1;
    }
    return data->unk_03 - 1;
}
