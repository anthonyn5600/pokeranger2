#include "VramImage.hpp"

#include "CGame.hpp"
#include "file/CNCGRFile.hpp"

VramImage::VramImage()
{
    Init();
}

VramImage::VramImage(const char *arg0, u32 arg1, u32 arg2, u32 arg3)
{
    Init();
    Load(arg0, arg1, arg2, 0);
}

VramImage::VramImage(NNSG2dCharacterData *arg0)
{
    Init();
    SetData(arg0);
}

VramImage::~VramImage()
{
    Release();
}

void VramImage::Init()
{
    unk_00 = NULL;
    unk_04 = NULL;

    NNS_G2dInitImageProxy(&unk_08);

    unk_30 = 0;
    unk_32 = 0;
    unk_34 = 0;
    unk_38 = 0;
}

void VramImage::Load(const char *arg0, u32 arg1, u32 arg2, u32 arg3)
{
    Release();
    unk_00 = new CNCGRFile(arg0, arg3, arg1, arg2);
    NNS_G2dInitImageProxy(&unk_08);

    unk_30 = 0;
    unk_04 = unk_00->unk_B8;

    unk_08.attr.fmt = unk_04->pixelFmt;
    unk_08.attr.bExtendedPlt = FALSE;
    unk_08.attr.plttUse = GX_TEXPLTTCOLOR0_TRNS;
#ifdef PC_PORT // libntrsystem fixed the SDK's spelling
    unk_08.attr.mappingType = unk_04->mappingType;
#else
    unk_08.attr.mappingType = unk_04->mapingType;
#endif

    unk_38 = unk_04->szByte;
    unk_32 = unk_04->W * 8;
    unk_34 = unk_04->H * 8;
}

void VramImage::SetData(NNSG2dCharacterData *arg0)
{
    Release();
    NNS_G2dInitImageProxy(&unk_08);

    unk_30 = 0;
    unk_04 = arg0;

    unk_08.attr.fmt = unk_04->pixelFmt;
    unk_08.attr.bExtendedPlt = FALSE;
    unk_08.attr.plttUse = GX_TEXPLTTCOLOR0_TRNS;
#ifdef PC_PORT // libntrsystem fixed the SDK's spelling
    unk_08.attr.mappingType = unk_04->mappingType;
#else
    unk_08.attr.mappingType = unk_04->mapingType;
#endif

    unk_38 = unk_04->szByte;
    unk_32 = unk_04->W * 8;
    unk_34 = unk_04->H * 8;
}

void VramImage::Release()
{
    if (unk_00 != NULL) {
        delete unk_00;
        unk_00 = NULL;
    }

    unk_04 = NULL;
}

void VramImage::LoadToVram(u32 arg0)
{
    NNS_G2dLoadImage2DMapping(unk_04, arg0, NNS_G2D_VRAM_TYPE_3DMAIN, &unk_08);
    unk_2C = arg0;
    unk_30 = 1;
}

void VramImage::LoadToVramDeferred(u32 arg0)
{
    unk_30 = 0;
    unk_2C = arg0;
    s_game->AddVBlankCallback(LoadToVramCallback, this);
}

void VramImage::LoadToVramCallback(void *data)
{
    VramImage *v0 = (VramImage *)data;

    if (v0 == NULL) {
        return;
    }

    NNS_G2dLoadImage2DMapping(v0->unk_04, v0->unk_2C, NNS_G2D_VRAM_TYPE_3DMAIN, &v0->unk_08);
    v0->unk_30 = 1;
}
