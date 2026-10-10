#include <nitro.h>
#include <string.h>

#include "UnkClass_02003718.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "heap.hpp"
#include "sub_02006000.hpp"

void CFieldMapLayerCharaTrans::DrawEntries(Rectangle view, int baseX, int baseY, fx32 scale)
{
    for (int i = 0; i < m_count; i++) {
        UnkClass_0212F82C *mct = m_mct[m_entries[i].mct];
        if (mct == NULL) {
            continue;
        }
        FieldMapCharaPiece *piece = mct->GetPiece(mct->m_frame);
        if (piece == NULL) {
            continue;
        }
        Rectangle bounds = piece->bounds;
        bounds.pos.x = ((m_offsetX + baseX + m_entries[i].x) << FX32_SHIFT) + (bounds.size.x >> 1);
        bounds.pos.y = ((m_offsetY + baseY + m_entries[i].y) << FX32_SHIFT) + (bounds.size.y >> 1);
        if (RectanglesOverlap(view, bounds)) {
            G3_RestoreMtx(0);
            G3_Scale(scale, scale, FX32_ONE);
            G3_Translate(m_offsetX + baseX + m_entries[i].x, m_offsetY + baseY + m_entries[i].y, unk_04);
            MI_SendGXCommand(3, piece->displayLists[m_entries[i].variant & 3], piece->displayListSize);
        }
    }
}

int CFieldMapLayerCharaTrans::Draw(UnkClass_02003718 *camera)
{
    if (m_mct != NULL && m_entries != NULL && m_count > 0) {
        fx32 scale = FX32_ONE << camera->unk_28;
        int baseX = 0;
        int baseY = 0;
        if (m_repeat) {
            Point2D cam = camera->GetOffset();
            if (cam.x <= 0) {
                baseX = m_width * (-cam.x / (m_width << FX32_SHIFT));
            } else {
                baseX = m_width * (-cam.x / (m_width << FX32_SHIFT) - 1);
            }
            if (cam.y <= 0) {
                baseY = m_height * (-cam.y / (m_height << FX32_SHIFT));
            } else {
                baseY = m_height * (-cam.y / (m_height << FX32_SHIFT) - 1);
            }
        }
        Rectangle view;
        view.pos.x = -camera->unk_1C;
        view.pos.y = -camera->unk_20;
        view.size.x = FX32_CONST(256);
        view.size.y = FX32_CONST(192);
        G3_Color(m_color);
        DrawEntries(view, baseX, baseY, scale);
        if (m_repeat) {
            DrawEntries(view, baseX - m_width, baseY - m_height, scale);
            DrawEntries(view, baseX - m_width, baseY + m_height, scale);
            DrawEntries(view, baseX - m_width, baseY, scale);
            DrawEntries(view, baseX + m_width, baseY, scale);
            DrawEntries(view, baseX + m_width, baseY - m_height, scale);
            DrawEntries(view, baseX + m_width, baseY + m_height, scale);
            DrawEntries(view, baseX, baseY - m_height, scale);
            DrawEntries(view, baseX, baseY + m_height, scale);
        }
        return 1;
    }
    return 0;
}

CFieldMapLayerCharaTrans::CFieldMapLayerCharaTrans()
{
    m_count = 0;
    m_width = 0;
    m_height = 0;
    m_offsetX = 0;
    m_offsetY = 0;
    m_color = GX_RGB(31, 31, 31);
    m_entries = NULL;
    m_mct = NULL;
    m_repeat = FALSE;
}

CFieldMapLayerCharaTrans::~CFieldMapLayerCharaTrans()
{
    Release();
}

BOOL CFieldMapLayerCharaTrans::Load(void *data)
{
    u8 *p = (u8 *)data;
    int cellSize;
    int count;
    u16 cellsX;
    u16 cellsY;

    memcpy(&cellSize, p, 4);
    memcpy(&count, p + 4, 4);
    memcpy(&m_offsetX, p + 8, 2);
    memcpy(&m_offsetY, p + 10, 2);
    memcpy(&cellsX, p + 12, 2);
    memcpy(&cellsY, p + 14, 2);
    p += 16;
    m_entries = (FieldMapCharaEntry *)Heap_AllocWithAlignment(count * sizeof(FieldMapCharaEntry), 4);
    m_count = count;
    m_width = cellsX * cellSize;
    m_height = cellsY * cellSize;
    for (int i = 0; i < count; i++) {
        memcpy(&m_entries[i].x, p, 2);
        memcpy(&m_entries[i].y, p + 2, 2);
        m_entries[i].mct = p[4];
        m_entries[i].variant = p[5];
        p += 6;
    }
    return TRUE;
}

void CFieldMapLayerCharaTrans::Release()
{
    if (m_entries != NULL) {
        Heap_Free(m_entries);
        m_entries = NULL;
    }
    m_mct = NULL;
    m_count = 0;
    m_width = 0;
    m_height = 0;
    m_offsetX = 0;
    m_offsetY = 0;
}

int CFieldMapLayerCharaTrans::GetType()
{
    return 14;
}
