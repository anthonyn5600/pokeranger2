#include "SubScreenPicture.hpp"

#include <nitro.h>

#include "BGLayer.hpp"
#include "common.hpp"

SubScreenPicture::SubScreenPicture(CGame *game)
{
    unk_04 = game;
    Init();
}

SubScreenPicture::~SubScreenPicture()
{
    Release();
}

void SubScreenPicture::Release()
{
}

void SubScreenPicture::Update()
{
}

void SubScreenPicture::Render()
{
}

void SubScreenPicture::Init()
{
}

BOOL SubScreenPicture::Load(int id)
{
    char file[0x20];
    char name[0x20];

    SetupBG();
    OS_SPrintf(name, "uppict%03d_", id);
    OS_SPrintf(file, "uppict%03d_00", id);
    BGS_LoadCharAndPltt("uppict/", name, 4, file, 0x20, file, 0);
    BGS_LoadScr("uppict/", name, 4, file, 0, 0x20, 0, 0);
    return TRUE;
}

void SubScreenPicture::SetupBG()
{
    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    GX_ResetBankForSubBGExtPltt();
    GX_ResetBankForSubOBJExtPltt();
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_48_HI);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_NONE);
    GXS_SetGraphicsMode(GX_BGMODE_0);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0);
    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01);
    G2S_SetBG0Priority(0);
    G2S_BG0Mosaic(FALSE);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 8, 7);
}
