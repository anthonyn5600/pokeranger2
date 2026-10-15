#include <nitro/wm.h>
#include <nitro/wvr.h>

#include "common.hpp"
#include "heap.hpp"

// D5: WH user layer: WVR start-up, beacon info, parent tick (02128F18..021298C4)

// defined in RangerNetPlayerInfo.cpp
struct RangerNetSessionParam {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u8 unk_14[0xC];
};

// beacon userGameInfo (0x5C bytes)
struct D5Beacon {
    u32 unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    union {
        u8 raw[0x54];
        struct {
            u8 unk_08[0x8];
            RangerNetSessionParam param;
            u8 unk_30[0x24];
            u8 unk_54;
            u8 unk_55[0x7];
        } info;
    } unk_08;
};

struct D5Work {
    D5Beacon beacon;
    u8 unk_05C[0x84];
    u8 unk_0E0[0x54];
    u8 unk_134[0xC00];
    u8 unk_D34[8][6];
    u8 unk_D64[0x20];
    void *unk_D84;
    int unk_D88;
    u8 unk_D8C;
    u8 unk_D8D[0x3];
    RangerNetSessionParam *unk_D90;
    u32 unk_D94;
    u16 unk_D98;
    u16 unk_D9A;
    u8 unk_D9C;
    u8 unk_D9D;
    u8 unk_D9E;
    u8 unk_D9F;
    u8 unk_DA0;
    u8 unk_DA1_0 : 1;
    u8 unk_DA1_1 : 1;
    u8 unk_DA1_2 : 1;
    u8 unk_DA1_3 : 1;
    u8 unk_DA1_4 : 1;
    u8 unk_DA1_5 : 1;
};

static u16 sTgid;
static int sWvrState;
static D5Work *sWork;

// RangerNetWh.cpp
u32 WH_GetHeapSize();
BOOL WH_Initialize();
void WH_SetGgid(u32 ggid);
void WH_SetUserGameInfo(void *info, u16 length);
u16 WH_GetBitmap();
int WH_GetSystemState();
int WH_GetLastError();
BOOL WH_StartMeasureChannel();
u16 WH_GetMeasureChannel();
BOOL WH_ParentConnect(int mode, u16 tgid, u16 channel, u16 maxEntry, u16 beaconPeriod, int entryFlag);
void WH_SetReceiver(void (*proc)(u16 aid, u16 *data, u16 size), int port);
void WH_Finalize();
BOOL WH_End();
u16 WH_GetCurrentAid();
BOOL WH_IsSysStateIdle();
BOOL WH_IsSysStateBusy();
BOOL WH_IsSysStateError();
BOOL WH_IsSysStateScan();
BOOL WH_EndScan();
void WH_SetGameInfo(void *info, int length, u32 ggid, int tgid);
void WH_ResetBeaconCount();
u8 WH_GetPauseConnection();
// RangerNetPlayerInfo.cpp, RangerNetSession.cpp
void CommInfo_ResetDisconnected();
int CommManager_GetCommType();
u8 CommManager_GetContestRegulation();

void CommSys_ServerRecvCallback(u16 aid, u16 *data, u16 size); // D7
u32 RangerNetSessionParam_Size();
u16 CommLocal_MaxMachines(u16 mode);

void WirelessDriver_InitCallback(void *arg, WVRResult result);
void WirelessDriver_ShutdownCallback(void *arg, WVRResult result);
void CommServerClient_IndCallback(void *arg);
void CommServerClient_InitWireless();
void CommServerClient_Free();
void CommServerClient_SetUserGameInfo();
void CommServerClient_UpdateBeaconCount();
u16 CommServerClient_ConnectedCount();
int CommServerClient_IsClientConnecting();
u16 CommServerClient_GetBeaconPeriod(u16 mode);
RangerNetSessionParam *CommServerClient_GetSessionParam();
void CommServerClient_RefreshGameInfo();

void CommServerClient_FatalError(int code)
{
    while (TRUE) {
    }
}

void CommServerClient_Init(RangerNetSessionParam *param)
{
    if (sWork != NULL) {
        return;
    }
    sWork = (D5Work *)Heap_AllocWithAlignment(sizeof(D5Work), 32);
    MI_CpuFill8(sWork, 0, sizeof(D5Work));
    sWork->unk_D84 = Heap_AllocWithAlignment(WH_GetHeapSize(), 32);
    MI_CpuFill8(sWork->unk_D84, 0, WH_GetHeapSize());
    sWork->unk_D94 = 0x333;
    sWork->unk_D90 = param;
    CommServerClient_InitWireless();
}

void WirelessDriver_InitCallback(void *arg, WVRResult result)
{
    if (result != WVR_RESULT_SUCCESS) {
        OS_Terminate();
    }
    sWvrState = 2;
}

void WirelessDriver_ShutdownCallback(void *arg, WVRResult result)
{
    sWvrState = 0;
}

void WirelessDriver_Init()
{
    sWvrState = 1;
    if (WVR_StartUpAsync(GX_VRAM_ARM7_128_C, WirelessDriver_InitCallback, NULL) != WVR_RESULT_OPERATING) {
        OS_Terminate();
    }
}

BOOL WirelessDriver_IsReady()
{
    return sWvrState == 2;
}

WVRResult WirelessDriver_Shutdown()
{
    return WVR_TerminateAsync(WirelessDriver_ShutdownCallback, NULL);
}

void CommServerClient_IndCallback(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;
    if (cb->state != 16) {
        return;
    }
    if (sWork != NULL) {
        sWork->unk_D88 = 2;
    }
}

void CommServerClient_InitWireless()
{
    sWork->unk_D88 = 0;
    WH_Initialize();
    WM_SetIndCallback(CommServerClient_IndCallback);
    WH_SetGgid(sWork->unk_D94);
}

void CommServerClient_SetIncTgid(int flag)
{
    sWork->unk_DA1_3 = flag;
}

void CommServerClient_ResetState()
{
    sWork->unk_D8C = 0;
    sWork->unk_DA1_0 = 0;
    sWork->unk_DA1_2 = 0;
    sWork->unk_D9E = 0;
    sWork->unk_DA1_4 = 0;
    sWork->unk_DA0 = 0;
    sWork->unk_D9F = 0;
}

BOOL CommServerClient_InitServer(int arg, int flag3, int flag5)
{
    CommServerClient_ResetState();
    CommServerClient_SetIncTgid(flag3);
    WH_ResetBeaconCount();
    if (sWork->unk_D9F == 0) {
        WH_SetReceiver(CommSys_ServerRecvCallback, 14);
        sWork->unk_D9F = 1;
    }
    sWork->unk_DA1_5 = flag5;
    if (WH_GetSystemState() == 1 && WH_StartMeasureChannel()) {
        return TRUE;
    }
    return FALSE;
}

BOOL CommServerClient_StepFinalize()
{
    if (sWork == NULL) {
        return TRUE;
    }
    switch (sWork->unk_DA0) {
    case 0:
        if (WH_IsSysStateScan()) {
            WH_EndScan();
            sWork->unk_DA0 = 1;
        } else if (!WH_IsSysStateBusy()) {
            WH_Finalize();
            sWork->unk_DA0 = 2;
        }
        break;
    case 1:
        if (!WH_IsSysStateBusy()) {
            WH_Finalize();
            sWork->unk_DA0 = 2;
        }
        break;
    case 2:
        if (WH_IsSysStateIdle()) {
            return TRUE;
        }
        if (WH_IsSysStateError()) {
            sWork->unk_DA0 = 1;
        }
        break;
    }
    return FALSE;
}

BOOL CommServerClient_RequestEnd()
{
    if (sWork != NULL && sWork->unk_D9E == 0) {
        sWork->unk_D9E = 1;
        WH_Finalize();
        return TRUE;
    }
    return FALSE;
}

void CommServerClient_Free()
{
    if (sWork->unk_D84 != NULL) {
        Heap_Free(sWork->unk_D84);
        sWork->unk_D84 = NULL;
    }
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void CommServerClient_SetUserGameInfo()
{
    int mode = CommManager_GetCommType();
    RangerNetSessionParam *param = CommServerClient_GetSessionParam();
    if (mode != 0xF) {
        D5Beacon *beacon = &sWork->beacon;
        MI_CpuCopy8(param, &beacon->unk_08.info.param, RangerNetSessionParam_Size());
        beacon->unk_00 = param->unk_10;
        beacon->unk_04 = CommManager_GetCommType();
        beacon->unk_08.info.unk_54 = WH_GetPauseConnection();
    } else {
        D5Beacon *beacon = &sWork->beacon;
        beacon->unk_00 = param->unk_10;
        beacon->unk_04 = CommManager_GetCommType();
        beacon->unk_05 = CommManager_GetContestRegulation();
        MI_CpuCopy8(sWork->unk_0E0, beacon->unk_08.raw, sizeof(beacon->unk_08.raw));
    }
    DC_FlushRange(sWork, sizeof(D5Beacon));
    WH_SetUserGameInfo(sWork, sizeof(D5Beacon));
}

void CommServerClient_UpdateBeaconCount()
{
    D5Beacon *beacon = &sWork->beacon;
    if (beacon->unk_06 == CommServerClient_ConnectedCount()) {
        return;
    }
    beacon->unk_06 = CommServerClient_ConnectedCount();
    DC_FlushRange(sWork, sizeof(D5Beacon));
    WH_SetUserGameInfo(sWork, sizeof(D5Beacon));
    WH_SetGameInfo(sWork, sizeof(D5Beacon), sWork->unk_D94, sTgid);
}

void CommServerClient_UpdateInternal(u16 vcount)
{
    int state = WH_GetSystemState();
    CommInfo_ResetDisconnected();
    CommServerClient_UpdateBeaconCount();
    if (WH_GetCurrentAid() == 0 && CommServerClient_IsClientConnecting() == 0) {
        if (sWork->unk_DA1_2) {
            sWork->unk_DA1_0 = 1;
        }
    }
    if (sWork->unk_D9A == 0xFFFF) {
        sWork->unk_D9A = vcount;
    }
    if (sWork->unk_DA1_1 && sWork->unk_D9A > vcount) {
        sWork->unk_DA1_0 = 1;
    }
    if (WH_GetLastError() == 0x19) {
        CommServerClient_FatalError(0);
    }
    switch (state) {
    case 0:
        if (sWork->unk_D9E == 1) {
            CommServerClient_Free();
        } else if (sWork->unk_D9E == 2) {
            sWork->unk_D9E = 3;
        }
        break;
    case 1:
        if (sWork->unk_D9E == 1 && WH_End()) {
            return;
        }
        if (sWork->unk_D9E == 2 && WH_End()) {
            return;
        }
        break;
    case 8:
    case 9:
        if (sWork != NULL) {
            sWork->unk_DA1_0 = 1;
        }
        break;
    case 7: {
        u16 channel = WH_GetMeasureChannel();
        if (sWork->unk_D9D != 0) {
            sWork->unk_D9D--;
        } else {
            sWork->unk_D98 = channel;
            sWork->unk_D9D = 5;
        }
        channel = sWork->unk_D98;
        if (sWork->unk_DA1_3) {
            sTgid++;
        }
        CommServerClient_SetUserGameInfo();
        WH_ParentConnect(0, sTgid, channel, CommLocal_MaxMachines(CommManager_GetCommType()), CommServerClient_GetBeaconPeriod(CommManager_GetCommType()), sWork->unk_DA1_5);
        sWork->unk_D9C = channel;
        break;
    }
    }
}

void CommServerClient_Update(u16 vcount)
{
    if (sWork == NULL) {
        return;
    }
    CommServerClient_UpdateInternal(vcount);
}

BOOL CommServerClient_IsConnected(u16 aid)
{
    if (sWork == NULL) {
        return FALSE;
    }
    if (WH_GetSystemState() != 4) {
        return FALSE;
    }
    if (WH_GetBitmap() & (1 << aid)) {
        return TRUE;
    }
    return FALSE;
}

u16 CommServerClient_ConnectedCount()
{
    u16 count = 0;
    for (u16 i = 0; i < 8; i++) {
        if (CommServerClient_IsConnected(i)) {
            count++;
        }
    }
    return count;
}

BOOL CommServerClient_IsInitialized()
{
    return sWork != NULL;
}

int CommServerClient_IsClientConnecting()
{
    if (sWork == NULL) {
        return 0;
    }
    return WH_GetBitmap() & 0xFFFE;
}

u16 CommServerClient_GetBeaconPeriod(u16 mode)
{
    u16 period = WM_GetDispersionBeaconPeriod();
    if (mode == 10) {
        return period / 4;
    } else if (mode == 9 || mode == 13) {
        return period / 4;
    }
    return period;
}

RangerNetSessionParam *CommServerClient_GetSessionParam()
{
    return sWork->unk_D90;
}

void CommServerClient_SetMacAddress(const u8 *mac, int idx)
{
    if (sWork == NULL) {
        return;
    }
    MI_CpuCopy8(mac, sWork->unk_D34[idx], 6);
}

BOOL CommServerClient_IsEnding()
{
    return sWork != NULL ? sWork->unk_DA1_4 : FALSE;
}

void CommServerClient_SetEnding()
{
    if (sWork != NULL) {
        sWork->unk_DA1_4 = 1;
    }
}

void CommServerClient_RefreshGameInfo()
{
    CommServerClient_SetUserGameInfo();
    WH_SetGameInfo(sWork, sizeof(D5Beacon), sWork->unk_D94, sTgid);
}

void CommServerClient_SetBeaconData(const void *src)
{
    MI_CpuCopy8(src, sWork->unk_0E0, sizeof(sWork->unk_0E0));
    CommServerClient_RefreshGameInfo();
}
