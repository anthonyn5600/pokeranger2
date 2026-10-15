#ifndef POKERANGER2_BATTLE_CBATTLEDISK_HPP
#define POKERANGER2_BATTLE_CBATTLEDISK_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"

class CBattlePowerSave;
class CDiskCursor;
class CLineEffect;
class CSoftwareSprite;
class GraphicsSet;
class BattleHitEffectGfx;
class BattleHitEffect;
class BattleHPNumber;
class BattleDamageNumberGfx;
class BattleDamageNumber;
class StylerLine;
class BattleDiskRing;
class BattleParticlePool;

// Defined in ov1
class CBattleDisk : public CActor {
public:
    CBattleDisk(BattleParticlePool *particles);
    virtual ~CBattleDisk();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void Load();
    void Release();
    void RenderLine(Camera2D *camera);
    void RenderDisk(Camera2D *camera);
    void RenderChargeEffect(Camera2D *camera);
    void RenderChargeLevel(Camera2D *camera);
    void AddLinePoint(Point2D pos);
    int TakeDamage(u16 damage, u8 type);
    void UpdateCursor();
    void UpdatePowerCharge();
    BOOL HasEnergy();
    BOOL IsLoopClosed();
    u8 IsVisible();
    void SetVisible(u8 enabled);
    void ov1_0212C4F4(BOOL arg0);
    void SetActive(BOOL active);
    BOOL IsActive();
    BOOL IsInvincible();
    void SetInvincible(BOOL arg0);
    void ResetLine(fx32 x, fx32 y);
    Point2D GetLineStart(int index);
    Point2D GetLineEnd(int index);
    int GetLineIndex(u16 index);
    int GetLineCount();
    void ShatterLine(u16 color);
    void SpawnLoopParticles(Point2D pos, int count, fx32 arg2, u16 color);
    void ov1_0212C990(Point2D pos, int count, fx32 arg2, u16 color);
    void ov1_0212CBA0(Point2D pos, int count, fx32 arg2);
    int CalcCapturePower(u16 level, int assistType, u8 type);
    void ShowHitEffect(fx32 x, fx32 y, int arg2);
    void InitTypeGuards();
    int SetZ(int z);
    int SetLineZ(int z);
    void SpawnSparks(Point2D pos, int count);

    inline void ShowHitEffect(Point2D pos, int mode)
    {
        ShowHitEffect(pos.x, pos.y, mode);
    }

    inline BOOL IsUnk194Flag80()
    {
        return (unk_194 & 0x80) != 0;
    }

public:
    u8 unk_184;
    u8 unk_185;
    u8 unk_186;
    u8 unk_187;
    u8 unk_188;
    u32 unk_18C;
    u32 unk_190;
    u16 unk_194;
    u16 unk_196;
    u16 unk_198;
    u16 unk_19A;
    u8 unk_19C;
    u8 unk_19D;
    u16 unk_19E;
    u8 unk_1A0[0x4];
    u8 unk_1A4[0x13];
    StylerLine *unk_1B8;
    BattleHPNumber *unk_1BC;
    CBattlePowerSave *unk_1C0;
    CPrimitiveSPHERE unk_1C4;
    CPrimitiveRECT unk_1E8;
    CSoftwareSprite *unk_228;
    GraphicsSet *unk_22C;
    u16 unk_230;
    CSoftwareSprite *unk_234;
    GraphicsSet *unk_238[2];
    u16 unk_240;
    u16 unk_242[3];
    CDiskCursor *unk_248;
    CLineEffect *unk_24C;
    BattleParticlePool *unk_250;
    BattleHitEffect *unk_254;
    BattleHitEffectGfx *unk_258;
    BattleDamageNumber *unk_25C;
    BattleDamageNumberGfx *unk_260;
    BattleDiskRing *unk_264;
};

STATIC_SIZE_ASSERT(CBattleDisk, 0x268);

#endif // POKERANGER2_BATTLE_CBATTLEDISK_HPP
