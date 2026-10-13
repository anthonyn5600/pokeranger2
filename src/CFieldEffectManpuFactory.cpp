#include "field/CFieldEffectManpuFactory.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpuAnger.hpp"
#include "field/CFieldEffectManpuAnime.hpp"
#include "field/CFieldEffectManpuAse.hpp"
#include "field/CFieldEffectManpuBalloon.hpp"
#include "field/CFieldEffectManpuDarkrie.hpp"
#include "field/CFieldEffectManpuDokarimo.hpp"
#include "field/CFieldEffectManpuGokigen.hpp"
#include "field/CFieldEffectManpuJumping.hpp"

extern UnkClass_0216D2D4 *OVERLAY0_BSS_0217B0E0;

CFieldEffectManpuFactory::CFieldEffectManpuFactory()
{
    OVERLAY0_BSS_0217B0E0 = &m_heap;
    m_data[0].Load(0x24);
    m_data[1].Load(0x25);
    m_data[2].Load(0x26);
    m_data[3].Load(0x27);
    m_data[4].Load(0x28);
    m_data[5].Load(0x29);
    m_data[6].Load(0x2A);
    m_data[7].Load(0x41);
    m_slots[0].Init(m_data[5].GetCac(0), 0x20);
    CFieldEffectManage::CResidentResource *res = &MAIN_BSS_0210CA60->m_resident;
    m_slots[1].Init(res->GetCac(9), 0x20);
    m_slots[2].Init(res->GetCac(10), 0x20);
}

CFieldEffectManpuFactory::~CFieldEffectManpuFactory()
{
    if (MAIN_BSS_0210CA60 != NULL) {
        CFieldEffectManage::CResidentResource *res = &MAIN_BSS_0210CA60->m_resident;
        m_slots[2].Release(res->GetCac(9));
        m_slots[1].Release(res->GetCac(9));
        m_slots[0].Release(m_data[5].GetCac(0));
    }
    OVERLAY0_BSS_0217B0E0 = NULL;
}

CFieldEffect *CFieldEffectManpuFactory::Create(int arg)
{
    int kind = arg;
    if (kind < 0x64) {
        if (kind >= 0x24 && kind <= 0x2A) {
            kind -= 0x24;
        } else if (kind == 0x41) {
            kind = 7;
        } else {
            kind = -1;
        }
    }
    switch (kind) {
    case 0:
    case 1:
        return new CFieldEffectManpuBalloon(&m_data[kind]);
    case 2:
    case 3:
        return new CFieldEffectManpuJumping(&m_data[kind]);
    case 4:
        return new CFieldEffectManpuAnger(&m_data[kind]);
    case 5:
        return new CFieldEffectManpuAse(&m_data[kind], &m_slots[0]);
    case 6:
        return new CFieldEffectManpuSimple(&m_data[kind]);
    case 7:
        return new CFieldEffectManpuGokigen(&m_data[kind]);
    case 0x64:
        return new CFieldEffectManpuDokarimo(&MAIN_BSS_0210CA60->m_resident, &m_slots[1], 9, 9);
    case 0x65:
        return new CFieldEffectManpuDokarimo(&MAIN_BSS_0210CA60->m_resident, &m_slots[1], 9, 0xC);
    case 0x66:
        return new CFieldEffectManpuDokarimo(&MAIN_BSS_0210CA60->m_resident, &m_slots[2], 0xA, 0xD);
    case 0x67:
        return new CFieldEffectManpuDarkrie(&MAIN_BSS_0210CA60->m_resident, &m_slots[2], 0xA, 0xE);
    }
    return NULL;
}

void CFieldEffectManpuFactory::ov0_0215215C(int arg)
{
}

void CFieldEffectManpuFactory::Update(int frames)
{
    for (int i = 0; i < 8; i++) {
        if (i != 5) {
            m_data[i].Update();
        }
    }
}

void CFieldEffectManpuFactory::Reset()
{
    ov0_0215215C(0x2B);
}

void CFieldEffectManpuFactory::Release(CFieldEffectManage *mgr)
{
    CFieldEffectManage::CResidentResource *res = &mgr->m_resident;
    m_slots[2].Release(res->GetCac(9));
    m_slots[1].Release(res->GetCac(9));
    m_slots[0].Release(m_data[5].GetCac(0));
}
