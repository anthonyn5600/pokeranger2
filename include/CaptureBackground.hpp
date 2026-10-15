#ifndef POKERANGER2_CAPTUREBACKGROUND_HPP
#define POKERANGER2_CAPTUREBACKGROUND_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

class CSoftwareSprite;
class VramImage;
class VramPalette;
class CNCERFile;

// Battle capture background (data/battle/bg/capbg%03d_LZ.bin)
class CaptureBackground {
public:
    CaptureBackground(u8 id);
    ~CaptureBackground();

    void Load();
    void Release();

public:
    u8 m_id;
    CSoftwareSprite *m_sprite;
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(CaptureBackground, 0x1C);

class Camera2D;

extern "C" {
void CaptureBackground_Render(CaptureBackground *obj, Camera2D *camera);
int CaptureBackground_SetZ(CaptureBackground *obj, int z);
}

#endif // POKERANGER2_CAPTUREBACKGROUND_HPP
