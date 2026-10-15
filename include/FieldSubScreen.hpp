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
    BOOL SwitchToRangerCard();
    BOOL ShowRangerCardNow();
    BOOL sub_02022D04();
    void sub_02022D88();
    void SwitchToDefaultPanel();
    void ShowPicture(int picId);
    void sub_02022EC4();
    BOOL BeginSwitch();
    BOOL LoadAreaMap();
    BOOL LoadPartyPanel();
    void BeginLoadPokemonInfo();
    int LoadPokemonInfoStep();
    void BeginLoadTargetInfo();
    int LoadTargetInfoStep();
    BOOL LoadRangerCard();
    BOOL LoadPicture();
    void FinishSwitch();
    void ResetBGOffsets();
    void SetVramBanks();
    void SetIdleReturn(int arg1);
    void UpdateIdleTimer();
    void ClearMapIcons();
    void AddMapIcon(int x, int y, int kind);
    void FadeIn(u16 duration);
    BOOL FadeOut(u16 duration);
    BOOL IsFading();
    static FieldSubScreen *GetInstance();
    BOOL IsRangerCardShown();

    static FieldSubScreen *sInstance;

public:
    u16 m_mode; // mode
    u16 m_nextMode; // next mode
    BOOL m_switching; // fading to the next mode
    u8 unk_08[0x10];
    SubScreenAreaMap *m_areaMap;
    int m_mapId; // map id
    int unk_20;
    int unk_24;
    int unk_28;
    int unk_2C;
    SubScreenPartyPanel *m_partyPanel;
    SubScreenPokemonInfo *m_pokemonInfo;
    u32 unk_38;
    int unk_3C;
    SubScreenTargetInfo *m_targetInfo;
    u32 unk_44;
    int unk_48;
    SubScreenRangerCard *m_rangerCard;
    int unk_50;
    SubScreenPicture *m_picture;
    BOOL unk_58;
    BOOL unk_5C;
    int unk_60;
    BOOL unk_64;
    CGame *m_game;
};

STATIC_SIZE_ASSERT(FieldSubScreen, 0x6C);

#endif // POKERANGER2_FIELDSUBSCREEN_HPP
