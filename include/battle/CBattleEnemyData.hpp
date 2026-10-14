#ifndef POKERANGER2_BATTLE_CBATTLEENEMYDATA_HPP
#define POKERANGER2_BATTLE_CBATTLEENEMYDATA_HPP

#include <nitro.h>

#include "CActorData.hpp"
#include "Collision.hpp"
#include "UnkStruct_020107A8.hpp"
#include "battle/UnkStruct_0212DFEC.hpp"
#include "common.hpp"
#include "file/CBinaryFile.hpp"

// Defined in ov1
class CBattleEnemyData : public CActorData {
public:
    CBattleEnemyData(u16 id, UnkStruct_020107A8 *info, UnkStruct_0212DFEC *param, u32 arg3);
    virtual ~CBattleEnemyData();

public:
    u16 unk_16;
    UnkStruct_020107A8 *unk_18;
    UnkStruct_0212DFEC *unk_1C;
    Circle unk_20;
    Rectangle unk_2C;
    Point2D unk_3C[3];
    CBinaryFile *m_scriptFile;
    void *m_script;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(CBattleEnemyData, 0x60);

#endif // POKERANGER2_BATTLE_CBATTLEENEMYDATA_HPP
