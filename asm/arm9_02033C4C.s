    .include "macros.inc"
    .include "include/arm9_02033C4C.inc"

    .text

	arm_func_start sub_02033C4C
sub_02033C4C: ; 0x02033C4C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02033EB0
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02033C4C

	arm_func_start sub_02033C60
sub_02033C60: ; 0x02033C60
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0xc
	mov r6, r0
	mov r5, r2
	mov r4, r3
	bl OS_SPrintf
	mov r0, r6
	bl sub_02033ED4
	mov r0, r6
	bl sub_02033EB0
	mov r0, #0xb8
	bl _Znwm
	cmp r0, #0
	beq _02033CB4
	mov r2, #0
	ldr ip, [sp, #0x20]
	str r5, [sp]
	mov r1, r6
	mov r3, r2
	stmib sp, {r4, ip}
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	arm_func_end sub_02033C60
_02033CB4:
	str r0, [r6, #0x28]
	ldr r0, [r0, #0x4c]
	str r0, [r6, #0x20]
	cmp r0, #0
	bne _02033CDC
	mov r0, r6
	bl sub_02033ED4
	add sp, sp, #0xc
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_02033CDC:
	str r0, [r6, #0x24]
	bl sub_02044AC8
	add r0, r6, #0x3c
	add r1, r6, #0x60
	mov r2, #0x80
	bl sub_02044B48
	mov r0, #0
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, r5, r6, pc}

	arm_func_start sub_02033D00
sub_02033D00: ; 0x02033D00
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl sub_02033ED4
	mov r0, r6
	bl sub_02033EB0
	cmp r5, #0
	moveq r0, #1
	ldmeqia sp!, {r4, r5, r6, pc}
	str r5, [r6, #0x20]
	str r5, [r6, #0x24]
	cmp r4, #0
	bne _02033D40
	ldr r0, [r6, #0x24]
	bl sub_02044AC8
	arm_func_end sub_02033D00
_02033D40:
	add r0, r6, #0x3c
	add r1, r6, #0x60
	mov r2, #0x80
	bl sub_02044B48
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_02033D58
sub_02033D58: ; 0x02033D58
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x20]
	mov r4, r1
	cmp r0, #0
	moveq r0, #1
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r4
	bl strlen
	cmp r0, #0xc
	bls _02033D88
	bl OS_Terminate
	arm_func_end sub_02033D58
_02033D88:
	mov r1, r4
	add r0, r5, #0x2c
	mov r2, #0xd
	bl OS_SPrintf
	add r0, r5, #0x3c
	bl sub_02044B84
	ldr r1, [r5, #0x24]
	add r0, r5, #0x3c
	add r2, r5, #0x2c
	bl sub_02045A18
	mov r0, #1
	str r0, [r5, #0x260]
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02033DC0
sub_02033DC0: ; 0x02033DC0
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	mov r5, r0
	mov r0, r4
	bl strlen
	cmp r0, #0xc
	bls _02033DE0
	bl OS_Terminate
	arm_func_end sub_02033DC0
_02033DE0:
	mov r1, r4
	add r0, r5, #0x264
	mov r2, #0xd
	bl OS_SPrintf
	mov r0, #1
	str r0, [r5, #0x274]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02033DFC
sub_02033DFC: ; 0x02033DFC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	moveq r0, #1
	ldmeqia sp!, {r4, pc}
	add r0, r4, #0x2c
	add r1, r4, #0x264
	mov r2, #0xd
	bl OS_SPrintf
	add r0, r4, #0x3c
	bl sub_02044B84
	ldr r1, [r4, #0x24]
	add r0, r4, #0x3c
	add r2, r4, #0x2c
	bl sub_02045A18
	mov r0, #1
	str r0, [r4, #0x260]
	mov r0, #0
	str r0, [r4, #0x274]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02033DFC

	arm_func_start sub_02033E50
sub_02033E50: ; 0x02033E50
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02033ED4
	mov r0, r4
	bl sub_02033EB0
	ldmia sp!, {r4, pc}
	arm_func_end sub_02033E50

	arm_func_start sub_02033E68
sub_02033E68: ; 0x02033E68
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x260]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r1, _02033EAC ; =0x000FFFFF
	add r0, r4, #0x3c
	bl sub_02044C9C
	tst r0, #2
	movne r0, #0
	strne r0, [r4, #0x260]
	ldmneia sp!, {r4, pc}
	ldr r0, [r4, #0x260]
	cmp r0, #1
	moveq r0, #2
	streq r0, [r4, #0x260]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033EAC: .word 0x000FFFFF
	arm_func_end sub_02033E68

	arm_func_start sub_02033EB0
sub_02033EB0: ; 0x02033EB0
	mov r1, #0
	str r1, [r0, #0x20]
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	str r1, [r0, #0x260]
	str r1, [r0, #0x274]
	sub r1, r1, #1
	str r1, [r0, #0x278]
	bx lr
	arm_func_end sub_02033EB0

	arm_func_start sub_02033ED4
sub_02033ED4: ; 0x02033ED4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x28]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	beq _02033EF8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02033ED4
_02033EF8:
	mov r0, #0
	str r0, [r4, #0x28]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_02033F04C1Em
_ZN17UnkClass_02033F04C1Em: ; 0x02033F04
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _Z12sub_02044440v
	ldr r1, _02033F8C ; =gScriptSyscalls
	mov r0, #2
	str r4, [r5]
	bl sub_02044B38
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F38
	bl sub_02033C4C
	arm_func_end _ZN17UnkClass_02033F04C1Em
_02033F38:
	str r0, [r5, #4]
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F50
	bl sub_02033C4C
_02033F50:
	str r0, [r5, #8]
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F68
	bl sub_02033C4C
_02033F68:
	str r0, [r5, #0xc]
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F80
	bl sub_02033C4C
_02033F80:
	str r0, [r5, #0x10]
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02033F8C: .word gScriptSyscalls

	arm_func_start sub_02033F90
sub_02033F90: ; 0x02033F90
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r3, #0
	cmp r4, r1
	beq _02034008
	cmp r4, #0
	ble _02033FE8
	ldr r1, _02034014 ; =s_data_Script_system_system_03d_fs_0208d4b4
	add r0, sp, #4
	mov r2, r4
	bl OS_SPrintf
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #4]
	ldr r2, [r5]
	add r1, sp, #4
	bl sub_02033C60
	b _02033FF8
	arm_func_end sub_02033F90
_02033FE8:
	str r3, [sp]
	ldr r2, [r5]
	ldr r1, _02034018 ; =s_data_Script_system_system_fsb_0208d4d8
	bl sub_02033C60
_02033FF8:
	mov r3, r0
	cmp r3, #0
	ldreq r0, [r5, #4]
	streq r4, [r0, #0x278]
_02034008:
	mov r0, r3
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034014: .word s_data_Script_system_system_03d_fs_0208d4b4
_02034018: .word s_data_Script_system_system_fsb_0208d4d8

	arm_func_start sub_0203401C
sub_0203401C: ; 0x0203401C
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #8]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r0, #0
	cmp r4, r1
	addeq sp, sp, #0x44
	ldmeqia sp!, {r4, r5, pc}
	ldr r1, _02034080 ; =s_data_Script_area_m_03d_fsb_0208d4f8
	add r0, sp, #4
	mov r2, r4
	bl OS_SPrintf
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #8]
	ldr r2, [r5]
	add r1, sp, #4
	bl sub_02033C60
	cmp r0, #0
	ldreq r1, [r5, #8]
	streq r4, [r1, #0x278]
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034080: .word s_data_Script_area_m_03d_fsb_0208d4f8
	arm_func_end sub_0203401C

	arm_func_start sub_02034084
sub_02034084: ; 0x02034084
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #0xc]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r0, #0
	cmp r4, r1
	addeq sp, sp, #0x44
	ldmeqia sp!, {r4, r5, pc}
	cmp r4, #0x46
	add r0, sp, #4
	bge _020340F4
	ldr r1, _02034118 ; =s_data_Script_chapter_c_03d_fsb_0208d514
	mov r2, r4
	bl OS_SPrintf
	mov r0, #0x18800
	str r0, [sp]
	ldr r0, [r5, #0xc]
	ldr r2, [r5]
	add r1, sp, #4
	add r3, r5, #0x1c
	bl sub_02033C60
	cmp r0, #0
	ldreq r1, [r5, #0xc]
	add sp, sp, #0x44
	streq r4, [r1, #0x278]
	ldmia sp!, {r4, r5, pc}
	arm_func_end sub_02034084
_020340F4:
	ldr r1, _0203411C ; =s_data_Script_chapter_cx_02d_fsb_0208d534
	sub r2, r4, #0x45
	bl OS_SPrintf
	ldr r0, [r5, #0xc]
	add r1, r5, #0x1c
	mov r2, #1
	bl sub_02033D00
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034118: .word s_data_Script_chapter_c_03d_fsb_0208d514
_0203411C: .word s_data_Script_chapter_cx_02d_fsb_0208d534

	arm_func_start sub_02034120
sub_02034120: ; 0x02034120
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #0x10]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r0, #0
	cmp r4, r1
	beq _0203416C
	ldr r1, _02034180 ; =s_data_Script_quest_q_03d_fsb_0208d554
	add r0, sp, #4
	mov r2, r4
	bl OS_SPrintf
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #0x10]
	ldr r2, [r5]
	add r1, sp, #4
	bl sub_02033C60
	arm_func_end sub_02034120
_0203416C:
	cmp r0, #0
	ldreq r1, [r5, #0x10]
	streq r4, [r1, #0x278]
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034180: .word s_data_Script_quest_q_03d_fsb_0208d554

	arm_func_start sub_02034184
sub_02034184: ; 0x02034184
	stmdb sp!, {r3, lr}
	ldrsb r2, [r1]
	cmp r2, #0x71
	bgt _020341B8
	bge _020341FC
	cmp r2, #0x63
	bgt _02034210
	cmp r2, #0x61
	blt _02034210
	beq _020341D4
	cmp r2, #0x63
	beq _020341E8
	b _02034210
	arm_func_end sub_02034184
_020341B8:
	cmp r2, #0x73
	bne _02034210
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #4]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_020341D4:
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #8]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_020341E8:
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #0xc]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_020341FC:
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #0x10]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_02034210:
	bl OS_Terminate
	mov r0, #1
	ldmia sp!, {r3, pc}

	arm_func_start sub_0203421C
sub_0203421C: ; 0x0203421C
	stmdb sp!, {r3, lr}
	ldrsb r2, [r1]
	cmp r2, #0x71
	bgt _02034250
	bge _0203427C
	cmp r2, #0x63
	bgt _02034288
	cmp r2, #0x61
	blt _02034288
	beq _02034264
	cmp r2, #0x63
	beq _02034270
	b _02034288
	arm_func_end sub_0203421C
_02034250:
	cmp r2, #0x73
	bne _02034288
	ldr r0, [r0, #4]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_02034264:
	ldr r0, [r0, #8]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_02034270:
	ldr r0, [r0, #0xc]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_0203427C:
	ldr r0, [r0, #0x10]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_02034288:
	bl OS_Terminate
	ldmia sp!, {r3, pc}

	arm_func_start sub_02034290
sub_02034290: ; 0x02034290
	ldr ip, _0203429C ; =sub_02033E50
	ldr r0, [r0, #4]
	bx ip
	.align 2, 0
_0203429C: .word sub_02033E50
	arm_func_end sub_02034290

	arm_func_start sub_020342A0
sub_020342A0: ; 0x020342A0
	ldr ip, _020342AC ; =sub_02033E50
	ldr r0, [r0, #8]
	bx ip
	.align 2, 0
_020342AC: .word sub_02033E50
	arm_func_end sub_020342A0

	arm_func_start sub_020342B0
sub_020342B0: ; 0x020342B0
	ldr ip, _020342BC ; =sub_02033E50
	ldr r0, [r0, #0xc]
	bx ip
	.align 2, 0
_020342BC: .word sub_02033E50
	arm_func_end sub_020342B0

	arm_func_start sub_020342C0
sub_020342C0: ; 0x020342C0
	ldr ip, _020342CC ; =sub_02033E50
	ldr r0, [r0, #0x10]
	bx ip
	.align 2, 0
_020342CC: .word sub_02033E50
	arm_func_end sub_020342C0

	arm_func_start sub_020342D0
sub_020342D0: ; 0x020342D0
	stmdb sp!, {r3, lr}
	ldmib r0, {r1, lr}
	ldr r2, [r1, #0x260]
	ldr r3, [r0, #0x18]
	ldr ip, [r0, #0xc]
	orr r2, r3, r2
	ldr r1, [r1, #0x274]
	ldr r3, [lr, #0x260]
	orr r1, r2, r1
	orr r1, r3, r1
	ldr r2, [lr, #0x274]
	ldr r0, [r0, #0x10]
	orr r1, r2, r1
	ldr r3, [ip, #0x260]
	ldr r2, [ip, #0x274]
	orr r1, r3, r1
	orr r1, r2, r1
	ldr r3, [r0, #0x260]
	ldr r2, [r0, #0x274]
	orr r0, r3, r1
	orr r0, r2, r0
	ldmia sp!, {r3, pc}
	arm_func_end sub_020342D0

	arm_func_start sub_02034328
sub_02034328: ; 0x02034328
	stmdb sp!, {r4, lr}
	ldmib r0, {r1, r4, lr}
	ldr r2, [r1, #0x260]
	ldr r1, [r1, #0x274]
	ldr ip, [r0, #0x10]
	orr r0, r2, r1
	ldr r3, [r4, #0x260]
	ldr r1, [r4, #0x274]
	orr r0, r3, r0
	orr r0, r1, r0
	ldr r2, [lr, #0x260]
	ldr r1, [lr, #0x274]
	orr r0, r2, r0
	orr r0, r1, r0
	ldr r2, [ip, #0x260]
	ldr r1, [ip, #0x274]
	orr r0, r2, r0
	orr r0, r1, r0
	ldmia sp!, {r4, pc}
	arm_func_end sub_02034328

	arm_func_start sub_02034374
sub_02034374: ; 0x02034374
	str r1, [r0, #0x14]
	bx lr
	arm_func_end sub_02034374

	arm_func_start sub_0203437C
sub_0203437C: ; 0x0203437C
	ldr r0, [r0, #0x14]
	bx lr
	arm_func_end sub_0203437C

	arm_func_start sub_02034384
sub_02034384: ; 0x02034384
	stmdb sp!, {r3, lr}
	ldr ip, [r0, #4]
	ldr r1, [ip, #0x260]
	cmp r1, #0
	beq _020343A4
	mov r0, ip
	bl sub_02033E68
	ldmia sp!, {r3, pc}
	arm_func_end sub_02034384
_020343A4:
	ldr r3, [r0, #8]
	ldr r1, [r3, #0x260]
	cmp r1, #0
	beq _020343C0
	mov r0, r3
	bl sub_02033E68
	ldmia sp!, {r3, pc}
_020343C0:
	ldr r2, [r0, #0xc]
	ldr r1, [r2, #0x260]
	cmp r1, #0
	beq _020343DC
	mov r0, r2
	bl sub_02033E68
	ldmia sp!, {r3, pc}
_020343DC:
	ldr r0, [r0, #0x10]
	ldr r1, [r0, #0x260]
	cmp r1, #0
	beq _020343F4
	bl sub_02033E68
	ldmia sp!, {r3, pc}
_020343F4:
	ldr r1, [ip, #0x274]
	cmp r1, #0
	beq _0203440C
	mov r0, ip
	bl sub_02033DFC
	ldmia sp!, {r3, pc}
_0203440C:
	ldr r1, [r3, #0x274]
	cmp r1, #0
	beq _02034424
	mov r0, r3
	bl sub_02033DFC
	ldmia sp!, {r3, pc}
_02034424:
	ldr r1, [r2, #0x274]
	cmp r1, #0
	beq _0203443C
	mov r0, r2
	bl sub_02033DFC
	ldmia sp!, {r3, pc}
_0203443C:
	ldr r1, [r0, #0x274]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	bl sub_02033DFC
	ldmia sp!, {r3, pc}

	arm_func_start sub_02034450
sub_02034450: ; 0x02034450
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02034290
	mov r0, r4
	bl sub_020342A0
	mov r0, r4
	bl sub_020342B0
	mov r0, r4
	bl sub_020342C0
	ldmia sp!, {r4, pc}
	arm_func_end sub_02034450
