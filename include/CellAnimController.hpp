#ifndef POKERANGER2_CELLANIMCONTROLLER_HPP
#define POKERANGER2_CELLANIMCONTROLLER_HPP

#include <nitro.h>

#include "CellAnimInstance.hpp"
#include "common.hpp"

struct AnimFileHeader {
    u8 unk_00[6];
    u8 count;
    u8 loop;
    u32 size;
    AnimCmd cmds[0];
};

class CellAnimController {
public:
    CellAnimController();
    CellAnimController(const char *path);
    ~CellAnimController();

    u16 GetCell(u16 id);
    fx32 *GetOffsets(u16 id);
    int GetStatus(u16 id);
    BOOL Load(const char *path, u32 heapId, u32 arg2);
    BOOL SetDirection(u16 id, u16 dir);
    BOOL SetAnim(u16 id, u16 anim);
    void Restart(u16 id);
    u8 GetAnimCount(u16 id);
    void UpdateAll();
    BOOL Update(u16 id);
    BOOL SetSpeed(u16 id, fx32 speed);
    u16 Create(u32 arg0, u32 arg1);
    BOOL Remove(u16 id);
    BOOL RemoveAll();
    u8 GetCount();
    void Init();
    CellAnimInstance *Find(u16 id);
    u16 GetScriptPos(u16 id);
    u8 sub_02008D38(u16 id);

public:
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    AnimCmd *unk_04;
    u8 unk_08;
    u16 unk_0A;
    CellAnimInstance *unk_0C;
};

STATIC_SIZE_ASSERT(CellAnimController, 0x10);

#endif // POKERANGER2_CELLANIMCONTROLLER_HPP
