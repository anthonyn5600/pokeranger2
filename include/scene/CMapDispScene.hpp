#ifndef POKERANGER2_SCENE_CMAPDISPSCENE_HPP
#define POKERANGER2_SCENE_CMAPDISPSCENE_HPP

#include "CGame.hpp"
#include "common.hpp"
#include "scene/CMapDispScreen.hpp"
#include "scene/CScene.hpp"

// Defined in ov28
class CMapDispScene : public CScene {
public:
    CMapDispScene(CGame *game);
    virtual ~CMapDispScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void Create();

public:
    CGame *m_game;
    CMapDispScreen *unk_08;
};

STATIC_SIZE_ASSERT(CMapDispScene, 0xC);

#endif // POKERANGER2_SCENE_CMAPDISPSCENE_HPP
