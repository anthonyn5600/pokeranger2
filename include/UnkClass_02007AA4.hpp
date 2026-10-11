#ifndef POKERANGER2_UNKCLASS_02007AA4_HPP
#define POKERANGER2_UNKCLASS_02007AA4_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "file/CNCLRFile.hpp"

// Palette loaded into palette VRAM (arm9_02007AA4.s).
class UnkClass_02007AA4 {
public:
    UnkClass_02007AA4();
    UnkClass_02007AA4(const char *path, u32 arg1, u32 arg2);
    UnkClass_02007AA4(NNSG2dPaletteData *data);
    ~UnkClass_02007AA4();

    void sub_02007B3C();
    void sub_02007B60(const char *path, u32 arg1, u32 arg2);
    void sub_02007BAC(NNSG2dPaletteData *data);
    void sub_02007BC4();
    void sub_02007BFC(u32 addr);
    void sub_02007C34(u32 addr);

    static void sub_02007C64(void *data);

public:
    CNCLRFile *unk_00;
    NNSG2dPaletteData *unk_04;
    NNSG2dImagePaletteProxy unk_08;
    u32 unk_1C;
    u8 unk_20;
};

STATIC_SIZE_ASSERT(UnkClass_02007AA4, 0x24);

#endif // POKERANGER2_UNKCLASS_02007AA4_HPP
