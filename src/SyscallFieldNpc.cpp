#include "FieldSyscallSets.hpp"
#include "UnkStruct_02044464.hpp"
#include "field/CFieldNpc.hpp"
#include "field/CFieldNpcManage.hpp"

extern "C" {
void LogError(const char *fmt, ...);
void LogInfo(const char *fmt, ...);
int ov0_0214B710(int *args);
int ov0_0214B718(int *args);
int ov0_0214B764(int *args);
int ov0_0214B774(int *args);
}

static ScriptSyscall sFieldNpcSyscalls[] = {
    (ScriptSyscall)ov0_0214B710,
    (ScriptSyscall)ov0_0214B718,
    (ScriptSyscall)ov0_0214B764,
    (ScriptSyscall)ov0_0214B774,
};

FieldNpcSyscalls::FieldNpcSyscalls() {}

FieldNpcSyscalls::~FieldNpcSyscalls() {}

void FieldNpcSyscalls::ov0_0214B6F8() {
  Script_RegisterSyscalls(0x10, sFieldNpcSyscalls);
}

extern "C" {

int ov0_0214B710(int *args) { return 0; }

int ov0_0214B718(int *args) {
  CFieldNpc *npc = (CFieldNpc *)args[1];
  int cmd = args[0];
  if (npc == NULL) {
    return -1;
  }
  switch (cmd) {
  case 0:
    LogInfo("test");
    LogInfo("id=%d", npc->unk_F0);
    return npc->unk_F0;
  }
  return 0;
}

int ov0_0214B764(int *args) { return (int)MAIN_BSS_0210CA50; }

int ov0_0214B774(int *args) {
  int cmd = args[0];
  CFieldNpcManage *manage = (CFieldNpcManage *)args[1];
  if (manage == NULL) {
    LogError("ERROR :syscallFieldNpc.cpp FieldNpcManage == NULL");
    return -1;
  }
  switch (cmd) {
  case 0: {
    int base = manage->CountActors();
    fx32 x = args[5];
    fx32 y = args[6];
    int slot = manage->ov0_0213C66C(base, args[3], args[2], args[4], 0);
    CFieldNpc *npc = (CFieldNpc *)manage->Get(slot);
    if (npc != NULL) {
      npc->SetPosXY(x, y);
      npc->unk_18 = x;
      npc->unk_1C = y;
    } else {
      LogInfo("scriptAddNpcError");
    }
    return 0;
  }
  case 1: {
    CFieldActor *actor = manage->Find(args[2]);
    if (actor == NULL) {
      return -1;
    }
    return (int)actor;
  }
  case 2:
    return manage->CountActors();
  }
  return -1;
}
}
