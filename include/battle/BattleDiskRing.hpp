#ifndef POKERANGER2_BATTLE_BATTLEDISKRING_HPP
#define POKERANGER2_BATTLE_BATTLEDISKRING_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"

class CSoftwareSprite;
class GraphicsSet;
class CellAnimController;

// Defined in ov1: the BSE i071 ring around the disk (CBattleDisk::unk_264)
class BattleDiskRing {
public:
    BattleDiskRing();
    ~BattleDiskRing();
    void Update();
    void UpdateOpen();
    void UpdateShown();
    void UpdateClose();
    void Render(Camera2D *camera);
    void Open();
    void Close();
    int SetZ(int z);
    void SetLineAlpha(u8 alpha);

    inline void SetPos(Point2D pos)
    {
        m_pos = pos;
    }

public:
    int m_state;
    u16 m_frame;
    u16 m_angle;
    fx32 m_radius;
    Point2D m_pos;
    GraphicsSet *m_res;
    CSoftwareSprite *m_sprites0[3];
    CSoftwareSprite *m_sprites1[3];
    CellAnimController *m_anim;
    u16 m_cells0[3];
    u16 m_cells1[3];
    CPrimitiveLINE m_lines[3][8];
};

STATIC_SIZE_ASSERT(BattleDiskRing, 0x400);

#endif // POKERANGER2_BATTLE_BATTLEDISKRING_HPP
