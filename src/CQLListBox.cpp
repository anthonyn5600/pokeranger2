#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SubTextPrinter.hpp"
#include "file/CBinaryFileMes.hpp"
#include "scene/CQuestListScene.hpp"

static u8 sScroll[2];
static OSVAlarm sAlarmBG;
static OSVAlarm sAlarmSplit;
static OSVAlarm sAlarmTop;

static void OnTopAlarm(void *arg);
static void OnScrollAlarm(void *arg);
static void OnSplitAlarm(void *arg);

QLListBoxGroup::QLListBoxGroup()
{
    unk_00 = 0;
    unk_04 = NULL;
    unk_08 = 0;
    unk_0C = 0;
}

CQLListBox::CQLListBox(int count)
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
    unk_3C = NULL;
    unk_40 = NULL;
    unk_44 = 0;
    unk_90 = NULL;
    unk_194 = FALSE;
    MI_CpuClear8(unk_48, sizeof(unk_48) + sizeof(unk_68) + sizeof(unk_88));
    unk_8C = count;
    unk_90 = unk_8C <= 0 ? NULL : new QLListBoxGroup[unk_8C];
    OS_InitVAlarm();
    OS_CreateVAlarm(&sAlarmBG);
    OS_CreateVAlarm(&sAlarmSplit);
    OS_CreateVAlarm(&sAlarmTop);
}

CQLListBox::~CQLListBox()
{
    OS_CancelAllVAlarms();
    OS_EndVAlarm();
    SAFE_DELETE_ARRAY(unk_90);
}

BOOL CQLListBox::Init(int id, OamSpriteSet *anims, int animCursor, int animNormal, int animCleared, int animCurrent, int x, int y, int w, int h, int argA, int argB, int argC, void *rows)
{
    unk_04 = id;
    unk_10 = w;
    unk_14 = h;
    unk_08 = x;
    unk_0C = y;
    unk_28 = argA + (unk_08 + unk_10 / 2);
    int top = unk_0C + 8;
    unk_40 = anims->AddSprite(animCursor, unk_28, top, 0);
    unk_24 = unk_08 + argB;
    for (int i = 0; i < 7; i++) {
        unk_48[i] = anims->AddSprite(animNormal, unk_24, top + i * 16, 1);
        unk_68[i] = anims->AddSprite(animCleared, unk_24, top + i * 16, 0);
    }
    unk_88 = anims->AddSprite(animCurrent, unk_24, 0, 1);
    unk_2C = unk_30 = top;
    G2S_SetBG0Offset(0, unk_34);
    G2S_SetBG3Offset(0, unk_34);
    MI_CpuCopy8(rows, unk_94, sizeof(unk_94));
    MI_CpuCopy8((u8 *)rows + 0x80, unk_114, sizeof(unk_114));
    if (unk_40 != NULL) {
        return TRUE;
    }
    return FALSE;
}

void CQLListBox::Start()
{
    u8 *scr = (u8 *)G2S_GetBG3ScrPtr();
    for (int i = 0; i < 16; i++) {
        MI_CpuCopy8(unk_114, scr, sizeof(unk_114));
        scr += 0x80;
    }
    if (unk_40 != NULL) {
        BOOL show = FALSE;
        if (unk_90 != NULL && unk_90[unk_18].unk_00 > 0) {
            show = TRUE;
        }
        unk_40->SetVisible(show);
    }
    OS_SetPeriodicVAlarm(&sAlarmTop, 22, 2, OnTopAlarm, this);
    OS_SetPeriodicVAlarm(&sAlarmBG, 46, 2, OnScrollAlarm, this);
}

void CQLListBox::SetGroupLines(int group, QLListLine *lines, int count)
{
    if (group < 0) {
        return;
    }
    if (group >= unk_8C) {
        return;
    }
    if (unk_90 == NULL) {
        return;
    }
    unk_90[group].unk_00 = count;
    unk_90[group].unk_04 = lines;
}

int CQLListBox::GetCursor()
{
    int y = unk_2C != unk_30 ? unk_30 : unk_2C;
    int top = unk_1C != unk_20 ? unk_20 : unk_1C;
    return top + ((y - (unk_0C + 8)) >> 4);
}

void CQLListBox::SetCursor(int line)
{
    int count = unk_90[unk_18].unk_00;
    if (line >= count) {
        return;
    }
    int top = line;
    if (top > count - 7) {
        top = count - 7;
    }
    if (top < 0) {
        top = 0;
    }
    unk_2C = unk_30 = unk_0C + (line - top) * 16 + 8;
    unk_1C = unk_20 = top;
    NotifyCursor(FALSE);
    Refresh();
    unk_40->SetPos(unk_28, unk_2C);
}

void CQLListBox::CursorDown()
{
    QLListBoxGroup *g = &unk_90[unk_18];
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
        } else if (unk_20 + 7 > g->unk_00) {
            unk_20 = g->unk_00 - 7;
        }
    }
    if (unk_20 != unk_1C || unk_30 != unk_2C) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0x108);
        return;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
}

void CQLListBox::CursorUp()
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

void CQLListBox::PageDown()
{
    int top = unk_20 == unk_1C ? unk_1C + 7 : unk_20 + 7;
    int max = unk_90[unk_18].unk_00 - 7;
    if (top > max) {
        top = max;
    }
    if (top < 0) {
        top = 0;
    }
    if (top != unk_1C) {
        unk_1C = unk_20 = top;
        NotifyCursor(FALSE);
        Refresh();
        CGame::GetInstance()->m_audioEngine->PlaySe(0x108);
        return;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
}

void CQLListBox::PageUp()
{
    int top = unk_20 == unk_1C ? unk_1C - 7 : unk_20 - 7;
    if (top < 0) {
        top = 0;
    }
    if (top != unk_1C) {
        unk_1C = unk_20 = top;
        NotifyCursor(FALSE);
        Refresh();
        CGame::GetInstance()->m_audioEngine->PlaySe(0x108);
        return;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
}

void CQLListBox::Refresh()
{
    if (unk_90 == NULL) {
        return;
    }
    unk_194 = TRUE;
    if (unk_1C <= 3) {
        unk_34 = (u8)(256 - (unk_0C - (unk_1C % 12) * 16));
    } else {
        unk_34 = (unk_1C % 12) * 16 - unk_0C;
        if (unk_34 < 0) {
            unk_34 += 192;
        }
    }
    PlaceLineSprites(0, unk_1C);
}

void CQLListBox::PlaceLineSprites(int dy, int line)
{
    int current = 0;
    QLListBoxGroup *group = &unk_90[unk_18];
    for (int i = 0; i < 7; i++) {
        int y = unk_0C + 8 + i * 16;
        if (line + i < group->unk_00) {
            int state = group->unk_04[line + i].unk_04;
            if (unk_68[i] != NULL) {
                unk_68[i]->SetPos(unk_24, dy + y);
                unk_68[i]->SetVisible(state == 1 ? TRUE : FALSE);
            }
            if (unk_48[i] != NULL) {
                unk_48[i]->SetPos(unk_24, dy + y);
                unk_48[i]->SetVisible(state != 2 ? TRUE : FALSE);
            }
            if (unk_88 != NULL && state == 2) {
                unk_88->SetPos(unk_24, dy + y);
                current++;
            }
        } else {
            unk_48[i]->unk_14 = FALSE;
            unk_68[i]->unk_14 = FALSE;
        }
    }
    if (unk_88 != NULL) {
        unk_88->SetVisible(current);
    }
}

void CQLListBox::UpdateInput()
{
    s32 group;
    QLListBoxGroup *groups = unk_90;
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
                    unk_40->SetPos(unk_28, unk_2C);
                    sel = unk_1C + ((unk_2C - (unk_0C + 8)) >> 4);
                    game->m_audioEngine->PlaySe(0xFA);
                    NotifyCursor(TRUE);
                }
            }
        } else if ((u16)(game->unk_0014->unk_0002 & PAD_BUTTON_A)) {
            sel = top + ((unk_2C - (unk_0C + 8)) >> 4);
        }
        if (sel < 0) {
            return;
        }
        if (unk_3C == NULL) {
            return;
        }
        unk_3C->OnListBoxEvent0(unk_04, sel);
    }
}

static inline void SetBlink(OamSprite *sprite, u8 timer)
{
    sprite->SetVisible(timer < 6 ? TRUE : FALSE);
}

void CQLListBox::UpdateScroll()
{
    if (unk_90[unk_18].unk_00 == 0) {
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
        unk_40->SetPos(unk_28, unk_2C);
        if (unk_30 == unk_2C) {
            NotifyCursor(FALSE);
        }
        unk_44 = 0;
    }
    if (unk_20 != unk_1C) {
        BOOL down = unk_20 > unk_1C ? TRUE : FALSE;
        if (down) {
            unk_34 += 2;
            if (unk_1C <= 3) {
                unk_34 = (u8)unk_34;
            } else if (unk_34 >= 192) {
                unk_34 -= 192;
            }
            if (!(unk_34 & 0xF)) {
                unk_1C++;
                NotifyCursor(FALSE);
                DrawLine(unk_1C + 8);
            }
        } else {
            unk_34 -= 2;
            if (unk_34 < 0) {
                if (unk_1C <= 3) {
                    unk_34 &= 0xFF;
                } else {
                    unk_34 += 192;
                }
            }
            if (!(unk_34 & 0xF)) {
                unk_1C--;
                NotifyCursor(FALSE);
                DrawLine(unk_1C - 2);
            }
        }
        UpdateLineSprites(down);
        unk_44 = 0;
    }
    if (unk_40 == NULL) {
        return;
    }
    if (++unk_44 >= 12) {
        unk_44 = 0;
    }
    SetBlink(unk_40, unk_44);
}

void CQLListBox::UpdateLineSprites(BOOL down)
{
    int line;
    int dy = unk_34 & 0xF;
    if (dy < 8) {
        dy = -dy;
        line = down ? unk_1C : unk_20;
    } else {
        dy = 16 - dy;
        line = down ? unk_20 : unk_1C;
    }
    PlaceLineSprites(dy, line);
}

static inline void SetSpriteVisible(OamSprite *sprite, int count)
{
    sprite->SetVisible(count != 0 ? TRUE : FALSE);
}

void CQLListBox::SelectGroup(int group)
{
    if (unk_18 != group) {
        QLListBoxGroup *prev = &unk_90[unk_18];
        prev->unk_08 = unk_1C;
        prev->unk_0C = unk_1C + ((unk_2C - 8 - unk_0C) >> 4);
        unk_18 = group;
        int idx;
        prev = unk_90;
        idx = unk_18;
        QLListBoxGroup *next = &prev[idx];
        unk_1C = unk_20 = next->unk_08;
        unk_2C = unk_30 = unk_0C + (next->unk_0C - next->unk_08) * 16 + 8;
        Refresh();
        unk_40->SetPos(unk_28, unk_2C);
        SetSpriteVisible(unk_40, prev[idx].unk_00);
    }
    NotifyCursor(FALSE);
}

void CQLListBox::DrawLine(int line)
{
    QLListBoxGroup *group = &unk_90[unk_18];
    if (line < 0) {
        return;
    }
    if (line >= group->unk_00) {
        return;
    }
    int row = line % 12;
    SubTextPrinter *text = CGame::GetInstance()->unk_1498;
    text->ClearWindow(row);
    text->Print(row, 32, 3, 3, (u8 *)group->unk_04[line].unk_00, FALSE, 0);
    u8 *scr = (u8 *)G2S_GetBG3ScrPtr() + (row << 7);
    MI_CpuCopy8(group->unk_04[line].unk_04 == 2 ? unk_94 : unk_114, scr, 0x80);
}

int CQLListBox::GetLineCount(int group)
{
    if (group >= 0 && group < unk_8C && unk_90 != NULL) {
        return unk_90[group].unk_00;
    }
    return 0;
}

void CQLListBox::ApplyScroll()
{
    unk_38 = unk_34;
    if (!unk_194) {
        return;
    }
    GX_GetVCount();
    CGame::GetInstance();
    for (int i = 0; i < 7; i++) {
        DrawLine(unk_1C + i);
    }
    DrawLine(unk_1C - 2);
    DrawLine(unk_1C - 1);
    DrawLine(unk_1C + 7);
    DrawLine(unk_1C + 8);
    unk_194 = FALSE;
    GX_GetVCount();
}

void CQLListBox::NotifyCursor(u8 changed)
{
    if (unk_3C == NULL) {
        return;
    }
    int cursor = -1;
    int count = unk_90[unk_18].unk_00;
    if (count > 0) {
        cursor = unk_1C + ((unk_2C - (unk_0C + 8)) >> 4);
    }
    u32 flags = 0;
    if (unk_1C + 7 < count) {
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
    unk_3C->OnListBoxEvent1(unk_04, cursor, flags, changed);
}

static void OnTopAlarm(void *arg)
{
    CQLListBox *box = (CQLListBox *)arg;
    G2S_SetBG0Offset(0, 216);
    sScroll[0] = box->unk_38;
    OS_CancelVAlarm(&sAlarmSplit);
    s16 line = -1;
    if (sScroll[0] > 16 && sScroll[0] < 192) {
        s16 split = 176 - (sScroll[0] - 16);
        if (split < 48) {
            sScroll[0] = 256 - split;
        } else {
            sScroll[1] = split;
            line = split - 2;
        }
    }
    if (line >= 0) {
        OS_SetVAlarm(&sAlarmSplit, line, 4, OnSplitAlarm, NULL);
    }
}

static void OnScrollAlarm(void *arg)
{
    G2S_SetBG0Offset(0, sScroll[0]);
    G2S_SetBG3Offset(0, sScroll[0]);
}

static void OnSplitAlarm(void *arg)
{
    G2S_SetBG0Offset(0, 256 - sScroll[1]);
    G2S_SetBG3Offset(0, 256 - sScroll[1]);
}

QLBlinkMarks::QLBlinkMarks()
{
    unk_00 = FALSE;
    unk_01 = 0;
    MI_CpuClear8(unk_04, sizeof(unk_04));
}

BOOL QLBlinkMarks::Init(OamSpriteSet *anims, int animOff, int animOn, int x, int y, int priority)
{
    int px = x - 10;
    for (int i = 0; i < 3; i++) {
        unk_04[i].on = anims->AddSprite(animOn, px, y, priority + 1);
        unk_04[i].off = anims->AddSprite(animOff, px, y, priority);
        px += 10;
    }
    return TRUE;
}

void QLBlinkMarks::SetEnabled(BOOL enabled)
{
    unk_00 = enabled;
    if (unk_00) {
        unk_01 = 0;
        for (int i = 0; i < 3; i++) {
            unk_04[i].on->unk_14 = TRUE;
            unk_04[i].off->unk_14 = FALSE;
        }
    } else {
        for (int i = 0; i < 3; i++) {
            unk_04[i].on->unk_14 = TRUE;
            unk_04[i].off->unk_14 = FALSE;
        }
    }
}

void QLBlinkMarks::Update()
{
    if (!unk_00) {
        return;
    }
    u32 t = unk_01 & 0x3F;
    BOOL show = t < 36 ? TRUE : FALSE;
    unk_04[0].off->SetVisible(show);
    unk_04[1].off->SetVisible(show && t >= 12 ? TRUE : FALSE);
    unk_04[2].off->SetVisible(show && t >= 24 ? TRUE : FALSE);
    unk_01++;
}

QLMessageStrings::QLMessageStrings()
{
    unk_00 = NULL;
    unk_04 = 0;
    unk_08 = NULL;
}

QLMessageStrings::~QLMessageStrings()
{
    Release();
}

int QLMessageStrings::Load(const char *path)
{
    Release();
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

const char *QLMessageStrings::GetString(int idx)
{
    if (idx >= 0 && idx < unk_04) {
        return unk_08[idx];
    }
    return NULL;
}

void QLMessageStrings::Release()
{
    SAFE_DELETE_ARRAY(unk_08);
    SAFE_DELETE(unk_00);
}
