#ifndef POKERANGER2_BATTLE_UNKCLASS_021296C8_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021296C8_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_021294BC;
class CSoftwareSprite;

// Defined in ov1
class UnkClass_021296C8 {
public:
    UnkClass_021296C8(); // ov1_021296C8
    ~UnkClass_021296C8(); // ov1_02129750
    void ov1_02129784(UnkClass_021294BC *data);

public:
    u8 unk_00[0xC];
    UnkClass_021294BC *m_data;
    CSoftwareSprite *m_sprite;
};

STATIC_SIZE_ASSERT(UnkClass_021296C8, 0x14);

#endif // POKERANGER2_BATTLE_UNKCLASS_021296C8_HPP
