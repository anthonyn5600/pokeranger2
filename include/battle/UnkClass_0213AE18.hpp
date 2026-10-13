#ifndef POKERANGER2_BATTLE_UNKCLASS_0213AE18_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0213AE18_HPP

#include <nitro.h>

#include "UnkClass_0201179C.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CTouchPanel;
class Camera2D;
class UnkClass_02008788;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_0201AAE0;
class UnkClass_0201AD60;
class UnkClass_0212DC20;
class UnkClass_0213CC28;

// Defined in ov1
class UnkClass_0213AE18 {
public:
    UnkClass_0213AE18(void *table, UnkClass_0212DC20 *params, UnkClass_0213CC28 *info, UnkClass_0201AD60 *window);
    ~UnkClass_0213AE18();
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
    void ov1_0213C2BC(int count, UnkClass_0200ECD0 **sprites, u16 *ids, u8 mask, BOOL partner);
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
    UnkClass_0200ECD0 **m_sources;
    UnkClass_0200E960 *m_icons[8];
    UnkClass_0200E960 *m_outlines[8][4];
    u8 unk_0E4[0x8];
    u32 m_dispcnt;
    void *m_table;
    UnkClass_0212DC20 *m_params;
    UnkClass_0213CC28 *m_info;
    UnkClass_0201179C m_motions[8];
    CSoftwareSprite m_slots[8];
    CSoftwareSprite m_sprite67C;
    CSoftwareSprite m_sprite6C8;
    CSoftwareSprite m_sprite714;
    CSoftwareSprite m_sprite760;
    CSoftwareSprite m_sprite7AC;
    CSoftwareSprite m_bubbles[3][6];
    UnkClass_02008788 *m_anim;
    u16 m_animIds[8];
    CPrimitiveRECT m_rects[8];
    CPrimitiveRECT m_okRect;
    CPrimitiveRECT m_cancelRect;
    UnkClass_0201AAE0 *m_resSlots;
    UnkClass_0201AAE0 *m_res060;
    UnkClass_0201AAE0 *m_res061;
    UnkClass_0201AAE0 *m_res063;
    UnkClass_0201AAE0 *m_res064;
    UnkClass_0201AD60 *m_window;
};

STATIC_SIZE_ASSERT(UnkClass_0213AE18, 0xFFC);

#endif // POKERANGER2_BATTLE_UNKCLASS_0213AE18_HPP
