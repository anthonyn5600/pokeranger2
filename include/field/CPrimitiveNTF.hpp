#ifndef POKERANGER2_FIELD_CPRIMITIVENTF_HPP
#define POKERANGER2_FIELD_CPRIMITIVENTF_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "file/CBinaryFile.hpp"
#include "primitive/CPrimitive.hpp"
#include "sub_02006000.hpp"

struct NtfTextureFormat {
    GXTexFmt texFmt;
    GXTexGen texGen;
    GXTexSizeS sizeS;
    GXTexSizeT sizeT;
    GXTexRepeat repeat;
    GXTexFlip flip;
    GXTexPlttColor0 plttColor0;
};

extern NtfTextureFormat g_ntfTextureFormats[6];

// Texture from a .ntft/.ntfp file pair in texture VRAM
class NtfTexture {
public:
    NtfTexture()
    {
        m_texKey = 0;
        m_plttKey = 0;
        m_texAddr = 0;
        m_plttAddr = 0;
        m_format = &g_ntfTextureFormats[0];
        m_ntft = NULL;
        m_ntfp = NULL;
    }

    ~NtfTexture()
    {
        Release();
    }

    BOOL Load(const char *texPath, const char *plttPath, int format);
    BOOL LoadDeferred(const char *texPath, const char *plttPath, int format);
    void ReleaseFiles();
    BOOL Release();
    void Bind();

public:
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    u32 m_texAddr;
    u32 m_plttAddr;
    NtfTextureFormat *m_format;
    CBinaryFile *m_ntft;
    CBinaryFile *m_ntfp;
};

STATIC_SIZE_ASSERT(NtfTexture, 0x1C);

class CPrimitiveRectNTF : public CPrimitive {
public:
    CPrimitiveRectNTF()
    {
        unk_18 = NULL;
    }

    virtual ~CPrimitiveRectNTF()
    {
    }
    virtual u32 Render(CPrimitive_Render_arg *arg0);

    void SetRect(fx32 x, fx32 y, fx32 width, fx32 height)
    {
        m_x = x;
        m_y = y;
        m_width = width;
        m_height = height;
    }

    void SetTexCoords(fx32 s1, fx32 t1, fx32 s2, fx32 t2)
    {
        m_s1 = s1;
        m_t1 = t1;
        m_s2 = s2;
        m_t2 = t2;
    }

public:
    void *unk_18;
    fx32 m_x;
    fx32 m_y;
    fx32 m_width;
    fx32 m_height;
    fx32 m_s1;
    fx32 m_t1;
    fx32 m_s2;
    fx32 m_t2;
};

STATIC_SIZE_ASSERT(CPrimitiveRectNTF, 0x3C);

class CPrimitiveQuadNTF : public CPrimitive {
public:
    CPrimitiveQuadNTF()
    {
        unk_18 = NULL;
    }

    virtual ~CPrimitiveQuadNTF()
    {
    }
    virtual u32 Render(CPrimitive_Render_arg *arg0);

public:
    void *unk_18;
    Point2D m_vtx[4];
    Point2D m_tex[4];
};

STATIC_SIZE_ASSERT(CPrimitiveQuadNTF, 0x5C);

#endif // POKERANGER2_FIELD_CPRIMITIVENTF_HPP
