#ifndef POKERANGER2_UNKCLASS_02124CDC_HPP
#define POKERANGER2_UNKCLASS_02124CDC_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0
class UnkClass_02124CDC {
public:
    UnkClass_02124CDC();
    ~UnkClass_02124CDC();

    inline void *Get(int i)
    {
        return i < unk_24 ? unk_30[i] : NULL;
    }

    inline void *GetLayer(int i)
    {
        return i < unk_24 ? unk_2C[i] : NULL;
    }

    inline void SetPolygonCount(int i, int count)
    {
        if (i < unk_24) {
            unk_34[i] = count;
        }
    }

public:
    u8 unk_00[0x24];
    int unk_24;
    u8 unk_28[0x4];
    void **unk_2C;
    void **unk_30;
    int *unk_34;
    u8 unk_38[0x4];
    int unk_3C;
    int unk_40;
    u8 unk_44[0x3C];
};

STATIC_SIZE_ASSERT(UnkClass_02124CDC, 0x80);

extern "C" {
int ov0_0212E1B4(void *obj, fx32 x, fx32 y);
}

#endif // POKERANGER2_UNKCLASS_02124CDC_HPP
