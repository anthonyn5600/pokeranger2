#ifndef POKERANGER2_UNKCLASS_0201164C_HPP
#define POKERANGER2_UNKCLASS_0201164C_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_020091E8;
class UnkClass_02033F04;

// Mission/quest progress; global MAIN_BSS_020B2638 (CGame::m_missionQuestData)
class UnkClass_0201164C {
public:
    UnkClass_0201164C();
    ~UnkClass_0201164C();

public:
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
    s32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u8 unk_14[0x3E]; // low nibble: state, 0x10: flag
    UnkClass_020091E8 *unk_54;
    UnkClass_02033F04 *unk_58;
};

STATIC_SIZE_ASSERT(UnkClass_0201164C, 0x5C);

extern UnkClass_0201164C MAIN_BSS_020B2638;

extern "C" {
void sub_0201135C(UnkClass_0201164C *obj);
BOOL sub_020114F8(UnkClass_0201164C *obj, int arg1);
BOOL sub_02011528(UnkClass_0201164C *obj, int arg1);
void sub_020116C0(UnkClass_0201164C *obj, int arg1);
BOOL sub_02011630(UnkClass_0201164C *obj, int arg1);
}

#endif // POKERANGER2_UNKCLASS_0201164C_HPP
