#ifndef POKERANGER2_FIELD_CFIELDEFFECTDARKCLOUD_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTDARKCLOUD_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/FieldPointMover.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// These complete the particle templates in the original's order (rect emitter, effect base, force field) before
// the class, without instantiating their vtables; with the nested classes' order below this gives the TU's
// typeinfo/vtable data order (modelled with the TU-end walk + heapsort, ~/scratch/ov0/f75cc/dcmodel.py).
STATIC_SIZE_ASSERT(TFieldParticleRectEmitter<CSoftwareSprite>, 0x30);
STATIC_SIZE_ASSERT(TFieldEffectParticle<CSoftwareSprite>, 0x28);
STATIC_SIZE_ASSERT(TFieldParticleForceField<CSoftwareSprite>, 4);

// size 0x154, ctor ov0_021675CC
class CFieldEffectDarkCloud : public TFieldEffectParticle<CSoftwareSprite> {
public:
    class CEmitter : public TFieldParticleSmokeRectEmitter<CSoftwareSprite> {
    public:
        CEmitter(u8 *polygonID)
            : TFieldParticleSmokeRectEmitter<CSoftwareSprite>(0)
        {
            m_nextPolygonID = polygonID;
        }
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        u8 *m_nextPolygonID;
    };

    class CRemainsEmitter : public TFieldParticleSmokeRectEmitter<CSoftwareSprite> {
    public:
        CRemainsEmitter(u8 *polygonID)
            : TFieldParticleSmokeRectEmitter<CSoftwareSprite>(0)
        {
            m_nextPolygonID = polygonID;
        }
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        u8 *m_nextPolygonID;
    };

    class CRemainsAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        CAnimator()
        {
            m_scaleStart = 0xCCC;
            m_scaleEnd = 0x2000;
        }
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        fx32 m_scaleStart;
        fx32 m_scaleEnd;
    };

    CFieldEffectDarkCloud(int mode);
    virtual ~CFieldEffectDarkCloud();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_0203331C(const Point2D &pos, int arg1);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
    virtual void SetRes(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer); // ov0_02167BA4

    u8 m_polygonID;
    CAnimator m_animator;
    CEmitter m_emitter;
    FieldPointMover m_mover;
    TFieldParticleSystem<CSoftwareSprite> m_remains;
    CRemainsEmitter m_remainsEmitter;
    CRemainsAnimator m_remainsAnimator;
};

STATIC_SIZE_ASSERT(CFieldEffectDarkCloud, 0x154);

class CFieldEffectDarkCloudFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTDARKCLOUD_HPP
