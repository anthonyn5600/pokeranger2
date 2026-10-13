#ifndef POKERANGER2_SCENE_CCONFSCENE_HPP
#define POKERANGER2_SCENE_CCONFSCENE_HPP

#include "CGame.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

class CPrimitiveSPHERE;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_0201FC80;
class UnkClass_02034478;
class UnkClass_020091E8_004;

// Defined in ov3
class CConfScene : public CScene {
public:
    CConfScene(CGame *game);
    virtual ~CConfScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov3_02121674();
    void ov3_021216A8();
    void ov3_021219BC();
    void ov3_02121A28();
    void ov3_02121B4C(int scale);

public:
    UnkClass_02034478 *m_audioEngine;
    CGame *m_game;
    u16 m_flags;
    u16 unk_0E;
    int unk_10;
    int unk_14;
    fx32 unk_18;
    UnkClass_0201FC80 *unk_1C;
    UnkClass_0200E960 *unk_20;
    UnkClass_0200E960 *unk_24;
    UnkClass_0200ECD0 *unk_28;
    UnkClass_020091E8_004 *unk_2C;
    CPrimitiveSPHERE *unk_30;
    CPrimitiveSPHERE *unk_34;
};

STATIC_SIZE_ASSERT(CConfScene, 0x38);

#endif // POKERANGER2_SCENE_CCONFSCENE_HPP
