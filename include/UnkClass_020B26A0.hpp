#ifndef POKERANGER2_UNKCLASS_020B26A0_HPP
#define POKERANGER2_UNKCLASS_020B26A0_HPP

#include <nitro.h>

#include "sub_02006000.hpp"

#define MAP_COUNT 441

struct UnkStruct_020B26A0_8AD4 {
    u32 unk_00;
    u32 unk_04;
    u16 unk_08;
    u16 unk_0A;
    fx32 unk_0C;
    fx32 unk_10;
    u8 unk_14[0x24];
};

struct UnkStruct_020155FC {
    inline void SetPos(Point2D pos)
    {
        unk_0C = pos.x;
        unk_10 = pos.y;
    }

    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u32 unk_08;
    fx32 unk_0C;
    fx32 unk_10;
    u16 unk_14;
    u16 unk_16;
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
    u8 unk_0020[0x4];
    u16 unk_0024;
    s16 unk_0026;
    u8 unk_0028[0x8];
    u32 unk_0030[MAP_COUNT][6];
    u32 unk_2988[MAP_COUNT][4];
    u32 unk_4518[MAP_COUNT][4];
    u32 unk_60A8[MAP_COUNT][4];
    u32 unk_7C38;
    u8 unk_7C3C[0x324];
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
    u8 unk_8757[0xD];
    int unk_8764;
    u8 unk_8768[0x57];
    u8 unk_87BF;
    int unk_87C0;
    int unk_87C4;
    u8 unk_87C8[0xC];
    u32 unk_87D4;
    u8 unk_87D8;
    u8 unk_87D9;
    u8 unk_87DA;
    u8 unk_87DB[0x8];
    u8 unk_87E3;
    u8 unk_87E4[0x1E];
    u8 unk_8802;
    u8 unk_8803;
    u8 unk_8804[0x2D0];
    UnkStruct_020B26A0_8AD4 unk_8AD4[2];
    char unk_8B44[0x20];
    u8 unk_8B64;
    u32 unk_8B68;
    u32 unk_8B6C;
    u8 unk_8B70[0x4];
    u32 unk_8B74;
    u8 unk_8B78[0x8];
    int unk_8B80;
    RTCDate unk_8B84;
    RTCTime unk_8B94;
    // TODO: Confirm this class is that big.
    // Not 100% sure, but very likely. This size is needed to match functions
    // sub_0200F8BC and ov0_0214F830.
    int unk_8BA0;
    u8 unk_8BA4[0x1C];
    int unk_8BC0;
    u8 unk_8BC4[0x8B75];
};

extern "C" {
UnkStruct_020155FC *sub_020155FC(UnkClass_020B26A0 *save, int idx);
}

#endif // POKERANGER2_UNKCLASS_020B26A0_HPP
