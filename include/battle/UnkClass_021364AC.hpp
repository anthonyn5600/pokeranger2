#ifndef POKERANGER2_BATTLE_UNKCLASS_021364AC_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021364AC_HPP

#include <nitro.h>

#include "common.hpp"

class CNCERFile;
class UnkClass_020074D4;
class UnkClass_02007AA4;
class UnkClass_0201AAE0;

// Defined in ov1
class UnkClass_021364AC {
public:
    UnkClass_021364AC();
    ~UnkClass_021364AC();
    void ov1_021364D4();
    void ov1_02136678();

public:
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    UnkClass_0201AAE0 *m_digits;
};

STATIC_SIZE_ASSERT(UnkClass_021364AC, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_021364AC_HPP
