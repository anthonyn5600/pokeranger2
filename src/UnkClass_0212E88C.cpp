#include "battle/UnkClass_0212E88C.hpp"

#include "fx_utils.hpp"

UnkClass_0212E88C::UnkClass_0212E88C()
{
    ov1_0212EDB4(0);
}

UnkClass_0212E88C::~UnkClass_0212E88C()
{
}

void UnkClass_0212E88C::ov1_0212E940()
{
    if (m_timer == 0) {
        return;
    }
    m_width = FX32_MUL(m_width, 0xE66);
    ov1_0212EB20(m_width);
    m_timer--;
}

void UnkClass_0212E88C::ov1_0212E998(Camera2D *camera)
{
    if (m_timer == 0) {
        return;
    }
    for (u16 i = 1; i < m_count; i++) {
        m_quads[i].m_color = m_color;
        m_quads[i].m_alpha = m_timer;
        m_quads[i].Render(camera);
    }
}

void UnkClass_0212E88C::ov1_0212EA1C(Point2D pos)
{
    m_timer = 0x18;
    m_width = 0x10000;
    m_color = 0x3FF;
    m_count = 0;
    m_lines[0].SetStart(pos);
}

void UnkClass_0212E88C::ov1_0212EA7C(Point2D pos)
{
    CPrimitiveLINE *line = &m_lines[m_count];
    line->SetEnd(pos);
    m_count++;
    line->SetStart(pos);
}

void UnkClass_0212E88C::ov1_0212EAD4()
{
    CPrimitiveLINE *line = &m_lines[m_count];
    CPrimitiveLINE *prev = &m_lines[m_count - 1];
    line->SetStart(prev->m_points.p2.x, prev->m_points.p2.y);
    line->SetEnd(m_lines[0].m_points.p1.x, m_lines[0].m_points.p1.y);
    m_count++;
}

void UnkClass_0212E88C::ov1_0212EB20(fx32 width)
{
    for (int i = 0; i < m_count; i++) {
        Point2D start;
        Point2D end;
        if (i != 0) {
            start = m_lines[i - 1].GetStart();
            end = m_lines[i - 1].GetEnd();
        } else {
            start = m_lines[m_count - 1].GetStart();
            end = m_lines[m_count - 1].GetEnd();
        }
        u16 angle = FX_Atan2Idx(end.y - start.y, end.x - start.x);
        m_quads[i].m_vtxCoords.x1 = end.x + FX32_MUL(width / 2, FX_CosIdx((u16)(angle - 0x4000)));
        m_quads[i].m_vtxCoords.y1 = end.y + FX32_MUL(width / 2, FX_SinIdx((u16)(angle - 0x4000)));
        m_quads[i].m_vtxCoords.x2 = end.x + FX32_MUL(width / 2, FX_CosIdx((u16)(angle + 0x4000)));
        m_quads[i].m_vtxCoords.y2 = end.y + FX32_MUL(width / 2, FX_SinIdx((u16)(angle + 0x4000)));

        start = m_lines[i].GetStart();
        end = m_lines[i].GetEnd();
        angle = FX_Atan2Idx(end.y - start.y, end.x - start.x);
        m_quads[i].m_vtxCoords.x3 = end.x + FX32_MUL(width / 2, FX_CosIdx((u16)(angle + 0x4000)));
        m_quads[i].m_vtxCoords.y3 = end.y + FX32_MUL(width / 2, FX_SinIdx((u16)(angle + 0x4000)));
        m_quads[i].m_vtxCoords.x4 = end.x + FX32_MUL(width / 2, FX_CosIdx((u16)(angle - 0x4000)));
        m_quads[i].m_vtxCoords.y4 = end.y + FX32_MUL(width / 2, FX_SinIdx((u16)(angle - 0x4000)));
    }
}

int UnkClass_0212E88C::ov1_0212EDB4(int z)
{
    for (u16 i = 0; i < 0x62; i++) {
        m_quads[i].m_z = z;
    }
    return z + 1;
}
