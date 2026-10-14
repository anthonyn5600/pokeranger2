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

    void ov8_0211D7E0();
    void ov8_0211D818();
    void ov8_0211D8A0();
    void ov8_0211D8AC();
    void ov8_0211D8B8();
    void ov8_0211D8EC();
    void ov8_0211D9E8();
    void ov8_0211DA98();
    BOOL ov8_0211E0A4(int mode, int arg1);
    void ov8_0211E0FC();
    BOOL ov8_0211E148();
    void ov8_0211E164();
    void ov8_0211E170();
    int ov8_0211E32C();
    int ov8_0211E380();
    int ov8_0211E3A4();

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
