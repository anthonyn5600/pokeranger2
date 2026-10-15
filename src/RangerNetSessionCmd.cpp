#include "common.hpp"

// Command table of the Ranger Net session commands (0212CDF4..0212CE10)

typedef void (*CommCmdFunc)(int netId, int size, void *data, void *arg);
typedef int (*CommCmdSizeFunc)();
typedef void *(*CommCmdBufferFunc)(int netId, void *arg, int size);

struct CommCmdTable {
    CommCmdFunc func;
    CommCmdSizeFunc sizeFunc;
    CommCmdBufferFunc bufferFunc;
};

// RangerNetConnect.cpp, RangerNetCommCmd.cpp
void ov11_02128634(u8 v);
u32 Connect_GetRecvBufferSize();
void *Connect_GetRecvBuffer();
void ov11_02128670(int i);
void CommCmd_Init(const CommCmdTable *cmdTable, int count, void *arg);
int CommPacketSizeOf_Nothing();

static const CommCmdTable sSessionCmds[] = {
    { (CommCmdFunc)ov11_02128634, (CommCmdSizeFunc)Connect_GetRecvBufferSize, (CommCmdBufferFunc)Connect_GetRecvBuffer },
    { (CommCmdFunc)ov11_02128670, CommPacketSizeOf_Nothing, NULL },
};

void SessionCmd_Init(int arg)
{
    CommCmd_Init(sSessionCmds, 2, (void *)arg);
}
