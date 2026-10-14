#ifndef POKERANGER2_MESSAGETABLE_HPP
#define POKERANGER2_MESSAGETABLE_HPP

#include <nitro.h>

#include "TextboxManager.hpp"
#include "common.hpp"

// String table loaded from a /data/message file (count + length-prefixed entries)
class MessageTable {
public:
    MessageTable(const char *path);
    ~MessageTable();

    void Release();
    void Init();
    void Load(const char *path);
    const char *GetString(u32 index);
    u32 GetCount();

public:
    UnkClass_020091E8_004 *unk_00;
};

STATIC_SIZE_ASSERT(MessageTable, 0x4);

#endif // POKERANGER2_MESSAGETABLE_HPP
