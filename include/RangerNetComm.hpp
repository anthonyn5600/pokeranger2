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
CommQueue *CommQueue_GetFree(CommQueueMan *pool);
BOOL CommQueue_IsEmpty(CommQueueMan *pool);
BOOL CommQueueList_PopHead(CommQueueList *list);
BOOL CommQueueCursor_WriteByte(CommQueueCursor *cursor, u8 v);
BOOL CommQueue_WriteHeader(CommQueue *node, CommQueueCursor *cursor);
BOOL CommQueue_WriteData(CommQueue *node, CommQueueCursor *cursor, CommRing *ring, BOOL partial);
BOOL CommQueue_Write(CommQueueMan *pool, u8 cmd, u8 *data, u16 size, int unused, BOOL toRing);
CommQueue *CommQueue_GetCurrent(CommQueueMan *pool);
void CommQueue_Advance(CommQueueMan *pool);
BOOL CommQueue_FillBuffer(CommQueueMan *pool, CommQueueCursor *cursor, BOOL partial);
void CommQueueMan_Init(CommQueueMan *pool, int count, CommRing *ring);
void CommQueueMan_Reset(CommQueueMan *pool);
void CommQueueMan_Delete(CommQueueMan *pool);

// RangerNetCommRing.cpp
void CommRing_Init(CommRing *ring, u8 *buf, int size);
void CommRing_Write(CommRing *ring, u8 *data, int size, int line);
int CommRing_Read(CommRing *ring, u8 *buf, int size);
u8 CommRing_ReadByte(CommRing *ring);
int CommRing_Peek(CommRing *ring, u8 *buf, int size);
int CommRing_DataSize(CommRing *ring);
int CommRing_RemainingSize(CommRing *ring);
int CommRing_Index(CommRing *ring, int pos);
void CommRing_UpdateEndPos(CommRing *ring);

#endif // POKERANGER2_RANGERNETCOMM_HPP
