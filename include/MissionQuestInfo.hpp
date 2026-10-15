#ifndef POKERANGER2_MISSIONQUESTINFO_HPP
#define POKERANGER2_MISSIONQUESTINFO_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "Camera2D.hpp"
#include "FieldDrawActorDataPool.hpp"
#include "MessageTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"

// Defined in ov8: mission/quest info panel on the main screen (CMissionQuestScene)
class MissionQuestInfo {
public:
    MissionQuestInfo(CGame *game);
    ~MissionQuestInfo();

    void Init();
    void Update();
    void Render();
    void OnVBlank();
    void ov8_0211D8B8();
    void Release();
    void Draw();
    void Load();
    BOOL SetMode(int mode, int arg1);
    void UpdateTabs();
    BOOL Setup();
    void RequestDrawTexts();
    void DrawTexts();
    int GetMissionPlace();
    int GetMissionIndex();
    int GetQuestIndex();

public:
    u16 unk_00;
    int unk_04; // text needs redraw
    Camera2D *unk_08;
    FieldDrawActorDataPool *unk_0C;
    OamSpriteSet *unk_10;
    u32 unk_14;
    OamSpriteSet *unk_18;
    OamSprite *unk_1C[6];
    int unk_34[2];
    MessageTable *unk_3C; // mission info
    MessageTable *unk_40; // quest info
    u32 unk_44;
    u16 unk_48;
    u16 unk_4A;
    u32 unk_4C;
    CFieldActor unk_50[2];
    int unk_210; // 1 mission, 0 quest
    int unk_214; // has a mission
    int unk_218; // has a quest
    CGame *unk_21C;
};

STATIC_SIZE_ASSERT(MissionQuestInfo, 0x220);

#endif // POKERANGER2_MISSIONQUESTINFO_HPP
