#ifndef POKERANGER2_BATTLE_CBATTLEENEMY_HPP
#define POKERANGER2_BATTLE_CBATTLEENEMY_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "CellCharBuffer.hpp"
#include "Collision.hpp"
#include "ScriptVM.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"

class CBattleEnemyGauge;
class BattleParticlePool;
class CaptureEffect;
class CaptureMark;
class UnkClass_02127B48;
class UnkClass_0212770C;
class BattleEffectivenessMark;
class BattleHPNumber;
class BattleStatusIcon;
class BattleStatusDebug;

// Defined in ov1
class CBattleEnemy : public CActor {
public:
    CBattleEnemy(u8 index, CBattleEnemyData *data);
    virtual ~CBattleEnemy();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void RunScript();
    void UpdateAlive();
    void UpdateCapture();
    void UpdateCaptureGather();
    void UpdateOrbit();
    int DrawOverlays(Camera2D *camera, int z);
    void InitScript();
    void Terminate();
    void TakeDamage(int damage, BOOL keepAlive);
    void SetStatus(int state, int duration);
    u8 ov1_02126424();
    void SpawnBurstParticles();
    void SpawnGatherParticles(u8 count);
    void SetTargetable(BOOL targetable);
    void SetInvincible(BOOL invincible);
    void SetShadowVisible(BOOL arg0);
    void ov1_02126764(BOOL arg0);
    void StartCapture(u16 duration);
    BOOL IsCaptureFinished();

    inline BOOL IsAlive()
    {
        return unk_188 != 0;
    }

    inline BOOL IsTargetable()
    {
        return (m_flags & 0x200) == 0;
    }

    inline Rectangle GetShadowRect()
    {
        Rectangle rect = unk_184->unk_2C;
        rect.pos.x += m_motion.m_pos.x;
        rect.pos.y += m_motion.m_pos.y;
        rect.pos.x += unk_484.x;
        return rect;
    }

    inline BOOL IsUnk800Clear()
    {
        return (m_flags & 0x800) == 0;
    }

    inline BOOL IsUnk400Clear()
    {
        return (m_flags & 0x400) == 0;
    }

    inline BOOL IsUnk2000()
    {
        return (m_flags & 0x2000) != 0;
    }

public:
    CBattleEnemyData *unk_184;
    u16 unk_188;
    int unk_18C;
    u16 unk_190;
    u16 unk_192;
    u16 unk_194;
    CaptureEffect *unk_198;
    CaptureMark *unk_19C;
    UnkClass_02127B48 *unk_1A0;
    UnkClass_0212770C *unk_1A4;
    BattleEffectivenessMark *unk_1A8;
    BattleHPNumber *unk_1AC;
    BattleStatusIcon *unk_1B0;
    BattleStatusDebug *unk_1B4;
    CBattleEnemyGauge *unk_1B8;
    BattleParticlePool *unk_1BC;
    CellCharBuffer m_cellBuffers[0x1D];
    NNSGfdTexKey m_texKey;
    u16 unk_47C;
    u8 unk_47E;
    u16 unk_480;
    Point2D unk_484;
    u8 m_index;
    u32 m_stack[0x80];
    ScriptVM m_vm;
    u16 unk_6B4;
    CPrimitiveLINE m_line;
    CPrimitiveSPHERE m_sphere;
};

STATIC_SIZE_ASSERT(CBattleEnemy, 0x704);

#endif // POKERANGER2_BATTLE_CBATTLEENEMY_HPP
