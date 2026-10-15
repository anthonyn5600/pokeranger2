#include "scene/CFieldScene.hpp"

#include <string.h>

#include "BGFontPrinter.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CTouchPanel.hpp"
#include "Camera2D.hpp"
#include "CameraController.hpp"
#include "DisplayUtil.hpp"
#include "DrawObjectList.hpp"
#include "FieldCannons.hpp"
#include "FieldDebugMenu.hpp"
#include "FieldDrawActorDataPool.hpp"
#include "FieldEventRectManage.hpp"
#include "FieldScreenEffectManage.hpp"
#include "FieldScriptLauncher.hpp"
#include "FieldShadow.hpp"
#include "FieldSubScreen.hpp"
#include "FieldSyscallSets.hpp"
#include "PadInput.hpp"
#include "SaveData.hpp"
#include "SubScreenIconMenu.hpp"
#include "TextboxManager.hpp"
#include "TitleBanner.hpp"
#include "TouchDotLine.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_0214B984.hpp"
#include "UnkClass_0214FB28.hpp"
#include "UnkClass_0214FD4C.hpp"
#include "UnkClass_0216D5F4.hpp"
#include "UnkStruct_020107A8.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldEnemyManage.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldNpc.hpp"
#include "field/CFieldNpcManage.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPartnerNpc.hpp"
#include "field/CFieldPartnerPokemon.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldPlayerInputControlManage.hpp"
#include "field/CFieldTargetObject.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

extern "C" {
void MissionQuestData_SetChapter(MissionQuestData *missionQuestData, u32 mapIdx);
void GlobalValues_ClearChapterValues(void *arg0);
void ScriptManager_LoadArea(void *scriptManager, u8 arg1);
void ScriptManager_LoadQuest(void *scriptManager, u8 arg1);
void SaveData_ReleaseAllActorData(SaveData *save);
void SaveData_ReleasePartnerVram(SaveData *save);
void ScriptManager_UnloadAll(void *scriptManager);
}

struct UnkStruct_0208AC1C {
    char name[0x10];
    u32 mapId;
    int x;
    int y;
};

extern CFieldScene *MAIN_BSS_0210CA40;
extern u16 DAT_0208d58c;
extern UnkStruct_0208AC1C s_c000First_0208ac1c[];
extern SaveData MAIN_BSS_020B26A0;
extern FieldData *MAIN_BSS_0210CA6C;
extern void *MAIN_BSS_0210CA74;

CFieldScene::CFieldScene(CGame *game)
    : unk_0140(-1)
{
    MAIN_BSS_0210CA40 = this;
    m_game = game;
    m_game->unk_146C.SetFps(30);
    DAT_0208d58c = 30;
    m_cameraTarget = 0;
    m_partnerPokemon = 0;
    unk_0080 = 0;
    m_flags = 0;
    unk_00EC = 0;
    unk_00AC = -1;
    unk_00B0 = 0;
    unk_00FC.SetRectangle(0, 0, FX32_CONST(256), FX32_CONST(256), 0x3F2);
    unk_00FC.m_color = 0;
    unk_00FC.m_polygonID = 0x2B;
    unk_00F0 = 0;
    unk_00F4 = 0;
    unk_00F8 = 0;
    unk_00F9 = 0;
    unk_00FA = 0;
    unk_0064 = 0;
    unk_00CC = -1;
}

CFieldScene::~CFieldScene()
{
    m_game->unk_146C.SetFps(30);
    MAIN_BSS_0210CA40 = NULL;
}

void CFieldScene::func5()
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
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);

    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);

    G2S_SetBG0Priority(3);
    G2S_SetBG1Priority(2);
    G2S_SetBG2Priority(1);
    G2S_SetBG3Priority(0);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG3);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG3);
    GX_DispOn();
    GXS_DispOn();
}

void CFieldScene::func6()
{
    Point2D positions[16];
    u16 directions[16];
    int sceneId;
    BOOL fromTable;
    UnkStruct_02041D80 *mapInfo;
    int doorEventId;
    SaveData *save;
    BOOL firstScene;
    BOOL flag2;
    u32 mapIdx;

    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    sceneId = m_game->unk_0008;
    CSoftwareSprite::AllocSharedPalette();
    save = &MAIN_BSS_020B26A0;
    MAIN_BSS_0210CA74 = NULL;
    m_game->m_textboxData->Init(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->m_nameTables, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);

    firstScene = FALSE;
    fromTable = FALSE;
    flag2 = FALSE;
    if (MAIN_BSS_020B26A0.unk_8B68 != 0) {
        mapIdx = save->unk_8B6C;
        firstScene = TRUE;
        GlobalValues_ClearChapterValues(m_game->unk_14B4);
        const char *name = s_c000First_0208ac1c[mapIdx].name;
        if (name != NULL) {
            strcpy(save->m_saveName, name);
        } else {
            save->m_saveName[0] = 0;
        }
        save->m_mapId = s_c000First_0208ac1c[mapIdx].mapId;
        Point2D pos;
        pos.x = s_c000First_0208ac1c[mapIdx].x << FX32_SHIFT;
        pos.y = s_c000First_0208ac1c[mapIdx].y << FX32_SHIFT;
        save->SetPos(pos);
        save->unk_8B68 = 0;
        save->unk_8B6C = 0;
        fromTable = TRUE;
    } else {
        mapIdx = m_game->m_missionQuestData->m_chapter;
    }

    m_fieldData = MAIN_BSS_0210CA6C;
    mapInfo = FieldData_GetMap(m_fieldData, save->m_mapId);
    save->m_areaType = mapInfo->unk_04;
    if (firstScene) {
        if (mapInfo->unk_04 == 1) {
            save->unk_8802 = 1;
        } else {
            save->unk_8802 = 0;
        }
    }

    m_game->m_textboxData->LoadSystemMessages(0);
    ScriptManager_LoadSystem(m_game->m_scriptManager, 0);
    MissionQuestData_SetChapter(m_game->m_missionQuestData, mapIdx);
    u8 quest = m_game->m_missionQuestData->m_questId;
    if (quest != 0) {
        m_game->m_textboxData->LoadQuestMessages(quest);
        ScriptManager_LoadQuest(m_game->m_scriptManager, quest);
    }

    if (save->unk_8B74 & 1) {
        m_flags |= 0x440;
    }
    if (save->unk_8B74 & 2) {
        flag2 = TRUE;
    }
    save->unk_8B74 &= ~3;
    doorEventId = -1;
    if (save->unk_8B74 & 4) {
        doorEventId = m_game->unk_1444->unk_18[0];
        save->unk_8B74 &= ~4;
    }
    if (!(save->unk_7F60 & 1)) {
        sub_02010D04(m_game->unk_1444);
    }

    m_syscallSets = new FieldSyscallSets();
    m_syscallSets->ov0_0213D658();

    m_camera = new Camera2D();
    m_camera->SetOrtho(0, 0xC0000, 0, 0x100000, -0x800000, 0x800000, 0x10000);
    m_game->m_cameraController->SetTarget((UnkStruct_0200D3F8_Target *)m_camera);

    m_hudCamera = new Camera2D();
    m_hudCamera->SetOrtho(0, 0xC0000, 0, 0x100000, -0x800000, 0x800000, 0x400000);
    Camera2D *camera = m_hudCamera;
    camera->unk_1C = 0;
    camera->unk_20 = 0;

    m_actorDataPool = new FieldDrawActorDataPool();

    m_partners = new CFieldPartnerManage();
    m_partners->Alloc(0x10);
    m_effectListeners.ov0_02143730(m_partners);

    m_npcs = new CFieldNpcManage();
    m_npcs->Alloc(0x20);
    m_enemies = new CFieldEnemyManage();
    m_enemies->Alloc(0x20);
    m_targetObjects = new CFieldTargetObjectManage();
    m_targetObjects->Alloc(0x20);

    m_eventRects = new FieldEventRectManage();
    m_eventRects->Create(0x30);
    m_scriptLauncher = new FieldScriptLauncher(m_game);
    m_scriptLauncher->ov0_0213F960();

    m_hpGauge = new CPlayerHPGauge();
    m_hpGauge->SetVisible(TRUE);
    m_hpGauge->SetPartnerVisible(FALSE);
    m_hpGauge->SetHP(save->m_energy, save->m_maxEnergy);
    m_hpGauge->SetPartner(save->unk_0004 >> FX32_SHIFT, save->unk_0008);
    m_hpGauge->SetZ(0x3FF);

    unk_004C = new UnkClass_0214FB28();
    unk_0050 = new UnkClass_0214FD4C();
    unk_004C->m_z = 0x424;
    unk_0050->m_z = 0x424;

    m_subScreen = new FieldSubScreen(m_game);
    m_iconMenu = new SubScreenIconMenu(m_game);
    m_cannons = new FieldCannons();
    m_map = new CFieldMap();

    m_player = new CFieldPlayer();
    m_player->ov0_02132F14(save->m_sex, (save->m_rangerClassGrade >> 4) & 0xF, mapInfo->unk_04);
    m_player->ov0_02132FA0(save->unk_8802);
    if (flag2) {
        m_player->sub_flag2();
    }
    m_player->SetPos(save->GetPos());
    m_player->sub_020128EC_(save->m_dir);
    m_player->sub_0201287C_();
    m_player->SetLayer(save->m_layer);

    unk_0078 = 0;
    m_partnerPokemon = 0;
    unk_0080 = 0;
    unk_0084 = 0;

    int mode = 0;
    switch (mapInfo->unk_04) {
    case 1:
        mode = 1;
        break;
    case 5:
        mode = 2;
        break;
    }

    if (mode != 1) {
        for (int i = 0; i < 2; i++) {
            PartnerSlot *partner = save->GetPartner(i);
            if (partner != NULL && partner->unk_00 != 0) {
                int idx = m_partners->ov0_02139920(partner->unk_04, partner->unk_08, 0x1E16, 1, 1);
                if (idx >= 0) {
                    CFieldActor *actor = m_partners->Get(idx);
                    if (actor != NULL) {
                        actor->SetPos((Point2D) { partner->unk_0C.x, partner->unk_0C.y });
                        actor->sub_020128EC_(partner->unk_0A);
                        actor->sub_0201287C_();
                        ((CFieldPartnerNpc *)actor)->SetName(partner->unk_14);
                    }
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        PartyEntry *data = SaveData_GetEntry(save, i);
        if (data != NULL && (data->m_flags & 1)) {
            u32 id = (data->m_index & 0xFFF) | ((6 << 24) | ((data->m_mapId & 0xFFF) << 12));
            if (id != 0) {
                int idx = m_partners->ov0_02139920(id, data->m_kind, 0xE, 0, 1);
                if (idx >= 0) {
                    CFieldActor *actor = m_partners->Get(idx);
                    if (actor != NULL) {
                        if (id == save->m_selectedPartyId) {
                            Actor_HideManpu(actor);
                            actor->unk_20 = 0;
                            actor->sub_0202D394();
                        } else {
                            actor->SetPos((Point2D) { data->m_pos.x, data->m_pos.y });
                            actor->SetLayer(data->m_layer);
                            actor->sub_020128EC_(data->unk_14);
                            actor->sub_0201287C_();
                        }
                    }
                }
            }
        }
    }

    if (save->unk_8802 != 0 && save->unk_8802 != 1) {
        m_partners->DeactivateAll();
        if (save->unk_8802 != 2) {
            m_partners->ov0_02139E14(4);
            m_partners->ov0_0213A7FC(0);
            CFieldActor *actor = m_partners->Find(save);
            if (actor != NULL) {
                actor->m_flags &= ~1;
            }
        }
    }

    m_drawLists = new DrawObjectList[10];
    m_banner = new TitleBanner();
    m_effects = new CFieldEffectManage(&m_effectListeners);
    m_effectFactories.ov0_021518B8(m_effects);
    m_screenEffects = new FieldScreenEffectManage();
    m_shadow = new FieldShadow(5);

    m_touchLine = new TouchDotLine();
    if (m_touchLine != NULL) {
        CellAnimController *cac = m_effects->m_resident.GetCac(6);
        CNCERFile *ncer = m_effects->m_resident.GetNcer(6);
        VramPalette *palette = m_effects->m_resident.GetPalette();
        VramImage *ncbr = m_effects->m_resident.GetNcbr(0);
        ov0_0214816C(m_touchLine, ncbr, palette, ncer, cac);
    }

    m_game->m_cameraController->SetTarget((UnkStruct_0200D3F8_Target *)m_camera);
    m_inputControl = new CFieldPlayerInputControlManage();
    if (m_hpGauge != NULL) {
        unk_0064 = new UnkClass_0216D5F4();
        ov0_0216D5F4(unk_0064, m_hpGauge->GetPart(1));
    }
    unk_00E4 = new UnkClass_0214B984();
    m_debugMenu = new FieldDebugMenu(m_game);

    m_game->m_textboxData->LoadAreaMessages(mapInfo->unk_00);
    ScriptManager_LoadArea(m_game->m_scriptManager, mapInfo->unk_00);
    ov0_021220D0(save->m_mapId, fromTable);

    if (sceneId != 5 && sceneId != 7) {
        BOOL handled = FALSE;
        if (sceneId == 0x19 || sceneId == 0xE || sceneId == 0x1E) {
            handled = m_game->RestoreBgmState();
        }
        if (!handled) {
            m_game->m_audioEngine->PlayMapBgm(save->m_mapId, 0, 0);
            if (m_flags & 0x40) {
                m_game->m_audioEngine->LoadBgmGroup(0x2D);
                m_game->m_audioEngine->PlayBgm(5, 30);
            }
        }
    }

    unk_00AA = 0xFFFF;
    unk_00AC = -1;
    unk_00B0 = 0;

    if (m_partners != NULL) {
        for (int i = 0; i < 16; i++) {
            CFieldActor *actor = m_partners->Get(i);
            if (actor != NULL && actor->IsActive()) {
                positions[i] = actor->GetPos();
                directions[i] = actor->GetDir();
            }
        }
    }

    ov0_02122EF4();

    if (m_partners != NULL) {
        for (int i = 0; i < 16; i++) {
            CFieldActor *actor = m_partners->Get(i);
            if (actor != NULL && actor->IsActive()) {
                actor->SetPos(positions[i]);
                actor->sub_020128EC_(directions[i]);
                actor->sub_0201287C_();
                static_cast<CFieldPartner *>(actor)->unk_EC.ov0_02158F38();
            }
        }
    }

    if (save->unk_7F60 & 1) {
        for (int i = 0; i < m_enemies->m_count; i++) {
            CFieldActor *actor = m_enemies->Get(i);
            if (actor != NULL && actor->IsActive()) {
                actor->SetPos(save->GetEnemyPos(i));
                actor->sub_020128EC_(save->m_enemyDir[i]);
                actor->sub_0201287C_();
            }
        }
        for (int i = 0; i < m_npcs->m_count; i++) {
            CFieldActor *actor = m_npcs->Get(i);
            if (actor != NULL) {
                actor->SetPos(save->GetNpcPos(i));
                actor->sub_020128EC_(save->m_npcDir[i]);
                actor->sub_0201287C_();
                ((CFieldNpc *)actor)->ov0_0213C5DC();
            }
        }
        for (int i = 0; i < m_targetObjects->m_count; i++) {
            CFieldActor *actor = m_targetObjects->Get(i);
            if (actor != NULL) {
                actor->SetPos(save->GetObjectPos(i));
                actor->sub_020128EC_(save->m_objectDir[i]);
                actor->sub_0201287C_();
            }
        }
        m_cannons->ov0_02159970();
    }

    for (int i = 0; i < 0x50; i++) {
        BOOL hide = FALSE;
        u32 flags = save->unk_81B4[i & 0x3FF];
        if ((flags & 1) ? TRUE : FALSE) {
            u32 state = (flags >> 8) & 0xF;
            switch ((flags >> 1) & 0x7F) {
            case 0:
                break;
            case 1:
                if (state == 1 || state == 2) {
                    hide = TRUE;
                }
                break;
            case 2:
            case 3:
                if (state == 1) {
                    hide = TRUE;
                }
                break;
            case 4:
                if (state == 0) {
                    hide = TRUE;
                }
                break;
            case 5:
                if (state != 2) {
                    hide = TRUE;
                }
                break;
            }
            if (hide) {
                CFieldActor *actor = m_targetObjects->Get(i);
                actor->sub_020129F4_(0, 0);
                actor->Update(NULL);
            }
        }
    }

    CFieldMapLayerAttribute *attrLayer = m_map->GetAttributeLayer(m_player->m_layer);
    if (attrLayer != NULL) {
        int result = attrLayer->GetCellAtPos(m_player->GetX(), m_player->GetY());
        if (result == 0xE || result == 0x17) {
            if (m_partners != NULL) {
                m_partners->ov0_0213A7FC(0);
            }
            if (m_player != NULL) {
                m_player->sub_reset();
                m_player->PlayAnim(0x80, 0);
            }
        }
    }

    if (save->HasString()) {
        m_scriptLauncher->ov0_0213FB0C(save->m_saveName, 0, -1);
        save->m_saveName[0] = '\0';
    } else if (doorEventId > 0) {
        m_scriptLauncher->ov0_0213FB0C("sDokaRelease", doorEventId, -1);
    } else {
        switch (m_game->m_mainFade->GetMode()) {
        case 2:
            m_game->m_mainFade->Start(1, 10);
            break;
        case 4:
            m_game->m_mainFade->Start(3, 10);
            break;
        }
        switch (m_game->m_subFade->GetMode()) {
        case 2:
            m_game->m_subFade->Start(1, 10);
            break;
        case 4:
            m_game->m_subFade->Start(3, 10);
            break;
        }
    }

    SetupBGFonts();
    m_subScreen->ShowAreaMap(save->m_mapId, m_player->GetX() >> FX32_SHIFT, m_player->GetY() >> FX32_SHIFT);
    ov0_021248EC();
    if (sceneId == 6) {
        m_subScreen->ShowRangerCardNow();
        m_iconMenu->OpenFadeIn();
    }
    m_effects->ov0_021434F0();
    m_enemies->ov0_02136878();
}

void CFieldScene::func7()
{
    ScriptManager_UnloadAll(m_game->m_scriptManager);
    m_game->m_textboxData->FreeAreaMessages();
    m_game->m_textboxData->FreeSystemMessages();
    m_game->m_textboxData->FreeChapterMessages();
    m_game->m_textboxData->FreeQuestMessages();
    m_game->m_textboxData->Reset();
    m_game->m_cameraController->SetTarget(NULL);

    SAFE_DELETE(m_inputControl);
    SAFE_DELETE(m_touchLine);
    SAFE_DELETE(m_screenEffects);
    SAFE_DELETE(m_effects);
    SAFE_DELETE(m_shadow);
    SAFE_DELETE_ARRAY(m_drawLists);
    SAFE_DELETE(m_player);
    SAFE_DELETE(m_map);
    m_effectFactories.ov0_021518F4();
    SAFE_DELETE(m_scriptLauncher);
    SAFE_DELETE(m_eventRects);
    SAFE_DELETE(m_targetObjects);
    SAFE_DELETE(m_enemies);
    SAFE_DELETE(m_npcs);
    m_effectListeners.ov0_02143760(m_partners);
    SAFE_DELETE(m_partners);
    SAFE_DELETE(m_actorDataPool);
    SAFE_DELETE(m_camera);
    SAFE_DELETE(m_hudCamera);
    SAFE_DELETE(m_syscallSets);
    SAFE_DELETE(m_hpGauge);
    SAFE_DELETE(unk_004C);
    SAFE_DELETE(unk_0050);
    SAFE_DELETE(unk_00E4);
    SAFE_DELETE(m_debugMenu);
    SAFE_DELETE(m_subScreen);
    SAFE_DELETE(m_iconMenu);
    SAFE_DELETE(m_cannons);
    SAFE_DELETE(m_banner);
    SAFE_DELETE(unk_0064);

    CSoftwareSprite::FreeSharedPalette();
    SaveData_ReleasePartnerVram(&MAIN_BSS_020B26A0);
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();

    RTCTime time;
    RTCDate date;
    RTC_GetTime(&time);
    RTC_GetDate(&date);
    MAIN_BSS_020B26A0.CheckElapsedTime(&time, &date);

    if (m_game->unk_0010 == 0) {
        SaveData_ReleaseAllActorData(&MAIN_BSS_020B26A0);
    }
}

struct UnkStruct_0201549C {
    inline void SetPos(Point2D pos)
    {
        unk_0C = pos.x;
        unk_10 = pos.y;
    }

    u8 unk_00[0xA];
    u16 unk_0A;
    fx32 unk_0C;
    fx32 unk_10;
    u8 unk_14[0x20];
    u16 unk_34;
};

extern "C" {
int SaveData_CountParty(SaveData *save, int arg1);
UnkStruct_0201549C *SaveData_FindPartner(SaveData *save, u32 id);
PartyEntry *SaveData_FindEntry(SaveData *save, u32 id);
void SaveData_EnableEnemy(SaveData *save, int idx, int mapId);
void SaveData_RemoveFromParty(SaveData *save, u32 id);
void SaveData_ClearActorPositions(SaveData *save);
int SaveData_GetPartyPartnerIndex(SaveData *save, int arg1);
int SaveData_HasPartnerInParty(SaveData *save, int arg1);
void ov0_02161F88(void);
void sub_0201094C(void *obj, int arg1);
void BattleStartParam_SetEnergy(void *obj, u8 arg1);
void BattleStartParam_SetStylerLevel(void *obj, u8 arg1);
void sub_02010964(void *obj, int arg1);
void sub_02010978(void *obj, u32 arg1);
void sub_02010980(void *obj, int arg1);
void BattleStartParam_SetPartnerMood(void *obj, u8 arg1);
void BattleStartParam_AddPartyMember(void *obj, u16 arg1, u32 arg2);
void BattleStartParam_SetCaptureBg(void *obj, int arg1);
void BattleStartParam_SetScreenEffect(void *obj, u8 arg1);
void sub_02010AC4(void *obj, int arg1);
void sub_02010B00(void *obj, u8 arg1);
void BattleStartParam_SetBannerType(void *obj, u16 arg1);
u32 BattleStartParam_GetOverrideFlags(void *obj);
}

extern u8 DAT_0208aaf8;

u32 CFieldScene::func0()
{
    if (m_flags & 0x10) {
        ov0_02124210();
        m_game->m_audioEngine->StopBgmReset(0);
        m_game->m_audioEngine->StopLoopSe(0);
        RTCTime time;
        RTCDate date;
        RTC_GetTime(&time);
        RTC_GetDate(&date);
        MAIN_BSS_020B26A0.CheckElapsedTime(&time, &date);
        return 0x22;
    }

    BOOL held;
    BOOL ok;
    int count;
    int i;
    void *record;
    u32 opts;
    SaveData *save = &MAIN_BSS_020B26A0;
    Point2D playerPos = m_player->GetPos();
    BOOL doUpdate = TRUE;
    u16 fps = 30;
    if (m_scriptLauncher->ov0_0213FEEC() != 0 || (m_flags & 0x48) || unk_0084 == 3 || unk_0084 == 4 || unk_0084 == 7 || unk_0084 == 5 || unk_0084 == 6 || unk_0084 == 8 || unk_0084 == 9 || unk_0084 == 0x14 || m_iconMenu->IsActive() != 0) {
        fps = 60;
    }
    m_game->unk_146C.SetFps(fps);
    DAT_0208d58c = fps;

    PadInput *pad = m_game->unk_0014;
    CTouchPanel *touch = m_game->activeTouchPanel;
    CBattleResultParameter *stats;
    BOOL updateActors;

    if (unk_00EC != 0) {
        updateActors = FALSE;
        doUpdate = FALSE;
        m_debugMenu->ov0_0214FB08();
        if (m_debugMenu->ov0_0214FB18() == FALSE) {
            m_debugMenu->ov0_0214FAA0();
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            unk_00EC = 0;
        }
    } else if (m_iconMenu->IsActive() != 0) {
        updateActors = FALSE;
        doUpdate = FALSE;
    } else {
        held = FALSE;
        BOOL canControl = (m_scriptLauncher->ov0_0213FEEC() == 0 && (m_flags & 0x1FE07B) == 0) ? TRUE : FALSE;
        ok = TRUE;
        if (canControl) {
            switch (unk_0084) {
            case 0:
                if (m_player->unk_110 == 0) {
                    int level = save->m_rangerClassGrade & 0xF;
                    if (SaveData_CountParty(save, -1) > SaveData_GetPartyCapacity(save, level)) {
                        m_game->m_mainFade->Start(4, 8);
                        m_game->m_subFade->Start(4, 8);
                        unk_0084 = 0x18;
                        break;
                    }
                    if (!(m_flags & 0x800)) {
                        Point2D touchPos = { (touch->unk_0A.x - 0x80) << FX32_SHIFT, (touch->unk_0A.y - 0x60) << FX32_SHIFT };
                        if (touch->unk_04 != 0) {
                            if (save->IsButton1Enabled()) {
                                if (PointInRect(touchPos, unk_004C->m_rect->m_rectangle, 0)) {
                                    unk_004C->ov0_0214FD24();
                                    m_flags |= 0x100;
                                }
                            }
                            if (save->IsButton2Enabled()) {
                                if (PointInRect(touchPos, unk_0050->m_rect->m_rectangle, 0)) {
                                    unk_0050->ov0_0214FF44();
                                    m_flags |= 0x200;
                                }
                            }
                        }
                        if (m_flags & 0x300) {
                            held = TRUE;
                        }
                        if (touch->unk_06 != 0) {
                            if (PointInRect(touchPos, unk_004C->m_rect->m_rectangle, 0) && (m_flags & 0x100)) {
                                m_subScreen->sub_02022D88();
                                m_game->m_audioEngine->PlaySe(0xFA);
                            }
                            if (PointInRect(touchPos, unk_0050->m_rect->m_rectangle, 0) && (m_flags & 0x200)) {
                                m_subScreen->SwitchToRangerCard();
                                m_iconMenu->Open();
                                if (m_player->m_drawObject != NULL && m_player->m_drawObject->m_actor != NULL) {
                                    m_player->m_drawObject->m_actor->m_motion.m_mode = 0;
                                }
                                m_game->m_audioEngine->PlaySe(0xFA);
                                ok = FALSE;
                                int state = m_player->m_drawObject->m_actor->unk_1A0;
                                if ((state == 0x80000 || state == 0x800000) && m_game->m_audioEngine->IsSePlaying(0x10E)) {
                                    m_game->m_audioEngine->StopSe(0x10E);
                                }
                            }
                            m_flags &= ~0x300;
                        }
                    }
                    if (m_screenEffects->IsEffectActive(5)) {
                        if ((save->unk_8BC0 + 2) % 300 < 2) {
                            m_player->ov0_021333A0(0, 0, 0, 1, 0);
                        }
                    }
                }
                if (save->m_energy == 0) {
                    switch (m_player->unk_110) {
                    case 0:
                    case 7:
                        if (save->m_areaType == 1) {
                            m_scriptLauncher->ov0_0213FB0C("sGameOverFS", 0, -2);
                        } else {
                            m_scriptLauncher->ov0_0213FB0C("sGameOverF", 0, -2);
                        }
                        m_flags |= 0x440;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        if (!m_game->m_mainFade->IsActive() && !m_game->m_subFade->IsActive()) {
                            if (m_player->m_drawObject != NULL && m_player->m_drawObject->m_actor != NULL) {
                                m_player->m_drawObject->m_actor->m_height = 0;
                            }
                            if (save->m_areaType == 1) {
                                m_scriptLauncher->ov0_0213FB0C("sGameOverFS", 0, -2);
                            } else {
                                m_scriptLauncher->ov0_0213FB0C("sGameOverF", 0, -2);
                            }
                            m_flags |= 0x440;
                            if (m_player->unk_110 == 3 && m_partners != NULL) {
                                m_partners->ov0_0213A96C(FALSE, 0, TRUE);
                            }
                        } else if (m_game->unk_0000 & 3) {
                            doUpdate = FALSE;
                        }
                        break;
                    }
                } else {
                    if (m_inputControl != NULL && ok && m_player->unk_110 == 0) {
                        ok = m_inputControl->ov0_0213FFC4(this, pad, held ? NULL : touch);
                    }
                }
                break;
            case 1: {
                CFieldPartner *partner = m_partnerPokemon;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    if (m_game->m_textboxData->GetYesNoResult() != 0) {
                        unk_0084 = 0;
                    } else {
                        ((CFieldTargetObject *)unk_0080)->ov0_0213CDB4(partner->m_id);
                        unk_0084 = 0x1A;
                    }
                    m_subScreen->SwitchToDefaultPanel();
                } else {
                    m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 10: {
                CFieldPartner *partner = m_partnerPokemon;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        UnkStruct_020107A8 *info = PokeIdTable_Get(m_game->unk_1434, partner->unk_200);
                        if (info->unk_05 != 0 && info->unk_05 == unk_0090 && unk_0098[0] != '\0') {
                            m_scriptLauncher->ov0_0213FB0C(unk_0098, partner->m_id, -1);
                        }
                    }
                    m_subScreen->SwitchToDefaultPanel();
                } else {
                    m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 11: {
                CFieldPartner *partner = m_partnerPokemon;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0084 = 0;
                        m_scriptLauncher->ov0_0213FB0C("sCharge", partner->m_id, -1);
                    } else {
                        unk_0084 = 0;
                    }
                    m_subScreen->SwitchToDefaultPanel();
                } else {
                    m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 12:
                if (++unk_0088 >= 60) {
                    CFieldPartner *partner = m_partnerPokemon;
                    if (!m_game->m_textboxData->IsActive()) {
                        ov0_0212451C();
                        m_game->m_textboxData->CloseAndClear(1, 1);
                        m_game->m_textboxData->ResetTextSpeed();
                        unk_0084 = 0;
                        m_subScreen->SwitchToDefaultPanel();
                    } else {
                        m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                    }
                }
                break;
            case 15: {
                CFieldPartner *partner = m_partnerPokemon;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        m_scriptLauncher->ov0_0213FB0C("sRideDodo", partner->m_id, -1);
                    }
                    m_subScreen->SwitchToDefaultPanel();
                } else {
                    m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 16:
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        m_scriptLauncher->ov0_0213FB0C("sGtOfDodo", 0, -1);
                    }
                }
                break;
            case 21: {
                CFieldPartner *partner = m_partnerPokemon;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0088 = 0;
                        unk_0084 = 0x16;
                        save->unk_8B80 = partner->m_id;
                        m_game->m_mainFade->Start(4, 10);
                        m_game->m_subFade->Start(4, 10);
                    } else {
                        m_subScreen->SwitchToDefaultPanel();
                    }
                } else {
                    m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 22:
                if (!m_game->m_mainFade->IsActive() && !m_game->m_subFade->IsActive()) {
                    unk_0084 = 0;
                    return 0xB;
                }
                break;
            case 23: {
                CFieldPartner *partner = m_partnerPokemon;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->CloseIfNoPrompt(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0084 = 0;
                        ov0_02161F88();
                        m_scriptLauncher->ov0_0213FB0C("sTeleport", partner->m_id, -1);
                    } else {
                        unk_0084 = 0;
                    }
                    m_subScreen->SwitchToDefaultPanel();
                } else {
                    m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 20:
                if (!m_game->m_textboxData->IsActive()) {
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                }
                break;
            case 24:
                if (!m_game->m_mainFade->IsActive() && !m_game->m_subFade->IsActive()) {
                    save->unk_8BA0 = ov0_02124604();
                    return 7;
                }
                break;
            case 25:
                if (!m_game->m_textboxData->IsActive()) {
                    m_game->m_textboxData->CloseAndClear(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    ov0_0212451C();
                    m_subScreen->SwitchToDefaultPanel();
                } else {
                    m_subScreen->SwitchToPokemonInfo(m_partnerPokemon->unk_200, 0);
                }
                break;
            }
        }

        if (m_iconMenu->IsActive() == 0) {
            BOOL canMove = (m_scriptLauncher->ov0_0213FF2C() == 0 && (m_flags & 0x1FE07B) == 0 && ok) ? TRUE : FALSE;
            if (canMove) {
                switch (unk_0084) {
                case 0x1A:
                    if (unk_0080->GetDCState() == 2) {
                        unk_0084 = 3;
                        unk_0088 = 0;
                        ov0_02124588(0x1F, 2);
                        m_partnerPokemon->m_flags |= 0x100;
                        unk_0080->m_flags |= 0x100;
                        m_player->SetFollow(m_partnerPokemon->m_id);
                    }
                    break;
                case 3:
                    if (++unk_0088 >= 2) {
                        unk_0084 = 4;
                        unk_0140 = -1;
                        m_partnerPokemon->ov0_0213E4BC(unk_0080->m_id);
                    }
                    break;
                case 4:
                    if (unk_0080->GetDCState() == 2) {
                        if ((m_partnerPokemon->unk_274 != NULL ? m_partnerPokemon->unk_274->unk_04 : 2) == 2) {
                            unk_0084 = 5;
                            unk_0088 = 0;
                            ov0_021245C4(2);
                        }
                    }
                    break;
                case 5:
                    if (++unk_0088 >= 2) {
                        unk_0084 = 6;
                        unk_0088 = 0;
                        m_cameraTarget = 0xFFFFFFFF;
                        Point2D pos = m_partnerPokemon->GetPos();
                        ov0_02124C30(&pos);
                        m_game->m_cameraController->MoveTo(1 - pos.x, 1 - pos.y, FX32_ONE);
                        m_player->m_flags &= ~0x100;
                        m_npcs->ClearOnTop();
                        m_enemies->ClearOnTop();
                        m_targetObjects->ClearOnTop();
                    }
                    break;
                case 6:
                    if (!m_game->m_cameraController->IsBusy()) {
                        unk_0084 = 7;
                        m_game->m_textboxData->SetParam(0, m_partnerPokemon->unk_268);
                        m_game->m_textboxData->SetTextSpeed(1);
                        m_game->m_textboxData->ShowSystemMessage(0x18, 1, 1, 0);
                    }
                    break;
                case 7:
                    if (++unk_0088 >= 60) {
                        m_game->m_textboxData->CloseAndClear(1, 1);
                        m_game->m_textboxData->ResetTextSpeed();
                        unk_0084 = 8;
                        Point2D target = { -m_camera->unk_1C, -m_camera->unk_20 };
                        m_partnerPokemon->StartMoveTo(target);
                    }
                    break;
                case 8:
                    if (!m_partnerPokemon->IsC8Set()) {
                        m_partners->ClearOnTop();
                        u32 id = m_partnerPokemon->m_id;
                        m_partners->ov0_0213A050((id & 0xFFFFFF) | 0x1000000);
                        PartyEntry *data = SaveData_FindEntry(save, id);
                        if (data != NULL) {
                            SaveData_EnableEnemy(save, data->m_index, data->m_mapId);
                            SaveData_RemoveFromParty(save, id);
                        }
                        ((CFieldTargetObject *)unk_0080)->ov0_0213CD3C();
                        m_player->sub_0201287C_();
                        Point2D pos = m_player->GetPos();
                        ov0_02124C30(&pos);
                        m_game->m_cameraController->MoveTo(1 - pos.x, 1 - pos.y, FX32_ONE);
                        unk_0084 = 9;
                    }
                    break;
                case 9:
                    if (!m_game->m_cameraController->IsBusy()) {
                        m_cameraTarget = 0;
                        unk_0084 = 0;
                    }
                    break;
                }
            }

            m_scriptLauncher->ov0_0213F9B0(unk_0084 == 0);
            if (m_scriptLauncher->ov0_0213FEEC() == 0 && (m_flags & 0x1FE07B) == 0 && unk_0084 == 0 && ok) {
                updateActors = TRUE;
            } else {
                updateActors = FALSE;
            }

            u8 mask = 0;
            if (!(unk_00E4->unk_00 & 2)) {
                mask |= 5;
            }
            if (!(unk_00E4->unk_00 & 8)) {
                mask |= 2;
            }
            m_player->unk_E8 = mask;

            if (doUpdate) {
                u32 playerFlags = (updateActors ? 1 : 0) | (save->m_areaType == 1 ? 2 : 0);
                if (unk_0078 == 0) {
                    m_player->ov0_021307B0(pad, held ? NULL : touch, m_camera, m_map, playerFlags);
                } else {
                    m_player->ov0_021307B0(NULL, NULL, m_camera, m_map, playerFlags);
                }
                Point2D pos = m_player->GetPos();
                Point2D tile;
                tile.x = (s16)(pos.x >> FX32_SHIFT) << FX32_SHIFT;
                tile.y = (s16)(pos.y >> FX32_SHIFT) << FX32_SHIFT;
                BOOL arg = (m_scriptLauncher->ov0_0213FEEC() == 0 && save->m_energy != 0 && ok) ? TRUE : FALSE;
                int hit = m_eventRects->Update(&tile, m_player->m_layer, arg);
                if (save->m_energy == 0 && m_player->unk_110 == 1 && hit != 0) {
                    m_player->SetPos(playerPos);
                }
                if (m_scriptLauncher->ov0_0213FEEC() == 0 && (m_flags & 0x1FE07B) == 0 && unk_0084 == 0 && ok && updateActors) {
                    updateActors = TRUE;
                } else {
                    updateActors = FALSE;
                }
                if (!(m_flags & 1)) {
                    if (updateActors) {
                        m_cannons->ov0_02159D7C();
                    }
                    m_targetObjects->UpdateAll(m_map, updateActors);
                    m_enemies->UpdateAll(m_map, updateActors);
                    m_partners->UpdateAll(m_map, updateActors);
                    m_npcs->UpdateAll(m_map, updateActors);
                }
                if (updateActors) {
                    m_cameraTarget = 0;
                }
            }
        } else {
            updateActors = FALSE;
            doUpdate = FALSE;
        }
    }

    Point2D pos = m_player->GetPos();
    int offset = m_player->GetBaseHeight();
    if (!((m_flags & 0x200000) ? TRUE : FALSE)) {
        save->SetPos(pos);
        save->m_dir = m_player->GetDir();
        save->m_layer = m_player->m_layer;
        m_subScreen->SetMapPos(pos.x >> FX32_SHIFT, pos.y >> FX32_SHIFT);
        save->unk_7F60 |= 1;
        for (int i = 0; i < m_enemies->m_count; i++) {
            CFieldActor *actor = m_enemies->Get(i);
            if (actor != NULL) {
                save->SetEnemy(i, actor->GetPos(), actor->GetDir());
            }
        }
        for (int i = 0; i < m_npcs->m_count; i++) {
            CFieldActor *actor = m_npcs->Get(i);
            if (actor != NULL) {
                save->SetNpc(i, actor->GetPos(), actor->GetDir());
            }
        }
        for (int i = 0; i < m_targetObjects->m_count; i++) {
            CFieldActor *actor = m_targetObjects->Get(i);
            if (actor != NULL) {
                save->SetObject(i, actor->GetPos(), actor->GetDir());
            }
        }
        for (int i = 0; i < m_partners->m_count; i++) {
            CFieldActor *actor = m_partners->Get(i);
            if (actor != NULL) {
                switch (((s32)actor->m_id >> 24) & 0xFF) {
                case 5: {
                    UnkStruct_0201549C *data = SaveData_FindPartner(save, actor->m_id);
                    if (data != NULL) {
                        data->SetPos(actor->GetPos());
                        data->unk_34 = actor->m_layer;
                        data->unk_0A = actor->GetDir();
                    }
                    break;
                }
                case 6: {
                    PartyEntry *data = SaveData_FindEntry(save, actor->m_id);
                    if (data != NULL) {
                        data->SetPos(actor->GetPos());
                        data->m_layer = actor->m_layer;
                        data->unk_14 = actor->GetDir();
                    }
                    break;
                }
                }
            }
        }
    }

    int target = m_cameraTarget;
    if (target != -1) {
        BOOL found = FALSE;
        Point2D camPos;
        if (target == 0) {
            camPos.y = pos.y;
            camPos.x = pos.x;
            if (m_player->unk_110 == 3) {
                camPos.y -= offset;
            }
            found = TRUE;
        } else {
            CFieldActor *actor;
            switch (((s32)target >> 24) & 0xFF) {
            case 0:
                break;
            case 1:
                actor = m_partners->FindPartner(target);
                if (actor == NULL) {
                    actor = m_enemies->Find(target);
                }
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            case 2:
                actor = m_partners->FindPartner(target);
                if (actor == NULL) {
                    actor = m_npcs->Find(target);
                }
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            case 3:
                actor = m_targetObjects->Find(target);
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            case 4:
            case 5:
            case 6:
                actor = m_partners->Find(target);
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            }
        }
        if (found) {
            if (m_flags & 4) {
                ov0_02124C30(&camPos);
            }
            camPos.x &= ~0xFFF;
            camPos.y &= ~0xFFF;
            m_camera->SetOrigin(camPos.x, camPos.y);
        }
    } else {
        m_game->m_cameraController->Update();
    }

    if (m_hpGauge != NULL) {
        if (!(m_flags & 1)) {
            m_hpGauge->SetCurrentHP(save->m_energy);
        }
        m_hpGauge->vfunc_08();
    }
    if (m_banner != NULL) {
        m_banner->Update();
    }
    if (unk_004C != NULL) {
        unk_004C->ov0_0214FCD0();
    }
    if (unk_0050 != NULL) {
        unk_0050->ov0_0214FEF0();
    }

    if (doUpdate) {
        if (updateActors) {
            switch (save->m_timerMode) {
            case 0:
                break;
            case 1:
                save->m_timer -= 60 / fps;
                if (save->m_timer < 0) {
                    save->m_timer = 0;
                }
                if (save->m_timerLimit > 0 && save->m_timer > save->m_timerLimit) {
                    save->m_timer = save->m_timerLimit;
                }
                if (save->m_timer <= 0) {
                    save->m_timerMode = 0;
                }
                break;
            case 2:
                save->m_timer += 60 / fps;
                if (save->m_timer < 0) {
                    save->m_timer = 0;
                }
                if (save->m_timerLimit > 0 && save->m_timer > save->m_timerLimit) {
                    save->m_timer = save->m_timerLimit;
                }
                int timer = save->m_timer;
                int limit = save->m_timerLimit;
                if (limit > 0 && timer >= limit) {
                    save->m_timerMode = 0;
                }
                break;
            }
            save->unk_8BC0 += 60 / fps;
        }
        if (m_map != NULL) {
            m_map->ov0_021251D8(1, fps);
        }
        if (m_effects != NULL) {
            m_effects->ov0_021428EC(fps, !updateActors);
        }
        if (m_screenEffects != NULL) {
            m_screenEffects->Update(fps);
        }
        if (m_shadow != NULL) {
            sub_02041920(m_shadow);
        }
        if (m_touchLine != NULL) {
            ov0_02121758(fps);
        }
        if ((m_flags & 0x80) && unk_00F4 > 0) {
            unk_00F0++;
            unk_00FA = LinearInterpolate(unk_00F8 << FX32_SHIFT, unk_00F9 << FX32_SHIFT, unk_00F0, unk_00F4) >> FX32_SHIFT;
            if (unk_00F0 >= unk_00F4) {
                unk_00F4 = 0;
                unk_00F0 = 0;
                if (unk_00FA == 0) {
                    m_flags &= ~0x80;
                    unk_00F8 = 0;
                    unk_00FA = 0;
                }
            }
        }
    }

    ov0_02124210();
    u32 flags = m_flags;
    if (flags & 0x20) {
        return 2;
    }
    if (flags & 0x2000) {
        return 3;
    }
    if (flags & 0x4000) {
        if (save->unk_81AC > 0 || save->m_saveCount == 0) {
            return 0x11;
        }
        return 0x19;
    }
    if (flags & 0x8000) {
        return 0x1A;
    }
    if (flags & 0x10000) {
        return 0x1B;
    }
    if (flags & 0x20000) {
        return 0x18;
    }
    if (flags & 0x40000) {
        return 0x14;
    }
    if (flags & 0x80000) {
        return 0x1D;
    }
    if (flags & 0x100000) {
        return 0x12;
    }

    if (flags & 1) {
        switch (unk_0084) {
        case 0xD:
            if (m_game->m_mainWipe->func0() || m_game->m_subWipe->func0() || m_game->m_mainFade->IsActive() || m_game->m_subFade->IsActive()) {
                break;
            }
            {
                int step = unk_0088 >> 1;
                if (step < 2) {
                    if (unk_0088 & 1) {
                        if (step < 1) {
                            m_game->m_mainFade->Start(2, 8);
                        } else {
                            m_game->m_mainFade->Start(2, 30);
                            if (m_game->m_subFade->GetMode() != 4 && m_game->m_subFade->GetMode() != 2) {
                                m_game->m_subFade->Start(4, 30);
                            }
                            m_game->m_audioEngine->StopJingle(60);
                        }
                    } else {
                        m_game->m_mainFade->Start(1, 8);
                    }
                    unk_0088++;
                    break;
                }
                unk_0084 = 0xE;
            }
        case 0xE:
            ov0_021244FC();
            record = m_game->unk_143C;
            stats = m_game->unk_1444;
            sub_0201094C(record, 5);
            opts = BattleStartParam_GetOverrideFlags(record);
            BattleStartParam_SetEnergy(record, save->m_energy);
            BattleStartParam_SetStylerLevel(record, save->m_stylerLevel);
            sub_02010978(record, save->unk_0004);
            sub_02010980(record, save->unk_0008 << FX32_SHIFT);
            BattleStartParam_SetPartnerMood(record, save->m_partnerMoods[SaveData_GetPartyPartnerIndex(save, -1)]);
            sub_02010964(record, SaveData_HasPartnerInParty(save, -1));
            sub_02010B00(record, save->unk_8803);
            count = 0;
            for (i = 0; i < 10; i++) {
                PartyEntry *data = SaveData_GetEntry(save, i);
                if (data != NULL && (data->m_flags & 1)) {
                    BattleStartParam_AddPartyMember(record, data->m_kind, !(data->m_flags & 4) | (data->m_flags & 2));
                    count++;
                }
            }
            stats->unk_6C = count;
            if (!(opts & 8)) {
                BattleStartParam_SetBannerType(record, ((u8)((save->m_rangerClassGrade >> 4) & 0xF) << 1) | save->m_sex);
            }
            if (!(opts & 1)) {
                BattleStartParam_SetCaptureBg(record, ov0_02124604());
            }
            if (!(opts & 2)) {
                if (m_screenEffects->IsEffectActive(9)) {
                    BattleStartParam_SetScreenEffect(record, 9);
                } else {
                    for (int i = 1; i < 0x11; i++) {
                        if (m_screenEffects->IsEffectActive(i)) {
                            BattleStartParam_SetScreenEffect(record, i);
                            break;
                        }
                    }
                }
            }
            if ((u8)((save->m_rangerClassGrade >> 4) & 0xF) == 0) {
                sub_02010AC4(record, 0);
            }
            return 0;
        default:
            if (m_game->m_missionQuestData->m_chapter == 0x10) {
                unk_0084 = 0xE;
            } else {
                unk_0084 = 0xD;
                m_game->m_mainFade->Start(2, 8);
            }
            m_game->m_audioEngine->PlayEncounterBgm();
            unk_0088 = 0;
            ov0_02123E58(-1);
            m_subScreen->SetIdleReturn(0);
            m_subScreen->unk_60 = 1;
            break;
        }
    } else {
        if (flags & 2) {
            DAT_0208aaf8 = 0;
            SaveData_ClearActorPositions(save);
            m_effects->ov0_021433D0();
            m_subScreen->HideAreaMap();
            m_subScreen->ClearMapIcons();
            ov0_021220D0(unk_0068, TRUE);
            ov0_021248DC();
            save->unk_8BC0 = 0;
            m_game->m_audioEngine->PlayMapBgm(unk_0068, 0, 0);
            ov0_02122EF4();
            fx32 y, x;
            x = unk_006C << FX32_SHIFT;
            y = unk_0070 << FX32_SHIFT;
            m_player->SetPosXY(x, y);
            if (unk_0074 >= 0) {
                m_player->sub_020128EC_(unk_0074);
                m_player->sub_0201287C_();
            }
            m_player->ResetMove();
            m_player->sub_show();
            m_player->ov0_021341E0();
            unk_0078 = 0;
            ov0_0212451C();
            m_partners->ov0_02139F98(x, y, m_player->m_layer);
            if (save->HasString()) {
                m_scriptLauncher->ov0_0213FB0C(save->m_saveName, 0, -1);
                save->m_saveName[0] = '\0';
            }
            m_subScreen->ShowAreaMap(unk_0068, unk_006C, unk_0070);
            ov0_021248EC();
        } else {
            m_game->AddVBlankCallback(ov0_021220AC, NULL);
        }
    }

    m_subScreen->Update();
    m_iconMenu->Update();
    int result = m_iconMenu->GetSelection();
    if (result >= 0) {
        ov0_021244DC();
        ov0_021244FC();
        switch (result) {
        case 0:
            return 3;
        case 1:
            break;
        case 2:
            return 10;
        case 3:
            return 0x16;
        case 4:
            return 0x17;
        case 5:
            break;
        case 6:
            return 4;
        case 8:
            return 0x1F;
        case 7:
            return 0x20;
        }
        save->unk_8BA0 = ov0_02124604();
        return 7;
    }
    if (touch->unk_05 == 0) {
        m_flags &= ~0x300;
    }
    return -1;
}

extern "C" {
void FieldData_GetEnemy(FieldData *obj, u32 arg1);
void ov0_02148480(TouchDotLine *obj, Point2D *pos, Point2D *target);
void ov0_021481EC(TouchDotLine *obj, int fps);
void ov0_0216D62C(UnkClass_0216D5F4 *obj, int time, int arg2, Camera2D *camera);
void ov0_02148288(TouchDotLine *obj, Camera2D *camera);
void SaveData_LotTimeCheck(SaveData *save);
void ScriptManager_UnloadArea(void *scriptManager);
void sub_020171B8(SaveData *save);
void sub_02017948(SaveData *save, int arg1);
void SaveData_EnableEventRect(SaveData *save, int idx, int mapId);
void SaveData_DisableEventRect(SaveData *save, int idx, int mapId);
BOOL SaveData_IsEventRectEnabled(SaveData *save, int idx, int mapId);
void SaveData_EnableNpc(SaveData *save, int idx, int mapId);
void SaveData_DisableNpc(SaveData *save, int idx, int mapId);
BOOL SaveData_IsNpcEnabled(SaveData *save, int idx, int mapId);
void SaveData_DisableEnemy(SaveData *save, int idx, int mapId);
BOOL SaveData_IsInParty(SaveData *save, int mapId, int idx);
void BattleStartParam_AddEnemy(void *record, u16 arg1, int arg2);
}

extern CFieldPlayer *MAIN_BSS_0210CA48;

struct UnkStruct_0210C1C0 {
    u8 unk_00[0x60];
    u8 unk_60;
    void *unk_64;
};

struct UnkStruct_0210C228 {
    u8 unk_000[0x800];
    u8 unk_800;
    void *unk_804;
};

extern UnkStruct_0210C1C0 MAIN_BSS_0210C1C0;
extern UnkStruct_0210C228 MAIN_BSS_0210C228;

extern "C" {
void sub_0202A4A0(UnkStruct_0210C1C0 *obj);
void sub_0202A4D8(UnkStruct_0210C228 *obj);
void SaveData_LoadPlayerActorData(SaveData *save, int arg1);
}

static inline void SetPoint(Point2D *dst, const Point2D *src)
{
    *dst = *src;
}

void CFieldScene::ov0_02121758(int fps)
{
    switch (unk_0078) {
    case 2: {
        CFieldPartner *partner = m_partnerPokemon;
        FieldData_GetEnemy(m_fieldData, partner->unk_200);
        UnkStruct_020107A8 *info = PokeIdTable_Get(m_game->unk_1434, partner->unk_200);
        if (info->unk_05 != 0 && info->unk_06 != 0) {
            Point2D pos;
            Point2D touchPos;
            Point2D hit;
            Point2D cam = m_camera->GetOffset();
            // The copy has to go through a pointer to the returned temporary to match.
            SetPoint(&pos, &(const Point2D &)m_partnerPokemon->GetPos());
            CTouchPanel *touch = m_game->activeTouchPanel;
            pos.y -= m_partnerPokemon->GetHeight();
            touchPos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
            touchPos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
            touchPos -= cam;
            CFieldMapLayerCollision *layer = m_map->GetLayer(m_player->m_layer);
            PointPair2D line = { pos, touchPos };
            if (layer->Sweep(&line, 0x4000, &hit, 1)) {
                touchPos = hit;
            }
            ov0_02148480(m_touchLine, &pos, &touchPos);
        }
        break;
    }
    case 3:
        break;
    }
    ov0_021481EC(m_touchLine, fps);
}

void CFieldScene::func1()
{
    SaveData *save = &MAIN_BSS_020B26A0;

    if (!(m_flags & 2)) {
        if (unk_00EC == 0) {
            BGFontPrinter *printer = m_game->GetPrinter();
            printer->unk_24 = 0;
            printer->Printf(0, 0, "");
            if (unk_00E4->unk_00 & 1) {
                s32 layerNo = m_player->m_layer;
                CFieldMapLayerCollision *layer = m_map->GetLayer(layerNo);
                CFieldMapLayerAttribute *attrLayer = m_map->GetAttributeLayer(layerNo);
                int cell = layer != NULL ? layer->GetCellAtPos(m_player->GetX(), m_player->GetY()) : -1;
                int attr = attrLayer != NULL ? attrLayer->GetCellAtPos(m_player->GetX(), m_player->GetY()) : -1;
                printer->Printf(0, 0, "FIELD (%d,%d,%d) : (%d,%d)", m_player->GetX() >> FX32_SHIFT, m_player->GetY() >> FX32_SHIFT, layerNo, cell, attr);
                if (unk_0084 == 4) {
                    printer->Printf(0, 1, "InTargetClearEvent");
                } else if (unk_0084 == 8) {
                    printer->Printf(0, 1, "InReleaseEventAfterTargetClear");
                } else if (m_scriptLauncher->ov0_0213FEEC()) {
                    printer->Printf(0, 1, "InAuthoringEvent");
                }
                if (unk_0090 >= 0) {
                    printer->Printf(0, 2, "FieldWaza(%d):%s", unk_0090, unk_0098);
                }
            }
            m_game->GetPrinter()->sub_020027E8();
        } else {
            m_game->GetPrinter()->sub_020027E8();
        }

        Point2D camPos = m_camera->GetOffset();
        m_hudCamera->ApplyProjection();
        m_hudCamera->ApplyView();
        G3_StoreMtx(0);
        if (!(m_flags & 0x800)) {
            if (m_hpGauge != NULL) {
                m_hpGauge->vfunc_0C(m_hudCamera);
            }
            if (unk_004C != NULL && save->IsButton1Enabled()) {
                unk_004C->ov0_0214FD00(m_hudCamera);
            }
            if (unk_0050 != NULL && save->IsButton2Enabled()) {
                unk_0050->ov0_0214FF20(m_hudCamera);
            }
        }

        if (!(m_flags & 0x1000)) {
            G3_Identity();
            m_camera->SetOffset(camPos);
            m_camera->ApplyProjection();
            m_camera->ApplyView();
            G3_StoreMtx(0);
            if (!(m_hiddenLayers & 1)) {
                m_player->Draw(m_drawLists, m_shadow);
            }
            if (!(m_flags & 0x400) && !(m_hiddenLayers & 4)) {
                m_enemies->DrawAll(m_drawLists, m_shadow);
            }
            if (!(m_hiddenLayers & 2)) {
                m_partners->DrawAll(m_drawLists, m_shadow);
            }
            if (!(m_hiddenLayers & 8)) {
                m_npcs->DrawAll(m_drawLists, m_shadow);
            }
            if (!(m_hiddenLayers & 0x10)) {
                m_targetObjects->DrawAll(m_drawLists, m_shadow);
            }
            if (!(m_flags & 0x40)) {
                m_cannons->ov0_02159DB4(m_drawLists, m_shadow);
            }
            m_effects->ov0_02143380(m_drawLists);
            for (int i = 0; i < 4; i++) {
                int budget = m_map->ov0_0212546C(i);
                DrawObjectList *list = &m_drawLists[i];
                int count = list->Draw(m_camera, budget);
                list->Clear();
                FieldShadow_Render(m_shadow, m_camera, i, budget - count);
                int total = count + 1;
                total += m_effects->ov0_0214336C(i, budget - total);
                list = &m_drawLists[i + 5];
                count = list->Draw(m_camera, budget - total);
                list->Clear();
                total += count;
                m_map->SetPolygonCount(i, total);
            }
            m_map->ov0_02125338(m_camera);
            m_effects->ov0_02142D88(m_camera);

            G3_Identity();
            m_camera->SetOffset(0, 0);
            m_camera->ApplyProjection();
            m_camera->ApplyView();
            G3_StoreMtx(0);
            if (m_screenEffects != NULL) {
                m_screenEffects->Draw(m_camera);
            }
            if (m_flags & 0x80) {
                unk_00FC.m_alpha = unk_00FA;
                unk_00FC.Render(m_camera);
            }
            if (unk_0064 != NULL) {
                SaveData *saveData = m_game->unk_14A4;
                if (saveData->unk_7F60 & 2) {
                    ov0_0216D62C(unk_0064, saveData->m_timerMode == 2 ? saveData->m_timer : saveData->m_timer + 59, 0x6A4, m_camera);
                }
            }

            G3_Identity();
            m_camera->SetOffset(camPos);
            m_camera->ApplyProjection();
            m_camera->ApplyView();
            G3_StoreMtx(0);
            DrawObjectList *list = &m_drawLists[4];
            int count = list->Draw(m_camera, 0x618);
            list->Clear();
            FieldShadow_Render(m_shadow, m_camera, 4, 0x618 - count);
            int total = count + 1;
            list = &m_drawLists[9];
            list->Draw(m_camera, 0x618 - total);
            list->Clear();
            FieldShadow_Clear(m_shadow);
            if (m_touchLine != NULL) {
                ov0_02148288(m_touchLine, m_camera);
            }
            m_eventRects->Draw(m_camera);
        }
        if (m_banner != NULL) {
            m_banner->Render();
        }
    }

    m_subScreen->sub_02022710();
    m_iconMenu->Render();
    m_flags &= ~2;
    unk_0068 = 0;
    unk_006C = 0;
    unk_0070 = 0;
    unk_0074 = 0;
}

void CFieldScene::func2()
{
    m_subScreen->Render();
    m_iconMenu->sub_02023470();
}

void CFieldScene::func3()
{
    m_subScreen->sub_020227AC();
    LoadOam();
}

void CFieldScene::func4()
{
    CScene::func4();
}

void CFieldScene::ov0_021220AC(void *arg0)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_map->ov0_02126658();
    }
}

static inline int GetMapMode(u8 type)
{
    switch (type) {
    case 1:
        return 1;
    case 5:
        return 2;
    default:
        return 0;
    }
}

BOOL CFieldScene::ov0_021220D0(u32 mapId, BOOL arg1)
{
    SaveData *save = &MAIN_BSS_020B26A0;

    if (unk_00CC >= 0) {
        m_npcs->Clear();
        m_enemies->Clear();
        m_targetObjects->Clear();
        FieldEventRectManage *items = m_eventRects;
        if (items->m_count > 0 && items->m_items != NULL) {
            for (int i = 0; i < items->m_count; i++) {
                SAFE_DELETE(items->m_items[i]);
            }
        }
        m_effects->ov0_02142F08();
        m_screenEffects->ClearSecondary();
        m_screenEffects->ClearPrimary();
        m_cannons->ov0_02159D70();
    }

    if (arg1) {
        for (int i = 0; i < 0x20; i++) {
            save->unk_81B4[i] = 0;
        }
        save->unk_81B0 = 0;
    }

    m_map->ov0_02124EE4();
    UnkStruct_02041D80 *newInfo = FieldData_GetMap(m_fieldData, mapId);
    if (unk_00CC >= 0) {
        u8 oldMode = GetMapMode(save->m_areaType);
        UnkStruct_02041D80 *oldInfo = FieldData_GetMap(m_fieldData, save->m_mapId);
        u8 newMode = GetMapMode(newInfo->unk_04);
        save->m_mapId = unk_0068;
        save->m_areaType = newInfo->unk_04;
        SaveData_LotTimeCheck(save);
        if (newInfo->unk_00 != oldInfo->unk_00) {
            m_game->m_textboxData->FreeAreaMessages();
            ScriptManager_UnloadArea(m_game->m_scriptManager);
        }
        if (oldMode != newMode) {
            m_partners->Clear();
            sub_020171B8(save);
            sub_02017948(save, 1);
            if (newMode != 1) {
                for (int i = 0; i < 2; i++) {
                    PartnerSlot *partner = save->GetPartner(i);
                    if (partner != NULL && partner->unk_00 != 0) {
                        int idx = m_partners->ov0_02139920(partner->unk_04, partner->unk_08, 0x1E16, 1, 1);
                        if (idx >= 0) {
                            CFieldActor *actor = m_partners->Get(idx);
                            if (actor != NULL) {
                                actor->SetPos((Point2D) { partner->unk_0C.x, partner->unk_0C.y });
                                actor->sub_020128EC_(partner->unk_0A);
                                actor->sub_0201287C_();
                                ((CFieldPartnerNpc *)actor)->SetName(partner->unk_14);
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < 10; i++) {
                PartyEntry *data = SaveData_GetEntry(save, i);
                if (data != NULL && (data->m_flags & 1)) {
                    u32 id = (data->m_index & 0xFFF) | ((6 << 24) | ((data->m_mapId & 0xFFF) << 12));
                    m_partners->ov0_02139920(id, data->m_kind, 0xE, 0, 1);
                }
            }
            if (oldMode == 1 || newMode == 1) {
                if (newInfo->unk_04 == 1) {
                    save->unk_8802 = TRUE;
                } else {
                    save->unk_8802 = FALSE;
                }
                m_player->ov0_02132FA0(save->unk_8802);
            }
        }
        if (newInfo->unk_00 != oldInfo->unk_00) {
            m_game->m_textboxData->LoadAreaMessages(newInfo->unk_00);
            ScriptManager_LoadArea(m_game->m_scriptManager, newInfo->unk_00);
        }
    }

    unk_00CC = mapId;
    UnkStruct_02041D80 *info = FieldData_GetMap(MAIN_BSS_0210CA6C, mapId);
    int group = info->unk_00;
    if (group >= 0 && group < 64) {
        save->unk_7F64 |= (u64)1 << group;
    }

    char name[0x80];
    u8 nameGroup = 0;
    if ((int)mapId > 0) {
        if (info->unk_02 == 0xFF) {
            OS_SPrintf(name, "m%03d_%03d", info->unk_00, info->unk_01);
        } else {
            OS_SPrintf(name, "m%03d_%03d%c", info->unk_00, info->unk_01, info->unk_02 + 'a');
        }
        nameGroup = info->unk_00;
    } else {
        strcpy(name, "test");
    }
    m_map->ov0_02125D28(nameGroup, name, m_game->unk_14A8);

    for (int i = 0; i < m_eventRects->m_count; i++) {
        CFieldEventRect *item = m_eventRects->Get(i);
        if (item != NULL) {
            if (save->GetEventRectState(mapId, i) == 0) {
                if (item->unk_18 != 0) {
                    SaveData_EnableEventRect(save, i, -1);
                } else {
                    SaveData_DisableEventRect(save, i, -1);
                }
            } else {
                if (SaveData_IsEventRectEnabled(save, i, -1)) {
                    item->unk_18 = 1;
                } else {
                    item->unk_18 = 0;
                }
            }
        }
    }

    for (int i = 0; i < m_npcs->m_count; i++) {
        CFieldActor *npc = m_npcs->Get(i);
        if (npc != NULL) {
            if (save->GetNpcState(mapId, i) == 0) {
                if (npc->IsActive()) {
                    SaveData_EnableNpc(save, i, -1);
                } else {
                    SaveData_DisableNpc(save, i, -1);
                }
            } else {
                if (SaveData_IsNpcEnabled(save, i, -1)) {
                    npc->unk_20 = 2;
                } else {
                    Actor_HideManpu(npc);
                    npc->unk_20 = 0;
                    npc->sub_0202D394();
                }
            }
        }
    }

    for (int i = 0; i < m_enemies->m_count; i++) {
        CFieldEnemy *enemy = (CFieldEnemy *)m_enemies->Get(i);
        if (enemy != NULL) {
            switch (save->GetEnemyState(mapId, i)) {
            case 0:
                if (enemy->IsActive()) {
                    SaveData_EnableEnemy(save, i, -1);
                } else {
                    SaveData_DisableEnemy(save, i, -1);
                }
                break;
            case 1:
                enemy->unk_20 = 0;
                break;
            case 2:
                if (arg1 && !SaveData_IsInParty(save, mapId, i)) {
                    if (enemy->unk_244 != 0) {
                        enemy->unk_20 = 0;
                        save->SetEnemyState(mapId, i, 1);
                    } else {
                        enemy->unk_20 = 2;
                        save->SetEnemyState(mapId, i, 3);
                    }
                } else {
                    enemy->unk_20 = 1;
                }
                break;
            case 3:
                if (!SaveData_IsInParty(save, save->m_mapId, i)) {
                    if (arg1 && enemy->unk_244 != 0) {
                        enemy->unk_20 = 0;
                        save->SetEnemyState(mapId, i, 1);
                    } else {
                        enemy->unk_20 = 2;
                        save->SetEnemyState(mapId, i, 3);
                    }
                } else {
                    enemy->unk_20 = 1;
                    save->SetEnemyState(mapId, i, 2);
                }
                break;
            case 4:
                enemy->unk_20 = 3;
                break;
            }
        }
    }

    for (int i = 0; i < m_targetObjects->m_count; i++) {
        CFieldActor *object = m_targetObjects->Get(i);
        if (object != NULL) {
            switch (save->GetObjectState(mapId, i)) {
            case 0:
                save->SetObjectState(mapId, i, object->unk_20 + 1);
                break;
            case 1:
                object->unk_20 = 0;
                break;
            case 2:
                object->unk_20 = 1;
                break;
            case 3:
                object->unk_20 = 2;
                break;
            case 4:
                object->sub_reset();
                object->PlayAnim(8, 0);
                break;
            }
        }
    }

    if (info->unk_03 != 0) {
        m_screenEffects->sub_02035D38(info->unk_03);
        m_screenEffects->StartEffect(info->unk_03, 0, -1, 0);
    }
    m_cameraTarget = 0;
    m_flags |= 4;
    unk_0078 = 0;
    m_partnerPokemon = 0;
    unk_0080 = 0;
    unk_0084 = 0;
    ov0_0212419C();
    m_enemies->ov0_02136384();
    m_game->m_audioEngine->StopLoopSe(0);
    if (info->unk_02 == 0xFF) {
        OS_SPrintf(name, "m%03d/m%03d_%03d.fsb", info->unk_00, info->unk_00, info->unk_01);
    } else {
        OS_SPrintf(name, "m%03d/m%03d_%03d%c.fsb", info->unk_00, info->unk_00, info->unk_01, info->unk_02 + 'a');
    }
    m_map->ov0_02124D98(name);
    FieldShadow_SetAlpha(m_shadow, info->unk_05);
    m_effects->ov0_02143410();
    return TRUE;
}

BOOL CFieldScene::ov0_02122EF4()
{
    m_map->ov0_02124E48();
    return TRUE;
}

static inline BOOL IsBossType(u16 type)
{
    return type >= 0x37 && type <= 0x3E;
}

void CFieldScene::ov0_02122F08(CFieldEnemy *enemy)
{
    if (m_flags & 1) {
        return;
    }
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    SaveData *save = &MAIN_BSS_020B26A0;
    if (enemy == NULL || player == NULL) {
        return;
    }
    if (player->unk_10C & 1) {
        return;
    }
    if (!(player->unk_E8 & 2) || save->m_energy == 0) {
        return;
    }
    BattleStartParam_Reset(m_game->unk_143C);
    sub_02010D04(m_game->unk_1444);
    ov0_02122FEC(enemy->unk_E8, enemy->unk_E0, enemy->m_id & 0xFFF);
    CBattleResultParameter *stats = m_game->unk_1444;
    if (IsBossType(enemy->unk_146)) {
        stats->unk_0C = 2;
    } else {
        stats->unk_0C = 0;
    }
    m_flags |= 1;
}

void CFieldScene::ov0_02122FEC(u32 arg0, u32 arg1, u32 arg2)
{
    BattleStartParam_AddEnemy(m_game->unk_143C, arg0, 0);
    CBattleResultParameter *stats = m_game->unk_1444;
    int n = stats->unk_14++;
    stats->unk_18[n] = (arg2 & 0xFFF) | ((1 << 24) | ((arg1 & 0xFFF) << 12));
    stats->unk_38[n] = arg0;
}

static inline u32 MakeActorId(u32 type, u32 id)
{
    return (id & 0xFFFFFF) | (type << 24);
}

// CFieldActorManage::Find written as a counted do-while. Case 2 of ov0_02123060 only matches with this form
// (with Find there, its count/actors get allocated before the later search loops and take ip/lr).
static inline CFieldActor *FindActorCounted(CFieldActorManage *mgr, u32 id)
{
    int count = mgr->m_count;
    if (count > 0) {
        CFieldActor **actors = mgr->m_actors;
        int i = 0;
        do {
            CFieldActor *actor = actors[i];
            if (actor != NULL && id == actor->m_id) {
                return actor;
            }
            i++;
        } while (i < count);
    }
    return NULL;
}

CFieldActor *CFieldScene::ov0_02123060(u32 id)
{
    CFieldActor *actor = NULL;
    if (id == 1) {
        return m_partners->FindLeader();
    }
    switch (((s32)id >> 24) & 0xFF) {
    case 0:
        actor = m_player;
        break;
    case 1:
        actor = m_partners->Find(MakeActorId(6, id));
        if (actor == NULL) {
            actor = m_enemies->Find(id);
        }
        break;
    case 2:
        actor = FindActorCounted(m_partners, MakeActorId(5, id));
        if (actor == NULL) {
            actor = m_npcs->Find(id);
        }
        break;
    case 3:
        actor = m_targetObjects->Find(id);
        break;
    case 4:
    case 5:
    case 6:
        actor = m_partners->Find(id);
        break;
    }
    return actor;
}

CFieldActor *CFieldScene::ov0_021232A8()
{
    CTouchPanel *touch = m_game->activeTouchPanel;
    Point2D pos;
    pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    pos.x -= m_camera->unk_1C;
    pos.y -= m_camera->unk_20;

    CFieldActor *hit = NULL;
    if (hit == NULL) {
        fx32 bestY = -0x800000;
        for (int i = 0; i < m_npcs->m_count; i++) {
            CFieldActor *npc = m_npcs->Get(i);
            if (npc != NULL && npc->IsActive() && !npc->IsHidden() && npc->IsTouched(pos)) {
                if (hit == NULL || npc->GetY() > bestY) {
                    hit = npc;
                    bestY = npc->GetY();
                }
            }
        }
    }
    if (hit == NULL) {
        SaveData *save = &MAIN_BSS_020B26A0;
        for (int i = m_partners->m_count - 1; i >= 0; i--) {
            CFieldPartner *partner = (CFieldPartner *)m_partners->Get(i);
            if (partner != NULL && partner->IsActive() && !partner->IsHidden() && partner->IsTouched(pos)) {
                if (save->m_areaType != 4 || !partner->IsKind0() || (partner->m_flags & 0x20)) {
                    hit = partner;
                    break;
                }
            }
        }
    }
    if (hit == NULL) {
        for (int i = m_targetObjects->m_count - 1; i >= 0; i--) {
            CFieldActor *object = m_targetObjects->Get(i);
            if (object != NULL && object->IsActive() && !object->IsHidden() && object->IsTouched(pos)) {
                hit = object;
                break;
            }
        }
    }
    if (m_player->IsTouched(pos)) {
        hit = m_player;
    }
    if (hit == NULL) {
        fx32 bestY = -0x800000;
        for (int i = 0; i < m_enemies->m_count; i++) {
            CFieldActor *enemy = m_enemies->Get(i);
            if (enemy != NULL && enemy->IsActive() && !enemy->IsHidden() && enemy->IsTouched(pos)) {
                if (hit == NULL || enemy->GetY() > bestY) {
                    hit = enemy;
                    bestY = enemy->GetY();
                }
            }
        }
    }
    return hit;
}

void CFieldScene::ov0_02123AEC(int state, int arg)
{
    unk_0084 = state;
    switch (state) {
    case 1:
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->ShowSystemMessage(7, 1, 1, 0);
        ov0_02123E58(-1);
        break;
    case 10:
        switch (arg) {
        default:
        case 0:
            m_game->m_textboxData->SetTextSpeed(0);
            m_game->m_textboxData->ShowSystemMessage(7, 1, 1, 0);
            break;
        case 1:
            m_game->m_textboxData->SetTextSpeed(0);
            m_game->m_textboxData->ShowSystemMessage(5, 1, 1, 0);
            break;
        }
        ov0_02123E58(-1);
        break;
    case 11:
        m_game->m_textboxData->SetParam(1, m_partnerPokemon->unk_268);
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->ShowSystemMessage(0x4B, 1, 1, 0);
        ov0_02123E58(-1);
        break;
    case 12:
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->ShowSystemMessage(0x4C, 1, 1, 0);
        ov0_02123E58(-1);
        break;
    case 15:
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->ShowSystemMessage(5, 1, 1, 0);
        ov0_02123E58(-1);
        break;
    case 21:
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->ShowSystemMessage(5, 1, 1, 0);
        ov0_02123E58(-1);
        break;
    case 16:
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->ShowSystemMessage(6, 1, 1, 0);
        ov0_02123E58(-1);
        break;
    case 23:
        m_game->m_textboxData->SetTextSpeed(0);
        m_game->m_textboxData->ShowSystemMessage(7, 1, 1, 0);
        ov0_02123E58(-1);
        break;
    case 25:
        ov0_02123E58(-1);
        break;
    case 20:
        ov0_02123E58(-1);
        break;
    }
}

void CFieldScene::ov0_02123E58(int flags)
{
    if (m_player != NULL && (flags & 1)) {
        if (!m_player->ov0_0213416C()) {
            m_player->StopMotion();
        }
        CFieldPlayer *player = m_player;
        player->unk_10C &= ~1;
        player->unk_E4 = 0;
        player->unk_140 = 0;
        player->sub_020129F4_(0, 0x1F);
        player->ClearEffectFlags(2);
    }
    if (m_partners != NULL && (flags & 2)) {
        FieldActorManage_StopAllMotion(m_partners);
    }
    if (m_npcs != NULL && (flags & 8)) {
        FieldActorManage_StopAllMotion(m_npcs);
    }
    if (m_targetObjects != NULL && (flags & 0x10)) {
        FieldActorManage_StopAllMotion(m_targetObjects);
    }
}

void CFieldScene::ov0_02123FEC(u32 arg0, int arg1)
{
    ov0_02124054();
    unk_00AA = m_effects->ov0_02142F6C(1, 0x25);
    CFieldEffect *effect = m_effects->ov0_02143088(unk_00AA);
    if (effect != NULL) {
        ((CFieldEffectManpu *)effect)->unk_1C = m_player;
        effect->ov0_021421F0(0, -1, 0);
    }
    unk_00B0 = arg0;
    unk_00AC = arg1;
}

void CFieldScene::ov0_02124054()
{
    if (unk_00AA != 0xFFFF) {
        CFieldEffect *effect = m_effects->ov0_02143088(unk_00AA);
        if (effect != NULL) {
            effect->ov0_02142240(0);
        }
        unk_00AA = 0xFFFF;
    }
    unk_00B0 = 0;
    unk_00AC = -1;
}

void CFieldScene::ov0_021240AC(int waza, int level, const char *name)
{
    if (waza < 0) {
        return;
    }
    if (name == NULL || name[0] == '\0') {
        return;
    }
    ov0_0212419C();
    unk_0090 = waza;
    unk_0094 = level;
    strcpy(unk_0098, name);
    int message = 0;
    switch (waza) {
    case 13:
        message = 0xB;
        break;
    case 14:
        message = 0xC;
        break;
    case 15:
        message = 0xF;
        break;
    case 16:
        message = 0x10;
        break;
    case 17:
        message = 0x11;
        break;
    case 18:
        message = 0xE;
        break;
    case 19:
        message = 0xD;
        break;
    case 21:
        message = level <= 1 ? 0x12 : 0x13;
        break;
    case 22:
        message = 0x14;
        break;
    case 23:
        message = 0x15;
        break;
    case 24:
        message = 0x5B;
        break;
    }
    ov0_02123FEC(0, message);
}

void CFieldScene::ov0_0212419C()
{
    unk_0090 = -1;
    unk_0098[0] = '\0';
    ov0_02124054();
}

void CFieldScene::ov0_021241B8()
{
    if (unk_00AC < 0) {
        return;
    }
    m_game->m_textboxData->ShowMessage(unk_00B0, unk_00AC, 1, 1, 0);
    ov0_02123AEC(0x14, 0);
}

void CFieldScene::ov0_02124210()
{
    SaveData *save = &MAIN_BSS_020B26A0;
    int mapId = save->m_mapId;

    for (int i = 0; i < m_eventRects->m_count; i++) {
        CFieldEventRect *item = m_eventRects->Get(i);
        if (item != NULL) {
            if (item->unk_18 != 0) {
                SaveData_EnableEventRect(save, i, -1);
            } else {
                SaveData_DisableEventRect(save, i, -1);
            }
        }
    }
    for (int i = 0; i < m_npcs->m_count; i++) {
        CFieldActor *npc = m_npcs->Get(i);
        if (npc != NULL) {
            save->SetNpcState(mapId, i, npc->unk_20 + 1);
        }
    }
    for (int i = 0; i < m_enemies->m_count; i++) {
        CFieldActor *enemy = m_enemies->Get(i);
        if (enemy != NULL) {
            save->SetEnemyState(mapId, i, enemy->unk_20 + 1);
        }
    }
    for (int i = 0; i < m_targetObjects->m_count; i++) {
        CFieldActor *object = m_targetObjects->Get(i);
        if (object != NULL) {
            save->SetObjectState(mapId, i, object->unk_20 + 1);
        }
    }
}

void CFieldScene::ov0_021244DC()
{
    sub_0202A4A0(&MAIN_BSS_0210C1C0);
    MAIN_BSS_0210C1C0.unk_60 = 1;
}

void CFieldScene::ov0_021244FC()
{
    sub_0202A4D8(&MAIN_BSS_0210C228);
    MAIN_BSS_0210C228.unk_800 = 1;
}

void CFieldScene::ov0_0212451C()
{
    m_player->ClearEffectFlags(1);
    m_npcs->ClearOutlines();
    m_enemies->ClearOutlines();
    m_targetObjects->ClearOutlines();
    m_partners->ClearOutlines();
}

void CFieldScene::ov0_02124588(int arg0, int arg1)
{
    m_flags |= 0x80;
    unk_00F0 = 0;
    unk_00F8 = 0;
    if (arg1 >= 0) {
        unk_00F4 = arg1;
        unk_00F9 = arg0;
        unk_00FA = 0;
    } else {
        unk_00F4 = 0;
        unk_00F9 = 0;
        unk_00FA = arg0;
    }
}

void CFieldScene::ov0_021245C4(int arg0)
{
    unk_00F0 = 0;
    unk_00F9 = 0;
    if (arg0 >= 0) {
        unk_00F4 = arg0;
        unk_00F8 = unk_00FA;
    } else {
        m_flags &= ~0x80;
        unk_00F4 = 0;
        unk_00F8 = 0;
        unk_00FA = 0;
    }
}

int CFieldScene::ov0_02124604()
{
    UnkStruct_02041D80 *info = FieldData_GetMap(m_fieldData, MAIN_BSS_020B26A0.m_mapId);
    u8 value = info->unk_06;
    int attr = 0;
    if (m_map != NULL && m_player != NULL) {
        Point2D pos = m_player->GetPos();
        CFieldMapLayerAttribute *attrLayer = m_map->GetAttributeLayer(m_player->m_layer);
        if (attrLayer != NULL) {
            attr = attrLayer->GetCellAtPos(pos.x, pos.y);
        }
    }
    switch (attr) {
    case 0:
        value = info->unk_06;
        break;
    case 1:
        value = info->unk_0A;
        break;
    case 2:
        value = info->unk_0E;
        break;
    case 3:
        value = info->unk_12;
        break;
    case 4:
        value = info->unk_16;
        break;
    case 5:
        value = info->unk_1A;
        break;
    case 6:
        value = info->unk_1E;
        break;
    case 7:
        value = info->unk_22;
        break;
    case 8:
        value = info->unk_26;
        break;
    case 9:
        value = info->unk_2A;
        break;
    case 10:
        value = info->unk_2E;
        break;
    case 11:
        value = info->unk_32;
        break;
    case 12:
        value = info->unk_36;
        break;
    case 13:
        value = info->unk_3A;
        break;
    case 14:
        value = info->unk_3E;
        break;
    case 15:
    case 16:
    case 17:
    case 18:
        value = info->unk_42;
        break;
    case 19:
    case 20:
    case 21:
    case 22:
        value = info->unk_46;
        break;
    }
    return value;
}

void CFieldScene::ov0_021247E4()
{
    m_flags |= 8;
    if (m_player != NULL && !m_player->ov0_0213416C()) {
        m_player->sub_show();
        m_player->sub_0201287C_();
        m_player->ResetMove();
        m_player->ov0_021341E0();
    }
    unk_0078 = 0;
    ov0_0212451C();
    if (m_partners != NULL) {
        m_partners->ov0_02139E9C();
    }
}

void CFieldScene::ov0_021248DC()
{
    m_flags &= ~8;
}

void CFieldScene::ov0_021248EC()
{
    if (m_targetObjects != NULL && m_subScreen != NULL) {
        for (int i = 0; i < m_targetObjects->m_count; i++) {
            CFieldTargetObject *object = (CFieldTargetObject *)m_targetObjects->Get(i);
            if (object != NULL && object->IsActive() && !object->IsHidden()) {
                switch (object->unk_E8) {
                case 0x16E:
                    m_subScreen->AddMapIcon(object->GetX() >> FX32_SHIFT, object->GetY() >> FX32_SHIFT, TRUE);
                    break;
                case 0x16F:
                    m_subScreen->AddMapIcon(object->GetX() >> FX32_SHIFT, object->GetY() >> FX32_SHIFT, FALSE);
                    break;
                }
            }
        }
    }
    if (m_npcs != NULL && m_subScreen != NULL) {
        for (int i = 0; i < m_npcs->m_count; i++) {
            CFieldNpc *npc = (CFieldNpc *)m_npcs->Get(i);
            if (npc != NULL && npc->IsActive() && !npc->IsHidden() && npc->unk_E8 == 0) {
                switch (npc->unk_EC) {
                case 0x5C:
                    m_subScreen->AddMapIcon(npc->GetX() >> FX32_SHIFT, npc->GetY() >> FX32_SHIFT, TRUE);
                    break;
                case 0x90:
                    m_subScreen->AddMapIcon(npc->GetX() >> FX32_SHIFT, npc->GetY() >> FX32_SHIFT, FALSE);
                    break;
                }
            }
        }
    }
}

extern "C" void ov0_02124BD4(void)
{
    // Through void * so the address stays in a register (a plain &MAIN_BSS_020B26A0 is reloaded per call).
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    SaveData_LoadPlayerActorData(save, -1);
    sub_02017948(save, 0);
}

BOOL CFieldScene::ov0_02124BFC()
{
    if (m_scriptLauncher->ov0_0213FEEC() != 0 || (m_flags & 0x49)) {
        return FALSE;
    }
    return TRUE;
}

BOOL CFieldScene::ov0_02124C30(Point2D *pos)
{
    BOOL clamped = FALSE;
    if (pos != NULL && m_map != NULL) {
        if (pos->x < FX32_CONST(128)) {
            pos->x = FX32_CONST(128);
            clamped = TRUE;
        }
        if (pos->y < FX32_CONST(96)) {
            pos->y = FX32_CONST(96);
            clamped = TRUE;
        }
        if (pos->x > (m_map->m_info.size.width - 128) << FX32_SHIFT) {
            pos->x = (m_map->m_info.size.width - 128) << FX32_SHIFT;
            clamped = TRUE;
        }
        if (pos->y > (m_map->m_info.size.height - 96) << FX32_SHIFT) {
            pos->y = (m_map->m_info.size.height - 96) << FX32_SHIFT;
            clamped = TRUE;
        }
        pos->x &= ~(FX32_ONE - 1);
        pos->y &= ~(FX32_ONE - 1);
    }
    return clamped;
}

u32 CFieldScene::getSceneId()
{
    return 1;
}
