#include "battle/CBattleGameOver.hpp"

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_02034478.hpp"
#include "battle/CBattleDisk.hpp"
#include "primitive/CSoftwareSprite.hpp"

CBattleGameOver::CBattleGameOver(CGame *game, CBattleDisk *disk, CPlayerHPGauge *gauge)
{
    m_audio = CGame::GetInstance()->m_audioEngine;
    m_audio->sub_02034870(0x57);
    m_game = game;
    m_disk = disk;
    m_gauge = gauge;
    m_flags = 0;
    m_z = 0x400;
    ov1_0213A680();
}

CBattleGameOver::~CBattleGameOver()
{
    SAFE_DELETE(m_resA);
    SAFE_DELETE(m_resB);
    SAFE_DELETE(m_resC);
}

void CBattleGameOver::ov1_0213A680()
{
    ov1_0213A6A0();
    ov1_0213A77C();
    ov1_0213A858();
}

void CBattleGameOver::ov1_0213A6A0()
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
    m_resA = new UnkClass_0201AAE0("BOA", path, ncbr, nclr, ncer, cac);
    m_animA = m_resA->m_anim->sub_02008A80(1, 0);
}

void CBattleGameOver::ov1_0213A77C()
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
    m_resB = new UnkClass_0201AAE0("BOB", path, ncbr, nclr, ncer, cac);
    m_animB = m_resB->m_anim->sub_02008A80(1, 0);
}

void CBattleGameOver::ov1_0213A858()
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
    m_resC = new UnkClass_0201AAE0("BOC", path, ncbr, nclr, ncer, cac);
    m_animC = m_resC->m_anim->sub_02008A80(1, 0);
}

void CBattleGameOver::ov1_0213A914()
{
    m_disk->ov1_0212C4F4(FALSE);
    m_disk->ov1_0212C4EC(0);
    m_disk->ov1_0212C610(0, 0);
}

void CBattleGameOver::ov1_0213A948()
{
    m_game->unk_14BC->sub_0200E0E0(2, 20);
}

void CBattleGameOver::ov1_0213A968()
{
    m_game->unk_14BC->sub_0200E0E0(1, 8);
    m_flags &= ~0x1000;
    m_flags |= 0x2000;
}

void CBattleGameOver::ov1_0213A9A8(u16 duration)
{
    m_timer = 0;
    m_duration = duration;
}

void CBattleGameOver::ov1_0213A9BC()
{
    switch (m_state) {
    case 2:
        m_flags |= 0x1000;
        ov1_0213A9A8(90);
        break;
    case 3:
        ov1_0213A948();
        break;
    case 4:
        ov1_0213A968();
        break;
    case 5:
        ov1_0213A9A8(60);
        break;
    case 6:
        ov1_0213A9A8(60);
        break;
    case 9:
        ov1_0213AC90();
        break;
    }
    m_flags &= ~2;
}

BOOL CBattleGameOver::ov1_0213AA58()
{
    return (m_flags & 1) ? TRUE : FALSE;
}

void CBattleGameOver::ov1_0213AA70(BOOL active)
{
    if (active) {
        m_flags |= 1;
    } else {
        m_flags &= ~1;
    }
}

int CBattleGameOver::ov1_0213AA90(int z)
{
    m_z = z;
    return z;
}

void CBattleGameOver::ov1_0213AA9C()
{
    if (!m_game->unk_14BC->sub_0200E310()) {
        ov1_0213AC70();
    }
}

void CBattleGameOver::ov1_0213AAC8()
{
    UnkClass_0200E0B4 *fadeB = m_game->unk_14C0;
    if (m_game->unk_14BC->sub_0200E310()) {
        return;
    }
    if (fadeB->sub_0200E310()) {
        return;
    }
    ov1_0213AC70();
}

void CBattleGameOver::ov1_0213AB08()
{
    if (m_duration == m_timer) {
        ov1_0213AC70();
    } else if (m_duration > m_timer) {
        m_timer++;
    }
}

void CBattleGameOver::vfunc_08()
{
    switch (m_state) {
    case 1:
        ov1_0213AC70();
        break;
    case 2:
    case 5:
    case 6:
        ov1_0213AB08();
        break;
    case 3:
    case 4:
        ov1_0213AA9C();
        break;
    case 7:
        ov1_0213AAC8();
        break;
    case 8:
        ov1_0213AC70();
        break;
    case 9:
        ov1_0213AC70();
        break;
    }
    if (m_flags & 2) {
        ov1_0213A9BC();
    }
    m_resA->m_anim->sub_020089EC();
    m_resB->m_anim->sub_020089EC();
    if (m_flags & 0x2000) {
        m_resC->m_anim->sub_020089EC();
    }
    if (m_flags & 0x2000) {
        if (m_frame == 80) {
            m_audio->sub_02034C44(0x5D);
        }
        if (m_frame <= 80) {
            m_frame++;
        }
    }
}

void CBattleGameOver::ov1_0213AC30()
{
    ov1_0213A914();
    m_state = 1;
    ov1_0213AA70(TRUE);
    m_audio->sub_02034B58(30);
    m_flags |= 2;
}

void CBattleGameOver::ov1_0213AC70()
{
    m_state++;
    m_flags |= 2;
}

void CBattleGameOver::ov1_0213AC90()
{
    m_flags &= ~1;
}

void CBattleGameOver::ov1_0213ACA4(Camera2D *camera)
{
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_resA->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_resA->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_resA->m_cells;
    sprite->m_cellDataIdx = m_resA->m_anim->sub_02008828(m_animA);
    sprite->SetPos(m_disk->m_motion.GetPos());
    sprite->m_z = m_z;
    sprite->Render(camera);
}

void CBattleGameOver::ov1_0213AD3C(Camera2D *camera)
{
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_resC->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_resC->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_resC->m_cells;
    sprite->m_cellDataIdx = m_resC->m_anim->sub_02008828(m_animC);
    sprite->SetPos(m_disk->m_motion.GetPos());
    sprite->m_z = m_z;
    sprite->Render(camera);
}

void CBattleGameOver::vfunc_0C(Camera2D *camera)
{
    if (m_flags & 0x1000) {
        ov1_0213ACA4(camera);
    }
    if (m_flags & 0x2000) {
        ov1_0213AD3C(camera);
    }
}

void CBattleGameOver::vfunc_10(Camera2D *camera)
{
}
