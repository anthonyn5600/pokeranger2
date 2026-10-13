#ifndef POKERANGER2_FIELD_CFIELDEFFECTACTOR_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTACTOR_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "field/CFieldEffect.hpp"

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

#endif // POKERANGER2_FIELD_CFIELDEFFECTACTOR_HPP
