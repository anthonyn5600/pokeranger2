#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Camera2D.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SubTextPrinter.hpp"
#include "file/CBinaryFileMes.hpp"
#include "file/CNCLRFile.hpp"
#include "scene/CEncyclopediaScene.hpp"

int ov22_021214CC(NNSG2dFont *font, int hSpace, u8 **str);

EncycListBoxGroup::EncycListBoxGroup()
{
    unk_00 = 0;
    unk_04 = NULL;
    unk_08 = 0;
    unk_0C = 0;
}

CEncycListBox::CEncycListBox(int count)
{
    unk_04 = -1;
    unk_08 = 0;
    unk_0C = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = 0;
    unk_2C = 0;
    unk_30 = 0;
    unk_34 = 0;
    unk_38 = NULL;
    unk_3C = NULL;
    unk_40 = 0;
    unk_6C = NULL;
    MI_CpuClear8(unk_44, sizeof(unk_44));
    unk_68 = count;
    unk_6C = unk_68 <= 0 ? NULL : new EncycListBoxGroup[unk_68];
}

CEncycListBox::~CEncycListBox()
{
    SAFE_DELETE_ARRAY(unk_6C);
}

BOOL CEncycListBox::ov22_0211FAD4(int arg0, OamSpriteSet *anims, int arg2, int arg3, int arg4, int arg5, u32 arg6, int arg7, int arg8, int arg9, int argA)
{
    unk_04 = arg0;
    unk_10 = arg6;
    unk_14 = arg7;
    unk_08 = arg4;
    unk_0C = arg5;
    unk_28 = arg8 + (unk_08 + unk_10 / 2);
    int y = unk_0C + 8;
    unk_3C = anims->AddSprite(arg2, unk_28, y, 0);
    unk_24 = unk_08 + arg9;
    for (int i = 0; i < 8; i++) {
        unk_44[i] = anims->AddSprite(arg3, unk_24, y + i * 16, 1);
    }
    unk_30 = y;
    unk_2C = y;
    G2S_SetBG0Offset(0, unk_34);
    G2S_SetBG3Offset(0, unk_34);
    if (unk_3C != NULL) {
        return TRUE;
    }
    return FALSE;
}

void CEncycListBox::ov22_0211FBE4()
{
    if (unk_3C == NULL) {
        return;
    }
    BOOL show = FALSE;
    if (unk_6C != NULL && unk_6C[unk_18].unk_00 > 0) {
        show = TRUE;
    }
    unk_3C->SetVisible(show);
}

void CEncycListBox::ov22_0211FC24(int group, UnkStruct_0211D918 *lines, int count)
{
    if (group < 0) {
        return;
    }
    if (group >= unk_68) {
        return;
    }
    if (unk_6C == NULL) {
        return;
    }
    unk_6C[group].unk_00 = count;
    unk_6C[group].unk_04 = lines;
}

void CEncycListBox::ov22_0211FC58()
{
    EncycListBoxGroup *g = &unk_6C[unk_18];
    if (g->unk_00 == 0) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
        return;
    }
    if (unk_2C != unk_30) {
        return;
    }
    int bottom = unk_0C + unk_14 - 8;
    if (unk_2C < bottom) {
        if (unk_2C == unk_30) {
            unk_30 = unk_2C + 16;
        } else {
            unk_30 = unk_30 + 16;
        }
        if (unk_30 > bottom) {
            unk_30 = bottom;
        }
        if (unk_1C + ((unk_30 - unk_0C - 8) >> 4) >= g->unk_00) {
            unk_30 = unk_2C;
        }
    } else {
        unk_20 = unk_1C + 1;
        if (unk_20 >= g->unk_00) {
            unk_20 = g->unk_00 - 1;
        } else if (unk_20 + 8 > g->unk_00) {
            unk_20 = g->unk_00 - 8;
        }
    }
    if (unk_20 != unk_1C || unk_30 != unk_2C) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0x108);
        return;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
}

void CEncycListBox::ov22_0211FD74()
{
    if (unk_2C != unk_30) {
        return;
    }
    int top = unk_0C + 8;
    if (unk_2C > top) {
        if (unk_30 == unk_2C) {
            unk_30 = unk_2C - 16;
        } else {
            unk_30 = unk_30 - 16;
        }
        if (unk_30 < top) {
            unk_30 = top;
        }
    } else {
        unk_20 = unk_1C - 1;
        if (unk_20 < 0) {
            unk_20 = 0;
        }
    }
    if (unk_20 != unk_1C || unk_30 != unk_2C) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0x108);
        return;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
}

void CEncycListBox::ov22_0211FE18()
{
    int top = unk_20 == unk_1C ? unk_1C + 8 : unk_20 + 8;
    int max = unk_6C[unk_18].unk_00 - 8;
    if (top > max) {
        top = max;
    }
    if (top < 0) {
        top = 0;
    }
    if (top != unk_1C) {
        unk_1C = unk_20 = top;
        ov22_021205B8(1);
        ov22_0211FF20();
        CGame::GetInstance()->m_audioEngine->PlaySe(0x108);
        return;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
}

void CEncycListBox::ov22_0211FEA8()
{
    int top = unk_20 == unk_1C ? unk_1C - 8 : unk_20 - 8;
    if (top < 0) {
        top = 0;
    }
    if (top != unk_1C) {
        unk_1C = unk_20 = top;
        ov22_021205B8(1);
        ov22_0211FF20();
        CGame::GetInstance()->m_audioEngine->PlaySe(0x108);
        return;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
}

void CEncycListBox::ov22_0211FF20()
{
    SubTextPrinter *text = CGame::GetInstance()->unk_1498;
    if (unk_6C == NULL) {
        return;
    }
    for (int i = 0; i < 16; i++) {
        text->ClearWindow(i);
    }
    for (int i = 0; i < 16; i++) {
        ov22_021204D8(unk_1C + i - 3);
    }
    unk_34 = (256 - (unk_0C - (unk_1C & 0xF) * 16)) & 0xFF;
    G2S_SetBG0Offset(0, unk_34);
    G2S_SetBG3Offset(0, unk_34);
    EncycListBoxGroup *group = &unk_6C[unk_18];
    for (int i = 0; i < 9; i++) {
        if (unk_44[i] != NULL) {
            unk_44[i]->SetPos(unk_24, unk_0C + 8 + i * 16);
            int line = unk_1C + i;
            if (line < group->unk_00 && (group->unk_04[line].unk_04 & 1)) {
                unk_44[i]->unk_14 = TRUE;
            } else {
                unk_44[i]->unk_14 = FALSE;
            }
        }
    }
}

void CEncycListBox::ov22_0212005C()
{
    s32 group;
    EncycListBoxGroup *groups = unk_6C;
    group = unk_18;
    if (groups[group].unk_00 == 0) {
        return;
    }
    CGame *game = CGame::GetInstance();
    int top = unk_1C;
    if (top == unk_20 && unk_2C == unk_30) {
        CTouchPanel *tp = game->touchPanel;
        int sel = -1;
        if (tp->unk_04 != 0) {
            u16 x = tp->unk_0A.x;
            u16 y = tp->unk_0A.y;
            if (unk_08 <= x && x < unk_08 + unk_10 && unk_0C <= y && y < unk_0C + unk_14) {
                int ofs = (y - unk_0C) & ~0xF;
                if (top + (ofs >> 4) < groups[group].unk_00) {
                    unk_2C = unk_30 = unk_0C + 8 + ofs;
                    unk_3C->SetPos(unk_28, unk_2C);
                    sel = unk_1C + ((unk_2C - (unk_0C + 8)) >> 4);
                    game->m_audioEngine->PlaySe(0xFA);
                    ov22_021205B8(1);
                }
            }
        } else if ((u16)(game->unk_0014->unk_0002 & PAD_BUTTON_A)) {
            sel = top + ((unk_2C - (unk_0C + 8)) >> 4);
        }
        if (sel < 0) {
            return;
        }
        if (unk_38 == NULL) {
            return;
        }
        unk_38->OnListBoxEvent0(unk_04, sel);
    }
}

static inline void SetBlink(OamSprite *sprite, u8 timer)
{
    sprite->SetVisible(timer < 6 ? TRUE : FALSE);
}

void CEncycListBox::ov22_021201B0()
{
    if (unk_6C[unk_18].unk_00 == 0) {
        return;
    }
    CGame::GetInstance();
    if (unk_30 != unk_2C) {
        if (unk_30 < unk_2C) {
            unk_2C -= 2;
            if (unk_2C <= unk_30) {
                unk_2C = unk_30;
            }
        } else {
            unk_2C += 2;
            if (unk_2C >= unk_30) {
                unk_2C = unk_30;
            }
        }
        unk_3C->SetPos(unk_28, unk_2C);
        if (unk_30 == unk_2C) {
            ov22_021205B8(1);
        }
        unk_40 = 0;
    }
    if (unk_20 != unk_1C) {
        BOOL down = unk_20 > unk_1C ? TRUE : FALSE;
        if (down) {
            unk_34 += 2;
            unk_34 &= 0xFF;
            if (!(unk_34 & 0xF)) {
                unk_1C++;
                ov22_021205B8(1);
                ov22_021204D8(unk_1C + 12);
            }
        } else {
            unk_34 -= 2;
            unk_34 &= 0xFF;
            if (!(unk_34 & 0xF)) {
                unk_1C--;
                ov22_021205B8(1);
                ov22_021204D8(unk_1C - 3);
            }
        }
        ov22_02120348(down);
        unk_40 = 0;
    }
    if (unk_3C == NULL) {
        return;
    }
    if (++unk_40 >= 12) {
        unk_40 = 0;
    }
    SetBlink(unk_3C, unk_40);
}

void CEncycListBox::ov22_02120348(BOOL down)
{
    EncycListBoxGroup *group;
    int i;
    int line;
    int dy = unk_34 & 0xF;
    if (dy < 8) {
        dy = -dy;
        line = down ? unk_1C : unk_20;
    } else {
        dy = 16 - dy;
        line = down ? unk_20 : unk_1C;
    }
    group = &unk_6C[unk_18];
    for (i = 0; i < 8; i++) {
        if (unk_44[i] != NULL) {
            unk_44[i]->SetPos(unk_24, dy + (unk_0C + 8 + i * 16));
            if (group->unk_04[line + i].unk_04 & 1) {
                unk_44[i]->unk_14 = TRUE;
            } else {
                unk_44[i]->unk_14 = FALSE;
            }
        }
    }
}

static inline void SetSpriteVisible(OamSprite *sprite, int count)
{
    sprite->SetVisible(count != 0 ? TRUE : FALSE);
}

void CEncycListBox::ov22_02120414(int group)
{
    if (unk_18 != group) {
        EncycListBoxGroup *prev = &unk_6C[unk_18];
        prev->unk_08 = unk_1C;
        prev->unk_0C = unk_1C + ((unk_2C - 8 - unk_0C) >> 4);
        unk_18 = group;
        int idx;
        prev = unk_6C;
        idx = unk_18;
        EncycListBoxGroup *next = &prev[idx];
        unk_1C = unk_20 = next->unk_08;
        unk_2C = unk_30 = unk_0C + (next->unk_0C - next->unk_08) * 16 + 8;
        ov22_0211FF20();
        unk_3C->SetPos(unk_28, unk_2C);
        SetSpriteVisible(unk_3C, prev[idx].unk_00);
    }
    ov22_021205B8(1);
}

void CEncycListBox::ov22_021204D8(int line)
{
    EncycListBoxGroup *group = &unk_6C[unk_18];
    if (line < 0) {
        return;
    }
    if (line >= group->unk_00) {
        return;
    }
    int row = line & 0xF;
    SubTextPrinter *text = CGame::GetInstance()->unk_1498;
    text->ClearWindow(row);
    text->Print(row, 32, 3, 3, group->unk_04[line].unk_00, FALSE, 0);
}

int CEncycListBox::ov22_02120560(int group)
{
    if (group >= 0 && group < unk_68 && unk_6C != NULL) {
        return unk_6C[group].unk_00;
    }
    return 0;
}

void CEncycListBox::ov22_0212058C()
{
    G2S_SetBG0Offset(0, unk_34);
    G2S_SetBG3Offset(0, unk_34);
}

void CEncycListBox::ov22_021205B8(int arg0)
{
    if (unk_38 == NULL) {
        return;
    }
    int cursor = -1;
    int count = unk_6C[unk_18].unk_00;
    if (count > 0) {
        cursor = unk_1C + ((unk_2C - (unk_0C + 8)) >> 4);
    }
    u32 flags = 0;
    if (unk_1C + 8 < count) {
        flags |= 1;
    }
    if (unk_1C > 0) {
        flags |= 2;
    }
    if (cursor > 0) {
        flags |= 8;
    }
    if (cursor < count - 1) {
        flags |= 4;
    }
    unk_38->OnListBoxEvent1(unk_04, cursor, flags, arg0);
}

EncycRadioButton::EncycRadioButton()
{
    unk_00 = -1;
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = NULL;
    unk_10 = NULL;
    unk_14 = 0;
}

EncycRadioButtonGroup::EncycRadioButtonGroup(int arg0, int count)
{
    unk_00 = arg0;
    unk_04 = count;
    if (count > 0) {
        unk_08 = new EncycRadioButton[count];
    } else {
        unk_08 = NULL;
    }
}

EncycRadioButtonGroup::~EncycRadioButtonGroup()
{
    SAFE_DELETE_ARRAY(unk_08);
}

void EncycRadioButtonGroup::ov22_021206DC(int idx, OamSpriteSet *anims, int animOn, int animOff, int x, int y, int w, int h, int arg8, const char *label)
{
    if (unk_08 == NULL) {
        return;
    }
    for (int i = 0; i < unk_04; i++) {
        if (unk_08[i].unk_00 < 0) {
            unk_08[i].unk_00 = idx;
            unk_08[i].unk_10 = label;
            unk_08[i].unk_04 = anims->AddSprite(animOn, x, y, arg8);
            unk_08[i].unk_08 = anims->AddSprite(animOff, x, y, arg8);
            if (unk_08[i].unk_04 == NULL) {
                return;
            }
            unk_08[i].unk_04->SetTouchRect(w, h, 0, 0);
            return;
        }
    }
}

void EncycRadioButtonGroup::ov22_021207E8(int idx, OamSpriteSet *anims, int anim, int x, int y, int arg5)
{
    for (int i = 0; i < unk_04; i++) {
        if (unk_08[i].unk_00 >= 0 && idx == unk_08[i].unk_00) {
            unk_08[i].unk_0C = anims->AddSprite(anim, x, y, arg5);
            return;
        }
    }
}

void EncycRadioButtonGroup::ov22_0212086C(int idx, BOOL flag)
{
    for (int i = 0; i < unk_04; i++) {
        if (unk_08[i].unk_00 >= 0 && idx == unk_08[i].unk_00) {
            unk_08[i].unk_0C->SetVisible(flag);
            return;
        }
    }
}

void EncycRadioButtonGroup::ov22_021208DC(int idx)
{
    for (int i = 0; i < unk_04; i++) {
        if (unk_08[i].unk_00 >= 0) {
            if (idx == unk_08[i].unk_00) {
                unk_08[i].unk_04->unk_14 = TRUE;
                unk_08[i].unk_08->unk_14 = FALSE;
            } else {
                unk_08[i].unk_04->unk_14 = FALSE;
                unk_08[i].unk_08->unk_14 = TRUE;
            }
        }
    }
    if (unk_0C == NULL) {
        return;
    }
    unk_0C->OnRadioButton(unk_00, idx);
}

void EncycRadioButtonGroup::ov22_0212098C()
{
    for (int i = 0; i < unk_04; i++) {
        if (unk_08[i].unk_04 != NULL && unk_08[i].unk_04->GetTouchTrigger()) {
            ov22_021208DC(unk_08[i].unk_00);
            return;
        }
    }
}

EncycMessageStrings::EncycMessageStrings()
{
    unk_00 = NULL;
    unk_04 = 0;
    unk_08 = NULL;
}

EncycMessageStrings::~EncycMessageStrings()
{
    ov22_02120B04();
}

int EncycMessageStrings::ov22_02120A24(const char *path)
{
    ov22_02120B04();
    if (path != NULL) {
        unk_00 = new CBinaryFileMes(path, 0);
        if (unk_00 != NULL) {
            s32 *data = (s32 *)unk_00->unk_4C;
            s32 *p = &data[2];
            unk_04 = data[1];
            if (unk_04 > 0) {
                unk_08 = new const char *[unk_04];
                if (unk_08 != NULL) {
                    for (int i = 0; i < unk_04; i++) {
                        int len = *p++;
                        unk_08[i] = (const char *)p;
                        p += len / 4;
                    }
                }
            }
        }
    }
    return 0;
}

int EncycMessageStrings::ov22_02120AD8()
{
    return unk_04;
}

const char *EncycMessageStrings::ov22_02120AE0(int idx)
{
    if (idx >= 0 && idx < unk_04) {
        return unk_08[idx];
    }
    return NULL;
}

void EncycMessageStrings::ov22_02120B04()
{
    SAFE_DELETE_ARRAY(unk_08);
    SAFE_DELETE(unk_00);
}

EncycEntries::EncycEntries()
    : unk_00(0)
    , unk_10(NULL)
    , unk_14(NULL)
    , unk_18(NULL)
    , unk_1C(NULL)
{
    for (int i = 0; i < 3; i++) {
        unk_04[i] = 0;
    }
}

EncycEntries::~EncycEntries()
{
    ov22_02120E80();
}

BOOL EncycEntries::ov22_02120BB4(const char *path)
{
    BOOL ret = FALSE;
    if (path != NULL) {
        unk_20.ov22_02120A24("/data/message/etc/dictionary_mes");
        CBinaryFile bin(path, 1, 0, CGame::GetInstance()->unk_14A8, NULL, 0);
        if (bin.unk_4C != NULL) {
            u16 *p = (u16 *)bin.unk_4C + 3;
            unk_00 = 0;
            for (int i = 0; i < 3; i++) {
                unk_04[i] = *p++;
                unk_00 += unk_04[i];
            }
            if (unk_00 > 0) {
                unk_10 = new UnkStruct_02120F34[unk_00];
                if (unk_10 != NULL) {
                    int n = *p++;
                    if (n > 0) {
                        int size = n * 2;
                        unk_14 = (u16 *)new u8[size];
                        if (unk_14 != NULL) {
                            MI_CpuCopy8(p, unk_14, size);
                        }
                        p += n;
                    }
                    n = *p++;
                    if (n > 0) {
                        u32 size = n * 8;
                        unk_18 = (UnkStruct_02120FA8 *)new u8[size];
                        if (unk_18 != NULL) {
                            MI_CpuCopy8(p, unk_18, size);
                        }
                        p += size / 2;
                    }
                    n = *p++;
                    if (n > 0) {
                        unk_1C = new s8[n];
                        if (unk_1C != NULL) {
                            MI_CpuCopy8(p, unk_1C, n);
                        }
                        p += (n + 1) / 2;
                    }
                    int markers = 0;
                    for (int i = 0; i < unk_00; i++) {
                        int first = p[0];
                        int pages = p[1];
                        UnkStruct_02120F34 *e = &unk_10[i];
                        e->unk_08 = first;
                        e->unk_0C = pages;
                        p += 2;
                        unk_10[i].unk_00 = (u8 *)unk_20.ov22_02120AE0(i + 1);
                        if (unk_14 != NULL) {
                            unk_10[i].unk_10 = unk_14 + first;
                        }
                        if (unk_18 != NULL) {
                            unk_10[i].unk_18 = unk_18 + markers;
                        }
                        if (unk_1C != NULL) {
                            unk_10[i].unk_14 = unk_1C + first;
                            for (int j = 0; j < pages; j++) {
                                int n = unk_1C[first + j];
                                if (n > 0) {
                                    markers += n;
                                }
                            }
                        }
                    }
                    int k = 0;
                    for (int g = 0; g < 3; g++) {
                        int no = 0;
                        for (int j = 0; j < unk_04[g]; j++) {
                            unk_10[k].unk_04 = no;
                            k++;
                            no++;
                        }
                    }
                    ret = TRUE;
                }
            }
        }
    }
    return ret;
}

void EncycEntries::ov22_02120E80()
{
    SAFE_DELETE_ARRAY(unk_1C);
    SAFE_DELETE_ARRAY(unk_18);
    SAFE_DELETE_ARRAY(unk_14);
    SAFE_DELETE_ARRAY(unk_10);
    unk_20.ov22_02120B04();
    for (int i = 0; i < 3; i++) {
        unk_04[i] = 0;
    }
    unk_00 = 0;
}

int EncycEntries::ov22_02120F14(int group)
{
    if (group >= 0 && group < 3) {
        return unk_04[group];
    }
    return 0;
}

UnkStruct_02120F34 *EncycEntries::ov22_02120F34(int group, int idx)
{
    if (unk_10 != NULL && group >= 0 && group < 3 && idx >= 0 && idx < unk_04[group]) {
        int base = 0;
        for (int i = 0; i < group; i++) {
            base += unk_04[i];
        }
        return &unk_10[base + idx];
    }
    return NULL;
}

UnkStruct_02120FA8 *UnkStruct_02120F34::ov22_02120FA8(int page, int idx)
{
    UnkStruct_02120FA8 *markers;
    if (unk_14 != NULL && (markers = unk_18) != NULL && page >= 0 && page < unk_0C) {
        for (int i = 0; i < page; i++) {
            int n = unk_14[i];
            if (n >= 0) {
                markers += n;
            }
        }
        int n = unk_14[page];
        if (n < 0) {
            markers += n;
            n = -n;
        }
        if (idx < n) {
            return &markers[idx];
        }
    }
    return NULL;
}

void EncycTextCanvas::ov22_02121024(NNSG2dFont *font, void *scr, void *chr, int charNo, int x, int y, int w, int h, int hSpace, int vSpace)
{
    NNS_G2dCharCanvasInitForBG(&unk_10, (u8 *)chr + (charNo << 5), w, h, NNS_G2D_CHARA_COLORMODE_16);
    NNS_G2dTextCanvasInit(&unk_00, &unk_10, font, hSpace, vSpace);
    NNS_G2dMapScrToCharText(scr, w, h, x, y, NNS_G2D_TEXT_BG_WIDTH_256, charNo, 14);
    ov22_021210B8();
}

void EncycTextCanvas::ov22_021210B8()
{
    CNCLRFile nclr("data/font/prs_lc_jp.NCLR", 1, 0, 0);
    DC_FlushRange(nclr.unk_B8->pRawData, 0x20);
    GX_LoadBGPltt(nclr.unk_B8->pRawData, 0x1C0, 0x20);
}

void EncycTextCanvas::ov22_02121110()
{
    NNS_G2dCharCanvasClear(&unk_10, 0);
}

void EncycTextRenderer::ov22_0212112C(EncycTextCanvas *canvas, int x, int y, int color, const char *label, int flags)
{
    int width;
    int lines;
    NNSG2dFont *font = (NNSG2dFont *)canvas->unk_00.pFont;
    int hSpace = canvas->unk_00.hSpace;
    int vSpace = canvas->unk_00.vSpace;
    u8 *pos = (u8 *)label;
    width = 0;
    lines = 1;
    if (pos != NULL) {
        do {
            int w = ov22_021214CC(font, hSpace, &pos);
            if (w > width) {
                width = w;
            }
            lines++;
        } while (pos != NULL);
    }
    int height = (lines - 1) * (vSpace + NNS_G2dFontGetLineFeed(font)) - vSpace;
    switch (flags & 0xC) {
    case 4:
        if (flags & 0x100) {
            x -= (width + 1) / 2;
        } else {
            x -= (width + 9) / 2;
        }
        break;
    case 8:
        x -= width;
        if (!(flags & 0x100)) {
            x -= 8;
        }
        break;
    }
    switch (flags & 0x30) {
    case 0x10:
        if (flags & 0x100) {
            y -= (height + 1) / 2;
        } else {
            y -= (height + 5) / 2;
        }
        break;
    case 0x20:
        y -= height;
        if (!(flags & 0x100)) {
            y -= 4;
        }
        break;
    }
    ov22_021212A4(x, y, width, height, flags);
    if (!(flags & 0x100)) {
        y += 2;
        x += 4;
    }
    ov22_02121304(canvas, label, x, y, color, width, flags);
}

void EncycTextRenderer::ov22_021212A4(int x, int y, int w, int h, int flags)
{
    fx32 top, left;
    if (flags & 0x100) {
        top = (y - 2) << FX32_SHIFT;
        left = (x - 4) << FX32_SHIFT;
    } else {
        top = y << FX32_SHIFT;
        left = x << FX32_SHIFT;
    }
    fx32 right = left + ((w + 8) << FX32_SHIFT);
    fx32 bottom = top + ((h + 4) << FX32_SHIFT);
    unk_00.SetVertexCoordinates(left, top, left, bottom, right, bottom, right, top, 0);
}

void EncycTextRenderer::ov22_02121304(EncycTextCanvas *canvas, const char *text, int x, int y, int color, int width, int flags)
{
    int py = y;
    NNSG2dFont *font = (NNSG2dFont *)canvas->unk_00.pFont;
    int hSpace = canvas->unk_00.hSpace;
    int linefeed = canvas->unk_00.vSpace + NNS_G2dFontGetLineFeed(font);
    u8 *pos = (u8 *)text;
    u8 *str;
    if (pos == NULL) {
        return;
    }
    do {
        int px = x;
        switch (flags & 3) {
        case 1:
            str = pos;
            px = x + ((width + 1) / 2 - (ov22_021214CC(font, hSpace, &str) + 1) / 2);
            break;
        case 2:
            str = pos;
            px = x + (width - ov22_021214CC(font, hSpace, &str));
            break;
        }
        ov22_021215C8(canvas, hSpace, px, py, color, &pos);
        py += linefeed;
    } while (pos != NULL);
}

void EncycTextRenderer::ov22_021213F0(Camera2D *camera)
{
    unk_00.m_z = unk_60 * 3 + 1;
    unk_00.m_alpha = 31;
    unk_00.m_color = 0x7FFF;
    unk_00.Render(camera);
    unk_00.m_z = unk_60 * 3 + 2;
    unk_00.m_alpha = 0;
    unk_00.m_color = 0;
    unk_00.Render(camera);
    G3_PushMtx();
    G3_Translate(1 << camera->unk_28, 2 << camera->unk_28, 0);
    unk_00.m_z = unk_60 * 3;
    unk_00.m_alpha = 16;
    unk_00.m_color = 0;
    unk_00.Render(camera);
    G3_PopMtx(1);
}

int ov22_021214CC(NNSG2dFont *font, int hSpace, u8 **str)
{
    if (str == NULL) {
        return 0;
    }
    BOOL end = FALSE;
    const void *pos = *str;
    int width = 0;
    u16 c;
    NNSiG2dSplitCharCallback getNextChar = font->cbCharSpliter;
    do {
        c = getNextChar(&pos);
        if (c != 0) {
            if (c == '\n') {
                end = TRUE;
            } else if (c == '[') {
                c = getNextChar(&pos);
                if (c == 'E') {
                    end = TRUE;
                }
                while (c != 0 && c != ']') {
                    c = getNextChar(&pos);
                }
                if (c == 0) {
                    end = TRUE;
                }
            } else {
                u16 idx = NNS_G2dFontFindGlyphIndex(font, c);
                if (idx == NNS_G2D_GLYPH_INDEX_NOT_FOUND) {
                    idx = font->pRes->alterCharIndex;
                }
                width += hSpace + NNS_G2dFontGetCharWidthsFromIndex(font, idx)->charWidth;
            }
        } else {
            end = TRUE;
        }
    } while (!end);
    *str = (c == 0 || c == '\n') ? NULL : (u8 *)pos;
    if (width > 0) {
        width -= hSpace;
    }
    return width;
}

void EncycTextRenderer::ov22_021215C8(EncycTextCanvas *canvas, int hSpace, int x, int y, int color, u8 **str)
{
    if (str == NULL) {
        return;
    }
    BOOL end = FALSE;
    const NNSG2dFont *font = canvas->unk_00.pFont;
    u16 c;
    NNSiG2dSplitCharCallback getNextChar = font->cbCharSpliter;
    const void *pos = *str;
    do {
        c = getNextChar(&pos);
        if (c != 0) {
            if (c == '\n') {
                end = TRUE;
            } else if (c == '[') {
                c = getNextChar(&pos);
                if (c == 'E') {
                    end = TRUE;
                }
                while (c != 0 && c != ']') {
                    c = getNextChar(&pos);
                }
                if (c == 0) {
                    end = TRUE;
                }
            } else {
                int w = NNS_G2dCharCanvasDrawChar(canvas->unk_00.pCanvas, font, x, y, color, c);
                x += w + hSpace;
            }
        } else {
            end = TRUE;
        }
    } while (!end);
    *str = (c == 0 || c == '\n') ? NULL : (u8 *)pos;
}
