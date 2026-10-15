#ifndef POKERANGER2_FIELDEFFECTLISTENERS_HPP
#define POKERANGER2_FIELDEFFECTLISTENERS_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectManageEventListener.hpp"

class CFieldEffectManage;

// Defined in FieldEffectManage.cpp (ov0): up to 4 listeners told when CFieldEffectManage::NotifyListeners runs.
class FieldEffectListeners {
public:
    FieldEffectListeners();
    BOOL Add(CFieldEffectManageEventListener *listener);
    void Remove(CFieldEffectManageEventListener *listener);
    void Notify(CFieldEffectManage *mgr);

public:
    CFieldEffectManageEventListener *m_listeners[4];
};
STATIC_SIZE_ASSERT(FieldEffectListeners, 0x10);

#endif // POKERANGER2_FIELDEFFECTLISTENERS_HPP
