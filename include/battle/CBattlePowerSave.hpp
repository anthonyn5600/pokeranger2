#ifndef POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP
#define POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"

// Defined in ov1
class CBattlePowerSave : public CActor {
public:
    CBattlePowerSave();
    virtual ~CBattlePowerSave();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    u16 ov1_02137AD4();

    inline void SetUnkC74(u16 a, u16 b)
    {
        unk_C74 = a;
        unk_C76 = b;
    }

public:
    u8 unk_184[0xAED];
    u8 unk_C71;
    u8 unk_C72[0x2];
    u16 unk_C74;
    u16 unk_C76;
    u8 unk_C78[0x8];
};

STATIC_SIZE_ASSERT(CBattlePowerSave, 0xC80);

#endif // POKERANGER2_BATTLE_CBATTLEPOWERSAVE_HPP
