#ifndef POKERANGER2_SCENE_CSTAFFROLLSCENE_HPP
#define POKERANGER2_SCENE_CSTAFFROLLSCENE_HPP

#include <nnsys.h>

#include "common.hpp"
#include "scene/CScene.hpp"

class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_0201FC80;
class UnkClass_02021404;

// Defined in ov25
// Loads one ending picture into a BG and uploads it to VRAM over several frames
class UnkClass_0211D4E4 {
public:
    UnkClass_0211D4E4();
    ~UnkClass_0211D4E4();

    void ov25_0211D514();
    BOOL ov25_0211D548();
    void ov25_0211D5DC();
    void ov25_0211D5EC(const char *dir, const char *name, const char *file, u32 charOffset, u32 plttNo);
    void ov25_0211D6A8(int bg, int steps);

public:
    u16 unk_00; // state
    UnkClass_0201FC80 *unk_04;
    int unk_08; // upload step
    int unk_0C; // upload steps
    int unk_10;
};

STATIC_SIZE_ASSERT(UnkClass_0211D4E4, 0x14);

// Defined in ov25
// Text BG drawn with an NNS char canvas, scrolled through a ring of 32 tile rows
class UnkClass_0211D6D4 {
public:
    UnkClass_0211D6D4();
    ~UnkClass_0211D6D4();

    void ov25_0211D6FC(NNSG2dFont *font);
    void ov25_0211D704();
    void ov25_0211D758(int bg, int scrBase, int charBase, int plttNo, int priority);
    void ov25_0211DBBC(int x, int y, int color, const char *str, int align);
    void ov25_0211DD14();
    void ov25_0211DD30(int x, int y);

public:
    NNSG2dFont *unk_00;
    NNSG2dCharCanvas *unk_04;
    NNSG2dTextCanvas *unk_08;
    int unk_0C; // bg (0..3 main, 4..7 sub)
    int unk_10; // screen base
    int unk_14; // char base
    int unk_18; // palette
    u16 *unk_1C; // screen ring
    int unk_20; // scroll x (tiles)
    int unk_24; // scroll y (tiles)
};

STATIC_SIZE_ASSERT(UnkClass_0211D6D4, 0x28);

// Defined in ov25
// Ending pictures on two BGs with fade/blend/wipe transitions between them
class UnkClass_0211E0BC {
public:
    UnkClass_0211E0BC();
    ~UnkClass_0211E0BC();

    void ov25_0211E108(int count, int bg0, int bg1);
    void ov25_0211E174();
    void ov25_0211E1B0();
    void ov25_0211EFFC(int idx, const char *dir, const char *name, const char *file, u32 charOffset, u32 plttNo);
    void ov25_0211F048(int idx, int steps, int type, int duration, int outType, int outDuration);
    void ov25_0211F16C(int type, int duration);
    void ov25_0211F1D4(int bg);
    void ov25_0211F344(int bg);
    void ov25_0211F4C0(int bg, int priority);
    void ov25_0211F5CC(int bg, int x, int y);

public:
    UnkClass_0211D4E4 *unk_00;
    int unk_04; // picture count
    u32 unk_08; // state
    int unk_0C; // frame
    int unk_10; // transition in
    int unk_14; // transition out
    int unk_18; // duration in
    int unk_1C; // duration out
    int unk_20[2]; // bgs
    int unk_28; // current bg index
    UnkClass_0211D4E4 *unk_2C; // loading picture
};

STATIC_SIZE_ASSERT(UnkClass_0211E0BC, 0x30);

// Defined in ov25
// "The End" sprites
class UnkClass_0211F71C {
public:
    UnkClass_0211F71C();
    ~UnkClass_0211F71C();

    BOOL ov25_0211F750();
    BOOL ov25_0211F840();
    BOOL ov25_0211F890();
    BOOL ov25_0211FA20();
    BOOL ov25_0211FA54();

public:
    UnkClass_0200ECD0 *unk_00;
    UnkClass_0200E960 *unk_04;
    UnkClass_0200E960 *unk_08;
    UnkClass_0200E960 *unk_0C;
    int unk_10; // state
    int unk_14; // frame
};

STATIC_SIZE_ASSERT(UnkClass_0211F71C, 0x18);

// Defined in ov25
class CStaffrollScene : public CScene {
public:
    CStaffrollScene();
    virtual ~CStaffrollScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

public:
    int unk_04; // state
    fx32 unk_08; // scroll
    fx32 unk_0C; // scroll speed
    UnkClass_0211D6D4 *unk_10; // sub screen text
    UnkClass_0211D6D4 *unk_14; // main screen text
    UnkClass_02021404 *unk_18; // staff roll strings
    int unk_1C;
    int unk_20;
    UnkClass_0211E0BC *unk_24;
    UnkClass_0211F71C *unk_28;
    int unk_2C; // frame
    int unk_30;
};

STATIC_SIZE_ASSERT(CStaffrollScene, 0x34);

#endif // POKERANGER2_SCENE_CSTAFFROLLSCENE_HPP
