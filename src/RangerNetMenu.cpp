#include "RangerNetMenu.hpp"

#include <dwc.h>
#include <nitro/ctrdg.h>
#include <nitro/wm.h>
#include <nnsys/fnd.h>
#include <string.h>

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPowerManage.hpp"
#include "CTouchPanel.hpp"
#include "DownloadStationScan.hpp"
#include "DwcConnection.hpp"
#include "MessageTable.hpp"
#include "MissionDownload.hpp"
#include "OamSpriteSet.hpp"
#include "PadInput.hpp"
#include "RangerNetExchange.hpp"
#include "RangerNetMenuItem.hpp"
#include "RangerNetMissionList.hpp"
#include "RangerNetSendBin.hpp"
#include "SaveManager.hpp"
#include "SubTextPrinter.hpp"
#include "TextPrinter.hpp"
#include "fx_utils.hpp"
#include "heap.hpp"

int AgbCheck_GetMissionNo();

extern BOOL OVERLAY11_BSS_02169B40; // set by the WM_Reset/WM_End callbacks
static void WmResetCallback(void *arg);
static void WmEndCallback(void *arg);
BOOL StopWm();
void WirelessDriver_Init();

extern "C" void thunk_FUN_overlay_11__02128b40(); // wireless lib (D4), ov11_02128C08
fx32 EvalQuadratic(fx32 start, fx32 b, fx32 t, fx32 a);
fx32 SolveQuadraticAccel(fx32 start, fx32 end, fx32 b, fx32 t);
int GetItemY(int pos);
#include "DiskHPTable.hpp"
#include "FieldData.hpp"
#include "MissionQuestData.hpp"
#include "SaveData.hpp"

extern FieldData *MAIN_BSS_0210CA6C;
extern "C" {
BOOL DownloadMissionRecord_IsValid(DownloadMissionRecord *obj, DownloadMissionRecord *other);
int DownloadMissionRecord_GetStatus(DownloadMissionRecord *obj, int bit);
void DownloadMissionData_Reset(DownloadMissionData *obj);
void DownloadMissionData_ResetStep(DownloadMissionData *obj);
int DownloadMissionData_Load(DownloadMissionData *obj, int list);
int DownloadMissionClears_Get(DownloadMissionClears *obj, int bit);
int DownloadMissionData_Save(DownloadMissionData *obj, int list);
}
fx32 QuadraticVelocity(fx32 a, fx32 b);

RangerNetMenu::RangerNetMenu(CGame *game, int arg)
{
    unk_72C = game;
    if (arg != 0) {
        ov11_0211E1DC();
    } else {
        Init();
    }
}

RangerNetMenu::~RangerNetMenu()
{
    Release();
}

void RangerNetMenu::Init()
{
    InitBase();
    unk_718 = new DwcConnection(unk_72C);
    unk_714 = new MissionDownload(unk_72C, unk_718, this);
    unk_71C = new RangerNetExchange(this);
    unk_720 = new RangerNetSendBin(unk_72C, this);
    SetState(0, 0);
    unk_002 = 0;
    unk_044 = MAIN_BSS_0210CA6C;
    unk_008 = new MessageTable("/data/message/etc/place_name");
    unk_350[unk_364] = 0;
    unk_59C = -1;
    unk_0EC = 0;
}

void RangerNetMenu::ov11_0211E1DC()
{
    InitBase();
}

void RangerNetMenu::InitBase()
{
    unk_000 = 0;
    unk_00C = NULL;
    unk_010 = NULL;
    unk_0A8 = NULL;
    unk_0AC = NULL;
    unk_0B0 = NULL;
    unk_0B4 = NULL;
    for (int i = 0; i < 3; i++) {
        unk_0C4[i] = NULL;
    }
    unk_038 = 0;
    unk_718 = NULL;
    unk_714 = NULL;
    unk_71C = NULL;
    unk_720 = NULL;
    unk_724 = NULL;
    unk_014 = new OamSprite *[25];
    unk_01C = new u8[0x64];
    unk_020 = new u8[0x64];
    SetState(0, 0);
    unk_002 = 0;
    unk_044 = NULL;
    unk_008 = NULL;
    unk_350[unk_364] = 0;
    unk_59C = -1;
    unk_620 = new DownloadMissionData();
    DownloadMissionData_Reset(unk_620);
    unk_0EC = 0;
    unk_700 = NULL;
    unk_364 = 0;
    unk_708 = NULL;
    unk_728 = new SaveManager(1);
}

void RangerNetMenu::Update()
{
    if (unk_724 != NULL) {
        unk_724->Update();
    }
    if (IsFading()) {
        return;
    }
    switch (unk_000) {
    case 1:
        UpdateLoad();
        break;
    case 15:
        UpdateAgbDownload();
        break;
    case 4:
        UpdateWifiDownload();
        break;
    case 5:
        UpdateLocalDownload();
        break;
    case 6:
        UpdateSendEgg();
        break;
    case 7:
        UpdateSendPokemon();
        break;
    case 3:
        UpdateMenu();
        break;
    case 8:
        UpdateWfcSettings();
        break;
    case 9:
        UpdateButtonSelect();
        break;
    case 10:
        UpdateReset();
        break;
    case 14:
        SetState(0xD, 0xFFFF);
        break;
    case 12:
        SetState(0xB, 0xFFFF);
        break;
    case 16:
        break;
    }
    UpdateSprites();
}

void RangerNetMenu::Draw()
{
    if (unk_724 != NULL) {
        unk_724->Draw();
    }
    DrawSprites();
}

void RangerNetMenu::ov11_0211E438()
{
    if (unk_724 != NULL) {
        unk_724->PrintText();
    }
    LoadButtonGraphics();
    PrintMessage();
}

void RangerNetMenu::LoadSprites()
{
    static s16 sPositions[] = {
        9,
        0x90,
        0x18,
        10,
        0x30,
        0x18,
        11,
        0x30,
        0x18,
        12,
        0x30,
        0x18,
        13,
        0x30,
        0x18,
        14,
        0x30,
        0x18,
        15,
        0x30,
        0x18,
        16,
        0x90,
        0x18,
        17,
        0x90,
        0x18,
        18,
        0x90,
        0x18,
        19,
        0x90,
        0x18,
        20,
        0x30,
        0x18,
        21,
        0x30,
        0x18,
        23,
        0x30,
        0x18,
        24,
        0x30,
        0x18,
        -1,
        -1,
        -1,
    };
    char name[0x40];
    int i;

    unk_040 = 0;
    unk_03C = 0;
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);

    if (unk_010 != NULL) {
        Heap_Free(unk_010);
        unk_010 = NULL;
    }
    unk_010 = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[unk_03C], unk_72C->unk_14A8, TRUE, 0x40);
    unk_040 += unk_010->Load("data/menu", "ma005_64", unk_040 / 32, 0);
    unk_014[0] = unk_010->AddSprite(0, 0xF0, 0x10, 0);
    unk_014[0]->SetTouchRect(0x20, 0x20, 0, 0);
    unk_5F8 = unk_010->unk_24;
    unk_03C += unk_010->unk_30;

    for (i = 0; i < 22; i++) {
        unk_048[i] = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[unk_03C], unk_72C->unk_14A8, TRUE, 0x40);
        OS_SPrintf(name, "rn001_%02d", i + 10);
        u32 size = unk_048[i]->LoadFiles("data/menu", name, unk_040 / 32, 1);
        if (i < 4) {
            unk_108[i].InitLabel(unk_048, i, unk_040);
            unk_03C += unk_048[i]->unk_30;
            unk_040 += size;
        }
    }

    if (unk_00C != NULL) {
        Heap_Free(unk_00C);
        unk_00C = NULL;
    }
    unk_00C = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[unk_03C], unk_72C->unk_14A8, TRUE, 0x40);
    unk_040 += unk_00C->Load("data/menu", "rn001_00", unk_040 / 32, 1);
    for (i = 1; i < 5; i++) {
        unk_014[i] = unk_00C->AddSprite(3, 0x80, 0x78 - i * 0x18, 0);
        unk_60C[i] = unk_00C->unk_24;
    }
    unk_014[5] = unk_00C->AddSprite(5, 0x94, 0xB5, 0);
    unk_014[6] = unk_00C->AddSprite(10, 0xA4, 0xB5, 0);
    unk_014[9] = unk_00C->AddSprite(2, 0x80, 0xB4, 1);
    unk_014[12] = unk_00C->AddSprite(0, 0x50, 0xB4, 0);
    unk_014[13] = unk_00C->AddSprite(1, 0xB0, 0xB4, 0);
    unk_014[20] = unk_00C->AddSprite(0x17, 0xB0, 0xB4, 0);
    unk_014[21] = unk_00C->AddSprite(0x18, 0x50, 0xB4, 0);
    unk_014[22] = unk_00C->AddSprite(0x13, 0x80, 0x60, 2);
    unk_014[22]->unk_28 = 1;
    unk_014[22]->SetAffine(0, 0);
    unk_014[7] = unk_00C->AddSprite(6, 0xC, 0xC, 0);
    unk_5FC = unk_00C->unk_24;
    unk_014[8] = unk_00C->AddSprite(0xB, 0xC, 0xC, 0);
    unk_600 = unk_00C->unk_24;
    for (i = 0; i < 2; i++) {
        unk_0A0[i] = unk_00C->AddSprite(i + 0x11, 0x10, 0, 0);
    }
    for (i = 0; i < 4; i++) {
        unk_108[i].InitFrame(unk_00C);
        unk_108[i].unk_18 = unk_0A0;
    }
    unk_03C += unk_00C->unk_30;

    if (unk_0A8 != NULL) {
        Heap_Free(unk_0A8);
        unk_0A8 = NULL;
    }
    unk_0A8 = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[unk_03C], unk_72C->unk_14A8, TRUE, 0x40);
    int offset = unk_040 / 32;
    unk_040 += unk_0A8->LoadFiles("data/menu", "rn001_01", offset, 1);
    unk_0A8->CopyToVram();
    unk_4AC = 1;
    unk_014[10] = unk_0A8->AddSprite(0, 0x50, 0xB4, 0);
    unk_014[11] = unk_0A8->AddSprite(1, 0xB0, 0xB4, 0);
    unk_014[16] = unk_0A8->AddSprite(2, 0x80, 0xB4, 0);
    unk_014[17] = unk_0A8->AddSprite(3, 0x80, 0xB4, 0);

    if (unk_0AC != NULL) {
        Heap_Free(unk_0AC);
        unk_0AC = NULL;
    }
    unk_0AC = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[unk_03C], unk_72C->unk_14A8, TRUE, 0x40);
    unk_0AC->LoadFiles("data/menu", "rn001_02", offset, 1);
    unk_014[14] = unk_0AC->AddSprite(0, 0x50, 0xB4, 0);
    unk_014[15] = unk_0AC->AddSprite(1, 0xB0, 0xB4, 0);
    unk_014[18] = unk_0AC->AddSprite(2, 0x80, 0xB4, 0);
    unk_014[19] = unk_0AC->AddSprite(3, 0x80, 0xB4, 0);
    unk_014[23] = unk_0AC->AddSprite(4, 0xB0, 0xB4, 0);
    unk_014[24] = unk_0AC->AddSprite(5, 0x50, 0xB4, 0);

    for (i = 0; sPositions[i * 3] != -1; i++) {
        unk_014[sPositions[i * 3]]->SetTouchRect(sPositions[i * 3 + 1], sPositions[i * 3 + 2], 0, 0);
    }

    unk_03C += unk_0A8->unk_30;
    u8 oam = unk_03C;
    int charOffset = unk_040;
    if (unk_0B0 != NULL) {
        Heap_Free(unk_0B0);
        unk_0B0 = NULL;
    }
    unk_0B0 = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[oam], unk_72C->unk_14A8, TRUE, 0x40);
    charOffset += unk_0B0->LoadFiles("data/menu", "rn001_03", charOffset / 32, 9);
    oam += unk_0B0->unk_30;
    if (unk_0B4 != NULL) {
        Heap_Free(unk_0B4);
        unk_0B4 = NULL;
    }
    unk_0B4 = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[oam], unk_72C->unk_14A8, TRUE, 0x40);
    unk_0B4->LoadFiles("data/menu", "rn001_04", charOffset / 32, 9);

    for (i = 0; i < 3; i++) {
        OS_SPrintf(name, "rn001_%02d", i + 7);
        if (unk_0C4[i] != NULL) {
            Heap_Free(unk_0C4[i]);
            unk_0C4[i] = NULL;
        }
        unk_0C4[i] = new OamSpriteSet((GXOamAttr *)&unk_72C->unk_0424[unk_03C], unk_72C->unk_14A8, TRUE, 0x40);
        unk_0C4[i]->LoadFiles("data/menu", name, unk_040 / 32, 9);
    }

    ClearItems();
    HideAllButtons();
    SetLinkIcon(0, -1);
    if (unk_724 != NULL) {
        Heap_Free(unk_724);
        unk_724 = NULL;
    }
    unk_724 = new RangerNetMissionList(unk_72C, this);
    unk_724->Load();
    unk_724->ShowMessage(0, 0, NULL);
    UpdateWaitIcon(0);
    SetMessageLayout(3);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3, 10, 6);
    unk_72C->m_audioEngine->LoadBgmGroup(3);
    unk_72C->m_audioEngine->LoadSystemSe();
    unk_72C->m_audioEngine->AddSeGroup(0xC6);
    unk_014[5]->SetVisible(FALSE);
    unk_014[6]->SetVisible(FALSE);
    unk_0B8 = 0x42680;
}

void RangerNetMenu::StartDownloadAnim()
{
    unk_0B0->CopyToVram();
    ClearDownloadAnim();
    unk_0BC = unk_0B0->AddSprite(0, unk_0B8 / 1000, 0x5C, 2);
}

void RangerNetMenu::ClearDownloadAnim()
{
    unk_0B0->RemoveAll();
}

void RangerNetMenu::InitDownloadDoneSprite()
{
    unk_0B4->CopyToVram();
    unk_0B4->RemoveAll();
    unk_0C0 = unk_0B4->AddSprite(0, 0x120, 0x5C, 2);
}

void RangerNetMenu::InitSendAnim(int i)
{
    unk_0D0 = unk_0C4[i]->AddSprite(0, 0x80, 0x90, 1);
    unk_0C4[i]->CopyToVram();
    unk_0D0->SetVisible(FALSE);
    unk_0D0->SetAffine(1, FALSE);
    unk_0D8 = 0;
    unk_0E8 = 0;
}

void RangerNetMenu::UpdateDownloadAnim()
{
    unk_0B8 -= 600;
    if (unk_0B8 <= -32000) {
        unk_0B8 = 0x42680;
    }
    unk_0BC->SetPos(unk_0B8 / 1000, 0x5C);
}

void RangerNetMenu::FinishDownloadAnim()
{
    InitDownloadDoneSprite();
    unk_0BC->SetVisible(FALSE);
    unk_0C0->SetPos(unk_0B8 / 1000, 0x5C);
}

BOOL RangerNetMenu::UpdateSendAnim()
{
    fx32 v;
    switch (unk_0D8) {
    case 0:
        unk_0E0 = 60;
        unk_0D0->SetVisible(TRUE);
        unk_0D8 = 1;
        unk_0EC = 1;
        for (int i = 0; i < 2; i++) {
            unk_0F8[i] = FX32_ONE;
            unk_100[i] = FX32_ONE;
        }
        break;
    case 1:
        if (--unk_0E0 <= 0) {
            unk_0D8 = 2;
            unk_0F0 = SolveQuadraticAccel(0, 0x1F000, 0, 0x3C000);
            unk_0E0 = 0;
        }
        break;
    case 2:
        UpdateSendPulse();
        unk_014[22]->SetVisible(TRUE);
        if (++unk_0E0 < 60) {
            v = EvalQuadratic(0, 0, unk_0E0 << 12, unk_0F0);
        } else {
            unk_0D8 = 3;
            unk_0E0 = 60;
            v = 0x1F000;
        }
        G2S_ChangeBlendAlpha(v >> 12, 16);
        break;
    case 3:
        UpdateSendPulse();
        if (--unk_0E0 <= 0) {
            unk_0DC = 0;
            unk_0D8 = 4;
        }
        break;
    case 4:
        UpdateSendPulse();
        if (!UpdateSendLaunch()) {
            StartSendFadeOut();
            return FALSE;
        }
        break;
    }
    return TRUE;
}

void RangerNetMenu::UpdateSendPulse()
{
    unk_0E8 += 4;
    u16 deg = unk_0E8 % 180;
    fx32 s = FX32_MUL(FX_SinIdx(deg * 0x10000 / 360), FX32_ONE) + 0x9000;
    fx32 q = FX32_DIV(s, 0xA000);
    unk_0F8[0] = q;
    unk_0F8[0] = FX32_DIV(FX32_ONE, q);
}

void RangerNetMenu::StartSendFadeOut()
{
    unk_0E0 = 60;
}

BOOL RangerNetMenu::UpdateSendFadeOut()
{
    UpdateSendPulse();
    fx32 a = SolveQuadraticAccel(0, 0x1F000, 0, 0x3C000);
    fx32 v = 0;
    if (--unk_0E0 > 0) {
        v = EvalQuadratic(0, 0, unk_0E0 << 12, a);
    }
    G2S_ChangeBlendAlpha(v >> 12, 16);
    return unk_0E0 > 0;
}

BOOL RangerNetMenu::UpdateSendLaunch()
{
    switch (unk_0DC) {
    case 0:
        unk_0F8[1] = FX32_ONE;
        unk_0DC++;
        unk_0E0 = 20;
        break;
    case 1:
        if (--unk_0E0 <= 0) {
            unk_0F0 = SolveQuadraticAccel(0xA000, 0x1000, 0, 0x5000);
            unk_0F4 = SolveQuadraticAccel(0x1000, 0, 0, 0xC000);
            unk_0DC++;
            unk_0E0 = 0;
            unk_0E4 = 0;
            CGame::GetInstance()->m_audioEngine->PlaySe(0xCD);
        }
        break;
    case 2:
        if (unk_0E0 < 5) {
            unk_0E0++;
        }
        fx32 v = EvalQuadratic(0xA000, 0, unk_0E0 << 12, unk_0F0);
        unk_0F8[1] = FX32_DIV(FX32_ONE, FX32_DIV(v, 0xA000));
        if (unk_0E4 < 12) {
            unk_0E4++;
        }
        fx32 w = EvalQuadratic(0x1000, 0, unk_0E4 << 12, unk_0F4);
        unk_0D0->SetPos(0x80, (FX32_MUL(w, 0xB0000) >> 12) - 0x20);
        if (unk_0E4 >= 12) {
            return FALSE;
        }
        break;
    }
    return TRUE;
}

void RangerNetMenu::Release()
{
    int i;
    thunk_FUN_overlay_11__02128b40();
    unk_72C->unk_1498->FreeWindows();
    SAFE_DELETE(unk_00C);
    SAFE_DELETE(unk_010);
    SAFE_DELETE(unk_0A8);
    SAFE_DELETE(unk_0AC);
    SAFE_DELETE(unk_0B0);
    SAFE_DELETE(unk_0B4);
    if (unk_014 != NULL) {
        delete unk_014;
        unk_014 = NULL;
    }
    if (unk_01C != NULL) {
        delete unk_01C;
        unk_01C = NULL;
    }
    if (unk_020 != NULL) {
        delete unk_020;
        unk_020 = NULL;
    }
    for (i = 0; i < 22; i++) {
        SAFE_DELETE(unk_048[i]);
    }
    SAFE_DELETE(unk_724);
    for (i = 0; i < 3; i++) {
        SAFE_DELETE(unk_0C4[i]);
    }
    SAFE_DELETE(unk_718);
    SAFE_DELETE(unk_714);
    SAFE_DELETE(unk_71C);
    SAFE_DELETE(unk_720);
    SAFE_DELETE(unk_008);
    SAFE_DELETE(unk_620);
    for (i = 0; i < 8; i++) {
        SAFE_DELETE(unk_534[i]);
    }
    for (i = 0; i <= 2; i++) {
        SAFE_DELETE(unk_584[i]);
    }
    if (unk_700 != NULL) {
        Heap_Free(unk_700);
        unk_700 = NULL;
    }
    SAFE_DELETE(unk_708);
    SAFE_DELETE(unk_728);
}

void RangerNetMenu::ClearItems()
{
    for (int i = 0; i < 4; i++) {
        unk_108[i].SetActive(FALSE);
        unk_108[i].SetVisible(FALSE);
        unk_328[i] = -1;
    }
    unk_33C[unk_364] = 0;
    SetArrowsVisible(FALSE);
}

void RangerNetMenu::HideAllButtons()
{
    for (int i = 9; i <= 24; i++) {
        unk_014[i]->SetVisible(FALSE);
    }
}

void RangerNetMenu::SetupMainMenu()
{
    static int sIds[] = { 0, 1, 4, 5 };
    int n = 0;
    for (int i = 0; i < 4; i++) {
        int type = 0;
        BOOL found;
        int v;
        if (HasItem(sIds[i])) {
            continue;
        }
        switch (i) {
        case 0:
            v = ov11_02120150();
            if (v < 0) {
                found = FALSE;
            } else {
                type = v;
                found = TRUE;
            }
            break;
        case 1:
            v = GetMissionsIcon();
            if (v < 0) {
                found = FALSE;
            } else {
                type = v;
                found = TRUE;
            }
            break;
        case 2:
            v = GetTransferIcon();
            if (v < 0) {
                found = FALSE;
            } else {
                type = v;
                found = TRUE;
            }
            break;
        case 3:
            type = 3;
            found = TRUE;
            break;
        default:
            found = TRUE;
            break;
        }
        if (found) {
            int slot = FindFreeItem();
            int idx = FindFreeRow();
            SetRowItem(slot, idx);
            unk_108[slot].SetId(sIds[i]);
            unk_108[slot].SetIcon(type);
            unk_108[slot].SetState(0, 1);
            if (n % 2 != 0) {
                unk_108[slot].SlideInLeft(idx);
            } else {
                unk_108[slot].SlideInRight(idx);
            }
            n++;
        }
    }
    unk_014[5]->SetVisible(FALSE);
    unk_014[6]->SetVisible(FALSE);
    unk_014[9]->SetVisible(FALSE);
}

void RangerNetMenu::SetLinkIcon(int mode, int level)
{
    if (unk_710 == 0) {
        mode = 0;
    }
    switch (mode) {
    case 0:
        unk_014[7]->SetVisible(FALSE);
        unk_014[8]->SetVisible(FALSE);
        unk_710 = 0;
        break;
    case 1:
        unk_014[7]->SetVisible(TRUE);
        unk_014[8]->SetVisible(FALSE);
        if (level < 0) {
            level = DWC_GetLinkLevel();
        }
        unk_00C->SetAnim(unk_5FC, 9 - level);
        break;
    case 2:
        if (level < 0) {
            level = WM_GetLinkLevel();
        }
        unk_014[7]->SetVisible(FALSE);
        unk_014[8]->SetVisible(TRUE);
        unk_00C->SetAnim(unk_600, 14 - level);
        break;
    }
}

void RangerNetMenu::SetBackButton(int mode)
{
    switch (mode) {
    case 3:
        unk_014[0]->SetVisible(FALSE);
        break;
    case 4:
        unk_014[0]->SetVisible(TRUE);
        unk_010->SetAnim(unk_5F8, 0);
        break;
    case 5:
        unk_014[0]->SetVisible(TRUE);
        unk_010->SetAnim(unk_5F8, 1);
        break;
    }
}

// FC60: `delay = 0` at the declaration is dead but makes IRO split delay before n (register order of cases 0/1).
int RangerNetMenu::SetupSubMenu()
{
    static int sIds0[] = { 6, 7 };
    static int sIds1[] = { 1, 2, 3 };
    static int sIds4[] = { 8, 10, 9 };
    int delay = 0;
    int type = 0;
    int slot;
    int idx;
    int n;

    unk_4B4 = 0;
    switch (unk_350[unk_364 - 1]) {
    case 0:
        for (n = 0, delay = 0; n < (sizeof(sIds0) / sizeof(sIds0[0])); n++, delay += 0x5000) {
            switch (sIds0[n]) {
            case 6:
                if (ov11_02120170() == -1) {
                    continue;
                }
                type = 3;
                break;
            case 7:
                if (unk_72C->unk_15DC == 0) {
                    continue;
                }
                type = 4;
                break;
            }
            slot = FindFreeItem();
            idx = FindFreeRow();
            SetRowItem(slot, idx);
            unk_108[slot].SetId(sIds0[n]);
            unk_108[slot].SetIcon(type);
            unk_108[slot].SetState(0, 1);
            unk_108[slot].SlideInBottom(idx, delay);
        }
        break;
    case 1:
        for (n = 0, delay = 0; n < (sizeof(sIds1) / sizeof(sIds1[0])); n++, delay += 0x5000) {
            if (HasItem(sIds1[n])) {
                continue;
            }
            int a = 0;
            BOOL delayed = TRUE;
            switch (sIds1[n]) {
            case 1:
                a = 2;
                type = 0;
                delayed = FALSE;
                break;
            case 2:
                type = GetSpecialMissionsIcon();
                if (type == -1) {
                    continue;
                }
                break;
            case 3:
                type = GetExtraMissionsIcon();
                if (type == -1) {
                    continue;
                }
                break;
            }
            slot = FindFreeItem();
            idx = FindFreeRow();
            SetRowItem(slot, idx);
            unk_108[slot].SetId(sIds1[n]);
            unk_108[slot].SetIcon(type);
            unk_108[slot].SetState(a, 1);
            if (delayed) {
                unk_108[slot].SlideInBottom(idx, delay);
            } else {
                unk_108[slot].SlideInLeft(idx);
            }
        }
        break;
    case 2: {
        int n = 0;
        int kind;
        unk_4B4 = 0;
        for (int i = 0; i < 3; i++) {
            SetEntry(i, -1, 0, 0);
            if (unk_638[i] >= 0) {
                switch (unk_638[i]) {
                case 1:
                    kind = 1;
                    break;
                case 2:
                    kind = 2;
                    break;
                case 0:
                default:
                    kind = 0;
                    break;
                }
                SetEntry(n, i + 11, kind, 1);
                n++;
            }
        }
        ShowPage(0, 1);
        break;
    }
    case 3: {
        int kind;
        n = 0;
        unk_4B4 = 0;
        for (int i = 0; i < 3; i++) {
            SetEntry(i, -1, 0, 0);
            if (unk_644[i] >= 0) {
                switch (unk_644[i]) {
                case 1:
                    kind = 1;
                    break;
                case 2:
                    kind = 2;
                    break;
                case 0:
                default:
                    kind = 0;
                    break;
                }
                SetEntry(n, i + 14, kind, 1);
                n++;
            }
        }
        ShowPage(0, 1);
        break;
    }
    case 4:
        n = 0;
        for (int i = 0; i < 3; i++) {
            BOOL show = FALSE;
            switch (unk_62C[i]) {
            case 0:
                break;
            case 1:
                type = 1;
                show = TRUE;
                break;
            case 2:
                show = TRUE;
                type = 0;
                break;
            }
            if (show) {
                slot = FindFreeItem();
                idx = FindFreeRow();
                SetRowItem(slot, idx);
                unk_108[slot].SetId(sIds4[i]);
                unk_108[slot].SetIcon(type);
                unk_108[slot].SetState(0, type == 1);
                unk_108[slot].SlideInBottom(idx, n * 0x5000);
                n++;
            }
        }
        break;
    }
    return 0;
}

int RangerNetMenu::ov11_02120150()
{
    int result = 4;
    if (ov11_02120170() == -1) {
        result = -1;
    }
    return result;
}

int RangerNetMenu::ov11_02120170()
{
    return 0;
}

int RangerNetMenu::GetMissionsIcon()
{
    int a = GetSpecialMissionsIcon();
    int b = GetExtraMissionsIcon();
    if (b != -1 && a != 1) {
        a = b;
    }
    return a;
}

static inline int GetStateResult(const int *states)
{
    int result = 0;
    BOOL found = FALSE;
    for (int i = 0; i < 3; i++) {
        if (states[i] >= 0) {
            if (states[i] == 1) {
                result = 1;
            }
            found = TRUE;
        }
    }
    if (!found) {
        result = -1;
    }
    return result;
}

int RangerNetMenu::GetSpecialMissionsIcon()
{
    return GetStateResult(unk_638);
}

int RangerNetMenu::GetExtraMissionsIcon()
{
    return GetStateResult(unk_644);
}

static inline int GetFlagResult(const int *states)
{
    int result = 0;
    BOOL found = FALSE;
    for (int i = 0; i < 3; i++) {
        if (states[i] != 0) {
            found = TRUE;
            if (states[i] == 1) {
                result = 1;
            }
        }
    }
    if (!found) {
        result = -1;
    }
    return result;
}

int RangerNetMenu::GetTransferIcon()
{
    return GetFlagResult(unk_62C);
}

int RangerNetMenu::FindItem(int id)
{
    for (int i = 0; i < 4; i++) {
        if (unk_108[i].unk_38 != 0 && id == unk_108[i].unk_54) {
            return i;
        }
    }
    return -1;
}

BOOL RangerNetMenu::HasItem(int id)
{
    return FindItem(id) >= 0 ? TRUE : FALSE;
}

void RangerNetMenu::UpdateLoad()
{
    switch (unk_002) {
    case 0:
        unk_650 = 0;
        unk_002 = 1;
    case 1:
        if (DownloadMissionRecord_IsValid(&MAIN_BSS_020AF5E4[unk_650], &MAIN_BSS_020AF5E4[unk_650])) {
            unk_62C[unk_650] = DownloadMissionRecord_GetStatus(&MAIN_BSS_020AF5E4[unk_650], unk_650);
        } else {
            unk_62C[unk_650] = 0;
        }
        if (++unk_650 < 3) {
            return;
        }
        unk_650 = 0;
        unk_002 = 2;
        DownloadMissionData_ResetStep(unk_620);
    case 2:
        switch (DownloadMissionData_Load(unk_620, unk_650)) {
        case 1:
            unk_002 = 3;
            break;
        case -1:
            unk_638[unk_650] = -1;
            unk_002 = 4;
            break;
        case -2:
            unk_638[unk_650] = -1;
            SetState(0x11, 0xFFFF);
            break;
        case 0:
            break;
        }
        break;
    case 3:
        if (DownloadMissionClears_Get(&MAIN_BSS_020AF598, unk_650)) {
            unk_638[unk_650] = 2;
        } else {
            unk_638[unk_650] = 1;
        }
        unk_002 = 4;
        break;
    case 4:
        if (++unk_650 < 6) {
            DownloadMissionData_ResetStep(unk_620);
            unk_002 = 2;
            return;
        }
        FadeIn();
        SetState(3, 0);
        unk_002 = 0;
        unk_72C->m_audioEngine->PlayBgm(0x16, 0);
        break;
    }
}

void RangerNetMenu::UpdateMenu()
{
    int r;
    switch (unk_002) {
    case 0:
        if (IsFading()) {
            return;
        }
        unk_002 = 1;
        SetupMainMenu();
        ShowMessage(0, 5, 3, 1);
        ShowTopMessage(0, 5, 0);
        SetButtonMode(0x19);
        SetBackButton(4);
        SetLinkIcon(0, -1);
        break;
    case 1:
        if (IsItemMoving(-1)) {
            return;
        }
        SaveItems(unk_364);
        SelectItem(FindItem(unk_350[unk_364]));
        unk_002 = 2;
        break;
    case 2:
        r = HandleItemInput(1);
        if (r == 4) {
            return;
        }
        if (r >= 0) {
            ChooseItem(r);
        } else {
            ExitToTitle();
        }
        break;
    case 4:
        if (unk_708 == NULL) {
            return;
        }
        if (unk_708->Update()) {
            return;
        }
        SAFE_DELETE(unk_708);
        unk_002 = 5;
        break;
    case 5:
        if (IsItemMoving(-1)) {
            return;
        }
        MoveRow(unk_33C[unk_364 - 1], 0);
        unk_002 = 6;
        break;
    case 6:
        if (IsItemMoving(-1)) {
            return;
        }
        unk_108[unk_328[0]].SetState(2, 1);
        SetupSubMenu();
        unk_002 = 7;
        break;
    case 7:
        if (IsItemMoving(-1)) {
            return;
        }
        SaveItems(unk_364);
        SelectItem(GetRowItem(1));
        unk_002 = 8;
        break;
    case 8:
        if (unk_4B4 != 0) {
            BOOL changed = FALSE;
            switch (UpdateButtonSelect()) {
            case 0x17:
                if (unk_4B0 < 1) {
                    unk_4B0++;
                    changed = TRUE;
                }
                break;
            case 0x18:
                if (unk_4B0 > 0) {
                    unk_4B0--;
                    changed = TRUE;
                }
                break;
            default:
                if (unk_52C == 2) {
                    SetArrowsVisible(changed);
                    return;
                }
                break;
            }
            if (changed) {
                unk_524 = 0;
                SetArrowsVisible(FALSE);
                ShowPage(unk_4B0, 0);
                SelectItem(GetRowItem(1));
                return;
            }
        }
        r = HandleItemInput(1);
        if (r == 4) {
            return;
        }
        if (r >= 0) {
            ChooseItem(r);
        } else {
            GoBack();
        }
        break;
    case 9: {
        if (IsItemMoving(-1)) {
            return;
        }
        int slot = GetRowItem(0);
        unk_108[slot].SetState(0, 1);
        unk_108[slot].SetIcon(unk_51C);
        unk_350[--unk_364] = unk_108[slot].unk_54;
        MoveRow(0, unk_33C[unk_364]);
        unk_002 = 11;
        break;
    }
    case 10:
        if (IsItemMoving(-1)) {
            return;
        }
        SelectItem(FindItem(unk_350[unk_364]));
        unk_002 = 8;
        break;
    case 11:
        if (IsItemMoving(-1)) {
            return;
        }
        switch (unk_350[unk_364]) {
        case 2:
        case 3:
            RestoreItems(unk_364);
            unk_002 = 10;
            break;
        default:
            unk_002 = 1;
            SetBackButton(4);
            SetupMainMenu();
            break;
        }
        break;
    case 3:
        if (IsItemMoving(-1)) {
            return;
        }
        unk_108[GetRowItem(GetSelectedRow())].SlideOutTop();
        unk_002 = 12;
        break;
    case 12:
        if (IsItemMoving(-1)) {
            return;
        }
        OpenItem();
        break;
    case 13:
        r = UpdateButtonSelect();
        if (r == -2) {
            return;
        }
        if (r == 0xE) {
            StartMission();
            return;
        }
        ReturnToMenu(unk_350[unk_364 - 2]);
        break;
    case 14:
        if (!CheckContinue()) {
            return;
        }
        ShowMessage(0, 5, 3, 1);
        unk_002 = 10;
        SetArrowsVisible(TRUE);
        break;
    case 15:
        break;
    }
}

void RangerNetMenu::UpdateLocalDownload()
{
    switch (unk_002) {
    case 0:
        unk_002 = 3;
        WirelessDriver_Init();
        unk_71C->SetState(2);
        SetBackButton(3);
        break;
    case 3: {
        int state = unk_71C->Update();
        if (state == 8 || state == 10) {
            StartReset();
        }
        break;
    }
    }
}

void RangerNetMenu::UpdateSendEgg()
{
    switch (unk_002) {
    case 0:
        unk_002 = 1;
        ShowMessage(2, 3, 1, 1);
        ShowTopMessage(1, 3, 1);
        ShowButtons(0x11);
        break;
    case 1:
        switch (UpdateButtonSelect()) {
        case -2:
            return;
        case 0x13:
            unk_002 = 2;
            break;
        default:
            ReturnToMenu(4);
            break;
        }
        break;
    case 2:
        ShowMessage(4, 3, 1, 0);
        ShowTopMessage(3, 3, 1);
        unk_002 = 3;
        WirelessDriver_Init();
        unk_71C->SetState(14);
        SetBackButton(5);
        unk_710 = 1;
        break;
    case 3: {
        int state = unk_71C->Update();
        if (state == 8 || state == 10) {
            StartReset();
        }
        break;
    }
    }
}

void RangerNetMenu::UpdateSendPokemon()
{
    switch (unk_002) {
    case 0:
        unk_002 = 1;
        ShowMessage(2, 4, 0, 1);
        ShowTopMessage(1, 4, 1);
        ShowButtons(0x11);
        break;
    case 1:
        switch (UpdateButtonSelect()) {
        case -2:
            return;
        case 0x13:
            unk_002 = 2;
            break;
        default:
            ReturnToMenu(4);
            break;
        }
        break;
    case 2:
        ShowMessage(4, 4, 1, 0);
        ShowTopMessage(3, 4, 1);
        unk_002 = 3;
        WirelessDriver_Init();
        unk_710 = 1;
        unk_720->Start(unk_604);
        SetBackButton(5);
        break;
    case 3: {
        BOOL busy = unk_720->Update();
        SetLinkIcon(2, -1);
        if (busy) {
            return;
        }
        if (StopWm()) {
            unk_002 = 4;
        } else {
            unk_002 = 5;
        }
        break;
    }
    case 4:
        if (!OVERLAY11_BSS_02169B40) {
            return;
        }
        OVERLAY11_BSS_02169B40 = FALSE;
        WM_End(WmEndCallback);
        unk_002 = 5;
        break;
    case 5:
        if (!OVERLAY11_BSS_02169B40) {
            return;
        }
        StartReset();
        break;
    }
}

void RangerNetMenu::UpdateWifiDownload()
{
    int r;
    switch (unk_002) {
    case 0:
        unk_002 = 1;
        ShowMessage(0x10, 0, 1, 1);
        ShowButtons(0xB);
        break;
    case 1:
        r = UpdateButtonSelect();
        if (r == -2) {
            return;
        }
        if (r == 0xE) {
            unk_002 = 2;
            WirelessDriver_Init();
            unk_714->Start();
            ShowMessage(0x16, 0, 0, 1);
            SetBackButton(5);
        } else {
            ReturnToMenu(0);
        }
        break;
    case 2:
        r = unk_714->Update();
        SetLinkIcon(1, -1);
        switch (r) {
        case 0:
            StartReset();
            break;
        case 1:
            StartReset();
            break;
        case 2:
            break;
        case 3:
            StartReset();
            break;
        }
        break;
    }
}

void RangerNetMenu::UpdateAgbDownload()
{
    int r;
    switch (unk_002) {
    case 0:
        SetupAgbMissionList();
        FadeIn();
        unk_002 = 1;
        break;
    case 1:
        if (!IsFading()) {
            unk_002 = 2;
        }
        break;
    case 2:
        r = UpdateMissionSelect();
        if (r < 0) {
            return;
        }
        unk_6EC = r - 0xB;
        unk_002 = 3;
        ShowMessage(4, 1, 1, 1);
        break;
    case 3:
        StartDownloadAnim();
        unk_002 = 4;
        StartSaveMissions(unk_700);
        ShowMessage(6, 1, 1, 1);
        break;
    case 4:
        r = UpdateSaveMissions();
        if (r == 0) {
            return;
        }
        if (r < 0) {
            ShowMessage(0xD, 1, 0, 1);
            unk_002 = 7;
        } else {
            ShowDownloadedMessage(unk_6EC, TRUE);
            unk_002 = 6;
        }
        break;
    case 5:
    case 6:
    case 7:
        break;
    }
}

void RangerNetMenu::StartSaveMissions(void *buf)
{
    unk_6F4 = buf;
    unk_6FC = 2;
}

int RangerNetMenu::UpdateSaveMissions()
{
    int r;
    switch (unk_6FC) {
    case 0:
    case 1:
        break;
    case 2:
        DownloadMissionData_ResetStep(unk_620);
        unk_6F0 = 0;
        unk_6FC = 3;
        break;
    case 3:
        UpdateDownloadAnim();
        for (; unk_6F0 < 6; unk_6F0++) {
            if (ReadMissionFile(unk_6F0, unk_6F4, MAIN_BSS_020AF620.unk_00.unk_04)) {
                unk_6FC = 4;
                DownloadMissionData_ResetStep(unk_620);
                break;
            }
        }
        if (unk_6F0 >= 6) {
            unk_6F8 = 120;
            FinishDownloadAnim();
            unk_6FC = 6;
            unk_72C->m_audioEngine->StopSe(0xD1);
            unk_72C->m_audioEngine->PlaySe(0xF0);
        }
        break;
    case 4:
        UpdateDownloadAnim();
        r = DownloadMissionData_Save(unk_620, unk_6F0);
        if (r == 0) {
            break;
        }
        if (r == 1) {
            unk_6F0++;
            unk_6FC = 3;
            break;
        }
        return -1;
    case 5:
        break;
    case 6:
        if (--unk_6F8 <= 0) {
            return 1;
        }
        break;
    }
    return 0;
}

int RangerNetMenu::UpdateButtonSelect()
{
    int r;
    switch (unk_52C) {
    case 0:
        unk_52C = 1;
    case 1:
        unk_70C = 0;
        r = HandleButtonInput();
        if (r == -1) {
            unk_014[6]->SetVisible(FALSE);
            return -1;
        }
        if (r >= 0) {
            unk_528 = r;
            unk_52C = 2;
            unk_524 = 0;
        }
        break;
    case 2:
        if (++unk_524 >= 30) {
            HideButtons();
            return unk_528;
        }
        break;
    }
    return -2;
}

int RangerNetMenu::UpdateReset()
{
    switch (unk_002) {
    case 1:
        if (!CheckContinue()) {
            break;
        }
        unk_002 = 2;
        FadeOutToWhite();
    case 2:
        if (!IsFading()) {
            ResetSystem();
        }
        break;
    }
    return -1;
}

void RangerNetMenu::ResetSystem()
{
    CPowerManage::SetMode(0);
    OS_ResetSystem(0);
}

void RangerNetMenu::StartReset()
{
    unk_002 = 2;
    SetState(0xA, 0xFFFF);
    FadeOutToWhite();
}

int RangerNetMenu::UpdateMissionSelect()
{
    int slot;
    switch (unk_530) {
    case 0:
        unk_530 = 1;
        ShowMessage(0, 5, 3, 1);
    case 1:
        if (IsItemMoving(-1)) {
            break;
        }
        slot = GetRowItem(1);
        if (slot < 0) {
            slot = GetRowItem(0);
        }
        SelectItem(slot);
        unk_530 = 3;
        break;
    case 2:
        break;
    case 3: {
        int id = UpdateItemSelect();
        if (id < 0) {
            break;
        }
        slot = FindItem(id);
        SelectItem(slot);
        SetArrowsVisible(FALSE);
        BlinkItem(slot, 30);
        ClearOtherRows(slot);
        unk_350[unk_364] = id;
        unk_530 = 4;
        break;
    }
    case 4:
        if (IsItemMoving(-1)) {
            break;
        }
        unk_108[GetRowItem(GetSelectedRow())].SlideOutTop();
        unk_530 = 5;
        break;
    case 5:
        if (IsItemMoving(-1)) {
            break;
        }
        return unk_350[unk_364];
    }
    return -1;
}

int RangerNetMenu::UpdateItemSelect()
{
    if (unk_4B4 != 0) {
        BOOL changed = FALSE;
        switch (UpdateButtonSelect()) {
        case 0x17:
            if (unk_4B0 < 1) {
                unk_4B0++;
                changed = TRUE;
            }
            break;
        case 0x18:
            if (unk_4B0 > 0) {
                unk_4B0--;
                changed = TRUE;
            }
            break;
        default:
            if (unk_52C == 2) {
                SetArrowsVisible(changed);
                return -1;
            }
            break;
        }
        if (changed) {
            unk_524 = 0;
            SetArrowsVisible(FALSE);
            ShowPage(unk_4B0, 0);
            SelectItem(GetRowItem(1));
            return -1;
        }
    }
    int r = HandleItemInput(1);
    if (r != 4) {
        if (r >= 0) {
            HideButtons();
            return unk_108[GetRowItem(r)].unk_54;
        }
        GoBack();
        return -2;
    }
    return -1;
}

void RangerNetMenu::GoBack()
{
    int slot = GetRowItem(GetSelectedRow());
    unk_108[slot].SetState(0, unk_108[slot].unk_48);
    SetArrowsVisible(FALSE);
    slot = GetRowItem(0);
    ClearOtherRows(slot);
    unk_51C = 0;
    int r;
    switch (unk_108[slot].unk_54) {
    case 0:
        r = ov11_02120150();
        if (r >= 0) {
            unk_51C = r;
        }
        break;
    case 1:
        r = GetMissionsIcon();
        if (r >= 0) {
            unk_51C = r;
        }
        break;
    case 2:
        r = GetSpecialMissionsIcon();
        if (r >= 0) {
            unk_51C = r;
        }
        break;
    case 3:
        r = GetExtraMissionsIcon();
        if (r >= 0) {
            unk_51C = r;
        }
        break;
    case 4:
        r = GetTransferIcon();
        if (r >= 0) {
            unk_51C = r;
        }
        break;
    }
    unk_002 = 9;
    HideButtons();
}

void RangerNetMenu::SaveItems(int idx)
{
    for (int i = 0; i < 4; i++) {
        int slot = GetRowItem(i);
        if (slot < 0) {
            unk_3B8[idx][i] = -1;
        } else {
            unk_368[idx][i] = unk_108[slot].unk_50;
            unk_3B8[idx][i] = unk_108[slot].unk_54;
            unk_408[idx][i] = unk_108[slot].unk_4C;
            unk_458[idx][i] = unk_108[slot].unk_48;
        }
    }
}

void RangerNetMenu::RestoreItems(int idx)
{
    int n = 0;
    for (int i = 0; i < 4; i++) {
        if (GetRowItem(i) >= 0) {
            continue;
        }
        int slot = FindFreeItem();
        if (unk_108[slot].unk_38 != 0) {
            continue;
        }
        if (unk_3B8[idx][i] < 0) {
            continue;
        }
        if (unk_368[idx][i] != 2) {
            unk_108[slot].SetState(0, 1);
        } else {
            unk_108[slot].SetState(2, 1);
        }
        unk_108[slot].SetId(unk_3B8[idx][i]);
        unk_108[slot].SetIcon(unk_408[idx][i]);
        unk_108[slot].SetEnabled(unk_458[idx][i]);
        unk_328[i] = slot;
        if (n % 2 != 0) {
            unk_108[slot].SlideInLeft(i);
        } else {
            unk_108[slot].SlideInRight(i);
        }
        n++;
    }
}

void RangerNetMenu::ShowButtons(int state)
{
    unk_52C = 0;
    SetButtonMode(state);
}

void RangerNetMenu::SetupMissionList(const int *ids, BOOL show, int arg)
{
    int n = 0;
    int i;
    unk_530 = 0;
    for (i = 0; i < 4; i++) {
        HideRow(i);
    }
    unk_4B4 = 0;
    for (i = 0; i < 6; i++) {
        unk_4B8[i / 3][i % 3].id = -1;
        unk_4B8[i / 3][i % 3].kind = 0;
        unk_4B8[i / 3][i % 3].flag = 0;
    }
    for (i = 0; i < 11; i++) {
        BOOL valid = FALSE;
        if (ids[i] != -1) {
            valid = TRUE;
        }
        if (valid) {
            unk_4B8[n / 3][n % 3].id = i + 11;
            unk_4B8[n / 3][n % 3].kind = 0;
            unk_4B8[n / 3][n % 3].flag = 1;
            if (n >= 3) {
                unk_4B4 = 1;
            }
            if (++n >= 6) {
                break;
            }
        }
    }
    if (show) {
        int slot = AddItem(arg, 0, 2);
        unk_108[slot].SetPos(0x80, GetItemY(0));
        unk_108[slot].SetVisible(TRUE);
        unk_108[slot].SetActive(TRUE);
    }
    ShowPage(0, 1);
}

void RangerNetMenu::ReturnToMenu(int a)
{
    HideAllRows();
    HideAllButtons();
    unk_108[AddItem(a, 0, 2)].SlideInLeft(0);
    unk_364--;
    SetupSubMenu();
    SetState(3, 0xFFFF);
    unk_002 = 10;
    ShowMessage(0, 5, 3, 1);
    ShowTopMessage(0, 5, 0);
}

void RangerNetMenu::UpdateWfcSettings()
{
    if (unk_002 != 0) {
        return;
    }
    if (IsFading()) {
        return;
    }
    Release();
    WirelessDriver_Init();
    OS_InitAlarm();
    OSIrqMask mask = OS_GetIrqMask();
    OS_SetIrqMask(0);
    unk_718->StartUtility();
    OS_SetIrqMask(mask);
    OS_EnableIrq();
    ResetSystem();
}

void RangerNetMenu::UpdateSprites()
{
    if (unk_00C != NULL) {
        unk_00C->Update();
    }
    if (unk_010 != NULL) {
        unk_010->Update();
    }
    if (unk_0A8 != NULL) {
        unk_0A8->Update();
    }
    if (unk_0AC != NULL) {
        unk_0AC->Update();
    }
    if (unk_0B0 != NULL) {
        unk_0B0->Update();
    }
    if (unk_0B4 != NULL) {
        unk_0B4->Update();
    }
    for (int i = 0; i < 4; i++) {
        unk_108[i].Update();
    }
    if (unk_0EC != 0) {
        for (int i = 0; i < 3; i++) {
            if (unk_0C4[i] != NULL) {
                unk_0C4[i]->Update();
            }
        }
    }
}

void RangerNetMenu::DrawSprites()
{
    if (unk_00C != NULL) {
        unk_00C->WriteOam();
    }
    if (unk_010 != NULL) {
        unk_010->WriteOam();
    }
    if (unk_0A8 != NULL) {
        unk_0A8->WriteOam();
    }
    if (unk_0AC != NULL) {
        unk_0AC->WriteOam();
    }
    if (unk_0B0 != NULL) {
        unk_0B0->WriteOam();
    }
    if (unk_0B4 != NULL) {
        unk_0B4->WriteOam();
    }
    for (int i = 0; i < 4; i++) {
        unk_108[i].Draw();
    }
    if (unk_0EC == 0) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (unk_0C4[i] != NULL) {
            unk_0C4[i]->WriteOam();
        }
    }
    for (int i = 0; i < 2; i++) {
        SetOamAffineScale(i, unk_0F8[i], unk_100[i], FALSE);
    }
}

void RangerNetMenu::LoadBackground()
{
    static int sScreens[] = { 0, 4, 3 };
    char path[0x40];

    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x08000, GX_BG_EXTPLTT_01);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x08000);
    G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x08000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(3);
    G2S_SetBG3Priority(1);
    BGS_LoadCharAndPltt("menu/", "rn001_bg_", 5, "rn001", 0x100, "rn001", 0);
    BGS_LoadScr("menu/", "rn001_bg_", 6, "rn001_02", 0, 0x100, 0, 0);
    BGS_LoadScr("menu/", "rn001_bg_", 5, "rn001_01", 0, 0x100, 0, 0);

    for (int i = 0; i <= 2; i++) {
        unk_584[i] = new BGLayer((int)unk_72C);
        unk_584[i]->SetBG(7);
        unk_584[i]->LoadArchive("menu/", "rn001_bg_");
        OS_SPrintf(path, "rn001_%02d", sScreens[i]);
        unk_584[i]->LoadScr(path, 0, 0, 0x100, 0, 0);
        unk_584[i]->ReleaseArchive();
        unk_584[i]->Setup(0x100, 0x100);
    }

    unk_72C->m_audioEngine->LoadSystemSe();
    unk_72C->unk_1498->FreeWindows();
    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x8000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_23);
    unk_72C->unk_1498->LoadPalette();

    unk_534[0] = new MessageTable("data/message/etc/network_mes");
    for (int i = 1; i < 8; i++) {
        OS_SPrintf(path, "data/message/etc/network%02d_mes", i);
        unk_534[i] = new MessageTable(path);
    }
}

BOOL RangerNetMenu::Setup()
{
    SetState(1, 0xFFFF);
    unk_002 = 0;
    LoadGraphics();
    return TRUE;
}

BOOL RangerNetMenu::LoadGraphics()
{
    LoadBackground();
    LoadSprites();
    unk_72C->unk_146C.SetFps(60);
    return TRUE;
}

int RangerNetMenu::HandleItemInput(BOOL sound)
{
    int dir = 0;
    PadInput *pad = unk_72C->unk_0014;
    unk_70C = 0;
    if ((u16)(pad->unk_0006 & PAD_KEY_DOWN)) {
        dir = PAD_KEY_DOWN;
    } else if ((u16)(pad->unk_0006 & PAD_KEY_UP)) {
        dir = PAD_KEY_UP;
    }
    if (dir != 0) {
        int cur = GetSelectedRow();
        for (int i = 1; i < 4; i++) {
            int slot;
            switch (dir) {
            case PAD_KEY_DOWN:
                slot = unk_328[(i + cur) % 4];
                break;
            case PAD_KEY_UP:
            default:
                slot = unk_328[(4 - i + cur) % 4];
                break;
            }
            if (slot >= 0 && unk_108[slot].unk_50 == 0) {
                SelectItem(slot);
                break;
            }
        }
        if (sound) {
            unk_72C->m_audioEngine->PlaySe(0x108);
        }
        unk_70C = 1;
        return 4;
    }
    if (unk_014[0]->unk_14 != 0) {
        if (unk_014[0]->GetTouchTrigger() || (u16)(pad->unk_0002 & PAD_BUTTON_B)) {
            if (sound) {
                unk_72C->m_audioEngine->PlaySe(0x100);
            }
            unk_70C = 1;
            return -1;
        }
    }
    if ((u16)(pad->unk_0002 & PAD_BUTTON_A)) {
        if (sound) {
            unk_72C->m_audioEngine->PlaySe(0xFF);
        }
        unk_70C = 1;
        return GetSelectedRow();
    }
    for (int i = 0; i < 4; i++) {
        if (unk_108[i].IsTouched()) {
            if (sound) {
                unk_72C->m_audioEngine->PlaySe(0xFF);
            }
            unk_70C = 1;
            return unk_108[i].unk_58;
        }
    }
    return 4;
}

int RangerNetMenu::HandleButtonInput()
{
    PadInput *pad = unk_72C->unk_0014;
    if ((u16)(pad->unk_0006 & PAD_KEY_LEFT) || (u16)(pad->unk_0006 & PAD_KEY_RIGHT)) {
        switch (unk_520) {
        case 10:
            SetButtonMode(11);
            unk_72C->m_audioEngine->PlaySe(0x108);
            unk_70C = 1;
            return -2;
        case 11:
            SetButtonMode(10);
            unk_72C->m_audioEngine->PlaySe(0x108);
            unk_70C = 1;
            return -2;
        }
    }
    if (unk_520 == 20 || unk_520 == 21) {
        if ((u16)(pad->unk_0006 & PAD_KEY_RIGHT)) {
            if (unk_4B0 < 1) {
                SetButtonMode(0x17);
                unk_72C->m_audioEngine->PlaySe(0x108);
                unk_70C = 1;
                return 0x17;
            }
        } else if ((u16)(pad->unk_0006 & PAD_KEY_LEFT)) {
            if (unk_4B0 > 0) {
                SetButtonMode(0x18);
                unk_72C->m_audioEngine->PlaySe(0x108);
                unk_70C = 1;
                return 0x18;
            }
        }
    }
    if (unk_014[0]->unk_14 != 0) {
        if (unk_014[0]->GetTouchTrigger() || (u16)(pad->unk_0002 & PAD_BUTTON_B)) {
            unk_72C->m_audioEngine->PlaySe(0x100);
            unk_70C = 1;
            return -1;
        }
    }
    int sel = -1;
    if ((u16)(pad->unk_0002 & PAD_BUTTON_A)) {
        if (unk_520 != 20 && unk_520 != 21) {
            sel = unk_520;
        }
    } else {
        for (int i = 10; i <= 24; i++) {
            if (unk_014[i]->unk_14 != 0 && unk_014[i]->GetTouchTrigger()) {
                sel = i;
                break;
            }
        }
    }
    if (sel != -1) {
        int next = -1;
        int se = 0xFF;
        switch (sel) {
        case 10:
        case 12:
            next = 0xE;
            break;
        case 11:
        case 13:
            next = 0xF;
            se = 0x100;
            break;
        case 16:
            next = 0x12;
            break;
        case 17:
            next = 0x13;
            break;
        case 20:
            next = 0x17;
            break;
        case 21:
            next = 0x18;
            break;
        case 9:
            next = 9;
            break;
        }
        if (next != -1) {
            SetButtonMode(next);
            unk_72C->m_audioEngine->PlaySe(se);
            unk_70C = 1;
            return next;
        }
    }
    return -2;
}

BOOL RangerNetMenu::CheckContinue()
{
    PadInput *pad = unk_72C->unk_0014;
    CTouchPanel *tp = CGame::GetInstance()->touchPanel;
    if (!(u16)(pad->unk_0002 & PAD_BUTTON_A) && tp->unk_04 == 0) {
        return FALSE;
    }
    unk_72C->m_audioEngine->PlaySe(0xFA);
    return TRUE;
}

int RangerNetMenu::CheckCancel()
{
    OamSprite *sprite = unk_014[0];
    PadInput *pad = unk_72C->unk_0014;
    if (sprite->unk_14 != 0) {
        if ((u16)(pad->unk_0002 & PAD_BUTTON_B) || sprite->GetTouchTrigger()) {
            unk_72C->m_audioEngine->PlaySe(0x100);
            return -1;
        }
    }
    return 0;
}

void RangerNetMenu::ExitToTitle()
{
    SetState(0xE, 0xFFFF);
    unk_002 = 15;
    FadeOutToWhite();
}

void RangerNetMenu::StartMission()
{
    SetState(0xC, 0xFFFF);
    unk_002 = 15;
    FadeOutToBlack();
}

void RangerNetMenu::ChooseItem(int sel)
{
    unk_33C[unk_364] = sel;
    int slot = GetRowItem(sel);
    unk_350[unk_364] = unk_108[slot].unk_54;
    switch (unk_350[unk_364]) {
    case 0:
        HideButtons();
        unk_002 = 4;
        SelectItem(slot);
        SetArrowsVisible(FALSE);
        BlinkItem(slot, 30);
        ClearOtherRows(slot);
        unk_364++;
        SAFE_DELETE(unk_708);
        unk_708 = new DownloadStationScan();
        return;
    case 1:
    case 4:
        HideButtons();
        unk_002 = 5;
        break;
    case 2:
    case 3:
        HideButtons();
        unk_002 = 5;
        break;
    case 5:
    case 6:
    case 7:
        HideButtons();
        unk_002 = 3;
        break;
    case 11:
        if (((MAIN_BSS_020B26A0.m_rangerClassGrade >> 4) & 0xF) < 1u) {
            ShowMessage(1, 2, 1, 1);
            unk_002 = 14;
            SelectItem(slot);
            SetArrowsVisible(FALSE);
            return;
        }
        HideButtons();
        unk_002 = 3;
        break;
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        if (unk_72C->m_missionQuestData->m_chapter < 0x45) {
            ShowMessage(2, 2, 1, 1);
            unk_002 = 14;
            SelectItem(slot);
            SetArrowsVisible(FALSE);
            return;
        }
        HideButtons();
        unk_002 = 3;
        break;
    case 8:
    case 9:
    case 10:
        if (unk_108[slot].unk_48 == 0) {
            ShowMessage(2, 5, 1, 1);
            unk_002 = 14;
            SelectItem(slot);
            SetArrowsVisible(FALSE);
            return;
        }
        HideButtons();
        unk_002 = 3;
        break;
    }
    SelectItem(slot);
    SetArrowsVisible(FALSE);
    BlinkItem(slot, 30);
    ClearOtherRows(slot);
    unk_364++;
}

void RangerNetMenu::OpenItem()
{
    int kind = unk_350[unk_364 - 1];
    switch (kind) {
    case 5:
        SetState(8, 0xFFFF);
        unk_002 = 0;
        FadeOutToWhite();
        break;
    case 6:
        SetState(4, 0xFFFF);
        unk_002 = 0;
        break;
    case 7:
        SetState(5, 0xFFFF);
        unk_002 = 0;
        break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        int idx = kind - 11;
        ShowTopMission(idx);
        int type = 3;
        if (unk_638[idx] == 2 && idx < 3) {
            type = 4;
        }
        ShowMessage(type, 2, 0, 1);
        unk_72C->unk_14A4->unk_81AC = idx + 1;
        SetState(3, 0xFFFF);
        unk_002 = 13;
        ShowButtons(11);
        break;
    }
    case 8:
        SetState(6, 0xFFFF);
        unk_002 = 0;
        break;
    case 9:
        unk_72C->unk_1498->unk_30[0] = 0x1EB;
        unk_72C->unk_1494->unk_34[0] = 0x1EB;
        unk_604 = 1;
        SetState(7, 0xFFFF);
        unk_002 = 0;
        break;
    case 10:
        unk_72C->unk_1498->unk_30[0] = 0x1BF;
        unk_72C->unk_1494->unk_34[0] = 0x1BF;
        unk_604 = 0;
        SetState(7, 0xFFFF);
        unk_002 = 0;
        break;
    }
}

void RangerNetMenu::ShowPage(int page, BOOL delayed)
{
    int i;
    for (i = 1; i < 4; i++) {
        HideRow(i);
    }
    unk_4B0 = page;
    for (i = 0; i < 3; i++) {
        if (unk_4B8[page][i].id < 0) {
            continue;
        }
        int slot = AddItem(unk_4B8[page][i].id, unk_4B8[page][i].kind, 0);
        unk_108[slot].SetEnabled(unk_4B8[page][i].flag);
        if (delayed) {
            unk_108[slot].SlideInBottom(unk_108[slot].unk_58, i * 0x5000);
        } else {
            unk_108[slot].SetPos(0x80, GetItemY(unk_108[slot].unk_58));
            unk_108[slot].SetVisible(TRUE);
            unk_108[slot].SetActive(TRUE);
        }
    }
    if (unk_4B4 == 0) {
        return;
    }
    if (page == 0) {
        ShowButtons(0x14);
    } else {
        ShowButtons(0x15);
    }
}

int RangerNetMenu::AddItem(int id, int type, int anim)
{
    int slot = FindFreeItem();
    if (slot < 0) {
        return -1;
    }
    SetRowItem(slot, FindFreeRow());
    unk_108[slot].SetId(id);
    unk_108[slot].SetIcon(type);
    unk_108[slot].SetState(anim, 1);
    return slot;
}

void RangerNetMenu::ShowMessage(int a, int b, int c, int d)
{
    unk_038 = 1;
    unk_5A0 = c;
    unk_554 = b;
    unk_580 = 0;
    unk_5A4 = d;
    AddMessage(a);
}

void RangerNetMenu::SetMessageString(const char *str, BOOL top)
{
    CGame *game = unk_72C;
    if (top) {
        game->unk_1494->SetString(str);
    } else {
        game->unk_1498->SetString(str);
    }
}

void RangerNetMenu::AddMessage(int a)
{
    if (unk_580 < 10) {
        unk_558[unk_580] = a;
        unk_580++;
    }
}

void RangerNetMenu::SetNameArg(int i, int v)
{
    if (i < 10) {
        unk_5D0[i] = v;
    }
}

void RangerNetMenu::SetNumberArg(int i, int v)
{
    if (i < 10) {
        unk_5A8[i] = v;
    }
}

void RangerNetMenu::ShowTopMessage(int a, int b, int c)
{
    if (unk_724 != NULL) {
        unk_724->ShowMessage(c, a, unk_534[b]);
    }
}

void RangerNetMenu::ShowTopMission(int mode)
{
    if (unk_724 != NULL) {
        unk_724->ShowMission(mode);
    }
}

static inline void PrintText(RangerNetMenu *menu, MessageTable *msgs, int idx, int x, int y, int color, u32 msg, BOOL center)
{
    SubTextPrinter *box = menu->unk_72C->unk_1498;
    box->Print(idx, x, y, color, (u8 *)msgs->GetString(msg), center, 0);
}

void RangerNetMenu::PrintMessage()
{
    if (unk_038 == 0) {
        return;
    }
    unk_038 = 0;
    SetMessageLayout(unk_5A0);
    unk_72C->unk_1498->ClearWindow(0);
    if (unk_5A4 != 0) {
        PrintText(this, unk_534[5], 0, 0, 3, 3, 1, TRUE);
    }
    switch (unk_59C) {
    case 0:
        unk_72C->unk_1498->ClearWindow(1);
        PrintText(this, unk_534[unk_554], 1, 0, 3, 1, unk_558[0], FALSE);
        break;
    case 1:
        unk_72C->unk_1498->ClearWindow(1);
        PrintText(this, unk_534[unk_554], 1, 0, 3, 1, unk_558[0], FALSE);
        break;
    case 2:
        unk_72C->unk_1498->ClearWindow(0);
        unk_72C->unk_1498->ClearWindow(1);
        unk_72C->unk_1498->ClearWindow(2);
        PrintText(this, unk_534[unk_554], 1, 0x17, 3, 3, unk_558[0], FALSE);
        PrintText(this, unk_534[unk_554], 2, 0, 3, 3, unk_558[1], TRUE);
        break;
    case 3:
        break;
    case 4:
        unk_72C->unk_1498->ClearWindow(1);
        PrintText(this, unk_534[unk_554], 1, 0, 3, 1, 9, FALSE);
        PrintText(this, unk_534[unk_554], 1, 0, 0xE, 1, 10, FALSE);
        PrintNumber(1, 0x46, 0xE, unk_5A8[0], 1, 0, 5);
        PrintText(this, unk_534[unk_554], 1, 0, 0x1A, 1, 11, FALSE);
        PrintApplicationNo(1, 0, 0x26, 1, 0);
        PrintText(this, unk_534[unk_554], 1, 0x64, 0x26, 1, 12, FALSE);
        PrintText(this, unk_534[unk_554], 1, 0, 0x3E, 1, unk_558[0], FALSE);
        break;
    case 5:
        unk_72C->unk_1498->ClearWindow(1);
        PrintText(this, unk_534[unk_554], 1, 0, 3, 1, 9, FALSE);
        PrintText(this, unk_534[unk_554], 1, 0, 0xE, 1, 10, FALSE);
        PrintNumber(1, 0x50, 0xE, unk_5A8[0], 1, 0, 5);
        PrintText(this, unk_534[unk_554], 1, 0, 0x1A, 1, 11, FALSE);
        PrintTrainerName(1, 0x50, 0x1A, unk_5D0[0], 1, 0);
        PrintText(this, unk_534[unk_554], 1, 0x64, 0x26, 1, 12, FALSE);
        PrintText(this, unk_534[unk_554], 1, 0, 0x3E, 1, unk_558[0], FALSE);
        break;
    }
}

static inline void PrintTextTop(RangerNetMenu *menu, MessageTable *msgs, int idx, int x, int y, int color, u32 msg, BOOL center)
{
    TextPrinter *box = menu->unk_72C->unk_1494;
    box->Print(idx, x, y, color, (u8 *)msgs->GetString(msg), center, 0);
}

void RangerNetMenu::PrintApplicationNo(int idx, int x, int y, int color, BOOL top)
{
    PrintNumber(idx, x, y, unk_5A8[1], color, top, 4);
    if (top) {
        PrintTextTop(this, unk_534[6], idx, x + 0x1C, y, color, 10, FALSE);
    } else {
        PrintText(this, unk_534[6], idx, x + 0x1C, y, color, 10, FALSE);
    }
    PrintNumber(idx, x + 0x23, y, unk_5A8[2], color, top, 4);
}

void RangerNetMenu::PrintNumber(int idx, int x, int y, int value, int color, BOOL top, int digits)
{
    TextPrinter *topBox;
    SubTextPrinter *subBox;
    int count = 1;
    int div = 10;
    value = value < 0 ? unk_5A8[0] : value;
    if (digits >= 0) {
        for (int i = 1; i < digits; i++) {
            div *= 10;
            count++;
        }
    } else {
        while (value >= div) {
            div *= 10;
            count++;
        }
    }
    for (int i = 0; i < count; i++) {
        int digit = (value % div) / (div / 10);
        if (top) {
            topBox = unk_72C->unk_1494;
            topBox->Print(idx, x, y, color, (u8 *)unk_534[6]->GetString(digit), FALSE, 0);
        } else {
            subBox = unk_72C->unk_1498;
            subBox->Print(idx, x, y, color, (u8 *)unk_534[6]->GetString(digit), FALSE, 0);
        }
        div /= 10;
        x += 7;
    }
}

void RangerNetMenu::FormatNumber(char *buf, int value, int digits)
{
    int count = 1;
    int div = 10;
    if (value < 0) {
        value = unk_5A8[0];
    }
    int i;
    if (digits >= 0) {
        for (i = 1; i < digits; i++) {
            div *= 10;
            count++;
        }
    } else {
        while (value >= div) {
            div *= 10;
            count++;
        }
    }
    buf[0] = '\0';
    for (i = 0; i < count; i++) {
        int digit = (value % div) / (div / 10);
        STD_ConcatenateString(buf, unk_534[6]->GetString(digit));
        buf[(i + 1) * 3] = '\0';
        div /= 10;
    }
}

void RangerNetMenu::PrintTrainerName(int idx, int x, int y, int name, int color, BOOL top)
{
    static u16 sRanges[] = { 1, 0x51, 0x52, 0xA1, 0xA2, 0xDF, 0xE1, 0x111, 0x121, 0x15E, 0x15F, 0x19E, 0x1A9, 0x1DD };
    char buf[0x34];
    const u16 *src = (const u16 *)name;
    if (src == NULL) {
        src = (const u16 *)unk_5D0[0];
    }
    char *dst = buf;
    for (;;) {
        u16 c = *src++;
        if (c == 0 || c == 0xFFFF) {
            break;
        }
        int j;
        for (j = 0; j < 7; j++) {
            if (c >= sRanges[j * 2] && c <= sRanges[j * 2 + 1]) {
                break;
            }
        }
        if (j >= 7) {
            *dst++ = ' ';
            continue;
        }
        c -= sRanges[j * 2];
        const char *str = unk_534[7]->GetString(j);
        for (j = 0; j < c; j++) {
            if ((*str & 0x80) != 0x80) {
                str++;
            } else {
                str++;
                while ((*str & 0xC0) == 0x80) {
                    str++;
                }
            }
        }
        if ((*str & 0x80) != 0x80) {
            *dst++ = *str;
            continue;
        }
        do {
            *dst++ = *str++;
        } while ((*str & 0xC0) == 0x80);
    }
    dst[0] = '\0';
    dst[1] = '\0';
    dst[2] = '\0';
    if (top) {
        unk_72C->unk_1494->Print(idx, x, y, color, (u8 *)buf, FALSE, 0);
    } else {
        unk_72C->unk_1498->Print(idx, x, y, color, (u8 *)buf, FALSE, 0);
    }
}

void RangerNetMenu::ShowDownloadedMessage(int a, BOOL b)
{
    BOOL flag = FALSE;
    if (b) {
        flag = TRUE;
    }
    if (a < 6) {
        a += 7;
    } else {
        int base = 0x28;
        if (b) {
            base = 0x13;
        }
        a = a - 6 + base;
    }
    ShowMessage(a, flag, 0, 1);
}

void RangerNetMenu::SetMessageLayout(int mode)
{
    if (unk_59C == mode) {
        return;
    }
    unk_59C = mode;
    unk_72C->unk_1498->FreeWindows();
    MI_CpuClearFast(G2S_GetBG0CharPtr(), 0x20);
    MI_CpuClearFast(G2S_GetBG0ScrPtr(), 0x800);
    unk_014[9]->SetVisible(FALSE);
    int bg = 2;
    switch (unk_59C) {
    case 2:
        bg++;
    case 0:
    case 1:
    case 4:
    case 5: {
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG3);
        unk_72C->unk_1498->AllocWindows(bg);
        unk_72C->unk_1498->InitWindow(0, 0x14, 2, 6, 1, 8, 0, 2);
        int idx = unk_59C;
        switch (idx) {
        case 4:
        case 5:
            idx = 0;
        case 0:
            unk_72C->unk_1498->InitWindow(1, 0x16, 0x10, 6, 4, 0x30, 0, 2);
            break;
        case 1:
            unk_72C->unk_1498->InitWindow(1, 0x16, 6, 6, 0xE, 0x30, 0, 2);
            break;
        case 2:
            unk_72C->unk_1498->InitWindow(1, 0x16, 6, 5, 8, 0x30, 0, 2);
            unk_72C->unk_1498->InitWindow(2, 0x16, 2, 5, 0x16, 0xB4, 0, 2);
            unk_014[9]->SetVisible(TRUE);
            break;
        }
        unk_584[idx]->LoadScrToVram();
        return;
    }
    default:
        unk_72C->unk_1498->AllocWindows(1);
        unk_72C->unk_1498->InitWindow(0, 0x14, 2, 6, 1, 8, 0, 2);
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() & ~GX_PLANEMASK_BG3);
        break;
    }
}

void RangerNetMenu::SetButtonMode(int sel)
{
    BOOL alt;
    unk_520 = sel;
    HideButtons();
    switch (unk_520) {
    case 10:
        unk_014[13]->SetVisible(TRUE);
        alt = TRUE;
        break;
    case 11:
        unk_014[12]->SetVisible(TRUE);
        alt = TRUE;
        break;
    case 14:
        unk_014[13]->SetVisible(TRUE);
        alt = FALSE;
        break;
    case 15:
        unk_014[12]->SetVisible(TRUE);
        alt = FALSE;
        break;
    case 17:
        unk_014[6]->SetVisible(TRUE);
    case 16:
    case 20:
    case 21:
        alt = TRUE;
        break;
    case 19:
        unk_014[6]->SetVisible(TRUE);
    case 18:
    case 23:
    case 24:
        alt = FALSE;
        break;
    case 9:
    default:
        return;
    }
    if (unk_520 == 25) {
        return;
    }
    unk_014[unk_520]->SetVisible(TRUE);
    if (unk_4AC != alt) {
        unk_4AC = alt;
        unk_4A8 = 1;
    }
}

void RangerNetMenu::LoadButtonGraphics()
{
    if (unk_4A8 == 0) {
        return;
    }
    unk_4A8 = 0;
    if (unk_4AC != 0) {
        unk_0A8->CopyToVram();
    } else {
        unk_0AC->CopyToVram();
    }
}

void RangerNetMenu::HideButtons()
{
    for (int i = 10; i <= 24; i++) {
        unk_014[i]->SetVisible(FALSE);
    }
    unk_014[6]->SetVisible(FALSE);
}

void RangerNetMenu::SelectItem(int sel)
{
    for (int i = 0; i < 4; i++) {
        if (unk_108[i].unk_38 == 0) {
            continue;
        }
        if (sel == i) {
            if (unk_108[i].unk_50 == 0) {
                unk_108[i].SetState(1, unk_108[i].unk_48);
                unk_108[i].StartArrowAnim();
            }
        } else if (unk_108[i].unk_50 == 1) {
            unk_108[i].SetState(0, unk_108[i].unk_48);
        }
    }
}

int RangerNetMenu::FindMissionFile(const char *name)
{
    char buf[0x30];
    for (int i = 0; i < 11; i++) {
        OS_SPrintf(buf, "PRS_MISSION_%02d.prs", i + 1);
        if (strcmp(buf, name) == 0) {
            return i;
        }
    }
    return -1;
}

BOOL RangerNetMenu::MountArchive(void *mem)
{
    return NNS_FndMountArchive(&unk_658, "RNS", mem);
}

BOOL RangerNetMenu::UnmountArchive()
{
    return NNS_FndUnmountArchive(&unk_658);
}

BOOL RangerNetMenu::ReadMissionFile(int i, void *mem, u8 *dst)
{
    char name[0x30];
    char path[0x30];
    FSFile file;
    if (!MountArchive(mem)) {
        return FALSE;
    }
    OS_SPrintf(name, "PRS_MISSION_%0d.dat", i + 1);
    OS_SPrintf(path, "RNS:%s", name);
    FS_InitFile(&file);
    if (!FS_OpenFile(&file, path)) {
        UnmountArchive();
        return FALSE;
    }
    s32 read = FS_ReadFile(&file, dst, FS_GetLength(&file));
    UnmountArchive();
    return read >= 0 ? TRUE : FALSE;
}

void RangerNetMenu::SetupAgbMissionList()
{
    unk_6EC = AgbCheck_GetMissionNo();
    for (int i = 0; i < 11; i++) {
        unk_6C0[i] = -1;
    }
    if (unk_6EC < 0) {
        unk_6EC = 10;
    }
    unk_6C0[unk_6EC] = 1;
    SetupMissionList(unk_6C0, FALSE, 6);
}

BOOL StopWm()
{
    OVERLAY11_BSS_02169B40 = FALSE;
    if (WM_Reset(WmResetCallback) != WM_ERRCODE_OPERATING) {
        if (WM_End(WmEndCallback) != WM_ERRCODE_OPERATING) {
            OVERLAY11_BSS_02169B40 = TRUE;
        }
        return FALSE;
    }
    return TRUE;
}

// WM_Reset callback (StopWm)
static void WmResetCallback(void *arg)
{
    OVERLAY11_BSS_02169B40 = TRUE;
}

// WM_End callback (StopWm, UpdateSendPokemon)
static void WmEndCallback(void *arg)
{
    OVERLAY11_BSS_02169B40 = TRUE;
}

void RangerNetMenu::FadeIn()
{
    if (unk_72C != NULL) {
        unk_72C->m_subFade->Start(3, 15);
        unk_72C->m_mainFade->Start(3, 15);
    }
}

void RangerNetMenu::FadeOutToBlack()
{
    if (unk_72C != NULL) {
        unk_72C->m_audioEngine->StopBgm(10);
        unk_72C->m_subFade->Start(4, 15);
        unk_72C->m_mainFade->Start(4, 15);
    }
}

void RangerNetMenu::FadeOutToWhite()
{
    unk_72C->m_audioEngine->StopBgm(10);
    if (unk_72C != NULL) {
        unk_72C->m_subFade->Start(2, 15);
        unk_72C->m_mainFade->Start(2, 15);
    }
}

BOOL RangerNetMenu::IsFading()
{
    if (unk_72C->m_subFade->IsActive() || unk_72C->m_mainFade->IsActive()) {
        return TRUE;
    }
    return FALSE;
}

int RangerNetMenu::GetNextScene()
{
    switch (unk_000) {
    case 0xD:
        return 0;
    case 0xB:
        return 1;
    case 0x11:
        return 2;
    }
    return -1;
}

void RangerNetMenu::SetState(int state, int arg)
{
    if (arg == 0xFFFF) {
        arg = unk_000;
    }
    unk_034 = arg;
    unk_000 = state;
}

int RangerNetMenu::FindFreeItem()
{
    for (int i = 0; i < 4; i++) {
        if (unk_108[i].IsEmpty()) {
            return i;
        }
    }
    return -1;
}

int RangerNetMenu::FindFreeRow()
{
    for (int i = 0; i < 4; i++) {
        if (unk_328[i] < 0) {
            return i;
        }
    }
    return -1;
}

int RangerNetMenu::GetRowItem(int i)
{
    if (i < 0) {
        return 0;
    }
    return unk_328[i];
}

void RangerNetMenu::ClearOtherRows(int keep)
{
    int n = 0;
    for (int i = 0; i < 4; i++) {
        int slot = unk_328[i];
        if (slot < 0 || slot == keep) {
            continue;
        }
        if (n % 2 == 0) {
            unk_108[slot].SlideOutLeft();
        } else {
            unk_108[slot].SlideOutRight();
        }
        unk_328[i] = -1;
        n++;
    }
}

void RangerNetMenu::HideRow(int i)
{
    int slot = unk_328[i];
    if (slot < 0) {
        return;
    }
    unk_108[slot].SetVisible(FALSE);
    unk_108[slot].SetActive(FALSE);
    unk_328[i] = -1;
}

void RangerNetMenu::HideAllRows()
{
    for (int i = 0; i < 4; i++) {
        HideRow(i);
    }
}

void RangerNetMenu::BlinkItem(int slot, int t)
{
    if (slot < 0) {
        return;
    }
    unk_108[slot].StartBlink(t << 12);
}

void RangerNetMenu::MoveRow(int a, int b)
{
    int slot = GetRowItem(a);
    if (slot == unk_328[b]) {
        return;
    }
    unk_108[slot].MoveToRow(slot, b);
    unk_108[slot].SetEnabled(1);
    unk_328[a] = -1;
    unk_328[b] = slot;
    SetArrowsVisible(FALSE);
}

void RangerNetMenu::SetRowItem(int slot, int idx)
{
    unk_108[slot].unk_58 = idx;
    unk_328[idx] = slot;
}

int RangerNetMenu::GetSelectedRow()
{
    for (int i = 0; i < 4; i++) {
        int slot = unk_328[i];
        if (slot >= 0 && unk_108[slot].unk_50 == 1) {
            return i;
        }
    }
    return -1;
}

BOOL RangerNetMenu::IsItemMoving(int slot)
{
    RemoveInactiveRows();
    if (slot < 0) {
        for (int i = 0; i < 4; i++) {
            if (unk_108[i].unk_34 != 0) {
                return TRUE;
            }
        }
    } else if (unk_108[slot].unk_34 != 0) {
        return TRUE;
    }
    return FALSE;
}

void RangerNetMenu::RemoveInactiveRows()
{
    for (int i = 0; i < 4; i++) {
        int idx = unk_328[i];
        if (idx > 0) {
            if (unk_108[idx].IsEmpty()) {
                unk_328[i] = -1;
            }
        }
    }
}

void RangerNetMenu::SetArrowsVisible(BOOL visible)
{
    unk_0A0[0]->SetVisible(visible);
    unk_0A0[1]->SetVisible(visible);
}

fx32 QuadraticVelocity(fx32 a, fx32 b)
{
    return FX32_MUL(FX32_MUL(b, a), 2 * FX32_ONE);
}

fx32 EvalQuadratic(fx32 start, fx32 b, fx32 t, fx32 a)
{
    return start + (FX32_MUL(b, t) + FX32_MUL(a, FX32_MUL(t, t)));
}

fx32 SolveQuadraticAccel(fx32 start, fx32 end, fx32 b, fx32 t)
{
    return FX32_DIV(end - FX32_MUL(b, t) - start, FX32_MUL(t, t));
}

void RangerNetMenu::UpdateWaitIcon(int mode)
{
    switch (mode) {
    case 0:
        for (int i = 1; i < 5; i++) {
            unk_014[i]->SetVisible(FALSE);
        }
        break;
    case 1: {
        int cur = (unk_608 / 20) % 4;
        for (int i = 1; i < 5; i++) {
            unk_014[i]->SetVisible(TRUE);
            if (i - 1 == cur) {
                unk_00C->SetAnim(unk_60C[i], 3);
            } else {
                unk_00C->SetAnim(unk_60C[i], 4);
            }
        }
        unk_608 = (unk_608 + 1) % 80;
        break;
    }
    }
}

void RangerNetMenu::StopConnecting()
{
    unk_72C->m_audioEngine->StopSe(0xD1);
    HideAllButtons();
    SetBackButton(3);
    UpdateWaitIcon(0);
    SetLinkIcon(0, -1);
    ClearItems();
}

RangerNetMenuItem::RangerNetMenuItem()
{
    unk_04 = 0;
    unk_4C = 0;
    unk_30 = 0;
    unk_34 = 0;
    unk_3C = 0;
    SetActive(FALSE);
}

RangerNetMenuItem::~RangerNetMenuItem()
{
}

void RangerNetMenuItem::InitLabel(OamSpriteSet **res, int idx, int v)
{
    unk_00 = res;
    unk_04 = unk_00[idx];
    unk_28 = v / 32;
    unk_0C = unk_04->AddSprite(0, 0, 0, 2);
    unk_24 = unk_04->unk_24;
}

void RangerNetMenuItem::InitFrame(OamSpriteSet *res)
{
    unk_08 = res;
    unk_10 = res->AddSprite(0x15, 0, 0, 3);
    unk_10->SetTouchRect(0xE0, 0x10, 0, 0);
    unk_1C = res->unk_24;
    unk_14 = res->AddSprite(0x10, 0, 0, 2);
    unk_20 = res->unk_24;
}

void RangerNetMenuItem::SetState(int state, int arg)
{
    unk_50 = state;
    switch (state) {
    case 1:
        unk_08->SetAnim(unk_1C, 0x15);
        unk_30 = 1;
        SetEnabled(arg);
        break;
    case 2:
        unk_08->SetAnim(unk_1C, 0x16);
        unk_30 = 0;
        SetEnabled(arg);
        SetIcon(0);
        break;
    case 0:
    default:
        unk_08->SetAnim(unk_1C, 0x14);
        unk_30 = 0;
        SetEnabled(arg);
        break;
    }
}

void RangerNetMenuItem::SetIcon(int type)
{
    int anim;
    unk_4C = type;
    switch (type) {
    case 1:
        anim = 15;
        break;
    case 2:
        anim = 16;
        break;
    case 3:
        anim = 5;
        break;
    case 4:
        anim = 10;
        break;
    default:
        unk_14->SetVisible(FALSE);
        return;
    }
    unk_14->SetVisible(TRUE);
    unk_08->SetAnim(unk_20, anim);
}

void RangerNetMenuItem::SetEnabled(int flag)
{
    unk_48 = flag;
    if (flag != 0) {
        unk_10->unk_28 = 0;
        switch (unk_50) {
        case 2:
            unk_04->SetAnim(unk_24, 0);
            break;
        case 0:
        case 1:
        default:
            unk_04->SetAnim(unk_24, 1);
            break;
        }
    } else {
        unk_10->unk_28 = 1;
        unk_04->SetAnim(unk_24, 2);
    }
}

void RangerNetMenuItem::SetId(int id)
{
    unk_54 = id;
    unk_00[id]->SetVramOffsets(unk_28, 1);
}

void RangerNetMenuItem::SetPos(int x, int y)
{
    unk_80 = x;
    unk_84 = y;
    unk_0C->SetPos(x, y);
    unk_10->SetPos(x, y);
    unk_14->SetPos(x + 0x58, y);
}

void RangerNetMenuItem::Update()
{
    if (unk_38 == 0) {
        return;
    }
    if (unk_04 != NULL) {
        unk_04->Update();
    }
    UpdateMove();
    if (unk_50 == 1) {
        UpdateArrows();
    }
}

void RangerNetMenuItem::Draw()
{
    if (unk_38 != 0 && unk_04 != NULL) {
        unk_04->WriteOam();
    }
}

void RangerNetMenuItem::SetVisible(BOOL visible)
{
    unk_2C = visible;
    unk_10->SetVisible(visible);
    unk_0C->SetVisible(visible);
    if (unk_4C == 0) {
        unk_14->SetVisible(FALSE);
    } else {
        unk_14->SetVisible(visible);
    }
}

void RangerNetMenuItem::StartBlink(fx32 v)
{
    unk_70 = 0;
    unk_74 = v;
    unk_44 = 1;
    unk_34 = 1;
}

void RangerNetMenuItem::StartMove(fx32 a, fx32 b, fx32 c, fx32 d, int e, int f, int g)
{
    unk_64 = SolveQuadraticAccel(a, b, c, d);
    unk_60 = c;
    unk_68 = a;
    unk_6C = b;
    unk_74 = d;
    unk_70 = 0;
    unk_34 = 1;
    unk_78 = e;
    unk_7C = g;
    unk_40 = f;
    unk_44 = 0;
    SetActive(TRUE);
}

void RangerNetMenuItem::StartArrowAnim()
{
    unk_64 = SolveQuadraticAccel(0, 0x4000, 0, 0x14000);
    unk_60 = QuadraticVelocity(0x14000, unk_64);
    unk_60 = FX32_MUL(unk_60, (fx64)-FX32_ONE);
    unk_68 = 0;
    unk_6C = 0x4000;
    unk_74 = 0x27000;
    unk_70 = 0;
    unk_18[0]->SetVisible(TRUE);
    unk_18[1]->SetVisible(TRUE);
}

void RangerNetMenuItem::SlideInLeft(int arg)
{
    unk_3C = 0;
    SetPos(-0x80, GetItemY(arg));
    StartMove(0x80000, -0x80000, 0, 0xF000, 1, 1, 0);
    unk_58 = arg;
}

void RangerNetMenuItem::SlideOutLeft()
{
    unk_3C = 1;
    StartMove(0x80000, -0x80000, 0, 0xA000, 1, 0, 0);
}

void RangerNetMenuItem::SlideInRight(int arg)
{
    unk_3C = 0;
    SetPos(0x180, GetItemY(arg));
    StartMove(0x80000, 0x180000, 0, 0xF000, 1, 1, 0);
    unk_58 = arg;
}

void RangerNetMenuItem::SlideOutRight()
{
    unk_3C = 1;
    StartMove(0x80000, 0x180000, 0, 0xA000, 1, 0, 0);
}

void RangerNetMenuItem::SlideInBottom(int arg, int g)
{
    unk_3C = 0;
    SetVisible(FALSE);
    SetPos(0x80, GetItemY(arg) + 0xC0);
    StartMove(GetItemY(arg) << 12, 0xF0000, 0, 0xF000, 0, 1, g);
    unk_58 = arg;
}

void RangerNetMenuItem::SlideOutTop()
{
    unk_3C = 1;
    StartMove(unk_84 << 12, -0x30000, 0, 0xA000, 0, 0, 0);
}

void RangerNetMenuItem::MoveToRow(int slot, int pos)
{
    int y = GetItemY(pos);
    StartMove(y << 12, unk_84 << 12, 0, 0x14000, 0, 1, 0);
    unk_58 = pos;
}

void RangerNetMenuItem::UpdateMove()
{
    if (unk_34 == 0) {
        return;
    }
    if (unk_7C > 0) {
        unk_7C -= 0x1000;
        return;
    }
    if (unk_44 != 0) {
        if (unk_70 < unk_74) {
            if ((unk_70 >> 12) % 8 < 4) {
                SetState(1, 1);
            } else {
                SetState(0, 1);
            }
            unk_70 += 0x1000;
        } else {
            SetState(1, 1);
            SetVisible(TRUE);
            unk_34 = 0;
        }
        return;
    }
    SetVisible(TRUE);
    fx32 pos;
    if (unk_70 < unk_74) {
        fx32 t = unk_70;
        if (unk_40 != 0) {
            t = unk_74 - unk_70;
        }
        pos = EvalQuadratic(unk_68, unk_60, t, unk_64);
        unk_70 += 0x1000;
    } else {
        pos = unk_6C;
        if (unk_40 != 0) {
            pos = unk_68;
        }
        unk_34 = 0;
        unk_70 = 0;
        if (unk_3C != 0) {
            SetActive(FALSE);
        }
    }
    if (unk_78 != 0) {
        SetPos(pos >> 12, unk_84);
        return;
    }
    if (pos < -0x20000 || pos > 0xA1000) {
        SetVisible(FALSE);
        return;
    }
    SetPos(unk_80, pos >> 12);
}

void RangerNetMenuItem::UpdateArrows()
{
    if (unk_18[0]->unk_14 == 0) {
        return;
    }
    fx32 pos = EvalQuadratic(unk_68, unk_60, unk_70, unk_64);
    unk_70 = unk_70 < unk_74 ? unk_70 + 0x1000 : 0;
    int x = pos >> 12;
    unk_18[0]->SetPos(x + 0x14, unk_84);
    unk_18[1]->SetPos(0xEC - x, unk_84);
}

int GetItemY(int pos)
{
    return pos * 32 + 0x34;
}

void RangerNetMenuItem::SetActive(BOOL active)
{
    unk_38 = active;
    if (!active) {
        unk_34 = 0;
    }
}

BOOL RangerNetMenuItem::IsTouched()
{
    if (unk_38 == 0 || unk_2C == 0 || unk_50 == 2) {
        return FALSE;
    }
    return unk_10->GetTouchTrigger();
}
