#include "BrowserScreen.hpp"
#include "CGame.hpp"
#include "PokeIdTableEntry.hpp"
#include "scene/CBrowserMenu.hpp"

BrowserMenuSprite::BrowserMenuSprite()
{
    unk_00 = NULL;
    unk_04 = NULL;
}

BrowserMenuSprite::~BrowserMenuSprite()
{
}

BrowserMenuSprite *BrowserMenuSprite::Create(OamSpriteSet *anim, int no, int x, int y, int priority)
{
    BrowserMenuSprite *sprite = new BrowserMenuSprite();
    sprite->unk_04 = anim;
    sprite->unk_00 = anim->AddSprite(no, x, y, priority);
    sprite->unk_08 = anim->unk_24;
    return sprite;
}

CBrowserMenuManager::CBrowserMenuManager()
{
    unk_04 = NULL;
    unk_08 = 0;
    unk_0C = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_1C = TRUE;
    unk_24 = NULL;
    for (int i = 0; i < 16; i++) {
        unk_28[i] = NULL;
    }
    unk_78 = 0;
    unk_80 = 0;
    unk_88 = 0;
}

CBrowserMenuManager::~CBrowserMenuManager()
{
    unk_04 = NULL;
    unk_08 = 0;
    unk_0C = 0;
    SAFE_DELETE(unk_24);
    for (int i = 0; i < 16; i++) {
        SAFE_DELETE(unk_28[i]);
    }
}

void CBrowserMenuManager::AddItem(CBrowserMenuItem *item)
{
    unk_28[unk_6C] = item;
    item->unk_08 = this;
    unk_6C++;
}

void CBrowserMenuManager::SetCursor(CBrowserMenuCursor *cursor)
{
    unk_24 = cursor;
    cursor->unk_04 = this;
}

void CBrowserMenuManager::SetList(int *list, int count, int sel)
{
    unk_04 = list;
    unk_08 = count;
    if (list == NULL || unk_08 == 0) {
        if (unk_24 != NULL) {
            unk_24->unk_10 = FALSE;
        }
        SetScroll(0);
        Select(0);
        Refresh();
    } else {
        if (unk_24 != NULL) {
            unk_24->unk_10 = TRUE;
        }
        SetScroll(0);
        Select(sel);
        Refresh();
    }
}

void CBrowserMenuManager::SetPos(int x, int y)
{
    unk_70 = x;
    unk_74 = y;
    if (unk_24 != NULL) {
        unk_24->UpdatePos();
    }
    for (int i = 0; i < unk_6C; i++) {
        unk_28[i]->UpdatePos();
    }
}

void CBrowserMenuManager::Select(int index)
{
    if (GetVisibleCount() == 0) {
        return;
    }
    if (index >= GetVisibleCount()) {
        index = GetVisibleCount() - 1;
    }
    unk_0C = index;
    if (index == -1) {
        unk_68 = NULL;
        if (unk_24 != NULL) {
            unk_24->MoveTo(0, 0xE0);
        }
    } else {
        UpdateSelected();
        unk_68 = unk_28[index];
        unk_68->Select();
        if (unk_24 != NULL) {
            unk_24->MoveTo(unk_28[index]->unk_0C, unk_28[index]->unk_10);
        }
    }
}

void CBrowserMenuManager::SetScroll(int scroll)
{
    unk_14 = scroll;
    Refresh();
    UpdateSelected();
}

void CBrowserMenuManager::UpdateSelected()
{
    if (unk_0C == -1) {
        unk_14 = 0;
        unk_10 = -1;
    } else {
        unk_10 = unk_14 + unk_0C;
    }
}

void CBrowserMenuManager::Refresh()
{
    int count = GetVisibleCount();
    int i = 0;
    for (; i < count; i++) {
        int index = unk_14 + i;
        unk_28[i]->unk_14 = TRUE;
        unk_28[i]->SetData(unk_04[index], 0, 0);
    }
    for (; i < unk_6C; i++) {
        unk_28[i]->unk_14 = FALSE;
        unk_28[i]->UpdatePos();
    }
}

BOOL CBrowserMenuManager::UpdateTouch()
{
    if (!unk_1C) {
        return FALSE;
    }
    if (unk_18 != 0) {
        return FALSE;
    }
    for (int i = 0; i < unk_6C; i++) {
        if (unk_14 + i >= unk_08) {
            return FALSE;
        }
        if (unk_28[i]->IsTouched()) {
            Select(i);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL CBrowserMenuManager::CanSelectPrev()
{
    if (unk_10 != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL CBrowserMenuManager::CanSelectNext()
{
    if (unk_10 != unk_08 - 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL CBrowserMenuManager::CanScrollPrev()
{
    if (unk_14 != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL CBrowserMenuManager::CanScrollNext()
{
    if (unk_14 < unk_08 - GetVisibleCount()) {
        return TRUE;
    }
    return FALSE;
}

BOOL CBrowserMenuManager::SelectPrev()
{
    if (!unk_1C) {
        return FALSE;
    }
    if (unk_18 != 0) {
        return FALSE;
    }
    if (unk_0C == -1) {
        Select(0);
        return TRUE;
    }
    if (unk_0C == 0) {
        if (unk_14 == 0) {
            return FALSE;
        }
        if (unk_78 == 0) {
            unk_14--;
            SetScroll(unk_14);
        } else {
            unk_18 = 3;
            unk_88 = 0;
        }
    } else if (unk_78 == 0) {
        Select(unk_0C - 1);
    } else {
        unk_18 = 1;
        unk_80 = 0;
    }
    return TRUE;
}

BOOL CBrowserMenuManager::SelectNext()
{
    if (!unk_1C) {
        return FALSE;
    }
    if (unk_18 != 0) {
        return FALSE;
    }
    int count = GetVisibleCount();
    if (count == 0) {
        return FALSE;
    }
    if (unk_0C == -1) {
        Select(0);
        return TRUE;
    }
    if (unk_0C == count - 1) {
        if (unk_08 - 1 == unk_14 + unk_0C) {
            return FALSE;
        }
        if (unk_78 == 0) {
            unk_14++;
            SetScroll(unk_14);
        } else {
            unk_18 = 4;
            unk_88 = 0;
        }
    } else if (unk_78 == 0) {
        Select(unk_0C + 1);
    } else {
        unk_18 = 2;
        unk_80 = 0;
    }
    return TRUE;
}

BOOL CBrowserMenuManager::PagePrev()
{
    if (!unk_1C) {
        return FALSE;
    }
    if (unk_18 != 0) {
        return FALSE;
    }
    if (unk_14 == 0) {
        return FALSE;
    }
    if (unk_0C == -1) {
        Select(0);
        return TRUE;
    }
    SetScroll(unk_14 < unk_6C ? 0 : unk_14 - unk_6C);
    return TRUE;
}

BOOL CBrowserMenuManager::PageNext()
{
    if (!unk_1C) {
        return FALSE;
    }
    if (unk_18 != 0) {
        return FALSE;
    }
    int count = GetVisibleCount();
    if (count == 0) {
        return FALSE;
    }
    int max = unk_08 - count;
    if (unk_14 == max) {
        return FALSE;
    }
    if (unk_0C == -1) {
        Select(0);
        return TRUE;
    }
    int scroll = unk_14 + count;
    if (scroll < max) {
        max = scroll;
    }
    SetScroll(max);
    return TRUE;
}

void CBrowserMenuManager::Update()
{
    if (!unk_1C) {
        return;
    }
    switch (unk_18) {
    case 1:
        unk_80 += unk_84;
        if (unk_80 >= unk_7C) {
            unk_18 = 0;
            unk_80 = 0;
            Select(unk_0C - 1);
        }
        if (unk_24 != NULL) {
            unk_24->MoveTo(unk_28[unk_0C]->unk_0C, unk_28[unk_0C]->unk_10 - (unk_80 >> 12));
        }
        break;
    case 2:
        unk_80 += unk_84;
        if (unk_80 >= unk_7C) {
            unk_18 = 0;
            unk_80 = 0;
            Select(unk_0C + 1);
        }
        if (unk_24 != NULL) {
            unk_24->MoveTo(unk_28[unk_0C]->unk_0C, unk_28[unk_0C]->unk_10 + (unk_80 >> 12));
        }
        break;
    case 3:
        unk_88 -= unk_84;
        if (unk_88 <= -unk_7C) {
            unk_18 = 0;
            unk_88 = 0;
            unk_14--;
            SetScroll(unk_14);
        }
        break;
    case 4:
        unk_88 += unk_84;
        if (unk_88 >= unk_7C) {
            unk_18 = 0;
            unk_88 = 0;
            unk_14++;
            SetScroll(unk_14);
        }
        break;
    }
    if (unk_24 != NULL) {
        unk_24->Update();
    }
}

void CBrowserMenuManager::Draw()
{
    if (!unk_1C) {
        return;
    }
    if (unk_24 != NULL) {
        unk_24->func0C();
    }
    int count = GetVisibleCount();
    for (int i = 0; i < count; i++) {
        unk_28[i]->func0C();
    }
}
