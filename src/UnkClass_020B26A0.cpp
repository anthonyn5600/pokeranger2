#include "UnkClass_020B26A0.hpp"

#include <nitro.h>
#include <stdarg.h>
#include <string.h>

#include "CGame.hpp"
#include "Log.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkStruct_020107A8.hpp"
#include "constants/scene.hpp"
#include "field/CFieldPokeMove.hpp"
#include "field/FieldPartnerIndex.hpp"

struct FieldNpcData {
    u16 unk_00;
    s8 unk_02;
    s8 unk_03;
};

extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;
extern MATHRandContext16 MAIN_BSS_0210CEC8;

extern "C" {
void LogInfo(const char *fmt, ...);
FieldNpcData *sub_02041D44(UnkClass_02041C80 *obj, int kind);
FieldEnemyData *sub_02041D58(UnkClass_02041C80 *obj, int kind);
}

UnkClass_020B26A0 MAIN_BSS_020B26A0;

static inline void CopyEntry(UnkStruct_020155FC *dst, UnkStruct_020155FC *src)
{
    *dst = *src;
    dst->unk_08 = 0;
    dst->unk_08 |= src->unk_08;
}

static inline int GetIdKind(u32 id)
{
    return ((int)id >> 24) & 0xFF;
}

static inline int GetIdMap(u32 id)
{
    return ((int)id >> 12) & 0xFFF;
}

static inline int GetIdIndex(u32 id)
{
    return id & 0xFFF;
}

static inline int GetEntryGroup(int area)
{
    int group;
    switch (area) {
    case 1:
        group = 1;
        break;
    case 5:
        group = 2;
        break;
    default:
        group = 0;
        break;
    }
    return group;
}

extern "C" void sub_020150B8(UnkStruct_020155FC *entry)
{
    entry->unk_08 = 0;
    entry->unk_00 = 0;
    entry->unk_02 = 0;
    entry->unk_04 = 0;
    Point2D pos = { 0, 0 };
    entry->unk_0C.x = pos.x;
    entry->unk_0C.y = pos.y;
    entry->unk_14 = 0;
}

UnkStruct_020155FC::UnkStruct_020155FC()
{
    sub_020150B8(this);
}

UnkStruct_020155FC::~UnkStruct_020155FC()
{
}

UnkStruct_020B26A0_8AD4::UnkStruct_020B26A0_8AD4()
{
    sub_02015124(this);
}

UnkStruct_020B26A0_8AD4::~UnkStruct_020B26A0_8AD4()
{
}

extern "C" void sub_02015124(UnkStruct_020B26A0_8AD4 *partner)
{
    partner->unk_00 = 0;
    partner->unk_04 = 0;
    partner->unk_08 = 0;
    Point2D pos = { 0, 0 };
    partner->unk_0C.x = pos.x;
    partner->unk_0C.y = pos.y;
    partner->unk_0A = 0;
    sub_0201518C(partner);
}

extern "C" void sub_02015164(UnkStruct_020B26A0_8AD4 *partner, const char *name)
{
    if (name != NULL && name[0] != '\0') {
        strcpy(partner->unk_14, name);
    } else {
        sub_0201518C(partner);
    }
}

extern "C" void sub_0201518C(UnkStruct_020B26A0_8AD4 *partner)
{
    partner->unk_14[0] = '\0';
}

extern "C" void sub_02015198(UnkClass_020B26A0 *save)
{
    MI_CpuFill8(save, 0, 0x8804);
    MIi_CpuClearFast(0xFFFFFFFF, save->unk_7EB0, sizeof(save->unk_7EB0));
    save->unk_8B44[0] = '\0';
    save->unk_8B64 = 0;
    save->unk_001A = 0x3B;
    save->unk_001C = 0x60F;
    save->unk_001E = 0x42E;
    save->unk_0024 = 0x4000;
    save->unk_0000 = 0;
    save->unk_0003 &= 0xF0;
    save->unk_0003 &= 0x0F;
    save->unk_8802 = 0;
    save->unk_7C38 = 0;
    sub_020160B8(save, 1);
    save->unk_0001 = save->unk_0002;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            sub_020150B8(&save->unk_8804[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        save->unk_8AD4[i].unk_00 = 0;
    }

    save->unk_8B68 = 0;
    save->unk_8B6C = 0;
    save->unk_8B70 = 1;
    save->unk_8B74 = 0;
    save->unk_87C8 = 0;
    save->unk_81AC = 0;
    save->unk_8BC0 = 0;
    sub_02017E44(save);
    sub_0201772C(save);
}

UnkClass_020B26A0::UnkClass_020B26A0()
{
    sub_02015198(this);
    unk_59A00 = 0;
    unk_8B84.day = 0;
    unk_8B84.month = 0;
}

UnkClass_020B26A0::~UnkClass_020B26A0()
{
}

extern "C" BOOL sub_02015434(UnkClass_020B26A0 *save, int mapId, int idx)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            UnkStruct_020155FC *entry = &save->unk_8804[i][j];
            if ((entry->unk_08 & 1) && mapId == entry->unk_02 && idx == entry->unk_04) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

extern "C" UnkStruct_020B26A0_8AD4 *sub_0201549C(UnkClass_020B26A0 *save, u32 id)
{
    u32 kind = GetIdKind(id);
    if (kind == 5 || kind == 2) {
        for (int i = 0; i < 2; i++) {
            if (save->unk_8AD4[i].unk_00 != 0 && GetIdMap(save->unk_8AD4[i].unk_04) == GetIdMap(id)
                && GetIdIndex(save->unk_8AD4[i].unk_04) == GetIdIndex(id)) {
                return &save->unk_8AD4[i];
            }
        }
    }
    return NULL;
}

extern "C" UnkStruct_020155FC *sub_02015520(UnkClass_020B26A0 *save, u32 id)
{
    u32 kind = GetIdKind(id);
    if (kind == 6 || kind == 1) {
        int group = GetEntryGroup(save->unk_8B64);
        for (int i = 0; i < 3; i++) {
            int g = (group + i) & 3;
            for (int j = 0; j < 10; j++) {
                if ((save->unk_8804[g][j].unk_08 & 1) && save->unk_8804[g][j].unk_02 == GetIdMap(id)
                    && save->unk_8804[g][j].unk_04 == GetIdIndex(id)) {
                    return &save->unk_8804[g][j];
                }
            }
        }
    }
    return NULL;
}

extern "C" UnkStruct_020155FC *sub_020155FC(UnkClass_020B26A0 *save, int idx)
{
    if (idx < 10) {
        return &save->unk_8804[GetEntryGroup(save->unk_8B64)][idx];
    }
    return NULL;
}

u8 DAT_0208b664[11] = { 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };

extern "C" int sub_02015658(UnkClass_020B26A0 *save, u32 level)
{
    if (level >= 11) {
        level = save->unk_0003 & 0xF;
    }
    u8 value = DAT_0208b664[level];
    if (sub_0201621C(save, -1)) {
        value++;
    }
    return value;
}

extern "C" BOOL sub_02015690(UnkClass_020B26A0 *save, int idx, int mapId)
{
    if (mapId < 0) {
        mapId = save->unk_001A;
    }
    switch (save->GetUnk0030State(mapId, idx)) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
    case 4:
        return TRUE;
    }
    return FALSE;
}

static inline void SetUnk0030State(UnkClass_020B26A0 *save, int mapId, int i, u8 state)
{
    if (mapId < 0) {
        mapId = save->unk_001A;
    }
    if (mapId < MAP_COUNT && i < 48) {
        int shift = (i & 7) * 4;
        save->unk_0030[mapId][i / 8] &= ~(0xF << shift);
        save->unk_0030[mapId][i / 8] |= (state & 0xF) << shift;
    }
}

extern "C" void sub_02015714(UnkClass_020B26A0 *save, int idx, int mapId)
{
    if (mapId < 0) {
        mapId = save->unk_001A;
    }
    SetUnk0030State(save, mapId, idx, 3);
}

extern "C" void sub_0201577C(UnkClass_020B26A0 *save, int idx, int mapId)
{
    if (mapId < 0) {
        mapId = save->unk_001A;
    }
    SetUnk0030State(save, mapId, idx, 1);
}

static inline u32 GetActorState(UnkClass_020B26A0 *save, int kind, int mapId, int i)
{
    if (((kind - 1 < 3) & (mapId < MAP_COUNT)) && i < 48) {
        return (((u32(*)[MAP_COUNT][4])save->unk_2988)[kind - 1][mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
    }
    return 0;
}

static inline void SetActorState(UnkClass_020B26A0 *save, int kind, int mapId, int i, u8 state)
{
    if (((kind - 1 < 3) & (mapId < MAP_COUNT)) && i < 48) {
        int shift = (i & 7) * 4;
        ((u32(*)[MAP_COUNT][4])save->unk_2988)[kind - 1][mapId][i / 8] &= ~(0xF << shift);
        ((u32(*)[MAP_COUNT][4])save->unk_2988)[kind - 1][mapId][i / 8] |= (state & 0xF) << shift;
    }
}

extern "C" BOOL sub_020157E4(UnkClass_020B26A0 *save, u32 id)
{
    int kind = GetIdKind(id);
    switch (kind) {
    case 0:
        return TRUE;
    case 1:
    case 2:
    case 3: {
        switch (GetActorState(save, kind, GetIdMap(id), GetIdIndex(id))) {
        case 3:
        case 4:
            return TRUE;
        }
        break;
    }
    case 4:
    default:
        break;
    }
    return FALSE;
}

extern "C" void sub_020158BC(UnkClass_020B26A0 *save, u32 id)
{
    int kind = GetIdKind(id);
    switch (kind) {
    case 1:
    case 2:
    case 3:
        SetActorState(save, kind, GetIdMap(id), GetIdIndex(id), 3);
        break;
    case 4:
        return;
    }
}

extern "C" void sub_0201597C(UnkClass_020B26A0 *save, u32 id)
{
    int kind = GetIdKind(id);
    switch (kind) {
    case 1:
    case 2:
    case 3:
        SetActorState(save, kind, GetIdMap(id), GetIdIndex(id), 1);
        break;
    case 4:
        return;
    }
}

extern "C" void sub_02015A3C(UnkClass_020B26A0 *save, int idx, int mapId)
{
    save->SetEnemyState(mapId, idx, 3);
}

extern "C" void sub_02015AAC(UnkClass_020B26A0 *save, int idx, int mapId)
{
    save->SetEnemyState(mapId, idx, 1);
}

extern "C" BOOL sub_02015B1C(UnkClass_020B26A0 *save, int idx, int mapId)
{
    switch (save->GetNpcState(mapId, idx)) {
    case 3:
    case 4:
        return TRUE;
    }
    return FALSE;
}

extern "C" void sub_02015B98(UnkClass_020B26A0 *save, int idx, int mapId)
{
    save->SetNpcState(mapId, idx, 3);
}

extern "C" void sub_02015C08(UnkClass_020B26A0 *save, int idx, int mapId)
{
    save->SetNpcState(mapId, idx, 1);
}

extern "C" BOOL sub_02015C78(UnkClass_020B26A0 *save, u32 id, int kind, int area)
{
    if ((((int)id >> 24) & 0xFF) != 1) {
        return FALSE;
    }
    if (area < 0) {
        area = save->unk_8B64;
    }
    int group = GetEntryGroup(area);

    UnkStruct_020155FC *entry = save->unk_8804[group];
    for (int i = 0; i < 10; i++, entry++) {
        if (!(entry->unk_08 & 1)) {
            sub_020150B8(entry);
            entry->unk_08 |= 1;
            entry->unk_00 = kind;
            entry->unk_02 = ((int)id >> 12) & 0xFFF;
            entry->unk_04 = id & 0xFFF;
            entry->unk_16 = save->unk_0026;
            if (sub_02034F9C((u16)kind)) {
                entry->unk_08 |= 6;
                if (i > 0) {
                    UnkStruct_020155FC tmp[9];
                    MI_CpuCopy8(save->unk_8804[group], tmp, i * sizeof(UnkStruct_020155FC));
                    *(UnkStruct_020155FC_Data *)&save->unk_8804[group][0] = *(UnkStruct_020155FC_Data *)entry;
                    save->unk_8804[group][0].unk_08 = 0;
                    save->unk_8804[group][0].unk_08 |= ((UnkStruct_020155FC_Data *)entry)->unk_08;
                    MI_CpuCopy8(tmp, &save->unk_8804[group][1], i * sizeof(UnkStruct_020155FC));
                }
            }
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" BOOL sub_02015E54(UnkClass_020B26A0 *save, u32 id)
{
    u32 kind = GetIdKind(id);
    if (kind == 5 || kind == 2) {
        for (int i = 0; i < 2; i++) {
            UnkStruct_020B26A0_8AD4 *partner = save->GetPartner(i);
            if (partner != NULL && partner->unk_00 != 0 && id == partner->unk_04) {
                partner->unk_00 = 0;
            }
        }
    } else if (kind == 6 || kind == 1) {
        int group = -1;
        int index = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (save->unk_8804[i][j].unk_02 == GetIdMap(id) && save->unk_8804[i][j].unk_04 == GetIdIndex(id)) {
                    group = i;
                    index = j;
                    break;
                }
            }
            if (group >= 0) {
                break;
            }
        }
        if (index == 9) {
            sub_020150B8(&save->unk_8804[group][9]);
        } else if (index >= 0 && index < 9) {
            for (; index < 9; index++) {
                UnkStruct_020155FC *dst = &save->unk_8804[group][index];
                UnkStruct_020155FC *src = &save->unk_8804[group][index + 1];
                sub_020150B8(dst);
                if (src->unk_08 & 1) {
                    CopyEntry(dst, src);
                }
                sub_020150B8(src);
            }
        }
    }
    return TRUE;
}

extern "C" void sub_02016024(UnkClass_020B26A0 *save)
{
    save->unk_7F60 &= ~1;
    MIi_CpuClearFast(0, save->unk_7F6C, sizeof(save->unk_7F6C));
    MIi_CpuClearFast(0, save->unk_7FEC, sizeof(save->unk_7FEC));
    MIi_CpuClearFast(0, save->unk_806C, sizeof(save->unk_806C));
    MIi_CpuClearFast(0, save->unk_80EC, sizeof(save->unk_80EC));
    MIi_CpuClearFast(0, save->unk_812C, sizeof(save->unk_812C));
    MIi_CpuClearFast(0, save->unk_816C, sizeof(save->unk_816C));
}

extern "C" void sub_020160B8(UnkClass_020B26A0 *save, u32 arg1)
{
    if (save->unk_87DB == arg1) {
        return;
    }
    save->unk_87DB = arg1;
    save->unk_0002 = CGame::GetInstance() == NULL ? 0 : sub_02010E78(CGame::GetInstance()->unk_1438, arg1);
    int level = sub_02016C14(save, 0x15);
    if (level == 1) {
        save->unk_0002 += 5;
    } else if (level >= 2) {
        save->unk_0002 += 15;
    }
}

extern "C" int sub_02016138(UnkClass_020B26A0 *save, int group)
{
    if (group < 0 || group >= 3) {
        group = GetEntryGroup(save->unk_8B64);
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (save->unk_8804[group][i].unk_08 & 1) {
            count++;
        }
    }
    return count;
}

extern "C" int sub_020161AC(UnkClass_020B26A0 *save, u32 level, int group)
{
    int value = sub_02015658(save, level);
    if (sub_0201621C(save, group)) {
        value--;
    }
    if (value < 0) {
        value = 0;
    }
    return value;
}

extern "C" int sub_020161E4(UnkClass_020B26A0 *save, int group)
{
    int count = sub_02016138(save, group);
    if (sub_0201621C(save, group)) {
        count--;
    }
    if (count < 0) {
        count = 0;
    }
    return count;
}

extern "C" BOOL sub_0201621C(UnkClass_020B26A0 *save, int group)
{
    int count = sub_02016138(save, group);
    for (int i = 0; i < count; i++) {
        if (sub_020155FC(save, i)->unk_08 & 2) {
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" int sub_02016268(UnkClass_020B26A0 *save, int group)
{
    int count = sub_02016138(save, group);
    for (int i = 0; i < count; i++) {
        UnkStruct_020155FC *entry = sub_020155FC(save, i);
        if (entry->unk_08 & 2) {
            return sub_02035088(entry->unk_00);
        }
    }
    return -1;
}

extern "C" void sub_020162BC(UnkClass_020B26A0 *save, u32 id)
{
    UnkStruct_020155FC *entry = sub_02015520(save, save->unk_7C38);
    if (entry != NULL) {
        entry->unk_08 &= ~4;
    }
    save->unk_7C38 = id;
    entry = sub_02015520(save, id);
    if (entry != NULL) {
        entry->unk_08 |= 4;
    }
}

void UnkClass_020B26A0::sub_0201630C(RTCTime *time, RTCDate *date)
{
    CGame *game = CGame::GetInstance();
    u32 currSceneId = game->currentScene->getSceneId();

    if (currSceneId == SCENE_RANGER_NET_1 || currSceneId == SCENE_TITLE) {
        return;
    }

    if (unk_8B84.day == 0 || unk_8B84.month == 0) {
        return;
    }

    if (time == NULL) {
        RTCTime currTime;
        RTC_GetTime(&currTime);
        time = &currTime;
    }

    if (date == NULL) {
        RTCDate currDate;
        RTC_GetDate(&currDate);
        date = &currDate;
    }

    s32 year = date->year - unk_8B84.year;
    s32 month = date->month - unk_8B84.month;
    s32 day = date->day - unk_8B84.day;
    s32 hour = time->hour - unk_8B94.hour;
    s32 minute = time->minute - unk_8B94.minute;
    s32 second = time->second - unk_8B94.second;

    while (second < 0) {
        --minute;
        second += 60;
    }

    while (second >= 60) {
        ++minute;
        second -= 60;
    }

    while (minute < 0) {
        --hour;
        minute += 60;
    }

    if (minute >= 60) {
        ++hour;
        minute -= 60;
    }

    if (year > 0) {
        month += year * 12;
    }

    if (month > 0) {
        s32 storedYear = unk_8B84.year;
        s32 i = 0;

        if (month > 0) {
            do {
                u32 v3 = (((unk_8B84.month - 1 + i) % 12) + 1);

                switch (v3) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    day += 31;
                    break;

                case 4:
                case 6:
                case 9:
                case 11:
                    day += 30;
                    break;

                case 2:
                    if (storedYear % 400 == 0) {
                        day += 29;
                    } else if (storedYear % 100 == 0) {
                        day += 28;
                    } else if (storedYear % 4 == 0) {
                        day += 29;
                    } else {
                        day += 28;
                    }

                    break;

                default:
                    break;
                }

                ++i;

                if (v3 == 12) {
                    ++storedYear;
                }
            } while (i < month);
        }
    }

    unk_87D4 += day * 24 + hour;
    unk_87D8 += minute;
    unk_87D9 += second;

    while (unk_87D9 >= 60) {
        ++unk_87D8;
        unk_87D9 -= 60;
    }

    while (unk_87D8 >= 60) {
        ++unk_87D4;
        unk_87D8 -= 60;
    }

    if (unk_87D4 >= 100) {
        unk_87DA = 1;
    }

    unk_8B94.hour = time->hour;
    unk_8B94.minute = time->minute;
    unk_8B94.second = time->second;
    unk_8B84.year = date->year;
    unk_8B84.month = date->month;
    unk_8B84.day = date->day;
    unk_8B84.week = date->week;
}

extern "C" void sub_020167B4(UnkClass_020B26A0 *save);

extern "C" void sub_0201668C(UnkClass_020B26A0 *save)
{
    RTCTime time;
    RTCDate date;
    RTC_GetTime(&time);
    RTC_GetDate(&date);
    save->sub_0201630C(&time, &date);

    int hours = save->unk_87D4 - save->unk_87CC;
    int minutes = save->unk_87D8 - save->unk_87D0;
    if (hours > 0) {
        minutes += hours * 60;
    } else if (hours < 0) {
        u32 wrap = 0xFFFFFFFF - save->unk_87D4;
        if (wrap < 2) {
            minutes += wrap * 60;
        } else {
            minutes += 120;
        }
    }

    LogInfo("************");
    LogInfo("LotTimeCheck");
    LogInfo("PlayTime %d:%d", save->unk_87D4, save->unk_87D8);
    LogInfo("LastTime %d:%d", save->unk_87CC, save->unk_87D0);
    LogInfo("DivTime %d", minutes);
    LogInfo("************");

    if (minutes < 30) {
        return;
    }
    save->unk_87CC = save->unk_87D4;
    save->unk_87D0 = save->unk_87D8;
    sub_020167B4(save);
}

extern "C" void LogInfo(const char *fmt, ...)
{
    // va_start without MSL's alignment of the parameter address
    va_list args = (va_list)(&fmt + 1);
    thunk_FUN_020442cc(fmt, args);
}

extern "C" void sub_020167B4(UnkClass_020B26A0 *save)
{
    LogInfo("/*********************");
    LogInfo("LotGokigenParameter()");

    int free[17];
    for (int i = 0; i < 17; i++) {
        free[i] = TRUE;
    }

    int remaining = 17;
    const char *names[17] = {
        "GONBE",
        "HIKOZARU",
        "POCHAMA",
        "NAETLE",
        "PACHIRISU",
        "YUKIKABURI",
        "WANRIKY",
        "GUREGGRU",
        "HIPPOPOTAS",
        "MUKKURU",
        "MANENE",
        "KOROBOHSHI",
        "ZUGAIDOS",
        "MUMA",
        "FUKAMARU",
        "NYULA",
        "TATETOPSU",
    };

    int count = 0;
    int bit = 1;
    for (int i = 0; bit <= 0x10000; i++, bit = 1 << i) {
        if (save->unk_87C8 & bit) {
            LogInfo("%s", names[i]);
            count++;
        } else {
            free[i] = FALSE;
            remaining--;
        }
    }
    LogInfo("GetpartnerNum= %d", count);

    int veryGood = 0;
    int good = 0;
    int normal;
    int probability;
    int probability2;
    if (count == 0) {
        LogInfo("*********************/");
        return;
    }
    if (count < 4) {
        normal = 1;
        probability = 10;
        probability2 = 20;
    } else if (count < 10) {
        normal = 2;
        good = 1;
        probability = 10;
        probability2 = 10;
    } else {
        normal = 5;
        veryGood = 1;
        // fake: orders the two constant moves like the original (good = 2)
        good = veryGood + 1;
        probability = 5;
        probability2 = 10;
    }

    for (int k = 0; k < 17; k++) {
        if (veryGood <= 0) {
            break;
        }
        u16 pick = MATH_Rand16(&MAIN_BSS_0210CEC8, remaining);
        int n = 0;
        for (int i = 0; i < 17; i++) {
            if (free[i] == TRUE) {
                if (n == pick) {
                    LogInfo("SetVeryGood= %s", names[i]);
                    save->unk_0009[i] = 2;
                    free[i] = FALSE;
                    remaining--;
                    veryGood--;
                    break;
                }
                n++;
            }
        }
    }
    for (int k = 0; k < 17; k++) {
        if (good <= 0) {
            break;
        }
        u16 pick = MATH_Rand16(&MAIN_BSS_0210CEC8, remaining);
        int n = 0;
        for (int i = 0; i < 17; i++) {
            if (free[i] == TRUE) {
                if (n == pick) {
                    LogInfo("SetGood= %s", names[i]);
                    save->unk_0009[i] = 1;
                    free[i] = FALSE;
                    remaining--;
                    good--;
                    break;
                }
                n++;
            }
        }
    }
    for (int k = 0; k < 17; k++) {
        if (normal <= 0) {
            break;
        }
        u16 pick = MATH_Rand16(&MAIN_BSS_0210CEC8, remaining);
        int n = 0;
        for (int i = 0; i < 17; i++) {
            if (free[i] == TRUE) {
                if (n == pick) {
                    LogInfo("SetNormal= %s", names[i]);
                    save->unk_0009[i] = 0;
                    free[i] = FALSE;
                    remaining--;
                    normal--;
                    break;
                }
                n++;
            }
        }
    }

    LogInfo("Probability= %d", probability);
    LogInfo("Probability2= %d", probability2);

    for (int i = 0; i < 17; i++) {
        if (free[i]) {
            if (MATH_Rand16(&MAIN_BSS_0210CEC8, 100) < probability) {
                LogInfo("SetVeryGood= %s", names[i]);
                free[i] = FALSE;
                save->unk_0009[i] = 2;
                remaining--;
            } else if (MATH_Rand16(&MAIN_BSS_0210CEC8, 100) < probability2) {
                LogInfo("SetGood= %s", names[i]);
                free[i] = FALSE;
                save->unk_0009[i] = 1;
                remaining--;
            } else {
                LogInfo("SetNormal= %s", names[i]);
                free[i] = FALSE;
                save->unk_0009[i] = 0;
                remaining--;
            }
        }
    }
    LogInfo("*********************/");
}

extern "C" int sub_02016C14(UnkClass_020B26A0 *save, int idx)
{
    if (idx >= 26) {
        return 0;
    }
    return (save->unk_87DC[idx >> 2] >> ((idx & 3) * 2)) & 3;
}

extern "C" void sub_02016C40(UnkClass_020B26A0 *save, int idx, int level)
{
    if (idx >= 26) {
        return;
    }
    if (level < 0 || level >= 4) {
        return;
    }
    int shift = (idx & 3) * 2;
    u8 bits = save->unk_87DC[idx >> 2];
    bits &= ~(3 << shift);
    bits |= level << shift;
    save->unk_87DC[idx >> 2] = bits;
    if (idx != 21) {
        return;
    }
    save->unk_0002 = CGame::GetInstance() == NULL ? 0 : sub_02010E78(CGame::GetInstance()->unk_1438, save->unk_87DB);
    if (level == 1) {
        save->unk_0002 += 5;
    } else if (level >= 2) {
        save->unk_0002 += 15;
    }
}

extern "C" int sub_02016CF0(UnkClass_020B26A0 *save, int idx)
{
    if (idx >= 26) {
        return 0;
    }
    int table[4] = { 0, 3, 6, 7 };
    return table[(save->unk_87DC[idx >> 2] >> ((idx & 3) * 2)) & 3];
}

extern "C" void sub_02016D4C(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_002C = value;
    if (value > 9999999) {
        save->unk_002C = 9999999;
    }
}

extern "C" u32 sub_02016D64(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_002C += value;
    if (save->unk_002C > 9999999) {
        save->unk_002C = 9999999;
    }
    return save->unk_002C;
}

extern "C" void sub_02016D88(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8758 = value;
    if (value > 9999999) {
        save->unk_8758 = 9999999;
    }
}

extern "C" u32 sub_02016DA4(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8758 += value;
    if (save->unk_8758 > 9999999) {
        save->unk_8758 = 9999999;
    }
    return save->unk_8758;
}

extern "C" void sub_02016DD0(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_875C = value;
    if (value > 99999) {
        save->unk_875C = 99999;
    }
}

extern "C" u32 sub_02016DEC(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_875C += value;
    if (save->unk_875C > 99999) {
        save->unk_875C = 99999;
    }
    return save->unk_875C;
}

extern "C" void sub_02016E18(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8760 = value;
    if (value > 99999) {
        save->unk_8760 = 99999;
    }
}

extern "C" u32 sub_02016E34(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8760 += value;
    if (save->unk_8760 > 99999) {
        save->unk_8760 = 99999;
    }
    return save->unk_8760;
}

extern "C" void sub_02016E60(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8764 = value;
    if (value > 99999) {
        save->unk_8764 = 99999;
    }
}

extern "C" u32 sub_02016E7C(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8764 += value;
    if (save->unk_8764 > 99999) {
        save->unk_8764 = 99999;
    }
    return save->unk_8764;
}

extern "C" void sub_02016EA8(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8768 = value;
    if (value > 99999) {
        save->unk_8768 = 99999;
    }
}

extern "C" u32 sub_02016EC4(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_8768 += value;
    if (save->unk_8768 > 99999) {
        save->unk_8768 = 99999;
    }
    return save->unk_8768;
}

extern "C" void sub_02016EF0(UnkClass_020B26A0 *save, int idx, u32 value)
{
    if (idx >= 17) {
        return;
    }
    save->unk_876C[idx] = value;
    if (save->unk_876C[idx] > 9999999) {
        save->unk_876C[idx] = 9999999;
    }
}

extern "C" u32 sub_02016F18(UnkClass_020B26A0 *save, int kind, u32 value)
{
    int idx = sub_02035088(kind);
    if (idx < 17) {
        save->unk_876C[idx] += value;
        if (save->unk_876C[idx] > 9999999) {
            save->unk_876C[idx] = 9999999;
        }
        return save->unk_876C[idx];
    }
    return 0;
}

extern "C" u16 sub_02016F7C(UnkClass_020B26A0 *save)
{
    int best = -1;
    for (int i = 0; i < 17; i++) {
        if (best < 0) {
            if ((save->unk_87C8 & (1 << i)) && save->unk_876C[i] != 0) {
                best = i;
            }
        } else if (save->unk_876C[best] < save->unk_876C[i]) {
            best = i;
        }
    }
    if (best < 0) {
        return 0;
    }
    int kind = sub_02035240(best);
    return sub_020107A8(CGame::GetInstance()->unk_1434, kind)->unk_00;
}

extern "C" void sub_02017020(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_87B0 = value;
    if (value > 0xDDF220) {
        save->unk_87B0 = 0xDDF220;
    }
}

extern "C" u32 sub_0201703C(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_87B0 += value;
    if (save->unk_87B0 > 0xDDF220) {
        save->unk_87B0 = 0xDDF220;
    }
    return save->unk_87B0;
}

extern "C" void sub_02017068(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_87B4 = value;
    if (value > 999999) {
        save->unk_87B4 = 999999;
    }
}

extern "C" u32 sub_02017084(UnkClass_020B26A0 *save, u32 value)
{
    save->unk_87B4 += value;
    if (save->unk_87B4 > 999999) {
        save->unk_87B4 = 999999;
    }
    return save->unk_87B4;
}

extern "C" void sub_020170B0(UnkClass_020B26A0 *save, u16 value)
{
    save->unk_87B8 = value;
    if (save->unk_87B8 > 9999) {
        save->unk_87B8 = 9999;
    }
}

extern "C" u16 sub_020170D0(UnkClass_020B26A0 *save, u16 value)
{
    save->unk_87B8 += value;
    if (save->unk_87B8 > 9999) {
        save->unk_87B8 = 9999;
    }
    return save->unk_87B8;
}

extern "C" void sub_02017100(UnkClass_020B26A0 *save, u16 value)
{
    save->unk_87BA = value;
    if (save->unk_87BA > 9999) {
        save->unk_87BA = 9999;
    }
}

extern "C" u16 sub_02017120(UnkClass_020B26A0 *save, u16 value)
{
    save->unk_87BA += value;
    if (save->unk_87BA > 9999) {
        save->unk_87BA = 9999;
    }
    return save->unk_87BA;
}

extern "C" void sub_02017150(UnkClass_020B26A0 *save, u16 value)
{
    save->unk_87BC = value;
    if (save->unk_87BC > 9999) {
        save->unk_87BC = 9999;
    }
}

extern "C" u16 sub_02017170(UnkClass_020B26A0 *save, u16 value)
{
    save->unk_87BC += value;
    if (save->unk_87BC > 9999) {
        save->unk_87BC = 9999;
    }
    return save->unk_87BC;
}

class UnkClass_0201164C;
extern UnkClass_0201164C MAIN_BSS_020B2638;
extern "C" int sub_02011678(UnkClass_0201164C *obj);

extern "C" u8 sub_020171A0(void)
{
    return sub_02011678(&MAIN_BSS_020B2638);
}

extern "C" void sub_020171B8(UnkClass_020B26A0 *save)
{
    for (int i = 0; i < 10; i++) {
        sub_020150B8(&save->unk_8804[2][i]);
    }
    for (int i = 0; i < 10; i++) {
        if ((save->unk_8804[0][i].unk_08 & 1) && (save->unk_8804[0][i].unk_08 & 2)) {
            *(UnkStruct_020155FC_Data *)&save->unk_8804[2][i] = *(UnkStruct_020155FC_Data *)&save->unk_8804[0][i];
            save->unk_8804[2][i].unk_08 = 0;
            save->unk_8804[2][i].unk_08 |= ((UnkStruct_020155FC_Data *)&save->unk_8804[0][i])->unk_08;
            return;
        }
    }
}

u32 DAT_0208b5c0 = 0x1F2E3D4C;

extern "C" BOOL sub_02017298(void)
{
    return DAT_0208b5c0 == 0x1F2E3D4C;
}

extern "C" void sub_020172BC(void)
{
    DAT_0208b5c0 = 0x1F2E3D4C;
}

extern "C" void sub_020172D4(UnkClass_020B26A0 *save)
{
    save->unk_8BC4.unk_00 = save->unk_0001;
    save->unk_8BC4.unk_01 = save->unk_0002;
    save->unk_8BC4.unk_02 = save->unk_87DB;
    MI_CpuCopy8(save->unk_87DC, save->unk_8BC4.unk_03, sizeof(save->unk_8BC4.unk_03));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            save->unk_8BC4.unk_0C[i][j] = *(UnkStruct_020155FC_Data *)&save->unk_8804[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        save->unk_8BC4.unk_2DC[i] = *(UnkStruct_020B26A0_8AD4_Data *)&save->unk_8AD4[i];
    }
    save->unk_8BC4.unk_34C = save->unk_0004;
    save->unk_8BC4.unk_350 = save->unk_0008;
    for (int i = 0; i < 17; i++) {
        save->unk_8BC4.unk_351[i] = save->unk_0009[i];
    }

    sub_020160B8(save, 1);
    save->unk_0001 = save->unk_0002;
    MI_CpuFill8(save->unk_87DC, 0, sizeof(save->unk_87DC));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (!(save->unk_8804[i][j].unk_08 & 1) || !(save->unk_8804[i][j].unk_08 & 2)) {
                sub_020150B8(&save->unk_8804[i][j]);
            }
        }
    }
    save->unk_0004 = 0;
    for (int i = 0; i < 17; i++) {
        save->unk_0009[i] = 0;
    }
}

extern "C" void sub_02017520(UnkClass_020B26A0 *save)
{
    save->unk_0001 = save->unk_8BC4.unk_00;
    save->unk_0002 = save->unk_8BC4.unk_01;
    save->unk_87DB = save->unk_8BC4.unk_02;
    MI_CpuCopy8(save->unk_8BC4.unk_03, save->unk_87DC, sizeof(save->unk_87DC));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            *(UnkStruct_020155FC_Data *)&save->unk_8804[i][j] = save->unk_8BC4.unk_0C[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        *(UnkStruct_020B26A0_8AD4_Data *)&save->unk_8AD4[i] = save->unk_8BC4.unk_2DC[i];
    }
    save->unk_0004 = save->unk_8BC4.unk_34C;
    save->unk_0008 = save->unk_8BC4.unk_350;
    for (int i = 0; i < 17; i++) {
        save->unk_0009[i] = save->unk_8BC4.unk_351[i];
    }
}

extern "C" CFieldDrawActorData *sub_020176BC(UnkClass_020B26A0 *save, int id)
{
    if (id < 0) {
        id = (save->unk_0000 & 1) + ((u8)((save->unk_0003 >> 4) & 0xF) == 0 ? 1 : 3);
    }
    save->unk_8F28.sub_02041344(id, 0, 0x1FFFFFFE, NULL, TRUE, FALSE);
    return &save->unk_8F28;
}

extern "C" void sub_0201772C(UnkClass_020B26A0 *save)
{
    save->unk_8F28.Release();
}

extern "C" u32 sub_02017E5C(UnkClass_020B26A0 *save);
extern "C" u32 sub_02017F78(UnkClass_020B26A0 *save);
extern "C" void sub_0201808C(UnkClass_020B26A0 *save);
extern "C" void sub_020180C0(UnkClass_020B26A0 *save);

extern "C" CFieldDrawActorData *sub_02017748(UnkClass_020B26A0 *save, u16 id, int form, u16 mask, BOOL reload)
{
    for (int i = 0; i < 2; i++) {
        if (save->unk_59760[i].unk_34 != 0 && id == save->unk_59760[i].unk_1C && form == save->unk_59760[i].unk_1E) {
            return &save->unk_59760[i];
        }
    }
    if (reload) {
        sub_02017E5C(save);
        save->unk_59A00 = 1;
    }
    for (int i = 0; i < 2; i++) {
        if (save->unk_59760[i].unk_34 == 0) {
            save->unk_59760[i].sub_02041230(1, id, form, mask);
            return &save->unk_59760[i];
        }
    }
    return NULL;
}

extern "C" CFieldDrawActorData *sub_02017848(UnkClass_020B26A0 *save, u16 id, int form, u16 mask, BOOL reload)
{
    for (int i = 0; i < 10; i++) {
        if (save->unk_597D0[i].unk_34 != 0 && id == save->unk_597D0[i].unk_1C && form == save->unk_597D0[i].unk_1E) {
            return &save->unk_597D0[i];
        }
    }
    if (reload) {
        sub_02017F78(save);
        save->unk_59A00 = 1;
    }
    for (int i = 0; i < 10; i++) {
        if (save->unk_597D0[i].unk_34 == 0) {
            save->unk_597D0[i].sub_02041230(0, id, form, mask);
            return &save->unk_597D0[i];
        }
    }
    return NULL;
}

extern "C" void sub_02017948(UnkClass_020B26A0 *save, BOOL force)
{
    u32 partnerMask = 0;
    u32 entryMask = 0;
    int group = GetEntryGroup(save->unk_8B64);
    if (force) {
        save->unk_59A00 = 1;
    } else if (save->unk_59A00 != 0) {
        save->unk_59A00 = 0;
        force = TRUE;
    }

    if (!force) {
        UnkClass_02041C80 *table = MAIN_BSS_0210CA6C;
        if (table != NULL) {
            u32 used = 0;
            for (int i = 0; i < 2; i++) {
                UnkStruct_020B26A0_8AD4 *partner = save->GetPartner(i);
                if (partner != NULL && partner->unk_00 != 0) {
                    FieldNpcData *data = sub_02041D44(table, partner->unk_08);
                    partnerMask |= 1 << i;
                    for (int j = 0; j < 2; j++) {
                        if (save->unk_59760[j].unk_34 != 0 && data->unk_00 == save->unk_59760[j].unk_1C) {
                            used |= 1 << j;
                            partnerMask &= ~(1 << i);
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < 2; j++) {
                if (save->unk_59760[j].unk_34 != 0 && !(used & (1 << j))) {
                    force = TRUE;
                    break;
                }
            }
        }
    }

    if (!force) {
        CGame *game = CGame::GetInstance();
        if (game != NULL) {
            u32 used = 0;
            for (int i = 0; i < 10; i++) {
                UnkStruct_020155FC *entry = sub_020155FC(save, i);
                if (entry != NULL && (entry->unk_08 & 1)) {
                    UnkStruct_020107A8 *info = sub_020107A8(game->unk_1434, entry->unk_00);
                    entryMask |= 1 << i;
                    for (int j = 0; j < 10; j++) {
                        if (save->unk_597D0[j].unk_34 != 0 && info->unk_00 == save->unk_597D0[j].unk_1C
                            && info->unk_02 == save->unk_597D0[j].unk_1E) {
                            used |= 1 << j;
                            entryMask &= ~(1 << i);
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < 10; j++) {
                if (save->unk_597D0[j].unk_34 != 0 && !(used & (1 << j))) {
                    force = TRUE;
                    break;
                }
            }
        }
    }

    if (force) {
        sub_02017E44(save);
        UnkClass_02041C80 *table = MAIN_BSS_0210CA6C;
        if (table == NULL) {
            return;
        }
        if (group != 1) {
            for (int i = 0; i < 2; i++) {
                UnkStruct_020B26A0_8AD4 *partner = save->GetPartner(i);
                if (partner != NULL && partner->unk_00 != 0) {
                    FieldNpcData *data = sub_02041D44(table, partner->unk_08);
                    sub_02017748(save, data->unk_00, 0, 0x1E16, FALSE);
                }
            }
        }
        CGame *game = CGame::GetInstance();
        if (game == NULL) {
            return;
        }
        for (int i = 0; i < 10; i++) {
            UnkStruct_020155FC *entry = sub_020155FC(save, i);
            if (entry != NULL && (entry->unk_08 & 1)) {
                FieldEnemyData *enemy = sub_02041D58(table, entry->unk_00);
                u16 mask = 0xE;
                if (enemy->unk_30 == 2 || enemy->unk_30 == 5) {
                    mask |= 0xC00;
                }
                UnkStruct_020107A8 *info = sub_020107A8(game->unk_1434, entry->unk_00);
                sub_02017848(save, info->unk_00, info->unk_02, mask, FALSE);
            }
        }
    } else {
        UnkClass_02041C80 *table = MAIN_BSS_0210CA6C;
        if (table == NULL) {
            return;
        }
        if (group != 1) {
            for (int i = 0; i < 2; i++) {
                if (partnerMask & (1 << i)) {
                    FieldNpcData *data = sub_02041D44(table, save->GetPartner(i)->unk_08);
                    sub_02017748(save, data->unk_00, 0, 0x1E16, FALSE);
                }
            }
        }
        CGame *game = CGame::GetInstance();
        if (game == NULL) {
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (entryMask & (1 << i)) {
                UnkStruct_020155FC *entry = sub_020155FC(save, i);
                FieldEnemyData *enemy = sub_02041D58(table, entry->unk_00);
                u16 mask = 0xE;
                if (enemy->unk_30 == 2 || enemy->unk_30 == 5) {
                    mask |= 0xC00;
                }
                UnkStruct_020107A8 *info = sub_020107A8(game->unk_1434, entry->unk_00);
                sub_02017848(save, info->unk_00, info->unk_02, mask, FALSE);
            }
        }
    }
}

extern "C" void sub_02017E44(UnkClass_020B26A0 *save)
{
    sub_0201808C(save);
    sub_020180C0(save);
}

extern "C" u32 sub_02017E5C(UnkClass_020B26A0 *save)
{
    u32 used = 0;
    UnkClass_02041C80 *table = MAIN_BSS_0210CA6C;
    u32 missing = 0;
    if (table != NULL) {
        for (int i = 0; i < 2; i++) {
            UnkStruct_020B26A0_8AD4 *partner = save->GetPartner(i);
            if (partner != NULL && partner->unk_00 != 0) {
                FieldNpcData *data = sub_02041D44(table, partner->unk_08);
                missing |= 1 << i;
                for (int j = 0; j < 2; j++) {
                    if (save->unk_59760[j].unk_34 != 0 && data->unk_00 == save->unk_59760[j].unk_1C) {
                        used |= 1 << j;
                        missing &= ~(1 << i);
                    }
                }
            }
        }
        for (int j = 0; j < 2; j++) {
            if (save->unk_59760[j].unk_34 != 0 && !(used & (1 << j))) {
                save->unk_59760[j].Release();
            }
        }
    }
    return missing;
}

extern "C" u32 sub_02017F78(UnkClass_020B26A0 *save)
{
    CGame *game = CGame::GetInstance();
    u32 used = 0;
    u32 missing = 0;
    if (game != NULL) {
        for (int i = 0; i < 10; i++) {
            UnkStruct_020155FC *entry = sub_020155FC(save, i);
            if (entry != NULL && (entry->unk_08 & 1)) {
                UnkStruct_020107A8 *info = sub_020107A8(game->unk_1434, entry->unk_00);
                missing |= 1 << i;
                for (int j = 0; j < 10; j++) {
                    if (save->unk_597D0[j].unk_34 != 0 && info->unk_00 == save->unk_597D0[j].unk_1C
                        && info->unk_02 == save->unk_597D0[j].unk_1E) {
                        used |= 1 << j;
                        missing &= ~(1 << i);
                    }
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            if (save->unk_597D0[j].unk_34 != 0 && !(used & (1 << j))) {
                save->unk_597D0[j].Release();
            }
        }
    }
    return missing;
}

extern "C" void sub_0201808C(UnkClass_020B26A0 *save)
{
    for (int i = 0; i < 2; i++) {
        save->unk_59760[i].Release();
    }
}

extern "C" void sub_020180C0(UnkClass_020B26A0 *save)
{
    for (int i = 0; i < 10; i++) {
        save->unk_597D0[i].Release();
    }
}

extern "C" void sub_020180F4(UnkClass_020B26A0 *save)
{
    for (int i = 0; i < 2; i++) {
        save->unk_59760[i].CFieldDrawActorData::sub_02040E80();
    }
    for (int i = 0; i < 10; i++) {
        save->unk_597D0[i].CFieldDrawActorData::sub_02040E80();
    }
}

extern "C" void sub_02018148(UnkClass_020B26A0 *save, u32 hours, u8 minutes, u8 seconds)
{
    save->unk_87D4 = hours;
    save->unk_87D8 = minutes;
    save->unk_87D9 = seconds;
    while (save->unk_87D9 >= 60) {
        save->unk_87D8++;
        save->unk_87D9 -= 60;
    }
    while (save->unk_87D8 >= 60) {
        save->unk_87D4++;
        save->unk_87D8 -= 60;
    }
    if (save->unk_87D4 >= 100) {
        save->unk_87DA = TRUE;
    } else {
        save->unk_87DA = FALSE;
    }
    save->unk_87CC = hours;
    save->unk_87D0 = minutes;
}
