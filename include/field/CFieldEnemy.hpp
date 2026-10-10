#ifndef POKERANGER2_FIELD_CFIELDENEMY_HPP
#define POKERANGER2_FIELD_CFIELDENEMY_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"

// Defined in ov0
class CFieldEnemy : public CFieldActor {
public:
    inline Point2D GetUnk158()
    {
        return unk_158;
    }

    u32 unk_E0;
    u8 unk_E4[0x4];
    u32 unk_E8;
    u8 unk_EC[0x5A];
    u16 unk_146;
    u8 unk_148[0x10];
    Point2D unk_158;
    u8 unk_160[0x38];
    Point2D unk_198;
    u8 unk_1A0[0xA4];
    int unk_244;
    u8 unk_248[0xE];
    u16 unk_256;
};

#endif // POKERANGER2_FIELD_CFIELDENEMY_HPP
