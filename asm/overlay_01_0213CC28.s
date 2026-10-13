    .include "macros.inc"
    .include "include/overlay_01_0213CC28.inc"

    .text

	arm_func_start _ZN17UnkClass_0213CC28C1EP5CGame
_ZN17UnkClass_0213CC28C1EP5CGame: ; 0x0213CC28
	stmdb sp!, {r4, lr}
	ldr r2, _0213CD28 ; =OVERLAY1_BSS_02142200
	mov r4, r0
	str r4, [r2]
	str r1, [r4]
	mov r0, #0x12
	str r0, [r4, #4]
	str r0, [r4, #8]
	mov r2, #0
	strb r2, [r4, #0xc]
	strb r2, [r4, #0xd]
	strb r2, [r4, #0xe]
	strb r2, [r4, #0xf]
	strh r2, [r4, #0x2c]
	strh r2, [r4, #0x2e]
	strb r2, [r4, #0x90]
	str r2, [r4, #0x9c]
	strh r2, [r4, #0x28]
	strh r2, [r4, #0x2a]
	mov r0, #0xdc
	strh r0, [r4, #0x20]
	strh r2, [r4, #0x22]
	strh r2, [r4, #0x24]
	strh r2, [r4, #0x26]
	mov r1, #0x12
	arm_func_end _ZN17UnkClass_0213CC28C1EP5CGame
_0213CC8C:
	add r0, r4, r2
	add r2, r2, #1
	strb r1, [r0, #0x91]
	cmp r2, #8
	blt _0213CC8C
	mov r1, #0
	str r1, [r4, #0x154]
	str r1, [r4, #0x164]
	str r1, [r4, #0x168]
	str r1, [r4, #0x158]
	str r1, [r4, #0x15c]
	strb r1, [r4, #0xd8]
	mov r0, #1
	strb r0, [r4, #0xd9]
	strb r1, [r4, #0xda]
	mov r0, r4
	str r1, [r4, #0x150]
	bl ov1_0213DE88
	mov r0, r4
	bl ov1_0213D018
	mov r0, r4
	bl ov1_0213DF20
	mov r0, r4
	bl ov1_0213E29C
	mov r0, r4
	mov r1, #1
	bl ov1_0213E7C4
	mov r0, r4
	mov r1, #0
	bl _ZN17UnkClass_0213CC2812ov1_0213EF14Ei
	mov r2, #0
	mov r1, r2
_0213CD0C:
	add r0, r4, r2, lsl #2
	add r2, r2, #1
	str r1, [r0, #0x70]
	cmp r2, #8
	blt _0213CD0C
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213CD28: .word OVERLAY1_BSS_02142200

	arm_func_start _ZN17UnkClass_0213CC28D1Ev
_ZN17UnkClass_0213CC28D1Ev: ; 0x0213CD2C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213CD40
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213CC28D1Ev

	arm_func_start ov1_0213CD40
ov1_0213CD40: ; 0x0213CD40
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	ldr r4, [r5, #0x164]
	cmp r4, #0
	beq _0213CD70
	beq _0213CD68
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end ov1_0213CD40
_0213CD68:
	mov r0, #0
	str r0, [r5, #0x164]
_0213CD70:
	ldr r4, [r5, #0x168]
	cmp r4, #0
	beq _0213CD98
	beq _0213CD90
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213CD90:
	mov r0, #0
	str r0, [r5, #0x168]
_0213CD98:
	ldr r0, [r5, #0x150]
	cmp r0, #0
	beq _0213CDBC
	beq _0213CDB4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213CDB4:
	mov r0, #0
	str r0, [r5, #0x150]
_0213CDBC:
	ldr r4, [r5, #0x154]
	cmp r4, #0
	beq _0213CDE4
	beq _0213CDDC
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213CDDC:
	mov r0, #0
	str r0, [r5, #0x154]
_0213CDE4:
	ldr r4, [r5, #0x158]
	cmp r4, #0
	beq _0213CE0C
	beq _0213CE04
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213CE04:
	mov r0, #0
	str r0, [r5, #0x158]
_0213CE0C:
	ldr r4, [r5, #0x15c]
	cmp r4, #0
	beq _0213CE34
	beq _0213CE2C
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213CE2C:
	mov r0, #0
	str r0, [r5, #0x15c]
_0213CE34:
	ldr r4, [r5, #0x160]
	cmp r4, #0
	beq _0213CE5C
	beq _0213CE54
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213CE54:
	mov r0, #0
	str r0, [r5, #0x160]
_0213CE5C:
	ldr r1, [r5, #0x16c]
	cmp r1, #0
	beq _0213CEEC
	ldr r0, [r1, #4]
	mov r4, #0
	cmp r0, #0
	bls _0213CEB8
	mov r6, r4
_0213CE7C:
	ldr r0, [r1, #8]
	add r0, r0, r4, lsl #3
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0213CEA4
	bl _ZdaPv
	ldr r0, [r5, #0x16c]
	ldr r0, [r0, #8]
	add r0, r0, r4, lsl #3
	str r6, [r0, #4]
_0213CEA4:
	ldr r1, [r5, #0x16c]
	add r4, r4, #1
	ldr r0, [r1, #4]
	cmp r4, r0
	blo _0213CE7C
_0213CEB8:
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _0213CED4
	bl _ZdaPv
	ldr r0, [r5, #0x16c]
	mov r1, #0
	str r1, [r0, #8]
_0213CED4:
	ldr r0, [r5, #0x16c]
	cmp r0, #0
	beq _0213CEEC
	bl _ZdlPv
	mov r0, #0
	str r0, [r5, #0x16c]
_0213CEEC:
	ldr r1, [r5, #0x170]
	cmp r1, #0
	beq _0213CF7C
	ldr r0, [r1, #4]
	mov r4, #0
	cmp r0, #0
	bls _0213CF48
	mov r6, r4
_0213CF0C:
	ldr r0, [r1, #8]
	add r0, r0, r4, lsl #3
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0213CF34
	bl _ZdaPv
	ldr r0, [r5, #0x170]
	ldr r0, [r0, #8]
	add r0, r0, r4, lsl #3
	str r6, [r0, #4]
_0213CF34:
	ldr r1, [r5, #0x170]
	add r4, r4, #1
	ldr r0, [r1, #4]
	cmp r4, r0
	blo _0213CF0C
_0213CF48:
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _0213CF64
	bl _ZdaPv
	ldr r0, [r5, #0x170]
	mov r1, #0
	str r1, [r0, #8]
_0213CF64:
	ldr r0, [r5, #0x170]
	cmp r0, #0
	beq _0213CF7C
	bl _ZdlPv
	mov r0, #0
	str r0, [r5, #0x170]
_0213CF7C:
	ldr r1, [r5, #0x174]
	cmp r1, #0
	beq _0213D00C
	ldr r0, [r1, #4]
	mov r4, #0
	cmp r0, #0
	bls _0213CFD8
	mov r6, r4
_0213CF9C:
	ldr r0, [r1, #8]
	add r0, r0, r4, lsl #3
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0213CFC4
	bl _ZdaPv
	ldr r0, [r5, #0x174]
	ldr r0, [r0, #8]
	add r0, r0, r4, lsl #3
	str r6, [r0, #4]
_0213CFC4:
	ldr r1, [r5, #0x174]
	add r4, r4, #1
	ldr r0, [r1, #4]
	cmp r4, r0
	blo _0213CF9C
_0213CFD8:
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _0213CFF4
	bl _ZdaPv
	ldr r0, [r5, #0x174]
	mov r1, #0
	str r1, [r0, #8]
_0213CFF4:
	ldr r0, [r5, #0x174]
	cmp r0, #0
	beq _0213D00C
	bl _ZdlPv
	mov r0, #0
	str r0, [r5, #0x174]
_0213D00C:
	mov r0, #0
	bl GXS_SetGraphicsMode
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov1_0213D018
ov1_0213D018: ; 0x0213D018
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	ldr r0, [r0, #0xc24]
	bl _ZN17UnkClass_020023EC12sub_020027E8Ev
	ldr r0, [r4]
	ldr r0, [r0, #0xc28]
	bl _ZN17UnkClass_020023EC12sub_020027E8Ev
	mov r0, r4
	mov r1, #0x12
	bl ov1_0213D058
	mov r0, r4
	bl ov1_0213DA14
	mov r0, r4
	bl ov1_0213D614
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213D018

	arm_func_start ov1_0213D058
ov1_0213D058: ; 0x0213D058
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x70
	mov r4, r0
	mov r0, #0x6c
	mov r7, r1
	bl _Znwm
	movs r5, r0
	beq _0213D0A0
	mov r3, #1
	str r3, [sp]
	mov r5, #0
	str r5, [sp, #4]
	str r5, [sp, #8]
	ldr r1, _0213D32C ; =s_BGU_overlay_1_02141f74
	ldr r2, _0213D330 ; =s_data_menu_pam001_bg_LZ_bin_overlay_1_02141f78
	str r5, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r5, r0
	arm_func_end ov1_0213D058
_0213D0A0:
	mov r0, #0xbc
	bl _Znwm
	movs r6, r0
	beq _0213D0C8
	ldr r1, _0213D334 ; =s_BGU_pam001_NCGR_overlay_1_02141f94
	mov r3, #0
	mov r2, #1
	str r3, [sp]
	bl _ZN11CBGNCGRFileC1EPKcmmm
	mov r6, r0
_0213D0C8:
	ldr r1, _0213D338 ; =s_BGU_pam_03d_NCLR_overlay_1_02141fa4
	add r0, sp, #0x10
	mov r2, r7
	bl OS_SPrintf
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _0213D0FC
	mov r3, #0
	add r1, sp, #0x10
	mov r2, #1
	str r3, [sp]
	bl _ZN9CNCLRFileC1EPKcmmm
_0213D0FC:
	str r0, [r4, #0x150]
	mov r0, #0xbc
	bl _Znwm
	movs r7, r0
	beq _0213D128
	ldr r1, _0213D33C ; =s_BGU_pam001_00_NSCR_overlay_1_02141fb8
	mov r3, #0
	mov r2, #1
	str r3, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r7, r0
_0213D128:
	ldr r8, _0213D340 ; =0x0400100E
	mov r2, #0
	ldrh r3, [r8]
	mov r1, #0xf
	mov r0, #7
	and r3, r3, #0x43
	orr r3, r3, #0x4000
	strh r3, [r8]
	str r2, [sp]
	str r2, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	ldr r3, [r4, #0x150]
	ldr r1, [r7, #0xb8]
	ldr r2, [r6, #0xb8]
	ldr r3, [r3, #0xb8]
	bl NNS_G2dBGSetupEx
	cmp r7, #0
	beq _0213D184
	mov r0, r7
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213D184:
	cmp r6, #0
	beq _0213D19C
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213D19C:
	cmp r5, #0
	beq _0213D1B4
	mov r0, r5
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r5
	bl _ZdlPv
_0213D1B4:
	mov r0, #0x6c
	bl _Znwm
	movs r5, r0
	beq _0213D1EC
	mov r3, #1
	str r3, [sp]
	mov r5, #0
	str r5, [sp, #4]
	str r5, [sp, #8]
	ldr r1, _0213D32C ; =s_BGU_overlay_1_02141f74
	ldr r2, _0213D344 ; =s_data_menu_pam000_bg_LZ_bin_overlay_1_02141fcc
	str r5, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r5, r0
_0213D1EC:
	mov r0, #0xbc
	bl _Znwm
	movs r6, r0
	beq _0213D214
	ldr r1, _0213D348 ; =s_BGU_pam000_NCGR_overlay_1_02141fe8
	mov r3, #0
	mov r2, #1
	str r3, [sp]
	bl _ZN11CBGNCGRFileC1EPKcmmm
	mov r6, r0
_0213D214:
	mov r0, #0xbc
	bl _Znwm
	movs r7, r0
	beq _0213D23C
	ldr r1, _0213D34C ; =s_BGU_pam000_01_NSCR_overlay_1_02141ff8
	mov r3, #0
	mov r2, #1
	str r3, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r7, r0
_0213D23C:
	mov r0, #0xbc
	bl _Znwm
	movs r8, r0
	beq _0213D264
	ldr r1, _0213D350 ; =s_BGU_pam000_02_NSCR_overlay_1_0214200c
	mov r3, #0
	mov r2, #1
	str r3, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r8, r0
_0213D264:
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #0xd
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	ldr r1, [r7, #0xb8]
	ldr r2, [r6, #0xb8]
	mov r0, #5
	bl NNS_G2dBGSetupEx
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r0, #0xe
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	ldr r1, [r8, #0xb8]
	mov r3, r2
	mov r0, #6
	bl NNS_G2dBGSetupEx
	cmp r7, #0
	beq _0213D2D4
	mov r0, r7
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213D2D4:
	cmp r8, #0
	beq _0213D2EC
	mov r0, r8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213D2EC:
	cmp r6, #0
	beq _0213D304
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213D304:
	cmp r5, #0
	beq _0213D31C
	mov r0, r5
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r5
	bl _ZdlPv
_0213D31C:
	mov r0, r4
	bl ov1_0213E4CC
	add sp, sp, #0x70
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0213D32C: .word s_BGU_overlay_1_02141f74
_0213D330: .word s_data_menu_pam001_bg_LZ_bin_overlay_1_02141f78
_0213D334: .word s_BGU_pam001_NCGR_overlay_1_02141f94
_0213D338: .word s_BGU_pam_03d_NCLR_overlay_1_02141fa4
_0213D33C: .word s_BGU_pam001_00_NSCR_overlay_1_02141fb8
_0213D340: .word 0x0400100E
_0213D344: .word s_data_menu_pam000_bg_LZ_bin_overlay_1_02141fcc
_0213D348: .word s_BGU_pam000_NCGR_overlay_1_02141fe8
_0213D34C: .word s_BGU_pam000_01_NSCR_overlay_1_02141ff8
_0213D350: .word s_BGU_pam000_02_NSCR_overlay_1_0214200c

	arm_func_start ov1_0213D354
ov1_0213D354: ; 0x0213D354
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x70
	mov r4, r0
	ldr r0, [r4, #0x150]
	mov r6, r1
	cmp r0, #0
	beq _0213D388
	beq _0213D380
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end ov1_0213D354
_0213D380:
	mov r0, #0
	str r0, [r4, #0x150]
_0213D388:
	mov r1, #0
	mov r0, #0x6c
	str r1, [r4, #0x150]
	bl _Znwm
	movs r5, r0
	beq _0213D3C8
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	str ip, [sp, #8]
	ldr r1, _0213D44C ; =s_BGU_overlay_1_02141f74
	ldr r2, _0213D450 ; =s_data_menu_pam000_bg_LZ_bin_overlay_1_02141fcc
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r5, r0
_0213D3C8:
	ldr r1, _0213D454 ; =s_BGU_pam_03d_NCLR_overlay_1_02141fa4
	add r0, sp, #0x10
	mov r2, r6
	bl OS_SPrintf
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _0213D3FC
	mov r3, #0
	add r1, sp, #0x10
	mov r2, #1
	str r3, [sp]
	bl _ZN9CNCLRFileC1EPKcmmm
_0213D3FC:
	str r0, [r4, #0x150]
	ldr r0, [r0, #0xb8]
	mov r1, #0x20
	ldr r0, [r0, #0xc]
	bl DC_FlushRange
	ldr r0, [r4, #0x150]
	mov r1, #0
	ldr r0, [r0, #0xb8]
	mov r2, #0x20
	ldr r0, [r0, #0xc]
	bl GXS_LoadBGPltt
	cmp r5, #0
	addeq sp, sp, #0x70
	ldmeqia sp!, {r4, r5, r6, pc}
	mov r0, r5
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r5
	bl _ZdlPv
	add sp, sp, #0x70
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0213D44C: .word s_BGU_overlay_1_02141f74
_0213D450: .word s_data_menu_pam000_bg_LZ_bin_overlay_1_02141fcc
_0213D454: .word s_BGU_pam_03d_NCLR_overlay_1_02141fa4

	arm_func_start ov1_0213D458
ov1_0213D458: ; 0x0213D458
	stmdb sp!, {r4, lr}
	ldr r1, [r0, #0x150]
	ldrb r0, [r0, #0xd9]
	ldr r2, [r1, #0xb8]
	mov r1, #0x10
	ldr r2, [r2, #0xc]
	add r4, r2, r0, lsl #5
	mov r0, r4
	bl DC_FlushRange
	mov r0, r4
	mov r1, #0x20
	mov r2, #0x10
	bl GXS_LoadBGPltt
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213D458

	arm_func_start ov1_0213D490
ov1_0213D490: ; 0x0213D490
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #1
	ldr r0, [r4, #0xe0]
	mov r2, r1
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	ldr r0, [r4]
	mov r1, #0x80
	add r0, r0, #0x44
	add r2, r0, #0x400
	strh r1, [r2, #6]
	mov r0, #0
	strh r0, [r2, #0xe]
	strh r0, [r2, #0x16]
	strh r1, [r2, #0x1e]
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213D490

	arm_func_start ov1_0213D4D0
ov1_0213D4D0: ; 0x0213D4D0
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	ldrb r0, [r5, #0xdc]
	ldr r1, _0213D564 ; =0x0400104C
	orr r0, r0, r0, lsl #4
	strb r0, [r1]
	ldrb r0, [r5, #0xdc]
	orr r0, r0, r0, lsl #4
	strb r0, [r1, #1]
	ldrb r0, [r5, #0xdc]
	sub r0, r0, #1
	strb r0, [r5, #0xdc]
	tst r0, #0xff
	ldmneia sp!, {r4, r5, r6, pc}
	ldrh r0, [r1, #-0x44]!
	mov r4, #0
	bic r0, r0, #0x40
	strh r0, [r1]
	ldrb r0, [r5, #0xdb]
	cmp r0, #0
	ble _0213D548
	mov r6, r4
	arm_func_end ov1_0213D4D0
_0213D528:
	add r0, r5, r4, lsl #2
	ldr r0, [r0, #0xf0]
	mov r1, r6
	bl _ZN17UnkClass_0200E96012sub_0200EB64Ei
	ldrb r0, [r5, #0xdb]
	add r4, r4, #1
	cmp r4, r0
	blt _0213D528
_0213D548:
	ldr r0, [r5, #0x13c]
	mov r1, #0
	bl _ZN17UnkClass_0200E96012sub_0200EB64Ei
	ldr r0, [r5, #0x140]
	mov r1, #0
	bl _ZN17UnkClass_0200E96012sub_0200EB64Ei
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0213D564: .word 0x0400104C

	arm_func_start ov1_0213D568
ov1_0213D568: ; 0x0213D568
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	mov r0, #0xf
	ldr r1, _0213D60C ; =0x04001008
	strb r0, [r5, #0xdc]
	ldrh r0, [r1]
	mov r4, #0
	orr r0, r0, #0x40
	strh r0, [r1]
	ldrb r0, [r5, #0xdb]
	cmp r0, #0
	ble _0213D5C4
	mov r6, #1
	arm_func_end ov1_0213D568
_0213D59C:
	add r2, r5, r4, lsl #2
	ldr r0, [r2, #0xf0]
	mov r1, r6
	str r6, [r0, #0x14]
	ldr r0, [r2, #0xf0]
	bl _ZN17UnkClass_0200E96012sub_0200EB64Ei
	ldrb r0, [r5, #0xdb]
	add r4, r4, #1
	cmp r4, r0
	blt _0213D59C
_0213D5C4:
	ldr r0, [r5, #0x13c]
	mov r1, #1
	str r1, [r0, #0x14]
	ldr r0, [r5, #0x140]
	str r1, [r0, #0x14]
	ldr r0, [r5, #0x13c]
	bl _ZN17UnkClass_0200E96012sub_0200EB64Ei
	ldr r0, [r5, #0x140]
	mov r1, #1
	bl _ZN17UnkClass_0200E96012sub_0200EB64Ei
	ldrb r0, [r5, #0xdc]
	ldr r1, _0213D610 ; =0x0400104C
	orr r0, r0, r0, lsl #4
	strb r0, [r1]
	ldrb r0, [r5, #0xdc]
	orr r0, r0, r0, lsl #4
	strb r0, [r1, #1]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0213D60C: .word 0x04001008
_0213D610: .word 0x0400104C

	arm_func_start ov1_0213D614
ov1_0213D614: ; 0x0213D614
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	mov r0, #0xb8
	bl _Znwm
	movs r7, r0
	beq _0213D63C
	ldr r1, _0213D920 ; =s_data_message_etc_menu_mes_overlay_1_02142020
	mov r2, #1
	bl _ZN14CBinaryFileMesC1EPKcm
	mov r7, r0
	arm_func_end ov1_0213D614
_0213D63C:
	mov r0, #0xc
	bl _Znwm
	str r0, [r4, #0x16c]
	ldr r1, [r7, #0x4c]
	mov r5, #2
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r7, #0x4c]
	ldr r0, [r4, #0x16c]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	ldr r0, [r4, #0x16c]
	ldr r0, [r0, #4]
	mov r0, r0, lsl #3
	bl _Znam
	ldr r1, [r4, #0x16c]
	mov r6, #0
	str r0, [r1, #8]
	ldr r2, [r4, #0x16c]
	ldr r0, [r2, #4]
	cmp r0, #0
	bls _0213D704
_0213D694:
	ldr r1, [r7, #0x4c]
	ldr r0, [r2, #8]
	ldr r1, [r1, r5, lsl #2]
	add r5, r5, #1
	str r1, [r0, r6, lsl #3]
	ldr r0, [r4, #0x16c]
	ldr r0, [r0, #8]
	ldr r0, [r0, r6, lsl #3]
	bl _Znam
	ldr r1, [r4, #0x16c]
	ldr r1, [r1, #8]
	add r1, r1, r6, lsl #3
	str r0, [r1, #4]
	ldr r1, [r4, #0x16c]
	ldr r0, [r7, #0x4c]
	ldr r2, [r1, #8]
	add r0, r0, r5, lsl #2
	add r1, r2, r6, lsl #3
	ldr r1, [r1, #4]
	ldr r2, [r2, r6, lsl #3]
	bl MIi_CpuCopyFast
	ldr r2, [r4, #0x16c]
	ldmib r2, {r0, r1}
	ldr r1, [r1, r6, lsl #3]
	add r6, r6, #1
	cmp r6, r0
	add r5, r5, r1, lsr #2
	blo _0213D694
_0213D704:
	cmp r7, #0
	beq _0213D71C
	mov r0, r7
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213D71C:
	mov r0, #0xb8
	bl _Znwm
	movs r7, r0
	beq _0213D73C
	ldr r1, _0213D924 ; =s_data_message_etc_assist_mes_overlay_1_0214203c
	mov r2, #1
	bl _ZN14CBinaryFileMesC1EPKcm
	mov r7, r0
_0213D73C:
	mov r0, #0xc
	bl _Znwm
	str r0, [r4, #0x170]
	ldr r1, [r7, #0x4c]
	mov r5, #2
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r7, #0x4c]
	ldr r0, [r4, #0x170]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	ldr r0, [r4, #0x170]
	ldr r0, [r0, #4]
	mov r0, r0, lsl #3
	bl _Znam
	ldr r1, [r4, #0x170]
	mov r6, #0
	str r0, [r1, #8]
	ldr r2, [r4, #0x170]
	ldr r0, [r2, #4]
	cmp r0, #0
	bls _0213D804
_0213D794:
	ldr r1, [r7, #0x4c]
	ldr r0, [r2, #8]
	ldr r1, [r1, r5, lsl #2]
	add r5, r5, #1
	str r1, [r0, r6, lsl #3]
	ldr r0, [r4, #0x170]
	ldr r0, [r0, #8]
	ldr r0, [r0, r6, lsl #3]
	bl _Znam
	ldr r1, [r4, #0x170]
	ldr r1, [r1, #8]
	add r1, r1, r6, lsl #3
	str r0, [r1, #4]
	ldr r1, [r4, #0x170]
	ldr r0, [r7, #0x4c]
	ldr r2, [r1, #8]
	add r0, r0, r5, lsl #2
	add r1, r2, r6, lsl #3
	ldr r1, [r1, #4]
	ldr r2, [r2, r6, lsl #3]
	bl MIi_CpuCopyFast
	ldr r2, [r4, #0x170]
	ldmib r2, {r0, r1}
	ldr r1, [r1, r6, lsl #3]
	add r6, r6, #1
	cmp r6, r0
	add r5, r5, r1, lsr #2
	blo _0213D794
_0213D804:
	cmp r7, #0
	beq _0213D81C
	mov r0, r7
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213D81C:
	mov r0, #0xb8
	bl _Znwm
	movs r7, r0
	beq _0213D83C
	ldr r1, _0213D928 ; =s_data_message_etc_fieldwaza_name_overlay_1_0214205c
	mov r2, #1
	bl _ZN14CBinaryFileMesC1EPKcm
	mov r7, r0
_0213D83C:
	mov r0, #0xc
	bl _Znwm
	str r0, [r4, #0x174]
	ldr r1, [r7, #0x4c]
	mov r5, #2
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r7, #0x4c]
	ldr r0, [r4, #0x174]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	ldr r0, [r4, #0x174]
	ldr r0, [r0, #4]
	mov r0, r0, lsl #3
	bl _Znam
	ldr r1, [r4, #0x174]
	mov r6, #0
	str r0, [r1, #8]
	ldr r2, [r4, #0x174]
	ldr r0, [r2, #4]
	cmp r0, #0
	bls _0213D904
_0213D894:
	ldr r1, [r7, #0x4c]
	ldr r0, [r2, #8]
	ldr r1, [r1, r5, lsl #2]
	add r5, r5, #1
	str r1, [r0, r6, lsl #3]
	ldr r0, [r4, #0x174]
	ldr r0, [r0, #8]
	ldr r0, [r0, r6, lsl #3]
	bl _Znam
	ldr r1, [r4, #0x174]
	ldr r1, [r1, #8]
	add r1, r1, r6, lsl #3
	str r0, [r1, #4]
	ldr r1, [r4, #0x174]
	ldr r0, [r7, #0x4c]
	ldr r2, [r1, #8]
	add r0, r0, r5, lsl #2
	add r1, r2, r6, lsl #3
	ldr r1, [r1, #4]
	ldr r2, [r2, r6, lsl #3]
	bl MIi_CpuCopyFast
	ldr r2, [r4, #0x174]
	ldmib r2, {r0, r1}
	ldr r1, [r1, r6, lsl #3]
	add r6, r6, #1
	cmp r6, r0
	add r5, r5, r1, lsr #2
	blo _0213D894
_0213D904:
	cmp r7, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mov r0, r7
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0213D920: .word s_data_message_etc_menu_mes_overlay_1_02142020
_0213D924: .word s_data_message_etc_assist_mes_overlay_1_0214203c
_0213D928: .word s_data_message_etc_fieldwaza_name_overlay_1_0214205c

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213D92CEt
_ZN17UnkClass_0213CC2812ov1_0213D92CEt: ; 0x0213D92C
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x64
	mov r5, r0
	ldr r4, [r5, #0x9c]
	mov r0, #0
	str r0, [r5, #0x144]
	ldr r6, [r5, #0x154]
	mov r7, r1
	cmp r6, #0
	beq _0213D970
	beq _0213D968
	mov r0, r6
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r6
	bl _ZdlPv
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213D92CEt
_0213D968:
	mov r0, #0
	str r0, [r5, #0x154]
_0213D970:
	ldr r1, _0213DA0C ; =s_bp_03d_overlay_1_02142080
	add r0, sp, #4
	mov r2, r7
	bl OS_SPrintf
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _0213D9B4
	ldr r3, [r5]
	mov r1, #0x40
	str r1, [sp]
	add r2, r3, #0x1000
	add r1, r3, #0x3f4
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0213D9B4:
	str r0, [r5, #0x154]
	mov r0, #0xf
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [r5, #0x154]
	ldr r1, _0213DA10 ; =s_data_pokeOBJ_overlay_1_02142088
	add r2, sp, #4
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0
	str r1, [sp]
	ldr r0, [r5, #0x154]
	mov r2, #0xc0
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r5, #0x144]
	ldrh r0, [r5, #0x2c]
	orr r0, r0, #6
	strh r0, [r5, #0x2c]
	add sp, sp, #0x64
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_0213DA0C: .word s_bp_03d_overlay_1_02142080
_0213DA10: .word s_data_pokeOBJ_overlay_1_02142088

	arm_func_start ov1_0213DA14
ov1_0213DA14: ; 0x0213DA14
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	mov r0, #0x44
	mov r4, #0
	bl _Znwm
	cmp r0, #0
	beq _0213DA54
	ldr r3, [sl]
	mov r1, #0x40
	str r1, [sp]
	add r2, r3, #0x1000
	add r1, r3, #0x24
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end ov1_0213DA14
_0213DA54:
	str r0, [sl, #0x160]
	mov r3, #0
	str r3, [sp]
	ldr r0, [sl, #0x160]
	ldr r1, _0213DE70 ; =s_data_menu_overlay_1_02142098
	ldr r2, _0213DE74 ; =s_pam003_00_overlay_1_021420a4
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r4, r4, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _0213DAA8
	ldr r3, [sl]
	mov r1, #0x40
	str r1, [sp]
	add r2, r3, #0x1000
	add r1, r3, #0x64
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0213DAA8:
	str r0, [sl, #0x158]
	mov r0, #2
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [sl, #0x158]
	ldr r1, _0213DE70 ; =s_data_menu_overlay_1_02142098
	ldr r2, _0213DE78 ; =s_pam001_00_overlay_1_021420b0
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r4, r4, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _0213DB08
	ldr r3, [sl]
	mov r1, #0x40
	str r1, [sp]
	add r2, r3, #0x1000
	add r1, r3, #0x8c
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0213DB08:
	str r0, [sl, #0x15c]
	mov r0, #6
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [sl, #0x15c]
	ldr r1, _0213DE70 ; =s_data_menu_overlay_1_02142098
	ldr r2, _0213DE7C ; =s_pam002_00_overlay_1_021420bc
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r4, r4, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _0213DB68
	ldr r3, [sl]
	mov r1, #0x40
	str r1, [sp]
	add r2, r3, #0x1000
	add r1, r3, #0x384
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0213DB68:
	str r0, [sl, #0x164]
	mov r0, #8
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [sl, #0x164]
	ldr r1, _0213DE70 ; =s_data_menu_overlay_1_02142098
	ldr r2, _0213DE80 ; =s_ma000_00_overlay_1_021420c8
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r4, r4, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _0213DBC8
	ldr r3, [sl]
	mov r1, #0x40
	str r1, [sp]
	add r2, r3, #0x1000
	add r1, r3, #0x38c
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0213DBC8:
	str r0, [sl, #0x168]
	mov r0, #0xe
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [sl, #0x168]
	ldr r1, _0213DE70 ; =s_data_menu_overlay_1_02142098
	ldr r2, _0213DE84 ; =s_ma001_00_overlay_1_021420d4
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r0, r4, r0
	str r0, [sl, #0x9c]
	mov r1, #0
	str r1, [sp]
	ldr r0, [sl, #0x158]
	mov r2, #0x98
	mov r3, #0x9a
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0xe0]
	ldr r0, [sl, #0x158]
	mov r1, #0x20
	ldr r0, [r0, #0x24]
	mov r2, #0
	str r0, [sl, #0xa0]
	ldr r0, [sl, #0xe0]
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	mov r1, #0
	str r1, [sp]
	ldr r0, [sl, #0x158]
	mov r2, #0xb6
	mov r3, #0x9a
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0xe4]
	ldr r0, [sl, #0x158]
	mov r1, #1
	ldr r0, [r0, #0x24]
	mov r2, r1
	str r0, [sl, #0xa4]
	ldr r0, [sl, #0xe4]
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	mov r1, #0
	str r1, [sp]
	ldr r0, [sl, #0x158]
	mov r2, #0xd9
	mov r3, #0xaa
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0xe8]
	ldr r0, [sl, #0x158]
	mov r1, #0x20
	ldr r0, [r0, #0x24]
	mov r2, #0
	str r0, [sl, #0xa8]
	ldr r0, [sl, #0xe8]
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	mov r1, #0
	str r1, [sp]
	ldr r0, [sl, #0x158]
	mov r2, #0xe9
	mov r3, #0xaa
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0xec]
	ldr r0, [sl, #0x158]
	mov r1, #0x20
	ldr r0, [r0, #0x24]
	mov r2, #0
	str r0, [sl, #0xac]
	ldr r0, [sl, #0xec]
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	mov r0, #0
	str r0, [sp]
	ldr r0, [sl, #0x158]
	mov r1, #0xa
	mov r2, #0xda
	mov r3, #0x98
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sl, #0x15c]
	mov r1, #4
	mov r2, #0xb4
	mov r3, #0x20
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0x130]
	mov r0, #1
	str r0, [sp]
	ldr r0, [sl, #0x15c]
	mov r1, #5
	mov r2, #0xc0
	mov r3, #0x98
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0x134]
	mov r0, #0
	str r0, [sp]
	ldr r0, [sl, #0x15c]
	mov r1, #6
	mov r2, #0x94
	mov r3, #0x14
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0x138]
	mov r0, #1
	str r0, [sp]
	ldr r0, [sl, #0x15c]
	mov r1, #0
	mov r2, #0x40
	mov r3, #0x19
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0x13c]
	mov r0, #1
	str r0, [sp]
	ldr r0, [sl, #0x15c]
	mov r1, #3
	mov r2, #0x40
	mov r3, #0xa9
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r7, #1
	str r0, [sl, #0x140]
	mov sb, #0
	mov r8, #0x29
	mov fp, r7
	mov r4, #2
	mov r6, r7
	mov r5, #0x40
_0213DDB0:
	str r6, [sp]
	ldr r0, [sl, #0x15c]
	mov r1, r7
	mov r2, r5
	mov r3, r8
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	add r1, sl, sb, lsl #2
	str r0, [r1, #0xf0]
	mov r0, #0
	str r0, [sp]
	cmp r7, #1
	moveq r7, r4
	ldr r0, [sl, #0x160]
	mov r1, #0
	mov r2, #0x60
	mov r3, r8
	movne r7, fp
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	add r1, sl, sb, lsl #2
	str r0, [r1, #0x110]
	ldr r0, [sl, #0x160]
	add sb, sb, #1
	ldr r0, [r0, #0x24]
	cmp sb, #8
	str r0, [r1, #0xb0]
	add r8, r8, #0x10
	blt _0213DDB0
	mov r1, #0
	str r1, [sp]
	ldr r0, [sl, #0x164]
	mov r2, #0x80
	mov r3, #0x31
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0x148]
	ldr r0, [sl, #0x164]
	mov r1, #0
	ldr r0, [r0, #0x24]
	mov r2, #0x8c
	str r0, [sl, #0xd0]
	str r1, [sp]
	ldr r0, [sl, #0x168]
	mov r3, #0x31
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sl, #0x14c]
	ldr r0, [sl, #0x168]
	ldr r0, [r0, #0x24]
	str r0, [sl, #0xd4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0213DE70: .word s_data_menu_overlay_1_02142098
_0213DE74: .word s_pam003_00_overlay_1_021420a4
_0213DE78: .word s_pam001_00_overlay_1_021420b0
_0213DE7C: .word s_pam002_00_overlay_1_021420bc
_0213DE80: .word s_ma000_00_overlay_1_021420c8
_0213DE84: .word s_ma001_00_overlay_1_021420d4

	arm_func_start ov1_0213DE88
ov1_0213DE88: ; 0x0213DE88
	stmdb sp!, {r3, lr}
	mov r0, #1
	bl GXS_SetGraphicsMode
	ldr ip, _0213DF1C ; =0x04001000
	mov r1, #0
	ldr r2, [ip]
	ldr r0, [ip]
	and r2, r2, #0x1f00
	mov r3, r2, lsr #8
	bic r2, r0, #0x1f00
	orr r0, r3, #0xe
	orr r0, r2, r0, lsl #8
	str r0, [ip]
	str r1, [ip, #0x10]
	str r1, [ip, #0x14]
	str r1, [ip, #0x18]
	ldrh r2, [ip, #8]
	add r0, ip, #0x50
	mov r3, #8
	bic r2, r2, #3
	strh r2, [ip, #8]
	ldrh lr, [ip, #0xa]
	mov r2, #0x1e
	bic lr, lr, #3
	orr lr, lr, #1
	strh lr, [ip, #0xa]
	ldrh lr, [ip, #0xc]
	bic lr, lr, #3
	orr lr, lr, #3
	strh lr, [ip, #0xc]
	ldrh lr, [ip, #0xe]
	bic lr, lr, #3
	orr lr, lr, #2
	strh lr, [ip, #0xe]
	str r3, [sp]
	bl G2x_SetBlendAlpha_
	ldmia sp!, {r3, pc}
	.align 2, 0
_0213DF1C: .word 0x04001000
	arm_func_end ov1_0213DE88

	arm_func_start ov1_0213DF20
ov1_0213DF20: ; 0x0213DF20
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x14
	mov sl, r0
	ldr r0, [sl]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CAE0Ev
	ldr r0, [sl]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CB14Ev
	ldr r0, [sl]
	mov r1, #0xc
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CC88Ei
	mov r8, #0
	mov r7, #0x220
	mov sb, #4
	mov r6, #2
	mov r5, r8
	mov r4, #8
	arm_func_end ov1_0213DF20
_0213DF78:
	stmia sp, {r6, sb}
	str r7, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	ldr r0, [sl]
	mov r1, r8
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r2, r4
	mov r3, r6
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	add r8, r8, #1
	cmp r8, #8
	add r7, r7, #0x10
	add sb, sb, #2
	blt _0213DF78
	mov r3, #2
	str r3, [sp]
	stmib sp, {r3, r7}
	mov r0, #0
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [sl]
	mov r1, #8
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r2, #0xb
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	mov r0, #0x16
	str r0, [sp]
	mov r3, #2
	str r3, [sp, #4]
	add r0, r7, #0x16
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [sl]
	mov r1, #9
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r2, #8
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	mov r0, #0x12
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	add r0, r7, #0x26
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r3, #2
	str r3, [sp, #0x10]
	ldr r0, [sl]
	mov r1, #0xa
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r2, #0xc
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	mov r1, #0x14
	str r1, [sp]
	mov r1, #0x10
	str r1, [sp, #4]
	add r0, r7, #0x3e
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r3, #2
	str r3, [sp, #0x10]
	ldr r0, [sl]
	mov r1, #0xb
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r2, #8
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	add sp, sp, #0x14
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start ov1_0213E0AC
ov1_0213E0AC: ; 0x0213E0AC
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x10
	mov r6, r0
	ldr r0, [r6, #8]
	mov r5, r1
	mov r4, r2
	cmp r0, #0x11
	beq _0213E104
	mov r0, #3
	str r0, [sp]
	ldr r0, [r6, #0x16c]
	mov r2, #0
	ldr r0, [r0, #8]
	mov r1, #0xb
	ldr r0, [r0, #0x104]
	mov r3, #4
	stmib sp, {r0, r2}
	str r2, [sp, #0xc]
	ldr r0, [r6]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	arm_func_end ov1_0213E0AC
_0213E104:
	mov r0, r6
	bl ov1_0213E12C
	mov r0, r6
	mov r1, r5
	bl ov1_0213E1D8
	mov r0, r6
	mov r1, r4
	bl ov1_0213E244
	add sp, sp, #0x10
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov1_0213E12C
ov1_0213E12C: ; 0x0213E12C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x10
	mov r1, #5
	mov r4, r0
	str r1, [sp]
	ldr r1, [r4, #0x16c]
	mov r0, #0
	ldr r2, [r1, #8]
	mov r1, #8
	ldr r3, [r2, #0xfc]
	mov r2, #2
	str r3, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [r4]
	mov r3, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	mov r7, #0
	mov r5, #3
	mov r6, #7
	arm_func_end ov1_0213E12C
_0213E184:
	add r0, r4, r7, lsl #1
	ldrh r1, [r0, #0x30]
	cmp r1, #0
	beq _0213E1C0
	add r0, r4, r7, lsl #2
	ldr r0, [r0, #0x70]
	mov r2, r7
	cmp r0, #0
	mov r0, r4
	beq _0213E1B8
	mov r3, r6
	bl ov1_0213EBB4
	b _0213E1C0
_0213E1B8:
	mov r3, r5
	bl ov1_0213EBB4
_0213E1C0:
	add r0, r7, #1
	and r7, r0, #0xff
	cmp r7, #8
	blo _0213E184
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov1_0213E1D8
ov1_0213E1D8: ; 0x0213E1D8
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x10
	cmp r1, #0
	addlt sp, sp, #0x10
	ldmltia sp!, {r3, pc}
	cmp r1, #0x11
	addgt sp, sp, #0x10
	ldmgtia sp!, {r3, pc}
	mov ip, #1
	str ip, [sp]
	ldr r2, [r0, #0x170]
	add r1, r1, #1
	ldr r3, [r2, #8]
	sub r2, ip, #4
	add r1, r3, r1, lsl #3
	ldr r3, [r1, #4]
	mov r1, #9
	stmib sp, {r3, ip}
	str r2, [sp, #0xc]
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r3, #2
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	add sp, sp, #0x10
	ldmia sp!, {r3, pc}
	arm_func_end ov1_0213E1D8

	arm_func_start ov1_0213E244
ov1_0213E244: ; 0x0213E244
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x10
	mov lr, #1
	str lr, [sp]
	ldr r2, [r0, #0x174]
	cmp r1, #0x19
	ldr ip, [r2, #8]
	movhs r1, #0x19
	add r1, ip, r1, lsl #3
	ldr ip, [r1, #4]
	mov r3, #2
	stmib sp, {ip, lr}
	str r3, [sp, #0xc]
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #0xa
	mov r3, #4
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	add sp, sp, #0x10
	ldmia sp!, {r3, pc}
	arm_func_end ov1_0213E244

	arm_func_start ov1_0213E29C
ov1_0213E29C: ; 0x0213E29C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, #0
	arm_func_end ov1_0213E29C
_0213E2A8:
	ldr r0, [r5]
	mov r1, r4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CF7CEi
	add r4, r4, #1
	cmp r4, #0xc
	blt _0213E2A8
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_0213E2CC
ov1_0213E2CC: ; 0x0213E2CC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, #9
	arm_func_end ov1_0213E2CC
_0213E2D8:
	ldr r0, [r5]
	mov r1, r4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CF7CEi
	add r4, r4, #1
	cmp r4, #0xc
	blt _0213E2D8
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_0213E2FC
ov1_0213E2FC: ; 0x0213E2FC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, #0
	arm_func_end ov1_0213E2FC
_0213E308:
	ldr r0, [r5]
	mov r1, r4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CF7CEi
	add r4, r4, #1
	cmp r4, #9
	blt _0213E308
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213E32CEi
_ZN17UnkClass_0213CC2812ov1_0213E32CEi: ; 0x0213E32C
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldrh r0, [r4, #0x2c]
	mov r5, r1
	tst r0, #1
	ldmneia sp!, {r3, r4, r5, pc}
	tst r0, #0x200
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r0, [r4, #0x158]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldr r0, [r4, #0x15c]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldr r0, [r4, #0x160]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldr r0, [r4, #0x164]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldr r0, [r4, #0x168]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	cmp r5, #0
	beq _0213E388
	ldrh r1, [r4, #0x2e]
	mov r0, r4
	bl _ZN17UnkClass_0213CC2812ov1_0213E8BCEt
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213E32CEi
_0213E388:
	ldrb r0, [r4, #0xdc]
	cmp r0, #0
	beq _0213E39C
	mov r0, r4
	bl ov1_0213D4D0
_0213E39C:
	ldrb r0, [r4, #0xd8]
	cmp r0, #0xc
	addlo r0, r0, #1
	strlob r0, [r4, #0xd8]
	blo _0213E40C
	ldrb r0, [r4, #0xda]
	cmp r0, #0
	ldreqb r0, [r4, #0xd9]
	cmpeq r0, #5
	moveq r0, #1
	streqb r0, [r4, #0xda]
	ldrb r0, [r4, #0xda]
	cmp r0, #1
	ldreqb r0, [r4, #0xd9]
	cmpeq r0, #1
	moveq r0, #0
	streqb r0, [r4, #0xda]
	ldrb r1, [r4, #0xda]
	ldrb r2, [r4, #0xd9]
	mov r0, r4
	mov r1, r1, lsl #1
	rsb r1, r1, #0
	add r1, r1, #1
	add r1, r2, r1
	strb r1, [r4, #0xd9]
	mov r1, #0
	strb r1, [r4, #0xd8]
	bl ov1_0213D458
_0213E40C:
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	beq _0213E424
	cmp r0, #2
	beq _0213E430
	b _0213E438
_0213E424:
	mov r0, r4
	bl ov1_0213E52C
	b _0213E438
_0213E430:
	mov r0, r4
	bl ov1_0213E60C
_0213E438:
	mov r0, r4
	bl ov1_0213E44C
	mov r0, r4
	bl ov1_0213D490
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_0213E44C
ov1_0213E44C: ; 0x0213E44C
	stmdb sp!, {r3, lr}
	ldrh r2, [r0, #0x26]
	ldr r1, _0213E4C0 ; =0x0000FFFF
	ldr r3, _0213E4C4 ; =FX_SinCosTable_
	add r2, r2, #0x100
	cmp r2, r1
	movge r1, #0
	strgeh r1, [r0, #0x26]
	ldrh r2, [r0, #0x26]
	ldr r1, _0213E4C8 ; =ov1_0213E708
	mov r2, r2, asr #4
	mov ip, r2, lsl #1
	add r2, ip, #1
	mov r2, r2, lsl #1
	mov lr, ip, lsl #1
	ldrsh ip, [r3, r2]
	ldrsh r3, [r3, lr]
	mov r2, #0
	str ip, [r0, #0x10]
	str r3, [r0, #0x14]
	rsb r3, r3, #0
	str r3, [r0, #0x18]
	str ip, [r0, #0x1c]
	ldrh r3, [r0, #0x2c]
	orr r3, r3, #0x80
	strh r3, [r0, #0x2c]
	ldr r0, [r0]
	bl _ZN5CGame12sub_020100E4EPFvPvES0_
	ldmia sp!, {r3, pc}
	.align 2, 0
_0213E4C0: .word 0x0000FFFF
_0213E4C4: .word FX_SinCosTable_
_0213E4C8: .word ov1_0213E708
	arm_func_end ov1_0213E44C

	arm_func_start ov1_0213E4CC
ov1_0213E4CC: ; 0x0213E4CC
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	ldr r1, _0213E524 ; =FX_SinCosTable_
	mov ip, r0
	ldrsh r2, [r1, #2]
	ldrsh r1, [r1]
	ldr r0, _0213E528 ; =0x04001030
	str r2, [ip, #0x10]
	str r1, [ip, #0x14]
	rsb r1, r1, #0
	str r1, [ip, #0x18]
	str r2, [ip, #0x1c]
	ldrsh r3, [ip, #0x20]
	add r1, ip, #0x10
	mov r2, #0x80
	str r3, [sp]
	ldrsh ip, [ip, #0x22]
	mov r3, #0x60
	str ip, [sp, #4]
	bl G2x_SetBGyAffine_
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0213E524: .word FX_SinCosTable_
_0213E528: .word 0x04001030
	arm_func_end ov1_0213E4CC

	arm_func_start ov1_0213E52C
ov1_0213E52C: ; 0x0213E52C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r1, [r4, #0x2a]
	cmp r1, #0x3c
	bne _0213E564
	mov r1, #0
	strh r1, [r4, #0x26]
	strh r1, [r4, #0x2a]
	mov r1, #1
	strh r1, [r4, #0x28]
	bl ov1_0213E12C
	mov r0, r4
	bl ov1_0213D568
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213E52C
_0213E564:
	ldmhsia sp!, {r4, pc}
	cmp r1, #0x1e
	bhs _0213E580
	ldrsh r0, [r4, #0x20]
	sub r0, r0, #0xf
	strh r0, [r4, #0x20]
	b _0213E5B0
_0213E580:
	cmp r1, #0x2d
	bhs _0213E598
	ldrsh r0, [r4, #0x20]
	add r0, r0, #8
	strh r0, [r4, #0x20]
	b _0213E5B0
_0213E598:
	ldrsh r0, [r4, #0x20]
	cmp r1, #0x37
	addlo r0, r0, #4
	strloh r0, [r4, #0x20]
	addhs r0, r0, #1
	strhsh r0, [r4, #0x20]
_0213E5B0:
	ldrh r1, [r4, #0x2a]
	mov r2, #3
	cmp r1, #0
	beq _0213E5DC
	ldr r2, _0213E604 ; =0x66666667
	mov r0, r1, lsr #0x1f
	smull r1, r3, r2, r1
	add r3, r0, r3, asr #3
	rsb r0, r3, #3
	mov r0, r0, lsl #0x10
	mov r2, r0, lsr #0x10
_0213E5DC:
	ldr r0, _0213E608 ; =0x00000888
	ldrh r1, [r4, #0x26]
	mul r0, r2, r0
	mov r0, r0, lsl #0x10
	add r0, r1, r0, lsr #16
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x2a]
	add r0, r0, #1
	strh r0, [r4, #0x2a]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213E604: .word 0x66666667
_0213E608: .word 0x00000888

	arm_func_start ov1_0213E60C
ov1_0213E60C: ; 0x0213E60C
	ldrh r2, [r0, #0x2a]
	cmp r2, #0x1e
	bne _0213E630
	mov r1, #0
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x2a]
	mov r1, #1
	strh r1, [r0, #0x28]
	bx lr
	arm_func_end ov1_0213E60C
_0213E630:
	bxhs lr
	cmp r2, #0
	mov r3, #3
	beq _0213E65C
	ldr r3, _0213E684 ; =0x66666667
	mov r1, r2, lsr #0x1f
	smull r2, ip, r3, r2
	add ip, r1, ip, asr #2
	rsb r1, ip, #3
	mov r1, r1, lsl #0x10
	mov r3, r1, lsr #0x10
_0213E65C:
	ldr r1, _0213E688 ; =0x00000888
	ldrh r2, [r0, #0x26]
	mul r1, r3, r1
	mov r1, r1, lsl #0x10
	add r1, r2, r1, lsr #16
	strh r1, [r0, #0x26]
	ldrh r1, [r0, #0x2a]
	add r1, r1, #1
	strh r1, [r0, #0x2a]
	bx lr
	.align 2, 0
_0213E684: .word 0x66666667
_0213E688: .word 0x00000888

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213E68CEv
_ZN17UnkClass_0213CC2812ov1_0213E68CEv: ; 0x0213E68C
	ldrh r1, [r0, #0x28]
	cmp r1, #0
	bxeq lr
	mov r1, #0
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x2a]
	mov r1, #2
	strh r1, [r0, #0x28]
	bx lr
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213E68CEv

	arm_func_start ov1_0213E6B0
ov1_0213E6B0: ; 0x0213E6B0
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldrh r0, [r4, #0x2c]
	tst r0, #0x80
	addeq sp, sp, #8
	ldmeqia sp!, {r4, pc}
	ldrsh r2, [r4, #0x20]
	ldr r0, _0213E704 ; =0x04001030
	add r1, r4, #0x10
	str r2, [sp]
	ldrsh ip, [r4, #0x22]
	mov r2, #0x80
	mov r3, #0x60
	str ip, [sp, #4]
	bl G2x_SetBGyAffine_
	ldrh r0, [r4, #0x2c]
	bic r0, r0, #0x80
	strh r0, [r4, #0x2c]
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213E704: .word 0x04001030
	arm_func_end ov1_0213E6B0

	arm_func_start ov1_0213E708
ov1_0213E708: ; 0x0213E708
	stmdb sp!, {r3, lr}
	ldr r0, _0213E724 ; =OVERLAY1_BSS_02142200
	ldr r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov1_0213E6B0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0213E724: .word OVERLAY1_BSS_02142200
	arm_func_end ov1_0213E708

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213E728Ev
_ZN17UnkClass_0213CC2812ov1_0213E728Ev: ; 0x0213E728
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r1, [r4, #0x2c]
	tst r1, #1
	beq _0213E744
	bl _Z12sub_02001210v
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213E728Ev
_0213E744:
	bl ov1_0213F01C
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldrh r0, [r4, #0x2c]
	tst r0, #2
	beq _0213E76C
	tst r0, #4
	beq _0213E76C
	ldr r0, [r4, #0x154]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
_0213E76C:
	ldr r0, [r4, #0x15c]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x164]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x168]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldrh r0, [r4, #0x2c]
	tst r0, #0x10
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x160]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldrh r0, [r4, #0x2c]
	tst r0, #0x40
	ldrne r0, [r4, #8]
	cmpne r0, #0x11
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x158]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213E7B8Ev
_ZN17UnkClass_0213CC2812ov1_0213E7B8Ev: ; 0x0213E7B8
	ldr ip, _0213E7C0 ; =ov1_0213E12C
	bx ip
	.align 2, 0
_0213E7C0: .word ov1_0213E12C
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213E7B8Ev

	arm_func_start ov1_0213E7C4
ov1_0213E7C4: ; 0x0213E7C4
	stmdb sp!, {r4, lr}
	mov ip, #0
	mov r2, #1
	mov r3, ip
	mov r4, ip
	arm_func_end ov1_0213E7C4
_0213E7D8:
	cmp r1, #0
	bne _0213E824
	cmp ip, #1
	ldreq lr, [r0, #8]
	cmpeq lr, #0x11
	add lr, r0, ip, lsl #2
	bne _0213E800
	ldr lr, [lr, #0x130]
	str r3, [lr, #0x14]
	b _0213E824
_0213E800:
	ldr lr, [lr, #0x130]
	str r2, [lr, #0x14]
	ldr lr, [r0, #0x148]
	str r2, [lr, #0x14]
	ldr lr, [r0, #0x14c]
	str r2, [lr, #0x14]
	ldrh lr, [r0, #0x2c]
	orr lr, lr, #0x40
	strh lr, [r0, #0x2c]
_0213E824:
	cmp r1, #1
	bne _0213E854
	add lr, r0, ip, lsl #2
	ldr lr, [lr, #0x130]
	str r4, [lr, #0x14]
	ldr lr, [r0, #0x148]
	str r4, [lr, #0x14]
	ldr lr, [r0, #0x14c]
	str r4, [lr, #0x14]
	ldrh lr, [r0, #0x2c]
	bic lr, lr, #0x40
	strh lr, [r0, #0x2c]
_0213E854:
	add ip, ip, #1
	cmp ip, #3
	blt _0213E7D8
	ldr r0, [r0, #0x15c]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r4, pc}

	arm_func_start ov1_0213E86C
ov1_0213E86C: ; 0x0213E86C
	ldr ip, _0213E880 ; =FUN_0200F628
	add r1, r0, r1, lsl #2
	ldr r0, [r0, #0x158]
	ldr r1, [r1, #0xa0]
	bx ip
	.align 2, 0
_0213E880: .word _ZN17UnkClass_0200ECD012sub_0200F628Eii
	arm_func_end ov1_0213E86C

	arm_func_start ov1_0213E884
ov1_0213E884: ; 0x0213E884
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldrb r4, [r5, #0xf]
	ldrb r2, [r5, #0xe]
	ldr r0, [r5, #0x164]
	cmp r4, #5
	ldr r1, [r5, #0xd0]
	movhi r4, #0
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	ldr r0, [r5, #0x168]
	ldr r1, [r5, #0xd4]
	mov r2, r4
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_0213E884

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213E8BCEt
_ZN17UnkClass_0213CC2812ov1_0213E8BCEt: ; 0x0213E8BC
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	mov r5, r1
	bl ov1_0213EF2C
	cmp r0, #0
	beq _0213E8E0
	ldr r0, [r8, #8]
	cmp r0, #0x11
	moveq r5, #0
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213E8BCEt
_0213E8E0:
	ldr r2, _0213E9AC ; =0x88888889
	mov r0, r5, lsr #0x1f
	smull r1, r4, r2, r5
	add r4, r5, r4
	add r4, r0, r4, asr #5
	mov r0, #0x3c
	mul r0, r4, r0
	sub r0, r5, r0
	cmp r0, #0
	mov r5, #0
	ble _0213E934
	add r0, r0, r0, lsl #2
	mov r2, r0, lsl #0xc
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r3, r5
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r2, #0x3000
	bl _ll_div
	mov r5, r0, asr #0xc
_0213E934:
	ldr ip, _0213E9B0 ; =0x66666667
	mov r0, r4, lsr #0x1f
	smull r1, r6, ip, r4
	add r6, r0, r6, asr #2
	mov r0, r8
	mov r2, r6
	mov r3, r5, lsr #0x1f
	smull r1, r7, ip, r5
	mov r1, #0
	add r7, r3, r7, asr #2
	bl ov1_0213E86C
	mov r0, #0xa
	mul r1, r6, r0
	mov r0, r8
	sub r2, r4, r1
	mov r1, #1
	bl ov1_0213E86C
	mov r0, r8
	mov r2, r7
	mov r1, #2
	bl ov1_0213E86C
	mov r0, r8
	mov r1, #3
	mov r2, #0xa
	mul r2, r7, r2
	sub r2, r5, r2
	bl ov1_0213E86C
	ldr r0, [r8, #0x158]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0213E9AC: .word 0x88888889
_0213E9B0: .word 0x66666667

	arm_func_start ov1_0213E9B4
ov1_0213E9B4: ; 0x0213E9B4
	stmdb sp!, {r3, lr}
	mov r0, r1
	mov r1, r2
	bl ov1_0212EE80
	cmp r0, #0x1000
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	movgt r0, #1
	ldmgtia sp!, {r3, pc}
	movlt r0, #2
	movge r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end ov1_0213E9B4

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213E9E4Et
_ZN17UnkClass_0213CC2812ov1_0213E9E4Et: ; 0x0213E9E4
	strh r1, [r0, #0x2e]
	bx lr
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213E9E4Et

	arm_func_start ov1_0213E9EC
ov1_0213E9EC: ; 0x0213E9EC
	mov r0, #0x29
	bx lr
	arm_func_end ov1_0213E9EC

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213E9F4Eh
_ZN17UnkClass_0213CC2812ov1_0213E9F4Eh: ; 0x0213E9F4
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	mov r5, r0
	cmp r4, #1
	ldmloia sp!, {r3, r4, r5, pc}
	cmp r4, #8
	ldmhiia sp!, {r3, r4, r5, pc}
	strb r4, [r5, #0x90]
	bl ov1_0213E9EC
	mov r2, r0
	mov r0, r5
	mov r1, r4
	bl ov1_0213EA3C
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213E9F4Eh

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EA2CEh
_ZN17UnkClass_0213CC2812ov1_0213EA2CEh: ; 0x0213EA2C
	add r0, r0, r1, lsl #2
	mov r1, #1
	str r1, [r0, #0x70]
	bx lr
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EA2CEh

	arm_func_start ov1_0213EA3C
ov1_0213EA3C: ; 0x0213EA3C
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	mov r3, #0
	mov r8, r2
	mov sl, r0
	mov sb, r1
	mov r2, r3
	arm_func_end ov1_0213EA3C
_0213EA54:
	add r1, sl, r3, lsl #2
	ldr r0, [r1, #0xf0]
	add r3, r3, #1
	str r2, [r0, #0x14]
	ldr r0, [r1, #0x110]
	cmp r3, #8
	str r2, [r0, #0x14]
	blt _0213EA54
	ldr r0, [sl, #0x13c]
	sub r2, r8, #0x10
	mov r1, #0x40
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [sl, #0x140]
	add r2, r8, sb, lsl #4
	mov r1, #0x40
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	cmp sb, #0
	mov r7, #0
	ble _0213EAF8
	mov r6, #0x40
	mov r5, #0x60
	mov r4, r7
_0213EAAC:
	add r0, sl, r7, lsl #2
	ldr r0, [r0, #0xf0]
	mov r1, r6
	mov r2, r8
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add r0, sl, r7, lsl #2
	ldr r0, [r0, #0x110]
	mov r1, r5
	mov r2, r8
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add r1, sl, r7, lsl #2
	ldr r0, [r1, #0xf0]
	add r7, r7, #1
	str r4, [r0, #0x14]
	ldr r0, [r1, #0x110]
	cmp r7, sb
	str r4, [r0, #0x14]
	add r8, r8, #0x10
	blt _0213EAAC
_0213EAF8:
	ldr r0, [sl, #0x13c]
	mov r1, #0
	str r1, [r0, #0x14]
	ldr r0, [sl, #0x140]
	str r1, [r0, #0x14]
	strb sb, [sl, #0xdb]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start ov1_0213EB14
ov1_0213EB14: ; 0x0213EB14
	stmdb sp!, {r4, r5, r6, lr}
	movs r5, r1
	mov r6, r0
	mov r4, r2
	bne _0213EB38
	add r0, r6, r4, lsl #2
	ldr r0, [r0, #0x110]
	mov r1, #0
	str r1, [r0, #0x14]
	arm_func_end ov1_0213EB14
_0213EB38:
	cmp r5, #1
	bne _0213EB64
	add r1, r6, r4, lsl #2
	ldr r0, [r6, #0x160]
	ldr r1, [r1, #0xb0]
	mov r2, #0
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	add r0, r6, r4, lsl #2
	ldr r0, [r0, #0x110]
	mov r1, #1
	str r1, [r0, #0x14]
_0213EB64:
	cmp r5, #2
	bne _0213EB90
	add r1, r6, r4, lsl #2
	ldr r0, [r6, #0x160]
	ldr r1, [r1, #0xb0]
	mov r2, #1
	bl _ZN17UnkClass_0200ECD012sub_0200F628Eii
	add r0, r6, r4, lsl #2
	ldr r0, [r0, #0x110]
	mov r1, #1
	str r1, [r0, #0x14]
_0213EB90:
	ldr r0, [r6, #0x160]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov1_0213EB9C
ov1_0213EB9C: ; 0x0213EB9C
	ldr r0, [r0]
	ldr ip, _0213EBB0 ; =FUN_02018B10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b0]
	bx ip
	.align 2, 0
_0213EBB0: .word sub_02018B10
	arm_func_end ov1_0213EB9C

	arm_func_start ov1_0213EBB4
ov1_0213EBB4: ; 0x0213EBB4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x30
	mov r4, r0
	ldr r0, [r4]
	mov r6, r2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r7, r1
	mov r1, r6
	mov r5, r3
	bl _ZN17UnkClass_0200CAB412sub_0200CF7CEi
	mov r0, r4
	mov r1, r7
	bl ov1_0213EB9C
	add r1, sp, #0x10
	mov r2, #0x1f
	bl sub_0202BC74
	str r5, [sp]
	add r2, sp, #0x10
	str r2, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [r4]
	mov r2, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, r6
	mov r3, r2
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end ov1_0213EBB4

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EC34Ehh
_ZN17UnkClass_0213CC2812ov1_0213EC34Ehh: ; 0x0213EC34
	add r0, r0, r2
	strb r1, [r0, #0x91]
	bx lr
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EC34Ehh

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EC40Eh
_ZN17UnkClass_0213CC2812ov1_0213EC40Eh: ; 0x0213EC40
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r4, #0
	mov r7, r0
	mov r6, r1
	mov r5, r4
	mov sb, #1
	mov r8, #2
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EC40Eh
_0213EC5C:
	add r0, r7, r5
	ldrb r2, [r0, #0x91]
	cmp r2, #0x12
	beq _0213ECAC
	add r0, r7, r5, lsl #2
	ldr r0, [r0, #0x70]
	cmp r0, #0
	bne _0213EC9C
	mov r0, r7
	mov r1, r6
	bl ov1_0213E9B4
	cmp r0, #1
	moveq r4, sb
	cmp r0, #2
	cmpeq r4, #0
	moveq r4, r8
_0213EC9C:
	add r0, r5, #1
	and r5, r0, #0xff
	cmp r5, #8
	blo _0213EC5C
_0213ECAC:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213ECB4Eiii
_ZN17UnkClass_0213CC2812ov1_0213ECB4Eiii: ; 0x0213ECB4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	mov sl, r0
	mov sb, r1
	mov r4, r2
	str sb, [sl, #8]
	strb r4, [sl, #0xe]
	strb r3, [sl, #0xf]
	bl ov1_0213D354
	mov r0, sl
	bl ov1_0213E29C
	mov r0, sl
	mov r1, sb
	mov r2, r4
	bl ov1_0213E0AC
	mov r0, sl
	mov r1, #0
	bl ov1_0213E7C4
	mov r0, sl
	bl ov1_0213E884
	mov r0, sl
	mov r1, #1
	bl _ZN17UnkClass_0213CC2812ov1_0213EF14Ei
	mov r7, #0
	ldrh r0, [sl, #0x2c]
	mov r8, r7
	mov r5, #1
	bic r0, r0, #4
	strh r0, [sl, #0x2c]
	mov r4, #2
	mov r6, r7
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213ECB4Eiii
_0213ED2C:
	add r0, sl, r8
	ldrb r2, [r0, #0x91]
	cmp r2, #0x12
	beq _0213ED9C
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x70]
	cmp r0, #0
	mov r0, sl
	beq _0213ED60
	mov r1, r6
	mov r2, r8
	bl ov1_0213EB14
	b _0213ED8C
_0213ED60:
	mov r1, sb
	bl ov1_0213E9B4
	mov r1, r0
	cmp r1, #1
	moveq r7, r5
	cmp r1, #2
	cmpeq r7, #0
	mov r0, sl
	mov r2, r8
	moveq r7, r4
	bl ov1_0213EB14
_0213ED8C:
	add r0, r8, #1
	and r8, r0, #0xff
	cmp r8, #8
	blo _0213ED2C
_0213ED9C:
	mov r0, r7
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EDA4Eth
_ZN17UnkClass_0213CC2812ov1_0213EDA4Eth: ; 0x0213EDA4
	add r0, r0, r2, lsl #1
	strh r1, [r0, #0x30]
	bx lr
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EDA4Eth

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EDB0Ehhh
_ZN17UnkClass_0213CC2812ov1_0213EDB0Ehhh: ; 0x0213EDB0
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r1, [r4, #4]
	strb r2, [r4, #0xc]
	strb r3, [r4, #0xd]
	bl ov1_0213E29C
	ldrb r2, [r4, #0xc]
	ldr r1, [r4, #4]
	mov r0, r4
	bl ov1_0213E0AC
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EDB0Ehhh

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EDDCEv
_ZN17UnkClass_0213CC2812ov1_0213EDDCEv: ; 0x0213EDDC
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r1, [r4, #4]
	str r1, [r4, #8]
	ldrb r1, [r4, #0xc]
	strb r1, [r4, #0xe]
	ldrb r1, [r4, #0xd]
	strb r1, [r4, #0xf]
	ldrh r1, [r4, #0x2c]
	tst r1, #2
	beq _0213EE38
	ldrh r1, [r4, #0x2e]
	bl _ZN17UnkClass_0213CC2812ov1_0213E8BCEt
	ldr r1, [r4, #4]
	ldrb r2, [r4, #0xc]
	ldrb r3, [r4, #0xd]
	mov r0, r4
	and r1, r1, #0xff
	bl _ZN17UnkClass_0213CC2812ov1_0213ECB4Eiii
	ldrh r0, [r4, #0x2c]
	orr r0, r0, #4
	strh r0, [r4, #0x2c]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EDDCEv
_0213EE38:
	mov r1, #0x12
	bl ov1_0213D354
	mov r0, r4
	bl ov1_0213E2CC
	mov r0, r4
	mov r1, #0
	bl _ZN17UnkClass_0213CC2812ov1_0213EF14Ei
	mov r0, r4
	bl ov1_0213E884
	mov r0, r4
	mov r1, #1
	bl ov1_0213E7C4
	mov r0, r4
	bl ov1_0213E12C
	mov r0, r4
	bl ov1_0213EF80
	cmp r0, #0
	beq _0213EE8C
	mov r0, r4
	mov r1, #1
	bl _ZN17UnkClass_0213CC2812ov1_0213EF14Ei
_0213EE8C:
	mov r6, #0
	mov r5, r6
_0213EE94:
	mov r0, r4
	mov r1, r5
	mov r2, r6
	bl ov1_0213EB14
	add r0, r6, #1
	and r6, r0, #0xff
	cmp r6, #8
	blo _0213EE94
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EEB8Ev
_ZN17UnkClass_0213CC2812ov1_0213EEB8Ev: ; 0x0213EEB8
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r0, #0
	str r0, [r5, #0x144]
	ldr r4, [r5, #0x154]
	cmp r4, #0
	beq _0213EEF0
	beq _0213EEE8
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EEB8Ev
_0213EEE8:
	mov r0, #0
	str r0, [r5, #0x154]
_0213EEF0:
	ldrh r0, [r5, #0x2c]
	mov r1, #0xa
	bic r0, r0, #2
	strh r0, [r5, #0x2c]
	ldr r0, [r5]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CF7CEi
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EF14Ei
_ZN17UnkClass_0213CC2812ov1_0213EF14Ei: ; 0x0213EF14
	cmp r1, #0
	ldrh r1, [r0, #0x2c]
	orrne r1, r1, #0x10
	biceq r1, r1, #0x10
	strh r1, [r0, #0x2c]
	bx lr
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EF14Ei

	arm_func_start ov1_0213EF2C
ov1_0213EF2C: ; 0x0213EF2C
	ldrh r0, [r0, #0x2c]
	tst r0, #0x10
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end ov1_0213EF2C

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EF40Ei
_ZN17UnkClass_0213CC2812ov1_0213EF40Ei: ; 0x0213EF40
	cmp r1, #0
	ldrh r1, [r0, #0x2c]
	orrne r1, r1, #0x20
	strneh r1, [r0, #0x2c]
	bxne lr
	bic r1, r1, #0x20
	strh r1, [r0, #0x2c]
	ldrh r1, [r0, #0x2c]
	tst r1, #2
	bxne lr
	mov r1, #0x12
	str r1, [r0, #4]
	mov r1, #0
	strb r1, [r0, #0xc]
	strb r1, [r0, #0xd]
	bx lr
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EF40Ei

	arm_func_start ov1_0213EF80
ov1_0213EF80: ; 0x0213EF80
	ldrh r0, [r0, #0x2c]
	tst r0, #0x20
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end ov1_0213EF80

	arm_func_start _ZN17UnkClass_0213CC2812ov1_0213EF94Ei
_ZN17UnkClass_0213CC2812ov1_0213EF94Ei: ; 0x0213EF94
	stmdb sp!, {r4, lr}
	ldrh r2, [r0, #0x2c]
	cmp r1, #0
	mov lr, #0
	orrne r2, r2, #0x200
	biceq r2, r2, #0x200
	strh r2, [r0, #0x2c]
	cmp r1, #0
	movne r3, #1
	moveq r3, #0
	ldr r2, [r0, #0x13c]
	cmp r1, #0
	str r3, [r2, #0x14]
	movne r3, #1
	ldr r2, [r0, #0x140]
	moveq r3, #0
	str r3, [r2, #0x14]
	ldrb r2, [r0, #0xdb]
	cmp r2, #0
	ble _0213F014
	mov r3, lr
	mov ip, #1
	arm_func_end _ZN17UnkClass_0213CC2812ov1_0213EF94Ei
_0213EFEC:
	add r2, r0, lr, lsl #2
	cmp r1, #0
	movne r4, ip
	ldr r2, [r2, #0xf0]
	moveq r4, r3
	str r4, [r2, #0x14]
	ldrb r2, [r0, #0xdb]
	add lr, lr, #1
	cmp lr, r2
	blt _0213EFEC
_0213F014:
	bl ov1_0213E2FC
	ldmia sp!, {r4, pc}

	arm_func_start ov1_0213F01C
ov1_0213F01C: ; 0x0213F01C
	ldrh r0, [r0, #0x2c]
	and r0, r0, #0x200
	bx lr
	arm_func_end ov1_0213F01C

	arm_func_start _ZN17UnkClass_0213F028C1Et
_ZN17UnkClass_0213F028C1Et: ; 0x0213F028
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x10
	mov r5, r0
	add r0, r5, #0x14
	mov r4, r1
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r5, #0x64
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r5, #0xb0
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r5, #0x100
	bl _ZN15CSoftwareSpriteC1Ev
	mov r0, r5
	mov r1, r4
	strh r4, [r5, #2]
	bl ov1_0213F0C8
	mov r0, #0
	mov r1, #0x18000
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r0, [sp]
	str r0, [r5, #8]
	mov r0, r5
	str r1, [r5, #0xc]
	str r1, [sp, #4]
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_0213F028C1Et

	arm_func_start _ZN17UnkClass_0213F028D1Ev
_ZN17UnkClass_0213F028D1Ev: ; 0x0213F094
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213F2B4
	add r0, r4, #0x100
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0xb0
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x64
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x14
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F028D1Ev

	arm_func_start ov1_0213F0C8
ov1_0213F0C8: ; 0x0213F0C8
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x1ec
	cmp r1, #7
	mov r4, r0
	addeq sp, sp, #0x1ec
	ldmeqia sp!, {r4, r5, pc}
	addhi sp, sp, #0x1ec
	ldmhiia sp!, {r4, r5, pc}
	add r0, r1, #0x30
	and r5, r0, #0xff
	ldr r1, _0213F27C ; =s_data_interface_i_03d_LZ_bin_overlay_1_021420e0
	add r0, sp, #0x18c
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F280 ; =s_BCO_i_03d_00_NCBR_overlay_1_021420fc
	add r0, sp, #0x12c
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F284 ; =s_BCO_i_03d_NCLR_overlay_1_02142110
	add r0, sp, #0xcc
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F288 ; =s_BCO_i_03d_00_NCER_overlay_1_02142120
	add r0, sp, #0x6c
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F28C ; =s_BCO_i_03d_00_cac_overlay_1_02142134
	mov r2, r5
	add r0, sp, #0xc
	bl OS_SPrintf
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213F178
	add r2, sp, #0xcc
	str r2, [sp]
	add r1, sp, #0x6c
	str r1, [sp, #4]
	add ip, sp, #0xc
	ldr r1, _0213F290 ; =s_BCO_overlay_1_02142148
	add r2, sp, #0x18c
	add r3, sp, #0x12c
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
	arm_func_end ov1_0213F0C8
_0213F178:
	str r0, [r4, #0x60]
	ldr r0, [r0, #0xc]
	mov r1, #1
	mov r2, #0
	str r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, #0x100
	strh r0, [r1, #0x54]
	ldr r0, [r4, #0x60]
	mov r1, #0
	ldmia r0, {r2, r3, ip}
	str r2, [r4, #0x40]
	str r1, [r4, #0x44]
	str r3, [r4, #0x48]
	mov r0, #0x18
	str ip, [r4, #0x4c]
	bl _Znwm
	cmp r0, #0
	beq _0213F1EC
	ldr r1, _0213F294 ; =s_BCO_i055_NCLR_overlay_1_0214217c
	ldr ip, _0213F298 ; =s_BCO_i055_00_NCER_overlay_1_0214218c
	str r1, [sp]
	ldr r1, _0213F290 ; =s_BCO_overlay_1_02142148
	ldr r2, _0213F29C ; =s_data_interface_i055_LZ_bin_overlay_1_0214214c
	ldr r3, _0213F2A0 ; =s_BCO_i055_00_NCBR_overlay_1_02142168
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213F1EC:
	str r0, [r4, #0xfc]
	ldmia r0, {r0, r1, r2}
	str r0, [r4, #0x90]
	mov ip, #0
	str ip, [r4, #0x94]
	str r1, [r4, #0x98]
	str r2, [r4, #0x9c]
	ldr r1, [r4, #0xfc]
	mov r0, #0x18
	ldmia r1, {r1, r2, r3}
	str r1, [r4, #0xdc]
	str ip, [r4, #0xe0]
	str r2, [r4, #0xe4]
	str r3, [r4, #0xe8]
	bl _Znwm
	cmp r0, #0
	beq _0213F258
	ldr r1, _0213F2A4 ; =s_BCO_i056_NCLR_overlay_1_021421d0
	ldr ip, _0213F2A8 ; =s_BCO_i056_00_NCER_overlay_1_021421e0
	str r1, [sp]
	ldr r1, _0213F290 ; =s_BCO_overlay_1_02142148
	ldr r2, _0213F2AC ; =s_data_interface_i056_LZ_bin_overlay_1_021421a0
	ldr r3, _0213F2B0 ; =s_BCO_i056_00_NCBR_overlay_1_021421bc
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213F258:
	str r0, [r4, #0x14c]
	ldmia r0, {r1, r2, r3}
	mov r0, #0
	str r1, [r4, #0x12c]
	str r0, [r4, #0x130]
	str r2, [r4, #0x134]
	str r3, [r4, #0x138]
	add sp, sp, #0x1ec
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_0213F27C: .word s_data_interface_i_03d_LZ_bin_overlay_1_021420e0
_0213F280: .word s_BCO_i_03d_00_NCBR_overlay_1_021420fc
_0213F284: .word s_BCO_i_03d_NCLR_overlay_1_02142110
_0213F288: .word s_BCO_i_03d_00_NCER_overlay_1_02142120
_0213F28C: .word s_BCO_i_03d_00_cac_overlay_1_02142134
_0213F290: .word s_BCO_overlay_1_02142148
_0213F294: .word s_BCO_i055_NCLR_overlay_1_0214217c
_0213F298: .word s_BCO_i055_00_NCER_overlay_1_0214218c
_0213F29C: .word s_data_interface_i055_LZ_bin_overlay_1_0214214c
_0213F2A0: .word s_BCO_i055_00_NCBR_overlay_1_02142168
_0213F2A4: .word s_BCO_i056_NCLR_overlay_1_021421d0
_0213F2A8: .word s_BCO_i056_00_NCER_overlay_1_021421e0
_0213F2AC: .word s_data_interface_i056_LZ_bin_overlay_1_021421a0
_0213F2B0: .word s_BCO_i056_00_NCBR_overlay_1_021421bc

	arm_func_start ov1_0213F2B4
ov1_0213F2B4: ; 0x0213F2B4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0x60]
	cmp r4, #0
	beq _0213F2E4
	beq _0213F2DC
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end ov1_0213F2B4
_0213F2DC:
	mov r0, #0
	str r0, [r5, #0x60]
_0213F2E4:
	ldr r4, [r5, #0xfc]
	cmp r4, #0
	beq _0213F30C
	beq _0213F304
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213F304:
	mov r0, #0
	str r0, [r5, #0xfc]
_0213F30C:
	ldr r4, [r5, #0x14c]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _0213F32C
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213F32C:
	mov r0, #0
	str r0, [r5, #0x14c]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F338Ev
_ZN17UnkClass_0213F02812ov1_0213F338Ev: ; 0x0213F338
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #4]
	cmp r1, #0xb
	addls pc, pc, r1, lsl #2
	ldmia sp!, {r3, pc}
_0213F34C: ; jump table
	ldmia sp!, {r3, pc} ; case 0
	b _0213F37C ; case 1
	b _0213F384 ; case 2
	b _0213F38C ; case 3
	b _0213F394 ; case 4
	b _0213F39C ; case 5
	b _0213F3A4 ; case 6
	b _0213F3AC ; case 7
	b _0213F3B4 ; case 8
	b _0213F3BC ; case 9
	b _0213F3C4 ; case 10
	b _0213F3CC ; case 11
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F338Ev
_0213F37C:
	bl ov1_0213F3D4
	ldmia sp!, {r3, pc}
_0213F384:
	bl ov1_0213F41C
	ldmia sp!, {r3, pc}
_0213F38C:
	bl ov1_0213F490
	ldmia sp!, {r3, pc}
_0213F394:
	bl ov1_0213F504
	ldmia sp!, {r3, pc}
_0213F39C:
	bl ov1_0213F578
	ldmia sp!, {r3, pc}
_0213F3A4:
	bl ov1_0213F5A0
	ldmia sp!, {r3, pc}
_0213F3AC:
	bl ov1_0213F608
	ldmia sp!, {r3, pc}
_0213F3B4:
	bl ov1_0213F688
	ldmia sp!, {r3, pc}
_0213F3BC:
	bl ov1_0213F6D0
	ldmia sp!, {r3, pc}
_0213F3C4:
	bl ov1_0213F794
	ldmia sp!, {r3, pc}
_0213F3CC:
	bl ov1_0213F7E4
	ldmia sp!, {r3, pc}

	arm_func_start ov1_0213F3D4
ov1_0213F3D4: ; 0x0213F3D4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #1
	ldmloia sp!, {r4, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	ldr r1, _0213F418 ; =s_system_000_overlay_1_021421f4
	bl sub_02034184
	mov r0, r4
	mov r1, #2
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213F418: .word s_system_000_overlay_1_021421f4
	arm_func_end ov1_0213F3D4

	arm_func_start ov1_0213F41C
ov1_0213F41C: ; 0x0213F41C
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x28
	mov r1, #0x1000
	mov r3, #6
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x120]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r0, [r4, #0x118]
	str r1, [r4, #0x11c]
	ldrh r0, [r4]
	str r1, [sp, #4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #6
	addls sp, sp, #8
	ldmlsia sp!, {r4, pc}
	mov r2, #0x1000
	mov r0, r4
	mov r1, #3
	str r2, [r4, #0x120]
	bl ov1_0213F960
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F41C

	arm_func_start ov1_0213F490
ov1_0213F490: ; 0x0213F490
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x28
	mov r1, #0x1000
	mov r3, #0xa
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x124]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r0, [r4, #0x118]
	str r1, [r4, #0x11c]
	ldrh r0, [r4]
	str r1, [sp, #4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0xa
	addlo sp, sp, #8
	ldmloia sp!, {r4, pc}
	mov r2, #0x1000
	mov r0, r4
	mov r1, #4
	str r2, [r4, #0x124]
	bl ov1_0213F960
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F490

	arm_func_start ov1_0213F504
ov1_0213F504: ; 0x0213F504
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x100000
	sub r1, r0, #0x160000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	ldr r2, [r4, #0xc]
	ldr r1, [r4, #8]
	str r2, [sp, #0xc]
	add r1, r1, r0
	str r1, [r4, #0x2c]
	str r2, [r4, #0x30]
	ldrh r0, [r4]
	str r1, [sp, #8]
	str r1, [sp]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	str r2, [sp, #4]
	cmp r0, #8
	addls sp, sp, #0x10
	ldmlsia sp!, {r4, pc}
	mov r0, r4
	mov r1, #5
	bl ov1_0213F960
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F504

	arm_func_start ov1_0213F578
ov1_0213F578: ; 0x0213F578
	stmdb sp!, {r3, lr}
	ldrh r1, [r0]
	add r1, r1, #1
	strh r1, [r0]
	ldrh r1, [r0]
	cmp r1, #0x30
	ldmlsia sp!, {r3, pc}
	mov r1, #6
	bl ov1_0213F960
	ldmia sp!, {r3, pc}
	arm_func_end ov1_0213F578

	arm_func_start ov1_0213F5A0
ov1_0213F5A0: ; 0x0213F5A0
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x3e]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0x20
	ldmlsia sp!, {r4, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0x3b
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, r4
	mov r1, #7
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F5A0

	arm_func_start ov1_0213F608
ov1_0213F608: ; 0x0213F608
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r2, [r4]
	cmp r2, #8
	bhi _0213F63C
	mov r0, #0x1f
	mov r1, #0
	mov r3, #8
	bl _Z17LinearInterpolatellll
	and r0, r0, #0xff
	str r0, [r4, #0xc4]
	mov r0, #0x1f
	str r0, [r4, #0x78]
	arm_func_end ov1_0213F608
_0213F63C:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x3e]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #8
	ldmloia sp!, {r4, pc}
	mov r0, r4
	mov r1, #8
	bl ov1_0213F960
	ldmia sp!, {r4, pc}

	arm_func_start ov1_0213F688
ov1_0213F688: ; 0x0213F688
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0x18
	ldmlsia sp!, {r4, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	mov r1, #1
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, r4
	mov r1, #9
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F688

	arm_func_start ov1_0213F6D0
ov1_0213F6D0: ; 0x0213F6D0
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x20
	mov r4, r0
	mov r0, #0x60000
	rsb r0, r0, #0
	ldrh r2, [r4]
	sub r1, r0, #0x120000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	ldr lr, [r4, #0xc]
	ldr r2, [r4, #8]
	mov r1, #0x100000
	add ip, r2, r0
	str ip, [r4, #0x2c]
	str lr, [r4, #0x30]
	ldrh r2, [r4]
	mov r0, #0x3b000
	mov r3, #8
	str lr, [sp, #0x1c]
	str ip, [sp, #0x18]
	str ip, [sp, #0x10]
	str lr, [sp, #0x14]
	bl _Z17LinearInterpolatellll
	ldr r2, [r4, #8]
	ldr r1, [r4, #0xc]
	add r2, r2, r0
	add r1, r1, #0x5000
	str r2, [r4, #0x7c]
	str r1, [r4, #0x80]
	str r2, [r4, #0xc8]
	str r1, [r4, #0xcc]
	ldrh r0, [r4]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	str r2, [sp, #8]
	str r1, [sp, #0xc]
	str r2, [sp]
	str r1, [sp, #4]
	cmp r0, #8
	addls sp, sp, #0x20
	ldmlsia sp!, {r4, pc}
	mov r0, r4
	mov r1, #0xa
	bl ov1_0213F960
	add sp, sp, #0x20
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F6D0

	arm_func_start ov1_0213F794
ov1_0213F794: ; 0x0213F794
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x1000
	mov r1, #0x28
	mov r3, #0xa
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x124]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0xa
	ldmlsia sp!, {r4, pc}
	mov r2, #0x28
	mov r0, r4
	mov r1, #0xb
	str r2, [r4, #0x124]
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F794

	arm_func_start ov1_0213F7E4
ov1_0213F7E4: ; 0x0213F7E4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x1000
	mov r1, #0x28
	mov r3, #6
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x120]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #6
	ldmlsia sp!, {r4, pc}
	mov r0, r4
	mov r1, #0
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F7E4

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F82CEP8Camera2D
_ZN17UnkClass_0213F02812ov1_0213F82CEP8Camera2D: ; 0x0213F82C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r1
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r1, _0213F8B0 ; =0x00000406
	mov r0, r5
	bl _ZN17UnkClass_0213F02812ov1_0213F970Ei
	add r0, r5, #0x14
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x64
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0xb0
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x100
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0213F8B0: .word 0x00000406
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F82CEP8Camera2D

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F8B4Ev
_ZN17UnkClass_0213F02812ov1_0213F8B4Ev: ; 0x0213F8B4
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldrh r1, [r4, #2]
	cmp r1, #7
	addeq sp, sp, #8
	ldmeqia sp!, {r4, pc}
	mov r1, #1
	bl ov1_0213F960
	mov r0, #0x28
	str r0, [r4, #0x120]
	str r0, [r4, #0x124]
	ldr r1, [r4, #8]
	ldr r0, [r4, #0xc]
	mov ip, #0
	str r1, [r4, #0x118]
	str r0, [r4, #0x11c]
	strh ip, [r4, #0x8e]
	str ip, [r4, #0x78]
	ldr r2, [r4, #8]
	ldr r3, [r4, #0xc]
	add r2, r2, #0x3b000
	str r2, [r4, #0x7c]
	add r2, r3, #0x5000
	str r2, [r4, #0x80]
	mov r2, #1
	strh r2, [r4, #0xda]
	str ip, [r4, #0xc4]
	ldr r2, [r4, #8]
	ldr r3, [r4, #0xc]
	add r2, r2, #0x3b000
	str r2, [r4, #0xc8]
	add r2, r3, #0x5000
	str r2, [r4, #0xcc]
	ldr r2, [r4, #8]
	ldr r3, [r4, #0xc]
	add r2, r2, #0x100000
	str r2, [r4, #0x2c]
	str r1, [sp]
	str r0, [sp, #4]
	str r3, [r4, #0x30]
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F8B4Ev

	arm_func_start ov1_0213F960
ov1_0213F960: ; 0x0213F960
	mov r2, #0
	strh r2, [r0]
	str r1, [r0, #4]
	bx lr
	arm_func_end ov1_0213F960

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F970Ei
_ZN17UnkClass_0213F02812ov1_0213F970Ei: ; 0x0213F970
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #0x100
	mov r4, r1
	ldrh r1, [r0, #0x2a]
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r4, r4, r0
	str r4, [r5, #0x104]
	ldrh r1, [r5, #0x3e]
	add r0, r5, #0x14
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r4, r4, r0
	str r4, [r5, #0x18]
	ldrh r1, [r5, #0x8e]
	add r0, r5, #0x64
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r4, r4, r0
	str r4, [r5, #0x68]
	ldrh r1, [r5, #0xda]
	add r0, r5, #0xb0
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r4, r0
	str r0, [r5, #0xb4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F970Ei

	arm_func_start _ZN17UnkClass_0213F9D0C1EPKcS1_
_ZN17UnkClass_0213F9D0C1EPKcS1_: ; 0x0213F9D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213F9F8
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F9D0C1EPKcS1_

	arm_func_start _ZN17UnkClass_0213F9D0D1Ev
_ZN17UnkClass_0213F9D0D1Ev: ; 0x0213F9E4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213FB4C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F9D0D1Ev

	arm_func_start ov1_0213F9F8
ov1_0213F9F8: ; 0x0213F9F8
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	mov r7, r0
	mov r0, #0xb8
	mov r5, r1
	mov r6, r2
	bl _Znwm
	movs r4, r0
	beq _0213FA3C
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r5
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	mov r4, r0
	arm_func_end ov1_0213F9F8
_0213FA3C:
	mov r0, #0xb8
	bl _Znwm
	movs r5, r0
	beq _0213FA6C
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r6
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	mov r5, r0
_0213FA6C:
	ldr r0, [r5, #0x50]
	mov r1, #0
	mov r0, r0, lsr #1
	bic r3, r0, #7
	ldr r0, [r4, #0x50]
	mov r2, r1
	add r6, r3, #8
	bl NNS_GfdAllocLnkTexVram
	mov r1, #0
	mov r6, r6, lsl #1
	str r0, [r7]
	mov r0, r6
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r7, #4]
	ldr r0, [r7]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0xd
	str r0, [r7, #8]
	ldr r0, [r7, #4]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0xd
	str r0, [r7, #0xc]
	ldr r0, [r5, #0x4c]
	ldr r1, [r5, #0x50]
	bl DC_FlushRange
	bl GX_BeginLoadTexPltt
	ldr r0, [r5, #0x4c]
	ldr r1, [r7, #0xc]
	mov r2, r6
	bl GX_LoadTexPltt
	bl GX_EndLoadTexPltt
	ldr r0, [r4, #0x4c]
	ldr r1, [r4, #0x50]
	bl DC_FlushRange
	bl GX_BeginLoadTex
	ldr r1, [r7, #8]
	ldr r0, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	bl GX_LoadTex
	bl GX_EndLoadTex
	cmp r4, #0
	beq _0213FB28
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213FB28:
	cmp r5, #0
	addeq sp, sp, #0xc
	ldmeqia sp!, {r4, r5, r6, r7, pc}
	mov r0, r5
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}

	arm_func_start ov1_0213FB4C
ov1_0213FB4C: ; 0x0213FB4C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl NNS_GfdFreeLnkTexVram
	ldr r0, [r4, #4]
	bl NNS_GfdFreeLnkPlttVram
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213FB4C

    .rodata

    .section .sinit,4 ; 0x02140734

    .data

    .global s_BGU_overlay_1_02141f74
s_BGU_overlay_1_02141f74: ; 0x02141F74
	.asciz "BGU"

    .global s_data_menu_pam001_bg_LZ_bin_overlay_1_02141f78
s_data_menu_pam001_bg_LZ_bin_overlay_1_02141f78: ; 0x02141F78
	.asciz "data/menu/pam001_bg_LZ.bin"

    .global DAT_overlay_1_02141F93
DAT_overlay_1_02141F93:
	.byte 0x00

    .global s_BGU_pam001_NCGR_overlay_1_02141f94
s_BGU_pam001_NCGR_overlay_1_02141f94: ; 0x02141F94
	.asciz "BGU:pam001.NCGR"

    .global s_BGU_pam_03d_NCLR_overlay_1_02141fa4
s_BGU_pam_03d_NCLR_overlay_1_02141fa4: ; 0x02141FA4
	.asciz "BGU:pam%03d.NCLR"

    .global DAT_overlay_1_02141FB5
DAT_overlay_1_02141FB5:
	.byte 0x00, 0x00, 0x00

    .global s_BGU_pam001_00_NSCR_overlay_1_02141fb8
s_BGU_pam001_00_NSCR_overlay_1_02141fb8: ; 0x02141FB8
	.asciz "BGU:pam001_00.NSCR"

    .global DAT_overlay_1_02141FCB
DAT_overlay_1_02141FCB:
	.byte 0x00

    .global s_data_menu_pam000_bg_LZ_bin_overlay_1_02141fcc
s_data_menu_pam000_bg_LZ_bin_overlay_1_02141fcc: ; 0x02141FCC
	.asciz "data/menu/pam000_bg_LZ.bin"

    .global DAT_overlay_1_02141FE7
DAT_overlay_1_02141FE7:
	.byte 0x00

    .global s_BGU_pam000_NCGR_overlay_1_02141fe8
s_BGU_pam000_NCGR_overlay_1_02141fe8: ; 0x02141FE8
	.asciz "BGU:pam000.NCGR"

    .global s_BGU_pam000_01_NSCR_overlay_1_02141ff8
s_BGU_pam000_01_NSCR_overlay_1_02141ff8: ; 0x02141FF8
	.asciz "BGU:pam000_01.NSCR"

    .global DAT_overlay_1_0214200B
DAT_overlay_1_0214200B:
	.byte 0x00

    .global s_BGU_pam000_02_NSCR_overlay_1_0214200c
s_BGU_pam000_02_NSCR_overlay_1_0214200c: ; 0x0214200C
	.asciz "BGU:pam000_02.NSCR"

    .global DAT_overlay_1_0214201F
DAT_overlay_1_0214201F:
	.byte 0x00

    .global s_data_message_etc_menu_mes_overlay_1_02142020
s_data_message_etc_menu_mes_overlay_1_02142020: ; 0x02142020
	.asciz "/data/message/etc/menu_mes"

    .global DAT_overlay_1_0214203B
DAT_overlay_1_0214203B:
	.byte 0x00

    .global s_data_message_etc_assist_mes_overlay_1_0214203c
s_data_message_etc_assist_mes_overlay_1_0214203c: ; 0x0214203C
	.asciz "/data/message/etc/assist_mes"

    .global DAT_overlay_1_02142059
DAT_overlay_1_02142059:
	.byte 0x00, 0x00, 0x00

    .global s_data_message_etc_fieldwaza_name_overlay_1_0214205c
s_data_message_etc_fieldwaza_name_overlay_1_0214205c: ; 0x0214205C
	.asciz "/data/message/etc/fieldwaza_name"

    .global DAT_overlay_1_0214207D
DAT_overlay_1_0214207D:
	.byte 0x00, 0x00, 0x00

    .global s_bp_03d_overlay_1_02142080
s_bp_03d_overlay_1_02142080: ; 0x02142080
	.asciz "bp%03d"

    .global DAT_overlay_1_02142087
DAT_overlay_1_02142087:
	.byte 0x00

    .global s_data_pokeOBJ_overlay_1_02142088
s_data_pokeOBJ_overlay_1_02142088: ; 0x02142088
	.asciz "data/pokeOBJ"

    .global DAT_overlay_1_02142095
DAT_overlay_1_02142095:
	.byte 0x00, 0x00, 0x00

    .global s_data_menu_overlay_1_02142098
s_data_menu_overlay_1_02142098: ; 0x02142098
	.asciz "data/menu"

    .global DAT_overlay_1_021420A2
DAT_overlay_1_021420A2:
	.byte 0x00, 0x00

    .global s_pam003_00_overlay_1_021420a4
s_pam003_00_overlay_1_021420a4: ; 0x021420A4
	.asciz "pam003_00"

    .global DAT_overlay_1_021420AE
DAT_overlay_1_021420AE:
	.byte 0x00, 0x00

    .global s_pam001_00_overlay_1_021420b0
s_pam001_00_overlay_1_021420b0: ; 0x021420B0
	.asciz "pam001_00"

    .global DAT_overlay_1_021420BA
DAT_overlay_1_021420BA:
	.byte 0x00, 0x00

    .global s_pam002_00_overlay_1_021420bc
s_pam002_00_overlay_1_021420bc: ; 0x021420BC
	.asciz "pam002_00"

    .global DAT_overlay_1_021420C6
DAT_overlay_1_021420C6:
	.byte 0x00, 0x00

    .global s_ma000_00_overlay_1_021420c8
s_ma000_00_overlay_1_021420c8: ; 0x021420C8
	.asciz "ma000_00"

    .global DAT_overlay_1_021420D1
DAT_overlay_1_021420D1:
	.byte 0x00, 0x00, 0x00

    .global s_ma001_00_overlay_1_021420d4
s_ma001_00_overlay_1_021420d4: ; 0x021420D4
	.asciz "ma001_00"

    .global DAT_overlay_1_021420DD
DAT_overlay_1_021420DD:
	.byte 0x00, 0x00, 0x00

    .global s_data_interface_i_03d_LZ_bin_overlay_1_021420e0
s_data_interface_i_03d_LZ_bin_overlay_1_021420e0: ; 0x021420E0
	.asciz "data/interface/i%03d_LZ.bin"

    .global s_BCO_i_03d_00_NCBR_overlay_1_021420fc
s_BCO_i_03d_00_NCBR_overlay_1_021420fc: ; 0x021420FC
	.asciz "BCO:i%03d_00.NCBR"

    .global DAT_overlay_1_0214210E
DAT_overlay_1_0214210E:
	.byte 0x00, 0x00

    .global s_BCO_i_03d_NCLR_overlay_1_02142110
s_BCO_i_03d_NCLR_overlay_1_02142110: ; 0x02142110
	.asciz "BCO:i%03d.NCLR"

    .global DAT_overlay_1_0214211F
DAT_overlay_1_0214211F:
	.byte 0x00

    .global s_BCO_i_03d_00_NCER_overlay_1_02142120
s_BCO_i_03d_00_NCER_overlay_1_02142120: ; 0x02142120
	.asciz "BCO:i%03d_00.NCER"

    .global DAT_overlay_1_02142132
DAT_overlay_1_02142132:
	.byte 0x00, 0x00

    .global s_BCO_i_03d_00_cac_overlay_1_02142134
s_BCO_i_03d_00_cac_overlay_1_02142134: ; 0x02142134
	.asciz "BCO:i%03d_00.cac"

    .global DAT_overlay_1_02142145
DAT_overlay_1_02142145:
	.byte 0x00, 0x00, 0x00

    .global s_BCO_overlay_1_02142148
s_BCO_overlay_1_02142148: ; 0x02142148
	.asciz "BCO"

    .global s_data_interface_i055_LZ_bin_overlay_1_0214214c
s_data_interface_i055_LZ_bin_overlay_1_0214214c: ; 0x0214214C
	.asciz "data/interface/i055_LZ.bin"

    .global DAT_overlay_1_02142167
DAT_overlay_1_02142167:
	.byte 0x00

    .global s_BCO_i055_00_NCBR_overlay_1_02142168
s_BCO_i055_00_NCBR_overlay_1_02142168: ; 0x02142168
	.asciz "BCO:i055_00.NCBR"

    .global DAT_overlay_1_02142179
DAT_overlay_1_02142179:
	.byte 0x00, 0x00, 0x00

    .global s_BCO_i055_NCLR_overlay_1_0214217c
s_BCO_i055_NCLR_overlay_1_0214217c: ; 0x0214217C
	.asciz "BCO:i055.NCLR"

    .global DAT_overlay_1_0214218A
DAT_overlay_1_0214218A:
	.byte 0x00, 0x00

    .global s_BCO_i055_00_NCER_overlay_1_0214218c
s_BCO_i055_00_NCER_overlay_1_0214218c: ; 0x0214218C
	.asciz "BCO:i055_00.NCER"

    .global DAT_overlay_1_0214219D
DAT_overlay_1_0214219D:
	.byte 0x00, 0x00, 0x00

    .global s_data_interface_i056_LZ_bin_overlay_1_021421a0
s_data_interface_i056_LZ_bin_overlay_1_021421a0: ; 0x021421A0
	.asciz "data/interface/i056_LZ.bin"

    .global DAT_overlay_1_021421BB
DAT_overlay_1_021421BB:
	.byte 0x00

    .global s_BCO_i056_00_NCBR_overlay_1_021421bc
s_BCO_i056_00_NCBR_overlay_1_021421bc: ; 0x021421BC
	.asciz "BCO:i056_00.NCBR"

    .global DAT_overlay_1_021421CD
DAT_overlay_1_021421CD:
	.byte 0x00, 0x00, 0x00

    .global s_BCO_i056_NCLR_overlay_1_021421d0
s_BCO_i056_NCLR_overlay_1_021421d0: ; 0x021421D0
	.asciz "BCO:i056.NCLR"

    .global DAT_overlay_1_021421DE
DAT_overlay_1_021421DE:
	.byte 0x00, 0x00

    .global s_BCO_i056_00_NCER_overlay_1_021421e0
s_BCO_i056_00_NCER_overlay_1_021421e0: ; 0x021421E0
	.asciz "BCO:i056_00.NCER"

    .global DAT_overlay_1_021421F1
DAT_overlay_1_021421F1:
	.byte 0x00, 0x00, 0x00

    .global s_system_000_overlay_1_021421f4
s_system_000_overlay_1_021421f4: ; 0x021421F4
	.asciz "system_000"
	; 0x021421FF

    .bss

    .global OVERLAY1_BSS_02142200
OVERLAY1_BSS_02142200: ; 0x02142200
    .space 0x20
