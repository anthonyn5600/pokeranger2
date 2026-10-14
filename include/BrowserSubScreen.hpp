#ifndef POKERANGER2_BROWSERSUBSCREEN_HPP
#define POKERANGER2_BROWSERSUBSCREEN_HPP

#include <nitro.h>

#include "BGLayer.hpp"
#include "CGame.hpp"
#include "MessageTable.hpp"
#include "RegionMap.hpp"
#include "UnkClass_021226C0.hpp"
#include "common.hpp"

// Defined in ov21
class BrowserSubScreen {
public:
    BrowserSubScreen(CGame *game);
    ~BrowserSubScreen();

    void ov21_021220B8();
    void ov21_02122114();
    void ov21_0212212C();
    void ov21_02122144();
    void ov21_02122168();
    void ov21_02122180();
    void ov21_02122214();
    void ov21_02122368();
    void ov21_021223FC();
    void ov21_021224B4(const UnkStruct_02123618 *entry);
    void ov21_021224E4(const UnkStruct_02123618 *entry);
    BOOL ov21_02122534();
    void ov21_021225F8(u16 id);
    void ov21_02122608();
    void ov21_021226AC();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    RegionMap *unk_08;
    u32 unk_0C;
    MessageTable *unk_10;
    UnkStruct_02123618 unk_14;
    u32 unk_20;
    int unk_24[6];
    BGLayer *unk_3C;
    int unk_40; // display needs update
    u16 unk_44;
    CGame *unk_48;
};

STATIC_SIZE_ASSERT(BrowserSubScreen, 0x4C);

#endif // POKERANGER2_BROWSERSUBSCREEN_HPP
