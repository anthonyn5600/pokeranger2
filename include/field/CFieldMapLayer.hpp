#ifndef POKERANGER2_FIELD_CFIELDMAPLAYER_HPP
#define POKERANGER2_FIELD_CFIELDMAPLAYER_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldMap.hpp"
#include "sub_02006000.hpp"

class Camera2D;

// Map layers, one list per layer group. CFieldMap::ov0_02125904 creates them from the map file's MLG chunks.
// The base and CharacterPriority layers are inline-only (their vtables live in FieldMap.cpp); every other
// layer type has its own source file.
class CFieldMapLayerBase {
public:
    CFieldMapLayerBase()
    {
        unk_04 = 0;
        unk_08 = 0;
    }

    virtual int GetType()
    {
        return 0;
    }

    virtual int Draw(Camera2D *camera)
    {
        return 0;
    }

    virtual int GetPolygonCount()
    {
        return 0;
    }

    virtual void Update(int fps)
    {
    }

    virtual ~CFieldMapLayerBase()
    {
    }

    virtual BOOL Load(void *data)
    {
        return FALSE;
    }

    virtual void Release()
    {
    }

    virtual void SetPolygonId(int id)
    {
    }

public:
    s32 unk_04;
    u32 unk_08;
};

class CFieldMapLayerCharacterPriority : public CFieldMapLayerBase {
public:
    virtual int GetType()
    {
        return 1;
    }
};

// One rectangular piece of a static layer, drawn with a prebuilt display list.
struct FieldMapStaticPiece {
    Rectangle bounds;
    void *displayList;
    u32 displayListSize;
};

class CFieldMapLayerStatic : public CFieldMapLayerBase {
public:
    CFieldMapLayerStatic();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual ~CFieldMapLayerStatic();
    virtual BOOL Load(void *data);
    virtual void Release();
    virtual void SetPolygonId(int id);

    void DrawPieces(Rectangle view);

public:
    int unk_0C;
    int m_width;
    int m_height;
    UnkClass_021302BC **m_textures;
    GXRgb m_color;
    u16 unk_1E;
    GXPolygonMode m_polygonMode;
    int m_polygonId;
    s16 m_offsetX;
    s16 m_offsetY;
    int m_alpha;
    FieldMapStaticPiece *m_pieces;
    int m_pieceCount;
    BOOL m_repeat;
};

// Cell coordinates in a collision layer's grid.
struct FieldCellPos {
    int x;
    int y;
};

// Only ever freed by CFieldMapLayerCollision::Release.
class UnkClass_CollisionObject {
public:
    virtual ~UnkClass_CollisionObject();
};

// Grid of collision cell types. Types 1-25 and 26-50 are the same 25 shapes for two kinds of wall,
// 63 is a full block of a third kind, 0 is empty.
class CFieldMapLayerCollision : public CFieldMapLayerBase {
public:
    CFieldMapLayerCollision();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual ~CFieldMapLayerCollision();
    virtual BOOL Load(void *data);
    virtual void Release();

    BOOL ToCell(fx32 x, fx32 y, FieldCellPos *out);
    int GetCell(int index);
    int GetCellIndex(int x, int y);
    int GetCellAt(int x, int y);
    int GetCellAtPos(fx32 x, fx32 y);
    int GetLeftEdge(int index, PointPair2D *out);
    int GetRightEdge(int index, PointPair2D *out);
    int GetTopEdge(int index, PointPair2D *out);
    int GetBottomEdge(int index, PointPair2D *out);
    int GetLeftEdges(int index, PointPair2D *out);
    int GetRightEdges(int index, PointPair2D *out);
    int GetTopEdges(int index, PointPair2D *out);
    int GetBottomEdges(int index, PointPair2D *out);
    BOOL Sweep(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds);
    BOOL Collide(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds);
    BOOL SweepFine(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds);
    BOOL CollideFine(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds);

    BOOL IsCircleBlocked(Point2D pos, fx32 radius, u32 kinds);
    BOOL IsCircleBlockedFine(Point2D pos, fx32 radius, u32 kinds);

    static BOOL IsKindA(int type);
    static BOOL IsKindB(int type);
    static BOOL IsWall(int type);
    static BOOL IsKindC(int type);

public:
    int m_cellCount;
    int m_width;
    int m_height;
    int m_cellSize;
    u16 *m_cells;
    int m_solidCount;
    UnkClass_CollisionObject **unk_24;
    u8 *unk_28;
};

// Entry of a CharaTrans layer: an MCT animation placed at a position.
struct FieldMapCharaEntry {
    s16 x;
    s16 y;
    u8 mct;
    u8 variant;
};

class CFieldMapLayerCharaTrans : public CFieldMapLayerBase {
public:
    CFieldMapLayerCharaTrans();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);

    virtual int GetPolygonCount()
    {
        if (m_mct != NULL && m_entries != NULL && m_count > 0) {
            return 1;
        }
        return 0;
    }

    virtual ~CFieldMapLayerCharaTrans();
    virtual BOOL Load(void *data);
    virtual void Release();

    void DrawEntries(Rectangle view, int baseX, int baseY, fx32 scale);

public:
    int m_count;
    int m_width;
    int m_height;
    s16 m_offsetX;
    s16 m_offsetY;
    GXRgb m_color;
    u16 unk_1E;
    FieldMapCharaEntry *m_entries;
    UnkClass_0212F82C **m_mct;
    BOOL m_repeat;
};

// A static layer plus a CharaTrans layer drawn on top of it.
class CFieldMapLayerNormalView : public CFieldMapLayerBase {
public:
    CFieldMapLayerNormalView();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual ~CFieldMapLayerNormalView();
    virtual BOOL Load(void *data);
    virtual void Release();
    virtual void SetPolygonId(int id);

public:
    CFieldMapLayerStatic *m_static;
    CFieldMapLayerCharaTrans *m_chara;
    u8 unk_14[0x8];
    s16 m_offsetX;
    s16 m_offsetY;
    UnkClass_021302BC **m_textures;
    UnkClass_0212F82C **m_mct;
};

// NPC placement of an Npc/Enemy layer (11 bytes in the map file).
struct FieldMapNpcEntry {
    s16 x;
    s16 y;
    u8 dir;
    u8 hidden;
    u16 unk_06;
    u16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
};

class CFieldMapLayerNpc : public CFieldMapLayerBase {
public:
    CFieldMapLayerNpc();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual ~CFieldMapLayerNpc();
    virtual BOOL Load(void *data);
    virtual void Release();

    BOOL LoadEntries(void *data);

public:
    int m_count;
    FieldMapNpcEntry *m_entries;
};

class CFieldMapLayerEnemy : public CFieldMapLayerNpc {
public:
    CFieldMapLayerEnemy()
    {
    }

    virtual int GetType();
    virtual ~CFieldMapLayerEnemy();
    virtual BOOL Load(void *data);

    BOOL LoadEntries(void *data);
};

// Target object placement of an Object layer.
struct FieldMapObjectEntry {
    s16 x;
    s16 y;
    u16 state;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
};

class CFieldMapLayerObject : public CFieldMapLayerBase {
public:
    CFieldMapLayerObject();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual ~CFieldMapLayerObject();
    virtual BOOL Load(void *data);
    virtual void Release();

public:
    int m_count;
    FieldMapObjectEntry *m_entries;
};

// Event rectangle of an EventRect layer, in pixels (top left corner and size).
struct FieldMapEventRectEntry {
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    u16 scriptId;
};

class CFieldMapLayerEventRect : public CFieldMapLayerBase {
public:
    CFieldMapLayerEventRect();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual ~CFieldMapLayerEventRect();
    virtual BOOL Load(void *data);
    virtual void Release();

public:
    int m_count;
    FieldMapEventRectEntry *m_entries;
};

// Grid of attribute cells (ground types). The kinds masks of its queries are bitmasks of attribute values.
class CFieldMapLayerAttribute : public CFieldMapLayerBase {
public:
    CFieldMapLayerAttribute();
    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual ~CFieldMapLayerAttribute();
    virtual BOOL Load(void *data);
    virtual void Release();

    BOOL ToCell(fx32 x, fx32 y, FieldCellPos *out);
    int GetCell(int index);
    int GetCellIndex(int x, int y);
    int GetCellAt(int x, int y);
    int GetCellAtPos(fx32 x, fx32 y);
    BOOL Sweep(PointPair2D *move, fx32 radius, u32 kinds, Point2D *out);
    BOOL Collide(PointPair2D *move, fx32 radius, u32 kinds, Point2D *out);
    BOOL IsCircleBlocked(Point2D pos, fx32 radius, u32 kinds);
    BOOL IsCircleBlockedFine(Point2D pos, fx32 radius, u32 kinds);

public:
    int m_cellCount;
    int m_width;
    int m_height;
    int m_cellSize;
    u16 *m_cells;
};

// A NormalView layer that scrolls at its own rate relative to the camera (parallax) and can scroll by itself.
class CFieldMapLayerMultiScroll : public CFieldMapLayerNormalView {
public:
    CFieldMapLayerMultiScroll()
    {
    }

    inline void SetMapSize(int width, int height)
    {
        m_mapSize.width = width;
        m_mapSize.height = height;
    }

    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual void Update(int fps);
    virtual ~CFieldMapLayerMultiScroll();
    virtual BOOL Load(void *data);

public:
    // The layer moves by m_rateX / m_divX of the camera's movement.
    int m_rateX;
    int m_rateY;
    int m_divX;
    int m_divY;
    FieldMapSize m_mapSize;
    // Scroll speed per 60 fps frame.
    fx32 m_speedX;
    fx32 m_speedY;
    fx32 m_scrollX;
    fx32 m_scrollY;
};

// A static layer whose texture coordinates scroll.
class CFieldMapLayerUVScroll : public CFieldMapLayerStatic {
public:
    CFieldMapLayerUVScroll()
    {
    }

    virtual int GetType();
    virtual int Draw(Camera2D *camera);
    virtual int GetPolygonCount();
    virtual void Update(int fps);
    virtual ~CFieldMapLayerUVScroll();
    virtual BOOL Load(void *data);

public:
    // Scroll speed per 60 fps frame, in texels.
    fx32 m_speedU;
    fx32 m_speedV;
    fx32 m_u;
    fx32 m_v;
};

// Color key of a ColorAnime layer: the color is held for holdTime frames, then blended into the next key's
// color over fadeTime frames (frames at 60 fps).
struct FieldMapColorKey {
    u8 r;
    u8 g;
    u8 b;
    u8 unk_03;
    u16 holdTime;
    u16 fadeTime;
};

// A NormalView layer whose vertex color cycles through color keys.
class CFieldMapLayerColorAnime : public CFieldMapLayerNormalView {
public:
    CFieldMapLayerColorAnime();
    virtual int GetType();
    virtual void Update(int fps);
    virtual ~CFieldMapLayerColorAnime();
    virtual BOOL Load(void *data);
    virtual void Release();

public:
    FieldMapColorKey *m_keys;
    int m_keyCount;
    int m_keyIndex;
    BOOL m_fading;
    int m_timer;
};

STATIC_SIZE_ASSERT(CFieldMapLayerBase, 0xC);
STATIC_SIZE_ASSERT(CFieldMapLayerCharacterPriority, 0xC);
STATIC_SIZE_ASSERT(CFieldMapLayerStatic, 0x3C);
STATIC_SIZE_ASSERT(CFieldMapLayerCollision, 0x2C);
STATIC_SIZE_ASSERT(CFieldMapLayerNormalView, 0x28);
STATIC_SIZE_ASSERT(CFieldMapLayerCharaTrans, 0x2C);
STATIC_SIZE_ASSERT(CFieldMapLayerNpc, 0x14);
STATIC_SIZE_ASSERT(CFieldMapLayerEnemy, 0x14);
STATIC_SIZE_ASSERT(CFieldMapLayerObject, 0x14);
STATIC_SIZE_ASSERT(CFieldMapLayerEventRect, 0x14);
STATIC_SIZE_ASSERT(CFieldMapLayerAttribute, 0x20);
STATIC_SIZE_ASSERT(CFieldMapLayerMultiScroll, 0x50);
STATIC_SIZE_ASSERT(CFieldMapLayerUVScroll, 0x4C);
STATIC_SIZE_ASSERT(CFieldMapLayerColorAnime, 0x3C);

#endif // POKERANGER2_FIELD_CFIELDMAPLAYER_HPP
