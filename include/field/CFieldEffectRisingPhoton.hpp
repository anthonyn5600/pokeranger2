#ifndef POKERANGER2_FIELD_CFIELDEFFECTRISINGPHOTON_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTRISINGPHOTON_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/UnkClass_02151244.hpp"

// Light specks that wait, rise and fade in, then rise faster until they leave the screen.
class CFieldEffectRisingPhoton : public CFieldEffect {
public:
    struct Photon {
        Photon()
        {
            x = y = delay = 0;
        }

        fx32 x;
        fx32 y;
        int delay;
        int state; // 0 waiting, 1 fading in, 2 rising, 3 gone
        int timer;
    };

    CFieldEffectRisingPhoton();
    virtual ~CFieldEffectRisingPhoton();
    virtual int GetEffectId();
    virtual int IsReady();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int SetParam(int param, int value);
    virtual int sub_02033244(int arg0, int arg1, int arg2);
    virtual void SetColor(u16 color);

    void LoadTextures();

public:
    int m_count;
    Photon *m_photons;
    CSimpleSpriteNTF *m_sprites; // two per photon
    int m_fadeInTime;
    fx32 m_speed;
    UnkClass_02151244 m_tex[2];
    u16 m_color;
    u8 m_readyFrames;
};

class CFieldEffectRisingPhotonFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

STATIC_SIZE_ASSERT(CFieldEffectRisingPhoton::Photon, 0x14);
STATIC_SIZE_ASSERT(CFieldEffectRisingPhoton, 0x88);

#endif // POKERANGER2_FIELD_CFIELDEFFECTRISINGPHOTON_HPP
