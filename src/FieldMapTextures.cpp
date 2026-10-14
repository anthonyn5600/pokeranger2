#include <nitro.h>
#include <nnsys.h>

#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "field/CFieldMap.hpp"
#include "heap.hpp"

FieldMapTextures::FieldMapTextures()
{
}

FieldMapTextures::~FieldMapTextures()
{
    Release();
}

BOOL FieldMapTextures::AddImage(VramImage *image, NNSGfdTexKey key)
{
    m_images.push_back(image);
    m_texKeys.push_back(key);
    return TRUE;
}

BOOL FieldMapTextures::AddPalette(VramPalette *palette, NNSGfdPlttKey key, void *data)
{
    m_palettes.push_back(palette);
    m_plttKeys.push_back(key);
    m_paletteData.push_back(data);
    return TRUE;
}

void FieldMapTextures::Release()
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
