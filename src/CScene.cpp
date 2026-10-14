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
    sub_02001210();
}

void CScene::func3()
{
    sub_02007D78();
    LoadOam();
}
