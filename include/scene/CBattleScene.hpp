#ifndef POKERANGER2_SCENE_CBATTLESCENE_HPP
#define POKERANGER2_SCENE_CBATTLESCENE_HPP

#include "CGame.hpp"
#include "Collision.hpp"
#include "ScriptVM.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"

class CActor;
class CBattleAssist;
class CBattleAttackEffect;
class CBattleAttackEffectData;
class CBattleDisk;
class CBattleEnemy;
class CBattleEnemyData;
class CBattleEnemyGauge;
class CBattleGameOver;
class CBinaryFile;
class CPlayerHPGauge;
class CTouchPanel;
class Camera2D;
class CameraController;
class OamSpriteSet;
class PokeIdTable;
class BattleStartParam;
class BattleShadow;
class GridOverlay;
class SubScreenPokemonInfo;
class CaptureBackground;
class FieldScreenEffectManage;
class UnkClass_021274AC;
class UnkClass_021278E8;
class BattleEffectivenessMarkGfx;
class BattleHPNumberGfx;
class BattleStatusIconGfx;
class BattleStatusDebugGfx;
class UnkClass_021297C0;
class UnkClass_02129B74;
class BattlePokemonTable;
class BattleEffectTable;
class CaptureLineTrail;
class BattleParamTable;
class BattleEnemyGaugeGfx;
class BattleParticle;
class BattleParticlePool;
class YSortedActorList;
class BattleAssistButton;
class BattleEscapeButton;
class BattleResult;
class BattleAssistMenu;
class BattleInfoPanel;
class CaptureResultBanner;
class BattleDebugMenu;

// A battle script: its file, the stack and the interpreter running it
struct CBattleScript {
    CBinaryFile *file;
    void *data;
    u32 stack[0x80];
    ScriptVM vm;
};

STATIC_SIZE_ASSERT(CBattleScript, 0x22C);

// Defined in ov1
class CBattleScene : public CScene {
public:
    CBattleScene(CGame *game);
    virtual ~CBattleScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ChangeBackground(u8 arg0);
    BOOL AddEffectData(u16 id);
    BOOL LoadEffectData(u16 id, CBattleAttackEffectData **slot);
    void CreateAssist(int type, u16 arg1, u32 partner);
    void StartPokemonAssist(u16 id, u32 partner);
    int UpdateIntro();
    int UpdateStartBanner();
    int UpdateBattle();
    int ov1_0211F984();
    int ov1_0211F9D8();
    int UpdateAssistMenu();
    int UpdateResult();
    int UpdateGameOver();
    int UpdateExit();
    int UpdateDebugMenu();
    int UpdateNewPokemon();
    int ov1_021208BC();
    void UpdateCaptureLine();
    void UpdateAssist();
    void UpdateEnemies();
    void RunEnemyScripts();
    void RunEffectScripts();
    void UpdateEffects();
    void UpdateParticles();
    void RemoveOffscreenEffects();
    BOOL CheckLineHitObjects();
    int RenderIntro(Camera2D *camera, int z);
    int RenderStartBanner(Camera2D *camera, int z);
    int RenderField(Camera2D *camera, int z);
    int RenderPrompt(Camera2D *camera, int z);
    int RenderAssistMenu(Camera2D *camera, int z);
    int RenderResult(Camera2D *camera, int z);
    int RenderGameOver(Camera2D *camera, int z);
    int RenderNewPokemon(Camera2D *camera, int z);
    int RenderEnemyGauges(Camera2D *camera, int z);
    int RenderScreenEffect(Camera2D *camera, int z);
    int RenderShadows(Camera2D *camera, int z);
    void ShowLineTrail();
    void CheckLineHit();
    void StartGameOver();
    void EndBattle(int arg0);
    void RemovePartyPokemon(u8 index);
    u16 GetAssistTime(u16 id);
    void SetAllEnemiesStatus(int arg0, u16 arg1);
    static int GetObjectType(u32 id);
    CBattleEnemy *GetEnemy(u32 id);
    CBattleAttackEffect *GetEffect(u32 id);
    CBattleAttackEffectData *GetEffectData(u32 idx);
    CameraController *GetCameraController();
    void CheckNewCaptures();
    void ClearAssistEffects();
    int ov1_02122D3C(u8 arg0);
    void SelectTouchPanel(int arg0);

public:
    CGame *m_game;
    u16 unk_0008;
    u16 unk_000A;
    u32 unk_000C;
    CTouchPanel *unk_0010;
    BOOL unk_0014;
    int unk_0018;
    BattleStartParam *unk_001C;
    int unk_0020;
    int unk_0024;
    u32 unk_0028;
    u16 unk_002C;
    u16 unk_002E;
    u16 unk_0030;
    u8 unk_0032[0x2];
    int unk_0034;
    u32 unk_0038;
    u32 unk_003C;
    u32 unk_0040;
    u8 unk_0044;
    u8 unk_0045;
    u16 unk_0046[8];
    u16 unk_0056;
    u32 unk_0058;
    u8 unk_005C;
    u8 unk_005D;
    u16 unk_005E[5];
    u32 unk_0068;
    u16 unk_006C;
    u8 unk_006E[0x2];
    u32 unk_0070;
    s32 unk_0074;
    s32 unk_0078;
    u32 unk_007C;
    u8 unk_0080;
    u8 unk_0081;
    u16 unk_0082[8];
    u8 unk_0092[8];
    u8 unk_009A[8];
    u8 unk_00A2[0x2];
    u8 *unk_00A4[8];
    Camera2D *unk_00C4;
    Camera2D *unk_00C8;
    CameraController *unk_00CC;
    GridOverlay *unk_00D0;
    CaptureBackground *unk_00D4;
    CBattleDisk *unk_00D8;
    CBattleEnemy *unk_00DC[8];
    CBattleEnemyData *unk_00FC[4];
    CBattleEnemyGauge *unk_010C[8];
    BattleEnemyGaugeGfx *unk_012C;
    CBattleAttackEffect *unk_0130[0x60];
    CBattleAttackEffectData *unk_02B0[0x12];
    CBattleAttackEffect *unk_02F8[0x20];
    CBattleAttackEffectData *unk_0378[3];
    CBattleAssist *unk_0384;
    OamSpriteSet *unk_0388[8];
    BattleParticle *unk_03A8[0x200];
    BattleParticlePool *unk_0BA8;
    CaptureLineTrail *unk_0BAC;
    CPlayerHPGauge *unk_0BB0;
    CActor *unk_0BB4;
    BattleResult *unk_0BB8;
    CBattleGameOver *unk_0BBC;
    BattleAssistMenu *unk_0BC0;
    YSortedActorList *unk_0BC4[8];
    u8 unk_0BE4;
    u8 unk_0BE5[0x3];
    UnkClass_02129B74 *unk_0BE8;
    UnkClass_021297C0 *unk_0BEC;
    UnkClass_021278E8 *unk_0BF0;
    UnkClass_021274AC *unk_0BF4;
    BattleEffectivenessMarkGfx *unk_0BF8;
    BattleHPNumberGfx *unk_0BFC;
    BattleStatusIconGfx *unk_0C00;
    BattleStatusDebugGfx *unk_0C04;
    BattleAssistButton *unk_0C08;
    BattleEscapeButton *unk_0C0C;
    CaptureResultBanner *unk_0C10;
    PokeIdTable *unk_0C14;
    BattlePokemonTable *unk_0C18;
    BattleEffectTable *unk_0C1C;
    BattleParamTable *unk_0C20;
    BattleParamTable *unk_0C24;
    BattleShadow *unk_0C28;
    FieldScreenEffectManage *unk_0C2C;
    BattleInfoPanel *unk_0C30;
    SubScreenPokemonInfo *unk_0C34;
    u32 unk_0C38;
    u8 unk_0C3C;
    u8 unk_0C3D[0x3];
    BattleDebugMenu *unk_0C40;
    CBattleScript unk_0C44[3];
    Rectangle unk_12C8[2];
};

STATIC_SIZE_ASSERT(CBattleScene, 0x12E8);

#endif // POKERANGER2_SCENE_CBATTLESCENE_HPP
