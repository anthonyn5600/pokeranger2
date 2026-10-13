#ifndef POKERANGER2_FIELD_CFEFRASTERTRANSFORM_HPP
#define POKERANGER2_FIELD_CFEFRASTERTRANSFORM_HPP

#include <nitro.h>

#include "primitive/CPrimitive.hpp"

class CFEFRasterTransform : public CPrimitive {
public:
    virtual ~CFEFRasterTransform();
    virtual u32 Render(Camera2D *camera);
};

#endif // POKERANGER2_FIELD_CFEFRASTERTRANSFORM_HPP
