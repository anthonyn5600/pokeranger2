#ifndef POKERANGER2_RANGERNETMISSIONLIST_HPP
#define POKERANGER2_RANGERNETMISSIONLIST_HPP

#include "common.hpp"
#include "field/CFieldActor.hpp"

class CGame;
class Camera2D;
class OamSpriteSet;
class OamSprite;
class MessageTable;
class FieldDrawActorDataPool;
class RangerNetMenu;

// Defined in ov11: Ranger Net menu helper (mission list display), owned by RangerNetMenu::unk_724
// helper owned by RangerNetMenu::unk_724 (new'd with size 0x5F4)
class RangerNetMissionList {
public:
    void Update();
    void Draw(); // thunk to Render
    void PrintText(); // thunk to PrintPendingText
    RangerNetMissionList(CGame *game, RangerNetMenu *menu);
    ~RangerNetMissionList();
    void Init();
    void LoadPalette();
    void Release();
    void Render();
    void LoadGraphics();
    void SetLayout(int mode);
    BOOL ShowMission(int idx);
    void PrintPendingText();
    BOOL ShowMessage(int a, int b, MessageTable *c);
    void ov11_0211D860(int mode);
    BOOL Load();
    void SetMessage(int a, MessageTable *b);
    void AddMessage(int v);
    void HideSprites();

    u16 unk_000;
    int unk_004;
    Camera2D *unk_008;
    FieldDrawActorDataPool *unk_00C;
    OamSpriteSet *unk_010;
    u8 unk_014[0x4];
    OamSpriteSet *unk_018;
    OamSprite *unk_01C[7];
    u8 unk_038[0x8];
    MessageTable *unk_040[6];
    RangerNetMenu *unk_058;
    u8 unk_05C[0x6];
    u16 unk_062;
    int unk_064;
    int unk_068;
    int unk_06C;
    MessageTable *unk_070;
    int unk_074[10];
    int unk_09C;
    CFieldActor unk_0A0[6];
    int unk_5E0;
    int unk_5E4;
    int unk_5E8;
    int unk_5EC;
    CGame *unk_5F0;
};

STATIC_SIZE_ASSERT(RangerNetMissionList, 0x5F4);

#endif // POKERANGER2_RANGERNETMISSIONLIST_HPP
