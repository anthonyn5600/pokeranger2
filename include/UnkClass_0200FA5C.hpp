#ifndef POKERANGER2_UNKCLASS_0200FA5C_HPP
#define POKERANGER2_UNKCLASS_0200FA5C_HPP

#include <nitro.h>

#include "common.hpp"

// Created by CGame's ctor (CGame::unk_15D8); its ctor lives in Game.cpp
class UnkClass_0200FA5C {
public:
    UnkClass_0200FA5C();

    static UnkClass_0200FA5C *sInstance;

public:
    u8 unk_00[0x54];
    u32 unk_54;
};

STATIC_SIZE_ASSERT(UnkClass_0200FA5C, 0x58);

#endif // POKERANGER2_UNKCLASS_0200FA5C_HPP
