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

    void ov8_0211CD2C();
    void ov8_0211CD8C();
    void ov8_0211CE08();
    void ov8_0211CE78();
    void ov8_0211CEAC();
    void ov8_0211CECC();
    void ov8_0211CFC4();
    void ov8_0211CFF0();
    BOOL ov8_0211D310();
    BOOL ov8_0211D328();
    void ov8_0211D358();
    void ov8_0211D444();
    void ov8_0211D478(u16 id);
    void ov8_0211D488();
    void ov8_0211D55C();
    void ov8_0211D5B8(int idx, u16 id);
    void ov8_0211D604();
    void ov8_0211D628();
    void ov8_0211D654(u16 id);
    void ov8_0211D678(u16 id, int mode);
    void ov8_0211D688();
    void ov8_0211D6CC();
    BOOL ov8_0211D710();
    int ov8_0211D758();

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
