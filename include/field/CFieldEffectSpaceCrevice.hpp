#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP

#include <nitro.h>

// clang-format off
#include "common.hpp"
#include "field/CFEFRasterTransform.hpp"
#include "DrawObjectList.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldEffect.hpp"
#include "field/UnkClass_02151244.hpp"
// clang-format on

// Two slits in space that open, spin and fade over a wavering backdrop (three raster strips; the third is the
// backdrop, the first two are drawn through a rotating texture matrix).
class CFieldEffectSpaceCrevice : public CFieldEffect {
public:
    class CEffectDrawObject : public CDrawObject {
    public:
        CEffectDrawObject(CFieldEffectSpaceCrevice *owner)
        {
            m_depth = 0;
            m_owner = owner;
            unk_14 = 0;
        }
        virtual int Draw(Camera2D *camera, int budget);

    public:
        int m_depth;
        CFieldEffectSpaceCrevice *m_owner;
        u8 unk_14;
    };

    struct Slit {
        s16 life;
        u16 angle;
        s16 speed;
    };

    // Moves a value from `from` to `to` over `duration` frames (same as CFieldEffectBloom's).
    struct Fader {
        Fader()
        {
            duration = 0;
            frame = 0;
            active = FALSE;
        }

        BOOL Update(int dt)
        {
            if (!active) {
                return FALSE;
            }
            frame += dt;
            fx32 t;
            if (duration <= 0) {
                t = FX32_ONE;
            } else if (frame >= duration) {
                t = FX32_ONE;
            } else {
                t = (frame << 12) / duration;
            }
            cur = from + FX32_MUL(t, to - from);
            if (frame >= duration) {
                active = FALSE;
            }
            return TRUE;
        }

        fx32 from;
        fx32 to;
        fx32 cur;
        int duration;
        int frame;
        BOOL active;
    };

    CFieldEffectSpaceCrevice(int arg);
    virtual ~CFieldEffectSpaceCrevice();
    virtual int GetEffectId();
    virtual int IsReady();
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual void AddToRenderLists(DrawObjectList *renderLists);
    virtual int SetParam(int param, int value);
    virtual void SetColor(u16 color);
    virtual void FadeTo(int arg0, int arg1);

    void SetTexture(int i, UnkClass_02151244 *tex);
    void DrawSlits(Camera2D *camera, int depth);
    void Spawn();

public:
    Point2D m_offset;
    CFEFRasterTransform m_rasters[3];
    UnkClass_02151244 *m_tex[3];
    Slit m_slits[2];
    s16 m_spawnTimer;
    u8 m_alpha;
    u8 m_drawAlpha;
    Fader m_fader;
    CEffectDrawObject m_drawObj;
};

STATIC_SIZE_ASSERT(CFieldEffectSpaceCrevice, 0x198);

class CFieldEffectSpaceCreviceFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectSpaceCreviceFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

    void Preload();
    BOOL LoadTexture(int i, int num, BOOL deferred);
    void ReleaseTextures();

public:
    UnkClass_02151244 m_tex[2];
};

STATIC_SIZE_ASSERT(CFieldEffectSpaceCreviceFactory, 0x5C);

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPACECREVICE_HPP
