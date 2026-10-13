#include "field/CFieldEffect.hpp"

#include <nitro.h>

int CFieldEffect::ov0_021421D0()
{
    m_outTime = 0;
    m_inTime = 0;
    m_holdTime = -1;
    m_state = 0;
    return TRUE;
}

BOOL CFieldEffect::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    if (inTime > 0) {
        m_state = 1;
    } else if (holdTime != 0) {
        m_state = 2;
    } else if (outTime > 0) {
        m_state = 3;
    } else {
        m_state = 4;
    }
    m_frame = 0;
    m_inTime = inTime;
    m_holdTime = holdTime;
    m_outTime = outTime;
    return m_state != 4;
}

int CFieldEffect::ov0_02142240(int outTime)
{
    if (outTime > 0) {
        m_state = 3;
    } else {
        m_state = 4;
    }
    m_frame = 0;
    m_outTime = outTime;
    return TRUE;
}

int CFieldEffect::ov0_02142264(int step)
{
    int frame = m_frame;
    switch (m_state) {
    case 1:
        m_frame = frame + step;
        if (frame >= m_inTime) {
            m_frame = 0;
            if (m_holdTime != 0) {
                m_state = 2;
            } else if (m_outTime > 0) {
                m_state = 3;
            } else {
                m_state = 4;
            }
        }
        break;
    case 2:
        if (m_holdTime > 0) {
            m_frame = frame + step;
            if (frame >= m_holdTime) {
                m_frame = 0;
                if (m_outTime > 0) {
                    m_state = 3;
                } else {
                    m_state = 4;
                }
            }
        }
        break;
    case 3:
        m_frame = frame + step;
        if (frame >= m_outTime) {
            m_frame = 0;
            m_state = 4;
        }
        break;
    }
    return m_state;
}

int CFieldEffect::ov0_02142344(Camera2D *camera)
{
    return 0;
}

void CFieldEffect::ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4)
{
}
