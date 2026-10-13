#ifndef POKERANGER2_BATTLE_UNKCLASS_0213CC28_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0213CC28_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class CNCLRFile;
class UnkClass_0200E960;
class UnkClass_0200ECD0;
class UnkClass_020091E8_004;

// Defined in ov1
// Battle info panel on the sub screen (capture time, assist list, Pokemon icon)
class UnkClass_0213CC28 {
public:
    UnkClass_0213CC28(CGame *game);
    ~UnkClass_0213CC28();
    void ov1_0213CD40();
    void ov1_0213D018();
    void ov1_0213D058(int palette);
    void ov1_0213D354(int palette);
    void ov1_0213D458();
    void ov1_0213D490();
    void ov1_0213D4D0();
    void ov1_0213D568();
    void ov1_0213D614();
    void ov1_0213D92C(u16 species);
    void ov1_0213DA14();
    void ov1_0213DE88();
    void ov1_0213DF20();
    void ov1_0213E0AC(int type, int arg2);
    void ov1_0213E12C();
    void ov1_0213E1D8(int type);
    void ov1_0213E244(u32 index);
    void ov1_0213E29C();
    void ov1_0213E2CC();
    void ov1_0213E2FC();
    void ov1_0213E32C(int arg0);
    void ov1_0213E44C();
    void ov1_0213E4CC();
    void ov1_0213E52C();
    void ov1_0213E60C();
    void ov1_0213E68C();
    void ov1_0213E6B0();
    void ov1_0213E728();
    void ov1_0213E7B8();
    void ov1_0213E7C4(int hide);
    void ov1_0213E86C(int digit, int value);
    void ov1_0213E884();
    void ov1_0213E8BC(u16 frames);
    int ov1_0213E9B4(int assistType, int type);
    int ov1_0213E9EC();
    void ov1_0213E9E4(u16 arg0);
    void ov1_0213E9F4(u8 count);
    void ov1_0213EA2C(u8 index);
    void ov1_0213EA3C(int count, int y);
    void ov1_0213EB14(int mode, int index);
    u8 *ov1_0213EB9C(u16 id);
    void ov1_0213EBB4(u16 id, int index, int color);
    void ov1_0213EC34(u8 arg0, u8 arg1);
    int ov1_0213EC40(u8 type);
    int ov1_0213ECB4(int arg0, int arg1, int arg2);
    void ov1_0213EDA4(u16 arg0, u8 arg1);
    void ov1_0213EDB0(u8 arg0, u8 arg1, u8 arg2);
    void ov1_0213EDDC();
    void ov1_0213EEB8();
    void ov1_0213EF14(int arg0);
    BOOL ov1_0213EF2C();
    void ov1_0213EF40(int arg0);
    BOOL ov1_0213EF80();
    void ov1_0213EF94(int arg0);
    u32 ov1_0213F01C();

public:
    CGame *m_game;
    int unk_04;
    int unk_08;
    u8 unk_0C;
    u8 unk_0D;
    u8 unk_0E;
    u8 unk_0F;
    MtxFx22 m_bgMtx;
    s16 m_bgX;
    s16 m_bgY;
    u16 unk_24;
    u16 m_angle;
    u16 m_rotState;
    u16 m_rotFrame;
    u16 m_flags;
    u16 unk_2E;
    u16 unk_30[8];
    u8 unk_40[0x30];
    BOOL unk_70[8];
    u8 unk_90;
    u8 unk_91[8];
    int m_charOffset;
    int unk_A0[4];
    int unk_B0[8];
    int unk_D0;
    int unk_D4;
    u8 m_blinkTimer;
    u8 m_blinkPal;
    u8 m_blinkDir;
    u8 m_count;
    u8 m_mosaic;
    UnkClass_0200E960 *unk_E0[4];
    UnkClass_0200E960 *unk_F0[8];
    UnkClass_0200E960 *unk_110[8];
    UnkClass_0200E960 *unk_130[3];
    UnkClass_0200E960 *unk_13C;
    UnkClass_0200E960 *unk_140;
    UnkClass_0200E960 *m_pokeIcon;
    UnkClass_0200E960 *unk_148;
    UnkClass_0200E960 *unk_14C;
    CNCLRFile *m_nclr;
    UnkClass_0200ECD0 *m_pokeObj;
    UnkClass_0200ECD0 *unk_158;
    UnkClass_0200ECD0 *unk_15C;
    UnkClass_0200ECD0 *unk_160;
    UnkClass_0200ECD0 *unk_164;
    UnkClass_0200ECD0 *unk_168;
    UnkClass_020091E8_004 *m_menuMes;
    UnkClass_020091E8_004 *m_assistMes;
    UnkClass_020091E8_004 *m_fieldWazaMes;
};

STATIC_SIZE_ASSERT(UnkClass_0213CC28, 0x178);

#endif // POKERANGER2_BATTLE_UNKCLASS_0213CC28_HPP
