#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP

#include <nitro.h>

#include "UnkClass_0211E3FC.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/UnkClass_02151244.hpp"

// size 0x198, ctor ov0_02171938
class CFieldEffectSpaceCrevice : public CFieldEffect {
public:
    class CEffectDrawObject : public CDrawObject {
    public:
        virtual ~CEffectDrawObject();
        virtual int sub_020091D4(Camera2D *camera, int budget);
    };

    virtual ~CFieldEffectSpaceCrevice();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_02142398(UnkClass_0211E3FC *renderLists);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_02033440(u16 color);
    virtual void sub_020333D8(int arg0, int arg1);
};

class CFieldEffectSpaceCreviceFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectSpaceCreviceFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

public:
    UnkClass_02151244 m_tex[2];
};

STATIC_SIZE_ASSERT(CFieldEffectSpaceCreviceFactory, 0x5C);

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP
