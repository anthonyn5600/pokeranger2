#include <nitro.h>

#include "SaveDataBuffer.hpp"

UnkStruct_0210C228 MAIN_BSS_0210C228;

void sub_0202A4D8(UnkStruct_0210C228 *obj)
{
    MI_CpuFill8(obj, 0, sizeof(obj->unk_000));
    if (obj->unk_804 != NULL) {
        obj->unk_804->BuildData(obj, sizeof(obj->unk_000));
    }
}
