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
u32 ov11_02128654();
void *ov11_0212865C();
void ov11_02128670(int i);
void ov11_0212CA60(const CommCmdTable *cmdTable, int count, void *arg);
int ov11_0212CCF0();

static const CommCmdTable sSessionCmds[] = {
    { (CommCmdFunc)ov11_02128634, (CommCmdSizeFunc)ov11_02128654, (CommCmdBufferFunc)ov11_0212865C },
    { (CommCmdFunc)ov11_02128670, ov11_0212CCF0, NULL },
};

void ov11_0212CDF4(int arg)
{
    ov11_0212CA60(sSessionCmds, 2, (void *)arg);
}
