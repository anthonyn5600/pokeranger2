#ifndef POKERANGER2_SCENE_CTITLEBG_HPP
#define POKERANGER2_SCENE_CTITLEBG_HPP

#include <nitro.h>

#include "common.hpp"

// Scrolling day/night background of the title screen (main BG0-BG3)
class CTitleBG {
public:
    struct LayerConfig {
        int screenSize;
        int colorMode;
        int scrollType;
        fx32 speed;
    };

    CTitleBG();
    ~CTitleBG();
    void SetupBG(int mode);
    void Load(int mode);
    void ResetOffsets();
    void Update();
    void Apply();
    void SetOffset(int bg, int h, int v);

public:
    int m_mode;
    fx32 m_scroll[4];
};

STATIC_SIZE_ASSERT(CTitleBG, 0x14);

#endif // POKERANGER2_SCENE_CTITLEBG_HPP
