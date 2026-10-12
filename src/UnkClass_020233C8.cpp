#include "UnkClass_020233C8.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "Camera2D.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201AD60.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_02022404.hpp"
#include "UnkClass_0202773C.hpp"
#include "UnkClass_02034478.hpp"
#include "common.hpp"
#include "fx_utils.hpp"

static u16 sIconOrder[9] = { 5, 2, 1, 7, 4, 6, 8, 9, 3 };

UnkClass_020233C8::UnkClass_020233C8(CGame *game)
{
    unk_0C = game;
    Init();
}

UnkClass_020233C8::~UnkClass_020233C8()
{
    SAFE_DELETE(unk_08);
}

void UnkClass_020233C8::Update()
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

void UnkClass_020233C8::Render()
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

void UnkClass_020233C8::sub_02023470()
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

void UnkClass_020233C8::Init()
{
    unk_00 = 0;
    unk_02 = 0;
    unk_04 = 0;
    unk_08 = new UnkClass_02023558(unk_0C);
}

void UnkClass_020233C8::sub_020234D4()
{
    unk_08->sub_02024380();
    unk_00 = 1;
}

void UnkClass_020233C8::sub_020234F0()
{
    unk_08->sub_020243CC();
    unk_00 = 1;
}

void UnkClass_020233C8::sub_0202350C(int timer)
{
    unk_08->sub_020243F0(timer);
    unk_00 = 1;
}

BOOL UnkClass_020233C8::IsActive()
{
    return unk_08->IsActive();
}

int UnkClass_020233C8::GetSelection()
{
    if (unk_00 != 1) {
        return -1;
    }
    return unk_08->GetSelection();
}

UnkClass_02023558::UnkClass_02023558(CGame *game)
{
    unk_120 = game;
    Init();
}

UnkClass_02023558::~UnkClass_02023558()
{
    Release();
}

void UnkClass_02023558::Update()
{
    unk_18->Update();

    switch (unk_00) {
    case 2:
        if (!IsBusy()) {
            if (unk_08 == -1) {
                sub_02024570();
            } else if (unk_08 == 5) {
                sub_020245A8();
            } else {
                sub_02024690();
            }
        }
        break;
    case 9:
        if (unk_11C != NULL && !unk_11C->sub_0202780C()) {
            SAFE_DELETE(unk_11C);
            GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
            sub_020245D8();
        }
        break;
    case 4:
        if (!IsBusy()) {
            if (unk_08 == 5) {
                SetVisible(TRUE);
                sub_02024480();
            } else {
                unk_00 = 0;
                unk_6C->unk_14 = 0;
                sub_020244F8();
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
            sub_020244F8();
        }
        break;
    case 5:
        if (unk_18->unk_04 == 0) {
            unk_00 = 6;
            unk_120->unk_14BC->sub_0200E0E0(3, 0x1E);
            unk_120->unk_14C0->sub_0200E0E0(3, 0x1E);
        }
        break;
    case 6:
        if (IsFading()) {
            break;
        }
        unk_00 = 1;
    case 1:
        sub_02023B54();
        break;
    }

    if (unk_1C != NULL) {
        unk_1C->sub_0200F64C();
    }
    if (unk_20 != NULL) {
        unk_20->sub_0200F64C();
    }
}

void UnkClass_02023558::Render()
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

void UnkClass_02023558::sub_020237E0()
{
}

void UnkClass_02023558::Init()
{
    unk_00 = 0;

    unk_0C = new Camera2D();
    unk_0C->sub_02003788(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);

    unk_18 = new UnkClass_0201AD60();
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
    unk_114 = FALSE;
}

void UnkClass_02023558::sub_020238D8()
{
    static const int sAnims[9] = { 0, 1, 3, 2, 7, 8, 6, 4, 5 };

    unk_1C->sub_0200F6C4();
    unk_20->sub_0200F6C4();

    int y;
    int x;
    int anim;
    int i;
    for (i = 0; i < 9; i++) {
        x = (i % 3) * 0x50;
        y = (i / 3) * 0x30;
        anim = sAnims[i];
        unk_24[anim] = unk_1C->sub_0200F4FC(anim, x + 0x30, y + 0x3C, 0);
        unk_48[anim] = unk_1C->sub_0200F4FC(9, x + 0x30, y + 0x3C, 0);
        unk_24[anim]->sub_0200EB34(anim, FALSE);
        unk_48[anim]->sub_0200EB34(anim, FALSE);
        unk_24[anim]->sub_0200EBF4(0x40, 0x30, 0, 0);
    }

    unk_6C = unk_20->sub_0200F4FC(0, 0xF0, 0x10, 2);
    unk_6C->sub_0200EBF4(0x20, 0x20, 0, 0);
    SetVisible(FALSE);
}

void UnkClass_02023558::Release()
{
    SAFE_DELETE(unk_11C);
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_20);
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_18);
}

void UnkClass_02023558::SetVisible(BOOL visible)
{
    for (int i = 0; i < 9; i++) {
        unk_24[i]->SetVisible(visible);
        unk_48[i]->SetVisible(visible);
    }
    unk_6C->SetVisible(visible);
}

void UnkClass_02023558::sub_02023B54()
{
    if (!UnkClass_02022404::GetInstance()->sub_020233B4()) {
        return;
    }

    if (unk_114) {
        if (--unk_118 > 0) {
            return;
        }
        sub_02024440();
        return;
    }

    if (unk_6C != NULL && unk_6C->unk_14 != 0) {
        UnkClass_02001C04 *pad = unk_120->unk_0014;
        if (unk_6C->sub_0200EB84() || (u16)(pad->unk_0002 & PAD_BUTTON_B) || (u16)(pad->unk_0002 & PAD_BUTTON_R)) {
            sub_02024440();
            return;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (unk_24[i] != NULL && unk_24[i]->sub_0200EB84()) {
            unk_A4[i] = 5;
            unk_80[i] = 0;
            unk_00 = 2;
            unk_08 = i;
            unk_120->m_audioEngine->sub_02034C44(0xFF);
            return;
        }
    }
}

BOOL UnkClass_02023558::IsBusy()
{
    for (int i = 0; i < 9; i++) {
        if (unk_A4[i] != 4 && unk_A4[i] != 3) {
            return TRUE;
        }
    }
    return FALSE;
}

void UnkClass_02023558::SetAffineScales(BOOL scaled)
{
    for (int i = 0; i < 9; i++) {
        if (scaled) {
            SetOamAffineScale(i, unk_C8[i], unk_EC[i], TRUE);
        } else {
            SetOamAffineScale(i, FX32_ONE, FX32_ONE, TRUE);
        }
    }
}

void UnkClass_02023558::UpdateIcon(u16 index)
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
                unk_120->m_audioEngine->sub_02034C44(10);
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
                unk_120->m_audioEngine->sub_02034C44(10);
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

void UnkClass_02023558::sub_02024068(int popFrames, int bounceFrames, BOOL opening)
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

void UnkClass_02023558::Draw()
{
    G3_Identity();
    unk_0C->sub_020037B4();
    unk_0C->sub_0200381C();
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
        unk_1C->sub_0200F71C();
    }
    if (unk_20 != NULL) {
        unk_20->sub_0200F71C();
    }
    SetAffineScales(scaled);
}

void UnkClass_02023558::sub_02024214()
{
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG0, 8, 8);

    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_20);

    unk_1C = new UnkClass_0200ECD0((GXOamAttr *)unk_120->unk_0024, unk_120->unk_14A8, FALSE, 0x40);
    unk_20 = new UnkClass_0200ECD0((GXOamAttr *)&unk_120->unk_0024[0x60], unk_120->unk_14A8, FALSE, 0x40);

    int offset = 0x6000;
    offset += unk_1C->sub_0200EE14("data/menu", "cm000_00", offset / 32, 10);
    unk_20->sub_0200EE14("data/menu", "ma005_00", offset / 32, 13);
}

BOOL UnkClass_02023558::sub_02024380()
{
    unk_00 = 1;
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    sub_020244DC();
    sub_0202458C();
    unk_114 = FALSE;
    return TRUE;
}

BOOL UnkClass_02023558::sub_020243CC()
{
    sub_020244DC();
    sub_0202462C();
    unk_114 = FALSE;
    return TRUE;
}

void UnkClass_02023558::sub_020243F0(int timer)
{
    unk_00 = 1;
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    sub_020244DC();
    sub_0202458C();
    unk_114 = TRUE;
    unk_118 = timer;
}

BOOL UnkClass_02023558::sub_02024440()
{
    unk_120->m_audioEngine->sub_02034C44(0x103);
    sub_02024570();
    unk_08 = -1;
    UnkClass_02022404::GetInstance()->sub_02022DD4();
    return TRUE;
}

void UnkClass_02023558::sub_02024480()
{
    unk_00 = 9;
    SAFE_DELETE(unk_11C);
    unk_11C = new UnkClass_0202773C(unk_120);
    unk_11C->sub_020279A4();
}

BOOL UnkClass_02023558::sub_020244DC()
{
    sub_02024214();
    sub_020238D8();
    return TRUE;
}

void UnkClass_02023558::sub_020244F8()
{
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_20);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
}

void UnkClass_02023558::sub_02024570()
{
    unk_18->Close();
    sub_020245A8();
}

void UnkClass_02023558::sub_0202458C()
{
    unk_18->Open();
    sub_020245D8();
}

void UnkClass_02023558::sub_020245A8()
{
    sub_02024068(5, 6, FALSE);
    unk_6C->unk_14 = 1;
    unk_00 = 4;
}

void UnkClass_02023558::sub_020245D8()
{
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
    sub_02024068(5, 6, TRUE);
    unk_6C->unk_14 = 1;
    unk_00 = 3;
}

void UnkClass_02023558::sub_0202462C()
{
    if (unk_120 == NULL) {
        return;
    }
    unk_00 = 6;
    unk_120->unk_14BC->sub_0200E0E0(3, 0x1E);
    unk_120->unk_14C0->sub_0200E0E0(3, 0x1E);
    unk_18->Show();
    SetVisible(TRUE);
}

void UnkClass_02023558::sub_02024690()
{
    if (unk_120 == NULL) {
        return;
    }
    unk_00 = 7;
    unk_120->unk_14BC->sub_0200E0E0(4, 0x1E);
    unk_120->unk_14C0->sub_0200E0E0(4, 0x1E);
}

BOOL UnkClass_02023558::IsFading()
{
    if (unk_120->unk_14BC->sub_0200E310() || unk_120->unk_14C0->sub_0200E310()) {
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_02023558::IsActive()
{
    return unk_00 != 0;
}

int UnkClass_02023558::GetSelection()
{
    if (unk_00 != 8) {
        return -1;
    }
    return unk_08;
}

fx32 UnkClass_02023558::Quadratic(fx32 a, fx32 b, fx32 t, fx32 c)
{
    return a + (FX32_MUL(b, t) + FX32_MUL(c, FX32_MUL(t, t)));
}

fx32 UnkClass_02023558::SolveQuadratic(fx32 start, fx32 end, fx32 b, fx32 t)
{
    return FX32_DIV(end - FX32_MUL(b, t) - start, FX32_MUL(t, t));
}
