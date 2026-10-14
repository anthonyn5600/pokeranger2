#include "scene/CMissionQuestScene.hpp"

#include "UnkClass_0200C38C.hpp"
#include "UnkClass_0200CAB4.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0201164C.hpp"
#include "UnkClass_02034478.hpp"

extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;

CMissionQuestScene::CMissionQuestScene(CGame *game)
{
    m_game = game;
    ov8_0211CAD4();
}

CMissionQuestScene::~CMissionQuestScene()
{
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    SAFE_DELETE(unk_08);
}

void CMissionQuestScene::ov8_0211CAD4()
{
    unk_08 = new UnkClass_0211CD00(m_game);
}

void CMissionQuestScene::func5()
{
    GX_ResetBankForBG();
    GX_ResetBankForOBJ();
    GX_ResetBankForBGExtPltt();
    GX_ResetBankForOBJExtPltt();
    GX_ResetBankForTex();
    GX_ResetBankForTexPltt();
    GX_ResetBankForClearImage();
    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    GX_ResetBankForSubBGExtPltt();
    GX_ResetBankForSubOBJExtPltt();
    GX_ResetBankForARM7();

    GX_SetBankForTex(GX_VRAM_TEX_0_B);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_0_G);
    GX_SetBankForOBJ(GX_VRAM_OBJ_80_EF);
    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GXS_SetGraphicsMode(GX_BGMODE_0);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GX_SetBGScrOffset(GX_BGSCROFFSET_0x00000);
    GX_SetBGCharOffset(GX_BGCHAROFFSET_0x00000);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_DispOn();
    GXS_DispOn();
}

void CMissionQuestScene::func6()
{
    m_game->sub_020101F4(0x20000, 0, 0x4000);
    if (unk_08 != NULL) {
        unk_08->ov8_0211D310();
        unk_08->ov8_0211D688();
    }
}

void CMissionQuestScene::func7()
{
    m_game->sub_020101F4(0x80000, 0, 0x4000);
}

u32 CMissionQuestScene::func0()
{
    if (unk_08 != NULL) {
        unk_08->ov8_0211CD8C();
        if (unk_08->ov8_0211D758() != -1) {
            return 6;
        }
    }
    return -1;
}

void CMissionQuestScene::func1()
{
    if (unk_08 != NULL) {
        unk_08->ov8_0211CE08();
    }
}

void CMissionQuestScene::func2()
{
    if (unk_08 != NULL) {
        unk_08->ov8_0211CE78();
    }
}

u32 CMissionQuestScene::getSceneId()
{
    return 0xA;
}

UnkClass_0211CD00::UnkClass_0211CD00(CGame *game)
{
    unk_40 = game;
    ov8_0211CD2C();
}

UnkClass_0211CD00::~UnkClass_0211CD00()
{
    ov8_0211CECC();
}

void UnkClass_0211CD00::ov8_0211CD2C()
{
    unk_00 = 0;
    unk_18 = NULL;
    unk_1C = NULL;
    unk_10 = NULL;
    unk_14 = NULL;
    unk_0C = NULL;
    for (int i = 0; i < 6; i++) {
        unk_24[i] = NULL;
    }
    unk_04 = 0;
    unk_08 = new UnkClass_0202A510(unk_40);
}

void UnkClass_0211CD00::ov8_0211CD8C()
{
    if (unk_18 != NULL) {
        unk_18->sub_0200F64C();
    }
    if (unk_1C != NULL) {
        unk_1C->sub_0200F64C();
    }
    if (unk_0C != NULL) {
        unk_0C->ov8_0211D818();
    }
    if (unk_08 != NULL) {
        unk_08->sub_0202A5A8();
    }
    switch (unk_00) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 1:
        ov8_0211D358();
        break;
    }
}

void UnkClass_0211CD00::ov8_0211CE08()
{
    if (unk_0C != NULL) {
        unk_0C->ov8_0211D8A0();
    }
    if (unk_08 != NULL) {
        unk_08->sub_0202A5EC();
    }
    switch (unk_00) {
    case 2:
        if (!ov8_0211D710()) {
            unk_00 = 4;
        }
    case 1:
    case 3:
    case 5:
        ov8_0211CFC4();
        break;
    }
}

void UnkClass_0211CD00::ov8_0211CE78()
{
    if (unk_0C != NULL) {
        unk_0C->ov8_0211D8AC();
    }
    if (unk_08 != NULL) {
        unk_08->sub_0202A5F8();
    }
    ov8_0211D488();
}

void UnkClass_0211CD00::ov8_0211CEAC()
{
    ov8_0211D55C();
    unk_40->unk_1498->sub_0200CB90();
}

void UnkClass_0211CD00::ov8_0211CECC()
{
    unk_40->unk_146C.sub_02008DB4(30);
    unk_40->unk_1498->sub_0200CAE0();
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_08);
}

void UnkClass_0211CD00::ov8_0211CFC4()
{
    if (unk_18 != NULL) {
        unk_18->sub_0200F71C();
    }
    if (unk_1C != NULL) {
        unk_1C->sub_0200F71C();
    }
}

void UnkClass_0211CD00::ov8_0211CFF0()
{
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x4800, GX_BG_CHARBASE_0x10000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(3);
    unk_40->m_audioEngine->sub_020345D4();

    int charNo = 0;
    int paletteSlot = 2;
    u8 oamIndex = 0;
    unk_08->sub_0202A724(6, &oamIndex, &charNo, &paletteSlot, FALSE);

    unk_1C = new UnkClass_0200ECD0((GXOamAttr *)&unk_40->unk_0424[oamIndex], unk_40->unk_14A8, TRUE, 0x40);
    charNo += unk_1C->sub_0200EE14("data/menu", "ma005_00", charNo / 32, 0);
    unk_24[3] = unk_1C->sub_0200F4FC(0, 0xF0, 0x10, 0);
    unk_24[3]->sub_0200EBF4(0x20, 0x20, 0, 0);
    oamIndex += unk_1C->unk_30;

    unk_18 = new UnkClass_0200ECD0((GXOamAttr *)&unk_40->unk_0424[oamIndex], unk_40->unk_14A8, TRUE, 0x40);
    charNo += unk_18->sub_0200EE14("data/menu", "mam000_00", charNo / 32, 1);
    unk_24[0] = unk_18->sub_0200F4FC(0, 0, 0, 1);
    unk_24[0]->sub_0200EBF4(0x18, 0x18, 0, 0);
    oamIndex += unk_18->unk_30;

    unk_10 = MAIN_BSS_0210CA6C;
    unk_14 = new UnkClass_02021404("/data/message/etc/place_name");
    unk_40->unk_1498->sub_0200CAE0();
    unk_40->unk_1498->sub_0200CB14();
    unk_40->unk_1498->sub_0200CC88(1);
    unk_40->unk_1498->sub_0200CCD0(0, 0x10, 2, 1, 0, 0xD, 0, 2);
    unk_0C = new UnkClass_0211D770(unk_40);
    unk_0C->ov8_0211E148();
    ov8_0211D628();
}

BOOL UnkClass_0211CD00::ov8_0211D310()
{
    unk_00 = 1;
    ov8_0211D328();
    return TRUE;
}

BOOL UnkClass_0211CD00::ov8_0211D328()
{
    ov8_0211CFF0();
    ov8_0211CEAC();
    unk_40->unk_146C.sub_02008DB4(60);
    return TRUE;
}

void UnkClass_0211CD00::ov8_0211D358()
{
    u32 cancel = (u16)(unk_40->unk_0014->unk_0002 & PAD_BUTTON_B);
    BOOL touched = unk_24[3]->sub_0200EB84() ? TRUE : FALSE;
    if (touched | cancel) {
        ov8_0211D444();
        return;
    }
    if (unk_24[0]->unk_14 != 0 && unk_24[0]->sub_0200EB84()) {
        unk_40->m_audioEngine->sub_02034C44(0xFA);
        ov8_0211D604();
        return;
    }
    s16 kind;
    u16 id;
    unk_08->sub_0202B5A8(&kind, &id);
    switch ((u16)kind) {
    case 1:
        unk_40->m_audioEngine->sub_02034C44(0xFA);
        ov8_0211D628();
        break;
    case 6:
        unk_40->m_audioEngine->sub_02034C44(0xFA);
        ov8_0211D654(id);
        break;
    }
}

void UnkClass_0211CD00::ov8_0211D444()
{
    unk_40->m_audioEngine->sub_02034C44(0x103);
    unk_00 = 2;
    ov8_0211D6CC();
}

void UnkClass_0211CD00::ov8_0211D478(u16 id)
{
    unk_3C = id;
    unk_04 = 1;
}

void UnkClass_0211CD00::ov8_0211D488()
{
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    if (unk_08 == NULL) {
        return;
    }
    u8 idx = unk_3C;
    if (idx > 200) {
        idx -= 155;
    } else if (idx > 100) {
        idx %= 100;
    }
    unk_40->unk_1498->sub_0200CF7C(0);
    UnkClass_0200CAB4 *text = unk_40->unk_1498;
    text->sub_0200CDA0(0, 0, 3, 3, (u8 *)unk_14->GetString(idx), TRUE, 0);
}

void UnkClass_0211CD00::ov8_0211D55C()
{
    if (unk_40->m_missionQuestData->unk_00 == 0) {
        unk_24[0]->unk_14 = 0;
        return;
    }
    unk_3E = unk_0C->ov8_0211E32C();
    unk_24[0]->unk_14 = 1;
    ov8_0211D5B8(0, unk_3E);
}

void UnkClass_0211CD00::ov8_0211D5B8(int idx, u16 id)
{
    if (unk_08 == NULL) {
        return;
    }
    int x;
    int y;
    unk_08->sub_0202B370(id, &x, &y);
    unk_24[idx]->sub_0200EB28(x, y);
}

void UnkClass_0211CD00::ov8_0211D604()
{
    ov8_0211D678(unk_3E, 1);
    ov8_0211D478(unk_3E);
}

void UnkClass_0211CD00::ov8_0211D628()
{
    u16 id = unk_08->unk_56;
    ov8_0211D678(id, 1);
    ov8_0211D478(id);
}

void UnkClass_0211CD00::ov8_0211D654(u16 id)
{
    ov8_0211D678(id, 3);
    ov8_0211D478(id);
}

void UnkClass_0211CD00::ov8_0211D678(u16 id, int mode)
{
    unk_08->sub_0202B50C(id, mode);
}

void UnkClass_0211CD00::ov8_0211D688()
{
    if (unk_40 != NULL) {
        unk_40->unk_14C0->sub_0200E0E0(3, 15);
        unk_40->unk_14BC->sub_0200E0E0(3, 15);
    }
}

void UnkClass_0211CD00::ov8_0211D6CC()
{
    if (unk_40 != NULL) {
        unk_40->unk_14C0->sub_0200E0E0(4, 15);
        unk_40->unk_14BC->sub_0200E0E0(4, 15);
    }
}

BOOL UnkClass_0211CD00::ov8_0211D710()
{
    if (unk_40->unk_14C0->sub_0200E310() || unk_40->unk_14C0->sub_0200E310()) {
        return TRUE;
    }
    return FALSE;
}

int UnkClass_0211CD00::ov8_0211D758()
{
    return unk_00 != 4 ? -1 : 0;
}
