#include "UnkClass_0202A2AC.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_02034478.hpp"
#include "common.hpp"

UnkClass_0202A2AC::UnkClass_0202A2AC()
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

UnkClass_0202A2AC::~UnkClass_0202A2AC()
{
    unk_04 = NULL;
    SAFE_DELETE(unk_08);
}

void UnkClass_0202A2AC::sub_0202A32C(u32 charOffset, int oamIndex, u32 paletteSlot, int x, int y)
{
    unk_0C = charOffset;
    unk_14 = oamIndex;
    unk_1C = paletteSlot;
    unk_08 = new UnkClass_0200ECD0((GXOamAttr *)&unk_00->unk_0024[(u8)oamIndex], unk_00->unk_14A8, FALSE, 0x40);
    unk_10 = (int)unk_08->sub_0200EE14("data/menu", "ma005_00", charOffset, paletteSlot) / 32;
    unk_04 = unk_08->sub_0200F4FC(0, x, y, 0);
    unk_04->sub_0200EBF4(0x20, 0x20, 0, 0);
    unk_18 = unk_08->unk_30;
    unk_20 = TRUE;
}

BOOL UnkClass_0202A2AC::sub_0202A404()
{
    unk_24 = FALSE;
    if (unk_04 != NULL && unk_20) {
        if ((u16)(unk_00->unk_0014->unk_0002 & PAD_BUTTON_B) || unk_04->sub_0200EB84()) {
            unk_00->m_audioEngine->sub_02034C44(0x103);
            unk_24 = TRUE;
            return TRUE;
        }
    }
    return FALSE;
}

void UnkClass_0202A2AC::sub_0202A47C()
{
    if (unk_08 != NULL && unk_20) {
        unk_08->sub_0200F71C();
    }
}
