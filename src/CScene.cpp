#include "scene/CScene.hpp"

#include "CGame.hpp"
#include "DisplayUtil.hpp"
#include "main.hpp"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::func4()
{
    CGame::GetInstance()->UpdateSystems();
}

void CScene::func2()
{
    ReportFrameTime();
}

void CScene::func3()
{
    FlushBGFonts();
    LoadOam();
}
