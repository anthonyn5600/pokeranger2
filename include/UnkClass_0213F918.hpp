#ifndef POKERANGER2_UNKCLASS_0213F918_HPP
#define POKERANGER2_UNKCLASS_0213F918_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldActor;
class CGame;

// Defined in ov0
class UnkClass_0213F918 {
public:
    UnkClass_0213F918(CGame *game);
    ~UnkClass_0213F918();

public:
    u8 unk_00[0x64];
};

STATIC_SIZE_ASSERT(UnkClass_0213F918, 0x64);

extern UnkClass_0213F918 *MAIN_BSS_0210CA44;

extern "C" {
void ov0_0213F960(UnkClass_0213F918 *obj);
void ov0_0213FB0C(UnkClass_0213F918 *obj, const char *name, int arg2, int arg3);
void ov0_0213FC24(UnkClass_0213F918 *obj, CFieldActor *actor, const char *func, int arg3);
}

#endif // POKERANGER2_UNKCLASS_0213F918_HPP
