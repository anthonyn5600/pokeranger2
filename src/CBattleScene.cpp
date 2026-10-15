#include "scene/CBattleScene.hpp"

#include "AudioEngine.hpp"
#include "BGFontPrinter.hpp"
#include "BattleShadow.hpp"
#include "BattleStartParam.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "Camera2D.hpp"
#include "CameraController.hpp"
#include "CaptureBackground.hpp"
#include "DiskHPTable.hpp"
#include "FieldScreenEffectManage.hpp"
#include "FontSet.hpp"
#include "FrameTimer.hpp"
#include "GridOverlay.hpp"
#include "MathUtil.hpp"
#include "OamSpriteSet.hpp"
#include "PokeIdTableEntry.hpp"
#include "SaveData.hpp"
#include "ScriptManager.hpp"
#include "SubScreenPokemonInfo.hpp"
#include "TextboxManager.hpp"
#include "battle/BattleAssistButton.hpp"
#include "battle/BattleAssistMenu.hpp"
#include "battle/BattleDamageNumber.hpp"
#include "battle/BattleDebugMenu.hpp"
#include "battle/BattleEffectTable.hpp"
#include "battle/BattleEffectivenessMark.hpp"
#include "battle/BattleEffectivenessMarkGfx.hpp"
#include "battle/BattleEnemyGaugeGfx.hpp"
#include "battle/BattleEscapeButton.hpp"
#include "battle/BattleHPNumber.hpp"
#include "battle/BattleHPNumberGfx.hpp"
#include "battle/BattleHitEffect.hpp"
#include "battle/BattleInfoPanel.hpp"
#include "battle/BattleParamTable.hpp"
#include "battle/BattleParticle.hpp"
#include "battle/BattleParticlePool.hpp"
#include "battle/BattlePokemonParam.hpp"
#include "battle/BattlePokemonTable.hpp"
#include "battle/BattleResult.hpp"
#include "battle/BattleStatusDebug.hpp"
#include "battle/BattleStatusDebugGfx.hpp"
#include "battle/BattleStatusIcon.hpp"
#include "battle/BattleStatusIconGfx.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/CBattleEnemyGauge.hpp"
#include "battle/CBattleGameOver.hpp"
#include "battle/CBattlePowerSave.hpp"
#include "battle/CaptureEffect.hpp"
#include "battle/CaptureLineTrail.hpp"
#include "battle/CaptureMark.hpp"
#include "battle/CaptureResultBanner.hpp"
#include "battle/StylerLine.hpp"
#include "battle/UnkClass_021274AC.hpp"
#include "battle/UnkClass_0212770C.hpp"
#include "battle/UnkClass_021278E8.hpp"
#include "battle/UnkClass_02127B48.hpp"
#include "battle/UnkClass_021297C0.hpp"
#include "battle/UnkClass_02129B74.hpp"
#include "battle/YSortedActorList.hpp"
#include "file/CBinaryFile.hpp"
#include "interpolation.hpp"
#include "primitive/CPrimitiveRECT.hpp"

static inline u32 GetPokemonState(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->m_pokemonStates[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline int CountPokemon(SaveData *save)
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
    game->unk_146C.SetFps(60);

    for (i = 0; i < BattleStartParam_GetPartyCount(unk_001C); i++) {
        unk_0082[i] = BattleStartParam_GetPartyId(unk_001C, i);
    }
    for (; i < 8; i++) {
        unk_0082[i] = 0;
    }
    for (i = 0; i < BattleStartParam_GetPartyCount(unk_001C); i++) {
        if (BattleStartParam_GetPartyFlags(unk_001C, i)) {
            unk_0092[i] = TRUE;
        } else {
            unk_0092[i] = FALSE;
        }
    }
    for (i = 0; i < 8; i++) {
        unk_009A[i] = 0;
        unk_00A4[i] = &unk_009A[i];
    }

    if (BattleStartParam_GetNextScene(unk_001C) == 0x23) {
        MAIN_BSS_020B26A0.m_levelExp = 0;
        SaveData_SetStylerLevel(&MAIN_BSS_020B26A0, BattleStartParam_GetStylerLevel(unk_001C));
    }

    unk_0074 = BattleStartParam_GetPartnerEnergy(unk_001C);
    unk_0078 = BattleStartParam_GetPartnerMaxEnergy(unk_001C);
    unk_007C = DAT_overlay_1_0213fb70[(u8)BattleStartParam_GetPartnerMood(unk_001C)];
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

    m_game->m_textboxData->Init(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->m_nameTables, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);
    m_game->m_textboxData->LoadSystemMessages(1);
    ScriptManager_LoadSystem(m_game->m_scriptManager, 1);

    if (BattleStartParam_GetEnemyCount(unk_001C) == 1) {
        game->m_textboxData->SetParam(0, PokeIdTable_Get(unk_0C14, BattleStartParam_GetPokemonId(unk_001C, 0))->unk_00);
    } else {
        game->m_textboxData->SetParam(0, 0x1EF);
    }
    TextboxManager *textbox = game->m_textboxData;
    textbox->SetParam(1, sub_02010C2C(unk_001C));
    if (BattleStartParam_GetEnemyCount(unk_001C) == 1) {
        game->m_textboxData->SetParam(2, 9);
    } else {
        game->m_textboxData->SetParam(2, 10);
    }
    game->m_mainFade->Start(1, 0x20);
    game->m_subFade->Start(1, 0x20);
}

CBattleScene::~CBattleScene()
{
    m_game->m_audioEngine->StopBgm(1);
    SelectTouchPanel(1);
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    m_game->unk_146C.SetFps(30);
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

extern ScriptSyscall gBattleSyscalls[];

void CBattleScene::func6()
{
    u32 offset;
    u16 id;
    u8 j4;
    PokeIdTable *table;
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    Script_RegisterSyscalls(1, gBattleSyscalls);
    m_game->m_audioEngine->LoadBattleSe();

    unk_0C18 = new BattlePokemonTable(m_game->unk_14A8);
    unk_0C1C = new BattleEffectTable(m_game->unk_14A8);
    unk_0C20 = new BattleParamTable("data/param/BattleAssist.bin", m_game->unk_14A8);
    unk_0C24 = new BattleParamTable("data/param/BattleAssistPartner.bin", m_game->unk_14A8);
    unk_00C4 = new Camera2D();
    unk_00C8 = new Camera2D();
    unk_00CC = new CameraController((UnkStruct_0200D3F8_Target *)unk_00C4);
    unk_00C4->SetOrtho(0, FX32_CONST(192), 0, FX32_CONST(256), FX32_CONST(-2048), FX32_CONST(2047), FX32_CONST(1024));
    unk_00C8->SetOrtho(0, FX32_CONST(192), 0, FX32_CONST(256), FX32_CONST(-2048), FX32_CONST(2048), FX32_CONST(1024));
    unk_00D0 = new GridOverlay();
    unk_00D0->SetZ(0x410, 0x411, 0x412);
    unk_00D0->SetPolygonID(0x3A, 0x3B, 0x3C);

    for (int i = 0; i < 0x200; i++) {
        unk_03A8[i] = new BattleParticle();
    }
    unk_0BA8 = new BattleParticlePool(unk_03A8, 0x200);
    unk_0BA8->SetPolygonId(1);

    unk_00D8 = new CBattleDisk(unk_0BA8);
    unk_00D8->unk_19C = BattleStartParam_GetEnergy(unk_001C);
    unk_0030 = 0x3B;
    switch (SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_LONGLINE)) {
    case 0:
        break;
    case 1:
        unk_0030 += 2;
        break;
    case 2:
        unk_0030 += 4;
        break;
    }
    unk_00D8->unk_1B8->SetMaxCount(unk_0030);

    if ((u32)((MAIN_BSS_020B26A0.m_rangerClassGrade >> 4) & 0xF) < 2) {
        unk_00D8->unk_18C = 0;
    } else {
        unk_00D8->unk_18C = 1;
        unk_00D8->unk_190 = 0;
    }
    if ((u32)(MAIN_BSS_020B26A0.m_rangerClassGrade & 0xF) >= 8) {
        unk_00D8->unk_1C0->m_maxLevel = 2;
    } else {
        unk_00D8->unk_1C0->m_maxLevel = 1;
    }
    if ((u32)(MAIN_BSS_020B26A0.m_rangerClassGrade & 0xF) >= 6) {
        unk_00D8->unk_1C0->SetChargeTimes(70, 90);
    } else {
        unk_00D8->unk_1C0->SetChargeTimes(100, 120);
    }

    table = m_game->unk_1434;
    for (u8 j1 = 0; j1 < BattleStartParam_GetPokemonCount(unk_001C); j1++) {
        id = BattleStartParam_GetPokemonId(unk_001C, j1);
        if (id != 0xFFFF) {
            unk_00FC[j1] = new CBattleEnemyData(id, PokeIdTable_Get(table, id), unk_0C18->GetEntry(id), m_game->unk_14A8);
        }
    }
    for (u8 j2 = 0; j2 < BattleStartParam_GetEnemyCount(unk_001C); j2++) {
        if (BattleStartParam_GetEnemySlot(unk_001C, j2) != 0xFF) {
            unk_00DC[j2] = new CBattleEnemy(j2 + 1, unk_00FC[BattleStartParam_GetEnemySlot(unk_001C, j2)]);
            unk_00DC[j2]->InitScript();
            unk_00DC[j2]->m_flags |= 0x100;
            if (sub_02010C08(unk_001C)) {
                unk_00DC[j2]->ov1_02126764(1);
            }
        }
    }
    for (u8 j3 = 0; j3 < BattleStartParam_GetEnemyCount(unk_001C); j3++) {
        if (unk_00DC[j3] != NULL) {
            unk_002E += unk_00DC[j3]->unk_184->unk_1C->unk_02;
        }
    }

    char name[0x60];
    offset = 0;
    for (j4 = 0; j4 < BattleStartParam_GetPartyCount(unk_001C); j4++) {
        if (BattleStartParam_GetPartyId(unk_001C, j4) != 0xFF) {
            id = BattleStartParam_GetPartyId(unk_001C, j4);
            unk_0388[j4] = new OamSpriteSet((GXOamAttr *)CGame::GetInstance()->unk_0024, 0, FALSE, 0x40);
            OS_SPrintf(name, "bp%03d", PokeIdTable_Get(table, id)->unk_00);
            unk_0388[j4]->Load("data/pokeOBJ", name, offset, (u32)j4 + 8);
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
        unk_0BC4[i] = new YSortedActorList();
        unk_0BC4[i]->m_z = i * -0x80;
    }
    unk_0BAC = new CaptureLineTrail();
    unk_0C28 = new BattleShadow();
    unk_0C28->SetPolygonID(0x3F);
    unk_0C28->SetAlpha(8);
    unk_012C = new BattleEnemyGaugeGfx();

    for (int i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL) {
            unk_010C[i] = new CBattleEnemyGauge(unk_012C);
            CBattleEnemy *enemy = unk_00DC[i];
            BattlePokemonParam *param = enemy->unk_184->unk_1C;
            Point2D pos;
            pos.x = enemy->m_motion.m_pos.x;
            pos.y = enemy->m_motion.m_pos.y + (param->unk_0F << 12);
            unk_010C[i]->Setup(ov1_02122D3C(param->unk_0E), enemy->unk_188, param->unk_00, pos);
        }
    }

    unk_0BE8 = new UnkClass_02129B74();
    unk_0BEC = new UnkClass_021297C0();
    unk_0BF0 = new UnkClass_021278E8();
    unk_0BF4 = new UnkClass_021274AC();
    unk_0BF8 = new BattleEffectivenessMarkGfx();
    unk_0BFC = new BattleHPNumberGfx();
    unk_0C00 = new BattleStatusIconGfx();
    unk_0C04 = new BattleStatusDebugGfx();
    for (int i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL) {
            unk_00DC[i]->unk_198->SetData(unk_0BE8);
            unk_00DC[i]->unk_19C->SetData(unk_0BEC);
            unk_00DC[i]->unk_1A0->SetData(unk_0BF0);
            unk_00DC[i]->unk_1A4->SetData(unk_0BF4);
            unk_00DC[i]->unk_1A8->SetData(unk_0BF8);
            unk_00DC[i]->unk_1AC->SetData(unk_0BFC);
            unk_00DC[i]->unk_1B0->SetData(unk_0C00);
            unk_00DC[i]->unk_1B4->SetData(unk_0C04);
            unk_00DC[i]->unk_1B8 = unk_010C[i];
            unk_00DC[i]->unk_1BC = unk_0BA8;
        }
    }

    unk_0C10 = new CaptureResultBanner(BattleStartParam_GetBannerType(unk_001C));
    u8 hp;
    u8 maxHP;
    maxHP = MAIN_BSS_020B26A0.m_maxEnergy;
    hp = BattleStartParam_GetEnergy(unk_001C);
    unk_0BB0 = new CPlayerHPGauge();
    unk_0BB0->SetVisible(TRUE);
    unk_0BB0->SetHP(hp, maxHP);
    if (BattleStartParam_HasPartner(unk_001C)) {
        unk_0BB0->SetPartnerVisible(TRUE);
        unk_0BB0->SetPartner(unk_0074 >> 12, unk_0078 >> 12);
    } else {
        unk_0BB0->SetPartnerVisible(FALSE);
    }
    unk_0C08 = new BattleAssistButton();
    unk_0C0C = new BattleEscapeButton();
    unk_0C2C = new FieldScreenEffectManage();
    unk_0C2C->SetPrimaryEffect(BattleStartParam_GetScreenEffect(unk_001C));
    unk_0C2C->StartEffect(BattleStartParam_GetScreenEffect(unk_001C), 0, -1, 0);
    unk_0BBC = new CBattleGameOver(m_game, unk_00D8, unk_0BB0);
    unk_0BB8 = new BattleResult();
    unk_0BB8->SetZ(0x500);
    unk_0C30 = new BattleInfoPanel(m_game);
    unk_0C30->SetListVisible(1);
    unk_0C30->SetPokemonCount(BattleStartParam_GetEnemyCount(unk_001C));
    for (u8 j6 = 0; j6 < BattleStartParam_GetEnemyCount(unk_001C); j6++) {
        PokeIdTableEntry *info = PokeIdTable_Get(table, BattleStartParam_GetPokemonId(unk_001C, BattleStartParam_GetEnemySlot(unk_001C, j6)));
        unk_0C30->SetPokemonSpecies(info->unk_00, j6);
        unk_0C30->SetPokemonType(info->unk_03, j6);
    }
    unk_0C34 = new SubScreenPokemonInfo();
    unk_0BC0 = new BattleAssistMenu(table, unk_0C18, unk_0C30, unk_00D0);
    unk_00D4 = new CaptureBackground(BattleStartParam_GetCaptureBg(unk_001C));
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x3800, GX_BG_CHARBASE_0x00000);
    CGame::GetInstance()->unk_0C24->Init(3, 0x2000, 0, 0);
    unk_0C40 = new BattleDebugMenu(m_game);

    char sequence[0x60];
    OS_SPrintf(sequence, "data/script/battle/sequence/s%03d.fsb", BattleStartParam_GetSequenceScript(unk_001C));
    unk_0C44[0].file = new CBinaryFile(sequence, 0, 0, 0, NULL, 0);
    unk_0C44[0].data = unk_0C44[0].file->unk_4C;
    Script_Link(unk_0C44[0].data);
    ScriptVM_Init(&unk_0C44[0].vm, unk_0C44[0].stack, 0x80);
    u32 *top = unk_0C44[0].vm.unk_04 -= 2;
    top[0] = 1;
    top[1] = BattleStartParam_GetEnemyCount(unk_001C);
    ScriptVM_CallFunction(&unk_0C44[0].vm, unk_0C44[0].data, "initialize", 2);
    ScriptVM_Start(&unk_0C44[0].vm, unk_0C44[0].data, "proc");

    char tutorial[0x60];
    OS_SPrintf(tutorial, "data/script/battle/tutorial/t%03d.fsb", BattleStartParam_GetTutorialScript(unk_001C));
    unk_0C44[1].file = new CBinaryFile(tutorial, 0, 0, 0, NULL, 0);
    unk_0C44[1].data = unk_0C44[1].file->unk_4C;
    Script_Link(unk_0C44[1].data);
    ScriptVM_Init(&unk_0C44[1].vm, unk_0C44[1].stack, 0x80);
    top = unk_0C44[1].vm.unk_04 -= 2;
    top[0] = 1;
    top[1] = BattleStartParam_GetEnemyCount(unk_001C);
    ScriptVM_CallFunction(&unk_0C44[1].vm, unk_0C44[1].data, "initialize", 2);
    ScriptVM_Start(&unk_0C44[1].vm, unk_0C44[1].data, "proc");

    char start[0x60];
    OS_SPrintf(start, "data/script/battle/start/s%03d.fsb", BattleStartParam_GetStartScript(unk_001C));
    unk_0C44[2].file = new CBinaryFile(start, 0, 0, 0, NULL, 0);
    unk_0C44[2].data = unk_0C44[2].file->unk_4C;
    Script_Link(unk_0C44[2].data);
    ScriptVM_Init(&unk_0C44[2].vm, unk_0C44[2].stack, 0x80);
    top = unk_0C44[2].vm.unk_04 -= 2;
    top[0] = 1;
    top[1] = BattleStartParam_GetEnemyCount(unk_001C);
    ScriptVM_CallFunction(&unk_0C44[2].vm, unk_0C44[2].data, "initialize", 2);
    ScriptVM_Start(&unk_0C44[2].vm, unk_0C44[2].data, "proc");

    NNS_GfdDumpLnkTexVramManager();
    NNS_GfdDumpLnkPlttVramManager();
}

void CBattleScene::func7()
{
    ScriptManager_UnloadSystem(m_game->m_scriptManager);
    m_game->m_textboxData->FreeSystemMessages();
    m_game->m_textboxData->FreeBattleMessages();
    m_game->m_textboxData->Reset();

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

void CBattleScene::ChangeBackground(u8 arg0)
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
    unk_00D4 = new CaptureBackground(arg0);
    if (hadAssist) {
        CreateAssist(type, value, partner);
    }
    NNS_GfdDumpLnkTexVramManager();
}

BOOL CBattleScene::AddEffectData(u16 id)
{
    if (unk_0BE4 >= 0x12) {
        return FALSE;
    }
    for (int i = 0; i < unk_0BE4; i++) {
        if (unk_02B0[i] != NULL && unk_02B0[i]->unk_18->unk_00 == id) {
            return FALSE;
        }
    }
    BattleEffectParam *entry = unk_0C1C->GetEntry(id);
    unk_02B0[unk_0BE4] = new CBattleAttackEffectData(id, entry, m_game->unk_14A8);
    unk_0BE4++;
    return TRUE;
}

BOOL CBattleScene::LoadEffectData(u16 id, CBattleAttackEffectData **slot)
{
    SAFE_DELETE(*slot);
    BattleEffectParam *entry = unk_0C1C->GetEntry(id);
    *slot = new CBattleAttackEffectData(id, entry, m_game->unk_14A8);
    return TRUE;
}

void CBattleScene::CreateAssist(int type, u16 arg1, u32 partner)
{
    ClearAssistEffects();
    SAFE_DELETE(unk_0384);
    for (u8 i = 0; i < 3; i++) {
        SAFE_DELETE(unk_0378[i]);
    }
    BattleParamTable *params = partner ? unk_0C24 : unk_0C20;
    unk_0C38 = partner;
    AudioEngine *audio = CGame::GetInstance()->m_audioEngine;
    switch (type) {
    case 0:
        unk_0384 = new CBattleAssistNormal(unk_02F8, unk_0378, params, arg1);
        break;
    case 1:
        LoadEffectData(0xD6, &unk_0378[0]);
        unk_0384 = new CBattleAssistFire(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x90);
        break;
    case 2:
        LoadEffectData(0xCB, &unk_0378[0]);
        unk_0384 = new CBattleAssistWater(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x8B);
        break;
    case 4:
        LoadEffectData(0xD5, &unk_0378[0]);
        unk_0384 = new CBattleAssistGrass(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x91);
        break;
    case 3:
        LoadEffectData(0xD7, &unk_0378[0]);
        unk_0384 = new CBattleAssistElectric(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x92);
        break;
    case 5:
        LoadEffectData(0xCD, &unk_0378[0]);
        LoadEffectData(0xCE, &unk_0378[1]);
        unk_0384 = new CBattleAssistIce(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x8C);
        break;
    case 6:
        unk_0384 = new CBattleAssistGrapple(unk_02F8, unk_0378, params, arg1);
        break;
    case 7:
        LoadEffectData(0xCF, &unk_0378[0]);
        unk_0384 = new CBattleAssistPoison(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x93);
        break;
    case 8: {
        LoadEffectData(0xCA, &unk_0378[0]);
        CBattleAssistGround *ground = new CBattleAssistGround(unk_02F8, unk_0378, params, arg1);
        ground->SetQuake(GetCameraController());
        unk_0384 = ground;
        audio->LoadSeGroup(0x8D);
        break;
    }
    case 9:
        LoadEffectData(0xD0, &unk_0378[0]);
        unk_0384 = new CBattleAssistFly(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x94);
        break;
    case 10:
        LoadEffectData(0xCC, &unk_0378[0]);
        unk_0384 = new CBattleAssistEsper(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x8F);
        break;
    case 11: {
        LoadEffectData(0xD1, &unk_0378[0]);
        LoadEffectData(0xD2, &unk_0378[1]);
        CBattleAssistInsect *insect = new CBattleAssistInsect(unk_02F8, unk_0378, params, arg1);
        unk_0384 = insect;
        insect->SetTargets(unk_0130);
        audio->LoadSeGroup(0x95);
        break;
    }
    case 12:
        LoadEffectData(0xC8, &unk_0378[0]);
        unk_0384 = new CBattleAssistRock(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x8E);
        break;
    case 13:
        LoadEffectData(0xD3, &unk_0378[0]);
        unk_0384 = new CBattleAssistGhost(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x96);
        break;
    case 14:
        LoadEffectData(0xD4, &unk_0378[0]);
        unk_0384 = new CBattleAssistDragon(unk_02F8, unk_0378, params, arg1);
        ((CBattleAssistDragon *)unk_0384)->unk_44 = GetCameraController();
        audio->LoadSeGroup(0x97);
        break;
    case 15:
        unk_0384 = new CBattleAssistEvil(unk_02F8, unk_0378, params, arg1);
        break;
    case 16:
        LoadEffectData(0xC9, &unk_0378[0]);
        unk_0384 = new CBattleAssistSteel(unk_02F8, unk_0378, params, arg1);
        audio->LoadSeGroup(0x98);
        break;
    case 17: {
        CBattleAssistRecover *recover = new CBattleAssistRecover(unk_02F8, unk_0378, params, arg1);
        unk_0384 = recover;
        recover->unk_1C = unk_0BB0;
        break;
    }
    }
    if (type == 0) {
        unk_00D8->unk_1B8->SetMaxCount(unk_0030 + 0x10);
    } else {
        unk_00D8->unk_1B8->SetMaxCount(unk_0030);
    }
    if (type != 0x11) {
        unk_00D8->unk_1B8->LoadTypeGfx(type);
    } else {
        unk_00D8->unk_1B8->ReleaseTypeGfx();
    }
    unk_00D8->unk_190 = 1;
}

void CBattleScene::StartPokemonAssist(u16 id, u32 partner)
{
    PokeIdTableEntry *info = PokeIdTable_Get(unk_0C14, id);
    BattlePokemonParam *param = unk_0C18->GetEntry(id);
    if (info->unk_04 != 0x11) {
        CreateAssist(info->unk_04, GetAssistTime(id), partner);
    } else {
        CreateAssist(0x11, param->unk_04, partner);
    }
    unk_0C30->SetPartnerInfo(info->unk_04, info->unk_05, info->unk_06);
    unk_0C30->LoadPokemonIcon(PokeIdTable_Get(unk_0C14, id)->unk_00);
}

u16 CBattleScene::GetAssistTime(u16 id)
{
    PokeIdTableEntry *info = PokeIdTable_Get(unk_0C14, id);
    BattlePokemonParam *param = unk_0C18->GetEntry(id);
    if (info->unk_04 != 0x11) {
        u16 value = param->unk_04 * 60;
        switch (SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_ASSISTT)) {
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

void CBattleScene::SetAllEnemiesStatus(int arg0, u16 arg1)
{
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL) {
            unk_00DC[i]->SetStatus(arg0, arg1);
        }
    }
}

u32 CBattleScene::func0()
{
    int result = -1;
    switch (unk_0020) {
    case 0:
        result = UpdateIntro();
        break;
    case 1:
        result = UpdateStartBanner();
        break;
    case 2:
        result = UpdateBattle();
        break;
    case 3:
        result = ov1_0211F984();
        break;
    case 4:
        result = ov1_0211F9D8();
        break;
    case 5:
        result = UpdateAssistMenu();
        break;
    case 7:
        result = UpdateResult();
        break;
    case 6:
        result = UpdateGameOver();
        break;
    case 11:
        result = UpdateDebugMenu();
        break;
    case 8:
        result = UpdateExit();
        break;
    case 9:
        result = UpdateNewPokemon();
        break;
    case 10:
        result = ov1_021208BC();
        break;
    }
    unk_0BB0->SetCurrentHP(unk_00D8->unk_19C);
    unk_0BB0->vfunc_08();
    unk_00D8->unk_19D = unk_0BB0->GetHPLevel();
    unk_00D0->Update();
    unk_0C08->Update();
    unk_0C0C->Update();
    if (unk_0020 == 2 && unk_0384 != NULL) {
        unk_0C30->SetTimeLeft(unk_0384->unk_04);
    }
    if (unk_0020 == 5) {
        unk_0C30->Update(0);
    } else {
        unk_0C30->Update(1);
    }
    unk_0C2C->Update(60);
    unk_0024 = unk_0020;
    if (unk_0008 & 1) {
        return BattleStartParam_GetNextScene(unk_001C);
    }
    return result;
}

int CBattleScene::UpdateIntro()
{
    BOOL done = FALSE;
    if (unk_0C44[2].file != NULL) {
        if (ScriptVM_Run(&unk_0C44[2].vm, 0xFFFFF) == 2) {
            done = TRUE;
        }
    } else {
        done = TRUE;
    }
    if (done == TRUE) {
        for (u8 i = 0; i < BattleStartParam_GetEnemyCount(unk_001C); i++) {
            if (unk_00DC[i] != NULL) {
                unk_00DC[i]->m_flags &= ~0x100;
            }
        }
        AudioEngine *audio = CGame::GetInstance()->m_audioEngine;
        audio->LoadBattleBgmGroup(BattleStartParam_GetBgmIndex(unk_001C));
        audio = CGame::GetInstance()->m_audioEngine;
        audio->PlayBattleBgm(BattleStartParam_GetBgmIndex(unk_001C), 0);
        unk_0C10->Start();
        unk_0020 = 1;
        return -1;
    }
    UpdateEnemies();
    UpdateEffects();
    UpdateParticles();
    RemoveOffscreenEffects();
    unk_00CC->Update();
    return -1;
}

int CBattleScene::UpdateStartBanner()
{
    unk_0C10->Update();
    if (!unk_0C10->IsActive()) {
        unk_0020 = 2;
    }
    return -1;
}

int CBattleScene::UpdateBattle()
{
    if (unk_0C44[0].file != NULL) {
        ScriptVM_Run(&unk_0C44[0].vm, 0xFFFFF);
    }
    if (unk_0C44[1].file != NULL) {
        ScriptVM_Run(&unk_0C44[1].vm, 0xFFFFF);
    }
    if (unk_0008 & 2) {
        return -1;
    }
    if (unk_0044 != BattleStartParam_GetEnemyCount(unk_001C)) {
        unk_0028++;
    }
    RunEnemyScripts();
    RunEffectScripts();
    if (unk_0020 != 2) {
        return -1;
    }
    UpdateAssist();
    UpdateCaptureLine();
    UpdateEnemies();
    UpdateEffects();
    UpdateParticles();
    RemoveOffscreenEffects();
    if (unk_0074 > unk_0078) {
        unk_0074 = unk_0078;
    }
    unk_0BB0->SetPartnerEnergy(unk_0074 >> 12);
    unk_00CC->Update();

    Point2D touchPos = { (unk_0010->unk_0A.x - 0x80) << FX32_SHIFT, (unk_0010->unk_0A.y - 0x60) << FX32_SHIFT };
    if (unk_0044 != BattleStartParam_GetEnemyCount(unk_001C)) {
        if (unk_0010->unk_04 != 0) {
            if (sub_02010BE0(unk_001C)) {
                if (PointInRect(touchPos, unk_0C08->m_rect->m_rectangle, 0)) {
                    unk_0C08->Press();
                    unk_0080 |= 1;
                    unk_0081 = 0;
                }
            }
            if (sub_02010BF4(unk_001C)) {
                if (PointInRect(touchPos, unk_0C0C->m_rect->m_rectangle, 0)) {
                    unk_0C0C->Press();
                    unk_0080 |= 2;
                    unk_0081 = 0;
                }
            }
        }
        if (unk_0010->unk_05 != 0) {
            BOOL held = TRUE;
            if ((unk_0080 & 1) && !PointInRect(touchPos, unk_0C08->m_rect->m_rectangle, 0)) {
                unk_0080 &= ~1;
                held = FALSE;
            } else if ((unk_0080 & 2) && !PointInRect(touchPos, unk_0C0C->m_rect->m_rectangle, 0)) {
                unk_0080 &= ~2;
                held = FALSE;
            }
            if (held && unk_0081 < 0xFF) {
                unk_0081++;
            }
        }
        if (unk_0010->unk_06 != 0) {
            if (unk_0081 <= 12) {
                if (PointInRect(touchPos, unk_0C08->m_rect->m_rectangle, 0)) {
                    if (unk_0080 & 1) {
                        unk_0080 &= ~1;
                        unk_0034--;
                        unk_0C30->ov1_0213EF14(1);
                        unk_0C30->ov1_0213EF40(1);
                        unk_0C30->RefreshPokemonList();
                        unk_00D0->Open();
                        u8 mask = 0;
                        for (u8 i = 0; i < BattleStartParam_GetPartyCount(unk_001C); i++) {
                            if (unk_0092[i]) {
                                mask |= 1 << i;
                            }
                        }
                        if (BattleStartParam_HasPartner(unk_001C)) {
                            if (unk_0074 == unk_0078) {
                                mask |= 1;
                            } else {
                                mask &= ~1;
                            }
                        }
                        int count = (u32)SaveData_GetPartyCapacity(&MAIN_BSS_020B26A0, 0xFF) <= BattleStartParam_GetPartyCount(unk_001C) ? BattleStartParam_GetPartyCount(unk_001C) : SaveData_GetPartyCapacity(&MAIN_BSS_020B26A0, 0xFF);
                        unk_0BC0->Open(count, unk_0388, unk_0082, mask, BattleStartParam_HasPartner(unk_001C));
                        m_game->m_audioEngine->StopAllSe();
                        m_game->m_audioEngine->PlaySe(0xFA);
                        unk_0020 = 5;
                    }
                } else if (PointInRect(touchPos, unk_0C0C->m_rect->m_rectangle, 0)) {
                    if (unk_0080 & 2) {
                        unk_0080 &= ~2;
                        unk_0034--;
                        m_game->m_audioEngine->StopAllSe();
                        unk_00D0->Open();
                        ScriptManager_Run(m_game->m_scriptManager, "system_001");
                        unk_0020 = 4;
                        m_game->m_audioEngine->SetBgmVolume(0x3F);
                        m_game->m_audioEngine->PlaySe(0xFA);
                    }
                }
            }
            unk_0080 &= ~1;
            unk_0080 &= ~2;
        }
    }
    CheckLineHit();
    if (unk_00D8->unk_19C != 0) {
        return -1;
    }
    StartGameOver();
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
        ScriptVM_Run(&unk_0C44[1].vm, 0xFFFFF);
    }
    if (unk_0008 & 2) {
        return -1;
    }
    if (unk_00D0->unk_04 == 0 && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
        if (m_game->m_textboxData->GetYesNoResult() == 0) {
            EndBattle(3);
        } else {
            unk_00D0->Close();
            unk_0020 = 2;
        }
        m_game->m_audioEngine->SetBgmVolume(0x7F);
    }
    return -1;
}

int CBattleScene::UpdateAssistMenu()
{
    if (unk_0C44[1].file != NULL) {
        ScriptVM_Run(&unk_0C44[1].vm, 0xFFFFF);
    }
    if (unk_0008 & 2) {
        return -1;
    }
    unk_0BC0->Update(unk_0010);
    if (!unk_0BC0->IsActive()) {
        if (unk_0BC0->IsCancelled() == 0) {
            *unk_00A4[unk_0BC0->GetSelectedIndex()] = 1;
            if (BattleStartParam_HasPartner(unk_001C) && unk_0BC0->GetSelectedIndex() == 0) {
                unk_0074 = 0;
            } else {
                RemovePartyPokemon(unk_0BC0->GetSelectedIndex());
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

int CBattleScene::UpdateResult()
{
    unk_0BB8->Update();
    if (!unk_0BB8->IsActive()) {
        m_game->m_mainFade->Start(4, 10);
        m_game->m_subFade->Start(4, 10);
        CBattleResultParameter *result = m_game->unk_1444;
        result->unk_6A = unk_0BB8->GetRank(unk_0BB8->m_score);
        result->unk_80 = unk_0BB8->m_exp;
        u8 hp = unk_0BB0->m_hp;
        unk_00D8->unk_19C = hp;
        result->unk_04 = hp;
        unk_0020 = 8;
    }
    return -1;
}

int CBattleScene::UpdateGameOver()
{
    unk_0BBC->vfunc_08();
    if (!unk_0BBC->IsActive()) {
        CBattleResultParameter *result = m_game->unk_1444;
        result->unk_08 = 1;
        u8 hp = unk_0BB0->m_hp;
        unk_00D8->unk_19C = hp;
        result->unk_04 = hp;
        EndBattle(1);
    }
    RunEnemyScripts();
    RunEffectScripts();
    UpdateAssist();
    UpdateCaptureLine();
    UpdateEnemies();
    UpdateEffects();
    UpdateParticles();
    RemoveOffscreenEffects();
    return -1;
}

int CBattleScene::UpdateExit()
{
    if (!m_game->m_mainFade->IsActive() && !m_game->m_subFade->IsActive()) {
        unk_0008 |= 1;
        if (m_game->unk_0008 != 1) {
            m_game->m_mainFade->Start(1, 0);
            m_game->m_subFade->Start(1, 0);
        }
    }
    return -1;
}

static inline void SetDebugAssist(CBattleScene *scene, int type, u16 value)
{
    scene->unk_0C30->ov1_0213ECB4(type, 0, 0);
    scene->unk_0C30->SetPartnerInfo(type, 0, 0);
    scene->unk_0C30->LoadPokemonIcon(0);
    scene->CreateAssist(type, value, 0);
}

int CBattleScene::UpdateDebugMenu()
{
    unk_0C40->Update();
    if (unk_0C40->IsActive() == 0) {
        G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
        GX_SetVisiblePlane(GX_PLANEMASK_BG0);
        unk_0020 = 2;
        int value = unk_0C40->GetResultValue();
        switch (unk_0C40->GetResultId()) {
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
            unk_00D8->SetInvincible(!unk_00D8->IsInvincible());
            break;
        case 12:
            SetAllEnemiesStatus(1, value * 60);
            break;
        case 13:
            SetAllEnemiesStatus(2, value * 60);
            break;
        case 14:
            SetAllEnemiesStatus(3, value * 60);
            break;
        case 15:
            SetAllEnemiesStatus(4, value * 60);
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
            EndBattle(0);
            break;
        case 35:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            EndBattle(1);
            break;
        case 36:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            EndBattle(2);
            break;
        case 37:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            EndBattle(3);
            break;
        case 38:
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            EndBattle(4);
            break;
        }
        unk_0C40->ResetResult();
    }
    return -1;
}

int CBattleScene::UpdateNewPokemon()
{
    int index;
    u16 i;
    BrightnessFade *fade;
    int count;
    PadInput *input;
    input = m_game->unk_0014;
    if (unk_0068 != 0) {
        if (unk_0010->unk_04 != 0 || (u16)(input->unk_0002 & 1)) {
            if (unk_005D == unk_005C) {
                m_game->m_textboxData->CloseAndClear(1, 1);
                unk_0BB8->Start(unk_00D8, unk_0BB0);
                if (!unk_00D0->IsOpen()) {
                    unk_00D0->Open();
                }
                unk_0020 = 7;
            } else {
                unk_0068 = 0;
            }
        }
    } else {
        fade = m_game->m_subFade;
        fade->Start(1, 0xFFFF);
        fade->Update();
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->SetParam(0, unk_005E[unk_005D]);
        m_game->m_textboxData->ShowSystemMessage(0x1A, 1, 1, 0);
        for (i = 0; i < 500; i++) {
            if (unk_005E[unk_005D] == PokeIdTable_Get(unk_0C14, i)->unk_00) {
                index = i;
                break;
            }
        }
        count = CountPokemon(&MAIN_BSS_020B26A0);
        unk_0C34->Release();
        unk_0C34->Load(index, 0, count + unk_005D + 1);
        m_game->m_audioEngine->PlaySe(0x3F);
        fade->Start(1, 0x20);
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
            if (BattleStartParam_GetNextScene(unk_001C) == 0x23) {
                unk_0BB8->Start(unk_00D8, unk_0BB0);
                if (!unk_00D0->IsOpen()) {
                    unk_00D0->Open();
                }
                unk_0020 = 7;
            } else {
                unk_0C30->SetListVisible(0);
                unk_0020 = 9;
            }
        } else {
            unk_0BB8->Start(unk_00D8, unk_0BB0);
            if (!unk_00D0->IsOpen()) {
                unk_00D0->Open();
            }
            unk_0020 = 7;
        }
    }
    RunEnemyScripts();
    RunEffectScripts();
    UpdateAssist();
    UpdateEnemies();
    UpdateEffects();
    UpdateParticles();
    RemoveOffscreenEffects();
    return -1;
}

void CBattleScene::UpdateCaptureLine()
{
    Point2D touchPos = { (unk_0010->unk_0A.x - 0x80) << FX32_SHIFT, (unk_0010->unk_0A.y - 0x60) << FX32_SHIFT };
    if (unk_0044 != BattleStartParam_GetEnemyCount(unk_001C) && unk_00D8->HasEnergy()) {
        if (unk_0010->unk_04 != 0) {
            unk_0040 = 0;
            unk_00D8->m_motion.SetPos(touchPos);
            unk_00D8->ResetLine(touchPos.x, touchPos.y);
            unk_00D8->SetActive(1);
            unk_00D8->vfunc_08();
            m_game->m_audioEngine->PlayCaptureLineSe(0);
            unk_0034++;
            unk_003C = 0;
            unk_00D8->unk_187 = 0;
        } else if (unk_0010->unk_06 != 0) {
            unk_00D8->SetActive(0);
            unk_00D8->vfunc_08();
            m_game->m_audioEngine->StopCaptureLineSe(0);
        } else if (unk_0010->unk_05 != 0 && unk_00D8->IsActive()) {
            unk_00D8->m_motion.SetPos(touchPos);
            StylerLine *line = unk_00D8->unk_1B8;
            Point2D last = line->m_lines[line->m_head].GetStart();
            if (MATH_IAbs(ApproxLength(touchPos.x - last.x, touchPos.y - last.y)) >= 0x8000) {
                m_game->m_audioEngine->AddCaptureLinePitch(12);
            } else {
                m_game->m_audioEngine->AddCaptureLinePitch(-12);
            }
            unk_00D8->AddLinePoint(touchPos);
            if (unk_00D8->IsLoopClosed()) {
                u8 hits = 0;
                u8 captured = 0;
                for (u8 i = 0; i < 8; i++) {
                    CBattleEnemy *enemy = unk_00DC[i];
                    if (enemy != NULL && enemy->IsAlive() && enemy->IsTargetable()
                        && unk_00D8->unk_1B8->IsInsideLoop(enemy->m_motion.m_pos.x, enemy->m_motion.m_pos.y - (enemy->m_bobHeight + (enemy->m_height + enemy->m_jumpHeight)))) {
                        if (hits == 0) {
                            unk_00D8->unk_187 = ++unk_003C;
                        }
                        hits++;
                        u16 level = DiskHPTable_GetPower(m_game->m_diskHPTable, MAIN_BSS_020B26A0.m_stylerLevel);
                        u8 type = enemy->unk_184->unk_18->unk_03;
                        enemy->TakeDamage(unk_00D8->CalcCapturePower(level, unk_0384 != NULL ? unk_0384->vfunc_10() : 0x12, type), 0);
                        Point2D pos;
                        pos.x = enemy->m_motion.m_pos.x;
                        pos.y = enemy->m_motion.m_pos.y - (enemy->m_bobHeight + (enemy->m_height + enemy->m_jumpHeight));
                        if (unk_00D8->IsUnk194Flag80()) {
                            unk_00D8->ov1_0212CBA0(pos, 0x14, 0x4000);
                        } else if (enemy->m_flags & 0x1000) {
                            unk_00D8->ov1_0212C990(pos, 0x14, 0x4000, 0x7FFF);
                        } else {
                            unk_00D8->SpawnLoopParticles(pos, 0x14, 0x4000, 0x7FFF);
                        }
                        if (BattleStartParam_HasPartner(unk_001C)) {
                            unk_0074 += unk_007C;
                        }
                        if (!enemy->IsAlive()) {
                            unk_002C += enemy->unk_184->unk_1C->unk_02;
                            captured++;
                            unk_0046[unk_0044] = enemy->unk_184->unk_16;
                            unk_0044++;
                            if (enemy->IsUnk2000()) {
                                enemy->StartCapture(0xF0);
                            } else {
                                enemy->StartCapture(captured * 6 + 0x78);
                            }
                            if (unk_00D8->unk_1C0->GetLevel() > unk_0056) {
                                unk_0056 = unk_00D8->unk_1C0->GetLevel();
                            }
                            if (unk_0044 == BattleStartParam_GetEnemyCount(unk_001C)) {
                                unk_00D8->SetActive(0);
                                if (unk_0384 != NULL) {
                                    unk_0384->vfunc_0C();
                                }
                                unk_00D8->vfunc_08();
                                m_game->m_audioEngine->StopCaptureLineSe(0);
                            }
                            BattlePokemonParam *param = enemy->unk_184->unk_1C;
                            Point2D gaugePos;
                            Point2D enemyPos = enemy->m_motion.GetPos();
                            gaugePos.x = enemyPos.x;
                            gaugePos.y = enemyPos.y + (param->unk_0F << 12);
                            unk_010C[i]->SetHP(enemy->unk_188, gaugePos);
                            unk_010C[i]->vfunc_08();
                            int mode = SaveData_GetPartsLevel(&MAIN_BSS_020B26A0, STYLER_PART_RECOVER);
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
                            if (hp >= MAIN_BSS_020B26A0.m_maxEnergy) {
                                hp = MAIN_BSS_020B26A0.m_maxEnergy;
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
                            && unk_00D8->unk_1B8->IsInsideLoop(effect->m_motion.m_pos.x, effect->m_motion.m_pos.y - (effect->m_bobHeight + (effect->m_height + effect->m_jumpHeight)))) {
                            effect->StartVanish();
                        }
                    }
                }
                if (hits != 0) {
                    if (captured != 0) {
                        m_game->m_audioEngine->PlaySe(0x1F);
                    } else if (unk_003C > 5) {
                        m_game->m_audioEngine->PlaySe(0x1F);
                    } else {
                        m_game->m_audioEngine->PlaySe(unk_003C + 0x1A);
                    }
                    if (BattleStartParam_GetEnemyCount(unk_001C) >= 2 && hits == BattleStartParam_GetEnemyCount(unk_001C)) {
                        unk_000C |= 0x10000;
                    }
                    unk_0058++;
                } else {
                    m_game->m_audioEngine->PlaySe(0x3A);
                }
                PointPair2D first = unk_00D8->unk_1B8->m_lines2[0].m_points;
                unk_0BAC->Start(first.p1);
                for (u16 j = 0; j < unk_00D8->unk_1B8->m_lines2Count; j++) {
                    unk_0BAC->AddPoint(unk_00D8->unk_1B8->m_lines2[j].GetStart());
                }
                unk_0BAC->Close();
            }
        }
    }
    unk_00D8->vfunc_08();
    unk_00D8->unk_254->Update();
    unk_0BAC->Update();
}

void CBattleScene::UpdateAssist()
{
    if (unk_0044 == BattleStartParam_GetEnemyCount(unk_001C)) {
        return;
    }
    if (!unk_00D8->HasEnergy()) {
        return;
    }
    if (unk_0384 != NULL) {
        if (unk_0384->vfunc_08(unk_0010, unk_00D8, unk_00DC) == 0) {
            ClearAssistEffects();
            m_game->m_mainFade->Start(1, 0x20);
            m_game->m_subFade->Start(1, 0x20);
            unk_00D8->unk_19E = 0;
            unk_00D8->unk_1B8->ReleaseTypeGfx();
            unk_00D8->unk_1B8->SetMaxCount(unk_0030);
            unk_00D8->unk_190 = 0;
            m_game->m_audioEngine->PlaySe(0x13);
            unk_0384->vfunc_0C();
            SAFE_DELETE(unk_0384);
            unk_0C30->ov1_0213EF40(0);
            unk_0C30->ReleasePokemonIcon();
            unk_0C30->ov1_0213EDDC();
        } else {
            u16 time = unk_0384->unk_04;
            if (time <= 300 && time % 60 == 0) {
                m_game->m_audioEngine->PlaySe(0x12);
            }
        }
    }
    for (u16 i = 0; i < 0x20; i++) {
        if (unk_02F8[i]->HasData()) {
            unk_02F8[i]->vfunc_08();
        }
    }
}

void CBattleScene::UpdateEnemies()
{
    for (u8 i = 0; i < 8; i++) {
        CBattleEnemy *enemy = unk_00DC[i];
        if (enemy != NULL && enemy->HasData()) {
            BattlePokemonParam *param = enemy->unk_184->unk_1C;
            Point2D gaugePos;
            Point2D enemyPos = enemy->m_motion.GetPos();
            gaugePos.x = enemyPos.x;
            gaugePos.y = enemyPos.y + (param->unk_0F << 12);
            if (enemy->IsAlive()) {
                unk_010C[i]->SetHP(enemy->unk_188, gaugePos);
            }
            int state = enemy->IsCaptureFinished();
            enemy->vfunc_08();
            unk_010C[i]->vfunc_08();
            if (state == 0 && enemy->IsCaptureFinished() == 1) {
                unk_0C30->SetCaptured(i);
                unk_0C30->ov1_0213EDDC();
            }
        }
    }
}

void CBattleScene::RunEnemyScripts()
{
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL && unk_00DC[i]->HasData()) {
            unk_00DC[i]->RunScript();
        }
    }
}

void CBattleScene::UpdateEffects()
{
    for (u16 i = 0; i < 0x60; i++) {
        if (unk_0130[i] != NULL && unk_0130[i]->HasData()) {
            unk_0130[i]->vfunc_08();
        }
    }
}

void CBattleScene::RunEffectScripts()
{
    for (u16 i = 0; i < 0x60; i++) {
        if (unk_0130[i] != NULL && unk_0130[i]->HasData()) {
            unk_0130[i]->RunScript();
        }
    }
}

void CBattleScene::UpdateParticles()
{
    unk_0BA8->Update();
}

void CBattleScene::RemoveOffscreenEffects()
{
    CBattleAttackEffect *effect;
    for (u16 i = 0; i < 0x60; i++) {
        effect = unk_0130[i];
        if (effect->HasData() && effect->unk_184->unk_18->unk_15 != 0) {
            if (!PointInRect(effect->m_motion.m_pos, unk_12C8[0], 0)) {
                effect->Terminate();
            } else if (!PointInRect(effect->m_motion.m_pos, unk_12C8[1], 0)) {
                effect->Terminate();
            }
        }
    }
    for (u8 j = 0; j < 0x20; j++) {
        effect = unk_02F8[j];
        if (effect->HasData() && effect->unk_184->unk_18->unk_15 != 0) {
            if (!PointInRect(effect->m_motion.m_pos, unk_12C8[0], 0)) {
                effect->Terminate();
            } else if (!PointInRect(effect->m_motion.m_pos, unk_12C8[1], 0)) {
                effect->Terminate();
            }
        }
    }
}

void CBattleScene::CheckLineHit()
{
    if (!unk_00D8->IsVisible()) {
        return;
    }
    if (unk_00D8->IsInvincible()) {
        return;
    }
    if ((unk_0080 & 2) && unk_0081 < 12) {
        return;
    }
    if ((unk_0080 & 1) && unk_0081 < 12) {
        return;
    }
    CheckLineHitObjects();
}

BOOL CBattleScene::CheckLineHitObjects()
{
    Circle hit;
    for (u8 i = 0; i < 0x60; i++) {
        CBattleAttackEffect *effect = unk_0130[i];
        if (effect != NULL && effect->HasData() && effect->IsUnk100Clear()) {
            Circle circle = effect->m_sphere.m_circle;
            hit.pos.x = circle.pos.x;
            hit.r = circle.r;
            hit.pos.y = circle.pos.y - (effect->m_bobHeight + (effect->m_height + effect->m_jumpHeight));
            for (u16 j = 0; j < unk_00D8->GetLineCount() + 1; j++) {
                if (PointInCircle(unk_00D8->GetLineStart(unk_00D8->GetLineIndex(j)), hit)) {
                    ShowLineTrail();
                    unk_00D8->SetActive(0);
                    int result = unk_00D8->TakeDamage(effect->unk_18E, effect->unk_184->unk_18->unk_0C);
                    unk_00D8->unk_25C->Show(hit.pos, result);
                    if (unk_0384 != NULL) {
                        unk_0384->vfunc_0C();
                    }
                    unk_00D8->ShatterLine(0x7FFF);
                    if (result != effect->unk_18E) {
                        unk_00D8->ShowHitEffect(hit.pos, 3);
                    } else {
                        unk_00D8->ShowHitEffect(hit.pos, 1);
                    }
                    if (result != 0) {
                        m_game->m_audioEngine->PlaySe(0x25);
                    } else {
                        m_game->m_audioEngine->PlaySe(0xF);
                    }
                    m_game->m_audioEngine->StopSe(0xB);
                    unk_0038++;
                    if (effect->unk_184->unk_18->unk_13 != 0) {
                        effect->Terminate();
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
            for (u16 j = 0; j < unk_00D8->GetLineCount() + 1; j++) {
                if (PointInCircle(unk_00D8->GetLineStart(unk_00D8->GetLineIndex(j)), hit)) {
                    unk_00D8->ShatterLine(0x7FFF);
                    ShowLineTrail();
                    unk_00D8->SetActive(0);
                    if (unk_0384 != NULL) {
                        unk_0384->vfunc_0C();
                    }
                    m_game->m_audioEngine->PlaySe(0x28);
                    m_game->m_audioEngine->StopSe(0xB);
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void CBattleScene::func1()
{
    unk_00C4->ApplyProjection();
    unk_00C4->ApplyView();
    G3_StoreMtx(0);
    int z = RenderField(unk_00C4, -0x3FF);
    RenderScreenEffect(unk_00C4, z);
    z = 2;
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL && unk_00DC[i]->HasData()) {
            z = unk_00DC[i]->DrawOverlays(unk_00C4, z);
        }
    }
    z = RenderEnemyGauges(unk_00C4, z);
    unk_00D0->SetZ(z + 3, z + 3, z + 3);
    unk_00D0->Render(unk_00C4);
    switch (unk_0024) {
    case 0:
        RenderIntro(unk_00C4, z + 3);
        break;
    case 1:
        RenderStartBanner(unk_00C4, z + 3);
        break;
    case 3:
    case 4:
        RenderPrompt(unk_00C4, z + 3);
        break;
    case 5:
        RenderAssistMenu(unk_00C4, z + 3);
        break;
    case 7:
        RenderResult(unk_00C4, z + 3);
        break;
    case 6:
        RenderGameOver(unk_00C4, z + 3);
        break;
    case 9:
        RenderNewPokemon(unk_00C4, z + 3);
        break;
    }
    int subZ = unk_0BB0->SetZ(0x3AC);
    unk_0BB0->vfunc_0C(unk_00C8);
    if (sub_02010BE0(unk_001C)) {
        subZ = unk_0C08->SetZ(subZ);
        unk_0C08->Render(unk_00C8);
    }
    if (sub_02010BF4(unk_001C)) {
        subZ = unk_0C0C->SetZ(subZ);
        unk_0C0C->Render(unk_00C8);
    }
}

void CBattleScene::func2()
{
    if (unk_005D != 0) {
        unk_0C34->Render();
    } else {
        unk_0C30->Render();
    }
}

int CBattleScene::RenderIntro(Camera2D *camera, int z)
{
    return z;
}

int CBattleScene::RenderStartBanner(Camera2D *camera, int z)
{
    int result = unk_0C10->SetZ(z);
    unk_0C10->Render(camera);
    return result;
}

int CBattleScene::RenderField(Camera2D *camera, int z)
{
    for (u8 i = 0; i < 8; i++) {
        unk_0BC4[i]->Clear();
    }
    for (u8 i = 0; i < 8; i++) {
        if (unk_00DC[i] != NULL && unk_00DC[i]->HasData()) {
            unk_0BC4[4]->Add(unk_00DC[i]);
        }
    }
    for (u8 i = 0; i < 0x60; i++) {
        if (unk_0130[i]->HasData()) {
            unk_0BC4[unk_0130[i]->unk_184->unk_18->unk_08]->Add(unk_0130[i]);
        }
    }
    for (u8 i = 0; i < 0x20; i++) {
        if (unk_02F8[i]->HasData()) {
            unk_0BC4[unk_02F8[i]->unk_184->unk_18->unk_08]->Add(unk_02F8[i]);
        }
    }
    z = CaptureBackground_SetZ(unk_00D4, z);
    CaptureBackground_Render(unk_00D4, unk_00C4);
    unk_0BC4[7]->m_z = z;
    unk_0BC4[6]->m_z = unk_0BC4[7]->Render(unk_00C4);
    z = unk_0BC4[6]->Render(unk_00C4);
    z = RenderShadows(unk_00C4, z);
    z = unk_0BAC->SetZ(z);
    unk_0BAC->Render(unk_00C4);
    z = unk_00D8->SetLineZ(z);
    unk_00D8->RenderLine(unk_00C4);
    unk_0BC4[5]->m_z = z;
    unk_0BC4[4]->m_z = unk_0BC4[5]->Render(unk_00C4);
    z = unk_0BC4[4]->Render(unk_00C4);
    z = unk_00D8->SetZ(z);
    unk_00D8->vfunc_0C(unk_00C4);
    unk_0BC4[3]->m_z = z;
    unk_0BC4[2]->m_z = unk_0BC4[3]->Render(unk_00C4);
    unk_0BC4[1]->m_z = unk_0BC4[2]->Render(unk_00C4);
    unk_0BC4[0]->m_z = unk_0BC4[1]->Render(unk_00C4);
    z = unk_0BC4[0]->Render(unk_00C4);
    unk_0BA8->Render(unk_00C4);
    return z;
}

int CBattleScene::RenderPrompt(Camera2D *camera, int z)
{
    return z;
}

int CBattleScene::RenderAssistMenu(Camera2D *camera, int z)
{
    int result = unk_0BC0->SetZ(z);
    unk_0BC0->Render(unk_00C4);
    return result;
}

int CBattleScene::RenderResult(Camera2D *camera, int z)
{
    int result = unk_0BB8->SetZ(z);
    unk_0BB8->Render(camera);
    return result;
}

int CBattleScene::RenderGameOver(Camera2D *camera, int z)
{
    int result = unk_0BBC->SetZ(z);
    unk_0BBC->vfunc_0C(camera);
    return result;
}

int CBattleScene::RenderNewPokemon(Camera2D *camera, int z)
{
    return z;
}

int CBattleScene::RenderEnemyGauges(Camera2D *camera, int z)
{
    G3_Identity();
    unk_00C8->ApplyProjection();
    unk_00C8->ApplyView();
    G3_StoreMtx(0);
    if (unk_0070 != 0) {
        if (sub_02010C08(unk_001C)) {
            CBattleEnemy *enemy = unk_00DC[0];
            if (enemy != NULL) {
                if (enemy->HasData()) {
                    unk_010C[0]->Setup(8, enemy->unk_188, enemy->unk_184->unk_1C->unk_00, DAT_overlay_1_0213fb68);
                    unk_010C[0]->vfunc_08();
                }
                z = unk_010C[0]->SetZ(z);
                unk_010C[0]->vfunc_0C(unk_00C8);
            }
            for (u8 i = 1; i < 8; i++) {
                if (unk_00DC[i] != NULL && unk_00DC[i]->HasData() && unk_00DC[i]->unk_108.value == 0x1F && unk_00DC[i]->IsUnk400Clear()) {
                    z = unk_010C[i]->SetZ(z);
                    unk_010C[i]->vfunc_0C(unk_00C8);
                }
            }
        } else {
            for (u8 i = 0; i < 8; i++) {
                if (unk_00DC[i] != NULL && unk_00DC[i]->HasData() && unk_00DC[i]->unk_108.value == 0x1F && unk_00DC[i]->IsUnk400Clear()) {
                    z = unk_010C[i]->SetZ(z);
                    unk_010C[i]->vfunc_0C(unk_00C8);
                }
            }
        }
    }
    return z;
}

int CBattleScene::RenderScreenEffect(Camera2D *camera, int z)
{
    G3_Identity();
    unk_00C4->SetOffset(0, 0);
    unk_00C4->ApplyProjection();
    unk_00C4->ApplyView();
    if (unk_0C2C != NULL) {
        unk_0C2C->Draw(unk_00C4);
    }
    return z;
}

int CBattleScene::RenderShadows(Camera2D *camera, int z)
{
    CBattleEnemy *enemy;
    for (u8 i = 0; i < 8; i++) {
        enemy = unk_00DC[i];
        if (enemy != NULL && enemy->HasData() && enemy->IsUnk800Clear() && (enemy->m_height + enemy->m_jumpHeight) + enemy->m_bobHeight <= FX32_CONST(96)) {
            Rectangle shadow = enemy->GetShadowRect();
            if (shadow.size.x != 0 && shadow.size.y != 0) {
                fx32 scale = LinearInterpolate(FX32_ONE, 0, (enemy->m_height + enemy->m_jumpHeight) + enemy->m_bobHeight, FX32_CONST(96));
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
            BattleEffectParam *entry = effect->unk_184->unk_18;
            if (entry->unk_17 != 0 && (effect->m_height + effect->m_jumpHeight) + effect->m_bobHeight <= FX32_CONST(96)) {
                Rectangle shadow = entry->GetShadowRect();
                shadow.pos.x += effect->m_motion.m_pos.x;
                shadow.pos.y += effect->m_motion.m_pos.y;
                fx32 scale = LinearInterpolate(FX32_ONE, 0, (effect->m_height + effect->m_jumpHeight) + effect->m_bobHeight, FX32_CONST(96));
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
            BattleEffectParam *entry = effect->unk_184->unk_18;
            if (entry->unk_17 != 0 && effect->unk_108.value == 0x1F && (effect->m_height + effect->m_jumpHeight) + effect->m_bobHeight <= FX32_CONST(96)) {
                Rectangle shadow = entry->GetShadowRect();
                shadow.pos.x += effect->m_motion.m_pos.x;
                shadow.pos.y += effect->m_motion.m_pos.y;
                fx32 scale = LinearInterpolate(FX32_ONE, 0, (effect->m_height + effect->m_jumpHeight) + effect->m_bobHeight, FX32_CONST(96));
                shadow.size.x = FX32_MUL(shadow.size.x, scale);
                shadow.size.y = FX32_MUL(shadow.size.y, scale);
                unk_0C28->SetRectangle(&shadow, z);
                unk_0C28->Render(unk_00C4);
            }
        }
    }
    return z + 1;
}

int CBattleScene::GetObjectType(u32 id)
{
    if (id >= 1 && id < 9) {
        return 1;
    }
    if (id >= 9 && id < 0x89) {
        return 2;
    }
    return id == 0 ? 0 : 3;
}

CBattleEnemy *CBattleScene::GetEnemy(u32 id)
{
    if (id >= 1 && id < 9) {
        u32 idx = id - 1;
        return unk_00DC[idx];
    }
    return NULL;
}

CBattleAttackEffect *CBattleScene::GetEffect(u32 id)
{
    if (id >= 9 && id < 0x89) {
        u32 idx = id - 9;
        return unk_0130[idx];
    }
    return NULL;
}

CBattleAttackEffectData *CBattleScene::GetEffectData(u32 idx)
{
    if (idx >= 0x12) {
        return NULL;
    }
    return unk_02B0[idx];
}

CameraController *CBattleScene::GetCameraController()
{
    return unk_00CC;
}

void CBattleScene::EndBattle(int result)
{
    CGame::GetInstance()->m_audioEngine->LoadResultAudio();
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
        m_game->m_mainFade->Start(4, 0x40);
        m_game->m_subFade->Start(4, 0x40);
        unk_0020 = 8;
        return;
    }
    unk_0BB8->m_baseExp = unk_002C;
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
        CheckNewCaptures();
    }
    unk_0BB8->m_bonusFlags = unk_000C;
    if (result == 0) {
        m_game->m_audioEngine->PlayBgm(3, 0);
        unk_006C = 0;
        unk_0020 = 10;
    } else if (unk_005C != 0) {
        if (BattleStartParam_GetNextScene(unk_001C) == 0x23) {
            unk_0BB8->Start(unk_00D8, unk_0BB0);
            if (!unk_00D0->IsOpen()) {
                unk_00D0->Open();
            }
            unk_0020 = 7;
        } else {
            unk_0020 = 9;
        }
    } else {
        unk_0BB8->Start(unk_00D8, unk_0BB0);
        if (!unk_00D0->IsOpen()) {
            unk_00D0->Open();
        }
        unk_0020 = 7;
    }
    unk_0018 = result;
}

void CBattleScene::StartGameOver()
{
    ShowLineTrail();
    unk_0BBC->Start();
    unk_0020 = 6;
}

void CBattleScene::ClearAssistEffects()
{
    for (u16 i = 0; i < 0x20; i++) {
        if (unk_02F8[i] != NULL && unk_02F8[i]->HasData()) {
            unk_02F8[i]->Terminate();
        }
    }
}

void CBattleScene::ShowLineTrail()
{
    Point2D first = unk_00D8->GetLineStart(0);
    unk_0BAC->Start(first);
    for (u16 i = 0; i < (u32)unk_00D8->GetLineCount(); i++) {
        Point2D pos = unk_00D8->GetLineEnd(unk_00D8->GetLineIndex(i));
        unk_0BAC->AddPoint(pos);
    }
    unk_0BAC->Update();
}

void CBattleScene::RemovePartyPokemon(u8 index)
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

void CBattleScene::SelectTouchPanel(int arg0)
{
    if (arg0) {
        CGame::GetInstance()->SetTouchPanelMode(0);
    } else {
        CGame::GetInstance()->SetTouchPanelMode(1);
    }
    unk_0010 = CGame::GetInstance()->activeTouchPanel;
}

static inline void SetCaptureCount(SaveData *save, u16 id, int count)
{
    if (count <= 0) {
        save->m_captureCounts[id] = 0;
    } else if (count >= 0xFF) {
        save->m_captureCounts[id] = 0xFF;
    } else {
        save->m_captureCounts[id] = count;
    }
}

void CBattleScene::CheckNewCaptures()
{
    SaveData *save = &MAIN_BSS_020B26A0;
    u16 ids[4];
    u8 counts[4];
    MI_CpuFill8(ids, 0, sizeof(ids));
    MI_CpuFill8(counts, 0, sizeof(counts));
    for (u8 i = 0; i < BattleStartParam_GetPokemonCount(unk_001C); i++) {
        u16 id = PokeIdTable_Get(unk_0C14, BattleStartParam_GetPokemonId(unk_001C, i))->unk_00;
        ids[i] = id;
        counts[i] = save->m_captureCounts[id];
    }
    for (u8 i = 0; i < BattleStartParam_GetPokemonCount(unk_001C); i++) {
        for (u8 j = 0; j < unk_0044; j++) {
            u16 id = ids[i];
            if (id == PokeIdTable_Get(unk_0C14, unk_0046[j])->unk_00) {
                SetCaptureCount(save, id, save->m_captureCounts[id] + 1);
            }
        }
    }
    unk_005C = 0;
    unk_005D = 0;
    unk_0068 = 0;
    MI_CpuFill8(unk_005E, 0, 8);
    for (u8 i = 0; i < BattleStartParam_GetPokemonCount(unk_001C); i++) {
        u16 id = ids[i];
        u8 before = counts[i];
        u8 after = save->m_captureCounts[id];
        if (before == 0 && after != 0) {
            unk_005E[unk_005C] = id;
            unk_005C++;
        } else if (before < 10 && after >= 10) {
            unk_000C |= 0x20;
        } else if (before < 100 && after >= 100) {
            unk_000C |= 0x40;
        }
    }
    for (u8 i = 0; i < BattleStartParam_GetPokemonCount(unk_001C); i++) {
        SetCaptureCount(save, ids[i], counts[i]);
    }
}

u32 CBattleScene::getSceneId()
{
    return 0;
}
