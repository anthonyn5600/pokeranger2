#include <nitro/wm.h>
#include <string.h>

#include "common.hpp"
#include "heap.hpp"

// D3: per-player info table (021286BC..02128A94)

struct D3Info {
    u8 unk_00[0x19];
    u8 unk_19;
    u8 unk_1A[0x6];
};

struct D3Entry {
    u8 unk_00[0x20];
    D3Info unk_20;
    u8 unk_40[0x1C];
    u8 mac[6];
    u8 unk_62;
    u8 unk_63[0x5];
};

struct D3Work {
    D3Entry entries[8];
    D3Info *unk_340[8];
    u8 unk_360[0x30];
    u8 unk_390[8];
    u8 unk_398;
    u8 unk_399;
    u8 unk_39A;
};

static D3Work *sWork;

// D4's default session parameter (RangerNetSession.cpp keeps a pointer to it and passes it on to D5). Defined in
// this TU: mwcc size-sorts a TU's .data, so in D4's own TU it would land after D4's 6-byte message strings.
struct RangerNetSessionParam {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u8 unk_0C[0x14];
};
RangerNetSessionParam gRangerNetSessionParam = { 0, 0, 2 };

void ov11_02129800(const u8 *mac, int aid); // D5
extern "C" int ov11_0212B938(u8 type, void *data, u8 size);
extern "C" BOOL ov11_0212BEA0(u16 aid);
extern "C" BOOL ov11_0212BF48();
extern "C" u8 ov11_0212C154();
extern "C" BOOL ov11_0212C1D0();

void ov11_02128974(int i);
void ov11_02128A74(D3Info *info);

void ov11_021286BC()
{
    if (sWork != NULL) {
        return;
    }
    sWork = (D3Work *)Heap_Alloc(sizeof(D3Work));
    MI_CpuFill8(sWork, 0, sizeof(D3Work));
    for (int i = 0; i < 8; i++) {
        sWork->unk_340[i] = &sWork->entries[i].unk_20;
        ov11_02128974(i);
    }
    sWork->unk_398 = 0;
    sWork->unk_399 = 0;
    sWork->unk_39A = 0;
}

void ov11_0212874C()
{
    if (sWork == NULL) {
        return;
    }
    for (int i = 0; i < 8; i++) {
        sWork->unk_340[i] = NULL;
    }
    if (sWork != NULL) {
        Heap_Free(sWork);
    }
    sWork = NULL;
}

void ov11_021287A8()
{
    int idx = ov11_0212C154();
    OS_GetMacAddress(sWork->entries[idx].mac);
    ov11_0212B938(3, &sWork->entries[idx], sizeof(D3Entry));
}

u32 ov11_021287EC()
{
    return sizeof(D3Entry);
}

void ov11_021287F4()
{
    if (sWork != NULL) {
        sWork->unk_398 = 1;
    }
}

void ov11_02128810(int aid, int size, D3Entry *data)
{
    if (sWork == NULL) {
        return;
    }
    if (data->unk_20.unk_19 != 2) {
        WM_Disconnect(NULL, (u16)aid);
        return;
    }
    MI_CpuCopy8(data, &sWork->entries[data->unk_62], sizeof(D3Entry));
    sWork->unk_39A = data->unk_62;
    if (sWork->unk_390[sWork->unk_39A] >= 2) {
        return;
    }
    sWork->unk_390[sWork->unk_39A] = 1;
    u8 idx = sWork->unk_39A;
    if (idx != ov11_0212C154()) {
        return;
    }
    sWork->unk_390[idx] = 3;
}

void ov11_021288BC(int aid, int size, D3Entry *data)
{
    if (sWork == NULL) {
        return;
    }
    if (data->unk_20.unk_19 != 2) {
        WM_Disconnect(NULL, (u16)aid);
        return;
    }
    MI_CpuCopy8(data, &sWork->entries[aid], sizeof(D3Entry));
    ov11_02129800(sWork->entries[aid].mac, aid);
    sWork->unk_390[aid] = 1;
    if (aid == ov11_0212C154()) {
        sWork->unk_390[aid] = 3;
        return;
    }
    sWork->unk_399 = 1;
}

void ov11_02128974(int i)
{
    ov11_02128A74(sWork->unk_340[i]);
    sWork->unk_390[i] = 0;
}

void ov11_021289AC()
{
    if (sWork == NULL) {
        return;
    }
    if (!ov11_0212BF48()) {
        return;
    }
    for (u16 i = 0; i < 8; i++) {
        if (!ov11_0212BEA0(i) && (i != 0 || !ov11_0212C1D0()) && sWork->unk_390[i] != 0) {
            ov11_02128974(i);
        }
    }
}

D3Info *ov11_02128A30(u16 aid)
{
    if (sWork == NULL) {
        return NULL;
    }
    switch (sWork->unk_390[aid]) {
    case 1:
    case 2:
    case 3:
        return sWork->unk_340[aid];
    }
    return NULL;
}

void ov11_02128A74(D3Info *info)
{
    memset(info, 0, sizeof(D3Info));
    info->unk_19 = 2;
}
