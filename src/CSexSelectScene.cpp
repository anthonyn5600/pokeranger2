#include "scene/CSexSelectScene.hpp"

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "Camera2D.hpp"
#include "CellAnimController.hpp"
#include "Collision.hpp"
#include "DisplayUtil.hpp"
#include "FontSet.hpp"
#include "GlobalValues.hpp"
#include "MissionQuestData.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SaveData.hpp"
#include "TextboxManager.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

static const char sDefaultNameBoy[4] = "";
static const char sDefaultNameGirl[4] = "";

CSexSelectScene::CSexSelectScene()
{
    m_game = CGame::GetInstance();
    m_audioEngine = CGame::GetInstance()->m_audioEngine;
    m_audioEngine->LoadSystemSe();
    m_audioEngine->AddSeGroup(0xBC);
    m_audioEngine->AddSeGroup(0xBD);
    m_audioEngine->LoadBgmGroup(3);
    unk_04 = 1;
    unk_06 = 0;
    unk_08 = 0;
    unk_0A = 0;
}

CSexSelectScene::~CSexSelectScene()
{
    m_audioEngine->StopBgm(1);
    func7();
}

void CSexSelectScene::func6()
{
    SetupBGFonts();
    unk_20 = new Camera2D();
    unk_20->SetOrtho(0, FX32_CONST(192), 0, FX32_CONST(256), FX32_CONST(-1024), FX32_CONST(2048), FX32_CONST(1024));
    ShowQuestion();
    LoadBG();
    CreateTouchRects();
    LoadPlayerGraphics();
    LoadSprites();
    unk_68 = new CSoftwareSprite();
    unk_68->m_z = 10;
    m_audioEngine->PlayBgm(0x16, 0x40);
    m_game->m_mainFade->Start(3, 30);
    m_game->m_subFade->Start(3, 30);
}

void CSexSelectScene::func7()
{
    SAFE_DELETE(unk_6C);
    SAFE_DELETE(unk_68);
    SAFE_DELETE(unk_20);
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(unk_70[i]);
    }
    for (int i = 0; i < 2; i++) {
        SAFE_DELETE(unk_24[i]);
    }
    for (int i = 0; i < 5; i++) {
        SAFE_DELETE(unk_3C[i]);
    }
    for (int i = 0; i < 4; i++) {
        SAFE_DELETE(unk_2C[i]);
    }
    m_game->m_textboxData->Reset();
}

void CSexSelectScene::ReleaseSprites()
{
    for (int i = 0; i < 5; i++) {
        SAFE_DELETE(unk_3C[i]);
    }
}

void CSexSelectScene::LoadBG()
{
    unk_24[0] = new BGLayer(PTR_CAST(int, m_game));
    unk_24[0]->SetBG(5);
    unk_24[0]->LoadArchive("menu/", "mnd000_bg_");
    unk_24[0]->LoadChar("mnd000", 0, 0, 0);
    unk_24[0]->LoadPltt("mnd000", 0, 0, 0);
    unk_24[0]->LoadScr("mnd000_00", 0, 0, 0, 0, 0);
    unk_24[0]->ReleaseArchive();
    unk_24[0]->Setup(0x100, 0x100);
    unk_24[0]->LoadToVram();

    CArchiveGuard *archive = new CArchiveGuard("BGD", "data/menu/mps000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    CBGNCGRFile *ncgr = new CBGNCGRFile("BGD:mps000.NCGR", 1, 0, 0);
    CNCLRFile *nclr = new CNCLRFile("BGD:mps000.NCLR", 1, 0, 0);
    CNSCRFile *nscr = new CNSCRFile("BGD:mps000_00.NSCR", 1, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_MAIN3, nscr->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x04000);
    delete nscr;
    delete ncgr;
    delete nclr;
    delete archive;
}

void CSexSelectScene::ShowQuestion()
{
    CGame *game = m_game;
    game->m_textboxData->Init(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->m_nameTables, game->unk_0024, m_audioEngine, 0x10, 0x4000, 0);
    m_game->m_textboxData->LoadSystemMessages(2);
    m_game->m_textboxData->SetTextSpeed(0);
    m_game->m_textboxData->ShowSystemMessage(1, 1, 1, 0);
}

void CSexSelectScene::CreateTouchRects()
{
    unk_70[0] = new CPrimitiveRECT();
    unk_70[0]->SetPos(FX32_CONST(-56), FX32_CONST(-24));
    unk_70[0]->SetSize(FX32_CONST(80), FX32_CONST(136));
    unk_70[1] = new CPrimitiveRECT();
    unk_70[1]->SetPos(0, FX32_CONST(-24));
    unk_70[1]->SetSize(FX32_CONST(80), FX32_CONST(136));
    unk_70[2] = new CPrimitiveRECT();
    unk_70[2]->SetPos(FX32_CONST(56), FX32_CONST(-24));
    unk_70[2]->SetSize(FX32_CONST(80), FX32_CONST(136));
    unk_6C = new CPrimitiveRECT();
    unk_6C->SetPos(0, 0);
    unk_6C->SetSize(FX32_CONST(256), FX32_CONST(192));
    unk_6C->m_color = 0;
    unk_6C->m_z = 0;
}

void CSexSelectScene::LoadPlayerGraphics()
{
    unk_2C[0] = new GraphicsSet("SS6", "/data/player/player3_LZ.bin", "SS6:player3_00.NCBR", "SS6:player3.NCLR", "SS6:player3_00.NCER", "SS6:player3_00.cac");
    unk_2C[2] = new GraphicsSet("SS7", "/data/player/player4_LZ.bin", "SS7:player4_00.NCBR", "SS7:player4.NCLR", "SS7:player4_00.NCER", "SS7:player4_00.cac");
    unk_2C[1] = new GraphicsSet("SS8", "/data/player/player3_LZ.bin", "SS8:player3_02.NCBR", "SS8:player3.NCLR", "SS8:player3_02.NCER", "SS8:player3_02.cac");
    unk_0C = unk_2C[1]->m_anim->Create(1, 0);
    unk_2C[3] = new GraphicsSet("SS9", "/data/player/player4_LZ.bin", "SS9:player4_02.NCBR", "SS9:player4.NCLR", "SS9:player4_02.NCER", "SS9:player4_02.cac");
    unk_0E = unk_2C[3]->m_anim->Create(1, 0);
}

void CSexSelectScene::LoadSprites()
{
    int charNo = 0;
    unk_3C[1] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x20], m_game->unk_14A8, FALSE, 0x40);
    charNo += unk_3C[1]->Load("data/menu", "mp005_00", charNo / 32, 5);
    unk_50[2] = unk_3C[1]->AddSprite(0, 0x48, 0x4E, 0);
    unk_3C[3] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x30], m_game->unk_14A8, FALSE, 0x40);
    charNo += unk_3C[3]->Load("data/menu", "mp006_00", charNo / 32, 7);
    unk_50[3] = unk_3C[3]->AddSprite(0, 0xB8, 0x4E, 0);
    unk_3C[0] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x40], m_game->unk_14A8, FALSE, 0x40);
    unk_3C[0]->Load("data/menu", "mps000_00", charNo / 32, 9);
    unk_50[0] = unk_3C[0]->AddSprite(0, 0x48, 0x48, 3);
    unk_50[1] = unk_3C[0]->AddSprite(0, 0xB8, 0x48, 3);
}

void CSexSelectScene::LoadBoyAnim()
{
    unk_3C[2] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x20], m_game->unk_14A8, FALSE, 0x40);
    unk_3C[2]->Load("data/menu", "mps001_00", 0x100, 5);
    unk_50[4] = unk_3C[2]->AddSprite(8, 0x80, 0x70, 0);
    unk_10 = unk_3C[2]->unk_24;
    unk_3C[2]->Update();
}

void CSexSelectScene::LoadGirlAnim()
{
    unk_3C[4] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x20], m_game->unk_14A8, FALSE, 0x40);
    unk_3C[4]->Load("data/menu", "mps002_00", 0x100, 5);
    unk_50[5] = unk_3C[4]->AddSprite(8, 0x80, 0x70, 0);
    unk_14 = unk_3C[4]->unk_24;
    unk_3C[4]->Update();
}

void CSexSelectScene::func5()
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

    GX_SetBankForTex(GX_VRAM_TEX_012_ABC);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_0_G);
    GX_SetBankForOBJ(GX_VRAM_OBJ_80_EF);
    GX_SetBankForBG(GX_VRAM_BG_128_D);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    G2S_SetBG0Priority(3);
    G2S_SetBG1Priority(2);
    G2S_SetBG2Priority(1);
    G2S_SetBG3Priority(0);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG3);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG1);
    GX_DispOn();
    GXS_DispOn();
}

static inline void ClearName(SaveData *save)
{
    for (int i = 0; i < 30; i++) {
        (&save->m_playerName)[i] = 0;
    }
}

static inline void CopyName(SaveData *save, const char *name)
{
    for (int i = 0; i < 30 && *name != 0; name++, i++) {
        (&save->m_playerName)[i] = *name;
    }
}

static inline void SetPlayer(SaveData *save, u8 sex, const char *name)
{
    save->m_sex = sex;
    ClearName(save);
    CopyName(save, name);
}

u32 CSexSelectScene::func0()
{
    int ret = -1;
    switch (unk_04) {
    case 1:
        UpdateSelect();
        break;
    case 2:
        UpdateMoveToCenter();
        break;
    case 3:
        UpdateMoveBack();
        break;
    case 4:
        UpdateConfirm();
        break;
    case 5:
        UpdateDarken();
        break;
    case 6:
        UpdateEffectAnim();
        break;
    case 7:
        UpdateWait();
        break;
    case 8:
        UpdatePlayerAnim();
        break;
    case 9:
        if (!m_game->m_mainFade->IsActive() && !m_game->m_subFade->IsActive()) {
            m_game->sub_0200FAEC();
            SaveData *data = m_game->unk_14A4;
            data->unk_8B68 = 1;
            data->unk_8B6C = 0x10;
            GlobalValues_ClearChapterValues((GlobalValues *)m_game->unk_14B4);
            GlobalValues_ApplyProgress((GlobalValues *)m_game->unk_14B4, 0);
            MissionQuestData_ApplyProgress(m_game->m_missionQuestData, 0);
            SaveData *save = &MAIN_BSS_020B26A0;
            if (unk_06 == 1) {
                SetPlayer(save, 0, sDefaultNameBoy);
            } else {
                SetPlayer(save, 1, sDefaultNameGirl);
            }
            ret = 1;
        }
        break;
    }
    if (unk_04 <= 4) {
        unk_3C[0]->Update();
        unk_3C[1]->Update();
        unk_3C[3]->Update();
    }
    return ret;
}

void CSexSelectScene::UpdateSelect()
{
    CTouchPanel *tp = m_game->touchPanel;
    Point2D touch;
    touch.x = (tp->unk_0A.x - 0x80) << FX32_SHIFT;
    touch.y = (tp->unk_0A.y - 0x60) << FX32_SHIFT;
    if (tp->unk_04 == 0) {
        return;
    }
    if (PointInRect(touch, unk_70[0]->m_rectangle, 0)) {
        unk_50[0]->unk_14 = 1;
        unk_50[1]->unk_14 = 0;
        unk_50[2]->unk_14 = 1;
        unk_50[3]->unk_14 = 0;
        unk_06 = 1;
        unk_04 = 2;
        m_audioEngine->PlaySe(0xFA);
    }
    if (PointInRect(touch, unk_70[2]->m_rectangle, 0)) {
        unk_50[0]->unk_14 = 0;
        unk_50[1]->unk_14 = 1;
        unk_50[2]->unk_14 = 0;
        unk_50[3]->unk_14 = 1;
        unk_06 = 2;
        unk_04 = 2;
        m_audioEngine->PlaySe(0xFA);
    }
}

void CSexSelectScene::UpdateMoveToCenter()
{
    int button = 0;
    int x = 0;
    fx32 speed = 0;
    int sprite = 0;
    if (unk_06 == 1) {
        speed = 0x3BBB;
        button = 2;
        x = 0x48;
    }
    if (unk_06 == 2) {
        speed = -0x3BBB;
        button = 3;
        sprite = 1;
        x = 0xB8;
    }
    u16 pos = x + (u16)(FX32_MUL(speed, unk_08 << FX32_SHIFT) >> FX32_SHIFT);
    unk_50[button]->SetPos(pos, 0x4E);
    unk_50[sprite]->SetPos(pos, 0x48);
    if (unk_08 < 15) {
        unk_08++;
    }
    if (unk_08 != 15) {
        return;
    }
    unk_50[button]->SetPos(0x80, 0x4E);
    unk_50[sprite]->SetPos(0x80, 0x48);
    m_game->m_textboxData->CloseAndClear(1, 1);
    m_game->m_textboxData->SetTextSpeed(0);
    m_game->m_textboxData->ShowSystemMessage(button, 1, 0, 0);
    unk_08 = 0;
    unk_04 = 4;
}

void CSexSelectScene::UpdateMoveBack()
{
    int button = 0;
    u16 x = 0;
    fx32 speed = 0;
    int sprite = 0;
    if (unk_06 == 1) {
        speed = 0x3BBB;
        button = 2;
        x = 0x48;
    }
    if (unk_06 == 2) {
        speed = -0x3BBB;
        button = 3;
        sprite = 1;
        x = 0xB8;
    }
    u16 pos = 0x80 - (FX32_MUL(speed, unk_08 << FX32_SHIFT) >> FX32_SHIFT);
    unk_50[button]->SetPos(pos, 0x4E);
    unk_50[sprite]->SetPos(pos, 0x48);
    if (unk_08 < 15) {
        unk_08++;
    }
    if (unk_08 != 15) {
        return;
    }
    unk_50[button]->SetPos(x, 0x4E);
    unk_50[sprite]->SetPos(x, 0x48);
    unk_50[0]->unk_14 = 1;
    unk_50[1]->unk_14 = 1;
    unk_50[2]->unk_14 = 1;
    unk_50[3]->unk_14 = 1;
    m_game->m_textboxData->SetTextSpeed(0);
    m_game->m_textboxData->ShowSystemMessage(1, 1, 1, 0);
    unk_08 = 0;
    unk_04 = 1;
}

void CSexSelectScene::UpdateConfirm()
{
    u32 answer;
    TextboxManager *textbox = m_game->m_textboxData;
    if (textbox->CloseIfNoPrompt(1)) {
        return;
    }
    answer = textbox->GetYesNoResult();
    if (answer == 0) {
        unk_50[0]->unk_14 = 0;
        unk_50[1]->unk_14 = 0;
        textbox->CloseAndClear(1, 1);
        unk_04 = 5;
    }
    if (answer == 1) {
        textbox->CloseAndClear(1, 1);
        unk_04 = 3;
    }
}

void CSexSelectScene::UpdateDarken()
{
    unk_0A = FX32_MUL(FX32_DIV(unk_08 << FX32_SHIFT, FX32_CONST(60)), FX32_CONST(31)) >> FX32_SHIFT;
    if (unk_08 < 60) {
        if (unk_08 == 0) {
            G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG0, GX_BLEND_PLANEMASK_BG3, 0, 0);
        }
        unk_08++;
    } else if (unk_08 == 60) {
        unk_08 = 0;
        unk_50[2]->unk_14 = 0;
        unk_50[3]->unk_14 = 0;
        unk_04 = 6;
        ReleaseSprites();
        if (unk_06 == 1) {
            LoadBoyAnim();
        }
        if (unk_06 == 2) {
            LoadGirlAnim();
        }
    }
}

void CSexSelectScene::UpdateEffectAnim()
{
    int idx = 0;
    u16 anim = 0;
    if (unk_06 == 1) {
        idx = 2;
        anim = unk_10;
    }
    if (unk_06 == 2) {
        idx = 4;
        anim = unk_14;
    }
    OamSpriteSet *sprites = unk_3C[idx];
    if (sprites->unk_38->GetStatus(sprites->unk_08[anim]) == 0) {
        unk_04 = 7;
    }
    unk_3C[idx]->Update();
}

void CSexSelectScene::UpdateWait()
{
    unk_08++;
    if (unk_08 != 60) {
        return;
    }
    unk_08 = 0;
    unk_04 = 8;
    if (unk_06 == 1) {
        m_audioEngine->PlaySe(0xB3);
    }
    if (unk_06 == 2) {
        m_audioEngine->PlaySe(0xB4);
    }
}

void CSexSelectScene::UpdatePlayerAnim()
{
    int idx = 0;
    u16 anim = 0;
    if (unk_06 == 1) {
        idx = 1;
        anim = unk_0C;
    }
    if (unk_06 == 2) {
        idx = 3;
        anim = unk_0E;
    }
    CellAnimController *anims = unk_2C[idx]->m_anim;
    if (anims->GetStatus(anim) == 0) {
        unk_04 = 9;
        m_game->m_mainFade->Start(2, 60);
        m_game->m_subFade->Start(2, 60);
    }
    anims->UpdateAll();
}

void CSexSelectScene::func1()
{
    if (unk_20 == NULL) {
        return;
    }
    unk_20->ApplyProjection();
    unk_20->ApplyView();
    G3_StoreMtx(0);
    switch (unk_04) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        unk_3C[0]->WriteOam();
        unk_3C[1]->WriteOam();
        unk_3C[3]->WriteOam();
        break;
    case 6:
        WriteEffectOam();
        break;
    case 7:
        DrawPlayer();
        break;
    case 8:
    case 9:
        DrawPlayerAnim();
        break;
    }
    DrawDarkRect();
    G3_Identity();
    unk_20->SetOffset(0, 0);
    unk_20->ApplyProjection();
    unk_20->ApplyView();
}

void CSexSelectScene::DrawDarkRect()
{
    unk_6C->m_alpha = unk_0A;
    unk_6C->Render(unk_20);
}

void CSexSelectScene::WriteEffectOam()
{
    if (unk_06 == 1) {
        unk_3C[2]->WriteOam();
    }
    if (unk_06 == 2) {
        unk_3C[4]->WriteOam();
    }
}

void CSexSelectScene::DrawPlayer()
{
    if (unk_06 == 1) {
        DrawBoyAnim();
    }
    if (unk_06 == 2) {
        DrawGirlStill();
    }
}

void CSexSelectScene::DrawPlayerAnim()
{
    if (unk_06 == 1) {
        DrawBoyAnim();
    }
    if (unk_06 == 2) {
        DrawGirlAnim();
    }
}

void CSexSelectScene::DrawGirlStill()
{
    unk_68->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_2C[2]->m_image, NULL);
    unk_68->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_2C[2]->m_palette;
    unk_68->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_2C[2]->m_cells;
    unk_68->m_cellDataIdx = 0;
    unk_68->SetXY(0, FX32_CONST(16));
    unk_68->Render(unk_20);
}

void CSexSelectScene::DrawBoyAnim()
{
    unk_68->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_2C[1]->m_image, NULL);
    unk_68->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_2C[1]->m_palette;
    unk_68->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_2C[1]->m_cells;
    CellAnimController *anims = unk_2C[1]->m_anim;
    unk_68->m_cellDataIdx = anims->GetCell(unk_0C);
    fx32 *pos = anims->GetOffsets(unk_0C);
    unk_68->SetXY(pos[0], pos[1] + FX32_CONST(16));
    unk_68->Render(unk_20);
}

void CSexSelectScene::DrawGirlAnim()
{
    unk_68->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_2C[3]->m_image, NULL);
    unk_68->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_2C[3]->m_palette;
    unk_68->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_2C[3]->m_cells;
    CellAnimController *anims = unk_2C[3]->m_anim;
    unk_68->m_cellDataIdx = anims->GetCell(unk_0E);
    fx32 *pos = anims->GetOffsets(unk_0E);
    unk_68->SetXY(pos[0], pos[1] + FX32_CONST(16));
    unk_68->Render(unk_20);
}

u32 CSexSelectScene::getSceneId()
{
    return 0x13;
}
