// PC port only: C++ definitions of the data that the DS build still takes from the data-only asm files
// asm/arm9_02084288.s, arm9_0208A840.s, arm9_0208AC1C.s, arm9_0210CA30.s, arm9_0210CAB0.s and overlay_11_02169B40.s.
// The matching build keeps those files (their owners and the original data order are unproven, see
// ~/scratch/main/fdata/NOTES.md), so this file is not listed in src/meson.build. Each object has the type its users
// declare; labels that only mark a point inside another object (string tails, DAT_020842fc...) have no definition.
// The values were generated from the assembled asm objects; tools/pc/check_asmdata.py compares them again.

#include <nitro.h>

#include "CardBackupInfo.hpp"
#include "Collision.hpp"
#include "Log.hpp"
#include "ScriptVM.hpp"
#include "TextColorTable.hpp"
#include "fx_utils.hpp"
#include "heap.hpp"

class CFieldEffectManage;
class CFieldEnemyManage;
class CFieldMap;
class CFieldNpcManage;
class CFieldPartnerManage;
class CFieldPlayer;
class CFieldPlayerInputControlManage;
class CFieldScene;
class CFieldTargetObjectManage;
class FieldData;
class FieldDebugMenu;
class FieldDrawActorDataPool;
class FieldEventRectManage;
class FieldScreenEffectManage;
class FieldScriptLauncher;
class SaveManager;
class FieldDebugFlags;

// Same layout as the local definitions in CFieldScene.cpp, Syscall.cpp, FieldDebugFlags.cpp, CStaffrollScene.cpp.
struct ChapterInfo {
    char name[0x10];
    u32 mapId;
    int x;
    int y;
};

// Same layout as ScriptVM.cpp's definition.
struct ScriptGlobals {
    ScriptHeader *scripts;
    ScriptSyscall *syscalls[64];
};

extern "C" {

// ---- asm/arm9_02084288.s (.rodata) ----

// BG character, screen and palette transfer destinations of BG0..3, main screen then sub screen (BGFontPrinter.cpp).
extern const NNS_GFD_DST_TYPE DAT_02084288[8][3] = {
    { NNS_GFD_DST_2D_BG0_CHAR_MAIN, NNS_GFD_DST_2D_BG0_SCR_MAIN, NNS_GFD_DST_2D_BG_PLTT_MAIN },
    { NNS_GFD_DST_2D_BG1_CHAR_MAIN, NNS_GFD_DST_2D_BG1_SCR_MAIN, NNS_GFD_DST_2D_BG_PLTT_MAIN },
    { NNS_GFD_DST_2D_BG2_CHAR_MAIN, NNS_GFD_DST_2D_BG2_SCR_MAIN, NNS_GFD_DST_2D_BG_PLTT_MAIN },
    { NNS_GFD_DST_2D_BG3_CHAR_MAIN, NNS_GFD_DST_2D_BG3_SCR_MAIN, NNS_GFD_DST_2D_BG_PLTT_MAIN },
    { NNS_GFD_DST_2D_BG0_CHAR_SUB, NNS_GFD_DST_2D_BG0_SCR_SUB, NNS_GFD_DST_2D_BG_PLTT_SUB },
    { NNS_GFD_DST_2D_BG1_CHAR_SUB, NNS_GFD_DST_2D_BG1_SCR_SUB, NNS_GFD_DST_2D_BG_PLTT_SUB },
    { NNS_GFD_DST_2D_BG2_CHAR_SUB, NNS_GFD_DST_2D_BG2_SCR_SUB, NNS_GFD_DST_2D_BG_PLTT_SUB },
    { NNS_GFD_DST_2D_BG3_CHAR_SUB, NNS_GFD_DST_2D_BG3_SCR_SUB, NNS_GFD_DST_2D_BG_PLTT_SUB },
};

// The original has an unreferenced copy of this rectangle right before it (end of the DAT_02084288 block).
extern const Rectangle DAT_020842f8 = { 0, 0, 256 << FX32_SHIFT, 192 << FX32_SHIFT };

extern const u32 DAT_02084308[4][4] = {
    { 1, 2, 4, 8 },
    { 2, 4, 4, 8 },
    { 1, 1, 2, 4 },
    { 0, 0, 0, 0 },
};

extern const u32 DAT_02084348[4][4] = {
    { 1, 4, 16, 64 },
    { 2, 4, 8, 32 },
    { 2, 4, 8, 32 },
    { 0, 0, 0, 0 },
};

extern const u32 DAT_02084388[4][4] = {
    { 1, 2, 4, 8 },
    { 1, 1, 2, 4 },
    { 2, 4, 4, 8 },
    { 0, 0, 0, 0 },
};

// UTF-8 ideographic space U+3000 followed by an ASCII space (TextboxManager.cpp uses &DAT_020843c8 as a string).
extern const u8 DAT_020843c8[8] = { 0xE3, 0x80, 0x80, 0x20, 0x00 };

extern const u32 DAT_020843d0[4] = { 0, 1, 2, 1 };

extern const TextColorTable DAT_020843e0 = { { 0, 1, 4, 7, 10, 13 } };

// Camera shake offsets per phase (CameraController.cpp).
extern const fx32 DAT_020843f8[6] = { -FX32_ONE, FX32_ONE, -FX32_ONE, FX32_ONE, -FX32_ONE, FX32_ONE };
extern const fx32 DAT_02084410[6] = { 0, -FX32_ONE, FX32_ONE, FX32_ONE, -FX32_ONE, 0 };

// ---- asm/arm9_0208A840.s (.data, .bss, static initializer) ----

char s_BGT_0208a848[] = "BGT";
char s_data_interface_i059_LZ_bin_0208a84c[] = "data/interface/i059_LZ.bin";
char s_BGT_i059_00_NCGR_0208a868[] = "BGT:i059_00.NCGR";
char s_BGT_i059_00_NSCR_0208a87c[] = "BGT:i059_00.NSCR";
char s_BGT_i059_NCLR_0208a890[] = "BGT:i059.NCLR";
char s_BGT_i059_00_NCLR_0208a8a0[] = "BGT:i059_00.NCLR";
char s_data_font_prs_jp_NCLR_0208a8b4[] = "data/font/prs_jp.NCLR";
char s_d_0208a8cc[] = "%d";
char s_data_message_system_system_mes_0208a8d0[] = "data/message/system/system_mes";
char s_data_message_system_system_03d_m_0208a8f0[] = "data/message/system/system%03d_mes";
char s_data_message_area_m_03d_mes_0208a914[] = "data/message/area/m%03d_mes";
char s_data_message_chapter_chapter_03d_0208a930[] = "data/message/chapter/chapter%03d_mes";
char s_data_message_chapter_chapterx_02_0208a958[] = "data/message/chapter/chapterx%02d_mes";
char s_data_message_quest_quest_03d_mes_0208a980[] = "data/message/quest/quest%03d_mes";
char s_data_message_battle_battle_02d_m_0208a9a4[] = "data/message/battle/battle%02d_mes";
char s_ICN_0208a9c8[] = "ICN";
char s_data_interface_i058_LZ_bin_0208a9cc[] = "data/interface/i058_LZ.bin";
char s_ICN_i058_00_NCGR_0208a9e8[] = "ICN:i058_00.NCGR";
char s_ICN_i058_NCLR_0208a9fc[] = "ICN:i058.NCLR";
char s_data_font_prs_lc_jp_NCLR_0208aa0c[] = "data/font/prs_lc_jp.NCLR";
char s_data_font_prs_jp_NCLR_0208aa28[] = "data/font/prs_jp.NCLR";
char s_data_font_prs_lc_jp_NCLR_0208aa40[] = "data/font/prs_lc_jp.NCLR";
char s_data_font_prs_jp_NCLR_0208aa5c[] = "data/font/prs_jp.NCLR";
char s_data_font_font_jp_utf8_NFTR_0208aa74[] = "/data/font/font_jp_utf8.NFTR";
char s_data_font_font_jp_lc_utf8_NFTR_0208aa94[] = "/data/font/font_jp_lc_utf8.NFTR";
char s_data_font_font_us_utf8_NFTR_0208aab4[] = "/data/font/font_us_utf8.NFTR";
char s_data_font_font_us_lc_utf8_NFTR_0208aad4[] = "/data/font/font_us_lc_utf8.NFTR";

u16 DAT_0208aaf4 = 60; // target frame rate (FrameTimer.cpp)
u8 DAT_0208aaf8 = 1;
u16 DAT_0208aafa = 60;

char s_COM_0208aafc[] = "COM";
char s_s_s_LZ_bin_0208ab00[] = "%s/%s_LZ.bin";
char s_s_s_NCGR_0208ab10[] = "%s:%s.NCGR";
char s_s_s_NCLR_0208ab1c[] = "%s:%s.NCLR";
char s_s_s_NCER_0208ab28[] = "%s:%s.NCER";
char s_s_s_cac_0208ab34[] = "%s:%s.cac";

HeapHandles sHeapHandles;
u32 MAIN_BSS_0208F31C;
u32 MAIN_BSS_0208F320[0x20000 / sizeof(u32)]; // whole-file load buffer (CBinaryFile.cpp, files up to 0x20000 bytes)
NNSGfdPlttKey MAIN_BSS_020AF320;
NNSG2dImagePaletteProxy MAIN_BSS_020AF324;

// Frame-time scale; the asm's static initializer sub_02084038 computes 60 / DAT_0208aafa.
fx32 MAIN_BSS_020AF338 = FX32_DIV(FX32_CONST(60), (fx64)(DAT_0208aafa << FX32_SHIFT));

// ---- asm/arm9_0208AC1C.s (.data) ----

// Start map and position of each chapter's "First" script.
ChapterInfo s_c000First_0208ac1c[] = {
    { "c000First", 0, 360, 360 }, // 0
    { "c001First", 0, 0, 0 }, // 1
    { "c002First", 47, 216, 168 }, // 2
    { "c003First", 20, 176, 192 }, // 3
    { "c004First", 0, 0, 0 }, // 4
    { "c005First", 8, -32, 0 }, // 5
    { "c006First", 8, 0, 0 }, // 6
    { "c007First", 8, 336, 135 }, // 7
    { "c008First", 0, 0, 0 }, // 8
    { "c009First", 11, 260, 160 }, // 9
    { "c010First", 0, 0, 0 }, // 10
    { "c011First", 8, 368, 180 }, // 11
    { "c012First", 0, 0, 0 }, // 12
    { "c013First", 8, 368, 180 }, // 13
    { "c014First", 0, 0, 0 }, // 14
    { "c015First", 8, 368, 180 }, // 15
    { "c016First", 14, 288, 217 }, // 16
    { "c017First", 0, 0, 0 }, // 17
    { "c018First", 8, 368, 180 }, // 18
    { "c019First", 0, 0, 0 }, // 19
    { "c020First", 47, 0, 0 }, // 20
    { "c021First", 47, 216, 168 }, // 21
    { "c022First", 23, 0, 0 }, // 22
    { "c023First", 23, 320, 112 }, // 23
    { "c024First", 23, 320, 280 }, // 24
    { "c025First", 23, 0, 0 }, // 25
    { "c026First", 23, 320, 100 }, // 26
    { "c027First", 23, 320, 280 }, // 27
    { "c028First", 23, 320, 280 }, // 28
    { "c029First", 23, 320, 112 }, // 29
    { "c030First", 103, 254, 496 }, // 30
    { "c031First", 120, 352, 416 }, // 31
    { "c032First", 121, 0, 0 }, // 32
    { "c033First", 121, 248, 104 }, // 33
    { "c034First", 23, 0, 0 }, // 34
    { "c035First", 23, 320, 100 }, // 35
    { "c036First", 23, 320, 100 }, // 36
    { "c037First", 23, 0, 0 }, // 37
    { "c038First", 23, 320, 112 }, // 38
    { "c039First", 158, 424, 480 }, // 39
    { "c040First", 23, 0, 0 }, // 40
    { "c041First", 23, 320, 225 }, // 41
    { "c042First", 123, 0, 0 }, // 42
    { "c043First", 123, 256, 400 }, // 43
    { "c044First", 126, 0, 0 }, // 44
    { "c045First", 126, 336, 320 }, // 45
    { "c046First", 119, 320, 160 }, // 46
    { "c047First", 208, 0, 0 }, // 47
    { "c048First", 208, 224, 176 }, // 48
    { "c049First", 127, 0, 0 }, // 49
    { "c050First", 126, 496, 380 }, // 50
    { "c051First", 119, 320, 160 }, // 51
    { "c052First", 126, 352, 320 }, // 52
    { "c053First", 119, 320, 160 }, // 53
    { "c054First", 266, 80, 152 }, // 54
    { "c055First", 437, -10, -10 }, // 55
    { "c056First", 305, 320, 800 }, // 56
    { "c057First", 123, 0, 0 }, // 57
    { "c058First", 126, 496, 376 }, // 58
    { "c059First", 121, 490, 376 }, // 59
    { "c060First", 119, 320, 160 }, // 60
    { "c061First", 328, 400, 440 }, // 61
    { "c062First", 348, 336, 184 }, // 62
    { "c063First", 359, 352, 360 }, // 63
    { "c064First", 359, 352, 360 }, // 64
    { "c065First", 366, 128, 80 }, // 65
    { "c066First", 364, 288, 592 }, // 66
    { "c067First", 91, -32, 0 }, // 67
    { "c068First", 47, 176, 160 }, // 68
    { "c069First", 47, 176, 160 }, // 69
    { "cx01First", 30, 320, 276 }, // 70
    { "cx02First", 22, 0, 0 }, // 71
    { "cx03First", 131, 480, 376 }, // 72
    { "cx04First", 55, 208, 136 }, // 73
    { "cx05First", 132, 0, 0 }, // 74
    { "cx06First", 126, 352, 296 }, // 75
};

// ---- asm/arm9_0210CA30.s (.bss) ----

CardBackupInfo sCardBackupInfo;
SaveManager *MAIN_BSS_0210CA3C;
CFieldScene *MAIN_BSS_0210CA40;
FieldScriptLauncher *MAIN_BSS_0210CA44;
CFieldPlayer *MAIN_BSS_0210CA48;
CFieldPartnerManage *MAIN_BSS_0210CA4C;
CFieldNpcManage *MAIN_BSS_0210CA50;
CFieldMap *MAIN_BSS_0210CA54;
FieldEventRectManage *MAIN_BSS_0210CA58;
CFieldEnemyManage *MAIN_BSS_0210CA5C;
CFieldEffectManage *MAIN_BSS_0210CA60;
FieldDrawActorDataPool *MAIN_BSS_0210CA64;
FieldDebugFlags *MAIN_BSS_0210CA68;
FieldData *MAIN_BSS_0210CA6C;
CFieldPlayerInputControlManage *MAIN_BSS_0210CA70;
// Flag word (FieldActor.cpp, Syscall.cpp: u32) that CFieldScene.cpp clears as a void *: pointer-sized so that its
// 8-byte store on a 64-bit build stays inside the object (the u32 users read the low half, little endian).
void *MAIN_BSS_0210CA74;
FieldScreenEffectManage *MAIN_BSS_0210CA78;
CFieldTargetObjectManage *MAIN_BSS_0210CA7C;
FieldDebugMenu *MAIN_BSS_0210CA80;

// ---- asm/arm9_0210CAB0.s (.bss) ----

u32 MAIN_BSS_0210CAB0; // picture number set by a script syscall (CSuitePictureScene.cpp)
LogFile MAIN_BSS_0210CAB4;
char MAIN_BSS_0210CAC8[0x400];
MATHRandContext16 MAIN_BSS_0210CEC8;
ScriptGlobals MAIN_BSS_0210CED4;

// ---- asm/overlay_11_02169B40.s (.bss) ----

BOOL OVERLAY11_BSS_02169B40; // set by the WM_Reset/WM_End callbacks (RangerNetMenu.cpp); 0x14 dead bytes follow in the DS build

} // extern "C"

// Two symbols name a field of another object, as in the asm:
// - MAIN_BSS_0210CA38 (SaveManager.cpp, u32) = sCardBackupInfo.totalSize;
// - MAIN_BSS_0210CED8 (ScriptVM.cpp, ScriptSyscall *[64]) = MAIN_BSS_0210CED4.syscalls.
// C++ has no way to name a member as a separate global, so they are assembler aliases. The second offset is the
// pointer size (4 on the DS, 8 on a 64-bit PC); the static_asserts keep both literals honest.
// The compiler treats differently named globals as distinct, so these only work across files: never write through
// one name and read through the other in one file, and don't build with LTO.
#ifndef __MWERKS__
#include <stddef.h>
#include <stdint.h>

#if UINTPTR_MAX > 0xFFFFFFFFu
#define PC_PTR_SIZE "8"
#else
#define PC_PTR_SIZE "4"
#endif
#define PC_STR2(x)   #x
#define PC_STR(x)    PC_STR2(x)
#define PC_SYM(name) PC_STR(__USER_LABEL_PREFIX__) #name

static_assert(offsetof(CardBackupInfo, totalSize) == 8, "MAIN_BSS_0210CA38 alias offset");
static_assert(offsetof(ScriptGlobals, syscalls) == sizeof(void *), "MAIN_BSS_0210CED8 alias offset");

asm(".globl " PC_SYM(MAIN_BSS_0210CA38) "\n"
                                        ".set " PC_SYM(MAIN_BSS_0210CA38) ", " PC_SYM(sCardBackupInfo) " + 8\n"
                                                                                                       ".globl " PC_SYM(MAIN_BSS_0210CED8) "\n"
                                                                                                                                           ".set " PC_SYM(MAIN_BSS_0210CED8) ", " PC_SYM(MAIN_BSS_0210CED4) " + " PC_PTR_SIZE "\n");
#endif
