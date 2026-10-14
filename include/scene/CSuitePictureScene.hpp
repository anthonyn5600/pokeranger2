#ifndef POKERANGER2_SCENE_CSUITEPICTURESCENE_HPP
#define POKERANGER2_SCENE_CSUITEPICTURESCENE_HPP

#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

struct SuitePictureMsg {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
};

struct SuitePicture {
    s32 id;
    s32 unk_04;
    const SuitePictureMsg *msgs;
    s32 unk_0C;
    s32 unk_10;
};

// Defined in ov26
class CSuitePictureScene : public CScene {
public:
    CSuitePictureScene();
    virtual ~CSuitePictureScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov26_0211D3C0(int id);

public:
    int unk_0004; // frame counter
    u32 unk_0008; // state
    OamSpriteSet *unk_000C;
    OamSprite *unk_0010;
    const SuitePictureMsg *unk_0014;
    const SuitePicture *unk_0018;
    int unk_001C; // frames to show (< 0: skip the wait for input)
    int unk_0020;
};

STATIC_SIZE_ASSERT(CSuitePictureScene, 0x24);

#endif // POKERANGER2_SCENE_CSUITEPICTURESCENE_HPP
