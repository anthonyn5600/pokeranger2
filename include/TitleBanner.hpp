#ifndef POKERANGER2_TITLEBANNER_HPP
#define POKERANGER2_TITLEBANNER_HPP

#include <nitro.h>

#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "common.hpp"

// Title / mission banner sprites shown by the field scene (type < 100: mission "mitNNN", < 200: title101, else
// title100).
class TitleBanner {
public:
    TitleBanner();
    ~TitleBanner();

    void Show(int type);
    void LoadTitle100();
    void LoadMission();
    void LoadTitle101();
    void Update();
    void UpdateTitle100();
    void UpdateMission();
    void UpdateTitle101();
    void Render();
    void RenderTitle100();
    void RenderMission();
    void RenderTitle101();
    int GetState();
    void Release();

public:
    OamSpriteSet *unk_00;
    OamSpriteSet *unk_04;
    OamSpriteSet *unk_08;
    OamSprite *unk_0C;
    OamSprite *unk_10;
    OamSprite *unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
    int unk_24;
    int unk_28;
};

STATIC_SIZE_ASSERT(TitleBanner, 0x2C);

#endif // POKERANGER2_TITLEBANNER_HPP
