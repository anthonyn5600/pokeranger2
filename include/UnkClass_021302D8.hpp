#ifndef POKERANGER2_UNKCLASS_021302D8_HPP
#define POKERANGER2_UNKCLASS_021302D8_HPP

#include <dwc.h>

#include "common.hpp"

class CGame;

// Defined in ov11, owned by UnkClass_0211E05C::unk_718 (DWC connection)
class UnkClass_021302D8 {
public:
    UnkClass_021302D8(CGame *game);
    ~UnkClass_021302D8();
    void ov11_02130310();
    int ov11_0213031C();
    void ov11_0213038C();
    int ov11_02130398();
    void ov11_021304B4();

public:
    u16 unk_00; // connection state
    DWCInetControl unk_04;
    CGame *unk_10;
    void *unk_14; // DWC_Init work
};

STATIC_SIZE_ASSERT(UnkClass_021302D8, 0x18);

#endif // POKERANGER2_UNKCLASS_021302D8_HPP
