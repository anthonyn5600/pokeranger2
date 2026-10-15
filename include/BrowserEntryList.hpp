#ifndef POKERANGER2_BROWSERENTRYLIST_HPP
#define POKERANGER2_BROWSERENTRYLIST_HPP

#include <nitro.h>

#include "common.hpp"

// Encyclopedia entry
struct BrowserEntry {
    u16 no; // >= 1000: special entries
    u16 id; // record id for PokeIdTable_Get
    u64 unk_04;
};

STATIC_SIZE_ASSERT(BrowserEntry, 0xC);

extern BrowserEntry OVERLAY21_DATA_02123618[0x10E];
extern int OVERLAY21_BSS_021242C4;

// Defined in ov21
class BrowserEntryList {
public:
    BrowserEntryList();
    ~BrowserEntryList();

    void Filter(u32 mode, int arg);
    int ov21_02122A8C();

public:
    int unk_000; // entry count
    u32 unk_004;
    int unk_008[0x200];
    int *unk_808;
    int unk_80C;
    int unk_810;
    int unk_814[18];
    int unk_85C[25];
};

STATIC_SIZE_ASSERT(BrowserEntryList, 0x8C0);

#endif // POKERANGER2_BROWSERENTRYLIST_HPP
