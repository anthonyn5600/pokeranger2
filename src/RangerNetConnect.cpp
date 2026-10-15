#include <nitro/math.h>

#include "common.hpp"
#include "heap.hpp"

// D2: connection manager work block (02128478..021286BC)

struct D2Work {
    int unk_00;
    MATHRandContext32 unk_04;
    void (*unk_1C)();
    u16 unk_20;
    u8 unk_22;
    u8 unk_23;
    void *unk_24[16];
    u8 unk_64[0x358];
    u8 unk_3BC;
    u8 unk_3BD[16];
};

static D2Work *sWork;

void CommInfo_SendPlayerInfo(); // D3 (RangerNetPlayerInfo.cpp)
void *CommInfo_GetPlayerInfo(u16 aid); // D3 (RangerNetPlayerInfo.cpp)
void CommManager_StartBattleServer(u8 arg); // D4
void CommManager_EndBattle(); // D4
int CommSys_SendDataHugeServer(u8 cmd, u8 *data, u16 size);
BOOL CommSys_IsPlayerConnected(u16 aid);
BOOL CommSys_IsInitialized();
u8 CommSys_CurNetId();
void CommSys_Seed(MATHRandContext32 *ctx);
void SessionCmd_Init(int arg);

void Connect_SetTask(void (*func)(), u16 n);
void Connect_TaskCollectPlayerInfo();

void Connect_Init(int arg)
{
    if (sWork != NULL) {
        return;
    }
    SessionCmd_Init(arg);
    sWork = (D2Work *)Heap_Alloc(sizeof(D2Work));
    MI_CpuFill8(sWork, 0, sizeof(D2Work));
    sWork->unk_20 = 0x32;
    sWork->unk_00 = arg;
    CommSys_Seed(&sWork->unk_04);
}

void Connect_SetTask(void (*func)(), u16 n)
{
    sWork->unk_1C = func;
    sWork->unk_20 = n;
}

void Connect_TaskSendPlayerInfo()
{
    if (!CommSys_IsPlayerConnected(CommSys_CurNetId())) {
        return;
    }
    for (int i = 0; i < 16; i++) {
        sWork->unk_3BD[i] = 0;
    }
    CommInfo_SendPlayerInfo();
    Connect_SetTask(Connect_TaskCollectPlayerInfo, 0);
}

void Connect_TaskCollectPlayerInfo()
{
    for (u16 i = 0; i < 16; i++) {
        if (sWork->unk_24[i] == NULL && CommSys_IsPlayerConnected(i) == TRUE) {
            sWork->unk_24[i] = CommInfo_GetPlayerInfo(i);
        }
    }
}

void Connect_Update()
{
    D2Work *work = sWork;
    if (work != NULL && work->unk_1C != NULL) {
        if (work->unk_22 == 0) {
            work->unk_1C();
        }
    }
}

void Connect_Start(int arg, u8 arg2)
{
    if (CommSys_IsInitialized()) {
        return;
    }
    CommManager_StartBattleServer(arg2);
    Connect_Init(arg);
    Connect_SetTask(Connect_TaskSendPlayerInfo, 0);
}

void Connect_SendData(void *data, u16 size)
{
    CommSys_SendDataHugeServer(0x16, (u8 *)data, size);
}

void ov11_02128634(u8 v)
{
    if (sWork->unk_23 == v) {
        sWork->unk_3BC = 1;
    }
}

u32 Connect_GetRecvBufferSize()
{
    return sizeof(sWork->unk_64);
}

void *Connect_GetRecvBuffer()
{
    return sWork->unk_64;
}

void ov11_02128670(int i)
{
    sWork->unk_3BD[i] = 1;
}

void Connect_Free()
{
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
    CommManager_EndBattle();
}
