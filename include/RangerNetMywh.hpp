#ifndef POKERANGER2_RANGERNETMYWH_HPP
#define POKERANGER2_RANGERNETMYWH_HPP

#include "common.hpp"

// ov11 mywh (src/RangerNetMywh.cpp): beacon download child, cut down from the NitroSDK demo library wh.c
void ov11_0212FD74(); // End or Reset
BOOL ov11_0212FE30(u8 *dest, void (*callback)(int state), u8 *buf); // Init + start scanning
u16 ov11_0213018C(); // chunks received
u16 ov11_021301A4(); // chunk count
int ov11_021301BC(); // parent link level
u32 ov11_021301D4(); // work buffer size
void *ov11_021301DC(); // header chunk, NULL until received
BOOL ov11_02130200(); // WM initialized
void ov11_02130210(const u8 *in, u8 *out); // decrypt the download

#endif // POKERANGER2_RANGERNETMYWH_HPP
