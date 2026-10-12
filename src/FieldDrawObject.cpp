#include <nitro.h>

#include "Camera2D.hpp"
#include "UnkClass_0211E3FC.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldDrawActor.hpp"

CFieldDrawObject::CFieldDrawObject()
{
    unk_0C = NULL;
    unk_10 = 0;
    unk_14 = 0;
}

CFieldDrawObject::~CFieldDrawObject()
{
    sub_02040638();
}

BOOL CFieldDrawObject::sub_02040530(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    SAFE_DELETE(unk_0C);
    unk_0C = new CFieldDrawActor();
    unk_0C->sub_0203DBB8(arg0, arg1, arg2, mask, arg4);
    return TRUE;
}

BOOL CFieldDrawObject::sub_020405B4(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    SAFE_DELETE(unk_0C);
    unk_0C = new CFieldDrawActor();
    unk_0C->sub_0203E10C(arg0, arg1, arg2, mask, arg4);
    return TRUE;
}

void CFieldDrawObject::sub_02040638()
{
    SAFE_DELETE(unk_0C);
}

int CFieldDrawObject::sub_020091D4(Camera2D *camera, int budget)
{
    unk_10 = budget;
    int used = 0;
    used += 4;
    if (unk_0C != NULL) {
        Rectangle rect = unk_0C->unk_1E4;
        rect.pos.x += GetX();
        rect.pos.y += GetY() - GetHeight();
        if (camera->sub_020038A8(&rect, 0x1199)) {
            used += unk_0C->sub_0203E934(camera, budget - used);
        }
    }
    unk_14 = budget - used;
    return used + 4;
}

void CFieldDrawObject::sub_02040740()
{
    if (unk_0C != NULL) {
        unk_0C->vfunc_08();
    }
    unk_04 = GetY();
}
