#ifndef POKERANGER2_FLYINGMAP_HPP
#define POKERANGER2_FLYINGMAP_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "FieldData.hpp"
#include "MessageTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "RegionMap.hpp"
#include "SubScreenPokemonInfo.hpp"
#include "common.hpp"

// Fly destination (ov9 table)
struct UnkStruct_0211DCAC {
    u16 mapId;
    s16 x;
    s16 y;
    u16 unk_06;
    u16 unk_08;
    u8 unk_0A;
    u8 placeId;
    u16 unk_0C;
    u16 messageId;
};

STATIC_SIZE_ASSERT(UnkStruct_0211DCAC, 0x10);

// Defined in ov9: fly destination map (CFlyingScene)
class FlyingMap {
public:
    FlyingMap(CGame *game);
    ~FlyingMap();

    void ov9_0211CCCC();
    void ov9_0211CD40();
    void ov9_0211CE80();
    void ov9_0211CEF0();
    void ov9_0211CF14();
    void ov9_0211CF48();
    void ov9_0211D0A0();
    void ov9_0211D0CC();
    BOOL ov9_0211D484();
    BOOL ov9_0211D49C();
    void ov9_0211D4D4();
    void ov9_0211D568();
    void ov9_0211D66C();
    void ov9_0211D680(u16 id);
    void ov9_0211D690();
    BOOL ov9_0211D754();
    void ov9_0211D790();
    void ov9_0211D7FC();
    void ov9_0211D84C();
    void ov9_0211D878(u16 id);
    u16 ov9_0211D89C(u8 placeId);
    void ov9_0211D8F8(u16 placeId);
    void ov9_0211D980(u16 id, int mode);
    void ov9_0211D9F0();
    void ov9_0211DA34();
    BOOL ov9_0211DA78();
    int ov9_0211DAC0();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    int unk_08; // frame counter
    u32 unk_0C;
    int unk_10; // flew
    RegionMap *unk_14;
    SubScreenPokemonInfo *unk_18;
    FieldData *unk_1C;
    MessageTable *unk_20;
    OamSpriteSet *unk_24;
    u32 unk_28;
    u32 unk_2C;
    OamSpriteSet *unk_30;
    u8 *unk_34;
    u32 unk_38;
    OamSprite *unk_3C[2];
    int unk_44;
    u16 unk_48;
    u16 unk_4A;
    u32 unk_4C;
    int unk_50;
    CGame *unk_54;
};

STATIC_SIZE_ASSERT(FlyingMap, 0x58);

#endif // POKERANGER2_FLYINGMAP_HPP
