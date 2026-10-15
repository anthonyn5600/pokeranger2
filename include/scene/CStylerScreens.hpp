#ifndef POKERANGER2_SCENE_CSTYLERSCREENS_HPP
#define POKERANGER2_SCENE_CSTYLERSCREENS_HPP

#include "CGame.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
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
    int m_levelExp;
    int m_nextExp;
    int m_maxEnergy;
    int m_energy;
    int unk_24;
    int m_power;
    int unk_2C;
    int unk_30;
    int unk_34;
    CStylerData *m_data;
    CGame *m_game;
    UnkClass_020091E8_004 *m_menuMessages;
    OamSpriteSet *m_sprites;
    OamSpriteSet *m_arrowSprites;
    OamSprite *m_objs[6];
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
    SubScreenButton *unk_218;
    UnkClass_020091E8_004 *m_menuMessages;
    OamSpriteSet *m_sprites;
    OamSpriteSet *unk_224;
    OamSprite *m_backButton;
    OamSprite *m_backButtonPressed;
};

STATIC_SIZE_ASSERT(CStylerStatusScreen, 0x230);

// Entry of the parts screen's power-up grid: sprite, position, the styler level that unlocks it, the
// CStylerData::m_powerLevels index and the level it shows
struct StylerPartEntry {
    int anim;
    int x;
    int y;
    int unlockLevel;
    int idx;
    int level;
};

// Touchable power-up icon on the parts screen (ov5)
class CStylerPartButton {
public:
    CStylerPartButton()
    {
        m_id = 0;
        m_sprites = NULL;
        m_obj = NULL;
    }

    ~CStylerPartButton()
    {
    }

    void Init(int id, OamSpriteSet *sprites, int anim, int x, int y, BOOL large);
    u8 IsTouched();

public:
    int m_slot;
    int m_id;
    OamSpriteSet *m_sprites;
    OamSprite *m_obj;
};

STATIC_SIZE_ASSERT(CStylerPartButton, 0x10);

// Animated selection frame on the parts screen (ov5)
class CStylerPartCursor {
public:
    CStylerPartCursor()
    {
        m_size = -1;
        m_counter = 0;
        m_frame = 0;
        m_sprites = NULL;
        MI_CpuFill8(m_objs, 0, sizeof(m_objs));
        MI_CpuFill8(m_slots, 0, sizeof(m_slots));
    }

    ~CStylerPartCursor()
    {
    }

    void Init(OamSpriteSet *sprites);
    void Set(int x, int y, int size);
    void Update();

public:
    int m_size;
    int m_slots[2];
    int m_counter;
    int m_frame;
    OamSpriteSet *m_sprites;
    OamSprite *m_objs[2];
};

STATIC_SIZE_ASSERT(CStylerPartCursor, 0x20);

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

    void LoadData();
    void SetupBG();
    void LoadSprites();
    void LoadBG();
    void DrawTexts();
    CStylerPartButton *CreateButton(int id, StylerPartEntry *entry);
    void CreateButtons();
    void UpdateButtons();
    StylerPartEntry *FindEntry(int unlockLevel);

public:
    int m_level;
    StylerPartEntry *m_selected;
    CStylerPartButton *m_selectedButton;
    u8 m_palette[0x200];
    CStylerData *m_data;
    CGame *m_game;
    SubScreenButton *unk_220;
    UnkClass_020091E8_004 *m_menuMessages;
    OamSpriteSet *m_sprites;
    OamSpriteSet *m_cursorSprites;
    CStylerPartButton *m_buttons[47];
    CStylerPartCursor *m_cursor;
};

STATIC_SIZE_ASSERT(CStylerPartsScreen, 0x2F0);

#endif // POKERANGER2_SCENE_CSTYLERSCREENS_HPP
