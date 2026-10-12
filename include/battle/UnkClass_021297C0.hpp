#ifndef POKERANGER2_BATTLE_UNKCLASS_021297C0_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021297C0_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_020074D4;
class UnkClass_02007AA4;
class CNCERFile;

// Defined in ov1
class UnkClass_021297C0 {
public:
    UnkClass_021297C0();
    ~UnkClass_021297C0();
    void ov1_021297E8();
    void ov1_0212993C();

public:
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_021297C0, 0x14);

#endif // POKERANGER2_BATTLE_UNKCLASS_021297C0_HPP
