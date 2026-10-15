#ifndef POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP
#define POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CSoftwareSprite.hpp"

class AudioEngine;
class GraphicsSet;
class BattleParticle;
class BattleParticlePool;

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

    void Load();
    void Release();
    void Hold(Point2D pos);
    void StopHold();
    void PlayLevelUpAnim();
    void Init();
    void ResetCharge();
    void SpawnChargeParticle();
    void SpawnStreak();
    BOOL IsNearTouchStart(Point2D pos);
    BOOL IsCharging();
    u16 GetLevel();
    fx32 GetLevelScale();
    void ov1_02137B94(Camera2D *camera);
    void DrawLevelUp(Camera2D *camera);
    void DrawBurst(Camera2D *camera);
    void DrawStreaks(Camera2D *camera);
    void StartBurst(u8 level);
    int SetZ(int z);

    inline void SetChargeTimes(u16 a, u16 b)
    {
        m_chargeTimes[0] = a;
        m_chargeTimes[1] = b;
    }

public:
    AudioEngine *m_audio;
    GraphicsSet *m_res[2];
    Point2D m_touchStart;
    Point2D unk_198;
    Point2D m_center;
    u16 m_flags;
    u16 m_tick;
    u16 m_chargeTimer;
    u16 unk_1AE;
    u16 m_anim[2];
    BattleParticle *m_particles[20];
    BattleParticlePool *m_pool;
    u8 unk_208;
    u8 m_burstState;
    u8 m_burstCount;
    u16 m_burstFrame;
    u16 m_burstAnim;
    GraphicsSet *m_burstRes;
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
