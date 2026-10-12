#include "UnkClass_02027FE8.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "CPowerManage.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "heap.hpp"

extern u8 MAIN_BSS_0210C0B0[];
extern u32 DAT_0208b5c0;
extern u32 MAIN_BSS_0210CA38;

extern "C" u32 sub_02016E7C(UnkClass_020B26A0 *save, u32 value);

#define SAVE_FIELD(offset) ((u8 *)&MAIN_BSS_020B26A0 + (offset))

const char *sSaveMagic = "DSPRS\0\0\0";

SaveBlock sEmptyBlocks[] = {
    { NULL, 0x1C8 },
    { NULL, 1 },
};

SaveBlock sOptionBlocks[] = {
    { &MAIN_BSS_020AF620, 0x3004 },
    { NULL, 1 },
};

extern SaveBlock sMainBlocks[];
extern SaveBlock sMainBlocks1[];

SaveBlock *sSaveLists[] = {
    sMainBlocks,
    sMainBlocks1,
    sOptionBlocks,
    sOptionBlocks,
    sOptionBlocks,
    sOptionBlocks,
    sOptionBlocks,
    sOptionBlocks,
};

#define SAVE_BLOCKS(copies)                                                                                              \
    { SAVE_FIELD(0), 0x8804 }, { SAVE_FIELD(0x8804), 0x18 }, { SAVE_FIELD(0x881C), 0x18 }, { SAVE_FIELD(0x8834), 0x18 }, \
        { SAVE_FIELD(0x884C), 0x18 }, { SAVE_FIELD(0x8864), 0x18 }, { SAVE_FIELD(0x887C), 0x18 },                        \
        { SAVE_FIELD(0x8894), 0x18 }, { SAVE_FIELD(0x88AC), 0x18 }, { SAVE_FIELD(0x88F4), 0x18 },                        \
        { SAVE_FIELD(0x890C), 0x18 }, { SAVE_FIELD(0x8924), 0x18 }, { SAVE_FIELD(0x893C), 0x18 },                        \
        { SAVE_FIELD(0x8954), 0x18 }, { SAVE_FIELD(0x896C), 0x18 }, { SAVE_FIELD(0x8984), 0x18 },                        \
        { SAVE_FIELD(0x899C), 0x18 }, { SAVE_FIELD(0x89E4), 0x18 }, { SAVE_FIELD(0x89FC), 0x18 },                        \
        { SAVE_FIELD(0x8A14), 0x18 }, { SAVE_FIELD(0x8A2C), 0x18 }, { SAVE_FIELD(0x8A44), 0x18 },                        \
        { SAVE_FIELD(0x8A5C), 0x18 }, { SAVE_FIELD(0x8A74), 0x18 }, { SAVE_FIELD(0x8A8C), 0x18 },                        \
        { SAVE_FIELD(0x8AD4), 0x38 }, { SAVE_FIELD(0x8B0C), 0x38 }, { &MAIN_BSS_020B2638, 0x54 },                        \
        { MAIN_BSS_0210C0B0, 0xFC }, { NULL, 0 }, { NULL, 0 }, { &DAT_0208b5c0, 4 }, { &MAIN_BSS_020AF5E4[0], 8 },       \
        { &MAIN_BSS_020AF5E4[1], 8 }, { &MAIN_BSS_020AF5E4[2], 8 }, { &MAIN_BSS_020AF598, 2 },                           \
    {                                                                                                                    \
        NULL, copies                                                                                                     \
    }

SaveBlock sMainBlocks[] = { SAVE_BLOCKS(2) };
SaveBlock sMainBlocks1[] = { SAVE_BLOCKS(1) };

UnkClass_02027FE8::UnkClass_02027FE8(u32 card)
{
    unk_54 = 0;
    unk_64 = 0;
    unk_68 = NULL;
    unk_58 = NULL;
    unk_5C = 0;
    unk_6C = FALSE;
    unk_70 = FALSE;
    unk_66 = 8;
    CGame::GetInstance()->unk_15D4 = 0;
    if (card) {
        unk_00 = &unk_04;
    } else {
        unk_00 = &unk_18;
    }
}

UnkClass_02027FE8::~UnkClass_02027FE8()
{
    if (unk_58 != NULL) {
        Heap_Free(unk_58);
        unk_58 = NULL;
    }
    CGame::GetInstance()->unk_15D4 = 1;
}

void UnkClass_02027FE8::SetDevice(int device)
{
    switch (device) {
    case 1:
    default:
        unk_00 = &unk_04;
        break;
    case 0:
        unk_00 = &unk_18;
        break;
    }
}

u32 UnkClass_02027FE8::GetCopies(int list)
{
    SaveBlock *block = sSaveLists[list];
    while (block->data != NULL) {
        block++;
    }
    return block->size;
}

u32 UnkClass_02027FE8::GetSize(int list)
{
    u32 size = 0;
    SaveBlock *block = sSaveLists[list];
    while (block->data != NULL) {
        size += block->size;
        block++;
    }
    return size;
}

u32 UnkClass_02027FE8::GetOffset(u16 list)
{
    return SumRegions(list);
}

u32 UnkClass_02027FE8::SumRegions(u16 count)
{
    u32 offset = 0;
    for (u16 i = 0; i < count; i++) {
        offset += GetRegionSize(i);
    }
    return offset;
}

u32 UnkClass_02027FE8::GetSlotOffset(int slot)
{
    return unk_60 + sizeof(SaveHeader) + slot * unk_5C;
}

u32 UnkClass_02027FE8::GetRegionSize(int list)
{
    return GetSize(list) * GetCopies(list) + sizeof(SaveHeader);
}

void UnkClass_02027FE8::SelectList(u16 list)
{
    if (unk_66 == list) {
        return;
    }
    unk_68 = sSaveLists[list];
    u32 size = GetSize(list);
    if (unk_58 != NULL) {
        Heap_Free(unk_58);
        unk_58 = NULL;
    }
    unk_58 = (u8 *)Heap_Alloc(size);
    unk_5C = size;
    unk_60 = GetOffset(list);
    unk_66 = list;
}

BOOL UnkClass_02027FE8::sub_02028220(u16 list)
{
    SelectList(list);
    switch (unk_54) {
    case 0:
    case 11:
    case 13:
    case 20:
    case 21:
    case 24:
    case 25:
        unk_65 = 1;
        unk_64 = 0;
        SetState(1, 0);
        CPowerManage::sub_0200FA2C(0);
        if (list == 0) {
            sub_02016E7C(&MAIN_BSS_020B26A0, 1);
        }
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_02027FE8::Load(u16 list)
{
    SelectList(list);
    switch (unk_54) {
    case 0:
    case 11:
    case 13:
    case 20:
    case 21:
    case 24:
    case 25:
        unk_65 = 2;
        unk_64 = 0;
        SetState(14, 0);
        CPowerManage::sub_0200FA2C(0);
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_02027FE8::sub_02028360(u16 list)
{
    unk_70 = TRUE;
    return Load(list);
}

BOOL UnkClass_02027FE8::Clear(u16 list)
{
    SelectList(list);
    switch (unk_54) {
    case 0:
    case 11:
    case 13:
    case 20:
    case 21:
    case 24:
    case 25:
        unk_65 = 3;
        unk_64 = 0;
        SetState(1, 0);
        CPowerManage::sub_0200FA2C(0);
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_02027FE8::sub_02028408(u16 list)
{
    unk_6C = TRUE;
    return Load(list);
}

u32 UnkClass_02027FE8::sub_0202841C()
{
    switch (unk_65) {
    case 1:
        return UpdateWrite(FALSE);
    case 2:
        return UpdateLoad();
    case 3:
        return UpdateClear();
    }
    return 0x80;
}

u8 UnkClass_02027FE8::UpdateWrite(BOOL clear)
{
    u8 result = 0;
    u32 limit;

    switch (unk_54) {
    case 1:
        if (!unk_00->Init()) {
            SetState(13, 1);
            break;
        }
        if (unk_5C + sizeof(SaveHeader) > MAIN_BSS_0210CA38) {
            SetState(13, 0);
            break;
        }
        if (!unk_00->Read(unk_60, &unk_38, sizeof(SaveHeader), NULL)) {
            SetState(13, 2);
            break;
        }
        SetState(2, 0);
    case 2:
        if (!unk_00->Wait(FALSE)) {
            break;
        }
        if (unk_00->unk_0C == 0) {
            if (IsMagicValid()) {
                if (CheckSum(&unk_38, 0x18, unk_38.checksum)) {
                    unk_38.offsets[0] = unk_60 + sizeof(SaveHeader);
                } else {
                    SetState(13, 3);
                }
                if (!clear) {
                    unk_38.slot = (unk_38.slot + 1) % GetCopies(unk_66);
                }
            } else {
                for (int i = 0; i < 8; i++) {
                    unk_38.magic[i] = sSaveMagic[i];
                }
                u32 copies = GetCopies(unk_66);
                for (u32 i = 0; i < copies; i++) {
                    unk_38.offsets[i] = -2;
                    unk_38.sums[i] = 0;
                }
                unk_38.slot = 0;
                unk_38.unk_0E = 0;
                unk_38.unk_12 = 0;
            }
            limit = MAIN_BSS_0210CA38;
            if (unk_5C + GetSlotOffset(unk_38.slot) > limit) {
                SetState(13, 0);
                break;
            }
            if (clear) {
                SetState(7, 0);
                break;
            }
            SetState(3, 0);
            break;
        }
        SetState(13, 3);
        break;
    case 3:
        CopyToBuffer(clear);
        if (!unk_00->Write(GetSlotOffset(unk_38.slot), unk_58, unk_5C, NULL)) {
            SetState(13, 4);
            break;
        }
        SetState(4, 0);
    case 4:
        if (!unk_00->Wait(FALSE)) {
            break;
        }
        if (unk_00->unk_0C == 0) {
            SetState(7, 0);
            break;
        }
        SetState(13, 5);
        break;
    case 7:
        if (clear) {
            unk_38.sums[unk_38.slot] = 0;
            unk_38.offsets[unk_38.slot] = -2;
            int n = GetCopies(unk_66);
            if (n < 1) {
                n = 1;
            }
            int i;
            for (i = 0; i < n; i++) {
                if (unk_38.offsets[i] != -2) {
                    break;
                }
            }
            if (i >= n) {
                MI_CpuFill8(&unk_38, 0, sizeof(SaveHeader));
            } else {
                unk_38.slot = (unk_38.slot + (n - 1)) % n;
                unk_38.checksum = Checksum(&unk_38, 0x18);
            }
        } else {
            unk_38.offsets[unk_38.slot] = GetSlotOffset(unk_38.slot);
            unk_38.sums[unk_38.slot] = Checksum(unk_58, unk_5C);
            unk_38.checksum = Checksum(&unk_38, 0x18);
        }
        if (!unk_00->Write(unk_60, &unk_38, sizeof(SaveHeader), NULL)) {
            SetState(13, 6);
            break;
        }
        SetState(9, 0);
    case 9:
        if (!unk_00->Wait(FALSE)) {
            break;
        }
        if (unk_00->unk_0C == 0) {
            SetState(11, 0);
            break;
        }
        SetState(13, 7);
        break;
    case 11:
        unk_00->Finalize();
        CPowerManage::sub_0200FA0C(0);
        result = 1;
        break;
    case 13:
        unk_00->Finalize();
        CPowerManage::sub_0200FA0C(0);
        result = unk_64 | 0x80;
        break;
    default:
        result = 0x80;
        CPowerManage::sub_0200FA0C(0);
        break;
    }

    return result;
}

u8 UnkClass_02027FE8::UpdateLoad()
{
    u8 result = 0;

    switch (unk_54) {
    case 14:
        if (!unk_00->Init()) {
            SetState(21, 1);
            break;
        }
        if (unk_60 + sizeof(SaveHeader) + unk_5C * 2 > MAIN_BSS_0210CA38) {
            SetState(13, 0);
            break;
        }
        if (!unk_00->Read(unk_60, &unk_38, sizeof(SaveHeader), NULL)) {
            SetState(21, 2);
            break;
        }
        SetState(15, 0);
    case 15:
        if (!unk_00->Wait(FALSE)) {
            break;
        }
        if (unk_00->unk_0C == 0) {
            if (IsMagicValid()) {
                if (CheckSum(&unk_38, 0x18, unk_38.checksum)) {
                    if (unk_6C) {
                        unk_6C = FALSE;
                        SetState(20, 0);
                        break;
                    }
                    SetState(16, 0);
                    break;
                }
                SetState(21, 3);
                break;
            }
            SetState(21, 10);
            break;
        }
        SetState(21, 3);
        break;
    case 16:
        if (unk_70) {
            unk_38.slot = (unk_38.slot + (GetCopies(unk_66) - 1)) % GetCopies(unk_66);
            unk_70 = FALSE;
        }
        if (!unk_00->Read(unk_38.offsets[unk_38.slot], unk_58, unk_5C, NULL)) {
            SetState(21, 8);
            break;
        }
        SetState(17, 0);
    case 17:
        if (!unk_00->Wait(FALSE)) {
            break;
        }
        if (unk_00->unk_0C == 0) {
            if (CheckSum(unk_58, unk_5C, unk_38.sums[unk_38.slot])) {
                CopyFromBuffer();
                SetState(20, 0);
                break;
            }
            SetState(21, 11);
            break;
        }
        SetState(21, 9);
        break;
    case 20:
        unk_00->Finalize();
        result = 1;
        CPowerManage::sub_0200FA0C(0);
        break;
    case 21:
        unk_00->Finalize();
        result = unk_64 | 0x80;
        CPowerManage::sub_0200FA0C(0);
        break;
    default:
        result = 0x80;
        CPowerManage::sub_0200FA0C(0);
        break;
    }

    return result;
}

u8 UnkClass_02027FE8::UpdateClear()
{
    return UpdateWrite(TRUE);
}

void UnkClass_02027FE8::CopyToBuffer(BOOL clear)
{
    SaveBlock *block = unk_68;
    u8 *dst = unk_58;
    while (block->data != NULL) {
        if (clear) {
            MI_CpuFill8(dst, 0, block->size);
        } else {
            MI_CpuCopy8(block->data, dst, block->size);
        }
        dst += block->size;
        block++;
    }
}

void UnkClass_02027FE8::CopyFromBuffer()
{
    SaveBlock *block = unk_68;
    u8 *src = unk_58;
    while (block->data != NULL) {
        MI_CpuCopy8(src, block->data, block->size);
        src += block->size;
        block++;
    }
}

BOOL UnkClass_02027FE8::IsMagicValid()
{
    for (int i = 0; i < 8; i++) {
        if (unk_38.magic[i] != sSaveMagic[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

u16 UnkClass_02027FE8::Checksum(const void *data, int len)
{
    u16 sum = 0;
    const u8 *p = (const u8 *)data;
    for (int i = 0; i < len; i++) {
        sum += *p++;
    }
    return sum;
}

BOOL UnkClass_02027FE8::CheckSum(const void *data, int len, u16 sum)
{
    return Checksum(data, len) == sum;
}

u8 UnkClass_02027FE8::UpdateWriteSteps()
{
    u8 result = 0;
    u32 limit;

    switch (unk_54) {
    case 1:
        if (!unk_00->Init()) {
            SetState(13, 1);
        } else if (unk_5C + sizeof(SaveHeader) > MAIN_BSS_0210CA38) {
            SetState(13, 0);
        } else if (!unk_00->Read(unk_60, &unk_38, sizeof(SaveHeader), NULL)) {
            SetState(13, 2);
        } else {
            SetState(2, 0);
        }
        break;
    case 2:
        if (unk_00->Wait(FALSE)) {
            if (unk_00->unk_0C == 0) {
                if (IsMagicValid()) {
                    if (CheckSum(&unk_38, 0x18, unk_38.checksum)) {
                        unk_38.offsets[0] = unk_60 + sizeof(SaveHeader);
                    } else {
                        SetState(13, 3);
                    }
                    unk_38.slot = (unk_38.slot + 1) % GetCopies(unk_66);
                } else {
                    for (int i = 0; i < 8; i++) {
                        unk_38.magic[i] = sSaveMagic[i];
                    }
                    u32 copies = GetCopies(unk_66);
                    for (u32 i = 0; i < copies; i++) {
                        unk_38.offsets[i] = -2;
                        unk_38.sums[i] = 0;
                    }
                    unk_38.slot = 0;
                    unk_38.unk_0E = 0;
                    unk_38.unk_12 = 0;
                }
                limit = MAIN_BSS_0210CA38;
                if (unk_5C + GetSlotOffset(unk_38.slot) > limit) {
                    SetState(13, 0);
                } else {
                    SetState(3, 0);
                }
            } else {
                SetState(13, 3);
            }
        }
        break;
    case 3:
        CopyToBuffer(FALSE);
        if (!unk_00->Write(GetSlotOffset(unk_38.slot), unk_58, unk_5C, NULL)) {
            SetState(13, 4);
            break;
        }
        SetState(4, 0);
    case 4:
        if (unk_00->Wait(FALSE)) {
            if (unk_00->unk_0C == 0) {
                SetState(7, 0);
            } else {
                SetState(13, 5);
            }
        }
        break;
    case 7:
        unk_38.offsets[unk_38.slot] = GetSlotOffset(unk_38.slot);
        unk_38.sums[unk_38.slot] = Checksum(unk_58, unk_5C);
        unk_38.checksum = Checksum(&unk_38, 0x18);
        SetState(10, 0);
        result = 2;
        break;
    case 8:
        if (!unk_00->Write(unk_60, &unk_38, sizeof(SaveHeader), NULL)) {
            SetState(13, 6);
            break;
        }
        SetState(9, 0);
    case 9:
        if (unk_00->Wait(FALSE)) {
            if (unk_00->unk_0C == 0) {
                SetState(11, 0);
            } else {
                SetState(13, 7);
            }
        }
        break;
    case 10:
        result = 2;
        break;
    case 11:
        unk_00->Finalize();
        CPowerManage::sub_0200FA0C(0);
        SetState(12, 0);
        result = 1;
        break;
    case 12:
        result = 1;
        break;
    case 13:
        unk_00->Finalize();
        CPowerManage::sub_0200FA0C(0);
        result = unk_64 | 0x80;
        break;
    default:
        result = 0x80;
        CPowerManage::sub_0200FA0C(0);
        break;
    }

    return result;
}

BOOL UnkClass_02027FE8::sub_020292CC(u16 list)
{
    SelectList(list);
    switch (unk_54) {
    case 0:
    case 11:
    case 13:
    case 20:
    case 21:
    case 24:
    case 25:
        unk_65 = 1;
        unk_64 = 0;
        SetState(1, 0);
        CPowerManage::sub_0200FA2C(0);
        if (list == 0) {
            sub_02016E7C(&MAIN_BSS_020B26A0, 1);
        }
        return TRUE;
    }
    return FALSE;
}

BOOL UnkClass_02027FE8::FinishWriteSteps()
{
    if (unk_54 != 10) {
        return FALSE;
    }
    SetState(8, 0);
    return TRUE;
}

// Not referenced (mwld strips it); it places sEmptyBlocks among the TU's data
SaveBlock *GetEmptyBlocks()
{
    return sEmptyBlocks;
}
