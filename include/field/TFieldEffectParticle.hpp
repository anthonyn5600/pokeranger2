#ifndef POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
#define POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP

#include <nitro.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Particle effects (ov0): a pool of sprites fed by emitters and moved by an optional force field.

struct FieldEffectSpriteRes {
    FieldEffectSpriteRes()
    {
    }
    FieldEffectSpriteRes(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer)
    {
        this->ncbr = ncbr;
        this->palette = palette;
        this->ncer = ncer;
    }

    UnkClass_020074D4 *ncbr;
    UnkClass_02007AA4 *palette;
    CNCERFile *ncer;
};

template <class T>
struct TFieldParticle {
    T sprite;
    Point2D pos;
    Point2D vel;
    s16 rot;
    s16 rotVel;
    int life;
    u8 unk_64[8];
    TFieldParticle *prev;
    TFieldParticle *next;

    void SetRes(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer)
    {
        sprite.SetImage((UnkClass_CPrimitive_ImageProxy *)ncbr, NULL);
        sprite.unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
        sprite.unk_38 = (UnkClass_CSoftwareSprite_38 *)ncer;
    }
};

template <class T>
class TFieldParticleEmitter {
public:
    virtual ~TFieldParticleEmitter()
    {
    }
    virtual void func2()
    {
    }
    virtual u32 Update(int dt);
    virtual void Emit(TFieldParticle<T> *p) = 0;
};

template <class T>
u32 TFieldParticleEmitter<T>::Update(int dt)
{
    return 0;
}

template <class T>
class TFieldParticleForceField {
public:
    virtual ~TFieldParticleForceField()
    {
    }
    virtual void Apply(TFieldParticle<T> *p, int dt) = 0;
};

template <class T>
struct TFieldParticleSystem {
    u8 unk_00[8];
    int m_speed;
    TFieldParticleEmitter<T> **m_emitters;
    u32 *m_emitCounts;
    u32 m_emitterCount;
    FieldEffectSpriteRes m_res;
    TFieldParticleForceField<T> *m_forceField;
    u8 unk_28[8];
    TFieldParticle<T> *m_active;
    TFieldParticle<T> *m_free;

    // Unlinks a dead particle from the active list (the caller already read its successor) and pools it.
    void Free(TFieldParticle<T> *p, TFieldParticle<T> *next)
    {
        if (p != NULL) {
            if (next != NULL) {
                next->prev = p->prev;
            }
            if (p->prev != NULL) {
                p->prev->next = p->next;
            } else {
                m_active = p->next;
            }
            p->next = m_free;
            p->prev = NULL;
            if (m_free != NULL) {
                m_free->prev = p;
            }
            m_free = p;
        }
    }

    void Update(int step)
    {
        int dt = step * m_speed;
        UpdateParticles(dt);
        u32 total = UpdateEmitters(dt);
        if (total != 0) {
            for (u32 i = 0; i < m_emitterCount; i++) {
                if (m_emitters[i] != NULL && m_emitCounts[i] != 0) {
                    for (u32 j = 0; j < m_emitCounts[i]; j++) {
                        TFieldParticle<T> *np = Alloc();
                        if (np != NULL) {
                            np->SetRes(m_res.ncbr, m_res.palette, m_res.ncer);
                            m_emitters[i]->Emit(np);
                            if (m_forceField != NULL) {
                                m_forceField->Apply(np, dt);
                            }
                        }
                    }
                }
            }
        }
    }

    void UpdateParticles(int dt)
    {
        TFieldParticle<T> *p = m_active;
        while (p != NULL) {
            TFieldParticle<T> *next = p->next;
            if (p->life != 0) {
                if (m_forceField != NULL) {
                    m_forceField->Apply(p, dt);
                }
                if (p->life > 0) {
                    p->pos += p->vel * (fx64)dt;
                    p->rot += (p->rotVel * dt) >> 12;
                    p->life -= dt;
                    if (p->life < 0) {
                        p->life = 0;
                    }
                }
            } else {
                Free(p, next);
            }
            p = next;
        }
    }

    u32 UpdateEmitters(int dt)
    {
        u32 i;
        u32 total = 0;
        for (i = 0; i < m_emitterCount; i++) {
            if (m_emitters[i] != NULL) {
                m_emitCounts[i] = m_emitters[i]->Update(dt);
                total += m_emitCounts[i];
            } else {
                m_emitCounts[i] = 0;
            }
        }

        return total;
    }

    TFieldParticle<T> *Alloc()
    {
        TFieldParticle<T> *p = NULL;
        if (m_free != NULL) {
            p = m_free;
            m_free = p->next;
            if (m_free != NULL) {
                m_free->prev = NULL;
            }
            p->next = m_active;
            p->prev = NULL;
            if (m_active != NULL) {
                m_active->prev = p;
            }
            m_active = p;
        }
        return p;
    }
};

template <class T>
class TFieldEffectParticle : public CFieldEffect {
public:
    virtual int ov0_02142264(int step)
    {
        int state = CFieldEffect::ov0_02142264(step);
        if (state != 4 && m_system != NULL) {
            m_system->Update(step);
        }
        return state;
    }

    virtual void ov0_021423E8(const FieldEffectSpriteRes &res)
    {
        m_res = res;
        if (m_system != NULL) {
            m_system->m_res = m_res;
        }
    }

    TFieldParticleSystem<T> *m_system;
    FieldEffectSpriteRes m_res;
};

#endif // POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
