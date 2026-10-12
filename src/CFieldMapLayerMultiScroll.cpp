#include <nitro.h>
#include <string.h>

#include "Camera2D.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"

BOOL CFieldMapLayerMultiScroll::Load(void *data)
{
    u8 *p = (u8 *)data;

    m_speedX = 0;
    m_speedY = 0;
    m_scrollX = 0;
    m_scrollY = 0;
    memcpy(&m_rateX, p, 4);
    p += 4;
    memcpy(&m_rateY, p, 4);
    p += 4;
    memcpy(&m_divX, p, 4);
    p += 4;
    memcpy(&m_divY, p, 4);
    p += 4;
    memcpy(&m_speedX, p, 4);
    p += 4;
    memcpy(&m_speedY, p, 4);
    p += 4;
    BOOL result = CFieldMapLayerNormalView::Load(p);
    if (m_static != NULL) {
        m_static->m_repeat = TRUE;
    }
    if (m_chara != NULL) {
        m_chara->m_repeat = TRUE;
    }
    return result;
}

void CFieldMapLayerMultiScroll::Update(int fps)
{
    if (m_speedX != 0) {
        m_scrollX += m_speedX * 60 / fps;
        if (m_scrollX >= m_mapSize.width << FX32_SHIFT) {
            m_scrollX -= m_mapSize.width << FX32_SHIFT;
        } else if (m_scrollX < 0) {
            m_scrollX += m_mapSize.width << FX32_SHIFT;
        }
    }
    if (m_speedY != 0) {
        m_scrollY += m_speedY * 60 / fps;
        if (m_scrollY >= m_mapSize.height << FX32_SHIFT) {
            m_scrollY -= m_mapSize.height << FX32_SHIFT;
        } else if (m_scrollY < 0) {
            m_scrollY += m_mapSize.height << FX32_SHIFT;
        }
    }
}

int CFieldMapLayerMultiScroll::Draw(Camera2D *camera)
{
    Point2D cam = camera->GetOffset();
    int x = (-cam.x >> FX32_SHIFT) - m_offsetX;
    int y = (-cam.y >> FX32_SHIFT) - m_offsetY;
    int dx = x * m_rateX / m_divX - x;
    int dy = y * m_rateY / m_divY - y;
    if (m_speedX != 0) {
        dx += m_scrollX >> FX32_SHIFT;
    }
    if (m_speedY != 0) {
        dy += m_scrollY >> FX32_SHIFT;
    }
    if (m_static != NULL) {
        m_static->m_offsetX = m_offsetX - dx;
        m_static->m_offsetY = m_offsetY - dy;
    }
    if (m_chara != NULL) {
        m_chara->m_offsetX = m_offsetX - dx;
        m_chara->m_offsetY = m_offsetY - dy;
    }
    return CFieldMapLayerNormalView::Draw(camera);
}

int CFieldMapLayerMultiScroll::GetPolygonCount()
{
    int count = 0;
    if (m_chara != NULL) {
        count += m_chara->GetPolygonCount();
    }
    if (m_static != NULL) {
        count += m_static->GetPolygonCount();
    }
    return count;
}

int CFieldMapLayerMultiScroll::GetType()
{
    return 10;
}

CFieldMapLayerMultiScroll::~CFieldMapLayerMultiScroll()
{
}
