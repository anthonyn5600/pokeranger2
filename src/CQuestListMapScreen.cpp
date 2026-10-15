#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "scene/CQuestListScene.hpp"

CQuestListMapScreen::CQuestListMapScreen()
{
    unk_08 = NULL;
    unk_0C = 0;
}

CQuestListMapScreen::~CQuestListMapScreen()
{
    SAFE_DELETE(unk_08);
}

void CQuestListMapScreen::func0()
{
    SAFE_DELETE(unk_08);
    unk_08 = new QuestListMap(CGame::GetInstance());
    unk_08->Load();
}

void CQuestListMapScreen::func1()
{
    SAFE_DELETE(unk_08);
}

void CQuestListMapScreen::func2()
{
}

void CQuestListMapScreen::func3(int prev)
{
    CGame *game = CGame::GetInstance();
    if (unk_08 != NULL && unk_0C > 0) {
        unk_08->Start(unk_0C - 1);
    }
    game->m_subFade->Start(3, 15);
    unk_04 = 0;
}

int CQuestListMapScreen::func4()
{
    if (unk_08 != NULL && !unk_08->Update()) {
        return 0;
    }
    return 1;
}

void CQuestListMapScreen::func5()
{
    if (unk_08 == NULL) {
        return;
    }
    unk_08->Render();
}

void CQuestListMapScreen::func6()
{
    if (unk_08 == NULL) {
        return;
    }
    unk_08->OnVBlank();
}
