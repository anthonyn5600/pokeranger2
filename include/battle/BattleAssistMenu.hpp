#ifndef POKERANGER2_BATTLE_BATTLEASSISTMENU_HPP
#define POKERANGER2_BATTLE_BATTLEASSISTMENU_HPP

#include <nitro.h>

#include "ActorMotion.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CTouchPanel;
class Camera2D;
class CellAnimController;
class OamSprite;
class OamSpriteSet;
class GraphicsSet;
class GridOverlay;
class BattlePokemonTable;
class BattleInfoPanel;

// Defined in ov1
class BattleAssistMenu {
public:
    BattleAssistMenu(void *table, BattlePokemonTable *params, BattleInfoPanel *info, GridOverlay *window);
    ~BattleAssistMenu();
    void ov1_0213B27C();
    void ov1_0213B454();
    void ov1_0213B528(CTouchPanel *touch);
    void ov1_0213B6B0();
    void ov1_0213B6D0();
    void ov1_0213B7C0(CTouchPanel *touch);
    void ov1_0213BC04();
    void ov1_0213BCEC();
    void ov1_0213BD0C();
    void ov1_0213BDC0();
    void ov1_0213BE30();
    void ov1_0213BEE0();
    void ov1_0213BF20();
    void ov1_0213BFFC(Camera2D *camera);
    void ov1_0213C090(Camera2D *camera);
    void ov1_0213C0F8(Camera2D *camera);
    void ov1_0213C1A8(Camera2D *camera, u8 index);
    void ov1_0213C1D8(Camera2D *camera);
    void ov1_0213C264(Camera2D *camera);
    void ov1_0213C2A0(Camera2D *camera);
    void ov1_0213C2BC(int count, OamSpriteSet **sprites, u16 *ids, u8 mask, BOOL partner);
    int ov1_0213C5F4();
    u8 ov1_0213C5FC();
    int ov1_0213C604();
    void ov1_0213C60C();
    int ov1_0213C67C(int z);
    void ov1_0213C838(u8 index, fx32 x, fx32 y);
    void ov1_0213C8E8(u8 index);
    void ov1_0213C9B8(u8 index);
    void ov1_0213CA78(int type);
    void ov1_0213CAC8();
    void ov1_0213CBD8(int alpha);

    inline BOOL IsActive()
    {
        return m_state != 0;
    }

public:
    u32 m_timer;
    u32 m_state;
    BOOL m_selected;
    u8 m_index;
    u8 m_count;
    u8 m_mask;
    u8 m_partner;
    int m_result;
    BOOL m_cancel;
    u8 m_fadeDir;
    u8 m_fade;
    GXRgb m_palette[16];
    u16 *m_ids;
    OamSpriteSet **m_sources;
    OamSprite *m_icons[8];
    OamSprite *m_outlines[8][4];
    u8 unk_0E4[0x8];
    u32 m_dispcnt;
    void *m_table;
    BattlePokemonTable *m_params;
    BattleInfoPanel *m_info;
    ActorMotion m_motions[8];
    CSoftwareSprite m_slots[8];
    CSoftwareSprite m_sprite67C;
    CSoftwareSprite m_sprite6C8;
    CSoftwareSprite m_sprite714;
    CSoftwareSprite m_sprite760;
    CSoftwareSprite m_sprite7AC;
    CSoftwareSprite m_bubbles[3][6];
    CellAnimController *m_anim;
    u16 m_animIds[8];
    CPrimitiveRECT m_rects[8];
    CPrimitiveRECT m_okRect;
    CPrimitiveRECT m_cancelRect;
    GraphicsSet *m_resSlots;
    GraphicsSet *m_res060;
    GraphicsSet *m_res061;
    GraphicsSet *m_res063;
    GraphicsSet *m_res064;
    GridOverlay *m_window;
};

STATIC_SIZE_ASSERT(BattleAssistMenu, 0xFFC);

#endif // POKERANGER2_BATTLE_BATTLEASSISTMENU_HPP
