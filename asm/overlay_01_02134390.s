    .include "macros.inc"
    .include "include/overlay_01_02134390.inc"

    .text

	arm_func_start _ZN17CBattleAssistRockC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t
_ZN17CBattleAssistRockC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t: ; 0x02134390
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldrh ip, [sp, #0x10]
	mov r4, r0
	str ip, [sp]
	bl _ZN13CBattleAssistC2EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t
	ldr r1, _021343BC ; =PTR_LAB_overlay_1_021343c0_overlay_1_02141828
	mov r0, r4
	str r1, [r4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_021343BC: .word PTR_LAB_overlay_1_021343c0_overlay_1_02141828
	arm_func_end _ZN17CBattleAssistRockC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t

	arm_func_start ov1_021343C0
ov1_021343C0: ; 0x021343C0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN13CBattleAssistD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_021343C0

	arm_func_start ov1_021343D4
ov1_021343D4: ; 0x021343D4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN13CBattleAssistD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_021343D4

	arm_func_start ov1_021343F0
ov1_021343F0: ; 0x021343F0
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0xc
	mov r5, r0
	ldrh r2, [r5, #4]
	mov r4, r1
	cmp r2, #0
	addeq sp, sp, #0xc
	moveq r0, #0
	ldmeqia sp!, {r4, r5, pc}
	sub r2, r2, #1
	mov r1, r3
	strh r2, [r5, #4]
	bl ov1_02134600
	ldrh r2, [r4, #0xa]
	ldrh r1, [r4, #0xc]
	ldrb r0, [r4, #4]
	sub r2, r2, #0x80
	sub r1, r1, #0x60
	mov r3, r2, lsl #0xc
	mov r2, r1, lsl #0xc
	str r3, [sp, #4]
	str r2, [sp, #8]
	cmp r0, #0
	beq _021344A4
	str r3, [r5, #0x20]
	str r2, [r5, #0x24]
	mov r2, #0
	add r1, sp, #0
	mov r0, r5
	strb r2, [sp]
	bl ov1_02134770
	cmp r0, #0
	beq _021344A4
	ldrb r1, [sp]
	add r0, sp, #4
	strb r1, [r5, #0x19]
	ldrb r3, [sp]
	ldmia r0, {r1, r2}
	add r0, r5, r3, lsl #2
	ldr r0, [r0, #0x28]
	add r0, r0, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldrb r0, [r5, #0x18]
	orr r0, r0, #1
	strb r0, [r5, #0x18]
	arm_func_end ov1_021343F0
_021344A4:
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _02134528
	ldrb r0, [r5, #0x18]
	tst r0, #1
	beq _021344F8
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r2, [r0, #0x28]
	cmp r2, #0
	beq _021344F8
	ldr r0, [r2, #0x104]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _021344F8
	add r1, sp, #4
	add r0, r2, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
_021344F8:
	ldrh r0, [r5, #0x1c]
	cmp r0, #0xa
	bne _02134520
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	str r1, [r5, #0x20]
	str r0, [r5, #0x24]
	mov r0, #0
	strh r0, [r5, #0x1c]
	b _02134528
_02134520:
	addlo r0, r0, #1
	strloh r0, [r5, #0x1c]
_02134528:
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _021345F0
	ldrb r0, [r5, #0x18]
	tst r0, #1
	beq _021345E4
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _021345E0
	ldr r1, [r0, #0x104]
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	cmp r1, #0
	beq _021345E0
	add r1, sp, #4
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r3, [sp, #8]
	ldr r0, [r5, #0x24]
	ldr r2, [sp, #4]
	ldr r1, [r5, #0x20]
	sub r0, r3, r0
	sub r1, r2, r1
	bl FX_Atan2Idx
	ldrb r3, [r5, #0x19]
	mov r1, r0
	mov r2, #0x6000
	add r0, r5, r3, lsl #2
	ldr r0, [r0, #0x28]
	add r0, r0, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011C90Etl
	ldr r0, [r5, #0x14]
	ldr r1, _021345FC ; =0x0000012A
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldrb r1, [r5, #0x19]
	mov r0, #6
	add r2, r5, #0x38
	smulbb r1, r1, r0
	ldrb r0, [r2, r1]
	orr r0, r0, #1
	strb r0, [r2, r1]
	b _021345E4
_021345E0:
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
_021345E4:
	ldrb r0, [r5, #0x18]
	bic r0, r0, #1
	strb r0, [r5, #0x18]
_021345F0:
	mov r0, #1
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_021345FC: .word 0x0000012A

	arm_func_start ov1_02134600
ov1_02134600: ; 0x02134600
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r8, #0
	mov r7, #1
	mov r5, #6
	mov sl, r0
	mov sb, r1
	mov r6, r8
	mov fp, r7
	mov r4, r5
	arm_func_end ov1_02134600
_02134624:
	add r0, sl, r8, lsl #2
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _02134700
	ldr r0, [r1, #0x104]
	cmp r0, #0
	movne r0, r7
	moveq r0, r6
	cmp r0, #0
	beq _02134700
	ldrb r0, [sl, #0x18]
	tst r0, #1
	beq _02134664
	ldrb r0, [sl, #0x19]
	cmp r0, r8
	beq _02134700
_02134664:
	ldrh r0, [r1, #4]
	tst r0, #0x100
	moveq r0, fp
	movne r0, #0
	cmp r0, #0
	beq _021346D0
	mov r0, sl
	mov r2, sb
	bl ov1_02134820
	cmp r0, #0
	beq _021346D0
	add r3, sl, r8, lsl #2
	mov r1, #0
	ldr r2, [r3, #0x28]
	mov r0, r1
	str r0, [r2, #0xc]
	ldr r0, [r3, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_02127388Ei
	mla r3, r8, r5, sl
	ldrb r2, [r3, #0x38]
	add r0, sl, r8, lsl #2
	mov r1, #0x20
	orr r2, r2, #2
	strb r2, [r3, #0x38]
	ldr r0, [r0, #0x28]
	mov r2, #1
	bl _ZN19CBattleAttackEffect12ov1_02127454Eim
_021346D0:
	mla r0, r8, r4, sl
	ldrb r0, [r0, #0x38]
	tst r0, #2
	beq _02134700
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_0212747CEv
	cmp r0, #0
	bne _02134700
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
_02134700:
	add r0, r8, #1
	and r8, r0, #0xff
	cmp r8, #4
	blo _02134624
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov1_02134714
ov1_02134714: ; 0x02134714
	stmdb sp!, {r3, lr}
	mov lr, #0
	mov r3, lr
	mov ip, #1
	arm_func_end ov1_02134714
_02134724:
	add r2, r0, lr, lsl #2
	ldr r2, [r2, #0x28]
	cmp r2, #0
	beq _0213474C
	ldr r2, [r2, #0x104]
	cmp r2, #0
	movne r2, ip
	moveq r2, r3
	cmp r2, #0
	bne _02134758
_0213474C:
	strb lr, [r1]
	mov r0, #1
	ldmia sp!, {r3, pc}
_02134758:
	add r2, lr, #1
	and lr, r2, #0xff
	cmp lr, #4
	blo _02134724
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start ov1_02134770
ov1_02134770: ; 0x02134770
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r5, r1
	mov r2, #0
	add r1, sp, #0
	mov r6, r0
	strb r2, [sp]
	bl ov1_02134714
	cmp r0, #0
	addeq sp, sp, #4
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, pc}
	mov r0, r6
	bl _ZN13CBattleAssist12ov1_0212EE3CEv
	movs r4, r0
	addeq sp, sp, #4
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, pc}
	ldrb r3, [sp]
	mov r1, #6
	mov lr, #0
	mla r2, r3, r1, r6
	strb lr, [r2, #0x38]
	ldrb ip, [sp]
	mov r2, #0x1f
	mla r3, ip, r1, r6
	strb lr, [r3, #0x39]
	ldrb r3, [sp]
	mla r1, r3, r1, r6
	strh lr, [r1, #0x3c]
	strb r2, [r1, #0x3a]
	ldr r1, [r6, #0xc]
	ldr r1, [r1]
	bl _ZN19CBattleAttackEffect12ov1_021270FCEP23CBattleAttackEffectData
	mov r0, r4
	mov r1, #1
	bl _ZN19CBattleAttackEffect12ov1_02127388Ei
	ldrb r2, [sp]
	mov r0, #1
	add r1, r6, r2, lsl #2
	str r4, [r1, #0x28]
	strb r2, [r5]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	arm_func_end ov1_02134770

	arm_func_start ov1_02134820
ov1_02134820: ; 0x02134820
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x24
	add r3, sp, #0xc
	add r1, r1, #0x430
	mov r8, #0
	mov sl, r0
	mov sb, r2
	ldmia r1, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldr r2, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	add r7, sp, #0x18
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x20]
	sub r4, sp, #4
	mov fp, r8
	mov r6, #1
	mov r5, r8
	arm_func_end ov1_02134820
_02134870:
	ldr r1, [sb, r8, lsl #2]
	cmp r1, #0
	beq _021349C8
	add r0, r1, #0x100
	ldrh r0, [r0, #0x88]
	cmp r0, #0
	movne r0, r6
	moveq r0, fp
	cmp r0, #0
	beq _021349C8
	ldrh r0, [r1, #4]
	tst r0, #0x200
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _021349C8
	add r0, r1, #0x2f8
	str r5, [sp, #8]
	add r0, r0, #0x400
	ldmia r0, {r0, r1, r2}
	stmia r4, {r0, r1, r2}
	ldr r3, [r4]
	ldmia r7, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	beq _021349C8
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r2, _021349E0 ; =MAIN_BSS_020B26A0+32768
	mov r1, r0
	ldrb r2, [r2, #0x7db]
	ldr r0, [sl, #0x10]
	mov r3, #0
	bl _ZN17UnkClass_0212EEB412ov1_0212F32CEitt
	mov r4, r0
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r1, [sb, r8, lsl #2]
	ldr r1, [r1, #0x184]
	ldr r1, [r1, #0x18]
	ldrb r1, [r1, #3]
	bl ov1_0212EE80
	mov r1, r4, lsl #0xc
	mov r4, r0
	smull r1, r0, r4, r1
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	mov r0, r1, lsl #4
	mov r1, r0, lsr #0x10
	ldr r0, [sb, r8, lsl #2]
	mov r2, #1
	bl _ZN12CBattleEnemy12ov1_02126310Eii
	cmp r4, #0x1000
	bne _02134978
	ldr r0, [sl, #0x14]
	ldr r1, _021349E4 ; =0x0000012B
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [sb, r8, lsl #2]
	mov r1, #0
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
	b _021349BC
_02134978:
	ble _0213499C
	ldr r0, [sl, #0x14]
	mov r1, #0x148
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [sb, r8, lsl #2]
	mov r1, #1
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
	b _021349BC
_0213499C:
	bge _021349BC
	ldr r0, [sl, #0x14]
	ldr r1, _021349E8 ; =0x00000149
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [sb, r8, lsl #2]
	mov r1, #2
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
_021349BC:
	add sp, sp, #0x24
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_021349C8:
	add r8, r8, #1
	cmp r8, #8
	blt _02134870
	mov r0, #0
	add sp, sp, #0x24
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_021349E0: .word MAIN_BSS_020B26A0+32768
_021349E4: .word 0x0000012B
_021349E8: .word 0x00000149

	arm_func_start ov1_021349EC
ov1_021349EC: ; 0x021349EC
	mov r0, #0xc
	bx lr
	arm_func_end ov1_021349EC

	arm_func_start ov1_021349F4
ov1_021349F4: ; 0x021349F4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #0x18]
	tst r0, #1
	beq _02134A44
	ldrb r0, [r4, #0x19]
	add r0, r4, r0, lsl #2
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _02134A38
	ldr r1, [r0, #0x104]
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	cmp r1, #0
	beq _02134A38
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
	arm_func_end ov1_021349F4
_02134A38:
	ldrb r0, [r4, #0x18]
	bic r0, r0, #1
	strb r0, [r4, #0x18]
_02134A44:
	ldr r0, [r4, #0x14]
	ldr r1, _02134A78 ; =0x0000012A
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _02134A7C ; =0x0000012B
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	mov r1, #0x148
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _02134A80 ; =0x00000149
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldmia sp!, {r4, pc}
	.align 2, 0
_02134A78: .word 0x0000012A
_02134A7C: .word 0x0000012B
_02134A80: .word 0x00000149

	arm_func_start _ZN18CBattleAssistSteelC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t
_ZN18CBattleAssistSteelC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t: ; 0x02134A84
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldrh ip, [sp, #0x10]
	mov r4, r0
	str ip, [sp]
	bl _ZN13CBattleAssistC2EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t
	ldr r1, _02134AB0 ; =PTR_LAB_overlay_1_02134ab4_overlay_1_02141868
	mov r0, r4
	str r1, [r4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02134AB0: .word PTR_LAB_overlay_1_02134ab4_overlay_1_02141868
	arm_func_end _ZN18CBattleAssistSteelC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t

	arm_func_start ov1_02134AB4
ov1_02134AB4: ; 0x02134AB4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN13CBattleAssistD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_02134AB4

	arm_func_start ov1_02134AC8
ov1_02134AC8: ; 0x02134AC8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN13CBattleAssistD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_02134AC8

	arm_func_start ov1_02134AE4
ov1_02134AE4: ; 0x02134AE4
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0xc
	mov r5, r0
	ldrh r2, [r5, #4]
	mov r4, r1
	cmp r2, #0
	addeq sp, sp, #0xc
	moveq r0, #0
	ldmeqia sp!, {r4, r5, pc}
	sub r2, r2, #1
	mov r1, r3
	strh r2, [r5, #4]
	bl ov1_02134E04
	ldrh r2, [r4, #0xa]
	ldrh r1, [r4, #0xc]
	ldrb r0, [r4, #4]
	sub r2, r2, #0x80
	sub r1, r1, #0x60
	mov r3, r2, lsl #0xc
	mov r2, r1, lsl #0xc
	str r3, [sp, #4]
	str r2, [sp, #8]
	cmp r0, #0
	beq _02134BA4
	str r3, [r5, #0x20]
	str r2, [r5, #0x24]
	mov r2, #0
	add r1, sp, #0
	mov r0, r5
	strb r2, [sp]
	bl ov1_02134F68
	cmp r0, #0
	beq _02134BA4
	ldrb r1, [sp]
	add r0, sp, #4
	strb r1, [r5, #0x19]
	ldrb r3, [sp]
	ldmia r0, {r1, r2}
	add r0, r5, r3, lsl #2
	ldr r0, [r0, #0x28]
	add r0, r0, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldrb r0, [r5, #0x18]
	mov r1, #0x140
	orr r0, r0, #1
	strb r0, [r5, #0x18]
	ldr r0, [r5, #0x14]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	arm_func_end ov1_02134AE4
_02134BA4:
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _02134D1C
	ldrb r0, [r5, #0x18]
	tst r0, #1
	beq _02134CEC
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _02134CEC
	ldr r0, [r0, #0x104]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _02134CEC
	ldr r3, [r5, #0x24]
	ldr r0, [sp, #8]
	ldr r2, [r5, #0x20]
	ldr r1, [sp, #4]
	sub r0, r3, r0
	sub r1, r2, r1
	bl _Z12sub_02007254ll
	cmp r0, #0x5000
	ldrb r1, [r5, #0x19]
	mov r0, #0xc
	ble _02134C30
	smulbb r1, r1, r0
	add r2, r5, #0x3c
	ldr r0, [r2, r1]
	add r0, r0, #0x28
	cmp r0, #0x1000
	strlt r0, [r2, r1]
	b _02134C4C
_02134C30:
	smulbb r2, r1, r0
	add r3, r5, #0x3c
	ldr r1, [r3, r2]
	ldr r0, _02134DFC ; =0x00000333
	sub r1, r1, #0x14
	cmp r1, r0
	strgt r1, [r3, r2]
_02134C4C:
	ldrb r2, [r5, #0x19]
	mov r1, #0xc
	mov r0, r5
	mla r1, r2, r1, r5
	ldr r1, [r1, #0x3c]
	bl ov1_021352B0
	ldrb ip, [r5, #0x19]
	mov r2, #0xc
	mov r1, #0
	mla r3, ip, r2, r5
	strb r0, [r3, #0x40]
	ldrb r0, [r5, #0x19]
	mla r2, r0, r2, r5
	add r0, r5, r0, lsl #2
	ldr r2, [r2, #0x3c]
	ldr r0, [r0, #0x28]
	mov r3, r2
	bl _ZN6CActor12sub_02012A3CEill
	ldrb r1, [r5, #0x19]
	add r0, sp, #4
	add r1, r5, r1, lsl #2
	ldr r3, [r1, #0x28]
	ldmia r0, {r1, r2}
	add r0, r3, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r2, [r0, #0x28]
	cmp r2, #0
	beq _02134CEC
	ldr r0, [r2, #0x104]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _02134CEC
	add r1, sp, #4
	add r0, r2, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
_02134CEC:
	ldrh r0, [r5, #0x1c]
	cmp r0, #0xa
	bne _02134D14
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	str r1, [r5, #0x20]
	str r0, [r5, #0x24]
	mov r0, #0
	strh r0, [r5, #0x1c]
	b _02134D1C
_02134D14:
	addlo r0, r0, #1
	strloh r0, [r5, #0x1c]
_02134D1C:
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _02134DF0
	ldrb r0, [r5, #0x18]
	tst r0, #1
	beq _02134DE4
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _02134DD4
	ldr r1, [r0, #0x104]
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	cmp r1, #0
	beq _02134DD4
	add r1, sp, #4
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r3, [sp, #8]
	ldr r0, [r5, #0x24]
	ldr r2, [sp, #4]
	ldr r1, [r5, #0x20]
	sub r0, r3, r0
	sub r1, r2, r1
	bl FX_Atan2Idx
	ldrb r3, [r5, #0x19]
	mov r1, r0
	mov r2, #0x4000
	add r0, r5, r3, lsl #2
	ldr r0, [r0, #0x28]
	add r0, r0, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011C90Etl
	ldrb r1, [r5, #0x19]
	mov r0, #0xc
	add r3, r5, #0x38
	smulbb r2, r1, r0
	ldrb r0, [r3, r2]
	ldr r1, _02134E00 ; =0x00000141
	orr r0, r0, #1
	strb r0, [r3, r2]
	ldr r0, [r5, #0x14]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _02134DD8
_02134DD4:
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
_02134DD8:
	ldr r0, [r5, #0x14]
	mov r1, #0x140
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
_02134DE4:
	ldrb r0, [r5, #0x18]
	bic r0, r0, #1
	strb r0, [r5, #0x18]
_02134DF0:
	mov r0, #1
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02134DFC: .word 0x00000333
_02134E00: .word 0x00000141

	arm_func_start ov1_02134E04
ov1_02134E04: ; 0x02134E04
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r8, #0
	mov r4, #0xc
	mov sl, r0
	mov sb, r1
	mov r6, r8
	mov r5, #1
	mov fp, r4
	arm_func_end ov1_02134E04
_02134E24:
	add r0, sl, r8, lsl #2
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _02134EF8
	ldr r0, [r1, #0x104]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _02134EF8
	ldrb r0, [sl, #0x18]
	tst r0, #1
	beq _02134E64
	ldrb r0, [sl, #0x19]
	cmp r0, r8
	beq _02134EF8
_02134E64:
	ldrh r0, [r1, #4]
	tst r0, #0x100
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02134EC8
	mla r7, r8, r4, sl
	mov r0, sl
	mov r2, sb
	ldrb r3, [r7, #0x40]
	bl ov1_0213502C
	cmp r0, #0
	beq _02134EC8
	add r2, sl, r8, lsl #2
	ldr r0, [r2, #0x28]
	mov r1, #8
	str r6, [r0, #0xc]
	ldr r0, [r2, #0x28]
	mov r2, #2
	bl _ZN19CBattleAttackEffect12ov1_021273A0Eht
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	mov r1, #0
	bl _ZN19CBattleAttackEffect12ov1_02127388Ei
	strb r5, [r7, #0x39]
_02134EC8:
	mla r0, r8, fp, sl
	ldrb r0, [r0, #0x39]
	cmp r0, #1
	bne _02134EF8
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_0212747CEv
	cmp r0, #0
	bne _02134EF8
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
_02134EF8:
	add r0, r8, #1
	and r8, r0, #0xff
	cmp r8, #4
	blo _02134E24
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov1_02134F0C
ov1_02134F0C: ; 0x02134F0C
	stmdb sp!, {r3, lr}
	mov lr, #0
	mov r3, lr
	mov ip, #1
	arm_func_end ov1_02134F0C
_02134F1C:
	add r2, r0, lr, lsl #2
	ldr r2, [r2, #0x28]
	cmp r2, #0
	beq _02134F44
	ldr r2, [r2, #0x104]
	cmp r2, #0
	movne r2, ip
	moveq r2, r3
	cmp r2, #0
	bne _02134F50
_02134F44:
	strb lr, [r1]
	mov r0, #1
	ldmia sp!, {r3, pc}
_02134F50:
	add r2, lr, #1
	and lr, r2, #0xff
	cmp lr, #4
	blo _02134F1C
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start ov1_02134F68
ov1_02134F68: ; 0x02134F68
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r5, r1
	mov r2, #0
	add r1, sp, #0
	mov r6, r0
	strb r2, [sp]
	bl ov1_02134F0C
	cmp r0, #0
	addeq sp, sp, #4
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, pc}
	mov r0, r6
	bl _ZN13CBattleAssist12ov1_0212EE3CEv
	movs r4, r0
	addeq sp, sp, #4
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, pc}
	ldrb r3, [sp]
	mov r1, #0xc
	mov lr, #0
	mla r2, r3, r1, r6
	strb lr, [r2, #0x38]
	ldrb ip, [sp]
	ldr r2, _02135028 ; =0x00000333
	mla r3, ip, r1, r6
	strb lr, [r3, #0x39]
	ldrb r3, [sp]
	mla r1, r3, r1, r6
	strh lr, [r1, #0x3a]
	str r2, [r1, #0x3c]
	ldr r1, [r6, #0xc]
	ldr r1, [r1]
	bl _ZN19CBattleAttackEffect12ov1_021270FCEP23CBattleAttackEffectData
	mov r0, r4
	mov r1, #7
	mov r2, #2
	bl _ZN19CBattleAttackEffect12ov1_021273A0Eht
	mov r0, r4
	mov r1, #1
	bl _ZN19CBattleAttackEffect12ov1_02127388Ei
	ldrb r2, [sp]
	mov r0, #1
	add r1, r6, r2, lsl #2
	str r4, [r1, #0x28]
	strb r2, [r5]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02135028: .word 0x00000333
	arm_func_end ov1_02134F68

	arm_func_start ov1_0213502C
ov1_0213502C: ; 0x0213502C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x28
	add r4, sp, #0x10
	add r1, r1, #0x430
	mov sl, r0
	mov r8, #0
	mov sb, r2
	ldmia r1, {r0, r1, r2}
	stmia r4, {r0, r1, r2}
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	add r7, sp, #0x1c
	str r3, [sp, #0xc]
	str r2, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	sub r4, sp, #4
	mov fp, r8
	mov r6, #1
	mov r5, r8
	arm_func_end ov1_0213502C
_02135080:
	ldr r1, [sb, r8, lsl #2]
	cmp r1, #0
	beq _02135200
	add r0, r1, #0x100
	ldrh r0, [r0, #0x88]
	cmp r0, #0
	movne r0, r6
	moveq r0, fp
	cmp r0, #0
	beq _02135200
	ldrh r0, [r1, #4]
	tst r0, #0x200
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02135200
	add r0, r1, #0x2f8
	str r5, [sp, #8]
	add r0, r0, #0x400
	ldmia r0, {r0, r1, r2}
	stmia r4, {r0, r1, r2}
	ldr r3, [r4]
	ldmia r7, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	beq _02135200
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r2, _02135218 ; =MAIN_BSS_020B26A0+32768
	mov r1, r0
	ldrb r2, [r2, #0x7db]
	ldr r0, [sl, #0x10]
	ldr r3, [sp, #0xc]
	bl _ZN17UnkClass_0212EEB412ov1_0212F32CEitt
	mov r4, r0
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r1, [sb, r8, lsl #2]
	ldr r1, [r1, #0x184]
	ldr r1, [r1, #0x18]
	ldrb r1, [r1, #3]
	bl ov1_0212EE80
	mov r1, r4, lsl #0xc
	mov r4, r0
	smull r1, r0, r4, r1
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	mov r0, r1, lsl #4
	mov r1, r0, lsr #0x10
	ldr r0, [sb, r8, lsl #2]
	mov r2, #1
	bl _ZN12CBattleEnemy12ov1_02126310Eii
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r1, [sp, #0xc]
	bl ov1_0212EE98
	mov r2, r0
	ldr r0, [sb, r8, lsl #2]
	mov r1, #1
	bl _ZN12CBattleEnemy12ov1_021263A4Eii
	cmp r4, #0x1000
	bne _021351B0
	ldr r0, [sl, #0x14]
	ldr r1, _0213521C ; =0x00000142
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [sb, r8, lsl #2]
	mov r1, #0
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
	b _021351F4
_021351B0:
	ble _021351D4
	ldr r0, [sl, #0x14]
	ldr r1, _02135220 ; =0x0000014E
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [sb, r8, lsl #2]
	mov r1, #1
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
	b _021351F4
_021351D4:
	bge _021351F4
	ldr r0, [sl, #0x14]
	ldr r1, _02135224 ; =0x0000014F
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [sb, r8, lsl #2]
	mov r1, #2
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
_021351F4:
	add sp, sp, #0x28
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02135200:
	add r8, r8, #1
	cmp r8, #8
	blt _02135080
	mov r0, #0
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02135218: .word MAIN_BSS_020B26A0+32768
_0213521C: .word 0x00000142
_02135220: .word 0x0000014E
_02135224: .word 0x0000014F

	arm_func_start ov1_02135228
ov1_02135228: ; 0x02135228
	mov r0, #0x10
	bx lr
	arm_func_end ov1_02135228

	arm_func_start ov1_02135230
ov1_02135230: ; 0x02135230
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #0x18]
	tst r0, #1
	beq _02135260
	ldrb r0, [r4, #0x19]
	add r0, r4, r0, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
	ldrb r0, [r4, #0x18]
	bic r0, r0, #1
	strb r0, [r4, #0x18]
	arm_func_end ov1_02135230
_02135260:
	ldr r0, [r4, #0x14]
	mov r1, #0x140
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _021352A0 ; =0x00000141
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _021352A4 ; =0x00000142
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _021352A8 ; =0x0000014E
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _021352AC ; =0x0000014F
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldmia sp!, {r4, pc}
	.align 2, 0
_021352A0: .word 0x00000141
_021352A4: .word 0x00000142
_021352A8: .word 0x0000014E
_021352AC: .word 0x0000014F

	arm_func_start ov1_021352B0
ov1_021352B0: ; 0x021352B0
	cmp r1, #0x800
	movle r0, #0
	bxle lr
	ldr r0, _021352D0 ; =0x00000E66
	cmp r1, r0
	movle r0, #1
	movgt r0, #2
	bx lr
	.align 2, 0
_021352D0: .word 0x00000E66
	arm_func_end ov1_021352B0

	arm_func_start _ZN18CBattleAssistWaterC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t
_ZN18CBattleAssistWaterC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t: ; 0x021352D4
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldrh ip, [sp, #0x10]
	mov r4, r0
	str ip, [sp]
	bl _ZN13CBattleAssistC2EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t
	ldr r1, _02135300 ; =PTR_LAB_overlay_1_02135304_overlay_1_021418a8
	mov r0, r4
	str r1, [r4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02135300: .word PTR_LAB_overlay_1_02135304_overlay_1_021418a8
	arm_func_end _ZN18CBattleAssistWaterC1EPP19CBattleAttackEffectPP23CBattleAttackEffectDataP17UnkClass_0212EEB4t

	arm_func_start ov1_02135304
ov1_02135304: ; 0x02135304
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN13CBattleAssistD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_02135304

	arm_func_start ov1_02135318
ov1_02135318: ; 0x02135318
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN13CBattleAssistD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_02135318

	arm_func_start ov1_02135334
ov1_02135334: ; 0x02135334
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0xc
	mov r5, r0
	ldrh r2, [r5, #4]
	mov r4, r1
	cmp r2, #0
	addeq sp, sp, #0xc
	moveq r0, #0
	ldmeqia sp!, {r4, r5, pc}
	sub r2, r2, #1
	mov r1, r3
	strh r2, [r5, #4]
	bl ov1_021355B0
	ldrh r2, [r4, #0xa]
	ldrh r1, [r4, #0xc]
	ldrb r0, [r4, #4]
	sub r2, r2, #0x80
	sub r1, r1, #0x60
	mov r3, r2, lsl #0xc
	mov r2, r1, lsl #0xc
	str r3, [sp, #4]
	str r2, [sp, #8]
	cmp r0, #0
	beq _021353F4
	str r3, [r5, #0x20]
	str r2, [r5, #0x24]
	mov r2, #0
	add r1, sp, #0
	mov r0, r5
	strb r2, [sp]
	bl ov1_02135848
	cmp r0, #0
	beq _021353F4
	ldrb r1, [sp]
	add r0, sp, #4
	strb r1, [r5, #0x19]
	ldrb r3, [sp]
	ldmia r0, {r1, r2}
	add r0, r5, r3, lsl #2
	ldr r0, [r0, #0x28]
	add r0, r0, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldrb r0, [r5, #0x18]
	ldr r1, _021355A8 ; =0x00000121
	orr r0, r0, #1
	strb r0, [r5, #0x18]
	ldr r0, [r5, #0x14]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	arm_func_end ov1_02135334
_021353F4:
	ldrb r0, [r4, #5]
	cmp r0, #0
	beq _02135484
	ldrb r0, [r5, #0x18]
	tst r0, #1
	beq _02135484
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r2, [r0, #0x28]
	cmp r2, #0
	beq _02135448
	ldr r0, [r2, #0x104]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _02135448
	add r1, sp, #4
	add r0, r2, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
_02135448:
	ldrb r1, [r5, #0x19]
	mov r0, r5
	bl ov1_02135794
	ldrh r0, [r5, #0x1c]
	cmp r0, #5
	bne _0213547C
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	str r1, [r5, #0x20]
	str r0, [r5, #0x24]
	mov r0, #0
	strh r0, [r5, #0x1c]
	b _02135484
_0213547C:
	addlo r0, r0, #1
	strloh r0, [r5, #0x1c]
_02135484:
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _0213559C
	ldrb r0, [r5, #0x18]
	tst r0, #1
	beq _02135584
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _02135584
	ldr r0, [r0, #0x104]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _02135584
	ldr r4, [sp, #8]
	ldr r0, [r5, #0x24]
	ldr r3, [sp, #4]
	ldr r2, [r5, #0x20]
	sub r1, r4, r0
	sub r0, r3, r2
	bl _Z12sub_02007254ll
	cmp r0, #0x8000
	blt _02135560
	ldrb r1, [r5, #0x19]
	add r0, sp, #4
	add r1, r5, r1, lsl #2
	ldr r3, [r1, #0x28]
	ldmia r0, {r1, r2}
	add r0, r3, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [r5, #0x24]
	ldr r2, [sp, #4]
	ldr r1, [r5, #0x20]
	sub r0, r4, r0
	sub r1, r2, r1
	bl FX_Atan2Idx
	ldrb r3, [r5, #0x19]
	mov r1, r0
	mov r2, #0x2000
	add r0, r5, r3, lsl #2
	ldr r0, [r0, #0x28]
	add r0, r0, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011C90Etl
	ldrb r1, [r5, #0x19]
	mov r0, #0xc
	mov r2, #1
	mla r0, r1, r0, r5
	strb r2, [r0, #0x38]
	ldr r0, [r5, #0x14]
	ldr r1, _021355AC ; =0x00000122
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _02135584
_02135560:
	ldrb r0, [r5, #0x19]
	add r0, r5, r0, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
	ldrb r1, [r5, #0x19]
	mov r0, #0xc
	mov r2, #1
	mla r0, r1, r0, r5
	strb r2, [r0, #0x38]
_02135584:
	ldr r0, [r5, #0x14]
	ldr r1, _021355A8 ; =0x00000121
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldrb r0, [r5, #0x18]
	bic r0, r0, #1
	strb r0, [r5, #0x18]
_0213559C:
	mov r0, #1
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_021355A8: .word 0x00000121
_021355AC: .word 0x00000122

	arm_func_start ov1_021355B0
ov1_021355B0: ; 0x021355B0
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r8, #0
	mov r5, #1
	mov sl, r0
	mov sb, r1
	mov r6, r8
	mov r4, r8
	mov fp, r5
	arm_func_end ov1_021355B0
_021355D0:
	add r0, sl, r8, lsl #2
	ldr r1, [r0, #0x28]
	cmp r1, #0
	beq _02135724
	ldr r0, [r1, #0x104]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _02135724
	ldrb r0, [sl, #0x18]
	tst r0, #1
	beq _02135610
	ldrb r0, [sl, #0x19]
	cmp r0, r8
	beq _02135724
_02135610:
	ldrh r0, [r1, #4]
	tst r0, #0x100
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02135678
	mov r0, #0xc
	mla r7, r8, r0, sl
	ldrb r3, [r7, #0x3a]
	mov r0, sl
	mov r2, sb
	bl ov1_02135938
	cmp r0, #0
	beq _02135678
	add r2, sl, r8, lsl #2
	ldr r0, [r2, #0x28]
	mov r1, #8
	str r6, [r0, #0xc]
	ldr r0, [r2, #0x28]
	mov r2, #2
	bl _ZN19CBattleAttackEffect12ov1_021273A0Eht
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	mov r1, #0
	bl _ZN19CBattleAttackEffect12ov1_02127388Ei
	strb r5, [r7, #0x39]
_02135678:
	add r0, sl, r8, lsl #2
	ldr r2, [r0, #0x28]
	ldrh r0, [r2, #4]
	tst r0, #0x100
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02135704
	mov r0, #0xc
	mla r1, r8, r0, sl
	ldrb r0, [r1, #0x38]
	cmp r0, #1
	bne _02135704
	ldrh r0, [r1, #0x3c]
	cmp r0, #0x78
	bne _021356FC
	str r4, [r2, #0xc]
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	mov r1, #0x20
	mov r2, #1
	bl _ZN19CBattleAttackEffect12ov1_02127454Eim
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	mov r1, #0
	bl _ZN19CBattleAttackEffect12ov1_02127388Ei
	mov r0, #0xc
	mla r1, r8, r0, sl
	strb fp, [r1, #0x39]
	mov r0, #0
	strb r0, [r1, #0x38]
	strh r0, [r1, #0x3c]
	b _02135704
_021356FC:
	addlo r0, r0, #1
	strloh r0, [r1, #0x3c]
_02135704:
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_0212747CEv
	cmp r0, #0
	bne _02135724
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x28]
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
_02135724:
	add r0, r8, #1
	and r8, r0, #0xff
	cmp r8, #4
	blo _021355D0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov1_02135738
ov1_02135738: ; 0x02135738
	stmdb sp!, {r3, lr}
	mov lr, #0
	mov r3, lr
	mov ip, #1
	arm_func_end ov1_02135738
_02135748:
	add r2, r0, lr, lsl #2
	ldr r2, [r2, #0x28]
	cmp r2, #0
	beq _02135770
	ldr r2, [r2, #0x104]
	cmp r2, #0
	movne r2, ip
	moveq r2, r3
	cmp r2, #0
	bne _0213577C
_02135770:
	strb lr, [r1]
	mov r0, #1
	ldmia sp!, {r3, pc}
_0213577C:
	add r2, lr, #1
	and lr, r2, #0xff
	cmp lr, #4
	blo _02135748
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start ov1_02135794
ov1_02135794: ; 0x02135794
	stmdb sp!, {r4, r5, r6, lr}
	mov r2, #0xc
	mul lr, r1, r2
	add ip, r0, #0x3a
	ldrb r4, [ip, lr]
	add r3, r0, #0x3e
	add r2, r0, lr
	cmp r4, #0
	ldrh r6, [r3, lr]
	ldr r2, [r2, #0x40]
	bne _021357EC
	cmp r6, #0x32
	bne _021357D8
	mov r6, #0
	mov r4, #1
	mov r2, #0xc00
	b _02135818
	arm_func_end ov1_02135794
_021357D8:
	bhs _02135818
	add r5, r6, #1
	mov r5, r5, lsl #0x10
	mov r6, r5, lsr #0x10
	b _02135818
_021357EC:
	cmp r4, #1
	bne _02135818
	cmp r6, #0x32
	bne _0213580C
	mov r6, #0
	mov r4, #2
	mov r2, #0x1000
	b _02135818
_0213580C:
	addlo r5, r6, #1
	movlo r5, r5, lsl #0x10
	movlo r6, r5, lsr #0x10
_02135818:
	mov r5, #0xc
	mul r5, r1, r5
	strb r4, [ip, lr]
	add r1, r0, r1, lsl #2
	strh r6, [r3, lr]
	add r0, r0, #0x40
	str r2, [r0, r5]
	ldr r0, [r1, #0x28]
	mov r3, r2
	mov r1, #0
	bl _ZN6CActor12sub_02012A3CEill
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov1_02135848
ov1_02135848: ; 0x02135848
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r5, r1
	mov r2, #0
	add r1, sp, #0
	mov r6, r0
	strb r2, [sp]
	bl ov1_02135738
	cmp r0, #0
	addeq sp, sp, #4
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, pc}
	mov r0, r6
	bl _ZN13CBattleAssist12ov1_0212EE3CEv
	movs r4, r0
	addeq sp, sp, #4
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, pc}
	ldrb ip, [sp]
	mov r2, #0xc
	mov r1, #0
	mla r3, ip, r2, r6
	strb r1, [r3, #0x38]
	ldrb lr, [sp]
	mov r3, #0x800
	mla ip, lr, r2, r6
	strb r1, [ip, #0x39]
	ldrb lr, [sp]
	mla ip, lr, r2, r6
	strb r1, [ip, #0x3a]
	ldrb ip, [sp]
	mla r2, ip, r2, r6
	strh r1, [r2, #0x3c]
	strh r1, [r2, #0x3e]
	str r3, [r2, #0x40]
	ldr r1, [r6, #0xc]
	ldr r1, [r1]
	bl _ZN19CBattleAttackEffect12ov1_021270FCEP23CBattleAttackEffectData
	mov r0, r4
	mov r1, #7
	mov r2, #2
	bl _ZN19CBattleAttackEffect12ov1_021273A0Eht
	mov r0, r4
	mov r1, #1
	bl _ZN19CBattleAttackEffect12ov1_02127388Ei
	ldrb r2, [sp]
	mov r1, #0xc
	mov r0, r4
	mla r1, r2, r1, r6
	ldr r2, [r1, #0x40]
	mov r1, #0
	mov r3, r2
	bl _ZN6CActor12sub_02012A3CEill
	ldrb r2, [sp]
	mov r0, #1
	add r1, r6, r2, lsl #2
	str r4, [r1, #0x28]
	strb r2, [r5]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	arm_func_end ov1_02135848

	arm_func_start ov1_02135938
ov1_02135938: ; 0x02135938
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x28
	add r4, sp, #0x10
	add r1, r1, #0x430
	mov sl, r0
	mov r8, #0
	mov sb, r2
	ldmia r1, {r0, r1, r2}
	stmia r4, {r0, r1, r2}
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	add r7, sp, #0x1c
	str r3, [sp, #0xc]
	str r2, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	sub r4, sp, #4
	mov fp, r8
	mov r6, #1
	mov r5, r8
	arm_func_end ov1_02135938
_0213598C:
	ldr r1, [sb, r8, lsl #2]
	cmp r1, #0
	beq _02135AF4
	add r0, r1, #0x100
	ldrh r0, [r0, #0x88]
	cmp r0, #0
	movne r0, r6
	moveq r0, fp
	cmp r0, #0
	beq _02135AF4
	ldrh r0, [r1, #4]
	tst r0, #0x200
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02135AF4
	add r0, r1, #0x2f8
	str r5, [sp, #8]
	add r0, r0, #0x400
	ldmia r0, {r0, r1, r2}
	stmia r4, {r0, r1, r2}
	ldr r3, [r4]
	ldmia r7, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	beq _02135AF4
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r2, _02135B0C ; =MAIN_BSS_020B26A0+32768
	mov r1, r0
	ldrb r2, [r2, #0x7db]
	ldr r0, [sl, #0x10]
	ldr r3, [sp, #0xc]
	bl _ZN17UnkClass_0212EEB412ov1_0212F32CEitt
	mov r4, r0
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r1, [sb, r8, lsl #2]
	ldr r1, [r1, #0x184]
	ldr r1, [r1, #0x18]
	ldrb r1, [r1, #3]
	bl ov1_0212EE80
	mov r1, r4, lsl #0xc
	mov r4, r0
	smull r1, r0, r4, r1
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	mov r0, r1, lsl #4
	mov r1, r0, lsr #0x10
	ldr r0, [sb, r8, lsl #2]
	mov r2, #1
	bl _ZN12CBattleEnemy12ov1_02126310Eii
	mov r0, sl
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	ldr r1, [sp, #0xc]
	bl ov1_0212EE98
	mov r2, r0
	ldr r0, [sb, r8, lsl #2]
	mov r1, #3
	bl _ZN12CBattleEnemy12ov1_021263A4Eii
	cmp r4, #0x1000
	bne _02135AB0
	ldr r0, [sb, r8, lsl #2]
	mov r1, #0
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
	b _02135ADC
_02135AB0:
	ble _02135AC8
	ldr r0, [sb, r8, lsl #2]
	mov r1, #1
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
	b _02135ADC
_02135AC8:
	bge _02135ADC
	ldr r0, [sb, r8, lsl #2]
	mov r1, #2
	ldr r0, [r0, #0x1a8]
	bl _ZN17UnkClass_0212841412ov1_02128598Ei
_02135ADC:
	ldr r0, [sl, #0x14]
	ldr r1, _02135B10 ; =0x00000123
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #0x28
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02135AF4:
	add r8, r8, #1
	cmp r8, #8
	blt _0213598C
	mov r0, #0
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02135B0C: .word MAIN_BSS_020B26A0+32768
_02135B10: .word 0x00000123

	arm_func_start ov1_02135B14
ov1_02135B14: ; 0x02135B14
	mov r0, #2
	bx lr
	arm_func_end ov1_02135B14

	arm_func_start ov1_02135B1C
ov1_02135B1C: ; 0x02135B1C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #0x18]
	tst r0, #1
	beq _02135B80
	ldrb r0, [r4, #0x19]
	add r0, r4, r0, lsl #2
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _02135B74
	ldr r1, [r0, #0x104]
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	cmp r1, #0
	beq _02135B74
	bl _ZN19CBattleAttackEffect12ov1_02127300Ev
	ldrb r1, [r4, #0x19]
	mov r0, #0xc
	mov r2, #1
	mla r0, r1, r0, r4
	strb r2, [r0, #0x38]
	arm_func_end ov1_02135B1C
_02135B74:
	ldrb r0, [r4, #0x18]
	bic r0, r0, #1
	strb r0, [r4, #0x18]
_02135B80:
	ldr r0, [r4, #0x14]
	ldr r1, _02135BA8 ; =0x00000121
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _02135BAC ; =0x00000122
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x14]
	ldr r1, _02135BB0 ; =0x00000123
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldmia sp!, {r4, pc}
	.align 2, 0
_02135BA8: .word 0x00000121
_02135BAC: .word 0x00000122
_02135BB0: .word 0x00000123

	arm_func_start _ZN17UnkClass_02135BB4C1EP5CGame
_ZN17UnkClass_02135BB4C1EP5CGame: ; 0x02135BB4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	mov r0, #0xb4
	str r4, [r5]
	bl _Znwm
	cmp r0, #0
	beq _02135BE0
	ldr r1, [r4, #0xc24]
	ldr r2, [r4, #0x14]
	bl _ZN17UnkClass_02008FA8C1EP17UnkClass_020023ECm
	arm_func_end _ZN17UnkClass_02135BB4C1EP5CGame
_02135BE0:
	str r0, [r5, #4]
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_02135BB4D1Ev
_ZN17UnkClass_02135BB4D1Ev: ; 0x02135BEC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	bl _ZN17UnkClass_02008FA812sub_02009020Ev
	ldr r4, [r5, #4]
	cmp r4, #0
	beq _02135C24
	beq _02135C1C
	mov r0, r4
	bl _ZN17UnkClass_02008FA8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end _ZN17UnkClass_02135BB4D1Ev
_02135C1C:
	mov r0, #0
	str r0, [r5, #4]
_02135C24:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_02135BB412ov1_02135C2CEv
_ZN17UnkClass_02135BB412ov1_02135C2CEv: ; 0x02135C2C
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	ldr r0, [r4, #4]
	mov r2, r1
	bl _ZN17UnkClass_02008FA812sub_020090E8Eim
	ldr r0, [r4, #4]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_02008FA812sub_020090E8Eim
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_02135BB412ov1_02135C2CEv

	arm_func_start _ZN17UnkClass_02135BB412ov1_02135C58Ev
_ZN17UnkClass_02135BB412ov1_02135C58Ev: ; 0x02135C58
	ldr ip, _02135C64 ; =FUN_02009050
	ldr r0, [r0, #4]
	bx ip
	.align 2, 0
_02135C64: .word _ZN17UnkClass_02008FA812sub_02009050Ev
	arm_func_end _ZN17UnkClass_02135BB412ov1_02135C58Ev

	arm_func_start _ZN17UnkClass_02135BB412ov1_02135C68Ev
_ZN17UnkClass_02135BB412ov1_02135C68Ev: ; 0x02135C68
	ldr ip, _02135C74 ; =FUN_02009108
	ldr r0, [r0, #4]
	bx ip
	.align 2, 0
_02135C74: .word _ZN17UnkClass_02008FA812sub_02009108Ev
	arm_func_end _ZN17UnkClass_02135BB412ov1_02135C68Ev

	arm_func_start _ZN17UnkClass_02135BB412ov1_02135C78Ev
_ZN17UnkClass_02135BB412ov1_02135C78Ev: ; 0x02135C78
	ldr ip, _02135C88 ; =FUN_020090F4
	ldr r0, [r0, #4]
	mov r1, #0
	bx ip
	.align 2, 0
_02135C88: .word _ZN17UnkClass_02008FA812sub_020090F4Ei
	arm_func_end _ZN17UnkClass_02135BB412ov1_02135C78Ev

	arm_func_start _ZN17UnkClass_02135BB412ov1_02135C8CEv
_ZN17UnkClass_02135BB412ov1_02135C8CEv: ; 0x02135C8C
	ldr ip, _02135C9C ; =FUN_020090F4
	ldr r0, [r0, #4]
	mov r1, #1
	bx ip
	.align 2, 0
_02135C9C: .word _ZN17UnkClass_02008FA812sub_020090F4Ei
	arm_func_end _ZN17UnkClass_02135BB412ov1_02135C8CEv

	arm_func_start _ZN17CBattleEnemyGaugeC1EP17UnkClass_021364AC
_ZN17CBattleEnemyGaugeC1EP17UnkClass_021364AC: ; 0x02135CA0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN6CActorC2Ev
	ldr r1, _02135CF8 ; =ptr_FUN_overlay_1_02135d04_overlay_1_021418e4
	add r0, r5, #0x184
	str r1, [r5]
	bl _ZN14CPrimitiveQUADC1Ev
	add r0, r5, #0x20c
	bl _ZN15CSoftwareSpriteC1Ev
	ldr r1, _02135CFC ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r5, #0x258
	str r1, [sp]
	mov r1, #4
	mov r2, #0x4c
	ldr r3, _02135D00 ; =FUN_02005150
	bl __cxa_vec_ctor
	str r4, [r5, #0x1f4]
	mov r0, r5
	bl ov1_02135D8C
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02135CF8: .word ptr_FUN_overlay_1_02135d04_overlay_1_021418e4
_02135CFC: .word _ZN15CSoftwareSpriteD1Ev
_02135D00: .word _ZN15CSoftwareSpriteC1Ev
	arm_func_end _ZN17CBattleEnemyGaugeC1EP17UnkClass_021364AC

	arm_func_start ov1_02135D04
ov1_02135D04: ; 0x02135D04
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02135D40 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x258
	mov r1, #4
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	add r0, r4, #0x20c
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x184
	bl _ZN14CPrimitiveQUADD1Ev
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02135D40: .word _ZN15CSoftwareSpriteD1Ev
	arm_func_end ov1_02135D04

	arm_func_start ov1_02135D44
ov1_02135D44: ; 0x02135D44
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02135D88 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x258
	mov r1, #4
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	add r0, r4, #0x20c
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x184
	bl _ZN14CPrimitiveQUADD1Ev
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02135D88: .word _ZN15CSoftwareSpriteD1Ev
	arm_func_end ov1_02135D44

	arm_func_start ov1_02135D8C
ov1_02135D8C: ; 0x02135D8C
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x18
	ldr r1, _02135E6C ; =0x000003FF
	mov r4, r0
	bl _ZN17CBattleEnemyGauge12ov1_02136248Ei
	mov r1, #0
	add r0, r4, #0x100
	strh r1, [r0, #0xec]
	strh r1, [r0, #0xee]
	strh r1, [r0, #0xf0]
	strb r1, [r4, #0x1f2]
	str r1, [r4, #0x1e4]
	strh r1, [r0, #0xf8]
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r4, #0x1e8]
	mov r2, r1
	add r5, r0, #1
	mov r3, r1
	add r0, r4, #0x184
	str r5, [sp, #0x14]
	bl _ZN14CPrimitiveQUAD20SetVertexCoordinatesElllllllll
	ldr r1, _02135E6C ; =0x000003FF
	add r0, r4, #0x100
	strh r1, [r0, #0x8c]
	mov r0, #0x1f
	str r0, [r4, #0x198]
	ldr r1, [r4, #0x1f4]
	mov r0, #0
	ldr r1, [r1, #0x14]
	add r2, r4, #0x200
	ldmia r1, {r5, r6, ip}
	str r5, [r4, #0x238]
	str r0, [r4, #0x23c]
	str r6, [r4, #0x240]
	mov r3, #0xa
	str ip, [r4, #0x244]
	strh r3, [r2, #0x36]
	mov r3, r0
	mov r2, #0x4c
	arm_func_end ov1_02135D8C
_02135E38:
	mla lr, r0, r2, r4
	ldmib r1, {r5, r6}
	ldr ip, [r1]
	add r0, r0, #1
	str ip, [lr, #0x284]
	str r3, [lr, #0x288]
	and r0, r0, #0xff
	str r5, [lr, #0x28c]
	cmp r0, #4
	str r6, [lr, #0x290]
	blo _02135E38
	add sp, sp, #0x18
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02135E6C: .word 0x000003FF

	arm_func_start _ZN17CBattleEnemyGauge12ov1_02135E70Eitt7Point2D
_ZN17CBattleEnemyGauge12ov1_02135E70Eitt7Point2D: ; 0x02135E70
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x100
	strh r2, [r0, #0xee]
	strh r3, [r0, #0xf0]
	strh r1, [r0, #0xec]
	ldrh r1, [r0, #0xec]
	cmp r1, #8
	addls pc, pc, r1, lsl #2
	b _02135F08
_02135E98: ; jump table
	b _02135F08 ; case 0
	b _02135EBC ; case 1
	b _02135ED0 ; case 2
	b _02135F08 ; case 3
	b _02135EE4 ; case 4
	b _02135F08 ; case 5
	b _02135F08 ; case 6
	b _02135F08 ; case 7
	b _02135EF8 ; case 8
	arm_func_end _ZN17CBattleEnemyGauge12ov1_02135E70Eitt7Point2D
_02135EBC:
	mov r1, #0x19
	strb r1, [r4, #0x1f2]
	mov r1, #0
	strh r1, [r0, #0xf8]
	b _02135F08
_02135ED0:
	mov r1, #0x29
	strb r1, [r4, #0x1f2]
	mov r1, #1
	strh r1, [r0, #0xf8]
	b _02135F08
_02135EE4:
	mov r1, #0x39
	strb r1, [r4, #0x1f2]
	mov r1, #2
	strh r1, [r0, #0xf8]
	b _02135F08
_02135EF8:
	mov r1, #0x99
	strb r1, [r4, #0x1f2]
	mov r1, #3
	strh r1, [r0, #0xf8]
_02135F08:
	add r1, sp, #8
	add r0, r4, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	add r0, r4, #0x100
	ldrh r1, [r0, #0xec]
	orr r1, r1, #0x10
	strh r1, [r0, #0xec]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17CBattleEnemyGauge12ov1_02135F2CEt7Point2D
_ZN17CBattleEnemyGauge12ov1_02135F2CEt7Point2D: ; 0x02135F2C
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, lr}
	add r2, r0, #0x100
	add r3, sp, #0x10
	strh r1, [r2, #0xee]
	add r0, r0, #0xc
	ldmia r3, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldmia sp!, {r3, lr}
	add sp, sp, #0x10
	bx lr
	arm_func_end _ZN17CBattleEnemyGauge12ov1_02135F2CEt7Point2D

	arm_func_start ov1_02135F58
ov1_02135F58: ; 0x02135F58
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x20
	mov r7, r0
	add r0, r7, #0x100
	ldrb r1, [r7, #0x1f2]
	ldrh r2, [r0, #0xf0]
	ldrh r0, [r0, #0xee]
	mov r4, r1, lsl #0xc
	mov r1, r4, asr #0x1f
	sub r0, r2, r0
	mov r3, r0, lsl #0xc
	mov r5, r1, lsl #0xb
	mov r6, r4, lsl #0xb
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	ldr ip, [r7, #0x24]
	ldr lr, [r7, #0x20]
	mov r2, r2, lsl #0xc
	orr r5, r5, r4, lsr #21
	mov r6, r6, lsr #0xc
	orr r6, r6, r5, lsl #20
	sub r5, lr, r6
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	str lr, [sp, #0x18]
	str ip, [sp, #0x1c]
	sub r6, ip, #0x1000
	bl _ll_div
	smull r1, r0, r4, r0
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r7, #0x1fc]
	add r0, r7, #0x100
	ldrh r0, [r0, #0xec]
	mov r2, r6
	tst r0, #8
	addne r5, r5, #0x8000
	add r3, r5, r1
	str r6, [sp]
	str r3, [sp, #4]
	add r0, r6, #0x3000
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x1e8]
	mov r1, r5
	add r0, r0, #1
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	str r0, [sp, #0x14]
	add r0, r7, #0x184
	bl _ZN14CPrimitiveQUAD20SetVertexCoordinatesElllllllll
	ldrb r0, [r7, #0x201]
	cmp r0, #3
	addls pc, pc, r0, lsl #2
	b _02136074
_0213603C: ; jump table
	b _02136074 ; case 0
	b _0213604C ; case 1
	b _0213605C ; case 2
	b _0213606C ; case 3
	arm_func_end ov1_02135F58
_0213604C:
	mov r0, r7
	bl ov1_02136344
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_0213605C:
	mov r0, r7
	bl ov1_021363D0
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_0213606C:
	mov r0, r7
	bl ov1_0213642C
_02136074:
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov1_0213607C
ov1_0213607C: ; 0x0213607C
	add r0, r0, #0x100
	ldrh r0, [r0, #0xec]
	tst r0, #0x10
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end ov1_0213607C

	arm_func_start ov1_02136094
ov1_02136094: ; 0x02136094
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x20
	mov r7, r0
	mov r6, r1
	bl ov1_0213607C
	cmp r0, #0
	addeq sp, sp, #0x20
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r1, [r7, #0x1f4]
	ldr r0, [r7, #0xc4]
	ldr r2, [r1]
	mov r1, #0
	str r2, [r0, #0x2c]
	str r1, [r0, #0x30]
	ldr r1, [r7, #0x1f4]
	add r2, r7, #0x100
	ldr r3, [r1, #4]
	mov r1, r6
	str r3, [r0, #0x34]
	ldr r3, [r7, #0x1f4]
	ldr r3, [r3, #8]
	str r3, [r0, #0x38]
	ldrh r2, [r2, #0xf8]
	strh r2, [r0, #0x2a]
	ldr r2, [r7, #0x20]
	ldr r3, [r7, #0x24]
	str r2, [sp, #0x10]
	str r2, [r0, #0x18]
	str r3, [r0, #0x1c]
	ldr r2, [r0]
	str r3, [sp, #0x14]
	ldr r2, [r2, #8]
	blx r2
	add r0, r7, #0x100
	ldrh r1, [r0, #0xee]
	ldrh r0, [r0, #0xf0]
	cmp r1, r0
	bhs _02136140
	add r0, r7, #0x184
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	arm_func_end ov1_02136094
_02136140:
	ldrb r0, [r7, #0x201]
	cmp r0, #0
	addeq sp, sp, #0x20
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldrb r0, [r7, #0x1f2]
	ldr r3, [r7, #0x24]
	ldr r4, [r7, #0x20]
	mov r1, r0, lsl #0xc
	mov r0, r1, asr #0x1f
	mov r0, r0, lsl #0xb
	mov r2, r1, lsl #0xb
	orr r0, r0, r1, lsr #21
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	sub r0, r4, r1
	add r2, r0, #0x8000
	sub r3, r3, #0x1000
	ldr r1, [r7, #0x208]
	ldr r0, [r7, #0x1fc]
	add r1, r2, r1
	add r4, r1, r0
	str r4, [r7, #0x224]
	str r3, [r7, #0x228]
	add r0, r7, #0x20c
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	str r4, [sp, #0x18]
	str r3, [sp, #0x1c]
	str r4, [sp, #8]
	str r3, [sp, #0xc]
	blx r2
	ldrb r0, [r7, #0x202]
	mov r1, r4
	add r1, r1, #0x5000
	str r1, [sp, #0x18]
	cmp r0, #0
	mov r5, #0
	addls sp, sp, #0x20
	ldmlsia sp!, {r4, r5, r6, r7, r8, pc}
	add r4, r7, #0x258
	mov r8, #0x4c
_021361E8:
	mul r1, r5, r8
	ldr ip, [sp, #0x18]
	add r0, r7, r1
	ldr r3, [sp, #0x1c]
	str ip, [r0, #0x270]
	str r3, [r0, #0x274]
	add r0, r4, r1
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	str ip, [sp]
	str r3, [sp, #4]
	blx r2
	ldr r0, [sp, #0x18]
	add r1, r5, #1
	add r2, r0, #0x5000
	ldrb r0, [r7, #0x202]
	and r5, r1, #0xff
	str r2, [sp, #0x18]
	cmp r5, r0
	blo _021361E8
	add sp, sp, #0x20
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov1_02136244
ov1_02136244: ; 0x02136244
	bx lr
	arm_func_end ov1_02136244

	arm_func_start _ZN17CBattleEnemyGauge12ov1_02136248Ei
_ZN17CBattleEnemyGauge12ov1_02136248Ei: ; 0x02136248
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r5, [r4, #0xc4]
	ldrh r1, [r5, #0x2a]
	mov r0, r5
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	str r0, [r5, #4]
	add r1, r0, #1
	str r1, [r4, #0x188]
	add r5, r0, #2
	str r5, [r4, #0x210]
	mov r2, #0
	mov r1, #0x4c
	arm_func_end _ZN17CBattleEnemyGauge12ov1_02136248Ei
_0213627C:
	mla r3, r2, r1, r4
	add r2, r2, #1
	and r2, r2, #0xff
	str r5, [r3, #0x25c]
	cmp r2, #4
	blo _0213627C
	add r0, r0, #3
	str r0, [r4, #0x1e8]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CBattleEnemyGauge12ov1_021362A0Ei
_ZN17CBattleEnemyGauge12ov1_021362A0Ei: ; 0x021362A0
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	ldr r3, _0213633C ; =0x00002710
	mov r2, r1
	mov r4, r0
	cmp r2, r3
	addlo r0, r4, #0x200
	strloh r2, [r0, #4]
	blo _021362D0
	sub r1, r3, #1
	add r0, r4, #0x200
	strh r1, [r0, #4]
	arm_func_end _ZN17CBattleEnemyGauge12ov1_021362A0Ei
_021362D0:
	mov r0, #0
	strb r0, [r4, #0x200]
	mov r3, #1
	ldr r1, _02136340 ; =s_d_overlay_1_021418f8
	add r0, sp, #0
	strb r3, [r4, #0x201]
	bl OS_SPrintf
	tst r0, #0xff
	addeq sp, sp, #8
	strb r0, [r4, #0x202]
	mov r2, #0
	ldmeqia sp!, {r4, pc}
	add ip, sp, #0
	mov r0, #0x4c
_02136308:
	mla r1, r2, r0, r4
	ldrsb r3, [ip, r2]
	add r1, r1, #0x200
	add r2, r2, #1
	sub r3, r3, #0x30
	and r3, r3, #0xff
	strh r3, [r1, #0x82]
	ldrb r1, [r4, #0x202]
	and r2, r2, #0xff
	cmp r2, r1
	blo _02136308
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213633C: .word 0x00002710
_02136340: .word s_d_overlay_1_021418f8

	arm_func_start ov1_02136344
ov1_02136344: ; 0x02136344
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #0x200]
	add r1, r0, #1
	and r0, r1, #0xff
	strb r1, [r4, #0x200]
	cmp r0, #0xc
	blo _02136374
	mov r0, #0
	strb r0, [r4, #0x200]
	mov r0, #2
	strb r0, [r4, #0x201]
	arm_func_end ov1_02136344
_02136374:
	ldrb r2, [r4, #0x200]
	mov r0, #0x8000
	rsb r0, r0, #0
	mov r1, #0
	mov r3, #0xc
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x208]
	ldrb r2, [r4, #0x200]
	mov r0, #1
	mov r1, #0x1f
	mov r3, #0xc
	bl _Z17LinearInterpolatellll
	and r3, r0, #0xff
	str r3, [r4, #0x220]
	mov r1, #0
	mov r0, #0x4c
_021363B4:
	mla r2, r1, r0, r4
	add r1, r1, #1
	and r1, r1, #0xff
	str r3, [r2, #0x26c]
	cmp r1, #4
	blo _021363B4
	ldmia sp!, {r4, pc}

	arm_func_start ov1_021363D0
ov1_021363D0: ; 0x021363D0
	ldrb r1, [r0, #0x200]
	add r2, r1, #1
	and r1, r2, #0xff
	strb r2, [r0, #0x200]
	cmp r1, #0x20
	blo _021363F8
	mov r1, #0
	strb r1, [r0, #0x200]
	mov r1, #3
	strb r1, [r0, #0x201]
	arm_func_end ov1_021363D0
_021363F8:
	mov r2, #0
	mov r1, #0x1f
	str r2, [r0, #0x208]
	str r1, [r0, #0x220]
	mov ip, r1
	mov r1, #0x4c
_02136410:
	mla r3, r2, r1, r0
	add r2, r2, #1
	and r2, r2, #0xff
	str ip, [r3, #0x26c]
	cmp r2, #4
	blo _02136410
	bx lr

	arm_func_start ov1_0213642C
ov1_0213642C: ; 0x0213642C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #0x200]
	mov r3, #0xc
	add r1, r0, #1
	and r0, r1, #0xff
	strb r1, [r4, #0x200]
	cmp r0, #0xc
	movhs r0, #0
	strcsb r0, [r4, #0x200]
	strcsb r0, [r4, #0x201]
	ldrb r2, [r4, #0x200]
	mov r0, #0
	mov r1, #0x8000
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x208]
	ldrb r2, [r4, #0x200]
	mov r0, #0x1f
	mov r1, #1
	mov r3, #0xc
	bl _Z17LinearInterpolatellll
	and r3, r0, #0xff
	str r3, [r4, #0x220]
	mov r1, #0
	mov r0, #0x4c
	arm_func_end ov1_0213642C
_02136490:
	mla r2, r1, r0, r4
	add r1, r1, #1
	and r1, r1, #0xff
	str r3, [r2, #0x26c]
	cmp r1, #4
	blo _02136490
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_021364ACC1Ev
_ZN17UnkClass_021364ACC1Ev: ; 0x021364AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_021364D4
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021364ACC1Ev

	arm_func_start _ZN17UnkClass_021364ACD1Ev
_ZN17UnkClass_021364ACD1Ev: ; 0x021364C0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_02136678
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021364ACD1Ev

	arm_func_start ov1_021364D4
ov1_021364D4: ; 0x021364D4
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x10
	mov r4, r0
	mov r0, #0x6c
	bl _Znwm
	movs r5, r0
	beq _02136518
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	str ip, [sp, #8]
	ldr r1, _0213664C ; =s_BEG_overlay_1_021418fc
	ldr r2, _02136650 ; =s_data_interface_i000_LZ_bin_overlay_1_02141900
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r5, r0
	arm_func_end ov1_021364D4
_02136518:
	mov r0, #0x3c
	bl _Znwm
	cmp r0, #0
	beq _0213653C
	mov r2, #0
	ldr r1, _02136654 ; =s_BEG_i000_00_NCBR_overlay_1_0214191c
	mov r3, r2
	str r2, [sp]
	bl _ZN17UnkClass_020074D4C1EPKcmmm
_0213653C:
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
	beq _02136590
	mov r2, #0
	ldr r1, _02136658 ; =s_BEG_i000_NCLR_overlay_1_02141930
	mov r3, r2
	bl _ZN17UnkClass_02007AA4C1EPKcmm
_02136590:
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
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _021365EC
	ldr r1, _0213665C ; =s_BEG_i000_00_NCER_overlay_1_02141940
	mov r3, #0
	mov r2, #1
	str r3, [sp]
	bl _ZN9CNCERFileC1EPKcmmm
_021365EC:
	str r0, [r4, #8]
	cmp r5, #0
	beq _02136608
	mov r0, r5
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r5
	bl _ZdlPv
_02136608:
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _02136640
	ldr r2, _02136660 ; =s_BDN_i070_NCLR_overlay_1_02141988
	ldr r1, _02136664 ; =s_BDN_i070_00_NCER_overlay_1_02141998
	str r2, [sp]
	ldr ip, _02136668 ; =s_BDN_i070_00_cac_overlay_1_021419ac
	str r1, [sp, #4]
	ldr r1, _0213666C ; =s_BDN_overlay_1_02141954
	ldr r2, _02136670 ; =s_data_interface_i070_LZ_bin_overlay_1_02141958
	ldr r3, _02136674 ; =s_BDN_i070_00_NCBR_overlay_1_02141974
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_02136640:
	str r0, [r4, #0x14]
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0213664C: .word s_BEG_overlay_1_021418fc
_02136650: .word s_data_interface_i000_LZ_bin_overlay_1_02141900
_02136654: .word s_BEG_i000_00_NCBR_overlay_1_0214191c
_02136658: .word s_BEG_i000_NCLR_overlay_1_02141930
_0213665C: .word s_BEG_i000_00_NCER_overlay_1_02141940
_02136660: .word s_BDN_i070_NCLR_overlay_1_02141988
_02136664: .word s_BDN_i070_00_NCER_overlay_1_02141998
_02136668: .word s_BDN_i070_00_cac_overlay_1_021419ac
_0213666C: .word s_BDN_overlay_1_02141954
_02136670: .word s_data_interface_i070_LZ_bin_overlay_1_02141958
_02136674: .word s_BDN_i070_00_NCBR_overlay_1_02141974

	arm_func_start ov1_02136678
ov1_02136678: ; 0x02136678
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r5, [r4]
	cmp r5, #0
	beq _021366A8
	beq _021366A0
	mov r0, r5
	bl _ZN17UnkClass_020074D4D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov1_02136678
_021366A0:
	mov r0, #0
	str r0, [r4]
_021366A8:
	ldr r5, [r4, #4]
	cmp r5, #0
	beq _021366D0
	beq _021366C8
	mov r0, r5
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r5
	bl _ZdlPv
_021366C8:
	mov r0, #0
	str r0, [r4, #4]
_021366D0:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _021366F4
	beq _021366EC
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_021366EC:
	mov r0, #0
	str r0, [r4, #8]
_021366F4:
	ldr r0, [r4, #0xc]
	bl NNS_GfdFreeLnkTexVram
	ldr r0, [r4, #0x10]
	bl NNS_GfdFreeLnkPlttVram
	ldr r5, [r4, #0x14]
	cmp r5, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _02136724
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_02136724:
	mov r0, #0
	str r0, [r4, #0x14]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_02136730C1Ev
_ZN17UnkClass_02136730C1Ev: ; 0x02136730
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveQUADC1Ev
	mov r1, #0
	mov r0, r4
	strh r1, [r4, #0x80]
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_02136730C1Ev

	arm_func_start _ZN17UnkClass_02136730D1Ev
_ZN17UnkClass_02136730D1Ev: ; 0x0213674C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveQUADD1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_02136730D1Ev

	arm_func_start ov1_02136760
ov1_02136760: ; 0x02136760
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r1, [r4, #0x80]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	ldrh r1, [r4, #0x60]
	tst r1, #1
	beq _02136784
	bl ov1_0213680C
	arm_func_end ov1_02136760
_02136784:
	ldrh r0, [r4, #0x60]
	tst r0, #2
	beq _02136798
	mov r0, r4
	bl ov1_02136840
_02136798:
	ldrh r0, [r4, #0x60]
	tst r0, #4
	beq _021367AC
	mov r0, r4
	bl ov1_02136874
_021367AC:
	ldrh r0, [r4, #0x60]
	tst r0, #8
	beq _021367C0
	mov r0, r4
	bl ov1_021368A8
_021367C0:
	ldrh r0, [r4, #0x60]
	tst r0, #0x10
	beq _021367D4
	mov r0, r4
	bl ov1_021368D0
_021367D4:
	ldrh r0, [r4, #0x60]
	tst r0, #0x20
	beq _021367E8
	mov r0, r4
	bl ov1_021368F8
_021367E8:
	ldrh r0, [r4, #0x60]
	tst r0, #0x80
	beq _021367FC
	mov r0, r4
	bl ov1_021368FC
_021367FC:
	ldrh r0, [r4, #0x80]
	sub r0, r0, #1
	strh r0, [r4, #0x80]
	ldmia sp!, {r4, pc}

	arm_func_start ov1_0213680C
ov1_0213680C: ; 0x0213680C
	ldr r2, [r0, #0x88]
	cmp r2, #0x1000
	beq _0213682C
	ldr r1, [r0, #0x84]
	smull r3, r2, r1, r2
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r0, #0x84]
	arm_func_end ov1_0213680C
_0213682C:
	ldr r2, [r0, #0x64]
	ldr r1, [r0, #0x84]
	add r1, r2, r1
	str r1, [r0, #0x64]
	bx lr

	arm_func_start ov1_02136840
ov1_02136840: ; 0x02136840
	ldr r2, [r0, #0x90]
	cmp r2, #0x1000
	beq _02136860
	ldr r1, [r0, #0x8c]
	smull r3, r2, r1, r2
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r0, #0x8c]
	arm_func_end ov1_02136840
_02136860:
	ldr r2, [r0, #0x68]
	ldr r1, [r0, #0x8c]
	add r1, r2, r1
	str r1, [r0, #0x68]
	bx lr

	arm_func_start ov1_02136874
ov1_02136874: ; 0x02136874
	ldr r2, [r0, #0x98]
	cmp r2, #0x1000
	beq _02136894
	ldr r1, [r0, #0x94]
	smull r3, r2, r1, r2
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r0, #0x94]
	arm_func_end ov1_02136874
_02136894:
	ldr r2, [r0, #0x6c]
	ldr r1, [r0, #0x94]
	add r1, r2, r1
	str r1, [r0, #0x6c]
	bx lr

	arm_func_start ov1_021368A8
ov1_021368A8: ; 0x021368A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r3, [r4, #0x7e]
	ldrh r2, [r4, #0x80]
	ldrb r0, [r4, #0x9c]
	ldrb r1, [r4, #0x9d]
	sub r2, r3, r2
	bl _Z17LinearInterpolatellll
	strb r0, [r4, #0x74]
	ldmia sp!, {r4, pc}
	arm_func_end ov1_021368A8

	arm_func_start ov1_021368D0
ov1_021368D0: ; 0x021368D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r3, [r4, #0x7e]
	ldrh r2, [r4, #0x80]
	ldr r0, [r4, #0xa0]
	ldr r1, [r4, #0xa4]
	sub r2, r3, r2
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x78]
	ldmia sp!, {r4, pc}
	arm_func_end ov1_021368D0

	arm_func_start ov1_021368F8
ov1_021368F8: ; 0x021368F8
	bx lr
	arm_func_end ov1_021368F8

	arm_func_start ov1_021368FC
ov1_021368FC: ; 0x021368FC
	ldr r2, [r0, #0x84]
	ldr r1, [r0, #0xa8]
	add r1, r2, r1
	str r1, [r0, #0x84]
	ldr r2, [r0, #0x8c]
	ldr r1, [r0, #0xac]
	add r1, r2, r1
	str r1, [r0, #0x8c]
	ldr r2, [r0, #0x94]
	ldr r1, [r0, #0xb0]
	add r1, r2, r1
	str r1, [r0, #0x94]
	bx lr
	arm_func_end ov1_021368FC

	arm_func_start ov1_02136930
ov1_02136930: ; 0x02136930
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x18
	mov r6, r0
	ldrh r3, [r6, #0x80]
	mov r5, r1
	mov r4, r2
	cmp r3, #0
	ldrneb r1, [r6, #0x74]
	cmpne r1, #0
	addeq sp, sp, #0x18
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldrh r1, [r6, #0x7c]
	ldr ip, _021369F8 ; =0x000003FF
	strh r1, [r6, #8]
	ldrb r1, [r6, #0x74]
	str r1, [r6, #0x14]
	ldr r2, [r6, #0x70]
	ldr r1, [r6, #0x78]
	ldr lr, [r6, #0x6c]
	smull r1, r7, r2, r1
	mov r3, r1, lsr #0xc
	ldr r2, [r6, #0x68]
	ldr r1, [r6, #0x64]
	add lr, r2, lr
	orr r3, r3, r7, lsl #20
	str lr, [sp]
	str r1, [sp, #4]
	add r2, r3, lr
	str r2, [sp, #8]
	sub r2, r1, r3
	str r2, [sp, #0xc]
	str lr, [sp, #0x10]
	sub r2, lr, r3
	add r3, r1, r3
	str ip, [sp, #0x14]
	bl _ZN14CPrimitiveQUAD20SetVertexCoordinatesElllllllll
	cmp r4, #0
	mov r0, r6
	beq _021369E0
	mov r1, r5
	mov r2, r4
	bl _ZN14CPrimitiveQUAD8RenderDLEP8Camera2DP8GXDLInfo
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end ov1_02136930
_021369E0:
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #8]
	blx r2
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_021369F8: .word 0x000003FF

	arm_func_start ov1_021369FC
ov1_021369FC: ; 0x021369FC
	mov ip, #0
	strh ip, [r0, #0x60]
	str r2, [r0, #0x64]
	ldr ip, [sp]
	str r3, [r0, #0x68]
	ldr r2, [sp, #4]
	str ip, [r0, #0x6c]
	ldrh r3, [sp, #8]
	str r2, [r0, #0x70]
	mov r2, #0x1f
	strh r3, [r0, #0x7c]
	strb r2, [r0, #0x74]
	mov r2, #0x1000
	str r2, [r0, #0x78]
	strh r1, [r0, #0x7e]
	strh r1, [r0, #0x80]
	bx lr
	arm_func_end ov1_021369FC

	arm_func_start _ZN17UnkClass_0213673012ov1_02136A40Ell
_ZN17UnkClass_0213673012ov1_02136A40Ell: ; 0x02136A40
	ldrh r3, [r0, #0x60]
	orr r3, r3, #1
	strh r3, [r0, #0x60]
	str r1, [r0, #0x84]
	str r2, [r0, #0x88]
	bx lr
	arm_func_end _ZN17UnkClass_0213673012ov1_02136A40Ell

	arm_func_start _ZN17UnkClass_0213673012ov1_02136A58Ell
_ZN17UnkClass_0213673012ov1_02136A58Ell: ; 0x02136A58
	ldrh r3, [r0, #0x60]
	orr r3, r3, #2
	strh r3, [r0, #0x60]
	str r1, [r0, #0x8c]
	str r2, [r0, #0x90]
	bx lr
	arm_func_end _ZN17UnkClass_0213673012ov1_02136A58Ell

	arm_func_start _ZN17UnkClass_0213673012ov1_02136A70Ell
_ZN17UnkClass_0213673012ov1_02136A70Ell: ; 0x02136A70
	ldrh r3, [r0, #0x60]
	orr r3, r3, #4
	strh r3, [r0, #0x60]
	str r1, [r0, #0x94]
	str r2, [r0, #0x98]
	bx lr
	arm_func_end _ZN17UnkClass_0213673012ov1_02136A70Ell

	arm_func_start _ZN17UnkClass_0213673012ov1_02136A88Ehh
_ZN17UnkClass_0213673012ov1_02136A88Ehh: ; 0x02136A88
	ldrh r3, [r0, #0x60]
	orr r3, r3, #8
	strh r3, [r0, #0x60]
	strb r1, [r0, #0x9c]
	strb r2, [r0, #0x9d]
	bx lr
	arm_func_end _ZN17UnkClass_0213673012ov1_02136A88Ehh

	arm_func_start _ZN17UnkClass_0213673012ov1_02136AA0Eli
_ZN17UnkClass_0213673012ov1_02136AA0Eli: ; 0x02136AA0
	ldrh r3, [r0, #0x60]
	orr r3, r3, #0x10
	strh r3, [r0, #0x60]
	str r1, [r0, #0xa0]
	str r2, [r0, #0xa4]
	bx lr
	arm_func_end _ZN17UnkClass_0213673012ov1_02136AA0Eli

	arm_func_start _ZN17UnkClass_0213673012ov1_02136AB8Elli
_ZN17UnkClass_0213673012ov1_02136AB8Elli: ; 0x02136AB8
	ldrh ip, [r0, #0x60]
	orr ip, ip, #0x80
	strh ip, [r0, #0x60]
	str r1, [r0, #0xa8]
	str r2, [r0, #0xac]
	str r3, [r0, #0xb0]
	bx lr
	arm_func_end _ZN17UnkClass_0213673012ov1_02136AB8Elli

	arm_func_start _ZN17UnkClass_02136AD4C1EPP17UnkClass_02136730i
_ZN17UnkClass_02136AD4C1EPP17UnkClass_02136730i: ; 0x02136AD4
	strh r2, [r0]
	str r1, [r0, #4]
	mov r1, #0
	strh r1, [r0, #8]
	bx lr
	arm_func_end _ZN17UnkClass_02136AD4C1EPP17UnkClass_02136730i

	arm_func_start _ZN17UnkClass_02136AD4D1Ev
_ZN17UnkClass_02136AD4D1Ev: ; 0x02136AE8
	bx lr
	arm_func_end _ZN17UnkClass_02136AD4D1Ev

	arm_func_start _ZN17UnkClass_02136AD412ov1_02136AECEv
_ZN17UnkClass_02136AD412ov1_02136AECEv: ; 0x02136AEC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldrh r0, [r5]
	mov r4, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_02136AD412ov1_02136AECEv
_02136B04:
	ldr r0, [r5, #4]
	ldr r0, [r0, r4, lsl #2]
	bl ov1_02136760
	ldrh r0, [r5]
	add r4, r4, #1
	cmp r4, r0
	blt _02136B04
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_02136AD412ov1_02136B24Eillilt
_ZN17UnkClass_02136AD412ov1_02136B24Eillilt: ; 0x02136B24
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0xc
	mov r5, r0
	ldrh r0, [r5, #8]
	ldr r4, [r5, #4]
	ldr ip, [sp, #0x18]
	ldr r4, [r4, r0, lsl #2]
	ldr r0, [sp, #0x1c]
	str ip, [sp]
	ldrh ip, [sp, #0x20]
	str r0, [sp, #4]
	mov r0, r4
	str ip, [sp, #8]
	bl ov1_021369FC
	ldrh r0, [r5, #8]
	add r0, r0, #1
	strh r0, [r5, #8]
	ldrh r1, [r5, #8]
	ldrh r0, [r5]
	cmp r1, r0
	movhs r0, #0
	strhsh r0, [r5, #8]
	mov r0, r4
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, pc}
	arm_func_end _ZN17UnkClass_02136AD412ov1_02136B24Eillilt

	arm_func_start _ZN17UnkClass_02136AD412ov1_02136B88EP8Camera2D
_ZN17UnkClass_02136AD412ov1_02136B88EP8Camera2D: ; 0x02136B88
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldrh r0, [r7]
	mov r6, r1
	mov r5, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r4, r5
	arm_func_end _ZN17UnkClass_02136AD412ov1_02136B88EP8Camera2D
_02136BA8:
	ldr r0, [r7, #4]
	mov r1, r6
	ldr r0, [r0, r5, lsl #2]
	mov r2, r4
	bl ov1_02136930
	ldrh r0, [r7]
	add r5, r5, #1
	cmp r5, r0
	blt _02136BA8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17UnkClass_02136AD412ov1_02136BD0Ei
_ZN17UnkClass_02136AD412ov1_02136BD0Ei: ; 0x02136BD0
	ldrh r2, [r0]
	mov r3, #0
	cmp r2, #0
	bxle lr
	arm_func_end _ZN17UnkClass_02136AD412ov1_02136BD0Ei
_02136BE0:
	ldr r2, [r0, #4]
	ldr r2, [r2, r3, lsl #2]
	add r3, r3, #1
	str r1, [r2, #0x10]
	ldrh r2, [r0]
	cmp r3, r2
	blt _02136BE0
	bx lr

	arm_func_start _ZN16CBattlePowerSaveC1Ev
_ZN16CBattlePowerSaveC1Ev: ; 0x02136C00
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r4, r0
	bl _ZN6CActorC2Ev
	ldr r1, _02136D20 ; =ptr_FUN_overlay_1_02136d60_overlay_1_02141a04
	add r0, r4, #0x214
	str r1, [r4]
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x260
	bl _ZN15CSoftwareSpriteC1Ev
	ldr r1, _02136D24 ; =ov1_02136D48
	ldr r3, _02136D28 ; =ov1_02136D30
	str r1, [sp]
	add r0, r4, #0x2b0
	mov r1, #0x30
	mov r2, #0x34
	bl __cxa_vec_ctor
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r1, [r0, #0x48c]
	mov r0, r4
	str r1, [r4, #0x184]
	bl ov1_021371C4
	mov r0, r4
	bl ov1_02136E08
	mov r6, #0
	mov r5, #0xb4
	arm_func_end _ZN16CBattlePowerSaveC1Ev
_02136C6C:
	mov r0, r5
	bl _Znwm
	cmp r0, #0
	beq _02136C80
	bl _ZN17UnkClass_02136730C1Ev
_02136C80:
	add r1, r4, r6, lsl #2
	add r6, r6, #1
	str r0, [r1, #0x1b4]
	cmp r6, #0x14
	blt _02136C6C
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02136CB0
	add r1, r4, #0x1b4
	mov r2, #0x14
	bl _ZN17UnkClass_02136AD4C1EPP17UnkClass_02136730i
_02136CB0:
	mov r1, #1
	str r0, [r4, #0x204]
	bl _ZN17UnkClass_02136AD412ov1_02136BD0Ei
	mov r0, #2
	strb r0, [r4, #0xc71]
	mov r5, #0
	add r0, r4, #0xc00
	mov r1, #0x64
	strh r1, [r0, #0x74]
	mov r1, #0x78
	strh r1, [r0, #0x76]
	ldr r3, _02136D2C ; =0x000013FF
	strb r5, [r4, #0x2ac]
	mov ip, r5
	mov r2, #1
	mov r0, #0x34
_02136CF0:
	mla lr, r5, r0, r4
	add r1, r5, #1
	and r5, r1, #0xff
	strb ip, [lr, #0x2b0]
	add r1, lr, #0x200
	strh r3, [r1, #0xc4]
	str r2, [lr, #0x2cc]
	cmp r5, #0x30
	blo _02136CF0
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02136D20: .word ptr_FUN_overlay_1_02136d60_overlay_1_02141a04
_02136D24: .word ov1_02136D48
_02136D28: .word ov1_02136D30
_02136D2C: .word 0x000013FF

	arm_func_start ov1_02136D30
ov1_02136D30: ; 0x02136D30
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0xc
	bl _ZN14CPrimitiveLINEC1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_02136D30

	arm_func_start ov1_02136D48
ov1_02136D48: ; 0x02136D48
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0xc
	bl _ZN14CPrimitiveLINED1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov1_02136D48

	arm_func_start ov1_02136D60
ov1_02136D60: ; 0x02136D60
	stmdb sp!, {r4, lr}
	ldr r1, _02136DA8 ; =ptr_FUN_overlay_1_02136d60_overlay_1_02141a04
	mov r4, r0
	str r1, [r4]
	bl ov1_02136FB8
	ldr r3, _02136DAC ; =ov1_02136D48
	add r0, r4, #0x2b0
	mov r1, #0x30
	mov r2, #0x34
	bl __cxa_vec_cleanup
	add r0, r4, #0x260
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x214
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02136DA8: .word ptr_FUN_overlay_1_02136d60_overlay_1_02141a04
_02136DAC: .word ov1_02136D48
	arm_func_end ov1_02136D60

	arm_func_start ov1_02136DB0
ov1_02136DB0: ; 0x02136DB0
	stmdb sp!, {r4, lr}
	ldr r1, _02136E00 ; =ptr_FUN_overlay_1_02136d60_overlay_1_02141a04
	mov r4, r0
	str r1, [r4]
	bl ov1_02136FB8
	ldr r3, _02136E04 ; =ov1_02136D48
	add r0, r4, #0x2b0
	mov r1, #0x30
	mov r2, #0x34
	bl __cxa_vec_cleanup
	add r0, r4, #0x260
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x214
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02136E00: .word ptr_FUN_overlay_1_02136d60_overlay_1_02141a04
_02136E04: .word ov1_02136D48
	arm_func_end ov1_02136DB0

	arm_func_start ov1_02136E08
ov1_02136E08: ; 0x02136E08
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x1ec
	ldr r8, _02136F84 ; =ptr_s_PSE_overlay_1_021419c8_overlay_1_021419cc
	ldr r7, _02136F88 ; =ptr_s_00_overlay_1_021419c0_overlay_1_021419d4
	mov sl, r0
	mov sb, #0
	add r6, sp, #0xcc
	add r5, sp, #0x6c
	add r4, sp, #0xc
	add fp, sp, #0x18c
	arm_func_end ov1_02136E08
_02136E30:
	ldr r1, _02136F8C ; =s_data_interface_i025_LZ_bin_overlay_1_02141a18
	mov r0, fp
	bl OS_SPrintf
	ldr r1, _02136F90 ; =s_s_i025_s_NCBR_overlay_1_02141a34
	ldr r2, [r8, sb, lsl #2]
	ldr r3, [r7, sb, lsl #2]
	add r0, sp, #0x12c
	bl OS_SPrintf
	ldr r1, _02136F94 ; =s_s_i025_NCLR_overlay_1_02141a44
	ldr r2, [r8, sb, lsl #2]
	mov r0, r6
	bl OS_SPrintf
	ldr r1, _02136F98 ; =s_s_i025_s_NCER_overlay_1_02141a54
	ldr r2, [r8, sb, lsl #2]
	ldr r3, [r7, sb, lsl #2]
	mov r0, r5
	bl OS_SPrintf
	ldr r1, _02136F9C ; =s_s_i025_s_cac_overlay_1_02141a64
	ldr r2, [r8, sb, lsl #2]
	ldr r3, [r7, sb, lsl #2]
	mov r0, r4
	bl OS_SPrintf
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _02136EB4
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	ldr r1, [r8, sb, lsl #2]
	mov r2, fp
	add r3, sp, #0x12c
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_02136EB4:
	add r1, sl, sb, lsl #2
	str r0, [r1, #0x188]
	ldr r0, [r0, #0xc]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, sl, sb, lsl #1
	add r1, r1, #0x100
	add sb, sb, #1
	strh r0, [r1, #0xb0]
	cmp sb, #2
	blt _02136E30
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _02136F1C
	ldr r2, _02136FA0 ; =s_BLD_i066_NCLR_overlay_1_02141aa8
	ldr r1, _02136FA4 ; =s_BLD_i066_00_NCER_overlay_1_02141ab8
	str r2, [sp]
	ldr r4, _02136FA8 ; =s_BLD_i066_00_cac_overlay_1_02141acc
	str r1, [sp, #4]
	ldr r1, _02136FAC ; =s_BLD_overlay_1_02141a74
	ldr r2, _02136FB0 ; =s_data_interface_i066_LZ_bin_overlay_1_02141a78
	ldr r3, _02136FB4 ; =s_BLD_i066_00_NCBR_overlay_1_02141a94
	str r4, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_02136F1C:
	str r0, [sl, #0x210]
	ldmia r0, {r0, r1, r3}
	str r0, [sl, #0x240]
	mov r2, #0
	str r2, [sl, #0x244]
	str r1, [sl, #0x248]
	mov r1, #1
	str r3, [sl, #0x24c]
	add r0, sl, #0x200
	strh r1, [r0, #0x3e]
	rsb r5, r1, #0x400
	str r5, [sl, #0x218]
	ldr r0, [sl, #0x210]
	ldmia r0, {r0, r3, r4}
	str r0, [sl, #0x28c]
	str r2, [sl, #0x290]
	str r3, [sl, #0x294]
	str r4, [sl, #0x298]
	str r5, [sl, #0x264]
	ldr r0, [sl, #0x210]
	ldr r0, [r0, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, sl, #0x200
	strh r0, [r1, #0xe]
	add sp, sp, #0x1ec
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02136F84: .word ptr_s_PSE_overlay_1_021419c8_overlay_1_021419cc
_02136F88: .word ptr_s_00_overlay_1_021419c0_overlay_1_021419d4
_02136F8C: .word s_data_interface_i025_LZ_bin_overlay_1_02141a18
_02136F90: .word s_s_i025_s_NCBR_overlay_1_02141a34
_02136F94: .word s_s_i025_NCLR_overlay_1_02141a44
_02136F98: .word s_s_i025_s_NCER_overlay_1_02141a54
_02136F9C: .word s_s_i025_s_cac_overlay_1_02141a64
_02136FA0: .word s_BLD_i066_NCLR_overlay_1_02141aa8
_02136FA4: .word s_BLD_i066_00_NCER_overlay_1_02141ab8
_02136FA8: .word s_BLD_i066_00_cac_overlay_1_02141acc
_02136FAC: .word s_BLD_overlay_1_02141a74
_02136FB0: .word s_data_interface_i066_LZ_bin_overlay_1_02141a78
_02136FB4: .word s_BLD_i066_00_NCBR_overlay_1_02141a94

	arm_func_start ov1_02136FB8
ov1_02136FB8: ; 0x02136FB8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, #0
	mov r4, r0
	mov r5, r6
	arm_func_end ov1_02136FB8
_02136FC8:
	add r0, r4, r6, lsl #2
	ldr r7, [r0, #0x1b4]
	cmp r7, #0
	beq _02136FF4
	beq _02136FEC
	mov r0, r7
	bl _ZN17UnkClass_02136730D1Ev
	mov r0, r7
	bl _ZdlPv
_02136FEC:
	add r0, r4, r6, lsl #2
	str r5, [r0, #0x1b4]
_02136FF4:
	add r6, r6, #1
	cmp r6, #0x14
	blt _02136FC8
	ldr r5, [r4, #0x204]
	cmp r5, #0
	beq _02137028
	beq _02137020
	mov r0, r5
	bl _ZN17UnkClass_02136AD4D1Ev
	mov r0, r5
	bl _ZdlPv
_02137020:
	mov r0, #0
	str r0, [r4, #0x204]
_02137028:
	mov r6, #0
	mov r5, r6
_02137030:
	add r0, r4, r6, lsl #2
	ldr r7, [r0, #0x188]
	cmp r7, #0
	beq _0213705C
	beq _02137054
	mov r0, r7
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r7
	bl _ZdlPv
_02137054:
	add r0, r4, r6, lsl #2
	str r5, [r0, #0x188]
_0213705C:
	add r6, r6, #1
	cmp r6, #2
	blt _02137030
	ldr r5, [r4, #0x210]
	cmp r5, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	beq _02137088
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_02137088:
	mov r0, #0
	str r0, [r4, #0x210]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN16CBattlePowerSave12ov1_02137094E7Point2D
_ZN16CBattlePowerSave12ov1_02137094E7Point2D: ; 0x02137094
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r1, r4, #0x100
	ldrh r2, [r1, #0xa8]
	tst r2, #1
	beq _021370E4
	add r1, sp, #0xc
	ldmia r1, {r1, r2}
	bl ov1_021374FC
	cmp r0, #0
	bne _02137118
	add r0, r4, #0x100
	ldrh r2, [r0, #0xa8]
	mov r1, #0
	bic r2, r2, #3
	strh r2, [r0, #0xa8]
	strb r1, [r4, #0xc72]
	strh r1, [r0, #0xac]
	b _02137118
	arm_func_end _ZN16CBattlePowerSave12ov1_02137094E7Point2D
_021370E4:
	orr r0, r2, #1
	ldr r2, [sp, #0xc]
	strh r0, [r1, #0xa8]
	ldr r0, [sp, #0x10]
	str r2, [r4, #0x190]
	str r0, [r4, #0x194]
	ldr r0, [r4, #0x184]
	mov r1, #0x32
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	bic r1, r1, #0x10
	strh r1, [r0, #0xa8]
_02137118:
	add r1, sp, #0xc
	add r0, r4, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	str r1, [r4, #0x1a0]
	str r0, [r4, #0x1a4]
	ldmia sp!, {r4, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start _ZN16CBattlePowerSave12ov1_02137144Ev
_ZN16CBattlePowerSave12ov1_02137144Ev: ; 0x02137144
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r1, r4, #0x100
	ldrh r3, [r1, #0xa8]
	mov r2, #0
	bic r3, r3, #3
	strh r3, [r1, #0xa8]
	strb r2, [r4, #0xc72]
	bl _ZN16CBattlePowerSave12ov1_021371F0Ev
	ldr r0, [r4, #0x184]
	mov r1, #0x32
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	bic r1, r1, #0x10
	strh r1, [r0, #0xa8]
	ldrh r1, [r0, #0xa8]
	bic r1, r1, #0x20
	strh r1, [r0, #0xa8]
	ldmia sp!, {r4, pc}
	arm_func_end _ZN16CBattlePowerSave12ov1_02137144Ev

	arm_func_start ov1_02137194
ov1_02137194: ; 0x02137194
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x100
	ldr r2, [r4, #0x18c]
	ldrh r1, [r0, #0xb2]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	orr r1, r1, #4
	strh r1, [r0, #0xa8]
	ldmia sp!, {r4, pc}
	arm_func_end ov1_02137194

	arm_func_start ov1_021371C4
ov1_021371C4: ; 0x021371C4
	add r1, r0, #0x100
	mov r2, #0
	strh r2, [r1, #0xa8]
	strh r2, [r1, #0xaa]
	strh r2, [r1, #0xac]
	strb r2, [r0, #0xc70]
	strb r2, [r0, #0xc72]
	mov r1, #0xf
	strb r1, [r0, #0xc7c]
	str r2, [r0, #0xc78]
	bx lr
	arm_func_end ov1_021371C4

	arm_func_start _ZN16CBattlePowerSave12ov1_021371F0Ev
_ZN16CBattlePowerSave12ov1_021371F0Ev: ; 0x021371F0
	add r1, r0, #0xc00
	mov r2, #0
	strh r2, [r1, #0x7e]
	strb r2, [r0, #0xc70]
	add r0, r0, #0x100
	strh r2, [r0, #0xac]
	bx lr
	arm_func_end _ZN16CBattlePowerSave12ov1_021371F0Ev

	arm_func_start ov1_0213720C
ov1_0213720C: ; 0x0213720C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x30
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x460
	add r1, r1, #0x1000
	ldmib r1, {r5, r6}
	ldr r3, [r2, #0x460]
	ldr r1, _021373E8 ; =0x000036B0
	mla r6, r5, r3, r6
	mov r3, r6, lsr #0x10
	ldr r8, [r4, #0x1a0]
	ldr r7, [r4, #0x1a4]
	add r0, r0, #0x48
	str r6, [r2, #0x460]
	mul r1, r3, r1
	add lr, r0, #0x1400
	mov r0, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r1, r0, lsr #0x10
	ldr r0, [lr, #8]
	mov r5, #0
	str r0, [sp, #0xc]
	mov r0, r5, lsl #0x10
	ldr r3, [r2, #0x448]
	ldr sl, [sp, #0xc]
	ldr r5, _021373EC ; =0xFFFFE4A8
	mov r1, r1, lsl #0x10
	add r1, r5, r1, asr #16
	ldr r5, [lr, #0x14]
	umull sb, ip, sl, r3
	str r5, [sp, #0x20]
	ldr r5, [lr, #0xc]
	str sb, [sp, #0x24]
	str r5, [sp, #0x10]
	ldr r5, [lr, #4]
	mov r6, #0xc000
	str r5, [sp, #0x14]
	ldr sb, [sp, #0x14]
	mov r1, r1, lsl #0x10
	mla ip, sl, sb, ip
	ldr sb, [sp, #0x10]
	add r1, r6, r1, asr #16
	mla ip, sb, r3, ip
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	mov r1, r1, asr #4
	mov r1, r1, lsl #1
	add r5, r1, #1
	mov r6, r5, lsl #1
	ldr r5, _021373F0 ; =FX_SinCosTable_
	ldr fp, [lr, #0x10]
	ldr r3, [sp, #0x24]
	ldrsh r6, [r5, r6]
	adds r3, fp, r3
	str r3, [r2, #0x448]
	ldr r2, [sp, #0x20]
	mov r1, r1, lsl #1
	adc r3, r2, ip
	ldrsh r5, [r5, r1]
	mov r1, r6, asr #0x1f
	str r1, [sp, #0x1c]
	mov r1, r5, asr #0x1f
	str r1, [sp, #0x18]
	str r3, [lr, #4]
	mov r2, #0
	str r2, [sp]
	mov r2, #0x3000
	str r2, [sp, #4]
	ldr r2, _021373F4 ; =0x000013FF
	orr r0, r0, r3, lsr #16
	str r2, [sp, #8]
	add r3, r0, #0x18000
	ldr r0, [r4, #0x204]
	smull r4, r2, r3, r6
	mov r4, r4, lsr #0xc
	orr r4, r4, r2, lsl #20
	str r8, [sp, #0x28]
	add r2, r8, r4
	smull r8, r4, r3, r5
	mov r3, r8, lsr #0xc
	orr r3, r3, r4, lsl #20
	mov r1, #0x14
	add r3, r7, r3
	str r7, [sp, #0x2c]
	bl _ZN17UnkClass_02136AD412ov1_02136B24Eillilt
	ldr r3, _021373F8 ; =0xFFFFECCD
	mvn r1, #0
	umull r8, r7, r6, r3
	mla r7, r6, r1, r7
	ldr r1, [sp, #0x1c]
	mov r2, #0x1000
	mla r7, r1, r3, r7
	mov r1, r8, lsr #0xc
	orr r1, r1, r7, lsl #20
	mov r4, r0
	bl _ZN17UnkClass_0213673012ov1_02136A40Ell
	ldr r1, _021373F8 ; =0xFFFFECCD
	mvn r0, #0
	umull r3, r2, r5, r1
	mla r2, r5, r0, r2
	ldr r0, [sp, #0x18]
	mla r2, r0, r1, r2
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	mov r0, r4
	mov r2, #0x1000
	bl _ZN17UnkClass_0213673012ov1_02136A58Ell
	mov r0, r4
	mov r1, #0xc
	mov r2, #0x1f
	bl _ZN17UnkClass_0213673012ov1_02136A88Ehh
	mov r0, r4
	mov r1, #0x1000
	mov r2, #4
	bl _ZN17UnkClass_0213673012ov1_02136AA0Eli
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_021373E8: .word 0x000036B0
_021373EC: .word 0xFFFFE4A8
_021373F0: .word FX_SinCosTable_
_021373F4: .word 0x000013FF
_021373F8: .word 0xFFFFECCD
	arm_func_end ov1_0213720C

	arm_func_start ov1_021373FC
ov1_021373FC: ; 0x021373FC
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	ldrb r2, [r4, #0x2ac]
	mov r1, #0x34
	add r5, r4, #0x2b0
	smulbb r2, r2, r1
	mov r1, #1
	strb r1, [r5, r2]
	add r3, r0, #0x460
	add r2, r5, r2
	mov r1, #0
	strh r1, [r2, #2]
	add lr, r0, #0x1000
	add r3, r3, #0x1000
	ldmib r3, {r6, r7}
	ldr r5, [lr, #0x460]
	ldr r3, _021374F4 ; =0x000036B0
	mla r7, r6, r5, r7
	mov r5, r7, lsr #0x10
	mul r3, r5, r3
	mov r3, r3, lsr #0x10
	mov r3, r3, lsl #0x10
	add ip, r0, #0x48
	mov r5, r3, lsr #0x10
	str r7, [lr, #0x460]
	mov r0, #0xc000
	strh r0, [r2, #4]
	mov r0, r5, lsl #0x10
	ldr r3, _021374F8 ; =0xFFFFE4A8
	ldrh r5, [r2, #4]
	add r0, r3, r0, asr #16
	mov r0, r0, lsl #0x10
	add r0, r5, r0, asr #16
	strh r0, [r2, #4]
	mov r3, #0x20000
	str r3, [r2, #8]
	add r0, ip, #0x1400
	ldr ip, [lr, #0x448]
	ldmib r0, {r3, r5}
	umull r7, r6, r5, ip
	mla r6, r5, r3, r6
	ldr r3, [r0, #0xc]
	ldr r8, [r0, #0x10]
	mla r6, r3, ip, r6
	ldr r5, [r0, #0x14]
	adds r7, r8, r7
	adc r5, r5, r6
	str r7, [lr, #0x448]
	str r5, [r0, #4]
	mov r0, #0x18000
	umull r0, r3, r5, r0
	ldr ip, [r2, #8]
	add r0, ip, r3
	str r0, [r2, #8]
	ldrb r0, [r4, #0x2ac]
	add r2, r0, #1
	and r0, r2, #0xff
	strb r2, [r4, #0x2ac]
	cmp r0, #0x30
	strcsb r1, [r4, #0x2ac]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_021374F4: .word 0x000036B0
_021374F8: .word 0xFFFFE4A8
	arm_func_end ov1_021373FC

	arm_func_start ov1_021374FC
ov1_021374FC: ; 0x021374FC
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, lr}
	ldr r3, [r0, #0x190]
	ldr r2, [sp, #0xc]
	ldr r1, [r0, #0x194]
	ldr r0, [sp, #0x10]
	sub lr, r3, r2
	sub ip, r1, r0
	smull r3, r2, lr, lr
	smull r1, r0, ip, ip
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	cmp r0, #0x40000
	movle r0, #1
	movgt r0, #0
	ldmia sp!, {r3, lr}
	add sp, sp, #0x10
	bx lr
	arm_func_end ov1_021374FC

	arm_func_start ov1_02137550
ov1_02137550: ; 0x02137550
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x20
	mov r4, r0
	add r0, r4, #0x100
	ldrh r2, [r0, #0xa8]
	tst r2, #1
	beq _02137584
	ldrb r1, [r4, #0xc72]
	cmp r1, #0x1e
	orreq r1, r2, #2
	streqh r1, [r0, #0xa8]
	addne r0, r1, #1
	strneb r0, [r4, #0xc72]
	arm_func_end ov1_02137550
_02137584:
	add r1, r4, #0x100
	ldrh r0, [r1, #0xa8]
	tst r0, #2
	beq _0213765C
	tst r0, #4
	bne _0213765C
	tst r0, #8
	bne _0213765C
	ldrb r3, [r4, #0xc70]
	ldrb r0, [r4, #0xc71]
	cmp r3, r0
	bhs _0213764C
	add r0, r4, r3, lsl #1
	add r0, r0, #0xc00
	ldrh r2, [r1, #0xac]
	ldrh r0, [r0, #0x74]
	cmp r2, r0
	bne _0213761C
	add r0, r3, #1
	strb r0, [r4, #0xc70]
	mov r2, #0
	mov r0, r4
	strh r2, [r1, #0xac]
	bl ov1_02137194
	ldr r0, [r4, #0x184]
	mov r1, #0x32
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x184]
	mov r1, #0x33
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add r1, r4, #0x100
	ldrh r2, [r1, #0xa8]
	mov r0, r4
	bic r2, r2, #0x10
	strh r2, [r1, #0xa8]
	ldrb r1, [r4, #0xc70]
	bl ov1_02137D44
	b _0213764C
_0213761C:
	add r0, r2, #1
	strh r0, [r1, #0xac]
	ldrh r0, [r1, #0xa8]
	tst r0, #0x10
	bne _0213764C
	ldr r0, [r4, #0x184]
	mov r1, #0x32
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	orr r1, r1, #0x10
	strh r1, [r0, #0xa8]
_0213764C:
	add r0, r4, #0x100
	ldrh r1, [r0, #0xaa]
	add r1, r1, #1
	strh r1, [r0, #0xaa]
_0213765C:
	add r1, r4, #0x100
	ldrh r0, [r1, #0xa8]
	tst r0, #8
	beq _02137698
	add r0, r4, #0xc00
	ldrh r2, [r0, #0x7e]
	cmp r2, #0x18
	addne r1, r2, #1
	strneh r1, [r0, #0x7e]
	bne _02137698
	mov r2, #0
	strh r2, [r0, #0x7e]
	ldrh r0, [r1, #0xa8]
	bic r0, r0, #8
	strh r0, [r1, #0xa8]
_02137698:
	add r1, r4, #0x100
	ldrh r3, [r1, #0xac]
	ldrb r2, [r4, #0xc70]
	ldr r0, _02137AA8 ; =DAT_overlay_1_02140280
	mov r3, r3, lsl #0xc
	ldr r2, [r0, r2, lsl #2]
	mov r0, #0xf000
	smull r5, r2, r3, r2
	mov r6, r5, lsr #0xc
	orr r6, r6, r2, lsl #20
	umull r5, r3, r6, r0
	mov r2, r6, asr #0x1f
	rsb r6, r6, #0x1000
	mla r3, r2, r0, r3
	mov r0, r5, lsr #0xc
	orr r0, r0, r3, lsl #20
	rsb r0, r0, #0x1f000
	str r6, [r4, #0xc78]
	mov r0, r0, asr #0xc
	strb r0, [r4, #0xc7c]
	ldr r0, [r4, #0x20]
	ldr r2, [r4, #0x24]
	str r0, [sp, #0x10]
	str r0, [r4, #0x198]
	str r2, [r4, #0x19c]
	ldrh r0, [r1, #0xa8]
	str r2, [sp, #0x14]
	tst r0, #2
	beq _02137730
	ldrb r2, [r4, #0xc70]
	ldrb r0, [r4, #0xc71]
	cmp r2, r0
	bhs _02137730
	ldrh r0, [r1, #0xaa]
	tst r0, #1
	beq _02137730
	mov r0, r4
	bl ov1_0213720C
_02137730:
	ldr r0, [r4, #0x204]
	bl _ZN17UnkClass_02136AD412ov1_02136AECEv
	ldr r0, [r4, #0x188]
	ldr r0, [r0, #0xc]
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	tst r1, #4
	beq _02137790
	ldr r2, [r4, #0x18c]
	ldrh r1, [r0, #0xb2]
	ldr r5, [r2, #0xc]
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_02008860Et
	cmp r0, #0
	bne _02137788
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	orr r1, r1, #8
	bic r1, r1, #4
	strh r1, [r0, #0xa8]
	b _02137790
_02137788:
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_020089ECEv
_02137790:
	add r0, r4, #0x100
	ldrh r0, [r0, #0xa8]
	tst r0, #0x20
	beq _02137904
	add r0, r4, #0x200
	ldrh r1, [r0, #0xc]
	add r1, r1, #1
	strh r1, [r0, #0xc]
	ldrb r1, [r4, #0x209]
	cmp r1, #1
	beq _021377D0
	cmp r1, #2
	beq _0213782C
	cmp r1, #3
	beq _021378B0
	b _02137904
_021377D0:
	ldrh r2, [r0, #0xc]
	ldr r1, _02137AAC ; =0x00000CCC
	mov r0, #0x2000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x234]
	str r0, [r4, #0x238]
	mov r0, #1
	str r0, [r4, #0x274]
	add r0, r4, #0x200
	ldrh r1, [r0, #0xc]
	cmp r1, #8
	blo _02137904
	ldr r2, [r4, #0x210]
	ldrh r1, [r0, #0xe]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	mov r0, #2
	strb r0, [r4, #0x209]
	add r0, r4, #0x200
	mov r1, #0
	strh r1, [r0, #0xc]
	b _02137904
_0213782C:
	mov r1, #0x1000
	str r1, [r4, #0x234]
	str r1, [r4, #0x238]
	ldr r2, [r4, #0x210]
	ldrh r1, [r0, #0xe]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	mov r0, #0x1f
	str r0, [r4, #0x274]
	add r0, r4, #0x200
	ldr r2, [r4, #0x210]
	ldrh r1, [r0, #0xe]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008860Et
	cmp r0, #0
	bne _02137904
	ldrb r0, [r4, #0x20a]
	cmp r0, #0
	beq _02137898
	sub r0, r0, #1
	strb r0, [r4, #0x20a]
	add r0, r4, #0x200
	ldr r2, [r4, #0x210]
	ldrh r1, [r0, #0xe]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	b _02137904
_02137898:
	mov r0, #3
	strb r0, [r4, #0x209]
	add r0, r4, #0x200
	mov r1, #0
	strh r1, [r0, #0xc]
	b _02137904
_021378B0:
	ldrh r2, [r0, #0xc]
	ldr r0, _02137AB0 ; =0x00001666
	mov r1, #0x800
	mov r3, #8
	bl _Z17LinearInterpolatellll
	mov r1, #0x1000
	str r1, [r4, #0x234]
	str r0, [r4, #0x238]
	mov r0, #1
	str r0, [r4, #0x274]
	add r0, r4, #0x200
	ldrh r1, [r0, #0xc]
	cmp r1, #8
	blo _02137904
	mov r1, #0
	strb r1, [r4, #0x209]
	strh r1, [r0, #0xc]
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	bic r1, r1, #0x20
	strh r1, [r0, #0xa8]
_02137904:
	add r0, r4, #0x100
	ldrh r1, [r0, #0xa8]
	tst r1, #2
	addeq sp, sp, #0x20
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldrb r2, [r4, #0xc70]
	ldrb r1, [r4, #0xc71]
	cmp r2, r1
	addhs sp, sp, #0x20
	ldmhsia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldrh r0, [r0, #0xaa]
	tst r0, #1
	beq _02137940
	mov r0, r4
	bl ov1_021373FC
_02137940:
	mov r7, #0
	ldr lr, _02137AB4 ; =DAT_overlay_1_02140294
	ldr ip, _02137AB8 ; =FX_SinCosTable_
	add r5, r4, #0x2b0
	mov fp, r7
_02137954:
	mov r0, #0x34
	mul r1, r7, r0
	ldrb r0, [r5, r1]
	add r6, r5, r1
	cmp r0, #0
	beq _02137A90
	ldrh r3, [r6, #2]
	mov r1, #0xc
	ldrh r2, [r6, #4]
	mul r1, r3, r1
	ldr r3, [lr, r1]
	ldr r0, [r6, #8]
	mov r1, r2, asr #4
	smull r3, r2, r0, r3
	mov r8, r3, lsr #0xc
	mov r0, r1, lsl #1
	orr r8, r8, r2, lsl #20
	mov r2, r0, lsl #1
	add r0, ip, r0, lsl #1
	ldrsh r1, [r0, #2]
	ldrsh r0, [ip, r2]
	ldr sl, [r4, #0x1a0]
	smull r3, r2, r8, r1
	smull r1, r0, r8, r0
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	add r2, sl, r3
	ldr sb, [r4, #0x1a4]
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	add r0, sb, r1
	str r2, [r6, #0x24]
	str r0, [r6, #0x28]
	ldrh r1, [r6, #4]
	ldrh r8, [r6, #2]
	mov sb, #0xc
	mov r1, r1, asr #4
	mla sb, r8, sb, lr
	mov r1, r1, lsl #1
	mov r8, r1, lsl #1
	str r0, [sp, #0x1c]
	str r0, [sp, #0xc]
	ldr r0, [r6, #8]
	ldr sb, [sb, #4]
	add r1, ip, r1, lsl #1
	smull sl, sb, r0, sb
	mov r0, sl, lsr #0xc
	orr r0, r0, sb, lsl #20
	ldrsh sb, [r1, #2]
	ldrsh r1, [ip, r8]
	ldr r3, [r4, #0x1a0]
	smull sl, sb, r0, sb
	smull r8, r1, r0, r1
	mov r0, sl, lsr #0xc
	orr r0, r0, sb, lsl #20
	add r3, r3, r0
	str r2, [sp, #0x18]
	str r2, [sp, #8]
	ldr r2, [r4, #0x1a4]
	mov r0, r8, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r0, r2, r0
	str r3, [r6, #0x2c]
	str r0, [r6, #0x30]
	ldrh r1, [r6, #2]
	str r0, [sp, #0x1c]
	str r0, [sp, #4]
	mov r0, #0xc
	mla r0, r1, r0, lr
	ldrb r0, [r0, #8]
	str r3, [sp, #0x18]
	str r3, [sp]
	str r0, [r6, #0x20]
	ldrh r0, [r6, #2]
	add r0, r0, #1
	strh r0, [r6, #2]
	ldrh r0, [r6, #2]
	cmp r0, #0x2a
	strcsb fp, [r6]
_02137A90:
	add r0, r7, #1
	and r7, r0, #0xff
	cmp r7, #0x30
	blo _02137954
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02137AA8: .word DAT_overlay_1_02140280
_02137AAC: .word 0x00000CCC
_02137AB0: .word 0x00001666
_02137AB4: .word DAT_overlay_1_02140294
_02137AB8: .word FX_SinCosTable_

	arm_func_start _ZN16CBattlePowerSave12ov1_02137ABCEv
_ZN16CBattlePowerSave12ov1_02137ABCEv: ; 0x02137ABC
	add r0, r0, #0x100
	ldrh r0, [r0, #0xa8]
	tst r0, #2
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end _ZN16CBattlePowerSave12ov1_02137ABCEv

	arm_func_start _ZN16CBattlePowerSave12ov1_02137AD4Ev
_ZN16CBattlePowerSave12ov1_02137AD4Ev: ; 0x02137AD4
	ldrb r0, [r0, #0xc70]
	bx lr
	arm_func_end _ZN16CBattlePowerSave12ov1_02137AD4Ev

	arm_func_start _ZN16CBattlePowerSave12ov1_02137ADCEv
_ZN16CBattlePowerSave12ov1_02137ADCEv: ; 0x02137ADC
	ldrb r1, [r0, #0xc70]
	ldr r0, _02137AEC ; =DAT_overlay_1_02140288
	ldr r0, [r0, r1, lsl #2]
	bx lr
	.align 2, 0
_02137AEC: .word DAT_overlay_1_02140288
	arm_func_end _ZN16CBattlePowerSave12ov1_02137ADCEv

	arm_func_start ov1_02137AF0
ov1_02137AF0: ; 0x02137AF0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN16CBattlePowerSave12ov1_02137ABCEv
	cmp r0, #0
	beq _02137B38
	add r0, r5, #0x100
	ldrh r0, [r0, #0xa8]
	tst r0, #4
	bne _02137B38
	tst r0, #8
	bne _02137B38
	mov r0, r5
	mov r1, r4
	bl ov1_02137B94
	ldr r0, [r5, #0x204]
	mov r1, r4
	bl _ZN17UnkClass_02136AD412ov1_02136B88EP8Camera2D
	arm_func_end ov1_02137AF0
_02137B38:
	add r0, r5, #0x100
	ldrh r0, [r0, #0xa8]
	tst r0, #4
	beq _02137B54
	mov r0, r5
	mov r1, r4
	bl ov1_02137B98
_02137B54:
	mov r0, r5
	mov r1, r4
	bl ov1_02137C3C
	add r0, r5, #0x100
	ldrh r0, [r0, #0xa8]
	tst r0, #2
	ldmeqia sp!, {r3, r4, r5, pc}
	ldrb r1, [r5, #0xc70]
	ldrb r0, [r5, #0xc71]
	cmp r1, r0
	ldmhsia sp!, {r3, r4, r5, pc}
	mov r0, r5
	mov r1, r4
	bl ov1_02137CF0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_02137B90
ov1_02137B90: ; 0x02137B90
	bx lr
	arm_func_end ov1_02137B90

	arm_func_start ov1_02137B94
ov1_02137B94: ; 0x02137B94
	bx lr
	arm_func_end ov1_02137B94

	arm_func_start ov1_02137B98
ov1_02137B98: ; 0x02137B98
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	ldr r0, [r6, #0x18c]
	ldr r4, [r6, #0xc4]
	ldr r2, [r0]
	mov r0, #0
	str r2, [r4, #0x2c]
	str r0, [r4, #0x30]
	ldr r2, [r6, #0x18c]
	add r0, r6, #0x100
	ldr r2, [r2, #4]
	mov r5, r1
	str r2, [r4, #0x34]
	ldr r1, [r6, #0x18c]
	ldr r1, [r1, #8]
	str r1, [r4, #0x38]
	ldr r2, [r6, #0x18c]
	ldrh r1, [r0, #0xb2]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x2a]
	ldr ip, [r6, #0x20]
	ldr r3, [r6, #0x24]
	mov r0, #0x1800
	str ip, [r4, #0x18]
	str r3, [r4, #0x1c]
	str r0, [r4, #0x20]
	mov r0, #0x1000
	str r0, [r4, #0x24]
	mov r1, #0x1f
	mov r0, r4
	str r1, [r4, #0x14]
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #8]
	str ip, [sp]
	str r3, [sp, #4]
	blx r2
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end ov1_02137B98

	arm_func_start ov1_02137C3C
ov1_02137C3C: ; 0x02137C3C
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x18
	mov r5, r0
	add r0, r5, #0x100
	ldrh r0, [r0, #0xa8]
	mov r4, r1
	tst r0, #0x20
	addeq sp, sp, #0x18
	ldmeqia sp!, {r3, r4, r5, pc}
	add r0, r5, #0x200
	ldr r2, [r5, #0x210]
	ldr ip, [r5, #0x20]
	ldr r3, [r5, #0x24]
	ldrh r1, [r0, #0xe]
	sub r3, r3, #0x20000
	ldr r0, [r2, #0xc]
	str ip, [sp, #0x10]
	str r3, [sp, #0x14]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	add r1, r5, #0x200
	ldr ip, [sp, #0x10]
	strh r0, [r1, #0x8a]
	ldr r3, [sp, #0x14]
	str ip, [r5, #0x278]
	str r3, [r5, #0x27c]
	add r0, r5, #0x260
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	str ip, [sp, #8]
	str r3, [sp, #0xc]
	blx r2
	ldr ip, [sp, #0x10]
	ldr r3, [sp, #0x14]
	str ip, [r5, #0x22c]
	str r3, [r5, #0x230]
	add r0, r5, #0x214
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	str ip, [sp]
	str r3, [sp, #4]
	blx r2
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_02137C3C

	arm_func_start ov1_02137CF0
ov1_02137CF0: ; 0x02137CF0
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r6, r0
	mov r5, r1
	mov r4, #0
	add r8, r6, #0x2bc
	mov r7, #0x34
	arm_func_end ov1_02137CF0
_02137D08:
	mul r1, r4, r7
	add r0, r6, r1
	ldrb r0, [r0, #0x2b0]
	cmp r0, #0
	beq _02137D30
	add r0, r8, r1
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #8]
	blx r2
_02137D30:
	add r0, r4, #1
	and r4, r0, #0xff
	cmp r4, #0x30
	blo _02137D08
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov1_02137D44
ov1_02137D44: ; 0x02137D44
	cmp r1, #0
	bxeq lr
	mov r2, #1
	strb r2, [r0, #0x209]
	add r2, r0, #0x200
	mov r3, #0
	strh r3, [r2, #0xc]
	sub r1, r1, #1
	strb r1, [r0, #0x20a]
	add r0, r0, #0x100
	ldrh r1, [r0, #0xa8]
	orr r1, r1, #0x20
	strh r1, [r0, #0xa8]
	bx lr
	arm_func_end ov1_02137D44

	arm_func_start _ZN16CBattlePowerSave12ov1_02137D7CEi
_ZN16CBattlePowerSave12ov1_02137D7CEi: ; 0x02137D7C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r4, [r0, #0xc4]
	mov r5, r1
	ldrh r1, [r4, #0x2a]
	mov r0, r4
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r5, r0
	str r0, [r4, #4]
	add r0, r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN16CBattlePowerSave12ov1_02137D7CEi

	arm_func_start _ZN17UnkClass_02137DA4C1Ev
_ZN17UnkClass_02137DA4C1Ev: ; 0x02137DA4
	mov r2, #0
	add r1, r0, #4
	str r2, [r0]
	str r1, [r1, #4]
	str r1, [r0, #4]
	bx lr
	arm_func_end _ZN17UnkClass_02137DA4C1Ev

	arm_func_start _ZN17UnkClass_02137DA4D1Ev
_ZN17UnkClass_02137DA4D1Ev: ; 0x02137DBC
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0xc
	mov r4, r0
	add r0, r4, #4
	str r0, [sp, #8]
	ldr ip, [r4, #8]
	add r0, sp, #0
	add r2, sp, #4
	add r3, sp, #8
	mov r1, r4
	str ip, [sp, #4]
	bl ov1_02138028
	mov r0, r4
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
	arm_func_end _ZN17UnkClass_02137DA4D1Ev

	arm_func_start _ZN17UnkClass_02137DA412ov1_02137DF8EP6CActor
_ZN17UnkClass_02137DA412ov1_02137DF8EP6CActor: ; 0x02137DF8
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x18
	ldr r2, [sp, #0x24]
	mov r4, r0
	cmp r2, #0
	addeq sp, sp, #0x18
	moveq r0, #0
	ldmeqia sp!, {r4, lr}
	addeq sp, sp, #0x10
	bxeq lr
	ldr r0, [r4]
	cmp r0, #0
	bne _02137E50
	add ip, r4, #4
	add r0, sp, #0x14
	add r2, sp, #0x10
	add r3, sp, #0x24
	mov r1, r4
	str ip, [sp, #0x10]
	bl ov1_02137F80
	b _02137EC8
	arm_func_end _ZN17UnkClass_02137DA412ov1_02137DF8EP6CActor
_02137E50:
	ldr ip, [r4, #8]
	add r1, r4, #4
	cmp ip, r1
	mov r3, #0
	beq _02137EA4
	ldr r2, [r2, #0x24]
_02137E68:
	ldr r0, [ip, #8]
	ldr r0, [r0, #0x24]
	cmp r2, r0
	bge _02137E98
	add r0, sp, #8
	add r2, sp, #0xc
	add r3, sp, #0x24
	mov r1, r4
	str ip, [sp, #0xc]
	bl ov1_02137F80
	mov r3, #1
	b _02137EA4
_02137E98:
	ldr ip, [ip, #4]
	cmp ip, r1
	bne _02137E68
_02137EA4:
	cmp r3, #0
	bne _02137EC8
	add ip, r4, #4
	add r0, sp, #4
	add r2, sp, #0
	add r3, sp, #0x24
	mov r1, r4
	str ip, [sp]
	bl ov1_02137F80
_02137EC8:
	ldrh r1, [r4, #0x10]
	mov r0, #1
	add r1, r1, #1
	strh r1, [r4, #0x10]
	add sp, sp, #0x18
	ldmia sp!, {r4, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start _ZN17UnkClass_02137DA412ov1_02137EE8Ev
_ZN17UnkClass_02137DA412ov1_02137EE8Ev: ; 0x02137EE8
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0xc
	mov r4, r0
	add r0, r4, #4
	str r0, [sp, #8]
	ldr ip, [r4, #8]
	add r0, sp, #0
	add r2, sp, #4
	add r3, sp, #8
	mov r1, r4
	str ip, [sp, #4]
	bl ov1_02138028
	mov r0, #0
	strh r0, [r4, #0x10]
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
	arm_func_end _ZN17UnkClass_02137DA412ov1_02137EE8Ev

	arm_func_start _ZN17UnkClass_02137DA412ov1_02137F28EP8Camera2D
_ZN17UnkClass_02137DA412ov1_02137F28EP8Camera2D: ; 0x02137F28
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r6, [r0, #8]
	add r5, r0, #4
	mov r7, r1
	cmp r6, r5
	ldr r4, [r0, #0xc]
	beq _02137F78
	arm_func_end _ZN17UnkClass_02137DA412ov1_02137F28EP8Camera2D
_02137F44:
	ldr r0, [r6, #8]
	mov r1, r7
	ldrh r2, [r0, #6]
	ldr r0, [r0, #0xc4]
	add r4, r4, r2
	str r4, [r0, #4]
	ldr r0, [r6, #8]
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	ldr r6, [r6, #4]
	cmp r6, r5
	bne _02137F44
_02137F78:
	add r0, r4, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov1_02137F80
ov1_02137F80: ; 0x02137F80
	stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x14
	mov r8, r0
	mov r0, #0xc
	mov r7, r1
	mov r6, r2
	mov r5, r3
	bl _Znwm
	movs r4, r0
	bne _02137FB4
	ldr r0, _02138024 ; =s_Memory_allocation_failure_overlay_1_02141adc
	bl printf
	bl abort
	arm_func_end ov1_02137F80
_02137FB4:
	mov r1, #0
	add r0, r7, #4
	strb r1, [sp]
	str r0, [sp, #0xc]
	adds r1, r4, #8
	ldrne r0, [r5]
	str r4, [sp, #0x10]
	strne r0, [r1]
	ldr r2, [r6]
	movs r0, #0
	ldr r1, [r2]
	str r4, [sp, #4]
	str r4, [r1, #4]
	ldr r1, [r2]
	str r4, [sp, #8]
	str r1, [r4]
	str r4, [r2]
	str r2, [r4, #4]
	ldr r1, [r7]
	str r0, [sp, #0x10]
	add r1, r1, #1
	str r1, [r7]
	addeq sp, sp, #0x14
	str r4, [r8]
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, pc}
	bl _ZdlPv
	add sp, sp, #0x14
	ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02138024: .word s_Memory_allocation_failure_overlay_1_02141adc

	arm_func_start ov1_02138028
ov1_02138028: ; 0x02138028
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r2
	mov r4, r3
	ldr r2, [r4]
	ldr r3, [r5]
	mov r7, r0
	cmp r3, r2
	mov r6, r1
	streq r2, [r7]
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r2, [r2]
	ldr r0, [r3]
	ldr r1, [r2, #4]
	str r1, [r0, #4]
	ldr r1, [r3]
	ldr r0, [r2, #4]
	str r1, [r0]
	ldr r1, [r4]
	ldr r0, [r5]
	cmp r0, r1
	beq _021380A4
	arm_func_end ov1_02138028
_0213807C:
	ldr r1, [r0, #4]
	str r1, [r5]
	bl _ZdlPv
	ldr r0, [r6]
	sub r0, r0, #1
	str r0, [r6]
	ldr r1, [r4]
	ldr r0, [r5]
	cmp r0, r1
	bne _0213807C
_021380A4:
	str r1, [r7]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17UnkClass_021380ACC1Ev
_ZN17UnkClass_021380ACC1Ev: ; 0x021380AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_021380D4
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021380ACC1Ev

	arm_func_start _ZN17UnkClass_021380ACD1Ev
_ZN17UnkClass_021380ACD1Ev: ; 0x021380C0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_021381BC
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021380ACD1Ev

	arm_func_start ov1_021380D4
ov1_021380D4: ; 0x021380D4
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0xc
	mov r4, r0
	mov r0, #0x40
	bl _Znwm
	cmp r0, #0
	beq _021380F4
	bl _ZN14CPrimitiveRECTC1Ev
	arm_func_end ov1_021380D4
_021380F4:
	str r0, [r4, #4]
	mov r1, #0x70000
	str r1, [r0, #0x18]
	mov r1, #0x50000
	str r1, [r0, #0x1c]
	ldr r2, [r4, #4]
	mov r1, #0x20000
	str r1, [r2, #0x20]
	mov r0, #0x18
	str r1, [r2, #0x24]
	bl _Znwm
	cmp r0, #0
	beq _02138150
	ldr r2, _021381A4 ; =s_BAS_i046_NCLR_overlay_1_02141b2c
	ldr r1, _021381A8 ; =s_BAS_i046_00_NCER_overlay_1_02141b3c
	str r2, [sp]
	ldr ip, _021381AC ; =s_BAS_i046_00_cac_overlay_1_02141b50
	str r1, [sp, #4]
	ldr r1, _021381B0 ; =s_BAS_overlay_1_02141af8
	ldr r2, _021381B4 ; =s_data_interface_i046_LZ_bin_overlay_1_02141afc
	ldr r3, _021381B8 ; =s_BAS_i046_00_NCBR_overlay_1_02141b18
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_02138150:
	str r0, [r4, #0xc]
	mov r0, #0x4c
	bl _Znwm
	cmp r0, #0
	beq _02138168
	bl _ZN15CSoftwareSpriteC1Ev
_02138168:
	str r0, [r4, #8]
	ldr r1, [r4, #0xc]
	ldmia r1, {r2, r3, ip}
	mov r1, #0
	str r2, [r0, #0x2c]
	str r1, [r0, #0x30]
	str r3, [r0, #0x34]
	str ip, [r0, #0x38]
	ldr r1, [r4, #8]
	mov r0, #0x70000
	str r0, [r1, #0x18]
	mov r0, #0x50000
	str r0, [r1, #0x1c]
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_021381A4: .word s_BAS_i046_NCLR_overlay_1_02141b2c
_021381A8: .word s_BAS_i046_00_NCER_overlay_1_02141b3c
_021381AC: .word s_BAS_i046_00_cac_overlay_1_02141b50
_021381B0: .word s_BAS_overlay_1_02141af8
_021381B4: .word s_data_interface_i046_LZ_bin_overlay_1_02141afc
_021381B8: .word s_BAS_i046_00_NCBR_overlay_1_02141b18

	arm_func_start ov1_021381BC
ov1_021381BC: ; 0x021381BC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _021381E8
	beq _021381E0
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end ov1_021381BC
_021381E0:
	mov r0, #0
	str r0, [r5, #4]
_021381E8:
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0213820C
	beq _02138204
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02138204:
	mov r0, #0
	str r0, [r5, #8]
_0213820C:
	ldr r4, [r5, #0xc]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _0213822C
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213822C:
	mov r0, #0
	str r0, [r5, #0xc]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_021380AC12ov1_02138238Ev
_ZN17UnkClass_021380AC12ov1_02138238Ev: ; 0x02138238
	ldrb r1, [r0]
	tst r1, #1
	bxeq lr
	ldrb r1, [r0, #1]
	add r2, r1, #1
	and r1, r2, #0xff
	cmp r1, #0x10
	strb r2, [r0, #1]
	ldrhs r0, [r0, #8]
	movhs r1, #0
	strhsh r1, [r0, #0x2a]
	bx lr
	arm_func_end _ZN17UnkClass_021380AC12ov1_02138238Ev

	arm_func_start _ZN17UnkClass_021380AC12ov1_02138268EP8Camera2D
_ZN17UnkClass_021380AC12ov1_02138268EP8Camera2D: ; 0x02138268
	stmdb sp!, {r3, lr}
	ldr r0, [r0, #8]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, pc}
	arm_func_end _ZN17UnkClass_021380AC12ov1_02138268EP8Camera2D

	arm_func_start _ZN17UnkClass_021380AC12ov1_02138280Ev
_ZN17UnkClass_021380AC12ov1_02138280Ev: ; 0x02138280
	ldrb r3, [r0]
	mov r2, #0
	mov r1, #1
	orr r3, r3, #1
	strb r3, [r0]
	strb r2, [r0, #1]
	ldr r0, [r0, #8]
	strh r1, [r0, #0x2a]
	bx lr
	arm_func_end _ZN17UnkClass_021380AC12ov1_02138280Ev

	arm_func_start _ZN17UnkClass_021380AC12ov1_021382A4Et
_ZN17UnkClass_021380AC12ov1_021382A4Et: ; 0x021382A4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	mov r4, r1
	ldrh r1, [r0, #0x2a]
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r2, r4, r0
	ldr r1, [r5, #8]
	add r0, r2, #1
	str r2, [r1, #4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_021380AC12ov1_021382A4Et

	arm_func_start _ZN17UnkClass_021382D0C1Ev
_ZN17UnkClass_021382D0C1Ev: ; 0x021382D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_021382F8
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021382D0C1Ev

	arm_func_start _ZN17UnkClass_021382D0D1Ev
_ZN17UnkClass_021382D0D1Ev: ; 0x021382E4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_021383E4
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021382D0D1Ev

	arm_func_start ov1_021382F8
ov1_021382F8: ; 0x021382F8
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0xc
	mov r4, r0
	mov r0, #0x40
	bl _Znwm
	cmp r0, #0
	beq _02138318
	bl _ZN14CPrimitiveRECTC1Ev
	arm_func_end ov1_021382F8
_02138318:
	mov r1, #0x70000
	str r0, [r4, #4]
	rsb r1, r1, #0
	str r1, [r0, #0x18]
	mov r1, #0x51000
	str r1, [r0, #0x1c]
	ldr r2, [r4, #4]
	mov r1, #0x20000
	str r1, [r2, #0x20]
	mov r0, #0x18
	str r1, [r2, #0x24]
	bl _Znwm
	cmp r0, #0
	beq _02138378
	ldr r2, _021383CC ; =s_BES_i047_NCLR_overlay_1_02141b94
	ldr r1, _021383D0 ; =s_BES_i047_00_NCER_overlay_1_02141ba4
	str r2, [sp]
	ldr ip, _021383D4 ; =s_BES_i047_00_cac_overlay_1_02141bb8
	str r1, [sp, #4]
	ldr r1, _021383D8 ; =DAT_overlay_1_02141b60
	ldr r2, _021383DC ; =s_data_interface_i047_LZ_bin_overlay_1_02141b64
	ldr r3, _021383E0 ; =s_BES_i047_00_NCBR_overlay_1_02141b80
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_02138378:
	str r0, [r4, #0xc]
	mov r0, #0x4c
	bl _Znwm
	cmp r0, #0
	beq _02138390
	bl _ZN15CSoftwareSpriteC1Ev
_02138390:
	str r0, [r4, #8]
	ldr r1, [r4, #0xc]
	mov r2, #0
	ldmia r1, {r1, r3, ip}
	str r1, [r0, #0x2c]
	str r2, [r0, #0x30]
	str r3, [r0, #0x34]
	str ip, [r0, #0x38]
	ldr r1, [r4, #8]
	sub r0, r2, #0x70000
	str r0, [r1, #0x18]
	mov r0, #0x51000
	str r0, [r1, #0x1c]
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_021383CC: .word s_BES_i047_NCLR_overlay_1_02141b94
_021383D0: .word s_BES_i047_00_NCER_overlay_1_02141ba4
_021383D4: .word s_BES_i047_00_cac_overlay_1_02141bb8
_021383D8: .word DAT_overlay_1_02141b60
_021383DC: .word s_data_interface_i047_LZ_bin_overlay_1_02141b64
_021383E0: .word s_BES_i047_00_NCBR_overlay_1_02141b80

	arm_func_start ov1_021383E4
ov1_021383E4: ; 0x021383E4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _02138410
	beq _02138408
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end ov1_021383E4
_02138408:
	mov r0, #0
	str r0, [r5, #4]
_02138410:
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _02138434
	beq _0213842C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213842C:
	mov r0, #0
	str r0, [r5, #8]
_02138434:
	ldr r4, [r5, #0xc]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _02138454
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_02138454:
	mov r0, #0
	str r0, [r5, #0xc]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_021382D012ov1_02138460Ev
_ZN17UnkClass_021382D012ov1_02138460Ev: ; 0x02138460
	ldrb r1, [r0]
	tst r1, #1
	bxeq lr
	ldrb r1, [r0, #1]
	add r2, r1, #1
	and r1, r2, #0xff
	cmp r1, #0x10
	strb r2, [r0, #1]
	ldrhs r0, [r0, #8]
	movhs r1, #0
	strhsh r1, [r0, #0x2a]
	bx lr
	arm_func_end _ZN17UnkClass_021382D012ov1_02138460Ev

	arm_func_start _ZN17UnkClass_021382D012ov1_02138490EP8Camera2D
_ZN17UnkClass_021382D012ov1_02138490EP8Camera2D: ; 0x02138490
	stmdb sp!, {r3, lr}
	ldr r0, [r0, #8]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, pc}
	arm_func_end _ZN17UnkClass_021382D012ov1_02138490EP8Camera2D

	arm_func_start _ZN17UnkClass_021382D012ov1_021384A8Ev
_ZN17UnkClass_021382D012ov1_021384A8Ev: ; 0x021384A8
	ldrb r3, [r0]
	mov r2, #0
	mov r1, #1
	orr r3, r3, #1
	strb r3, [r0]
	strb r2, [r0, #1]
	ldr r0, [r0, #8]
	strh r1, [r0, #0x2a]
	bx lr
	arm_func_end _ZN17UnkClass_021382D012ov1_021384A8Ev

	arm_func_start _ZN17UnkClass_021382D012ov1_021384CCEt
_ZN17UnkClass_021382D012ov1_021384CCEt: ; 0x021384CC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	mov r4, r1
	ldrh r1, [r0, #0x2a]
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r2, r4, r0
	ldr r1, [r5, #8]
	add r0, r2, #1
	str r2, [r1, #4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_021382D012ov1_021384CCEt

	arm_func_start _ZN17UnkClass_021384F8C1Ev
_ZN17UnkClass_021384F8C1Ev: ; 0x021384F8
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	add r0, r4, #0x48
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x94
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0xe0
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x12c
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x178
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x1c4
	bl _ZN15CSoftwareSpriteC1Ev
	ldr r1, _02138C9C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x210
	str r1, [sp]
	mov r1, #2
	mov r2, #0x4c
	ldr r3, _02138CA0 ; =FUN_02005150
	bl __cxa_vec_ctor
	ldr r1, _02138C9C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x2a8
	str r1, [sp]
	mov r1, #2
	mov r2, #0x4c
	ldr r3, _02138CA0 ; =FUN_02005150
	bl __cxa_vec_ctor
	add r0, r4, #0x340
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x38c
	bl _ZN15CSoftwareSpriteC1Ev
	ldr r1, _02138C9C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x3d8
	str r1, [sp]
	mov r1, #3
	mov r2, #0x4c
	ldr r3, _02138CA0 ; =FUN_02005150
	bl __cxa_vec_ctor
	add r0, r4, #0xbc
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x108
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	ldr r1, _02138C9C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x154
	str r1, [sp]
	add r0, r0, #0x400
	mov r1, #3
	mov r2, #0x4c
	ldr r3, _02138CA0 ; =FUN_02005150
	bl __cxa_vec_ctor
	add r0, r4, #0x238
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x284
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x6d0
	bl _ZN14CPrimitiveQUADC1Ev
	ldr r1, _02138C9C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x730
	str r1, [sp]
	mov r1, #4
	mov r2, #0x4c
	ldr r3, _02138CA0 ; =FUN_02005150
	bl __cxa_vec_ctor
	add r0, r4, #0x860
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0xac
	add r0, r0, #0x800
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0xf8
	ldr ip, _02138C9C ; =_ZN15CSoftwareSpriteD1Ev
	ldr r3, _02138CA0 ; =FUN_02005150
	add r0, r0, #0x800
	mov r1, #5
	mov r2, #0x4c
	str ip, [sp]
	bl __cxa_vec_ctor
	add r0, r4, #0x274
	add r0, r0, #0x800
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0xac0
	bl _ZN15CSoftwareSpriteC1Ev
	mov r0, r4
	bl ov1_02138DE4
	mov r0, #0
	strh r0, [r4, #8]
	strh r0, [r4, #0xa]
	strb r0, [r4, #0x24]
	str r0, [r4, #0x28]
	strh r0, [r4, #0x2e]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	str r0, [r4, #0x3c]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r1, [r0, #0x438]
	ldr r0, _02138CA4 ; =MAIN_BSS_020B26A0
	str r1, [r4, #0x34]
	str r0, [r4, #0x38]
	ldr r2, [r4, #0xb14]
	ldr r1, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	mov ip, #0
	str r0, [r4, #0x664]
	str ip, [r4, #0x668]
	str r1, [r4, #0x66c]
	str r2, [r4, #0x670]
	ldr r2, [r4, #0xb14]
	ldr r1, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	mov lr, r4
	str r0, [r4, #0x6b0]
	str ip, [r4, #0x6b4]
	str r1, [r4, #0x6b8]
	str r2, [r4, #0x6bc]
	mov r0, ip
	arm_func_end _ZN17UnkClass_021384F8C1Ev
_021386E0:
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r1, [r4, #0xb0c]
	add ip, ip, #1
	str r1, [lr, #0x75c]
	str r0, [lr, #0x760]
	str r2, [lr, #0x764]
	str r3, [lr, #0x768]
	cmp ip, #4
	add lr, lr, #0x4c
	blt _021386E0
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r1, [r4, #0xb0c]
	mov lr, r4
	str r1, [r4, #0x88c]
	str r0, [r4, #0x890]
	str r2, [r4, #0x894]
	str r3, [r4, #0x898]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r1, [r4, #0xb0c]
	str r1, [r4, #0x8d8]
	str r0, [r4, #0x8dc]
	str r2, [r4, #0x8e0]
	str r3, [r4, #0x8e4]
	mov r1, #0
_0213874C:
	ldr ip, [r4, #0xb14]
	ldr r3, [r4, #0xb10]
	ldr r2, [r4, #0xb0c]
	add r0, r0, #1
	str r2, [lr, #0x924]
	str r1, [lr, #0x928]
	str r3, [lr, #0x92c]
	str ip, [lr, #0x930]
	cmp r0, #5
	add lr, lr, #0x4c
	blt _0213874C
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	mov lr, r4
	str r0, [r4, #0x74]
	str r1, [r4, #0x78]
	str r2, [r4, #0x7c]
	str r3, [r4, #0x80]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	mov ip, #0
	str r0, [r4, #0xc0]
	str r1, [r4, #0xc4]
	str r2, [r4, #0xc8]
	str r3, [r4, #0xcc]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x10c]
	str r1, [r4, #0x110]
	str r2, [r4, #0x114]
	str r3, [r4, #0x118]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x158]
	str r1, [r4, #0x15c]
	str r2, [r4, #0x160]
	str r3, [r4, #0x164]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x1a4]
	str r1, [r4, #0x1a8]
	str r2, [r4, #0x1ac]
	str r3, [r4, #0x1b0]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x1f0]
	str r1, [r4, #0x1f4]
	str r2, [r4, #0x1f8]
	str r3, [r4, #0x1fc]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x36c]
	str r1, [r4, #0x370]
	str r2, [r4, #0x374]
	str r3, [r4, #0x378]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x3b8]
	str r1, [r4, #0x3bc]
	str r2, [r4, #0x3c0]
	str r3, [r4, #0x3c4]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x4e8]
	str r1, [r4, #0x4ec]
	str r2, [r4, #0x4f0]
	str r3, [r4, #0x4f4]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	str r0, [r4, #0x534]
	str r1, [r4, #0x538]
	str r2, [r4, #0x53c]
	str r3, [r4, #0x540]
_02138898:
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	add r1, r1, #1
	str r0, [lr, #0x23c]
	str ip, [lr, #0x240]
	str r2, [lr, #0x244]
	str r3, [lr, #0x248]
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	cmp r1, #2
	str r0, [lr, #0x2d4]
	str ip, [lr, #0x2d8]
	str r2, [lr, #0x2dc]
	str r3, [lr, #0x2e0]
	add lr, lr, #0x4c
	blt _02138898
	mov r3, r4
	mov lr, #0
_021388E8:
	ldr r2, [r4, #0xb14]
	ldr r1, [r4, #0xb10]
	ldr r0, [r4, #0xb0c]
	add ip, ip, #1
	str r0, [r3, #0x404]
	str lr, [r3, #0x408]
	str r1, [r3, #0x40c]
	str r2, [r3, #0x410]
	cmp ip, #3
	add r3, r3, #0x4c
	blt _021388E8
	mov ip, r4
	mov r0, #0
_0213891C:
	ldr r3, [r4, #0xb14]
	ldr r2, [r4, #0xb10]
	ldr r1, [r4, #0xb0c]
	add lr, lr, #1
	str r1, [ip, #0x580]
	str r0, [ip, #0x584]
	str r2, [ip, #0x588]
	str r3, [ip, #0x58c]
	cmp lr, #3
	add ip, ip, #0x4c
	blt _0213891C
	ldr ip, [r4, #0xb14]
	ldr r3, [r4, #0xb10]
	ldr r2, [r4, #0xb0c]
	add r1, r4, #0x600
	str r2, [r4, #0xaa0]
	str r0, [r4, #0xaa4]
	str r3, [r4, #0xaa8]
	str ip, [r4, #0xaac]
	ldr lr, [r4, #0xb14]
	ldr ip, [r4, #0xb10]
	ldr r3, [r4, #0xb0c]
	mov r2, #0xd
	str r3, [r4, #0xaec]
	str r0, [r4, #0xaf0]
	str ip, [r4, #0xaf4]
	str lr, [r4, #0xaf8]
	strh r2, [r1, #0x62]
	mov r2, #0xe
	strh r2, [r1, #0xae]
	add r1, r4, #0x800
	mov r2, #0x11
	strh r2, [r1, #0x8a]
	mov r2, #0x23
	strh r2, [r1, #0xd6]
	strh r0, [r4, #0x72]
	mov r1, #2
	strh r1, [r4, #0xbe]
	add r1, r4, #0x100
	mov r2, #1
	strh r2, [r1, #0xa]
	mov r2, #6
	strh r2, [r1, #0x56]
	mov r2, #7
	strh r2, [r1, #0xa2]
	mov r2, #8
	strh r2, [r1, #0xee]
	add r1, r4, #0x300
	mov r2, #9
	strh r2, [r1, #0x6a]
	mov r2, #0xa
	strh r2, [r1, #0xb6]
	add r1, r4, #0x400
	mov r2, #0xb
	strh r2, [r1, #0xe6]
	add r1, r4, #0x500
	mov r2, #0xc
	strh r2, [r1, #0x32]
	add r1, r4, #0xa00
	mov r2, #0xf
	strh r2, [r1, #0x9e]
	mov r2, #0x10
	strh r2, [r1, #0xea]
	mov r3, r4
	mov r2, #0x24
_02138A20:
	add r1, r3, #0x200
	strh r2, [r1, #0x3a]
	add r0, r0, #1
	strh r2, [r1, #0xd2]
	cmp r0, #2
	add r3, r3, #0x4c
	blt _02138A20
	mov r3, r4
	mov r2, #0
	mov r1, #0x24
_02138A48:
	add r0, r3, #0x400
	add r2, r2, #1
	strh r1, [r0, #2]
	cmp r2, #3
	add r3, r3, #0x4c
	blt _02138A48
	mov r3, r4
	mov r2, #0
	mov r1, #0x24
_02138A6C:
	add r0, r3, #0x500
	add r2, r2, #1
	strh r1, [r0, #0x7e]
	cmp r2, #3
	add r3, r3, #0x4c
	blt _02138A6C
	mov r3, r4
	mov r2, #0
	mov r1, #0x24
_02138A90:
	add r0, r3, #0x700
	add r2, r2, #1
	strh r1, [r0, #0x5a]
	cmp r2, #4
	add r3, r3, #0x4c
	blt _02138A90
	mov r3, r4
	mov r2, #0
	mov r1, #0x24
_02138AB4:
	add r0, r3, #0x900
	add r2, r2, #1
	strh r1, [r0, #0x22]
	cmp r2, #5
	add r3, r3, #0x4c
	blt _02138AB4
	mov r0, #0xe
	str r0, [r4, #0xf4]
	str r0, [r4, #0x8c0]
	str r0, [r4, #0x18c]
	str r0, [r4, #0x3a0]
	str r0, [r4, #0x51c]
	mov r0, #0
	mov r2, r4
	str r0, [r4, #0x874]
	mov r1, r0
_02138AF4:
	add r0, r0, #1
	str r1, [r2, #0x90c]
	cmp r0, #5
	add r2, r2, #0x4c
	blt _02138AF4
	mov r2, r4
	mov r0, #0x800
_02138B10:
	str r0, [r2, #0x230]
	str r0, [r2, #0x234]
	str r0, [r2, #0x2c8]
	add r1, r1, #1
	str r0, [r2, #0x2cc]
	cmp r1, #2
	add r2, r2, #0x4c
	blt _02138B10
	mov r2, r4
	mov r1, #0
	mov r0, #0x800
_02138B3C:
	str r0, [r2, #0x3f8]
	add r1, r1, #1
	str r0, [r2, #0x3fc]
	cmp r1, #3
	add r2, r2, #0x4c
	blt _02138B3C
	mov r2, r4
	mov r1, #0
	mov r0, #0x800
_02138B60:
	str r0, [r2, #0x574]
	add r1, r1, #1
	str r0, [r2, #0x578]
	cmp r1, #3
	add r2, r2, #0x4c
	blt _02138B60
	ldr r1, _02138CA8 ; =0x000043F0
	add r0, r4, #0x100
	strh r1, [r4, #0x50]
	strh r1, [r0, #0x34]
	add r0, r4, #0x300
	strh r1, [r0, #0x48]
	add r0, r4, #0x400
	strh r1, [r0, #0xc4]
	add r0, r4, #0x600
	mov r3, r4
	strh r1, [r0, #0xd8]
	mov r2, #0
_02138BA8:
	add r0, r3, #0x700
	add r2, r2, #1
	strh r1, [r0, #0x38]
	cmp r2, #4
	add r3, r3, #0x4c
	blt _02138BA8
	ldr r1, _02138CA8 ; =0x000043F0
	mov r3, r4
	mov r2, #0
_02138BCC:
	add r0, r3, #0x900
	add r2, r2, #1
	strh r1, [r0]
	cmp r2, #5
	add r3, r3, #0x4c
	blt _02138BCC
	mov r1, #0x100000
	rsb r1, r1, #0
	mov r0, r4
	add r2, r1, #0xd8000
	bl ov1_02139DE0
	mov r1, #0x100000
	mov r0, r4
	rsb r1, r1, #0
	mov r2, #0x28000
	bl ov1_02139DFC
	mov r0, r4
	mov r1, #0x140000
	mov r2, #0x28000
	bl ov1_02139E70
	mov r0, r4
	mov r1, #0x140000
	mov r2, #0x28000
	bl ov1_02139EAC
	mov r0, r4
	mov r1, #0x100000
	rsb r1, r1, #0
	mov r2, #0x18000
	bl ov1_02139EE8
	mov r0, r4
	mov r1, #0x100000
	rsb r1, r1, #0
	mov r2, #0x18000
	bl ov1_02139EFC
	mov r0, r4
	mov r1, #0x100000
	mov r2, #0x18000
	bl ov1_02139F5C
	mov r0, r4
	mov r1, #0x100000
	sub r2, r1, #0x12c000
	bl ov1_02139FC4
	mov r0, r4
	mov r1, #0x100000
	sub r2, r1, #0x148000
	bl ov1_02139F88
	mov r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02138C9C: .word _ZN15CSoftwareSpriteD1Ev
_02138CA0: .word _ZN15CSoftwareSpriteC1Ev
_02138CA4: .word MAIN_BSS_020B26A0
_02138CA8: .word 0x000043F0

	arm_func_start _ZN17UnkClass_021384F8D1Ev
_ZN17UnkClass_021384F8D1Ev: ; 0x02138CAC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_02138F5C
	add r0, r4, #0xac0
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x274
	add r0, r0, #0x800
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0xf8
	add r0, r0, #0x800
	mov r1, #5
	mov r2, #0x4c
	ldr r3, _02138DE0 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0xac
	add r0, r0, #0x800
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x860
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x730
	mov r1, #4
	mov r2, #0x4c
	ldr r3, _02138DE0 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0x6d0
	bl _ZN14CPrimitiveQUADD1Ev
	add r0, r4, #0x284
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x238
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x154
	add r0, r0, #0x400
	mov r1, #3
	mov r2, #0x4c
	ldr r3, _02138DE0 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0x108
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0xbc
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x3d8
	mov r1, #3
	mov r2, #0x4c
	ldr r3, _02138DE0 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0x38c
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x340
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x2a8
	mov r1, #2
	mov r2, #0x4c
	ldr r3, _02138DE0 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0x210
	mov r1, #2
	mov r2, #0x4c
	ldr r3, _02138DE0 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0x1c4
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x178
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x12c
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0xe0
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x94
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x48
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02138DE0: .word _ZN15CSoftwareSpriteD1Ev
	arm_func_end _ZN17UnkClass_021384F8D1Ev

	arm_func_start ov1_02138DE4
ov1_02138DE4: ; 0x02138DE4
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x70
	ldr r1, _02138F48 ; =s_data_battle_result_r000_00_LZ_bi_overlay_1_02141bc8
	mov r4, r0
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x6c
	bl _Znwm
	movs r5, r0
	beq _02138E34
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	str ip, [sp, #8]
	ldr r1, _02138F4C ; =s_BRM_overlay_1_02141bec
	add r2, sp, #0x10
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r5, r0
	arm_func_end ov1_02138DE4
_02138E34:
	ldr r1, _02138F50 ; =s_BRM_r000_00_NCBR_overlay_1_02141bf0
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x3c
	bl _Znwm
	cmp r0, #0
	beq _02138E64
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	str r2, [sp]
	bl _ZN17UnkClass_020074D4C1EPKcmmm
_02138E64:
	str r0, [r4, #0xb0c]
	mov r1, #0
	ldr r0, [r0, #0x38]
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	str r0, [r4, #0xb18]
	mov r1, r1, lsl #0x10
	ldr r0, [r4, #0xb0c]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_020074D412sub_020076E8Em
	ldr r0, [r4, #0xb0c]
	bl _ZN17UnkClass_020074D412sub_020076B0Ev
	ldr r1, _02138F54 ; =s_BRM_r000_NCLR_overlay_1_02141c04
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02138EC4
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	bl _ZN17UnkClass_02007AA4C1EPKcmm
_02138EC4:
	str r0, [r4, #0xb10]
	ldr r0, [r0, #4]
	mov r1, #0
	ldr r0, [r0, #8]
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	mov r1, r0
	str r0, [r4, #0xb1c]
	mov r1, r1, lsl #0x10
	ldr r0, [r4, #0xb10]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007BFCEm
	ldr r0, [r4, #0xb10]
	bl _ZN17UnkClass_02007AA412sub_02007BC4Ev
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02138F20
	mov r2, #0
	ldr r1, _02138F58 ; =s_BRM_r000_00_NCER_overlay_1_02141c14
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNCERFileC1EPKcmmm
_02138F20:
	cmp r5, #0
	addeq sp, sp, #0x70
	str r0, [r4, #0xb14]
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r5
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r5
	bl _ZdlPv
	add sp, sp, #0x70
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02138F48: .word s_data_battle_result_r000_00_LZ_bi_overlay_1_02141bc8
_02138F4C: .word s_BRM_overlay_1_02141bec
_02138F50: .word s_BRM_r000_00_NCBR_overlay_1_02141bf0
_02138F54: .word s_BRM_r000_NCLR_overlay_1_02141c04
_02138F58: .word s_BRM_r000_00_NCER_overlay_1_02141c14

	arm_func_start ov1_02138F5C
ov1_02138F5C: ; 0x02138F5C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xb0c]
	cmp r4, #0
	beq _02138F8C
	beq _02138F84
	mov r0, r4
	bl _ZN17UnkClass_020074D4D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end ov1_02138F5C
_02138F84:
	mov r0, #0
	str r0, [r5, #0xb0c]
_02138F8C:
	ldr r4, [r5, #0xb10]
	cmp r4, #0
	beq _02138FB4
	beq _02138FAC
	mov r0, r4
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r4
	bl _ZdlPv
_02138FAC:
	mov r0, #0
	str r0, [r5, #0xb10]
_02138FB4:
	ldr r0, [r5, #0xb14]
	cmp r0, #0
	beq _02138FD8
	beq _02138FD0
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02138FD0:
	mov r0, #0
	str r0, [r5, #0xb14]
_02138FD8:
	ldr r0, [r5, #0xb18]
	bl NNS_GfdFreeLnkTexVram
	ldr r0, [r5, #0xb1c]
	bl NNS_GfdFreeLnkPlttVram
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_021384F812ov1_02138FECEv
_ZN17UnkClass_021384F812ov1_02138FECEv: ; 0x02138FEC
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]
	ldr r1, [r0, #4]
	cmp r1, #0xa
	addls pc, pc, r1, lsl #2
	ldmia sp!, {r3, pc}
_0213900C: ; jump table
	ldmia sp!, {r3, pc} ; case 0
	b _02139038 ; case 1
	b _02139040 ; case 2
	b _02139048 ; case 3
	b _02139050 ; case 4
	b _02139058 ; case 5
	b _02139060 ; case 6
	b _02139068 ; case 7
	b _02139078 ; case 8
	b _02139070 ; case 9
	b _02139080 ; case 10
	arm_func_end _ZN17UnkClass_021384F812ov1_02138FECEv
_02139038:
	bl ov1_02139088
	ldmia sp!, {r3, pc}
_02139040:
	bl ov1_021390A8
	ldmia sp!, {r3, pc}
_02139048:
	bl ov1_02139154
	ldmia sp!, {r3, pc}
_02139050:
	bl ov1_02139280
	ldmia sp!, {r3, pc}
_02139058:
	bl ov1_021392F8
	ldmia sp!, {r3, pc}
_02139060:
	bl ov1_02139364
	ldmia sp!, {r3, pc}
_02139068:
	bl ov1_021396C0
	ldmia sp!, {r3, pc}
_02139070:
	bl ov1_0213985C
	ldmia sp!, {r3, pc}
_02139078:
	bl ov1_021397FC
	ldmia sp!, {r3, pc}
_02139080:
	bl ov1_021398F4
	ldmia sp!, {r3, pc}

	arm_func_start ov1_02139088
ov1_02139088: ; 0x02139088
	ldr r1, [r0]
	cmp r1, #0x10
	bxlo lr
	mov r1, #0
	str r1, [r0]
	mov r1, #2
	str r1, [r0, #4]
	bx lr
	arm_func_end ov1_02139088

	arm_func_start ov1_021390A8
ov1_021390A8: ; 0x021390A8
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldrsh r1, [r4, #8]
	bl ov1_02139FD8
	ldr r0, [r4, #0x38]
	ldrh r2, [r4, #0x1a]
	ldr r1, [r0, #0x28]
	mov r0, r4
	mov r1, r1, lsl #0xc
	mov r2, r2, lsl #0xc
	bl ov1_0213A09C
	mov r0, #0x100000
	ldr r2, [r4]
	rsb r0, r0, #0
	mov r1, #0
	mov r3, #0x18
	bl _Z17LinearInterpolatellll
	mov r5, r0
	mov r0, r4
	mov r1, r5
	mov r2, #0x18000
	bl ov1_02139EE8
	mov r1, r5
	mov r0, r4
	mov r2, #0x18000
	bl ov1_02139EFC
	ldr r2, [r4]
	mov r0, #0x100000
	mov r1, #0
	mov r3, #0x18
	bl _Z17LinearInterpolatellll
	mov r1, r0
	mov r0, r4
	mov r2, #0x18000
	bl ov1_02139F5C
	ldr r0, [r4]
	cmp r0, #0x28
	ldmloia sp!, {r3, r4, r5, pc}
	mov r0, #0
	str r0, [r4]
	mov r0, #3
	str r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_021390A8

	arm_func_start ov1_02139154
ov1_02139154: ; 0x02139154
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #1
	arm_func_end ov1_02139154
_02139160:
	ldrb r2, [r4, #0x24]
	cmp r2, #0x11
	blo _021391C4
	ldrh r1, [r4, #0x2e]
	mov r0, r4
	bl _ZN17UnkClass_021384F812ov1_0213A4A0Et
	add r1, r0, #2
	strh r1, [r4, #0xbe]
	cmp r0, #0
	ldr r0, [r4, #0x3c]
	bne _02139198
	mov r1, #0x14
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _021391A0
_02139198:
	mov r1, #0x35
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
_021391A0:
	mov r1, #0x100000
	mov r0, r4
	sub r2, r1, #0x148000
	bl ov1_02139F88
	mov r0, #0
	str r0, [r4]
	mov r0, #5
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}
_021391C4:
	ldr r0, [r4, #0x28]
	tst r0, r1, lsl r2
	beq _02139264
	mov r0, #0x1f
	str r0, [r4, #0x874]
	ldrb r1, [r4, #0x24]
	add r0, r4, #0x800
	ldr ip, _02139278 ; =DAT_overlay_1_02140494
	add r1, r1, #0x11
	strh r1, [r0, #0x8a]
	ldrb r0, [r4, #0x24]
	ldrsh r2, [r4, #0xa]
	ldr r3, _0213927C ; =0x51EB851F
	mov r0, r0, lsl #1
	ldrh r1, [ip, r0]
	mov r0, r4
	mul lr, r2, r1
	mov r1, lr, lsr #0x1f
	smull r2, lr, r3, lr
	add lr, r1, lr, asr #5
	strh lr, [r4, #0x2c]
	ldrb r1, [r4, #0x24]
	ldrh r2, [r4, #0x2e]
	mov r1, r1, lsl #1
	ldrh r1, [ip, r1]
	add r1, r2, r1
	strh r1, [r4, #0x2e]
	ldrsh r1, [r4, #0x2c]
	bl ov1_0213A164
	ldr r0, [r4, #0x3c]
	mov r1, #0x38
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #0
	str r0, [r4]
	mov r0, #4
	str r0, [r4, #4]
	ldrb r0, [r4, #0x24]
	add r0, r0, #1
	strb r0, [r4, #0x24]
	ldmia sp!, {r4, pc}
_02139264:
	mov r0, r2
	add r0, r0, #1
	strb r0, [r4, #0x24]
	b _02139160
_02139274:
	.byte 0x10, 0x80, 0xBD, 0xE8
_02139278: .word DAT_overlay_1_02140494
_0213927C: .word 0x51EB851F

	arm_func_start ov1_02139280
ov1_02139280: ; 0x02139280
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r2, [r4]
	mov r0, #0x100000
	mov r1, #0
	mov r3, #8
	bl _Z17LinearInterpolatellll
	mov r2, #0x48000
	mov r1, r0
	mov r0, r4
	rsb r2, r2, #0
	bl ov1_02139F88
	ldr r0, [r4]
	cmp r0, #8
	bne _021392D8
	ldrsh r2, [r4, #8]
	ldrsh r1, [r4, #0x2c]
	mov r0, r4
	add r1, r2, r1
	strh r1, [r4, #8]
	ldrsh r1, [r4, #8]
	bl ov1_02139FD8
	arm_func_end ov1_02139280
_021392D8:
	ldr r0, [r4]
	cmp r0, #0x28
	ldmloia sp!, {r4, pc}
	mov r0, #0
	str r0, [r4]
	mov r0, #3
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}

	arm_func_start ov1_021392F8
ov1_021392F8: ; 0x021392F8
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r0, #0x100000
	rsb r0, r0, #0
	ldr r2, [r4]
	add r1, r0, #0x80000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	mov r2, #0x28000
	mov r1, r0
	mov r0, r4
	rsb r2, r2, #0
	bl ov1_02139DE0
	ldr r0, [r4]
	cmp r0, #0x28
	ldmloia sp!, {r4, pc}
	ldr r0, [r4, #0x3c]
	mov r1, #0x35
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x3c]
	mov r1, #0x36
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #0
	str r0, [r4]
	mov r0, #6
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}
	arm_func_end ov1_021392F8

	arm_func_start ov1_02139364
ov1_02139364: ; 0x02139364
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldrsh r0, [r4, #0xa]
	cmp r0, #0
	bne _02139398
	ldr r0, [r4, #0x3c]
	mov r1, #0x36
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	mov r0, #0
	str r0, [r4]
	mov r0, #0xa
	str r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end ov1_02139364
_02139398:
	ldr r0, [r4, #0xc]
	cmp r0, #0x40
	blo _0213949C
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bne _021393D0
	ldr r3, [r4, #0x38]
	ldrsh r2, [r4, #8]
	ldr r1, [r4, #0x1c]
	ldr r0, [r3, #0x28]
	sub r1, r2, r1
	adds r0, r1, r0
	movmi r0, #0
	str r0, [r3, #0x28]
_021393D0:
	ldrb r6, [r4, #0x18]
	ldrb r1, [r4, #0x19]
	cmp r6, r1
	beq _0213947C
	ldr r0, [r4, #0x34]
	bl sub_02010E90
	mov r5, r0
	ldr r0, [r4, #0x34]
	mov r1, r6
	bl sub_02010E90
	sub r2, r5, r0
	ldrb r1, [r4, #0x19]
	ldr r0, [r4, #0x34]
	and r6, r2, #0xff
	bl sub_02010E78
	mov r5, r0
	ldrb r1, [r4, #0x18]
	ldr r0, [r4, #0x34]
	bl sub_02010E78
	sub r0, r5, r0
	and r5, r0, #0xff
	ldrb r1, [r4, #0x18]
	ldrb r2, [r4, #0x19]
	mov r0, r4
	bl ov1_0213A21C
	mov r1, r6
	mov r0, r4
	bl ov1_0213A358
	mov r1, r5
	mov r0, r4
	bl ov1_0213A3FC
	ldr r0, [r4, #0x3c]
	mov r1, #0x36
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x3c]
	mov r1, #0xb
	mov r2, #0
	mov r3, #0x100
	bl _ZN17UnkClass_0203447812sub_02034DE8Eiii
	mov r0, #0
	str r0, [r4]
	mov r0, #9
	b _02139494
_0213947C:
	ldr r0, [r4, #0x3c]
	mov r1, #0x36
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	mov r0, #0
	str r0, [r4]
	mov r0, #0xa
_02139494:
	str r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, pc}
_0213949C:
	bl _ZN5CGame11GetInstanceEv
	ldr r5, [r0, #0x14]
	bl _ZN5CGame11GetInstanceEv
	ldrh r1, [r5]
	ldr r2, [r0, #0x18]
	and r0, r1, #1
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	ldreqb r0, [r2, #5]
	cmpeq r0, #0
	ldr r0, [r4, #0xc]
	beq _021394E4
	add r0, r0, #2
	str r0, [r4, #0xc]
	cmp r0, #0x40
	movhi r0, #0x40
	strhi r0, [r4, #0xc]
	b _021394EC
_021394E4:
	add r0, r0, #1
	str r0, [r4, #0xc]
_021394EC:
	ldrsh r0, [r4, #8]
	ldr r2, [r4, #0xc]
	mov r1, #0
	mov r0, r0, lsl #0xc
	mov r3, #0x40
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x10]
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bne _0213954C
	ldrsh r1, [r4, #8]
	ldr r2, [r4, #0xc]
	mov r0, #0
	mov r1, r1, lsl #0xc
	mov r3, #0x40
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x38]
	ldr r1, [r1, #0x28]
	add r1, r0, r1, lsl #12
	str r1, [r4, #0x14]
	ldr r0, [r4, #0x1c]
	sub r0, r1, r0, lsl #12
	str r0, [r4, #0x14]
_0213954C:
	ldrh r0, [r4, #0x1a]
	ldr r1, [r4, #0x14]
	cmp r0, r1, asr #12
	bgt _02139674
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bne _02139674
	ldr r2, [r4, #0x38]
	ldrb r1, [r4, #0x19]
	ldr r0, [r4, #0x34]
	ldr r5, [r2, #0x28]
	bl sub_02010EAC
	ldr r1, [r4, #0x1c]
	sub r0, r0, r5
	add r0, r1, r0
	str r0, [r4, #0x1c]
	ldrb r0, [r4, #0x19]
	add r1, r0, #1
	strb r1, [r4, #0x19]
	ldr r0, [r4, #0x34]
	and r1, r1, #0xff
	bl sub_02010EAC
	strh r0, [r4, #0x1a]
	ldr r0, [r4, #0x38]
	mov r1, #0
	str r1, [r0, #0x28]
	ldrb r1, [r4, #0x19]
	ldr r0, [r4, #0x38]
	bl sub_020160B8
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x438]
	bl sub_02010E60
	ldrb r1, [r4, #0x19]
	cmp r1, r0
	moveq r0, #1
	streq r0, [r4, #0x20]
	ldrsh r2, [r4, #8]
	ldr r1, [r4, #0x1c]
	mov r0, r4
	sub r1, r2, r1
	mov r1, r1, lsl #0x10
	mov r1, r1, asr #0x10
	bl ov1_02139FD8
	mov r1, #1
	mov r0, r4
	mov r2, r1
	bl ov1_0213A09C
	mov r0, r4
	mov r1, #0
	mov r2, #0x18000
	bl ov1_02139EE8
	mov r0, r4
	mov r1, #0
	mov r2, #0x18000
	bl ov1_02139EFC
	ldr r1, [r4, #0x38]
	ldr r0, [r4, #0x40]
	ldrb r1, [r1, #2]
	strb r1, [r0, #0x19c]
	ldr r0, [r4, #0x44]
	mov r2, r1
	bl _ZN14CPlayerHPGauge5SetHPEtt
	ldr r0, [r4, #0x3c]
	mov r1, #0x36
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	ldr r0, [r4, #0x3c]
	mov r1, #0x37
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #0
	str r0, [r4]
	mov r0, #8
	str r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, pc}
_02139674:
	ldr r1, [r4, #0x10]
	mov r0, r4
	mov r1, r1, lsl #4
	mov r1, r1, asr #0x10
	bl ov1_02139FD8
	mov r0, r4
	mov r1, #0
	mov r2, #0x18000
	bl ov1_02139EE8
	ldrh r2, [r4, #0x1a]
	ldr r1, [r4, #0x14]
	mov r0, r4
	mov r2, r2, lsl #0xc
	bl ov1_0213A09C
	mov r0, r4
	mov r1, #0
	mov r2, #0x18000
	bl ov1_02139EFC
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov1_021396C0
ov1_021396C0: ; 0x021396C0
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #0xc]
	cmp r0, #0x40
	blo _02139724
	ldrsh r2, [r4, #8]
	ldr r1, [r4, #0x38]
	cmp r2, #0
	rsblt r3, r2, #0
	ldr r0, [r1, #0x28]
	movge r3, r2
	cmp r3, r0
	movhs r0, #0
	addlo r0, r2, r0
	cmp r0, #0
	movlt r0, #0
	str r0, [r1, #0x28]
	ldr r0, [r4, #0x3c]
	mov r1, #0x36
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	mov r0, #0
	str r0, [r4]
	mov r0, #0xa
	str r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_021396C0
_02139724:
	bl _ZN5CGame11GetInstanceEv
	ldr r5, [r0, #0x14]
	bl _ZN5CGame11GetInstanceEv
	ldrh r1, [r5]
	ldr r2, [r0, #0x18]
	and r0, r1, #1
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	ldreqb r0, [r2, #5]
	cmpeq r0, #0
	ldr r0, [r4, #0xc]
	beq _0213976C
	add r0, r0, #2
	str r0, [r4, #0xc]
	cmp r0, #0x40
	movhi r0, #0x40
	strhi r0, [r4, #0xc]
	b _02139774
_0213976C:
	add r0, r0, #1
	str r0, [r4, #0xc]
_02139774:
	ldrsh r0, [r4, #8]
	ldr r2, [r4, #0xc]
	mov r1, #0
	mov r0, r0, lsl #0xc
	mov r3, #0x40
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x10]
	ldrsh r1, [r4, #8]
	ldr r2, [r4, #0xc]
	mov r0, #0
	mov r1, r1, lsl #0xc
	mov r3, #0x40
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x38]
	mov r2, r0
	ldr r1, [r1, #0x28]
	mov r0, r4
	add r1, r2, r1, lsl #12
	str r1, [r4, #0x14]
	ldr r1, [r4, #0x10]
	mov r1, r1, lsl #4
	mov r1, r1, asr #0x10
	bl ov1_02139FD8
	ldrh r2, [r4, #0x1a]
	ldr r1, [r4, #0x14]
	mov r0, r4
	mov r2, r2, lsl #0xc
	bl ov1_0213A09C
	mov r0, r4
	mov r1, #0
	mov r2, #0x18000
	bl ov1_02139EE8
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_021397FC
ov1_021397FC: ; 0x021397FC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r2, [r4]
	mov r0, #0x1f
	mov r1, #4
	mov r3, #0x20
	bl _Z17LinearInterpolatellll
	and r0, r0, #0xff
	str r0, [r4, #0x6e4]
	ldr r1, _02139858 ; =0x00007FFF
	add r0, r4, #0x600
	strh r1, [r0, #0xd8]
	ldr r0, [r4]
	cmp r0, #0x40
	ldmloia sp!, {r4, pc}
	ldr r0, [r4, #0x3c]
	mov r1, #0x36
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #0
	str r0, [r4]
	mov r0, #6
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02139858: .word 0x00007FFF
	arm_func_end ov1_021397FC

	arm_func_start ov1_0213985C
ov1_0213985C: ; 0x0213985C
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r0, #0x100000
	rsb r0, r0, #0
	ldr r2, [r4]
	add r1, r0, #0x80000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	mov r1, r0
	mov r0, r4
	mov r2, #0x28000
	bl ov1_02139DFC
	ldr r2, [r4]
	mov r0, #0x140000
	mov r1, #0x80000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	mov r1, r0
	mov r0, r4
	mov r2, #0x28000
	bl ov1_02139E70
	ldr r2, [r4]
	mov r0, #0x140000
	mov r1, #0x80000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	mov r1, r0
	mov r0, r4
	mov r2, #0x28000
	bl ov1_02139EAC
	ldr r0, [r4]
	cmp r0, #0x28
	ldmloia sp!, {r4, pc}
	mov r0, #0
	str r0, [r4]
	mov r0, #0xa
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213985C

	arm_func_start ov1_021398F4
ov1_021398F4: ; 0x021398F4
	stmdb sp!, {r3, r4, r5, lr}
	mov r1, #0
	mov r4, r0
	sub r2, r1, #0x2c000
	bl ov1_02139FC4
	ldrh r0, [r4, #0x30]
	ldr r1, _021399A4 ; =FX_SinCosTable_
	add r0, r0, #0x400
	strh r0, [r4, #0x30]
	ldrh r0, [r4, #0x30]
	cmp r0, #0x8000
	subhs r0, r0, #0x8000
	strhsh r0, [r4, #0x30]
	ldrh r2, [r4, #0x30]
	mov r0, #0x1f
	mov r2, r2, asr #4
	mov r2, r2, lsl #2
	ldrsh r2, [r1, r2]
	mov r1, r2, asr #0x1f
	mov r1, r1, lsl #0xf
	mov r3, r2, lsl #0xf
	orr r1, r1, r2, lsr #17
	mov r2, r3, lsr #0xc
	orr r2, r2, r1, lsl #20
	sub r1, r2, #0x2c000
	str r1, [r4, #0xa90]
	str r0, [r4, #0xa88]
	str r0, [r4, #0xad4]
	bl _ZN5CGame11GetInstanceEv
	ldr r5, [r0, #0x14]
	bl _ZN5CGame11GetInstanceEv
	ldr r0, [r0, #0x18]
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _02139994
	ldrh r0, [r5, #2]
	and r0, r0, #1
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	ldmeqia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_021398F4
_02139994:
	mov r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021399A4: .word FX_SinCosTable_

	arm_func_start _ZN17UnkClass_021384F812ov1_021399A8EP8Camera2D
_ZN17UnkClass_021384F812ov1_021399A8EP8Camera2D: ; 0x021399A8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r0
	add r0, r5, #0x48
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x94
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0xe0
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x12c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x178
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x1c4
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r6, #0
	add r7, r5, #0x210
	arm_func_end _ZN17UnkClass_021384F812ov1_021399A8EP8Camera2D
_02139A30:
	mov r0, r7
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, #1
	cmp r6, #2
	add r7, r7, #0x4c
	blt _02139A30
	add r7, r5, #0x2a8
	mov r6, #0
_02139A5C:
	mov r0, r7
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, #1
	cmp r6, #2
	add r7, r7, #0x4c
	blt _02139A5C
	add r0, r5, #0x340
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x38c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r7, r5, #0x3d8
	mov r6, #0
_02139AB0:
	mov r0, r7
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, #1
	cmp r6, #3
	add r7, r7, #0x4c
	blt _02139AB0
	add r0, r5, #0xbc
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x108
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x154
	add r7, r0, #0x400
	mov r6, #0
_02139B10:
	mov r0, r7
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, #1
	cmp r6, #3
	add r7, r7, #0x4c
	blt _02139B10
	add r0, r5, #0x238
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x284
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x6d0
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r7, r5, #0x730
	mov r6, #0
_02139B80:
	mov r0, r7
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, #1
	cmp r6, #4
	add r7, r7, #0x4c
	blt _02139B80
	add r0, r5, #0x860
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0xac
	add r0, r0, #0x800
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0xf8
	add r7, r0, #0x800
	mov r6, #0
_02139BDC:
	mov r0, r7
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, #1
	cmp r6, #5
	add r7, r7, #0x4c
	blt _02139BDC
	add r0, r5, #0x274
	add r0, r0, #0x800
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0xac0
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17UnkClass_021384F812ov1_02139C30EP11CBattleDiskP14CPlayerHPGauge
_ZN17UnkClass_021384F812ov1_02139C30EP11CBattleDiskP14CPlayerHPGauge: ; 0x02139C30
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r0, [r6, #0x28]
	mov r5, r1
	tst r0, #0x20000
	movne r0, #0
	ldreqsh r0, [r6, #0xa]
	mov r1, #0
	mov r4, r2
	strh r0, [r6, #8]
	str r1, [r6, #0xc]
	ldrsh r0, [r6, #8]
	str r0, [r6, #0x10]
	ldrsh r0, [r6, #8]
	str r0, [r6, #0x14]
	str r1, [r6, #0x1c]
	ldr r0, [r6, #0x38]
	add r0, r0, #0x8000
	ldrb r0, [r0, #0x7db]
	strb r0, [r6, #0x18]
	strb r0, [r6, #0x19]
	ldrb r1, [r6, #0x18]
	ldr r0, [r6, #0x34]
	bl sub_02010EAC
	strh r0, [r6, #0x1a]
	ldr r0, [r6, #0x3c]
	mov r1, #4
	mov r2, #1
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	str r5, [r6, #0x40]
	str r4, [r6, #0x44]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x438]
	bl sub_02010E60
	ldrb r1, [r6, #0x18]
	cmp r1, r0
	moveq r0, #1
	movne r0, #0
	str r0, [r6, #0x20]
	mov r0, #0
	str r0, [r6]
	mov r0, #1
	str r0, [r6, #4]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end _ZN17UnkClass_021384F812ov1_02139C30EP11CBattleDiskP14CPlayerHPGauge

	arm_func_start _ZN17UnkClass_021384F812ov1_02139CE4Ei
_ZN17UnkClass_021384F812ov1_02139CE4Ei: ; 0x02139CE4
	stmdb sp!, {r3, lr}
	add lr, r1, #0x40
	str lr, [r0, #0x4c]
	str lr, [r0, #0x98]
	add ip, r1, #0x20
	str ip, [r0, #0xe4]
	str lr, [r0, #0x130]
	str lr, [r0, #0x1c8]
	mov r3, r0
	str ip, [r0, #0x17c]
	mov r2, #0
	arm_func_end _ZN17UnkClass_021384F812ov1_02139CE4Ei
_02139D10:
	add r2, r2, #1
	str lr, [r3, #0x214]
	cmp r2, #2
	add r3, r3, #0x4c
	blt _02139D10
	mov r3, r0
	mov r2, #0
_02139D2C:
	add r2, r2, #1
	str lr, [r3, #0x2ac]
	cmp r2, #2
	add r3, r3, #0x4c
	blt _02139D2C
	str lr, [r0, #0x344]
	mov r3, r0
	str ip, [r0, #0x390]
	mov r2, #0
_02139D50:
	add r2, r2, #1
	str lr, [r3, #0x3dc]
	cmp r2, #3
	add r3, r3, #0x4c
	blt _02139D50
	str lr, [r0, #0x4c0]
	mov r3, r0
	str ip, [r0, #0x50c]
	mov r2, #0
_02139D74:
	add r2, r2, #1
	str lr, [r3, #0x558]
	cmp r2, #3
	add r3, r3, #0x4c
	blt _02139D74
	str lr, [r0, #0xa78]
	str lr, [r0, #0xac4]
	str lr, [r0, #0x63c]
	str ip, [r0, #0x688]
	mov r3, r0
	str lr, [r0, #0x6d4]
	mov r2, #0
_02139DA4:
	add r2, r2, #1
	str ip, [r3, #0x734]
	cmp r2, #4
	add r3, r3, #0x4c
	blt _02139DA4
	str lr, [r0, #0x864]
	str ip, [r0, #0x8b0]
	mov r2, #0
_02139DC4:
	add r2, r2, #1
	str ip, [r0, #0x8fc]
	cmp r2, #5
	add r0, r0, #0x4c
	blt _02139DC4
	add r0, r1, #0x41
	ldmia sp!, {r3, pc}

	arm_func_start ov1_02139DE0
ov1_02139DE0: ; 0x02139DE0
	str r1, [r0, #0x60]
	str r2, [r0, #0x64]
	str r1, [r0, #0xac]
	str r2, [r0, #0xb0]
	str r1, [r0, #0xf8]
	str r2, [r0, #0xfc]
	bx lr
	arm_func_end ov1_02139DE0

	arm_func_start ov1_02139DFC
ov1_02139DFC: ; 0x02139DFC
	str r1, [r0, #0x144]
	sub r3, r2, #0x2000
	str r3, [r0, #0x148]
	str r1, [r0, #0x190]
	str r2, [r0, #0x194]
	str r1, [r0, #0x1dc]
	sub r3, r2, #0x6000
	str r3, [r0, #0x1e0]
	add r3, r2, #0x17000
	mov ip, r0
	add r1, r1, #0x1a000
	mov r2, #0
	arm_func_end ov1_02139DFC
_02139E2C:
	str r1, [ip, #0x228]
	add r2, r2, #1
	str r3, [ip, #0x22c]
	cmp r2, #2
	add r1, r1, #0x10000
	add ip, ip, #0x4c
	blt _02139E2C
	add r1, r1, #0x9000
	mov r2, #0
_02139E50:
	str r1, [r0, #0x2c0]
	add r2, r2, #1
	str r3, [r0, #0x2c4]
	cmp r2, #2
	add r1, r1, #0x10000
	add r0, r0, #0x4c
	blt _02139E50
	bx lr

	arm_func_start ov1_02139E70
ov1_02139E70: ; 0x02139E70
	str r1, [r0, #0x358]
	str r2, [r0, #0x35c]
	str r1, [r0, #0x3a4]
	str r2, [r0, #0x3a8]
	add r3, r2, #0x2000
	sub r1, r1, #0x30000
	mov r2, #0
	arm_func_end ov1_02139E70
_02139E8C:
	str r1, [r0, #0x3f0]
	add r2, r2, #1
	str r3, [r0, #0x3f4]
	cmp r2, #3
	add r1, r1, #0x10000
	add r0, r0, #0x4c
	blt _02139E8C
	bx lr

	arm_func_start ov1_02139EAC
ov1_02139EAC: ; 0x02139EAC
	str r1, [r0, #0x4d4]
	str r2, [r0, #0x4d8]
	str r1, [r0, #0x520]
	str r2, [r0, #0x524]
	add r3, r2, #0x1f000
	sub r1, r1, #0x40000
	mov r2, #0
	arm_func_end ov1_02139EAC
_02139EC8:
	str r1, [r0, #0x56c]
	add r2, r2, #1
	str r3, [r0, #0x570]
	cmp r2, #3
	add r1, r1, #0x10000
	add r0, r0, #0x4c
	blt _02139EC8
	bx lr

	arm_func_start ov1_02139EE8
ov1_02139EE8: ; 0x02139EE8
	str r1, [r0, #0x650]
	str r2, [r0, #0x654]
	str r1, [r0, #0x69c]
	str r2, [r0, #0x6a0]
	bx lr
	arm_func_end ov1_02139EE8

	arm_func_start ov1_02139EFC
ov1_02139EFC: ; 0x02139EFC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x18
	mov r7, #0
	sub ip, r1, #0x12000
	sub r2, r2, #0x6000
	arm_func_end ov1_02139EFC
_02139F10:
	add r6, r0, r7, lsl #3
	ldr r5, [r6, #0x6e8]
	ldr r4, [r6, #0x6ec]
	add lr, r5, ip
	add r3, r4, r2
	add r1, r7, #1
	str lr, [r6, #0x6e8]
	and r7, r1, #0xff
	str r5, [sp, #8]
	str r4, [sp, #0xc]
	str lr, [sp, #0x10]
	str r3, [sp, #0x14]
	str lr, [sp]
	str r3, [sp, #4]
	str r3, [r6, #0x6ec]
	cmp r7, #4
	blo _02139F10
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov1_02139F5C
ov1_02139F5C: ; 0x02139F5C
	sub r3, r2, #0xc000
	add r1, r1, #0x10000
	mov r2, #0
	arm_func_end ov1_02139F5C
_02139F68:
	str r1, [r0, #0x748]
	add r2, r2, #1
	str r3, [r0, #0x74c]
	cmp r2, #4
	add r1, r1, #0x20000
	add r0, r0, #0x4c
	blt _02139F68
	bx lr

	arm_func_start ov1_02139F88
ov1_02139F88: ; 0x02139F88
	str r1, [r0, #0x878]
	str r2, [r0, #0x87c]
	str r1, [r0, #0x8c4]
	str r2, [r0, #0x8c8]
	add r3, r2, #0x32000
	sub r1, r1, #0x10000
	mov r2, #0
	arm_func_end ov1_02139F88
_02139FA4:
	str r1, [r0, #0x910]
	add r2, r2, #1
	str r3, [r0, #0x914]
	cmp r2, #5
	add r1, r1, #0x20000
	add r0, r0, #0x4c
	blt _02139FA4
	bx lr

	arm_func_start ov1_02139FC4
ov1_02139FC4: ; 0x02139FC4
	str r1, [r0, #0xa8c]
	str r2, [r0, #0xa90]
	str r1, [r0, #0xad8]
	str r2, [r0, #0xadc]
	bx lr
	arm_func_end ov1_02139FC4

	arm_func_start ov1_02139FD8
ov1_02139FD8: ; 0x02139FD8
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	ldr r3, _0213A094 ; =0x00002710
	mov r2, r1
	mov r4, r0
	cmp r2, r3
	add r0, sp, #0
	blt _0213A008
	ldr r1, _0213A098 ; =s_4d_overlay_1_02141c28
	sub r2, r3, #1
	bl OS_SPrintf
	b _0213A010
	arm_func_end ov1_02139FD8
_0213A008:
	ldr r1, _0213A098 ; =s_4d_overlay_1_02141c28
	bl OS_SPrintf
_0213A010:
	mov r5, #0
	add r6, sp, #0
	mov ip, #0x1f
	mov r2, #0x2f
	mov r3, #0x2e
	mov lr, r5
_0213A028:
	ldrsb r0, [r6]
	cmp r0, #0x20
	streq lr, [r4, #0x744]
	beq _0213A078
	str ip, [r4, #0x744]
	ldrsb r0, [r6]
	cmp r0, #0x2b
	beq _0213A054
	cmp r0, #0x2d
	beq _0213A060
	b _0213A06C
_0213A054:
	add r0, r4, #0x700
	strh r3, [r0, #0x5a]
	b _0213A078
_0213A060:
	add r0, r4, #0x700
	strh r2, [r0, #0x5a]
	b _0213A078
_0213A06C:
	sub r1, r0, #0xc
	add r0, r4, #0x700
	strh r1, [r0, #0x5a]
_0213A078:
	add r5, r5, #1
	cmp r5, #4
	add r6, r6, #1
	add r4, r4, #0x4c
	blt _0213A028
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0213A094: .word 0x00002710
_0213A098: .word s_4d_overlay_1_02141c28

	arm_func_start ov1_0213A09C
ov1_0213A09C: ; 0x0213A09C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	movne r2, #0x8b
	bne _0213A108
	cmp r1, r2
	movge r2, #0x8b
	bge _0213A108
	cmp r1, #0
	movle r2, #0
	ble _0213A108
	mov r0, r1, asr #0x1f
	mov r3, r0, lsl #0xc
	orr r3, r3, r1, lsr #20
	mov r0, r1, lsl #0xc
	mov r1, r3
	mov r3, r2, asr #0x1f
	bl _ll_div
	mov r1, #0x8b000
	umull r3, r2, r0, r1
	mov r0, r0, asr #0x1f
	mla r2, r0, r1, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mov r0, r0, asr #0xc
	and r2, r0, #0xff
	arm_func_end ov1_0213A09C
_0213A108:
	cmp r2, #0
	movne r0, #0x1f
	strne r0, [r4, #0x6e4]
	bne _0213A124
	mov r0, #1
	str r0, [r4, #0x6e4]
	ldmia sp!, {r4, pc}
_0213A124:
	ldr r1, _0213A160 ; =0x000043F0
	add r0, r4, #0x600
	strh r1, [r0, #0xd8]
	mov r1, #0
	str r1, [r4, #0x6e8]
	str r1, [r4, #0x6ec]
	mov r0, r2, lsl #0xc
	str r0, [r4, #0x6f0]
	str r1, [r4, #0x6f4]
	str r0, [r4, #0x6f8]
	mov r0, #0x2000
	str r0, [r4, #0x6fc]
	str r1, [r4, #0x700]
	str r0, [r4, #0x704]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213A160: .word 0x000043F0

	arm_func_start ov1_0213A164
ov1_0213A164: ; 0x0213A164
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r4, r0
	movs r2, r1
	add r0, sp, #0
	bpl _0213A188
	ldr r1, _0213A214 ; =s_5d_overlay_1_02141c2c
	bl OS_SPrintf
	b _0213A190
	arm_func_end ov1_0213A164
_0213A188:
	ldr r1, _0213A218 ; =s_4d_overlay_1_02141c30
	bl OS_SPrintf
_0213A190:
	mov r5, #0
	add r6, sp, #0
	mov ip, #0x1f
	mov r2, #0x2f
	mov r3, #0x2e
	mov lr, r5
_0213A1A8:
	ldrsb r0, [r6]
	cmp r0, #0x20
	streq lr, [r4, #0x90c]
	beq _0213A1F8
	str ip, [r4, #0x90c]
	ldrsb r0, [r6]
	cmp r0, #0x2b
	beq _0213A1D4
	cmp r0, #0x2d
	beq _0213A1E0
	b _0213A1EC
_0213A1D4:
	add r0, r4, #0x900
	strh r3, [r0, #0x22]
	b _0213A1F8
_0213A1E0:
	add r0, r4, #0x900
	strh r2, [r0, #0x22]
	b _0213A1F8
_0213A1EC:
	sub r1, r0, #0xc
	add r0, r4, #0x900
	strh r1, [r0, #0x22]
_0213A1F8:
	add r5, r5, #1
	cmp r5, #5
	add r6, r6, #1
	add r4, r4, #0x4c
	blt _0213A1A8
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0213A214: .word s_5d_overlay_1_02141c2c
_0213A218: .word s_4d_overlay_1_02141c30

	arm_func_start ov1_0213A21C
ov1_0213A21C: ; 0x0213A21C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
	sub sp, sp, #4
	mov r3, r1
	mov r5, r0
	mov r4, r2
	ldr r1, _0213A354 ; =s_2d_overlay_1_02141c38
	add r0, sp, #0
	mov r2, r3
	bl OS_SPrintf
	mov r2, #0
	add r3, sp, #0
	mov ip, r5
	mov r0, #0x1f
	mov r7, #0x2f
	mov r8, #0x2e
	mov r1, r2
	arm_func_end ov1_0213A21C
_0213A25C:
	ldrsb r6, [r3]
	cmp r6, #0x20
	streq r1, [ip, #0x224]
	beq _0213A2AC
	str r0, [ip, #0x224]
	ldrsb r6, [r3]
	cmp r6, #0x2b
	beq _0213A288
	cmp r6, #0x2d
	beq _0213A294
	b _0213A2A0
_0213A288:
	add lr, ip, #0x200
	strh r8, [lr, #0x3a]
	b _0213A2AC
_0213A294:
	add lr, ip, #0x200
	strh r7, [lr, #0x3a]
	b _0213A2AC
_0213A2A0:
	sub r6, r6, #0xc
	add lr, ip, #0x200
	strh r6, [lr, #0x3a]
_0213A2AC:
	add r2, r2, #1
	cmp r2, #2
	add r3, r3, #1
	add ip, ip, #0x4c
	blt _0213A25C
	ldr r1, _0213A354 ; =s_2d_overlay_1_02141c38
	add r0, sp, #0
	mov r2, r4
	bl OS_SPrintf
	mov r6, #0
	add r7, sp, #0
	mov r4, #0x1f
	mov r2, #0x2f
	mov r3, #0x2e
	mov ip, r6
_0213A2E8:
	ldrsb r0, [r7]
	cmp r0, #0x20
	streq ip, [r5, #0x2bc]
	beq _0213A338
	str r4, [r5, #0x2bc]
	ldrsb r0, [r7]
	cmp r0, #0x2b
	beq _0213A314
	cmp r0, #0x2d
	beq _0213A320
	b _0213A32C
_0213A314:
	add r0, r5, #0x200
	strh r3, [r0, #0xd2]
	b _0213A338
_0213A320:
	add r0, r5, #0x200
	strh r2, [r0, #0xd2]
	b _0213A338
_0213A32C:
	sub r1, r0, #0xc
	add r0, r5, #0x200
	strh r1, [r0, #0xd2]
_0213A338:
	add r6, r6, #1
	cmp r6, #2
	add r7, r7, #1
	add r5, r5, #0x4c
	blt _0213A2E8
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0213A354: .word s_2d_overlay_1_02141c38

	arm_func_start ov1_0213A358
ov1_0213A358: ; 0x0213A358
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r2, r1
	mov r4, r0
	ldr r1, _0213A3F8 ; =s_2d_overlay_1_02141c3c
	add r0, sp, #0
	bl OS_SPrintf
	mov r5, #0
	add r6, sp, #0
	mov ip, #0x1f
	mov r2, #0x2f
	mov r3, #0x2e
	mov lr, r5
	arm_func_end ov1_0213A358
_0213A38C:
	ldrsb r0, [r6]
	cmp r0, #0x20
	streq lr, [r4, #0x3ec]
	beq _0213A3DC
	str ip, [r4, #0x3ec]
	ldrsb r0, [r6]
	cmp r0, #0x2b
	beq _0213A3B8
	cmp r0, #0x2d
	beq _0213A3C4
	b _0213A3D0
_0213A3B8:
	add r0, r4, #0x400
	strh r3, [r0, #2]
	b _0213A3DC
_0213A3C4:
	add r0, r4, #0x400
	strh r2, [r0, #2]
	b _0213A3DC
_0213A3D0:
	sub r1, r0, #0xc
	add r0, r4, #0x400
	strh r1, [r0, #2]
_0213A3DC:
	add r5, r5, #1
	cmp r5, #3
	add r6, r6, #1
	add r4, r4, #0x4c
	blt _0213A38C
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0213A3F8: .word s_2d_overlay_1_02141c3c

	arm_func_start ov1_0213A3FC
ov1_0213A3FC: ; 0x0213A3FC
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r2, r1
	mov r4, r0
	ldr r1, _0213A49C ; =s_2d_overlay_1_02141c3c
	add r0, sp, #0
	bl OS_SPrintf
	mov r5, #0
	add r6, sp, #0
	mov ip, #0x1f
	mov r2, #0x2f
	mov r3, #0x2e
	mov lr, r5
	arm_func_end ov1_0213A3FC
_0213A430:
	ldrsb r0, [r6]
	cmp r0, #0x20
	streq lr, [r4, #0x568]
	beq _0213A480
	str ip, [r4, #0x568]
	ldrsb r0, [r6]
	cmp r0, #0x2b
	beq _0213A45C
	cmp r0, #0x2d
	beq _0213A468
	b _0213A474
_0213A45C:
	add r0, r4, #0x500
	strh r3, [r0, #0x7e]
	b _0213A480
_0213A468:
	add r0, r4, #0x500
	strh r2, [r0, #0x7e]
	b _0213A480
_0213A474:
	sub r1, r0, #0xc
	add r0, r4, #0x500
	strh r1, [r0, #0x7e]
_0213A480:
	add r5, r5, #1
	cmp r5, #3
	add r6, r6, #1
	add r4, r4, #0x4c
	blt _0213A430
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0213A49C: .word s_2d_overlay_1_02141c3c

	arm_func_start _ZN17UnkClass_021384F812ov1_0213A4A0Et
_ZN17UnkClass_021384F812ov1_0213A4A0Et: ; 0x0213A4A0
	ldr r3, _0213A4D0 ; =DAT_overlay_1_0214048c
	mov r0, #0
	arm_func_end _ZN17UnkClass_021384F812ov1_0213A4A0Et
_0213A4A8:
	mov r2, r0, lsl #1
	ldrh r2, [r3, r2]
	cmp r1, r2
	bxhs lr
	add r0, r0, #1
	and r0, r0, #0xff
	cmp r0, #4
	blo _0213A4A8
	mov r0, #3
	bx lr
	.align 2, 0
_0213A4D0: .word DAT_overlay_1_0214048c

	arm_func_start _ZN15CBattleGameOverC1EP5CGameP11CBattleDiskP14CPlayerHPGauge
_ZN15CBattleGameOverC1EP5CGameP11CBattleDiskP14CPlayerHPGauge: ; 0x0213A4D4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	mov r7, r1
	mov r6, r2
	mov r5, r3
	bl _ZN6CActorC2Ev
	ldr r0, _0213A53C ; =ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c
	str r0, [r4]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0x57
	str r0, [r4, #0x184]
	bl _ZN17UnkClass_0203447812sub_02034870Ei
	str r7, [r4, #0x1ac]
	str r6, [r4, #0x1b0]
	str r5, [r4, #0x1b4]
	add r1, r4, #0x100
	mov r2, #0
	strh r2, [r1, #0x88]
	mov r1, #0x400
	mov r0, r4
	str r1, [r4, #0x194]
	bl ov1_0213A680
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0213A53C: .word ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c
	arm_func_end _ZN15CBattleGameOverC1EP5CGameP11CBattleDiskP14CPlayerHPGauge

	arm_func_start ov1_0213A540
ov1_0213A540: ; 0x0213A540
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0213A5D8 ; =ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x1a0]
	cmp r5, #0
	beq _0213A578
	beq _0213A570
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov1_0213A540
_0213A570:
	mov r0, #0
	str r0, [r4, #0x1a0]
_0213A578:
	ldr r5, [r4, #0x1a4]
	cmp r5, #0
	beq _0213A5A0
	beq _0213A598
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213A598:
	mov r0, #0
	str r0, [r4, #0x1a4]
_0213A5A0:
	ldr r5, [r4, #0x1a8]
	cmp r5, #0
	beq _0213A5C8
	beq _0213A5C0
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213A5C0:
	mov r0, #0
	str r0, [r4, #0x1a8]
_0213A5C8:
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0213A5D8: .word ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c

	arm_func_start ov1_0213A5DC
ov1_0213A5DC: ; 0x0213A5DC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0213A67C ; =ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x1a0]
	cmp r5, #0
	beq _0213A614
	beq _0213A60C
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov1_0213A5DC
_0213A60C:
	mov r0, #0
	str r0, [r4, #0x1a0]
_0213A614:
	ldr r5, [r4, #0x1a4]
	cmp r5, #0
	beq _0213A63C
	beq _0213A634
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213A634:
	mov r0, #0
	str r0, [r4, #0x1a4]
_0213A63C:
	ldr r5, [r4, #0x1a8]
	cmp r5, #0
	beq _0213A664
	beq _0213A65C
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213A65C:
	mov r0, #0
	str r0, [r4, #0x1a8]
_0213A664:
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0213A67C: .word ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c

	arm_func_start ov1_0213A680
ov1_0213A680: ; 0x0213A680
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213A6A0
	mov r0, r4
	bl ov1_0213A77C
	mov r0, r4
	bl ov1_0213A858
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213A680

	arm_func_start ov1_0213A6A0
ov1_0213A6A0: ; 0x0213A6A0
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x1ec
	ldr r1, _0213A764 ; =s_data_interface_i_03d_LZ_bin_overlay_1_02141c80
	mov r4, r0
	add r0, sp, #0xc
	mov r2, #0x13
	bl OS_SPrintf
	ldr r1, _0213A768 ; =s_BOA_i_03d_02d_NCBR_overlay_1_02141c9c
	add r0, sp, #0x6c
	mov r2, #0x13
	mov r3, #2
	bl OS_SPrintf
	ldr r1, _0213A76C ; =s_BOA_i_03d_NCLR_overlay_1_02141cb0
	add r0, sp, #0xcc
	mov r2, #0x13
	bl OS_SPrintf
	ldr r1, _0213A770 ; =s_BOA_i_03d_02d_NCER_overlay_1_02141cc0
	add r0, sp, #0x12c
	mov r2, #0x13
	mov r3, #2
	bl OS_SPrintf
	ldr r1, _0213A774 ; =s_BOA_i_03d_02d_cac_overlay_1_02141cd4
	add r0, sp, #0x18c
	mov r2, #0x13
	mov r3, #2
	bl OS_SPrintf
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213A740
	add r2, sp, #0xcc
	str r2, [sp]
	add r1, sp, #0x12c
	str r1, [sp, #4]
	add ip, sp, #0x18c
	ldr r1, _0213A778 ; =s_BOA_overlay_1_02141ce8
	add r2, sp, #0xc
	add r3, sp, #0x6c
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
	arm_func_end ov1_0213A6A0
_0213A740:
	str r0, [r4, #0x1a0]
	ldr r0, [r0, #0xc]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, #0x100
	strh r0, [r1, #0x98]
	add sp, sp, #0x1ec
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0213A764: .word s_data_interface_i_03d_LZ_bin_overlay_1_02141c80
_0213A768: .word s_BOA_i_03d_02d_NCBR_overlay_1_02141c9c
_0213A76C: .word s_BOA_i_03d_NCLR_overlay_1_02141cb0
_0213A770: .word s_BOA_i_03d_02d_NCER_overlay_1_02141cc0
_0213A774: .word s_BOA_i_03d_02d_cac_overlay_1_02141cd4
_0213A778: .word s_BOA_overlay_1_02141ce8

	arm_func_start ov1_0213A77C
ov1_0213A77C: ; 0x0213A77C
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x1ec
	ldr r1, _0213A840 ; =s_data_interface_i_03d_LZ_bin_overlay_1_02141c80
	mov r4, r0
	add r0, sp, #0xc
	mov r2, #0x13
	bl OS_SPrintf
	ldr r1, _0213A844 ; =s_BOB_i_03d_02d_NCBR_overlay_1_02141cec
	add r0, sp, #0x6c
	mov r2, #0x13
	mov r3, #3
	bl OS_SPrintf
	ldr r1, _0213A848 ; =s_BOB_i_03d_NCLR_overlay_1_02141d00
	add r0, sp, #0xcc
	mov r2, #0x13
	bl OS_SPrintf
	ldr r1, _0213A84C ; =s_BOB_i_03d_02d_NCER_overlay_1_02141d10
	add r0, sp, #0x12c
	mov r2, #0x13
	mov r3, #3
	bl OS_SPrintf
	ldr r1, _0213A850 ; =s_BOB_i_03d_02d_cac_overlay_1_02141d24
	add r0, sp, #0x18c
	mov r2, #0x13
	mov r3, #3
	bl OS_SPrintf
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213A81C
	add r2, sp, #0xcc
	str r2, [sp]
	add r1, sp, #0x12c
	str r1, [sp, #4]
	add ip, sp, #0x18c
	ldr r1, _0213A854 ; =s_BOB_overlay_1_02141d38
	add r2, sp, #0xc
	add r3, sp, #0x6c
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
	arm_func_end ov1_0213A77C
_0213A81C:
	str r0, [r4, #0x1a4]
	ldr r0, [r0, #0xc]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, #0x100
	strh r0, [r1, #0x9a]
	add sp, sp, #0x1ec
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0213A840: .word s_data_interface_i_03d_LZ_bin_overlay_1_02141c80
_0213A844: .word s_BOB_i_03d_02d_NCBR_overlay_1_02141cec
_0213A848: .word s_BOB_i_03d_NCLR_overlay_1_02141d00
_0213A84C: .word s_BOB_i_03d_02d_NCER_overlay_1_02141d10
_0213A850: .word s_BOB_i_03d_02d_cac_overlay_1_02141d24
_0213A854: .word s_BOB_overlay_1_02141d38

	arm_func_start ov1_0213A858
ov1_0213A858: ; 0x0213A858
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x1ec
	ldr r1, _0213A8FC ; =s_data_interface_i019_LZ_bin_overlay_1_02141d3c
	mov r4, r0
	add r0, sp, #0xc
	bl OS_SPrintf
	ldr r1, _0213A900 ; =s_BOC_i019_03_NCBR_overlay_1_02141d58
	add r0, sp, #0x6c
	bl OS_SPrintf
	ldr r1, _0213A904 ; =s_BOC_i019_NCLR_overlay_1_02141d6c
	add r0, sp, #0xcc
	bl OS_SPrintf
	ldr r1, _0213A908 ; =s_BOC_i019_03_NCER_overlay_1_02141d7c
	add r0, sp, #0x12c
	bl OS_SPrintf
	ldr r1, _0213A90C ; =s_BOC_i019_03_cac_overlay_1_02141d90
	add r0, sp, #0x18c
	bl OS_SPrintf
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213A8D8
	add r2, sp, #0xcc
	str r2, [sp]
	add r1, sp, #0x12c
	str r1, [sp, #4]
	add ip, sp, #0x18c
	ldr r1, _0213A910 ; =s_BOC_overlay_1_02141da0
	add r2, sp, #0xc
	add r3, sp, #0x6c
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
	arm_func_end ov1_0213A858
_0213A8D8:
	str r0, [r4, #0x1a8]
	ldr r0, [r0, #0xc]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, #0x100
	strh r0, [r1, #0x9c]
	add sp, sp, #0x1ec
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0213A8FC: .word s_data_interface_i019_LZ_bin_overlay_1_02141d3c
_0213A900: .word s_BOC_i019_03_NCBR_overlay_1_02141d58
_0213A904: .word s_BOC_i019_NCLR_overlay_1_02141d6c
_0213A908: .word s_BOC_i019_03_NCER_overlay_1_02141d7c
_0213A90C: .word s_BOC_i019_03_cac_overlay_1_02141d90
_0213A910: .word s_BOC_overlay_1_02141da0

	arm_func_start ov1_0213A914
ov1_0213A914: ; 0x0213A914
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x1b0]
	mov r1, #0
	bl _ZN11CBattleDisk12ov1_0212C4F4Ei
	ldr r0, [r4, #0x1b0]
	mov r1, #0
	bl _ZN11CBattleDisk12ov1_0212C4ECEh
	mov r1, #0
	ldr r0, [r4, #0x1b0]
	mov r2, r1
	bl _ZN11CBattleDisk12ov1_0212C610Ell
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213A914

	arm_func_start ov1_0213A948
ov1_0213A948: ; 0x0213A948
	ldr r0, [r0, #0x1ac]
	ldr ip, _0213A964 ; =FUN_0200E0E0
	add r0, r0, #0x1000
	mov r1, #2
	ldr r0, [r0, #0x4bc]
	mov r2, #0x14
	bx ip
	.align 2, 0
_0213A964: .word _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	arm_func_end ov1_0213A948

	arm_func_start ov1_0213A968
ov1_0213A968: ; 0x0213A968
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x1ac]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #8
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	add r0, r4, #0x100
	ldrh r1, [r0, #0x88]
	bic r1, r1, #0x1000
	strh r1, [r0, #0x88]
	ldrh r1, [r0, #0x88]
	orr r1, r1, #0x2000
	strh r1, [r0, #0x88]
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213A968

	arm_func_start ov1_0213A9A8
ov1_0213A9A8: ; 0x0213A9A8
	add r0, r0, #0x100
	mov r2, #0
	strh r2, [r0, #0x8c]
	strh r1, [r0, #0x8e]
	bx lr
	arm_func_end ov1_0213A9A8

	arm_func_start ov1_0213A9BC
ov1_0213A9BC: ; 0x0213A9BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r2, r4, #0x100
	ldrh r1, [r2, #0x8a]
	cmp r1, #9
	addls pc, pc, r1, lsl #2
	b _0213AA44
_0213A9D8: ; jump table
	b _0213AA44 ; case 0
	b _0213AA44 ; case 1
	b _0213AA00 ; case 2
	b _0213AA18 ; case 3
	b _0213AA20 ; case 4
	b _0213AA28 ; case 5
	b _0213AA34 ; case 6
	b _0213AA44 ; case 7
	b _0213AA44 ; case 8
	b _0213AA40 ; case 9
	arm_func_end ov1_0213A9BC
_0213AA00:
	ldrh r3, [r2, #0x88]
	mov r1, #0x5a
	orr r3, r3, #0x1000
	strh r3, [r2, #0x88]
	bl ov1_0213A9A8
	b _0213AA44
_0213AA18:
	bl ov1_0213A948
	b _0213AA44
_0213AA20:
	bl ov1_0213A968
	b _0213AA44
_0213AA28:
	mov r1, #0x3c
	bl ov1_0213A9A8
	b _0213AA44
_0213AA34:
	mov r1, #0x3c
	bl ov1_0213A9A8
	b _0213AA44
_0213AA40:
	bl ov1_0213AC90
_0213AA44:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x88]
	bic r1, r1, #2
	strh r1, [r0, #0x88]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN15CBattleGameOver12ov1_0213AA58Ev
_ZN15CBattleGameOver12ov1_0213AA58Ev: ; 0x0213AA58
	add r0, r0, #0x100
	ldrh r0, [r0, #0x88]
	tst r0, #1
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end _ZN15CBattleGameOver12ov1_0213AA58Ev

	arm_func_start ov1_0213AA70
ov1_0213AA70: ; 0x0213AA70
	add r0, r0, #0x100
	cmp r1, #0
	ldrneh r1, [r0, #0x88]
	orrne r1, r1, #1
	ldreqh r1, [r0, #0x88]
	biceq r1, r1, #1
	strh r1, [r0, #0x88]
	bx lr
	arm_func_end ov1_0213AA70

	arm_func_start _ZN15CBattleGameOver12ov1_0213AA90Ei
_ZN15CBattleGameOver12ov1_0213AA90Ei: ; 0x0213AA90
	str r1, [r0, #0x194]
	mov r0, r1
	bx lr
	arm_func_end _ZN15CBattleGameOver12ov1_0213AA90Ei

	arm_func_start ov1_0213AA9C
ov1_0213AA9C: ; 0x0213AA9C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x1ac]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, r4
	bl ov1_0213AC70
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213AA9C

	arm_func_start ov1_0213AAC8
ov1_0213AAC8: ; 0x0213AAC8
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x1ac]
	add r1, r0, #0x1000
	ldr r0, [r1, #0x4bc]
	ldr r4, [r1, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	mov r0, r4
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	mov r0, r5
	bl ov1_0213AC70
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_0213AAC8

	arm_func_start ov1_0213AB08
ov1_0213AB08: ; 0x0213AB08
	stmdb sp!, {r3, lr}
	add r1, r0, #0x100
	ldrh r3, [r1, #0x8c]
	ldrh r2, [r1, #0x8e]
	cmp r2, r3
	bne _0213AB28
	bl ov1_0213AC70
	ldmia sp!, {r3, pc}
	arm_func_end ov1_0213AB08
_0213AB28:
	addhi r0, r3, #1
	strhih r0, [r1, #0x8c]
	ldmia sp!, {r3, pc}

	arm_func_start ov1_0213AB34
ov1_0213AB34: ; 0x0213AB34
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r1, r4, #0x100
	ldrh r1, [r1, #0x8a]
	cmp r1, #9
	addls pc, pc, r1, lsl #2
	b _0213ABA4
_0213AB50: ; jump table
	b _0213ABA4 ; case 0
	b _0213AB78 ; case 1
	b _0213AB80 ; case 2
	b _0213AB88 ; case 3
	b _0213AB88 ; case 4
	b _0213AB80 ; case 5
	b _0213AB80 ; case 6
	b _0213AB90 ; case 7
	b _0213AB98 ; case 8
	b _0213ABA0 ; case 9
	arm_func_end ov1_0213AB34
_0213AB78:
	bl ov1_0213AC70
	b _0213ABA4
_0213AB80:
	bl ov1_0213AB08
	b _0213ABA4
_0213AB88:
	bl ov1_0213AA9C
	b _0213ABA4
_0213AB90:
	bl ov1_0213AAC8
	b _0213ABA4
_0213AB98:
	bl ov1_0213AC70
	b _0213ABA4
_0213ABA0:
	bl ov1_0213AC70
_0213ABA4:
	add r0, r4, #0x100
	ldrh r0, [r0, #0x88]
	tst r0, #2
	beq _0213ABBC
	mov r0, r4
	bl ov1_0213A9BC
_0213ABBC:
	ldr r0, [r4, #0x1a0]
	ldr r0, [r0, #0xc]
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	ldr r0, [r4, #0x1a4]
	ldr r0, [r0, #0xc]
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	add r0, r4, #0x100
	ldrh r0, [r0, #0x88]
	tst r0, #0x2000
	beq _0213ABF0
	ldr r0, [r4, #0x1a8]
	ldr r0, [r0, #0xc]
	bl _ZN17UnkClass_0200878812sub_020089ECEv
_0213ABF0:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x88]
	tst r1, #0x2000
	ldmeqia sp!, {r4, pc}
	ldrh r0, [r0, #0x90]
	cmp r0, #0x50
	bne _0213AC18
	ldr r0, [r4, #0x184]
	mov r1, #0x5d
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
_0213AC18:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x90]
	cmp r1, #0x50
	addls r1, r1, #1
	strlsh r1, [r0, #0x90]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN15CBattleGameOver12ov1_0213AC30Ev
_ZN15CBattleGameOver12ov1_0213AC30Ev: ; 0x0213AC30
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213A914
	add r2, r4, #0x100
	mov r1, #1
	mov r0, r4
	strh r1, [r2, #0x8a]
	bl ov1_0213AA70
	ldr r0, [r4, #0x184]
	mov r1, #0x1e
	bl _ZN17UnkClass_0203447812sub_02034B58Ei
	add r0, r4, #0x100
	ldrh r1, [r0, #0x88]
	orr r1, r1, #2
	strh r1, [r0, #0x88]
	ldmia sp!, {r4, pc}
	arm_func_end _ZN15CBattleGameOver12ov1_0213AC30Ev

	arm_func_start ov1_0213AC70
ov1_0213AC70: ; 0x0213AC70
	add r0, r0, #0x100
	ldrh r1, [r0, #0x8a]
	add r1, r1, #1
	strh r1, [r0, #0x8a]
	ldrh r1, [r0, #0x88]
	orr r1, r1, #2
	strh r1, [r0, #0x88]
	bx lr
	arm_func_end ov1_0213AC70

	arm_func_start ov1_0213AC90
ov1_0213AC90: ; 0x0213AC90
	add r0, r0, #0x100
	ldrh r1, [r0, #0x88]
	bic r1, r1, #1
	strh r1, [r0, #0x88]
	bx lr
	arm_func_end ov1_0213AC90

	arm_func_start ov1_0213ACA4
ov1_0213ACA4: ; 0x0213ACA4
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	ldr r0, [r6, #0x1a0]
	ldr r4, [r6, #0xc4]
	ldr r2, [r0]
	mov r0, #0
	str r2, [r4, #0x2c]
	str r0, [r4, #0x30]
	ldr r2, [r6, #0x1a0]
	add r0, r6, #0x100
	ldr r2, [r2, #4]
	mov r5, r1
	str r2, [r4, #0x34]
	ldr r1, [r6, #0x1a0]
	ldr r1, [r1, #8]
	str r1, [r4, #0x38]
	ldr r2, [r6, #0x1a0]
	ldrh r1, [r0, #0x98]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x2a]
	ldr r1, [r6, #0x1b0]
	mov r0, r4
	ldr ip, [r1, #0x20]
	ldr r3, [r1, #0x24]
	mov r1, r5
	str ip, [r4, #0x18]
	str r3, [r4, #0x1c]
	ldr r2, [r6, #0x194]
	str ip, [sp]
	str r2, [r4, #4]
	ldr r2, [r0]
	str r3, [sp, #4]
	ldr r2, [r2, #8]
	blx r2
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end ov1_0213ACA4

	arm_func_start ov1_0213AD3C
ov1_0213AD3C: ; 0x0213AD3C
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	ldr r0, [r6, #0x1a8]
	ldr r4, [r6, #0xc4]
	ldr r2, [r0]
	mov r0, #0
	str r2, [r4, #0x2c]
	str r0, [r4, #0x30]
	ldr r2, [r6, #0x1a8]
	add r0, r6, #0x100
	ldr r2, [r2, #4]
	mov r5, r1
	str r2, [r4, #0x34]
	ldr r1, [r6, #0x1a8]
	ldr r1, [r1, #8]
	str r1, [r4, #0x38]
	ldr r2, [r6, #0x1a8]
	ldrh r1, [r0, #0x9c]
	ldr r0, [r2, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x2a]
	ldr r1, [r6, #0x1b0]
	mov r0, r4
	ldr ip, [r1, #0x20]
	ldr r3, [r1, #0x24]
	mov r1, r5
	str ip, [r4, #0x18]
	str r3, [r4, #0x1c]
	ldr r2, [r6, #0x194]
	str ip, [sp]
	str r2, [r4, #4]
	ldr r2, [r0]
	str r3, [sp, #4]
	ldr r2, [r2, #8]
	blx r2
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end ov1_0213AD3C

	arm_func_start ov1_0213ADD4
ov1_0213ADD4: ; 0x0213ADD4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r2, r5, #0x100
	ldrh r2, [r2, #0x88]
	mov r4, r1
	tst r2, #0x1000
	beq _0213ADF4
	bl ov1_0213ACA4
	arm_func_end ov1_0213ADD4
_0213ADF4:
	add r0, r5, #0x100
	ldrh r0, [r0, #0x88]
	tst r0, #0x2000
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r5
	mov r1, r4
	bl ov1_0213AD3C
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_0213AE14
ov1_0213AE14: ; 0x0213AE14
	bx lr
	arm_func_end ov1_0213AE14

	arm_func_start _ZN17UnkClass_0213AE18C1EPvP17UnkClass_0212DC20P17UnkClass_0213CC28P17UnkClass_0201AD60
_ZN17UnkClass_0213AE18C1EPvP17UnkClass_0212DC20P17UnkClass_0213CC28P17UnkClass_0201AD60: ; 0x0213AE18
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #4
	mov r4, r0
	mov r5, r3
	ldr r8, _0213B194 ; =_ZN17UnkClass_0201179CD1Ev
	mov r7, r1
	mov r6, r2
	ldr r3, _0213B198 ; =_ZN17UnkClass_0201179CC1Ev
	add r0, r4, #0xfc
	mov r1, #8
	mov r2, #0x64
	str r8, [sp]
	bl __cxa_vec_ctor
	ldr r1, _0213B19C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x1c
	str r1, [sp]
	ldr r3, _0213B1A0 ; =FUN_02005150
	add r0, r0, #0x400
	mov r1, #8
	mov r2, #0x4c
	bl __cxa_vec_ctor
	add r0, r4, #0x27c
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x2c8
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x314
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x760
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r4, #0x3ac
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteC1Ev
	ldr r1, _0213B19C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x3f8
	str r1, [sp]
	ldr r3, _0213B1A0 ; =FUN_02005150
	add r0, r0, #0x400
	mov r1, #0x12
	mov r2, #0x4c
	bl __cxa_vec_ctor
	ldr r1, _0213B1A4 ; =FUN_02003BB0
	add r0, r4, #0x164
	str r1, [sp]
	ldr r3, _0213B1A8 ; =FUN_02003B64
	add r0, r0, #0xc00
	mov r1, #8
	mov r2, #0x40
	bl __cxa_vec_ctor
	add r0, r4, #0x364
	add r0, r0, #0xc00
	bl _ZN14CPrimitiveRECTC1Ev
	add r0, r4, #0x3a4
	add r0, r0, #0xc00
	bl _ZN14CPrimitiveRECTC1Ev
	mov r0, r4
	bl ov1_0213B27C
	str r7, [r4, #0xf0]
	str r6, [r4, #0xf4]
	ldr r1, [sp, #0x28]
	str r5, [r4, #0xf8]
	str r1, [r4, #0xff8]
	mov r0, #0
	str r0, [r4, #8]
	strb r0, [r4, #0xc]
	ldr r1, _0213B1AC ; =0x0000042E
	mov r0, r4
	bl _ZN17UnkClass_0213AE1812ov1_0213C67CEi
	mov r2, #0
	mov r1, #0x30000
	arm_func_end _ZN17UnkClass_0213AE18C1EPvP17UnkClass_0212DC20P17UnkClass_0213CC28P17UnkClass_0201AD60
_0213AF38:
	add r0, r4, r2, lsl #6
	str r1, [r0, #0xd84]
	add r2, r2, #1
	str r1, [r0, #0xd88]
	cmp r2, #8
	blt _0213AF38
	str r1, [r4, #0xf84]
	mov r1, #0x20000
	mov r8, #0
	str r1, [r4, #0xf88]
	str r8, [r4, #0xf7c]
	sub r0, r8, #0x48000
	str r0, [r4, #0xf80]
	str r1, [r4, #0xfc4]
	str r1, [r4, #0xfc8]
	mov r0, #0x70000
	str r0, [r4, #0xfbc]
	sub r0, r0, #0xc0000
	str r0, [r4, #0xfc0]
	mov r1, r8
	mov r0, #0x4c
_0213AF8C:
	mla r3, r8, r0, r4
	add r2, r8, #1
	and r8, r2, #0xff
	ldr r7, [r4, #0xfe4]
	cmp r8, #8
	ldmia r7, {r2, r5, r6}
	str r2, [r3, #0x448]
	str r1, [r3, #0x44c]
	str r5, [r3, #0x450]
	str r6, [r3, #0x454]
	blo _0213AF8C
	ldr r0, [r4, #0xfe8]
	mov r5, #0x4c
	ldmia r0, {r0, r2, r3}
	str r0, [r4, #0x6a8]
	str r1, [r4, #0x6ac]
	str r2, [r4, #0x6b0]
	str r3, [r4, #0x6b4]
	ldr r0, [r4, #0xfec]
	mov r6, #0x1c8
	ldmia r0, {r0, r2, r3}
	str r0, [r4, #0x6f4]
	str r1, [r4, #0x6f8]
	str r2, [r4, #0x6fc]
	str r3, [r4, #0x700]
	ldr r0, [r4, #0xfe8]
	ldmia r0, {r0, r2, r3}
	str r0, [r4, #0x740]
	str r1, [r4, #0x744]
	str r2, [r4, #0x748]
	str r3, [r4, #0x74c]
	ldr r0, [r4, #0xff0]
	ldmia r0, {r0, r2, r3}
	str r0, [r4, #0x78c]
	str r1, [r4, #0x790]
	str r2, [r4, #0x794]
	str r3, [r4, #0x798]
	ldr r0, [r4, #0xff4]
	ldmia r0, {r0, r2, r3}
	str r0, [r4, #0x7d8]
	str r1, [r4, #0x7dc]
	str r2, [r4, #0x7e0]
	mov r2, #0
	str r3, [r4, #0x7e4]
	mov r0, r2
_0213B040:
	mla r3, r1, r6, r4
	mov sl, r0
_0213B048:
	mla ip, sl, r5, r3
	ldr sb, [r4, #0xff4]
	add r7, sl, #1
	and sl, r7, #0xff
	ldr r8, [sb, #8]
	ldmia sb, {r7, lr}
	str r7, [ip, #0x824]
	str r2, [ip, #0x828]
	str lr, [ip, #0x82c]
	cmp sl, #6
	str r8, [ip, #0x830]
	blo _0213B048
	add r1, r1, #1
	and r1, r1, #0xff
	cmp r1, #3
	blo _0213B040
	mov r0, #0
	mov r1, #0x4c
_0213B090:
	mla r3, r2, r1, r4
	add r2, r2, #1
	add r3, r3, #0x400
	and r2, r2, #0xff
	strh r0, [r3, #0x46]
	cmp r2, #8
	blo _0213B090
	add r1, r4, #0x600
	strh r0, [r1, #0xa6]
	strh r0, [r1, #0xf2]
	add r1, r4, #0x700
	mov r2, #1
	strh r2, [r1, #0x3e]
	mov r6, #0
	mov r1, #0x4c
	mov r3, #0x1c8
_0213B0D0:
	mla r8, r0, r3, r4
	add r2, r0, #1
	mov r5, r6
	and r7, r2, #0xff
_0213B0E0:
	mla r2, r5, r1, r8
	add r5, r5, #1
	add r2, r2, #0x800
	and r5, r5, #0xff
	strh r7, [r2, #0x22]
	cmp r5, #6
	blo _0213B0E0
	add r0, r0, #1
	and r0, r0, #0xff
	cmp r0, #3
	blo _0213B0D0
	mov r2, #0
	str r2, [r4, #0x694]
	sub r0, r2, #0x48000
	mov r1, #0x70000
	str r0, [r4, #0x698]
	str r1, [r4, #0x6e0]
	sub r0, r1, #0xc0000
	str r0, [r4, #0x6e4]
	sub r0, r1, #0xc4000
	str r2, [r4, #0x72c]
	str r0, [r4, #0x730]
	mov r0, r4
	str r2, [r4, #0x778]
	sub r1, r1, #0xa6000
	str r1, [r4, #0x77c]
	bl ov1_0213CAC8
	mov r1, #0
	mov r3, #0xe
	mov r0, #0x4c
_0213B158:
	mla r2, r1, r0, r4
	add r1, r1, #1
	and r1, r1, #0xff
	str r3, [r2, #0x430]
	cmp r1, #8
	blo _0213B158
	mov r0, #0x1000
	str r0, [r4, #0x7cc]
	str r0, [r4, #0x7d0]
	mov r1, #0
	str r1, [r4]
	mov r0, r4
	str r1, [r4, #4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_0213B194: .word _ZN17UnkClass_0201179CD1Ev
_0213B198: .word _ZN17UnkClass_0201179CC1Ev
_0213B19C: .word _ZN15CSoftwareSpriteD1Ev
_0213B1A0: .word _ZN15CSoftwareSpriteC1Ev
_0213B1A4: .word _ZN14CPrimitiveRECTD1Ev
_0213B1A8: .word _ZN14CPrimitiveRECTC1Ev
_0213B1AC: .word 0x0000042E

	arm_func_start _ZN17UnkClass_0213AE18D1Ev
_ZN17UnkClass_0213AE18D1Ev: ; 0x0213B1B0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213B454
	add r0, r4, #0x3a4
	add r0, r0, #0xc00
	bl _ZN14CPrimitiveRECTD1Ev
	add r0, r4, #0x364
	add r0, r0, #0xc00
	bl _ZN14CPrimitiveRECTD1Ev
	add r0, r4, #0x164
	add r0, r0, #0xc00
	mov r1, #8
	mov r2, #0x40
	ldr r3, _0213B270 ; =FUN_02003BB0
	bl __cxa_vec_cleanup
	add r0, r4, #0x3f8
	add r0, r0, #0x400
	mov r1, #0x12
	mov r2, #0x4c
	ldr r3, _0213B274 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0x3ac
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x760
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x314
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x2c8
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x27c
	add r0, r0, #0x400
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x1c
	add r0, r0, #0x400
	mov r1, #8
	mov r2, #0x4c
	ldr r3, _0213B274 ; =_ZN15CSoftwareSpriteD1Ev
	bl __cxa_vec_cleanup
	add r0, r4, #0xfc
	mov r1, #8
	mov r2, #0x64
	ldr r3, _0213B278 ; =_ZN17UnkClass_0201179CD1Ev
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213B270: .word _ZN14CPrimitiveRECTD1Ev
_0213B274: .word _ZN15CSoftwareSpriteD1Ev
_0213B278: .word _ZN17UnkClass_0201179CD1Ev
	arm_func_end _ZN17UnkClass_0213AE18D1Ev

	arm_func_start ov1_0213B27C
ov1_0213B27C: ; 0x0213B27C
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	mov r4, r0
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213B2C0
	ldr r2, _0213B3FC ; =s_BAM_i062_NCLR_overlay_1_02141dd8
	ldr r1, _0213B400 ; =s_BAM_i062_00_NCER_overlay_1_02141de8
	str r2, [sp]
	ldr r5, _0213B404 ; =s_BAM_i062_00_cac_overlay_1_02141dfc
	str r1, [sp, #4]
	ldr r1, _0213B408 ; =s_BAM_overlay_1_02141da4
	ldr r2, _0213B40C ; =s_data_interface_i062_LZ_bin_overlay_1_02141da8
	ldr r3, _0213B410 ; =s_BAM_i062_00_NCBR_overlay_1_02141dc4
	str r5, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
	arm_func_end ov1_0213B27C
_0213B2C0:
	str r0, [r4, #0xfe4]
	ldr r0, [r0, #0xc]
	mov r7, #0
	str r0, [r4, #0xd50]
	mov r6, #1
	mov r5, r7
_0213B2D8:
	ldr r0, [r4, #0xd50]
	mov r1, r6
	mov r2, r5
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, r7, lsl #1
	add r2, r7, #1
	add r1, r1, #0xd00
	and r7, r2, #0xff
	strh r0, [r1, #0x54]
	cmp r7, #8
	blo _0213B2D8
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213B33C
	ldr r1, _0213B414 ; =s_BAM_i060_NCLR_overlay_1_02141e3c
	ldr ip, _0213B418 ; =s_BAM_i060_00_NCER_overlay_1_02141e4c
	str r1, [sp]
	ldr r1, _0213B408 ; =s_BAM_overlay_1_02141da4
	ldr r2, _0213B41C ; =s_data_interface_i060_LZ_bin_overlay_1_02141e0c
	ldr r3, _0213B420 ; =s_BAM_i060_00_NCBR_overlay_1_02141e28
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213B33C:
	str r0, [r4, #0xfe8]
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213B378
	ldr r1, _0213B424 ; =s_BAM_i061_NCLR_overlay_1_02141e90
	ldr ip, _0213B428 ; =s_BAM_i061_00_NCER_overlay_1_02141ea0
	str r1, [sp]
	ldr r1, _0213B408 ; =s_BAM_overlay_1_02141da4
	ldr r2, _0213B42C ; =s_data_interface_i061_LZ_bin_overlay_1_02141e60
	ldr r3, _0213B430 ; =s_BAM_i061_00_NCBR_overlay_1_02141e7c
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213B378:
	str r0, [r4, #0xfec]
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213B3B4
	ldr r1, _0213B434 ; =s_BAM_i063_NCLR_overlay_1_02141ee4
	ldr ip, _0213B438 ; =s_BAM_i063_00_NCER_overlay_1_02141ef4
	str r1, [sp]
	ldr r1, _0213B408 ; =s_BAM_overlay_1_02141da4
	ldr r2, _0213B43C ; =s_data_interface_i063_LZ_bin_overlay_1_02141eb4
	ldr r3, _0213B440 ; =s_BAM_i063_00_NCBR_overlay_1_02141ed0
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213B3B4:
	str r0, [r4, #0xff0]
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213B3F0
	ldr r1, _0213B444 ; =s_BAM_i064_NCLR_overlay_1_02141f38
	ldr ip, _0213B448 ; =s_BAM_i064_00_NCER_overlay_1_02141f48
	str r1, [sp]
	ldr r1, _0213B408 ; =s_BAM_overlay_1_02141da4
	ldr r2, _0213B44C ; =s_data_interface_i064_LZ_bin_overlay_1_02141f08
	ldr r3, _0213B450 ; =s_BAM_i064_00_NCBR_overlay_1_02141f24
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213B3F0:
	str r0, [r4, #0xff4]
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_0213B3FC: .word s_BAM_i062_NCLR_overlay_1_02141dd8
_0213B400: .word s_BAM_i062_00_NCER_overlay_1_02141de8
_0213B404: .word s_BAM_i062_00_cac_overlay_1_02141dfc
_0213B408: .word s_BAM_overlay_1_02141da4
_0213B40C: .word s_data_interface_i062_LZ_bin_overlay_1_02141da8
_0213B410: .word s_BAM_i062_00_NCBR_overlay_1_02141dc4
_0213B414: .word s_BAM_i060_NCLR_overlay_1_02141e3c
_0213B418: .word s_BAM_i060_00_NCER_overlay_1_02141e4c
_0213B41C: .word s_data_interface_i060_LZ_bin_overlay_1_02141e0c
_0213B420: .word s_BAM_i060_00_NCBR_overlay_1_02141e28
_0213B424: .word s_BAM_i061_NCLR_overlay_1_02141e90
_0213B428: .word s_BAM_i061_00_NCER_overlay_1_02141ea0
_0213B42C: .word s_data_interface_i061_LZ_bin_overlay_1_02141e60
_0213B430: .word s_BAM_i061_00_NCBR_overlay_1_02141e7c
_0213B434: .word s_BAM_i063_NCLR_overlay_1_02141ee4
_0213B438: .word s_BAM_i063_00_NCER_overlay_1_02141ef4
_0213B43C: .word s_data_interface_i063_LZ_bin_overlay_1_02141eb4
_0213B440: .word s_BAM_i063_00_NCBR_overlay_1_02141ed0
_0213B444: .word s_BAM_i064_NCLR_overlay_1_02141f38
_0213B448: .word s_BAM_i064_00_NCER_overlay_1_02141f48
_0213B44C: .word s_data_interface_i064_LZ_bin_overlay_1_02141f08
_0213B450: .word s_BAM_i064_00_NCBR_overlay_1_02141f24

	arm_func_start ov1_0213B454
ov1_0213B454: ; 0x0213B454
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r5, [r4, #0xfe4]
	cmp r5, #0
	beq _0213B484
	beq _0213B47C
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov1_0213B454
_0213B47C:
	mov r0, #0
	str r0, [r4, #0xfe4]
_0213B484:
	ldr r5, [r4, #0xfe8]
	cmp r5, #0
	beq _0213B4AC
	beq _0213B4A4
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213B4A4:
	mov r0, #0
	str r0, [r4, #0xfe8]
_0213B4AC:
	ldr r5, [r4, #0xfec]
	cmp r5, #0
	beq _0213B4D4
	beq _0213B4CC
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213B4CC:
	mov r0, #0
	str r0, [r4, #0xfec]
_0213B4D4:
	ldr r5, [r4, #0xff0]
	cmp r5, #0
	beq _0213B4FC
	beq _0213B4F4
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213B4F4:
	mov r0, #0
	str r0, [r4, #0xff0]
_0213B4FC:
	ldr r5, [r4, #0xff4]
	cmp r5, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _0213B51C
	mov r0, r5
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r5
	bl _ZdlPv
_0213B51C:
	mov r0, #0
	str r0, [r4, #0xff4]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_0213AE1812ov1_0213B528EP11CTouchPanel
_ZN17UnkClass_0213AE1812ov1_0213B528EP11CTouchPanel: ; 0x0213B528
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	mov r4, r0
	ldr r2, [r4]
	add r2, r2, #1
	str r2, [r4]
	ldr r2, [r4, #4]
	cmp r2, #9
	addls pc, pc, r2, lsl #2
	b _0213B5BC
_0213B550: ; jump table
	b _0213B5BC ; case 0
	b _0213B578 ; case 1
	b _0213B580 ; case 2
	b _0213B588 ; case 3
	b _0213B590 ; case 4
	b _0213B598 ; case 5
	b _0213B5A0 ; case 6
	b _0213B5A8 ; case 7
	b _0213B5B0 ; case 8
	b _0213B5B8 ; case 9
	arm_func_end _ZN17UnkClass_0213AE1812ov1_0213B528EP11CTouchPanel
_0213B578:
	bl ov1_0213B6B0
	b _0213B5BC
_0213B580:
	bl ov1_0213B6D0
	b _0213B5BC
_0213B588:
	bl ov1_0213B7C0
	b _0213B5BC
_0213B590:
	bl ov1_0213BC04
	b _0213B5BC
_0213B598:
	bl ov1_0213BCEC
	b _0213B5BC
_0213B5A0:
	bl ov1_0213BD0C
	b _0213B5BC
_0213B5A8:
	bl ov1_0213BDC0
	b _0213B5BC
_0213B5B0:
	bl ov1_0213BE30
	b _0213B5BC
_0213B5B8:
	bl ov1_0213BEE0
_0213B5BC:
	mov r7, #0
	add r6, r4, #0xfc
	mov r5, #0x64
_0213B5C8:
	mul r8, r7, r5
	add r0, r6, r8
	bl _ZN17UnkClass_0201179C12sub_020117B0Ev
	add r0, r4, r8
	ldr r2, [r0, #0x110]
	ldr r3, [r0, #0x114]
	mov r0, r4
	mov r1, r7
	bl ov1_0213C838
	add r0, r7, #1
	and r7, r0, #0xff
	cmp r7, #8
	blo _0213B5C8
	ldr r0, [r4, #0xd50]
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	mov r6, #0
	mov r1, #0x90000
	ldr r5, _0213B6AC ; =DAT_overlay_1_021404e8
	rsb r1, r1, #0
	mov fp, r6
	mov r0, #0x4c
	mov r2, #0x1c8
_0213B620:
	mla r8, r6, r2, r4
	ldr sb, [r5, r6, lsl #2]
	mov r7, fp
_0213B62C:
	mla sl, r7, r0, r8
	ldr lr, [sl, #0x810]
	ldr ip, [sl, #0x814]
	sub r3, lr, sb
	str r3, [sp, #0x10]
	cmp r3, r1
	addle r3, r3, #0x120000
	add r7, r7, #1
	strle r3, [sp, #0x10]
	str ip, [sp, #0x14]
	str ip, [sp, #0xc]
	ldr ip, [sp, #0x10]
	ldr r3, [sp, #0x14]
	and r7, r7, #0xff
	str ip, [sl, #0x810]
	str lr, [sp, #8]
	str ip, [sp]
	str r3, [sp, #4]
	str r3, [sl, #0x814]
	cmp r7, #6
	blo _0213B62C
	add r3, r6, #1
	and r6, r3, #0xff
	cmp r6, #3
	blo _0213B620
	mov r0, r4
	bl ov1_0213BF20
	ldr r0, [r4, #0xf8]
	mov r1, #0
	bl _ZN17UnkClass_0213CC2812ov1_0213E32CEi
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0213B6AC: .word DAT_overlay_1_021404e8

	arm_func_start ov1_0213B6B0
ov1_0213B6B0: ; 0x0213B6B0
	ldr r1, [r0]
	cmp r1, #8
	bxlo lr
	mov r1, #0
	str r1, [r0]
	mov r1, #2
	str r1, [r0, #4]
	bx lr
	arm_func_end ov1_0213B6B0

	arm_func_start ov1_0213B6D0
ov1_0213B6D0: ; 0x0213B6D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4]
	cmp r1, #0x14
	bhi _0213B720
	bhs _0213B774
	cmp r1, #0xc
	bhi _0213B714
	bhs _0213B75C
	cmp r1, #8
	bhi _0213B7A0
	cmp r1, #4
	blo _0213B7A0
	beq _0213B744
	cmp r1, #8
	beq _0213B750
	b _0213B7A0
	arm_func_end ov1_0213B6D0
_0213B714:
	cmp r1, #0x10
	beq _0213B768
	b _0213B7A0
_0213B720:
	cmp r1, #0x1c
	bhi _0213B738
	bhs _0213B78C
	cmp r1, #0x18
	beq _0213B780
	b _0213B7A0
_0213B738:
	cmp r1, #0x20
	beq _0213B798
	b _0213B7A0
_0213B744:
	mov r1, #0
	bl ov1_0213C8E8
	b _0213B7A0
_0213B750:
	mov r1, #1
	bl ov1_0213C8E8
	b _0213B7A0
_0213B75C:
	mov r1, #2
	bl ov1_0213C8E8
	b _0213B7A0
_0213B768:
	mov r1, #3
	bl ov1_0213C8E8
	b _0213B7A0
_0213B774:
	mov r1, #4
	bl ov1_0213C8E8
	b _0213B7A0
_0213B780:
	mov r1, #5
	bl ov1_0213C8E8
	b _0213B7A0
_0213B78C:
	mov r1, #6
	bl ov1_0213C8E8
	b _0213B7A0
_0213B798:
	mov r1, #7
	bl ov1_0213C8E8
_0213B7A0:
	ldr r0, [r4]
	cmp r0, #0x30
	ldmloia sp!, {r4, pc}
	mov r0, #0
	str r0, [r4]
	mov r0, #3
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}

	arm_func_start ov1_0213B7C0
ov1_0213B7C0: ; 0x0213B7C0
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	mov sl, r0
	mov r4, r1
	bl _ZN5CGame11GetInstanceEv
	ldr r0, [r0, #0xc]
	ldr r0, [r0, #0x14]
	cmp r0, #0
	beq _0213B818
	bl _ZN5CGame11GetInstanceEv
	ldr r0, [r0, #0x14]
	ldrh r0, [r0, #2]
	and r0, r0, #2
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	beq _0213B818
	mov r0, #1
	str r0, [sl, #0x14]
	mov r0, #0
	str r0, [sl]
	mov r0, #4
	str r0, [sl, #4]
	arm_func_end ov1_0213B7C0
_0213B818:
	ldrh r2, [r4, #0xa]
	ldrh r1, [r4, #0xc]
	ldrb r0, [r4, #4]
	sub r2, r2, #0x80
	sub r1, r1, #0x60
	mov r2, r2, lsl #0xc
	mov r1, r1, lsl #0xc
	mov r4, #0
	str r4, [sp, #0xc]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	cmp r0, #0
	addeq sp, sp, #0x18
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldrb r0, [sl, #0xd]
	mov sb, r4
	cmp r0, #0
	bls _0213B9CC
	sub r7, sp, #8
	mov r6, #1
	mov r8, r4
	add fp, sp, #0x10
_0213B870:
	ldr r0, [sl, #0x40]
	ldr r0, [r0, sb, lsl #2]
	cmp r0, #0
	beq _0213B9B8
	add r0, sl, sb, lsl #6
	add r0, r0, #0x17c
	add r0, r0, #0xc00
	str r8, [sp, #8]
	ldmia r0, {r0, r1, r2, r3}
	stmia r7, {r0, r1, r2, r3}
	ldmia r7, {r2, r3}
	ldmia fp, {r0, r1}
	bl _Z12sub_020060007Point2D9Rectanglem
	cmp r0, #0
	beq _0213B9B8
	ldrb r0, [sl, #0xe]
	tst r0, r6, lsl sb
	beq _0213B9B8
	ldr r0, [sl, #8]
	cmp r0, #1
	ldreqb r0, [sl, #0xc]
	cmpeq r0, sb
	moveq r4, r6
	beq _0213B9B8
	mov r0, #1
	str r0, [sl, #8]
	strb sb, [sl, #0xc]
	and r0, sb, #0xff
	ldr r1, [sl, #0x3c]
	mov r0, r0, lsl #1
	ldrh r1, [r1, r0]
	ldr r0, [sl, #0xf0]
	bl sub_020107A8
	mov r5, r0
	ldrb r1, [r5, #4]
	mov r0, sl
	bl ov1_0213CA78
	bl _ZN5CGame11GetInstanceEv
	ldrb r1, [sl, #0xc]
	ldr r2, [sl, #0x3c]
	ldr r0, [r0, #0xc]
	mov r1, r1, lsl #1
	ldrh r1, [r2, r1]
	bl _ZN12CBattleScene12ov1_0211F010Et
	mov r4, r0
	ldrb r1, [r5, #4]
	ldrb r2, [r5, #5]
	ldrb r3, [r5, #6]
	ldr r0, [sl, #0xf8]
	bl _ZN17UnkClass_0213CC2812ov1_0213ECB4Eiii
	mov r1, r4
	mov r4, r0
	str r4, [sl, #0x10]
	ldr r0, [sl, #0xf8]
	bl ov1_0213E8BC
	ldr r0, [sl, #0xf8]
	bl ov1_0213E68C
	cmp r4, #0
	beq _0213B970
	cmp r4, #1
	beq _0213B988
	cmp r4, #2
	beq _0213B9A0
	b _0213B9B4
_0213B970:
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xc
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _0213B9B4
_0213B988:
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xfb
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _0213B9B4
_0213B9A0:
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xfc
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
_0213B9B4:
	mov r4, #1
_0213B9B8:
	ldrb r0, [sl, #0xd]
	add r1, sb, #1
	and sb, r1, #0xff
	cmp sb, r0
	blo _0213B870
_0213B9CC:
	add r0, sl, #0x37c
	mov r1, #0
	str r1, [sp, #8]
	add r0, r0, #0xc00
	sub r5, sp, #8
	ldmia r0, {r0, r1, r2, r3}
	stmia r5, {r0, r1, r2, r3}
	add r0, sp, #0x10
	ldmia r5, {r2, r3}
	ldmia r0, {r0, r1}
	bl _Z12sub_020060007Point2D9Rectanglem
	cmp r0, #0
	ldrne r0, [sl, #8]
	mov r1, #0
	cmpne r0, #0
	movne r0, #1
	strne r0, [sp, #0xc]
	add r0, sl, #0x3bc
	str r1, [sp, #8]
	add r0, r0, #0xc00
	sub r5, sp, #8
	ldmia r0, {r0, r1, r2, r3}
	stmia r5, {r0, r1, r2, r3}
	add r0, sp, #0x10
	ldmia r5, {r2, r3}
	ldmia r0, {r0, r1}
	bl _Z12sub_020060007Point2D9Rectanglem
	cmp r0, #0
	beq _0213BA84
	mov r0, #1
	str r0, [sl, #0x14]
	mov r0, #0
	str r0, [sl]
	mov r0, #4
	str r0, [sl, #4]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xc
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [sl, #0xf8]
	mov r1, #0
	bl _ZN17UnkClass_0213CC2812ov1_0213EF40Ei
	ldr r0, [sl, #0xf8]
	bl _ZN17UnkClass_0213CC2812ov1_0213EDDCEv
	mov r4, #1
_0213BA84:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq _0213BB8C
	mov r0, #0
	str r0, [sl, #0x14]
	ldrb r2, [sl, #0xc]
	ldr r1, _0213BBFC ; =DAT_overlay_1_021404d8
	add r3, sl, #0xfc
	mov r0, #0x64
	mla r0, r2, r0, r3
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldrb r1, [sl, #0xc]
	ldr r2, [sl, #0x3c]
	ldr r0, [sl, #0xf0]
	mov r1, r1, lsl #1
	ldrh r1, [r2, r1]
	bl sub_020107A8
	ldrb r1, [r0, #4]
	add r0, sl, #0x700
	strh r1, [r0, #0x8a]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r1, #1
	mov r2, #0x40
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r1, #1
	mov r2, #0x40
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [sl, #0xff8]
	bl _ZN17UnkClass_0201AD605CloseEv
	bl _ZN5CGame11GetInstanceEv
	ldr r0, [r0, #0xc]
	ldrb r1, [sl, #0xf]
	cmp r1, #0
	beq _0213BB48
	ldrb r1, [sl, #0xc]
	cmp r1, #0
	bne _0213BB48
	ldr r2, [sl, #0x3c]
	mov r1, r1, lsl #1
	ldrh r1, [r2, r1]
	mov r2, #1
	bl _ZN12CBattleScene12ov1_0211EF74Etm
	b _0213BB60
_0213BB48:
	ldrb r1, [sl, #0xc]
	ldr r3, [sl, #0x3c]
	mov r2, #0
	mov r1, r1, lsl #1
	ldrh r1, [r3, r1]
	bl _ZN12CBattleScene12ov1_0211EF74Etm
_0213BB60:
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xc
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #0
	str r0, [sl]
	mov r0, #5
	add sp, sp, #0x18
	str r0, [sl, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0213BB8C:
	cmp r4, #0
	addne sp, sp, #0x18
	ldmneia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [sl, #8]
	cmp r0, #0
	addeq sp, sp, #0x18
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, #0
	str r0, [sl, #8]
	bl _ZN5CGame11GetInstanceEv
	mov r4, r0
	add r0, r4, #0x1000
	ldr r0, [r0, #0x490]
	mov r1, #1
	bl _ZN17UnkClass_020091E812sub_0200A088Em
	add r0, r4, #0x1000
	ldr r0, [r0, #0x49c]
	ldr r1, _0213BC00 ; =s_sPokeSelect_overlay_1_02141f5c
	bl sub_02034184
	ldr r0, [sl, #0xf8]
	bl _ZN17UnkClass_0213CC2812ov1_0213EDDCEv
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xc
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0213BBFC: .word DAT_overlay_1_021404d8
_0213BC00: .word s_sPokeSelect_overlay_1_02141f5c

	arm_func_start ov1_0213BC04
ov1_0213BC04: ; 0x0213BC04
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4]
	cmp r1, #0x14
	bhi _0213BC54
	bhs _0213BCA8
	cmp r1, #0xc
	bhi _0213BC48
	bhs _0213BC90
	cmp r1, #8
	bhi _0213BCD4
	cmp r1, #4
	blo _0213BCD4
	beq _0213BC78
	cmp r1, #8
	beq _0213BC84
	b _0213BCD4
	arm_func_end ov1_0213BC04
_0213BC48:
	cmp r1, #0x10
	beq _0213BC9C
	b _0213BCD4
_0213BC54:
	cmp r1, #0x1c
	bhi _0213BC6C
	bhs _0213BCC0
	cmp r1, #0x18
	beq _0213BCB4
	b _0213BCD4
_0213BC6C:
	cmp r1, #0x20
	beq _0213BCCC
	b _0213BCD4
_0213BC78:
	mov r1, #0
	bl ov1_0213C9B8
	b _0213BCD4
_0213BC84:
	mov r1, #1
	bl ov1_0213C9B8
	b _0213BCD4
_0213BC90:
	mov r1, #2
	bl ov1_0213C9B8
	b _0213BCD4
_0213BC9C:
	mov r1, #3
	bl ov1_0213C9B8
	b _0213BCD4
_0213BCA8:
	mov r1, #4
	bl ov1_0213C9B8
	b _0213BCD4
_0213BCB4:
	mov r1, #5
	bl ov1_0213C9B8
	b _0213BCD4
_0213BCC0:
	mov r1, #6
	bl ov1_0213C9B8
	b _0213BCD4
_0213BCCC:
	mov r1, #7
	bl ov1_0213C9B8
_0213BCD4:
	ldr r0, [r4]
	cmp r0, #0x30
	ldmloia sp!, {r4, pc}
	mov r0, r4
	bl ov1_0213C60C
	ldmia sp!, {r4, pc}

	arm_func_start ov1_0213BCEC
ov1_0213BCEC: ; 0x0213BCEC
	ldr r1, [r0]
	cmp r1, #0x40
	bxlo lr
	mov r1, #0
	str r1, [r0]
	mov r1, #6
	str r1, [r0, #4]
	bx lr
	arm_func_end ov1_0213BCEC

	arm_func_start ov1_0213BD0C
ov1_0213BD0C: ; 0x0213BD0C
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #1
	bne _0213BD90
	add r1, sp, #8
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	ldrb r1, [r4, #0xc]
	add r2, r4, #0xfc
	mov r0, #0x64
	mla r0, r1, r0, r2
	ldr r1, _0213BDB8 ; =DAT_overlay_1_021404c0
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	mov r1, #0x10
	ldr r0, _0213BDBC ; =DAT_overlay_1_021404b8
	str r1, [sp, #4]
	ldr r1, [r0, #0x18]
	ldr r0, [r0, #0x1c]
	sub ip, sp, #4
	str r1, [ip]
	str r0, [ip, #4]
	ldrb r2, [r4, #0xc]
	add r3, r4, #0xfc
	mov r0, #0x64
	mla r0, r2, r0, r3
	add r1, sp, #8
	ldr r3, [ip]
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011B18E7Point2DS0_m
	arm_func_end ov1_0213BD0C
_0213BD90:
	ldr r0, [r4]
	cmp r0, #0x10
	addlo sp, sp, #0x10
	ldmloia sp!, {r4, pc}
	mov r0, #0
	str r0, [r4]
	mov r0, #7
	str r0, [r4, #4]
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213BDB8: .word DAT_overlay_1_021404c0
_0213BDBC: .word DAT_overlay_1_021404b8

	arm_func_start ov1_0213BDC0
ov1_0213BDC0: ; 0x0213BDC0
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #1
	bne _0213BE10
	bl _ZN5CGame11GetInstanceEv
	ldrb r1, [r4, #0xc]
	add r0, r0, #0x1000
	ldr r2, [r4, #0x3c]
	mov r1, r1, lsl #1
	ldrh r1, [r2, r1]
	ldr r0, [r0, #0x434]
	bl sub_020107A8
	ldrh r5, [r0]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, r5
	mov r2, #0x40
	bl _ZN17UnkClass_0203447812sub_02034CF4Eii
	arm_func_end ov1_0213BDC0
_0213BE10:
	ldr r0, [r4]
	cmp r0, #0x30
	ldmloia sp!, {r3, r4, r5, pc}
	mov r0, #0
	str r0, [r4]
	mov r0, #8
	str r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_0213BE30
ov1_0213BE30: ; 0x0213BE30
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #1
	bne _0213BEB0
	add r3, sp, #8
	mov r0, #0
	str r0, [r3]
	str r0, [r3, #4]
	ldrb r1, [r4, #0xc]
	add r2, r4, #0xfc
	mov r0, #0x64
	mla r0, r1, r0, r2
	ldmia r3, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	mov r1, #0x10
	ldr r0, _0213BED8 ; =DAT_overlay_1_021404b8
	str r1, [sp, #4]
	ldr r1, [r0, #0x10]
	ldr r0, [r0, #0x14]
	sub ip, sp, #4
	str r1, [ip]
	str r0, [ip, #4]
	ldrb r2, [r4, #0xc]
	add r3, r4, #0xfc
	mov r0, #0x64
	mla r0, r2, r0, r3
	ldr r1, _0213BEDC ; =DAT_overlay_1_021404e0
	ldr r3, [ip]
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011B18E7Point2DS0_m
	arm_func_end ov1_0213BE30
_0213BEB0:
	ldr r0, [r4]
	cmp r0, #0x10
	addlo sp, sp, #0x10
	ldmloia sp!, {r4, pc}
	mov r0, #0
	str r0, [r4]
	mov r0, #9
	str r0, [r4, #4]
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213BED8: .word DAT_overlay_1_021404b8
_0213BEDC: .word DAT_overlay_1_021404e0

	arm_func_start ov1_0213BEE0
ov1_0213BEE0: ; 0x0213BEE0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r2, [r4]
	mov r0, #0x1f
	mov r1, #1
	mov r3, #0x10
	bl _Z17LinearInterpolatellll
	and r1, r0, #0xff
	mov r0, r4
	bl ov1_0213CBD8
	ldr r0, [r4]
	cmp r0, #0x10
	ldmloia sp!, {r4, pc}
	mov r0, r4
	bl ov1_0213C60C
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213BEE0

	arm_func_start ov1_0213BF20
ov1_0213BF20: ; 0x0213BF20
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldrb r0, [r4, #0x18]
	cmp r0, #0
	ldrb r0, [r4, #0x19]
	beq _0213BF54
	add r1, r0, #1
	and r0, r1, #0xff
	cmp r0, #0x40
	strb r1, [r4, #0x19]
	movhs r0, #0
	strcsb r0, [r4, #0x18]
	b _0213BF68
	arm_func_end ov1_0213BF20
_0213BF54:
	sub r0, r0, #1
	strb r0, [r4, #0x19]
	tst r0, #0xff
	moveq r0, #1
	streqb r0, [r4, #0x18]
_0213BF68:
	ldrb r2, [r4, #0x19]
	mov r0, #0x1f
	mov r1, #0xc
	mov r3, #0x40
	bl _Z17LinearInterpolatellll
	and r5, r0, #0xff
	ldrb r2, [r4, #0x19]
	mov r0, #0x1f
	mov r1, #0xc
	mov r3, #0x40
	bl _Z17LinearInterpolatellll
	and r6, r0, #0xff
	mov r0, #0x1f
	ldrb r2, [r4, #0x19]
	mov r1, r0
	mov r3, #0x40
	bl _Z17LinearInterpolatellll
	and r1, r0, #0xff
	orr r0, r5, r6, lsl #5
	orr r0, r0, r1, lsl #10
	mov r0, r0, lsl #0x10
	mov r3, #0
	mov r2, r0, lsr #0x10
_0213BFC4:
	add r0, r3, #1
	add r1, r4, r3, lsl #1
	and r3, r0, #0xff
	strh r2, [r1, #0x1a]
	cmp r3, #0x10
	blo _0213BFC4
	add r0, r4, #0x1a
	mov r1, #0x20
	bl DC_FlushRange
	add r0, r4, #0x1a
	mov r1, #0xe0
	mov r2, #0x20
	bl GX_LoadOBJPltt
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17UnkClass_0213AE1812ov1_0213BFFCEP8Camera2D
_ZN17UnkClass_0213AE1812ov1_0213BFFCEP8Camera2D: ; 0x0213BFFC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r2, [r5, #4]
	mov r4, r1
	cmp r2, #9
	addls pc, pc, r2, lsl #2
	ldmia sp!, {r3, r4, r5, pc}
_0213C018: ; jump table
	ldmia sp!, {r3, r4, r5, pc} ; case 0
	b _0213C040 ; case 1
	b _0213C040 ; case 2
	b _0213C040 ; case 3
	b _0213C040 ; case 4
	b _0213C078 ; case 5
	b _0213C078 ; case 6
	b _0213C078 ; case 7
	b _0213C078 ; case 8
	b _0213C078 ; case 9
	arm_func_end _ZN17UnkClass_0213AE1812ov1_0213BFFCEP8Camera2D
_0213C040:
	bl ov1_0213C0F8
	mov r0, r5
	mov r1, r4
	bl ov1_0213C090
	mov r0, r5
	mov r1, r4
	bl ov1_0213C2A0
	ldr r0, [r5, #8]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r5
	mov r1, r4
	bl ov1_0213C264
	ldmia sp!, {r3, r4, r5, pc}
_0213C078:
	ldrb r2, [r5, #0xc]
	bl ov1_0213C1A8
	mov r0, r5
	mov r1, r4
	bl ov1_0213C1D8
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov1_0213C090
ov1_0213C090: ; 0x0213C090
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r7, r0
	add r0, r7, #0x1c
	mov r6, r1
	mov r5, #0
	add r4, r0, #0x400
	mov r8, #0x4c
	arm_func_end ov1_0213C090
_0213C0AC:
	add r0, r7, r5, lsl #1
	add r0, r0, #0xd00
	ldrh r1, [r0, #0x54]
	ldr r0, [r7, #0xd50]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	mul r2, r5, r8
	add r1, r7, r2
	add r1, r1, #0x400
	strh r0, [r1, #0x46]
	add r0, r4, r2
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #1
	and r5, r0, #0xff
	cmp r5, #8
	blo _0213C0AC
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov1_0213C0F8
ov1_0213C0F8: ; 0x0213C0F8
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	mov sl, r0
	bl _ZN5CGame11GetInstanceEv
	ldrb r2, [sl, #0xd]
	mov r8, #0
	add r1, r0, #0x24
	cmp r2, #0
	ldmlsia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	mov r4, r8
	mov r6, r8
	mov r7, r8
	arm_func_end ov1_0213C0F8
_0213C124:
	ldr r0, [sl, #0x40]
	ldr r0, [r0, r8, lsl #2]
	cmp r0, #0
	beq _0213C190
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0x44]
	mov r2, r7
	mov r3, r7
	bl _ZN17UnkClass_0200E96012sub_0200EB78EP9GXOamAttrii
	ldrb r2, [sl, #0xc]
	mov r1, r0
	cmp r8, r2
	bne _0213C190
	ldr r0, [sl, #8]
	cmp r0, #0
	beq _0213C190
	mov sb, r6
	add r5, sl, r8, lsl #4
_0213C16C:
	add r0, r5, sb, lsl #2
	ldr r0, [r0, #0x64]
	mov r2, r4
	mov r3, r4
	bl _ZN17UnkClass_0200E96012sub_0200EB78EP9GXOamAttrii
	add sb, sb, #1
	mov r1, r0
	cmp sb, #4
	blt _0213C16C
_0213C190:
	ldrb r0, [sl, #0xd]
	add r2, r8, #1
	and r8, r2, #0xff
	cmp r8, r0
	blo _0213C124
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start ov1_0213C1A8
ov1_0213C1A8: ; 0x0213C1A8
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r2
	bl _ZN5CGame11GetInstanceEv
	mov r1, r0
	add r0, r5, r4, lsl #2
	mov r2, #0
	ldr r0, [r0, #0x44]
	mov r3, r2
	add r1, r1, #0x24
	bl _ZN17UnkClass_0200E96012sub_0200EB78EP9GXOamAttrii
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_0213C1A8

	arm_func_start ov1_0213C1D8
ov1_0213C1D8: ; 0x0213C1D8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov fp, r0
	add r0, fp, #0x3f8
	mov sl, r1
	mov r7, #0
	add r6, r0, #0x400
	mov r4, #0x4c
	mov r5, #0x1c8
	arm_func_end ov1_0213C1D8
_0213C1F8:
	mla sb, r7, r5, r6
	mov r8, #0
_0213C200:
	mla r0, r8, r4, sb
	ldr r2, [r0]
	mov r1, sl
	ldr r2, [r2, #8]
	blx r2
	add r0, r8, #1
	and r8, r0, #0xff
	cmp r8, #6
	blo _0213C200
	add r0, r7, #1
	and r7, r0, #0xff
	cmp r7, #3
	blo _0213C1F8
	add r0, fp, #0x760
	ldr r2, [r0]
	mov r1, sl
	ldr r2, [r2, #8]
	blx r2
	add r0, fp, #0x3ac
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, sl
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov1_0213C264
ov1_0213C264: ; 0x0213C264
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #0x27c
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x314
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov1_0213C264

	arm_func_start ov1_0213C2A0
ov1_0213C2A0: ; 0x0213C2A0
	stmdb sp!, {r3, lr}
	add r0, r0, #0x2c8
	add r0, r0, #0x400
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, pc}
	arm_func_end ov1_0213C2A0

	arm_func_start _ZN17UnkClass_0213AE1812ov1_0213C2BCEiPP17UnkClass_0200ECD0Pthi
_ZN17UnkClass_0213AE1812ov1_0213C2BCEiPP17UnkClass_0200ECD0Pthi: ; 0x0213C2BC
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x1c
	mov r4, #0x4000000
	ldr r6, [r4]
	ldr r5, _0213C5D8 ; =0x00300010
	mov sl, r0
	and r0, r6, r5
	str r0, [sl, #0xec]
	ldr r5, [r4]
	ldr r0, _0213C5DC ; =0xFFCFFFEF
	mov r8, #0
	and r0, r5, r0
	orr r0, r0, #0x10
	str r0, [r4]
	ldr r5, [r4]
	ldr r0, [r4]
	and r5, r5, #0x1f00
	mov r6, r5, lsr #8
	bic r5, r0, #0x1f00
	orr r0, r6, #0x10
	orr r0, r5, r0, lsl #8
	str r0, [r4]
	str r2, [sl, #0x40]
	str r3, [sl, #0x3c]
	strb r1, [sl, #0xd]
	mov r6, r8
	mov r4, #7
	mov fp, r8
	mov r7, r8
	arm_func_end _ZN17UnkClass_0213AE1812ov1_0213C2BCEiPP17UnkClass_0200ECD0Pthi
_0213C330:
	ldr r0, [sl, #0x40]
	ldr r0, [r0, r8, lsl #2]
	cmp r0, #0
	beq _0213C398
	mov r1, fp
	mov r2, fp
	mov r3, fp
	str fp, [sp]
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	add r1, sl, r8, lsl #2
	mov sb, r7
	str r0, [r1, #0x44]
	add r5, sl, r8, lsl #4
_0213C364:
	str r6, [sp]
	ldr r0, [sl, #0x40]
	mov r1, r6
	ldr r0, [r0, r8, lsl #2]
	mov r2, r6
	mov r3, r6
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	add r1, r5, sb, lsl #2
	add sb, sb, #1
	str r0, [r1, #0x64]
	strh r4, [r0, #0x1a]
	cmp sb, #4
	blt _0213C364
_0213C398:
	add r0, r8, #1
	and r8, r0, #0xff
	cmp r8, #8
	blo _0213C330
	ldr r0, _0213C5E0 ; =DAT_overlay_1_021404b8
	add r6, sp, #0x14
	ldmia r0, {r7, sb}
	str r7, [sp, #4]
	str sb, [sp, #8]
	str r7, [sp, #0x14]
	str sb, [sp, #0x18]
	str r7, [sp, #0xc]
	str sb, [sp, #0x10]
	mov r8, #0
	add r5, sl, #0xfc
	mov fp, #0x4c
	mov r4, #0x64
_0213C3DC:
	mla r1, r8, fp, sl
	str r7, [r1, #0x434]
	mla r0, r8, r4, r5
	str sb, [r1, #0x438]
	ldmia r6, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	mov r0, sl
	mov r1, r8
	mov r2, r7
	mov r3, sb
	bl ov1_0213C838
	add r0, r8, #1
	and r8, r0, #0xff
	cmp r8, #8
	blo _0213C3DC
	mov r1, #0
	str r1, [sl, #8]
	strb r1, [sl, #0xc]
	mov r1, #1
	mov r0, sl
	str r1, [sl, #0x14]
	bl ov1_0213CAC8
	mov r0, sl
	mov r1, #0x1f
	bl ov1_0213CBD8
	ldrb r2, [sp, #0x40]
	ldr r0, [sp, #0x44]
	ldr r3, _0213C5E4 ; =0x0000294A
	strb r2, [sl, #0xe]
	strb r0, [sl, #0xf]
	mov r0, #0
	ldr r5, _0213C5E8 ; =0x00007FFF
	mov r1, sl
	mov r7, #1
	mov r6, r0
_0213C468:
	ldr r2, [sl, #0x40]
	ldr r2, [r2, r0, lsl #2]
	cmp r2, #0
	beq _0213C4A8
	ldrb r2, [sl, #0xe]
	tst r2, r7, lsl r0
	add r2, sl, r0, lsl #2
	ldr r4, [r2, #0x44]
	beq _0213C49C
	add r2, r1, #0x400
	strb r6, [r4, #0x28]
	strh r5, [r2, #0x24]
	b _0213C4A8
_0213C49C:
	add r2, r1, #0x400
	strb r7, [r4, #0x28]
	strh r3, [r2, #0x24]
_0213C4A8:
	add r0, r0, #1
	cmp r0, #8
	add r1, r1, #0x4c
	blt _0213C468
	mov sb, #0
	mov r5, #1
	mov r4, #2
	mov r6, sb
	mov r7, sb
	mov r8, r5
_0213C4D0:
	ldrb r0, [sl, #0xe]
	tst r0, r8, lsl sb
	bne _0213C4F8
	add r0, sl, sb, lsl #1
	add r0, r0, #0xd00
	ldrh r1, [r0, #0x54]
	ldr r0, [sl, #0xd50]
	mov r2, r7
	bl _ZN17UnkClass_0200878812sub_02008990Ett
	b _0213C584
_0213C4F8:
	ldr r1, [sl, #0x3c]
	mov r0, sb, lsl #1
	ldrh r1, [r1, r0]
	ldr r0, [sl, #0xf0]
	bl sub_020107A8
	ldrb r1, [r0, #4]
	ldr r0, [sl, #0xf8]
	bl ov1_0213EC40
	cmp r0, #0
	beq _0213C534
	cmp r0, #1
	beq _0213C550
	cmp r0, #2
	beq _0213C56C
	b _0213C584
_0213C534:
	add r0, sl, sb, lsl #1
	add r0, r0, #0xd00
	ldrh r1, [r0, #0x54]
	ldr r0, [sl, #0xd50]
	mov r2, r6
	bl _ZN17UnkClass_0200878812sub_02008990Ett
	b _0213C584
_0213C550:
	add r0, sl, sb, lsl #1
	add r0, r0, #0xd00
	ldrh r1, [r0, #0x54]
	ldr r0, [sl, #0xd50]
	mov r2, r5
	bl _ZN17UnkClass_0200878812sub_02008990Ett
	b _0213C584
_0213C56C:
	add r0, sl, sb, lsl #1
	add r0, r0, #0xd00
	ldrh r1, [r0, #0x54]
	ldr r0, [sl, #0xd50]
	mov r2, r4
	bl _ZN17UnkClass_0200878812sub_02008990Ett
_0213C584:
	add r0, sb, #1
	and sb, r0, #0xff
	cmp sb, #8
	blo _0213C4D0
	ldr r0, _0213C5EC ; =0x04000050
	mov r1, #0
	mov r2, #1
	mov r3, #8
	str r1, [sp]
	bl G2x_SetBlendAlpha_
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	ldr r1, _0213C5F0 ; =s_sPokeSelect_overlay_1_02141f5c
	bl sub_02034184
	mov r0, #0
	str r0, [sl]
	mov r0, #1
	str r0, [sl, #4]
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0213C5D8: .word 0x00300010
_0213C5DC: .word 0xFFCFFFEF
_0213C5E0: .word DAT_overlay_1_021404b8
_0213C5E4: .word 0x0000294A
_0213C5E8: .word 0x00007FFF
_0213C5EC: .word 0x04000050
_0213C5F0: .word s_sPokeSelect_overlay_1_02141f5c

	arm_func_start _ZN17UnkClass_0213AE1812ov1_0213C5F4Ev
_ZN17UnkClass_0213AE1812ov1_0213C5F4Ev: ; 0x0213C5F4
	ldr r0, [r0, #0x14]
	bx lr
	arm_func_end _ZN17UnkClass_0213AE1812ov1_0213C5F4Ev

	arm_func_start _ZN17UnkClass_0213AE1812ov1_0213C5FCEv
_ZN17UnkClass_0213AE1812ov1_0213C5FCEv: ; 0x0213C5FC
	ldrb r0, [r0, #0xc]
	bx lr
	arm_func_end _ZN17UnkClass_0213AE1812ov1_0213C5FCEv

	arm_func_start _ZN17UnkClass_0213AE1812ov1_0213C604Ev
_ZN17UnkClass_0213AE1812ov1_0213C604Ev: ; 0x0213C604
	ldr r0, [r0, #0x10]
	bx lr
	arm_func_end _ZN17UnkClass_0213AE1812ov1_0213C604Ev

	arm_func_start ov1_0213C60C
ov1_0213C60C: ; 0x0213C60C
	stmdb sp!, {r3, r4, r5, lr}
	mov r2, #0x4000000
	mov r4, r0
	ldr r1, [r2]
	ldr r0, _0213C678 ; =0xFFCFFFEF
	ldr r3, [r4, #0xec]
	and r0, r1, r0
	orr r0, r0, r3
	str r0, [r2]
	ldr r0, [r2]
	mov r5, #0
	bic r0, r0, #0x1f00
	orr r0, r0, #0x100
	str r0, [r2]
	arm_func_end ov1_0213C60C
_0213C644:
	ldr r0, [r4, #0x40]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	beq _0213C658
	bl _ZN17UnkClass_0200ECD012sub_0200F6C4Ev
_0213C658:
	add r0, r5, #1
	and r5, r0, #0xff
	cmp r5, #8
	blo _0213C644
	mov r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0213C678: .word 0xFFCFFFEF

	arm_func_start _ZN17UnkClass_0213AE1812ov1_0213C67CEi
_ZN17UnkClass_0213AE1812ov1_0213C67CEi: ; 0x0213C67C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r5, r0
	add r0, r5, #0x1c
	mov r4, r1
	mov r7, #0
	add r6, r0, #0x400
	mov sb, #0x4c
	arm_func_end _ZN17UnkClass_0213AE1812ov1_0213C67CEi
_0213C698:
	mul r2, r7, sb
	add r8, r5, r2
	add r0, r8, #0x400
	ldrh r1, [r0, #0x46]
	add r0, r6, r2
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r1, r0, #1
	add r0, r7, #1
	add r4, r4, r1
	and r7, r0, #0xff
	str r4, [r8, #0x420]
	cmp r7, #8
	blo _0213C698
	add r0, r5, #0x600
	ldrh r1, [r0, #0xa6]
	add r0, r5, #0x27c
	add r0, r0, #0x400
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r0, #1
	add r4, r4, r0
	add r0, r5, #0x2c8
	str r4, [r5, #0x680]
	add r1, r5, #0x600
	ldrh r1, [r1, #0xf2]
	add r0, r0, #0x400
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r0, #1
	add r4, r4, r0
	add r0, r5, #0x314
	str r4, [r5, #0x6cc]
	add r1, r5, #0x700
	ldrh r1, [r1, #0x3e]
	add r0, r0, #0x400
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r0, #1
	add r4, r4, r0
	str r4, [r5, #0x718]
	add r0, r5, #0x700
	ldrh r1, [r0, #0x8a]
	add r0, r5, #0x760
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r0, #1
	add r4, r4, r0
	add r0, r5, #0x3ac
	str r4, [r5, #0x764]
	add r1, r5, #0x700
	ldrh r1, [r1, #0xd6]
	add r0, r0, #0x400
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r0, #1
	add r4, r4, r0
	add r0, r5, #0x388
	str r4, [r5, #0x7b0]
	mov r7, #0
	add r6, r0, #0x800
	mov sb, #0x4c
_0213C778:
	mul r2, r7, sb
	add r8, r5, r2
	add r0, r8, #0xb00
	ldrh r1, [r0, #0xb2]
	add r0, r6, r2
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r1, r0, #1
	add r0, r7, #1
	add r4, r4, r1
	and r7, r0, #0xff
	str r4, [r8, #0xb8c]
	cmp r7, #6
	blo _0213C778
	mov r7, #0
	add r6, r5, #0x9c0
	mov sb, #0x4c
_0213C7B8:
	mul r2, r7, sb
	add r8, r5, r2
	add r0, r8, #0x900
	ldrh r1, [r0, #0xea]
	add r0, r6, r2
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r1, r0, #1
	add r0, r7, #1
	add r4, r4, r1
	and r7, r0, #0xff
	str r4, [r8, #0x9c4]
	cmp r7, #6
	blo _0213C7B8
	add r0, r5, #0x3f8
	mov r7, #0
	add r6, r0, #0x400
	mov sb, #0x4c
_0213C7FC:
	mul r2, r7, sb
	add r8, r5, r2
	add r0, r8, #0x800
	ldrh r1, [r0, #0x22]
	add r0, r6, r2
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r1, r0, #1
	add r0, r7, #1
	add r4, r4, r1
	and r7, r0, #0xff
	str r4, [r8, #0x7fc]
	cmp r7, #6
	blo _0213C7FC
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start ov1_0213C838
ov1_0213C838: ; 0x0213C838
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r6, r1
	mov r0, #0x4c
	mla r0, r6, r0, r7
	str r2, [r0, #0x434]
	str r3, [r0, #0x438]
	add r0, r7, r6, lsl #6
	str r2, [r0, #0xd7c]
	str r3, [r0, #0xd80]
	ldr r0, [r7, #0x40]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mov r2, r2, asr #0xc
	mov r1, r3, asr #0xc
	add r0, r7, r6, lsl #2
	add r4, r2, #0x80
	add r5, r1, #0x60
	ldr r0, [r0, #0x44]
	mov r1, r4
	mov r2, r5
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add r0, r7, r6, lsl #4
	ldr r0, [r0, #0x64]
	mov r1, r4
	sub r2, r5, #2
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add r0, r7, r6, lsl #4
	ldr r0, [r0, #0x68]
	mov r1, r4
	add r2, r5, #2
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add r0, r7, r6, lsl #4
	ldr r0, [r0, #0x6c]
	sub r1, r4, #2
	mov r2, r5
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add r0, r7, r6, lsl #4
	ldr r0, [r0, #0x70]
	add r1, r4, #2
	mov r2, r5
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end ov1_0213C838

	arm_func_start ov1_0213C8E8
ov1_0213C8E8: ; 0x0213C8E8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x18
	mov r7, r0
	ldrb r2, [r7, #0xd]
	mov r6, r1
	cmp r6, r2
	addhs sp, sp, #0x18
	ldmhsia sp!, {r3, r4, r5, r6, r7, pc}
	mov r0, #0x64
	mul r4, r6, r0
	ldr r0, _0213C9B0 ; =DAT_overlay_1_021404f4
	add r5, r7, #0xfc
	add r0, r0, r2, lsl #6
	ldr r1, [r0, r6, lsl #3]
	add r0, r5, r4
	add r1, r1, #0x100000
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	ldrb r2, [r7, #0xd]
	ldr r1, _0213C9B4 ; =DAT_overlay_1_021404f8
	add r0, r5, r4
	add r1, r1, r2, lsl #6
	ldr r1, [r1, r6, lsl #3]
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldrb r2, [r7, #0xd]
	ldr r0, _0213C9B0 ; =DAT_overlay_1_021404f4
	mov r1, #0x10
	add r0, r0, r2, lsl #6
	ldr r7, [r0, r6, lsl #3]
	add r0, r0, r6, lsl #3
	ldr r6, [r0, #4]
	add r2, r7, #0x20000
	str r1, [sp, #4]
	sub r1, sp, #4
	stmia r1, {r2, r6}
	ldr r3, [r1]
	add r0, r5, r4
	add r1, sp, #8
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	str r2, [sp, #0x10]
	str r6, [sp, #0x14]
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011B18E7Point2DS0_m
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xc
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0213C9B0: .word DAT_overlay_1_021404f4
_0213C9B4: .word DAT_overlay_1_021404f8
	arm_func_end ov1_0213C8E8

	arm_func_start ov1_0213C9B8
ov1_0213C9B8: ; 0x0213C9B8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x20
	mov r7, r0
	ldrb r2, [r7, #0xd]
	mov r6, r1
	cmp r6, r2
	addhs sp, sp, #0x20
	ldmhsia sp!, {r3, r4, r5, r6, r7, pc}
	mov r0, #0x64
	mul r4, r6, r0
	ldr r0, _0213CA74 ; =DAT_overlay_1_021404f4
	add r5, r7, #0xfc
	add r0, r0, r2, lsl #6
	add r1, r0, r6, lsl #3
	add r0, r5, r4
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldrb r2, [r7, #0xd]
	ldr r1, _0213CA74 ; =DAT_overlay_1_021404f4
	mov r0, #0x10
	add r1, r1, r2, lsl #6
	ldr ip, [r1, r6, lsl #3]
	add r1, r1, r6, lsl #3
	ldr r7, [r1, #4]
	add r1, ip, #0x20000
	str r0, [sp, #4]
	sub r0, sp, #4
	stmia r0, {r1, r7}
	ldr r3, [r0]
	sub r2, ip, #0x100000
	add r6, sp, #0x18
	str r7, [sp, #0x1c]
	add r0, r5, r4
	str r2, [sp, #0x18]
	str r1, [sp, #0x10]
	str ip, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x14]
	ldmia r6, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011B18E7Point2DS0_m
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xc
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0213CA74: .word DAT_overlay_1_021404f4
	arm_func_end ov1_0213C9B8

	arm_func_start ov1_0213CA78
ov1_0213CA78: ; 0x0213CA78
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	mov r2, r1
	ldr r1, _0213CAC4 ; =s_sAssist_03d_overlay_1_02141f68
	add r0, sp, #0
	and r2, r2, #0xff
	bl OS_SPrintf
	bl _ZN5CGame11GetInstanceEv
	mov r4, r0
	add r0, r4, #0x1000
	ldr r0, [r0, #0x490]
	mov r1, #1
	bl _ZN17UnkClass_020091E812sub_0200A088Em
	add r0, r4, #0x1000
	ldr r0, [r0, #0x49c]
	add r1, sp, #0
	bl sub_02034184
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213CAC4: .word s_sAssist_03d_overlay_1_02141f68
	arm_func_end ov1_0213CA78

	arm_func_start ov1_0213CAC8
ov1_0213CAC8: ; 0x0213CAC8
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x1c
	str r0, [sp]
	bl _ZN5CGame11GetInstanceEv
	mov r1, #0
	str r1, [sp, #8]
	arm_func_end ov1_0213CAC8
_0213CAE0:
	ldr r2, [sp, #8]
	ldr r1, [sp]
	mov r3, #0x1c8
	mla r1, r2, r3, r1
	str r1, [sp, #4]
	add r1, r0, #0x48
	add sl, r1, #0x1400
	mov sb, #0
_0213CB00:
	ldr r2, [sl]
	ldmib sl, {r1, r3}
	umull r5, r4, r3, r2
	mla r4, r3, r1, r4
	ldr r1, [sl, #0xc]
	ldr r3, [sl, #0x10]
	mla r4, r1, r2, r4
	mov r1, #0
	ldr r2, [sl, #0x14]
	adds r3, r3, r5
	adc r8, r2, r4
	stmia sl, {r3, r8}
	mov r1, r1, lsl #8
	orr r1, r1, r8, lsr #24
	sub r1, r1, #0x80
	mov r7, r1, lsl #0xc
	mov r1, #0
	mov r2, r1, lsl #6
	ldr r6, [sl]
	ldr r3, [sl, #8]
	ldr r1, [sp, #4]
	mov ip, #0x4c
	mla r1, sb, ip, r1
	umull lr, ip, r3, r6
	ldr r5, [sl, #0x10]
	add sb, sb, #1
	mla ip, r3, r8, ip
	ldr fp, [sl, #0xc]
	ldr r4, [sl, #0x14]
	adds r5, r5, lr
	mla ip, fp, r6, ip
	adc r3, r4, ip
	str r5, [sl]
	orr r2, r2, r3, lsr #26
	str r3, [sl, #4]
	sub r2, r2, #0x20
	mov r2, r2, lsl #0xc
	and sb, sb, #0xff
	str r7, [r1, #0x810]
	str r7, [sp, #0x14]
	str r7, [sp, #0xc]
	str r2, [r1, #0x814]
	str r2, [sp, #0x18]
	str r2, [sp, #0x10]
	cmp sb, #6
	blo _0213CB00
	ldr r1, [sp, #8]
	add r1, r1, #1
	and r1, r1, #0xff
	str r1, [sp, #8]
	cmp r1, #3
	blo _0213CAE0
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov1_0213CBD8
ov1_0213CBD8: ; 0x0213CBD8
	stmdb sp!, {r4, r5, r6, lr}
	str r1, [r0, #0x774]
	mov r5, #0
	str r1, [r0, #0x7c0]
	mov r4, r5
	mov r2, #0x4c
	mov r3, #0x1c8
	arm_func_end ov1_0213CBD8
_0213CBF4:
	mla r6, r5, r3, r0
	mov ip, r4
_0213CBFC:
	mla lr, ip, r2, r6
	add ip, ip, #1
	and ip, ip, #0xff
	str r1, [lr, #0x80c]
	cmp ip, #6
	blo _0213CBFC
	add ip, r5, #1
	and r5, ip, #0xff
	cmp r5, #3
	blo _0213CBF4
	ldmia sp!, {r4, r5, r6, pc}

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
	bl ov1_0213E8BC
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

	arm_func_start ov1_0213E68C
ov1_0213E68C: ; 0x0213E68C
	ldrh r1, [r0, #0x28]
	cmp r1, #0
	bxeq lr
	mov r1, #0
	strh r1, [r0, #0x26]
	strh r1, [r0, #0x2a]
	mov r1, #2
	strh r1, [r0, #0x28]
	bx lr
	arm_func_end ov1_0213E68C

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

	arm_func_start ov1_0213E8BC
ov1_0213E8BC: ; 0x0213E8BC
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	mov r5, r1
	bl ov1_0213EF2C
	cmp r0, #0
	beq _0213E8E0
	ldr r0, [r8, #8]
	cmp r0, #0x11
	moveq r5, #0
	arm_func_end ov1_0213E8BC
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

	arm_func_start ov1_0213EC40
ov1_0213EC40: ; 0x0213EC40
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r4, #0
	mov r7, r0
	mov r6, r1
	mov r5, r4
	mov sb, #1
	mov r8, #2
	arm_func_end ov1_0213EC40
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
	bl ov1_0213E8BC
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

    .global DAT_overlay_1_02140280
DAT_overlay_1_02140280: ; 0x02140280
	.byte 0x28, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00

    .global DAT_overlay_1_02140288
DAT_overlay_1_02140288: ; 0x02140288
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00
	.byte 0x00, 0x30, 0x00, 0x00

    .global DAT_overlay_1_02140294
DAT_overlay_1_02140294: ; 0x02140294
	.byte 0x00, 0x10, 0x00, 0x00

    .global DAT_overlay_1_02140298
DAT_overlay_1_02140298: ; 0x02140298
	.byte 0x00, 0x10, 0x00, 0x00

    .global DAT_overlay_1_0214029c
DAT_overlay_1_0214029c: ; 0x0214029C
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x14, 0x10, 0x00, 0x00, 0x14, 0x10, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x28, 0x10, 0x00, 0x00
	.byte 0x28, 0x10, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x3D, 0x10, 0x00, 0x00, 0x3D, 0x10, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x51, 0x10, 0x00, 0x00, 0x51, 0x10, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x66, 0x10, 0x00, 0x00, 0x66, 0x10, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x7A, 0x10, 0x00, 0x00
	.byte 0x7A, 0x10, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x8F, 0x10, 0x00, 0x00, 0x8F, 0x10, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00, 0xA3, 0x10, 0x00, 0x00, 0xA3, 0x10, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00
	.byte 0xB8, 0x10, 0x00, 0x00, 0xB8, 0x10, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0xCC, 0x10, 0x00, 0x00
	.byte 0xCC, 0x10, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0xE1, 0x10, 0x00, 0x00, 0xE1, 0x10, 0x00, 0x00
	.byte 0x0C, 0x00, 0x00, 0x00, 0xF5, 0x10, 0x00, 0x00, 0xF5, 0x10, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00
	.byte 0x0A, 0x11, 0x00, 0x00, 0x0A, 0x11, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x1E, 0x11, 0x00, 0x00
	.byte 0x1E, 0x11, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x33, 0x11, 0x00, 0x00, 0x33, 0x11, 0x00, 0x00
	.byte 0x10, 0x00, 0x00, 0x00, 0x37, 0x11, 0x00, 0x00, 0x37, 0x11, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00
	.byte 0x3B, 0x11, 0x00, 0x00, 0x3B, 0x11, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x3F, 0x11, 0x00, 0x00
	.byte 0x3F, 0x11, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x43, 0x11, 0x00, 0x00, 0x43, 0x11, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00
	.byte 0x47, 0x11, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00
	.byte 0x47, 0x11, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00
	.byte 0x18, 0x00, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00
	.byte 0x47, 0x11, 0x00, 0x00, 0x47, 0x11, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00
	.byte 0x00, 0x10, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x66, 0x0E, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00
	.byte 0x18, 0x00, 0x00, 0x00, 0xCC, 0x0C, 0x00, 0x00, 0x66, 0x0E, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00
	.byte 0x33, 0x0B, 0x00, 0x00, 0xCC, 0x0C, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x99, 0x09, 0x00, 0x00
	.byte 0x33, 0x0B, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x99, 0x09, 0x00, 0x00
	.byte 0x18, 0x00, 0x00, 0x00, 0x33, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00
	.byte 0x66, 0x06, 0x00, 0x00, 0x33, 0x07, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x99, 0x05, 0x00, 0x00
	.byte 0x66, 0x06, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xCC, 0x04, 0x00, 0x00, 0x99, 0x05, 0x00, 0x00
	.byte 0x18, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0xCC, 0x04, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00
	.byte 0x33, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x66, 0x02, 0x00, 0x00
	.byte 0x33, 0x03, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x99, 0x01, 0x00, 0x00, 0x66, 0x02, 0x00, 0x00
	.byte 0x0C, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0x99, 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0xCC, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00

    .global DAT_overlay_1_0214048c
DAT_overlay_1_0214048c: ; 0x0214048C
	.byte 0x32, 0x00

    .global DAT_overlay_1_0214048e
DAT_overlay_1_0214048e: ; 0x0214048E
	.byte 0x19, 0x00
	.byte 0x0C, 0x00, 0x00, 0x00

    .global DAT_overlay_1_02140494
DAT_overlay_1_02140494: ; 0x02140494
	.byte 0x0C, 0x00, 0x0D, 0x00, 0x0F, 0x00, 0x0D, 0x00, 0x0F, 0x00, 0x19, 0x00
	.byte 0x32, 0x00, 0x19, 0x00, 0x0F, 0x00, 0x19, 0x00, 0x0A, 0x00, 0x0F, 0x00, 0x14, 0x00, 0x0A, 0x00
	.byte 0x14, 0x00, 0x0F, 0x00, 0x1E, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404b8
DAT_overlay_1_021404b8: ; 0x021404B8
	.byte 0x00, 0x00, 0x10, 0x00

    .global DAT_overlay_1_021404bc
DAT_overlay_1_021404bc: ; 0x021404BC
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404c0
DAT_overlay_1_021404c0: ; 0x021404C0
	.byte 0x00, 0x00, 0x10, 0x00

    .global DAT_overlay_1_021404c4
DAT_overlay_1_021404c4: ; 0x021404C4
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404c8
DAT_overlay_1_021404c8: ; 0x021404C8
	.byte 0x00, 0x00, 0xFC, 0xFF

    .global DAT_overlay_1_021404cc
DAT_overlay_1_021404cc: ; 0x021404CC
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404d0
DAT_overlay_1_021404d0: ; 0x021404D0
	.byte 0x00, 0x00, 0x04, 0x00

    .global DAT_overlay_1_021404d4
DAT_overlay_1_021404d4: ; 0x021404D4
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404d8
DAT_overlay_1_021404d8: ; 0x021404D8
	.byte 0x00, 0x00, 0x10, 0x00

    .global DAT_overlay_1_021404dc
DAT_overlay_1_021404dc: ; 0x021404DC
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404e0
DAT_overlay_1_021404e0: ; 0x021404E0
	.byte 0x00, 0x00, 0xF0, 0xFF

    .global DAT_overlay_1_021404e4
DAT_overlay_1_021404e4: ; 0x021404E4
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404e8
DAT_overlay_1_021404e8: ; 0x021404E8
	.byte 0x00, 0x80, 0x00, 0x00

    .global DAT_overlay_1_021404ec
DAT_overlay_1_021404ec: ; 0x021404EC
	.byte 0x00, 0x40, 0x00, 0x00
	.byte 0x00, 0x20, 0x00, 0x00

    .global DAT_overlay_1_021404f4
DAT_overlay_1_021404f4: ; 0x021404F4
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_1_021404f8
DAT_overlay_1_021404f8: ; 0x021404F8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFE, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x80, 0x01, 0x00
	.byte 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFE, 0xFF, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x80, 0x01, 0x00
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFD, 0xFF, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0xC0, 0x00, 0x00
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x40, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x02, 0x00
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD, 0xFF, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x00, 0x03, 0x00, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x80, 0xFE, 0xFF
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xFC, 0xFF, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x40, 0xFF, 0xFF
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0xC0, 0xFD, 0xFF
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xC0, 0x03, 0x00
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFB, 0xFF, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x80, 0xFE, 0xFF
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x80, 0x01, 0x00, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x80, 0x04, 0x00
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x00, 0xFD, 0xFF, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFA, 0xFF, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0xC0, 0xFD, 0xFF
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x40, 0xFE, 0xFF, 0x00, 0xC0, 0x03, 0x00
	.byte 0x00, 0x40, 0xFE, 0xFF, 0x00, 0x40, 0xFC, 0xFF, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x40, 0x05, 0x00
	.byte 0x00, 0x00, 0x01, 0x00

    .section .sinit,4 ; 0x02140734

    .data

    .global PTR_ptr_FUN_020835bc_overlay_1_02141800
PTR_ptr_FUN_020835bc_overlay_1_02141800: ; 0x02141800
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CBattleAssistRock_overlay_1_0214180c
	.word _ZTI13CBattleAssist

    .global s_17CBattleAssistRock_overlay_1_0214180c
s_17CBattleAssistRock_overlay_1_0214180c: ; 0x0214180C
	.asciz "17CBattleAssistRock"

    .global DAT_overlay_1_02141820
DAT_overlay_1_02141820:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_1_02141800

    .global PTR_LAB_overlay_1_021343c0_overlay_1_02141828
PTR_LAB_overlay_1_021343c0_overlay_1_02141828: ; 0x02141828
	.word ov1_021343C0

    .global ptr_FUN_overlay_1_021343d4_overlay_1_0214182c
ptr_FUN_overlay_1_021343d4_overlay_1_0214182c: ; 0x0214182C
	.word ov1_021343D4

    .global ptr_FUN_overlay_1_021343f0_overlay_1_02141830
ptr_FUN_overlay_1_021343f0_overlay_1_02141830: ; 0x02141830
	.word ov1_021343F0

    .global ptr_FUN_overlay_1_021349f4_overlay_1_02141834
ptr_FUN_overlay_1_021349f4_overlay_1_02141834: ; 0x02141834
	.word ov1_021349F4
	.word ov1_021349EC

    .global PTR_ptr_FUN_020835bc_overlay_1_0214183c
PTR_ptr_FUN_020835bc_overlay_1_0214183c: ; 0x0214183C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_18CBattleAssistSteel_overlay_1_02141848
	.word _ZTI13CBattleAssist

    .global s_18CBattleAssistSteel_overlay_1_02141848
s_18CBattleAssistSteel_overlay_1_02141848: ; 0x02141848
	.asciz "18CBattleAssistSteel"

    .global DAT_overlay_1_0214185D
DAT_overlay_1_0214185D:
	.byte 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_1_0214183c

    .global PTR_LAB_overlay_1_02134ab4_overlay_1_02141868
PTR_LAB_overlay_1_02134ab4_overlay_1_02141868: ; 0x02141868
	.word ov1_02134AB4

    .global ptr_FUN_overlay_1_02134ac8_overlay_1_0214186c
ptr_FUN_overlay_1_02134ac8_overlay_1_0214186c: ; 0x0214186C
	.word ov1_02134AC8

    .global ptr_FUN_overlay_1_02134ae4_overlay_1_02141870
ptr_FUN_overlay_1_02134ae4_overlay_1_02141870: ; 0x02141870
	.word ov1_02134AE4

    .global ptr_FUN_overlay_1_02135230_overlay_1_02141874
ptr_FUN_overlay_1_02135230_overlay_1_02141874: ; 0x02141874
	.word ov1_02135230

    .global ptr_FUN_overlay_11_02135228_overlay_1_02141878
ptr_FUN_overlay_11_02135228_overlay_1_02141878: ; 0x02141878
	.word ov1_02135228

    .global PTR_ptr_FUN_020835bc_overlay_1_0214187c
PTR_ptr_FUN_020835bc_overlay_1_0214187c: ; 0x0214187C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_18CBattleAssistWater_overlay_1_02141888
	.word _ZTI13CBattleAssist

    .global s_18CBattleAssistWater_overlay_1_02141888
s_18CBattleAssistWater_overlay_1_02141888: ; 0x02141888
	.asciz "18CBattleAssistWater"

    .global DAT_overlay_1_0214189D
DAT_overlay_1_0214189D:
	.byte 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_1_0214187c

    .global PTR_LAB_overlay_1_02135304_overlay_1_021418a8
PTR_LAB_overlay_1_02135304_overlay_1_021418a8: ; 0x021418A8
	.word ov1_02135304

    .global ptr_FUN_overlay_1_02135318_overlay_1_021418ac
ptr_FUN_overlay_1_02135318_overlay_1_021418ac: ; 0x021418AC
	.word ov1_02135318

    .global ptr_FUN_overlay_1_02135334_overlay_1_021418b0
ptr_FUN_overlay_1_02135334_overlay_1_021418b0: ; 0x021418B0
	.word ov1_02135334

    .global ptr_FUN_overlay_1_02135b1c_overlay_1_021418b4
ptr_FUN_overlay_1_02135b1c_overlay_1_021418b4: ; 0x021418B4
	.word ov1_02135B1C
	.word ov1_02135B14

    .global PTR_ptr_FUN_020835bc_overlay_1_021418bc
PTR_ptr_FUN_020835bc_overlay_1_021418bc: ; 0x021418BC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CBattleEnemyGauge_overlay_1_021418c8
	.word _ZTI6CActor

    .global s_17CBattleEnemyGauge_overlay_1_021418c8
s_17CBattleEnemyGauge_overlay_1_021418c8: ; 0x021418C8
	.asciz "17CBattleEnemyGauge"

    .global DAT_overlay_1_021418DC
DAT_overlay_1_021418DC:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_1_021418bc

    .global ptr_FUN_overlay_1_02135d04_overlay_1_021418e4
ptr_FUN_overlay_1_02135d04_overlay_1_021418e4: ; 0x021418E4
	.word ov1_02135D04

    .global ptr_FUN_overlay_1_02135d44_overlay_1_021418e8
ptr_FUN_overlay_1_02135d44_overlay_1_021418e8: ; 0x021418E8
	.word ov1_02135D44

    .global ptr_FUN_overlay_1_02135f58_overlay_1_021418ec
ptr_FUN_overlay_1_02135f58_overlay_1_021418ec: ; 0x021418EC
	.word ov1_02135F58

    .global ptr_FUN_overlay_1_02136094_overlay_1_021418f0
ptr_FUN_overlay_1_02136094_overlay_1_021418f0: ; 0x021418F0
	.word ov1_02136094
	.word ov1_02136244

    .global s_d_overlay_1_021418f8
s_d_overlay_1_021418f8: ; 0x021418F8
	.asciz "%d"

    .global DAT_overlay_1_021418FB
DAT_overlay_1_021418FB:
	.byte 0x00

    .global s_BEG_overlay_1_021418fc
s_BEG_overlay_1_021418fc: ; 0x021418FC
	.asciz "BEG"

    .global s_data_interface_i000_LZ_bin_overlay_1_02141900
s_data_interface_i000_LZ_bin_overlay_1_02141900: ; 0x02141900
	.asciz "data/interface/i000_LZ.bin"

    .global DAT_overlay_1_0214191B
DAT_overlay_1_0214191B:
	.byte 0x00

    .global s_BEG_i000_00_NCBR_overlay_1_0214191c
s_BEG_i000_00_NCBR_overlay_1_0214191c: ; 0x0214191C
	.asciz "BEG:i000_00.NCBR"

    .global DAT_overlay_1_0214192D
DAT_overlay_1_0214192D:
	.byte 0x00, 0x00, 0x00

    .global s_BEG_i000_NCLR_overlay_1_02141930
s_BEG_i000_NCLR_overlay_1_02141930: ; 0x02141930
	.asciz "BEG:i000.NCLR"

    .global DAT_overlay_1_0214193E
DAT_overlay_1_0214193E:
	.byte 0x00, 0x00

    .global s_BEG_i000_00_NCER_overlay_1_02141940
s_BEG_i000_00_NCER_overlay_1_02141940: ; 0x02141940
	.asciz "BEG:i000_00.NCER"

    .global DAT_overlay_1_02141951
DAT_overlay_1_02141951:
	.byte 0x00, 0x00, 0x00

    .global s_BDN_overlay_1_02141954
s_BDN_overlay_1_02141954: ; 0x02141954
	.asciz "BDN"

    .global s_data_interface_i070_LZ_bin_overlay_1_02141958
s_data_interface_i070_LZ_bin_overlay_1_02141958: ; 0x02141958
	.asciz "/data/interface/i070_LZ.bin"

    .global s_BDN_i070_00_NCBR_overlay_1_02141974
s_BDN_i070_00_NCBR_overlay_1_02141974: ; 0x02141974
	.asciz "BDN:i070_00.NCBR"

    .global DAT_overlay_1_02141985
DAT_overlay_1_02141985:
	.byte 0x00, 0x00, 0x00

    .global s_BDN_i070_NCLR_overlay_1_02141988
s_BDN_i070_NCLR_overlay_1_02141988: ; 0x02141988
	.asciz "BDN:i070.NCLR"

    .global DAT_overlay_1_02141996
DAT_overlay_1_02141996:
	.byte 0x00, 0x00

    .global s_BDN_i070_00_NCER_overlay_1_02141998
s_BDN_i070_00_NCER_overlay_1_02141998: ; 0x02141998
	.asciz "BDN:i070_00.NCER"

    .global DAT_overlay_1_021419A9
DAT_overlay_1_021419A9:
	.byte 0x00, 0x00, 0x00

    .global s_BDN_i070_00_cac_overlay_1_021419ac
s_BDN_i070_00_cac_overlay_1_021419ac: ; 0x021419AC
	.asciz "BDN:i070_00.cac"

    .global s_02_overlay_1_021419bc
s_02_overlay_1_021419bc: ; 0x021419BC
	.asciz "02"

    .global DAT_overlay_1_021419BF
DAT_overlay_1_021419BF:
	.byte 0x00

    .global s_00_overlay_1_021419c0
s_00_overlay_1_021419c0: ; 0x021419C0
	.asciz "00"

    .global DAT_overlay_1_021419C3
DAT_overlay_1_021419C3:
	.byte 0x00

    .global s_PSS_overlay_1_021419c4
s_PSS_overlay_1_021419c4: ; 0x021419C4
	.asciz "PSS"

    .global s_PSE_overlay_1_021419c8
s_PSE_overlay_1_021419c8: ; 0x021419C8
	.asciz "PSE"

    .global ptr_s_PSE_overlay_1_021419c8_overlay_1_021419cc
ptr_s_PSE_overlay_1_021419c8_overlay_1_021419cc: ; 0x021419CC
	.word s_PSE_overlay_1_021419c8
	.word s_PSS_overlay_1_021419c4

    .global ptr_s_00_overlay_1_021419c0_overlay_1_021419d4
ptr_s_00_overlay_1_021419c0_overlay_1_021419d4: ; 0x021419D4
	.word s_00_overlay_1_021419c0
	.word s_02_overlay_1_021419bc

    .global PTR_ptr_FUN_020835bc_overlay_1_021419dc
PTR_ptr_FUN_020835bc_overlay_1_021419dc: ; 0x021419DC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CBattlePowerSave_overlay_1_021419e8
	.word _ZTI6CActor

    .global s_16CBattlePowerSave_overlay_1_021419e8
s_16CBattlePowerSave_overlay_1_021419e8: ; 0x021419E8
	.asciz "16CBattlePowerSave"

    .global DAT_overlay_1_021419FB
DAT_overlay_1_021419FB:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_1_021419dc

    .global ptr_FUN_overlay_1_02136d60_overlay_1_02141a04
ptr_FUN_overlay_1_02136d60_overlay_1_02141a04: ; 0x02141A04
	.word ov1_02136D60

    .global ptr_FUN_overlay_1_02136db0_overlay_1_02141a08
ptr_FUN_overlay_1_02136db0_overlay_1_02141a08: ; 0x02141A08
	.word ov1_02136DB0

    .global ptr_FUN_overlay_1_02137550_overlay_1_02141a0c
ptr_FUN_overlay_1_02137550_overlay_1_02141a0c: ; 0x02141A0C
	.word ov1_02137550

    .global ptr_FUN_overlay_1_02137af0_overlay_1_02141a10
ptr_FUN_overlay_1_02137af0_overlay_1_02141a10: ; 0x02141A10
	.word ov1_02137AF0
	.word ov1_02137B90

    .global s_data_interface_i025_LZ_bin_overlay_1_02141a18
s_data_interface_i025_LZ_bin_overlay_1_02141a18: ; 0x02141A18
	.asciz "data/interface/i025_LZ.bin"

    .global DAT_overlay_1_02141A33
DAT_overlay_1_02141A33:
	.byte 0x00

    .global s_s_i025_s_NCBR_overlay_1_02141a34
s_s_i025_s_NCBR_overlay_1_02141a34: ; 0x02141A34
	.asciz "%s:i025_%s.NCBR"

    .global s_s_i025_NCLR_overlay_1_02141a44
s_s_i025_NCLR_overlay_1_02141a44: ; 0x02141A44
	.asciz "%s:i025.NCLR"

    .global DAT_overlay_1_02141A51
DAT_overlay_1_02141A51:
	.byte 0x00, 0x00, 0x00

    .global s_s_i025_s_NCER_overlay_1_02141a54
s_s_i025_s_NCER_overlay_1_02141a54: ; 0x02141A54
	.asciz "%s:i025_%s.NCER"

    .global s_s_i025_s_cac_overlay_1_02141a64
s_s_i025_s_cac_overlay_1_02141a64: ; 0x02141A64
	.asciz "%s:i025_%s.cac"

    .global DAT_overlay_1_02141A73
DAT_overlay_1_02141A73:
	.byte 0x00

    .global s_BLD_overlay_1_02141a74
s_BLD_overlay_1_02141a74: ; 0x02141A74
	.asciz "BLD"

    .global s_data_interface_i066_LZ_bin_overlay_1_02141a78
s_data_interface_i066_LZ_bin_overlay_1_02141a78: ; 0x02141A78
	.asciz "data/interface/i066_LZ.bin"

    .global DAT_overlay_1_02141A93
DAT_overlay_1_02141A93:
	.byte 0x00

    .global s_BLD_i066_00_NCBR_overlay_1_02141a94
s_BLD_i066_00_NCBR_overlay_1_02141a94: ; 0x02141A94
	.asciz "BLD:i066_00.NCBR"

    .global DAT_overlay_1_02141AA5
DAT_overlay_1_02141AA5:
	.byte 0x00, 0x00, 0x00

    .global s_BLD_i066_NCLR_overlay_1_02141aa8
s_BLD_i066_NCLR_overlay_1_02141aa8: ; 0x02141AA8
	.asciz "BLD:i066.NCLR"

    .global DAT_overlay_1_02141AB6
DAT_overlay_1_02141AB6:
	.byte 0x00, 0x00

    .global s_BLD_i066_00_NCER_overlay_1_02141ab8
s_BLD_i066_00_NCER_overlay_1_02141ab8: ; 0x02141AB8
	.asciz "BLD:i066_00.NCER"

    .global DAT_overlay_1_02141AC9
DAT_overlay_1_02141AC9:
	.byte 0x00, 0x00, 0x00

    .global s_BLD_i066_00_cac_overlay_1_02141acc
s_BLD_i066_00_cac_overlay_1_02141acc: ; 0x02141ACC
	.asciz "BLD:i066_00.cac"

    .global s_Memory_allocation_failure_overlay_1_02141adc
s_Memory_allocation_failure_overlay_1_02141adc: ; 0x02141ADC
	.asciz "Memory allocation failure"

    .global DAT_overlay_1_02141AF6
DAT_overlay_1_02141AF6:
	.byte 0x00, 0x00

    .global s_BAS_overlay_1_02141af8
s_BAS_overlay_1_02141af8: ; 0x02141AF8
	.asciz "BAS"

    .global s_data_interface_i046_LZ_bin_overlay_1_02141afc
s_data_interface_i046_LZ_bin_overlay_1_02141afc: ; 0x02141AFC
	.asciz "/data/interface/i046_LZ.bin"

    .global s_BAS_i046_00_NCBR_overlay_1_02141b18
s_BAS_i046_00_NCBR_overlay_1_02141b18: ; 0x02141B18
	.asciz "BAS:i046_00.NCBR"

    .global DAT_overlay_1_02141B29
DAT_overlay_1_02141B29:
	.byte 0x00, 0x00, 0x00

    .global s_BAS_i046_NCLR_overlay_1_02141b2c
s_BAS_i046_NCLR_overlay_1_02141b2c: ; 0x02141B2C
	.asciz "BAS:i046.NCLR"

    .global DAT_overlay_1_02141B3A
DAT_overlay_1_02141B3A:
	.byte 0x00, 0x00

    .global s_BAS_i046_00_NCER_overlay_1_02141b3c
s_BAS_i046_00_NCER_overlay_1_02141b3c: ; 0x02141B3C
	.asciz "BAS:i046_00.NCER"

    .global DAT_overlay_1_02141B4D
DAT_overlay_1_02141B4D:
	.byte 0x00, 0x00, 0x00

    .global s_BAS_i046_00_cac_overlay_1_02141b50
s_BAS_i046_00_cac_overlay_1_02141b50: ; 0x02141B50
	.asciz "BAS:i046_00.cac"

    .global DAT_overlay_1_02141b60
DAT_overlay_1_02141b60: ; 0x02141B60
	.byte 0x42, 0x45, 0x53, 0x00

    .global s_data_interface_i047_LZ_bin_overlay_1_02141b64
s_data_interface_i047_LZ_bin_overlay_1_02141b64: ; 0x02141B64
	.asciz "/data/interface/i047_LZ.bin"

    .global s_BES_i047_00_NCBR_overlay_1_02141b80
s_BES_i047_00_NCBR_overlay_1_02141b80: ; 0x02141B80
	.asciz "BES:i047_00.NCBR"

    .global DAT_overlay_1_02141B91
DAT_overlay_1_02141B91:
	.byte 0x00, 0x00, 0x00

    .global s_BES_i047_NCLR_overlay_1_02141b94
s_BES_i047_NCLR_overlay_1_02141b94: ; 0x02141B94
	.asciz "BES:i047.NCLR"

    .global DAT_overlay_1_02141BA2
DAT_overlay_1_02141BA2:
	.byte 0x00, 0x00

    .global s_BES_i047_00_NCER_overlay_1_02141ba4
s_BES_i047_00_NCER_overlay_1_02141ba4: ; 0x02141BA4
	.asciz "BES:i047_00.NCER"

    .global DAT_overlay_1_02141BB5
DAT_overlay_1_02141BB5:
	.byte 0x00, 0x00, 0x00

    .global s_BES_i047_00_cac_overlay_1_02141bb8
s_BES_i047_00_cac_overlay_1_02141bb8: ; 0x02141BB8
	.asciz "BES:i047_00.cac"

    .global s_data_battle_result_r000_00_LZ_bi_overlay_1_02141bc8
s_data_battle_result_r000_00_LZ_bi_overlay_1_02141bc8: ; 0x02141BC8
	.asciz "data/battle/result/r000_00_LZ.bin"

    .global DAT_overlay_1_02141BEA
DAT_overlay_1_02141BEA:
	.byte 0x00, 0x00

    .global s_BRM_overlay_1_02141bec
s_BRM_overlay_1_02141bec: ; 0x02141BEC
	.asciz "BRM"

    .global s_BRM_r000_00_NCBR_overlay_1_02141bf0
s_BRM_r000_00_NCBR_overlay_1_02141bf0: ; 0x02141BF0
	.asciz "BRM:r000_00.NCBR"

    .global DAT_overlay_1_02141C01
DAT_overlay_1_02141C01:
	.byte 0x00, 0x00, 0x00

    .global s_BRM_r000_NCLR_overlay_1_02141c04
s_BRM_r000_NCLR_overlay_1_02141c04: ; 0x02141C04
	.asciz "BRM:r000.NCLR"

    .global DAT_overlay_1_02141C12
DAT_overlay_1_02141C12:
	.byte 0x00, 0x00

    .global s_BRM_r000_00_NCER_overlay_1_02141c14
s_BRM_r000_00_NCER_overlay_1_02141c14: ; 0x02141C14
	.asciz "BRM:r000_00.NCER"

    .global DAT_overlay_1_02141C25
DAT_overlay_1_02141C25:
	.byte 0x00, 0x00, 0x00

    .global s_4d_overlay_1_02141c28
s_4d_overlay_1_02141c28: ; 0x02141C28
	.asciz "%4d"

    .global s_5d_overlay_1_02141c2c
s_5d_overlay_1_02141c2c: ; 0x02141C2C
	.asciz "%5d"

    .global s_4d_overlay_1_02141c30
s_4d_overlay_1_02141c30: ; 0x02141C30
	.asciz "+%4d"

    .global DAT_overlay_1_02141C35
DAT_overlay_1_02141C35:
	.byte 0x00, 0x00, 0x00

    .global s_2d_overlay_1_02141c38
s_2d_overlay_1_02141c38: ; 0x02141C38
	.asciz "%2d"

    .global s_2d_overlay_1_02141c3c
s_2d_overlay_1_02141c3c: ; 0x02141C3C
	.asciz "+%2d"

    .global DAT_overlay_1_02141C41
DAT_overlay_1_02141C41:
	.byte 0x00, 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_1_02141c44
PTR_ptr_FUN_020835bc_overlay_1_02141c44: ; 0x02141C44
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_15CBattleGameOver_overlay_1_02141c50
	.word _ZTI6CActor

    .global s_15CBattleGameOver_overlay_1_02141c50
s_15CBattleGameOver_overlay_1_02141c50: ; 0x02141C50
	.asciz "15CBattleGameOver"

    .global DAT_overlay_1_02141C62
DAT_overlay_1_02141C62:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_1_02141c44

    .global ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c
ptr_FUN_overlay_1_0213a540_overlay_1_02141c6c: ; 0x02141C6C
	.word ov1_0213A540

    .global ptr_FUN_overlay_1_0213a5dc_overlay_1_02141c70
ptr_FUN_overlay_1_0213a5dc_overlay_1_02141c70: ; 0x02141C70
	.word ov1_0213A5DC

    .global ptr_FUN_overlay_1_0213ab34_overlay_1_02141c74
ptr_FUN_overlay_1_0213ab34_overlay_1_02141c74: ; 0x02141C74
	.word ov1_0213AB34

    .global ptr_FUN_overlay_1_0213add4_overlay_1_02141c78
ptr_FUN_overlay_1_0213add4_overlay_1_02141c78: ; 0x02141C78
	.word ov1_0213ADD4
	.word ov1_0213AE14

    .global s_data_interface_i_03d_LZ_bin_overlay_1_02141c80
s_data_interface_i_03d_LZ_bin_overlay_1_02141c80: ; 0x02141C80
	.asciz "data/interface/i%03d_LZ.bin"

    .global s_BOA_i_03d_02d_NCBR_overlay_1_02141c9c
s_BOA_i_03d_02d_NCBR_overlay_1_02141c9c: ; 0x02141C9C
	.asciz "BOA:i%03d_%02d.NCBR"

    .global s_BOA_i_03d_NCLR_overlay_1_02141cb0
s_BOA_i_03d_NCLR_overlay_1_02141cb0: ; 0x02141CB0
	.asciz "BOA:i%03d.NCLR"

    .global DAT_overlay_1_02141CBF
DAT_overlay_1_02141CBF:
	.byte 0x00

    .global s_BOA_i_03d_02d_NCER_overlay_1_02141cc0
s_BOA_i_03d_02d_NCER_overlay_1_02141cc0: ; 0x02141CC0
	.asciz "BOA:i%03d_%02d.NCER"

    .global s_BOA_i_03d_02d_cac_overlay_1_02141cd4
s_BOA_i_03d_02d_cac_overlay_1_02141cd4: ; 0x02141CD4
	.asciz "BOA:i%03d_%02d.cac"

    .global DAT_overlay_1_02141CE7
DAT_overlay_1_02141CE7:
	.byte 0x00

    .global s_BOA_overlay_1_02141ce8
s_BOA_overlay_1_02141ce8: ; 0x02141CE8
	.asciz "BOA"

    .global s_BOB_i_03d_02d_NCBR_overlay_1_02141cec
s_BOB_i_03d_02d_NCBR_overlay_1_02141cec: ; 0x02141CEC
	.asciz "BOB:i%03d_%02d.NCBR"

    .global s_BOB_i_03d_NCLR_overlay_1_02141d00
s_BOB_i_03d_NCLR_overlay_1_02141d00: ; 0x02141D00
	.asciz "BOB:i%03d.NCLR"

    .global DAT_overlay_1_02141D0F
DAT_overlay_1_02141D0F:
	.byte 0x00

    .global s_BOB_i_03d_02d_NCER_overlay_1_02141d10
s_BOB_i_03d_02d_NCER_overlay_1_02141d10: ; 0x02141D10
	.asciz "BOB:i%03d_%02d.NCER"

    .global s_BOB_i_03d_02d_cac_overlay_1_02141d24
s_BOB_i_03d_02d_cac_overlay_1_02141d24: ; 0x02141D24
	.asciz "BOB:i%03d_%02d.cac"

    .global DAT_overlay_1_02141D37
DAT_overlay_1_02141D37:
	.byte 0x00

    .global s_BOB_overlay_1_02141d38
s_BOB_overlay_1_02141d38: ; 0x02141D38
	.asciz "BOB"

    .global s_data_interface_i019_LZ_bin_overlay_1_02141d3c
s_data_interface_i019_LZ_bin_overlay_1_02141d3c: ; 0x02141D3C
	.asciz "data/interface/i019_LZ.bin"

    .global DAT_overlay_1_02141D57
DAT_overlay_1_02141D57:
	.byte 0x00

    .global s_BOC_i019_03_NCBR_overlay_1_02141d58
s_BOC_i019_03_NCBR_overlay_1_02141d58: ; 0x02141D58
	.asciz "BOC:i019_03.NCBR"

    .global DAT_overlay_1_02141D69
DAT_overlay_1_02141D69:
	.byte 0x00, 0x00, 0x00

    .global s_BOC_i019_NCLR_overlay_1_02141d6c
s_BOC_i019_NCLR_overlay_1_02141d6c: ; 0x02141D6C
	.asciz "BOC:i019.NCLR"

    .global DAT_overlay_1_02141D7A
DAT_overlay_1_02141D7A:
	.byte 0x00, 0x00

    .global s_BOC_i019_03_NCER_overlay_1_02141d7c
s_BOC_i019_03_NCER_overlay_1_02141d7c: ; 0x02141D7C
	.asciz "BOC:i019_03.NCER"

    .global DAT_overlay_1_02141D8D
DAT_overlay_1_02141D8D:
	.byte 0x00, 0x00, 0x00

    .global s_BOC_i019_03_cac_overlay_1_02141d90
s_BOC_i019_03_cac_overlay_1_02141d90: ; 0x02141D90
	.asciz "BOC:i019_03.cac"

    .global s_BOC_overlay_1_02141da0
s_BOC_overlay_1_02141da0: ; 0x02141DA0
	.asciz "BOC"

    .global s_BAM_overlay_1_02141da4
s_BAM_overlay_1_02141da4: ; 0x02141DA4
	.asciz "BAM"

    .global s_data_interface_i062_LZ_bin_overlay_1_02141da8
s_data_interface_i062_LZ_bin_overlay_1_02141da8: ; 0x02141DA8
	.asciz "data/interface/i062_LZ.bin"

    .global DAT_overlay_1_02141DC3
DAT_overlay_1_02141DC3:
	.byte 0x00

    .global s_BAM_i062_00_NCBR_overlay_1_02141dc4
s_BAM_i062_00_NCBR_overlay_1_02141dc4: ; 0x02141DC4
	.asciz "BAM:i062_00.NCBR"

    .global DAT_overlay_1_02141DD5
DAT_overlay_1_02141DD5:
	.byte 0x00, 0x00, 0x00

    .global s_BAM_i062_NCLR_overlay_1_02141dd8
s_BAM_i062_NCLR_overlay_1_02141dd8: ; 0x02141DD8
	.asciz "BAM:i062.NCLR"

    .global DAT_overlay_1_02141DE6
DAT_overlay_1_02141DE6:
	.byte 0x00, 0x00

    .global s_BAM_i062_00_NCER_overlay_1_02141de8
s_BAM_i062_00_NCER_overlay_1_02141de8: ; 0x02141DE8
	.asciz "BAM:i062_00.NCER"

    .global DAT_overlay_1_02141DF9
DAT_overlay_1_02141DF9:
	.byte 0x00, 0x00, 0x00

    .global s_BAM_i062_00_cac_overlay_1_02141dfc
s_BAM_i062_00_cac_overlay_1_02141dfc: ; 0x02141DFC
	.asciz "BAM:i062_00.cac"

    .global s_data_interface_i060_LZ_bin_overlay_1_02141e0c
s_data_interface_i060_LZ_bin_overlay_1_02141e0c: ; 0x02141E0C
	.asciz "data/interface/i060_LZ.bin"

    .global DAT_overlay_1_02141E27
DAT_overlay_1_02141E27:
	.byte 0x00

    .global s_BAM_i060_00_NCBR_overlay_1_02141e28
s_BAM_i060_00_NCBR_overlay_1_02141e28: ; 0x02141E28
	.asciz "BAM:i060_00.NCBR"

    .global DAT_overlay_1_02141E39
DAT_overlay_1_02141E39:
	.byte 0x00, 0x00, 0x00

    .global s_BAM_i060_NCLR_overlay_1_02141e3c
s_BAM_i060_NCLR_overlay_1_02141e3c: ; 0x02141E3C
	.asciz "BAM:i060.NCLR"

    .global DAT_overlay_1_02141E4A
DAT_overlay_1_02141E4A:
	.byte 0x00, 0x00

    .global s_BAM_i060_00_NCER_overlay_1_02141e4c
s_BAM_i060_00_NCER_overlay_1_02141e4c: ; 0x02141E4C
	.asciz "BAM:i060_00.NCER"

    .global DAT_overlay_1_02141E5D
DAT_overlay_1_02141E5D:
	.byte 0x00, 0x00, 0x00

    .global s_data_interface_i061_LZ_bin_overlay_1_02141e60
s_data_interface_i061_LZ_bin_overlay_1_02141e60: ; 0x02141E60
	.asciz "data/interface/i061_LZ.bin"

    .global DAT_overlay_1_02141E7B
DAT_overlay_1_02141E7B:
	.byte 0x00

    .global s_BAM_i061_00_NCBR_overlay_1_02141e7c
s_BAM_i061_00_NCBR_overlay_1_02141e7c: ; 0x02141E7C
	.asciz "BAM:i061_00.NCBR"

    .global DAT_overlay_1_02141E8D
DAT_overlay_1_02141E8D:
	.byte 0x00, 0x00, 0x00

    .global s_BAM_i061_NCLR_overlay_1_02141e90
s_BAM_i061_NCLR_overlay_1_02141e90: ; 0x02141E90
	.asciz "BAM:i061.NCLR"

    .global DAT_overlay_1_02141E9E
DAT_overlay_1_02141E9E:
	.byte 0x00, 0x00

    .global s_BAM_i061_00_NCER_overlay_1_02141ea0
s_BAM_i061_00_NCER_overlay_1_02141ea0: ; 0x02141EA0
	.asciz "BAM:i061_00.NCER"

    .global DAT_overlay_1_02141EB1
DAT_overlay_1_02141EB1:
	.byte 0x00, 0x00, 0x00

    .global s_data_interface_i063_LZ_bin_overlay_1_02141eb4
s_data_interface_i063_LZ_bin_overlay_1_02141eb4: ; 0x02141EB4
	.asciz "data/interface/i063_LZ.bin"

    .global DAT_overlay_1_02141ECF
DAT_overlay_1_02141ECF:
	.byte 0x00

    .global s_BAM_i063_00_NCBR_overlay_1_02141ed0
s_BAM_i063_00_NCBR_overlay_1_02141ed0: ; 0x02141ED0
	.asciz "BAM:i063_00.NCBR"

    .global DAT_overlay_1_02141EE1
DAT_overlay_1_02141EE1:
	.byte 0x00, 0x00, 0x00

    .global s_BAM_i063_NCLR_overlay_1_02141ee4
s_BAM_i063_NCLR_overlay_1_02141ee4: ; 0x02141EE4
	.asciz "BAM:i063.NCLR"

    .global DAT_overlay_1_02141EF2
DAT_overlay_1_02141EF2:
	.byte 0x00, 0x00

    .global s_BAM_i063_00_NCER_overlay_1_02141ef4
s_BAM_i063_00_NCER_overlay_1_02141ef4: ; 0x02141EF4
	.asciz "BAM:i063_00.NCER"

    .global DAT_overlay_1_02141F05
DAT_overlay_1_02141F05:
	.byte 0x00, 0x00, 0x00

    .global s_data_interface_i064_LZ_bin_overlay_1_02141f08
s_data_interface_i064_LZ_bin_overlay_1_02141f08: ; 0x02141F08
	.asciz "data/interface/i064_LZ.bin"

    .global DAT_overlay_1_02141F23
DAT_overlay_1_02141F23:
	.byte 0x00

    .global s_BAM_i064_00_NCBR_overlay_1_02141f24
s_BAM_i064_00_NCBR_overlay_1_02141f24: ; 0x02141F24
	.asciz "BAM:i064_00.NCBR"

    .global DAT_overlay_1_02141F35
DAT_overlay_1_02141F35:
	.byte 0x00, 0x00, 0x00

    .global s_BAM_i064_NCLR_overlay_1_02141f38
s_BAM_i064_NCLR_overlay_1_02141f38: ; 0x02141F38
	.asciz "BAM:i064.NCLR"

    .global DAT_overlay_1_02141F46
DAT_overlay_1_02141F46:
	.byte 0x00, 0x00

    .global s_BAM_i064_00_NCER_overlay_1_02141f48
s_BAM_i064_00_NCER_overlay_1_02141f48: ; 0x02141F48
	.asciz "BAM:i064_00.NCER"

    .global DAT_overlay_1_02141F59
DAT_overlay_1_02141F59:
	.byte 0x00, 0x00, 0x00

    .global s_sPokeSelect_overlay_1_02141f5c
s_sPokeSelect_overlay_1_02141f5c: ; 0x02141F5C
	.asciz "sPokeSelect"

    .global s_sAssist_03d_overlay_1_02141f68
s_sAssist_03d_overlay_1_02141f68: ; 0x02141F68
	.asciz "sAssist%03d"

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
