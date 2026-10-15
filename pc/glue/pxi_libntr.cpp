// libntr's ARM7 parts the port still uses (wireless, ...) talk to the game through ntros's FIFO: words for them go
// into libntr's queue to its ARM7 thread, and their answers come back through NtrOs_PxiReply
#include <nitro.h>
#include <simulator/queue.h>
#include <simulator/sim.h>
#include <stdlib.h>

#include "ntros.h"

extern "C" SIM_queue_t *pxiQueuePtr;
extern "C" PXIFifoCallback FifoRecvCallbackTable7[PXI_MAX_FIFO_TAG];
PXIFifoCallback FifoRecvCallbackTable7[PXI_MAX_FIFO_TAG];

namespace {

void Forward(int tag, unsigned long long data, int err)
{
    WIN_PXIFifoMessage *msg = (WIN_PXIFifoMessage *)malloc(sizeof(WIN_PXIFifoMessage));
    msg->e.tag = (u32)tag;
    msg->e.err = (u32)err;
    msg->e.data = data;
    SIM_queue_write(pxiQueuePtr, msg);
    SIM_PostPxiThread();
}

const bool sForwarding = (NtrOs_SetPxiForward(Forward), true);

} // namespace

extern "C" void PXI_SetFifoRecvCallback7(int fifotag, PXIFifoCallback callback)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    FifoRecvCallbackTable7[fifotag] = callback;
    OSSystemWork *work = OS_GetSystemWork();
    if (callback != NULL) {
        work->pxiHandleChecker[PXI_PROC_ARM7] |= 1UL << fifotag;
    } else {
        work->pxiHandleChecker[PXI_PROC_ARM7] &= ~(1UL << fifotag);
    }
    (void)OS_RestoreInterrupts(enabled);
}

extern "C" int PXI_SendWordByFifo7(int fifotag, uPtr data, BOOL err)
{
    NtrOs_PxiReply(fifotag, data, err);
    return PXI_FIFO_SUCCESS;
}

// libntr's own ARM7 -> ARM9 queue stays empty: answers go through ntros
extern "C" PXIFifoCallback PXI_WIN_GetCallback(u32)
{
    return NULL;
}
