#ifndef POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP
#define POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"

class CBattleDisk;
class CGame;
class CPlayerHPGauge;
class UnkClass_0201AAE0;
class UnkClass_02034478;

// Defined in ov1
class CBattleGameOver : public CActor {
public:
    CBattleGameOver(CGame *game, CBattleDisk *disk, CPlayerHPGauge *gauge);
    virtual ~CBattleGameOver();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void ov1_0213A680();
    void ov1_0213A6A0();
    void ov1_0213A77C();
    void ov1_0213A858();
    void ov1_0213A914();
    void ov1_0213A948();
    void ov1_0213A968();
    void ov1_0213A9A8(u16 duration);
    void ov1_0213A9BC();
    BOOL ov1_0213AA58();
    void ov1_0213AA70(BOOL active);
    int ov1_0213AA90(int z);
    void ov1_0213AA9C();
    void ov1_0213AAC8();
    void ov1_0213AB08();
    void ov1_0213AC30();
    void ov1_0213AC70();
    void ov1_0213AC90();
    void ov1_0213ACA4(Camera2D *camera);
    void ov1_0213AD3C(Camera2D *camera);

public:
    UnkClass_02034478 *m_audio;
    u16 m_flags;
    u16 m_state;
    u16 m_timer;
    u16 m_duration;
    u16 m_frame;
    int m_z;
    u16 m_animA;
    u16 m_animB;
    u16 m_animC;
    UnkClass_0201AAE0 *m_resA;
    UnkClass_0201AAE0 *m_resB;
    UnkClass_0201AAE0 *m_resC;
    CGame *m_game;
    CBattleDisk *m_disk;
    CPlayerHPGauge *m_gauge;
};

STATIC_SIZE_ASSERT(CBattleGameOver, 0x1B8);

#endif // POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP
