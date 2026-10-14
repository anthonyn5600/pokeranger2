#ifndef POKERANGER2_SUBSCREENBUTTON_HPP
#define POKERANGER2_SUBSCREENBUTTON_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "common.hpp"

// Sub-screen "ma005" button sprite (used by overlays 5 and 21).
class SubScreenButton {
public:
    SubScreenButton();
    ~SubScreenButton();

    void Load(u32 charOffset, int oamIndex, u32 paletteSlot, int x, int y);
    BOOL UpdateInput();
    void Render();

public:
    CGame *unk_00;
    OamSprite *unk_04;
    OamSpriteSet *unk_08;
    u32 unk_0C;
    int unk_10;
    int unk_14;
    int unk_18;
    u32 unk_1C;
    BOOL unk_20;
    BOOL unk_24;
};

STATIC_SIZE_ASSERT(SubScreenButton, 0x28);

#endif // POKERANGER2_SUBSCREENBUTTON_HPP
