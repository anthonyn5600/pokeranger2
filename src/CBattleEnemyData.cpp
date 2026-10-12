#include "battle/CBattleEnemyData.hpp"

#include "UnkStruct_02044464.hpp"

CBattleEnemyData::CBattleEnemyData(u16 id, UnkStruct_020107A8 *info, UnkStruct_0212DFEC *param, u32 heapId)
    : CActorData(0, info->unk_00, info->unk_02, 0x26, TRUE, NULL)
{
    unk_16 = id;
    unk_18 = info;
    unk_1C = param;
    m_plttKey = NNS_GfdAllocLnkPlttVram(sub_02014364(), FALSE, 0);
    sub_0201429C(NNS_GfdGetPlttKeyAddr(m_plttKey));
    sub_020142F8();
    unk_20 = param->unk_06 << FX32_SHIFT;
    unk_24 = param->unk_07 << FX32_SHIFT;
    unk_28 = param->unk_08 << FX32_SHIFT;
    unk_2C.pos.x = info->unk_0A << FX32_SHIFT;
    unk_2C.pos.y = info->unk_0B << FX32_SHIFT;
    unk_2C.size.x = info->unk_0C << FX32_SHIFT;
    unk_2C.size.y = info->unk_0D << FX32_SHIFT;
    unk_3C[0] = param->unk_10 << FX32_SHIFT;
    unk_3C[1] = param->unk_11 << FX32_SHIFT;
    unk_3C[2] = param->unk_12 << FX32_SHIFT;
    unk_3C[3] = param->unk_13 << FX32_SHIFT;
    unk_3C[4] = param->unk_14 << FX32_SHIFT;
    unk_3C[5] = param->unk_15 << FX32_SHIFT;

    char path[0x60];
    OS_SPrintf(path, "data/script/battle/pokemon/p%03d.fsb", unk_16);
    if (CBinaryFile::sub_02003108(path, heapId)) {
        m_scriptFile = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
        m_script = m_scriptFile->unk_4C;
        sub_02044AC8(m_script);
    } else {
        m_scriptFile = NULL;
        m_script = NULL;
    }
}

CBattleEnemyData::~CBattleEnemyData()
{
    Release();
    SAFE_DELETE(m_scriptFile);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}
