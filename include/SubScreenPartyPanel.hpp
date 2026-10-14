#ifndef POKERANGER2_SUBSCREENPARTYPANEL_HPP
#define POKERANGER2_SUBSCREENPARTYPANEL_HPP

#include <nitro.h>

#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"

// Sub-screen party panel (BGS archive, data/menu/mc000_bg_LZ.bin): the leader and the partner Pokémon that follow
// the player, with their names and icons (FieldSubScreen::unk_30)
class SubScreenPartyPanel {
public:
    SubScreenPartyPanel();
    ~SubScreenPartyPanel();

    void Release();
    void LoadPanel();
    void Load();
    void SetupBG();
    void SetupBlend();
    void DrawTexts();
    void Update();
    void Render();

public:
    u32 unk_00[8]; // [0] = the leader's kind, then the partners'
    int unk_20; // has a leader
    int unk_24;
    int unk_28; // partner count
    int unk_2C;
    u16 unk_30[8];
    u8 unk_40[8];
    u8 unk_48[8];
    OamSpriteSet *unk_50;
    OamSpriteSet *unk_54;
    OamSpriteSet *unk_58;
    OamSprite *unk_5C;
    CBGNCGRFile *unk_60;
    CNCLRFile *unk_64;
    CNSCRFile *unk_68;
    CNSCRFile *unk_6C;
    CNSCRFile *unk_70;
    UnkClass_020091E8_004 *unk_74;
};

STATIC_SIZE_ASSERT(SubScreenPartyPanel, 0x78);

#endif // POKERANGER2_SUBSCREENPARTYPANEL_HPP
