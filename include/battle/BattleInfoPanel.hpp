#ifndef POKERANGER2_BATTLE_BATTLEINFOPANEL_HPP
#define POKERANGER2_BATTLE_BATTLEINFOPANEL_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;
class CNCLRFile;
class OamSprite;
class OamSpriteSet;
class UnkClass_020091E8_004;

// Defined in ov1
// Battle info panel on the sub screen (capture time, assist list, Pokemon icon)
class BattleInfoPanel {
public:
    BattleInfoPanel(CGame *game);
    ~BattleInfoPanel();
    void Release();
    void Load();
    void LoadBG(int palette);
    void LoadPalette(int palette);
    void LoadBlinkPalette();
    void ov1_0213D490();
    void UpdateMosaic();
    void StartMosaic();
    void LoadMessages();
    void LoadPokemonIcon(u16 species);
    void LoadSprites();
    void InitDisplay();
    void InitWindows();
    void PrintInfo(int type, int arg2);
    void PrintPokemonList();
    void PrintAssistType(int type);
    void PrintFieldMove(u32 index);
    void ClearAllWindows();
    void ClearInfoWindows();
    void ClearListWindows();
    void Update(int arg0);
    void UpdateRotation();
    void ResetRotation();
    void UpdateSlideIn();
    void UpdateSpin();
    void ov1_0213E68C();
    void ApplyBGAffine();
    void Render();
    void RefreshPokemonList();
    void SetAssistInfoHidden(int hide);
    void SetTimerDigit(int digit, int value);
    void SetFieldMoveIcons();
    void SetTime(u16 frames);
    int GetEffectiveness(int assistType, int type);
    int GetListY();
    void SetTimeLeft(u16 arg0);
    void SetPokemonCount(u8 count);
    void SetCaptured(u8 index);
    void LayoutList(int count, int y);
    void SetEffectMark(int mode, int index);
    u8 *GetPokemonName(u16 id);
    void PrintPokemonName(u16 id, int index, int color);
    void SetPokemonType(u8 arg0, u8 arg1);
    int GetAssistEffectiveness(u8 type);
    int ov1_0213ECB4(int arg0, int arg1, int arg2);
    void SetPokemonSpecies(u16 arg0, u8 arg1);
    void SetPartnerInfo(u8 arg0, u8 arg1, u8 arg2);
    void ov1_0213EDDC();
    void ReleasePokemonIcon();
    void ov1_0213EF14(int arg0);
    BOOL ov1_0213EF2C();
    void ov1_0213EF40(int arg0);
    BOOL ov1_0213EF80();
    void SetListVisible(int arg0);
    u32 IsListVisible();

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
    OamSprite *unk_E0[4];
    OamSprite *unk_F0[8];
    OamSprite *unk_110[8];
    OamSprite *unk_130[3];
    OamSprite *unk_13C;
    OamSprite *unk_140;
    OamSprite *m_pokeIcon;
    OamSprite *unk_148;
    OamSprite *unk_14C;
    CNCLRFile *m_nclr;
    OamSpriteSet *m_pokeObj;
    OamSpriteSet *unk_158;
    OamSpriteSet *unk_15C;
    OamSpriteSet *unk_160;
    OamSpriteSet *unk_164;
    OamSpriteSet *unk_168;
    UnkClass_020091E8_004 *m_menuMes;
    UnkClass_020091E8_004 *m_assistMes;
    UnkClass_020091E8_004 *m_fieldWazaMes;
};

STATIC_SIZE_ASSERT(BattleInfoPanel, 0x178);

#endif // POKERANGER2_BATTLE_BATTLEINFOPANEL_HPP
