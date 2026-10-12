#ifndef POKERANGER2_UNKCLASS_02010D2C_HPP
#define POKERANGER2_UNKCLASS_02010D2C_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_02027FE8;

// Table loaded from data/param/DiskHP.bin; CGame::unk_1438
class UnkClass_02010D2C {
public:
    UnkClass_02010D2C(int arg0);

public:
    u8 m_count;
    u8 *unk_04;
    u16 *unk_08;
    u16 *unk_0C;
};

STATIC_SIZE_ASSERT(UnkClass_02010D2C, 0x10);

// MAIN_BSS_020AF5D0, MAIN_BSS_020AF5E4[3]
class UnkClass_02010EC8 {
public:
    UnkClass_02010EC8();
    ~UnkClass_02010EC8();

public:
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 unk_0A[0x6];
    UnkClass_02027FE8 *unk_10;
};

STATIC_SIZE_ASSERT(UnkClass_02010EC8, 0x14);

struct UnkStruct_0201100C {
    u32 unk_00;
    u8 unk_04[0x3000];
};

// MAIN_BSS_020AF620
class UnkClass_0201100C {
public:
    UnkClass_0201100C();
    ~UnkClass_0201100C();

public:
    UnkStruct_0201100C unk_00;
    u16 unk_3004;
    UnkClass_02027FE8 *unk_3008;
};

STATIC_SIZE_ASSERT(UnkClass_0201100C, 0x300C);

// MAIN_BSS_020AF598
class UnkClass_02011248 {
public:
    UnkClass_02011248();
    ~UnkClass_02011248();

public:
    u16 unk_00;
    UnkClass_02027FE8 *unk_04;
};

STATIC_SIZE_ASSERT(UnkClass_02011248, 0x8);

extern UnkClass_02010EC8 MAIN_BSS_020AF5D0;
extern UnkClass_02010EC8 MAIN_BSS_020AF5E4[3];
extern UnkClass_0201100C MAIN_BSS_020AF620;
extern UnkClass_02011248 MAIN_BSS_020AF598;

extern "C" {
u16 sub_02010E90(UnkClass_02010D2C *obj, u8 idx);
void sub_02010F18(UnkClass_02010EC8 *obj);
void sub_02010F5C(UnkClass_02010EC8 *obj, int bit);
void sub_0201128C(UnkClass_02011248 *obj);
void sub_020112DC(UnkClass_02011248 *obj, int bit);
}

#endif // POKERANGER2_UNKCLASS_02010D2C_HPP
