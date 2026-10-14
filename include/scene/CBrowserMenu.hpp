#ifndef POKERANGER2_SCENE_CBROWSERMENU_HPP
#define POKERANGER2_SCENE_CBROWSERMENU_HPP

#include <nitro.h>

#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "common.hpp"

class CBrowserMenuManager;
class BrowserScreen;

// Defined in ov21: a sprite of an animation set
class BrowserMenuSprite {
public:
    BrowserMenuSprite();
    ~BrowserMenuSprite();

    static BrowserMenuSprite *Create(OamSpriteSet *anim, int no, int x, int y, int priority);

public:
    OamSprite *unk_00;
    OamSpriteSet *unk_04;
    int unk_08;
};

STATIC_SIZE_ASSERT(BrowserMenuSprite, 0xC);

// Defined in ov21
class CBrowserMenuItem {
public:
    virtual ~CBrowserMenuItem()
    {
    }
    virtual void func08() = 0;
    virtual void func0C() = 0;
    virtual BOOL IsTouched() = 0;
    virtual void func14()
    {
    }
    virtual void SetData(int id, int arg1, int arg2) = 0;
    virtual void UpdatePos() = 0;
    virtual void Select()
    {
    }
    virtual void SetPos(int x, int y)
    {
        unk_0C = x;
        unk_10 = y;
    }

public:
    int unk_04; // id
    CBrowserMenuManager *unk_08;
    int unk_0C;
    int unk_10;
    BOOL unk_14; // visible
};

// Defined in ov21
class CBrowserMenuCursor {
public:
    virtual ~CBrowserMenuCursor()
    {
    }
    virtual void Update() = 0;
    virtual void func0C() = 0;
    virtual void UpdatePos() = 0;
    virtual void MoveTo(int x, int y)
    {
        unk_08 = x;
        unk_0C = y;
    }

public:
    CBrowserMenuManager *unk_04;
    int unk_08;
    int unk_0C;
    BOOL unk_10; // visible
};

// Defined in ov21
class CBrowserMenuManager {
public:
    CBrowserMenuManager();
    virtual void Refresh();
    virtual ~CBrowserMenuManager();
    virtual void AddItem(CBrowserMenuItem *item);
    virtual void SetCursor(CBrowserMenuCursor *cursor);
    virtual BOOL UpdateTouch();
    virtual void Update();
    virtual void Draw();
    virtual void SetPos(int x, int y);

    void ov21_02120A00(int *list, int count, int sel);
    void Select(int index);
    void SetScroll(int scroll);
    void UpdateSelected();
    BOOL ov21_02120D5C();
    BOOL ov21_02120D70();
    BOOL ov21_02120D8C();
    BOOL ov21_02120DA0();
    BOOL ov21_02120DC8();
    BOOL ov21_02120E84();
    BOOL ov21_02120F68();
    BOOL ov21_02120FD8();

    BOOL IsLastPage()
    {
        return unk_14 + GetVisibleCount() >= unk_08 ? TRUE : FALSE;
    }

    int GetSelectedValue()
    {
        return unk_04[unk_10];
    }

    int GetVisibleCount()
    {
        return unk_08 > unk_6C ? unk_6C : unk_08;
    }

public:
    int *unk_04; // list
    int unk_08; // list count
    int unk_0C; // selected item
    int unk_10; // selected list index
    int unk_14; // scroll
    u32 unk_18; // scroll animation
    BOOL unk_1C; // enabled
    int unk_20;
    CBrowserMenuCursor *unk_24;
    CBrowserMenuItem *unk_28[16];
    CBrowserMenuItem *unk_68; // selected
    int unk_6C; // item count
    int unk_70;
    int unk_74;
    int unk_78;
    int unk_7C;
    int unk_80;
    int unk_84;
    int unk_88;
};

STATIC_SIZE_ASSERT(CBrowserMenuManager, 0x8C);

// Defined in ov21
class CBrowserMenuItemPokemon : public CBrowserMenuItem {
public:
    CBrowserMenuItemPokemon();
    virtual ~CBrowserMenuItemPokemon();
    void ov21_0212131C(OamSpriteSet *anim);
    virtual void func08();
    virtual void func0C();
    virtual BOOL IsTouched();
    virtual void SetData(int id, int arg1, int arg2);
    virtual void UpdatePos();

public:
    BrowserMenuSprite *unk_18;
};

STATIC_SIZE_ASSERT(CBrowserMenuItemPokemon, 0x1C);

// Defined in ov21
class CBrowserMenuCursorPokemon : public CBrowserMenuCursor {
public:
    CBrowserMenuCursorPokemon();
    virtual ~CBrowserMenuCursorPokemon();
    void ov21_0212149C(OamSpriteSet *anim);
    virtual void Update();
    virtual void func0C();
    virtual void UpdatePos();

public:
    BrowserMenuSprite *unk_14;
    int unk_18; // blink
    int unk_1C; // blink delay
};

STATIC_SIZE_ASSERT(CBrowserMenuCursorPokemon, 0x20);

// Defined in ov21
class CBrowserMenuManagerPokemon : public CBrowserMenuManager {
public:
    CBrowserMenuManagerPokemon();
    virtual ~CBrowserMenuManagerPokemon();
    void ov21_021215F8(OamSpriteSet *anim, BrowserScreen *owner);
    virtual void Refresh();
    virtual void Draw();

public:
    BrowserScreen *unk_8C;
};

STATIC_SIZE_ASSERT(CBrowserMenuManagerPokemon, 0x90);

// Defined in ov21
class CBrowserMenuItemIcon : public CBrowserMenuItem {
public:
    CBrowserMenuItemIcon();
    virtual ~CBrowserMenuItemIcon();
    void ov21_0212181C(OamSpriteSet **anims);
    virtual void func08();
    virtual void func0C();
    virtual BOOL IsTouched();
    virtual void SetData(int id, int count, int arg2);
    virtual void UpdatePos();

public:
    BrowserMenuSprite *unk_18[3];
};

STATIC_SIZE_ASSERT(CBrowserMenuItemIcon, 0x24);

// Defined in ov21
class CBrowserMenuCursorIcon : public CBrowserMenuCursor {
public:
    CBrowserMenuCursorIcon();
    virtual ~CBrowserMenuCursorIcon();
    void ov21_02121AF0(OamSpriteSet *anim);
    virtual void Update();
    virtual void func0C();
    virtual void UpdatePos();

public:
    BrowserMenuSprite *unk_14;
    BOOL unk_18; // blink visible
    int unk_1C; // blink
    int unk_20; // blink delay
    int unk_24; // last selected
};

STATIC_SIZE_ASSERT(CBrowserMenuCursorIcon, 0x28);

// Defined in ov21
class CBrowserMenuManagerIcon : public CBrowserMenuManager {
public:
    CBrowserMenuManagerIcon();
    virtual ~CBrowserMenuManagerIcon();
    void ov21_02121C74(OamSpriteSet **anims, OamSpriteSet *cursorAnim, BrowserScreen *browser);
    virtual void Refresh();

public:
    int unk_8C[18];
    int unk_D4[25];
};

STATIC_SIZE_ASSERT(CBrowserMenuManagerIcon, 0x138);

// Defined in ov21
class CBrowserMenuItemType : public CBrowserMenuItem {
public:
    CBrowserMenuItemType();
    virtual ~CBrowserMenuItemType();
    void ov21_02121EA8(OamSpriteSet *anim);
    virtual void func08();
    virtual void func0C();
    virtual BOOL IsTouched();
    virtual void SetData(int id, int arg1, int arg2);
    virtual void UpdatePos();
    virtual void Select();

public:
    OamSprite *unk_18;
    int unk_1C;
    int unk_20; // flash
    OamSpriteSet *unk_24;
};

STATIC_SIZE_ASSERT(CBrowserMenuItemType, 0x28);

// Defined in ov21
class CBrowserMenuManagerType : public CBrowserMenuManager {
public:
    CBrowserMenuManagerType();
    virtual ~CBrowserMenuManagerType();
    void ov21_0212200C(OamSpriteSet *anim);
};

STATIC_SIZE_ASSERT(CBrowserMenuManagerType, 0x8C);

#endif // POKERANGER2_SCENE_CBROWSERMENU_HPP
