#include "field/CFieldEnemy.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldScene *MAIN_BSS_0210CA40;
extern CFieldEffectManage *MAIN_BSS_0210CA60;

extern "C" {
void LogError(const char *fmt, ...);
}

CFieldEnemy::CFieldEnemy()
{
    m_flags |= 0x400;
    unk_EC = 4;
    unk_10 = 0x2000;
    Rectangle bounds = { { 0, -0x8000 }, { 0x10000, 0x20000 } };
    unk_24.pos.x = bounds.pos.x;
    unk_24.pos.y = bounds.pos.y;
    unk_24.size.x = bounds.size.x;
    unk_24.size.y = bounds.size.y;
    unk_F0 = 10;
    unk_F4 = 10;
    unk_F8 = 90;
    unk_FC = 90;
    unk_100 = 100;
    unk_104 = 0x1000;
    unk_108 = 0x1000;
    unk_10C = 0x1000;
    unk_110 = 0x1000;
    unk_114 = 1;
    unk_118 = 1;
    unk_11C = 1;
    unk_120 = 100;
    unk_124 = 10;
    unk_128 = 10;
    unk_12C = 60;
    unk_12E = 60;
    unk_130 = 0;
    unk_144 = 0;
    unk_146 = 0;
    for (int i = 0; i < 3; i++) {
        unk_132[i] = 0;
    }
    unk_138 = 0;
    unk_13C = -1;
    unk_148 = 0;
    unk_160 = 0;
    unk_164 = 0;
    unk_158.x = 0x1000;
    unk_158.y = 0;
    unk_168.unk_48 = this;
    m_bushMode = 2;
    unk_244 = 0;
    unk_250 = 1;
    unk_254 = 0;
    unk_256 = 0;
}

CFieldEnemy::~CFieldEnemy()
{
}

int CFieldEnemy::ov0_021343B8(int index)
{
    if (index >= 0 && index < 3) {
        switch (unk_132[index]) {
        case 0:
            return -1;
        case 1:
            PlayAnim(0x20, 0);
            return 0;
        case 2:
            PlayAnim(0x20, 1);
            return 0;
        case 3:
            PlayAnim(0x20, 2);
            return 0;
        case 4:
            PlayAnim(0x20, 3);
            return 0;
        case 5:
            PlayAnim(0x10, 0);
            return 0;
        case 6:
            PlayAnim(0x10, 1);
            return 0;
        case 7:
            PlayAnim(8, 0);
            return 0;
        }
    } else {
        LogError("ERROR : FieldEnemy.cpp PlayEnemyAnime ");
    }
    return -1;
}

void CFieldEnemy::Process(CFieldMap *map)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player != NULL) {
        Point2D d = player->GetPos() - GetPos();
        int dx = d.x >> FX32_SHIFT;
        int dy = d.y >> FX32_SHIFT;
        int dz = GetHeight() >> FX32_SHIFT;
        unk_148 = dx * dx + dy * dy + dz * dz;
    }
    if (unk_250 == 1 && unk_148 > 90000) {
        return;
    }
    switch (unk_EC) {
    case 0:
        if (ov0_02134D60(unk_F0)) {
            unk_EC = 1;
            s_game->m_audioEngine->sub_02034D44(0, 0x40);
            m_flags &= ~1;
            if (MAIN_BSS_0210CA48 != NULL) {
                Point2D dir = MAIN_BSS_0210CA48->GetPos() - GetPos();
                fx32 len = FX_Sqrt(FX32_MUL(dir.x, dir.x) + FX32_MUL(dir.y, dir.y));
                if (len != 0) {
                    dir.x = FX_Div(dir.x, len);
                    dir.y = FX_Div(dir.y, len);
                    dir.x = FX32_MUL(dir.x, 0x14000);
                    dir.y = FX32_MUL(dir.y, 0x14000);
                    Point2D dest = GetPos() + dir;
                    if (m_drawObject != NULL) {
                        if (m_drawObject->m_actor != NULL) {
                            m_drawObject->m_actor->Jump(0x23000, 30);
                        }
                        if (m_drawObject->m_actor != NULL) {
                            m_drawObject->m_actor->m_motion.MoveLinear(dest, 30);
                        }
                    }
                }
            }
            ov0_021352E4(1);
        }
        break;
    case 1:
        if (ov0_02134D60(unk_124 >> FX32_SHIFT)) {
            unk_EC = 4;
            if (MAIN_BSS_0210CA40 != NULL) {
                MAIN_BSS_0210CA40->ov0_02122F08(this);
            }
        }
        if (!IsUnk00CSet()) {
            unk_EC = 4;
        }
        break;
    case 2:
        m_flags &= ~2;
        if (ov0_02134D60(unk_F0)) {
            s_game->m_audioEngine->PlaySe(0x10A);
            unk_EC = 3;
            m_flags &= ~1;
            SetBaseHeight(0x96000);
        }
        break;
    case 3: {
        if (ov0_02134D60(unk_124 >> FX32_SHIFT)) {
            CFieldScene *scene = MAIN_BSS_0210CA40;
            if (unk_130 != 0) {
                fx32 dist = FX_Sqrt(unk_148 << FX32_SHIFT);
                Point2D v = player->GetPos() - GetPos();
                v.x = FX_Div(v.x, dist);
                v.y = FX_Div(v.y, dist);
                player->ov0_021333A0(v.x, v.y, 10, unk_130, -1);
            } else if (scene != NULL) {
                unk_EC = 4;
                scene->ov0_02122F08(this);
            }
        }
        int height = GetBaseHeight();
        fx32 vz = m_fallSpeed - m_gravity;
        if (vz < -0x14000) {
            vz = -0x14000;
        }
        m_fallSpeed = vz;
        height += vz;
        SetBaseHeight(height);
        if (GetBaseHeight() <= 0) {
            SetBaseHeight(0);
            m_fallSpeed = 0;
            if (unk_A0 > 0) {
                m_flags |= 2;
            }
            ov0_021352E4(0);
            unk_EC = 4;
        }
        break;
    }
    case 4:
        if (m_flags & 0x400) {
            ov0_02134F70();
        }
        UpdateScript();
        if (--unk_164 < 0) {
            unk_164 = 0;
        }
        break;
    }
    unk_168.ov0_02152B04();
    Update(map);
    ov0_0213524C();
}

BOOL CFieldEnemy::UpdateMove(CFieldMap *map)
{
    BOOL result = CFieldActor::UpdateMove(map);
    unk_168.ov0_02158988();
    ov0_0213524C();
    if (result) {
        s_game->m_audioEngine->PlayStream(unk_E4, 0x40);
    }
    return result;
}

BOOL CFieldEnemy::ov0_02134D60(int radius)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player != NULL) {
        Point2D d = player->GetPos() - GetPos();
        if (GetHeight() <= (radius << FX32_SHIFT) + 0x19000) {
            int dx = d.x >> FX32_SHIFT;
            int dy = d.y >> FX32_SHIFT;
            int r = radius + (player->unk_E0 >> FX32_SHIFT);
            r *= r;
            if (dx * dx + dy * dy <= r) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void CFieldEnemy::ov0_02134F00()
{
    m_flags |= 1;
    SetBaseHeight(0);
    unk_168.ov0_0215674C(0xE);
}

void CFieldEnemy::ov0_02134F38()
{
    m_flags |= 1;
    SetBaseHeight(0xDC000);
    unk_168.ov0_0215674C(0xF);
}

void CFieldEnemy::ov0_02134F70()
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    if (player->m_layer != m_layer) {
        return;
    }
    if (ov0_02134D60(unk_124 >> FX32_SHIFT) && MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->ov0_02122F08(this);
    }
}

void CFieldEnemy::ov0_02134FCC()
{
    CFieldTargetObjectManage *manage = MAIN_BSS_0210CA7C;
    if (manage == NULL || unk_13C < 0) {
        return;
    }
    CFieldActor *target = manage->FindTarget(unk_13C);
    if (target == NULL) {
        return;
    }
    target->SetPos(GetPos());
    target->SetHomePos(GetPos());
    target->unk_20 = 2;
    m_flags |= 0x800;
}

void CFieldEnemy::ov0_021351AC()
{
    CFieldTargetObjectManage *manage = MAIN_BSS_0210CA7C;
    if (manage == NULL || unk_13C < 0) {
        return;
    }
    CFieldActor *target = manage->FindTarget(unk_13C);
    if (target == NULL) {
        return;
    }
    Actor_HideManpu(target);
    target->unk_20 = 0;
    target->sub_0202D394();
    m_flags &= ~0x800;
}

void CFieldEnemy::ov0_0213524C()
{
}

void CFieldEnemy::ov0_02135250()
{
    s_game->m_audioEngine->PlayStream(unk_E4, 0x40);
}

CFieldActor *CFieldEnemy::ov0_02135278()
{
    CFieldTargetObjectManage *manage = MAIN_BSS_0210CA7C;
    if (manage != NULL && unk_13C >= 0) {
        return manage->FindTarget(unk_13C);
    }
    return NULL;
}

void CFieldEnemy::ov0_021352E4(int arg1)
{
    CFieldEffectManage *manage = MAIN_BSS_0210CA60;
    if (manage == NULL) {
        return;
    }
    fx32 x = GetX();
    fx32 y = GetY();
    int cell = 0;
    if (m_map != NULL) {
        CFieldMapLayerAttribute *attr = m_map->GetAttributeLayer(m_layer);
        if (attr != NULL) {
            cell = attr->GetCellAtPos(x, y);
        }
    }
    CFieldEffect *effect;
    switch (cell) {
    case 0:
        break;
    case 1:
    case 6:
        effect = manage->ov0_02143088(manage->ov0_02142F6C(0xB, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(0, 8);
        effect->SetParam(8, 20);
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, y >> FX32_SHIFT);
        effect->SetParam(3, 0);
        effect->SetParam(4, 0);
        effect->ov0_021421F0(0, -1, 0);
        break;
    case 3:
    case 4:
    case 8:
        effect = manage->ov0_02143088(manage->ov0_02142F6C(0xA, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(0, 16);
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, (y >> FX32_SHIFT) + 8);
        effect->SetParam(3, 16);
        effect->SetParam(4, 0);
        effect->ov0_021421F0(0, -1, 0);
        break;
    case 2:
    case 5:
        effect = manage->ov0_02143088(manage->ov0_02142F6C(0x26, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, (y >> FX32_SHIFT) + 8);
        effect->ov0_021421F0(0, -1, 0);
        break;
    case 7:
    case 9:
    case 10:
        break;
    case 11:
        effect = manage->ov0_02143088(manage->ov0_02142F6C(0xA, 0));
        if (effect == NULL) {
            return;
        }
        effect->SetParam(0, 16);
        effect->SetParam(1, x >> FX32_SHIFT);
        effect->SetParam(2, (y >> FX32_SHIFT) + 8);
        effect->SetParam(3, 16);
        effect->SetParam(4, 0);
        effect->SetParam(19, 1);
        effect->ov0_021421F0(0, -1, 0);
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
        break;
    }
}

void CFieldEnemy::ov0_021356BC(void *buf, void *end)
{
    unk_168.ov0_0215844C(buf, end);
}

void CFieldEnemy::ov0_021356CC(void *data)
{
    unk_168.ov0_021585B8(data);
}

void CFieldEnemy::sub_0202D394()
{
    unk_168.ov0_02158954();
}

void CFieldEnemy::ov0_021356EC()
{
    // SetPosXY written out: the declaration order of these locals is the original's register order.
    fx32 y = unk_1C;
    CFieldDrawObject *obj = m_drawObject;
    CFieldDrawActor *sprite;
    fx32 x = unk_18;
    if (obj != NULL && (sprite = obj->m_actor) != NULL) {
        sprite->SetXY(x, y);
        if (obj->m_actor->m_sprite != NULL) {
            obj->m_actor->m_sprite->SetXY(x, y);
        }
    }
    sub_020128EC_(unk_256);
    u16 dir = unk_256;
    unk_158.x = FX_CosIdx(dir);
    unk_158.y = FX_SinIdx(dir);
    unk_168.unk_30 = GetUnk158();
    sub_0201287C_();
}

void CFieldEnemy::sub_02032A44(int arg0)
{
    unk_168.ov0_0215674C(arg0);
}
