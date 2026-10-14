#ifndef POKERANGER2_RANGERNETMENU_HPP
#define POKERANGER2_RANGERNETMENU_HPP

#include <nnsys/fnd.h>

#include "UnkClass_02124578.hpp"
#include "common.hpp"

class CGame;
class OamSpriteSet;
class OamSprite;
class UnkClass_0201100C;
class BGLayer;
class MessageTable;
class SaveManager;
class RangerNetMissionList;
class FieldData;
class RangerNetSendBin;
class RangerNetExchange;
class UnkClass_0212F3DC;
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
    void ov11_0211E0E8();
    void ov11_0211E1DC(); // thunk to ov11_0211E1E8
    void ov11_0211E1E8();
    void ov11_0211E2EC();
    void ov11_0211EF5C();
    void ov11_0211EFB4();
    void ov11_0211F06C();
    BOOL ov11_0211F0FC();
    void ov11_0211F26C();
    void ov11_0211F32C();
    BOOL ov11_0211F338();
    BOOL ov11_0211F3A8();
    void ov11_0211EFC4();
    void ov11_0211F008(int i);
    void ov11_0211F0BC();
    void ov11_0211F96C();
    int ov11_021201A8();
    int ov11_021201F8();
    int ov11_02120294(int id);
    void ov11_02121000(void *buf);
    int ov11_02121010();
    BOOL ov11_02123D20(int i, void *buf, u8 *dst);
    void ov11_0212374C(int a, BOOL b);
    int ov11_021212B4();
    void ov11_02123DDC();
    void ov11_02121288();
    void ov11_02123F58();
    void ov11_02123BD4();
    int ov11_02124094();
    void ov11_02124150(int i);
    void ov11_021241A0();
    void ov11_02124318();
    void ov11_02124370(BOOL visible);
    int ov11_02123C8C(const char *name);
    BOOL ov11_02123CEC(void *mem);
    void ov11_0211E464();
    void ov11_0211F904();
    int ov11_0211FC60();
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
    void ov11_021229F0(int a, int b);
    BOOL ov11_021242B8(int a);
    void ov11_02121658(int a);
    void ov11_02123C04(int a);
    int ov11_02121F48(int a);
    void ov11_0212253C(int a);
    void ov11_021224E4();
    void ov11_02121550();
    int ov11_02121428();
    void ov11_021241C8(int a, int b);
    void ov11_021240D4(int a);
    void ov11_021241EC(int a, int b);
    int ov11_021240C0(int a);
    void ov11_021216C4(int idx);
    void ov11_021217D4(const int *ids, BOOL show, int arg);
    int ov11_02122B04(int a, int b, int c);
    int ov11_02124278();
    void ov11_0212280C();
    void ov11_02122510();
    void ov11_02121964(int a);
    void ov11_02122C18(int a, int b, int c);
    void ov11_0211F990();
    void ov11_0211FBE4(int mode);
    int ov11_02120150();
    int ov11_02120170();
    int ov11_02120178();
    int ov11_02120248();
    BOOL ov11_021202CC(int id);
    int ov11_02124054();
    void ov11_02124260(int slot, int idx);
    void ov11_0211FB08(int a, int b);
    void ov11_02124438(int mode);
    void ov11_02124520();
    void ov11_02123794(int mode);
    void ov11_02121C20();
    BOOL ov11_02121F18();
    BOOL ov11_02122428();
    int ov11_0212247C();
    void ov11_02122B7C(int a, int b, int c, int d);
    void ov11_02122BD4(int a);
    void ov11_02122BF8(int i, int v);
    void ov11_02122C08(int i, int v);
    void ov11_02122C48(int mode);
    void ov11_021202E4();
    void ov11_021204B0();
    void ov11_02120A80();
    void ov11_02120AE8();
    void ov11_02120C1C();
    void ov11_02120DA8();
    void ov11_02120EBC();
    int ov11_02121168();
    int ov11_02121214();
    void ov11_02121270();
    int ov11_02122150();
    void ov11_02121A08();
    void ov11_02121A7C();
    BOOL ov11_02123FB0(); // IsFading
    void ov11_02124038(int state, int arg);
    void ov11_0211E414();
    void ov11_0211E438();
    void ov11_0211F52C();
    void ov11_02121B38();
    BOOL ov11_02121EEC();
    void ov11_02123228(int idx, int x, int y, int color, BOOL top);
    void ov11_0212331C(int idx, int x, int y, int value, int color, BOOL top, int digits);
    void ov11_021234A8(char *buf, int value, int digits);
    void ov11_02123598(int idx, int x, int y, int name, int color, BOOL top);
    void ov11_02122C60();
    void ov11_02123B98();
    int ov11_02123FF8();
    void ov11_021217C0(int state);
    void ov11_02123A78(int state);
    BOOL ov11_02123D0C();
    void ov11_02122BA8(const char *str, BOOL top);
    void ov11_02123EBC();
    void ov11_02123F00();

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
    UnkClass_02124578 unk_108[4];
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
    UnkClass_0201100C *unk_620;
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
    UnkClass_0212F3DC *unk_708;
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
