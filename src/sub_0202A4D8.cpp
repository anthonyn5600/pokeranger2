#include <nitro.h>

#include "SaveDataBuffer.hpp"

FieldEnemySaveBuffer MAIN_BSS_0210C228;

void FieldEnemySaveBuffer_Build(FieldEnemySaveBuffer *obj)
{
    MI_CpuFill8(obj, 0, sizeof(obj->unk_000));
    if (obj->unk_804 != NULL) {
        obj->unk_804->BuildData(obj, sizeof(obj->unk_000));
    }
}
