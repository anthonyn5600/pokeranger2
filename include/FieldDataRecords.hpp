#ifndef POKERANGER2_FIELDDATARECORDS_HPP
#define POKERANGER2_FIELDDATARECORDS_HPP

#include <nitro.h>

#include "FieldData.hpp"
#include "common.hpp"

struct FieldMapData {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07;
    s16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
    s16 unk_0C;
    u8 unk_0E;
    u8 unk_0F;
    s16 unk_10;
    u8 unk_12;
    u8 unk_13;
    s16 unk_14;
    u8 unk_16;
    u8 unk_17;
    s16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    s16 unk_1C;
    u8 unk_1E;
    u8 unk_1F;
    s16 unk_20;
    u8 unk_22;
    u8 unk_23;
    s16 unk_24;
    u8 unk_26;
    u8 unk_27;
    s16 unk_28;
    u8 unk_2A;
    u8 unk_2B;
    s16 unk_2C;
    u8 unk_2E;
    u8 unk_2F;
    s16 unk_30;
    u8 unk_32;
    u8 unk_33;
    s16 unk_34;
    u8 unk_36;
    u8 unk_37;
    s16 unk_38;
    u8 unk_3A;
    u8 unk_3B;
    s16 unk_3C;
    u8 unk_3E;
    u8 unk_3F;
    s16 unk_40;
    u8 unk_42;
    u8 unk_43;
    s16 unk_44;
    u8 unk_46;
    u8 unk_47;
    s16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u8 unk_4E[0x2];
    int unk_50;
};

// Target record (0x20 bytes, FieldData_GetTargetObject)
struct FieldTargetObjectData {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u16 unk_06;
    u8 unk_08;
    s8 unk_09;
    s8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    s8 unk_0F;
    s8 unk_10;
    u8 unk_11;
    u8 unk_12;
    s8 unk_13;
    s8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u8 unk_1E[0x2];
};

extern "C" {
FieldTargetObjectData *FieldData_GetTargetObject(FieldData *obj, int kind);
FieldMapData *FieldData_GetMap(FieldData *obj, u32 mapId);
}

STATIC_SIZE_ASSERT(FieldTargetObjectData, 0x20);
STATIC_SIZE_ASSERT(FieldMapData, 0x54);

#endif // POKERANGER2_FIELDDATARECORDS_HPP
