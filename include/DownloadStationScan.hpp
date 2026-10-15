#ifndef POKERANGER2_DOWNLOADSTATIONSCAN_HPP
#define POKERANGER2_DOWNLOADSTATIONSCAN_HPP

#include "common.hpp"

// Defined in ov11, owned by RangerNetMenu::unk_708 (also used by CCompanyLogoScene)
class DownloadStationScan {
public:
    DownloadStationScan();
    ~DownloadStationScan();
    BOOL Update();

public:
    u8 *unk_0;
    u8 *unk_4;
    u8 unk_8;
    u16 unk_A;
};

STATIC_SIZE_ASSERT(DownloadStationScan, 0xC);

#endif // POKERANGER2_DOWNLOADSTATIONSCAN_HPP
