#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPARK_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPARK_HPP

#include <nitro.h>

#include "UnkClass_02007AA4.hpp"
#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// One spark's motion: bobs between -m_size.y / 2 and m_size.y / 2, its colours pulse between two palette ramps.
struct SparkGlow {
    fx32 offset;
    fx32 offsetStep;
    fx32 blend;
    fx32 blendStep;
};

// Three sparks around m_pos (ov0) whose palettes (colours 2..8) blend between the effect palette's colours 2..8 and
// 9..15; each spark double-buffers its palette in VRAM (m_bank = the one drawn).
class CFieldEffectSpark : public CFieldEffectActor {
public:
    CFieldEffectSpark(int kind);
    virtual ~CFieldEffectSpark();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);

    void InitSprites();

public:
    Point2D m_pos;
    Point2D m_size;
    CSoftwareSprite m_sprites[3];
    u16 m_cacIds[3];
    UnkClass_02007AA4 m_palettes[3][2];
    NNSG2dPaletteData m_plttData[3];
    u8 m_plttRaw[3][0x20];
    NNSGfdPlttKey m_plttKeys[3][2];
    SparkGlow m_glow[3];
    u8 m_bank[3];
    u16 m_colorsFrom[8];
    u16 m_colorsTo[8];
};
STATIC_SIZE_ASSERT(CFieldEffectSpark, 0x2EC);

class CFieldEffectSparkFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPARK_HPP
