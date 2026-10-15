#include "CellCharBuffer.hpp"

#include <nnsys.h>

#include "VramImage.hpp"
#include "file/CNCERFile.hpp"
#include "heap.hpp"

#define GET_OAM_SHAPE(attr) (u8)(((attr)->attr0 & 0xC000) >> 0xE)
#define GET_OAM_SIZE(attr)  (u8)(((attr)->attr1 & 0xC000) >> 0xE)

extern "C" {
extern u32 DAT_02084308[4][4];
extern u32 DAT_02084348[4][4];
extern u32 DAT_02084388[4][4];
}

CellCharBuffer::CellCharBuffer()
{
    Clear();
}

CellCharBuffer::~CellCharBuffer()
{
    Release();
}

void CellCharBuffer::Clear()
{
    m_image = NULL;
    m_cells = NULL;
    m_size = 0;
    m_buffer = NULL;
    m_vramAddr = 0;
}

void CellCharBuffer::Release()
{
    ReleaseImage();
    ReleaseCells();
}

void CellCharBuffer::SetImage(VramImage *arg0)
{
    ReleaseImage();
    m_image = arg0;
}

void CellCharBuffer::SetCells(CNCERFile *arg0)
{
    ReleaseCells();
    m_cells = arg0;

    u32 v0 = 0;

    for (u16 i = 0;; ++i) {
        const NNSG2dCellData *cellData = NNS_G2dGetCellDataByIdx(arg0->unk_B8, i);

        if (cellData == NULL) {
            break;
        }

        u32 v1 = GetCellCharSize(cellData);

        if (v0 < v1) {
            v0 = v1;
        }
    }

    m_size = v0 * 32;
    m_buffer = (u8 *)Heap_Alloc(m_size);
}

void CellCharBuffer::ReleaseImage()
{
    m_image = NULL;
}

void CellCharBuffer::ReleaseCells()
{
    if (m_buffer != NULL) {
        Heap_Free(m_buffer);
        m_buffer = NULL;
    }

    m_cells = NULL;
}

u32 CellCharBuffer::GetCellCharSize(const NNSG2dCellData *cellData)
{
    u32 res = 0;
    NNSG2dCellOAMAttrData *iter = cellData->pOamAttrArray;

    for (int i = 0; i < cellData->numOAMAttrs; ++i) {
        res += DAT_02084348[GET_OAM_SHAPE(iter)][GET_OAM_SIZE(iter)];
        ++iter;
    }

    return res;
}

u32 CellCharBuffer::LoadCell(u16 arg0)
{
    if (m_cells == NULL) {
        return 0;
    }

    const NNSG2dCellData *cellData = NNS_G2dGetCellDataByIdx(m_cells->unk_B8, arg0);

    if (cellData == NULL) {
        return 0;
    }

    u32 res = 0;
    int i = 0;
    NNSG2dCellOAMAttrData *iter = cellData->pOamAttrArray;

    for (; i < cellData->numOAMAttrs; ++i) {
        res += CopyOamChars(&m_buffer[res], GET_OAM_SHAPE(iter), GET_OAM_SIZE(iter), iter->attr2 & GX_OAM_ATTR2_NAME_MASK);
        ++iter;
    }

    DC_FlushRange(m_buffer, m_size);
    m_cell = arg0;

    return res;
}

u32 CellCharBuffer::CopyOamChars(u8 *arg0, u8 arg1, u8 arg2, u16 arg3)
{
    unsigned res = 0;
    u32 v0;
    u32 v1 = (DAT_02084308[arg1][arg2] * 8) / 2;
    u32 v2 = m_image->unk_04->szByte;
    u8 *v3 = m_image->func0();
    u8 *v4 = (v3 + ((arg3 % 32) * 4)) + ((((arg3 & 0xFFFF) / 32) * m_image->unk_32) * 4);
    v0 = DAT_02084388[arg1][arg2] * 8;

    for (int i = 0; i < v0; ++i) {
        if (v4 - v3 < v2) {
            MI_CpuCopy8(v4, arg0, v1);
        } else {
            MI_CpuClear8(arg0, v1);
        }

        arg0 += v1;
        res += v1;

        v4 += m_image->unk_32 >> 1;
    }

    return res;
}

u32 CellCharBuffer::SetVramAddr(u32 arg0)
{
    u32 v0 = m_vramAddr;
    m_vramAddr = arg0;

    return v0;
}
