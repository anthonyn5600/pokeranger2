#include "FieldSyscallSets.hpp"
#include "ScriptVM.hpp"
#include "field/CFieldPlayer.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;

extern "C" {
int ov0_021499A4(int *args);
int Sys_GetPlayer(int *args);
int Sys_PlayerCommand(int *args);
}

static ScriptSyscall sFieldPlayerSyscalls[] = {
    (ScriptSyscall)ov0_021499A4,
    (ScriptSyscall)Sys_GetPlayer,
    (ScriptSyscall)Sys_PlayerCommand,
};

FieldPlayerSyscalls::FieldPlayerSyscalls() {}

FieldPlayerSyscalls::~FieldPlayerSyscalls() {}

void FieldPlayerSyscalls::Register() {
  Script_RegisterSyscalls(0xC, sFieldPlayerSyscalls);
}

extern "C" {

int ov0_021499A4(int *args) { return 0; }

int Sys_GetPlayer(int *args) { return (int)MAIN_BSS_0210CA48; }

int Sys_PlayerCommand(int *args) {
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
    return player->KnockBack(args[2], args[3], args[4], args[5], -1);
  case 3:
    return player->unk_E0;
  }
  return -1;
}
}
