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
        Reset();
    }
    virtual ~CFieldEffect()
    {
        Finalize();
    }
    virtual void Destroy()
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
    virtual int Reset();
    virtual int Finalize()
    {
        return TRUE;
    }
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Stop(int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual int GetDrawCount(int layer)
    {
        return 0;
    }
    virtual void AddToRenderLists(DrawObjectList *renderLists)
    {
    }
    virtual void StartAt(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int SetParam(int param, int value)
    {
        return 0;
    }
    virtual int SetParamArray(int arg0, int arg1, int arg2)
    {
        return 0;
    }
    virtual void SetColor(u16 color)
    {
    }
    virtual void MoveTo(const Point2D &pos, int arg1)
    {
    }
    virtual void ScaleTo(const Point2D &pos, int arg1)
    {
    }
    virtual void FadeTo(int arg0, int arg1)
    {
    }
    virtual void SetSe(int arg0)
    {
    }
    virtual int SaveState(void *buf, void *end)
    {
        return 0;
    }
    virtual BOOL RestoreState(const void *data)
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
