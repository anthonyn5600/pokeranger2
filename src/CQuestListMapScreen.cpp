#include "CGame.hpp"
#include "UnkClass_0200E0B4.hpp"
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
    unk_08 = new UnkClass_0211FBA4(CGame::GetInstance());
    unk_08->ov27_0211FE58();
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
        unk_08->ov27_021201AC(unk_0C - 1);
    }
    game->unk_14C0->sub_0200E0E0(3, 15);
    unk_04 = 0;
}

int CQuestListMapScreen::func4()
{
    if (unk_08 != NULL && !unk_08->ov27_0211FC2C()) {
        return 0;
    }
    return 1;
}

void CQuestListMapScreen::func5()
{
    if (unk_08 == NULL) {
        return;
    }
    unk_08->ov27_0211FCE4();
}

void CQuestListMapScreen::func6()
{
    if (unk_08 == NULL) {
        return;
    }
    unk_08->ov27_0211FD34();
}
