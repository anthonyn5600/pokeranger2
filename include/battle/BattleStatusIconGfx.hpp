#ifndef POKERANGER2_BATTLE_BATTLESTATUSICONGFX_HPP
#define POKERANGER2_BATTLE_BATTLESTATUSICONGFX_HPP

#include <nitro.h>

#include "common.hpp"

class VramImage;
class VramPalette;
class CNCERFile;
class CellAnimController;

// Defined in ov1
class BattleStatusIconGfx {
public:
    BattleStatusIconGfx();
    ~BattleStatusIconGfx();
    void ov1_02128EB0();
    void ov1_021290D4();

    inline VramImage *GetImage(u8 idx)
    {
        return m_image[idx];
    }
    inline VramPalette *GetPalette(u8 idx)
    {
        return m_palette[idx];
    }
    inline CNCERFile *GetCells(u8 idx)
    {
        return m_cells[idx];
    }
    inline CellAnimController *GetAnim(u8 idx)
    {
        return m_anim[idx];
    }

public:
    // Index 0 is unused
    VramImage *m_image[5];
    VramPalette *m_palette[5];
    CNCERFile *m_cells[5];
    CellAnimController *m_anim[5];
    NNSGfdTexKey m_texKey[5];
    NNSGfdPlttKey m_plttKey[5];
};

STATIC_SIZE_ASSERT(BattleStatusIconGfx, 0x78);

#endif // POKERANGER2_BATTLE_BATTLESTATUSICONGFX_HPP
