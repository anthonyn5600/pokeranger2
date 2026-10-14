#ifndef POKERANGER2_BATTLE_BATTLEENEMYGAUGEGFX_HPP
#define POKERANGER2_BATTLE_BATTLEENEMYGAUGEGFX_HPP

#include <nitro.h>

#include "common.hpp"

class CNCERFile;
class VramImage;
class VramPalette;
class GraphicsSet;

// Defined in ov1
class BattleEnemyGaugeGfx {
public:
    BattleEnemyGaugeGfx();
    ~BattleEnemyGaugeGfx();
    void ov1_021364D4();
    void ov1_02136678();

public:
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    GraphicsSet *m_digits;
};

STATIC_SIZE_ASSERT(BattleEnemyGaugeGfx, 0x18);

#endif // POKERANGER2_BATTLE_BATTLEENEMYGAUGEGFX_HPP
