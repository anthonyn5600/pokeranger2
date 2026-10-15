#include <nitro/wm.h>

#include "common.hpp"

// D0: WH-style wireless state machine (02124F00..021272F8); statics reached through getters

struct WhMacLo {
    u32 v;
};

struct WhMacHi {
    u16 v;
};

struct WhId {
    u32 unk_00 : 8;
    u32 unk_08 : 4;
    u32 unk_0C : 4;
    u32 unk_10 : 16;
};

struct WhInfo {
    WhId unk_00;
    WhId unk_04;
};

struct WhName {
    u16 s[12];
};

// beacon userGameInfo
struct WhUserInfo {
    WhInfo info;
    WhName unk_08;
    WhName unk_20;
};

struct WhInitParam {
    WhId id;
    u16 *unk_04;
    u16 *unk_08;
};

struct WhParentEntry {
    u32 macLo;
    WhName unk_04;
    WhName unk_1C;
    u16 macHi;
    u8 unk_36;
    u8 unk_37;
};

struct WhScan {
    WhParentEntry entries[1];
    u16 unk_38;
    u8 unk_3A;
    u8 unk_3B_0 : 4;
    u8 unk_3B_4 : 4;
};

struct WhChildEntry {
    u32 macLo;
    u16 macHi;
    u16 aid;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
};

struct WhMeasure {
    WhChildEntry unk_00[1];
    u8 unk_0C;
    u8 unk_0D;
    u16 unk_0E;
    u8 unk_10;
    u8 unk_11[3];
};

struct WhPacket {
    WhInfo info;
    u32 unk_08 : 8;
    u32 unk_08_8 : 8;
    u32 unk_08_16 : 16;
    u32 unk_0C : 8;
    u32 unk_0C_8 : 24;
};

struct WhState {
    void *unk_00;
    void *unk_04;
    void *unk_08;
    void *unk_0C;
    int unk_10;
    int unk_14;
    u8 unk_18;
    volatile u8 unk_19; // re-read in 02125C28's && chain
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
};

struct WhWork {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    int unk_04;
    u8 unk_08[0x04];
    u16 unk_0C;
    u8 unk_0E[0x02];
    BOOL unk_10;
    int unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    WMScanParam *unk_24;
    WMBssDesc *unk_28;
    int unk_2C;
    int unk_30;
    void *unk_34;
    void *unk_38;
    void *unk_3C;
    WhUserInfo userInfo;
    WhInfo unk_78;
    u8 unk_80[0x10];
    WhMeasure unk_90;
    u8 unk_A4[0x28];
    WhState unk_CC;
};

static WMParentParam sParentParam ATTRIBUTE_ALIGN(32) = {
    NULL,
    0,
    0,
    0x400131,
    0,
    1,
    9,
    0,
    0,
    0,
    200,
    { 0 },
    { 0 },
    0,
    0x40,
    0x40,
    { 0 },
};
static WhWork sWork;

WhWork *Wireless_GetWork();
void *Wireless_GetPeerWork();
WMParentParam *Wireless_GetParentParam();
void Wireless_SetState(u8 error);
u8 Wireless_GetRequestedState();
void Wireless_SetRequestedState(u8 state);
void Wireless_SetFinished(int v);
WhMeasure *Wireless_GetParentWork();
WhMacLo Wireless_PackMacLo(const u8 *mac);
WhMacHi Wireless_PackMacHi(const u8 *mac);
WMScanParam *Wireless_GetScanParam();
WMBssDesc *Wireless_GetBssDesc();
void Wireless_PrintError(WMErrCode result); // empty (failure report)
void Wireless_PrintState(u16 state); // empty
BOOL Wireless_WmDisable();
BOOL Wireless_WmMeasureChannel(int channel);
BOOL Wireless_WmSetParentParameter();
BOOL Wireless_WmStartParent();
BOOL Wireless_WmPowerOn();
BOOL Wireless_WmReset();
BOOL Wireless_WmStartMP();
void Wireless_DumpChildren(void *p); // empty
void Wireless_SetAid(u16 v);
WhScan *Wireless_GetScanWork();
BOOL Wireless_WmStartScan();
BOOL Wireless_WmEndScan();
u8 Wireless_GetMode();
int Wireless_GetGgid();
void Wireless_InvalidateBssDesc(WMBssDesc *desc);
void Wireless_DumpScan(void *p); // empty
void Wireless_DumpPacket(void *p); // empty
BOOL Wireless_WmStartConnect();
void Wireless_SetConnected(int v);
void Wireless_SetLinkLost(int v);
int Wireless_IsConnected();
WhState *Wireless_GetTransfer();
void Wireless_DecryptPacket(void *buf);
BOOL Wireless_CheckPacketCrc(void *buf);
u8 Wireless_GetState();
BOOL Wireless_WmEnable();
BOOL Wireless_WmPowerOff();
BOOL Wireless_WmEnd();
BOOL Wireless_WmSetMPData(void *data, u32 size, u16 bitmap);
int Wireless_CalcSendBufferSize();
int Wireless_CalcRecvBufferSize();
BOOL Wireless_WmSetIndCallback();
void Wireless_ResetTransfer();
u32 Wireless_GetPacketHeaderSize();
void Wireless_BuildPacket(void *buf, const void *src, int size, int type, int id);
extern "C" u16 sub_0200071A(u32 start, const void *data, u32 size); // SVC_GetCRC16 (swi 0xE, libsyscall)
void Wireless_UpdateSend();
void Wireless_UpdateRecv();
void Wireless_SetMode(u8 v);
void Wireless_ClearParentWork();
void Wireless_EnableIfIdle();
BOOL Wireless_WmDisconnectChildren(u16 aidBitmap);
int Wireless_GetPort();
int Wireless_GetUserInfoSize();
WhUserInfo *Wireless_GetUserInfo();
WhInfo *Wireless_GetSsid();
void *Wireless_GetSendBuffer();
void *Wireless_GetRecvBuffer();
int Wireless_GetSendBufferSize();
int Wireless_GetRecvBufferSize();
u32 ov11_02126F04();
u32 ov11_02126F1C();
u32 ov11_02126F34();

void Wireless_Fail()
{
    Wireless_SetState(4);
    Wireless_WmReset();
}

WhMacLo Wireless_GetMacLo(const u8 *mac)
{
    return Wireless_PackMacLo(mac);
}

WhMacHi Wireless_GetMacHi(const u8 *mac)
{
    return Wireless_PackMacHi(mac);
}

BOOL Wireless_CheckEnd()
{
    if (Wireless_GetRequestedState() == 12) {
        WhWork *work = Wireless_GetWork();
        if (work->unk_1C == 0) {
            Wireless_WmReset();
            work->unk_1C = 1;
        }
        return TRUE;
    }
    return FALSE;
}

void Wireless_RemoveChild(u32 aid)
{
    WhMeasure *m = Wireless_GetParentWork();
    if (m->unk_00[0].macLo == 0) {
        return;
    }
    if (aid == m->unk_00[0].aid) {
        m->unk_00[0].unk_08 = 0;
        m->unk_00[0].unk_0A = 0;
    }
}

int Wireless_NextMeasureChannel()
{
    WhMeasure *m = Wireless_GetParentWork();
    if (m->unk_0E & 1) {
        m->unk_0E &= ~1;
        return 1;
    }
    if (m->unk_0E & 0x40) {
        m->unk_0E &= ~0x40;
        return 7;
    }
    if (m->unk_0E & 0x1000) {
        m->unk_0E &= ~0x1000;
        return 13;
    }
    return 0;
}

BOOL Wireless_InitMeasureChannel()
{
    WhMeasure *m = Wireless_GetParentWork();
    m->unk_0C = 1;
    m->unk_0E = WM_GetAllowedChannel();
    if (m->unk_0E != 0 && m->unk_0E != 0x8000) {
        m->unk_0D = 102;
        m->unk_10 = 0;
        return TRUE;
    }
    return FALSE;
}

void Wireless_InitParentParam()
{
    WMParentParam *param = Wireless_GetParentParam();
    param->beaconPeriod = WM_GetDispersionBeaconPeriod();
    param->tgid = WM_GetNextTgid();
}

void Wireless_InitScanParam()
{
    WMScanParam *param = Wireless_GetScanParam();
    param->scanBuf = Wireless_GetBssDesc();
    param->channel = Wireless_GetParentParam()->channel;
    param->maxChannelTime = WM_GetDispersionScanPeriod();
    param->bssid[0] = 0xFF;
    param->bssid[1] = 0xFF;
    param->bssid[2] = 0xFF;
    param->bssid[3] = 0xFF;
    param->bssid[4] = 0xFF;
    param->bssid[5] = 0xFF;
}

void Wireless_NextScanChannel()
{
    WMScanParam *param = Wireless_GetScanParam();
    u16 allowed = WM_GetAllowedChannel();
    if (allowed == 0) {
        return;
    }
    u16 channel = param->channel;
    for (int i = 0; i < 16; i++) {
        if (allowed & (1 << ((channel + i) % 16))) {
            param->channel = (channel + i) % 16 + 1;
            return;
        }
    }
}

void Wireless_OnIndication(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;
    Wireless_PrintState(cb->state);
    if (cb->errcode == WM_ERRCODE_FIFO_ERROR) {
        Wireless_PrintError((WMErrCode)cb->errcode);
        Wireless_Fail();
    }
}

void Wireless_OnSetMPData(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    Wireless_PrintState(((u16 *)arg)[4]);
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        Wireless_PrintError((WMErrCode)cb->errcode);
    }
}

void Wireless_OnEnable(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        Wireless_SetState(2);
        if (Wireless_GetRequestedState() == 12) {
            Wireless_WmDisable();
            Wireless_SetState(2);
            return;
        }
        if (!Wireless_WmPowerOn()) {
            Wireless_WmDisable();
            Wireless_SetState(2);
        }
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_WmDisable();
}

void Wireless_OnDisable(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (Wireless_GetRequestedState() == 12) {
            WM_Finish();
            Wireless_SetState(12);
            Wireless_SetFinished(1);
            return;
        }
        Wireless_SetState(1);
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_SetState(4);
    OS_Terminate();
}

void Wireless_OnMeasureChannel(void *arg)
{
    WMMeasureChannelCallback *cb = (WMMeasureChannelCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        WhMeasure *m = Wireless_GetParentWork();
        if (m->unk_0D > cb->ccaBusyRatio) {
            m->unk_0D = cb->ccaBusyRatio;
            m->unk_10 = cb->channel;
        }
        int channel = Wireless_NextMeasureChannel();
        if (channel != 0) {
            if (!Wireless_WmMeasureChannel(channel)) {
                Wireless_Fail();
            }
            return;
        }
        if (m->unk_0D < 102) {
            Wireless_InitParentParam();
            if (!Wireless_WmSetParentParameter()) {
                Wireless_Fail();
            }
            return;
        }
        Wireless_Fail();
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_Fail();
}

void Wireless_OnSetParentParameter(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (Wireless_CheckEnd()) {
            return;
        }
        if (!Wireless_WmStartParent()) {
            Wireless_Fail();
        }
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_Fail();
}

void Wireless_OnStartParent(void *arg)
{
    WMStartParentCallback *cb = (WMStartParentCallback *)arg;
    Wireless_PrintState(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        WhMeasure *m = Wireless_GetParentWork();
        Wireless_SetState(8);
        if (Wireless_CheckEnd()) {
            return;
        }
        if (m->unk_0C == 1) {
            m->unk_0C = 2;
        }
        switch (cb->state) {
        case WM_STATECODE_PARENT_START:
            if (!Wireless_WmStartMP()) {
                Wireless_Fail();
                return;
            }
            Wireless_SetAid(0);
            break;
        case WM_STATECODE_BEACON_SENT:
            break;
        case WM_STATECODE_CHILD_CONNECTED: {
            Wireless_DumpChildren(Wireless_GetParentWork());
            if (m->unk_0C != 2) {
                return;
            }
            WhInfo *info = (WhInfo *)cb->ssid;
            if (ov11_02126F04() != info->unk_00.unk_00) {
                return;
            }
            if (ov11_02126F1C() < info->unk_00.unk_08) {
                return;
            }
            if (ov11_02126F34() != info->unk_04.unk_10) {
                return;
            }
            WhChildEntry *table = Wireless_GetParentWork()->unk_00;
            WhMacLo lo = Wireless_GetMacLo(cb->macAddress);
            WhMacHi hi = Wireless_GetMacHi(cb->macAddress);
            for (int i = 0; i < 1; i++) {
                WhChildEntry *e = &table[i];
                if (e->macLo == lo.v) {
                    table[i].aid = cb->aid;
                    table[i].unk_0A = 1;
                    return;
                }
                if (table[i].macLo == 0) {
                    table[i].macLo = lo.v;
                    table[i].macHi = hi.v;
                    table[i].aid = cb->aid;
                    table[i].unk_0A = 1;
                    return;
                }
            }
            break;
        }
        case WM_STATECODE_DISCONNECTED:
            Wireless_RemoveChild(cb->aid);
            break;
        }
    } else {
        Wireless_PrintError((WMErrCode)cb->errcode);
        Wireless_Fail();
    }
}

BOOL Wireless_AddParent(WMStartScanCallback *cb, WMBssDesc *desc)
{
    WhParentEntry *table = Wireless_GetScanWork()->entries;
    WhMacLo lo = Wireless_GetMacLo(desc->bssid);
    WhMacHi hi = Wireless_GetMacHi(desc->bssid);
    for (int i = 0; i < 1; i++) {
        WhParentEntry *e = &table[i];
        if (e->macLo == lo.v && e->macHi == hi.v) {
            return TRUE;
        }
        if (table[i].macLo == 0) {
            WhUserInfo *info = (WhUserInfo *)desc->gameInfo.userGameInfo;
            table[i].macLo = lo.v;
            table[i].unk_04 = info->unk_08;
            table[i].unk_1C = info->unk_20;
            table[i].macHi = hi.v;
            table[i].unk_36 = cb->linkLevel;
            return TRUE;
        }
    }
    return FALSE;
}

void Wireless_ContinueScan()
{
    Wireless_NextScanChannel();
    if (!Wireless_WmStartScan()) {
        Wireless_Fail();
    }
}

BOOL Wireless_OnParentFound(WMStartScanCallback *cb)
{
    WMBssDesc *desc = Wireless_GetBssDesc();
    WhScan *scan = Wireless_GetScanWork();
    if (Wireless_CheckEnd()) {
        return TRUE;
    }
    BOOL found = FALSE;
    for (int i = 0; i < 1; i++) {
        if (scan->entries[i].macLo != 0) {
            found = TRUE;
            break;
        }
    }
    if (found && scan->unk_38 == 0) {
        if (!Wireless_WmEndScan()) {
            Wireless_Fail();
        }
        return TRUE;
    }
    DC_InvalidateRange(desc, sizeof(WMBssDesc));
    Wireless_DumpScan(Wireless_GetScanWork());
    if (cb->gameInfoLength >= 8 && desc->gameInfo.ggid == Wireless_GetGgid()) {
        WhInfo *info = (WhInfo *)desc->gameInfo.userGameInfo;
        if (ov11_02126F04() == info->unk_00.unk_00 && ov11_02126F1C() >= info->unk_00.unk_08 && ov11_02126F34() == info->unk_04.unk_10) {
            if (Wireless_AddParent(cb, desc)) {
                if (++Wireless_GetScanWork()->unk_3A > 28) {
                    if (!Wireless_WmEndScan()) {
                        Wireless_Fail();
                        return TRUE;
                    }
                }
            } else {
                if (!Wireless_WmEndScan()) {
                    Wireless_Fail();
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

void Wireless_OnStartScan(void *arg)
{
    WMStartScanCallback *cb = (WMStartScanCallback *)arg;
    Wireless_PrintState(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        Wireless_InvalidateBssDesc(Wireless_GetBssDesc());
        Wireless_SetState(6);
        if (Wireless_CheckEnd()) {
            return;
        }
        if (Wireless_GetMode() == 1) {
            Wireless_GetScanWork()->unk_3B_4 = 1;
        }
        switch (cb->state) {
        case WM_STATECODE_PARENT_FOUND:
            if (Wireless_OnParentFound(cb)) {
                break;
            }
            // fall through
        case WM_STATECODE_PARENT_NOT_FOUND:
            Wireless_ContinueScan();
            break;
        default:
            Wireless_PrintError((WMErrCode)cb->errcode);
            Wireless_Fail();
            break;
        }
    } else {
        Wireless_PrintError((WMErrCode)cb->errcode);
        Wireless_Fail();
    }
}

void Wireless_OnEndScan(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        Wireless_SetState(7);
        if (Wireless_CheckEnd()) {
            return;
        }
        if (Wireless_GetMode() != 1) {
            return;
        }
        if (Wireless_GetScanWork()->unk_3B_4 != 2) {
            return;
        }
        if (!Wireless_WmStartConnect()) {
            Wireless_Fail();
            return;
        }
        Wireless_SetState(3);
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_Fail();
}

void Wireless_OnStartConnect(void *arg)
{
    WMStartConnectCallback *cb = (WMStartConnectCallback *)arg;
    Wireless_PrintState(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        Wireless_SetState(9);
        if (Wireless_CheckEnd()) {
            return;
        }
        switch (cb->state) {
        case WM_STATECODE_CONNECT_START:
            break;
        case WM_STATECODE_CONNECTED:
            Wireless_SetAid(cb->aid);
            Wireless_SetConnected(1);
            Wireless_SetLinkLost(0);
            if (!Wireless_WmStartMP()) {
                Wireless_Fail();
            }
            break;
        case WM_STATECODE_BEACON_LOST:
            break;
        case WM_STATECODE_DISCONNECTED:
            if (Wireless_IsConnected()) {
                Wireless_SetLinkLost(1);
            }
            Wireless_SetConnected(0);
            break;
        default:
            Wireless_PrintError((WMErrCode)cb->errcode);
            Wireless_Fail();
            break;
        }
    } else {
        Wireless_PrintError((WMErrCode)cb->errcode);
        Wireless_Fail();
    }
}

void Wireless_StartMode()
{
    switch (Wireless_GetMode()) {
    case 2:
        if (Wireless_InitMeasureChannel()) {
            if (Wireless_WmMeasureChannel(Wireless_NextMeasureChannel())) {
                Wireless_GetParentWork()->unk_0C = 1;
                Wireless_SetState(3);
                return;
            }
        }
        Wireless_Fail();
        break;
    case 1:
        Wireless_InitScanParam();
        if (!Wireless_WmStartScan()) {
            Wireless_Fail();
            return;
        }
        Wireless_SetState(3);
        break;
    }
}

void Wireless_OnDisconnectChildren(void *arg)
{
    WMDisconnectCallback *cb = (WMDisconnectCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        u16 bitmap = cb->disconnectedBitmap;
        for (u32 aid = 1; aid < 16; aid++) {
            if (bitmap & (1 << aid)) {
                Wireless_RemoveChild(aid);
            }
        }
        if (Wireless_CheckEnd()) {
            return;
        }
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_Fail();
}

void Wireless_OnStartMP(void *arg)
{
    WMStartMPCallback *cb = (WMStartMPCallback *)arg;
    Wireless_PrintState(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (cb->apiid == WM_APIID_START_MP && Wireless_CheckEnd()) {
            return;
        }
        switch (Wireless_GetMode()) {
        case 2:
            Wireless_SetState(10);
            break;
        case 1:
            Wireless_SetState(11);
            break;
        }
    } else if (cb->errcode != WM_ERRCODE_TIMEOUT && cb->errcode != WM_ERRCODE_INVALID_POLLBITMAP
        && cb->errcode != WM_ERRCODE_SEND_FAILED) {
        Wireless_Fail();
    }
}

void Wireless_RecvAck(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    WhState *st = Wireless_GetTransfer();
    if (st->unk_19 != 1) {
        return;
    }
    WhPacket *pkt = (WhPacket *)st->unk_0C;
    DC_FlushRange(cb->data, cb->length);
    MI_CpuCopy8(cb->data, st->unk_0C, cb->length);
    if (ov11_02126F04() != pkt->info.unk_00.unk_00) {
        return;
    }
    if (ov11_02126F1C() < pkt->info.unk_00.unk_08) {
        return;
    }
    Wireless_DecryptPacket(st->unk_0C);
    if (pkt->unk_08 != st->unk_1C) {
        return;
    }
    Wireless_DumpPacket(st->unk_0C);
    if (Wireless_CheckPacketCrc(st->unk_0C) && pkt->unk_08_8 != 1) {
        st->unk_19 = 2;
        return;
    }
    st->unk_19 = 0;
}

void ov11_02125B40(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    WhState *st = Wireless_GetTransfer();
    if (Wireless_GetMode() != 2) {
        return;
    }
    if (st->unk_19 == 2) {
        return;
    }
    WhPacket *pkt = (WhPacket *)st->unk_0C;
    DC_FlushRange(cb->data, cb->length);
    MI_CpuCopy8(cb->data, st->unk_0C, cb->length);
    if (ov11_02126F04() != pkt->info.unk_00.unk_00) {
        return;
    }
    if (ov11_02126F1C() < pkt->info.unk_00.unk_08) {
        return;
    }
    Wireless_DecryptPacket(st->unk_0C);
    if (pkt->unk_08 != 0xFD) {
        return;
    }
    WhChildEntry *table = Wireless_GetParentWork()->unk_00;
    for (int i = 0; i < 1; i++) {
        if (cb->aid == table[i].aid) {
            table[i].unk_08 = 1;
            table[i].unk_09 = 3;
            st->unk_1A = 180;
            st->unk_19 = 0;
            return;
        }
    }
}

void Wireless_RecvData(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    WhState *st = Wireless_GetTransfer();
    if (st->unk_1C == 0xFD) {
        ov11_02125B40(cb);
        return;
    }
    if (st->unk_19 != 1 && st->unk_19 != 3) {
        return;
    }
    if (st->unk_1B != 0) {
        return;
    }
    WhPacket *pkt = (WhPacket *)st->unk_0C;
    DC_FlushRange(cb->data, cb->length);
    MI_CpuCopy8(cb->data, st->unk_0C, cb->length);
    if (ov11_02126F04() != pkt->info.unk_00.unk_00) {
        return;
    }
    if (ov11_02126F1C() < pkt->info.unk_00.unk_08) {
        return;
    }
    Wireless_DecryptPacket(st->unk_0C);
    if (pkt->unk_08 != st->unk_1C) {
        return;
    }
    Wireless_DumpPacket(st->unk_0C);
    st->unk_19 = 0;
    if (Wireless_CheckPacketCrc(st->unk_0C)) {
        if (pkt->unk_08 == 0xFD) {
            ov11_02125B40(cb);
        } else {
            MI_CpuCopy8((u8 *)st->unk_0C + pkt->unk_0C, st->unk_04, pkt->unk_0C_8);
        }
        pkt->unk_08_8 = 0;
        st->unk_1B = 4;
        return;
    }
    pkt->unk_08_8 = 1;
}

void Wireless_OnPortRecv(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    Wireless_PrintState(cb->state);
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        return;
    }
    switch (cb->state) {
    case WM_STATECODE_PORT_RECV: {
        u8 state = Wireless_GetState();
        if (state != 10 && state != 11) {
            return;
        }
        switch (Wireless_GetTransfer()->unk_18) {
        case 1:
            Wireless_RecvAck(cb);
            break;
        case 2:
            Wireless_RecvData(cb);
            break;
        }
        break;
    }
    case WM_STATECODE_CONNECTED:
        Wireless_SetConnected(1);
        Wireless_SetLinkLost(0);
        break;
    case WM_STATECODE_DISCONNECTED:
        if (Wireless_IsConnected()) {
            Wireless_SetLinkLost(1);
        }
        switch (Wireless_GetState()) {
        case 10:
            Wireless_RemoveChild(cb->aid);
            break;
        case 11:
            Wireless_SetConnected(0);
            break;
        }
        break;
    }
}

void Wireless_OnPowerOn(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (Wireless_CheckEnd()) {
            return;
        }
        Wireless_StartMode();
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_SetState(4);
    OS_Terminate();
}

void Wireless_OnPowerOff(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (!Wireless_WmDisable()) {
            OS_Terminate();
            return;
        }
        Wireless_SetState(2);
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_Fail();
}

void Wireless_OnReset(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        Wireless_SetAid(0);
        if (Wireless_GetRequestedState() == 12) {
            if (!Wireless_WmEnd()) {
                OS_Terminate();
                return;
            }
            Wireless_SetState(3);
            return;
        }
        if (!Wireless_WmPowerOff()) {
            OS_Terminate();
            return;
        }
        Wireless_SetState(3);
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_SetState(4);
    OS_Terminate();
}

void Wireless_OnEnd(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        Wireless_SetState(12);
        Wireless_SetFinished(1);
        return;
    }
    Wireless_PrintError((WMErrCode)cb->errcode);
    Wireless_SetState(4);
    OS_Terminate();
}

BOOL Wireless_WmSetIndCallback()
{
    if (WM_SetIndCallback(Wireless_OnIndication) != WM_ERRCODE_SUCCESS) {
        Wireless_SetState(4);
        return FALSE;
    }
    return TRUE;
}

void Wireless_EnableIfIdle()
{
    u8 state = Wireless_GetState();
    if (state != 0 && state != 1 && state != 2) {
        return;
    }
    Wireless_WmEnable();
}

void Wireless_SendData(void *data, u32 size, u16 bitmap)
{
    if (size > Wireless_GetParentParam()->parentMaxSize) {
        return;
    }
    DC_FlushRange(data, size);
    Wireless_WmSetMPData(data, size, bitmap);
}

int Wireless_CalcSendBufferSize()
{
    return 0x5C0;
}

int Wireless_CalcRecvBufferSize()
{
    return 0x5C0;
}

int Wireless_GetWorkSize()
{
    int size = 0xF00;
    size += Wireless_CalcSendBufferSize() * 2;
    size += Wireless_CalcRecvBufferSize() * 2;
    size += 0x100;
    return size;
}

void Wireless_Init(WhInitParam *param, u32 buf)
{
    WMParentParam *parent = Wireless_GetParentParam();
    WhWork *work = Wireless_GetWork();
    u8 mac[WM_SIZE_MACADDR];
    u32 rem = buf & 0x1F;
    if (rem != 0) {
        buf += 0x20 - rem;
    }
    OS_GetMacAddress(mac);
    work->unk_00 = 0;
    work->unk_01 = 0;
    work->unk_02 = 0;
    work->unk_03 = 4;
    work->unk_04 = 0x400131;
    work->unk_0C = 0;
    work->unk_34 = (void *)buf;
    buf += WM_SYSTEM_BUF_SIZE;
    work->unk_38 = (void *)buf;
    work->unk_2C = Wireless_CalcSendBufferSize();
    buf += work->unk_2C;
    work->unk_3C = (void *)buf;
    work->unk_30 = Wireless_CalcRecvBufferSize();
    buf += work->unk_30;
    work->unk_28 = (WMBssDesc *)buf;
    work->unk_24 = (WMScanParam *)(buf + sizeof(WMBssDesc));
    buf += sizeof(WMBssDesc) + 0x20;
    WM_Init(work->unk_34, 2);
    work->unk_10 = Wireless_WmSetIndCallback();
    work->unk_14 = 0;
    work->unk_18 = 0;
    work->unk_1C = 0;
    work->unk_20 = 0;
    work->userInfo.info.unk_00.unk_00 = 15;
    work->userInfo.info.unk_00.unk_08 = 1;
    work->userInfo.info.unk_00.unk_0C = 1;
    work->userInfo.info.unk_04.unk_00 = param->id.unk_00;
    work->userInfo.info.unk_04.unk_08 = param->id.unk_08;
    work->userInfo.info.unk_04.unk_0C = param->id.unk_0C;
    work->userInfo.info.unk_04.unk_10 = param->id.unk_10;
    u16 *name1 = param->unk_08;
    u16 *name2 = param->unk_04;
    for (u32 i = 0; name1 != NULL && i < 12; i++) {
        work->userInfo.unk_08.s[i] = *name1++;
        work->userInfo.unk_20.s[i] = *name2++;
    }
    work->unk_78 = work->userInfo.info;
    Wireless_ResetTransfer();
    Wireless_GetTransfer()->unk_08 = (void *)buf;
    buf += work->unk_2C;
    Wireless_GetTransfer()->unk_0C = (void *)buf;
    WM_GetNextTgid();
}

void Wireless_UpdateSend()
{
    WhState *st = Wireless_GetTransfer();
    if (st->unk_19 == 1) {
        if (--st->unk_1A != 0) {
            return;
        }
        st->unk_19 = 0;
    }
    if (st->unk_19 != 0) {
        return;
    }
    int size = 0x40 - Wireless_GetPacketHeaderSize();
    Wireless_BuildPacket(st->unk_08, st->unk_04, size, 3, st->unk_1C);
    Wireless_SendData(st->unk_08, size + Wireless_GetPacketHeaderSize(), 0xFFFF);
    st->unk_19 = 1;
    st->unk_1A = 60;
}

void Wireless_UpdateRecv()
{
    WhState *st = Wireless_GetTransfer();
    if (st->unk_19 != 0) {
        return;
    }
    if (st->unk_1C == 0xFD) {
        WhChildEntry *table = Wireless_GetParentWork()->unk_00;
        for (int i = 0; i < 1; i++) {
            if (table[i].unk_09 != 0) {
                u16 bitmap = 1 << table[i].aid;
                Wireless_BuildPacket(st->unk_08, st->unk_04, 0, 0, 0xFD);
                Wireless_SendData(st->unk_08, Wireless_GetPacketHeaderSize(), bitmap);
                table[i].unk_09--;
                return;
            }
        }
        if (--st->unk_1A == 0) {
            st->unk_19 = 2;
        }
        return;
    }
    Wireless_GetPacketHeaderSize();
    Wireless_CalcSendBufferSize();
    u32 flag = ((WhPacket *)st->unk_0C)->unk_08_8;
    if (flag == 0) {
        if (st->unk_1B == 0) {
            st->unk_19 = 2;
            return;
        }
        st->unk_1B--;
    }
    Wireless_BuildPacket(st->unk_08, st->unk_04, 0, flag, st->unk_1C);
    Wireless_SendData(st->unk_08, Wireless_GetPacketHeaderSize(), 0xFFFF);
}

void Wireless_UpdateTransfer()
{
    switch (Wireless_GetTransfer()->unk_18) {
    case 1:
        Wireless_UpdateSend();
        break;
    case 2:
        Wireless_UpdateRecv();
        break;
    }
}

void Wireless_UpdateChild()
{
    WhScan *scan = Wireless_GetScanWork();
    switch (Wireless_GetState()) {
    case 6:
        if (scan->unk_38 != 0) {
            scan->unk_38--;
        }
        break;
    case 11:
        Wireless_UpdateTransfer();
        break;
    }
}

void Wireless_UpdateParent()
{
    if (Wireless_GetState() != 10) {
        return;
    }
    Wireless_UpdateTransfer();
}

void Wireless_Update()
{
    if (Wireless_GetState() == 12) {
        return;
    }
    if (Wireless_GetRequestedState() == 12) {
        if (Wireless_GetState() != 7) {
            return;
        }
        Wireless_WmReset();
        return;
    }
    switch (Wireless_GetMode()) {
    case 1:
        Wireless_UpdateChild();
        break;
    case 2:
        Wireless_UpdateParent();
        break;
    default:
        Wireless_GetWork();
        Wireless_GetState();
        break;
    }
}

void Wireless_StartParent()
{
    Wireless_ClearParentWork();
    Wireless_SetMode(2);
    Wireless_EnableIfIdle();
}

int Wireless_CountParents()
{
    u8 mode = Wireless_GetMode();
    int n = 0;
    if (mode != 1) {
        OS_Terminate();
    }
    if (mode == 1) {
        WhScan *scan = Wireless_GetScanWork();
        if (scan->unk_3B_4 == 1 && scan->entries[0].macLo != 0) {
            n++;
        }
    }
    return n;
}

u32 Wireless_GetParentMacLo(int index)
{
    return Wireless_GetScanWork()->entries[index].macLo;
}

int Wireless_CountChildren()
{
    u8 mode = Wireless_GetMode();
    int n = 0;
    if (mode != 2) {
        OS_Terminate();
    }
    if (mode == 2) {
        WhMeasure *m = Wireless_GetParentWork();
        if (m->unk_0C == 2 && m->unk_00[0].macLo != 0 && m->unk_00[0].unk_0A != 0) {
            n++;
        }
    }
    return n;
}

int Wireless_CountReadyChildren()
{
    u8 mode = Wireless_GetMode();
    int n = 0;
    if (mode != 2) {
        OS_Terminate();
    }
    if (mode == 2) {
        WhMeasure *m = Wireless_GetParentWork();
        if (m->unk_0C == 2 && m->unk_00[0].macLo != 0 && m->unk_00[0].unk_08 != 0 && m->unk_00[0].unk_0A != 0) {
            n++;
        }
    }
    return n;
}

u32 Wireless_GetReadyChildIndex(int index)
{
    WhChildEntry *e = Wireless_GetParentWork()->unk_00;
    int n = 0;
    for (u32 i = 0; i < 1; i++, e++) {
        if (e->macLo != 0 && e->unk_08 != 0 && e->unk_0A != 0) {
            if (n == index) {
                return i;
            }
            n++;
        }
    }
    return 0;
}

u32 Wireless_GetChildMacLo(int index)
{
    return Wireless_GetParentWork()->unk_00[index].macLo;
}

void Wireless_DisconnectOthers(u32 macLo)
{
    WhMeasure *m = Wireless_GetParentWork();
    int bitmap = 0;
    if (m->unk_00[0].macLo != 0 && macLo != m->unk_00[0].macLo && m->unk_00[0].unk_0A != 0) {
        bitmap |= 1 << m->unk_00[0].aid;
    }
    if (bitmap == 0) {
        return;
    }
    Wireless_WmDisconnectChildren(bitmap);
}

BOOL Wireless_GetConnectedCount()
{
    switch (Wireless_GetMode()) {
    case 1:
        return Wireless_CountParents();
    case 2:
        return Wireless_CountChildren();
    }
    return FALSE;
}

BOOL ov11_0212669C()
{
    switch (Wireless_GetMode()) {
    case 1:
        return FALSE;
    case 2:
        return Wireless_CountReadyChildren();
    }
    return FALSE;
}

u32 Wireless_GetPeerMacLo(int index)
{
    switch (Wireless_GetMode()) {
    case 1:
        return Wireless_GetParentMacLo(index);
    case 2:
        return Wireless_GetChildMacLo(index);
    }
    return 0;
}

u32 Wireless_GetPartnerMac(int n)
{
    return Wireless_GetPeerMacLo(Wireless_GetReadyChildIndex(n));
}

void Wireless_StartSend(void *data, int size, int id)
{
    WhState *st = Wireless_GetTransfer();
    if (id > 0xF0) {
        return;
    }
    st->unk_18 = 1;
    st->unk_19 = 0;
    st->unk_00 = data;
    st->unk_04 = data;
    st->unk_10 = size;
    st->unk_14 = size;
    st->unk_1A = 120;
    st->unk_1B = 0;
    st->unk_1C = id;
}

void ov11_02126770()
{
    WhState *st = Wireless_GetTransfer();
    if (Wireless_GetMode() != 2) {
        return;
    }
    st->unk_18 = 2;
    st->unk_19 = 3;
    st->unk_00 = NULL;
    st->unk_04 = NULL;
    st->unk_10 = 0;
    st->unk_14 = 0;
    st->unk_1A = 120;
    st->unk_1B = 0;
    st->unk_1C = 0xFD;
}

void Wireless_StartReceive(void *data)
{
    WhState *st = Wireless_GetTransfer();
    st->unk_18 = 2;
    st->unk_19 = 3;
    st->unk_00 = data;
    st->unk_04 = data;
    st->unk_10 = 0x30;
    st->unk_14 = 0;
    st->unk_1A = 120;
    st->unk_1B = 0;
    st->unk_1C = 0xFE;
}

BOOL Wireless_IsSendDone()
{
    switch (Wireless_GetMode()) {
    case 1:
    case 2:
        switch (Wireless_GetState()) {
        case 10:
        case 11:
            if (Wireless_GetTransfer()->unk_19 == 2) {
                return TRUE;
            }
            break;
        }
        break;
    }
    return FALSE;
}

BOOL Wireless_IsReceiveDone()
{
    switch (Wireless_GetMode()) {
    case 1:
    case 2:
        switch (Wireless_GetState()) {
        case 10:
        case 11:
            if (Wireless_GetTransfer()->unk_19 == 2) {
                return TRUE;
            }
            break;
        }
        break;
    }
    return FALSE;
}

BOOL ov11_02126890()
{
    if (Wireless_GetMode() == 2) {
        WhChildEntry *e = Wireless_GetParentWork()->unk_00;
        for (int i = 0; i < 1; i++, e++) {
            if (e->macLo != 0 && e->unk_0A != 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return Wireless_IsConnected();
}

BOOL ov11_021268E0()
{
    return ov11_0212669C() ? TRUE : FALSE;
}

void Wireless_End()
{
    Wireless_SetRequestedState(12);
    switch (Wireless_GetState()) {
    case 0:
    case 1:
        WM_Finish();
        Wireless_SetFinished(1);
        break;
    case 9:
        if (Wireless_IsConnected()) {
            return;
        }
        WhWork *work = Wireless_GetWork();
        Wireless_WmReset();
        work->unk_1C = 1;
        break;
    }
}

int Wireless_IsFinished()
{
    return Wireless_GetWork()->unk_20;
}

void Wireless_PrintError(WMErrCode result)
{
}

void Wireless_PrintState(u16 state)
{
}

void Wireless_InvalidateBssDesc(WMBssDesc *desc)
{
    DC_InvalidateRange(desc, sizeof(WMBssDesc));
}

void Wireless_DumpScan(void *p)
{
}

void Wireless_DumpChildren(void *p)
{
}

void Wireless_DumpPacket(void *p)
{
}

BOOL Wireless_WmSetMPData(void *data, u32 size, u16 bitmap)
{
    WMErrCode result = WM_SetMPDataToPortEx(Wireless_OnSetMPData, NULL, (const u16 *)data, size, bitmap, Wireless_GetPort(), WM_PRIORITY_NORMAL);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Wireless_PrintError(result);
    return FALSE;
}

BOOL Wireless_WmEnable()
{
    WMErrCode result = WM_Enable(Wireless_OnEnable);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmDisable()
{
    WMErrCode result = WM_Disable(Wireless_OnDisable);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmMeasureChannel(int channel)
{
    WMErrCode result = WM_MeasureChannel(Wireless_OnMeasureChannel, 3, 17, channel, 30);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmSetParentParameter()
{
    WMParentParam *param = Wireless_GetParentParam();
    WhUserInfo *info = Wireless_GetUserInfo();
    param->channel = Wireless_GetParentWork()->unk_10;
    param->userGameInfo = (u16 *)info;
    param->userGameInfoLength = Wireless_GetUserInfoSize();
    WMErrCode result = WM_SetParentParameter(Wireless_OnSetParentParameter, param);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Wireless_PrintError(result);
    return FALSE;
}

BOOL Wireless_WmStartParent()
{
    WMErrCode result = WM_StartParent(Wireless_OnStartParent);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmStartScan()
{
    WMErrCode result = WM_StartScan(Wireless_OnStartScan, Wireless_GetScanParam());
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmEndScan()
{
    WMErrCode result = WM_EndScan(Wireless_OnEndScan);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmStartConnect()
{
    WhInfo *ssid = Wireless_GetSsid();
    WMErrCode result = WM_StartConnectEx(Wireless_OnStartConnect, Wireless_GetBssDesc(), (u8 *)ssid, TRUE, 0);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Wireless_PrintError(result);
    return FALSE;
}

BOOL Wireless_WmDisconnectChildren(u16 aidBitmap)
{
    WMErrCode result = WM_DisconnectChildren(Wireless_OnDisconnectChildren, aidBitmap);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmStartMP()
{
    WMErrCode result = WM_SetPortCallback(4, Wireless_OnPortRecv, NULL);
    if (result != WM_ERRCODE_SUCCESS) {
        Wireless_PrintError(result);
        return FALSE;
    }
    int mpFreq;
    if (Wireless_GetParentParam()->CS_Flag == 0) {
        mpFreq = 1;
    } else {
        mpFreq = 0;
    }
    result = WM_StartMP(Wireless_OnStartMP, (u16 *)Wireless_GetRecvBuffer(), Wireless_GetRecvBufferSize(), (u16 *)Wireless_GetSendBuffer(), Wireless_GetSendBufferSize(), mpFreq);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Wireless_PrintError(result);
    return FALSE;
}

BOOL Wireless_WmPowerOn()
{
    WMErrCode result = WM_PowerOn(Wireless_OnPowerOn);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmPowerOff()
{
    WMErrCode result = WM_PowerOff(Wireless_OnPowerOff);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmReset()
{
    WMErrCode result = WM_Reset(Wireless_OnReset);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

BOOL Wireless_WmEnd()
{
    WMErrCode result = WM_End(Wireless_OnEnd);
    if (result != WM_ERRCODE_OPERATING) {
        Wireless_PrintError(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

WMParentParam *Wireless_GetParentParam()
{
    return &sParentParam;
}

WhWork *Wireless_GetWork()
{
    return &sWork;
}

u8 Wireless_GetState()
{
    return Wireless_GetWork()->unk_00;
}

void Wireless_SetState(u8 error)
{
    Wireless_GetWork()->unk_00 = error;
}

u8 Wireless_GetRequestedState()
{
    return Wireless_GetWork()->unk_01;
}

void Wireless_SetRequestedState(u8 state)
{
    Wireless_GetWork()->unk_01 = state;
}

u8 Wireless_GetMode()
{
    return Wireless_GetWork()->unk_02;
}

void Wireless_SetMode(u8 v)
{
    Wireless_GetWork()->unk_02 = v;
}

int Wireless_GetPort()
{
    return Wireless_GetWork()->unk_03;
}

WMScanParam *Wireless_GetScanParam()
{
    return Wireless_GetWork()->unk_24;
}

int Wireless_GetSendBufferSize()
{
    return Wireless_GetWork()->unk_2C;
}

int Wireless_GetRecvBufferSize()
{
    return Wireless_GetWork()->unk_30;
}

void *Wireless_GetSendBuffer()
{
    return Wireless_GetWork()->unk_38;
}

void *Wireless_GetRecvBuffer()
{
    return Wireless_GetWork()->unk_3C;
}

WMBssDesc *Wireless_GetBssDesc()
{
    return Wireless_GetWork()->unk_28;
}

void Wireless_SetAid(u16 v)
{
    Wireless_GetWork()->unk_0C = v;
}

int Wireless_IsConnected()
{
    return Wireless_GetWork()->unk_14;
}

void Wireless_SetConnected(int v)
{
    Wireless_GetWork()->unk_14 = v;
}

void Wireless_SetLinkLost(int v)
{
    Wireless_GetWork()->unk_18 = v;
}

void Wireless_SetFinished(int v)
{
    Wireless_GetWork()->unk_20 = v;
}

void *Wireless_GetPeerWork()
{
    return &Wireless_GetWork()->unk_90;
}

WhScan *Wireless_GetScanWork()
{
    return (WhScan *)Wireless_GetPeerWork();
}

WhMeasure *Wireless_GetParentWork()
{
    return (WhMeasure *)Wireless_GetPeerWork();
}

void Wireless_ClearParentWork()
{
    MI_CpuFill8(Wireless_GetParentWork(), 0, sizeof(WhMeasure));
}

WhState *Wireless_GetTransfer()
{
    return &Wireless_GetWork()->unk_CC;
}

void Wireless_ResetTransfer()
{
    Wireless_GetTransfer()->unk_18 = 0;
}

int Wireless_GetGgid()
{
    return Wireless_GetWork()->unk_04;
}

u32 ov11_02126F04()
{
    return Wireless_GetWork()->userInfo.info.unk_00.unk_00;
}

u32 ov11_02126F1C()
{
    return Wireless_GetWork()->userInfo.info.unk_00.unk_08;
}

u32 ov11_02126F34()
{
    return Wireless_GetWork()->userInfo.info.unk_04.unk_10;
}

int Wireless_GetUserInfoSize()
{
    return 0x38;
}

WhUserInfo *Wireless_GetUserInfo()
{
    return &Wireless_GetWork()->userInfo;
}

WhInfo *Wireless_GetSsid()
{
    return &Wireless_GetWork()->unk_78;
}

WhMacLo Wireless_PackMacLo(const u8 *mac)
{
    WhMacLo v;
    v.v = 0;
    u8 *dst = (u8 *)&v;
    for (u32 i = 0; i < 4; i++) {
        *dst++ = mac[i + 2];
    }
    return v;
}

WhMacHi Wireless_PackMacHi(const u8 *mac)
{
    WhMacHi v;
    v.v = 0;
    u8 *dst = (u8 *)&v;
    for (u32 i = 0; i < 2; i++) {
        *dst++ = mac[i];
    }
    return v;
}

void Wireless_SplitNumber(u32 value, u32 *lo, u32 *hi)
{
    *lo = value % 10000;
    *hi = value / 10000 % 10000;
}

u32 Wireless_GetPacketHeaderSize()
{
    return sizeof(WhPacket);
}

u32 Wireless_MakeSeed()
{
    return ((u32)(OS_GetTick() + GX_GetVCount()) & ~1) + 1;
}

u32 Wireless_Crypt(u32 seed, u32 size, u32 *data)
{
    u32 i = 0;
    while (i < size / 4) {
        seed = seed * 0x5D588B65 + 0x269EC3;
        u16 hi = seed >> 16;
        seed = seed * 0x5D588B65 + 0x269EC3;
        u16 lo = seed >> 16;
        *data ^= (hi << 16) | lo;
        data++;
        i++;
    }
    return seed;
}

void Wireless_BuildPacket(void *buf, const void *src, int size, int type, int id)
{
    WhPacket *pkt = (WhPacket *)buf;
    WhUserInfo *info = Wireless_GetUserInfo();
    pkt->info.unk_00.unk_00 = info->info.unk_00.unk_00;
    pkt->info.unk_00.unk_08 = info->info.unk_00.unk_08;
    pkt->info.unk_00.unk_0C = info->info.unk_00.unk_0C;
    pkt->info.unk_00.unk_10 = (u16)Wireless_MakeSeed();
    pkt->info.unk_04.unk_00 = info->info.unk_04.unk_00;
    pkt->info.unk_04.unk_08 = info->info.unk_04.unk_08;
    pkt->info.unk_04.unk_0C = info->info.unk_04.unk_0C;
    pkt->info.unk_04.unk_10 = 0;
    pkt->unk_08 = (u8)id;
    pkt->unk_08_8 = type;
    pkt->unk_08_16 = sub_0200071A(0, src, size);
    pkt->unk_0C = Wireless_GetPacketHeaderSize();
    pkt->unk_0C_8 = size;
    if (size != 0) {
        MI_CpuCopy8(src, (u8 *)pkt + pkt->unk_0C, size);
    }
    Wireless_DumpPacket(pkt);
    if (info->info.unk_00.unk_0C == 1) {
        Wireless_Crypt(pkt->info.unk_00.unk_10, size + pkt->unk_0C - 4, (u32 *)&pkt->info.unk_04);
    }
}

void Wireless_DecryptPacket(void *buf)
{
    WhPacket *pkt = (WhPacket *)buf;
    Wireless_GetUserInfo();
    if (pkt->info.unk_00.unk_0C != 1) {
        return;
    }
    u32 seed = Wireless_Crypt(pkt->info.unk_00.unk_10, 0xC, (u32 *)&pkt->info.unk_04);
    Wireless_Crypt(seed, pkt->unk_0C + pkt->unk_0C_8 - 0x10, (u32 *)((u8 *)pkt + 0x10));
}

BOOL Wireless_CheckPacketCrc(void *buf)
{
    WhPacket *pkt = (WhPacket *)buf;
    if (sub_0200071A(0, (u8 *)pkt + pkt->unk_0C, pkt->unk_0C_8) == pkt->unk_08_16) {
        return TRUE;
    }
    return FALSE;
}
