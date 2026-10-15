#ifndef POKERANGER2_BATTLE_BATTLEDAMAGENUMBERGFX_HPP
#define POKERANGER2_BATTLE_BATTLEDAMAGENUMBERGFX_HPP

#include <nitro.h>

#include "common.hpp"

class GraphicsSet;

// Defined in ov1
class BattleDamageNumberGfx {
public:
    BattleDamageNumberGfx();
    ~BattleDamageNumberGfx();
    void Load();
    void Release();

public:
    GraphicsSet *m_res;
};

STATIC_SIZE_ASSERT(BattleDamageNumberGfx, 0x4);

#endif // POKERANGER2_BATTLE_BATTLEDAMAGENUMBERGFX_HPP
