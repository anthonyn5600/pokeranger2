#include "FieldSyscallSets.hpp"
#include "ScriptVM.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldPartner.hpp"

extern "C" {
int ov0_02149138(int *args);
int Sys_ActorCommand(int *args);
}

static ScriptSyscall sFieldActorSyscalls[] = {
    (ScriptSyscall)ov0_02149138,
    (ScriptSyscall)Sys_ActorCommand,
};

FieldActorSyscalls::FieldActorSyscalls()
{
}

FieldActorSyscalls::~FieldActorSyscalls()
{
}

void FieldActorSyscalls::Register()
{
    Script_RegisterSyscalls(0xB, sFieldActorSyscalls);
}

static inline void SetHome(CFieldActor *actor, fx32 x, fx32 y)
{
    actor->unk_18 = x;
    actor->unk_1C = y;
}

static inline BOOL IsPartner(CFieldActor *actor)
{
    return (((int)actor->m_id >> 24) & 0xFF) == 1 ? TRUE : FALSE;
}

extern "C" {

int ov0_02149138(int *args)
{
    return 0;
}

int Sys_ActorCommand(int *args)
{
    CFieldActor *actor = (CFieldActor *)args[1];
    int cmd = args[0];
    if (actor == NULL) {
        return -1;
    }
    switch (cmd) {
    case 0:
        return actor->GetX();
    case 1:
        return actor->GetY();
    case 2: {
        fx32 y = args[3];
        // Reusing cmd makes this x a split live range, which gets the original's
        // register.
        cmd = args[2];
        actor->SetPosXY(cmd, y);
        return 0;
    }
    case 3:
        return actor->unk_18;
    case 4:
        return actor->unk_1C;
    case 5:
        SetHome(actor, args[2], args[3]);
        return 0;
    case 6: {
        Point2D pos = { args[2], args[3] };
        actor->MoveLinear(pos, args[4]);
        return 0;
    }
    case 7: {
        Point2D pos = { args[2], args[3] };
        actor->MoveTo(pos, args[4]);
        return 0;
    }
    case 8: {
        Point2D end = { args[2], args[3] };
        Point2D ctrl = { args[4], args[5] };
        actor->MoveCurve(end, ctrl, args[6]);
        return 0;
    }
    case 9: {
        Point2D end = { args[2], args[3] };
        Point2D ctrl1 = { args[4], args[5] };
        Point2D ctrl2 = { args[6], args[7] };
        actor->MoveCurve(end, ctrl1, ctrl2, args[8]);
        return 0;
    }
    case 10: {
        Point2D p1 = { args[2], args[3] };
        Point2D p2 = { args[4], args[5] };
        PointPair2D move = { p1, p2 };
        u32 flags = 0;
        if (IsPartner(actor)) {
            flags |= 0x24;
            if (((CFieldPartner *)actor)->unk_1D0 == 3) {
                flags |= 2;
            }
        }
        return actor->CheckSweepCollision(move, args[6], flags);
    }
    case 11:
        return actor->unk_64.x;
    case 12:
        return actor->unk_64.y;
    case 13:
        actor->sub_020128EC_(args[2]);
        return 0;
    case 14: {
        Point2D pos = { args[2], args[3] };
        actor->sub_02012948_(pos);
        return 0;
    }
    case 15:
        return actor->IsUnk00CSet();
    case 16:
        return actor->GetAnimState();
    case 17:
        actor->SetUnk19C(args[2]);
        return 0;
    case 18:
        actor->StopMotion();
        return 0;
    case 19:
        actor->PlayAnim(args[2], (u8)args[3]);
        return 0;
    case 20:
        actor->sub_show();
        return 0;
    case 21:
        actor->sub_reset();
        return 0;
    case 22:
        actor->sub_0201287C_();
        return 0;
    case 23:
        actor->Jump(args[2], args[3]);
        return 0;
    case 24:
        return actor->m_id;
    case 25:
        actor->m_flags |= 1;
        return 0;
    case 26:
        actor->m_flags &= ~1;
        return 0;
    case 27:
        actor->m_flags |= 0x200;
        return 0;
    case 28:
        actor->m_flags &= ~0x200;
        return 0;
    case 30:
        actor->SetBaseHeight(args[2]);
        return 0;
    case 29:
        return actor->GetBaseHeight();
    case 31: {
        Point2D pos = { args[2], args[3] };
        return actor->CheckCircleCollision(pos, args[4], 0);
    }
    case 32:
        actor->sub_020129F4_(args[2], args[3]);
        return 0;
    case 33:
        if (actor->m_drawObject != NULL) {
            if (actor->m_drawObject->m_actor != NULL) {
                return actor->m_drawObject->m_actor->unk_108.value;
            }
            return 0;
        }
        return 0;
    case 34:
        actor->sub_02012A3C_(args[2], args[3], args[4]);
        return 0;
    case 35:
        if (actor->m_drawObject != NULL) {
            if (actor->m_drawObject->m_actor != NULL) {
                return actor->m_drawObject->m_actor->unk_11C.value;
            }
            return 0x1000;
        }
        return 0x1000;
    case 36:
        if (actor->m_drawObject != NULL) {
            if (actor->m_drawObject->m_actor != NULL) {
                return actor->m_drawObject->m_actor->unk_134.value;
            }
            return 0x1000;
        }
        return 0x1000;
    case 37:
        return actor->unk_20;
    case 38: {
        Point2D end = { args[2], args[3] };
        Point2D ctrl = { args[4], args[5] };
        actor->MoveCurve(&end, &ctrl, args[6]);
        return 0;
    }
    }
    return -1;
}
}
