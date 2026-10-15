#include "scene/CBattleToFieldScene.hpp"

#include <string.h>

#include "AudioEngine.hpp"
#include "BattleStartParam.hpp"
#include "CBattleResultParameter.hpp"
#include "CGame.hpp"
#include "SaveData.hpp"
#include "UnkStruct_020107A8.hpp"

extern "C" {
void SaveData_LotTimeCheck(SaveData *save);
BOOL SaveData_AddToParty(SaveData *save, u32 id, int kind, int area);
BOOL SaveData_RemoveFromParty(SaveData *save, u32 id);
u32 SaveData_AddExp(SaveData *save, u32 value);
u32 SaveData_AddPartnerCount(SaveData *save, int kind, u32 value);
u32 SaveData_AddCaptureLineLength(SaveData *save, u32 value);
u32 SaveData_AddLoopCount(SaveData *save, u32 value);
u16 SaveData_AddTotalCaptures(SaveData *save, u16 value);
u16 SaveData_AddFledCount(SaveData *save, u16 value);
u16 SaveData_AddAssistsUsed(SaveData *save, u16 value);
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

static inline u32 GetPokemonState2(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->unk_7EB0[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 3;
}

static inline void LowerPokemonState2(SaveData *save, int i, u32 state)
{
    if (i >= 0 && i < 500 && state <= 3) {
        if (state < GetPokemonState2(save, i)) {
            int shift = (i & 0xF) * 2;
            save->unk_7EB0[i >> 4] &= ~(3 << shift);
            save->unk_7EB0[i >> 4] |= (state & 3) << shift;
        }
    }
}

static inline void SetCaptureCount(SaveData *save, u16 id, int count)
{
    if (count <= 0) {
        save->m_captureCounts[id] = 0;
    } else if (count >= 0xFF) {
        save->m_captureCounts[id] = 0xFF;
    } else {
        save->m_captureCounts[id] = count;
    }
}

static inline void SetSaveName(SaveData *save, const char *name)
{
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
}

static inline void SetEnemyStateById(SaveData *save, u32 id, u8 state)
{
    int mapId = ((int)id >> 12) & 0xFFF;
    int i = id & 0xFFF;
    save->SetEnemyState(mapId, i, state);
}

void CBattleToFieldScene::func6()
{
    CBattleResultParameter *result;
    SaveData *save;
    PokeIdTable *table;
    u32 kind;
    u32 ids[10];
    int enemyCount;
    int idCount;
    int count;

    save = &MAIN_BSS_020B26A0;
    result = game->unk_1444;
    table = game->unk_1434;
    kind = result->unk_08;

    if (game->unk_0008 == 0) {
        game->m_audioEngine->RestoreFieldBgm();
        game->m_audioEngine->SetLoopSeVolume(0);
    }
    if (result->unk_04 != 0xFF) {
        save->m_energy = result->unk_04;
    }
    save->unk_0004 = result->unk_10;
    SaveData_LotTimeCheck(save);

    count = 0;
    enemyCount = result->unk_14;
    idCount = result->unk_6C;
    for (int i = 0; i < 10; i++) {
        PartyEntry *data = SaveData_GetEntry(save, i);
        if (data != NULL && (data->m_flags & 1)) {
            ids[count] = (data->m_index & 0xFFF) | (((data->m_mapId & 0xFFF) << 12) | 0x6000000);
            if (++count >= idCount) {
                break;
            }
        }
    }
    for (int i = 0; i < idCount; i++) {
        if (result->unk_6D[(u8)i] != 0) {
            int id = ids[i];
            if (id >= 0) {
                PartyEntry *data = SaveData_FindEntry(save, id);
                if (data->m_flags & 2) {
                    SaveData_AddPartnerCount(save, data->m_kind, 1);
                } else {
                    SaveData_RemoveFromParty(save, id);
                }
                SaveData_AddAssistsUsed(save, 1);
            }
        }
    }

    if (kind != 0) {
        for (int i = 0; i < enemyCount; i++) {
            UnkStruct_020107A8 *rec = PokeIdTable_Get(table, result->unk_38[(u8)i]);
            RaisePokemonState(save, rec->unk_00, 1);
        }
    } else {
        for (int i = 0; i < enemyCount; i++) {
            UnkStruct_020107A8 *rec = PokeIdTable_Get(table, result->unk_38[(u8)i]);
            RaisePokemonState(save, rec->unk_00, 2);
            SetCaptureCount(save, rec->unk_00, save->m_captureCounts[rec->unk_00] + 1);
            LowerPokemonState2(save, rec->unk_00, result->unk_6A);
        }
        if (result->unk_80 > 0) {
            SaveData_AddExp(save, result->unk_80);
        }
        SaveData_AddTotalCaptures(save, result->unk_14);
    }
    SaveData_AddCaptureLineLength(save, result->unk_78);
    SaveData_AddLoopCount(save, result->unk_7C);
    save->unk_8803 = result->unk_6B;

    if (result->unk_0C == 1) {
        return;
    }
    if (game->unk_0008 == 0 && kind == 1) {
        game->m_audioEngine->LoadBgmGroup(0x2D);
        game->m_audioEngine->PlayBgm(5, 0x1E);
    }
    switch (kind) {
    case 0:
        if (result->unk_0C == 0) {
            for (int i = enemyCount - 1; i >= 0; i--) {
                u32 id = result->unk_18[(u8)i];
                SaveData_AddToParty(save, id, result->unk_38[(u8)i], -1);
                int idx = id & 0xFFF;
                int mapId = ((int)id >> 12) & 0xFFF;
                save->SetEnemyState(mapId, idx, 2);
            }
        } else {
            save->unk_8B74 = 4;
        }
        break;
    case 1:
        if (save->m_areaType == 5) {
            SetSaveName(save, "aBattleLose");
        } else {
            if (save->m_areaType == 1) {
                SetSaveName(save, "sGameOverBS");
            } else {
                SetSaveName(save, "sGameOverB");
            }
            save->unk_8B74 = 1;
        }
        break;
    case 4:
        for (int i = 0; i < enemyCount; i++) {
            u32 id = result->unk_18[(u8)i];
            SetEnemyStateById(save, id, 2);
        }
        break;
    case 3:
        save->unk_8B74 = 2;
        SaveData_AddFledCount(save, 1);
        break;
    }
}

u32 CBattleToFieldScene::func0()
{
    if (game->unk_1444->unk_0C != 1) {
        SaveData *save = &MAIN_BSS_020B26A0;
        int level = save->m_rangerClassGrade & 0xF;
        if (SaveData_CountParty(save, -1) > SaveData_GetPartyCapacity(save, level)) {
            save->unk_8BA0 = BattleStartParam_GetCaptureBg(game->unk_143C);
            return 7;
        }
    }
    return 1;
}
