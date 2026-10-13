#include "scene/CBattleToFieldScene.hpp"

#include <string.h>

#include "CBattleResultParameter.hpp"
#include "CGame.hpp"
#include "UnkClass_02010854.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkStruct_020107A8.hpp"

extern "C" {
void sub_0201668C(UnkClass_020B26A0 *save);
BOOL sub_02015C78(UnkClass_020B26A0 *save, u32 id, int kind, int area);
BOOL sub_02015E54(UnkClass_020B26A0 *save, u32 id);
u32 sub_02016D64(UnkClass_020B26A0 *save, u32 value);
u32 sub_02016F18(UnkClass_020B26A0 *save, int kind, u32 value);
u32 sub_0201703C(UnkClass_020B26A0 *save, u32 value);
u32 sub_02017084(UnkClass_020B26A0 *save, u32 value);
u16 sub_020170D0(UnkClass_020B26A0 *save, u16 value);
u16 sub_02017120(UnkClass_020B26A0 *save, u16 value);
u16 sub_02017170(UnkClass_020B26A0 *save, u16 value);
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

static inline u32 GetPokemonState2(UnkClass_020B26A0 *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->unk_7EB0[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 3;
}

static inline void LowerPokemonState2(UnkClass_020B26A0 *save, int i, u32 state)
{
    if (i >= 0 && i < 500 && state <= 3) {
        if (state < GetPokemonState2(save, i)) {
            int shift = (i & 0xF) * 2;
            save->unk_7EB0[i >> 4] &= ~(3 << shift);
            save->unk_7EB0[i >> 4] |= (state & 3) << shift;
        }
    }
}

static inline void SetCaptureCount(UnkClass_020B26A0 *save, u16 id, int count)
{
    if (count <= 0) {
        save->unk_7CBC[id] = 0;
    } else if (count >= 0xFF) {
        save->unk_7CBC[id] = 0xFF;
    } else {
        save->unk_7CBC[id] = count;
    }
}

static inline void SetSaveName(UnkClass_020B26A0 *save, const char *name)
{
    if (name != NULL) {
        strcpy(save->unk_8B44, name);
    } else {
        save->unk_8B44[0] = '\0';
    }
}

static inline void SetEnemyStateById(UnkClass_020B26A0 *save, u32 id, u8 state)
{
    int mapId = ((int)id >> 12) & 0xFFF;
    int i = id & 0xFFF;
    save->SetEnemyState(mapId, i, state);
}

void CBattleToFieldScene::func6()
{
    CBattleResultParameter *result;
    UnkClass_020B26A0 *save;
    UnkClass_02010470 *table;
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
        game->m_audioEngine->sub_02034954();
        game->m_audioEngine->sub_02034F20(0);
    }
    if (result->unk_04 != 0xFF) {
        save->unk_0001 = result->unk_04;
    }
    save->unk_0004 = result->unk_10;
    sub_0201668C(save);

    count = 0;
    enemyCount = result->unk_14;
    idCount = result->unk_6C;
    for (int i = 0; i < 10; i++) {
        UnkStruct_020155FC *data = sub_020155FC(save, i);
        if (data != NULL && (data->unk_08 & 1)) {
            ids[count] = (data->unk_04 & 0xFFF) | (((data->unk_02 & 0xFFF) << 12) | 0x6000000);
            if (++count >= idCount) {
                break;
            }
        }
    }
    for (int i = 0; i < idCount; i++) {
        if (result->unk_6D[(u8)i] != 0) {
            int id = ids[i];
            if (id >= 0) {
                UnkStruct_020155FC *data = sub_02015520(save, id);
                if (data->unk_08 & 2) {
                    sub_02016F18(save, data->unk_00, 1);
                } else {
                    sub_02015E54(save, id);
                }
                sub_02017170(save, 1);
            }
        }
    }

    if (kind != 0) {
        for (int i = 0; i < enemyCount; i++) {
            UnkStruct_020107A8 *rec = sub_020107A8(table, result->unk_38[(u8)i]);
            RaisePokemonState(save, rec->unk_00, 1);
        }
    } else {
        for (int i = 0; i < enemyCount; i++) {
            UnkStruct_020107A8 *rec = sub_020107A8(table, result->unk_38[(u8)i]);
            RaisePokemonState(save, rec->unk_00, 2);
            SetCaptureCount(save, rec->unk_00, save->unk_7CBC[rec->unk_00] + 1);
            LowerPokemonState2(save, rec->unk_00, result->unk_6A);
        }
        if (result->unk_80 > 0) {
            sub_02016D64(save, result->unk_80);
        }
        sub_020170D0(save, result->unk_14);
    }
    sub_0201703C(save, result->unk_78);
    sub_02017084(save, result->unk_7C);
    save->unk_8803 = result->unk_6B;

    if (result->unk_0C == 1) {
        return;
    }
    if (game->unk_0008 == 0 && kind == 1) {
        game->m_audioEngine->sub_0203499C(0x2D);
        game->m_audioEngine->sub_02034A40(5, 0x1E);
    }
    switch (kind) {
    case 0:
        if (result->unk_0C == 0) {
            for (int i = enemyCount - 1; i >= 0; i--) {
                u32 id = result->unk_18[(u8)i];
                sub_02015C78(save, id, result->unk_38[(u8)i], -1);
                int idx = id & 0xFFF;
                int mapId = ((int)id >> 12) & 0xFFF;
                save->SetEnemyState(mapId, idx, 2);
            }
        } else {
            save->unk_8B74 = 4;
        }
        break;
    case 1:
        if (save->unk_8B64 == 5) {
            SetSaveName(save, "aBattleLose");
        } else {
            if (save->unk_8B64 == 1) {
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
        sub_02017120(save, 1);
        break;
    }
}

u32 CBattleToFieldScene::func0()
{
    if (game->unk_1444->unk_0C != 1) {
        UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
        int level = save->unk_0003 & 0xF;
        if (sub_02016138(save, -1) > sub_02015658(save, level)) {
            save->unk_8BA0 = sub_02010BB0(game->unk_143C);
            return 7;
        }
    }
    return 1;
}
