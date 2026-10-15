#ifndef POKERANGER2_BATTLE_CLINEEFFECT_HPP
#define POKERANGER2_BATTLE_CLINEEFFECT_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"

// Defined in ov1
class CLineEffect : public CActor {
public:
    CLineEffect();
    virtual ~CLineEffect();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void Load();
    void Release();
    void Setup(fx32 arg0, fx32 arg1, CActor *leader);

public:
    CActorData *unk_184;
    u8 unk_188[0x8];
    CActor *m_leader;
    fx32 unk_194;
    fx32 unk_198;
};

STATIC_SIZE_ASSERT(CLineEffect, 0x19C);

#endif // POKERANGER2_BATTLE_CLINEEFFECT_HPP
