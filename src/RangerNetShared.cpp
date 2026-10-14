#include "common.hpp"
#include "heap.hpp"

// D6: shared per-player values and blocks (021298C4..02129B60)

struct D6Work {
    u8 unk_000[8][2];
    u8 unk_010[8];
    u8 unk_018[8][0x46];
    u8 unk_248[8];
    u8 unk_250;
    u8 unk_251;
    u8 unk_252;
};

static D6Work *sWork;

extern "C" void ov11_0212BB6C(u8 cmd, u8 *data);
extern "C" BOOL ov11_0212BEA0(u16 aid);
extern "C" u16 ov11_0212C154();
extern "C" BOOL ov11_0212C198(u8 cmd, u8 *data);

void ov11_021298C4()
{
    if (sWork == NULL) {
        sWork = (D6Work *)Heap_Alloc(sizeof(D6Work));
        MI_CpuFill8(sWork, 0, sizeof(D6Work));
    }
    for (int i = 0; i < 8; i++) {
        sWork->unk_010[i] = 0xFF;
    }
    sWork->unk_250 = 0xFF;
    sWork->unk_251 = 0xFF;
    sWork->unk_252 = 0;
}

void ov11_02129944()
{
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void ov11_02129970(u8 aid, int size, u8 *data)
{
    u8 value = data[0];
    if (ov11_0212C154() != 0) {
        return;
    }
    u8 msg[2];
    msg[0] = aid;
    msg[1] = value;
    ov11_0212BB6C(0x12, msg);
    sWork->unk_010[aid] = value;
    for (u16 i = 0; i < 8; i++) {
        if (ov11_0212BEA0(i) && value != sWork->unk_010[i]) {
            return;
        }
    }
    ov11_0212BB6C(0x11, &value);
}

void ov11_02129A1C(int aid, int size, const u8 *data)
{
    sWork->unk_010[data[0]] = data[1];
}

void ov11_02129A3C(int aid, int size, const u8 *data)
{
    sWork->unk_250 = data[0];
}

void ov11_02129A54(u8 v)
{
    sWork->unk_251 = v;
    sWork->unk_252 = 1;
}

void ov11_02129A74()
{
    if (sWork != NULL && sWork->unk_252 != 0) {
        if (!ov11_0212C198(0x10, &sWork->unk_251)) {
            return;
        }
        sWork->unk_252 = 0;
    }
}

BOOL ov11_02129AC0(u8 v)
{
    if (sWork == NULL) {
        return TRUE;
    }
    return sWork->unk_250 == v;
}

void ov11_02129AEC(int aid, int size, const u8 *data)
{
    sWork->unk_000[aid][0] = data[0];
    sWork->unk_000[aid][1] = data[1];
}

u32 ov11_02129B14()
{
    return sizeof(sWork->unk_000[0]);
}

void ov11_02129B1C(int idx, int size, const void *data)
{
    sWork->unk_248[idx] = 1;
    MI_CpuCopy8(data, sWork->unk_018[idx], sizeof(sWork->unk_018[0]));
}

u32 ov11_02129B58()
{
    return sizeof(sWork->unk_018[0]);
}
