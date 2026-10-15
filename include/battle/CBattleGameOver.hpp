#ifndef POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP
#define POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "common.hpp"

class CBattleDisk;
class CGame;
class CPlayerHPGauge;
class GraphicsSet;
class AudioEngine;

// Defined in ov1
class CBattleGameOver : public CActor {
public:
    CBattleGameOver(CGame *game, CBattleDisk *disk, CPlayerHPGauge *gauge);
    virtual ~CBattleGameOver();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void LoadGraphics();
    void LoadResA();
    void LoadResB();
    void LoadResC();
    void ov1_0213A914();
    void StartWhiteOut();
    void StartWhiteIn();
    void StartWait(u16 duration);
    void EnterState();
    BOOL IsActive();
    void SetActive(BOOL active);
    int SetZ(int z);
    void WaitMainFade();
    void WaitFades();
    void WaitTimer();
    void Start();
    void NextState();
    void Finish();
    void DrawResA(Camera2D *camera);
    void DrawResC(Camera2D *camera);

public:
    AudioEngine *m_audio;
    u16 m_flags;
    u16 m_state;
    u16 m_timer;
    u16 m_duration;
    u16 m_frame;
    int m_z;
    u16 m_animA;
    u16 m_animB;
    u16 m_animC;
    GraphicsSet *m_resA;
    GraphicsSet *m_resB;
    GraphicsSet *m_resC;
    CGame *m_game;
    CBattleDisk *m_disk;
    CPlayerHPGauge *m_gauge;
};

STATIC_SIZE_ASSERT(CBattleGameOver, 0x1B8);

#endif // POKERANGER2_BATTLE_CBATTLEGAMEOVER_HPP
