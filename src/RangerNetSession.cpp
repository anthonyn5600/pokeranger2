#include "common.hpp"
#include "heap.hpp"

// D4: wireless session setup (02128A94..02128F1C)

// defined in RangerNetPlayerInfo.cpp (see there)
struct RangerNetSessionParam {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0C[0x14];
};
extern RangerNetSessionParam gRangerNetSessionParam;

struct D4Work {
    u8 unk_00[0x8];
    u8 unk_08[0x18];
    void (*unk_20)();
    RangerNetSessionParam *unk_24;
    u8 unk_28[0x6];
    u16 unk_2E;
    u8 unk_30;
    u8 unk_31;
    u8 unk_32;
    u8 unk_33;
    u8 unk_34;
    u8 unk_35[0x2];
    u8 unk_37;
    u8 unk_38[0x4];
    u8 unk_3C;
    u8 unk_3D[0x7];
};

static D4Work *sWork;
static u8 sFreak[] = "FREAK";
static u8 sGame[] = " GAME";
static u8 sFull[] = " FULL";

void ov11_021286BC(); // D3 (RangerNetPlayerInfo.cpp)
void ov11_02128F1C(RangerNetSessionParam *param); // D5
BOOL ov11_02129024(); // D5
BOOL ov11_021291DC(); // D5
extern "C" BOOL ov11_0212A524(u8 a, u8 b, int c, int d);
extern "C" void ov11_0212A630();
extern "C" void ov11_0212A668();
extern "C" void ov11_0212BB6C(u8 cmd, u8 *data);
extern "C" BOOL ov11_0212BEA0(u16 aid);
extern "C" BOOL ov11_0212BF7C();
extern "C" u16 ov11_0212C154();
extern "C" void ov11_0212C21C(void *p);
extern "C" void ov11_0212CA60(void *a, int b, int c);
extern "C" void ov11_0212CAE0();

void ov11_02128C3C(void (*func)(), u16 n);
void ov11_02128C58();
void ov11_02128C70();
void ov11_02128E38();
void ov11_02128E60();
void ov11_02128E84();

void ov11_02128A94(u8 arg)
{
    if (sWork != NULL) {
        return;
    }
    sWork = (D4Work *)Heap_Alloc(sizeof(D4Work));
    MI_CpuFill8(sWork, 0, sizeof(D4Work));
    sWork->unk_2E = 0x32;
    sWork->unk_37 = 1;
    sWork->unk_24 = &gRangerNetSessionParam;
    sWork->unk_30 = 2;
    sWork->unk_31 = 0;
    sWork->unk_3C = 0;
    sWork->unk_33 = arg;
    ov11_0212C21C(sWork->unk_08);
    ov11_0212CA60(NULL, 0, 0);
}

void ov11_02128B40()
{
    if (sWork == NULL) {
        return;
    }
    ov11_0212CAE0();
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

BOOL ov11_02128B80()
{
    if (sWork != NULL) {
        return TRUE;
    }
    return FALSE;
}

void ov11_02128B9C(u8 arg)
{
    if (ov11_0212BF7C()) {
        return;
    }
    ov11_02128A94(arg);
    sWork->unk_33 = arg;
    ov11_02128C3C(ov11_02128E84, 0);
}

void ov11_02128BDC()
{
    if (sWork != NULL) {
        ov11_02128C3C(ov11_02128C70, 5);
    }
}

extern "C" void thunk_FUN_overlay_11__02128b40()
{
    ov11_02128B40();
}

void ov11_02128C14()
{
    if (sWork != NULL && sWork->unk_20 != NULL) {
        sWork->unk_20();
    }
}

void ov11_02128C3C(void (*func)(), u16 n)
{
    sWork->unk_20 = func;
    sWork->unk_2E = n;
}

void ov11_02128C58()
{
    if (ov11_0212BF7C()) {
        return;
    }
    ov11_02128B40();
}

void ov11_02128C70()
{
    if (sWork->unk_2E != 0) {
        sWork->unk_2E--;
    }
    if (!ov11_021291DC()) {
        return;
    }
    if (sWork->unk_2E != 0) {
        return;
    }
    ov11_0212A668();
    ov11_02128C3C(ov11_02128C58, 0);
}

void ov11_02128CC8(u8 aid, int size, u8 *data)
{
    u32 i;
    BOOL match;

    if (ov11_0212C154() != 0) {
        return;
    }
    match = TRUE;
    for (i = 0; i < 6; i++) {
        if (sFreak[i] != data[i]) {
            match = FALSE;
            break;
        }
    }
    if (match && sWork->unk_3C == 0) {
        sGame[0] = aid;
        ov11_0212BB6C(7, sGame);
        return;
    }
    sFull[0] = aid;
    ov11_0212BB6C(7, sFull);
}

void ov11_02128D64(int aid, int size, u8 *data)
{
    u8 id;
    u32 i;
    BOOL match;

    match = TRUE;
    for (i = 1; i < 6; i++) {
        if (sGame[i] != data[i]) {
            match = FALSE;
            break;
        }
    }
    if (match) {
        id = data[0];
        if (id == ov11_0212C154()) {
            sWork->unk_31 = 1;
        }
        return;
    }
    match = TRUE;
    for (i = 1; i < 6; i++) {
        if (sFull[i] != data[i]) {
            match = FALSE;
            break;
        }
    }
    if (match) {
        id = data[0];
        if (id == (u8)ov11_0212C154()) {
            sWork->unk_31 = 2;
        }
    }
}

u32 ov11_02128E30()
{
    return sizeof(sFreak);
}

void ov11_02128E38()
{
    if (!ov11_0212BEA0(ov11_0212C154())) {
        return;
    }
    ov11_02128C3C(ov11_02128E60, 0);
}

void ov11_02128E60()
{
    if (ov11_0212BF7C()) {
        return;
    }
    ov11_02128C3C(ov11_02128C58, 0);
}

void ov11_02128E84()
{
    if (!ov11_02129024()) {
        return;
    }
    ov11_02128F1C(sWork->unk_24);
    ov11_021286BC();
    if (!ov11_0212A524(1, 1, 0x200, 1)) {
        return;
    }
    ov11_0212A630();
    ov11_02128C3C(ov11_02128E38, 0);
}

int ov11_02128EE0()
{
    if (sWork != NULL) {
        return sWork->unk_33;
    }
    return 1;
}

u8 ov11_02128EFC()
{
    if (sWork != NULL) {
        return sWork->unk_34;
    }
    return 0;
}
