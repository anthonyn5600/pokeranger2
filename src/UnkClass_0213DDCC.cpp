#include "UnkClass_0213DDCC.hpp"

#include <nitro.h>

UnkClass_0213DDCC::UnkClass_0213DDCC()
{
    MAIN_BSS_0210CA58 = this;
    m_count = 0;
    m_items = NULL;
    m_draw = FALSE;
}

UnkClass_0213DDCC::~UnkClass_0213DDCC()
{
    Clear();
    MAIN_BSS_0210CA58 = NULL;
}

void UnkClass_0213DDCC::Create(int count)
{
    Clear();
    m_count = count;
    m_items = new CFieldEventRect *[count];
    for (int i = 0; i < count; i++) {
        m_items[i] = NULL;
    }
}

void UnkClass_0213DDCC::Clear()
{
    if (m_count > 0 && m_items != NULL) {
        for (int i = 0; i < m_count; i++) {
            SAFE_DELETE(m_items[i]);
        }
    }
    if (m_items != NULL) {
        delete[] m_items;
        m_items = NULL;
    }
    m_count = 0;
}

BOOL UnkClass_0213DDCC::Update(Point2D *pos, int group, BOOL run)
{
    BOOL result = FALSE;
    if (m_items != NULL) {
        if (run) {
            for (int i = 0; i < m_count; i++) {
                CFieldEventRect *rect = m_items[i];
                if (rect != NULL && rect->unk_18 != 0) {
                    result |= rect->Update(pos, group);
                }
            }
        } else {
            for (int i = 0; i < m_count; i++) {
                CFieldEventRect *rect = m_items[i];
                if (rect != NULL && rect->unk_18 != 0) {
                    result |= rect->IsInside(pos, group);
                }
            }
        }
    }
    return result;
}

void UnkClass_0213DDCC::Draw(Camera2D *camera)
{
    if (m_items == NULL || !m_draw) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        if (m_items[i] != NULL) {
            m_items[i]->Draw(camera);
        }
    }
}
