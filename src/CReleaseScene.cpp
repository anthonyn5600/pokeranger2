#include "scene/CReleaseScene.hpp"

#include "CPlayerHPGauge.hpp"
#include "Camera2D.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200D3F8.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201CA6C.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_02040F34.hpp"
#include "UnkClass_020416AC.hpp"
#include "UnkClass_02042108.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkClass_0211E3FC.hpp"
#include "UnkStruct_020107A8.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldActorManage.hpp"
#include "interpolation.hpp"
#include "sub_02007CF0.hpp"

// Fake (linker): ov7 has its own copies of the render lists' inline ctor/dtor, but mwld keeps one copy of a weak
// function for all overlays (ov0's CFieldScene emits UnkClass_0211E3FC's first; SEARCH_SYMBOL doesn't change that).
// A layout twin of UnkClass_0211E3FC gives ov7 its own copies. It must have no base or member with a dtor, else
// __cxa_vec_new gets the dtor (the original passes NULL).
class UnkClass_0211E018 {
public:
    UnkClass_0211E018()
    {
        GetList()->sub_020091DC();
    }

    ~UnkClass_0211E018()
    {
    }

    UnkClass_0211E3FC *GetList()
    {
        return (UnkClass_0211E3FC *)this;
    }

public:
    CDrawObject *unk_00;
};

extern "C" {
BOOL sub_02015E54(UnkClass_020B26A0 *save, u32 id);
int sub_020161AC(UnkClass_020B26A0 *save, u32 level, int group);
int sub_020161E4(UnkClass_020B26A0 *save, int group);
}

// Screen positions of the 10 Pokémon for each count 1..
static s16 sPositions[132] = {
    0x80,
    0x7C,
    0x50,
    0x7C,
    0xB0,
    0x7C,
    0x80,
    0x58,
    0x48,
    0x88,
    0xB8,
    0x88,
    0x58,
    0x58,
    0x58,
    0x90,
    0xA8,
    0x58,
    0xA8,
    0x90,
    0x80,
    0x58,
    0x38,
    0x58,
    0xC8,
    0x58,
    0x58,
    0x90,
    0xA8,
    0x90,
    0x28,
    0x58,
    0x70,
    0x58,
    0xB8,
    0x58,
    0x48,
    0x90,
    0x90,
    0x90,
    0xD8,
    0x90,
    0x60,
    0x58,
    0xA0,
    0x58,
    0x20,
    0x58,
    0xE0,
    0x58,
    0x80,
    0x90,
    0xC0,
    0x90,
    0x40,
    0x90,
    0x60,
    0x58,
    0xA0,
    0x58,
    0x20,
    0x58,
    0xE0,
    0x58,
    0x60,
    0x90,
    0xA0,
    0x90,
    0x20,
    0x90,
    0xE0,
    0x90,
    0x78,
    0x50,
    0xC8,
    0x50,
    0x28,
    0x50,
    0x90,
    0x78,
    0xE0,
    0x78,
    0x40,
    0x78,
    0x78,
    0xA0,
    0xC8,
    0xA0,
    0x28,
    0xA0,
    0x60,
    0x50,
    0xA0,
    0x50,
    0x20,
    0x50,
    0xE0,
    0x50,
    0x40,
    0x78,
    0xC0,
    0x78,
    0x60,
    0x98,
    0xA0,
    0x98,
    0x20,
    0x98,
    0xE0,
    0x98,
    0x60,
    0x50,
    0xA0,
    0x50,
    0x20,
    0x50,
    0xE0,
    0x50,
    0x80,
    0x78,
    0xC8,
    0x78,
    0x30,
    0x78,
    0x60,
    0x98,
    0xA0,
    0x98,
    0x20,
    0x98,
    0xE0,
    0x98,
};

CReleaseScene::CReleaseScene(CGame *game)
{
    m_game = game;
    unk_08 = NULL;
    ov7_0211CAB4();
}

CReleaseScene::~CReleaseScene()
{
    SAFE_DELETE(unk_08);
}

void CReleaseScene::ov7_0211CAB4()
{
    unk_08 = new UnkClass_0211CD84(m_game);
}

void CReleaseScene::func5()
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
    GX_SetBankForOBJ(GX_VRAM_OBJ_64_E);
    GX_SetBankForBG(GX_VRAM_BG_128_D);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    G2_SetBG0Priority(3);
    G2_SetBG1Priority(2);
    G2_SetBG2Priority(1);
    G2_SetBG3Priority(0);

    GXS_SetGraphicsMode(GX_BGMODE_0);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    G2S_SetBG0Priority(3);
    G2S_SetBG1Priority(2);
    G2S_SetBG2Priority(1);
    G2S_SetBG3Priority(0);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG3);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3);
    GX_DispOn();
    GXS_DispOn();
}

void CReleaseScene::func6()
{
    m_game->sub_020101F4(0x60000, 0, 0x4000);
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    if (unk_08 != NULL) {
        unk_08->ov7_0211E02C();
    }
}

void CReleaseScene::func7()
{
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    m_game->sub_020101F4(0x80000, 0, 0x4000);
}

u32 CReleaseScene::func0()
{
    if (unk_08 != NULL) {
        unk_08->ov7_0211D054();
        int result = unk_08->ov7_0211F604();
        if (result != -1) {
            return result == 0 ? 6 : 1;
        }
    } else {
        return 1;
    }
    return -1;
}

void CReleaseScene::func1()
{
    if (unk_08 != NULL) {
        unk_08->ov7_0211D38C();
    }
}

void CReleaseScene::func2()
{
    if (unk_08 != NULL) {
        unk_08->ov7_0211D3F0();
    }
}

void CReleaseScene::func3()
{
    sub_02007D98();
}

u32 CReleaseScene::getSceneId()
{
    return 7;
}

UnkClass_0211CD84::UnkClass_0211CD84(CGame *game)
{
    unk_27C = game;
    ov7_0211CFB4();
}

UnkClass_0211CD84::~UnkClass_0211CD84()
{
    ov7_0211D62C();
    SAFE_DELETE(unk_014);
    SAFE_DELETE(unk_00C);
    SAFE_DELETE(unk_010);
    SAFE_DELETE(unk_058);
    SAFE_DELETE(unk_05C);
    SAFE_DELETE(unk_0A0);
    if (unk_0A8 != NULL) {
        delete[] unk_0A8;
        unk_0A8 = NULL;
    }
    SAFE_DELETE(unk_0A4);
    SAFE_DELETE(unk_0AC);
    SAFE_DELETE(unk_224);
    SAFE_DELETE(unk_228);
    SAFE_DELETE(unk_278);
}

void UnkClass_0211CD84::ov7_0211CFB4()
{
    int i;

    unk_000 = 0;
    unk_014 = NULL;
    unk_00C = NULL;
    unk_010 = NULL;
    unk_058 = NULL;
    unk_05C = NULL;
    unk_0A0 = NULL;
    unk_0A4 = NULL;
    unk_0A8 = NULL;
    unk_0AC = NULL;
    for (i = 0; i < 8; i++) {
        unk_060[i] = NULL;
    }
    for (i = 0; i < 16; i++) {
        unk_0B4[i].unk_00 = FALSE;
    }
    unk_224 = NULL;
    unk_220 = 0x10;
    unk_222 = 0x10;
    unk_008 = ov7_0211EFE4();
    unk_228 = NULL;
    unk_278 = NULL;
    unk_21C = -1;
}

void UnkClass_0211CD84::ov7_0211D054()
{
    if (unk_058 != NULL) {
        unk_058->sub_0200F64C();
    }
    if (unk_05C != NULL) {
        unk_05C->sub_0200F64C();
    }
    if (unk_010 != NULL) {
        unk_010->sub_0200D9CC();
        unk_0A4->sub_0203F2B0(NULL, FALSE);
    }
    if (unk_224 != NULL) {
        unk_224->Update();
    }
    if (unk_278 != NULL) {
        unk_278->vfunc_08();
    }

    switch (unk_000) {
    case 8:
        if (ov7_0211F5BC()) {
            break;
        }
        if (!ov7_0211F4FC()) {
            if (--unk_1F4 > 0) {
                break;
            }
        }
        unk_000 = 1;
        unk_27C->m_textboxData->sub_02009FB0(1, 0);
        unk_27C->m_textboxData->sub_0200AA04(0);
        break;
    case 7:
        if (!unk_27C->m_textboxData->sub_02009ECC()) {
            unk_000 = 1;
        }
        break;
    case 1:
        ov7_0211E1B4();
        break;
    case 2: {
        if (--unk_218 != 0) {
            break;
        }
        unk_218 = 10;
        ov7_0211EE6C(ov7_0211F100() != 0, ov7_0211F168() != 0);
        if (ov7_0211EF5C() > 1) {
            u32 msg = 0x5D;
            if (unk_204 != 0) {
                msg = 0x5E;
            }
            ov7_0211F1FC(msg, 1, 1, 1, 0);
            unk_000 = 5;
            break;
        }
        if (unk_204 != 0) {
            unk_000 = 3;
        } else {
            unk_000 = 4;
        }
        break;
    }
    case 5:
        if (unk_27C->m_textboxData->sub_02009ECC()) {
            break;
        }
        if (unk_27C->m_textboxData->sub_0200B6A4(0)) {
            break;
        }
        if (unk_27C->m_textboxData->sub_0200B6D4() == 0) {
            unk_218 = 1;
            if (unk_204 != 0) {
                unk_000 = 3;
            } else {
                unk_000 = 4;
            }
            break;
        }
        unk_000 = 1;
        break;
    case 3:
        if (--unk_218 != 0) {
            break;
        }
        ov7_0211EC8C();
        break;
    case 4:
        if (--unk_218 != 0) {
            break;
        }
        ov7_0211EB7C();
        break;
    case 10:
        ov7_0211E894();
        break;
    case 11:
        ov7_0211E680();
        break;
    }
}

void UnkClass_0211CD84::ov7_0211D38C()
{
    switch (unk_000) {
    case 0:
    case 9:
        break;
    case 6:
        if (!ov7_0211F5BC()) {
            unk_000 = 9;
        }
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 10:
    case 11:
    default:
        ov7_0211D698();
        break;
    }
}

void UnkClass_0211CD84::ov7_0211D3F0()
{
    if (unk_220 == unk_222) {
        return;
    }
    unk_220 = unk_222;
    u16 id = 0;
    if (unk_220 != 0x10) {
        id = unk_0B4[unk_220].unk_0C;
    }
    ov7_0211F2B0(id);
}

void UnkClass_0211CD84::ov7_0211D42C()
{
    for (int i = 0; i <= 2; i++) {
        unk_060[i] = unk_058->sub_0200F4FC(0, (i + i / 2) * 14 + 0x10, 0x10, 0);
        unk_080[i] = unk_058->unk_24;
    }
    unk_060[3] = unk_058->sub_0200F4FC(0xA, 0x2C, 0x10, 0);
    unk_060[4] = unk_058->sub_0200F4FC(0xB, 0x50, 0x10, 0);
    unk_060[5] = unk_058->sub_0200F4FC(0xD, 0x80, 0xF, 0);
    unk_080[5] = unk_058->unk_24;
    unk_060[5]->sub_0200EBF4(0x40, 0x20, 0, 0);
    unk_060[6] = unk_058->sub_0200F4FC(0x10, 0xC3, 0xF, 0);
    unk_080[6] = unk_058->unk_24;
    unk_060[6]->sub_0200EBF4(0x40, 0x20, 0, 0);

    int count = sub_020161E4(&MAIN_BSS_020B26A0, -1);
    int max = sub_020161AC(&MAIN_BSS_020B26A0, 0xFF, -1);
    if (count <= max) {
        unk_060[7] = unk_05C->sub_0200F4FC(0, 0xF0, 0x10, 0);
        unk_060[7]->sub_0200EBF4(0x20, 0x20, 0, 0);
        ov7_0211F1FC(0x17, 1, 2, 1, 0);
    } else {
        ov7_0211F1FC(0x66, 1, 2, 1, 0);
    }
    ov7_0211E080(count);
    ov7_0211E168(max);
    ov7_0211EE6C(FALSE, FALSE);
}

void UnkClass_0211CD84::ov7_0211D62C()
{
    unk_27C->m_textboxData->sub_0200AA14();
    unk_27C->m_textboxData->sub_02009FB0(1, 1);
    CSoftwareSprite::sub_02005120();
    unk_27C->unk_146C.sub_02008DB4(30);
    unk_27C->m_textboxData->sub_0200AC90();
    unk_27C->m_textboxData->sub_020092D4();
}

void UnkClass_0211CD84::ov7_0211D698()
{
    if (unk_058 != NULL) {
        unk_058->sub_0200F71C();
    }
    if (unk_05C != NULL) {
        unk_05C->sub_0200F71C();
    }
    if (unk_224 != NULL) {
        unk_224->Render();
    }
    if (unk_00C == NULL) {
        return;
    }
    unk_00C->sub_020037B4();
    unk_00C->sub_0200381C();
    G3_StoreMtx(0);
    if (unk_014 != NULL) {
        sub_020423F4(unk_014, unk_00C);
    }
    unk_0A4->sub_0203F348(unk_0A8->GetList(), unk_0AC);
    if (unk_000 != 10) {
        if (unk_000 == 11) {
            unk_018.m_alpha = unk_216;
            unk_018.Render(unk_00C);
        } else {
            ov7_0211F370(unk_00C);
        }
    }
    UnkClass_0211E3FC *list = unk_0A8[0].GetList();
    int count = list->sub_02009188(unk_00C, 0);
    list->sub_020091DC();
    sub_02041924(unk_0AC, unk_00C, 0, 0 - count);
    list = unk_0A8[4].GetList();
    count = list->sub_02009188(unk_00C, 0x618);
    list->sub_020091DC();
    sub_02041924(unk_0AC, unk_00C, 4, 0x618 - count);
    sub_020419AC(unk_0AC);
    if (unk_278 != NULL) {
        unk_278->vfunc_0C(unk_00C);
    }
}

void UnkClass_0211CD84::ov7_0211D7FC()
{
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2_SetBG0Priority(3);
    G2_SetBG1Priority(2);
    G2_SetBG2Priority(1);
    G2_SetBG3Priority(0);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x04000);
    CSoftwareSprite::sub_020050C8();
    unk_27C->m_audioEngine->sub_020345D4();

    int charNo = 0;
    SAFE_DELETE(unk_058);
    unk_058 = new UnkClass_0200ECD0((GXOamAttr *)&unk_27C->unk_0024[0x40],
        unk_27C->unk_14A8,
        FALSE,
        0x40);
    charNo += unk_058->sub_0200EE14("data/menu", "mr000_00", 0, 4);
    SAFE_DELETE(unk_05C);
    unk_05C = new UnkClass_0200ECD0((GXOamAttr *)&unk_27C->unk_0024[0x50],
        unk_27C->unk_14A8,
        FALSE,
        0x40);
    unk_05C->sub_0200EE14("data/menu", "ma005_00", charNo / 32, 9);

    CGame *game = unk_27C;
    game->m_textboxData->sub_02009328(
        game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->unk_14B0, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    unk_27C->m_textboxData->sub_0200AB28(0);
    BGS_LoadCharAndPltt("menu/", "mr000_bg_", 2, "mr000", 0x100, "mr000", 1);
    BGS_LoadScr("menu/", "mr000_bg_", 2, "mr000_00", 1, 0x100, 0, 0);

    SAFE_DELETE(unk_00C);
    unk_00C = new Camera2D();
    SAFE_DELETE(unk_010);
    unk_010 = new UnkClass_0200D3F8((UnkStruct_0200D3F8_Target *)unk_00C);
    unk_00C->sub_02003788(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);

    unk_0B0 = &MAIN_BSS_020B26A0;
    SAFE_DELETE(unk_014);
    unk_014 = new UnkClass_02042108(unk_0B0->unk_8BA0);
    unk_0A0 = new UnkClass_02040F34();
    SAFE_DELETE(unk_0A4);
    unk_0A4 = new CFieldActorManage();
    unk_0A4->sub_0203EFE4(0x10);
    if (unk_0A8 != NULL) {
        delete[] unk_0A8;
        unk_0A8 = NULL;
    }
    unk_0A8 = new UnkClass_0211E018[10];
    SAFE_DELETE(unk_0AC);
    unk_0AC = new UnkClass_020416AC(5);

    UnkStruct_020107A8 *info;
    int n;
    s32 i;
    UnkStruct_020155FC *data;
    u16 base;
    CFieldActor *actor;
    u32 id;
    int count;

    base = 0;
    for (n = 0; n < sub_020161E4(unk_0B0, -1); n++) {
        base += n;
    }

    count = 0;
    for (i = 0; i < 10; i++) {
        unk_0B4[i].unk_0A = 0;
        unk_0B4[i].unk_0C = 0;
        unk_0B4[i].unk_04 = 0;
        data = sub_020155FC(unk_0B0, i);
        if (data != NULL && (data->unk_08 & 1) && !(data->unk_08 & 2)) {
            id = (data->unk_04 & 0xFFF) | ((6 << 24) | ((data->unk_02 & 0xFFF) << 12));
            info = sub_020107A8(unk_27C->unk_1434, data->unk_00);
            actor = new CFieldActor();
            actor->sub_0203DA60(id);
            actor->sub_0203C418(0, info->unk_00, info->unk_02, 0xE, 1);
            unk_0B4[i].unk_0A = info->unk_00;
            unk_0B4[i].unk_0C = data->unk_00;
            unk_0B4[i].unk_08 = info->unk_05 == 9 ? info->unk_06 : -1;
            unk_0B4[i].unk_04 = data->unk_08 & 4;
            actor->SetUnkBC(info->unk_0A, info->unk_0B);
            actor->SetUnkBE(info->unk_0C, info->unk_0D);
            fx32 y = (sPositions[(base + count) * 2 + 1] - 0x60) << FX32_SHIFT;
            fx32 x = (sPositions[(base + count) * 2] - 0x80) << FX32_SHIFT;
            actor->SetPosXY(x, y);
            Rectangle bounds = {
                { info->unk_07 << FX32_SHIFT, info->unk_08 << FX32_SHIFT },
                { info->unk_09 << 13, info->unk_09 << 13 }
            };
            actor->unk_24.pos.x = bounds.pos.x;
            actor->unk_24.pos.y = bounds.pos.y;
            actor->unk_24.size.x = bounds.size.x;
            actor->unk_24.size.y = bounds.size.y;
            unk_0A4->Set(i, actor);
            count++;
        }
    }

    SAFE_DELETE(unk_224);
    unk_224 = new UnkClass_0201CA6C();
    unk_224->Release();
    unk_224->Load(0, 0, 0);
    SAFE_DELETE(unk_278);
    unk_278 = new CPlayerHPGauge();
    unk_278->SetVisible(TRUE);
    unk_278->SetHP(unk_0B0->unk_0001, unk_0B0->unk_0002);
    unk_278->SetPartnerVisible(FALSE);
    ov7_0211F2E0();
    unk_018.SetRectangle(0, 0, 0x100000, 0x100000, 0x3F2);
    unk_018.m_color = 0;
    unk_018.m_polygonID = 0x2B;
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_BG0, 8, 8);
}

BOOL UnkClass_0211CD84::ov7_0211E02C()
{
    unk_000 = 1;
    ov7_0211E050();
    ov7_0211F534();
    return TRUE;
}

BOOL UnkClass_0211CD84::ov7_0211E050()
{
    ov7_0211D7FC();
    ov7_0211D42C();
    unk_27C->unk_146C.sub_02008DB4(60);
    return TRUE;
}

void UnkClass_0211CD84::ov7_0211E080(int count)
{
    if (unk_058 == NULL) {
        return;
    }
    if (count / 10 > 0) {
        unk_060[0]->unk_14 = 1;
        ov7_0211E19C(unk_080[0], count / 10);
    } else {
        unk_060[0]->unk_14 = 0;
    }
    ov7_0211E19C(unk_080[1], count % 10);
    int left = sub_020161E4(&MAIN_BSS_020B26A0, -1) - ov7_0211EF5C();
    if (left > sub_020161AC(&MAIN_BSS_020B26A0, 0xFF, -1)) {
        unk_060[0]->sub_0200EB20(5);
        unk_060[1]->sub_0200EB20(5);
    } else {
        unk_060[0]->sub_0200EB20(4);
        unk_060[1]->sub_0200EB20(4);
    }
}

void UnkClass_0211CD84::ov7_0211E168(int count)
{
    ov7_0211E19C(unk_080[2], count % 10);
}

void UnkClass_0211CD84::ov7_0211E19C(int idx, int anim)
{
    if (unk_058 != NULL) {
        unk_058->sub_0200F628(idx, anim);
    }
}

void UnkClass_0211CD84::ov7_0211E1B4()
{
    if (unk_060[7] != NULL && ((u16)(unk_27C->unk_0014->unk_0002 & PAD_BUTTON_B) || unk_060[7]->sub_0200EB84())) {
        unk_27C->m_audioEngine->sub_02034C44(0x103);
        ov7_0211F1E8();
        return;
    }
    if (unk_060[5] != NULL && unk_060[5]->unk_14 != 0) {
        if (ov7_0211F168() != 0 && unk_060[5]->sub_0200EB84()) {
            ov7_0211EF14(0);
            return;
        }
    }
    if (unk_060[6] != NULL && unk_060[6]->unk_14 != 0) {
        if (ov7_0211F100() != 0 && unk_060[6]->sub_0200EB84()) {
            ov7_0211EF14(1);
            return;
        }
    }

    CTouchPanel *tp = unk_27C->touchPanel;
    if (tp->unk_04 == 0) {
        return;
    }
    Point2D pos = { (tp->unk_0A.x - 0x80) << FX32_SHIFT, (tp->unk_0A.y - 0x60) << FX32_SHIFT };
    pos.x -= unk_00C->unk_1C;
    pos.y -= unk_00C->unk_20;
    for (int i = 0; i < unk_0A4->m_count; i++) {
        CFieldActor *actor = unk_0A4->Get(i);
        if (actor != NULL && actor->IsActive() && actor->IsTouched(pos)) {
            if (unk_0B4[i].unk_04 != 0) {
                unk_27C->m_audioEngine->sub_02034C44(0xFD);
                ov7_0211F1FC(0x1B, 1, 2, 1, 0);
            } else {
                if (!unk_0B4[i].unk_00) {
                    unk_27C->m_audioEngine->sub_02034C44(0xFA);
                    if (unk_21C != i) {
                        if (unk_21C < 0x10) {
                            CFieldActor *prev = unk_0A4->Get(unk_21C);
                            if (prev != NULL) {
                                prev->ClearUnk1A8Bits(1);
                            }
                        }
                        unk_21C = i;
                        if (actor->unk_08 != NULL) {
                            actor->unk_08->ResetOutlinePhase();
                            actor->unk_08->SetOutlineColor(0x7FE0);
                            actor->unk_08->SetOutlineWidth(2);
                            actor->unk_08->StartOutline(-1);
                        }
                        ov7_0211F29C(i);
                    }
                } else {
                    if (unk_21C == i) {
                        actor->ClearUnk1A8Bits(1);
                        ov7_0211F29C(0x10);
                        unk_21C = 0x10;
                    }
                    unk_27C->m_audioEngine->sub_02034C44(0xFE);
                }
                unk_0B4[i].unk_00 = !unk_0B4[i].unk_00;
            }
            break;
        }
    }
    int selected = ov7_0211EF5C();
    ov7_0211E080(sub_020161E4(&MAIN_BSS_020B26A0, -1) - selected);
    ov7_0211EE6C(ov7_0211F100() != 0, ov7_0211F168() != 0);
}

void UnkClass_0211CD84::ov7_0211E680()
{
    switch (unk_1F8) {
    case 0:
        unk_1FC = ov7_0211F100();
        for (u32 i = 0; i < unk_0A4->m_count; i++) {
            if (unk_1FC & (1 << i)) {
                unk_0A4->Get(i)->unk_04 |= 0x100;
            }
        }
        unk_27C->m_textboxData->sub_02009FB0(1, 0);
        ov7_0211EE6C(FALSE, FALSE);
        ov7_0211EB04(0x1F, 60);
        unk_1F8 = 1;
    case 1:
        if (unk_208) {
            break;
        }
        unk_1F8 = 2;
    case 2: {
        u16 anim = 0;
        u16 hp = 0;
        unk_1FC = ov7_0211F100();
        if (unk_1FC == 0) {
            return;
        }
        ov7_0211F01C(&hp, &anim);
        hp += unk_0B0->unk_0001;
        if (hp > unk_0B0->unk_0002) {
            hp = unk_0B0->unk_0002;
        }
        unk_0B0->unk_0001 = hp;
        unk_278->SetCurrentHP(hp);
        unk_278->StartHeal(anim);
        unk_27C->m_audioEngine->sub_02034C44(0x143);
        unk_1F8 = 3;
        ov7_0211ED10(TRUE);
    }
    case 3:
        if (!unk_278->IsHealing()) {
            unk_27C->m_audioEngine->sub_02034C5C(0x143);
            unk_1F8 = 4;
            unk_200 = 30;
            ov7_0211ED10(FALSE);
            ov7_0211EB3C(60);
        }
        break;
    case 4:
        if (!unk_208) {
            ov7_0211EB7C();
        }
        break;
    }
    ov7_0211EA74();
}

void UnkClass_0211CD84::ov7_0211E894()
{
    unk_218++;
    for (s32 i = 0; i < unk_0A4->m_count; i++) {
        if (unk_0B4[i].unk_00) {
            CFieldActor *actor = unk_0A4->Get(i);
            switch (unk_0B4[i].unk_0E) {
            case 0:
                if (unk_218 > unk_0B4[i].unk_10) {
                    unk_0B4[i].unk_0E = 1;
                    actor->unk_04 |= 0x100;
                    ov7_0211ECA4(actor, i);
                }
                break;
            case 1:
                if (actor != NULL && !actor->IsC8Set()) {
                    unk_0B4[i].unk_00 = FALSE;
                    unk_0A4->sub_0203F144(i);
                }
                break;
            }
        }
    }
    if (ov7_0211EF5C() > 0) {
        return;
    }
    ov7_0211E080(sub_020161E4(&MAIN_BSS_020B26A0, -1));
    unk_000 = 1;
    if (unk_060[7] == NULL) {
        if (!ov7_0211EFE4()) {
            ov7_0211F1E8();
            return;
        }
        ov7_0211F1FC(0x66, 1, 2, 1, 0);
        return;
    }
    if (sub_020161E4(&MAIN_BSS_020B26A0, -1) - ov7_0211EFA0() <= 0) {
        ov7_0211F1E8();
        return;
    }
    ov7_0211F1FC(0x17, 1, 2, 1, 0);
}

void UnkClass_0211CD84::ov7_0211EA74()
{
    if (unk_208 && unk_210 > 0) {
        unk_20C++;
        unk_216 = LinearInterpolate(unk_214 << FX32_SHIFT, unk_215 << FX32_SHIFT, unk_20C, unk_210) >> FX32_SHIFT;
        if (unk_20C < unk_210) {
            return;
        }
        unk_210 = 0;
        unk_20C = 0;
        if (unk_216 != 0) {
            return;
        }
        unk_208 = FALSE;
        unk_214 = 0;
        unk_216 = 0;
        return;
    }
    unk_208 = FALSE;
}

void UnkClass_0211CD84::ov7_0211EB04(u8 alpha, int duration)
{
    unk_208 = TRUE;
    unk_20C = 0;
    unk_214 = 0;
    if (duration >= 0) {
        unk_210 = duration;
        unk_215 = alpha;
        unk_216 = 0;
    } else {
        unk_210 = 0;
        unk_215 = 0;
        unk_216 = alpha;
    }
}

void UnkClass_0211CD84::ov7_0211EB3C(int duration)
{
    unk_20C = 0;
    unk_215 = 0;
    if (duration >= 0) {
        unk_208 = TRUE;
        unk_210 = duration;
        unk_214 = unk_216;
    } else {
        unk_208 = FALSE;
        unk_210 = 0;
        unk_214 = 0;
        unk_216 = 0;
    }
}

void UnkClass_0211CD84::ov7_0211EB7C()
{
    if (ov7_0211EF5C() == 0) {
        return;
    }
    unk_218 = 0;
    int count = 0;
    for (int i = 0; i < unk_0A4->m_count; i++) {
        CFieldActor *actor = unk_0A4->Get(i);
        if (actor != NULL && unk_0B4[i].unk_00) {
            unk_27C->m_textboxData->sub_020097FC(0, unk_0B4[i].unk_0A);
            unk_000 = 10;
            unk_0B4[i].unk_0E = 0;
            count++;
            unk_0B4[i].unk_10 = count * 20;
        }
    }
    if (ov7_0211EF5C() == 1) {
        ov7_0211F1FC(0x18, 0, 0, 1, 0);
    } else {
        ov7_0211F1FC(0x19, 0, 0, 1, 0);
    }
    ov7_0211EE6C(FALSE, FALSE);
}

void UnkClass_0211CD84::ov7_0211EC8C()
{
    unk_1F8 = 0;
    unk_000 = 11;
}

void UnkClass_0211CD84::ov7_0211ECA4(CFieldActor *actor, int idx)
{
    unk_27C->m_audioEngine->sub_02034CF4(unk_0B4[idx].unk_0A, 0x40);
    sub_02015E54(unk_0B0, actor->unk_58);
    actor->ClearUnk1A8Bits(1);
    actor->sub_0203D404(unk_00C->GetOffset());
}

void UnkClass_0211CD84::ov7_0211ED10(BOOL heal)
{
    int i;
    BOOL played = FALSE;
    for (i = 0; i < unk_0A4->m_count; i++) {
        if (unk_1FC & (1 << i)) {
            CFieldActor *actor = unk_0A4->Get(i);
            if (heal) {
                actor->sub_0202DC54(8, 0);
                if (actor->unk_08 != NULL) {
                    actor->unk_08->ResetOutlinePhase();
                    actor->unk_08->SetOutlineColor(0x7FE0);
                    actor->unk_08->SetOutlineWidth(2);
                    actor->unk_08->StartOutline(-1);
                }
                if (!played) {
                    unk_27C->m_audioEngine->sub_02034CF4(unk_0B4[i].unk_0A, 0x40);
                    played = TRUE;
                }
            } else {
                actor->sub_0202DC54(2, 0);
                actor->ClearUnk1A8Bits(1);
            }
        }
    }
}

void UnkClass_0211CD84::ov7_0211EE6C(BOOL a, BOOL b)
{
    if (unk_060[6] != NULL) {
        unk_058->sub_0200F628(unk_080[6], a ? 0xF : 0x10);
    }
    if (unk_060[5] != NULL) {
        unk_058->sub_0200F628(unk_080[5], b ? 0xC : 0xD);
    }
}

void UnkClass_0211CD84::ov7_0211EEC4(BOOL a)
{
    if (a) {
        if (unk_060[6] != NULL) {
            unk_058->sub_0200F628(unk_080[6], 0x11);
        }
    } else {
        if (unk_060[5] != NULL) {
            unk_058->sub_0200F628(unk_080[5], 0xE);
        }
    }
}

void UnkClass_0211CD84::ov7_0211EF14(int choice)
{
    unk_27C->m_audioEngine->sub_02034C44(0xFF);
    ov7_0211EEC4(choice);
    unk_204 = choice;
    unk_000 = 2;
    unk_218 = 10;
}

s16 UnkClass_0211CD84::ov7_0211EF5C()
{
    int i;
    s16 count = 0;
    for (i = 0; i < unk_0A4->m_count; i++) {
        if (unk_0B4[i].unk_00) {
            count++;
        }
    }
    return count;
}

s16 UnkClass_0211CD84::ov7_0211EFA0()
{
    int i;
    s16 count = 0;
    for (i = 0; i < unk_0A4->m_count; i++) {
        if (unk_0B4[i].unk_04) {
            count++;
        }
    }
    return count;
}

BOOL UnkClass_0211CD84::ov7_0211EFE4()
{
    if (sub_020161E4(&MAIN_BSS_020B26A0, -1) > sub_020161AC(&MAIN_BSS_020B26A0, 0xFF, -1)) {
        return TRUE;
    }
    return FALSE;
}

void UnkClass_0211CD84::ov7_0211F01C(u16 *hp, u16 *anim)
{
    *hp = 0;
    *anim = 0;
    for (int i = 0; i < unk_0A4->m_count; i++) {
        if (unk_1FC & (1 << i)) {
            *anim += unk_0B4[i].unk_08;
            switch (unk_0B4[i].unk_08) {
            case 0:
            case 1:
            default:
                *hp += 5;
                break;
            case 2:
                *hp += 10;
                break;
            case 3:
                *hp += 20;
                break;
            case 4:
                *hp += 30;
                break;
            case 5:
                *hp += 50;
                break;
            }
        }
    }
    if (*anim > 5) {
        *anim = 5;
    }
}

u32 UnkClass_0211CD84::ov7_0211F100()
{
    u32 mask = 0;
    if (ov7_0211F4E0()) {
        return 0;
    }
    u32 selected = ov7_0211F168();
    for (u32 i = 0; i < unk_0A4->m_count; i++) {
        if ((selected & (1 << i)) && unk_0B4[i].unk_08 >= 0) {
            mask |= 1 << i;
        }
    }
    return mask;
}

u32 UnkClass_0211CD84::ov7_0211F168()
{
    u32 i;
    u32 mask = 0;
    for (i = 0; i < unk_0A4->m_count; i++) {
        CFieldActor *actor = unk_0A4->Get(i);
        if (actor != NULL && actor->IsActive() && unk_0B4[i].unk_00) {
            mask |= 1 << i;
        }
    }
    return mask;
}

void UnkClass_0211CD84::ov7_0211F1E8()
{
    unk_000 = 6;
    ov7_0211F578();
}

void UnkClass_0211CD84::ov7_0211F1FC(u32 msg, u32 arg1, int next, u32 arg3, u32 arg4)
{
    unk_27C->m_textboxData->sub_02009FB0(1, 0);
    unk_27C->m_textboxData->sub_0200AA04(0);
    unk_27C->m_textboxData->sub_0200AD34(msg, arg3, arg1, arg4);
    switch (next) {
    case 0:
        break;
    case 1:
        unk_000 = 7;
        break;
    case 2:
        unk_000 = 8;
        unk_1F4 = 90;
        break;
    }
}

void UnkClass_0211CD84::ov7_0211F29C(u16 idx)
{
    if (unk_220 != idx) {
        unk_222 = idx;
    }
}

void UnkClass_0211CD84::ov7_0211F2B0(u16 id)
{
    if (unk_224 == NULL) {
        return;
    }
    unk_224->sub_0201DF54(id, 0);
    unk_224->sub_0201EC80();
    unk_224->sub_0201E27C();
}

void UnkClass_0211CD84::ov7_0211F2E0()
{
    SAFE_DELETE(unk_228);
    unk_228 = new UnkClass_0201AAE0("RSC", "data/menu/mr001_00_LZ.bin", "RSC:mr001_00.NCBR", "RSC:mr001.NCLR", "RSC:mr001_00.NCER", "RSC:mr001_00.cac");
}

static inline fx32 RectX(Rectangle rect)
{
    return rect.pos.x;
}

static inline fx32 RectY(Rectangle rect)
{
    return rect.pos.y;
}

void UnkClass_0211CD84::ov7_0211F370(Camera2D *camera)
{
    int i;
    CSoftwareSprite *sprite = &unk_22C;
    sprite->unk_2C = (UnkClass_CPrimitive_ImageProxy *)unk_228->m_image;
    sprite->unk_30 = NULL;
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_228->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_228->m_cells;
    sprite->m_alpha = 0x10;
    sprite->m_z = -500;
    for (i = 0; i < unk_0A4->m_count; i++) {
        CFieldActor *actor = unk_0A4->Get(i);
        if (actor != NULL && unk_0B4[i].unk_00) {
            if (unk_0B4[i].unk_08 < 0 || ov7_0211F4E0()) {
                sprite->m_cellDataIdx = 0;
            } else {
                sprite->m_cellDataIdx = 1;
            }
            fx32 x = actor->GetX() + RectX(actor->unk_24);
            fx32 y = actor->GetY() + RectY(actor->unk_24);
            sprite->SetXY(x, y);
            unk_22C.Render(camera);
        }
    }
}

BOOL UnkClass_0211CD84::ov7_0211F4E0()
{
    if (unk_0B0->unk_0001 >= unk_0B0->unk_0002) {
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_0211CD84::ov7_0211F4FC()
{
    UnkClass_02001C04 *keys = unk_27C->unk_0014;
    CTouchPanel *tp = CGame::GetInstance()->touchPanel;
    if ((u16)(keys->unk_0002 & PAD_BUTTON_A) || tp->unk_04 != 0) {
        return TRUE;
    }
    return FALSE;
}

void UnkClass_0211CD84::ov7_0211F534()
{
    if (unk_27C == NULL) {
        return;
    }
    unk_27C->unk_14BC->sub_0200E0E0(3, 15);
    unk_27C->unk_14C0->sub_0200E0E0(3, 15);
}

void UnkClass_0211CD84::ov7_0211F578()
{
    if (unk_27C == NULL) {
        return;
    }
    unk_27C->unk_14BC->sub_0200E0E0(4, 15);
    unk_27C->unk_14C0->sub_0200E0E0(4, 15);
}

BOOL UnkClass_0211CD84::ov7_0211F5BC()
{
    if (unk_27C->unk_14C0->sub_0200E310() || unk_27C->unk_14BC->sub_0200E310()) {
        return TRUE;
    }
    return FALSE;
}

int UnkClass_0211CD84::ov7_0211F604()
{
    if (unk_000 != 9) {
        return -1;
    }
    if (unk_008) {
        return 1;
    }
    return 0;
}
