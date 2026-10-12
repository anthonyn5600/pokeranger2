#ifndef POKERANGER2_UNKCLASS_02022404_HPP
#define POKERANGER2_UNKCLASS_02022404_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class UnkClass_0201B724;
class UnkClass_0201CA6C;
class UnkClass_0202163C;
class UnkClass_0202229C;
class UnkClass_020247CC;
class UnkClass_02025648;

// Sub-screen controller of the field (CFieldScene::unk_0054): switches between the area map, the panels, the
// pokemon info and target screens and the picture, with fades
class UnkClass_02022404 {
public:
    UnkClass_02022404(CGame *game);
    ~UnkClass_02022404();

    void Update();
    void sub_02022710();
    void Render();
    void sub_020227AC();
    void Init();
    void sub_020228C0();
    void sub_020228C4();
    void sub_020228D4();
    void sub_020228E4();
    void sub_020228F4();
    void sub_02022904();
    void sub_02022914();
    void sub_02022924();
    BOOL sub_0202293C(u32 mapId, int x, int y);
    void sub_020229F4(int mapId, int x, int y);
    void sub_02022A98(int x, int y);
    BOOL sub_02022AB4();
    BOOL sub_02022B20();
    BOOL sub_02022B60(u32 id, int arg2);
    BOOL sub_02022BC0(u32 id);
    BOOL sub_02022C1C();
    BOOL sub_02022C74();
    BOOL sub_02022D04();
    void sub_02022D88();
    void sub_02022DD4();
    void sub_02022E48(int picId);
    void sub_02022EC4();
    BOOL sub_02022ED0();
    BOOL sub_02022EE8();
    BOOL sub_02022F50();
    void sub_02022FA8();
    int sub_02022FF4();
    void sub_02023014();
    int sub_02023060();
    BOOL sub_02023078();
    BOOL sub_020230D4();
    void sub_02023134();
    void sub_02023160();
    void sub_02023180();
    void sub_02023198(int arg1);
    void sub_020231A0();
    void sub_02023200();
    void sub_02023218(int x, int y, int kind);
    void sub_02023230(u16 duration);
    BOOL sub_02023298(u16 duration);
    BOOL sub_0202331C();
    static UnkClass_02022404 *GetInstance();
    BOOL sub_020233B4();

    static UnkClass_02022404 *sInstance;

public:
    u16 unk_00; // mode
    u16 unk_02; // next mode
    BOOL unk_04; // fading to the next mode
    u8 unk_08[0x10];
    UnkClass_0202163C *unk_18;
    int unk_1C; // map id
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    UnkClass_020247CC *unk_30;
    UnkClass_0201CA6C *unk_34;
    u32 unk_38;
    int unk_3C;
    UnkClass_0201B724 *unk_40;
    u32 unk_44;
    int unk_48;
    UnkClass_02025648 *unk_4C;
    int unk_50;
    UnkClass_0202229C *unk_54;
    BOOL unk_58;
    BOOL unk_5C;
    int unk_60;
    BOOL unk_64;
    CGame *unk_68;
};

STATIC_SIZE_ASSERT(UnkClass_02022404, 0x6C);

#endif // POKERANGER2_UNKCLASS_02022404_HPP
