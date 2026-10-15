#include "BrowserScreen.hpp"
#include "CGame.hpp"
#include "PokeIdTableEntry.hpp"
#include "scene/CBrowserMenu.hpp"

CBrowserMenuItemPokemon::CBrowserMenuItemPokemon()
{
    unk_18 = NULL;
}

CBrowserMenuItemPokemon::~CBrowserMenuItemPokemon()
{
    SAFE_DELETE(unk_18);
}

void CBrowserMenuItemPokemon::Init(OamSpriteSet *anim)
{
    unk_18 = BrowserMenuSprite::Create(anim, 0x10, 0, 0, 3);
    unk_18->unk_00->SetTouchRect(0xB0, 0x10, -4, 0);
}

BOOL CBrowserMenuItemPokemon::IsTouched()
{
    return unk_18->unk_00->GetTouchTrigger();
}

void CBrowserMenuItemPokemon::func08()
{
}

void CBrowserMenuItemPokemon::SetData(int id, int arg1, int arg2)
{
    unk_04 = id;
    PokeIdTable_Get(CGame::GetInstance()->unk_1434, id);
}

void CBrowserMenuItemPokemon::UpdatePos()
{
    unk_18->unk_00->SetPos(unk_0C + unk_08->unk_70, unk_10 + unk_08->unk_74);
}

void CBrowserMenuItemPokemon::func0C()
{
    unk_18->unk_00->unk_14 = FALSE;
}

CBrowserMenuCursorPokemon::CBrowserMenuCursorPokemon()
{
    unk_14 = NULL;
}

CBrowserMenuCursorPokemon::~CBrowserMenuCursorPokemon()
{
    SAFE_DELETE(unk_14);
}

void CBrowserMenuCursorPokemon::Init(OamSpriteSet *anim)
{
    unk_14 = BrowserMenuSprite::Create(anim, 0x10, 0, 0, 0);
    anim->SetAnim(anim->unk_24, 0x10);
    unk_18 = 0;
    unk_1C = 0;
}

void CBrowserMenuCursorPokemon::Update()
{
    if (unk_04->unk_18 != 0) {
        unk_14->unk_00->unk_14 = TRUE;
        unk_18 = 0;
        unk_1C = 20;
        return;
    }
    if (unk_1C != 0) {
        unk_1C--;
        return;
    }
    if (++unk_18 == 6) {
        unk_14->unk_00->unk_14 = FALSE;
    }
    if (unk_18 == 12) {
        unk_14->unk_00->unk_14 = TRUE;
        unk_18 = 0;
    }
}

void CBrowserMenuCursorPokemon::UpdatePos()
{
    unk_14->unk_00->SetPos(unk_08 + unk_04->unk_70, unk_0C + unk_04->unk_74);
}

void CBrowserMenuCursorPokemon::func0C()
{
}

CBrowserMenuManagerPokemon::CBrowserMenuManagerPokemon()
{
}

CBrowserMenuManagerPokemon::~CBrowserMenuManagerPokemon()
{
}

void CBrowserMenuManagerPokemon::Init(OamSpriteSet *anim, BrowserScreen *owner)
{
    unk_8C = owner;
    unk_20 = 0;

    CBrowserMenuCursorPokemon *cursor = new CBrowserMenuCursorPokemon();
    cursor->Init(anim);
    SetCursor(cursor);

    unk_78 = 2;
    unk_7C = 0x10000;
    unk_84 = 0x2000;
    for (int i = 0; i < 6; i++) {
        CBrowserMenuItemPokemon *item = new CBrowserMenuItemPokemon();
        item->Init(anim);
        item->SetPos(0, i * 16);
        AddItem(item);
    }
}

void CBrowserMenuManagerPokemon::Refresh()
{
    CBrowserMenuManager::Refresh();
}

void CBrowserMenuManagerPokemon::Draw()
{
    for (int i = 0; i < 6; i++) {
        if (unk_28[i] != NULL) {
            unk_28[i]->func0C();
        }
    }
    CBrowserMenuManager::Draw();
}
