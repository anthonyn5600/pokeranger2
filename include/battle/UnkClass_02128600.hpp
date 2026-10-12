#ifndef POKERANGER2_BATTLE_UNKCLASS_02128600_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128600_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_020074D4;
class UnkClass_02007AA4;
class CNCERFile;
class UnkClass_02008788;

// Defined in ov1
class UnkClass_02128600 {
public:
    UnkClass_02128600();
    ~UnkClass_02128600();
    void ov1_02128628();
    void ov1_021287A8();

public:
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    CNCERFile *m_cells;
    UnkClass_02008788 *m_anim;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_02128600, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128600_HPP
