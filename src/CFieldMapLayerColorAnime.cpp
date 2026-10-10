#include <nitro.h>
#include <string.h>

#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "heap.hpp"

CFieldMapLayerColorAnime::CFieldMapLayerColorAnime()
{
    m_keys = NULL;
    m_keyCount = 0;
    m_keyIndex = 0;
    m_fading = FALSE;
    m_timer = 0;
}

CFieldMapLayerColorAnime::~CFieldMapLayerColorAnime()
{
    Release();
}

BOOL CFieldMapLayerColorAnime::Load(void *data)
{
    BOOL result;
    int size;

    memcpy(&size, data, 4);
    u8 *p = (u8 *)data + 4;
    result = CFieldMapLayerNormalView::Load(p + size);
    memcpy(&m_keyCount, p, 4);
    p += 4;
    m_keys = (FieldMapColorKey *)Heap_AllocWithAlignment(m_keyCount * sizeof(FieldMapColorKey), 4);
    for (int i = 0; i < m_keyCount; i++) {
        m_keys[i].r = p[0];
        m_keys[i].g = p[1];
        m_keys[i].b = p[2];
        m_keys[i].unk_03 = p[3];
        memcpy(&m_keys[i].holdTime, p + 4, 2);
        memcpy(&m_keys[i].fadeTime, p + 6, 2);
        p += 8;
    }
    return result;
}

void CFieldMapLayerColorAnime::Release()
{
    if (m_keys != NULL) {
        Heap_Free(m_keys);
        m_keys = NULL;
    }
    m_keyCount = 0;
    m_keyIndex = 0;
    m_fading = FALSE;
    m_timer = 0;
    CFieldMapLayerNormalView::Release();
}

void CFieldMapLayerColorAnime::Update(int fps)
{
    FieldMapColorKey *key = &m_keys[m_keyIndex];
    FieldMapColorKey *next = &m_keys[(m_keyIndex + 1) % m_keyCount];
    m_timer += 60 / fps;
    if (!m_fading) {
        if (m_timer >= key->holdTime) {
            m_fading = TRUE;
            m_timer = 0;
        }
    } else if (m_timer >= key->fadeTime) {
        m_fading = FALSE;
        m_timer = 0;
        m_keyIndex = (m_keyIndex + 1) % m_keyCount;
        key = &m_keys[m_keyIndex];
        next = &m_keys[(m_keyIndex + 1) % m_keyCount];
    }
    GXRgb color;
    if (!m_fading) {
        color = GX_RGB(key->r, key->g, key->b);
    } else {
        int len;
        int rest;
        int t;
        t = m_timer;
        len = key->fadeTime;
        rest = len - t;
        color = GX_RGB((u8)((key->r * rest + next->r * t) / len), (u8)((key->g * rest + next->g * t) / len), (u8)((key->b * rest + next->b * t) / len));
    }
    if (m_static != NULL) {
        m_static->m_color = color;
    }
    if (m_chara != NULL) {
        m_chara->m_color = color;
    }
}

int CFieldMapLayerColorAnime::GetType()
{
    return 12;
}
