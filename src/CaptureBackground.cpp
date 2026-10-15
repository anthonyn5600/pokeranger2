#include "CaptureBackground.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

CaptureBackground::CaptureBackground(u8 id)
{
    m_id = id;
    Load();
}

CaptureBackground::~CaptureBackground()
{
    Release();
}

void CaptureBackground::Load()
{
    char path[0x60];

    Release();

    OS_SPrintf(path, "data/battle/bg/capbg%03d_LZ.bin", m_id);
    CArchiveGuard *guard = new CArchiveGuard("BBG", path, 1, 1, 0, NULL, 0);

    OS_SPrintf(path, "BBG:capbg%03d.NCBR", m_id);
    m_image = new VramImage(path, 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    OS_SPrintf(path, "BBG:capbg%03d.NCLR", m_id);
    m_palette = new VramPalette(path, 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    OS_SPrintf(path, "BBG:capbg%03d.NCER", m_id);
    m_cells = new CNCERFile(path, 0, 0, 0);

    m_sprite = new CSoftwareSprite();
    m_sprite->SetResources((UnkClass_CPrimitive_ImageProxy *)m_image, NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)m_palette, (UnkClass_CSoftwareSprite_38 *)m_cells);
    m_sprite->m_z = -0x3FF;

    if (guard != NULL) {
        delete guard;
    }
}

void CaptureBackground::Release()
{
    SAFE_DELETE(m_sprite);
    if (m_image != NULL) {
        NNS_GfdFreeLnkTexVram(m_texKey);
        m_texKey = 0;
    }
    if (m_palette != NULL) {
        NNS_GfdFreeLnkPlttVram(m_plttKey);
        m_plttKey = 0;
    }
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
}

extern "C" void CaptureBackground_Render(CaptureBackground *obj, Camera2D *camera)
{
    obj->m_sprite->Render(camera);
}

extern "C" int CaptureBackground_SetZ(CaptureBackground *obj, int z)
{
    z += obj->m_sprite->GetCellNumOAMAttrs(obj->m_sprite->m_cellDataIdx);
    obj->m_sprite->m_z = z;
    return z;
}
