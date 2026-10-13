#ifndef POKERANGER2_BATTLE_UNKCLASS_0213F028_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0213F028_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02006000.hpp"

class Camera2D;
class UnkClass_02008788;
class UnkClass_0201AAE0;

// Defined in ov1
// Capture result banner (slides in, flashes, then shrinks away)
class UnkClass_0213F028 {
public:
    UnkClass_0213F028(u16 type);
    ~UnkClass_0213F028();
    void ov1_0213F0C8(u16 type);
    void ov1_0213F2B4();
    void ov1_0213F338();
    void ov1_0213F3D4();
    void ov1_0213F41C();
    void ov1_0213F490();
    void ov1_0213F504();
    void ov1_0213F578();
    void ov1_0213F5A0();
    void ov1_0213F608();
    void ov1_0213F688();
    void ov1_0213F6D0();
    void ov1_0213F794();
    void ov1_0213F7E4();
    void ov1_0213F82C(Camera2D *camera);
    void ov1_0213F8B4();
    void ov1_0213F960(int state);
    int ov1_0213F970(int z);

    inline BOOL IsActive()
    {
        return m_state != 0;
    }

    inline void SetPos(Point2D pos)
    {
        m_pos = pos;
    }

public:
    u16 m_frame;
    u16 m_type;
    int m_state;
    Point2D m_pos;
    u8 unk_10[0x4];
    CSoftwareSprite m_banner;
    UnkClass_0201AAE0 *m_bannerRes;
    CSoftwareSprite m_flash;
    CSoftwareSprite m_flash2;
    UnkClass_0201AAE0 *m_flashRes;
    CSoftwareSprite m_ring;
    UnkClass_0201AAE0 *m_ringRes;
    UnkClass_02008788 *m_anim;
    u16 m_animId;
};

STATIC_SIZE_ASSERT(UnkClass_0213F028, 0x158);

#endif // POKERANGER2_BATTLE_UNKCLASS_0213F028_HPP
