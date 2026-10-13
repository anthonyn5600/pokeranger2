#ifndef POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP
#define POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CSoftwareSprite.hpp"

class UnkClass_02034478;
class UnkClass_0201AAE0;
class UnkClass_02136730;
class UnkClass_02136AD4;

struct PowerStreak {
    u8 m_active;
    u16 m_frame;
    u16 m_angle;
    fx32 m_dist;
    CPrimitiveLINE m_line;
};

STATIC_SIZE_ASSERT(PowerStreak, 0x34);

// Defined in ov1
class CBattlePowerSave : public CActor {
public:
    CBattlePowerSave();
    virtual ~CBattlePowerSave();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void ov1_02136E08();
    void ov1_02136FB8();
    void ov1_02137094(Point2D pos);
    void ov1_02137144();
    void ov1_02137194();
    void ov1_021371C4();
    void ov1_021371F0();
    void ov1_0213720C();
    void ov1_021373FC();
    BOOL ov1_021374FC(Point2D pos);
    BOOL ov1_02137ABC();
    u16 ov1_02137AD4();
    fx32 ov1_02137ADC();
    void ov1_02137B94(Camera2D *camera);
    void ov1_02137B98(Camera2D *camera);
    void ov1_02137C3C(Camera2D *camera);
    void ov1_02137CF0(Camera2D *camera);
    void ov1_02137D44(u8 level);
    int ov1_02137D7C(int z);

    inline void SetChargeTimes(u16 a, u16 b)
    {
        m_chargeTimes[0] = a;
        m_chargeTimes[1] = b;
    }

public:
    UnkClass_02034478 *m_audio;
    UnkClass_0201AAE0 *m_res[2];
    Point2D m_touchStart;
    Point2D unk_198;
    Point2D m_center;
    u16 m_flags;
    u16 m_tick;
    u16 m_chargeTimer;
    u16 unk_1AE;
    u16 m_anim[2];
    UnkClass_02136730 *m_particles[20];
    UnkClass_02136AD4 *m_pool;
    u8 unk_208;
    u8 m_burstState;
    u8 m_burstCount;
    u16 m_burstFrame;
    u16 m_burstAnim;
    UnkClass_0201AAE0 *m_burstRes;
    CSoftwareSprite m_burst;
    CSoftwareSprite m_burstFx;
    u8 m_streakNext;
    PowerStreak m_streaks[0x30];
    u8 m_level;
    u8 m_maxLevel;
    u8 m_holdTimer;
    u16 m_chargeTimes[2];
    fx32 m_ratio;
    u8 m_alpha;
    u16 m_flashTimer;
};

STATIC_SIZE_ASSERT(CBattlePowerSave, 0xC80);

#endif // POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP
