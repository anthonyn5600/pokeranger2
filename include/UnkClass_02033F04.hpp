#ifndef POKERANGER2_UNKCLASS_02033F04_HPP
#define POKERANGER2_UNKCLASS_02033F04_HPP

#include <nitro.h>

#include "common.hpp"

class ScriptFile;

// Script manager (src/UnkClass_02033F04.cpp); CGame::m_scriptManager
class UnkClass_02033F04 {
public:
    UnkClass_02033F04(u32 heap);

public:
    u32 m_heap;
    ScriptFile *m_system;
    ScriptFile *m_area;
    ScriptFile *m_chapter;
    ScriptFile *m_quest;
    int unk_14;
    int unk_18;
    u8 m_chapterBuffer[0x18800];
};

STATIC_SIZE_ASSERT(UnkClass_02033F04, 0x1881C);

extern "C" {
int sub_02033F90(UnkClass_02033F04 *mgr, int id);
int sub_02034184(UnkClass_02033F04 *mgr, const char *name);
void sub_02034290(UnkClass_02033F04 *mgr);
int sub_020342D0(UnkClass_02033F04 *mgr);
BOOL sub_02034328(UnkClass_02033F04 *mgr);
void sub_02034374(UnkClass_02033F04 *mgr, int value);
}

#endif // POKERANGER2_UNKCLASS_02033F04_HPP
