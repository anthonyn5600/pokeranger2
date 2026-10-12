#ifndef POKERANGER2_BATTLE_UNKCLASS_0213CC28_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0213CC28_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;

class CGame;

// Defined in ov1
class UnkClass_0213CC28 {
public:
    UnkClass_0213CC28(CGame *game);
    ~UnkClass_0213CC28(); // ov1_0213CD2C
    void ov1_0213D92C(u16 arg0);
    void ov1_0213E32C(int arg0);
    void ov1_0213E728();
    void ov1_0213E7B8();
    void ov1_0213E9E4(u16 arg0);
    void ov1_0213EDDC();
    void ov1_0213EEB8();
    void ov1_0213EF14(int arg0);
    void ov1_0213EF40(int arg0);
    void ov1_0213E9F4(u8 arg0);
    void ov1_0213EA2C(u8 arg0);
    void ov1_0213ECB4(int arg0, int arg1, int arg2);
    void ov1_0213EDB0(u8 arg0, u8 arg1, u8 arg2);
    void ov1_0213EC34(u8 arg0, u8 arg1);
    void ov1_0213EDA4(u16 arg0, u8 arg1);
    void ov1_0213EF94(int arg0);

public:
    u8 unk_000[0x178];
};

STATIC_SIZE_ASSERT(UnkClass_0213CC28, 0x178);

#endif // POKERANGER2_BATTLE_UNKCLASS_0213CC28_HPP
