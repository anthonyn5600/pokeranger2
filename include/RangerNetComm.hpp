#ifndef POKERANGER2_RANGERNETCOMM_HPP
#define POKERANGER2_RANGERNETCOMM_HPP

#include "common.hpp"

// Ranger Net packet layer helpers (overlay 11): command queues and byte ring buffers. The same library as
// pokeplatinum's unk_020322D8.c / comm_ring.c (the DP-era comm code); type names follow it.

struct CommRing {
    u8 *buffer;
    s16 startIndex;
    volatile s16 endIndex;
    volatile s16 backupEndIndex;
    s16 size;
};

struct CommQueue {
    u8 *data;
    CommQueue *prev;
    CommQueue *next;
    u16 size;
    u8 cmd;
    u8 started : 1;
    u8 inRing : 1;
};

struct CommQueueList {
    CommQueue *head;
    CommQueue *tail;
};

struct CommQueueMan {
    CommQueueList lists[2];
    CommQueue *cur;
    CommRing *ring;
    CommQueue *nodes;
    int count;
};

struct CommQueueCursor {
    u8 *ptr;
    int size;
};

// RangerNetCommQueue.cpp
CommQueue *ov11_0212C304(CommQueueMan *pool);
BOOL ov11_0212C33C(CommQueueMan *pool);
BOOL ov11_0212C378(CommQueueList *list);
BOOL ov11_0212C3B8(CommQueueCursor *cursor, u8 v);
BOOL ov11_0212C3E4(CommQueue *node, CommQueueCursor *cursor);
BOOL ov11_0212C4A0(CommQueue *node, CommQueueCursor *cursor, CommRing *ring, BOOL partial);
BOOL ov11_0212C5FC(CommQueueMan *pool, u8 cmd, u8 *data, u16 size, int unused, BOOL toRing);
CommQueue *ov11_0212C6C0(CommQueueMan *pool);
void ov11_0212C6F0(CommQueueMan *pool);
BOOL ov11_0212C724(CommQueueMan *pool, CommQueueCursor *cursor, BOOL partial);
void ov11_0212C7FC(CommQueueMan *pool, int count, CommRing *ring);
void ov11_0212C840(CommQueueMan *pool);
void ov11_0212C878(CommQueueMan *pool);

// RangerNetCommRing.cpp
void ov11_0212C89C(CommRing *ring, u8 *buf, int size);
void ov11_0212C8B8(CommRing *ring, u8 *data, int size, int line);
int ov11_0212C938(CommRing *ring, u8 *buf, int size);
u8 ov11_0212C964(CommRing *ring);
int ov11_0212C97C(CommRing *ring, u8 *buf, int size);
int ov11_0212C9F4(CommRing *ring);
int ov11_0212CA20(CommRing *ring);
int ov11_0212CA38(CommRing *ring, int pos);
void ov11_0212CA54(CommRing *ring);

#endif // POKERANGER2_RANGERNETCOMM_HPP
