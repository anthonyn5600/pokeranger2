#ifndef POKERANGER2_MISSIONQUESTMAP_HPP
#define POKERANGER2_MISSIONQUESTMAP_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "FieldData.hpp"
#include "MessageTable.hpp"
#include "MissionQuestInfo.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "RegionMap.hpp"
#include "common.hpp"

// Defined in ov8: mission/quest map on the sub screen (CMissionQuestScene)
class MissionQuestMap {
public:
    MissionQuestMap(CGame *game);
    ~MissionQuestMap();

    void Init();
    void Update();
    void Render();
    void OnVBlank();
    void ov8_0211CEAC();
    void Release();
    void WriteOam();
    void Load();
    BOOL Start();
    BOOL Setup();
    void UpdateInput();
    void Close();
    void RequestPlaceName(u16 id);
    void DrawPlaceName();
    void ShowMissionPlace();
    void SetSpriteToArea(int idx, u16 id);
    void SelectMissionPlace();
    void SelectCurrentArea();
    void SelectArea(u16 id);
    void SetAreaMarker(u16 id, int mode);
    void FadeIn();
    void FadeOut();
    BOOL IsFading();
    int GetResult();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    RegionMap *unk_08;
    MissionQuestInfo *unk_0C;
    FieldData *unk_10;
    MessageTable *unk_14;
    OamSpriteSet *unk_18;
    OamSpriteSet *unk_1C;
    u32 unk_20;
    OamSprite *unk_24[6];
    u16 unk_3C;
    u16 unk_3E;
    CGame *unk_40;
};

STATIC_SIZE_ASSERT(MissionQuestMap, 0x44);

#endif // POKERANGER2_MISSIONQUESTMAP_HPP
