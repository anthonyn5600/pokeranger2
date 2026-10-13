#ifndef POKERANGER2_SAVEDATABUFFER_HPP
#define POKERANGER2_SAVEDATABUFFER_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/IFieldEnemyDataBuilder.hpp"

class IDataBuilder {
public:
    virtual void BuildData(void *buf, int size) = 0;
};

// Buffers saved with the main save blocks (src/UnkClass_02027FE8.cpp); a builder fills them before saving.
// Each global lives in its own TU (src/sub_0202A4A0.cpp, src/sub_0202A4D8.cpp), whose static init runs the ctor.
struct UnkStruct_0210C1C0 {
    u8 unk_00[0x60];
    u8 unk_60;
    IDataBuilder *unk_64;

    UnkStruct_0210C1C0()
    {
        unk_64 = NULL;
        MI_CpuFill8(unk_00, 0, sizeof(unk_00));
    }
    u8 *GetData()
    {
        return unk_00;
    }
    u32 GetSize()
    {
        return sizeof(unk_00);
    }
};

STATIC_SIZE_ASSERT(UnkStruct_0210C1C0, 0x68);

struct UnkStruct_0210C228 {
    u8 unk_000[0x800];
    u8 unk_800;
    IFieldEnemyDataBuilder *unk_804;

    UnkStruct_0210C228()
    {
        unk_804 = NULL;
        MI_CpuFill8(unk_000, 0, sizeof(unk_000));
    }
    u8 *GetData()
    {
        return unk_000;
    }
    u32 GetSize()
    {
        return sizeof(unk_000);
    }
};

STATIC_SIZE_ASSERT(UnkStruct_0210C228, 0x808);

extern UnkStruct_0210C1C0 MAIN_BSS_0210C1C0;
extern UnkStruct_0210C228 MAIN_BSS_0210C228;

extern "C" {
void sub_0202A4A0(UnkStruct_0210C1C0 *obj);
void sub_0202A4D8(UnkStruct_0210C228 *obj);
}

#endif // POKERANGER2_SAVEDATABUFFER_HPP
