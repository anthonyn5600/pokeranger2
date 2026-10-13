#ifndef POKERANGER2_SCENE_CCONTINUESCENE_HPP
#define POKERANGER2_SCENE_CCONTINUESCENE_HPP

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

    void ov3_02120CF4();
    void ov3_02120D90(int sel);
    void ov3_021210A4();
    void ov3_02121110();
    void ov3_02121234(int scale);

public:
    UnkClass_02034478 *m_audioEngine;
    CGame *m_game;
    u16 m_flags;
    u16 unk_0E;
    u16 unk_10;
    int unk_14;
    int unk_18;
    fx32 unk_1C;
    UnkClass_0201FC80 *unk_20;
    UnkClass_0200E960 *unk_24;
    UnkClass_0200E960 *unk_28;
    UnkClass_0200ECD0 *unk_2C;
    UnkClass_020091E8_004 *unk_30;
    CPrimitiveSPHERE *unk_34;
    CPrimitiveSPHERE *unk_38;
};

STATIC_SIZE_ASSERT(CContinueScene, 0x3C);

#endif // POKERANGER2_SCENE_CCONTINUESCENE_HPP
