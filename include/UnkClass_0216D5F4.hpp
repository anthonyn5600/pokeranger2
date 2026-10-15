#ifndef POKERANGER2_UNKCLASS_0216D5F4_HPP
#define POKERANGER2_UNKCLASS_0216D5F4_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"

class GraphicsSet;

// The field's play-time display (mm:ss), drawn glyph by glyph with one textured rectangle.
class UnkClass_0216D5F4 {
public:
    void Init(GraphicsSet *gfx);
    void Draw(int time, fx32 z, Camera2D *camera);

    CPrimitiveRECT unk_00;
};

STATIC_SIZE_ASSERT(UnkClass_0216D5F4, 0x40);

#endif // POKERANGER2_UNKCLASS_0216D5F4_HPP
