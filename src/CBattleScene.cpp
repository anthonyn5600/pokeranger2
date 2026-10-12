#include "scene/CBattleScene.hpp"

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "Camera2D.hpp"
#include "UnkClass_020023EC.hpp"
#include "UnkClass_02008D50.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200CFF4.hpp"
#include "UnkClass_0200D3F8.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_02010854.hpp"
#include "UnkClass_02010D2C.hpp"
#include "UnkClass_02018B9C.hpp"
#include "UnkClass_0201AD60.hpp"
#include "UnkClass_0201CA6C.hpp"
#include "UnkClass_02033F04.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_02042108.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkClass_0211D850.hpp"
#include "UnkStruct_020107A8.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/CBattleEnemyGauge.hpp"
#include "battle/CBattleGameOver.hpp"
#include "battle/CBattlePowerSave.hpp"
#include "battle/UnkClass_0212306C.hpp"
#include "battle/UnkClass_021274AC.hpp"
#include "battle/UnkClass_0212770C.hpp"
#include "battle/UnkClass_021278E8.hpp"
#include "battle/UnkClass_02127B48.hpp"
#include "battle/UnkClass_02127E14.hpp"
#include "battle/UnkClass_021281B4.hpp"
#include "battle/UnkClass_02128414.hpp"
#include "battle/UnkClass_02128600.hpp"
#include "battle/UnkClass_02128860.hpp"
#include "battle/UnkClass_02128B24.hpp"
#include "battle/UnkClass_02128E88.hpp"
#include "battle/UnkClass_021291BC.hpp"
#include "battle/UnkClass_021294BC.hpp"
#include "battle/UnkClass_021296C8.hpp"
#include "battle/UnkClass_021297C0.hpp"
#include "battle/UnkClass_021299CC.hpp"
#include "battle/UnkClass_02129B74.hpp"
#include "battle/UnkClass_02129DD4.hpp"
#include "battle/UnkClass_0212DC20.hpp"
#include "battle/UnkClass_0212E008.hpp"
#include "battle/UnkClass_0212E88C.hpp"
#include "battle/UnkClass_0212EEB4.hpp"
#include "battle/UnkClass_02135BB4.hpp"
#include "battle/UnkClass_021364AC.hpp"
#include "battle/UnkClass_02136730.hpp"
#include "battle/UnkClass_02136AD4.hpp"
#include "battle/UnkClass_02137DA4.hpp"
#include "battle/UnkClass_021380AC.hpp"
#include "battle/UnkClass_021382D0.hpp"
#include "battle/UnkClass_021384F8.hpp"
#include "battle/UnkClass_0213AE18.hpp"
#include "battle/UnkClass_0213CC28.hpp"
#include "battle/UnkClass_0213F028.hpp"
#include "battle/UnkStruct_0212DFEC.hpp"
#include "file/CBinaryFile.hpp"
#include "interpolation.hpp"
#include "sub_02007254.hpp"

static inline u32 GetPokemonState(UnkClass_020B26A0 *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->unk_7C3C[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline int CountPokemon(UnkClass_020B26A0 *save)
{
    int n = 0;
    for (int i = 0; i < 500; i++) {
        if (GetPokemonState(save, i) >= 2) {
            n++;
        }
    }
    return n;
}

static const Point2D DAT_overlay_1_0213fb68 = { 0, FX32_CONST(-88) };
static const u32 DAT_overlay_1_0213fb70[] = { 0x2000, 0x3000, 0x4000, 0x14000 };

CBattleScene::CBattleScene(CGame *game)
{
    u8 i;

    m_game = game;
    unk_0C14 = game->unk_1434;
    unk_001C = game->unk_143C;
    game->unk_146C.sub_02008DB4(60);

    for (i = 0; i < sub_02010B90(unk_001C); i++) {
        unk_0082[i] = sub_02010B98(unk_001C, i);
    }
    for (; i < 8; i++) {
        unk_0082[i] = 0;
    }
    for (i = 0; i < sub_02010B90(unk_001C); i++) {
        if (sub_02010BA4(unk_001C, i)) {
            unk_0092[i] = TRUE;
        } else {
            unk_0092[i] = FALSE;
        }
    }
    for (i = 0; i < 8; i++) {
        unk_009A[i] = 0;
        unk_00A4[i] = &unk_009A[i];
    }

    if (sub_02010B24(unk_001C) == 0x23) {
        MAIN_BSS_020B26A0.unk_0028 = 0;
        sub_020160B8(&MAIN_BSS_020B26A0, sub_02010B34(unk_001C));
    }

    unk_0074 = sub_02010B50(unk_001C);
    unk_0078 = sub_02010B58(unk_001C);
    unk_007C = DAT_overlay_1_0213fb70[(u8)sub_02010B60(unk_001C)];
    unk_0070 = 1;
    unk_0010 = CGame::GetInstance()->touchPanel;
    unk_0008 = 0;
    unk_000A = 0;
    unk_000C = 0;
    unk_0020 = 0;
    unk_0024 = 0;
    unk_0028 = 0;
    unk_002C = 0;
    unk_002E = 0;
    unk_0034 = 0;
    unk_0038 = 0;
    unk_0044 = 0;
    unk_003C = 0;
    unk_0058 = 0;
    unk_0BE4 = 0;
    unk_0C3C = 0;
    for (i = 0; i < 8; i++) {
        unk_0046[i] = 0;
    }
    unk_0384 = NULL;
    for (i = 0; i < 3; i++) {
        unk_0378[i] = NULL;
    }
    unk_12C8[0].pos.x = 0;
    unk_12C8[0].pos.y = 0;
    unk_12C8[0].size.x = FX32_CONST(272);
    unk_12C8[0].size.y = FX32_CONST(208);
    unk_12C8[1].pos.x = 0;
    unk_12C8[1].pos.y = 0;
    unk_12C8[1].size.x = FX32_CONST(320);
    unk_12C8[1].size.y = FX32_CONST(256);

    m_game->m_textboxData->sub_02009328(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->unk_14B0, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);
    m_game->m_textboxData->sub_0200AB28(1);
    sub_02033F90(m_game->m_scriptManager, 1);

    if (sub_02010B7C(unk_001C) == 1) {
        game->m_textboxData->sub_020097FC(0, sub_020107A8(unk_0C14, sub_02010B70(unk_001C, 0))->unk_00);
    } else {
        game->m_textboxData->sub_020097FC(0, 0x1EF);
    }
    UnkClass_020091E8 *textbox = game->m_textboxData;
    textbox->sub_020097FC(1, sub_02010C2C(unk_001C));
    if (sub_02010B7C(unk_001C) == 1) {
        game->m_textboxData->sub_020097FC(2, 9);
    } else {
        game->m_textboxData->sub_020097FC(2, 10);
    }
    game->unk_14BC->sub_0200E0E0(1, 0x20);
    game->unk_14C0->sub_0200E0E0(1, 0x20);
}

CBattleScene::~CBattleScene()
{
    m_game->m_audioEngine->sub_02034B58(1);
    ov1_02122D78(1);
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    m_game->unk_146C.sub_02008DB4(30);
}

void CBattleScene::func5()
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

    GX_SetBankForTex(GX_VRAM_TEX_0123_ABCD);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_0_G);
    GX_SetBankForOBJ(GX_VRAM_OBJ_64_E);
    GX_SetBankForBG(GX_VRAM_BG_16_F);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);

    G2_SetBG0Priority(3);
    G2_SetBG1Priority(2);
    G2_SetBG2Priority(1);
    G2_SetBG3Priority(0);

    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);

    GX_SetPower(GX_POWER_ALL);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_DispOn();
    GXS_DispOn();
}

extern u32 gBattleSyscalls[];

void CBattleScene::func6()
{
    u32 offset;
    u16 id;
    u8 j4;
    UnkClass_02010470 *table;
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    sub_02044B38(1, gBattleSyscalls);
    m_game->m_audioEngine->sub_020347C4();

    unk_0C18 = new UnkClass_0212DC20(m_game->unk_14A8);
    unk_0C1C = new UnkClass_0212E008(m_game->unk_14A8);
    unk_0C20 = new UnkClass_0212EEB4("data/param/BattleAssist.bin", m_game->unk_14A8);
    unk_0C24 = new UnkClass_0212EEB4("data/param/BattleAssistPartner.bin", m_game->unk_14A8);
    unk_00C4 = new Camera2D();
    unk_00C8 = new Camera2D();
    unk_00CC = new UnkClass_0200D3F8((UnkStruct_0200D3F8_Target *)unk_00C4);
    unk_00C4->sub_02003788(0, FX32_CONST(192), 0, FX32_CONST(256), FX32_CONST(-2048), FX32_CONST(2047), FX32_CONST(1024));
    unk_00C8->sub_02003788(0, FX32_CONST(192), 0, FX32_CONST(256), FX32_CONST(-2048), FX32_CONST(2048), FX32_CONST(1024));
    unk_00D0 = new UnkClass_0201AD60();
    unk_00D0->SetZ(0x410, 0x411, 0x412);
    unk_00D0->SetPolygonID(0x3A, 0x3B, 0x3C);

    for (int i = 0; i < 0x200; i++) {
        unk_03A8[i] = new UnkClass_02136730();
    }
    unk_0BA8 = new UnkClass_02136AD4(unk_03A8, 0x200);
    unk_0BA8->ov1_02136BD0(1);

    unk_00D8 = new CBattleDisk(unk_0BA8);
    unk_00D8->unk_19C = sub_02010B2C(unk_001C);
    unk_0030 = 0x3B;
    switch (sub_02016C14(&MAIN_BSS_020B26A0, 0x16)) {
    case 0:
        break;
    case 1:
        unk_0030 += 2;
        break;
    case 2:
        unk_0030 += 4;
        break;
    }
    unk_00D8->unk_1B8->ov1_02124AF4(unk_0030);

    if ((u32)((MAIN_BSS_020B26A0.unk_0003 >> 4) & 0xF) < 2) {
        unk_00D8->unk_18C = 0;
    } else {
        unk_00D8->unk_18C = 1;
        unk_00D8->unk_190 = 0;
    }
    if ((u32)(MAIN_BSS_020B26A0.unk_0003 & 0xF) >= 8) {
        unk_00D8->unk_1C0->unk_C71 = 2;
    } else {
        unk_00D8->unk_1C0->unk_C71 = 1;
    }
    if ((u32)(MAIN_BSS_020B26A0.unk_0003 & 0xF) >= 6) {
        unk_00D8->unk_1C0->SetUnkC74(70, 90);
    } else {
        unk_00D8->unk_1C0->SetUnkC74(100, 120);
    }

    table = m_game->unk_1434;
    for (u8 j1 = 0; j1 < sub_02010B68(unk_001C); j1++) {
        id = sub_02010B70(unk_001C, j1);
        if (id != 0xFFFF) {
            unk_00FC[j1] = new CBattleEnemyData(id, sub_020107A8(table, id), unk_0C18->ov1_0212DFEC(id), m_game->unk_14A8);
        }
    }
    for (u8 j2 = 0; j2 < sub_02010B7C(unk_001C); j2++) {
        if (sub_02010B84(unk_001C, j2) != 0xFF) {
            unk_00DC[j2] = new CBattleEnemy(j2 + 1, unk_00FC[sub_02010B84(unk_001C, j2)]);
            unk_00DC[j2]->ov1_02126224();
            unk_00DC[j2]->m_flags |= 0x100;
            if (sub_02010C08(unk_001C)) {
                unk_00DC[j2]->ov1_02126764(1);
            }
        }
    }
    for (u8 j3 = 0; j3 < sub_02010B7C(unk_001C); j3++) {
        if (unk_00DC[j3] != NULL) {
            unk_002E += unk_00DC[j3]->unk_184->unk_1C->unk_02;
        }
    }

    char name[0x60];
    offset = 0;
    for (j4 = 0; j4 < sub_02010B90(unk_001C); j4++) {
        if (sub_02010B98(unk_001C, j4) != 0xFF) {
            id = sub_02010B98(unk_001C, j4);
            unk_0388[j4] = new UnkClass_0200ECD0((GXOamAttr *)CGame::GetInstance()->unk_0024, 0, FALSE, 0x40);
            OS_SPrintf(name, "bp%03d", sub_020107A8(table, id)->unk_00);
            unk_0388[j4]->sub_0200EE14("data/pokeOBJ", name, offset, (u32)j4 + 8);
            offset += unk_0388[j4]->unk_28;
        }
    }

    for (int i = 0; i < 0x60; i++) {
        unk_0130[i] = new CBattleAttackEffect(i + 9);
    }
    for (int i = 0; i < 0x20; i++) {
        unk_02F8[i] = new CBattleAttackEffect(i + 0x69);
    }
    unk_0384 = NULL;
    for (u8 j5 = 0; j5 < 3; j5++) {
        unk_0378[j5] = NULL;
    }
    for (int i = 0; i < 8; i++) {
        unk_0BC4[i] = new UnkClass_02137DA4();
        unk_0BC4[i]->unk_0C = i * -0x80;
    }
    unk_0BAC = new UnkClass_0212E88C();
    unk_0C28 = new UnkClass_02018B9C();
    unk_0C28->SetPolygonID(0x3F);
    unk_0C28->SetAlpha(8);
    unk_012C = new UnkClass_021364AC();

    for (int i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL) {
            unk_010C[i] = new CBattleEnemyGauge(unk_012C);
            CBattleEnemy *enemy = unk_00DC[i];
            UnkStruct_0212DFEC *param = enemy->unk_184->unk_1C;
            Point2D pos;
            pos.x = enemy->m_motion.m_pos.x;
            pos.y = enemy->m_motion.m_pos.y + (param->unk_0F << 12);
            unk_010C[i]->ov1_02135E70(ov1_02122D3C(param->unk_0E), enemy->unk_188, param->unk_00, pos);
        }
    }

    unk_0BE8 = new UnkClass_02129B74();
    unk_0BEC = new UnkClass_021297C0();
    unk_0BF0 = new UnkClass_021278E8();
    unk_0BF4 = new UnkClass_021274AC();
    unk_0BF8 = new UnkClass_021281B4();
    unk_0BFC = new UnkClass_02128600();
    unk_0C00 = new UnkClass_02128E88();
    unk_0C04 = new UnkClass_021294BC();
    for (int i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL) {
            unk_00DC[i]->unk_198->ov1_0212A058(unk_0BE8);
            unk_00DC[i]->unk_19C->ov1_02129AF4(unk_0BEC);
            unk_00DC[i]->unk_1A0->ov1_02127C60(unk_0BF0);
            unk_00DC[i]->unk_1A4->ov1_02127854(unk_0BF4);
            unk_00DC[i]->unk_1A8->ov1_0212854C(unk_0BF8);
            unk_00DC[i]->unk_1AC->ov1_0212891C(unk_0BFC);
            unk_00DC[i]->unk_1B0->ov1_02129274(unk_0C00);
            unk_00DC[i]->unk_1B4->ov1_02129784(unk_0C04);
            unk_00DC[i]->unk_1B8 = unk_010C[i];
            unk_00DC[i]->unk_1BC = unk_0BA8;
        }
    }

    unk_0C10 = new UnkClass_0213F028(sub_02010C34(unk_001C));
    u8 hp;
    u8 maxHP;
    maxHP = MAIN_BSS_020B26A0.unk_0002;
    hp = sub_02010B2C(unk_001C);
    unk_0BB0 = new CPlayerHPGauge();
    unk_0BB0->SetVisible(TRUE);
    unk_0BB0->SetHP(hp, maxHP);
    if (sub_02010B3C(unk_001C)) {
        unk_0BB0->SetPartnerVisible(TRUE);
        unk_0BB0->SetPartner(unk_0074 >> 12, unk_0078 >> 12);
    } else {
        unk_0BB0->SetPartnerVisible(FALSE);
    }
    unk_0C08 = new UnkClass_021380AC();
    unk_0C0C = new UnkClass_021382D0();
    unk_0C2C = new UnkClass_0211D850();
    unk_0C2C->sub_02035D38(sub_02010BB8(unk_001C));
    unk_0C2C->sub_02035DA0(sub_02010BB8(unk_001C), 0, -1, 0);
    unk_0BBC = new CBattleGameOver(m_game, unk_00D8, unk_0BB0);
    unk_0BB8 = new UnkClass_021384F8();
    unk_0BB8->ov1_02139CE4(0x500);
    unk_0C30 = new UnkClass_0213CC28(m_game);
    unk_0C30->ov1_0213EF94(1);
    unk_0C30->ov1_0213E9F4(sub_02010B7C(unk_001C));
    for (u8 j6 = 0; j6 < sub_02010B7C(unk_001C); j6++) {
        UnkStruct_020107A8 *info = sub_020107A8(table, sub_02010B70(unk_001C, sub_02010B84(unk_001C, j6)));
        unk_0C30->ov1_0213EDA4(info->unk_00, j6);
        unk_0C30->ov1_0213EC34(info->unk_03, j6);
    }
    unk_0C34 = new UnkClass_0201CA6C();
    unk_0BC0 = new UnkClass_0213AE18(table, unk_0C18, unk_0C30, unk_00D0);
    unk_00D4 = new UnkClass_02042108(sub_02010BB0(unk_001C));
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x3800, GX_BG_CHARBASE_0x00000);
    CGame::GetInstance()->unk_0C24->sub_02002434(3, 0x2000, 0, 0);
    unk_0C40 = new UnkClass_02135BB4(m_game);

    char sequence[0x60];
    OS_SPrintf(sequence, "data/script/battle/sequence/s%03d.fsb", sub_02010BC0(unk_001C));
    unk_0C44[0].file = new CBinaryFile(sequence, 0, 0, 0, NULL, 0);
    unk_0C44[0].data = unk_0C44[0].file->unk_4C;
    sub_02044AC8(unk_0C44[0].data);
    sub_02044B48(&unk_0C44[0].vm, unk_0C44[0].stack, 0x80);
    u32 *top = unk_0C44[0].vm.unk_04 -= 2;
    top[0] = 1;
    top[1] = sub_02010B7C(unk_001C);
    sub_02046040(&unk_0C44[0].vm, unk_0C44[0].data, "initialize", 2);
    sub_02045A18(&unk_0C44[0].vm, unk_0C44[0].data, "proc");

    char tutorial[0x60];
    OS_SPrintf(tutorial, "data/script/battle/tutorial/t%03d.fsb", sub_02010BC8(unk_001C));
    unk_0C44[1].file = new CBinaryFile(tutorial, 0, 0, 0, NULL, 0);
    unk_0C44[1].data = unk_0C44[1].file->unk_4C;
    sub_02044AC8(unk_0C44[1].data);
    sub_02044B48(&unk_0C44[1].vm, unk_0C44[1].stack, 0x80);
    top = unk_0C44[1].vm.unk_04 -= 2;
    top[0] = 1;
    top[1] = sub_02010B7C(unk_001C);
    sub_02046040(&unk_0C44[1].vm, unk_0C44[1].data, "initialize", 2);
    sub_02045A18(&unk_0C44[1].vm, unk_0C44[1].data, "proc");

    char start[0x60];
    OS_SPrintf(start, "data/script/battle/start/s%03d.fsb", sub_02010BD0(unk_001C));
    unk_0C44[2].file = new CBinaryFile(start, 0, 0, 0, NULL, 0);
    unk_0C44[2].data = unk_0C44[2].file->unk_4C;
    sub_02044AC8(unk_0C44[2].data);
    sub_02044B48(&unk_0C44[2].vm, unk_0C44[2].stack, 0x80);
    top = unk_0C44[2].vm.unk_04 -= 2;
    top[0] = 1;
    top[1] = sub_02010B7C(unk_001C);
    sub_02046040(&unk_0C44[2].vm, unk_0C44[2].data, "initialize", 2);
    sub_02045A18(&unk_0C44[2].vm, unk_0C44[2].data, "proc");

    NNS_GfdDumpLnkTexVramManager();
    NNS_GfdDumpLnkPlttVramManager();
}

void CBattleScene::func7()
{
    sub_02034290(m_game->m_scriptManager);
    m_game->m_textboxData->sub_0200AC90();
    m_game->m_textboxData->sub_0200B59C();
    m_game->m_textboxData->sub_020092D4();

    SAFE_DELETE(unk_00C4);
    SAFE_DELETE(unk_00C8);
    SAFE_DELETE(unk_00CC);
    SAFE_DELETE(unk_00D0);
    SAFE_DELETE(unk_00D4);
    SAFE_DELETE(unk_00D8);
    for (int i = 0; i < 8; i++) {
        SAFE_DELETE(unk_00DC[i]);
    }
    for (int i = 0; i < 4; i++) {
        SAFE_DELETE(unk_00FC[i]);
    }
    for (int i = 0; i < 4; i++) {
        SAFE_DELETE(unk_010C[i]);
    }
    SAFE_DELETE(unk_012C);
    for (int i = 0; i < 0x60; i++) {
        SAFE_DELETE(unk_0130[i]);
    }
    for (int i = 0; i < 0x12; i++) {
        SAFE_DELETE(unk_02B0[i]);
    }
    for (int i = 0; i < 0x20; i++) {
        SAFE_DELETE(unk_02F8[i]);
    }
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(unk_0378[i]);
    }
    SAFE_DELETE(unk_0384);
    for (int i = 0; i < 8; i++) {
        SAFE_DELETE(unk_0388[i]);
    }
    for (int i = 0; i < 0x200; i++) {
        SAFE_DELETE(unk_03A8[i]);
    }
    SAFE_DELETE(unk_0BA8);
    SAFE_DELETE(unk_0BAC);
    SAFE_DELETE(unk_0BB0);
    SAFE_DELETE(unk_0BB4);
    SAFE_DELETE(unk_0BB8);
    SAFE_DELETE(unk_0BBC);
    SAFE_DELETE(unk_0BC0);
    SAFE_DELETE(unk_0C34);
    for (int i = 0; i < 8; i++) {
        SAFE_DELETE(unk_0BC4[i]);
    }
    SAFE_DELETE(unk_0BE8);
    SAFE_DELETE(unk_0BEC);
    SAFE_DELETE(unk_0BF0);
    SAFE_DELETE(unk_0BF4);
    SAFE_DELETE(unk_0BF8);
    SAFE_DELETE(unk_0BFC);
    SAFE_DELETE(unk_0C00);
    SAFE_DELETE(unk_0C04);
    SAFE_DELETE(unk_0C10);
    SAFE_DELETE(unk_0C08);
    SAFE_DELETE(unk_0C0C);
    SAFE_DELETE(unk_0C2C);
    SAFE_DELETE(unk_0C18);
    SAFE_DELETE(unk_0C1C);
    SAFE_DELETE(unk_0C20);
    SAFE_DELETE(unk_0C24);
    SAFE_DELETE(unk_0C28);
    SAFE_DELETE(unk_0C30);
    SAFE_DELETE(unk_0C40);
    SAFE_DELETE(unk_0C44[0].file);
    SAFE_DELETE(unk_0C44[1].file);
    SAFE_DELETE(unk_0C44[2].file);
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
}

void CBattleScene::ov1_0211E71C(u8 arg0)
{
    NNS_GfdDumpLnkTexVramManager();
    SAFE_DELETE(unk_00D4);
    BOOL hadAssist = FALSE;
    int type;
    u16 value;
    u32 partner;
    if (unk_0384 != NULL) {
        hadAssist = TRUE;
        type = unk_0384->vfunc_10();
        partner = unk_0C38;
        value = unk_0384->unk_04;
        SAFE_DELETE(unk_0384);
    }
    unk_00D4 = new UnkClass_02042108(arg0);
    if (hadAssist) {
        ov1_0211E928(type, value, partner);
    }
    NNS_GfdDumpLnkTexVramManager();
}

BOOL CBattleScene::ov1_0211E7E8(u16 id)
{
    if (unk_0BE4 >= 0x12) {
        return FALSE;
    }
    for (int i = 0; i < unk_0BE4; i++) {
        if (unk_02B0[i] != NULL && unk_02B0[i]->unk_18->unk_00 == id) {
            return FALSE;
        }
    }
    UnkStruct_0212E008 *entry = unk_0C1C->GetEntry(id);
    unk_02B0[unk_0BE4] = new CBattleAttackEffectData(id, entry, m_game->unk_14A8);
    unk_0BE4++;
    return TRUE;
}

BOOL CBattleScene::ov1_0211E8A4(u16 id, CBattleAttackEffectData **slot)
{
    SAFE_DELETE(*slot);
    UnkStruct_0212E008 *entry = unk_0C1C->GetEntry(id);
    *slot = new CBattleAttackEffectData(id, entry, m_game->unk_14A8);
    return TRUE;
}

void CBattleScene::ov1_0211E928(int type, u16 arg1, u32 partner)
{
    ov1_02122B90();
    SAFE_DELETE(unk_0384);
    for (u8 i = 0; i < 3; i++) {
        SAFE_DELETE(unk_0378[i]);
    }
    UnkClass_0212EEB4 *params = partner ? unk_0C24 : unk_0C20;
    unk_0C38 = partner;
    UnkClass_02034478 *audio = CGame::GetInstance()->m_audioEngine;
    switch (type) {
    case 0:
        unk_0384 = new CBattleAssistNormal(unk_02F8, unk_0378, params, arg1);
        break;
    case 1:
        ov1_0211E8A4(0xD6, &unk_0378[0]);
        unk_0384 = new CBattleAssistFire(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x90);
        break;
    case 2:
        ov1_0211E8A4(0xCB, &unk_0378[0]);
        unk_0384 = new CBattleAssistWater(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x8B);
        break;
    case 4:
        ov1_0211E8A4(0xD5, &unk_0378[0]);
        unk_0384 = new CBattleAssistGrass(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x91);
        break;
    case 3:
        ov1_0211E8A4(0xD7, &unk_0378[0]);
        unk_0384 = new CBattleAssistElectric(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x92);
        break;
    case 5:
        ov1_0211E8A4(0xCD, &unk_0378[0]);
        ov1_0211E8A4(0xCE, &unk_0378[1]);
        unk_0384 = new CBattleAssistIce(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x8C);
        break;
    case 6:
        unk_0384 = new CBattleAssistGrapple(unk_02F8, unk_0378, params, arg1);
        break;
    case 7:
        ov1_0211E8A4(0xCF, &unk_0378[0]);
        unk_0384 = new CBattleAssistPoison(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x93);
        break;
    case 8: {
        ov1_0211E8A4(0xCA, &unk_0378[0]);
        CBattleAssistGround *ground = new CBattleAssistGround(unk_02F8, unk_0378, params, arg1);
        ground->ov1_0213219C(ov1_021227C4());
        unk_0384 = ground;
        audio->sub_020348DC(0x8D);
        break;
    }
    case 9:
        ov1_0211E8A4(0xD0, &unk_0378[0]);
        unk_0384 = new CBattleAssistFly(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x94);
        break;
    case 10:
        ov1_0211E8A4(0xCC, &unk_0378[0]);
        unk_0384 = new CBattleAssistEsper(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x8F);
        break;
    case 11: {
        ov1_0211E8A4(0xD1, &unk_0378[0]);
        ov1_0211E8A4(0xD2, &unk_0378[1]);
        CBattleAssistInsect *insect = new CBattleAssistInsect(unk_02F8, unk_0378, params, arg1);
        unk_0384 = insect;
        insect->ov1_02133B3C(unk_0130);
        audio->sub_020348DC(0x95);
        break;
    }
    case 12:
        ov1_0211E8A4(0xC8, &unk_0378[0]);
        unk_0384 = new CBattleAssistRock(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x8E);
        break;
    case 13:
        ov1_0211E8A4(0xD3, &unk_0378[0]);
        unk_0384 = new CBattleAssistGhost(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x96);
        break;
    case 14:
        ov1_0211E8A4(0xD4, &unk_0378[0]);
        unk_0384 = new CBattleAssistDragon(unk_02F8, unk_0378, params, arg1);
        ((CBattleAssistDragon *)unk_0384)->unk_44 = ov1_021227C4();
        audio->sub_020348DC(0x97);
        break;
    case 15:
        unk_0384 = new CBattleAssistEvil(unk_02F8, unk_0378, params, arg1);
        break;
    case 16:
        ov1_0211E8A4(0xC9, &unk_0378[0]);
        unk_0384 = new CBattleAssistSteel(unk_02F8, unk_0378, params, arg1);
        audio->sub_020348DC(0x98);
        break;
    case 17: {
        CBattleAssistRecover *recover = new CBattleAssistRecover(unk_02F8, unk_0378, params, arg1);
        unk_0384 = recover;
        recover->unk_1C = unk_0BB0;
        break;
    }
    }
    if (type == 0) {
        unk_00D8->unk_1B8->ov1_02124AF4(unk_0030 + 0x10);
    } else {
        unk_00D8->unk_1B8->ov1_02124AF4(unk_0030);
    }
    if (type != 0x11) {
        unk_00D8->unk_1B8->ov1_02124B08(type);
    } else {
        unk_00D8->unk_1B8->ov1_02124DEC();
    }
    unk_00D8->unk_190 = 1;
}

void CBattleScene::ov1_0211EF74(u16 id, u32 partner)
{
    UnkStruct_020107A8 *info = sub_020107A8(unk_0C14, id);
    UnkStruct_0212DFEC *param = unk_0C18->ov1_0212DFEC(id);
    if (info->unk_04 != 0x11) {
        ov1_0211E928(info->unk_04, ov1_0211F010(id), partner);
    } else {
        ov1_0211E928(0x11, param->unk_04, partner);
    }
    unk_0C30->ov1_0213EDB0(info->unk_04, info->unk_05, info->unk_06);
    unk_0C30->ov1_0213D92C(sub_020107A8(unk_0C14, id)->unk_00);
}

u16 CBattleScene::ov1_0211F010(u16 id)
{
    UnkStruct_020107A8 *info = sub_020107A8(unk_0C14, id);
    UnkStruct_0212DFEC *param = unk_0C18->ov1_0212DFEC(id);
    if (info->unk_04 != 0x11) {
        u16 value = param->unk_04 * 60;
        switch (sub_02016C14(&MAIN_BSS_020B26A0, 0x11)) {
        case 0:
            break;
        case 1:
            value = value * 120 / 100;
            break;
        case 2:
            value = value * 140 / 100;
            break;
        }
        return value;
    }
    return 0;
}

void CBattleScene::ov1_0211F0D8(int arg0, u16 arg1)
{
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL) {
            unk_00DC[i]->ov1_021263A4(arg0, arg1);
        }
    }
}

u32 CBattleScene::func0()
{
    int result = -1;
    switch (unk_0020) {
    case 0:
        result = ov1_0211F2B4();
        break;
    case 1:
        result = ov1_0211F3CC();
        break;
    case 2:
        result = ov1_0211F404();
        break;
    case 3:
        result = ov1_0211F984();
        break;
    case 4:
        result = ov1_0211F9D8();
        break;
    case 5:
        result = ov1_0211FA90();
        break;
    case 7:
        result = ov1_0211FB88();
        break;
    case 6:
        result = ov1_0211FC38();
        break;
    case 11:
        result = ov1_0211FD68();
        break;
    case 8:
        result = ov1_0211FCE0();
        break;
    case 9:
        result = ov1_02120694();
        break;
    case 10:
        result = ov1_021208BC();
        break;
    }
    unk_0BB0->SetCurrentHP(unk_00D8->unk_19C);
    unk_0BB0->vfunc_08();
    unk_00D8->unk_19D = unk_0BB0->GetHPLevel();
    unk_00D0->Update();
    unk_0C08->ov1_02138238();
    unk_0C0C->ov1_02138460();
    if (unk_0020 == 2 && unk_0384 != NULL) {
        unk_0C30->ov1_0213E9E4(unk_0384->unk_04);
    }
    if (unk_0020 == 5) {
        unk_0C30->ov1_0213E32C(0);
    } else {
        unk_0C30->ov1_0213E32C(1);
    }
    unk_0C2C->sub_0203580C(60);
    unk_0024 = unk_0020;
    if (unk_0008 & 1) {
        return sub_02010B24(unk_001C);
    }
    return result;
}

int CBattleScene::ov1_0211F2B4()
{
    BOOL done = FALSE;
    if (unk_0C44[2].file != NULL) {
        if (sub_02044C9C(&unk_0C44[2].vm, 0xFFFFF) == 2) {
            done = TRUE;
        }
    } else {
        done = TRUE;
    }
    if (done == TRUE) {
        for (u8 i = 0; i < sub_02010B7C(unk_001C); i++) {
            if (unk_00DC[i] != NULL) {
                unk_00DC[i]->m_flags &= ~0x100;
            }
        }
        UnkClass_02034478 *audio = CGame::GetInstance()->m_audioEngine;
        audio->sub_0203481C(sub_02010BD8(unk_001C));
        audio = CGame::GetInstance()->m_audioEngine;
        audio->sub_02034AE4(sub_02010BD8(unk_001C), 0);
        unk_0C10->ov1_0213F8B4();
        unk_0020 = 1;
        return -1;
    }
    ov1_02121350();
    ov1_021214B4();
    ov1_0212156C();
    ov1_0212157C();
    unk_00CC->sub_0200D9CC();
    return -1;
}

int CBattleScene::ov1_0211F3CC()
{
    unk_0C10->ov1_0213F338();
    if (!unk_0C10->IsActive()) {
        unk_0020 = 2;
    }
    return -1;
}

int CBattleScene::ov1_0211F404()
{
    if (unk_0C44[0].file != NULL) {
        sub_02044C9C(&unk_0C44[0].vm, 0xFFFFF);
    }
    if (unk_0C44[1].file != NULL) {
        sub_02044C9C(&unk_0C44[1].vm, 0xFFFFF);
    }
    if (unk_0008 & 2) {
        return -1;
    }
    if (unk_0044 != sub_02010B7C(unk_001C)) {
        unk_0028++;
    }
    ov1_02121460();
    ov1_02121514();
    if (unk_0020 != 2) {
        return -1;
    }
    ov1_02121184();
    ov1_021209C4();
    ov1_02121350();
    ov1_021214B4();
    ov1_0212156C();
    ov1_0212157C();
    if (unk_0074 > unk_0078) {
        unk_0074 = unk_0078;
    }
    unk_0BB0->SetPartnerEnergy(unk_0074 >> 12);
    unk_00CC->sub_0200D9CC();

    Point2D touchPos = { (unk_0010->unk_0A.x - 0x80) << FX32_SHIFT, (unk_0010->unk_0A.y - 0x60) << FX32_SHIFT };
    if (unk_0044 != sub_02010B7C(unk_001C)) {
        if (unk_0010->unk_04 != 0) {
            if (sub_02010BE0(unk_001C)) {
                if (sub_02006000(touchPos, unk_0C08->unk_04->unk_18, 0)) {
                    unk_0C08->ov1_02138280();
                    unk_0080 |= 1;
                    unk_0081 = 0;
                }
            }
            if (sub_02010BF4(unk_001C)) {
                if (sub_02006000(touchPos, unk_0C0C->unk_04->unk_18, 0)) {
                    unk_0C0C->ov1_021384A8();
                    unk_0080 |= 2;
                    unk_0081 = 0;
                }
            }
        }
        if (unk_0010->unk_05 != 0) {
            BOOL held = TRUE;
            if ((unk_0080 & 1) && !sub_02006000(touchPos, unk_0C08->unk_04->unk_18, 0)) {
                unk_0080 &= ~1;
                held = FALSE;
            } else if ((unk_0080 & 2) && !sub_02006000(touchPos, unk_0C0C->unk_04->unk_18, 0)) {
                unk_0080 &= ~2;
                held = FALSE;
            }
            if (held && unk_0081 < 0xFF) {
                unk_0081++;
            }
        }
        if (unk_0010->unk_06 != 0) {
            if (unk_0081 <= 12) {
                if (sub_02006000(touchPos, unk_0C08->unk_04->unk_18, 0)) {
                    if (unk_0080 & 1) {
                        unk_0080 &= ~1;
                        unk_0034--;
                        unk_0C30->ov1_0213EF14(1);
                        unk_0C30->ov1_0213EF40(1);
                        unk_0C30->ov1_0213E7B8();
                        unk_00D0->Open();
                        u8 mask = 0;
                        for (u8 i = 0; i < sub_02010B90(unk_001C); i++) {
                            if (unk_0092[i]) {
                                mask |= 1 << i;
                            }
                        }
                        if (sub_02010B3C(unk_001C)) {
                            if (unk_0074 == unk_0078) {
                                mask |= 1;
                            } else {
                                mask &= ~1;
                            }
                        }
                        int count = (u32)sub_02015658(&MAIN_BSS_020B26A0, 0xFF) <= sub_02010B90(unk_001C) ? sub_02010B90(unk_001C) : sub_02015658(&MAIN_BSS_020B26A0, 0xFF);
                        unk_0BC0->ov1_0213C2BC(count, unk_0388, unk_0082, mask, sub_02010B3C(unk_001C));
                        m_game->m_audioEngine->sub_02034C70();
                        m_game->m_audioEngine->sub_02034C44(0xFA);
                        unk_0020 = 5;
                    }
                } else if (sub_02006000(touchPos, unk_0C0C->unk_04->unk_18, 0)) {
                    if (unk_0080 & 2) {
                        unk_0080 &= ~2;
                        unk_0034--;
                        m_game->m_audioEngine->sub_02034C70();
                        unk_00D0->Open();
                        sub_02034184(m_game->m_scriptManager, "system_001");
                        unk_0020 = 4;
                        m_game->m_audioEngine->sub_02034F10(0x3F);
                        m_game->m_audioEngine->sub_02034C44(0xFA);
                    }
                }
            }
            unk_0080 &= ~1;
            unk_0080 &= ~2;
        }
    }
    ov1_02121714();
    if (unk_00D8->unk_19C != 0) {
        return -1;
    }
    ov1_02122B70();
    return -1;
}

int CBattleScene::ov1_0211F984()
{
    if ((u16)(m_game->unk_0014->unk_0002 & 0x100)) {
        unk_00D0->Close();
    }
    if (!unk_00D0->IsOpen()) {
        unk_0020 = 2;
    }
    return -1;
}

int CBattleScene::ov1_0211F9D8()
{
    if (unk_0C44[1].file != NULL) {
        sub_02044C9C(&unk_0C44[1].vm, 0xFFFFF);
    }
    if (unk_0008 & 2) {
        return -1;
    }
    if (unk_00D0->unk_04 == 0 && !m_game->m_textboxData->sub_0200B6A4(1)) {
        if (m_game->m_textboxData->sub_0200B6D4() == 0) {
            ov1_021227CC(3);
        } else {
            unk_00D0->Close();
            unk_0020 = 2;
        }
        m_game->m_audioEngine->sub_02034F10(0x7F);
    }
    return -1;
}

int CBattleScene::ov1_0211FA90()
{
    if (unk_0C44[1].file != NULL) {
        sub_02044C9C(&unk_0C44[1].vm, 0xFFFFF);
    }
    if (unk_0008 & 2) {
        return -1;
    }
    unk_0BC0->ov1_0213B528(unk_0010);
    if (!unk_0BC0->IsActive()) {
        if (unk_0BC0->ov1_0213C5F4() == 0) {
            *unk_00A4[unk_0BC0->ov1_0213C5FC()] = 1;
            if (sub_02010B3C(unk_001C) && unk_0BC0->ov1_0213C5FC() == 0) {
                unk_0074 = 0;
            } else {
                ov1_02122CA4(unk_0BC0->ov1_0213C5FC());
            }
            if (unk_0BC0->ov1_0213C604() == 1) {
                unk_000C |= 8;
            }
        } else {
            unk_00D0->Close();
        }
        unk_0020 = 2;
    }
    return -1;
}

int CBattleScene::ov1_0211FB88()
{
    unk_0BB8->ov1_02138FEC();
    if (!unk_0BB8->IsActive()) {
        m_game->unk_14BC->sub_0200E0E0(4, 10);
        m_game->unk_14C0->sub_0200E0E0(4, 10);
        CBattleResultParameter *result = m_game->unk_1444;
        result->unk_6A = unk_0BB8->ov1_0213A4A0(unk_0BB8->unk_02E);
        result->unk_80 = unk_0BB8->unk_008;
        u8 hp = unk_0BB0->m_hp;
        unk_00D8->unk_19C = hp;
        result->unk_04 = hp;
        unk_0020 = 8;
    }
    return -1;
}

int CBattleScene::ov1_0211FC38()
{
    unk_0BBC->vfunc_08();
    if (!unk_0BBC->ov1_0213AA58()) {
        CBattleResultParameter *result = m_game->unk_1444;
        result->unk_08 = 1;
        u8 hp = unk_0BB0->m_hp;
        unk_00D8->unk_19C = hp;
        result->unk_04 = hp;
        ov1_021227CC(1);
    }
    ov1_02121460();
    ov1_02121514();
    ov1_02121184();
    ov1_021209C4();
    ov1_02121350();
    ov1_021214B4();
    ov1_0212156C();
    ov1_0212157C();
    return -1;
}

int CBattleScene::ov1_0211FCE0()
{
    if (!m_game->unk_14BC->sub_0200E310() && !m_game->unk_14C0->sub_0200E310()) {
        unk_0008 |= 1;
        if (m_game->unk_0008 != 1) {
            m_game->unk_14BC->sub_0200E0E0(1, 0);
            m_game->unk_14C0->sub_0200E0E0(1, 0);
        }
    }
    return -1;
}

static inline void SetDebugAssist(CBattleScene *scene, int type, u16 value)
{
    scene->unk_0C30->ov1_0213ECB4(type, 0, 0);
    scene->unk_0C30->ov1_0213EDB0(type, 0, 0);
    scene->unk_0C30->ov1_0213D92C(0);
    scene->ov1_0211E928(type, value, 0);
}

int CBattleScene::ov1_0211FD68()
{
    unk_0C40->ov1_02135C58();
    if (unk_0C40->ov1_02135C68() == 0) {
        G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
        GX_SetVisiblePlane(GX_PLANEMASK_BG0);
        unk_0020 = 2;
        int value = unk_0C40->ov1_02135C8C();
        switch (unk_0C40->ov1_02135C78()) {
        case 6:
            if (value == 1) {
                unk_000A |= 8;
            }
            if (value == 2) {
                unk_000A &= ~8;
            }
            break;
        case 7:
            if (value == 1) {
                unk_000A |= 0x10;
            }
            if (value == 2) {
                unk_000A &= ~0x10;
            }
            break;
        case 8:
            if (value == 1) {
                unk_000A |= 2;
            }
            if (value == 2) {
                unk_000A &= ~2;
            }
            break;
        case 9:
            if (value == 1) {
                unk_000A |= 4;
            }
            if (value == 2) {
                unk_000A &= ~4;
            }
            break;
        case 10:
            unk_00D8->unk_19C = value;
            break;
        case 11:
            unk_00D8->ov1_0212C5F0(!unk_00D8->ov1_0212C5D8());
            break;
        case 12:
            ov1_0211F0D8(1, value * 60);
            break;
        case 13:
            ov1_0211F0D8(2, value * 60);
            break;
        case 14:
            ov1_0211F0D8(3, value * 60);
            break;
        case 15:
            ov1_0211F0D8(4, value * 60);
            break;
        case 16:
            SetDebugAssist(this, 0, value * 60);
            break;
        case 17:
            SetDebugAssist(this, 1, value * 60);
            break;
        case 18:
            SetDebugAssist(this, 2, value * 60);
            break;
        case 19:
            SetDebugAssist(this, 4, value * 60);
            break;
        case 20:
            SetDebugAssist(this, 3, value * 60);
            break;
        case 21:
            SetDebugAssist(this, 5, value * 60);
            break;
        case 22:
            SetDebugAssist(this, 6, value * 60);
            break;
        case 23:
            SetDebugAssist(this, 7, value * 60);
            break;
        case 24:
            SetDebugAssist(this, 8, value * 60);
            break;
        case 25:
            SetDebugAssist(this, 9, value * 60);
            break;
        case 26:
            SetDebugAssist(this, 10, value * 60);
            break;
        case 27:
            SetDebugAssist(this, 11, value * 60);
            break;
        case 28:
            SetDebugAssist(this, 12, value * 60);
            break;
        case 29:
            SetDebugAssist(this, 13, value * 60);
            break;
        case 30:
            SetDebugAssist(this, 14, value * 60);
            break;
        case 31:
            SetDebugAssist(this, 15, value * 60);
            break;
        case 32:
            SetDebugAssist(this, 16, value * 60);
            break;
        case 33:
            SetDebugAssist(this, 0x11, value);
            break;
        case 34:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            ov1_021227CC(0);
            break;
        case 35:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            ov1_021227CC(1);
            break;
        case 36:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            ov1_021227CC(2);
            break;
        case 37:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            ov1_021227CC(3);
            break;
        case 38:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            ov1_021227CC(4);
            break;
        }
        unk_0C40->ov1_02135C2C();
    }
    return -1;
}

int CBattleScene::ov1_02120694()
{
    int index;
    u16 i;
    UnkClass_0200E0B4 *fade;
    int count;
    UnkClass_02001C04 *input;
    input = m_game->unk_0014;
    if (unk_0068 != 0) {
        if (unk_0010->unk_04 != 0 || (u16)(input->unk_0002 & 1)) {
            if (unk_005D == unk_005C) {
                m_game->m_textboxData->sub_02009FB0(1, 1);
                unk_0BB8->ov1_02139C30(unk_00D8, unk_0BB0);
                if (!unk_00D0->IsOpen()) {
                    unk_00D0->Open();
                }
                unk_0020 = 7;
            } else {
                unk_0068 = 0;
            }
        }
    } else {
        fade = m_game->unk_14C0;
        fade->sub_0200E0E0(1, 0xFFFF);
        fade->sub_0200E210();
        m_game->m_textboxData->sub_0200AA04(0);
        m_game->m_textboxData->sub_020097FC(0, unk_005E[unk_005D]);
        m_game->m_textboxData->sub_0200AD34(0x1A, 1, 1, 0);
        for (i = 0; i < 500; i++) {
            if (unk_005E[unk_005D] == sub_020107A8(unk_0C14, i)->unk_00) {
                index = i;
                break;
            }
        }
        count = CountPokemon(&MAIN_BSS_020B26A0);
        unk_0C34->Release();
        unk_0C34->Load(index, 0, count + unk_005D + 1);
        m_game->m_audioEngine->sub_02034C44(0x3F);
        fade->sub_0200E0E0(1, 0x20);
        unk_005D++;
        unk_0068 = 1;
    }
    return -1;
}

int CBattleScene::ov1_021208BC()
{
    unk_006C++;
    if (unk_006C > 0x98) {
        if (unk_005C != 0) {
            if (sub_02010B24(unk_001C) == 0x23) {
                unk_0BB8->ov1_02139C30(unk_00D8, unk_0BB0);
                if (!unk_00D0->IsOpen()) {
                    unk_00D0->Open();
                }
                unk_0020 = 7;
            } else {
                unk_0C30->ov1_0213EF94(0);
                unk_0020 = 9;
            }
        } else {
            unk_0BB8->ov1_02139C30(unk_00D8, unk_0BB0);
            if (!unk_00D0->IsOpen()) {
                unk_00D0->Open();
            }
            unk_0020 = 7;
        }
    }
    ov1_02121460();
    ov1_02121514();
    ov1_02121184();
    ov1_02121350();
    ov1_021214B4();
    ov1_0212156C();
    ov1_0212157C();
    return -1;
}

void CBattleScene::ov1_021209C4()
{
    Point2D touchPos = { (unk_0010->unk_0A.x - 0x80) << FX32_SHIFT, (unk_0010->unk_0A.y - 0x60) << FX32_SHIFT };
    if (unk_0044 != sub_02010B7C(unk_001C) && unk_00D8->ov1_0212C4B8()) {
        if (unk_0010->unk_04 != 0) {
            unk_0040 = 0;
            unk_00D8->m_motion.sub_02011D3C(touchPos);
            unk_00D8->ov1_0212C610(touchPos.x, touchPos.y);
            unk_00D8->ov1_0212C514(1);
            unk_00D8->vfunc_08();
            m_game->m_audioEngine->sub_02034E48(0);
            unk_0034++;
            unk_003C = 0;
            unk_00D8->unk_187 = 0;
        } else if (unk_0010->unk_06 != 0) {
            unk_00D8->ov1_0212C514(0);
            unk_00D8->vfunc_08();
            m_game->m_audioEngine->sub_02034ED8(0);
        } else if (unk_0010->unk_05 != 0 && unk_00D8->ov1_0212C5C0()) {
            unk_00D8->m_motion.sub_02011D3C(touchPos);
            UnkClass_0212306C *line = unk_00D8->unk_1B8;
            Point2D last = line->m_lines[line->m_head].GetStart();
            if (MATH_IAbs(sub_02007254(touchPos.x - last.x, touchPos.y - last.y)) >= 0x8000) {
                m_game->m_audioEngine->sub_02034E80(12);
            } else {
                m_game->m_audioEngine->sub_02034E80(-12);
            }
            unk_00D8->ov1_0212C1C4(touchPos);
            if (unk_00D8->ov1_0212C4CC()) {
                u8 hits = 0;
                u8 captured = 0;
                for (u8 i = 0; i < 8; i++) {
                    CBattleEnemy *enemy = unk_00DC[i];
                    if (enemy != NULL && enemy->IsAlive() && enemy->IsTargetable()
                        && unk_00D8->unk_1B8->ov1_02124650(enemy->m_motion.m_pos.x, enemy->m_motion.m_pos.y - (enemy->m_bobHeight + (enemy->unk_8C + enemy->m_jumpHeight)))) {
                        if (hits == 0) {
                            unk_00D8->unk_187 = ++unk_003C;
                        }
                        hits++;
                        u16 level = sub_02010E90(m_game->unk_1438, MAIN_BSS_020B26A0.unk_87DB);
                        u8 type = enemy->unk_184->unk_18->unk_03;
                        enemy->ov1_02126310(unk_00D8->ov1_0212CD6C(level, unk_0384 != NULL ? unk_0384->vfunc_10() : 0x12, type), 0);
                        Point2D pos;
                        pos.x = enemy->m_motion.m_pos.x;
                        pos.y = enemy->m_motion.m_pos.y - (enemy->m_bobHeight + (enemy->unk_8C + enemy->m_jumpHeight));
                        if (unk_00D8->IsUnk194Flag80()) {
                            unk_00D8->ov1_0212CBA0(pos, 0x14, 0x4000);
                        } else if (enemy->m_flags & 0x1000) {
                            unk_00D8->ov1_0212C990(pos, 0x14, 0x4000, 0x7FFF);
                        } else {
                            unk_00D8->ov1_0212C7E8(pos, 0x14, 0x4000, 0x7FFF);
                        }
                        if (sub_02010B3C(unk_001C)) {
                            unk_0074 += unk_007C;
                        }
                        if (!enemy->IsAlive()) {
                            unk_002C += enemy->unk_184->unk_1C->unk_02;
                            captured++;
                            unk_0046[unk_0044] = enemy->unk_184->unk_16;
                            unk_0044++;
                            if (enemy->IsUnk2000()) {
                                enemy->ov1_0212677C(0xF0);
                            } else {
                                enemy->ov1_0212677C(captured * 6 + 0x78);
                            }
                            if (unk_00D8->unk_1C0->ov1_02137AD4() > unk_0056) {
                                unk_0056 = unk_00D8->unk_1C0->ov1_02137AD4();
                            }
                            if (unk_0044 == sub_02010B7C(unk_001C)) {
                                unk_00D8->ov1_0212C514(0);
                                if (unk_0384 != NULL) {
                                    unk_0384->vfunc_0C();
                                }
                                unk_00D8->vfunc_08();
                                m_game->m_audioEngine->sub_02034ED8(0);
                            }
                            UnkStruct_0212DFEC *param = enemy->unk_184->unk_1C;
                            Point2D gaugePos;
                            Point2D enemyPos = enemy->m_motion.GetPos();
                            gaugePos.x = enemyPos.x;
                            gaugePos.y = enemyPos.y + (param->unk_0F << 12);
                            unk_010C[i]->ov1_02135F2C(enemy->unk_188, gaugePos);
                            unk_010C[i]->vfunc_08();
                            int mode = sub_02016C14(&MAIN_BSS_020B26A0, 0x14);
                            u8 hp = unk_00D8->unk_19C;
                            switch (mode) {
                            case 0:
                                break;
                            case 1:
                                hp += 1;
                                break;
                            case 2:
                                hp += 3;
                                break;
                            }
                            if (hp >= MAIN_BSS_020B26A0.unk_0002) {
                                hp = MAIN_BSS_020B26A0.unk_0002;
                            }
                            unk_00D8->unk_19C = hp;
                            unk_0BB0->SetCurrentHP(hp);
                        }
                    }
                }
                if (unk_0384 != NULL && unk_0384->vfunc_10() == 0xF) {
                    CBattleAttackEffect *effect;
                    for (u8 i = 0; i < 0x60; i++) {
                        effect = unk_0130[i];
                        if (effect->HasData() && effect->IsUnk100Clear() && effect->unk_184->unk_18->unk_16 != 0
                            && unk_00D8->unk_1B8->ov1_02124650(effect->m_motion.m_pos.x, effect->m_motion.m_pos.y - (effect->m_bobHeight + (effect->unk_8C + effect->m_jumpHeight)))) {
                            effect->ov1_021272AC();
                        }
                    }
                }
                if (hits != 0) {
                    if (captured != 0) {
                        m_game->m_audioEngine->sub_02034C44(0x1F);
                    } else if (unk_003C > 5) {
                        m_game->m_audioEngine->sub_02034C44(0x1F);
                    } else {
                        m_game->m_audioEngine->sub_02034C44(unk_003C + 0x1A);
                    }
                    if (sub_02010B7C(unk_001C) >= 2 && hits == sub_02010B7C(unk_001C)) {
                        unk_000C |= 0x10000;
                    }
                    unk_0058++;
                } else {
                    m_game->m_audioEngine->sub_02034C44(0x3A);
                }
                PointPair2D first = unk_00D8->unk_1B8->m_lines2[0].m_points;
                unk_0BAC->ov1_0212EA1C(first.p1);
                for (u16 j = 0; j < unk_00D8->unk_1B8->m_lines2Count; j++) {
                    unk_0BAC->ov1_0212EA7C(unk_00D8->unk_1B8->m_lines2[j].GetStart());
                }
                unk_0BAC->ov1_0212EAD4();
            }
        }
    }
    unk_00D8->vfunc_08();
    unk_00D8->unk_254->ov1_02127EE4();
    unk_0BAC->ov1_0212E940();
}

void CBattleScene::ov1_02121184()
{
    if (unk_0044 == sub_02010B7C(unk_001C)) {
        return;
    }
    if (!unk_00D8->ov1_0212C4B8()) {
        return;
    }
    if (unk_0384 != NULL) {
        if (unk_0384->vfunc_08(unk_0010, unk_00D8, unk_00DC) == 0) {
            ov1_02122B90();
            m_game->unk_14BC->sub_0200E0E0(1, 0x20);
            m_game->unk_14C0->sub_0200E0E0(1, 0x20);
            unk_00D8->unk_19E = 0;
            unk_00D8->unk_1B8->ov1_02124DEC();
            unk_00D8->unk_1B8->ov1_02124AF4(unk_0030);
            unk_00D8->unk_190 = 0;
            m_game->m_audioEngine->sub_02034C44(0x13);
            unk_0384->vfunc_0C();
            SAFE_DELETE(unk_0384);
            unk_0C30->ov1_0213EF40(0);
            unk_0C30->ov1_0213EEB8();
            unk_0C30->ov1_0213EDDC();
        } else {
            u16 time = unk_0384->unk_04;
            if (time <= 300 && time % 60 == 0) {
                m_game->m_audioEngine->sub_02034C44(0x12);
            }
        }
    }
    for (u16 i = 0; i < 0x20; i++) {
        if (unk_02F8[i]->HasData()) {
            unk_02F8[i]->vfunc_08();
        }
    }
}

void CBattleScene::ov1_02121350()
{
    for (u8 i = 0; i < 8; i++) {
        CBattleEnemy *enemy = unk_00DC[i];
        if (enemy != NULL && enemy->HasData()) {
            UnkStruct_0212DFEC *param = enemy->unk_184->unk_1C;
            Point2D gaugePos;
            Point2D enemyPos = enemy->m_motion.GetPos();
            gaugePos.x = enemyPos.x;
            gaugePos.y = enemyPos.y + (param->unk_0F << 12);
            if (enemy->IsAlive()) {
                unk_010C[i]->ov1_02135F2C(enemy->unk_188, gaugePos);
            }
            int state = enemy->ov1_021267E8();
            enemy->vfunc_08();
            unk_010C[i]->vfunc_08();
            if (state == 0 && enemy->ov1_021267E8() == 1) {
                unk_0C30->ov1_0213EA2C(i);
                unk_0C30->ov1_0213EDDC();
            }
        }
    }
}

void CBattleScene::ov1_02121460()
{
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL && unk_00DC[i]->HasData()) {
            unk_00DC[i]->ov1_0212580C();
        }
    }
}

void CBattleScene::ov1_021214B4()
{
    for (u16 i = 0; i < 0x60; i++) {
        if (unk_0130[i] != NULL && unk_0130[i]->HasData()) {
            unk_0130[i]->vfunc_08();
        }
    }
}

void CBattleScene::ov1_02121514()
{
    for (u16 i = 0; i < 0x60; i++) {
        if (unk_0130[i] != NULL && unk_0130[i]->HasData()) {
            unk_0130[i]->ov1_02126F90();
        }
    }
}

void CBattleScene::ov1_0212156C()
{
    unk_0BA8->ov1_02136AEC();
}

void CBattleScene::ov1_0212157C()
{
    CBattleAttackEffect *effect;
    for (u16 i = 0; i < 0x60; i++) {
        effect = unk_0130[i];
        if (effect->HasData() && effect->unk_184->unk_18->unk_15 != 0) {
            if (!sub_02006000(effect->m_motion.m_pos, unk_12C8[0], 0)) {
                effect->ov1_02127300();
            } else if (!sub_02006000(effect->m_motion.m_pos, unk_12C8[1], 0)) {
                effect->ov1_02127300();
            }
        }
    }
    for (u8 j = 0; j < 0x20; j++) {
        effect = unk_02F8[j];
        if (effect->HasData() && effect->unk_184->unk_18->unk_15 != 0) {
            if (!sub_02006000(effect->m_motion.m_pos, unk_12C8[0], 0)) {
                effect->ov1_02127300();
            } else if (!sub_02006000(effect->m_motion.m_pos, unk_12C8[1], 0)) {
                effect->ov1_02127300();
            }
        }
    }
}

void CBattleScene::ov1_02121714()
{
    if (!unk_00D8->ov1_0212C4E4()) {
        return;
    }
    if (unk_00D8->ov1_0212C5D8()) {
        return;
    }
    if ((unk_0080 & 2) && unk_0081 < 12) {
        return;
    }
    if ((unk_0080 & 1) && unk_0081 < 12) {
        return;
    }
    ov1_02121774();
}

BOOL CBattleScene::ov1_02121774()
{
    Circle hit;
    for (u8 i = 0; i < 0x60; i++) {
        CBattleAttackEffect *effect = unk_0130[i];
        if (effect != NULL && effect->HasData() && effect->IsUnk100Clear()) {
            Circle circle = effect->m_sphere.m_circle;
            hit.pos.x = circle.pos.x;
            hit.r = circle.r;
            hit.pos.y = circle.pos.y - (effect->m_bobHeight + (effect->unk_8C + effect->m_jumpHeight));
            for (u16 j = 0; j < unk_00D8->ov1_0212C6C0() + 1; j++) {
                if (sub_02006100(unk_00D8->ov1_0212C670(unk_00D8->ov1_0212C6B0(j)), hit)) {
                    ov1_02122BE8();
                    unk_00D8->ov1_0212C514(0);
                    int result = unk_00D8->ov1_0212C33C(effect->unk_18E, effect->unk_184->unk_18->unk_0C);
                    unk_00D8->unk_25C->ov1_02128E34(hit.pos, result);
                    if (unk_0384 != NULL) {
                        unk_0384->vfunc_0C();
                    }
                    unk_00D8->ov1_0212C6D0(0x7FFF);
                    if (result != effect->unk_18E) {
                        unk_00D8->ShowHitEffect(hit.pos, 3);
                    } else {
                        unk_00D8->ShowHitEffect(hit.pos, 1);
                    }
                    if (result != 0) {
                        m_game->m_audioEngine->sub_02034C44(0x25);
                    } else {
                        m_game->m_audioEngine->sub_02034C44(0xF);
                    }
                    m_game->m_audioEngine->sub_02034C5C(0xB);
                    unk_0038++;
                    if (effect->unk_184->unk_18->unk_13 != 0) {
                        effect->ov1_02127300();
                    }
                    return TRUE;
                }
            }
        }
    }
    for (u8 i = 0; i < 8; i++) {
        CBattleEnemy *enemy = unk_00DC[i];
        if (enemy != NULL && enemy->IsAlive() && enemy->IsTargetable()) {
            Circle circle = enemy->m_sphere.m_circle;
            hit.pos.x = circle.pos.x;
            hit.pos.y = circle.pos.y;
            hit.r = circle.r;
            for (u16 j = 0; j < unk_00D8->ov1_0212C6C0() + 1; j++) {
                if (sub_02006100(unk_00D8->ov1_0212C670(unk_00D8->ov1_0212C6B0(j)), hit)) {
                    unk_00D8->ov1_0212C6D0(0x7FFF);
                    ov1_02122BE8();
                    unk_00D8->ov1_0212C514(0);
                    if (unk_0384 != NULL) {
                        unk_0384->vfunc_0C();
                    }
                    m_game->m_audioEngine->sub_02034C44(0x28);
                    m_game->m_audioEngine->sub_02034C5C(0xB);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void CBattleScene::func1()
{
    unk_00C4->sub_020037B4();
    unk_00C4->sub_0200381C();
    G3_StoreMtx(0);
    int z = ov1_02121DB0(unk_00C4, -0x3FF);
    ov1_021222E8(unk_00C4, z);
    z = 2;
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL && unk_00DC[i]->HasData()) {
            z = unk_00DC[i]->ov1_02125E00(unk_00C4, z);
        }
    }
    z = ov1_021220B4(unk_00C4, z);
    unk_00D0->SetZ(z + 3, z + 3, z + 3);
    unk_00D0->Render(unk_00C4);
    switch (unk_0024) {
    case 0:
        ov1_02121D78(unk_00C4, z + 3);
        break;
    case 1:
        ov1_02121D80(unk_00C4, z + 3);
        break;
    case 3:
    case 4:
        ov1_02122010(unk_00C4, z + 3);
        break;
    case 5:
        ov1_02122018(unk_00C4, z + 3);
        break;
    case 7:
        ov1_02122044(unk_00C4, z + 3);
        break;
    case 6:
        ov1_02122074(unk_00C4, z + 3);
        break;
    case 9:
        ov1_021220AC(unk_00C4, z + 3);
        break;
    }
    u16 subZ = unk_0BB0->SetZ(0x3AC);
    unk_0BB0->vfunc_0C(unk_00C8);
    if (sub_02010BE0(unk_001C)) {
        subZ = unk_0C08->ov1_021382A4(subZ);
        unk_0C08->ov1_02138268(unk_00C8);
    }
    if (sub_02010BF4(unk_001C)) {
        subZ = unk_0C0C->ov1_021384CC(subZ);
        unk_0C0C->ov1_02138490(unk_00C8);
    }
}

void CBattleScene::func2()
{
    if (unk_005D != 0) {
        unk_0C34->Render();
    } else {
        unk_0C30->ov1_0213E728();
    }
}

int CBattleScene::ov1_02121D78(Camera2D *camera, int z)
{
    return z;
}

int CBattleScene::ov1_02121D80(Camera2D *camera, int z)
{
    int result = unk_0C10->ov1_0213F970(z);
    unk_0C10->ov1_0213F82C(camera);
    return result;
}

int CBattleScene::ov1_02121DB0(Camera2D *camera, int z)
{
    for (u8 i = 0; i < 8; i++) {
        unk_0BC4[i]->ov1_02137EE8();
    }
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL && unk_00DC[i]->HasData()) {
            unk_0BC4[4]->ov1_02137DF8(unk_00DC[i]);
        }
    }
    for (u8 i = 0; i < 0x60; i++) {
        if (unk_0130[i]->HasData()) {
            unk_0BC4[unk_0130[i]->unk_184->unk_18->unk_08]->ov1_02137DF8(unk_0130[i]);
        }
    }
    for (u8 i = 0; i < 0x20; i++) {
        if (unk_02F8[i]->HasData()) {
            unk_0BC4[unk_02F8[i]->unk_184->unk_18->unk_08]->ov1_02137DF8(unk_02F8[i]);
        }
    }
    z = sub_0204240C(unk_00D4, z);
    sub_020423F4(unk_00D4, unk_00C4);
    unk_0BC4[7]->unk_0C = z;
    unk_0BC4[6]->unk_0C = unk_0BC4[7]->ov1_02137F28(unk_00C4);
    z = unk_0BC4[6]->ov1_02137F28(unk_00C4);
    z = ov1_0212233C(unk_00C4, z);
    z = unk_0BAC->ov1_0212EDB4(z);
    unk_0BAC->ov1_0212E998(unk_00C4);
    z = unk_00D8->ov1_0212D124(z);
    unk_00D8->ov1_0212C00C(unk_00C4);
    unk_0BC4[5]->unk_0C = z;
    unk_0BC4[4]->unk_0C = unk_0BC4[5]->ov1_02137F28(unk_00C4);
    z = unk_0BC4[4]->ov1_02137F28(unk_00C4);
    z = unk_00D8->ov1_0212D0D4(z);
    unk_00D8->vfunc_0C(unk_00C4);
    unk_0BC4[3]->unk_0C = z;
    unk_0BC4[2]->unk_0C = unk_0BC4[3]->ov1_02137F28(unk_00C4);
    unk_0BC4[1]->unk_0C = unk_0BC4[2]->ov1_02137F28(unk_00C4);
    unk_0BC4[0]->unk_0C = unk_0BC4[1]->ov1_02137F28(unk_00C4);
    z = unk_0BC4[0]->ov1_02137F28(unk_00C4);
    unk_0BA8->ov1_02136B88(unk_00C4);
    return z;
}

int CBattleScene::ov1_02122010(Camera2D *camera, int z)
{
    return z;
}

int CBattleScene::ov1_02122018(Camera2D *camera, int z)
{
    int result = unk_0BC0->ov1_0213C67C(z);
    unk_0BC0->ov1_0213BFFC(unk_00C4);
    return result;
}

int CBattleScene::ov1_02122044(Camera2D *camera, int z)
{
    int result = unk_0BB8->ov1_02139CE4(z);
    unk_0BB8->ov1_021399A8(camera);
    return result;
}

int CBattleScene::ov1_02122074(Camera2D *camera, int z)
{
    int result = unk_0BBC->ov1_0213AA90(z);
    unk_0BBC->vfunc_0C(camera);
    return result;
}

int CBattleScene::ov1_021220AC(Camera2D *camera, int z)
{
    return z;
}

int CBattleScene::ov1_021220B4(Camera2D *camera, int z)
{
    G3_Identity();
    unk_00C8->sub_020037B4();
    unk_00C8->sub_0200381C();
    G3_StoreMtx(0);
    if (unk_0070 != 0) {
        if (sub_02010C08(unk_001C)) {
            CBattleEnemy *enemy = unk_00DC[0];
            if (enemy != NULL) {
                if (enemy->HasData()) {
                    unk_010C[0]->ov1_02135E70(8, enemy->unk_188, enemy->unk_184->unk_1C->unk_00, DAT_overlay_1_0213fb68);
                    unk_010C[0]->vfunc_08();
                }
                z = unk_010C[0]->ov1_02136248(z);
                unk_010C[0]->vfunc_0C(unk_00C8);
            }
            for (u8 i = 1; i < 8; i++) {
                if (unk_00DC[i] != NULL && unk_00DC[i]->HasData() && unk_00DC[i]->unk_108.value == 0x1F && unk_00DC[i]->IsUnk400Clear()) {
                    z = unk_010C[i]->ov1_02136248(z);
                    unk_010C[i]->vfunc_0C(unk_00C8);
                }
            }
        } else {
            for (u8 i = 0; i < 8; i++) {
                if (unk_00DC[i] != NULL && unk_00DC[i]->HasData() && unk_00DC[i]->unk_108.value == 0x1F && unk_00DC[i]->IsUnk400Clear()) {
                    z = unk_010C[i]->ov1_02136248(z);
                    unk_010C[i]->vfunc_0C(unk_00C8);
                }
            }
        }
    }
    return z;
}

int CBattleScene::ov1_021222E8(Camera2D *camera, int z)
{
    G3_Identity();
    unk_00C4->SetOffset(0, 0);
    unk_00C4->sub_020037B4();
    unk_00C4->sub_0200381C();
    if (unk_0C2C != NULL) {
        unk_0C2C->sub_020358AC(unk_00C4);
    }
    return z;
}

int CBattleScene::ov1_0212233C(Camera2D *camera, int z)
{
    CBattleEnemy *enemy;
    for (u8 i = 0; i < 8; i++) {
        enemy = unk_00DC[i];
        if (enemy != NULL && enemy->HasData() && enemy->IsUnk800Clear() && (enemy->unk_8C + enemy->m_jumpHeight) + enemy->m_bobHeight <= FX32_CONST(96)) {
            Rectangle shadow = enemy->GetShadowRect();
            if (shadow.size.x != 0 && shadow.size.y != 0) {
                fx32 scale = LinearInterpolate(FX32_ONE, 0, (enemy->unk_8C + enemy->m_jumpHeight) + enemy->m_bobHeight, FX32_CONST(96));
                shadow.size.x = FX32_MUL(shadow.size.x, scale);
                shadow.size.y = FX32_MUL(shadow.size.y, scale);
                unk_0C28->SetRectangle(&shadow, z);
                unk_0C28->Render(unk_00C4);
            }
        }
    }
    CBattleAttackEffect *effect;
    for (u8 i = 0; i < 0x60; i++) {
        effect = unk_0130[i];
        if (effect->HasData() && effect->IsUnk200Clear()) {
            UnkStruct_0212E008 *entry = effect->unk_184->unk_18;
            if (entry->unk_17 != 0 && (effect->unk_8C + effect->m_jumpHeight) + effect->m_bobHeight <= FX32_CONST(96)) {
                Rectangle shadow = entry->GetShadowRect();
                shadow.pos.x += effect->m_motion.m_pos.x;
                shadow.pos.y += effect->m_motion.m_pos.y;
                fx32 scale = LinearInterpolate(FX32_ONE, 0, (effect->unk_8C + effect->m_jumpHeight) + effect->m_bobHeight, FX32_CONST(96));
                shadow.size.x = FX32_MUL(shadow.size.x, scale);
                shadow.size.y = FX32_MUL(shadow.size.y, scale);
                unk_0C28->SetRectangle(&shadow, z);
                unk_0C28->Render(unk_00C4);
            }
        }
    }
    for (u8 i = 0; i < 0x20; i++) {
        CBattleAttackEffect *effect = unk_02F8[i];
        if (effect->HasData()) {
            UnkStruct_0212E008 *entry = effect->unk_184->unk_18;
            if (entry->unk_17 != 0 && effect->unk_108.value == 0x1F && (effect->unk_8C + effect->m_jumpHeight) + effect->m_bobHeight <= FX32_CONST(96)) {
                Rectangle shadow = entry->GetShadowRect();
                shadow.pos.x += effect->m_motion.m_pos.x;
                shadow.pos.y += effect->m_motion.m_pos.y;
                fx32 scale = LinearInterpolate(FX32_ONE, 0, (effect->unk_8C + effect->m_jumpHeight) + effect->m_bobHeight, FX32_CONST(96));
                shadow.size.x = FX32_MUL(shadow.size.x, scale);
                shadow.size.y = FX32_MUL(shadow.size.y, scale);
                unk_0C28->SetRectangle(&shadow, z);
                unk_0C28->Render(unk_00C4);
            }
        }
    }
    return z + 1;
}

int CBattleScene::ov1_02122728(u32 id)
{
    if (id >= 1 && id < 9) {
        return 1;
    }
    if (id >= 9 && id < 0x89) {
        return 2;
    }
    return id == 0 ? 0 : 3;
}

CBattleEnemy *CBattleScene::ov1_02122760(u32 id)
{
    if (id >= 1 && id < 9) {
        u32 idx = id - 1;
        return unk_00DC[idx];
    }
    return NULL;
}

CBattleAttackEffect *CBattleScene::ov1_02122788(u32 id)
{
    if (id >= 9 && id < 0x89) {
        u32 idx = id - 9;
        return unk_0130[idx];
    }
    return NULL;
}

CBattleAttackEffectData *CBattleScene::ov1_021227B0(u32 idx)
{
    if (idx >= 0x12) {
        return NULL;
    }
    return unk_02B0[idx];
}

UnkClass_0200D3F8 *CBattleScene::ov1_021227C4()
{
    return unk_00CC;
}

void CBattleScene::ov1_021227CC(int result)
{
    CGame::GetInstance()->m_audioEngine->sub_0203491C();
    CBattleResultParameter *res = m_game->unk_1444;
    res->unk_08 = result;
    res->unk_10 = unk_0074;
    for (u8 i = 0; i < 8; i++) {
        res->unk_6D[i] = unk_009A[i];
    }
    res->unk_78 = unk_00D8->unk_1B8->unk_54C8 << 3;
    res->unk_7C = unk_0058;
    if ((u32)(result - 1) <= 2) {
        unk_0018 = result;
        u8 hp = unk_0BB0->m_hp;
        unk_00D8->unk_19C = hp;
        res->unk_04 = hp;
        res->unk_58 = 0;
        m_game->unk_14BC->sub_0200E0E0(4, 0x40);
        m_game->unk_14C0->sub_0200E0E0(4, 0x40);
        unk_0020 = 8;
        return;
    }
    unk_0BB8->unk_00A = unk_002C;
    res->unk_58 = unk_0044;
    for (u8 i = 0; i < unk_0044; i++) {
        res->unk_5A[i] = unk_0046[i];
    }
    if (unk_0044 != 0) {
        if (unk_0034 == 1) {
            unk_000C |= 0x80;
        }
        if (result != 2) {
            if (unk_0038 == 0) {
                switch (sub_02010C1C(unk_001C)) {
                case 0:
                    unk_000C |= 0x400;
                    res->unk_6B = 1;
                    break;
                case 1:
                    unk_000C |= 0x800;
                    res->unk_6B = 2;
                    break;
                case 2:
                default:
                    unk_000C |= 0x1000;
                    res->unk_6B = 2;
                    break;
                }
            } else {
                res->unk_6B = 0;
            }
        } else {
            res->unk_6B = sub_02010C1C(unk_001C);
        }
        if (unk_0028 <= 600) {
            unk_000C |= 1;
        }
        if (unk_0028 <= 180) {
            unk_000C |= 2;
        }
        if (unk_0BB0->GetHPLevel() == 2) {
            unk_000C |= 0x8000;
        }
        if (unk_0058 >= 100) {
            unk_000C |= 0x4000;
        } else if (unk_0058 >= 50) {
            unk_000C |= 0x2000;
        }
        if (sub_02010C08(unk_001C)) {
            unk_000C |= 4;
        }
        if (unk_00D8->unk_1B8->unk_54C8 << 3 >= 100000) {
            unk_000C |= 0x10;
        }
        if (unk_0056 == 1) {
            unk_000C |= 0x100;
        } else if (unk_0056 == 2) {
            unk_000C |= 0x200;
        }
        ov1_02122DB4();
    }
    unk_0BB8->unk_028 = unk_000C;
    if (result == 0) {
        m_game->m_audioEngine->sub_02034A40(3, 0);
        unk_006C = 0;
        unk_0020 = 10;
    } else if (unk_005C != 0) {
        if (sub_02010B24(unk_001C) == 0x23) {
            unk_0BB8->ov1_02139C30(unk_00D8, unk_0BB0);
            if (!unk_00D0->IsOpen()) {
                unk_00D0->Open();
            }
            unk_0020 = 7;
        } else {
            unk_0020 = 9;
        }
    } else {
        unk_0BB8->ov1_02139C30(unk_00D8, unk_0BB0);
        if (!unk_00D0->IsOpen()) {
            unk_00D0->Open();
        }
        unk_0020 = 7;
    }
    unk_0018 = result;
}

void CBattleScene::ov1_02122B70()
{
    ov1_02122BE8();
    unk_0BBC->ov1_0213AC30();
    unk_0020 = 6;
}

void CBattleScene::ov1_02122B90()
{
    for (u16 i = 0; i < 0x20; i++) {
        if (unk_02F8[i] != NULL && unk_02F8[i]->HasData()) {
            unk_02F8[i]->ov1_02127300();
        }
    }
}

void CBattleScene::ov1_02122BE8()
{
    Point2D first = unk_00D8->ov1_0212C670(0);
    unk_0BAC->ov1_0212EA1C(first);
    for (u16 i = 0; i < (u32)unk_00D8->ov1_0212C6C0(); i++) {
        Point2D pos = unk_00D8->ov1_0212C690(unk_00D8->ov1_0212C6B0(i));
        unk_0BAC->ov1_0212EA7C(pos);
    }
    unk_0BAC->ov1_0212E940();
}

void CBattleScene::ov1_02122CA4(u8 index)
{
    SAFE_DELETE(unk_0388[index]);
    for (; index < 7; index++) {
        unk_0082[index] = unk_0082[index + 1];
        unk_0092[index] = unk_0092[index + 1];
        unk_0388[index] = unk_0388[index + 1];
        unk_00A4[index] = unk_00A4[index + 1];
    }
    unk_0082[7] = 0;
    unk_0092[7] = 0;
    unk_0388[7] = NULL;
    unk_00A4[7] = NULL;
}

int CBattleScene::ov1_02122D3C(u8 arg0)
{
    switch (arg0) {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 4;
    }
    return 1;
}

void CBattleScene::ov1_02122D78(int arg0)
{
    if (arg0) {
        CGame::GetInstance()->sub_02010178(0);
    } else {
        CGame::GetInstance()->sub_02010178(1);
    }
    unk_0010 = CGame::GetInstance()->activeTouchPanel;
}

static inline void SetCaptureCount(UnkClass_020B26A0 *save, u16 id, int count)
{
    if (count <= 0) {
        save->unk_7CBC[id] = 0;
    } else if (count >= 0xFF) {
        save->unk_7CBC[id] = 0xFF;
    } else {
        save->unk_7CBC[id] = count;
    }
}

void CBattleScene::ov1_02122DB4()
{
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    u16 ids[4];
    u8 counts[4];
    MI_CpuFill8(ids, 0, sizeof(ids));
    MI_CpuFill8(counts, 0, sizeof(counts));
    for (u8 i = 0; i < sub_02010B68(unk_001C); i++) {
        u16 id = sub_020107A8(unk_0C14, sub_02010B70(unk_001C, i))->unk_00;
        ids[i] = id;
        counts[i] = save->unk_7CBC[id];
    }
    for (u8 i = 0; i < sub_02010B68(unk_001C); i++) {
        for (u8 j = 0; j < unk_0044; j++) {
            u16 id = ids[i];
            if (id == sub_020107A8(unk_0C14, unk_0046[j])->unk_00) {
                SetCaptureCount(save, id, save->unk_7CBC[id] + 1);
            }
        }
    }
    unk_005C = 0;
    unk_005D = 0;
    unk_0068 = 0;
    MI_CpuFill8(unk_005E, 0, 8);
    for (u8 i = 0; i < sub_02010B68(unk_001C); i++) {
        u16 id = ids[i];
        u8 before = counts[i];
        u8 after = save->unk_7CBC[id];
        if (before == 0 && after != 0) {
            unk_005E[unk_005C] = id;
            unk_005C++;
        } else if (before < 10 && after >= 10) {
            unk_000C |= 0x20;
        } else if (before < 100 && after >= 100) {
            unk_000C |= 0x40;
        }
    }
    for (u8 i = 0; i < sub_02010B68(unk_001C); i++) {
        SetCaptureCount(save, ids[i], counts[i]);
    }
}

u32 CBattleScene::getSceneId()
{
    return 0;
}
