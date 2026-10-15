#ifndef POKERANGER2_RANGERNETMENU_HPP
#define POKERANGER2_RANGERNETMENU_HPP

#include <nnsys/fnd.h>

#include "RangerNetMenuItem.hpp"
#include "common.hpp"

class CGame;
class OamSpriteSet;
class OamSprite;
class DownloadMissionData;
class BGLayer;
class MessageTable;
class SaveManager;
class RangerNetMissionList;
class FieldData;
class RangerNetSendBin;
class RangerNetExchange;
class DownloadStationScan;
class DwcConnection;
class MissionDownload;

struct UnkStruct_0211E05C_4B8 {
    int id;
    int kind;
    int flag;
};

// Defined in ov11: Ranger Net menu, created by CRangerNetScene
// Ranger Net menu (region C), new'd by CRangerNetScene (size 0x730)
class RangerNetMenu {
public:
    RangerNetMenu(CGame *game, int arg);
    ~RangerNetMenu();
    void Init();
    void ov11_0211E1DC(); // thunk to InitBase
    void InitBase();
    void Update();
    void StartDownloadAnim();
    void ClearDownloadAnim();
    void UpdateDownloadAnim();
    BOOL UpdateSendAnim();
    void UpdateSendPulse();
    void StartSendFadeOut();
    BOOL UpdateSendFadeOut();
    BOOL UpdateSendLaunch();
    void InitDownloadDoneSprite();
    void InitSendAnim(int i);
    void FinishDownloadAnim();
    void HideAllButtons();
    int GetSpecialMissionsIcon();
    int GetExtraMissionsIcon();
    int FindItem(int id);
    void StartSaveMissions(void *buf);
    int UpdateSaveMissions();
    BOOL ReadMissionFile(int i, void *buf, u8 *dst);
    void ShowDownloadedMessage(int a, BOOL b);
    int UpdateMissionSelect();
    void SetupAgbMissionList();
    void StartReset();
    void FadeOutToWhite();
    void HideButtons();
    int FindFreeRow();
    void HideRow(int i);
    void HideAllRows();
    void RemoveInactiveRows();
    void SetArrowsVisible(BOOL visible);
    int FindMissionFile(const char *name);
    BOOL MountArchive(void *mem);
    void LoadSprites();
    void ClearItems();
    int SetupSubMenu();
    int Get350(int i)
    {
        return unk_350[i];
    }
    int GetCurrent350()
    {
        return unk_350[unk_364];
    }
    void SetEntry(int i, int id, int kind, int flag)
    {
        unk_4B8[0][i % 3].id = id;
        unk_4B8[0][i % 3].kind = kind;
        unk_4B8[0][i % 3].flag = flag;
    }
    void ShowPage(int a, int b);
    BOOL IsItemMoving(int a);
    void SaveItems(int a);
    void SelectItem(int a);
    int HandleItemInput(int a);
    void ChooseItem(int a);
    void ExitToTitle();
    void GoBack();
    int UpdateItemSelect();
    void BlinkItem(int a, int b);
    void ClearOtherRows(int a);
    void MoveRow(int a, int b);
    int GetRowItem(int a);
    void RestoreItems(int idx);
    void SetupMissionList(const int *ids, BOOL show, int arg);
    int AddItem(int a, int b, int c);
    int GetSelectedRow();
    void OpenItem();
    void StartMission();
    void ReturnToMenu(int a);
    void ShowTopMessage(int a, int b, int c);
    void SetupMainMenu();
    void SetBackButton(int mode);
    int ov11_02120150();
    int ov11_02120170();
    int GetMissionsIcon();
    int GetTransferIcon();
    BOOL HasItem(int id);
    int FindFreeItem();
    void SetRowItem(int slot, int idx);
    void SetLinkIcon(int a, int b);
    void UpdateWaitIcon(int mode);
    void StopConnecting();
    void SetMessageLayout(int mode);
    void LoadBackground();
    BOOL LoadGraphics();
    BOOL CheckContinue();
    int CheckCancel();
    void ShowMessage(int a, int b, int c, int d);
    void AddMessage(int a);
    void SetNameArg(int i, int v);
    void SetNumberArg(int i, int v);
    void ShowTopMission(int mode);
    void UpdateLoad();
    void UpdateMenu();
    void UpdateLocalDownload();
    void UpdateSendEgg();
    void UpdateSendPokemon();
    void UpdateWifiDownload();
    void UpdateAgbDownload();
    int UpdateButtonSelect();
    int UpdateReset();
    void ResetSystem();
    int HandleButtonInput();
    void UpdateWfcSettings();
    void UpdateSprites();
    BOOL IsFading(); // IsFading
    void SetState(int state, int arg);
    void Draw();
    void ov11_0211E438();
    void Release();
    void DrawSprites();
    BOOL Setup();
    void PrintApplicationNo(int idx, int x, int y, int color, BOOL top);
    void PrintNumber(int idx, int x, int y, int value, int color, BOOL top, int digits);
    void FormatNumber(char *buf, int value, int digits);
    void PrintTrainerName(int idx, int x, int y, int name, int color, BOOL top);
    void PrintMessage();
    void LoadButtonGraphics();
    int GetNextScene();
    void ShowButtons(int state);
    void SetButtonMode(int state);
    BOOL UnmountArchive();
    void SetMessageString(const char *str, BOOL top);
    void FadeIn();
    void FadeOutToBlack();

    u16 unk_000;
    u16 unk_002;
    u8 unk_004[0x4];
    MessageTable *unk_008;
    OamSpriteSet *unk_00C;
    OamSpriteSet *unk_010;
    OamSprite **unk_014;
    u8 unk_018[0x4];
    void *unk_01C;
    void *unk_020;
    u8 unk_024[0x10];
    u16 unk_034;
    u8 unk_036[0x2];
    int unk_038;
    u8 unk_03C;
    int unk_040;
    FieldData *unk_044;
    OamSpriteSet *unk_048[22];
    OamSprite *unk_0A0[2];
    OamSpriteSet *unk_0A8;
    OamSpriteSet *unk_0AC;
    OamSpriteSet *unk_0B0;
    OamSpriteSet *unk_0B4;
    int unk_0B8;
    OamSprite *unk_0BC;
    OamSprite *unk_0C0;
    OamSpriteSet *unk_0C4[3];
    OamSprite *unk_0D0;
    u8 unk_0D4[0x4];
    int unk_0D8;
    int unk_0DC;
    int unk_0E0;
    int unk_0E4;
    int unk_0E8;
    int unk_0EC;
    fx32 unk_0F0;
    fx32 unk_0F4;
    fx32 unk_0F8[2];
    fx32 unk_100[2];
    RangerNetMenuItem unk_108[4];
    int unk_328[4];
    u8 unk_338[0x4];
    int unk_33C[5];
    int unk_350[5];
    int unk_364;
    int unk_368[5][4];
    int unk_3B8[5][4];
    int unk_408[5][4];
    int unk_458[5][4];
    int unk_4A8;
    int unk_4AC;
    int unk_4B0;
    int unk_4B4;
    UnkStruct_0211E05C_4B8 unk_4B8[2][4];
    u8 unk_518[0x4];
    int unk_51C;
    int unk_520;
    int unk_524;
    int unk_528;
    int unk_52C;
    int unk_530;
    MessageTable *unk_534[8];
    int unk_554;
    int unk_558[10];
    int unk_580;
    BGLayer *unk_584[3];
    u8 unk_590[0xC];
    int unk_59C;
    int unk_5A0;
    int unk_5A4;
    int unk_5A8[10];
    int unk_5D0[10];
    int unk_5F8;
    int unk_5FC;
    int unk_600;
    int unk_604;
    int unk_608;
    int unk_60C[5];
    DownloadMissionData *unk_620;
    u8 unk_624[0x8];
    int unk_62C[3];
    int unk_638[3];
    int unk_644[3];
    int unk_650;
    u8 unk_654[0x4];
    NNSFndArchive unk_658;
    u8 unk_658_end[0x6C0 - 0x658 - sizeof(NNSFndArchive)];
    int unk_6C0[11];
    int unk_6EC;
    int unk_6F0;
    void *unk_6F4;
    int unk_6F8;
    int unk_6FC;
    void *unk_700;
    u8 unk_704[0x4];
    DownloadStationScan *unk_708;
    int unk_70C;
    int unk_710;
    MissionDownload *unk_714;
    DwcConnection *unk_718;
    RangerNetExchange *unk_71C;
    RangerNetSendBin *unk_720;
    RangerNetMissionList *unk_724;
    SaveManager *unk_728;
    CGame *unk_72C;
};

STATIC_SIZE_ASSERT(RangerNetMenu, 0x730);

#endif // POKERANGER2_RANGERNETMENU_HPP
