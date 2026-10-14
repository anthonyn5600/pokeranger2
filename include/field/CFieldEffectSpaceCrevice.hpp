#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP

#include <nitro.h>

#include "DrawObjectList.hpp"
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
        virtual int Draw(Camera2D *camera, int budget);
    };

    virtual ~CFieldEffectSpaceCrevice();
    virtual int GetEffectId();
    virtual int IsReady();
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_02142398(DrawObjectList *renderLists);
    virtual int SetParam(int param, int value);
    virtual void SetColor(u16 color);
    virtual void FadeTo(int arg0, int arg1);
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
