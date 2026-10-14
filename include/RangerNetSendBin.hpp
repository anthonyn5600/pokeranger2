#ifndef POKERANGER2_RANGERNETSENDBIN_HPP
#define POKERANGER2_RANGERNETSENDBIN_HPP

#include "common.hpp"

class CGame;
class RangerNetMenu;

// Defined in ov11
// 0x30-byte block owned by RangerNetExchange::unk_060/064 (no ctor): a RangerNetWireless name pair
struct UnkClass_0212CE58_000 {
    u16 name[12];
    u16 id[12];
};

struct D3Info;

// Work block of RangerNetSendBin (0x1E24, heap)
struct UnkClass_0212CE58Work {
    u8 unk_0000[0x4];
    u8 unk_0004[0x1AB8];
    int unk_1ABC;
    int unk_1AC0;
    int unk_1AC4;
    u8 unk_1AC8[0x358];
    u8 unk_1E20[0x4];
};

// Defined in ov11, owned by RangerNetMenu::unk_720: sends data/sendbin/sendbin*.bin (RC4) over the comm layer
class RangerNetSendBin {
public:
    RangerNetSendBin(CGame *game, RangerNetMenu *menu);
    ~RangerNetSendBin();
    u8 *ov11_0212CEE8(const char *path);
    void ov11_0212CFD4();
    void ov11_0212D018(int v);
    BOOL ov11_0212D030();
    BOOL ov11_0212D854(UnkClass_0212CE58Work *work, int index);
    int ov11_0212D880(UnkClass_0212CE58Work *work);
    void ov11_0212D8A0(u8 *data, u8 *out);

public:
    UnkClass_0212CE58Work *unk_0;
    u8 unk_004[0x3A8];
    int unk_3AC;
    int unk_3B0;
    RangerNetMenu *unk_3B4;
    D3Info *unk_3B8;
    u32 unk_3BC;
    u32 unk_3C0;
    u32 unk_3C4;
    u32 unk_3C8;
    u32 unk_3CC;
    u32 unk_3D0;
    u8 unk_3D4[0x4];
    RangerNetMenu *unk_3D8;
    u16 *unk_3DC;
    u16 *unk_3E0;
    u16 *unk_3E4;
    CGame *unk_3E8;
};

STATIC_SIZE_ASSERT(RangerNetSendBin, 0x3EC);

#endif // POKERANGER2_RANGERNETSENDBIN_HPP
