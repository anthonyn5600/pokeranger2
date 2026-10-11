#include "UnkClass_02008788.hpp"

#include <nitro.h>

#include "file/CBinaryFile.hpp"
#include "heap.hpp"

UnkClass_02008788::UnkClass_02008788()
{
    sub_02008C74();
}

UnkClass_02008788::UnkClass_02008788(const char *path)
{
    sub_02008C74();
    sub_0200887C(path, 0, 0);
}

UnkClass_02008788::~UnkClass_02008788()
{
    if (unk_08 != 0) {
        sub_02008BF0();
    }
    if (unk_04 != NULL) {
        Heap_Free(unk_04);
        unk_04 = NULL;
    }
    SAFE_DELETE(unk_0C);
}

u16 UnkClass_02008788::sub_02008828(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        return anim->sub_02008014();
    }
    return 0;
}

fx32 *UnkClass_02008788::sub_02008844(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        return anim->sub_02008024();
    }
    return NULL;
}

int UnkClass_02008788::sub_02008860(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        return anim->sub_0200802C();
    }
    return 2;
}

BOOL UnkClass_02008788::sub_0200887C(const char *path, u32 heapId, u32 arg2)
{
    if (unk_04 != NULL) {
        return TRUE;
    }
    CBinaryFile *file = new CBinaryFile(path, arg2 == 0 ? 1 : 0, 0, heapId, NULL, 0);
    AnimFileHeader *data = (AnimFileHeader *)file->unk_4C;
    unk_00 = data->size >> 2;
    unk_02 = data->count;
    unk_03 = data->loop;
    unk_04 = (AnimCmd *)Heap_AllocWithAlignment(unk_00 * 4 * data->count, arg2 == 0 ? 4 : -4);
    MI_CpuCopy32(data->cmds, unk_04, unk_00 * 4 * data->count);
    if (file != NULL) {
        delete file;
    }
    return FALSE;
}

BOOL UnkClass_02008788::sub_02008968(u16 id, u16 dir)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        anim->sub_02008104(dir);
        return FALSE;
    }
    return TRUE;
}

BOOL UnkClass_02008788::sub_02008990(u16 id, u16 index)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        anim->sub_020081E4(index);
        return FALSE;
    }
    return TRUE;
}

void UnkClass_02008788::sub_020089B8(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        anim->sub_02008170();
    }
}

u8 UnkClass_02008788::sub_020089D0(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        return anim->sub_02008780();
    }
    return 0;
}

void UnkClass_02008788::sub_020089EC()
{
    UnkClass_02007F98 *anim = unk_0C->sub_02008724();
    while (anim != unk_0C && sub_02008C6C() != 0) {
        anim->sub_020086B4();
        anim = anim->sub_02008724();
    }
}

BOOL UnkClass_02008788::sub_02008A38(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        anim->sub_020086B4();
        return FALSE;
    }
    return TRUE;
}

BOOL UnkClass_02008788::sub_02008A58(u16 id, fx32 speed)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim != NULL) {
        anim->sub_0200805C(speed);
        return FALSE;
    }
    return TRUE;
}

u16 UnkClass_02008788::sub_02008A80(u32 arg0, u32 arg1)
{
    if (unk_04 == NULL) {
        return 0;
    }
    unk_0A++;
    unk_08++;
    UnkClass_02007F98 *anim = new UnkClass_02007F98(arg0, arg1);
    anim->sub_02008734(unk_04, unk_00, unk_02, unk_03);
    anim->sub_02008778(unk_0A);
    UnkClass_02007F98 *last = unk_0C->sub_0200871C();
    if (last == unk_0C) {
        unk_0C->sub_0200870C(anim);
        unk_0C->sub_02008714(anim);
        anim->sub_0200870C(unk_0C);
        anim->sub_02008714(unk_0C);
    } else {
        last->sub_02008714(anim);
        anim->sub_0200870C(last);
        anim->sub_02008714(unk_0C);
        unk_0C->sub_0200870C(anim);
    }
    return unk_0A;
}

BOOL UnkClass_02008788::sub_02008B80(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim == NULL) {
        return TRUE;
    }
    UnkClass_02007F98 *prev = anim->sub_0200871C();
    UnkClass_02007F98 *next = anim->sub_02008724();
    prev->sub_02008714(next);
    next->sub_0200870C(prev);
    delete anim;
    unk_08--;
    return FALSE;
}

BOOL UnkClass_02008788::sub_02008BF0()
{
    UnkClass_02007F98 *anim = unk_0C->sub_02008724();
    while (anim != unk_0C) {
        UnkClass_02007F98 *next = anim->sub_02008724();
        delete anim;
        anim = next;
    }
    unk_08 = 0;
    unk_0C->sub_0200870C(unk_0C);
    unk_0C->sub_02008714(unk_0C);
    return FALSE;
}

u8 UnkClass_02008788::sub_02008C6C()
{
    return unk_08;
}

void UnkClass_02008788::sub_02008C74()
{
    unk_00 = 0;
    unk_02 = 0;
    unk_03 = 0;
    unk_04 = NULL;
    unk_08 = 0;
    unk_0A = 0;
    unk_0C = new UnkClass_02007F98(0, 0);
    unk_0C->sub_0200870C(unk_0C);
    unk_0C->sub_02008714(unk_0C);
}

UnkClass_02007F98 *UnkClass_02008788::sub_02008CD0(u16 id)
{
    UnkClass_02007F98 *anim = unk_0C->sub_02008724();
    while (TRUE) {
        if (anim == unk_0C) {
            return NULL;
        }
        if (id == anim->sub_0200872C()) {
            break;
        }
        anim = anim->sub_02008724();
    }
    return anim;
}

u16 UnkClass_02008788::sub_02008D20(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim == NULL) {
        return 0;
    } else {
        return anim->unk_0E;
    }
}

u8 UnkClass_02008788::sub_02008D38(u16 id)
{
    UnkClass_02007F98 *anim = sub_02008CD0(id);
    if (anim == NULL) {
        return 0;
    } else {
        return anim->unk_10;
    }
}
