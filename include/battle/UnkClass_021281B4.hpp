#ifndef POKERANGER2_BATTLE_UNKCLASS_021281B4_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021281B4_HPP

#include <nitro.h>

#include "common.hpp"

class VramImage;
class VramPalette;
class CNCERFile;
class CellAnimController;

// Defined in ov1
class UnkClass_021281B4 {
public:
    UnkClass_021281B4();
    ~UnkClass_021281B4();
    void ov1_021281DC();
    void ov1_0212835C();

public:
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    CellAnimController *m_anim;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_021281B4, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_021281B4_HPP
