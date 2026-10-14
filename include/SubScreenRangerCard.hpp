#ifndef POKERANGER2_SUBSCREENRANGERCARD_HPP
#define POKERANGER2_SUBSCREENRANGERCARD_HPP

#include <nitro.h>

#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"

// Sub-screen ranger card (BGS archive, data/menu/mp000_bg_LZ.bin): player name, rank, styler level and energy, browser
// count; loaded step by step by LoadStep() (FieldSubScreen::unk_4C) or at once by LoadAll() (overlay 6)
class SubScreenRangerCard {
public:
    SubScreenRangerCard();
    ~SubScreenRangerCard();

    void Release();
    int LoadStep(int step);
    void LoadAll();
    int LoadBG(int step);
    void LoadBGAll();
    void SetupBlend();
    void DrawTexts();
    void DrawGauge();
    void Update();
    void Render();
    void ReleaseMessages();

public:
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    OamSpriteSet *unk_28;
    OamSpriteSet *unk_2C;
    OamSpriteSet *unk_30;
    OamSpriteSet *unk_34;
    OamSprite *unk_38;
    UnkClass_020091E8_004 *unk_3C;
    int unk_40;
    int unk_44;
    CArchiveGuard *unk_48;
    CBGNCGRFile *unk_4C;
    CNCLRFile *unk_50;
};

STATIC_SIZE_ASSERT(SubScreenRangerCard, 0x54);

#endif // POKERANGER2_SUBSCREENRANGERCARD_HPP
