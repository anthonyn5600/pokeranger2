#ifndef POKERANGER2_BATTLE_UNKCLASS_021278E8_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021278E8_HPP

#include <nitro.h>

#include "common.hpp"

class VramImage;
class VramPalette;
class CNCERFile;
class CellAnimController;

// Defined in ov1
class UnkClass_021278E8 {
public:
    UnkClass_021278E8();
    ~UnkClass_021278E8();
    void Load();
    void Release();

public:
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    CellAnimController *m_anim;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_021278E8, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_021278E8_HPP
