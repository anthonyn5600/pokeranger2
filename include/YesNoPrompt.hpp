#ifndef POKERANGER2_YESNOPROMPT_HPP
#define POKERANGER2_YESNOPROMPT_HPP

#include <nitro.h>

#include "AudioEngine.hpp"
#include "CGame_0024.hpp"
#include "CTouchPanel.hpp"
#include "PadInput.hpp"
#include "PromptIcon.hpp"
#include "common.hpp"

class YesNoPrompt {
public:
    YesNoPrompt();

    void Init(CGame_0024 *arg0, PadInput *arg1, CTouchPanel *arg2, void *arg3, u32 arg4, u32 arg5, u32 arg6);
    void LoadGraphics();
    void AddIcon(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void Update();
    void Reset();
    void ScrollIcons();
    void Open();
    void UpdateInput();
    void ShowAnswer();
    BOOL PlaySe(int index);

public:
    CGame_0024 *unk_0000;
    PromptIcon m_icons[0x80];
    u32 unk_1604;
    u32 m_state;
    u32 m_result;
    u32 m_timer;
    PadInput *m_pad;
    CTouchPanel *m_touch;
    AudioEngine *m_audio;
    u32 unk_1620[4];
    u32 unk_1630;
    u32 unk_1634;
    u32 unk_1638;
};

STATIC_SIZE_ASSERT(YesNoPrompt, 0x163C);

#endif // POKERANGER2_YESNOPROMPT_HPP
