#include <nitro.h>
#include <string.h>

#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldTargetObject.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "heap.hpp"

int CFieldMapLayerObject::Draw(UnkClass_02003718 *camera)
{
    return 0;
}

CFieldMapLayerObject::CFieldMapLayerObject()
{
    m_count = 0;
    m_entries = NULL;
}

CFieldMapLayerObject::~CFieldMapLayerObject()
{
    Release();
}

BOOL CFieldMapLayerObject::Load(void *data)
{
    u8 *p = (u8 *)data;
    int count;

    memcpy(&count, p, 4);
    p += 4;
    m_entries = (FieldMapObjectEntry *)Heap_AllocWithAlignment(count * sizeof(FieldMapObjectEntry), 4);
    m_count = count;
    for (int i = 0; i < count; i++) {
        memcpy(&m_entries[i].x, p, 2);
        memcpy(&m_entries[i].y, p + 2, 2);
        memcpy(&m_entries[i].state, p + 4, 2);
        memcpy(&m_entries[i].unk_06, p + 6, 2);
        memcpy(&m_entries[i].unk_08, p + 8, 2);
        memcpy(&m_entries[i].unk_0A, p + 10, 2);
        p += 12;
    }
    CFieldTargetObjectManage *manage = MAIN_BSS_0210CA7C;
    if (manage != NULL) {
        int base = manage->CountActors();
        for (int i = 0; i < count; i++) {
            int slot = manage->ov0_0213D1AC(base + i, m_entries[i].unk_06, m_entries[i].unk_08, m_entries[i].unk_0A, 0);
            if (slot >= 0) {
                CFieldTargetObject *obj = (CFieldTargetObject *)manage->Get(slot);
                fx32 y = m_entries[i].y << FX32_SHIFT;
                fx32 x = m_entries[i].x << FX32_SHIFT;
                obj->SetPosXY(x, y);
                x = m_entries[i].x << FX32_SHIFT;
                y = m_entries[i].y << FX32_SHIFT;
                obj->unk_18 = x;
                obj->unk_1C = y;
                obj->unk_E0 = 0;
                obj->unk_E4 = 0;
                obj->sub_0202E68C(unk_08);
                switch (m_entries[i].state) {
                case 0:
                    obj->unk_20 = 0;
                    break;
                case 1:
                    obj->unk_20 = 2;
                    break;
                case 2:
                    obj->unk_20 = 3;
                    obj->sub_reset();
                    obj->sub_0202DC54(8, 0);
                    break;
                }
            } else {
                OS_Terminate();
            }
        }
    }
    return TRUE;
}

void CFieldMapLayerObject::Release()
{
    if (m_entries != NULL) {
        Heap_Free(m_entries);
        m_entries = NULL;
    }
    m_count = 0;
}

int CFieldMapLayerObject::GetPolygonCount()
{
    return 0;
}

int CFieldMapLayerObject::GetType()
{
    return 4;
}
