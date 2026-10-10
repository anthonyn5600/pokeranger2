#ifndef POKERANGER2_UNKCLASS_02022404_HPP
#define POKERANGER2_UNKCLASS_02022404_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;

class UnkClass_02022404 {
public:
    UnkClass_02022404(CGame *game);
    ~UnkClass_02022404();

public:
    u8 unk_00[0x60];
    int unk_60;
    u8 unk_64[0x8];
};

STATIC_SIZE_ASSERT(UnkClass_02022404, 0x6C);

extern "C" {
void sub_0202293C(UnkClass_02022404 *obj, u32 mapId, int x, int y);
void sub_02022C74(UnkClass_02022404 *obj);
}

#endif // POKERANGER2_UNKCLASS_02022404_HPP
