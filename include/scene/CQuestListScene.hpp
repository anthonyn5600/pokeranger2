#ifndef POKERANGER2_SCENE_CQUESTLISTSCENE_HPP
#define POKERANGER2_SCENE_CQUESTLISTSCENE_HPP

#include <nnsys.h>

#include "Camera2D.hpp"
#include "FieldDrawActorDataPool.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "scene/CScene.hpp"

class CBinaryFileMes;
class CGame;
class OamSprite;
class OamSpriteSet;
class MessageTable;
class RegionMap;
class FieldData;

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
struct QuestGiverActor {
    u16 actorId;
    u16 placeId;
};

// One quest list entry
struct QLListLine {
    const char *unk_00; // title
    int unk_04; // 0 = open, 1 = cleared, 2 = current
    int unk_08; // quest id
};

STATIC_SIZE_ASSERT(QLListLine, 0xC);

// Defined in ov27
// Message file split into its strings
class QLMessageStrings {
public:
    QLMessageStrings();
    ~QLMessageStrings();

    int Load(const char *path);
    const char *GetString(int idx);
    void Release();

public:
    CBinaryFileMes *unk_00;
    int unk_04; // count
    const char **unk_08;
};

STATIC_SIZE_ASSERT(QLMessageStrings, 0xC);

// Defined in ov27
// Three blinking marks (shown while the current quest is in the list)
class QLBlinkMarks {
public:
    QLBlinkMarks();

    BOOL Init(OamSpriteSet *anims, int animOff, int animOn, int x, int y, int priority);
    void SetEnabled(BOOL enabled);
    void Update();

public:
    u8 unk_00; // enabled
    u8 unk_01; // timer
    struct {
        OamSprite *on;
        OamSprite *off;
    } unk_04[3];
};

STATIC_SIZE_ASSERT(QLBlinkMarks, 0x1C);

// Defined in ov27
// One list box group
class QLListBoxGroup {
public:
    QLListBoxGroup();

public:
    int unk_00; // line count
    QLListLine *unk_04; // lines
    int unk_08; // saved top line
    int unk_0C; // saved cursor line
};

STATIC_SIZE_ASSERT(QLListBoxGroup, 0x10);

// Defined in ov27
class CQLListBox {
public:
    CQLListBox(int count);
    virtual ~CQLListBox();

    BOOL Init(int id, OamSpriteSet *anims, int animCursor, int animNormal, int animCleared, int animCurrent, int x, int y, int w, int h, int argA, int argB, int argC, void *rows);
    void Start();
    void SetGroupLines(int group, QLListLine *lines, int count);
    int GetCursor();
    void SetCursor(int line);
    void CursorDown();
    void CursorUp();
    void PageDown();
    void PageUp();
    void Refresh();
    void PlaceLineSprites(int dy, int line);
    void UpdateInput();
    void UpdateScroll();
    void UpdateLineSprites(BOOL down);
    void SelectGroup(int group);
    void DrawLine(int line);
    int GetLineCount(int group);
    void ApplyScroll();
    void NotifyCursor(u8 changed);

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
    OamSprite *unk_40; // cursor
    u8 unk_44; // blink timer
    OamSprite *unk_48[8]; // open marks
    OamSprite *unk_68[8]; // cleared marks
    OamSprite *unk_88; // current mark
    int unk_8C; // group count
    QLListBoxGroup *unk_90;
    u8 unk_94[0x80]; // BG3 row for the current quest
    u8 unk_114[0x80]; // BG3 row for other quests
    u8 unk_194; // lines need redrawing
};

STATIC_SIZE_ASSERT(CQLListBox, 0x198);

// Defined in ov27
// Loads cell animation sets into consecutive OBJ char/palette slots
class QLAnimLoader {
public:
    QLAnimLoader();

    OamSpriteSet *Load(const char *dir, const char *name, int plttCount, int oamIdx);
    void ReserveOam(OamSpriteSet *anims, int oamIdx);

public:
    u32 unk_00; // char offset
    u32 unk_04; // palette slot
    int unk_08; // next oam index
};

STATIC_SIZE_ASSERT(QLAnimLoader, 0xC);

// Defined in ov27
// Push button made of two cell animations (normal, pressed); type 1 = blinking toggle
class QLPushButton {
public:
    QLPushButton()
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

    BOOL Init(int id, OamSpriteSet *anims, int animNormal, int animPressed, int x, int y, int w, int h, int priority, int type);
    void Update();
    void UpdateNormal();
    void UpdateBlink();
    void UpdateAnim();
    void UpdateAnimNormal();
    void UpdateAnimBlink();
    void ResetInput();

public:
    int unk_00; // type
    int unk_04; // id
    OamSprite *unk_08[2]; // normal, pressed
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

STATIC_SIZE_ASSERT(QLPushButton, 0x34);

// Defined in ov27
// Quest giver portrait and quest info on the main screen; a thread swaps the giver actor
class QuestGiverInfo {
public:
    QuestGiverInfo();
    ~QuestGiverInfo();

    void Init();
    void Update();
    void Render();
    void OnVBlank();
    void Release();
    void Draw();
    void Load(BOOL noInfo);
    BOOL SetQuest(QLMessageStrings *info, int questId, BOOL notCleared);
    BOOL Setup(BOOL noInfo);
    void DrawTexts();
    void LoadGiver(int questId);

public:
    int unk_0000; // shown quest
    u8 unk_0004;
    u8 unk_0005; // quest not cleared yet
    int unk_0008; // quest to show (-1 = none)
    Camera2D *unk_000C;
    OamSpriteSet *unk_0010;
    OamSprite *unk_0014[6];
    QLMessageStrings *unk_002C; // quest info
    CFieldActor unk_0030[2];
    u8 unk_01F0; // current actor
    u8 unk_01F1; // has a quest
    FieldDrawActorDataPool unk_01F4;
    OSThread unk_01FC;
    u8 unk_02BC[0x1000]; // thread stack
    OSMessageQueue unk_12BC;
    OSMessage unk_12DC[1];
};

STATIC_SIZE_ASSERT(QuestGiverInfo, 0x12E0);

class CQuestListScreen : public CQuestListScreenBase, public IQLPushButtonListener, public IQLListBoxEventListener {
public:
    CQuestListScreen(QuestGiverInfo *map);
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

    void SaveSubDisplay();
    void RestoreSubDisplay();
    void Exit();
    void SetupBG();
    void LoadBG();
    void LoadBGToVram();
    void LoadQuests();
    int GetSelectedQuestId();

public:
    struct {
        void *data;
        u32 size;
    } unk_010[5]; // char, palette, screens (BG7, BG6, BG5)
    QLAnimLoader unk_038;
    OamSpriteSet *unk_044;
    OamSpriteSet *unk_048;
    QLPushButton unk_04C[6]; // left, right, up, down, A, back
    CQLListBox unk_184;
    QLBlinkMarks unk_31C;
    int unk_338; // quest count
    QLMessageStrings *unk_33C; // quest infos
    QLMessageStrings unk_340;
    QLListLine *unk_34C;
    int unk_350; // saved sub BG mode
    int unk_354; // saved sub visible windows
    GXWndPlane unk_358; // saved sub window 0 inside plane
    GXWndPlane unk_359; // saved sub outside plane
    QuestGiverInfo *unk_35C;
    u8 unk_360;
};

STATIC_SIZE_ASSERT(CQuestListScreen, 0x364);

// Defined in ov27
// Quest place map on the sub screen (twin of ov8's MissionQuestMap)
class QuestListMap {
public:
    QuestListMap(CGame *game);
    ~QuestListMap();

    void Init();
    BOOL Update();
    void Render();
    void OnVBlank();
    void LoadPalette();
    void Release();
    void WriteOam();
    void Load();
    void LoadToVram();
    void SetupBG();
    void Start(u16 idx);
    BOOL Setup();
    void UpdateInput();
    void Close();
    void RequestPlaceName(u16 id);
    void DrawPlaceName();
    void ShowQuestPlace(u16 idx);
    void SetSpriteToArea(int idx, u16 id);
    void SelectQuestPlace();
    void SelectCurrentArea();
    void SelectArea(u16 id);
    void SetAreaMarker(u16 id, int mode);
    void FadeIn();
    void FadeOut();
    BOOL IsFading();

public:
    u16 unk_00; // state
    int unk_04; // text needs redraw
    RegionMap *unk_08;
    FieldData *unk_0C;
    MessageTable *unk_10; // place names
    OamSpriteSet *unk_14;
    OamSpriteSet *unk_18;
    u32 unk_1C;
    OamSprite *unk_20[5]; // quest place mark, -, back button
    u16 unk_34; // shown place
    u16 unk_36; // quest place
    CGame *unk_38;
};

STATIC_SIZE_ASSERT(QuestListMap, 0x3C);

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
    QuestListMap *unk_08;
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
    QuestGiverInfo unk_384;
};

STATIC_SIZE_ASSERT(CQuestListScene, 0x1664);

#endif // POKERANGER2_SCENE_CQUESTLISTSCENE_HPP
