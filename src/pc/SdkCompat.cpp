// PC port only: SDK and BIOS functions the game uses that libntr has only as ARM assembly (or not at all).
// Formats follow the DS BIOS/NitroSDK ones: a u32 header (compression type | decompressed size << 8), then the data.

#include <nitro.h>
#include <string.h>

extern "C" {

void MIi_CpuClearFast(u32 data, void *destp, u32 size)
{
    u32 *dest = (u32 *)destp;
    for (u32 i = 0; i < size / sizeof(u32); i++) {
        dest[i] = data;
    }
}

void MI_UncompressRL8(const void *srcp, void *destp)
{
    const u8 *src = (const u8 *)srcp;
    u8 *dest = (u8 *)destp;
    u32 size = *(const u32 *)src >> 8;
    src += 4;
    while (size > 0) {
        u8 flag = *src++;
        u32 len = flag & 0x7F;
        if (flag & 0x80) { // run of one byte
            len += 3;
            if (len > size) {
                len = size;
            }
            memset(dest, *src++, len);
        } else { // literal bytes
            len += 1;
            if (len > size) {
                len = size;
            }
            memcpy(dest, src, len);
            src += len;
        }
        dest += len;
        size -= len;
    }
}

void MI_UncompressHuffman(const void *srcp, void *destp)
{
    const u8 *src = (const u8 *)srcp;
    u32 header = *(const u32 *)src;
    u32 bits = header & 0xF; // 4 or 8 bits per symbol
    u32 size = header >> 8;
    const u8 *treeSize = src + 4;
    const u8 *root = treeSize + 1;
    const u32 *stream = (const u32 *)(treeSize + (*treeSize + 1) * 2);
    u32 *dest = (u32 *)destp;

    const u8 *node = root;
    u32 out = 0;
    u32 outBits = 0;
    while (size > 0) {
        u32 word = *stream++;
        for (int i = 0; i < 32 && size > 0; i++) {
            u32 bit = word >> 31;
            word <<= 1;
            // children of a node: ((node address & ~1) + offset * 2 + 2) + bit
            const u8 *child = (const u8 *)(((uintptr_t)node & ~(uintptr_t)1) + (*node & 0x3F) * 2 + 2) + bit;
            if (*node & (0x80 >> bit)) { // child is a leaf: a symbol
                out |= (u32)*child << outBits;
                outBits += bits;
                node = root;
                if (outBits == 32) {
                    *dest++ = out;
                    out = 0;
                    outBits = 0;
                    size = size > 4 ? size - 4 : 0;
                }
            } else {
                node = child;
            }
        }
    }
}

void MI_UnfilterDiff8(const void *srcp, void *destp)
{
    const u8 *src = (const u8 *)srcp;
    u8 *dest = (u8 *)destp;
    u32 size = *(const u32 *)src >> 8;
    src += 4;
    u8 sum = 0;
    for (u32 i = 0; i < size; i++) {
        sum += src[i];
        dest[i] = sum;
    }
}

// BIOS SVC_GetCRC16 (swi 0xE): CRC-16 with the reflected polynomial 0xA001.
u16 sub_0200071A(u32 start, const void *data, u32 size)
{
    const u8 *p = (const u8 *)data;
    u32 crc = start & 0xFFFF;
    for (u32 i = 0; i < size; i++) {
        crc ^= p[i];
        for (int j = 0; j < 8; j++) {
            crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : crc >> 1;
        }
    }
    return (u16)crc;
}

// libdwcutil (the WFC settings utility) has no PC version yet.
// TODO(pc): online features.
int DWC_StartUtility(void *work, int language, int param)
{
    (void)work;
    (void)language;
    (void)param;
    return -1;
}

} // extern "C"
