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
class UnkClass_0200D3F8;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_0201AAE0;
class UnkClass_0201CA6C;
class UnkClass_020B26A0;
class UnkClass_02040F34;
class UnkClass_020416AC;
class UnkClass_02042108;
class UnkClass_0211E018;

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
class UnkClass_0211CD84 {
public:
    UnkClass_0211CD84(CGame *game);
    ~UnkClass_0211CD84();

    void ov7_0211CFB4();
    void ov7_0211D054();
    void ov7_0211D38C();
    void ov7_0211D3F0();
    void ov7_0211D42C();
    void ov7_0211D62C();
    void ov7_0211D698();
    void ov7_0211D7FC();
    BOOL ov7_0211E02C();
    BOOL ov7_0211E050();
    void ov7_0211E080(int count);
    void ov7_0211E168(int count);
    void ov7_0211E19C(int idx, int anim);
    void ov7_0211E1B4();
    void ov7_0211E680();
    void ov7_0211E894();
    void ov7_0211EA74();
    void ov7_0211EB04(u8 alpha, int duration);
    void ov7_0211EB3C(int duration);
    void ov7_0211EB7C();
    void ov7_0211EC8C();
    void ov7_0211ECA4(CFieldActor *actor, int idx);
    void ov7_0211ED10(BOOL heal);
    void ov7_0211EE6C(BOOL a, BOOL b);
    void ov7_0211EEC4(BOOL a);
    void ov7_0211EF14(int choice);
    s16 ov7_0211EF5C();
    s16 ov7_0211EFA0();
    BOOL ov7_0211EFE4();
    void ov7_0211F01C(u16 *hp, u16 *anim);
    u32 ov7_0211F100();
    u32 ov7_0211F168();
    void ov7_0211F1E8();
    void ov7_0211F1FC(u32 msg, u32 arg1, int next, u32 arg3, u32 arg4);
    void ov7_0211F29C(u16 idx);
    void ov7_0211F2B0(u16 id);
    void ov7_0211F2E0();
    void ov7_0211F370(Camera2D *camera);
    BOOL ov7_0211F4E0();
    BOOL ov7_0211F4FC();
    void ov7_0211F534();
    void ov7_0211F578();
    BOOL ov7_0211F5BC();
    int ov7_0211F604();

public:
    u16 unk_000; // state
    int unk_004;
    BOOL unk_008;
    Camera2D *unk_00C;
    UnkClass_0200D3F8 *unk_010;
    UnkClass_02042108 *unk_014;
    CPrimitiveRECT unk_018;
    UnkClass_0200ECD0 *unk_058;
    UnkClass_0200ECD0 *unk_05C;
    UnkClass_0200E960 *unk_060[8];
    int unk_080[8];
    UnkClass_02040F34 *unk_0A0;
    CFieldActorManage *unk_0A4;
    UnkClass_0211E018 *unk_0A8; // render lists
    UnkClass_020416AC *unk_0AC;
    UnkClass_020B26A0 *unk_0B0;
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
    UnkClass_0201CA6C *unk_224;
    UnkClass_0201AAE0 *unk_228;
    CSoftwareSprite unk_22C;
    CPlayerHPGauge *unk_278;
    CGame *unk_27C;
};

STATIC_SIZE_ASSERT(UnkClass_0211CD84, 0x280);

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

    void ov7_0211CAB4();

public:
    CGame *m_game;
    UnkClass_0211CD84 *unk_08;
};

STATIC_SIZE_ASSERT(CReleaseScene, 0xC);

#endif // POKERANGER2_SCENE_CRELEASESCENE_HPP
