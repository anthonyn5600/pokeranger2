#ifndef POKERANGER2_BATTLE_UNKCLASS_021384F8_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021384F8_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CBattleDisk;
class Camera2D;
class CNCERFile;
class CPlayerHPGauge;
class UnkClass_02007AA4;
class UnkClass_020074D4;
class UnkClass_02010D2C;
class UnkClass_02034478;
class UnkClass_020B26A0;

// Defined in ov1: battle result screen (exp tally and level up, "BRM" r000)
class UnkClass_021384F8 {
public:
    UnkClass_021384F8();
    ~UnkClass_021384F8();
    void Load();
    void Release();
    void ov1_02138FEC();
    void ov1_02139088();
    void ov1_021390A8();
    void ov1_02139154();
    void ov1_02139280();
    void ov1_021392F8();
    void ov1_02139364();
    void ov1_021396C0();
    void ov1_021397FC();
    void ov1_0213985C();
    void ov1_021398F4();
    void ov1_021399A8(Camera2D *camera);
    void ov1_02139C30(CBattleDisk *disk, CPlayerHPGauge *gauge);
    int ov1_02139CE4(int z);
    void SetPanelPos(fx32 x, fx32 y);
    void SetLevelPos(fx32 x, fx32 y);
    void SetStat1Pos(fx32 x, fx32 y);
    void SetStat2Pos(fx32 x, fx32 y);
    void SetExpLabelPos(fx32 x, fx32 y);
    void MoveExpBar(fx32 dx, fx32 dy);
    void SetExpPos(fx32 x, fx32 y);
    void SetBonusPos(fx32 x, fx32 y);
    void SetPromptPos(fx32 x, fx32 y);
    void SetExpDigits(s16 exp);
    void SetExpBar(fx32 exp, fx32 next);
    void SetBonusDigits(s16 bonus);
    void SetLevelDigits(u8 from, u8 to);
    void SetStat1Digits(u8 value);
    void SetStat2Digits(u8 value);
    u8 ov1_0213A4A0(u16 score);

    inline BOOL IsActive()
    {
        return m_state != 0;
    }

public:
    u32 m_frame;
    u32 m_state;
    s16 m_exp;
    s16 m_baseExp;
    u32 m_tally;
    fx32 m_shownExp;
    fx32 m_shownTotal;
    u8 m_startLevel;
    u8 m_level;
    u16 m_nextExp;
    int m_levelExp;
    BOOL m_maxLevel;
    u8 m_bonusIdx;
    u32 m_bonusFlags;
    s16 m_bonus;
    u16 m_score;
    u16 m_angle;
    UnkClass_02010D2C *m_levelTable;
    UnkClass_020B26A0 *m_save;
    UnkClass_02034478 *m_audio;
    CBattleDisk *m_disk;
    CPlayerHPGauge *m_gauge;
    CSoftwareSprite m_panel0;
    CSoftwareSprite m_panel1;
    CSoftwareSprite m_panel2;
    CSoftwareSprite m_levelLabel0;
    CSoftwareSprite m_levelLabel1;
    CSoftwareSprite m_levelLabel2;
    CSoftwareSprite m_levelFrom[2];
    CSoftwareSprite m_levelTo[2];
    CSoftwareSprite m_stat1Label0;
    CSoftwareSprite m_stat1Label1;
    CSoftwareSprite m_stat1Digits[3];
    CSoftwareSprite m_stat2Label0;
    CSoftwareSprite m_stat2Label1;
    CSoftwareSprite m_stat2Digits[3];
    CSoftwareSprite m_expLabel0;
    CSoftwareSprite m_expLabel1;
    CPrimitiveQUAD m_expBar;
    CSoftwareSprite m_expDigits[4];
    CSoftwareSprite m_bonusLabel0;
    CSoftwareSprite m_bonusLabel1;
    CSoftwareSprite m_bonusDigits[5];
    CSoftwareSprite m_prompt0;
    CSoftwareSprite m_prompt1;
    UnkClass_020074D4 *m_image;
    UnkClass_02007AA4 *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(UnkClass_021384F8, 0xB20);

#endif // POKERANGER2_BATTLE_UNKCLASS_021384F8_HPP
