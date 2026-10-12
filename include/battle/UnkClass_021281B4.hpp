#ifndef POKERANGER2_BATTLE_UNKCLASS_021281B4_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021281B4_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_020074D4;
class UnkClass_02007AA4;
class CNCERFile;
class UnkClass_02008788;

// Defined in ov1
class UnkClass_021281B4 {
public:
    UnkClass_021281B4();
    ~UnkClass_021281B4();
    void ov1_021281DC();
    void ov1_0212835C();

public:
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    CNCERFile *m_cells;
    UnkClass_02008788 *m_anim;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_021281B4, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_021281B4_HPP
