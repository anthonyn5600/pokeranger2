#include "DrawObjectList.hpp"

#include <nitro.h>

BOOL DrawObjectList::Insert(CDrawObject *obj)
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

int DrawObjectList::Draw(Camera2D *camera, int budget)
{
    int total = 0;
    for (CDrawObject *obj = unk_00; obj != NULL; obj = obj->unk_08) {
        total += obj->Draw(camera, budget - total);
    }
    return total;
}

void DrawObjectList::Clear()
{
    unk_00 = NULL;
}
