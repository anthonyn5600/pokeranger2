#ifndef POKERANGER2_SCENE_CRELEASESCENE_HPP
#define POKERANGER2_SCENE_CRELEASESCENE_HPP

#include "CGame.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "scene/CScene.hpp"

class Camera2D;
class CFieldActor;
class CFieldActorManage;
class CPlayerHPGauge;
class CameraController;
class OamSprite;
class OamSpriteSet;
class GraphicsSet;
class SubScreenPokemonInfo;
class SaveData;
class FieldDrawActorDataPool;
class FieldShadow;
class CaptureBackground;
class DrawObjectListTwin;

// One captured Pokémon shown in the release menu
struct UnkStruct_0211CD84_Entry {
    BOOL unk_00; // selected
    int unk_04; // flag 4 of the save entry
    s16 unk_08; // heal level (-1 = none)
    u16 unk_0A; // species
    u16 unk_0C; // save id
    u16 unk_0E; // release state
    u16 unk_10; // release delay
};

STATIC_SIZE_ASSERT(UnkStruct_0211CD84_Entry, 0x14);

// Defined in ov7: release menu (CReleaseScene)
class ReleaseMenu {
public:
    ReleaseMenu(CGame *game);
    ~ReleaseMenu();

    void Init();
    void Update();
    void Render();
    void OnVBlank();
    void CreateSprites();
    void Release();
    void Draw();
    void Load();
    BOOL Start();
    BOOL Setup();
    void DrawPartyCount(int count);
    void DrawPartyCapacity(int count);
    void SetDigit(int idx, int anim);
    void UpdateInput();
    void UpdateRecharge();
    void UpdateRelease();
    void UpdateDim();
    void StartDim(u8 alpha, int duration);
    void StopDim(int duration);
    void StartRelease();
    void StartRecharge();
    void ReleasePokemon(CFieldActor *actor, int idx);
    void SetRechargeAnim(BOOL heal);
    void SetButtonsEnabled(BOOL a, BOOL b);
    void SetButtonPressed(BOOL a);
    void SelectAction(int choice);
    s16 CountSelected();
    s16 CountUnreleasable();
    BOOL IsOverCapacity();
    void GetRechargeAmount(u16 *hp, u16 *anim);
    u32 GetRechargeMask();
    u32 GetSelectedMask();
    void Exit();
    void ShowMessage(u32 msg, u32 arg1, int next, u32 arg3, u32 arg4);
    void RequestPokemonInfo(u16 idx);
    void ShowPokemonInfo(u16 id);
    void LoadMarks();
    void DrawMarks(Camera2D *camera);
    BOOL IsEnergyFull();
    BOOL IsConfirmPressed();
    void FadeIn();
    void FadeOut();
    BOOL IsFading();
    int GetResult();

public:
    u16 unk_000; // state
    int unk_004;
    BOOL unk_008;
    Camera2D *unk_00C;
    CameraController *unk_010;
    CaptureBackground *unk_014;
    CPrimitiveRECT unk_018;
    OamSpriteSet *unk_058;
    OamSpriteSet *unk_05C;
    OamSprite *unk_060[8];
    int unk_080[8];
    FieldDrawActorDataPool *unk_0A0;
    CFieldActorManage *unk_0A4;
    DrawObjectListTwin *unk_0A8; // render lists
    FieldShadow *unk_0AC;
    SaveData *unk_0B0;
    UnkStruct_0211CD84_Entry unk_0B4[16];
    int unk_1F4; // message timer
    u16 unk_1F8; // heal state
    u32 unk_1FC; // heal mask
    int unk_200;
    int unk_204; // choice
    BOOL unk_208; // fade active
    int unk_20C; // fade frame
    int unk_210; // fade duration
    u8 unk_214; // fade from
    u8 unk_215; // fade to
    u8 unk_216; // fade alpha
    u16 unk_218; // timer
    int unk_21C; // highlighted entry
    u16 unk_220;
    u16 unk_222;
    SubScreenPokemonInfo *unk_224;
    GraphicsSet *unk_228;
    CSoftwareSprite unk_22C;
    CPlayerHPGauge *unk_278;
    CGame *unk_27C;
};

STATIC_SIZE_ASSERT(ReleaseMenu, 0x280);

// Defined in ov7
class CReleaseScene : public CScene {
public:
    CReleaseScene(CGame *game);
    virtual ~CReleaseScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void Create();

public:
    CGame *m_game;
    ReleaseMenu *unk_08;
};

STATIC_SIZE_ASSERT(CReleaseScene, 0xC);

#endif // POKERANGER2_SCENE_CRELEASESCENE_HPP
