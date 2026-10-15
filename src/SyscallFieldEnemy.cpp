#include "FieldSyscallSets.hpp"
#include "ScriptVM.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldEnemyManage.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern CFieldEnemyManage *MAIN_BSS_0210CA5C;

extern "C" {
void LogError(const char *fmt, ...);
void LogInfo(const char *fmt, ...);
int ov0_021485E0(int *args);
int Sys_EnemyCommand(int *args);
int Sys_GetEnemyManage(int *args);
int Sys_EnemyManageCommand(int *args);
}

static ScriptSyscall sFieldEnemySyscalls[] = {
    (ScriptSyscall)ov0_021485E0,
    (ScriptSyscall)Sys_EnemyCommand,
    (ScriptSyscall)Sys_GetEnemyManage,
    (ScriptSyscall)Sys_EnemyManageCommand,
};

FieldEnemySyscalls::FieldEnemySyscalls()
{
}

FieldEnemySyscalls::~FieldEnemySyscalls()
{
}

void FieldEnemySyscalls::Register()
{
    Script_RegisterSyscalls(0xA, sFieldEnemySyscalls);
}

static void ov0_02148CDC(VecFx32 *out, CFieldEnemy *enemy);

static inline void SetDir(CFieldEnemy *enemy, fx32 x, fx32 y)
{
    Point2D dir = { x, y };
    enemy->unk_158 = dir;
    enemy->unk_168.unk_30 = enemy->GetUnk158();
}

static inline CFieldEnemy *FindByUnk13C(CFieldEnemyManage *manage, int id)
{
    for (int i = 0; i < manage->m_count; i++) {
        CFieldEnemy *enemy = (CFieldEnemy *)manage->m_actors[i];
        if (enemy != NULL && id == enemy->unk_13C) {
            return enemy;
        }
    }
    return NULL;
}

static inline void SetXY(VecFx32 *v, fx32 x, fx32 y)
{
    v->x = x;
    v->y = y;
}

extern "C" {

int ov0_021485E0(int *args)
{
    return 0;
}

int Sys_EnemyCommand(int *args)
{
    int cmd = args[0];
    CFieldEnemy *enemy = (CFieldEnemy *)args[1];
    if (enemy == NULL) {
        return -1;
    }
    switch (cmd) {
    case 1:
        enemy->unk_F0 = args[2];
        return 0;
    case 2:
        return enemy->unk_F0;
    case 3:
        enemy->unk_F4 = args[2];
        return 0;
    case 4:
        return enemy->unk_F4;
    case 5:
        enemy->unk_F8 = args[2];
        return 0;
    case 6:
        return enemy->unk_F8;
    case 7:
        enemy->unk_FC = args[2];
        return 0;
    case 8:
        return enemy->unk_FC;
    case 9:
        enemy->unk_100 = args[2];
        return 0;
    case 10:
        return enemy->unk_100;
    case 11:
        enemy->unk_104 = args[2];
        return 0;
    case 12:
        return enemy->unk_104;
    case 13:
        enemy->unk_108 = args[2];
        return 0;
    case 14:
        return enemy->unk_108;
    case 15:
        enemy->unk_10C = args[2];
        return 0;
    case 16:
        return enemy->unk_10C;
    case 17:
        enemy->unk_110 = args[2];
        return 0;
    case 18:
        return enemy->unk_110;
    case 19:
        enemy->unk_114 = args[2];
        return 0;
    case 20:
        return enemy->unk_114;
    case 21:
        enemy->unk_118 = args[2];
        return 0;
    case 22:
        return enemy->unk_118;
    case 23:
        enemy->unk_11C = args[2];
        return 0;
    case 24:
        return enemy->unk_11C;
    case 25:
        enemy->unk_120 = args[2];
        return 0;
    case 26:
        return enemy->unk_120;
    case 27:
        enemy->unk_124 = args[2];
        return 0;
    case 28:
        return enemy->unk_124;
    case 29:
        enemy->unk_128 = args[2];
        return 0;
    case 30:
        return enemy->unk_128;
    case 31:
        return enemy->unk_12C;
    case 32:
        return enemy->unk_12E;
    case 33:
        return enemy->unk_130;
    case 34:
        return enemy->m_flags & 0x400;
    case 35:
        enemy->m_flags |= 0x400;
        return 0;
    case 36:
        enemy->m_flags &= ~0x400;
        return 0;
    case 37:
        return enemy->PlayEnemyAnime(args[2]);
    case 38:
        if (MAIN_BSS_0210CA40 != NULL) {
            MAIN_BSS_0210CA40->StartEnemyBattle(enemy);
        }
        return 0;
    case 39:
        return enemy->unk_138;
    case 40:
        return enemy->unk_13C;
    case 41:
        enemy->EnableTargetObject();
        return 0;
    case 42:
        enemy->DisableTargetObject();
        return 0;
    case 43:
        return enemy->unk_141;
    case 44:
        return enemy->unk_140;
    case 45:
        return enemy->unk_142;
    case 46:
        return enemy->unk_148;
    case 47:
        VEC_Set(&enemy->unk_14C, args[2], args[3], args[4]);
        return 0;
    case 48:
        SetXY(&enemy->unk_14C, args[2], args[3]);
        return 0;
    case 49: {
        VecFx32 v;
        ov0_02148CDC(&v, enemy);
        return v.x;
    }
    case 50: {
        VecFx32 v;
        ov0_02148CDC(&v, enemy);
        return v.y;
    }
    case 51: {
        VecFx32 v;
        ov0_02148CDC(&v, enemy);
        return v.z;
    }
    case 52: {
        SetDir(enemy, args[2], args[3]);
        return 0;
    }
    case 53:
        return enemy->GetUnk158().x;
    case 54:
        return enemy->GetUnk158().y;
    case 55:
        return enemy->unk_E8;
    case 56:
        enemy->PlayCry();
        return 0;
    case 57:
        return enemy->unk_E4;
    case 58:
        enemy->unk_160 = args[2];
        return 0;
    case 59:
        return enemy->unk_160;
    case 60:
        enemy->unk_20 = 3;
        return 0;
    case 61:
        enemy->unk_20 = 2;
        return 0;
    case 62:
        return enemy->unk_20 == 3;
    case 63:
        enemy->unk_164 = args[2];
        return 0;
    case 64:
        return enemy->unk_164;
    case 65:
        return PTR_CAST(int, enemy->GetTargetObject());
    case 66: {
        enemy->unk_168.SetTarget(enemy, (Point2D) { args[2], args[3] }, args[4]);
        return 0;
    }
    case 67:
        return enemy->unk_168.unk_44;
    case 68:
        enemy->SetMoveSequence(args[2]);
        return 0;
    case 69:
        return enemy->unk_168.unk_C0;
    case 70:
        enemy->unk_168.unk_D0 = args[2];
        return 0;
    case 71:
        return enemy->unk_168.unk_D0;
    case 72:
        enemy->unk_168.unk_68 = args[2];
        return 0;
    case 73:
        enemy->unk_168.unk_D6 = args[2];
        return 0;
    case 74:
        enemy->unk_168.unk_50 = args[2];
        return 0;
    case 75:
        return enemy->unk_168.unk_50;
    case 76:
        enemy->unk_250 = args[2] != 0 ? TRUE : FALSE;
        return 0;
    }
    return 0;
}
}

static void ov0_02148CDC(VecFx32 *out, CFieldEnemy *enemy)
{
    out->x = enemy->unk_14C.x;
    out->y = enemy->unk_14C.y;
    out->z = enemy->unk_14C.z;
}

extern "C" {

int Sys_GetEnemyManage(int *args)
{
    return PTR_CAST(int, MAIN_BSS_0210CA5C);
}

int Sys_EnemyManageCommand(int *args)
{
    int cmd = args[0];
    CFieldEnemyManage *manage = (CFieldEnemyManage *)args[1];
    if (manage == NULL) {
        LogError("ERROR :syscallFieldEnemy.cpp FieldEnemyManage == NULL");
        return -1;
    }
    switch (cmd) {
    case 0: {
        int slot;
        int base = manage->CountActors();
        fx32 x = args[3];
        fx32 y = args[4];
        slot = manage->Create(base, args[2], 0, 0);
        CFieldEnemy *enemy = (CFieldEnemy *)manage->Get(slot);
        if (enemy != NULL) {
            enemy->SetPosXY(x, y);
            enemy->unk_18 = x;
            enemy->unk_1C = y;
            manage->AddTargets();
        } else {
            LogInfo("scriptAddEnemyError");
        }
        return slot;
    }
    case 1: {
        CFieldActor *actor = manage->Get(args[2]);
        if (actor == NULL) {
            return -1;
        }
        return PTR_CAST(int, actor);
    }
    case 2:
        return manage->CountActors();
    case 3:
        manage->ChangeScript(args[2], args[3]);
        return 0;
    case 4:
        manage->RestoreScript(args[2]);
        return 0;
    case 5: {
        CFieldEnemy *enemy = FindByUnk13C(manage, args[2]);
        if (enemy == NULL) {
            return -1;
        }
        return PTR_CAST(int, enemy);
    }
    case 6: {
        CFieldActor *actor = manage->Find(args[2]);
        if (actor == NULL) {
            return -1;
        }
        return PTR_CAST(int, actor);
    }
    case 7: {
        CFieldActor *actor = manage->Find(args[2]);
        if (actor != NULL) {
            fx32 y = args[4];
            // Reusing cmd makes this x a split live range, which gets the original's
            // register.
            cmd = args[3];
            actor->SetPosXY(cmd, y);
        }
        return 0;
    }
    case 8: {
        int slot;
        int base = manage->CountActors();
        fx32 x = args[3];
        fx32 y = args[4];
        slot = manage->Create(base, args[2], args[5], 0);
        CFieldEnemy *enemy = (CFieldEnemy *)manage->Get(slot);
        if (enemy != NULL) {
            enemy->SetPosXY(x, y);
            enemy->unk_18 = x;
            enemy->unk_1C = y;
            manage->AddTargets();
        } else {
            LogInfo("scriptAddEnemyAndSetScriptIDError");
        }
        return slot;
    }
    }
    return -1;
}
}
