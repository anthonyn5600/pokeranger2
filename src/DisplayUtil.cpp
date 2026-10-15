#include "DisplayUtil.hpp"

#include <nitro.h>

#include "CGame.hpp"

void SetupMainBGFont()
{
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x3800, GX_BG_CHARBASE_0x00000);
    CGame::GetInstance()->unk_0C24->Init(3, 0x2000, 0, 0);
}

void SetupSubBGFont()
{
    G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);
    CGame::GetInstance()->unk_0C28->Init(7, 0x6000, 0, 0);
}

void SetupBGFonts()
{
    SetupMainBGFont();
    SetupSubBGFont();
}

void FlushBGFonts()
{
    CGame *game = CGame::GetInstance();
    game->unk_0C24->FlushArea();
    game->unk_0C28->FlushArea();
}

void LoadOam()
{
    CGame *game = CGame::GetInstance();
    DC_FlushRange(game->unk_0024, 0x400);
    GX_LoadOAM(game->unk_0024, 0, 0x400);
    CGame_0024 *oam = game->unk_0024;
    DC_FlushRange(oam + 0x80, 0x400);
    GXS_LoadOAM(oam + 0x80, 0, 0x400);
}
