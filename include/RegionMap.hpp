#ifndef POKERANGER2_REGIONMAP_HPP
#define POKERANGER2_REGIONMAP_HPP

#include <nitro.h>

#include "BGLayer.hpp"
#include "CGame.hpp"
#include "MessageTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "common.hpp"

class FieldData;

// One area of the sub-screen region map (DAT_0208c938).
struct MapMenuArea {
    u16 id;
    u64 mask; // save flag bits that unlock the area
    u16 type;
    s16 offsetX;
    s16 offsetY;
};

STATIC_SIZE_ASSERT(MapMenuArea, 0x14);

// Sub-screen region map ("map000" BG + area/cursor sprites), used by overlays 8, 9, 21, 27 and 28.
class RegionMap {
public:
    struct Entry {
        OamSprite *sprite;
        int cellId;
        int unk_08;
    };

    RegionMap(CGame *game);
    ~RegionMap();

    void Init();
    void Update();
    void Render();
    void sub_0202A5F8();
    void Release();
    void WriteOam();
    void Load(int bg, u8 *oamIndex, int *charNo, int *paletteSlot, BOOL extPltt);
    void LoadToVram(BOOL extPltt);
    void UpdateTouch();
    void BlinkCursor();
    void ShowAvailableAreas();
    BOOL ShowHabitat(u64 *flags);
    BOOL HighlightAreas(u64 *flags);
    BOOL IsAreaAvailable(int i, u64 *flags);
    void ShowCurrentArea();
    void SetSpriteToArea(int sprite, u16 id);
    u16 GetAreaId(u32 mapId);
    void GetAreaPos(u16 id, int *x, int *y);
    int FindArea(u16 id);
    void SetAreaMarker(u16 id, int mode);
    void GetSelection(s16 *kind, u16 *id);

public:
    u16 unk_00;
    int unk_04;
    FieldData *unk_08;
    MessageTable *unk_0C;
    OamSpriteSet *unk_10;
    OamSpriteSet *unk_14;
    OamSpriteSet *unk_18;
    Entry *unk_1C;
    BGLayer *unk_20;
    int unk_24;
    OamSprite *unk_28[5];
    u8 unk_3C[0x14];
    int unk_50;
    u16 unk_54;
    u16 unk_56;
    s16 unk_58;
    int unk_5C;
    BOOL unk_60;
    CGame *unk_64;
};

STATIC_SIZE_ASSERT(RegionMap, 0x68);

#endif // POKERANGER2_REGIONMAP_HPP
