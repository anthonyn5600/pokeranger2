#ifndef POKERANGER2_UNKCLASS_0213F918_HPP
#define POKERANGER2_UNKCLASS_0213F918_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldActor;
class CGame;

// Defined in ov0
class UnkClass_0213F918 {
public:
    UnkClass_0213F918(CGame *game);
    ~UnkClass_0213F918();

    void ov0_0213F960();
    void ov0_0213F990();
    void ov0_0213F9B0(BOOL startPending);
    BOOL ov0_0213FB0C(const char *label, int arg, int fade);
    BOOL ov0_0213FC24(CFieldActor *actor, const char *label, int fade);
    void ov0_0213FD60(const char *label, int arg, int fade);
    BOOL ov0_0213FDFC(CFieldActor *actor, const char *label, int fade);
    BOOL ov0_0213FEEC();
    BOOL ov0_0213FF2C();

public:
    CGame *m_game;
    int m_state; // 0 idle, 1 global script, 2 actor script, 3 target object script
    char m_label[0x20];
    int unk_28;
    CFieldActor *m_actor;
    BOOL unk_30;
    int m_pendingKind; // 0 none, 1 global (ov0_0213FB0C), 2 actor (ov0_0213FC24)
    char m_pendingLabel[0x20];
    int m_pendingArg;
    CFieldActor *m_pendingActor;
    int m_pendingFade;
};

STATIC_SIZE_ASSERT(UnkClass_0213F918, 0x64);

extern UnkClass_0213F918 *MAIN_BSS_0210CA44;

#endif // POKERANGER2_UNKCLASS_0213F918_HPP
