#ifndef POKERANGER2_SCENE_CENCYCLOPEDIASCENE_HPP
#define POKERANGER2_SCENE_CENCYCLOPEDIASCENE_HPP

#include <nnsys.h>

#include "common.hpp"
#include "file/CBinaryFile.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "scene/CScene.hpp"

class Camera2D;
class CBinaryFileMes;
class OamSprite;
class OamSpriteSet;
class CEncycListBox;
class EncycRadioButtonGroup;
class EncycAnimLoader;
class EncycMainScreen;
struct UnkStruct_02120F34;
struct UnkStruct_0211D918;

// Defined in ov22
class CEncycMenuScreen {
public:
    CEncycMenuScreen()
    {
        unk_04 = 0;
    }
    virtual ~CEncycMenuScreen()
    {
    }

    virtual void func0(EncycAnimLoader *loader) = 0;
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3(EncycMainScreen *display) = 0;
    virtual int func4() = 0;
    virtual void func5() = 0;
    virtual void func6() = 0;
    virtual void func7()
    {
    }

public:
    int unk_04;
};

// Defined in ov22
class IEncycPushButtonListener {
public:
    virtual void OnPushButton(int id) = 0;
};

// Defined in ov22
class IEncycRadioButtonListener {
public:
    virtual void OnRadioButton(int groupId, int idx) = 0;
};

// Defined in ov22
class IEncycListBoxEventListener {
public:
    virtual void OnListBoxEvent0(int id, int idx) = 0;
    virtual void OnListBoxEvent1(int id, int cursor, u32 flags, int arg3) = 0;
};

// Defined in ov22
// Push button made of two cell animations (normal, pressed); reports presses to a listener
class EncycPushButton {
public:
    EncycPushButton()
    {
        unk_00 = -1;
        unk_0C = NULL;
        unk_10 = 0;
        unk_14 = 0;
        unk_18 = 0;
        unk_1C = 24;
        unk_1D = 8;
        unk_1E = TRUE;
        unk_1F = TRUE;
        MI_CpuClear8(unk_04, sizeof(unk_04));
    }

    BOOL ov22_0211F134(int id, OamSpriteSet *anims, int animNormal, int animPressed, int x, int y, int arg6, int arg7, int priority);
    void ov22_0211F1D0();
    void ov22_0211F2A4();
    void ov22_0211F344(BOOL arg0);
    void ov22_0211F398(BOOL enabled);
    void ov22_0211F3C8();

    void SetListener(IEncycPushButtonListener *listener)
    {
        unk_0C = listener;
    }

public:
    int unk_00; // id
    OamSprite *unk_04[2]; // normal, pressed
    IEncycPushButtonListener *unk_0C;
    int unk_10; // repeat timer
    int unk_14; // touching
    int unk_18; // touching last frame
    s8 unk_1C; // repeat delay
    s8 unk_1D; // repeat interval
    u8 unk_1E;
    u8 unk_1F; // enabled
};

STATIC_SIZE_ASSERT(EncycPushButton, 0x20);

// Defined in ov22
// Loads cell animation sets into consecutive OBJ char/palette slots
class EncycAnimLoader {
public:
    EncycAnimLoader();

    OamSpriteSet *ov22_0211F3F0(const char *dir, const char *name, int plttCount, int oamIdx);
    void ov22_0211F4A4(OamSpriteSet *anims, int oamIdx);

public:
    u32 unk_00; // char offset
    u32 unk_04; // palette slot
    int unk_08; // next oam index
};

STATIC_SIZE_ASSERT(EncycAnimLoader, 0xC);

// Defined in ov22
// Text canvas over a BG (NNS text canvas + char canvas)
class EncycTextCanvas {
public:
    void ov22_02121024(NNSG2dFont *font, void *scr, void *chr, int charNo, int x, int y, int w, int h, int hSpace, int vSpace);
    void ov22_021210B8();
    void ov22_02121110();

public:
    NNSG2dTextCanvas unk_00;
    NNSG2dCharCanvas unk_10;
};

STATIC_SIZE_ASSERT(EncycTextCanvas, 0x28);

// Defined in ov22
class EncycTextRenderer {
public:
    EncycTextRenderer()
    {
        unk_60 = 0;
    }

    void ov22_0212112C(EncycTextCanvas *canvas, int x, int y, int color, const char *label, int flags);
    void ov22_021212A4(int x, int y, int w, int h, int flags);
    void ov22_02121304(EncycTextCanvas *canvas, const char *text, int x, int y, int color, int width, int flags);
    void ov22_021213F0(Camera2D *camera);
    void ov22_021215C8(EncycTextCanvas *canvas, int hSpace, int x, int y, int color, u8 **str);

public:
    CPrimitiveQUAD unk_00;
    int unk_60;
};

STATIC_SIZE_ASSERT(EncycTextRenderer, 0x64);

// Owning pointer; nothing in ov22 sets it (pointee type unknown, only its virtual dtor is used)
struct UnkStruct_0211F544 {
    UnkStruct_0211F544()
    {
        unk_00 = NULL;
    }
    ~UnkStruct_0211F544()
    {
        SAFE_DELETE(unk_00);
    }

    CBinaryFile *unk_00;
};

// Defined in ov22
// Main screen: 3D quads + text on BG1
class EncycMainScreen {
public:
    EncycMainScreen();
    ~EncycMainScreen();

    void ov22_0211F594();
    void ov22_0211F6F8();
    void ov22_0211F72C();
    void ov22_0211F7B8(const char *archive, const char *file);
    void ov22_0211F8A8();
    BOOL ov22_0211F8C4(int x, int y, int color, const char *label, int arg4);
    void ov22_0211F928();

public:
    int unk_00;
    UnkStruct_0211F544 unk_04;
    Camera2D *unk_08;
    EncycTextCanvas unk_0C;
    EncycTextRenderer unk_34[8];
    int unk_354; // quad count
};

STATIC_SIZE_ASSERT(EncycMainScreen, 0x358);

// Defined in ov22
// Message file split into its strings
class EncycMessageStrings {
public:
    EncycMessageStrings();
    ~EncycMessageStrings();

    int ov22_02120A24(const char *path);
    int ov22_02120AD8();
    const char *ov22_02120AE0(int idx);
    void ov22_02120B04();

public:
    CBinaryFileMes *unk_00;
    int unk_04; // count
    const char **unk_08;
};

STATIC_SIZE_ASSERT(EncycMessageStrings, 0xC);

// Defined in ov22
// One radio button (cell animations + label)
class EncycRadioButton {
public:
    EncycRadioButton();

public:
    int unk_00; // id (-1 = free)
    OamSprite *unk_04; // selected
    OamSprite *unk_08; // not selected
    OamSprite *unk_0C; // "new" mark
    const char *unk_10; // label
    int unk_14;
};

STATIC_SIZE_ASSERT(EncycRadioButton, 0x18);

// Defined in ov22
// Radio button group
class EncycRadioButtonGroup {
public:
    EncycRadioButtonGroup(int arg0, int count);
    ~EncycRadioButtonGroup();

    void ov22_021206DC(int idx, OamSpriteSet *anims, int animOn, int animOff, int x, int y, int w, int h, int arg8, const char *label);
    void ov22_021207E8(int idx, OamSpriteSet *anims, int anim, int x, int y, int arg5);
    void ov22_0212086C(int idx, BOOL flag);
    void ov22_021208DC(int idx);
    void ov22_0212098C();

    void SetListener(IEncycRadioButtonListener *listener)
    {
        unk_0C = listener;
    }

public:
    int unk_00;
    int unk_04; // count
    EncycRadioButton *unk_08;
    IEncycRadioButtonListener *unk_0C;
};

STATIC_SIZE_ASSERT(EncycRadioButtonGroup, 0x10);

// Defined in ov22
class EncycListBoxGroup {
public:
    EncycListBoxGroup();

public:
    int unk_00; // line count
    UnkStruct_0211D918 *unk_04; // lines
    int unk_08; // saved top line
    int unk_0C; // saved cursor line
};

STATIC_SIZE_ASSERT(EncycListBoxGroup, 0x10);

// One picture marker of an encyclopedia page
struct UnkStruct_02120FA8 {
    u8 unk_00; // x
    u8 unk_01; // y
    u16 unk_02; // type
    u16 unk_04; // label message
    u16 unk_06;
};

STATIC_SIZE_ASSERT(UnkStruct_02120FA8, 0x8);

// One encyclopedia entry (data/encyclo/encyclopedia.bin)
struct UnkStruct_02120F34 {
    UnkStruct_02120F34()
    {
        unk_00 = NULL;
        unk_04 = 0;
        unk_08 = 0;
        unk_0C = 0;
        unk_10 = NULL;
    }

    UnkStruct_02120FA8 *ov22_02120FA8(int page, int idx);

    int GetPicture(int page)
    {
        if (unk_10 != NULL && page >= 0 && page < unk_0C) {
            return unk_10[page];
        }
        return 0;
    }

    int GetMarkerCount(int page)
    {
        if (unk_14 != NULL && page >= 0 && page < unk_0C) {
            int n = unk_14[page];
            if (n < 0) {
                n = -n;
            }
            return n;
        }
        return 0;
    }

    u8 *unk_00; // name
    int unk_04; // number in its category
    int unk_08; // first description message
    int unk_0C; // page count
    u16 *unk_10; // picture per page
    s8 *unk_14; // markers per page (negative: shared with the previous page)
    UnkStruct_02120FA8 *unk_18; // markers
    u32 unk_1C; // capture state
};

STATIC_SIZE_ASSERT(UnkStruct_02120F34, 0x20);

// Defined in ov22
// Dictionary messages shared by the screens
class EncycDictionary {
public:
    EncycDictionary()
    {
        unk_18 = 0;
    }
    ~EncycDictionary()
    {
    }

    void Load(const char *path0, const char *path1)
    {
        if (unk_00.unk_08 == NULL) {
            unk_00.ov22_02120A24(path0);
        }
        if (unk_0C.unk_08 == NULL) {
            unk_0C.ov22_02120A24(path1);
        }
    }

public:
    UnkStruct_02120FA8 *ov22_0211F0F0(int page, int idx);

    int GetPageCount()
    {
        return unk_18 != NULL ? unk_18->unk_0C : 0;
    }
    int GetPicture(int page)
    {
        return unk_18 != NULL ? unk_18->GetPicture(page) : 0;
    }
    int GetMarkerCount(int page)
    {
        return unk_18 != NULL ? unk_18->GetMarkerCount(page) : 0;
    }
    u8 *GetName()
    {
        return unk_18 != NULL ? unk_18->unk_00 : NULL;
    }

    const char *GetDescription(int page)
    {
        if (unk_18 != NULL) {
            if (page < 0) {
                page = 0;
            }
            if (page >= unk_18->unk_0C) {
                page = unk_18->unk_0C - 1;
            }
            int idx = page + unk_18->unk_08 + 1;
            if (idx >= unk_00.ov22_02120AD8()) {
                idx = unk_00.ov22_02120AD8() - 1;
            }
            return unk_00.ov22_02120AE0(idx);
        }
        return NULL;
    }

public:
    EncycMessageStrings unk_00;
    EncycMessageStrings unk_0C;
    UnkStruct_02120F34 *unk_18;
};

STATIC_SIZE_ASSERT(EncycDictionary, 0x1C);

// One list box line
struct UnkStruct_0211D918 {
    u8 *unk_00; // name
    u32 unk_04; // 1 = new
    UnkStruct_02120F34 *unk_08;
};

STATIC_SIZE_ASSERT(UnkStruct_0211D918, 0xC);

// Defined in ov22
class CEncycListBox {
public:
    CEncycListBox(int count);
    virtual ~CEncycListBox();

    BOOL ov22_0211FAD4(int arg0, OamSpriteSet *anims, int arg2, int arg3, int arg4, int arg5, u32 arg6, int arg7, int arg8, int arg9, int argA);
    void ov22_0211FBE4();
    void ov22_0211FC24(int group, UnkStruct_0211D918 *lines, int count);
    void ov22_0211FC58();
    void ov22_0211FD74();
    void ov22_0211FE18();
    void ov22_0211FEA8();
    void ov22_0211FF20();
    void ov22_0212005C();
    void ov22_021201B0();
    void ov22_02120348(BOOL down);
    void ov22_02120414(int group);
    void ov22_021204D8(int line);
    int ov22_02120560(int group);
    void ov22_0212058C();
    void ov22_021205B8(int arg0);

    void SetListener(IEncycListBoxEventListener *listener)
    {
        unk_38 = listener;
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
    IEncycListBoxEventListener *unk_38;
    OamSprite *unk_3C; // cursor
    u8 unk_40; // blink timer
    OamSprite *unk_44[9];
    int unk_68; // group count
    EncycListBoxGroup *unk_6C;
};

STATIC_SIZE_ASSERT(CEncycListBox, 0x70);

// Defined in ov22
// Encyclopedia entries by category
class EncycEntries {
public:
    EncycEntries();
    ~EncycEntries();

    BOOL ov22_02120BB4(const char *path);
    void ov22_02120E80();
    int ov22_02120F14(int group);
    UnkStruct_02120F34 *ov22_02120F34(int group, int idx);

public:
    int unk_00;
    int unk_04[3]; // counts
    UnkStruct_02120F34 *unk_10;
    u16 *unk_14; // pictures
    UnkStruct_02120FA8 *unk_18; // markers
    s8 *unk_1C; // marker counts
    EncycMessageStrings unk_20;
};

STATIC_SIZE_ASSERT(EncycEntries, 0x2C);

// Defined in ov22
class CEncycItemListScreen : public CEncycMenuScreen,
                             public IEncycPushButtonListener,
                             public IEncycListBoxEventListener,
                             public IEncycRadioButtonListener {
public:
    CEncycItemListScreen(EncycPushButton *backButton);

    virtual void func0(EncycAnimLoader *loader);
    virtual void func1();
    virtual void func2();
    virtual void func3(EncycMainScreen *display);
    virtual int func4();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual void OnPushButton(int id);
    virtual void OnListBoxEvent0(int id, int idx);
    virtual void OnListBoxEvent1(int id, int cursor, u32 flags, int arg3);
    virtual void OnRadioButton(int groupId, int idx);

    void ov22_0211D918(int count);
    void ov22_0211DE40(int group);
    UnkStruct_02120F34 *ov22_0211DE9C();

public:
    int unk_14; // result
    int unk_18; // category
    UnkStruct_02120F34 *unk_1C; // chosen entry
    OamSpriteSet *unk_20;
    EncycRadioButtonGroup unk_24;
    CEncycListBox unk_34;
    EncycPushButton unk_A4[4];
    EncycPushButton *unk_124; // back button
    EncycMessageStrings unk_128;
    EncycEntries unk_134;
    UnkStruct_0211D918 *unk_160;
    int unk_164[3]; // new entries per category
    u16 unk_170[3][16]; // category palettes
};

STATIC_SIZE_ASSERT(CEncycItemListScreen, 0x1D0);

// Strings of data/message/etc/menu_mes
struct UnkStruct_0211E4AC_Entry {
    u32 unk_00; // size
    u8 *unk_04;
};

struct UnkStruct_0211E4AC {
    u32 unk_00;
    u32 unk_04; // count
    UnkStruct_0211E4AC_Entry *unk_08;
};

// Defined in ov22
class CEncycItemDescriptionScreen : public CEncycMenuScreen, public IEncycPushButtonListener {
public:
    CEncycItemDescriptionScreen(EncycPushButton *backButton);
    virtual ~CEncycItemDescriptionScreen();

    virtual void func0(EncycAnimLoader *loader);
    virtual void func1();
    virtual void func2();
    virtual void func3(EncycMainScreen *display);
    virtual int func4();
    virtual void func5();
    virtual void func6();
    virtual void OnPushButton(int id);

    void ov22_0211E4AC();
    void ov22_0211E66C(int group);
    void ov22_0211EA78(int page);
    BOOL ov22_0211ED04();
    BOOL ov22_0211EE10();
    void ov22_0211EF04(int page);

public:
    int unk_0C; // fade state
    int unk_10; // page
    u8 unk_14; // page changed
    OamSpriteSet *unk_18;
    EncycMainScreen *unk_1C;
    EncycPushButton unk_20[2]; // previous, next page
    EncycPushButton *unk_60; // back button
    EncycDictionary *unk_64;
    u16 unk_68[3][16]; // category palettes
    int unk_C8; // category
    UnkStruct_0211E4AC *unk_CC;
};

STATIC_SIZE_ASSERT(CEncycItemDescriptionScreen, 0xD0);

// Defined in ov22
class CEncyclopediaScene : public CScene, public IEncycPushButtonListener {
public:
    CEncyclopediaScene();
    virtual ~CEncyclopediaScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();
    virtual void OnPushButton(int id);

    void ov22_0211D1A4();
    void ov22_0211D200();
    void ov22_0211D294();

public:
    int unk_008; // current screen
    CEncycMenuScreen *unk_00C[2];
    CEncycItemListScreen *unk_014;
    CEncycItemDescriptionScreen *unk_018;
    EncycAnimLoader unk_01C;
    OamSpriteSet *unk_028;
    EncycPushButton unk_02C; // back button
    EncycMainScreen unk_04C;
    EncycDictionary *unk_3A4;
    int unk_3A8; // saved sub visible windows
    GXWndPlane unk_3AC; // saved sub window 0 inside plane
    GXWndPlane unk_3AD; // saved sub outside plane
};

STATIC_SIZE_ASSERT(CEncyclopediaScene, 0x3B0);

#endif // POKERANGER2_SCENE_CENCYCLOPEDIASCENE_HPP
