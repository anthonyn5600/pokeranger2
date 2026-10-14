#include "scene/CCompanyLogoScene.hpp"

#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "DisplayUtil.hpp"
#include "TextboxManager.hpp"
#include "UnkClass_0212F3DC.hpp"

static void ov11_0213251C(void *arg);

CCompanyLogoScene::CCompanyLogoScene()
{
    unk_04 = 0;
    unk_08 = 0;
    unk_0C = NULL;
    unk_24 = 0;
    unk_1C = NULL;
    unk_20 = 0;
    for (int i = 0; i < 3; i++) {
        unk_10[i] = NULL;
    }
}

CCompanyLogoScene::~CCompanyLogoScene()
{
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_0C);
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(unk_10[i]);
    }
}

u32 CCompanyLogoScene::func0()
{
    if (unk_20 != 0) {
        unk_20 = unk_1C->ov11_0212F46C();
    }
    switch (unk_08) {
    case 0:
        unk_0C->sub_02028408(1);
        unk_08 = 1;
    case 1: {
        u32 result = unk_0C->sub_0202841C();
        if (result == 0) {
            break;
        }
        if (!(result & 0x80)) {
            unk_24 = 2;
            unk_08 = 4;
            break;
        }
        switch (result & 0x7F) {
        case 1:
        case 2:
        case 4:
        case 6:
        case 8:
            unk_24 = 3;
            unk_08 = 4;
            break;
        case 0:
        case 3:
        case 5:
        case 7:
        default:
            unk_24 = 1;
            unk_08 = 2;
            break;
        }
        break;
    }
    case 2:
        unk_0C->sub_02028408(0);
        unk_08 = 3;
        break;
    case 3: {
        u32 result = unk_0C->sub_0202841C();
        if (result == 0) {
            break;
        }
        if (!(result & 0x80)) {
            unk_24 = 2;
            unk_08 = 4;
            break;
        }
        switch (result & 0x7F) {
        case 1:
        case 2:
        case 4:
        case 6:
        case 8:
            unk_24 = 3;
            unk_08 = 4;
            break;
        case 0:
        case 3:
        case 5:
        case 7:
        default:
            unk_24 = 1;
            unk_08 = 4;
            break;
        }
        break;
    }
    case 4:
        s_game->unk_14BC->Start(1, 10);
        s_game->unk_14C0->Start(1, 10);
        unk_08 = 5;
        break;
    case 5:
        if (!s_game->unk_14BC->IsActive() && !s_game->unk_14C0->IsActive()) {
            unk_08 = 6;
            unk_04 = 0;
        }
        break;
    case 6:
        if (++unk_04 > 60) {
            unk_08 = 7;
            unk_04 = 0;
        }
        break;
    case 7: {
        int brightness;
        if (++unk_04 > 10) {
            unk_04 = 0;
            unk_08 = 8;
            unk_10[2]->LoadCharToVram();
            unk_10[2]->LoadPlttToVram(0);
            unk_10[2]->LoadScrToVram();
            brightness = 0x1F | (0x1F << 16);
        } else {
            brightness = unk_04 * 31 / 10;
            brightness |= brightness << 16;
        }
        s_game->AddVBlankCallback(ov11_0213251C, (void *)brightness);
        break;
    }
    case 8: {
        int brightness;
        if (++unk_04 > 10) {
            unk_04 = 0;
            unk_08 = 9;
            brightness = 0x1F;
        } else {
            brightness = 0x1F | (((10 - unk_04) * 31 / 10) << 16);
        }
        s_game->AddVBlankCallback(ov11_0213251C, (void *)brightness);
        break;
    }
    case 9:
        if (++unk_04 > 60) {
            unk_08 = 10;
            s_game->unk_14BC->Start(4, 10);
            s_game->unk_14C0->Start(4, 10);
        }
        break;
    case 10:
        if (!s_game->unk_14BC->IsActive() && !s_game->unk_14C0->IsActive()) {
            if (unk_24 == 3) {
                unk_08 = 13;
            } else {
                unk_08 = 12;
            }
        }
        break;
    case 11:
        break;
    case 12:
        if (unk_20 == 0) {
            return 0x12;
        }
        break;
    case 13:
        s_game->unk_14BC->Start(3, 0);
        GX_SetVisiblePlane(GX_PLANEMASK_NONE);
        s_game->m_textboxData->ShowMessage(0, 0x45, 1, 1, 0);
        unk_08 = 14;
        break;
    case 14:
        break;
    }
    return -1;
}

void CCompanyLogoScene::func1()
{
}

void CCompanyLogoScene::func2()
{
}

void CCompanyLogoScene::func5()
{
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

    GX_SetBankForBG(GX_VRAM_BG_256_AB);
    GX_SetBankForOBJ(GX_VRAM_OBJ_NONE);
    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_DisableBankForSubBG();
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_48_HI);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_NONE);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0);
    GX_DispOn();
    GXS_DispOn();

    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x08000, GX_BG_EXTPLTT_01);
    G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x8000, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);
}

void CCompanyLogoScene::func6()
{
    s_game->unk_146C.SetFps(60);
    unk_08 = 0;
    unk_04 = 0;
    unk_24 = 0;
    unk_0C = new SaveManager(1);
    s_game->m_textboxData->Init(s_game->unk_0014, s_game->touchPanel, &s_game->unk_14AC->unk_0C, s_game->unk_14B0, s_game->unk_0024, s_game->m_audioEngine, 0x10, 0x4000, 0);
    s_game->m_textboxData->LoadSystemMessages(0);

    unk_10[0] = new BGLayer((int)s_game);
    unk_10[1] = new BGLayer((int)s_game);
    unk_10[2] = new BGLayer((int)s_game);
    unk_10[0]->SetBG(4);
    unk_10[1]->SetBG(0);
    unk_10[2]->SetBG(4);

    unk_10[0]->LoadArchive("title/", "copyright000_");
    unk_10[0]->LoadChar("copyright000", 0, 0, 0);
    *(u16 *)unk_10[0]->LoadPltt("copyright000", 0, 0, 0) = 0;
    unk_10[0]->LoadScr("copyright000", 0, 0, 0, 0, 0);
    unk_10[0]->ReleaseArchive();

    unk_10[1]->LoadArchive("title/", "copyright001_");
    unk_10[1]->LoadChar("copyright001", 0, 0, 0);
    *(u16 *)unk_10[1]->LoadPltt("copyright001", 0, 0, 0) = 0;
    unk_10[1]->LoadScr("copyright001", 0, 0, 0, 0, 0);
    unk_10[1]->ReleaseArchive();

    unk_10[2]->LoadArchive("title/", "copyright002_");
    unk_10[2]->LoadChar("copyright002", 0, 0, 0);
    *(u16 *)unk_10[2]->LoadPltt("copyright002", 0, 0, 0) = 0;
    unk_10[2]->LoadScr("copyright002", 0, 0, 0, 0, 0);
    unk_10[2]->ReleaseArchive();

    unk_10[0]->LoadCharToVram();
    unk_10[0]->LoadPlttToVram(FALSE);
    unk_10[0]->LoadScrToVram();
    unk_10[1]->LoadCharToVram();
    unk_10[1]->LoadPlttToVram(FALSE);
    unk_10[1]->LoadScrToVram();

    s_game->m_audioEngine->sub_020345D4();
}

void CCompanyLogoScene::func7()
{
    SAFE_DELETE(unk_0C);
    s_game->unk_146C.SetFps(30);
    s_game->m_textboxData->FreeSystemMessages();
    G2_SetBlendBrightness(GX_BLEND_PLANEMASK_BG0, 0);
    G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG0, 0);
    s_game->m_textboxData->Reset();
}

// VBlank callback: arg = main brightness | sub brightness << 16
static void ov11_0213251C(void *arg)
{
    int brightness = (int)arg;
    G2_SetBlendBrightness(GX_BLEND_PLANEMASK_BG0, (u16)brightness);
    G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG0, (u16)(brightness >> 16));
}

u32 CCompanyLogoScene::getSceneId()
{
    return 0x11;
}
