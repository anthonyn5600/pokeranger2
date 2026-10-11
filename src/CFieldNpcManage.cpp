#include "field/CFieldNpcManage.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkStruct_020107A8.hpp"
#include "field/CFieldNpc.hpp"

struct FieldNpcData {
    u16 unk_00;
    s8 unk_02;
    s8 unk_03;
};

extern UnkClass_02041D80 *MAIN_BSS_0210CA6C;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;
extern MATHRandContext16 MAIN_BSS_0210CEC8;

extern "C" {
FieldNpcData *sub_02041D44(UnkClass_02041D80 *obj, int kind);
FieldEnemyData *sub_02041D58(UnkClass_02041D80 *obj, int kind);
}

void CFieldNpcManage::sub_0203EFE4(int capacity)
{
    CFieldActorManage::sub_0203EFE4(capacity);
}

void CFieldNpcManage::sub_0203F034()
{
    CFieldActorManage::sub_0203F034();
}

static inline void SetUnk70(CFieldActor *actor, fx32 x, fx32 y)
{
    actor->unk_70 = x;
    actor->unk_74 = y;
}

// Collision shape: unk_50 = 0 uses the rectangle at unk_34, 1 the circle at unk_44.
static inline void SetCircle(CFieldActor *actor, Circle v)
{
    actor->unk_44 = v;
}

int CFieldNpcManage::ov0_0213C66C(int slot, int type, u16 kind, u16 script, int arg5)
{
    if (m_actors != NULL) {
        UnkClass_02041D80 *table = MAIN_BSS_0210CA6C;
        UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
        for (int i = 0; i < m_count; i++) {
            if (Get(i) != NULL) {
                continue;
            }
            CFieldNpc *npc = new CFieldNpc();
            u32 id = slot & 0xFFF;
            id |= ((save->unk_001A & 0xFFF) << 12) | 0x2000000;
            npc->sub_0203DA60(id);
            // u8: its spill store gets the catch-all alias, which orders the loads around it like the original.
            u8 arg3 = 0;
            fx32 radius = 0x8000;
            u32 flags;
            u16 model;
            if (type == 0) {
                flags = 0x1E16;
                FieldNpcData *data = sub_02041D44(table, kind);
                model = data->unk_00;
                npc->unk_78 = 0;
                SetUnk70(npc, data->unk_02 << FX32_SHIFT, data->unk_03 << FX32_SHIFT);
            } else {
                flags = 6;
                UnkStruct_020107A8 *info = sub_020107A8(s_game->unk_1434, kind);
                model = info->unk_00;
                arg3 = info->unk_02;
                FieldEnemyData *data = sub_02041D58(MAIN_BSS_0210CA6C, kind);
                radius = data->unk_1C;
                npc->unk_F4.unk_6C = *data;
                npc->unk_F4.unk_68 = npc->unk_F4.unk_6C.unk_30;
                npc->unk_F4.unk_64 = npc->unk_F4.unk_6C.unk_1C;
                npc->unk_F4.unk_6C.unk_16 += MATH_Rand16(&MAIN_BSS_0210CEC8, 0xB6);
                Rectangle bounds = { { info->unk_07 << FX32_SHIFT, info->unk_08 << FX32_SHIFT },
                    { info->unk_09 << FX32_SHIFT, info->unk_09 << FX32_SHIFT } };
                npc->unk_24.pos.x = bounds.pos.x;
                npc->unk_24.pos.y = bounds.pos.y;
                npc->unk_24.size.x = bounds.size.x;
                npc->unk_24.size.y = bounds.size.y;
                npc->unk_D4 = info->unk_0E;
                npc->unk_D6 = info->unk_0F;
                SetUnk70(npc, data->unk_3D << FX32_SHIFT, data->unk_3E << FX32_SHIFT);
                npc->SetUnkBE(info->unk_0C, info->unk_0D);
                npc->SetUnkBC(info->unk_0A, info->unk_0B);
            }
            if (type == 0) {
                npc->sub_0203C418(1, model, arg3, flags, arg5);
            } else {
                npc->sub_0203C418(0, model, arg3, flags, arg5);
            }
            npc->LoadScript(script);
            npc->unk_E8 = type;
            npc->unk_EC = kind;
            npc->unk_F0 = model;
            npc->unk_50 = 1;
            // Field by field: an initializer zero-fills the temp first.
            Circle v;
            v.pos.x = 0;
            v.pos.y = 0;
            v.r = radius;
            SetCircle(npc, v);
            m_actors[i] = npc;
            return i;
        }
    }
    return -1;
}
