#include "common.hpp"
#include "heap.hpp"

// Command dispatch of the Ranger Net packet layer (0212CA60..0212CDF4); pokeplatinum unk_02032798.c (CommCmd)

typedef void (*CommCmdFunc)(int netId, int size, void *data, void *arg);
typedef int (*CommCmdSizeFunc)();
typedef void *(*CommCmdBufferFunc)(int netId, void *arg, int size);

struct CommCmdTable {
    CommCmdFunc func;
    CommCmdSizeFunc sizeFunc;
    CommCmdBufferFunc bufferFunc;
};

struct CommCmdManager {
    const CommCmdTable *cmdTable;
    int count;
    void *arg;
    u8 unk_0C[8];
    u8 unk_14;
};

struct D3Entry;

// RangerNetConnect.cpp .. RangerNetCommSystem.cpp
void CommPlayerInfo_Size();
void CommInfo_FinishReading();
void CommInfo_RecvPlayerDataArray(int aid, int size, D3Entry *data);
void CommInfo_RecvPlayerData(int aid, int size, D3Entry *data);
void CommManager_ValidateConfirmationMessage(u8 aid, int size, u8 *data);
void CommManager_ValidateConfirmationResponseMessage(int aid, int size, u8 *data);
void CommManager_ConfirmationMessage_sizeof();
void CommTiming_RecvSyncNo(u8 aid, int size, u8 *data);
void CommTiming_RecvPlayerSyncNo(int aid, int size, const u8 *data);
void CommTiming_RecvSyncState(int aid, int size, const u8 *data);
void CommList_Recv(int aid, int size, const u8 *data);
void CommList_Size();
void CommTool_RecvTempData(int idx, int size, const void *data);
void CommTool_TempDataSize();
BOOL CommSys_SendDataServer(u8 cmd, u8 *data, u16 size);
BOOL CommSys_IsPlayerConnected(u16 aid);
u16 CommSys_CurNetId();
BOOL CommSys_SendDataFixedSize(u8 cmd, u8 *data);
void CommSys_RecvSwitchRequest(int aid, int size, u8 *data);
void CommSys_RecvSwitchNotify(int aid, int size, u8 *data);
void CommSys_RecvSwitchAck(int aid, int size, u8 *data);
void CommSys_RecvEnd();
void CommSys_SetError();

int CommPacketSizeOf_Nothing();
int CommPacketSizeOf_NetId();
int CommPacketSizeOf_U16();
static void CommCmd_RecvResetRequest(int netId, int size, void *data, void *arg);
static void CommCmd_RecvReset(int netId, int size, void *data, void *arg);
static void CommCmd_RecvResetDone(int netId, int size, void *data, void *arg);

static const CommCmdTable sBuiltinCmds[] = {
    { NULL, CommPacketSizeOf_Nothing, NULL },
    { NULL, CommPacketSizeOf_Nothing, NULL },
    { (CommCmdFunc)CommSys_RecvEnd, CommPacketSizeOf_Nothing, NULL },
    { (CommCmdFunc)CommInfo_RecvPlayerData, (CommCmdSizeFunc)CommPlayerInfo_Size, NULL },
    { (CommCmdFunc)CommInfo_RecvPlayerDataArray, (CommCmdSizeFunc)CommPlayerInfo_Size, NULL },
    { (CommCmdFunc)CommInfo_FinishReading, CommPacketSizeOf_Nothing, NULL },
    { (CommCmdFunc)CommManager_ValidateConfirmationMessage, (CommCmdSizeFunc)CommManager_ConfirmationMessage_sizeof, NULL },
    { (CommCmdFunc)CommManager_ValidateConfirmationResponseMessage, (CommCmdSizeFunc)CommManager_ConfirmationMessage_sizeof, NULL },
    { NULL, NULL, NULL },
    { NULL, NULL, NULL },
    { (CommCmdFunc)CommSys_RecvSwitchRequest, CommPacketSizeOf_NetId, NULL },
    { (CommCmdFunc)CommSys_RecvSwitchNotify, CommPacketSizeOf_NetId, NULL },
    { (CommCmdFunc)CommSys_RecvSwitchAck, CommPacketSizeOf_NetId, NULL },
    { CommCmd_RecvResetRequest, CommPacketSizeOf_Nothing, NULL },
    { CommCmd_RecvReset, CommPacketSizeOf_Nothing, NULL },
    { CommCmd_RecvResetDone, CommPacketSizeOf_Nothing, NULL },
    { (CommCmdFunc)CommTiming_RecvSyncNo, CommPacketSizeOf_NetId, NULL },
    { (CommCmdFunc)CommTiming_RecvSyncState, CommPacketSizeOf_NetId, NULL },
    { (CommCmdFunc)CommTiming_RecvPlayerSyncNo, CommPacketSizeOf_U16, NULL },
    { (CommCmdFunc)CommList_Recv, (CommCmdSizeFunc)CommList_Size, NULL },
    { (CommCmdFunc)CommTool_RecvTempData, (CommCmdSizeFunc)CommTool_TempDataSize, NULL },
};

static CommCmdManager *sCommCmdManager;

void CommCmd_Init(const CommCmdTable *cmdTable, int count, void *arg)
{
    int i;

    if (sCommCmdManager == NULL) {
        sCommCmdManager = (CommCmdManager *)Heap_Alloc(sizeof(CommCmdManager));
    }
    sCommCmdManager->cmdTable = cmdTable;
    sCommCmdManager->count = count;
    sCommCmdManager->arg = arg;
    for (i = 0; i < 8; i++) {
        sCommCmdManager->unk_0C[i] = 0;
    }
    sCommCmdManager->unk_14 = 0;
}

void CommCmd_Delete()
{
    if (sCommCmdManager == NULL) {
        return;
    }
    if (sCommCmdManager != NULL) {
        Heap_Free(sCommCmdManager);
    }
    sCommCmdManager = NULL;
}

void CommCmd_Callback(int netId, int cmd, int size, void *data)
{
    CommCmdFunc func;

    if (cmd < 22) {
        func = sBuiltinCmds[cmd].func;
    } else {
        if (cmd > sCommCmdManager->count + 22) {
            CommSys_SetError();
            return;
        }
        func = sCommCmdManager->cmdTable[cmd - 22].func;
    }
    if (func != NULL) {
        if (sCommCmdManager != NULL) {
            func(netId, size, data, sCommCmdManager->arg);
        } else {
            func(netId, size, data, NULL);
        }
    }
}

int CommCmd_PacketSizeOf(int cmd)
{
    int size = 0;
    CommCmdSizeFunc func;

    if (cmd < 22) {
        func = sBuiltinCmds[cmd].sizeFunc;
    } else {
        if (sCommCmdManager == NULL) {
            CommSys_SetError();
            return size;
        }
        if (cmd > sCommCmdManager->count + 22) {
            CommSys_SetError();
            return size;
        }
        func = sCommCmdManager->cmdTable[cmd - 22].sizeFunc;
    }
    if (func != NULL) {
        size = func();
    }
    return size;
}

BOOL CommCmd_HasRecvBuffer(int cmd)
{
    if (cmd < 22) {
        return sBuiltinCmds[cmd].bufferFunc != NULL;
    }
    return sCommCmdManager->cmdTable[cmd - 22].bufferFunc != NULL;
}

void *CommCmd_GetRecvBuffer(int cmd, int netId, int size)
{
    CommCmdBufferFunc func;

    if (cmd < 22) {
        func = sBuiltinCmds[cmd].bufferFunc;
        return func(netId, NULL, size);
    } else {
        func = sCommCmdManager->cmdTable[cmd - 22].bufferFunc;
        return func(netId, sCommCmdManager->arg, size);
    }
    return NULL;
}

int CommPacketSizeOf_Nothing()
{
    return 0;
}

int CommPacketSizeOf_NetId()
{
    return 1;
}

int CommPacketSizeOf_U16()
{
    return 2;
}

static void CommCmd_RecvResetRequest(int netId, int size, void *data, void *arg)
{
    int i;

    if (CommSys_CurNetId() != 0) {
        return;
    }
    sCommCmdManager->unk_0C[netId] = 1;
    for (i = 0; i < 8; i++) {
        if (!CommSys_IsPlayerConnected(i)) {
            continue;
        }
        if (!sCommCmdManager->unk_0C[i]) {
            return;
        }
    }
    CommSys_SendDataServer(14, NULL, 0);
}

static void CommCmd_RecvReset(int netId, int size, void *data, void *arg)
{
    sCommCmdManager->cmdTable = NULL;
    sCommCmdManager->count = 0;
    sCommCmdManager->arg = NULL;
    sCommCmdManager->unk_14 = 1;
    CommSys_SendDataFixedSize(15, (u8 *)data);
}

static void CommCmd_RecvResetDone(int netId, int size, void *data, void *arg)
{
    if (CommSys_CurNetId() != 0) {
        return;
    }
    sCommCmdManager->unk_0C[netId] = 0;
}
