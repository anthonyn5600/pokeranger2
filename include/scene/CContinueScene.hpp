#ifndef POKERANGER2_SCENE_CCONTINUESCENE_HPP
#define POKERANGER2_SCENE_CCONTINUESCENE_HPP

#include "CGame.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

class CPrimitiveSPHERE;
class OamSprite;
class OamSpriteSet;
class BGLayer;
class AudioEngine;
class UnkClass_020091E8_004;

// Defined in ov3
class CContinueScene : public CScene {
public:
    CContinueScene(CGame *game);
    virtual ~CContinueScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void InitMessageWindow();
    void DrawMessage(int sel);
    void LoadSprites();
    void CreateYesNoButtons();
    void SetButtonScale(int scale);

public:
    AudioEngine *m_audioEngine;
    CGame *m_game;
    u16 m_flags;
    u16 unk_0E;
    u16 unk_10;
    int unk_14;
    int unk_18;
    fx32 unk_1C;
    BGLayer *unk_20;
    OamSprite *unk_24;
    OamSprite *unk_28;
    OamSpriteSet *unk_2C;
    UnkClass_020091E8_004 *unk_30;
    CPrimitiveSPHERE *unk_34;
    CPrimitiveSPHERE *unk_38;
};

STATIC_SIZE_ASSERT(CContinueScene, 0x3C);

#endif // POKERANGER2_SCENE_CCONTINUESCENE_HPP
