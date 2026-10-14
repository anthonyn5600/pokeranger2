#include "SaveData.hpp"
#include "FieldSyscallSets.hpp"
#include "UnkStruct_02044464.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPartnerManage.hpp"

extern CFieldPartnerManage *MAIN_BSS_0210CA4C;
extern SaveData MAIN_BSS_020B26A0;

extern "C" {
BOOL ov0_0213E668(Point2D pos, fx32 radius, int floor, int arg3);
int ov0_02149A94(int *args);
int ov0_02149A9C(int *args);
int ov0_02149BAC(int *args);
int ov0_02149E48(int *args);
}

static ScriptSyscall sFieldPartnerSyscalls[] = {
    (ScriptSyscall)ov0_02149A94,
    (ScriptSyscall)ov0_02149A9C,
    (ScriptSyscall)ov0_02149BAC,
    (ScriptSyscall)ov0_02149E48,
};

FieldPartnerSyscalls::FieldPartnerSyscalls() {}

FieldPartnerSyscalls::~FieldPartnerSyscalls() {}

void FieldPartnerSyscalls::ov0_02149A7C() {
  Script_RegisterSyscalls(0xD, sFieldPartnerSyscalls);
}

static inline CFieldActor *FindById(CFieldPartnerManage *manage, int id) {
  int count = manage->m_count;
  for (int i = 0; i < count; i++) {
    CFieldPartner *partner =
        (CFieldPartner *)(count <= i ? NULL : manage->m_actors[i]);
    if (partner != NULL && id == partner->unk_1E8) {
      return partner;
    }
  }
  return NULL;
}

// CFieldActorManage::FindLeader with the counter declared first (its registers
// differ otherwise)
static inline CFieldActor *FindLeader(CFieldPartnerManage *manage) {
  int i;
  int count = manage->m_count;
  for (i = 0; i < count; i++) {
    CFieldActor *actor = count <= i ? NULL : manage->m_actors[i];
    if (actor != NULL && (actor->unk_04 & 0x20)) {
      return actor;
    }
  }
  return NULL;
}

static inline void SetUnk1D8(CFieldPartner *partner, Point2D pos) {
  partner->unk_1D8 = pos;
}

static inline Point2D GetUnk1D8(CFieldPartner *partner) {
  return partner->unk_1D8;
}

extern "C" {

int ov0_02149A94(int *args) { return 0; }

int ov0_02149A9C(int *args) {
  int cmd = args[0];
  CFieldPartnerManage *manage = (CFieldPartnerManage *)args[1];
  if (manage == NULL) {
    return -1;
  }
  switch (cmd) {
  case 0:
    return (int)FindById(manage, args[2]);
  case 1:
    return manage->unk_84 + manage->unk_88;
  case 2:
    return manage->unk_84;
  case 3:
    return manage->unk_88;
  case 4:
    return (int)FindLeader(manage);
  case 5:
    MAIN_BSS_020B26A0.unk_0004 = 0;
    return 0;
  }
  return -1;
}

int ov0_02149BAC(int *args) {
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
    Point2D pos = {args[2], args[3]};
    if (args[4] != 0) {
      partner->unk_EC.ov0_02152AD0(partner, pos, partner->unk_1F8);
    } else {
      partner->unk_EC.SetUnk04(pos);
    }
    return 0;
  }
  case 5:
    return partner->unk_EC.unk_44;
  case 6:
    partner->sub_02032A44(args[2]);
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
    return ov0_0213E668(partner->GetPos(), args[2] << FX32_SHIFT,
                        partner->unk_14, 0);
  }
  return -1;
}

int ov0_02149E48(int *args) { return (int)MAIN_BSS_0210CA4C; }
}
