#ifndef POKERANGER2_BROWSERSCREEN_HPP
#define POKERANGER2_BROWSERSCREEN_HPP

#include <nitro.h>

#include "BrowserSubScreen.hpp"
#include "CGame.hpp"
#include "Collision.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SubScreenButton.hpp"
#include "SubScreenPokemonInfo.hpp"
#include "TextPrinter.hpp"
#include "UnkClass_021226C0.hpp"
#include "common.hpp"
#include "scene/CBrowserMenu.hpp"

// Defined in ov21: a sprite of the browser's screen
struct UnkStruct_0211CFF4 {
    void Init(OamSpriteSet *anim, u8 no, int x, int y, int priority);

    void SetAnim(u8 no)
    {
        unk_04->SetAnim(unk_08, no);
        unk_09 = no;
    }

    OamSprite *unk_00;
    OamSpriteSet *unk_04;
    u8 unk_08;
    u8 unk_09; // anim no
    int unk_0C; // x
    int unk_10; // y
};

STATIC_SIZE_ASSERT(UnkStruct_0211CFF4, 0x14);

// Defined in ov21: a touch button of the browser's screen
struct UnkStruct_0211D040 {
    UnkStruct_0211D040()
    {
        unk_00 = NULL;
        unk_04 = 0;
        unk_0C = 0;
        unk_10 = 1;
    }

    void Init(UnkStruct_0211CFF4 *sprite, s16 width, s16 height, s16 offsetX, s16 offsetY, u8 type);
    BOOL IsTouched();
    int ov21_0211D0A8();
    void Press(u8 timer);
    void Update();

    UnkStruct_0211CFF4 *unk_00;
    u8 unk_04; // timer
    u8 unk_05; // anim no
    u8 unk_06; // pressed anim no
    u8 unk_07;
    u8 unk_08; // type
    u8 unk_09; // repeat timer
    int unk_0C; // pressed
    int unk_10;
};

STATIC_SIZE_ASSERT(UnkStruct_0211D040, 0x14);

// A message file copied into memory
struct UnkStruct_0211DAB4 {
    struct Entry {
        u32 size;
        u8 *data;
    };

    u32 unk_00;
    u32 count;
    Entry *entries;
};

// Defined in ov21: the encyclopedia browser
class BrowserScreen {
public:
    BrowserScreen(CGame *game);
    ~BrowserScreen();

    void ov21_0211D824();
    void ov21_0211D8D4();
    void ov21_0211D950();
    UnkStruct_0211DAB4 *ov21_0211DAB4(const char *path);
    void ov21_0211DBA0();
    void ov21_0211E14C();
    void ov21_0211E600();
    void ov21_0211E7D8();
    void ov21_0211E8B4();
    void ov21_0211ED70();
    void ov21_0211F1D4();
    void ov21_0211F260(int x);
    void ov21_0211F394(u32 mode, int arg, BOOL keep);
    BOOL ov21_0211F440(int mode, BOOL arg1);
    void ov21_0211F730(int arg0);
    void ov21_0211F8E4();
    void ov21_0211F9E0(BOOL arg0);
    void ov21_0211FAE8(int row, int id, int no);
    void ov21_0211FD9C(int mode);
    void ov21_0211FF20();
    u16 ov21_0211FFDC(int index);
    int ov21_02120000(int index);
    void ov21_0212004C();
    void ov21_021203A8();
    void ov21_02120490();
    void ov21_021204B0();
    void ov21_0211F584(int category);
    void ov21_0211FF80(int msg);

public:
    CGame *unk_000;
    SubScreenPokemonInfo *unk_004;
    BrowserSubScreen *unk_008;
    SubScreenButton *unk_00C;
    UnkClass_021226C0 *unk_010;
    CBrowserMenuManagerPokemon *unk_014;
    CBrowserMenuManagerType *unk_018;
    CBrowserMenuManagerIcon *unk_01C;
    TextPrinter *unk_020;
    TextPrinter *unk_024;
    TextPrinter *unk_028;
    u32 unk_02C;
    int unk_030;
    int unk_034; // state
    u32 unk_038;
    int unk_03C;
    int unk_040; // category
    int unk_044; // saved unk_03C
    int unk_048; // saved unk_040
    int unk_04C; // saved scroll (Pokemon list)
    int unk_050; // saved scroll (icons)
    int unk_054; // saved scroll (types)
    int unk_058; // saved selection (Pokemon list)
    int unk_05C; // saved selection (icons)
    int unk_060; // saved selection (types)
    int unk_064;
    int unk_068;
    u16 unk_06C;
    int unk_070;
    int unk_074;
    Point2D unk_078; // x: slide between the list and the category screen
    OamSpriteSet *unk_080;
    OamSpriteSet *unk_084[3];
    u32 unk_090;
    UnkStruct_0211CFF4 unk_094[11];
    UnkStruct_0211D040 unk_170[11];
    u32 unk_24C;
    UnkStruct_0211DAB4 *unk_250;
    UnkStruct_0211DAB4 *unk_254;
    UnkStruct_0211DAB4 *unk_258;
    UnkStruct_0211DAB4 *unk_25C;
};

STATIC_SIZE_ASSERT(BrowserScreen, 0x260);

#endif // POKERANGER2_BROWSERSCREEN_HPP
