// The FIFO between the two CPUs, the ARM9's side (the SDK's PXI_* API, pxi_fifo.c): tagged words in both directions.
// An ARM7 part of ntros (Pxi_SetArm7Service) takes the game's word as part of the send; words for ARM7 parts ntros
// doesn't have go to the port (NtrOs_SetPxiForward). Words for the game raise the FIFO receive interrupt, whose
// handler hands them to the callback the game set for their tag; a word nobody listens to goes back with the error
// flag set, as the SDK's handler does. The FIFO never fills up here.
#include <deque>
#include <mutex>

#include "ntros.h"

#include "internal.hpp"

namespace ntros {
namespace {

    struct Word {
        int tag;
        uPtr data;
        BOOL err;
    };

    bool sInitialized;
    PXIFifoCallback sRecv[PXI_MAX_FIFO_TAG];
    PxiService sArm7[PXI_MAX_FIFO_TAG];
    NtrOsPxiForward sForward;
    std::mutex sMutex; // guards sToArm9 (the port's ARM7 parts reply from their own threads)
    std::deque<Word> sToArm9;

    void SendToArm7(int tag, uPtr data, BOOL err)
    {
        if (sArm7[tag] != NULL) {
            sArm7[tag](tag, data, err);
        } else if (sForward != NULL) {
            sForward(tag, data, err);
        }
    }

    // OS_IE_FIFO_RECV
    void RecvHandler()
    {
        for (;;) {
            Word word;
            {
                std::lock_guard<std::mutex> lock(sMutex);
                if (sToArm9.empty()) {
                    return;
                }
                word = sToArm9.front();
                sToArm9.pop_front();
            }
            if (word.tag == 0) {
                continue;
            }
            if (sRecv[word.tag] != NULL) {
                sRecv[word.tag]((PXIFifoTag)word.tag, word.data, word.err);
            } else if (!word.err) {
                SendToArm7(word.tag, word.data, TRUE);
            }
        }
    }

    void SetReady(PXIProc proc, int tag, bool ready)
    {
        OSSystemWork *work = OS_GetSystemWork();
        if (ready) {
            work->pxiHandleChecker[proc] |= 1UL << tag;
        } else {
            work->pxiHandleChecker[proc] &= ~(1UL << tag);
        }
    }

} // namespace

void Pxi_SetArm7Service(int tag, PxiService service)
{
    sArm7[tag] = service;
    SetReady(PXI_PROC_ARM7, tag, service != NULL);
}

void Pxi_SendToArm9(int tag, uPtr data, BOOL err)
{
    {
        std::lock_guard<std::mutex> lock(sMutex);
        sToArm9.push_back({ tag, data, err });
    }
    if (OnGameThread()) {
        RaiseIrq(OS_IE_FIFO_RECV);
    }
}

void Pxi_Step()
{
    bool pending;
    {
        std::lock_guard<std::mutex> lock(sMutex);
        pending = !sToArm9.empty();
    }
    if (pending) {
        RaiseIrq(OS_IE_FIFO_RECV);
    }
}

} // namespace ntros

using namespace ntros;

extern "C" {

void PXI_InitFifo(void)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    if (!sInitialized) {
        sInitialized = true;
        OS_GetSystemWork()->pxiHandleChecker[PXI_PROC_ARM9] = 0;
        for (int i = 0; i < PXI_MAX_FIFO_TAG; i++) {
            sRecv[i] = NULL;
        }
        (void)OS_ResetRequestIrqMask(OS_IE_FIFO_RECV);
        OS_SetIrqFunction(OS_IE_FIFO_RECV, RecvHandler);
        (void)OS_EnableIrqMask(OS_IE_FIFO_RECV);
        Sound_Init(); // the ARM7 has started its sound thread by now
    }
    (void)OS_RestoreInterrupts(enabled);
}

void PXI_SetFifoRecvCallback(int fifotag, PXIFifoCallback callback)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    sRecv[fifotag] = callback;
    SetReady(PXI_PROC_ARM9, fifotag, callback != NULL);
    (void)OS_RestoreInterrupts(enabled);
}

BOOL PXI_IsCallbackReady(int fifotag, PXIProc proc)
{
    return (OS_GetSystemWork()->pxiHandleChecker[proc] & (1UL << fifotag)) ? TRUE : FALSE;
}

// The send FIFO is never full, so its "empty" interrupt has nothing to report
void PXI_SetFifoSendCallback(PXIFifoEmtpyCallback callback)
{
    OSIntrMode enabled = OS_DisableInterrupts();
    OS_SetIrqFunction(OS_IE_FIFO_SEND, callback);
    (void)OS_RestoreInterrupts(enabled);
}

int PXI_SendWordByFifo(int fifotag, uPtr data, BOOL err)
{
    SendToArm7(fifotag, data, err);
    return PXI_FIFO_SUCCESS;
}

// The SDK's FIFO receive interrupt handler, which some libraries call directly while interrupts are off
void PXIi_HandlerRecvFifoNotEmpty(void)
{
    RecvHandler();
}

void NtrOs_SetPxiForward(NtrOsPxiForward forward)
{
    sForward = forward;
}

void NtrOs_PxiReply(int tag, unsigned long long data, int err)
{
    Pxi_SendToArm9(tag, (uPtr)data, (BOOL)err);
}

} // extern "C"
