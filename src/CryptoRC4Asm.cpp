// NitroSDK libcrypto RC4 encryptors: hand-written ARM assembly in the SDK (same build settings as CryptoRC4.cpp)

#include "CryptoRC4.hpp"

#ifdef PC_PORT
// Portable versions for the PC port: the same algorithm and context layout as the asm below. A length of 2 GB or more
// encrypts nothing (the asm skips most such lengths too; it can't occur on the DS).

// The fast context keeps every state byte, i and j in the top 8 bits of a word (see CRYPTO_RC4FastInit), so the
// index sums wrap by themselves; i is stored masked, j as is.
void CRYPTO_RC4FastEncrypt(CRYPTORC4FastContext *context, const void *in, u32 length, void *out)
{
    u32 *s = context->s;
    u32 i = context->i;
    u32 j = context->j;
    const u8 *src = (const u8 *)in;
    u8 *dst = (u8 *)out;

    for (s32 n = (s32)length; n > 0; n--) {
        i += 1 << 24;
        u32 x = s[i >> 24];
        j += x;
        u32 y = s[j >> 24];
        s[i >> 24] = y;
        s[j >> 24] = x;
        *dst++ = *src++ ^ (u8)(s[(x + y) >> 24] >> 24);
    }
    context->i = i & 0xFF000000;
    context->j = j;
}

void CRYPTO_RC4Encrypt(CRYPTORC4Context *context, const void *in, u32 length, void *out)
{
    u8 *s = context->s;
    u8 i = context->i;
    u8 j = context->j;
    const u8 *src = (const u8 *)in;
    u8 *dst = (u8 *)out;

    for (s32 n = (s32)length; n > 0; n--) {
        i++;
        u8 x = s[i];
        j += x;
        u8 y = s[j];
        s[i] = y;
        s[j] = x;
        *dst++ = *src++ ^ s[(u8)(x + y)];
    }
    context->i = i;
    context->j = j;
}
#else
// clang-format off
asm void CRYPTO_RC4FastEncrypt(register CRYPTORC4FastContext *context, register const void *in, register u32 length, register void *out)
{
    stmdb sp!, {r4, r5, r6, r7, r8, r9, lr}
    ldr r7, [r0]
    ldr r6, [r0, #4]
    add r0, r0, #8
    mov lr, #0x1000000
    add r7, r7, lr
    subs r2, r2, #8
    ldr r9, [r0, r7, lsr #22]
    bmi @rest
@loop8:
    add r6, r6, r9
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    add r6, r6, r9
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    add r6, r6, r9
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    add r6, r6, r9
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    add r6, r6, r9
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    add r6, r6, r9
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    add r6, r6, r9
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    add r6, r6, r9
    subs r2, r2, #8
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    bpl @loop8
@rest:
    adds r2, r2, #8
    ble @done
@restLoop:
    add r6, r6, r9
    subs r2, r2, #1
    ldr r8, [r0, r6, lsr #22]
    ldrb r5, [r1], #1
    str r8, [r0, r7, lsr #22]
    str r9, [r0, r6, lsr #22]
    add r4, r9, r8
    add r7, r7, lr
    ldr r4, [r0, r4, lsr #22]
    ldr r9, [r0, r7, lsr #22]
    eor r5, r5, r4, lsr #24
    strb r5, [r3], #1
    bgt @restLoop
@done:
    sub r7, r7, lr
    and r7, r7, #0xff000000
    str r6, [r0, #-4]
    str r7, [r0, #-8]
    ldmia sp!, {r4, r5, r6, r7, r8, r9, pc}
}

asm void CRYPTO_RC4Encrypt(register CRYPTORC4Context *context, register const void *in, register u32 length, register void *out)
{
    stmdb sp!, {r4, r5, r6, r7, r8, r9, lr}
    ldrb r7, [r0]
    ldrb r6, [r0, #1]
    add r0, r0, #4
    mov lr, #0x1000000
    add r7, lr, r7, lsl #24
    mov r6, r6, lsl #0x18
    ldrb r9, [r0, r7, lsr #24]
    subs r2, r2, #1
    bmi @end
@loop:
    add r6, r6, r9, lsl #24
    subs r2, r2, #1
    ldrb r8, [r0, r6, lsr #24]
    ldrb r5, [r1], #1
    strb r8, [r0, r7, lsr #24]
    strb r9, [r0, r6, lsr #24]
    add r4, r9, r8
    and r4, r4, #0xff
    add r7, r7, lr
    ldrb r4, [r0, r4]
    ldrb r9, [r0, r7, lsr #24]
    eor r5, r5, r4
    strb r5, [r3], #1
    bge @loop
@end:
    sub r7, r7, lr
    mov r7, r7, lsr #0x18
    mov r6, r6, lsr #0x18
    strb r7, [r0, #-4]
    strb r6, [r0, #-3]
    ldmia sp!, {r4, r5, r6, r7, r8, r9, pc}
}
// clang-format on
#endif
