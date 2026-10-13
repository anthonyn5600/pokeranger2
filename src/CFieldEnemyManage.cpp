#include "field/CFieldEnemyManage.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkStruct_020107A8.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "file/CBinaryFile.hpp"
#include "sub_02044440.hpp"

struct UnkStruct_0210C228 {
    u8 unk_000[0x800];
    u8 unk_800;
    IFieldEnemyDataBuilder *unk_804;
};

extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldPartnerManage *MAIN_BSS_0210CA4C;
extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;
extern UnkStruct_0210C228 MAIN_BSS_0210C228;
extern MATHRandContext16 MAIN_BSS_0210CEC8;

extern "C" {
void LogError(const char *fmt, ...);
void LogInfo(const char *fmt, ...);
void sub_02044AC8(void *script);
FieldEnemyData *sub_02041D58(UnkClass_02041C80 *obj, int kind);
BOOL sub_02015434(UnkClass_020B26A0 *save, int mapId, int idx);
}

UnkStruct_021357DC::UnkStruct_021357DC()
{
    unk_00 = 0;
    unk_04 = NULL;
    unk_08 = NULL;
}

UnkStruct_021357DC::~UnkStruct_021357DC()
{
    SAFE_DELETE(unk_04);
}

void UnkStruct_021357DC::Load(const char *path)
{
    u32 heapId = s_game->unk_14A8;
    unk_04 = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    unk_08 = unk_04->unk_4C;
    sub_02044AC8(unk_08);
}

UnkClass_0213588C::UnkClass_0213588C()
{
    sub_02044440();
    for (int i = 0; i < 64; i++) {
        m_scripts[i] = NULL;
    }
}

UnkClass_0213588C::~UnkClass_0213588C()
{
    for (int i = 0; i < 64; i++) {
        SAFE_DELETE(m_scripts[i]);
    }
}

void *UnkClass_0213588C::Get(u32 id)
{
    char path[0x100];
    if (id >= 64) {
        LogError("*****ScriptID MAX Over*****");
        return NULL;
    }
    for (int i = 0; i < 64; i++) {
        if (m_scripts[i] != NULL) {
            if (id == m_scripts[i]->unk_00) {
                return m_scripts[i]->unk_08;
            }
        } else {
            m_scripts[i] = new UnkStruct_021357DC();
            OS_SPrintf(path, "data/Script/field/actor/FieldEnemyScript%d.fsb", id);
            m_scripts[i]->Load(path);
            m_scripts[i]->unk_00 = id;
            return m_scripts[i]->unk_08;
        }
    }
    LogError("***************");
    LogError("EnemyScriptBlockError  unScriptID= %d", id);
    LogError("*************:*");
    return NULL;
}

void UnkClass_0213588C::Clear()
{
    for (int i = 0; i < 64; i++) {
        SAFE_DELETE(m_scripts[i]);
    }
}

// Picks the enemy's script (0: its default; 101/102: the default plus a special start) and starts it.
// A static helper, not an inline member: an inline member's string literals become mergeable function-local
// statics, emitted ahead of the TU's other strings.
static inline BOOL SetEnemyScript(CFieldEnemyManage *manage, CFieldEnemy *enemy, FieldEnemyData *data, u16 script)
{
    if (script == 0) {
        script = data->unk_00;
    } else if (script == 101) {
        script = data->unk_00;
        enemy->ov0_02134F00();
    } else if (script == 102) {
        script = data->unk_00;
        enemy->ov0_02134F38();
    } else {
        manage->unk_14->Get(data->unk_00);
    }
    void *block = manage->unk_14->Get(script);
    enemy->unk_146 = script;
    if (script == 52 || script == 54) {
        enemy->unk_250 = 0;
    }
    if (!enemy->sub_0203C1B4(block)) {
        LogError("SetScript  ERROR by FieldEnemyManage.cpp");
        return FALSE;
    }
    enemy->sub_0203C22C("main");
    enemy->unk_0C = TRUE;
    return TRUE;
}

void CFieldEnemyManage::sub_0203EFE4(int capacity)
{
    CFieldActorManage::sub_0203EFE4(capacity);
    unk_14 = new UnkClass_0213588C();
    MAIN_BSS_0210C228.unk_804 = this;
}

void CFieldEnemyManage::sub_0203F034()
{
    CFieldActorManage::sub_0203F034();
    MAIN_BSS_0210C228.unk_804 = NULL;
    SAFE_DELETE(unk_14);
}

static inline BOOL IsUnk146InRange(CFieldEnemy *enemy)
{
    if (enemy->unk_146 >= 55 && enemy->unk_146 <= 62) {
        return TRUE;
    }
    return FALSE;
}

// unk_58 = map id << 12 | index; shifted as a signed value (asr).
static inline void SetEnemyStateById(CFieldActor *actor, u8 state)
{
    MAIN_BSS_020B26A0.SetEnemyState(((int)actor->unk_58 >> 12) & 0xFFF, actor->unk_58 & 0xFFF, state);
}

void CFieldEnemyManage::sub_0203F2B0(CFieldMap *map, BOOL update)
{
    if (m_actors != NULL) {
        Point2D playerPos = MAIN_BSS_0210CA48->GetPos();
        playerPos.y -= MAIN_BSS_0210CA48->GetHeight();
        for (int i = 0; i < m_count; i++) {
            CFieldEnemy *enemy = (CFieldEnemy *)m_actors[i];
            if (enemy == NULL || enemy->unk_58 == 0x01130002 || enemy->unk_20 != 1) {
                continue;
            }
            if (IsUnk146InRange(enemy)) {
                continue;
            }
            if (sub_02015434(&MAIN_BSS_020B26A0, ((int)enemy->unk_58 >> 12) & 0xFFF, enemy->unk_58 & 0xFFF)) {
                continue;
            }
            if (MAIN_BSS_0210CA4C->FindTarget(enemy->unk_58) != NULL) {
                continue;
            }
            if (MATH_IAbs(enemy->GetX() - playerPos.x) <= 0x100000 && MATH_IAbs(enemy->GetY() - playerPos.y) <= 0x100000) {
                continue;
            }
            if (enemy->unk_244) {
                sub_02041C1C(enemy);
                enemy->unk_20 = 0;
                enemy->sub_0202D394();
                SetEnemyStateById(enemy, 1);
            } else {
                ov0_021369DC(enemy);
                SetEnemyStateById(enemy, 3);
            }
        }
    }
    CFieldActorManage::sub_0203F2B0(map, update);
}

static inline void SetUnk70(CFieldActor *actor, fx32 x, fx32 y)
{
    actor->unk_70 = x;
    actor->unk_74 = y;
}

int CFieldEnemyManage::ov0_02135E30(int slot, u16 kind, u16 script, int arg4)
{
    if (m_actors != NULL) {
        UnkClass_02041C80 *table = MAIN_BSS_0210CA6C;
        // Spilled under register pressure and rematerialized at its use (the NPC/object managers keep it in a
        // register); reading MAIN_BSS_020B26A0 directly schedules the id computation differently.
        UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
        for (int i = 0; i < m_count; i++) {
            if (Get(i) != NULL || unk_14 == NULL) {
                continue;
            }
            FieldEnemyData *data = sub_02041D58(table, kind);
            UnkStruct_020107A8 *info = sub_020107A8(s_game->unk_1434, kind);
            CFieldEnemy *enemy = new CFieldEnemy();
            u32 id = slot & 0xFFF;
            id |= ((save->unk_001A & 0xFFF) << 12) | 0x1000000;
            enemy->sub_0203DA60(id);
            enemy->unk_E8 = kind;
            u32 flags = 6;
            flags |= ov0_02136320(data->unk_38);
            flags |= ov0_02136320(data->unk_39);
            flags |= ov0_02136320(data->unk_3A);
            enemy->sub_0203C418(0, info->unk_00, info->unk_02, flags, arg4);
            enemy->unk_168.unk_B0 = enemy->unk_E4 = info->unk_00;
            enemy->SetUnkBC(info->unk_0A, info->unk_0B);
            enemy->SetUnkBE(info->unk_0C, info->unk_0D);
            Rectangle bounds = { { info->unk_07 << FX32_SHIFT, info->unk_08 << FX32_SHIFT },
                { info->unk_09 << FX32_SHIFT, info->unk_09 << FX32_SHIFT } };
            enemy->unk_24.pos.x = bounds.pos.x;
            enemy->unk_24.pos.y = bounds.pos.y;
            enemy->unk_24.size.x = bounds.size.x;
            enemy->unk_24.size.y = bounds.size.y;
            enemy->unk_D4 = info->unk_0E;
            enemy->unk_D6 = info->unk_0F;
            SetUnk70(enemy, data->unk_3D << FX32_SHIFT, data->unk_3E << FX32_SHIFT);
            enemy->unk_168.unk_6C = *data;
            enemy->unk_168.unk_68 = enemy->unk_168.unk_6C.unk_30;
            enemy->unk_168.unk_64 = enemy->unk_168.unk_6C.unk_1C;
            enemy->unk_168.unk_6C.unk_16 += MATH_Rand16(&MAIN_BSS_0210CEC8, 0xB6);
            enemy->unk_168.unk_48 = enemy;
            enemy->unk_F0 = data->unk_02;
            enemy->unk_F4 = data->unk_04;
            enemy->unk_F8 = data->unk_06;
            enemy->unk_FC = data->unk_08;
            enemy->unk_100 = data->unk_0A;
            enemy->unk_104 = data->unk_0C;
            enemy->unk_108 = data->unk_10;
            enemy->unk_10C = data->unk_0C;
            enemy->unk_110 = data->unk_10;
            enemy->unk_114 = data->unk_14;
            enemy->unk_118 = data->unk_16;
            enemy->unk_11C = data->unk_18;
            enemy->unk_120 = data->unk_1A;
            enemy->unk_124 = data->unk_1C;
            enemy->unk_128 = data->unk_20;
            enemy->unk_138 = data->unk_37;
            enemy->unk_132[0] = data->unk_38;
            enemy->unk_132[1] = data->unk_39;
            enemy->unk_132[2] = data->unk_3A;
            enemy->unk_140 = data->unk_25;
            enemy->unk_141 = data->unk_24;
            enemy->unk_142 = data->unk_26;
            enemy->unk_12C = data->unk_28;
            enemy->unk_12E = data->unk_2A;
            enemy->unk_130 = data->unk_27;
            enemy->unk_144 = data->unk_00;
            enemy->unk_254 = script;
            SetEnemyScript(this, enemy, data, script);
            if (data->unk_2C != 0) {
                enemy->unk_A0 = data->unk_2C << FX32_SHIFT;
            }
            enemy->unk_9C = data->unk_2E;
            m_actors[i] = enemy;
            return i;
        }
    }
    return -1;
}

u32 CFieldEnemyManage::ov0_02136320(int type)
{
    if (type == 0) {
        return 0;
    }
    if (type == 1) {
        return 0x200;
    }
    if (type == 2) {
        return 0x400;
    }
    if (type == 3) {
        return 0x800;
    }
    if (type == 4) {
        return 0x1000;
    }
    if (type == 5) {
        return 0x40;
    }
    if (type == 6) {
        return 0x80;
    }
    if (type == 7) {
        return 8;
    }
    return 0;
}

void CFieldEnemyManage::ov0_02136384()
{
    CFieldTargetObjectManage *targets = MAIN_BSS_0210CA7C;
    if (targets == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldEnemy *enemy = (CFieldEnemy *)Get(i);
        if (enemy == NULL) {
            continue;
        }
        u16 kind = enemy->unk_138;
        if (kind == 0 || enemy->unk_13C != -1) {
            continue;
        }
        int count = targets->CountActors();
        int index = targets->ov0_0213D1AC(count, kind, 0, 0, 0);
        if (index < 0) {
            continue;
        }
        CFieldActor *target = targets->Get(index);
        if (target == NULL) {
            continue;
        }
        target->SetPos(enemy->GetPos());
        target->SetHomePos(enemy->GetPos());
        enemy->unk_13C = target->unk_58;
        if (enemy->IsActive()) {
            switch (enemy->unk_146) {
            case 0:
            case 1:
            case 2:
            case 3:
                break;
            case 4:
                enemy->ov0_021351AC();
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                enemy->ov0_02134FCC();
                enemy->unk_04 &= ~0x400;
                enemy->unk_04 |= 0x200;
                enemy->unk_168.unk_D0 = 7;
                enemy->sub_02032A44(0x11);
                enemy->unk_04 |= 1;
                break;
            }
            LogInfo("addtarget= %d", target->unk_58);
            LogInfo("targetid= %d", index);
            LogInfo("objnum= %d", count);
        } else {
            enemy->ov0_021351AC();
        }
    }
}

void CFieldEnemyManage::ov0_0213669C(u32 id, u16 script)
{
    CFieldEnemy *enemy = (CFieldEnemy *)Find(id);
    void *block = unk_14->Get(script);
    enemy->unk_146 = script;
    if (enemy != NULL && block != NULL) {
        enemy->sub_0203C1B4(block);
        enemy->sub_0203C22C("main");
    }
}

void CFieldEnemyManage::ov0_02136730(u32 id)
{
    CFieldEnemy *enemy = (CFieldEnemy *)Find(id);
    void *block = NULL;
    if (enemy != NULL) {
        block = unk_14->Get(enemy->unk_144);
        enemy->unk_146 = enemy->unk_144;
    }
    if (enemy != NULL && block != NULL) {
        enemy->sub_0203C1B4(block);
        enemy->sub_0203C22C("main");
    }
}

void CFieldEnemyManage::BuildData(void *buf, int size)
{
    LogInfo("*********************************");
    LogInfo("CFieldEnemyManage::BuildData() ");
    LogInfo("*********************************");
    if (m_count > 32) {
        LogError("******************************");
        LogError("ENEMY_SAVE_MAX < EnemyActorNum");
        LogError("******************************");
        return;
    }
    u8 *p = (u8 *)buf;
    u8 *end = p + size;
    for (int i = 0; i < m_count; i++) {
        CFieldEnemy *enemy = (CFieldEnemy *)m_actors[i];
        if (enemy != NULL) {
            enemy->ov0_021356BC(p, end);
        }
        p += 0x40;
    }
}

void CFieldEnemyManage::ov0_02136878()
{
    u8 data[0x40];
    if (!MAIN_BSS_0210C228.unk_800) {
        return;
    }
    u8 *p = MAIN_BSS_0210C228.unk_000;
    u8 *end = &MAIN_BSS_0210C228.unk_800;
    for (int i = 0; p < end && i < m_count; i++) {
        MI_CpuCopy8(p, data, sizeof(data));
        CFieldEnemy *enemy = (CFieldEnemy *)m_actors[i];
        if (enemy != NULL) {
            enemy->ov0_021356CC(data);
        }
        p += 0x40;
    }
    MAIN_BSS_0210C228.unk_800 = 0;
}

void CFieldEnemyManage::ov0_0213690C(int arg1, int arg2)
{
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = Get(i);
        if (actor != NULL) {
            sub_02041A70(actor, arg1, arg2);
        }
    }
}

void CFieldEnemyManage::ov0_02136968()
{
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = Get(i);
        if (actor != NULL) {
            sub_02041C1C(actor);
        }
    }
}

BOOL CFieldEnemyManage::sub_0203F190()
{
    BOOL result = CFieldActorManage::sub_0203F190();
    if (unk_14 != NULL) {
        unk_14->Clear();
    }
    return result;
}

void CFieldEnemyManage::ov0_021369DC(CFieldEnemy *enemy)
{
    if (enemy == NULL) {
        return;
    }
    enemy->unk_20 = 2;
    enemy->ov0_021356EC();
    FieldEnemyData *data = sub_02041D58(MAIN_BSS_0210CA6C, enemy->unk_E8);
    SetEnemyScript(this, enemy, data, enemy->unk_254);
}
