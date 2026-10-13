#ifndef POKERANGER2_FIELD_CFIELDCANNON_HPP
#define POKERANGER2_FIELD_CFIELDCANNON_HPP

#include <nitro.h>

#include "field/CFieldActor.hpp"

class CFieldCannon : public CFieldActor {
public:
    virtual ~CFieldCannon();
};

class CFieldCannonUnit : public CFieldActor {
public:
    virtual ~CFieldCannonUnit();
};

#endif // POKERANGER2_FIELD_CFIELDCANNON_HPP
