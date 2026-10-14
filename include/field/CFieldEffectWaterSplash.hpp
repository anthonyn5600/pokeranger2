#ifndef POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// After the field headers: CDrawObject completing last gives the .data typeinfo order (WaterSplash, factory, draw
// object).
#include "DrawObjectList.hpp"

class CNCERFile;
class VramPalette;
class VramImage;
class CellAnimController;

class CFieldEffectWaterSplash : public CFieldEffect {
public:
    // Hands the render list's depth to the splash sprite.
    class CEffectDrawObject : public CDrawObject {
    public:
        CEffectDrawObject()
        {
            m_depth = 0;
        }
        virtual int Draw(Camera2D *camera, int budget);

    public:
        int m_depth;
    };

    CFieldEffectWaterSplash();
    virtual ~CFieldEffectWaterSplash();
    virtual void ov0_021423A4();
    virtual int GetEffectId();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_02142398(DrawObjectList *renderLists);
    virtual int SetParam(int param, int value);

    void Setup(VramImage *ncbr, VramPalette *palette, CNCERFile *ncer, CellAnimController *cac);
    void Activate();
    void Deactivate();

public:
    u8 m_active;
    CellAnimController *m_cac;
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
