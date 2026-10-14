#include "field/CPrimitiveNTF.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "Camera2D.hpp"
#include "field/CFieldScreenEffect.hpp"
#include "file/CArchiveGuard.hpp"

NtfTextureFormat g_ntfTextureFormats[6] = {
    { GX_TEXFMT_NONE, GX_TEXGEN_NONE, GX_TEXSIZE_S64, GX_TEXSIZE_T64, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE },
    { GX_TEXFMT_A5I3, GX_TEXGEN_TEXCOORD, GX_TEXSIZE_S128, GX_TEXSIZE_T128, GX_TEXREPEAT_ST, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE },
    { GX_TEXFMT_A5I3, GX_TEXGEN_TEXCOORD, GX_TEXSIZE_S64, GX_TEXSIZE_T64, GX_TEXREPEAT_ST, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE },
    { GX_TEXFMT_A5I3, GX_TEXGEN_TEXCOORD, GX_TEXSIZE_S32, GX_TEXSIZE_T32, GX_TEXREPEAT_S, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_TRNS },
    { GX_TEXFMT_A5I3, GX_TEXGEN_TEXCOORD, GX_TEXSIZE_S32, GX_TEXSIZE_T32, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, GX_TEXPLTTCOLOR0_USE },
    { GX_TEXFMT_NONE, GX_TEXGEN_NONE, GX_TEXSIZE_S64, GX_TEXSIZE_T64, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE },
};

BOOL CFieldScreenEffectActorData::Load(int id)
{
    char path[0x60];

    OS_SPrintf(path, "data/Field/Effect/ew%03d_LZ.bin", id);
    CArchiveGuard archive("MEF", path, 1, 1, 0, NULL, 0);

    OS_SPrintf(path, "MEF:ew%03d.NCLR", id);
    m_palette.Load(path, 0, 0);

    m_count = 1;
    m_entries = new Entry[1];

    OS_SPrintf(path, "MEF:ew%03d.NCBR", id);
    m_entries[0].ncbr = new VramImage(path, 0, 0, 0);

    OS_SPrintf(path, "MEF:ew%03d.NCER", id);
    m_entries[0].ncer = new CNCERFile(path, 0, 0, 0);

    OS_SPrintf(path, "MEF:ew%03d.cac", id);
    m_entries[0].cac = new CellAnimController(path);

    AllocPalette((OS_GetIrqMask() & OS_IE_V_BLANK) == 0);
    return TRUE;
}

BOOL NtfTexture::Load(const char *texPath, const char *plttPath, int format)
{
    m_format = &g_ntfTextureFormats[format];

    CBinaryFile *tex = new CBinaryFile(texPath, 1, 0, 0, NULL, 0);
    CBinaryFile *pltt = new CBinaryFile(plttPath, 1, 0, 0, NULL, 0);

    u32 colors = ((pltt->unk_50 >> 1) & ~7) + 8;
    m_texKey = NNS_GfdAllocLnkTexVram(tex->unk_50, FALSE, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(colors * 2, FALSE, 0);
    m_texAddr = NNS_GfdGetTexKeyAddr(m_texKey);
    m_plttAddr = NNS_GfdGetPlttKeyAddr(m_plttKey);

    DC_FlushRange(pltt->unk_4C, pltt->unk_50);
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(pltt->unk_4C, m_plttAddr, colors * 2);
    GX_EndLoadTexPltt();

    DC_FlushRange(tex->unk_4C, tex->unk_50);
    GX_BeginLoadTex();
    GX_LoadTex(tex->unk_4C, m_texAddr, tex->unk_50);
    GX_EndLoadTex();

    SAFE_DELETE(tex);
    SAFE_DELETE(pltt);
    return TRUE;
}

BOOL NtfTexture::LoadDeferred(const char *texPath, const char *plttPath, int format)
{
    m_format = &g_ntfTextureFormats[format];

    m_ntft = new CBinaryFile(texPath, 1, 0, 0, NULL, 0);
    m_ntfp = new CBinaryFile(plttPath, 1, 0, 0, NULL, 0);

    u32 plttSize = m_ntfp->unk_50;
    m_texKey = NNS_GfdAllocLnkTexVram(m_ntft->unk_50, FALSE, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram((((plttSize >> 1) + 7) & ~7) << 1, FALSE, 0);
    m_texAddr = NNS_GfdGetTexKeyAddr(m_texKey);
    m_plttAddr = NNS_GfdGetPlttKeyAddr(m_plttKey);

    DC_FlushRange(m_ntfp->unk_4C, m_ntfp->unk_50);
    DC_FlushRange(m_ntft->unk_4C, m_ntft->unk_50);
    NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_3D_TEX_PLTT, m_plttAddr, m_ntfp->unk_4C, (m_ntfp->unk_50 + 3) & ~3);
    NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_3D_TEX_VRAM, m_texAddr, m_ntft->unk_4C, m_ntft->unk_50);
    return TRUE;
}

void NtfTexture::ReleaseFiles()
{
    SAFE_DELETE(m_ntft);
    SAFE_DELETE(m_ntfp);
}

BOOL NtfTexture::Release()
{
    if (m_texKey != 0) {
        NNS_GfdFreeLnkTexVram(m_texKey);
        m_texKey = 0;
    }
    if (m_plttKey != 0) {
        NNS_GfdFreeLnkPlttVram(m_plttKey);
        m_plttKey = 0;
    }
    m_texAddr = 0;
    m_plttAddr = 0;
    ReleaseFiles();
    return FALSE;
}

void NtfTexture::Bind()
{
    G3_TexImageParam(m_format->texFmt, m_format->texGen, m_format->sizeS, m_format->sizeT, m_format->repeat, m_format->flip, m_format->plttColor0, m_texAddr);
    G3_TexPlttBase(m_plttAddr, m_format->texFmt);
}

u32 CPrimitiveRectNTF::Render(Camera2D *camera)
{
    if (m_alpha == 0) {
        return 0;
    }

    u16 shift = camera->unk_28;
    fx32 width = m_width;
    fx32 height = m_height;

    G3_Color(m_color);
    G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, m_polygonID, m_alpha, GX_POLYGON_ATTR_MISC_NONE);
    G3_Begin(GX_BEGIN_QUADS);

    G3_TexCoord(m_s1, m_t1);
    G3_Vtx(FX_Whole(m_x - (width >> 1)) << shift, FX_Whole(m_y - (height >> 1)) << shift, m_z);

    G3_TexCoord(m_s1, m_t2);
    G3_VtxXY(FX_Whole(m_x - (width >> 1)) << shift, FX_Whole(m_y + (height >> 1)) << shift);

    G3_TexCoord(m_s2, m_t2);
    G3_VtxXY(FX_Whole(m_x + (width >> 1)) << shift, FX_Whole(m_y + (height >> 1)) << shift);

    G3_TexCoord(m_s2, m_t1);
    G3_VtxXY(FX_Whole(m_x + (width >> 1)) << shift, FX_Whole(m_y - (height >> 1)) << shift);

    G3_End();
    return 1;
}

u32 CPrimitiveQuadNTF::Render(Camera2D *camera)
{
    if (m_alpha == 0) {
        return 0;
    }

    u16 shift = camera->unk_28;

    G3_Color(m_color);
    G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, m_polygonID, m_alpha, GX_POLYGON_ATTR_MISC_NONE);
    G3_Begin(GX_BEGIN_QUADS);

    for (int i = 0; i < 4; i++) {
        G3_TexCoord(m_tex[i].x, m_tex[i].y);
        G3_Vtx(FX_Whole(m_vtx[i].x) << shift, FX_Whole(m_vtx[i].y) << shift, m_z);
    }

    G3_End();
    return 1;
}
