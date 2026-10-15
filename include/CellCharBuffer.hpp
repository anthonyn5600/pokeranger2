#ifndef POKERANGER2_CELLCHARBUFFER_HPP
#define POKERANGER2_CELLCHARBUFFER_HPP

#include <nitro.h>

#include "VramImage.hpp"
#include "common.hpp"
#include "file/CNCERFile.hpp"

class CellCharBuffer {
public:
    CellCharBuffer();
    ~CellCharBuffer();

    void Clear();
    void Release();
    void SetImage(VramImage *arg0);
    void SetCells(CNCERFile *arg0);
    void ReleaseImage();
    void ReleaseCells();
    u32 GetCellCharSize(const NNSG2dCellData *cellData);
    u32 LoadCell(u16 arg0);
    u32 CopyOamChars(u8 *arg0, u8 arg1, u8 arg2, u16 arg3);
    u32 SetVramAddr(u32 arg0);

public:
    VramImage *m_image;
    CNCERFile *m_cells;
    u32 m_vramAddr;
    u16 m_cell;
    u32 m_size;
    u8 *m_buffer;
};

STATIC_SIZE_ASSERT(CellCharBuffer, 0x18);

#endif // POKERANGER2_CELLCHARBUFFER_HPP
