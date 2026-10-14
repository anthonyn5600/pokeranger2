#include <nnsys.h>

#include "battle/StylerLine.hpp"
#include "file/CBinaryFile.hpp"

NtfResource::NtfResource(const char *ntft, const char *ntfp)
{
    Load(ntft, ntfp);
}

NtfResource::~NtfResource()
{
    Release();
}

void NtfResource::Load(const char *ntft, const char *ntfp)
{
    CBinaryFile *tex = new CBinaryFile(ntft, 1, 0, 0, NULL, 0);
    CBinaryFile *pltt = new CBinaryFile(ntfp, 1, 0, 0, NULL, 0);

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
}

void NtfResource::Release()
{
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}
