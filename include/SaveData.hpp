#ifndef POKERANGER2_SAVEDATA_HPP
#define POKERANGER2_SAVEDATA_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "field/CFieldDrawActorData.hpp"

#define MAP_COUNT 441

// Plain data of a partner slot / field entry; the backup at 0x8BC4 holds copies of them.
struct PartnerSlotData {
    u32 unk_00;
    u32 unk_04;
    u16 unk_08;
    u16 unk_0A;
    Point2D unk_0C;
    char unk_14[0x20];
    u16 unk_34;
};

struct PartnerSlot : public PartnerSlotData {
    PartnerSlot();
    ~PartnerSlot();
};

struct PartyEntryData {
    u16 m_kind;
    u16 m_mapId;
    u16 m_index;
    u32 m_flags;
    Point2D m_pos;
    u16 unk_14;
    u16 m_layer;
};

struct PartyEntry : public PartyEntryData {
    PartyEntry();
    ~PartyEntry();

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
};

struct UnkStruct_020B26A0_Backup {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03[7];
    PartyEntryData unk_0C[3][10];
    PartnerSlotData unk_2DC[2];
    u32 unk_34C;
    u8 unk_350;
    u8 unk_351[0x11];
};

// Styler custom parts (SaveData::m_partsLevels, 2 bits each); names from the field debug menu labels
// (Custom0..2: "CROUND_G" spelled so there).
enum StylerPart {
    STYLER_PART_LEAF_G = 0,
    STYLER_PART_AQUA_G = 1,
    STYLER_PART_LIGHT_G = 2,
    STYLER_PART_FIRE_G = 3,
    STYLER_PART_FIGHT_G = 4,
    STYLER_PART_POISON_G = 5,
    STYLER_PART_PSYCHO_G = 6,
    STYLER_PART_INSECT_G = 7,
    STYLER_PART_GROUND_G = 8,
    STYLER_PART_ROCK_G = 9,
    STYLER_PART_AIR_G = 10,
    STYLER_PART_DARK_G = 11,
    STYLER_PART_HORROR_G = 12,
    STYLER_PART_ICE_G = 13,
    STYLER_PART_NORMAL_G = 14,
    STYLER_PART_METAL_G = 15,
    STYLER_PART_DRAGON_G = 16,
    STYLER_PART_ASSISTT = 17,
    STYLER_PART_SOKO = 18,
    STYLER_PART_COMBO = 19,
    STYLER_PART_RECOVER = 20,
    STYLER_PART_ENEPLS = 21,
    STYLER_PART_LONGLINE = 22,
    STYLER_PART_POWPLS = 23,
    STYLER_PART_CHGSPD = 24,
    STYLER_PART_SUPERCHG = 25,
    STYLER_PART_COUNT = 26,
};

class SaveData {
public:
    void CheckElapsedTime(RTCTime *time, RTCDate *date);

    inline BOOL HasString()
    {
        return m_saveName[0] != '\0';
    }

    inline PartnerSlot *GetPartner(int i)
    {
        if (i >= 0 && i < 2) {
            return &m_partners[i];
        }
        return NULL;
    }

    inline Point2D GetPos()
    {
        return (Point2D) { m_posX << FX32_SHIFT, m_posY << FX32_SHIFT };
    }

    inline Point2D GetEnemyPos(int i)
    {
        return (Point2D) { m_enemyPos[i * 2] << FX32_SHIFT, m_enemyPos[i * 2 + 1] << FX32_SHIFT };
    }

    inline Point2D GetNpcPos(int i)
    {
        return (Point2D) { m_npcPos[i * 2] << FX32_SHIFT, m_npcPos[i * 2 + 1] << FX32_SHIFT };
    }

    inline Point2D GetObjectPos(int i)
    {
        return (Point2D) { m_objectPos[i * 2] << FX32_SHIFT, m_objectPos[i * 2 + 1] << FX32_SHIFT };
    }

    inline BOOL IsButton1Enabled()
    {
        BOOL enabled = FALSE;
        if (!(unk_8756 & 1)) {
            enabled = TRUE;
        }
        return enabled;
    }

    inline BOOL IsButton2Enabled()
    {
        BOOL enabled = FALSE;
        if (!(unk_8756 & 2)) {
            enabled = TRUE;
        }
        return enabled;
    }

    inline void SetEnemy(int i, Point2D pos, u16 dir)
    {
        m_enemyPos[i * 2] = pos.x >> FX32_SHIFT;
        m_enemyPos[i * 2 + 1] = pos.y >> FX32_SHIFT;
        m_enemyDir[i] = dir;
    }

    inline void SetNpc(int i, Point2D pos, u16 dir)
    {
        m_npcPos[i * 2] = pos.x >> FX32_SHIFT;
        m_npcPos[i * 2 + 1] = pos.y >> FX32_SHIFT;
        m_npcDir[i] = dir;
    }

    inline void SetObject(int i, Point2D pos, u16 dir)
    {
        m_objectPos[i * 2] = pos.x >> FX32_SHIFT;
        m_objectPos[i * 2 + 1] = pos.y >> FX32_SHIFT;
        m_objectDir[i] = dir;
    }

    inline void SetPos(Point2D pos)
    {
        m_posX = pos.x >> FX32_SHIFT;
        m_posY = pos.y >> FX32_SHIFT;
    }

    inline Point2D GetUnk0020()
    {
        return (Point2D) { unk_0020 << FX32_SHIFT, unk_0022 << FX32_SHIFT };
    }

    inline void SetUnk0020(Point2D pos)
    {
        unk_0020 = pos.x >> FX32_SHIFT;
        unk_0022 = pos.y >> FX32_SHIFT;
    }

    // Fields of the per-flag words unk_81B4: bit 0 valid, 1-7 kind, 8-11 sub, 12-19 count, 20-31 value.
    inline void SetFlagKind(u32 i, int kind)
    {
        u32 flags = unk_81B4[i];
        unk_81B4[i] = (flags & ~0xFE) | ((u32)(kind << 25) >> 24) | 1;
    }

    inline void SetFlagCount(u32 i, int count, int sub)
    {
        u32 flags = unk_81B4[i];
        unk_81B4[i] = (flags & 0xFFF000FE) | ((u32)(count << 24) >> 12) | ((u32)(sub << 28) >> 20) | 1;
    }

    inline void SetFlagValue(u32 i, int value)
    {
        u32 flags = unk_81B4[i];
        unk_81B4[i] = (flags & 0xFFFFF) | (value << 20);
    }

    // Per-map 4-bit states of the field's actors; mapId < 0 means the current map.
    static inline BOOL IsValidMapId(int mapId)
    {
        return mapId < MAP_COUNT;
    }

    inline u32 GetEventRectState(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = m_mapId;
        }
        if (mapId < MAP_COUNT && i < 48) {
            return (m_eventRectStates[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline u32 GetEnemyState(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = m_mapId;
        }
        if (IsValidMapId(mapId) && i < 48) {
            return (m_enemyStates[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline void SetEnemyState(int mapId, int i, u8 state)
    {
        if (mapId < 0) {
            mapId = m_mapId;
        }
        if (IsValidMapId(mapId) && i < 48) {
            int shift = (i & 7) * 4;
            m_enemyStates[mapId][i / 8] &= ~(0xF << shift);
            m_enemyStates[mapId][i / 8] |= (state & 0xF) << shift;
        }
    }

    inline u32 GetNpcState(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = m_mapId;
        }
        if (IsValidMapId(mapId) && i < 48) {
            return (m_npcStates[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline void SetNpcState(int mapId, int i, u8 state)
    {
        if (mapId < 0) {
            mapId = m_mapId;
        }
        if (IsValidMapId(mapId) && i < 48) {
            int shift = (i & 7) * 4;
            m_npcStates[mapId][i / 8] &= ~(0xF << shift);
            m_npcStates[mapId][i / 8] |= (state & 0xF) << shift;
        }
    }

    inline u32 GetObjectState(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = m_mapId;
        }
        if (IsValidMapId(mapId) && i < 48) {
            return (m_objectStates[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline void SetObjectState(int mapId, int i, u8 state)
    {
        if (mapId < 0) {
            mapId = m_mapId;
        }
        if (IsValidMapId(mapId) && i < 48) {
            int shift = (i & 7) * 4;
            m_objectStates[mapId][i / 8] &= ~(0xF << shift);
            m_objectStates[mapId][i / 8] |= (state & 0xF) << shift;
        }
    }

public:
    SaveData();
    ~SaveData();

    u8 m_sex;
    u8 m_energy;
    u8 m_maxEnergy;
    u8 m_rangerClassGrade;
    u32 unk_0004;
    u8 unk_0008;
    u8 m_partnerMoods[0x11];
    u16 m_mapId;
    s16 m_posX;
    s16 m_posY;
    s16 unk_0020;
    s16 unk_0022;
    u16 m_dir;
    s16 m_layer;
    u32 m_levelExp;
    u32 m_exp;
    u32 m_eventRectStates[MAP_COUNT][6];
    u32 m_enemyStates[MAP_COUNT][4];
    u32 m_npcStates[MAP_COUNT][4];
    u32 m_objectStates[MAP_COUNT][4];
    u32 m_selectedPartyId;
    u32 m_pokemonStates[0x20];
    u8 m_captureCounts[500];
    u32 unk_7EB0[0x20];
    u32 m_encyclopediaStates[3][4];
    u32 unk_7F60;
    u64 unk_7F64;
    s16 m_enemyPos[64];
    s16 m_npcPos[64];
    s16 m_objectPos[64];
    u16 m_enemyDir[32];
    u16 m_npcDir[32];
    u16 m_objectDir[32];
    int unk_81AC;
    u32 unk_81B0;
    u32 unk_81B4[0x50];
    s16 unk_82F4[0xA0]; // per-flag position x, y (unk_81B4)
    u8 unk_8434; // cannon type (FieldCannons::CreateCannon)
    u8 unk_8435;
    // per-flag cannon shot state (flags 0x20..0x4F, CFieldCannon::UpdateShots)
    s16 unk_8436[0x50]; // x
    s16 unk_84D6[0x50]; // y
    u16 unk_8576[0x50]; // speed
    u16 unk_8616[0x50]; // angle
    u16 unk_86B6[0x50];
    u8 unk_8756;
    u8 unk_8757;
    u32 m_stepsWalked;
    u32 m_conversations;
    u32 m_targetsChecked;
    u32 m_saveCount;
    u32 m_pokemonRides;
    u32 m_partnerCounts[17];
    u32 m_captureLineLength;
    u32 m_loopCount;
    u16 m_totalCaptures;
    u16 m_fledCount;
    u16 m_assistsUsed;
    u8 unk_87BE;
    u8 m_timerMode;
    int m_timer;
    int m_timerLimit;
    u32 m_partnerFlags;
    u32 m_lastPlayHours;
    u8 m_lastPlayMinutes;
    u32 m_playHours;
    u8 m_playMinutes;
    u8 m_playSeconds;
    u8 unk_87DA;
    u8 m_stylerLevel;
    u8 m_partsLevels[7];
    u8 m_playerName;
    u8 unk_87E4[0x1E];
    u8 unk_8802;
    u8 unk_8803;
    PartyEntry m_party[3][10];
    PartnerSlot m_partners[2];
    char m_saveName[0x20];
    u8 m_areaType;
    u32 unk_8B68;
    u32 unk_8B6C;
    u32 m_subScreenShowsMap;
    u32 unk_8B74;
    u16 unk_8B78;
    u16 unk_8B7A;
    u16 unk_8B7C;
    u16 unk_8B7E;
    int unk_8B80;
    RTCDate m_lastDate;
    RTCTime m_lastTime;
    int unk_8BA0;
    u8 unk_8BA4[0x1C];
    int unk_8BC0;
    UnkStruct_020B26A0_Backup m_backup;
    CActorDataPlayer m_playerActorData;
    CActorDataPartner m_partnerActorData[2];
    CActorDataPartner m_partyActorData[10];
    u32 m_reloadPartyActorData;
};

extern SaveData MAIN_BSS_020B26A0;

extern "C" {
void SaveEntry_Clear(PartyEntry *entry);
void SavePartner_Clear(PartnerSlot *partner);
void SavePartner_SetName(PartnerSlot *partner, const char *name);
void SavePartner_ClearName(PartnerSlot *partner);
void SaveData_Init(SaveData *save);
PartyEntry *SaveData_FindEntry(SaveData *save, u32 id);
PartyEntry *SaveData_GetEntry(SaveData *save, int idx);
int SaveData_GetPartyCapacity(SaveData *save, u32 level);
void SaveData_ClearActorPositions(SaveData *save);
void SaveData_SetStylerLevel(SaveData *save, u32 arg1);
int SaveData_CountParty(SaveData *save, int group);
BOOL SaveData_HasPartnerInParty(SaveData *save, int group);
void SaveData_SelectPartyEntry(SaveData *save, u32 id);
int SaveData_GetPartsLevel(SaveData *save, int idx);
void SaveData_SetPartsLevel(SaveData *save, int idx, int level);
int SaveData_GetPartsBonus(SaveData *save, int idx);
void SaveData_SetExp(SaveData *save, u32 value);
void SaveData_SetStepsWalked(SaveData *save, u32 value);
void SaveData_SetConversations(SaveData *save, u32 value);
void SaveData_SetTargetsChecked(SaveData *save, u32 value);
void SaveData_SetSaveCount(SaveData *save, u32 value);
void SaveData_SetPokemonRides(SaveData *save, u32 value);
void SaveData_SetCaptureLineLength(SaveData *save, u32 value);
void SaveData_SetLoopCount(SaveData *save, u32 value);
void SaveData_SetTotalCaptures(SaveData *save, u16 value);
void SaveData_SetFledCount(SaveData *save, u16 value);
void SaveData_SetAssistsUsed(SaveData *save, u16 value);
void SaveData_ReleasePlayerActorData(SaveData *save);
void SaveData_ReleaseAllActorData(SaveData *save);

u8 DiskHPTable_GetMaxEnergy(void *obj, u32 arg1);
}

#endif // POKERANGER2_SAVEDATA_HPP
