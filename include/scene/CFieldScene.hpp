#ifndef POKERANGER2_SCENE_CFIELDSCENE_HPP
#define POKERANGER2_SCENE_CFIELDSCENE_HPP

#include "CGame.hpp"
#include "UnkClass_02143714.hpp"
#include "UnkClass_021518AC.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "scene/CScene.hpp"
#include "sub_02006000.hpp"

class CFieldActor;
class CFieldEnemy;
class CFieldEnemyManage;
class CFieldPartner;
class CFieldNpcManage;
class CFieldPartnerManage;
class CFieldPlayer;
class CFieldTargetObjectManage;
class Camera2D;
class CPlayerHPGauge;
class UnkClass_02022404;
class UnkClass_020233C8;
class UnkClass_02029800;
class UnkClass_02040F34;
class UnkClass_02041C80;
class UnkClass_020416AC;
class UnkClass_0211D850;
class UnkClass_0211E3FC;
class CFieldMap;
class UnkClass_0213D624;
class UnkClass_0213DDCC;
class UnkClass_0213F918;
class UnkClass_0213FF64;
class UnkClass_02142428;
class UnkClass_021480E4;
class UnkClass_0214B984;
class UnkClass_0214F9DC;
class UnkClass_0214FB28;
class UnkClass_0214FD4C;
class UnkClass_0215994C;
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
    UnkClass_02142428 *unk_0028;
    UnkClass_0211D850 *unk_002C;
    UnkClass_0213DDCC *unk_0030;
    UnkClass_0213F918 *unk_0034;
    UnkClass_02041C80 *unk_0038;
    UnkClass_0211E3FC *unk_003C;
    UnkClass_0213FF64 *unk_0040;
    UnkClass_02040F34 *unk_0044;
    UnkClass_020416AC *unk_0048;
    UnkClass_0214FB28 *unk_004C;
    UnkClass_0214FD4C *unk_0050;
    UnkClass_02022404 *unk_0054;
    UnkClass_020233C8 *unk_0058;
    UnkClass_0215994C *unk_005C;
    UnkClass_02029800 *unk_0060;
    UnkClass_0216D5F4 *unk_0064;
    u32 unk_0068;
    int unk_006C;
    int unk_0070;
    int unk_0074;
    int unk_0078;
    CFieldPartner *unk_007C;
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
    UnkClass_021480E4 *unk_00DC;
    UnkClass_0213D624 *unk_00E0;
    UnkClass_0214B984 *unk_00E4;
    UnkClass_0214F9DC *unk_00E8;
    u32 unk_00EC;
    int unk_00F0;
    int unk_00F4;
    u8 unk_00F8;
    u8 unk_00F9;
    u8 unk_00FA;
    CPrimitiveRECT unk_00FC;
    UnkClass_021518AC unk_013C;
    int unk_0140;
    UnkClass_02143714 unk_0144;
};

STATIC_SIZE_ASSERT(CFieldScene, 0x154);

#endif // POKERANGER2_SCENE_CFIELDSCENE_HPP
