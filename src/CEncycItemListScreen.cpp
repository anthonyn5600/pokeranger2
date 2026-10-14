#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "OamSpriteSet.hpp"
#include "SaveData.hpp"
#include "SubTextPrinter.hpp"
#include "scene/CEncyclopediaScene.hpp"

static inline u32 GetCaptureState(SaveData *save, int group, int i)
{
    if (group >= 0 && group < 3 && i >= 0 && i < 64) {
        return (save->m_encyclopediaStates[group][i / 16] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline u32 SetCaptureState(SaveData *save, int group, int i, u32 state)
{
    if (group >= 0 && group < 3 && i >= 0 && i < 64) {
        int shift = (i & 0xF) * 2;
        save->m_encyclopediaStates[group][i / 16] &= ~(3 << shift);
        save->m_encyclopediaStates[group][i / 16] |= (state & 3) << shift;
        return state;
    }
    return 0;
}

CEncycItemListScreen::CEncycItemListScreen(EncycPushButton *backButton)
    : unk_14(-1)
    , unk_18(0)
    , unk_1C(NULL)
    , unk_24(0, 3)
    , unk_34(3)
    , unk_124(backButton)
    , unk_160(NULL)
{
    for (int i = 0; i < 3; i++) {
        unk_164[i] = 0;
    }
}

void CEncycItemListScreen::func0(EncycAnimLoader *loader)
{
    unk_128.ov22_02120A24("/data/message/etc/dictionary02_mes");
    unk_134.ov22_02120BB4("/data/encyclo/encyclopedia.bin");
    int total;
    SaveData *save = CGame::GetInstance()->unk_14A4;
    if (save != NULL) {
        int counts[3];
        total = 0;
        for (int group = 0; group < 3; group++) {
            counts[group] = 0;
            int count = unk_134.ov22_02120F14(group);
            for (int i = 0; i < count; i++) {
                u32 state = GetCaptureState(save, group, i);
                UnkStruct_02120F34 *entry = unk_134.ov22_02120F34(group, i);
                if (entry != NULL) {
                    entry->unk_1C = state;
                }
                if (state != 0) {
                    counts[group]++;
                }
            }
            total += counts[group];
        }
        if (total > 0) {
            ov22_0211D918(total);
        }
    }

    BGS_LoadCharAndPltt("menu/", "md000_bg_", 5, "md000", 0, "md000", 0);
    MI_CpuCopy8((void *)(HW_DB_BG_PLTT), unk_170, sizeof(unk_170));
    BGS_LoadScr("menu/", "md000_bg_", 5, "md000_02", 0, 0, 0, 0);
    BGS_LoadScr("menu/", "md000_bg_", 6, "md000_01", 0, 0, 0, 0);
    BGS_LoadScr("menu/", "md000_bg_", 7, "md000_03", 0, 0, 0, 0);
    unk_20 = loader->ov22_0211F3F0("data/menu", "md000_00", 4, -1);

    int labels[3] = { 1, 2, 3 };
    for (int i = 0; i < 3; i++) {
        unk_24.ov22_021206DC(i, unk_20, i + 13, i + 10, 45 + i * 67, 28, 67, 32, 3, unk_128.ov22_02120AE0(labels[i]));
        unk_24.ov22_021207E8(i, unk_20, 8, 22 + i * 68, 13, 1);
    }
    unk_24.SetListener(this);
    unk_34.ov22_0211FAD4(0, unk_20, 9, 8, 8, 48, 208, 128, 8, 13, 0);
    unk_34.SetListener(this);
    unk_A4[0].ov22_0211F134(0, unk_20, 0, 1, 232, 51, 24, 24, 1);
    unk_A4[0].SetListener(this);
    unk_A4[1].ov22_0211F134(1, unk_20, 2, 3, 232, 173, 24, 24, 1);
    unk_A4[1].SetListener(this);
    unk_A4[2].ov22_0211F134(2, unk_20, 4, 5, 232, 92, 16, 16, 1);
    unk_A4[2].SetListener(this);
    unk_A4[3].ov22_0211F134(3, unk_20, 6, 7, 232, 132, 16, 16, 1);
    unk_A4[3].SetListener(this);
    unk_20->Update();
    for (int i = 0; i < 3; i++) {
        unk_24.ov22_0212086C(i, unk_164[i] > 0 ? TRUE : FALSE);
    }
    unk_34.ov22_0211FBE4();
}

void CEncycItemListScreen::ov22_0211D918(int count)
{
    unk_160 = new UnkStruct_0211D918[count];
    if (unk_160 == NULL) {
        return;
    }
    int n = 0;
    for (int group = 0; group < 3; group++) {
        int groupCount = unk_134.ov22_02120F14(group);
        int start = n;
        unk_164[group] = 0;
        for (int i = 0; i < groupCount; i++) {
            UnkStruct_02120F34 *entry = unk_134.ov22_02120F34(group, i);
            if (entry != NULL && entry->unk_1C != 0) {
                unk_160[n].unk_00 = entry->unk_00;
                unk_160[n].unk_08 = entry;
                if (entry->unk_1C == 1) {
                    unk_160[n].unk_04 = 1;
                    unk_164[group]++;
                } else {
                    unk_160[n].unk_04 = 0;
                }
                n++;
            }
        }
        unk_34.ov22_0211FC24(group, &unk_160[start], n - start);
    }
}

void CEncycItemListScreen::func1()
{
    SAFE_DELETE(unk_20);
    SAFE_DELETE_ARRAY(unk_160);
    unk_134.ov22_02120E80();
    unk_128.ov22_02120B04();
}

void CEncycItemListScreen::func2()
{
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x04000, GX_BG_EXTPLTT_01);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x04000);
    G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x2000, GX_BG_CHARBASE_0x04000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(3);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(1);
    GXS_SetVisibleWnd(GX_WNDMASK_W0);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
}

void CEncycItemListScreen::func3(EncycMainScreen *display)
{
    int charNo;
    int i;
    SubTextPrinter *text = CGame::GetInstance()->unk_1498;
    text->FreeWindows();
    text->AllocWindows(16);
    for (charNo = 0, i = 0; i < 16; charNo += 64, i++) {
        text->InitWindow(i, 32, 2, 0, i * 2, charNo, 0, 2);
    }
    display->ov22_0211F8A8();
    display->ov22_0211F7B8("data/menu/rd000_LZ.bin", "rd000.nbfs");
    unk_04 = 0;
    unk_24.ov22_021208DC(unk_18);
    unk_14 = -1;
    unk_124->ov22_0211F3C8();
}

int CEncycItemListScreen::func4()
{
    CGame *game = CGame::GetInstance();
    int ret = 0;
    switch (unk_04) {
    case 0:
        if (!game->unk_14BC->IsActive()) {
            if (!game->unk_14C0->IsActive()) {
                unk_04 = 1;
            }
        }
        break;
    case 1:
        unk_24.ov22_0212098C();
        unk_124->ov22_0211F1D0();
        unk_124->ov22_0211F2A4();
        for (int i = 0; i <= 3; i++) {
            unk_A4[i].ov22_0211F1D0();
        }
        if ((u16)(game->unk_0014->unk_0006 & PAD_BUTTON_L)) {
            int group = unk_18 - 1;
            if (group < 0) {
                group = 2;
            }
            unk_24.ov22_021208DC(group);
        } else if ((u16)(game->unk_0014->unk_0006 & PAD_BUTTON_R)) {
            int group = unk_18 + 1;
            if (group > 2) {
                group = 0;
            }
            unk_24.ov22_021208DC(group);
        }
        unk_A4[2].unk_14 = game->unk_0014->unk_0000 & PAD_KEY_UP;
        unk_A4[3].unk_14 = (u16)(game->unk_0014->unk_0000 & PAD_KEY_DOWN);
        unk_A4[0].unk_14 = game->unk_0014->unk_0000 & PAD_KEY_LEFT;
        unk_A4[1].unk_14 = game->unk_0014->unk_0000 & PAD_KEY_RIGHT;
        unk_20->Update();
        unk_34.ov22_0212005C();
        if ((u16)(game->unk_0014->unk_0002 & PAD_BUTTON_B)) {
            func6();
        }
        break;
    case 2:
        if (!game->unk_14BC->IsActive() && !game->unk_14C0->IsActive()) {
            ret = unk_14;
        }
        break;
    }
    for (int i = 0; i <= 3; i++) {
        unk_A4[i].ov22_0211F2A4();
    }
    unk_34.ov22_021201B0();
    return ret;
}

void CEncycItemListScreen::func5()
{
    if (unk_20 != NULL) {
        unk_20->WriteOam();
    }
}

void CEncycItemListScreen::func7()
{
    unk_34.ov22_0212058C();
}

void CEncycItemListScreen::func6()
{
    CGame *game = CGame::GetInstance();
    unk_04 = 2;
    unk_14 = -1;
    game->m_audioEngine->PlaySe(0x103);
    game->unk_14BC->Start(4, 15);
    game->unk_14C0->Start(4, 15);
}

void CEncycItemListScreen::ov22_0211DE40(int group)
{
    unk_18 = group;
    unk_34.ov22_02120414(unk_18);
    unk_34.ov22_0211FF20();
    if (unk_04 != 0) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0xFA);
    }
    NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_BG_PLTT_SUB, 0, unk_170[unk_18], 0x20);
}

UnkStruct_02120F34 *CEncycItemListScreen::ov22_0211DE9C()
{
    return unk_1C;
}

void CEncycItemListScreen::OnPushButton(int id)
{
    switch (id) {
    case 0:
        unk_34.ov22_0211FEA8();
        break;
    case 1:
        unk_34.ov22_0211FE18();
        break;
    case 2:
        unk_34.ov22_0211FD74();
        break;
    case 3:
        unk_34.ov22_0211FC58();
        break;
    }
}

void CEncycItemListScreen::OnListBoxEvent0(int id, int idx)
{
    CGame *game = CGame::GetInstance();
    int base = 0;
    for (int i = 0; i < unk_18; i++) {
        base += unk_34.ov22_02120560(i);
    }
    int line = base + idx;
    unk_1C = unk_160[line].unk_08;
    int group = unk_18;
    int no = unk_1C->unk_04;
    SaveData *save = game->unk_14A4;
    u32 state = GetCaptureState(save, group, no);
    if (state == 1) {
        state = SetCaptureState(save, group, no, 2);
    }
    unk_1C->unk_1C = state;
    if (unk_160[line].unk_04 & 1) {
        unk_164[unk_18]--;
        if (unk_164[unk_18] == 0) {
            unk_24.ov22_0212086C(unk_18, FALSE);
        }
        unk_160[line].unk_04 &= ~1;
    }
    unk_14 = 1;
    unk_04 = 2;
    game->m_audioEngine->PlaySe(0xFA);
    game->unk_14BC->Start(4, 15);
    game->unk_14C0->Start(4, 15);
}

void CEncycItemListScreen::OnListBoxEvent1(int id, int cursor, u32 flags, int arg3)
{
    unk_A4[0].ov22_0211F344(flags & 2 ? TRUE : FALSE);
    unk_A4[2].ov22_0211F344(flags & 8 ? TRUE : FALSE);
    unk_A4[1].ov22_0211F344(flags & 1 ? TRUE : FALSE);
    unk_A4[3].ov22_0211F344(flags & 4 ? TRUE : FALSE);
}

void CEncycItemListScreen::OnRadioButton(int groupId, int idx)
{
    if (idx < 0 || idx >= 3) {
        return;
    }
    ov22_0211DE40(idx);
}
