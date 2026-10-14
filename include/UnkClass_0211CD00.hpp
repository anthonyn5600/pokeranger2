#ifndef POKERANGER2_UNKCLASS_0211CD00_HPP
#define POKERANGER2_UNKCLASS_0211CD00_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_02021404.hpp"
#include "UnkClass_0202A510.hpp"
#include "UnkClass_02041C80.hpp"
#include "UnkClass_0211D770.hpp"
#include "common.hpp"

// Defined in ov8: mission/quest map on the sub screen (CMissionQuestScene)
class UnkClass_0211CD00 {
public:
    UnkClass_0211CD00(CGame *game);
    ~UnkClass_0211CD00();

    void ov8_0211CD2C();
    void ov8_0211CD8C();
    void ov8_0211CE08();
    void ov8_0211CE78();
    void ov8_0211CEAC();
    void ov8_0211CECC();
    void ov8_0211CFC4();
    void ov8_0211CFF0();
    BOOL ov8_0211D310();
    BOOL ov8_0211D328();
    void ov8_0211D358();
    void ov8_0211D444();
    void ov8_0211D478(u16 id);
    void ov8_0211D488();
    void ov8_0211D55C();
    void ov8_0211D5B8(int idx, u16 id);
    void ov8_0211D604();
    void ov8_0211D628();
    void ov8_0211D654(u16 id);
    void ov8_0211D678(u16 id, int mode);
    void ov8_0211D688();
    void ov8_0211D6CC();
    BOOL ov8_0211D710();
    int ov8_0211D758();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    UnkClass_0202A510 *unk_08;
    UnkClass_0211D770 *unk_0C;
    UnkClass_02041C80 *unk_10;
    UnkClass_02021404 *unk_14;
    UnkClass_0200ECD0 *unk_18;
    UnkClass_0200ECD0 *unk_1C;
    u32 unk_20;
    UnkClass_0200E960 *unk_24[6];
    u16 unk_3C;
    u16 unk_3E;
    CGame *unk_40;
};

STATIC_SIZE_ASSERT(UnkClass_0211CD00, 0x44);

#endif // POKERANGER2_UNKCLASS_0211CD00_HPP
