#include <nitro.h>
#include <string.h>

#include "UnkClass_0213DDCC.hpp"
#include "field/CFieldEventRect.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "heap.hpp"

int CFieldMapLayerEventRect::Draw(Camera2D *camera)
{
    return 0;
}

CFieldMapLayerEventRect::CFieldMapLayerEventRect()
{
    m_count = 0;
    m_entries = NULL;
}

CFieldMapLayerEventRect::~CFieldMapLayerEventRect()
{
    Release();
}

BOOL CFieldMapLayerEventRect::Load(void *data)
{
    u8 *p = (u8 *)data;
    int count;

    memcpy(&count, p, 4);
    p += 4;
    m_entries = (FieldMapEventRectEntry *)Heap_AllocWithAlignment(count * sizeof(FieldMapEventRectEntry), 4);
    m_count = count;
    for (int i = 0; i < count; i++) {
        memcpy(&m_entries[i].x, p, 2);
        memcpy(&m_entries[i].y, p + 2, 2);
        memcpy(&m_entries[i].width, p + 4, 2);
        memcpy(&m_entries[i].height, p + 6, 2);
        memcpy(&m_entries[i].scriptId, p + 8, 2);
        p += 10;
    }
    UnkClass_0213DDCC *manage = MAIN_BSS_0210CA58;
    if (manage != NULL) {
        for (int i = 0; i < count; i++) {
            CFieldEventRect *rect = new CFieldEventRect();
            FieldMapEventRectEntry *entry = &m_entries[i];
            int height = entry->height;
            int width = entry->width;
            int x = entry->x + width / 2;
            int y = entry->y + height / 2;
            rect->m_rect.pos.x = x << FX32_SHIFT;
            rect->m_rect.pos.y = y << FX32_SHIFT;
            rect->m_rect.size.x = width << FX32_SHIFT;
            rect->m_rect.size.y = height << FX32_SHIFT;
            rect->m_group = unk_08;
            rect->unk_18 = 1;
            rect->LoadScript(entry->scriptId);
            if (manage->Add(rect) < 0) {
                OS_Terminate();
            }
        }
    }
    return TRUE;
}

void CFieldMapLayerEventRect::Release()
{
    if (m_entries != NULL) {
        Heap_Free(m_entries);
        m_entries = NULL;
    }
    m_count = 0;
}

int CFieldMapLayerEventRect::GetPolygonCount()
{
    return 0;
}

int CFieldMapLayerEventRect::GetType()
{
    return 7;
}
