#ifndef POKERANGER2_BATTLE_BATTLEESCAPEBUTTON_HPP
#define POKERANGER2_BATTLE_BATTLEESCAPEBUTTON_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;
class CPrimitiveRECT;
class CSoftwareSprite;
class GraphicsSet;

// Defined in ov1
// Battle icon i047 (BES archive), animated for 16 frames after Start
class BattleEscapeButton {
public:
    BattleEscapeButton();
    ~BattleEscapeButton(); // ov1_021382E4
    void Init();
    void Release();
    void Update();
    void Render(Camera2D *camera);
    void Press();
    int SetZ(int z);

public:
    u8 m_flags;
    u8 m_frame;
    CPrimitiveRECT *m_rect;
    CSoftwareSprite *m_sprite;
    GraphicsSet *m_res;
};

STATIC_SIZE_ASSERT(BattleEscapeButton, 0x10);

#endif // POKERANGER2_BATTLE_BATTLEESCAPEBUTTON_HPP
