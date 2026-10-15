#include "SaveData.hpp"

#include <nitro.h>
#include <stdarg.h>
#include <string.h>

#include "CGame.hpp"
#include "FieldDataRecords.hpp"
#include "Log.hpp"
#include "PokeIdTableEntry.hpp"
#include "constants/scene.hpp"
#include "field/CFieldPokeMove.hpp"
#include "field/FieldPartnerIndex.hpp"

struct FieldNpcData {
    u16 unk_00;
    s8 unk_02;
    s8 unk_03;
};

extern FieldData *MAIN_BSS_0210CA6C;
extern MATHRandContext16 MAIN_BSS_0210CEC8;

extern "C" {
void LogInfo(const char *fmt, ...);
FieldNpcData *FieldData_GetNpc(FieldData *obj, int kind);
FieldEnemyData *FieldData_GetEnemy(FieldData *obj, int kind);
}

SaveData MAIN_BSS_020B26A0;

static inline void CopyEntry(PartyEntry *dst, PartyEntry *src)
{
    *dst = *src;
    dst->m_flags = 0;
    dst->m_flags |= src->m_flags;
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

extern "C" void SaveEntry_Clear(PartyEntry *entry)
{
    entry->m_flags = 0;
    entry->m_kind = 0;
    entry->m_mapId = 0;
    entry->m_index = 0;
    Point2D pos = { 0, 0 };
    entry->m_pos.x = pos.x;
    entry->m_pos.y = pos.y;
    entry->unk_14 = 0;
}

PartyEntry::PartyEntry()
{
    SaveEntry_Clear(this);
}

PartyEntry::~PartyEntry()
{
}

PartnerSlot::PartnerSlot()
{
    SavePartner_Clear(this);
}

PartnerSlot::~PartnerSlot()
{
}

extern "C" void SavePartner_Clear(PartnerSlot *partner)
{
    partner->unk_00 = 0;
    partner->unk_04 = 0;
    partner->unk_08 = 0;
    Point2D pos = { 0, 0 };
    partner->unk_0C.x = pos.x;
    partner->unk_0C.y = pos.y;
    partner->unk_0A = 0;
    SavePartner_ClearName(partner);
}

extern "C" void SavePartner_SetName(PartnerSlot *partner, const char *name)
{
    if (name != NULL && name[0] != '\0') {
        strcpy(partner->unk_14, name);
    } else {
        SavePartner_ClearName(partner);
    }
}

extern "C" void SavePartner_ClearName(PartnerSlot *partner)
{
    partner->unk_14[0] = '\0';
}

extern "C" void SaveData_Init(SaveData *save)
{
    MI_CpuFill8(save, 0, 0x8804);
    MIi_CpuClearFast(0xFFFFFFFF, save->unk_7EB0, sizeof(save->unk_7EB0));
    save->m_saveName[0] = '\0';
    save->m_areaType = 0;
    save->m_mapId = 0x3B;
    save->m_posX = 0x60F;
    save->m_posY = 0x42E;
    save->m_dir = 0x4000;
    save->m_sex = 0;
    save->m_rangerClassGrade &= 0xF0;
    save->m_rangerClassGrade &= 0x0F;
    save->unk_8802 = 0;
    save->m_selectedPartyId = 0;
    SaveData_SetStylerLevel(save, 1);
    save->m_energy = save->m_maxEnergy;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            SaveEntry_Clear(&save->m_party[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        save->m_partners[i].unk_00 = 0;
    }

    save->unk_8B68 = 0;
    save->unk_8B6C = 0;
    save->m_subScreenShowsMap = 1;
    save->unk_8B74 = 0;
    save->m_partnerFlags = 0;
    save->unk_81AC = 0;
    save->unk_8BC0 = 0;
    SaveData_ReleaseAllActorData(save);
    SaveData_ReleasePlayerActorData(save);
}

SaveData::SaveData()
{
    SaveData_Init(this);
    m_reloadPartyActorData = 0;
    m_lastDate.day = 0;
    m_lastDate.month = 0;
}

SaveData::~SaveData()
{
}

extern "C" BOOL SaveData_IsInParty(SaveData *save, int mapId, int idx)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            PartyEntry *entry = &save->m_party[i][j];
            if ((entry->m_flags & 1) && mapId == entry->m_mapId && idx == entry->m_index) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

extern "C" PartnerSlot *SaveData_FindPartner(SaveData *save, u32 id)
{
    u32 kind = GetIdKind(id);
    if (kind == 5 || kind == 2) {
        for (int i = 0; i < 2; i++) {
            if (save->m_partners[i].unk_00 != 0 && GetIdMap(save->m_partners[i].unk_04) == GetIdMap(id)
                && GetIdIndex(save->m_partners[i].unk_04) == GetIdIndex(id)) {
                return &save->m_partners[i];
            }
        }
    }
    return NULL;
}

extern "C" PartyEntry *SaveData_FindEntry(SaveData *save, u32 id)
{
    u32 kind = GetIdKind(id);
    if (kind == 6 || kind == 1) {
        int group = GetEntryGroup(save->m_areaType);
        for (int i = 0; i < 3; i++) {
            int g = (group + i) & 3;
            for (int j = 0; j < 10; j++) {
                if ((save->m_party[g][j].m_flags & 1) && save->m_party[g][j].m_mapId == GetIdMap(id)
                    && save->m_party[g][j].m_index == GetIdIndex(id)) {
                    return &save->m_party[g][j];
                }
            }
        }
    }
    return NULL;
}

extern "C" PartyEntry *SaveData_GetEntry(SaveData *save, int idx)
{
    if (idx < 10) {
        return &save->m_party[GetEntryGroup(save->m_areaType)][idx];
    }
    return NULL;
}

u8 DAT_0208b664[11] = { 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7 };

extern "C" int SaveData_GetPartyCapacity(SaveData *save, u32 level)
{
    if (level >= 11) {
        level = save->m_rangerClassGrade & 0xF;
    }
    u8 value = DAT_0208b664[level];
    if (SaveData_HasPartnerInParty(save, -1)) {
        value++;
    }
    return value;
}

extern "C" BOOL SaveData_IsEventRectEnabled(SaveData *save, int idx, int mapId)
{
    if (mapId < 0) {
        mapId = save->m_mapId;
    }
    switch (save->GetEventRectState(mapId, idx)) {
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

static inline void SetEventRectState(SaveData *save, int mapId, int i, u8 state)
{
    if (mapId < 0) {
        mapId = save->m_mapId;
    }
    if (mapId < MAP_COUNT && i < 48) {
        int shift = (i & 7) * 4;
        save->m_eventRectStates[mapId][i / 8] &= ~(0xF << shift);
        save->m_eventRectStates[mapId][i / 8] |= (state & 0xF) << shift;
    }
}

extern "C" void SaveData_EnableEventRect(SaveData *save, int idx, int mapId)
{
    if (mapId < 0) {
        mapId = save->m_mapId;
    }
    SetEventRectState(save, mapId, idx, 3);
}

extern "C" void SaveData_DisableEventRect(SaveData *save, int idx, int mapId)
{
    if (mapId < 0) {
        mapId = save->m_mapId;
    }
    SetEventRectState(save, mapId, idx, 1);
}

static inline u32 GetActorState(SaveData *save, int kind, int mapId, int i)
{
    if (((kind - 1 < 3) & (mapId < MAP_COUNT)) && i < 48) {
        return (((u32(*)[MAP_COUNT][4])save->m_enemyStates)[kind - 1][mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
    }
    return 0;
}

static inline void SetActorState(SaveData *save, int kind, int mapId, int i, u8 state)
{
    if (((kind - 1 < 3) & (mapId < MAP_COUNT)) && i < 48) {
        int shift = (i & 7) * 4;
        ((u32(*)[MAP_COUNT][4])save->m_enemyStates)[kind - 1][mapId][i / 8] &= ~(0xF << shift);
        ((u32(*)[MAP_COUNT][4])save->m_enemyStates)[kind - 1][mapId][i / 8] |= (state & 0xF) << shift;
    }
}

extern "C" BOOL SaveData_IsActorEnabled(SaveData *save, u32 id)
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

extern "C" void SaveData_EnableActor(SaveData *save, u32 id)
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

extern "C" void SaveData_DisableActor(SaveData *save, u32 id)
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

extern "C" void SaveData_EnableEnemy(SaveData *save, int idx, int mapId)
{
    save->SetEnemyState(mapId, idx, 3);
}

extern "C" void SaveData_DisableEnemy(SaveData *save, int idx, int mapId)
{
    save->SetEnemyState(mapId, idx, 1);
}

extern "C" BOOL SaveData_IsNpcEnabled(SaveData *save, int idx, int mapId)
{
    switch (save->GetNpcState(mapId, idx)) {
    case 3:
    case 4:
        return TRUE;
    }
    return FALSE;
}

extern "C" void SaveData_EnableNpc(SaveData *save, int idx, int mapId)
{
    save->SetNpcState(mapId, idx, 3);
}

extern "C" void SaveData_DisableNpc(SaveData *save, int idx, int mapId)
{
    save->SetNpcState(mapId, idx, 1);
}

extern "C" BOOL SaveData_AddToParty(SaveData *save, u32 id, int kind, int area)
{
    if ((((int)id >> 24) & 0xFF) != 1) {
        return FALSE;
    }
    if (area < 0) {
        area = save->m_areaType;
    }
    int group = GetEntryGroup(area);

    PartyEntry *entry = save->m_party[group];
    for (int i = 0; i < 10; i++, entry++) {
        if (!(entry->m_flags & 1)) {
            SaveEntry_Clear(entry);
            entry->m_flags |= 1;
            entry->m_kind = kind;
            entry->m_mapId = ((int)id >> 12) & 0xFFF;
            entry->m_index = id & 0xFFF;
            entry->m_layer = save->m_layer;
            if (HasPartnerIndex((u16)kind)) {
                entry->m_flags |= 6;
                if (i > 0) {
                    PartyEntry tmp[9];
                    MI_CpuCopy8(save->m_party[group], tmp, i * sizeof(PartyEntry));
                    *(PartyEntryData *)&save->m_party[group][0] = *(PartyEntryData *)entry;
                    save->m_party[group][0].m_flags = 0;
                    save->m_party[group][0].m_flags |= ((PartyEntryData *)entry)->m_flags;
                    MI_CpuCopy8(tmp, &save->m_party[group][1], i * sizeof(PartyEntry));
                }
            }
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" BOOL SaveData_RemoveFromParty(SaveData *save, u32 id)
{
    u32 kind = GetIdKind(id);
    if (kind == 5 || kind == 2) {
        for (int i = 0; i < 2; i++) {
            PartnerSlot *partner = save->GetPartner(i);
            if (partner != NULL && partner->unk_00 != 0 && id == partner->unk_04) {
                partner->unk_00 = 0;
            }
        }
    } else if (kind == 6 || kind == 1) {
        int group = -1;
        int index = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (save->m_party[i][j].m_mapId == GetIdMap(id) && save->m_party[i][j].m_index == GetIdIndex(id)) {
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
            SaveEntry_Clear(&save->m_party[group][9]);
        } else if (index >= 0 && index < 9) {
            for (; index < 9; index++) {
                PartyEntry *dst = &save->m_party[group][index];
                PartyEntry *src = &save->m_party[group][index + 1];
                SaveEntry_Clear(dst);
                if (src->m_flags & 1) {
                    CopyEntry(dst, src);
                }
                SaveEntry_Clear(src);
            }
        }
    }
    return TRUE;
}

extern "C" void SaveData_ClearActorPositions(SaveData *save)
{
    save->unk_7F60 &= ~1;
    MIi_CpuClearFast(0, save->m_enemyPos, sizeof(save->m_enemyPos));
    MIi_CpuClearFast(0, save->m_npcPos, sizeof(save->m_npcPos));
    MIi_CpuClearFast(0, save->m_objectPos, sizeof(save->m_objectPos));
    MIi_CpuClearFast(0, save->m_enemyDir, sizeof(save->m_enemyDir));
    MIi_CpuClearFast(0, save->m_npcDir, sizeof(save->m_npcDir));
    MIi_CpuClearFast(0, save->m_objectDir, sizeof(save->m_objectDir));
}

extern "C" void SaveData_SetStylerLevel(SaveData *save, u32 arg1)
{
    if (save->m_stylerLevel == arg1) {
        return;
    }
    save->m_stylerLevel = arg1;
    save->m_maxEnergy = CGame::GetInstance() == NULL ? 0 : DiskHPTable_GetMaxEnergy(CGame::GetInstance()->m_diskHPTable, arg1);
    int level = SaveData_GetPartsLevel(save, STYLER_PART_ENEPLS);
    if (level == 1) {
        save->m_maxEnergy += 5;
    } else if (level >= 2) {
        save->m_maxEnergy += 15;
    }
}

extern "C" int SaveData_CountParty(SaveData *save, int group)
{
    if (group < 0 || group >= 3) {
        group = GetEntryGroup(save->m_areaType);
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (save->m_party[group][i].m_flags & 1) {
            count++;
        }
    }
    return count;
}

extern "C" int SaveData_GetPartyCapacityExceptPartner(SaveData *save, u32 level, int group)
{
    int value = SaveData_GetPartyCapacity(save, level);
    if (SaveData_HasPartnerInParty(save, group)) {
        value--;
    }
    if (value < 0) {
        value = 0;
    }
    return value;
}

extern "C" int SaveData_CountPartyExceptPartner(SaveData *save, int group)
{
    int count = SaveData_CountParty(save, group);
    if (SaveData_HasPartnerInParty(save, group)) {
        count--;
    }
    if (count < 0) {
        count = 0;
    }
    return count;
}

extern "C" BOOL SaveData_HasPartnerInParty(SaveData *save, int group)
{
    int count = SaveData_CountParty(save, group);
    for (int i = 0; i < count; i++) {
        if (SaveData_GetEntry(save, i)->m_flags & 2) {
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" int SaveData_GetPartyPartnerIndex(SaveData *save, int group)
{
    int count = SaveData_CountParty(save, group);
    for (int i = 0; i < count; i++) {
        PartyEntry *entry = SaveData_GetEntry(save, i);
        if (entry->m_flags & 2) {
            return PartnerKindToIndex(entry->m_kind);
        }
    }
    return -1;
}

extern "C" void SaveData_SelectPartyEntry(SaveData *save, u32 id)
{
    PartyEntry *entry = SaveData_FindEntry(save, save->m_selectedPartyId);
    if (entry != NULL) {
        entry->m_flags &= ~4;
    }
    save->m_selectedPartyId = id;
    entry = SaveData_FindEntry(save, id);
    if (entry != NULL) {
        entry->m_flags |= 4;
    }
}

void SaveData::CheckElapsedTime(RTCTime *time, RTCDate *date)
{
    CGame *game = CGame::GetInstance();
    u32 currSceneId = game->currentScene->getSceneId();

    if (currSceneId == SCENE_RANGER_NET_1 || currSceneId == SCENE_TITLE) {
        return;
    }

    if (m_lastDate.day == 0 || m_lastDate.month == 0) {
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

    s32 year = date->year - m_lastDate.year;
    s32 month = date->month - m_lastDate.month;
    s32 day = date->day - m_lastDate.day;
    s32 hour = time->hour - m_lastTime.hour;
    s32 minute = time->minute - m_lastTime.minute;
    s32 second = time->second - m_lastTime.second;

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
        s32 storedYear = m_lastDate.year;
        s32 i = 0;

        if (month > 0) {
            do {
                u32 v3 = (((m_lastDate.month - 1 + i) % 12) + 1);

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

    m_playHours += day * 24 + hour;
    m_playMinutes += minute;
    m_playSeconds += second;

    while (m_playSeconds >= 60) {
        ++m_playMinutes;
        m_playSeconds -= 60;
    }

    while (m_playMinutes >= 60) {
        ++m_playHours;
        m_playMinutes -= 60;
    }

    if (m_playHours >= 100) {
        unk_87DA = 1;
    }

    m_lastTime.hour = time->hour;
    m_lastTime.minute = time->minute;
    m_lastTime.second = time->second;
    m_lastDate.year = date->year;
    m_lastDate.month = date->month;
    m_lastDate.day = date->day;
    m_lastDate.week = date->week;
}

extern "C" void SaveData_LotGokigenParameter(SaveData *save);

extern "C" void SaveData_LotTimeCheck(SaveData *save)
{
    RTCTime time;
    RTCDate date;
    RTC_GetTime(&time);
    RTC_GetDate(&date);
    save->CheckElapsedTime(&time, &date);

    int hours = save->m_playHours - save->m_lastPlayHours;
    int minutes = save->m_playMinutes - save->m_lastPlayMinutes;
    if (hours > 0) {
        minutes += hours * 60;
    } else if (hours < 0) {
        u32 wrap = 0xFFFFFFFF - save->m_playHours;
        if (wrap < 2) {
            minutes += wrap * 60;
        } else {
            minutes += 120;
        }
    }

    LogInfo("************");
    LogInfo("LotTimeCheck");
    LogInfo("PlayTime %d:%d", save->m_playHours, save->m_playMinutes);
    LogInfo("LastTime %d:%d", save->m_lastPlayHours, save->m_lastPlayMinutes);
    LogInfo("DivTime %d", minutes);
    LogInfo("************");

    if (minutes < 30) {
        return;
    }
    save->m_lastPlayHours = save->m_playHours;
    save->m_lastPlayMinutes = save->m_playMinutes;
    SaveData_LotGokigenParameter(save);
}

extern "C" void LogInfo(const char *fmt, ...)
{
#ifdef PC_PORT
    va_list args;
    va_start(args, fmt);
    thunk_FUN_020442cc(fmt, args);
    va_end(args);
#else
    // va_start without MSL's alignment of the parameter address
    va_list args = (va_list)(&fmt + 1);
    thunk_FUN_020442cc(fmt, args);
#endif
}

extern "C" void SaveData_LotGokigenParameter(SaveData *save)
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
        if (save->m_partnerFlags & bit) {
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
                    save->m_partnerMoods[i] = 2;
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
                    save->m_partnerMoods[i] = 1;
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
                    save->m_partnerMoods[i] = 0;
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
                save->m_partnerMoods[i] = 2;
                remaining--;
            } else if (MATH_Rand16(&MAIN_BSS_0210CEC8, 100) < probability2) {
                LogInfo("SetGood= %s", names[i]);
                free[i] = FALSE;
                save->m_partnerMoods[i] = 1;
                remaining--;
            } else {
                LogInfo("SetNormal= %s", names[i]);
                free[i] = FALSE;
                save->m_partnerMoods[i] = 0;
                remaining--;
            }
        }
    }
    LogInfo("*********************/");
}

extern "C" int SaveData_GetPartsLevel(SaveData *save, int idx)
{
    if (idx >= 26) {
        return 0;
    }
    return (save->m_partsLevels[idx >> 2] >> ((idx & 3) * 2)) & 3;
}

extern "C" void SaveData_SetPartsLevel(SaveData *save, int idx, int level)
{
    if (idx >= 26) {
        return;
    }
    if (level < 0 || level >= 4) {
        return;
    }
    int shift = (idx & 3) * 2;
    u8 bits = save->m_partsLevels[idx >> 2];
    bits &= ~(3 << shift);
    bits |= level << shift;
    save->m_partsLevels[idx >> 2] = bits;
    if (idx != 21) {
        return;
    }
    save->m_maxEnergy = CGame::GetInstance() == NULL ? 0 : DiskHPTable_GetMaxEnergy(CGame::GetInstance()->m_diskHPTable, save->m_stylerLevel);
    if (level == 1) {
        save->m_maxEnergy += 5;
    } else if (level >= 2) {
        save->m_maxEnergy += 15;
    }
}

extern "C" int SaveData_GetPartsBonus(SaveData *save, int idx)
{
    if (idx >= 26) {
        return 0;
    }
    int table[4] = { 0, 3, 6, 7 };
    return table[(save->m_partsLevels[idx >> 2] >> ((idx & 3) * 2)) & 3];
}

extern "C" void SaveData_SetExp(SaveData *save, u32 value)
{
    save->m_exp = value;
    if (value > 9999999) {
        save->m_exp = 9999999;
    }
}

extern "C" u32 SaveData_AddExp(SaveData *save, u32 value)
{
    save->m_exp += value;
    if (save->m_exp > 9999999) {
        save->m_exp = 9999999;
    }
    return save->m_exp;
}

extern "C" void SaveData_SetStepsWalked(SaveData *save, u32 value)
{
    save->m_stepsWalked = value;
    if (value > 9999999) {
        save->m_stepsWalked = 9999999;
    }
}

extern "C" u32 SaveData_AddStepsWalked(SaveData *save, u32 value)
{
    save->m_stepsWalked += value;
    if (save->m_stepsWalked > 9999999) {
        save->m_stepsWalked = 9999999;
    }
    return save->m_stepsWalked;
}

extern "C" void SaveData_SetConversations(SaveData *save, u32 value)
{
    save->m_conversations = value;
    if (value > 99999) {
        save->m_conversations = 99999;
    }
}

extern "C" u32 SaveData_AddConversations(SaveData *save, u32 value)
{
    save->m_conversations += value;
    if (save->m_conversations > 99999) {
        save->m_conversations = 99999;
    }
    return save->m_conversations;
}

extern "C" void SaveData_SetTargetsChecked(SaveData *save, u32 value)
{
    save->m_targetsChecked = value;
    if (value > 99999) {
        save->m_targetsChecked = 99999;
    }
}

extern "C" u32 SaveData_AddTargetsChecked(SaveData *save, u32 value)
{
    save->m_targetsChecked += value;
    if (save->m_targetsChecked > 99999) {
        save->m_targetsChecked = 99999;
    }
    return save->m_targetsChecked;
}

extern "C" void SaveData_SetSaveCount(SaveData *save, u32 value)
{
    save->m_saveCount = value;
    if (value > 99999) {
        save->m_saveCount = 99999;
    }
}

extern "C" u32 SaveData_AddSaveCount(SaveData *save, u32 value)
{
    save->m_saveCount += value;
    if (save->m_saveCount > 99999) {
        save->m_saveCount = 99999;
    }
    return save->m_saveCount;
}

extern "C" void SaveData_SetPokemonRides(SaveData *save, u32 value)
{
    save->m_pokemonRides = value;
    if (value > 99999) {
        save->m_pokemonRides = 99999;
    }
}

extern "C" u32 SaveData_AddPokemonRides(SaveData *save, u32 value)
{
    save->m_pokemonRides += value;
    if (save->m_pokemonRides > 99999) {
        save->m_pokemonRides = 99999;
    }
    return save->m_pokemonRides;
}

extern "C" void SaveData_SetPartnerCount(SaveData *save, int idx, u32 value)
{
    if (idx >= 17) {
        return;
    }
    save->m_partnerCounts[idx] = value;
    if (save->m_partnerCounts[idx] > 9999999) {
        save->m_partnerCounts[idx] = 9999999;
    }
}

extern "C" u32 SaveData_AddPartnerCount(SaveData *save, int kind, u32 value)
{
    int idx = PartnerKindToIndex(kind);
    if (idx < 17) {
        save->m_partnerCounts[idx] += value;
        if (save->m_partnerCounts[idx] > 9999999) {
            save->m_partnerCounts[idx] = 9999999;
        }
        return save->m_partnerCounts[idx];
    }
    return 0;
}

extern "C" u16 SaveData_GetBestPartner(SaveData *save)
{
    int best = -1;
    for (int i = 0; i < 17; i++) {
        if (best < 0) {
            if ((save->m_partnerFlags & (1 << i)) && save->m_partnerCounts[i] != 0) {
                best = i;
            }
        } else if (save->m_partnerCounts[best] < save->m_partnerCounts[i]) {
            best = i;
        }
    }
    if (best < 0) {
        return 0;
    }
    int kind = PartnerIndexToKind(best);
    return PokeIdTable_Get(CGame::GetInstance()->unk_1434, kind)->unk_00;
}

extern "C" void SaveData_SetCaptureLineLength(SaveData *save, u32 value)
{
    save->m_captureLineLength = value;
    if (value > 0xDDF220) {
        save->m_captureLineLength = 0xDDF220;
    }
}

extern "C" u32 SaveData_AddCaptureLineLength(SaveData *save, u32 value)
{
    save->m_captureLineLength += value;
    if (save->m_captureLineLength > 0xDDF220) {
        save->m_captureLineLength = 0xDDF220;
    }
    return save->m_captureLineLength;
}

extern "C" void SaveData_SetLoopCount(SaveData *save, u32 value)
{
    save->m_loopCount = value;
    if (value > 999999) {
        save->m_loopCount = 999999;
    }
}

extern "C" u32 SaveData_AddLoopCount(SaveData *save, u32 value)
{
    save->m_loopCount += value;
    if (save->m_loopCount > 999999) {
        save->m_loopCount = 999999;
    }
    return save->m_loopCount;
}

extern "C" void SaveData_SetTotalCaptures(SaveData *save, u16 value)
{
    save->m_totalCaptures = value;
    if (save->m_totalCaptures > 9999) {
        save->m_totalCaptures = 9999;
    }
}

extern "C" u16 SaveData_AddTotalCaptures(SaveData *save, u16 value)
{
    save->m_totalCaptures += value;
    if (save->m_totalCaptures > 9999) {
        save->m_totalCaptures = 9999;
    }
    return save->m_totalCaptures;
}

extern "C" void SaveData_SetFledCount(SaveData *save, u16 value)
{
    save->m_fledCount = value;
    if (save->m_fledCount > 9999) {
        save->m_fledCount = 9999;
    }
}

extern "C" u16 SaveData_AddFledCount(SaveData *save, u16 value)
{
    save->m_fledCount += value;
    if (save->m_fledCount > 9999) {
        save->m_fledCount = 9999;
    }
    return save->m_fledCount;
}

extern "C" void SaveData_SetAssistsUsed(SaveData *save, u16 value)
{
    save->m_assistsUsed = value;
    if (save->m_assistsUsed > 9999) {
        save->m_assistsUsed = 9999;
    }
}

extern "C" u16 SaveData_AddAssistsUsed(SaveData *save, u16 value)
{
    save->m_assistsUsed += value;
    if (save->m_assistsUsed > 9999) {
        save->m_assistsUsed = 9999;
    }
    return save->m_assistsUsed;
}

class MissionQuestData;
extern MissionQuestData MAIN_BSS_020B2638;
extern "C" int MissionQuestData_CountClearedQuests(MissionQuestData *obj);

extern "C" u8 SaveData_CountClearedQuests(void)
{
    return MissionQuestData_CountClearedQuests(&MAIN_BSS_020B2638);
}

extern "C" void sub_020171B8(SaveData *save)
{
    for (int i = 0; i < 10; i++) {
        SaveEntry_Clear(&save->m_party[2][i]);
    }
    for (int i = 0; i < 10; i++) {
        if ((save->m_party[0][i].m_flags & 1) && (save->m_party[0][i].m_flags & 2)) {
            *(PartyEntryData *)&save->m_party[2][i] = *(PartyEntryData *)&save->m_party[0][i];
            save->m_party[2][i].m_flags = 0;
            save->m_party[2][i].m_flags |= ((PartyEntryData *)&save->m_party[0][i])->m_flags;
            return;
        }
    }
}

u32 DAT_0208b5c0 = 0x1F2E3D4C;

extern "C" BOOL SaveData_IsInitialized(void)
{
    return DAT_0208b5c0 == 0x1F2E3D4C;
}

extern "C" void SaveData_MarkInitialized(void)
{
    DAT_0208b5c0 = 0x1F2E3D4C;
}

extern "C" void SaveData_Backup(SaveData *save)
{
    save->m_backup.unk_00 = save->m_energy;
    save->m_backup.unk_01 = save->m_maxEnergy;
    save->m_backup.unk_02 = save->m_stylerLevel;
    MI_CpuCopy8(save->m_partsLevels, save->m_backup.unk_03, sizeof(save->m_backup.unk_03));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            save->m_backup.unk_0C[i][j] = *(PartyEntryData *)&save->m_party[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        save->m_backup.unk_2DC[i] = *(PartnerSlotData *)&save->m_partners[i];
    }
    save->m_backup.unk_34C = save->unk_0004;
    save->m_backup.unk_350 = save->unk_0008;
    for (int i = 0; i < 17; i++) {
        save->m_backup.unk_351[i] = save->m_partnerMoods[i];
    }

    SaveData_SetStylerLevel(save, 1);
    save->m_energy = save->m_maxEnergy;
    MI_CpuFill8(save->m_partsLevels, 0, sizeof(save->m_partsLevels));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (!(save->m_party[i][j].m_flags & 1) || !(save->m_party[i][j].m_flags & 2)) {
                SaveEntry_Clear(&save->m_party[i][j]);
            }
        }
    }
    save->unk_0004 = 0;
    for (int i = 0; i < 17; i++) {
        save->m_partnerMoods[i] = 0;
    }
}

extern "C" void SaveData_Restore(SaveData *save)
{
    save->m_energy = save->m_backup.unk_00;
    save->m_maxEnergy = save->m_backup.unk_01;
    save->m_stylerLevel = save->m_backup.unk_02;
    MI_CpuCopy8(save->m_backup.unk_03, save->m_partsLevels, sizeof(save->m_partsLevels));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            *(PartyEntryData *)&save->m_party[i][j] = save->m_backup.unk_0C[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        *(PartnerSlotData *)&save->m_partners[i] = save->m_backup.unk_2DC[i];
    }
    save->unk_0004 = save->m_backup.unk_34C;
    save->unk_0008 = save->m_backup.unk_350;
    for (int i = 0; i < 17; i++) {
        save->m_partnerMoods[i] = save->m_backup.unk_351[i];
    }
}

extern "C" CFieldDrawActorData *SaveData_LoadPlayerActorData(SaveData *save, int id)
{
    if (id < 0) {
        id = (save->m_sex & 1) + ((u8)((save->m_rangerClassGrade >> 4) & 0xF) == 0 ? 1 : 3);
    }
    save->m_playerActorData.LoadPlayer(id, 0, 0x1FFFFFFE, NULL, TRUE, FALSE);
    return &save->m_playerActorData;
}

extern "C" void SaveData_ReleasePlayerActorData(SaveData *save)
{
    save->m_playerActorData.Release();
}

extern "C" u32 SaveData_ReleaseUnusedPartnerActorData(SaveData *save);
extern "C" u32 SaveData_ReleaseUnusedPartyActorData(SaveData *save);
extern "C" void SaveData_ReleasePartnerActorData(SaveData *save);
extern "C" void SaveData_ReleasePartyActorData(SaveData *save);

extern "C" CFieldDrawActorData *SaveData_FindPartnerActorData(SaveData *save, u16 id, int form, u16 mask, BOOL reload)
{
    for (int i = 0; i < 2; i++) {
        if (save->m_partnerActorData[i].unk_34 != 0 && id == save->m_partnerActorData[i].unk_1C && form == save->m_partnerActorData[i].unk_1E) {
            return &save->m_partnerActorData[i];
        }
    }
    if (reload) {
        SaveData_ReleaseUnusedPartnerActorData(save);
        save->m_reloadPartyActorData = 1;
    }
    for (int i = 0; i < 2; i++) {
        if (save->m_partnerActorData[i].unk_34 == 0) {
            save->m_partnerActorData[i].Assign(1, id, form, mask);
            return &save->m_partnerActorData[i];
        }
    }
    return NULL;
}

extern "C" CFieldDrawActorData *SaveData_FindPartyActorData(SaveData *save, u16 id, int form, u16 mask, BOOL reload)
{
    for (int i = 0; i < 10; i++) {
        if (save->m_partyActorData[i].unk_34 != 0 && id == save->m_partyActorData[i].unk_1C && form == save->m_partyActorData[i].unk_1E) {
            return &save->m_partyActorData[i];
        }
    }
    if (reload) {
        SaveData_ReleaseUnusedPartyActorData(save);
        save->m_reloadPartyActorData = 1;
    }
    for (int i = 0; i < 10; i++) {
        if (save->m_partyActorData[i].unk_34 == 0) {
            save->m_partyActorData[i].Assign(0, id, form, mask);
            return &save->m_partyActorData[i];
        }
    }
    return NULL;
}

extern "C" void SaveData_LoadPartyActorData(SaveData *save, BOOL force)
{
    u32 partnerMask = 0;
    u32 entryMask = 0;
    int group = GetEntryGroup(save->m_areaType);
    if (force) {
        save->m_reloadPartyActorData = 1;
    } else if (save->m_reloadPartyActorData != 0) {
        save->m_reloadPartyActorData = 0;
        force = TRUE;
    }

    if (!force) {
        FieldData *table = MAIN_BSS_0210CA6C;
        if (table != NULL) {
            u32 used = 0;
            for (int i = 0; i < 2; i++) {
                PartnerSlot *partner = save->GetPartner(i);
                if (partner != NULL && partner->unk_00 != 0) {
                    FieldNpcData *data = FieldData_GetNpc(table, partner->unk_08);
                    partnerMask |= 1 << i;
                    for (int j = 0; j < 2; j++) {
                        if (save->m_partnerActorData[j].unk_34 != 0 && data->unk_00 == save->m_partnerActorData[j].unk_1C) {
                            used |= 1 << j;
                            partnerMask &= ~(1 << i);
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < 2; j++) {
                if (save->m_partnerActorData[j].unk_34 != 0 && !(used & (1 << j))) {
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
                PartyEntry *entry = SaveData_GetEntry(save, i);
                if (entry != NULL && (entry->m_flags & 1)) {
                    PokeIdTableEntry *info = PokeIdTable_Get(game->unk_1434, entry->m_kind);
                    entryMask |= 1 << i;
                    for (int j = 0; j < 10; j++) {
                        if (save->m_partyActorData[j].unk_34 != 0 && info->unk_00 == save->m_partyActorData[j].unk_1C
                            && info->unk_02 == save->m_partyActorData[j].unk_1E) {
                            used |= 1 << j;
                            entryMask &= ~(1 << i);
                            break;
                        }
                    }
                }
            }
            for (int j = 0; j < 10; j++) {
                if (save->m_partyActorData[j].unk_34 != 0 && !(used & (1 << j))) {
                    force = TRUE;
                    break;
                }
            }
        }
    }

    if (force) {
        SaveData_ReleaseAllActorData(save);
        FieldData *table = MAIN_BSS_0210CA6C;
        if (table == NULL) {
            return;
        }
        if (group != 1) {
            for (int i = 0; i < 2; i++) {
                PartnerSlot *partner = save->GetPartner(i);
                if (partner != NULL && partner->unk_00 != 0) {
                    FieldNpcData *data = FieldData_GetNpc(table, partner->unk_08);
                    SaveData_FindPartnerActorData(save, data->unk_00, 0, 0x1E16, FALSE);
                }
            }
        }
        CGame *game = CGame::GetInstance();
        if (game == NULL) {
            return;
        }
        for (int i = 0; i < 10; i++) {
            PartyEntry *entry = SaveData_GetEntry(save, i);
            if (entry != NULL && (entry->m_flags & 1)) {
                FieldEnemyData *enemy = FieldData_GetEnemy(table, entry->m_kind);
                u16 mask = 0xE;
                if (enemy->unk_30 == 2 || enemy->unk_30 == 5) {
                    mask |= 0xC00;
                }
                PokeIdTableEntry *info = PokeIdTable_Get(game->unk_1434, entry->m_kind);
                SaveData_FindPartyActorData(save, info->unk_00, info->unk_02, mask, FALSE);
            }
        }
    } else {
        FieldData *table = MAIN_BSS_0210CA6C;
        if (table == NULL) {
            return;
        }
        if (group != 1) {
            for (int i = 0; i < 2; i++) {
                if (partnerMask & (1 << i)) {
                    FieldNpcData *data = FieldData_GetNpc(table, save->GetPartner(i)->unk_08);
                    SaveData_FindPartnerActorData(save, data->unk_00, 0, 0x1E16, FALSE);
                }
            }
        }
        CGame *game = CGame::GetInstance();
        if (game == NULL) {
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (entryMask & (1 << i)) {
                PartyEntry *entry = SaveData_GetEntry(save, i);
                FieldEnemyData *enemy = FieldData_GetEnemy(table, entry->m_kind);
                u16 mask = 0xE;
                if (enemy->unk_30 == 2 || enemy->unk_30 == 5) {
                    mask |= 0xC00;
                }
                PokeIdTableEntry *info = PokeIdTable_Get(game->unk_1434, entry->m_kind);
                SaveData_FindPartyActorData(save, info->unk_00, info->unk_02, mask, FALSE);
            }
        }
    }
}

extern "C" void SaveData_ReleaseAllActorData(SaveData *save)
{
    SaveData_ReleasePartnerActorData(save);
    SaveData_ReleasePartyActorData(save);
}

extern "C" u32 SaveData_ReleaseUnusedPartnerActorData(SaveData *save)
{
    u32 used = 0;
    FieldData *table = MAIN_BSS_0210CA6C;
    u32 missing = 0;
    if (table != NULL) {
        for (int i = 0; i < 2; i++) {
            PartnerSlot *partner = save->GetPartner(i);
            if (partner != NULL && partner->unk_00 != 0) {
                FieldNpcData *data = FieldData_GetNpc(table, partner->unk_08);
                missing |= 1 << i;
                for (int j = 0; j < 2; j++) {
                    if (save->m_partnerActorData[j].unk_34 != 0 && data->unk_00 == save->m_partnerActorData[j].unk_1C) {
                        used |= 1 << j;
                        missing &= ~(1 << i);
                    }
                }
            }
        }
        for (int j = 0; j < 2; j++) {
            if (save->m_partnerActorData[j].unk_34 != 0 && !(used & (1 << j))) {
                save->m_partnerActorData[j].Release();
            }
        }
    }
    return missing;
}

extern "C" u32 SaveData_ReleaseUnusedPartyActorData(SaveData *save)
{
    CGame *game = CGame::GetInstance();
    u32 used = 0;
    u32 missing = 0;
    if (game != NULL) {
        for (int i = 0; i < 10; i++) {
            PartyEntry *entry = SaveData_GetEntry(save, i);
            if (entry != NULL && (entry->m_flags & 1)) {
                PokeIdTableEntry *info = PokeIdTable_Get(game->unk_1434, entry->m_kind);
                missing |= 1 << i;
                for (int j = 0; j < 10; j++) {
                    if (save->m_partyActorData[j].unk_34 != 0 && info->unk_00 == save->m_partyActorData[j].unk_1C
                        && info->unk_02 == save->m_partyActorData[j].unk_1E) {
                        used |= 1 << j;
                        missing &= ~(1 << i);
                    }
                }
            }
        }
        for (int j = 0; j < 10; j++) {
            if (save->m_partyActorData[j].unk_34 != 0 && !(used & (1 << j))) {
                save->m_partyActorData[j].Release();
            }
        }
    }
    return missing;
}

extern "C" void SaveData_ReleasePartnerActorData(SaveData *save)
{
    for (int i = 0; i < 2; i++) {
        save->m_partnerActorData[i].Release();
    }
}

extern "C" void SaveData_ReleasePartyActorData(SaveData *save)
{
    for (int i = 0; i < 10; i++) {
        save->m_partyActorData[i].Release();
    }
}

extern "C" void SaveData_ReleasePartnerVram(SaveData *save)
{
    for (int i = 0; i < 2; i++) {
        save->m_partnerActorData[i].CFieldDrawActorData::ReleaseVram();
    }
    for (int i = 0; i < 10; i++) {
        save->m_partyActorData[i].CFieldDrawActorData::ReleaseVram();
    }
}

extern "C" void SaveData_SetPlayTime(SaveData *save, u32 hours, u8 minutes, u8 seconds)
{
    save->m_playHours = hours;
    save->m_playMinutes = minutes;
    save->m_playSeconds = seconds;
    while (save->m_playSeconds >= 60) {
        save->m_playMinutes++;
        save->m_playSeconds -= 60;
    }
    while (save->m_playMinutes >= 60) {
        save->m_playHours++;
        save->m_playMinutes -= 60;
    }
    if (save->m_playHours >= 100) {
        save->unk_87DA = TRUE;
    } else {
        save->unk_87DA = FALSE;
    }
    save->m_lastPlayHours = hours;
    save->m_lastPlayMinutes = minutes;
}
