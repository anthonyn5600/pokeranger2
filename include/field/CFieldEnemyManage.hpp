#ifndef POKERANGER2_FIELD_CFIELDENEMYMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDENEMYMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"
#include "field/IFieldEnemyDataBuilder.hpp"

class CBinaryFile;
class CFieldEnemy;
class CFieldEnemyManage;

extern CFieldEnemyManage *MAIN_BSS_0210CA5C;

// One loaded enemy script (data/Script/field/actor/FieldEnemyScript%d.fsb).
class FieldEnemyScript {
public:
    FieldEnemyScript();
    ~FieldEnemyScript();
    void Load(const char *path);

    u16 unk_00;
    CBinaryFile *unk_04;
    void *unk_08;
};

// Enemy scripts loaded so far, by script id.
class FieldEnemyScriptCache {
public:
    FieldEnemyScriptCache();
    ~FieldEnemyScriptCache();
    void *Get(u32 id);
    void Clear();

    FieldEnemyScript *m_scripts[64];
};

// FieldEnemyManage.cpp (ov0)
class CFieldEnemyManage : public CFieldActorManage, public IFieldEnemyDataBuilder {
public:
    CFieldEnemyManage()
    {
        MAIN_BSS_0210CA5C = this;
        unk_0C = 1;
    }

    virtual ~CFieldEnemyManage()
    {
        Free();
        MAIN_BSS_0210CA5C = NULL;
    }

    virtual void Alloc(int capacity);
    virtual void Free();
    virtual BOOL Clear();
    virtual void UpdateAll(CFieldMap *map, BOOL update);
    virtual void BuildData(void *buf, int size);

    int Create(int slot, u16 kind, u16 script, int arg4);
    u32 ov0_02136320(int type);
    void AddTargets();
    void ChangeScript(u32 id, u16 script);
    void RestoreScript(u32 id);
    void RestoreSavedEnemies();
    void ShowManpuAll(int arg1, int arg2);
    void HideManpuAll();
    void ResetEnemy(CFieldEnemy *enemy);

public:
    FieldEnemyScriptCache *unk_14;
};

STATIC_SIZE_ASSERT(CFieldEnemyManage, 0x18);

#endif // POKERANGER2_FIELD_CFIELDENEMYMANAGE_HPP
