#ifndef POKERANGER2_SCENE_CSTYLERSCREENS_HPP
#define POKERANGER2_SCENE_CSTYLERSCREENS_HPP

#include "CGame.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "common.hpp"
#include "scene/CStylerScreen.hpp"

// Upper screen of the styler menu (ov5)
class CStylerUpperScreen : public CStylerScreen {
public:
    CStylerUpperScreen(CGame *game, CStylerData *data);
    virtual ~CStylerUpperScreen();

    virtual void Load();
    virtual void Release();
    virtual void Reset();
    virtual int Update();
    virtual void Render();
    virtual void func7();
    virtual void func8();

    void LoadStatus();
    void SetupBlend();
    void LoadSprites();
    void LoadBG();
    void DrawTexts();
    void DrawGauge();
    void UpdateSprites();

public:
    u32 unk_0C;
    int m_level;
    int m_energy;
    int m_maxEnergy;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    int unk_30;
    int unk_34;
    CStylerData *m_data;
    CGame *m_game;
    UnkClass_020091E8_004 *m_menuMessages;
    UnkClass_0200ECD0 *m_sprites;
    UnkClass_0200ECD0 *m_arrowSprites;
    UnkClass_0200E960 *m_objs[6];
    int m_slots[5];
};

STATIC_SIZE_ASSERT(CStylerUpperScreen, 0x78);

// Styler status screen (ov5)
class CStylerStatusScreen : public CStylerScreen {
public:
    CStylerStatusScreen(CGame *game, CStylerData *data);
    virtual ~CStylerStatusScreen();

    virtual void Load();
    virtual void Release();
    virtual void Reset();
    virtual int Update();
    virtual void Render();
    virtual void func7();
    virtual void func8();

    void LoadData();
    void SetupBG();
    void LoadSprites();
    void LoadBG();
    void DrawTexts();

public:
    int unk_0C;
    u8 m_palette[0x200];
    CStylerData *m_data;
    CGame *m_game;
    UnkClass_0202A2AC *unk_218;
    UnkClass_020091E8_004 *m_menuMessages;
    UnkClass_0200ECD0 *m_sprites;
    UnkClass_0200ECD0 *unk_224;
    UnkClass_0200E960 *m_backButton;
    UnkClass_0200E960 *m_backButtonPressed;
};

STATIC_SIZE_ASSERT(CStylerStatusScreen, 0x230);

// Styler power-up parts screen (ov5)
class CStylerPartsScreen : public CStylerScreen {
public:
    CStylerPartsScreen(CGame *game, CStylerData *data);
    virtual ~CStylerPartsScreen();

    virtual void Load();
    virtual void Release();
    virtual void Reset();
    virtual int Update();
    virtual void Render();
    virtual void func7();
    virtual void func8();

public:
    u8 unk_0C[0x2E4];
};

STATIC_SIZE_ASSERT(CStylerPartsScreen, 0x2F0);

#endif // POKERANGER2_SCENE_CSTYLERSCREENS_HPP
