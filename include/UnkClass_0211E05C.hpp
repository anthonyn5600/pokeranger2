#ifndef POKERANGER2_UNKCLASS_0211E05C_HPP
#define POKERANGER2_UNKCLASS_0211E05C_HPP

#include <nnsys/fnd.h>

#include "UnkClass_02124578.hpp"
#include "common.hpp"

class CGame;
class UnkClass_0200ECD0;
class UnkClass_0200E960;
class UnkClass_0201100C;
class UnkClass_0201FC80;
class UnkClass_02021404;
class UnkClass_02027FE8;
class UnkClass_0211CD68;
class UnkClass_0212CE58;
class UnkClass_0212D97C;
class UnkClass_0212F3DC;
class UnkClass_021302D8;
class UnkClass_021304DC;

// Defined in ov11: Ranger Net menu, created by CRangerNetScene
// Ranger Net menu (region C), new'd by CRangerNetScene (size 0x730)
class UnkClass_0211E05C {
public:
    UnkClass_0211E05C(CGame *game, int arg);
    ~UnkClass_0211E05C();
    void ov11_0211E0E8();
    void ov11_0211E1DC(); // thunk to ov11_0211E1E8
    void ov11_0211E2EC();
    void ov11_0211EF5C();
    void ov11_0211EFB4();
    void ov11_0211EFC4();
    void ov11_0211F008(int i);
    void ov11_0211F0BC();
    void ov11_0211F96C();
    int ov11_021201A8();
    int ov11_021201F8();
    int ov11_02120294(int id);
    void ov11_02121000(int v);
    void ov11_02121288();
    void ov11_02123F58();
    void ov11_02123BD4();
    int ov11_02124094();
    void ov11_02124150(int i);
    void ov11_021241A0();
    void ov11_02124318();
    void ov11_02124370(BOOL visible);
    int ov11_02123C8C(const char *name);
    BOOL ov11_02123CEC(void *mem);
    void ov11_0211E464();
    void ov11_02121C20();
    BOOL ov11_02121F18();
    BOOL ov11_02122428();
    int ov11_0212247C();
    void ov11_02122B7C(int a, int b, int c, int d);
    void ov11_02122BD4(int a);
    void ov11_02122BF8(int i, int v);
    void ov11_02122C08(int i, int v);
    void ov11_02122C48();
    void ov11_021202E4();
    void ov11_021204B0();
    void ov11_02120A80();
    void ov11_02120AE8();
    void ov11_02120C1C();
    void ov11_02120DA8();
    void ov11_02120EBC();
    void ov11_02121168();
    void ov11_02121214();
    void ov11_02121A08();
    void ov11_02121A7C();
    BOOL ov11_02123FB0(); // IsFading
    void ov11_02124038(int state, int arg);
    void ov11_0211E414();
    void ov11_0211E438();
    void ov11_0211F52C();
    void ov11_02121B38();
    void ov11_02121EEC();
    void ov11_02123228(int a, int x, int y, int d, int e);
    void ov11_0212331C(int a, int x, int y, int d, int e, int f, int g);
    void ov11_02123598(int a, int x, int y, int d, int e, int f);
    void ov11_02122C60();
    void ov11_02123B98();
    int ov11_02123FF8();

    u16 unk_000;
    u16 unk_002;
    u8 unk_004[0x4];
    UnkClass_02021404 *unk_008;
    UnkClass_0200ECD0 *unk_00C;
    UnkClass_0200ECD0 *unk_010;
    UnkClass_0200E960 **unk_014;
    u8 unk_018[0x4];
    void *unk_01C;
    void *unk_020;
    u8 unk_024[0x14];
    int unk_038;
    u8 unk_03C[0xC];
    UnkClass_0200ECD0 *unk_048[22];
    UnkClass_0200E960 *unk_0A0;
    UnkClass_0200E960 *unk_0A4;
    UnkClass_0200ECD0 *unk_0A8;
    UnkClass_0200ECD0 *unk_0AC;
    UnkClass_0200ECD0 *unk_0B0;
    UnkClass_0200ECD0 *unk_0B4;
    int unk_0B8;
    UnkClass_0200E960 *unk_0BC;
    UnkClass_0200E960 *unk_0C0;
    UnkClass_0200ECD0 *unk_0C4[3];
    UnkClass_0200E960 *unk_0D0;
    u8 unk_0D4[0x4];
    int unk_0D8;
    u8 unk_0DC[0xC];
    int unk_0E8;
    int unk_0EC;
    u8 unk_0F0[0x18];
    UnkClass_02124578 unk_108[4];
    int unk_328[4];
    u8 unk_338[0x170];
    int unk_4A8;
    int unk_4AC;
    u8 unk_4B0[0x84];
    UnkClass_02021404 *unk_534[8];
    int unk_554;
    u8 unk_558[0x28];
    int unk_580;
    UnkClass_0201FC80 *unk_584[3];
    u8 unk_590[0x10];
    int unk_5A0;
    int unk_5A4;
    int unk_5A8[10];
    int unk_5D0[10];
    u8 unk_5F8[0x28];
    UnkClass_0201100C *unk_620;
    u8 unk_624[0x14];
    int unk_638[3];
    int unk_644[3];
    u8 unk_650[0x8];
    NNSFndArchive unk_658;
    u8 unk_658_end[0x6F4 - 0x658 - sizeof(NNSFndArchive)];
    int unk_6F4;
    u8 unk_6F8[0x4];
    int unk_6FC;
    void *unk_700;
    u8 unk_704[0x4];
    UnkClass_0212F3DC *unk_708;
    u8 unk_70C[0x8];
    UnkClass_021304DC *unk_714;
    UnkClass_021302D8 *unk_718;
    UnkClass_0212D97C *unk_71C;
    UnkClass_0212CE58 *unk_720;
    UnkClass_0211CD68 *unk_724;
    UnkClass_02027FE8 *unk_728;
    CGame *unk_72C;
};

STATIC_SIZE_ASSERT(UnkClass_0211E05C, 0x730);

#endif // POKERANGER2_UNKCLASS_0211E05C_HPP
