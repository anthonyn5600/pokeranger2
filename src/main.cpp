#include "main.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "CPowerManage.hpp"
#include "PcDebug.hpp"
#include "constants/scene.hpp"
#include "heap.hpp"
#include "overlay_manager.hpp"
#include "sub_0202B80C.hpp"
#include "sub_0204436C.hpp"
#include "sub_02044440.hpp"
#include "sub_02046D40.hpp"

extern "C" {

extern u32 DAT_04000454;
extern u8 DAT_0208aaf8;
}

static CScene *RestartGame(void);
static void PrepareSceneDisplay(void);
static void sub_0200120C(u64 arg0);
static void InitSystem(void);
static void VBlankIntr(void);
static void HBlankIntr_1(s32 vcount, WindowWipe *arg1);
static void HBlankIntr(void);

CGame *s_game;
static u32 MAIN_BSS_0208F300;
static OSTick MAIN_BSS_0208F308;

void NitroMain(void)
{
    SaveData *game_unk_14A4;
    NNSFndHeapHandle *handle;
    CScene *v3;
    u32 v6;
    u32 v4;
    BrightnessFade *v7;
    BrightnessFade *v8;
    WindowWipe *v9;
    WindowWipe *v10;
    u32 v11;
    u32 v12;
    u32 v13;
    OSTick v14;

    InitSystem();
    SetupInterrupts();

    s_game = new CGame();
    DetectCardBackup();

    game_unk_14A4 = s_game->unk_14A4;
    game_unk_14A4->unk_8B68 = 1;
    game_unk_14A4->unk_8B6C = 0;

    handle = Heap_GetMainHandle();
    NNS_FndGetTotalFreeSizeForExpHeap(*handle);

    handle = Heap_GetMainHandle();
    NNS_FndGetAllocatableSizeForExpHeapEx(*handle, 4);

    PrepareSceneDisplay();
#ifdef PC_PORT
    v3 = Scene_LoadByID(PcDebug_StartScene(SCENE_RANGER_NET_AGB), s_game);
#else
    v3 = Scene_LoadByID(SCENE_RANGER_NET_AGB, s_game);
#endif
    v4 = SCENE_NONE;
    CPowerManage::Initialize();
    CPowerManage::SetMode(0);

    v6 = v4;
    v7 = s_game->m_mainFade;
    v8 = s_game->m_subFade;
    v9 = s_game->m_mainWipe;
    v10 = s_game->m_subWipe;

    while (1) {
        if (
            (v7->IsActive() != 0)
            || (v7->GetMode() == 2)
            || (v7->GetMode() == 4)
            || (v8->IsActive() != 0)
            || (v8->GetMode() == 2)
            || (v8->GetMode() == 4)
            || (v9->func0() != FALSE)
            || (v9->sub_0200E91C() != 0)
            || (v10->func0() != FALSE)
            || (v10->sub_0200E91C() != 0)) {
            CPowerManage::BlockSleep(1);
        } else {
            CPowerManage::AllowSleep(1);
        }

        CPowerManage::Process();
        s_game->unk_0014->Update();
        s_game->touchPanel->func0();
        s_game->touchPanelEmulator->func0();

        s_game->func0();

        s_game->unk_0C24->ClearArea(0, 0, 0x20, 0x18);
        s_game->unk_0C28->ClearArea(0, 0, 0x20, 0x18);
        G3X_Reset();

        G3_Identity();

        if (MAIN_BSS_0208F300 != 0) {
            v3 = RestartGame();
            MAIN_BSS_0208F300 = 0;
        }

        if (v4 != v6) {
            OS_GetTick();
            OS_DisableIrqMask(1);
            s_game->PrintHeapInfo("Delete Scene");

            DAT_0208aaf8 = 0;

            v13 = v3->getSceneId();
            s_game->unk_0008 = v13;
            s_game->unk_0010 = v4;

            v3->func7();
            delete v3;

            s_game->unk_0010 = v6;
            s_game->InitVramTransfer();
            s_game->FreeTextWindows();

            handle = Heap_GetMainHandle();
            NNS_FndGetTotalFreeSizeForExpHeap(*handle);

            handle = Heap_GetMainHandle();
            NNS_FndGetAllocatableSizeForExpHeapEx(*handle, 4);

            s_game->PrintHeapInfo("Create Scene");
            PrepareSceneDisplay();

            v3 = Scene_LoadByID(v4, s_game);
            OS_GetTick();
            s_game->PrintHeapInfo("Scene Create Finished");

            OS_EnableIrqMask(1);
        }

        MAIN_BSS_0208F308 = OS_GetTick();
        s_game->unk_15E0 = 0;
        v4 = v3->func0();
        v3->func1();
        s_game->unk_15E0 = 1;

        v14 = OS_GetTick();
        MAIN_BSS_0208F308 = v14 - MAIN_BSS_0208F308;

        v14 = OS_GetTick();
        DAT_0208aaf8 = 1;

        s_game->unk_15E0 = 0;
        v3->func4();
        s_game->unk_15E0 = 1;
        G3_SwapBuffers(GX_SORTMODE_MANUAL, GX_BUFFERMODE_Z);

        OS_GetTick();
        OS_GetTick();

        s_game->unk_146C.WaitFrame();

        OS_GetTick();
        OS_GetTick();

        v3->func2();

        OS_GetTick();
        ++s_game->unk_0000;

        OS_GetTick();
        v3->func3();

        s_game->UpdateBarScroll();
        OS_GetTick();
    }
}

void RequestRangerNetAGB(void)
{
    MAIN_BSS_0208F300 = 1;
}

CScene *RestartGame(void)
{
    CScene *currentScene = s_game->currentScene;
    if (currentScene != NULL) {
        currentScene->func7();
        delete currentScene;
    }

    s_game->ResetForRestart();

    SaveData *game_unk_14A4 = s_game->unk_14A4;
    game_unk_14A4->unk_8B68 = 1;
    game_unk_14A4->unk_8B6C = 0;

    PrepareSceneDisplay();
    Scene_LoadByID(SCENE_RANGER_NET_AGB, s_game);
}

void PrepareSceneDisplay(void)
{
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);

    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_OBJ);

    s_game->sub_02010448();
}

void sub_0200120C(u64 arg0)
{
}

void ReportFrameTime(void)
{
    sub_0200120C(OS_TicksToMicroSeconds(MAIN_BSS_0208F308));
}

void InitSystem(void)
{
    OS_Init();
    FX_Init();
    OS_InitTick();
    FS_Init(2);
    GX_Init();
    G3X_Init();
    RTC_Init();
#ifdef PC_PORT
    Heap_Init(0xB0000 + 0x10000); // room for the larger sound archive heap (src/AudioEngine.cpp)
#else
    Heap_Init(0xB0000);
#endif
    InitScriptRandom();
    Script_InitSyscalls();
    CRYPTO_SetAllocator(Heap_Alloc, Heap_Free);
}

void SetupInterrupts(void)
{
    OS_SetIrqFunction(OS_IE_V_BLANK, VBlankIntr);
    OS_EnableIrqMask(OS_IE_V_BLANK);
    GX_VBlankIntr(TRUE);

    OS_SetIrqFunction(OS_IE_H_BLANK, HBlankIntr);
    OS_EnableIrqMask(OS_IE_H_BLANK);
    GX_HBlankIntr(TRUE);

    OS_EnableIrq();
}

void VBlankIntr(void)
{
    u16 wasIrqEnabled = OS_EnableIrq();

    if (s_game != NULL) {
        s_game->OnVBlank();
    }

    if (wasIrqEnabled) {
        OS_EnableIrq();
    } else {
        OS_DisableIrq();
    }

    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

void inline HBlankIntr_1(s32 vcount, WindowWipe *arg1)
{
    if (arg1->func0()) {
        u32 idx = vcount + 1;
        u16 v13 = arg1->unk_0860[arg1->unk_001C][idx];

        if (GX_IsHBlank()) {
            *arg1->unk_0020 = v13;
        }
    }
}

void HBlankIntr(void)
{
    s32 vcount = GX_GetVCount();

    if (vcount < GX_LCD_SIZE_Y - 1 && s_game != NULL) {
        HBlankIntr_1(vcount, s_game->m_mainWipe);
        HBlankIntr_1(vcount, s_game->m_subWipe);
    }

    OS_SetIrqCheckFlag(OS_IE_H_BLANK);
}
