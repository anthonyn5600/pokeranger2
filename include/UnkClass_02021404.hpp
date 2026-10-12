#ifndef POKERANGER2_UNKCLASS_02021404_HPP
#define POKERANGER2_UNKCLASS_02021404_HPP

#include <nitro.h>

#include "UnkClass_020091E8.hpp"
#include "common.hpp"

// String table loaded from a /data/message file (count + length-prefixed entries)
class UnkClass_02021404 {
public:
    UnkClass_02021404(const char *path);
    ~UnkClass_02021404();

    void Release();
    void Init();
    void Load(const char *path);
    const char *GetString(u32 index);
    u32 GetCount();

public:
    UnkClass_020091E8_004 *unk_00;
};

STATIC_SIZE_ASSERT(UnkClass_02021404, 0x4);

#endif // POKERANGER2_UNKCLASS_02021404_HPP
