#include "UnkClass_02010854.hpp"

UnkClass_02010854::UnkClass_02010854()
{
    sub_02010868(this);
}

extern "C" {

void sub_02010868(UnkClass_02010854 *obj)
{
    obj->unk_00 = 0x22;
    obj->unk_04 = 10;
    obj->unk_05 = 1;
    obj->unk_06 = FALSE;
    obj->unk_08 = 0;
    obj->unk_0C = 0;
    obj->unk_10 = 0;
    obj->unk_14 = 0;
    int i;
    for (i = 0; i < 8; i++) {
        obj->unk_16[i] = 0xFF;
        obj->unk_26[i] = 0;
    }
    obj->unk_40 = 0;
    for (i = 0; i < 8; i++) {
        obj->unk_41[i] = 0xFF;
    }
    obj->unk_2E = 0;
    for (i = 0; i < 4; i++) {
        obj->unk_30[i] = 0xFFFF;
        obj->unk_38[i] = 0;
        obj->unk_3C[i] = 0;
    }
    obj->unk_49 = 0;
    obj->unk_4A = 0;
    obj->unk_4B = 0;
    obj->unk_4C = 0;
    obj->unk_4D = 0;
    obj->unk_4E = 0;
    obj->unk_4F = TRUE;
    obj->unk_50 = TRUE;
    obj->unk_51 = FALSE;
    obj->unk_52 = 0;
    obj->unk_54 = 0;
    obj->unk_56 = 0;
    obj->unk_58 = 0;
}

void sub_0201094C(UnkClass_02010854 *obj, u32 arg1)
{
    obj->unk_00 = arg1;
}

void sub_02010954(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_04 = arg1;
}

void sub_0201095C(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_05 = arg1;
}

void sub_02010964(UnkClass_02010854 *obj, BOOL arg1)
{
    obj->unk_06 = arg1 ? TRUE : FALSE;
}

void sub_02010978(UnkClass_02010854 *obj, u32 arg1)
{
    obj->unk_08 = arg1;
}

void sub_02010980(UnkClass_02010854 *obj, u32 arg1)
{
    obj->unk_0C = arg1;
}

void sub_02010988(UnkClass_02010854 *obj, u32 arg1)
{
    obj->unk_10 = arg1;
}

void sub_02010990(UnkClass_02010854 *obj, u16 arg1, u8 arg2)
{
    if (obj->unk_14 >= 8) {
        return;
    }
    obj->unk_16[obj->unk_14] = arg1;
    obj->unk_26[obj->unk_14] = arg2;
    obj->unk_14++;
}

void sub_020109C0(UnkClass_02010854 *obj, u16 arg1, u8 arg2)
{
    if (obj->unk_40 >= 8) {
        return;
    }
    u8 i;
    u8 idx = 0xFF;
    u8 count = obj->unk_2E;
    for (i = 0; i < count; i++) {
        if (obj->unk_30[i] == arg1 && obj->unk_38[i] == arg2) {
            idx = i;
            break;
        }
    }
    if (idx == 0xFF) {
        if (count >= 4) {
            return;
        }
        obj->unk_30[count] = arg1;
        obj->unk_38[count] = arg2;
        obj->unk_2E++;
        idx = count;
    }
    obj->unk_3C[idx]++;
    obj->unk_41[obj->unk_40] = idx;
    obj->unk_40++;
}

void sub_02010A70(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_49 = arg1;
    obj->unk_58 |= 1;
}

void sub_02010A84(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_4A = arg1;
    obj->unk_58 |= 2;
}

void sub_02010A98(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_4B = arg1;
}

void sub_02010AA0(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_4C = arg1;
}

void sub_02010AA8(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_4D = arg1;
}

void sub_02010AB0(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_4E = arg1;
    obj->unk_58 |= 4;
}

void sub_02010AC4(UnkClass_02010854 *obj, BOOL arg1)
{
    obj->unk_4F = arg1 ? TRUE : FALSE;
}

void sub_02010AD8(UnkClass_02010854 *obj, BOOL arg1)
{
    obj->unk_50 = arg1 ? TRUE : FALSE;
}

void sub_02010AEC(UnkClass_02010854 *obj, BOOL arg1)
{
    obj->unk_51 = arg1 ? TRUE : FALSE;
}

void sub_02010B00(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_52 = arg1;
}

void sub_02010B08(UnkClass_02010854 *obj, u8 arg1)
{
    obj->unk_54 = arg1;
}

void sub_02010B10(UnkClass_02010854 *obj, u16 arg1)
{
    obj->unk_56 = arg1;
    obj->unk_58 |= 8;
}

u32 sub_02010B24(UnkClass_02010854 *obj)
{
    return obj->unk_00;
}

u8 sub_02010B2C(UnkClass_02010854 *obj)
{
    return obj->unk_04;
}

u8 sub_02010B34(UnkClass_02010854 *obj)
{
    return obj->unk_05;
}

BOOL sub_02010B3C(UnkClass_02010854 *obj)
{
    return obj->unk_06 ? TRUE : FALSE;
}

u32 sub_02010B50(UnkClass_02010854 *obj)
{
    return obj->unk_08;
}

u32 sub_02010B58(UnkClass_02010854 *obj)
{
    return obj->unk_0C;
}

u32 sub_02010B60(UnkClass_02010854 *obj)
{
    return obj->unk_10;
}

u8 sub_02010B68(UnkClass_02010854 *obj)
{
    return obj->unk_2E;
}

u16 sub_02010B70(UnkClass_02010854 *obj, int idx)
{
    return obj->unk_30[idx];
}

u8 sub_02010B7C(UnkClass_02010854 *obj)
{
    return obj->unk_40;
}

u8 sub_02010B84(UnkClass_02010854 *obj, int idx)
{
    return obj->unk_41[idx];
}

u8 sub_02010B90(UnkClass_02010854 *obj)
{
    return obj->unk_14;
}

u16 sub_02010B98(UnkClass_02010854 *obj, int idx)
{
    return obj->unk_16[idx];
}

u8 sub_02010BA4(UnkClass_02010854 *obj, int idx)
{
    return obj->unk_26[idx];
}

u8 sub_02010BB0(UnkClass_02010854 *obj)
{
    return obj->unk_49;
}

u8 sub_02010BB8(UnkClass_02010854 *obj)
{
    return obj->unk_4A;
}

u8 sub_02010BC0(UnkClass_02010854 *obj)
{
    return obj->unk_4B;
}

u8 sub_02010BC8(UnkClass_02010854 *obj)
{
    return obj->unk_4C;
}

u8 sub_02010BD0(UnkClass_02010854 *obj)
{
    return obj->unk_4D;
}

u8 sub_02010BD8(UnkClass_02010854 *obj)
{
    return obj->unk_4E;
}

BOOL sub_02010BE0(UnkClass_02010854 *obj)
{
    return obj->unk_4F ? TRUE : FALSE;
}

BOOL sub_02010BF4(UnkClass_02010854 *obj)
{
    return obj->unk_50 ? TRUE : FALSE;
}

BOOL sub_02010C08(UnkClass_02010854 *obj)
{
    return obj->unk_51 ? TRUE : FALSE;
}

u8 sub_02010C1C(UnkClass_02010854 *obj)
{
    return obj->unk_52;
}

u8 sub_02010C24(UnkClass_02010854 *obj)
{
    return obj->unk_58;
}

u8 sub_02010C2C(UnkClass_02010854 *obj)
{
    return obj->unk_54;
}

u16 sub_02010C34(UnkClass_02010854 *obj)
{
    return obj->unk_56;
}
}
