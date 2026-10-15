#ifndef POKERANGER2_FIELDTIMERDISPLAY_HPP
#define POKERANGER2_FIELDTIMERDISPLAY_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"

class GraphicsSet;

// The field's play-time display (mm:ss), drawn glyph by glyph with one textured rectangle.
class FieldTimerDisplay {
public:
    void Init(GraphicsSet *gfx);
    void Draw(int time, fx32 z, Camera2D *camera);

    CPrimitiveRECT unk_00;
};

STATIC_SIZE_ASSERT(FieldTimerDisplay, 0x40);

#endif // POKERANGER2_FIELDTIMERDISPLAY_HPP
