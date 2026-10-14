#ifndef POKERANGER2_BATTLE_BATTLEPARTICLE_HPP
#define POKERANGER2_BATTLE_BATTLEPARTICLE_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveQUAD.hpp"

// Defined in ov1
class BattleParticle {
public:
    BattleParticle();
    ~BattleParticle();
    void ov1_02136760();
    void ov1_0213680C();
    void ov1_02136840();
    void ov1_02136874();
    void ov1_021368A8();
    void ov1_021368D0();
    void ov1_021368F8();
    void ov1_021368FC();
    void ov1_02136930(Camera2D *camera, GXDLInfo *dl);
    void ov1_021369FC(u16 duration, fx32 x, fx32 y, fx32 z, fx32 size, u16 color);
    void ov1_02136A40(fx32 x, fx32 y);
    void ov1_02136A58(fx32 x, fx32 y);
    void ov1_02136A70(fx32 x, fx32 y);
    void ov1_02136A88(u8 arg0, u8 arg1);
    void ov1_02136AA0(fx32 arg0, int arg1);
    void ov1_02136AB8(fx32 x, fx32 y, int arg2);

public:
    CPrimitiveQUAD m_quad;
    u16 m_flags;
    fx32 m_x;
    fx32 m_y;
    fx32 m_z;
    fx32 m_size;
    u8 m_alpha;
    fx32 m_scale;
    u16 m_color;
    u16 m_duration;
    u16 m_timer;
    fx32 m_vx;
    fx32 m_ax;
    fx32 m_vy;
    fx32 m_ay;
    fx32 m_vz;
    fx32 m_az;
    u8 m_alphaFrom;
    u8 m_alphaTo;
    fx32 m_scaleFrom;
    fx32 m_scaleTo;
    fx32 m_dvx;
    fx32 m_dvy;
    fx32 m_dvz;
};

STATIC_SIZE_ASSERT(BattleParticle, 0xB4);

#endif // POKERANGER2_BATTLE_BATTLEPARTICLE_HPP
