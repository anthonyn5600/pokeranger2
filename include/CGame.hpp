#ifndef POKERANGER2_CGAME_HPP
#define POKERANGER2_CGAME_HPP

#include <nitro.h>

#include "AudioEngine.hpp"
#include "BGFontPrinter.hpp"
#include "BattleStartParam.hpp"
#include "BrightnessFade.hpp"
#include "CBattleResultParameter.hpp"
#include "CGame_0024.hpp"
#include "CTPEmulator.hpp"
#include "CTouchPanel.hpp"
#include "DiskHPTable.hpp"
#include "FieldData.hpp"
#include "FontSet.hpp"
#include "FrameTimer.hpp"
#include "MissionQuestData.hpp"
#include "NameTables.hpp"
#include "PadInput.hpp"
#include "PokeIdTable.hpp"
#include "SaveData.hpp"
#include "ScriptManager.hpp"
#include "SubTextPrinter.hpp"
#include "TextPrinter.hpp"
#include "TextboxManager.hpp"
#include "UnkClass_0200FA5C.hpp"
#include "UnkClass_02010C3C.hpp"
#include "WindowWipe.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

typedef void (*CGame_020100E4_arg0)(void *);

class CameraController;

class CGame {
public:
    CGame();

    void *operator new(size_t size);

    static CGame *GetInstance();

    inline void func0()
    {
        MI_DmaCopy32(3, unk_0824, unk_0024, 0x400);
        MI_DmaCopy32(3, unk_0824, unk_0424, 0x400);
    }

    inline BGFontPrinter *GetPrinter()
    {
        return unk_0C24;
    }

    void ResetSaveState();
    void sub_0200FAA4();
    void sub_0200FAEC();
    void ResetForRestart();
    void OnVBlank();
    BOOL AddVBlankCallback(CGame_020100E4_arg0 arg0, void *arg1);
    void UpdateSystems();
    CTouchPanel *SetTouchPanelMode(int mode);
    void PrintHeapInfo(char *arg0);
    void InitVramManagers(u32 texSize, u32 texSize4x4, u32 plttSize);
    void ApplyTextSettings();
    void UpdateBarScroll();
    void InitVramTransfer();
    void SaveBgmState();
    BOOL RestoreBgmState();
    void ClearBgmState();
    void sub_02010448();
    void FreeTextWindows();

    static CGame *sInstance;

public:
    u32 unk_0000;
    u32 unk_0004;
    u32 unk_0008;
    CScene *currentScene;
    u32 unk_0010;
    PadInput *unk_0014;
    CTouchPanel *touchPanel;
    CTPEmulator *touchPanelEmulator;
    CTouchPanel *activeTouchPanel;
    CGame_0024 unk_0024[0x80];
    CGame_0024 unk_0424[0x80];
    CGame_0024 unk_0824[0x80];
    BGFontPrinter *unk_0C24;
    BGFontPrinter *unk_0C28;
    void *m_texVramWork;
    void *m_plttVramWork;
    NNSGfdVramTransferTask m_vramTransferTasks[0x80];
    PokeIdTable *unk_1434;
    DiskHPTable *m_diskHPTable;
    BattleStartParam *unk_143C;
    UnkClass_02010C3C *unk_1440;
    CBattleResultParameter *unk_1444;
    MATHRandContext32 m_rand32;
    MATHRandContext16 m_rand16;
    FrameTimer unk_146C;
    AudioEngine *m_audioEngine;
    TextboxManager *m_textboxData;
    TextPrinter *unk_1494;
    SubTextPrinter *unk_1498;
    ScriptManager *m_scriptManager;
    MissionQuestData *m_missionQuestData;
    SaveData *unk_14A4;
    u32 unk_14A8;
    FontSet *unk_14AC;
    NameTables *m_nameTables;
    void *unk_14B4;
    CameraController *m_cameraController;
    BrightnessFade *m_mainFade;
    BrightnessFade *m_subFade;
    WindowWipe *m_mainWipe;
    WindowWipe *m_subWipe;
    FieldData *m_fieldData;
    CGame_020100E4_arg0 m_vblankCallbacks[0x20];
    void *m_vblankArgs[0x20];
    s32 unk_15D0;
    u32 unk_15D4;
    UnkClass_0200FA5C *unk_15D8;
    u32 unk_15DC;
    u32 unk_15E0;
};

STATIC_SIZE_ASSERT(CGame, 0x15E4);

extern CGame *s_game;

#endif // POKERANGER2_CGAME_HPP
