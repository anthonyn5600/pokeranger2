#ifndef POKERANGER2_UNKCLASS_02029800_HPP
#define POKERANGER2_UNKCLASS_02029800_HPP

#include <nitro.h>

#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "common.hpp"

// Title / mission banner sprites shown by the field scene (type < 100: mission "mitNNN", < 200: title101, else
// title100).
class UnkClass_02029800 {
public:
    UnkClass_02029800();
    ~UnkClass_02029800();

    void sub_0202982C(int type);
    void sub_02029884();
    void sub_02029A34();
    void sub_02029B70();
    void sub_02029D4C();
    void sub_02029D7C();
    void sub_02029F34();
    void sub_02029F74();
    void sub_0202A0A4();
    void sub_0202A0D4();
    void sub_0202A150();
    void sub_0202A184();
    int sub_0202A1AC();
    void sub_0202A1B4();

public:
    UnkClass_0200ECD0 *unk_00;
    UnkClass_0200ECD0 *unk_04;
    UnkClass_0200ECD0 *unk_08;
    UnkClass_0200E960 *unk_0C;
    UnkClass_0200E960 *unk_10;
    UnkClass_0200E960 *unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
};

STATIC_SIZE_ASSERT(UnkClass_02029800, 0x2C);

#endif // POKERANGER2_UNKCLASS_02029800_HPP
