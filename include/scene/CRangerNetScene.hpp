#ifndef POKERANGER2_SCENE_CRANGERNETSCENE_HPP
#define POKERANGER2_SCENE_CRANGERNETSCENE_HPP

#include "CGame.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

class RangerNetMenu; // ov11 Ranger Net menu

// Defined in ov11
class CRangerNetScene : public CScene {
public:
    CRangerNetScene(CGame *game);
    virtual ~CRangerNetScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov11_0211CAE4();

public:
    CGame *m_game;
    RangerNetMenu *unk_08;
};

STATIC_SIZE_ASSERT(CRangerNetScene, 0xC);

#endif // POKERANGER2_SCENE_CRANGERNETSCENE_HPP
