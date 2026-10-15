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
    void ResetResult();
    void Update();
    int IsActive();
    int GetResultId();
    int GetResultValue();

public:
    CGame *m_game;
    DebugProcessManager *unk_04;
};

STATIC_SIZE_ASSERT(BattleDebugMenu, 0x8);

#endif // POKERANGER2_BATTLE_BATTLEDEBUGMENU_HPP
