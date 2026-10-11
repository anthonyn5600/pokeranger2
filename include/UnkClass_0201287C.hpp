#ifndef POKERANGER2_UNKCLASS_0201287C_HPP
#define POKERANGER2_UNKCLASS_0201287C_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"
#include "sub_02006000.hpp"

// TODO: Figure out which CActor subclass this is (CFieldDrawActor?)
class UnkClass_0201287C : public CActor {
public:
    inline void sub_reset()
    {
        unk_1DC = 3;
        unk_1E1 = 0;
    }

    inline void SetXY(fx32 x, fx32 y)
    {
        m_motion.sub_02011D1C(x);
        m_motion.sub_02011D2C(y);
    }

    inline void sub_show()
    {
        unk_1DC = 0;
        unk_1E1 = 0;
    }

    inline void SetUnk1DC(int value)
    {
        unk_1DC = value;
        unk_1E1 = 0;
    }

    inline void StartBlink()
    {
        unk_1A8 |= 2;
        unk_1B8 = 0x1F;
        unk_1C6 = 0x1F;
    }

public:
    u8 unk_184[0x1C];
    int unk_1A0;
    int unk_1A4;
    u32 unk_1A8;
    u8 unk_1AC[0xC];
    u16 unk_1B8;
    u8 unk_1BA[0xC];
    u8 unk_1C6;
    u8 unk_1C7[0x11];
    int unk_1D8;
    int unk_1DC;
    u8 unk_1E0;
    u8 unk_1E1;
};

#endif // POKERANGER2_UNKCLASS_0201287C_HPP
