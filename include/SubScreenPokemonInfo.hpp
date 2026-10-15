#ifndef POKERANGER2_SUBSCREENPOKEMONINFO_HPP
#define POKERANGER2_SUBSCREENPOKEMONINFO_HPP

#include <nitro.h>

#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"

// Sub-screen menu (BGS/PTC archives, data/menu/mt000_bg_LZ.bin): pokemon info, menu and assist messages
// (FieldSubScreen::unk_34)
class SubScreenPokemonInfo {
public:
    SubScreenPokemonInfo();
    ~SubScreenPokemonInfo();

    void Release();
    void Load(int arg0, int arg1, int count);
    void ResetLoad();
    int LoadStep(int arg0, int arg1, int count);
    void LoadBG();
    void LoadPTC();
    void ReleaseBG();
    void SetupBlend();
    void SetPokemon(int arg0, int arg1);
    void LoadSprites();
    void SetupTextWindows();
    int LoadSpritesStep(int step);
    void StartRefresh();
    void DrawTexts();
    void PrintLabels();
    void PrintValues();
    void sub_0201F38C();
    void sub_0201F48C();
    void Update();
    void Render();
    void ReleaseMessages();

public:
    int unk_00;
    int unk_04;
    int unk_08;
    u16 unk_0C;
    u8 unk_0E;
    u16 unk_10;
    u16 unk_12;
    u8 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    int unk_24;
    OamSpriteSet *unk_28;
    OamSpriteSet *unk_2C;
    OamSpriteSet *unk_30;
    OamSpriteSet *unk_34;
    OamSpriteSet *unk_38;
    OamSpriteSet *unk_3C;
    OamSpriteSet *unk_40;
    OamSprite *unk_44;
    UnkClass_020091E8_004 *unk_48;
    UnkClass_020091E8_004 *unk_4C;
    UnkClass_020091E8_004 *unk_50;
    int unk_54;
    CArchiveGuard *unk_58;
    CBGNCGRFile *unk_5C;
    CNCLRFile *unk_60;
    CNSCRFile *unk_64;
    CNSCRFile *unk_68;
    CNSCRFile *unk_6C;
    int unk_70;
    int unk_74;
    int unk_78;
};

STATIC_SIZE_ASSERT(SubScreenPokemonInfo, 0x7C);

#endif // POKERANGER2_SUBSCREENPOKEMONINFO_HPP
