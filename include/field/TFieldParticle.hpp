#ifndef POKERANGER2_FIELD_TFIELDPARTICLE_HPP
#define POKERANGER2_FIELD_TFIELDPARTICLE_HPP

#include <nitro.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
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
    TFieldParticle();
    ~TFieldParticle();

    T sprite;
    Point2D pos;
    Point2D vel;
    s16 rot;
    s16 rotVel;
    int life;
    int maxLife;
    int animIdx;
    TFieldParticle *prev;
    TFieldParticle *next;

    void SetRes(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer)
    {
        sprite.SetImage((UnkClass_CPrimitive_ImageProxy *)ncbr, NULL);
        sprite.unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
        sprite.unk_38 = (UnkClass_CSoftwareSprite_38 *)ncer;
    }
};

// m_rate and unk_14 are unused by the ov0 subclasses.
template <class T>
TFieldParticle<T>::TFieldParticle()
{
    animIdx = 0;
    sprite.m_polygonID = 8;
    sprite.m_z = 0x622;
}

template <class T>
TFieldParticle<T>::~TFieldParticle()
{
}

template <class T>
class TFieldParticleEmitter {
public:
    TFieldParticleEmitter()
    {
        unk_14 = 0;
        m_pos.x = 0;
        m_pos.y = 0;
        unk_0C = 0;
        m_rate = 0x1000;
    }
    virtual ~TFieldParticleEmitter()
    {
    }
    virtual void func2();
    virtual u32 Update(int dt);
    virtual void Emit(TFieldParticle<T> *p) = 0;

    Point2D m_pos;
    int unk_0C;
    int m_rate;
    int unk_14;
};

template <class T>
void TFieldParticleEmitter<T>::func2()
{
}

template <class T>
u32 TFieldParticleEmitter<T>::Update(int dt)
{
    return 0;
}

// Its vtable and own virtuals are never emitted in ov0 (the subclasses override everything), so only this is known:
// it overrides func2, otherwise its vtable would instantiate TFieldParticleEmitter::func2 early (emission order).
template <class T>
class TFieldParticlePointEmitter : public TFieldParticleEmitter<T> {
public:
    TFieldParticlePointEmitter()
    {
    }
    virtual void func2()
    {
    }
};

// Emits from a rectangle (ov0). Fields not mapped yet (the smoke subclass uses up to about 0x58).
template <class T>
class TFieldParticleRectEmitter : public TFieldParticleEmitter<T> {
public:
    virtual ~TFieldParticleRectEmitter();
};

template <class T>
class TFieldParticleSmokeRectEmitter : public TFieldParticleRectEmitter<T> {
public:
    virtual ~TFieldParticleSmokeRectEmitter();
    virtual void func2();
    virtual u32 Update(int dt);
    virtual void Emit(TFieldParticle<T> *p);
    virtual void ov0_0215B988(); // clears +0x30
};

template <class T>
class TFieldParticleForceField {
public:
    TFieldParticleForceField()
    {
    }
    virtual ~TFieldParticleForceField()
    {
    }
    virtual void Apply(TFieldParticle<T> *p, int dt) = 0;
};

template <class T>
struct TFieldParticleSystem {
    TFieldParticleSystem(u32 emitterCount, u32 poolSize)
    {
        m_speed = 0x1000;
        m_emitterCount = emitterCount;
        m_res.ncbr = NULL;
        m_res.palette = NULL;
        m_res.ncer = NULL;
        m_forceField = NULL;
        m_poolSize = poolSize;
        m_active = NULL;
        if (m_poolSize != 0) {
            m_pool = new TFieldParticle<T>[m_poolSize];
            TFieldParticle<T> *prev = NULL;
            for (u32 i = 0; i < m_poolSize; i++) {
                m_pool[i].prev = prev;
                u32 n = i + 1;
                m_pool[i].next = n < m_poolSize ? &m_pool[n] : NULL;
                prev = &m_pool[i];
            }
            m_free = m_pool;
        } else {
            m_pool = NULL;
            m_free = NULL;
        }
        m_depth = 0;
        if (m_emitterCount != 0) {
            m_emitters = new TFieldParticleEmitter<T> *[m_emitterCount];
            MI_CpuFill8(m_emitters, 0, m_emitterCount * sizeof(TFieldParticleEmitter<T> *));
            m_emitCounts = new u32[m_emitterCount];
        } else {
            m_emitters = NULL;
            m_emitCounts = NULL;
        }
        m_offset.y = 0;
        m_offset.x = 0;
    }

    ~TFieldParticleSystem()
    {
        SAFE_DELETE_ARRAY(m_emitCounts);
        SAFE_DELETE_ARRAY(m_emitters);
        SAFE_DELETE_ARRAY(m_pool);
    }

    Point2D m_offset;
    int m_speed;
    TFieldParticleEmitter<T> **m_emitters;
    u32 *m_emitCounts;
    u32 m_emitterCount;
    FieldEffectSpriteRes m_res;
    TFieldParticleForceField<T> *m_forceField;
    TFieldParticle<T> *m_pool;
    u32 m_poolSize;
    TFieldParticle<T> *m_active;
    TFieldParticle<T> *m_free;
    int m_depth;

    void SetEmitter(u32 i, TFieldParticleEmitter<T> *emitter)
    {
        if (i < m_emitterCount && m_emitters != NULL) {
            m_emitters[i] = emitter;
        }
    }

    void SetRes(const FieldEffectSpriteRes &res)
    {
        m_res = res;
    }

    void Draw(Camera2D *camera)
    {
        for (TFieldParticle<T> *p = m_active; p != NULL; p = p->next) {
            if (m_depth < 0) {
                p->sprite.m_z = m_depth;
            }
            p->sprite.m_coords[0] = p->pos.x + m_offset.x;
            p->sprite.m_coords[1] = p->pos.y + m_offset.y;
            p->sprite.m_rotAngle = p->rot;
            p->sprite.Render(camera);
        }
    }

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

#endif // POKERANGER2_FIELD_TFIELDPARTICLE_HPP
