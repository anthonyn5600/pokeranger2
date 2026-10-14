#ifndef POKERANGER2_SUBSCREENAREAMAP_HPP
#define POKERANGER2_SUBSCREENAREAMAP_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class OamSprite;
class OamSpriteSet;
class BGLayer;
class MessageTable;

struct UnkStruct_0202163C_5C {
    OamSprite *unk_00;
    s16 unk_04; // x
    s16 unk_06; // y
    s16 unk_08; // kind
};

// Sub-screen area map with the place name (FieldSubScreen::unk_18)
class SubScreenAreaMap {
public:
    SubScreenAreaMap(CGame *game);
    ~SubScreenAreaMap();

    void Release();
    void Update();
    void Render();
    void Init();
    void Draw();
    void DrawIcons(int x, int y);
    void Load();
    void LoadOAM();
    void LoadOAMToVram();
    void LoadMapScr();
    void Hide();
    void DrawPlaceName();
    void LoadToVram();
    void SetupBG();
    BOOL Show(int mapId, int x, int y);
    BOOL SetMap(int mapId, int x, int y);
    void SetPos(int x, int y);
    void ClearIcons();
    BOOL AddIcon(int x, int y, int kind);

public:
    u8 unk_00[0x30];
    int unk_30; // x
    int unk_34; // y
    int unk_38; // map id
    BGLayer *unk_3C;
    BGLayer *unk_40;
    BGLayer *unk_44;
    OamSpriteSet *unk_48;
    OamSpriteSet *unk_4C;
    OamSpriteSet *unk_50;
    OamSprite *unk_54;
    OamSprite *unk_58;
    UnkStruct_0202163C_5C unk_5C[5];
    u16 unk_98;
    u32 unk_9C;
    int unk_A0; // OAM offset
    MessageTable *unk_A4;
    CGame *unk_A8;
};

STATIC_SIZE_ASSERT(SubScreenAreaMap, 0xAC);

#endif // POKERANGER2_SUBSCREENAREAMAP_HPP
