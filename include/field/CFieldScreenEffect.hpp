#ifndef POKERANGER2_FIELD_CFIELDSCREENEFFECT_HPP
#define POKERANGER2_FIELD_CFIELDSCREENEFFECT_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "UnkClass_02003718.hpp"
#include "common.hpp"
#include "field/CPrimitiveNTF.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02006000.hpp"

class CFieldScreenEffectActorData;

class CFieldScreenEffectObjectBase {
public:
    enum State {
        STATE_FADE_START = 2,
        STATE_FADE_IN = 3,
        STATE_SHOWN = 4,
        STATE_FADE_OUT = 5,
        STATE_FADE_END = 6,
        STATE_DONE = 7,
    };

    CFieldScreenEffectObjectBase()
    {
        unk_1C = 4;
    }

    virtual ~CFieldScreenEffectObjectBase()
    {
    }
    virtual int GetType()
    {
        return 0;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera)
    {
    }
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);
    virtual BOOL Stop(int fadeOut);

    void SetupMatrix(UnkClass_02003718 *camera);

    static void InitScroll();
    static void UpdateScroll();

    static int s_frameStep;
    static Point2D s_scroll;

public:
    int m_state; // 0x04
    int m_timer; // 0x08
    int m_fadeIn; // 0x0C
    int m_hold; // 0x10
    int m_fadeOut; // 0x14
    fx32 m_alpha; // 0x18
    int unk_1C;
};

STATIC_SIZE_ASSERT(CFieldScreenEffectObjectBase, 0x20);

struct SnowFlake {
    Point2D pos;
    Point2D basePos;
    Point2D vel;
    Point2D baseVel;
    u8 phase;
    u8 timer;
    u8 type;
    u16 angle;
};

STATIC_SIZE_ASSERT(SnowFlake, 0x28);

class CFieldSEFSnow : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFSnow();
    virtual ~CFieldSEFSnow()
    {
        Unload();
    }
    virtual int GetType()
    {
        return 14;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();

    CFieldScreenEffectActorData *m_actorData;
    CSoftwareSprite *m_sprite;
    u16 m_cells[8];
    SnowFlake m_flakes[32];
    NtfTexture m_tex;
    CPrimitiveRectNTF m_rect;
    int m_density;
    int unk_594;
    int unk_598;
};

STATIC_SIZE_ASSERT(CFieldSEFSnow, 0x59C);

// Defined after CFieldSEFSnow and before CFieldSEFHinoko: mwcc orders same-size data objects by where their
// classes are defined (Hinoko's typeinfo before this one's, Snow's speed table before Snow's typeinfo).
class CFieldScreenEffectActorData : public CEffectActorData {
public:
    virtual void Update()
    {
        if (GetCac(0) != NULL) {
            GetCac(0)->sub_020089EC();
        }
    }

    BOOL Load(int id);
};

struct HinokoSpark {
    Point2D pos;
    Point2D vel;
    Point2D baseVel;
    u8 phase;
    u8 timer;
};

STATIC_SIZE_ASSERT(HinokoSpark, 0x1C);

class CFieldSEFHinoko : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFHinoko(BOOL withSparks);
    virtual ~CFieldSEFHinoko()
    {
        Unload();
    }
    virtual int GetType()
    {
        return m_withSparks ? 1 : 12;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();

    CFieldScreenEffectActorData *m_actorData;
    CSoftwareSprite *m_sprite;
    u16 m_cells[8];
    u16 m_bigCell;
    HinokoSpark m_sparks1[16];
    HinokoSpark m_sparks2[16];
    int m_releaseDelay;
    NtfTexture m_tex;
    CPrimitiveRectNTF m_rect;
    int m_density;
    BOOL m_withSparks;
    fx32 m_s;
    fx32 m_t;
};

STATIC_SIZE_ASSERT(CFieldSEFHinoko, 0x428);

class CFieldSEFRainDrop {
public:
    int m_mode; // 0: off, 1: falling, 2: streak
    CPrimitiveLINE m_line;
};

STATIC_SIZE_ASSERT(CFieldSEFRainDrop, 0x2C);

struct RainSplash {
    BOOL active;
    Point2D pos;
};

STATIC_SIZE_ASSERT(RainSplash, 0xC);

class CFieldSEFRain : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFRain()
    {
        Load();
    }
    virtual ~CFieldSEFRain()
    {
        Unload();
    }
    virtual int GetType()
    {
        return 2;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut)
    {
        BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
        ResetDrops();
        return result;
    }

    BOOL Load();
    BOOL Unload();
    void ResetDrops();

    CFieldSEFRainDrop m_drops[32];
    RainSplash m_splashes[16];
    CFieldScreenEffectActorData *m_actorData;
    CSoftwareSprite *m_sprite;
    u16 m_cells[8];
};

STATIC_SIZE_ASSERT(CFieldSEFRain, 0x678);

struct KomorebiRay {
    fx32 len;
    u16 alpha;
    u16 angle;
    u16 speed;
    GXRgb color;
};

class CFieldSEFKomorebi : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFKomorebi();
    virtual ~CFieldSEFKomorebi();
    virtual int GetType()
    {
        return 3;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();
    void sub_02037330(int arg);

public:
    int unk_20;
    fx32 m_drawAlpha;
    int m_releaseDelay;
    NtfTexture m_tex;
    CPrimitiveQuadNTF m_quad;
    KomorebiRay m_rays[9];
};

STATIC_SIZE_ASSERT(CFieldSEFKomorebi, 0x110);

struct FogParam {
    GXRgb color;
    int density;
};

class CFieldSEFFog : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFFog(int type);
    virtual ~CFieldSEFFog()
    {
        Unload();
    }
    virtual int GetType()
    {
        return m_type;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();

    static int GetDensity()
    {
        return s_density;
    }
    static void SetDensity(int density)
    {
        s_density = density;
        s_dirty = TRUE;
    }
    static int GetColorR()
    {
        return s_color[0];
    }
    static void SetColorR(int r)
    {
        s_color[0] = r;
        s_dirty = TRUE;
    }
    static int GetColorG()
    {
        return s_color[1];
    }
    static void SetColorG(int g)
    {
        s_color[1] = g;
        s_dirty = TRUE;
    }
    static int GetColorB()
    {
        return s_color[2];
    }
    static void SetColorB(int b)
    {
        s_color[2] = b;
        s_dirty = TRUE;
    }

    static BOOL s_dirty;
    static int s_density;
    static int s_color[3];

    int m_releaseDelay;
    NtfTexture m_tex[2];
    CPrimitiveRectNTF m_rect;
    fx32 m_s[2];
    fx32 m_t[2];
    int m_type;
    int m_density;
    int m_flickerTimer;
};

STATIC_SIZE_ASSERT(CFieldSEFFog, 0xB4);

struct SandStormLayer {
    fx32 s;
    fx32 t;
    fx32 ds;
    fx32 dt;
};

class CFieldSEFSandStorm : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFSandStorm();
    virtual ~CFieldSEFSandStorm()
    {
        Unload();
    }
    virtual int GetType()
    {
        return 8;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();

    NtfTexture m_tex[2];
    u8 unk_58[0x10];
    SandStormLayer m_layers[2];
    int unk_88;
    int m_density;
    int m_frame;
    int m_releaseDelay;
    CPrimitiveRectNTF m_rect;
};

STATIC_SIZE_ASSERT(CFieldSEFSandStorm, 0xD4);

class CFieldSEFDokarimo : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFDokarimo();
    virtual ~CFieldSEFDokarimo()
    {
        Unload();
    }
    virtual int GetType()
    {
        return 9;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();
    void SetGridPoint(int index, fx32 x, fx32 y);

    NtfTexture m_tex;
    NtfTexture m_rectTex;
    int unk_58;
    int m_density;
    int m_rectDensity;
    int m_releaseDelay;
    CPrimitiveRectNTF m_rect;
    CPrimitiveQuadNTF m_quads[16];
    u16 m_angles[3];
};

STATIC_SIZE_ASSERT(CFieldSEFDokarimo, 0x66C);

class CFieldSEFTheWater : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFTheWater(int type);
    virtual ~CFieldSEFTheWater()
    {
        Unload();
    }
    virtual int GetType()
    {
        return m_type;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();

    NtfTexture m_tex;
    int m_type;
    int m_density;
    CPrimitiveRectNTF m_rect;
};

STATIC_SIZE_ASSERT(CFieldSEFTheWater, 0x80);

class CFieldSEFWarning : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFWarning();
    virtual ~CFieldSEFWarning()
    {
        Unload();
    }
    virtual int GetType()
    {
        return 13;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);

    BOOL Load();
    BOOL Unload();

    NtfTexture m_tex;
    int unk_3C;
    int m_density;
    int m_pulseTimer;
    int m_pulsePeriod;
    CPrimitiveRectNTF m_rect;
};

STATIC_SIZE_ASSERT(CFieldSEFWarning, 0x88);

class CFieldSEFDarkness : public CFieldScreenEffectObjectBase {
public:
    CFieldSEFDarkness(int type);
    virtual ~CFieldSEFDarkness()
    {
        Unload();
    }
    virtual int GetType()
    {
        return m_type;
    }
    virtual int Update(int fps);
    virtual void Draw(UnkClass_02003718 *camera);
    virtual BOOL Start(int fadeIn, int hold, int fadeOut);

    BOOL Load();
    BOOL Unload();
    void SetGridPoint(int index, fx32 x, fx32 y);

    NtfTexture m_tex;
    NtfTexture m_rectTex;
    int m_type;
    int m_density;
    int m_rectDensity;
    int m_releaseDelay;
    CPrimitiveRectNTF m_rect;
    CPrimitiveQuadNTF m_quads[16];
    u16 m_angles[3];
};

#endif // POKERANGER2_FIELD_CFIELDSCREENEFFECT_HPP
