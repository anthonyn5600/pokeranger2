#include "AudioEngine.hpp"
#include "BattleStartParam.hpp"
#include "CBattleResultParameter.hpp"
#include "CGame.hpp"
#include "FieldCannons.hpp"
#include "FieldDataRecords.hpp"
#include "FieldEventRectManage.hpp"
#include "FieldScriptLauncher.hpp"
#include "FieldSyscallSets.hpp"
#include "SaveData.hpp"
#include "ScriptVM.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEnemyManage.hpp"
#include "field/CFieldEventRect.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPlayer.hpp"
#include "field/CFieldTargetObject.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "interpolation.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern FieldScriptLauncher *MAIN_BSS_0210CA44;
extern FieldEventRectManage *MAIN_BSS_0210CA58;
extern CFieldPlayer *MAIN_BSS_0210CA48;
extern CFieldPartnerManage *MAIN_BSS_0210CA4C;
extern CFieldEnemyManage *MAIN_BSS_0210CA5C;
extern CFieldEffectManage *MAIN_BSS_0210CA60;
extern FieldData *MAIN_BSS_0210CA6C;
extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;
extern SaveData MAIN_BSS_020B26A0;

static inline AudioEngine *Audio()
{
    return s_game->m_audioEngine;
}

extern "C" {
void SaveData_EnableEventRect(SaveData *save, int idx, int mapId);
void SaveData_DisableEventRect(SaveData *save, int idx, int mapId);
u32 SaveData_AddPokemonRides(SaveData *save, u32 value);
PartyEntry *SaveData_FindEntry(SaveData *save, u32 id);
PartyEntry *SaveData_GetEntry(SaveData *save, int idx);
int ov0_02149E78(int *args, int argc);
int Sys_LaunchScript(int *args, int argc);
int Sys_StartBattleWithEnemy(int *args, int argc);
int Sys_DisableEventRectAt(int *args, int argc);
int Sys_EnableEventRectAt(int *args, int argc);
int ov0_0214A034(int *args, int argc);
int ov0_0214A058(int *args, int argc);
int Sys_IsPlayerControlUnlocked(int *args, int argc);
int Sys_SetFieldWaza(int *args, int argc);
int Sys_ClearFieldWaza(int *args, int argc);
int Sys_RidePokemon(int *args, int argc);
int Sys_GetOffPokemon(int *args, int argc);
int Sys_GetSelectedPartyId(int *args, int argc);
int ov0_0214A588(int *args, int argc);
int Sys_GetPartyEntryId(int *args, int argc);
int ov0_0214A62C(int *args, int argc);
int ov0_0214A6D4(int *args, int argc);
int ov0_0214A6FC(int *args, int argc);
int Sys_CreateCannon(int *args, int argc);
int Sys_ActivateCannon(int *args, int argc);
int Sys_SetCannonPos(int *args, int argc);
int Sys_SetCannonParams(int *args, int argc);
int Sys_GetEnemyId(int *args, int argc);
int Sys_IsPlayerAtTargetObject(int *args, int argc);
int Sys_HideEnemies(int *args, int argc);
int Sys_ShowEnemies(int *args, int argc);
int Sys_IsPlayerAtTargetObjectEx(int *args, int argc);
int ov0_0214ABC8(int *args, int argc);
int ov0_0214ABE4(int *args, int argc);
int ov0_0214AC00(int *args, int argc);
int ov0_0214AC1C(int *args, int argc);
int Sys_QuadraticInterpolate(int *args, int argc);
int Sys_IsPlayerAboveEventRect(int *args, int argc);
int Sys_IsPlayerBelowEventRect(int *args, int argc);
int Sys_IsPlayerLeftOfEventRect(int *args, int argc);
int Sys_IsPlayerRightOfEventRect(int *args, int argc);
int Sys_KnockBackPlayer(int *args, int argc);
int Sys_IsFlagValid(int *args, int argc);
int Sys_SetFlagCount(int *args, int argc);
int Sys_SetFlagSub(int *args, int argc);
int Sys_GetFlagCount(int *args, int argc);
int Sys_GetFlagSub(int *args, int argc);
int Sys_IsActorFloating(int *args, int argc);
int ov0_0214B180(int *args, int argc);
int Sys_IsPlayerNearTargetObject(int *args, int argc);
int ov0_0214B320(int *args, int argc);
int Sys_SetFlagCountValue(int *args, int argc);
int Sys_SetFlagPos(int *args, int argc);
int Sys_GetFlagX(int *args, int argc);
int Sys_GetFlagY(int *args, int argc);
int Sys_GetFlagValue(int *args, int argc);
int Sys_SetFlagKind(int *args, int argc);
int Sys_GetFlagKind(int *args, int argc);
int Sys_SetFlagValue(int *args, int argc);
int Sys_IsFieldBusy(int *args, int argc);
int Sys_SetButton1Enabled(int *args, int argc);
int Sys_SetButton2Enabled(int *args, int argc);
int Sys_IsButton1Enabled(int *args, int argc);
int Sys_IsButton2Enabled(int *args, int argc);
int ov0_0214B68C(int *args, int argc);
int ov0_0214B6CC(int *args, int argc);
}

static inline void SetFlagPos(int i, Point2D pos)
{
    int j = (i & 0x3FF) * 2;
    s16 *table = MAIN_BSS_020B26A0.unk_82F4;
    table[j] = pos.x >> FX32_SHIFT;
    table[j + 1] = pos.y >> FX32_SHIFT;
}

static inline Point2D GetFlagPos(int i)
{
    int j = (i & 0x3FF) * 2;
    s16 *table = MAIN_BSS_020B26A0.unk_82F4;
    Point2D pos = { table[j] << FX32_SHIFT, table[j + 1] << FX32_SHIFT };
    return pos;
}

static ScriptSyscall sFieldSyscalls[] = {
    (ScriptSyscall)ov0_02149E78,
    (ScriptSyscall)Sys_LaunchScript,
    (ScriptSyscall)Sys_StartBattleWithEnemy,
    (ScriptSyscall)Sys_DisableEventRectAt,
    (ScriptSyscall)Sys_EnableEventRectAt,
    (ScriptSyscall)ov0_0214A034,
    (ScriptSyscall)ov0_0214A058,
    (ScriptSyscall)Sys_IsPlayerControlUnlocked,
    (ScriptSyscall)Sys_SetFieldWaza,
    (ScriptSyscall)Sys_ClearFieldWaza,
    (ScriptSyscall)Sys_RidePokemon,
    (ScriptSyscall)Sys_GetOffPokemon,
    (ScriptSyscall)Sys_SetFieldWaza,
    (ScriptSyscall)Sys_GetSelectedPartyId,
    (ScriptSyscall)ov0_0214A588,
    (ScriptSyscall)Sys_GetPartyEntryId,
    (ScriptSyscall)ov0_0214A62C,
    (ScriptSyscall)ov0_0214A6D4,
    (ScriptSyscall)ov0_0214A6FC,
    (ScriptSyscall)Sys_CreateCannon,
    (ScriptSyscall)Sys_ActivateCannon,
    (ScriptSyscall)Sys_SetCannonPos,
    (ScriptSyscall)Sys_SetCannonParams,
    (ScriptSyscall)Sys_GetEnemyId,
    (ScriptSyscall)Sys_IsPlayerAtTargetObject,
    (ScriptSyscall)Sys_HideEnemies,
    (ScriptSyscall)Sys_ShowEnemies,
    (ScriptSyscall)Sys_IsPlayerAtTargetObjectEx,
    (ScriptSyscall)ov0_0214ABC8,
    (ScriptSyscall)ov0_0214ABE4,
    (ScriptSyscall)ov0_0214AC00,
    (ScriptSyscall)ov0_0214AC1C,
    (ScriptSyscall)Sys_QuadraticInterpolate,
    (ScriptSyscall)Sys_IsPlayerAboveEventRect,
    (ScriptSyscall)Sys_IsPlayerBelowEventRect,
    (ScriptSyscall)Sys_IsPlayerLeftOfEventRect,
    (ScriptSyscall)Sys_IsPlayerRightOfEventRect,
    (ScriptSyscall)Sys_KnockBackPlayer,
    (ScriptSyscall)Sys_IsFlagValid,
    (ScriptSyscall)Sys_SetFlagCount,
    (ScriptSyscall)Sys_SetFlagSub,
    (ScriptSyscall)Sys_GetFlagCount,
    (ScriptSyscall)Sys_GetFlagSub,
    (ScriptSyscall)Sys_IsActorFloating,
    (ScriptSyscall)ov0_0214B180,
    (ScriptSyscall)Sys_IsPlayerNearTargetObject,
    (ScriptSyscall)ov0_0214B320,
    (ScriptSyscall)Sys_SetFlagCountValue,
    (ScriptSyscall)Sys_SetFlagPos,
    (ScriptSyscall)Sys_GetFlagX,
    (ScriptSyscall)Sys_GetFlagY,
    (ScriptSyscall)Sys_GetFlagValue,
    (ScriptSyscall)Sys_SetFlagKind,
    (ScriptSyscall)Sys_GetFlagKind,
    (ScriptSyscall)Sys_SetFlagValue,
    (ScriptSyscall)Sys_IsFieldBusy,
    (ScriptSyscall)Sys_SetButton1Enabled,
    (ScriptSyscall)Sys_SetButton2Enabled,
    (ScriptSyscall)Sys_IsButton1Enabled,
    (ScriptSyscall)Sys_IsButton2Enabled,
    (ScriptSyscall)ov0_0214B68C,
    (ScriptSyscall)ov0_0214B6CC,
};

FieldSyscalls::FieldSyscalls()
{
}

FieldSyscalls::~FieldSyscalls()
{
}

void FieldSyscalls::Register()
{
    Script_RegisterSyscalls(0xE, sFieldSyscalls);
}

extern "C" {

int ov0_02149E78(int *args, int argc)
{
    return 0;
}

int Sys_LaunchScript(int *args, int argc)
{
    const char *label = NULL;
    int arg = 0;
    if (argc > 0) {
        label = (const char *)args[0];
    }
    if (argc > 1) {
        arg = args[1];
    }
    if (label != NULL && label[0] != '\0' && MAIN_BSS_0210CA44 != NULL) {
        MAIN_BSS_0210CA44->LaunchScript(label, arg, -1);
    }
    return 0;
}

int Sys_StartBattleWithEnemy(int *args, int argc)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        int a = 0;
        if (argc > 0) {
            a = args[0];
        }
        BattleStartParam_Reset(scene->m_game->unk_143C);
        BattleResultParameter_Reset(scene->m_game->unk_1444);
        scene->AddBattleEnemy(a, -1, -1);
        scene->m_flags |= 1;
    }
    return 0;
}

int Sys_DisableEventRectAt(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    int map = 0;
    int idx = 0;
    if (argc > 0) {
        map = args[0];
    }
    if (argc > 1) {
        idx = args[1];
    }
    SaveData_DisableEventRect(save, idx, map);
    if (map == save->m_mapId) {
        FieldEventRectManage *manage = MAIN_BSS_0210CA58;
        if (manage != NULL) {
            CFieldEventRect *rect = manage->Get(idx);
            if (rect != NULL) {
                rect->unk_18 = 0;
            }
        }
    }
    return 0;
}

int Sys_EnableEventRectAt(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    int map = 0;
    int idx = 0;
    if (argc > 0) {
        map = args[0];
    }
    if (argc > 1) {
        idx = args[1];
    }
    SaveData_EnableEventRect(save, idx, map);
    if (map == save->m_mapId) {
        FieldEventRectManage *manage = MAIN_BSS_0210CA58;
        if (manage != NULL) {
            CFieldEventRect *rect = manage->Get(idx);
            if (rect != NULL) {
                rect->unk_18 = 1;
            }
        }
    }
    return 0;
}

int ov0_0214A034(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->LockPlayerControl();
    }
    return 0;
}

int ov0_0214A058(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->UnlockPlayerControl();
    }
    return 0;
}

int Sys_IsPlayerControlUnlocked(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        return !(MAIN_BSS_0210CA40->m_flags & 8) ? 1 : 0;
    }
    return 0;
}

int Sys_SetFieldWaza(int *args, int argc)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL && argc >= 2) {
        int waza = 0;
        int level = 1;
        const char *name = NULL;
        if (argc == 2) {
            waza = args[0];
            name = (const char *)args[1];
        } else if (argc >= 3) {
            waza = args[0];
            level = args[1];
            name = (const char *)args[2];
        }
        scene->SetFieldWaza(waza, level, name);
        return 1;
    }
    return 0;
}

int Sys_ClearFieldWaza(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 == NULL) {
        return 0;
    }
    MAIN_BSS_0210CA40->ClearFieldWaza();
    return 1;
}
int Sys_RidePokemon(int *args, int argc)
{
    u32 id = args[0];
    SaveData *save = &MAIN_BSS_020B26A0;
    SaveData_AddPokemonRides(save, 1);
    PartyEntry *data = SaveData_FindEntry(save, id);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (data != NULL && player != NULL) {
        switch (data->m_kind) {
        case 0x2B:
            player->SetRideMode(2);
            save->unk_8802 = 2;
            Audio()->PlayStream2(0x54, 0x40);
            break;
        case 0x6A:
            player->SetRideMode(6);
            save->unk_8802 = 6;
            Audio()->PlayStream2(0xE2, 0x40);
            break;
        case 0xA9:
        case 0x129:
            player->SetRideMode(3);
            save->unk_8802 = 3;
            Audio()->PlayStream2(0x18B, 0x40);
            if (Audio()->unk_F0 != 1) {
                Audio()->LoadBgmGroup(0x1E);
                Audio()->PlayBgm(0x10, 0);
                Audio()->sub_02034F4C(1);
            }
            break;
        case 0xAC:
            player->SetRideMode(5);
            save->unk_8802 = 5;
            break;
        case 0xBE:
            player->SetRideMode(4);
            save->unk_8802 = 4;
            Audio()->PlayStream2(0x1A3, 0x40);
            break;
        case 0x8E:
            player->SetRideMode(7);
            save->unk_8802 = 7;
            Audio()->PlayStream2(0x144, 0x40);
            break;
        }
        SaveData_SelectPartyEntry(save, id);
        if (MAIN_BSS_0210CA4C != NULL) {
            MAIN_BSS_0210CA4C->DeactivateAll();
        }
    }
    return 0;
}

int Sys_GetOffPokemon(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    u32 ret = 0;
    u32 id = save->m_selectedPartyId;
    if (id != 0) {
        u8 ride = save->unk_8802;
        PartyEntry *data = SaveData_FindEntry(save, id);
        CFieldPlayer *player = MAIN_BSS_0210CA48;
        if (data != NULL && player != NULL) {
            switch (ride) {
            case 1:
            case 6:
                player->SetRideMode(1);
                save->unk_8802 = 1;
                break;
            case 3: {
                FieldData *maps = MAIN_BSS_0210CA6C;
                if (Audio()->m_bgmSeq == 0x10) {
                    FieldData_GetMap(maps, save->m_mapId);
                    Audio()->sub_02034F4C(0);
                    Audio()->PlayMapBgm(save->m_mapId, 0x1E, 0);
                }
            }
            default:
                player->SetRideMode(0);
                save->unk_8802 = 0;
                break;
            }
            CFieldPartnerManage *partners = MAIN_BSS_0210CA4C;
            if (partners != NULL) {
                partners->ActivateAll();
                partners->SetPosAll(player->GetPos());
            }
        }
        SaveData_SelectPartyEntry(save, 0);
        ret = id;
    }
    return ret;
}
int Sys_GetSelectedPartyId(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->m_selectedPartyId;
    }
    return 0;
}

int ov0_0214A588(int *args, int argc)
{
    int arg = args[0];
    u32 id = args[1];
    if (MAIN_BSS_0210CA40 != NULL && (((int)id >> 24) & 0xFF) == 3) {
        CFieldTargetObject *obj = (CFieldTargetObject *)MAIN_BSS_0210CA40->FindActor(id);
        if (obj != NULL) {
            obj->CallTargetClear(arg);
        }
    }
    return 0;
}

int Sys_GetPartyEntryId(int *args, int argc)
{
    PartyEntry *record = SaveData_GetEntry(&MAIN_BSS_020B26A0, args[0]);
    if (record != NULL && (record->m_flags & 1)) {
        return (record->m_index & 0xFFF) | (((record->m_mapId & 0xFFF) << 12) | 0x6000000);
    }
    return 0;
}

int ov0_0214A62C(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    PartnerSlot *partner = save->GetPartner(args[0]);
    if (partner != NULL && partner->unk_00 != 0) {
        return partner->unk_04;
    }
    return 0;
}

int Sys_GetEnemyId(int *args, int argc)
{
    int idx = args[0];
    CFieldEnemyManage *manage = MAIN_BSS_0210CA5C;
    if (manage != NULL) {
        CFieldActor *enemy = manage->Get(idx);
        if (enemy != NULL && enemy->IsActive()) {
            return enemy->m_id;
        }
    }
    return 0;
}

int ov0_0214A6D4(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        int *p = &MAIN_BSS_0210CA40->unk_0140;
        if (p != NULL) {
            *p = args[0];
        }
    }
    return 0;
}

int ov0_0214A6FC(int *args, int argc)
{
    BOOL ret = TRUE;
    if (MAIN_BSS_0210CA40 != NULL) {
        int *p = &MAIN_BSS_0210CA40->unk_0140;
        if (p != NULL && *p >= args[0]) {
            ret = FALSE;
        }
    }
    return ret;
}

int Sys_CreateCannon(int *args, int argc)
{
    int ret = -1;
    if (MAIN_BSS_0210CA40 != NULL) {
        ret = MAIN_BSS_0210CA40->m_cannons->CreateCannon(args[0], 0, 0);
    }
    return ret;
}

int Sys_ActivateCannon(int *args, int argc)
{
    int ret = 0;
    if (MAIN_BSS_0210CA40 != NULL) {
        int flag = args[1];
        CFieldCannon *entry = MAIN_BSS_0210CA40->m_cannons->GetCannon(args[0]);
        if (entry != NULL && flag != 0) {
            entry->SetEnabled(1);
            ret = entry->unk_20;
        }
    }
    return ret;
}

int Sys_SetCannonPos(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        int a = args[1];
        int b = args[2];
        CFieldCannon *entry = MAIN_BSS_0210CA40->m_cannons->GetCannon(args[0]);
        if (entry != NULL) {
            entry->SetOrigin(a, b);
        }
    }
    return 0;
}

int Sys_SetCannonParams(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        int a1 = args[1];
        int a2 = args[2];
        int a3 = args[3];
        int a4 = args[4];
        int a5 = args[5];
        int a6 = args[6];
        int a7 = args[7];
        int a8 = args[8];
        CFieldCannon *entry = MAIN_BSS_0210CA40->m_cannons->GetCannon(args[0]);
        if (entry != NULL) {
            entry->SetParams(a1, a2, a3, a4, a5, a6, a7, a8);
        }
    }
    return 0;
}

int Sys_HideEnemies(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_flags |= 0x400;
    }
    return 0;
}

int Sys_ShowEnemies(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->m_flags &= ~0x400;
    }
    return 0;
}
int Sys_IsPlayerAtTargetObject(int *args, int argc)
{
    CFieldActor *obj = MAIN_BSS_0210CA7C->Get(args[0] & 0xFFF);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    Point2D pos = player->GetPos();
    Rectangle rect = obj->unk_34;
    rect.pos.x = obj->GetX();
    rect.pos.y = obj->GetY() + 0x10000;
    rect.size.x += 0x2000;
    rect.size.y += 0x2000;
    if (player->m_layer == obj->m_layer && PointInRect(pos, rect, 0)) {
        return TRUE;
    }
    return FALSE;
}
int Sys_IsPlayerAtTargetObjectEx(int *args, int argc)
{
    int height = args[1];
    CFieldActor *obj = MAIN_BSS_0210CA7C->Get(args[0] & 0xFFF);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    Point2D pos = player->GetPos();
    Rectangle rect = obj->unk_34;
    rect.pos.x = obj->GetX();
    rect.pos.y = obj->GetY() + (height << FX32_SHIFT);
    rect.size.x += 0x2000;
    rect.size.y += 0x2000;
    if (player->m_layer == obj->m_layer && PointInRect(pos, rect, 0)) {
        return TRUE;
    }
    return FALSE;
}
int ov0_0214ABC8(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->unk_8B80;
    }
    return 0;
}

int ov0_0214ABE4(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->unk_8B78;
    }
    return 0;
}

int ov0_0214AC00(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->unk_8B7A;
    }
    return 0;
}

int ov0_0214AC1C(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->unk_8B7C;
    }
    return 0;
}

int Sys_QuadraticInterpolate(int *args, int argc)
{
    return QuadraticInterpolate(args[0], args[1], args[2], args[3], args[4]);
}

int Sys_IsPlayerAboveEventRect(int *args, int argc)
{
    int idx = args[0];
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    FieldEventRectManage *manage = MAIN_BSS_0210CA58;
    if (manage != NULL && player != NULL) {
        CFieldEventRect *rect = manage->Get(idx);
        if (rect != NULL) {
            fx32 y = player->GetY();
            Rectangle area = rect->m_rect;
            return (y & -0x1000) <= area.pos.y - (area.size.y >> 1);
        }
    }
    return 0;
}

int Sys_IsPlayerBelowEventRect(int *args, int argc)
{
    int idx = args[0];
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    FieldEventRectManage *manage = MAIN_BSS_0210CA58;
    if (manage != NULL && player != NULL) {
        CFieldEventRect *rect = manage->Get(idx);
        if (rect != NULL) {
            fx32 y = player->GetY();
            Rectangle area = rect->m_rect;
            return (y & -0x1000) >= area.pos.y + (area.size.y >> 1);
        }
    }
    return 0;
}

int Sys_IsPlayerLeftOfEventRect(int *args, int argc)
{
    int idx = args[0];
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    FieldEventRectManage *manage = MAIN_BSS_0210CA58;
    if (manage != NULL && player != NULL) {
        CFieldEventRect *rect = manage->Get(idx);
        if (rect != NULL) {
            fx32 x = player->GetX();
            Rectangle area = rect->m_rect;
            return (x & -0x1000) <= area.pos.x - (area.size.x >> 1);
        }
    }
    return 0;
}

int Sys_IsPlayerRightOfEventRect(int *args, int argc)
{
    int idx = args[0];
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    FieldEventRectManage *manage = MAIN_BSS_0210CA58;
    if (manage != NULL && player != NULL) {
        CFieldEventRect *rect = manage->Get(idx);
        if (rect != NULL) {
            fx32 x = player->GetX();
            Rectangle area = rect->m_rect;
            return (x & -0x1000) >= area.pos.x + (area.size.x >> 1);
        }
    }
    return 0;
}
int Sys_KnockBackPlayer(int *args, int argc)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    int x = args[0];
    int y = args[1];
    int arg3 = args[2];
    int damage = args[3];
    Point2D pos = player->GetPos();
    u16 angle = FX_Atan2Idx(pos.y - (y << FX32_SHIFT), pos.x - (x << FX32_SHIFT));
    player->KnockBack(FX_CosIdx(angle) << FX32_SHIFT,
        FX_SinIdx(angle) << FX32_SHIFT,
        arg3,
        damage,
        -1);
    return 0;
}

int Sys_IsFlagValid(int *args, int argc)
{
    u32 flags = MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF];
    return ((flags & 1) ? TRUE : FALSE) ? TRUE : FALSE;
}

int Sys_SetFlagCount(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    save->SetFlagCount(i, args[1], args[2]);
    return 0;
}

int Sys_SetFlagSub(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    u32 flags = save->unk_81B4[i];
    save->unk_81B4[i] = (flags & 0xFFFFF0FE) | ((u32)(args[1] << 28) >> 20) | 1;
    return 0;
}

int Sys_GetFlagCount(int *args, int argc)
{
    return (MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 12) & 0xFF;
}

int Sys_GetFlagSub(int *args, int argc)
{
    return (MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 8) & 0xF;
}

int Sys_IsActorFloating(int *args, int argc)
{
    u32 id = args[0];
    int ret = 0;
    if (MAIN_BSS_0210CA40 != NULL) {
        CFieldActor *actor = MAIN_BSS_0210CA40->FindActor(id);
        if (actor != NULL && actor->m_floatBase > 0) {
            ret = 1;
        }
    }
    return ret;
}

int ov0_0214B180(int *args, int argc)
{
    return MAIN_BSS_0210CA48->unk_104;
}
int Sys_IsPlayerNearTargetObject(int *args, int argc)
{
    int height = args[1];
    CFieldActor *obj = MAIN_BSS_0210CA7C->Get(args[0] & 0xFFF);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    Point2D pos = player->GetPos();
    Rectangle rect = obj->unk_34;
    rect.pos.x = obj->GetX();
    rect.pos.y = obj->GetY() + (height << FX32_SHIFT);
    rect.size.x += 0x18000;
    rect.size.y += 0x18000;
    if (player->m_layer == obj->m_layer && PointInRect(pos, rect, 0)) {
        return TRUE;
    }
    return FALSE;
}

int ov0_0214B320(int *args, int argc)
{
    MAIN_BSS_020B26A0.unk_81B0 = args[0];
    return 0;
}

int Sys_SetFlagCountValue(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    int i = args[0];
    int value = args[1];
    int w = args[2];
    if (w < 0 || w > 0xFFFF) {
        w = 0;
    }
    u32 j = i & 0x3FF;
    u32 flags = save->unk_81B4[j];
    save->unk_81B4[j] = (flags & 0xFFE) | (w << 20) | ((u32)(value << 24) >> 12) | 1;
    return 0;
}

int Sys_SetFlagPos(int *args, int argc)
{
    int i = args[0];
    Point2D pos = { args[1] << FX32_SHIFT, args[2] << FX32_SHIFT };
    SetFlagPos(i, pos);
    return 0;
}

int Sys_GetFlagX(int *args, int argc)
{
    return (s16)(GetFlagPos(args[0]).x >> FX32_SHIFT);
}

int Sys_GetFlagY(int *args, int argc)
{
    return (s16)(GetFlagPos(args[0]).y >> FX32_SHIFT);
}

int Sys_GetFlagValue(int *args, int argc)
{
    return (u16)(MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 20);
}

int Sys_SetFlagKind(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    save->SetFlagKind(i, args[1]);
    return 0;
}
int Sys_GetFlagKind(int *args, int argc)
{
    return (MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 1) & 0x7F;
}

int Sys_SetFlagValue(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    save->SetFlagValue(i, args[1]);
    return 0;
}

int Sys_IsFieldBusy(int *args, int argc)
{
    BOOL ret = FALSE;
    FieldScriptLauncher *runner = MAIN_BSS_0210CA44;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (runner != NULL && runner->IsBusy()) {
        ret = TRUE;
    }
    if (scene != NULL) {
        int state = scene->unk_0084;
        if (!(!(scene->m_flags & 8) ? TRUE : FALSE) || state == 3 || state == 4 || state == 7 || state == 5 || state == 6 || state == 8 || state == 9 || state == 0x14) {
            ret = TRUE;
        }
    }
    return ret;
}

int Sys_SetButton1Enabled(int *args, int argc)
{
    int enable = args[0];
    SaveData *save = &MAIN_BSS_020B26A0;
    if (enable == 0) {
        save->unk_8756 |= 1;
    } else {
        save->unk_8756 &= ~1;
    }
    return 0;
}

int Sys_SetButton2Enabled(int *args, int argc)
{
    int enable = args[0];
    SaveData *save = &MAIN_BSS_020B26A0;
    if (enable == 0) {
        save->unk_8756 |= 2;
    } else {
        save->unk_8756 &= ~2;
    }
    return 0;
}

int Sys_IsButton1Enabled(int *args, int argc)
{
    return MAIN_BSS_020B26A0.IsButton1Enabled();
}

int Sys_IsButton2Enabled(int *args, int argc)
{
    return MAIN_BSS_020B26A0.IsButton2Enabled();
}

int ov0_0214B68C(int *args, int argc)
{
    u32 id = args[0];
    if (MAIN_BSS_0210CA40 != NULL) {
        CFieldActor *actor = MAIN_BSS_0210CA40->FindActor(id);
        if (actor != NULL) {
            actor->SetMoveSequence(0x19);
        }
    }
    return 0;
}

int ov0_0214B6CC(int *args, int argc)
{
    if (MAIN_BSS_0210CA60 != NULL) {
        MAIN_BSS_0210CA60->ov0_0214366C();
    }
    return 0;
}
}
