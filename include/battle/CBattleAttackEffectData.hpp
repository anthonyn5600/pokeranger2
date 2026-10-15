#ifndef POKERANGER2_BATTLE_CBATTLEATTACKEFFECTDATA_HPP
#define POKERANGER2_BATTLE_CBATTLEATTACKEFFECTDATA_HPP

#include <nitro.h>

#include "CActorData.hpp"
#include "battle/BattleEffectParam.hpp"
#include "common.hpp"

class CBinaryFile;
class CNANRFile;

// Defined in ov1
class CBattleAttackEffectData : public CActorData {
public:
    CBattleAttackEffectData(u16 id, BattleEffectParam *entry, u32 heapId);
    virtual ~CBattleAttackEffectData();

public:
    BattleEffectParam *unk_18;
    CNANRFile *m_nanr[0x1D];
    CBinaryFile *m_scriptFile;
    void *m_script;
    NNSGfdTexKey m_texKeys[0x1D];
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(CBattleAttackEffectData, 0x110);

#endif // POKERANGER2_BATTLE_CBATTLEATTACKEFFECTDATA_HPP
