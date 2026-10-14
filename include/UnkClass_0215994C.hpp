#ifndef POKERANGER2_UNKCLASS_0215994C_HPP
#define POKERANGER2_UNKCLASS_0215994C_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldCannon.hpp"

// Cannons of the field scene (CFieldScene::unk_005C)
class UnkClass_0215994C {
public:
    UnkClass_0215994C();
    ~UnkClass_0215994C();

    void ov0_02159970();
    int ov0_02159B24();
    int ov0_02159B5C();
    int ov0_02159B84(int type, int index, int mode);
    void ov0_02159CA8();
    void ov0_02159D70();
    void ov0_02159D7C();
    void ov0_02159DB4(UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud);
    CFieldCannon *ov0_02159DFC(int index);

public:
    u16 unk_00; // used slots
    u16 unk_02; // slots handed out
    CFieldCannon *unk_04[10];
};

STATIC_SIZE_ASSERT(UnkClass_0215994C, 0x2C);

void ov0_02159D30(u16 type);

#endif // POKERANGER2_UNKCLASS_0215994C_HPP
