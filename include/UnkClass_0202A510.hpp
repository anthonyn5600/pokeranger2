#ifndef POKERANGER2_UNKCLASS_0202A510_HPP
#define POKERANGER2_UNKCLASS_0202A510_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_02021404.hpp"
#include "common.hpp"

class UnkClass_02041C80;

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
class UnkClass_0202A510 {
public:
    struct Entry {
        UnkClass_0200E960 *sprite;
        int cellId;
        int unk_08;
    };

    UnkClass_0202A510(CGame *game);
    ~UnkClass_0202A510();

    void Init();
    void sub_0202A5A8();
    void sub_0202A5EC();
    void sub_0202A5F8();
    void Release();
    void sub_0202A6E8();
    void sub_0202A724(int bg, u8 *oamIndex, int *charNo, int *paletteSlot, BOOL extPltt);
    void sub_0202AD04(BOOL extPltt);
    void sub_0202AD78();
    void sub_0202AE7C();
    void sub_0202AED4();
    BOOL sub_0202AF5C(u64 *flags);
    BOOL sub_0202B140(u64 *flags);
    BOOL sub_0202B244(int i, u64 *flags);
    void sub_0202B2CC();
    void sub_0202B2FC(int sprite, u16 id);
    u16 sub_0202B338(u32 mapId);
    void sub_0202B370(u16 id, int *x, int *y);
    int sub_0202B458(u16 id);
    void sub_0202B50C(u16 id, int mode);
    void sub_0202B5A8(s16 *kind, u16 *id);

public:
    u16 unk_00;
    int unk_04;
    UnkClass_02041C80 *unk_08;
    UnkClass_02021404 *unk_0C;
    UnkClass_0200ECD0 *unk_10;
    UnkClass_0200ECD0 *unk_14;
    UnkClass_0200ECD0 *unk_18;
    Entry *unk_1C;
    UnkClass_0201FC80 *unk_20;
    int unk_24;
    UnkClass_0200E960 *unk_28[5];
    u8 unk_3C[0x14];
    int unk_50;
    u16 unk_54;
    u16 unk_56;
    s16 unk_58;
    int unk_5C;
    BOOL unk_60;
    CGame *unk_64;
};

STATIC_SIZE_ASSERT(UnkClass_0202A510, 0x68);

#endif // POKERANGER2_UNKCLASS_0202A510_HPP
