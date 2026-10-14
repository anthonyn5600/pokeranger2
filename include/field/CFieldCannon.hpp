#ifndef POKERANGER2_FIELD_CFIELDCANNON_HPP
#define POKERANGER2_FIELD_CFIELDCANNON_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"

class CFieldCannonUnit;
class CFieldPlayer;
class AudioEngine;

// Shot settings of a cannon (CFieldCannon::unk_EC); each shot copies them into a unit (ov0_0215AAA4).
struct FieldCannonParam {
    u16 unk_00; // angle
    u16 unk_02; // frames between shots
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    u16 unk_0C; // flags: 1 = active, 4 = no auto fire
    u16 unk_0E;
    fx32 unk_10; // speed
    Circle unk_14; // pos, radius
};

STATIC_SIZE_ASSERT(FieldCannonParam, 0x20);

// State of one shot (CFieldCannonUnit::unk_E8).
struct FieldCannonUnitParam {
    u16 unk_00; // angle
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08; // lifetime
    u16 unk_0A; // flags: 1 = active, 2 = hit
    u16 unk_0C;
    fx32 unk_10; // speed
    Circle unk_14; // pos, radius
};

STATIC_SIZE_ASSERT(FieldCannonUnitParam, 0x20);

class CFieldCannon : public CFieldActor {
public:
    CFieldCannon(u16 type);
    virtual ~CFieldCannon();

    void ov0_02159ED0();
    void ov0_02159F28();
    void ov0_02159F88();
    void ov0_0215A010();
    void ov0_0215A25C(DrawObjectList *renderLists, FieldShadow *hud);
    BOOL ov0_0215A2BC();
    BOOL ov0_0215A33C(u16 *index);
    void ov0_0215A384(BOOL active);
    BOOL ov0_0215A3A4();
    void ov0_0215A3BC(int x, int y);
    void ov0_0215A3D4(int angle, int speed, int interval, int arg4, int arg5, int arg6, int arg7, int arg8);
    void ov0_0215A434(FieldCannonParam *param, u16 frame, u16 index);

    u16 unk_E0;
    u16 unk_E2;
    u16 unk_E4;
    u8 unk_E6[0x2];
    AudioEngine *unk_E8;
    FieldCannonParam *unk_EC;
    CFieldCannonUnit *unk_F0[4];
};

STATIC_SIZE_ASSERT(CFieldCannon, 0x100);

class CFieldCannonUnit : public CFieldActor {
public:
    CFieldCannonUnit(u16 type);
    virtual ~CFieldCannonUnit();

    void ov0_0215A5A4();
    void ov0_0215A604();
    void ov0_0215A628();
    void ov0_0215A698();
    void ov0_0215AA60(BOOL active);
    BOOL ov0_0215AA80();
    void ov0_0215AA98(u16 flags);
    void ov0_0215AAA4(FieldCannonParam *param);
    void ov0_0215ABA4();
    FieldCannonUnitParam *ov0_0215ABF0();

    u16 unk_E0;
    u16 unk_E2;
    CFieldPlayer *unk_E4;
    FieldCannonUnitParam *unk_E8;
};

STATIC_SIZE_ASSERT(CFieldCannonUnit, 0xEC);

#endif // POKERANGER2_FIELD_CFIELDCANNON_HPP
