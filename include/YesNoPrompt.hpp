#ifndef POKERANGER2_YESNOPROMPT_HPP
#define POKERANGER2_YESNOPROMPT_HPP

#include <nitro.h>

#include "AudioEngine.hpp"
#include "CGame_0024.hpp"
#include "CTouchPanel.hpp"
#include "PadInput.hpp"
#include "UnkClass_0200BBC0.hpp"
#include "common.hpp"

class YesNoPrompt {
public:
    YesNoPrompt();

    void Init(CGame_0024 *arg0, PadInput *arg1, CTouchPanel *arg2, void *arg3, u32 arg4, u32 arg5, u32 arg6);
    void LoadGraphics();
    void AddIcon(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void sub_0200BEBC();
    void Reset();
    void sub_0200BFB4();
    void Open();
    void sub_0200C0C8();
    void sub_0200C2C4();
    BOOL sub_0200C36C(int index);

public:
    CGame_0024 *unk_0000;
    UnkClass_0200BBC0 unk_0004[0x80];
    u32 unk_1604;
    u32 unk_1608;
    u32 unk_160C;
    u32 unk_1610;
    PadInput *unk_1614;
    CTouchPanel *unk_1618;
    AudioEngine *unk_161C;
    u32 unk_1620[4];
    u32 unk_1630;
    u32 unk_1634;
    u32 unk_1638;
};

STATIC_SIZE_ASSERT(YesNoPrompt, 0x163C);

#endif // POKERANGER2_YESNOPROMPT_HPP
