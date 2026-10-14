#ifndef POKERANGER2_SCENE_CSTYLERSCREEN_HPP
#define POKERANGER2_SCENE_CSTYLERSCREEN_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "SubScreenButton.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"

// Styler menu data shared by the styler screens (ov5): styler level and the power-up levels from the save
class CStylerData {
public:
    CStylerData(CGame *game);
    ~CStylerData();

    void Init();
    void Release();
    void LoadLevels();
    void LoadMessages();
    void RaiseLevel(int idx, int max);
    void ApplyLevelUp();

public:
    s32 m_level;
    CGame *m_game;
    UnkClass_020091E8_004 *m_menuMessages;
    UnkClass_020091E8_004 *m_assistMessages;
    SubScreenButton *unk_10;
    s32 m_powerLevels[26];
    s32 m_raised[26];
};

STATIC_SIZE_ASSERT(CStylerData, 0xE4);

// Base of the styler menu's screens (ov5)
class CStylerScreen {
public:
    CStylerScreen()
    {
        unk_04 = 0;
        unk_08 = 0;
    }

    virtual ~CStylerScreen()
    {
    }

    virtual void Load() = 0;
    virtual void Release() = 0;

    virtual void Reset()
    {
        unk_04 = 0;
        unk_08 = 0;
    }

    virtual int Update() = 0;
    virtual void Render() = 0;
    virtual void func7() = 0;
    virtual void func8() = 0;

public:
    int unk_04;
    int unk_08;
};

#endif // POKERANGER2_SCENE_CSTYLERSCREEN_HPP
