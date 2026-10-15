#include "RangerNetComm.hpp"
#include "heap.hpp"

// Command queues of the Ranger Net packet layer (0212C304..0212C89C); pokeplatinum unk_020322D8.c

u16 CommCmd_PacketSizeOf(int cmd); // RangerNetCommCmd.cpp
void CommSys_SetError(); // RangerNetCommSystem.cpp

CommQueue *CommQueue_GetFree(CommQueueMan *pool)
{
    CommQueue *node = pool->nodes;
    for (int i = 0; i < pool->count; i++) {
        if (node->cmd == 0) {
            return node;
        }
        node++;
    }
    return NULL;
}

BOOL CommQueue_IsEmpty(CommQueueMan *pool)
{
    CommQueue *node = pool->nodes;
    for (int i = 0; i < pool->count; i++) {
        if (node->cmd != 0) {
            return FALSE;
        }
        node++;
    }
    return TRUE;
}

BOOL CommQueueList_PopHead(CommQueueList *list)
{
    if (list->head != NULL) {
        CommQueue *next = list->head->next;
        if (next != NULL) {
            list->head = next;
            next->prev = NULL;
        } else {
            list->head = NULL;
            list->tail = NULL;
        }
        return TRUE;
    }
    return FALSE;
}

BOOL CommQueueCursor_WriteByte(CommQueueCursor *cursor, u8 v)
{
    *cursor->ptr = v;
    cursor->ptr++;
    if (--cursor->size == 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL CommQueue_WriteHeader(CommQueue *node, CommQueueCursor *cursor)
{
    u16 size = CommCmd_PacketSizeOf(node->cmd);
    if (size == 0xFFFF) {
        if (cursor->size < 3) {
            node->started = 0;
            return TRUE;
        }
    } else if (cursor->size < 1) {
        node->started = 0;
        return TRUE;
    }
    CommQueueCursor_WriteByte(cursor, node->cmd);
    if (size != 0xFFFF) {
        node->size = size;
    } else {
        CommQueueCursor_WriteByte(cursor, node->size >> 8);
        CommQueueCursor_WriteByte(cursor, node->size);
    }
    node->started = 1;
    return FALSE;
}

BOOL CommQueue_WriteData(CommQueue *node, CommQueueCursor *cursor, CommRing *ring, BOOL partial)
{
    int hdr;
    if (CommCmd_PacketSizeOf(node->cmd) == 0xFFFF) {
        hdr = 3;
    } else {
        hdr = 1;
    }
    if (cursor->size < node->size + hdr && !partial) {
        return FALSE;
    }
    if (node->started != 1 && CommQueue_WriteHeader(node, cursor)) {
        return FALSE;
    }
    if (cursor->size < node->size) {
        if (node->inRing) {
            CommRing_Read(ring, cursor->ptr, cursor->size);
        } else {
            for (int i = 0; i < cursor->size; i++) {
                cursor->ptr[i] = node->data[i];
            }
        }
        node->data += cursor->size;
        node->size -= cursor->size;
        cursor->size = -1;
        return TRUE;
    }
    if (node->inRing) {
        CommRing_Read(ring, cursor->ptr, node->size);
    } else {
        MI_CpuCopy8(node->data, cursor->ptr, node->size);
    }
    cursor->ptr = &cursor->ptr[node->size];
    cursor->size -= node->size;
    return TRUE;
}

BOOL CommQueue_Write(CommQueueMan *pool, u8 cmd, u8 *data, u16 size, int unused, BOOL toRing)
{
    CommQueue *node = CommQueue_GetFree(pool);
    if (node == NULL) {
        return FALSE;
    }
    u16 len = CommCmd_PacketSizeOf(cmd);
    if (len == 0xFFFF) {
        len = size;
    }
    if (toRing) {
        if (len + 3 >= CommRing_RemainingSize(pool->ring)) {
            return FALSE;
        }
        CommRing_Write(pool->ring, data, len, 0x108);
        CommRing_UpdateEndPos(pool->ring);
        node->inRing = 1;
    }
    node->size = len;
    node->cmd = cmd;
    node->data = data;
    if (pool->lists[0].tail == NULL) {
        pool->lists[0].tail = node;
        pool->lists[0].head = node;
    } else {
        pool->lists[0].tail->next = node;
        node->prev = pool->lists[0].tail;
        pool->lists[0].tail = node;
    }
    return TRUE;
}

CommQueue *CommQueue_GetCurrent(CommQueueMan *pool)
{
    if (pool->cur != NULL) {
        return pool->cur;
    }
    if (pool->lists[0].head != NULL) {
        return pool->lists[0].head;
    }
    if (pool->lists[1].head != NULL) {
        return pool->lists[1].head;
    }
    return NULL;
}

void CommQueue_Advance(CommQueueMan *pool)
{
    if (pool->cur != NULL) {
        pool->cur = NULL;
        return;
    }
    if (CommQueueList_PopHead(&pool->lists[0])) {
        return;
    }
    CommQueueList_PopHead(&pool->lists[1]);
}

BOOL CommQueue_FillBuffer(CommQueueMan *pool, CommQueueCursor *cursor, BOOL partial)
{
    BOOL first = TRUE;
    while (cursor->size > 0) {
        CommQueue *node = CommQueue_GetCurrent(pool);
        if (node == NULL) {
            break;
        }
        CommQueue_Advance(pool);
        if (!CommQueue_WriteData(node, cursor, pool->ring, first)) {
            pool->cur = node;
            break;
        }
        if (cursor->size == -1) {
            pool->cur = node;
            return FALSE;
        }
        MI_CpuFill8(node, 0, sizeof(CommQueue));
        first = partial;
    }
    for (int i = 0; i < cursor->size; i++) {
        *cursor->ptr = 0xEE;
        cursor->ptr++;
    }
    return TRUE;
}

void CommQueueMan_Init(CommQueueMan *pool, int count, CommRing *ring)
{
    MI_CpuFill8(pool, 0, sizeof(CommQueueMan));
    pool->nodes = (CommQueue *)Heap_Alloc(count * sizeof(CommQueue));
    MI_CpuFill8(pool->nodes, 0, count * sizeof(CommQueue));
    pool->count = count;
    pool->ring = ring;
}

void CommQueueMan_Reset(CommQueueMan *pool)
{
    MI_CpuFill8(pool->nodes, 0, pool->count * sizeof(CommQueue));
    pool->lists[0].head = NULL;
    pool->lists[0].tail = NULL;
    pool->lists[1].head = NULL;
    pool->lists[1].tail = NULL;
    pool->cur = NULL;
}

void CommQueueMan_Delete(CommQueueMan *pool)
{
    if (pool->nodes != NULL) {
        Heap_Free(pool->nodes);
        pool->nodes = NULL;
    }
}
