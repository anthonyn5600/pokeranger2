#include <nitro/wm.h>
#include <string.h>

#include "common.hpp"
#include "heap.hpp"

// D3: per-player info table (021286BC..02128A94)

struct D3Info {
    u8 unk_00[0x19];
    u8 unk_19;
    u8 unk_1A[0x6];
};

struct D3Entry {
    u8 unk_00[0x20];
    D3Info unk_20;
    u8 unk_40[0x1C];
    u8 mac[6];
    u8 unk_62;
    u8 unk_63[0x5];
};

struct D3Work {
    D3Entry entries[8];
    D3Info *unk_340[8];
    u8 unk_360[0x30];
    u8 unk_390[8];
    u8 unk_398;
    u8 unk_399;
    u8 unk_39A;
};

static D3Work *sWork;

// D4's default session parameter (RangerNetSession.cpp keeps a pointer to it and passes it on to D5). Defined in
// this TU: mwcc size-sorts a TU's .data, so in D4's own TU it would land after D4's 6-byte message strings.
struct RangerNetSessionParam {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0C[0x14];
};
RangerNetSessionParam gRangerNetSessionParam = { 0, 0, 2 };

void CommServerClient_SetMacAddress(const u8 *mac, int aid); // D5
int CommSys_SendData(u8 type, u8 *data, u16 size);
BOOL CommSys_IsPlayerConnected(u16 aid);
BOOL CommSys_ConnectedCount();
u8 CommSys_CurNetId();
BOOL CommSys_IsAlone();

void CommInfo_InitPlayer(int i);
void TrainerInfo_Init(D3Info *info);

void CommInfo_Init()
{
    if (sWork != NULL) {
        return;
    }
    sWork = (D3Work *)Heap_Alloc(sizeof(D3Work));
    MI_CpuFill8(sWork, 0, sizeof(D3Work));
    for (int i = 0; i < 8; i++) {
        sWork->unk_340[i] = &sWork->entries[i].unk_20;
        CommInfo_InitPlayer(i);
    }
    sWork->unk_398 = 0;
    sWork->unk_399 = 0;
    sWork->unk_39A = 0;
}

void CommInfo_Delete()
{
    if (sWork == NULL) {
        return;
    }
    for (int i = 0; i < 8; i++) {
        sWork->unk_340[i] = NULL;
    }
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void CommInfo_SendPlayerInfo()
{
    int idx = CommSys_CurNetId();
    OS_GetMacAddress(sWork->entries[idx].mac);
    CommSys_SendData(3, (u8 *)&sWork->entries[idx], sizeof(D3Entry));
}

u32 CommPlayerInfo_Size()
{
    return sizeof(D3Entry);
}

void CommInfo_FinishReading()
{
    if (sWork != NULL) {
        sWork->unk_398 = 1;
    }
}

void CommInfo_RecvPlayerDataArray(int aid, int size, D3Entry *data)
{
    if (sWork == NULL) {
        return;
    }
    if (data->unk_20.unk_19 != 2) {
        WM_Disconnect(NULL, (u16)aid);
        return;
    }
    MI_CpuCopy8(data, &sWork->entries[data->unk_62], sizeof(D3Entry));
    sWork->unk_39A = data->unk_62;
    if (sWork->unk_390[sWork->unk_39A] >= 2) {
        return;
    }
    sWork->unk_390[sWork->unk_39A] = 1;
    u8 idx = sWork->unk_39A;
    if (idx != CommSys_CurNetId()) {
        return;
    }
    sWork->unk_390[idx] = 3;
}

void CommInfo_RecvPlayerData(int aid, int size, D3Entry *data)
{
    if (sWork == NULL) {
        return;
    }
    if (data->unk_20.unk_19 != 2) {
        WM_Disconnect(NULL, (u16)aid);
        return;
    }
    MI_CpuCopy8(data, &sWork->entries[aid], sizeof(D3Entry));
    CommServerClient_SetMacAddress(sWork->entries[aid].mac, aid);
    sWork->unk_390[aid] = 1;
    if (aid == CommSys_CurNetId()) {
        sWork->unk_390[aid] = 3;
        return;
    }
    sWork->unk_399 = 1;
}

void CommInfo_InitPlayer(int i)
{
    TrainerInfo_Init(sWork->unk_340[i]);
    sWork->unk_390[i] = 0;
}

void CommInfo_ResetDisconnected()
{
    if (sWork == NULL) {
        return;
    }
    if (!CommSys_ConnectedCount()) {
        return;
    }
    for (u16 i = 0; i < 8; i++) {
        if (!CommSys_IsPlayerConnected(i) && (i != 0 || !CommSys_IsAlone()) && sWork->unk_390[i] != 0) {
            CommInfo_InitPlayer(i);
        }
    }
}

D3Info *CommInfo_GetPlayerInfo(u16 aid)
{
    if (sWork == NULL) {
        return NULL;
    }
    switch (sWork->unk_390[aid]) {
    case 1:
    case 2:
    case 3:
        return sWork->unk_340[aid];
    }
    return NULL;
}

void TrainerInfo_Init(D3Info *info)
{
    memset(info, 0, sizeof(D3Info));
    info->unk_19 = 2;
}
