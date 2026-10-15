#ifndef POKERANGER2_BATTLE_BATTLERESULT_HPP
#define POKERANGER2_BATTLE_BATTLERESULT_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CBattleDisk;
class Camera2D;
class CNCERFile;
class CPlayerHPGauge;
class VramPalette;
class VramImage;
class DiskHPTable;
class AudioEngine;
class SaveData;

// Defined in ov1: battle result screen (exp tally and level up, "BRM" r000)
class BattleResult {
public:
    BattleResult();
    ~BattleResult();
    void Load();
    void Release();
    void Update();
    void UpdateStart();
    void UpdateExpSlideIn();
    void UpdateNextBonus();
    void UpdateBonusSlideIn();
    void UpdateRankSlideIn();
    void UpdateExpTally();
    void UpdateExpTallyNoLevel();
    void UpdateLevelUpFlash();
    void UpdateLevelUpSlideIn();
    void UpdateWaitInput();
    void Render(Camera2D *camera);
    void Start(CBattleDisk *disk, CPlayerHPGauge *gauge);
    int SetZ(int z);
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
    u8 GetRank(u16 score);

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
    DiskHPTable *m_levelTable;
    SaveData *m_save;
    AudioEngine *m_audio;
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
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(BattleResult, 0xB20);

#endif // POKERANGER2_BATTLE_BATTLERESULT_HPP
