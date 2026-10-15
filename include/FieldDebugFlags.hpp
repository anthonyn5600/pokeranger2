#ifndef POKERANGER2_FIELDDEBUGFLAGS_HPP
#define POKERANGER2_FIELDDEBUGFLAGS_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0
class FieldDebugFlags {
public:
    FieldDebugFlags();
    ~FieldDebugFlags();

public:
    u32 unk_00;
};

STATIC_SIZE_ASSERT(FieldDebugFlags, 0x4);

#endif // POKERANGER2_FIELDDEBUGFLAGS_HPP
