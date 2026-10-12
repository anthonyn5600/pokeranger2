#include <nitro.h>
#include <string.h>

#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"

BOOL CFieldMapLayerUVScroll::Load(void *data)
{
    u8 *p = (u8 *)data;

    m_speedU = 0;
    m_speedV = 0;
    m_u = 0;
    m_v = 0;
    memcpy(&m_speedU, p, 4);
    p += 4;
    memcpy(&m_speedV, p, 4);
    p += 4;
    return CFieldMapLayerStatic::Load(p);
}

void CFieldMapLayerUVScroll::Update(int fps)
{
    m_u += m_speedU * 60 / fps;
    if (m_u >= FX32_CONST(256)) {
        m_u -= FX32_CONST(256);
    } else if (m_u <= -FX32_CONST(256)) {
        m_u += FX32_CONST(256);
    }
    m_v += m_speedV * 60 / fps;
    if (m_v >= FX32_CONST(256)) {
        m_v -= FX32_CONST(256);
    } else if (m_v <= -FX32_CONST(256)) {
        m_v += FX32_CONST(256);
    }
}

int CFieldMapLayerUVScroll::Draw(Camera2D *camera)
{
    // The game's MTX_Identity43_ fills a 4x4 matrix (see the NitroSDK patch for it).
    MtxFx44 mtx;
    MTX_Identity43((MtxFx43 *)&mtx);
    mtx._30 = m_u;
    mtx._31 = m_v;
    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_LoadTexMtxTexCoord(&mtx);
    G3_MtxMode(GX_MTXMODE_POSITION);
    int count = CFieldMapLayerStatic::Draw(camera);
    MTX_Identity43((MtxFx43 *)&mtx);
    G3_MtxMode(GX_MTXMODE_TEXTURE);
    G3_LoadTexMtxTexCoord(&mtx);
    G3_MtxMode(GX_MTXMODE_POSITION);
    return count;
}

int CFieldMapLayerUVScroll::GetPolygonCount()
{
    return m_pieceCount > 0 ? 1 : 0;
}

int CFieldMapLayerUVScroll::GetType()
{
    return 11;
}

CFieldMapLayerUVScroll::~CFieldMapLayerUVScroll()
{
}
