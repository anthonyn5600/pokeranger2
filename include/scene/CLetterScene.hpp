#ifndef POKERANGER2_SCENE_CLETTERSCENE_HPP
#define POKERANGER2_SCENE_CLETTERSCENE_HPP

#include "CGame.hpp"
#include "OamSpriteSet.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

// Defined in ov4
class CLetterScene : public CScene {
public:
    CLetterScene(CGame *game);
    virtual ~CLetterScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void LoadBG();
    void SetupBG();
    void SetupText();

public:
    CGame *m_game;
    UnkClass_020091E8_004 *m_messages;
    s32 m_chapter;
    u32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
    OamSpriteSet *unk_2C;
};

STATIC_SIZE_ASSERT(CLetterScene, 0x30);

#endif // POKERANGER2_SCENE_CLETTERSCENE_HPP
