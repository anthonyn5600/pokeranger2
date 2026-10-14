#include "battle/CBattleEnemyData.hpp"

#include "UnkStruct_02044464.hpp"

CBattleEnemyData::CBattleEnemyData(u16 id, UnkStruct_020107A8 *info, UnkStruct_0212DFEC *param, u32 heapId)
    : CActorData(0, info->unk_00, info->unk_02, 0x26, TRUE, NULL)
{
    unk_16 = id;
    unk_18 = info;
    unk_1C = param;
    m_plttKey = NNS_GfdAllocLnkPlttVram(GetPaletteSize(), FALSE, 0);
    LoadPaletteToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    ReleasePalette();
    unk_20.pos.x = param->unk_06 << FX32_SHIFT;
    unk_20.pos.y = param->unk_07 << FX32_SHIFT;
    unk_20.r = param->unk_08 << FX32_SHIFT;
    unk_2C.pos.x = info->unk_0A << FX32_SHIFT;
    unk_2C.pos.y = info->unk_0B << FX32_SHIFT;
    unk_2C.size.x = info->unk_0C << FX32_SHIFT;
    unk_2C.size.y = info->unk_0D << FX32_SHIFT;
    unk_3C[0].x = param->unk_10 << FX32_SHIFT;
    unk_3C[0].y = param->unk_11 << FX32_SHIFT;
    unk_3C[1].x = param->unk_12 << FX32_SHIFT;
    unk_3C[1].y = param->unk_13 << FX32_SHIFT;
    unk_3C[2].x = param->unk_14 << FX32_SHIFT;
    unk_3C[2].y = param->unk_15 << FX32_SHIFT;

    char path[0x60];
    OS_SPrintf(path, "data/script/battle/pokemon/p%03d.fsb", unk_16);
    if (CBinaryFile::Exists(path, heapId)) {
        m_scriptFile = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
        m_script = m_scriptFile->unk_4C;
        Script_Link(m_script);
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
