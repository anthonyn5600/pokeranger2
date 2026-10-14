#include "scene/COpeningDemoScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "CGame.hpp"
#include "Camera2D.hpp"
#include "OamSpriteSet.hpp"
#include "SaveData.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "scene/CTitleScene.hpp"

struct OPDTextureInfo {
    int format;
    int width;
    int height;
};

static OPDTextureInfo s_textureInfo[15] = {
    { 6, 3, 3 },
    { 6, 2, 3 },
    { 6, 2, 3 },
    { 6, 5, 5 },
    { 6, 2, 3 },
    { 1, 5, 4 },
    { 1, 5, 4 },
    { 0, 5, 5 },
    { 6, 1, 1 },
    { 6, 5, 1 },
    { 3, 5, 2 },
    { 1, 2, 2 },
    { 6, 2, 2 },
    { 1, 5, 3 },
    { 1, 5, 2 },
};

static BOOL s_captureFlip;

COpeningDemoScene::COpeningDemoScene()
    : m_screen(NULL)
    , m_current(-1)
    , m_next(-1)
{
    m_resource = NULL;
    unk_14D0 = 0;
}

COpeningDemoScene::~COpeningDemoScene()
{
}

u32 COpeningDemoScene::func0()
{
    if (s_captureFlip) {
        m_camera->SetOffset(0, -0x60000);
    } else {
        m_camera->SetOffset(0, 0x60000);
    }
    if (m_screen != NULL) {
        int next = m_screen->Update();
        if (next == -1) {
            return s_game->unk_0008 != 1 ? 14 : 1;
        }
        if (next != m_current) {
            m_next = next;
        }
    }
    return -1;
}

static void ov3_02125140(void *arg);

void COpeningDemoScene::func1()
{
    G3_Identity();
    m_camera->ApplyProjection();
    m_camera->ApplyView();
    G3_StoreMtx(0);
    G3_PushMtx();
    if (m_screen != NULL) {
        m_screen->Render(m_camera, s_captureFlip);
    }
    G3_PopMtx(1);
    s_game->AddVBlankCallback(ov3_02125140, NULL);
    if (m_next < 0) {
        return;
    }
    if (m_screen != NULL) {
        m_screen->Stop();
    }
    ov3_02124CAC(m_next);
    m_next = -1;
}

void COpeningDemoScene::func2()
{
}

void COpeningDemoScene::func3()
{
}

void COpeningDemoScene::func5()
{
    s_game->unk_146C.SetFps(60);
    m_visibleWnd = GX_GetVisibleWnd();
    m_wnd0Inside = G2_GetWnd0InsidePlane();
    m_wndOutside = G2_GetWndOutsidePlane();

    GX_ResetBankForBG();
    GX_ResetBankForOBJ();
    GX_ResetBankForBGExtPltt();
    GX_ResetBankForOBJExtPltt();
    GX_ResetBankForTex();
    GX_ResetBankForTexPltt();
    GX_ResetBankForClearImage();
    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    GX_ResetBankForSubBGExtPltt();
    GX_ResetBankForSubOBJExtPltt();
    GX_ResetBankForARM7();

    GX_SetBankForLCDC(GX_VRAM_LCDC_ALL);
    MI_CpuClearFast((void *)HW_LCDC_VRAM, HW_LCDC_VRAM_SIZE);
    GX_DisableBankForLCDC();
    MI_CpuFillFast((void *)HW_OAM, 192, HW_OAM_SIZE);
    MI_CpuClearFast((void *)HW_PLTT, HW_PLTT_SIZE);
    MI_CpuFillFast((void *)HW_DB_OAM, 192, HW_DB_OAM_SIZE);
    MI_CpuClearFast((void *)HW_DB_PLTT, HW_DB_PLTT_SIZE);

    G3_SwapBuffers(GX_SORTMODE_MANUAL, GX_BUFFERMODE_W);
    GX_SetBankForTex(GX_VRAM_TEX_01_AB);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_012345_EFG);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(FALSE);
    GX_DispOn();
    GXS_DispOn();
    ov3_02124F18();
    s_captureFlip = FALSE;

    G2_SetWnd0Position(0, 50, 255, 100);
    G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0, FALSE);
    G2_SetWndOutsidePlane(GX_WND_PLANEMASK_NONE, FALSE);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3_ViewPort(0, 0, 255, 191);
}

void COpeningDemoScene::func6()
{
    s_game->m_audioEngine->sub_02034DC8(0);
    s_game->unk_146C.SetFps(60);
    m_camera = new Camera2D();
    m_camera->SetOrtho(0, 0xC0000, 0, 0x100000, -0x800000, 0x800000, 0x10000);
    m_camera->SetOffset(0, 0);
    s_game->InitVramManagers(0x40000, 0, 0x18000);

    {
        CArchiveGuard archive("OPD", "data/opening/opdm_LZ.bin", 1, 1, 0, NULL, 0);
        for (int i = 0; i < 15; i++) {
            if (s_textureInfo[i].format != 0) {
                char ntft[0x60];
                char ntfp[0x60];
                OS_SPrintf(ntft, "OPD:opdm%02d.ntft", i);
                OS_SPrintf(ntfp, "OPD:opdm%02d.ntfp", i);
                m_textures[i].m_tex.Load(ntft, ntfp, 0);
                m_textures[i].SetSize(s_textureInfo[i].width, s_textureInfo[i].height);
                m_textures[i].unk_1C = s_textureInfo[i].format;
            }
        }
    }

    s_game->m_audioEngine->StopBgm(1);
    s_game->m_audioEngine->sub_02034C2C(1);
    if (s_game->unk_0008 != 1) {
        s_game->m_audioEngine->LoadBgmGroup(1);
    } else {
        s_game->m_audioEngine->LoadBgmGroup(2);
    }
    s_game->m_audioEngine->sub_020345D4();
    s_game->m_audioEngine->sub_020347C4();
    s_game->m_audioEngine->sub_020349E8(0xA5);
    s_game->m_audioEngine->sub_020349E8(0xA6);

    if (s_game->unk_0008 != 1) {
        m_capture.Init();
        m_title.Init();
        m_title.unk_613 = 0;
        ov3_02124CAC(0);
        m_resource = new CTitleResource();
        m_resource->Load(s_game);
        s_game->unk_14A4->unk_8BA0 = (int)m_resource;
    } else {
        m_title.Init();
        m_title.unk_613 = 1;
        ov3_02124CAC(1);
        s_game->unk_14A4->unk_8BA0 = 0;
    }
    unk_14D0 = 0;
}

void COpeningDemoScene::ov3_02124CAC(int screen)
{
    switch (screen) {
    case 1:
        m_screen = &m_title;
        break;
    case 0:
        m_screen = &m_capture;
        break;
    default:
        m_screen = NULL;
        break;
    }
    m_current = screen;
    if (m_screen != NULL) {
        m_screen->Start(m_textures);
    }
}

void COpeningDemoScene::func7()
{
    m_title.Release();
    m_capture.Release();
    if (unk_14D0) {
        SAFE_DELETE(m_resource);
        s_game->unk_14A4->unk_8BA0 = 0;
    }
    SAFE_DELETE(m_camera);
    s_game->InitVramManagers(0x80000, 0, 0x4000);
    G3X_SetClearColor(GX_RGB(0, 0, 0), 0, 0x7FFF, 0, FALSE);
    G2_SetWnd0InsidePlane(m_wnd0Inside.planeMask, m_wnd0Inside.effect);
    G2_SetWndOutsidePlane(m_wndOutside.planeMask, m_wndOutside.effect);
    GX_SetVisibleWnd(m_visibleWnd);
    GXS_SetGraphicsMode(GX_BGMODE_0);
}

void COpeningDemoScene::ov3_02124F18()
{
    int i;
    int x;
    int y;
    int idx = 0;
    GXS_SetOBJVRamModeBmp(GX_OBJVRAMMODE_BMP_2D_W256);
    for (i = 0; i < 128; i++) {
        m_subOam[i].attr01 = 0;
        m_subOam[i].attr23 = 0;
    }
    for (y = 0; y < 192; y += 64) {
        for (x = 0; x < 256; x += 64, idx++) {
            G2_SetOBJAttr(&m_subOam[idx], x, y, 0, GX_OAM_MODE_BITMAPOBJ, FALSE, GX_OAM_EFFECT_NONE, GX_OAM_SHAPE_64x64, GX_OAM_COLOR_16, (y / 8) * 32 + (x / 8), 15, 0);
        }
    }
    DC_FlushRange(m_subOam, sizeof(m_subOam));
    GXS_LoadOAM(m_subOam, 0, sizeof(m_subOam));
}

static void ov3_02124FEC()
{
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GX_ResetBankForSubOBJ();
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForLCDC(GX_VRAM_LCDC_D);
    GX_SetCapture(GX_CAPTURE_SIZE_256x192, GX_CAPTURE_MODE_A, GX_CAPTURE_SRCA_3D, (GXCaptureSrcB)0, GX_CAPTURE_DEST_VRAM_D_0x00000, 16, 0);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0);
    G2_SetBG0Priority(0);
    GXS_SetGraphicsMode(GX_BGMODE_5);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG2);
    G2S_SetBG2ControlDCBmp(GX_BG_SCRSIZE_DCBMP_256x256, GX_BG_AREAOVER_XLU, GX_BG_BMPSCRBASE_0x00000);
    G2S_SetBG2Priority(0);
    G2S_BG2Mosaic(FALSE);
}

static void ov3_021250AC()
{
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_ResetBankForSubBG();
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);
    GX_SetBankForLCDC(GX_VRAM_LCDC_C);
    GX_SetCapture(GX_CAPTURE_SIZE_256x192, GX_CAPTURE_MODE_A, GX_CAPTURE_SRCA_3D, (GXCaptureSrcB)0, GX_CAPTURE_DEST_VRAM_C_0x00000, 16, 0);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0);
    G2_SetBG0Priority(0);
    GXS_SetGraphicsMode(GX_BGMODE_5);
    GXS_SetVisiblePlane(GX_PLANEMASK_OBJ);
}

static void ov3_02125140(void *arg)
{
    if (s_captureFlip) {
        ov3_021250AC();
    } else {
        ov3_02124FEC();
    }
    s_captureFlip = !s_captureFlip;
}

u32 COpeningDemoScene::getSceneId()
{
    return 18;
}
