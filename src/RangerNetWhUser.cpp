#include <nitro/wm.h>
#include <nitro/wvr.h>

#include "common.hpp"
#include "heap.hpp"

// D5: WH user layer: WVR start-up, beacon info, parent tick (02128F18..021298C4)

// defined in RangerNetPlayerInfo.cpp
struct RangerNetSessionParam {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u8 unk_14[0xC];
};

// beacon userGameInfo (0x5C bytes)
struct D5Beacon {
    u32 unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    union {
        u8 raw[0x54];
        struct {
            u8 unk_08[0x8];
            RangerNetSessionParam param;
            u8 unk_30[0x24];
            u8 unk_54;
            u8 unk_55[0x7];
        } info;
    } unk_08;
};

struct D5Work {
    D5Beacon beacon;
    u8 unk_05C[0x84];
    u8 unk_0E0[0x54];
    u8 unk_134[0xC00];
    u8 unk_D34[8][6];
    u8 unk_D64[0x20];
    void *unk_D84;
    int unk_D88;
    u8 unk_D8C;
    u8 unk_D8D[0x3];
    RangerNetSessionParam *unk_D90;
    u32 unk_D94;
    u16 unk_D98;
    u16 unk_D9A;
    u8 unk_D9C;
    u8 unk_D9D;
    u8 unk_D9E;
    u8 unk_D9F;
    u8 unk_DA0;
    u8 unk_DA1_0 : 1;
    u8 unk_DA1_1 : 1;
    u8 unk_DA1_2 : 1;
    u8 unk_DA1_3 : 1;
    u8 unk_DA1_4 : 1;
    u8 unk_DA1_5 : 1;
};

static u16 sTgid;
static int sWvrState;
static D5Work *sWork;

// RangerNetWh.cpp
u32 ov11_02127FA4();
BOOL ov11_02127ED0();
void ov11_02127A70(u32 ggid);
void ov11_02127A84(void *info, u16 length);
u16 ov11_02127AA4();
int ov11_02127B08();
int ov11_02127B20();
BOOL ov11_02127B38();
u16 ov11_02127D9C();
BOOL ov11_0212806C(int mode, u16 tgid, u16 channel, u16 maxEntry, u16 beaconPeriod, int entryFlag);
void ov11_021281CC(void (*proc)(u16 aid, u16 *data, u16 size), int port);
void ov11_0212825C();
BOOL ov11_021282FC();
u16 ov11_02128330();
BOOL ov11_02128348();
BOOL ov11_0212836C();
BOOL ov11_02128390();
BOOL ov11_021283B4();
BOOL ov11_021277AC();
void ov11_021283E8(void *info, int length, u32 ggid, int tgid);
void ov11_02128444();
u8 ov11_02128460();
// RangerNetPlayerInfo.cpp, RangerNetSession.cpp
void ov11_021289AC();
int ov11_02128EE0();
u8 ov11_02128EFC();

void ov11_0212B0C0(u16 aid, u16 *data, u16 size); // D7
u32 ov11_0212C2FC();
u16 ov11_0212CE10(u16 mode);

void ov11_02128FB4(void *arg, WVRResult result);
void ov11_02128FD8(void *arg, WVRResult result);
void ov11_02129058(void *arg);
void ov11_02129080();
void ov11_021292F8();
void ov11_0212934C();
void ov11_02129400();
u16 ov11_02129730();
int ov11_0212978C();
u16 ov11_021297BC(u16 mode);
RangerNetSessionParam *ov11_021297EC();
void ov11_02129878();

void ov11_02128F18(int code)
{
    while (TRUE) {
    }
}

void ov11_02128F1C(RangerNetSessionParam *param)
{
    if (sWork != NULL) {
        return;
    }
    sWork = (D5Work *)Heap_AllocWithAlignment(sizeof(D5Work), 32);
    MI_CpuFill8(sWork, 0, sizeof(D5Work));
    sWork->unk_D84 = Heap_AllocWithAlignment(ov11_02127FA4(), 32);
    MI_CpuFill8(sWork->unk_D84, 0, ov11_02127FA4());
    sWork->unk_D94 = 0x333;
    sWork->unk_D90 = param;
    ov11_02129080();
}

void ov11_02128FB4(void *arg, WVRResult result)
{
    if (result != WVR_RESULT_SUCCESS) {
        OS_Terminate();
    }
    sWvrState = 2;
}

void ov11_02128FD8(void *arg, WVRResult result)
{
    sWvrState = 0;
}

void ov11_02128FEC()
{
    sWvrState = 1;
    if (WVR_StartUpAsync(GX_VRAM_ARM7_128_C, ov11_02128FB4, NULL) != WVR_RESULT_OPERATING) {
        OS_Terminate();
    }
}

BOOL ov11_02129024()
{
    return sWvrState == 2;
}

WVRResult ov11_02129040()
{
    return WVR_TerminateAsync(ov11_02128FD8, NULL);
}

void ov11_02129058(void *arg)
{
    WMIndCallback *cb = (WMIndCallback *)arg;
    if (cb->state != 16) {
        return;
    }
    if (sWork != NULL) {
        sWork->unk_D88 = 2;
    }
}

void ov11_02129080()
{
    sWork->unk_D88 = 0;
    ov11_02127ED0();
    WM_SetIndCallback(ov11_02129058);
    ov11_02127A70(sWork->unk_D94);
}

void ov11_021290BC(int flag)
{
    sWork->unk_DA1_3 = flag;
}

void ov11_021290E4()
{
    sWork->unk_D8C = 0;
    sWork->unk_DA1_0 = 0;
    sWork->unk_DA1_2 = 0;
    sWork->unk_D9E = 0;
    sWork->unk_DA1_4 = 0;
    sWork->unk_DA0 = 0;
    sWork->unk_D9F = 0;
}

BOOL ov11_02129144(int arg, int flag3, int flag5)
{
    ov11_021290E4();
    ov11_021290BC(flag3);
    ov11_02128444();
    if (sWork->unk_D9F == 0) {
        ov11_021281CC(ov11_0212B0C0, 14);
        sWork->unk_D9F = 1;
    }
    sWork->unk_DA1_5 = flag5;
    if (ov11_02127B08() == 1 && ov11_02127B38()) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov11_021291DC()
{
    if (sWork == NULL) {
        return TRUE;
    }
    switch (sWork->unk_DA0) {
    case 0:
        if (ov11_021283B4()) {
            ov11_021277AC();
            sWork->unk_DA0 = 1;
        } else if (!ov11_0212836C()) {
            ov11_0212825C();
            sWork->unk_DA0 = 2;
        }
        break;
    case 1:
        if (!ov11_0212836C()) {
            ov11_0212825C();
            sWork->unk_DA0 = 2;
        }
        break;
    case 2:
        if (ov11_02128348()) {
            return TRUE;
        }
        if (ov11_02128390()) {
            sWork->unk_DA0 = 1;
        }
        break;
    }
    return FALSE;
}

BOOL ov11_021292B8()
{
    if (sWork != NULL && sWork->unk_D9E == 0) {
        sWork->unk_D9E = 1;
        ov11_0212825C();
        return TRUE;
    }
    return FALSE;
}

void ov11_021292F8()
{
    if (sWork->unk_D84 != NULL) {
        Heap_Free(sWork->unk_D84);
        sWork->unk_D84 = NULL;
    }
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void ov11_0212934C()
{
    int mode = ov11_02128EE0();
    RangerNetSessionParam *param = ov11_021297EC();
    if (mode != 0xF) {
        D5Beacon *beacon = &sWork->beacon;
        MI_CpuCopy8(param, &beacon->unk_08.info.param, ov11_0212C2FC());
        beacon->unk_00 = param->unk_10;
        beacon->unk_04 = ov11_02128EE0();
        beacon->unk_08.info.unk_54 = ov11_02128460();
    } else {
        D5Beacon *beacon = &sWork->beacon;
        beacon->unk_00 = param->unk_10;
        beacon->unk_04 = ov11_02128EE0();
        beacon->unk_05 = ov11_02128EFC();
        MI_CpuCopy8(sWork->unk_0E0, beacon->unk_08.raw, sizeof(beacon->unk_08.raw));
    }
    DC_FlushRange(sWork, sizeof(D5Beacon));
    ov11_02127A84(sWork, sizeof(D5Beacon));
}

void ov11_02129400()
{
    D5Beacon *beacon = &sWork->beacon;
    if (beacon->unk_06 == ov11_02129730()) {
        return;
    }
    beacon->unk_06 = ov11_02129730();
    DC_FlushRange(sWork, sizeof(D5Beacon));
    ov11_02127A84(sWork, sizeof(D5Beacon));
    ov11_021283E8(sWork, sizeof(D5Beacon), sWork->unk_D94, sTgid);
}

void ov11_02129464(u16 vcount)
{
    int state = ov11_02127B08();
    ov11_021289AC();
    ov11_02129400();
    if (ov11_02128330() == 0 && ov11_0212978C() == 0) {
        if (sWork->unk_DA1_2) {
            sWork->unk_DA1_0 = 1;
        }
    }
    if (sWork->unk_D9A == 0xFFFF) {
        sWork->unk_D9A = vcount;
    }
    if (sWork->unk_DA1_1 && sWork->unk_D9A > vcount) {
        sWork->unk_DA1_0 = 1;
    }
    if (ov11_02127B20() == 0x19) {
        ov11_02128F18(0);
    }
    switch (state) {
    case 0:
        if (sWork->unk_D9E == 1) {
            ov11_021292F8();
        } else if (sWork->unk_D9E == 2) {
            sWork->unk_D9E = 3;
        }
        break;
    case 1:
        if (sWork->unk_D9E == 1 && ov11_021282FC()) {
            return;
        }
        if (sWork->unk_D9E == 2 && ov11_021282FC()) {
            return;
        }
        break;
    case 8:
    case 9:
        if (sWork != NULL) {
            sWork->unk_DA1_0 = 1;
        }
        break;
    case 7: {
        u16 channel = ov11_02127D9C();
        if (sWork->unk_D9D != 0) {
            sWork->unk_D9D--;
        } else {
            sWork->unk_D98 = channel;
            sWork->unk_D9D = 5;
        }
        channel = sWork->unk_D98;
        if (sWork->unk_DA1_3) {
            sTgid++;
        }
        ov11_0212934C();
        ov11_0212806C(0, sTgid, channel, ov11_0212CE10(ov11_02128EE0()), ov11_021297BC(ov11_02128EE0()), sWork->unk_DA1_5);
        sWork->unk_D9C = channel;
        break;
    }
    }
}

void ov11_021296C8(u16 vcount)
{
    if (sWork == NULL) {
        return;
    }
    ov11_02129464(vcount);
}

BOOL ov11_021296E8(u16 aid)
{
    if (sWork == NULL) {
        return FALSE;
    }
    if (ov11_02127B08() != 4) {
        return FALSE;
    }
    if (ov11_02127AA4() & (1 << aid)) {
        return TRUE;
    }
    return FALSE;
}

u16 ov11_02129730()
{
    u16 count = 0;
    for (u16 i = 0; i < 8; i++) {
        if (ov11_021296E8(i)) {
            count++;
        }
    }
    return count;
}

BOOL ov11_02129770()
{
    return sWork != NULL;
}

int ov11_0212978C()
{
    if (sWork == NULL) {
        return 0;
    }
    return ov11_02127AA4() & 0xFFFE;
}

u16 ov11_021297BC(u16 mode)
{
    u16 period = WM_GetDispersionBeaconPeriod();
    if (mode == 10) {
        return period / 4;
    } else if (mode == 9 || mode == 13) {
        return period / 4;
    }
    return period;
}

RangerNetSessionParam *ov11_021297EC()
{
    return sWork->unk_D90;
}

void ov11_02129800(const u8 *mac, int idx)
{
    if (sWork == NULL) {
        return;
    }
    MI_CpuCopy8(mac, sWork->unk_D34[idx], 6);
}

BOOL ov11_02129830()
{
    return sWork != NULL ? sWork->unk_DA1_4 : FALSE;
}

void ov11_02129858()
{
    if (sWork != NULL) {
        sWork->unk_DA1_4 = 1;
    }
}

void ov11_02129878()
{
    ov11_0212934C();
    ov11_021283E8(sWork, sizeof(D5Beacon), sWork->unk_D94, sTgid);
}

void ov11_021298A0(const void *src)
{
    MI_CpuCopy8(src, sWork->unk_0E0, sizeof(sWork->unk_0E0));
    ov11_02129878();
}
