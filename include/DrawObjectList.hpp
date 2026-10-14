#ifndef POKERANGER2_DRAWOBJECTLIST_HPP
#define POKERANGER2_DRAWOBJECTLIST_HPP

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

    virtual int Draw(Camera2D *camera, int budget)
    {
        return 0;
    }

public:
    int unk_04;
    CDrawObject *unk_08;
};

class DrawObjectList {
public:
    DrawObjectList()
    {
        Clear();
    }

    ~DrawObjectList()
    {
    }

    BOOL Insert(CDrawObject *obj);
    int Draw(Camera2D *camera, int budget);
    void Clear();

public:
    CDrawObject *unk_00;
};

STATIC_SIZE_ASSERT(DrawObjectList, 0x4);

#endif // POKERANGER2_DRAWOBJECTLIST_HPP
