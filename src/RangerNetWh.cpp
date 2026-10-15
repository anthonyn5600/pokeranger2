#include <nitro/wm.h>
#include <string.h>

#include "common.hpp"
#include "heap.hpp"

// D1: NitroSDK demo WH library (wh.c) with its statics in a heap work block (021272F8..02128478)

enum {
    WH_SYSSTATE_STOP,
    WH_SYSSTATE_IDLE,
    WH_SYSSTATE_SCANNING,
    WH_SYSSTATE_BUSY,
    WH_SYSSTATE_CONNECTED,
    WH_SYSSTATE_DATASHARING,
    WH_SYSSTATE_KEYSHARING,
    WH_SYSSTATE_MEASURECHANNEL,
    WH_SYSSTATE_CONNECT_FAIL,
    WH_SYSSTATE_ERROR,
    WH_SYSSTATE_FATAL,
};

enum {
    WH_CONNECTMODE_MP_PARENT,
    WH_CONNECTMODE_MP_CHILD,
    WH_CONNECTMODE_KS_PARENT,
    WH_CONNECTMODE_KS_CHILD,
    WH_CONNECTMODE_DS_PARENT,
    WH_CONNECTMODE_DS_CHILD,
};

enum {
    WH_ERRCODE_DISCONNECTED = WM_ERRCODE_MAX,
    WH_ERRCODE_PARENT_NOT_FOUND,
    WH_ERRCODE_NO_RADIO,
    WH_ERRCODE_LOST_PARENT,
    WH_ERRCODE_NOMORE_CHANNEL,
    WH_ERRCODE_FATAL,
};

typedef void (*WHReceiverFunc)(u16 aid, u16 *data, u16 size);
typedef void (*WHSendCallbackFunc)(BOOL result);
typedef void (*WHDisconnectFunc)(u16 aid);

struct WhWork {
    u8 wmBuffer[0xF20];
    WMParentParam parentParam;
    u8 sendBuffer[0xE0];
    u8 recvBuffer[0x2E4];
    u32 sendBufferSize;
    u32 recvBufferSize;
    u8 unk_132C[0x4];
    int sysState;
    int connectMode;
    WHReceiverFunc receiverFunc;
    void *unk_133C;
    u8 unk_1340[0x4];
    WHDisconnectFunc disconnectFunc;
    u16 myAid;
    u16 connectBitmap;
    int errCode;
    u8 maxChildren;
    u8 unk_1351;
    u8 unk_1352[0x2];
    u32 rand;
    u16 channel;
    u16 channelBusyRatio;
    u16 channelBitmap;
    u8 unk_135E;
    u8 unk_135F;
    u8 unk_1360;
    u8 beaconCount;
    u8 unk_1362[0x2];
};

static WhWork *sWork;
static u32 sUnused; // second word of the TU's .bss: only ov11_RangerNetWhUnused (stripped) uses it

#define RAND_INIT(x) (sWork->rand = (u32)(x))
#define RAND()       (sWork->rand = sWork->rand * 69069UL + 12345)

int CommManager_GetCommType(); // D4

BOOL WH_StateInStartParent();
BOOL WH_StateInStartParentMP();
BOOL WH_StateInEndParent();
BOOL WH_StateInEndChild();
BOOL WH_StateInReset();
int WH_GetConnectedCount();
u16 WH_StateInMeasureChannel(u16 channel);
WMErrCode WH_MeasureChannel(WMCallbackFunc callback, u16 channel);
s16 WH_SelectChannel(u16 bitmap);
BOOL WH_StateInInitialize();
void WH_Reset();
void WH_Finalize();

void WH_ChangeSysState(int state)
{
    sWork->sysState = state;
}

void WH_SetError(int code)
{
    if (sWork->sysState == WH_SYSSTATE_ERROR || sWork->sysState == WH_SYSSTATE_FATAL) {
        return;
    }
    sWork->errCode = code;
}

void WH_StateOutSetParentParam(void *arg);

BOOL WH_StateInSetParentParam()
{
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    WMErrCode result = WM_SetParentParameter(WH_StateOutSetParentParam, &sWork->parentParam);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutSetParentParam(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return;
    }
    if (!WH_StateInStartParent()) {
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
    }
}

void WH_StateOutStartParent(void *arg);

BOOL WH_StateInStartParent()
{
    if (sWork->sysState == WH_SYSSTATE_CONNECTED || sWork->sysState == WH_SYSSTATE_KEYSHARING || sWork->sysState == WH_SYSSTATE_DATASHARING) {
        return TRUE;
    }
    WMStatus *status = (WMStatus *)WMi_GetStatusAddress();
    DC_InvalidateRange(&status->wep_flag, 4);
    status->wep_flag = 0;
    DC_FlushRange(&status->wep_flag, 4);
    WMErrCode result = WM_StartParent(WH_StateOutStartParent);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        return FALSE;
    }
    sWork->myAid = 0;
    sWork->connectBitmap = 1;
    return TRUE;
}

void WH_StateOutStartParent(void *arg)
{
    WMStartParentCallback *cb = (WMStartParentCallback *)arg;
    const u16 target_bitmap = (u16)(1 << cb->aid);

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return;
    }

    switch (cb->state) {
    case WM_STATECODE_BEACON_SENT:
        sWork->beaconCount++;
        break;
    case WM_STATECODE_CONNECTED:
        if (sWork->unk_135F == 1 || sWork->unk_135E == 1 || WH_GetConnectedCount() >= sWork->maxChildren || cb->ssid[0] != CommManager_GetCommType() || memcmp("DP", &cb->ssid[1], 3) != 0) {
            WMErrCode result = WM_Disconnect(NULL, cb->aid);
            if (result != WM_ERRCODE_OPERATING) {
                WH_SetError(result);
                WH_ChangeSysState(WH_SYSSTATE_ERROR);
            }
            break;
        }
        sWork->connectBitmap |= target_bitmap;
        break;
    case WM_STATECODE_DISCONNECTED:
        sWork->connectBitmap &= ~target_bitmap;
        if (sWork->disconnectFunc != NULL) {
            sWork->disconnectFunc(cb->aid);
        }
        break;
    case WM_STATECODE_DISCONNECTED_FROM_MYSELF:
        break;
    case WM_STATECODE_PARENT_START:
        if (!WH_StateInStartParentMP()) {
            WH_ChangeSysState(WH_SYSSTATE_ERROR);
        }
        break;
    }
}

void WH_StateOutStartParentMP(void *arg);

BOOL WH_StateInStartParentMP()
{
    if (sWork->sysState == WH_SYSSTATE_CONNECTED || sWork->sysState == WH_SYSSTATE_KEYSHARING || sWork->sysState == WH_SYSSTATE_DATASHARING) {
        return TRUE;
    }
    WH_ChangeSysState(WH_SYSSTATE_CONNECTED);
    WMErrCode result = WM_StartMP(WH_StateOutStartParentMP, (u16 *)sWork->recvBuffer, (u16)sWork->recvBufferSize, (u16 *)sWork->sendBuffer, (u16)sWork->sendBufferSize, 1);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutStartParentMP(void *arg)
{
    WMStartMPCallback *cb = (WMStartMPCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return;
    }

    switch (cb->state) {
    case WM_STATECODE_MP_START:
        if (sWork->connectMode == WH_CONNECTMODE_KS_PARENT) {
            if (sWork->sysState == WH_SYSSTATE_CONNECTED) {
            } else if (sWork->sysState == WH_SYSSTATE_KEYSHARING) {
                break;
            }
        }
        WH_ChangeSysState(WH_SYSSTATE_CONNECTED);
        break;
    case WM_STATECODE_MPEND_IND:
        break;
    case WM_STATECODE_MP_IND:
    case WM_STATECODE_MPACK_IND:
        break;
    }
}

void WH_StateOutEndParentMP(void *arg);

BOOL WH_StateInEndParentMP()
{
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    WMErrCode result = WM_EndMP(WH_StateOutEndParentMP);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutEndParentMP(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        WH_Reset();
        return;
    }
    if (!WH_StateInEndParent()) {
        WH_Reset();
        return;
    }
}

void WH_StateOutEndParent(void *arg);

BOOL WH_StateInEndParent()
{
    WMErrCode result = WM_EndParent(WH_StateOutEndParent);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutEndParent(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        return;
    }
    WH_ChangeSysState(WH_SYSSTATE_IDLE);
}

BOOL WH_EndScan()
{
    if (sWork->sysState != WH_SYSSTATE_SCANNING) {
        return FALSE;
    }
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    return TRUE;
}

void WH_StateOutEndChildMP(void *arg);

BOOL WH_StateInEndChildMP()
{
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    WMErrCode result = WM_EndMP(WH_StateOutEndChildMP);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutEndChildMP(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        WH_Finalize();
        return;
    }
    if (!WH_StateInEndChild()) {
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
    }
}

void WH_StateOutEndChild(void *arg);

BOOL WH_StateInEndChild()
{
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    WMErrCode result = WM_Disconnect(WH_StateOutEndChild, 0);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        WH_Reset();
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutEndChild(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        return;
    }
    WH_ChangeSysState(WH_SYSSTATE_IDLE);
}

void WH_StateOutReset(void *arg);

BOOL WH_StateInReset()
{
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    WMErrCode result = WM_Reset(WH_StateOutReset);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutReset(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        WH_SetError(cb->errcode);
        return;
    }
    WH_ChangeSysState(WH_SYSSTATE_IDLE);
}

void WH_StateOutSetMPData(void *arg);

BOOL WH_StateInSetMPData(const void *data, u16 size, int port, WHSendCallbackFunc callback)
{
    DC_FlushRange(sWork->sendBuffer, sWork->sendBufferSize);
    WMErrCode result = WM_SetMPDataToPortEx(WH_StateOutSetMPData, (void *)callback, (const u16 *)data, size, 0xFFFF, (u16)port, 2);
    return result == WM_ERRCODE_OPERATING;
}

void WH_StateOutSetMPData(void *arg)
{
    WMPortSendCallback *cb = (WMPortSendCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS && cb->errcode != WM_ERRCODE_SEND_FAILED) {
        WH_SetError(cb->errcode);
        return;
    }
    if (cb->arg != NULL) {
        WHSendCallbackFunc callback = (WHSendCallbackFunc)cb->arg;
        (*callback)(cb->errcode == WM_ERRCODE_SUCCESS);
    }
}

void WH_PortReceiveCallback(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
    } else if (sWork->receiverFunc != NULL) {
        if (cb->state == WM_STATECODE_PORT_INIT) {
        } else if (cb->state == WM_STATECODE_PORT_RECV) {
            (*sWork->receiverFunc)(cb->aid, cb->data, cb->length);
        } else if (cb->state == WM_STATECODE_DISCONNECTED) {
            (*sWork->receiverFunc)(cb->aid, NULL, 0);
        }
    }
}

void WH_StateOutEnd(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_ChangeSysState(WH_SYSSTATE_FATAL);
        return;
    }
    WVR_TerminateAsync(NULL, NULL);
    WH_ChangeSysState(WH_SYSSTATE_STOP);
}

void WH_SetGgid(u32 ggid)
{
    sWork->parentParam.ggid = ggid;
}

void WH_SetUserGameInfo(void *info, u16 length)
{
    sWork->parentParam.userGameInfo = (u16 *)info;
    sWork->parentParam.userGameInfoLength = length;
}

u16 WH_GetBitmap()
{
    return sWork->connectBitmap;
}

int WH_GetConnectedCount()
{
    u16 count = 0;
    u16 bitmap = sWork->connectBitmap;
    for (u16 i = 0; i < 16; i++) {
        if (bitmap & 1) {
            count++;
        }
        bitmap >>= 1;
    }
    return count;
}

int WH_GetSystemState()
{
    return sWork->sysState;
}

int WH_GetLastError()
{
    return sWork->errCode;
}

BOOL WH_StartMeasureChannel()
{
    u16 result;
    u8 macAddr[6];

    OS_GetMacAddress(macAddr);
    RAND_INIT(OS_GetVBlankCount() + *(u16 *)&macAddr[0] + *(u16 *)&macAddr[2] + *(u16 *)&macAddr[4]);
    RAND();

    sWork->channel = 0;
    sWork->channelBusyRatio = 100 + 1;

    WH_ChangeSysState(WH_SYSSTATE_BUSY);

    result = WH_StateInMeasureChannel(1);

    if (result == WH_ERRCODE_NOMORE_CHANNEL) {
        WH_SetError(WH_ERRCODE_NOMORE_CHANNEL);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return FALSE;
    }

    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutMeasureChannel(void *arg);

u16 WH_StateInMeasureChannel(u16 channel)
{
    WMErrCode result;
    u16 allowedChannel;

    allowedChannel = WM_GetAllowedChannel();

    if (allowedChannel == 0x8000) {
        WH_SetError(WM_ERRCODE_ILLEGAL_STATE);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return WM_ERRCODE_ILLEGAL_STATE;
    }
    if (allowedChannel == 0) {
        WH_SetError(WH_ERRCODE_NO_RADIO);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return WH_ERRCODE_NOMORE_CHANNEL;
    }

    while (((1 << (channel - 1)) & allowedChannel) == 0) {
        channel++;
        if (channel > 16) {
            return WH_ERRCODE_NOMORE_CHANNEL;
        }
    }

    result = WH_MeasureChannel(WH_StateOutMeasureChannel, channel);
    if (result != WM_ERRCODE_OPERATING) {
        return result;
    }
    return result;
}

void WH_StateOutMeasureChannel(void *arg)
{
    u16 result;
    u16 channel;
    WMMeasureChannelCallback *cb = (WMMeasureChannelCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return;
    }

    channel = cb->channel;
    if (sWork->channelBusyRatio > cb->ccaBusyRatio) {
        sWork->channelBusyRatio = cb->ccaBusyRatio;
        sWork->channelBitmap = (u16)(1 << (channel - 1));
    } else if (sWork->channelBusyRatio == cb->ccaBusyRatio) {
        sWork->channelBitmap |= 1 << (channel - 1);
    }

    result = WH_StateInMeasureChannel((u16)(channel + 1));

    if (result == WH_ERRCODE_NOMORE_CHANNEL) {
        WH_ChangeSysState(WH_SYSSTATE_MEASURECHANNEL);
        return;
    }

    if (result != WM_ERRCODE_OPERATING) {
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return;
    }
}

WMErrCode WH_MeasureChannel(WMCallbackFunc callback, u16 channel)
{
    return WM_MeasureChannel(callback, 3, 17, channel, 30);
}

u16 WH_GetMeasureChannel()
{
    WH_ChangeSysState(WH_SYSSTATE_IDLE);
    sWork->channel = (u16)WH_SelectChannel(sWork->channelBitmap);
    return sWork->channel;
}

s16 WH_SelectChannel(u16 bitmap)
{
    s16 i;
    s16 channel = 0;
    u16 num = 0;
    u16 select;

    for (i = 0; i < 16; i++) {
        if (bitmap & (1 << i)) {
            channel = (s16)(i + 1);
            num++;
        }
    }

    if (num <= 1) {
        return channel;
    }

    select = (u16)(((RAND() & 0xFF) * num) / 0x100);

    channel = 1;

    for (i = 0; i < 16; i++) {
        if (bitmap & 1) {
            if (select == 0) {
                return (s16)(i + 1);
            }
            select--;
        }
        bitmap >>= 1;
    }

    return 0;
}

BOOL WH_Initialize()
{
    sWork = (WhWork *)Heap_AllocWithAlignment(sizeof(WhWork), 32);
    sWork->recvBufferSize = 0;
    sWork->sendBufferSize = 0;
    sWork->receiverFunc = NULL;
    sWork->myAid = 0;
    sWork->connectBitmap = 1;
    sWork->errCode = 0;
    sWork->sysState = WH_SYSSTATE_STOP;
    sWork->parentParam.userGameInfo = NULL;
    sWork->parentParam.userGameInfoLength = 0;
    sWork->unk_133C = NULL;
    sWork->maxChildren = 8;
    sWork->unk_1351 = 0;
    sWork->unk_135E = 0;
    if (!WH_StateInInitialize()) {
        return FALSE;
    }
    return TRUE;
}

u32 WH_GetHeapSize()
{
    return sizeof(WhWork) + 32;
}

void WH_IndicateHandler(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;
    if (cb->errcode == WM_ERRCODE_FIFO_ERROR) {
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        WH_SetError(WH_ERRCODE_FATAL);
    }
}

void WH_StateOutInitialize(void *arg);

BOOL WH_StateInInitialize()
{
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    WMErrCode result = WM_Initialize(sWork, WH_StateOutInitialize, 2);
    if (result != WM_ERRCODE_OPERATING) {
        WH_SetError(result);
        WH_ChangeSysState(WH_SYSSTATE_FATAL);
        return FALSE;
    }
    return TRUE;
}

void WH_StateOutInitialize(void *arg)
{
    WMErrCode result;
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        WH_SetError(cb->errcode);
        WH_ChangeSysState(WH_SYSSTATE_FATAL);
        return;
    }

    result = WM_SetIndCallback(WH_IndicateHandler);
    if (result != WM_ERRCODE_SUCCESS) {
        WH_SetError(result);
        WH_ChangeSysState(WH_SYSSTATE_FATAL);
        return;
    }

    WH_ChangeSysState(WH_SYSSTATE_IDLE);
}

BOOL WH_ParentConnect(int mode, u16 tgid, u16 channel, u16 maxEntry, u16 beaconPeriod, int entryFlag)
{
    sWork->recvBufferSize = 0x1C0;
    sWork->sendBufferSize = 0xE0;

    sWork->connectMode = mode;
    WH_ChangeSysState(WH_SYSSTATE_BUSY);

    sWork->parentParam.tgid = tgid;
    sWork->parentParam.channel = channel;
    sWork->parentParam.beaconPeriod = beaconPeriod;
    switch (mode) {
    case WH_CONNECTMODE_MP_PARENT:
        sWork->parentParam.parentMaxSize = 0xC0;
        if (maxEntry >= 5) {
            sWork->parentParam.childMaxSize = 0xC;
        } else {
            sWork->parentParam.childMaxSize = 0x26;
        }
        break;
    case WH_CONNECTMODE_DS_PARENT:
        sWork->parentParam.parentMaxSize = 0x64;
        sWork->parentParam.childMaxSize = 0xC;
        break;
    }
    sWork->parentParam.maxEntry = maxEntry;
    sWork->parentParam.CS_Flag = 0;
    sWork->parentParam.multiBootFlag = 0;
    sWork->parentParam.entryFlag = entryFlag;
    sWork->parentParam.KS_Flag = (u16)((mode == WH_CONNECTMODE_KS_PARENT) ? TRUE : FALSE);

    switch (mode) {
    case WH_CONNECTMODE_MP_PARENT:
    case WH_CONNECTMODE_KS_PARENT:
    case WH_CONNECTMODE_DS_PARENT:
        return WH_StateInSetParentParam();
    default:
        break;
    }

    return FALSE;
}

void WH_SetReceiver(WHReceiverFunc proc, int port)
{
    sWork->receiverFunc = proc;
    if (WM_SetPortCallback((u16)port, WH_PortReceiveCallback, NULL) != WM_ERRCODE_SUCCESS) {
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        while (TRUE) {
        }
    }
}

extern "C" BOOL thunk_FUN_overlay_11__02127904(const void *data, u16 size, int port, WHSendCallbackFunc callback)
{
    return WH_StateInSetMPData(data, size, port, callback);
}

void WH_Reset()
{
    if (sWork->sysState == WH_SYSSTATE_SCANNING) {
        while (TRUE) {
        }
    }
    if (!WH_StateInReset()) {
        WH_ChangeSysState(WH_SYSSTATE_FATAL);
    }
}

void WH_Finalize()
{
    if (sWork->sysState == WH_SYSSTATE_IDLE) {
        return;
    }

    if (sWork->sysState != WH_SYSSTATE_KEYSHARING && sWork->sysState != WH_SYSSTATE_DATASHARING && sWork->sysState != WH_SYSSTATE_CONNECTED) {
        WH_ChangeSysState(WH_SYSSTATE_BUSY);
        WH_Reset();
        return;
    }

    WH_ChangeSysState(WH_SYSSTATE_BUSY);

    switch (sWork->connectMode) {
    case WH_CONNECTMODE_DS_CHILD:
    case WH_CONNECTMODE_MP_CHILD:
        if (!WH_StateInEndChildMP()) {
            WH_Reset();
        }
        break;
    case WH_CONNECTMODE_DS_PARENT:
    case WH_CONNECTMODE_MP_PARENT:
        if (!WH_StateInEndParentMP()) {
            WH_Reset();
        }
        break;
    }
}

BOOL WH_End()
{
    WH_ChangeSysState(WH_SYSSTATE_BUSY);
    WMErrCode result = WM_End(WH_StateOutEnd);
    if (result != WM_ERRCODE_OPERATING) {
        WH_ChangeSysState(WH_SYSSTATE_ERROR);
        return FALSE;
    }
    return TRUE;
}

u16 WH_GetCurrentAid()
{
    return sWork->myAid;
}

BOOL WH_IsSysStateIdle()
{
    return sWork->sysState == WH_SYSSTATE_IDLE;
}

BOOL WH_IsSysStateBusy()
{
    return sWork->sysState == WH_SYSSTATE_BUSY;
}

BOOL WH_IsSysStateError()
{
    return sWork->sysState == WH_SYSSTATE_ERROR;
}

BOOL WH_IsSysStateScan()
{
    if (sWork != NULL) {
        return sWork->sysState == WH_SYSSTATE_SCANNING;
    }
    return FALSE;
}

void WH_SetGameInfo(void *info, int length, u32 ggid, int tgid)
{
    if (sWork->sysState != WH_SYSSTATE_CONNECTED) {
        return;
    }
    WM_SetGameInfo(NULL, (u16 *)info, (u16)length, ggid, (u16)tgid, WM_ATTR_FLAG_ENTRY);
}

void WH_ResetBeaconCount()
{
    sWork->beaconCount = 0;
}

u8 WH_GetPauseConnection()
{
    return sWork->unk_135E;
}

// Never called: mwld strips it, but it keeps sUnused in this TU's .bss (the original's 4 orphan bytes at 02169C48)
u32 ov11_RangerNetWhUnused()
{
    return sUnused;
}
