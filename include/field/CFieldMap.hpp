#ifndef POKERANGER2_FIELD_CFIELDMAP_HPP
#define POKERANGER2_FIELD_CFIELDMAP_HPP

#include <nitro.h>
#include <nnsys.h>
#include <vector>

#include "common.hpp"
#include "sub_02006000.hpp"

// vector<T *> uses the vector<unsigned long> code, whose instances come from MSL_CPP (msl_thread.o, in main).
// The original calls them as external symbols; instantiating them here would replace the library copies.
// __dont_instantiate (mwcc's extern template) would also keep the out-of-class inline ctor from being inlined,
// so that one is instantiated explicitly (its unreferenced copy is deadstripped).
// clang-format off
namespace std {
template __vec_deleter<unsigned long, allocator<unsigned long> >::__vec_deleter();
template __dont_instantiate class __vec_deleter<unsigned long, allocator<unsigned long> >;
} // namespace std
// clang-format on

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

// Textures of the map's MTX chunk (constructor ov0_021302BC): images and palettes with their VRAM keys.
class UnkClass_021302BC {
public:
    UnkClass_021302BC();
    ~UnkClass_021302BC();
    BOOL AddImage(UnkClass_020074D4 *image, NNSGfdTexKey key);
    BOOL AddPalette(UnkClass_02007AA4 *palette, NNSGfdPlttKey key, void *data);
    void Release();

    std::vector<UnkClass_020074D4 *> m_images;
    std::vector<UnkClass_02007AA4 *> m_palettes;
    std::vector<NNSGfdTexKey> m_texKeys;
    std::vector<NNSGfdPlttKey> m_plttKeys;
    std::vector<void *> m_paletteData;
    u16 unk_3C;
    u8 unk_3E[0x2];
};

// One animation frame of an MCT entry: a prebuilt display list per flip (bit 0: horizontal, bit 1: vertical).
struct FieldMapCharaPiece {
    Rectangle bounds;
    void *displayLists[4];
    u32 displayListSize;
    u32 bufferSize;
    u8 duration;
    u8 unk_29[0x3];
};

// Frame data of an MCT entry as stored in the map file: which texture/palette and which 16x16 cell of it.
struct FieldMapCharaFrame {
    u8 unk_00;
    u8 texture;
    u8 palette;
    u8 paletteOffset;
    u8 duration;
    u8 unk_05;
    u16 cell;
};

// Entry of the map's MCT chunk (constructor ov0_0212F82C): an animated textured quad.
class UnkClass_0212F82C {
public:
    UnkClass_0212F82C();
    ~UnkClass_0212F82C();
    BOOL Load(void *data);
    void Release();
    void Update(int fps);

    inline FieldMapCharaPiece *GetPiece(int i)
    {
        if (i >= 0 && i < m_pieceCount) {
            return &m_pieces[i];
        }
        return NULL;
    }

    UnkClass_021302BC **m_textures;
    FieldMapCharaFrame *m_frames;
    FieldMapCharaPiece *m_pieces;
    int m_width;
    int m_height;
    int m_pieceCount;
    u8 m_timer;
    u8 m_frame;
    u8 unk_1A[0x2];
    int m_polygonId;
};

// Frame of an MPA entry: which palette and color to show, and for how long.
struct FieldMapPaletteFrame {
    u8 palette;
    u8 color;
    u8 duration;
};

// Entry of the map's MPA chunk (constructor ov0_0212FEDC): a palette animation. Mode 1 replaces one color,
// mode 2 swaps whole 16-color palettes, mode 3 cycles a range of colors.
class UnkClass_0212FEDC {
public:
    UnkClass_0212FEDC();
    ~UnkClass_0212FEDC();
    void Reset();
    BOOL Load(void *data);
    void Release();
    void Update(int fps);
    void Apply();

    UnkClass_021302BC **m_textures;
    FieldMapPaletteFrame *m_frames;
    u8 m_texture;
    u8 m_mode;
    u8 m_palette;
    u8 m_color;
    u8 m_colorCount;
    u8 m_frameCount;
    u8 m_timer;
    u8 m_frame;
    BOOL m_dirty;
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
STATIC_SIZE_ASSERT(UnkClass_021302BC, 0x40);

#endif // POKERANGER2_FIELD_CFIELDMAP_HPP
