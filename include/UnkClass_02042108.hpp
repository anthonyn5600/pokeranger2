#ifndef POKERANGER2_UNKCLASS_02042108_HPP
#define POKERANGER2_UNKCLASS_02042108_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

class CSoftwareSprite;
class UnkClass_020074D4;
class UnkClass_02007AA4;
class CNCERFile;

// Battle capture background (data/battle/bg/capbg%03d_LZ.bin)
class UnkClass_02042108 {
public:
    UnkClass_02042108(u8 id);
    ~UnkClass_02042108();

    void Load();
    void Release();

public:
    u8 m_id;
    CSoftwareSprite *m_sprite;
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_02042108, 0x1C);

class Camera2D;

extern "C" {
void sub_020423F4(UnkClass_02042108 *obj, Camera2D *camera);
int sub_0204240C(UnkClass_02042108 *obj, int z);
}

#endif // POKERANGER2_UNKCLASS_02042108_HPP
