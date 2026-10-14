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
void sub_02017E44(SaveData *save);
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
    unk_008C = 0;
    unk_007C = 0;
    unk_0080 = 0;
    unk_00D0 = 0;
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
    m_game->m_textboxData->Init(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->unk_14B0, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);

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

    unk_0038 = MAIN_BSS_0210CA6C;
    mapInfo = FieldData_GetMap(unk_0038, save->m_mapId);
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
    u8 quest = m_game->m_missionQuestData->unk_03;
    if (quest != 0) {
        m_game->m_textboxData->LoadQuestMessages(quest);
        ScriptManager_LoadQuest(m_game->m_scriptManager, quest);
    }

    if (save->unk_8B74 & 1) {
        unk_00D0 |= 0x440;
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

    unk_00E0 = new FieldSyscallSets();
    unk_00E0->ov0_0213D658();

    unk_0008 = new Camera2D();
    unk_0008->SetOrtho(0, 0xC0000, 0, 0x100000, -0x800000, 0x800000, 0x10000);
    m_game->unk_14B8->SetTarget((UnkStruct_0200D3F8_Target *)unk_0008);

    unk_000C = new Camera2D();
    unk_000C->SetOrtho(0, 0xC0000, 0, 0x100000, -0x800000, 0x800000, 0x400000);
    Camera2D *camera = unk_000C;
    camera->unk_1C = 0;
    camera->unk_20 = 0;

    unk_0044 = new FieldDrawActorDataPool();

    unk_001C = new CFieldPartnerManage();
    unk_001C->Alloc(0x10);
    unk_0144.ov0_02143730(unk_001C);

    unk_0020 = new CFieldNpcManage();
    unk_0020->Alloc(0x20);
    unk_0018 = new CFieldEnemyManage();
    unk_0018->Alloc(0x20);
    unk_0024 = new CFieldTargetObjectManage();
    unk_0024->Alloc(0x20);

    unk_0030 = new FieldEventRectManage();
    unk_0030->Create(0x30);
    unk_0034 = new FieldScriptLauncher(m_game);
    unk_0034->ov0_0213F960();

    unk_00D8 = new CPlayerHPGauge();
    unk_00D8->SetVisible(TRUE);
    unk_00D8->SetPartnerVisible(FALSE);
    unk_00D8->SetHP(save->m_energy, save->m_maxEnergy);
    unk_00D8->SetPartner(save->unk_0004 >> FX32_SHIFT, save->unk_0008);
    unk_00D8->SetZ(0x3FF);

    unk_004C = new UnkClass_0214FB28();
    unk_0050 = new UnkClass_0214FD4C();
    unk_004C->m_z = 0x424;
    unk_0050->m_z = 0x424;

    unk_0054 = new FieldSubScreen(m_game);
    unk_0058 = new SubScreenIconMenu(m_game);
    unk_005C = new FieldCannons();
    unk_0010 = new CFieldMap();

    unk_0014 = new CFieldPlayer();
    unk_0014->ov0_02132F14(save->m_sex, (save->m_rangerClassGrade >> 4) & 0xF, mapInfo->unk_04);
    unk_0014->ov0_02132FA0(save->unk_8802);
    if (flag2) {
        unk_0014->sub_flag2();
    }
    unk_0014->SetPos(save->GetPos());
    unk_0014->sub_020128EC_(save->m_dir);
    unk_0014->sub_0201287C_();
    unk_0014->SetLayer(save->m_layer);

    unk_0078 = 0;
    unk_007C = 0;
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
            UnkStruct_020B26A0_8AD4 *partner = save->GetPartner(i);
            if (partner != NULL && partner->unk_00 != 0) {
                int idx = unk_001C->ov0_02139920(partner->unk_04, partner->unk_08, 0x1E16, 1, 1);
                if (idx >= 0) {
                    CFieldActor *actor = unk_001C->Get(idx);
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
        UnkStruct_020155FC *data = SaveData_GetEntry(save, i);
        if (data != NULL && (data->unk_08 & 1)) {
            u32 id = (data->unk_04 & 0xFFF) | ((6 << 24) | ((data->unk_02 & 0xFFF) << 12));
            if (id != 0) {
                int idx = unk_001C->ov0_02139920(id, data->unk_00, 0xE, 0, 1);
                if (idx >= 0) {
                    CFieldActor *actor = unk_001C->Get(idx);
                    if (actor != NULL) {
                        if (id == save->unk_7C38) {
                            Actor_HideManpu(actor);
                            actor->unk_20 = 0;
                            actor->sub_0202D394();
                        } else {
                            actor->SetPos((Point2D) { data->unk_0C.x, data->unk_0C.y });
                            actor->SetLayer(data->unk_16);
                            actor->sub_020128EC_(data->unk_14);
                            actor->sub_0201287C_();
                        }
                    }
                }
            }
        }
    }

    if (save->unk_8802 != 0 && save->unk_8802 != 1) {
        unk_001C->sub_02040460();
        if (save->unk_8802 != 2) {
            unk_001C->ov0_02139E14(4);
            unk_001C->ov0_0213A7FC(0);
            CFieldActor *actor = unk_001C->Find(save);
            if (actor != NULL) {
                actor->unk_04 &= ~1;
            }
        }
    }

    unk_003C = new DrawObjectList[10];
    unk_0060 = new TitleBanner();
    unk_0028 = new CFieldEffectManage(&unk_0144);
    unk_013C.ov0_021518B8(unk_0028);
    unk_002C = new FieldScreenEffectManage();
    unk_0048 = new FieldShadow(5);

    unk_00DC = new TouchDotLine();
    if (unk_00DC != NULL) {
        CellAnimController *cac = unk_0028->m_resident.GetCac(6);
        CNCERFile *ncer = unk_0028->m_resident.GetNcer(6);
        VramPalette *palette = unk_0028->m_resident.GetPalette();
        VramImage *ncbr = unk_0028->m_resident.GetNcbr(0);
        ov0_0214816C(unk_00DC, ncbr, palette, ncer, cac);
    }

    m_game->unk_14B8->SetTarget((UnkStruct_0200D3F8_Target *)unk_0008);
    unk_0040 = new CFieldPlayerInputControlManage();
    if (unk_00D8 != NULL) {
        unk_0064 = new UnkClass_0216D5F4();
        ov0_0216D5F4(unk_0064, unk_00D8->GetPart(1));
    }
    unk_00E4 = new UnkClass_0214B984();
    unk_00E8 = new FieldDebugMenu(m_game);

    m_game->m_textboxData->LoadAreaMessages(mapInfo->unk_00);
    ScriptManager_LoadArea(m_game->m_scriptManager, mapInfo->unk_00);
    ov0_021220D0(save->m_mapId, fromTable);

    if (sceneId != 5 && sceneId != 7) {
        BOOL handled = FALSE;
        if (sceneId == 0x19 || sceneId == 0xE || sceneId == 0x1E) {
            handled = m_game->sub_02010378();
        }
        if (!handled) {
            m_game->m_audioEngine->PlayMapBgm(save->m_mapId, 0, 0);
            if (unk_00D0 & 0x40) {
                m_game->m_audioEngine->LoadBgmGroup(0x2D);
                m_game->m_audioEngine->PlayBgm(5, 30);
            }
        }
    }

    unk_00AA = 0xFFFF;
    unk_00AC = -1;
    unk_00B0 = 0;

    if (unk_001C != NULL) {
        for (int i = 0; i < 16; i++) {
            CFieldActor *actor = unk_001C->Get(i);
            if (actor != NULL && actor->IsActive()) {
                positions[i] = actor->GetPos();
                directions[i] = actor->GetDir();
            }
        }
    }

    ov0_02122EF4();

    if (unk_001C != NULL) {
        for (int i = 0; i < 16; i++) {
            CFieldActor *actor = unk_001C->Get(i);
            if (actor != NULL && actor->IsActive()) {
                actor->SetPos(positions[i]);
                actor->sub_020128EC_(directions[i]);
                actor->sub_0201287C_();
                static_cast<CFieldPartner *>(actor)->unk_EC.ov0_02158F38();
            }
        }
    }

    if (save->unk_7F60 & 1) {
        for (int i = 0; i < unk_0018->m_count; i++) {
            CFieldActor *actor = unk_0018->Get(i);
            if (actor != NULL && actor->IsActive()) {
                actor->SetPos(save->GetEnemyPos(i));
                actor->sub_020128EC_(save->m_enemyDir[i]);
                actor->sub_0201287C_();
            }
        }
        for (int i = 0; i < unk_0020->m_count; i++) {
            CFieldActor *actor = unk_0020->Get(i);
            if (actor != NULL) {
                actor->SetPos(save->GetNpcPos(i));
                actor->sub_020128EC_(save->m_npcDir[i]);
                actor->sub_0201287C_();
                ((CFieldNpc *)actor)->ov0_0213C5DC();
            }
        }
        for (int i = 0; i < unk_0024->m_count; i++) {
            CFieldActor *actor = unk_0024->Get(i);
            if (actor != NULL) {
                actor->SetPos(save->GetObjectPos(i));
                actor->sub_020128EC_(save->m_objectDir[i]);
                actor->sub_0201287C_();
            }
        }
        unk_005C->ov0_02159970();
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
                CFieldActor *actor = unk_0024->Get(i);
                actor->sub_020129F4_(0, 0);
                actor->Update(NULL);
            }
        }
    }

    CFieldMapLayerAttribute *attrLayer = unk_0010->GetAttributeLayer(unk_0014->unk_14);
    if (attrLayer != NULL) {
        int result = attrLayer->GetCellAtPos(unk_0014->GetX(), unk_0014->GetY());
        if (result == 0xE || result == 0x17) {
            if (unk_001C != NULL) {
                unk_001C->ov0_0213A7FC(0);
            }
            if (unk_0014 != NULL) {
                unk_0014->sub_reset();
                unk_0014->PlayAnim(0x80, 0);
            }
        }
    }

    if (save->HasString()) {
        unk_0034->ov0_0213FB0C(save->m_saveName, 0, -1);
        save->m_saveName[0] = '\0';
    } else if (doorEventId > 0) {
        unk_0034->ov0_0213FB0C("sDokaRelease", doorEventId, -1);
    } else {
        switch (m_game->unk_14BC->GetMode()) {
        case 2:
            m_game->unk_14BC->Start(1, 10);
            break;
        case 4:
            m_game->unk_14BC->Start(3, 10);
            break;
        }
        switch (m_game->unk_14C0->GetMode()) {
        case 2:
            m_game->unk_14C0->Start(1, 10);
            break;
        case 4:
            m_game->unk_14C0->Start(3, 10);
            break;
        }
    }

    SetupBGFonts();
    unk_0054->ShowAreaMap(save->m_mapId, unk_0014->GetX() >> FX32_SHIFT, unk_0014->GetY() >> FX32_SHIFT);
    ov0_021248EC();
    if (sceneId == 6) {
        unk_0054->sub_02022C74();
        unk_0058->sub_020234F0();
    }
    unk_0028->ov0_021434F0();
    unk_0018->ov0_02136878();
}

void CFieldScene::func7()
{
    ScriptManager_UnloadAll(m_game->m_scriptManager);
    m_game->m_textboxData->FreeAreaMessages();
    m_game->m_textboxData->FreeSystemMessages();
    m_game->m_textboxData->FreeChapterMessages();
    m_game->m_textboxData->FreeQuestMessages();
    m_game->m_textboxData->Reset();
    m_game->unk_14B8->SetTarget(NULL);

    SAFE_DELETE(unk_0040);
    SAFE_DELETE(unk_00DC);
    SAFE_DELETE(unk_002C);
    SAFE_DELETE(unk_0028);
    SAFE_DELETE(unk_0048);
    SAFE_DELETE_ARRAY(unk_003C);
    SAFE_DELETE(unk_0014);
    SAFE_DELETE(unk_0010);
    unk_013C.ov0_021518F4();
    SAFE_DELETE(unk_0034);
    SAFE_DELETE(unk_0030);
    SAFE_DELETE(unk_0024);
    SAFE_DELETE(unk_0018);
    SAFE_DELETE(unk_0020);
    unk_0144.ov0_02143760(unk_001C);
    SAFE_DELETE(unk_001C);
    SAFE_DELETE(unk_0044);
    SAFE_DELETE(unk_0008);
    SAFE_DELETE(unk_000C);
    SAFE_DELETE(unk_00E0);
    SAFE_DELETE(unk_00D8);
    SAFE_DELETE(unk_004C);
    SAFE_DELETE(unk_0050);
    SAFE_DELETE(unk_00E4);
    SAFE_DELETE(unk_00E8);
    SAFE_DELETE(unk_0054);
    SAFE_DELETE(unk_0058);
    SAFE_DELETE(unk_005C);
    SAFE_DELETE(unk_0060);
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
        sub_02017E44(&MAIN_BSS_020B26A0);
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
int sub_02016138(SaveData *save, int arg1);
UnkStruct_0201549C *SaveData_FindPartner(SaveData *save, u32 id);
UnkStruct_020155FC *SaveData_FindEntry(SaveData *save, u32 id);
void sub_02015A3C(SaveData *save, int idx, int mapId);
void sub_02015E54(SaveData *save, u32 id);
void SaveData_ClearActorPositions(SaveData *save);
int sub_02016268(SaveData *save, int arg1);
int sub_0201621C(SaveData *save, int arg1);
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
    if (unk_00D0 & 0x10) {
        ov0_02124210();
        m_game->m_audioEngine->StopBgmReset(0);
        m_game->m_audioEngine->sub_02034C2C(0);
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
    Point2D playerPos = unk_0014->GetPos();
    BOOL doUpdate = TRUE;
    u16 fps = 30;
    if (unk_0034->ov0_0213FEEC() != 0 || (unk_00D0 & 0x48) || unk_0084 == 3 || unk_0084 == 4 || unk_0084 == 7 || unk_0084 == 5 || unk_0084 == 6 || unk_0084 == 8 || unk_0084 == 9 || unk_0084 == 0x14 || unk_0058->IsActive() != 0) {
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
        unk_00E8->ov0_0214FB08();
        if (unk_00E8->ov0_0214FB18() == FALSE) {
            unk_00E8->ov0_0214FAA0();
            G2_SetBlendBrightness(GX_BLEND_PLANEMASK_NONE, 0);
            unk_00EC = 0;
        }
    } else if (unk_0058->IsActive() != 0) {
        updateActors = FALSE;
        doUpdate = FALSE;
    } else {
        held = FALSE;
        BOOL canControl = (unk_0034->ov0_0213FEEC() == 0 && (unk_00D0 & 0x1FE07B) == 0) ? TRUE : FALSE;
        ok = TRUE;
        if (canControl) {
            switch (unk_0084) {
            case 0:
                if (unk_0014->unk_110 == 0) {
                    int level = save->m_rangerClassGrade & 0xF;
                    if (sub_02016138(save, -1) > sub_02015658(save, level)) {
                        m_game->unk_14BC->Start(4, 8);
                        m_game->unk_14C0->Start(4, 8);
                        unk_0084 = 0x18;
                        break;
                    }
                    if (!(unk_00D0 & 0x800)) {
                        Point2D touchPos = { (touch->unk_0A.x - 0x80) << FX32_SHIFT, (touch->unk_0A.y - 0x60) << FX32_SHIFT };
                        if (touch->unk_04 != 0) {
                            if (save->IsButton1Enabled()) {
                                if (PointInRect(touchPos, unk_004C->m_rect->m_rectangle, 0)) {
                                    unk_004C->ov0_0214FD24();
                                    unk_00D0 |= 0x100;
                                }
                            }
                            if (save->IsButton2Enabled()) {
                                if (PointInRect(touchPos, unk_0050->m_rect->m_rectangle, 0)) {
                                    unk_0050->ov0_0214FF44();
                                    unk_00D0 |= 0x200;
                                }
                            }
                        }
                        if (unk_00D0 & 0x300) {
                            held = TRUE;
                        }
                        if (touch->unk_06 != 0) {
                            if (PointInRect(touchPos, unk_004C->m_rect->m_rectangle, 0) && (unk_00D0 & 0x100)) {
                                unk_0054->sub_02022D88();
                                m_game->m_audioEngine->PlaySe(0xFA);
                            }
                            if (PointInRect(touchPos, unk_0050->m_rect->m_rectangle, 0) && (unk_00D0 & 0x200)) {
                                unk_0054->sub_02022C1C();
                                unk_0058->Open();
                                if (unk_0014->unk_08 != NULL && unk_0014->unk_08->unk_0C != NULL) {
                                    unk_0014->unk_08->unk_0C->m_motion.m_mode = 0;
                                }
                                m_game->m_audioEngine->PlaySe(0xFA);
                                ok = FALSE;
                                int state = unk_0014->unk_08->unk_0C->unk_1A0;
                                if ((state == 0x80000 || state == 0x800000) && m_game->m_audioEngine->IsSePlaying(0x10E)) {
                                    m_game->m_audioEngine->StopSe(0x10E);
                                }
                            }
                            unk_00D0 &= ~0x300;
                        }
                    }
                    if (unk_002C->IsEffectActive(5)) {
                        if ((save->unk_8BC0 + 2) % 300 < 2) {
                            unk_0014->ov0_021333A0(0, 0, 0, 1, 0);
                        }
                    }
                }
                if (save->m_energy == 0) {
                    switch (unk_0014->unk_110) {
                    case 0:
                    case 7:
                        if (save->m_areaType == 1) {
                            unk_0034->ov0_0213FB0C("sGameOverFS", 0, -2);
                        } else {
                            unk_0034->ov0_0213FB0C("sGameOverF", 0, -2);
                        }
                        unk_00D0 |= 0x440;
                        break;
                    case 1:
                    case 2:
                    case 3:
                        if (!m_game->unk_14BC->IsActive() && !m_game->unk_14C0->IsActive()) {
                            if (unk_0014->unk_08 != NULL && unk_0014->unk_08->unk_0C != NULL) {
                                unk_0014->unk_08->unk_0C->unk_8C = 0;
                            }
                            if (save->m_areaType == 1) {
                                unk_0034->ov0_0213FB0C("sGameOverFS", 0, -2);
                            } else {
                                unk_0034->ov0_0213FB0C("sGameOverF", 0, -2);
                            }
                            unk_00D0 |= 0x440;
                            if (unk_0014->unk_110 == 3 && unk_001C != NULL) {
                                unk_001C->ov0_0213A96C(FALSE, 0, TRUE);
                            }
                        } else if (m_game->unk_0000 & 3) {
                            doUpdate = FALSE;
                        }
                        break;
                    }
                } else {
                    if (unk_0040 != NULL && ok && unk_0014->unk_110 == 0) {
                        ok = unk_0040->ov0_0213FFC4(this, pad, held ? NULL : touch);
                    }
                }
                break;
            case 1: {
                CFieldPartner *partner = unk_007C;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->sub_0200B6A4(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    if (m_game->m_textboxData->GetYesNoResult() != 0) {
                        unk_0084 = 0;
                    } else {
                        ((CFieldTargetObject *)unk_0080)->ov0_0213CDB4(partner->unk_58);
                        unk_0084 = 0x1A;
                    }
                    unk_0054->sub_02022DD4();
                } else {
                    unk_0054->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 10: {
                CFieldPartner *partner = unk_007C;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->sub_0200B6A4(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        UnkStruct_020107A8 *info = PokeIdTable_Get(m_game->unk_1434, partner->unk_200);
                        if (info->unk_05 != 0 && info->unk_05 == unk_0090 && unk_0098[0] != '\0') {
                            unk_0034->ov0_0213FB0C(unk_0098, partner->unk_58, -1);
                        }
                    }
                    unk_0054->sub_02022DD4();
                } else {
                    unk_0054->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 11: {
                CFieldPartner *partner = unk_007C;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->sub_0200B6A4(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0084 = 0;
                        unk_0034->ov0_0213FB0C("sCharge", partner->unk_58, -1);
                    } else {
                        unk_0084 = 0;
                    }
                    unk_0054->sub_02022DD4();
                } else {
                    unk_0054->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 12:
                if (++unk_0088 >= 60) {
                    CFieldPartner *partner = unk_007C;
                    if (!m_game->m_textboxData->IsActive()) {
                        ov0_0212451C();
                        m_game->m_textboxData->sub_02009FB0(1, 1);
                        m_game->m_textboxData->ResetTextSpeed();
                        unk_0084 = 0;
                        unk_0054->sub_02022DD4();
                    } else {
                        unk_0054->SwitchToPokemonInfo(partner->unk_200, 0);
                    }
                }
                break;
            case 15: {
                CFieldPartner *partner = unk_007C;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->sub_0200B6A4(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0034->ov0_0213FB0C("sRideDodo", partner->unk_58, -1);
                    }
                    unk_0054->sub_02022DD4();
                } else {
                    unk_0054->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 16:
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->sub_0200B6A4(1)) {
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0034->ov0_0213FB0C("sGtOfDodo", 0, -1);
                    }
                }
                break;
            case 21: {
                CFieldPartner *partner = unk_007C;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->sub_0200B6A4(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0088 = 0;
                        unk_0084 = 0x16;
                        save->unk_8B80 = partner->unk_58;
                        m_game->unk_14BC->Start(4, 10);
                        m_game->unk_14C0->Start(4, 10);
                    } else {
                        unk_0054->sub_02022DD4();
                    }
                } else {
                    unk_0054->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 22:
                if (!m_game->unk_14BC->IsActive() && !m_game->unk_14C0->IsActive()) {
                    unk_0084 = 0;
                    return 0xB;
                }
                break;
            case 23: {
                CFieldPartner *partner = unk_007C;
                if (!m_game->m_textboxData->IsActive() && !m_game->m_textboxData->sub_0200B6A4(1)) {
                    ov0_0212451C();
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    if (m_game->m_textboxData->GetYesNoResult() == 0) {
                        unk_0084 = 0;
                        ov0_02161F88();
                        unk_0034->ov0_0213FB0C("sTeleport", partner->unk_58, -1);
                    } else {
                        unk_0084 = 0;
                    }
                    unk_0054->sub_02022DD4();
                } else {
                    unk_0054->SwitchToPokemonInfo(partner->unk_200, 0);
                }
                break;
            }
            case 20:
                if (!m_game->m_textboxData->IsActive()) {
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                }
                break;
            case 24:
                if (!m_game->unk_14BC->IsActive() && !m_game->unk_14C0->IsActive()) {
                    save->unk_8BA0 = ov0_02124604();
                    return 7;
                }
                break;
            case 25:
                if (!m_game->m_textboxData->IsActive()) {
                    m_game->m_textboxData->sub_02009FB0(1, 1);
                    m_game->m_textboxData->ResetTextSpeed();
                    unk_0084 = 0;
                    ov0_0212451C();
                    unk_0054->sub_02022DD4();
                } else {
                    unk_0054->SwitchToPokemonInfo(unk_007C->unk_200, 0);
                }
                break;
            }
        }

        if (unk_0058->IsActive() == 0) {
            BOOL canMove = (unk_0034->ov0_0213FF2C() == 0 && (unk_00D0 & 0x1FE07B) == 0 && ok) ? TRUE : FALSE;
            if (canMove) {
                switch (unk_0084) {
                case 0x1A:
                    if (unk_0080->GetDCState() == 2) {
                        unk_0084 = 3;
                        unk_0088 = 0;
                        ov0_02124588(0x1F, 2);
                        unk_007C->unk_04 |= 0x100;
                        unk_0080->unk_04 |= 0x100;
                        unk_0014->SetFollow(unk_007C->unk_58);
                    }
                    break;
                case 3:
                    if (++unk_0088 >= 2) {
                        unk_0084 = 4;
                        unk_0140 = -1;
                        unk_007C->ov0_0213E4BC(unk_0080->unk_58);
                    }
                    break;
                case 4:
                    if (unk_0080->GetDCState() == 2) {
                        if ((unk_007C->unk_274 != NULL ? unk_007C->unk_274->unk_04 : 2) == 2) {
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
                        unk_008C = 0xFFFFFFFF;
                        Point2D pos = unk_007C->GetPos();
                        ov0_02124C30(&pos);
                        m_game->unk_14B8->MoveTo(1 - pos.x, 1 - pos.y, FX32_ONE);
                        unk_0014->unk_04 &= ~0x100;
                        unk_0020->sub_0203F7AC();
                        unk_0018->sub_0203F7AC();
                        unk_0024->sub_0203F7AC();
                    }
                    break;
                case 6:
                    if (!m_game->unk_14B8->IsBusy()) {
                        unk_0084 = 7;
                        m_game->m_textboxData->SetParam(0, unk_007C->unk_268);
                        m_game->m_textboxData->SetTextSpeed(1);
                        m_game->m_textboxData->ShowSystemMessage(0x18, 1, 1, 0);
                    }
                    break;
                case 7:
                    if (++unk_0088 >= 60) {
                        m_game->m_textboxData->sub_02009FB0(1, 1);
                        m_game->m_textboxData->ResetTextSpeed();
                        unk_0084 = 8;
                        Point2D target = { -unk_0008->unk_1C, -unk_0008->unk_20 };
                        unk_007C->StartMoveTo(target);
                    }
                    break;
                case 8:
                    if (!unk_007C->IsC8Set()) {
                        unk_001C->sub_0203F7AC();
                        u32 id = unk_007C->unk_58;
                        unk_001C->ov0_0213A050((id & 0xFFFFFF) | 0x1000000);
                        UnkStruct_020155FC *data = SaveData_FindEntry(save, id);
                        if (data != NULL) {
                            sub_02015A3C(save, data->unk_04, data->unk_02);
                            sub_02015E54(save, id);
                        }
                        ((CFieldTargetObject *)unk_0080)->ov0_0213CD3C();
                        unk_0014->sub_0201287C_();
                        Point2D pos = unk_0014->GetPos();
                        ov0_02124C30(&pos);
                        m_game->unk_14B8->MoveTo(1 - pos.x, 1 - pos.y, FX32_ONE);
                        unk_0084 = 9;
                    }
                    break;
                case 9:
                    if (!m_game->unk_14B8->IsBusy()) {
                        unk_008C = 0;
                        unk_0084 = 0;
                    }
                    break;
                }
            }

            unk_0034->ov0_0213F9B0(unk_0084 == 0);
            if (unk_0034->ov0_0213FEEC() == 0 && (unk_00D0 & 0x1FE07B) == 0 && unk_0084 == 0 && ok) {
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
            unk_0014->unk_E8 = mask;

            if (doUpdate) {
                u32 playerFlags = (updateActors ? 1 : 0) | (save->m_areaType == 1 ? 2 : 0);
                if (unk_0078 == 0) {
                    unk_0014->ov0_021307B0(pad, held ? NULL : touch, unk_0008, unk_0010, playerFlags);
                } else {
                    unk_0014->ov0_021307B0(NULL, NULL, unk_0008, unk_0010, playerFlags);
                }
                Point2D pos = unk_0014->GetPos();
                Point2D tile;
                tile.x = (s16)(pos.x >> FX32_SHIFT) << FX32_SHIFT;
                tile.y = (s16)(pos.y >> FX32_SHIFT) << FX32_SHIFT;
                BOOL arg = (unk_0034->ov0_0213FEEC() == 0 && save->m_energy != 0 && ok) ? TRUE : FALSE;
                int hit = unk_0030->Update(&tile, unk_0014->unk_14, arg);
                if (save->m_energy == 0 && unk_0014->unk_110 == 1 && hit != 0) {
                    unk_0014->SetPos(playerPos);
                }
                if (unk_0034->ov0_0213FEEC() == 0 && (unk_00D0 & 0x1FE07B) == 0 && unk_0084 == 0 && ok && updateActors) {
                    updateActors = TRUE;
                } else {
                    updateActors = FALSE;
                }
                if (!(unk_00D0 & 1)) {
                    if (updateActors) {
                        unk_005C->ov0_02159D7C();
                    }
                    unk_0024->UpdateAll(unk_0010, updateActors);
                    unk_0018->UpdateAll(unk_0010, updateActors);
                    unk_001C->UpdateAll(unk_0010, updateActors);
                    unk_0020->UpdateAll(unk_0010, updateActors);
                }
                if (updateActors) {
                    unk_008C = 0;
                }
            }
        } else {
            updateActors = FALSE;
            doUpdate = FALSE;
        }
    }

    Point2D pos = unk_0014->GetPos();
    int offset = unk_0014->GetUnk8C();
    if (!((unk_00D0 & 0x200000) ? TRUE : FALSE)) {
        save->SetPos(pos);
        save->m_dir = unk_0014->GetDir();
        save->m_layer = unk_0014->unk_14;
        unk_0054->SetMapPos(pos.x >> FX32_SHIFT, pos.y >> FX32_SHIFT);
        save->unk_7F60 |= 1;
        for (int i = 0; i < unk_0018->m_count; i++) {
            CFieldActor *actor = unk_0018->Get(i);
            if (actor != NULL) {
                save->SetEnemy(i, actor->GetPos(), actor->GetDir());
            }
        }
        for (int i = 0; i < unk_0020->m_count; i++) {
            CFieldActor *actor = unk_0020->Get(i);
            if (actor != NULL) {
                save->SetNpc(i, actor->GetPos(), actor->GetDir());
            }
        }
        for (int i = 0; i < unk_0024->m_count; i++) {
            CFieldActor *actor = unk_0024->Get(i);
            if (actor != NULL) {
                save->SetObject(i, actor->GetPos(), actor->GetDir());
            }
        }
        for (int i = 0; i < unk_001C->m_count; i++) {
            CFieldActor *actor = unk_001C->Get(i);
            if (actor != NULL) {
                switch (((s32)actor->unk_58 >> 24) & 0xFF) {
                case 5: {
                    UnkStruct_0201549C *data = SaveData_FindPartner(save, actor->unk_58);
                    if (data != NULL) {
                        data->SetPos(actor->GetPos());
                        data->unk_34 = actor->unk_14;
                        data->unk_0A = actor->GetDir();
                    }
                    break;
                }
                case 6: {
                    UnkStruct_020155FC *data = SaveData_FindEntry(save, actor->unk_58);
                    if (data != NULL) {
                        data->SetPos(actor->GetPos());
                        data->unk_16 = actor->unk_14;
                        data->unk_14 = actor->GetDir();
                    }
                    break;
                }
                }
            }
        }
    }

    int target = unk_008C;
    if (target != -1) {
        BOOL found = FALSE;
        Point2D camPos;
        if (target == 0) {
            camPos.y = pos.y;
            camPos.x = pos.x;
            if (unk_0014->unk_110 == 3) {
                camPos.y -= offset;
            }
            found = TRUE;
        } else {
            CFieldActor *actor;
            switch (((s32)target >> 24) & 0xFF) {
            case 0:
                break;
            case 1:
                actor = unk_001C->FindPartner(target);
                if (actor == NULL) {
                    actor = unk_0018->Find(target);
                }
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            case 2:
                actor = unk_001C->FindPartner(target);
                if (actor == NULL) {
                    actor = unk_0020->Find(target);
                }
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            case 3:
                actor = unk_0024->Find(target);
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            case 4:
            case 5:
            case 6:
                actor = unk_001C->Find(target);
                if (actor != NULL) {
                    camPos = actor->GetPos();
                    found = TRUE;
                }
                break;
            }
        }
        if (found) {
            if (unk_00D0 & 4) {
                ov0_02124C30(&camPos);
            }
            camPos.x &= ~0xFFF;
            camPos.y &= ~0xFFF;
            unk_0008->SetOrigin(camPos.x, camPos.y);
        }
    } else {
        m_game->unk_14B8->Update();
    }

    if (unk_00D8 != NULL) {
        if (!(unk_00D0 & 1)) {
            unk_00D8->SetCurrentHP(save->m_energy);
        }
        unk_00D8->vfunc_08();
    }
    if (unk_0060 != NULL) {
        unk_0060->Update();
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
        if (unk_0010 != NULL) {
            unk_0010->ov0_021251D8(1, fps);
        }
        if (unk_0028 != NULL) {
            unk_0028->ov0_021428EC(fps, !updateActors);
        }
        if (unk_002C != NULL) {
            unk_002C->Update(fps);
        }
        if (unk_0048 != NULL) {
            sub_02041920(unk_0048);
        }
        if (unk_00DC != NULL) {
            ov0_02121758(fps);
        }
        if ((unk_00D0 & 0x80) && unk_00F4 > 0) {
            unk_00F0++;
            unk_00FA = LinearInterpolate(unk_00F8 << FX32_SHIFT, unk_00F9 << FX32_SHIFT, unk_00F0, unk_00F4) >> FX32_SHIFT;
            if (unk_00F0 >= unk_00F4) {
                unk_00F4 = 0;
                unk_00F0 = 0;
                if (unk_00FA == 0) {
                    unk_00D0 &= ~0x80;
                    unk_00F8 = 0;
                    unk_00FA = 0;
                }
            }
        }
    }

    ov0_02124210();
    u32 flags = unk_00D0;
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
            if (m_game->unk_14C4->func0() || m_game->unk_14C8->func0() || m_game->unk_14BC->IsActive() || m_game->unk_14C0->IsActive()) {
                break;
            }
            {
                int step = unk_0088 >> 1;
                if (step < 2) {
                    if (unk_0088 & 1) {
                        if (step < 1) {
                            m_game->unk_14BC->Start(2, 8);
                        } else {
                            m_game->unk_14BC->Start(2, 30);
                            if (m_game->unk_14C0->GetMode() != 4 && m_game->unk_14C0->GetMode() != 2) {
                                m_game->unk_14C0->Start(4, 30);
                            }
                            m_game->m_audioEngine->sub_02034E38(60);
                        }
                    } else {
                        m_game->unk_14BC->Start(1, 8);
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
            BattleStartParam_SetPartnerMood(record, save->m_partnerMoods[sub_02016268(save, -1)]);
            sub_02010964(record, sub_0201621C(save, -1));
            sub_02010B00(record, save->unk_8803);
            count = 0;
            for (i = 0; i < 10; i++) {
                UnkStruct_020155FC *data = SaveData_GetEntry(save, i);
                if (data != NULL && (data->unk_08 & 1)) {
                    BattleStartParam_AddPartyMember(record, data->unk_00, !(data->unk_08 & 4) | (data->unk_08 & 2));
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
                if (unk_002C->IsEffectActive(9)) {
                    BattleStartParam_SetScreenEffect(record, 9);
                } else {
                    for (int i = 1; i < 0x11; i++) {
                        if (unk_002C->IsEffectActive(i)) {
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
                m_game->unk_14BC->Start(2, 8);
            }
            m_game->m_audioEngine->sub_02034AA8();
            unk_0088 = 0;
            ov0_02123E58(-1);
            unk_0054->SetIdleReturn(0);
            unk_0054->unk_60 = 1;
            break;
        }
    } else {
        if (flags & 2) {
            DAT_0208aaf8 = 0;
            SaveData_ClearActorPositions(save);
            unk_0028->ov0_021433D0();
            unk_0054->HideAreaMap();
            unk_0054->ClearMapIcons();
            ov0_021220D0(unk_0068, TRUE);
            ov0_021248DC();
            save->unk_8BC0 = 0;
            m_game->m_audioEngine->PlayMapBgm(unk_0068, 0, 0);
            ov0_02122EF4();
            fx32 y, x;
            x = unk_006C << FX32_SHIFT;
            y = unk_0070 << FX32_SHIFT;
            unk_0014->SetPosXY(x, y);
            if (unk_0074 >= 0) {
                unk_0014->sub_020128EC_(unk_0074);
                unk_0014->sub_0201287C_();
            }
            unk_0014->ResetMove();
            unk_0014->sub_show();
            unk_0014->ov0_021341E0();
            unk_0078 = 0;
            ov0_0212451C();
            unk_001C->ov0_02139F98(x, y, unk_0014->unk_14);
            if (save->HasString()) {
                unk_0034->ov0_0213FB0C(save->m_saveName, 0, -1);
                save->m_saveName[0] = '\0';
            }
            unk_0054->ShowAreaMap(unk_0068, unk_006C, unk_0070);
            ov0_021248EC();
        } else {
            m_game->AddVBlankCallback(ov0_021220AC, NULL);
        }
    }

    unk_0054->Update();
    unk_0058->Update();
    int result = unk_0058->GetSelection();
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
        unk_00D0 &= ~0x300;
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
void sub_02015714(SaveData *save, int idx, int mapId);
void sub_0201577C(SaveData *save, int idx, int mapId);
BOOL sub_02015690(SaveData *save, int idx, int mapId);
void sub_02015B98(SaveData *save, int idx, int mapId);
void sub_02015C08(SaveData *save, int idx, int mapId);
BOOL sub_02015B1C(SaveData *save, int idx, int mapId);
void sub_02015AAC(SaveData *save, int idx, int mapId);
BOOL sub_02015434(SaveData *save, int mapId, int idx);
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
        CFieldPartner *partner = unk_007C;
        FieldData_GetEnemy(unk_0038, partner->unk_200);
        UnkStruct_020107A8 *info = PokeIdTable_Get(m_game->unk_1434, partner->unk_200);
        if (info->unk_05 != 0 && info->unk_06 != 0) {
            Point2D pos;
            Point2D touchPos;
            Point2D hit;
            Point2D cam = unk_0008->GetOffset();
            // The copy has to go through a pointer to the returned temporary to match.
            SetPoint(&pos, &(const Point2D &)unk_007C->GetPos());
            CTouchPanel *touch = m_game->activeTouchPanel;
            pos.y -= unk_007C->GetHeight();
            touchPos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
            touchPos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
            touchPos -= cam;
            CFieldMapLayerCollision *layer = unk_0010->GetLayer(unk_0014->unk_14);
            PointPair2D line = { pos, touchPos };
            if (layer->Sweep(&line, 0x4000, &hit, 1)) {
                touchPos = hit;
            }
            ov0_02148480(unk_00DC, &pos, &touchPos);
        }
        break;
    }
    case 3:
        break;
    }
    ov0_021481EC(unk_00DC, fps);
}

void CFieldScene::func1()
{
    SaveData *save = &MAIN_BSS_020B26A0;

    if (!(unk_00D0 & 2)) {
        if (unk_00EC == 0) {
            BGFontPrinter *printer = m_game->GetPrinter();
            printer->unk_24 = 0;
            printer->Printf(0, 0, "");
            if (unk_00E4->unk_00 & 1) {
                s32 layerNo = unk_0014->unk_14;
                CFieldMapLayerCollision *layer = unk_0010->GetLayer(layerNo);
                CFieldMapLayerAttribute *attrLayer = unk_0010->GetAttributeLayer(layerNo);
                int cell = layer != NULL ? layer->GetCellAtPos(unk_0014->GetX(), unk_0014->GetY()) : -1;
                int attr = attrLayer != NULL ? attrLayer->GetCellAtPos(unk_0014->GetX(), unk_0014->GetY()) : -1;
                printer->Printf(0, 0, "FIELD (%d,%d,%d) : (%d,%d)", unk_0014->GetX() >> FX32_SHIFT, unk_0014->GetY() >> FX32_SHIFT, layerNo, cell, attr);
                if (unk_0084 == 4) {
                    printer->Printf(0, 1, "InTargetClearEvent");
                } else if (unk_0084 == 8) {
                    printer->Printf(0, 1, "InReleaseEventAfterTargetClear");
                } else if (unk_0034->ov0_0213FEEC()) {
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

        Point2D camPos = unk_0008->GetOffset();
        unk_000C->ApplyProjection();
        unk_000C->ApplyView();
        G3_StoreMtx(0);
        if (!(unk_00D0 & 0x800)) {
            if (unk_00D8 != NULL) {
                unk_00D8->vfunc_0C(unk_000C);
            }
            if (unk_004C != NULL && save->IsButton1Enabled()) {
                unk_004C->ov0_0214FD00(unk_000C);
            }
            if (unk_0050 != NULL && save->IsButton2Enabled()) {
                unk_0050->ov0_0214FF20(unk_000C);
            }
        }

        if (!(unk_00D0 & 0x1000)) {
            G3_Identity();
            unk_0008->SetOffset(camPos);
            unk_0008->ApplyProjection();
            unk_0008->ApplyView();
            G3_StoreMtx(0);
            if (!(unk_00D4 & 1)) {
                unk_0014->Draw(unk_003C, unk_0048);
            }
            if (!(unk_00D0 & 0x400) && !(unk_00D4 & 4)) {
                unk_0018->DrawAll(unk_003C, unk_0048);
            }
            if (!(unk_00D4 & 2)) {
                unk_001C->DrawAll(unk_003C, unk_0048);
            }
            if (!(unk_00D4 & 8)) {
                unk_0020->DrawAll(unk_003C, unk_0048);
            }
            if (!(unk_00D4 & 0x10)) {
                unk_0024->DrawAll(unk_003C, unk_0048);
            }
            if (!(unk_00D0 & 0x40)) {
                unk_005C->ov0_02159DB4(unk_003C, unk_0048);
            }
            unk_0028->ov0_02143380(unk_003C);
            for (int i = 0; i < 4; i++) {
                int budget = unk_0010->ov0_0212546C(i);
                DrawObjectList *list = &unk_003C[i];
                int count = list->Draw(unk_0008, budget);
                list->Clear();
                FieldShadow_Render(unk_0048, unk_0008, i, budget - count);
                int total = count + 1;
                total += unk_0028->ov0_0214336C(i, budget - total);
                list = &unk_003C[i + 5];
                count = list->Draw(unk_0008, budget - total);
                list->Clear();
                total += count;
                unk_0010->SetPolygonCount(i, total);
            }
            unk_0010->ov0_02125338(unk_0008);
            unk_0028->ov0_02142D88(unk_0008);

            G3_Identity();
            unk_0008->SetOffset(0, 0);
            unk_0008->ApplyProjection();
            unk_0008->ApplyView();
            G3_StoreMtx(0);
            if (unk_002C != NULL) {
                unk_002C->Draw(unk_0008);
            }
            if (unk_00D0 & 0x80) {
                unk_00FC.m_alpha = unk_00FA;
                unk_00FC.Render(unk_0008);
            }
            if (unk_0064 != NULL) {
                SaveData *saveData = m_game->unk_14A4;
                if (saveData->unk_7F60 & 2) {
                    ov0_0216D62C(unk_0064, saveData->m_timerMode == 2 ? saveData->m_timer : saveData->m_timer + 59, 0x6A4, unk_0008);
                }
            }

            G3_Identity();
            unk_0008->SetOffset(camPos);
            unk_0008->ApplyProjection();
            unk_0008->ApplyView();
            G3_StoreMtx(0);
            DrawObjectList *list = &unk_003C[4];
            int count = list->Draw(unk_0008, 0x618);
            list->Clear();
            FieldShadow_Render(unk_0048, unk_0008, 4, 0x618 - count);
            int total = count + 1;
            list = &unk_003C[9];
            list->Draw(unk_0008, 0x618 - total);
            list->Clear();
            FieldShadow_Clear(unk_0048);
            if (unk_00DC != NULL) {
                ov0_02148288(unk_00DC, unk_0008);
            }
            unk_0030->Draw(unk_0008);
        }
        if (unk_0060 != NULL) {
            unk_0060->Render();
        }
    }

    unk_0054->sub_02022710();
    unk_0058->Render();
    unk_00D0 &= ~2;
    unk_0068 = 0;
    unk_006C = 0;
    unk_0070 = 0;
    unk_0074 = 0;
}

void CFieldScene::func2()
{
    unk_0054->Render();
    unk_0058->sub_02023470();
}

void CFieldScene::func3()
{
    unk_0054->sub_020227AC();
    LoadOam();
}

void CFieldScene::func4()
{
    CScene::func4();
}

void CFieldScene::ov0_021220AC(void *arg0)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->unk_0010->ov0_02126658();
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
        unk_0020->Clear();
        unk_0018->Clear();
        unk_0024->Clear();
        FieldEventRectManage *items = unk_0030;
        if (items->m_count > 0 && items->m_items != NULL) {
            for (int i = 0; i < items->m_count; i++) {
                SAFE_DELETE(items->m_items[i]);
            }
        }
        unk_0028->ov0_02142F08();
        unk_002C->ClearSecondary();
        unk_002C->ClearPrimary();
        unk_005C->ov0_02159D70();
    }

    if (arg1) {
        for (int i = 0; i < 0x20; i++) {
            save->unk_81B4[i] = 0;
        }
        save->unk_81B0 = 0;
    }

    unk_0010->ov0_02124EE4();
    UnkStruct_02041D80 *newInfo = FieldData_GetMap(unk_0038, mapId);
    if (unk_00CC >= 0) {
        u8 oldMode = GetMapMode(save->m_areaType);
        UnkStruct_02041D80 *oldInfo = FieldData_GetMap(unk_0038, save->m_mapId);
        u8 newMode = GetMapMode(newInfo->unk_04);
        save->m_mapId = unk_0068;
        save->m_areaType = newInfo->unk_04;
        SaveData_LotTimeCheck(save);
        if (newInfo->unk_00 != oldInfo->unk_00) {
            m_game->m_textboxData->FreeAreaMessages();
            ScriptManager_UnloadArea(m_game->m_scriptManager);
        }
        if (oldMode != newMode) {
            unk_001C->Clear();
            sub_020171B8(save);
            sub_02017948(save, 1);
            if (newMode != 1) {
                for (int i = 0; i < 2; i++) {
                    UnkStruct_020B26A0_8AD4 *partner = save->GetPartner(i);
                    if (partner != NULL && partner->unk_00 != 0) {
                        int idx = unk_001C->ov0_02139920(partner->unk_04, partner->unk_08, 0x1E16, 1, 1);
                        if (idx >= 0) {
                            CFieldActor *actor = unk_001C->Get(idx);
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
                UnkStruct_020155FC *data = SaveData_GetEntry(save, i);
                if (data != NULL && (data->unk_08 & 1)) {
                    u32 id = (data->unk_04 & 0xFFF) | ((6 << 24) | ((data->unk_02 & 0xFFF) << 12));
                    unk_001C->ov0_02139920(id, data->unk_00, 0xE, 0, 1);
                }
            }
            if (oldMode == 1 || newMode == 1) {
                if (newInfo->unk_04 == 1) {
                    save->unk_8802 = TRUE;
                } else {
                    save->unk_8802 = FALSE;
                }
                unk_0014->ov0_02132FA0(save->unk_8802);
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
    unk_0010->ov0_02125D28(nameGroup, name, m_game->unk_14A8);

    for (int i = 0; i < unk_0030->m_count; i++) {
        CFieldEventRect *item = unk_0030->Get(i);
        if (item != NULL) {
            if (save->GetUnk0030State(mapId, i) == 0) {
                if (item->unk_18 != 0) {
                    sub_02015714(save, i, -1);
                } else {
                    sub_0201577C(save, i, -1);
                }
            } else {
                if (sub_02015690(save, i, -1)) {
                    item->unk_18 = 1;
                } else {
                    item->unk_18 = 0;
                }
            }
        }
    }

    for (int i = 0; i < unk_0020->m_count; i++) {
        CFieldActor *npc = unk_0020->Get(i);
        if (npc != NULL) {
            if (save->GetNpcState(mapId, i) == 0) {
                if (npc->IsActive()) {
                    sub_02015B98(save, i, -1);
                } else {
                    sub_02015C08(save, i, -1);
                }
            } else {
                if (sub_02015B1C(save, i, -1)) {
                    npc->unk_20 = 2;
                } else {
                    Actor_HideManpu(npc);
                    npc->unk_20 = 0;
                    npc->sub_0202D394();
                }
            }
        }
    }

    for (int i = 0; i < unk_0018->m_count; i++) {
        CFieldEnemy *enemy = (CFieldEnemy *)unk_0018->Get(i);
        if (enemy != NULL) {
            switch (save->GetEnemyState(mapId, i)) {
            case 0:
                if (enemy->IsActive()) {
                    sub_02015A3C(save, i, -1);
                } else {
                    sub_02015AAC(save, i, -1);
                }
                break;
            case 1:
                enemy->unk_20 = 0;
                break;
            case 2:
                if (arg1 && !sub_02015434(save, mapId, i)) {
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
                if (!sub_02015434(save, save->m_mapId, i)) {
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

    for (int i = 0; i < unk_0024->m_count; i++) {
        CFieldActor *object = unk_0024->Get(i);
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
        unk_002C->sub_02035D38(info->unk_03);
        unk_002C->StartEffect(info->unk_03, 0, -1, 0);
    }
    unk_008C = 0;
    unk_00D0 |= 4;
    unk_0078 = 0;
    unk_007C = 0;
    unk_0080 = 0;
    unk_0084 = 0;
    ov0_0212419C();
    unk_0018->ov0_02136384();
    m_game->m_audioEngine->sub_02034C2C(0);
    if (info->unk_02 == 0xFF) {
        OS_SPrintf(name, "m%03d/m%03d_%03d.fsb", info->unk_00, info->unk_00, info->unk_01);
    } else {
        OS_SPrintf(name, "m%03d/m%03d_%03d%c.fsb", info->unk_00, info->unk_00, info->unk_01, info->unk_02 + 'a');
    }
    unk_0010->ov0_02124D98(name);
    FieldShadow_SetAlpha(unk_0048, info->unk_05);
    unk_0028->ov0_02143410();
    return TRUE;
}

BOOL CFieldScene::ov0_02122EF4()
{
    unk_0010->ov0_02124E48();
    return TRUE;
}

static inline BOOL IsBossType(u16 type)
{
    return type >= 0x37 && type <= 0x3E;
}

void CFieldScene::ov0_02122F08(CFieldEnemy *enemy)
{
    if (unk_00D0 & 1) {
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
    ov0_02122FEC(enemy->unk_E8, enemy->unk_E0, enemy->unk_58 & 0xFFF);
    CBattleResultParameter *stats = m_game->unk_1444;
    if (IsBossType(enemy->unk_146)) {
        stats->unk_0C = 2;
    } else {
        stats->unk_0C = 0;
    }
    unk_00D0 |= 1;
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
            if (actor != NULL && id == actor->unk_58) {
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
        return unk_001C->FindLeader();
    }
    switch (((s32)id >> 24) & 0xFF) {
    case 0:
        actor = unk_0014;
        break;
    case 1:
        actor = unk_001C->Find(MakeActorId(6, id));
        if (actor == NULL) {
            actor = unk_0018->Find(id);
        }
        break;
    case 2:
        actor = FindActorCounted(unk_001C, MakeActorId(5, id));
        if (actor == NULL) {
            actor = unk_0020->Find(id);
        }
        break;
    case 3:
        actor = unk_0024->Find(id);
        break;
    case 4:
    case 5:
    case 6:
        actor = unk_001C->Find(id);
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
    pos.x -= unk_0008->unk_1C;
    pos.y -= unk_0008->unk_20;

    CFieldActor *hit = NULL;
    if (hit == NULL) {
        fx32 bestY = -0x800000;
        for (int i = 0; i < unk_0020->m_count; i++) {
            CFieldActor *npc = unk_0020->Get(i);
            if (npc != NULL && npc->IsActive() && !npc->IsUnk04Bit0() && npc->IsTouched(pos)) {
                if (hit == NULL || npc->GetY() > bestY) {
                    hit = npc;
                    bestY = npc->GetY();
                }
            }
        }
    }
    if (hit == NULL) {
        SaveData *save = &MAIN_BSS_020B26A0;
        for (int i = unk_001C->m_count - 1; i >= 0; i--) {
            CFieldPartner *partner = (CFieldPartner *)unk_001C->Get(i);
            if (partner != NULL && partner->IsActive() && !partner->IsUnk04Bit0() && partner->IsTouched(pos)) {
                if (save->m_areaType != 4 || !partner->IsKind0() || (partner->unk_04 & 0x20)) {
                    hit = partner;
                    break;
                }
            }
        }
    }
    if (hit == NULL) {
        for (int i = unk_0024->m_count - 1; i >= 0; i--) {
            CFieldActor *object = unk_0024->Get(i);
            if (object != NULL && object->IsActive() && !object->IsUnk04Bit0() && object->IsTouched(pos)) {
                hit = object;
                break;
            }
        }
    }
    if (unk_0014->IsTouched(pos)) {
        hit = unk_0014;
    }
    if (hit == NULL) {
        fx32 bestY = -0x800000;
        for (int i = 0; i < unk_0018->m_count; i++) {
            CFieldActor *enemy = unk_0018->Get(i);
            if (enemy != NULL && enemy->IsActive() && !enemy->IsUnk04Bit0() && enemy->IsTouched(pos)) {
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
        m_game->m_textboxData->SetParam(1, unk_007C->unk_268);
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
    if (unk_0014 != NULL && (flags & 1)) {
        if (!unk_0014->ov0_0213416C()) {
            unk_0014->StopMotion();
        }
        CFieldPlayer *player = unk_0014;
        player->unk_10C &= ~1;
        player->unk_E4 = 0;
        player->unk_140 = 0;
        player->sub_020129F4_(0, 0x1F);
        player->ClearUnk1A8Bits(2);
    }
    if (unk_001C != NULL && (flags & 2)) {
        sub_0203F3C8(unk_001C);
    }
    if (unk_0020 != NULL && (flags & 8)) {
        sub_0203F3C8(unk_0020);
    }
    if (unk_0024 != NULL && (flags & 0x10)) {
        sub_0203F3C8(unk_0024);
    }
}

void CFieldScene::ov0_02123FEC(u32 arg0, int arg1)
{
    ov0_02124054();
    unk_00AA = unk_0028->ov0_02142F6C(1, 0x25);
    CFieldEffect *effect = unk_0028->ov0_02143088(unk_00AA);
    if (effect != NULL) {
        ((CFieldEffectManpu *)effect)->unk_1C = unk_0014;
        effect->ov0_021421F0(0, -1, 0);
    }
    unk_00B0 = arg0;
    unk_00AC = arg1;
}

void CFieldScene::ov0_02124054()
{
    if (unk_00AA != 0xFFFF) {
        CFieldEffect *effect = unk_0028->ov0_02143088(unk_00AA);
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

    for (int i = 0; i < unk_0030->m_count; i++) {
        CFieldEventRect *item = unk_0030->Get(i);
        if (item != NULL) {
            if (item->unk_18 != 0) {
                sub_02015714(save, i, -1);
            } else {
                sub_0201577C(save, i, -1);
            }
        }
    }
    for (int i = 0; i < unk_0020->m_count; i++) {
        CFieldActor *npc = unk_0020->Get(i);
        if (npc != NULL) {
            save->SetNpcState(mapId, i, npc->unk_20 + 1);
        }
    }
    for (int i = 0; i < unk_0018->m_count; i++) {
        CFieldActor *enemy = unk_0018->Get(i);
        if (enemy != NULL) {
            save->SetEnemyState(mapId, i, enemy->unk_20 + 1);
        }
    }
    for (int i = 0; i < unk_0024->m_count; i++) {
        CFieldActor *object = unk_0024->Get(i);
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
    unk_0014->ClearUnk1A8Bits(1);
    unk_0020->sub_0203F754();
    unk_0018->sub_0203F754();
    unk_0024->sub_0203F754();
    unk_001C->sub_0203F754();
}

void CFieldScene::ov0_02124588(int arg0, int arg1)
{
    unk_00D0 |= 0x80;
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
        unk_00D0 &= ~0x80;
        unk_00F4 = 0;
        unk_00F8 = 0;
        unk_00FA = 0;
    }
}

int CFieldScene::ov0_02124604()
{
    UnkStruct_02041D80 *info = FieldData_GetMap(unk_0038, MAIN_BSS_020B26A0.m_mapId);
    u8 value = info->unk_06;
    int attr = 0;
    if (unk_0010 != NULL && unk_0014 != NULL) {
        Point2D pos = unk_0014->GetPos();
        CFieldMapLayerAttribute *attrLayer = unk_0010->GetAttributeLayer(unk_0014->unk_14);
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
    unk_00D0 |= 8;
    if (unk_0014 != NULL && !unk_0014->ov0_0213416C()) {
        unk_0014->sub_show();
        unk_0014->sub_0201287C_();
        unk_0014->ResetMove();
        unk_0014->ov0_021341E0();
    }
    unk_0078 = 0;
    ov0_0212451C();
    if (unk_001C != NULL) {
        unk_001C->ov0_02139E9C();
    }
}

void CFieldScene::ov0_021248DC()
{
    unk_00D0 &= ~8;
}

void CFieldScene::ov0_021248EC()
{
    if (unk_0024 != NULL && unk_0054 != NULL) {
        for (int i = 0; i < unk_0024->m_count; i++) {
            CFieldTargetObject *object = (CFieldTargetObject *)unk_0024->Get(i);
            if (object != NULL && object->IsActive() && !object->IsUnk04Bit0()) {
                switch (object->unk_E8) {
                case 0x16E:
                    unk_0054->AddMapIcon(object->GetX() >> FX32_SHIFT, object->GetY() >> FX32_SHIFT, TRUE);
                    break;
                case 0x16F:
                    unk_0054->AddMapIcon(object->GetX() >> FX32_SHIFT, object->GetY() >> FX32_SHIFT, FALSE);
                    break;
                }
            }
        }
    }
    if (unk_0020 != NULL && unk_0054 != NULL) {
        for (int i = 0; i < unk_0020->m_count; i++) {
            CFieldNpc *npc = (CFieldNpc *)unk_0020->Get(i);
            if (npc != NULL && npc->IsActive() && !npc->IsUnk04Bit0() && npc->unk_E8 == 0) {
                switch (npc->unk_EC) {
                case 0x5C:
                    unk_0054->AddMapIcon(npc->GetX() >> FX32_SHIFT, npc->GetY() >> FX32_SHIFT, TRUE);
                    break;
                case 0x90:
                    unk_0054->AddMapIcon(npc->GetX() >> FX32_SHIFT, npc->GetY() >> FX32_SHIFT, FALSE);
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
    if (unk_0034->ov0_0213FEEC() != 0 || (unk_00D0 & 0x49)) {
        return FALSE;
    }
    return TRUE;
}

BOOL CFieldScene::ov0_02124C30(Point2D *pos)
{
    BOOL clamped = FALSE;
    if (pos != NULL && unk_0010 != NULL) {
        if (pos->x < FX32_CONST(128)) {
            pos->x = FX32_CONST(128);
            clamped = TRUE;
        }
        if (pos->y < FX32_CONST(96)) {
            pos->y = FX32_CONST(96);
            clamped = TRUE;
        }
        if (pos->x > (unk_0010->m_info.size.width - 128) << FX32_SHIFT) {
            pos->x = (unk_0010->m_info.size.width - 128) << FX32_SHIFT;
            clamped = TRUE;
        }
        if (pos->y > (unk_0010->m_info.size.height - 96) << FX32_SHIFT) {
            pos->y = (unk_0010->m_info.size.height - 96) << FX32_SHIFT;
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
