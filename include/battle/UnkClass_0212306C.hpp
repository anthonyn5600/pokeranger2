#ifndef POKERANGER2_BATTLE_UNKCLASS_0212306C_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212306C_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CPrimitiveTRIANGLE.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02006000.hpp"

class Camera2D;
class CNCERFile;
class UnkClass_020074D4;
class UnkClass_02007AA4;
class UnkClass_02008788;

// Defined in ov1
class UnkClass_0213F9D0 {
public:
    UnkClass_0213F9D0(const char *ntft, const char *ntfp);
    ~UnkClass_0213F9D0();
    void Load(const char *ntft, const char *ntfp);
    void Release();

public:
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    u32 m_texAddr;
    u32 m_plttAddr;
};

// Styler line: ring buffer of the last 0x60 segments drawn on the touch screen
class UnkClass_0212306C {
public:
    UnkClass_0212306C();
    ~UnkClass_0212306C();

    void ov1_021232CC();
    void ov1_021235E8();
    void ov1_0212372C(Camera2D *camera);
    void ov1_02123770(Camera2D *camera);
    void ov1_02123774(Camera2D *camera);
    void ov1_02123A9C(Camera2D *camera);
    void ov1_0212402C();
    void ov1_021242D0(fx32 x, fx32 y);
    u8 ov1_021243CC(fx32 x, fx32 y);
    void ov1_02124548(fx32 x, fx32 y);
    BOOL ov1_02124588(PointPair2D seg);
    BOOL ov1_02124650(fx32 x, fx32 y);
    void ov1_02124828(u16 hit);
    void ov1_021248E8(u16 from, u16 to);
    u16 ov1_02124AB8(u16 index);
    u16 ov1_02124AD4(u16 i);
    void ov1_02124AF4(u16 arg0);
    void ov1_02124B08(int type);
    void ov1_02124DEC();
    void ov1_02124F08();
    void ov1_02124F64();
    void ov1_02124F84();

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
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    fx32 unk_6428;
    CNCERFile *m_cells;
    UnkClass_02008788 *m_anim;
    u8 unk_6434[0x58];
    UnkClass_020074D4 *m_image2;
    UnkClass_02007AA4 *m_palette2;
    NNSGfdTexKey m_texKey2;
    NNSGfdPlttKey m_plttKey2;
    CNCERFile *m_cells2;
    UnkClass_02008788 *m_anim2;
    u8 unk_64A4[0x58];
    UnkClass_0213F9D0 *unk_64FC;
    UnkClass_0213F9D0 *unk_6500;
};

STATIC_SIZE_ASSERT(UnkClass_0212306C, 0x6504);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212306C_HPP
