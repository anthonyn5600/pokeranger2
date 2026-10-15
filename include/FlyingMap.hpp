#ifndef POKERANGER2_FLYINGMAP_HPP
#define POKERANGER2_FLYINGMAP_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "FieldData.hpp"
#include "MessageTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "RegionMap.hpp"
#include "SubScreenPokemonInfo.hpp"
#include "common.hpp"

// Fly destination (ov9 table)
struct FlyDestination {
    u16 mapId;
    s16 x;
    s16 y;
    u16 unk_06;
    u16 unk_08;
    u8 unk_0A;
    u8 placeId;
    u16 unk_0C;
    u16 messageId;
};

STATIC_SIZE_ASSERT(FlyDestination, 0x10);

// Defined in ov9: fly destination map (CFlyingScene)
class FlyingMap {
public:
    FlyingMap(CGame *game);
    ~FlyingMap();

    void Init();
    void Update();
    void Render();
    void OnVBlank();
    void ResetMarker();
    void Release();
    void WriteOam();
    void InitGraphics();
    BOOL Start();
    BOOL Setup();
    void MarkDestinations();
    void UpdateSelect();
    void Close();
    void SetSelected(u16 id);
    void PrintPlaceName();
    BOOL UpdateButtonAnim();
    void ShowConfirmMessage();
    void SelectCurrentArea();
    void PressFlyButton();
    void SelectArea(u16 id);
    u16 FindDestination(u8 placeId);
    void SetDestination(u16 placeId);
    void SetMarker(u16 id, int mode);
    void FadeIn();
    void FadeOut();
    BOOL IsFading();
    int GetResult();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    int unk_08; // frame counter
    u32 unk_0C;
    int unk_10; // flew
    RegionMap *unk_14;
    SubScreenPokemonInfo *unk_18;
    FieldData *unk_1C;
    MessageTable *unk_20;
    OamSpriteSet *unk_24;
    u32 unk_28;
    u32 unk_2C;
    OamSpriteSet *unk_30;
    u8 *unk_34;
    u32 unk_38;
    OamSprite *unk_3C[2];
    int unk_44;
    u16 unk_48;
    u16 unk_4A;
    u32 unk_4C;
    int unk_50;
    CGame *unk_54;
};

STATIC_SIZE_ASSERT(FlyingMap, 0x58);

#endif // POKERANGER2_FLYINGMAP_HPP
