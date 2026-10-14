#include "RangerNetComm.hpp"

// Byte ring buffers of the Ranger Net packet layer (0212C89C..0212CA60); pokeplatinum comm_ring.c

void ov11_0212C2E4(); // RangerNetCommSystem.cpp

void ov11_0212C89C(CommRing *ring, u8 *buf, int size)
{
    ring->buffer = buf;
    ring->size = size;
    ring->startIndex = 0;
    ring->endIndex = 0;
    ring->backupEndIndex = 0;
}

void ov11_0212C8B8(CommRing *ring, u8 *data, int size, int line)
{
    if (ov11_0212CA20(ring) <= size) {
        ov11_0212C2E4();
        return;
    }
    int i;
    int j = 0;
    for (i = ring->backupEndIndex; i < ring->backupEndIndex + size; i++) {
        ring->buffer[ov11_0212CA38(ring, i)] = data[j];
        j++;
    }
    ring->backupEndIndex = ov11_0212CA38(ring, i);
}

int ov11_0212C938(CommRing *ring, u8 *buf, int size)
{
    int n = ov11_0212C97C(ring, buf, size);
    ring->startIndex = ov11_0212CA38(ring, ring->startIndex + n);
    return n;
}

u8 ov11_0212C964(CommRing *ring)
{
    u8 b;
    ov11_0212C938(ring, &b, 1);
    return b;
}

int ov11_0212C97C(CommRing *ring, u8 *buf, int size)
{
    int i;
    int n = 0;
    for (i = ring->startIndex; i < ring->startIndex + size; i++) {
        if (ring->endIndex == ov11_0212CA38(ring, i)) {
            return n;
        }
        buf[n] = ring->buffer[ov11_0212CA38(ring, i)];
        n++;
    }
    return n;
}

int ov11_0212C9F4(CommRing *ring)
{
    s16 read = ring->startIndex;
    if (read > ring->endIndex) {
        return ring->size + ring->endIndex - read;
    }
    return ring->endIndex - read;
}

int ov11_0212CA20(CommRing *ring)
{
    return ring->size - ov11_0212C9F4(ring);
}

int ov11_0212CA38(CommRing *ring, int pos)
{
    return pos % ring->size;
}

void ov11_0212CA54(CommRing *ring)
{
    ring->endIndex = ring->backupEndIndex;
}
