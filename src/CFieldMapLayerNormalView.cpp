#include <nitro.h>
#include <string.h>

#include "UnkClass_02003718.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"

int CFieldMapLayerNormalView::Draw(UnkClass_02003718 *camera)
{
    int count = 0;
    if (m_chara != NULL) {
        m_chara->unk_04 = unk_04;
        count += m_chara->Draw(camera);
    }
    if (m_static != NULL) {
        m_static->unk_04 = unk_04 - count;
        count += m_static->Draw(camera);
    }
    return count;
}

CFieldMapLayerNormalView::CFieldMapLayerNormalView()
{
    m_static = NULL;
    m_chara = NULL;
}

CFieldMapLayerNormalView::~CFieldMapLayerNormalView()
{
    Release();
}

BOOL CFieldMapLayerNormalView::Load(void *data)
{
    u8 *p;
    int staticSize;
    int charaSize;
    int staticType;
    int charaType;
    u8 *staticData;
    u8 *charaData;

    Release();
    p = (u8 *)data;
    memcpy(&staticSize, p, 4);
    memcpy(&charaSize, p + 4, 4);
    staticData = p + 8;
    charaData = staticData + staticSize;
    if (staticSize != 0) {
        memcpy(&staticType, staticData, 4);
        if (staticType == 13) {
            m_static = new CFieldMapLayerStatic();
            m_static->m_textures = m_textures;
            m_static->Load(staticData + 4);
            m_offsetX = m_static->m_offsetX;
            m_offsetY = m_static->m_offsetY;
        }
    }
    if (charaSize != 0) {
        memcpy(&charaType, charaData, 4);
        if (charaType == 14) {
            m_chara = new CFieldMapLayerCharaTrans();
            m_chara->m_mct = m_mct;
            m_chara->Load(charaData + 4);
            m_offsetX = m_chara->m_offsetX;
            m_offsetY = m_chara->m_offsetY;
        }
    }
    return TRUE;
}

void CFieldMapLayerNormalView::Release()
{
    SAFE_DELETE(m_static);
    SAFE_DELETE(m_chara);
}

void CFieldMapLayerNormalView::SetPolygonId(int id)
{
    if (m_static != NULL) {
        m_static->SetPolygonId(id);
    }
}

int CFieldMapLayerNormalView::GetPolygonCount()
{
    int count = 0;
    if (m_chara != NULL) {
        count += m_chara->GetPolygonCount();
    }
    if (m_static != NULL) {
        count += m_static->GetPolygonCount();
    }
    return count;
}

int CFieldMapLayerNormalView::GetType()
{
    return 2;
}
