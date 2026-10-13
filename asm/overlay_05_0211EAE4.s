    .include "macros.inc"
    .include "include/overlay_05_0211EAE4.inc"

    .text

	arm_func_start _ZN19CStylerStatusScreenC1EP5CGameP11CStylerData
_ZN19CStylerStatusScreenC1EP5CGameP11CStylerData: ; 0x0211EAE4
	ldr r3, _0211EB24 ; =_ZTV13CStylerScreen+8
	mov ip, #0
	stmia r0, {r3, ip}
	ldr r3, _0211EB28 ; =PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8
	str ip, [r0, #8]
	str r3, [r0]
	str ip, [r0, #0xc]
	str ip, [r0, #0x220]
	str ip, [r0, #0x224]
	str r1, [r0, #0x214]
	str r2, [r0, #0x210]
	ldr r1, [r2, #8]
	str r1, [r0, #0x21c]
	ldr r1, [r2, #0x10]
	str r1, [r0, #0x218]
	bx lr
	.align 2, 0
_0211EB24: .word _ZTV13CStylerScreen+8
_0211EB28: .word PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8
	arm_func_end _ZN19CStylerStatusScreenC1EP5CGameP11CStylerData

	arm_func_start _ZN19CStylerStatusScreenD1Ev
_ZN19CStylerStatusScreenD1Ev: ; 0x0211EB2C
	stmdb sp!, {r4, lr}
	ldr r1, _0211EB50 ; =PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0211EB50: .word PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8
	arm_func_end _ZN19CStylerStatusScreenD1Ev

	arm_func_start _ZN19CStylerStatusScreenD0Ev
_ZN19CStylerStatusScreenD0Ev: ; 0x0211EB54
	stmdb sp!, {r4, lr}
	ldr r1, _0211EB80 ; =PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0211EB80: .word PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8
	arm_func_end _ZN19CStylerStatusScreenD0Ev

	arm_func_start _ZN19CStylerStatusScreen4LoadEv
_ZN19CStylerStatusScreen4LoadEv: ; 0x0211EB84
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN19CStylerStatusScreen8LoadDataEv
	mov r0, r4
	bl _ZN19CStylerStatusScreen7SetupBGEv
	mov r0, r4
	bl _ZN19CStylerStatusScreen11LoadSpritesEv
	mov r0, r4
	bl _ZN19CStylerStatusScreen6LoadBGEv
	mov r0, r4
	bl _ZN19CStylerStatusScreen9DrawTextsEv
	ldmia sp!, {r4, pc}
	arm_func_end _ZN19CStylerStatusScreen4LoadEv

	arm_func_start _ZN19CStylerStatusScreen7ReleaseEv
_ZN19CStylerStatusScreen7ReleaseEv: ; 0x0211EBB4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0x220]
	cmp r4, #0
	beq _0211EBE4
	beq _0211EBDC
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end _ZN19CStylerStatusScreen7ReleaseEv
_0211EBDC:
	mov r0, #0
	str r0, [r5, #0x220]
_0211EBE4:
	ldr r4, [r5, #0x224]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _0211EC04
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_0211EC04:
	mov r0, #0
	str r0, [r5, #0x224]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN19CStylerStatusScreen5ResetEv
_ZN19CStylerStatusScreen5ResetEv: ; 0x0211EC10
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	str r1, [r4, #4]
	str r1, [r4, #8]
	bl _ZN19CStylerStatusScreen7SetupBGEv
	ldr r0, [r4, #0x228]
	mov r1, #1
	str r1, [r0, #0x14]
	ldr r3, [r4, #0x22c]
	mov ip, #0
	ldr r1, _0211EC54 ; =0x05000200
	add r0, r4, #0x10
	mov r2, #0x1e0
	str ip, [r3, #0x14]
	bl MIi_CpuCopyFast
	ldmia sp!, {r4, pc}
	.align 2, 0
_0211EC54: .word 0x05000200
	arm_func_end _ZN19CStylerStatusScreen5ResetEv

	arm_func_start _ZN19CStylerStatusScreen8LoadDataEv
_ZN19CStylerStatusScreen8LoadDataEv: ; 0x0211EC58
	bx lr
	arm_func_end _ZN19CStylerStatusScreen8LoadDataEv

	arm_func_start _ZN19CStylerStatusScreen7SetupBGEv
_ZN19CStylerStatusScreen7SetupBGEv: ; 0x0211EC5C
	mov r0, #0x4000000
	ldr r2, [r0]
	ldr r1, _0211ECF8 ; =0x00001310
	bic r2, r2, #0x1f00
	orr r2, r2, #0x1d00
	str r2, [r0]
	ldrh r3, [r0, #8]
	add r2, r1, #0x1f4
	add r1, r1, #0x3f4
	and r3, r3, #0x43
	orr r3, r3, #0x310
	orr r3, r3, #0x1000
	strh r3, [r0, #8]
	ldrh ip, [r0, #0xc]
	mov r3, #0
	and ip, ip, #0x43
	orr r2, ip, r2
	strh r2, [r0, #0xc]
	ldrh r2, [r0, #0xe]
	and r2, r2, #0x43
	orr r1, r2, r1
	strh r1, [r0, #0xe]
	ldrh r1, [r0, #0xa]
	bic r1, r1, #3
	strh r1, [r0, #0xa]
	ldrh r1, [r0, #8]
	bic r1, r1, #3
	orr r1, r1, #1
	strh r1, [r0, #8]
	ldrh r1, [r0, #0xc]
	bic r1, r1, #3
	orr r1, r1, #2
	strh r1, [r0, #0xc]
	ldrh r1, [r0, #0xe]
	bic r1, r1, #3
	orr r1, r1, #3
	strh r1, [r0, #0xe]
	strh r3, [r0, #0x50]
	bx lr
	.align 2, 0
_0211ECF8: .word 0x00001310
	arm_func_end _ZN19CStylerStatusScreen7SetupBGEv

	arm_func_start _ZN19CStylerStatusScreen11LoadSpritesEv
_ZN19CStylerStatusScreen11LoadSpritesEv: ; 0x0211ECFC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
	sub sp, sp, #4
	mov r4, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _0211ED38
	ldr r3, [r4, #0x214]
	mov r1, #0x40
	str r1, [sp]
	add r1, r3, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r3, #0x34
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end _ZN19CStylerStatusScreen11LoadSpritesEv
_0211ED38:
	str r0, [r4, #0x220]
	mov r0, #0
	str r0, [sp]
	ldr r0, [r4, #0x220]
	ldr r1, _0211EED8 ; =s_data_menu_overlay_5_0212083c
	ldr r2, _0211EEDC ; =s_stl000_00_overlay_5_02120848
	mov r3, #0x350
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r7, #0
	ldr r8, _0211EEE0 ; =DAT_overlay_5_021206e8
	mov r6, #0x1a
	mov r5, r7
_0211ED68:
	ldr r1, [r4, #0x210]
	ldr r0, [r8, #0x10]
	add r0, r1, r0, lsl #2
	ldr r0, [r0, #0x14]
	cmp r0, #0
	ldrne r1, [r8, #8]
	str r5, [sp]
	ldr r2, [r8]
	ldr r0, [r8, #4]
	mov r2, r2, lsl #3
	mov r3, r0, lsl #3
	ldr r0, [r4, #0x220]
	moveq r1, r6
	sub r2, r2, #8
	add r3, r3, #8
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	add r7, r7, #1
	cmp r7, #0x11
	add r8, r8, #0x14
	blt _0211ED68
	mov r7, #0
	ldr r8, _0211EEE4 ; =DAT_overlay_5_0212060c
	mov r6, #0x1a
	mov r5, r7
_0211EDC8:
	ldr r1, [r4, #0x210]
	ldr r0, [r8, #0x10]
	add r0, r1, r0, lsl #2
	ldr r0, [r0, #0x14]
	cmp r0, #0
	ldrne r1, [r8, #8]
	str r5, [sp]
	ldr r2, [r8]
	ldr r0, [r8, #4]
	mov r2, r2, lsl #3
	mov r3, r0, lsl #3
	ldr r0, [r4, #0x220]
	moveq r1, r6
	sub r2, r2, #8
	add r3, r3, #8
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	add r7, r7, #1
	cmp r7, #4
	add r8, r8, #0x14
	blt _0211EDC8
	mov r5, #0
	ldr r6, _0211EEE8 ; =DAT_overlay_5_0212065c
	mov r7, r5
_0211EE24:
	ldr r2, [r4, #0x210]
	ldr r1, [r6, #0xc]
	ldr r0, [r6, #0x10]
	add r1, r2, r1, lsl #2
	ldr r1, [r1, #0x14]
	cmp r1, r0
	blt _0211EE54
	str r7, [sp]
	ldr r0, [r4, #0x220]
	ldr r1, [r6, #8]
	ldmia r6, {r2, r3}
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_0211EE54:
	add r5, r5, #1
	cmp r5, #7
	add r6, r6, #0x14
	blt _0211EE24
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4, #0x220]
	mov r2, #0xf0
	mov r3, #0x5c
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r1, #0x20
	str r0, [r4, #0x228]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4, #0x228]
	mov r2, r1
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	mov r0, #0
	str r0, [sp]
	ldr r0, [r4, #0x220]
	mov r1, #0x1b
	mov r2, #0xf0
	mov r3, #0x5c
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r4, #0x22c]
	mov r1, #0
	str r1, [r0, #0x14]
	ldr r0, _0211EEEC ; =0x05000200
	add r1, r4, #0x10
	mov r2, #0x1e0
	bl MIi_CpuCopyFast
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0211EED8: .word s_data_menu_overlay_5_0212083c
_0211EEDC: .word s_stl000_00_overlay_5_02120848
_0211EEE0: .word DAT_overlay_5_021206e8
_0211EEE4: .word DAT_overlay_5_0212060c
_0211EEE8: .word DAT_overlay_5_0212065c
_0211EEEC: .word 0x05000200

	arm_func_start _Z14SetTilePalettePtiii
_Z14SetTilePalettePtiii: ; 0x0211EEF0
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #8
	ldr r4, _0211EF78 ; =DAT_overlay_5_021203d8
	add r8, sp, #0
	ldrh r7, [r4]
	ldrh r6, [r4, #2]
	ldrh r5, [r4, #4]
	ldrh r4, [r4, #6]
	strh r6, [sp, #2]
	strh r7, [sp]
	strh r4, [sp, #6]
	mov r3, r3, lsl #1
	strh r5, [sp, #4]
	ldrh r5, [r8, r3]
	mov ip, #0
	ldr r6, _0211EF7C ; =0x00008FFF
	mov r3, ip
	arm_func_end _Z14SetTilePalettePtiii
_0211EF34:
	mov lr, r3
	add r4, ip, r1
_0211EF3C:
	add r7, lr, r2
	add r7, r4, r7, lsl #5
	mov r8, r7, lsl #1
	ldrh r7, [r0, r8]
	add lr, lr, #1
	cmp lr, #2
	and r7, r7, r6
	orr r7, r7, r5
	strh r7, [r0, r8]
	blt _0211EF3C
	add ip, ip, #1
	cmp ip, #0xa
	blt _0211EF34
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0211EF78: .word DAT_overlay_5_021203d8
_0211EF7C: .word 0x00008FFF

	arm_func_start _ZN19CStylerStatusScreen6LoadBGEv
_ZN19CStylerStatusScreen6LoadBGEv: ; 0x0211EF80
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x810
	mov r1, #0x200
	mov r4, r0
	str r1, [sp]
	ldr r3, _0211F074 ; =s_stl000_overlay_5_02120868
	ldr r0, _0211F078 ; =s_menu_overlay_5_02120854
	ldr r1, _0211F07C ; =s_stl000_bg_overlay_5_0212085c
	str r3, [sp, #4]
	mov r5, #8
	mov r2, #2
	str r5, [sp, #8]
	bl _Z19BGS_LoadCharAndPlttPKcS0_iS0_mS0_m
	mov r0, r5
	str r0, [sp]
	mov r0, #0x200
	str r0, [sp, #4]
	add r2, sp, #0x10
	str r2, [sp, #8]
	mov r5, #0
	ldr r0, _0211F078 ; =s_menu_overlay_5_02120854
	ldr r1, _0211F07C ; =s_stl000_bg_overlay_5_0212085c
	ldr r3, _0211F080 ; =s_stl000_01_overlay_5_02120870
	mov r2, #2
	str r5, [sp, #0xc]
	bl _Z11BGS_LoadScrPKcS0_iS0_mmim
	mov r0, #8
	str r0, [sp]
	mov r0, #0x200
	str r0, [sp, #4]
	mov r2, r5
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, _0211F078 ; =s_menu_overlay_5_02120854
	ldr r1, _0211F07C ; =s_stl000_bg_overlay_5_0212085c
	ldr r3, _0211F084 ; =s_stl000_00_overlay_5_02120848
	mov r2, #3
	bl _Z11BGS_LoadScrPKcS0_iS0_mmim
	mov r6, r5
	ldr r7, _0211F088 ; =DAT_overlay_5_021206e8
	add r5, sp, #0x10
	arm_func_end _ZN19CStylerStatusScreen6LoadBGEv
_0211F024:
	ldr r1, [r4, #0x210]
	ldr r0, [r7, #0x10]
	add r0, r1, r0, lsl #2
	ldr r3, [r0, #0x14]
	cmp r3, #0
	beq _0211F048
	mov r0, r5
	ldmia r7, {r1, r2}
	bl _Z14SetTilePalettePtiii
_0211F048:
	add r6, r6, #1
	cmp r6, #0x11
	add r7, r7, #0x14
	blt _0211F024
	bl G2_GetBG2ScrPtr
	mov r1, r0
	add r0, sp, #0x10
	mov r2, #0x800
	bl MIi_CpuCopyFast
	add sp, sp, #0x810
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0211F074: .word s_stl000_overlay_5_02120868
_0211F078: .word s_menu_overlay_5_02120854
_0211F07C: .word s_stl000_bg_overlay_5_0212085c
_0211F080: .word s_stl000_01_overlay_5_02120870
_0211F084: .word s_stl000_00_overlay_5_02120848
_0211F088: .word DAT_overlay_5_021206e8

	arm_func_start _ZN19CStylerStatusScreen9DrawTextsEv
_ZN19CStylerStatusScreen9DrawTextsEv: ; 0x0211F08C
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x2c
	mov sl, r0
	ldr r0, [sl, #0x214]
	add r0, r0, #0x1000
	ldr r6, [r0, #0x494]
	mov r0, r6
	bl _ZN17UnkClass_0200C38C12sub_0200C3D0Ev
	mov r0, r6
	mov r1, #0
	mov r2, #0x13
	mov r3, #4
	bl _ZN17UnkClass_0200C38C12sub_0200C408Ei11GXBGScrBase12GXBGCharBase
	mov r0, r6
	mov r1, #0x16
	bl _ZN17UnkClass_0200C38C12sub_0200C680Ei
	ldr r0, [sl, #0x210]
	mov r4, #0x3d
	ldr r7, [r0, #0xc]
	mov r0, #1
	str r0, [sp]
	mov r1, #0
	stmib sp, {r1, r4}
	str r1, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	mov r0, r6
	mov r2, #0xb
	mov r3, #3
	bl _ZN17UnkClass_0200C38C12sub_0200C6C8Eiiiiiiii
	ldr r0, [sl, #0x21c]
	add r4, r4, #0x21
	ldr r0, [r0, #8]
	ldr r1, [r0, #0x1fc]
	cmp r1, #0
	beq _0211F140
	mov r0, #3
	stmia sp, {r0, r1}
	mov r1, #0
	str r1, [sp, #8]
	mov r0, r6
	mov r2, #4
	mov r3, #6
	str r1, [sp, #0xc]
	bl _ZN17UnkClass_0200C38C12sub_0200C7A4EiiiiPhii
	arm_func_end _ZN19CStylerStatusScreen9DrawTextsEv
_0211F140:
	ldr r0, _0211F358 ; =DAT_overlay_5_021203e0
	add r3, sp, #0x14
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldr sb, _0211F35C ; =DAT_overlay_5_021206e8
	mov r5, #0
	add fp, sp, #0x20
_0211F15C:
	ldr r1, [sb]
	mov r0, r6
	str r1, [sp]
	ldr r2, [sb, #4]
	add r1, r5, #1
	stmib sp, {r2, r4}
	mov r2, #0
	str r2, [sp, #0xc]
	mov r2, #2
	str r2, [sp, #0x10]
	mov r2, #0xa
	mov r3, #2
	bl _ZN17UnkClass_0200C38C12sub_0200C6C8Eiiiiiiii
	ldr r1, [sl, #0x210]
	ldr r0, [sb, #0x10]
	add r4, r4, #0x14
	add r0, r1, r0, lsl #2
	ldr r8, [r0, #0x14]
	cmp r8, #0
	beq _0211F238
	ldr r2, [r7, #8]
	ldr r1, [sb, #0xc]
	mov r0, r6
	add r1, r2, r1, lsl #3
	ldr r3, [r1, #0xc]
	mov r2, #3
	stmia sp, {r2, r3}
	mov r2, #0
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	mov r2, #2
	add r1, r5, #1
	mov r3, r2
	bl _ZN17UnkClass_0200C38C12sub_0200C7A4EiiiiPhii
	add r0, sp, #0x14
	ldmia r0, {r0, r1, r2}
	stmia fp, {r0, r1, r2}
	mov r3, #3
	mov r0, r3
	str r0, [sp]
	add r8, fp, r8, lsl #2
	ldr r1, [sl, #0x21c]
	ldr r2, [r8, #-4]
	ldr r8, [r1, #8]
	mov r0, r6
	add r2, r8, r2, lsl #3
	ldr r8, [r2, #4]
	add r1, r5, #1
	str r8, [sp, #4]
	mov r8, #0
	str r8, [sp, #8]
	mov r2, #0x36
	str r8, [sp, #0xc]
	bl _ZN17UnkClass_0200C38C12sub_0200C7A4EiiiiPhii
	b _0211F26C
_0211F238:
	mov r0, #3
	str r0, [sp]
	ldr r1, [r7, #8]
	mov r0, r6
	ldr r2, [r1, #0xcc]
	add r1, r5, #1
	str r2, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	mov r2, #4
	mov r3, #2
	bl _ZN17UnkClass_0200C38C12sub_0200C7A4EiiiiPhii
_0211F26C:
	add sb, sb, #0x14
	add r5, r5, #1
	cmp r5, #0x11
	blt _0211F15C
	mov r8, #0
	ldr sb, _0211F360 ; =DAT_overlay_5_0212060c
	mov fp, #3
	mov r5, r8
_0211F28C:
	ldr r1, [sb]
	mov r0, r6
	str r1, [sp]
	ldr r2, [sb, #4]
	add r1, r8, #0x12
	stmib sp, {r2, r4, r5}
	mov r2, #2
	str r2, [sp, #0x10]
	mov r2, #0xa
	mov r3, #2
	bl _ZN17UnkClass_0200C38C12sub_0200C6C8Eiiiiiiii
	ldr r1, [sl, #0x210]
	ldr r0, [sb, #0x10]
	add r4, r4, #0x14
	add r0, r1, r0, lsl #2
	ldr r0, [r0, #0x14]
	mov r3, #2
	cmp r0, #0
	beq _0211F310
	str fp, [sp]
	ldr r2, [r7, #8]
	ldr r1, [sb, #0xc]
	mov r0, r6
	add r1, r2, r1, lsl #3
	ldr r2, [r1, #4]
	add r1, r8, #0x12
	str r2, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	mov r2, #4
	bl _ZN17UnkClass_0200C38C12sub_0200C7A4EiiiiPhii
	b _0211F340
_0211F310:
	mov r0, #3
	str r0, [sp]
	ldr r1, [r7, #8]
	mov r0, r6
	ldr r2, [r1, #0xcc]
	add r1, r8, #0x12
	str r2, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	mov r2, #4
	bl _ZN17UnkClass_0200C38C12sub_0200C7A4EiiiiPhii
_0211F340:
	add sb, sb, #0x14
	add r8, r8, #1
	cmp r8, #4
	blt _0211F28C
	add sp, sp, #0x2c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0211F358: .word DAT_overlay_5_021203e0
_0211F35C: .word DAT_overlay_5_021206e8
_0211F360: .word DAT_overlay_5_0212060c

	arm_func_start _ZN19CStylerStatusScreen6UpdateEv
_ZN19CStylerStatusScreen6UpdateEv: ; 0x0211F364
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #0x220]
	cmp r0, #0
	beq _0211F37C
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	arm_func_end _ZN19CStylerStatusScreen6UpdateEv
_0211F37C:
	ldr r0, [r4, #0x224]
	cmp r0, #0
	beq _0211F38C
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
_0211F38C:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0211F3AC
	cmp r0, #1
	beq _0211F3E4
	cmp r0, #2
	beq _0211F4BC
	b _0211F514
_0211F3AC:
	ldr r0, [r4, #0x214]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _0211F514
	ldr r0, [r4, #0x214]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	moveq r0, #1
	streq r0, [r4, #4]
	b _0211F514
_0211F3E4:
	ldr r1, [r4, #0x214]
	ldr r0, [r4, #0x218]
	ldr r5, [r1, #0x14]
	bl _ZN17UnkClass_0202A2AC12sub_0202A404Ev
	cmp r0, #0
	beq _0211F440
	mov r0, #2
	str r0, [r4, #4]
	ldr r0, [r4, #0x214]
	mov r1, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x14
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #0x214]
	mov r1, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x14
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0
	str r0, [r4, #0xc]
	b _0211F514
_0211F440:
	ldr r0, [r4, #0x228]
	bl _ZN17UnkClass_0200E96012sub_0200EB84Ev
	cmp r0, #0
	bne _0211F464
	ldrh r0, [r5, #2]
	and r0, r0, #0x100
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	beq _0211F514
_0211F464:
	ldr r0, [r4, #0x228]
	mov r1, #0
	str r1, [r0, #0x14]
	ldr r0, [r4, #0x22c]
	mov r1, #1
	str r1, [r0, #0x14]
	ldr r0, [r4, #0x214]
	mov r1, #0xfa
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #2
	str r0, [r4, #4]
	ldr r0, [r4, #0x214]
	mov r1, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x14
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #1
	str r0, [r4, #0xc]
	b _0211F514
_0211F4BC:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldr r0, [r4, #0x214]
	add r0, r0, #0x1000
	bne _0211F500
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _0211F514
	ldr r0, [r4, #0x214]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _0211F514
	mvn r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_0211F500:
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	moveq r0, #1
	ldmeqia sp!, {r3, r4, r5, pc}
_0211F514:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN19CStylerStatusScreen6RenderEv
_ZN19CStylerStatusScreen6RenderEv: ; 0x0211F51C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x218]
	bl _ZN17UnkClass_0202A2AC12sub_0202A47CEv
	ldr r0, [r4, #0x220]
	cmp r0, #0
	beq _0211F53C
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	arm_func_end _ZN19CStylerStatusScreen6RenderEv
_0211F53C:
	ldr r0, [r4, #0x224]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}

	arm_func_start _ZN19CStylerStatusScreen5func7Ev
_ZN19CStylerStatusScreen5func7Ev: ; 0x0211F550
	bx lr
	arm_func_end _ZN19CStylerStatusScreen5func7Ev

	arm_func_start _ZN19CStylerStatusScreen5func8Ev
_ZN19CStylerStatusScreen5func8Ev: ; 0x0211F554
	bx lr
	arm_func_end _ZN19CStylerStatusScreen5func8Ev

	arm_func_start ov5_0211F558
ov5_0211F558: ; 0x0211F558
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r2
	str r1, [r5, #4]
	mov r1, r3
	str r4, [r5, #8]
	mov ip, #1
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x14]
	mov r0, r4
	str ip, [sp]
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r5, #0xc]
	ldr r1, [r4, #0x24]
	ldr r0, [sp, #0x18]
	str r1, [r5]
	mov r3, #0
	cmp r0, #1
	mov r1, #0x20
	str r3, [sp]
	bne _0211F5BC
	ldr r0, [r5, #0xc]
	mov r2, #0x40
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov5_0211F558
_0211F5BC:
	ldr r0, [r5, #0xc]
	mov r2, r1
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov5_0211F5CC
ov5_0211F5CC: ; 0x0211F5CC
	ldr ip, _0211F5D8 ; =FUN_0200EB84
	ldr r0, [r0, #0xc]
	bx ip
	.align 2, 0
_0211F5D8: .word _ZN17UnkClass_0200E96012sub_0200EB84Ev
	arm_func_end ov5_0211F5CC

	arm_func_start ov5_0211F5DC
ov5_0211F5DC: ; 0x0211F5DC
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	mov r5, r0
	mov r1, #0
	str r4, [r5, #0x14]
	mov r0, r4
	mov r2, r1
	mov r3, r1
	str r1, [sp]
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r5, #0x18]
	ldr r0, [r4, #0x24]
	mov r2, #0
	str r0, [r5, #4]
	mov r0, r4
	mov r3, r2
	str r2, [sp]
	mov r1, #3
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r5, #0x1c]
	ldr r0, [r4, #0x24]
	mov r1, #0
	str r0, [r5, #8]
	ldr r0, [r5, #0x18]
	str r1, [r0, #0x14]
	ldr r0, [r5, #0x1c]
	str r1, [r0, #0x14]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov5_0211F5DC

	arm_func_start ov5_0211F64C
ov5_0211F64C: ; 0x0211F64C
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r3, [r4]
	cmp r3, #0
	beq _0211F66C
	cmp r3, #1
	beq _0211F6A0
	b _0211F6D0
	arm_func_end ov5_0211F64C
_0211F66C:
	ldr r0, [r4, #0x18]
	mov r3, #1
	str r3, [r0, #0x14]
	ldr r0, [r4, #0x1c]
	mov r3, #0
	str r3, [r0, #0x14]
	ldr r0, [r4, #0x18]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #4]
	mov r2, #0
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	b _0211F6D0
_0211F6A0:
	ldr r0, [r4, #0x1c]
	mov r3, #1
	str r3, [r0, #0x14]
	ldr r0, [r4, #0x18]
	mov r3, #0
	str r3, [r0, #0x14]
	ldr r0, [r4, #0x1c]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #8]
	mov r2, #3
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
_0211F6D0:
	mov r0, #0
	str r0, [r4, #0x10]
	str r0, [r4, #0xc]
	ldmia sp!, {r4, pc}

	arm_func_start ov5_0211F6E0
ov5_0211F6E0: ; 0x0211F6E0
	stmdb sp!, {lr}
	sub sp, sp, #0xc
	mov r3, r0
	ldr r1, [r3]
	mvn r0, #0
	cmp r1, r0
	addeq sp, sp, #0xc
	ldmeqia sp!, {pc}
	ldr r0, _0211F774 ; =DAT_overlay_5_021203ec
	add ip, sp, #0
	ldmia r0, {r0, r1, r2}
	stmia ip, {r0, r1, r2}
	ldr r0, [r3, #0xc]
	add r1, r0, #1
	str r1, [r3, #0xc]
	ldr r0, [r3, #0x10]
	ldr r0, [ip, r0, lsl #2]
	cmp r1, r0
	addne sp, sp, #0xc
	ldmneia sp!, {pc}
	mov r1, #0
	str r1, [r3, #0xc]
	ldr r0, [r3, #0x10]
	add r0, r0, #1
	str r0, [r3, #0x10]
	cmp r0, #3
	streq r1, [r3, #0x10]
	ldr r0, [r3]
	ldr ip, [r3, #0x10]
	add r1, r3, r0, lsl #2
	add r2, r0, r0, lsl #1
	ldr r0, [r3, #0x14]
	ldr r1, [r1, #4]
	add r2, ip, r2
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	add sp, sp, #0xc
	ldmia sp!, {pc}
	.align 2, 0
_0211F774: .word DAT_overlay_5_021203ec
	arm_func_end ov5_0211F6E0

	arm_func_start _ZN18CStylerPartsScreenC1EP5CGameP11CStylerData
_ZN18CStylerPartsScreenC1EP5CGameP11CStylerData: ; 0x0211F778
	stmdb sp!, {r4, lr}
	ldr r3, _0211F7DC ; =_ZTV13CStylerScreen+8
	mov r4, r0
	str r3, [r4]
	mov r3, #0
	str r3, [r4, #4]
	ldr r0, _0211F7E0 ; =PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8
	str r3, [r4, #8]
	str r0, [r4]
	str r3, [r4, #0x10]
	str r3, [r4, #0x14]
	str r3, [r4, #0x228]
	str r3, [r4, #0x22c]
	str r1, [r4, #0x21c]
	str r2, [r4, #0x218]
	ldr r0, [r2, #8]
	mov r1, r3
	str r0, [r4, #0x224]
	ldr r3, [r2, #0x10]
	add r0, r4, #0x230
	mov r2, #0xbc
	str r3, [r4, #0x220]
	bl MI_CpuFill8
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0211F7DC: .word _ZTV13CStylerScreen+8
_0211F7E0: .word PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8
	arm_func_end _ZN18CStylerPartsScreenC1EP5CGameP11CStylerData

	arm_func_start ov5_0211F7E4
ov5_0211F7E4: ; 0x0211F7E4
	stmdb sp!, {r4, lr}
	ldr r1, _0211F808 ; =PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0211F808: .word PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8
	arm_func_end ov5_0211F7E4

	arm_func_start ov5_0211F80C
ov5_0211F80C: ; 0x0211F80C
	stmdb sp!, {r4, lr}
	ldr r1, _0211F838 ; =PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0211F838: .word PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8
	arm_func_end ov5_0211F80C

	arm_func_start ov5_0211F83C
ov5_0211F83C: ; 0x0211F83C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov5_0211F978
	mov r0, r4
	bl ov5_0211F9A0
	mov r0, r4
	bl ov5_0211FA2C
	mov r0, r4
	bl ov5_0211FB04
	mov r0, r4
	bl ov5_0211FB6C
	mov r0, r4
	bl ov5_0211FD0C
	ldmia sp!, {r4, pc}
	arm_func_end ov5_0211F83C

	arm_func_start ov5_0211F874
ov5_0211F874: ; 0x0211F874
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r5, [r4, #0x228]
	cmp r5, #0
	beq _0211F8A4
	beq _0211F89C
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov5_0211F874
_0211F89C:
	mov r0, #0
	str r0, [r4, #0x228]
_0211F8A4:
	ldr r5, [r4, #0x22c]
	cmp r5, #0
	beq _0211F8CC
	beq _0211F8C4
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_0211F8C4:
	mov r0, #0
	str r0, [r4, #0x22c]
_0211F8CC:
	mov r6, #0
	mov r5, r6
_0211F8D4:
	add r0, r4, r6, lsl #2
	ldr r0, [r0, #0x230]
	cmp r0, #0
	beq _0211F8F4
	beq _0211F8EC
	bl _ZdlPv
_0211F8EC:
	add r0, r4, r6, lsl #2
	str r5, [r0, #0x230]
_0211F8F4:
	add r6, r6, #1
	cmp r6, #0x2f
	blt _0211F8D4
	ldr r0, [r4, #0x2ec]
	cmp r0, #0
	beq _0211F91C
	beq _0211F914
	bl _ZdlPv
_0211F914:
	mov r0, #0
	str r0, [r4, #0x2ec]
_0211F91C:
	ldr r0, [r4, #0x21c]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	ldr r0, [r4, #0x21c]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov5_0211F948
ov5_0211F948: ; 0x0211F948
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	str r1, [r4, #4]
	str r1, [r4, #8]
	bl ov5_0211F9A0
	ldr r1, _0211F974 ; =0x05000200
	add r0, r4, #0x18
	mov r2, #0x1e0
	bl MIi_CpuCopyFast
	ldmia sp!, {r4, pc}
	.align 2, 0
_0211F974: .word 0x05000200
	arm_func_end ov5_0211F948

	arm_func_start ov5_0211F978
ov5_0211F978: ; 0x0211F978
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x218]
	ldr r1, [r1]
	str r1, [r4, #0xc]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	bl ov5_02120248
	str r0, [r4, #0x10]
	ldmia sp!, {r4, pc}
	arm_func_end ov5_0211F978

	arm_func_start ov5_0211F9A0
ov5_0211F9A0: ; 0x0211F9A0
	mov r0, #0x4000000
	ldr r2, [r0]
	ldr r1, _0211FA28 ; =0x00001210
	bic r2, r2, #0x1f00
	orr r2, r2, #0x1b00
	str r2, [r0]
	ldrh r3, [r0, #8]
	add r1, r1, #0x3f4
	mov r2, #0
	and r3, r3, #0x43
	orr r3, r3, #0x210
	orr r3, r3, #0x1000
	strh r3, [r0, #8]
	ldrh r3, [r0, #0xe]
	and r3, r3, #0x43
	orr r1, r3, r1
	strh r1, [r0, #0xe]
	ldrh r1, [r0, #0xa]
	bic r1, r1, #3
	strh r1, [r0, #0xa]
	ldrh r1, [r0, #8]
	bic r1, r1, #3
	orr r1, r1, #1
	strh r1, [r0, #8]
	ldrh r1, [r0, #0xc]
	bic r1, r1, #3
	orr r1, r1, #2
	strh r1, [r0, #0xc]
	ldrh r1, [r0, #0xe]
	bic r1, r1, #3
	orr r1, r1, #3
	strh r1, [r0, #0xe]
	strh r2, [r0, #0x50]
	bx lr
	.align 2, 0
_0211FA28: .word 0x00001210
	arm_func_end ov5_0211F9A0

	arm_func_start ov5_0211FA2C
ov5_0211FA2C: ; 0x0211FA2C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r0, #0x44
	mov r4, #0
	bl _Znwm
	cmp r0, #0
	beq _0211FA68
	ldr r3, [r5, #0x21c]
	mov r1, #0x40
	str r1, [sp]
	add r1, r3, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r3, #0x64
	mov r3, r4
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end ov5_0211FA2C
_0211FA68:
	str r0, [r5, #0x228]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #0x228]
	ldr r1, _0211FAF4 ; =s_data_menu_overlay_5_02120d34
	ldr r2, _0211FAF8 ; =s_stl001_00_overlay_5_02120d40
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r4, r4, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _0211FAB8
	ldr r3, [r5, #0x21c]
	mov r1, #0x40
	str r1, [sp]
	add r1, r3, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r3, #0x34
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0211FAB8:
	str r0, [r5, #0x22c]
	mov r0, #0xe
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [r5, #0x22c]
	ldr r1, _0211FAF4 ; =s_data_menu_overlay_5_02120d34
	ldr r2, _0211FAFC ; =s_stl002_00_overlay_5_02120d4c
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r0, _0211FB00 ; =0x05000200
	add r1, r5, #0x18
	mov r2, #0x1e0
	bl MIi_CpuCopyFast
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0211FAF4: .word s_data_menu_overlay_5_02120d34
_0211FAF8: .word s_stl001_00_overlay_5_02120d40
_0211FAFC: .word s_stl002_00_overlay_5_02120d4c
_0211FB00: .word 0x05000200

	arm_func_start ov5_0211FB04
ov5_0211FB04: ; 0x0211FB04
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x10
	mov ip, #0
	ldr r3, _0211FB5C ; =s_stl001_overlay_5_02120d6c
	str ip, [sp]
	ldr r0, _0211FB60 ; =s_menu_overlay_5_02120d58
	ldr r1, _0211FB64 ; =s_stl001_bg_overlay_5_02120d60
	mov r2, #3
	stmib sp, {r3, ip}
	bl _Z19BGS_LoadCharAndPlttPKcS0_iS0_mS0_m
	mov ip, #0
	str ip, [sp]
	str ip, [sp, #4]
	str ip, [sp, #8]
	ldr r0, _0211FB60 ; =s_menu_overlay_5_02120d58
	ldr r1, _0211FB64 ; =s_stl001_bg_overlay_5_02120d60
	ldr r3, _0211FB68 ; =s_stl001_00_overlay_5_02120d40
	mov r2, #3
	str ip, [sp, #0xc]
	bl _Z11BGS_LoadScrPKcS0_iS0_mmim
	add sp, sp, #0x10
	ldmia sp!, {r3, pc}
	.align 2, 0
_0211FB5C: .word s_stl001_overlay_5_02120d6c
_0211FB60: .word s_menu_overlay_5_02120d58
_0211FB64: .word s_stl001_bg_overlay_5_02120d60
_0211FB68: .word s_stl001_00_overlay_5_02120d40
	arm_func_end ov5_0211FB04

	arm_func_start ov5_0211FB6C
ov5_0211FB6C: ; 0x0211FB6C
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x14
	mov r5, r0
	ldr r0, [r5, #0x21c]
	add r0, r0, #0x1000
	ldr r4, [r0, #0x494]
	mov r0, r4
	bl _ZN17UnkClass_0200C38C12sub_0200C3D0Ev
	mov r0, r4
	mov r1, #0
	mov r2, #0x12
	mov r3, #4
	bl _ZN17UnkClass_0200C38C12sub_0200C408Ei11GXBGScrBase12GXBGCharBase
	mov r0, r4
	mov r1, #1
	bl _ZN17UnkClass_0200C38C12sub_0200C680Ei
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	mov r0, r4
	mov r2, #0x14
	mov r3, #3
	bl _ZN17UnkClass_0200C38C12sub_0200C6C8Eiiiiiiii
	ldr r0, [r5, #0x224]
	ldr r0, [r0, #8]
	ldr r1, [r0, #0x204]
	cmp r1, #0
	beq _0211FC14
	mov r0, #3
	stmia sp, {r0, r1}
	mov r1, #0
	str r1, [sp, #8]
	mov r0, r4
	mov r2, #4
	mov r3, #6
	str r1, [sp, #0xc]
	bl _ZN17UnkClass_0200C38C12sub_0200C7A4EiiiiPhii
	arm_func_end ov5_0211FB6C
_0211FC14:
	ldr r0, [r5, #0x21c]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	ldr r0, [r5, #0x21c]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA04El
	ldr r0, [r5, #0xc]
	mov r2, #1
	cmp r0, #0
	mov r0, #0
	str r0, [sp]
	bne _0211FC74
	ldr r0, [r5, #0x21c]
	mov r3, r2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r1, #0x18
	bl _ZN17UnkClass_020091E812sub_0200AD34Emmmm
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, pc}
_0211FC74:
	ldr r0, [r5, #0x21c]
	ldr r1, _0211FC94 ; =OVERLAY5_BSS_02120D80
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r3, r2
	bl _ZN17UnkClass_020091E812sub_02009D8CEPhmmm
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_0211FC94: .word OVERLAY5_BSS_02120D80

	arm_func_start ov5_0211FC98
ov5_0211FC98: ; 0x0211FC98
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	mov r7, r0
	mov r0, #0x10
	mov r6, r1
	mov r5, r2
	bl _Znwm
	movs r4, r0
	beq _0211FCCC
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	arm_func_end ov5_0211FC98
_0211FCCC:
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #4]
	cmp r0, #0x19
	str r1, [sp]
	moveq r3, #1
	ldr r2, [r5, #8]
	movne r3, #0
	stmib sp, {r2, r3}
	ldr r2, [r7, #0x228]
	ldr r3, [r5]
	mov r0, r4
	mov r1, r6
	bl ov5_0211F558
	mov r0, r4
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}

	arm_func_start ov5_0211FD0C
ov5_0211FD0C: ; 0x0211FD0C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r6, #0x2f
	mov r7, #0x30
	ldr sb, _0211FE30 ; =DAT_overlay_5_021208cc
	mov sl, r0
	mov r8, #0
	mov fp, r6
	mov r5, r7
	mov r4, #1
	arm_func_end ov5_0211FD0C
_0211FD30:
	ldr r2, [sl, #0x218]
	ldr r1, [sb, #0x10]
	ldr r0, [sb, #0x14]
	add r1, r2, r1, lsl #2
	ldr r1, [r1, #0x14]
	cmp r1, r0
	blt _0211FDA8
	mov r0, sl
	mov r1, r8
	mov r2, sb
	bl ov5_0211FC98
	add r1, sl, r8, lsl #2
	str r0, [r1, #0x230]
	ldr r0, [sl, #0xc]
	cmp r0, #0
	beq _0211FDC8
	ldr r0, [sl, #0x10]
	cmp sb, r0
	bne _0211FDC8
	ldr r0, [r1, #0x230]
	str r0, [sl, #0x14]
	ldr r0, [sb, #0xc]
	ldr r1, [sl, #0x14]
	cmp r0, #0x19
	moveq r2, r7
	ldr r0, [r1, #8]
	ldr r1, [r1]
	movne r2, r6
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	b _0211FDC8
_0211FDA8:
	ldr r0, [sb, #0xc]
	str r4, [sp]
	cmp r0, #0x19
	moveq r1, r5
	ldr r0, [sl, #0x228]
	movne r1, fp
	ldmib sb, {r2, r3}
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_0211FDC8:
	add r8, r8, #1
	cmp r8, #0x2f
	add sb, sb, #0x18
	blt _0211FD30
	mov r0, #0x20
	bl _Znwm
	movs r4, r0
	beq _0211FE1C
	mvn r0, #0
	str r0, [r4]
	mov r1, #0
	str r1, [r4, #0xc]
	str r1, [r4, #0x10]
	add r0, r4, #0x18
	mov r2, #8
	str r1, [r4, #0x14]
	bl MI_CpuFill8
	add r0, r4, #4
	mov r1, #0
	mov r2, #8
	bl MI_CpuFill8
_0211FE1C:
	str r4, [sl, #0x2ec]
	ldr r1, [sl, #0x22c]
	mov r0, r4
	bl ov5_0211F5DC
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0211FE30: .word DAT_overlay_5_021208cc

	arm_func_start ov5_0211FE34
ov5_0211FE34: ; 0x0211FE34
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0211FEB0
	ldr r0, [r4, #8]
	cmp r0, #0x258
	bne _0211FEB0
	ldr r0, [r4, #0x21c]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200A088Em
	ldr r0, [r4, #0x21c]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA04El
	mov r0, #0
	str r0, [sp]
	ldr r0, [r4, #0x21c]
	mov r2, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r3, r2
	mov r1, #0x72
	bl _ZN17UnkClass_020091E812sub_0200AD34Emmmm
	arm_func_end ov5_0211FE34
_0211FEB0:
	ldr r0, [r4, #0x2ec]
	bl ov5_0211F6E0
	ldr r0, [r4, #0x228]
	cmp r0, #0
	beq _0211FEC8
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
_0211FEC8:
	ldr r0, [r4, #0x22c]
	cmp r0, #0
	beq _0211FED8
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
_0211FED8:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0211FEF8
	cmp r0, #1
	beq _0211FFFC
	cmp r0, #2
	beq _021200D0
	b _02120130
_0211FEF8:
	ldr r0, [r4, #0x21c]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02120130
	ldr r0, [r4, #0x21c]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02120130
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0211FFF0
	ldr r0, [r4, #8]
	cmp r0, #0x3c
	bne _02120130
	ldr r2, [r4, #0x10]
	ldr r0, [r2, #0xc]
	ldmib r2, {r1, r2}
	cmp r0, #0x19
	moveq r3, #1
	ldr r0, [r4, #0x2ec]
	movne r3, #0
	bl ov5_0211F64C
	ldr r1, [r4, #0x14]
	ldr r2, [r4, #0x10]
	ldr r0, [r1, #8]
	ldr r1, [r1]
	ldr r2, [r2]
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	ldr r0, [r4, #0x21c]
	mov r1, #0xba
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr ip, [r4, #0xc]
	mov r0, #0
	cmp ip, #0x19
	mov r2, #1
	str r0, [sp]
	ble _0211FFCC
	ldr r0, [r4, #0x21c]
	ldr r1, [r4, #0x10]
	add r0, r0, #0x1000
	ldr r1, [r1, #0x14]
	add ip, ip, #0x17
	ldr r0, [r0, #0x490]
	mov r3, r2
	add r1, ip, r1
	bl _ZN17UnkClass_020091E812sub_0200AD34Emmmm
	b _0211FFE4
_0211FFCC:
	ldr r0, [r4, #0x21c]
	mov r3, r2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	add r1, ip, #0x18
	bl _ZN17UnkClass_020091E812sub_0200AD34Emmmm
_0211FFE4:
	mov r0, #1
	str r0, [r4, #4]
	b _02120130
_0211FFF0:
	mov r0, #1
	str r0, [r4, #4]
	b _02120130
_0211FFFC:
	ldr r2, [r4, #0x21c]
	ldr r0, [r4, #0xc]
	ldr r1, [r2, #0x14]
	cmp r0, #0
	ldr r0, [r2, #0x18]
	beq _02120090
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _02120044
	ldrh r1, [r1, #2]
	and r0, r1, #1
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	bne _02120044
	and r0, r1, #2
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	beq _02120130
_02120044:
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	ldr r1, _0212013C ; =0x00000103
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #2
	str r0, [r4, #4]
	ldr r0, [r4, #0x21c]
	mov r1, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x14
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #0x21c]
	mov r1, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x14
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	b _02120130
_02120090:
	ldr r0, [r4, #0x220]
	bl _ZN17UnkClass_0202A2AC12sub_0202A404Ev
	cmp r0, #0
	beq _021200C4
	mov r0, #2
	str r0, [r4, #4]
	ldr r0, [r4, #0x21c]
	mov r1, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x14
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	b _02120130
_021200C4:
	mov r0, r4
	bl ov5_02120140
	b _02120130
_021200D0:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldr r0, [r4, #0x21c]
	add r0, r0, #0x1000
	beq _02120118
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02120130
	ldr r0, [r4, #0x21c]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02120130
	add sp, sp, #4
	mvn r0, #0
	ldmia sp!, {r3, r4, pc}
_02120118:
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #4
	moveq r0, #1
	ldmeqia sp!, {r3, r4, pc}
_02120130:
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0212013C: .word 0x00000103

	arm_func_start ov5_02120140
ov5_02120140: ; 0x02120140
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, #0
	arm_func_end ov5_02120140
_0212014C:
	add r0, r5, r4, lsl #2
	ldr r0, [r0, #0x230]
	cmp r0, #0
	beq _021201EC
	bl ov5_0211F5CC
	cmp r0, #0
	beq _021201EC
	ldr r1, _021201FC ; =DAT_overlay_5_021208cc
	mov r0, #0x18
	mla r1, r4, r0, r1
	ldr r0, [r5, #0x10]
	cmp r0, r1
	ldmeqia sp!, {r3, r4, r5, pc}
	str r1, [r5, #0x10]
	add r0, r5, r4, lsl #2
	ldr r0, [r0, #0x230]
	mov r1, #0xfa
	str r0, [r5, #0x14]
	ldr r0, [r5, #0x21c]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r2, [r5, #0x10]
	ldr r0, [r2, #0xc]
	ldmib r2, {r1, r2}
	cmp r0, #0x19
	moveq r3, #1
	ldr r0, [r5, #0x2ec]
	movne r3, #0
	bl ov5_0211F64C
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5, #0x21c]
	mov r2, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r3, r2
	add r1, r4, #0x77
	bl _ZN17UnkClass_020091E812sub_0200AD34Emmmm
	ldmia sp!, {r3, r4, r5, pc}
_021201EC:
	add r4, r4, #1
	cmp r4, #0x2f
	blt _0212014C
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021201FC: .word DAT_overlay_5_021208cc

	arm_func_start ov5_02120200
ov5_02120200: ; 0x02120200
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _0212021C
	ldr r0, [r4, #0x220]
	bl _ZN17UnkClass_0202A2AC12sub_0202A47CEv
	arm_func_end ov5_02120200
_0212021C:
	ldr r0, [r4, #0x22c]
	cmp r0, #0
	beq _0212022C
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
_0212022C:
	ldr r0, [r4, #0x228]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}

	arm_func_start ov5_02120240
ov5_02120240: ; 0x02120240
	bx lr
	arm_func_end ov5_02120240

	arm_func_start ov5_02120244
ov5_02120244: ; 0x02120244
	bx lr
	arm_func_end ov5_02120244

	arm_func_start ov5_02120248
ov5_02120248: ; 0x02120248
	stmdb sp!, {r4, lr}
	ldr r4, _0212029C ; =DAT_overlay_5_021208cc
	mov lr, #0
	arm_func_end ov5_02120248
_02120254:
	ldr r2, [r4, #0xc]
	cmp r2, r1
	bne _02120280
	ldr r3, [r0, #0x218]
	ldr r2, [r4, #0x10]
	ldr ip, [r4, #0x14]
	add r2, r3, r2, lsl #2
	ldr r2, [r2, #0x14]
	cmp ip, r2
	moveq r0, r4
	ldmeqia sp!, {r4, pc}
_02120280:
	add lr, lr, #1
	cmp lr, #0x2f
	add r4, r4, #0x18
	blt _02120254
	bl OS_Terminate
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212029C: .word DAT_overlay_5_021208cc
	; 0x021202A0

    .rodata

    .global DAT_overlay_5_021203d8
DAT_overlay_5_021203d8: ; 0x021203D8
	.byte 0x00, 0x10

    .global DAT_overlay_5_021203da
DAT_overlay_5_021203da: ; 0x021203DA
	.byte 0x00, 0x20

    .global DAT_overlay_5_021203dc
DAT_overlay_5_021203dc: ; 0x021203DC
	.byte 0x00, 0x30

    .global DAT_overlay_5_021203de
DAT_overlay_5_021203de: ; 0x021203DE
	.byte 0x00, 0x40

    .global DAT_overlay_5_021203e0
DAT_overlay_5_021203e0: ; 0x021203E0
	.byte 0x41, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021203e4
DAT_overlay_5_021203e4: ; 0x021203E4
	.byte 0x42, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021203e8
DAT_overlay_5_021203e8: ; 0x021203E8
	.byte 0x43, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021203ec
DAT_overlay_5_021203ec: ; 0x021203EC
	.byte 0x14, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021203f0
DAT_overlay_5_021203f0: ; 0x021203F0
	.byte 0x08, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021203f4
DAT_overlay_5_021203f4: ; 0x021203F4
	.byte 0x08, 0x00, 0x00, 0x00

    .section .sinit,4 ; 0x021203F8

    .data

    .global PTR_ptr_FUN_020835bc_overlay_5_021205bc
PTR_ptr_FUN_020835bc_overlay_5_021205bc: ; 0x021205BC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_19CStylerStatusScreen_overlay_5_021205c8
	.word _ZTI13CStylerScreen

    .global s_19CStylerStatusScreen_overlay_5_021205c8
s_19CStylerStatusScreen_overlay_5_021205c8: ; 0x021205C8
	.asciz "19CStylerStatusScreen"

    .global DAT_overlay_5_021205DE
DAT_overlay_5_021205DE:
	.byte 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_5_021205bc

    .global PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8
PTR_LAB_overlay_5_0211eb2c_overlay_5_021205e8: ; 0x021205E8
	.word _ZN19CStylerStatusScreenD1Ev

    .global ptr_FUN_overlay_5_0211eb54_overlay_5_021205ec
ptr_FUN_overlay_5_0211eb54_overlay_5_021205ec: ; 0x021205EC
	.word _ZN19CStylerStatusScreenD0Ev

    .global ptr_FUN_overlay_27_0211eb84_overlay_5_021205f0
ptr_FUN_overlay_27_0211eb84_overlay_5_021205f0: ; 0x021205F0
	.word _ZN19CStylerStatusScreen4LoadEv

    .global ptr_FUN_overlay_5_0211ebb4_overlay_5_021205f4
ptr_FUN_overlay_5_0211ebb4_overlay_5_021205f4: ; 0x021205F4
	.word _ZN19CStylerStatusScreen7ReleaseEv

    .global ptr_FUN_overlay_5_0211ec10_overlay_5_021205f8
ptr_FUN_overlay_5_0211ec10_overlay_5_021205f8: ; 0x021205F8
	.word _ZN19CStylerStatusScreen5ResetEv

    .global ptr_FUN_overlay_5_0211f364_overlay_5_021205fc
ptr_FUN_overlay_5_0211f364_overlay_5_021205fc: ; 0x021205FC
	.word _ZN19CStylerStatusScreen6UpdateEv

    .global ptr_FUN_overlay_5_0211f51c_overlay_5_02120600
ptr_FUN_overlay_5_0211f51c_overlay_5_02120600: ; 0x02120600
	.word _ZN19CStylerStatusScreen6RenderEv
	.word _ZN19CStylerStatusScreen5func7Ev
	.word _ZN19CStylerStatusScreen5func8Ev

    .global DAT_overlay_5_0212060c
DAT_overlay_5_0212060c: ; 0x0212060C
	.byte 0x03, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120610
DAT_overlay_5_02120610: ; 0x02120610
	.byte 0x13, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120618
DAT_overlay_5_02120618: ; 0x02120618
	.byte 0x15, 0x00, 0x00, 0x00

    .global DAT_overlay_5_0212061c
DAT_overlay_5_0212061c: ; 0x0212061C
	.byte 0x11, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120620
DAT_overlay_5_02120620: ; 0x02120620
	.byte 0x12, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120624
DAT_overlay_5_02120624: ; 0x02120624
	.byte 0x13, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120630
DAT_overlay_5_02120630: ; 0x02120630
	.byte 0x12, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00
	.byte 0x18, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00
	.byte 0x17, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00

    .global DAT_overlay_5_0212065c
DAT_overlay_5_0212065c: ; 0x0212065C
	.byte 0x70, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120660
DAT_overlay_5_02120660: ; 0x02120660
	.byte 0xA0, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120664
DAT_overlay_5_02120664: ; 0x02120664
	.byte 0x18, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120668
DAT_overlay_5_02120668: ; 0x02120668
	.byte 0x11, 0x00, 0x00, 0x00

    .global DAT_overlay_5_0212066c
DAT_overlay_5_0212066c: ; 0x0212066C
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00

    .global DAT_overlay_5_0212067c
DAT_overlay_5_0212067c: ; 0x0212067C
	.byte 0x11, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120680
DAT_overlay_5_02120680: ; 0x02120680
	.byte 0x02, 0x00, 0x00, 0x00, 0xE8, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00
	.byte 0x12, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00
	.byte 0x18, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00
	.byte 0xB0, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0xEC, 0x00, 0x00, 0x00, 0xB0, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021206e8
DAT_overlay_5_021206e8: ; 0x021206E8
	.byte 0x03, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021206ec
DAT_overlay_5_021206ec: ; 0x021206EC
	.byte 0x03, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021206f4
DAT_overlay_5_021206f4: ; 0x021206F4
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021206f8
DAT_overlay_5_021206f8: ; 0x021206F8
	.byte 0x0E, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021206fc
DAT_overlay_5_021206fc: ; 0x021206FC
	.byte 0x03, 0x00, 0x00, 0x00

    .global DAT_overlay_5_02120700
DAT_overlay_5_02120700: ; 0x02120700
	.byte 0x05, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_5_0212070c
DAT_overlay_5_0212070c: ; 0x0212070C
	.byte 0x03, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.byte 0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x0D, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
	.byte 0x07, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x12, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x06, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x0B, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00
	.byte 0x0D, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00
	.byte 0x0B, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x12, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00
	.byte 0x10, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x0F, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00
	.byte 0x11, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00

    .global s_data_menu_overlay_5_0212083c
s_data_menu_overlay_5_0212083c: ; 0x0212083C
	.asciz "data/menu"

    .global DAT_overlay_5_02120846
DAT_overlay_5_02120846:
	.byte 0x00, 0x00

    .global s_stl000_00_overlay_5_02120848
s_stl000_00_overlay_5_02120848: ; 0x02120848
	.asciz "stl000_00"

    .global DAT_overlay_5_02120852
DAT_overlay_5_02120852:
	.byte 0x00, 0x00

    .global s_menu_overlay_5_02120854
s_menu_overlay_5_02120854: ; 0x02120854
	.asciz "menu/"

    .global DAT_overlay_5_0212085A
DAT_overlay_5_0212085A:
	.byte 0x00, 0x00

    .global s_stl000_bg_overlay_5_0212085c
s_stl000_bg_overlay_5_0212085c: ; 0x0212085C
	.asciz "stl000_bg_"

    .global DAT_overlay_5_02120867
DAT_overlay_5_02120867:
	.byte 0x00

    .global s_stl000_overlay_5_02120868
s_stl000_overlay_5_02120868: ; 0x02120868
	.asciz "stl000"

    .global DAT_overlay_5_0212086F
DAT_overlay_5_0212086F:
	.byte 0x00

    .global s_stl000_01_overlay_5_02120870
s_stl000_01_overlay_5_02120870: ; 0x02120870
	.asciz "stl000_01"

    .global DAT_overlay_5_0212087A
DAT_overlay_5_0212087A:
	.byte 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_5_0212087c
PTR_ptr_FUN_020835bc_overlay_5_0212087c: ; 0x0212087C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_18CStylerPartsScreen_overlay_5_02120888
	.word _ZTI13CStylerScreen

    .global s_18CStylerPartsScreen_overlay_5_02120888
s_18CStylerPartsScreen_overlay_5_02120888: ; 0x02120888
	.asciz "18CStylerPartsScreen"

    .global DAT_overlay_5_0212089D
DAT_overlay_5_0212089D:
	.byte 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_5_0212087c

    .global PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8
PTR_LAB_overlay_5_0211f7e4_overlay_5_021208a8: ; 0x021208A8
	.word ov5_0211F7E4

    .global ptr_FUN_overlay_5_0211f80c_overlay_5_021208ac
ptr_FUN_overlay_5_0211f80c_overlay_5_021208ac: ; 0x021208AC
	.word ov5_0211F80C

    .global ptr_FUN_overlay_5_0211f83c_overlay_5_021208b0
ptr_FUN_overlay_5_0211f83c_overlay_5_021208b0: ; 0x021208B0
	.word ov5_0211F83C

    .global ptr_FUN_overlay_5_0211f874_overlay_5_021208b4
ptr_FUN_overlay_5_0211f874_overlay_5_021208b4: ; 0x021208B4
	.word ov5_0211F874

    .global ptr_FUN_overlay_5_0211f948_overlay_5_021208b8
ptr_FUN_overlay_5_0211f948_overlay_5_021208b8: ; 0x021208B8
	.word ov5_0211F948

    .global ptr_FUN_overlay_5_0211fe34_overlay_5_021208bc
ptr_FUN_overlay_5_0211fe34_overlay_5_021208bc: ; 0x021208BC
	.word ov5_0211FE34

    .global ptr_FUN_overlay_5_02120200_overlay_5_021208c0
ptr_FUN_overlay_5_02120200_overlay_5_021208c0: ; 0x021208C0
	.word ov5_02120200
	.word ov5_02120240
	.word ov5_02120244

    .global DAT_overlay_5_021208cc
DAT_overlay_5_021208cc: ; 0x021208CC
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208d0
DAT_overlay_5_021208d0: ; 0x021208D0
	.byte 0x13, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208d4
DAT_overlay_5_021208d4: ; 0x021208D4
	.byte 0x23, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208d8
DAT_overlay_5_021208d8: ; 0x021208D8
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208dc
DAT_overlay_5_021208dc: ; 0x021208DC
	.byte 0x0E, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208e0
DAT_overlay_5_021208e0: ; 0x021208E0
	.byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208f0
DAT_overlay_5_021208f0: ; 0x021208F0
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208f4
DAT_overlay_5_021208f4: ; 0x021208F4
	.byte 0x0E, 0x00, 0x00, 0x00

    .global DAT_overlay_5_021208f8
DAT_overlay_5_021208f8: ; 0x021208F8
	.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x43, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x5B, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00
	.byte 0x07, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x73, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x8B, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0xA3, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x43, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x5B, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00
	.byte 0x10, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x73, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x8B, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00
	.byte 0xA3, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00
	.byte 0x0C, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00
	.byte 0x0A, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00
	.byte 0x43, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x5B, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00
	.byte 0x06, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x73, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x8B, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00
	.byte 0x0E, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00
	.byte 0xA3, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00
	.byte 0x05, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00
	.byte 0x43, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x5B, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00
	.byte 0x0D, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x73, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x1D, 0x00, 0x00, 0x00, 0x8B, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00
	.byte 0x11, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00
	.byte 0xA3, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00
	.byte 0x0F, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00
	.byte 0x0B, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00
	.byte 0x43, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x5B, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00
	.byte 0x1E, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00
	.byte 0x73, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x8B, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00
	.byte 0x21, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00
	.byte 0xA3, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00
	.byte 0x25, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00
	.byte 0xD3, 0x00, 0x00, 0x00, 0x83, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0xD3, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00
	.byte 0x1A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00
	.byte 0xEB, 0x00, 0x00, 0x00, 0x3B, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00, 0xD3, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00
	.byte 0x27, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00
	.byte 0xEB, 0x00, 0x00, 0x00, 0x53, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 0xD3, 0x00, 0x00, 0x00, 0x6B, 0x00, 0x00, 0x00
	.byte 0x2A, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00
	.byte 0xEB, 0x00, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00

    .global s_data_menu_overlay_5_02120d34
s_data_menu_overlay_5_02120d34: ; 0x02120D34
	.asciz "data/menu"

    .global DAT_overlay_5_02120D3E
DAT_overlay_5_02120D3E:
	.byte 0x00, 0x00

    .global s_stl001_00_overlay_5_02120d40
s_stl001_00_overlay_5_02120d40: ; 0x02120D40
	.asciz "stl001_00"

    .global DAT_overlay_5_02120D4A
DAT_overlay_5_02120D4A:
	.byte 0x00, 0x00

    .global s_stl002_00_overlay_5_02120d4c
s_stl002_00_overlay_5_02120d4c: ; 0x02120D4C
	.asciz "stl002_00"

    .global DAT_overlay_5_02120D56
DAT_overlay_5_02120D56:
	.byte 0x00, 0x00

    .global s_menu_overlay_5_02120d58
s_menu_overlay_5_02120d58: ; 0x02120D58
	.asciz "menu/"

    .global DAT_overlay_5_02120D5E
DAT_overlay_5_02120D5E:
	.byte 0x00, 0x00

    .global s_stl001_bg_overlay_5_02120d60
s_stl001_bg_overlay_5_02120d60: ; 0x02120D60
	.asciz "stl001_bg_"

    .global DAT_overlay_5_02120D6B
DAT_overlay_5_02120D6B:
	.byte 0x00

    .global s_stl001_overlay_5_02120d6c
s_stl001_overlay_5_02120d6c: ; 0x02120D6C
	.asciz "stl001"
	; 0x02120D73

    .bss

    .global OVERLAY5_BSS_02120D80
OVERLAY5_BSS_02120D80: ; 0x02120D80
    .space 0x20
