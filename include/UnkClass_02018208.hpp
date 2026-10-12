#ifndef POKERANGER2_UNKCLASS_02018208_HPP
#define POKERANGER2_UNKCLASS_02018208_HPP

#include <nitro.h>

#include "UnkClass_020091E8.hpp"
#include "common.hpp"

// Name tables of /data/message/etc (pokemon, item, yakumono, npc, fieldwaza); CGame::unk_14B0
class UnkClass_02018208 {
public:
    UnkClass_02018208();

    UnkClass_020091E8_004 *sub_02018250();
    void sub_02018374();
    UnkClass_020091E8_004 *sub_02018410();
    void sub_02018534();
    UnkClass_020091E8_004 *sub_020185D0();
    void sub_020186F4();
    UnkClass_020091E8_004 *sub_02018790();
    void sub_020188B4();
    UnkClass_020091E8_004 *sub_02018950();
    void sub_02018A74();

public:
    UnkClass_020091E8_004 *unk_00;
    UnkClass_020091E8_004 *unk_04;
    UnkClass_020091E8_004 *unk_08;
    UnkClass_020091E8_004 *unk_0C;
    UnkClass_020091E8_004 *unk_10;
};

STATIC_SIZE_ASSERT(UnkClass_02018208, 0x14);

#endif // POKERANGER2_UNKCLASS_02018208_HPP
