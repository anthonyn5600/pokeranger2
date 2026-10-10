#ifndef POKERANGER2_FIELD_CFIELDMAP_HPP
#define POKERANGER2_FIELD_CFIELDMAP_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class CBinaryFile;
class CFieldMapLayerAttribute;
class CFieldMapLayerBase;
class CFieldMapLayerCollision;
class UnkClass_02003718;
class UnkClass_02007AA4;
class UnkClass_020074D4;

// Map size in pixels.
struct FieldMapSize {
    int width;
    int height;
};

// MPIF chunk of a map file.
struct FieldMapInfo {
    FieldMapSize size;
    u32 unk_08;
    u32 unk_0C;
};

// Script interpreter state (arm9, around 0x02044464), embedded in CFieldMap.
struct UnkStruct_02044464 {
    u8 unk_00[0x24];
};

// Texture of the map's MTX chunk (constructor ov0_021302BC).
class UnkClass_021302BC {
public:
    UnkClass_021302BC();
    ~UnkClass_021302BC();

    UnkClass_020074D4 **m_images;
    u8 unk_04[0x8];
    UnkClass_02007AA4 **m_palettes;
    u8 unk_10[0x2C];
    u16 unk_3C;
    u8 unk_3E[0x2];
};

// One animation frame of an MCT entry: a prebuilt display list per palette variant.
struct FieldMapCharaPiece {
    Rectangle bounds;
    void *displayLists[4];
    u32 displayListSize;
    u8 unk_24[0x8];
};

// Entry of the map's MCT chunk (constructor ov0_0212F82C).
class UnkClass_0212F82C {
public:
    UnkClass_0212F82C();
    ~UnkClass_0212F82C();

    inline FieldMapCharaPiece *GetPiece(int i)
    {
        if (i >= 0 && i < m_pieceCount) {
            return &m_pieces[i];
        }
        return NULL;
    }

    void *unk_00;
    u32 unk_04;
    FieldMapCharaPiece *m_pieces;
    u32 unk_0C;
    u32 unk_10;
    int m_pieceCount;
    u8 unk_18;
    u8 m_frame;
    u8 unk_1A[0x2];
    int unk_1C;
};

// Entry of the map's MPA chunk (constructor ov0_0212FEDC).
class UnkClass_0212FEDC {
public:
    UnkClass_0212FEDC();
    ~UnkClass_0212FEDC();

    void *unk_00;
    u8 unk_04[0x10];
};

// FieldMap.cpp (ov0)
class CFieldMap {
public:
    CFieldMap();
    ~CFieldMap();

    void ov0_02124D98(const char *name);
    void ov0_02124E48();
    void ov0_02124E9C();
    void ov0_02124EE4();
    void ov0_021251D8(BOOL runScript, int fps);
    void ov0_02125338(UnkClass_02003718 *camera);
    int ov0_0212546C(int group);
    UnkClass_021302BC *ov0_0212550C(void *data, int id);
    CFieldMapLayerBase *ov0_02125904(void *data, int group, int index);
    UnkClass_0212F82C *ov0_02125CA8(void *data, int index);
    UnkClass_0212FEDC *ov0_02125CE8(void *data, int index);
    BOOL ov0_02125D28(u8 group, const char *name, u32 heapId);
    void ov0_02126658();

    // Attribute layer of a layer group.
    inline CFieldMapLayerAttribute *GetAttributeLayer(int i)
    {
        return i < unk_24 ? (CFieldMapLayerAttribute *)unk_30[i] : NULL;
    }

    // Collision layer of a layer group.
    inline CFieldMapLayerCollision *GetLayer(int i)
    {
        return i < unk_24 ? (CFieldMapLayerCollision *)unk_2C[i] : NULL;
    }

    inline void SetPolygonCount(int i, int count)
    {
        if (i < unk_24) {
            unk_34[i] = count;
        }
    }

    inline int GetCharacterPriority(int i)
    {
        return i < unk_24 ? unk_28[i] : -1;
    }

    inline int GetPolygonCount(int i)
    {
        return i < unk_24 ? unk_34[i] : 0;
    }

public:
    BOOL unk_00;
    UnkClass_021302BC **unk_04;
    int unk_08;
    int unk_0C;
    UnkClass_0212F82C **unk_10;
    int unk_14;
    UnkClass_0212FEDC **unk_18;
    int unk_1C;
    CFieldMapLayerBase ***unk_20;
    int unk_24;
    int *unk_28;
    void **unk_2C;
    void **unk_30;
    int *unk_34;
    int *unk_38;
    FieldMapInfo m_info;
    CBinaryFile *unk_4C;
    int unk_50;
    UnkStruct_02044464 unk_54;
    void *unk_78;
    void *unk_7C;
};

STATIC_SIZE_ASSERT(CFieldMap, 0x80);

#endif // POKERANGER2_FIELD_CFIELDMAP_HPP
