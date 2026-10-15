#ifndef POKERANGER2_SCRIPTMANAGER_HPP
#define POKERANGER2_SCRIPTMANAGER_HPP

#include <nitro.h>

#include "common.hpp"

class ScriptFile;

// Script manager (src/ScriptManager.cpp); CGame::m_scriptManager
class ScriptManager {
public:
    ScriptManager(u32 heap);

public:
    u32 m_heap;
    ScriptFile *m_system;
    ScriptFile *m_area;
    ScriptFile *m_chapter;
    ScriptFile *m_quest;
    int m_arg;
    int unk_18;
    u8 m_chapterBuffer[0x18800];
};

STATIC_SIZE_ASSERT(ScriptManager, 0x1881C);

extern "C" {
int ScriptManager_LoadSystem(ScriptManager *mgr, int id);
int ScriptManager_Run(ScriptManager *mgr, const char *name);
void ScriptManager_UnloadSystem(ScriptManager *mgr);
int ScriptManager_IsBusy(ScriptManager *mgr);
BOOL ScriptManager_IsRunning(ScriptManager *mgr);
void ScriptManager_SetArg(ScriptManager *mgr, int value);
}

#endif // POKERANGER2_SCRIPTMANAGER_HPP
