#include "CEffectActorData.hpp"

void CEffectActorData::Entry::Release()
{
    FreeTex();
    SAFE_DELETE(ncbr);
    SAFE_DELETE(ncer);
    SAFE_DELETE(cac);
}

void CEffectActorData::Entry::AllocTex(BOOL immediate)
{
    if (texKey != 0) {
        return;
    }
    texKey = NNS_GfdAllocLnkTexVram(ncbr->unk_38, FALSE, 0);
    if (immediate) {
        ncbr->sub_020076E8(NNS_GfdGetTexKeyAddr(texKey));
    } else {
        ncbr->sub_02007714(NNS_GfdGetTexKeyAddr(texKey));
    }
}

void CEffectActorData::Entry::FreeTex()
{
    if (texKey != 0) {
        NNS_GfdFreeLnkTexVram(texKey);
        texKey = 0;
    }
}

void CEffectActorData::Entry::sub_020294A8()
{
    if (ncbr != NULL) {
        ncbr->sub_020076B0();
    }
}

CEffectActorData::~CEffectActorData()
{
    Release();
}

void CEffectActorData::Release()
{
    Entry *entry = m_entries;
    if (entry != NULL) {
        u32 n = m_count;
        while (n-- != 0) {
            entry->Release();
            entry++;
        }
        SAFE_DELETE_ARRAY(m_entries);
    }
    m_palette.sub_02007BC4();
    FreeVram();
    m_count = 0;
}

void CEffectActorData::sub_020295B0(BOOL immediate)
{
    if (m_plttKey == 0) {
        m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette.unk_04->szByte, FALSE, 0);
        if (immediate) {
            m_palette.sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
        } else {
            m_palette.sub_02007C34(NNS_GfdGetPlttKeyAddr(m_plttKey));
        }
    }
    for (u32 i = 0; i < m_count; i++) {
        m_entries[i].AllocTex(immediate);
    }
}

void CEffectActorData::FreeVram()
{
    if (m_entries != NULL) {
        for (u32 i = 0; i < m_count; i++) {
            m_entries[i].FreeTex();
        }
    }
    if (m_plttKey != 0) {
        NNS_GfdFreeLnkPlttVram(m_plttKey);
        m_plttKey = 0;
        m_palette.unk_20 = FALSE;
    }
}

void CEffectActorData::sub_020296B0()
{
    m_palette.sub_02007BC4();
    if (m_entries != NULL) {
        for (u32 i = 0; i < m_count; i++) {
            m_entries[i].sub_020294A8();
        }
    }
}

BOOL CEffectActorData::IsLoaded()
{
    BOOL loaded;
    if (m_palette.unk_20) {
        if (GetEntryCount() != 0) {
            loaded = TRUE;
            for (u32 i = 0; i < GetEntryCount(); i++) {
                if (m_entries[i].ncbr == NULL || !m_entries[i].ncbr->unk_30) {
                    loaded = FALSE;
                    break;
                }
            }
        } else {
            loaded = FALSE;
        }
    } else {
        loaded = FALSE;
    }
    return loaded;
}

int CEffectActorData::GetCount()
{
    return m_count;
}

void CEffectActorData::Update()
{
}

UnkClass_02007AA4 *CEffectActorData::GetPalette()
{
    return &m_palette;
}

UnkClass_02008788 *CEffectActorData::GetCac(int i)
{
    if (i >= 0 && i < m_count) {
        return m_entries[i].cac;
    }
    return NULL;
}

CNCERFile *CEffectActorData::GetNcer(int i)
{
    if (i >= 0 && i < m_count) {
        return m_entries[i].ncer;
    }
    return NULL;
}

UnkClass_020074D4 *CEffectActorData::GetNcbr(int i)
{
    if (i >= 0 && i < m_count) {
        return m_entries[i].ncbr;
    }
    return NULL;
}
