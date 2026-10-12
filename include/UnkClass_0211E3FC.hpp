#ifndef POKERANGER2_UNKCLASS_0211E3FC_HPP
#define POKERANGER2_UNKCLASS_0211E3FC_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;

class CDrawObject {
public:
    CDrawObject()
    {
        unk_04 = 0;
    }

    virtual ~CDrawObject()
    {
    }

    virtual int sub_020091D4(Camera2D *camera, int budget)
    {
        return 0;
    }

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
    int sub_02009188(Camera2D *camera, int budget);
    void sub_020091DC();

public:
    CDrawObject *unk_00;
};

STATIC_SIZE_ASSERT(UnkClass_0211E3FC, 0x4);

#endif // POKERANGER2_UNKCLASS_0211E3FC_HPP
