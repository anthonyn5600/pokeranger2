    .include "macros.inc"
    .include "include/overlay_00_0215994C.inc"

    .text

	arm_func_start _ZN17UnkClass_0215994CC1Ev
_ZN17UnkClass_0215994CC1Ev: ; 0x0215994C
	mov r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	bx lr
	arm_func_end _ZN17UnkClass_0215994CC1Ev

	arm_func_start _ZN17UnkClass_0215994CD1Ev
_ZN17UnkClass_0215994CD1Ev: ; 0x0215995C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov0_02159D70
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0215994CD1Ev

	arm_func_start ov0_02159970
ov0_02159970: ; 0x02159970
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x30
	ldr r1, _02159B1C ; =MAIN_BSS_020B26A0+32768
	mov sl, r0
	ldr r0, [r1, #0x1b0]
	ldr fp, _02159B20 ; =MAIN_BSS_020B26A0
	cmp r0, #6
	addne sp, sp, #0x30
	ldmneia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r6, #0x20
	add r4, fp, #0x8000
	mov r5, #1
	arm_func_end ov0_02159970
_021599A0:
	mov r2, #0
	mov r8, r2
	cmp r6, #0x20
	ble _021599D8
	sub r3, r6, #0x20
	mov r1, r3, lsr #0x1f
	mov r0, r3, asr #1
	add r0, r3, r0, lsr #30
	mov r0, r0, lsl #0xe
	mov r2, r0, lsr #0x10
	rsb r0, r1, r3, lsl #30
	add r0, r1, r0, ror #30
	mov r0, r0, lsl #0x10
	mov r8, r0, lsr #0x10
_021599D8:
	mov r0, r6, lsl #0x16
	add r1, fp, r0, lsr #20
	add r0, r1, #0x1b4
	add r3, r0, #0x8000
	add r0, r1, #0x8000
	ldr r0, [r0, #0x1b4]
	tst r0, #1
	movne r1, #1
	moveq r1, #0
	cmp r1, #0
	beq _02159B08
	mov r0, r0, lsr #1
	and r0, r0, #0x7f
	cmp r0, #6
	bne _02159B08
	mov r0, #0
	strh r0, [sp, #0x16]
	strh r0, [sp, #0x1e]
	mov r0, #0x10000
	str r0, [sp, #0x2c]
	add r0, fp, r6, lsl #1
	add r1, r0, #0x8600
	ldrh r7, [r1, #0x16]
	ldr r3, [r3]
	ldrh sb, [r1, #0xb6]
	mov r1, r3, lsr #0x14
	strh r1, [sp, #0x1a]
	mov r1, r3, lsr #0xc
	strh r7, [sp, #0x10]
	and r7, r1, #0xff
	mov r1, sb, asr #8
	and r1, r1, #0xff
	strh r1, [sp, #0x14]
	and r1, sb, #0xff
	strh r1, [sp, #0x18]
	add r1, r0, #0x8500
	ldrh sb, [r1, #0x76]
	add r1, r0, #0x36
	add r3, r1, #0x8400
	mov r1, sb, lsl #0xc
	add r0, r0, #0x8400
	str r1, [sp, #0x20]
	ldrsh r1, [r0, #0x36]
	ldrsh r0, [r3, #0xa0]
	strh r5, [sp, #0x1c]
	mov r1, r1, lsl #0xc
	mov r0, r0, lsl #0xc
	str r1, [sp, #0x24]
	str r0, [sp, #4]
	str r0, [sp, #0xc]
	str r0, [sp, #0x28]
	ldrh r0, [sl]
	str r1, [sp]
	str r1, [sp, #8]
	tst r0, r5, lsl r2
	beq _02159AC8
	mov r1, r2
	mov r0, sl
	bl ov0_02159DFC
	b _02159AE4
_02159AC8:
	ldrb r1, [r4, #0x434]
	mov r0, sl
	mov r3, r5
	bl ov0_02159B84
	mov r1, r0
	mov r0, sl
	bl ov0_02159DFC
_02159AE4:
	mov sb, r0
	mov r2, r7
	mov r3, r8
	mov r0, sb
	add r1, sp, #0x10
	bl ov0_0215A434
	mov r0, sb
	mov r1, #1
	bl ov0_0215A384
_02159B08:
	add r6, r6, #1
	cmp r6, #0x50
	blt _021599A0
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02159B1C: .word MAIN_BSS_020B26A0+32768
_02159B20: .word MAIN_BSS_020B26A0

	arm_func_start ov0_02159B24
ov0_02159B24: ; 0x02159B24
	ldrh ip, [r0]
	mov r3, #0
	mov r2, #1
	arm_func_end ov0_02159B24
_02159B30:
	tst ip, r2, lsl r3
	beq _02159B48
	ldrh r1, [r0, #2]
	tst r1, r2, lsl r3
	moveq r0, r3
	bxeq lr
_02159B48:
	add r3, r3, #1
	cmp r3, #0xa
	blt _02159B30
	mvn r0, #0
	bx lr

	arm_func_start ov0_02159B5C
ov0_02159B5C: ; 0x02159B5C
	ldrh r2, [r0]
	mov r0, #0
	mov r1, #1
	arm_func_end ov0_02159B5C
_02159B68:
	tst r2, r1, lsl r0
	bxeq lr
	add r0, r0, #1
	cmp r0, #0xa
	blt _02159B68
	mvn r0, #0
	bx lr

	arm_func_start ov0_02159B84
ov0_02159B84: ; 0x02159B84
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r3
	mov r6, r0
	mov r5, r1
	mov r4, r2
	cmp r7, #1
	bne _02159C04
	ldr r1, _02159CA4 ; =MAIN_BSS_020B26A0+32768
	mov r0, #0x100
	strb r5, [r1, #0x434]
	bl _Znwm
	cmp r0, #0
	beq _02159BC4
	mov r1, r5, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02159E10
	arm_func_end ov0_02159B84
_02159BC4:
	cmp r0, #0
	mvneq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldrh r1, [r6]
	mov r2, #1
	tst r1, r2, lsl r4
	subne r0, r2, #2
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
	strh r4, [r0, #0xe4]
	add r1, r6, r4, lsl #2
	str r0, [r1, #4]
	ldrh r1, [r6]
	mov r0, r4
	orr r1, r1, r2, lsl r4
	strh r1, [r6]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_02159C04:
	bl ov0_02159B24
	cmp r7, #0
	mvneq r1, #0
	cmpeq r0, r1
	bne _02159C90
	ldr r1, _02159CA4 ; =MAIN_BSS_020B26A0+32768
	mov r0, #0x100
	strb r5, [r1, #0x434]
	bl _Znwm
	movs r4, r0
	beq _02159C40
	mov r1, r5, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02159E10
	mov r4, r0
_02159C40:
	cmp r4, #0
	mvneq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mov r0, r6
	bl ov0_02159B5C
	mvn r1, #0
	cmp r0, r1
	moveq r0, r1
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	strh r0, [r4, #0xe4]
	add r1, r6, r0, lsl #2
	str r4, [r1, #4]
	ldrh r1, [r6]
	mov r2, #1
	orr r1, r1, r2, lsl r0
	strh r1, [r6]
	ldrh r1, [r6, #2]
	orr r1, r1, r2, lsl r0
	strh r1, [r6, #2]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_02159C90:
	ldrh r2, [r6, #2]
	mov r1, #1
	orr r1, r2, r1, lsl r0
	strh r1, [r6, #2]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02159CA4: .word MAIN_BSS_020B26A0+32768

	arm_func_start ov0_02159CA8
ov0_02159CA8: ; 0x02159CA8
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, #0
	mov r4, r0
	strh r6, [r4]
	strh r6, [r4, #2]
	mov r5, r6
	arm_func_end ov0_02159CA8
_02159CC0:
	add r0, r4, r6, lsl #2
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02159CE8
	beq _02159CE0
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02159CE0:
	add r0, r4, r6, lsl #2
	str r5, [r0, #4]
_02159CE8:
	add r0, r6, #1
	mov r0, r0, lsl #0x10
	mov r6, r0, lsr #0x10
	cmp r6, #0xa
	blo _02159CC0
	ldr r0, _02159D2C ; =OVERLAY0_BSS_0217B380
	ldr r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	beq _02159D1C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02159D1C:
	ldr r0, _02159D2C ; =OVERLAY0_BSS_0217B380
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02159D2C: .word OVERLAY0_BSS_0217B380

	arm_func_start ov0_02159D30
ov0_02159D30: ; 0x02159D30
	stmdb sp!, {r4, lr}
	ldr r1, _02159D6C ; =OVERLAY0_BSS_0217B380
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, #0xec
	bl _Znwm
	cmp r0, #0
	beq _02159D60
	mov r1, r4
	bl ov0_0215A500
	arm_func_end ov0_02159D30
_02159D60:
	ldr r1, _02159D6C ; =OVERLAY0_BSS_0217B380
	str r0, [r1]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02159D6C: .word OVERLAY0_BSS_0217B380

	arm_func_start ov0_02159D70
ov0_02159D70: ; 0x02159D70
	ldr ip, _02159D78 ; =ov0_02159CA8
	bx ip
	.align 2, 0
_02159D78: .word ov0_02159CA8
	arm_func_end ov0_02159D70

	arm_func_start ov0_02159D7C
ov0_02159D7C: ; 0x02159D7C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, #0
	arm_func_end ov0_02159D7C
_02159D88:
	add r0, r5, r4, lsl #2
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02159D9C
	bl ov0_0215A010
_02159D9C:
	add r0, r4, #1
	mov r0, r0, lsl #0x10
	mov r4, r0, lsr #0x10
	cmp r4, #0xa
	blo _02159D88
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov0_02159DB4
ov0_02159DB4: ; 0x02159DB4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r6, r1
	mov r5, r2
	mov r4, #0
	arm_func_end ov0_02159DB4
_02159DC8:
	add r0, r7, r4, lsl #2
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02159DE4
	mov r1, r6
	mov r2, r5
	bl ov0_0215A25C
_02159DE4:
	add r0, r4, #1
	mov r0, r0, lsl #0x10
	mov r4, r0, lsr #0x10
	cmp r4, #0xa
	blo _02159DC8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov0_02159DFC
ov0_02159DFC: ; 0x02159DFC
	cmp r1, #0xa
	movge r0, #0
	addlt r0, r0, r1, lsl #2
	ldrlt r0, [r0, #4]
	bx lr
	arm_func_end ov0_02159DFC

	arm_func_start ov0_02159E10
ov0_02159E10: ; 0x02159E10
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN11CFieldActorC2Ev
	ldr r1, _02159E74 ; =PTR_LAB_overlay_0_02159e78_overlay_0_02178200
	mov r0, #0
	str r1, [r5]
	str r0, [r5, #0xec]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r2, #0
	str r0, [r5, #0xe8]
	mov r1, r2
	arm_func_end ov0_02159E10
_02159E48:
	add r0, r5, r2, lsl #2
	add r2, r2, #1
	str r1, [r0, #0xf0]
	cmp r2, #4
	blt _02159E48
	strh r4, [r5, #0xe2]
	mov r0, r5
	strh r1, [r5, #0xe0]
	bl ov0_02159ED0
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02159E74: .word PTR_LAB_overlay_0_02159e78_overlay_0_02178200

	arm_func_start _ZN12CFieldCannonD1Ev
_ZN12CFieldCannonD1Ev: ; 0x02159E78
	stmdb sp!, {r4, lr}
	ldr r1, _02159E9C ; =PTR_LAB_overlay_0_02159e78_overlay_0_02178200
	mov r4, r0
	str r1, [r4]
	bl ov0_02159F28
	mov r0, r4
	bl _ZN11CFieldActorD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02159E9C: .word PTR_LAB_overlay_0_02159e78_overlay_0_02178200
	arm_func_end _ZN12CFieldCannonD1Ev

	arm_func_start ov0_02159EA0
ov0_02159EA0: ; 0x02159EA0
	stmdb sp!, {r4, lr}
	ldr r1, _02159ECC ; =PTR_LAB_overlay_0_02159e78_overlay_0_02178200
	mov r4, r0
	str r1, [r4]
	bl ov0_02159F28
	mov r0, r4
	bl _ZN11CFieldActorD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02159ECC: .word PTR_LAB_overlay_0_02159e78_overlay_0_02178200
	arm_func_end ov0_02159EA0

	arm_func_start ov0_02159ED0
ov0_02159ED0: ; 0x02159ED0
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	bl ov0_02159F28
	mov r0, #0x20
	bl _Znwm
	str r0, [r6, #0xec]
	mov r0, r6
	bl ov0_02159F88
	mov r5, #0
	mov r4, #0xec
	arm_func_end ov0_02159ED0
_02159EF8:
	mov r0, r4
	bl _Znwm
	cmp r0, #0
	beq _02159F10
	ldrh r1, [r6, #0xe2]
	bl ov0_0215A500
_02159F10:
	add r1, r6, r5, lsl #2
	add r5, r5, #1
	str r0, [r1, #0xf0]
	cmp r5, #4
	blt _02159EF8
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov0_02159F28
ov0_02159F28: ; 0x02159F28
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r0, [r6, #0xec]
	cmp r0, #0
	beq _02159F48
	bl _ZdlPv
	mov r0, #0
	str r0, [r6, #0xec]
	arm_func_end ov0_02159F28
_02159F48:
	mov r5, #0
	mov r4, r5
_02159F50:
	add r0, r6, r5, lsl #2
	ldr r0, [r0, #0xf0]
	cmp r0, #0
	beq _02159F78
	beq _02159F70
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02159F70:
	add r0, r6, r5, lsl #2
	str r4, [r0, #0xf0]
_02159F78:
	add r5, r5, #1
	cmp r5, #4
	blt _02159F50
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov0_02159F88
ov0_02159F88: ; 0x02159F88
	stmdb sp!, {r3, lr}
	ldr r3, [r0, #0xec]
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	ldr r2, _0215A00C ; =0x00003A98
	mov r1, #0
	strh r2, [r3]
	ldr r2, [r0, #0xec]
	mov lr, #0x400
	strh r1, [r2, #2]
	ldr r2, [r0, #0xec]
	mov ip, #0x1000
	strh r1, [r2, #4]
	ldr r3, [r0, #0xec]
	mov r2, #0x10000
	strh r1, [r3, #6]
	ldr r3, [r0, #0xec]
	strh r1, [r3, #8]
	ldr r3, [r0, #0xec]
	strh r1, [r3, #0xa]
	ldr r3, [r0, #0xec]
	strh r1, [r3, #0xc]
	ldr r3, [r0, #0xec]
	strh lr, [r3, #0xe]
	ldr r3, [r0, #0xec]
	str ip, [r3, #0x10]
	ldr r3, [r0, #0xec]
	str r1, [r3, #0x14]
	ldr r3, [r0, #0xec]
	str r1, [r3, #0x18]
	ldr r0, [r0, #0xec]
	str r2, [r0, #0x1c]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0215A00C: .word 0x00003A98
	arm_func_end ov0_02159F88

	arm_func_start ov0_0215A010
ov0_0215A010: ; 0x0215A010
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xc
	mov sl, r0
	bl ov0_0215A3A4
	cmp r0, #0
	addeq sp, sp, #0xc
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, sl
	bl ov0_0215A2BC
	cmp r0, #0
	addne sp, sp, #0xc
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [sl, #0xec]
	ldrh r0, [r0, #0xc]
	tst r0, #4
	bne _0215A0DC
	ldrh r0, [sl, #0xe0]
	add r0, r0, #1
	strh r0, [sl, #0xe0]
	ldr r0, [sl, #0xec]
	ldrh r1, [sl, #0xe0]
	ldrh r0, [r0, #2]
	cmp r1, r0
	bne _0215A0DC
	mov r2, #0
	add r1, sp, #0
	mov r0, sl
	strh r2, [sp]
	bl ov0_0215A33C
	cmp r0, #0
	beq _0215A0D4
	ldrh r0, [sp]
	add r0, sl, r0, lsl #2
	ldr r0, [r0, #0xf0]
	bl ov0_0215ABA4
	ldrh r0, [sp]
	ldr r1, [sl, #0xec]
	add r0, sl, r0, lsl #2
	ldr r0, [r0, #0xf0]
	bl ov0_0215AAA4
	ldrh r0, [sp]
	mov r1, #1
	add r0, sl, r0, lsl #2
	ldr r0, [r0, #0xf0]
	bl ov0_0215AA60
	ldr r0, [sl, #0xe8]
	mov r1, #0x5c
	mov r2, #0x62
	bl _ZN17UnkClass_0203447812sub_02034CA0Eii
	arm_func_end ov0_0215A010
_0215A0D4:
	mov r0, #0
	strh r0, [sl, #0xe0]
_0215A0DC:
	ldr r0, _0215A254 ; =0xFFF000FE
	mov sb, #0
	ldr r6, _0215A258 ; =MAIN_BSS_020B26A0
	rsb r4, r0, #0xfd
	mov fp, sb
_0215A0F0:
	ldrh r1, [sl, #0xe4]
	add r0, sl, sb, lsl #2
	ldr r0, [r0, #0xf0]
	mov r1, r1, lsl #2
	add r1, r1, #0x20
	add r1, sb, r1
	mov r1, r1, lsl #0x10
	mov r7, r1, lsr #0x10
	bl ov0_0215ABF0
	add r1, sl, sb, lsl #2
	mov r5, r0
	ldr r0, [r1, #0xf0]
	bl ov0_0215AA80
	cmp r0, #0
	beq _0215A238
	mov r0, sl
	bl ov0_0215A3A4
	cmp r0, #0
	beq _0215A228
	ldrh r0, [r5, #0xa]
	tst r0, #2
	bne _0215A1F4
	add r0, sl, sb, lsl #2
	ldr r0, [r0, #0xf0]
	ldrh r8, [r0, #0xe0]
	bl ov0_0215ABF0
	mov r1, r7, lsl #0x16
	add r1, r6, r1, lsr #20
	add r1, r1, #0x8000
	mov ip, r8, lsl #0x18
	ldr r2, [r1, #0x1b4]
	ldrh r3, [r0, #8]
	bic r0, r2, #0xfe
	ldr r2, [r5, #0x10]
	ldr r8, _0215A254 ; =0xFFF000FE
	orr r0, r0, #0xd
	and r0, r0, r8
	orr r8, r0, ip, lsr #12
	orr r0, r8, #1
	orr r0, r0, #0x100
	and r0, r0, r4
	orr r0, r0, r3, lsl #20
	str r0, [r1, #0x1b4]
	ldr r1, [r5, #0x14]
	ldr r0, [r5, #0x18]
	str r1, [sp, #4]
	mov ip, r1, asr #0xc
	ldrh r1, [r5, #6]
	str r0, [sp, #8]
	mov r3, r0, asr #0xc
	ldrh r0, [r5, #2]
	ldrh r5, [r5]
	add r8, r6, r7, lsl #1
	and r1, r1, #0xff
	and r0, r0, #0xff
	orr r0, r1, r0, lsl #8
	add r1, r8, #0x8400
	strh ip, [r1, #0x36]
	strh r3, [r1, #0xd6]
	add r3, r8, #0x8600
	mov r2, r2, asr #0xc
	strh r5, [r3, #0x16]
	add r1, r8, #0x8500
	strh r2, [r1, #0x76]
	strh r0, [r3, #0xb6]
_0215A1F4:
	add r0, sl, sb, lsl #2
	ldr r0, [r0, #0xf0]
	bl ov0_0215A698
	add r0, sl, sb, lsl #2
	ldr r0, [r0, #0xf0]
	bl ov0_0215AA80
	cmp r0, #0
	bne _0215A238
	mov r0, r7, lsl #0x16
	add r0, r6, r0, lsr #20
	add r0, r0, #0x8000
	str fp, [r0, #0x1b4]
	b _0215A238
_0215A228:
	add r0, sl, sb, lsl #2
	ldr r0, [r0, #0xf0]
	mov r1, #0
	bl ov0_0215AA60
_0215A238:
	add r0, sb, #1
	mov r0, r0, lsl #0x10
	mov sb, r0, lsr #0x10
	cmp sb, #4
	blo _0215A0F0
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0215A254: .word 0xFFF000FE
_0215A258: .word MAIN_BSS_020B26A0

	arm_func_start ov0_0215A25C
ov0_0215A25C: ; 0x0215A25C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl ov0_0215A3A4
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mov r7, #0
	arm_func_end ov0_0215A25C
_0215A27C:
	add r0, r6, r7, lsl #2
	ldr r0, [r0, #0xf0]
	bl ov0_0215AA80
	cmp r0, #0
	beq _0215A2A4
	add r0, r6, r7, lsl #2
	ldr r0, [r0, #0xf0]
	mov r1, r5
	mov r2, r4
	bl _ZN11CFieldActor12sub_0203C590EP17UnkClass_0211E3FCP17UnkClass_020416AC
_0215A2A4:
	add r0, r7, #1
	mov r0, r0, lsl #0x10
	mov r7, r0, lsr #0x10
	cmp r7, #4
	blo _0215A27C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov0_0215A2BC
ov0_0215A2BC: ; 0x0215A2BC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r0, _0215A334 ; =MAIN_BSS_0210CA44
	ldr r1, _0215A338 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	ldr r5, [r1]
	cmp r0, #0
	mov r4, #0
	beq _0215A2E8
	bl _ZN17UnkClass_0213F91812ov0_0213FEECEv
	cmp r0, #0
	movne r4, #1
	arm_func_end ov0_0215A2BC
_0215A2E8:
	cmp r5, #0
	beq _0215A32C
	ldr r0, [r5, #0xd0]
	ldr r1, [r5, #0x84]
	tst r0, #8
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	cmpne r1, #3
	cmpne r1, #4
	cmpne r1, #7
	cmpne r1, #5
	cmpne r1, #6
	cmpne r1, #8
	cmpne r1, #9
	cmpne r1, #0x14
	moveq r4, #1
_0215A32C:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0215A334: .word MAIN_BSS_0210CA44
_0215A338: .word MAIN_BSS_0210CA40

	arm_func_start ov0_0215A33C
ov0_0215A33C: ; 0x0215A33C
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	mov r4, #0
	arm_func_end ov0_0215A33C
_0215A34C:
	add r0, r6, r4, lsl #2
	ldr r0, [r0, #0xf0]
	bl ov0_0215AA80
	cmp r0, #0
	streqh r4, [r5]
	moveq r0, #1
	ldmeqia sp!, {r4, r5, r6, pc}
	add r0, r4, #1
	mov r0, r0, lsl #0x10
	mov r4, r0, lsr #0x10
	cmp r4, #4
	blo _0215A34C
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov0_0215A384
ov0_0215A384: ; 0x0215A384
	cmp r1, #0
	ldr r1, [r0, #0xec]
	ldrneh r0, [r1, #0xc]
	orrne r0, r0, #1
	ldreqh r0, [r1, #0xc]
	biceq r0, r0, #1
	strh r0, [r1, #0xc]
	bx lr
	arm_func_end ov0_0215A384

	arm_func_start ov0_0215A3A4
ov0_0215A3A4: ; 0x0215A3A4
	ldr r0, [r0, #0xec]
	ldrh r0, [r0, #0xc]
	tst r0, #1
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end ov0_0215A3A4

	arm_func_start ov0_0215A3BC
ov0_0215A3BC: ; 0x0215A3BC
	ldr r3, [r0, #0xec]
	mov r0, r1, lsl #0xc
	str r0, [r3, #0x14]
	mov r0, r2, lsl #0xc
	str r0, [r3, #0x18]
	bx lr
	arm_func_end ov0_0215A3BC

	arm_func_start ov0_0215A3D4
ov0_0215A3D4: ; 0x0215A3D4
	ldr ip, [r0, #0xec]
	mov r2, r2, lsl #0x10
	strh r1, [ip]
	ldr r1, [r0, #0xec]
	mov r2, r2, lsr #0x10
	str r2, [r1, #0x10]
	ldr r1, [r0, #0xec]
	ldr r2, [sp, #4]
	strh r3, [r1, #2]
	ldr r1, [r0, #0xec]
	ldr r3, [sp, #8]
	strh r2, [r1, #4]
	ldr r1, [r0, #0xec]
	ldr r2, [sp, #0xc]
	strh r3, [r1, #6]
	ldr r1, [r0, #0xec]
	ldr r3, [sp, #0x10]
	strh r2, [r1, #8]
	ldr r2, [r0, #0xec]
	ldr r1, [sp]
	strh r3, [r2, #0xa]
	ldr r0, [r0, #0xec]
	str r1, [r0, #0x1c]
	bx lr
	arm_func_end ov0_0215A3D4

	arm_func_start ov0_0215A434
ov0_0215A434: ; 0x0215A434
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x10
	mov r5, r0
	mov r6, r3
	add r0, r5, r6, lsl #2
	ldr r0, [r0, #0xf0]
	mov r4, r1
	cmp r0, #0
	mov r7, r2
	addeq sp, sp, #0x10
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	bl ov0_0215ABA4
	add r0, r5, r6, lsl #2
	ldr r0, [r0, #0xf0]
	mov r1, r4
	bl ov0_0215AAA4
	add r2, r5, r6, lsl #2
	ldr r0, [r2, #0xf0]
	mov r1, #1
	strh r7, [r0, #0xe0]
	ldr r0, [r2, #0xf0]
	bl ov0_0215AA60
	add r0, r5, r6, lsl #2
	ldr r2, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r0, [r0, #0xf0]
	str r1, [sp, #0xc]
	ldr r4, [r0, #8]
	str r2, [sp, #8]
	cmp r4, #0
	ldrne r0, [r4, #0xc]
	add r1, sp, #8
	cmpne r0, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [r4, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r1, [sp, #8]
	ldr r0, [sp, #0xc]
	str r1, [r2, #0x18]
	str r1, [sp]
	str r0, [sp, #4]
	str r0, [r2, #0x1c]
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end ov0_0215A434

	arm_func_start ov0_0215A500
ov0_0215A500: ; 0x0215A500
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN11CFieldActorC2Ev
	ldr r0, _0215A544 ; =PTR_LAB_overlay_0_0215a54c_overlay_0_02178248
	mov r2, #0
	str r0, [r5]
	str r2, [r5, #0xe8]
	ldr r0, _0215A548 ; =MAIN_BSS_0210CA48
	strh r4, [r5, #0xe2]
	ldr r1, [r0]
	mov r0, r5
	str r1, [r5, #0xe4]
	strh r2, [r5, #0xe0]
	bl ov0_0215A5A4
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0215A544: .word PTR_LAB_overlay_0_0215a54c_overlay_0_02178248
_0215A548: .word MAIN_BSS_0210CA48
	arm_func_end ov0_0215A500

	arm_func_start _ZN16CFieldCannonUnitD1Ev
_ZN16CFieldCannonUnitD1Ev: ; 0x0215A54C
	stmdb sp!, {r4, lr}
	ldr r1, _0215A570 ; =PTR_LAB_overlay_0_0215a54c_overlay_0_02178248
	mov r4, r0
	str r1, [r4]
	bl ov0_0215A604
	mov r0, r4
	bl _ZN11CFieldActorD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215A570: .word PTR_LAB_overlay_0_0215a54c_overlay_0_02178248
	arm_func_end _ZN16CFieldCannonUnitD1Ev

	arm_func_start ov0_0215A574
ov0_0215A574: ; 0x0215A574
	stmdb sp!, {r4, lr}
	ldr r1, _0215A5A0 ; =PTR_LAB_overlay_0_0215a54c_overlay_0_02178248
	mov r4, r0
	str r1, [r4]
	bl ov0_0215A604
	mov r0, r4
	bl _ZN11CFieldActorD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215A5A0: .word PTR_LAB_overlay_0_0215a54c_overlay_0_02178248
	arm_func_end ov0_0215A574

	arm_func_start ov0_0215A5A4
ov0_0215A5A4: ; 0x0215A5A4
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	bl ov0_0215A604
	mov r0, #0x20
	bl _Znwm
	str r0, [r4, #0xe8]
	mov r0, r4
	bl ov0_0215A628
	ldrh r0, [r4, #0xe2]
	mov r1, #6
	mov r2, #0
	cmp r0, #0
	moveq r2, #0x154
	cmp r0, #1
	str r1, [sp]
	mov r3, #0
	moveq r2, #0x174
	mov r0, r4
	mov r1, #2
	str r3, [sp, #4]
	bl _ZN11CFieldActor12sub_0203C418Eitimi
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0215A5A4

	arm_func_start ov0_0215A604
ov0_0215A604: ; 0x0215A604
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0xe8]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZdlPv
	mov r0, #0
	str r0, [r4, #0xe8]
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0215A604

	arm_func_start ov0_0215A628
ov0_0215A628: ; 0x0215A628
	ldr r1, [r0, #0xe8]
	cmp r1, #0
	bxeq lr
	mov ip, #0
	strh ip, [r1]
	ldr r1, [r0, #0xe8]
	mov r3, #0x400
	strh ip, [r1, #2]
	ldr r2, [r0, #0xe8]
	mov r1, #0x10000
	strh ip, [r2, #4]
	ldr r2, [r0, #0xe8]
	strh ip, [r2, #6]
	ldr r2, [r0, #0xe8]
	strh ip, [r2, #8]
	ldr r2, [r0, #0xe8]
	strh ip, [r2, #0xa]
	ldr r2, [r0, #0xe8]
	strh r3, [r2, #0xc]
	ldr r2, [r0, #0xe8]
	str ip, [r2, #0x10]
	ldr r2, [r0, #0xe8]
	str ip, [r2, #0x14]
	ldr r2, [r0, #0xe8]
	str ip, [r2, #0x18]
	ldr r0, [r0, #0xe8]
	str r1, [r0, #0x1c]
	bx lr
	arm_func_end ov0_0215A628

	arm_func_start ov0_0215A698
ov0_0215A698: ; 0x0215A698
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x90
	mov r5, r0
	ldr r0, [r5, #0xe8]
	ldrh r0, [r0, #0xa]
	tst r0, #1
	addeq sp, sp, #0x90
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0215A704
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0215A6E4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x64]
	str r0, [sp, #0x68]
	b _0215A6FC
	arm_func_end ov0_0215A698
_0215A6E4:
	mov r0, #0
	add r1, sp, #0x4c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
_0215A6FC:
	add r2, sp, #0x64
	b _0215A720
_0215A704:
	mov r0, #0
	add r1, sp, #0x44
	add r2, sp, #0x64
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
_0215A720:
	ldr r3, [r2]
	ldr r2, [r2, #4]
	ldr r0, [r5, #0xe8]
	str r3, [sp, #0x7c]
	str r3, [r0, #0x14]
	str r2, [r0, #0x18]
	ldr r0, [r5, #0xe8]
	str r2, [sp, #0x80]
	ldrh r4, [r0, #0xa]
	add r1, sp, #0x7c
	tst r4, #2
	beq _0215A790
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0215A774
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _0215A778
	bl _ZN6CActor12sub_02012AFCEv
	b _0215A778
_0215A774:
	mov r0, #2
_0215A778:
	cmp r0, #0
	bne _0215AA48
	mov r0, r5
	mov r1, #0
	bl ov0_0215AA60
	b _0215AA48
_0215A790:
	ldrh r7, [r0]
	ldr r4, [r5, #8]
	ldr r6, _0215AA5C ; =FX_SinCosTable_
	mov r7, r7, asr #4
	mov r7, r7, lsl #1
	add ip, r7, #1
	mov lr, ip, lsl #1
	mov ip, r7, lsl #1
	ldrsh lr, [r6, lr]
	ldrsh ip, [r6, ip]
	ldr r0, [r0, #0x10]
	cmp r4, #0
	smull r7, r6, r0, lr
	smull lr, ip, r0, ip
	mov r0, lr, lsr #0xc
	orr r0, r0, ip, lsl #20
	mov r7, r7, lsr #0xc
	add r0, r2, r0
	orr r7, r7, r6, lsl #20
	str r0, [sp, #0x80]
	ldrne r0, [r4, #0xc]
	add r3, r3, r7
	str r3, [sp, #0x7c]
	cmpne r0, #0
	beq _0215A828
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [r4, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	beq _0215A828
	ldr r1, [sp, #0x7c]
	ldr r0, [sp, #0x80]
	str r1, [r2, #0x18]
	str r1, [sp, #0x3c]
	str r0, [sp, #0x40]
	str r0, [r2, #0x1c]
_0215A828:
	ldr r0, [r5, #0xe4]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0215A874
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0215A858
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x5c]
	str r0, [sp, #0x60]
	b _0215A88C
_0215A858:
	mov r0, #0
	add r1, sp, #0x34
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
	b _0215A88C
_0215A874:
	mov r0, #0
	add r1, sp, #0x2c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
_0215A88C:
	ldr r0, [r5, #0xe4]
	ldr r3, [sp, #0x5c]
	ldr r2, [sp, #0x60]
	ldr r1, [r0, #0xe0]
	ldr r0, [r0, #0x10c]
	str r3, [sp, #0x84]
	str r2, [sp, #0x88]
	str r1, [sp, #0x8c]
	tst r0, #1
	bne _0215A9F0
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [r5, #0xe8]
	sub r3, sp, #4
	add r0, r0, #0x14
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	add r0, sp, #0x84
	ldr r3, [r3]
	ldmia r0, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	beq _0215A9F0
	mov r0, r5
	ldr r3, [r0]
	mov r1, #4
	ldr r3, [r3, #0x38]
	mov r2, #0
	blx r3
	ldr r1, [r5, #0xe8]
	ldrh r0, [r1, #0xa]
	orr r0, r0, #2
	strh r0, [r1, #0xa]
	ldr r0, [r5, #0xe4]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0215A960
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0215A940
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x54]
	str r0, [sp, #0x58]
	b _0215A958
_0215A940:
	mov r0, #0
	add r1, sp, #0x24
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x54]
	str r0, [sp, #0x58]
_0215A958:
	add r2, sp, #0x54
	b _0215A97C
_0215A960:
	mov r0, #0
	add r1, sp, #0x1c
	add r2, sp, #0x54
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x54]
	str r0, [sp, #0x58]
_0215A97C:
	ldr r3, [r2]
	ldr r2, [r2, #4]
	ldr r0, [sp, #0x7c]
	ldr r1, [sp, #0x80]
	sub r0, r0, r3
	sub r1, r1, r2
	str r3, [sp, #0x74]
	str r2, [sp, #0x78]
	bl _Z12sub_02007254ll
	ldr r3, [r5, #0xe8]
	ldr ip, [sp, #0x7c]
	ldrh r0, [r3, #2]
	ldr r4, [sp, #0x80]
	ldr r1, [sp, #0x74]
	ldr r2, [sp, #0x78]
	sub r1, r1, ip
	sub r2, r2, r4
	str r0, [sp]
	mvn r0, #0
	str r0, [sp, #4]
	ldrh r3, [r3, #6]
	ldr r0, [r5, #0xe4]
	str ip, [sp, #0x14]
	str r4, [sp, #0x18]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r1, [sp, #0x6c]
	str r2, [sp, #0x70]
	bl _ZN12CFieldPlayer12ov0_021333A0Elliii
_0215A9F0:
	ldr r0, [r5, #0xe8]
	ldrh r0, [r0, #0xa]
	tst r0, #2
	bne _0215AA48
	ldrh r0, [r5, #0xe0]
	add r0, r0, #1
	strh r0, [r5, #0xe0]
	ldr r0, [r5, #0xe8]
	ldrh r1, [r5, #0xe0]
	ldrh r0, [r0, #8]
	cmp r1, r0
	bne _0215AA48
	mov r0, r5
	ldr r3, [r0]
	mov r1, #4
	ldr r3, [r3, #0x38]
	mov r2, #0
	blx r3
	ldr r1, [r5, #0xe8]
	ldrh r0, [r1, #0xa]
	orr r0, r0, #2
	strh r0, [r1, #0xa]
_0215AA48:
	mov r0, r5
	mov r1, #0
	bl _ZN11CFieldActor12sub_0203C87CEP9CFieldMap
	add sp, sp, #0x90
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0215AA5C: .word FX_SinCosTable_

	arm_func_start ov0_0215AA60
ov0_0215AA60: ; 0x0215AA60
	cmp r1, #0
	ldr r1, [r0, #0xe8]
	ldrneh r0, [r1, #0xa]
	orrne r0, r0, #1
	ldreqh r0, [r1, #0xa]
	biceq r0, r0, #1
	strh r0, [r1, #0xa]
	bx lr
	arm_func_end ov0_0215AA60

	arm_func_start ov0_0215AA80
ov0_0215AA80: ; 0x0215AA80
	ldr r0, [r0, #0xe8]
	ldrh r0, [r0, #0xa]
	tst r0, #1
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end ov0_0215AA80

	arm_func_start ov0_0215AA98
ov0_0215AA98: ; 0x0215AA98
	ldr r0, [r0, #0xe8]
	strh r1, [r0, #0xa]
	bx lr
	arm_func_end ov0_0215AA98

	arm_func_start ov0_0215AAA4
ov0_0215AAA4: ; 0x0215AAA4
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	ldr lr, [r0, #0xe8]
	cmp lr, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r4, pc}
	ldrh r3, [r1]
	mov ip, #0
	add r2, sp, #8
	strh r3, [lr]
	ldrh lr, [r1, #4]
	ldr r3, [r0, #0xe8]
	strh lr, [r3, #2]
	ldrh lr, [r1, #6]
	ldr r3, [r0, #0xe8]
	strh lr, [r3, #4]
	ldrh lr, [r1, #8]
	ldr r3, [r0, #0xe8]
	strh lr, [r3, #6]
	ldrh lr, [r1, #0xa]
	ldr r3, [r0, #0xe8]
	strh lr, [r3, #8]
	ldr r3, [r0, #0xe8]
	strh ip, [r3, #0xa]
	ldrh ip, [r1, #0xe]
	ldr r3, [r0, #0xe8]
	strh ip, [r3, #0xc]
	ldr ip, [r1, #0x10]
	ldr r3, [r0, #0xe8]
	str ip, [r3, #0x10]
	ldr lr, [r0, #0xe8]
	ldr ip, [r1, #0x14]
	ldr r3, [r1, #0x18]
	str ip, [lr, #0x14]
	str r3, [lr, #0x18]
	ldr r1, [r1, #0x1c]
	str r1, [lr, #0x1c]
	ldr r3, [r0, #0xe8]
	ldr r4, [r0, #8]
	ldr r0, [r3, #0x18]
	ldr r1, [r3, #0x14]
	str r0, [sp, #0xc]
	cmp r4, #0
	ldrne r0, [r4, #0xc]
	str r1, [sp, #8]
	cmpne r0, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r4, pc}
	add r0, r0, #0xc
	ldmia r2, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [r4, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r4, pc}
	ldr r1, [sp, #8]
	ldr r0, [sp, #0xc]
	str r1, [r2, #0x18]
	str r1, [sp]
	str r0, [sp, #4]
	str r0, [r2, #0x1c]
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0215AAA4

	arm_func_start ov0_0215ABA4
ov0_0215ABA4: ; 0x0215ABA4
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	strh r1, [r4, #0xe0]
	bl ov0_0215AA98
	mov r0, r4
	ldr r3, [r0]
	mov r1, #2
	ldr r3, [r3, #0x38]
	mov r2, #0
	blx r3
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r1, [r0, #0xc]
	cmpne r1, #0
	ldrneh r0, [r1, #4]
	orrne r0, r0, #8
	strneh r0, [r1, #4]
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0215ABA4

	arm_func_start ov0_0215ABF0
ov0_0215ABF0: ; 0x0215ABF0
	ldr r0, [r0, #0xe8]
	bx lr
	arm_func_end ov0_0215ABF0

    .rodata

    .bss

    .global OVERLAY0_BSS_0217B380
OVERLAY0_BSS_0217B380: ; 0x0217B380
    .space 0x20
