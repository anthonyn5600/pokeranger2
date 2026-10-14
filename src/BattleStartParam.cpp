#include "BattleStartParam.hpp"

BattleStartParam::BattleStartParam()
{
    BattleStartParam_Reset(this);
}

extern "C" {

void BattleStartParam_Reset(BattleStartParam *obj)
{
    obj->unk_00 = 0x22;
    obj->m_energy = 10;
    obj->m_stylerLevel = 1;
    obj->unk_06 = FALSE;
    obj->unk_08 = 0;
    obj->unk_0C = 0;
    obj->m_partnerMood = 0;
    obj->m_partyCount = 0;
    int i;
    for (i = 0; i < 8; i++) {
        obj->m_partyIds[i] = 0xFF;
        obj->m_partyFlags[i] = 0;
    }
    obj->m_enemyCount = 0;
    for (i = 0; i < 8; i++) {
        obj->m_enemySlots[i] = 0xFF;
    }
    obj->m_pokemonCount = 0;
    for (i = 0; i < 4; i++) {
        obj->m_pokemonIds[i] = 0xFFFF;
        obj->m_pokemonForms[i] = 0;
        obj->m_pokemonEnemyCounts[i] = 0;
    }
    obj->m_captureBg = 0;
    obj->m_screenEffect = 0;
    obj->m_sequenceScript = 0;
    obj->m_tutorialScript = 0;
    obj->m_startScript = 0;
    obj->m_bgmIndex = 0;
    obj->unk_4F = TRUE;
    obj->unk_50 = TRUE;
    obj->unk_51 = FALSE;
    obj->unk_52 = 0;
    obj->unk_54 = 0;
    obj->m_bannerType = 0;
    obj->m_overrideFlags = 0;
}

void sub_0201094C(BattleStartParam *obj, u32 arg1)
{
    obj->unk_00 = arg1;
}

void BattleStartParam_SetEnergy(BattleStartParam *obj, u8 arg1)
{
    obj->m_energy = arg1;
}

void BattleStartParam_SetStylerLevel(BattleStartParam *obj, u8 arg1)
{
    obj->m_stylerLevel = arg1;
}

void sub_02010964(BattleStartParam *obj, BOOL arg1)
{
    obj->unk_06 = arg1 ? TRUE : FALSE;
}

void sub_02010978(BattleStartParam *obj, u32 arg1)
{
    obj->unk_08 = arg1;
}

void sub_02010980(BattleStartParam *obj, u32 arg1)
{
    obj->unk_0C = arg1;
}

void BattleStartParam_SetPartnerMood(BattleStartParam *obj, u32 arg1)
{
    obj->m_partnerMood = arg1;
}

void BattleStartParam_AddPartyMember(BattleStartParam *obj, u16 arg1, u8 arg2)
{
    if (obj->m_partyCount >= 8) {
        return;
    }
    obj->m_partyIds[obj->m_partyCount] = arg1;
    obj->m_partyFlags[obj->m_partyCount] = arg2;
    obj->m_partyCount++;
}

void BattleStartParam_AddEnemy(BattleStartParam *obj, u16 arg1, u8 arg2)
{
    if (obj->m_enemyCount >= 8) {
        return;
    }
    u8 i;
    u8 idx = 0xFF;
    u8 count = obj->m_pokemonCount;
    for (i = 0; i < count; i++) {
        if (obj->m_pokemonIds[i] == arg1 && obj->m_pokemonForms[i] == arg2) {
            idx = i;
            break;
        }
    }
    if (idx == 0xFF) {
        if (count >= 4) {
            return;
        }
        obj->m_pokemonIds[count] = arg1;
        obj->m_pokemonForms[count] = arg2;
        obj->m_pokemonCount++;
        idx = count;
    }
    obj->m_pokemonEnemyCounts[idx]++;
    obj->m_enemySlots[obj->m_enemyCount] = idx;
    obj->m_enemyCount++;
}

void BattleStartParam_SetCaptureBg(BattleStartParam *obj, u8 arg1)
{
    obj->m_captureBg = arg1;
    obj->m_overrideFlags |= 1;
}

void BattleStartParam_SetScreenEffect(BattleStartParam *obj, u8 arg1)
{
    obj->m_screenEffect = arg1;
    obj->m_overrideFlags |= 2;
}

void BattleStartParam_SetSequenceScript(BattleStartParam *obj, u8 arg1)
{
    obj->m_sequenceScript = arg1;
}

void BattleStartParam_SetTutorialScript(BattleStartParam *obj, u8 arg1)
{
    obj->m_tutorialScript = arg1;
}

void BattleStartParam_SetStartScript(BattleStartParam *obj, u8 arg1)
{
    obj->m_startScript = arg1;
}

void BattleStartParam_SetBgmIndex(BattleStartParam *obj, u8 arg1)
{
    obj->m_bgmIndex = arg1;
    obj->m_overrideFlags |= 4;
}

void sub_02010AC4(BattleStartParam *obj, BOOL arg1)
{
    obj->unk_4F = arg1 ? TRUE : FALSE;
}

void sub_02010AD8(BattleStartParam *obj, BOOL arg1)
{
    obj->unk_50 = arg1 ? TRUE : FALSE;
}

void sub_02010AEC(BattleStartParam *obj, BOOL arg1)
{
    obj->unk_51 = arg1 ? TRUE : FALSE;
}

void sub_02010B00(BattleStartParam *obj, u8 arg1)
{
    obj->unk_52 = arg1;
}

void sub_02010B08(BattleStartParam *obj, u8 arg1)
{
    obj->unk_54 = arg1;
}

void BattleStartParam_SetBannerType(BattleStartParam *obj, u16 arg1)
{
    obj->m_bannerType = arg1;
    obj->m_overrideFlags |= 8;
}

u32 sub_02010B24(BattleStartParam *obj)
{
    return obj->unk_00;
}

u8 BattleStartParam_GetEnergy(BattleStartParam *obj)
{
    return obj->m_energy;
}

u8 BattleStartParam_GetStylerLevel(BattleStartParam *obj)
{
    return obj->m_stylerLevel;
}

BOOL sub_02010B3C(BattleStartParam *obj)
{
    return obj->unk_06 ? TRUE : FALSE;
}

u32 sub_02010B50(BattleStartParam *obj)
{
    return obj->unk_08;
}

u32 sub_02010B58(BattleStartParam *obj)
{
    return obj->unk_0C;
}

u32 BattleStartParam_GetPartnerMood(BattleStartParam *obj)
{
    return obj->m_partnerMood;
}

u8 BattleStartParam_GetPokemonCount(BattleStartParam *obj)
{
    return obj->m_pokemonCount;
}

u16 BattleStartParam_GetPokemonId(BattleStartParam *obj, int idx)
{
    return obj->m_pokemonIds[idx];
}

u8 BattleStartParam_GetEnemyCount(BattleStartParam *obj)
{
    return obj->m_enemyCount;
}

u8 BattleStartParam_GetEnemySlot(BattleStartParam *obj, int idx)
{
    return obj->m_enemySlots[idx];
}

u8 BattleStartParam_GetPartyCount(BattleStartParam *obj)
{
    return obj->m_partyCount;
}

u16 BattleStartParam_GetPartyId(BattleStartParam *obj, int idx)
{
    return obj->m_partyIds[idx];
}

u8 BattleStartParam_GetPartyFlags(BattleStartParam *obj, int idx)
{
    return obj->m_partyFlags[idx];
}

u8 BattleStartParam_GetCaptureBg(BattleStartParam *obj)
{
    return obj->m_captureBg;
}

u8 BattleStartParam_GetScreenEffect(BattleStartParam *obj)
{
    return obj->m_screenEffect;
}

u8 BattleStartParam_GetSequenceScript(BattleStartParam *obj)
{
    return obj->m_sequenceScript;
}

u8 BattleStartParam_GetTutorialScript(BattleStartParam *obj)
{
    return obj->m_tutorialScript;
}

u8 BattleStartParam_GetStartScript(BattleStartParam *obj)
{
    return obj->m_startScript;
}

u8 BattleStartParam_GetBgmIndex(BattleStartParam *obj)
{
    return obj->m_bgmIndex;
}

BOOL sub_02010BE0(BattleStartParam *obj)
{
    return obj->unk_4F ? TRUE : FALSE;
}

BOOL sub_02010BF4(BattleStartParam *obj)
{
    return obj->unk_50 ? TRUE : FALSE;
}

BOOL sub_02010C08(BattleStartParam *obj)
{
    return obj->unk_51 ? TRUE : FALSE;
}

u8 sub_02010C1C(BattleStartParam *obj)
{
    return obj->unk_52;
}

u8 BattleStartParam_GetOverrideFlags(BattleStartParam *obj)
{
    return obj->m_overrideFlags;
}

u8 sub_02010C2C(BattleStartParam *obj)
{
    return obj->unk_54;
}

u16 BattleStartParam_GetBannerType(BattleStartParam *obj)
{
    return obj->m_bannerType;
}
}
