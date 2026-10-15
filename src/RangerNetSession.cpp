#include <nitro/math.h>

#include "common.hpp"
#include "heap.hpp"

// D4: wireless session setup (02128A94..02128F1C)

// defined in RangerNetPlayerInfo.cpp (see there)
struct RangerNetSessionParam {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0C[0x14];
};
extern RangerNetSessionParam gRangerNetSessionParam;

struct D4Work {
    u8 unk_00[0x8];
    MATHRandContext32 unk_08;
    void (*unk_20)();
    RangerNetSessionParam *unk_24;
    u8 unk_28[0x6];
    u16 unk_2E;
    u8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 unk_34;
    u8 unk_35[0x2];
    u8 unk_37;
    u8 unk_38[0x4];
    u8 unk_3C;
    u8 unk_3D[0x7];
};

static D4Work *sWork;
static u8 sFreak[] = "FREAK";
static u8 sGame[] = " GAME";
static u8 sFull[] = " FULL";

void CommInfo_Init(); // D3 (RangerNetPlayerInfo.cpp)
void CommServerClient_Init(RangerNetSessionParam *param); // D5
BOOL WirelessDriver_IsReady(); // D5
BOOL CommServerClient_StepFinalize(); // D5
BOOL CommSys_InitServer(int arg, int flag3, int size, int flag5);
void CommSys_SwitchTransitionTypeToParallel();
void CommSys_Delete();
void CommSys_SendDataFixedSizeServer(u8 cmd, u8 *data);
BOOL CommSys_IsPlayerConnected(u16 aid);
BOOL CommSys_IsInitialized();
u16 CommSys_CurNetId();
void CommSys_Seed(MATHRandContext32 *ctx);
struct CommCmdTable;
void CommCmd_Init(const CommCmdTable *cmdTable, int count, void *arg);
void CommCmd_Delete();

void CommManager_SetTask(void (*func)(), u16 n);
void CommTask_End();
void CommTask_EndConnection();
void CommTask_ConnectingBattleServer();
void CommTask_WaitBattleServer();
void CommTask_StartBattleServer();

void CommManager_Initialize(u8 arg)
{
    if (sWork != NULL) {
        return;
    }
    sWork = (D4Work *)Heap_Alloc(sizeof(D4Work));
    MI_CpuFill8(sWork, 0, sizeof(D4Work));
    sWork->unk_2E = 0x32;
    sWork->unk_37 = 1;
    sWork->unk_24 = &gRangerNetSessionParam;
    sWork->unk_30 = 2;
    sWork->unk_31 = 0;
    sWork->unk_3C = 0;
    sWork->unk_33 = arg;
    CommSys_Seed(&sWork->unk_08);
    CommCmd_Init(NULL, 0, 0);
}

void CommManager_Free()
{
    if (sWork == NULL) {
        return;
    }
    CommCmd_Delete();
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

BOOL CommManager_IsInitialized()
{
    if (sWork != NULL) {
        return TRUE;
    }
    return FALSE;
}

void CommManager_StartBattleServer(u8 arg)
{
    if (CommSys_IsInitialized()) {
        return;
    }
    CommManager_Initialize(arg);
    sWork->unk_33 = arg;
    CommManager_SetTask(CommTask_StartBattleServer, 0);
}

void CommManager_EndBattle()
{
    if (sWork != NULL) {
        CommManager_SetTask(CommTask_EndConnection, 5);
    }
}

extern "C" void thunk_FUN_overlay_11__02128b40()
{
    CommManager_Free();
}

void CommManager_Update()
{
    if (sWork != NULL && sWork->unk_20 != NULL) {
        sWork->unk_20();
    }
}

void CommManager_SetTask(void (*func)(), u16 n)
{
    sWork->unk_20 = func;
    sWork->unk_2E = n;
}

void CommTask_End()
{
    if (CommSys_IsInitialized()) {
        return;
    }
    CommManager_Free();
}

void CommTask_EndConnection()
{
    if (sWork->unk_2E != 0) {
        sWork->unk_2E--;
    }
    if (!CommServerClient_StepFinalize()) {
        return;
    }
    if (sWork->unk_2E != 0) {
        return;
    }
    CommSys_Delete();
    CommManager_SetTask(CommTask_End, 0);
}

void CommManager_ValidateConfirmationMessage(u8 aid, int size, u8 *data)
{
    u32 i;
    BOOL match;

    if (CommSys_CurNetId() != 0) {
        return;
    }
    match = TRUE;
    for (i = 0; i < 6; i++) {
        if (sFreak[i] != data[i]) {
            match = FALSE;
            break;
        }
    }
    if (match && sWork->unk_3C == 0) {
        sGame[0] = aid;
        CommSys_SendDataFixedSizeServer(7, sGame);
        return;
    }
    sFull[0] = aid;
    CommSys_SendDataFixedSizeServer(7, sFull);
}

void CommManager_ValidateConfirmationResponseMessage(int aid, int size, u8 *data)
{
    u8 id;
    u32 i;
    BOOL match;

    match = TRUE;
    for (i = 1; i < 6; i++) {
        if (sGame[i] != data[i]) {
            match = FALSE;
            break;
        }
    }
    if (match) {
        id = data[0];
        if (id == CommSys_CurNetId()) {
            sWork->unk_31 = 1;
        }
        return;
    }
    match = TRUE;
    for (i = 1; i < 6; i++) {
        if (sFull[i] != data[i]) {
            match = FALSE;
            break;
        }
    }
    if (match) {
        id = data[0];
        if (id == (u8)CommSys_CurNetId()) {
            sWork->unk_31 = 2;
        }
    }
}

u32 CommManager_ConfirmationMessage_sizeof()
{
    return sizeof(sFreak);
}

void CommTask_ConnectingBattleServer()
{
    if (!CommSys_IsPlayerConnected(CommSys_CurNetId())) {
        return;
    }
    CommManager_SetTask(CommTask_WaitBattleServer, 0);
}

void CommTask_WaitBattleServer()
{
    if (CommSys_IsInitialized()) {
        return;
    }
    CommManager_SetTask(CommTask_End, 0);
}

void CommTask_StartBattleServer()
{
    if (!WirelessDriver_IsReady()) {
        return;
    }
    CommServerClient_Init(sWork->unk_24);
    CommInfo_Init();
    if (!CommSys_InitServer(1, 1, 0x200, 1)) {
        return;
    }
    CommSys_SwitchTransitionTypeToParallel();
    CommManager_SetTask(CommTask_ConnectingBattleServer, 0);
}

int CommManager_GetCommType()
{
    if (sWork != NULL) {
        return sWork->unk_33;
    }
    return 1;
}

u8 CommManager_GetContestRegulation()
{
    if (sWork != NULL) {
        return sWork->unk_34;
    }
    return 0;
}
