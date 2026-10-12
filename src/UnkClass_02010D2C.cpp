#include "UnkClass_02010D2C.hpp"

#include "UnkClass_0200D114.hpp"
#include "UnkClass_02027FE8.hpp"

UnkClass_02010EC8 MAIN_BSS_020AF5D0;
UnkClass_02010EC8 MAIN_BSS_020AF5E4[3];
UnkClass_0201100C MAIN_BSS_020AF620;
UnkClass_02011248 MAIN_BSS_020AF598;
// Never referenced (mwld strips it); with it in the TU mwcc's unstable size sort lays out the four destructor
// chain objects in .bss like the original (598, 620, 5D0, 5E4).
u32 g_unk_02010D2C_unused;

UnkClass_02010D2C::UnkClass_02010D2C(int arg0)
{
    UnkClass_0200D114 *table = new UnkClass_0200D114(arg0);
    table->sub_0200D148("data/param/DiskHP.bin");
    m_count = table->sub_0200D390();
    unk_04 = new u8[m_count];
    unk_08 = new u16[m_count];
    unk_0C = new u16[m_count];

    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        table->sub_0200D3B8(i, 1, &value);
        unk_04[i] = (u8)value;
        table->sub_0200D3B8(i, 2, &value);
        unk_08[i] = (u16)value;
        table->sub_0200D3B8(i, 3, &value);
        unk_0C[i] = (u16)value;
    }

    delete table;
}

extern "C" {

u8 sub_02010E60(UnkClass_02010D2C *obj)
{
    if (obj->m_count == 0) {
        return 0;
    }
    return obj->m_count - 1;
}

u8 sub_02010E78(UnkClass_02010D2C *obj, u8 idx)
{
    if (idx > obj->m_count) {
        return 0;
    }
    return obj->unk_04[idx];
}

u16 sub_02010E90(UnkClass_02010D2C *obj, u8 idx)
{
    if (idx > obj->m_count) {
        return 0;
    }
    return obj->unk_08[idx];
}

u16 sub_02010EAC(UnkClass_02010D2C *obj, u8 idx)
{
    if (idx > obj->m_count) {
        return 0;
    }
    return obj->unk_0C[idx];
}
}

UnkClass_02010EC8::UnkClass_02010EC8()
{
    unk_10 = NULL;
}

UnkClass_02010EC8::~UnkClass_02010EC8()
{
    SAFE_DELETE(unk_10);
}

extern "C" {

void sub_02010F0C(UnkClass_02010EC8 *obj)
{
    obj->unk_08 = 0;
}

void sub_02010F18(UnkClass_02010EC8 *obj)
{
    MI_CpuClear8(obj, 8);
    obj->unk_00 = 0xC68F;
    obj->unk_02 = 0;
    obj->unk_04 = 0;
    obj->unk_06 = 0xE97C;
    sub_02010F0C(obj);
}

void sub_02010F5C(UnkClass_02010EC8 *obj, int bit)
{
    obj->unk_02 |= (u16)(1 << bit);
}

BOOL sub_02010F78(UnkClass_02010EC8 *obj, UnkClass_02010EC8 *other)
{
    if (other != NULL) {
        obj = other;
    }
    return obj->unk_00 == 0xC68F && obj->unk_06 == 0xE97C;
}

void sub_02010FAC(UnkClass_02010EC8 *obj, int bit)
{
    obj->unk_04 |= (u16)(1 << bit);
}

int sub_02010FC8(UnkClass_02010EC8 *obj, int bit)
{
    u16 mask = 1 << bit;
    BOOL set = (obj->unk_02 & mask) ? TRUE : FALSE;
    if ((obj->unk_04 & mask) ? TRUE : FALSE) {
        return 2;
    }
    return set ? 1 : 0;
}
}

UnkClass_0201100C::UnkClass_0201100C()
{
    unk_3008 = NULL;
}

UnkClass_0201100C::~UnkClass_0201100C()
{
    SAFE_DELETE(unk_3008);
}

extern "C" {

void sub_020110E0(UnkClass_0201100C *obj, u32 arg1);
void sub_020110E8(UnkClass_0201100C *obj);

void sub_0201105C(UnkClass_0201100C *obj)
{
    sub_020110E0(obj, 0);
    MI_CpuClear8(&MAIN_BSS_020AF620.unk_00, sizeof(UnkStruct_0201100C));
    SAFE_DELETE(obj->unk_3008);
    obj->unk_3008 = new UnkClass_02027FE8(1);
    sub_020110E8(obj);
}

void sub_020110E0(UnkClass_0201100C *obj, u32 arg1)
{
    obj->unk_00.unk_00 = arg1;
}

void sub_020110E8(UnkClass_0201100C *obj)
{
    obj->unk_3004 = 0;
}

int sub_020110F8(UnkClass_0201100C *obj, u16 list)
{
    switch (obj->unk_3004) {
    case 0:
        obj->unk_3008->sub_02028220(list + 2);
        obj->unk_3004 = 1;
        break;
    case 1:
        u32 result = obj->unk_3008->sub_0202841C();
        if (result != 0) {
            if (!(result & 0x80)) {
                obj->unk_3004 = 3;
                return 1;
            }
            obj->unk_3004 = 4;
            return -1;
        }
        break;
    }
    return 0;
}

int sub_02011188(UnkClass_0201100C *obj, u16 list)
{
    switch (obj->unk_3004) {
    case 0:
        obj->unk_3008->sub_02028408(list + 2);
        obj->unk_3004 = 1;
        break;
    case 1:
        u32 result = obj->unk_3008->sub_0202841C();
        if (result != 0) {
            if (!(result & 0x80)) {
                sub_020110E8(obj);
                return 1;
            }
            sub_020110E8(obj);
            switch (result & 0x7F) {
            case 1:
            case 2:
            case 4:
            case 6:
            case 8:
                return -2;
            default:
                return -1;
            }
        }
        break;
    }
    return 0;
}
}

UnkClass_02011248::UnkClass_02011248()
{
    unk_04 = NULL;
}

UnkClass_02011248::~UnkClass_02011248()
{
    SAFE_DELETE(unk_04);
}

extern "C" {

void sub_020112DC(UnkClass_02011248 *obj, int bit);

void sub_0201128C(UnkClass_02011248 *obj)
{
    sub_020112DC(obj, -1);
    MI_CpuClear8(&MAIN_BSS_020AF598.unk_00, sizeof(u16));
    SAFE_DELETE(obj->unk_04);
}

void sub_020112DC(UnkClass_02011248 *obj, int bit)
{
    if (bit < 0) {
        MAIN_BSS_020AF598.unk_00 = 0;
        return;
    }
    MAIN_BSS_020AF598.unk_00 |= (u16)(1 << bit);
}

int sub_02011318(UnkClass_02011248 *obj, int bit)
{
    return (u16)(1 << bit) & MAIN_BSS_020AF598.unk_00;
}
}
