#include "battle/CaptureResultBanner.hpp"

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CellAnimController.hpp"
#include "ScriptManager.hpp"
#include "TextboxManager.hpp"
#include "interpolation.hpp"

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

CaptureResultBanner::CaptureResultBanner(u16 type)
{
    m_type = type;
    Load(type);
    Point2D pos;
    pos.x = 0;
    pos.y = 0x18000;
    SetPos(pos);
}

CaptureResultBanner::~CaptureResultBanner()
{
    Release();
}

void CaptureResultBanner::Load(u16 type)
{
    char path[96];
    char ncbr[96];
    char nclr[96];
    char ncer[96];
    char cac[96];

    if (type == 7) {
        return;
    }
    if (type > 7) {
        return;
    }
    u8 id = type + 0x30;
    OS_SPrintf(path, "data/interface/i%03d_LZ.bin", id);
    OS_SPrintf(ncbr, "BCO:i%03d_00.NCBR", id);
    OS_SPrintf(nclr, "BCO:i%03d.NCLR", id);
    OS_SPrintf(ncer, "BCO:i%03d_00.NCER", id);
    OS_SPrintf(cac, "BCO:i%03d_00.cac", id);
    m_bannerRes = new GraphicsSet("BCO", path, ncbr, nclr, ncer, cac);
    m_anim = m_bannerRes->m_anim;
    m_animId = m_anim->Create(1, 0);
    SetSpriteRes(&m_banner, m_bannerRes->m_image, m_bannerRes->m_palette, m_bannerRes->m_cells);
    m_flashRes = new GraphicsSet("BCO", "data/interface/i055_LZ.bin", "BCO:i055_00.NCBR", "BCO:i055.NCLR", "BCO:i055_00.NCER", NULL);
    SetSpriteRes(&m_flash, m_flashRes->m_image, m_flashRes->m_palette, m_flashRes->m_cells);
    SetSpriteRes(&m_flash2, m_flashRes->m_image, m_flashRes->m_palette, m_flashRes->m_cells);
    m_ringRes = new GraphicsSet("BCO", "data/interface/i056_LZ.bin", "BCO:i056_00.NCBR", "BCO:i056.NCLR", "BCO:i056_00.NCER", NULL);
    SetSpriteRes(&m_ring, m_ringRes->m_image, m_ringRes->m_palette, m_ringRes->m_cells);
}

void CaptureResultBanner::Release()
{
    SAFE_DELETE(m_bannerRes);
    SAFE_DELETE(m_flashRes);
    SAFE_DELETE(m_ringRes);
}

void CaptureResultBanner::Update()
{
    switch (m_state) {
    case 0:
        break;
    case 1:
        UpdateStart();
        break;
    case 2:
        UpdateRingOpenX();
        break;
    case 3:
        UpdateRingOpenY();
        break;
    case 4:
        UpdateSlideIn();
        break;
    case 5:
        UpdateWait();
        break;
    case 6:
        UpdateBannerAnim();
        break;
    case 7:
        UpdateFlash();
        break;
    case 8:
        UpdateCloseTextbox();
        break;
    case 9:
        UpdateSlideOut();
        break;
    case 10:
        UpdateRingCloseY();
        break;
    case 11:
        UpdateRingCloseX();
        break;
    }
}

void CaptureResultBanner::UpdateStart()
{
    m_frame++;
    if (m_frame >= 1) {
        ScriptManager_Run(CGame::GetInstance()->m_scriptManager, "system_000");
        SetState(2);
    }
}

void CaptureResultBanner::UpdateRingOpenX()
{
    m_ring.m_scale[0] = LinearInterpolate(0x28, 0x1000, m_frame, 6);
    m_ring.SetPos(m_pos);
    m_frame++;
    if (m_frame > 6) {
        m_ring.m_scale[0] = 0x1000;
        SetState(3);
    }
}

void CaptureResultBanner::UpdateRingOpenY()
{
    m_ring.m_scale[1] = LinearInterpolate(0x28, 0x1000, m_frame, 10);
    m_ring.SetPos(m_pos);
    m_frame++;
    if (m_frame >= 10) {
        m_ring.m_scale[1] = 0x1000;
        SetState(4);
    }
}

void CaptureResultBanner::UpdateSlideIn()
{
    fx32 dx = LinearInterpolate(0x100000, -0x60000, m_frame, 8);
    Point2D pos = m_pos;
    pos.x += dx;
    m_banner.SetPos(pos);
    m_frame++;
    if (m_frame > 8) {
        SetState(5);
    }
}

void CaptureResultBanner::UpdateWait()
{
    m_frame++;
    if (m_frame > 0x30) {
        SetState(6);
    }
}

void CaptureResultBanner::UpdateBannerAnim()
{
    m_anim->Update(m_animId);
    m_banner.m_cellDataIdx = m_anim->GetCell(m_animId);
    m_frame++;
    if (m_frame > 0x20) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0x3B);
        SetState(7);
    }
}

void CaptureResultBanner::UpdateFlash()
{
    if (m_frame <= 8) {
        m_flash2.m_alpha = (u8)LinearInterpolate(31, 0, m_frame, 8);
        m_flash.m_alpha = 31;
    }
    m_anim->Update(m_animId);
    m_banner.m_cellDataIdx = m_anim->GetCell(m_animId);
    m_frame++;
    if (m_frame >= 8) {
        SetState(8);
    }
}

void CaptureResultBanner::UpdateCloseTextbox()
{
    m_frame++;
    if (m_frame > 0x18) {
        CGame::GetInstance()->m_textboxData->CloseAndClear(1, 1);
        SetState(9);
    }
}

void CaptureResultBanner::UpdateSlideOut()
{
    fx32 dx = LinearInterpolate(-0x60000, -0x180000, m_frame, 8);
    Point2D pos = m_pos;
    pos.x += dx;
    m_banner.SetPos(pos);
    dx = LinearInterpolate(0x3B000, 0x100000, m_frame, 8);
    pos.x = m_pos.x + dx;
    pos.y = m_pos.y + 0x5000;
    m_flash.SetPos(pos);
    m_flash2.SetPos(pos);
    m_frame++;
    if (m_frame > 8) {
        SetState(10);
    }
}

void CaptureResultBanner::UpdateRingCloseY()
{
    m_ring.m_scale[1] = LinearInterpolate(0x1000, 0x28, m_frame, 10);
    m_frame++;
    if (m_frame > 10) {
        m_ring.m_scale[1] = 0x28;
        SetState(11);
    }
}

void CaptureResultBanner::UpdateRingCloseX()
{
    m_ring.m_scale[0] = LinearInterpolate(0x1000, 0x28, m_frame, 6);
    m_frame++;
    if (m_frame > 6) {
        SetState(0);
    }
}

void CaptureResultBanner::Render(Camera2D *camera)
{
    if (!IsActive()) {
        return;
    }
    SetZ(0x406);
    m_banner.Render(camera);
    m_flash.Render(camera);
    m_flash2.Render(camera);
    m_ring.Render(camera);
}

void CaptureResultBanner::Start()
{
    if (m_type == 7) {
        return;
    }
    SetState(1);
    m_ring.SetScale(0x28, 0x28);
    m_ring.SetPos(m_pos);
    m_flash.m_cellDataIdx = 0;
    m_flash.m_alpha = 0;
    m_flash.SetXY(m_pos.x + 0x3B000, m_pos.y + 0x5000);
    m_flash2.m_cellDataIdx = 1;
    m_flash2.m_alpha = 0;
    m_flash2.SetXY(m_pos.x + 0x3B000, m_pos.y + 0x5000);
    m_banner.SetXY(m_pos.x + 0x100000, m_pos.y);
}

void CaptureResultBanner::SetState(int state)
{
    m_frame = 0;
    m_state = state;
}

int CaptureResultBanner::SetZ(int z)
{
    z += m_ring.GetCellNumOAMAttrs(m_ring.m_cellDataIdx);
    m_ring.m_z = z;
    z += m_banner.GetCellNumOAMAttrs(m_banner.m_cellDataIdx);
    m_banner.m_z = z;
    z += m_flash.GetCellNumOAMAttrs(m_flash.m_cellDataIdx);
    m_flash.m_z = z;
    z += m_flash2.GetCellNumOAMAttrs(m_flash2.m_cellDataIdx);
    m_flash2.m_z = z;
    return z;
}
