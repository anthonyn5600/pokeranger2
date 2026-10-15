#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Camera2D.hpp"
#include "CameraController.hpp"
#include "Collision.hpp"
#include "FieldData.hpp"
#include "FieldScreenEffectManage.hpp"
#include "FieldSubScreen.hpp"
#include "MathUtil.hpp"
#include "PadInput.hpp"
#include "SaveData.hpp"
#include "SubScreenIconMenu.hpp"
#include "TextboxManager.hpp"
#include "UnkClass_0214FB28.hpp"
#include "UnkClass_0214FD4C.hpp"
#include "UnkStruct_020107A8.hpp"
#include "WindowWipe.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldNpc.hpp"
#include "field/CFieldNpcManage.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPartnerPokemon.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldPlayerInputControlManage.hpp"
#include "field/CFieldTargetObject.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldNpcManage *MAIN_BSS_0210CA50;
extern FieldData *MAIN_BSS_0210CA6C;
extern FieldScreenEffectManage *MAIN_BSS_0210CA78;
extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;
extern SaveData MAIN_BSS_020B26A0;

extern "C" {
u32 SaveData_AddConversations(SaveData *save, u32 value);
u32 SaveData_AddTargetsChecked(SaveData *save, u32 value);
int sub_020107C4(int arg0);
}

static inline u32 GetPokemonState(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->m_pokemonStates[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline void SetPokemonState(SaveData *save, int i, u32 state)
{
    int shift = (i & 0xF) * 2;
    save->m_pokemonStates[i >> 4] &= ~(3 << shift);
    save->m_pokemonStates[i >> 4] |= state << shift;
}

static inline void RaisePokemonState(SaveData *save, int i, u32 state)
{
    if (i >= 0 && i < 500) {
        if (GetPokemonState(save, i) < state) {
            SetPokemonState(save, i, state);
        }
    }
}

static inline void StartOutline(CFieldActor *actor, u16 color, int time)
{
    if (actor->m_drawObject != NULL) {
        CFieldDrawActor *draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_outlinePhase = 0;
        }
        draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_outlineColor = color;
            draw->m_outlinePhase = 0;
        }
        draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_outlineWidth = 2;
        }
        draw = actor->m_drawObject->m_actor;
        if (draw != NULL) {
            draw->m_effectFlags |= 1;
            draw->m_outlineTime = time;
            draw->m_outlinePhase = 0;
        }
    }
}

static inline u16 IsTrigger(PadInput *pad, u16 mask)
{
    return pad->unk_0002 & mask;
}

static inline BOOL IsMenuAllowed(CFieldScene *scene)
{
    return (scene->m_flags & 0x800) ? FALSE : TRUE;
}

static inline Point2D GetHeadPos(CFieldActor *actor)
{
    Point2D head = *(Point2D *)&actor->unk_70 + actor->GetPos();
    head.y -= actor->GetHeight();
    return head;
}

static inline FieldData *GetTargetTable()
{
    return MAIN_BSS_0210CA6C;
}

static inline int GetKind(CFieldActor *actor)
{
    return ((int)actor->m_id >> 24) & 0xFF;
}

static inline fx32 RectWidth(Rectangle rect)
{
    return rect.size.x;
}

static inline fx32 RectHeight(Rectangle rect)
{
    return rect.size.y;
}

static inline fx32 CircleRadius(Circle circle)
{
    return circle.r;
}

static inline Point2D GetCamPos()
{
    Camera2D *cam = (Camera2D *)s_game->m_cameraController->m_target;
    return cam->GetOffsetCopy();
}

static inline Rectangle GetTouchRect(CFieldActor *actor)
{
    Rectangle rect = actor->unk_24;
    rect.pos.x += actor->GetX();
    rect.pos.y += actor->GetY() - actor->GetHeight();
    return rect;
}

CFieldPlayerInputControlManage::CFieldPlayerInputControlManage()
{
    MAIN_BSS_0210CA70 = this;
    unk_04 = 0xFFFF;
}

CFieldPlayerInputControlManage::~CFieldPlayerInputControlManage()
{
    MAIN_BSS_0210CA70 = NULL;
}

BOOL CFieldPlayerInputControlManage::ov0_0213FFC4(CFieldScene *scene,
    PadInput *pad,
    CTouchPanel *touch)
{
    if (scene != NULL) {
        SaveData *save = &MAIN_BSS_020B26A0;
        // C89-style scratch, reused as the NPC loop counter, the effect icon hit and the button result (register order)
        int i;
        FieldData *table = GetTargetTable();
        // Used through casts per kind: typed alias locals would be coalesced with it and change its register
        CFieldActor *touched = scene->ov0_021232A8();
        BOOL busy = FALSE;
        if (MAIN_BSS_0210CA78 != NULL && MAIN_BSS_0210CA78->IsEffectActive(0xB)) {
            busy = TRUE;
        }

        Point2D touchPos;
        if (touch != NULL) {
            fx32 x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
            fx32 y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
            x -= scene->m_camera->unk_1C;
            y -= scene->m_camera->unk_20;
            touchPos.x = x;
            touchPos.y = y;
        } else {
            touchPos.y = 0;
            touchPos.x = 0;
        }

        CFieldPlayer *player = MAIN_BSS_0210CA48;
        if (scene->unk_0084 == 0) {

            BOOL touchHandled = FALSE;
            if (pad != NULL && IsTrigger(pad, PAD_BUTTON_A)) {
                CFieldNpcManage *npcs = MAIN_BSS_0210CA50;
                CFieldTargetObjectManage *objects = MAIN_BSS_0210CA7C;
                if (player != NULL) {
                    UnkStruct_02006238 area;
                    area.pos = player->GetPos();
                    area.unk_0C = player->GetDir();
                    area.unk_10 = 0x4000;
                    fx32 bestDist = 0x30000;
                    area.unk_08 = 0x30000;

                    if (npcs != NULL) {
                        CFieldNpc *best = NULL;
                        for (i = 0; i < npcs->m_count; i++) {
                            CFieldNpc *npc = (CFieldNpc *)npcs->Get(i);
                            if (npc != NULL && npc->IsActive() && !npc->IsHidden() && npc->m_layer == player->m_layer) {
                                Circle circle;
                                circle.pos = npc->GetPos();
                                if (npc->unk_50 == 0) {
                                    circle.r = (RectWidth(npc->unk_34) + RectHeight(npc->unk_34)) / 2;
                                } else {
                                    circle.r = CircleRadius(npc->unk_44);
                                }
                                if (CircleInSector(circle, area)) {
                                    fx32 dist = ApproxLength(area.pos.x - circle.pos.x, area.pos.y - circle.pos.y);
                                    if (dist < bestDist) {
                                        best = npc;
                                        bestDist = dist;
                                    }
                                }
                            }
                        }
                        if (best != NULL) {
                            scene->unk_0078 = 5;
                            s_game->m_audioEngine->PlaySe(5);
                            scene->m_subScreen->SwitchToDefaultPanel();
                            scene->ov0_0212451C();
                            if (best->unk_E8 == 1) {
                                UnkStruct_020107A8 *rec = PokeIdTable_Get(s_game->unk_1434, best->unk_EC);
                                RaisePokemonState(save, rec->unk_00, 1);
                                BOOL notCaught = FALSE;
                                if (GetPokemonState(save, rec->unk_00) != 2) {
                                    notCaught = TRUE;
                                }
                                scene->m_subScreen->SwitchToPokemonInfo(best->unk_EC, notCaught);
                                SaveData_AddConversations(save, 1);
                            } else {
                                switch (best->unk_EC) {
                                case 0x5C:
                                case 0x67:
                                case 0x76:
                                case 0x90:
                                    SaveData_AddTargetsChecked(save, 1);
                                    break;
                                default:
                                    SaveData_AddConversations(save, 1);
                                    break;
                                }
                            }
                            best->sub_0203DA38();
                            return FALSE;
                        }
                    }

                    if (objects != NULL && !busy) {
                        fx32 bestDist = 0x30000;
                        CFieldTargetObject *best = NULL;
                        for (int i = 0; i < objects->m_count; i++) {
                            CFieldTargetObject *obj = (CFieldTargetObject *)objects->Get(i);
                            if (obj != NULL && obj->IsActive() && !obj->IsHidden() && obj->ov0_0213CFDC() && obj->m_layer == player->m_layer) {
                                Circle circle;
                                circle.pos = obj->GetPos();
                                if (obj->unk_50 == 0) {
                                    circle.r = (RectWidth(obj->unk_34) + RectHeight(obj->unk_34)) / 2;
                                } else {
                                    circle.r = CircleRadius(obj->unk_44);
                                }
                                if (CircleInSector(circle, area)) {
                                    fx32 dist = ApproxLength(area.pos.x - circle.pos.x, area.pos.y - circle.pos.y);
                                    if (dist < bestDist) {
                                        best = obj;
                                        bestDist = dist;
                                    }
                                }
                            }
                        }
                        if (best != NULL) {
                            scene->ov0_0212451C();
                            scene->m_subScreen->SwitchToDefaultPanel();
                            s_game->m_audioEngine->PlaySe(5);
                            best->sub_0203DA38();
                            SaveData_AddTargetsChecked(save, 1);
                            return FALSE;
                        }
                    }
                }
            }

            if (touch != NULL) {
                if (touch->unk_04) {
                    touchHandled = TRUE;
                    i = FALSE;
                    if (scene->unk_00AA != 0xFFFF && scene->m_effects->ov0_02143088(scene->unk_00AA) != NULL) {
                        CFieldPlayer *self = scene->m_player;
                        Point2D pos = GetHeadPos(self);
                        Rectangle rect;
                        rect.pos.x = pos.x;
                        rect.pos.y = pos.y - 0x8000;
                        rect.size.y = 0x10000;
                        rect.size.x = 0x10000;
                        if (PointInRect(touchPos, rect, 0)) {
                            scene->ov0_021241B8();
                            i = TRUE;
                        }
                    }
                    if (touched != NULL && !i) {
                        Rectangle rect = GetTouchRect(touched);
                        Rectangle screen;
                        screen.pos.x = -GetCamPos().x;
                        screen.pos.y = -GetCamPos().y;
                        screen.size.x = 0xE0000;
                        screen.size.y = 0x80000;
                        BOOL onScreen = RectanglesOverlap(rect, screen);
                        switch (GetKind(touched)) {
                        case 0:
                            if (save->unk_8802 == 2) {
                                UnkStruct_020107A8 *rec = PokeIdTable_Get(s_game->unk_1434, 0x2B);
                                scene->unk_0078 = 0;
                                s_game->m_textboxData->SetParam(0, rec->unk_00);
                                scene->ov0_02123AEC(0x10, 0);
                                s_game->m_audioEngine->PlaySe(5);
                            } else {
                                scene->unk_0078 = 1;
                            }
                            scene->m_subScreen->SwitchToDefaultPanel();
                            break;
                        case 1: {
                            scene->unk_0078 = 4;
                            s_game->m_audioEngine->PlaySe(5);
                            scene->ov0_0212451C();
                            StartOutline((CFieldEnemy *)touched, 0x1F, 300);
                            RaisePokemonState(save, ((CFieldEnemy *)touched)->unk_E4, 1);
                            int mode = 0;
                            if (busy) {
                                mode = 2;
                            } else if (GetPokemonState(save, ((CFieldEnemy *)touched)->unk_E4) != 2) {
                                mode = 1;
                            }
                            scene->m_subScreen->SwitchToPokemonInfo(((CFieldEnemy *)touched)->unk_E8, mode);
                            break;
                        }
                        case 2: {
                            scene->m_subScreen->SwitchToDefaultPanel();
                            scene->ov0_0212451C();
                            if (((CFieldNpc *)touched)->m_layer == player->m_layer) {
                                scene->unk_0078 = 5;
                                s_game->m_audioEngine->PlaySe(5);
                                if (((CFieldNpc *)touched)->unk_E8 == 1) {
                                    UnkStruct_020107A8 *rec = PokeIdTable_Get(s_game->unk_1434, ((CFieldNpc *)touched)->unk_EC);
                                    RaisePokemonState(save, rec->unk_00, 1);
                                    BOOL notCaught = FALSE;
                                    if (GetPokemonState(save, rec->unk_00) != 2) {
                                        notCaught = TRUE;
                                    }
                                    scene->m_subScreen->SwitchToPokemonInfo(((CFieldNpc *)touched)->unk_EC, notCaught);
                                }
                                if (onScreen) {
                                    ((CFieldNpc *)touched)->sub_0203DA38();
                                    if (((CFieldNpc *)touched)->unk_E8 == 0) {
                                        switch (((CFieldNpc *)touched)->unk_EC) {
                                        case 0x5C:
                                        case 0x67:
                                        case 0x76:
                                        case 0x90:
                                            SaveData_AddTargetsChecked(save, 1);
                                            break;
                                        default:
                                            SaveData_AddConversations(save, 1);
                                            break;
                                        }
                                    } else {
                                        if (((CFieldNpc *)touched)->unk_1D4 == 0) {
                                            StartOutline((CFieldNpc *)touched, 0x3F0, 300);
                                        }
                                        SaveData_AddConversations(save, 1);
                                    }
                                } else {
                                    StartOutline((CFieldNpc *)touched, 0x3F0, 300);
                                }
                            }
                            return FALSE;
                        }
                        case 3: {
                            scene->ov0_0212451C();
                            if (((CFieldTargetObject *)touched)->unk_20 == 2 && !busy) {
                                if (((CFieldTargetObject *)touched)->ov0_0213CFDC()) {
                                    if (onScreen && ((CFieldTargetObject *)touched)->m_layer == player->m_layer) {
                                        ((CFieldTargetObject *)touched)->sub_0203DA38();
                                        SaveData_AddTargetsChecked(save, 1);
                                        return FALSE;
                                    }
                                } else {
                                    scene->unk_0078 = 3;
                                    scene->m_partnerPokemon = (CFieldPartnerPokemon *)touched;
                                    s_game->m_audioEngine->PlaySe(5);
                                    scene->m_subScreen->SwitchToTargetInfo(((CFieldTargetObject *)touched)->unk_E8);
                                    StartOutline((CFieldTargetObject *)touched, 0x3F0, 300);
                                    SaveData_AddTargetsChecked(save, 1);
                                }
                            }
                            break;
                        }
                        case 6: {
                            BrightnessFade *fade = s_game->m_mainFade;
                            WindowWipe *wipe = s_game->m_mainWipe;
                            if (!fade->IsActive() && fade->GetMode() != 2 && fade->GetMode() != 4 && !wipe->func0() && !wipe->sub_0200E91C()) {
                                UnkStruct_020107A8 *rec = PokeIdTable_Get(s_game->unk_1434, ((CFieldPartnerPokemon *)touched)->unk_200);
                                scene->m_partnerPokemon = (CFieldPartnerPokemon *)touched;
                                s_game->m_audioEngine->PlaySe(5);
                                scene->m_subScreen->SwitchToPokemonInfo(((CFieldPartnerPokemon *)touched)->unk_200, 0);
                                scene->ov0_0212451C();
                                StartOutline((CFieldPartnerPokemon *)touched, 0x7FE0, -1);
                                u32 type = rec->unk_05;
                                if (type != 0 && type == scene->unk_0090 && rec->unk_06 >= scene->unk_0094 && scene->unk_0098[0] != 0) {
                                    int arg = 0;
                                    scene->unk_0078 = 0;
                                    switch ((int)((CFieldPartnerPokemon *)touched)->unk_200) {
                                    case 0x6A:
                                    case 0x8E:
                                    case 0xA9:
                                    case 0xAC:
                                    case 0xBE:
                                    case 0x129:
                                        arg = 1;
                                        s_game->m_textboxData->SetParam(0, rec->unk_00);
                                        break;
                                    default:
                                        s_game->m_textboxData->SetParam(0, rec->unk_05);
                                        break;
                                    }
                                    scene->ov0_02123AEC(10, arg);
                                } else {
                                    if (type == 0xC) {
                                        if (save->m_areaType == 2) {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->SetParam(0, rec->unk_05);
                                            scene->ov0_02123AEC(0x17, 0);
                                        } else {
                                            s_game->m_textboxData->SetTextSpeed(0);
                                            s_game->m_textboxData->SetParam(0, rec->unk_05);
                                            s_game->m_textboxData->ShowMessage(0, 0x53, 1, 1, 0);
                                            scene->ov0_02123AEC(0x19, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (type == 9) {
                                        if (save->m_energy == save->m_maxEnergy) {
                                            scene->unk_0078 = 0;
                                            scene->ov0_02123AEC(0xC, 0);
                                        } else {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->SetParam(0, rec->unk_05);
                                            scene->ov0_02123AEC(0xB, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (type == 10) {
                                        if (save->m_areaType == 0) {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->SetParam(0, rec->unk_00);
                                            scene->ov0_02123AEC(0xF, 0);
                                        } else {
                                            s_game->m_textboxData->SetTextSpeed(0);
                                            s_game->m_textboxData->SetParam(0, rec->unk_00);
                                            s_game->m_textboxData->ShowMessage(0, 0x52, 1, 1, 0);
                                            scene->ov0_02123AEC(0x19, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (type == 11) {
                                        if (save->m_areaType == 0) {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->SetParam(0, rec->unk_00);
                                            scene->ov0_02123AEC(0x15, 0);
                                        } else {
                                            s_game->m_textboxData->SetTextSpeed(0);
                                            s_game->m_textboxData->SetParam(0, rec->unk_00);
                                            s_game->m_textboxData->ShowMessage(0, 0x52, 1, 1, 0);
                                            scene->ov0_02123AEC(0x19, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (sub_020107C4(type) == 3) {
                                        if (scene->unk_0090 >= 0) {
                                            s_game->m_textboxData->SetTextSpeed(0);
                                            if (scene->unk_0090 == 0x15 && rec->unk_05 == 0x15 && rec->unk_06 < scene->unk_0094) {
                                                s_game->m_textboxData->SetParam(0, rec->unk_00);
                                                s_game->m_textboxData->ShowMessage(0, 0x52, 1, 1, 0);
                                            } else {
                                                s_game->m_textboxData->SetParam(0, rec->unk_05);
                                                s_game->m_textboxData->ShowMessage(0, 0x53, 1, 1, 0);
                                            }
                                            scene->ov0_02123AEC(0x19, 0);
                                        } else {
                                            scene->unk_0078 = 6;
                                        }
                                        return FALSE;
                                    }
                                    if (busy) {
                                        scene->unk_0078 = 6;
                                    } else {
                                        scene->unk_0078 = 2;
                                    }
                                }
                            }
                            break;
                        }
                        case 5:
                            touched->sub_0203DA38();
                            scene->m_subScreen->SwitchToDefaultPanel();
                            return FALSE;
                        case 4:
                        default:
                            scene->m_subScreen->SwitchToDefaultPanel();
                            break;
                        }
                    } else {
                        scene->m_subScreen->SwitchToDefaultPanel();
                    }
                } else if (touch->unk_05) {
                    touchHandled = TRUE;
                    switch (scene->unk_0078) {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2: {
                        CFieldPartnerPokemon *partner = scene->m_partnerPokemon;
                        BOOL done = FALSE;
                        if (touched != NULL && GetKind(touched) == 3) {
                            Rectangle rect = GetTouchRect(touched);
                            Rectangle screen;
                            screen.pos.x = -GetCamPos().x;
                            screen.pos.y = -GetCamPos().y;
                            screen.size.x = 0xE0000;
                            screen.size.y = 0x80000;
                            BOOL onScreen = RectanglesOverlap(rect, screen);
                            FieldTargetObjectData *data = FieldData_GetTargetObject(table, ((CFieldTargetObject *)touched)->unk_E8);
                            Point2D partnerPos = partner->GetPos();
                            Point2D objPos = ((CFieldTargetObject *)touched)->GetPos();
                            BOOL started;
                            int layerId = MAIN_BSS_0210CA48->m_layer;
                            CFieldMapLayerCollision *layer = scene->m_map->GetLayer(layerId);
                            PointPair2D move = { partnerPos, objPos };
                            UnkStruct_020107A8 *rec = PokeIdTable_Get(s_game->unk_1434, partner->unk_200);
                            started = FALSE;
                            Point2D hit;
                            if (!layer->Sweep(&move, 0x4000, &hit, 1) && layerId == ((CFieldTargetObject *)touched)->m_layer && ((CFieldTargetObject *)touched)->unk_20 == 2) {
                                if (rec->unk_05 != 0 && rec->unk_06 != 0 && data->unk_03 == 1 && rec->unk_05 == data->unk_04 && rec->unk_06 >= data->unk_05 && onScreen) {
                                    scene->unk_0078 = 0;
                                    s_game->m_textboxData->SetParam(0, rec->unk_05);
                                    scene->ov0_02123AEC(1, 0);
                                    scene->unk_0080 = touched;
                                    s_game->m_audioEngine->PlaySe(0);
                                    scene->ov0_0212451C();
                                    StartOutline(partner, 0x21F, -1);
                                    StartOutline((CFieldTargetObject *)touched, 0x21F, -1);
                                    started = TRUE;
                                }
                            }
                            if (!started && !((CFieldTargetObject *)touched)->ov0_0213CFDC() && ((CFieldTargetObject *)touched)->unk_20 == 2) {
                                scene->m_subScreen->SwitchToTargetInfo(((CFieldTargetObject *)touched)->unk_E8);
                                done = TRUE;
                            }
                            if (started) {
                                return FALSE;
                            }
                        }
                        if (!done) {
                            scene->m_subScreen->SwitchToPokemonInfo(partner->unk_200, 0);
                        }
                        break;
                    }
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    }
                } else if (touch->unk_06) {
                    touchHandled = TRUE;
                    switch (scene->unk_0078) {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2:
                    case 6: {
                        CFieldPartnerPokemon *partner = scene->m_partnerPokemon;
                        if (partner != NULL) {
                            StartOutline(partner, 0x7FE0, 300);
                        }
                        break;
                    }
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    default:
                        goto released;
                    }
                    scene->unk_0078 = 0;
released:;
                }
            }

            if (!touchHandled) {
                switch (scene->unk_0078) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    scene->unk_0078 = 0;
                    break;
                }
            }

            if (pad != NULL) {
                i = FALSE;
                if (!touchHandled && IsMenuAllowed(scene)) {
                    if (IsTrigger(pad, PAD_BUTTON_L) && save->IsButton1Enabled()) {
                        FieldSubScreen *inst = FieldSubScreen::GetInstance();
                        if (inst != NULL) {
                            inst->sub_02022D88();
                            s_game->m_audioEngine->PlaySe(0xFA);
                            if (scene->unk_004C != NULL) {
                                scene->unk_004C->ov0_0214FD24();
                            }
                        }
                        i = TRUE;
                    } else if (IsTrigger(pad, PAD_BUTTON_R) && save->IsButton2Enabled()) {
                        FieldSubScreen *inst = FieldSubScreen::GetInstance();
                        SubScreenIconMenu *menu = scene->m_iconMenu;
                        if (inst != NULL && menu != NULL) {
                            inst->SwitchToRangerCard();
                            menu->Open();
                            CFieldPlayer *p = MAIN_BSS_0210CA48;
                            if (p != NULL) {
                                p->ResetUnk00C();
                                int mask = p->m_drawObject->m_actor->unk_1A0;
                                if ((mask == 0x80000 || mask == 0x800000) && s_game->m_audioEngine->IsSePlaying(0x10E)) {
                                    s_game->m_audioEngine->StopSe(0x10E);
                                }
                            }
                            s_game->m_audioEngine->PlaySe(0xFA);
                            if (scene->unk_0050 != NULL) {
                                scene->unk_0050->ov0_0214FF44();
                            }
                        }
                        i = TRUE;
                    }
                }
                if (!i && IsTrigger(pad, PAD_BUTTON_X | PAD_BUTTON_Y)) {
                    scene->ov0_0212451C();
                    scene->m_partners->SetOutlineAll(0x7FE0, 2, 300);
                }
                if (i) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}
