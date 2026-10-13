#ifndef POKERANGER2_UNKCLASS_0215994C_HPP
#define POKERANGER2_UNKCLASS_0215994C_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0
class UnkClass_0215994C {
public:
    UnkClass_0215994C();
    ~UnkClass_0215994C();

public:
    u8 unk_00[0x2C];
};

STATIC_SIZE_ASSERT(UnkClass_0215994C, 0x2C);

// Entry of UnkClass_0215994C's table (ov0_02159DFC)
struct UnkStruct_02159DFC {
    u8 unk_00[0x20];
    u8 unk_20;
};

extern "C" {
void ov0_02159970(UnkClass_0215994C *obj);
int ov0_02159B84(UnkClass_0215994C *obj, int arg1, int arg2, int arg3);
UnkStruct_02159DFC *ov0_02159DFC(UnkClass_0215994C *obj, int index);
void ov0_0215A384(UnkStruct_02159DFC *obj, int arg1);
void ov0_0215A3BC(UnkStruct_02159DFC *obj, int arg1, int arg2);
void ov0_0215A3D4(UnkStruct_02159DFC *obj, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8);
}

#endif // POKERANGER2_UNKCLASS_0215994C_HPP
