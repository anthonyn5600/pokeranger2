#ifndef POKERANGER2_BATTLE_CBATTLEENEMYGAUGE_HPP
#define POKERANGER2_BATTLE_CBATTLEENEMYGAUGE_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_021364AC;

// Defined in ov1
class CBattleEnemyGauge : public CActor {
public:
    CBattleEnemyGauge(UnkClass_021364AC *arg0);
    virtual ~CBattleEnemyGauge();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10();
    void ov1_02135F2C(u16 hp, Point2D pos);
    int ov1_02136248(int z);
    void ov1_02135E70(int arg0, u16 arg1, u16 arg2, Point2D pos);

public:
    u8 unk_184[0x204];
};

STATIC_SIZE_ASSERT(CBattleEnemyGauge, 0x388);

#endif // POKERANGER2_BATTLE_CBATTLEENEMYGAUGE_HPP
