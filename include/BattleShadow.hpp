#ifndef POKERANGER2_BATTLESHADOW_HPP
#define POKERANGER2_BATTLESHADOW_HPP

#include <nitro.h>
#include <nnsys.h>

#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"

// A textured rectangle showing data/shadow.NCBR (used by overlay 1)
class BattleShadow {
public:
    BattleShadow();
    ~BattleShadow();

    void Load();
    void Release();
    void SetRectangle(Rectangle *rect, fx32 z);
    void SetPolygonID(int id);
    void SetAlpha(int alpha);
    void Render(Camera2D *camera);

public:
    VramImage *unk_00;
    VramPalette *unk_04;
    CPrimitiveRECT *unk_08;
    NNSGfdTexKey unk_0C;
    NNSGfdPlttKey unk_10;
};

STATIC_SIZE_ASSERT(BattleShadow, 0x14);

#endif // POKERANGER2_BATTLESHADOW_HPP
