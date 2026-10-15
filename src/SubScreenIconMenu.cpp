#include "SubScreenIconMenu.hpp"

#include <nitro.h>

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "Camera2D.hpp"
#include "FieldSubScreen.hpp"
#include "GridOverlay.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "PadInput.hpp"
#include "SaveDialog.hpp"
#include "common.hpp"
#include "fx_utils.hpp"

static u16 sIconOrder[9] = { 5, 2, 1, 7, 4, 6, 8, 9, 3 };

SubScreenIconMenu::SubScreenIconMenu(CGame *game)
{
    unk_0C = game;
    Init();
}

SubScreenIconMenu::~SubScreenIconMenu()
{
    SAFE_DELETE(unk_08);
}

void SubScreenIconMenu::Update()
{
    switch (unk_00) {
    case 0:
        break;
    case 1:
        if (unk_08 != NULL) {
            unk_08->Update();
        }
        break;
    }
}

void SubScreenIconMenu::Render()
{
    switch (unk_00) {
    case 0:
        break;
    case 1:
        if (unk_08 != NULL) {
            unk_08->Render();
        }
        break;
    }
}

void SubScreenIconMenu::sub_02023470()
{
    switch (unk_00) {
    case 0:
        break;
    case 1:
        if (unk_08 != NULL) {
            unk_08->sub_020237E0();
        }
        break;
    }
}

void SubScreenIconMenu::Init()
{
    unk_00 = 0;
    unk_02 = 0;
    unk_04 = 0;
    unk_08 = new SubScreenIconMenuView(unk_0C);
}

void SubScreenIconMenu::Open()
{
    unk_08->Open();
    unk_00 = 1;
}

void SubScreenIconMenu::OpenFadeIn()
{
    unk_08->OpenFadeIn();
    unk_00 = 1;
}

void SubScreenIconMenu::OpenTimed(int timer)
{
    unk_08->OpenTimed(timer);
    unk_00 = 1;
}

BOOL SubScreenIconMenu::IsActive()
{
    return unk_08->IsActive();
}

int SubScreenIconMenu::GetSelection()
{
    if (unk_00 != 1) {
        return -1;
    }
    return unk_08->GetSelection();
}

SubScreenIconMenuView::SubScreenIconMenuView(CGame *game)
{
    m_game = game;
    Init();
}

SubScreenIconMenuView::~SubScreenIconMenuView()
{
    Release();
}

void SubScreenIconMenuView::Update()
{
    unk_18->Update();

    switch (unk_00) {
    case 2:
        if (!IsBusy()) {
            if (unk_08 == -1) {
                CloseIcons();
            } else if (unk_08 == 5) {
                StartClose();
            } else {
                FadeOut();
            }
        }
        break;
    case 9:
        if (unk_11C != NULL && !unk_11C->Update()) {
            SAFE_DELETE(unk_11C);
            GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
            StartOpen();
        }
        break;
    case 4:
        if (!IsBusy()) {
            if (unk_08 == 5) {
                SetVisible(TRUE);
                OpenSaveDialog();
            } else {
                unk_00 = 0;
                unk_6C->unk_14 = 0;
                ReleaseSprites();
            }
        }
        break;
    case 3:
        if (!IsBusy()) {
            unk_00 = 1;
        }
        break;
    case 7:
        if (!IsFading()) {
            unk_00 = 8;
            ReleaseSprites();
        }
        break;
    case 5:
        if (unk_18->unk_04 == 0) {
            unk_00 = 6;
            m_game->m_mainFade->Start(3, 0x1E);
            m_game->m_subFade->Start(3, 0x1E);
        }
        break;
    case 6:
        if (IsFading()) {
            break;
        }
        unk_00 = 1;
    case 1:
        UpdateAutoClose();
        break;
    }

    if (unk_1C != NULL) {
        unk_1C->Update();
    }
    if (unk_20 != NULL) {
        unk_20->Update();
    }
}

void SubScreenIconMenuView::Render()
{
    switch (unk_00) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
        Draw();
        break;
    }
}

void SubScreenIconMenuView::sub_020237E0()
{
}

void SubScreenIconMenuView::Init()
{
    unk_00 = 0;

    unk_0C = new Camera2D();
    unk_0C->SetOrtho(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);

    unk_18 = new GridOverlay();
    unk_18->SetZ(0x14, 0x1C, 0x1A);
    unk_18->SetPolygonID(0x28, 0x29, 0x2A);

    int i;
    for (i = 0; i < 9; i++) {
        unk_24[i] = NULL;
        unk_48[i] = NULL;
    }
    unk_6C = NULL;
    for (i = 0; i < 9; i++) {
        unk_A4[i] = 3;
    }

    unk_1C = NULL;
    unk_20 = NULL;
    unk_11C = NULL;
    m_autoClose = FALSE;
}

void SubScreenIconMenuView::CreateIcons()
{
    static const int sAnims[9] = { 0, 1, 3, 2, 7, 8, 6, 4, 5 };

    unk_1C->RemoveAll();
    unk_20->RemoveAll();

    int y;
    int x;
    int anim;
    int i;
    for (i = 0; i < 9; i++) {
        x = (i % 3) * 0x50;
        y = (i / 3) * 0x30;
        anim = sAnims[i];
        unk_24[anim] = unk_1C->AddSprite(anim, x + 0x30, y + 0x3C, 0);
        unk_48[anim] = unk_1C->AddSprite(9, x + 0x30, y + 0x3C, 0);
        unk_24[anim]->SetAffine(anim, FALSE);
        unk_48[anim]->SetAffine(anim, FALSE);
        unk_24[anim]->SetTouchRect(0x40, 0x30, 0, 0);
    }

    unk_6C = unk_20->AddSprite(0, 0xF0, 0x10, 2);
    unk_6C->SetTouchRect(0x20, 0x20, 0, 0);
    SetVisible(FALSE);
}

void SubScreenIconMenuView::Release()
{
    SAFE_DELETE(unk_11C);
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_20);
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_18);
}

void SubScreenIconMenuView::SetVisible(BOOL visible)
{
    for (int i = 0; i < 9; i++) {
        unk_24[i]->SetVisible(visible);
        unk_48[i]->SetVisible(visible);
    }
    unk_6C->SetVisible(visible);
}

void SubScreenIconMenuView::UpdateAutoClose()
{
    if (!FieldSubScreen::GetInstance()->IsRangerCardShown()) {
        return;
    }

    if (m_autoClose) {
        if (--m_closeTimer > 0) {
            return;
        }
        Close();
        return;
    }

    if (unk_6C != NULL && unk_6C->unk_14 != 0) {
        PadInput *pad = m_game->unk_0014;
        if (unk_6C->GetTouchTrigger() || (u16)(pad->unk_0002 & PAD_BUTTON_B) || (u16)(pad->unk_0002 & PAD_BUTTON_R)) {
            Close();
            return;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (unk_24[i] != NULL && unk_24[i]->GetTouchTrigger()) {
            unk_A4[i] = 5;
            unk_80[i] = 0;
            unk_00 = 2;
            unk_08 = i;
            m_game->m_audioEngine->PlaySe(0xFF);
            return;
        }
    }
}

BOOL SubScreenIconMenuView::IsBusy()
{
    for (int i = 0; i < 9; i++) {
        if (unk_A4[i] != 4 && unk_A4[i] != 3) {
            return TRUE;
        }
    }
    return FALSE;
}

void SubScreenIconMenuView::SetAffineScales(BOOL scaled)
{
    for (int i = 0; i < 9; i++) {
        if (scaled) {
            SetOamAffineScale(i, unk_C8[i], unk_EC[i], TRUE);
        } else {
            SetOamAffineScale(i, FX32_ONE, FX32_ONE, TRUE);
        }
    }
}

void SubScreenIconMenuView::UpdateIcon(u16 index)
{
    int frame = unk_80[index] + 1;
    int state = unk_A4[index];
    unk_C8[index] = FX32_ONE;
    unk_EC[index] = FX32_ONE;

    if (frame <= 0) {
        unk_80[index] = frame;
        if (unk_110) {
            unk_24[index]->unk_14 = 0;
            unk_48[index]->unk_14 = 0;
        }
        return;
    }

    unk_24[index]->unk_14 = 1;
    unk_48[index]->unk_14 = 1;

    switch (state) {
    case 0: {
        int t;
        fx32 sx;
        if (unk_110) {
            t = frame;
            if (frame == 1) {
                m_game->m_audioEngine->PlaySe(10);
            }
        } else {
            t = unk_70 - frame;
        }
        if (frame >= unk_70) {
            frame = 0;
            if (unk_110) {
                sx = FX32_ONE;
                state = 2;
            } else {
                unk_24[index]->unk_14 = 0;
                unk_48[index]->unk_14 = 0;
                state = 4;
                sx = 0x40000;
            }
        } else {
            fx32 v = FX_Div(FX_Mul((t * t) << FX32_SHIFT, FX32_ONE), unk_78);
            sx = FX_F32_TO_FX32(FX_FX64C_TO_F32(FX_DivFx64c(FX32_ONE, v)));
            if (sx >= 0x40000) {
                sx = 0x40000;
            }
        }
        unk_C8[index] = sx;
        unk_EC[index] = 0xA000;
        break;
    }
    case 2:
        if (frame >= 1) {
            frame = 0;
            if (unk_110) {
                state = 1;
            } else {
                state = 0;
            }
        }
        unk_C8[index] = FX32_ONE;
        unk_EC[index] = 0xA000;
        break;
    case 1: {
        int t;
        fx32 sy;
        if (unk_110) {
            t = unk_74 - frame;
        } else {
            t = frame;
            if (frame == 1) {
                m_game->m_audioEngine->PlaySe(10);
            }
        }
        if (frame >= unk_74) {
            frame = 0;
            if (unk_110) {
                sy = FX32_ONE;
                state = 3;
            } else {
                state = 2;
                sy = 0xA000;
            }
        } else {
            fx32 c = SolveQuadratic(FX32_ONE, 0, 0x666, unk_74 << FX32_SHIFT);
            fx32 y = Quadratic(FX32_ONE, 0x666, t << FX32_SHIFT, c);
            Quadratic(FX32_ONE, 0x666, unk_74 << FX32_SHIFT, c);
            sy = FX32_MUL(y, 0xE66) + 0x199;
            sy = FX32_DIV(FX32_ONE, sy);
            if (sy >= 0x40000) {
                sy = 0x40000;
            }
            if (sy > 0xA000) {
                sy = 0xA000;
            }
        }
        unk_C8[index] = FX32_ONE;
        unk_EC[index] = sy;
        break;
    }
    case 3:
        frame = 0;
        break;
    case 4:
        frame = 0;
        unk_24[index]->unk_14 = 0;
        unk_48[index]->unk_14 = 0;
        break;
    case 5:
        if (frame >= 6) {
            frame = 0;
            state = 3;
        }
        unk_C8[index] = 0x11C7;
        unk_EC[index] = 0x11C7;
        break;
    }

    unk_80[index] = frame;
    unk_A4[index] = state;
}

void SubScreenIconMenuView::StartPop(int popFrames, int bounceFrames, BOOL opening)
{
    unk_78 = FX_Mul(FX_Mul(popFrames << FX32_SHIFT, popFrames << FX32_SHIFT), FX32_ONE);
    unk_7C = FX_Mul(FX_Mul(bounceFrames << FX32_SHIFT, bounceFrames << FX32_SHIFT), FX32_ONE);
    unk_110 = opening;
    unk_70 = popFrames;
    unk_74 = bounceFrames;

    int state = 0;
    if (!unk_110) {
        state = 1;
    }
    for (int i = 0; i < 9; i++) {
        unk_24[sIconOrder[i] - 1]->unk_1A = 10;
        unk_80[i] = 0;
        unk_A4[i] = state;
    }
}

void SubScreenIconMenuView::Draw()
{
    G3_Identity();
    unk_0C->ApplyProjection();
    unk_0C->ApplyView();
    G3_StoreMtx(0);
    unk_18->Render(unk_0C);

    BOOL scaled = FALSE;
    switch (unk_00) {
    case 9:
        return;
    case 2:
    case 3:
    case 4:
        for (int i = 0; i < 9; i++) {
            UpdateIcon(i);
        }
        scaled = TRUE;
        break;
    }

    if (unk_1C != NULL) {
        unk_1C->WriteOam();
    }
    if (unk_20 != NULL) {
        unk_20->WriteOam();
    }
    SetAffineScales(scaled);
}

void SubScreenIconMenuView::LoadGraphics()
{
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG0, 8, 8);

    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_20);

    unk_1C = new OamSpriteSet((GXOamAttr *)m_game->unk_0024, m_game->unk_14A8, FALSE, 0x40);
    unk_20 = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x60], m_game->unk_14A8, FALSE, 0x40);

    int offset = 0x6000;
    offset += unk_1C->Load("data/menu", "cm000_00", offset / 32, 10);
    unk_20->Load("data/menu", "ma005_00", offset / 32, 13);
}

BOOL SubScreenIconMenuView::Open()
{
    unk_00 = 1;
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    Setup();
    OpenIcons();
    m_autoClose = FALSE;
    return TRUE;
}

BOOL SubScreenIconMenuView::OpenFadeIn()
{
    Setup();
    FadeIn();
    m_autoClose = FALSE;
    return TRUE;
}

void SubScreenIconMenuView::OpenTimed(int timer)
{
    unk_00 = 1;
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    Setup();
    OpenIcons();
    m_autoClose = TRUE;
    m_closeTimer = timer;
}

BOOL SubScreenIconMenuView::Close()
{
    m_game->m_audioEngine->PlaySe(0x103);
    CloseIcons();
    unk_08 = -1;
    FieldSubScreen::GetInstance()->SwitchToDefaultPanel();
    return TRUE;
}

void SubScreenIconMenuView::OpenSaveDialog()
{
    unk_00 = 9;
    SAFE_DELETE(unk_11C);
    unk_11C = new SaveDialog(m_game);
    unk_11C->Start();
}

BOOL SubScreenIconMenuView::Setup()
{
    LoadGraphics();
    CreateIcons();
    return TRUE;
}

void SubScreenIconMenuView::ReleaseSprites()
{
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_20);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
}

void SubScreenIconMenuView::CloseIcons()
{
    unk_18->Close();
    StartClose();
}

void SubScreenIconMenuView::OpenIcons()
{
    unk_18->Open();
    StartOpen();
}

void SubScreenIconMenuView::StartClose()
{
    StartPop(5, 6, FALSE);
    unk_6C->unk_14 = 1;
    unk_00 = 4;
}

void SubScreenIconMenuView::StartOpen()
{
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
    StartPop(5, 6, TRUE);
    unk_6C->unk_14 = 1;
    unk_00 = 3;
}

void SubScreenIconMenuView::FadeIn()
{
    if (m_game == NULL) {
        return;
    }
    unk_00 = 6;
    m_game->m_mainFade->Start(3, 0x1E);
    m_game->m_subFade->Start(3, 0x1E);
    unk_18->Show();
    SetVisible(TRUE);
}

void SubScreenIconMenuView::FadeOut()
{
    if (m_game == NULL) {
        return;
    }
    unk_00 = 7;
    m_game->m_mainFade->Start(4, 0x1E);
    m_game->m_subFade->Start(4, 0x1E);
}

BOOL SubScreenIconMenuView::IsFading()
{
    if (m_game->m_mainFade->IsActive() || m_game->m_subFade->IsActive()) {
        return TRUE;
    }
    return FALSE;
}

BOOL SubScreenIconMenuView::IsActive()
{
    return unk_00 != 0;
}

int SubScreenIconMenuView::GetSelection()
{
    if (unk_00 != 8) {
        return -1;
    }
    return unk_08;
}

fx32 SubScreenIconMenuView::Quadratic(fx32 a, fx32 b, fx32 t, fx32 c)
{
    return a + (FX32_MUL(b, t) + FX32_MUL(c, FX32_MUL(t, t)));
}

fx32 SubScreenIconMenuView::SolveQuadratic(fx32 start, fx32 end, fx32 b, fx32 t)
{
    return FX32_DIV(end - FX32_MUL(b, t) - start, FX32_MUL(t, t));
}
