#include "scene/CNameInputScene.hpp"

CNameInputScene::CNameInputScene()
{
    m_game = CGame::GetInstance();
    m_audioEngine = CGame::GetInstance()->m_audioEngine;
    m_audioEngine->sub_020345D4();
    m_audioEngine->sub_0203499C(3);
    unk_000C = 0;
    unk_0010 = 0;
    unk_0004 = 0;
    unk_0005 = 0;
    unk_0007 = 0;
    unk_0008 = 0;

    for (int i = 0; i < 4; i++) {
        unk_00BC[i] = 0;
    }

    for (int i = 0; i < 22; i++) {
        unk_0068[i] = 0;
    }
}
