#ifndef POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// After the field headers: CDrawObject completing last gives the .data typeinfo order (WaterSplash, factory, draw
// object).
#include "UnkClass_0211E3FC.hpp"

class CNCERFile;
class UnkClass_02007AA4;
class UnkClass_020074D4;
class UnkClass_02008788;

class CFieldEffectWaterSplash : public CFieldEffect {
public:
    // Hands the render list's depth to the splash sprite.
    class CEffectDrawObject : public CDrawObject {
    public:
        CEffectDrawObject()
        {
            m_depth = 0;
        }
        virtual int sub_020091D4(Camera2D *camera, int budget);

    public:
        int m_depth;
    };

    CFieldEffectWaterSplash();
    virtual ~CFieldEffectWaterSplash();
    virtual void ov0_021423A4();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_02142398(UnkClass_0211E3FC *renderLists);
    virtual int sub_0203312C(int param, int value);

    void Setup(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer, UnkClass_02008788 *cac);
    void Activate();
    void Deactivate();

public:
    u8 m_active;
    UnkClass_02008788 *m_cac;
    CSoftwareSprite m_sprite;
    u16 m_anim;
    CEffectDrawObject m_drawObj;
};

STATIC_SIZE_ASSERT(CFieldEffectWaterSplash, 0x80);

class CFieldEffectWaterSplashFactory : public CFieldEffectFactory {
public:
    CFieldEffectWaterSplashFactory(CFieldEffectManage *mgr);
    virtual CFieldEffect *Create(int arg);

public:
    CFieldEffectWaterSplash m_splashes[16];
};

STATIC_SIZE_ASSERT(CFieldEffectWaterSplashFactory, 0x804);

#endif // POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP
