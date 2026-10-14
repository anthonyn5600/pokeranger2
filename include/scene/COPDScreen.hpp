#ifndef POKERANGER2_SCENE_COPDSCREEN_HPP
#define POKERANGER2_SCENE_COPDSCREEN_HPP

#include "common.hpp"
#include "field/CPrimitiveNTF.hpp"
#include "field/CSimpleSpriteNTF.hpp"

#ifdef POKERANGER2_FIELD_TFIELDPARTICLE_HPP
#error "include scene/COPDScreen.hpp before field/TFieldParticle.hpp: ov3 uses the in-class template members"
#endif
#define TFIELDPARTICLE_INLINE_MEMBERS
#include "field/TFieldParticle.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

class Camera2D;
class UnkClass_0201AAE0;

// Opening demo texture: an NtfTexture plus its frame layout from the scene's table
struct COPDTexture {
    COPDTexture()
    {
        unk_1C = 0;
        unk_20 = 0;
        unk_24 = 0;
        unk_28 = 0;
    }

    void SetSize(int width, int height)
    {
        unk_20 = width;
        unk_24 = height;
    }

    NtfTexture m_tex;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
};

STATIC_SIZE_ASSERT(COPDTexture, 0x2C);

// Resource the system hands to each new particle: the title's NTF sprites take a texture, the capture disc's line
// particles none (the member stays uninitialized).
template <class T>
struct TOPDParticleRes {
    typedef void *Type;
    static void Init(Type &res)
    {
    }
    static void Set(void *sprite, Type res)
    {
    }
};

template <>
struct TOPDParticleRes<CSimpleSpriteNTF> {
    typedef COPDTexture *Type;
    static void Init(Type &res)
    {
        res = NULL;
    }
    static void Set(CSimpleSpriteNTF *sprite, Type res)
    {
        sprite->unk_18 = res;
    }
};

// ov3's particle system: TFieldParticleSystem with one texture as the particles' resource
template <class T>
struct TOPDParticleSystem {
    TOPDParticleSystem(u32 emitterCount, u32 poolSize)
    {
        m_speed = 0x1000;
        m_emitterCount = emitterCount;
        TOPDParticleRes<T>::Init(m_res);
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

    ~TOPDParticleSystem()
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
    typename TOPDParticleRes<T>::Type m_res;
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
                            TOPDParticleRes<T>::Set(&np->sprite, m_res);
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

// Defined in ov3: one screen of the opening demo
class COPDScreen {
public:
    virtual ~COPDScreen()
    {
    }
    virtual void Init() = 0;
    virtual void Release() = 0;
    virtual void Start(COPDTexture *textures) = 0;
    virtual void Stop() = 0;
    virtual int Update() = 0;
    virtual void Render(Camera2D *camera, int flip) = 0;
};

class CSparkLine;
class CLineParticle;

// Defined in ov3
class COPDCaptureLine : public CPrimitive {
public:
    COPDCaptureLine()
        : unk_18(NULL)
        , unk_20(0)
        , unk_24(0)
        , unk_28(0)
    {
    }
    virtual ~COPDCaptureLine(); // ov3_02129130
    virtual u32 Render(Camera2D *camera); // ov3_021296C4
    void ov3_02129198(int count);
    void ov3_02129280();
    void ov3_021292FC(Point2D *points, int count);
    void ov3_02129A4C();

public:
    void *unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    CSoftwareSprite m_sprite;
    int unk_7C;
};

STATIC_SIZE_ASSERT(COPDCaptureLine, 0x80);

struct UnkStruct_COPDRing {
    u16 angle;
    Point2D radii[4];
};

STATIC_SIZE_ASSERT(UnkStruct_COPDRing, 0x24);

struct UnkStruct_COPDBeam {
    u16 angle;
    s16 speed;
    fx32 unk_04;
    fx32 unk_08;
    fx32 unk_0C;
};

STATIC_SIZE_ASSERT(UnkStruct_COPDBeam, 0x10);

// The thrown capture disc: position (z = height), velocity, gravity and bounce count.
struct UnkStruct_COPDBall {
    fx32 x;
    fx32 y;
    fx32 z;
    fx32 vx;
    fx32 vy;
    fx32 vz;
    fx32 gravity;
    u32 bounces;
};

STATIC_SIZE_ASSERT(UnkStruct_COPDBall, 0x20);

// Defined in ov3
class COPDCaptureDiscScreen : public COPDScreen {
public:
    COPDCaptureDiscScreen(); // ov3_02126ECC
    virtual ~COPDCaptureDiscScreen(); // ov3_02127350
    virtual void Init();
    virtual void Release();
    virtual void Start(COPDTexture *textures);
    virtual void Stop();
    virtual int Update();
    virtual void Render(Camera2D *camera, int flip);
    void ov3_02127B34();

public:
    int unk_004;
    int unk_008;
    CSoftwareSprite unk_00C[1];
    UnkClass_0201AAE0 *unk_058;
    u16 unk_05C;
    CSimpleSpriteNTF unk_060[2];
    UnkStruct_COPDBall unk_118;
    COPDCaptureLine unk_138;
    Point2D *unk_1B8;
    int unk_1BC;
    UnkStruct_COPDRing unk_1C0[6];
    u8 unk_298[0x24];
    int unk_2BC;
    u8 unk_2C0;
    TOPDParticleSystem<CSparkLine> m_sparks;
    TOPDParticleSystem<CLineParticle> m_lines;

    class CLineParticleEmitter : public TFieldParticleEmitter<CLineParticle> {
    public:
        CLineParticleEmitter()
        {
            unk_20 = unk_1C = unk_18 = 0;
        }
        void Burst(int count, UnkStruct_COPDRing *ring)
        {
            unk_18 = count;
            unk_1C = (int)ring;
        }
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CLineParticle> *p);

    public:
        int unk_18;
        int unk_1C;
        int unk_20;
    };

    class CLineParticleAnimator : public TFieldParticleForceField<CLineParticle> {
    public:
        virtual void Apply(TFieldParticle<CLineParticle> *p, int dt);
    };

    class CSparkEmitter : public TFieldParticleEmitter<CSparkLine> {
    public:
        CSparkEmitter()
        {
            m_timer = 0;
        }
        virtual void func2()
        {
            m_timer = FX32_ONE;
        }
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSparkLine> *p);

    public:
        int m_timer;
    };

    class CSparkAnimator : public TFieldParticleForceField<CSparkLine> {
    public:
        virtual void Apply(TFieldParticle<CSparkLine> *p, int dt);
    };

public:
    CLineParticleEmitter m_lineEmitter;
    CLineParticleAnimator m_lineAnimator;
    CSparkEmitter m_sparkEmitter;
    CSparkAnimator m_sparkAnimator;
    CSimplePrimitiveQuadNTF unk_374[10];
    UnkStruct_COPDBeam unk_75C[10];
    int unk_7FC;
    int unk_800;
    u8 unk_804;
};

STATIC_SIZE_ASSERT(COPDCaptureDiscScreen, 0x808);

// Defined in ov3: light streak particle of the capture disc screen
class CLineParticle : public CPrimitiveQUAD {
public:
    int unk_60;
};

// Defined in ov3: spark particle of the capture disc screen
class CSparkLine : public CPrimitiveLINE {
public:
    int unk_28;
    int unk_2C;
};

// Defined in ov3: textured grid mesh (vtable 0x0212B4E0)
class COPDScreenMeshNTF : public CPrimitive {
public:
    COPDScreenMeshNTF()
    {
        unk_18 = NULL;
    }
    virtual ~COPDScreenMeshNTF(); // ov3_02129A68
    virtual u32 Render(Camera2D *camera); // ov3_02129C90
    void ov3_02129AC0(int columns, int rows, fx32 x, fx32 y, fx32 s, fx32 t, fx32 width, fx32 height);
    void ov3_02129C54();

    void SetVertex(u16 x, u16 y, fx32 vx, fx32 vy)
    {
        Point2D *line = &unk_1C[y * (unk_24 + 1)];
        line[x].x = vx;
        line[x].y = vy;
    }

public:
    COPDTexture *unk_18;
    Point2D *unk_1C;
    int unk_20;
    u16 unk_24;
    u16 unk_26;
};

STATIC_SIZE_ASSERT(COPDScreenMeshNTF, 0x28);

struct UnkStruct_02129E98_1D4 {
    fx32 x;
    fx32 y;
    u16 angle;
    u16 speed;
    fx32 radius;
};

// Defined in ov3
class UnkClass_02129E98 {
public:
    UnkClass_02129E98(); // ov3_02129E98
    ~UnkClass_02129E98(); // ov3_02129F54
    void ov3_02129F78();
    void ov3_02129FE0(Camera2D *camera);

public:
    CPrimitiveRECT unk_000[7];
    int unk_1C0;
    int unk_1C4;
    int unk_1C8;
    int unk_1CC;
    int unk_1D0;
    UnkStruct_02129E98_1D4 unk_1D4[3][3];
};

STATIC_SIZE_ASSERT(UnkClass_02129E98, 0x264);

// Defined in ov3
class COPDTitleScreen : public COPDScreen {
public:
    class CSparkAnimator : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);
    };

    class CSparkEmitter : public TFieldParticleEmitter<CSimpleSpriteNTF> {
    public:
        CSparkEmitter(COPDTitleScreen *owner)
        {
            m_timer = 0;
            m_counter = &owner->m_particleId;
        }
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSimpleSpriteNTF> *p);

    public:
        int m_timer;
        int *m_counter;
    };

    class CStarEmitter : public TFieldParticleEmitter<CSimpleSpriteNTF> {
    public:
        CStarEmitter(COPDTitleScreen *owner)
        {
            m_timer = 0;
            m_counter = &owner->m_particleId;
        }
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSimpleSpriteNTF> *p);

    public:
        int m_timer;
        int *m_counter;
    };

    class CStarAnimator : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);
    };

    COPDTitleScreen(); // ov3_021251DC
    virtual ~COPDTitleScreen(); // ov3_021255B8
    virtual void Init();
    virtual void Release();
    virtual void Start(COPDTexture *textures);
    virtual void Stop();
    virtual int Update();
    virtual void Render(Camera2D *camera, int flip);
    void ov3_02125CB0();

public:
    int unk_004;
    int unk_008;
    CSimpleSpriteNTF m_sprites[7];
    COPDScreenMeshNTF m_mesh;
    UnkClass_02129E98 unk_2B8;
    TOPDParticleSystem<CSimpleSpriteNTF> m_sparks;
    TOPDParticleSystem<CSimpleSpriteNTF> m_stars;
    int m_particleId;
    CSparkEmitter m_sparkEmitter;
    CSparkAnimator m_sparkAnimator;
    CStarEmitter m_starEmitter;
    CStarAnimator m_starAnimator;
    u8 unk_5D0;
    u16 m_toonTable[32];
    u8 unk_612;
    u8 unk_613;
};

STATIC_SIZE_ASSERT(COPDTitleScreen, 0x614);

#endif // POKERANGER2_SCENE_COPDSCREEN_HPP
