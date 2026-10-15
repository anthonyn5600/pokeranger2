#include "scene/CMapDispRscLoader.hpp"

#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "file/CArchiveGuard.hpp"

static void LoaderThreadMain(void *arg);

CMapDispRscLoader::CMapDispRscLoader()
{
    m_request = -1;
    unk_08 = NULL;
    m_pathBuilder = NULL;
    m_alarmAvailable = OS_IsAlarmAvailable();
    if (!m_alarmAvailable) {
        OS_InitAlarm();
    }
    OS_InitMessageQueue(&m_queue, m_messages, 1);
    OS_CreateThread(&m_thread, LoaderThreadMain, this, &m_stack[sizeof(m_stack)], sizeof(m_stack), 20);
    OS_WakeupThreadDirect(&m_thread);
}

CMapDispRscLoader::~CMapDispRscLoader()
{
    if (!OS_IsThreadTerminated(&m_thread)) {
        OS_SendMessage(&m_queue, (OSMessage)-1, OS_MESSAGE_BLOCK);
        OS_JoinThread(&m_thread);
    }
    if (!m_alarmAvailable) {
        OS_EndAlarm();
    }
    RestoreBG();
    SAFE_DELETE(unk_08);
}

void CMapDispRscLoader::SetupBG()
{
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    m_savedBGMode = (GXBGMode)GXS_GetDispCnt().bgMode;
    GXS_SetGraphicsMode(GX_BGMODE_3);
    G2S_SetBG3ControlDCBmp(GX_BG_SCRSIZE_DCBMP_256x256, GX_BG_AREAOVER_XLU, GX_BG_BMPSCRBASE_0x00000);
    MI_CpuFill16(G2S_GetBG3ScrPtr(), 0x8000, 0x18000);
    G2S_SetBG3Offset(0, 0);
    MtxFx22 mtx;
    MTX_Identity22(&mtx);
    G2S_SetBG3Affine(&mtx, 0, 0, 0, 0);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG3);
}

void CMapDispRscLoader::RestoreBG()
{
    GXS_SetGraphicsMode(m_savedBGMode);
}

BOOL CMapDispRscLoader::Request(int id)
{
    m_request = id;
    if (OS_SendMessage(&m_queue, (OSMessage)id, OS_MESSAGE_NOBLOCK)) {
        m_request = -1;
        return TRUE;
    }
    return FALSE;
}

void CMapDispRscLoader::Update()
{
    if (m_request < 0) {
        return;
    }
    if (OS_SendMessage(&m_queue, (OSMessage)m_request, OS_MESSAGE_NOBLOCK)) {
        m_request = -1;
    }
}

static inline BOOL LoadDCB(const char *archivePath, const char *filePath)
{
    CArchiveGuard archive("DCB", archivePath, 1, 1, CGame::GetInstance()->unk_14A8, NULL, 0);
    if (archive.unk_68 == NULL || archive.unk_68->unk_4C == NULL) {
        return FALSE;
    }
    char path[0x60];
    OS_SPrintf(path, "DCB:%s", filePath);
    CBinaryFile file(path, 1, 0, 0, NULL, 0);
    if (file.unk_4C == NULL) {
        return FALSE;
    }
    DC_FlushRange(file.unk_4C, file.unk_50);
    GXS_LoadBG3Scr(file.unk_4C, 0, file.unk_50);
    return TRUE;
}

BOOL CMapDispRscLoader::Load(int id)
{
    char archivePath[0x60];
    char filePath[0x60];
    if (m_pathBuilder != NULL && m_pathBuilder->GetArchivePath(id, archivePath, sizeof(archivePath)) && m_pathBuilder->GetFilePath(id, filePath, sizeof(filePath))) {
        if (LoadDCB(archivePath, filePath)) {
            return TRUE;
        }
    }
    return FALSE;
}

static void LoaderThreadMain(void *arg)
{
    CMapDispRscLoader *loader = (CMapDispRscLoader *)arg;
    if (loader == NULL) {
        return;
    }
    while (TRUE) {
        OSMessage msg;
        OS_ReceiveMessage(&loader->m_queue, &msg, OS_MESSAGE_BLOCK);
        int id = (int)msg;
        if (id < 0) {
            break;
        }
        BOOL cancel;
        BrightnessFade *fade = CGame::GetInstance()->m_subFade;
        if (fade->GetMode() != 4) {
            fade->Start(4, 30);
        }
        cancel = FALSE;
        while (fade->IsActive()) {
            OS_Sleep(17);
            if (OS_ReadMessage(&loader->m_queue, &msg, OS_MESSAGE_NOBLOCK)) {
                cancel = TRUE;
                break;
            }
        }
        if (!cancel) {
            loader->Load(id);
            fade->Start(3, 30);
        }
    }
}

BOOL CMapDispRscLoader::Quit()
{
    if (!OS_IsThreadTerminated(&m_thread) && OS_SendMessage(&m_queue, (OSMessage)-1, OS_MESSAGE_NOBLOCK)) {
        return TRUE;
    }
    return FALSE;
}

BOOL CMapDispRscLoader::IsDone()
{
    if (OS_IsThreadTerminated(&m_thread)) {
        return TRUE;
    }
    return FALSE;
}
