#include "field/CFieldEnemy.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldScene *MAIN_BSS_0210CA40;
extern UnkClass_02142428 *MAIN_BSS_0210CA60;

extern "C" {
void LogError(const char *fmt, ...);
void sub_02034CF4(void *audioEngine, int arg1, int arg2);
void sub_02034D44(void *audioEngine, int arg1, int arg2);
void sub_02034C44(void *audioEngine, int arg1);
void sub_0203C2B8(CFieldActor *actor);
void sub_02012860(UnkClass_0201287C *obj, fx32 arg1, int arg2);
}

CFieldEnemy::CFieldEnemy()
{
    unk_04 |= 0x400;
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
    unk_D4 = 2;
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
            sub_0202DC54(0x20, 0);
            return 0;
        case 2:
            sub_0202DC54(0x20, 1);
            return 0;
        case 3:
            sub_0202DC54(0x20, 2);
            return 0;
        case 4:
            sub_0202DC54(0x20, 3);
            return 0;
        case 5:
            sub_0202DC54(0x10, 0);
            return 0;
        case 6:
            sub_0202DC54(0x10, 1);
            return 0;
        case 7:
            sub_0202DC54(8, 0);
            return 0;
        }
    } else {
        LogError("ERROR : FieldEnemy.cpp PlayEnemyAnime ");
    }
    return -1;
}

void CFieldEnemy::sub_0203DA40(CFieldMap *map)
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
            sub_02034D44(s_game->m_audioEngine, 0, 0x40);
            unk_04 &= ~1;
            if (MAIN_BSS_0210CA48 != NULL) {
                Point2D dir = MAIN_BSS_0210CA48->GetPos() - GetPos();
                fx32 len = FX_Sqrt(FX32_MUL(dir.x, dir.x) + FX32_MUL(dir.y, dir.y));
                if (len != 0) {
                    dir.x = FX_Div(dir.x, len);
                    dir.y = FX_Div(dir.y, len);
                    dir.x = FX32_MUL(dir.x, 0x14000);
                    dir.y = FX32_MUL(dir.y, 0x14000);
                    Point2D dest = GetPos() + dir;
                    if (unk_08 != NULL) {
                        if (unk_08->unk_0C != NULL) {
                            sub_02012860(unk_08->unk_0C, 0x23000, 30);
                        }
                        if (unk_08->unk_0C != NULL) {
                            sub_02011AB0(&unk_08->unk_0C->unk_00C, dest, 30);
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
        unk_04 &= ~2;
        if (ov0_02134D60(unk_F0)) {
            sub_02034C44(s_game->m_audioEngine, 0x10A);
            unk_EC = 3;
            unk_04 &= ~1;
            SetUnk8C(0x96000);
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
        int height = GetUnk8C();
        fx32 vz = unk_A4 - unk_9C;
        if (vz < -0x14000) {
            vz = -0x14000;
        }
        unk_A4 = vz;
        height += vz;
        SetUnk8C(height);
        if (GetUnk8C() <= 0) {
            SetUnk8C(0);
            unk_A4 = 0;
            if (unk_A0 > 0) {
                unk_04 |= 2;
            }
            ov0_021352E4(0);
            unk_EC = 4;
        }
        break;
    }
    case 4:
        if (unk_04 & 0x400) {
            ov0_02134F70();
        }
        sub_0203C2B8(this);
        if (--unk_164 < 0) {
            unk_164 = 0;
        }
        break;
    }
    unk_168.ov0_02152B04();
    sub_0203C87C(this, (int)map);
    ov0_0213524C();
}

BOOL CFieldEnemy::sub_0203D578(CFieldMap *map)
{
    BOOL result = CFieldActor::sub_0203D578(map);
    unk_168.ov0_02158988();
    ov0_0213524C();
    if (result) {
        sub_02034CF4(s_game->m_audioEngine, unk_E4, 0x40);
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
    unk_04 |= 1;
    SetUnk8C(0);
    unk_168.ov0_0215674C(0xE);
}

void CFieldEnemy::ov0_02134F38()
{
    unk_04 |= 1;
    SetUnk8C(0xDC000);
    unk_168.ov0_0215674C(0xF);
}

void CFieldEnemy::ov0_02134F70()
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (player == NULL) {
        return;
    }
    if (player->unk_14 != unk_14) {
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
    unk_04 |= 0x800;
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
    sub_02041C1C(target);
    target->unk_20 = 0;
    target->sub_0202D394();
    unk_04 &= ~0x800;
}

void CFieldEnemy::ov0_0213524C()
{
}

void CFieldEnemy::ov0_02135250()
{
    sub_02034CF4(s_game->m_audioEngine, unk_E4, 0x40);
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
    UnkClass_02142428 *manage = MAIN_BSS_0210CA60;
    if (manage == NULL) {
        return;
    }
    fx32 x = GetX();
    fx32 y = GetY();
    int cell = 0;
    if (unk_6C != NULL) {
        CFieldMapLayerAttribute *attr = unk_6C->GetAttributeLayer(unk_14);
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
        effect = ov0_02143088(manage, ov0_02142F6C(manage, 0xB, 0));
        if (effect == NULL) {
            return;
        }
        effect->sub_0203312C(0, 8);
        effect->sub_0203312C(8, 20);
        effect->sub_0203312C(1, x >> FX32_SHIFT);
        effect->sub_0203312C(2, y >> FX32_SHIFT);
        effect->sub_0203312C(3, 0);
        effect->sub_0203312C(4, 0);
        effect->ov0_021421F0(0, -1, 0);
        break;
    case 3:
    case 4:
    case 8:
        effect = ov0_02143088(manage, ov0_02142F6C(manage, 0xA, 0));
        if (effect == NULL) {
            return;
        }
        effect->sub_0203312C(0, 16);
        effect->sub_0203312C(1, x >> FX32_SHIFT);
        effect->sub_0203312C(2, (y >> FX32_SHIFT) + 8);
        effect->sub_0203312C(3, 16);
        effect->sub_0203312C(4, 0);
        effect->ov0_021421F0(0, -1, 0);
        break;
    case 2:
    case 5:
        effect = ov0_02143088(manage, ov0_02142F6C(manage, 0x26, 0));
        if (effect == NULL) {
            return;
        }
        effect->sub_0203312C(1, x >> FX32_SHIFT);
        effect->sub_0203312C(2, (y >> FX32_SHIFT) + 8);
        effect->ov0_021421F0(0, -1, 0);
        break;
    case 7:
    case 9:
    case 10:
        break;
    case 11:
        effect = ov0_02143088(manage, ov0_02142F6C(manage, 0xA, 0));
        if (effect == NULL) {
            return;
        }
        effect->sub_0203312C(0, 16);
        effect->sub_0203312C(1, x >> FX32_SHIFT);
        effect->sub_0203312C(2, (y >> FX32_SHIFT) + 8);
        effect->sub_0203312C(3, 16);
        effect->sub_0203312C(4, 0);
        effect->sub_0203312C(19, 1);
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
    UnkStruct_0203BF40 *obj = unk_08;
    UnkClass_0201287C *sprite;
    fx32 x = unk_18;
    if (obj != NULL && (sprite = obj->unk_0C) != NULL) {
        sprite->SetXY(x, y);
        if (obj->unk_0C->unk_0C4 != NULL) {
            obj->unk_0C->unk_0C4->SetXY(x, y);
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
