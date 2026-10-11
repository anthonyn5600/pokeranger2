#include "scene/CScene.hpp"

#include "CGame.hpp"
#include "main.hpp"

extern "C" {
void sub_02007D78(void);
void sub_02007D98(void);
}

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::func4()
{
    CGame::GetInstance()->sub_02010124();
}

void CScene::func2()
{
    sub_02001210();
}

void CScene::func3()
{
    sub_02007D78();
    sub_02007D98();
}
