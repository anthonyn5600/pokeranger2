#include <dwc.h>

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "DiskHPTable.hpp"
#include "DwcConnection.hpp"
#include "MissionDownload.hpp"
#include "RangerNetMenu.hpp"
#include "heap.hpp"
#include "main.hpp"

// Ranger Net mission download over Nintendo WFC (021302D8..021319EC): the DWC connection (DwcConnection) and
// the download state machine (MissionDownload), built on the DWC_Nd download sample.

extern "C" void sub_020110E8(UnkClass_0201100C *obj);
extern "C" int sub_020110F8(UnkClass_0201100C *obj, int list);

static int sResult = 3;

static int sNdCleanupDone;
static int sNdError;
static int sNdDone;

static void *ov11_02130470(DWCAllocType name, u32 size, int align);
static void ov11_021304A4(DWCAllocType name, void *ptr, u32 size);
static void ov11_021316A8(DWCNdCallbackReason reason, DWCNdError error, int servererror);
static void ov11_021316C4();
static int ov11_021316D8();

DwcConnection::DwcConnection(CGame *game)
{
    unk_10 = game;
    ov11_02130310();
}

DwcConnection::~DwcConnection()
{
    if (unk_14 != NULL) {
        Heap_Free(unk_14);
    }
}

void DwcConnection::ov11_02130310()
{
    unk_14 = NULL;
}

int DwcConnection::ov11_0213031C()
{
    if (unk_14 != NULL) {
        Heap_Free(unk_14);
        unk_14 = NULL;
    }
    unk_14 = Heap_AllocWithAlignment(DWC_INIT_WORK_SIZE, 32);
    int ret = DWC_Init(unk_14);
    DWC_ClearError();
    if (unk_14 != NULL) {
        Heap_Free(unk_14);
        unk_14 = NULL;
    }
    DWC_SetMemFunc(ov11_02130470, ov11_021304A4);
    return ret;
}

void DwcConnection::ov11_0213038C()
{
    unk_00 = 0;
}

int DwcConnection::ov11_02130398()
{
    DWCApInfo apInfo;

    switch (unk_00) {
    case 0:
        if (ov11_0213031C() == DWC_INIT_RESULT_DESTROY_OTHER_SETTING) {
            return 1;
        }
        SetupInterrupts();
        DWC_InitInet(&unk_04);
        DWC_SetAuthServer(DWC_CONNECTINET_AUTH_RELEASE);
        DWC_ConnectInetAsync();
        unk_00 = 1;
        break;
    case 1:
        DWC_ProcessInet();
        DWC_GetInetStatus();
        if (!DWC_CheckInet()) {
            break;
        }
        unk_00 = 2;
    case 2:
        switch (DWC_GetInetStatus()) {
        case DWC_CONNECTINET_STATE_ERROR:
            return 2;
        case DWC_CONNECTINET_STATE_FATAL_ERROR:
            return 2;
        case DWC_CONNECTINET_STATE_CONNECTED:
            DWC_GetApInfo(&apInfo);
            return 0;
        }
        break;
    }
    return 3;
}

static void *ov11_02130470(DWCAllocType name, u32 size, int align)
{
    OSIntrMode mode = OS_DisableInterrupts();
    void *ptr = Heap_AllocWithAlignment(size, align);
    OS_RestoreInterrupts(mode);
    return ptr;
}

static void ov11_021304A4(DWCAllocType name, void *ptr, u32 size)
{
    Heap_Free(ptr);
}

void DwcConnection::ov11_021304B4()
{
    void *work = Heap_Alloc(DWC_UTILITY_WORK_SIZE);
    DWC_StartUtility(work, DWC_LANGUAGE_ENGLISH, DWC_UTILITY_TOP_MENU_FOR_USA);
    Heap_Free(work);
}

MissionDownload::MissionDownload(CGame *game, DwcConnection *dwc, RangerNetMenu *menu)
{
    unk_4DC = game;
    unk_4D8 = dwc;
    unk_4E0 = menu;
    ov11_02130B14();
}

MissionDownload::~MissionDownload()
{
    if (unk_4C0 != NULL) {
        Heap_Free(unk_4C0);
    }
}

int MissionDownload::ov11_0213051C()
{
    switch (unk_02C) {
    case 0:
    case 7:
    case 8:
        break;
    case 1:
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        unk_4D8->ov11_0213038C();
        unk_02C = 2;
        unk_4B8 = 0;
        unk_4E0->unk_710 = 1;
    case 2: {
        if (unk_4E0->ov11_0212247C() < 0) {
            sResult = 6;
            unk_02C = 6;
            unk_4E0->ov11_02124520();
            break;
        }
        int ret = unk_4D8->ov11_02130398();
        if (ret == 3) {
            break;
        }
        if (ret == 1) {
            sResult = 9;
            unk_02C = 6;
            unk_4C4 = 7200;
            unk_4E0->ov11_02124520();
            unk_4E0->ov11_02122B7C(15, 0, 0, 1);
            break;
        }
        if (ret == 2) {
            sResult = 8;
            unk_4E0->ov11_02124520();
            unk_02C = 6;
            break;
        }
        unk_02C = 3;
        unk_4B4 = 24;
        unk_4B8 = 0;
    }
    case 3:
        sResult = ov11_02130B48();
        switch (sResult) {
        case 6:
            unk_02C = 6;
            unk_4E0->ov11_02124520();
            if (unk_4B8 != 0) {
                unk_4E0->ov11_02122B7C(24, 0, 0, 1);
            }
            break;
        case 1:
            sResult = 1;
            unk_02C = 6;
            unk_4E0->ov11_02124520();
            break;
        case 8:
            unk_4E0->ov11_02124520();
            unk_4E0->ov11_0211EFB4();
            unk_02C = 6;
            break;
        case 0:
            unk_02C = 12;
            unk_4E0->ov11_02124520();
            break;
        case 4:
            unk_4E0->ov11_02124520();
            unk_02C = 6;
            unk_4C4 = 0;
            break;
        case 5:
            unk_4E0->ov11_02124520();
            unk_4E0->ov11_02122B7C(24, 0, 0, 1);
            unk_02C = 4;
            unk_4C4 = 0;
            break;
        case 7:
            unk_4E0->ov11_02124520();
            unk_4E0->ov11_0211EFB4();
            unk_02C = 6;
            unk_4C4 = 0;
            break;
        }
        break;
    case 4:
        unk_4C4 = 120;
        unk_02C = 5;
    case 5:
        if (--unk_4C4 <= 0) {
            unk_02C = 6;
        }
        break;
    case 6:
        unk_4C4 = 120;
        if (sResult == 5 || (sResult == 6 && unk_4B8 != 0)) {
            unk_4C4 = 0;
        }
        unk_4E0->ov11_02124520();
        sNdCleanupDone = FALSE;
        if (DWC_NdCleanupAsync(ov11_021316C4)) {
            unk_02C = 9;
        } else {
            DWC_CleanupInet();
            unk_02C = 10;
        }
        break;
    case 9:
        unk_4C4++;
        if (!sNdCleanupDone) {
            break;
        }
        DWC_CleanupInet();
        unk_02C = 10;
    case 10:
        if (++unk_4C4 >= 120) {
            unk_02C = 12;
            unk_4C4 = 0;
            switch (sResult) {
            case 1:
                unk_4E0->ov11_02122B7C(3, 0, 0, 1);
                break;
            case 7:
                unk_4E0->ov11_0211EFB4();
                unk_4E0->ov11_02122B7C(5, 5, 0, 1);
                break;
            case 6:
                if (unk_4B8 == 0) {
                    unk_02C = 11;
                } else {
                    unk_4E0->ov11_02122B7C(25, 0, 0, 1);
                    unk_4C4 = 120;
                    unk_02C = 11;
                }
                break;
            case 4:
                unk_4E0->ov11_02122B7C(49, 0, 0, 1);
                unk_4C4 = 0;
                unk_02C = 12;
                break;
            case 5:
                unk_4E0->ov11_02122B7C(48, 0, 0, 1);
                unk_4C4 = 0;
                unk_02C = 12;
                break;
            case 8:
                ov11_02131710();
                break;
            }
        }
        break;
    case 11:
        if (--unk_4C4 > 0) {
            break;
        }
        unk_4E0->ov11_02122B7C(15, 1, 0, 1);
        unk_02C = 12;
    case 12:
        switch (sResult) {
        case 1:
        case 4:
        case 5:
        case 8:
        case 9:
            if (unk_4E0->ov11_02122428()) {
                return 1;
            }
            break;
        case 6:
            if (unk_4E0->ov11_02122428()) {
                unk_4E0->ov11_0211FB08(0, -1);
                unk_4E0->ov11_02124520();
                return 3;
            }
            break;
        case 7:
            break;
        case 0:
        case 2:
        case 3:
        default:
            return 0;
        }
        break;
    case 13:
        ov11_02131710();
        unk_02C = 14;
        unk_4C4 = 7200;
        break;
    case 14:
        unk_4C4--;
        if (unk_4E0->ov11_02122428() || unk_4C4 <= 0) {
            unk_4C4 = 0;
            switch (sResult) {
            case 9:
                unk_02C = 6;
                break;
            default:
                unk_02C = 5;
                break;
            }
        }
        break;
    }
    return 2;
}

void MissionDownload::ov11_02130B14()
{
    unk_4C0 = NULL;
    unk_02C = 0;
    unk_4B4 = 24;
}

void MissionDownload::ov11_02130B30()
{
    unk_02C = 1;
    unk_4B4 = 24;
}

int MissionDownload::ov11_02130B48()
{
    char name[40];
    u32 received;
    u32 contentLen;

    if (unk_4E0->ov11_0212247C() < 0) {
        if (unk_4B8 == 0) {
            return 6;
        }
        unk_4E0->ov11_0211F96C();
        unk_4E0->ov11_0211FBE4(3);
        unk_4E0->ov11_02124438(0);
        unk_4E0->ov11_0211F904();
        unk_4E0->ov11_021217C0(11);
        unk_4E0->ov11_0211EFB4();
        unk_4B4 = 10;
        unk_4E0->ov11_02122B7C(23, 0, 0, 1);
        return 3;
    }
    switch (unk_4B4) {
    case 24:
        unk_4B8 = 0;
        unk_4B6 = 24;
        sNdError = 0;
        sNdDone = 0;
        if (!DWC_NASLoginAsync()) {
            return 8;
        }
        unk_4B4 = 25;
        unk_4C8 = 7200;
        break;
    case 25:
        switch (DWC_NASLoginProcess()) {
        case DWC_NASLOGIN_STATE_HTTP:
            return 3;
        case DWC_NASLOGIN_STATE_SUCCESS:
            unk_4B4 = 0;
            break;
        default:
            return 8;
        }
        break;
    case 0:
        sNdError = 0;
        sNdDone = 0;
        if (!DWC_NdInitAsync(ov11_021316A8, "YP2E", "griUBMRWtExs4ZNS")) {
            return 8;
        }
        unk_4B4 = 1;
        break;
    case 1:
        if (DWC_UpdateConnection()) {
            return 8;
        }
        if (!ov11_021316D8()) {
            break;
        }
        if (sNdError == 1) {
            return 8;
        }
        unk_4E0->ov11_02122B7C(2, 0, 0, 1);
        unk_4B8 = 1;
        unk_4B6 = 2;
        unk_4B4 = 4;
    case 4:
        if (ov11_02131980()) {
            return 8;
        }
        ov11_021316E8();
        sNdError = 0;
        sNdDone = 0;
        if (!DWC_NdGetFileListNumAsync(&unk_4B0)) {
            return 8;
        }
        unk_4B4 = 5;
        break;
    case 2:
        unk_4E0->ov11_02122B7C(2, 0, 0, 1);
        unk_4B4 = 5;
    case 5:
        if (ov11_02131980()) {
            return 8;
        }
        if (!ov11_021316D8()) {
            break;
        }
        if (sNdError == 1) {
            return 8;
        }
        if (unk_4B0 == 0) {
            return 1;
        }
        unk_4B4 = 6;
        unk_4B6 = 3;
    case 6:
        if (ov11_02131980()) {
            return 8;
        }
        sNdError = 0;
        sNdDone = 0;
        if (!DWC_NdGetFileListAsync(unk_038, 0, 6)) {
            return 8;
        }
        unk_4B4 = 7;
        break;
    case 3:
        unk_4E0->ov11_02122B7C(2, 0, 0, 1);
        unk_4B4 = 7;
    case 7: {
        if (ov11_02131980()) {
            return 8;
        }
        if (!ov11_021316D8()) {
            break;
        }
        if (sNdError == 1) {
            return 8;
        }
        if (unk_4B0 == 0 || unk_4B0 > 6) {
            return 1;
        }
        BOOL found = FALSE;
        for (int k = 0; k < 11; k++) {
            unk_484[k] = -1;
        }
        for (int i = 0; i < 11; i++) {
            OS_SPrintf(name, "PRS_MISSION_%02d.prs", i + 1);
            int j;
            for (j = 0; j < unk_4B0; j++) {
                if (strcmp(name, unk_038[j].name) == 0) {
                    unk_484[j] = i;
                    break;
                }
            }
            if (j >= unk_4B0) {
                unk_458[i] = -1;
            } else {
                found = TRUE;
                unk_458[i] = 1;
            }
        }
        if (!found) {
            return 1;
        }
        CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD2);
    }
    case 8:
        unk_4E0->ov11_021217D4(unk_458, TRUE, 6);
        unk_4B6 = 8;
        unk_4B4 = 9;
    case 9: {
        if (ov11_02131980()) {
            return 8;
        }
        int sel = unk_4E0->ov11_021212B4();
        if (sel < 0) {
            if (unk_4E0->unk_70C != 0) {
                unk_4C8 = 7200;
                break;
            }
            if (--unk_4C8 <= 0) {
                return 5;
            }
            break;
        }
        int i;
        for (i = 0; i < unk_4B0; i++) {
            if (sel - 11 == unk_484[i]) {
                break;
            }
        }
        if (i < unk_4B0) {
            unk_4BC = i;
        }
        unk_4B4 = 11;
    }
    case 11:
        if (ov11_02131980()) {
            return 8;
        }
        if (unk_4C0 != NULL) {
            Heap_Free(unk_4C0);
            unk_4C0 = NULL;
        }
        unk_4C0 = (char *)Heap_Alloc(unk_038[unk_4BC].size);
        if (unk_4C0 == NULL) {
            return 8;
        }
        sNdError = 0;
        sNdDone = 0;
        if (!DWC_NdGetFileAsync(&unk_038[unk_4BC], unk_4C0, unk_038[unk_4BC].size)) {
            return 8;
        }
        CGame::GetInstance()->m_audioEngine->PlaySe(0xD1);
        unk_034 = 0;
        unk_4D0 = 0;
        unk_4D4 = 0;
    case 12:
        unk_4E0->ov11_02122B7C(4, 0, 1, 1);
        unk_4E0->ov11_0211EF5C();
        unk_4B4 = 13;
        unk_4B6 = 12;
    case 13:
        if (ov11_02131980()) {
            return 8;
        }
        unk_4E0->ov11_0211F06C();
        if (sNdDone == 0) {
            if (DWC_NdGetProgress(&received, &contentLen) == TRUE && unk_4D4 != received) {
                unk_4D4 = received;
                unk_4D0 = 0;
                break;
            }
            if (++unk_4D0 >= 1800) {
                return 4;
            }
            break;
        }
        unk_4E0->ov11_0211FBE4(3);
        unk_4E0->ov11_02122B7C(45, 0, 1, 1);
        unk_4B4 = 16;
        unk_4C4 = 120;
        break;
    case 16:
        unk_4E0->ov11_0211F06C();
        if (--unk_4C4 <= 0) {
            unk_4E0->ov11_02122B7C(46, 0, 1, 1);
            unk_4B4 = 17;
            unk_4C4 = 120;
            sNdCleanupDone = FALSE;
            if (!DWC_NdCleanupAsync(ov11_021316C4)) {
                sNdCleanupDone = TRUE;
            }
            unk_4E0->unk_710 = 0;
        }
        break;
    case 17:
        unk_4E0->ov11_0211F06C();
        if (!sNdCleanupDone) {
            break;
        }
        if (unk_4C4 > 0) {
            unk_4C4--;
        }
        if (!DWC_CleanupInetAsync()) {
            break;
        }
        unk_4B4 = 18;
    case 18:
        unk_4E0->ov11_0211F06C();
        if (unk_4C4 > 0) {
            unk_4C4--;
        } else {
            unk_4E0->ov11_02122B7C(47, 0, 1, 1);
            unk_4B4 = 20;
            unk_4C4 = 120;
        }
        break;
    case 20:
        unk_4E0->ov11_0211F06C();
        if (--unk_4C4 <= 0) {
            unk_4E0->ov11_02122B7C(6, 0, 1, 1);
            unk_4B4 = 21;
            unk_4CC = 0;
        }
        break;
    case 21:
        unk_4E0->ov11_0211F06C();
        for (; unk_4CC < 6; unk_4CC++) {
            if (unk_4E0->ov11_02123D20(unk_4CC, unk_4C0, MAIN_BSS_020AF620.unk_00.unk_04)) {
                unk_4B4 = 22;
                sub_020110E8(unk_4E0->unk_620);
                break;
            }
        }
        if (unk_4CC >= 6) {
            unk_4B4 = 14;
            unk_4C4 = 0;
            unk_4E0->ov11_0211F0BC();
            CGame::GetInstance()->m_audioEngine->StopSe(0xD1);
            CGame::GetInstance()->m_audioEngine->PlaySe(0xF0);
        }
        break;
    case 22: {
        unk_4E0->ov11_0211F06C();
        int r = sub_020110F8(unk_4E0->unk_620, unk_4CC);
        if (r == 0) {
            break;
        }
        if (r == 1) {
            unk_4CC++;
            unk_4B4 = 21;
            break;
        }
        return 7;
    }
    case 14:
        if (++unk_4C4 >= 180) {
            unk_4E0->ov11_0212374C(unk_484[unk_4BC], FALSE);
            unk_4B4 = 15;
        }
        break;
    case 15:
        if (unk_4E0->ov11_02122428()) {
            return 0;
        }
        break;
    case 23:
        if (ov11_021316D8()) {
            return 2;
        }
        break;
    case 10:
        if (ov11_02131980()) {
            return 8;
        }
        switch (unk_4E0->ov11_02121168()) {
        case -2:
            if (unk_4E0->unk_70C != 0) {
                unk_4C8 = 7200;
                break;
            }
            if (--unk_4C8 <= 0) {
                return 5;
            }
            break;
        case 14:
            unk_4E0->ov11_02122B7C(0, 5, 3, 1);
            return 6;
        default:
            unk_4E0->ov11_0211F904();
            unk_4E0->ov11_0211F96C();
            unk_4B4 = unk_4B6;
            unk_4E0->ov11_0211FBE4(5);
            unk_4E0->ov11_02122B7C(0, 5, 3, 1);
            break;
        }
        break;
    case 19:
    default:
        break;
    }
    if (sNdError == 1) {
        return 8;
    }
    return 3;
}

static void ov11_021316A8(DWCNdCallbackReason reason, DWCNdError error, int servererror)
{
    sNdDone = TRUE;
    if (error != DWC_ND_ERROR_NONE) {
        sNdError = TRUE;
    }
}

static void ov11_021316C4()
{
    sNdCleanupDone = TRUE;
}

static int ov11_021316D8()
{
    return sNdDone;
}

void MissionDownload::ov11_021316E8()
{
    if (!DWC_NdSetAttr("", "", "")) {
        OS_Terminate();
    }
}

void MissionDownload::ov11_02131710()
{
    char buf[64];
    int code;
    int msg = 26;

    DWC_GetLastError(&code);
    code *= -1;
    if (code >= 20000 && code <= 20999) {
        switch (code) {
        case 20110:
            msg = 29;
            break;
        case 20101:
            msg = 27;
            break;
        case 20108:
            msg = 28;
            break;
        }
    } else if (code >= 23000 && code <= 23999) {
        msg = 27;
    } else if (code >= 52000 && code <= 53299) {
        switch (code) {
        case 52000:
        case 52001:
        case 52002:
        case 52003:
        case 52100:
        case 52102:
        case 52103:
        case 52104:
        case 52200:
        case 52201:
        case 52202:
        case 52203:
            msg = 39;
            break;
        }
    } else if (code >= 51200 && code <= 51299) {
        msg = 30;
    } else if (code >= 50000 && code <= 50099) {
        msg = 31;
    } else if (code >= 51000 && code <= 51099) {
        msg = 32;
    } else if (code >= 51100 && code <= 51199) {
        switch (code) {
        case 51103:
            msg = 33;
            break;
        default:
            msg = 32;
            break;
        }
    } else if (code >= 51300 && code <= 51399) {
        msg = 32;
    } else {
        msg = 34;
    }
    unk_4E0->ov11_021234A8(buf, code, -1);
    unk_4E0->ov11_02122BA8(buf, FALSE);
    unk_4E0->ov11_02122B7C(msg, 0, 0, 1);
}

BOOL MissionDownload::ov11_02131980()
{
    int code;
    DWCErrorType type;

    if (sNdError) {
        return TRUE;
    }
    if (DWC_UpdateConnection()) {
        return TRUE;
    }
    if (DWC_GetLastErrorEx(&code, &type)) {
        return TRUE;
    }
    if (type != DWC_ETYPE_NO_ERROR) {
        return TRUE;
    }
    return FALSE;
}
