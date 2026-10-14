#ifndef POKERANGER2_SUBSCREENICONMENU_HPP
#define POKERANGER2_SUBSCREENICONMENU_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class Camera2D;
class OamSprite;
class OamSpriteSet;
class GridOverlay;
class SaveDialog;

// Sub-screen 3x3 icon menu: the icons pop in/out with a scale animation over a grid overlay
class SubScreenIconMenuView {
public:
    SubScreenIconMenuView(CGame *game);
    ~SubScreenIconMenuView();

    void Update();
    void Render();
    void sub_020237E0();
    void Init();
    void CreateIcons();
    void Release();
    void SetVisible(BOOL visible);
    void sub_02023B54();
    BOOL IsBusy();
    void SetAffineScales(BOOL scaled);
    void UpdateIcon(u16 index);
    void StartPop(int popFrames, int bounceFrames, BOOL opening);
    void Draw();
    void sub_02024214();
    BOOL sub_02024380();
    BOOL sub_020243CC();
    void sub_020243F0(int timer);
    BOOL sub_02024440();
    void OpenSaveDialog();
    BOOL sub_020244DC();
    void ReleaseSprites();
    void CloseIcons();
    void OpenIcons();
    void StartClose();
    void StartOpen();
    void sub_0202462C();
    void sub_02024690();
    BOOL IsFading();
    BOOL IsActive();
    int GetSelection();
    fx32 Quadratic(fx32 a, fx32 b, fx32 t, fx32 c);
    fx32 SolveQuadratic(fx32 start, fx32 end, fx32 b, fx32 t);

public:
    u16 unk_00;
    u8 unk_02[6];
    int unk_08;
    Camera2D *unk_0C;
    u8 unk_10[8];
    GridOverlay *unk_18;
    OamSpriteSet *unk_1C;
    OamSpriteSet *unk_20;
    OamSprite *unk_24[9];
    OamSprite *unk_48[9];
    OamSprite *unk_6C;
    int unk_70;
    int unk_74;
    fx32 unk_78;
    fx32 unk_7C;
    int unk_80[9];
    int unk_A4[9];
    fx32 unk_C8[9];
    fx32 unk_EC[9];
    BOOL unk_110;
    BOOL unk_114;
    int unk_118;
    SaveDialog *unk_11C;
    CGame *unk_120;
};

STATIC_SIZE_ASSERT(SubScreenIconMenuView, 0x124);

class SubScreenIconMenu {
public:
    SubScreenIconMenu(CGame *game);
    ~SubScreenIconMenu();

    void Update();
    void Render();
    void sub_02023470();
    void Init();
    void Open();
    void sub_020234F0();
    void sub_0202350C(int timer);
    BOOL IsActive();
    int GetSelection();

public:
    u16 unk_00;
    u16 unk_02;
    int unk_04;
    SubScreenIconMenuView *unk_08;
    CGame *unk_0C;
};

STATIC_SIZE_ASSERT(SubScreenIconMenu, 0x10);

#endif // POKERANGER2_SUBSCREENICONMENU_HPP
