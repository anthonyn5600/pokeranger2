#ifndef POKERANGER2_FIELD_CFIELDEFFECT_HPP
#define POKERANGER2_FIELD_CFIELDEFFECT_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02006000.hpp"

class CFieldActor;
class CFieldEffectManage;
class UnkClass_0211E3FC;
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

// Effect attached to an actor data object (factory kind 1 = Manpu balloons, incl. FieldScene's ov0_02142F6C(1, 0x25)).
class CFieldEffectActor : public CFieldEffect {
public:
    CFieldEffectActor()
    {
        unk_18 = NULL;
    }
    virtual ~CFieldEffectActor()
    {
    }

    virtual int sub_020332A4();
    virtual int ov0_02142264(int step);

public:
    CEffectActorData *unk_18;
};

// Emotion balloon over an actor (CFieldActor::unk_D0 holds its effect id). Defined in ov0, except SetType.
class CFieldEffectManpu : public CFieldEffectActor {
public:
    static void *operator new(size_t size);
    static void operator delete(void *ptr);

    virtual ~CFieldEffectManpu();
    virtual int sub_02033028();
    virtual int ov0_02142344(Camera2D *camera);
    virtual void SetType(int type);
    virtual int Draw(Camera2D *camera) = 0;
    virtual void SetDepth(fx32 z) = 0;

    BOOL IsVisible();
    inline void Detach();

public:
    CFieldActor *unk_1C;
    u8 unk_20;
    u8 unk_21[0x3];
    int unk_24;
    int unk_28;
};

class CFieldEffectManpuSimple : public CFieldEffectManpu {
public:
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    void Init(int type);

public:
    CSoftwareSprite m_sprite;
    int unk_78;
};

extern "C" {
int sub_02041A70(CFieldActor *actor, int type, int arg2);
}

#endif // POKERANGER2_FIELD_CFIELDEFFECT_HPP
