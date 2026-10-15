#ifndef POKERANGER2_BROWSERSCREEN_HPP
#define POKERANGER2_BROWSERSCREEN_HPP

#include <nitro.h>

#include "BrowserEntryList.hpp"
#include "BrowserSubScreen.hpp"
#include "CGame.hpp"
#include "Collision.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SubScreenButton.hpp"
#include "SubScreenPokemonInfo.hpp"
#include "TextPrinter.hpp"
#include "common.hpp"
#include "scene/CBrowserMenu.hpp"

// Defined in ov21: a sprite of the browser's screen
struct BrowserSprite {
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

STATIC_SIZE_ASSERT(BrowserSprite, 0x14);

// Defined in ov21: a touch button of the browser's screen
struct BrowserButton {
    BrowserButton()
    {
        unk_00 = NULL;
        unk_04 = 0;
        unk_0C = 0;
        unk_10 = 1;
    }

    void Init(BrowserSprite *sprite, s16 width, s16 height, s16 offsetX, s16 offsetY, u8 type);
    BOOL IsTouched();
    int IsPressed();
    void Press(u8 timer);
    void Update();

    BrowserSprite *unk_00;
    u8 unk_04; // timer
    u8 unk_05; // anim no
    u8 unk_06; // pressed anim no
    u8 unk_07;
    u8 unk_08; // type
    u8 unk_09; // repeat timer
    int unk_0C; // pressed
    int unk_10;
};

STATIC_SIZE_ASSERT(BrowserButton, 0x14);

// A message file copied into memory
struct MessageBank {
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

    void Init();
    void InitSubScreen();
    void LoadTextboxFrame();
    MessageBank *LoadMessageBank(const char *path);
    void InitText();
    void InitGraphics();
    void InitButtons();
    void InitMenus();
    void UpdateTouch();
    void UpdateKeys();
    void UpdateButtons();
    void SetSlideX(int x);
    void ApplyFilter(u32 mode, int arg, BOOL keep);
    BOOL SwitchPage(int mode, BOOL arg1);
    void SelectValue(int arg0);
    void ToggleAreaView();
    void RefreshSubScreen(BOOL arg0);
    void PrintRow(int row, int id, int no);
    void RefreshRows(int mode);
    void PrintPendingRow();
    u16 GetEntryId(int index);
    int GetDexNo(int index);
    void Update();
    void Draw();
    void ov21_02120490();
    void ov21_021204B0();
    void SetCategory(int category);
    void PrintHelp(int msg);

public:
    CGame *unk_000;
    SubScreenPokemonInfo *unk_004;
    BrowserSubScreen *unk_008;
    SubScreenButton *unk_00C;
    BrowserEntryList *unk_010;
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
    BrowserSprite unk_094[11];
    BrowserButton unk_170[11];
    u32 unk_24C;
    MessageBank *unk_250;
    MessageBank *unk_254;
    MessageBank *unk_258;
    MessageBank *unk_25C;
};

STATIC_SIZE_ASSERT(BrowserScreen, 0x260);

#endif // POKERANGER2_BROWSERSCREEN_HPP
