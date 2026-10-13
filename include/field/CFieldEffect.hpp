#ifndef POKERANGER2_FIELD_CFIELDEFFECT_HPP
#define POKERANGER2_FIELD_CFIELDEFFECT_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class CFieldActor;
class CFieldEffectManage;
class UnkClass_0211E3FC;
class Camera2D;

// Defined in ov0
class CFieldEffect {
public:
    virtual ~CFieldEffect()
    {
        ov0_02142380();
    }
    virtual void ov0_021423A4()
    {
        delete this;
    }
    virtual int sub_02033028()
    {
        return 0;
    }
    virtual int sub_020332A4()
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
    virtual void ov0_02142398(UnkClass_0211E3FC *renderLists)
    {
    }
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int sub_0203312C(int param, int value)
    {
        return 0;
    }
    virtual int sub_02033244(int arg0, int arg1, int arg2)
    {
        return 0;
    }
    virtual void sub_02033440(u16 color)
    {
    }
    virtual void sub_0203331C(const Point2D &pos, int arg1)
    {
    }
    virtual void sub_02033388(const Point2D &pos, int arg1)
    {
    }
    virtual void sub_020333D8(int arg0, int arg1)
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

// TODO: the effect FieldScene starts with ov0_02142F6C(1, 0x25); its real class is unknown.
class CFieldEffectActor : public CFieldEffect {
public:
    void *unk_18;
    CFieldActor *unk_1C;
};

// Emotion balloon over an actor (CFieldActor::unk_D0 holds its effect id). Defined in ov0, except SetType.
class CFieldEffectManpu : public CFieldEffectActor {
public:
    virtual ~CFieldEffectManpu();
    virtual void SetType(int type);

public:
    u8 unk_20[0x4];
    int unk_24;
};

extern "C" {
int sub_02041A70(CFieldActor *actor, int type, int arg2);
}

#endif // POKERANGER2_FIELD_CFIELDEFFECT_HPP
