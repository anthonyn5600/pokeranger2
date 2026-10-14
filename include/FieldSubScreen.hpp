#ifndef POKERANGER2_FIELDSUBSCREEN_HPP
#define POKERANGER2_FIELDSUBSCREEN_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class SubScreenTargetInfo;
class SubScreenPokemonInfo;
class SubScreenAreaMap;
class SubScreenPicture;
class SubScreenPartyPanel;
class SubScreenRangerCard;

// Sub-screen controller of the field (CFieldScene::unk_0054): switches between the area map, the panels, the
// pokemon info and target screens and the picture, with fades
class FieldSubScreen {
public:
    FieldSubScreen(CGame *game);
    ~FieldSubScreen();

    void Update();
    void sub_02022710();
    void Render();
    void sub_020227AC();
    void Init();
    void sub_020228C0();
    void RenderAreaMap();
    void RenderPartyPanel();
    void RenderPokemonInfo();
    void RenderTargetInfo();
    void RenderRangerCard();
    void RenderPicture();
    void HideAreaMap();
    BOOL ShowAreaMap(u32 mapId, int x, int y);
    void SwitchToAreaMap(int mapId, int x, int y);
    void SetMapPos(int x, int y);
    BOOL SwitchToPartyPanel();
    BOOL sub_02022B20();
    BOOL SwitchToPokemonInfo(u32 id, int arg2);
    BOOL SwitchToTargetInfo(u32 id);
    BOOL sub_02022C1C();
    BOOL sub_02022C74();
    BOOL sub_02022D04();
    void sub_02022D88();
    void sub_02022DD4();
    void ShowPicture(int picId);
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
    void ResetBGOffsets();
    void SetVramBanks();
    void SetIdleReturn(int arg1);
    void UpdateIdleTimer();
    void ClearMapIcons();
    void AddMapIcon(int x, int y, int kind);
    void sub_02023230(u16 duration);
    BOOL sub_02023298(u16 duration);
    BOOL sub_0202331C();
    static FieldSubScreen *GetInstance();
    BOOL IsRangerCardShown();

    static FieldSubScreen *sInstance;

public:
    u16 unk_00; // mode
    u16 unk_02; // next mode
    BOOL unk_04; // fading to the next mode
    u8 unk_08[0x10];
    SubScreenAreaMap *unk_18;
    int unk_1C; // map id
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    SubScreenPartyPanel *unk_30;
    SubScreenPokemonInfo *unk_34;
    u32 unk_38;
    int unk_3C;
    SubScreenTargetInfo *unk_40;
    u32 unk_44;
    int unk_48;
    SubScreenRangerCard *unk_4C;
    int unk_50;
    SubScreenPicture *unk_54;
    BOOL unk_58;
    BOOL unk_5C;
    int unk_60;
    BOOL unk_64;
    CGame *unk_68;
};

STATIC_SIZE_ASSERT(FieldSubScreen, 0x6C);

#endif // POKERANGER2_FIELDSUBSCREEN_HPP
