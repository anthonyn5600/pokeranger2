#ifndef POKERANGER2_BATTLE_BATTLEHITEFFECTGFX_HPP
#define POKERANGER2_BATTLE_BATTLEHITEFFECTGFX_HPP

#include <nitro.h>

#include "common.hpp"

class GraphicsSet;

// Defined in ov1
class BattleHitEffectGfx {
public:
    BattleHitEffectGfx();
    ~BattleHitEffectGfx();
    void Load();
    void Release();

public:
    GraphicsSet *m_res0;
    GraphicsSet *m_res1;
};

STATIC_SIZE_ASSERT(BattleHitEffectGfx, 0x8);

#endif // POKERANGER2_BATTLE_BATTLEHITEFFECTGFX_HPP
