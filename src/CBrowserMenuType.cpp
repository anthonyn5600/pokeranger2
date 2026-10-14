#include "BrowserScreen.hpp"
#include "CGame.hpp"
#include "UnkStruct_020107A8.hpp"
#include "scene/CBrowserMenu.hpp"

CBrowserMenuItemType::CBrowserMenuItemType()
{
    unk_18 = NULL;
    unk_24 = NULL;
}

CBrowserMenuItemType::~CBrowserMenuItemType()
{
}

void CBrowserMenuItemType::ov21_02121EA8(OamSpriteSet *anim)
{
    unk_24 = anim;
    unk_18 = unk_24->AddSprite(0xB, 0, 0, 2);
    unk_1C = unk_24->unk_24;
    unk_18->SetTouchRect(0x68, 0x14, -4, 8);
}

BOOL CBrowserMenuItemType::IsTouched()
{
    return unk_18->GetTouchTrigger();
}

void CBrowserMenuItemType::func08()
{
}

void CBrowserMenuItemType::SetData(int id, int arg1, int arg2)
{
    unk_04 = id;
}

void CBrowserMenuItemType::UpdatePos()
{
    unk_18->SetPos(unk_0C + unk_08->unk_70, unk_10 + unk_08->unk_74);
    if (this == unk_08->unk_68) {
        if (unk_20 != 0) {
            unk_24->SetAnim(unk_1C, 0xF);
            unk_20--;
        } else {
            unk_24->SetAnim(unk_1C, 0xE);
        }
    } else {
        unk_24->SetAnim(unk_1C, 0xD);
    }
}

void CBrowserMenuItemType::Select()
{
    unk_20 = 8;
}

void CBrowserMenuItemType::func0C()
{
}

CBrowserMenuManagerType::CBrowserMenuManagerType()
{
}

CBrowserMenuManagerType::~CBrowserMenuManagerType()
{
}

void CBrowserMenuManagerType::ov21_0212200C(OamSpriteSet *anim)
{
    for (int i = 0; i < 4; i++) {
        CBrowserMenuItemType *item = new CBrowserMenuItemType();
        item->ov21_02121EA8(anim);
        item->SetPos(0, i * 20);
        AddItem(item);
    }
}
