// PC port only: the game's stand-in classes (raw byte prefixes in front of the one field it uses) must keep lining up
// with the real classes behind them now that pointers are 8 bytes.

#include <stddef.h>

#include "CellCharBuffer.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CPrimitive.hpp"
#include "primitive/CSoftwareSprite.hpp"

#pragma GCC diagnostic ignored "-Winvalid-offsetof"

static_assert(offsetof(UnkClass_CPrimitive_ImageProxy, imageProxy) == offsetof(VramImage, unk_08), "VramImage");
static_assert(offsetof(UnkClass_CPrimitive_ImagePaletteProxy, imagePlttProxy) == offsetof(VramPalette, unk_08), "VramPalette");
static_assert(offsetof(UnkClass_CSoftwareSprite_30, unk_08) == offsetof(CellCharBuffer, m_vramAddr), "CellCharBuffer");
static_assert(offsetof(UnkClass_CSoftwareSprite_38, unk_B8) == offsetof(CNCERFile, unk_B8), "CNCERFile");
