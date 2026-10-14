#include "RangerNetComm.hpp"
#include "heap.hpp"

// Command queues of the Ranger Net packet layer (0212C304..0212C89C); pokeplatinum unk_020322D8.c

u16 ov11_0212CBA4(int cmd); // RangerNetCommCmd.cpp
void ov11_0212C2E4(); // RangerNetCommSystem.cpp

CommQueue *ov11_0212C304(CommQueueMan *pool)
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

BOOL ov11_0212C33C(CommQueueMan *pool)
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

BOOL ov11_0212C378(CommQueueList *list)
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

BOOL ov11_0212C3B8(CommQueueCursor *cursor, u8 v)
{
    *cursor->ptr = v;
    cursor->ptr++;
    if (--cursor->size == 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov11_0212C3E4(CommQueue *node, CommQueueCursor *cursor)
{
    u16 size = ov11_0212CBA4(node->cmd);
    if (size == 0xFFFF) {
        if (cursor->size < 3) {
            node->started = 0;
            return TRUE;
        }
    } else if (cursor->size < 1) {
        node->started = 0;
        return TRUE;
    }
    ov11_0212C3B8(cursor, node->cmd);
    if (size != 0xFFFF) {
        node->size = size;
    } else {
        ov11_0212C3B8(cursor, node->size >> 8);
        ov11_0212C3B8(cursor, node->size);
    }
    node->started = 1;
    return FALSE;
}

BOOL ov11_0212C4A0(CommQueue *node, CommQueueCursor *cursor, CommRing *ring, BOOL partial)
{
    int hdr;
    if (ov11_0212CBA4(node->cmd) == 0xFFFF) {
        hdr = 3;
    } else {
        hdr = 1;
    }
    if (cursor->size < node->size + hdr && !partial) {
        return FALSE;
    }
    if (node->started != 1 && ov11_0212C3E4(node, cursor)) {
        return FALSE;
    }
    if (cursor->size < node->size) {
        if (node->inRing) {
            ov11_0212C938(ring, cursor->ptr, cursor->size);
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
        ov11_0212C938(ring, cursor->ptr, node->size);
    } else {
        MI_CpuCopy8(node->data, cursor->ptr, node->size);
    }
    cursor->ptr = &cursor->ptr[node->size];
    cursor->size -= node->size;
    return TRUE;
}

BOOL ov11_0212C5FC(CommQueueMan *pool, u8 cmd, u8 *data, u16 size, int unused, BOOL toRing)
{
    CommQueue *node = ov11_0212C304(pool);
    if (node == NULL) {
        return FALSE;
    }
    u16 len = ov11_0212CBA4(cmd);
    if (len == 0xFFFF) {
        len = size;
    }
    if (toRing) {
        if (len + 3 >= ov11_0212CA20(pool->ring)) {
            return FALSE;
        }
        ov11_0212C8B8(pool->ring, data, len, 0x108);
        ov11_0212CA54(pool->ring);
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

CommQueue *ov11_0212C6C0(CommQueueMan *pool)
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

void ov11_0212C6F0(CommQueueMan *pool)
{
    if (pool->cur != NULL) {
        pool->cur = NULL;
        return;
    }
    if (ov11_0212C378(&pool->lists[0])) {
        return;
    }
    ov11_0212C378(&pool->lists[1]);
}

BOOL ov11_0212C724(CommQueueMan *pool, CommQueueCursor *cursor, BOOL partial)
{
    BOOL first = TRUE;
    while (cursor->size > 0) {
        CommQueue *node = ov11_0212C6C0(pool);
        if (node == NULL) {
            break;
        }
        ov11_0212C6F0(pool);
        if (!ov11_0212C4A0(node, cursor, pool->ring, first)) {
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

void ov11_0212C7FC(CommQueueMan *pool, int count, CommRing *ring)
{
    MI_CpuFill8(pool, 0, sizeof(CommQueueMan));
    pool->nodes = (CommQueue *)Heap_Alloc(count * sizeof(CommQueue));
    MI_CpuFill8(pool->nodes, 0, count * sizeof(CommQueue));
    pool->count = count;
    pool->ring = ring;
}

void ov11_0212C840(CommQueueMan *pool)
{
    MI_CpuFill8(pool->nodes, 0, pool->count * sizeof(CommQueue));
    pool->lists[0].head = NULL;
    pool->lists[0].tail = NULL;
    pool->lists[1].head = NULL;
    pool->lists[1].tail = NULL;
    pool->cur = NULL;
}

void ov11_0212C878(CommQueueMan *pool)
{
    if (pool->nodes != NULL) {
        Heap_Free(pool->nodes);
        pool->nodes = NULL;
    }
}
