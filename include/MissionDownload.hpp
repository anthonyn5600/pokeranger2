#ifndef POKERANGER2_MISSIONDOWNLOAD_HPP
#define POKERANGER2_MISSIONDOWNLOAD_HPP

#include <dwc.h>

#include "common.hpp"

class CGame;
class DwcConnection;
class RangerNetMenu;

// Defined in ov11, owned by RangerNetMenu::unk_714
class MissionDownload {
public:
    MissionDownload(CGame *game, DwcConnection *dwc, RangerNetMenu *menu);
    ~MissionDownload();
    void ov11_02130B14();
    void ov11_02130B30();
    int ov11_0213051C();
    int ov11_02130B48();
    void ov11_021316E8();
    void ov11_02131710();
    BOOL ov11_02131980();

public:
    u8 unk_000[0x2C];
    u16 unk_02C;
    u8 unk_02E[0x6];
    int unk_034;
    DWCNdFileInfo unk_038[6];
    int unk_458[11];
    int unk_484[11];
    int unk_4B0; // file count
    u16 unk_4B4;
    u16 unk_4B6;
    int unk_4B8;
    int unk_4BC;
    char *unk_4C0;
    int unk_4C4;
    int unk_4C8;
    int unk_4CC;
    int unk_4D0;
    u32 unk_4D4;
    DwcConnection *unk_4D8;
    CGame *unk_4DC;
    RangerNetMenu *unk_4E0;
};

STATIC_SIZE_ASSERT(MissionDownload, 0x4E4);

#endif // POKERANGER2_MISSIONDOWNLOAD_HPP
