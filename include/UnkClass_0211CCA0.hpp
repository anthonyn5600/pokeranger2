#ifndef POKERANGER2_UNKCLASS_0211CCA0_HPP
#define POKERANGER2_UNKCLASS_0211CCA0_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201CA6C.hpp"
#include "UnkClass_02021404.hpp"
#include "UnkClass_0202A510.hpp"
#include "UnkClass_02041C80.hpp"
#include "common.hpp"

// Fly destination (ov9 table)
struct UnkStruct_0211DCAC {
    u16 mapId;
    s16 x;
    s16 y;
    u16 unk_06;
    u16 unk_08;
    u8 unk_0A;
    u8 placeId;
    u16 unk_0C;
    u16 messageId;
};

STATIC_SIZE_ASSERT(UnkStruct_0211DCAC, 0x10);

// Defined in ov9: fly destination map (CFlyingScene)
class UnkClass_0211CCA0 {
public:
    UnkClass_0211CCA0(CGame *game);
    ~UnkClass_0211CCA0();

    void ov9_0211CCCC();
    void ov9_0211CD40();
    void ov9_0211CE80();
    void ov9_0211CEF0();
    void ov9_0211CF14();
    void ov9_0211CF48();
    void ov9_0211D0A0();
    void ov9_0211D0CC();
    BOOL ov9_0211D484();
    BOOL ov9_0211D49C();
    void ov9_0211D4D4();
    void ov9_0211D568();
    void ov9_0211D66C();
    void ov9_0211D680(u16 id);
    void ov9_0211D690();
    BOOL ov9_0211D754();
    void ov9_0211D790();
    void ov9_0211D7FC();
    void ov9_0211D84C();
    void ov9_0211D878(u16 id);
    u16 ov9_0211D89C(u8 placeId);
    void ov9_0211D8F8(u16 placeId);
    void ov9_0211D980(u16 id, int mode);
    void ov9_0211D9F0();
    void ov9_0211DA34();
    BOOL ov9_0211DA78();
    int ov9_0211DAC0();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    int unk_08; // frame counter
    u32 unk_0C;
    int unk_10; // flew
    UnkClass_0202A510 *unk_14;
    UnkClass_0201CA6C *unk_18;
    UnkClass_02041C80 *unk_1C;
    UnkClass_02021404 *unk_20;
    UnkClass_0200ECD0 *unk_24;
    u32 unk_28;
    u32 unk_2C;
    UnkClass_0200ECD0 *unk_30;
    u8 *unk_34;
    u32 unk_38;
    UnkClass_0200E960 *unk_3C[2];
    int unk_44;
    u16 unk_48;
    u16 unk_4A;
    u32 unk_4C;
    int unk_50;
    CGame *unk_54;
};

STATIC_SIZE_ASSERT(UnkClass_0211CCA0, 0x58);

#endif // POKERANGER2_UNKCLASS_0211CCA0_HPP
