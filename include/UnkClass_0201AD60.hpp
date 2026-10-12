#ifndef POKERANGER2_UNKCLASS_0201AD60_HPP
#define POKERANGER2_UNKCLASS_0201AD60_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CPrimitiveTRIANGLE.hpp"

class Camera2D;

// A grid overlay: a backdrop rectangle, 16 vertical and 12 horizontal lines (flat triangles) and 22 horizontal
// bars that scroll with CGame::unk_15D0; opens/closes by fading (used by overlay 1 and UnkClass_020233C8?)
class UnkClass_0201AD60 {
public:
    UnkClass_0201AD60();
    ~UnkClass_0201AD60();

    void Update();
    void UpdateOpen();
    void UpdateClose();
    void Reset();
    void Render(Camera2D *camera);
    void Open();
    void Close();
    void Show();
    void SetZ(fx32 backZ, fx32 linesZ, fx32 barsZ);
    void SetPolygonID(int backID, int linesID, int barsID);
    void SetVLinesAlpha(int alpha);
    void SetHLinesAlpha(int alpha);
    void SetBarsAlpha(int alpha);

public:
    u8 unk_00;
    u8 unk_01;
    int unk_04;
    u8 unk_08;
    CPrimitiveRECT *unk_0C;
    CPrimitiveTRIANGLE *unk_10[16];
    CPrimitiveTRIANGLE *unk_50[12];
    CPrimitiveRECT *unk_80[22];
};

STATIC_SIZE_ASSERT(UnkClass_0201AD60, 0xD8);

#endif // POKERANGER2_UNKCLASS_0201AD60_HPP
