#include "YesNoPrompt.hpp"

#include "CGame_0024.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCGRFile.hpp"
#include "file/CNCLRFile.hpp"

extern "C" {

extern char s_ICN_0208a9c8;
extern char s_data_interface_i058_LZ_bin_0208a9cc;
extern char s_ICN_i058_00_NCGR_0208a9e8;
extern char s_ICN_i058_NCLR_0208a9fc;
}

YesNoPrompt::YesNoPrompt()
{
    unk_0000 = 0;
    unk_1604 = 0;
    m_state = 0;
    m_result = 0;
    m_timer = 0;

    for (int i = 0; i < 4; ++i) {
        unk_1620[i] = 0x1000;
    }

    m_pad = 0;
    m_touch = 0;
    m_audio = 0;
    unk_1630 = 0x10;
    unk_1634 = 0x4000;
    unk_1638 = 0;
}

void YesNoPrompt::Init(CGame_0024 *arg0, PadInput *arg1, CTouchPanel *arg2, void *arg3, u32 arg4, u32 arg5, u32 arg6)
{
    unk_1630 = arg4;
    unk_1634 = arg5;
    unk_1638 = arg6;

    if (arg0 != NULL) {
        unk_0000 = arg0;
    }

    if (arg1 != NULL) {
        m_pad = arg1;
    }

    if (arg2 != NULL) {
        m_touch = arg2;
    }

    if (arg3 != NULL) {
        m_audio = (AudioEngine *)arg3;
    }

    LoadGraphics();

    for (int i = 0; i < 0x80; ++i) {
        m_icons[i].Init(&unk_0000[i]);
    }
}

void YesNoPrompt::LoadGraphics()
{
    CArchiveGuard *archive = new CArchiveGuard(&s_ICN_0208a9c8, &s_data_interface_i058_LZ_bin_0208a9cc, 1, 1, 0, 0, 0);

    CNCGRFile *ncgrFile = new CNCGRFile(&s_ICN_i058_00_NCGR_0208a9e8, 1, 0, 0);
    MI_CpuCopyFast(ncgrFile->unk_B8->pRawData, (void *)(HW_OBJ_VRAM + unk_1634), ncgrFile->unk_B8->szByte);

    if (ncgrFile != NULL) {
        delete ncgrFile;
    }

    CNCLRFile *nclrFile = new CNCLRFile(&s_ICN_i058_NCLR_0208a9fc, 1, 0, 0);
    MI_CpuCopyFast(nclrFile->unk_B8->pRawData, (void *)(HW_OBJ_PLTT + unk_1638), nclrFile->unk_B8->szByte);

    if (nclrFile != NULL) {
        delete nclrFile;
    }

    delete archive;
}

void YesNoPrompt::AddIcon(u32 arg0, u32 arg1, u32 arg2, u32 arg3)
{
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);

    for (int i = 0; i < 0x80; ++i) {
        if (m_icons[i].unk_10 == 0) {
            m_icons[i].Setup(arg0, arg1, arg2, arg3, unk_1630, unk_1634, unk_1638);
            return;
        }
    }
}

void YesNoPrompt::Update()
{
    for (int i = 0; i < 4; ++i) {
        s16 v0 = unk_1620[i] / 16;
        CGame_0024 *ptr = &unk_0000[i * 4];

        ptr[0].unk_06 = v0;
        ptr[1].unk_06 = 0;
        ptr[2].unk_06 = 0;
        ptr[3].unk_06 = v0;
    }

    if (unk_1604 == 1) {
        UpdateInput();
    }

    for (int i = 0; i < 0x80; ++i) {
        if (m_icons[i].unk_10 == 1) {
            m_icons[i].Update();
        }
    }
}

void YesNoPrompt::Reset()
{
    for (int i = 0; i < 0x80; ++i) {
        m_icons[i].Init(&unk_0000[i]);
    }

    for (int i = 0; i < 4; ++i) {
        unk_1620[i] = 0x1000;
    }
}

void YesNoPrompt::ScrollIcons()
{
    for (int i = 0; i < 0x80; ++i) {
        switch (m_icons[i].unk_04) {
        case 0:
        case 1:
        case 15:
        case 16:
            m_icons[i].Init(&unk_0000[i]);
            break;

        default:
            if (m_icons[i].unk_0C == 0x18 || m_icons[i].unk_0C == 0xA8) {
                m_icons[i].unk_0C -= 0x10;
            } else {
                m_icons[i].Init(&unk_0000[i]);
            }

            break;
        }
    }
}

void YesNoPrompt::Open()
{
    AddIcon(0xF, 0x20, 0x40, 1);
    AddIcon(0x10, 0xA0, 0x40, 1);

    unk_1604 = 1;
    m_state = 1;
    m_result = 0;
    m_timer = 10;
}

void YesNoPrompt::UpdateInput()
{
    if (m_state == 2) {
        if (m_timer != 0) {
            if (m_timer == 40) {
                unk_1620[1] = 0x1400;
            } else if (m_timer == 36) {
                unk_1620[1] = 0x1000;
            }

            --m_timer;
            return;
        }

        unk_1604 = 0;
        m_state = 0;
        return;
    }

    if (m_timer != 0) {
        --m_timer;
        return;
    }

    if ((u16)(m_pad->unk_0002 & 1) != 0) {
        // "A" physical button press
        m_state = 2;
        m_result = 0;
        m_timer = 0x28;

        if (!PlaySe(6)) {
            PlaySe(0x43);
        }
    } else if ((u16)(m_pad->unk_0002 & 2) != 0) {
        // "B" physical button press
        m_state = 2;
        m_result = 1;
        m_timer = 0x28;

        if (!PlaySe(8)) {
            PlaySe(0x44);
        }
    } else if (m_touch->unk_04 != 0) {
        if (m_touch->unk_0A.y >= 0x40 && m_touch->unk_0A.y <= 0x80 && m_touch->unk_0A.x >= 0x20 && m_touch->unk_0A.x <= 0x60) {
            // "Yes" virtual button touch
            m_state = 2;
            m_result = 0;
            m_timer = 0x28;

            if (!PlaySe(6)) {
                PlaySe(0x43);
            }
        } else if (m_touch->unk_0A.y >= 0x40 && m_touch->unk_0A.y <= 0x80 && m_touch->unk_0A.x >= 0xA0 && m_touch->unk_0A.x <= 0xE0) {
            // "No" virtual button touch
            m_state = 2;
            m_result = 1;
            m_timer = 0x28;

            if (!PlaySe(8)) {
                PlaySe(0x44);
            }
        }
    }

    if (m_state == 2) {
        ShowAnswer();
    }
}

void YesNoPrompt::ShowAnswer()
{
    for (int i = 0; i < 0x80; ++i) {
        if (m_icons[i].unk_10 == 1 && m_icons[i].unk_04 == 0xF) {
            if (m_result == 0) {
                m_icons[i].unk_24 = 1;
            } else {
                m_icons[i].Init(&unk_0000[i]);
            }
        } else if (m_icons[i].unk_10 == 1 && m_icons[i].unk_04 == 0x10) {
            if (m_result == 1) {
                m_icons[i].unk_24 = 1;
            } else {
                m_icons[i].Init(&unk_0000[i]);
            }
        }
    }
}

BOOL YesNoPrompt::PlaySe(int index)
{
    if (m_audio != 0) {
        return m_audio->PlaySe(index);
    }

    return FALSE;
}
