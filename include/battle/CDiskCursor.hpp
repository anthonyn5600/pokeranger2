#ifndef POKERANGER2_BATTLE_CDISKCURSOR_HPP
#define POKERANGER2_BATTLE_CDISKCURSOR_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"

// Defined in ov1
class CDiskCursor : public CActor {
public:
    CDiskCursor();
    virtual ~CDiskCursor();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);
    void ov1_0212E410();
    void ov1_0212E45C();

public:
    CActorData *unk_184;
    u8 unk_188[0x8];
};

STATIC_SIZE_ASSERT(CDiskCursor, 0x190);

#endif // POKERANGER2_BATTLE_CDISKCURSOR_HPP
