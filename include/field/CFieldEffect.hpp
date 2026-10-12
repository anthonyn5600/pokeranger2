#ifndef POKERANGER2_FIELD_CFIELDEFFECT_HPP
#define POKERANGER2_FIELD_CFIELDEFFECT_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class CFieldActor;
class UnkClass_02142428;

// Defined in ov0
class CFieldEffect {
public:
    virtual ~CFieldEffect();
    virtual void ov0_021423A4();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual void ov0_021421D0();
    virtual void ov0_02142380();
    virtual void ov0_021421F0(int arg0, int arg1, int arg2);
    virtual int ov0_02142240(int arg0);
    virtual void ov0_02142264(int arg0);
    virtual void ov0_02142344();
    virtual void ov0_0214239C();
    virtual void ov0_02142398();
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int sub_0203312C(int param, int value);
    virtual int sub_02033244(int arg0, int arg1, int arg2);
    virtual void sub_02033440(u16 color);
    virtual void sub_0203331C(const Point2D &pos, int arg1);
    virtual void sub_02033388(const Point2D &pos, int arg1);
    virtual void sub_020333D8(int arg0, int arg1);
    virtual void sub_0203365C(int arg0);
    virtual void ov0_02142390();
    virtual void ov0_02142388();

public:
    u8 unk_04[0x18];
    CFieldActor *unk_1C;
};

extern "C" {
CFieldEffect *ov0_02143088(UnkClass_02142428 *mgr, u16 id);
u16 ov0_02142F6C(UnkClass_02142428 *mgr, int arg1, int arg2);
}

#endif // POKERANGER2_FIELD_CFIELDEFFECT_HPP
