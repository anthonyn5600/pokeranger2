#include "SubScreenButton.hpp"

#include <nitro.h>

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "PadInput.hpp"
#include "common.hpp"

SubScreenButton::SubScreenButton()
{
    unk_00 = CGame::GetInstance();
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_1C = 0;
    unk_20 = FALSE;
    unk_24 = FALSE;
}

SubScreenButton::~SubScreenButton()
{
    unk_04 = NULL;
    SAFE_DELETE(unk_08);
}

void SubScreenButton::Load(u32 charOffset, int oamIndex, u32 paletteSlot, int x, int y)
{
    unk_0C = charOffset;
    unk_14 = oamIndex;
    unk_1C = paletteSlot;
    unk_08 = new OamSpriteSet((GXOamAttr *)&unk_00->unk_0024[(u8)oamIndex], unk_00->unk_14A8, FALSE, 0x40);
    unk_10 = (int)unk_08->Load("data/menu", "ma005_00", charOffset, paletteSlot) / 32;
    unk_04 = unk_08->AddSprite(0, x, y, 0);
    unk_04->SetTouchRect(0x20, 0x20, 0, 0);
    unk_18 = unk_08->unk_30;
    unk_20 = TRUE;
}

BOOL SubScreenButton::UpdateInput()
{
    unk_24 = FALSE;
    if (unk_04 != NULL && unk_20) {
        if ((u16)(unk_00->unk_0014->unk_0002 & PAD_BUTTON_B) || unk_04->GetTouchTrigger()) {
            unk_00->m_audioEngine->PlaySe(0x103);
            unk_24 = TRUE;
            return TRUE;
        }
    }
    return FALSE;
}

void SubScreenButton::Render()
{
    if (unk_08 != NULL && unk_20) {
        unk_08->WriteOam();
    }
}
