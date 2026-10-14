#include "RangerNetMywh.hpp"

#include "CryptoRC4.hpp"
#include "common.hpp"

// mywh (0212F64C..021302D8): the child side of a beacon download, cut down from the NitroSDK wireless demo
// library wh.c. Scans for the parent with GGID 0x400643 and collects the data it sends in 0x68-byte beacon chunks.

// SDK_ASSERT's debug form, kept in the final build
#define MYWH_ASSERT(exp) ((void)((exp) || (OS_Terminate(), 0)))

#define MYWH_GGID       0x400643
#define MYWH_CHUNK_SIZE 0x68

enum {
    MYWH_SYSSTATE_STOP,
    MYWH_SYSSTATE_IDLE,
    MYWH_SYSSTATE_SCANNING,
    MYWH_SYSSTATE_BUSY,
    MYWH_SYSSTATE_CONNECTED,
    MYWH_SYSSTATE_DATASHARING,
    MYWH_SYSSTATE_KEYSHARING,
    MYWH_SYSSTATE_MEASURECHANNEL,
    MYWH_SYSSTATE_CONNECT_FAIL,
    MYWH_SYSSTATE_ERROR,
    MYWH_SYSSTATE_FATAL,
};

// Beacon user game info
struct MywhBeacon {
    u16 id;
    u16 chunk;
    u32 size;
    u8 data[MYWH_CHUNK_SIZE];
};

struct MywhWork {
    u8 wmBuf[WM_SYSTEM_BUF_SIZE];
    WMBssDesc bssDesc;
    WMScanParam scanParam ATTRIBUTE_ALIGN(32); // makes mwcc skip IRO in the functions using it
    u8 header[MYWH_CHUNK_SIZE];
    int hasHeader;
    CRYPTORC4Context rc4;
    int sysState;
    int errCode;
    u16 mode;
    u16 id;
    u16 chunkCount;
    u16 chunksReceived;
    u32 size;
    u32 retry;
    int lastChunk;
    int linkLevel;
    u8 parentMac[WM_SIZE_MACADDR];
    u16 channel;
    u8 *dest;
    void (*callback)(int state);
    u8 received[1];
};

static MywhWork *sWork;
static void (*sPrintf)(const char *fmt, ...);
static int sInitialized;

static BOOL ov11_0212F7C0();
static void ov11_0212F938(void *arg);
static BOOL ov11_0212FB40();
static void ov11_0212FB68(void *arg);
static void ov11_0212FB8C(void *arg);
static void ov11_0212FC0C(void *arg);
static BOOL ov11_0212FC50();
static void ov11_0212FC98(void *arg);
static BOOL ov11_0212FCFC();
static BOOL ov11_0212FDA4();
static void ov11_0212FDD4(void *arg);
static void ov11_0212FEC8(const MywhBeacon *beacon);
static BOOL ov11_0212FF98(const MywhBeacon *beacon);

static void ov11_0212F64C(int state)
{
    static const char *sStateNames[] = {
        "mywh_SYSSTATE_STOP",
        "mywh_SYSSTATE_IDLE",
        "mywh_SYSSTATE_SCANNING",
        "mywh_SYSSTATE_BUSY",
        "mywh_SYSSTATE_CONNECTED",
        "mywh_SYSSTATE_DATASHARING",
        "mywh_SYSSTATE_KEYSHARING",
        "mywh_SYSSTATE_MEASURECHANNEL",
        "mywh_SYSSTATE_CONNECT_FAIL",
        "mywh_SYSSTATE_ERROR",
    };

    if (sPrintf != NULL) {
        sPrintf("%s -> ", sStateNames[sWork->sysState]);
    }
    sWork->sysState = state;
    if (sPrintf != NULL) {
        sPrintf("%s\n", sStateNames[sWork->sysState]);
    }
}

static void ov11_0212F6CC(int code)
{
    if (sWork->sysState == MYWH_SYSSTATE_ERROR || sWork->sysState == MYWH_SYSSTATE_FATAL) {
        return;
    }
    sWork->errCode = code;
}

static BOOL ov11_0212F6F0()
{
    if (sWork->sysState == MYWH_SYSSTATE_CONNECTED) {
        OS_Terminate();
    }
    ov11_0212F64C(MYWH_SYSSTATE_SCANNING);
    *(u16 *)&sWork->scanParam.bssid[4] = 0xFFFF;
    *(u16 *)&sWork->scanParam.bssid[2] = 0xFFFF;
    *(u16 *)&sWork->scanParam.bssid[0] = 0xFFFF;
    if (!ov11_0212F7C0()) {
        ov11_0212F64C(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        return FALSE;
    }
    sWork->mode = 2;
    if (sWork->callback != NULL) {
        sWork->callback(0);
    }
    return TRUE;
}

static BOOL ov11_0212F7C0()
{
    MYWH_ASSERT(sWork->sysState == MYWH_SYSSTATE_SCANNING);
    u16 chanpat = WM_GetAllowedChannel();
    if (chanpat == 0x8000) {
        ov11_0212F6CC(WM_ERRCODE_ILLEGAL_STATE);
        return FALSE;
    }
    if (chanpat == 0) {
        ov11_0212F6CC(0x16);
        return FALSE;
    }
    if (sWork->channel >= 16) {
        int ch = sWork->channel - 16;
        for (int i = 0; i < 13; i++) {
            ch = (ch + 1) % 13;
            if (chanpat & (1 << ch)) {
                break;
            }
        }
        sWork->channel = ch + 16;
        sWork->scanParam.channel = ch + 1;
    } else {
        sWork->scanParam.channel = sWork->channel;
    }
    sWork->scanParam.maxChannelTime = 220;
    sWork->scanParam.scanBuf = &sWork->bssDesc;
    if (sWork->mode == 3) {
        for (int i = 0; i < WM_SIZE_MACADDR; i++) {
            sWork->scanParam.bssid[i] = sWork->parentMac[i];
        }
    }
    WMErrCode result = WM_StartScan(ov11_0212F938, &sWork->scanParam);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_0212F6CC(result);
    return FALSE;
}

static void ov11_0212F938(void *arg)
{
    WMStartScanCallback *cb = (WMStartScanCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        ov11_0212F6CC(cb->errcode);
        ov11_0212F64C(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        return;
    }
    if (sWork->sysState != MYWH_SYSSTATE_SCANNING) {
        if (!ov11_0212FB40()) {
            ov11_0212F64C(MYWH_SYSSTATE_ERROR);
            if (sWork->callback != NULL) {
                sWork->callback(4);
            }
        }
        return;
    }
    switch (cb->state) {
    case WM_STATECODE_SCAN_START:
        return;
    case WM_STATECODE_PARENT_NOT_FOUND:
        sWork->linkLevel = 0;
        break;
    case WM_STATECODE_PARENT_FOUND:
        DC_InvalidateRange(&sWork->bssDesc, sizeof(WMBssDesc));
        if (cb->gameInfoLength < 8 || cb->gameInfo.ggid != MYWH_GGID) {
            if (sPrintf != NULL) {
                sPrintf("not my parent ggid (%d != %d)\n", cb->gameInfo.ggid, MYWH_GGID);
            }
            break;
        }
        sWork->linkLevel = cb->linkLevel;
        if (sWork->mode == 2) {
            ov11_0212FEC8((const MywhBeacon *)cb->gameInfo.userGameInfo);
            for (int i = 0; i < WM_SIZE_MACADDR; i++) {
                sWork->parentMac[i] = cb->macAddress[i];
            }
            sWork->channel -= 15;
            if (sWork->callback != NULL) {
                sWork->callback(1);
            }
        }
        if (ov11_0212FF98((const MywhBeacon *)cb->gameInfo.userGameInfo)) {
            sWork->mode = 4;
            return;
        }
        break;
    }
    if (!ov11_0212F7C0()) {
        ov11_0212F64C(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
    }
}

static BOOL ov11_0212FB40()
{
    WMErrCode result = WM_EndScan(ov11_0212FB68);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_0212F6CC(result);
    return FALSE;
}

static void ov11_0212FB68(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        ov11_0212F6CC(cb->errcode);
        return;
    }
    ov11_0212F64C(MYWH_SYSSTATE_IDLE);
}

static void ov11_0212FB8C(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        ov11_0212F64C(MYWH_SYSSTATE_FATAL);
        return;
    }
    ov11_0212F64C(MYWH_SYSSTATE_STOP);
    if (sWork->callback != NULL) {
        sWork->callback(3);
    }
}

static BOOL ov11_0212FBD8()
{
    sWork->errCode = 0;
    sInitialized = FALSE;
    if (ov11_0212FC50()) {
        return TRUE;
    }
    return FALSE;
}

static void ov11_0212FC0C(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;

    if (cb->errcode == WM_ERRCODE_FIFO_ERROR) {
        ov11_0212F64C(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        OS_Terminate();
    }
}

static BOOL ov11_0212FC50()
{
    ov11_0212F64C(MYWH_SYSSTATE_BUSY);
    WMErrCode result = WM_Initialize(sWork, ov11_0212FC98, 2);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_0212F6CC(result);
    ov11_0212F64C(MYWH_SYSSTATE_FATAL);
    return FALSE;
}

static void ov11_0212FC98(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        ov11_0212F6CC(cb->errcode);
        ov11_0212F64C(MYWH_SYSSTATE_FATAL);
        return;
    }
    WMErrCode result = WM_SetIndCallback(ov11_0212FC0C);
    if (result != WM_ERRCODE_SUCCESS) {
        ov11_0212F6CC(result);
        ov11_0212F64C(MYWH_SYSSTATE_FATAL);
        return;
    }
    ov11_0212F64C(MYWH_SYSSTATE_IDLE);
    sInitialized = TRUE;
    ov11_0212F6F0();
}

static BOOL ov11_0212FCFC()
{
    if (sWork->sysState != MYWH_SYSSTATE_IDLE) {
        OS_Terminate();
    }
    ov11_0212F64C(MYWH_SYSSTATE_BUSY);
    if (WM_End(ov11_0212FB8C) != WM_ERRCODE_OPERATING) {
        ov11_0212F64C(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        return FALSE;
    }
    return TRUE;
}

void ov11_0212FD74()
{
    if (sWork->sysState == MYWH_SYSSTATE_IDLE) {
        ov11_0212FCFC();
    } else {
        ov11_0212FDA4();
    }
}

static BOOL ov11_0212FDA4()
{
    ov11_0212F64C(MYWH_SYSSTATE_BUSY);
    WMErrCode result = WM_Reset(ov11_0212FDD4);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    ov11_0212F6CC(result);
    return FALSE;
}

static void ov11_0212FDD4(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        ov11_0212F64C(MYWH_SYSSTATE_ERROR);
        ov11_0212F6CC(cb->errcode);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        return;
    }
    ov11_0212F64C(MYWH_SYSSTATE_IDLE);
    ov11_0212FCFC();
}

BOOL ov11_0212FE30(u8 *dest, void (*callback)(int state), u8 *buf)
{
    sWork = (MywhWork *)(((u32)buf + 31) & ~31);
    sWork->sysState = MYWH_SYSSTATE_STOP;
    sWork->mode = 1;
    sWork->dest = dest;
    sWork->chunkCount = 0;
    sWork->chunksReceived = 0;
    sWork->callback = callback;
    sWork->channel = 16;
    sWork->hasHeader = 0;
    sWork->linkLevel = -1;
    return ov11_0212FBD8();
}

static void ov11_0212FEC8(const MywhBeacon *beacon)
{
    sWork->hasHeader = 0;
    sWork->mode = 3;
    sWork->id = beacon->id;
    sWork->size = beacon->size;
    sWork->chunkCount = (sWork->size - 1) / MYWH_CHUNK_SIZE + 1;
    sWork->chunksReceived = 0;
    sWork->retry = 0;
    for (int i = 0; i < sWork->chunkCount; i++) {
        sWork->received[i] = 0;
    }
}

static BOOL ov11_0212FF98(const MywhBeacon *beacon)
{
    if (sWork->id != beacon->id || sWork->size != beacon->size) {
        if (sWork->retry++ >= 16) {
            ov11_0212FEC8(beacon);
            if (sWork->callback != NULL) {
                sWork->callback(5);
            }
        } else {
            return FALSE;
        }
    }
    if (beacon->chunk == 0xFFFF) {
        MI_CpuCopy32(beacon->data, sWork->header, MYWH_CHUNK_SIZE);
        sWork->hasHeader = 1;
    } else {
        sWork->lastChunk = beacon->chunk;
        if (beacon->chunk >= sWork->chunkCount) {
            if (sWork->callback != NULL) {
                sWork->callback(4);
            }
            ov11_0212F64C(MYWH_SYSSTATE_ERROR);
        }
        if (sWork->received[beacon->chunk] == 0) {
            sWork->received[beacon->chunk] = 1;
            if (beacon->chunk == sWork->chunkCount - 1) {
                MI_CpuCopy32(beacon->data, sWork->dest + beacon->chunk * MYWH_CHUNK_SIZE, sWork->size - beacon->chunk * MYWH_CHUNK_SIZE);
            } else {
                MI_CpuCopy32(beacon->data, sWork->dest + beacon->chunk * MYWH_CHUNK_SIZE, MYWH_CHUNK_SIZE);
            }
            sWork->chunksReceived++;
            if (sWork->chunksReceived == sWork->chunkCount && sWork->hasHeader == 1) {
                if (sWork->callback != NULL) {
                    sWork->callback(2);
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

u16 ov11_0213018C()
{
    return sWork->chunksReceived;
}

u16 ov11_021301A4()
{
    return sWork->chunkCount;
}

int ov11_021301BC()
{
    return sWork->linkLevel;
}

u32 ov11_021301D4()
{
    return 0x1400;
}

void *ov11_021301DC()
{
    if (sWork->hasHeader != 0) {
        return sWork->header;
    }
    return NULL;
}

BOOL ov11_02130200()
{
    return sInitialized;
}

static inline void MixKey(u16 *key)
{
    u16 x = 0x5FA2;
    for (int i = 0; i < 4; i++) {
        key[i] = x ^ key[i];
        x = key[i];
    }
}

void ov11_02130210(const u8 *in, u8 *out)
{
    u16 key[4];
    u8 *p = (u8 *)key;
    int i;

    for (i = 0; i < WM_SIZE_MACADDR; i++) {
        *p++ = sWork->parentMac[i];
    }
    key[3] = key[1];
    key[1] = sWork->id;
    MixKey(key);
    CRYPTO_RC4Init(&sWork->rc4, key, sizeof(key));
    CRYPTO_RC4Encrypt(&sWork->rc4, in, sWork->size, out);
}
