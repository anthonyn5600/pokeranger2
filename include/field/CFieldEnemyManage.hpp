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
class UnkStruct_021357DC {
public:
    UnkStruct_021357DC();
    ~UnkStruct_021357DC();
    void Load(const char *path);

    u16 unk_00;
    CBinaryFile *unk_04;
    void *unk_08;
};

// Enemy scripts loaded so far, by script id.
class UnkClass_0213588C {
public:
    UnkClass_0213588C();
    ~UnkClass_0213588C();
    void *Get(u32 id);
    void Clear();

    UnkStruct_021357DC *m_scripts[64];
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
        sub_0203F034();
        MAIN_BSS_0210CA5C = NULL;
    }

    virtual void sub_0203EFE4(int capacity);
    virtual void sub_0203F034();
    virtual BOOL sub_0203F190();
    virtual void sub_0203F2B0(CFieldMap *map, BOOL update);
    virtual void BuildData(void *buf, int size);

    int ov0_02135E30(int slot, u16 kind, u16 script, int arg4);
    u32 ov0_02136320(int type);
    void ov0_02136384();
    void ov0_0213669C(u32 id, u16 script);
    void ov0_02136730(u32 id);
    void ov0_02136878();
    void ov0_0213690C(int arg1, int arg2);
    void ov0_02136968();
    void ov0_021369DC(CFieldEnemy *enemy);

public:
    UnkClass_0213588C *unk_14;
};

STATIC_SIZE_ASSERT(CFieldEnemyManage, 0x18);

#endif // POKERANGER2_FIELD_CFIELDENEMYMANAGE_HPP
