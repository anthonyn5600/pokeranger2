#include "FieldSyscallSets.hpp"
#include "UnkStruct_02044464.hpp"
#include "field/CFieldPlayer.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;

extern "C" {
int ov0_021499A4(int *args);
int ov0_021499AC(int *args);
int ov0_021499BC(int *args);
}

static ScriptSyscall sFieldPlayerSyscalls[] = {
    (ScriptSyscall)ov0_021499A4,
    (ScriptSyscall)ov0_021499AC,
    (ScriptSyscall)ov0_021499BC,
};

FieldPlayerSyscalls::FieldPlayerSyscalls() {}

FieldPlayerSyscalls::~FieldPlayerSyscalls() {}

void FieldPlayerSyscalls::ov0_0214998C() {
  Script_RegisterSyscalls(0xC, sFieldPlayerSyscalls);
}

extern "C" {

int ov0_021499A4(int *args) { return 0; }

int ov0_021499AC(int *args) { return (int)MAIN_BSS_0210CA48; }

int ov0_021499BC(int *args) {
  CFieldPlayer *player = MAIN_BSS_0210CA48;
  int cmd = args[0];
  if (player == NULL) {
    return -1;
  }
  switch (cmd) {
  case 0:
    if (player->unk_10C == 1) {
      return player->unk_E4;
    }
    return 0;
  case 1:
    player->unk_10C |= 1;
    player->unk_E4 = args[2];
    break;
  case 2:
    return player->ov0_021333A0(args[2], args[3], args[4], args[5], -1);
  case 3:
    return player->unk_E0;
  }
  return -1;
}
}
