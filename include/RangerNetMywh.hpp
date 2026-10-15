#ifndef POKERANGER2_RANGERNETMYWH_HPP
#define POKERANGER2_RANGERNETMYWH_HPP

#include "common.hpp"

// ov11 mywh (src/RangerNetMywh.cpp): beacon download child, cut down from the NitroSDK demo library wh.c
void Mywh_Finalize(); // End or Reset
BOOL Mywh_StartDownload(u8 *dest, void (*callback)(int state), u8 *buf); // Init + start scanning
u16 Mywh_GetChunksReceived(); // chunks received
u16 Mywh_GetChunkCount(); // chunk count
int Mywh_GetLinkLevel(); // parent link level
u32 Mywh_GetWorkSize(); // work buffer size
void *Mywh_GetHeader(); // header chunk, NULL until received
BOOL Mywh_IsInitialized(); // WM initialized
void Mywh_Decrypt(const u8 *in, u8 *out); // decrypt the download

#endif // POKERANGER2_RANGERNETMYWH_HPP
