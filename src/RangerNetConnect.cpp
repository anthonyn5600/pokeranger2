#include <nitro/math.h>

#include "common.hpp"
#include "heap.hpp"

// D2: connection manager work block (02128478..021286BC)

struct D2Work {
    int unk_00;
    MATHRandContext32 unk_04;
    void (*unk_1C)();
    u16 unk_20;
    u8 unk_22;
    u8 unk_23;
    void *unk_24[16];
    u8 unk_64[0x358];
    u8 unk_3BC;
    u8 unk_3BD[16];
};

static D2Work *sWork;

void ov11_021287A8(); // D3 (RangerNetPlayerInfo.cpp)
void *ov11_02128A30(u16 aid); // D3 (RangerNetPlayerInfo.cpp)
void ov11_02128B9C(u8 arg); // D4
void ov11_02128BDC(); // D4
int ov11_0212B9CC(u8 cmd, u8 *data, u16 size);
BOOL ov11_0212BEA0(u16 aid);
BOOL ov11_0212BF7C();
u8 ov11_0212C154();
void ov11_0212C21C(MATHRandContext32 *ctx);
void ov11_0212CDF4(int arg);

void ov11_021284DC(void (*func)(), u16 n);
void ov11_0212854C();

void ov11_02128478(int arg)
{
    if (sWork != NULL) {
        return;
    }
    ov11_0212CDF4(arg);
    sWork = (D2Work *)Heap_Alloc(sizeof(D2Work));
    MI_CpuFill8(sWork, 0, sizeof(D2Work));
    sWork->unk_20 = 0x32;
    sWork->unk_00 = arg;
    ov11_0212C21C(&sWork->unk_04);
}

void ov11_021284DC(void (*func)(), u16 n)
{
    sWork->unk_1C = func;
    sWork->unk_20 = n;
}

void ov11_021284F8()
{
    if (!ov11_0212BEA0(ov11_0212C154())) {
        return;
    }
    for (int i = 0; i < 16; i++) {
        sWork->unk_3BD[i] = 0;
    }
    ov11_021287A8();
    ov11_021284DC(ov11_0212854C, 0);
}

void ov11_0212854C()
{
    for (u16 i = 0; i < 16; i++) {
        if (sWork->unk_24[i] == NULL && ov11_0212BEA0(i) == TRUE) {
            sWork->unk_24[i] = ov11_02128A30(i);
        }
    }
}

void ov11_021285AC()
{
    D2Work *work = sWork;
    if (work != NULL && work->unk_1C != NULL) {
        if (work->unk_22 == 0) {
            work->unk_1C();
        }
    }
}

void ov11_021285E0(int arg, u8 arg2)
{
    if (ov11_0212BF7C()) {
        return;
    }
    ov11_02128B9C(arg2);
    ov11_02128478(arg);
    ov11_021284DC(ov11_021284F8, 0);
}

void ov11_0212861C(void *data, u16 size)
{
    ov11_0212B9CC(0x16, (u8 *)data, size);
}

void ov11_02128634(u8 v)
{
    if (sWork->unk_23 == v) {
        sWork->unk_3BC = 1;
    }
}

u32 ov11_02128654()
{
    return sizeof(sWork->unk_64);
}

void *ov11_0212865C()
{
    return sWork->unk_64;
}

void ov11_02128670(int i)
{
    sWork->unk_3BD[i] = 1;
}

void ov11_0212868C()
{
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
    ov11_02128BDC();
}
