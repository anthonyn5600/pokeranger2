#ifndef POKERANGER2_UNKCLASS_020416AC_HPP
#define POKERANGER2_UNKCLASS_020416AC_HPP

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "sub_02006000.hpp"

class Camera2D;

// Actor shadows of the field (CFieldScene::unk_0048): data/shadow.NCBR drawn as one quad per queued rectangle.
struct ShadowEntry {
    Rectangle rect;
    int layer;
};

class UnkClass_020416AC {
public:
    UnkClass_020416AC(int layerCount);
    ~UnkClass_020416AC();
    void Load();
    void Release();

public:
    UnkClass_020074D4 *unk_00;
    UnkClass_02007AA4 *unk_04;
    CPrimitiveRECT *unk_08;
    NNSGfdTexKey unk_0C;
    NNSGfdPlttKey unk_10;
    ShadowEntry unk_14[0x73];
    int unk_910;
    int unk_914;
};

STATIC_SIZE_ASSERT(UnkClass_020416AC, 0x918);

extern "C" {
void sub_02041920(UnkClass_020416AC *obj);
void sub_02041924(UnkClass_020416AC *obj, Camera2D *camera, int layer, int z);
void sub_020419AC(UnkClass_020416AC *obj);
void sub_020419D8(UnkClass_020416AC *obj, int layer, Rectangle rect);
void sub_02041A60(UnkClass_020416AC *obj, u8 alpha);
}

#endif // POKERANGER2_UNKCLASS_020416AC_HPP
