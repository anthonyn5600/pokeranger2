#ifndef POKERANGER2_FIELDSHADOW_HPP
#define POKERANGER2_FIELDSHADOW_HPP

#include <nitro.h>
#include <nnsys.h>

#include "Collision.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"

class Camera2D;

// Actor shadows of the field (CFieldScene::unk_0048): data/shadow.NCBR drawn as one quad per queued rectangle.
struct ShadowEntry {
    Rectangle rect;
    int layer;
};

class FieldShadow {
public:
    FieldShadow(int layerCount);
    ~FieldShadow();
    void Load();
    void Release();

public:
    VramImage *unk_00;
    VramPalette *unk_04;
    CPrimitiveRECT *unk_08;
    NNSGfdTexKey unk_0C;
    NNSGfdPlttKey unk_10;
    ShadowEntry unk_14[0x73];
    int unk_910;
    int unk_914;
};

STATIC_SIZE_ASSERT(FieldShadow, 0x918);

extern "C" {
void sub_02041920(FieldShadow *obj);
void FieldShadow_Render(FieldShadow *obj, Camera2D *camera, int layer, int z);
void FieldShadow_Clear(FieldShadow *obj);
void FieldShadow_Add(FieldShadow *obj, int layer, Rectangle rect);
void FieldShadow_SetAlpha(FieldShadow *obj, u8 alpha);
}

#endif // POKERANGER2_FIELDSHADOW_HPP
