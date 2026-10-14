#ifndef POKERANGER2_UNKCLASS_0212208C_HPP
#define POKERANGER2_UNKCLASS_0212208C_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_02021404.hpp"
#include "UnkClass_0202A510.hpp"
#include "UnkClass_021226C0.hpp"
#include "common.hpp"

// Defined in ov21
class UnkClass_0212208C {
public:
    UnkClass_0212208C(CGame *game);
    ~UnkClass_0212208C();

    void ov21_021220B8();
    void ov21_02122114();
    void ov21_0212212C();
    void ov21_02122144();
    void ov21_02122168();
    void ov21_02122180();
    void ov21_02122214();
    void ov21_02122368();
    void ov21_021223FC();
    void ov21_021224B4(const UnkStruct_02123618 *entry);
    void ov21_021224E4(const UnkStruct_02123618 *entry);
    BOOL ov21_02122534();
    void ov21_021225F8(u16 id);
    void ov21_02122608();
    void ov21_021226AC();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    UnkClass_0202A510 *unk_08;
    u32 unk_0C;
    UnkClass_02021404 *unk_10;
    UnkStruct_02123618 unk_14;
    u32 unk_20;
    int unk_24[6];
    UnkClass_0201FC80 *unk_3C;
    int unk_40; // display needs update
    u16 unk_44;
    CGame *unk_48;
};

STATIC_SIZE_ASSERT(UnkClass_0212208C, 0x4C);

#endif // POKERANGER2_UNKCLASS_0212208C_HPP
