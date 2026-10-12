#ifndef POKERANGER2_BATTLE_UNKCLASS_02128E88_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128E88_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_020074D4;
class UnkClass_02007AA4;
class CNCERFile;
class UnkClass_02008788;

// Defined in ov1
class UnkClass_02128E88 {
public:
    UnkClass_02128E88();
    ~UnkClass_02128E88();
    void ov1_02128EB0();
    void ov1_021290D4();

    inline UnkClass_020074D4 *GetImage(u8 idx)
    {
        return m_image[idx];
    }
    inline UnkClass_02007AA4 *GetPalette(u8 idx)
    {
        return m_palette[idx];
    }
    inline CNCERFile *GetCells(u8 idx)
    {
        return m_cells[idx];
    }
    inline UnkClass_02008788 *GetAnim(u8 idx)
    {
        return m_anim[idx];
    }

public:
    // Index 0 is unused
    UnkClass_020074D4 *m_image[5];
    UnkClass_02007AA4 *m_palette[5];
    CNCERFile *m_cells[5];
    UnkClass_02008788 *m_anim[5];
    NNSGfdTexKey m_texKey[5];
    NNSGfdPlttKey m_plttKey[5];
};

STATIC_SIZE_ASSERT(UnkClass_02128E88, 0x78);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128E88_HPP
