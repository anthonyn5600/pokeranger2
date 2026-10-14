#ifndef POKERANGER2_BATTLESTARTPARAM_HPP
#define POKERANGER2_BATTLESTARTPARAM_HPP

#include <nitro.h>

#include "common.hpp"

// CGame::unk_143C
class BattleStartParam {
public:
    BattleStartParam();

public:
    u32 unk_00;
    u8 m_energy;
    u8 m_stylerLevel;
    u8 unk_06;
    u32 unk_08;
    u32 unk_0C;
    u32 m_partnerMood;
    u8 m_partyCount;
    u16 m_partyIds[8];
    u8 m_partyFlags[8];
    u8 m_pokemonCount;
    u16 m_pokemonIds[4];
    u8 m_pokemonForms[4];
    u8 m_pokemonEnemyCounts[4];
    u8 m_enemyCount;
    u8 m_enemySlots[8];
    u8 m_captureBg;
    u8 m_screenEffect;
    u8 m_sequenceScript;
    u8 m_tutorialScript;
    u8 m_startScript;
    u8 m_bgmIndex;
    u8 unk_4F;
    u8 unk_50;
    u8 unk_51;
    u8 unk_52;
    u8 unk_53;
    u8 unk_54;
    u16 m_bannerType;
    u8 m_overrideFlags;
};

STATIC_SIZE_ASSERT(BattleStartParam, 0x5C);

extern "C" {
void BattleStartParam_Reset(BattleStartParam *obj);
u32 sub_02010B24(BattleStartParam *obj);
u8 BattleStartParam_GetEnergy(BattleStartParam *obj);
u8 BattleStartParam_GetStylerLevel(BattleStartParam *obj);
BOOL sub_02010B3C(BattleStartParam *obj);
u32 sub_02010B50(BattleStartParam *obj);
u32 sub_02010B58(BattleStartParam *obj);
u32 BattleStartParam_GetPartnerMood(BattleStartParam *obj);
u8 BattleStartParam_GetPokemonCount(BattleStartParam *obj);
u16 BattleStartParam_GetPokemonId(BattleStartParam *obj, int idx);
u8 BattleStartParam_GetEnemyCount(BattleStartParam *obj);
u8 BattleStartParam_GetEnemySlot(BattleStartParam *obj, int idx);
u8 BattleStartParam_GetPartyCount(BattleStartParam *obj);
u16 BattleStartParam_GetPartyId(BattleStartParam *obj, int idx);
u8 BattleStartParam_GetPartyFlags(BattleStartParam *obj, int idx);
u8 BattleStartParam_GetCaptureBg(BattleStartParam *obj);
u8 BattleStartParam_GetScreenEffect(BattleStartParam *obj);
u8 BattleStartParam_GetSequenceScript(BattleStartParam *obj);
u8 BattleStartParam_GetTutorialScript(BattleStartParam *obj);
u8 BattleStartParam_GetStartScript(BattleStartParam *obj);
BOOL sub_02010C08(BattleStartParam *obj);
u8 sub_02010C1C(BattleStartParam *obj);
u8 sub_02010C2C(BattleStartParam *obj);
u16 BattleStartParam_GetBannerType(BattleStartParam *obj);
u8 BattleStartParam_GetBgmIndex(BattleStartParam *obj);
BOOL sub_02010BE0(BattleStartParam *obj);
BOOL sub_02010BF4(BattleStartParam *obj);
}

#endif // POKERANGER2_BATTLESTARTPARAM_HPP
