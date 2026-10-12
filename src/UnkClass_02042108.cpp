#include "UnkClass_02042108.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_02042108::UnkClass_02042108(u8 id)
{
    m_id = id;
    Load();
}

UnkClass_02042108::~UnkClass_02042108()
{
    Release();
}

void UnkClass_02042108::Load()
{
    char path[0x60];

    Release();

    OS_SPrintf(path, "data/battle/bg/capbg%03d_LZ.bin", m_id);
    CArchiveGuard *guard = new CArchiveGuard("BBG", path, 1, 1, 0, NULL, 0);

    OS_SPrintf(path, "BBG:capbg%03d.NCBR", m_id);
    m_image = new UnkClass_020074D4(path, 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->sub_020076B0();

    OS_SPrintf(path, "BBG:capbg%03d.NCLR", m_id);
    m_palette = new UnkClass_02007AA4(path, 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->sub_02007BC4();

    OS_SPrintf(path, "BBG:capbg%03d.NCER", m_id);
    m_cells = new CNCERFile(path, 0, 0, 0);

    m_sprite = new CSoftwareSprite();
    m_sprite->SetResources((UnkClass_CPrimitive_ImageProxy *)m_image, NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)m_palette, (UnkClass_CSoftwareSprite_38 *)m_cells);
    m_sprite->m_z = -0x3FF;

    if (guard != NULL) {
        delete guard;
    }
}

void UnkClass_02042108::Release()
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

extern "C" void sub_020423F4(UnkClass_02042108 *obj, Camera2D *camera)
{
    obj->m_sprite->Render(camera);
}

extern "C" int sub_0204240C(UnkClass_02042108 *obj, int z)
{
    z += obj->m_sprite->GetCellNumOAMAttrs(obj->m_sprite->m_cellDataIdx);
    obj->m_sprite->m_z = z;
    return z;
}
