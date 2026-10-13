#ifndef POKERANGER2_UNKCLASS_021518AC_HPP
#define POKERANGER2_UNKCLASS_021518AC_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldEffectManage;
struct FieldEffectFactories;

// Owns the field effect factories (ov0)
class UnkClass_021518AC {
public:
    UnkClass_021518AC();

    ~UnkClass_021518AC()
    {
        ov0_021518F4();
    }

    void ov0_021518B8(CFieldEffectManage *mgr);
    void ov0_021518F4();

public:
    FieldEffectFactories *unk_00;
};

STATIC_SIZE_ASSERT(UnkClass_021518AC, 0x4);

#endif // POKERANGER2_UNKCLASS_021518AC_HPP
