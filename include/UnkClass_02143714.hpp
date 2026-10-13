#ifndef POKERANGER2_UNKCLASS_02143714_HPP
#define POKERANGER2_UNKCLASS_02143714_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectManageEventListener.hpp"

class CFieldEffectManage;

// Defined in FieldEffectManage.cpp (ov0): up to 4 listeners told when CFieldEffectManage::ov0_02143410 runs.
class UnkClass_02143714 {
public:
    UnkClass_02143714();
    BOOL ov0_02143730(CFieldEffectManageEventListener *listener);
    void ov0_02143760(CFieldEffectManageEventListener *listener);
    void ov0_0214378C(CFieldEffectManage *mgr);

public:
    CFieldEffectManageEventListener *m_listeners[4];
};
STATIC_SIZE_ASSERT(UnkClass_02143714, 0x10);

#endif // POKERANGER2_UNKCLASS_02143714_HPP
