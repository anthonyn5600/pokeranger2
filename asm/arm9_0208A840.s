    .include "macros.inc"
    .include "include/arm9_0208A840.inc"

; Main .init/.ctor/.data/.bss of the objects before src/CPowerManage.cpp (whose data comes from C++)

    .section .init, 4

	arm_func_start sub_02084038
sub_02084038: ; 0x02084038
	stmdb sp!, {r3, lr}
	ldr r1, _02084064 ; =DAT_0208aaf8
	mov r0, #0x3c000000
	ldrh r2, [r1, #2]
	mov r1, #0
	mov r2, r2, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	ldr r1, _02084068 ; =MAIN_BSS_020AF338
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02084064: .word DAT_0208aaf8
_02084068: .word MAIN_BSS_020AF338
	arm_func_end sub_02084038

    .section .ctor, 4
; mwld keeps a .ctor section only through an object named .p__sinit_* (like mwcc's), .sinit is KEEP_SECTION
; but comes after every object's .ctor

	.global DAT_0208a354
DAT_0208a354: ; 0x0208A354
	.type .p__sinit_arm9_0208A840, @object
	.size .p__sinit_arm9_0208A840, 4
.p__sinit_arm9_0208A840:
	.word sub_02084038

    .data
    .balign 4

	.global DAT_0208a840
DAT_0208a840: ; 0x0208A840
	.byte 0x3C, 0x00, 0x00, 0x00

	.global DAT_0208a844
DAT_0208a844: ; 0x0208A844
	.byte 0x00, 0x00, 0x00, 0x00

	.global s_BGT_0208a848
s_BGT_0208a848: ; 0x0208A848
	.asciz "BGT"

	.global s_data_interface_i059_LZ_bin_0208a84c
s_data_interface_i059_LZ_bin_0208a84c: ; 0x0208A84C
	.asciz "data/interface/i059_LZ.bin"

	.global _0208A867
_0208A867:
	.byte 0x00

	.global s_BGT_i059_00_NCGR_0208a868
s_BGT_i059_00_NCGR_0208a868: ; 0x0208A868
	.asciz "BGT:i059_00.NCGR"

	.global _0208A879
_0208A879:
	.byte 0x00, 0x00, 0x00

	.global s_BGT_i059_00_NSCR_0208a87c
s_BGT_i059_00_NSCR_0208a87c: ; 0x0208A87C
	.asciz "BGT:i059_00.NSCR"

	.global _0208A88D
_0208A88D:
	.byte 0x00, 0x00, 0x00

	.global s_BGT_i059_NCLR_0208a890
s_BGT_i059_NCLR_0208a890: ; 0x0208A890
	.asciz "BGT:i059.NCLR"

	.global _0208A89E
_0208A89E:
	.byte 0x00, 0x00

	.global s_BGT_i059_00_NCLR_0208a8a0
s_BGT_i059_00_NCLR_0208a8a0: ; 0x0208A8A0
	.asciz "BGT:i059_00.NCLR"

	.global _0208A8B1
_0208A8B1:
	.byte 0x00, 0x00, 0x00

	.global s_data_font_prs_jp_NCLR_0208a8b4
s_data_font_prs_jp_NCLR_0208a8b4: ; 0x0208A8B4
	.asciz "data/font/prs_jp.NCLR"

	.global _0208A8CA
_0208A8CA:
	.byte 0x00, 0x00

	.global s_d_0208a8cc
s_d_0208a8cc: ; 0x0208A8CC
	.asciz "%d"

	.global _0208A8CF
_0208A8CF:
	.byte 0x00

	.global s_data_message_system_system_mes_0208a8d0
s_data_message_system_system_mes_0208a8d0: ; 0x0208A8D0
	.asciz "data/message/system/system_mes"

	.global _0208A8EF
_0208A8EF:
	.byte 0x00

	.global s_data_message_system_system_03d_m_0208a8f0
s_data_message_system_system_03d_m_0208a8f0: ; 0x0208A8F0
	.asciz "data/message/system/system%03d_mes"

	.global _0208A913
_0208A913:
	.byte 0x00

	.global s_data_message_area_m_03d_mes_0208a914
s_data_message_area_m_03d_mes_0208a914: ; 0x0208A914
	.asciz "data/message/area/m%03d_mes"

	.global s_data_message_chapter_chapter_03d_0208a930
s_data_message_chapter_chapter_03d_0208a930: ; 0x0208A930
	.asciz "data/message/chapter/chapter%03d_mes"

	.global _0208A955
_0208A955:
	.byte 0x00, 0x00, 0x00

	.global s_data_message_chapter_chapterx_02_0208a958
s_data_message_chapter_chapterx_02_0208a958: ; 0x0208A958
	.asciz "data/message/chapter/chapterx%02d_mes"

	.global _0208A97E
_0208A97E:
	.byte 0x00, 0x00

	.global s_data_message_quest_quest_03d_mes_0208a980
s_data_message_quest_quest_03d_mes_0208a980: ; 0x0208A980
	.asciz "data/message/quest/quest%03d_mes"

	.global _0208A9A1
_0208A9A1:
	.byte 0x00, 0x00, 0x00

	.global s_data_message_battle_battle_02d_m_0208a9a4
s_data_message_battle_battle_02d_m_0208a9a4: ; 0x0208A9A4
	.asciz "data/message/battle/battle%02d_mes"

	.global _0208A9C7
_0208A9C7:
	.byte 0x00

	.global s_ICN_0208a9c8
s_ICN_0208a9c8: ; 0x0208A9C8
	.asciz "ICN"

	.global s_data_interface_i058_LZ_bin_0208a9cc
s_data_interface_i058_LZ_bin_0208a9cc: ; 0x0208A9CC
	.asciz "data/interface/i058_LZ.bin"

	.global _0208A9E7
_0208A9E7:
	.byte 0x00

	.global s_ICN_i058_00_NCGR_0208a9e8
s_ICN_i058_00_NCGR_0208a9e8: ; 0x0208A9E8
	.asciz "ICN:i058_00.NCGR"

	.global _0208A9F9
_0208A9F9:
	.byte 0x00, 0x00, 0x00

	.global s_ICN_i058_NCLR_0208a9fc
s_ICN_i058_NCLR_0208a9fc: ; 0x0208A9FC
	.asciz "ICN:i058.NCLR"

	.global _0208AA0A
_0208AA0A:
	.byte 0x00, 0x00

	.global s_data_font_prs_lc_jp_NCLR_0208aa0c
s_data_font_prs_lc_jp_NCLR_0208aa0c: ; 0x0208AA0C
	.asciz "data/font/prs_lc_jp.NCLR"

	.global _0208AA25
_0208AA25:
	.byte 0x00, 0x00, 0x00

	.global s_data_font_prs_jp_NCLR_0208aa28
s_data_font_prs_jp_NCLR_0208aa28: ; 0x0208AA28
	.asciz "data/font/prs_jp.NCLR"

	.global _0208AA3E
_0208AA3E:
	.byte 0x00, 0x00

	.global s_data_font_prs_lc_jp_NCLR_0208aa40
s_data_font_prs_lc_jp_NCLR_0208aa40: ; 0x0208AA40
	.asciz "data/font/prs_lc_jp.NCLR"

	.global _0208AA59
_0208AA59:
	.byte 0x00, 0x00, 0x00

	.global s_data_font_prs_jp_NCLR_0208aa5c
s_data_font_prs_jp_NCLR_0208aa5c: ; 0x0208AA5C
	.asciz "data/font/prs_jp.NCLR"

	.global _0208AA72
_0208AA72:
	.byte 0x00, 0x00

	.global s_data_font_font_jp_utf8_NFTR_0208aa74
s_data_font_font_jp_utf8_NFTR_0208aa74: ; 0x0208AA74
	.asciz "/data/font/font_jp_utf8.NFTR"

	.global _0208AA91
_0208AA91:
	.byte 0x00, 0x00, 0x00

	.global s_data_font_font_jp_lc_utf8_NFTR_0208aa94
s_data_font_font_jp_lc_utf8_NFTR_0208aa94: ; 0x0208AA94
	.asciz "/data/font/font_jp_lc_utf8.NFTR"

	.global s_data_font_font_us_utf8_NFTR_0208aab4
s_data_font_font_us_utf8_NFTR_0208aab4: ; 0x0208AAB4
	.asciz "/data/font/font_us_utf8.NFTR"

	.global _0208AAD1
_0208AAD1:
	.byte 0x00, 0x00, 0x00

	.global s_data_font_font_us_lc_utf8_NFTR_0208aad4
s_data_font_font_us_lc_utf8_NFTR_0208aad4: ; 0x0208AAD4
	.asciz "/data/font/font_us_lc_utf8.NFTR"

	.global DAT_0208aaf4
DAT_0208aaf4: ; 0x0208AAF4
	.byte 0x3C, 0x00, 0x00, 0x00

	.global DAT_0208aaf8
DAT_0208aaf8: ; 0x0208AAF8
	.byte 0x01, 0x00

	.global DAT_0208aafa
DAT_0208aafa: ; 0x0208AAFA
	.byte 0x3C, 0x00

	.global s_COM_0208aafc
s_COM_0208aafc: ; 0x0208AAFC
	.asciz "COM"

	.global s_s_s_LZ_bin_0208ab00
s_s_s_LZ_bin_0208ab00: ; 0x0208AB00
	.asciz "%s/%s_LZ.bin"

	.global _0208AB0D
_0208AB0D:
	.byte 0x00, 0x00, 0x00

	.global s_s_s_NCGR_0208ab10
s_s_s_NCGR_0208ab10: ; 0x0208AB10
	.asciz "%s:%s.NCGR"

	.global _0208AB1B
_0208AB1B:
	.byte 0x00

	.global s_s_s_NCLR_0208ab1c
s_s_s_NCLR_0208ab1c: ; 0x0208AB1C
	.asciz "%s:%s.NCLR"

	.global _0208AB27
_0208AB27:
	.byte 0x00

	.global s_s_s_NCER_0208ab28
s_s_s_NCER_0208ab28: ; 0x0208AB28
	.asciz "%s:%s.NCER"

	.global _0208AB33
_0208AB33:
	.byte 0x00

	.global s_s_s_cac_0208ab34
s_s_s_cac_0208ab34: ; 0x0208AB34
	.asciz "%s:%s.cac"

	.global _0208AB3E
_0208AB3E:
	.byte 0x00, 0x00

    .bss

    .global sHeapHandles
sHeapHandles: ; 0x0208F310
    .space 0x4

    .global sHeap_SecondaryHandle
sHeap_SecondaryHandle: ; 0x0208F314
    .space 0x8

    .global MAIN_BSS_0208F31C
MAIN_BSS_0208F31C: ; 0x0208F31C
    .space 0x4

    .global MAIN_BSS_0208F320
MAIN_BSS_0208F320: ; 0x0208F320
    .space 0xD04

    .global MAIN_BSS_02090024
MAIN_BSS_02090024: ; 0x02090024
    .space 0x10003

    .global MAIN_BSS_020A0027
MAIN_BSS_020A0027: ; 0x020A0027
    .space 0xF2F9

    .global MAIN_BSS_020AF320
MAIN_BSS_020AF320: ; 0x020AF320
    .space 0x4

    .global MAIN_BSS_020AF324
MAIN_BSS_020AF324: ; 0x020AF324
    .space 0x14

    .global MAIN_BSS_020AF338
MAIN_BSS_020AF338: ; 0x020AF338
    .space 0x4
