#ifndef POKERANGER2_UNKCLASS_0211CD68_HPP
#define POKERANGER2_UNKCLASS_0211CD68_HPP

#include "common.hpp"
#include "field/CFieldActor.hpp"

class CGame;
class Camera2D;
class UnkClass_0200ECD0;
class UnkClass_0200E960;
class UnkClass_02021404;
class UnkClass_02040F34;
class UnkClass_0211E05C;

// Defined in ov11: Ranger Net menu helper (mission list display), owned by UnkClass_0211E05C::unk_724
// helper owned by UnkClass_0211E05C::unk_724 (new'd with size 0x5F4)
class UnkClass_0211CD68 {
public:
    void ov11_0211CE20();
    void ov11_0211CF04(); // thunk to ov11_0211D02C
    void ov11_0211CF10(); // thunk to ov11_0211D8C4
    UnkClass_0211CD68(CGame *game, UnkClass_0211E05C *menu);
    ~UnkClass_0211CD68();
    void ov11_0211CDE8();
    void ov11_0211CF1C();
    void ov11_0211CF40();
    void ov11_0211D02C();
    void ov11_0211D0D0();
    void ov11_0211D4C0(int mode);
    BOOL ov11_0211D804(int idx);
    void ov11_0211D8C4();
    BOOL ov11_0211D7D4(int a, int b, UnkClass_02021404 *c);
    void ov11_0211D860(int mode);
    BOOL ov11_0211D864();
    void ov11_0211D880(int a, UnkClass_02021404 *b);
    void ov11_0211D8A0(int v);
    void ov11_0211DED0();

    u16 unk_000;
    int unk_004;
    Camera2D *unk_008;
    UnkClass_02040F34 *unk_00C;
    UnkClass_0200ECD0 *unk_010;
    u8 unk_014[0x4];
    UnkClass_0200ECD0 *unk_018;
    UnkClass_0200E960 *unk_01C[7];
    u8 unk_038[0x8];
    UnkClass_02021404 *unk_040[6];
    UnkClass_0211E05C *unk_058;
    u8 unk_05C[0x6];
    u16 unk_062;
    int unk_064;
    int unk_068;
    int unk_06C;
    UnkClass_02021404 *unk_070;
    int unk_074[10];
    int unk_09C;
    CFieldActor unk_0A0[6];
    int unk_5E0;
    int unk_5E4;
    int unk_5E8;
    int unk_5EC;
    CGame *unk_5F0;
};

STATIC_SIZE_ASSERT(UnkClass_0211CD68, 0x5F4);

#endif // POKERANGER2_UNKCLASS_0211CD68_HPP
