#include "UnkClass_02007AA4.hpp"

#include "CGame.hpp"
#include "file/CNCLRFile.hpp"

UnkClass_02007AA4::UnkClass_02007AA4()
{
    unk_20 = 0;
    sub_02007B3C();
}

UnkClass_02007AA4::UnkClass_02007AA4(const char *path, u32 arg1, u32 arg2)
{
    unk_20 = 0;
    sub_02007B3C();
    sub_02007B60(path, arg1, arg2);
}

UnkClass_02007AA4::UnkClass_02007AA4(NNSG2dPaletteData *data)
{
    unk_20 = 0;
    sub_02007B3C();
    sub_02007BAC(data);
}

UnkClass_02007AA4::~UnkClass_02007AA4()
{
    sub_02007BC4();
}

void UnkClass_02007AA4::sub_02007B3C()
{
    unk_00 = NULL;
    NNS_G2dInitImagePaletteProxy(&unk_08);
    unk_20 = 0;
}

void UnkClass_02007AA4::sub_02007B60(const char *path, u32 arg1, u32 arg2)
{
    sub_02007BC4();
    unk_00 = new CNCLRFile(path, 0, arg1, arg2);
    unk_04 = unk_00->unk_B8;
}

void UnkClass_02007AA4::sub_02007BAC(NNSG2dPaletteData *data)
{
    sub_02007BC4();
    unk_04 = data;
}

void UnkClass_02007AA4::sub_02007BC4()
{
    SAFE_DELETE(unk_00);
    unk_04 = NULL;
}

void UnkClass_02007AA4::sub_02007BFC(u32 addr)
{
    NNS_G2dInitImagePaletteProxy(&unk_08);
    NNS_G2dLoadPalette(unk_04, addr, NNS_G2D_VRAM_TYPE_3DMAIN, &unk_08);
    unk_1C = addr;
    unk_20 = 1;
}

void UnkClass_02007AA4::sub_02007C34(u32 addr)
{
    unk_1C = addr;
    unk_20 = 0;
    s_game->sub_020100E4(sub_02007C64, this);
}

void UnkClass_02007AA4::sub_02007C64(void *data)
{
    UnkClass_02007AA4 *palette = (UnkClass_02007AA4 *)data;

    if (palette == NULL) {
        return;
    }

    NNS_G2dInitImagePaletteProxy(&palette->unk_08);
    NNS_G2dLoadPalette(palette->unk_04, palette->unk_1C, NNS_G2D_VRAM_TYPE_3DMAIN, &palette->unk_08);
    palette->unk_20 = 1;
}
