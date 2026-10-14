#ifndef POKERANGER2_BATTLE_BATTLEDEBUGMENU_HPP
#define POKERANGER2_BATTLE_BATTLEDEBUGMENU_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class DebugProcessManager;

// Defined in ov1
class BattleDebugMenu {
public:
    BattleDebugMenu(CGame *game);
    ~BattleDebugMenu();
    void ov1_02135C2C();
    void ov1_02135C58();
    int ov1_02135C68();
    int ov1_02135C78();
    int ov1_02135C8C();

public:
    CGame *m_game;
    DebugProcessManager *unk_04;
};

STATIC_SIZE_ASSERT(BattleDebugMenu, 0x8);

#endif // POKERANGER2_BATTLE_BATTLEDEBUGMENU_HPP
