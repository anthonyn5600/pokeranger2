#include "MissionQuestInfo.hpp"

#include "BGLayer.hpp"
#include "CActor.hpp"
#include "MissionQuestData.hpp"
#include "SaveData.hpp"
#include "TextPrinter.hpp"

struct MissionQuestActor {
    u16 actorId;
    u16 placeId;
};

static MissionQuestActor sMissionActors[26] = {
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

static MissionQuestActor sQuestActors[61] = {
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

MissionQuestInfo::MissionQuestInfo(CGame *game)
{
    unk_21C = game;
    Init();
}

MissionQuestInfo::~MissionQuestInfo()
{
    Release();
}

void MissionQuestInfo::Init()
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

void MissionQuestInfo::Update()
{
    G2_SetBG1Offset(0, -((int)unk_21C->unk_15D0 >> FX32_SHIFT));
    if (unk_18 == NULL) {
        return;
    }
    unk_18->Update();
    if (unk_210) {
        if (unk_214) {
            unk_50[0].Update(NULL);
        }
    } else if (unk_218) {
        unk_50[1].Update(NULL);
    }
}

void MissionQuestInfo::Render()
{
    Draw();
}

void MissionQuestInfo::OnVBlank()
{
    DrawTexts();
}

void MissionQuestInfo::ov8_0211D8B8()
{
    if (unk_18 != NULL) {
        SetMode(TRUE, 0);
        unk_21C->unk_1494->LoadPalette();
    }
}

void MissionQuestInfo::Release()
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
    if (actor->m_drawObject != NULL) {
        actor->m_drawObject->Draw(camera, 0);
    }
}

void MissionQuestInfo::Draw()
{
    if (unk_18 == NULL) {
        return;
    }
    unk_18->WriteOam();
    if (unk_08 == NULL) {
        return;
    }
    unk_08->SetOffset(0x41000, -0x17000);
    unk_08->ApplyProjection();
    unk_08->ApplyView();
    G3_StoreMtx(0);
    if (unk_210) {
        if (unk_214) {
            DrawActor(&unk_50[0], unk_08);
        }
    } else if (unk_218) {
        DrawActor(&unk_50[1], unk_08);
    }
}

void MissionQuestInfo::Load()
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

    unk_18 = new OamSpriteSet((GXOamAttr *)&unk_21C->unk_0024[0x0A], unk_21C->unk_14A8, FALSE, 0x40);
    unk_18->Load("data/menu", "mmq000_00", 0, 1);
    unk_1C[5] = unk_18->AddSprite(5, 0x80, 0x60, 1);
    unk_1C[0] = unk_18->AddSprite(1, 0x16, 0x17, 1);
    unk_34[0] = unk_18->unk_24;
    unk_1C[1] = unk_18->AddSprite(2, 0xEA, 0x17, 1);
    unk_34[1] = unk_18->unk_24;
    unk_1C[2] = unk_18->AddSprite(0, 0x80, 0x18, 1);
    unk_1C[3] = unk_18->AddSprite(3, 0x80, 0x90, 1);
    unk_1C[4] = unk_18->AddSprite(4, 0x7C, 0x38, 1);
    if (GetMissionIndex() < 0) {
        for (int i = 0; i < 6; i++) {
            if (i != 5 && unk_1C[i] != NULL) {
                unk_1C[i]->unk_14 = 0;
            }
        }
        return;
    }

    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    unk_21C->unk_1494->FreeWindows();
    unk_21C->unk_1494->SetupBG(3, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    unk_21C->unk_1494->AllocWindows(4);
    unk_21C->unk_1494->InitWindow(0, 0x18, 2, 4, 2, 8, 0, 2);
    unk_21C->unk_1494->InitWindow(1, 0x11, 2, 5, 6, 0x38, 0, 2);
    unk_21C->unk_1494->InitWindow(2, 0xF, 2, 6, 8, 0x5A, 0, 2);
    unk_21C->unk_1494->InitWindow(3, 0x1E, 0xA, 1, 0xC, 0x78, 0, 2);
    unk_0C = new FieldDrawActorDataPool();
    unk_08 = new Camera2D();
    unk_08->SetOrtho(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);

    for (int i = 0; i < 2; i++) {
        u16 id;
        switch (i) {
        case 0: {
            int mission = GetMissionIndex();
            if (mission < 0) {
                continue;
            }
            if (mission >= 0x45) {
                mission -= 0x31;
            }
            unk_214 = 1;
            id = sMissionActors[mission].actorId;
            int info = GetMissionIndex();
            if (info == 9 && unk_21C->m_missionQuestData->m_chapter >= 0x30) {
                info = 0x14;
            }
            OS_SPrintf(path, "data/message/etc/mission_info_%02d", info);
            unk_3C = new MessageTable(path);
            break;
        }
        case 1: {
            int quest = GetQuestIndex();
            if (quest < 0) {
                continue;
            }
            unk_218 = 1;
            id = sQuestActors[quest].actorId;
            OS_SPrintf(path, "data/message/etc/quest_info_%02d", quest);
            unk_40 = new MessageTable(path);
            break;
        }
        default:
            break;
        }
        int type = 1;
        if (id == 0) {
            type = 4;
            if (MAIN_BSS_020B26A0.m_sex == 0) {
                id = 3;
            } else {
                id = 4;
            }
        }
        unk_50[i].CreateDrawObjectOwnData(type, id, 0, 2, 0);
        if (unk_50[i].m_drawObject != NULL && unk_50[i].m_drawObject->m_actor != NULL) {
            unk_50[i].m_drawObject->m_actor->SetDir(0x4000);
        }
    }
}

BOOL MissionQuestInfo::SetMode(int mode, int arg1)
{
    unk_00 = 0;
    if (mode) {
        if (GetMissionIndex() < 0) {
            return FALSE;
        }
    } else {
        if (GetQuestIndex() < 0) {
            return FALSE;
        }
    }
    unk_210 = mode;
    UpdateTabs();
    RequestDrawTexts();
    return TRUE;
}

void MissionQuestInfo::UpdateTabs()
{
    if (unk_18 == NULL) {
        return;
    }
    int anim = 2;
    if (unk_210) {
        anim = 1;
    }
    for (int i = 0; i < 2; i++) {
        unk_18->SetAnim(unk_34[i], anim);
    }
}

BOOL MissionQuestInfo::Setup()
{
    Load();
    ov8_0211D8B8();
    return TRUE;
}

void MissionQuestInfo::RequestDrawTexts()
{
    unk_04 = 1;
}

void MissionQuestInfo::DrawTexts()
{
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    unk_21C->unk_1494->ClearWindow(0);
    unk_21C->unk_1494->ClearWindow(1);
    unk_21C->unk_1494->ClearWindow(2);
    unk_21C->unk_1494->ClearWindow(3);
    MessageTable *info;
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
    TextPrinter *text = unk_21C->unk_1494;
    text->Print(0, 0, 2, 3, (u8 *)info->GetString(1), TRUE, 0);
    text = unk_21C->unk_1494;
    text->Print(1, 0, 0, 3, (u8 *)info->GetString(2), TRUE, 0);
    text = unk_21C->unk_1494;
    text->Print(2, 0, 0, 3, (u8 *)info->GetString(3), TRUE, 0);
    text = unk_21C->unk_1494;
    text->Print(3, 2, 6, 1, (u8 *)info->GetString(4), FALSE, 0);
}

int MissionQuestInfo::GetMissionPlace()
{
    int mission = GetMissionIndex();
    if (mission < 0) {
        return -1;
    }
    if (mission >= 0x45) {
        mission -= 0x31;
    }
    u16 place = sMissionActors[mission].placeId;
    if (mission == 9 && unk_21C->m_missionQuestData->m_chapter >= 0x30) {
        place = 0x1C;
    }
    return place;
}

int MissionQuestInfo::GetMissionIndex()
{
    MissionQuestData *data = unk_21C->m_missionQuestData;
    if (data->m_missionState == 0) {
        return -1;
    }
    return data->m_missionId - 1;
}

int MissionQuestInfo::GetQuestIndex()
{
    MissionQuestData *data = unk_21C->m_missionQuestData;
    if (data->m_questActive == 0) {
        return -1;
    }
    return data->m_questId - 1;
}
