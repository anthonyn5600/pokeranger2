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
    void Load(u16 type);
    void Release();
    void Update();
    void UpdateStart();
    void UpdateRingOpenX();
    void UpdateRingOpenY();
    void UpdateSlideIn();
    void UpdateWait();
    void UpdateBannerAnim();
    void UpdateFlash();
    void UpdateCloseTextbox();
    void UpdateSlideOut();
    void UpdateRingCloseY();
    void UpdateRingCloseX();
    void Render(Camera2D *camera);
    void Start();
    void SetState(int state);
    int SetZ(int z);

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
