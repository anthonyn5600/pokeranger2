#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Camera2D.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200D3F8.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E330.hpp"
#include "UnkClass_02022404.hpp"
#include "UnkClass_020233C8.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_02041C80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkClass_0211D850.hpp"
#include "UnkStruct_020107A8.hpp"
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
#include "sub_02006000.hpp"
#include "sub_02007254.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldNpcManage *MAIN_BSS_0210CA50;
extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;
extern UnkClass_0211D850 *MAIN_BSS_0210CA78;
extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

extern "C" {
u32 sub_02016DEC(UnkClass_020B26A0 *save, u32 value);
u32 sub_02016E34(UnkClass_020B26A0 *save, u32 value);
int sub_020107C4(int arg0);
void ov0_0214FD24(UnkClass_0214FB28 *obj);
void ov0_0214FF44(UnkClass_0214FD4C *obj);
}

static inline u32 GetPokemonState(UnkClass_020B26A0 *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->unk_7C3C[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline void SetPokemonState(UnkClass_020B26A0 *save, int i, u32 state)
{
    int shift = (i & 0xF) * 2;
    save->unk_7C3C[i >> 4] &= ~(3 << shift);
    save->unk_7C3C[i >> 4] |= state << shift;
}

static inline void RaisePokemonState(UnkClass_020B26A0 *save, int i, u32 state)
{
    if (i >= 0 && i < 500) {
        if (GetPokemonState(save, i) < state) {
            SetPokemonState(save, i, state);
        }
    }
}

static inline void StartOutline(CFieldActor *actor, u16 color, int time)
{
    if (actor->unk_08 != NULL) {
        CFieldDrawActor *draw = actor->unk_08->unk_0C;
        if (draw != NULL) {
            draw->m_outlinePhase = 0;
        }
        draw = actor->unk_08->unk_0C;
        if (draw != NULL) {
            draw->m_outlineColor = color;
            draw->m_outlinePhase = 0;
        }
        draw = actor->unk_08->unk_0C;
        if (draw != NULL) {
            draw->m_outlineWidth = 2;
        }
        draw = actor->unk_08->unk_0C;
        if (draw != NULL) {
            draw->unk_1A8 |= 1;
            draw->m_outlineTime = time;
            draw->m_outlinePhase = 0;
        }
    }
}

static inline u16 IsTrigger(UnkClass_02001C04 *pad, u16 mask)
{
    return pad->unk_0002 & mask;
}

static inline BOOL IsMenuAllowed(CFieldScene *scene)
{
    return (scene->unk_00D0 & 0x800) ? FALSE : TRUE;
}

static inline Point2D GetHeadPos(CFieldActor *actor)
{
    Point2D head = *(Point2D *)&actor->unk_70 + actor->GetPos();
    head.y -= actor->GetHeight();
    return head;
}

static inline UnkClass_02041C80 *GetTargetTable()
{
    return MAIN_BSS_0210CA6C;
}

static inline int GetKind(CFieldActor *actor)
{
    return ((int)actor->unk_58 >> 24) & 0xFF;
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
    Camera2D *cam = (Camera2D *)s_game->unk_14B8->unk_00;
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
    UnkClass_02001C04 *pad,
    CTouchPanel *touch)
{
    if (scene != NULL) {
        UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
        // C89-style scratch, reused as the NPC loop counter, the effect icon hit and the button result (register order)
        int i;
        UnkClass_02041C80 *table = GetTargetTable();
        // Used through casts per kind: typed alias locals would be coalesced with it and change its register
        CFieldActor *touched = scene->ov0_021232A8();
        BOOL busy = FALSE;
        if (MAIN_BSS_0210CA78 != NULL && MAIN_BSS_0210CA78->sub_02035ECC(0xB)) {
            busy = TRUE;
        }

        Point2D touchPos;
        if (touch != NULL) {
            fx32 x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
            fx32 y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
            x -= scene->unk_0008->unk_1C;
            y -= scene->unk_0008->unk_20;
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
                            if (npc != NULL && npc->IsActive() && !npc->IsUnk04Bit0() && npc->unk_14 == player->unk_14) {
                                Circle circle;
                                circle.pos = npc->GetPos();
                                if (npc->unk_50 == 0) {
                                    circle.r = (RectWidth(npc->unk_34) + RectHeight(npc->unk_34)) / 2;
                                } else {
                                    circle.r = CircleRadius(npc->unk_44);
                                }
                                if (sub_02006238(circle, area)) {
                                    fx32 dist = sub_02007254(area.pos.x - circle.pos.x, area.pos.y - circle.pos.y);
                                    if (dist < bestDist) {
                                        best = npc;
                                        bestDist = dist;
                                    }
                                }
                            }
                        }
                        if (best != NULL) {
                            scene->unk_0078 = 5;
                            s_game->m_audioEngine->sub_02034C44(5);
                            scene->unk_0054->sub_02022DD4();
                            scene->ov0_0212451C();
                            if (best->unk_E8 == 1) {
                                UnkStruct_020107A8 *rec = sub_020107A8(s_game->unk_1434, best->unk_EC);
                                RaisePokemonState(save, rec->unk_00, 1);
                                BOOL notCaught = FALSE;
                                if (GetPokemonState(save, rec->unk_00) != 2) {
                                    notCaught = TRUE;
                                }
                                scene->unk_0054->sub_02022B60(best->unk_EC, notCaught);
                                sub_02016DEC(save, 1);
                            } else {
                                switch (best->unk_EC) {
                                case 0x5C:
                                case 0x67:
                                case 0x76:
                                case 0x90:
                                    sub_02016E34(save, 1);
                                    break;
                                default:
                                    sub_02016DEC(save, 1);
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
                            if (obj != NULL && obj->IsActive() && !obj->IsUnk04Bit0() && obj->ov0_0213CFDC() && obj->unk_14 == player->unk_14) {
                                Circle circle;
                                circle.pos = obj->GetPos();
                                if (obj->unk_50 == 0) {
                                    circle.r = (RectWidth(obj->unk_34) + RectHeight(obj->unk_34)) / 2;
                                } else {
                                    circle.r = CircleRadius(obj->unk_44);
                                }
                                if (sub_02006238(circle, area)) {
                                    fx32 dist = sub_02007254(area.pos.x - circle.pos.x, area.pos.y - circle.pos.y);
                                    if (dist < bestDist) {
                                        best = obj;
                                        bestDist = dist;
                                    }
                                }
                            }
                        }
                        if (best != NULL) {
                            scene->ov0_0212451C();
                            scene->unk_0054->sub_02022DD4();
                            s_game->m_audioEngine->sub_02034C44(5);
                            best->sub_0203DA38();
                            sub_02016E34(save, 1);
                            return FALSE;
                        }
                    }
                }
            }

            if (touch != NULL) {
                if (touch->unk_04) {
                    touchHandled = TRUE;
                    i = FALSE;
                    if (scene->unk_00AA != 0xFFFF && scene->unk_0028->ov0_02143088(scene->unk_00AA) != NULL) {
                        CFieldPlayer *self = scene->unk_0014;
                        Point2D pos = GetHeadPos(self);
                        Rectangle rect;
                        rect.pos.x = pos.x;
                        rect.pos.y = pos.y - 0x8000;
                        rect.size.y = 0x10000;
                        rect.size.x = 0x10000;
                        if (sub_02006000(touchPos, rect, 0)) {
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
                                UnkStruct_020107A8 *rec = sub_020107A8(s_game->unk_1434, 0x2B);
                                scene->unk_0078 = 0;
                                s_game->m_textboxData->sub_020097FC(0, rec->unk_00);
                                scene->ov0_02123AEC(0x10, 0);
                                s_game->m_audioEngine->sub_02034C44(5);
                            } else {
                                scene->unk_0078 = 1;
                            }
                            scene->unk_0054->sub_02022DD4();
                            break;
                        case 1: {
                            scene->unk_0078 = 4;
                            s_game->m_audioEngine->sub_02034C44(5);
                            scene->ov0_0212451C();
                            StartOutline((CFieldEnemy *)touched, 0x1F, 300);
                            RaisePokemonState(save, ((CFieldEnemy *)touched)->unk_E4, 1);
                            int mode = 0;
                            if (busy) {
                                mode = 2;
                            } else if (GetPokemonState(save, ((CFieldEnemy *)touched)->unk_E4) != 2) {
                                mode = 1;
                            }
                            scene->unk_0054->sub_02022B60(((CFieldEnemy *)touched)->unk_E8, mode);
                            break;
                        }
                        case 2: {
                            scene->unk_0054->sub_02022DD4();
                            scene->ov0_0212451C();
                            if (((CFieldNpc *)touched)->unk_14 == player->unk_14) {
                                scene->unk_0078 = 5;
                                s_game->m_audioEngine->sub_02034C44(5);
                                if (((CFieldNpc *)touched)->unk_E8 == 1) {
                                    UnkStruct_020107A8 *rec = sub_020107A8(s_game->unk_1434, ((CFieldNpc *)touched)->unk_EC);
                                    RaisePokemonState(save, rec->unk_00, 1);
                                    BOOL notCaught = FALSE;
                                    if (GetPokemonState(save, rec->unk_00) != 2) {
                                        notCaught = TRUE;
                                    }
                                    scene->unk_0054->sub_02022B60(((CFieldNpc *)touched)->unk_EC, notCaught);
                                }
                                if (onScreen) {
                                    ((CFieldNpc *)touched)->sub_0203DA38();
                                    if (((CFieldNpc *)touched)->unk_E8 == 0) {
                                        switch (((CFieldNpc *)touched)->unk_EC) {
                                        case 0x5C:
                                        case 0x67:
                                        case 0x76:
                                        case 0x90:
                                            sub_02016E34(save, 1);
                                            break;
                                        default:
                                            sub_02016DEC(save, 1);
                                            break;
                                        }
                                    } else {
                                        if (((CFieldNpc *)touched)->unk_1D4 == 0) {
                                            StartOutline((CFieldNpc *)touched, 0x3F0, 300);
                                        }
                                        sub_02016DEC(save, 1);
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
                                    if (onScreen && ((CFieldTargetObject *)touched)->unk_14 == player->unk_14) {
                                        ((CFieldTargetObject *)touched)->sub_0203DA38();
                                        sub_02016E34(save, 1);
                                        return FALSE;
                                    }
                                } else {
                                    scene->unk_0078 = 3;
                                    scene->unk_007C = (CFieldPartnerPokemon *)touched;
                                    s_game->m_audioEngine->sub_02034C44(5);
                                    scene->unk_0054->sub_02022BC0(((CFieldTargetObject *)touched)->unk_E8);
                                    StartOutline((CFieldTargetObject *)touched, 0x3F0, 300);
                                    sub_02016E34(save, 1);
                                }
                            }
                            break;
                        }
                        case 6: {
                            UnkClass_0200E0B4 *fade = s_game->unk_14BC;
                            UnkClass_0200E330 *wipe = s_game->unk_14C4;
                            if (!fade->sub_0200E310() && fade->sub_0200E324() != 2 && fade->sub_0200E324() != 4 && !wipe->func0() && !wipe->sub_0200E91C()) {
                                UnkStruct_020107A8 *rec = sub_020107A8(s_game->unk_1434, ((CFieldPartnerPokemon *)touched)->unk_200);
                                scene->unk_007C = (CFieldPartnerPokemon *)touched;
                                s_game->m_audioEngine->sub_02034C44(5);
                                scene->unk_0054->sub_02022B60(((CFieldPartnerPokemon *)touched)->unk_200, 0);
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
                                        s_game->m_textboxData->sub_020097FC(0, rec->unk_00);
                                        break;
                                    default:
                                        s_game->m_textboxData->sub_020097FC(0, rec->unk_05);
                                        break;
                                    }
                                    scene->ov0_02123AEC(10, arg);
                                } else {
                                    if (type == 0xC) {
                                        if (save->unk_8B64 == 2) {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->sub_020097FC(0, rec->unk_05);
                                            scene->ov0_02123AEC(0x17, 0);
                                        } else {
                                            s_game->m_textboxData->sub_0200AA04(0);
                                            s_game->m_textboxData->sub_020097FC(0, rec->unk_05);
                                            s_game->m_textboxData->sub_0200AA84(0, 0x53, 1, 1, 0);
                                            scene->ov0_02123AEC(0x19, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (type == 9) {
                                        if (save->unk_0001 == save->unk_0002) {
                                            scene->unk_0078 = 0;
                                            scene->ov0_02123AEC(0xC, 0);
                                        } else {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->sub_020097FC(0, rec->unk_05);
                                            scene->ov0_02123AEC(0xB, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (type == 10) {
                                        if (save->unk_8B64 == 0) {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->sub_020097FC(0, rec->unk_00);
                                            scene->ov0_02123AEC(0xF, 0);
                                        } else {
                                            s_game->m_textboxData->sub_0200AA04(0);
                                            s_game->m_textboxData->sub_020097FC(0, rec->unk_00);
                                            s_game->m_textboxData->sub_0200AA84(0, 0x52, 1, 1, 0);
                                            scene->ov0_02123AEC(0x19, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (type == 11) {
                                        if (save->unk_8B64 == 0) {
                                            scene->unk_0078 = 0;
                                            s_game->m_textboxData->sub_020097FC(0, rec->unk_00);
                                            scene->ov0_02123AEC(0x15, 0);
                                        } else {
                                            s_game->m_textboxData->sub_0200AA04(0);
                                            s_game->m_textboxData->sub_020097FC(0, rec->unk_00);
                                            s_game->m_textboxData->sub_0200AA84(0, 0x52, 1, 1, 0);
                                            scene->ov0_02123AEC(0x19, 0);
                                        }
                                        return FALSE;
                                    }
                                    if (sub_020107C4(type) == 3) {
                                        if (scene->unk_0090 >= 0) {
                                            s_game->m_textboxData->sub_0200AA04(0);
                                            if (scene->unk_0090 == 0x15 && rec->unk_05 == 0x15 && rec->unk_06 < scene->unk_0094) {
                                                s_game->m_textboxData->sub_020097FC(0, rec->unk_00);
                                                s_game->m_textboxData->sub_0200AA84(0, 0x52, 1, 1, 0);
                                            } else {
                                                s_game->m_textboxData->sub_020097FC(0, rec->unk_05);
                                                s_game->m_textboxData->sub_0200AA84(0, 0x53, 1, 1, 0);
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
                            scene->unk_0054->sub_02022DD4();
                            return FALSE;
                        case 4:
                        default:
                            scene->unk_0054->sub_02022DD4();
                            break;
                        }
                    } else {
                        scene->unk_0054->sub_02022DD4();
                    }
                } else if (touch->unk_05) {
                    touchHandled = TRUE;
                    switch (scene->unk_0078) {
                    case 0:
                        break;
                    case 1:
                        break;
                    case 2: {
                        CFieldPartnerPokemon *partner = scene->unk_007C;
                        BOOL done = FALSE;
                        if (touched != NULL && GetKind(touched) == 3) {
                            Rectangle rect = GetTouchRect(touched);
                            Rectangle screen;
                            screen.pos.x = -GetCamPos().x;
                            screen.pos.y = -GetCamPos().y;
                            screen.size.x = 0xE0000;
                            screen.size.y = 0x80000;
                            BOOL onScreen = RectanglesOverlap(rect, screen);
                            FieldTargetObjectData *data = sub_02041D6C(table, ((CFieldTargetObject *)touched)->unk_E8);
                            Point2D partnerPos = partner->GetPos();
                            Point2D objPos = ((CFieldTargetObject *)touched)->GetPos();
                            BOOL started;
                            int layerId = MAIN_BSS_0210CA48->unk_14;
                            CFieldMapLayerCollision *layer = scene->unk_0010->GetLayer(layerId);
                            PointPair2D move = { partnerPos, objPos };
                            UnkStruct_020107A8 *rec = sub_020107A8(s_game->unk_1434, partner->unk_200);
                            started = FALSE;
                            Point2D hit;
                            if (!layer->Sweep(&move, 0x4000, &hit, 1) && layerId == ((CFieldTargetObject *)touched)->unk_14 && ((CFieldTargetObject *)touched)->unk_20 == 2) {
                                if (rec->unk_05 != 0 && rec->unk_06 != 0 && data->unk_03 == 1 && rec->unk_05 == data->unk_04 && rec->unk_06 >= data->unk_05 && onScreen) {
                                    scene->unk_0078 = 0;
                                    s_game->m_textboxData->sub_020097FC(0, rec->unk_05);
                                    scene->ov0_02123AEC(1, 0);
                                    scene->unk_0080 = touched;
                                    s_game->m_audioEngine->sub_02034C44(0);
                                    scene->ov0_0212451C();
                                    StartOutline(partner, 0x21F, -1);
                                    StartOutline((CFieldTargetObject *)touched, 0x21F, -1);
                                    started = TRUE;
                                }
                            }
                            if (!started && !((CFieldTargetObject *)touched)->ov0_0213CFDC() && ((CFieldTargetObject *)touched)->unk_20 == 2) {
                                scene->unk_0054->sub_02022BC0(((CFieldTargetObject *)touched)->unk_E8);
                                done = TRUE;
                            }
                            if (started) {
                                return FALSE;
                            }
                        }
                        if (!done) {
                            scene->unk_0054->sub_02022B60(partner->unk_200, 0);
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
                        CFieldPartnerPokemon *partner = scene->unk_007C;
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
                        UnkClass_02022404 *inst = UnkClass_02022404::GetInstance();
                        if (inst != NULL) {
                            inst->sub_02022D88();
                            s_game->m_audioEngine->sub_02034C44(0xFA);
                            if (scene->unk_004C != NULL) {
                                ov0_0214FD24(scene->unk_004C);
                            }
                        }
                        i = TRUE;
                    } else if (IsTrigger(pad, PAD_BUTTON_R) && save->IsButton2Enabled()) {
                        UnkClass_02022404 *inst = UnkClass_02022404::GetInstance();
                        UnkClass_020233C8 *menu = scene->unk_0058;
                        if (inst != NULL && menu != NULL) {
                            inst->sub_02022C1C();
                            menu->sub_020234D4();
                            CFieldPlayer *p = MAIN_BSS_0210CA48;
                            if (p != NULL) {
                                p->ResetUnk00C();
                                int mask = p->unk_08->unk_0C->unk_1A0;
                                if ((mask == 0x80000 || mask == 0x800000) && s_game->m_audioEngine->sub_02034C84(0x10E)) {
                                    s_game->m_audioEngine->sub_02034C5C(0x10E);
                                }
                            }
                            s_game->m_audioEngine->sub_02034C44(0xFA);
                            if (scene->unk_0050 != NULL) {
                                ov0_0214FF44(scene->unk_0050);
                            }
                        }
                        i = TRUE;
                    }
                }
                if (!i && IsTrigger(pad, PAD_BUTTON_X | PAD_BUTTON_Y)) {
                    scene->ov0_0212451C();
                    scene->unk_001C->sub_0203F4B8(0x7FE0, 2, 300);
                }
                if (i) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}
