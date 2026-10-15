#ifndef POKERANGER2_SCENE_COPTIONSCENE_HPP
#define POKERANGER2_SCENE_COPTIONSCENE_HPP

#include "CGame.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SubScreenRangerCard.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

// Defined in ov6
class COptionScene : public CScene {
public:
    COptionScene(CGame *game);
    virtual ~COptionScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void LoadBG();
    void SetupBG();
    void DrawTexts();

public:
    OamSpriteSet *m_sprites;
    OamSpriteSet *m_backSprites;
    // 0-2: text speed, 3-10: window frame, 11: frame cursor
    OamSprite *m_buttons[12];
    OamSprite *m_backButton;
    int m_buttonIds[12];
    CGame *m_game;
    int m_fadeTimer;
    u32 unk_78;
    int m_frame;
    int m_textSpeed;
    SubScreenRangerCard *unk_84;
    UnkClass_020091E8_004 *m_messages;
};

STATIC_SIZE_ASSERT(COptionScene, 0x8C);

#endif // POKERANGER2_SCENE_COPTIONSCENE_HPP
