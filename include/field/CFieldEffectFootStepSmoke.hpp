#ifndef POKERANGER2_FIELD_CFIELDEFFECTFOOTSTEPSMOKE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFOOTSTEPSMOKE_HPP

#include <nitro.h>

// clang-format off
#include "field/CFieldEffect.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_0211E3FC.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"
// clang-format on

// Dust puffs under walking actors (ov0, member of CFieldEffectManage): particles from a one-shot emitter, plus up
// to four sprite puffs with their own CAC animation.
class CFieldEffectFootStepSmoke : public CFieldEffect {
public:
    // Draws one emitted particle from a render list (depth = the list's budget).
    class CDrawObjectParticle : public CDrawObject {
    public:
        CDrawObjectParticle()
        {
            m_particle = NULL;
        }
        virtual int sub_020091D4(Camera2D *camera, int budget);

        TFieldParticle<CSoftwareSprite> *m_particle;
    };

    // Emits the queued puffs (up to 8 per frame), one particle each.
    class CFieldParticleOneShotEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        struct Entry {
            fx32 x;
            fx32 y;
            u16 color;
            u16 kind;
            int layer;
            CDrawObjectParticle obj;
        };

        CFieldParticleOneShotEmitter()
        {
            m_emitIdx = m_count = 0;
        }

        virtual u32 Update(int dt)
        {
            u32 count = m_count;
            m_count = 0;
            m_emitIdx = 0;
            return count;
        }
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        void AddToRenderLists(UnkClass_0211E3FC *lists);
        void Add(u16 color, fx32 x, fx32 y, u16 kind, int layer);

        Entry m_entries[8];
        u8 m_count;
        u8 m_emitIdx;
    };

    // Scales the particles up over their life; kind 1 also fades out.
    class CFieldParticleAlphaAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    struct Puff {
        u16 cacId;
        s8 timer;
        u8 layer;
    };

    CFieldEffectFootStepSmoke();
    virtual ~CFieldEffectFootStepSmoke();
    virtual int sub_02033028()
    {
        return 0x27;
    }
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int ov0_0214239C(int layer)
    {
        return 1;
    }
    virtual void ov0_02142398(UnkClass_0211E3FC *renderLists);
    void ov0_021509F4(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer);
    void ov0_02150A04(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer, UnkClass_02008788 *cac);
    void ov0_02150A94();
    void ov0_02150AE8(int idx, int arg1, int arg2, int arg3);

    TFieldParticleSystem<CSoftwareSprite> m_system;
    CFieldParticleOneShotEmitter m_emitter;
    CFieldParticleAlphaAnimator m_animator;
    Puff m_puffs[4];
    CSoftwareSprite m_sprites[4];
    UnkClass_02008788 *m_cac;
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFOOTSTEPSMOKE_HPP
