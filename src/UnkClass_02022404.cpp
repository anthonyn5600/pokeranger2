#include "UnkClass_02022404.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E330.hpp"
#include "UnkClass_0201B724.hpp"
#include "UnkClass_0201CA6C.hpp"
#include "UnkClass_0202163C.hpp"
#include "UnkClass_0202229C.hpp"
#include "UnkClass_020247CC.hpp"
#include "UnkClass_02025648.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "main.hpp"
#include "sub_02007CF0.hpp"

extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

UnkClass_02022404 *UnkClass_02022404::sInstance;

UnkClass_02022404::UnkClass_02022404(CGame *game)
{
    unk_68 = game;
    Init();
}

UnkClass_02022404::~UnkClass_02022404()
{
    SAFE_DELETE(unk_30);
    SAFE_DELETE(unk_40);
    SAFE_DELETE(unk_34);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_4C);
    SAFE_DELETE(unk_54);
}

void UnkClass_02022404::Update()
{
    switch (unk_00) {
    case 0:
        break;
    case 1:
        unk_18->Update();
        break;
    case 2:
        unk_30->sub_020255F0();
        break;
    case 3:
        break;
    case 4:
        if (unk_34->unk_70 == 0x10) {
            unk_34->Update();
            sub_020231A0();
        }
        break;
    case 5:
        break;
    case 6:
        if (unk_40->unk_50 == 0x10) {
            unk_40->Update();
            sub_020231A0();
        }
        break;
    case 7:
        break;
    case 9:
        unk_48 = unk_4C->sub_020257F4(unk_48);
        if (unk_48 == -1) {
            unk_4C->sub_020276A0();
            unk_00 = 8;
            sub_02023230(10);
        }
        break;
    case 8:
        unk_4C->sub_02027640();
        break;
    case 10:
        unk_54->Update();
        break;
    }

    if (unk_04) {
        if (sub_0202331C()) {
            return;
        }
        unk_04 = FALSE;
        switch (unk_02) {
        case 0:
            break;
        case 1:
            sub_02022EE8();
            break;
        case 2:
            sub_02022F50();
            break;
        case 3:
            break;
        case 4:
            unk_00 = 3;
            if (sub_02022FF4() != 0x10) {
                unk_04 = TRUE;
                return;
            }
            sub_02023134();
            unk_34->ReleaseMessages();
            unk_00 = 4;
            break;
        case 5:
            break;
        case 6:
            unk_00 = 5;
            if (sub_02023060() != 0x10) {
                unk_04 = TRUE;
                return;
            }
            sub_02023134();
            unk_40->ReleaseMessages();
            unk_00 = 6;
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            sub_02023078();
            break;
        case 10:
            sub_020230D4();
            break;
        }
    }
}

void UnkClass_02022404::sub_02022710()
{
}

void UnkClass_02022404::Render()
{
    switch (unk_00) {
    case 0:
        break;
    case 1:
        sub_020228C4();
        break;
    case 2:
        sub_020228D4();
        break;
    case 3:
        break;
    case 4:
        if (unk_34->unk_70 == 0x10) {
            sub_020228E4();
        }
        break;
    case 5:
        break;
    case 6:
        if (unk_40->unk_50 == 0x10) {
            sub_020228F4();
        }
        break;
    case 8:
        sub_02022904();
        break;
    case 9:
        break;
    case 10:
        sub_02022914();
        break;
    case 7:
        sub_02001210();
        break;
    }
}

void UnkClass_02022404::sub_020227AC()
{
    if (unk_00 == 7) {
        sub_02007D78();
    }
}

void UnkClass_02022404::Init()
{
    unk_02 = unk_00 = 0;
    sInstance = this;
    sub_020228C0();
    unk_04 = FALSE;
    unk_18 = new UnkClass_0202163C(unk_68);
    unk_18->Load();
    unk_40 = new UnkClass_0201B724();
    unk_40->LoadBG();
    unk_34 = new UnkClass_0201CA6C();
    unk_34->LoadPTC();
    unk_30 = new UnkClass_020247CC();
    unk_4C = new UnkClass_02025648();
    unk_54 = new UnkClass_0202229C(unk_68);
    unk_38 = -1;
    unk_44 = -1;
    unk_58 = FALSE;
    sub_02023198(1);
    unk_64 = FALSE;
}

void UnkClass_02022404::sub_020228C0()
{
}

void UnkClass_02022404::sub_020228C4()
{
    unk_18->Render();
}

void UnkClass_02022404::sub_020228D4()
{
    unk_30->sub_02025624();
}

void UnkClass_02022404::sub_020228E4()
{
    unk_34->Render();
}

void UnkClass_02022404::sub_020228F4()
{
    unk_40->Render();
}

void UnkClass_02022404::sub_02022904()
{
    unk_4C->sub_02027674();
}

void UnkClass_02022404::sub_02022914()
{
    unk_54->Render();
}

void UnkClass_02022404::sub_02022924()
{
    if (unk_18 != NULL) {
        unk_18->Hide();
    }
}

BOOL UnkClass_02022404::sub_0202293C(u32 mapId, int x, int y)
{
    unk_64 = FALSE;
    unk_2C = 0;
    unk_1C = mapId;
    unk_18->SetMap(mapId, x, y);
    if (unk_58) {
        return FALSE;
    }
    unk_44 = -1;
    unk_38 = -1;
    sub_02023180();
    if (MAIN_BSS_020B26A0.unk_8B70 == 0) {
        unk_30->sub_02024A2C();
        unk_30->sub_02024A60();
        sub_02023160();
        unk_00 = 2;
        unk_02 = 0;
        return FALSE;
    }
    unk_18->Show(unk_1C, x, y);
    unk_00 = 1;
    unk_02 = 0;
    MAIN_BSS_020B26A0.unk_8B70 = 1;
    return TRUE;
}

void UnkClass_02022404::sub_020229F4(int mapId, int x, int y)
{
    unk_64 = FALSE;
    if (unk_58) {
        return;
    }
    unk_02 = 1;
    if (x == -1000 && y == -1000 && mapId == -1000) {
        unk_20 = unk_1C;
        unk_24 = unk_18->unk_30;
        unk_28 = unk_18->unk_34;
    } else {
        unk_20 = mapId;
        unk_24 = x;
        unk_28 = y;
    }
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_02022EE8();
    }
    MAIN_BSS_020B26A0.unk_8B70 = 1;
    unk_38 = -1;
    unk_44 = -1;
}

void UnkClass_02022404::sub_02022A98(int x, int y)
{
    if (!unk_58) {
        unk_18->SetPos(x, y);
    }
}

BOOL UnkClass_02022404::sub_02022AB4()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_2C = 0;
    unk_02 = 2;
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_02022F50();
    }
    MAIN_BSS_020B26A0.unk_8B70 = 0;
    unk_38 = -1;
    unk_44 = -1;
    return TRUE;
}

BOOL UnkClass_02022404::sub_02022B20()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    if (unk_00 == 2 && unk_02 != 2) {
        sub_02022AB4();
    }
    return TRUE;
}

BOOL UnkClass_02022404::sub_02022B60(u32 id, int arg2)
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_2C = 0;
    if (id != unk_38) {
        unk_02 = 4;
        unk_38 = id;
        unk_3C = arg2;
        sub_02022ED0();
        sub_02022FA8();
        unk_44 = -1;
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_02022404::sub_02022BC0(u32 id)
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_2C = 0;
    if (id != unk_44) {
        unk_02 = 6;
        unk_44 = id;
        sub_02022ED0();
        sub_02023014();
        unk_38 = -1;
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_02022404::sub_02022C1C()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_38 = -1;
    unk_44 = -1;
    unk_02 = 9;
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_02023078();
    }
    return TRUE;
}

BOOL UnkClass_02022404::sub_02022C74()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    sub_02023180();
    unk_38 = -1;
    unk_44 = -1;
    sub_02023180();
    unk_4C->sub_020256A4();
    unk_48 = 0;
    while (unk_48 != -1) {
        unk_48 = unk_4C->sub_020257F4(unk_48);
    }
    unk_4C->sub_020276A0();
    unk_00 = 8;
    sub_02023160();
    return TRUE;
}

BOOL UnkClass_02022404::sub_02022D04()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    if (unk_68->unk_15D4 == 0) {
        return FALSE;
    }
    if (unk_00 == 8 || unk_02 == 9 || unk_00 == 9) {
        return FALSE;
    }
    sub_02023180();
    unk_00 = 7;
    GXS_SetVisiblePlane(GX_PLANEMASK_BG3);
    sub_02007D68();
    return TRUE;
}

void UnkClass_02022404::sub_02022D88()
{
    unk_64 = FALSE;
    if (unk_58) {
        return;
    }
    if (MAIN_BSS_020B26A0.unk_8B70 != 0) {
        sub_02022AB4();
    } else {
        sub_020229F4(unk_1C, unk_18->unk_30, unk_18->unk_34);
    }
}

void UnkClass_02022404::sub_02022DD4()
{
    unk_64 = FALSE;
    if (unk_02 == 9) {
        return;
    }
    if (unk_58) {
        return;
    }
    if (MAIN_BSS_020B26A0.unk_8B70 != 0) {
        if (unk_00 != 1 && unk_02 != 1) {
            sub_020229F4(unk_1C, unk_18->unk_30, unk_18->unk_34);
        }
    } else {
        if (unk_00 != 2 && unk_02 != 2) {
            sub_02022AB4();
        }
    }
}

void UnkClass_02022404::sub_02022E48(int picId)
{
    unk_64 = FALSE;
    unk_30->sub_02024A2C();
    unk_34->Release();
    unk_40->Release();
    unk_4C->sub_020256A4();
    unk_54->Init();
    unk_58 = TRUE;
    unk_50 = picId;
    unk_02 = 10;
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_020230D4();
    }
    unk_64 = FALSE;
}

void UnkClass_02022404::sub_02022EC4()
{
    unk_58 = FALSE;
}

BOOL UnkClass_02022404::sub_02022ED0()
{
    unk_04 = TRUE;
    return sub_02023298(10);
}

BOOL UnkClass_02022404::sub_02022EE8()
{
    unk_30->sub_02024A2C();
    unk_34->Release();
    unk_40->Release();
    unk_4C->sub_020256A4();
    unk_54->Init();
    sub_02023180();
    sub_02023134();
    unk_2C = 0;
    unk_1C = unk_20;
    unk_18->Show(unk_1C, unk_24, unk_28);
    return TRUE;
}

BOOL UnkClass_02022404::sub_02022F50()
{
    unk_34->Release();
    unk_40->Release();
    unk_4C->sub_020256A4();
    unk_54->Init();
    sub_02023180();
    unk_2C = 0;
    unk_30->sub_02024A2C();
    unk_30->sub_02024A60();
    sub_02023134();
    return TRUE;
}

void UnkClass_02022404::sub_02022FA8()
{
    unk_30->sub_02024A2C();
    unk_40->Release();
    unk_4C->sub_020256A4();
    unk_54->Init();
    sub_02023180();
    unk_2C = 0;
    unk_34->Release();
    unk_34->ResetLoad();
}

int UnkClass_02022404::sub_02022FF4()
{
    return unk_34->LoadStep(unk_38, unk_3C, 0);
}

void UnkClass_02022404::sub_02023014()
{
    unk_30->sub_02024A2C();
    unk_40->Release();
    unk_4C->sub_020256A4();
    unk_54->Init();
    sub_02023180();
    unk_2C = 0;
    unk_40->Release();
    unk_40->ResetLoad();
}

int UnkClass_02022404::sub_02023060()
{
    return unk_40->Load(unk_44);
}

BOOL UnkClass_02022404::sub_02023078()
{
    unk_30->sub_02024A2C();
    unk_34->Release();
    unk_40->Release();
    unk_54->Init();
    sub_02023180();
    unk_4C->sub_020256A4();
    sub_02023160();
    unk_00 = unk_02;
    unk_02 = 0;
    unk_48 = 0;
    return TRUE;
}

BOOL UnkClass_02022404::sub_020230D4()
{
    unk_30->sub_02024A2C();
    unk_34->Release();
    unk_40->Release();
    unk_4C->sub_020256A4();
    unk_2C = 0;
    unk_54->Init();
    unk_54->Load(unk_50);
    sub_02023134();
    sub_02023230(30);
    return TRUE;
}

void UnkClass_02022404::sub_02023134()
{
    sub_02023160();
    unk_00 = unk_02;
    unk_02 = 0;
    sub_02023230(10);
}

void UnkClass_02022404::sub_02023160()
{
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
}

void UnkClass_02022404::sub_02023180()
{
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
}

void UnkClass_02022404::sub_02023198(int arg1)
{
    unk_5C = arg1;
}

void UnkClass_02022404::sub_020231A0()
{
    if (unk_5C) {
        unk_2C += 60 / unk_68->unk_146C.sub_02008E50();
        if (unk_2C >= 300) {
            sub_02022DD4();
            unk_64 = TRUE;
            unk_2C = 0;
        }
    }
}

void UnkClass_02022404::sub_02023200()
{
    if (unk_18 != NULL) {
        unk_18->ClearIcons();
    }
}

void UnkClass_02022404::sub_02023218(int x, int y, int kind)
{
    if (unk_18 != NULL) {
        unk_18->AddIcon(x, y, kind);
    }
}

void UnkClass_02022404::sub_02023230(u16 duration)
{
    if (unk_68 == NULL) {
        return;
    }
    if (unk_60) {
        return;
    }
    if (unk_68->unk_14C0->sub_0200E324() == 2) {
        unk_68->unk_14C0->sub_0200E0E0(1, duration);
    } else {
        unk_68->unk_14C0->sub_0200E0E0(3, duration);
    }
}

BOOL UnkClass_02022404::sub_02023298(u16 duration)
{
    if (unk_68 == NULL) {
        return FALSE;
    }
    unk_60 = 0;
    if (unk_68->unk_14C0->sub_0200E324() == 4 || unk_68->unk_14C0->sub_0200E324() == 2) {
        return unk_68->unk_14C0->sub_0200E310();
    }
    unk_68->unk_14C0->sub_0200E0E0(4, duration);
    return TRUE;
}

BOOL UnkClass_02022404::sub_0202331C()
{
    if (unk_64) {
        if (unk_68->unk_14C0->sub_0200E310() || unk_68->unk_14BC->sub_0200E310() || unk_68->unk_14C4->func0()) {
            return TRUE;
        }
        unk_64 = FALSE;
        return FALSE;
    }
    return unk_68->unk_14C0->sub_0200E310();
}

UnkClass_02022404 *UnkClass_02022404::GetInstance()
{
    return sInstance;
}

BOOL UnkClass_02022404::sub_020233B4()
{
    return unk_00 == 8;
}
