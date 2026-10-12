#ifndef POKERANGER2_BATTLE_UNKCLASS_021294BC_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021294BC_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_020074D4;
class UnkClass_02007AA4;
class CNCERFile;

// Defined in ov1
class UnkClass_021294BC {
public:
    UnkClass_021294BC();
    ~UnkClass_021294BC();
    void ov1_021294E4();
    void ov1_02129638();

public:
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_021294BC, 0x14);

#endif // POKERANGER2_BATTLE_UNKCLASS_021294BC_HPP
