#include "CGame.hpp"

#include <nitro.h>

#include "CameraController.hpp"
#include "heap.hpp"

extern "C" {
void MissionQuestData_Clear(MissionQuestData *obj);
void MissionQuestData_Init(MissionQuestData *obj, ScriptManager *scriptManager, TextboxManager *textboxData);
void SaveData_Init(SaveData *obj);
void GlobalValues_Init(void *obj);
void GlobalValues_Set(void *obj, int index, s32 value);
s32 GlobalValues_Get(void *obj, int index);
void ScriptManager_Update(ScriptManager *scriptManager);

extern SaveData MAIN_BSS_020B26A0;
extern u8 MAIN_BSS_0210C0B0[];
}

CGame *CGame::sInstance;

static inline void ResetTimers()
{
    DownloadMissionRecord_Init(&MAIN_BSS_020AF5D0);
    for (int i = 0; i < 3; i++) {
        DownloadMissionRecord_Init(&MAIN_BSS_020AF5E4[i]);
    }
    DownloadMissionClears_Reset(&MAIN_BSS_020AF598);
}

void CGame::ResetSaveState()
{
    MissionQuestData_Clear(m_missionQuestData);
    GlobalValues_Init(unk_14B4);
    SaveData_Init(unk_14A4);
}

void CGame::sub_0200FAA4()
{
    ResetSaveState();
    ResetTimers();
}

void CGame::sub_0200FAEC()
{
    ResetSaveState();
    for (int i = 0; i < 0x20; i++) {
        m_vblankCallbacks[i] = NULL;
    }
    unk_15E0 = 1;
}

void CGame::ResetForRestart()
{
    sub_0200FAEC();
    unk_0008 = -1;
    m_audioEngine->StopBgmReset(0);
}

CGame::CGame()
{
    sInstance = this;

    unk_0014 = new PadInput();
    touchPanel = new CTouchPanel();
    touchPanelEmulator = new CTPEmulator();
    SetTouchPanelMode(0);
    unk_14A8 = 0;

    NNS_GfdInitVramTransferManager(m_vramTransferTasks, 0x80);
    u32 workSize = NNS_GfdGetLnkTexVramManagerWorkSize(0x20);
    m_texVramWork = Heap_AllocSecondary(workSize);
    NNS_GfdInitLnkTexVramManager(0x80000, 0, m_texVramWork, workSize, TRUE);
    workSize = NNS_GfdGetLnkPlttVramManagerWorkSize(0x20);
    m_plttVramWork = Heap_AllocSecondary(workSize);
    NNS_GfdInitLnkPlttVramManager(0x4000, m_plttVramWork, workSize, TRUE);

    for (u8 i = 0; i < 0x80; i++) {
        unk_0824[i].attr0 = 0x200;
    }

    unk_0C24 = new BGFontPrinter();
    unk_0C28 = new BGFontPrinter();
    unk_1434 = new PokeIdTable(unk_14A8);
    m_diskHPTable = new DiskHPTable(0);
    unk_143C = new BattleStartParam();
    unk_1440 = new UnkClass_02010C3C();
    unk_1444 = new CBattleResultParameter();
    m_fieldData = new FieldData("data/field/fielddata.bin", 0);
    MATHRandContext32 *ctx32 = &m_rand32;
    MATH_InitRand32(ctx32, 0x1234);
    MATHRandContext16 *ctx16 = &m_rand16;
    MATH_InitRand16(ctx16, 0x4321);
    unk_0000 = 0;
    unk_146C.SetFps(30);

    m_audioEngine = new AudioEngine();
    unk_14AC = new FontSet(1);
    m_nameTables = new NameTables();
    m_textboxData = new TextboxManager();
    unk_1494 = new TextPrinter(&unk_14AC->unk_14, m_nameTables);
    unk_1498 = new SubTextPrinter(&unk_14AC->unk_14, m_nameTables);
    m_scriptManager = new ScriptManager(unk_14A8);
    m_missionQuestData = &MAIN_BSS_020B2638;
    MissionQuestData_Init(m_missionQuestData, m_scriptManager, m_textboxData);
    unk_14A4 = &MAIN_BSS_020B26A0;
    unk_14B4 = MAIN_BSS_0210C0B0;
    GlobalValues_Init(unk_14B4);

    m_cameraController = new CameraController(NULL);
    m_mainFade = new BrightnessFade(1, 0x10);
    m_subFade = new BrightnessFade(2, 0x10);
    m_mainWipe = new WindowWipe(1);
    m_subWipe = new WindowWipe(2);
    unk_15D4 = 1;
    unk_15D0 = 0;
    unk_15D8 = new UnkClass_0200FA5C();
    unk_15E0 = 1;
    ResetTimers();
}

CGame *CGame::GetInstance()
{
    return sInstance;
}

void CGame::OnVBlank()
{
    unk_146C.SampleTick();

    if (unk_15E0) {
        for (int i = 0; i < 0x20; i++) {
            if (m_vblankCallbacks[i] != NULL) {
                m_vblankCallbacks[i](m_vblankArgs[i]);
                m_vblankCallbacks[i] = NULL;
            }
        }
        NNS_GfdDoVramTransfer();
        InitVramTransfer();
    }

    m_mainFade->UpdateAndApply();
    m_subFade->UpdateAndApply();
    m_mainWipe->Apply();
    m_subWipe->Apply();
    // VCOUNT is read and dropped (likely a debug print stripped from the final build)
    GX_GetVCount();
    unk_146C.CountVBlank();
}

BOOL CGame::AddVBlankCallback(CGame_020100E4_arg0 callback, void *arg)
{
    for (int i = 0; i < 0x20; i++) {
        if (m_vblankCallbacks[i] == NULL) {
            m_vblankCallbacks[i] = callback;
            m_vblankArgs[i] = arg;
            return TRUE;
        }
    }
    return FALSE;
}

void CGame::UpdateSystems()
{
    ScriptManager_Update(m_scriptManager);
    m_textboxData->Update();
    m_cameraController->Update();
    m_mainWipe->Update();
    m_subWipe->Update();
    m_audioEngine->Main();
}

CTouchPanel *CGame::SetTouchPanelMode(int mode)
{
    CTouchPanel *prev = activeTouchPanel;
    switch (mode) {
    case 1:
        activeTouchPanel = touchPanelEmulator;
        break;
    case 0:
    default:
        activeTouchPanel = touchPanel;
        break;
    }
    return prev;
}

void *CGame::operator new(size_t size)
{
    return Heap_AllocSecondary(size);
}

void CGame::PrintHeapInfo(char *label)
{
    NNSFndHeapHandle *heap = Heap_GetSecondaryHandle();
    NNS_FndGetTotalFreeSizeForExpHeap(*heap);
    NNS_FndGetAllocatableSizeForExpHeapEx(*heap, 4);
    heap = Heap_GetMainHandle();
    NNS_FndGetTotalFreeSizeForExpHeap(*heap);
    NNS_FndGetAllocatableSizeForExpHeapEx(*heap, 4);
}

void CGame::InitVramManagers(u32 texSize, u32 texSize4x4, u32 plttSize)
{
    NNS_GfdInitLnkTexVramManager(texSize, texSize4x4, m_texVramWork, NNS_GfdGetLnkTexVramManagerWorkSize(0x20), TRUE);
    NNS_GfdInitLnkPlttVramManager(plttSize, m_plttVramWork, NNS_GfdGetLnkPlttVramManagerWorkSize(0x20), TRUE);
}

void CGame::ApplyTextSettings()
{
    m_textboxData->unk_070 = GlobalValues_Get(unk_14B4, 1);
    m_textboxData->unk_074 = GlobalValues_Get(unk_14B4, 2);
}

void CGame::UpdateBarScroll()
{
    unk_15D0 += 0x1E000 / unk_146C.GetFps();
    if (unk_15D0 > 0xD0000 || unk_15D0 < -0x10000) {
        unk_15D0 = -0x10000;
    }
}

void CGame::InitVramTransfer()
{
    NNS_GfdInitVramTransferManager(m_vramTransferTasks, 0x80);
    for (int i = 0; i < 0x20; i++) {
        m_vblankCallbacks[i] = NULL;
    }
}

void CGame::SaveBgmState()
{
    AudioEngine *audio = m_audioEngine;
    s32 c4 = audio->m_bgmGroup;
    s32 d0 = audio->m_bgmSeq;
    s32 f0 = audio->unk_F0;
    GlobalValues_Set(unk_14B4, 5, c4);
    GlobalValues_Set(unk_14B4, 6, d0);
    GlobalValues_Set(unk_14B4, 0x1A, f0);
}

BOOL CGame::RestoreBgmState()
{
    s32 v5 = GlobalValues_Get(unk_14B4, 5);
    s32 v6 = GlobalValues_Get(unk_14B4, 6);
    s32 v1A = GlobalValues_Get(unk_14B4, 0x1A);
    if (v1A < 0) {
        return FALSE;
    }
    m_audioEngine->LoadBgmGroup(v5);
    m_audioEngine->PlayBgm(v6, 0);
    m_audioEngine->sub_02034F4C(v1A);
    return TRUE;
}

void CGame::ClearBgmState()
{
    GlobalValues_Set(unk_14B4, 5, 0);
    GlobalValues_Set(unk_14B4, 6, 0);
    GlobalValues_Set(unk_14B4, 0x1A, -1);
}

void CGame::sub_02010448()
{
}

void CGame::FreeTextWindows()
{
    unk_1494->FreeWindows();
    unk_1498->FreeWindows();
}
