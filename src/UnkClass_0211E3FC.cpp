#include "UnkClass_0211E3FC.hpp"

#include <nitro.h>

BOOL UnkClass_0211E3FC::sub_0200912C(CDrawObject *obj)
{
    if (obj != NULL) {
        CDrawObject *prev = NULL;
        CDrawObject *cur = unk_00;
        while (cur != NULL) {
            if (obj->unk_04 > cur->unk_04) {
                break;
            }
            prev = cur;
            cur = cur->unk_08;
        }
        if (prev == NULL) {
            unk_00 = obj;
        } else {
            prev->unk_08 = obj;
        }
        obj->unk_08 = cur;
        return TRUE;
    }
    return FALSE;
}

int UnkClass_0211E3FC::sub_02009188(Camera2D *camera, int budget)
{
    int total = 0;
    for (CDrawObject *obj = unk_00; obj != NULL; obj = obj->unk_08) {
        total += obj->sub_020091D4(camera, budget - total);
    }
    return total;
}

void UnkClass_0211E3FC::sub_020091DC()
{
    unk_00 = NULL;
}
