#ifndef POKERANGER2_SCENE_CBATTLESCENE_HPP
#define POKERANGER2_SCENE_CBATTLESCENE_HPP

#include "CGame.hpp"
#include "UnkStruct_02044464.hpp"
#include "common.hpp"
#include "scene/CScene.hpp"
#include "sub_02006000.hpp"

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
class UnkClass_0200D3F8;
class UnkClass_0200ECD0;
class UnkClass_02010470;
class UnkClass_02010854;
class UnkClass_02018B9C;
class UnkClass_0201AD60;
class UnkClass_0201CA6C;
class UnkClass_02042108;
class UnkClass_0211D850;
class UnkClass_021274AC;
class UnkClass_021278E8;
class UnkClass_021281B4;
class UnkClass_02128600;
class UnkClass_02128E88;
class UnkClass_021294BC;
class UnkClass_021297C0;
class UnkClass_02129B74;
class UnkClass_0212DC20;
class UnkClass_0212E008;
class UnkClass_0212E88C;
class UnkClass_0212EEB4;
class UnkClass_021364AC;
class UnkClass_02136730;
class UnkClass_02136AD4;
class UnkClass_02137DA4;
class UnkClass_021380AC;
class UnkClass_021382D0;
class UnkClass_021384F8;
class UnkClass_0213AE18;
class UnkClass_0213CC28;
class UnkClass_0213F028;
class UnkClass_02135BB4;

// A battle script: its file, the stack and the interpreter running it
struct CBattleScript {
    CBinaryFile *file;
    void *data;
    u32 stack[0x80];
    UnkStruct_02044464 vm;
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

    void ov1_0211E71C(u8 arg0);
    BOOL ov1_0211E7E8(u16 id);
    BOOL ov1_0211E8A4(u16 id, CBattleAttackEffectData **slot);
    void ov1_0211E928(int type, u16 arg1, u32 partner);
    void ov1_0211EF74(u16 id, u32 partner);
    int ov1_0211F2B4();
    int ov1_0211F3CC();
    int ov1_0211F404();
    int ov1_0211F984();
    int ov1_0211F9D8();
    int ov1_0211FA90();
    int ov1_0211FB88();
    int ov1_0211FC38();
    int ov1_0211FCE0();
    int ov1_0211FD68();
    int ov1_02120694();
    int ov1_021208BC();
    void ov1_021209C4();
    void ov1_02121184();
    void ov1_02121350();
    void ov1_02121460();
    void ov1_02121514();
    void ov1_021214B4();
    void ov1_0212156C();
    void ov1_0212157C();
    BOOL ov1_02121774();
    int ov1_02121D78(Camera2D *camera, int z);
    int ov1_02121D80(Camera2D *camera, int z);
    int ov1_02121DB0(Camera2D *camera, int z);
    int ov1_02122010(Camera2D *camera, int z);
    int ov1_02122018(Camera2D *camera, int z);
    int ov1_02122044(Camera2D *camera, int z);
    int ov1_02122074(Camera2D *camera, int z);
    int ov1_021220AC(Camera2D *camera, int z);
    int ov1_021220B4(Camera2D *camera, int z);
    int ov1_021222E8(Camera2D *camera, int z);
    int ov1_0212233C(Camera2D *camera, int z);
    void ov1_02122BE8();
    void ov1_02121714();
    void ov1_02122B70();
    void ov1_021227CC(int arg0);
    void ov1_02122CA4(u8 index);
    u16 ov1_0211F010(u16 id);
    void ov1_0211F0D8(int arg0, u16 arg1);
    static int ov1_02122728(u32 id);
    CBattleEnemy *ov1_02122760(u32 id);
    CBattleAttackEffect *ov1_02122788(u32 id);
    CBattleAttackEffectData *ov1_021227B0(u32 idx);
    UnkClass_0200D3F8 *ov1_021227C4();
    void ov1_02122DB4();
    void ov1_02122B90();
    int ov1_02122D3C(u8 arg0);
    void ov1_02122D78(int arg0);

public:
    CGame *m_game;
    u16 unk_0008;
    u16 unk_000A;
    u32 unk_000C;
    CTouchPanel *unk_0010;
    u8 unk_0014[0x4];
    int unk_0018;
    UnkClass_02010854 *unk_001C;
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
    UnkClass_0200D3F8 *unk_00CC;
    UnkClass_0201AD60 *unk_00D0;
    UnkClass_02042108 *unk_00D4;
    CBattleDisk *unk_00D8;
    CBattleEnemy *unk_00DC[8];
    CBattleEnemyData *unk_00FC[4];
    CBattleEnemyGauge *unk_010C[8];
    UnkClass_021364AC *unk_012C;
    CBattleAttackEffect *unk_0130[0x60];
    CBattleAttackEffectData *unk_02B0[0x12];
    CBattleAttackEffect *unk_02F8[0x20];
    CBattleAttackEffectData *unk_0378[3];
    CBattleAssist *unk_0384;
    UnkClass_0200ECD0 *unk_0388[8];
    UnkClass_02136730 *unk_03A8[0x200];
    UnkClass_02136AD4 *unk_0BA8;
    UnkClass_0212E88C *unk_0BAC;
    CPlayerHPGauge *unk_0BB0;
    CActor *unk_0BB4;
    UnkClass_021384F8 *unk_0BB8;
    CBattleGameOver *unk_0BBC;
    UnkClass_0213AE18 *unk_0BC0;
    UnkClass_02137DA4 *unk_0BC4[8];
    u8 unk_0BE4;
    u8 unk_0BE5[0x3];
    UnkClass_02129B74 *unk_0BE8;
    UnkClass_021297C0 *unk_0BEC;
    UnkClass_021278E8 *unk_0BF0;
    UnkClass_021274AC *unk_0BF4;
    UnkClass_021281B4 *unk_0BF8;
    UnkClass_02128600 *unk_0BFC;
    UnkClass_02128E88 *unk_0C00;
    UnkClass_021294BC *unk_0C04;
    UnkClass_021380AC *unk_0C08;
    UnkClass_021382D0 *unk_0C0C;
    UnkClass_0213F028 *unk_0C10;
    UnkClass_02010470 *unk_0C14;
    UnkClass_0212DC20 *unk_0C18;
    UnkClass_0212E008 *unk_0C1C;
    UnkClass_0212EEB4 *unk_0C20;
    UnkClass_0212EEB4 *unk_0C24;
    UnkClass_02018B9C *unk_0C28;
    UnkClass_0211D850 *unk_0C2C;
    UnkClass_0213CC28 *unk_0C30;
    UnkClass_0201CA6C *unk_0C34;
    u32 unk_0C38;
    u8 unk_0C3C;
    u8 unk_0C3D[0x3];
    UnkClass_02135BB4 *unk_0C40;
    CBattleScript unk_0C44[3];
    Rectangle unk_12C8[2];
};

STATIC_SIZE_ASSERT(CBattleScene, 0x12E8);

#endif // POKERANGER2_SCENE_CBATTLESCENE_HPP
