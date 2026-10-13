#ifndef POKERANGER2_FIELD_CFIELDPLAYERINPUTCONTROLMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDPLAYERINPUTCONTROLMANAGE_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldScene;
class CTouchPanel;
class UnkClass_02001C04;

// FieldPlayerInputControlManage.cpp (ov0): A button and touch input on the field (talk, check, capture, partner moves)
class CFieldPlayerInputControlManage {
public:
    CFieldPlayerInputControlManage();
    virtual ~CFieldPlayerInputControlManage();

    BOOL ov0_0213FFC4(CFieldScene *scene, UnkClass_02001C04 *pad, CTouchPanel *touch);

public:
    u16 unk_04;
};

STATIC_SIZE_ASSERT(CFieldPlayerInputControlManage, 0x8);

extern CFieldPlayerInputControlManage *MAIN_BSS_0210CA70;

#endif // POKERANGER2_FIELD_CFIELDPLAYERINPUTCONTROLMANAGE_HPP
