#ifndef POKERANGER2_CRYPTORC4_HPP
#define POKERANGER2_CRYPTORC4_HPP

// NitroSDK libcrypto RC4 (the repo's SDK copy has no libcrypto)

#include <nitro/types.h>

struct CRYPTORC4Context {
    u8 i;
    u8 j;
    u8 padding[2];
    u8 s[256];
};

// Same algorithm with a word-sized state (s[] holds each byte << 24): faster, 1032 bytes
struct CRYPTORC4FastContext {
    u32 i;
    u32 j;
    u32 s[256];
};

extern "C" {
// Keys longer than 16 bytes are cut to 16
void CRYPTO_RC4Init(CRYPTORC4Context *context, const void *key, u32 key_len);
void CRYPTO_RC4Encrypt(CRYPTORC4Context *context, const void *in, u32 length, void *out);
void CRYPTO_RC4FastInit(CRYPTORC4FastContext *context, const void *key, u32 key_len);
void CRYPTO_RC4FastEncrypt(CRYPTORC4FastContext *context, const void *in, u32 length, void *out);
}

#endif // POKERANGER2_CRYPTORC4_HPP
