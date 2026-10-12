#ifndef POKERANGER2_SCENE_DOWNLOADMISSION_HPP
#define POKERANGER2_SCENE_DOWNLOADMISSION_HPP

#include <nitro.h>

#include "common.hpp"

// NitroSDK libcrypto (no header in the repo's SDK copy)
struct CRYPTORC4FastContext {
    u32 i;
    u32 j;
    u32 s[256];
};

extern "C" {
void CRYPTO_RC4FastInit(CRYPTORC4FastContext *context, const void *key, u32 keyLen);
void CRYPTO_RC4FastEncrypt(CRYPTORC4FastContext *context, const void *in, u32 length, void *out);
}

// RC4 key of the downloaded mission data (MAIN_BSS_020AF620), defined in CDownloadMissionStartScene.cpp
extern u8 g_downloadMissionKey[16];

#endif // POKERANGER2_SCENE_DOWNLOADMISSION_HPP
