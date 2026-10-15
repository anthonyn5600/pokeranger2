#include "battle/CBattleAttackEffectData.hpp"

#include "ScriptVM.hpp"
#include "file/CBinaryFile.hpp"
#include "file/CNANRFile.hpp"

CBattleAttackEffectData::CBattleAttackEffectData(u16 id, BattleEffectParam *entry, u32 heapId)
    : CActorData(3, entry->unk_02, 0, 0x20, FALSE, NULL)
{
    AllocAndLoadImages(m_texKeys);
    ReleaseImages();
    m_plttKey = NNS_GfdAllocLnkPlttVram(GetPaletteSize(), FALSE, 0);
    LoadPaletteToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    ReleasePalette();
    unk_18 = entry;

    char animPath[0x60];
    char scriptPath[0x60];
    for (u8 i = 0; i < 12; i++) {
        OS_SPrintf(animPath, "ACT:e%03d_a%02d.NANR", entry->unk_02, i + 1);
        if (CBinaryFile::Exists(animPath, 0)) {
            m_nanr[i + 7] = new CNANRFile(animPath, 1, 0, 0);
        }
    }
    OS_SPrintf(scriptPath, "data/script/battle/effect/e%03d.fsb", id);
    if (CBinaryFile::Exists(scriptPath, heapId)) {
        m_scriptFile = new CBinaryFile(scriptPath, 0, 0, heapId, NULL, 0);
        m_script = m_scriptFile->unk_4C;
        Script_Link(m_script);
    } else {
        m_scriptFile = NULL;
        m_script = NULL;
    }
    SAFE_DELETE(m_archive);
}

CBattleAttackEffectData::~CBattleAttackEffectData()
{
    Release();
    for (u8 i = 0; i < 12; i++) {
        SAFE_DELETE(m_nanr[i]);
    }
    SAFE_DELETE(m_scriptFile);
    for (u8 i = 0; i < 0x1D; i++) {
        NNS_GfdFreeLnkTexVram(m_texKeys[i]);
    }
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}
