#ifndef POKERANGER2_UNKCLASS_020B26A0_HPP
#define POKERANGER2_UNKCLASS_020B26A0_HPP

#include <nitro.h>

#include "field/CFieldDrawActorData.hpp"
#include "sub_02006000.hpp"

#define MAP_COUNT 441

// Plain data of a partner slot / field entry; the backup at 0x8BC4 holds copies of them.
struct UnkStruct_020B26A0_8AD4_Data {
    u32 unk_00;
    u32 unk_04;
    u16 unk_08;
    u16 unk_0A;
    Point2D unk_0C;
    char unk_14[0x20];
    u16 unk_34;
};

struct UnkStruct_020B26A0_8AD4 : public UnkStruct_020B26A0_8AD4_Data {
    UnkStruct_020B26A0_8AD4();
    ~UnkStruct_020B26A0_8AD4();
};

struct UnkStruct_020155FC_Data {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u32 unk_08;
    Point2D unk_0C;
    u16 unk_14;
    u16 unk_16;
};

struct UnkStruct_020155FC : public UnkStruct_020155FC_Data {
    UnkStruct_020155FC();
    ~UnkStruct_020155FC();

    inline void SetPos(Point2D pos)
    {
        unk_0C.x = pos.x;
        unk_0C.y = pos.y;
    }
};

struct UnkStruct_020B26A0_Backup {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03[7];
    UnkStruct_020155FC_Data unk_0C[3][10];
    UnkStruct_020B26A0_8AD4_Data unk_2DC[2];
    u32 unk_34C;
    u8 unk_350;
    u8 unk_351[0x11];
};

class UnkClass_020B26A0 {
public:
    void sub_0201630C(RTCTime *time, RTCDate *date);

    inline BOOL HasString()
    {
        return unk_8B44[0] != '\0';
    }

    inline UnkStruct_020B26A0_8AD4 *GetPartner(int i)
    {
        if (i >= 0 && i < 2) {
            return &unk_8AD4[i];
        }
        return NULL;
    }

    inline Point2D GetPos()
    {
        return (Point2D) { unk_001C << FX32_SHIFT, unk_001E << FX32_SHIFT };
    }

    inline Point2D GetEnemyPos(int i)
    {
        return (Point2D) { unk_7F6C[i * 2] << FX32_SHIFT, unk_7F6C[i * 2 + 1] << FX32_SHIFT };
    }

    inline Point2D GetNpcPos(int i)
    {
        return (Point2D) { unk_7FEC[i * 2] << FX32_SHIFT, unk_7FEC[i * 2 + 1] << FX32_SHIFT };
    }

    inline Point2D GetObjectPos(int i)
    {
        return (Point2D) { unk_806C[i * 2] << FX32_SHIFT, unk_806C[i * 2 + 1] << FX32_SHIFT };
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
        unk_7F6C[i * 2] = pos.x >> FX32_SHIFT;
        unk_7F6C[i * 2 + 1] = pos.y >> FX32_SHIFT;
        unk_80EC[i] = dir;
    }

    inline void SetNpc(int i, Point2D pos, u16 dir)
    {
        unk_7FEC[i * 2] = pos.x >> FX32_SHIFT;
        unk_7FEC[i * 2 + 1] = pos.y >> FX32_SHIFT;
        unk_812C[i] = dir;
    }

    inline void SetObject(int i, Point2D pos, u16 dir)
    {
        unk_806C[i * 2] = pos.x >> FX32_SHIFT;
        unk_806C[i * 2 + 1] = pos.y >> FX32_SHIFT;
        unk_816C[i] = dir;
    }

    inline void SetPos(Point2D pos)
    {
        unk_001C = pos.x >> FX32_SHIFT;
        unk_001E = pos.y >> FX32_SHIFT;
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

    // Per-map 4-bit states of the field's actors; mapId < 0 means the current map.
    static inline BOOL IsValidMapId(int mapId)
    {
        return mapId < MAP_COUNT;
    }

    inline u32 GetUnk0030State(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = unk_001A;
        }
        if (mapId < MAP_COUNT && i < 48) {
            return (unk_0030[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline u32 GetEnemyState(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = unk_001A;
        }
        if (IsValidMapId(mapId) && i < 48) {
            return (unk_2988[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline void SetEnemyState(int mapId, int i, u8 state)
    {
        if (mapId < 0) {
            mapId = unk_001A;
        }
        if (IsValidMapId(mapId) && i < 48) {
            int shift = (i & 7) * 4;
            unk_2988[mapId][i / 8] &= ~(0xF << shift);
            unk_2988[mapId][i / 8] |= (state & 0xF) << shift;
        }
    }

    inline u32 GetNpcState(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = unk_001A;
        }
        if (IsValidMapId(mapId) && i < 48) {
            return (unk_4518[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline void SetNpcState(int mapId, int i, u8 state)
    {
        if (mapId < 0) {
            mapId = unk_001A;
        }
        if (IsValidMapId(mapId) && i < 48) {
            int shift = (i & 7) * 4;
            unk_4518[mapId][i / 8] &= ~(0xF << shift);
            unk_4518[mapId][i / 8] |= (state & 0xF) << shift;
        }
    }

    inline u32 GetObjectState(int mapId, int i)
    {
        if (mapId < 0) {
            mapId = unk_001A;
        }
        if (IsValidMapId(mapId) && i < 48) {
            return (unk_60A8[mapId][i / 8] >> ((i & 7) * 4)) & 0xF;
        }
        return 0;
    }

    inline void SetObjectState(int mapId, int i, u8 state)
    {
        if (mapId < 0) {
            mapId = unk_001A;
        }
        if (IsValidMapId(mapId) && i < 48) {
            int shift = (i & 7) * 4;
            unk_60A8[mapId][i / 8] &= ~(0xF << shift);
            unk_60A8[mapId][i / 8] |= (state & 0xF) << shift;
        }
    }

public:
    UnkClass_020B26A0();
    ~UnkClass_020B26A0();

    u8 unk_0000;
    u8 unk_0001;
    u8 unk_0002;
    u8 unk_0003;
    u32 unk_0004;
    u8 unk_0008;
    u8 unk_0009[0x11];
    u16 unk_001A;
    s16 unk_001C;
    s16 unk_001E;
    s16 unk_0020;
    s16 unk_0022;
    u16 unk_0024;
    s16 unk_0026;
    u32 unk_0028;
    u32 unk_002C;
    u32 unk_0030[MAP_COUNT][6];
    u32 unk_2988[MAP_COUNT][4];
    u32 unk_4518[MAP_COUNT][4];
    u32 unk_60A8[MAP_COUNT][4];
    u32 unk_7C38;
    u32 unk_7C3C[0x9D];
    u32 unk_7EB0[0x20];
    u8 unk_7F30[0x30];
    u32 unk_7F60;
    u64 unk_7F64;
    s16 unk_7F6C[64];
    s16 unk_7FEC[64];
    s16 unk_806C[64];
    u16 unk_80EC[32];
    u16 unk_812C[32];
    u16 unk_816C[32];
    int unk_81AC;
    u32 unk_81B0;
    u32 unk_81B4[0x50];
    u8 unk_82F4[0x462];
    u8 unk_8756;
    u8 unk_8757;
    u32 unk_8758;
    u32 unk_875C;
    u32 unk_8760;
    u32 unk_8764;
    u32 unk_8768;
    u32 unk_876C[17];
    u32 unk_87B0;
    u32 unk_87B4;
    u16 unk_87B8;
    u16 unk_87BA;
    u16 unk_87BC;
    u8 unk_87BE;
    u8 unk_87BF;
    int unk_87C0;
    int unk_87C4;
    u32 unk_87C8;
    u32 unk_87CC;
    u8 unk_87D0;
    u32 unk_87D4;
    u8 unk_87D8;
    u8 unk_87D9;
    u8 unk_87DA;
    u8 unk_87DB;
    u8 unk_87DC[7];
    u8 unk_87E3;
    u8 unk_87E4[0x1E];
    u8 unk_8802;
    u8 unk_8803;
    UnkStruct_020155FC unk_8804[3][10];
    UnkStruct_020B26A0_8AD4 unk_8AD4[2];
    char unk_8B44[0x20];
    u8 unk_8B64;
    u32 unk_8B68;
    u32 unk_8B6C;
    u32 unk_8B70;
    u32 unk_8B74;
    u8 unk_8B78[0x8];
    int unk_8B80;
    RTCDate unk_8B84;
    RTCTime unk_8B94;
    int unk_8BA0;
    u8 unk_8BA4[0x1C];
    int unk_8BC0;
    UnkStruct_020B26A0_Backup unk_8BC4;
    UnkClass_020412A0 unk_8F28;
    CActorDataPartner unk_59760[2];
    CActorDataPartner unk_597D0[10];
    u32 unk_59A00;
};

extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

extern "C" {
void sub_020150B8(UnkStruct_020155FC *entry);
void sub_02015124(UnkStruct_020B26A0_8AD4 *partner);
void sub_02015164(UnkStruct_020B26A0_8AD4 *partner, const char *name);
void sub_0201518C(UnkStruct_020B26A0_8AD4 *partner);
void sub_02015198(UnkClass_020B26A0 *save);
UnkStruct_020155FC *sub_02015520(UnkClass_020B26A0 *save, u32 id);
UnkStruct_020155FC *sub_020155FC(UnkClass_020B26A0 *save, int idx);
int sub_02015658(UnkClass_020B26A0 *save, u32 level);
void sub_020160B8(UnkClass_020B26A0 *save, u32 arg1);
int sub_02016138(UnkClass_020B26A0 *save, int group);
BOOL sub_0201621C(UnkClass_020B26A0 *save, int group);
int sub_02016C14(UnkClass_020B26A0 *save, int idx);
void sub_0201772C(UnkClass_020B26A0 *save);
void sub_02017E44(UnkClass_020B26A0 *save);

u8 sub_02010E78(void *obj, u32 arg1);
}

#endif // POKERANGER2_UNKCLASS_020B26A0_HPP
