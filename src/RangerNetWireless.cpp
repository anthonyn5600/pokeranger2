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

WhWork *ov11_02126D48();
void *ov11_02126E90();
WMParentParam *ov11_02126D3C();
void ov11_02126D64(u8 error);
u8 ov11_02126D78();
void ov11_02126D88(u8 state);
void ov11_02126E7C(int v);
WhMeasure *ov11_02126EAC();
WhMacLo ov11_02126F70(const u8 *mac);
WhMacHi ov11_02126FAC(const u8 *mac);
WMScanParam *ov11_02126DD0();
WMBssDesc *ov11_02126E20();
void ov11_02126964(WMErrCode result); // empty (failure report)
void ov11_02126968(u16 state); // empty
BOOL ov11_02126A1C();
BOOL ov11_02126A48(int channel);
BOOL ov11_02126A88();
BOOL ov11_02126ADC();
BOOL ov11_02126C90();
BOOL ov11_02126CE4();
BOOL ov11_02126BDC();
void ov11_02126980(void *p); // empty
void ov11_02126E30(u16 v);
WhScan *ov11_02126EA0();
BOOL ov11_02126B04();
BOOL ov11_02126B34();
u8 ov11_02126D9C();
int ov11_02126EF4();
void ov11_0212696C(WMBssDesc *desc);
void ov11_0212697C(void *p); // empty
void ov11_02126984(void *p); // empty
BOOL ov11_02126B5C();
void ov11_02126E54(int v);
void ov11_02126E68(int v);
int ov11_02126E44();
WhState *ov11_02126ED0();
void ov11_02127274(void *buf);
BOOL ov11_021272C4(void *buf);
u8 ov11_02126D54();
BOOL ov11_021269F4();
BOOL ov11_02126CB8();
BOOL ov11_02126D10();
BOOL ov11_02126988(void *data, u32 size, u16 bitmap);
int ov11_02125FDC();
int ov11_02125FE4();
BOOL ov11_02125F50();
void ov11_02126EE0();
u32 ov11_0212702C();
void ov11_021270B8(void *buf, const void *src, int size, int type, int id);
extern "C" u16 sub_0200071A(u32 start, const void *data, u32 size); // SVC_GetCRC16 (swi 0xE, libsyscall)
void ov11_021261C4();
void ov11_02126258();
void ov11_02126DAC(u8 v);
void ov11_02126EB8();
void ov11_02125F7C();
BOOL ov11_02126BB0(u16 aidBitmap);
int ov11_02126DC0();
int ov11_02126F48();
WhUserInfo *ov11_02126F50();
WhInfo *ov11_02126F60();
void *ov11_02126E00();
void *ov11_02126E10();
int ov11_02126DE0();
int ov11_02126DF0();
u32 ov11_02126F04();
u32 ov11_02126F1C();
u32 ov11_02126F34();

void ov11_02124F00()
{
    ov11_02126D64(4);
    ov11_02126CE4();
}

WhMacLo ov11_02124F14(const u8 *mac)
{
    return ov11_02126F70(mac);
}

WhMacHi ov11_02124F24(const u8 *mac)
{
    return ov11_02126FAC(mac);
}

BOOL ov11_02124F38()
{
    if (ov11_02126D78() == 12) {
        WhWork *work = ov11_02126D48();
        if (work->unk_1C == 0) {
            ov11_02126CE4();
            work->unk_1C = 1;
        }
        return TRUE;
    }
    return FALSE;
}

void ov11_02124F78(u32 aid)
{
    WhMeasure *m = ov11_02126EAC();
    if (m->unk_00[0].macLo == 0) {
        return;
    }
    if (aid == m->unk_00[0].aid) {
        m->unk_00[0].unk_08 = 0;
        m->unk_00[0].unk_0A = 0;
    }
}

int ov11_02124FA8()
{
    WhMeasure *m = ov11_02126EAC();
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

BOOL ov11_02125000()
{
    WhMeasure *m = ov11_02126EAC();
    m->unk_0C = 1;
    m->unk_0E = WM_GetAllowedChannel();
    if (m->unk_0E != 0 && m->unk_0E != 0x8000) {
        m->unk_0D = 102;
        m->unk_10 = 0;
        return TRUE;
    }
    return FALSE;
}

void ov11_02125048()
{
    WMParentParam *param = ov11_02126D3C();
    param->beaconPeriod = WM_GetDispersionBeaconPeriod();
    param->tgid = WM_GetNextTgid();
}

void ov11_02125068()
{
    WMScanParam *param = ov11_02126DD0();
    param->scanBuf = ov11_02126E20();
    param->channel = ov11_02126D3C()->channel;
    param->maxChannelTime = WM_GetDispersionScanPeriod();
    param->bssid[0] = 0xFF;
    param->bssid[1] = 0xFF;
    param->bssid[2] = 0xFF;
    param->bssid[3] = 0xFF;
    param->bssid[4] = 0xFF;
    param->bssid[5] = 0xFF;
}

void ov11_021250B0()
{
    WMScanParam *param = ov11_02126DD0();
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

void ov11_0212511C(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;
    ov11_02126968(cb->state);
    if (cb->errcode == WM_ERRCODE_FIFO_ERROR) {
        ov11_02126964((WMErrCode)cb->errcode);
        ov11_02124F00();
    }
}

void ov11_02125144(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    ov11_02126968(((u16 *)arg)[4]);
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        ov11_02126964((WMErrCode)cb->errcode);
    }
}

void ov11_02125168(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        ov11_02126D64(2);
        if (ov11_02126D78() == 12) {
            ov11_02126A1C();
            ov11_02126D64(2);
            return;
        }
        if (!ov11_02126C90()) {
            ov11_02126A1C();
            ov11_02126D64(2);
        }
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02126A1C();
}

void ov11_021251C4(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (ov11_02126D78() == 12) {
            WM_Finish();
            ov11_02126D64(12);
            ov11_02126E7C(1);
            return;
        }
        ov11_02126D64(1);
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02126D64(4);
    OS_Terminate();
}

void ov11_02125218(void *arg)
{
    WMMeasureChannelCallback *cb = (WMMeasureChannelCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        WhMeasure *m = ov11_02126EAC();
        if (m->unk_0D > cb->ccaBusyRatio) {
            m->unk_0D = cb->ccaBusyRatio;
            m->unk_10 = cb->channel;
        }
        int channel = ov11_02124FA8();
        if (channel != 0) {
            if (!ov11_02126A48(channel)) {
                ov11_02124F00();
            }
            return;
        }
        if (m->unk_0D < 102) {
            ov11_02125048();
            if (!ov11_02126A88()) {
                ov11_02124F00();
            }
            return;
        }
        ov11_02124F00();
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02124F00();
}

void ov11_021252A4(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (ov11_02124F38()) {
            return;
        }
        if (!ov11_02126ADC()) {
            ov11_02124F00();
        }
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02124F00();
}

void ov11_021252E0(void *arg)
{
    WMStartParentCallback *cb = (WMStartParentCallback *)arg;
    ov11_02126968(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        WhMeasure *m = ov11_02126EAC();
        ov11_02126D64(8);
        if (ov11_02124F38()) {
            return;
        }
        if (m->unk_0C == 1) {
            m->unk_0C = 2;
        }
        switch (cb->state) {
        case WM_STATECODE_PARENT_START:
            if (!ov11_02126BDC()) {
                ov11_02124F00();
                return;
            }
            ov11_02126E30(0);
            break;
        case WM_STATECODE_BEACON_SENT:
            break;
        case WM_STATECODE_CHILD_CONNECTED: {
            ov11_02126980(ov11_02126EAC());
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
            WhChildEntry *table = ov11_02126EAC()->unk_00;
            WhMacLo lo = ov11_02124F14(cb->macAddress);
            WhMacHi hi = ov11_02124F24(cb->macAddress);
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
            ov11_02124F78(cb->aid);
            break;
        }
    } else {
        ov11_02126964((WMErrCode)cb->errcode);
        ov11_02124F00();
    }
}

BOOL ov11_021254D0(WMStartScanCallback *cb, WMBssDesc *desc)
{
    WhParentEntry *table = ov11_02126EA0()->entries;
    WhMacLo lo = ov11_02124F14(desc->bssid);
    WhMacHi hi = ov11_02124F24(desc->bssid);
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

void ov11_021255EC()
{
    ov11_021250B0();
    if (!ov11_02126B04()) {
        ov11_02124F00();
    }
}

BOOL ov11_02125608(WMStartScanCallback *cb)
{
    WMBssDesc *desc = ov11_02126E20();
    WhScan *scan = ov11_02126EA0();
    if (ov11_02124F38()) {
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
        if (!ov11_02126B34()) {
            ov11_02124F00();
        }
        return TRUE;
    }
    DC_InvalidateRange(desc, sizeof(WMBssDesc));
    ov11_0212697C(ov11_02126EA0());
    if (cb->gameInfoLength >= 8 && desc->gameInfo.ggid == ov11_02126EF4()) {
        WhInfo *info = (WhInfo *)desc->gameInfo.userGameInfo;
        if (ov11_02126F04() == info->unk_00.unk_00 && ov11_02126F1C() >= info->unk_00.unk_08 && ov11_02126F34() == info->unk_04.unk_10) {
            if (ov11_021254D0(cb, desc)) {
                if (++ov11_02126EA0()->unk_3A > 28) {
                    if (!ov11_02126B34()) {
                        ov11_02124F00();
                        return TRUE;
                    }
                }
            } else {
                if (!ov11_02126B34()) {
                    ov11_02124F00();
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

void ov11_02125758(void *arg)
{
    WMStartScanCallback *cb = (WMStartScanCallback *)arg;
    ov11_02126968(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        ov11_0212696C(ov11_02126E20());
        ov11_02126D64(6);
        if (ov11_02124F38()) {
            return;
        }
        if (ov11_02126D9C() == 1) {
            ov11_02126EA0()->unk_3B_4 = 1;
        }
        switch (cb->state) {
        case WM_STATECODE_PARENT_FOUND:
            if (ov11_02125608(cb)) {
                break;
            }
            // fall through
        case WM_STATECODE_PARENT_NOT_FOUND:
            ov11_021255EC();
            break;
        default:
            ov11_02126964((WMErrCode)cb->errcode);
            ov11_02124F00();
            break;
        }
    } else {
        ov11_02126964((WMErrCode)cb->errcode);
        ov11_02124F00();
    }
}

void ov11_021257F8(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        ov11_02126D64(7);
        if (ov11_02124F38()) {
            return;
        }
        if (ov11_02126D9C() != 1) {
            return;
        }
        if (ov11_02126EA0()->unk_3B_4 != 2) {
            return;
        }
        if (!ov11_02126B5C()) {
            ov11_02124F00();
            return;
        }
        ov11_02126D64(3);
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02124F00();
}

void ov11_0212586C(void *arg)
{
    WMStartConnectCallback *cb = (WMStartConnectCallback *)arg;
    ov11_02126968(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        ov11_02126D64(9);
        if (ov11_02124F38()) {
            return;
        }
        switch (cb->state) {
        case WM_STATECODE_CONNECT_START:
            break;
        case WM_STATECODE_CONNECTED:
            ov11_02126E30(cb->aid);
            ov11_02126E54(1);
            ov11_02126E68(0);
            if (!ov11_02126BDC()) {
                ov11_02124F00();
            }
            break;
        case WM_STATECODE_BEACON_LOST:
            break;
        case WM_STATECODE_DISCONNECTED:
            if (ov11_02126E44()) {
                ov11_02126E68(1);
            }
            ov11_02126E54(0);
            break;
        default:
            ov11_02126964((WMErrCode)cb->errcode);
            ov11_02124F00();
            break;
        }
    } else {
        ov11_02126964((WMErrCode)cb->errcode);
        ov11_02124F00();
    }
}

void ov11_0212593C()
{
    switch (ov11_02126D9C()) {
    case 2:
        if (ov11_02125000()) {
            if (ov11_02126A48(ov11_02124FA8())) {
                ov11_02126EAC()->unk_0C = 1;
                ov11_02126D64(3);
                return;
            }
        }
        ov11_02124F00();
        break;
    case 1:
        ov11_02125068();
        if (!ov11_02126B04()) {
            ov11_02124F00();
            return;
        }
        ov11_02126D64(3);
        break;
    }
}

void ov11_021259B4(void *arg)
{
    WMDisconnectCallback *cb = (WMDisconnectCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        u16 bitmap = cb->disconnectedBitmap;
        for (u32 aid = 1; aid < 16; aid++) {
            if (bitmap & (1 << aid)) {
                ov11_02124F78(aid);
            }
        }
        if (ov11_02124F38()) {
            return;
        }
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02124F00();
}

void ov11_02125A08(void *arg)
{
    WMStartMPCallback *cb = (WMStartMPCallback *)arg;
    ov11_02126968(cb->state);
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (cb->apiid == WM_APIID_START_MP && ov11_02124F38()) {
            return;
        }
        switch (ov11_02126D9C()) {
        case 2:
            ov11_02126D64(10);
            break;
        case 1:
            ov11_02126D64(11);
            break;
        }
    } else if (cb->errcode != WM_ERRCODE_TIMEOUT && cb->errcode != WM_ERRCODE_INVALID_POLLBITMAP
        && cb->errcode != WM_ERRCODE_SEND_FAILED) {
        ov11_02124F00();
    }
}

void ov11_02125A80(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    WhState *st = ov11_02126ED0();
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
    ov11_02127274(st->unk_0C);
    if (pkt->unk_08 != st->unk_1C) {
        return;
    }
    ov11_02126984(st->unk_0C);
    if (ov11_021272C4(st->unk_0C) && pkt->unk_08_8 != 1) {
        st->unk_19 = 2;
        return;
    }
    st->unk_19 = 0;
}

void ov11_02125B40(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    WhState *st = ov11_02126ED0();
    if (ov11_02126D9C() != 2) {
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
    ov11_02127274(st->unk_0C);
    if (pkt->unk_08 != 0xFD) {
        return;
    }
    WhChildEntry *table = ov11_02126EAC()->unk_00;
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

void ov11_02125C28(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    WhState *st = ov11_02126ED0();
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
    ov11_02127274(st->unk_0C);
    if (pkt->unk_08 != st->unk_1C) {
        return;
    }
    ov11_02126984(st->unk_0C);
    st->unk_19 = 0;
    if (ov11_021272C4(st->unk_0C)) {
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

void ov11_02125D58(void *arg)
{
    WMPortRecvCallback *cb = (WMPortRecvCallback *)arg;
    ov11_02126968(cb->state);
    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        return;
    }
    switch (cb->state) {
    case WM_STATECODE_PORT_RECV: {
        u8 state = ov11_02126D54();
        if (state != 10 && state != 11) {
            return;
        }
        switch (ov11_02126ED0()->unk_18) {
        case 1:
            ov11_02125A80(cb);
            break;
        case 2:
            ov11_02125C28(cb);
            break;
        }
        break;
    }
    case WM_STATECODE_CONNECTED:
        ov11_02126E54(1);
        ov11_02126E68(0);
        break;
    case WM_STATECODE_DISCONNECTED:
        if (ov11_02126E44()) {
            ov11_02126E68(1);
        }
        switch (ov11_02126D54()) {
        case 10:
            ov11_02124F78(cb->aid);
            break;
        case 11:
            ov11_02126E54(0);
            break;
        }
        break;
    }
}

void ov11_02125E2C(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (ov11_02124F38()) {
            return;
        }
        ov11_0212593C();
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02126D64(4);
    OS_Terminate();
}

void ov11_02125E64(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        if (!ov11_02126A1C()) {
            OS_Terminate();
            return;
        }
        ov11_02126D64(2);
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02124F00();
}

void ov11_02125EA0(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        ov11_02126E30(0);
        if (ov11_02126D78() == 12) {
            if (!ov11_02126D10()) {
                OS_Terminate();
                return;
            }
            ov11_02126D64(3);
            return;
        }
        if (!ov11_02126CB8()) {
            OS_Terminate();
            return;
        }
        ov11_02126D64(3);
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02126D64(4);
    OS_Terminate();
}

void ov11_02125F18(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;
    if (cb->errcode == WM_ERRCODE_SUCCESS) {
        ov11_02126D64(12);
        ov11_02126E7C(1);
        return;
    }
    ov11_02126964((WMErrCode)cb->errcode);
    ov11_02126D64(4);
    OS_Terminate();
}

BOOL ov11_02125F50()
{
    if (WM_SetIndCallback(ov11_0212511C) != WM_ERRCODE_SUCCESS) {
        ov11_02126D64(4);
        return FALSE;
    }
    return TRUE;
}

void ov11_02125F7C()
{
    u8 state = ov11_02126D54();
    if (state != 0 && state != 1 && state != 2) {
        return;
    }
    ov11_021269F4();
}

void ov11_02125F9C(void *data, u32 size, u16 bitmap)
{
    if (size > ov11_02126D3C()->parentMaxSize) {
        return;
    }
    DC_FlushRange(data, size);
    ov11_02126988(data, size, bitmap);
}

int ov11_02125FDC()
{
    return 0x5C0;
}

int ov11_02125FE4()
{
    return 0x5C0;
}

int ov11_02125FEC()
{
    int size = 0xF00;
    size += ov11_02125FDC() * 2;
    size += ov11_02125FE4() * 2;
    size += 0x100;
    return size;
}

void ov11_0212600C(WhInitParam *param, u32 buf)
{
    WMParentParam *parent = ov11_02126D3C();
    WhWork *work = ov11_02126D48();
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
    work->unk_2C = ov11_02125FDC();
    buf += work->unk_2C;
    work->unk_3C = (void *)buf;
    work->unk_30 = ov11_02125FE4();
    buf += work->unk_30;
    work->unk_28 = (WMBssDesc *)buf;
    work->unk_24 = (WMScanParam *)(buf + sizeof(WMBssDesc));
    buf += sizeof(WMBssDesc) + 0x20;
    WM_Init(work->unk_34, 2);
    work->unk_10 = ov11_02125F50();
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
    ov11_02126EE0();
    ov11_02126ED0()->unk_08 = (void *)buf;
    buf += work->unk_2C;
    ov11_02126ED0()->unk_0C = (void *)buf;
    WM_GetNextTgid();
}

void ov11_021261C4()
{
    WhState *st = ov11_02126ED0();
    if (st->unk_19 == 1) {
        if (--st->unk_1A != 0) {
            return;
        }
        st->unk_19 = 0;
    }
    if (st->unk_19 != 0) {
        return;
    }
    int size = 0x40 - ov11_0212702C();
    ov11_021270B8(st->unk_08, st->unk_04, size, 3, st->unk_1C);
    ov11_02125F9C(st->unk_08, size + ov11_0212702C(), 0xFFFF);
    st->unk_19 = 1;
    st->unk_1A = 60;
}

void ov11_02126258()
{
    WhState *st = ov11_02126ED0();
    if (st->unk_19 != 0) {
        return;
    }
    if (st->unk_1C == 0xFD) {
        WhChildEntry *table = ov11_02126EAC()->unk_00;
        for (int i = 0; i < 1; i++) {
            if (table[i].unk_09 != 0) {
                u16 bitmap = 1 << table[i].aid;
                ov11_021270B8(st->unk_08, st->unk_04, 0, 0, 0xFD);
                ov11_02125F9C(st->unk_08, ov11_0212702C(), bitmap);
                table[i].unk_09--;
                return;
            }
        }
        if (--st->unk_1A == 0) {
            st->unk_19 = 2;
        }
        return;
    }
    ov11_0212702C();
    ov11_02125FDC();
    u32 flag = ((WhPacket *)st->unk_0C)->unk_08_8;
    if (flag == 0) {
        if (st->unk_1B == 0) {
            st->unk_19 = 2;
            return;
        }
        st->unk_1B--;
    }
    ov11_021270B8(st->unk_08, st->unk_04, 0, flag, st->unk_1C);
    ov11_02125F9C(st->unk_08, ov11_0212702C(), 0xFFFF);
}

void ov11_02126394()
{
    switch (ov11_02126ED0()->unk_18) {
    case 1:
        ov11_021261C4();
        break;
    case 2:
        ov11_02126258();
        break;
    }
}

void ov11_021263C4()
{
    WhScan *scan = ov11_02126EA0();
    switch (ov11_02126D54()) {
    case 6:
        if (scan->unk_38 != 0) {
            scan->unk_38--;
        }
        break;
    case 11:
        ov11_02126394();
        break;
    }
}

void ov11_02126404()
{
    if (ov11_02126D54() != 10) {
        return;
    }
    ov11_02126394();
}

void ov11_0212641C()
{
    if (ov11_02126D54() == 12) {
        return;
    }
    if (ov11_02126D78() == 12) {
        if (ov11_02126D54() != 7) {
            return;
        }
        ov11_02126CE4();
        return;
    }
    switch (ov11_02126D9C()) {
    case 1:
        ov11_021263C4();
        break;
    case 2:
        ov11_02126404();
        break;
    default:
        ov11_02126D48();
        ov11_02126D54();
        break;
    }
}

void ov11_02126480()
{
    ov11_02126EB8();
    ov11_02126DAC(2);
    ov11_02125F7C();
}

int ov11_02126498()
{
    u8 mode = ov11_02126D9C();
    int n = 0;
    if (mode != 1) {
        OS_Terminate();
    }
    if (mode == 1) {
        WhScan *scan = ov11_02126EA0();
        if (scan->unk_3B_4 == 1 && scan->entries[0].macLo != 0) {
            n++;
        }
    }
    return n;
}

u32 ov11_021264E8(int index)
{
    return ov11_02126EA0()->entries[index].macLo;
}

int ov11_02126504()
{
    u8 mode = ov11_02126D9C();
    int n = 0;
    if (mode != 2) {
        OS_Terminate();
    }
    if (mode == 2) {
        WhMeasure *m = ov11_02126EAC();
        if (m->unk_0C == 2 && m->unk_00[0].macLo != 0 && m->unk_00[0].unk_0A != 0) {
            n++;
        }
    }
    return n;
}

int ov11_02126554()
{
    u8 mode = ov11_02126D9C();
    int n = 0;
    if (mode != 2) {
        OS_Terminate();
    }
    if (mode == 2) {
        WhMeasure *m = ov11_02126EAC();
        if (m->unk_0C == 2 && m->unk_00[0].macLo != 0 && m->unk_00[0].unk_08 != 0 && m->unk_00[0].unk_0A != 0) {
            n++;
        }
    }
    return n;
}

u32 ov11_021265AC(int index)
{
    WhChildEntry *e = ov11_02126EAC()->unk_00;
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

u32 ov11_02126604(int index)
{
    return ov11_02126EAC()->unk_00[index].macLo;
}

void ov11_02126620(u32 macLo)
{
    WhMeasure *m = ov11_02126EAC();
    int bitmap = 0;
    if (m->unk_00[0].macLo != 0 && macLo != m->unk_00[0].macLo && m->unk_00[0].unk_0A != 0) {
        bitmap |= 1 << m->unk_00[0].aid;
    }
    if (bitmap == 0) {
        return;
    }
    ov11_02126BB0(bitmap);
}

BOOL ov11_02126668()
{
    switch (ov11_02126D9C()) {
    case 1:
        return ov11_02126498();
    case 2:
        return ov11_02126504();
    }
    return FALSE;
}

BOOL ov11_0212669C()
{
    switch (ov11_02126D9C()) {
    case 1:
        return FALSE;
    case 2:
        return ov11_02126554();
    }
    return FALSE;
}

u32 ov11_021266D0(int index)
{
    switch (ov11_02126D9C()) {
    case 1:
        return ov11_021264E8(index);
    case 2:
        return ov11_02126604(index);
    }
    return 0;
}

u32 ov11_02126710(int n)
{
    return ov11_021266D0(ov11_021265AC(n));
}

void ov11_02126720(void *data, int size, int id)
{
    WhState *st = ov11_02126ED0();
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
    WhState *st = ov11_02126ED0();
    if (ov11_02126D9C() != 2) {
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

void ov11_021267C4(void *data)
{
    WhState *st = ov11_02126ED0();
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

BOOL ov11_02126810()
{
    switch (ov11_02126D9C()) {
    case 1:
    case 2:
        switch (ov11_02126D54()) {
        case 10:
        case 11:
            if (ov11_02126ED0()->unk_19 == 2) {
                return TRUE;
            }
            break;
        }
        break;
    }
    return FALSE;
}

BOOL ov11_02126850()
{
    switch (ov11_02126D9C()) {
    case 1:
    case 2:
        switch (ov11_02126D54()) {
        case 10:
        case 11:
            if (ov11_02126ED0()->unk_19 == 2) {
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
    if (ov11_02126D9C() == 2) {
        WhChildEntry *e = ov11_02126EAC()->unk_00;
        for (int i = 0; i < 1; i++, e++) {
            if (e->macLo != 0 && e->unk_0A != 0) {
                return TRUE;
            }
        }
        return FALSE;
    }
    return ov11_02126E44();
}

BOOL ov11_021268E0()
{
    return ov11_0212669C() ? TRUE : FALSE;
}

void ov11_021268F8()
{
    ov11_02126D88(12);
    switch (ov11_02126D54()) {
    case 0:
    case 1:
        WM_Finish();
        ov11_02126E7C(1);
        break;
    case 9:
        if (ov11_02126E44()) {
            return;
        }
        WhWork *work = ov11_02126D48();
        ov11_02126CE4();
        work->unk_1C = 1;
        break;
    }
}

int ov11_02126954()
{
    return ov11_02126D48()->unk_20;
}

void ov11_02126964(WMErrCode result)
{
}

void ov11_02126968(u16 state)
{
}

void ov11_0212696C(WMBssDesc *desc)
{
    DC_InvalidateRange(desc, sizeof(WMBssDesc));
}

void ov11_0212697C(void *p)
{
}

void ov11_02126980(void *p)
{
}

void ov11_02126984(void *p)
{
}

BOOL ov11_02126988(void *data, u32 size, u16 bitmap)
{
    WMErrCode result = WM_SetMPDataToPortEx(ov11_02125144, NULL, (const u16 *)data, size, bitmap, ov11_02126DC0(), WM_PRIORITY_NORMAL);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_02126964(result);
    return FALSE;
}

BOOL ov11_021269F4()
{
    WMErrCode result = WM_Enable(ov11_02125168);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126A1C()
{
    WMErrCode result = WM_Disable(ov11_021251C4);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126A48(int channel)
{
    WMErrCode result = WM_MeasureChannel(ov11_02125218, 3, 17, channel, 30);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126A88()
{
    WMParentParam *param = ov11_02126D3C();
    WhUserInfo *info = ov11_02126F50();
    param->channel = ov11_02126EAC()->unk_10;
    param->userGameInfo = (u16 *)info;
    param->userGameInfoLength = ov11_02126F48();
    WMErrCode result = WM_SetParentParameter(ov11_021252A4, param);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_02126964(result);
    return FALSE;
}

BOOL ov11_02126ADC()
{
    WMErrCode result = WM_StartParent(ov11_021252E0);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126B04()
{
    WMErrCode result = WM_StartScan(ov11_02125758, ov11_02126DD0());
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126B34()
{
    WMErrCode result = WM_EndScan(ov11_021257F8);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126B5C()
{
    WhInfo *ssid = ov11_02126F60();
    WMErrCode result = WM_StartConnectEx(ov11_0212586C, ov11_02126E20(), (u8 *)ssid, TRUE, 0);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_02126964(result);
    return FALSE;
}

BOOL ov11_02126BB0(u16 aidBitmap)
{
    WMErrCode result = WM_DisconnectChildren(ov11_021259B4, aidBitmap);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126BDC()
{
    WMErrCode result = WM_SetPortCallback(4, ov11_02125D58, NULL);
    if (result != WM_ERRCODE_SUCCESS) {
        ov11_02126964(result);
        return FALSE;
    }
    int mpFreq;
    if (ov11_02126D3C()->CS_Flag == 0) {
        mpFreq = 1;
    } else {
        mpFreq = 0;
    }
    result = WM_StartMP(ov11_02125A08, (u16 *)ov11_02126E10(), ov11_02126DF0(), (u16 *)ov11_02126E00(), ov11_02126DE0(), mpFreq);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_02126964(result);
    return FALSE;
}

BOOL ov11_02126C90()
{
    WMErrCode result = WM_PowerOn(ov11_02125E2C);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126CB8()
{
    WMErrCode result = WM_PowerOff(ov11_02125E64);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126CE4()
{
    WMErrCode result = WM_Reset(ov11_02125EA0);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

BOOL ov11_02126D10()
{
    WMErrCode result = WM_End(ov11_02125F18);
    if (result != WM_ERRCODE_OPERATING) {
        ov11_02126964(result);
        OS_Terminate();
        return FALSE;
    }
    return TRUE;
}

WMParentParam *ov11_02126D3C()
{
    return &sParentParam;
}

WhWork *ov11_02126D48()
{
    return &sWork;
}

u8 ov11_02126D54()
{
    return ov11_02126D48()->unk_00;
}

void ov11_02126D64(u8 error)
{
    ov11_02126D48()->unk_00 = error;
}

u8 ov11_02126D78()
{
    return ov11_02126D48()->unk_01;
}

void ov11_02126D88(u8 state)
{
    ov11_02126D48()->unk_01 = state;
}

u8 ov11_02126D9C()
{
    return ov11_02126D48()->unk_02;
}

void ov11_02126DAC(u8 v)
{
    ov11_02126D48()->unk_02 = v;
}

int ov11_02126DC0()
{
    return ov11_02126D48()->unk_03;
}

WMScanParam *ov11_02126DD0()
{
    return ov11_02126D48()->unk_24;
}

int ov11_02126DE0()
{
    return ov11_02126D48()->unk_2C;
}

int ov11_02126DF0()
{
    return ov11_02126D48()->unk_30;
}

void *ov11_02126E00()
{
    return ov11_02126D48()->unk_38;
}

void *ov11_02126E10()
{
    return ov11_02126D48()->unk_3C;
}

WMBssDesc *ov11_02126E20()
{
    return ov11_02126D48()->unk_28;
}

void ov11_02126E30(u16 v)
{
    ov11_02126D48()->unk_0C = v;
}

int ov11_02126E44()
{
    return ov11_02126D48()->unk_14;
}

void ov11_02126E54(int v)
{
    ov11_02126D48()->unk_14 = v;
}

void ov11_02126E68(int v)
{
    ov11_02126D48()->unk_18 = v;
}

void ov11_02126E7C(int v)
{
    ov11_02126D48()->unk_20 = v;
}

void *ov11_02126E90()
{
    return &ov11_02126D48()->unk_90;
}

WhScan *ov11_02126EA0()
{
    return (WhScan *)ov11_02126E90();
}

WhMeasure *ov11_02126EAC()
{
    return (WhMeasure *)ov11_02126E90();
}

void ov11_02126EB8()
{
    MI_CpuFill8(ov11_02126EAC(), 0, sizeof(WhMeasure));
}

WhState *ov11_02126ED0()
{
    return &ov11_02126D48()->unk_CC;
}

void ov11_02126EE0()
{
    ov11_02126ED0()->unk_18 = 0;
}

int ov11_02126EF4()
{
    return ov11_02126D48()->unk_04;
}

u32 ov11_02126F04()
{
    return ov11_02126D48()->userInfo.info.unk_00.unk_00;
}

u32 ov11_02126F1C()
{
    return ov11_02126D48()->userInfo.info.unk_00.unk_08;
}

u32 ov11_02126F34()
{
    return ov11_02126D48()->userInfo.info.unk_04.unk_10;
}

int ov11_02126F48()
{
    return 0x38;
}

WhUserInfo *ov11_02126F50()
{
    return &ov11_02126D48()->userInfo;
}

WhInfo *ov11_02126F60()
{
    return &ov11_02126D48()->unk_78;
}

WhMacLo ov11_02126F70(const u8 *mac)
{
    WhMacLo v;
    v.v = 0;
    u8 *dst = (u8 *)&v;
    for (u32 i = 0; i < 4; i++) {
        *dst++ = mac[i + 2];
    }
    return v;
}

WhMacHi ov11_02126FAC(const u8 *mac)
{
    WhMacHi v;
    v.v = 0;
    u8 *dst = (u8 *)&v;
    for (u32 i = 0; i < 2; i++) {
        *dst++ = mac[i];
    }
    return v;
}

void ov11_02126FE4(u32 value, u32 *lo, u32 *hi)
{
    *lo = value % 10000;
    *hi = value / 10000 % 10000;
}

u32 ov11_0212702C()
{
    return sizeof(WhPacket);
}

u32 ov11_02127034()
{
    return ((u32)(OS_GetTick() + GX_GetVCount()) & ~1) + 1;
}

u32 ov11_02127058(u32 seed, u32 size, u32 *data)
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

void ov11_021270B8(void *buf, const void *src, int size, int type, int id)
{
    WhPacket *pkt = (WhPacket *)buf;
    WhUserInfo *info = ov11_02126F50();
    pkt->info.unk_00.unk_00 = info->info.unk_00.unk_00;
    pkt->info.unk_00.unk_08 = info->info.unk_00.unk_08;
    pkt->info.unk_00.unk_0C = info->info.unk_00.unk_0C;
    pkt->info.unk_00.unk_10 = (u16)ov11_02127034();
    pkt->info.unk_04.unk_00 = info->info.unk_04.unk_00;
    pkt->info.unk_04.unk_08 = info->info.unk_04.unk_08;
    pkt->info.unk_04.unk_0C = info->info.unk_04.unk_0C;
    pkt->info.unk_04.unk_10 = 0;
    pkt->unk_08 = (u8)id;
    pkt->unk_08_8 = type;
    pkt->unk_08_16 = sub_0200071A(0, src, size);
    pkt->unk_0C = ov11_0212702C();
    pkt->unk_0C_8 = size;
    if (size != 0) {
        MI_CpuCopy8(src, (u8 *)pkt + pkt->unk_0C, size);
    }
    ov11_02126984(pkt);
    if (info->info.unk_00.unk_0C == 1) {
        ov11_02127058(pkt->info.unk_00.unk_10, size + pkt->unk_0C - 4, (u32 *)&pkt->info.unk_04);
    }
}

void ov11_02127274(void *buf)
{
    WhPacket *pkt = (WhPacket *)buf;
    ov11_02126F50();
    if (pkt->info.unk_00.unk_0C != 1) {
        return;
    }
    u32 seed = ov11_02127058(pkt->info.unk_00.unk_10, 0xC, (u32 *)&pkt->info.unk_04);
    ov11_02127058(seed, pkt->unk_0C + pkt->unk_0C_8 - 0x10, (u32 *)((u8 *)pkt + 0x10));
}

BOOL ov11_021272C4(void *buf)
{
    WhPacket *pkt = (WhPacket *)buf;
    if (sub_0200071A(0, (u8 *)pkt + pkt->unk_0C, pkt->unk_0C_8) == pkt->unk_08_16) {
        return TRUE;
    }
    return FALSE;
}
