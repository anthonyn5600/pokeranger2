#include "ScriptManager.hpp"

#include <nitro.h>
#include <string.h>

#include "UnkStruct_02044464.hpp"
#include "file/CBinaryFile.hpp"
#include "sub_02044440.hpp"

typedef int (*ScriptSyscall)(int *args, int argc);
extern ScriptSyscall gScriptSyscalls[];

// One loaded .fsb script file and the VM that runs it
class ScriptFile {
public:
    ScriptFile();

    int Load(const char *path, u32 heap, void *buffer, u32 bufferSize);
    int LoadFromMemory(void *data, BOOL skipInit);
    int Run(const char *name);
    void SetNext(const char *name);
    int RunNext();
    void Unload();
    void Update();
    void Reset();
    void Release();
    int GetState()
    {
        return m_state;
    }
    int GetPending()
    {
        return m_pending;
    }

public:
    char m_path[0x20];
    void *m_data;
    void *m_script;
    CBinaryFile *m_file;
    char m_name[0x10];
    UnkStruct_02044464 m_vm;
    u32 m_stack[0x80];
    int m_state;
    char m_next[0x10];
    int m_pending;
    int m_id;
};

STATIC_SIZE_ASSERT(ScriptFile, 0x27C);

ScriptFile::ScriptFile()
{
    Reset();
}

int ScriptFile::Load(const char *path, u32 heap, void *buffer, u32 bufferSize)
{
    OS_SPrintf(m_path, path);
    Release();
    Reset();
    m_file = new CBinaryFile(m_path, 0, 0, heap, buffer, bufferSize);
    m_data = m_file->unk_4C;
    if (m_data == NULL) {
        Release();
        return 1;
    }
    m_script = m_data;
    Script_Link(m_script);
    ScriptVM_Init(&m_vm, m_stack, 0x80);
    return 0;
}

int ScriptFile::LoadFromMemory(void *data, BOOL skipInit)
{
    Release();
    Reset();
    if (data == NULL) {
        return 1;
    }
    m_data = data;
    m_script = data;
    if (!skipInit) {
        Script_Link(m_script);
    }
    ScriptVM_Init(&m_vm, m_stack, 0x80);
    return 0;
}

int ScriptFile::Run(const char *name)
{
    if (m_data == NULL) {
        return 1;
    }
    if (strlen(name) > 12) {
        OS_Terminate();
    }
    OS_SPrintf(m_name, name, 13);
    ScriptVM_Reset(&m_vm);
    ScriptVM_Start(&m_vm, m_script, m_name);
    m_state = 1;
    return 0;
}

void ScriptFile::SetNext(const char *name)
{
    if (strlen(name) > 12) {
        OS_Terminate();
    }
    OS_SPrintf(m_next, name, 13);
    m_pending = 1;
}

int ScriptFile::RunNext()
{
    if (m_data == NULL) {
        return 1;
    }
    OS_SPrintf(m_name, m_next, 13);
    ScriptVM_Reset(&m_vm);
    ScriptVM_Start(&m_vm, m_script, m_name);
    m_state = 1;
    m_pending = 0;
    return 0;
}

void ScriptFile::Unload()
{
    Release();
    Reset();
}

void ScriptFile::Update()
{
    if (m_state == 0) {
        return;
    }
    if (ScriptVM_Run(&m_vm, 0xFFFFF) & 2) {
        m_state = 0;
        return;
    }
    if (m_state == 1) {
        m_state = 2;
    }
}

void ScriptFile::Reset()
{
    m_data = NULL;
    m_script = NULL;
    m_file = NULL;
    m_state = 0;
    m_pending = 0;
    m_id = -1;
}

void ScriptFile::Release()
{
    SAFE_DELETE(m_file);
}

ScriptManager::ScriptManager(u32 heap)
{
    Script_InitSyscalls();
    m_heap = heap;
    Script_RegisterSyscalls(2, gScriptSyscalls);
    m_system = new ScriptFile();
    m_area = new ScriptFile();
    m_chapter = new ScriptFile();
    m_quest = new ScriptFile();
}

extern "C" {

int ScriptManager_LoadSystem(ScriptManager *mgr, int id)
{
    int result = 0;
    if (id != mgr->m_system->m_id) {
        char path[0x40];
        if (id > 0) {
            OS_SPrintf(path, "data/Script/system/system%03d.fsb", id);
            result = mgr->m_system->Load(path, mgr->m_heap, NULL, 0);
        } else {
            result = mgr->m_system->Load("data/Script/system/system.fsb", mgr->m_heap, NULL, 0);
        }
        if (result == 0) {
            mgr->m_system->m_id = id;
        }
    }
    return result;
}

int ScriptManager_LoadArea(ScriptManager *mgr, int id)
{
    char path[0x40];
    int result = 0;
    if (id != mgr->m_area->m_id) {
        OS_SPrintf(path, "data/Script/area/m%03d.fsb", id);
        result = mgr->m_area->Load(path, mgr->m_heap, NULL, 0);
        if (result == 0) {
            mgr->m_area->m_id = id;
        }
    }
    return result;
}

int ScriptManager_LoadChapter(ScriptManager *mgr, int id)
{
    char path[0x40];
    int result = 0;
    if (id != mgr->m_chapter->m_id) {
        if (id < 70) {
            OS_SPrintf(path, "data/Script/chapter/c%03d.fsb", id);
            result = mgr->m_chapter->Load(path, mgr->m_heap, mgr->m_chapterBuffer, sizeof(mgr->m_chapterBuffer));
            if (result == 0) {
                mgr->m_chapter->m_id = id;
            }
        } else {
            OS_SPrintf(path, "data/Script/chapter/cx%02d.fsb", id - 69);
            result = mgr->m_chapter->LoadFromMemory(mgr->m_chapterBuffer, TRUE);
        }
    }
    return result;
}

int ScriptManager_LoadQuest(ScriptManager *mgr, int id)
{
    char path[0x40];
    int result = 0;
    if (id != mgr->m_quest->m_id) {
        OS_SPrintf(path, "data/Script/quest/q%03d.fsb", id);
        result = mgr->m_quest->Load(path, mgr->m_heap, NULL, 0);
    }
    if (result == 0) {
        mgr->m_quest->m_id = id;
    }
    return result;
}

int ScriptManager_Run(ScriptManager *mgr, const char *name)
{
    switch (name[0]) {
    case 's':
        mgr->unk_18 = 0;
        return mgr->m_system->Run(name);
    case 'a':
        mgr->unk_18 = 0;
        return mgr->m_area->Run(name);
    case 'c':
        mgr->unk_18 = 0;
        return mgr->m_chapter->Run(name);
    case 'q':
        mgr->unk_18 = 0;
        return mgr->m_quest->Run(name);
    }
    OS_Terminate();
    return 1;
}

void ScriptManager_SetNext(ScriptManager *mgr, const char *name)
{
    switch (name[0]) {
    case 's':
        mgr->m_system->SetNext(name);
        return;
    case 'a':
        mgr->m_area->SetNext(name);
        return;
    case 'c':
        mgr->m_chapter->SetNext(name);
        return;
    case 'q':
        mgr->m_quest->SetNext(name);
        return;
    }
    OS_Terminate();
}

void ScriptManager_UnloadSystem(ScriptManager *mgr)
{
    mgr->m_system->Unload();
}

void ScriptManager_UnloadArea(ScriptManager *mgr)
{
    mgr->m_area->Unload();
}

void ScriptManager_UnloadChapter(ScriptManager *mgr)
{
    mgr->m_chapter->Unload();
}

void ScriptManager_UnloadQuest(ScriptManager *mgr)
{
    mgr->m_quest->Unload();
}

int ScriptManager_IsBusy(ScriptManager *mgr)
{
    return mgr->unk_18 | mgr->m_system->GetState() | mgr->m_system->GetPending() | mgr->m_area->GetState() | mgr->m_area->GetPending() | mgr->m_chapter->GetState() | mgr->m_chapter->GetPending() | mgr->m_quest->GetState() | mgr->m_quest->GetPending();
}

int ScriptManager_IsRunning(ScriptManager *mgr)
{
    return mgr->m_system->GetState() | mgr->m_system->GetPending() | mgr->m_area->GetState() | mgr->m_area->GetPending() | mgr->m_chapter->GetState() | mgr->m_chapter->GetPending() | mgr->m_quest->GetState() | mgr->m_quest->GetPending();
}

void ScriptManager_SetArg(ScriptManager *mgr, int value)
{
    mgr->m_arg = value;
}

int ScriptManager_GetArg(ScriptManager *mgr)
{
    return mgr->m_arg;
}

void ScriptManager_Update(ScriptManager *mgr)
{
    if (mgr->m_system->m_state != 0) {
        mgr->m_system->Update();
    } else if (mgr->m_area->m_state != 0) {
        mgr->m_area->Update();
    } else if (mgr->m_chapter->m_state != 0) {
        mgr->m_chapter->Update();
    } else if (mgr->m_quest->m_state != 0) {
        mgr->m_quest->Update();
    } else if (mgr->m_system->m_pending != 0) {
        mgr->m_system->RunNext();
    } else if (mgr->m_area->m_pending != 0) {
        mgr->m_area->RunNext();
    } else if (mgr->m_chapter->m_pending != 0) {
        mgr->m_chapter->RunNext();
    } else if (mgr->m_quest->m_pending != 0) {
        mgr->m_quest->RunNext();
    }
}

void ScriptManager_UnloadAll(ScriptManager *mgr)
{
    ScriptManager_UnloadSystem(mgr);
    ScriptManager_UnloadArea(mgr);
    ScriptManager_UnloadChapter(mgr);
    ScriptManager_UnloadQuest(mgr);
}
}
