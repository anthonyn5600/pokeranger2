#include "VramPalette.hpp"

#include "CGame.hpp"
#include "file/CNCLRFile.hpp"

VramPalette::VramPalette()
{
    unk_20 = 0;
    Init();
}

VramPalette::VramPalette(const char *path, u32 arg1, u32 arg2)
{
    unk_20 = 0;
    Init();
    Load(path, arg1, arg2);
}

VramPalette::VramPalette(NNSG2dPaletteData *data)
{
    unk_20 = 0;
    Init();
    SetData(data);
}

VramPalette::~VramPalette()
{
    Release();
}

void VramPalette::Init()
{
    unk_00 = NULL;
    NNS_G2dInitImagePaletteProxy(&unk_08);
    unk_20 = 0;
}

void VramPalette::Load(const char *path, u32 arg1, u32 arg2)
{
    Release();
    unk_00 = new CNCLRFile(path, 0, arg1, arg2);
    unk_04 = unk_00->unk_B8;
}

void VramPalette::SetData(NNSG2dPaletteData *data)
{
    Release();
    unk_04 = data;
}

void VramPalette::Release()
{
    SAFE_DELETE(unk_00);
    unk_04 = NULL;
}

void VramPalette::LoadToVram(u32 addr)
{
    NNS_G2dInitImagePaletteProxy(&unk_08);
    NNS_G2dLoadPalette(unk_04, addr, NNS_G2D_VRAM_TYPE_3DMAIN, &unk_08);
    unk_1C = addr;
    unk_20 = 1;
}

void VramPalette::LoadToVramDeferred(u32 addr)
{
    unk_1C = addr;
    unk_20 = 0;
    s_game->AddVBlankCallback(LoadToVramCallback, this);
}

void VramPalette::LoadToVramCallback(void *data)
{
    VramPalette *palette = (VramPalette *)data;

    if (palette == NULL) {
        return;
    }

    NNS_G2dInitImagePaletteProxy(&palette->unk_08);
    NNS_G2dLoadPalette(palette->unk_04, palette->unk_1C, NNS_G2D_VRAM_TYPE_3DMAIN, &palette->unk_08);
    palette->unk_20 = 1;
}
