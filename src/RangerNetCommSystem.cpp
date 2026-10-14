#include <nitro/math.h>
#include <nitro/rtc.h>

#include "RangerNetComm.hpp"
#include "common.hpp"
#include "heap.hpp"

// Ranger Net packet layer over WH (02129B60..0212C304): double-buffered send/receive frames, command parsing.
// The same library as pokeplatinum's communication_system.c (the DP-era comm code).

struct CommRecvState {
    int unk_0;
    u8 *unk_4;
    u16 unk_8;
    u8 unk_A;
};

struct CommSystem {
    u8 unk_000[2][0x26];
    u8 unk_04C[0x108];
    u8 unk_154[2][0xC0];
    u8 unk_2D4[0x180];
    u8 *unk_454;
    u8 *unk_458;
    u8 *unk_45C;
    u8 *unk_460;
    CommRing unk_464;
    CommRing unk_470;
    CommRing unk_47C[8];
    CommRing unk_4DC;
    CommRing unk_4E8[8];
    CommQueueMan unk_548;
    CommQueueMan unk_568;
    CommRecvState unk_588[8];
    CommRecvState unk_5E8;
    MATHRandContext32 unk_5F4;
    u16 unk_60C[8];
    u8 unk_61C[0x8];
    u16 unk_624;
    u8 unk_626;
    u8 unk_627;
    u8 unk_628;
    u8 unk_629;
    u8 unk_62A[0x2];
    int unk_62C;
    int unk_630;
    int unk_634[8];
    int unk_654;
    u16 unk_658;
    u8 unk_65A;
    u8 unk_65B[8];
    u8 unk_663[8];
    u8 unk_66B[8];
    u8 unk_673[4];
    u8 unk_677;
    u8 unk_678;
    u8 unk_679;
    u8 unk_67A;
    u8 unk_67B;
    u8 unk_67C;
    u8 unk_67D;
    u8 unk_67E;
    u8 unk_67F;
    u8 unk_680;
    u8 unk_681;
    u8 unk_682;
    u8 unk_683;
    u8 unk_684;
    u8 unk_685;
    u8 unk_686;
    u8 unk_687;
};

static u8 sActive;
static CommSystem *sWork;
// send states of the client (0x26-byte frames) and server (0xC0-byte frames) side; two objects, not an array:
// 02129D64's reload of sWork after the second store only schedules like the original that way
static volatile u8 sClientSendState = 4;
static volatile u8 sServerSendState = 4;

// RangerNetWh.cpp ... RangerNetShared.cpp
int ov11_02127B08();
void ov11_021285AC();
void ov11_0212874C();
int ov11_02128EE0();
void ov11_02128C14();
BOOL ov11_02129144(int arg, int flag3, int flag5);
BOOL ov11_021292B8();
void ov11_021296C8(u16 vcount);
BOOL ov11_02129770();
void ov11_02129858();
u16 ov11_02128330();
u16 ov11_02127AA4();
int ov11_0212978C();
BOOL ov11_02129830();
void ov11_021298C4(int arg);
void ov11_02129944();
void ov11_02129A74();
extern "C" BOOL thunk_FUN_overlay_11__02127904(const void *data, u16 size, int port, void (*callback)(BOOL result));

u16 ov11_0212CE10(u16 mode); // D8
void ov11_0212CB10(int netId, int cmd, int size, void *data); // RangerNetCommCmd.cpp
u16 ov11_0212CBA4(int cmd);
BOOL ov11_0212CC34(int cmd);
u8 *ov11_0212CC90(int cmd, int netId, int size);

void ov11_02129D64();
void ov11_0212A0C0();
void ov11_0212A3E4(u16 aid);
void ov11_0212A4C4();
void ov11_0212A570();
u8 ov11_0212A640();
void ov11_0212A668();
void ov11_0212A7A4();
void ov11_0212A804();
void ov11_0212A944();
BOOL ov11_0212AA64(u8 frame);
void ov11_0212AB58();
void ov11_0212AED4(u16 aid, u8 *data, u16 size);
void ov11_0212B110(u16 aid, u8 *data, u16 size);
void ov11_0212B260(BOOL result);
void ov11_0212B280(BOOL result);
BOOL ov11_0212B4B4(u8 *data, int aid);
BOOL ov11_0212B59C(u8 *hdr);
BOOL ov11_0212B8A0(u8 cmd, u8 *data, u16 size);
BOOL ov11_0212B938(u8 cmd, u8 *data, u16 size);
BOOL ov11_0212BA98(u8 cmd, u8 *data, u16 size);
BOOL ov11_0212BFAC();
void ov11_0212C2E4();
void ov11_0212BB7C(int aid, int cmd, int size, u8 *data, CommRecvState *pending);
BOOL ov11_0212BF7C();
BOOL ov11_0212C198(u8 cmd, u8 *data);
void ov11_0212A5F8(u8 mode);
void ov11_0212B7E4(u8 *frame);
int ov11_0212C1A8(u16 mode);
void ov11_0212AD8C();
void ov11_0212B2A0();
BOOL ov11_0212B6AC(u8 *frame);
void ov11_0212BD58();
void ov11_0212BDC8();
BOOL ov11_0212BEA0(u16 aid);
void ov11_0212BFD4();
u16 ov11_0212C154();
BOOL ov11_0212C1D0();
void ov11_0212C21C(MATHRandContext32 *ctx);

BOOL ov11_02129B60(BOOL keep, int size)
{
    BOOL reset = FALSE;
    sActive = 0;
    if (keep) {
        int n = ov11_0212CE10(ov11_02128EE0()) + 1;
        if (sWork != NULL) {
            return TRUE;
        }
        ov11_021298C4(0);
        sWork = (CommSystem *)Heap_Alloc(sizeof(CommSystem));
        MI_CpuFill8(sWork, 0, sizeof(CommSystem));
        sWork->unk_654 = size + 0x40;
        sWork->unk_679 = 0;
        sWork->unk_67A = 0x1B;
        sWork->unk_45C = (u8 *)Heap_Alloc(sWork->unk_654 * 2);
        sWork->unk_460 = (u8 *)Heap_Alloc(sWork->unk_654);
        sWork->unk_458 = (u8 *)Heap_Alloc(n * sWork->unk_654);
        sWork->unk_454 = (u8 *)Heap_Alloc(n * sWork->unk_654);
        if (ov11_02128EE0() == 10) {
            ov11_0212C7FC(&sWork->unk_548, 100, &sWork->unk_464);
            ov11_0212C7FC(&sWork->unk_568, 800, &sWork->unk_4DC);
        } else {
            ov11_0212C7FC(&sWork->unk_548, 20, &sWork->unk_464);
            ov11_0212C7FC(&sWork->unk_568, 280, &sWork->unk_4DC);
        }
    } else {
        reset = TRUE;
    }
    sWork->unk_658 = 0;
    for (int i = 0; i < 4; i++) {
        sWork->unk_673[i] = 0xFF;
    }
    if (!reset) {
        ov11_02129D64();
    }
    ov11_0212C21C(&sWork->unk_5F4);
    sWork->unk_683 = 0;
    return TRUE;
}

void ov11_02129D64()
{
    int i;

    sWork->unk_628 = 0;
    sWork->unk_629 = 0;
    sWork->unk_67B = 0;
    sWork->unk_67C = 0;
    int n = ov11_0212CE10(ov11_02128EE0()) + 1;
    MI_CpuFill8(sWork->unk_458, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        ov11_0212C89C(&sWork->unk_4E8[i], sWork->unk_458 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_454, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        ov11_0212C89C(&sWork->unk_47C[i], sWork->unk_454 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_2D4, 0, sizeof(sWork->unk_2D4));
    ov11_0212C89C(&sWork->unk_4DC, sWork->unk_2D4, sizeof(sWork->unk_2D4));
    for (i = 0; i < 0xC0; i++) {
        sWork->unk_154[0][i] = 0xEE;
        sWork->unk_154[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_04C, 0, sizeof(sWork->unk_04C));
    ov11_0212C89C(&sWork->unk_464, sWork->unk_04C, sizeof(sWork->unk_04C));
    sWork->unk_000[0][0] = 0xFF;
    sWork->unk_000[1][0] = 0xFF;
    for (i = 1; i < 0x26; i++) {
        sWork->unk_000[0][i] = 0xEE;
        sWork->unk_000[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_45C, 0, sWork->unk_654 * 2);
    ov11_0212C89C(&sWork->unk_470, sWork->unk_45C, sWork->unk_654 * 2);
    sWork->unk_680 = 0;
    sWork->unk_681 = 0;
    for (i = 0; i < 8; i++) {
        sWork->unk_65B[i] = 0;
        sWork->unk_663[i] = 1;
        sWork->unk_66B[i] = 1;
        sWork->unk_60C[i] = 0;
        sWork->unk_588[i].unk_A = 0xEE;
        sWork->unk_588[i].unk_8 = 0xFFFF;
        sWork->unk_588[i].unk_4 = NULL;
        sWork->unk_588[i].unk_0 = 0;
        sWork->unk_634[i] = 0;
    }
    sWork->unk_630 = 0;
    sWork->unk_62C = 1;
    sWork->unk_5E8.unk_A = 0xEE;
    sWork->unk_5E8.unk_8 = 0xFFFF;
    sWork->unk_5E8.unk_4 = NULL;
    sWork->unk_5E8.unk_0 = 0;
    sWork->unk_67E = 1;
    sWork->unk_67F = 1;
    sServerSendState = 4;
    sClientSendState = 4;
    ov11_0212C840(&sWork->unk_548);
    ov11_0212C840(&sWork->unk_568);
    sWork->unk_684 = 0;
}

void ov11_0212A0C0()
{
    int i;

    sWork->unk_628 = 0;
    sWork->unk_629 = 0;
    int n = ov11_0212CE10(ov11_02128EE0()) + 1;
    MI_CpuFill8(sWork->unk_458, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        ov11_0212C89C(&sWork->unk_4E8[i], sWork->unk_458 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_454, 0, sWork->unk_654 * n);
    for (i = 0; i < n; i++) {
        ov11_0212C89C(&sWork->unk_47C[i], sWork->unk_454 + i * sWork->unk_654, sWork->unk_654);
    }
    MI_CpuFill8(sWork->unk_2D4, 0, sizeof(sWork->unk_2D4));
    ov11_0212C89C(&sWork->unk_4DC, sWork->unk_2D4, sizeof(sWork->unk_2D4));
    for (i = 0; i < 0xC0; i++) {
        sWork->unk_154[0][i] = 0xEE;
        sWork->unk_154[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_04C, 0, sizeof(sWork->unk_04C));
    ov11_0212C89C(&sWork->unk_464, sWork->unk_04C, sizeof(sWork->unk_04C));
    sWork->unk_000[0][0] = 0xFF;
    sWork->unk_000[1][0] = 0xFF;
    for (i = 1; i < 0x26; i++) {
        sWork->unk_000[0][i] = 0xEE;
        sWork->unk_000[1][i] = 0xEE;
    }
    MI_CpuFill8(sWork->unk_45C, 0, sWork->unk_654 * 2);
    ov11_0212C89C(&sWork->unk_470, sWork->unk_45C, sWork->unk_654 * 2);
    sWork->unk_680 = 0;
    sWork->unk_681 = 0;
    for (i = 0; i < 8; i++) {
        sWork->unk_65B[i] = 0;
        sWork->unk_663[i] = 1;
        sWork->unk_66B[i] = 1;
        sWork->unk_60C[i] = 0;
        sWork->unk_588[i].unk_A = 0xEE;
        sWork->unk_588[i].unk_8 = 0xFFFF;
        sWork->unk_588[i].unk_4 = NULL;
        sWork->unk_588[i].unk_0 = 0;
    }
    sWork->unk_62C = 1;
    sWork->unk_5E8.unk_A = 0xEE;
    sWork->unk_5E8.unk_8 = 0xFFFF;
    sWork->unk_5E8.unk_4 = NULL;
    sWork->unk_5E8.unk_0 = 0;
    sWork->unk_67E = 1;
    sWork->unk_67F = 1;
    ov11_0212C840(&sWork->unk_548);
    ov11_0212C840(&sWork->unk_568);
    sWork->unk_684 = 0;
}

void ov11_0212A3E4(u16 aid)
{
    sWork->unk_65B[aid] = 0;
    sWork->unk_663[aid] = 1;
    sWork->unk_634[aid] = 0;
    sWork->unk_66B[aid] = 1;
    ov11_0212C89C(&sWork->unk_47C[aid], sWork->unk_454 + aid * sWork->unk_654, sWork->unk_654);
    ov11_0212C89C(&sWork->unk_4E8[aid], sWork->unk_458 + aid * sWork->unk_654, sWork->unk_654);
    sWork->unk_588[aid].unk_A = 0xEE;
    sWork->unk_588[aid].unk_8 = 0xFFFF;
    sWork->unk_588[aid].unk_4 = NULL;
    sWork->unk_588[aid].unk_0 = 0;
}

void ov11_0212A4C4()
{
    for (u16 aid = 1; aid < 8; aid++) {
        if (!ov11_0212BEA0(aid) && sWork->unk_663[aid] == 0 && !ov11_0212C1D0()) {
            ov11_0212A3E4(aid);
        }
    }
}

BOOL ov11_0212A524(int arg, int flag3, int size, int flag5)
{
    BOOL result = TRUE;
    if (ov11_02128EE0() < 0x13) {
        result = ov11_02129144(arg, flag3, flag5);
    }
    ov11_02129B60(arg, size);
    return result;
}

void ov11_0212A570()
{
    BOOL reset = FALSE;
    if (ov11_0212C154() == 0) {
        if (sServerSendState != 4) {
            return;
        }
    } else if (sClientSendState != 4) {
        return;
    }
    if (sWork->unk_679 == 2) {
        sWork->unk_679 = 0;
        reset = TRUE;
    }
    if (sWork->unk_679 == 3) {
        reset = TRUE;
        sWork->unk_679 = 1;
    }
    if (reset) {
        ov11_0212A0C0();
    }
    ov11_0212BFD4();
}

void ov11_0212A5F8(u8 mode)
{
    u8 state = sWork->unk_679;
    if (state == 0 && mode == 1) {
        sWork->unk_679 = 3;
    } else if (state == 1 && mode == 0) {
        sWork->unk_679 = 2;
    }
}

void ov11_0212A630()
{
    ov11_0212A5F8(1);
}

u8 ov11_0212A640()
{
    u8 state = sWork->unk_679;
    if (state == 2) {
        return 1;
    }
    if (state == 3) {
        state = 0;
    }
    return state;
}

void ov11_0212A668()
{
    BOOL end = FALSE;
    if (sWork != NULL) {
        if (ov11_02128EE0() >= 0x13) {
            end = TRUE;
        } else if (ov11_021292B8()) {
            end = TRUE;
        }
    }
    if (!end) {
        return;
    }
    ov11_02129944();
    ov11_0212874C();
    sActive = 0;
    if (sWork->unk_45C != NULL) {
        Heap_Free(sWork->unk_45C);
        sWork->unk_45C = NULL;
    }
    if (sWork->unk_460 != NULL) {
        Heap_Free(sWork->unk_460);
        sWork->unk_460 = NULL;
    }
    if (sWork->unk_458 != NULL) {
        Heap_Free(sWork->unk_458);
        sWork->unk_458 = NULL;
    }
    if (sWork->unk_454 != NULL) {
        Heap_Free(sWork->unk_454);
        sWork->unk_454 = NULL;
    }
    ov11_0212C878(&sWork->unk_568);
    ov11_0212C878(&sWork->unk_548);
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void ov11_0212A7A4()
{
    if (sWork != NULL && sActive != 0) {
        ov11_0212B2A0();
        if ((ov11_0212C154() == 0 && ov11_0212BEA0(0)) || ov11_0212C1D0()) {
            ov11_0212AB58();
        }
        sActive = 0;
    }
}

void ov11_0212A804()
{
    if (!ov11_02129830()) {
        return;
    }
    if (ov11_0212C154() == 0) {
        if (ov11_0212978C() != 0) {
            return;
        }
        ov11_0212A668();
        return;
    }
    ov11_0212A668();
}

BOOL ov11_0212A83C()
{
    ov11_021285AC();
    ov11_02128C14();
    if (sWork != NULL) {
        if (sWork->unk_686 == 0) {
            sActive = 0;
            ov11_0212A570();
            ov11_0212A944();
            sWork->unk_624 &= 0x8000;
            if (ov11_0212A640() == 0) {
                ov11_0212BD58();
            }
            if ((ov11_0212C154() == 0 && ov11_0212BEA0(0)) || ov11_0212C1D0()) {
                ov11_0212AD8C();
            }
            if (ov11_0212C154() == 0 || ov11_0212A640() == 1 || ov11_0212C1D0()) {
                ov11_0212BDC8();
            }
            sActive = 1;
        }
        ov11_021296C8(sWork->unk_658);
        if (ov11_0212C154() == 0) {
            ov11_0212A4C4();
        }
        ov11_0212A804();
    } else {
        ov11_021296C8(0);
    }
    ov11_02129A74();
    ov11_0212A7A4();
    return TRUE;
}

void ov11_0212A944()
{
    if (sWork->unk_67F != 0) {
        if (ov11_02128EE0() >= 0x13) {
            return;
        }
        if ((ov11_02127B08() != 4 || !ov11_0212BEA0(ov11_0212C154())) && !ov11_0212C1D0()) {
            return;
        }
        sClientSendState = 0;
        ov11_0212B2A0();
        if (sClientSendState == 0) {
            return;
        }
        sWork->unk_67F = 0;
        return;
    }
    if (ov11_02128EE0() >= 0x13) {
        return;
    }
    if ((ov11_02127B08() != 4 || !ov11_0212BEA0(ov11_0212C154())) && !ov11_0212C1D0()) {
        return;
    }
    if (sClientSendState != 4) {
        return;
    }
    if (sWork->unk_630 > 3) {
        return;
    }
    ov11_0212B6AC(sWork->unk_000[sWork->unk_67B]);
    ov11_0212B6AC(sWork->unk_000[1 - sWork->unk_67B]);
    sClientSendState = 0;
    ov11_0212B2A0();
}

BOOL ov11_0212AA64(u8 frame)
{
    int stride;
    int i;
    int full;
    int n;

    full = 0;
    stride = ov11_0212C1A8(ov11_02128EE0());
    n = ov11_0212CE10(ov11_02128EE0()) + 1;
    for (i = 0; i < n; i++) {
        ov11_0212CA54(&sWork->unk_47C[i]);
        if (ov11_0212BEA0(i)) {
            sWork->unk_154[frame][i * stride] = 0xE;
        }
        ov11_0212C938(&sWork->unk_47C[i], &sWork->unk_154[frame][i * stride], stride);
        if (sWork->unk_154[frame][i * stride] == 0xE) {
            full++;
        }
    }
    if (full == n) {
        return FALSE;
    }
    return TRUE;
}

void ov11_0212AB58()
{
    if (sWork == NULL) {
        return;
    }
    if (ov11_02128EE0() >= 0x13) {
        return;
    }
    int i;
    int stride = ov11_0212C1A8(ov11_02128EE0());
    int n = ov11_0212CE10(ov11_02128EE0()) + 1;
    if (sServerSendState != 2 && sServerSendState != 0) {
        return;
    }
    sServerSendState++;
    if (ov11_0212A640() == 1) {
        ov11_0212AA64(sWork->unk_67C);
    }
    if (ov11_02127B08() == 4 && !ov11_0212C1D0() && !thunk_FUN_overlay_11__02127904(sWork->unk_154[sWork->unk_67C], sizeof(sWork->unk_154[0]), 14, ov11_0212B280)) {
        sServerSendState--;
    }
    if (sServerSendState == 1 || sServerSendState == 3) {
        for (i = 0; i < n; i++) {
            if (ov11_0212BEA0(i)) {
                sWork->unk_634[i]++;
            } else if (ov11_0212C1D0() && i == 0) {
                sWork->unk_634[i]++;
            }
        }
        ov11_0212AED4(0, sWork->unk_154[sWork->unk_67C], sizeof(sWork->unk_154[0]));
        sWork->unk_67C = 1 - sWork->unk_67C;
    }
    for (i = 0; i < n; i++) {
        if (!ov11_0212BEA0(i) && ov11_0212A640() == 1) {
            sWork->unk_154[sWork->unk_67C][i * stride] = 0xFF;
        }
    }
    if (ov11_02127B08() == 4 && !ov11_0212C1D0()) {
        return;
    }
    sServerSendState++;
}

void ov11_0212AD8C()
{
    if (sWork->unk_67F != 0 && (ov11_02127B08() == 4 || ov11_0212C1D0())) {
        ov11_0212AB58();
        if (sServerSendState == 2) {
            sWork->unk_67F = 0;
            return;
        }
    }
    if (ov11_02127B08() != 4 && !ov11_0212C1D0()) {
        return;
    }
    if (sServerSendState != 4) {
        return;
    }
    for (int i = 1; i < 8; i++) {
        if (ov11_0212BEA0(i)) {
            if (sWork->unk_634[i] > 3) {
                return;
            }
        } else if (i == 0 && ov11_0212C1D0() && sWork->unk_634[0] > 3) {
            return;
        }
    }
    if (ov11_0212A640() == 0) {
        ov11_0212B7E4(sWork->unk_154[sWork->unk_67C]);
        ov11_0212B7E4(sWork->unk_154[1 - sWork->unk_67C]);
    }
    sServerSendState = 0;
    ov11_0212AB58();
}

void ov11_0212AED4(u16 aid, u8 *data, u16 size)
{
    sWork->unk_630--;
    if (data == NULL) {
        return;
    }
    if (*data == 0xB) {
        if (ov11_0212A640() == 1) {
            return;
        }
        data++;
    } else if (ov11_0212A640() == 0) {
        return;
    }
    if (sWork->unk_67E != 0 && (*data & 1)) {
        return;
    }
    sWork->unk_67E = 0;
    if (ov11_0212A640() == 1) {
        int stride = ov11_0212C1A8(ov11_02128EE0());
        int n = ov11_0212CE10(ov11_02128EE0()) + 1;
        for (int i = 0; i < n; i++) {
            if (*data == 0xFF) {
                sWork->unk_658 &= ~(1 << i);
            } else {
                sWork->unk_658 |= 1 << i;
            }
            if (*data == 0xFF) {
                data += stride;
            } else if (*data == 0xE) {
                data += stride;
            } else if (sWork->unk_663[i] != 0 && (*data & 1)) {
                data += stride;
            } else {
                data++;
                ov11_0212C8B8(&sWork->unk_4E8[i], data, stride - 1, 0x5E6);
                data += stride - 1;
                sWork->unk_663[i] = 0;
            }
        }
        return;
    }
    sWork->unk_658 = data[1];
    sWork->unk_658 <<= 8;
    sWork->unk_658 += data[2];
    ov11_0212C8B8(&sWork->unk_470, data + 4, data[3], 0x5FF);
}

void ov11_0212B0C0(u16 aid, u16 *data, u16 size)
{
    if (sWork->unk_66B[aid] != 0) {
        sWork->unk_634[aid]--;
        sWork->unk_66B[aid] = 0;
        return;
    }
    ov11_0212B110(aid, (u8 *)data, size);
}

void ov11_0212B110(u16 aid, u8 *data, u16 size)
{
    sWork->unk_634[aid]--;
    if (data == NULL) {
        return;
    }
    if (sWork->unk_663[aid] != 0 && (*data & 1)) {
        return;
    }
    sWork->unk_663[aid] = 0;
    if (ov11_0212A640() == 1) {
        int stride = ov11_0212C1A8(ov11_02128EE0());
        ov11_0212CE10(ov11_02128EE0());
        if (!(*data & 2)) {
            ov11_0212C8B8(&sWork->unk_47C[aid], data, stride, 0x65E);
        }
        sWork->unk_65B[aid]++;
        return;
    }
    ov11_0212B4B4(data, aid);
    if (*data & 2) {
        return;
    }
    if (ov11_0212CA20(&sWork->unk_4E8[aid]) < 0xB) {
        return;
    }
    ov11_0212C8B8(&sWork->unk_4E8[aid], data + 1, 0xB, 0x66E);
}

void ov11_0212B260(BOOL result)
{
    if (result) {
        sClientSendState++;
    }
}

void ov11_0212B280(BOOL result)
{
    if (result) {
        sServerSendState++;
    }
}

void ov11_0212B2A0()
{
    if (sWork == NULL) {
        return;
    }
    if (ov11_02128EE0() >= 0x13) {
        return;
    }
    int stride = ov11_0212C1A8(ov11_02128EE0());
    ov11_0212CE10(ov11_02128EE0());
    if (ov11_0212C1D0()) {
        if (sClientSendState == 2 || sClientSendState == 0) {
            sClientSendState++;
            ov11_0212B260(TRUE);
            ov11_0212B110(0, sWork->unk_000[sWork->unk_67B], stride);
            sWork->unk_67B = 1 - sWork->unk_67B;
            sWork->unk_630++;
            return;
        }
    }
    if (ov11_02127B08() != 4) {
        return;
    }
    if (!ov11_0212BEA0(ov11_0212C154())) {
        ov11_0212C154();
        return;
    }
    if (sClientSendState != 2 && sClientSendState != 0) {
        return;
    }
    if (ov11_0212C154() != 0) {
        sClientSendState++;
        if (!thunk_FUN_overlay_11__02127904(sWork->unk_000[sWork->unk_67B], stride, 14, ov11_0212B260)) {
            sClientSendState--;
            return;
        }
        sWork->unk_67B = 1 - sWork->unk_67B;
        sWork->unk_630++;
        return;
    }
    if (!(ov11_02127AA4() & 0xFFFE)) {
        return;
    }
    sClientSendState++;
    ov11_0212B260(TRUE);
    ov11_0212B110(0, sWork->unk_000[sWork->unk_67B], stride);
    sWork->unk_67B = 1 - sWork->unk_67B;
    sWork->unk_630++;
}

BOOL ov11_0212B4B4(u8 *data, int aid)
{
    sWork->unk_60C[aid] = 0;
    if ((*data & 0x10) == 0x10) {
        u8 type = *data & 0xC;
        if (type == 0) {
            sWork->unk_60C[aid] |= 0x40;
        } else if (type == 4) {
            sWork->unk_60C[aid] |= 0x80;
        } else if (type == 8) {
            sWork->unk_60C[aid] |= 0x20;
        } else if (type == 12) {
            sWork->unk_60C[aid] |= 0x10;
        }
        sWork->unk_61C[aid] = (*data >> 5) & 7;
    }
    return TRUE;
}

BOOL ov11_0212B59C(u8 *hdr)
{
    if (sWork->unk_626 != 0) {
        return FALSE;
    }
    if (!ov11_0212BFAC()) {
        return FALSE;
    }
    if (sWork->unk_67D != 0) {
        sWork->unk_67D--;
    }
    u16 flags = sWork->unk_624;
    if (flags & 0x40) {
        *hdr |= 0x10;
        sWork->unk_67D = 8;
    } else if (flags & 0x80) {
        *hdr |= 0x14;
        sWork->unk_67D = 8;
    } else if (flags & 0x20) {
        *hdr |= 0x18;
        sWork->unk_67D = 8;
    } else if (flags & 0x10) {
        *hdr |= 0x1C;
        sWork->unk_67D = 8;
    }
    *hdr |= (u8)(sWork->unk_627 << 5);
    return FALSE;
}

BOOL ov11_0212B6AC(u8 *frame)
{
    int stride = ov11_0212C1A8(ov11_02128EE0());
    ov11_0212CE10(ov11_02128EE0());
    if (sWork->unk_680 == 0) {
        *frame = 0;
    } else {
        *frame = 1;
    }
    if (ov11_0212A640() == 0) {
        ov11_0212B59C(frame);
    }
    sWork->unk_680 = 0;
    if (ov11_0212C33C(&sWork->unk_548)) {
        *frame |= 2;
        if (*frame == 2) {
            return FALSE;
        }
    } else {
        CommQueueCursor cursor;
        cursor.size = stride - 1;
        cursor.ptr = frame + 1;
        if (!ov11_0212C724(&sWork->unk_548, &cursor, 1)) {
            sWork->unk_680 = 1;
        }
        if (ov11_0212A640() == 1) {
            sWork->unk_65A++;
            *frame |= (sWork->unk_65A << 4) & 0xF0;
        }
    }
    return TRUE;
}

void ov11_0212B7E4(u8 *frame)
{
    frame[0] = 0xB;
    if (sWork->unk_681 == 0) {
        frame[1] = 0;
    } else {
        frame[1] = 1;
    }
    u16 bitmap = ov11_02127AA4();
    frame[2] = bitmap >> 8;
    frame[3] = bitmap;
    CommQueueCursor cursor;
    cursor.size = 0xBB;
    cursor.ptr = frame + 5;
    if (ov11_0212C724(&sWork->unk_568, &cursor, 0)) {
        sWork->unk_681 = 0;
        frame[4] = 0xBB - cursor.size;
        return;
    }
    sWork->unk_681 = 1;
    frame[4] = 0xBB;
}

BOOL ov11_0212B8A0(u8 cmd, u8 *data, u16 size)
{
    if (!ov11_0212BEA0(ov11_0212C154()) && !ov11_0212C1D0()) {
        return FALSE;
    }
    if (ov11_0212C5FC(&sWork->unk_548, cmd, data, size, 1, 0)) {
        return TRUE;
    }
    if (ov11_02128EE0() == 10) {
        ov11_0212C2E4();
    }
    return FALSE;
}

BOOL ov11_0212B938(u8 cmd, u8 *data, u16 size)
{
    if (!ov11_0212BEA0(ov11_0212C154()) && !ov11_0212C1D0()) {
        return FALSE;
    }
    if (ov11_0212C5FC(&sWork->unk_548, cmd, data, size, 1, 1)) {
        return TRUE;
    }
    if (ov11_02128EE0() == 10) {
        ov11_0212C2E4();
    }
    return FALSE;
}

BOOL ov11_0212B9CC(u8 cmd, u8 *data, u16 size)
{
    if (ov11_0212C154() != 0) {
        return FALSE;
    }
    if (!ov11_0212BEA0(0) && !ov11_0212C1D0()) {
        return FALSE;
    }
    if (ov11_0212A640() == 1) {
        return ov11_0212B8A0(cmd, data, size);
    }
    if (ov11_0212C5FC(&sWork->unk_568, cmd, data, size, 1, 0)) {
        return TRUE;
    }
    if (ov11_02128EE0() == 10) {
        ov11_0212C2E4();
    }
    return FALSE;
}

BOOL ov11_0212BA98(u8 cmd, u8 *data, u16 size)
{
    if (ov11_0212C154() != 0) {
        ov11_0212C2E4();
        return FALSE;
    }
    if (!ov11_0212BEA0(0) && !ov11_0212C1D0()) {
        return FALSE;
    }
    if (ov11_0212A640() == 1) {
        return ov11_0212B938(cmd, data, size);
    }
    if (ov11_0212C5FC(&sWork->unk_568, cmd, data, size, 1, 1)) {
        return TRUE;
    }
    if (ov11_02128EE0() == 10) {
        ov11_0212C2E4();
    }
    return FALSE;
}

BOOL ov11_0212BB6C(u8 cmd, u8 *data)
{
    return ov11_0212BA98(cmd, data, 0);
}

void ov11_0212BB7C(int aid, int cmd, int size, u8 *data, CommRecvState *pending)
{
    ov11_0212CB10(aid, cmd, size, data);
    pending->unk_A = 0xEE;
    pending->unk_8 = 0xFFFF;
    pending->unk_4 = NULL;
    pending->unk_0 = 0;
}

void ov11_0212BBAC(CommRing *ring, int aid, u8 *buf, int flag, CommRecvState *pending)
{
    int size;
    s16 pos;
    u8 cmd;

    if (ov11_0212C9F4(ring) == 0) {
        return;
    }
    do {
        cmd = pending->unk_A;
        if (cmd != 0xEE || (cmd = ov11_0212C964(ring)) != 0xEE) {
            pos = ring->startIndex;
            pending->unk_A = cmd;
            size = pending->unk_8;
            if (size == 0xFFFF) {
                size = ov11_0212CBA4(cmd);
                if (sWork->unk_685 != 0) {
                    return;
                }
                if (size == 0xFFFF) {
                    if (ov11_0212C9F4(ring) < 1) {
                        ring->startIndex = pos;
                        return;
                    }
                    int hi = ov11_0212C964(ring);
                    size = ov11_0212C964(ring) + (hi << 8);
                    pos = ring->startIndex;
                }
                pending->unk_8 = size;
            }
            if (ov11_0212CC34(cmd)) {
                if (pending->unk_4 == NULL) {
                    pending->unk_4 = ov11_0212CC90(cmd, aid, pending->unk_8);
                }
                int n = ov11_0212C938(ring, buf, size - pending->unk_0);
                if (pending->unk_4 != NULL) {
                    MI_CpuCopy8(buf, &pending->unk_4[pending->unk_0], n);
                }
                pending->unk_0 += n;
                if (pending->unk_0 >= size) {
                    ov11_0212BB7C(aid, cmd, size, pending->unk_4, pending);
                }
            } else if (ov11_0212C9F4(ring) >= size) {
                ov11_0212C938(ring, buf, size);
                ov11_0212BB7C(aid, cmd, size, buf, pending);
            } else {
                ring->startIndex = pos;
                return;
            }
        }
    } while (ov11_0212C9F4(ring) != 0);
}

void ov11_0212BD58()
{
    if (sWork == NULL) {
        return;
    }
    if (sWork->unk_687 != 0) {
        return;
    }
    ov11_0212CA54(&sWork->unk_470);
    if (ov11_0212C9F4(&sWork->unk_470) <= 0) {
        return;
    }
    ov11_0212BBAC(&sWork->unk_470, 0, sWork->unk_460, 1, &sWork->unk_5E8);
}

void ov11_0212BDC8()
{
    if (sWork == NULL) {
        return;
    }
    if (sWork->unk_687 != 0) {
        return;
    }
    int i;
    int n = ov11_0212CE10(ov11_02128EE0()) + 1;
    for (i = 0; i < n; i++) {
        ov11_0212CA54(&sWork->unk_4E8[i]);
        if (ov11_0212C9F4(&sWork->unk_4E8[i]) > 0) {
            ov11_0212BBAC(&sWork->unk_4E8[i], i, sWork->unk_460, 0, &sWork->unk_588[i]);
        }
    }
}

BOOL ov11_0212BEA0(u16 aid)
{
    if (sWork == NULL) {
        return FALSE;
    }
    if (ov11_02128EE0() >= 0x13) {
        return FALSE;
    }
    if (!ov11_0212BF7C()) {
        return FALSE;
    }
    if (ov11_02127B08() != 4) {
        return FALSE;
    }
    if (aid == ov11_0212C154()) {
        return TRUE;
    }
    if (ov11_0212C154() == 0) {
        if (ov11_02127AA4() & (1 << aid)) {
            return TRUE;
        }
    } else if (sWork->unk_658 & (1 << aid)) {
        return TRUE;
    }
    return FALSE;
}

int ov11_0212BF48()
{
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (ov11_0212BEA0(i)) {
            count++;
        }
    }
    return count;
}

BOOL ov11_0212BF7C()
{
    if (sWork != NULL && ov11_02128EE0() >= 0x13) {
        return TRUE;
    }
    return ov11_02129770();
}

int ov11_0212BFAC()
{
    return sWork != NULL ? sWork->unk_624 & 0x8000 : TRUE;
}

void ov11_0212BFD4()
{
    if (sWork == NULL) {
        return;
    }
    switch (sWork->unk_677) {
    case 1: {
        BOOL sent;
        if (ov11_0212A640() == 1) {
            sent = ov11_0212C198(0xB, &sWork->unk_678);
        } else {
            sent = ov11_0212BA98(0xB, &sWork->unk_678, 1);
        }
        if (!sent) {
            return;
        }
        sWork->unk_677 = 2;
        break;
    }
    case 3:
        if (!ov11_0212C198(0xC, &sWork->unk_678)) {
            return;
        }
        ov11_0212A5F8(sWork->unk_678);
        sWork->unk_677 = 0;
        break;
    }
}

void ov11_0212C09C(int aid, int size, u8 *data)
{
    if (ov11_0212C154() != 0) {
        return;
    }
    sWork->unk_677 = 1;
    sWork->unk_678 = *data;
}

void ov11_0212C0D4(int aid, int size, u8 *data)
{
    if (ov11_0212C154() == 0) {
        return;
    }
    sWork->unk_678 = *data;
    sWork->unk_677 = 3;
}

void ov11_0212C10C(int aid, int size, u8 *data)
{
    if (ov11_0212C154() != 0) {
        return;
    }
    if (sWork->unk_677 != 2) {
        return;
    }
    ov11_0212A5F8(*data);
    sWork->unk_677 = 0;
}

u16 ov11_0212C154()
{
    if (sWork != NULL && ov11_02128EE0() < 0x13) {
        if (ov11_0212C1D0()) {
            return 0;
        }
        return ov11_02128330();
    }
    return 0;
}

BOOL ov11_0212C198(u8 cmd, u8 *data)
{
    return ov11_0212B938(cmd, data, 0);
}

int ov11_0212C1A8(u16 mode)
{
    if (ov11_0212CE10(mode) >= 5) {
        return 12;
    }
    if (ov11_0212A640() == 0) {
        return 12;
    }
    return 0x26;
}

BOOL ov11_0212C1D0()
{
    CommSystem *work = sWork;
    return work != NULL ? work->unk_682 : 0;
}

void ov11_0212C1EC()
{
    u8 data;
    if (!ov11_02129830() && ov11_0212C154() == 0) {
        ov11_0212BB6C(2, &data);
    }
    ov11_02129858();
}

void ov11_0212C21C(MATHRandContext32 *ctx)
{
    RTCDate date;
    RTCTime time;
    RTC_GetDate(&date);
    RTC_GetTime(&time);
    MATH_InitRand32(ctx, ((((((((((u64)date.year * 16) + date.month) * 32) + date.day) * 32) + time.hour) * 64) + time.minute) * 64) + (time.second + 0x25));
}

void ov11_0212C2E4()
{
    sWork->unk_685 = 1;
}

// size of RangerNetSessionParam (RangerNetPlayerInfo.cpp)
u32 ov11_0212C2FC()
{
    return 0x20;
}
