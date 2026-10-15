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
    void Load();
    void Release();

public:
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(BattleStatusDebugGfx, 0x14);

#endif // POKERANGER2_BATTLE_BATTLESTATUSDEBUGGFX_HPP
