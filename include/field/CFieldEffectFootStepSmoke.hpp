#ifndef POKERANGER2_FIELD_CFIELDEFFECTFOOTSTEPSMOKE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFOOTSTEPSMOKE_HPP

#include <nitro.h>

#include "UnkClass_0211E3FC.hpp"
#include "field/CFieldEffect.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldEffectFootStepSmoke : public CFieldEffect {
public:
    CFieldEffectFootStepSmoke();
    class CFieldParticleOneShotEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        virtual ~CFieldParticleOneShotEmitter();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    class CFieldParticleAlphaAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CFieldParticleAlphaAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    class CDrawObjectParticle : public CDrawObject {
    public:
        virtual ~CDrawObjectParticle();
        virtual int sub_020091D4(Camera2D *camera, int budget);
    };

    virtual ~CFieldEffectFootStepSmoke();
    virtual int sub_02033028();
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int ov0_0214239C(int layer);
    virtual void ov0_02142398(UnkClass_0211E3FC *renderLists);
    void ov0_021509F4(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer);
    void ov0_02150A04(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer, UnkClass_02008788 *cac);
    void ov0_02150A94();
    void ov0_02150AE8(int idx, int arg1, int arg2, int arg3);

    u8 unk_18[0x2A0];
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFOOTSTEPSMOKE_HPP
