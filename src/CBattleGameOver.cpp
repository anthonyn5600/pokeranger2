#include "battle/CBattleGameOver.hpp"

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CellAnimController.hpp"
#include "battle/CBattleDisk.hpp"
#include "primitive/CSoftwareSprite.hpp"

CBattleGameOver::CBattleGameOver(CGame *game, CBattleDisk *disk, CPlayerHPGauge *gauge)
{
    m_audio = CGame::GetInstance()->m_audioEngine;
    m_audio->LoadBattleSeGroup(0x57);
    m_game = game;
    m_disk = disk;
    m_gauge = gauge;
    m_flags = 0;
    m_z = 0x400;
    LoadGraphics();
}

CBattleGameOver::~CBattleGameOver()
{
    SAFE_DELETE(m_resA);
    SAFE_DELETE(m_resB);
    SAFE_DELETE(m_resC);
}

void CBattleGameOver::LoadGraphics()
{
    LoadResA();
    LoadResB();
    LoadResC();
}

void CBattleGameOver::LoadResA()
{
    char cac[96];
    char ncer[96];
    char nclr[96];
    char ncbr[96];
    char path[96];

    OS_SPrintf(path, "data/interface/i%03d_LZ.bin", 19);
    OS_SPrintf(ncbr, "BOA:i%03d_%02d.NCBR", 19, 2);
    OS_SPrintf(nclr, "BOA:i%03d.NCLR", 19);
    OS_SPrintf(ncer, "BOA:i%03d_%02d.NCER", 19, 2);
    OS_SPrintf(cac, "BOA:i%03d_%02d.cac", 19, 2);
    m_resA = new GraphicsSet("BOA", path, ncbr, nclr, ncer, cac);
    m_animA = m_resA->m_anim->Create(1, 0);
}

void CBattleGameOver::LoadResB()
{
    char cac[96];
    char ncer[96];
    char nclr[96];
    char ncbr[96];
    char path[96];

    OS_SPrintf(path, "data/interface/i%03d_LZ.bin", 19);
    OS_SPrintf(ncbr, "BOB:i%03d_%02d.NCBR", 19, 3);
    OS_SPrintf(nclr, "BOB:i%03d.NCLR", 19);
    OS_SPrintf(ncer, "BOB:i%03d_%02d.NCER", 19, 3);
    OS_SPrintf(cac, "BOB:i%03d_%02d.cac", 19, 3);
    m_resB = new GraphicsSet("BOB", path, ncbr, nclr, ncer, cac);
    m_animB = m_resB->m_anim->Create(1, 0);
}

void CBattleGameOver::LoadResC()
{
    char cac[96];
    char ncer[96];
    char nclr[96];
    char ncbr[96];
    char path[96];

    OS_SPrintf(path, "data/interface/i019_LZ.bin");
    OS_SPrintf(ncbr, "BOC:i019_03.NCBR");
    OS_SPrintf(nclr, "BOC:i019.NCLR");
    OS_SPrintf(ncer, "BOC:i019_03.NCER");
    OS_SPrintf(cac, "BOC:i019_03.cac");
    m_resC = new GraphicsSet("BOC", path, ncbr, nclr, ncer, cac);
    m_animC = m_resC->m_anim->Create(1, 0);
}

void CBattleGameOver::ov1_0213A914()
{
    m_disk->ov1_0212C4F4(FALSE);
    m_disk->SetVisible(0);
    m_disk->ResetLine(0, 0);
}

void CBattleGameOver::StartWhiteOut()
{
    m_game->m_mainFade->Start(2, 20);
}

void CBattleGameOver::StartWhiteIn()
{
    m_game->m_mainFade->Start(1, 8);
    m_flags &= ~0x1000;
    m_flags |= 0x2000;
}

void CBattleGameOver::StartWait(u16 duration)
{
    m_timer = 0;
    m_duration = duration;
}

void CBattleGameOver::EnterState()
{
    switch (m_state) {
    case 2:
        m_flags |= 0x1000;
        StartWait(90);
        break;
    case 3:
        StartWhiteOut();
        break;
    case 4:
        StartWhiteIn();
        break;
    case 5:
        StartWait(60);
        break;
    case 6:
        StartWait(60);
        break;
    case 9:
        Finish();
        break;
    }
    m_flags &= ~2;
}

BOOL CBattleGameOver::IsActive()
{
    return (m_flags & 1) ? TRUE : FALSE;
}

void CBattleGameOver::SetActive(BOOL active)
{
    if (active) {
        m_flags |= 1;
    } else {
        m_flags &= ~1;
    }
}

int CBattleGameOver::SetZ(int z)
{
    m_z = z;
    return z;
}

void CBattleGameOver::WaitMainFade()
{
    if (!m_game->m_mainFade->IsActive()) {
        NextState();
    }
}

void CBattleGameOver::WaitFades()
{
    BrightnessFade *fadeB = m_game->m_subFade;
    if (m_game->m_mainFade->IsActive()) {
        return;
    }
    if (fadeB->IsActive()) {
        return;
    }
    NextState();
}

void CBattleGameOver::WaitTimer()
{
    if (m_duration == m_timer) {
        NextState();
    } else if (m_duration > m_timer) {
        m_timer++;
    }
}

void CBattleGameOver::vfunc_08()
{
    switch (m_state) {
    case 1:
        NextState();
        break;
    case 2:
    case 5:
    case 6:
        WaitTimer();
        break;
    case 3:
    case 4:
        WaitMainFade();
        break;
    case 7:
        WaitFades();
        break;
    case 8:
        NextState();
        break;
    case 9:
        NextState();
        break;
    }
    if (m_flags & 2) {
        EnterState();
    }
    m_resA->m_anim->UpdateAll();
    m_resB->m_anim->UpdateAll();
    if (m_flags & 0x2000) {
        m_resC->m_anim->UpdateAll();
    }
    if (m_flags & 0x2000) {
        if (m_frame == 80) {
            m_audio->PlaySe(0x5D);
        }
        if (m_frame <= 80) {
            m_frame++;
        }
    }
}

void CBattleGameOver::Start()
{
    ov1_0213A914();
    m_state = 1;
    SetActive(TRUE);
    m_audio->StopBgm(30);
    m_flags |= 2;
}

void CBattleGameOver::NextState()
{
    m_state++;
    m_flags |= 2;
}

void CBattleGameOver::Finish()
{
    m_flags &= ~1;
}

void CBattleGameOver::DrawResA(Camera2D *camera)
{
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_resA->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_resA->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_resA->m_cells;
    sprite->m_cellDataIdx = m_resA->m_anim->GetCell(m_animA);
    sprite->SetPos(m_disk->m_motion.GetPos());
    sprite->m_z = m_z;
    sprite->Render(camera);
}

void CBattleGameOver::DrawResC(Camera2D *camera)
{
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_resC->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_resC->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_resC->m_cells;
    sprite->m_cellDataIdx = m_resC->m_anim->GetCell(m_animC);
    sprite->SetPos(m_disk->m_motion.GetPos());
    sprite->m_z = m_z;
    sprite->Render(camera);
}

void CBattleGameOver::vfunc_0C(Camera2D *camera)
{
    if (m_flags & 0x1000) {
        DrawResA(camera);
    }
    if (m_flags & 0x2000) {
        DrawResC(camera);
    }
}

void CBattleGameOver::vfunc_10(Camera2D *camera)
{
}
