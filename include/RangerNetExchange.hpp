#ifndef POKERANGER2_RANGERNETEXCHANGE_HPP
#define POKERANGER2_RANGERNETEXCHANGE_HPP

#include "RangerNetSendBin.hpp"
#include "common.hpp"

class RangerNetMenu;

// Defined in ov11, owned by RangerNetMenu::unk_71C: Ranger-to-Ranger exchange over RangerNetWireless
class RangerNetExchange {
public:
    void ov11_0212D978();
    RangerNetExchange(RangerNetMenu *menu);
    ~RangerNetExchange();
    int ov11_0212DA48();
    void ov11_0212DC84();
    void ov11_0212E128();
    void ov11_0212E518();
    void ov11_0212E9B4(int state); // SetState: unk_151 = unk_150, unk_150 = state
    void ov11_0212E9D8();
    void ov11_0212E9E8();
    void ov11_0212EA38();
    int ov11_0212EBA4(const u16 *str);
    void ov11_0212EBCC();
    void ov11_0212EE24();
    void ov11_0212EF94();
    void ov11_0212F158();
    void ov11_0212F3B0();

public:
    u8 unk_000[0x48];
    int unk_048;
    u8 *unk_04C;
    u8 *unk_050;
    u8 unk_054[0x8];
    u8 *unk_05C;
    UnkClass_0212CE58_000 *unk_060;
    UnkClass_0212CE58_000 *unk_064;
    int unk_068;
    u8 unk_06C;
    u8 unk_06D[0xD7];
    u16 unk_144;
    u16 unk_146;
    u8 unk_148[0x8];
    u8 unk_150;
    u8 unk_151;
    u8 unk_152;
    u8 unk_153;
    int unk_154;
    u8 unk_158[0x4];
    int unk_15C[11];
    int unk_188;
    u8 unk_18C[0x8];
    RangerNetMenu *unk_194;
};

STATIC_SIZE_ASSERT(RangerNetExchange, 0x198);

#endif // POKERANGER2_RANGERNETEXCHANGE_HPP
