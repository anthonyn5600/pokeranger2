#ifndef POKERANGER2_SCENE_CRECORDSCENE_HPP
#define POKERANGER2_SCENE_CRECORDSCENE_HPP

#include "common.hpp"
#include "scene/CScene.hpp"

class CPrimitiveRECT;
class UnkClass_020091E8_004;
class OamSprite;
class OamSpriteSet;
class AudioEngine;
class SaveData;

// Defined in ov23
// Ranger records menu (two pages, switched with the arrow buttons)
class CRecordScene : public CScene {
public:
    CRecordScene();
    virtual ~CRecordScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov23_0211CBDC();
    void ov23_0211CC44(Point2D touch);
    void ov23_0211CDD4(Point2D touch);
    void ov23_0211D214();
    void ov23_0211D270();
    void ov23_0211D870();
    void ov23_0211DEB8();
    void ov23_0211DEDC();
    void ov23_0211DF00();
    void ov23_0211E19C();
    void ov23_0211E454();
    void ov23_0211E668();
    void ov23_0211E75C();
    void ov23_0211E818(int digits, u32 value);
    void ov23_0211E8A8(int value);
    void ov23_0211E940(int hours, int minutes);
    int ov23_0211EA18(int exp, int base);

public:
    int unk_04; // frame counter
    u32 unk_08; // state
    int unk_0C; // next page
    int unk_10; // pressed buttons (keys)
    int unk_14; // pressed buttons (touch)
    int unk_18; // back button sprite index
    int unk_1C; // right arrow sprite index
    int unk_20; // left arrow sprite index
    char unk_24[0x15]; // number text
    AudioEngine *m_audioEngine;
    OamSprite *unk_40;
    OamSprite *unk_44;
    OamSprite *unk_48;
    OamSpriteSet *unk_4C;
    CPrimitiveRECT *unk_50[3];
    SaveData *m_save;
    UnkClass_020091E8_004 *m_recodeMes;
    UnkClass_020091E8_004 *m_menuMes;
};

STATIC_SIZE_ASSERT(CRecordScene, 0x68);

#endif // POKERANGER2_SCENE_CRECORDSCENE_HPP
