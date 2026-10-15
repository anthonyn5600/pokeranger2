#include "battle/BattleDebugMenu.hpp"

#include "CGame.hpp"
#include "DebugProcess.hpp"

BattleDebugMenu::BattleDebugMenu(CGame *game)
{
    m_game = game;
    unk_04 = new DebugProcessManager(game->GetPrinter(), PTR_CAST(u32, game->unk_0014));
}

BattleDebugMenu::~BattleDebugMenu()
{
    unk_04->CloseAll();
    SAFE_DELETE(unk_04);
}

void BattleDebugMenu::ResetResult()
{
    unk_04->SetValue(0, 0);
    unk_04->SetValue(1, 0);
}

void BattleDebugMenu::Update()
{
    unk_04->Update();
}

int BattleDebugMenu::IsActive()
{
    return unk_04->IsActive();
}

int BattleDebugMenu::GetResultId()
{
    return unk_04->GetValue(0);
}

int BattleDebugMenu::GetResultValue()
{
    return unk_04->GetValue(1);
}
