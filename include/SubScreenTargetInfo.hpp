#ifndef POKERANGER2_SUBSCREENTARGETINFO_HPP
#define POKERANGER2_SUBSCREENTARGETINFO_HPP

#include <nitro.h>

#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"

// Sub-screen target info (TGT archive, data/menu/mt000_bg_LZ.bin): place name, target sprite (data/targetOBJ
// bt%03d_%02d) and its texts; loaded step by step by Load() (FieldSubScreen::unk_40)
class SubScreenTargetInfo {
public:
    SubScreenTargetInfo();
    ~SubScreenTargetInfo();

    void Release();
    void ResetLoad();
    int Load(u32 id);
    void LoadArchive(const char *name);
    void LoadBG();
    void ReleaseBG();
    void SetupBlend();
    void DrawTexts();
    void Update();
    void Render();
    void ReleaseMessages();

public:
    int unk_00;
    u32 unk_04;
    u16 unk_08;
    u8 unk_0A;
    u8 unk_0B;
    u8 unk_0C;
    u16 unk_0E;
    u16 unk_10;
    u16 unk_12;
    OamSpriteSet *unk_14;
    OamSpriteSet *unk_18;
    OamSpriteSet *unk_1C;
    OamSpriteSet *unk_20;
    OamSpriteSet *unk_24;
    OamSprite *unk_28;
    UnkClass_020091E8_004 *unk_2C;
    UnkClass_020091E8_004 *unk_30;
    UnkClass_020091E8_004 *unk_34;
    CArchiveGuard *unk_38;
    CBGNCGRFile *unk_3C;
    CNCLRFile *unk_40;
    CNSCRFile *unk_44;
    CNSCRFile *unk_48;
    CNSCRFile *unk_4C;
    int unk_50;
    int unk_54;
    u8 unk_58[0x4];
};

STATIC_SIZE_ASSERT(SubScreenTargetInfo, 0x5C);

#endif // POKERANGER2_SUBSCREENTARGETINFO_HPP
