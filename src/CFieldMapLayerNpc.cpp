#include <nitro.h>
#include <string.h>

#include "UnkClass_020B26A0.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldNpc.hpp"
#include "field/CFieldNpcManage.hpp"
#include "heap.hpp"

extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

int CFieldMapLayerNpc::Draw(Camera2D *camera)
{
    return 0;
}

CFieldMapLayerNpc::CFieldMapLayerNpc()
{
    m_count = 0;
    m_entries = NULL;
}

CFieldMapLayerNpc::~CFieldMapLayerNpc()
{
    Release();
}

BOOL CFieldMapLayerNpc::LoadEntries(void *data)
{
    u8 *p = (u8 *)data;
    int count;

    memcpy(&count, p, 4);
    p += 4;
    m_entries = (FieldMapNpcEntry *)Heap_AllocWithAlignment(count * sizeof(FieldMapNpcEntry), 4);
    m_count = count;
    for (int i = 0; i < count; i++) {
        memcpy(&m_entries[i].x, p, 2);
        memcpy(&m_entries[i].y, p + 2, 2);
        m_entries[i].dir = p[4];
        m_entries[i].hidden = p[5];
        memcpy(&m_entries[i].unk_06, p + 6, 2);
        memcpy(&m_entries[i].unk_08, p + 8, 2);
        m_entries[i].unk_0A = p[10];
        m_entries[i].unk_0B = 0;
        p += 11;
    }
    return TRUE;
}

BOOL CFieldMapLayerNpc::Load(void *data)
{
    LoadEntries(data);
    CFieldNpcManage *manage = MAIN_BSS_0210CA50;
    if (manage != NULL) {
        int base = manage->CountActors();
        for (int i = 0; i < m_count; i++) {
            int slot = manage->ov0_0213C66C(base + i, m_entries[i].unk_0A, m_entries[i].unk_06, m_entries[i].unk_08, 0);
            if (slot >= 0) {
                CFieldNpc *npc = (CFieldNpc *)manage->Get(slot);
                fx32 y = m_entries[i].y << FX32_SHIFT;
                fx32 x = m_entries[i].x << FX32_SHIFT;
                npc->SetPosXY(x, y);
                npc->sub_020128EC_((m_entries[i].dir + 1) << 14);
                npc->sub_0201287C_();
                x = m_entries[i].x << FX32_SHIFT;
                y = m_entries[i].y << FX32_SHIFT;
                npc->unk_18 = x;
                npc->unk_1C = y;
                npc->unk_E0 = MAIN_BSS_020B26A0.unk_001A;
                npc->unk_E4 = 0;
                npc->sub_0202E68C(unk_08);
                if (m_entries[i].hidden) {
                    npc->unk_20 = 2;
                } else {
                    sub_02041C1C(npc);
                    npc->unk_20 = 0;
                    npc->sub_0202D394();
                }
            } else {
                OS_Terminate();
            }
        }
    }
    return TRUE;
}

void CFieldMapLayerNpc::Release()
{
    if (m_entries != NULL) {
        Heap_Free(m_entries);
        m_entries = NULL;
    }
    m_count = 0;
}

int CFieldMapLayerNpc::GetPolygonCount()
{
    return 0;
}

int CFieldMapLayerNpc::GetType()
{
    return 8;
}
