#include "UnkClass_0201164C.hpp"

#include "UnkClass_020091E8.hpp"

extern "C" {
void sub_02034084(void *scriptManager);
void sub_02034120(void *scriptManager, int arg1);
void sub_020342C0(void *scriptManager);
}

UnkClass_0201164C MAIN_BSS_020B2638;

extern "C" {

void sub_0201135C(UnkClass_0201164C *obj)
{
    MI_CpuClear8(obj, 0x54);
}
}

UnkClass_0201164C::UnkClass_0201164C()
{
    sub_0201135C(this);
}

UnkClass_0201164C::~UnkClass_0201164C()
{
    unk_58 = NULL;
    unk_54 = NULL;
}

extern "C" {

void sub_02011394(UnkClass_0201164C *obj, UnkClass_02033F04 *scriptManager, UnkClass_020091E8 *textboxData)
{
    sub_0201135C(obj);
    obj->unk_58 = scriptManager;
    obj->unk_54 = textboxData;
}

void sub_020113B4(UnkClass_0201164C *obj, int arg1)
{
    if (arg1 == 0) {
        obj->unk_02 = arg1;
        return;
    }
    if (arg1 <= 0x4C) {
        if (obj->unk_00 != 0) {
            OS_Terminate();
        }
        if (arg1 < 0x32) {
            obj->unk_00 = 1;
        } else if (arg1 >= 0x46) {
            obj->unk_00 = 1;
        }
        obj->unk_02 = arg1;
    } else {
        OS_Terminate();
    }
}

void sub_0201140C(UnkClass_0201164C *obj)
{
    if (obj->unk_02 == 0) {
        return;
    }
    if (obj->unk_02 <= 0x4C) {
        if (obj->unk_02 < 0x32) {
            if (obj->unk_00 != 1) {
                OS_Terminate();
            }
            obj->unk_00 = 2;
        } else if (obj->unk_02 >= 0x46) {
            obj->unk_00 = 2;
        }
    } else {
        OS_Terminate();
    }
}

void sub_02011464(UnkClass_0201164C *obj)
{
    if (obj->unk_02 == 0) {
        return;
    }
    if (obj->unk_02 <= 0x4C) {
        if (obj->unk_02 < 0x32) {
            if (obj->unk_00 != 2) {
                OS_Terminate();
            }
            obj->unk_00 = 0;
            obj->unk_04 = obj->unk_02;
        } else if (obj->unk_02 >= 0x46) {
            obj->unk_00 = 0;
        }
    } else {
        OS_Terminate();
    }
}

void sub_020114C4(UnkClass_0201164C *obj, int arg1)
{
    if ((obj->unk_14[arg1] & 0xF) == 2) {
        OS_Terminate();
    }
    obj->unk_14[arg1] = (obj->unk_14[arg1] & ~0xF) | 1;
}

BOOL sub_020114F8(UnkClass_0201164C *obj, int arg1)
{
    return (obj->unk_14[arg1] & 0xF) == 1;
}

void sub_02011514(UnkClass_0201164C *obj, int arg1)
{
    obj->unk_14[arg1] |= 0x10;
}

BOOL sub_02011528(UnkClass_0201164C *obj, int arg1)
{
    return (obj->unk_14[arg1] & 0x10) ? TRUE : FALSE;
}

void sub_02011540(UnkClass_0201164C *obj, int arg1)
{
    if (obj->unk_01 != 0) {
        OS_Terminate();
    }
    if ((obj->unk_14[arg1] & 0xF) == 2) {
        OS_Terminate();
    }
    obj->unk_01 = 1;
    obj->unk_03 = arg1;
    sub_02011514(obj, arg1);
    sub_02034120(obj->unk_58, arg1);
    obj->unk_54->sub_0200B21C(arg1);
}

void sub_020115A8(UnkClass_0201164C *obj)
{
    if (obj->unk_01 != 1) {
        OS_Terminate();
    }
    obj->unk_01 = 0;
    obj->unk_14[obj->unk_03] = (obj->unk_14[obj->unk_03] & ~0xF) | 2;
    obj->unk_03 = 0;
    sub_020342C0(obj->unk_58);
    obj->unk_54->sub_0200B36C();
}

void sub_020115F8(UnkClass_0201164C *obj)
{
    if (obj->unk_01 != 1) {
        OS_Terminate();
    }
    obj->unk_01 = 0;
    obj->unk_03 = 0;
    sub_020342C0(obj->unk_58);
    obj->unk_54->sub_0200B36C();
}

BOOL sub_02011630(UnkClass_0201164C *obj, int arg1)
{
    return (obj->unk_14[arg1] & 0xF) == 2;
}

void sub_0201164C(UnkClass_0201164C *obj, int arg1)
{
    if (arg1 > 0x4C) {
        return;
    }
    obj->unk_08 = arg1;
    sub_02034084(obj->unk_58);
    obj->unk_54->sub_0200AFC0(obj->unk_08);
}

int sub_02011678(UnkClass_0201164C *obj)
{
    int count = 0;
    for (int i = 0; i < 0x3E; i++) {
        if ((obj->unk_14[i] & 0xF) == 2) {
            count++;
        }
    }
    return count;
}

void sub_020116A8(UnkClass_0201164C *obj, int arg1)
{
    if (arg1 > 0x4C) {
        return;
    }
    obj->unk_54->sub_0200AFC0(arg1);
}

void sub_020116C0(UnkClass_0201164C *obj, int arg1)
{
    int i;
    if (arg1 > 0x45) {
        for (i = 0; i < 0x3E; i++) {
            obj->unk_14[i] &= ~0xF;
        }
        return;
    }
    if (arg1 == 0) {
        for (i = 0; i < 0x3E; i++) {
            obj->unk_14[i] &= ~0xF;
        }
        return;
    }
    const int table[0x3E] = {
        99,
        99,
        30,
        28,
        29,
        32,
        34,
        34,
        31,
        34,
        44,
        28,
        44,
        44,
        44,
        47,
        47,
        49,
        49,
        49,
        52,
        52,
        52,
        59,
        56,
        56,
        59,
        59,
        59,
        69,
        69,
        69,
        69,
        69,
        69,
        30,
        44,
        47,
        56,
        52,
        56,
        69,
        69,
        69,
        69,
        49,
        34,
        69,
        69,
        26,
        28,
        31,
        44,
        69,
        69,
        69,
        69,
        69,
        69,
        69,
        69,
        69,
    };
    for (i = 0; i < 0x3E; i++) {
        if (table[i] <= arg1 && (obj->unk_14[i] & 0xF) != 2) {
            obj->unk_14[i] = (obj->unk_14[i] & ~0xF) | 1;
        }
    }
}
}
