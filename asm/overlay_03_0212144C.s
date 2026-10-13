    .include "macros.inc"
    .include "include/overlay_03_0212144C.inc"

    .text

	arm_func_start _ZN10CConfSceneC1EP5CGame
_ZN10CConfSceneC1EP5CGame: ; 0x0212144C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN6CSceneC2Ev
	ldr r0, _02121494 ; =PTR_LAB_overlay_3_02121498_overlay_3_0212aa08
	str r0, [r5]
	str r4, [r5, #8]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	str r0, [r5, #4]
	bl _ZN17UnkClass_0203447812sub_020345D4Ev
	mov r0, #0x1000
	str r0, [r5, #0x18]
	mov r1, #0
	mov r0, r5
	strh r1, [r5, #0xe]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02121494: .word PTR_LAB_overlay_3_02121498_overlay_3_0212aa08
	arm_func_end _ZN10CConfSceneC1EP5CGame

	arm_func_start ov3_02121498
ov3_02121498: ; 0x02121498
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN6CSceneD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_02121498

	arm_func_start ov3_021214AC
ov3_021214AC: ; 0x021214AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN6CSceneD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_021214AC

	arm_func_start ov3_021214C8
ov3_021214C8: ; 0x021214C8
	stmdb sp!, {r3, lr}
	bl GX_ResetBankForBG
	bl GX_ResetBankForOBJ
	bl GX_ResetBankForBGExtPltt
	bl GX_ResetBankForOBJExtPltt
	bl GX_ResetBankForTex
	bl GX_ResetBankForTexPltt
	bl GX_ResetBankForClearImage
	bl GX_ResetBankForSubBG
	bl GX_ResetBankForSubOBJ
	bl GX_ResetBankForSubBGExtPltt
	bl GX_ResetBankForSubOBJExtPltt
	bl GX_ResetBankForARM7
	mov r0, #0xf
	bl GX_SetBankForTex
	mov r0, #0x40
	bl GX_SetBankForTexPltt
	mov r0, #0x10
	bl GX_SetBankForOBJ
	mov r0, #0x20
	bl GX_SetBankForBG
	mov r0, #1
	mov r1, #0
	mov r2, r0
	bl GX_SetGraphicsMode
	ldr r2, _0212165C ; =0x04000008
	mov r0, #0x80
	ldrh r1, [r2]
	bic r1, r1, #3
	orr r1, r1, #3
	strh r1, [r2]
	ldrh r1, [r2, #2]
	bic r1, r1, #3
	orr r1, r1, #2
	strh r1, [r2, #2]
	ldrh r1, [r2, #4]
	bic r1, r1, #3
	orr r1, r1, #1
	strh r1, [r2, #4]
	ldrh r1, [r2, #6]
	bic r1, r1, #3
	strh r1, [r2, #6]
	bl GX_SetBankForSubBG
	mov r0, #0x100
	bl GX_SetBankForSubOBJ
	ldr r1, _02121660 ; =0x04001008
	ldrh r0, [r1]
	bic r0, r0, #3
	orr r0, r0, #3
	strh r0, [r1]
	ldrh r0, [r1, #2]
	bic r0, r0, #3
	orr r0, r0, #2
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	bic r0, r0, #3
	orr r0, r0, #1
	strh r0, [r1, #4]
	ldrh r0, [r1, #6]
	bic r0, r0, #3
	strh r0, [r1, #6]
	mov r1, #0
	ldr r0, _02121664 ; =0x04000050
	mov r2, r1
	mov r3, r1
	str r1, [sp]
	bl G2x_SetBlendAlpha_
	ldr lr, _02121668 ; =0x04000060
	mov r2, #0x4000000
	ldrh r1, [lr]
	add ip, lr, #0x2a4
	ldr r0, _0212166C ; =0xFFFFFDF1
	bic r1, r1, #0x3000
	orr r1, r1, #8
	strh r1, [lr]
	ldrh r3, [lr]
	add r1, r2, #0x1000
	bic r3, r3, #0x3000
	orr r3, r3, #0x10
	strh r3, [lr]
	ldrh r3, [ip]
	and r0, r3, r0
	orr r0, r0, #0xe
	orr r0, r0, #0x200
	strh r0, [ip]
	ldrh r0, [ip]
	orr r0, r0, #0x8000
	strh r0, [ip]
	ldr r0, [r2]
	bic r0, r0, #0x1f00
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x200
	str r0, [r1]
	bl GX_DispOn
	ldr r1, _02121670 ; =0x04001000
	ldr r0, [r1]
	orr r0, r0, #0x10000
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212165C: .word 0x04000008
_02121660: .word 0x04001008
_02121664: .word 0x04000050
_02121668: .word 0x04000060
_0212166C: .word 0xFFFFFDF1
_02121670: .word 0x04001000
	arm_func_end ov3_021214C8

	arm_func_start ov3_02121674
ov3_02121674: ; 0x02121674
	ldr r0, _021216A4 ; =0x04001010
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	sub r1, r0, #6
	ldrh r0, [r1]
	and r0, r0, #0x43
	orr r0, r0, #0xd00
	strh r0, [r1]
	bx lr
	.align 2, 0
_021216A4: .word 0x04001010
	arm_func_end ov3_02121674

	arm_func_start ov3_021216A8
ov3_021216A8: ; 0x021216A8
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x30
	ldr lr, _02121768 ; =DAT_overlay_3_0212a250
	add ip, sp, #0x14
	mov r4, r0
	ldmia lr!, {r0, r1, r2, r3}
	stmia ip!, {r0, r1, r2, r3}
	ldmia lr, {r0, r1, r2}
	stmia ip, {r0, r1, r2}
	ldr r0, [r4, #8]
	add r0, r0, #0x1000
	ldr r5, [r0, #0x498]
	mov r0, r5
	bl _ZN17UnkClass_0200CAB412sub_0200CAE0Ev
	mov r0, r5
	bl _ZN17UnkClass_0200CAB412sub_0200CB14Ev
	mov r0, r5
	mov r1, #1
	bl _ZN17UnkClass_0200CAB412sub_0200CC88Ei
	ldr r1, [sp, #0x1c]
	mov r0, #0x20
	str r1, [sp]
	ldr r2, [sp, #0x20]
	mov r1, #0
	str r2, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r2, [sp, #0x14]
	ldr r3, [sp, #0x18]
	mov r0, r5
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	ldr r2, [sp, #0x2c]
	mov r1, #0
	str r2, [sp]
	ldr r2, [r4, #0x2c]
	mov r0, r5
	ldr r2, [r2, #8]
	ldr r2, [r2, #0x134]
	str r2, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02121768: .word DAT_overlay_3_0212a250
	arm_func_end ov3_021216A8

	arm_func_start ov3_0212176C
ov3_0212176C: ; 0x0212176C
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	mov r7, r0
	bl ov3_02121674
	mov r0, #0x64
	bl _Znwm
	cmp r0, #0
	beq _02121794
	ldr r1, [r7, #8]
	bl _ZN17UnkClass_0201FC80C1Ei
	arm_func_end ov3_0212176C
_02121794:
	str r0, [r7, #0x1c]
	mov r1, #5
	bl _ZN17UnkClass_0201FC805SetBGEi
	ldr r0, [r7, #0x1c]
	ldr r1, _021219A8 ; =s_menu_overlay_3_0212aa34
	ldr r2, _021219AC ; =s_title004_bg_overlay_3_0212aa3c
	bl _ZN17UnkClass_0201FC8011LoadArchiveEPKcS1_
	mov r2, #0
	str r2, [sp]
	ldr r0, [r7, #0x1c]
	ldr r1, _021219B0 ; =s_title004_overlay_3_0212aa4c
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadCharEPKcimm
	mov r2, #0
	str r2, [sp]
	ldr r0, [r7, #0x1c]
	ldr r1, _021219B0 ; =s_title004_overlay_3_0212aa4c
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadPlttEPKcimm
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r7, #0x1c]
	ldr r1, _021219B4 ; =s_title004_00_overlay_3_0212aa58
	mov r3, r2
	bl _ZN17UnkClass_0201FC807LoadScrEPKcimmmm
	ldr r0, [r7, #0x1c]
	bl _ZN17UnkClass_0201FC8014ReleaseArchiveEv
	mov r1, #0x100
	ldr r0, [r7, #0x1c]
	mov r2, r1
	bl _ZN17UnkClass_0201FC805SetupEii
	ldr r0, [r7, #0x1c]
	bl _ZN17UnkClass_0201FC8010LoadToVramEv
	mov r0, #0xb8
	bl _Znwm
	movs r6, r0
	beq _02121840
	ldr r1, _021219B8 ; =s_data_message_etc_menu_mes_overlay_3_0212aa64
	mov r2, #1
	bl _ZN14CBinaryFileMesC1EPKcm
	mov r6, r0
_02121840:
	mov r0, #0xc
	bl _Znwm
	str r0, [r7, #0x2c]
	ldr r1, [r6, #0x4c]
	mov r4, #2
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r6, #0x4c]
	ldr r0, [r7, #0x2c]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	ldr r0, [r7, #0x2c]
	ldr r0, [r0, #4]
	mov r0, r0, lsl #3
	bl _Znam
	ldr r1, [r7, #0x2c]
	mov r5, #0
	str r0, [r1, #8]
	ldr r2, [r7, #0x2c]
	ldr r0, [r2, #4]
	cmp r0, #0
	bls _02121908
_02121898:
	ldr r1, [r6, #0x4c]
	ldr r0, [r2, #8]
	ldr r1, [r1, r4, lsl #2]
	add r4, r4, #1
	str r1, [r0, r5, lsl #3]
	ldr r0, [r7, #0x2c]
	ldr r0, [r0, #8]
	ldr r0, [r0, r5, lsl #3]
	bl _Znam
	ldr r1, [r7, #0x2c]
	ldr r1, [r1, #8]
	add r1, r1, r5, lsl #3
	str r0, [r1, #4]
	ldr r1, [r7, #0x2c]
	ldr r0, [r6, #0x4c]
	ldr r2, [r1, #8]
	add r0, r0, r4, lsl #2
	add r1, r2, r5, lsl #3
	ldr r1, [r1, #4]
	ldr r2, [r2, r5, lsl #3]
	bl MIi_CpuCopyFast
	ldr r2, [r7, #0x2c]
	ldmib r2, {r0, r1}
	ldr r1, [r1, r5, lsl #3]
	add r5, r5, #1
	cmp r5, r0
	add r4, r4, r1, lsr #2
	blo _02121898
_02121908:
	cmp r6, #0
	beq _02121920
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02121920:
	mov r0, r7
	bl ov3_021216A8
	mov r0, r7
	bl ov3_021219BC
	mov r0, r7
	bl ov3_02121A28
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _0212194C
	bl _ZN16CPrimitiveSPHEREC1Ev
_0212194C:
	mov r1, #0x20000
	str r0, [r7, #0x30]
	str r1, [r0, #0x20]
	sub r0, r1, #0x60000
	ldr r2, [r7, #0x30]
	sub r1, r1, #0x40000
	str r0, [r2, #0x18]
	mov r0, #0x24
	str r1, [r2, #0x1c]
	bl _Znwm
	cmp r0, #0
	beq _02121980
	bl _ZN16CPrimitiveSPHEREC1Ev
_02121980:
	str r0, [r7, #0x34]
	mov r1, #0x20000
	str r1, [r0, #0x20]
	mov r1, #0x40000
	ldr r2, [r7, #0x34]
	sub r0, r1, #0x60000
	str r1, [r2, #0x18]
	str r0, [r2, #0x1c]
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_021219A8: .word s_menu_overlay_3_0212aa34
_021219AC: .word s_title004_bg_overlay_3_0212aa3c
_021219B0: .word s_title004_overlay_3_0212aa4c
_021219B4: .word s_title004_00_overlay_3_0212aa58
_021219B8: .word s_data_message_etc_menu_mes_overlay_3_0212aa64

	arm_func_start ov3_021219BC
ov3_021219BC: ; 0x021219BC
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _021219FC
	ldr r3, [r4, #8]
	mov r1, #0x40
	str r1, [sp]
	add r2, r3, #0x1000
	add r1, r3, #0xe4
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end ov3_021219BC
_021219FC:
	str r0, [r4, #0x28]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4, #0x28]
	ldr r1, _02121A20 ; =s_data_menu_overlay_3_0212aa80
	ldr r2, _02121A24 ; =s_title003_00_overlay_3_0212aa8c
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02121A20: .word s_data_menu_overlay_3_0212aa80
_02121A24: .word s_title003_00_overlay_3_0212aa8c

	arm_func_start ov3_02121A28
ov3_02121A28: ; 0x02121A28
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r1, #0
	mov r4, r0
	str r1, [sp]
	ldr r0, [r4, #0x28]
	mov r2, #0x40
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r4, #0x20]
	ldr r1, [r4, #0x28]
	mov r0, #0
	ldr r2, [r1, #0x24]
	mov r1, #1
	str r2, [r4, #0x10]
	str r0, [sp]
	ldr r0, [r4, #0x28]
	mov r2, #0xc0
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x28]
	ldr r0, [r0, #0x24]
	str r0, [r4, #0x14]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	arm_func_end ov3_02121A28

	arm_func_start ov3_02121A90
ov3_02121A90: ; 0x02121A90
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r5, [r4, #0x1c]
	cmp r5, #0
	beq _02121AC0
	beq _02121AB8
	mov r0, r5
	bl _ZN17UnkClass_0201FC80D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov3_02121A90
_02121AB8:
	mov r0, #0
	str r0, [r4, #0x1c]
_02121AC0:
	ldr r5, [r4, #0x28]
	cmp r5, #0
	beq _02121AE8
	beq _02121AE0
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_02121AE0:
	mov r0, #0
	str r0, [r4, #0x28]
_02121AE8:
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _02121B00
	bl _ZdlPv
	mov r0, #0
	str r0, [r4, #0x2c]
_02121B00:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _02121B24
	beq _02121B1C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02121B1C:
	mov r0, #0
	str r0, [r4, #0x30]
_02121B24:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _02121B40
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02121B40:
	mov r0, #0
	str r0, [r4, #0x34]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov3_02121B4C
ov3_02121B4C: ; 0x02121B4C
	ldr r0, [r0, #8]
	mov r1, r1, lsl #0xc
	add r0, r0, #0x44
	add r2, r0, #0x400
	mov r1, r1, asr #0x10
	strh r1, [r2, #6]
	mov r0, #0
	strh r0, [r2, #0xe]
	strh r0, [r2, #0x16]
	strh r1, [r2, #0x1e]
	bx lr
	arm_func_end ov3_02121B4C

	arm_func_start ov3_02121B78
ov3_02121B78: ; 0x02121B78
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0xc
	mov r5, r0
	ldr r1, [r5, #0x18]
	mvn r4, #0
	bl ov3_02121B4C
	ldr r0, [r5, #0x28]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldr r1, [r5, #8]
	ldr r0, [r1, #0x14]
	ldr r3, [r1, #0x18]
	ldrh r0, [r0, #2]
	ldrh r2, [r3, #0xa]
	ldrh r1, [r3, #0xc]
	and r0, r0, #1
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	ldrh r0, [r5, #0xc]
	movne r4, #0x22
	sub r2, r2, #0x80
	tst r0, #3
	sub r0, r1, #0x80
	mov r1, r2, lsl #0xc
	mov r0, r0, lsl #0xc
	str r1, [sp, #4]
	str r0, [sp, #8]
	beq _02121C24
	ldrh r0, [r5, #0xe]
	add r0, r0, #1
	strh r0, [r5, #0xe]
	ldrh r0, [r5, #0xe]
	cmp r0, #0x10
	blo _02121C10
	ldrh r0, [r5, #0xc]
	tst r0, #2
	mov r0, #0
	movne r4, #0xe
	strh r0, [r5, #0xe]
	arm_func_end ov3_02121B78
_02121C10:
	ldrh r0, [r5, #0xe]
	cmp r0, #2
	moveq r0, #0x1000
	streq r0, [r5, #0x18]
	b _02121D00
_02121C24:
	ldrb r0, [r3, #4]
	cmp r0, #0
	beq _02121D00
	ldr r0, [r5, #0x30]
	add ip, sp, #4
	add r0, r0, #0x18
	sub r3, sp, #8
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldmia r3, {r2, r3}
	ldmia ip, {r0, r1}
	bl _Z12sub_020061007Point2D6Circle
	cmp r0, #0
	beq _02121C98
	mov r0, #0x1400
	str r0, [r5, #0x18]
	ldr r0, [r5, #0x20]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	ldr r0, [r5, #0x24]
	mov r1, #0
	str r1, [r0, #0x14]
	ldrh r0, [r5, #0xc]
	mov r1, #0xff
	orr r0, r0, #1
	strh r0, [r5, #0xc]
	ldr r0, [r5, #4]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
_02121C98:
	ldr r0, [r5, #0x34]
	add ip, sp, #4
	add r0, r0, #0x18
	sub r3, sp, #8
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldmia r3, {r2, r3}
	ldmia ip, {r0, r1}
	bl _Z12sub_020061007Point2D6Circle
	cmp r0, #0
	beq _02121D00
	mov r0, #0x1400
	str r0, [r5, #0x18]
	ldr r0, [r5, #0x24]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	ldr r0, [r5, #0x20]
	mov r1, #0
	str r1, [r0, #0x14]
	ldrh r0, [r5, #0xc]
	mov r1, #0x100
	orr r0, r0, #2
	strh r0, [r5, #0xc]
	ldr r0, [r5, #4]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
_02121D00:
	mov r0, r4
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, pc}

	arm_func_start ov3_02121D0C
ov3_02121D0C: ; 0x02121D0C
	bx lr
	arm_func_end ov3_02121D0C

	arm_func_start ov3_02121D10
ov3_02121D10: ; 0x02121D10
	ldr ip, _02121D1C ; =FUN_0200F71C
	ldr r0, [r0, #0x28]
	bx ip
	.align 2, 0
_02121D1C: .word _ZN17UnkClass_0200ECD012sub_0200F71CEv
	arm_func_end ov3_02121D10

	arm_func_start ov3_02121D20
ov3_02121D20: ; 0x02121D20
	mov r0, #0xf
	bx lr
	arm_func_end ov3_02121D20
