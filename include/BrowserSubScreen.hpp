#ifndef POKERANGER2_BROWSERSUBSCREEN_HPP
#define POKERANGER2_BROWSERSUBSCREEN_HPP

#include <nitro.h>

#include "BGLayer.hpp"
#include "BrowserEntryList.hpp"
#include "CGame.hpp"
#include "MessageTable.hpp"
#include "RegionMap.hpp"
#include "common.hpp"

// Defined in ov21
class BrowserSubScreen {
public:
    BrowserSubScreen(CGame *game);
    ~BrowserSubScreen();

    void Init();
    void Update();
    void Render();
    void ov21_02122144();
    void LoadPalette();
    void Release();
    void Load();
    void SetupBg();
    void LoadToVram();
    void SetEntry(const BrowserEntry *entry);
    void ShowEntry(const BrowserEntry *entry);
    BOOL ShowHabitat();
    void SetArea(u16 id);
    void ApplyPending();
    void SetCurrentArea();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    RegionMap *unk_08;
    u32 unk_0C;
    MessageTable *unk_10;
    BrowserEntry unk_14;
    u32 unk_20;
    int unk_24[6];
    BGLayer *unk_3C;
    int unk_40; // display needs update
    u16 unk_44;
    CGame *unk_48;
};

STATIC_SIZE_ASSERT(BrowserSubScreen, 0x4C);

#endif // POKERANGER2_BROWSERSUBSCREEN_HPP
