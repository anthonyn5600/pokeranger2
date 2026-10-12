#ifndef POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP
#define POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"

class CBattleDisk;
class CGame;
class CPlayerHPGauge;

// Defined in ov1
class CBattleGameOver : public CActor {
public:
    CBattleGameOver(CGame *game, CBattleDisk *disk, CPlayerHPGauge *gauge);
    virtual ~CBattleGameOver();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    BOOL ov1_0213AA58();
    void ov1_0213AC30();
    int ov1_0213AA90(int z);

public:
    u8 unk_184[0x34];
};

STATIC_SIZE_ASSERT(CBattleGameOver, 0x1B8);

#endif // POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP
