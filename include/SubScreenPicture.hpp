#ifndef POKERANGER2_SUBSCREENPICTURE_HPP
#define POKERANGER2_SUBSCREENPICTURE_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;

// Sub-screen picture (uppict/uppict%03d_) on BG0 (FieldSubScreen::unk_54)
class SubScreenPicture {
public:
    SubScreenPicture(CGame *game);
    ~SubScreenPicture();

    void Release();
    void Update();
    void Render();
    void Init();
    BOOL Load(int id);
    void SetupBG();

public:
    u32 unk_00;
    CGame *unk_04;
};

STATIC_SIZE_ASSERT(SubScreenPicture, 0x8);

#endif // POKERANGER2_SUBSCREENPICTURE_HPP
