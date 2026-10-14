#ifndef POKERANGER2_CPLAYERHPGAUGE_HPP
#define POKERANGER2_CPLAYERHPGAUGE_HPP

#include <nitro.h>
#include <nnsys.h>

#include "CActor.hpp"
#include "CellAnimController.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "primitive/CPrimitiveRECT.hpp"

class CGame;
class AudioEngine;

// One graphics set of the gauge (image, palette, optional cells and animation), loaded from an archive
class GraphicsSet {
public:
    GraphicsSet(const char *arcName, const char *arcPath, const char *ncbr, const char *nclr, const char *ncer, const char *cac);
    ~GraphicsSet();

    void Load(const char *arcName, const char *arcPath, const char *ncbr, const char *nclr, const char *ncer, const char *cac);
    void Release();

public:
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_cells;
    CellAnimController *m_anim;
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
};

STATIC_SIZE_ASSERT(GraphicsSet, 0x18);

// The player's HP gauge (CFieldScene::unk_00D8)
class CPlayerHPGauge : public CActor {
public:
    CPlayerHPGauge();
    virtual ~CPlayerHPGauge();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void CreateParts();
    void DeleteParts();
    void Init();
    void InitHPBars();
    void InitPartnerBars();
    void UpdateHP();
    void UpdatePartner();
    void UpdateHPLevel(fx32 ratio);
    void UpdateLowHPFlash(fx32 ratio);
    void UpdateAlpha();
    void SetHP(u16 hp, u16 maxHP);
    void SetCurrentHP(u16 hp);
    void StartHeal(u16 anim);
    void StopHeal();
    BOOL IsHealing();
    BOOL IsHPChanging();
    u16 SetZ(u16 z);
    BOOL IsVisible();
    void SetVisible(BOOL visible);
    BOOL IsPartnerVisible();
    void SetPartnerVisible(BOOL visible);
    u16 GetHPLevel();
    void SetPartnerEnergy(u16 energy);
    void SetPartner(u16 energy, u16 maxEnergy);
    void SetPartnerMax(u16 maxEnergy);
    void DrawIcon(Camera2D *camera);
    void DrawHPNumber(Camera2D *camera);
    void DrawMaxHPNumber(Camera2D *camera);
    void DrawDigit(int digit, int part, Point2D pos, Camera2D *camera);
    void DrawHPBars(Camera2D *camera);
    void DrawPartner(Camera2D *camera);
    void DrawPartnerFrame(Camera2D *camera);
    void DrawPartnerBar(Camera2D *camera);
    void DrawPartnerLeft(Camera2D *camera);
    void DrawPartnerMiddle(Camera2D *camera);
    void DrawPartnerRight(Camera2D *camera);
    void DrawHealEffect(Camera2D *camera);
    GraphicsSet *GetPart(int index);

public:
    CGame *m_game;
    AudioEngine *m_audio;
    CPrimitiveQUAD unk_18C;
    CPrimitiveQUAD unk_1EC;
    CPrimitiveQUAD unk_24C;
    CPrimitiveQUAD unk_2AC;
    CPrimitiveQUAD unk_30C;
    CPrimitiveQUAD unk_36C;
    CPrimitiveQUAD unk_3CC;
    CPrimitiveQUAD unk_42C[3];
    CPrimitiveRECT unk_54C;
    u16 m_z;
    u8 unk_58E[0x2];
    u16 m_hpLevel;
    u16 unk_592;
    u8 unk_594[0x2];
    u16 m_hp;
    u16 m_maxHP;
    u8 unk_59A[0x2];
    fx32 m_shownHP;
    fx32 m_trailHP;
    fx32 m_flash;
    u8 unk_5A8;
    u16 unk_5AA;
    u16 unk_5AC;
    u16 unk_5AE;
    u16 unk_5B0;
    u16 m_alpha;
    fx32 unk_5B4;
    fx32 unk_5B8;
    u16 unk_5BC;
    u16 unk_5BE;
    u16 unk_5C0;
    fx32 m_healRate;
    GraphicsSet *m_parts[7];
};

STATIC_SIZE_ASSERT(CPlayerHPGauge, 0x5E4);

#endif // POKERANGER2_CPLAYERHPGAUGE_HPP
