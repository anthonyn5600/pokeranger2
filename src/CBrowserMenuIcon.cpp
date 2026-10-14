#include "BrowserScreen.hpp"
#include "CGame.hpp"
#include "UnkStruct_020107A8.hpp"
#include "scene/CBrowserMenu.hpp"

CBrowserMenuItemIcon::CBrowserMenuItemIcon()
{
    for (int i = 0; i < 3; i++) {
        unk_18[i] = NULL;
    }
}

CBrowserMenuItemIcon::~CBrowserMenuItemIcon()
{
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(unk_18[i]);
    }
}

void CBrowserMenuItemIcon::ov21_0212181C(OamSpriteSet **anims)
{
    for (int i = 0; i < 3; i++) {
        unk_18[i] = BrowserMenuSprite::Create(anims[i], 0, 0, 0, 2);
        unk_18[i]->unk_00->SetTouchRect(0x10, 0x10, 0, 0);
    }
}

BOOL CBrowserMenuItemIcon::IsTouched()
{
    int kind = unk_08->unk_20;
    if (kind >= 3) {
        return FALSE;
    }
    return unk_18[kind]->unk_00->GetTouchTrigger();
}

void CBrowserMenuItemIcon::func08()
{
}

void CBrowserMenuItemIcon::SetData(int id, int count, int arg2)
{
    unk_04 = id;
    int kind = unk_08->unk_20;
    switch (kind) {
    case 0:
        unk_18[kind]->unk_04->SetAnim(unk_18[kind]->unk_08, id);
        break;
    case 1:
        if (count != 0) {
            unk_18[kind]->unk_04->SetAnim(unk_18[kind]->unk_08, id);
        } else {
            unk_18[kind]->unk_04->SetAnim(unk_18[kind]->unk_08, 0x13);
        }
        break;
    case 2:
        if (count == 0) {
            unk_18[kind]->unk_04->SetAnim(unk_18[kind]->unk_08, 0x18);
        } else if (id == 0) {
            unk_18[kind]->unk_04->SetAnim(unk_18[kind]->unk_08, 0x17);
        } else if (id == 0x18) {
            unk_18[kind]->unk_04->SetAnim(unk_18[kind]->unk_08, 0x19);
        } else {
            unk_18[kind]->unk_04->SetAnim(unk_18[kind]->unk_08, id - 1);
        }
        break;
    }
}

void CBrowserMenuItemIcon::UpdatePos()
{
    for (int i = 0; i < 3; i++) {
        unk_18[i]->unk_00->unk_14 = FALSE;
    }
    if (!unk_14) {
        return;
    }
    int kind = unk_08->unk_20;
    if (kind >= 3) {
        return;
    }
    unk_18[kind]->unk_00->unk_14 = TRUE;
    unk_18[kind]->unk_00->SetPos(unk_0C + unk_08->unk_70, unk_10 + unk_08->unk_74);
}

void CBrowserMenuItemIcon::func0C()
{
}

CBrowserMenuCursorIcon::CBrowserMenuCursorIcon()
{
    unk_14 = NULL;
    unk_18 = TRUE;
    unk_1C = 0;
    unk_24 = 0;
    unk_20 = 0;
}

CBrowserMenuCursorIcon::~CBrowserMenuCursorIcon()
{
    SAFE_DELETE(unk_14);
}

void CBrowserMenuCursorIcon::ov21_02121AF0(OamSpriteSet *anim)
{
    unk_14 = BrowserMenuSprite::Create(anim, 0x11, 0, 0, 0);
}

void CBrowserMenuCursorIcon::Update()
{
    if (unk_24 != unk_04->unk_10) {
        unk_24 = unk_04->unk_10;
        unk_18 = TRUE;
        unk_20 = 20;
    }
    if (unk_20 != 0) {
        unk_20--;
        return;
    }
    if (unk_04->unk_18 != 0) {
        unk_18 = TRUE;
        unk_1C = 0;
        return;
    }
    if (++unk_1C == 6) {
        unk_18 = FALSE;
    }
    if (unk_1C == 12) {
        unk_18 = TRUE;
        unk_1C = 0;
    }
}

void CBrowserMenuCursorIcon::UpdatePos()
{
    if (!unk_10) {
        unk_14->unk_00->unk_14 = FALSE;
        return;
    }
    unk_14->unk_00->SetVisible(unk_18);
    unk_14->unk_00->SetPos(unk_08 + unk_04->unk_70, unk_0C + unk_04->unk_74);
}

void CBrowserMenuCursorIcon::func0C()
{
}

CBrowserMenuManagerIcon::CBrowserMenuManagerIcon()
{
}

CBrowserMenuManagerIcon::~CBrowserMenuManagerIcon()
{
}

void CBrowserMenuManagerIcon::ov21_02121C74(OamSpriteSet **anims, OamSpriteSet *cursorAnim, BrowserScreen *browser)
{
    unk_20 = 0;
    UnkClass_021226C0 *list = browser->unk_010;
    for (int i = 0; i < 18; i++) {
        unk_8C[i] = list->unk_814[i];
    }
    for (int i = 0; i < 25; i++) {
        unk_D4[i] = list->unk_85C[i];
    }
    for (int i = 0; i < 9; i++) {
        CBrowserMenuItemIcon *item = new CBrowserMenuItemIcon();
        item->ov21_0212181C(anims);
        item->SetPos(i * 24, 0);
        AddItem(item);
    }
    CBrowserMenuCursorIcon *cursor = new CBrowserMenuCursorIcon();
    cursor->ov21_02121AF0(cursorAnim);
    SetCursor(cursor);
}

void CBrowserMenuManagerIcon::Refresh()
{
    int count = GetVisibleCount();
    int i = 0;
    for (; i < count; i++) {
        int index = i + unk_14;
        unk_28[i]->unk_14 = TRUE;
        int n = 0;
        switch (unk_20) {
        case 0:
            break;
        case 1:
            n = unk_8C[unk_04[index]];
            break;
        case 2:
            n = unk_D4[unk_04[index]];
            break;
        }
        unk_28[i]->SetData(unk_04[index], n, 0);
    }
    for (; i < GetVisibleCount(); i++) {
        unk_28[i]->unk_14 = FALSE;
        unk_28[i]->UpdatePos();
    }
}
