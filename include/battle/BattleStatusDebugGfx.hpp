#ifndef POKERANGER2_BATTLE_BATTLESTATUSDEBUGGFX_HPP
#define POKERANGER2_BATTLE_BATTLESTATUSDEBUGGFX_HPP

#include <nitro.h>

#include "common.hpp"

class VramImage;
class VramPalette;
class CNCERFile;

// Defined in ov1
class BattleStatusDebugGfx {
public:
    BattleStatusDebugGfx();
    ~BattleStatusDebugGfx();
    void ov1_021294E4();
    void ov1_02129638();

public:
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(BattleStatusDebugGfx, 0x14);

#endif // POKERANGER2_BATTLE_BATTLESTATUSDEBUGGFX_HPP
