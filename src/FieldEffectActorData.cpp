#include <nitro.h>

#include "CellAnimController.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldManpuEffectActorData.hpp"
#include "file/CArchiveGuard.hpp"

BOOL CFieldEffectAttackActorData::ov0_0214FFF0(int id, int first, int count)
{
    char path[0x60];

    OS_SPrintf(path, "data/effect/e%03d_LZ.bin", id);
    CArchiveGuard archive("EFC", path, 1, 1, 0, NULL, 0);

    OS_SPrintf(path, "EFC:e%03d.NCLR", id);
    m_palette.Load(path, 0, 0);

    m_count = count;
    m_entries = new Entry[count];

    for (int i = 0; i < count; i++) {
        OS_SPrintf(path, "EFC:e%03d_a%02d.NCBR", id, first);
        m_entries[i].ncbr = new VramImage(path, 0, 0, 0);

        OS_SPrintf(path, "EFC:e%03d_a%02d.NCER", id, first);
        m_entries[i].ncer = new CNCERFile(path, 0, 0, 0);

        OS_SPrintf(path, "EFC:e%03d_a%02d.cac", id, first);
        m_entries[i].cac = new CellAnimController(path);
        first++;
    }

    AllocPalette((OS_GetIrqMask() & OS_IE_V_BLANK) == 0);
    return TRUE;
}

void CFieldEffectAttackActorData::Update()
{
    for (u32 i = 0; i < m_count; i++) {
        if (m_entries[i].cac != NULL) {
            m_entries[i].cac->UpdateAll();
        }
    }
}

BOOL CFieldManpuEffectActorData::Load(int id)
{
    char path[0x60];

    OS_SPrintf(path, "data/interface/i%03d_LZ.bin", id);
    CArchiveGuard archive("MEF", path, 1, 1, 0, NULL, 0);

    OS_SPrintf(path, "MEF:i%03d.NCLR", id);
    m_palette.Load(path, 0, 0);

    m_count = 1;
    m_entries = new Entry[1];

    OS_SPrintf(path, "MEF:i%03d_00.NCBR", id);
    m_entries[0].ncbr = new VramImage(path, 0, 0, 0);

    OS_SPrintf(path, "MEF:i%03d_00.NCER", id);
    m_entries[0].ncer = new CNCERFile(path, 0, 0, 0);

    OS_SPrintf(path, "MEF:i%03d_00.cac", id);
    m_entries[0].cac = new CellAnimController(path);

    AllocPalette(TRUE);
    ReleaseAll();
    return TRUE;
}

void CFieldManpuEffectActorData::Update()
{
    if (GetCac(0) != NULL) {
        GetCac(0)->UpdateAll();
    }
}

BOOL CFieldEffectNormalActorData::ov0_021503B8(int id, BOOL immediate)
{
    char path[0x60];

    OS_SPrintf(path, "data/field/effect/ef%03d_LZ.bin", id);
    CArchiveGuard archive("MEF", path, 1, 1, 0, NULL, 0);

    OS_SPrintf(path, "MEF:ef%03d.NCLR", id);
    m_palette.Load(path, 0, 0);

    m_count = 1;
    m_entries = new Entry[1];

    OS_SPrintf(path, "MEF:ef%03d.NCBR", id);
    m_entries[0].ncbr = new VramImage(path, 0, 0, 0);

    OS_SPrintf(path, "MEF:ef%03d.NCER", id);
    m_entries[0].ncer = new CNCERFile(path, 0, 0, 0);

    OS_SPrintf(path, "MEF:ef%03d.cac", id);
    m_entries[0].cac = new CellAnimController(path);

    AllocPalette(immediate);
    if (immediate) {
        ReleaseAll();
    }
    return TRUE;
}

void CFieldEffectNormalActorData::Update()
{
    if (GetCac(0) != NULL) {
        GetCac(0)->UpdateAll();
    }
}
