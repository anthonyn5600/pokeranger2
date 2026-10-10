#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "field/CFieldMap.hpp"
#include "heap.hpp"

UnkClass_021302BC::UnkClass_021302BC()
{
}

UnkClass_021302BC::~UnkClass_021302BC()
{
    Release();
}

BOOL UnkClass_021302BC::AddImage(UnkClass_020074D4 *image, NNSGfdTexKey key)
{
    m_images.push_back(image);
    m_texKeys.push_back(key);
    return TRUE;
}

BOOL UnkClass_021302BC::AddPalette(UnkClass_02007AA4 *palette, NNSGfdPlttKey key, void *data)
{
    m_palettes.push_back(palette);
    m_plttKeys.push_back(key);
    m_paletteData.push_back(data);
    return TRUE;
}

void UnkClass_021302BC::Release()
{
    for (int i = 0; i < m_images.size(); i++) {
        SAFE_DELETE(m_images[i]);
    }
    for (int i = 0; i < m_palettes.size(); i++) {
        SAFE_DELETE(m_palettes[i]);
    }
    for (int i = 0; i < m_texKeys.size(); i++) {
        NNS_GfdFreeLnkTexVram(m_texKeys[i]);
    }
    for (int i = 0; i < m_plttKeys.size(); i++) {
        NNS_GfdFreeLnkPlttVram(m_plttKeys[i]);
    }
    for (int i = 0; i < m_paletteData.size(); i++) {
        if (m_paletteData[i] != NULL) {
            Heap_Free(m_paletteData[i]);
            m_paletteData[i] = NULL;
        }
    }
}
