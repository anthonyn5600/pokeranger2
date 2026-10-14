#ifndef POKERANGER2_SCENE_CQUESTLISTSCENE_HPP
#define POKERANGER2_SCENE_CQUESTLISTSCENE_HPP

#include <nnsys.h>

#include "Camera2D.hpp"
#include "UnkClass_02040F34.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "scene/CScene.hpp"

class CBinaryFileMes;
class CGame;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_02021404;
class UnkClass_0202A510;
class UnkClass_02041C80;

// Defined in ov27
class CQuestListScreenBase {
public:
    CQuestListScreenBase()
    {
        unk_04 = 0;
    }
    virtual ~CQuestListScreenBase()
    {
    }

    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3(int prev) = 0;
    virtual int func4() = 0;
    virtual void func5() = 0;
    virtual void func6()
    {
    }
    virtual void func7()
    {
    }

public:
    int unk_04;
};

class IQLPushButtonListener {
public:
    virtual void OnPushButton(int id, BOOL repeat) = 0;
    virtual void OnReleaseButton(int id) = 0;
};

class IQLListBoxEventListener {
public:
    virtual void OnListBoxEvent0(int id, int idx) = 0;
    virtual void OnListBoxEvent1(int id, int cursor, u32 flags, u8 changed) = 0;
    virtual void OnListBoxEvent2() = 0;
};

// Quest giver and place per quest
struct UnkStruct_021213AC {
    u16 actorId;
    u16 placeId;
};

// One quest list entry
struct UnkStruct_0211DE28 {
    const char *unk_00; // title
    int unk_04; // 0 = open, 1 = cleared, 2 = current
    int unk_08; // quest id
};

STATIC_SIZE_ASSERT(UnkStruct_0211DE28, 0xC);

// Defined in ov27
// Message file split into its strings
class UnkClass_0211FA5C {
public:
    UnkClass_0211FA5C();
    ~UnkClass_0211FA5C();

    int ov27_0211FA84(const char *path);
    const char *ov27_0211FB38(int idx);
    void ov27_0211FB5C();

public:
    CBinaryFileMes *unk_00;
    int unk_04; // count
    const char **unk_08;
};

STATIC_SIZE_ASSERT(UnkClass_0211FA5C, 0xC);

// Defined in ov27
// Three blinking marks (shown while the current quest is in the list)
class UnkClass_0211F8A0 {
public:
    UnkClass_0211F8A0();

    BOOL ov27_0211F8C8(UnkClass_0200ECD0 *anims, int animOff, int animOn, int x, int y, int priority);
    void ov27_0211F954(BOOL enabled);
    void ov27_0211F9C0();

public:
    u8 unk_00; // enabled
    u8 unk_01; // timer
    struct {
        UnkClass_0200E960 *on;
        UnkClass_0200E960 *off;
    } unk_04[3];
};

STATIC_SIZE_ASSERT(UnkClass_0211F8A0, 0x1C);

// Defined in ov27
// One list box group
class UnkClass_0211E7EC {
public:
    UnkClass_0211E7EC();

public:
    int unk_00; // line count
    UnkStruct_0211DE28 *unk_04; // lines
    int unk_08; // saved top line
    int unk_0C; // saved cursor line
};

STATIC_SIZE_ASSERT(UnkClass_0211E7EC, 0x10);

// Defined in ov27
class CQLListBox {
public:
    CQLListBox(int count);
    virtual ~CQLListBox();

    BOOL ov27_0211E958(int id, UnkClass_0200ECD0 *anims, int animCursor, int animNormal, int animCleared, int animCurrent, int x, int y, int w, int h, int argA, int argB, int argC, void *rows);
    void ov27_0211EACC();
    void ov27_0211EB84(int group, UnkStruct_0211DE28 *lines, int count);
    int ov27_0211EBB8();
    void ov27_0211EBEC(int line);
    void ov27_0211EC68();
    void ov27_0211ED84();
    void ov27_0211EE28();
    void ov27_0211EEB8();
    void ov27_0211EF30();
    void ov27_0211EFC4(int dy, int line);
    void ov27_0211F140();
    void ov27_0211F294();
    void ov27_0211F470(BOOL down);
    void ov27_0211F4B0(int group);
    void ov27_0211F574(int line);
    int ov27_0211F648(int group);
    void ov27_0211F674();
    void ov27_0211F714(u8 changed);

    void SetListener(IQLListBoxEventListener *listener)
    {
        unk_3C = listener;
    }

public:
    int unk_04; // id
    int unk_08; // x
    int unk_0C; // y
    int unk_10; // width
    int unk_14; // height
    int unk_18; // group
    int unk_1C; // top line
    int unk_20; // target top line
    int unk_24; // mark x
    int unk_28; // cursor x
    int unk_2C; // cursor y
    int unk_30; // target cursor y
    int unk_34; // BG scroll
    int unk_38; // BG scroll for the raster alarms
    IQLListBoxEventListener *unk_3C;
    UnkClass_0200E960 *unk_40; // cursor
    u8 unk_44; // blink timer
    UnkClass_0200E960 *unk_48[8]; // open marks
    UnkClass_0200E960 *unk_68[8]; // cleared marks
    UnkClass_0200E960 *unk_88; // current mark
    int unk_8C; // group count
    UnkClass_0211E7EC *unk_90;
    u8 unk_94[0x80]; // BG3 row for the current quest
    u8 unk_114[0x80]; // BG3 row for other quests
    u8 unk_194; // lines need redrawing
};

STATIC_SIZE_ASSERT(CQLListBox, 0x198);

// Defined in ov27
// Loads cell animation sets into consecutive OBJ char/palette slots
class UnkClass_0211E2A4 {
public:
    UnkClass_0211E2A4();

    UnkClass_0200ECD0 *ov27_0211E2B8(const char *dir, const char *name, int plttCount, int oamIdx);
    void ov27_0211E374(UnkClass_0200ECD0 *anims, int oamIdx);

public:
    u32 unk_00; // char offset
    u32 unk_04; // palette slot
    int unk_08; // next oam index
};

STATIC_SIZE_ASSERT(UnkClass_0211E2A4, 0xC);

// Defined in ov27
// Push button made of two cell animations (normal, pressed); type 1 = blinking toggle
class UnkClass_0211E394 {
public:
    UnkClass_0211E394()
    {
        unk_00 = 0;
        unk_04 = -1;
        unk_10 = NULL;
        unk_14 = 0;
        unk_18 = 0;
        unk_1C = 0;
        unk_20 = 0;
        unk_24 = 0;
        unk_28 = 0;
        unk_2C = 0;
        unk_30 = TRUE;
        MI_CpuClear8(unk_08, sizeof(unk_08));
    }

    BOOL ov27_0211E394(int id, UnkClass_0200ECD0 *anims, int animNormal, int animPressed, int x, int y, int w, int h, int priority, int type);
    void ov27_0211E438();
    void ov27_0211E460();
    void ov27_0211E598();
    void ov27_0211E64C();
    void ov27_0211E688();
    void ov27_0211E708();
    void ov27_0211E7CC();

public:
    int unk_00; // type
    int unk_04; // id
    UnkClass_0200E960 *unk_08[2]; // normal, pressed
    IQLPushButtonListener *unk_10;
    int unk_14; // repeat timer
    int unk_18; // touching
    int unk_1C; // touching last frame
    int unk_20; // held
    int unk_24; // held last frame
    int unk_28; // blink frames
    int unk_2C; // blink phase
    u8 unk_30; // enabled
};

STATIC_SIZE_ASSERT(UnkClass_0211E394, 0x34);

// Defined in ov27
// Quest giver portrait and quest info on the main screen; a thread swaps the giver actor
class UnkClass_021205AC {
public:
    UnkClass_021205AC();
    ~UnkClass_021205AC();

    void ov27_0212062C();
    void ov27_021206B4();
    void ov27_02120748();
    void ov27_02120754();
    void ov27_02120758();
    void ov27_021207E4();
    void ov27_02120870(BOOL noInfo);
    BOOL ov27_02120CA8(UnkClass_0211FA5C *info, int questId, BOOL notCleared);
    BOOL ov27_02120CC4(BOOL noInfo);
    void ov27_02120CD4();
    void ov27_02120E70(int questId);

public:
    int unk_0000; // shown quest
    u8 unk_0004;
    u8 unk_0005; // quest not cleared yet
    int unk_0008; // quest to show (-1 = none)
    Camera2D *unk_000C;
    UnkClass_0200ECD0 *unk_0010;
    UnkClass_0200E960 *unk_0014[6];
    UnkClass_0211FA5C *unk_002C; // quest info
    CFieldActor unk_0030[2];
    u8 unk_01F0; // current actor
    u8 unk_01F1; // has a quest
    UnkClass_02040F34 unk_01F4;
    OSThread unk_01FC;
    u8 unk_02BC[0x1000]; // thread stack
    OSMessageQueue unk_12BC;
    OSMessage unk_12DC[1];
};

STATIC_SIZE_ASSERT(UnkClass_021205AC, 0x12E0);

class CQuestListScreen : public CQuestListScreenBase, public IQLPushButtonListener, public IQLListBoxEventListener {
public:
    CQuestListScreen(UnkClass_021205AC *map);
    virtual ~CQuestListScreen();

    virtual void func0();
    virtual void func1();
    virtual void func2();
    virtual void func3(int prev);
    virtual int func4();
    virtual void func5();
    virtual void func7();
    virtual void OnPushButton(int id, BOOL repeat);
    virtual void OnReleaseButton(int id);
    virtual void OnListBoxEvent0(int id, int idx);
    virtual void OnListBoxEvent1(int id, int cursor, u32 flags, u8 changed);
    virtual void OnListBoxEvent2();

    void ov27_0211D0E0();
    void ov27_0211D150();
    void ov27_0211DB4C();
    void ov27_0211DBB4();
    void ov27_0211DC64();
    void ov27_0211DDC0();
    void ov27_0211DE28();
    int ov27_0211E204();

public:
    struct {
        void *data;
        u32 size;
    } unk_010[5]; // char, palette, screens (BG7, BG6, BG5)
    UnkClass_0211E2A4 unk_038;
    UnkClass_0200ECD0 *unk_044;
    UnkClass_0200ECD0 *unk_048;
    UnkClass_0211E394 unk_04C[6]; // left, right, up, down, A, back
    CQLListBox unk_184;
    UnkClass_0211F8A0 unk_31C;
    int unk_338; // quest count
    UnkClass_0211FA5C *unk_33C; // quest infos
    UnkClass_0211FA5C unk_340;
    UnkStruct_0211DE28 *unk_34C;
    int unk_350; // saved sub BG mode
    int unk_354; // saved sub visible windows
    GXWndPlane unk_358; // saved sub window 0 inside plane
    GXWndPlane unk_359; // saved sub outside plane
    UnkClass_021205AC *unk_35C;
    u8 unk_360;
};

STATIC_SIZE_ASSERT(CQuestListScreen, 0x364);

// Defined in ov27
// Quest place map on the sub screen (twin of ov8's UnkClass_0211CD00)
class UnkClass_0211FBA4 {
public:
    UnkClass_0211FBA4(CGame *game);
    ~UnkClass_0211FBA4();

    void ov27_0211FBD0();
    BOOL ov27_0211FC2C();
    void ov27_0211FCE4();
    void ov27_0211FD34();
    void ov27_0211FD58();
    void ov27_0211FD70();
    void ov27_0211FE2C();
    void ov27_0211FE58();
    void ov27_02120068();
    void ov27_02120128();
    void ov27_021201AC(u16 idx);
    BOOL ov27_021201DC();
    void ov27_0212020C();
    void ov27_021202F8();
    void ov27_0212032C(u16 id);
    void ov27_0212033C();
    void ov27_02120410(u16 idx);
    void ov27_02120444(int idx, u16 id);
    void ov27_02120490();
    void ov27_021204B4();
    void ov27_021204E0(u16 id);
    void ov27_02120504(u16 id, int mode);
    void ov27_02120514();
    void ov27_0212053C();
    BOOL ov27_02120564();

public:
    u16 unk_00; // state
    int unk_04; // text needs redraw
    UnkClass_0202A510 *unk_08;
    UnkClass_02041C80 *unk_0C;
    UnkClass_02021404 *unk_10; // place names
    UnkClass_0200ECD0 *unk_14;
    UnkClass_0200ECD0 *unk_18;
    u32 unk_1C;
    UnkClass_0200E960 *unk_20[5]; // quest place mark, -, back button
    u16 unk_34; // shown place
    u16 unk_36; // quest place
    CGame *unk_38;
};

STATIC_SIZE_ASSERT(UnkClass_0211FBA4, 0x3C);

class CQuestListMapScreen : public CQuestListScreenBase {
public:
    CQuestListMapScreen();
    virtual ~CQuestListMapScreen();

    virtual void func0();
    virtual void func1();
    virtual void func2();
    virtual void func3(int prev);
    virtual int func4();
    virtual void func5();
    virtual void func6();

public:
    UnkClass_0211FBA4 *unk_08;
    int unk_0C; // selected quest
};

STATIC_SIZE_ASSERT(CQuestListMapScreen, 0x10);

class CQuestListScene : public CScene {
public:
    CQuestListScene();
    virtual ~CQuestListScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

public:
    int unk_004; // current screen
    CQuestListScreenBase *unk_008[2];
    CQuestListScreen unk_010;
    CQuestListMapScreen unk_374;
    UnkClass_021205AC unk_384;
};

STATIC_SIZE_ASSERT(CQuestListScene, 0x1664);

#endif // POKERANGER2_SCENE_CQUESTLISTSCENE_HPP
