#ifndef POKERANGER2_FIELD_IFIELDENEMYDATABUILDER_HPP
#define POKERANGER2_FIELD_IFIELDENEMYDATABUILDER_HPP

#include <nitro.h>

// Defined in ov0
class IFieldEnemyDataBuilder {
public:
    virtual void BuildData(void *buf, int size) = 0;
};

#endif // POKERANGER2_FIELD_IFIELDENEMYDATABUILDER_HPP
