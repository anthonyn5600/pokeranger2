#ifndef POKERANGER2_SCENE_CSTYLERSCENE_HPP
#define POKERANGER2_SCENE_CSTYLERSCENE_HPP

#include "CGame.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"
#include "scene/CStylerScreen.hpp"

// Defined in ov5
class CStylerScene : public CScene {
public:
    CStylerScene(CGame *game);
    virtual ~CStylerScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

public:
    u32 unk_04;
    u32 unk_08;
    s32 m_screenIdx;
    CGame *m_game;
    CStylerData *m_data;
    CStylerScreen *m_upper;
    CStylerScreen *m_screens[2];
};

STATIC_SIZE_ASSERT(CStylerScene, 0x24);

#endif // POKERANGER2_SCENE_CSTYLERSCENE_HPP
