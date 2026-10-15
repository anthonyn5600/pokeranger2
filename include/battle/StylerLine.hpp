#ifndef POKERANGER2_BATTLE_STYLERLINE_HPP
#define POKERANGER2_BATTLE_STYLERLINE_HPP

#include <nitro.h>
#include <nnsys.h>

#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CPrimitiveTRIANGLE.hpp"
#include "primitive/CSoftwareSprite.hpp"

class Camera2D;
class CNCERFile;
class VramImage;
class VramPalette;
class CellAnimController;

// Defined in ov1
class NtfResource {
public:
    NtfResource(const char *ntft, const char *ntfp);
    ~NtfResource();
    void Load(const char *ntft, const char *ntfp);
    void Release();

public:
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    u32 m_texAddr;
    u32 m_plttAddr;
};

// Styler line: ring buffer of the last 0x60 segments drawn on the touch screen
class StylerLine {
public:
    StylerLine();
    ~StylerLine();

    void Load();
    void Release();
    void Render(Camera2D *camera);
    void ov1_02123770(Camera2D *camera);
    void RenderNormal(Camera2D *camera);
    void RenderPowered(Camera2D *camera);
    void Update();
    void AddSegment(fx32 x, fx32 y);
    u8 ExtendTo(fx32 x, fx32 y);
    void Reset(fx32 x, fx32 y);
    BOOL FindCrossing(PointPair2D seg);
    BOOL IsInsideLoop(fx32 x, fx32 y);
    void CutAt(u16 hit);
    void BuildLoop(u16 from, u16 to);
    u16 WrapIndex(u16 index);
    u16 GetIndex(u16 i);
    void SetMaxCount(u16 arg0);
    void LoadTypeGfx(int type);
    void ReleaseTypeGfx();
    void SetNormal();
    void SetPowerLevel1();
    void SetPowerLevel2();

public:
    int m_state;
    CPrimitiveLINE m_lines[0x60];
    CPrimitiveQUAD m_quads[0x60];
    CSoftwareSprite m_sprite0;
    CSoftwareSprite m_sprite1;
    CPrimitiveTRIANGLE m_tris[0x60];
    Point2D m_dirs[0x60];
    u16 m_count;
    u16 m_maxCount;
    u16 m_tail;
    u16 m_head;
    u16 m_hitIndex;
    u8 unk_54A6;
    fx32 m_width;
    fx32 unk_54AC;
    GXRgb m_color;
    int unk_54B4;
    int unk_54B8;
    int unk_54BC;
    u16 unk_54C0;
    u16 m_animCell;
    u16 m_animCell2;
    u32 unk_54C8;
    u32 unk_54CC;
    u8 unk_54D0;
    u8 unk_54D1;
    CPrimitiveLINE m_lines2[0x60];
    CPrimitiveRECT m_rect;
    u16 m_lines2Count;
    VramImage *m_image;
    VramPalette *m_palette;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    fx32 unk_6428;
    CNCERFile *m_cells;
    CellAnimController *m_anim;
    u8 unk_6434[0x58];
    VramImage *m_image2;
    VramPalette *m_palette2;
    NNSGfdTexKey m_texKey2;
    NNSGfdPlttKey m_plttKey2;
    CNCERFile *m_cells2;
    CellAnimController *m_anim2;
    u8 unk_64A4[0x58];
    NtfResource *unk_64FC;
    NtfResource *unk_6500;
};

STATIC_SIZE_ASSERT(StylerLine, 0x6504);

#endif // POKERANGER2_BATTLE_STYLERLINE_HPP
