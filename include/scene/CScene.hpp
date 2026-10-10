#ifndef POKERANGER2_SCENE_CSCENE_HPP
#define POKERANGER2_SCENE_CSCENE_HPP

#include <nitro.h>

class CScene {
public:
    CScene();
    virtual ~CScene();

    virtual u32 func0() = 0;
    virtual void func1() = 0;
    virtual void func2();
    virtual void func3();
    virtual void func4();
    virtual void func5() = 0;
    virtual void func6() = 0;
    virtual void func7() = 0;
    virtual u32 getSceneId() = 0;
};

#endif // POKERANGER2_SCENE_CSCENE_HPP
