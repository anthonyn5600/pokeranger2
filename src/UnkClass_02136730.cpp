#include "battle/UnkClass_02136730.hpp"

#include "battle/UnkClass_02136AD4.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"

UnkClass_02136730::UnkClass_02136730()
{
    m_timer = 0;
}

UnkClass_02136730::~UnkClass_02136730()
{
}

void UnkClass_02136730::ov1_02136760()
{
    if (m_timer == 0) {
        return;
    }
    if (m_flags & 1) {
        ov1_0213680C();
    }
    if (m_flags & 2) {
        ov1_02136840();
    }
    if (m_flags & 4) {
        ov1_02136874();
    }
    if (m_flags & 8) {
        ov1_021368A8();
    }
    if (m_flags & 0x10) {
        ov1_021368D0();
    }
    if (m_flags & 0x20) {
        ov1_021368F8();
    }
    if (m_flags & 0x80) {
        ov1_021368FC();
    }
    m_timer--;
}

void UnkClass_02136730::ov1_0213680C()
{
    if (m_ax != FX32_ONE) {
        m_vx = FX32_MUL(m_vx, m_ax);
    }
    m_x += m_vx;
}

void UnkClass_02136730::ov1_02136840()
{
    if (m_ay != FX32_ONE) {
        m_vy = FX32_MUL(m_vy, m_ay);
    }
    m_y += m_vy;
}

void UnkClass_02136730::ov1_02136874()
{
    if (m_az != FX32_ONE) {
        m_vz = FX32_MUL(m_vz, m_az);
    }
    m_z += m_vz;
}

void UnkClass_02136730::ov1_021368A8()
{
    m_alpha = LinearInterpolate(m_alphaFrom, m_alphaTo, m_duration - m_timer, m_duration);
}

void UnkClass_02136730::ov1_021368D0()
{
    m_scale = LinearInterpolate(m_scaleFrom, m_scaleTo, m_duration - m_timer, m_duration);
}

void UnkClass_02136730::ov1_021368F8()
{
}

void UnkClass_02136730::ov1_021368FC()
{
    m_vx += m_dvx;
    m_vy += m_dvy;
    m_vz += m_dvz;
}

void UnkClass_02136730::ov1_02136930(Camera2D *camera, GXDLInfo *dl)
{
    if (m_timer == 0 || m_alpha == 0) {
        return;
    }
    m_quad.m_color = m_color;
    m_quad.m_alpha = m_alpha;
    fx32 r = FX32_MUL(m_size, m_scale);
    fx32 x = m_x;
    // the cast keeps m_y as the first operand while m_z is loaded first
    fx32 y = m_z;
    y = m_y + (int)y;
    m_quad.SetVertexCoordinates(x, y - r, x + r, y, x, r + y, x - r, y, 0x3FF);
    if (dl != NULL) {
        m_quad.RenderDL(camera, dl);
    } else {
        m_quad.Render(camera);
    }
}

void UnkClass_02136730::ov1_021369FC(u16 duration, fx32 x, fx32 y, fx32 z, fx32 size, u16 color)
{
    m_flags = 0;
    m_x = x;
    m_y = y;
    m_z = z;
    m_size = size;
    m_color = color;
    m_alpha = 0x1F;
    m_scale = FX32_ONE;
    m_duration = duration;
    m_timer = duration;
}

void UnkClass_02136730::ov1_02136A40(fx32 x, fx32 y)
{
    m_flags |= 1;
    m_vx = x;
    m_ax = y;
}

void UnkClass_02136730::ov1_02136A58(fx32 x, fx32 y)
{
    m_flags |= 2;
    m_vy = x;
    m_ay = y;
}

void UnkClass_02136730::ov1_02136A70(fx32 x, fx32 y)
{
    m_flags |= 4;
    m_vz = x;
    m_az = y;
}

void UnkClass_02136730::ov1_02136A88(u8 arg0, u8 arg1)
{
    m_flags |= 8;
    m_alphaFrom = arg0;
    m_alphaTo = arg1;
}

void UnkClass_02136730::ov1_02136AA0(fx32 arg0, int arg1)
{
    m_flags |= 0x10;
    m_scaleFrom = arg0;
    m_scaleTo = arg1;
}

void UnkClass_02136730::ov1_02136AB8(fx32 x, fx32 y, int arg2)
{
    m_flags |= 0x80;
    m_dvx = x;
    m_dvy = y;
    m_dvz = arg2;
}

UnkClass_02136AD4::UnkClass_02136AD4(UnkClass_02136730 **items, int count)
{
    m_count = count;
    m_items = items;
    m_next = 0;
}

UnkClass_02136AD4::~UnkClass_02136AD4()
{
}

void UnkClass_02136AD4::ov1_02136AEC()
{
    for (int i = 0; i < m_count; i++) {
        m_items[i]->ov1_02136760();
    }
}

UnkClass_02136730 *UnkClass_02136AD4::ov1_02136B24(u16 arg0, fx32 x, fx32 y, int arg3, fx32 arg4, u16 color)
{
    UnkClass_02136730 *item = m_items[m_next];
    item->ov1_021369FC(arg0, x, y, arg3, arg4, color);
    m_next++;
    if (m_next >= m_count) {
        m_next = 0;
    }
    return item;
}

void UnkClass_02136AD4::ov1_02136B88(Camera2D *camera)
{
    for (int i = 0; i < m_count; i++) {
        m_items[i]->ov1_02136930(camera, NULL);
    }
}

void UnkClass_02136AD4::ov1_02136BD0(int arg0)
{
    for (int i = 0; i < m_count; i++) {
        m_items[i]->m_quad.m_polygonID = arg0;
    }
}
