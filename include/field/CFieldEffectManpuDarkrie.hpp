#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"

// size 0x1D4, ctor ov0_021700E4
class CFieldEffectManpuDarkrie : public CFieldEffectManpu {
public:
    virtual ~CFieldEffectManpuDarkrie();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP
