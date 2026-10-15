#ifndef POKERANGER2_FIELD_CFIELDEFFECTACTOR_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTACTOR_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "field/CFieldEffect.hpp"

// Effect attached to an actor data object (factory kind 1 = Manpu balloons, incl. FieldScene's Create(1, 0x25)).
class CFieldEffectActor : public CFieldEffect {
public:
    CFieldEffectActor()
    {
        unk_18 = NULL;
    }
    CFieldEffectActor(CEffectActorData *data)
    {
        unk_18 = data;
    }
    virtual ~CFieldEffectActor()
    {
    }

    virtual int IsReady();
    virtual int Update(int step);

public:
    CEffectActorData *unk_18;
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTACTOR_HPP
