#ifndef POKERANGER2_TEXTBOXMANAGER_HPP
#define POKERANGER2_TEXTBOXMANAGER_HPP

#include <nitro.h>

#include "AudioEngine.hpp"
#include "CTouchPanel.hpp"
#include "PadInput.hpp"
#include "YesNoPrompt.hpp"
#include "common.hpp"
#include "file/CNCLRFile.hpp"

// TODO: Figure out what this really is
class UnkClass_020091E8_004_08 {
public:
    u32 unk_00;
    u8 *unk_04;
};

// TODO: Figure out what this really is
class UnkClass_020091E8_004 {
public:
    u32 unk_00;
    u32 unk_04;
    UnkClass_020091E8_004_08 *unk_08;
};

// TODO: Figure out what this really is
class UnkClass_020091E8_084 {
public:
    virtual void func0();
    virtual void func1();
};

class UnkClass_020091E8_0F8 {
public:
    inline void func0(void *charBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, int charNo, NNSG2dFont **arg6)
    {
        NNS_G2dCharCanvasInitForBG(&unk_00, charBase, areaWidth, areaHeight, NNS_G2D_CHARA_COLORMODE_16);

        NNSG2dFont *v0 = *arg6;
        unk_18 = &unk_00;
        unk_1C = v0;
        unk_20 = 0;
        unk_24 = 4;

        NNS_G2dMapScrToCharText(G2_GetBG1ScrPtr(), areaWidth, areaHeight, areaLeft, areaTop, NNS_G2D_TEXT_BG_WIDTH_256, charNo, 0xF);
    }

public:
    NNSG2dCharCanvas unk_00;
    NNSG2dCharCanvas *unk_18;
    NNSG2dFont *unk_1C;
    u32 unk_20;
    u32 unk_24;
};

class TextboxManager {
public:
    TextboxManager();

    void sub_02009274();
    void FreeAllMessages();
    void Reset();
    void Init(PadInput *arg0, CTouchPanel *arg1, NNSG2dFont *arg2, void *arg3, CGame_0024 *arg4, void *arg5, u32 arg6, u32 arg7, u32 arg8);
    void ResetState();
    void LoadWindowGraphics();
    void SetupBG();
    void LoadFontPalette();
    void InitCanvases();
    void LoadWindowColor(u32 arg0);
    void SetParam(size_t arg0, u32 arg1);
    u32 GetParam(size_t arg0);
    BOOL ExecControlCode(u32 arg0);
    void ShowText(u8 *arg0, u32 arg1, u32 arg2, u32 arg3);
    BOOL IsActive();
    void Close();
    void CloseAndClear(u32 arg0, u32 arg1);
    void Clear(u32 arg0);
    u32 GetState();
    u32 Update();
    u32 sub_0200A804(int arg0);
    void UpdateAdvance();
    BOOL IsAdvanceTriggered();
    BOOL IsAdvanceHeld();
    void SetTextSpeed(s32 arg0);
    void ResetTextSpeed();
    void SetAutoAdvance(s32 arg0);
    void ClearAutoAdvance();
    void SetAutoClose(s32 arg0);
    void ClearAutoClose();
    BOOL PlaySe(u32 arg0);
    void ShowMessage(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
    void LoadSystemMessages(s32 arg0);
    void FreeSystemMessages();
    void ShowSystemMessage(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void LoadAreaMessages(s32 arg0);
    void FreeAreaMessages();
    void ShowAreaMessage(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void LoadChapterMessages(s32 arg0);
    void FreeChapterMessages();
    void ShowChapterMessage(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void LoadQuestMessages(s32 arg0);
    void FreeQuestMessages();
    void ShowQuestMessage(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void LoadBattleMessages(s32 arg0);
    void FreeBattleMessages();
    void ShowBattleMessage(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void OpenYesNo();
    BOOL CloseIfNoPrompt(u32 arg0);
    u32 GetYesNoResult();

    static void ClearScreenCallback(void *data);

public:
    // TODO: What is this?
    void *unk_000;
    UnkClass_020091E8_004 *unk_004;
    UnkClass_020091E8_004 *unk_008;
    UnkClass_020091E8_004 *unk_00C;
    UnkClass_020091E8_004 *unk_010;
    UnkClass_020091E8_004 *unk_014;
    u32 unk_018;
    u32 unk_01C;
    u32 unk_020;
    u32 unk_024;
    u32 unk_028;
    CNCLRFile *unk_02C;
    // TODO: Size not definitive
    char unk_030[0x18];
    u8 *unk_048;
    u32 unk_04C;
    u32 unk_050;
    u32 unk_054;
    u32 m_autoAdvance;
    u32 m_autoAdvanceDelay;
    u32 unk_060;
    u32 m_autoClose;
    u32 m_autoCloseDelay;
    u32 unk_06C;
    u32 unk_070;
    u32 unk_074;
    u32 unk_078;
    u8 *unk_07C;
    u32 unk_080;
    UnkClass_020091E8_084 *unk_084;
    PadInput *unk_088;
    CTouchPanel *unk_08C;
    // TODO: What is this?
    AudioEngine *m_audio;
    u32 unk_094;
    u32 unk_098;
    s32 unk_09C;
    s32 unk_0A0;
    s32 unk_0A4;
    s32 unk_0A8;
    s32 unk_0AC;
    s32 unk_0B0;
    // TODO: Size not definitive
    u32 unk_0B4[0x10];
    NNSG2dFont *unk_0F4;
    UnkClass_020091E8_0F8 unk_0F8;
    UnkClass_020091E8_0F8 unk_120;
    u32 unk_148;
    YesNoPrompt *m_yesNo;
    u32 unk_150;
    u32 unk_154;
};

STATIC_SIZE_ASSERT(TextboxManager, 0x158);

#endif // POKERANGER2_TEXTBOXMANAGER_HPP
