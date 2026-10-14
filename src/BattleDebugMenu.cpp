#include "battle/BattleDebugMenu.hpp"

#include "CGame.hpp"
#include "DebugProcess.hpp"

BattleDebugMenu::BattleDebugMenu(CGame *game)
{
    m_game = game;
    unk_04 = new DebugProcessManager(game->GetPrinter(), (u32)game->unk_0014);
}

BattleDebugMenu::~BattleDebugMenu()
{
    unk_04->CloseAll();
    SAFE_DELETE(unk_04);
}

void BattleDebugMenu::ov1_02135C2C()
{
    unk_04->SetValue(0, 0);
    unk_04->SetValue(1, 0);
}

void BattleDebugMenu::ov1_02135C58()
{
    unk_04->Update();
}

int BattleDebugMenu::ov1_02135C68()
{
    return unk_04->IsActive();
}

int BattleDebugMenu::ov1_02135C78()
{
    return unk_04->GetValue(0);
}

int BattleDebugMenu::ov1_02135C8C()
{
    return unk_04->GetValue(1);
}
