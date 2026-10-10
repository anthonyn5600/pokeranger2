#include "scene/CScene.hpp"

#include "CGame.hpp"
#include "main.hpp"

extern "C" {
CGame *sub_0201001C(void);
void sub_02010124(CGame *game);
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
    sub_02010124(sub_0201001C());
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
