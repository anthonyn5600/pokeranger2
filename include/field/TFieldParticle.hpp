#ifndef POKERANGER2_FIELD_TFIELDPARTICLE_HPP
#define POKERANGER2_FIELD_TFIELDPARTICLE_HPP

// TFIELDPARTICLE_INLINE_MEMBERS: ov3 (opening demo) was built from a version of these templates whose particle
// ctor/dtor and TFieldParticleEmitter::Update are defined in the class: they are instantiated right after their first
// user instead of at the end of the TU. ov0 needs the out-of-class definitions. Set by scene/COPDScreen.hpp.

#include <nitro.h>

#include "CGame.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "field/CPrimitiveNTF.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

extern MATHRandContext16 MAIN_BSS_0210CEC8;

// Random value in [-range / 2, range / 2) (fx32).
static inline fx32 RandCentered(fx32 range)
{
    return FX_Mul((MATH_Rand16(&MAIN_BSS_0210CEC8, 0) & 0x7FFF) >> 3, range) - (range >> 1);
}

// Particle effects (ov0): a pool of sprites fed by emitters and moved by an optional force field.

struct FieldEffectSpriteRes {
    FieldEffectSpriteRes()
    {
    }
    FieldEffectSpriteRes(VramImage *ncbr, VramPalette *palette, CNCERFile *ncer)
    {
        this->ncbr = ncbr;
        this->palette = palette;
        this->ncer = ncer;
    }

    VramImage *ncbr;
    VramPalette *palette;
    CNCERFile *ncer;
};

template <class T>
struct TFieldParticle {
#ifdef TFIELDPARTICLE_INLINE_MEMBERS
    TFieldParticle()
    {
        animIdx = 0;
        sprite.m_polygonID = 8;
        sprite.m_z = 0x622;
    }
    ~TFieldParticle()
    {
    }
#else
    TFieldParticle();
    ~TFieldParticle();
#endif

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

    void SetPos(fx32 x, fx32 y)
    {
        pos.x = x;
        pos.y = y;
    }

    void SetRes(VramImage *ncbr, VramPalette *palette, CNCERFile *ncer)
    {
        sprite.SetImage((UnkClass_CPrimitive_ImageProxy *)ncbr, NULL);
        sprite.unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
        sprite.unk_38 = (UnkClass_CSoftwareSprite_38 *)ncer;
    }
};

// m_rate and unk_14 are unused by the ov0 subclasses.
#ifndef TFIELDPARTICLE_INLINE_MEMBERS
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
#endif

// What a particle sprite type is drawn with, and how a particle's sprite takes it.
template <class T>
struct TFieldParticleRes;

template <>
struct TFieldParticleRes<CSoftwareSprite> {
    typedef FieldEffectSpriteRes Type;

    static void Clear(Type &res)
    {
        res.ncbr = NULL;
        res.palette = NULL;
        res.ncer = NULL;
    }

    static void Set(TFieldParticle<CSoftwareSprite> *p, const Type &res)
    {
        p->SetRes(res.ncbr, res.palette, res.ncer);
    }

    static void SetCell(TFieldParticle<CSoftwareSprite> *p, u16 cell)
    {
        p->sprite.m_cellDataIdx = cell;
    }
};

template <>
struct TFieldParticleRes<CSimpleSpriteNTF> {
    typedef NtfTextureParam *Type;

    static void Clear(Type &res)
    {
        res = NULL;
    }

    static void Set(TFieldParticle<CSimpleSpriteNTF> *p, const Type &res)
    {
        p->sprite.unk_18 = res;
    }

    // NTF sprites have no cell banks.
    static void SetCell(TFieldParticle<CSimpleSpriteNTF> *p, u16 cell)
    {
    }
};

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
#ifdef TFIELDPARTICLE_INLINE_MEMBERS
    virtual u32 Update(int dt)
    {
        return 0;
    }
#else
    virtual u32 Update(int dt);
#endif
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

#ifndef TFIELDPARTICLE_INLINE_MEMBERS
template <class T>
u32 TFieldParticleEmitter<T>::Update(int dt)
{
    return 0;
}
#endif

// Its vtable and own virtuals are never emitted in ov0 (the subclasses override everything), so only this is known:
// it overrides func2, otherwise its vtable would instantiate TFieldParticleEmitter::func2 early (emission order).
// No user ctor (like TFieldParticleForceField): the implicit one lets the TU-end pass make its vtable in the first
// walk, which the data order of the effect TUs needs (an inline user ctor is only compiled after that walk).
template <class T>
class TFieldParticlePointEmitter : public TFieldParticleEmitter<T> {
public:
    virtual void func2()
    {
    }
};

// Emits from a rectangle (ov0) centred on m_pos.
template <class T>
class TFieldParticleRectEmitter : public TFieldParticleEmitter<T> {
public:
    TFieldParticleRectEmitter()
    {
        m_width = 0;
        m_height = 0;
        m_mtx[0] = 0x1000;
        m_mtx[1] = 0;
        m_mtx[2] = 0;
        m_mtx[3] = -0x1000;
    }

    fx32 m_mtx[4];
    fx32 m_width;
    fx32 m_height;
};

// No user ctor: see TFieldParticlePointEmitter.
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
    TFieldParticleSystem(u32 emitterCount, u32 poolSize)
    {
        m_speed = 0x1000;
        m_emitterCount = emitterCount;
        TFieldParticleRes<T>::Clear(m_res);
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
        m_offset.x = m_offset.y = 0;
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
    typename TFieldParticleRes<T>::Type m_res;
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

    void SetRes(const typename TFieldParticleRes<T>::Type &res)
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

    u32 Update(int step)
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
                            TFieldParticleRes<T>::Set(np, m_res);
                            m_emitters[i]->Emit(np);
                            if (m_forceField != NULL) {
                                m_forceField->Apply(np, dt);
                            }
                        }
                    }
                }
            }
        }
        return total;
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
