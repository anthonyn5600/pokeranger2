#ifndef POKERANGER2_SCENE_CFIELDSCENE_HPP
#define POKERANGER2_SCENE_CFIELDSCENE_HPP

#include "CGame.hpp"
#include "Collision.hpp"
#include "FieldEffectFactorySet.hpp"
#include "FieldEffectListeners.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "scene/CScene.hpp"

class CFieldActor;
class CFieldEnemy;
class CFieldEnemyManage;
class CFieldPartner;
class CFieldPartnerPokemon;
class CFieldNpcManage;
class CFieldPartnerManage;
class CFieldPlayer;
class CFieldTargetObjectManage;
class Camera2D;
class CPlayerHPGauge;
class FieldSubScreen;
class SubScreenIconMenu;
class TitleBanner;
class FieldDrawActorDataPool;
class FieldData;
class FieldShadow;
class FieldScreenEffectManage;
class DrawObjectList;
class CFieldMap;
class FieldSyscallSets;
class FieldEventRectManage;
class FieldScriptLauncher;
class CFieldPlayerInputControlManage;
class CFieldEffectManage;
class TouchDotLine;
class UnkClass_0214B984;
class FieldDebugMenu;
class UnkClass_0214FB28;
class UnkClass_0214FD4C;
class FieldCannons;
class UnkClass_0216D5F4;

// Defined in ov0
class CFieldScene : public CScene {
public:
    CFieldScene(CGame *game);
    virtual ~CFieldScene();

    virtual u32 func0();
    virtual void func1();
    virtual void func2();
    virtual void func3();
    virtual void func4();
    virtual void func5();
    virtual void func6();
    virtual void func7();
    virtual u32 getSceneId();

    void ov0_02121758(int fps);
    static void ov0_021220AC(void *arg0);
    BOOL ov0_021220D0(u32 mapId, BOOL arg1);
    BOOL ov0_02122EF4();
    void ov0_02122F08(CFieldEnemy *enemy);
    void ov0_02122FEC(u32 arg0, u32 arg1, u32 arg2);
    CFieldActor *ov0_02123060(u32 id);
    CFieldActor *ov0_021232A8();
    void ov0_02123AEC(int arg0, int arg1);
    void ov0_02123E58(int arg0);
    void ov0_02123FEC(u32 arg0, int arg1);
    void ov0_02124054();
    void ov0_021240AC(int waza, int level, const char *name);
    void ov0_0212419C();
    void ov0_021241B8();
    void ov0_02124210();
    void ov0_021244DC();
    void ov0_021244FC();
    void ov0_0212451C();
    void ov0_02124588(int arg0, int arg1);
    void ov0_021245C4(int arg0);
    int ov0_02124604();
    void ov0_021247E4();
    void ov0_021248DC();
    BOOL ov0_02124BFC();
    void ov0_021248EC();
    BOOL ov0_02124C30(Point2D *pos);

public:
    CGame *m_game;
    Camera2D *m_camera;
    Camera2D *m_hudCamera;
    CFieldMap *m_map;
    CFieldPlayer *m_player;
    CFieldEnemyManage *m_enemies;
    CFieldPartnerManage *m_partners;
    CFieldNpcManage *m_npcs;
    CFieldTargetObjectManage *m_targetObjects;
    CFieldEffectManage *m_effects;
    FieldScreenEffectManage *m_screenEffects;
    FieldEventRectManage *m_eventRects;
    FieldScriptLauncher *m_scriptLauncher;
    FieldData *m_fieldData;
    DrawObjectList *m_drawLists;
    CFieldPlayerInputControlManage *m_inputControl;
    FieldDrawActorDataPool *m_actorDataPool;
    FieldShadow *m_shadow;
    UnkClass_0214FB28 *unk_004C;
    UnkClass_0214FD4C *unk_0050;
    FieldSubScreen *m_subScreen;
    SubScreenIconMenu *m_iconMenu;
    FieldCannons *m_cannons;
    TitleBanner *m_banner;
    UnkClass_0216D5F4 *unk_0064;
    u32 unk_0068;
    int unk_006C;
    int unk_0070;
    int unk_0074;
    int unk_0078;
    CFieldPartnerPokemon *m_partnerPokemon;
    CFieldActor *unk_0080;
    int unk_0084;
    int unk_0088;
    u32 m_cameraTarget;
    int unk_0090;
    int unk_0094;
    char unk_0098[0x12];
    u16 unk_00AA;
    int unk_00AC;
    u32 unk_00B0;
    u8 unk_00B4[0x18];
    int unk_00CC;
    u32 m_flags;
    u32 m_hiddenLayers;
    CPlayerHPGauge *m_hpGauge;
    TouchDotLine *m_touchLine;
    FieldSyscallSets *m_syscallSets;
    UnkClass_0214B984 *unk_00E4;
    FieldDebugMenu *m_debugMenu;
    u32 unk_00EC;
    int unk_00F0;
    int unk_00F4;
    u8 unk_00F8;
    u8 unk_00F9;
    u8 unk_00FA;
    CPrimitiveRECT unk_00FC;
    FieldEffectFactorySet m_effectFactories;
    int unk_0140;
    FieldEffectListeners m_effectListeners;
};

STATIC_SIZE_ASSERT(CFieldScene, 0x154);

#endif // POKERANGER2_SCENE_CFIELDSCENE_HPP
