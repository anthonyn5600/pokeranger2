    .include "macros.inc"
    .include "include/overlay_00_02152A14.inc"

    .text

	arm_func_start _ZN14CFieldPokeMoveC1Ev
_ZN14CFieldPokeMoveC1Ev: ; 0x02152A14
	sub sp, sp, #8
	ldr r1, _02152AAC ; =ptr_FUN_overlay_0_02152ab8_overlay_0_021780dc
	mov r3, #0
	str r1, [r0]
	str r3, [r0, #0x48]
	strh r3, [r0, #0x4c]
	mov r1, #0xa000
	str r1, [r0, #0x64]
	str r3, [r0, #0x68]
	strh r3, [r0, #0x4e]
	str r3, [r0, #0xac]
	str r3, [r0, #0xb0]
	mov r2, #0x24
	ldr r1, _02152AB0 ; =0x00000FFF
	str r2, [r0, #0xb4]
	strh r1, [r0, #0x4c]
	strh r3, [r0, #0xb8]
	mov r1, #1
	str r1, [r0, #0xbc]
	str r3, [r0, #0x5c]
	str r3, [r0, #0xcc]
	str r3, [r0, #0xc0]
	str r3, [r0, #0xd0]
	str r3, [r0, #0x24]
	str r3, [r0, #0x28]
	str r3, [r0, #0x2c]
	str r1, [r0, #0x44]
	strb r3, [r0, #0xd4]
	ldr r1, _02152AB4 ; =DAT_overlay_0_02172ee0
	strh r3, [r0, #0xd6]
	ldr r2, [r1]
	ldr r1, [r1, #4]
	str r2, [sp]
	str r2, [r0, #0x30]
	str r1, [sp, #4]
	str r1, [r0, #0x34]
	add sp, sp, #8
	bx lr
	.align 2, 0
_02152AAC: .word ptr_FUN_overlay_0_02152ab8_overlay_0_021780dc
_02152AB0: .word 0x00000FFF
_02152AB4: .word DAT_overlay_0_02172ee0
	arm_func_end _ZN14CFieldPokeMoveC1Ev

	arm_func_start _ZN14CFieldPokeMoveD1Ev
_ZN14CFieldPokeMoveD1Ev: ; 0x02152AB8
	bx lr
	arm_func_end _ZN14CFieldPokeMoveD1Ev

	arm_func_start _ZN14CFieldPokeMoveD0Ev
_ZN14CFieldPokeMoveD0Ev: ; 0x02152ABC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN14CFieldPokeMoveD0Ev

	arm_func_start _ZN14CFieldPokeMove12ov0_02152AD0EP11CFieldActor7Point2Di
_ZN14CFieldPokeMove12ov0_02152AD0EP11CFieldActor7Point2Di: ; 0x02152AD0
	stmdb sp!, {r0, r1, r2, r3}
	ldr r2, [sp, #8]
	str r1, [r0, #0x48]
	ldr r1, [sp, #0xc]
	str r2, [r0, #4]
	str r1, [r0, #8]
	ldr r1, [r0, #0x44]
	cmp r1, #0xf
	cmpne r1, #0xe
	movne r1, #1
	strne r1, [r0, #0x44]
	add sp, sp, #0x10
	bx lr
	arm_func_end _ZN14CFieldPokeMove12ov0_02152AD0EP11CFieldActor7Point2Di

	arm_func_start _ZN14CFieldPokeMove12ov0_02152B04Ev
_ZN14CFieldPokeMove12ov0_02152B04Ev: ; 0x02152B04
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x74
	mov r4, r0
	ldr r0, [r4, #0xac]
	cmp r0, #0
	ldreq r0, _0215303C ; =MAIN_BSS_0210CA48
	ldreq r0, [r0]
	streq r0, [r4, #0xac]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _02152E8C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02152B54
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x20]
	moveq r0, #0
	b _02152B58
	arm_func_end _ZN14CFieldPokeMove12ov0_02152B04Ev
_02152B54:
	mov r0, #0
_02152B58:
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02152B80
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	b _02152B84
_02152B80:
	mov r0, #0
_02152B84:
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02152BAC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x8c]
	moveq r0, #0
	b _02152BB0
_02152BAC:
	mov r0, #0
_02152BB0:
	str r0, [r4, #0x14]
	ldr r0, [r4, #0xac]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02152C04
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02152BE4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x64]
	str r0, [sp, #0x68]
	b _02152BFC
_02152BE4:
	mov r0, #0
	add r1, sp, #0x4c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
_02152BFC:
	add r3, sp, #0x64
	b _02152C20
_02152C04:
	mov r0, #0
	add r1, sp, #0x44
	add r3, sp, #0x64
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x64]
	str r0, [sp, #0x68]
_02152C20:
	ldr r2, [r3, #4]
	ldr r0, [r4, #0x10]
	ldr lr, [r3]
	sub ip, r2, r0
	mov r2, ip, asr #0xc
	mul r0, r2, r2
	ldr r3, [r4, #0xc]
	ldr r1, [r4, #0x14]
	sub lr, lr, r3
	mov r3, lr, asr #0xc
	mov r2, r1, asr #0xc
	mla r1, r3, r3, r0
	mla r0, r2, r2, r1
	str r1, [r4, #0xc8]
	str r0, [r4, #0xc4]
	ldr r0, [r4, #0xcc]
	ldr r2, [r4, #0xc]
	ldr r1, [r4, #0x10]
	str r2, [sp, #0x6c]
	str r1, [sp, #0x70]
	cmp r0, #0
	bne _02152E40
	ldr r2, [r4, #0xac]
	ldr r0, [r2, #0x10c]
	tst r0, #1
	bne _02152E40
	ldr r0, [r4, #0x68]
	cmp r0, #5
	beq _02152CA8
	ldr r0, [r4, #0x48]
	ldr r1, [r2, #0x14]
	ldr r0, [r0, #0x14]
	cmp r1, r0
	bne _02152E34
_02152CA8:
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _02152CF4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02152CD4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x5c]
	str r0, [sp, #0x60]
	b _02152CEC
_02152CD4:
	mov r0, #0
	add r1, sp, #0x3c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
_02152CEC:
	add r3, sp, #0x5c
	b _02152D10
_02152CF4:
	mov r0, #0
	add r1, sp, #0x34
	add r3, sp, #0x5c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x5c]
	str r0, [sp, #0x60]
_02152D10:
	ldrh r0, [r4, #0x6e]
	sub lr, sp, #4
	add r1, sp, #0x6c
	str r0, [sp, #4]
	ldr ip, [r4, #0x30]
	ldr r2, [r4, #0x34]
	mov r0, r4
	str ip, [sp, #8]
	str r2, [sp, #0xc]
	ldrh ip, [r4, #0x72]
	ldmia r1, {r1, r2}
	str ip, [sp, #0x10]
	ldr ip, [r3]
	ldr r3, [r3, #4]
	str ip, [lr]
	str r3, [lr, #4]
	ldr r3, [lr]
	bl ov0_021582C4
	cmp r0, #0
	movne r0, #1
	strne r0, [r4, #0xc0]
	bne _02152E48
	ldr r0, [r4, #0xac]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02152DB8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02152D98
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x54]
	str r0, [sp, #0x58]
	b _02152DB0
_02152D98:
	mov r0, #0
	add r1, sp, #0x2c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x54]
	str r0, [sp, #0x58]
_02152DB0:
	add r3, sp, #0x54
	b _02152DD4
_02152DB8:
	mov r0, #0
	add r1, sp, #0x24
	add r3, sp, #0x54
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x54]
	str r0, [sp, #0x58]
_02152DD4:
	ldrh r0, [r4, #0x70]
	sub lr, sp, #4
	add r1, sp, #0x6c
	str r0, [sp, #4]
	ldr ip, [r4, #0x30]
	ldr r2, [r4, #0x34]
	mov r0, r4
	str ip, [sp, #8]
	str r2, [sp, #0xc]
	ldrh ip, [r4, #0x74]
	ldmia r1, {r1, r2}
	str ip, [sp, #0x10]
	ldr ip, [r3]
	ldr r3, [r3, #4]
	str ip, [lr]
	str r3, [lr, #4]
	ldr r3, [lr]
	bl ov0_021582C4
	cmp r0, #0
	movne r0, #2
	strne r0, [r4, #0xc0]
	moveq r0, #0
	streq r0, [r4, #0xc0]
	b _02152E48
_02152E34:
	mov r0, #0
	str r0, [r4, #0xc0]
	b _02152E48
_02152E40:
	mov r0, #0
	str r0, [r4, #0xc0]
_02152E48:
	ldr r3, [r4, #0x48]
	cmp r3, #0
	beq _02152E8C
	ldr r0, [r4, #0xcc]
	cmp r0, #0
	bne _02152E8C
	ldr r1, [r4, #0x34]
	ldr r2, [r4, #0x30]
	str r1, [sp, #0x20]
	str r2, [r3, #0x158]
	str r1, [r3, #0x15c]
	ldr r0, [r3, #0x158]
	str r2, [sp, #0x1c]
	str r0, [r3, #0x198]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [r3, #0x19c]
_02152E8C:
	ldr r0, [r4, #0x44]
	cmp r0, #0x18
	addls pc, pc, r0, lsl #2
	b _0215301C
_02152E9C: ; jump table
	b _0215301C ; case 0
	b _02152F00 ; case 1
	b _02152F0C ; case 2
	b _02152F18 ; case 3
	b _02152F24 ; case 4
	b _02152F3C ; case 5
	b _02152F30 ; case 6
	b _02152F48 ; case 7
	b _02152F54 ; case 8
	b _02152F60 ; case 9
	b _02152F6C ; case 10
	b _02152F78 ; case 11
	b _02152F84 ; case 12
	b _02152F90 ; case 13
	b _02152F9C ; case 14
	b _02152FA8 ; case 15
	b _02152FB4 ; case 16
	b _02152FC0 ; case 17
	b _02152FCC ; case 18
	b _02152FD8 ; case 19
	b _02152FE4 ; case 20
	b _02152FF0 ; case 21
	b _02152FFC ; case 22
	b _02153008 ; case 23
	b _02153014 ; case 24
_02152F00:
	mov r0, r4
	bl ov0_0215675C
	b _0215301C
_02152F0C:
	mov r0, r4
	bl ov0_02156898
	b _0215301C
_02152F18:
	mov r0, r4
	bl ov0_02153040
	b _0215301C
_02152F24:
	mov r0, r4
	bl ov0_02153538
	b _0215301C
_02152F30:
	mov r0, r4
	bl ov0_02153D78
	b _0215301C
_02152F3C:
	mov r0, r4
	bl ov0_02154210
	b _0215301C
_02152F48:
	mov r0, r4
	bl ov0_021545EC
	b _0215301C
_02152F54:
	mov r0, r4
	bl ov0_02154810
	b _0215301C
_02152F60:
	mov r0, r4
	bl ov0_0215900C
	b _0215301C
_02152F6C:
	mov r0, r4
	bl ov0_02154C30
	b _0215301C
_02152F78:
	mov r0, r4
	bl ov0_02154C58
	b _0215301C
_02152F84:
	mov r0, r4
	bl ov0_02155558
	b _0215301C
_02152F90:
	mov r0, r4
	bl ov0_02155580
	b _0215301C
_02152F9C:
	mov r0, r4
	bl ov0_02155588
	b _0215301C
_02152FA8:
	mov r0, r4
	bl ov0_021558F4
	b _0215301C
_02152FB4:
	mov r0, r4
	bl ov0_021559F0
	b _0215301C
_02152FC0:
	mov r0, r4
	bl ov0_021559F8
	b _0215301C
_02152FCC:
	mov r0, r4
	bl ov0_02155A90
	b _0215301C
_02152FD8:
	mov r0, r4
	bl ov0_02155B88
	b _0215301C
_02152FE4:
	mov r0, r4
	bl ov0_02155C20
	b _0215301C
_02152FF0:
	mov r0, r4
	bl ov0_02155D38
	b _0215301C
_02152FFC:
	mov r0, r4
	bl ov0_02155EA0
	b _0215301C
_02153008:
	mov r0, r4
	bl ov0_02156194
	b _0215301C
_02153014:
	mov r0, r4
	bl ov0_02156290
_0215301C:
	mov r0, r4
	bl ov0_02154A84
	ldr r1, [r4, #0x50]
	mov r0, #0
	sub r1, r1, #1
	str r1, [r4, #0x50]
	add sp, sp, #0x74
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0215303C: .word MAIN_BSS_0210CA48

	arm_func_start ov0_02153040
ov0_02153040: ; 0x02153040
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x90
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0xf
	addls pc, pc, r1, lsl #2
	b _02153528
_0215305C: ; jump table
	b _0215309C ; case 0
	b _0215334C ; case 1
	b _021533B8 ; case 2
	b _02153528 ; case 3
	b _02153528 ; case 4
	b _02153528 ; case 5
	b _02153528 ; case 6
	b _02153528 ; case 7
	b _02153528 ; case 8
	b _02153528 ; case 9
	b _021534A4 ; case 10
	b _021534F0 ; case 11
	b _021534FC ; case 12
	b _02153508 ; case 13
	b _02153514 ; case 14
	b _02153520 ; case 15
	arm_func_end ov0_02153040
_0215309C:
	bl ov0_02156A8C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021530C4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _021530C8
_021530C4:
	mov r0, #0
_021530C8:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _02153534 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02153108
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _0215310C
_02153108:
	mov r0, #0
_0215310C:
	mov r1, r0, asr #4
	ldr r0, _02153534 ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x34]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _02153194
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02153174
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02153158
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x80]
	str r0, [sp, #0x84]
	b _0215318C
_02153158:
	mov r0, #0
	add r1, sp, #0x48
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x80]
	str r0, [sp, #0x84]
	b _0215318C
_02153174:
	mov r0, #0
	add r1, sp, #0x50
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x80]
	str r0, [sp, #0x84]
_0215318C:
	add r5, sp, #0x80
	b _021531B0
_02153194:
	mov r0, #0
	add r1, sp, #0x40
	add r5, sp, #0x80
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x80]
	str r0, [sp, #0x84]
_021531B0:
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r5]
	ldr r0, [r5, #4]
	sub r1, r1, r3
	sub r6, r0, r2
	str r1, [r4, #0x38]
	str r6, [r4, #0x3c]
	ldr r0, [r4, #0x38]
	str r3, [sp, #0x78]
	smull r5, lr, r0, r0
	smull ip, r0, r6, r6
	mov r5, r5, lsr #0xc
	mov ip, ip, lsr #0xc
	orr r5, r5, lr, lsl #20
	orr ip, ip, r0, lsl #20
	add r0, r5, ip
	str r2, [sp, #0x7c]
	str r3, [sp, #0x60]
	str r2, [sp, #0x64]
	str r1, [sp, #0x58]
	str r6, [sp, #0x5c]
	str r1, [sp, #0x88]
	str r6, [sp, #0x8c]
	bl FX_InvSqrt
	ldr r1, [r4, #0x38]
	smull r3, r2, r1, r0
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	smull r2, r0, r1, r0
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r4, #0x3c]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _021532B0
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02153290
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02153274
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x70]
	str r0, [sp, #0x74]
	b _021532A8
_02153274:
	mov r0, #0
	add r1, sp, #0x28
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x70]
	str r0, [sp, #0x74]
	b _021532A8
_02153290:
	mov r0, #0
	add r1, sp, #0x30
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x70]
	str r0, [sp, #0x74]
_021532A8:
	add r2, sp, #0x70
	b _021532CC
_021532B0:
	mov r0, #0
	add r1, sp, #0x20
	add r2, sp, #0x70
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x70]
	str r0, [sp, #0x74]
_021532CC:
	ldmia r2, {r3, ip}
	stmib r4, {r3, ip}
	ldrh r2, [r4, #0x80]
	str r3, [sp, #0x38]
	mov r0, r4
	strh r2, [r4, #0x4c]
	add r1, r4, #0x38
	ldr r3, [r4, #0x7c]
	str ip, [sp, #0x3c]
	ldmia r1, {r1, r2}
	bl ov0_02158894
	cmp r0, #0
	mov r0, r4
	beq _02153310
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02153528
_02153310:
	mov r1, #4
	mov r2, #0x1e
	bl ov0_021582B4
	ldr r0, [r4, #0x68]
	cmp r0, #5
	beq _02153330
	mov r0, r4
	bl ov0_0215826C
_02153330:
	ldr r0, [r4, #0x68]
	cmp r0, #9
	moveq r0, #0xa
	streqh r0, [r4, #0x4e]
	movne r0, #1
	strneh r0, [r4, #0x4e]
	b _02153528
_0215334C:
	ldrb r1, [r4, #0xa8]
	cmp r1, #0
	bne _02153378
	ldrh r3, [r4, #0x4c]
	add r1, r4, #0x30
	add r2, r4, #0x38
	bl ov0_02157F0C
	cmp r0, #0
	movne r0, #2
	strneh r0, [r4, #0x4e]
	b _02153380
_02153378:
	mov r0, #2
	strh r0, [r4, #0x4e]
_02153380:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021533AC
	bl _ZN6CActor12sub_020128ECEt
_021533AC:
	ldrh r0, [r4, #0x86]
	str r0, [r4, #0x50]
	b _02153528
_021533B8:
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _0215342C
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0215340C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021533F0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x68]
	str r0, [sp, #0x6c]
	b _02153424
_021533F0:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x68]
	str r0, [sp, #0x6c]
	b _02153424
_0215340C:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x68]
	str r0, [sp, #0x6c]
_02153424:
	add r2, sp, #0x68
	b _02153448
_0215342C:
	mov r0, #0
	add r1, sp, #0
	add r2, sp, #0x68
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x68]
	str r0, [sp, #0x6c]
_02153448:
	ldr lr, [r2]
	ldr ip, [r2, #4]
	mov r0, r4
	str lr, [r4, #4]
	str ip, [r4, #8]
	ldr r2, [r4, #0x7c]
	add r1, r4, #0x24
	mvn r3, #0
	str lr, [sp, #0x18]
	str ip, [sp, #0x1c]
	bl ov0_02156B30
	movs r1, r0
	beq _02153488
	mov r0, r4
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02153528
_02153488:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bgt _02153528
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02153528
_021534A4:
	ldrh r3, [r4, #0x4c]
	add r1, r4, #0x30
	add r2, r4, #0x38
	bl ov0_02157F0C
	cmp r0, #0
	movne r0, #0xb
	strneh r0, [r4, #0x4e]
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02153528
	bl _ZN6CActor12sub_020128ECEt
	b _02153528
_021534F0:
	mov r0, #0xc
	strh r0, [r4, #0x4e]
	b _02153528
_021534FC:
	mov r0, #0xd
	strh r0, [r4, #0x4e]
	b _02153528
_02153508:
	mov r0, #0xe
	strh r0, [r4, #0x4e]
	b _02153528
_02153514:
	mov r0, #0xf
	strh r0, [r4, #0x4e]
	b _02153528
_02153520:
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_02153528:
	mov r0, #0
	add sp, sp, #0x90
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02153534: .word FX_SinCosTable_

	arm_func_start ov0_02153538
ov0_02153538: ; 0x02153538
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x74
	mov r6, r0
	ldrh r1, [r6, #0x4e]
	cmp r1, #0xa
	bgt _0215357C
	bge _021538B8
	cmp r1, #2
	bgt _02153B48
	cmp r1, #0
	blt _02153B48
	beq _02153588
	cmp r1, #1
	beq _0215382C
	cmp r1, #2
	beq _02153890
	b _02153B48
	arm_func_end ov0_02153538
_0215357C:
	cmp r1, #0xb
	beq _021538B8
	b _02153B48
_02153588:
	bl ov0_02156A8C
	ldr r0, [r6, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021535B0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _021535B4
_021535B0:
	mov r0, #0
_021535B4:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _02153B54 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r6, #0x30]
	ldr r0, [r6, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021535F4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _021535F8
_021535F4:
	mov r0, #0
_021535F8:
	mov r1, r0, asr #4
	ldr r0, _02153B54 ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	str r0, [r6, #0x34]
	ldr r0, [r6, #0xac]
	cmp r0, #0
	beq _02153680
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02153660
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02153644
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x4c]
	str r0, [sp, #0x50]
	b _02153678
_02153644:
	mov r0, #0
	add r1, sp, #0x2c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
	b _02153678
_02153660:
	mov r0, #0
	add r1, sp, #0x34
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
_02153678:
	add r3, sp, #0x4c
	b _0215369C
_02153680:
	mov r0, #0
	add r1, sp, #0x24
	add r3, sp, #0x4c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x4c]
	str r0, [sp, #0x50]
_0215369C:
	ldr r2, [r3]
	ldr r0, [r6, #0xc]
	ldr r1, [r3, #4]
	sub r7, r0, r2
	ldr r0, [r6, #0x10]
	str r2, [sp, #0x44]
	sub r5, r0, r1
	str r7, [r6, #0x38]
	str r5, [r6, #0x3c]
	ldr r0, [r6, #0x38]
	str r1, [sp, #0x48]
	smull r4, r3, r0, r0
	smull r2, r0, r5, r5
	mov r4, r4, lsr #0xc
	mov r2, r2, lsr #0xc
	orr r4, r4, r3, lsl #20
	orr r2, r2, r0, lsl #20
	add r0, r4, r2
	str r7, [sp, #0x3c]
	str r5, [sp, #0x40]
	str r7, [sp, #0x54]
	str r5, [sp, #0x58]
	bl FX_InvSqrt
	ldr r2, [r6, #0x38]
	mov r1, #7
	smull r4, r3, r2, r0
	mov r2, r4, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r6, #0x38]
	ldr r3, [r6, #0x3c]
	mov r2, #0x1e
	smull r4, r0, r3, r0
	mov r3, r4, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r6, #0x3c]
	ldrh r0, [r6, #0x86]
	ldr r4, [r6, #0x7c]
	ldr r3, [r6, #0x38]
	mov r0, r0, lsl #0xc
	smull r5, r0, r4, r0
	mov r4, r5, lsr #0xc
	orr r4, r4, r0, lsl #20
	smull r7, r5, r3, r4
	ldr r0, [r6, #0x3c]
	mov r7, r7, lsr #0xc
	smull r4, r3, r0, r4
	mov r0, r4, lsr #0xc
	orr r0, r0, r3, lsl #20
	ldr r3, [r6, #0x10]
	ldr r4, [r6, #0xc]
	add r0, r3, r0
	orr r7, r7, r5, lsl #20
	add r4, r4, r7
	str r4, [r6, #4]
	str r0, [r6, #8]
	ldrh r3, [r6, #0x80]
	str r0, [sp, #0x70]
	str r0, [sp, #0x20]
	mov r0, r6
	strh r3, [r6, #0x4c]
	str r4, [sp, #0x6c]
	str r4, [sp, #0x1c]
	bl ov0_021582B4
	ldr r0, [r6, #0x68]
	cmp r0, #5
	beq _0215380C
	ldr r3, [r6, #0x7c]
	add r1, r6, #0x38
	mov r0, r6
	ldmia r1, {r1, r2}
	bl ov0_02158894
	cmp r0, #0
	beq _0215380C
	ldr r2, [r6, #0x48]
	ldr r0, [r6, #0xc]
	ldr r1, [r2, #0x64]
	cmp r1, r0
	ldr r1, [r2, #0x68]
	ldr r0, [r6, #0x10]
	ble _021537F4
	cmp r1, r0
	movgt r0, #0xa
	strgth r0, [r6, #0x4e]
	movle r0, #0xb
	strleh r0, [r6, #0x4e]
	b _02153B48
_021537F4:
	cmp r1, r0
	movgt r0, #0xb
	strgth r0, [r6, #0x4e]
	movle r0, #0xa
	strleh r0, [r6, #0x4e]
	b _02153B48
_0215380C:
	ldr r0, [r6, #0x68]
	cmp r0, #5
	beq _02153820
	mov r0, r6
	bl ov0_0215826C
_02153820:
	mov r0, #1
	strh r0, [r6, #0x4e]
	b _02153B48
_0215382C:
	ldrb r1, [r6, #0xa8]
	cmp r1, #0
	bne _02153858
	ldrh r3, [r6, #0x4c]
	add r1, r6, #0x30
	add r2, r6, #0x38
	bl ov0_02157F0C
	cmp r0, #0
	movne r0, #2
	strneh r0, [r6, #0x4e]
	b _02153860
_02153858:
	mov r0, #2
	strh r0, [r6, #0x4e]
_02153860:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r6, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02153B48
	bl _ZN6CActor12sub_020128ECEt
	b _02153B48
_02153890:
	ldr r2, [r6, #0x7c]
	add r1, r6, #0x24
	mvn r3, #0
	bl ov0_02156B30
	cmp r0, #0
	beq _02153B48
	mov r0, r6
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02153B48
_021538B8:
	cmp r1, #0xa
	ldreq r0, _02153B58 ; =0x00000AAA
	ldr sl, [r6, #0x38]
	ldrne r0, _02153B5C ; =0x0000F555
	ldr sb, [r6, #0x3c]
	mov r0, r0, asr #4
	mov r3, r0, lsl #1
	add r0, r3, #1
	mov r2, r0, lsl #1
	ldr r1, _02153B54 ; =FX_SinCosTable_
	mov r0, r3, lsl #1
	ldrsh r5, [r1, r2]
	ldrsh r4, [r1, r0]
	str sl, [sp, #0x64]
	smull r8, r7, sl, r5
	smull r3, r2, sb, r4
	smull r1, r0, sb, r5
	smull ip, fp, sl, r4
	mov r8, r8, lsr #0xc
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	mov ip, ip, lsr #0xc
	orr r8, r8, r7, lsl #20
	orr r3, r3, r2, lsl #20
	sub r2, r8, r3
	orr r1, r1, r0, lsl #20
	orr ip, ip, fp, lsl #20
	add r7, r1, ip
	str r2, [r6, #0x38]
	str r7, [r6, #0x3c]
	ldr r0, [r6, #0x38]
	str sb, [sp, #0x68]
	smull r3, r2, r0, r0
	smull r1, r0, r7, r7
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	mov r1, r4, asr #0x1f
	str r1, [sp]
	mov r1, r5, asr #0x1f
	str r1, [sp, #4]
	bl FX_InvSqrt
	ldr r2, [r6, #0x38]
	mov r1, #7
	smull r7, r3, r2, r0
	mov r2, r7, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r6, #0x38]
	ldr r3, [r6, #0x3c]
	mov r2, #0x1e
	smull r7, r0, r3, r0
	mov r3, r7, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r6, #0x3c]
	mov r0, r6
	bl ov0_021582B4
	add r1, r6, #0x38
	ldr r3, [r6, #0x7c]
	mov r0, r6
	ldmia r1, {r1, r2}
	bl ov0_02158894
	cmp r0, #0
	beq _02153AC4
	ldr sb, [r6, #0x38]
	ldr r8, [r6, #0x3c]
	umull r2, r0, sb, r4
	umull sl, r3, r8, r4
	str r2, [sp, #0xc]
	mov r2, sl, lsr #0xc
	umull fp, ip, sb, r5
	ldr sl, [sp, #4]
	umull r7, r1, r8, r5
	str r2, [sp, #0x10]
	mov r2, r7, lsr #0xc
	ldr r7, [sp, #0xc]
	mov lr, fp, lsr #0xc
	mov r7, r7, lsr #0xc
	str r7, [sp, #8]
	mla ip, sb, sl, ip
	mla r1, r8, sl, r1
	ldr sl, [sp]
	mov r7, r8, asr #0x1f
	mla r3, r8, sl, r3
	str r8, [sp, #0x68]
	mov r8, sl
	mla r1, r7, r5, r1
	mov fp, sb, asr #0x1f
	mla r0, sb, r8, r0
	mla ip, fp, r5, ip
	orr r2, r2, r1, lsl #20
	mla r0, fp, r4, r0
	mla r3, r7, r4, r3
	ldr r1, [sp, #8]
	ldr r4, [sp, #0x10]
	orr r0, r1, r0, lsl #20
	orr r3, r4, r3, lsl #20
	add r2, r2, r0
	str r0, [sp, #8]
	smull r1, r0, r2, r2
	mov r1, r1, lsr #0xc
	orr lr, lr, ip, lsl #20
	str r3, [sp, #0x10]
	sub r3, lr, r3
	str r3, [r6, #0x38]
	str r2, [r6, #0x3c]
	ldr r3, [r6, #0x38]
	orr r1, r1, r0, lsl #20
	smull r2, r0, r3, r3
	mov r2, r2, lsr #0xc
	orr r2, r2, r0, lsl #20
	add r0, r2, r1
	str sb, [sp, #0x64]
	bl FX_InvSqrt
	ldr r2, [r6, #0x38]
	add r1, r6, #0x38
	smull r4, r3, r2, r0
	mov r2, r4, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r6, #0x38]
	ldr r2, [r6, #0x3c]
	smull r3, r0, r2, r0
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	str r2, [r6, #0x3c]
	ldr r3, [r6, #0x7c]
	mov r0, r6
	ldmia r1, {r1, r2}
	bl ov0_02158894
	b _02153B48
_02153AC4:
	ldr r0, [r6, #0x68]
	cmp r0, #5
	beq _02153AD8
	mov r0, r6
	bl ov0_0215826C
_02153AD8:
	ldrh r0, [r6, #0x86]
	ldr r2, [r6, #0x7c]
	ldr r1, [r6, #0x38]
	mov r0, r0, lsl #0xc
	smull r3, r0, r2, r0
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	ldr r0, [r6, #0x3c]
	smull r4, r3, r1, r2
	smull r2, r1, r0, r2
	mov r4, r4, lsr #0xc
	mov r0, r2, lsr #0xc
	ldr r2, [r6, #0xc]
	orr r4, r4, r3, lsl #20
	add r3, r2, r4
	ldr r2, [r6, #0x10]
	orr r0, r0, r1, lsl #20
	add r2, r2, r0
	str r3, [r6, #4]
	str r2, [r6, #8]
	ldrh r1, [r6, #0x80]
	mov r0, #1
	str r3, [sp, #0x5c]
	strh r1, [r6, #0x4c]
	str r2, [sp, #0x60]
	str r3, [sp, #0x14]
	str r2, [sp, #0x18]
	strh r0, [r6, #0x4e]
_02153B48:
	mov r0, #0
	add sp, sp, #0x74
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02153B54: .word FX_SinCosTable_
_02153B58: .word 0x00000AAA
_02153B5C: .word 0x0000F555

	arm_func_start ov0_02153B60
ov0_02153B60: ; 0x02153B60
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x30
	mov r6, r0
	cmp r1, #0
	bgt _02153B94
	ldr r2, [r6, #0x88]
	ldr r3, [r6, #0xb4]
	add r1, r6, #4
	bl ov0_02158928
	cmp r0, #0
	moveq r5, #1
	movne r5, #0
	b _02153D68
	arm_func_end ov0_02153B60
_02153B94:
	ldrh r2, [r6, #0x86]
	sub r0, r1, #1
	ldr r3, [r6, #0x7c]
	mov r2, r2, lsl #0xc
	smull r2, r4, r3, r2
	mov r0, r0, asr #1
	add r0, r0, #1
	mov r0, r0, lsl #0x1c
	mov r2, r2, lsr #0xc
	mov r0, r0, lsr #0x10
	cmp r0, #0x4000
	orr r2, r2, r4, lsl #20
	movhi r4, #1
	movls r4, #0
	tst r1, #1
	rsbne r0, r0, #0x10000
	movne r0, r0, lsl #0x10
	movne r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r5, r0, lsl #1
	add r0, r5, #1
	mov r1, r0, lsl #1
	ldr r3, _02153D74 ; =FX_SinCosTable_
	mov r0, r5, lsl #1
	ldrsh r1, [r3, r1]
	ldrsh ip, [r3, r0]
	ldr lr, [r6, #0x3c]
	ldr sb, [r6, #0x38]
	smull r5, r3, lr, r1
	smull r8, r7, lr, ip
	smull r1, r0, sb, r1
	smull lr, ip, sb, ip
	mov r1, r1, lsr #0xc
	mov r8, r8, lsr #0xc
	mov lr, lr, lsr #0xc
	mov r5, r5, lsr #0xc
	orr r1, r1, r0, lsl #20
	orr r8, r8, r7, lsl #20
	sub r0, r1, r8
	smull r1, r7, r0, r2
	mov r8, r1, lsr #0xc
	orr lr, lr, ip, lsl #20
	orr r5, r5, r3, lsl #20
	add r0, lr, r5
	smull r2, r1, r0, r2
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	ldr r2, [r6, #0xc]
	orr r8, r8, r7, lsl #20
	add r2, r2, r8
	str r2, [sp, #0x28]
	ldr r2, [r6, #0x10]
	add r1, sp, #0x28
	add r0, r2, r0
	str r0, [sp, #0x2c]
	ldr r2, [r6, #0x88]
	ldr r3, [r6, #0xb4]
	mov r0, r6
	bl ov0_02158928
	cmp r0, #0
	moveq r5, #1
	movne r5, #0
	cmp r4, #0
	beq _02153D50
	ldr r0, [r6, #0xac]
	cmp r0, #0
	beq _02153D08
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02153CE8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02153CCC
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	b _02153D00
_02153CCC:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	b _02153D00
_02153CE8:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_02153D00:
	add r2, sp, #0x18
	b _02153D24
_02153D08:
	mov r0, #0
	add r1, sp, #0
	add r2, sp, #0x18
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_02153D24:
	ldr r3, [r2]
	ldr r2, [r2, #4]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	sub r0, r0, r3
	sub r1, r1, r2
	str r3, [sp, #0x20]
	str r2, [sp, #0x24]
	bl _Z12sub_02007254ll
	cmp r0, #0x20000
	movlt r5, #0
_02153D50:
	cmp r5, #0
	beq _02153D68
	ldr r0, [sp, #0x28]
	str r0, [r6, #4]
	ldr r0, [sp, #0x2c]
	str r0, [r6, #8]
_02153D68:
	mov r0, r5
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02153D74: .word FX_SinCosTable_

	arm_func_start ov0_02153D78
ov0_02153D78: ; 0x02153D78
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	and r0, r1, #0xff
	cmp r0, #7
	addls pc, pc, r0, lsl #2
	b _02154208
_02153D94: ; jump table
	b _02153DB4 ; case 0
	b _02153E14 ; case 1
	b _02153ECC ; case 2
	b _02153F64 ; case 3
	b _02153FEC ; case 4
	b _0215405C ; case 5
	b _02154118 ; case 6
	b _02154184 ; case 7
	arm_func_end ov0_02153D78
_02153DB4:
	mov r5, r1, asr #8
	mov r7, r5, lsl #8
	mov r6, #0
	b _02153DF0
_02153DC4:
	mov r0, r4
	mov r1, r5
	bl ov0_02153B60
	cmp r0, #0
	movne r0, #1
	strneh r0, [r4, #0x4e]
	bne _02153DFC
	add r7, r7, #0x100
	strh r7, [r4, #0x4e]
	add r5, r5, #1
	add r6, r6, #1
_02153DF0:
	cmp r5, #0x10
	cmplt r6, #4
	blt _02153DC4
_02153DFC:
	cmp r5, #0x10
	blt _02154208
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02154208
_02153E14:
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02153E50
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02153E50
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_02153E50:
	mov r0, r4
	mov r1, #0
	bl ov0_021580F8
	mvn r1, #0
	cmp r0, r1
	bne _02153EA4
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02153E90
	mov r1, #7
	mov r2, #0x1800
	mov r3, #0x800
	bl _ZN6CActor12sub_02012A3CEill
_02153E90:
	mov r0, #4
	strh r0, [r4, #0x4e]
	mov r0, #7
	str r0, [r4, #0x50]
	b _02153EAC
_02153EA4:
	mov r0, #2
	strh r0, [r4, #0x4e]
_02153EAC:
	ldr r0, [r4, #0xcc]
	cmp r0, #0
	bne _02154208
	mov r0, r4
	mov r1, #0x56
	mov r2, #0x5c
	bl ov0_02158294
	b _02154208
_02153ECC:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02153EF4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _02153EF8
	bl _ZN6CActor12sub_02012AFCEv
	b _02153EF8
_02153EF4:
	mov r0, #2
_02153EF8:
	cmp r0, #0
	bne _02154208
	mov r1, #3
	strh r1, [r4, #0x4e]
	mov r0, r4
	mov r1, #1
	bl ov0_021580F8
	ldr r0, [r4, #0x48]
	ldr r5, [r4, #8]
	ldr r6, [r0, #8]
	ldr r7, [r4, #4]
	cmp r6, #0
	ldrne r4, [r6, #0xc]
	cmpne r4, #0
	beq _02154208
	mov r1, r7
	add r0, r4, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r5
	add r0, r4, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r7, [r0, #0x18]
	strne r5, [r0, #0x1c]
	b _02154208
_02153F64:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02153F8C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _02153F90
	bl _ZN6CActor12sub_02012AFCEv
	b _02153F90
_02153F8C:
	mov r0, #2
_02153F90:
	cmp r0, #0
	bne _02154208
	ldr r2, [r4, #0x48]
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _02153FDC
	ldr r0, [r2, #4]
	tst r0, #8
	bne _02153FDC
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
_02153FDC:
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02154208
_02153FEC:
	ldr r0, [r4, #0x48]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _02154010
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x11c]
	moveq r0, #0x1000
	b _02154014
_02154010:
	mov r0, #0x1000
_02154014:
	cmp r0, #0x1800
	beq _02154028
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bgt _02154208
_02154028:
	cmp r1, #0
	ldrne r0, [r1, #0xc]
	cmpne r0, #0
	beq _02154048
	mov r1, #7
	mov r2, #0
	mov r3, #0x2000
	bl _ZN6CActor12sub_02012A3CEill
_02154048:
	mov r0, #5
	strh r0, [r4, #0x4e]
	mov r0, #7
	str r0, [r4, #0x50]
	b _02154208
_0215405C:
	ldr r0, [r4, #0x48]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _02154080
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x11c]
	moveq r0, #0x1000
	b _02154084
_02154080:
	mov r0, #0x1000
_02154084:
	cmp r0, #0
	beq _02154098
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bgt _02154208
_02154098:
	cmp r1, #0
	ldrne r0, [r1, #0xc]
	cmpne r0, #0
	beq _021540B8
	mov r1, #7
	mov r2, #0x1800
	mov r3, #0x800
	bl _ZN6CActor12sub_02012A3CEill
_021540B8:
	ldr r0, [r4, #0x48]
	ldr r5, [r4, #8]
	ldr r6, [r0, #8]
	ldr r8, [r4, #4]
	cmp r6, #0
	ldrne r7, [r6, #0xc]
	cmpne r7, #0
	beq _02154104
	mov r1, r8
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r5
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r8, [r0, #0x18]
	strne r5, [r0, #0x1c]
_02154104:
	mov r0, #6
	strh r0, [r4, #0x4e]
	mov r0, #7
	str r0, [r4, #0x50]
	b _02154208
_02154118:
	ldr r0, [r4, #0x48]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0215413C
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x11c]
	moveq r0, #0x1000
	b _02154140
_0215413C:
	mov r0, #0x1000
_02154140:
	cmp r0, #0x1800
	beq _02154154
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bgt _02154208
_02154154:
	cmp r1, #0
	ldrne r0, [r1, #0xc]
	cmpne r0, #0
	beq _02154174
	mov r2, #0x1000
	mov r3, r2
	mov r1, #7
	bl _ZN6CActor12sub_02012A3CEill
_02154174:
	mov r0, #7
	strh r0, [r4, #0x4e]
	str r0, [r4, #0x50]
	b _02154208
_02154184:
	ldr r2, [r4, #0x48]
	ldr r1, [r2, #8]
	cmp r1, #0
	beq _021541A8
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x11c]
	moveq r0, #0x1000
	b _021541AC
_021541A8:
	mov r0, #0x1000
_021541AC:
	cmp r0, #0x1000
	beq _021541C0
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bgt _02154208
_021541C0:
	cmp r1, #0
	beq _021541FC
	ldr r0, [r2, #4]
	tst r0, #8
	bne _021541FC
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
_021541FC:
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_02154208:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov0_02154210
ov0_02154210: ; 0x02154210
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x90
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0
	beq _0215423C
	cmp r1, #1
	beq _02154570
	cmp r1, #2
	beq _021545D4
	b _021545DC
	arm_func_end ov0_02154210
_0215423C:
	bl ov0_02156A8C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154264
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _02154268
_02154264:
	mov r0, #0
_02154268:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _021545E8 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021542A8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _021542AC
_021542A8:
	mov r0, #0
_021542AC:
	mov r1, r0, asr #4
	ldr r0, _021545E8 ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x34]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _02154334
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154314
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021542F8
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x78]
	str r0, [sp, #0x7c]
	b _0215432C
_021542F8:
	mov r0, #0
	add r1, sp, #0x40
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x78]
	str r0, [sp, #0x7c]
	b _0215432C
_02154314:
	mov r0, #0
	add r1, sp, #0x48
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x78]
	str r0, [sp, #0x7c]
_0215432C:
	add r5, sp, #0x78
	b _02154350
_02154334:
	mov r0, #0
	add r1, sp, #0x38
	add r5, sp, #0x78
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x78]
	str r0, [sp, #0x7c]
_02154350:
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r5]
	ldr r0, [r5, #4]
	sub r1, r1, r3
	sub r6, r0, r2
	str r1, [r4, #0x38]
	str r6, [r4, #0x3c]
	ldr r0, [r4, #0x38]
	str r3, [sp, #0x70]
	smull r5, lr, r0, r0
	smull ip, r0, r6, r6
	mov r5, r5, lsr #0xc
	mov ip, ip, lsr #0xc
	orr r5, r5, lr, lsl #20
	orr ip, ip, r0, lsl #20
	add r0, r5, ip
	str r2, [sp, #0x74]
	str r3, [sp, #0x58]
	str r2, [sp, #0x5c]
	str r1, [sp, #0x50]
	str r6, [sp, #0x54]
	str r1, [sp, #0x80]
	str r6, [sp, #0x84]
	bl FX_InvSqrt
	ldr r1, [r4, #0x38]
	smull r3, r2, r1, r0
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	smull r2, r0, r1, r0
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r4, #0x3c]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _02154450
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154430
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02154414
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x68]
	str r0, [sp, #0x6c]
	b _02154448
_02154414:
	mov r0, #0
	add r1, sp, #0x28
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x68]
	str r0, [sp, #0x6c]
	b _02154448
_02154430:
	mov r0, #0
	add r1, sp, #0x30
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x68]
	str r0, [sp, #0x6c]
_02154448:
	add r5, sp, #0x68
	b _0215446C
_02154450:
	mov r0, #0
	add r1, sp, #0x20
	add r5, sp, #0x68
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x68]
	str r0, [sp, #0x6c]
_0215446C:
	ldr r0, [r4, #0x38]
	ldr r2, [r4, #0xac]
	rsb r1, r0, #0
	mov r0, #0x23000
	umull ip, r3, r1, r0
	mov r1, r1, asr #0x1f
	mla r3, r1, r0, r3
	mov r1, ip, lsr #0xc
	ldr r0, [r5]
	orr r1, r1, r3, lsl #20
	add r0, r1, r0
	str r0, [sp, #0x88]
	cmp r2, #0
	mov r1, #0
	beq _02154508
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _021544EC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021544D4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x60]
	str r0, [sp, #0x64]
	b _02154500
_021544D4:
	add r0, sp, #0x10
	str r1, [sp, #0x60]
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [sp, #0x64]
	b _02154500
_021544EC:
	add r0, sp, #0x18
	str r1, [sp, #0x60]
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [sp, #0x64]
_02154500:
	add r5, sp, #0x60
	b _02154520
_02154508:
	add r0, sp, #8
	add r5, sp, #0x60
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [sp, #0x60]
	str r1, [sp, #0x64]
_02154520:
	ldr r0, [r4, #0x3c]
	ldr r2, [sp, #0x88]
	rsb r1, r0, #0
	mov r0, #0x23000
	umull lr, ip, r1, r0
	mov r3, r1, asr #0x1f
	mla ip, r3, r0, ip
	mov r0, lr, lsr #0xc
	ldr r1, [r5, #4]
	orr r0, r0, ip, lsl #20
	add r3, r0, r1
	stmib r4, {r2, r3}
	ldrh r1, [r4, #0x80]
	mov r0, #1
	str r3, [sp, #0x8c]
	strh r1, [r4, #0x4c]
	str r2, [sp]
	str r3, [sp, #4]
	strh r0, [r4, #0x4e]
	b _021545DC
_02154570:
	ldrb r1, [r4, #0xa8]
	cmp r1, #0
	bne _0215459C
	ldrh r3, [r4, #0x4c]
	add r1, r4, #0x30
	add r2, r4, #0x38
	bl ov0_02157F0C
	cmp r0, #0
	movne r0, #2
	strneh r0, [r4, #0x4e]
	b _021545A4
_0215459C:
	mov r0, #2
	strh r0, [r4, #0x4e]
_021545A4:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021545DC
	bl _ZN6CActor12sub_020128ECEt
	b _021545DC
_021545D4:
	mov r1, #6
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_021545DC:
	mov r0, #0
	add sp, sp, #0x90
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_021545E8: .word FX_SinCosTable_

	arm_func_start ov0_021545EC
ov0_021545EC: ; 0x021545EC
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	ldrh r1, [r6, #0x4e]
	cmp r1, #0
	beq _02154618
	cmp r1, #1
	beq _02154688
	cmp r1, #2
	beq _021547E8
	b _021547FC
	arm_func_end ov0_021545EC
_02154618:
	mov r1, #4
	mov r2, #0x1e
	bl ov0_021582B4
	mov r0, r6
	bl ov0_0215826C
	mov r0, r6
	bl ov0_02156A8C
	ldr r1, [r6, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02154670
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02154670
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_02154670:
	mov r0, r6
	mov r1, #0
	bl ov0_021580F8
	mov r0, #1
	strh r0, [r6, #0x4e]
	b _021547FC
_02154688:
	ldr r0, [r6, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021546B0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _021546B4
	bl _ZN6CActor12sub_02012AFCEv
	b _021546B4
_021546B0:
	mov r0, #2
_021546B4:
	cmp r0, #0
	bne _021547FC
	ldr r2, [r6, #0x48]
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _02154700
	ldr r0, [r2, #4]
	tst r0, #8
	bne _02154700
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
_02154700:
	ldr r0, _02154808 ; =MAIN_BSS_0210CA60
	ldr r3, _0215480C ; =MAIN_BSS_0210CA78
	ldr r4, [r0]
	mov r1, #0xc
	mov r0, r4
	mov r2, #0
	ldr r5, [r3]
	bl _ZN18CFieldEffectManage12ov0_02142F6CEii
	mov r1, r0
	mov r0, r4
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r4, r0
	beq _021547A4
	ldr r3, [r0]
	ldr r1, [r6, #0xc]
	ldr r3, [r3, #0x38]
	mov r2, r1, asr #0xc
	mov r1, #1
	blx r3
	mov r0, r4
	ldr r3, [r0]
	ldr r2, [r6, #0x10]
	ldr r1, [r6, #0x14]
	ldr r3, [r3, #0x38]
	sub r1, r2, r1
	mov r2, r1, asr #0xc
	mov r1, #2
	blx r3
	mov r0, r4
	mov r1, #0x12
	ldrb r2, [r6, #0x93]
	ldr r3, [r0]
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, r4
	mov r1, #0
	sub r2, r1, #1
	mov r3, r1
	ldr r4, [r0]
	ldr r4, [r4, #0x1c]
	blx r4
_021547A4:
	cmp r5, #0
	beq _021547D4
	mov r0, r5
	mov r1, #6
	bl _ZN17UnkClass_0211D85012sub_02035D38Ei
	mov r4, #0x96
	mov r0, r5
	mov r1, #6
	mov r2, #0xf
	mov r3, #0x1e
	str r4, [sp]
	bl _ZN17UnkClass_0211D85012sub_02035DA0Eiiii
_021547D4:
	mov r0, #0x78
	str r0, [r6, #0x50]
	mov r0, #2
	strh r0, [r6, #0x4e]
	b _021547FC
_021547E8:
	ldr r1, [r6, #0x50]
	cmp r1, #0
	bgt _021547FC
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_021547FC:
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02154808: .word MAIN_BSS_0210CA60
_0215480C: .word MAIN_BSS_0210CA78

	arm_func_start ov0_02154810
ov0_02154810: ; 0x02154810
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #3
	addls pc, pc, r1, lsl #2
	b _02154A78
_02154828: ; jump table
	b _02154838 ; case 0
	b _021548A8 ; case 1
	b _02154994 ; case 2
	b _021549F4 ; case 3
	arm_func_end ov0_02154810
_02154838:
	mov r1, #4
	mov r2, #0x1e
	bl ov0_021582B4
	mov r0, r4
	bl ov0_0215826C
	mov r0, r4
	bl ov0_02156A8C
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02154890
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02154890
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_02154890:
	mov r0, r4
	mov r1, #0
	bl ov0_021580F8
	mov r0, #1
	strh r0, [r4, #0x4e]
	b _02154A78
_021548A8:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021548D0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _021548D4
	bl _ZN6CActor12sub_02012AFCEv
	b _021548D4
_021548D0:
	mov r0, #2
_021548D4:
	cmp r0, #0
	bne _02154A78
	ldr r0, _02154A80 ; =MAIN_BSS_0210CA60
	mov r1, #0xd
	ldr r5, [r0]
	mov r2, #0
	mov r0, r5
	bl _ZN18CFieldEffectManage12ov0_02142F6CEii
	mov r1, r0
	mov r0, r5
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r5, r0
	beq _02154980
	ldr r3, [r0]
	ldr r1, [r4, #0xc]
	ldr r3, [r3, #0x38]
	mov r2, r1, asr #0xc
	mov r1, #1
	blx r3
	mov r0, r5
	ldr r3, [r0]
	ldr r1, [r4, #0x10]
	ldr r3, [r3, #0x38]
	mov r2, r1, asr #0xc
	mov r1, #2
	blx r3
	mov r0, r5
	ldr r3, [r0]
	mov r1, #0x12
	ldrb r2, [r4, #0x93]
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, r5
	mov r1, #0
	sub r2, r1, #1
	mov r3, r1
	ldr ip, [r0]
	ldr ip, [ip, #0x1c]
	blx ip
	mov r0, r4
	mov r1, #0x57
	mov r2, #0x5d
	bl ov0_02158294
_02154980:
	mov r0, #0x3c
	str r0, [r4, #0x50]
	mov r0, #2
	strh r0, [r4, #0x4e]
	b _02154A78
_02154994:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bgt _02154A78
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _021549DC
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _021549DC
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_021549DC:
	mov r0, r4
	mov r1, #1
	bl ov0_021580F8
	mov r0, #3
	strh r0, [r4, #0x4e]
	b _02154A78
_021549F4:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154A1C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _02154A20
	bl _ZN6CActor12sub_02012AFCEv
	b _02154A20
_02154A1C:
	mov r0, #2
_02154A20:
	cmp r0, #0
	bne _02154A78
	ldr r2, [r4, #0x48]
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _02154A6C
	ldr r0, [r2, #4]
	tst r0, #8
	bne _02154A6C
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
_02154A6C:
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_02154A78:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02154A80: .word MAIN_BSS_0210CA60

	arm_func_start ov0_02154A84
ov0_02154A84: ; 0x02154A84
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	ldr r0, [r8, #0xcc]
	cmp r0, #0
	bne _02154BE4
	ldrh r1, [r8, #0x6c]
	cmp r1, #0x10
	blo _02154BE4
	cmp r1, #0x12
	bhi _02154BE4
	ldrh r0, [r8, #0xb8]
	cmp r0, #0
	bne _02154BE4
	ldr r0, _02154C28 ; =MAIN_BSS_0210CA60
	ldr r7, [r0]
	cmp r7, #0
	beq _02154BE4
	cmp r1, #0x10
	mov r5, #0
	beq _02154AE8
	cmp r1, #0x11
	beq _02154AF0
	cmp r1, #0x12
	beq _02154AF8
	b _02154B00
	arm_func_end ov0_02154A84
_02154AE8:
	mov r5, #0x84
	b _02154B08
_02154AF0:
	mov r5, #0x85
	b _02154B08
_02154AF8:
	mov r5, #0x86
	b _02154B08
_02154B00:
	ldr r0, _02154C2C ; =s_ProcSpecaialEffect_ScriptID_d_overlay_0_021780f8
	bl LogError
_02154B08:
	mov r0, r7
	mov r1, #0
	bl _ZN18CFieldEffectManage12ov0_02143024Et
	movs r6, r0
	beq _02154B78
_02154B1C:
	mov r0, r7
	mov r1, r6
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r4, r0
	beq _02154B64
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	cmp r0, #0x12
	ldreq r1, [r4, #0x1ec]
	ldreq r0, [r8, #0x48]
	cmpeq r1, r0
	bne _02154B64
	add r0, r4, #0x100
	ldrh r0, [r0, #0xfc]
	tst r0, #0x8000
	streqh r6, [r8, #0xb8]
	beq _02154B78
_02154B64:
	mov r0, r7
	mov r1, r6
	bl _ZN18CFieldEffectManage12ov0_02143024Et
	movs r6, r0
	bne _02154B1C
_02154B78:
	ldrh r0, [r8, #0xb8]
	cmp r0, #0
	bne _02154BE4
	mov r0, r7
	mov r2, r5
	mov r1, #0x12
	bl _ZN18CFieldEffectManage12ov0_02142F6CEii
	strh r0, [r8, #0xb8]
	ldrh r1, [r8, #0xb8]
	mov r0, r7
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r4, r0
	beq _02154BE4
	ldr r2, [r8, #0x48]
	mov r1, #0x12
	str r2, [r4, #0x1ec]
	ldr r3, [r0]
	ldrb r2, [r8, #0x93]
	ldr r3, [r3, #0x38]
	blx r3
	mov r1, #0
	mov r0, r4
	ldr r4, [r0]
	mov r3, r1
	ldr r4, [r4, #0x1c]
	sub r2, r1, #1
	blx r4
_02154BE4:
	ldrh r1, [r8, #0xb8]
	cmp r1, #0
	ldrne r0, _02154C28 ; =MAIN_BSS_0210CA60
	ldrne r0, [r0]
	cmpne r0, #0
	beq _02154C20
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	cmp r0, #0
	beq _02154C20
	ldr r1, [r8, #0x44]
	cmp r1, #1
	bne _02154C1C
	bl ov0_021633B8
	b _02154C20
_02154C1C:
	bl ov0_021633CC
_02154C20:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02154C28: .word MAIN_BSS_0210CA60
_02154C2C: .word s_ProcSpecaialEffect_ScriptID_d_overlay_0_021780f8

	arm_func_start ov0_02154C30
ov0_02154C30: ; 0x02154C30
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #4
	mov r2, #0x1e
	bl ov0_021582B4
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	mov r0, #0
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02154C30

	arm_func_start ov0_02154C58
ov0_02154C58: ; 0x02154C58
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0xe4
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #6
	addls pc, pc, r1, lsl #2
	b _02155528
_02154C74: ; jump table
	b _02154C90 ; case 0
	b _02154F04 ; case 1
	b _02154F68 ; case 2
	b _02155018 ; case 3
	b _02155340 ; case 4
	b _0215535C ; case 5
	b _021553C4 ; case 6
	arm_func_end ov0_02154C58
_02154C90:
	mov r1, #4
	mov r2, #0x1e
	bl ov0_021582B4
	mov r0, r4
	bl ov0_0215826C
	mov r0, r4
	bl ov0_02156A8C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154CD0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _02154CD4
_02154CD0:
	mov r0, #0
_02154CD4:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _02155534 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154D14
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _02154D18
_02154D14:
	mov r0, #0
_02154D18:
	mov r1, r0, asr #4
	ldr r0, _02155534 ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x34]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _02154DA0
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154D80
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02154D64
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x90]
	str r0, [sp, #0x94]
	b _02154D98
_02154D64:
	mov r0, #0
	add r1, sp, #0x50
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x90]
	str r0, [sp, #0x94]
	b _02154D98
_02154D80:
	mov r0, #0
	add r1, sp, #0x58
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x90]
	str r0, [sp, #0x94]
_02154D98:
	add r5, sp, #0x90
	b _02154DBC
_02154DA0:
	mov r0, #0
	add r1, sp, #0x48
	add r5, sp, #0x90
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x90]
	str r0, [sp, #0x94]
_02154DBC:
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r5]
	ldr r0, [r5, #4]
	sub r1, r1, r3
	sub lr, r0, r2
	str r1, [r4, #0x38]
	str lr, [r4, #0x3c]
	ldr r0, [r4, #0x38]
	str r3, [sp, #0x88]
	smull ip, r6, r0, r0
	smull r5, r0, lr, lr
	mov ip, ip, lsr #0xc
	mov r5, r5, lsr #0xc
	orr ip, ip, r6, lsl #20
	orr r5, r5, r0, lsl #20
	add r0, ip, r5
	str r2, [sp, #0x8c]
	str r3, [sp, #0x68]
	str r2, [sp, #0x6c]
	str r1, [sp, #0x60]
	str lr, [sp, #0x64]
	str r1, [sp, #0x98]
	str lr, [sp, #0x9c]
	bl FX_InvSqrt
	ldr r1, [r4, #0x38]
	smull r3, r2, r1, r0
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	smull r2, r0, r1, r0
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r4, #0x3c]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _02154EBC
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02154E9C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02154E80
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x80]
	str r0, [sp, #0x84]
	b _02154EB4
_02154E80:
	mov r0, #0
	add r1, sp, #0x30
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x80]
	str r0, [sp, #0x84]
	b _02154EB4
_02154E9C:
	mov r0, #0
	add r1, sp, #0x38
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x80]
	str r0, [sp, #0x84]
_02154EB4:
	add r2, sp, #0x80
	b _02154ED8
_02154EBC:
	mov r0, #0
	add r1, sp, #0x28
	add r2, sp, #0x80
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x80]
	str r0, [sp, #0x84]
_02154ED8:
	ldr r3, [r2]
	ldr r2, [r2, #4]
	mov r0, #1
	str r3, [r4, #4]
	str r2, [r4, #8]
	ldrh r1, [r4, #0x80]
	str r3, [sp, #0x40]
	str r2, [sp, #0x44]
	strh r1, [r4, #0x4c]
	strh r0, [r4, #0x4e]
	b _02155528
_02154F04:
	ldrb r1, [r4, #0xa8]
	cmp r1, #0
	bne _02154F30
	ldrh r3, [r4, #0x4c]
	add r1, r4, #0x30
	add r2, r4, #0x38
	bl ov0_02157F0C
	cmp r0, #0
	movne r0, #2
	strneh r0, [r4, #0x4e]
	b _02154F38
_02154F30:
	mov r0, #2
	strh r0, [r4, #0x4e]
_02154F38:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02155528
	bl _ZN6CActor12sub_020128ECEt
	b _02155528
_02154F68:
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02154FA4
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02154FA4
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_02154FA4:
	ldr r3, [r4, #0x48]
	mov r0, r4
	ldr r2, [r3, #4]
	mov r1, #2
	bic r2, r2, #0x400
	str r2, [r3, #4]
	bl ov0_021580F8
	mov r0, #3
	strh r0, [r4, #0x4e]
	ldr r1, [r4, #0x30]
	mov r0, #0x6000
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r4, #0x24]
	ldr r2, [r4, #0x34]
	mov r1, #0x4000
	umull r5, r3, r2, r0
	mov r2, r2, asr #0x1f
	mla r3, r2, r0, r3
	mov r0, r5, lsr #0xc
	orr r0, r0, r3, lsl #20
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	mov r0, #0x3c
	str r0, [r4, #0x50]
	b _02155528
_02155018:
	bl ov0_02158420
	cmp r0, #0
	beq _02155174
	ldr r0, [r4, #0xac]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02155074
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02155054
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x78]
	str r0, [sp, #0x7c]
	b _0215506C
_02155054:
	mov r0, #0
	add r1, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x78]
	str r0, [sp, #0x7c]
_0215506C:
	add r2, sp, #0x78
	b _02155090
_02155074:
	mov r0, #0
	add r1, sp, #0x18
	add r2, sp, #0x78
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x78]
	str r0, [sp, #0x7c]
_02155090:
	ldr r0, [r4, #0xac]
	ldr r2, [r2]
	ldr r1, [r4, #0xc]
	ldr r0, [r0, #8]
	sub r6, r2, r1
	cmp r0, #0
	beq _021550EC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021550CC
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x70]
	str r0, [sp, #0x74]
	b _021550E4
_021550CC:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x70]
	str r0, [sp, #0x74]
_021550E4:
	add r2, sp, #0x70
	b _02155108
_021550EC:
	mov r0, #0
	add r1, sp, #8
	add r2, sp, #0x70
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x70]
	str r0, [sp, #0x74]
_02155108:
	ldr r1, [r2, #4]
	ldr r0, [r4, #0x10]
	smull r3, r2, r6, r6
	sub r5, r1, r0
	smull r1, r0, r5, r5
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	bl FX_InvSqrt
	smull r1, ip, r6, r0
	smull r0, r3, r5, r0
	mov r2, r0, lsr #0xc
	ldrb r5, [r4, #0x93]
	mov r1, r1, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r5, [sp]
	mvn r0, #0
	str r0, [sp, #4]
	ldr r0, [r4, #0xac]
	orr r1, r1, ip, lsl #20
	mov r3, #0xa
	bl _ZN12CFieldPlayer12ov0_021333A0Elliii
	mov r0, #5
	strh r0, [r4, #0x4e]
	b _02155528
_02155174:
	ldr r1, [r4, #0x2c]
	mov r0, #0xa000
	sub r1, r1, #0x800
	rsb r0, r0, #0
	str r1, [r4, #0x2c]
	cmp r1, r0
	strlt r0, [r4, #0x2c]
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x24]
	add r0, r1, r0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0x28]
	add r0, r1, r0
	str r0, [r4, #0x1c]
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #0x2c]
	adds r0, r1, r0
	str r0, [r4, #0x20]
	movmi r0, #0
	strmi r0, [r4, #0x20]
	ldr r0, [r4, #0xc]
	str r0, [sp, #0xd4]
	ldr r0, [r4, #0x10]
	str r0, [sp, #0xd8]
	ldr r0, [r4, #0x18]
	str r0, [sp, #0xdc]
	ldr r0, [r4, #0x1c]
	str r0, [sp, #0xe0]
	ldr r0, [r4, #0xbc]
	ldr r3, [r4, #0xb4]
	cmp r0, #0
	ldr r2, [r4, #0x64]
	moveq r0, #0
	beq _0215520C
	ldr r0, [r4, #0x48]
	add r1, sp, #0xd4
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
_0215520C:
	cmp r0, #0
	beq _021552A8
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #0x64]
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x48]
	ldr r8, [r0, #0x68]
	str r8, [r4, #0x1c]
	ldr r7, [r4, #0x48]
	ldr r5, [r4, #0x20]
	ldr sb, [r7, #8]
	ldr r6, [r4, #0x18]
	cmp sb, #0
	ldrne sl, [sb, #0xc]
	cmpne sl, #0
	beq _02155278
	mov r1, r6
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r8
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r6, [r0, #0x18]
	strne r8, [r0, #0x1c]
_02155278:
	ldr r0, [r7, #8]
	add r1, r4, #0xc
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	add r2, r4, #0x18
	cmpne r0, #0
	strne r5, [r0, #0x8c]
	add r0, sp, #0xb8
	bl ov0_02155538
	mov r0, #5
	strh r0, [r4, #0x4e]
	b _02155528
_021552A8:
	ldr r7, [r4, #0x48]
	ldr r5, [r4, #0x20]
	ldr sb, [r7, #8]
	ldr r8, [r4, #0x1c]
	cmp sb, #0
	ldrne sl, [sb, #0xc]
	ldr r6, [r4, #0x18]
	cmpne sl, #0
	beq _021552F8
	mov r1, r6
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r8
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r6, [r0, #0x18]
	strne r8, [r0, #0x1c]
_021552F8:
	ldr r0, [r7, #8]
	add r1, r4, #0xc
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	add r2, r4, #0x18
	cmpne r0, #0
	strne r5, [r0, #0x8c]
	add r0, sp, #0xac
	bl ov0_02155538
	ldr r0, [r4, #0x50]
	cmp r0, #0
	blt _02155334
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bgt _02155528
_02155334:
	mov r0, #4
	strh r0, [r4, #0x4e]
	b _02155528
_02155340:
	ldr r3, [r4, #0x48]
	mov r1, #1
	ldr r2, [r3, #4]
	orr r2, r2, #0x400
	str r2, [r3, #4]
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02155528
_0215535C:
	mov r1, #0x49
	mov r2, #0x4f
	bl ov0_02158294
	ldr r0, [r4, #0x30]
	mov r1, #0x2000
	rsb r2, r0, #0
	mov r0, r2, asr #0x1f
	mov r0, r0, lsl #0xc
	mov r3, r2, lsl #0xc
	orr r0, r0, r2, lsr #20
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	str r2, [r4, #0x24]
	ldr r2, [r4, #0x34]
	mov r0, #6
	rsb r3, r2, #0
	mov r2, r3, asr #0x1f
	mov r2, r2, lsl #0xc
	mov r5, r3, lsl #0xc
	orr r2, r2, r3, lsr #20
	mov r3, r5, lsr #0xc
	orr r3, r3, r2, lsl #20
	str r3, [r4, #0x28]
	str r1, [r4, #0x2c]
	strh r0, [r4, #0x4e]
	b _02155528
_021553C4:
	ldr r1, [r4, #0x2c]
	mov r0, #0xa000
	sub r1, r1, #0x800
	rsb r0, r0, #0
	str r1, [r4, #0x2c]
	cmp r1, r0
	strlt r0, [r4, #0x2c]
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x24]
	add r0, r1, r0
	str r0, [r4, #0x18]
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0x28]
	add r0, r1, r0
	str r0, [r4, #0x1c]
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #0x2c]
	adds r0, r1, r0
	str r0, [r4, #0x20]
	movmi r0, #0
	strmi r0, [r4, #0x20]
	ldr r0, [r4, #0xc]
	str r0, [sp, #0xc4]
	ldr r0, [r4, #0x10]
	str r0, [sp, #0xc8]
	ldr r0, [r4, #0x18]
	str r0, [sp, #0xcc]
	ldr r0, [r4, #0x1c]
	str r0, [sp, #0xd0]
	ldr r0, [r4, #0xbc]
	ldr r3, [r4, #0xb4]
	cmp r0, #0
	ldr r2, [r4, #0x64]
	moveq r0, #0
	beq _0215545C
	ldr r0, [r4, #0x48]
	add r1, sp, #0xc4
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
_0215545C:
	cmp r0, #0
	beq _021554A4
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #0x64]
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #0x68]
	str r0, [r4, #0x1c]
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x20]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x14]
	b _02155518
_021554A4:
	ldr r7, [r4, #0x48]
	ldr r5, [r4, #0x20]
	ldr sb, [r7, #8]
	ldr r8, [r4, #0x1c]
	cmp sb, #0
	ldrne sl, [sb, #0xc]
	ldr r6, [r4, #0x18]
	cmpne sl, #0
	beq _021554F4
	mov r1, r6
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r8
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r6, [r0, #0x18]
	strne r8, [r0, #0x1c]
_021554F4:
	ldr r0, [r7, #8]
	add r1, r4, #0xc
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	add r2, r4, #0x18
	cmpne r0, #0
	strne r5, [r0, #0x8c]
	add r0, sp, #0xa0
	bl ov0_02155538
_02155518:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	moveq r0, #4
	streqh r0, [r4, #0x4e]
_02155528:
	mov r0, #0
	add sp, sp, #0xe4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02155534: .word FX_SinCosTable_

	arm_func_start ov0_02155538
ov0_02155538: ; 0x02155538
	ldr ip, [r2, #8]
	str ip, [r1, #8]
	ldr r3, [r2, #4]
	str r3, [r1, #4]
	ldr r2, [r2]
	str r2, [r1]
	stmia r0, {r2, r3, ip}
	bx lr
	arm_func_end ov0_02155538

	arm_func_start ov0_02155558
ov0_02155558: ; 0x02155558
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #4
	mov r2, #0x1e
	bl ov0_021582B4
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	mov r0, #0
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02155558

	arm_func_start ov0_02155580
ov0_02155580: ; 0x02155580
	mov r0, #0
	bx lr
	arm_func_end ov0_02155580

	arm_func_start ov0_02155588
ov0_02155588: ; 0x02155588
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x40
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0
	beq _021555B4
	cmp r1, #1
	beq _02155800
	cmp r1, #2
	beq _02155874
	b _0215587C
	arm_func_end ov0_02155588
_021555B4:
	bl ov0_02156A8C
	ldrh ip, [r4, #0x70]
	ldr r0, _021558F0 ; =0x00000555
	ldr r1, [r4, #0xc8]
	mov r2, ip, lsl #0xc
	umull r6, r5, r2, r0
	mov r3, r2, asr #0x1f
	mul r2, ip, ip
	mla r5, r3, r0, r5
	mov r0, r6, lsr #0xc
	cmp r1, r2
	orr r0, r0, r5, lsl #20
	mov r1, #0
	bgt _0215587C
	str r1, [r4, #0x14]
	ldr r2, [r4, #0x48]
	ldr r1, [r2, #4]
	bic r1, r1, #1
	str r1, [r2, #4]
	ldrh r3, [r4, #0x9a]
	cmp r3, #0
	beq _02155640
	umull r2, r1, r0, r3
	mov r0, r0, asr #0x1f
	mla r1, r0, r3, r1
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	mov r0, r2, asr #0x1f
	mov r0, r0, lsl #0xb
	mov r1, r2, lsl #0xb
	orr r0, r0, r2, lsr #21
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r4, #0x2c]
	b _0215565C
_02155640:
	mov r1, r0, asr #0x1f
	mov r1, r1, lsl #0xa
	mov r2, r0, lsl #0xa
	orr r1, r1, r0, lsr #22
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r4, #0x2c]
_0215565C:
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _021556D0
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021556B0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02155694
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x30]
	str r0, [sp, #0x34]
	b _021556C8
_02155694:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	b _021556C8
_021556B0:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
_021556C8:
	add r5, sp, #0x30
	b _021556EC
_021556D0:
	mov r0, #0
	add r1, sp, #0
	add r5, sp, #0x30
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
_021556EC:
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r5]
	ldr r0, [r5, #4]
	sub r1, r1, r3
	sub r6, r0, r2
	str r1, [r4, #0x30]
	str r6, [r4, #0x34]
	ldr r0, [r4, #0x30]
	str r3, [sp, #0x28]
	smull r5, lr, r0, r0
	smull ip, r0, r6, r6
	mov r5, r5, lsr #0xc
	mov ip, ip, lsr #0xc
	orr r5, r5, lr, lsl #20
	orr ip, ip, r0, lsl #20
	add r0, r5, ip
	str r2, [sp, #0x2c]
	str r3, [sp, #0x20]
	str r2, [sp, #0x24]
	str r1, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r1, [sp, #0x38]
	str r6, [sp, #0x3c]
	bl FX_InvSqrt
	ldr r2, [r4, #0x30]
	mov r1, #0x3000
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r4, #0x30]
	ldr r2, [r4, #0x34]
	smull r3, r0, r2, r0
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	str r2, [r4, #0x34]
	ldr r0, [r4, #0x30]
	umull r3, r2, r0, r1
	mov r0, r0, asr #0x1f
	mla r2, r0, r1, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x34]
	umull r3, r2, r0, r1
	mov r0, r0, asr #0x1f
	mla r2, r0, r1, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021557E0
	bl _ZN6CActor12sub_020128ECEt
_021557E0:
	mov r0, r4
	bl ov0_0215826C
	mov r0, r4
	mov r1, #1
	bl ov0_02158B5C
	mov r0, #1
	strh r0, [r4, #0x4e]
	b _0215587C
_02155800:
	ldrh r1, [r4, #0x9a]
	ldr r0, [r4, #0x2c]
	cmp r1, #0
	subne r0, r0, r1
	subeq r0, r0, #0x800
	str r0, [r4, #0x2c]
	mov r0, #0xa000
	ldr r1, [r4, #0x2c]
	rsb r0, r0, #0
	cmp r1, r0
	strlt r0, [r4, #0x2c]
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x24]
	add r0, r1, r0
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0x28]
	add r0, r1, r0
	str r0, [r4, #0x10]
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #0x2c]
	adds r0, r1, r0
	str r0, [r4, #0x14]
	bpl _0215587C
	mov r0, #0
	str r0, [r4, #0x14]
	mov r0, #2
	strh r0, [r4, #0x4e]
	b _0215587C
_02155874:
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_0215587C:
	ldr r0, [r4, #0x48]
	ldr r5, [r4, #0x10]
	ldr r6, [r0, #8]
	ldr r8, [r4, #0xc]
	cmp r6, #0
	ldrne r7, [r6, #0xc]
	cmpne r7, #0
	beq _021558C8
	mov r1, r8
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r5
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r8, [r0, #0x18]
	strne r5, [r0, #0x1c]
_021558C8:
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	mov r0, #0
	add sp, sp, #0x40
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_021558F0: .word 0x00000555

	arm_func_start ov0_021558F4
ov0_021558F4: ; 0x021558F4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0
	beq _0215591C
	cmp r1, #1
	beq _02155970
	cmp r1, #2
	beq _021559C4
	b _021559CC
	arm_func_end ov0_021558F4
_0215591C:
	mov r1, #0xfa000
	str r1, [r4, #0x14]
	ldrh r3, [r4, #0x6e]
	ldr r1, [r4, #0xc8]
	mul r2, r3, r3
	cmp r1, r2
	bgt _021559CC
	mov r1, #0x99
	mov r2, #0x91
	bl ov0_02158294
	mov r0, #0x96000
	str r0, [r4, #0x14]
	ldr r3, [r4, #0x48]
	mov r1, #0
	ldr r2, [r3, #4]
	mov r0, #1
	bic r2, r2, #1
	str r2, [r3, #4]
	str r1, [r4, #0x2c]
	strh r0, [r4, #0x4e]
	b _021559CC
_02155970:
	ldrh r1, [r4, #0x9a]
	ldr r2, [r4, #0x2c]
	mov r0, #0x14000
	sub r1, r2, r1
	rsb r0, r0, #0
	cmp r1, r0
	str r1, [r4, #0x2c]
	movlt r0, #0x14000
	strlt r0, [r4, #0x2c]
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #0x2c]
	adds r0, r1, r0
	str r0, [r4, #0x14]
	bpl _021559CC
	mov r1, #0
	mov r0, r4
	str r1, [r4, #0x14]
	bl ov0_02158B5C
	mov r0, #2
	strh r0, [r4, #0x4e]
	b _021559CC
_021559C4:
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_021559CC:
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start ov0_021559F0
ov0_021559F0: ; 0x021559F0
	mov r0, #0
	bx lr
	arm_func_end ov0_021559F0

	arm_func_start ov0_021559F8
ov0_021559F8: ; 0x021559F8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4, #0x4e]
	cmp r0, #0
	beq _02155A20
	cmp r0, #1
	beq _02155A64
	cmp r0, #2
	beq _02155A78
	b _02155A88
	arm_func_end ov0_021559F8
_02155A20:
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #4]
	bic r0, r0, #0x400
	str r0, [r1, #4]
	ldr r0, [r4, #0x48]
	bl _ZN11CFieldEnemy12ov0_02134FCCEv
	ldr r2, [r4, #0x48]
	mov r0, #1
	ldr r1, [r2, #4]
	orr r1, r1, #1
	str r1, [r2, #4]
	ldr r2, [r4, #0x48]
	ldr r1, [r2, #4]
	orr r1, r1, #0x200
	str r1, [r2, #4]
	strh r0, [r4, #0x4e]
	b _02155A88
_02155A64:
	mov r0, #0x3c
	str r0, [r4, #0x50]
	mov r0, #2
	strh r0, [r4, #0x4e]
	b _02155A88
_02155A78:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	movle r0, #1
	strleh r0, [r4, #0x4e]
_02155A88:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start ov0_02155A90
ov0_02155A90: ; 0x02155A90
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0
	beq _02155AB4
	cmp r1, #1
	beq _02155B1C
	cmp r1, #2
	b _02155B80
	arm_func_end ov0_02155A90
_02155AB4:
	bl ov0_0215826C
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02155AF4
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02155AF4
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_02155AF4:
	ldr r3, [r4, #0x48]
	mov r0, r4
	ldr r2, [r3, #4]
	mov r1, #1
	bic r2, r2, #0x400
	str r2, [r3, #4]
	bl ov0_021580F8
	mov r0, #1
	strh r0, [r4, #0x4e]
	b _02155B80
_02155B1C:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02155B44
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _02155B48
	bl _ZN6CActor12sub_02012AFCEv
	b _02155B48
_02155B44:
	mov r0, #2
_02155B48:
	cmp r0, #0
	bne _02155B80
	ldr r0, [r4, #0x48]
	bl _ZN11CFieldEnemy12ov0_02134FCCEv
	ldr r2, [r4, #0x48]
	mov r0, #2
	ldr r1, [r2, #4]
	orr r1, r1, #1
	str r1, [r2, #4]
	ldr r2, [r4, #0x48]
	ldr r1, [r2, #4]
	orr r1, r1, #0x200
	str r1, [r2, #4]
	strh r0, [r4, #0x4e]
_02155B80:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start ov0_02155B88
ov0_02155B88: ; 0x02155B88
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x48]
	bl _ZN11CFieldEnemy12ov0_021351ACEv
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #4]
	bic r0, r0, #1
	str r0, [r1, #4]
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #4]
	bic r0, r0, #0x200
	str r0, [r1, #4]
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #4]
	orr r0, r0, #0x400
	str r0, [r1, #4]
	ldr r2, [r4, #0x48]
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _02155C0C
	ldr r0, [r2, #4]
	tst r0, #8
	bne _02155C0C
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
	arm_func_end ov0_02155B88
_02155C0C:
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start ov0_02155C20
ov0_02155C20: ; 0x02155C20
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4, #0x4e]
	cmp r0, #0
	beq _02155C40
	cmp r0, #1
	beq _02155C98
	b _02155D2C
	arm_func_end ov0_02155C20
_02155C40:
	ldr r0, [r4, #0x48]
	bl _ZN11CFieldEnemy12ov0_021351ACEv
	ldr r2, [r4, #0x48]
	ldr r0, _02155D34 ; =0x000001C7
	ldr r1, [r2, #4]
	bic r1, r1, #1
	str r1, [r2, #4]
	ldr r2, [r4, #0x48]
	ldr r1, [r2, #4]
	bic r1, r1, #0x200
	str r1, [r2, #4]
	ldr r1, [r4, #0xb0]
	cmp r1, r0
	beq _02155C80
	mov r0, r4
	bl ov0_0215826C
_02155C80:
	mov r0, r4
	mov r1, #0
	bl ov0_021580F8
	mov r0, #1
	strh r0, [r4, #0x4e]
	b _02155D2C
_02155C98:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02155CC0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _02155CC4
	bl _ZN6CActor12sub_02012AFCEv
	b _02155CC4
_02155CC0:
	mov r0, #2
_02155CC4:
	cmp r0, #0
	bne _02155D2C
	ldr r1, [r4, #0x48]
	ldr r0, [r1, #4]
	orr r0, r0, #0x400
	str r0, [r1, #4]
	ldr r2, [r4, #0x48]
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _02155D20
	ldr r0, [r2, #4]
	tst r0, #8
	bne _02155D20
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
_02155D20:
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_02155D2C:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02155D34: .word 0x000001C7

	arm_func_start ov0_02155D38
ov0_02155D38: ; 0x02155D38
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x38
	mov r6, r0
	bl ov0_02158420
	cmp r0, #0
	beq _02155E94
	ldr r0, [r6, #0xac]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02155DA0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02155D80
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x30]
	str r0, [sp, #0x34]
	b _02155D98
	arm_func_end ov0_02155D38
_02155D80:
	mov r0, #0
	add r1, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
_02155D98:
	add r2, sp, #0x30
	b _02155DBC
_02155DA0:
	mov r0, #0
	add r1, sp, #0x18
	add r2, sp, #0x30
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
_02155DBC:
	ldr r0, [r6, #0xac]
	ldr r2, [r2]
	ldr r1, [r6, #0xc]
	ldr r0, [r0, #8]
	sub r5, r2, r1
	cmp r0, #0
	beq _02155E18
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02155DF8
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x28]
	str r0, [sp, #0x2c]
	b _02155E10
_02155DF8:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
_02155E10:
	add r2, sp, #0x28
	b _02155E34
_02155E18:
	mov r0, #0
	add r1, sp, #8
	add r2, sp, #0x28
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
_02155E34:
	ldr r1, [r2, #4]
	ldr r0, [r6, #0x10]
	smull r3, r2, r5, r5
	sub r4, r1, r0
	smull r1, r0, r4, r4
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	bl FX_InvSqrt
	smull r1, ip, r5, r0
	smull r0, r3, r4, r0
	mov r2, r0, lsr #0xc
	ldrb r4, [r6, #0x93]
	mov r1, r1, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r4, [sp]
	mvn r0, #0
	str r0, [sp, #4]
	ldr r0, [r6, #0xac]
	orr r1, r1, ip, lsl #20
	mov r3, #0xa
	bl _ZN12CFieldPlayer12ov0_021333A0Elliii
_02155E94:
	mov r0, #0
	add sp, sp, #0x38
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov0_02155EA0
ov0_02155EA0: ; 0x02155EA0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x20
	mov r5, r0
	ldrh r1, [r5, #0x4e]
	mov r4, #1
	cmp r1, #5
	addls pc, pc, r1, lsl #2
	b _02156170
_02155EC0: ; jump table
	b _02155ED8 ; case 0
	b _02155F34 ; case 1
	b _02155F50 ; case 2
	b _02156088 ; case 3
	b _021560C4 ; case 4
	b _02156100 ; case 5
	arm_func_end ov0_02155EA0
_02155ED8:
	ldr r1, [r5, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02155F14
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02155F14
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_02155F14:
	mov r0, r5
	mov r1, #1
	bl ov0_021580F8
	mov r0, #1
	strh r0, [r5, #0x4e]
	mov r0, #0x3c
	str r0, [r5, #0x50]
	b _02156178
_02155F34:
	ldr r0, [r5, #0x50]
	cmp r0, #0
	bgt _02156178
	mov r0, #2
	strh r0, [r5, #0x4e]
	mov r4, #0
	b _02156178
_02155F50:
	ldr r2, [r5, #0x48]
	mov r4, #0
	ldr r1, [r2, #4]
	bic r1, r1, #0x400
	str r1, [r2, #4]
	bl ov0_02156A8C
	ldr r0, [r5, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02155F8C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, r4
	b _02155F90
_02155F8C:
	mov r0, r4
_02155F90:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _0215618C ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r5, #0x30]
	ldr r0, [r5, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02155FD0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _02155FD4
_02155FD0:
	mov r0, #0
_02155FD4:
	mov r1, r0, asr #4
	ldr r0, _0215618C ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	str r0, [r5, #0x34]
	ldr ip, [r5, #0xc]
	ldr r3, [r5, #0x10]
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]
	sub r2, r1, ip
	sub r1, r0, r3
	str r2, [r5, #0x38]
	str r1, [r5, #0x3c]
	ldr r0, [r5, #0x38]
	str ip, [sp, #0x10]
	smull r7, r6, r0, r0
	smull lr, r0, r1, r1
	mov r7, r7, lsr #0xc
	mov lr, lr, lsr #0xc
	orr r7, r7, r6, lsl #20
	orr lr, lr, r0, lsl #20
	add r0, r7, lr
	str r3, [sp, #0x14]
	str ip, [sp, #8]
	str r3, [sp, #0xc]
	str r2, [sp]
	str r1, [sp, #4]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	bl FX_InvSqrt
	ldr r2, [r5, #0x38]
	mov r1, #3
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r5, #0x38]
	ldr r2, [r5, #0x3c]
	smull r3, r0, r2, r0
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	str r2, [r5, #0x3c]
	ldrh r0, [r5, #0x80]
	strh r0, [r5, #0x4c]
	strh r1, [r5, #0x4e]
	b _02156178
_02156088:
	mov r0, #4
	strh r0, [r5, #0x4e]
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x30]
	mov r4, #0
	bl FX_Atan2Idx
	ldr r2, [r5, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02156178
	bl _ZN6CActor12sub_020128ECEt
	b _02156178
_021560C4:
	ldr r2, [r5, #0x7c]
	add r1, r5, #0x24
	mov r3, #0xa
	mov r4, #0
	bl ov0_02156B30
	cmp r0, #0
	beq _02156178
	mov r0, r5
	mov r1, r4
	bl ov0_021580F8
	mov r0, #5
	strh r0, [r5, #0x4e]
	mov r0, #0x3c
	str r0, [r5, #0x50]
	b _02156178
_02156100:
	ldr r0, [r5, #0x50]
	cmp r0, #0
	bgt _02156178
	ldr r2, [r5, #0x48]
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _02156150
	ldr r0, [r2, #4]
	tst r0, #8
	bne _02156150
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
_02156150:
	ldr r3, [r5, #0x48]
	mov r0, r5
	ldr r2, [r3, #4]
	mov r1, #1
	orr r2, r2, #0x400
	str r2, [r3, #4]
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02156178
_02156170:
	ldr r0, _02156190 ; =s_CFieldPokeMove_Sequence_Exceptio_overlay_0_0217811c
	bl LogError
_02156178:
	ldr r1, [r5, #0x48]
	mov r0, #0
	str r4, [r1, #0x90]
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0215618C: .word FX_SinCosTable_
_02156190: .word s_CFieldPokeMove_Sequence_Exceptio_overlay_0_0217811c

	arm_func_start ov0_02156194
ov0_02156194: ; 0x02156194
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0
	beq _021561BC
	cmp r1, #1
	beq _02156230
	cmp r1, #2
	beq _02156248
	b _02156288
	arm_func_end ov0_02156194
_021561BC:
	mov r1, #4
	mov r2, #0x1e
	bl ov0_021582B4
	mov r0, r4
	mov r1, #0
	bl ov0_021580F8
	mov r0, r4
	bl ov0_0215826C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02156204
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _02156208
	bl _ZN6CActor12sub_02012AFCEv
	b _02156208
_02156204:
	mov r0, #2
_02156208:
	mvn r1, #0
	cmp r0, r1
	movne r0, #2
	strneh r0, [r4, #0x4e]
	bne _02156288
	mov r0, #0x3c
	str r0, [r4, #0x50]
	mov r0, #1
	strh r0, [r4, #0x4e]
	b _02156288
_02156230:
	ldr r1, [r4, #0x50]
	cmp r1, #0
	bgt _02156288
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02156288
_02156248:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02156270
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	beq _02156274
	bl _ZN6CActor12sub_02012AFCEv
	b _02156274
_02156270:
	mov r0, #2
_02156274:
	cmp r0, #0
	bne _02156288
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
_02156288:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start ov0_02156290
ov0_02156290: ; 0x02156290
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0xd0
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0
	beq _021562B4
	cmp r1, #1
	beq _02156538
	b _0215673C
	arm_func_end ov0_02156290
_021562B4:
	bl ov0_02156A8C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021562DC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _021562E0
_021562DC:
	mov r0, #0
_021562E0:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _02156748 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02156320
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _02156324
_02156320:
	mov r0, #0
_02156324:
	mov r1, r0, asr #4
	ldr r0, _02156748 ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	mov r1, #2
	mov r2, #0
	str r0, [r4, #0x34]
	ldr r0, [r4, #0x48]
	ldr r3, [r0]
	ldr r3, [r3, #0x38]
	blx r3
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _021563C4
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021563A4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02156388
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xc0]
	str r0, [sp, #0xc4]
	b _021563BC
_02156388:
	mov r0, #0
	add r1, sp, #0x70
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xc0]
	str r0, [sp, #0xc4]
	b _021563BC
_021563A4:
	mov r0, #0
	add r1, sp, #0x78
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xc0]
	str r0, [sp, #0xc4]
_021563BC:
	add r5, sp, #0xc0
	b _021563E0
_021563C4:
	mov r0, #0
	add r1, sp, #0x68
	add r5, sp, #0xc0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xc0]
	str r0, [sp, #0xc4]
_021563E0:
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r5]
	ldr r0, [r5, #4]
	sub r1, r1, r3
	sub lr, r0, r2
	str r1, [r4, #0x38]
	str lr, [r4, #0x3c]
	ldr r0, [r4, #0x38]
	str r3, [sp, #0xb8]
	smull ip, r6, r0, r0
	smull r5, r0, lr, lr
	mov ip, ip, lsr #0xc
	mov r5, r5, lsr #0xc
	orr ip, ip, r6, lsl #20
	orr r5, r5, r0, lsl #20
	add r0, ip, r5
	str r2, [sp, #0xbc]
	str r3, [sp, #0x88]
	str r2, [sp, #0x8c]
	str r1, [sp, #0x80]
	str lr, [sp, #0x84]
	str r1, [sp, #0xc8]
	str lr, [sp, #0xcc]
	bl FX_InvSqrt
	ldr r1, [r4, #0x38]
	smull r3, r2, r1, r0
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	smull r2, r0, r1, r0
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r4, #0x3c]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _021564E0
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021564C0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021564A4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xb0]
	str r0, [sp, #0xb4]
	b _021564D8
_021564A4:
	mov r0, #0
	add r1, sp, #0x50
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xb0]
	str r0, [sp, #0xb4]
	b _021564D8
_021564C0:
	mov r0, #0
	add r1, sp, #0x58
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xb0]
	str r0, [sp, #0xb4]
_021564D8:
	add r2, sp, #0xb0
	b _021564FC
_021564E0:
	mov r0, #0
	add r1, sp, #0x48
	add r2, sp, #0xb0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xb0]
	str r0, [sp, #0xb4]
_021564FC:
	ldr r6, [r2]
	ldr r5, [r2, #4]
	mov r0, r4
	str r6, [r4, #4]
	str r5, [r4, #8]
	ldrh r3, [r4, #0x80]
	mov r1, #8
	mov r2, #0x3c
	str r6, [sp, #0x60]
	str r5, [sp, #0x64]
	strh r3, [r4, #0x4c]
	bl ov0_021582B4
	mov r0, #1
	strh r0, [r4, #0x4e]
	b _0215673C
_02156538:
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _021565AC
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0215658C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02156570
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xa0]
	str r0, [sp, #0xa4]
	b _021565A4
_02156570:
	mov r0, #0
	add r1, sp, #0x28
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xa0]
	str r0, [sp, #0xa4]
	b _021565A4
_0215658C:
	mov r0, #0
	add r1, sp, #0x30
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xa0]
	str r0, [sp, #0xa4]
_021565A4:
	add r5, sp, #0xa0
	b _021565C8
_021565AC:
	mov r0, #0
	add r1, sp, #0x20
	add r5, sp, #0xa0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xa0]
	str r0, [sp, #0xa4]
_021565C8:
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r5]
	ldr r0, [r5, #4]
	sub r1, r1, r3
	sub r6, r0, r2
	str r1, [r4, #0x38]
	str r6, [r4, #0x3c]
	ldr r0, [r4, #0x38]
	str r3, [sp, #0x98]
	smull r5, lr, r0, r0
	smull ip, r0, r6, r6
	mov r5, r5, lsr #0xc
	mov ip, ip, lsr #0xc
	orr r5, r5, lr, lsl #20
	orr ip, ip, r0, lsl #20
	add r0, r5, ip
	str r2, [sp, #0x9c]
	str r3, [sp, #0x40]
	str r2, [sp, #0x44]
	str r1, [sp, #0x38]
	str r6, [sp, #0x3c]
	str r1, [sp, #0xa8]
	str r6, [sp, #0xac]
	bl FX_InvSqrt
	ldr r1, [r4, #0x38]
	smull r3, r2, r1, r0
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r4, #0x38]
	ldr r1, [r4, #0x3c]
	smull r2, r0, r1, r0
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r4, #0x3c]
	ldr r0, [r4, #0xac]
	cmp r0, #0
	beq _021566C8
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021566A8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0215668C
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x90]
	str r0, [sp, #0x94]
	b _021566C0
_0215668C:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x90]
	str r0, [sp, #0x94]
	b _021566C0
_021566A8:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x90]
	str r0, [sp, #0x94]
_021566C0:
	add r2, sp, #0x90
	b _021566E4
_021566C8:
	mov r0, #0
	add r1, sp, #0
	add r2, sp, #0x90
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x90]
	str r0, [sp, #0x94]
_021566E4:
	ldr lr, [r2]
	ldr ip, [r2, #4]
	mov r0, r4
	str lr, [r4, #4]
	str ip, [r4, #8]
	ldrh r3, [r4, #0x4c]
	add r1, r4, #0x30
	add r2, r4, #0x38
	str lr, [sp, #0x18]
	str ip, [sp, #0x1c]
	bl ov0_02157F0C
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0215673C
	bl _ZN6CActor12sub_020128ECEt
_0215673C:
	mov r0, #0
	add sp, sp, #0xd0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02156748: .word FX_SinCosTable_

	arm_func_start _ZN14CFieldPokeMove12ov0_0215674CEi
_ZN14CFieldPokeMove12ov0_0215674CEi: ; 0x0215674C
	str r1, [r0, #0x44]
	mov r1, #0
	strh r1, [r0, #0x4e]
	bx lr
	arm_func_end _ZN14CFieldPokeMove12ov0_0215674CEi

	arm_func_start ov0_0215675C
ov0_0215675C: ; 0x0215675C
	ldr r3, [r0, #0x48]
	ldr r1, [r3, #8]
	cmp r1, #0
	beq _021567A0
	ldr r1, [r3, #4]
	tst r1, #8
	bne _021567A0
	orr r1, r1, #8
	str r1, [r3, #4]
	ldr r1, [r3, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1dc]
	strneb r1, [r2, #0x1e1]
	mov r1, #0
	str r1, [r3, #0x94]
	arm_func_end ov0_0215675C
_021567A0:
	ldr r1, [r0, #0x68]
	cmp r1, #1
	cmpne r1, #2
	beq _021567BC
	cmp r1, #3
	beq _02156814
	b _0215688C
_021567BC:
	ldrh r2, [r0, #0x9a]
	ldr r3, [r0, #0x2c]
	mov r1, #0xa000
	sub r2, r3, r2
	rsb r1, r1, #0
	str r2, [r0, #0x2c]
	cmp r2, r1
	strlt r1, [r0, #0x2c]
	ldr r2, [r0, #0x14]
	ldr r1, [r0, #0x2c]
	adds r1, r2, r1
	str r1, [r0, #0x14]
	movmi r1, #0
	strmi r1, [r0, #0x14]
	ldr r1, [r0, #0x48]
	ldr r2, [r0, #0x14]
	ldr r0, [r1, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r2, [r0, #0x8c]
	b _0215688C
_02156814:
	ldr r1, [r0, #0x2c]
	ldrh r2, [r0, #0x84]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	mov r3, r1, asr #4
	ldr r1, _02156894 ; =FX_SinCosTable_
	mov r3, r3, lsl #2
	ldrsh r3, [r1, r3]
	mov r1, r2, lsl #0xc
	ldrb ip, [r0, #0xa1]
	smull r2, r1, r3, r1
	adds r2, r2, #0x800
	adc r1, r1, #0
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	add r1, r2, ip, lsl #12
	str r1, [r0, #0x14]
	ldrh r1, [r0, #0x82]
	ldr r2, [r0, #0x2c]
	add r2, r2, r1
	mov r1, r2, lsl #0x10
	mov r1, r1, lsr #0x10
	str r1, [r0, #0x2c]
	ldr r1, [r0, #0x48]
	ldr r2, [r0, #0x14]
	ldr r0, [r1, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r2, [r0, #0x8c]
_0215688C:
	mov r0, #0
	bx lr
	.align 2, 0
_02156894: .word FX_SinCosTable_

	arm_func_start ov0_02156898
ov0_02156898: ; 0x02156898
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x20
	mov r4, r0
	ldrh r1, [r4, #0x4e]
	cmp r1, #0
	beq _021568C4
	cmp r1, #1
	beq _021569E8
	cmp r1, #2
	beq _02156A4C
	b _02156A70
	arm_func_end ov0_02156898
_021568C4:
	bl ov0_02156A8C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021568EC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _021568F0
_021568EC:
	mov r0, #0
_021568F0:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _02156A84 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02156930
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _02156934
_02156930:
	mov r0, #0
_02156934:
	mov r1, r0, asr #4
	ldr r0, _02156A84 ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x34]
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r4, #4]
	ldr r0, [r4, #8]
	sub r1, r1, r3
	sub r6, r0, r2
	str r1, [r4, #0x38]
	str r6, [r4, #0x3c]
	ldr r0, [r4, #0x38]
	str r3, [sp, #0x10]
	smull r5, lr, r0, r0
	smull ip, r0, r6, r6
	mov r5, r5, lsr #0xc
	mov ip, ip, lsr #0xc
	orr r5, r5, lr, lsl #20
	orr ip, ip, r0, lsl #20
	add r0, r5, ip
	str r2, [sp, #0x14]
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp]
	str r6, [sp, #4]
	str r1, [sp, #0x18]
	str r6, [sp, #0x1c]
	bl FX_InvSqrt
	ldr r2, [r4, #0x38]
	mov r1, #1
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r4, #0x38]
	ldr r2, [r4, #0x3c]
	smull r3, r0, r2, r0
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	str r2, [r4, #0x3c]
	ldrh r0, [r4, #0x80]
	strh r0, [r4, #0x4c]
	strh r1, [r4, #0x4e]
	b _02156A78
_021569E8:
	ldrb r1, [r4, #0xa8]
	cmp r1, #0
	bne _02156A14
	ldrh r3, [r4, #0x4c]
	add r1, r4, #0x30
	add r2, r4, #0x38
	bl ov0_02157F0C
	cmp r0, #0
	movne r0, #2
	strneh r0, [r4, #0x4e]
	b _02156A1C
_02156A14:
	mov r0, #2
	strh r0, [r4, #0x4e]
_02156A1C:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02156A78
	bl _ZN6CActor12sub_020128ECEt
	b _02156A78
_02156A4C:
	ldr r2, [r4, #0x78]
	add r1, r4, #0x24
	mvn r3, #0
	bl ov0_02156B30
	movs r1, r0
	beq _02156A78
	mov r0, r4
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02156A78
_02156A70:
	ldr r0, _02156A88 ; =s_CFieldPokeMove_Sequence_Exceptio_overlay_0_02178148
	bl LogError
_02156A78:
	mov r0, #0
	add sp, sp, #0x20
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02156A84: .word FX_SinCosTable_
_02156A88: .word s_CFieldPokeMove_Sequence_Exceptio_overlay_0_02178148

	arm_func_start ov0_02156A8C
ov0_02156A8C: ; 0x02156A8C
	ldr r1, [r0, #0x48]
	ldr r1, [r1, #8]
	cmp r1, #0
	beq _02156AB0
	ldr r1, [r1, #0xc]
	cmp r1, #0
	ldrne r1, [r1, #0x20]
	moveq r1, #0
	b _02156AB4
	arm_func_end ov0_02156A8C
_02156AB0:
	mov r1, #0
_02156AB4:
	str r1, [r0, #0xc]
	ldr r1, [r0, #0x48]
	ldr r1, [r1, #8]
	cmp r1, #0
	beq _02156ADC
	ldr r1, [r1, #0xc]
	cmp r1, #0
	ldrne r1, [r1, #0x24]
	moveq r1, #0
	b _02156AE0
_02156ADC:
	mov r1, #0
_02156AE0:
	str r1, [r0, #0x10]
	ldr r1, [r0, #0x48]
	ldr r1, [r1, #8]
	cmp r1, #0
	beq _02156B08
	ldr r1, [r1, #0xc]
	cmp r1, #0
	ldrne r1, [r1, #0x8c]
	moveq r1, #0
	b _02156B0C
_02156B08:
	mov r1, #0
_02156B0C:
	str r1, [r0, #0x14]
	mov r1, #1
	strh r1, [r0, #0x54]
	mov r1, #0
	str r1, [r0, #0x58]
	str r1, [r0, #0x5c]
	strh r1, [r0, #0x60]
	str r1, [r0, #0x40]
	bx lr

	arm_func_start ov0_02156B30
ov0_02156B30: ; 0x02156B30
	stmdb sp!, {r3, lr}
	mvn ip, #0
	cmp r3, ip
	ldreq r3, [r0, #0x68]
	cmp r3, #0xa
	addls pc, pc, r3, lsl #2
	b _02156BB8
_02156B4C: ; jump table
	b _02156B80 ; case 0
	b _02156B90 ; case 1
	b _02156B98 ; case 2
	b _02156BA0 ; case 3
	b _02156BA8 ; case 4
	b _02156B78 ; case 5
	b _02156BB8 ; case 6
	b _02156BB8 ; case 7
	b _02156BB8 ; case 8
	b _02156B88 ; case 9
	b _02156BB0 ; case 10
	arm_func_end ov0_02156B30
_02156B78:
	bl ov0_02156BC0
	ldmia sp!, {r3, pc}
_02156B80:
	bl ov0_02156BE4
	ldmia sp!, {r3, pc}
_02156B88:
	bl ov0_02156BE4
	ldmia sp!, {r3, pc}
_02156B90:
	bl ov0_02156E68
	ldmia sp!, {r3, pc}
_02156B98:
	bl ov0_021572F4
	ldmia sp!, {r3, pc}
_02156BA0:
	bl ov0_02157764
	ldmia sp!, {r3, pc}
_02156BA8:
	bl ov0_02157A70
	ldmia sp!, {r3, pc}
_02156BB0:
	bl ov0_02157CF4
	ldmia sp!, {r3, pc}
_02156BB8:
	bl ov0_02156BE4
	ldmia sp!, {r3, pc}

	arm_func_start ov0_02156BC0
ov0_02156BC0: ; 0x02156BC0
	stmdb sp!, {r3, lr}
	ldrh r1, [r0, #0x54]
	cmp r1, #0
	subne r1, r1, #1
	strneh r1, [r0, #0x54]
	mov r1, #6
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end ov0_02156BC0

	arm_func_start ov0_02156BE4
ov0_02156BE4: ; 0x02156BE4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x3c
	mov r5, r2
	mov r6, r1
	mov r1, r5
	mov r7, r0
	mov r4, #0
	bl ov0_02158B34
	cmp r0, #0
	movne r0, #1
	strne r0, [r7, #0x58]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	beq _02156C84
	sub r0, r0, #1
	strh r0, [r7, #0x54]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	bne _02156C84
	ldr r1, [r7, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02156C6C
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02156C6C
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
	arm_func_end ov0_02156BE4
_02156C6C:
	ldr r0, [r7, #0x48]
	mov r1, #4
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
_02156C84:
	ldr ip, [r7, #0xc]
	ldr r3, [r7, #0x10]
	ldr r1, [r7, #4]
	ldr r0, [r7, #8]
	sub r2, r1, ip
	sub r1, r0, r3
	str r2, [r7, #0x38]
	str r1, [r7, #0x3c]
	ldr r0, [r7, #0x38]
	str ip, [sp, #0x10]
	smull sb, r8, r0, r0
	smull lr, r0, r1, r1
	mov sb, sb, lsr #0xc
	mov lr, lr, lsr #0xc
	orr sb, sb, r8, lsl #20
	orr lr, lr, r0, lsl #20
	add r0, sb, lr
	str r3, [sp, #0x14]
	str ip, [sp, #8]
	str r3, [sp, #0xc]
	str r2, [sp]
	str r1, [sp, #4]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	bl FX_InvSqrt
	ldr r2, [r7, #0x38]
	add r1, r7, #0x30
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r7, #0x38]
	ldr r3, [r7, #0x3c]
	add r2, r7, #0x38
	smull ip, r0, r3, r0
	mov r3, ip, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r7, #0x3c]
	ldrh r3, [r7, #0x4c]
	mov r0, r7
	bl ov0_02157F0C
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [r7, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02156D50
	bl _ZN6CActor12sub_020128ECEt
_02156D50:
	ldr r0, [r7, #0x30]
	smull r2, r1, r0, r5
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r6]
	ldr r0, [r7, #0x34]
	smull r2, r1, r0, r5
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r6, #4]
	ldr r1, [r7, #0xc]
	ldr r0, [r6]
	add r0, r1, r0
	str r0, [r7, #0x18]
	ldr r1, [r7, #0x10]
	ldr r0, [r6, #4]
	add r0, r1, r0
	str r0, [r7, #0x1c]
	ldr r0, [r7, #0xc]
	str r0, [sp, #0x2c]
	ldr r0, [r7, #0x10]
	str r0, [sp, #0x30]
	ldr r0, [r7, #0x18]
	str r0, [sp, #0x34]
	ldr r0, [r7, #0x1c]
	str r0, [sp, #0x38]
	ldr r0, [r7, #0xbc]
	ldr r3, [r7, #0xb4]
	cmp r0, #0
	ldr r2, [r7, #0x64]
	moveq r0, #0
	beq _02156DDC
	ldr r0, [r7, #0x48]
	add r1, sp, #0x2c
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
_02156DDC:
	cmp r0, #0
	beq _02156DF4
	mov r0, #1
	str r0, [r7, #0x58]
	str r0, [r7, #0x5c]
	b _02156E50
_02156DF4:
	ldr r0, [r7, #0x48]
	ldr r6, [r7, #0x1c]
	ldr r8, [r0, #8]
	ldr r5, [r7, #0x18]
	cmp r8, #0
	ldrne sb, [r8, #0xc]
	cmpne sb, #0
	beq _02156E40
	mov r1, r5
	add r0, sb, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r6
	add r0, sb, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r8, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r5, [r0, #0x18]
	strne r6, [r0, #0x1c]
_02156E40:
	add r0, sp, #0x20
	add r1, r7, #0xc
	add r2, r7, #0x18
	bl ov0_02155538
_02156E50:
	ldr r0, [r7, #0x58]
	cmp r0, #0
	movne r4, #1
	mov r0, r4
	add sp, sp, #0x3c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

	arm_func_start ov0_02156E68
ov0_02156E68: ; 0x02156E68
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x74
	mov r8, r0
	ldrh r0, [r8, #0x54]
	mov r7, r1
	mov r6, r2
	cmp r0, #0
	mov r4, #0
	beq _02156FD4
	sub r0, r0, #1
	strh r0, [r8, #0x54]
	ldrh r0, [r8, #0x54]
	cmp r0, #0
	bne _02156FD4
	ldr r1, [r8, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02156ED4
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #3
	strne r0, [r1, #0x1dc]
	strneb r4, [r1, #0x1e1]
	arm_func_end ov0_02156E68
_02156ED4:
	ldr r0, [r8, #0x48]
	mov r1, #4
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	ldr r5, [r8, #0xc]
	ldr r3, [r8, #0x10]
	ldr r1, [r8, #4]
	ldr r0, [r8, #8]
	sub r2, r1, r5
	sub r1, r0, r3
	str r2, [r8, #0x38]
	str r1, [r8, #0x3c]
	ldr r0, [r8, #0x38]
	str r5, [sp, #0x30]
	smull sl, sb, r0, r0
	smull r6, r0, r1, r1
	mov sl, sl, lsr #0xc
	mov r6, r6, lsr #0xc
	orr sl, sl, sb, lsl #20
	orr r6, r6, r0, lsl #20
	add r0, sl, r6
	str r5, [sp, #0x18]
	str r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	str r2, [sp, #0x38]
	str r1, [sp, #0x3c]
	bl FX_InvSqrt
	ldr r2, [r8, #0x38]
	add r1, r8, #0x30
	smull r5, r3, r2, r0
	mov r2, r5, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r8, #0x38]
	ldr r3, [r8, #0x3c]
	add r2, r8, #0x38
	smull r5, r0, r3, r0
	mov r3, r5, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r8, #0x3c]
	ldrh r3, [r8, #0x4c]
	mov r0, r8
	bl ov0_02157F0C
	ldr r0, [r8, #0x34]
	ldr r1, [r8, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [r8, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02156FB8
	bl _ZN6CActor12sub_020128ECEt
_02156FB8:
	ldr r0, [r8, #0x14]
	cmp r0, #0
	bne _021572B4
	ldrh r0, [r8, #0x98]
	mov r0, r0, lsl #0xc
	str r0, [r7, #8]
	b _021572B4
_02156FD4:
	cmp r0, #0
	bne _021572B4
	ldr r0, [r8, #0x30]
	mov r5, r6, asr #0x1f
	smull r2, r1, r0, r6
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7]
	ldr r0, [r8, #0x34]
	smull r2, r1, r0, r6
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7, #4]
	ldr r0, [r8, #0x48]
	ldr r0, [r0, #0x58]
	mov r0, r0, asr #0x18
	and r0, r0, #0xff
	cmp r0, #6
	bne _0215712C
	ldr lr, [r8, #0xc]
	ldr ip, [r8, #0x10]
	ldr r1, [r8, #4]
	ldr r0, [r8, #8]
	sub r3, r1, lr
	sub r2, r0, ip
	str r3, [r8, #0x38]
	str r2, [r8, #0x3c]
	ldr sb, [r8, #0x38]
	str lr, [sp, #0x20]
	smull r1, r0, sb, sb
	smull sl, sb, r2, r2
	mov r1, r1, lsr #0xc
	mov sl, sl, lsr #0xc
	orr r1, r1, r0, lsl #20
	orr sl, sl, sb, lsl #20
	add r0, r1, sl
	str ip, [sp, #0x24]
	str lr, [sp, #8]
	str ip, [sp, #0xc]
	str r3, [sp]
	str r2, [sp, #4]
	str r3, [sp, #0x28]
	str r2, [sp, #0x2c]
	bl FX_InvSqrt
	ldr r2, [r8, #0x38]
	add r1, r8, #0x30
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r8, #0x38]
	ldr r3, [r8, #0x3c]
	add r2, r8, #0x38
	smull ip, r0, r3, r0
	mov r3, ip, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r8, #0x3c]
	ldrh r3, [r8, #0x4c]
	mov r0, r8
	bl ov0_02157F0C
	ldr r0, [r8, #0x34]
	ldr r1, [r8, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [r8, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021570EC
	bl _ZN6CActor12sub_020128ECEt
_021570EC:
	ldr r0, [r8, #0x30]
	umull r2, r1, r0, r6
	mla r1, r0, r5, r1
	mov r0, r0, asr #0x1f
	mla r1, r0, r6, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7]
	ldr r0, [r8, #0x34]
	umull r2, r1, r0, r6
	mla r1, r0, r5, r1
	mov r0, r0, asr #0x1f
	mla r1, r0, r6, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7, #4]
_0215712C:
	ldrh r1, [r8, #0x9a]
	ldr r2, [r7, #8]
	mov r0, #0xa000
	sub r1, r2, r1
	str r1, [r7, #8]
	ldr r1, [r8, #0x2c]
	rsb r0, r0, #0
	cmp r1, r0
	strlt r0, [r8, #0x2c]
	add r0, sp, #0x58
	mov r2, r7
	add r1, r8, #0xc
	bl ov0_021572C0
	add r0, sp, #0x4c
	add r2, sp, #0x58
	add r1, r8, #0x18
	bl ov0_02155538
	ldr r0, [r8, #0x20]
	cmp r0, #0
	bge _0215718C
	mov r0, #0xa
	strh r0, [r8, #0x54]
	mov r0, #0
	str r0, [r8, #0x20]
_0215718C:
	ldr r0, [r8, #0xc]
	str r0, [sp, #0x64]
	ldr r0, [r8, #0x10]
	str r0, [sp, #0x68]
	ldr r0, [r8, #0x18]
	str r0, [sp, #0x6c]
	ldr r0, [r8, #0x1c]
	str r0, [sp, #0x70]
	ldr r0, [r8, #0xbc]
	ldr r3, [r8, #0xb4]
	cmp r0, #0
	ldr r2, [r8, #0x64]
	moveq r0, #0
	beq _021571D0
	ldr r0, [r8, #0x48]
	add r1, sp, #0x64
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
_021571D0:
	cmp r0, #0
	beq _0215720C
	mov r0, #1
	str r0, [r8, #0x5c]
	str r0, [r8, #0x58]
	ldr r0, [r8, #0x20]
	str r0, [r8, #0x14]
	ldr r0, [r8, #0x48]
	ldr r1, [r8, #0x20]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	b _02157284
_0215720C:
	ldr r0, [r8, #0x48]
	ldr r5, [r8, #0x1c]
	ldr sb, [r0, #8]
	ldr r7, [r8, #0x18]
	cmp sb, #0
	ldrne sl, [sb, #0xc]
	cmpne sl, #0
	beq _02157258
	mov r1, r7
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r5
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r7, [r0, #0x18]
	strne r5, [r0, #0x1c]
_02157258:
	ldr r0, [r8, #0x48]
	ldr r1, [r8, #0x20]
	ldr r0, [r0, #8]
	add r2, r8, #0x18
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	add r0, sp, #0x40
	add r1, r8, #0xc
	bl ov0_02155538
_02157284:
	mov r0, r8
	mov r1, r6
	bl ov0_02158B34
	cmp r0, #0
	movne r0, #1
	strne r0, [r8, #0x58]
	ldr r0, [r8, #0x58]
	cmp r0, #0
	beq _021572B4
	ldr r0, [r8, #0x14]
	cmp r0, #0
	moveq r4, #1
_021572B4:
	mov r0, r4
	add sp, sp, #0x74
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start ov0_021572C0
ov0_021572C0: ; 0x021572C0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r3, [r2]
	ldr r4, [r2, #8]
	ldr r5, [r1, #8]
	ldmia r1, {ip, lr}
	ldr r2, [r2, #4]
	add r1, ip, r3
	str r1, [r0]
	add r1, lr, r2
	str r1, [r0, #4]
	add r1, r5, r4
	str r1, [r0, #8]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov0_021572C0

	arm_func_start ov0_021572F4
ov0_021572F4: ; 0x021572F4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x74
	mov r8, r0
	ldrh r0, [r8, #0x54]
	mov r7, r1
	mov r6, r2
	cmp r0, #0
	mov r4, #0
	beq _02157460
	sub r0, r0, #1
	strh r0, [r8, #0x54]
	ldrh r0, [r8, #0x54]
	cmp r0, #0
	bne _02157460
	ldr r1, [r8, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02157360
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #3
	strne r0, [r1, #0x1dc]
	strneb r4, [r1, #0x1e1]
	arm_func_end ov0_021572F4
_02157360:
	ldr r0, [r8, #0x48]
	mov r1, #4
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	ldr r5, [r8, #0xc]
	ldr r3, [r8, #0x10]
	ldr r1, [r8, #4]
	ldr r0, [r8, #8]
	sub r2, r1, r5
	sub r1, r0, r3
	str r2, [r8, #0x38]
	str r1, [r8, #0x3c]
	ldr r0, [r8, #0x38]
	str r5, [sp, #0x30]
	smull sl, sb, r0, r0
	smull r6, r0, r1, r1
	mov sl, sl, lsr #0xc
	mov r6, r6, lsr #0xc
	orr sl, sl, sb, lsl #20
	orr r6, r6, r0, lsl #20
	add r0, sl, r6
	str r5, [sp, #0x18]
	str r3, [sp, #0x34]
	str r3, [sp, #0x1c]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	str r2, [sp, #0x38]
	str r1, [sp, #0x3c]
	bl FX_InvSqrt
	ldr r2, [r8, #0x38]
	add r1, r8, #0x30
	smull r5, r3, r2, r0
	mov r2, r5, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r8, #0x38]
	ldr r3, [r8, #0x3c]
	add r2, r8, #0x38
	smull r5, r0, r3, r0
	mov r3, r5, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r8, #0x3c]
	ldrh r3, [r8, #0x4c]
	mov r0, r8
	bl ov0_02157F0C
	ldr r0, [r8, #0x34]
	ldr r1, [r8, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [r8, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02157444
	bl _ZN6CActor12sub_020128ECEt
_02157444:
	ldr r0, [r8, #0x14]
	cmp r0, #0
	bne _02157758
	ldrh r0, [r8, #0x98]
	mov r0, r0, lsl #0xc
	str r0, [r7, #8]
	b _02157758
_02157460:
	cmp r0, #0
	bne _02157758
	ldr r0, [r8, #0x30]
	mov r5, r6, asr #0x1f
	smull r2, r1, r0, r6
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7]
	ldr r0, [r8, #0x34]
	smull r2, r1, r0, r6
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7, #4]
	ldr r0, [r8, #0x48]
	ldr r0, [r0, #0x58]
	mov r0, r0, asr #0x18
	and r0, r0, #0xff
	cmp r0, #6
	bne _021575B8
	ldr lr, [r8, #0xc]
	ldr ip, [r8, #0x10]
	ldr r1, [r8, #4]
	ldr r0, [r8, #8]
	sub r3, r1, lr
	sub r2, r0, ip
	str r3, [r8, #0x38]
	str r2, [r8, #0x3c]
	ldr sb, [r8, #0x38]
	str lr, [sp, #0x20]
	smull r1, r0, sb, sb
	smull sl, sb, r2, r2
	mov r1, r1, lsr #0xc
	mov sl, sl, lsr #0xc
	orr r1, r1, r0, lsl #20
	orr sl, sl, sb, lsl #20
	add r0, r1, sl
	str ip, [sp, #0x24]
	str lr, [sp, #8]
	str ip, [sp, #0xc]
	str r3, [sp]
	str r2, [sp, #4]
	str r3, [sp, #0x28]
	str r2, [sp, #0x2c]
	bl FX_InvSqrt
	ldr r2, [r8, #0x38]
	add r1, r8, #0x30
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r8, #0x38]
	ldr r3, [r8, #0x3c]
	add r2, r8, #0x38
	smull ip, r0, r3, r0
	mov r3, ip, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r8, #0x3c]
	ldrh r3, [r8, #0x4c]
	mov r0, r8
	bl ov0_02157F0C
	ldr r0, [r8, #0x34]
	ldr r1, [r8, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [r8, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02157578
	bl _ZN6CActor12sub_020128ECEt
_02157578:
	ldr r0, [r8, #0x30]
	umull r2, r1, r0, r6
	mla r1, r0, r5, r1
	mov r0, r0, asr #0x1f
	mla r1, r0, r6, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7]
	ldr r0, [r8, #0x34]
	umull r2, r1, r0, r6
	mla r1, r0, r5, r1
	mov r0, r0, asr #0x1f
	mla r1, r0, r6, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r7, #4]
_021575B8:
	ldrh r1, [r8, #0x9a]
	ldr r2, [r7, #8]
	mov r0, #0x64000
	sub r1, r2, r1
	str r1, [r7, #8]
	ldr r1, [r8, #0x2c]
	rsb r0, r0, #0
	cmp r1, r0
	strlt r0, [r8, #0x2c]
	add r0, sp, #0x58
	mov r2, r7
	add r1, r8, #0xc
	bl ov0_021572C0
	add r0, sp, #0x4c
	add r2, sp, #0x58
	add r1, r8, #0x18
	bl ov0_02155538
	ldr r0, [r8, #0x20]
	cmp r0, #0
	bge _02157630
	ldr r0, [r8, #0x48]
	mov r1, #2
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0x1e
	strh r0, [r8, #0x54]
	mov r0, #0
	str r0, [r8, #0x20]
_02157630:
	ldr r0, [r8, #0xc]
	str r0, [sp, #0x64]
	ldr r0, [r8, #0x10]
	str r0, [sp, #0x68]
	ldr r0, [r8, #0x18]
	str r0, [sp, #0x6c]
	ldr r0, [r8, #0x1c]
	str r0, [sp, #0x70]
	ldr r0, [r8, #0xbc]
	ldr r3, [r8, #0xb4]
	cmp r0, #0
	ldr r2, [r8, #0x64]
	moveq r0, #0
	beq _02157674
	ldr r0, [r8, #0x48]
	add r1, sp, #0x64
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
_02157674:
	cmp r0, #0
	beq _021576B0
	mov r0, #1
	str r0, [r8, #0x5c]
	str r0, [r8, #0x58]
	ldr r0, [r8, #0x20]
	str r0, [r8, #0x14]
	ldr r0, [r8, #0x48]
	ldr r1, [r8, #0x20]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	b _02157728
_021576B0:
	ldr r0, [r8, #0x48]
	ldr r5, [r8, #0x1c]
	ldr sb, [r0, #8]
	ldr r7, [r8, #0x18]
	cmp sb, #0
	ldrne sl, [sb, #0xc]
	cmpne sl, #0
	beq _021576FC
	mov r1, r7
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r5
	add r0, sl, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r7, [r0, #0x18]
	strne r5, [r0, #0x1c]
_021576FC:
	ldr r0, [r8, #0x48]
	ldr r1, [r8, #0x20]
	ldr r0, [r0, #8]
	add r2, r8, #0x18
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	add r0, sp, #0x40
	add r1, r8, #0xc
	bl ov0_02155538
_02157728:
	mov r0, r8
	mov r1, r6
	bl ov0_02158B34
	cmp r0, #0
	movne r0, #1
	strne r0, [r8, #0x58]
	ldr r0, [r8, #0x58]
	cmp r0, #0
	beq _02157758
	ldr r0, [r8, #0x14]
	cmp r0, #0
	moveq r4, #1
_02157758:
	mov r0, r4
	add sp, sp, #0x74
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start ov0_02157764
ov0_02157764: ; 0x02157764
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x3c
	mov r7, r0
	ldr r3, [r7, #0xb4]
	mov r5, r2
	mov r6, r1
	orr r2, r3, #2
	mov r1, r5
	str r2, [r7, #0xb4]
	mov r4, #0
	bl ov0_02158B34
	cmp r0, #0
	movne r0, #1
	strne r0, [r7, #0x58]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	beq _02157810
	sub r0, r0, #1
	strh r0, [r7, #0x54]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	bne _02157810
	ldr r1, [r7, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _021577F8
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _021577F8
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
	arm_func_end ov0_02157764
_021577F8:
	ldr r0, [r7, #0x48]
	mov r1, #4
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
_02157810:
	ldr ip, [r7, #0xc]
	ldr r3, [r7, #0x10]
	ldr r1, [r7, #4]
	ldr r0, [r7, #8]
	sub r2, r1, ip
	sub r1, r0, r3
	str r2, [r7, #0x38]
	str r1, [r7, #0x3c]
	ldr r0, [r7, #0x38]
	str ip, [sp, #0x10]
	smull sb, r8, r0, r0
	smull lr, r0, r1, r1
	mov sb, sb, lsr #0xc
	mov lr, lr, lsr #0xc
	orr sb, sb, r8, lsl #20
	orr lr, lr, r0, lsl #20
	add r0, sb, lr
	str r3, [sp, #0x14]
	str ip, [sp, #8]
	str r3, [sp, #0xc]
	str r2, [sp]
	str r1, [sp, #4]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	bl FX_InvSqrt
	ldr r2, [r7, #0x38]
	add r1, r7, #0x30
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r7, #0x38]
	ldr r3, [r7, #0x3c]
	add r2, r7, #0x38
	smull ip, r0, r3, r0
	mov r3, ip, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r7, #0x3c]
	ldrh r3, [r7, #0x4c]
	mov r0, r7
	bl ov0_02157F0C
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [r7, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021578DC
	bl _ZN6CActor12sub_020128ECEt
_021578DC:
	ldr r0, [r7, #0x30]
	smull r2, r1, r0, r5
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r6]
	ldr r0, [r7, #0x34]
	smull r2, r1, r0, r5
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r6, #4]
	ldr r1, [r7, #0xc]
	ldr r0, [r6]
	add r0, r1, r0
	str r0, [r7, #0x18]
	ldr r1, [r7, #0x10]
	ldr r0, [r6, #4]
	add r0, r1, r0
	str r0, [r7, #0x1c]
	ldr r0, [r7, #0xc]
	str r0, [sp, #0x2c]
	ldr r0, [r7, #0x10]
	str r0, [sp, #0x30]
	ldr r0, [r7, #0x18]
	str r0, [sp, #0x34]
	ldr r0, [r7, #0x1c]
	str r0, [sp, #0x38]
	ldr r0, [r7, #0xbc]
	ldr r3, [r7, #0xb4]
	cmp r0, #0
	ldr r2, [r7, #0x64]
	moveq r0, #0
	beq _02157968
	ldr r0, [r7, #0x48]
	add r1, sp, #0x2c
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
_02157968:
	cmp r0, #0
	beq _02157980
	mov r0, #1
	str r0, [r7, #0x58]
	str r0, [r7, #0x5c]
	b _021579DC
_02157980:
	ldr r0, [r7, #0x48]
	ldr r6, [r7, #0x1c]
	ldr r8, [r0, #8]
	ldr r5, [r7, #0x18]
	cmp r8, #0
	ldrne sb, [r8, #0xc]
	cmpne sb, #0
	beq _021579CC
	mov r1, r5
	add r0, sb, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r6
	add r0, sb, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r8, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r5, [r0, #0x18]
	strne r6, [r0, #0x1c]
_021579CC:
	add r0, sp, #0x20
	add r1, r7, #0xc
	add r2, r7, #0x18
	bl ov0_02155538
_021579DC:
	ldr r0, [r7, #0x2c]
	ldrh r1, [r7, #0x84]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r2, r0, asr #4
	ldr r0, _02157A6C ; =FX_SinCosTable_
	mov r2, r2, lsl #2
	ldrsh r2, [r0, r2]
	mov r0, r1, lsl #0xc
	ldrb r3, [r7, #0xa1]
	smull r1, r0, r2, r0
	adds r1, r1, #0x800
	adc r0, r0, #0
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	add r0, r1, r3, lsl #12
	str r0, [r7, #0x14]
	ldrh r0, [r7, #0x82]
	ldr r1, [r7, #0x2c]
	add r1, r1, r0
	mov r0, r1, lsl #0x10
	mov r0, r0, lsr #0x10
	str r0, [r7, #0x2c]
	ldr r0, [r7, #0x48]
	ldr r1, [r7, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	ldr r0, [r7, #0x58]
	cmp r0, #0
	movne r4, #1
	mov r0, r4
	add sp, sp, #0x3c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02157A6C: .word FX_SinCosTable_

	arm_func_start ov0_02157A70
ov0_02157A70: ; 0x02157A70
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x3c
	mov r5, r2
	mov r6, r1
	mov r1, r5
	mov r7, r0
	mov r4, #0
	bl ov0_02158B34
	cmp r0, #0
	movne r0, #1
	strne r0, [r7, #0x58]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	beq _02157B10
	sub r0, r0, #1
	strh r0, [r7, #0x54]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	bne _02157B10
	ldr r1, [r7, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02157AF8
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02157AF8
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
	arm_func_end ov0_02157A70
_02157AF8:
	ldr r0, [r7, #0x48]
	mov r1, #4
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
_02157B10:
	ldr ip, [r7, #0xc]
	ldr r3, [r7, #0x10]
	ldr r1, [r7, #4]
	ldr r0, [r7, #8]
	sub r2, r1, ip
	sub r1, r0, r3
	str r2, [r7, #0x38]
	str r1, [r7, #0x3c]
	ldr r0, [r7, #0x38]
	str ip, [sp, #0x10]
	smull sb, r8, r0, r0
	smull lr, r0, r1, r1
	mov sb, sb, lsr #0xc
	mov lr, lr, lsr #0xc
	orr sb, sb, r8, lsl #20
	orr lr, lr, r0, lsl #20
	add r0, sb, lr
	str r3, [sp, #0x14]
	str ip, [sp, #8]
	str r3, [sp, #0xc]
	str r2, [sp]
	str r1, [sp, #4]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	bl FX_InvSqrt
	ldr r2, [r7, #0x38]
	add r1, r7, #0x30
	smull ip, r3, r2, r0
	mov r2, ip, lsr #0xc
	orr r2, r2, r3, lsl #20
	str r2, [r7, #0x38]
	ldr r3, [r7, #0x3c]
	add r2, r7, #0x38
	smull ip, r0, r3, r0
	mov r3, ip, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r7, #0x3c]
	ldrh r3, [r7, #0x4c]
	mov r0, r7
	bl ov0_02157F0C
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [r7, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02157BDC
	bl _ZN6CActor12sub_020128ECEt
_02157BDC:
	ldr r0, [r7, #0x30]
	smull r2, r1, r0, r5
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r6]
	ldr r0, [r7, #0x34]
	smull r2, r1, r0, r5
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r6, #4]
	ldr r1, [r7, #0xc]
	ldr r0, [r6]
	add r0, r1, r0
	str r0, [r7, #0x18]
	ldr r1, [r7, #0x10]
	ldr r0, [r6, #4]
	add r0, r1, r0
	str r0, [r7, #0x1c]
	ldr r0, [r7, #0xc]
	str r0, [sp, #0x2c]
	ldr r0, [r7, #0x10]
	str r0, [sp, #0x30]
	ldr r0, [r7, #0x18]
	str r0, [sp, #0x34]
	ldr r0, [r7, #0x1c]
	str r0, [sp, #0x38]
	ldr r0, [r7, #0xbc]
	ldr r3, [r7, #0xb4]
	cmp r0, #0
	ldr r2, [r7, #0x64]
	moveq r0, #0
	beq _02157C68
	ldr r0, [r7, #0x48]
	add r1, sp, #0x2c
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
_02157C68:
	cmp r0, #0
	beq _02157C80
	mov r0, #1
	str r0, [r7, #0x58]
	str r0, [r7, #0x5c]
	b _02157CDC
_02157C80:
	ldr r0, [r7, #0x48]
	ldr r6, [r7, #0x1c]
	ldr r8, [r0, #8]
	ldr r5, [r7, #0x18]
	cmp r8, #0
	ldrne sb, [r8, #0xc]
	cmpne sb, #0
	beq _02157CCC
	mov r1, r5
	add r0, sb, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r6
	add r0, sb, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r8, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r5, [r0, #0x18]
	strne r6, [r0, #0x1c]
_02157CCC:
	add r0, sp, #0x20
	add r1, r7, #0xc
	add r2, r7, #0x18
	bl ov0_02155538
_02157CDC:
	ldr r0, [r7, #0x58]
	cmp r0, #0
	movne r4, #1
	mov r0, r4
	add sp, sp, #0x3c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

	arm_func_start ov0_02157CF4
ov0_02157CF4: ; 0x02157CF4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x2c
	mov r7, r2
	mov r8, r1
	mov r1, r7
	mov sb, r0
	mov r6, #0
	bl ov0_02158B34
	cmp r0, #0
	movne r0, #1
	strne r0, [sb, #0x58]
	ldrh r0, [sb, #0x54]
	cmp r0, #0
	beq _02157D7C
	sub r0, r0, #1
	strh r0, [sb, #0x54]
	ldrh r0, [sb, #0x54]
	cmp r0, #0
	bne _02157D7C
	ldr r1, [sb, #0x48]
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02157D7C
	ldr r0, [r1, #4]
	bic r0, r0, #8
	str r0, [r1, #4]
	ldr r0, [r1, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02157D7C
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
	arm_func_end ov0_02157CF4
_02157D7C:
	ldr r4, [sb, #0xc]
	ldr r3, [sb, #0x10]
	ldr r1, [sb, #4]
	ldr r0, [sb, #8]
	sub r2, r1, r4
	sub r1, r0, r3
	str r2, [sb, #0x38]
	str r1, [sb, #0x3c]
	ldr r0, [sb, #0x38]
	str r4, [sp, #0x10]
	str r3, [sp, #0x14]
	str r4, [sp, #8]
	str r3, [sp, #0xc]
	str r2, [sp]
	str r1, [sp, #4]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	bl _Z12sub_02007254ll
	mov r5, r0
	ldr ip, [sb, #0x38]
	mov r4, r5, asr #0x1f
	mov r0, ip, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, r5
	mov r3, r4
	orr r1, r1, ip, lsr #20
	mov r0, ip, lsl #0xc
	bl _ll_div
	str r0, [sb, #0x38]
	mov r3, r4
	ldr r4, [sb, #0x3c]
	mov r2, r5
	mov r0, r4, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r4, lsr #20
	mov r0, r4, lsl #0xc
	bl _ll_div
	str r0, [sb, #0x3c]
	ldrh r3, [sb, #0x4c]
	mov r0, sb
	add r1, sb, #0x30
	add r2, sb, #0x38
	bl ov0_02157F0C
	ldr r0, [sb, #0x34]
	ldr r1, [sb, #0x30]
	bl FX_Atan2Idx
	mov r1, r0
	ldr r0, [sb, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02157E54
	bl _ZN6CActor12sub_020128ECEt
_02157E54:
	ldr r0, [sb, #0x30]
	smull r2, r1, r0, r7
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r8]
	ldr r0, [sb, #0x34]
	smull r2, r1, r0, r7
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	str r0, [r8, #4]
	ldr r1, [sb, #0xc]
	ldr r0, [r8]
	add r0, r1, r0
	str r0, [sb, #0x18]
	ldr r1, [sb, #0x10]
	ldr r0, [r8, #4]
	add r5, r1, r0
	str r5, [sb, #0x1c]
	ldr r0, [sb, #0x48]
	ldr r4, [sb, #0x18]
	ldr r7, [r0, #8]
	cmp r7, #0
	ldrne r8, [r7, #0xc]
	cmpne r8, #0
	beq _02157EE4
	mov r1, r4
	add r0, r8, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r5
	add r0, r8, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r7, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r4, [r0, #0x18]
	strne r5, [r0, #0x1c]
_02157EE4:
	add r0, sp, #0x20
	add r1, sb, #0xc
	add r2, sb, #0x18
	bl ov0_02155538
	ldr r0, [sb, #0x58]
	cmp r0, #0
	movne r6, #1
	mov r0, r6
	add sp, sp, #0x2c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

	arm_func_start ov0_02157F0C
ov0_02157F0C: ; 0x02157F0C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r5, r2
	ldr r2, [r5]
	mov r7, r0
	cmp r2, #0
	ldreq r0, [r5, #4]
	mov r6, r1
	cmpeq r0, #0
	mov r4, r3
	moveq r0, #1
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r0, r6
	mov r1, r5
	bl _Z12sub_020072C4P7Point2DS0_
	mov r1, r4, asr #4
	mov r4, r1, lsl #1
	add r2, r4, #1
	ldr r1, _0215806C ; =FX_SinCosTable_
	mov r2, r2, lsl #1
	ldrsh r1, [r1, r2]
	add r0, r0, #0x64
	cmp r1, r0
	bge _02157F80
	ldr r1, [r5]
	mov r0, #1
	str r1, [r6]
	ldr r1, [r5, #4]
	str r1, [r6, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	arm_func_end ov0_02157F0C
_02157F80:
	mov r0, r6
	mov r1, r5
	bl _Z12sub_020072F8P7Point2DS0_
	cmp r0, #0
	blt _02157FEC
	add r0, r4, #1
	ldr r1, _0215806C ; =FX_SinCosTable_
	mov r2, r4, lsl #1
	mov r0, r0, lsl #1
	ldrsh r2, [r1, r2]
	ldrsh r1, [r1, r0]
	ldr ip, [r6, #4]
	ldr r0, [r6]
	smull r5, r4, ip, r2
	smull sb, r8, r0, r1
	smull r3, r2, r0, r2
	smull r1, r0, ip, r1
	mov sb, sb, lsr #0xc
	mov r5, r5, lsr #0xc
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr sb, sb, r8, lsl #20
	orr r5, r5, r4, lsl #20
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	sub r4, sb, r5
	b _02158040
_02157FEC:
	ldr r1, _0215806C ; =FX_SinCosTable_
	mov r2, r4, lsl #1
	add r0, r4, #1
	mov r0, r0, lsl #1
	ldrsh r2, [r1, r2]
	ldrsh sb, [r1, r0]
	ldmia r6, {r1, r8}
	rsb r0, r2, #0
	smull lr, ip, r1, sb
	smull r5, r4, r8, r0
	smull r3, r2, r1, r0
	smull r1, r0, r8, sb
	mov lr, lr, lsr #0xc
	mov r5, r5, lsr #0xc
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr lr, lr, ip, lsl #20
	orr r5, r5, r4, lsl #20
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	sub r4, lr, r5
_02158040:
	add r5, r3, r1
	mov r0, r7
	mov r1, r4
	mov r2, r5
	bl ov0_021580D0
	ldmia r6, {r1, r2}
	mov r0, r7
	bl ov0_021580D0
	stmia r6, {r4, r5}
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0215806C: .word FX_SinCosTable_

	arm_func_start ov0_02158070
ov0_02158070: ; 0x02158070
	ldr r2, [r0, #8]
	ldr r1, [r0, #0x10]
	ldr r3, [r0, #4]
	sub r1, r2, r1
	mov r2, r1, asr #0xc
	mul r1, r2, r2
	ldr r0, [r0, #0xc]
	sub r0, r3, r0
	mov r2, r0, asr #0xc
	mla r0, r2, r2, r1
	bx lr
	arm_func_end ov0_02158070

	arm_func_start ov0_0215809C
ov0_0215809C: ; 0x0215809C
	stmdb sp!, {r3, lr}
	ldr ip, [sp, #8]
	sub r0, r1, r3
	sub ip, r2, ip
	smull r3, r2, r0, r0
	smull r1, r0, ip, ip
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	bl FX_Sqrt
	ldmia sp!, {r3, pc}
	arm_func_end ov0_0215809C

	arm_func_start ov0_021580D0
ov0_021580D0: ; 0x021580D0
	stmdb sp!, {r3, lr}
	smull ip, r3, r1, r1
	smull r1, r0, r2, r2
	mov r2, ip, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r2, r2, r3, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r2, r1
	bl FX_Sqrt
	ldmia sp!, {r3, pc}
	arm_func_end ov0_021580D0

	arm_func_start ov0_021580F8
ov0_021580F8: ; 0x021580F8
	stmdb sp!, {r3, lr}
	cmp r1, #0
	blt _02158258
	cmp r1, #3
	bge _02158258
	cmp r1, #0
	beq _02158128
	cmp r1, #1
	beq _02158130
	cmp r1, #2
	beq _02158138
	b _02158140
	arm_func_end ov0_021580F8
_02158128:
	ldrb r1, [r0, #0xa4]
	b _02158144
_02158130:
	ldrb r1, [r0, #0xa5]
	b _02158144
_02158138:
	ldrb r1, [r0, #0xa6]
	b _02158144
_02158140:
	mov r1, #0
_02158144:
	cmp r1, #7
	addls pc, pc, r1, lsl #2
	b _02158260
_02158150: ; jump table
	b _02158170 ; case 0
	b _02158178 ; case 1
	b _02158198 ; case 2
	b _021581B8 ; case 3
	b _021581D8 ; case 4
	b _021581F8 ; case 5
	b _02158218 ; case 6
	b _02158238 ; case 7
_02158170:
	mvn r0, #0
	ldmia sp!, {r3, pc}
_02158178:
	ldr r0, [r0, #0x48]
	mov r1, #0x20
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0
	ldmia sp!, {r3, pc}
_02158198:
	ldr r0, [r0, #0x48]
	mov r1, #0x20
	ldr r3, [r0]
	mov r2, #1
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0
	ldmia sp!, {r3, pc}
_021581B8:
	ldr r0, [r0, #0x48]
	mov r1, #0x20
	ldr r3, [r0]
	mov r2, #2
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0
	ldmia sp!, {r3, pc}
_021581D8:
	ldr r0, [r0, #0x48]
	mov r1, #0x20
	ldr r3, [r0]
	mov r2, #3
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0
	ldmia sp!, {r3, pc}
_021581F8:
	ldr r0, [r0, #0x48]
	mov r1, #0x10
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0
	ldmia sp!, {r3, pc}
_02158218:
	ldr r0, [r0, #0x48]
	mov r1, #0x10
	ldr r3, [r0]
	mov r2, #1
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0
	ldmia sp!, {r3, pc}
_02158238:
	ldr r0, [r0, #0x48]
	mov r1, #8
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0
	ldmia sp!, {r3, pc}
_02158258:
	ldr r0, _02158268 ; =s_ERROR_FieldPokeMove_cpp_PlayEn_overlay_0_0217816c
	bl LogError
_02158260:
	mvn r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02158268: .word s_ERROR_FieldPokeMove_cpp_PlayEn_overlay_0_0217816c

	arm_func_start ov0_0215826C
ov0_0215826C: ; 0x0215826C
	ldr r1, _0215828C ; =s_game
	ldr ip, _02158290 ; =FUN_02034CF4
	ldr r2, [r1]
	ldr r1, [r0, #0xb0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	mov r2, #0x40
	bx ip
	.align 2, 0
_0215828C: .word s_game
_02158290: .word _ZN17UnkClass_0203447812sub_02034CF4Eii
	arm_func_end ov0_0215826C

	arm_func_start ov0_02158294
ov0_02158294: ; 0x02158294
	ldr r0, _021582AC ; =s_game
	ldr ip, _021582B0 ; =FUN_02034CA0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bx ip
	.align 2, 0
_021582AC: .word s_game
_021582B0: .word _ZN17UnkClass_0203447812sub_02034CA0Eii
	arm_func_end ov0_02158294

	arm_func_start ov0_021582B4
ov0_021582B4: ; 0x021582B4
	ldr ip, _021582C0 ; =FUN_02041A70
	ldr r0, [r0, #0x48]
	bx ip
	.align 2, 0
_021582C0: .word sub_02041A70
	arm_func_end ov0_021582B4

	arm_func_start ov0_021582C4
ov0_021582C4: ; 0x021582C4
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	ldr sb, [sp, #0x40]
	ldr r8, [sp, #0x3c]
	cmp sb, #0
	ldr r5, [sp, #0x28]
	ldr r4, [sp, #0x30]
	ldr r7, [sp, #0x38]
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	addeq sp, sp, #0x10
	bxeq lr
	ldr r2, [sp, #0x34]
	add r1, sb, sb, lsr #31
	mul r3, r2, r2
	ldr r0, [r0, #0xc8]
	mov sb, r1, asr #1
	cmp r3, r0
	movlt r0, #0
	ldmltia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	addlt sp, sp, #0x10
	bxlt lr
	mov r6, #0
	cmp sb, #0xb4
	movge r0, #1
	ldmgeia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	addge sp, sp, #0x10
	bxge lr
	cmp sb, #0x5a
	blt _0215834C
	rsb sb, sb, #0xb4
	rsb r7, r7, #0
	rsb r8, r8, #0
	mov r6, #1
	arm_func_end ov0_021582C4
_0215834C:
	ldr r1, [sp, #0x2c]
	ldr r0, [sp, #0x24]
	sub r5, r4, r5
	sub r4, r1, r0
	smull r3, r2, r4, r4
	smull r1, r0, r5, r5
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	bl FX_Sqrt
	smull r3, r7, r4, r7
	smull r2, r1, r5, r8
	mov r4, r3, lsr #0xc
	mov r3, r2, lsr #0xc
	mov r2, r0
	orr r4, r4, r7, lsl #20
	orr r3, r3, r1, lsl #20
	add r3, r4, r3
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	mov r4, r0
	mov r0, sb, lsl #0x10
	mov r1, #0x168000
	bl FX_Div
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r0, r0, #1
	mov r1, r0, lsl #1
	ldr r0, _0215841C ; =FX_SinCosTable_
	ldrsh r0, [r0, r1]
	cmp r0, r4
	bge _02158404
	cmp r6, #1
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	add sp, sp, #0x10
	bx lr
_02158404:
	cmp r6, #1
	moveq r0, #1
	movne r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	add sp, sp, #0x10
	bx lr
	.align 2, 0
_0215841C: .word FX_SinCosTable_

	arm_func_start ov0_02158420
ov0_02158420: ; 0x02158420
	ldr r1, [r0, #0xac]
	ldr r2, [r0, #0x88]
	ldr r1, [r1, #0xe0]
	ldr r0, [r0, #0xc4]
	add r1, r2, r1
	mov r2, r1, asr #0xc
	mul r1, r2, r2
	cmp r0, r1
	movlt r0, #1
	movge r0, #0
	bx lr
	arm_func_end ov0_02158420

	arm_func_start _ZN14CFieldPokeMove12ov0_0215844CEPvS0_
_ZN14CFieldPokeMove12ov0_0215844CEPvS0_: ; 0x0215844C
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x58
	mov r6, r0
	mov r5, r1
	mov r4, r2
	add r0, sp, #0x18
	mov r1, #0
	mov r2, #0x40
	bl MI_CpuFill8
	ldr r1, [r6, #0x44]
	add r0, sp, #0xc
	strb r1, [sp, #0x18]
	ldrh r3, [r6, #0x4e]
	add r1, sp, #0x1c
	add r2, r6, #0xc
	strb r3, [sp, #0x19]
	ldr r3, [r6, #0x58]
	strb r3, [sp, #0x1a]
	ldrh r3, [r6, #0x54]
	strb r3, [sp, #0x1b]
	bl ov0_02155538
	ldr r1, [r6, #0x30]
	add r0, sp, #0
	str r1, [sp, #0x28]
	ldr r2, [r6, #0x34]
	add r1, sp, #0x30
	str r2, [sp, #0x2c]
	add r2, r6, #0x24
	bl ov0_02155538
	ldr r0, [r6, #0x38]
	str r0, [sp, #0x3c]
	ldr r0, [r6, #0x3c]
	str r0, [sp, #0x40]
	ldr r0, [r6, #4]
	str r0, [sp, #0x44]
	ldr r0, [r6, #8]
	str r0, [sp, #0x48]
	ldr r0, [r6, #0xd0]
	strb r0, [sp, #0x4c]
	ldr r0, [r6, #0x50]
	strh r0, [sp, #0x4e]
	ldr r0, [r6, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02158518
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #0
	beq _0215851C
	bl _ZN6CActor12sub_02012DD0Ev
	b _0215851C
	arm_func_end _ZN14CFieldPokeMove12ov0_0215844CEPvS0_
_02158518:
	mov r0, #0
_0215851C:
	strh r0, [sp, #0x50]
	ldr r0, [r6, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02158548
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #0
	beq _0215854C
	bl _ZN6CActor12sub_02012E1CEv
	b _0215854C
_02158548:
	mov r0, #0
_0215854C:
	strb r0, [sp, #0x52]
	ldr r0, [r6, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02158574
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneb r0, [r0, #0xc0]
	moveq r0, #0
	b _02158578
_02158574:
	mov r0, #0
_02158578:
	strb r0, [sp, #0x53]
	ldr r1, [r6, #0x48]
	add r0, r5, #0x40
	ldr r1, [r1, #4]
	cmp r0, r4
	str r1, [sp, #0x54]
	addhi sp, sp, #0x58
	movhi r0, #0
	ldmhiia sp!, {r4, r5, r6, pc}
	add r0, sp, #0x18
	mov r1, r5
	mov r2, #0x40
	bl MI_CpuCopy8
	mov r0, #0x40
	add sp, sp, #0x58
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN14CFieldPokeMove12ov0_021585B8EPv
_ZN14CFieldPokeMove12ov0_021585B8EPv: ; 0x021585B8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	mov sb, r1
	ldrb r1, [sb]
	mov sl, r0
	add r0, sp, #0xc
	str r1, [sl, #0x44]
	ldrb r3, [sb, #1]
	add r1, sl, #0xc
	add r2, sb, #4
	strh r3, [sl, #0x4e]
	ldrb r3, [sb, #2]
	str r3, [sl, #0x58]
	ldrb r3, [sb, #3]
	strh r3, [sl, #0x54]
	bl ov0_02155538
	ldr r0, [sl, #0x48]
	ldr r1, [sl, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	ldr r0, [sl, #0x48]
	ldr r2, [sl, #0x10]
	ldr r0, [r0, #8]
	ldr r1, [sl, #0x14]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	sub r2, r2, r1
	cmpne r0, #0
	ldrne r0, [r0, #0xc4]
	ldr r1, [sl, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x18]
	strne r2, [r0, #0x1c]
	ldr r1, [sb, #0x10]
	add r0, sp, #0
	str r1, [sl, #0x30]
	ldr r2, [sb, #0x14]
	add r1, sl, #0x24
	str r2, [sl, #0x34]
	add r2, sb, #0x18
	bl ov0_02155538
	ldr r0, [sb, #0x24]
	str r0, [sl, #0x38]
	ldr r0, [sb, #0x28]
	str r0, [sl, #0x3c]
	ldr r0, [sb, #0x2c]
	str r0, [sl, #4]
	ldr r0, [sb, #0x30]
	str r0, [sl, #8]
	ldrb r0, [sb, #0x34]
	str r0, [sl, #0xd0]
	ldrh r0, [sb, #0x36]
	str r0, [sl, #0x50]
	ldr r0, [sl, #0x48]
	ldrb r1, [sb, #0x3b]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strneb r1, [r0, #0xc0]
	ldr r0, [sl, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021586D0
	bl _ZN6CActor12sub_02012E68Ev
	arm_func_end _ZN14CFieldPokeMove12ov0_021585B8EPv
_021586D0:
	ldr r0, [sl, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021586EC
	bl _ZN6CActor12sub_02012DD0Ev
_021586EC:
	ldr r0, [sl, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02158708
	bl _ZN6CActor12sub_02012E1CEv
_02158708:
	ldr r0, _02158890 ; =0x0000FFFF
	mov r4, #0
	sub r7, r0, #1
	mov r6, r4
	mov r5, r4
	mov fp, r4
_02158720:
	ldr r0, [sl, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0215873C
	bl _ZN6CActor12sub_020125FCEv
_0215873C:
	ldr r0, [sl, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02158768
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r8, r6
	beq _0215876C
	bl _ZN6CActor12sub_02012DD0Ev
	mov r8, r0
	b _0215876C
_02158768:
	mov r8, r5
_0215876C:
	ldr r0, [sl, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02158794
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, r4
	beq _02158798
	bl _ZN6CActor12sub_02012E1CEv
	b _02158798
_02158794:
	mov r0, fp
_02158798:
	ldrh r1, [sb, #0x38]
	cmp r8, r1
	ldreqb r1, [sb, #0x3a]
	cmpeq r0, r1
	beq _021587B8
	cmp r7, #0
	sub r7, r7, #1
	bne _02158720
_021587B8:
	ldr r0, [sl, #0x48]
	mov r3, #0
	str r3, [r0, #4]
	ldr r2, [sl, #0x48]
	ldr r0, [sb, #0x3c]
	ldr r1, [r2, #4]
	orr r0, r1, r0
	str r0, [r2, #4]
	ldr r2, [sl, #0x48]
	ldr r0, [r2, #4]
	ands r1, r0, #8
	movne r3, #1
	cmp r3, #0
	ldr r0, [r2, #8]
	beq _02158834
	cmp r0, #0
	beq _02158868
	cmp r1, #0
	bne _02158868
	ldr r0, [r2, #4]
	orr r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r2, #0x94]
	b _02158868
_02158834:
	cmp r0, #0
	beq _02158868
	ldr r0, [r2, #4]
	bic r0, r0, #8
	str r0, [r2, #4]
	ldr r0, [r2, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02158868
	mov r0, #3
	str r0, [r1, #0x1dc]
	mov r0, #0
	strb r0, [r1, #0x1e1]
_02158868:
	ldr r0, [sl, #0x48]
	ldr r1, [r0, #4]
	tst r1, #0x800
	beq _02158880
	bl _ZN11CFieldEnemy12ov0_02134FCCEv
	b _02158884
_02158880:
	bl _ZN11CFieldEnemy12ov0_021351ACEv
_02158884:
	mov r0, #1
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02158890: .word 0x0000FFFF

	arm_func_start ov0_02158894
ov0_02158894: ; 0x02158894
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x10
	ldr r1, [sp, #0x1c]
	ldr r2, [r0, #0xc]
	smull lr, ip, r1, r3
	ldr r1, [sp, #0x20]
	str r2, [sp]
	smull r3, r2, r1, r3
	ldr r1, [r0, #0x10]
	mov lr, lr, lsr #0xc
	str r1, [sp, #4]
	mov r1, r3, lsr #0xc
	ldr r3, [r0, #0xc]
	orr lr, lr, ip, lsl #20
	add r3, r3, lr
	str r3, [sp, #8]
	ldr r3, [r0, #0x10]
	orr r1, r1, r2, lsl #20
	add r1, r3, r1
	str r1, [sp, #0xc]
	ldr r1, [r0, #0xbc]
	ldr r3, [r0, #0xb4]
	cmp r1, #0
	ldr r2, [r0, #0x64]
	moveq r0, #0
	beq _0215890C
	ldr r0, [r0, #0x48]
	add r1, sp, #0
	bl _ZN11CFieldActor12sub_0203CF40ERK11PointPair2Dlm
	arm_func_end ov0_02158894
_0215890C:
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	add sp, sp, #0x10
	ldmia sp!, {r3, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start ov0_02158928
ov0_02158928: ; 0x02158928
	stmdb sp!, {r3, lr}
	ldr ip, [r0, #0xbc]
	cmp ip, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	str r3, [sp]
	ldr r0, [r0, #0x48]
	mov r3, r2
	ldmia r1, {r1, r2}
	bl _ZN11CFieldActor12sub_0203D110E7Point2Dlm
	ldmia sp!, {r3, pc}
	arm_func_end ov0_02158928

	arm_func_start _ZN14CFieldPokeMove12ov0_02158954Ev
_ZN14CFieldPokeMove12ov0_02158954Ev: ; 0x02158954
	stmdb sp!, {r3, lr}
	ldrh r1, [r0, #0xb8]
	cmp r1, #0
	ldrne r0, _02158984 ; =MAIN_BSS_0210CA60
	ldrne r0, [r0]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov0_021633B8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02158984: .word MAIN_BSS_0210CA60
	arm_func_end _ZN14CFieldPokeMove12ov0_02158954Ev

	arm_func_start _ZN14CFieldPokeMove12ov0_02158988Ev
_ZN14CFieldPokeMove12ov0_02158988Ev: ; 0x02158988
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r1, [r4, #0xd4]
	ldr r0, _02158B2C ; =s_game
	eor r1, r1, #0xff
	strb r1, [r4, #0xd4]
	ldr r0, [r0]
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008E50Ev
	cmp r0, #0x3c
	ldreqb r0, [r4, #0xd4]
	cmpeq r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x44]
	cmp r0, #9
	bgt _02158A00
	cmp r0, #0
	addge pc, pc, r0, lsl #2
	ldmia sp!, {r4, pc}
_021589D8: ; jump table
	ldmia sp!, {r4, pc} ; case 0
	b _02158A0C ; case 1
	ldmia sp!, {r4, pc} ; case 2
	b _02158A0C ; case 3
	b _02158A0C ; case 4
	ldmia sp!, {r4, pc} ; case 5
	ldmia sp!, {r4, pc} ; case 6
	ldmia sp!, {r4, pc} ; case 7
	ldmia sp!, {r4, pc} ; case 8
	b _02158A0C ; case 9
	arm_func_end _ZN14CFieldPokeMove12ov0_02158988Ev
_02158A00:
	cmp r0, #0x19
	beq _02158AF8
	ldmia sp!, {r4, pc}
_02158A0C:
	ldr r0, [r4, #0x68]
	cmp r0, #1
	cmpne r0, #2
	beq _02158AA0
	cmp r0, #3
	ldmneia sp!, {r4, pc}
	ldr r0, [r4, #0x2c]
	ldrh r1, [r4, #0x84]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r2, r0, asr #4
	ldr r0, _02158B30 ; =FX_SinCosTable_
	mov r2, r2, lsl #2
	ldrsh r2, [r0, r2]
	mov r0, r1, lsl #0xc
	ldrb r3, [r4, #0xa1]
	smull r1, r0, r2, r0
	adds r1, r1, #0x800
	adc r0, r0, #0
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	add r0, r1, r3, lsl #12
	str r0, [r4, #0x14]
	ldrh r0, [r4, #0x82]
	ldr r1, [r4, #0x2c]
	add r1, r1, r0
	mov r0, r1, lsl #0x10
	mov r0, r0, lsr #0x10
	str r0, [r4, #0x2c]
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	ldmia sp!, {r4, pc}
_02158AA0:
	ldrh r1, [r4, #0x9a]
	ldr r2, [r4, #0x2c]
	mov r0, #0x64000
	sub r1, r2, r1
	rsb r0, r0, #0
	str r1, [r4, #0x2c]
	cmp r1, r0
	strlt r0, [r4, #0x2c]
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #0x2c]
	adds r0, r1, r0
	str r0, [r4, #0x14]
	movmi r0, #0
	strmi r0, [r4, #0x14]
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	ldmia sp!, {r4, pc}
_02158AF8:
	ldr r0, [r4, #0x68]
	cmp r0, #3
	ldmneia sp!, {r4, pc}
	ldrb r0, [r4, #0xa1]
	mov r1, r0, lsl #0xc
	str r1, [r4, #0x14]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02158B2C: .word s_game
_02158B30: .word FX_SinCosTable_

	arm_func_start ov0_02158B34
ov0_02158B34: ; 0x02158B34
	stmdb sp!, {r4, lr}
	mov r1, r1, asr #0xc
	cmp r1, #1
	movlt r4, #1
	mulge r4, r1, r1
	bl ov0_02158070
	cmp r0, r4
	movle r0, #1
	movgt r0, #0
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02158B34

	arm_func_start ov0_02158B5C
ov0_02158B5C: ; 0x02158B5C
	stmdb sp!, {r4, r5, r6, lr}
	ldr r1, _02158F34 ; =MAIN_BSS_0210CA60
	ldr r4, [r1]
	cmp r4, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r1, [r0, #0x48]
	ldr r2, [r1, #8]
	cmp r2, #0
	beq _02158B94
	ldr r0, [r2, #0xc]
	cmp r0, #0
	ldrne r5, [r0, #0x20]
	moveq r5, #0
	b _02158B98
	arm_func_end ov0_02158B5C
_02158B94:
	mov r5, #0
_02158B98:
	cmp r2, #0
	beq _02158BB4
	ldr r0, [r2, #0xc]
	cmp r0, #0
	ldrne r6, [r0, #0x24]
	moveq r6, #0
	b _02158BB8
_02158BB4:
	mov r6, #0
_02158BB8:
	ldr r2, [r1, #0x6c]
	mov r3, #0
	cmp r2, #0
	beq _02158BF8
	ldr r1, [r1, #0x14]
	ldr r0, [r2, #0x24]
	cmp r1, r0
	ldrlt r0, [r2, #0x30]
	ldrlt r0, [r0, r1, lsl #2]
	movge r0, r3
	cmp r0, #0
	beq _02158BF8
	mov r1, r5
	mov r2, r6
	bl _ZN23CFieldMapLayerAttribute12GetCellAtPosEll
	mov r3, r0
_02158BF8:
	cmp r3, #0x16
	addls pc, pc, r3, lsl #2
	ldmia sp!, {r4, r5, r6, pc}
_02158C04: ; jump table
	ldmia sp!, {r4, r5, r6, pc} ; case 0
	b _02158C60 ; case 1
	b _02158DEC ; case 2
	b _02158D30 ; case 3
	b _02158D30 ; case 4
	b _02158DEC ; case 5
	b _02158C60 ; case 6
	ldmia sp!, {r4, r5, r6, pc} ; case 7
	b _02158D30 ; case 8
	ldmia sp!, {r4, r5, r6, pc} ; case 9
	ldmia sp!, {r4, r5, r6, pc} ; case 10
	b _02158E60 ; case 11
	ldmia sp!, {r4, r5, r6, pc} ; case 12
	ldmia sp!, {r4, r5, r6, pc} ; case 13
	ldmia sp!, {r4, r5, r6, pc} ; case 14
	ldmia sp!, {r4, r5, r6, pc} ; case 15
	ldmia sp!, {r4, r5, r6, pc} ; case 16
	ldmia sp!, {r4, r5, r6, pc} ; case 17
	ldmia sp!, {r4, r5, r6, pc} ; case 18
	ldmia sp!, {r4, r5, r6, pc} ; case 19
	ldmia sp!, {r4, r5, r6, pc} ; case 20
	ldmia sp!, {r4, r5, r6, pc} ; case 21
	ldmia sp!, {r4, r5, r6, pc} ; case 22
_02158C60:
	mov r0, r4
	mov r1, #0xb
	mov r2, #0
	bl _ZN18CFieldEffectManage12ov0_02142F6CEii
	mov r1, r0
	mov r0, r4
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r4, r0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r3, [r0]
	mov r1, #0
	ldr r3, [r3, #0x38]
	mov r2, #8
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #8
	ldr r3, [r3, #0x38]
	mov r2, #0x14
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r2, r5, asr #0xc
	ldr r3, [r3, #0x38]
	mov r1, #1
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r2, r6, asr #0xc
	ldr r3, [r3, #0x38]
	mov r1, #2
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #3
	ldr r3, [r3, #0x38]
	mov r2, #0
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #4
	ldr r3, [r3, #0x38]
	mov r2, #0
	blx r3
	mov r1, #0
	mov r0, r4
	ldr r4, [r0]
	sub r2, r1, #1
	ldr r4, [r4, #0x1c]
	mov r3, r1
	blx r4
	ldmia sp!, {r4, r5, r6, pc}
_02158D30:
	mov r0, r4
	mov r1, #0xa
	mov r2, #0
	bl _ZN18CFieldEffectManage12ov0_02142F6CEii
	mov r1, r0
	mov r0, r4
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r4, r0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r3, [r0]
	mov r1, #0
	ldr r3, [r3, #0x38]
	mov r2, #0x10
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r2, r5, asr #0xc
	ldr r3, [r3, #0x38]
	mov r1, #1
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, r6, asr #0xc
	add r2, r1, #8
	ldr r3, [r3, #0x38]
	mov r1, #2
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #3
	ldr r3, [r3, #0x38]
	mov r2, #0x10
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #4
	ldr r3, [r3, #0x38]
	mov r2, #0
	blx r3
	mov r1, #0
	mov r0, r4
	ldr r4, [r0]
	sub r2, r1, #1
	ldr r4, [r4, #0x1c]
	mov r3, r1
	blx r4
	ldmia sp!, {r4, r5, r6, pc}
_02158DEC:
	mov r0, r4
	mov r1, #0x26
	mov r2, #0
	bl _ZN18CFieldEffectManage12ov0_02142F6CEii
	mov r1, r0
	mov r0, r4
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r4, r0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r3, [r0]
	mov r2, r5, asr #0xc
	ldr r3, [r3, #0x38]
	mov r1, #1
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, r6, asr #0xc
	add r2, r1, #8
	ldr r3, [r3, #0x38]
	mov r1, #2
	blx r3
	mov r1, #0
	mov r0, r4
	ldr r4, [r0]
	mov r3, r1
	ldr r4, [r4, #0x1c]
	sub r2, r1, #1
	blx r4
	ldmia sp!, {r4, r5, r6, pc}
_02158E60:
	mov r0, r4
	mov r1, #0xa
	mov r2, #0
	bl _ZN18CFieldEffectManage12ov0_02142F6CEii
	mov r1, r0
	mov r0, r4
	bl _ZN18CFieldEffectManage12ov0_02143088Et
	movs r4, r0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r3, [r0]
	mov r1, #0
	ldr r3, [r3, #0x38]
	mov r2, #0x10
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r2, r5, asr #0xc
	ldr r3, [r3, #0x38]
	mov r1, #1
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, r6, asr #0xc
	add r2, r1, #8
	mov r1, #2
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, r4
	mov r1, #3
	mov r2, #0x10
	ldr r3, [r0]
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, r4
	mov r1, #4
	mov r2, #0
	ldr r3, [r0]
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, r4
	mov r1, #0x13
	mov r2, #1
	ldr r3, [r0]
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, r4
	mov r1, #0
	sub r2, r1, #1
	mov r3, r1
	ldr r4, [r0]
	ldr r4, [r4, #0x1c]
	blx r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02158F34: .word MAIN_BSS_0210CA60

	arm_func_start ov0_02158F38
ov0_02158F38: ; 0x02158F38
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #0x44]
	cmp r1, #9
	addls pc, pc, r1, lsl #2
	ldmia sp!, {r3, pc}
_02158F4C: ; jump table
	ldmia sp!, {r3, pc} ; case 0
	b _02158F74 ; case 1
	ldmia sp!, {r3, pc} ; case 2
	b _02158F74 ; case 3
	b _02158F74 ; case 4
	ldmia sp!, {r3, pc} ; case 5
	ldmia sp!, {r3, pc} ; case 6
	ldmia sp!, {r3, pc} ; case 7
	ldmia sp!, {r3, pc} ; case 8
	b _02158F74 ; case 9
	arm_func_end ov0_02158F38
_02158F74:
	ldr r1, [r0, #0x68]
	cmp r1, #3
	ldmneia sp!, {r3, pc}
	ldr r1, [r0, #0x48]
	ldr r3, [r1, #8]
	cmp r3, #0
	beq _02158FA4
	ldr r1, [r3, #0xc]
	cmp r1, #0
	ldrne ip, [r1, #0x20]
	moveq ip, #0
	b _02158FA8
_02158FA4:
	mov ip, #0
_02158FA8:
	cmp r3, #0
	beq _02158FC4
	ldr r1, [r3, #0xc]
	cmp r1, #0
	ldrne lr, [r1, #0x24]
	moveq lr, #0
	b _02158FC8
_02158FC4:
	mov lr, #0
_02158FC8:
	ldrb r1, [r0, #0xa1]
	cmp r3, #0
	mov r2, r1, lsl #0xc
	ldrne r1, [r3, #0xc]
	cmpne r1, #0
	strne r2, [r1, #0x8c]
	ldr r0, [r0, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	ldrne r1, [r0, #0xc4]
	cmpne r1, #0
	strne ip, [r1, #0x18]
	subne r0, lr, r2
	strne r0, [r1, #0x1c]
	ldmia sp!, {r3, pc}

	arm_func_start ov0_0215900C
ov0_0215900C: ; 0x0215900C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x11c
	mov r4, r0
	mov r0, #0x8000
	strh r0, [r4, #0x4c]
	ldr r5, [r4, #0x48]
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _02159070
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02159050
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x10c]
	str r0, [sp, #0x110]
	b _02159068
	arm_func_end ov0_0215900C
_02159050:
	mov r0, #0
	add r1, sp, #0xb4
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x10c]
	str r0, [sp, #0x110]
_02159068:
	add r2, sp, #0x10c
	b _0215908C
_02159070:
	mov r0, #0
	add r1, sp, #0xac
	add r2, sp, #0x10c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x10c]
	str r0, [sp, #0x110]
_0215908C:
	ldr r0, [r2]
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021590E4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021590C4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x104]
	str r0, [sp, #0x108]
	b _021590DC
_021590C4:
	mov r0, #0
	add r1, sp, #0xa4
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x104]
	str r0, [sp, #0x108]
_021590DC:
	add r2, sp, #0x104
	b _02159100
_021590E4:
	mov r0, #0
	add r1, sp, #0x9c
	add r2, sp, #0x104
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x104]
	str r0, [sp, #0x108]
_02159100:
	ldr r1, [r2, #4]
	mov r0, #0x10000
	str r1, [r4, #0x10]
	ldr r1, [r4, #0xb4]
	orr r1, r1, #8
	str r1, [r4, #0xb4]
	str r0, [r4, #0x64]
	ldrh r0, [r4, #0x4e]
	cmp r0, #0
	beq _0215913C
	cmp r0, #1
	beq _02159264
	cmp r0, #2
	beq _0215941C
	b _02159910
_0215913C:
	mov r0, r4
	bl ov0_02156A8C
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02159168
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _0215916C
_02159168:
	mov r0, #0
_0215916C:
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r1, r0, #1
	ldr r0, _02159924 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021591AC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _021591B0
_021591AC:
	mov r0, #0
_021591B0:
	mov r1, r0, asr #4
	ldr r0, _02159924 ; =FX_SinCosTable_
	mov r1, r1, lsl #2
	ldrsh r0, [r0, r1]
	str r0, [r4, #0x34]
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldr r1, [r4, #4]
	ldr r0, [r4, #8]
	sub r1, r1, r3
	sub r8, r0, r2
	str r1, [r4, #0x38]
	str r8, [r4, #0x3c]
	ldr r0, [r4, #0x38]
	str r3, [sp, #0xf4]
	smull r7, r6, r0, r0
	smull r5, r0, r8, r8
	mov r7, r7, lsr #0xc
	mov r5, r5, lsr #0xc
	orr r7, r7, r6, lsl #20
	orr r5, r5, r0, lsl #20
	add r0, r7, r5
	str r2, [sp, #0xf8]
	str r3, [sp, #0x94]
	str r2, [sp, #0x98]
	str r1, [sp, #0x8c]
	str r8, [sp, #0x90]
	str r1, [sp, #0xfc]
	str r8, [sp, #0x100]
	bl FX_InvSqrt
	ldr r1, [r4, #0x38]
	ldr r2, _02159928 ; =0x00000FFF
	smull r5, r3, r1, r0
	mov r1, r5, lsr #0xc
	orr r1, r1, r3, lsl #20
	str r1, [r4, #0x38]
	ldr r3, [r4, #0x3c]
	mov r1, #1
	smull r5, r0, r3, r0
	mov r3, r5, lsr #0xc
	orr r3, r3, r0, lsl #20
	str r3, [r4, #0x3c]
	strh r2, [r4, #0x4c]
	strh r1, [r4, #0x4e]
	b _02159918
_02159264:
	ldrb r0, [r4, #0xa8]
	cmp r0, #0
	bne _02159294
	ldrh r3, [r4, #0x4c]
	mov r0, r4
	add r1, r4, #0x30
	add r2, r4, #0x38
	bl ov0_02157F0C
	cmp r0, #0
	movne r0, #2
	strneh r0, [r4, #0x4e]
	b _0215929C
_02159294:
	mov r0, #2
	strh r0, [r4, #0x4e]
_0215929C:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x30]
	bl FX_Atan2Idx
	ldr r2, [r4, #0x48]
	mov r1, r0
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021592C8
	bl _ZN6CActor12sub_020128ECEt
_021592C8:
	ldr r0, [r4, #0x68]
	sub r0, r0, #1
	cmp r0, #1
	bhi _02159918
	ldrh r0, [r4, #0x98]
	ldrh r2, [r4, #0x9a]
	mov r3, #0
	mov r5, r0, lsl #0xc
	mov r0, r5, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r5, lsr #20
	mov r0, r5, lsl #0xc
	bl _ll_div
	mov r5, r0, lsl #1
	ldr r0, [r4, #0x48]
	cmp r5, #0x1000
	ldr r0, [r0, #8]
	movlt r5, #0x1000
	cmp r0, #0
	beq _02159358
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02159338
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xec]
	str r0, [sp, #0xf0]
	b _02159350
_02159338:
	mov r0, #0
	add r1, sp, #0x84
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xec]
	str r0, [sp, #0xf0]
_02159350:
	add r3, sp, #0xec
	b _02159374
_02159358:
	mov r0, #0
	add r1, sp, #0x7c
	add r3, sp, #0xec
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xec]
	str r0, [sp, #0xf0]
_02159374:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021593C4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021593A4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xe4]
	str r0, [sp, #0xe8]
	b _021593BC
_021593A4:
	mov r0, #0
	add r1, sp, #0x74
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xe4]
	str r0, [sp, #0xe8]
_021593BC:
	add r2, sp, #0xe4
	b _021593E0
_021593C4:
	mov r0, #0
	add r1, sp, #0x6c
	add r2, sp, #0xe4
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xe4]
	str r0, [sp, #0xe8]
_021593E0:
	ldr r1, [r2, #4]
	mov r0, r4
	str r1, [sp]
	ldr r3, [r3]
	ldmib r4, {r1, r2}
	bl ov0_0215809C
	mov r1, r0, asr #0x1f
	mov r1, r1, lsl #0xc
	orr r1, r1, r0, lsr #20
	mov r2, r5
	mov r0, r0, lsl #0xc
	mov r3, r5, asr #0x1f
	bl _ll_div
	str r0, [r4, #0xd8]
	b _02159918
_0215941C:
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _02159438
	mov r0, r4
	mov r1, #1
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02159918
_02159438:
	bl ov0_0215993C
	cmp r0, #0x3c
	ldr r0, [r4, #0x48]
	ldr r2, [r4, #4]
	ldr r1, [r4, #8]
	moveq r6, #1
	ldr r0, [r0, #8]
	movne r6, #2
	str r2, [sp, #0x114]
	str r1, [sp, #0x118]
	cmp r0, #0
	beq _021594A8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02159488
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xdc]
	str r0, [sp, #0xe0]
	b _021594A0
_02159488:
	mov r0, #0
	add r1, sp, #0x5c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xdc]
	str r0, [sp, #0xe0]
_021594A0:
	add r2, sp, #0xdc
	b _021594C4
_021594A8:
	mov r0, #0
	add r1, sp, #0x54
	add r2, sp, #0xdc
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xdc]
	str r0, [sp, #0xe0]
_021594C4:
	ldr r3, [r2]
	ldr r2, [r2, #4]
	ldr r1, [sp, #0x114]
	ldr r0, [sp, #0x118]
	sub r1, r1, r3
	sub r0, r0, r2
	smull r8, r7, r1, r1
	smull lr, ip, r0, r0
	mov r8, r8, lsr #0xc
	mov lr, lr, lsr #0xc
	ldr r5, [r5, #0x1ec]
	orr r8, r8, r7, lsl #20
	orr lr, lr, ip, lsl #20
	str r3, [sp, #0x64]
	str r2, [sp, #0x68]
	str r1, [sp, #0x114]
	str r0, [sp, #0x118]
	cmp r5, #1
	add r5, r8, lr
	bne _02159568
	cmp r5, #0x4000000
	ldr r1, [r4, #0xac]
	ble _02159544
	ldr r1, [r1, #0x10]
	mov r0, #0x3800
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mul r2, r6, r0
	b _0215961C
_02159544:
	ldr r1, [r1, #0x10]
	mov r0, #0x2800
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mul r2, r6, r0
	b _0215961C
_02159568:
	cmp r5, #0x4000000
	ble _02159598
	ldr r1, [r4, #0xac]
	mov r0, #0x3800
	ldr r1, [r1, #0x10]
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mul r2, r6, r0
	b _0215961C
_02159598:
	ldr r0, [r4, #0x68]
	cmp r0, #1
	bne _021595CC
	ldr r1, [r4, #0xac]
	ldr r0, _0215992C ; =0x00001CCC
	ldr r1, [r1, #0x10]
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mul r2, r6, r0
	b _0215961C
_021595CC:
	cmp r0, #2
	ldr r1, [r4, #0xac]
	bne _021595FC
	ldr r0, _02159930 ; =0x00002666
	ldr r1, [r1, #0x10]
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mul r2, r6, r0
	b _0215961C
_021595FC:
	ldr r0, _02159934 ; =0x00001333
	ldr r1, [r1, #0x10]
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mul r2, r6, r0
_0215961C:
	ldr r0, [r4, #0x68]
	sub r0, r0, #1
	cmp r0, #1
	bhi _02159788
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _02159784
	ldrh r0, [r4, #0x98]
	ldrh r2, [r4, #0x9a]
	mov r3, #0
	mov r6, r0, lsl #0xc
	mov r0, r6, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r6, lsr #20
	mov r0, r6, lsl #0xc
	bl _ll_div
	mov r6, r0, lsl #1
	ldr r0, [r4, #0x48]
	cmp r6, #0x1000
	ldr r0, [r0, #8]
	movlt r6, #0x1000
	cmp r0, #0
	beq _021596B8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02159698
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xd4]
	str r0, [sp, #0xd8]
	b _021596B0
_02159698:
	mov r0, #0
	add r1, sp, #0x4c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xd4]
	str r0, [sp, #0xd8]
_021596B0:
	add r3, sp, #0xd4
	b _021596D4
_021596B8:
	mov r0, #0
	add r1, sp, #0x44
	add r3, sp, #0xd4
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xd4]
	str r0, [sp, #0xd8]
_021596D4:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02159724
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02159704
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xcc]
	str r0, [sp, #0xd0]
	b _0215971C
_02159704:
	mov r0, #0
	add r1, sp, #0x3c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xcc]
	str r0, [sp, #0xd0]
_0215971C:
	add r2, sp, #0xcc
	b _02159740
_02159724:
	mov r0, #0
	add r1, sp, #0x34
	add r2, sp, #0xcc
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xcc]
	str r0, [sp, #0xd0]
_02159740:
	ldr r1, [r2, #4]
	mov r0, r4
	str r1, [sp]
	ldr r3, [r3]
	ldmib r4, {r1, r2}
	bl ov0_0215809C
	mov r1, r0, asr #0x1f
	mov r1, r1, lsl #0xc
	orr r1, r1, r0, lsr #20
	mov r2, r6
	mov r0, r0, lsl #0xc
	mov r3, r6, asr #0x1f
	bl _ll_div
	str r0, [r4, #0xd8]
	cmp r0, #0x1000
	movlt r0, #0x1000
	strlt r0, [r4, #0xd8]
_02159784:
	ldr r2, [r4, #0xd8]
_02159788:
	smull r1, r0, r2, r2
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	cmp r5, r1
	cmpgt r5, #0x1000
	bgt _021598FC
	ldr r0, [r4, #0x48]
	ldr r2, [r4, #4]
	ldr r5, [r0, #8]
	ldr r1, [r4, #8]
	cmp r5, #0
	ldrne r0, [r5, #0xc]
	str r1, [sp, #0x30]
	str r2, [sp, #0x2c]
	add r1, sp, #0x2c
	cmpne r0, #0
	beq _02159800
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [r5, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	beq _02159800
	ldr r1, [sp, #0x2c]
	ldr r0, [sp, #0x30]
	str r1, [r2, #0x18]
	str r1, [sp, #0x24]
	str r0, [sp, #0x28]
	str r0, [r2, #0x1c]
_02159800:
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02159850
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02159830
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xc4]
	str r0, [sp, #0xc8]
	b _02159848
_02159830:
	mov r0, #0
	add r1, sp, #0x1c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xc4]
	str r0, [sp, #0xc8]
_02159848:
	add r2, sp, #0xc4
	b _0215986C
_02159850:
	mov r0, #0
	add r1, sp, #0x14
	add r2, sp, #0xc4
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xc4]
	str r0, [sp, #0xc8]
_0215986C:
	ldr r0, [r2]
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x48]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _021598C4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _021598A4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0xbc]
	str r0, [sp, #0xc0]
	b _021598BC
_021598A4:
	mov r0, #0
	add r1, sp, #0xc
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xbc]
	str r0, [sp, #0xc0]
_021598BC:
	add r2, sp, #0xbc
	b _021598E0
_021598C4:
	mov r0, #0
	add r1, sp, #4
	add r2, sp, #0xbc
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0xbc]
	str r0, [sp, #0xc0]
_021598E0:
	ldr r1, [r2, #4]
	mov r0, r4
	str r1, [r4, #0x10]
	mov r1, #1
	str r1, [r4, #0x40]
	bl _ZN14CFieldPokeMove12ov0_0215674CEi
	b _02159918
_021598FC:
	mov r0, r4
	add r1, r4, #0x24
	mvn r3, #0
	bl ov0_02156B30
	b _02159918
_02159910:
	ldr r0, _02159938 ; =s_CFieldPokeMove_Sequence_Exceptio_overlay_0_02178198
	bl LogError
_02159918:
	mov r0, #0
	add sp, sp, #0x11c
	ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02159924: .word FX_SinCosTable_
_02159928: .word 0x00000FFF
_0215992C: .word 0x00001CCC
_02159930: .word 0x00002666
_02159934: .word 0x00001333
_02159938: .word s_CFieldPokeMove_Sequence_Exceptio_overlay_0_02178198

	arm_func_start ov0_0215993C
ov0_0215993C: ; 0x0215993C
	ldr r0, _02159948 ; =DAT_0208d58c
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_02159948: .word DAT_0208d58c
	arm_func_end ov0_0215993C

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

    .global DAT_overlay_0_02172ee0
DAT_overlay_0_02172ee0: ; 0x02172EE0
	.byte 0x00, 0x10, 0x00, 0x00

    .global DAT_overlay_0_02172ee4
DAT_overlay_0_02172ee4: ; 0x02172EE4
	.byte 0x00, 0x00, 0x00, 0x00

    .bss

    .global OVERLAY0_BSS_0217B380
OVERLAY0_BSS_0217B380: ; 0x0217B380
    .space 0x20
