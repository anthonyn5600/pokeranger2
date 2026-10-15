#include <nitro.h>

#include "CGame.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "file/CBinaryFile.hpp"
#include "sub_02044440.hpp"

extern "C" {
void Script_Link(void *script);
}

// One loaded target object/touch script (twin of FieldEnemyScript).
class FieldTargetObjectScript {
public:
    FieldTargetObjectScript();
    ~FieldTargetObjectScript();
    void Load(const char *path, int id);

    u16 unk_00;
    CBinaryFile *unk_04;
    void *unk_08;
};

FieldTargetObjectScript::FieldTargetObjectScript()
{
    unk_00 = 0;
    unk_04 = NULL;
    unk_08 = NULL;
}

FieldTargetObjectScript::~FieldTargetObjectScript()
{
    SAFE_DELETE(unk_04);
}

void FieldTargetObjectScript::Load(const char *path, int id)
{
    u32 heapId = s_game->unk_14A8;
    SAFE_DELETE(unk_04);
    unk_04 = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    unk_08 = unk_04->unk_4C;
    if (unk_08 != NULL) {
        Script_Link(unk_08);
    }
    unk_00 = id;
}

FieldTargetObjectScriptCache::FieldTargetObjectScriptCache()
{
    Script_InitSyscalls();
    for (int i = 0; i < 32; i++) {
        m_scripts[i] = NULL;
    }
}

FieldTargetObjectScriptCache::~FieldTargetObjectScriptCache()
{
    Clear();
}

void FieldTargetObjectScriptCache::Clear()
{
    for (int i = 0; i < 32; i++) {
        SAFE_DELETE(m_scripts[i]);
    }
}

void *FieldTargetObjectScriptCache::Get(int id, BOOL touch)
{
    char path[0x100];
    u32 key = id;
    if (touch == TRUE) {
        key = (u16)(key | 0x8000);
    }
    for (int i = 0; i < 32; i++) {
        if (m_scripts[i] != NULL) {
            if (key == m_scripts[i]->unk_00) {
                return m_scripts[i]->unk_08;
            }
        } else {
            m_scripts[i] = new FieldTargetObjectScript();
            if (!touch) {
                OS_SPrintf(path, "data/Script/field/targetobject/to%02d/TargetObject%03d.fsb", id / 10, id);
            } else {
                OS_SPrintf(path, "data/Script/field/targettouch/tt%02d/TargetTouch%03d.fsb", id / 10, id);
            }
            m_scripts[i]->Load(path, key);
            if (m_scripts[i]->unk_08 != NULL) {
                return m_scripts[i]->unk_08;
            }
            SAFE_DELETE(m_scripts[i]);
            return NULL;
        }
    }
    return NULL;
}
