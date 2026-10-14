#ifndef POKERANGER2_UNKCLASS_02124578_HPP
#define POKERANGER2_UNKCLASS_02124578_HPP

#include "common.hpp"

class UnkClass_0200ECD0;
class UnkClass_0200E960;

// Defined in ov11
// 0x88-byte element of UnkClass_0211E05C::unk_108[4]
class UnkClass_02124578 {
public:
    UnkClass_02124578();
    ~UnkClass_02124578();
    void ov11_02124888();
    void ov11_021248CC();
    void ov11_02124680(int a, int b);
    void ov11_02124820(int id);
    void ov11_02124C28();
    void ov11_021249E0();
    void ov11_02124C64(int slot, int pos);
    void ov11_021247A8(int a);
    void ov11_0212494C(fx32 v);
    BOOL IsEmpty()
    {
        return unk_38 == 0 ? TRUE : FALSE;
    }
    void ov11_021245A8(UnkClass_0200ECD0 **res, int idx, int v);
    void ov11_02124604(UnkClass_0200ECD0 *res);
    void ov11_02124730(int type);
    void ov11_02124844(int x, int y);
    void ov11_02124968(fx32 a, fx32 b, fx32 c, fx32 d, int e, int f, int g);
    void ov11_02124A6C(int arg);
    void ov11_02124AD4();
    void ov11_02124B10(int arg);
    void ov11_02124B78();
    void ov11_02124BB0(int arg, int g);
    void ov11_021248EC(BOOL visible);
    BOOL ov11_02124ED0();
    void ov11_02124CBC();
    void ov11_02124E38();
    void ov11_02124EBC(BOOL active); // SetActive
    UnkClass_0200ECD0 **unk_00;
    UnkClass_0200ECD0 *unk_04;
    UnkClass_0200ECD0 *unk_08;
    UnkClass_0200E960 *unk_0C;
    UnkClass_0200E960 *unk_10;
    UnkClass_0200E960 *unk_14;
    UnkClass_0200E960 **unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    int unk_30;
    int unk_34;
    int unk_38;
    int unk_3C;
    int unk_40;
    int unk_44;
    int unk_48;
    int unk_4C;
    int unk_50;
    int unk_54;
    int unk_58;
    u8 unk_5C[0x4];
    fx32 unk_60;
    fx32 unk_64;
    fx32 unk_68;
    fx32 unk_6C;
    int unk_70;
    fx32 unk_74;
    int unk_78;
    int unk_7C;
    int unk_80;
    int unk_84;
};

STATIC_SIZE_ASSERT(UnkClass_02124578, 0x88);

#endif // POKERANGER2_UNKCLASS_02124578_HPP
