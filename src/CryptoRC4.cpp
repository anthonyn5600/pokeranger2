// NitroSDK libcrypto RC4 key setup. Built like the SDK library: SDK 1.2 compiler, -proc arm9tdmi (see meson.build).
// That compiler emits compiled (non-asm) functions in reverse source order: FastInit lands first.

#include "CryptoRC4.hpp"

void CRYPTO_RC4Init(CRYPTORC4Context *context, const void *key, u32 key_len)
{
    int i;
    u8 *s;
    u8 k;
    u8 j;
    u8 x;
    const u8 *keyBytes = (const u8 *)key;

    if (key_len > 16) {
        key_len = 16;
    }
    context->i = 0;
    context->j = 0;
    s = context->s;
    for (i = 0; i < 256; i++) {
        s[i] = i;
    }
    j = 0;
    k = 0;
    for (i = 0; i < 256; i++) {
        x = s[i];
        j = j + (x + keyBytes[k]);
        if (++k == (u8)key_len) {
            k = 0;
        }
        s[i] = s[j];
        s[j] = x;
    }
}

void CRYPTO_RC4FastInit(CRYPTORC4FastContext *context, const void *key, u32 key_len)
{
    int i;
    u32 *s;
    u32 k;
    u32 j;
    u32 x;
    const u8 *keyBytes = (const u8 *)key;

    if (key_len > 16) {
        key_len = 16;
    }
    context->i = 0;
    context->j = 0;
    s = context->s;
    for (i = 0; i < 256; i++) {
        s[i] = i;
    }
    j = 0;
    k = 0;
    for (i = 0; i < 256; i++) {
        x = s[i];
        j = (j + (x + keyBytes[k])) & 0xFF;
        if (++k == key_len) {
            k = 0;
        }
        s[i] = s[j];
        s[j] = x;
    }
    // keep each byte in the top 8 bits so the asm encryptor can index with "lsr #22"
    for (i = 0; i < 256; i++) {
        s[i] <<= 24;
    }
}
