#ifndef POKERANGER2_SCENE_CBROWSERSCENE_HPP
#define POKERANGER2_SCENE_CBROWSERSCENE_HPP

#include "common.hpp"
#include "scene/CScene.hpp"

class BrowserScreen;

// Defined in ov21
class CBrowserScene : public CScene {
public:
    CBrowserScene();
    virtual ~CBrowserScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

public:
    u32 unk_0004;
    BrowserScreen *unk_0008;
    u32 unk_000C;
    u32 unk_0010; // state
    u32 unk_0014; // saved visible windows
    GXWndPlane unk_0018; // saved window 0 inside plane
    GXWndPlane unk_0019; // saved outside plane
    OSIrqFunction unk_001C; // saved H-blank handler
};

STATIC_SIZE_ASSERT(CBrowserScene, 0x20);

#endif // POKERANGER2_SCENE_CBROWSERSCENE_HPP
