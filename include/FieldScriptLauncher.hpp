#ifndef POKERANGER2_FIELDSCRIPTLAUNCHER_HPP
#define POKERANGER2_FIELDSCRIPTLAUNCHER_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldActor;
class CGame;

// Defined in ov0
class FieldScriptLauncher {
public:
    FieldScriptLauncher(CGame *game);
    ~FieldScriptLauncher();

    void Reset();
    void ClearPending();
    void Update(BOOL startPending);
    BOOL LaunchScript(const char *label, int arg, int fade);
    BOOL LaunchActorScript(CFieldActor *actor, const char *label, int fade);
    void RunScript(const char *label, int arg, int fade);
    BOOL RunActorScript(CFieldActor *actor, const char *label, int fade);
    BOOL IsBusy();
    BOOL IsRunning();

public:
    CGame *m_game;
    int m_state; // 0 idle, 1 global script, 2 actor script, 3 target object script
    char m_label[0x20];
    int unk_28;
    CFieldActor *m_actor;
    BOOL unk_30;
    int m_pendingKind; // 0 none, 1 global (LaunchScript), 2 actor (LaunchActorScript)
    char m_pendingLabel[0x20];
    int m_pendingArg;
    CFieldActor *m_pendingActor;
    int m_pendingFade;
};

STATIC_SIZE_ASSERT(FieldScriptLauncher, 0x64);

extern FieldScriptLauncher *MAIN_BSS_0210CA44;

#endif // POKERANGER2_FIELDSCRIPTLAUNCHER_HPP
