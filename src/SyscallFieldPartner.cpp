#include "FieldSyscallSets.hpp"
#include "SaveData.hpp"
#include "ScriptVM.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPartnerManage.hpp"

extern CFieldPartnerManage *MAIN_BSS_0210CA4C;
extern SaveData MAIN_BSS_020B26A0;

extern "C" {
BOOL PartnerPath_IsBlocked(Point2D pos, fx32 radius, int floor, int arg3);
int ov0_02149A94(int *args);
int Sys_PartnerManageCommand(int *args);
int Sys_PartnerCommand(int *args);
int Sys_GetPartnerManage(int *args);
}

static ScriptSyscall sFieldPartnerSyscalls[] = {
    (ScriptSyscall)ov0_02149A94,
    (ScriptSyscall)Sys_PartnerManageCommand,
    (ScriptSyscall)Sys_PartnerCommand,
    (ScriptSyscall)Sys_GetPartnerManage,
};

FieldPartnerSyscalls::FieldPartnerSyscalls()
{
}

FieldPartnerSyscalls::~FieldPartnerSyscalls()
{
}

void FieldPartnerSyscalls::Register()
{
    Script_RegisterSyscalls(0xD, sFieldPartnerSyscalls);
}

static inline CFieldActor *FindById(CFieldPartnerManage *manage, int id)
{
    int count = manage->m_count;
    for (int i = 0; i < count; i++) {
        CFieldPartner *partner = (CFieldPartner *)(count <= i ? NULL : manage->m_actors[i]);
        if (partner != NULL && id == partner->unk_1E8) {
            return partner;
        }
    }
    return NULL;
}

// CFieldActorManage::FindLeader with the counter declared first (its registers
// differ otherwise)
static inline CFieldActor *FindLeader(CFieldPartnerManage *manage)
{
    int i;
    int count = manage->m_count;
    for (i = 0; i < count; i++) {
        CFieldActor *actor = count <= i ? NULL : manage->m_actors[i];
        if (actor != NULL && (actor->m_flags & 0x20)) {
            return actor;
        }
    }
    return NULL;
}

static inline void SetUnk1D8(CFieldPartner *partner, Point2D pos)
{
    partner->unk_1D8 = pos;
}

static inline Point2D GetUnk1D8(CFieldPartner *partner)
{
    return partner->unk_1D8;
}

extern "C" {

int ov0_02149A94(int *args)
{
    return 0;
}

int Sys_PartnerManageCommand(int *args)
{
    int cmd = args[0];
    CFieldPartnerManage *manage = (CFieldPartnerManage *)args[1];
    if (manage == NULL) {
        return -1;
    }
    switch (cmd) {
    case 0:
        return PTR_CAST(int, FindById(manage, args[2]));
    case 1:
        return manage->unk_84 + manage->unk_88;
    case 2:
        return manage->unk_84;
    case 3:
        return manage->unk_88;
    case 4:
        return PTR_CAST(int, FindLeader(manage));
    case 5:
        MAIN_BSS_020B26A0.unk_0004 = 0;
        return 0;
    }
    return -1;
}

int Sys_PartnerCommand(int *args)
{
    int cmd = args[0];
    CFieldPartner *partner = (CFieldPartner *)args[1];
    if (partner == NULL) {
        return -1;
    }
    switch (cmd) {
    case 0:
        return partner->unk_1E8;
    case 1:
        return partner->unk_1EC;
    case 2:
        partner->SetUnk1EC(args[2]);
        return 0;
    case 3:
        return partner->unk_200;
    case 4: {
        Point2D pos = { args[2], args[3] };
        if (args[4] != 0) {
            partner->unk_EC.SetTarget(partner, pos, partner->unk_1F8);
        } else {
            partner->unk_EC.SetUnk04(pos);
        }
        return 0;
    }
    case 5:
        return partner->unk_EC.unk_44;
    case 6:
        partner->SetMoveSequence(args[2]);
        return 0;
    case 7:
        partner->ov0_02138A7C();
        return 0;
    case 8:
        partner->ov0_02138714(args[2]);
        return 0;
    case 9:
        partner->ov0_02138B44();
        return 0;
    case 10: {
        Point2D pos;
        partner->ov0_021373C0(&pos);
        SetUnk1D8(partner, pos);
        return 0;
    }
    case 11: {
        Point2D pos;
        partner->ov0_02137AFC(&pos, (CFieldPartner *)args[2]);
        SetUnk1D8(partner, pos);
        return 0;
    }
    case 12:
        return GetUnk1D8(partner).x;
    case 13:
        return GetUnk1D8(partner).y;
    case 14:
        return PartnerPath_IsBlocked(partner->GetPos(), args[2] << FX32_SHIFT, partner->m_layer, 0);
    }
    return -1;
}

int Sys_GetPartnerManage(int *args)
{
    return PTR_CAST(int, MAIN_BSS_0210CA4C);
}
}
