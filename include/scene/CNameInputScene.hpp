#ifndef POKERANGER2_SCENE_CNAMEINPUTSCENE_HPP
#define POKERANGER2_SCENE_CNAMEINPUTSCENE_HPP

#include "CGame.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

class CPrimitiveRECT;
class OamSprite;
class OamSpriteSet;
class UnkClass_020091E8_004;
class AudioEngine;

// Defined in ov3
class CNameInputScene : public CScene {
public:
    CNameInputScene();
    virtual ~CNameInputScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov3_02121E44(int page);
    void ov3_02122264(u8 pos);
    void ov3_021222A0();
    void ov3_02122340(int pos, int page, int idx);
    BOOL ov3_021223FC();
    void ov3_02122688();
    void ov3_02122A8C();
    void ov3_02122B7C();
    void ov3_02122BCC();
    void ov3_02122E68();
    void ov3_02123014();
    void ov3_021231F4();
    void ov3_0212351C();
    void ov3_0212362C(int mode);
    void ov3_02123654();
    void ov3_02123878();
    void ov3_021239A8();
    void ov3_02123DC0();
    u16 ov3_02123E0C();
    void ov3_02123E84(int idx, int x, int y, int color, int c);
    void ov3_02123F8C();

public:
    u8 unk_0004; // name length (cursor)
    u8 unk_0005; // keyboard page
    u8 unk_0006;
    u8 unk_0007; // cursor blink timer
    u8 unk_0008; // cursor blink state
    u32 unk_000C;
    int unk_0010; // state
    int unk_0014; // next state
    int unk_0018;
    int unk_001C;
    int unk_0020;
    int unk_0024;
    int unk_0028;
    int unk_002C;
    u32 unk_0030[7]; // key per character: page << 24 | key index
    int unk_004C[7]; // UTF-8 bytes per character, big endian
    char unk_0068[22];
    CGame *m_game;
    AudioEngine *m_audioEngine;
    u32 unk_0088;
    OamSprite *unk_008C;
    OamSprite *unk_0090;
    OamSprite *unk_0094;
    OamSprite *unk_0098;
    OamSprite *unk_009C;
    OamSprite *unk_00A0;
    OamSprite *unk_00A4;
    OamSprite *unk_00A8;
    OamSprite *unk_00AC;
    OamSprite *unk_00B0;
    OamSprite *unk_00B4;
    OamSprite *unk_00B8;
    OamSpriteSet *unk_00BC[4];
    CPrimitiveRECT *unk_00CC[0x44]; // 60 keys, then the buttons
    UnkClass_020091E8_004 *unk_01DC;
};

STATIC_SIZE_ASSERT(CNameInputScene, 0x1E0);

#endif // POKERANGER2_SCENE_CNAMEINPUTSCENE_HPP
