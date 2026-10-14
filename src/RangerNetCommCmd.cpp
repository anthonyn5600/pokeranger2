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
void ov11_021287EC();
void ov11_021287F4();
void ov11_02128810(int aid, int size, D3Entry *data);
void ov11_021288BC(int aid, int size, D3Entry *data);
void ov11_02128CC8(u8 aid, int size, u8 *data);
void ov11_02128D64(int aid, int size, u8 *data);
void ov11_02128E30();
void ov11_02129970(u8 aid, int size, u8 *data);
void ov11_02129A1C(int aid, int size, const u8 *data);
void ov11_02129A3C(int aid, int size, const u8 *data);
void ov11_02129AEC(int aid, int size, const u8 *data);
void ov11_02129B14();
void ov11_02129B1C(int idx, int size, const void *data);
void ov11_02129B58();
BOOL ov11_0212BA98(u8 cmd, u8 *data, u16 size);
BOOL ov11_0212BEA0(u16 aid);
u16 ov11_0212C154();
BOOL ov11_0212C198(u8 cmd, u8 *data);
void ov11_0212C09C(int aid, int size, u8 *data);
void ov11_0212C0D4(int aid, int size, u8 *data);
void ov11_0212C10C(int aid, int size, u8 *data);
void ov11_0212C1EC();
void ov11_0212C2E4();

int ov11_0212CCF0();
int ov11_0212CCF8();
int ov11_0212CD00();
static void ov11_0212CD08(int netId, int size, void *data, void *arg);
static void ov11_0212CD80(int netId, int size, void *data, void *arg);
static void ov11_0212CDC4(int netId, int size, void *data, void *arg);

static const CommCmdTable sBuiltinCmds[] = {
    { NULL, ov11_0212CCF0, NULL },
    { NULL, ov11_0212CCF0, NULL },
    { (CommCmdFunc)ov11_0212C1EC, ov11_0212CCF0, NULL },
    { (CommCmdFunc)ov11_021288BC, (CommCmdSizeFunc)ov11_021287EC, NULL },
    { (CommCmdFunc)ov11_02128810, (CommCmdSizeFunc)ov11_021287EC, NULL },
    { (CommCmdFunc)ov11_021287F4, ov11_0212CCF0, NULL },
    { (CommCmdFunc)ov11_02128CC8, (CommCmdSizeFunc)ov11_02128E30, NULL },
    { (CommCmdFunc)ov11_02128D64, (CommCmdSizeFunc)ov11_02128E30, NULL },
    { NULL, NULL, NULL },
    { NULL, NULL, NULL },
    { (CommCmdFunc)ov11_0212C09C, ov11_0212CCF8, NULL },
    { (CommCmdFunc)ov11_0212C0D4, ov11_0212CCF8, NULL },
    { (CommCmdFunc)ov11_0212C10C, ov11_0212CCF8, NULL },
    { ov11_0212CD08, ov11_0212CCF0, NULL },
    { ov11_0212CD80, ov11_0212CCF0, NULL },
    { ov11_0212CDC4, ov11_0212CCF0, NULL },
    { (CommCmdFunc)ov11_02129970, ov11_0212CCF8, NULL },
    { (CommCmdFunc)ov11_02129A3C, ov11_0212CCF8, NULL },
    { (CommCmdFunc)ov11_02129A1C, ov11_0212CD00, NULL },
    { (CommCmdFunc)ov11_02129AEC, (CommCmdSizeFunc)ov11_02129B14, NULL },
    { (CommCmdFunc)ov11_02129B1C, (CommCmdSizeFunc)ov11_02129B58, NULL },
};

static CommCmdManager *sCommCmdManager;

void ov11_0212CA60(const CommCmdTable *cmdTable, int count, void *arg)
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

void ov11_0212CAE0()
{
    if (sCommCmdManager == NULL) {
        return;
    }
    if (sCommCmdManager != NULL) {
        Heap_Free(sCommCmdManager);
    }
    sCommCmdManager = NULL;
}

void ov11_0212CB10(int netId, int cmd, int size, void *data)
{
    CommCmdFunc func;

    if (cmd < 22) {
        func = sBuiltinCmds[cmd].func;
    } else {
        if (cmd > sCommCmdManager->count + 22) {
            ov11_0212C2E4();
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

int ov11_0212CBA4(int cmd)
{
    int size = 0;
    CommCmdSizeFunc func;

    if (cmd < 22) {
        func = sBuiltinCmds[cmd].sizeFunc;
    } else {
        if (sCommCmdManager == NULL) {
            ov11_0212C2E4();
            return size;
        }
        if (cmd > sCommCmdManager->count + 22) {
            ov11_0212C2E4();
            return size;
        }
        func = sCommCmdManager->cmdTable[cmd - 22].sizeFunc;
    }
    if (func != NULL) {
        size = func();
    }
    return size;
}

BOOL ov11_0212CC34(int cmd)
{
    if (cmd < 22) {
        return sBuiltinCmds[cmd].bufferFunc != NULL;
    }
    return sCommCmdManager->cmdTable[cmd - 22].bufferFunc != NULL;
}

void *ov11_0212CC90(int cmd, int netId, int size)
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

int ov11_0212CCF0()
{
    return 0;
}

int ov11_0212CCF8()
{
    return 1;
}

int ov11_0212CD00()
{
    return 2;
}

static void ov11_0212CD08(int netId, int size, void *data, void *arg)
{
    int i;

    if (ov11_0212C154() != 0) {
        return;
    }
    sCommCmdManager->unk_0C[netId] = 1;
    for (i = 0; i < 8; i++) {
        if (!ov11_0212BEA0(i)) {
            continue;
        }
        if (!sCommCmdManager->unk_0C[i]) {
            return;
        }
    }
    ov11_0212BA98(14, NULL, 0);
}

static void ov11_0212CD80(int netId, int size, void *data, void *arg)
{
    sCommCmdManager->cmdTable = NULL;
    sCommCmdManager->count = 0;
    sCommCmdManager->arg = NULL;
    sCommCmdManager->unk_14 = 1;
    ov11_0212C198(15, (u8 *)data);
}

static void ov11_0212CDC4(int netId, int size, void *data, void *arg)
{
    if (ov11_0212C154() != 0) {
        return;
    }
    sCommCmdManager->unk_0C[netId] = 0;
}
