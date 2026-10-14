#include "CGame.hpp"
#include "Camera2D.hpp"
#include "FontSet.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "file/CArchiveGuard.hpp"
#include "scene/CEncyclopediaScene.hpp"

BOOL EncycPushButton::ov22_0211F134(int id, OamSpriteSet *anims, int animNormal, int animPressed, int x, int y, int w, int h, int priority)
{
    unk_00 = id;
    unk_04[0] = anims->AddSprite(animNormal, x, y, priority);
    unk_04[1] = anims->AddSprite(animPressed, x, y, priority);
    if (unk_04[0] != NULL) {
        unk_04[0]->SetTouchRect(w, h, 0, 0);
    }
    if (unk_04[0] != NULL && unk_04[1] != NULL) {
        return TRUE;
    }
    return FALSE;
}

void EncycPushButton::ov22_0211F1D0()
{
    if (unk_1F && unk_04[0] != NULL && unk_04[1] != NULL) {
        BOOL fire = FALSE;
        if ((unk_14 & (unk_18 ^ unk_14)) || unk_04[0]->GetTouchTrigger()) {
            fire = TRUE;
            unk_10 = unk_1C;
        } else if (unk_14 != 0 || unk_04[0]->GetTouchHold()) {
            if (unk_10 > 0) {
                if (--unk_10 <= 0) {
                    fire = TRUE;
                    unk_10 = unk_1D;
                }
            }
        } else {
            unk_10 = 0;
        }
        if (fire && unk_0C != NULL) {
            unk_0C->OnPushButton(unk_00);
        }
        unk_18 = unk_14;
    }
}

void EncycPushButton::ov22_0211F2A4()
{
    if (unk_1F && unk_04[0] != NULL && unk_04[1] != NULL) {
        if (!unk_1E) {
            unk_04[0]->unk_14 = FALSE;
            unk_04[1]->unk_14 = TRUE;
        } else if ((unk_04[0]->GetTouchHold() || unk_14 != 0) && unk_10 >= 4) {
            unk_04[0]->unk_14 = FALSE;
            unk_04[1]->unk_14 = TRUE;
        } else {
            unk_04[0]->unk_14 = TRUE;
            unk_04[1]->unk_14 = FALSE;
        }
    }
}

void EncycPushButton::ov22_0211F344(BOOL arg0)
{
    unk_1E = arg0;
    if (unk_04[0] != NULL) {
        unk_04[0]->SetVisible(unk_1E);
    }
    if (unk_04[1] != NULL) {
        unk_04[1]->SetVisible(!unk_1E ? TRUE : FALSE);
    }
}

void EncycPushButton::ov22_0211F398(BOOL enabled)
{
    unk_1F = enabled;
    if (unk_1F) {
        return;
    }
    if (unk_04[0] != NULL) {
        unk_04[0]->unk_14 = FALSE;
    }
    if (unk_04[1] != NULL) {
        unk_04[1]->unk_14 = FALSE;
    }
}

void EncycPushButton::ov22_0211F3C8()
{
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
}

EncycAnimLoader::EncycAnimLoader()
{
    unk_00 = 0;
    unk_04 = 0;
    unk_08 = 0;
}

OamSpriteSet *EncycAnimLoader::ov22_0211F3F0(const char *dir, const char *name, int plttCount, int oamIdx)
{
    CGame *game = CGame::GetInstance();
    if (oamIdx < 0) {
        oamIdx = unk_08;
    }
    OamSpriteSet *anims = new OamSpriteSet((GXOamAttr *)&game->unk_0424[(u8)oamIdx], game->unk_14A8, TRUE, 0x40);
    anims->Load(dir, name, unk_00, unk_04);
    anims->Update();
    unk_00 += anims->unk_28;
    unk_04 += plttCount;
    return anims;
}

void EncycAnimLoader::ov22_0211F4A4(OamSpriteSet *anims, int oamIdx)
{
    if (oamIdx < 0) {
        oamIdx = unk_08;
    }
    int next = oamIdx + anims->unk_30;
    if (next > unk_08) {
        unk_08 = next;
    }
}

EncycMainScreen::EncycMainScreen()
    : unk_08(NULL)
{
    unk_354 = 0;
}

EncycMainScreen::~EncycMainScreen()
{
    ov22_0211F6F8();
}

void EncycMainScreen::ov22_0211F594()
{
    MtxFx22 mtx;

    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_3, GX_BG0_AS_3D);
    G2_SetBG3ControlDCBmp(GX_BG_SCRSIZE_DCBMP_256x256, GX_BG_AREAOVER_XLU, GX_BG_BMPSCRBASE_0x08000);
    MI_CpuFill16(G2_GetBG3ScrPtr(), 0x8000, 0x18000);
    G2_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    MTX_Identity22(&mtx);
    G2_SetBG3Affine(&mtx, 0, 0, 0, 0);
    G2_SetBG1Priority(0);
    G2_SetBG0Priority(1);
    G2_SetBG3Priority(2);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG0, GX_BLEND_PLANEMASK_BG3, 0, 0);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG3);
    unk_08 = new Camera2D();
    unk_08->SetOrtho(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);
}

void EncycMainScreen::ov22_0211F6F8()
{
    SAFE_DELETE(unk_08);
}

void EncycMainScreen::ov22_0211F72C()
{
    FontSet *font = CGame::GetInstance()->unk_14AC;
    void *scr = G2_GetBG1ScrPtr();
    unk_0C.ov22_02121024(&font->unk_14, scr, G2_GetBG1CharPtr(), 0, 0, 0, 32, 24, 1, 6);
    unk_354 = 0;
    for (int i = 0; i < 8; i++) {
        unk_34[i].unk_60 = i;
    }
}

static inline void LoadDCB(const char *archive, const char *file)
{
    CArchiveGuard guard("DCB", archive, 1, 1, CGame::GetInstance()->unk_14A8, NULL, 0);
    if (guard.unk_68 == NULL || guard.unk_68->unk_4C == NULL) {
        return;
    }
    char path[0x60];
    OS_SPrintf(path, "DCB:%s", file);
    CBinaryFile bin(path, 1, 0, 0, NULL, 0);
    if (bin.unk_4C == NULL) {
        return;
    }
    DC_FlushRange(bin.unk_4C, bin.unk_50);
    GX_LoadBG3Scr(bin.unk_4C, 0, bin.unk_50);
}

void EncycMainScreen::ov22_0211F7B8(const char *archive, const char *file)
{
    LoadDCB(archive, file);
}

void EncycMainScreen::ov22_0211F8A8()
{
    unk_0C.ov22_02121110();
    unk_354 = 0;
}

BOOL EncycMainScreen::ov22_0211F8C4(int x, int y, int color, const char *label, int arg4)
{
    if (unk_354 < 8) {
        unk_34[unk_354].ov22_0212112C(&unk_0C, x, y, color, label, arg4);
        unk_354++;
    }
    return TRUE;
}

void EncycMainScreen::ov22_0211F928()
{
    if (unk_08 == NULL) {
        return;
    }
    unk_08->SetOffset(-0x80000, -0x60000);
    unk_08->ApplyProjection();
    unk_08->ApplyView();
    G3_StoreMtx(0);
    for (int i = 0; i < unk_354; i++) {
        unk_34[i].ov22_021213F0(unk_08);
    }
}
