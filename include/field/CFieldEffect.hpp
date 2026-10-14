#ifndef POKERANGER2_FIELD_CFIELDEFFECT_HPP
#define POKERANGER2_FIELD_CFIELDEFFECT_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldActor;
class CFieldEffectManage;
class DrawObjectList;
class Camera2D;

// Defined in ov0
class CFieldEffect {
public:
    CFieldEffect()
    {
        ov0_021421D0();
    }
    virtual ~CFieldEffect()
    {
        ov0_02142380();
    }
    virtual void ov0_021423A4()
    {
        delete this;
    }
    virtual int GetEffectId()
    {
        return 0;
    }
    virtual int IsReady()
    {
        return 1;
    }
    virtual int ov0_021421D0();
    virtual int ov0_02142380()
    {
        return TRUE;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142240(int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int ov0_0214239C(int layer)
    {
        return 0;
    }
    virtual void ov0_02142398(DrawObjectList *renderLists)
    {
    }
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int SetParam(int param, int value)
    {
        return 0;
    }
    virtual int sub_02033244(int arg0, int arg1, int arg2)
    {
        return 0;
    }
    virtual void SetColor(u16 color)
    {
    }
    virtual void sub_0203331C(const Point2D &pos, int arg1)
    {
    }
    virtual void sub_02033388(const Point2D &pos, int arg1)
    {
    }
    virtual void FadeTo(int arg0, int arg1)
    {
    }
    virtual void sub_0203365C(int arg0)
    {
    }
    virtual int ov0_02142390(void *buf, void *end)
    {
        return 0;
    }
    virtual BOOL ov0_02142388(const void *data)
    {
        return 0;
    }

public:
    // Fade-in, hold (-1 = until stopped), fade-out: m_state 1/2/3, 4 when done.
    int m_inTime;
    int m_holdTime;
    int m_outTime;
    int m_frame;
    int m_state;
};

#endif // POKERANGER2_FIELD_CFIELDEFFECT_HPP
