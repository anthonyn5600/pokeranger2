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
    Camera2D *unk_0008;
    Camera2D *unk_000C;
    CFieldMap *unk_0010;
    CFieldPlayer *unk_0014;
    CFieldEnemyManage *unk_0018;
    CFieldPartnerManage *unk_001C;
    CFieldNpcManage *unk_0020;
    CFieldTargetObjectManage *unk_0024;
    CFieldEffectManage *unk_0028;
    FieldScreenEffectManage *unk_002C;
    FieldEventRectManage *unk_0030;
    FieldScriptLauncher *unk_0034;
    FieldData *unk_0038;
    DrawObjectList *unk_003C;
    CFieldPlayerInputControlManage *unk_0040;
    FieldDrawActorDataPool *unk_0044;
    FieldShadow *unk_0048;
    UnkClass_0214FB28 *unk_004C;
    UnkClass_0214FD4C *unk_0050;
    FieldSubScreen *unk_0054;
    SubScreenIconMenu *unk_0058;
    FieldCannons *unk_005C;
    TitleBanner *unk_0060;
    UnkClass_0216D5F4 *unk_0064;
    u32 unk_0068;
    int unk_006C;
    int unk_0070;
    int unk_0074;
    int unk_0078;
    CFieldPartnerPokemon *unk_007C;
    CFieldActor *unk_0080;
    int unk_0084;
    int unk_0088;
    u32 unk_008C;
    int unk_0090;
    int unk_0094;
    char unk_0098[0x12];
    u16 unk_00AA;
    int unk_00AC;
    u32 unk_00B0;
    u8 unk_00B4[0x18];
    int unk_00CC;
    u32 unk_00D0;
    u32 unk_00D4;
    CPlayerHPGauge *unk_00D8;
    TouchDotLine *unk_00DC;
    FieldSyscallSets *unk_00E0;
    UnkClass_0214B984 *unk_00E4;
    FieldDebugMenu *unk_00E8;
    u32 unk_00EC;
    int unk_00F0;
    int unk_00F4;
    u8 unk_00F8;
    u8 unk_00F9;
    u8 unk_00FA;
    CPrimitiveRECT unk_00FC;
    FieldEffectFactorySet unk_013C;
    int unk_0140;
    FieldEffectListeners unk_0144;
};

STATIC_SIZE_ASSERT(CFieldScene, 0x154);

#endif // POKERANGER2_SCENE_CFIELDSCENE_HPP
