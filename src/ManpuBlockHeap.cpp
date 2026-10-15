#include "field/ManpuBlockHeap.hpp"

#include <nitro.h>

#include "field/AnimSlotPool.hpp"

ManpuBlockHeap::ManpuBlockHeap()
{
    m_used = 0;
    m_cont = 0;
}

void *ManpuBlockHeap::Alloc(u32 size)
{
    void *ptr;
    u32 count;
    int i;
    int n;
    u32 cont;

    ptr = NULL;
    count = (size + 0xFF) >> 8;
    i = 0;
    while (i < 32) {
        if (!(m_used & (1 << i))) {
            if (count == 1) {
                ptr = m_blocks[i];
                m_used |= 1 << i;
                m_cont &= ~(1 << i);
                break;
            }
            if (i + count > 32) {
                break;
            }
            cont = 0;
            for (n = 1; n < count; n++) {
                if (m_used & (1 << (i + n))) {
                    break;
                }
                cont |= 1 << (i + n);
            }
            if (n >= count) {
                ptr = m_blocks[i];
                m_used |= cont | (1 << i);
                m_cont &= ~(1 << i);
                m_cont |= cont;
                break;
            }
            i += n + 1;
        } else {
            i++;
        }
    }
    return ptr;
}

void ManpuBlockHeap::Free(void *ptr)
{
    u32 bit = 1 << (((u8 *)ptr - (u8 *)m_blocks) >> 8);
    while (bit != 0) {
        m_used &= ~bit;
        m_cont &= ~bit;
        bit <<= 1;
        if (!(m_cont & bit)) {
            bit = 0;
        }
    }
}

AnimSlotPool::AnimSlotPool()
{
    m_slots = NULL;
    m_count = 0;
}

AnimSlotPool::~AnimSlotPool()
{
    SAFE_DELETE_ARRAY(m_slots);
}

void AnimSlotPool::Init(CellAnimController *cac, u32 count)
{
    SAFE_DELETE_ARRAY(m_slots);
    m_count = count;
    if (count != 0) {
        int size = count * sizeof(Slot);
        m_slots = new Slot[count];
        if (m_slots != NULL) {
            MI_CpuFill8(m_slots, 0, size);
        }
    }
    if (m_slots != NULL && cac != NULL) {
        for (u32 i = 0; i < m_count; i++) {
            m_slots[i].anim = cac->Create(1, 0);
        }
    }
}

void AnimSlotPool::Release(CellAnimController *cac)
{
    if (cac != NULL) {
        cac->RemoveAll();
    }
    SAFE_DELETE_ARRAY(m_slots);
}

u16 AnimSlotPool::Acquire()
{
    u16 anim = 0;
    if (m_slots != NULL) {
        for (u32 i = 0; i < m_count; i++) {
            if (!m_slots[i].used) {
                anim = m_slots[i].anim;
                m_slots[i].used = TRUE;
                break;
            }
        }
    }
    return anim;
}

void AnimSlotPool::Free(u16 anim)
{
    if (m_slots != NULL) {
        for (u32 i = 0; i < m_count; i++) {
            if (m_slots[i].used && anim == m_slots[i].anim) {
                m_slots[i].used = FALSE;
            }
        }
    }
}
