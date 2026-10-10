#ifndef POKERANGER2_UNKCLASS_0214F9DC_HPP
#define POKERANGER2_UNKCLASS_0214F9DC_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;

// Defined in ov0
class UnkClass_0214F9DC {
public:
    UnkClass_0214F9DC(CGame *game);
    ~UnkClass_0214F9DC();

public:
    u8 unk_00[0x14];
};

STATIC_SIZE_ASSERT(UnkClass_0214F9DC, 0x14);

#endif // POKERANGER2_UNKCLASS_0214F9DC_HPP
