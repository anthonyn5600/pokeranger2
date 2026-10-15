#include "RangerNetComm.hpp"

// Byte ring buffers of the Ranger Net packet layer (0212C89C..0212CA60); pokeplatinum comm_ring.c

void CommSys_SetError(); // RangerNetCommSystem.cpp

void CommRing_Init(CommRing *ring, u8 *buf, int size)
{
    ring->buffer = buf;
    ring->size = size;
    ring->startIndex = 0;
    ring->endIndex = 0;
    ring->backupEndIndex = 0;
}

void CommRing_Write(CommRing *ring, u8 *data, int size, int line)
{
    if (CommRing_RemainingSize(ring) <= size) {
        CommSys_SetError();
        return;
    }
    int i;
    int j = 0;
    for (i = ring->backupEndIndex; i < ring->backupEndIndex + size; i++) {
        ring->buffer[CommRing_Index(ring, i)] = data[j];
        j++;
    }
    ring->backupEndIndex = CommRing_Index(ring, i);
}

int CommRing_Read(CommRing *ring, u8 *buf, int size)
{
    int n = CommRing_Peek(ring, buf, size);
    ring->startIndex = CommRing_Index(ring, ring->startIndex + n);
    return n;
}

u8 CommRing_ReadByte(CommRing *ring)
{
    u8 b;
    CommRing_Read(ring, &b, 1);
    return b;
}

int CommRing_Peek(CommRing *ring, u8 *buf, int size)
{
    int i;
    int n = 0;
    for (i = ring->startIndex; i < ring->startIndex + size; i++) {
        if (ring->endIndex == CommRing_Index(ring, i)) {
            return n;
        }
        buf[n] = ring->buffer[CommRing_Index(ring, i)];
        n++;
    }
    return n;
}

int CommRing_DataSize(CommRing *ring)
{
    s16 read = ring->startIndex;
    if (read > ring->endIndex) {
        return ring->size + ring->endIndex - read;
    }
    return ring->endIndex - read;
}

int CommRing_RemainingSize(CommRing *ring)
{
    return ring->size - CommRing_DataSize(ring);
}

int CommRing_Index(CommRing *ring, int pos)
{
    return pos % ring->size;
}

void CommRing_UpdateEndPos(CommRing *ring)
{
    ring->endIndex = ring->backupEndIndex;
}
