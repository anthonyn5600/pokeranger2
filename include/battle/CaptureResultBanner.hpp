#ifndef POKERANGER2_BATTLE_CAPTURERESULTBANNER_HPP
#define POKERANGER2_BATTLE_CAPTURERESULTBANNER_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"

class Camera2D;
class CellAnimController;
class GraphicsSet;

// Defined in ov1
// Capture result banner (slides in, flashes, then shrinks away)
class CaptureResultBanner {
public:
    CaptureResultBanner(u16 type);
    ~CaptureResultBanner();
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
    GraphicsSet *m_bannerRes;
    CSoftwareSprite m_flash;
    CSoftwareSprite m_flash2;
    GraphicsSet *m_flashRes;
    CSoftwareSprite m_ring;
    GraphicsSet *m_ringRes;
    CellAnimController *m_anim;
    u16 m_animId;
};

STATIC_SIZE_ASSERT(CaptureResultBanner, 0x158);

#endif // POKERANGER2_BATTLE_CAPTURERESULTBANNER_HPP
