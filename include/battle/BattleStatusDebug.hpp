#ifndef POKERANGER2_BATTLE_BATTLESTATUSDEBUG_HPP
#define POKERANGER2_BATTLE_BATTLESTATUSDEBUG_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class BattleStatusDebugGfx;
class CSoftwareSprite;

// Defined in ov1
class BattleStatusDebug {
public:
    BattleStatusDebug(); // ov1_021296C8
    ~BattleStatusDebug(); // ov1_02129750
    void ov1_02129784(BattleStatusDebugGfx *data);

public:
    u8 unk_00[0xC];
    BattleStatusDebugGfx *m_data;
    CSoftwareSprite *m_sprite;
};

STATIC_SIZE_ASSERT(BattleStatusDebug, 0x14);

#endif // POKERANGER2_BATTLE_BATTLESTATUSDEBUG_HPP
