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

    void OpenPage();
    void UpdatePage1Input(Point2D touch);
    void UpdatePage2Input(Point2D touch);
    void DrawPage();
    void DrawPage1();
    void DrawPage2();
    void ShowPage1Buttons();
    void ShowPage2Buttons();
    void ClearNumberText();
    void LoadBG();
    void LoadMessages();
    void LoadSprites();
    void CreateTouchRects();
    void FormatNumber(int digits, u32 value);
    void FormatQuestCount(int value);
    void FormatPlayTime(int hours, int minutes);
    int Pow(int exp, int base);

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
