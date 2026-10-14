#ifndef POKERANGER2_SCENE_CSEXSELECTSCENE_HPP
#define POKERANGER2_SCENE_CSEXSELECTSCENE_HPP

#include "common.hpp"
#include "scene/CScene.hpp"

class CGame;
class Camera2D;
class CPrimitiveRECT;
class CSoftwareSprite;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_0201AAE0;
class UnkClass_0201FC80;
class UnkClass_02034478;

// Defined in ov19
class CSexSelectScene : public CScene {
public:
    CSexSelectScene();
    virtual ~CSexSelectScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov19_0211CD54();
    void ov19_0211CDA0();
    void ov19_0211CFC0();
    void ov19_0211D070();
    void ov19_0211D17C();
    void ov19_0211D300();
    void ov19_0211D4A0();
    void ov19_0211D540();
    void ov19_0211D9B0();
    void ov19_0211DAE8();
    void ov19_0211DC24();
    void ov19_0211DD7C();
    void ov19_0211DE04();
    void ov19_0211DEF8();
    void ov19_0211DF74();
    void ov19_0211DFD8();
    void ov19_0211E140();
    void ov19_0211E16C();
    void ov19_0211E1A0();
    void ov19_0211E1D0();
    void ov19_0211E200();
    void ov19_0211E270();
    void ov19_0211E308();

public:
    u16 unk_04; // state
    u16 unk_06; // selection: 1 boy, 2 girl
    u16 unk_08; // frame counter
    u16 unk_0A; // fade alpha
    u16 unk_0C;
    u16 unk_0E;
    int unk_10;
    int unk_14;
    UnkClass_02034478 *m_audioEngine;
    CGame *m_game;
    Camera2D *unk_20;
    UnkClass_0201FC80 *unk_24[2];
    UnkClass_0201AAE0 *unk_2C[4];
    UnkClass_0200ECD0 *unk_3C[5];
    UnkClass_0200E960 *unk_50[6];
    CSoftwareSprite *unk_68;
    CPrimitiveRECT *unk_6C;
    CPrimitiveRECT *unk_70[3];
};

STATIC_SIZE_ASSERT(CSexSelectScene, 0x7C);

#endif // POKERANGER2_SCENE_CSEXSELECTSCENE_HPP
