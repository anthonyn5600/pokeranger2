#ifndef POKERANGER2_UNKCLASS_0211E3FC_HPP
#define POKERANGER2_UNKCLASS_0211E3FC_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_02003718;

class CDrawObject {
public:
    virtual ~CDrawObject();
    virtual int sub_020091D4(UnkClass_02003718 *camera, int budget);

public:
    int unk_04;
    CDrawObject *unk_08;
};

class UnkClass_0211E3FC {
public:
    UnkClass_0211E3FC()
    {
        sub_020091DC();
    }

    ~UnkClass_0211E3FC()
    {
    }

    BOOL sub_0200912C(CDrawObject *obj);
    int sub_02009188(UnkClass_02003718 *camera, int budget);
    void sub_020091DC();

public:
    CDrawObject *unk_00;
};

STATIC_SIZE_ASSERT(UnkClass_0211E3FC, 0x4);

#endif // POKERANGER2_UNKCLASS_0211E3FC_HPP
