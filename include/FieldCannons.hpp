#ifndef POKERANGER2_FIELDCANNONS_HPP
#define POKERANGER2_FIELDCANNONS_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldCannon.hpp"

// Cannons of the field scene (CFieldScene::unk_005C)
class FieldCannons {
public:
    FieldCannons();
    ~FieldCannons();

    void RestoreSaved();
    int ov0_02159B24();
    int FindFreeSlot();
    int CreateCannon(int type, int index, int mode);
    void Release();
    void Clear();
    void Update();
    void Draw(DrawObjectList *renderLists, FieldShadow *hud);
    CFieldCannon *GetCannon(int index);

public:
    u16 unk_00; // used slots
    u16 unk_02; // slots handed out
    CFieldCannon *unk_04[10];
};

STATIC_SIZE_ASSERT(FieldCannons, 0x2C);

void ov0_02159D30(u16 type);

#endif // POKERANGER2_FIELDCANNONS_HPP
