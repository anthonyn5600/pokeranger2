#ifndef POKERANGER2_FIELD_CFIELDMANPUEFFECTACTORDATA_HPP
#define POKERANGER2_FIELD_CFIELDMANPUEFFECTACTORDATA_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"

class CFieldManpuEffectActorData : public CEffectActorData {
public:
    virtual void Update();

    // Loads data/interface/i<id>_LZ.bin.
    BOOL Load(int id); // ov0_02150204
};

#endif // POKERANGER2_FIELD_CFIELDMANPUEFFECTACTORDATA_HPP
