    .include "macros.inc"
    .include "include/arm9_0203EF1C.inc"

    .text

	arm_func_start _ZN17CFieldActorManageC2Ev
_ZN17CFieldActorManageC2Ev: ; 0x0203EF1C
	ldr r2, _0203EF3C ; =PTR_LAB_0208ddc0
	mov r1, #0xff
	str r2, [r0]
	strb r1, [r0, #0xc]
	mov r1, #0
	str r1, [r0, #8]
	str r1, [r0, #4]
	bx lr
	.align 2, 0
_0203EF3C: .word PTR_LAB_0208ddc0
	arm_func_end _ZN17CFieldActorManageC2Ev

	arm_func_start sub_0203EF40
sub_0203EF40: ; 0x0203EF40
	ldr r2, _0203EF60 ; =PTR_LAB_0208ddc0
	mov r1, #0xff
	str r2, [r0]
	strb r1, [r0, #0xc]
	mov r1, #0
	str r1, [r0, #8]
	str r1, [r0, #4]
	bx lr
	.align 2, 0
_0203EF60: .word PTR_LAB_0208ddc0
	arm_func_end sub_0203EF40

	arm_func_start sub_0203EF64
sub_0203EF64: ; 0x0203EF64
	stmdb sp!, {r4, lr}
	ldr r1, _0203EF88 ; =PTR_LAB_0208ddc0
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203EF88: .word PTR_LAB_0208ddc0
	arm_func_end sub_0203EF64

	arm_func_start sub_0203EF8C
sub_0203EF8C: ; 0x0203EF8C
	stmdb sp!, {r4, lr}
	ldr r1, _0203EFB8 ; =PTR_LAB_0208ddc0
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
_0203EFB8: .word PTR_LAB_0208ddc0
	arm_func_end sub_0203EF8C

	arm_func_start _ZN17CFieldActorManageD2Ev
_ZN17CFieldActorManageD2Ev: ; 0x0203EFBC
	stmdb sp!, {r4, lr}
	ldr r1, _0203EFE0 ; =PTR_LAB_0208ddc0
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203EFE0: .word PTR_LAB_0208ddc0
	arm_func_end _ZN17CFieldActorManageD2Ev

	arm_func_start _ZN17CFieldActorManage12sub_0203EFE4Ei
_ZN17CFieldActorManage12sub_0203EFE4Ei: ; 0x0203EFE4
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, [r0]
	mov r5, r0
	ldr r2, [r2, #0xc]
	mov r4, r1
	blx r2
	str r4, [r5, #4]
	mov r0, r4, lsl #2
	bl _Znam
	str r0, [r5, #8]
	cmp r4, #0
	mov r2, #0
	ldmleia sp!, {r3, r4, r5, pc}
	mov r1, r2
	arm_func_end _ZN17CFieldActorManage12sub_0203EFE4Ei
_0203F01C:
	ldr r0, [r5, #8]
	str r1, [r0, r2, lsl #2]
	add r2, r2, #1
	cmp r2, r4
	blt _0203F01C
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F034Ev
_ZN17CFieldActorManage12sub_0203F034Ev: ; 0x0203F034
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r1, [r4, #4]
	cmp r1, #0
	ble _0203F09C
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203F09C
	cmp r1, #0
	mov r6, #0
	ble _0203F09C
	mov r5, r6
	arm_func_end _ZN17CFieldActorManage12sub_0203F034Ev
_0203F064:
	ldr r0, [r4, #8]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	beq _0203F08C
	beq _0203F084
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203F084:
	ldr r0, [r4, #8]
	str r5, [r0, r6, lsl #2]
_0203F08C:
	ldr r0, [r4, #4]
	add r6, r6, #1
	cmp r6, r0
	blt _0203F064
_0203F09C:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203F0B4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #8]
_0203F0B4:
	mov r0, #0
	str r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F0C0Ev
_ZN17CFieldActorManage12sub_0203F0C0Ev: ; 0x0203F0C0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r3, [r5, #4]
	cmp r3, #0
	ble _0203F13C
	ldr ip, [r5, #8]
	cmp ip, #0
	beq _0203F13C
	cmp r3, #0
	mov r4, #0
	ble _0203F13C
	arm_func_end _ZN17CFieldActorManage12sub_0203F0C0Ev
_0203F0EC:
	ldr r0, [ip, r4, lsl #2]
	cmp r0, #0
	beq _0203F130
	ldr r2, [r0, #0x58]
	cmp r1, r2
	bne _0203F130
	cmp r0, #0
	beq _0203F128
	beq _0203F11C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203F11C:
	ldr r0, [r5, #8]
	mov r1, #0
	str r1, [r0, r4, lsl #2]
_0203F128:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_0203F130:
	add r4, r4, #1
	cmp r4, r3
	blt _0203F0EC
_0203F13C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F144Ei
_ZN17CFieldActorManage12sub_0203F144Ei: ; 0x0203F144
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	mov r4, r1
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _0203F188
	beq _0203F180
	beq _0203F174
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end _ZN17CFieldActorManage12sub_0203F144Ei
_0203F174:
	ldr r0, [r5, #8]
	mov r1, #0
	str r1, [r0, r4, lsl #2]
_0203F180:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_0203F188:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F190Ev
_ZN17CFieldActorManage12sub_0203F190Ev: ; 0x0203F190
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r1, [r4, #4]
	cmp r1, #0
	ble _0203F1F4
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203F1F4
	subs r6, r1, #1
	bmi _0203F1EC
	mov r5, #0
	arm_func_end _ZN17CFieldActorManage12sub_0203F190Ev
_0203F1BC:
	ldr r0, [r4, #8]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	beq _0203F1E4
	beq _0203F1DC
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203F1DC:
	ldr r0, [r4, #8]
	str r5, [r0, r6, lsl #2]
_0203F1E4:
	subs r6, r6, #1
	bpl _0203F1BC
_0203F1EC:
	mov r0, #1
	ldmia sp!, {r4, r5, r6, pc}
_0203F1F4:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F1FCEv
_ZN17CFieldActorManage12sub_0203F1FCEv: ; 0x0203F1FC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr ip, [r0, #4]
	mov r5, r2
	mov r4, r3
	cmp r1, ip
	bge _0203F270
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, r1, lsl #2]
	cmpne r0, #0
	beq _0203F270
	ldr r6, [r0, #8]
	cmp r6, #0
	ldrne r7, [r6, #0xc]
	cmpne r7, #0
	beq _0203F268
	mov r1, r5
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r4
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r5, [r0, #0x18]
	strne r4, [r0, #0x1c]
	arm_func_end _ZN17CFieldActorManage12sub_0203F1FCEv
_0203F268:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_0203F270:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F278Ev
_ZN17CFieldActorManage12sub_0203F278Ev: ; 0x0203F278
	ldr ip, [r0, #4]
	cmp r1, ip
	bge _0203F2A8
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, r1, lsl #2]
	cmpne r0, #0
	beq _0203F2A8
	str r2, [r0, #0x18]
	str r3, [r0, #0x1c]
	mov r0, #1
	bx lr
	arm_func_end _ZN17CFieldActorManage12sub_0203F278Ev
_0203F2A8:
	mov r0, #0
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_0203F2B0EP9CFieldMapi
_ZN17CFieldActorManage12sub_0203F2B0EP9CFieldMapi: ; 0x0203F2B0
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov sb, r0
	ldr r0, [sb, #8]
	mov r8, r1
	mov r7, r2
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	ldr r0, [sb, #4]
	mov r6, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r4, r6
	mov r5, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F2B0EP9CFieldMapi
_0203F2E4:
	ldr r0, [sb, #8]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	beq _0203F334
	ldrb r1, [r0, #0x20]
	mov r2, r5
	cmp r1, #2
	cmpne r1, #3
	movne r2, r4
	cmp r2, #0
	beq _0203F334
	cmp r7, #0
	ldr r2, [r0]
	mov r1, r8
	beq _0203F32C
	ldr r2, [r2, #0x24]
	blx r2
	b _0203F334
_0203F32C:
	ldr r2, [r2, #0x28]
	blx r2
_0203F334:
	ldr r0, [sb, #4]
	add r6, r6, #1
	cmp r6, r0
	blt _0203F2E4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F348EP17UnkClass_0211E3FCP17UnkClass_020416AC
_ZN17CFieldActorManage12sub_0203F348EP17UnkClass_0211E3FCP17UnkClass_020416AC: ; 0x0203F348
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r8, r0
	ldr r0, [r8, #8]
	mov r7, r1
	mov r6, r2
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	ldr r0, [r8, #4]
	mov r5, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov sb, r5
	mov r4, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F348EP17UnkClass_0211E3FCP17UnkClass_020416AC
_0203F37C:
	ldr r0, [r8, #8]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	beq _0203F3B4
	ldrb r1, [r0, #0x20]
	mov r2, r4
	cmp r1, #2
	cmpne r1, #3
	movne r2, sb
	cmp r2, #0
	beq _0203F3B4
	mov r1, r7
	mov r2, r6
	bl _ZN11CFieldActor12sub_0203C590EP17UnkClass_0211E3FCP17UnkClass_020416AC
_0203F3B4:
	ldr r0, [r8, #4]
	add r5, r5, #1
	cmp r5, r0
	blt _0203F37C
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start sub_0203F3C8
sub_0203F3C8: ; 0x0203F3C8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r0, [r5, #4]
	mov r4, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r6, r4
	mov r7, #1
	arm_func_end sub_0203F3C8
_0203F3F4:
	ldr r0, [r5, #8]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _0203F42C
	ldrb r1, [r0, #0x20]
	mov r2, r7
	cmp r1, #2
	cmpne r1, #3
	movne r2, r6
	cmp r2, #0
	beq _0203F42C
	ldr r1, [r0]
	ldr r1, [r1, #0x34]
	blx r1
_0203F42C:
	ldr r0, [r5, #4]
	add r4, r4, #1
	cmp r4, r0
	blt _0203F3F4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_0203F440
sub_0203F440: ; 0x0203F440
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r0, [r5, #4]
	mov r4, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r6, r4
	mov r7, #1
	arm_func_end sub_0203F440
_0203F46C:
	ldr r0, [r5, #8]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _0203F4A4
	ldrb r1, [r0, #0x20]
	mov r2, r7
	cmp r1, #2
	cmpne r1, #3
	movne r2, r6
	cmp r2, #0
	beq _0203F4A4
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
_0203F4A4:
	ldr r0, [r5, #4]
	add r4, r4, #1
	cmp r4, r0
	blt _0203F46C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F4B8Ev
_ZN17CFieldActorManage12sub_0203F4B8Ev: ; 0x0203F4B8
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	ldr r4, [r0, #8]
	cmp r4, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r4, [r0, #4]
	mov r6, #0
	cmp r4, #0
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	mov r4, r6
	mov r5, #1
	mov lr, r6
	mov ip, r6
	mov sb, r6
	arm_func_end _ZN17CFieldActorManage12sub_0203F4B8Ev
_0203F4EC:
	ldr r7, [r0, #8]
	ldr r7, [r7, r6, lsl #2]
	cmp r7, #0
	beq _0203F578
	ldrb r8, [r7, #0x20]
	mov sl, r5
	cmp r8, #2
	cmpne r8, #3
	movne sl, r4
	cmp sl, #0
	ldrne r8, [r7, #8]
	cmpne r8, #0
	beq _0203F578
	ldr r8, [r8, #0xc]
	cmp r8, #0
	strne lr, [r8, #0x1b0]
	ldr r8, [r7, #8]
	ldr sl, [r8, #0xc]
	cmp sl, #0
	addne r8, sl, #0x100
	strneh r1, [r8, #0xac]
	strne ip, [sl, #0x1b0]
	ldr r8, [r7, #8]
	ldr r8, [r8, #0xc]
	cmp r8, #0
	strneb r2, [r8, #0x1c4]
	ldr r7, [r7, #8]
	ldr r8, [r7, #0xc]
	cmp r8, #0
	beq _0203F578
	ldr r7, [r8, #0x1a8]
	orr r7, r7, #1
	str r7, [r8, #0x1a8]
	str r3, [r8, #0x1b4]
	str sb, [r8, #0x1b0]
_0203F578:
	ldr r7, [r0, #4]
	add r6, r6, #1
	cmp r6, r7
	blt _0203F4EC
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F58CEv
_ZN17CFieldActorManage12sub_0203F58CEv: ; 0x0203F58C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, [r0, #8]
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r2, [r0, #4]
	mov lr, #0
	cmp r2, #0
	ldmleia sp!, {r3, r4, r5, pc}
	mov r3, lr
	mov ip, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F58CEv
_0203F5B4:
	ldr r2, [r0, #8]
	ldr r5, [r2, lr, lsl #2]
	cmp r5, #0
	beq _0203F5F0
	ldrb r2, [r5, #0x20]
	mov r4, ip
	cmp r2, #2
	cmpne r2, #3
	movne r4, r3
	cmp r4, #0
	ldrne r2, [r5, #8]
	cmpne r2, #0
	ldrne r2, [r2, #0xc]
	cmpne r2, #0
	strneb r1, [r2, #0x1c4]
_0203F5F0:
	ldr r2, [r0, #4]
	add lr, lr, #1
	cmp lr, r2
	blt _0203F5B4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F604Ev
_ZN17CFieldActorManage12sub_0203F604Ev: ; 0x0203F604
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, [r0, #8]
	cmp r2, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r2, [r0, #4]
	mov r5, #0
	cmp r2, #0
	ldmleia sp!, {r4, r5, r6, pc}
	mov lr, r5
	mov r4, #1
	mov r3, r5
	arm_func_end _ZN17CFieldActorManage12sub_0203F604Ev
_0203F630:
	ldr r2, [r0, #8]
	ldr r6, [r2, r5, lsl #2]
	cmp r6, #0
	beq _0203F674
	ldrb r2, [r6, #0x20]
	mov ip, r4
	cmp r2, #2
	cmpne r2, #3
	movne ip, lr
	cmp ip, #0
	ldrne r2, [r6, #8]
	cmpne r2, #0
	ldrne ip, [r2, #0xc]
	cmpne ip, #0
	addne r2, ip, #0x100
	strneh r1, [r2, #0xac]
	strne r3, [ip, #0x1b0]
_0203F674:
	ldr r2, [r0, #4]
	add r5, r5, #1
	cmp r5, r2
	blt _0203F630
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F688Ev
_ZN17CFieldActorManage12sub_0203F688Ev: ; 0x0203F688
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, [r0, #8]
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r2, [r0, #4]
	mov lr, #0
	cmp r2, #0
	ldmleia sp!, {r3, r4, r5, pc}
	mov r3, lr
	mov ip, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F688Ev
_0203F6B0:
	ldr r2, [r0, #8]
	ldr r5, [r2, lr, lsl #2]
	cmp r5, #0
	beq _0203F6EC
	ldrb r2, [r5, #0x20]
	mov r4, ip
	cmp r2, #2
	cmpne r2, #3
	movne r4, r3
	cmp r4, #0
	ldrne r2, [r5, #8]
	cmpne r2, #0
	ldrne r2, [r2, #0xc]
	cmpne r2, #0
	strneb r1, [r2, #0x1c5]
_0203F6EC:
	ldr r2, [r0, #4]
	add lr, lr, #1
	cmp lr, r2
	blt _0203F6B0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F700Ev
_ZN17CFieldActorManage12sub_0203F700Ev: ; 0x0203F700
	ldr r1, [r0, #8]
	cmp r1, #0
	bxeq lr
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	mov r2, r3
	arm_func_end _ZN17CFieldActorManage12sub_0203F700Ev
_0203F720:
	ldr r1, [r0, #8]
	ldr r1, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r1, #0
	ldrne r1, [r1, #8]
	cmpne r1, #0
	ldrne r1, [r1, #0xc]
	cmpne r1, #0
	strne r2, [r1, #0x1b0]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0203F720
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_0203F754Ev
_ZN17CFieldActorManage12sub_0203F754Ev: ; 0x0203F754
	ldr r1, [r0, #8]
	cmp r1, #0
	bxeq lr
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	arm_func_end _ZN17CFieldActorManage12sub_0203F754Ev
_0203F770:
	ldr r1, [r0, #8]
	ldr r1, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r1, #0
	ldrne r1, [r1, #8]
	cmpne r1, #0
	ldrne r2, [r1, #0xc]
	cmpne r2, #0
	ldrne r1, [r2, #0x1a8]
	bicne r1, r1, #1
	strne r1, [r2, #0x1a8]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0203F770
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_0203F7ACEv
_ZN17CFieldActorManage12sub_0203F7ACEv: ; 0x0203F7AC
	ldr r1, [r0, #8]
	cmp r1, #0
	bxeq lr
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	arm_func_end _ZN17CFieldActorManage12sub_0203F7ACEv
_0203F7C8:
	ldr r1, [r0, #8]
	ldr r2, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r2, #0
	ldrne r1, [r2, #4]
	bicne r1, r1, #0x100
	strne r1, [r2, #4]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0203F7C8
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_0203F7F4EP11PointPair2DliP7Point2D
_ZN17CFieldActorManage12sub_0203F7F4EP11PointPair2DliP7Point2D: ; 0x0203F7F4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x348
	sub sp, sp, #0x800
	mov sl, r0
	ldr r5, [sl, #4]
	mov r0, #0x14
	mov r4, r2
	mul r2, r5, r0
	mov r6, #0
	mov sb, r3
	ldr r3, [sp, #0xb68]
	mov r5, r1
	add r1, sp, #0x148
	mov r0, r6
	str r6, [sp, #0x3c]
	str r3, [sp, #0xb68]
	bl MIi_CpuClear32
	ldr r0, [sl, #4]
	mov r7, r6
	cmp r0, #0
	ble _0203FB68
	arm_func_end _ZN17CFieldActorManage12sub_0203F7F4EP11PointPair2DliP7Point2D
_0203F848:
	ldr r0, [sl, #8]
	ldr r8, [r0, r7, lsl #2]
	cmp r8, #0
	beq _0203FB58
	ldr r0, [r8, #4]
	mov r1, #1
	tst r0, #0x80
	ldrb r0, [r8, #0x20]
	moveq r2, #1
	movne r2, #0
	cmp r0, #2
	cmpne r0, #3
	movne r1, #0
	tst r1, r2
	beq _0203FB58
	ldr r0, [r8, #0x14]
	cmp sb, r0
	bne _0203FB58
	ldr r0, [r8, #0x50]
	cmp r0, #0
	beq _0203F8A8
	cmp r0, #1
	beq _0203FA08
	b _0203FB58
_0203F8A8:
	add r0, r8, #0x34
	add ip, sp, #0x138
	ldmia r0, {r0, r1, r2, r3}
	stmia ip, {r0, r1, r2, r3}
	ldr r0, [sp, #0x140]
	cmp r0, #0
	ldrne r0, [sp, #0x144]
	cmpne r0, #0
	beq _0203FB58
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203F8EC
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203F8F0
_0203F8EC:
	mov r2, #0
_0203F8F0:
	ldr r0, [sp, #0x138]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x138]
	beq _0203F918
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r3, [r0, #0x24]
	moveq r3, #0
	b _0203F91C
_0203F918:
	mov r3, #0
_0203F91C:
	ldr r0, [sp, #0x13c]
	ldr r2, [sp, #0x140]
	add r0, r0, r3
	add r3, r2, r4, lsl #1
	ldr r1, [sp, #0x144]
	mov ip, sp
	add r2, r1, r4, lsl #1
	add r1, sp, #0x138
	str r0, [sp, #0x13c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x144]
	ldmia r1, {r0, r1, r2, r3}
	stmia ip, {r0, r1, r2, r3}
	add r0, sp, #0xd8
	str r0, [sp, #0x10]
	ldmia r5, {r0, r1, r2, r3}
	bl _Z12sub_02006C0411PointPair2D9RectangleP7Point2D
	cmp r0, #0
	beq _0203FB58
	mov r0, #0x14
	mul r0, r6, r0
	add r2, sp, #0x148
	str r8, [r2, r0]
	add r8, r2, r0
	ldr r1, [sp, #0xd8]
	ldr r0, [sp, #0xdc]
	str r1, [r8, #8]
	str r0, [r8, #0xc]
	ldr r3, [sp, #0xd8]
	ldmia r5, {r0, r1}
	ldr r2, [sp, #0xdc]
	sub r0, r3, r0
	sub r1, r2, r1
	bl _Z12sub_02007254ll
	cmp r6, #0
	str r0, [r8, #4]
	streq r8, [sp, #0x3c]
	beq _0203FA00
	ldr r2, [sp, #0x3c]
	mov r1, #0
	movs r0, r2
	beq _0203F9F8
	ldr r3, [r8, #4]
_0203F9C8:
	ldr r0, [r2, #4]
	cmp r3, r0
	bge _0203F9E8
	cmp r1, #0
	strne r8, [r1, #0x10]
	streq r8, [sp, #0x3c]
	str r2, [r8, #0x10]
	b _0203F9F8
_0203F9E8:
	mov r1, r2
	ldr r2, [r2, #0x10]
	cmp r2, #0
	bne _0203F9C8
_0203F9F8:
	cmp r2, #0
	streq r8, [r1, #0x10]
_0203FA00:
	add r6, r6, #1
	b _0203FB58
_0203FA08:
	add r0, r8, #0x44
	add r3, sp, #0x12c
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldr r0, [sp, #0x134]
	cmp r0, #0
	beq _0203FB58
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203FA44
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203FA48
_0203FA44:
	mov r2, #0
_0203FA48:
	ldr r0, [sp, #0x12c]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x12c]
	beq _0203FA70
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x24]
	moveq r2, #0
	b _0203FA74
_0203FA70:
	mov r2, #0
_0203FA74:
	ldr r1, [sp, #0x130]
	ldr r0, [sp, #0x134]
	add r2, r1, r2
	add r1, r0, r4
	add r0, sp, #0x12c
	mov r3, sp
	str r2, [sp, #0x130]
	str r1, [sp, #0x134]
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	add r1, sp, #0xd8
	mov r0, #0
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	ldmia r5, {r0, r1, r2, r3}
	bl _Z12sub_0200676411PointPair2D6CircleP7Point2Dl
	cmp r0, #0
	beq _0203FB58
	mov r0, #0x14
	mul r0, r6, r0
	add r2, sp, #0x148
	str r8, [r2, r0]
	add r8, r2, r0
	ldr r1, [sp, #0xd8]
	ldr r0, [sp, #0xdc]
	str r1, [r8, #8]
	str r0, [r8, #0xc]
	ldr r3, [sp, #0xd8]
	ldmia r5, {r0, r1}
	ldr r2, [sp, #0xdc]
	sub r0, r3, r0
	sub r1, r2, r1
	bl _Z12sub_02007254ll
	cmp r6, #0
	str r0, [r8, #4]
	streq r8, [sp, #0x3c]
	beq _0203FB54
	ldr r2, [sp, #0x3c]
	mov r1, #0
	movs r0, r2
	beq _0203FB4C
	ldr r3, [r8, #4]
_0203FB1C:
	ldr r0, [r2, #4]
	cmp r3, r0
	bge _0203FB3C
	cmp r1, #0
	strne r8, [r1, #0x10]
	streq r8, [sp, #0x3c]
	str r2, [r8, #0x10]
	b _0203FB4C
_0203FB3C:
	mov r1, r2
	ldr r2, [r2, #0x10]
	cmp r2, #0
	bne _0203FB1C
_0203FB4C:
	cmp r2, #0
	streq r8, [r1, #0x10]
_0203FB54:
	add r6, r6, #1
_0203FB58:
	ldr r0, [sl, #4]
	add r7, r7, #1
	cmp r7, r0
	blt _0203F848
_0203FB68:
	cmp r6, #0
	beq _02040148
	ldr r1, [r5, #8]
	ldr r0, [r5]
	ldr r2, [r5, #0xc]
	subs r0, r1, r0
	ldr r1, [r5, #4]
	rsbmi r0, r0, #0
	subs r1, r2, r1
	rsbmi r1, r1, #0
	bl _Z12sub_02007254ll
	mov r6, #0
	str r0, [sp, #0x34]
	mov r0, r6
_0203FBA0:
	add r0, r0, #1
	cmp r0, #4
	add r6, r6, r4, asr r0
	blt _0203FBA0
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq _02040148
	ldr r0, [sp, #0x34]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x38]
_0203FBC8:
	ldr r0, [sp, #0x3c]
	ldr r8, [r0]
	ldr r0, [r8, #0x50]
	cmp r0, #0
	beq _0203FBE8
	cmp r0, #1
	beq _0203FE38
	b _02040134
_0203FBE8:
	add r0, r8, #0x34
	add r7, sp, #0x110
	ldmia r0, {r0, r1, r2, r3}
	stmia r7, {r0, r1, r2, r3}
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203FC18
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203FC1C
_0203FC18:
	mov r2, #0
_0203FC1C:
	ldr r0, [sp, #0x110]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x110]
	beq _0203FC44
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x24]
	moveq r2, #0
	b _0203FC48
_0203FC44:
	mov r2, #0
_0203FC48:
	ldr r1, [sp, #0x114]
	add r0, sp, #0xec
	mov r7, #0
	add r1, r1, r2
	str r1, [sp, #0x114]
	str r7, [r0]
	str r7, [r0, #4]
	str r7, [r0, #8]
	ldr r0, [sp, #0x34]
	ldr r2, [r5]
	ldr r1, [r5, #4]
	cmp r0, #0
	str r2, [sp, #0xec]
	str r1, [sp, #0xf0]
	str r4, [sp, #0xf4]
	str r2, [sp, #0x120]
	str r1, [sp, #0x124]
	str r4, [sp, #0x128]
	ldr r3, [r5]
	ldr r0, [r5, #8]
	ldr r2, [r5, #4]
	sub r0, r0, r3
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x1c]
	sub r0, r1, r2
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x1c]
	str r3, [sp, #0x98]
	str r0, [sp, #0x90]
	ldr r0, [sp, #0x14]
	str r2, [sp, #0x9c]
	str r0, [sp, #0x94]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0xc8]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0xcc]
	ble _02040134
	ldr r0, [sp, #0x1c]
	sub r8, sp, #4
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x14]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x18]
_0203FCF8:
	ldr r0, [sp, #0x34]
	add r7, r7, r6
	str r4, [sp, #0x128]
	cmp r7, r0
	bge _0203FDA4
	mov r0, r7, asr #0x1f
	mov r1, r0, lsl #0xc
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	orr r1, r1, r7, lsr #20
	mov r0, r7, lsl #0xc
	bl _ll_div
	ldr sb, [sp, #0x1c]
	mov sl, r0, asr #0x1f
	umull ip, r3, sb, r0
	mov sb, ip, lsr #0xc
	ldr ip, [sp, #0x1c]
	ldr r2, [r5]
	mla r3, ip, sl, r3
	ldr ip, [sp, #0x20]
	ldr r1, [r5, #4]
	mla r3, ip, r0, r3
	orr sb, sb, r3, lsl #20
	add r2, r2, sb
	str r2, [sp, #0x78]
	str r2, [sp, #0xc0]
	str r2, [sp, #0x120]
	ldr r2, [sp, #0x14]
	str sb, [sp, #0x88]
	str sb, [sp, #0x80]
	umull sb, r3, r2, r0
	mla r3, r2, sl, r3
	ldr r2, [sp, #0x18]
	mla r3, r2, r0, r3
	mov r2, sb, lsr #0xc
	orr r2, r2, r3, lsl #20
	add r0, r1, r2
	str r2, [sp, #0x8c]
	str r2, [sp, #0x84]
	str r0, [sp, #0x7c]
	str r0, [sp, #0xc4]
	str r0, [sp, #0x124]
	b _0203FDB4
_0203FDA4:
	ldr r0, [r5, #8]
	str r0, [sp, #0x120]
	ldr r0, [r5, #0xc]
	str r0, [sp, #0x124]
_0203FDB4:
	add r0, sp, #0xd0
	str r0, [sp, #0xc]
	mov r0, #4
	str r0, [sp, #0x10]
	add r0, sp, #0x110
	ldmia r0, {r0, r1, r2, r3}
	stmia r8, {r0, r1, r2, r3}
	add r0, sp, #0x120
	ldr r3, [r8]
	ldmia r0, {r0, r1, r2}
	bl _Z12sub_02006E306Circle9RectangleP7Point2Dl
	cmp r0, #0
	beq _0203FE28
	ldr r0, [sp, #0xb68]
	cmp r0, #0
	beq _0203FE18
	add r0, sp, #0xb8
	add r1, sp, #0x120
	add r2, sp, #0xd0
	bl _Z12sub_0200732CP6CircleP7Point2D
	ldr r1, [sp, #0xb8]
	ldr r0, [sp, #0xb68]
	str r1, [r0]
	ldr r1, [sp, #0xbc]
	str r1, [r0, #4]
_0203FE18:
	add sp, sp, #0x348
	add sp, sp, #0x800
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_0203FE28:
	ldr r0, [sp, #0x34]
	cmp r7, r0
	blt _0203FCF8
	b _02040134
_0203FE38:
	add r0, r8, #0x44
	add r3, sp, #0x104
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203FE68
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203FE6C
_0203FE68:
	mov r2, #0
_0203FE6C:
	ldr r0, [sp, #0x104]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x104]
	beq _0203FE94
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x24]
	moveq r2, #0
	b _0203FE98
_0203FE94:
	mov r2, #0
_0203FE98:
	ldr r1, [sp, #0x108]
	add r0, sp, #0xe0
	mov r7, #0
	add r1, r1, r2
	str r1, [sp, #0x108]
	str r7, [r0]
	str r7, [r0, #4]
	str r7, [r0, #8]
	ldr r0, [sp, #0x34]
	ldr r2, [r5]
	ldr r1, [r5, #4]
	cmp r0, #0
	str r2, [sp, #0xe0]
	str r1, [sp, #0xe4]
	str r4, [sp, #0xe8]
	str r2, [sp, #0x120]
	str r1, [sp, #0x124]
	str r4, [sp, #0x128]
	ldr r3, [r5]
	ldr r0, [r5, #8]
	ldr r2, [r5, #4]
	sub r0, r0, r3
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x2c]
	sub r0, r1, r2
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x2c]
	str r3, [sp, #0x70]
	str r0, [sp, #0x68]
	ldr r0, [sp, #0x24]
	str r2, [sp, #0x74]
	str r0, [sp, #0x6c]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xb0]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xb4]
	ble _02040134
	ldr r0, [sp, #0x2c]
	sub r8, sp, #4
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x24]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x28]
_0203FF48:
	ldr r0, [sp, #0x34]
	add r7, r7, r6
	str r4, [sp, #0x100]
	cmp r7, r0
	bge _0203FFF4
	mov r0, r7, asr #0x1f
	mov r1, r0, lsl #0xc
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	orr r1, r1, r7, lsr #20
	mov r0, r7, lsl #0xc
	bl _ll_div
	ldr sb, [sp, #0x2c]
	mov sl, r0, asr #0x1f
	umull ip, r3, sb, r0
	mov sb, ip, lsr #0xc
	ldr ip, [sp, #0x2c]
	ldr r2, [r5]
	mla r3, ip, sl, r3
	ldr ip, [sp, #0x30]
	ldr r1, [r5, #4]
	mla r3, ip, r0, r3
	orr sb, sb, r3, lsl #20
	add r2, r2, sb
	str r2, [sp, #0x50]
	str r2, [sp, #0xa8]
	str r2, [sp, #0xf8]
	ldr r2, [sp, #0x24]
	str sb, [sp, #0x60]
	str sb, [sp, #0x58]
	umull sb, r3, r2, r0
	mla r3, r2, sl, r3
	ldr r2, [sp, #0x28]
	mla r3, r2, r0, r3
	mov r2, sb, lsr #0xc
	orr r2, r2, r3, lsl #20
	add r0, r1, r2
	str r2, [sp, #0x64]
	str r2, [sp, #0x5c]
	str r0, [sp, #0x54]
	str r0, [sp, #0xac]
	str r0, [sp, #0xfc]
	b _02040004
_0203FFF4:
	ldr r0, [r5, #8]
	str r0, [sp, #0xf8]
	ldr r0, [r5, #0xc]
	str r0, [sp, #0xfc]
_02040004:
	add r0, sp, #0xd0
	str r0, [sp, #8]
	add r0, sp, #0x104
	ldmia r0, {r0, r1, r2}
	stmia r8, {r0, r1, r2}
	add r0, sp, #0xf8
	ldr r3, [r8]
	ldmia r0, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	beq _02040128
	ldr r3, [sp, #0x104]
	ldr r0, [sp, #0xd0]
	ldr r2, [sp, #0x108]
	ldr r1, [sp, #0xd4]
	sub r0, r0, r3
	sub r1, r1, r2
	str r0, [sp, #0xd0]
	str r3, [sp, #0x48]
	str r2, [sp, #0x4c]
	str r1, [sp, #0xd4]
	bl _Z12sub_02007254ll
	mov r5, r0
	ldr r4, [sp, #0x10c]
	ldr r1, [sp, #0xd0]
	mov r7, r5, asr #0x1f
	smull r2, r0, r1, r4
	mov r6, r2, lsr #0xc
	orr r6, r6, r0, lsl #20
	mov r0, r6, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, r5
	mov r3, r7
	orr r1, r1, r6, lsr #20
	mov r0, r6, lsl #0xc
	bl _ll_div
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0xd4]
	mov r2, r5
	smull r4, r1, r0, r4
	mov r4, r4, lsr #0xc
	orr r4, r4, r1, lsl #20
	mov r0, r4, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r3, r7
	orr r1, r1, r4, lsr #20
	mov r0, r4, lsl #0xc
	bl _ll_div
	ldr r1, [sp, #0xb68]
	ldr r2, [sp, #0x104]
	cmp r1, #0
	ldr r1, [sp, #0x108]
	str r2, [sp, #0x40]
	add r0, r0, r1
	str r0, [sp, #0xd4]
	ldr r0, [sp, #0xd0]
	str r1, [sp, #0x44]
	add r0, r0, r2
	str r0, [sp, #0xd0]
	beq _02040118
	add r0, sp, #0xa0
	add r1, sp, #0xf8
	add r2, sp, #0xd0
	bl _Z12sub_0200732CP6CircleP7Point2D
	ldr r1, [sp, #0xa0]
	ldr r0, [sp, #0xb68]
	str r1, [r0]
	ldr r1, [sp, #0xa4]
	str r1, [r0, #4]
_02040118:
	add sp, sp, #0x348
	add sp, sp, #0x800
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_02040128:
	ldr r0, [sp, #0x34]
	cmp r7, r0
	blt _0203FF48
_02040134:
	ldr r0, [sp, #0x3c]
	ldr r0, [r0, #0x10]
	str r0, [sp, #0x3c]
	cmp r0, #0
	bne _0203FBC8
_02040148:
	mov r0, #0
	add sp, sp, #0x348
	add sp, sp, #0x800
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start _ZN17CFieldActorManage12sub_02040158E7Point2Dli
_ZN17CFieldActorManage12sub_02040158E7Point2Dli: ; 0x02040158
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x34
	add r7, sp, #0x28
	mov r8, #0
	str r8, [r7, #8]
	ldr r2, [sp, #0x5c]
	str r8, [r7]
	ldr r1, [sp, #0x60]
	str r8, [r7, #4]
	mov sl, r0
	str r2, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r3, [sp, #0x30]
	ldr r0, [sl, #4]
	ldr sb, [sp, #0x68]
	cmp r0, #0
	ble _02040370
	sub r5, sp, #4
	mov fp, r8
	add r4, sp, #0xc
	add r6, sp, #0x18
	arm_func_end _ZN17CFieldActorManage12sub_02040158E7Point2Dli
_020401B0:
	ldr r0, [sl, #8]
	ldr ip, [r0, r8, lsl #2]
	cmp ip, #0
	beq _02040360
	ldr r0, [ip, #4]
	mov r1, #1
	tst r0, #0x80
	ldrb r0, [ip, #0x20]
	moveq r2, #1
	movne r2, #0
	cmp r0, #2
	cmpne r0, #3
	movne r1, #0
	tst r1, r2
	beq _02040360
	ldr r0, [ip, #0x14]
	cmp sb, r0
	bne _02040360
	ldr r0, [ip, #0x50]
	cmp r0, #0
	beq _02040210
	cmp r0, #1
	beq _020402BC
	b _02040360
_02040210:
	add r0, ip, #0x34
	ldmia r0, {r0, r1, r2, r3}
	stmia r6, {r0, r1, r2, r3}
	ldr r0, [sp, #0x20]
	cmp r0, #0
	ldrne r0, [sp, #0x24]
	cmpne r0, #0
	beq _02040360
	ldr r1, [ip, #8]
	cmp r1, #0
	beq _02040250
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _02040254
_02040250:
	mov r2, #0
_02040254:
	cmp r1, #0
	ldr r0, [sp, #0x18]
	add r0, r0, r2
	str r0, [sp, #0x18]
	beq _0204027C
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r1, [r0, #0x24]
	moveq r1, #0
	b _02040280
_0204027C:
	mov r1, #0
_02040280:
	ldr r0, [sp, #0x1c]
	add r0, r0, r1
	str r0, [sp, #0x1c]
	ldmia r6, {r0, r1, r2, r3}
	stmia r5, {r0, r1, r2, r3}
	ldr r3, [r5]
	ldmia r7, {r0, r1, r2}
	bl _Z12sub_02006F806Circle9Rectangle
	cmp r0, #0
	beq _02040360
	add sp, sp, #0x34
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	add sp, sp, #0x10
	bx lr
_020402BC:
	add r0, ip, #0x44
	ldmia r0, {r0, r1, r2}
	stmia r4, {r0, r1, r2}
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02040360
	ldr r1, [ip, #8]
	cmp r1, #0
	beq _020402F4
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _020402F8
_020402F4:
	mov r2, #0
_020402F8:
	cmp r1, #0
	ldr r0, [sp, #0xc]
	add r0, r0, r2
	str r0, [sp, #0xc]
	beq _02040320
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r1, [r0, #0x24]
	moveq r1, #0
	b _02040324
_02040320:
	mov r1, #0
_02040324:
	ldr r0, [sp, #0x10]
	add r0, r0, r1
	str r0, [sp, #0x10]
	str fp, [sp, #8]
	ldmia r4, {r0, r1, r2}
	stmia r5, {r0, r1, r2}
	ldr r3, [r5]
	ldmia r7, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	addne sp, sp, #0x10
	bxne lr
_02040360:
	add r8, r8, #1
	ldr r0, [sl, #4]
	cmp r8, r0
	blt _020401B0
_02040370:
	mov r0, #0
	add sp, sp, #0x34
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_02040384Ev
_ZN17CFieldActorManage12sub_02040384Ev: ; 0x02040384
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #8
	mov r6, r0
	ldr r0, [r6, #4]
	mov r5, #0
	cmp r0, #0
	addle sp, sp, #8
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	addle sp, sp, #0x10
	bxle lr
	ldr r8, [sp, #0x2c]
	ldr r7, [sp, #0x30]
	add r4, sp, #0x2c
	arm_func_end _ZN17CFieldActorManage12sub_02040384Ev
_020403BC:
	ldr r0, [r6, #8]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldrne sb, [r0, #8]
	cmpne sb, #0
	ldrne r0, [sb, #0xc]
	cmpne r0, #0
	beq _02040408
	add r0, r0, #0xc
	ldmia r4, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	beq _02040408
	str r8, [r0, #0x18]
	str r8, [sp]
	str r7, [sp, #4]
	str r7, [r0, #0x1c]
_02040408:
	ldr r0, [r6, #4]
	add r5, r5, #1
	cmp r5, r0
	blt _020403BC
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_02040428Ev
_ZN17CFieldActorManage12sub_02040428Ev: ; 0x02040428
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	mov r2, #2
	arm_func_end _ZN17CFieldActorManage12sub_02040428Ev
_0204043C:
	ldr r1, [r0, #8]
	ldr r1, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r1, #0
	strneb r2, [r1, #0x20]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0204043C
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_02040460Ev
_ZN17CFieldActorManage12sub_02040460Ev: ; 0x02040460
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	ldr r0, [r4, #4]
	mov r6, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r5, r6
	arm_func_end _ZN17CFieldActorManage12sub_02040460Ev
_0204047C:
	ldr r0, [r4, #8]
	ldr r7, [r0, r6, lsl #2]
	cmp r7, #0
	beq _020404A8
	mov r0, r7
	bl sub_02041C1C
	mov r0, r7
	strb r5, [r7, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x1c]
	blx r1
_020404A8:
	ldr r0, [r4, #4]
	add r6, r6, #1
	cmp r6, r0
	blt _0204047C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN16CFieldDrawObjectC1Ev
_ZN16CFieldDrawObjectC1Ev: ; 0x020404BC
	ldr r1, _020404E0 ; =PTR_LAB_0208de68
	mov r2, #0
	str r1, [r0]
	ldr r1, _020404E4 ; =PTR_LAB_0208de54
	stmia r0, {r1, r2}
	str r2, [r0, #0xc]
	str r2, [r0, #0x10]
	str r2, [r0, #0x14]
	bx lr
	.align 2, 0
_020404E0: .word PTR_LAB_0208de68
_020404E4: .word PTR_LAB_0208de54
	arm_func_end _ZN16CFieldDrawObjectC1Ev

	arm_func_start sub_020404E8
sub_020404E8: ; 0x020404E8
	stmdb sp!, {r4, lr}
	ldr r1, _02040504 ; =PTR_LAB_0208de54
	mov r4, r0
	str r1, [r4]
	bl sub_02040638
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02040504: .word PTR_LAB_0208de54
	arm_func_end sub_020404E8

	arm_func_start sub_02040508
sub_02040508: ; 0x02040508
	stmdb sp!, {r4, lr}
	ldr r1, _0204052C ; =PTR_LAB_0208de54
	mov r4, r0
	str r1, [r4]
	bl sub_02040638
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0204052C: .word PTR_LAB_0208de54
	arm_func_end sub_02040508

	arm_func_start _ZN16CFieldDrawObject12sub_02040530Eitimi
_ZN16CFieldDrawObject12sub_02040530Eitimi: ; 0x02040530
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #8
	mov r7, r0
	ldr r0, [r7, #0xc]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp r0, #0
	beq _0204056C
	beq _02040564
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end _ZN16CFieldDrawObject12sub_02040530Eitimi
_02040564:
	mov r0, #0
	str r0, [r7, #0xc]
_0204056C:
	mov r0, #0x204
	bl _Znwm
	cmp r0, #0
	beq _02040580
	bl _ZN15CFieldDrawActorC1Ev
_02040580:
	ldr r1, [sp, #0x20]
	str r0, [r7, #0xc]
	ldr r0, [sp, #0x24]
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r7, #0xc]
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl _ZN15CFieldDrawActor12sub_0203DBB8Eitimi
	mov r0, #1
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN16CFieldDrawObject12sub_020405B4Eitimi
_ZN16CFieldDrawObject12sub_020405B4Eitimi: ; 0x020405B4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #8
	mov r7, r0
	ldr r0, [r7, #0xc]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp r0, #0
	beq _020405F0
	beq _020405E8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end _ZN16CFieldDrawObject12sub_020405B4Eitimi
_020405E8:
	mov r0, #0
	str r0, [r7, #0xc]
_020405F0:
	mov r0, #0x204
	bl _Znwm
	cmp r0, #0
	beq _02040604
	bl _ZN15CFieldDrawActorC1Ev
_02040604:
	ldr r1, [sp, #0x20]
	str r0, [r7, #0xc]
	ldr r0, [sp, #0x24]
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r7, #0xc]
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl _ZN15CFieldDrawActor12sub_0203E10CEitimi
	mov r0, #1
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02040638
sub_02040638: ; 0x02040638
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	beq _0204065C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02040638
_0204065C:
	mov r0, #0
	str r0, [r4, #0xc]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040668
sub_02040668: ; 0x02040668
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x10
	mov r7, r0
	mov r5, r2
	str r5, [r7, #0x10]
	ldr r0, [r7, #0xc]
	mov ip, #0
	mov r6, r1
	cmp r0, #0
	add r4, ip, #4
	beq _02040728
	add r0, r0, #0x1e4
	add lr, sp, #0
	ldmia r0, {r0, r1, r2, r3}
	stmia lr, {r0, r1, r2, r3}
	ldr r0, [r7, #0xc]
	cmp r0, #0
	ldrne ip, [r0, #0x20]
	ldr r0, [sp]
	add r0, r0, ip
	str r0, [sp]
	ldr r2, [r7, #0xc]
	cmp r2, #0
	ldrne r3, [r2, #0x24]
	moveq r3, #0
	cmp r2, #0
	moveq r0, #0
	beq _020406EC
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r0, r2, r0
	arm_func_end sub_02040668
_020406EC:
	ldr r1, [sp, #4]
	sub r0, r3, r0
	add r3, r1, r0
	ldr r2, _0204073C ; =0x00001199
	add r1, sp, #0
	mov r0, r6
	str r3, [sp, #4]
	bl _ZN8Camera2D12sub_020038A8EP9Rectanglel
	cmp r0, #0
	beq _02040728
	ldr r0, [r7, #0xc]
	mov r1, r6
	sub r2, r5, r4
	bl _ZN15CFieldDrawActor12sub_0203E934EP8Camera2Dl
	add r4, r4, r0
_02040728:
	sub r0, r5, r4
	str r0, [r7, #0x14]
	add r0, r4, #4
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0204073C: .word 0x00001199

	arm_func_start _ZN16CFieldDrawObject12sub_02040740Ev
_ZN16CFieldDrawObject12sub_02040740Ev: ; 0x02040740
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _02040760
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end _ZN16CFieldDrawObject12sub_02040740Ev
_02040760:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040778
sub_02040778: ; 0x02040778
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02040778

	arm_func_start sub_0204078C
sub_0204078C: ; 0x0204078C
	bx lr
	arm_func_end sub_0204078C

	arm_func_start sub_02040790
sub_02040790: ; 0x02040790
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CActorDataC2Ev
	ldr r1, _020407DC ; =ptr_FUN_02040f20_0208dec0
	mvn r0, #0
	str r1, [r4]
	str r0, [r4, #0x18]
	add r0, r0, #0x10000
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	mov r1, #0
	strh r1, [r4, #0x20]
	str r1, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	mov r0, r4
	str r1, [r4, #0x30]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020407DC: .word ptr_FUN_02040f20_0208dec0
	arm_func_end sub_02040790

	arm_func_start _ZN19CFieldDrawActorDataC1Ev
_ZN19CFieldDrawActorDataC1Ev: ; 0x020407E0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CActorDataC2Ev
	ldr r1, _0204082C ; =ptr_FUN_02040f20_0208dec0
	mvn r0, #0
	str r1, [r4]
	str r0, [r4, #0x18]
	add r0, r0, #0x10000
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	mov r1, #0
	strh r1, [r4, #0x20]
	str r1, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	mov r0, r4
	str r1, [r4, #0x30]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0204082C: .word ptr_FUN_02040f20_0208dec0
	arm_func_end _ZN19CFieldDrawActorDataC1Ev

	arm_func_start _ZN19CFieldDrawActorData12sub_02040830Eititiii
_ZN19CFieldDrawActorData12sub_02040830Eititiii: ; 0x02040830
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x14
	mov r8, r1
	mov sb, r0
	mov r7, r2
	mov r6, r3
	cmp r8, #2
	ldr r5, [sp, #0x30]
	ldr r4, [sp, #0x34]
	beq _020408A8
	cmp r4, #0
	beq _02040884
	str r5, [sp]
	mov lr, #1
	ldr ip, [sp, #0x38]
	str lr, [sp, #4]
	str ip, [sp, #8]
	mov ip, #0
	str ip, [sp, #0xc]
	bl _ZN10CActorData12sub_02013154EiiitiPKcm
	b _020408C8
	arm_func_end _ZN19CFieldDrawActorData12sub_02040830Eititiii
_02040884:
	ldr ip, [sp, #0x38]
	stmia sp, {r5, ip}
	mov ip, #0
	str ip, [sp, #8]
	mov ip, #1
	str ip, [sp, #0xc]
	str r4, [sp, #0x10]
	bl _ZN10CActorData12sub_02014514EiiitPKcmmi
	b _020408C8
_020408A8:
	mov r1, #0
	ldr ip, [sp, #0x38]
	str r1, [sp]
	mov r1, r7
	mov r2, r6
	mov r3, r5
	str ip, [sp, #4]
	bl sub_020409B4
_020408C8:
	str r8, [sb, #0x18]
	strh r7, [sb, #0x1c]
	strh r6, [sb, #0x1e]
	ldr r0, [sp, #0x3c]
	str r4, [sb, #0x28]
	strh r5, [sb, #0x20]
	cmp r0, #0
	beq _02040980
	cmp r4, #0
	bne _02040924
	mov r0, sb
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	mov r1, r1, lsl #0x10
	str r0, [sb, #0x2c]
	mov r0, sb
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_020141ACEm
	mov r0, sb
	bl _ZN10CActorData12sub_020142B4Ev
_02040924:
	mov r0, sb
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [sb, #0x30]
	cmp r4, #0
	beq _02040964
	ldr r0, [sb, #0xc]
	cmp r0, #0
	beq _02040980
	ldr r1, [sb, #0x30]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007C34Em
	b _02040980
_02040964:
	ldr r1, [sb, #0x30]
	mov r0, sb
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_0201429CEm
	mov r0, sb
	bl _ZN10CActorData12sub_020142F8Ev
_02040980:
	ldr r4, [sb, #8]
	cmp r4, #0
	addeq sp, sp, #0x14
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, pc}
	beq _020409A4
	mov r0, r4
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r4
	bl _ZdlPv
_020409A4:
	mov r0, #0
	str r0, [sb, #8]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

	arm_func_start sub_020409B4
sub_020409B4: ; 0x020409B4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x1f8
	ldr ip, [r0]
	mov r8, r0
	ldr ip, [ip, #8]
	mov r5, r1
	mov r4, r2
	mov r7, r3
	ldr r6, [sp, #0x218]
	blx ip
	mov sb, #0
	mov r1, sb
	mov r0, #1
	arm_func_end sub_020409B4
_020409E8:
	tst r7, r0, lsl r1
	add r1, r1, #1
	addne sb, sb, #1
	cmp r1, #0x1d
	blt _020409E8
	cmp sb, #0
	addeq sp, sp, #0x1f8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	mov sl, sb, lsl #4
	mov r0, sl
	mov r1, #4
	bl _Z23Heap_AllocWithAlignmentmm
	str r0, [r8, #0x10]
	mov r1, r0
	mov r2, sl
	mov r0, #0
	bl MIi_CpuClearFast
	strb sb, [r8, #0x14]
	mov r0, #1
	strb r0, [r8, #5]
	strb r0, [r8, #6]
	ldr r1, _02040D24 ; =s_t_03d_02d_0208df10
	mov r2, r5
	mov r3, r4
	add r0, sp, #0x198
	bl OS_SPrintf
	ldr r1, [sp, #0x21c]
	add r0, sp, #0x14
	cmp r1, #0
	beq _02040A68
	bl STD_CopyString
	b _02040A70
_02040A68:
	ldr r1, _02040D28 ; =DAT_0208df1c
	bl STD_CopyString
_02040A70:
	ldr r1, _02040D2C ; =s_data_target_s_LZ_bin_0208df20
	add r0, sp, #0x138
	add r2, sp, #0x198
	bl OS_SPrintf
	mov r0, #0x6c
	bl _Znwm
	cmp r0, #0
	beq _02040AC0
	mov r1, #1
	str r1, [sp]
	mov r4, #0
	cmp r6, #0
	moveq r3, #1
	str r4, [sp, #4]
	str r4, [sp, #8]
	movne r3, #0
	add r1, sp, #0x14
	add r2, sp, #0x138
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
_02040AC0:
	cmp r0, #0
	addeq sp, sp, #0x1f8
	str r0, [r8, #8]
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r1, _02040D30 ; =s_s_s_NCLR_0208df38
	add r0, sp, #0xd8
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	add r0, sp, #0xd8
	bl NNS_FndGetArchiveFileByName
	cmp r0, #0
	beq _02040B20
	add r1, sp, #0x10
	bl NNS_G2dGetUnpackedPaletteData
	cmp r0, #0
	beq _02040B20
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02040B1C
	ldr r1, [sp, #0x10]
	bl _ZN17UnkClass_02007AA4C1EP17NNSG2dPaletteData
_02040B1C:
	str r0, [r8, #0xc]
_02040B20:
	ldr r1, _02040D34 ; =s_s_s_0208df44
	add r0, sp, #0x18
	add r2, sp, #0x14
	add r3, sp, #0x198
	mov r4, #0
	bl OS_SPrintf
	tst r7, #1
	mov r5, r4
	beq _02040B84
	ldr r1, _02040D34 ; =s_s_s_0208df44
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	mov r0, r4
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
	ldr r0, [r8, #0x10]
	mov r1, r4
	strb r1, [r0, #1]
	add r5, r5, #1
_02040B84:
	tst r7, #2
	beq _02040C10
	ldr r1, _02040D38 ; =s_s_s_s_0208df4c
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x18
	add r3, sp, #0x78
	mov r0, r8
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014EA4EP10CActorAnimPKcS3_P17UnkClass_020074D4mi
	cmp r0, #0
	ldrne r0, [r8, #0x10]
	addne r0, r0, r5, lsl #4
	ldrne r4, [r0, #4]
	bne _02040BFC
	mov r0, #0
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
_02040BFC:
	ldr r0, [r8, #0x10]
	mov r1, #1
	add r0, r0, r5, lsl #4
	strb r1, [r0, #1]
	add r5, r5, #1
_02040C10:
	tst r7, #4
	beq _02040C9C
	ldr r1, _02040D3C ; =s_s_s_a_0208df54
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	str r4, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x18
	add r3, sp, #0x78
	mov r0, r8
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014EA4EP10CActorAnimPKcS3_P17UnkClass_020074D4mi
	cmp r0, #0
	ldrne r0, [r8, #0x10]
	addne r0, r0, r5, lsl #4
	ldrne r4, [r0, #4]
	bne _02040C88
	mov r0, #0
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
_02040C88:
	ldr r0, [r8, #0x10]
	mov r1, #2
	add r0, r0, r5, lsl #4
	strb r1, [r0, #1]
	add r5, r5, #1
_02040C9C:
	tst r7, #8
	addeq sp, sp, #0x1f8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r1, _02040D40 ; =s_s_s_c_0208df5c
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	str r4, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x18
	add r3, sp, #0x78
	mov r0, r8
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014EA4EP10CActorAnimPKcS3_P17UnkClass_020074D4mi
	cmp r0, #0
	bne _02040D0C
	mov r0, #0
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
_02040D0C:
	ldr r0, [r8, #0x10]
	mov r1, #3
	add r0, r0, r5, lsl #4
	strb r1, [r0, #1]
	add sp, sp, #0x1f8
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02040D24: .word s_t_03d_02d_0208df10
_02040D28: .word DAT_0208df1c
_02040D2C: .word s_data_target_s_LZ_bin_0208df20
_02040D30: .word s_s_s_NCLR_0208df38
_02040D34: .word s_s_s_0208df44
_02040D38: .word s_s_s_s_0208df4c
_02040D3C: .word s_s_s_a_0208df54
_02040D40: .word s_s_s_c_0208df5c

	arm_func_start sub_02040D44
sub_02040D44: ; 0x02040D44
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x24]
	cmp r0, #0
	ldmleia sp!, {r4, pc}
	subs r0, r0, #1
	str r0, [r4, #0x24]
	ldmneia sp!, {r4, pc}
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _02040D78
	ldr r0, [r4, #0x2c]
	bl NNS_GfdFreeLnkTexVram
	arm_func_end sub_02040D44
_02040D78:
	ldr r0, [r4, #0x30]
	bl NNS_GfdFreeLnkPlttVram
	mov r0, r4
	bl _ZN10CActorData7ReleaseEv
	mvn r0, #0
	str r0, [r4, #0x18]
	add r0, r0, #0x10000
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	mov r1, #0
	str r1, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040DB8
sub_02040DB8: ; 0x02040DB8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _02040DDC
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _02040DDC
	bl NNS_GfdFreeLnkTexVram
	arm_func_end sub_02040DB8
_02040DDC:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _02040DEC
	bl NNS_GfdFreeLnkPlttVram
_02040DEC:
	mov r0, r4
	bl _ZN10CActorData7ReleaseEv
	mov r2, #0
	str r2, [r4, #0x24]
	sub r1, r2, #1
	ldr r0, _02040E28 ; =0x0000FFFF
	str r1, [r4, #0x18]
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	str r2, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r2, [r4, #0x2c]
	str r2, [r4, #0x30]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02040E28: .word 0x0000FFFF

	arm_func_start sub_02040E2C
sub_02040E2C: ; 0x02040E2C
	stmdb sp!, {r4, lr}
	ldr r1, [r0]
	mov r4, r0
	ldr r1, [r1, #0x20]
	blx r1
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _02040E64
	mov r0, r4
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	str r0, [r4, #0x2c]
	arm_func_end sub_02040E2C
_02040E64:
	mov r0, r4
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN19CFieldDrawActorData12sub_02040E80Ev
_ZN19CFieldDrawActorData12sub_02040E80Ev: ; 0x02040E80
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _02040EA0
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4, #0x2c]
	arm_func_end _ZN19CFieldDrawActorData12sub_02040E80Ev
_02040EA0:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN19CFieldDrawActorData12sub_02040EBCEv
_ZN19CFieldDrawActorData12sub_02040EBCEv: ; 0x02040EBC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x28]
	cmp r1, #0
	bne _02040EE0
	ldr r1, [r4, #0x2c]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_020141ACEm
	arm_func_end _ZN19CFieldDrawActorData12sub_02040EBCEv
_02040EE0:
	ldr r1, [r4, #0x30]
	mov r0, r4
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_0201429CEm
	ldmia sp!, {r4, pc}

	arm_func_start _ZN19CFieldDrawActorData12sub_02040EF8Ev
_ZN19CFieldDrawActorData12sub_02040EF8Ev: ; 0x02040EF8
	stmdb sp!, {r3, lr}
	mov r1, r0
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r1, #0x30]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007C34Em
	ldmia sp!, {r3, pc}
	arm_func_end _ZN19CFieldDrawActorData12sub_02040EF8Ev

	arm_func_start sub_02040F20
sub_02040F20: ; 0x02040F20
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02040F20

	arm_func_start _ZN17UnkClass_02040F34C1Ev
_ZN17UnkClass_02040F34C1Ev: ; 0x02040F34
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02040F7C ; =MAIN_BSS_0210CA64
	mov r4, r0
	str r4, [r1]
	mov r1, #0x28
	ldr r0, _02040F80 ; =sub_02040F20
	str r1, [r4]
	str r0, [sp]
	ldr r0, [r4]
	ldr r3, _02040F84 ; =_ZN19CFieldDrawActorDataC1Ev
	mov r1, #0x34
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #4]
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02040F7C: .word MAIN_BSS_0210CA64
_02040F80: .word sub_02040F20
_02040F84: .word _ZN19CFieldDrawActorDataC1Ev
	arm_func_end _ZN17UnkClass_02040F34C1Ev

	arm_func_start _ZN17UnkClass_02040F34D1Ev
_ZN17UnkClass_02040F34D1Ev: ; 0x02040F88
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4]
	mov r5, #0
	cmp r0, #0
	ble _02040FC4
	mov r6, r5
	arm_func_end _ZN17UnkClass_02040F34D1Ev
_02040FA4:
	ldr r0, [r4, #4]
	add r0, r0, r6
	bl sub_02040DB8
	ldr r0, [r4]
	add r5, r5, #1
	cmp r5, r0
	add r6, r6, #0x34
	blt _02040FA4
_02040FC4:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _02040FE8
	ldr r3, _02041000 ; =sub_02040F20
	mov r1, #0x34
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #4]
_02040FE8:
	mov r2, #0
	ldr r1, _02041004 ; =MAIN_BSS_0210CA64
	str r2, [r4]
	mov r0, r4
	str r2, [r1]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02041000: .word sub_02040F20
_02041004: .word MAIN_BSS_0210CA64

	arm_func_start _ZN17UnkClass_02040F3412sub_02041008Eititi
_ZN17UnkClass_02040F3412sub_02041008Eititi: ; 0x02041008
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x14
	mov r8, r1
	ldr r1, [r0]
	mov r7, r2
	mov r6, r3
	cmp r1, #0
	ldr r5, [sp, #0x30]
	ldr r4, [sp, #0x34]
	mov r3, #0
	ble _02041094
	ldr sb, [r0, #4]
	arm_func_end _ZN17UnkClass_02040F3412sub_02041008Eititi
_02041038:
	ldr r2, [sb, #0x24]
	cmp r2, #0
	ble _02041084
	ldr ip, [sb, #0x18]
	cmp r8, ip
	ldreqh ip, [sb, #0x1c]
	cmpeq r7, ip
	ldreqh ip, [sb, #0x1e]
	cmpeq r6, ip
	ldreqh ip, [sb, #0x20]
	cmpeq r5, ip
	ldreq ip, [sb, #0x28]
	cmpeq r4, ip
	bne _02041084
	add r1, r2, #1
	add sp, sp, #0x14
	mov r0, sb
	str r1, [sb, #0x24]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
_02041084:
	add r3, r3, #1
	cmp r3, r1
	add sb, sb, #0x34
	blt _02041038
_02041094:
	cmp r1, #0
	mov r2, #0
	ble _02041108
	ldr sb, [r0, #4]
_020410A4:
	ldr r0, [sb, #0x24]
	cmp r0, #0
	bne _020410F8
	ldr r1, _0204111C ; =s_F_02d_0208df64
	add r0, sp, #0x10
	bl OS_SPrintf
	str r5, [sp]
	add r5, sp, #0x10
	stmib sp, {r4, r5}
	mov r4, #1
	mov r0, sb
	mov r1, r8
	mov r2, r7
	mov r3, r6
	str r4, [sp, #0xc]
	bl _ZN19CFieldDrawActorData12sub_02040830Eititiii
	mov r1, r4
	add sp, sp, #0x14
	mov r0, sb
	str r1, [sb, #0x24]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
_020410F8:
	add r2, r2, #1
	cmp r2, r1
	add sb, sb, #0x34
	blt _020410A4
_02041108:
	ldr r0, _02041120 ; =s_NO_EMPTY_m_nActorDataMax_d_0208df6c
	bl LogInfo
	mov r0, #0
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0204111C: .word s_F_02d_0208df64
_02041120: .word s_NO_EMPTY_m_nActorDataMax_d_0208df6c

	arm_func_start _ZN17CActorDataPartnerC1Ev
_ZN17CActorDataPartnerC1Ev: ; 0x02041124
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02040790
	ldr r0, _02041148 ; =ptr_FUN_0204114c_0208deec
	mov r1, #0
	str r0, [r4]
	mov r0, r4
	str r1, [r4, #0x34]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041148: .word ptr_FUN_0204114c_0208deec
	arm_func_end _ZN17CActorDataPartnerC1Ev

	arm_func_start _ZN17CActorDataPartnerD1Ev
_ZN17CActorDataPartnerD1Ev: ; 0x0204114C
	stmdb sp!, {r4, lr}
	ldr r1, _02041178 ; =ptr_FUN_0204114c_0208deec
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041178: .word ptr_FUN_0204114c_0208deec
	arm_func_end _ZN17CActorDataPartnerD1Ev

	arm_func_start sub_0204117C
sub_0204117C: ; 0x0204117C
	stmdb sp!, {r4, lr}
	ldr r1, _020411B0 ; =ptr_FUN_0204114c_0208deec
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_020411B0: .word ptr_FUN_0204114c_0208deec
	arm_func_end sub_0204117C

	arm_func_start sub_020411B4
sub_020411B4: ; 0x020411B4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x34]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	bl sub_02040DB8
	mov r0, #0
	str r0, [r4, #0x34]
	ldmia sp!, {r4, pc}
	arm_func_end sub_020411B4

	arm_func_start sub_020411D8
sub_020411D8: ; 0x020411D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x28]
	cmp r1, #0
	ldreq r1, [r4, #0x2c]
	cmpeq r1, #0
	bne _02041208
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	str r0, [r4, #0x2c]
	arm_func_end sub_020411D8
_02041208:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, r4
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17CActorDataPartner12sub_02041230Eitit
_ZN17CActorDataPartner12sub_02041230Eitit: ; 0x02041230
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x10
	mov r7, r0
	ldr ip, [r7, #0x34]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp ip, #0
	beq _02041260
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end _ZN17CActorDataPartner12sub_02041230Eitit
_02041260:
	ldrh r1, [sp, #0x28]
	mov r0, #1
	mov ip, #0
	str r1, [sp]
	stmib sp, {r0, ip}
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	str ip, [sp, #0xc]
	bl _ZN19CFieldDrawActorData12sub_02040830Eititiii
	mov r0, #1
	str r0, [r7, #0x34]
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_0204129C
sub_0204129C: ; 0x0204129C
	bx lr
	arm_func_end sub_0204129C

	arm_func_start _ZN17UnkClass_020412A0C1Ev
_ZN17UnkClass_020412A0C1Ev: ; 0x020412A0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02040790
	ldr r1, _020412D0 ; =ptr_FUN_020412dc_0208dfb4
	mov r0, r4
	str r1, [r4]
	bl _ZN10CActorData4InitEv
	ldr r2, _020412D4 ; =0x0000FFFF
	ldr r1, _020412D8 ; =0x00050834
	mov r0, r4
	strh r2, [r4, r1]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020412D0: .word ptr_FUN_020412dc_0208dfb4
_020412D4: .word 0x0000FFFF
_020412D8: .word 0x00050834
	arm_func_end _ZN17UnkClass_020412A0C1Ev

	arm_func_start _ZN17UnkClass_020412A0D1Ev
_ZN17UnkClass_020412A0D1Ev: ; 0x020412DC
	stmdb sp!, {r4, lr}
	ldr r1, _02041308 ; =ptr_FUN_020412dc_0208dfb4
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041308: .word ptr_FUN_020412dc_0208dfb4
	arm_func_end _ZN17UnkClass_020412A0D1Ev

	arm_func_start sub_0204130C
sub_0204130C: ; 0x0204130C
	stmdb sp!, {r4, lr}
	ldr r1, _02041340 ; =ptr_FUN_020412dc_0208dfb4
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041340: .word ptr_FUN_020412dc_0208dfb4
	arm_func_end sub_0204130C

	arm_func_start _ZN17UnkClass_020412A012sub_02041344EtimPKcii
_ZN17UnkClass_020412A012sub_02041344EtimPKcii: ; 0x02041344
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x198
	ldr r2, _020415AC ; =0x00050834
	mov sl, r0
	ldrh r2, [sl, r2]
	mov sb, r1
	mov r8, r3
	cmp r2, sb
	addeq sp, sp, #0x198
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, #0x1d0
	mov r1, #4
	bl _Z23Heap_AllocWithAlignmentmm
	str r0, [sl, #0x10]
	mov r1, r0
	mov r0, #0
	mov r2, #0x1d0
	bl MIi_CpuClearFast
	mov r0, #0x1d
	strb r0, [sl, #0x14]
	mov r0, #0
	strb r0, [sl, #5]
	ldr r1, _020415B0 ; =s_player_1d_0208dfd8
	add r0, sp, #0x138
	mov r2, sb
	bl OS_SPrintf
	ldr r1, [sp, #0x1c0]
	add r0, sp, #0x14
	cmp r1, #0
	beq _020413D4
	mov r2, #4
	bl STD_CopyLString
	b _020413DC
	arm_func_end _ZN17UnkClass_020412A012sub_02041344EtimPKcii
_020413D4:
	ldr r1, _020415B4 ; =DAT_0208dfe4
	bl STD_CopyString
_020413DC:
	ldr r1, _020415B8 ; =s_data_player_s_LZ_bin_0208dfe8
	add r0, sp, #0xd8
	add r2, sp, #0x138
	bl OS_SPrintf
	mov r0, #0x6c
	bl _Znwm
	cmp r0, #0
	beq _02041428
	mov r1, #1
	str r1, [sp]
	mov r3, #0
	str r3, [sp, #4]
	add r1, sl, #0x34
	str r1, [sp, #8]
	ldr r4, _020415BC ; =0x00050800
	add r1, sp, #0x14
	add r2, sp, #0xd8
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
_02041428:
	cmp r0, #0
	addeq sp, sp, #0x198
	str r0, [sl, #8]
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r1, _020415C0 ; =s_s_s_NCLR_0208e000
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x138
	bl OS_SPrintf
	add r0, sp, #0x78
	bl NNS_FndGetArchiveFileByName
	cmp r0, #0
	beq _02041488
	add r1, sp, #0x10
	bl NNS_G2dGetUnpackedPaletteData
	cmp r0, #0
	beq _02041488
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02041484
	ldr r1, [sp, #0x10]
	bl _ZN17UnkClass_02007AA4C1EP17NNSG2dPaletteData
_02041484:
	str r0, [sl, #0xc]
_02041488:
	mov r5, #0
	mov r6, r5
	mov r7, r5
	add r4, sp, #0x18
	mov fp, #1
_0204149C:
	add r0, r6, #1
	tst r8, fp, lsl r0
	beq _020414F8
	ldr r1, _020415C4 ; =s_s_s_02d_0208e00c
	mov r0, r4
	add r2, sp, #0x14
	add r3, sp, #0x138
	str r6, [sp]
	bl OS_SPrintf
	mov r0, #1
	str r0, [sp]
	ldr r1, [sl, #0x10]
	mov r0, sl
	mov r2, r4
	add r1, r1, r7
	mov r3, #0
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
	ldr r0, [sl, #0x10]
	add r1, r6, #1
	add r0, r0, r5, lsl #4
	add r7, r7, #0x10
	strb r1, [r0, #1]
	add r5, r5, #1
_020414F8:
	add r6, r6, #1
	cmp r6, #0x1c
	blt _0204149C
	mov r0, #4
	str r0, [sl, #0x18]
	ldr r0, [sp, #0x1c8]
	strh sb, [sl, #0x1c]
	mov r2, #0
	ldr r1, [sp, #0x1c4]
	strh r2, [sl, #0x1e]
	str r1, [sl, #0x28]
	cmp r0, #0
	beq _0204159C
	cmp r1, #0
	bne _02041568
	mov r0, sl
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	mov r1, r1, lsl #0x10
	str r0, [sl, #0x2c]
	mov r0, sl
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_020141ACEm
	mov r0, sl
	bl _ZN10CActorData12sub_020142B4Ev
_02041568:
	mov r0, sl
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	mov r1, r0
	mov r1, r1, lsl #0x10
	str r0, [sl, #0x30]
	mov r0, sl
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_0201429CEm
	mov r0, sl
	bl _ZN10CActorData12sub_020142F8Ev
_0204159C:
	ldr r0, _020415AC ; =0x00050834
	strh sb, [sl, r0]
	add sp, sp, #0x198
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_020415AC: .word 0x00050834
_020415B0: .word s_player_1d_0208dfd8
_020415B4: .word DAT_0208dfe4
_020415B8: .word s_data_player_s_LZ_bin_0208dfe8
_020415BC: .word 0x00050800
_020415C0: .word s_s_s_NCLR_0208e000
_020415C4: .word s_s_s_02d_0208e00c

	arm_func_start sub_020415C8
sub_020415C8: ; 0x020415C8
	stmdb sp!, {r3, lr}
	ldrb lr, [r0, #0x14]
	mov r3, #0
	cmp lr, #0
	ble _020415FC
	ldr ip, [r0, #0x10]
	arm_func_end sub_020415C8
_020415E0:
	add r0, ip, r3, lsl #4
	ldrb r2, [r0, #1]
	cmp r1, r2
	ldmeqia sp!, {r3, pc}
	add r3, r3, #1
	cmp r3, lr
	blt _020415E0
_020415FC:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_02041604
sub_02041604: ; 0x02041604
	stmdb sp!, {r4, lr}
	ldr r3, [r0]
	mov r4, r0
	ldr r3, [r3, #0x14]
	blx r3
	cmp r0, #0xff
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	ldrb lr, [r4, #0x14]
	mov r3, #0
	cmp lr, #0
	ble _02041658
	ldr ip, [r4, #0x10]
	arm_func_end sub_02041604
_02041638:
	add r2, ip, r3, lsl #4
	ldrb r1, [r2, #1]
	cmp r0, r1
	moveq r0, r2
	ldmeqia sp!, {r4, pc}
	add r3, r3, #1
	cmp r3, lr
	blt _02041638
_02041658:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_02041660
sub_02041660: ; 0x02041660
	mov r0, #0
	mov r3, r0
	arm_func_end sub_02041660
_02041668:
	mov r2, r1, asr r3
	tst r2, #1
	andne r0, r3, #0xff
	bxne lr
	add r3, r3, #1
	cmp r3, #0x1d
	blt _02041668
	bx lr

	arm_func_start sub_02041688
sub_02041688: ; 0x02041688
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02040DB8
	ldr r1, _020416A4 ; =0x0000FFFF
	ldr r0, _020416A8 ; =0x00050834
	strh r1, [r4, r0]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020416A4: .word 0x0000FFFF
_020416A8: .word 0x00050834
	arm_func_end sub_02041688

	arm_func_start _ZN17UnkClass_020416ACC1Ei
_ZN17UnkClass_020416ACC1Ei: ; 0x020416AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r2, #0
	str r2, [r4]
	str r2, [r4, #4]
	str r2, [r4, #8]
	str r2, [r4, #0xc]
	str r2, [r4, #0x10]
	mov r3, r4
	str r1, [r4, #0x910]
	mvn r0, #0
	arm_func_end _ZN17UnkClass_020416ACC1Ei
_020416D8:
	add r2, r2, #1
	str r0, [r3, #0x24]
	cmp r2, #0x73
	add r3, r3, #0x14
	blt _020416D8
	mov r1, #0
	mov r0, r4
	str r1, [r4, #0x914]
	bl sub_02041718
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_020416ACD1Ev
_ZN17UnkClass_020416ACD1Ev: ; 0x02041704
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02041870
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_020416ACD1Ev

	arm_func_start sub_02041718
sub_02041718: ; 0x02041718
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	mov r0, #0x3c
	bl _Znwm
	cmp r0, #0
	beq _02041748
	mov r2, #0
	ldr r1, _02041864 ; =s_data_shadow_NCBR_0208e018
	mov r3, r2
	str r2, [sp]
	bl _ZN17UnkClass_020074D4C1EPKcmmm
	arm_func_end sub_02041718
_02041748:
	str r0, [r4]
	mov r1, #0
	ldr r0, [r0, #0x38]
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	str r0, [r4, #0xc]
	mov r1, r1, lsl #0x10
	ldr r0, [r4]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_020074D412sub_020076E8Em
	ldr r0, [r4]
	bl _ZN17UnkClass_020074D412sub_020076B0Ev
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _0204179C
	mov r2, #0
	ldr r1, _02041868 ; =s_data_shadow_NCLR_0208e02c
	mov r3, r2
	bl _ZN17UnkClass_02007AA4C1EPKcmm
_0204179C:
	str r0, [r4, #4]
	ldr r0, [r0, #4]
	mov r1, #0
	ldr r0, [r0, #8]
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	mov r1, r0
	str r0, [r4, #0x10]
	mov r1, r1, lsl #0x10
	ldr r0, [r4, #4]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007BFCEm
	ldr r0, [r4, #4]
	bl _ZN17UnkClass_02007AA412sub_02007BC4Ev
	mov r0, #0x40
	bl _Znwm
	cmp r0, #0
	beq _020417E8
	bl _ZN14CPrimitiveRECTC1Ev
_020417E8:
	mov r1, #0
	str r0, [r4, #8]
	ldr r0, _0204186C ; =0x000003FF
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r2, r1
	mov r3, r1
	bl _ZN14CPrimitiveRECT12SetRectangleElllll
	ldr r1, [r4, #8]
	mov r0, #0
	str r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	mov r0, #0x40000
	str r0, [r1, #0x30]
	mov r0, #0x20000
	str r0, [r1, #0x34]
	ldr r1, [r4]
	ldr r0, [r4, #8]
	mov r2, #2
	str r1, [r0, #0x38]
	ldr r3, [r4, #4]
	ldr r0, [r4, #8]
	mov r1, #8
	str r3, [r0, #0x3c]
	ldr r0, [r4, #8]
	str r2, [r0, #0x10]
	ldr r0, [r4, #8]
	str r1, [r0, #0x14]
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041864: .word s_data_shadow_NCBR_0208e018
_02041868: .word s_data_shadow_NCLR_0208e02c
_0204186C: .word 0x000003FF

	arm_func_start sub_02041870
sub_02041870: ; 0x02041870
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r5, [r4]
	cmp r5, #0
	beq _020418A0
	beq _02041898
	mov r0, r5
	bl _ZN17UnkClass_020074D4D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end sub_02041870
_02041898:
	mov r0, #0
	str r0, [r4]
_020418A0:
	ldr r5, [r4, #4]
	cmp r5, #0
	beq _020418C8
	beq _020418C0
	mov r0, r5
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r5
	bl _ZdlPv
_020418C0:
	mov r0, #0
	str r0, [r4, #4]
_020418C8:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _020418EC
	beq _020418E4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020418E4:
	mov r0, #0
	str r0, [r4, #8]
_020418EC:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _02041904
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4, #0xc]
_02041904:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #0x10]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02041920
sub_02041920: ; 0x02041920
	bx lr
	arm_func_end sub_02041920

	arm_func_start sub_02041924
sub_02041924: ; 0x02041924
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #8
	mov sl, r0
	ldr r0, [sl, #0x914]
	mov sb, r1
	cmp r0, #0
	mov r8, r2
	mov r7, r3
	mov r4, #0
	addle sp, sp, #8
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	mov r5, sl
	add r6, sl, #0x14
	arm_func_end sub_02041924
_02041958:
	ldr r0, [r5, #0x24]
	cmp r8, r0
	bne _0204198C
	ldr r0, [r6, #0xc]
	stmia sp, {r0, r7}
	ldr r0, [sl, #8]
	ldmia r6, {r1, r2, r3}
	bl _ZN14CPrimitiveRECT12SetRectangleElllll
	ldr r0, [sl, #8]
	mov r1, sb
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
_0204198C:
	ldr r0, [sl, #0x914]
	add r4, r4, #1
	cmp r4, r0
	add r5, r5, #0x14
	add r6, r6, #0x14
	blt _02041958
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start sub_020419AC
sub_020419AC: ; 0x020419AC
	mov r3, r0
	mov r2, #0
	mvn r1, #0
	arm_func_end sub_020419AC
_020419B8:
	add r2, r2, #1
	str r1, [r3, #0x24]
	cmp r2, #0x73
	add r3, r3, #0x14
	blt _020419B8
	mov r1, #0
	str r1, [r0, #0x914]
	bx lr

	arm_func_start sub_020419D8
sub_020419D8: ; 0x020419D8
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, r4, r5, lr}
	ldr r3, [sp, #0x20]
	cmp r1, #0
	ldr ip, [sp, #0x1c]
	ldr r2, [sp, #0x24]
	ldmltia sp!, {r3, r4, r5, lr}
	addlt sp, sp, #0x10
	bxlt lr
	ldr r4, [r0, #0x910]
	cmp r1, r4
	ldrlt r5, [r0, #0x914]
	cmplt r5, #0x73
	ldmgeia sp!, {r3, r4, r5, lr}
	addge sp, sp, #0x10
	bxge lr
	mov lr, #0x14
	mla r4, r5, lr, r0
	str r1, [r4, #0x24]
	ldr r4, [r0, #0x914]
	ldr r1, [sp, #0x18]
	mul lr, r4, lr
	add r4, r0, #0x14
	str r1, [r4, lr]
	add r1, r4, lr
	str ip, [r1, #4]
	str r3, [r1, #8]
	str r2, [r1, #0xc]
	ldr r1, [r0, #0x914]
	add r1, r1, #1
	str r1, [r0, #0x914]
	ldmia sp!, {r3, r4, r5, lr}
	add sp, sp, #0x10
	bx lr
	arm_func_end sub_020419D8

	arm_func_start sub_02041A60
sub_02041A60: ; 0x02041A60
	ldr r0, [r0, #8]
	cmp r0, #0
	strne r1, [r0, #0x14]
	bx lr
	arm_func_end sub_02041A60

	arm_func_start sub_02041A70
sub_02041A70: ; 0x02041A70
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	movs r6, r0
	ldrne r0, _02041C10 ; =MAIN_BSS_0210CA60
	mov r5, r1
	ldrne r7, [r0]
	mov r4, r2
	mov r8, #0
	cmpne r7, #0
	beq _02041C08
	ldr r0, [r6, #0xd0]
	mov r0, r0, lsl #0x10
	movs r8, r0, lsr #0x10
	beq _02041AD8
	mov r0, r7
	mov r1, r8
	bl ov0_02143088
	cmp r0, #0
	beq _02041AD8
	ldr r0, [r0, #0x24]
	cmp r0, #0xd
	cmpne r0, #9
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r0, r7
	mov r1, r8
	bl ov0_021430D8
	arm_func_end sub_02041A70
_02041AD8:
	cmp r5, #0xe
	mvn r2, #0
	mov sb, #0
	addls pc, pc, r5, lsl #2
	b _02041B94
_02041AEC: ; jump table
	b _02041B28 ; case 0
	b _02041B28 ; case 1
	b _02041B28 ; case 2
	b _02041B30 ; case 3
	b _02041B38 ; case 4
	b _02041B44 ; case 5
	b _02041B50 ; case 6
	b _02041B58 ; case 7
	b _02041B60 ; case 8
	b _02041B78 ; case 9
	b _02041B88 ; case 10
	b _02041B90 ; case 11
	b _02041B68 ; case 12
	b _02041B70 ; case 13
	b _02041B80 ; case 14
_02041B28:
	mov r2, #0x24
	b _02041B94
_02041B30:
	mov r2, #0x25
	b _02041B94
_02041B38:
	mov r2, #0x26
	mov sb, #8
	b _02041B94
_02041B44:
	mov r2, #0x27
	mov sb, #8
	b _02041B94
_02041B50:
	mov r2, #0x28
	b _02041B94
_02041B58:
	mov r2, #0x29
	b _02041B94
_02041B60:
	mov r2, #0x2a
	b _02041B94
_02041B68:
	mov r2, #0x65
	b _02041B94
_02041B70:
	mov r2, #0x66
	b _02041B94
_02041B78:
	mov r2, #0x64
	b _02041B94
_02041B80:
	mov r2, #0x67
	b _02041B94
_02041B88:
	mov r2, #0x41
	b _02041B94
_02041B90:
	mov r2, #0x41
_02041B94:
	cmp r2, #0
	blt _02041C08
	mov r0, r7
	mov r1, #1
	bl ov0_02142F6C
	mov r8, r0
	mov r0, r7
	mov r1, r8
	str r8, [r6, #0xd0]
	bl ov0_02143088
	movs r7, r0
	beq _02041C08
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #0x5c]
	blx r2
	mov r0, r7
	str r6, [r7, #0x1c]
	ldr r5, [r0]
	mov r1, sb
	ldr r5, [r5, #0x1c]
	mov r2, r4
	mov r3, #0
	blx r5
	mov r0, r7
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x24]
	blx r2
_02041C08:
	mov r0, r8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02041C10: .word MAIN_BSS_0210CA60

	arm_func_start sub_02041C14
sub_02041C14: ; 0x02041C14
	str r1, [r0, #0x24]
	bx lr
	arm_func_end sub_02041C14

	arm_func_start sub_02041C1C
sub_02041C1C: ; 0x02041C1C
	stmdb sp!, {r4, r5, r6, lr}
	movs r4, r0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r4, #0xd0]
	ldr r1, _02041C7C ; =MAIN_BSS_0210CA60
	mov r0, r0, lsl #0x10
	ldr r6, [r1]
	movs r5, r0, lsr #0x10
	cmpne r6, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	mov r0, r6
	mov r1, r5
	bl ov0_02143088
	cmp r0, #0
	beq _02041C70
	ldr r0, [r0, #0x1c]
	cmp r0, r4
	bne _02041C70
	mov r0, r6
	mov r1, r5
	bl ov0_021430D8
	arm_func_end sub_02041C1C
_02041C70:
	mov r0, #0
	str r0, [r4, #0xd0]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02041C7C: .word MAIN_BSS_0210CA60

	arm_func_start _ZN17UnkClass_02041C80C1EPKci
_ZN17UnkClass_02041C80C1EPKci: ; 0x02041C80
	stmdb sp!, {r4, lr}
	ldr r3, _02041CB0 ; =MAIN_BSS_0210CA6C
	mov r4, r0
	str r4, [r3]
	mov r3, #0
	str r3, [r4]
	str r3, [r4, #4]
	str r3, [r4, #8]
	str r3, [r4, #0xc]
	bl sub_02041CB4
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041CB0: .word MAIN_BSS_0210CA6C
	arm_func_end _ZN17UnkClass_02041C80C1EPKci

	arm_func_start sub_02041CB4
sub_02041CB4: ; 0x02041CB4
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0xc
	mov r4, r0
	mov r0, #0xb8
	mov r6, r1
	mov r5, r2
	bl _Znwm
	cmp r0, #0
	beq _02041CF4
	mov r2, #0
	str r5, [sp]
	str r2, [sp, #4]
	mov r1, r6
	mov r3, r2
	str r2, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	arm_func_end sub_02041CB4
_02041CF4:
	str r0, [r4]
	ldr r1, [r0, #0x4c]
	ldr r0, [r1, #8]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #8]
	ldr r0, [r1, #0xc]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #0xc]
	ldr r0, [r1, #0x10]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #4]
	ldr r0, [r1, #0x14]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #0x10]
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, r5, r6, pc}

	arm_func_start sub_02041D44
sub_02041D44: ; 0x02041D44
	ldr r0, [r0, #4]
	cmp r0, #0
	addne r0, r0, r1, lsl #2
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D44

	arm_func_start sub_02041D58
sub_02041D58: ; 0x02041D58
	ldr r0, [r0, #8]
	cmp r0, #0
	addne r0, r0, r1, lsl #6
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D58

	arm_func_start sub_02041D6C
sub_02041D6C: ; 0x02041D6C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	addne r0, r0, r1, lsl #5
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D6C

	arm_func_start sub_02041D80
sub_02041D80: ; 0x02041D80
	ldr r2, [r0, #0x10]
	cmp r2, #0
	movne r0, #0x54
	mlane r0, r1, r0, r2
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D80

	arm_func_start sub_02041D98
sub_02041D98: ; 0x02041D98
	ldr r3, [r0, #0x1c]
	ldr ip, [r0, #8]
	mov r3, r3, lsl #0x1a
	orr r3, r3, ip, lsr #3
	orr r2, r3, r2, lsl #30
	ldr ip, [r0, #0x20]
	ldr r3, [r0, #0x24]
	orr r2, r2, ip, lsl #20
	orr r3, r2, r3, lsl #23
	ldr r2, _02041DF0 ; =0x040004A8
	orr r1, r3, r1, lsl #29
	str r1, [r2]
	ldr r1, [r0, #0x1c]
	cmp r1, #2
	moveq r2, #1
	movne r2, #0
	ldr r1, [r0, #0xc]
	rsb r0, r2, #4
	mov r1, r1, lsr r0
	ldr r0, _02041DF4 ; =0x040004AC
	str r1, [r0]
	bx lr
	.align 2, 0
_02041DF0: .word 0x040004A8
_02041DF4: .word 0x040004AC
	arm_func_end sub_02041D98

	arm_func_start sub_02041DF8
sub_02041DF8: ; 0x02041DF8
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x24
	mov r7, r0
	ldr r2, [r7, #0x14]
	mov r6, r1
	cmp r2, #0
	addeq sp, sp, #0x24
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, pc}
	ldr r4, [r7, #0x50]
	ldr r3, [r7, #0x4c]
	ldr r2, [r7, #0x40]
	ldr r1, [r7, #0x3c]
	str r1, [r7, #0x1c]
	str r2, [r7, #0x20]
	str r3, [r7, #0x24]
	str r4, [r7, #0x28]
	bl sub_02041F50
	ldr r0, [r7, #0x40]
	ldr r1, [r7, #0x3c]
	mov r2, r0, asr #0xc
	mov r3, r1, asr #0xc
	ldrh r5, [r6, #0x28]
	ldr r0, _02041F3C ; =0x04000450
	mov r1, #0
	str r1, [r0]
	ldrh r0, [r7, #0x54]
	mov r4, r3, lsl r5
	cmp r0, #0
	ldreq r0, [r7, #0x44]
	mov r5, r2, lsl r5
	cmpeq r0, #0x1000
	ldreq r0, [r7, #0x48]
	cmpeq r0, #0x1000
	beq _02041F1C
	ldr r1, _02041F40 ; =0x04000470
	mov r0, #0
	str r4, [r1]
	str r5, [r1]
	str r0, [r1]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	beq _02041ED4
	mov r0, r0, asr #4
	mov r1, r0, lsl #1
	add r0, r1, #1
	ldr r2, _02041F44 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	mov r0, r0, lsl #1
	ldrsh r1, [r2, r1]
	ldrsh r2, [r2, r0]
	add r0, sp, #0
	blx MTX_RotZ33_
	add r0, sp, #0
	bl G3_MultMtx33
	arm_func_end sub_02041DF8
_02041ED4:
	ldr r3, [r7, #0x44]
	cmp r3, #0x1000
	ldreq r0, [r7, #0x48]
	cmpeq r0, #0x1000
	beq _02041F00
	ldr r2, [r7, #0x48]
	ldr r1, _02041F48 ; =0x0400046C
	mov r0, #0x1000
	str r3, [r1]
	str r2, [r1]
	str r0, [r1]
_02041F00:
	ldr r1, _02041F40 ; =0x04000470
	rsb r0, r4, #0
	str r0, [r1]
	rsb r0, r5, #0
	str r0, [r1]
	mov r0, #0
	str r0, [r1]
_02041F1C:
	mov r0, r7
	mov r1, r6
	bl _ZN17CPrimitiveRectNTF6RenderEP8Camera2D
	ldr r1, _02041F4C ; =0x04000448
	mov r2, #0
	str r2, [r1]
	add sp, sp, #0x24
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_02041F3C: .word 0x04000450
_02041F40: .word 0x04000470
_02041F44: .word FX_SinCosTable_
_02041F48: .word 0x0400046C
_02041F4C: .word 0x04000448

	arm_func_start sub_02041F50
sub_02041F50: ; 0x02041F50
	stmdb sp!, {r3, lr}
	mov r1, r0
	ldr r0, [r1, #0x18]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r1, #0x58]
	mov r2, #0
	bl sub_02041D98
	ldmia sp!, {r3, pc}
	arm_func_end sub_02041F50

	arm_func_start sub_02041F74
sub_02041F74: ; 0x02041F74
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4, #0x18]
	mov r5, r1
	cmp r0, #0
	beq _02041F98
	mov r1, #0
	mov r2, r1
	bl sub_02041D98
	arm_func_end sub_02041F74
_02041F98:
	ldr r1, _020420A0 ; =0x04000450
	mov r2, #0
	str r2, [r1]
	ldrh r3, [r5, #0x28]
	ldrh r5, [r4, #8]
	mov r0, #1
	rsb r3, r3, #0xc
	str r5, [r1, #0x30]
	ldr r5, [r4, #0xc]
	ldr r6, [r4, #0x10]
	mov r5, r5, lsl #4
	orr r5, r5, #0xc0
	ldr ip, [r4, #0x14]
	orr r5, r5, r6, lsl #24
	orr r5, r5, ip, lsl #16
	str r5, [r1, #0x54]
	ldr r5, [r4, #0x1c]
	ldr r6, [r4, #0x20]
	mov r5, r5, asr r3
	mov r6, r6, asr r3
	str r5, [r1, #0x20]
	str r6, [r1, #0x20]
	str r2, [r1, #0x20]
	str r0, [r1, #0xb0]
_02041FF8:
	add r0, r4, r2, lsl #3
	ldr r5, [r0, #0x48]
	ldr r6, [r0, #0x44]
	mov ip, r5, lsl #8
	mov r5, ip, asr #0x10
	mov ip, r6, lsl #8
	mov lr, r5, lsl #0x10
	mov r6, ip, asr #0x10
	mov r5, lr, lsr #0x10
	mov ip, r6, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r5, r5, ip, lsr #16
	str r5, [r1, #0x38]
	ldr ip, [r0, #0x28]
	ldr r5, [r0, #0x24]
	mov r0, ip, asr r3
	mov r5, r5, asr r3
	mov r0, r0, lsl #0x10
	mov r0, r0, asr #0x10
	ldr r6, [r4, #4]
	mov ip, r5, lsl #0x10
	mov lr, r0, lsl #0x10
	mov r0, r6, lsl #0x10
	mov r5, ip, asr #0x10
	mov lr, lr, lsr #0x10
	mov r0, r0, asr #0x10
	mov ip, r0, lsl #0x10
	add r2, r2, #1
	mov r0, r5, lsl #0x10
	mov lr, lr, lsl #0x10
	orr r0, lr, r0, lsr #16
	str r0, [r1, #0x3c]
	mov r0, ip, lsr #0x10
	str r0, [r1, #0x3c]
	cmp r2, #4
	blt _02041FF8
	ldr r0, _020420A4 ; =0x04000504
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #-0xbc]
	mov r0, #1
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_020420A0: .word 0x04000450
_020420A4: .word 0x04000504

	arm_func_start sub_020420A8
sub_020420A8: ; 0x020420A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420A8

	arm_func_start sub_020420BC
sub_020420BC: ; 0x020420BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420BC

	arm_func_start sub_020420D8
sub_020420D8: ; 0x020420D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420D8

	arm_func_start sub_020420EC
sub_020420EC: ; 0x020420EC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420EC

	arm_func_start sub_02042108
sub_02042108: ; 0x02042108
	stmdb sp!, {r4, lr}
	mov r4, r0
	strb r1, [r4]
	bl sub_02042134
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02042108

	arm_func_start sub_02042120
sub_02042120: ; 0x02042120
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02042318
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02042120

	arm_func_start sub_02042134
sub_02042134: ; 0x02042134
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x70
	mov r5, r0
	bl sub_02042318
	ldrb r2, [r5]
	ldr r1, _02042300 ; =s_data_battle_bg_capbg_03d_LZ_bin_0208e0b0
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x6c
	bl _Znwm
	movs r4, r0
	beq _0204218C
	mov r3, #1
	str r3, [sp]
	mov r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	ldr r1, _02042304 ; =DAT_0208e0d0
	add r2, sp, #0x10
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r4, r0
	arm_func_end sub_02042134
_0204218C:
	ldrb r2, [r5]
	ldr r1, _02042308 ; =s_BBG_capbg_03d_NCBR_0208e0d4
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x3c
	bl _Znwm
	cmp r0, #0
	beq _020421C0
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	str r2, [sp]
	bl _ZN17UnkClass_020074D4C1EPKcmmm
_020421C0:
	str r0, [r5, #8]
	mov r1, #0
	ldr r0, [r0, #0x38]
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	str r0, [r5, #0x14]
	mov r1, r1, lsl #0x10
	ldr r0, [r5, #8]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_020074D412sub_020076E8Em
	ldr r0, [r5, #8]
	bl _ZN17UnkClass_020074D412sub_020076B0Ev
	ldrb r2, [r5]
	ldr r1, _0204230C ; =s_BBG_capbg_03d_NCLR_0208e0e8
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02042224
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	bl _ZN17UnkClass_02007AA4C1EPKcmm
_02042224:
	str r0, [r5, #0xc]
	ldr r0, [r0, #4]
	mov r1, #0
	ldr r0, [r0, #8]
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	mov r1, r0
	str r0, [r5, #0x18]
	mov r1, r1, lsl #0x10
	ldr r0, [r5, #0xc]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007BFCEm
	ldr r0, [r5, #0xc]
	bl _ZN17UnkClass_02007AA412sub_02007BC4Ev
	ldrb r2, [r5]
	ldr r1, _02042310 ; =s_BBG_capbg_03d_NCER_0208e0fc
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02042290
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNCERFileC1EPKcmmm
_02042290:
	str r0, [r5, #0x10]
	mov r0, #0x4c
	bl _Znwm
	cmp r0, #0
	beq _020422A8
	bl _ZN15CSoftwareSpriteC1Ev
_020422A8:
	str r0, [r5, #4]
	ldr r3, [r5, #0x10]
	ldr r2, [r5, #0xc]
	ldr r1, [r5, #8]
	cmp r4, #0
	str r1, [r0, #0x2c]
	mov r1, #0
	str r1, [r0, #0x30]
	str r2, [r0, #0x34]
	str r3, [r0, #0x38]
	cmpne r4, #0
	ldr r0, [r5, #4]
	ldr r1, _02042314 ; =0xFFFFFC01
	addeq sp, sp, #0x70
	str r1, [r0, #4]
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r4
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r4
	bl _ZdlPv
	add sp, sp, #0x70
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02042300: .word s_data_battle_bg_capbg_03d_LZ_bin_0208e0b0
_02042304: .word DAT_0208e0d0
_02042308: .word s_BBG_capbg_03d_NCBR_0208e0d4
_0204230C: .word s_BBG_capbg_03d_NCLR_0208e0e8
_02042310: .word s_BBG_capbg_03d_NCER_0208e0fc
_02042314: .word 0xFFFFFC01

	arm_func_start sub_02042318
sub_02042318: ; 0x02042318
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _02042344
	beq _0204233C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02042318
_0204233C:
	mov r0, #0
	str r0, [r4, #4]
_02042344:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _02042360
	ldr r0, [r4, #0x14]
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4, #0x14]
_02042360:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0204237C
	ldr r0, [r4, #0x18]
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #0x18]
_0204237C:
	ldr r5, [r4, #8]
	cmp r5, #0
	beq _020423A4
	beq _0204239C
	mov r0, r5
	bl _ZN17UnkClass_020074D4D1Ev
	mov r0, r5
	bl _ZdlPv
_0204239C:
	mov r0, #0
	str r0, [r4, #8]
_020423A4:
	ldr r5, [r4, #0xc]
	cmp r5, #0
	beq _020423CC
	beq _020423C4
	mov r0, r5
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r5
	bl _ZdlPv
_020423C4:
	mov r0, #0
	str r0, [r4, #0xc]
_020423CC:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _020423E8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020423E8:
	mov r0, #0
	str r0, [r4, #0x10]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_020423F4
sub_020423F4: ; 0x020423F4
	stmdb sp!, {r3, lr}
	ldr r0, [r0, #4]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, pc}
	arm_func_end sub_020423F4

	arm_func_start sub_0204240C
sub_0204240C: ; 0x0204240C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r1
	ldrh r1, [r0, #0x2a]
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	ldr r1, [r5, #4]
	add r0, r4, r0
	str r0, [r1, #4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_0204240C

	arm_func_start sub_02042434
sub_02042434: ; 0x02042434
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x18
	ldr r1, _020424F0 ; =MAIN_BSS_020B26A0+32768
	mov r4, r0
	ldr r1, [r1, #0x1ac]
	mov r0, #0x74
	str r1, [r4, #0x10]
	bl _Znwm
	cmp r0, #0
	beq _02042464
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
	arm_func_end sub_02042434
_02042464:
	str r0, [r4, #0xc]
	mov lr, #0
	str lr, [r4, #8]
	ldr ip, [r4, #4]
	mov r2, #0x10
	add r0, ip, #0x1000
	ldr r3, [r0, #0x4b0]
	add r1, ip, #0x24
	str r3, [sp]
	str r1, [sp, #4]
	ldr r3, [r0, #0x48c]
	mov r1, #0x4000
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp, #0x10]
	str lr, [sp, #0x14]
	ldr r3, [r0, #0x4ac]
	ldr r0, [r0, #0x490]
	ldr r1, [ip, #0x14]
	ldr r2, [ip, #0x18]
	add r3, r3, #0xc
	bl _ZN17UnkClass_020091E812sub_02009328EP17UnkClass_02001C04P11CTouchPanelP10NNSG2dFontPvP10CGame_0024S6_mmm
	bl _Z12sub_02007D68v
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	ldr r0, [r4, #4]
	mov r1, #0x3c
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	add sp, sp, #0x18
	ldmia sp!, {r4, pc}
	.align 2, 0
_020424F0: .word MAIN_BSS_020B26A0+32768

	arm_func_start sub_020424F4
sub_020424F4: ; 0x020424F4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02042524
	beq _0204251C
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_020424F4
_0204251C:
	mov r0, #0
	str r0, [r5, #0xc]
_02042524:
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AC90Ev
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02042548
sub_02042548: ; 0x02042548
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x430
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0x13
	addls pc, pc, r0, lsl #2
	b _02042F54
_02042564: ; jump table
	b _020425B4 ; case 0
	b _020425D8 ; case 1
	b _02042660 ; case 2
	b _02042748 ; case 3
	b _02042760 ; case 4
	b _02042810 ; case 5
	b _02042B34 ; case 6
	b _02042BA4 ; case 7
	b _02042BE0 ; case 8
	b _02042C50 ; case 9
	b _02042C8C ; case 10
	b _02042CB0 ; case 11
	b _02042D30 ; case 12
	b _02042D88 ; case 13
	b _02042DC4 ; case 14
	b _02042E34 ; case 15
	b _02042E70 ; case 16
	b _02042F54 ; case 17
	b _02042EE0 ; case 18
	b _02042F1C ; case 19
	arm_func_end sub_02042548
_020425B4:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl _ZN17UnkClass_02027FE84LoadEt
	mov r0, #1
	str r0, [r4, #8]
	b _02042F54
_020425D8:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02042F54
	tst r0, #0x80
	beq _02042654
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02042F54
_02042600: ; jump table
	b _02042630 ; case 0
	b _02042630 ; case 1
	b _02042630 ; case 2
	b _02042648 ; case 3
	b _02042F54 ; case 4
	b _02042F54 ; case 5
	b _02042F54 ; case 6
	b _02042F54 ; case 7
	b _02042630 ; case 8
	b _02042648 ; case 9
	b _0204263C ; case 10
	b _02042648 ; case 11
_02042630:
	mov r0, #0x10
	str r0, [r4, #8]
	b _02042F54
_0204263C:
	mov r0, #0xa
	str r0, [r4, #8]
	b _02042F54
_02042648:
	mov r0, #0xa
	str r0, [r4, #8]
	b _02042F54
_02042654:
	mov r0, #2
	str r0, [r4, #8]
	b _02042F54
_02042660:
	ldr r1, [r4, #4]
	ldr r6, _02042F60 ; =MAIN_BSS_020AF624
	add r3, r1, #0x1000
	ldr r1, _02042F64 ; =DAT_0208e11c
	add r0, sp, #0x28
	mov r2, #0x10
	ldr r5, [r3, #0x49c]
	bl CRYPTO_RC4FastInit
	add r0, sp, #0x28
	mov r1, r6
	mov r3, r6
	mov r2, #0x3000
	bl CRYPTO_RC4FastEncrypt
	ldr r0, [r6]
	and r0, r0, #0xf0
	cmp r0, #0x20
	bgt _020426B4
	bge _020426E0
	cmp r0, #0x10
	beq _020426D0
	b _0204270C
_020426B4:
	cmp r0, #0x30
	bgt _020426C4
	beq _020426F0
	b _0204270C
_020426C4:
	cmp r0, #0x80
	beq _02042700
	b _0204270C
_020426D0:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UncompressLZ8
	b _0204270C
_020426E0:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UncompressHuffman
	b _0204270C
_020426F0:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UncompressRL8
	b _0204270C
_02042700:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UnfilterDiff8
_0204270C:
	add r0, r5, #0x1c
	bl sub_02044AC8
	mov r0, #5
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldr r2, _02042F6C ; =MAIN_BSS_0210CA6C
	ldrh r1, [r0, #0x1a]
	ldr r0, [r2]
	bl sub_02041D80
	ldrb r1, [r0, #4]
	ldr r0, _02042F70 ; =MAIN_BSS_020B26A0+32768
	strb r1, [r0, #0xb64]
	b _02042F54
_02042748:
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl _ZN17UnkClass_02027FE84LoadEt
	mov r0, #4
	str r0, [r4, #8]
	b _02042F54
_02042760:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02042F54
	tst r0, #0x80
	beq _020427DC
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02042F54
_02042788: ; jump table
	b _020427B8 ; case 0
	b _020427B8 ; case 1
	b _020427B8 ; case 2
	b _020427D0 ; case 3
	b _02042F54 ; case 4
	b _02042F54 ; case 5
	b _02042F54 ; case 6
	b _02042F54 ; case 7
	b _020427B8 ; case 8
	b _020427D0 ; case 9
	b _020427C4 ; case 10
	b _020427D0 ; case 11
_020427B8:
	mov r0, #0x10
	str r0, [r4, #8]
	b _02042F54
_020427C4:
	mov r0, #8
	str r0, [r4, #8]
	b _02042F54
_020427D0:
	mov r0, #6
	str r0, [r4, #8]
	b _02042F54
_020427DC:
	mov r0, #5
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldr r2, _02042F6C ; =MAIN_BSS_0210CA6C
	ldrh r1, [r0, #0x1a]
	ldr r0, [r2]
	bl sub_02041D80
	ldrb r1, [r0, #4]
	ldr r0, _02042F70 ; =MAIN_BSS_020B26A0+32768
	strb r1, [r0, #0xb64]
	b _02042F54
_02042810:
	ldr r2, [r4, #0x10]
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	add r2, r2, #0x45
	mov r1, #0
	str r2, [sp, #8]
	bl sub_020162BC
	ldr r1, _02042F70 ; =MAIN_BSS_020B26A0+32768
	mov r3, #0
	strb r3, [r1, #0x802]
	ldr r2, [r4, #0x10]
	mov r0, #1
	str r2, [r1, #0x1ac]
	str r0, [r1, #0xb68]
	ldr r0, [sp, #8]
	ldr r2, _02042F68 ; =MAIN_BSS_020B26A0
	str r0, [r1, #0xb6c]
	mov r4, r3
_02042854:
	add r0, r2, #0x8000
	add r3, r3, #1
	str r4, [r0, #0xad4]
	cmp r3, #2
	add r2, r2, #0x38
	blt _02042854
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldr fp, _02042F68 ; =MAIN_BSS_020B26A0
	add r0, r0, #4
	mov r5, r4
	mov r6, r4
	add r8, r0, #0x8800
_02042884:
	mov r7, #0
	mov sb, fp
	mov sl, r8
_02042890:
	cmp r6, #0
	bne _020428B0
	add r0, sb, #0x8000
	ldr r0, [r0, #0x80c]
	tst r0, #2
	movne r4, sl
	movne r5, r7
	bne _020428B8
_020428B0:
	mov r0, sl
	bl sub_020150B8
_020428B8:
	add r7, r7, #1
	cmp r7, #0xa
	add sb, sb, #0x18
	add sl, sl, #0x18
	blt _02042890
	add r6, r6, #1
	cmp r6, #3
	add fp, fp, #0xf0
	add r8, r8, #0xf0
	blt _02042884
	cmp r4, #0
	cmpne r5, #0
	beq _02042954
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldrh r3, [r4]
	add r1, r0, #0x8800
	add r2, r0, #0x8000
	strh r3, [r1, #4]
	ldrh r5, [r4, #2]
	mov r3, #0
	mov r0, r4
	strh r5, [r1, #6]
	ldrh r5, [r4, #4]
	strh r5, [r1, #8]
	ldr r5, [r4, #8]
	str r5, [r2, #0x80c]
	ldr r6, [r4, #0xc]
	ldr r5, [r4, #0x10]
	str r6, [r2, #0x810]
	str r5, [r2, #0x814]
	ldrh r5, [r4, #0x14]
	strh r5, [r1, #0x18]
	ldrh r5, [r4, #0x16]
	str r3, [r2, #0x80c]
	strh r5, [r1, #0x1a]
	ldr r1, [r4, #8]
	orr r1, r1, #0
	str r1, [r2, #0x80c]
	bl sub_020150B8
_02042954:
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	bl sub_02016024
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	mov r2, #0x140
	add r0, r0, #0x1b4
	add r1, r0, #0x8000
	mov r0, #0
	bl MIi_CpuClearFast
	ldr r1, _02042F68 ; =MAIN_BSS_020B26A0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	add r2, r1, #0x8000
	mov r3, #0
	mov r1, #1
	strb r3, [r2, #0x434]
	str r3, [r2, #0xad4]
	str r3, [r2, #0xb0c]
	bl sub_02019278
	mov sl, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #2
	bl sub_02019278
	mov sb, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1b
	bl sub_02019278
	mov r8, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1c
	bl sub_02019278
	mov r7, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1d
	bl sub_02019278
	mov r6, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1e
	bl sub_02019278
	mov r5, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #4
	bl sub_02019278
	mov r4, r0
	ldr r0, _02042F78 ; =MAIN_BSS_020B2638
	bl sub_0201135C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	bl sub_02018E1C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	bl sub_02018E30
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0
	bl sub_02018E94
	ldr r1, [sp, #8]
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	bl sub_02018E94
	ldr r0, _02042F78 ; =MAIN_BSS_020B2638
	mov r1, #0
	bl sub_020116C0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, sl
	mov r1, #1
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, sb
	mov r1, #2
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r8
	mov r1, #0x1b
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r7
	mov r1, #0x1c
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r6
	mov r1, #0x1d
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r5
	mov r1, #0x1e
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r4
	mov r1, #4
	bl sub_0201926C
	ldr r0, _02042F7C ; =MAIN_BSS_0210C1C0
	mov r1, #0
	mov r2, #0x60
	bl MI_CpuFill8
	ldr r0, _02042F80 ; =MAIN_BSS_0210C228
	mov r1, #0
	mov r2, #0x800
	bl MI_CpuFill8
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	mov r1, #0
	ldrb r2, [r0, #2]
	str r1, [r0, #4]
	strb r2, [r0, #1]
	add r0, sp, #0x1c
	bl RTC_GetTime
	add r0, sp, #0xc
	bl RTC_GetDate
	ldr r2, [sp, #0x1c]
	ldr r1, _02042F70 ; =MAIN_BSS_020B26A0+32768
	ldr r0, [sp, #0x20]
	str r2, [r1, #0xb94]
	str r0, [r1, #0xb98]
	ldr r2, [sp, #0x24]
	ldr r0, [sp, #0xc]
	str r2, [r1, #0xb9c]
	str r0, [r1, #0xb84]
	ldr r2, [sp, #0x10]
	ldr r0, [sp, #0x14]
	str r2, [r1, #0xb88]
	ldr r2, [sp, #0x18]
	str r0, [r1, #0xb8c]
	str r2, [r1, #0xb90]
	add sp, sp, #0x430
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02042B34:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x48
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #7
	str r0, [r4, #8]
	b _02042F54
_02042BA4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042BE0:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #9
	str r0, [r4, #8]
	b _02042F54
_02042C50:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042C8C:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl _ZN17UnkClass_02027FE85ClearEt
	mov r0, #0xb
	str r0, [r4, #8]
	b _02042F54
_02042CB0:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02042F54
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x73
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0xc
	str r0, [r4, #8]
	b _02042F54
_02042D30:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x74
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0xd
	str r0, [r4, #8]
	b _02042F54
_02042D88:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042DC4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xf
	str r0, [r4, #8]
	b _02042F54
_02042E34:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042E70:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0x11
	str r0, [r4, #8]
	b _02042F54
_02042EE0:
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0x13
	str r0, [r4, #8]
	b _02042F54
_02042F1C:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #0x430
	moveq r0, #0x11
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02042F54:
	mvn r0, #0
	add sp, sp, #0x430
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02042F60: .word MAIN_BSS_020AF624
_02042F64: .word DAT_0208e11c
_02042F68: .word MAIN_BSS_020B26A0
_02042F6C: .word MAIN_BSS_0210CA6C
_02042F70: .word MAIN_BSS_020B26A0+32768
_02042F74: .word MAIN_BSS_0210C0B0
_02042F78: .word MAIN_BSS_020B2638
_02042F7C: .word MAIN_BSS_0210C1C0
_02042F80: .word MAIN_BSS_0210C228

	arm_func_start sub_02042F84
sub_02042F84: ; 0x02042F84
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
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #0x100
	bl GX_SetBankForSubOBJ
	mov r1, #0
	str r1, [sp]
	ldr r0, _020430C0 ; =0x04000050
	mov r2, r1
	mov r3, r1
	bl G2x_SetBlendAlpha_
	ldr lr, _020430C4 ; =0x04000060
	ldr r0, _020430C8 ; =0xFFFFFDF1
	ldrh r1, [lr]
	add ip, lr, #0x2a4
	mov r2, #0x4000000
	bic r1, r1, #0x3000
	orr r1, r1, #8
	strh r1, [lr]
	ldrh r3, [lr]
	mov r1, #0
	bic r3, r3, #0x3000
	orr r3, r3, #0x10
	strh r3, [lr]
	ldrh r3, [ip]
	and r0, r3, r0
	orr r0, r0, #0xe
	orr r0, r0, #0x200
	strh r0, [ip]
	ldrh r0, [ip]
	bic r0, r0, #0x8000
	strh r0, [ip]
	ldr r0, [r2]
	bic r0, r0, #0x38000000
	str r0, [r2]
	ldr r0, [r2]
	bic r0, r0, #0x7000000
	str r0, [r2]
	str r1, [r2, #0x10]
	str r1, [r2, #0x14]
	str r1, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldr r0, [r2]
	add r1, r2, #0x1000
	bic r0, r0, #0x1f00
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	str r0, [r1]
	bl GX_DispOn
	ldr r1, _020430CC ; =0x04001000
	ldr r0, [r1]
	orr r0, r0, #0x10000
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020430C0: .word 0x04000050
_020430C4: .word 0x04000060
_020430C8: .word 0xFFFFFDF1
_020430CC: .word 0x04001000
	arm_func_end sub_02042F84

	arm_func_start sub_020430D0
sub_020430D0: ; 0x020430D0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02043120 ; =ptr_FUN_02043134_0208e154
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02043108
	beq _02043100
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_020430D0
_02043100:
	mov r0, #0
	str r0, [r5, #0xc]
_02043108:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	bl _ZdlPv
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02043120: .word ptr_FUN_02043134_0208e154

	arm_func_start sub_02043124
sub_02043124: ; 0x02043124
	bx lr
	arm_func_end sub_02043124

	arm_func_start sub_02043128
sub_02043128: ; 0x02043128
	bx lr
	arm_func_end sub_02043128

	arm_func_start sub_0204312C
sub_0204312C: ; 0x0204312C
	mov r0, #0x1c
	bx lr
	arm_func_end sub_0204312C

	arm_func_start sub_02043134
sub_02043134: ; 0x02043134
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0204317C ; =ptr_FUN_02043134_0208e154
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _0204316C
	beq _02043164
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02043134
_02043164:
	mov r0, #0
	str r0, [r5, #0xc]
_0204316C:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0204317C: .word ptr_FUN_02043134_0208e154

	arm_func_start sub_02043180
sub_02043180: ; 0x02043180
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x18
	ldr r3, _0204331C ; =MAIN_BSS_020B26A0
	mov r4, r0
	ldrb r2, [r3, #2]
	ldr r1, _02043320 ; =MAIN_BSS_020B26A0+32768
	ldr r0, _02043324 ; =MAIN_BSS_020B26A0+31804
	strb r2, [r4, #0x10]
	ldrb r5, [r1, #0x7db]
	add r1, r4, #0x1c
	mov r2, #0x80
	strb r5, [r4, #0x11]
	ldr r5, [r3, #0x28]
	str r5, [r4, #0x14]
	ldr r3, [r3, #0x2c]
	str r3, [r4, #0x18]
	bl MIi_CpuCopyFast
	ldr r0, _02043328 ; =MAIN_BSS_020B26A0+32432
	add r1, r4, #0x9c
	mov r2, #0x80
	bl MIi_CpuCopyFast
	ldr r0, _0204332C ; =MAIN_BSS_020B26A0+31932
	add r1, r4, #0x11c
	mov r2, #0x1f4
	bl MI_CpuCopy8
	ldr r3, _02043320 ; =MAIN_BSS_020B26A0+32768
	ldr r0, _02043330 ; =MAIN_BSS_020B26A0+34668
	ldr r2, [r3, #0x758]
	add r1, r4, #0x328
	str r2, [r4, #0x314]
	ldr r5, [r3, #0x75c]
	mov r2, #0x44
	str r5, [r4, #0x318]
	ldr r5, [r3, #0x760]
	str r5, [r4, #0x31c]
	ldr r5, [r3, #0x764]
	str r5, [r4, #0x320]
	ldr r3, [r3, #0x768]
	str r3, [r4, #0x324]
	bl MIi_CpuCopyFast
	ldr r2, _02043320 ; =MAIN_BSS_020B26A0+32768
	ldr r1, _02043334 ; =MAIN_BSS_020B26A0+34560
	ldr r3, [r2, #0x7b0]
	add r0, r4, #0x300
	str r3, [r4, #0x36c]
	ldr r3, [r2, #0x7b4]
	mov lr, #0x10
	str r3, [r4, #0x370]
	ldrh r5, [r1, #0xb8]
	mov ip, #0x4000
	mov r3, #0
	strh r5, [r0, #0x74]
	ldrh r5, [r1, #0xba]
	strh r5, [r0, #0x76]
	ldrh r1, [r1, #0xbc]
	strh r1, [r0, #0x78]
	ldr r0, [r2, #0x7cc]
	str r0, [r4, #0x37c]
	ldrb r0, [r2, #0x7d0]
	strb r0, [r4, #0x380]
	ldr r0, [r2, #0x7d4]
	str r0, [r4, #0x384]
	ldrb r0, [r2, #0x7d8]
	strb r0, [r4, #0x388]
	ldrb r0, [r2, #0x7d9]
	strb r0, [r4, #0x389]
	ldrb r0, [r2, #0x7da]
	strb r0, [r4, #0x38a]
	ldrb r0, [r2, #0x803]
	strb r0, [r4, #0x310]
	ldr r0, [r2, #0x1ac]
	str r0, [r4, #0x38c]
	ldr r5, [r4, #4]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4b0]
	add r0, r5, #0x24
	str r2, [sp]
	str r0, [sp, #4]
	ldr r0, [r1, #0x48c]
	str r0, [sp, #8]
	str lr, [sp, #0xc]
	str ip, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r0, [r1, #0x490]
	ldr r3, [r1, #0x4ac]
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	add r3, r3, #0xc
	bl _ZN17UnkClass_020091E812sub_02009328EP17UnkClass_02001C04P11CTouchPanelP10NNSG2dFontPvP10CGame_0024S6_mmm
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	mov r0, #0
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	mov r1, #0x3c
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0204331C: .word MAIN_BSS_020B26A0
_02043320: .word MAIN_BSS_020B26A0+32768
_02043324: .word MAIN_BSS_020B26A0+31804
_02043328: .word MAIN_BSS_020B26A0+32432
_0204332C: .word MAIN_BSS_020B26A0+31932
_02043330: .word MAIN_BSS_020B26A0+34668
_02043334: .word MAIN_BSS_020B26A0+34560
	arm_func_end sub_02043180

	arm_func_start sub_02043338
sub_02043338: ; 0x02043338
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02043368
	beq _02043360
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02043338
_02043360:
	mov r0, #0
	str r0, [r5, #0xc]
_02043368:
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AC90Ev
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0204338C
sub_0204338C: ; 0x0204338C
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02043854
_020433A8: ; jump table
	b _020433D8 ; case 0
	b _02043408 ; case 1
	b _02043498 ; case 2
	b _0204360C ; case 3
	b _02043618 ; case 4
	b _02043688 ; case 5
	b _020436C4 ; case 6
	b _02043854 ; case 7
	b _02043734 ; case 8
	b _020437A4 ; case 9
	b _020437E0 ; case 10
	b _0204381C ; case 11
	arm_func_end sub_0204338C
_020433D8:
	mov r0, #0x74
	bl _Znwm
	cmp r0, #0
	beq _020433F0
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
_020433F0:
	mov r1, #0
	str r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE84LoadEt
	mov r0, #1
	str r0, [r4, #8]
	b _02043854
_02043408:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02043854
	tst r0, #0x80
	beq _02043484
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02043854
_02043430: ; jump table
	b _02043460 ; case 0
	b _02043460 ; case 1
	b _02043460 ; case 2
	b _02043478 ; case 3
	b _02043854 ; case 4
	b _02043854 ; case 5
	b _02043854 ; case 6
	b _02043854 ; case 7
	b _02043460 ; case 8
	b _02043478 ; case 9
	b _0204346C ; case 10
	b _02043478 ; case 11
_02043460:
	mov r0, #6
	str r0, [r4, #8]
	b _02043854
_0204346C:
	mov r0, #8
	str r0, [r4, #8]
	b _02043854
_02043478:
	mov r0, #4
	str r0, [r4, #8]
	b _02043854
_02043484:
	mov r0, #2
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	b _02043854
_02043498:
	ldrb r1, [r4, #0x10]
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	strb r1, [r0, #2]
	ldrb r1, [r4, #0x11]
	bl sub_020160B8
	ldr r1, [r4, #0x14]
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	str r1, [r0, #0x28]
	ldr r1, [r4, #0x18]
	bl sub_02016D4C
	ldr r1, _02043864 ; =MAIN_BSS_020B26A0+31804
	add r0, r4, #0x1c
	mov r2, #0x80
	bl MIi_CpuCopyFast
	ldr r1, _02043868 ; =MAIN_BSS_020B26A0+32432
	add r0, r4, #0x9c
	mov r2, #0x80
	bl MIi_CpuCopyFast
	ldr r1, _0204386C ; =MAIN_BSS_020B26A0+31932
	add r0, r4, #0x11c
	mov r2, #0x1f4
	bl MI_CpuCopy8
	ldrb r2, [r4, #0x310]
	ldr r1, _02043870 ; =MAIN_BSS_020B26A0+32768
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	strb r2, [r1, #0x803]
	ldr r1, [r4, #0x314]
	bl sub_02016D88
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x318]
	bl sub_02016DD0
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x31c]
	bl sub_02016E18
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x320]
	bl sub_02016E60
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x324]
	bl sub_02016EA8
	add r0, r4, #0x328
	ldr r1, _02043874 ; =MAIN_BSS_020B26A0+34668
	mov r2, #0x44
	bl MIi_CpuCopyFast
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x36c]
	bl sub_02017020
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x370]
	bl sub_02017068
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	add r1, r4, #0x300
	ldrh r1, [r1, #0x74]
	bl sub_020170B0
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	add r1, r4, #0x300
	ldrh r1, [r1, #0x76]
	bl sub_02017100
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	add r1, r4, #0x300
	ldrh r1, [r1, #0x78]
	bl sub_02017150
	ldr r1, [r4, #0x37c]
	ldr r0, _02043870 ; =MAIN_BSS_020B26A0+32768
	str r1, [r0, #0x7cc]
	ldrb r1, [r4, #0x380]
	strb r1, [r0, #0x7d0]
	ldr r1, [r4, #0x384]
	str r1, [r0, #0x7d4]
	ldrb r1, [r4, #0x388]
	strb r1, [r0, #0x7d8]
	ldrb r1, [r4, #0x389]
	strb r1, [r0, #0x7d9]
	ldrb r1, [r4, #0x38a]
	strb r1, [r0, #0x7da]
	ldr r0, [r4, #0x38c]
	subs r5, r0, #1
	bmi _02043600
	cmp r5, #6
	bge _02043600
	ldr r0, _02043878 ; =MAIN_BSS_020AF598
	mov r1, r5
	bl sub_020112DC
	cmp r5, #3
	bge _02043600
	ldr r1, _0204387C ; =MAIN_BSS_020AF5E4
	mov r0, #0x14
	mla r0, r5, r0, r1
	mov r1, r5
	bl sub_02010F5C
_02043600:
	mov r0, #3
	str r0, [r4, #8]
	b _02043854
_0204360C:
	add sp, sp, #8
	mov r0, #0x15
	ldmia sp!, {r3, r4, r5, pc}
_02043618:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x48
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #5
	str r0, [r4, #8]
	b _02043854
_02043688:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043854
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xa
	str r0, [r4, #8]
	b _02043854
_020436C4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #7
	str r0, [r4, #8]
	b _02043854
_02043734:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #9
	str r0, [r4, #8]
	b _02043854
_020437A4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043854
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xa
	str r0, [r4, #8]
	b _02043854
_020437E0:
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xb
	str r0, [r4, #8]
	b _02043854
_0204381C:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02043854
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #8
	moveq r0, #0x11
	ldmeqia sp!, {r3, r4, r5, pc}
_02043854:
	mvn r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02043860: .word MAIN_BSS_020B26A0
_02043864: .word MAIN_BSS_020B26A0+31804
_02043868: .word MAIN_BSS_020B26A0+32432
_0204386C: .word MAIN_BSS_020B26A0+31932
_02043870: .word MAIN_BSS_020B26A0+32768
_02043874: .word MAIN_BSS_020B26A0+34668
_02043878: .word MAIN_BSS_020AF598
_0204387C: .word MAIN_BSS_020AF5E4

	arm_func_start sub_02043880
sub_02043880: ; 0x02043880
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
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #0x100
	bl GX_SetBankForSubOBJ
	mov r1, #0
	str r1, [sp]
	ldr r0, _02043998 ; =0x04000050
	mov r2, r1
	mov r3, r1
	bl G2x_SetBlendAlpha_
	ldr lr, _0204399C ; =0x04000060
	ldr r0, _020439A0 ; =0xFFFFFDF1
	ldrh r1, [lr]
	add ip, lr, #0x2a4
	mov r2, #0x4000000
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
	bic r0, r0, #0x8000
	strh r0, [ip]
	ldr r0, [r2]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r1]
	bl GX_DispOn
	ldr r1, _020439A4 ; =0x04001000
	ldr r0, [r1]
	orr r0, r0, #0x10000
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02043998: .word 0x04000050
_0204399C: .word 0x04000060
_020439A0: .word 0xFFFFFDF1
_020439A4: .word 0x04001000
	arm_func_end sub_02043880

	arm_func_start sub_020439A8
sub_020439A8: ; 0x020439A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN6CSceneD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020439A8

	arm_func_start sub_020439C4
sub_020439C4: ; 0x020439C4
	bx lr
	arm_func_end sub_020439C4

	arm_func_start sub_020439C8
sub_020439C8: ; 0x020439C8
	bx lr
	arm_func_end sub_020439C8

	arm_func_start sub_020439CC
sub_020439CC: ; 0x020439CC
	mov r0, #0x1d
	bx lr
	arm_func_end sub_020439CC

	arm_func_start sub_020439D4
sub_020439D4: ; 0x020439D4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN6CSceneD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020439D4

	arm_func_start sub_020439E8
sub_020439E8: ; 0x020439E8
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x18
	ldr r1, _02043AA4 ; =MAIN_BSS_020B26A0+32768
	mov r4, r0
	ldr r1, [r1, #0x1ac]
	mov r0, #0x74
	str r1, [r4, #0x10]
	bl _Znwm
	cmp r0, #0
	beq _02043A18
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
	arm_func_end sub_020439E8
_02043A18:
	str r0, [r4, #0xc]
	mov lr, #0
	str lr, [r4, #8]
	ldr ip, [r4, #4]
	mov r2, #0x10
	add r0, ip, #0x1000
	ldr r3, [r0, #0x4b0]
	add r1, ip, #0x24
	str r3, [sp]
	str r1, [sp, #4]
	ldr r3, [r0, #0x48c]
	mov r1, #0x4000
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp, #0x10]
	str lr, [sp, #0x14]
	ldr r3, [r0, #0x4ac]
	ldr r0, [r0, #0x490]
	ldr r1, [ip, #0x14]
	ldr r2, [ip, #0x18]
	add r3, r3, #0xc
	bl _ZN17UnkClass_020091E812sub_02009328EP17UnkClass_02001C04P11CTouchPanelP10NNSG2dFontPvP10CGame_0024S6_mmm
	bl _Z12sub_02007D68v
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	ldr r0, [r4, #4]
	mov r1, #0x3c
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	add sp, sp, #0x18
	ldmia sp!, {r4, pc}
	.align 2, 0
_02043AA4: .word MAIN_BSS_020B26A0+32768

	arm_func_start sub_02043AA8
sub_02043AA8: ; 0x02043AA8
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02043AD8
	beq _02043AD0
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02043AA8
_02043AD0:
	mov r0, #0
	str r0, [r5, #0xc]
_02043AD8:
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AC90Ev
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02043AFC
sub_02043AFC: ; 0x02043AFC
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x410
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0xc
	addls pc, pc, r0, lsl #2
	b _02043FA8
_02043B18: ; jump table
	b _02043B4C ; case 0
	b _02043B70 ; case 1
	b _02043C20 ; case 2
	b _02043CE0 ; case 3
	b _02043D04 ; case 4
	b _02043D84 ; case 5
	b _02043DDC ; case 6
	b _02043EC4 ; case 7
	b _02043FA8 ; case 8
	b _02043E18 ; case 9
	b _02043E88 ; case 10
	b _02043F34 ; case 11
	b _02043F70 ; case 12
	arm_func_end sub_02043AFC
_02043B4C:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl _ZN17UnkClass_02027FE84LoadEt
	mov r0, #1
	str r0, [r4, #8]
	b _02043FA8
_02043B70:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02043FA8
	tst r0, #0x80
	beq _02043BEC
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02043FA8
_02043B98: ; jump table
	b _02043BC8 ; case 0
	b _02043BC8 ; case 1
	b _02043BC8 ; case 2
	b _02043BE0 ; case 3
	b _02043FA8 ; case 4
	b _02043FA8 ; case 5
	b _02043FA8 ; case 6
	b _02043FA8 ; case 7
	b _02043BC8 ; case 8
	b _02043BE0 ; case 9
	b _02043BD4 ; case 10
	b _02043BE0 ; case 11
_02043BC8:
	mov r0, #7
	str r0, [r4, #8]
	b _02043FA8
_02043BD4:
	mov r0, #3
	str r0, [r4, #8]
	b _02043FA8
_02043BE0:
	mov r0, #3
	str r0, [r4, #8]
	b _02043FA8
_02043BEC:
	mov r0, #2
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	ldr r0, _02043FB4 ; =MAIN_BSS_020B26A0
	ldr r2, _02043FB8 ; =MAIN_BSS_0210CA6C
	ldrh r1, [r0, #0x1a]
	ldr r0, [r2]
	bl sub_02041D80
	ldrb r1, [r0, #4]
	ldr r0, _02043FBC ; =MAIN_BSS_020B26A0+32768
	strb r1, [r0, #0xb64]
	b _02043FA8
_02043C20:
	ldr r1, [r4, #4]
	ldr r5, _02043FC0 ; =MAIN_BSS_020AF624
	add r3, r1, #0x1000
	ldr r1, _02043FC4 ; =DAT_0208e11c
	add r0, sp, #8
	mov r2, #0x10
	ldr r4, [r3, #0x49c]
	bl CRYPTO_RC4FastInit
	add r0, sp, #8
	mov r1, r5
	mov r3, r5
	mov r2, #0x3000
	bl CRYPTO_RC4FastEncrypt
	ldr r0, [r5]
	and r0, r0, #0xf0
	cmp r0, #0x20
	bgt _02043C74
	bge _02043CA0
	cmp r0, #0x10
	beq _02043C90
	b _02043CCC
_02043C74:
	cmp r0, #0x30
	bgt _02043C84
	beq _02043CB0
	b _02043CCC
_02043C84:
	cmp r0, #0x80
	beq _02043CC0
	b _02043CCC
_02043C90:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UncompressLZ8
	b _02043CCC
_02043CA0:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UncompressHuffman
	b _02043CCC
_02043CB0:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UncompressRL8
	b _02043CCC
_02043CC0:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UnfilterDiff8
_02043CCC:
	add r0, r4, #0x1c
	bl sub_02044AC8
	add sp, sp, #0x410
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_02043CE0:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl _ZN17UnkClass_02027FE85ClearEt
	mov r0, #4
	str r0, [r4, #8]
	b _02043FA8
_02043D04:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02043FA8
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x73
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #5
	str r0, [r4, #8]
	b _02043FA8
_02043D84:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x74
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #6
	str r0, [r4, #8]
	b _02043FA8
_02043DDC:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xb
	str r0, [r4, #8]
	b _02043FA8
_02043E18:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xa
	str r0, [r4, #8]
	b _02043FA8
_02043E88:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xb
	str r0, [r4, #8]
	b _02043FA8
_02043EC4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #8
	str r0, [r4, #8]
	b _02043FA8
_02043F34:
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xc
	str r0, [r4, #8]
	b _02043FA8
_02043F70:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #0x410
	moveq r0, #0x11
	ldmeqia sp!, {r3, r4, r5, pc}
_02043FA8:
	mvn r0, #0
	add sp, sp, #0x410
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02043FB4: .word MAIN_BSS_020B26A0
_02043FB8: .word MAIN_BSS_0210CA6C
_02043FBC: .word MAIN_BSS_020B26A0+32768
_02043FC0: .word MAIN_BSS_020AF624
_02043FC4: .word DAT_0208e11c

	arm_func_start sub_02043FC8
sub_02043FC8: ; 0x02043FC8
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
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #0x100
	bl GX_SetBankForSubOBJ
	mov r1, #0
	str r1, [sp]
	ldr r0, _020440E0 ; =0x04000050
	mov r2, r1
	mov r3, r1
	bl G2x_SetBlendAlpha_
	ldr lr, _020440E4 ; =0x04000060
	ldr r0, _020440E8 ; =0xFFFFFDF1
	ldrh r1, [lr]
	add ip, lr, #0x2a4
	mov r2, #0x4000000
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
	bic r0, r0, #0x8000
	strh r0, [ip]
	ldr r0, [r2]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r1]
	bl GX_DispOn
	ldr r1, _020440EC ; =0x04001000
	ldr r0, [r1]
	orr r0, r0, #0x10000
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020440E0: .word 0x04000050
_020440E4: .word 0x04000060
_020440E8: .word 0xFFFFFDF1
_020440EC: .word 0x04001000
	arm_func_end sub_02043FC8

	arm_func_start sub_020440F0
sub_020440F0: ; 0x020440F0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02044140 ; =ptr_FUN_02044154_0208e210
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02044128
	beq _02044120
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_020440F0
_02044120:
	mov r0, #0
	str r0, [r5, #0xc]
_02044128:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	bl _ZdlPv
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02044140: .word ptr_FUN_02044154_0208e210

	arm_func_start sub_02044144
sub_02044144: ; 0x02044144
	bx lr
	arm_func_end sub_02044144

	arm_func_start sub_02044148
sub_02044148: ; 0x02044148
	bx lr
	arm_func_end sub_02044148

	arm_func_start sub_0204414C
sub_0204414C: ; 0x0204414C
	mov r0, #0x1e
	bx lr
	arm_func_end sub_0204414C

	arm_func_start sub_02044154
sub_02044154: ; 0x02044154
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0204419C ; =ptr_FUN_02044154_0208e210
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _0204418C
	beq _02044184
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02044154
_02044184:
	mov r0, #0
	str r0, [r5, #0xc]
_0204418C:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0204419C: .word ptr_FUN_02044154_0208e210

	arm_func_start thunk_FUN_02064f9c
thunk_FUN_02064f9c: ; 0x020441A0
	ldr ip, _020441A8 ; =OS_Printf
	bx ip
	.align 2, 0
_020441A8: .word OS_Printf
	arm_func_end thunk_FUN_02064f9c

	arm_func_start sub_020441AC
sub_020441AC: ; 0x020441AC
	bx lr
	arm_func_end sub_020441AC

	arm_func_start sub_020441B0
sub_020441B0: ; 0x020441B0
	stmdb sp!, {r3, lr}
	ldr r0, _020441F8 ; =MAIN_BSS_0210CAB4
	ldr r3, [r0, #4]
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r0]
	ldr r0, _020441FC ; =MAIN_BSS_0210CAC8
	subs r1, r1, r0
	beq _020441E8
	mov r2, #1
	bl fwrite
	ldr r0, _020441F8 ; =MAIN_BSS_0210CAB4
	ldr r0, [r0, #4]
	bl fflush
	arm_func_end sub_020441B0
_020441E8:
	ldr r1, _020441FC ; =MAIN_BSS_0210CAC8
	ldr r0, _020441F8 ; =MAIN_BSS_0210CAB4
	str r1, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020441F8: .word MAIN_BSS_0210CAB4
_020441FC: .word MAIN_BSS_0210CAC8

	arm_func_start sub_02044200
sub_02044200: ; 0x02044200
	stmdb sp!, {r4, r5, r6, lr}
	ldr r5, _02044258 ; =MAIN_BSS_0210CAB4
	mov r4, r0
	ldr r0, [r5, #4]
	cmp r0, #0
	ldrnesb r0, [r4]
	cmpne r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r6, _0204425C ; =MAIN_BSS_0210CEC8
	arm_func_end sub_02044200
_02044224:
	ldr r1, [r5]
	add r0, r1, #1
	str r0, [r5]
	ldrsb r0, [r4], #1
	strb r0, [r1]
	ldr r0, [r5]
	cmp r0, r6
	blo _02044248
	bl sub_020441B0
_02044248:
	ldrsb r0, [r4]
	cmp r0, #0
	bne _02044224
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02044258: .word MAIN_BSS_0210CAB4
_0204425C: .word MAIN_BSS_0210CEC8

	arm_func_start sub_02044260
sub_02044260: ; 0x02044260
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _020442C4 ; =DAT_0208e23c
	mov r5, r0
	ldr r4, [r1, #4]
	tst r4, #4
	beq _0204427C
	bl sub_02044200
	arm_func_end sub_02044260
_0204427C:
	tst r4, #2
	beq _0204428C
	mov r0, r5
	bl thunk_FUN_02064f9c
_0204428C:
	tst r4, #8
	beq _0204429C
	mov r0, r5
	bl sub_020441AC
_0204429C:
	tst r4, #0x10
	ldrne r0, _020442C8 ; =MAIN_BSS_0210CAB4
	ldrne r3, [r0, #0x10]
	cmpne r3, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r1, [r0, #0xc]
	ldr r2, [r0, #8]
	mov r0, r5
	blx r3
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020442C4: .word DAT_0208e23c
_020442C8: .word MAIN_BSS_0210CAB4

	arm_func_start sub_020442CC
sub_020442CC: ; 0x020442CC
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x200
	mov r3, r0
	mov r2, r1
	add r0, sp, #0
	mov r1, r3
	bl vsprintf
	ldr r1, _02044304 ; =DAT_0208e244
	add r0, sp, #0
	bl strcat
	add r0, sp, #0
	bl sub_02044260
	add sp, sp, #0x200
	ldmia sp!, {r3, pc}
	.align 2, 0
_02044304: .word DAT_0208e244
	arm_func_end sub_020442CC

	arm_func_start sub_02044308
sub_02044308: ; 0x02044308
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x200
	mov r3, r0
	mov r2, r1
	add r0, sp, #0
	mov r1, r3
	bl vsprintf
	add r0, sp, #0
	bl sub_02044260
	add sp, sp, #0x200
	ldmia sp!, {r3, pc}
	arm_func_end sub_02044308

	arm_func_start thunk_FUN_020442cc
thunk_FUN_020442cc: ; 0x02044334
	ldr ip, _0204433C ; =sub_020442CC
	bx ip
	.align 2, 0
_0204433C: .word sub_020442CC
	arm_func_end thunk_FUN_020442cc

	arm_func_start sub_02044340
sub_02044340: ; 0x02044340
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, lr}
	ldr r0, [sp, #8]
	add r1, sp, #0xc
	bl sub_020442CC
	ldmia sp!, {r3, lr}
	add sp, sp, #0x10
	bx lr
	arm_func_end sub_02044340

	arm_func_start thunk_FUN_02044308
thunk_FUN_02044308: ; 0x02044360
	ldr ip, _02044368 ; =sub_02044308
	bx ip
	.align 2, 0
_02044368: .word sub_02044308
	arm_func_end thunk_FUN_02044308
