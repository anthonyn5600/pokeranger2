#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"

class CFieldEffectManpuAnime : public CFieldEffectManpuSimple {
public:
    virtual ~CFieldEffectManpuAnime();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual int ov0_021528B4(); // TODO signature (slot 26)
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP
