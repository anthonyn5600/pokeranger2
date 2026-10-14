#ifndef POKERANGER2_BATTLE_BATTLEPARTICLEPOOL_HPP
#define POKERANGER2_BATTLE_BATTLEPARTICLEPOOL_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;
class BattleParticle;

// Defined in ov1
class BattleParticlePool {
public:
    BattleParticlePool(BattleParticle **items, int count);
    ~BattleParticlePool();
    void ov1_02136AEC();
    BattleParticle *ov1_02136B24(u16 arg0, fx32 x, fx32 y, int arg3, fx32 arg4, u16 color);
    void ov1_02136B88(Camera2D *camera);
    void ov1_02136BD0(int arg0);

public:
    u16 m_count;
    BattleParticle **m_items;
    u16 m_next;
    u8 unk_0A[0x1A];
};

STATIC_SIZE_ASSERT(BattleParticlePool, 0x24);

#endif // POKERANGER2_BATTLE_BATTLEPARTICLEPOOL_HPP
