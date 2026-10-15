#include <nitro/math.h>
#include <nitro/rtc.h>

#include "RangerNetComm.hpp"
#include "common.hpp"
#include "heap.hpp"

// Ranger Net packet layer over WH (02129B60..0212C304): double-buffered send/receive frames, command parsing.
// The same library as pokeplatinum's communication_system.c (the DP-era comm code).

struct CommRecvState {
    int unk_0;
    u8 *unk_4;
    u16 unk_8;
    u8 unk_A;
};

struct CommSystem {
    u8 unk_000[2][0x26];
    u8 unk_04C[0x108];
    u8 unk_154[2][0xC0];
    u8 unk_2D4[0x180];
    u8 *unk_454;
    u8 *unk_458;
    u8 *unk_45C;
    u8 *unk_460;
    CommRing unk_464;
    CommRing unk_470;
    CommRing unk_47C[8];
    CommRing unk_4DC;
    CommRing unk_4E8[8];
    CommQueueMan unk_548;
    CommQueueMan unk_568;
    CommRecvState unk_588[8];
    CommRecvState unk_5E8;
    MATHRandContext32 unk_5F4;
    u16 unk_60C[8];
    u8 unk_61C[0x8];
    u16 unk_624;
    u8 unk_626;
    u8 unk_627;
    u8 unk_628;
    u8 unk_629;
    u8 unk_62A[0x2];
    int unk_62C;
    int unk_630;
    int unk_634[8];
    int unk_654;
    u16 unk_658;
    u8 unk_65A;
    u8 unk_65B[8];
    u8 unk_663[8];
    u8 unk_66B[8];
    u8 unk_673[4];
    u8 unk_677;
    u8 unk_678;
    u8 unk_679;
    u8 unk_67A;
    u8 unk_67B;
    u8 unk_67C;
    u8 unk_67D;
    u8 unk_67E;
    u8 unk_67F;
    u8 unk_680;
    u8 unk_681;
    u8 unk_682;
    u8 unk_683;
    u8 unk_684;
    u8 unk_685;
    u8 unk_686;
    u8 unk_687;
};

static u8 sActive;
static CommSystem *sWork;
// send states of the client (0x26-byte frames) and server (0xC0-byte frames) side; two objects, not an array:
// 02129D64's reload of sWork after the second store only schedules like the original that way
static volatile u8 sClientSendState = 4;
static volatile u8 sServerSendState = 4;

// RangerNetWh.cpp ... RangerNetShared.cpp
int WH_GetSystemState();
void Connect_Update();
void CommInfo_Delete();
int CommManager_GetCommType();
void CommManager_Update();
BOOL CommServerClient_InitServer(int arg, int flag3, int flag5);
BOOL CommServerClient_RequestEnd();
void CommServerClient_Update(u16 vcount);
BOOL CommServerClient_IsInitialized();
void CommServerClient_SetEnding();
u16 WH_GetCurrentAid();
u16 WH_GetBitmap();
int CommServerClient_IsClientConnecting();
BOOL CommServerClient_IsEnding();
void CommTool_Init(int arg);
void CommTool_Delete();
void CommTiming_Update();
extern "C" BOOL thunk_FUN_overlay_11__02127904(const void *data, u16 size, int port, void (*callback)(BOOL result));

u16 CommLocal_MaxMachines(u16 mode); // D8
void CommCmd_Callback(int netId, int cmd, int size, void *data); // RangerNetCommCmd.cpp
u16 CommCmd_PacketSizeOf(int cmd);
BOOL CommCmd_HasRecvBuffer(int cmd);
u8 *CommCmd_GetRecvBuffer(int cmd, int netId, int size);

void CommSys_ResetData();
void CommSys_ClearData();
void CommSys_ClearServerRecvData(u16 aid);
void CommSys_ClearDisconnectedClients();
void CommSys_UpdateTransitionType();
u8 CommSys_TransmissionType();
void CommSys_Delete();
void CommSys_UpdateSend();
void CommSys_UpdateEnd();
void CommSys_UpdateClient();
BOOL CommSys_BuildParallelServerFrame(u8 frame);
void CommSys_UpdateServerClient();
void CommSys_RecvFromServer(u16 aid, u8 *data, u16 size);
void CommSys_RecvFromClient(u16 aid, u8 *data, u16 size);
void CommSys_ClientSendCallback(BOOL result);
void CommSys_ServerSendCallback(BOOL result);
BOOL CommSys_DecodeKeys(u8 *data, int aid);
BOOL CommSys_EncodeKeys(u8 *hdr);
BOOL CommSys_SendDataHuge(u8 cmd, u8 *data, u16 size);
BOOL CommSys_SendData(u8 cmd, u8 *data, u16 size);
BOOL CommSys_SendDataServer(u8 cmd, u8 *data, u16 size);
BOOL CommSys_IsSendingMovementData();
void CommSys_SetError();
void CommSys_EndCallback(int aid, int cmd, int size, u8 *data, CommRecvState *pending);
BOOL CommSys_IsInitialized();
BOOL CommSys_SendDataFixedSize(u8 cmd, u8 *data);
void CommSys_SwitchTransitionType(u8 mode);
void CommSys_BuildServerFrame(u8 *frame);
int CommSys_GetPacketSize(u16 mode);
void CommSys_UpdateServer();
void CommSys_SendClientFrame();
BOOL CommSys_BuildClientFrame(u8 *frame);
void CommSys_RecvData();
void CommSys_RecvDataServer();
BOOL CommSys_IsPlayerConnected(u16 aid);
void CommSys_Transmission();
u16 CommSys_CurNetId();
BOOL CommSys_IsAlone();
void CommSys_Seed(MATHRandContext32 *ctx);

BOOL CommSys_Init(BOOL keep, int size)
{
    BOOL reset = FALSE;
    sActive = 0;
    if (keep) {
        int n = CommLocal_MaxMachines(CommManager_GetCommType()) + 1;
        if (sWork != NULL) {
            return TRUE;
        }
        CommTool_Init(0);
        sWork = (CommSystem *)Heap_Alloc(sizeof(CommSystem));
        MI_CpuFill8(sWork, 0, sizeof(CommSystem));
        sWork->unk_654 = size + 0x40;
        sWork->unk_679 = 0;
        sWork->unk_67A = 0x1B;
        sWork->unk_45C = (u8 *)Heap_Alloc(sWork->unk_654 * 2);
        sWork->unk_460 = (u8 *)Heap_Alloc(sWork->unk_654);
        sWork->unk_458 = (u8 *)Heap_Alloc(n * sWork->unk_654);
        sWork->unk_454 = (u8 *)Heap_Alloc(n * sWork->unk_654);
        if (CommManager_GetCommType() == 10) {
            CommQueueMan_Init(&sWork->unk_548, 100, &sWork->unk_464);
            CommQueueMan_Init(&sWork->unk_568, 800, &sWork->unk_4DC);
        } else {
            CommQueueMan_Init(&sWork->unk_548, 20, &sWork->unk_464);
            CommQueueMan_Init(&sWork->unk_568, 280, &sWork->unk_4DC);
        }
    } else {
        reset = TRUE;
    }
    sWork->unk_658 = 0;
    for (int i = 0; i < 4; i++) {
        sWork->unk_673[i] = 0xFF;
    }
    if (!reset) {
        CommSys_ResetData();
    }
    CommSys_Seed(&sWork->unk_5F4);
    sWork->unk_683 = 0;
    return TRUE;
}

void CommSys_ResetData()
{
    int i;

    sWork->unk_628 = 0;
    sWork->unk_629 = 0;
    sWork->unk_67B = 0;
    sWork->unk_67C = 0;
    int n = CommLocal_MaxMachines(CommManager_GetCommType()) + 1;
    MI_CpuFill8(sWork->unk_458, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        CommRing_Init(&sWork->unk_4E8[i], sWork->unk_458 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_454, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        CommRing_Init(&sWork->unk_47C[i], sWork->unk_454 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_2D4, 0, sizeof(sWork->unk_2D4));
    CommRing_Init(&sWork->unk_4DC, sWork->unk_2D4, sizeof(sWork->unk_2D4));
    for (i = 0; i < 0xC0; i++) {
        sWork->unk_154[0][i] = 0xEE;
        sWork->unk_154[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_04C, 0, sizeof(sWork->unk_04C));
    CommRing_Init(&sWork->unk_464, sWork->unk_04C, sizeof(sWork->unk_04C));
    sWork->unk_000[0][0] = 0xFF;
    sWork->unk_000[1][0] = 0xFF;
    for (i = 1; i < 0x26; i++) {
        sWork->unk_000[0][i] = 0xEE;
        sWork->unk_000[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_45C, 0, sWork->unk_654 * 2);
    CommRing_Init(&sWork->unk_470, sWork->unk_45C, sWork->unk_654 * 2);
    sWork->unk_680 = 0;
    sWork->unk_681 = 0;
    for (i = 0; i < 8; i++) {
        sWork->unk_65B[i] = 0;
        sWork->unk_663[i] = 1;
        sWork->unk_66B[i] = 1;
        sWork->unk_60C[i] = 0;
        sWork->unk_588[i].unk_A = 0xEE;
        sWork->unk_588[i].unk_8 = 0xFFFF;
        sWork->unk_588[i].unk_4 = NULL;
        sWork->unk_588[i].unk_0 = 0;
        sWork->unk_634[i] = 0;
    }
    sWork->unk_630 = 0;
    sWork->unk_62C = 1;
    sWork->unk_5E8.unk_A = 0xEE;
    sWork->unk_5E8.unk_8 = 0xFFFF;
    sWork->unk_5E8.unk_4 = NULL;
    sWork->unk_5E8.unk_0 = 0;
    sWork->unk_67E = 1;
    sWork->unk_67F = 1;
    sServerSendState = 4;
    sClientSendState = 4;
    CommQueueMan_Reset(&sWork->unk_548);
    CommQueueMan_Reset(&sWork->unk_568);
    sWork->unk_684 = 0;
}

void CommSys_ClearData()
{
    int i;

    sWork->unk_628 = 0;
    sWork->unk_629 = 0;
    int n = CommLocal_MaxMachines(CommManager_GetCommType()) + 1;
    MI_CpuFill8(sWork->unk_458, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        CommRing_Init(&sWork->unk_4E8[i], sWork->unk_458 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_454, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        CommRing_Init(&sWork->unk_47C[i], sWork->unk_454 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_2D4, 0, sizeof(sWork->unk_2D4));
    CommRing_Init(&sWork->unk_4DC, sWork->unk_2D4, sizeof(sWork->unk_2D4));
    for (i = 0; i < 0xC0; i++) {
        sWork->unk_154[0][i] = 0xEE;
        sWork->unk_154[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_04C, 0, sizeof(sWork->unk_04C));
    CommRing_Init(&sWork->unk_464, sWork->unk_04C, sizeof(sWork->unk_04C));
    sWork->unk_000[0][0] = 0xFF;
    sWork->unk_000[1][0] = 0xFF;
    for (i = 1; i < 0x26; i++) {
        sWork->unk_000[0][i] = 0xEE;
        sWork->unk_000[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_45C, 0, sWork->unk_654 * 2);
    CommRing_Init(&sWork->unk_470, sWork->unk_45C, sWork->unk_654 * 2);
    sWork->unk_680 = 0;
    sWork->unk_681 = 0;
    for (i = 0; i < 8; i++) {
        sWork->unk_65B[i] = 0;
        sWork->unk_663[i] = 1;
        sWork->unk_66B[i] = 1;
        sWork->unk_60C[i] = 0;
        sWork->unk_588[i].unk_A = 0xEE;
        sWork->unk_588[i].unk_8 = 0xFFFF;
        sWork->unk_588[i].unk_4 = NULL;
        sWork->unk_588[i].unk_0 = 0;
    }
    sWork->unk_62C = 1;
    sWork->unk_5E8.unk_A = 0xEE;
    sWork->unk_5E8.unk_8 = 0xFFFF;
    sWork->unk_5E8.unk_4 = NULL;
    sWork->unk_5E8.unk_0 = 0;
    sWork->unk_67E = 1;
    sWork->unk_67F = 1;
    CommQueueMan_Reset(&sWork->unk_548);
    CommQueueMan_Reset(&sWork->unk_568);
    sWork->unk_684 = 0;
}

void CommSys_ClearServerRecvData(u16 aid)
{
    sWork->unk_65B[aid] = 0;
    sWork->unk_663[aid] = 1;
    sWork->unk_634[aid] = 0;
    sWork->unk_66B[aid] = 1;
    CommRing_Init(&sWork->unk_47C[aid], sWork->unk_454 + aid * sWork->unk_654, sWork->unk_654);
    CommRing_Init(&sWork->unk_4E8[aid], sWork->unk_458 + aid * sWork->unk_654, sWork->unk_654);
    sWork->unk_588[aid].unk_A = 0xEE;
    sWork->unk_588[aid].unk_8 = 0xFFFF;
    sWork->unk_588[aid].unk_4 = NULL;
    sWork->unk_588[aid].unk_0 = 0;
}

void CommSys_ClearDisconnectedClients()
{
    for (u16 aid = 1; aid < 8; aid++) {
        if (!CommSys_IsPlayerConnected(aid) && sWork->unk_663[aid] == 0 && !CommSys_IsAlone()) {
            CommSys_ClearServerRecvData(aid);
        }
    }
}

BOOL CommSys_InitServer(int arg, int flag3, int size, int flag5)
{
    BOOL result = TRUE;
    if (CommManager_GetCommType() < 0x13) {
        result = CommServerClient_InitServer(arg, flag3, flag5);
    }
    CommSys_Init(arg, size);
    return result;
}

void CommSys_UpdateTransitionType()
{
    BOOL reset = FALSE;
    if (CommSys_CurNetId() == 0) {
        if (sServerSendState != 4) {
            return;
        }
    } else if (sClientSendState != 4) {
        return;
    }
    if (sWork->unk_679 == 2) {
        sWork->unk_679 = 0;
        reset = TRUE;
    }
    if (sWork->unk_679 == 3) {
        reset = TRUE;
        sWork->unk_679 = 1;
    }
    if (reset) {
        CommSys_ClearData();
    }
    CommSys_Transmission();
}

void CommSys_SwitchTransitionType(u8 mode)
{
    u8 state = sWork->unk_679;
    if (state == 0 && mode == 1) {
        sWork->unk_679 = 3;
    } else if (state == 1 && mode == 0) {
        sWork->unk_679 = 2;
    }
}

void CommSys_SwitchTransitionTypeToParallel()
{
    CommSys_SwitchTransitionType(1);
}

u8 CommSys_TransmissionType()
{
    u8 state = sWork->unk_679;
    if (state == 2) {
        return 1;
    }
    if (state == 3) {
        state = 0;
    }
    return state;
}

void CommSys_Delete()
{
    BOOL end = FALSE;
    if (sWork != NULL) {
        if (CommManager_GetCommType() >= 0x13) {
            end = TRUE;
        } else if (CommServerClient_RequestEnd()) {
            end = TRUE;
        }
    }
    if (!end) {
        return;
    }
    CommTool_Delete();
    CommInfo_Delete();
    sActive = 0;
    if (sWork->unk_45C != NULL) {
        Heap_Free(sWork->unk_45C);
        sWork->unk_45C = NULL;
    }
    if (sWork->unk_460 != NULL) {
        Heap_Free(sWork->unk_460);
        sWork->unk_460 = NULL;
    }
    if (sWork->unk_458 != NULL) {
        Heap_Free(sWork->unk_458);
        sWork->unk_458 = NULL;
    }
    if (sWork->unk_454 != NULL) {
        Heap_Free(sWork->unk_454);
        sWork->unk_454 = NULL;
    }
    CommQueueMan_Delete(&sWork->unk_568);
    CommQueueMan_Delete(&sWork->unk_548);
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void CommSys_UpdateSend()
{
    if (sWork != NULL && sActive != 0) {
        CommSys_SendClientFrame();
        if ((CommSys_CurNetId() == 0 && CommSys_IsPlayerConnected(0)) || CommSys_IsAlone()) {
            CommSys_UpdateServerClient();
        }
        sActive = 0;
    }
}

void CommSys_UpdateEnd()
{
    if (!CommServerClient_IsEnding()) {
        return;
    }
    if (CommSys_CurNetId() == 0) {
        if (CommServerClient_IsClientConnecting() != 0) {
            return;
        }
        CommSys_Delete();
        return;
    }
    CommSys_Delete();
}

BOOL CommSys_Update()
{
    Connect_Update();
    CommManager_Update();
    if (sWork != NULL) {
        if (sWork->unk_686 == 0) {
            sActive = 0;
            CommSys_UpdateTransitionType();
            CommSys_UpdateClient();
            sWork->unk_624 &= 0x8000;
            if (CommSys_TransmissionType() == 0) {
                CommSys_RecvData();
            }
            if ((CommSys_CurNetId() == 0 && CommSys_IsPlayerConnected(0)) || CommSys_IsAlone()) {
                CommSys_UpdateServer();
            }
            if (CommSys_CurNetId() == 0 || CommSys_TransmissionType() == 1 || CommSys_IsAlone()) {
                CommSys_RecvDataServer();
            }
            sActive = 1;
        }
        CommServerClient_Update(sWork->unk_658);
        if (CommSys_CurNetId() == 0) {
            CommSys_ClearDisconnectedClients();
        }
        CommSys_UpdateEnd();
    } else {
        CommServerClient_Update(0);
    }
    CommTiming_Update();
    CommSys_UpdateSend();
    return TRUE;
}

void CommSys_UpdateClient()
{
    if (sWork->unk_67F != 0) {
        if (CommManager_GetCommType() >= 0x13) {
            return;
        }
        if ((WH_GetSystemState() != 4 || !CommSys_IsPlayerConnected(CommSys_CurNetId())) && !CommSys_IsAlone()) {
            return;
        }
        sClientSendState = 0;
        CommSys_SendClientFrame();
        if (sClientSendState == 0) {
            return;
        }
        sWork->unk_67F = 0;
        return;
    }
    if (CommManager_GetCommType() >= 0x13) {
        return;
    }
    if ((WH_GetSystemState() != 4 || !CommSys_IsPlayerConnected(CommSys_CurNetId())) && !CommSys_IsAlone()) {
        return;
    }
    if (sClientSendState != 4) {
        return;
    }
    if (sWork->unk_630 > 3) {
        return;
    }
    CommSys_BuildClientFrame(sWork->unk_000[sWork->unk_67B]);
    CommSys_BuildClientFrame(sWork->unk_000[1 - sWork->unk_67B]);
    sClientSendState = 0;
    CommSys_SendClientFrame();
}

BOOL CommSys_BuildParallelServerFrame(u8 frame)
{
    int stride;
    int i;
    int full;
    int n;

    full = 0;
    stride = CommSys_GetPacketSize(CommManager_GetCommType());
    n = CommLocal_MaxMachines(CommManager_GetCommType()) + 1;
    for (i = 0; i < n; i++) {
        CommRing_UpdateEndPos(&sWork->unk_47C[i]);
        if (CommSys_IsPlayerConnected(i)) {
            sWork->unk_154[frame][i * stride] = 0xE;
        }
        CommRing_Read(&sWork->unk_47C[i], &sWork->unk_154[frame][i * stride], stride);
        if (sWork->unk_154[frame][i * stride] == 0xE) {
            full++;
        }
    }
    if (full == n) {
        return FALSE;
    }
    return TRUE;
}

void CommSys_UpdateServerClient()
{
    if (sWork == NULL) {
        return;
    }
    if (CommManager_GetCommType() >= 0x13) {
        return;
    }
    int i;
    int stride = CommSys_GetPacketSize(CommManager_GetCommType());
    int n = CommLocal_MaxMachines(CommManager_GetCommType()) + 1;
    if (sServerSendState != 2 && sServerSendState != 0) {
        return;
    }
    sServerSendState++;
    if (CommSys_TransmissionType() == 1) {
        CommSys_BuildParallelServerFrame(sWork->unk_67C);
    }
    if (WH_GetSystemState() == 4 && !CommSys_IsAlone() && !thunk_FUN_overlay_11__02127904(sWork->unk_154[sWork->unk_67C], sizeof(sWork->unk_154[0]), 14, CommSys_ServerSendCallback)) {
        sServerSendState--;
    }
    if (sServerSendState == 1 || sServerSendState == 3) {
        for (i = 0; i < n; i++) {
            if (CommSys_IsPlayerConnected(i)) {
                sWork->unk_634[i]++;
            } else if (CommSys_IsAlone() && i == 0) {
                sWork->unk_634[i]++;
            }
        }
        CommSys_RecvFromServer(0, sWork->unk_154[sWork->unk_67C], sizeof(sWork->unk_154[0]));
        sWork->unk_67C = 1 - sWork->unk_67C;
    }
    for (i = 0; i < n; i++) {
        if (!CommSys_IsPlayerConnected(i) && CommSys_TransmissionType() == 1) {
            sWork->unk_154[sWork->unk_67C][i * stride] = 0xFF;
        }
    }
    if (WH_GetSystemState() == 4 && !CommSys_IsAlone()) {
        return;
    }
    sServerSendState++;
}

void CommSys_UpdateServer()
{
    if (sWork->unk_67F != 0 && (WH_GetSystemState() == 4 || CommSys_IsAlone())) {
        CommSys_UpdateServerClient();
        if (sServerSendState == 2) {
            sWork->unk_67F = 0;
            return;
        }
    }
    if (WH_GetSystemState() != 4 && !CommSys_IsAlone()) {
        return;
    }
    if (sServerSendState != 4) {
        return;
    }
    for (int i = 1; i < 8; i++) {
        if (CommSys_IsPlayerConnected(i)) {
            if (sWork->unk_634[i] > 3) {
                return;
            }
        } else if (i == 0 && CommSys_IsAlone() && sWork->unk_634[0] > 3) {
            return;
        }
    }
    if (CommSys_TransmissionType() == 0) {
        CommSys_BuildServerFrame(sWork->unk_154[sWork->unk_67C]);
        CommSys_BuildServerFrame(sWork->unk_154[1 - sWork->unk_67C]);
    }
    sServerSendState = 0;
    CommSys_UpdateServerClient();
}

void CommSys_RecvFromServer(u16 aid, u8 *data, u16 size)
{
    sWork->unk_630--;
    if (data == NULL) {
        return;
    }
    if (*data == 0xB) {
        if (CommSys_TransmissionType() == 1) {
            return;
        }
        data++;
    } else if (CommSys_TransmissionType() == 0) {
        return;
    }
    if (sWork->unk_67E != 0 && (*data & 1)) {
        return;
    }
    sWork->unk_67E = 0;
    if (CommSys_TransmissionType() == 1) {
        int stride = CommSys_GetPacketSize(CommManager_GetCommType());
        int n = CommLocal_MaxMachines(CommManager_GetCommType()) + 1;
        for (int i = 0; i < n; i++) {
            if (*data == 0xFF) {
                sWork->unk_658 &= ~(1 << i);
            } else {
                sWork->unk_658 |= 1 << i;
            }
            if (*data == 0xFF) {
                data += stride;
            } else if (*data == 0xE) {
                data += stride;
            } else if (sWork->unk_663[i] != 0 && (*data & 1)) {
                data += stride;
            } else {
                data++;
                CommRing_Write(&sWork->unk_4E8[i], data, stride - 1, 0x5E6);
                data += stride - 1;
                sWork->unk_663[i] = 0;
            }
        }
        return;
    }
    sWork->unk_658 = data[1];
    sWork->unk_658 <<= 8;
    sWork->unk_658 += data[2];
    CommRing_Write(&sWork->unk_470, data + 4, data[3], 0x5FF);
}

void CommSys_ServerRecvCallback(u16 aid, u16 *data, u16 size)
{
    if (sWork->unk_66B[aid] != 0) {
        sWork->unk_634[aid]--;
        sWork->unk_66B[aid] = 0;
        return;
    }
    CommSys_RecvFromClient(aid, (u8 *)data, size);
}

void CommSys_RecvFromClient(u16 aid, u8 *data, u16 size)
{
    sWork->unk_634[aid]--;
    if (data == NULL) {
        return;
    }
    if (sWork->unk_663[aid] != 0 && (*data & 1)) {
        return;
    }
    sWork->unk_663[aid] = 0;
    if (CommSys_TransmissionType() == 1) {
        int stride = CommSys_GetPacketSize(CommManager_GetCommType());
        CommLocal_MaxMachines(CommManager_GetCommType());
        if (!(*data & 2)) {
            CommRing_Write(&sWork->unk_47C[aid], data, stride, 0x65E);
        }
        sWork->unk_65B[aid]++;
        return;
    }
    CommSys_DecodeKeys(data, aid);
    if (*data & 2) {
        return;
    }
    if (CommRing_RemainingSize(&sWork->unk_4E8[aid]) < 0xB) {
        return;
    }
    CommRing_Write(&sWork->unk_4E8[aid], data + 1, 0xB, 0x66E);
}

void CommSys_ClientSendCallback(BOOL result)
{
    if (result) {
        sClientSendState++;
    }
}

void CommSys_ServerSendCallback(BOOL result)
{
    if (result) {
        sServerSendState++;
    }
}

void CommSys_SendClientFrame()
{
    if (sWork == NULL) {
        return;
    }
    if (CommManager_GetCommType() >= 0x13) {
        return;
    }
    int stride = CommSys_GetPacketSize(CommManager_GetCommType());
    CommLocal_MaxMachines(CommManager_GetCommType());
    if (CommSys_IsAlone()) {
        if (sClientSendState == 2 || sClientSendState == 0) {
            sClientSendState++;
            CommSys_ClientSendCallback(TRUE);
            CommSys_RecvFromClient(0, sWork->unk_000[sWork->unk_67B], stride);
            sWork->unk_67B = 1 - sWork->unk_67B;
            sWork->unk_630++;
            return;
        }
    }
    if (WH_GetSystemState() != 4) {
        return;
    }
    if (!CommSys_IsPlayerConnected(CommSys_CurNetId())) {
        CommSys_CurNetId();
        return;
    }
    if (sClientSendState != 2 && sClientSendState != 0) {
        return;
    }
    if (CommSys_CurNetId() != 0) {
        sClientSendState++;
        if (!thunk_FUN_overlay_11__02127904(sWork->unk_000[sWork->unk_67B], stride, 14, CommSys_ClientSendCallback)) {
            sClientSendState--;
            return;
        }
        sWork->unk_67B = 1 - sWork->unk_67B;
        sWork->unk_630++;
        return;
    }
    if (!(WH_GetBitmap() & 0xFFFE)) {
        return;
    }
    sClientSendState++;
    CommSys_ClientSendCallback(TRUE);
    CommSys_RecvFromClient(0, sWork->unk_000[sWork->unk_67B], stride);
    sWork->unk_67B = 1 - sWork->unk_67B;
    sWork->unk_630++;
}

BOOL CommSys_DecodeKeys(u8 *data, int aid)
{
    sWork->unk_60C[aid] = 0;
    if ((*data & 0x10) == 0x10) {
        u8 type = *data & 0xC;
        if (type == 0) {
            sWork->unk_60C[aid] |= 0x40;
        } else if (type == 4) {
            sWork->unk_60C[aid] |= 0x80;
        } else if (type == 8) {
            sWork->unk_60C[aid] |= 0x20;
        } else if (type == 12) {
            sWork->unk_60C[aid] |= 0x10;
        }
        sWork->unk_61C[aid] = (*data >> 5) & 7;
    }
    return TRUE;
}

BOOL CommSys_EncodeKeys(u8 *hdr)
{
    if (sWork->unk_626 != 0) {
        return FALSE;
    }
    if (!CommSys_IsSendingMovementData()) {
        return FALSE;
    }
    if (sWork->unk_67D != 0) {
        sWork->unk_67D--;
    }
    u16 flags = sWork->unk_624;
    if (flags & 0x40) {
        *hdr |= 0x10;
        sWork->unk_67D = 8;
    } else if (flags & 0x80) {
        *hdr |= 0x14;
        sWork->unk_67D = 8;
    } else if (flags & 0x20) {
        *hdr |= 0x18;
        sWork->unk_67D = 8;
    } else if (flags & 0x10) {
        *hdr |= 0x1C;
        sWork->unk_67D = 8;
    }
    *hdr |= (u8)(sWork->unk_627 << 5);
    return FALSE;
}

BOOL CommSys_BuildClientFrame(u8 *frame)
{
    int stride = CommSys_GetPacketSize(CommManager_GetCommType());
    CommLocal_MaxMachines(CommManager_GetCommType());
    if (sWork->unk_680 == 0) {
        *frame = 0;
    } else {
        *frame = 1;
    }
    if (CommSys_TransmissionType() == 0) {
        CommSys_EncodeKeys(frame);
    }
    sWork->unk_680 = 0;
    if (CommQueue_IsEmpty(&sWork->unk_548)) {
        *frame |= 2;
        if (*frame == 2) {
            return FALSE;
        }
    } else {
        CommQueueCursor cursor;
        cursor.size = stride - 1;
        cursor.ptr = frame + 1;
        if (!CommQueue_FillBuffer(&sWork->unk_548, &cursor, 1)) {
            sWork->unk_680 = 1;
        }
        if (CommSys_TransmissionType() == 1) {
            sWork->unk_65A++;
            *frame |= (sWork->unk_65A << 4) & 0xF0;
        }
    }
    return TRUE;
}

void CommSys_BuildServerFrame(u8 *frame)
{
    frame[0] = 0xB;
    if (sWork->unk_681 == 0) {
        frame[1] = 0;
    } else {
        frame[1] = 1;
    }
    u16 bitmap = WH_GetBitmap();
    frame[2] = bitmap >> 8;
    frame[3] = bitmap;
    CommQueueCursor cursor;
    cursor.size = 0xBB;
    cursor.ptr = frame + 5;
    if (CommQueue_FillBuffer(&sWork->unk_568, &cursor, 0)) {
        sWork->unk_681 = 0;
        frame[4] = 0xBB - cursor.size;
        return;
    }
    sWork->unk_681 = 1;
    frame[4] = 0xBB;
}

BOOL CommSys_SendDataHuge(u8 cmd, u8 *data, u16 size)
{
    if (!CommSys_IsPlayerConnected(CommSys_CurNetId()) && !CommSys_IsAlone()) {
        return FALSE;
    }
    if (CommQueue_Write(&sWork->unk_548, cmd, data, size, 1, 0)) {
        return TRUE;
    }
    if (CommManager_GetCommType() == 10) {
        CommSys_SetError();
    }
    return FALSE;
}

BOOL CommSys_SendData(u8 cmd, u8 *data, u16 size)
{
    if (!CommSys_IsPlayerConnected(CommSys_CurNetId()) && !CommSys_IsAlone()) {
        return FALSE;
    }
    if (CommQueue_Write(&sWork->unk_548, cmd, data, size, 1, 1)) {
        return TRUE;
    }
    if (CommManager_GetCommType() == 10) {
        CommSys_SetError();
    }
    return FALSE;
}

BOOL CommSys_SendDataHugeServer(u8 cmd, u8 *data, u16 size)
{
    if (CommSys_CurNetId() != 0) {
        return FALSE;
    }
    if (!CommSys_IsPlayerConnected(0) && !CommSys_IsAlone()) {
        return FALSE;
    }
    if (CommSys_TransmissionType() == 1) {
        return CommSys_SendDataHuge(cmd, data, size);
    }
    if (CommQueue_Write(&sWork->unk_568, cmd, data, size, 1, 0)) {
        return TRUE;
    }
    if (CommManager_GetCommType() == 10) {
        CommSys_SetError();
    }
    return FALSE;
}

BOOL CommSys_SendDataServer(u8 cmd, u8 *data, u16 size)
{
    if (CommSys_CurNetId() != 0) {
        CommSys_SetError();
        return FALSE;
    }
    if (!CommSys_IsPlayerConnected(0) && !CommSys_IsAlone()) {
        return FALSE;
    }
    if (CommSys_TransmissionType() == 1) {
        return CommSys_SendData(cmd, data, size);
    }
    if (CommQueue_Write(&sWork->unk_568, cmd, data, size, 1, 1)) {
        return TRUE;
    }
    if (CommManager_GetCommType() == 10) {
        CommSys_SetError();
    }
    return FALSE;
}

BOOL CommSys_SendDataFixedSizeServer(u8 cmd, u8 *data)
{
    return CommSys_SendDataServer(cmd, data, 0);
}

void CommSys_EndCallback(int aid, int cmd, int size, u8 *data, CommRecvState *pending)
{
    CommCmd_Callback(aid, cmd, size, data);
    pending->unk_A = 0xEE;
    pending->unk_8 = 0xFFFF;
    pending->unk_4 = NULL;
    pending->unk_0 = 0;
}

void CommSys_RecvDataSingle(CommRing *ring, int aid, u8 *buf, int flag, CommRecvState *pending)
{
    int size;
    s16 pos;
    u8 cmd;

    if (CommRing_DataSize(ring) == 0) {
        return;
    }
    do {
        cmd = pending->unk_A;
        if (cmd != 0xEE || (cmd = CommRing_ReadByte(ring)) != 0xEE) {
            pos = ring->startIndex;
            pending->unk_A = cmd;
            size = pending->unk_8;
            if (size == 0xFFFF) {
                size = CommCmd_PacketSizeOf(cmd);
                if (sWork->unk_685 != 0) {
                    return;
                }
                if (size == 0xFFFF) {
                    if (CommRing_DataSize(ring) < 1) {
                        ring->startIndex = pos;
                        return;
                    }
                    int hi = CommRing_ReadByte(ring);
                    size = CommRing_ReadByte(ring) + (hi << 8);
                    pos = ring->startIndex;
                }
                pending->unk_8 = size;
            }
            if (CommCmd_HasRecvBuffer(cmd)) {
                if (pending->unk_4 == NULL) {
                    pending->unk_4 = CommCmd_GetRecvBuffer(cmd, aid, pending->unk_8);
                }
                int n = CommRing_Read(ring, buf, size - pending->unk_0);
                if (pending->unk_4 != NULL) {
                    MI_CpuCopy8(buf, &pending->unk_4[pending->unk_0], n);
                }
                pending->unk_0 += n;
                if (pending->unk_0 >= size) {
                    CommSys_EndCallback(aid, cmd, size, pending->unk_4, pending);
                }
            } else if (CommRing_DataSize(ring) >= size) {
                CommRing_Read(ring, buf, size);
                CommSys_EndCallback(aid, cmd, size, buf, pending);
            } else {
                ring->startIndex = pos;
                return;
            }
        }
    } while (CommRing_DataSize(ring) != 0);
}

void CommSys_RecvData()
{
    if (sWork == NULL) {
        return;
    }
    if (sWork->unk_687 != 0) {
        return;
    }
    CommRing_UpdateEndPos(&sWork->unk_470);
    if (CommRing_DataSize(&sWork->unk_470) <= 0) {
        return;
    }
    CommSys_RecvDataSingle(&sWork->unk_470, 0, sWork->unk_460, 1, &sWork->unk_5E8);
}

void CommSys_RecvDataServer()
{
    if (sWork == NULL) {
        return;
    }
    if (sWork->unk_687 != 0) {
        return;
    }
    int i;
    int n = CommLocal_MaxMachines(CommManager_GetCommType()) + 1;
    for (i = 0; i < n; i++) {
        CommRing_UpdateEndPos(&sWork->unk_4E8[i]);
        if (CommRing_DataSize(&sWork->unk_4E8[i]) > 0) {
            CommSys_RecvDataSingle(&sWork->unk_4E8[i], i, sWork->unk_460, 0, &sWork->unk_588[i]);
        }
    }
}

BOOL CommSys_IsPlayerConnected(u16 aid)
{
    if (sWork == NULL) {
        return FALSE;
    }
    if (CommManager_GetCommType() >= 0x13) {
        return FALSE;
    }
    if (!CommSys_IsInitialized()) {
        return FALSE;
    }
    if (WH_GetSystemState() != 4) {
        return FALSE;
    }
    if (aid == CommSys_CurNetId()) {
        return TRUE;
    }
    if (CommSys_CurNetId() == 0) {
        if (WH_GetBitmap() & (1 << aid)) {
            return TRUE;
        }
    } else if (sWork->unk_658 & (1 << aid)) {
        return TRUE;
    }
    return FALSE;
}

int CommSys_ConnectedCount()
{
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (CommSys_IsPlayerConnected(i)) {
            count++;
        }
    }
    return count;
}

BOOL CommSys_IsInitialized()
{
    if (sWork != NULL && CommManager_GetCommType() >= 0x13) {
        return TRUE;
    }
    return CommServerClient_IsInitialized();
}

int CommSys_IsSendingMovementData()
{
    return sWork != NULL ? sWork->unk_624 & 0x8000 : TRUE;
}

void CommSys_Transmission()
{
    if (sWork == NULL) {
        return;
    }
    switch (sWork->unk_677) {
    case 1: {
        BOOL sent;
        if (CommSys_TransmissionType() == 1) {
            sent = CommSys_SendDataFixedSize(0xB, &sWork->unk_678);
        } else {
            sent = CommSys_SendDataServer(0xB, &sWork->unk_678, 1);
        }
        if (!sent) {
            return;
        }
        sWork->unk_677 = 2;
        break;
    }
    case 3:
        if (!CommSys_SendDataFixedSize(0xC, &sWork->unk_678)) {
            return;
        }
        CommSys_SwitchTransitionType(sWork->unk_678);
        sWork->unk_677 = 0;
        break;
    }
}

void CommSys_RecvSwitchRequest(int aid, int size, u8 *data)
{
    if (CommSys_CurNetId() != 0) {
        return;
    }
    sWork->unk_677 = 1;
    sWork->unk_678 = *data;
}

void CommSys_RecvSwitchNotify(int aid, int size, u8 *data)
{
    if (CommSys_CurNetId() == 0) {
        return;
    }
    sWork->unk_678 = *data;
    sWork->unk_677 = 3;
}

void CommSys_RecvSwitchAck(int aid, int size, u8 *data)
{
    if (CommSys_CurNetId() != 0) {
        return;
    }
    if (sWork->unk_677 != 2) {
        return;
    }
    CommSys_SwitchTransitionType(*data);
    sWork->unk_677 = 0;
}

u16 CommSys_CurNetId()
{
    if (sWork != NULL && CommManager_GetCommType() < 0x13) {
        if (CommSys_IsAlone()) {
            return 0;
        }
        return WH_GetCurrentAid();
    }
    return 0;
}

BOOL CommSys_SendDataFixedSize(u8 cmd, u8 *data)
{
    return CommSys_SendData(cmd, data, 0);
}

int CommSys_GetPacketSize(u16 mode)
{
    if (CommLocal_MaxMachines(mode) >= 5) {
        return 12;
    }
    if (CommSys_TransmissionType() == 0) {
        return 12;
    }
    return 0x26;
}

BOOL CommSys_IsAlone()
{
    CommSystem *work = sWork;
    return work != NULL ? work->unk_682 : 0;
}

void CommSys_RecvEnd()
{
    u8 data;
    if (!CommServerClient_IsEnding() && CommSys_CurNetId() == 0) {
        CommSys_SendDataFixedSizeServer(2, &data);
    }
    CommServerClient_SetEnding();
}

void CommSys_Seed(MATHRandContext32 *ctx)
{
    RTCDate date;
    RTCTime time;
    RTC_GetDate(&date);
    RTC_GetTime(&time);
    MATH_InitRand32(ctx, ((((((((((u64)date.year * 16) + date.month) * 32) + date.day) * 32) + time.hour) * 64) + time.minute) * 64) + (time.second + 0x25));
}

void CommSys_SetError()
{
    sWork->unk_685 = 1;
}

// size of RangerNetSessionParam (RangerNetPlayerInfo.cpp)
u32 RangerNetSessionParam_Size()
{
    return 0x20;
}
