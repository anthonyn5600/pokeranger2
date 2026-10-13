#ifndef POKERANGER2_FIELD_CMESHSPRITE_HPP
#define POKERANGER2_FIELD_CMESHSPRITE_HPP

#include <nitro.h>

#include "primitive/CPrimitive.hpp"

class CMeshSprite : public CPrimitive {
public:
    virtual ~CMeshSprite();
    virtual u32 Render(Camera2D *camera);
};

#endif // POKERANGER2_FIELD_CMESHSPRITE_HPP
