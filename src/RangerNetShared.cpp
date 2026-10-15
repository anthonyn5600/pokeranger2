#include "common.hpp"
#include "heap.hpp"

// D6: shared per-player values and blocks (021298C4..02129B60)

struct D6Work {
    u8 unk_000[8][2];
    u8 unk_010[8];
    u8 unk_018[8][0x46];
    u8 unk_248[8];
    u8 unk_250;
    u8 unk_251;
    u8 unk_252;
};

static D6Work *sWork;

void CommSys_SendDataFixedSizeServer(u8 cmd, u8 *data);
BOOL CommSys_IsPlayerConnected(u16 aid);
u16 CommSys_CurNetId();
BOOL CommSys_SendDataFixedSize(u8 cmd, u8 *data);

void CommTool_Init(int arg)
{
    if (sWork == NULL) {
        sWork = (D6Work *)Heap_Alloc(sizeof(D6Work));
        MI_CpuFill8(sWork, 0, sizeof(D6Work));
    }
    for (int i = 0; i < 8; i++) {
        sWork->unk_010[i] = 0xFF;
    }
    sWork->unk_250 = 0xFF;
    sWork->unk_251 = 0xFF;
    sWork->unk_252 = 0;
}

void CommTool_Delete()
{
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void CommTiming_RecvSyncNo(u8 aid, int size, u8 *data)
{
    u8 value = data[0];
    if (CommSys_CurNetId() != 0) {
        return;
    }
    u8 msg[2];
    msg[0] = aid;
    msg[1] = value;
    CommSys_SendDataFixedSizeServer(0x12, msg);
    sWork->unk_010[aid] = value;
    for (u16 i = 0; i < 8; i++) {
        if (CommSys_IsPlayerConnected(i) && value != sWork->unk_010[i]) {
            return;
        }
    }
    CommSys_SendDataFixedSizeServer(0x11, &value);
}

void CommTiming_RecvPlayerSyncNo(int aid, int size, const u8 *data)
{
    sWork->unk_010[data[0]] = data[1];
}

void CommTiming_RecvSyncState(int aid, int size, const u8 *data)
{
    sWork->unk_250 = data[0];
}

void CommTiming_StartSync(u8 v)
{
    sWork->unk_251 = v;
    sWork->unk_252 = 1;
}

void CommTiming_Update()
{
    if (sWork != NULL && sWork->unk_252 != 0) {
        if (!CommSys_SendDataFixedSize(0x10, &sWork->unk_251)) {
            return;
        }
        sWork->unk_252 = 0;
    }
}

BOOL CommTiming_IsSyncState(u8 v)
{
    if (sWork == NULL) {
        return TRUE;
    }
    return sWork->unk_250 == v;
}

void CommList_Recv(int aid, int size, const u8 *data)
{
    sWork->unk_000[aid][0] = data[0];
    sWork->unk_000[aid][1] = data[1];
}

u32 CommList_Size()
{
    return sizeof(sWork->unk_000[0]);
}

void CommTool_RecvTempData(int idx, int size, const void *data)
{
    sWork->unk_248[idx] = 1;
    MI_CpuCopy8(data, sWork->unk_018[idx], sizeof(sWork->unk_018[0]));
}

u32 CommTool_TempDataSize()
{
    return sizeof(sWork->unk_018[0]);
}
