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

static BOOL Mywh_StateInStartScan();
static void Mywh_StateOutStartScan(void *arg);
static BOOL Mywh_StateInEndScan();
static void Mywh_StateOutEndScan(void *arg);
static void Mywh_StateOutEnd(void *arg);
static void Mywh_IndicateHandler(void *arg);
static BOOL Mywh_StateInInitialize();
static void Mywh_StateOutInitialize(void *arg);
static BOOL Mywh_End();
static BOOL Mywh_StateInReset();
static void Mywh_StateOutReset(void *arg);
static void Mywh_BeginDownload(const MywhBeacon *beacon);
static BOOL Mywh_ReceiveChunk(const MywhBeacon *beacon);

static void Mywh_ChangeSysState(int state)
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

static void Mywh_SetError(int code)
{
    if (sWork->sysState == MYWH_SYSSTATE_ERROR || sWork->sysState == MYWH_SYSSTATE_FATAL) {
        return;
    }
    sWork->errCode = code;
}

static BOOL Mywh_StartScan()
{
    if (sWork->sysState == MYWH_SYSSTATE_CONNECTED) {
        OS_Terminate();
    }
    Mywh_ChangeSysState(MYWH_SYSSTATE_SCANNING);
    *(u16 *)&sWork->scanParam.bssid[4] = 0xFFFF;
    *(u16 *)&sWork->scanParam.bssid[2] = 0xFFFF;
    *(u16 *)&sWork->scanParam.bssid[0] = 0xFFFF;
    if (!Mywh_StateInStartScan()) {
        Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
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

static BOOL Mywh_StateInStartScan()
{
    MYWH_ASSERT(sWork->sysState == MYWH_SYSSTATE_SCANNING);
    u16 chanpat = WM_GetAllowedChannel();
    if (chanpat == 0x8000) {
        Mywh_SetError(WM_ERRCODE_ILLEGAL_STATE);
        return FALSE;
    }
    if (chanpat == 0) {
        Mywh_SetError(0x16);
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
    WMErrCode result = WM_StartScan(Mywh_StateOutStartScan, &sWork->scanParam);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Mywh_SetError(result);
    return FALSE;
}

static void Mywh_StateOutStartScan(void *arg)
{
    WMStartScanCallback *cb = (WMStartScanCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        Mywh_SetError(cb->errcode);
        Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        return;
    }
    if (sWork->sysState != MYWH_SYSSTATE_SCANNING) {
        if (!Mywh_StateInEndScan()) {
            Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
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
            Mywh_BeginDownload((const MywhBeacon *)cb->gameInfo.userGameInfo);
            for (int i = 0; i < WM_SIZE_MACADDR; i++) {
                sWork->parentMac[i] = cb->macAddress[i];
            }
            sWork->channel -= 15;
            if (sWork->callback != NULL) {
                sWork->callback(1);
            }
        }
        if (Mywh_ReceiveChunk((const MywhBeacon *)cb->gameInfo.userGameInfo)) {
            sWork->mode = 4;
            return;
        }
        break;
    }
    if (!Mywh_StateInStartScan()) {
        Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
    }
}

static BOOL Mywh_StateInEndScan()
{
    WMErrCode result = WM_EndScan(Mywh_StateOutEndScan);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Mywh_SetError(result);
    return FALSE;
}

static void Mywh_StateOutEndScan(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        Mywh_SetError(cb->errcode);
        return;
    }
    Mywh_ChangeSysState(MYWH_SYSSTATE_IDLE);
}

static void Mywh_StateOutEnd(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        Mywh_ChangeSysState(MYWH_SYSSTATE_FATAL);
        return;
    }
    Mywh_ChangeSysState(MYWH_SYSSTATE_STOP);
    if (sWork->callback != NULL) {
        sWork->callback(3);
    }
}

static BOOL Mywh_Initialize()
{
    sWork->errCode = 0;
    sInitialized = FALSE;
    if (Mywh_StateInInitialize()) {
        return TRUE;
    }
    return FALSE;
}

static void Mywh_IndicateHandler(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;

    if (cb->errcode == WM_ERRCODE_FIFO_ERROR) {
        Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        OS_Terminate();
    }
}

static BOOL Mywh_StateInInitialize()
{
    Mywh_ChangeSysState(MYWH_SYSSTATE_BUSY);
    WMErrCode result = WM_Initialize(sWork, Mywh_StateOutInitialize, 2);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Mywh_SetError(result);
    Mywh_ChangeSysState(MYWH_SYSSTATE_FATAL);
    return FALSE;
}

static void Mywh_StateOutInitialize(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        Mywh_SetError(cb->errcode);
        Mywh_ChangeSysState(MYWH_SYSSTATE_FATAL);
        return;
    }
    WMErrCode result = WM_SetIndCallback(Mywh_IndicateHandler);
    if (result != WM_ERRCODE_SUCCESS) {
        Mywh_SetError(result);
        Mywh_ChangeSysState(MYWH_SYSSTATE_FATAL);
        return;
    }
    Mywh_ChangeSysState(MYWH_SYSSTATE_IDLE);
    sInitialized = TRUE;
    Mywh_StartScan();
}

static BOOL Mywh_End()
{
    if (sWork->sysState != MYWH_SYSSTATE_IDLE) {
        OS_Terminate();
    }
    Mywh_ChangeSysState(MYWH_SYSSTATE_BUSY);
    if (WM_End(Mywh_StateOutEnd) != WM_ERRCODE_OPERATING) {
        Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        return FALSE;
    }
    return TRUE;
}

void Mywh_Finalize()
{
    if (sWork->sysState == MYWH_SYSSTATE_IDLE) {
        Mywh_End();
    } else {
        Mywh_StateInReset();
    }
}

static BOOL Mywh_StateInReset()
{
    Mywh_ChangeSysState(MYWH_SYSSTATE_BUSY);
    WMErrCode result = WM_Reset(Mywh_StateOutReset);
    if (result == WM_ERRCODE_OPERATING) {
        return TRUE;
    }
    Mywh_SetError(result);
    return FALSE;
}

static void Mywh_StateOutReset(void *arg)
{
    WMCallback *cb = (WMCallback *)arg;

    if (cb->errcode != WM_ERRCODE_SUCCESS) {
        Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
        Mywh_SetError(cb->errcode);
        if (sWork->callback != NULL) {
            sWork->callback(4);
        }
        return;
    }
    Mywh_ChangeSysState(MYWH_SYSSTATE_IDLE);
    Mywh_End();
}

BOOL Mywh_StartDownload(u8 *dest, void (*callback)(int state), u8 *buf)
{
    sWork = (MywhWork *)((PTR_CAST(u32, buf) + 31) & ~31);
    sWork->sysState = MYWH_SYSSTATE_STOP;
    sWork->mode = 1;
    sWork->dest = dest;
    sWork->chunkCount = 0;
    sWork->chunksReceived = 0;
    sWork->callback = callback;
    sWork->channel = 16;
    sWork->hasHeader = 0;
    sWork->linkLevel = -1;
    return Mywh_Initialize();
}

static void Mywh_BeginDownload(const MywhBeacon *beacon)
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

static BOOL Mywh_ReceiveChunk(const MywhBeacon *beacon)
{
    if (sWork->id != beacon->id || sWork->size != beacon->size) {
        if (sWork->retry++ >= 16) {
            Mywh_BeginDownload(beacon);
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
            Mywh_ChangeSysState(MYWH_SYSSTATE_ERROR);
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

u16 Mywh_GetChunksReceived()
{
    return sWork->chunksReceived;
}

u16 Mywh_GetChunkCount()
{
    return sWork->chunkCount;
}

int Mywh_GetLinkLevel()
{
    return sWork->linkLevel;
}

u32 Mywh_GetWorkSize()
{
    return 0x1400;
}

void *Mywh_GetHeader()
{
    if (sWork->hasHeader != 0) {
        return sWork->header;
    }
    return NULL;
}

BOOL Mywh_IsInitialized()
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

void Mywh_Decrypt(const u8 *in, u8 *out)
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
