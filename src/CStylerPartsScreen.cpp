#include <nitro.h>

#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200C38C.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_0202A2AC.hpp"
#include "UnkClass_02034478.hpp"
#include "scene/CStylerScreens.hpp"

static StylerPartEntry sEntries[47] = {
    { 0, 19, 35, 1, 14, 1 },
    { 1, 43, 35, 1, 14, 2 },
    { 2, 67, 35, 7, 3, 1 },
    { 3, 91, 35, 7, 3, 2 },
    { 4, 115, 35, 3, 1, 1 },
    { 5, 139, 35, 3, 1, 2 },
    { 6, 163, 35, 9, 2, 1 },
    { 7, 187, 35, 9, 2, 2 },
    { 8, 19, 59, 2, 0, 1 },
    { 9, 43, 59, 2, 0, 2 },
    { 10, 67, 59, 16, 13, 1 },
    { 11, 91, 59, 16, 13, 2 },
    { 12, 115, 59, 8, 4, 1 },
    { 13, 139, 59, 8, 4, 2 },
    { 14, 163, 59, 12, 5, 1 },
    { 15, 187, 59, 12, 5, 2 },
    { 16, 19, 83, 10, 8, 1 },
    { 17, 43, 83, 10, 8, 2 },
    { 18, 67, 83, 6, 10, 1 },
    { 19, 91, 83, 6, 10, 2 },
    { 20, 115, 83, 14, 6, 1 },
    { 21, 139, 83, 14, 6, 2 },
    { 22, 163, 83, 5, 7, 1 },
    { 23, 187, 83, 5, 7, 2 },
    { 24, 19, 107, 4, 9, 1 },
    { 25, 43, 107, 4, 9, 2 },
    { 26, 67, 107, 13, 12, 1 },
    { 27, 91, 107, 13, 12, 2 },
    { 28, 115, 107, 17, 16, 1 },
    { 29, 139, 107, 17, 16, 2 },
    { 30, 163, 107, 15, 11, 1 },
    { 31, 187, 107, 15, 11, 2 },
    { 32, 19, 131, 11, 15, 1 },
    { 33, 43, 131, 11, 15, 2 },
    { 34, 67, 131, 30, 17, 1 },
    { 35, 91, 131, 30, 17, 2 },
    { 36, 115, 131, 33, 18, 1 },
    { 37, 139, 131, 33, 18, 2 },
    { 38, 163, 131, 37, 20, 1 },
    { 39, 187, 131, 37, 20, 2 },
    { 40, 211, 131, 35, 19, 1 },
    { 41, 211, 59, 26, 22, 1 },
    { 42, 235, 59, 26, 22, 2 },
    { 43, 211, 83, 39, 23, 1 },
    { 44, 235, 83, 39, 23, 2 },
    { 45, 211, 107, 42, 21, 1 },
    { 46, 235, 119, 25, 15, 3 },
};

static u8 sEmptyText[0x20];

void CStylerPartButton::Init(int id, UnkClass_0200ECD0 *sprites, int anim, int x, int y, BOOL large)
{
    m_id = id;
    m_sprites = sprites;
    m_obj = sprites->sub_0200F4FC(anim, x, y, 1);
    m_slot = sprites->unk_24;
    if (large == TRUE) {
        m_obj->sub_0200EBF4(0x20, 0x40, 0, 0);
    } else {
        m_obj->sub_0200EBF4(0x20, 0x20, 0, 0);
    }
}

u8 CStylerPartButton::IsTouched()
{
    return m_obj->sub_0200EB84();
}

void CStylerPartCursor::Init(UnkClass_0200ECD0 *sprites)
{
    m_sprites = sprites;
    m_objs[0] = sprites->sub_0200F4FC(0, 0, 0, 0);
    m_slots[0] = sprites->unk_24;
    m_objs[1] = sprites->sub_0200F4FC(3, 0, 0, 0);
    m_slots[1] = sprites->unk_24;
    m_objs[0]->unk_14 = FALSE;
    m_objs[1]->unk_14 = FALSE;
}

void CStylerPartCursor::Set(int x, int y, int size)
{
    m_size = size;
    switch (size) {
    case 0:
        m_objs[0]->unk_14 = TRUE;
        m_objs[1]->unk_14 = FALSE;
        m_objs[0]->sub_0200EB28(x, y);
        m_sprites->sub_0200F628(m_slots[0], 0);
        break;
    case 1:
        m_objs[1]->unk_14 = TRUE;
        m_objs[0]->unk_14 = FALSE;
        m_objs[1]->sub_0200EB28(x, y);
        m_sprites->sub_0200F628(m_slots[1], 3);
        break;
    }
    m_frame = 0;
    m_counter = 0;
}

void CStylerPartCursor::Update()
{
    if (m_size == -1) {
        return;
    }

    int durations[3] = { 20, 8, 8 };
    if (++m_counter != durations[m_frame]) {
        return;
    }

    m_counter = 0;
    if (++m_frame == 3) {
        m_frame = 0;
    }
    m_sprites->sub_0200F628(m_slots[m_size], m_size * 3 + m_frame);
}

CStylerPartsScreen::CStylerPartsScreen(CGame *game, CStylerData *data)
{
    m_selected = NULL;
    m_selectedButton = NULL;
    m_sprites = NULL;
    m_cursorSprites = NULL;
    m_game = game;
    m_data = data;
    m_menuMessages = data->m_menuMessages;
    unk_220 = data->unk_10;
    MI_CpuFill8(m_buttons, 0, sizeof(m_buttons));
}

CStylerPartsScreen::~CStylerPartsScreen()
{
    Release();
}

void CStylerPartsScreen::Load()
{
    LoadData();
    SetupBG();
    LoadSprites();
    LoadBG();
    DrawTexts();
    CreateButtons();
}

void CStylerPartsScreen::Release()
{
    SAFE_DELETE(m_sprites);
    SAFE_DELETE(m_cursorSprites);
    for (int i = 0; i < 47; i++) {
        SAFE_DELETE(m_buttons[i]);
    }
    SAFE_DELETE(m_cursor);

    m_game->m_textboxData->sub_02009FB0(1, 1);
    m_game->m_textboxData->sub_020092D4();
}

void CStylerPartsScreen::Reset()
{
    CStylerScreen::Reset();
    SetupBG();
    MI_CpuCopyFast(m_palette, (void *)HW_OBJ_PLTT, 0x1E0);
}

void CStylerPartsScreen::LoadData()
{
    m_level = m_data->m_level;
    if (m_level != 0) {
        m_selected = FindEntry(m_level);
    }
}

void CStylerPartsScreen::SetupBG()
{
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x9000, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0xb000, GX_BG_CHARBASE_0x04000);
    G2_SetBG1Priority(0);
    G2_SetBG0Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    G2_BlendNone();
}

void CStylerPartsScreen::LoadSprites()
{
    int charNo = 0;
    m_sprites = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0024[8], m_game->unk_14A8, FALSE, 0x40);
    charNo += m_sprites->sub_0200EE14("data/menu", "stl001_00", charNo / 32, 0);
    m_cursorSprites = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0024[2], m_game->unk_14A8, FALSE, 0x40);
    m_cursorSprites->sub_0200EE14("data/menu", "stl002_00", charNo / 32, 14);
    MI_CpuCopyFast((void *)HW_OBJ_PLTT, m_palette, 0x1E0);
}

void CStylerPartsScreen::LoadBG()
{
    BGS_LoadCharAndPltt("menu/", "stl001_bg_", 3, "stl001", 0, "stl001", 0);
    BGS_LoadScr("menu/", "stl001_bg_", 3, "stl001_00", 0, 0, 0, 0);
}

void CStylerPartsScreen::DrawTexts()
{
    UnkClass_0200C38C *printer = m_game->unk_1494;
    printer->sub_0200C3D0();
    printer->sub_0200C408(0, GX_BG_SCRBASE_0x9000, GX_BG_CHARBASE_0x10000);
    printer->sub_0200C680(1);
    printer->sub_0200C6C8(0, 20, 3, 0, 0, 1, 0, 2);

    if (m_menuMessages->unk_08[64].unk_04 != NULL) {
        printer->sub_0200C7A4(0, 4, 6, 3, m_menuMessages->unk_08[64].unk_04, FALSE, 0);
    }

    m_game->m_textboxData->sub_0200AB28(3);
    m_game->m_textboxData->sub_0200AA04(0);
    if (m_level == 0) {
        m_game->m_textboxData->sub_0200AD34(0x18, 1, 1, 0);
    } else {
        m_game->m_textboxData->sub_02009D8C(sEmptyText, 1, 1, 0);
    }
}

CStylerPartButton *CStylerPartsScreen::CreateButton(int id, StylerPartEntry *entry)
{
    CStylerPartButton *button = new CStylerPartButton();
    button->Init(id, m_sprites, entry->anim, entry->x, entry->y, entry->unlockLevel == 25);
    return button;
}

void CStylerPartsScreen::CreateButtons()
{
    for (int i = 0; i < 47; i++) {
        StylerPartEntry *entry = &sEntries[i];
        if (m_data->m_powerLevels[entry->idx] >= entry->level) {
            m_buttons[i] = CreateButton(i, entry);
            if (m_level != 0 && entry == m_selected) {
                m_selectedButton = m_buttons[i];
                m_selectedButton->m_sprites->sub_0200F628(m_selectedButton->m_slot, entry->unlockLevel == 25 ? 48 : 47);
            }
        } else {
            m_sprites->sub_0200F4FC(entry->unlockLevel == 25 ? 48 : 47, entry->x, entry->y, 1);
        }
    }

    m_cursor = new CStylerPartCursor();
    m_cursor->Init(m_cursorSprites);
}

int CStylerPartsScreen::Update()
{
    unk_08++;
    if (m_level != 0 && unk_08 == 600) {
        m_game->m_textboxData->sub_0200A088(1);
        m_game->m_textboxData->sub_0200AA04(0);
        m_game->m_textboxData->sub_0200AD34(0x72, 1, 1, 0);
    }

    m_cursor->Update();
    if (m_sprites != NULL) {
        m_sprites->sub_0200F64C();
    }
    if (m_cursorSprites != NULL) {
        m_cursorSprites->sub_0200F64C();
    }

    switch (unk_04) {
    case 0:
        if (!m_game->unk_14BC->sub_0200E310() && !m_game->unk_14C0->sub_0200E310()) {
            if (m_level != 0) {
                if (unk_08 == 60) {
                    m_cursor->Set(m_selected->x, m_selected->y, m_selected->unlockLevel == 25);
                    m_selectedButton->m_sprites->sub_0200F628(m_selectedButton->m_slot, m_selected->anim);
                    m_game->m_audioEngine->sub_02034C44(0xBA);
                    if (m_level > 25) {
                        m_game->m_textboxData->sub_0200AD34(m_level + 0x17 + m_selected->level, 1, 1, 0);
                    } else {
                        m_game->m_textboxData->sub_0200AD34(m_level + 0x18, 1, 1, 0);
                    }
                    unk_04 = 1;
                }
            } else {
                unk_04 = 1;
            }
        }
        break;
    case 1: {
        CGame *game = m_game;
        UnkClass_02001C04 *pad = game->unk_0014;
        CTouchPanel *touchPanel = game->touchPanel;
        if (m_level != 0) {
            if (touchPanel->unk_04 != 0 || (u16)(pad->unk_0002 & PAD_BUTTON_A) || (u16)(pad->unk_0002 & PAD_BUTTON_B)) {
                game->m_audioEngine->sub_02034C44(0x103);
                unk_04 = 2;
                m_game->unk_14BC->sub_0200E0E0(4, 20);
                m_game->unk_14C0->sub_0200E0E0(4, 20);
            }
        } else if (unk_220->sub_0202A404()) {
            unk_04 = 2;
            m_game->unk_14BC->sub_0200E0E0(4, 20);
        } else {
            UpdateButtons();
        }
        break;
    }
    case 2:
        if (m_level != 0) {
            if (!m_game->unk_14BC->sub_0200E310() && !m_game->unk_14C0->sub_0200E310()) {
                return -1;
            }
        } else {
            if (!m_game->unk_14BC->sub_0200E310()) {
                return 1;
            }
        }
        break;
    }

    return 0;
}

void CStylerPartsScreen::UpdateButtons()
{
    for (int i = 0; i < 47; i++) {
        if (m_buttons[i] != NULL && m_buttons[i]->IsTouched()) {
            StylerPartEntry *entry = &sEntries[i];
            if (m_selected == entry) {
                return;
            }
            m_selected = entry;
            m_selectedButton = m_buttons[i];
            m_game->m_audioEngine->sub_02034C44(0xFA);
            m_cursor->Set(m_selected->x, m_selected->y, m_selected->unlockLevel == 25);
            m_game->m_textboxData->sub_0200AD34(i + 0x77, 1, 1, 0);
            return;
        }
    }
}

void CStylerPartsScreen::Render()
{
    if (m_level == 0) {
        unk_220->sub_0202A47C();
    }
    if (m_cursorSprites != NULL) {
        m_cursorSprites->sub_0200F71C();
    }
    if (m_sprites != NULL) {
        m_sprites->sub_0200F71C();
    }
}

void CStylerPartsScreen::func7()
{
}

void CStylerPartsScreen::func8()
{
}

StylerPartEntry *CStylerPartsScreen::FindEntry(int unlockLevel)
{
    for (int i = 0; i < 47; i++) {
        StylerPartEntry *entry = &sEntries[i];
        if (entry->unlockLevel == unlockLevel && entry->level == m_data->m_powerLevels[entry->idx]) {
            return entry;
        }
    }
    OS_Terminate();
    return NULL;
}
