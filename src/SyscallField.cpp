#include "AudioEngine.hpp"
#include "BattleStartParam.hpp"
#include "CBattleResultParameter.hpp"
#include "CGame.hpp"
#include "FieldCannons.hpp"
#include "FieldEventRectManage.hpp"
#include "FieldScriptLauncher.hpp"
#include "FieldSyscallSets.hpp"
#include "SaveData.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkStruct_02044464.hpp"
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
void sub_02015714(SaveData *save, int idx, int mapId);
void sub_0201577C(SaveData *save, int idx, int mapId);
u32 SaveData_AddPokemonRides(SaveData *save, u32 value);
UnkStruct_020155FC *SaveData_FindEntry(SaveData *save, u32 id);
UnkStruct_020155FC *SaveData_GetEntry(SaveData *save, int idx);
int ov0_02149E78(int *args, int argc);
int ov0_02149E80(int *args, int argc);
int ov0_02149ED0(int *args, int argc);
int ov0_02149F3C(int *args, int argc);
int ov0_02149FB8(int *args, int argc);
int ov0_0214A034(int *args, int argc);
int ov0_0214A058(int *args, int argc);
int ov0_0214A07C(int *args, int argc);
int ov0_0214A0AC(int *args, int argc);
int ov0_0214A110(int *args, int argc);
int ov0_0214A138(int *args, int argc);
int ov0_0214A3A8(int *args, int argc);
int ov0_0214A56C(int *args, int argc);
int ov0_0214A588(int *args, int argc);
int ov0_0214A5D4(int *args, int argc);
int ov0_0214A62C(int *args, int argc);
int ov0_0214A6D4(int *args, int argc);
int ov0_0214A6FC(int *args, int argc);
int ov0_0214A734(int *args, int argc);
int ov0_0214A76C(int *args, int argc);
int ov0_0214A7B8(int *args, int argc);
int ov0_0214A7FC(int *args, int argc);
int ov0_0214A678(int *args, int argc);
int ov0_0214A8B4(int *args, int argc);
int ov0_0214A86C(int *args, int argc);
int ov0_0214A890(int *args, int argc);
int ov0_0214AA3C(int *args, int argc);
int ov0_0214ABC8(int *args, int argc);
int ov0_0214ABE4(int *args, int argc);
int ov0_0214AC00(int *args, int argc);
int ov0_0214AC1C(int *args, int argc);
int ov0_0214AC38(int *args, int argc);
int ov0_0214AC54(int *args, int argc);
int ov0_0214AD0C(int *args, int argc);
int ov0_0214ADC4(int *args, int argc);
int ov0_0214AE7C(int *args, int argc);
int ov0_0214AF34(int *args, int argc);
int ov0_0214B020(int *args, int argc);
int ov0_0214B058(int *args, int argc);
int ov0_0214B0A8(int *args, int argc);
int ov0_0214B0F0(int *args, int argc);
int ov0_0214B118(int *args, int argc);
int ov0_0214B140(int *args, int argc);
int ov0_0214B180(int *args, int argc);
int ov0_0214B194(int *args, int argc);
int ov0_0214B320(int *args, int argc);
int ov0_0214B338(int *args, int argc);
int ov0_0214B39C(int *args, int argc);
int ov0_0214B3FC(int *args, int argc);
int ov0_0214B450(int *args, int argc);
int ov0_0214B4A4(int *args, int argc);
int ov0_0214B4D0(int *args, int argc);
int ov0_0214B50C(int *args, int argc);
int ov0_0214B534(int *args, int argc);
int ov0_0214B574(int *args, int argc);
int ov0_0214B5F4(int *args, int argc);
int ov0_0214B624(int *args, int argc);
int ov0_0214B654(int *args, int argc);
int ov0_0214B670(int *args, int argc);
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
    (ScriptSyscall)ov0_02149E80,
    (ScriptSyscall)ov0_02149ED0,
    (ScriptSyscall)ov0_02149F3C,
    (ScriptSyscall)ov0_02149FB8,
    (ScriptSyscall)ov0_0214A034,
    (ScriptSyscall)ov0_0214A058,
    (ScriptSyscall)ov0_0214A07C,
    (ScriptSyscall)ov0_0214A0AC,
    (ScriptSyscall)ov0_0214A110,
    (ScriptSyscall)ov0_0214A138,
    (ScriptSyscall)ov0_0214A3A8,
    (ScriptSyscall)ov0_0214A0AC,
    (ScriptSyscall)ov0_0214A56C,
    (ScriptSyscall)ov0_0214A588,
    (ScriptSyscall)ov0_0214A5D4,
    (ScriptSyscall)ov0_0214A62C,
    (ScriptSyscall)ov0_0214A6D4,
    (ScriptSyscall)ov0_0214A6FC,
    (ScriptSyscall)ov0_0214A734,
    (ScriptSyscall)ov0_0214A76C,
    (ScriptSyscall)ov0_0214A7B8,
    (ScriptSyscall)ov0_0214A7FC,
    (ScriptSyscall)ov0_0214A678,
    (ScriptSyscall)ov0_0214A8B4,
    (ScriptSyscall)ov0_0214A86C,
    (ScriptSyscall)ov0_0214A890,
    (ScriptSyscall)ov0_0214AA3C,
    (ScriptSyscall)ov0_0214ABC8,
    (ScriptSyscall)ov0_0214ABE4,
    (ScriptSyscall)ov0_0214AC00,
    (ScriptSyscall)ov0_0214AC1C,
    (ScriptSyscall)ov0_0214AC38,
    (ScriptSyscall)ov0_0214AC54,
    (ScriptSyscall)ov0_0214AD0C,
    (ScriptSyscall)ov0_0214ADC4,
    (ScriptSyscall)ov0_0214AE7C,
    (ScriptSyscall)ov0_0214AF34,
    (ScriptSyscall)ov0_0214B020,
    (ScriptSyscall)ov0_0214B058,
    (ScriptSyscall)ov0_0214B0A8,
    (ScriptSyscall)ov0_0214B0F0,
    (ScriptSyscall)ov0_0214B118,
    (ScriptSyscall)ov0_0214B140,
    (ScriptSyscall)ov0_0214B180,
    (ScriptSyscall)ov0_0214B194,
    (ScriptSyscall)ov0_0214B320,
    (ScriptSyscall)ov0_0214B338,
    (ScriptSyscall)ov0_0214B39C,
    (ScriptSyscall)ov0_0214B3FC,
    (ScriptSyscall)ov0_0214B450,
    (ScriptSyscall)ov0_0214B4A4,
    (ScriptSyscall)ov0_0214B4D0,
    (ScriptSyscall)ov0_0214B50C,
    (ScriptSyscall)ov0_0214B534,
    (ScriptSyscall)ov0_0214B574,
    (ScriptSyscall)ov0_0214B5F4,
    (ScriptSyscall)ov0_0214B624,
    (ScriptSyscall)ov0_0214B654,
    (ScriptSyscall)ov0_0214B670,
    (ScriptSyscall)ov0_0214B68C,
    (ScriptSyscall)ov0_0214B6CC,
};

FieldSyscalls::FieldSyscalls()
{
}

FieldSyscalls::~FieldSyscalls()
{
}

void FieldSyscalls::ov0_02149E60()
{
    Script_RegisterSyscalls(0xE, sFieldSyscalls);
}

extern "C" {

int ov0_02149E78(int *args, int argc)
{
    return 0;
}

int ov0_02149E80(int *args, int argc)
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
        MAIN_BSS_0210CA44->ov0_0213FB0C(label, arg, -1);
    }
    return 0;
}

int ov0_02149ED0(int *args, int argc)
{
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (scene != NULL) {
        int a = 0;
        if (argc > 0) {
            a = args[0];
        }
        BattleStartParam_Reset(scene->m_game->unk_143C);
        sub_02010D04(scene->m_game->unk_1444);
        scene->ov0_02122FEC(a, -1, -1);
        scene->unk_00D0 |= 1;
    }
    return 0;
}

int ov0_02149F3C(int *args, int argc)
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
    sub_0201577C(save, idx, map);
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

int ov0_02149FB8(int *args, int argc)
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
    sub_02015714(save, idx, map);
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
        MAIN_BSS_0210CA40->ov0_021247E4();
    }
    return 0;
}

int ov0_0214A058(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->ov0_021248DC();
    }
    return 0;
}

int ov0_0214A07C(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        return !(MAIN_BSS_0210CA40->unk_00D0 & 8) ? 1 : 0;
    }
    return 0;
}

int ov0_0214A0AC(int *args, int argc)
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
        scene->ov0_021240AC(waza, level, name);
        return 1;
    }
    return 0;
}

int ov0_0214A110(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 == NULL) {
        return 0;
    }
    MAIN_BSS_0210CA40->ov0_0212419C();
    return 1;
}
int ov0_0214A138(int *args, int argc)
{
    u32 id = args[0];
    SaveData *save = &MAIN_BSS_020B26A0;
    SaveData_AddPokemonRides(save, 1);
    UnkStruct_020155FC *data = SaveData_FindEntry(save, id);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    if (data != NULL && player != NULL) {
        switch (data->unk_00) {
        case 0x2B:
            player->ov0_02132FA0(2);
            save->unk_8802 = 2;
            Audio()->sub_02034D54(0x54, 0x40);
            break;
        case 0x6A:
            player->ov0_02132FA0(6);
            save->unk_8802 = 6;
            Audio()->sub_02034D54(0xE2, 0x40);
            break;
        case 0xA9:
        case 0x129:
            player->ov0_02132FA0(3);
            save->unk_8802 = 3;
            Audio()->sub_02034D54(0x18B, 0x40);
            if (Audio()->unk_F0 != 1) {
                Audio()->LoadBgmGroup(0x1E);
                Audio()->PlayBgm(0x10, 0);
                Audio()->sub_02034F4C(1);
            }
            break;
        case 0xAC:
            player->ov0_02132FA0(5);
            save->unk_8802 = 5;
            break;
        case 0xBE:
            player->ov0_02132FA0(4);
            save->unk_8802 = 4;
            Audio()->sub_02034D54(0x1A3, 0x40);
            break;
        case 0x8E:
            player->ov0_02132FA0(7);
            save->unk_8802 = 7;
            Audio()->sub_02034D54(0x144, 0x40);
            break;
        }
        sub_020162BC(save, id);
        if (MAIN_BSS_0210CA4C != NULL) {
            MAIN_BSS_0210CA4C->sub_02040460();
        }
    }
    return 0;
}

int ov0_0214A3A8(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    u32 ret = 0;
    u32 id = save->unk_7C38;
    if (id != 0) {
        u8 ride = save->unk_8802;
        UnkStruct_020155FC *data = SaveData_FindEntry(save, id);
        CFieldPlayer *player = MAIN_BSS_0210CA48;
        if (data != NULL && player != NULL) {
            switch (ride) {
            case 1:
            case 6:
                player->ov0_02132FA0(1);
                save->unk_8802 = 1;
                break;
            case 3: {
                FieldData *maps = MAIN_BSS_0210CA6C;
                if (Audio()->unk_D0 == 0x10) {
                    FieldData_GetMap(maps, save->m_mapId);
                    Audio()->sub_02034F4C(0);
                    Audio()->PlayMapBgm(save->m_mapId, 0x1E, 0);
                }
            }
            default:
                player->ov0_02132FA0(0);
                save->unk_8802 = 0;
                break;
            }
            CFieldPartnerManage *partners = MAIN_BSS_0210CA4C;
            if (partners != NULL) {
                partners->sub_02040428();
                partners->SetPosAll(player->GetPos());
            }
        }
        sub_020162BC(save, 0);
        ret = id;
    }
    return ret;
}
int ov0_0214A56C(int *args, int argc)
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    if (save != NULL) {
        return save->unk_7C38;
    }
    return 0;
}

int ov0_0214A588(int *args, int argc)
{
    int arg = args[0];
    u32 id = args[1];
    if (MAIN_BSS_0210CA40 != NULL && (((int)id >> 24) & 0xFF) == 3) {
        CFieldTargetObject *obj = (CFieldTargetObject *)MAIN_BSS_0210CA40->ov0_02123060(id);
        if (obj != NULL) {
            obj->ov0_0213CD78(arg);
        }
    }
    return 0;
}

int ov0_0214A5D4(int *args, int argc)
{
    UnkStruct_020155FC *record = SaveData_GetEntry(&MAIN_BSS_020B26A0, args[0]);
    if (record != NULL && (record->unk_08 & 1)) {
        return (record->unk_04 & 0xFFF) | (((record->unk_02 & 0xFFF) << 12) | 0x6000000);
    }
    return 0;
}

int ov0_0214A62C(int *args, int argc)
{
    SaveData *save = &MAIN_BSS_020B26A0;
    UnkStruct_020B26A0_8AD4 *partner = save->GetPartner(args[0]);
    if (partner != NULL && partner->unk_00 != 0) {
        return partner->unk_04;
    }
    return 0;
}

int ov0_0214A678(int *args, int argc)
{
    int idx = args[0];
    CFieldEnemyManage *manage = MAIN_BSS_0210CA5C;
    if (manage != NULL) {
        CFieldActor *enemy = manage->Get(idx);
        if (enemy != NULL && enemy->IsActive()) {
            return enemy->unk_58;
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

int ov0_0214A734(int *args, int argc)
{
    int ret = -1;
    if (MAIN_BSS_0210CA40 != NULL) {
        ret = MAIN_BSS_0210CA40->unk_005C->ov0_02159B84(args[0], 0, 0);
    }
    return ret;
}

int ov0_0214A76C(int *args, int argc)
{
    int ret = 0;
    if (MAIN_BSS_0210CA40 != NULL) {
        int flag = args[1];
        CFieldCannon *entry = MAIN_BSS_0210CA40->unk_005C->ov0_02159DFC(args[0]);
        if (entry != NULL && flag != 0) {
            entry->ov0_0215A384(1);
            ret = entry->unk_20;
        }
    }
    return ret;
}

int ov0_0214A7B8(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        int a = args[1];
        int b = args[2];
        CFieldCannon *entry = MAIN_BSS_0210CA40->unk_005C->ov0_02159DFC(args[0]);
        if (entry != NULL) {
            entry->ov0_0215A3BC(a, b);
        }
    }
    return 0;
}

int ov0_0214A7FC(int *args, int argc)
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
        CFieldCannon *entry = MAIN_BSS_0210CA40->unk_005C->ov0_02159DFC(args[0]);
        if (entry != NULL) {
            entry->ov0_0215A3D4(a1, a2, a3, a4, a5, a6, a7, a8);
        }
    }
    return 0;
}

int ov0_0214A86C(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->unk_00D0 |= 0x400;
    }
    return 0;
}

int ov0_0214A890(int *args, int argc)
{
    if (MAIN_BSS_0210CA40 != NULL) {
        MAIN_BSS_0210CA40->unk_00D0 &= ~0x400;
    }
    return 0;
}
int ov0_0214A8B4(int *args, int argc)
{
    CFieldActor *obj = MAIN_BSS_0210CA7C->Get(args[0] & 0xFFF);
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    Point2D pos = player->GetPos();
    Rectangle rect = obj->unk_34;
    rect.pos.x = obj->GetX();
    rect.pos.y = obj->GetY() + 0x10000;
    rect.size.x += 0x2000;
    rect.size.y += 0x2000;
    if (player->unk_14 == obj->unk_14 && PointInRect(pos, rect, 0)) {
        return TRUE;
    }
    return FALSE;
}
int ov0_0214AA3C(int *args, int argc)
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
    if (player->unk_14 == obj->unk_14 && PointInRect(pos, rect, 0)) {
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

int ov0_0214AC38(int *args, int argc)
{
    return QuadraticInterpolate(args[0], args[1], args[2], args[3], args[4]);
}

int ov0_0214AC54(int *args, int argc)
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

int ov0_0214AD0C(int *args, int argc)
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

int ov0_0214ADC4(int *args, int argc)
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

int ov0_0214AE7C(int *args, int argc)
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
int ov0_0214AF34(int *args, int argc)
{
    CFieldPlayer *player = MAIN_BSS_0210CA48;
    int x = args[0];
    int y = args[1];
    int arg3 = args[2];
    int damage = args[3];
    Point2D pos = player->GetPos();
    u16 angle = FX_Atan2Idx(pos.y - (y << FX32_SHIFT), pos.x - (x << FX32_SHIFT));
    player->ov0_021333A0(FX_CosIdx(angle) << FX32_SHIFT,
        FX_SinIdx(angle) << FX32_SHIFT,
        arg3,
        damage,
        -1);
    return 0;
}

int ov0_0214B020(int *args, int argc)
{
    u32 flags = MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF];
    return ((flags & 1) ? TRUE : FALSE) ? TRUE : FALSE;
}

int ov0_0214B058(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    save->SetFlagCount(i, args[1], args[2]);
    return 0;
}

int ov0_0214B0A8(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    u32 flags = save->unk_81B4[i];
    save->unk_81B4[i] = (flags & 0xFFFFF0FE) | ((u32)(args[1] << 28) >> 20) | 1;
    return 0;
}

int ov0_0214B0F0(int *args, int argc)
{
    return (MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 12) & 0xFF;
}

int ov0_0214B118(int *args, int argc)
{
    return (MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 8) & 0xF;
}

int ov0_0214B140(int *args, int argc)
{
    u32 id = args[0];
    int ret = 0;
    if (MAIN_BSS_0210CA40 != NULL) {
        CFieldActor *actor = MAIN_BSS_0210CA40->ov0_02123060(id);
        if (actor != NULL && actor->unk_A8 > 0) {
            ret = 1;
        }
    }
    return ret;
}

int ov0_0214B180(int *args, int argc)
{
    return MAIN_BSS_0210CA48->unk_104;
}
int ov0_0214B194(int *args, int argc)
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
    if (player->unk_14 == obj->unk_14 && PointInRect(pos, rect, 0)) {
        return TRUE;
    }
    return FALSE;
}

int ov0_0214B320(int *args, int argc)
{
    MAIN_BSS_020B26A0.unk_81B0 = args[0];
    return 0;
}

int ov0_0214B338(int *args, int argc)
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

int ov0_0214B39C(int *args, int argc)
{
    int i = args[0];
    Point2D pos = { args[1] << FX32_SHIFT, args[2] << FX32_SHIFT };
    SetFlagPos(i, pos);
    return 0;
}

int ov0_0214B3FC(int *args, int argc)
{
    return (s16)(GetFlagPos(args[0]).x >> FX32_SHIFT);
}

int ov0_0214B450(int *args, int argc)
{
    return (s16)(GetFlagPos(args[0]).y >> FX32_SHIFT);
}

int ov0_0214B4A4(int *args, int argc)
{
    return (u16)(MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 20);
}

int ov0_0214B4D0(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    save->SetFlagKind(i, args[1]);
    return 0;
}
int ov0_0214B50C(int *args, int argc)
{
    return (MAIN_BSS_020B26A0.unk_81B4[args[0] & 0x3FF] >> 1) & 0x7F;
}

int ov0_0214B534(int *args, int argc)
{
    u32 i = args[0] & 0x3FF;
    SaveData *save = &MAIN_BSS_020B26A0;
    save->SetFlagValue(i, args[1]);
    return 0;
}

int ov0_0214B574(int *args, int argc)
{
    BOOL ret = FALSE;
    FieldScriptLauncher *runner = MAIN_BSS_0210CA44;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    if (runner != NULL && runner->ov0_0213FEEC()) {
        ret = TRUE;
    }
    if (scene != NULL) {
        int state = scene->unk_0084;
        if (!(!(scene->unk_00D0 & 8) ? TRUE : FALSE) || state == 3 || state == 4 || state == 7 || state == 5 || state == 6 || state == 8 || state == 9 || state == 0x14) {
            ret = TRUE;
        }
    }
    return ret;
}

int ov0_0214B5F4(int *args, int argc)
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

int ov0_0214B624(int *args, int argc)
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

int ov0_0214B654(int *args, int argc)
{
    return MAIN_BSS_020B26A0.IsButton1Enabled();
}

int ov0_0214B670(int *args, int argc)
{
    return MAIN_BSS_020B26A0.IsButton2Enabled();
}

int ov0_0214B68C(int *args, int argc)
{
    u32 id = args[0];
    if (MAIN_BSS_0210CA40 != NULL) {
        CFieldActor *actor = MAIN_BSS_0210CA40->ov0_02123060(id);
        if (actor != NULL) {
            actor->sub_02032A44(0x19);
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
