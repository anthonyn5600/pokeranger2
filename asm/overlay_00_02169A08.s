    .include "macros.inc"
    .include "include/overlay_00_02169A08.inc"

    .text

	arm_func_start ov0_02169A08
ov0_02169A08: ; 0x02169A08
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr r2, _02169B78 ; =_ZTV12CFieldEffect+8
	mov sl, r0
	str r2, [sl]
	ldr r2, [r0]
	mov sb, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r1, _02169B7C ; =ptr_FUN_overlay_0_02169b90_overlay_0_02179e58
	add r0, sl, #0x18
	str r1, [sl]
	bl _ZN14CPrimitiveRECTC1Ev
	ldr r0, _02169B80 ; =_ZN15CSoftwareSpriteD1Ev
	ldr r3, _02169B84 ; =FUN_02005150
	str r0, [sp]
	add r0, sl, #0x58
	mov r1, #0x20
	mov r2, #0x4c
	bl __cxa_vec_ctor
	mov r1, #0
	mov r0, #1
	str r1, [sl, #0xa1c]
	str r0, [sl, #0xa28]
	sub r0, r0, #2
	str r1, [sl, #0xa44]
	str r1, [sl, #0xa48]
	str r1, [sl, #0xa4c]
	str r1, [sl, #0xa68]
	str r1, [sl, #0xa6c]
	str r1, [sl, #0xa70]
	str r1, [sl, #0x40]
	str r1, [sl, #0x44]
	mov r2, #0x40000
	str r2, [sl, #0x48]
	cmp sb, #0
	mov r1, #0x20000
	str r1, [sl, #0x4c]
	str r2, [sl, #0x38]
	str r1, [sl, #0x3c]
	str r0, [sl, #0x1c]
	beq _02169AC4
	cmp sb, #1
	beq _02169AD0
	cmp sb, #2
	moveq r0, #0x10
	streq r0, [sl, #0xa18]
	b _02169AD8
	arm_func_end ov0_02169A08
_02169AC4:
	mov r0, #0x10
	str r0, [sl, #0xa18]
	b _02169AD8
_02169AD0:
	mov r0, #0x20
	str r0, [sl, #0xa18]
_02169AD8:
	mov r7, #0
	mov r8, r7
	mov fp, #0x1800
	mov r6, #6
	mvn r5, #0
	mov r4, r7
_02169AF0:
	add r0, sl, r8
	strh r6, [r0, #0x82]
	str r5, [r0, #0x5c]
	strh r4, [r0, #0x60]
	cmp sb, #2
	streq fp, [r0, #0x78]
	streq fp, [r0, #0x7c]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x460
	add r1, r1, #0x1000
	add r0, r0, #0x1000
	ldmib r1, {r3, ip}
	ldr r1, [r0, #0x460]
	add r2, sl, r7, lsl #1
	mla r1, r3, r1, ip
	str r1, [r0, #0x460]
	ldr r0, _02169B88 ; =0x00000E38
	mov r1, r1, lsr #0x10
	mul r0, r1, r0
	mov r0, r0, lsr #0x10
	mov r1, r0, lsl #0x10
	ldr r0, _02169B8C ; =0xFFFFF8E4
	add r7, r7, #1
	add r1, r0, r1, lsr #16
	add r0, r2, #0x900
	strh r1, [r0, #0xd8]
	cmp r7, #0x20
	add r8, r8, #0x4c
	blt _02169AF0
	mov r1, #0x1000
	str r1, [sl, #0xa24]
	mov r0, sl
	str r1, [sl, #0xa20]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02169B78: .word _ZTV12CFieldEffect+8
_02169B7C: .word ptr_FUN_overlay_0_02169b90_overlay_0_02179e58
_02169B80: .word _ZN15CSoftwareSpriteD1Ev
_02169B84: .word _ZN15CSoftwareSpriteC1Ev
_02169B88: .word 0x00000E38
_02169B8C: .word 0xFFFFF8E4

	arm_func_start _ZN22CFieldEffectDarkShadowD1Ev
_ZN22CFieldEffectDarkShadowD1Ev: ; 0x02169B90
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02169BD4 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x58
	mov r1, #0x20
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	add r0, r4, #0x18
	bl _ZN14CPrimitiveRECTD1Ev
	ldr r1, _02169BD8 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02169BD4: .word _ZN15CSoftwareSpriteD1Ev
_02169BD8: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN22CFieldEffectDarkShadowD1Ev

	arm_func_start ov0_02169BDC
ov0_02169BDC: ; 0x02169BDC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02169C28 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x58
	mov r1, #0x20
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	add r0, r4, #0x18
	bl _ZN14CPrimitiveRECTD1Ev
	ldr r1, _02169C2C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02169C28: .word _ZN15CSoftwareSpriteD1Ev
_02169C2C: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_02169BDC

	arm_func_start _ZN22CFieldEffectDarkShadow8SetParamEii
_ZN22CFieldEffectDarkShadow8SetParamEii: ; 0x02169C30
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	mov r0, #1
	cmp r1, #0x11
	str r0, [sp]
	bgt _02169C70
	cmp r1, #0x11
	bge _02169D7C
	cmp r1, #4
	addls pc, pc, r1, lsl #2
	b _02169DAC
_02169C5C: ; jump table
	b _02169DAC ; case 0
	b _02169C7C ; case 1
	b _02169CF0 ; case 2
	b _02169D64 ; case 3
	b _02169D70 ; case 4
	arm_func_end _ZN22CFieldEffectDarkShadow8SetParamEii
_02169C70:
	cmp r1, #0x14
	beq _02169DA4
	b _02169DAC
_02169C7C:
	mov sb, r2, lsl #0xc
	str sb, [r4, #0x30]
	ldr r0, [r4, #0xa18]
	mov r6, #0
	mov r7, r6
	cmp r0, #0
	ble _02169DB4
	ldr r5, _02169DBC ; =FX_SinCosTable_
	mov r8, r4
	mov fp, #0x10000
_02169CA4:
	mov r0, r6, asr #4
	ldr r1, [r8, #0x78]
	add r0, r5, r0, lsl #2
	mov r1, r1, lsl #3
	mov r2, r1, asr #0xc
	ldrsh r1, [r0, #2]
	rsb r2, r2, #0x28
	mov r0, fp
	mla r1, r2, r1, sb
	str r1, [r8, #0x70]
	ldr sl, [r4, #0xa18]
	mov r1, sl
	bl _s32_div_f
	add r7, r7, #1
	cmp r7, sl
	add r6, r6, r0
	add r8, r8, #0x4c
	blt _02169CA4
	b _02169DB4
_02169CF0:
	mov sb, r2, lsl #0xc
	str sb, [r4, #0x34]
	ldr r0, [r4, #0xa18]
	mov r6, #0
	mov r7, r6
	cmp r0, #0
	ble _02169DB4
	ldr r5, _02169DBC ; =FX_SinCosTable_
	mov r8, r4
	mov fp, #0x10000
_02169D18:
	mov r0, r6, asr #4
	ldr r1, [r8, #0x7c]
	mov r0, r0, lsl #2
	mov r1, r1, lsl #3
	mov r2, r1, asr #0xc
	ldrsh r1, [r5, r0]
	rsb r2, r2, #0x18
	mov r0, fp
	mla r1, r2, r1, sb
	str r1, [r8, #0x74]
	ldr sl, [r4, #0xa18]
	mov r1, sl
	bl _s32_div_f
	add r7, r7, #1
	cmp r7, sl
	add r6, r6, r0
	add r8, r8, #0x4c
	blt _02169D18
	b _02169DB4
_02169D64:
	mov r0, r2, lsl #0xc
	str r0, [r4, #0x38]
	b _02169DB4
_02169D70:
	mov r0, r2, lsl #0xc
	str r0, [r4, #0x3c]
	b _02169DB4
_02169D7C:
	ldr r0, _02169DC0 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02169DB4
	mov r1, r2
	bl _ZN11CFieldScene12ov0_02123060Em
	cmp r0, #0
	ldrne r0, [r0, #0x14]
	strne r0, [r4, #0xa1c]
	b _02169DB4
_02169DA4:
	str r2, [r4, #0xa28]
	b _02169DB4
_02169DAC:
	mov r0, #0
	str r0, [sp]
_02169DB4:
	ldr r0, [sp]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02169DBC: .word FX_SinCosTable_
_02169DC0: .word MAIN_BSS_0210CA40

	arm_func_start _ZN22CFieldEffectDarkShadow12ov0_02142264Ei
_ZN22CFieldEffectDarkShadow12ov0_02142264Ei: ; 0x02169DC4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	ldr r0, [r4, #0xa4c]
	mov fp, r1
	cmp r0, #0
	moveq r0, #0
	beq _02169E6C
	ldr r0, [r4, #0xa48]
	add r0, r0, fp
	str r0, [r4, #0xa48]
	ldr r1, [r4, #0xa44]
	cmp r1, #0
	movle r0, #0x1000
	ble _02169E14
	ldr r0, [r4, #0xa48]
	cmp r0, r1
	movge r0, #0x1000
	bge _02169E14
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	arm_func_end _ZN22CFieldEffectDarkShadow12ov0_02142264Ei
_02169E14:
	ldr r3, [r4, #0xa2c]
	ldr r1, [r4, #0xa34]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	add r1, r3, r2
	str r1, [r4, #0xa3c]
	ldr r3, [r4, #0xa30]
	ldr r1, [r4, #0xa38]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r0, r3, r0
	str r0, [r4, #0xa40]
	ldr r1, [r4, #0xa48]
	ldr r0, [r4, #0xa44]
	cmp r1, r0
	movge r0, #0
	strge r0, [r4, #0xa4c]
	mov r0, #1
_02169E6C:
	cmp r0, #0
	beq _02169E88
	ldr r1, [r4, #0xa3c]
	add r0, r4, #0x23c
	str r1, [r4, #0xa20]
	ldr r0, [r0, #0x804]
	str r0, [r4, #0xa24]
_02169E88:
	ldr r0, [r4, #0xa70]
	cmp r0, #0
	moveq r0, #0
	beq _02169F24
	ldr r0, [r4, #0xa6c]
	add r0, r0, fp
	str r0, [r4, #0xa6c]
	ldr r1, [r4, #0xa68]
	cmp r1, #0
	movle r0, #0x1000
	ble _02169ECC
	ldr r0, [r4, #0xa6c]
	cmp r0, r1
	movge r0, #0x1000
	bge _02169ECC
	mov r0, r0, lsl #0xc
	bl _s32_div_f
_02169ECC:
	ldr r3, [r4, #0xa50]
	ldr r1, [r4, #0xa58]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	add r1, r3, r2
	str r1, [r4, #0xa60]
	ldr r3, [r4, #0xa54]
	ldr r1, [r4, #0xa5c]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r0, r3, r0
	str r0, [r4, #0xa64]
	ldr r1, [r4, #0xa6c]
	ldr r0, [r4, #0xa68]
	cmp r1, r0
	movge r0, #0
	strge r0, [r4, #0xa70]
	mov r0, #1
_02169F24:
	cmp r0, #0
	beq _0216A014
	ldr r0, [r4, #0xa60]
	mov r7, #0
	str r0, [r4, #0x30]
	ldr r0, [r4, #0xa18]
	mov r8, r7
	cmp r0, #0
	ble _02169FA0
	ldr r6, _0216A068 ; =FX_SinCosTable_
	mov sb, r4
	mov r5, #0x10000
_02169F54:
	mov r0, r7, asr #4
	ldr r1, [sb, #0x78]
	add r0, r6, r0, lsl #2
	mov r1, r1, lsl #3
	mov r1, r1, asr #0xc
	ldrsh r0, [r0, #2]
	ldr r2, [r4, #0xa60]
	rsb r1, r1, #0x28
	mla r0, r1, r0, r2
	str r0, [sb, #0x70]
	ldr sl, [r4, #0xa18]
	mov r0, r5
	mov r1, sl
	bl _s32_div_f
	add r8, r8, #1
	cmp r8, sl
	add r7, r7, r0
	add sb, sb, #0x4c
	blt _02169F54
_02169FA0:
	ldr r0, [r4, #0xa64]
	mov r7, #0
	str r0, [r4, #0x34]
	ldr r0, [r4, #0xa18]
	mov r8, r7
	cmp r0, #0
	ble _0216A014
	ldr r6, _0216A068 ; =FX_SinCosTable_
	mov sb, r4
	mov r5, #0x10000
_02169FC8:
	mov r0, r7, asr #4
	ldr r1, [sb, #0x7c]
	mov r0, r0, lsl #2
	mov r1, r1, lsl #3
	mov r1, r1, asr #0xc
	ldrsh r0, [r6, r0]
	ldr r2, [r4, #0xa64]
	rsb r1, r1, #0x18
	mla r0, r1, r0, r2
	str r0, [sb, #0x74]
	ldr sl, [r4, #0xa18]
	mov r0, r5
	mov r1, sl
	bl _s32_div_f
	add r8, r8, #1
	cmp r8, sl
	add r7, r7, r0
	add sb, sb, #0x4c
	blt _02169FC8
_0216A014:
	mov r0, r4
	mov r1, fp
	bl _ZN12CFieldEffect12ov0_02142264Ei
	ldr r1, [r4, #0xa18]
	mov r5, #0
	cmp r1, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r6, r4
_0216A034:
	add r1, r4, r5, lsl #1
	add r1, r1, #0x900
	ldrsh r2, [r1, #0xd8]
	ldrh r1, [r6, #0x80]
	ldr r3, [r4, #0xa28]
	add r5, r5, #1
	mla r1, r3, r2, r1
	strh r1, [r6, #0x80]
	ldr r1, [r4, #0xa18]
	add r6, r6, #0x4c
	cmp r5, r1
	blt _0216A034
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0216A068: .word FX_SinCosTable_

	arm_func_start _ZN22CFieldEffectDarkShadow12ov0_02142344EP8Camera2D
_ZN22CFieldEffectDarkShadow12ov0_02142344EP8Camera2D: ; 0x0216A06C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	ldr r0, [sl, #0x14]
	mov fp, r1
	cmp r0, #0
	cmpne r0, #4
	beq _0216A258
	ldr r0, _0216A260 ; =MAIN_BSS_0210CA60
	ldr r1, [sl, #0xa1c]
	ldr r0, [r0]
	add r0, r0, r1, lsl #2
	ldr sb, [r0, #0x790]
	str sb, [sl, #0x1c]
	ldr r2, [sl, #0xa20]
	cmp r2, #0x1000
	ldreq r0, [sl, #0xa24]
	cmpeq r0, #0x1000
	beq _0216A1FC
	mov r0, r2, asr #0x1f
	mov r0, r0, lsl #0x12
	mov r1, r2, lsl #0x12
	orr r0, r0, r2, lsr #14
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [sl, #0x38]
	ldr r1, [sl, #0xa24]
	mov r4, #0
	mov r0, r1, asr #0x1f
	mov r0, r0, lsl #0x11
	mov r2, r1, lsl #0x11
	orr r0, r0, r1, lsr #15
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [sl, #0x3c]
	ldr r0, [sl, #0xa20]
	subs r3, r0, #0x1000
	movmi r3, r4
	bmi _0216A10C
	cmp r3, #0x1000
	movgt r3, #0x1000
	arm_func_end _ZN22CFieldEffectDarkShadow12ov0_02142344EP8Camera2D
_0216A10C:
	mov r0, r3, lsl #4
	mov r0, r0, asr #0xc
	add r2, r0, #0x10
	str r2, [sl, #0xa18]
	cmp r2, #0
	mov r5, #0
	ble _0216A1FC
	mov r0, r3, asr #0x1f
	mov r0, r0, lsl #0xb
	mov r1, r3, lsl #0xb
	orr r0, r0, r3, lsr #21
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	cmp r2, #0
	add r7, r1, #0x1800
	ble _0216A1FC
	mov r6, sl
_0216A150:
	str r7, [r6, #0x78]
	str r7, [r6, #0x7c]
	mov r0, r4, asr #4
	mov r1, r0, lsl #1
	ldr r2, [sl, #0x38]
	ldr r0, _0216A264 ; =FX_SinCosTable_
	ldr r8, [sl, #0xa20]
	mov r2, r2, asr #1
	add r0, r0, r1, lsl #1
	add r8, r2, r8, lsl #3
	ldr r3, [r6, #0x78]
	ldrsh r2, [r0, #2]
	sub r3, r8, r3, lsl #3
	ldr r0, [sl, #0x30]
	smull r8, r2, r3, r2
	mov r3, r8, lsr #0xc
	orr r3, r3, r2, lsl #20
	add r0, r0, r3
	str r0, [r6, #0x70]
	ldr r2, [sl, #0x3c]
	mov r0, r1, lsl #1
	mov r1, r2, asr #1
	ldr r3, [sl, #0xa24]
	ldr r2, [r6, #0x7c]
	add r3, r1, r3, lsl #3
	ldr r1, _0216A264 ; =FX_SinCosTable_
	ldrsh r0, [r1, r0]
	sub r1, r3, r2, lsl #3
	ldr r3, [sl, #0x34]
	smull r2, r0, r1, r0
	mov r1, r2, lsr #0xc
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	str r0, [r6, #0x74]
	ldr r8, [sl, #0xa18]
	mov r0, #0x10000
	mov r1, r8
	bl _s32_div_f
	add r5, r5, #1
	cmp r5, r8
	add r4, r4, r0
	add r6, r6, #0x4c
	blt _0216A150
_0216A1FC:
	add r0, sl, #0x18
	ldr r2, [r0]
	mov r1, fp
	ldr r2, [r2, #8]
	blx r2
	ldr r0, [sl, #0xa18]
	mov r4, #0
	cmp r0, #0
	ble _0216A258
	mov r5, sl
	add r6, sl, #0x58
_0216A228:
	mov r0, r6
	str sb, [r5, #0x5c]
	ldr r2, [r0]
	mov r1, fp
	ldr r2, [r2, #8]
	blx r2
	ldr r0, [sl, #0xa18]
	add r4, r4, #1
	cmp r4, r0
	add r5, r5, #0x4c
	add r6, r6, #0x4c
	blt _0216A228
_0216A258:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0216A260: .word MAIN_BSS_0210CA60
_0216A264: .word FX_SinCosTable_

	arm_func_start _ZN22CFieldEffectDarkShadow12ov0_0214239CEi
_ZN22CFieldEffectDarkShadow12ov0_0214239CEi: ; 0x0216A268
	mov r0, #1
	bx lr
	arm_func_end _ZN22CFieldEffectDarkShadow12ov0_0214239CEi

	arm_func_start _ZN22CFieldEffectDarkShadow12sub_02033388ERK7Point2Di
_ZN22CFieldEffectDarkShadow12sub_02033388ERK7Point2Di: ; 0x0216A270
	stmdb sp!, {r3, lr}
	ldr r3, [r0, #0xa20]
	mov ip, #1
	str r3, [r0, #0xa2c]
	ldr lr, [r0, #0xa24]
	cmp r2, #0
	str lr, [r0, #0xa30]
	ldr lr, [r1]
	mov r3, #0
	str lr, [r0, #0xa34]
	ldr lr, [r1, #4]
	str lr, [r0, #0xa38]
	str r2, [r0, #0xa44]
	str ip, [r0, #0xa4c]
	ldr r2, [r0, #0xa2c]
	str r2, [r0, #0xa3c]
	ldr r2, [r0, #0xa30]
	str r2, [r0, #0xa40]
	str r3, [r0, #0xa48]
	ldmneia sp!, {r3, pc}
	ldr r2, [r1]
	str r2, [r0, #0xa20]
	ldr r1, [r1, #4]
	str r1, [r0, #0xa24]
	ldmia sp!, {r3, pc}
	arm_func_end _ZN22CFieldEffectDarkShadow12sub_02033388ERK7Point2Di

	arm_func_start _ZN22CFieldEffectDarkShadow12sub_0203331CERK7Point2Di
_ZN22CFieldEffectDarkShadow12sub_0203331CERK7Point2Di: ; 0x0216A2D4
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	mov r5, r1
	add r0, sp, #0
	add r1, r6, #0x18
	mov r4, r2
	bl _ZN14CPrimitiveRECT12sub_02003C00EP7Point2DPS_
	ldr r0, [sp]
	mov r1, #1
	str r0, [r6, #0xa50]
	ldr r2, [sp, #4]
	mov r0, #0
	str r2, [r6, #0xa54]
	ldr r2, [r5]
	str r2, [r6, #0xa58]
	ldr r2, [r5, #4]
	str r2, [r6, #0xa5c]
	str r4, [r6, #0xa68]
	str r1, [r6, #0xa70]
	ldr r1, [r6, #0xa50]
	str r1, [r6, #0xa60]
	ldr r1, [r6, #0xa54]
	str r1, [r6, #0xa64]
	str r0, [r6, #0xa6c]
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end _ZN22CFieldEffectDarkShadow12sub_0203331CERK7Point2Di

	arm_func_start _ZN29CFieldEffectDarkShadowFactory6CreateEi
_ZN29CFieldEffectDarkShadowFactory6CreateEi: ; 0x0216A340
	stmdb sp!, {r4, r5, r6, lr}
	ldr r0, _0216A420 ; =0x00000A74
	mov r5, r1
	bl _Znwm
	movs r4, r0
	beq _0216A364
	mov r1, r5
	bl ov0_02169A08
	mov r4, r0
	arm_func_end _ZN29CFieldEffectDarkShadowFactory6CreateEi
_0216A364:
	cmp r4, #0
	beq _0216A418
	ldr r0, _0216A424 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _0216A390
	ldr r0, [r0, #0x48]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x50]
	str r1, [r4, #0x54]
_0216A390:
	ldr r0, _0216A428 ; =MAIN_BSS_0210CA60
	ldr r6, [r0]
	cmp r6, #0
	beq _0216A418
	add r0, r6, #0x27c
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	add r1, r6, #0x27c
	mov r5, r0
	add r0, r1, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	add r1, r6, #0x27c
	mov r6, r0
	add r0, r1, #0x400
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	mov r2, #0
	mov r3, r4
	mov r1, r2
_0216A3F8:
	str r0, [r3, #0x84]
	str r1, [r3, #0x88]
	str r6, [r3, #0x8c]
	add r2, r2, #1
	str r5, [r3, #0x90]
	cmp r2, #0x20
	add r3, r3, #0x4c
	blt _0216A3F8
_0216A418:
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0216A420: .word 0x00000A74
_0216A424: .word MAIN_BSS_0210CA40
_0216A428: .word MAIN_BSS_0210CA60

	arm_func_start _ZN22CFieldEffectDarkShadow11GetEffectIdEv
_ZN22CFieldEffectDarkShadow11GetEffectIdEv: ; 0x0216A42C
	mov r0, #0x16
	bx lr
	arm_func_end _ZN22CFieldEffectDarkShadow11GetEffectIdEv

	arm_func_start ov0_0216A434
ov0_0216A434: ; 0x0216A434
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216A434

	arm_func_start ov0_0216A448
ov0_0216A448: ; 0x0216A448
	stmdb sp!, {r4, lr}
	ldr r1, _0216A5AC ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r1, _0216A5B0 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r0, #0
	str r1, [r4]
	ldr r2, _0216A5B4 ; =ptr_FUN_overlay_0_0216a5d8_overlay_0_0217a21c
	str r0, [r4, #0x1c]
	ldr r1, _0216A5B8 ; =PTR_LAB_overlay_0_0216a5d0_overlay_0_02179f44
	str r2, [r4]
	str r1, [r4, #0x20]
	mov r2, #0x1000
	ldr r1, _0216A5BC ; =PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	str r0, [r4, #0x3c]
	str r0, [r4, #0x2c]
	str r0, [r4, #0x30]
	str r0, [r4, #0x34]
	ldr r1, _0216A5C0 ; =PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4
	str r2, [r4, #0x38]
	str r1, [r4, #0x28]
	str r0, [r4, #0x50]
	str r0, [r4, #0x54]
	str r2, [r4, #0x40]
	str r0, [r4, #0x44]
	mov r1, #0x10
	str r0, [r4, #0x48]
	sub r3, r2, #0x2000
	ldr r2, _0216A5C4 ; =PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000
	str r3, [r4, #0x4c]
	str r2, [r4, #0x28]
	str r0, [r4, #0x58]
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
	mov r2, #0xa
	str r2, [r4, #0x64]
	mov r2, #0xf
	str r2, [r4, #0x68]
	str r1, [r4, #0x6c]
	str r0, [r4, #0x70]
	str r0, [r4, #0x74]
	sub r1, r1, #0x810
	str r1, [r4, #0x78]
	ldr r1, _0216A5C8 ; =PTR_LAB_overlay_0_0216a5d4_overlay_0_02179fe0
	strb r0, [r4, #0x7c]
	str r1, [r4, #0x28]
	strb r0, [r4, #0x7d]
	strb r0, [r4, #0x7e]
	str r0, [r4, #0x80]
	str r0, [r4, #0x84]
	str r0, [r4, #0x88]
	ldr r1, _0216A5CC ; =g_ntfTextureFormats
	str r0, [r4, #0x8c]
	str r1, [r4, #0x90]
	str r0, [r4, #0x94]
	str r0, [r4, #0x98]
	str r0, [r4, #0x9c]
	str r0, [r4, #0xa0]
	str r0, [r4, #0xa4]
	str r0, [r4, #0xa8]
	mov r0, r4
	bl ov0_0216A750
	mov r0, r4
	ldr r3, [r0]
	mov r1, #0
	ldr r3, [r3, #0x38]
	mov r2, #0x30
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #3
	ldr r3, [r3, #0x38]
	mov r2, #0x100
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #4
	mov r2, #0xc0
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0x20
	str r0, [r4, #0x6c]
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216A5AC: .word _ZTV12CFieldEffect+8
_0216A5B0: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216A5B4: .word ptr_FUN_overlay_0_0216a5d8_overlay_0_0217a21c
_0216A5B8: .word PTR_LAB_overlay_0_0216a5d0_overlay_0_02179f44
_0216A5BC: .word PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c
_0216A5C0: .word PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4
_0216A5C4: .word PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000
_0216A5C8: .word PTR_LAB_overlay_0_0216a5d4_overlay_0_02179fe0
_0216A5CC: .word g_ntfTextureFormats
	arm_func_end ov0_0216A448

	arm_func_start _ZN25CFieldEffectDarknessClear11CForceFieldD1Ev
_ZN25CFieldEffectDarknessClear11CForceFieldD1Ev: ; 0x0216A5D0
	bx lr
	arm_func_end _ZN25CFieldEffectDarknessClear11CForceFieldD1Ev

	arm_func_start _ZN25CFieldEffectDarknessClear8CEmitterD1Ev
_ZN25CFieldEffectDarknessClear8CEmitterD1Ev: ; 0x0216A5D4
	bx lr
	arm_func_end _ZN25CFieldEffectDarknessClear8CEmitterD1Ev

	arm_func_start _ZN25CFieldEffectDarknessClearD1Ev
_ZN25CFieldEffectDarknessClearD1Ev: ; 0x0216A5D8
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	add r0, r4, #0x80
	bl _ZN10NtfTexture7ReleaseEv
	ldr r0, _0216A684 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216A664
	beq _0216A65C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216A618
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN25CFieldEffectDarknessClearD1Ev
_0216A618:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216A630
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216A630:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216A654
	ldr r3, _0216A688 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216A654:
	mov r0, r5
	bl _ZdlPv
_0216A65C:
	mov r0, #0
	str r0, [r4, #0x18]
_0216A664:
	ldr r1, _0216A68C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216A684: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216A688: .word ov0_0216AD48
_0216A68C: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216A690
ov0_0216A690: ; 0x0216A690
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	add r0, r4, #0x80
	bl _ZN10NtfTexture7ReleaseEv
	ldr r0, _0216A744 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216A71C
	beq _0216A714
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216A6D0
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end ov0_0216A690
_0216A6D0:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216A6E8
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216A6E8:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216A70C
	ldr r3, _0216A748 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216A70C:
	mov r0, r5
	bl _ZdlPv
_0216A714:
	mov r0, #0
	str r0, [r4, #0x18]
_0216A71C:
	ldr r1, _0216A74C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216A744: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216A748: .word ov0_0216AD48
_0216A74C: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216A750
ov0_0216A750: ; 0x0216A750
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x80
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	mov r4, r0
	str ip, [sp, #8]
	ldr r1, _0216A7D8 ; =DAT_overlay_0_0217a464
	ldr r2, _0216A7DC ; =s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217a468
	add r0, sp, #0x14
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r1, _0216A7E0 ; =s_MEF_ef102_00_ntft_overlay_0_0217a488
	ldr r2, _0216A7E4 ; =s_MEF_ef102_00_ntfp_overlay_0_0217a49c
	add r0, r4, #0x80
	mov r3, #0
	bl _ZN10NtfTexture4LoadEPKcS1_i
	mov r0, #6
	str r0, [r4, #0x9c]
	mov r0, #2
	str r0, [r4, #0xa0]
	str r0, [r4, #0xa4]
	add r1, r4, #0x80
	str r1, [sp, #0x10]
	mov r0, r4
	ldr r2, [r0]
	add r1, sp, #0x10
	ldr r2, [r2, #0x5c]
	blx r2
	add r0, sp, #0x14
	bl _ZN13CArchiveGuardD1Ev
	add sp, sp, #0x80
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216A7D8: .word DAT_overlay_0_0217a464
_0216A7DC: .word s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217a468
_0216A7E0: .word s_MEF_ef102_00_ntft_overlay_0_0217a488
_0216A7E4: .word s_MEF_ef102_00_ntfp_overlay_0_0217a49c
	arm_func_end ov0_0216A750

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam: ; 0x0216A7E8
	ldr r1, [r1]
	str r1, [r0, #0x1c]
	ldr r1, [r0, #0x18]
	cmp r1, #0
	ldrne r0, [r0, #0x1c]
	strne r0, [r1, #0x18]
	bx lr
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam

	arm_func_start _ZN25CFieldEffectDarknessClear8SetParamEii
_ZN25CFieldEffectDarknessClear8SetParamEii: ; 0x0216A804
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #4
	mov r0, #1
	addls pc, pc, r1, lsl #2
	b _0216A858
_0216A824: ; jump table
	b _0216A858 ; case 0
	b _0216AAB8 ; case 1
	b _0216AAB8 ; case 2
	b _0216A838 ; case 3
	b _0216A848 ; case 4
	arm_func_end _ZN25CFieldEffectDarknessClear8SetParamEii
_0216A838:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x50]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216A848:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x54]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216A858:
	cmp r1, #0
	mov r0, #0
	beq _0216A87C
	cmp r1, #1
	beq _0216AA90
	cmp r1, #2
	beq _0216AAA8
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216A87C:
	cmp r5, #0
	ble _0216AA84
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _0216A8F8
	beq _0216A8F0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0216A8AC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_0216A8AC:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0216A8C4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_0216A8C4:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0216A8E8
	ldr r3, _0216AAC0 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x20]
_0216A8E8:
	mov r0, r4
	bl _ZdlPv
_0216A8F0:
	mov r0, #0
	str r0, [r6, #0x18]
_0216A8F8:
	mov r0, #0x34
	bl _Znwm
	movs r4, r0
	beq _0216AA28
	mov r0, #0x1000
	str r0, [r4, #8]
	mov r0, #1
	str r0, [r4, #0x14]
	mov r1, #0
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	str r5, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0216A9CC
	ldr r1, _0216AAC0 ; =ov0_0216AD48
	ldr r3, _0216AAC4 ; =ov0_0216AD5C
	str r1, [sp]
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _0216A9C0
	mov r1, lr
	mov ip, lr
	mov r2, #0x84
_0216A974:
	ldr r3, [r4, #0x20]
	add r5, r0, #1
	add r3, r3, r1
	str lr, [r3, #0x7c]
	ldr r3, [r4, #0x24]
	add r0, r0, #1
	cmp r5, r3
	ldrlo r3, [r4, #0x20]
	mlalo lr, r5, r2, r3
	ldr r3, [r4, #0x20]
	movhs lr, ip
	add r3, r3, r1
	str lr, [r3, #0x80]
	ldr r5, [r4, #0x20]
	ldr r3, [r4, #0x24]
	add lr, r5, r1
	cmp r0, r3
	add r1, r1, #0x84
	blo _0216A974
_0216A9C0:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x2c]
	b _0216A9D4
_0216A9CC:
	str r1, [r4, #0x20]
	str r1, [r4, #0x2c]
_0216A9D4:
	mov r1, #0
	str r1, [r4, #0x30]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _0216AA1C
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x14]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x14]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x10]
_0216AA1C:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_0216AA28:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _0216AA84
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0216AA60
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0216AA60:
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x60]
	blx r1
	ldr r1, [r6, #0x18]
	str r0, [r1, #0x1c]
	ldr r1, [r6, #0x1c]
	ldr r0, [r6, #0x18]
	str r1, [r0, #0x18]
_0216AA84:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216AA90:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216AAA8:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
_0216AAB8:
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0216AAC0: .word ov0_0216AD48
_0216AAC4: .word ov0_0216AD5C

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE8SetParamEii
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFE8SetParamEii: ; 0x0216AAC8
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #0
	mov r0, #0
	beq _0216AAFC
	cmp r1, #1
	beq _0216AD10
	cmp r1, #2
	beq _0216AD28
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE8SetParamEii
_0216AAFC:
	cmp r5, #0
	ble _0216AD04
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _0216AB78
	beq _0216AB70
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0216AB2C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_0216AB2C:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0216AB44
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_0216AB44:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0216AB68
	ldr r3, _0216AD40 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x20]
_0216AB68:
	mov r0, r4
	bl _ZdlPv
_0216AB70:
	mov r0, #0
	str r0, [r6, #0x18]
_0216AB78:
	mov r0, #0x34
	bl _Znwm
	movs r4, r0
	beq _0216ACA8
	mov r0, #0x1000
	str r0, [r4, #8]
	mov r0, #1
	str r0, [r4, #0x14]
	mov r1, #0
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	str r5, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0216AC4C
	ldr r1, _0216AD40 ; =ov0_0216AD48
	ldr r3, _0216AD44 ; =ov0_0216AD5C
	str r1, [sp]
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _0216AC40
	mov r1, lr
	mov ip, lr
	mov r2, #0x84
_0216ABF4:
	ldr r3, [r4, #0x20]
	add r5, r0, #1
	add r3, r3, r1
	str lr, [r3, #0x7c]
	ldr r3, [r4, #0x24]
	add r0, r0, #1
	cmp r5, r3
	ldrlo r3, [r4, #0x20]
	mlalo lr, r5, r2, r3
	ldr r3, [r4, #0x20]
	movhs lr, ip
	add r3, r3, r1
	str lr, [r3, #0x80]
	ldr r5, [r4, #0x20]
	ldr r3, [r4, #0x24]
	add lr, r5, r1
	cmp r0, r3
	add r1, r1, #0x84
	blo _0216ABF4
_0216AC40:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x2c]
	b _0216AC54
_0216AC4C:
	str r1, [r4, #0x20]
	str r1, [r4, #0x2c]
_0216AC54:
	mov r1, #0
	str r1, [r4, #0x30]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _0216AC9C
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x14]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x14]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x10]
_0216AC9C:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_0216ACA8:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _0216AD04
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0216ACE0
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0216ACE0:
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x60]
	blx r1
	ldr r1, [r6, #0x18]
	str r0, [r1, #0x1c]
	ldr r1, [r6, #0x1c]
	ldr r0, [r6, #0x18]
	str r1, [r0, #0x18]
_0216AD04:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216AD10:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216AD28:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0216AD40: .word ov0_0216AD48
_0216AD44: .word ov0_0216AD5C

	arm_func_start ov0_0216AD48
ov0_0216AD48: ; 0x0216AD48
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216AD48

	arm_func_start ov0_0216AD5C
ov0_0216AD5C: ; 0x0216AD5C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _0216ADB8 ; =_ZTV17CPrimitiveRectNTF+8
	mov r1, #0
	str r0, [r4]
	ldr r0, _0216ADBC ; =_ZTV16CSimpleSpriteNTF+8
	str r1, [r4, #0x18]
	str r0, [r4]
	str r1, [r4, #0x4c]
	str r1, [r4, #0x50]
	strh r1, [r4, #0x54]
	mov r0, #0x1000
	str r1, [r4, #0x58]
	str r0, [r4, #0x48]
	str r0, [r4, #0x44]
	str r1, [r4, #0x78]
	mov r0, #8
	str r0, [r4, #0x10]
	ldr r1, _0216ADC0 ; =0x00000622
	mov r0, r4
	str r1, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216ADB8: .word _ZTV17CPrimitiveRectNTF+8
_0216ADBC: .word _ZTV16CSimpleSpriteNTF+8
_0216ADC0: .word 0x00000622
	arm_func_end ov0_0216AD5C

	arm_func_start _ZN25CFieldEffectDarknessClear12ov0_021421F0Eiii
_ZN25CFieldEffectDarknessClear12ov0_021421F0Eiii: ; 0x0216ADC4
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r3
	mov r6, r0
	mov r5, r2
	cmp r4, #0
	movle r4, #0xb4
	str r5, [r6, #0x64]
	str r4, [r6, #0x68]
	mov r1, r5, lsl #0xc
	mov r0, r6
	str r1, [r6, #0x24]
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	cmp r0, #0
	beq _0216AE10
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end _ZN25CFieldEffectDarknessClear12ov0_021421F0Eiii
_0216AE10:
	mov r0, r6
	mov r2, r5
	mov r3, r4
	mov r1, #0
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021421F0Eiii
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021421F0Eiii: ; 0x0216AE28
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr ip, [r0]
	mov r7, r0
	ldr ip, [ip, #0x64]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	blx ip
	cmp r0, #0
	beq _0216AE5C
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021421F0Eiii
_0216AE5C:
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov0_0216AE74
ov0_0216AE74: ; 0x0216AE74
	bx lr
	arm_func_end ov0_0216AE74

	arm_func_start _ZN25CFieldEffectDarknessClear12ov0_02142344EP8Camera2D
_ZN25CFieldEffectDarknessClear12ov0_02142344EP8Camera2D: ; 0x0216AE78
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, [r0, #0x18]
	mov r6, r1
	cmp r2, #0
	beq _0216AEA4
	ldr r1, [r6, #0x1c]
	rsb r1, r1, #0
	str r1, [r2]
	ldr r1, [r6, #0x20]
	rsb r1, r1, #0
	str r1, [r2, #4]
	arm_func_end _ZN25CFieldEffectDarknessClear12ov0_02142344EP8Camera2D
_0216AEA4:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	ldrne r4, [r5, #0x28]
	cmpne r4, #0
	beq _0216AF0C
_0216AEB8:
	ldr r0, [r5, #0x30]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x5c]
	ldr r1, [r5]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x3c]
	ldr r3, [r4, #0x60]
	ldr r2, [r5, #4]
	mov r1, r6
	add r2, r3, r2
	str r2, [r4, #0x40]
	ldrsh r2, [r4, #0x6c]
	strh r2, [r4, #0x54]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x80]
	cmp r4, #0
	bne _0216AEB8
_0216AF0C:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142344EP8Camera2D
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142344EP8Camera2D: ; 0x0216AF14
	stmdb sp!, {r4, r5, r6, lr}
	ldr r5, [r0, #0x18]
	mov r6, r1
	cmp r5, #0
	ldrne r4, [r5, #0x28]
	cmpne r4, #0
	beq _0216AF84
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142344EP8Camera2D
_0216AF30:
	ldr r0, [r5, #0x30]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x5c]
	ldr r1, [r5]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x3c]
	ldr r3, [r4, #0x60]
	ldr r2, [r5, #4]
	mov r1, r6
	add r2, r3, r2
	str r2, [r4, #0x40]
	ldrsh r2, [r4, #0x6c]
	strh r2, [r4, #0x54]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x80]
	cmp r4, #0
	bne _0216AF30
_0216AF84:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN25CFieldEffectDarknessClear11CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
_ZN25CFieldEffectDarknessClear11CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi: ; 0x0216AF8C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r1
	ldr r2, [r5, #0x74]
	ldr r1, [r5, #0x70]
	ldr r0, [r0, #4]
	sub r4, r2, r1
	cmp r4, r0
	ldmltia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	add r0, r0, #0x28
	str r0, [r5, #0x44]
	add r0, r1, #0x28
	str r0, [r5, #0x48]
	ldr r0, [r5, #0x70]
	ldr r2, [r5, #0x74]
	rsb r3, r0, r0, lsl #5
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	mov r0, r0, asr #0xc
	str r0, [r5, #0x14]
	ldr r0, [r5, #0x64]
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r0, [r5, #0x74]
	sub r4, r0, r4
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r3, r1, #0x1400
	add r0, r0, #0x1000
	ldr r2, [r0, #0x448]
	ldmib r3, {r1, ip}
	umull r6, lr, ip, r2
	mla lr, ip, r1, lr
	ldr r1, [r3, #0xc]
	ldr r7, [r3, #0x10]
	mla lr, r1, r2, lr
	adds r7, r7, r6
	ldr r6, [r3, #0x14]
	mov r1, #0
	str r7, [r0, #0x448]
	adc r6, r6, lr
	mov r0, r1, lsl #7
	orr r0, r0, r6, lsr #25
	add r0, r0, #0x40
	mov ip, r0, lsl #0xc
	mov r0, ip, asr #0x1f
	mov r1, r0, lsl #0xc
	str r6, [r3, #4]
	mov r2, r4
	orr r1, r1, ip, lsr #20
	mov r0, ip, lsl #0xc
	mov r3, r4, asr #0x1f
	bl _ll_div
	ldr r1, [r5, #0x78]
	cmp r1, #0
	strne r0, [r5, #0x64]
	movne r0, #0
	strne r0, [r5, #0x68]
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
	rsb r0, r0, #0
	str r0, [r5, #0x64]
	mov r0, #0
	str r0, [r5, #0x68]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end _ZN25CFieldEffectDarknessClear11CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi

	arm_func_start _ZN25CFieldEffectDarknessClear8CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE
_ZN25CFieldEffectDarknessClear8CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE: ; 0x0216B0A0
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	ldr r3, _0216B38C ; =MAIN_BSS_0210CEC8
	mov r5, r0
	ldr r4, [r3, #8]
	ldmia r3, {r2, r6}
	mla r7, r6, r2, r4
	mla r4, r6, r7, r4
	ldr r2, [r5, #0x2c]
	ldr r0, [r5, #0x28]
	mov r8, r7, lsr #0x10
	str r4, [r3]
	mov r7, r4, lsr #0x10
	ldr r4, _0216B390 ; =0x00007FFF
	mov r3, r8, lsl #0x10
	and r8, r4, r3, lsr #16
	mov r3, r7, lsl #0x10
	and r7, r4, r3, lsr #16
	mov r3, r0, asr #2
	mov r0, r8, asr #3
	smull r4, sl, r0, r3
	adds r0, r4, #0x800
	ldrb r6, [r5, #0x56]
	mov r2, r2, asr #2
	mov r7, r7, asr #3
	add lr, r6, #1
	and r4, r6, #3
	smull sb, r8, r7, r2
	adc sl, sl, #0
	adds r7, sb, #0x800
	mul sb, r4, r3
	mov r0, r0, lsr #0xc
	orr r0, r0, sl, lsl #20
	ldr sl, [r5, #0x28]
	mov r4, r1
	sub r1, sb, sl, asr #1
	mov r6, r6, asr #2
	sub sb, r0, r3, asr #1
	mul r0, r6, r2
	ldr sl, [r5, #0x2c]
	and ip, lr, #0xff
	add r1, r1, r3, asr #1
	and r3, ip, #0xf
	strb r3, [r5, #0x56]
	ldr r3, [r5, #4]
	adc r6, r8, #0
	mov r7, r7, lsr #0xc
	orr r7, r7, r6, lsl #20
	add r3, r3, sb
	ldr r6, [r5, #8]
	add r1, r1, r3
	sub r0, r0, sl, asr #1
	sub r7, r7, r2, asr #1
	add r2, r0, r2, asr #1
	add r0, r6, r7
	str r1, [r4, #0x5c]
	add r0, r2, r0
	str r0, [r4, #0x60]
	ldr r1, [r5, #0x40]
	ldr r0, [r5, #0x3c]
	sub r0, r1, r0
	add r6, r0, #1
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, r7}
	umull sb, r8, r7, r3
	mla r8, r7, r2, r8
	ldr r2, [r1, #0xc]
	ldr sl, [r1, #0x10]
	mla r8, r2, r3, r8
	ldr r7, [r1, #0x14]
	adds sb, sl, sb
	str sb, [r0, #0x448]
	adc r0, r7, r8
	str r0, [r1, #4]
	cmp r6, #0
	ldreq r2, [r1, #4]
	ldrne r0, [r1, #4]
	umullne r1, r2, r0, r6
	ldr r1, [r5, #0x3c]
	mov r0, #0x1f
	add r1, r1, r2
	mov r1, r1, lsl #0xc
	str r1, [r4, #0x70]
	str r1, [r4, #0x74]
	mov r1, #0
	strh r1, [r4, #8]
	str r0, [r4, #0x14]
	sub r0, r0, #0x20
	str r0, [r4, #4]
	strh r1, [r4, #0x6e]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	mov r0, #0x20000
	str r0, [r4, #0x34]
	str r0, [r4, #0x38]
	str r0, [r4, #0x4c]
	str r0, [r4, #0x50]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, r6}
	umull r8, r7, r6, r3
	mla r7, r6, r2, r7
	ldr r2, [r1, #0xc]
	ldr sb, [r1, #0x10]
	mla r7, r2, r3, r7
	ldr r6, [r1, #0x14]
	adds r8, sb, r8
	str r8, [r0, #0x448]
	adc r3, r6, r7
	ldr r0, _0216B394 ; =0x00000C01
	str r3, [r1, #4]
	umull r0, r2, r3, r0
	add r6, r2, #0x1800
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr r7, [r2, #0x448]
	ldmib r1, {r3, r8}
	umull sl, sb, r8, r7
	mla sb, r8, r3, sb
	ldr r3, [r1, #0xc]
	ldr r8, [r1, #0x10]
	mla sb, r3, r7, sb
	ldr r7, [r1, #0x14]
	adds r8, r8, sl
	str r8, [r2, #0x448]
	adc r7, r7, sb
	ldr r2, _0216B398 ; =0x00000801
	str r7, [r1, #4]
	umull r1, r2, r7, r2
	add r1, r2, #0x1800
	umull r7, r2, r6, r1
	mov r3, r6, asr #0x1f
	mla r2, r3, r1, r2
	mov r1, r7, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [r4, #0x44]
	str r6, [r4, #0x48]
	mov r0, #0
	ldr r2, [r4, #0x5c]
	sub r1, r0, #0x20000
	cmp r2, r1
	blt _0216B358
	cmp r2, #0x20000
	movgt r0, #1
	bgt _0216B358
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r6, [r0, #0x448]
	ldmib r1, {r3, r7}
	umull sb, r8, r7, r6
	mla r8, r7, r3, r8
	ldr r3, [r1, #0xc]
	ldr sl, [r1, #0x10]
	mla r8, r3, r6, r8
	ldr r7, [r1, #0x14]
	adds sb, sl, sb
	mov r2, #0
	str sb, [r0, #0x448]
	adc r3, r7, r8
	mov r0, r2, lsl #1
	orrs r0, r0, r3, lsr #31
	movne r0, r2
	str r3, [r1, #4]
	moveq r0, #1
	arm_func_end _ZN25CFieldEffectDarknessClear8CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE
_0216B358:
	ldrb r2, [r5, #0x55]
	mov r1, #0
	add r2, r2, #8
	str r2, [r4, #0x10]
	ldrb r2, [r5, #0x55]
	add r3, r2, #1
	and r2, r3, #0xff
	and r2, r2, #0x1f
	strb r2, [r5, #0x55]
	str r1, [r4, #0x64]
	str r1, [r4, #0x68]
	str r0, [r4, #0x78]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_0216B38C: .word MAIN_BSS_0210CEC8
_0216B390: .word 0x00007FFF
_0216B394: .word 0x00000C01
_0216B398: .word 0x00000801

	arm_func_start ov0_0216B39C
ov0_0216B39C: ; 0x0216B39C
	stmdb sp!, {r4, lr}
	ldr r1, _0216B508 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _0216B50C ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r1, #0
	str r0, [r4]
	ldr r2, _0216B510 ; =ptr_FUN_overlay_0_0216b534_overlay_0_0217a2fc
	str r1, [r4, #0x1c]
	ldr r0, _0216B514 ; =PTR_LAB_overlay_0_0216b52c_overlay_0_02179f58
	str r2, [r4]
	str r0, [r4, #0x20]
	mov r2, #0x1000
	ldr r0, _0216B518 ; =PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c
	str r1, [r4, #0x24]
	str r0, [r4, #0x30]
	str r1, [r4, #0x44]
	str r1, [r4, #0x34]
	str r1, [r4, #0x38]
	str r1, [r4, #0x3c]
	ldr r0, _0216B51C ; =PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4
	str r2, [r4, #0x40]
	str r0, [r4, #0x30]
	str r1, [r4, #0x58]
	str r1, [r4, #0x5c]
	str r2, [r4, #0x48]
	str r1, [r4, #0x4c]
	mov r0, #0x10
	str r1, [r4, #0x50]
	sub r3, r2, #0x2000
	ldr r2, _0216B520 ; =PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000
	str r3, [r4, #0x54]
	str r2, [r4, #0x30]
	str r1, [r4, #0x60]
	str r1, [r4, #0x64]
	str r1, [r4, #0x68]
	mov r2, #0xa
	str r2, [r4, #0x6c]
	mov r2, #0xf
	str r2, [r4, #0x70]
	str r0, [r4, #0x74]
	str r1, [r4, #0x78]
	str r1, [r4, #0x7c]
	sub r0, r0, #0x810
	str r0, [r4, #0x80]
	ldr r0, _0216B524 ; =PTR_LAB_overlay_0_0216b530_overlay_0_0217a040
	strb r1, [r4, #0x84]
	str r0, [r4, #0x30]
	strb r1, [r4, #0x85]
	strb r1, [r4, #0x86]
	strb r1, [r4, #0x87]
	strb r1, [r4, #0x88]
	str r1, [r4, #0x8c]
	str r1, [r4, #0x90]
	str r1, [r4, #0x94]
	ldr r0, _0216B528 ; =g_ntfTextureFormats
	str r1, [r4, #0x98]
	str r0, [r4, #0x9c]
	str r1, [r4, #0xa0]
	str r1, [r4, #0xa4]
	str r1, [r4, #0xa8]
	str r1, [r4, #0xac]
	str r1, [r4, #0xb0]
	mov r0, r4
	str r1, [r4, #0xb4]
	bl ov0_0216B6AC
	mov r0, r4
	ldr r3, [r0]
	mov r1, #0
	ldr r3, [r3, #0x38]
	mov r2, #0x20
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #3
	ldr r3, [r3, #0x38]
	mov r2, #0x100
	blx r3
	mov r0, r4
	ldr r3, [r0]
	mov r1, #4
	mov r2, #0xc0
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, #0x20
	str r0, [r4, #0x74]
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216B508: .word _ZTV12CFieldEffect+8
_0216B50C: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216B510: .word ptr_FUN_overlay_0_0216b534_overlay_0_0217a2fc
_0216B514: .word PTR_LAB_overlay_0_0216b52c_overlay_0_02179f58
_0216B518: .word PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c
_0216B51C: .word PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4
_0216B520: .word PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000
_0216B524: .word PTR_LAB_overlay_0_0216b530_overlay_0_0217a040
_0216B528: .word g_ntfTextureFormats
	arm_func_end ov0_0216B39C

	arm_func_start _ZN26CFieldEffectDarknessClear211CForceFieldD1Ev
_ZN26CFieldEffectDarknessClear211CForceFieldD1Ev: ; 0x0216B52C
	bx lr
	arm_func_end _ZN26CFieldEffectDarknessClear211CForceFieldD1Ev

	arm_func_start _ZN26CFieldEffectDarknessClear28CEmitterD1Ev
_ZN26CFieldEffectDarknessClear28CEmitterD1Ev: ; 0x0216B530
	bx lr
	arm_func_end _ZN26CFieldEffectDarknessClear28CEmitterD1Ev

	arm_func_start _ZN26CFieldEffectDarknessClear2D1Ev
_ZN26CFieldEffectDarknessClear2D1Ev: ; 0x0216B534
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	add r0, r4, #0x8c
	bl _ZN10NtfTexture7ReleaseEv
	ldr r0, _0216B5E0 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216B5C0
	beq _0216B5B8
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216B574
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN26CFieldEffectDarknessClear2D1Ev
_0216B574:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216B58C
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216B58C:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216B5B0
	ldr r3, _0216B5E4 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216B5B0:
	mov r0, r5
	bl _ZdlPv
_0216B5B8:
	mov r0, #0
	str r0, [r4, #0x18]
_0216B5C0:
	ldr r1, _0216B5E8 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216B5E0: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216B5E4: .word ov0_0216AD48
_0216B5E8: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216B5EC
ov0_0216B5EC: ; 0x0216B5EC
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	add r0, r4, #0x8c
	bl _ZN10NtfTexture7ReleaseEv
	ldr r0, _0216B6A0 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216B678
	beq _0216B670
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216B62C
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end ov0_0216B5EC
_0216B62C:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216B644
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216B644:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216B668
	ldr r3, _0216B6A4 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216B668:
	mov r0, r5
	bl _ZdlPv
_0216B670:
	mov r0, #0
	str r0, [r4, #0x18]
_0216B678:
	ldr r1, _0216B6A8 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216B6A0: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216B6A4: .word ov0_0216AD48
_0216B6A8: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216B6AC
ov0_0216B6AC: ; 0x0216B6AC
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x80
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	mov r4, r0
	str ip, [sp, #8]
	ldr r1, _0216B734 ; =DAT_overlay_0_0217a464
	ldr r2, _0216B738 ; =s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217a468
	add r0, sp, #0x14
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r1, _0216B73C ; =s_MEF_ef102_00_ntft_overlay_0_0217a488
	ldr r2, _0216B740 ; =s_MEF_ef102_00_ntfp_overlay_0_0217a49c
	add r0, r4, #0x8c
	mov r3, #0
	bl _ZN10NtfTexture4LoadEPKcS1_i
	mov r0, #6
	str r0, [r4, #0xa8]
	mov r0, #2
	str r0, [r4, #0xac]
	str r0, [r4, #0xb0]
	add r1, r4, #0x8c
	str r1, [sp, #0x10]
	mov r0, r4
	ldr r2, [r0]
	add r1, sp, #0x10
	ldr r2, [r2, #0x5c]
	blx r2
	add r0, sp, #0x14
	bl _ZN13CArchiveGuardD1Ev
	add sp, sp, #0x80
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216B734: .word DAT_overlay_0_0217a464
_0216B738: .word s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217a468
_0216B73C: .word s_MEF_ef102_00_ntft_overlay_0_0217a488
_0216B740: .word s_MEF_ef102_00_ntfp_overlay_0_0217a49c
	arm_func_end ov0_0216B6AC

	arm_func_start _ZN26CFieldEffectDarknessClear212sub_0203312CEii
_ZN26CFieldEffectDarknessClear212sub_0203312CEii: ; 0x0216B744
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #4
	mov r0, #1
	addls pc, pc, r1, lsl #2
	b _0216B798
_0216B764: ; jump table
	b _0216B798 ; case 0
	b _0216B9F8 ; case 1
	b _0216B9F8 ; case 2
	b _0216B778 ; case 3
	b _0216B788 ; case 4
	arm_func_end _ZN26CFieldEffectDarknessClear212sub_0203312CEii
_0216B778:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x58]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216B788:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x5c]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216B798:
	cmp r1, #0
	mov r0, #0
	beq _0216B7BC
	cmp r1, #1
	beq _0216B9D0
	cmp r1, #2
	beq _0216B9E8
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216B7BC:
	cmp r5, #0
	ble _0216B9C4
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _0216B838
	beq _0216B830
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0216B7EC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_0216B7EC:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0216B804
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_0216B804:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0216B828
	ldr r3, _0216BA00 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x20]
_0216B828:
	mov r0, r4
	bl _ZdlPv
_0216B830:
	mov r0, #0
	str r0, [r6, #0x18]
_0216B838:
	mov r0, #0x34
	bl _Znwm
	movs r4, r0
	beq _0216B968
	mov r0, #0x1000
	str r0, [r4, #8]
	mov r0, #1
	str r0, [r4, #0x14]
	mov r1, #0
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	str r5, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0216B90C
	ldr r1, _0216BA00 ; =ov0_0216AD48
	ldr r3, _0216BA04 ; =ov0_0216AD5C
	str r1, [sp]
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _0216B900
	mov r1, lr
	mov ip, lr
	mov r2, #0x84
_0216B8B4:
	ldr r3, [r4, #0x20]
	add r5, r0, #1
	add r3, r3, r1
	str lr, [r3, #0x7c]
	ldr r3, [r4, #0x24]
	add r0, r0, #1
	cmp r5, r3
	ldrlo r3, [r4, #0x20]
	mlalo lr, r5, r2, r3
	ldr r3, [r4, #0x20]
	movhs lr, ip
	add r3, r3, r1
	str lr, [r3, #0x80]
	ldr r5, [r4, #0x20]
	ldr r3, [r4, #0x24]
	add lr, r5, r1
	cmp r0, r3
	add r1, r1, #0x84
	blo _0216B8B4
_0216B900:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x2c]
	b _0216B914
_0216B90C:
	str r1, [r4, #0x20]
	str r1, [r4, #0x2c]
_0216B914:
	mov r1, #0
	str r1, [r4, #0x30]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _0216B95C
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x14]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x14]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x10]
_0216B95C:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_0216B968:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _0216B9C4
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0216B9A0
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0216B9A0:
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x60]
	blx r1
	ldr r1, [r6, #0x18]
	str r0, [r1, #0x1c]
	ldr r1, [r6, #0x1c]
	ldr r0, [r6, #0x18]
	str r1, [r0, #0x18]
_0216B9C4:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216B9D0:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216B9E8:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
_0216B9F8:
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0216BA00: .word ov0_0216AD48
_0216BA04: .word ov0_0216AD5C

	arm_func_start _ZN26CFieldEffectDarknessClear212ov0_021421F0Eiii
_ZN26CFieldEffectDarknessClear212ov0_021421F0Eiii: ; 0x0216BA08
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r3
	cmp r4, #0
	mov r6, r0
	mov r5, r2
	movle r4, #0xb4
	str r5, [r6, #0x6c]
	str r4, [r6, #0x70]
	mov r0, r5, lsl #0xc
	str r0, [r6, #0x24]
	ldr r1, [r6, #0x34]
	mov r0, r6
	str r1, [r6, #0x28]
	ldr r1, [r6, #0x38]
	str r1, [r6, #0x2c]
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	cmp r0, #0
	beq _0216BA64
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end _ZN26CFieldEffectDarknessClear212ov0_021421F0Eiii
_0216BA64:
	mov r0, r6
	mov r2, r5
	mov r3, r4
	mov r1, #0
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN26CFieldEffectDarknessClear212ov0_02142264Ei
_ZN26CFieldEffectDarknessClear212ov0_02142264Ei: ; 0x0216BA7C
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov r4, r0
	mov r2, #0
	strb r2, [r4, #0x87]
	mov r5, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	cmp r0, #4
	ldrne r8, [r4, #0x18]
	str r0, [sp]
	cmpne r8, #0
	beq _0216BD34
	ldr r0, [r8, #8]
	ldr r4, [r8, #0x28]
	mul r7, r5, r0
	cmp r4, #0
	beq _0216BBE0
	mov fp, #0
	mov r6, r7, asr #0x1f
	mov sb, fp
	arm_func_end _ZN26CFieldEffectDarknessClear212ov0_02142264Ei
_0216BACC:
	ldr r0, [r4, #0x70]
	ldr r5, [r4, #0x80]
	cmp r0, #0
	beq _0216BB90
	ldr r0, [r8, #0x1c]
	cmp r0, #0
	beq _0216BAFC
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, r7
	blx r3
_0216BAFC:
	ldr r0, [r4, #0x70]
	cmp r0, #0
	ble _0216BBD4
	ldr ip, [r4, #0x64]
	ldr r0, [r4, #0x68]
	umull r3, lr, ip, r7
	umull r2, r1, r0, r7
	mov sl, r3, lsr #0xc
	mla lr, ip, r6, lr
	mov r3, ip, asr #0x1f
	mla lr, r3, r7, lr
	orr sl, sl, lr, lsl #20
	mla r1, r0, r6, r1
	mov r3, r0, asr #0x1f
	ldr r0, [r4, #0x5c]
	mla r1, r3, r7, r1
	add r0, r0, sl
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	str r2, [sp, #8]
	add r0, r0, r2
	str r0, [r4, #0x60]
	ldrsh r0, [r4, #0x6e]
	str r2, [sp, #0x10]
	ldrsh r2, [r4, #0x6c]
	mul r1, r0, r7
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	str sl, [sp, #4]
	subs r0, r0, r7
	str r0, [r4, #0x70]
	str sl, [sp, #0xc]
	strmi sb, [r4, #0x70]
	b _0216BBD4
_0216BB90:
	cmp r4, #0
	beq _0216BBD4
	cmp r5, #0
	ldrne r0, [r4, #0x7c]
	strne r0, [r5, #0x7c]
	ldr r1, [r4, #0x7c]
	ldr r0, [r4, #0x80]
	cmp r1, #0
	strne r0, [r1, #0x80]
	streq r0, [r8, #0x28]
	ldr r0, [r8, #0x2c]
	str r0, [r4, #0x80]
	str fp, [r4, #0x7c]
	ldr r0, [r8, #0x2c]
	cmp r0, #0
	strne r4, [r0, #0x7c]
	str r4, [r8, #0x2c]
_0216BBD4:
	mov r4, r5
	cmp r5, #0
	bne _0216BACC
_0216BBE0:
	ldr r0, [r8, #0x14]
	mov r4, #0
	mov r5, r4
	cmp r0, #0
	bls _0216BC44
	mov r6, r4
_0216BBF8:
	ldr r0, [r8, #0xc]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [r8, #0x10]
	streq r6, [r0, r5, lsl #2]
	beq _0216BC34
	ldr r2, [r0]
	mov r1, r7
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [r8, #0x10]
	str r0, [r1, r5, lsl #2]
	ldr r0, [r8, #0x10]
	ldr r0, [r0, r5, lsl #2]
	add r4, r4, r0
_0216BC34:
	ldr r0, [r8, #0x14]
	add r5, r5, #1
	cmp r5, r0
	blo _0216BBF8
_0216BC44:
	cmp r4, #0
	beq _0216BD34
	cmp r0, #0
	mov r6, #0
	bls _0216BD34
_0216BC58:
	ldr r0, [r8, #0xc]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	ldrne r0, [r8, #0x10]
	ldrne r0, [r0, r6, lsl #2]
	cmpne r0, #0
	beq _0216BD24
	cmp r0, #0
	mov sb, #0
	bls _0216BD24
	mov r4, sb
	mov r5, sb
_0216BC88:
	ldr r1, [r8, #0x2c]
	mov sl, r5
	cmp r1, #0
	beq _0216BCC8
	ldr r0, [r1, #0x80]
	mov sl, r1
	str r0, [r8, #0x2c]
	cmp r0, #0
	strne r5, [r0, #0x7c]
	ldr r0, [r8, #0x28]
	str r0, [r1, #0x80]
	str r4, [r1, #0x7c]
	ldr r0, [r8, #0x28]
	cmp r0, #0
	strne r1, [r0, #0x7c]
	str r1, [r8, #0x28]
_0216BCC8:
	cmp sl, #0
	beq _0216BD10
	ldr r0, [r8, #0x18]
	mov r1, sl
	str r0, [sl, #0x18]
	ldr r0, [r8, #0xc]
	ldr r0, [r0, r6, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [r8, #0x1c]
	cmp r0, #0
	beq _0216BD10
	ldr r3, [r0]
	mov r1, sl
	ldr r3, [r3, #8]
	mov r2, r7
	blx r3
_0216BD10:
	ldr r0, [r8, #0x10]
	add sb, sb, #1
	ldr r0, [r0, r6, lsl #2]
	cmp sb, r0
	blo _0216BC88
_0216BD24:
	ldr r0, [r8, #0x14]
	add r6, r6, #1
	cmp r6, r0
	blo _0216BC58
_0216BD34:
	ldr r0, [sp]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142264Ei
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142264Ei: ; 0x0216BD40
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov r4, r0
	mov r5, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	cmp r0, #4
	ldrne r8, [r4, #0x18]
	str r0, [sp]
	cmpne r8, #0
	beq _0216BFF0
	ldr r0, [r8, #8]
	ldr r4, [r8, #0x28]
	mul r7, r5, r0
	cmp r4, #0
	beq _0216BE9C
	mov fp, #0
	mov r6, r7, asr #0x1f
	mov sb, fp
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142264Ei
_0216BD88:
	ldr r0, [r4, #0x70]
	ldr r5, [r4, #0x80]
	cmp r0, #0
	beq _0216BE4C
	ldr r0, [r8, #0x1c]
	cmp r0, #0
	beq _0216BDB8
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, r7
	blx r3
_0216BDB8:
	ldr r0, [r4, #0x70]
	cmp r0, #0
	ble _0216BE90
	ldr ip, [r4, #0x64]
	ldr r0, [r4, #0x68]
	umull r3, lr, ip, r7
	umull r2, r1, r0, r7
	mov sl, r3, lsr #0xc
	mla lr, ip, r6, lr
	mov r3, ip, asr #0x1f
	mla lr, r3, r7, lr
	orr sl, sl, lr, lsl #20
	mla r1, r0, r6, r1
	mov r3, r0, asr #0x1f
	ldr r0, [r4, #0x5c]
	mla r1, r3, r7, r1
	add r0, r0, sl
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	str r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	str r2, [sp, #0x10]
	add r0, r0, r2
	str r0, [r4, #0x60]
	ldrsh r0, [r4, #0x6e]
	str r2, [sp, #8]
	ldrsh r2, [r4, #0x6c]
	mul r1, r0, r7
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	str sl, [sp, #0xc]
	subs r0, r0, r7
	str r0, [r4, #0x70]
	str sl, [sp, #4]
	strmi sb, [r4, #0x70]
	b _0216BE90
_0216BE4C:
	cmp r4, #0
	beq _0216BE90
	cmp r5, #0
	ldrne r0, [r4, #0x7c]
	strne r0, [r5, #0x7c]
	ldr r1, [r4, #0x7c]
	ldr r0, [r4, #0x80]
	cmp r1, #0
	strne r0, [r1, #0x80]
	streq r0, [r8, #0x28]
	ldr r0, [r8, #0x2c]
	str r0, [r4, #0x80]
	str fp, [r4, #0x7c]
	ldr r0, [r8, #0x2c]
	cmp r0, #0
	strne r4, [r0, #0x7c]
	str r4, [r8, #0x2c]
_0216BE90:
	mov r4, r5
	cmp r5, #0
	bne _0216BD88
_0216BE9C:
	ldr r0, [r8, #0x14]
	mov r5, #0
	mov r4, r5
	cmp r0, #0
	bls _0216BF00
	mov r6, r5
_0216BEB4:
	ldr r0, [r8, #0xc]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	ldreq r0, [r8, #0x10]
	streq r6, [r0, r4, lsl #2]
	beq _0216BEF0
	ldr r2, [r0]
	mov r1, r7
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [r8, #0x10]
	str r0, [r1, r4, lsl #2]
	ldr r0, [r8, #0x10]
	ldr r0, [r0, r4, lsl #2]
	add r5, r5, r0
_0216BEF0:
	ldr r0, [r8, #0x14]
	add r4, r4, #1
	cmp r4, r0
	blo _0216BEB4
_0216BF00:
	cmp r5, #0
	beq _0216BFF0
	cmp r0, #0
	mov sl, #0
	bls _0216BFF0
_0216BF14:
	ldr r0, [r8, #0xc]
	ldr r0, [r0, sl, lsl #2]
	cmp r0, #0
	ldrne r0, [r8, #0x10]
	ldrne r0, [r0, sl, lsl #2]
	cmpne r0, #0
	beq _0216BFE0
	cmp r0, #0
	mov sb, #0
	bls _0216BFE0
	mov r4, sb
	mov r5, sb
_0216BF44:
	ldr r1, [r8, #0x2c]
	mov r6, r5
	cmp r1, #0
	beq _0216BF84
	ldr r0, [r1, #0x80]
	mov r6, r1
	str r0, [r8, #0x2c]
	cmp r0, #0
	strne r5, [r0, #0x7c]
	ldr r0, [r8, #0x28]
	str r0, [r1, #0x80]
	str r4, [r1, #0x7c]
	ldr r0, [r8, #0x28]
	cmp r0, #0
	strne r1, [r0, #0x7c]
	str r1, [r8, #0x28]
_0216BF84:
	cmp r6, #0
	beq _0216BFCC
	ldr r0, [r8, #0x18]
	mov r1, r6
	str r0, [r6, #0x18]
	ldr r0, [r8, #0xc]
	ldr r0, [r0, sl, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [r8, #0x1c]
	cmp r0, #0
	beq _0216BFCC
	ldr r3, [r0]
	mov r1, r6
	ldr r3, [r3, #8]
	mov r2, r7
	blx r3
_0216BFCC:
	ldr r0, [r8, #0x10]
	add sb, sb, #1
	ldr r0, [r0, sl, lsl #2]
	cmp sb, r0
	blo _0216BF44
_0216BFE0:
	ldr r0, [r8, #0x14]
	add sl, sl, #1
	cmp sl, r0
	blo _0216BF14
_0216BFF0:
	ldr r0, [sp]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov0_0216BFFC
ov0_0216BFFC: ; 0x0216BFFC
	mov r0, #0
	bx lr
	arm_func_end ov0_0216BFFC

	arm_func_start _ZN26CFieldEffectDarknessClear212ov0_02142344EP8Camera2D
_ZN26CFieldEffectDarknessClear212ov0_02142344EP8Camera2D: ; 0x0216C004
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, [r0, #0x18]
	mov r6, r1
	cmp r2, #0
	beq _0216C030
	ldr r1, [r6, #0x1c]
	rsb r1, r1, #0
	str r1, [r2]
	ldr r1, [r6, #0x20]
	rsb r1, r1, #0
	str r1, [r2, #4]
	arm_func_end _ZN26CFieldEffectDarknessClear212ov0_02142344EP8Camera2D
_0216C030:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	ldrne r4, [r5, #0x28]
	cmpne r4, #0
	beq _0216C098
_0216C044:
	ldr r0, [r5, #0x30]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x5c]
	ldr r1, [r5]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x3c]
	ldr r3, [r4, #0x60]
	ldr r2, [r5, #4]
	mov r1, r6
	add r2, r3, r2
	str r2, [r4, #0x40]
	ldrsh r2, [r4, #0x6c]
	strh r2, [r4, #0x54]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x80]
	cmp r4, #0
	bne _0216C044
_0216C098:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN26CFieldEffectDarknessClear211CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
_ZN26CFieldEffectDarknessClear211CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi: ; 0x0216C0A0
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x30
	mov r5, r1
	mov r7, r0
	ldr r2, [r5, #0x74]
	ldr r1, [r5, #0x70]
	ldr r0, [r7, #4]
	sub r4, r2, r1
	cmp r4, r0
	addlt sp, sp, #0x30
	ldmltia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	add r0, r0, #0x28
	str r0, [r5, #0x44]
	add r0, r1, #0x28
	str r0, [r5, #0x48]
	ldr r0, [r5, #0x70]
	ldr r2, [r5, #0x74]
	rsb r3, r0, r0, lsl #5
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	mov r0, r0, asr #0xc
	str r0, [r5, #0x14]
	ldr r6, [r5, #0x78]
	tst r6, #0x40000000
	bne _0216C258
	tst r6, #0x80000000
	beq _0216C1A8
	ldr r2, [r7, #0xc]
	ldr r0, [r5, #0x60]
	ldr r3, [r7, #8]
	sub r4, r0, r2
	ldr r0, [r5, #0x5c]
	mov r1, r4
	sub r0, r0, r3
	str r3, [sp, #0x18]
	str r2, [sp, #0x1c]
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r0, [sp, #0x28]
	str r4, [sp, #0x2c]
	bl _Z12ApproxLengthll
	mov r2, r0
	cmp r2, #0x1000
	movlt r0, #0x51
	blt _0216C17C
	mov r3, r2, asr #0x1f
	mov r0, #0x2000000
	mov r1, #0
	bl _ll_div
	arm_func_end _ZN26CFieldEffectDarknessClear211CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
_0216C17C:
	ldr r1, [sp, #0x28]
	smull r4, r3, r0, r4
	rsb r1, r1, #0
	smull r2, r1, r0, r1
	mov r4, r4, lsr #0xc
	orr r4, r4, r3, lsl #20
	mov r0, r2, lsr #0xc
	str r4, [r5, #0x64]
	orr r0, r0, r1, lsl #20
	str r0, [r5, #0x68]
	b _0216C248
_0216C1A8:
	ldr r0, [r5, #0x74]
	sub r4, r0, r4
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r0, r0, #0x1000
	add r1, r1, #0x1400
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, r7}
	umull sb, r8, r7, r3
	mla r8, r7, r2, r8
	ldr r2, [r1, #0xc]
	ldr r7, [r1, #0x10]
	mla r8, r2, r3, r8
	ldr r3, [r1, #0x14]
	adds r7, r7, sb
	str r7, [r0, #0x448]
	mov r2, #0
	adc r7, r3, r8
	mov r0, r2, lsl #7
	orr r0, r0, r7, lsr #25
	add r0, r0, #0x40
	mov r3, r0, lsl #0xc
	mov r0, r3, asr #0x1f
	str r7, [r1, #4]
	mov r1, r0, lsl #0xc
	mov r2, r4
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r4, asr #0x1f
	bl _ll_div
	ldr r1, [r5, #0x78]
	cmp r1, #0
	strne r0, [r5, #0x64]
	movne r0, #0
	strne r0, [r5, #0x68]
	bne _0216C248
	rsb r0, r0, #0
	str r0, [r5, #0x64]
	mov r0, #0
	str r0, [r5, #0x68]
_0216C248:
	orr r0, r6, #0x40000000
	add sp, sp, #0x30
	str r0, [r5, #0x78]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_0216C258:
	tst r6, #0x80000000
	addeq sp, sp, #0x30
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r2, [r7, #0xc]
	ldr r0, [r5, #0x60]
	ldr r3, [r7, #8]
	sub r4, r0, r2
	ldr r0, [r5, #0x5c]
	mov r1, r4
	sub r0, r0, r3
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	str r0, [sp]
	str r4, [sp, #4]
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	bl _Z12ApproxLengthll
	mov r2, r0
	cmp r2, #0x1000
	movlt r0, #0x51
	blt _0216C2BC
	mov r3, r2, asr #0x1f
	mov r0, #0x2000000
	mov r1, #0
	bl _ll_div
_0216C2BC:
	ldr r2, [sp, #0x20]
	mov r8, #0x28
	smull r7, r6, r0, r4
	umull lr, ip, r2, r8
	rsb r1, r2, #0
	mov r3, r2, asr #0x1f
	smull r2, r1, r0, r1
	umull sl, sb, r4, r8
	mov r4, r4, asr #0x1f
	mov r0, r7, lsr #0xc
	mov r7, r2, lsr #0xc
	mla ip, r3, r8, ip
	mov r3, lr, lsr #0xc
	mla sb, r4, r8, sb
	mov r2, sl, lsr #0xc
	orr r0, r0, r6, lsl #20
	orr r3, r3, ip, lsl #20
	add r0, r0, r3
	orr r7, r7, r1, lsl #20
	orr r2, r2, sb, lsl #20
	str r0, [r5, #0x64]
	add r0, r7, r2
	str r0, [r5, #0x68]
	add sp, sp, #0x30
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start _ZN26CFieldEffectDarknessClear28CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE
_ZN26CFieldEffectDarknessClear28CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE: ; 0x0216C320
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r5, r0
	ldrb r3, [r5, #0x57]
	ldr r2, _0216C580 ; =DAT_overlay_0_0217a368
	ldr r0, _0216C584 ; =DAT_overlay_0_0217a364
	ldr r2, [r2, r3, lsl #3]
	ldr r0, [r0, r3, lsl #3]
	mov r4, r1
	str r0, [r4, #0x5c]
	str r2, [r4, #0x60]
	ldrb r1, [r5, #0x57]
	mov r0, #0x20000
	rsb r0, r0, #0
	add r1, r1, #1
	strb r1, [r5, #0x57]
	ldr r1, [r4, #0x5c]
	cmp r1, r0
	movlt r1, #0
	blt _0216C3CC
	cmp r1, #0x20000
	movgt r1, #1
	bgt _0216C3CC
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r6, [r0, #0x448]
	ldmib r1, {r3, r7}
	umull ip, r8, r7, r6
	mla r8, r7, r3, r8
	ldr r3, [r1, #0xc]
	ldr lr, [r1, #0x10]
	mla r8, r3, r6, r8
	ldr r7, [r1, #0x14]
	adds ip, lr, ip
	mov r2, #0
	str ip, [r0, #0x448]
	adc r3, r7, r8
	mov r0, r2, lsl #1
	str r3, [r1, #4]
	orrs r0, r0, r3, lsr #31
	movne r1, r2
	moveq r1, #1
	arm_func_end _ZN26CFieldEffectDarknessClear28CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE
_0216C3CC:
	ldrb r0, [r5, #0x58]
	cmp r0, #0x10
	subhs r0, r0, #0x10
	strlo r1, [r4, #0x78]
	orrhs r0, r0, #0x80000000
	strhs r0, [r4, #0x78]
	mov r0, #0
	str r0, [r4, #0x64]
	str r0, [r4, #0x68]
	ldr r1, [r5, #0x40]
	ldr r0, [r5, #0x3c]
	sub r0, r1, r0
	add r6, r0, #1
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, r7}
	umull ip, r8, r7, r3
	mla r8, r7, r2, r8
	ldr r2, [r1, #0xc]
	ldr lr, [r1, #0x10]
	mla r8, r2, r3, r8
	ldr r7, [r1, #0x14]
	adds ip, lr, ip
	adc r2, r7, r8
	str ip, [r0, #0x448]
	str r2, [r1, #4]
	cmp r6, #0
	ldreq r2, [r1, #4]
	ldrne r0, [r1, #4]
	umullne r1, r2, r0, r6
	ldr r1, [r5, #0x3c]
	mov r0, #0x1f
	add r1, r1, r2
	mov r1, r1, lsl #0xc
	str r1, [r4, #0x70]
	str r1, [r4, #0x74]
	mov r1, #0
	strh r1, [r4, #8]
	str r0, [r4, #0x14]
	sub r0, r0, #0x20
	str r0, [r4, #4]
	strh r1, [r4, #0x6e]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	mov r0, #0x20000
	str r0, [r4, #0x34]
	str r0, [r4, #0x38]
	str r0, [r4, #0x4c]
	str r0, [r4, #0x50]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, r6}
	umull r8, r7, r6, r3
	mla r7, r6, r2, r7
	ldr r2, [r1, #0xc]
	ldr ip, [r1, #0x10]
	mla r7, r2, r3, r7
	ldr r6, [r1, #0x14]
	adds r8, ip, r8
	str r8, [r0, #0x448]
	adc r3, r6, r7
	ldr r0, _0216C588 ; =0x00000C01
	str r3, [r1, #4]
	umull r0, r2, r3, r0
	add r6, r2, #0x1800
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, ip}
	umull r7, lr, ip, r3
	mla lr, ip, r2, lr
	ldr r2, [r1, #0xc]
	ldr r8, [r1, #0x10]
	mla lr, r2, r3, lr
	adds r8, r8, r7
	ldr r7, [r1, #0x14]
	str r8, [r0, #0x448]
	adc r7, r7, lr
	ldr r0, _0216C58C ; =0x00000801
	str r7, [r1, #4]
	umull r0, r2, r7, r0
	add r0, r2, #0x1800
	umull ip, r3, r6, r0
	mov r2, r6, asr #0x1f
	mla r3, r2, r0, r3
	mov r0, ip, lsr #0xc
	orr r0, r0, r3, lsl #20
	str r0, [r4, #0x44]
	str r6, [r4, #0x48]
	ldrb r0, [r5, #0x55]
	add r0, r0, #8
	str r0, [r4, #0x10]
	ldrb r0, [r5, #0x55]
	add r1, r0, #1
	and r0, r1, #0xff
	and r0, r0, #0x1f
	strb r0, [r5, #0x55]
	ldrb r0, [r5, #0x58]
	add r0, r0, #1
	strb r0, [r5, #0x58]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0216C580: .word DAT_overlay_0_0217a368
_0216C584: .word DAT_overlay_0_0217a364
_0216C588: .word 0x00000C01
_0216C58C: .word 0x00000801

	arm_func_start _ZN32CFieldEffectDarknessClearFactory6CreateEi
_ZN32CFieldEffectDarknessClearFactory6CreateEi: ; 0x0216C590
	stmdb sp!, {r4, lr}
	movs r4, r1
	bne _0216C5B8
	mov r0, #0xac
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r1, r4
	bl ov0_0216A448
	ldmia sp!, {r4, pc}
	arm_func_end _ZN32CFieldEffectDarknessClearFactory6CreateEi
_0216C5B8:
	mov r0, #0xb8
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r1, r4
	bl ov0_0216B39C
	ldmia sp!, {r4, pc}

	arm_func_start _ZN26CFieldEffectDarknessClear210GetEmitterEv
_ZN26CFieldEffectDarknessClear210GetEmitterEv: ; 0x0216C5D4
	add r0, r0, #0x30
	bx lr
	arm_func_end _ZN26CFieldEffectDarknessClear210GetEmitterEv

	arm_func_start _ZN26CFieldEffectDarknessClear213GetForceFieldEv
_ZN26CFieldEffectDarknessClear213GetForceFieldEv: ; 0x0216C5DC
	add r0, r0, #0x20
	bx lr
	arm_func_end _ZN26CFieldEffectDarknessClear213GetForceFieldEv

	arm_func_start _ZN26CFieldEffectDarknessClear212sub_02033028Ev
_ZN26CFieldEffectDarknessClear212sub_02033028Ev: ; 0x0216C5E4
	mov r0, #0x17
	bx lr
	arm_func_end _ZN26CFieldEffectDarknessClear212sub_02033028Ev

	arm_func_start _ZN25CFieldEffectDarknessClear10GetEmitterEv
_ZN25CFieldEffectDarknessClear10GetEmitterEv: ; 0x0216C5EC
	add r0, r0, #0x28
	bx lr
	arm_func_end _ZN25CFieldEffectDarknessClear10GetEmitterEv

	arm_func_start _ZN25CFieldEffectDarknessClear13GetForceFieldEv
_ZN25CFieldEffectDarknessClear13GetForceFieldEv: ; 0x0216C5F4
	add r0, r0, #0x20
	bx lr
	arm_func_end _ZN25CFieldEffectDarknessClear13GetForceFieldEv

	arm_func_start _ZN25CFieldEffectDarknessClear11GetEffectIdEv
_ZN25CFieldEffectDarknessClear11GetEffectIdEv: ; 0x0216C5FC
	mov r0, #0x17
	bx lr
	arm_func_end _ZN25CFieldEffectDarknessClear11GetEffectIdEv

	arm_func_start _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE5func2Ev
_ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE5func2Ev: ; 0x0216C604
	mov r1, #0x1000
	str r1, [r0, #0x30]
	bx lr
	arm_func_end _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE5func2Ev

	arm_func_start _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4StopEv
_ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4StopEv: ; 0x0216C610
	mov r1, #0
	str r1, [r0, #0x30]
	bx lr
	arm_func_end _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4StopEv

	arm_func_start _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE6UpdateEi
_ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE6UpdateEi: ; 0x0216C61C
	ldr r2, [r0, #0x30]
	mov r3, #0
	cmp r2, #0
	ble _0216C650
	sub r1, r2, r1
	str r1, [r0, #0x30]
	cmp r1, #0
	bgt _0216C650
	ldr r1, [r0, #0x34]
	ldr r3, [r0, #0x44]
	cmp r1, #0
	movgt r1, r1, lsl #0xc
	strgt r1, [r0, #0x30]
	arm_func_end _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE6UpdateEi
_0216C650:
	mov r0, r3
	bx lr

	arm_func_start ov0_0216C658
ov0_0216C658: ; 0x0216C658
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216C658

	arm_func_start ov0_0216C66C
ov0_0216C66C: ; 0x0216C66C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216C66C

	arm_func_start ov0_0216C680
ov0_0216C680: ; 0x0216C680
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216C680

	arm_func_start ov0_0216C694
ov0_0216C694: ; 0x0216C694
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216C694

	arm_func_start ov0_0216C6A8
ov0_0216C6A8: ; 0x0216C6A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216C6A8

	arm_func_start ov0_0216C6BC
ov0_0216C6BC: ; 0x0216C6BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216C6BC

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFED0Ev
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFED0Ev: ; 0x0216C6D0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216C77C ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216C754
	beq _0216C74C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216C708
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFED0Ev
_0216C708:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216C720
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216C720:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216C744
	ldr r3, _0216C780 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216C744:
	mov r0, r5
	bl _ZdlPv
_0216C74C:
	mov r0, #0
	str r0, [r4, #0x18]
_0216C754:
	ldr r1, _0216C784 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216C77C: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216C780: .word ov0_0216AD48
_0216C784: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4EmitEP14TFieldParticleIS0_E
_ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4EmitEP14TFieldParticleIS0_E: ; 0x0216C788
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r7, r0
	mov r6, r1
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr r8, [r2, #0x448]
	ldmib r1, {r3, sb}
	umull fp, sl, sb, r8
	mla sl, sb, r3, sl
	ldr r3, [r1, #0xc]
	ldr ip, [r1, #0x10]
	mla sl, r3, r8, sl
	adds sb, ip, fp
	ldr r3, [r1, #0x14]
	ldr fp, [r7, #0x40]
	ldr r8, [r7, #0x3c]
	adc r3, r3, sl
	str sb, [r2, #0x448]
	sub r2, fp, r8
	str r3, [r1, #4]
	adds r2, r2, #1
	ldreq sl, [r1, #4]
	ldrne r1, [r1, #4]
	ldr r8, _0216CA90 ; =MAIN_BSS_0210CEC8
	umullne r2, sl, r1, r2
	ldmia r8, {r1, r2, r3}
	ldr sb, [r7, #0x3c]
	mla r1, r2, r1, r3
	add lr, sb, sl
	mla sl, r2, r1, r3
	ldr ip, [r7, #0x28]
	mov r2, r1, lsr #0x10
	str r1, [r8]
	ldr r1, [r7, #0x2c]
	ldr r3, _0216CA94 ; =0x00007FFF
	mov r2, r2, lsl #0x10
	mov sb, sl, lsr #0x10
	and fp, r3, r2, lsr #16
	mov r2, sb, lsl #0x10
	str sl, [r8]
	and r8, r3, r2, lsr #16
	mov sb, fp, asr #3
	smull r3, r2, sb, ip
	mov r8, r8, asr #3
	adds r3, r3, #0x800
	adc fp, r2, #0
	smull sl, sb, r8, r1
	adds r8, sl, #0x800
	mov r2, r3, lsr #0xc
	orr r2, r2, fp, lsl #20
	adc r3, sb, #0
	mov r8, r8, lsr #0xc
	orr r8, r8, r3, lsl #20
	sub sl, r2, ip, asr #1
	ldmib r7, {r3, sb}
	sub r2, r8, r1, asr #1
	add r1, r3, sl
	str r1, [r6, #0x5c]
	add r1, sb, r2
	str r1, [r6, #0x60]
	mov r1, lr, lsl #0xc
	str r1, [r6, #0x70]
	str r1, [r6, #0x74]
	ldrb r2, [r7, #0x54]
	add r1, r2, #1
	strb r1, [r7, #0x54]
	add r1, r2, #8
	str r1, [r6, #0x10]
	ldrb r1, [r7, #0x54]
	and r1, r1, #0x1f
	strb r1, [r7, #0x54]
	ldr r1, [r7, #0x48]
	cmp r1, #0
	beq _0216C8C0
	cmp r1, #1
	b _0216C8CC
	arm_func_end _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4EmitEP14TFieldParticleIS0_E
_0216C8C0:
	ldr r1, _0216CA98 ; =0x0000439C
	strh r1, [r6, #8]
	b _0216C8D4
_0216C8CC:
	ldr r1, _0216CA94 ; =0x00007FFF
	strh r1, [r6, #8]
_0216C8D4:
	ldr r1, [r7, #0x38]
	cmp r1, #1
	beq _0216CA20
	cmp r1, #2
	beq _0216C8F4
	cmp r1, #3
	beq _0216CA2C
	b _0216CA20
_0216C8F4:
	ldr r1, [r6, #0x5c]
	cmp r1, #0
	bne _0216C978
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr r7, [r2, #0x448]
	ldmib r1, {r3, r8}
	umull lr, ip, r8, r7
	mla ip, r8, r3, ip
	ldr r3, [r1, #0xc]
	ldr r8, [r1, #0x10]
	mla ip, r3, r7, ip
	ldr r3, [r1, #0x14]
	adds r7, r8, lr
	str r7, [r2, #0x448]
	adc r8, r3, ip
	mov r2, #3
	umull r3, r7, r8, r2
	mov r3, #0
	str r8, [r1, #4]
	mlas r7, r3, r2, r7
	mov r1, r3
	beq _0216C968
	cmp r7, #1
	beq _0216C970
	cmp r7, #2
	subeq r5, r1, #0x1000
	b _0216C984
_0216C968:
	mov r5, r1
	b _0216C984
_0216C970:
	mov r5, #0x1000
	b _0216C984
_0216C978:
	mov r5, #0x1000
	cmp r1, #0
	rsblt r5, r5, #0
_0216C984:
	ldr r1, [r6, #0x60]
	cmp r1, #0
	bne _0216CA10
	add r1, r0, #0x48
	add r0, r0, #0x1000
	add r1, r1, #0x1400
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, r7}
	umull ip, r8, r7, r3
	mla r8, r7, r2, r8
	ldr r2, [r1, #0xc]
	ldr r7, [r1, #0x10]
	mla r8, r2, r3, r8
	ldr r2, [r1, #0x14]
	adds r3, r7, ip
	str r3, [r0, #0x448]
	adc r7, r2, r8
	mov r0, #3
	umull r2, r3, r7, r0
	mov r2, #0
	mlas r3, r2, r0, r3
	str r7, [r1, #4]
	mov r0, r2
	beq _0216C9F8
	cmp r3, #1
	beq _0216CA08
	cmp r3, #2
	subeq r4, r0, #0x1000
	b _0216CA7C
_0216C9F8:
	cmp r5, #0
	moveq r4, #0x1000
	movne r4, r0
	b _0216CA7C
_0216CA08:
	mov r4, #0x1000
	b _0216CA7C
_0216CA10:
	mov r5, #0x800
	cmp r1, #0
	rsblt r5, r5, #0
	b _0216CA7C
_0216CA20:
	ldr r5, [r7, #0x4c]
	ldr r4, [r7, #0x50]
	b _0216CA7C
_0216CA2C:
	add r1, r0, #0x48
	add r0, r0, #0x1000
	add r1, r1, #0x1400
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, r4}
	umull r8, r5, r4, r3
	mla r5, r4, r2, r5
	ldr r2, [r1, #0xc]
	ldr r4, [r1, #0x10]
	mla r5, r2, r3, r5
	ldr r2, [r1, #0x14]
	adds r3, r4, r8
	str r3, [r0, #0x448]
	adc r2, r2, r5
	str r2, [r1, #4]
	ldr r0, _0216CA9C ; =0x00000333
	ldr r4, [r7, #0x50]
	umull r0, r1, r2, r0
	mvn r0, #0x198
	add r5, r1, r0
_0216CA7C:
	str r5, [r6, #0x64]
	str r4, [r6, #0x68]
	mov r0, #0
	strh r0, [r6, #0x6e]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0216CA90: .word MAIN_BSS_0210CEC8
_0216CA94: .word 0x00007FFF
_0216CA98: .word 0x0000439C
_0216CA9C: .word 0x00000333

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFED1Ev
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFED1Ev: ; 0x0216CAA0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216CB44 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216CB24
	beq _0216CB1C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216CAD8
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFED1Ev
_0216CAD8:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216CAF0
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216CAF0:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216CB14
	ldr r3, _0216CB48 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216CB14:
	mov r0, r5
	bl _ZdlPv
_0216CB1C:
	mov r0, #0
	str r0, [r4, #0x18]
_0216CB24:
	ldr r1, _0216CB4C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216CB44: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216CB48: .word ov0_0216AD48
_0216CB4C: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216CB50
ov0_0216CB50: ; 0x0216CB50
	bx lr
	arm_func_end ov0_0216CB50

	arm_func_start _ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED0Ev
_ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED0Ev: ; 0x0216CB54
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED0Ev

	arm_func_start _ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED1Ev
_ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED1Ev: ; 0x0216CB68
	bx lr
	arm_func_end _ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED1Ev

	arm_func_start _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED0Ev
_ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED0Ev: ; 0x0216CB6C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED0Ev

	arm_func_start _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED1Ev
_ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED1Ev: ; 0x0216CB80
	bx lr
	arm_func_end _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED1Ev

	arm_func_start _ZN22CFieldEffectAirBubblesC1Ev
_ZN22CFieldEffectAirBubblesC1Ev: ; 0x0216CB84
	stmdb sp!, {r4, lr}
	ldr r1, _0216CC2C ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _0216CC30 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r3, #0
	str r0, [r4]
	str r3, [r4, #0x1c]
	str r3, [r4, #0x20]
	ldr r0, _0216CC34 ; =ptr_FUN_overlay_0_0216cc50_overlay_0_0217a584
	str r3, [r4, #0x24]
	ldr r2, _0216CC38 ; =PTR_LAB_overlay_0_0216cc48_overlay_0_0217a4dc
	str r0, [r4]
	mov r1, #0x1000
	ldr r0, _0216CC3C ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r2, [r4, #0x28]
	str r0, [r4, #0x2c]
	str r3, [r4, #0x40]
	str r3, [r4, #0x30]
	str r3, [r4, #0x34]
	str r3, [r4, #0x38]
	ldr r0, _0216CC40 ; =_ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
	str r1, [r4, #0x3c]
	str r0, [r4, #0x2c]
	str r3, [r4, #0x54]
	str r3, [r4, #0x58]
	str r1, [r4, #0x44]
	str r3, [r4, #0x48]
	str r3, [r4, #0x4c]
	sub r1, r1, #0x2000
	ldr r0, _0216CC44 ; =PTR_LAB_overlay_0_0216cc4c_overlay_0_0217a50c
	str r1, [r4, #0x50]
	str r0, [r4, #0x2c]
	str r3, [r4, #0x64]
	str r3, [r4, #0x68]
	mov r1, #0xa000
	mov r0, r4
	str r1, [r4, #0x54]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216CC2C: .word _ZTV12CFieldEffect+8
_0216CC30: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0216CC34: .word ptr_FUN_overlay_0_0216cc50_overlay_0_0217a584
_0216CC38: .word PTR_LAB_overlay_0_0216cc48_overlay_0_0217a4dc
_0216CC3C: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_0216CC40: .word _ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
_0216CC44: .word PTR_LAB_overlay_0_0216cc4c_overlay_0_0217a50c
	arm_func_end _ZN22CFieldEffectAirBubblesC1Ev

	arm_func_start _ZN22CFieldEffectAirBubbles17CBubbleForceFieldD1Ev
_ZN22CFieldEffectAirBubbles17CBubbleForceFieldD1Ev: ; 0x0216CC48
	bx lr
	arm_func_end _ZN22CFieldEffectAirBubbles17CBubbleForceFieldD1Ev

	arm_func_start _ZN22CFieldEffectAirBubbles14CBubbleEmitterD1Ev
_ZN22CFieldEffectAirBubbles14CBubbleEmitterD1Ev: ; 0x0216CC4C
	bx lr
	arm_func_end _ZN22CFieldEffectAirBubbles14CBubbleEmitterD1Ev

	arm_func_start _ZN22CFieldEffectAirBubblesD1Ev
_ZN22CFieldEffectAirBubblesD1Ev: ; 0x0216CC50
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216CCF4 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216CCD4
	beq _0216CCCC
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216CC88
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN22CFieldEffectAirBubblesD1Ev
_0216CC88:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216CCA0
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216CCA0:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _0216CCC4
	ldr r3, _0216CCF8 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_0216CCC4:
	mov r0, r5
	bl _ZdlPv
_0216CCCC:
	mov r0, #0
	str r0, [r4, #0x18]
_0216CCD4:
	ldr r1, _0216CCFC ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216CCF4: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0216CCF8: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0216CCFC: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216CD00
ov0_0216CD00: ; 0x0216CD00
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216CDAC ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216CD84
	beq _0216CD7C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216CD38
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end ov0_0216CD00
_0216CD38:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216CD50
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216CD50:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _0216CD74
	ldr r3, _0216CDB0 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_0216CD74:
	mov r0, r5
	bl _ZdlPv
_0216CD7C:
	mov r0, #0
	str r0, [r4, #0x18]
_0216CD84:
	ldr r1, _0216CDB4 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216CDAC: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0216CDB0: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0216CDB4: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN22CFieldEffectAirBubbles8SetParamEii
_ZN22CFieldEffectAirBubbles8SetParamEii: ; 0x0216CDB8
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #0
	mov r0, #0
	beq _0216CDEC
	cmp r1, #1
	beq _0216D018
	cmp r1, #2
	beq _0216D030
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	arm_func_end _ZN22CFieldEffectAirBubbles8SetParamEii
_0216CDEC:
	cmp r5, #0
	ble _0216D00C
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _0216CE68
	beq _0216CE60
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0216CE1C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_0216CE1C:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0216CE34
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_0216CE34:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _0216CE58
	ldr r3, _0216D048 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x28]
_0216CE58:
	mov r0, r4
	bl _ZdlPv
_0216CE60:
	mov r0, #0
	str r0, [r6, #0x18]
_0216CE68:
	mov r0, #0x3c
	bl _Znwm
	movs r4, r0
	beq _0216CFA0
	mov r0, #0x1000
	str r0, [r4, #8]
	mov r0, #1
	str r0, [r4, #0x14]
	mov r1, #0
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	str r1, [r4, #0x20]
	str r1, [r4, #0x24]
	str r5, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0216CF44
	ldr r1, _0216D048 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _0216D04C ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _0216CF38
	mov r1, lr
	mov ip, lr
	mov r2, #0x74
_0216CEEC:
	ldr r3, [r4, #0x28]
	add r5, r0, #1
	add r3, r3, r1
	str lr, [r3, #0x6c]
	ldr r3, [r4, #0x2c]
	add r0, r0, #1
	cmp r5, r3
	ldrlo r3, [r4, #0x28]
	mlalo lr, r5, r2, r3
	ldr r3, [r4, #0x28]
	movhs lr, ip
	add r3, r3, r1
	str lr, [r3, #0x70]
	ldr r5, [r4, #0x28]
	ldr r3, [r4, #0x2c]
	add lr, r5, r1
	cmp r0, r3
	add r1, r1, #0x74
	blo _0216CEEC
_0216CF38:
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x34]
	b _0216CF4C
_0216CF44:
	str r1, [r4, #0x28]
	str r1, [r4, #0x34]
_0216CF4C:
	mov r1, #0
	str r1, [r4, #0x38]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _0216CF94
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x14]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x14]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x10]
_0216CF94:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_0216CFA0:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _0216D00C
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0216CFD8
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0216CFD8:
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x60]
	blx r1
	ldr r1, [r6, #0x18]
	str r0, [r1, #0x24]
	ldr r1, [r6, #0x18]
	ldr r0, [r6, #0x1c]
	str r0, [r1, #0x18]
	ldr r0, [r6, #0x20]
	str r0, [r1, #0x1c]
	ldr r0, [r6, #0x24]
	str r0, [r1, #0x20]
_0216D00C:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216D018:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216D030:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0216D048: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0216D04C: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev

	arm_func_start _ZN22CFieldEffectAirBubbles12ov0_0216D050Ell
_ZN22CFieldEffectAirBubbles12ov0_0216D050Ell: ; 0x0216D050
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r7, r0
	mov r6, r1
	mov r4, r2
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add sl, r1, #0x1400
	add fp, r0, #0x1000
	mov r2, r4
	ldr r5, [sl, #8]
	ldr lr, [fp, #0x448]
	ldr ip, [sl, #4]
	add r0, r7, #0x2c
	mov r1, r6
	umull r7, r6, r5, lr
	mov r3, #0
	mla r6, r5, ip, r6
	ldr r4, [sl, #0xc]
	ldr sb, [sl, #0x10]
	mla r6, r4, lr, r6
	ldr r8, [sl, #0x14]
	adds r4, sb, r7
	str r4, [fp, #0x448]
	adc r4, r8, r6
	mov r3, r3, lsl #1
	orr r3, r3, r4, lsr #31
	add r3, r3, #2
	str r4, [sl, #4]
	bl ov0_0216D12C
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	arm_func_end _ZN22CFieldEffectAirBubbles12ov0_0216D050Ell

	arm_func_start _ZN22CFieldEffectAirBubbles17CBubbleForceField5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN22CFieldEffectAirBubbles17CBubbleForceField5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x0216D0CC
	ldr r3, [r1, #0x64]
	ldr r2, [r1, #0x60]
	ldr r0, _0216D124 ; =0x00000CCC
	sub r2, r3, r2
	umull ip, r3, r2, r0
	mov r2, r2, asr #0x1f
	mla r3, r2, r0, r3
	mov r0, ip, lsr #0xc
	orr r0, r0, r3, lsl #20
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r0, r0, lsl #1
	add r3, r0, #1
	mov r0, #0
	ldr r2, _0216D128 ; =FX_SinCosTable_
	mov r3, r3, lsl #1
	ldrsh r2, [r2, r3]
	sub r0, r0, #0x1000
	str r2, [r1, #0x54]
	str r0, [r1, #0x58]
	bx lr
	.align 2, 0
_0216D124: .word 0x00000CCC
_0216D128: .word FX_SinCosTable_
	arm_func_end _ZN22CFieldEffectAirBubbles17CBubbleForceField5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

	arm_func_start ov0_0216D12C
ov0_0216D12C: ; 0x0216D12C
	str r1, [r0, #0x30]
	str r2, [r0, #0x34]
	ldr r2, [r0, #0x30]
	mov r1, #1
	str r2, [r0, #4]
	ldr r2, [r0, #0x34]
	str r2, [r0, #8]
	str r3, [r0, #0x38]
	str r1, [r0, #0x3c]
	bx lr
	arm_func_end ov0_0216D12C

	arm_func_start _ZN22CFieldEffectAirBubbles14CBubbleEmitter6UpdateEi
_ZN22CFieldEffectAirBubbles14CBubbleEmitter6UpdateEi: ; 0x0216D154
	ldr r1, [r0, #0x38]
	cmp r1, #0
	ble _0216D190
	ldr r1, [r0, #0x3c]
	sub r1, r1, #1
	str r1, [r0, #0x3c]
	cmp r1, #0
	bgt _0216D190
	ldr r2, [r0, #0x38]
	mov r1, #5
	sub r2, r2, #1
	str r2, [r0, #0x38]
	str r1, [r0, #0x3c]
	mov r0, #1
	bx lr
	arm_func_end _ZN22CFieldEffectAirBubbles14CBubbleEmitter6UpdateEi
_0216D190:
	mov r0, #0
	bx lr

	arm_func_start _ZN22CFieldEffectAirBubbles14CBubbleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN22CFieldEffectAirBubbles14CBubbleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x0216D198
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r4, _0216D28C ; =MAIN_BSS_0210CEC8
	ldr ip, [r0, #0x28]
	ldmia r4, {r2, r5, r6}
	mla r7, r5, r2, r6
	mla r6, r5, r7, r6
	mov r2, r7, lsr #0x10
	ldr r3, _0216D290 ; =0x00007FFF
	mov r2, r2, lsl #0x10
	str r7, [r4]
	and r7, r3, r2, lsr #16
	mov r5, r6, lsr #0x10
	mov r2, r5, lsl #0x10
	and r5, r3, r2, lsr #16
	ldr r2, [r0, #0x2c]
	mov r7, r7, asr #3
	smull r3, lr, r7, ip
	str r6, [r4]
	mov r4, r5, asr #3
	adds r3, r3, #0x800
	smull r6, r5, r4, r2
	adc r7, lr, #0
	adds r4, r6, #0x800
	mov r6, r3, lsr #0xc
	orr r6, r6, r7, lsl #20
	adc r3, r5, #0
	mov r4, r4, lsr #0xc
	orr r4, r4, r3, lsl #20
	sub r2, r4, r2, asr #1
	sub r6, r6, ip, asr #1
	ldmib r0, {r3, r5}
	mov r4, r1
	add r0, r3, r6
	str r0, [r4, #0x4c]
	add r0, r5, r2
	str r0, [r4, #0x50]
	mov r0, #0x78000
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr ip, [r0, #0x448]
	ldmib r1, {r3, lr}
	umull r6, r5, lr, ip
	mla r5, lr, r3, r5
	ldr r3, [r1, #0xc]
	ldr r7, [r1, #0x10]
	mla r5, r3, ip, r5
	ldr lr, [r1, #0x14]
	adds r3, r7, r6
	mov r2, #3
	adc r5, lr, r5
	str r3, [r0, #0x448]
	umull r0, r3, r5, r2
	str r5, [r1, #4]
	strh r3, [r4, #0x2a]
	sub r0, r2, #4
	str r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0216D28C: .word MAIN_BSS_0210CEC8
_0216D290: .word 0x00007FFF
	arm_func_end _ZN22CFieldEffectAirBubbles14CBubbleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

	arm_func_start _ZN22CFieldEffectAirBubbles10GetEmitterEv
_ZN22CFieldEffectAirBubbles10GetEmitterEv: ; 0x0216D294
	add r0, r0, #0x2c
	bx lr
	arm_func_end _ZN22CFieldEffectAirBubbles10GetEmitterEv

	arm_func_start _ZN22CFieldEffectAirBubbles13GetForceFieldEv
_ZN22CFieldEffectAirBubbles13GetForceFieldEv: ; 0x0216D29C
	add r0, r0, #0x28
	bx lr
	arm_func_end _ZN22CFieldEffectAirBubbles13GetForceFieldEv

	arm_func_start _ZN22CFieldEffectAirBubbles11GetEffectIdEv
_ZN22CFieldEffectAirBubbles11GetEffectIdEv: ; 0x0216D2A4
	mov r0, #0x28
	bx lr
	arm_func_end _ZN22CFieldEffectAirBubbles11GetEffectIdEv

	arm_func_start ov0_0216D2AC
ov0_0216D2AC: ; 0x0216D2AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216D2AC

	arm_func_start ov0_0216D2C0
ov0_0216D2C0: ; 0x0216D2C0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216D2C0

	arm_func_start _ZN14ManpuBlockHeapC1Ev
_ZN14ManpuBlockHeapC1Ev: ; 0x0216D2D4
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	bx lr
	arm_func_end _ZN14ManpuBlockHeapC1Ev

	arm_func_start _ZN14ManpuBlockHeap5AllocEm
_ZN14ManpuBlockHeap5AllocEm: ; 0x0216D2E4
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r2, #0
	add r1, r1, #0xff
	ldr r8, [r0]
	mov lr, #1
	mov r6, r1, lsr #8
	mov r3, r2
	mov r5, r2
	mov r1, lr
	arm_func_end _ZN14ManpuBlockHeap5AllocEm
_0216D308:
	tst r8, r1, lsl r3
	bne _0216D3BC
	cmp r6, #1
	bne _0216D340
	ldr r2, [r0]
	add r5, r0, #8
	orr r2, r2, r1, lsl r3
	str r2, [r0]
	mvn r1, r1, lsl r3
	ldr r4, [r0, #4]
	add r2, r5, r3, lsl #8
	and r1, r4, r1
	str r1, [r0, #4]
	b _0216D3C8
_0216D340:
	add r4, r3, r6
	cmp r4, #0x20
	bhi _0216D3C8
	mov ip, r5
	mov r7, r1
	cmp r6, #1
	bls _0216D378
_0216D35C:
	add r4, r3, r7
	tst r8, lr, lsl r4
	bne _0216D378
	add r7, r7, #1
	cmp r7, r6
	orr ip, ip, lr, lsl r4
	blo _0216D35C
_0216D378:
	cmp r7, r6
	blo _0216D3B0
	orr r2, ip, r1, lsl r3
	ldr lr, [r0]
	mvn r1, r1, lsl r3
	orr r2, lr, r2
	str r2, [r0]
	ldr lr, [r0, #4]
	add r4, r0, #8
	and r1, lr, r1
	orr r1, r1, ip
	add r2, r4, r3, lsl #8
	str r1, [r0, #4]
	b _0216D3C8
_0216D3B0:
	add ip, r7, #1
	add r3, r3, ip
	b _0216D3C0
_0216D3BC:
	add r3, r3, #1
_0216D3C0:
	cmp r3, #0x20
	blt _0216D308
_0216D3C8:
	mov r0, r2
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start _ZN14ManpuBlockHeap4FreeEPv
_ZN14ManpuBlockHeap4FreeEPv: ; 0x0216D3D0
	add r2, r0, #8
	sub r1, r1, r2
	mov r1, r1, asr #8
	mov r2, #1
	movs ip, r2, lsl r1
	bxeq lr
	mov r1, #0
	arm_func_end _ZN14ManpuBlockHeap4FreeEPv
_0216D3EC:
	ldr r2, [r0]
	mvn r3, ip
	and r2, r2, r3
	str r2, [r0]
	ldr r2, [r0, #4]
	mov ip, ip, lsl #1
	and r2, r2, r3
	tst r2, ip
	moveq ip, r1
	str r2, [r0, #4]
	cmp ip, #0
	bne _0216D3EC
	bx lr

	arm_func_start _ZN12AnimSlotPoolC1Ev
_ZN12AnimSlotPoolC1Ev: ; 0x0216D420
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	bx lr
	arm_func_end _ZN12AnimSlotPoolC1Ev

	arm_func_start _ZN12AnimSlotPoolD1Ev
_ZN12AnimSlotPoolD1Ev: ; 0x0216D430
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0216D450
	bl _ZdaPv
	mov r0, #0
	str r0, [r4]
	arm_func_end _ZN12AnimSlotPoolD1Ev
_0216D450:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN12AnimSlotPool4InitEP18CellAnimControllerm
_ZN12AnimSlotPool4InitEP18CellAnimControllerm: ; 0x0216D458
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	ldr r0, [r8]
	mov r7, r1
	mov r4, r2
	cmp r0, #0
	beq _0216D480
	bl _ZdaPv
	mov r0, #0
	str r0, [r8]
	arm_func_end _ZN12AnimSlotPool4InitEP18CellAnimControllerm
_0216D480:
	str r4, [r8, #4]
	cmp r4, #0
	beq _0216D4B0
	mov r4, r4, lsl #2
	mov r0, r4
	bl _Znam
	str r0, [r8]
	cmp r0, #0
	beq _0216D4B0
	mov r2, r4
	mov r1, #0
	bl MI_CpuFill8
_0216D4B0:
	ldr r0, [r8]
	cmp r0, #0
	cmpne r7, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, [r8, #4]
	mov r6, #0
	cmp r0, #0
	ldmlsia sp!, {r4, r5, r6, r7, r8, pc}
	mov r5, #1
	mov r4, r6
_0216D4D8:
	mov r0, r7
	mov r1, r5
	mov r2, r4
	bl _ZN18CellAnimController6CreateEmm
	ldr r1, [r8]
	add r1, r1, r6, lsl #2
	strh r0, [r1, #2]
	ldr r0, [r8, #4]
	add r6, r6, #1
	cmp r6, r0
	blo _0216D4D8
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start _ZN12AnimSlotPool7ReleaseEP18CellAnimController
_ZN12AnimSlotPool7ReleaseEP18CellAnimController: ; 0x0216D508
	stmdb sp!, {r4, lr}
	mov r4, r0
	cmp r1, #0
	beq _0216D520
	mov r0, r1
	bl _ZN18CellAnimController9RemoveAllEv
	arm_func_end _ZN12AnimSlotPool7ReleaseEP18CellAnimController
_0216D520:
	ldr r0, [r4]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZdaPv
	mov r0, #0
	str r0, [r4]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN12AnimSlotPool7AcquireEv
_ZN12AnimSlotPool7AcquireEv: ; 0x0216D53C
	stmdb sp!, {r3, lr}
	ldr lr, [r0]
	mov r2, #0
	cmp lr, #0
	beq _0216D590
	ldr ip, [r0, #4]
	mov r3, r2
	cmp ip, #0
	bls _0216D590
	arm_func_end _ZN12AnimSlotPool7AcquireEv
_0216D560:
	ldrb r0, [lr, r3, lsl #2]
	mov r1, r3, lsl #2
	cmp r0, #0
	bne _0216D584
	add r0, lr, r1
	ldrh r2, [r0, #2]
	mov r0, #1
	strb r0, [lr, r1]
	b _0216D590
_0216D584:
	add r3, r3, #1
	cmp r3, ip
	blo _0216D560
_0216D590:
	mov r0, r2
	ldmia sp!, {r3, pc}

	arm_func_start _ZN12AnimSlotPool4FreeEt
_ZN12AnimSlotPool4FreeEt: ; 0x0216D598
	stmdb sp!, {r4, lr}
	ldr r2, [r0]
	cmp r2, #0
	ldmeqia sp!, {r4, pc}
	ldr r2, [r0, #4]
	mov r4, #0
	cmp r2, #0
	ldmlsia sp!, {r4, pc}
	mov r3, r4
	arm_func_end _ZN12AnimSlotPool4FreeEt
_0216D5BC:
	ldr lr, [r0]
	mov ip, r4, lsl #2
	ldrb r2, [lr, r4, lsl #2]
	cmp r2, #0
	beq _0216D5E0
	add r2, lr, ip
	ldrh r2, [r2, #2]
	cmp r1, r2
	streqb r3, [lr, ip]
_0216D5E0:
	ldr r2, [r0, #4]
	add r4, r4, #1
	cmp r4, r2
	blo _0216D5BC
	ldmia sp!, {r4, pc}

	arm_func_start ov0_0216D5F4
ov0_0216D5F4: ; 0x0216D5F4
	ldr r3, [r1]
	ldr r2, _0216D628 ; =0x00007FFF
	str r3, [r0, #0x38]
	ldr r3, [r1, #4]
	mov r1, #0
	str r3, [r0, #0x3c]
	strh r2, [r0, #8]
	str r1, [r0, #0x10]
	mov r1, #0x10000
	str r1, [r0, #0x20]
	mov r1, #0x20000
	str r1, [r0, #0x24]
	bx lr
	.align 2, 0
_0216D628: .word 0x00007FFF
	arm_func_end ov0_0216D5F4

	arm_func_start ov0_0216D62C
ov0_0216D62C: ; 0x0216D62C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr r4, _0216D890 ; =0x88888889
	mov sl, r0
	smull r6, r5, r4, r1
	add r5, r1, r5
	mov r1, r1, lsr #0x1f
	add r5, r1, r5, asr #5
	smull r1, r6, r4, r5
	mov r1, r5, lsr #0x1f
	add r6, r5, r6
	add r6, r1, r6, asr #5
	mov r7, #0x3c
	str r2, [sl, #4]
	smull r2, r6, r7, r6
	sub r6, r5, r2
	smull r2, r7, r4, r5
	add r7, r5, r7
	mov sb, r3
	ldr r8, _0216D894 ; =0x66666667
	add r7, r1, r7, asr #5
	smull r1, r2, r8, r6
	mov r1, r6, lsr #0x1f
	add r2, r1, r2, asr #2
	mov r3, #0xa
	smull r1, r2, r3, r2
	sub r2, r6, r1
	mov r1, r2, lsl #0x10
	str r1, [sl, #0x28]
	mov r1, r2, lsl #4
	add r1, r1, #0xa
	mov r2, #0
	mov r1, r1, lsl #0xc
	str r2, [sl, #0x2c]
	str r1, [sl, #0x30]
	mov r1, #0x10000
	str r1, [sl, #0x34]
	mov r1, #0x77000
	str r1, [sl, #0x18]
	sub r1, r1, #0xc6000
	str r1, [sl, #0x1c]
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
	mov r2, r8
	smull r1, r3, r2, r6
	mov r0, r6, lsr #0x1f
	add r3, r0, r3, asr #2
	mov r0, r3, lsl #0x10
	str r0, [sl, #0x28]
	mov r0, r3, lsl #4
	add r0, r0, #0xa
	mov r1, #0
	str r1, [sl, #0x2c]
	mov r0, r0, lsl #0xc
	str r0, [sl, #0x30]
	mov r0, #0x10000
	str r0, [sl, #0x34]
	mov r0, #0x67000
	str r0, [sl, #0x18]
	sub r0, r0, #0xb6000
	str r0, [sl, #0x1c]
	mov r0, sl
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
	mov r0, #0xa0000
	str r0, [sl, #0x28]
	mov r0, #0
	str r0, [sl, #0x2c]
	mov r0, #0xa8000
	str r0, [sl, #0x30]
	mov r0, #0x10000
	str r0, [sl, #0x34]
	mov r0, #0x57000
	str r0, [sl, #0x18]
	sub r0, r0, #0xa6000
	str r0, [sl, #0x1c]
	mov r0, sl
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
	mov r2, r8
	smull r1, r3, r2, r7
	mov r0, r7, lsr #0x1f
	add r3, r0, r3, asr #2
	mov r2, #0xa
	smull r0, r1, r2, r3
	sub r3, r7, r0
	mov r0, r3, lsl #0x10
	str r0, [sl, #0x28]
	mov r0, r3, lsl #4
	add r0, r0, #0xa
	mov r1, #0
	str r1, [sl, #0x2c]
	mov r0, r0, lsl #0xc
	str r0, [sl, #0x30]
	mov r0, #0x10000
	str r0, [sl, #0x34]
	mov r0, #0x47000
	str r0, [sl, #0x18]
	sub r0, r0, #0x96000
	str r0, [sl, #0x1c]
	mov r0, sl
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
	mov r1, r7
	mov r4, r8
	mov r0, r1, lsr #0x1f
	smull r1, r7, r4, r1
	adds r7, r0, r7, asr #2
	mov r8, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r5, #0x4f000
	rsb r5, r5, #0
	mov r6, r8
	mov fp, #0x10000
	arm_func_end ov0_0216D62C
_0216D810:
	smull r1, r2, r4, r7
	mov r0, r7, lsr #0x1f
	add r2, r0, r2, asr #2
	mov r0, #0xa
	smull r1, r2, r0, r2
	sub r2, r7, r1
	mov r1, r2, lsl #0x10
	str r1, [sl, #0x28]
	mov r0, r2, lsl #4
	add r1, r0, #0xa
	add r0, r8, #4
	mov r0, r0, lsl #4
	rsb r0, r0, #0x77
	str r6, [sl, #0x2c]
	mov r1, r1, lsl #0xc
	str r1, [sl, #0x30]
	str fp, [sl, #0x34]
	mov r0, r0, lsl #0xc
	str r0, [sl, #0x18]
	mov r0, sl
	str r5, [sl, #0x1c]
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
	mov r1, r7
	smull r0, r7, r4, r1
	mov r0, r1, lsr #0x1f
	adds r7, r0, r7, asr #2
	add r8, r8, #1
	bne _0216D810
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0216D890: .word 0x88888889
_0216D894: .word 0x66666667

	arm_func_start ov0_0216D898
ov0_0216D898: ; 0x0216D898
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #4
	ldr r2, _0216DA10 ; =_ZTV12CFieldEffect+8
	mov sl, r0
	str r2, [sl]
	ldr r2, [r0]
	mov sb, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _0216DA14 ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [sl]
	str r1, [sl, #0x18]
	ldr r0, _0216DA18 ; =ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c
	ldr r4, _0216DA1C ; =_ZN15CSoftwareSpriteD1Ev
	str r0, [sl]
	ldr r3, _0216DA20 ; =FUN_02005150
	add r0, sl, #0x50
	mov r1, #3
	mov r2, #0x4c
	str r4, [sp]
	bl __cxa_vec_ctor
	mov r0, #0x34
	bl _Znwm
	movs r4, r0
	beq _0216D924
	ldr r1, _0216DA24 ; =_ZTV16CEffectActorData+8
	add r0, r4, #4
	str r1, [r4]
	bl _ZN11VramPaletteC1Ev
	mov r1, #0
	str r1, [r4, #0x2c]
	ldr r0, _0216DA28 ; =_ZTV27CFieldEffectAttackActorData+8
	str r1, [r4, #0x30]
	str r0, [r4]
	arm_func_end ov0_0216D898
_0216D924:
	cmp r4, #0
	beq _0216D940
	mov r0, r4
	mov r1, sb
	mov r2, #1
	mov r3, #3
	bl _ZN27CFieldEffectAttackActorData12ov0_0214FFF0Eiii
_0216D940:
	str r4, [sl, #0x18]
	mov r8, #0
	ldr r5, _0216DA2C ; =0x0000FFFF
	ldr r4, _0216DA30 ; =s_childid_d_overlay_0_0217a6b8
	mov r7, #1
	mov r6, r8
_0216D958:
	ldr r0, [sl, #0x18]
	mov r1, r8
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	addeq r0, sl, r8, lsl #1
	addeq r0, r0, #0x100
	streqh r5, [r0, #0x34]
	beq _0216D998
	mov r1, r7
	mov r2, r6
	bl _ZN18CellAnimController6CreateEmm
	add r1, sl, r8, lsl #1
	add r1, r1, #0x100
	strh r0, [r1, #0x34]
_0216D998:
	add r0, sl, r8, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0x34]
	mov r0, r4
	bl LogInfo
	add r8, r8, #1
	cmp r8, #3
	blt _0216D958
	mov r0, sl
	bl ov0_0216E04C
	mov r1, #0
	str r1, [sl, #0x1c]
	str r1, [sl, #0x20]
	str r1, [sl, #0x2c]
	str r1, [sl, #0x30]
	str r1, [sl, #0x24]
	str r1, [sl, #0x28]
	str r1, [sl, #0x34]
	str r1, [sl, #0x38]
	mov r0, #0x1000
	str r0, [sl, #0x44]
	str r0, [sl, #0x48]
	str r1, [sl, #0x3c]
	str r0, [sl, #0x40]
	cmp sb, #0x36
	ldreq r0, _0216DA34 ; =0x00001333
	str r0, [sl, #0x4c]
	mov r0, sl
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_0216DA10: .word _ZTV12CFieldEffect+8
_0216DA14: .word _ZTV17CFieldEffectActor+8
_0216DA18: .word ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c
_0216DA1C: .word _ZN15CSoftwareSpriteD1Ev
_0216DA20: .word _ZN15CSoftwareSpriteC1Ev
_0216DA24: .word _ZTV16CEffectActorData+8
_0216DA28: .word _ZTV27CFieldEffectAttackActorData+8
_0216DA2C: .word 0x0000FFFF
_0216DA30: .word s_childid_d_overlay_0_0217a6b8
_0216DA34: .word 0x00001333

	arm_func_start _ZN17CFieldEffectLaserD1Ev
_ZN17CFieldEffectLaserD1Ev: ; 0x0216DA38
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216DAD4 ; =ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c
	mov r4, r0
	str r1, [r4]
	mov r5, #0
	arm_func_end _ZN17CFieldEffectLaserD1Ev
_0216DA4C:
	ldr r0, [r4, #0x18]
	mov r1, r5
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	add r1, r4, r5, lsl #1
	add r1, r1, #0x100
	ldrh r1, [r1, #0x34]
	bl _ZN18CellAnimController6RemoveEt
	add r5, r5, #1
	cmp r5, #3
	blt _0216DA4C
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0216DAA0
	beq _0216DA98
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0216DA98:
	mov r0, #0
	str r0, [r4, #0x18]
_0216DAA0:
	ldr r3, _0216DAD8 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x50
	mov r1, #3
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _0216DADC ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216DAD4: .word ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c
_0216DAD8: .word _ZN15CSoftwareSpriteD1Ev
_0216DADC: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216DAE0
ov0_0216DAE0: ; 0x0216DAE0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216DB84 ; =ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c
	mov r4, r0
	str r1, [r4]
	mov r5, #0
	arm_func_end ov0_0216DAE0
_0216DAF4:
	ldr r0, [r4, #0x18]
	mov r1, r5
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	add r1, r4, r5, lsl #1
	add r1, r1, #0x100
	ldrh r1, [r1, #0x34]
	bl _ZN18CellAnimController6RemoveEt
	add r5, r5, #1
	cmp r5, #3
	blt _0216DAF4
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0216DB48
	beq _0216DB40
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0216DB40:
	mov r0, #0
	str r0, [r4, #0x18]
_0216DB48:
	ldr r3, _0216DB88 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x50
	mov r1, #3
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _0216DB8C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216DB84: .word ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c
_0216DB88: .word _ZN15CSoftwareSpriteD1Ev
_0216DB8C: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN17CFieldEffectLaser12ov0_02142264Ei
_ZN17CFieldEffectLaser12ov0_02142264Ei: ; 0x0216DB90
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x20
	mov r5, r0
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	movs r4, r0
	cmpne r4, #4
	ldrne r0, [r5, #0x18]
	cmpne r0, #0
	beq _0216DBC0
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	arm_func_end _ZN17CFieldEffectLaser12ov0_02142264Ei
_0216DBC0:
	cmp r4, #1
	beq _0216DBDC
	cmp r4, #2
	beq _0216DC40
	cmp r4, #3
	beq _0216DC24
	b _0216DC48
_0216DBDC:
	ldr r1, [r5, #0x40]
	ldr r0, [r5, #0x44]
	add r0, r1, r0
	str r0, [r5, #0x40]
	cmp r0, #0x1000
	movgt r0, #0x1000
	strgt r0, [r5, #0x40]
	ldr r2, [r5, #0x34]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x38]
	add r0, r0, r2
	str r0, [r5, #0x2c]
	ldr r0, [r5, #0x30]
	str r2, [sp, #0x10]
	add r0, r0, r1
	str r1, [sp, #0x14]
	str r0, [r5, #0x30]
	b _0216DC48
_0216DC24:
	ldr r1, [r5, #0x40]
	ldr r0, [r5, #0x48]
	subs r0, r1, r0
	str r0, [r5, #0x40]
	movmi r0, #0
	strmi r0, [r5, #0x40]
	b _0216DC48
_0216DC40:
	mov r0, #0x1000
	str r0, [r5, #0x40]
_0216DC48:
	ldr r1, [r5, #0x1c]
	ldr r0, [r5, #0x20]
	ldr r3, [r5, #0x2c]
	ldr r2, [r5, #0x30]
	sub r7, r3, r1
	sub r6, r2, r0
	smull lr, ip, r7, r7
	smull r3, r2, r6, r6
	mov lr, lr, lsr #0xc
	mov r3, r3, lsr #0xc
	orr lr, lr, ip, lsl #20
	orr r3, r3, r2, lsl #20
	str r0, [sp, #0xc]
	adds r0, lr, r3
	str r1, [sp, #8]
	str r7, [sp]
	str r6, [sp, #4]
	str r7, [sp, #0x18]
	str r6, [sp, #0x1c]
	moveq r0, #0
	beq _0216DCA4
	bl FX_Sqrt
	mov r0, r0, asr #4
_0216DCA4:
	str r0, [r5, #0x3c]
	mov r0, r4
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17CFieldEffectLaser12ov0_02142344EP8Camera2D
_ZN17CFieldEffectLaser12ov0_02142344EP8Camera2D: ; 0x0216DCB4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x38
	mov r6, r0
	ldr r0, [r6, #0x14]
	mov r5, r1
	cmp r0, #4
	cmpne r0, #0
	beq _0216DE24
	ldr sl, [r6, #0x1c]
	ldr sb, [r6, #0x20]
	mov r4, r6
	str sl, [r6, #0x68]
	str sb, [r6, #0x6c]
	ldr r8, [r6, #0x1c]
	ldr r0, [r6, #0x2c]
	ldr r7, [r6, #0x20]
	add lr, r0, r8
	ldr r1, [r6, #0x30]
	mov r0, lr, asr #0x1f
	add ip, r1, r7
	mov r2, r0, lsl #0xb
	mov r3, lr, lsl #0xb
	mov r0, ip, asr #0x1f
	mov r0, r0, lsl #0xb
	mov r1, ip, lsl #0xb
	orr r2, r2, lr, lsr #21
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	str r8, [sp, #0x20]
	str r7, [sp, #0x24]
	orr r0, r0, ip, lsr #21
	mov r2, r1, lsr #0xc
	orr r2, r2, r0, lsl #20
	str r3, [r6, #0xb4]
	str r2, [r6, #0xb8]
	ldr r0, [r6, #0x3c]
	str sl, [sp, #0x28]
	str r0, [r6, #0xbc]
	ldr r1, [r6, #0x2c]
	ldr r0, [r6, #0x30]
	str sb, [sp, #0x2c]
	str r1, [r6, #0x100]
	str lr, [sp, #0x18]
	str ip, [sp, #0x1c]
	str lr, [sp, #0x30]
	str ip, [sp, #0x34]
	str r3, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp]
	str r0, [sp, #4]
	str r0, [r6, #0x104]
	add r8, r6, #0x50
	mov r7, #0
	arm_func_end _ZN17CFieldEffectLaser12ov0_02142344EP8Camera2D
_0216DD90:
	cmp r7, #2
	bne _0216DDA4
	ldr r0, [r6, #0x3c]
	cmp r0, #0x1000
	blt _0216DE10
_0216DDA4:
	ldr r0, [r6, #0x18]
	mov r1, r7
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r7, #1
	ldrne r1, [r6, #0x40]
	strne r1, [r4, #0x74]
	bne _0216DDE0
	ldr r2, [r6, #0x40]
	ldr r1, [r6, #0x4c]
	smull r3, r1, r2, r1
	mov r2, r3, lsr #0xc
	orr r2, r2, r1, lsl #20
	str r2, [r4, #0x74]
_0216DDE0:
	cmp r0, #0
	beq _0216DDFC
	add r1, r6, r7, lsl #1
	add r1, r1, #0x100
	ldrh r1, [r1, #0x34]
	bl _ZN18CellAnimController7GetCellEt
	strh r0, [r4, #0x7a]
_0216DDFC:
	mov r0, r8
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #8]
	blx r2
_0216DE10:
	add r7, r7, #1
	cmp r7, #3
	add r4, r4, #0x4c
	add r8, r8, #0x4c
	blt _0216DD90
_0216DE24:
	mov r0, #0
	add sp, sp, #0x38
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start _ZN17CFieldEffectLaser8SetParamEii
_ZN17CFieldEffectLaser8SetParamEii: ; 0x0216DE30
	cmp r1, #9
	mov r3, #1
	bgt _0216DE64
	cmp r1, #9
	bge _0216DE88
	cmp r1, #2
	bgt _0216DEA0
	cmp r1, #1
	blt _0216DEA0
	beq _0216DE70
	cmp r1, #2
	beq _0216DE7C
	b _0216DEA0
	arm_func_end _ZN17CFieldEffectLaser8SetParamEii
_0216DE64:
	cmp r1, #0xa
	beq _0216DE94
	b _0216DEA0
_0216DE70:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x1c]
	b _0216DEA4
_0216DE7C:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x20]
	b _0216DEA4
_0216DE88:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x24]
	b _0216DEA4
_0216DE94:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x28]
	b _0216DEA4
_0216DEA0:
	mov r3, #0
_0216DEA4:
	mov r0, r3
	bx lr

	arm_func_start _ZN17CFieldEffectLaser12ov0_021421F0Eiii
_ZN17CFieldEffectLaser12ov0_021421F0Eiii: ; 0x0216DEAC
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x28
	mov r8, r0
	ldr r0, [r8, #0x1c]
	mov r7, r1
	str r0, [r8, #0x2c]
	ldr r0, [r8, #0x20]
	mov r1, #0
	str r0, [r8, #0x30]
	str r1, [r8, #0x40]
	cmp r7, #0
	mov r6, r2
	mov r5, r3
	str r1, [r8, #0x3c]
	movle r0, #0x1000
	ble _0216DEFC
	mov r2, r7, lsl #0xc
	mov r3, r2, asr #0x1f
	mov r0, #0x1000000
	bl _ll_div
	arm_func_end _ZN17CFieldEffectLaser12ov0_021421F0Eiii
_0216DEFC:
	str r0, [r8, #0x44]
	cmp r5, #0
	movle r0, #0x1000
	ble _0216DF20
	mov r2, r5, lsl #0xc
	mov r3, r2, asr #0x1f
	mov r0, #0x1000000
	mov r1, #0
	bl _ll_div
_0216DF20:
	str r0, [r8, #0x48]
	ldr r2, [r8, #0x2c]
	ldr r1, [r8, #0x30]
	ldr r0, [r8, #0x24]
	ldr r3, [r8, #0x28]
	sub r0, r0, r2
	sub r4, r3, r1
	smull ip, sl, r0, r0
	smull sb, r3, r4, r4
	mov ip, ip, lsr #0xc
	mov sb, sb, lsr #0xc
	orr ip, ip, sl, lsl #20
	orr sb, sb, r3, lsl #20
	str r1, [sp, #0x14]
	str r2, [sp, #0x10]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	adds r1, ip, sb
	beq _0216DFFC
	cmp r7, #0
	ble _0216DFE0
	mov sl, r7, lsl #0xc
	mov r1, r0, asr #0x1f
	mov sb, sl, asr #0x1f
	mov r1, r1, lsl #0xc
	orr r1, r1, r0, lsr #20
	mov r2, sl
	mov r3, sb
	mov r0, r0, lsl #0xc
	bl _ll_div
	mov ip, r4
	str r0, [sp]
	mov r0, ip, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, sl
	mov r3, sb
	orr r1, r1, ip, lsr #20
	mov r0, ip, lsl #0xc
	bl _ll_div
	ldr r1, [sp]
	str r0, [sp, #4]
	str r1, [r8, #0x34]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [r8, #0x38]
	b _0216E008
_0216DFE0:
	str r0, [r8, #0x34]
	str r4, [r8, #0x38]
	ldr r0, [r8, #0x24]
	str r0, [r8, #0x2c]
	ldr r0, [r8, #0x28]
	str r0, [r8, #0x30]
	b _0216E008
_0216DFFC:
	mov r0, #0
	str r0, [r8, #0x34]
	str r0, [r8, #0x38]
_0216E008:
	ldr r1, [sp, #0x20]
	mov r0, r4
	bl FX_Atan2Idx
	mov r2, r8
	mov r1, #0
_0216E01C:
	add r1, r1, #1
	strh r0, [r2, #0x78]
	cmp r1, #3
	add r2, r2, #0x4c
	blt _0216E01C
	mov r0, r8
	mov r1, r7
	mov r2, r6
	mov r3, r5
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	add sp, sp, #0x28
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start ov0_0216E04C
ov0_0216E04C: ; 0x0216E04C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r7, r0
	mov r5, #0
	mov r6, r7
	mov r8, r5
	arm_func_end ov0_0216E04C
_0216E060:
	ldr r0, [r7, #0x18]
	mov r1, r5
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	mov r4, r0
	ldr r0, [r7, #0x18]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov sb, r0
	ldr r0, [r7, #0x18]
	mov r1, r5
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	str r0, [r6, #0x7c]
	str r8, [r6, #0x80]
	str sb, [r6, #0x84]
	str r4, [r6, #0x88]
	add r0, r5, #8
	strh r8, [r6, #0x7a]
	add r5, r5, #1
	str r0, [r6, #0x60]
	cmp r5, #3
	add r6, r6, #0x4c
	blt _0216E060
	ldr r1, _0216E0E4 ; =0x00000622
	str r1, [r7, #0x54]
	sub r0, r1, #0xa
	str r0, [r7, #0xa0]
	str r1, [r7, #0xec]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0216E0E4: .word 0x00000622

	arm_func_start _ZN24CFieldEffectLaserFactory6CreateEi
_ZN24CFieldEffectLaserFactory6CreateEi: ; 0x0216E0E8
	stmdb sp!, {r4, lr}
	mov r0, #0x13c
	mov r4, r1
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r1, r4
	bl ov0_0216D898
	ldmia sp!, {r4, pc}
	arm_func_end _ZN24CFieldEffectLaserFactory6CreateEi

	arm_func_start _ZN17CFieldEffectLaser11GetEffectIdEv
_ZN17CFieldEffectLaser11GetEffectIdEv: ; 0x0216E10C
	mov r0, #3
	bx lr
	arm_func_end _ZN17CFieldEffectLaser11GetEffectIdEv

	arm_func_start ov0_0216E114
ov0_0216E114: ; 0x0216E114
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216E114

	arm_func_start ov0_0216E128
ov0_0216E128: ; 0x0216E128
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _0216E1A8 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r1, _0216E1AC ; =ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744
	mov r0, #0
	str r1, [r4]
	str r0, [r4, #0x18]
	str r0, [r4, #0x1c]
	str r0, [r4, #0x20]
	mov r0, #0x78
	str r0, [r4, #0x24]
	mov r0, #0x1000
	ldr ip, _0216E1B0 ; =_ZN17UnkClass_02151244D1Ev
	str r0, [r4, #0x28]
	ldr r3, _0216E1B4 ; =_ZN17UnkClass_02151244C1Ev
	add r0, r4, #0x2c
	mov r1, #2
	mov r2, #0x2c
	str ip, [sp]
	bl __cxa_vec_ctor
	ldr r1, _0216E1B8 ; =0x00007FFF
	mov r0, r4
	strh r1, [r4, #0x84]
	bl ov0_0216EA58
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0216E1A8: .word _ZTV12CFieldEffect+8
_0216E1AC: .word ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744
_0216E1B0: .word _ZN17UnkClass_02151244D1Ev
_0216E1B4: .word _ZN17UnkClass_02151244C1Ev
_0216E1B8: .word 0x00007FFF
	arm_func_end ov0_0216E128

	arm_func_start _ZN24CFieldEffectRisingPhotonD1Ev
_ZN24CFieldEffectRisingPhotonD1Ev: ; 0x0216E1BC
	stmdb sp!, {r4, r5, r6, lr}
	ldr r1, _0216E25C ; =ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744
	mov r4, r0
	str r1, [r4]
	add r6, r4, #0x2c
	mov r5, #0
	arm_func_end _ZN24CFieldEffectRisingPhotonD1Ev
_0216E1D4:
	mov r0, r6
	bl _ZN10NtfTexture12ReleaseFilesEv
	add r5, r5, #1
	cmp r5, #2
	add r6, r6, #0x2c
	blt _0216E1D4
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0216E210
	ldr r3, _0216E260 ; =_ZN16CSimpleSpriteNTFD1Ev
	mov r1, #0x5c
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x20]
_0216E210:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0216E228
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x1c]
_0216E228:
	ldr r3, _0216E264 ; =_ZN17UnkClass_02151244D1Ev
	add r0, r4, #0x2c
	mov r1, #2
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	ldr r1, _0216E268 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0216E25C: .word ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744
_0216E260: .word _ZN16CSimpleSpriteNTFD1Ev
_0216E264: .word _ZN17UnkClass_02151244D1Ev
_0216E268: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216E26C
ov0_0216E26C: ; 0x0216E26C
	stmdb sp!, {r4, r5, r6, lr}
	ldr r1, _0216E314 ; =ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744
	mov r4, r0
	str r1, [r4]
	add r6, r4, #0x2c
	mov r5, #0
	arm_func_end ov0_0216E26C
_0216E284:
	mov r0, r6
	bl _ZN10NtfTexture12ReleaseFilesEv
	add r5, r5, #1
	cmp r5, #2
	add r6, r6, #0x2c
	blt _0216E284
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0216E2C0
	ldr r3, _0216E318 ; =_ZN16CSimpleSpriteNTFD1Ev
	mov r1, #0x5c
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x20]
_0216E2C0:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0216E2D8
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x1c]
_0216E2D8:
	ldr r3, _0216E31C ; =_ZN17UnkClass_02151244D1Ev
	add r0, r4, #0x2c
	mov r1, #2
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	ldr r1, _0216E320 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0216E314: .word ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744
_0216E318: .word _ZN16CSimpleSpriteNTFD1Ev
_0216E31C: .word _ZN17UnkClass_02151244D1Ev
_0216E320: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN24CFieldEffectRisingPhoton8SetParamEii
_ZN24CFieldEffectRisingPhoton8SetParamEii: ; 0x0216E324
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r4, r0
	cmp r1, #0x15
	mov r5, #1
	beq _0216E34C
	cmp r1, #0x18
	beq _0216E488
	cmp r1, #0x19
	beq _0216E490
	b _0216E4B0
	arm_func_end _ZN24CFieldEffectRisingPhoton8SetParamEii
_0216E34C:
	cmp r2, #0
	ble _0216E440
	str r2, [r4, #0x18]
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x18]
	ldr r3, _0216E4BC ; =ov0_0216E4CC
	mov r1, #0x14
	bl __cxa_vec_new
	ldr r1, _0216E4C0 ; =_ZN16CSimpleSpriteNTFD1Ev
	str r0, [r4, #0x1c]
	str r1, [sp]
	ldr r0, [r4, #0x18]
	ldr r3, _0216E4C4 ; =ov0_02166794
	mov r0, r0, lsl #1
	mov r1, #0x5c
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x20]
	ldr r0, [r4, #0x18]
	mov ip, #0
	mov r0, r0, lsl #1
	cmp r0, #0
	ble _0216E4B4
	mov lr, ip
	add r3, r4, #0x2c
	mov r2, #0x10000
	mov r1, ip
	mov r0, #0x40000
	mov r6, #0x2c
_0216E3C4:
	and r7, ip, #1
	mla sb, r7, r6, r3
	ldr r8, [r4, #0x20]
	and r7, ip, #0x1f
	add r8, r8, lr
	str sb, [r8, #0x18]
	ldr sb, [r4, #0x20]
	add r8, r7, #8
	add r7, sb, lr
	str r2, [r7, #0x4c]
	ldr r7, [r4, #0x20]
	add ip, ip, #1
	add r7, r7, lr
	str r2, [r7, #0x50]
	ldr r7, [r4, #0x20]
	add r7, r7, lr
	str r1, [r7, #0x2c]
	str r1, [r7, #0x30]
	str r0, [r7, #0x34]
	str r0, [r7, #0x38]
	ldr r7, [r4, #0x20]
	add r7, r7, lr
	str r8, [r7, #0x10]
	ldr r7, [r4, #0x20]
	add r7, r7, lr
	str r1, [r7, #0x14]
	ldr r7, [r4, #0x18]
	add lr, lr, #0x5c
	cmp ip, r7, lsl #1
	blt _0216E3C4
	b _0216E4B4
_0216E440:
	mov r0, #0
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0216E46C
	ldr r3, _0216E4C0 ; =_ZN16CSimpleSpriteNTFD1Ev
	mov r1, #0x5c
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x20]
_0216E46C:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0216E4B4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x1c]
	b _0216E4B4
_0216E488:
	str r2, [r4, #0x24]
	b _0216E4B4
_0216E490:
	ldr r1, _0216E4C8 ; =0x88888889
	mov r3, r2, lsl #0xc
	smull r0, r6, r1, r3
	add r6, r6, r2, lsl #12
	mov r0, r3, lsr #0x1f
	add r6, r0, r6, asr #5
	str r6, [r4, #0x28]
	b _0216E4B4
_0216E4B0:
	mov r5, #0
_0216E4B4:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0216E4BC: .word ov0_0216E4CC
_0216E4C0: .word _ZN16CSimpleSpriteNTFD1Ev
_0216E4C4: .word ov0_02166794
_0216E4C8: .word 0x88888889

	arm_func_start ov0_0216E4CC
ov0_0216E4CC: ; 0x0216E4CC
	mov r1, #0
	str r1, [r0, #8]
	str r1, [r0, #4]
	str r1, [r0]
	bx lr
	arm_func_end ov0_0216E4CC

	arm_func_start _ZN24CFieldEffectRisingPhoton12sub_02033244Eiii
_ZN24CFieldEffectRisingPhoton12sub_02033244Eiii: ; 0x0216E4E0
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	cmp r1, #0x16
	mov ip, #1
	bne _0216E5C0
	ldr r4, [r0, #0x18]
	cmp r4, #0
	ble _0216E5B8
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	ldrne r1, [r0, #0x20]
	cmpne r1, #0
	beq _0216E5B8
	add r1, r4, r4, lsl #1
	cmp r3, r1
	bne _0216E5B8
	cmp r4, #0
	mov lr, #0
	ble _0216E5C4
	mov r7, #0x5c
	mov r4, lr
	mov r5, lr
	mov r6, ip
	mov r8, r7
	arm_func_end _ZN24CFieldEffectRisingPhoton12sub_02033244Eiii
_0216E53C:
	ldr r3, [r2]
	ldr r1, [r0, #0x1c]
	mov r3, r3, lsl #0xc
	str r3, [r1, r4]
	ldr sb, [r2, #4]
	add r3, r1, r4
	mov sb, sb, lsl #0xc
	str sb, [r3, #4]
	ldr sb, [r2, #8]
	add lr, lr, #1
	str sb, [r3, #8]
	ldr sl, [r0, #0x20]
	ldr sb, [r1, r4]
	mla sl, r5, r7, sl
	str sb, [sl, #0x3c]
	ldr sb, [r3, #4]
	add r2, r2, #0xc
	str sb, [sl, #0x40]
	ldr sb, [r0, #0x20]
	ldr r1, [r1, r4]
	mla sb, r6, r8, sb
	str r1, [sb, #0x3c]
	ldr r1, [r3, #4]
	add r4, r4, #0x14
	str r1, [sb, #0x40]
	ldr r1, [r0, #0x18]
	add r5, r5, #2
	cmp lr, r1
	add r6, r6, #2
	blt _0216E53C
	b _0216E5C4
_0216E5B8:
	mov ip, #0
	b _0216E5C4
_0216E5C0:
	mov ip, #0
_0216E5C4:
	mov r0, ip
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start _ZN24CFieldEffectRisingPhoton7IsReadyEv
_ZN24CFieldEffectRisingPhoton7IsReadyEv: ; 0x0216E5CC
	ldrb r0, [r0, #0x86]
	cmp r0, #2
	movhs r0, #1
	movlo r0, #0
	bx lr
	arm_func_end _ZN24CFieldEffectRisingPhoton7IsReadyEv

	arm_func_start _ZN24CFieldEffectRisingPhoton12ov0_021421F0Eiii
_ZN24CFieldEffectRisingPhoton12ov0_021421F0Eiii: ; 0x0216E5E0
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	ldr r4, [r0, #0x18]
	mov ip, #0
	cmp r4, #0
	ble _0216E648
	mov lr, ip
	mov r6, #2
	mov r7, #1
	mov r8, ip
	mov r5, ip
	arm_func_end _ZN24CFieldEffectRisingPhoton12ov0_021421F0Eiii
_0216E608:
	ldr r4, [r0, #0x1c]
	add sb, r4, lr
	ldr r4, [sb, #8]
	cmp r4, #0
	strgt r8, [sb, #0xc]
	bgt _0216E630
	ldr r4, [r0, #0x24]
	cmp r4, #0
	strgt r7, [sb, #0xc]
	strle r6, [sb, #0xc]
_0216E630:
	str r5, [sb, #0x10]
	ldr r4, [r0, #0x18]
	add ip, ip, #1
	cmp ip, r4
	add lr, lr, #0x14
	blt _0216E608
_0216E648:
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN24CFieldEffectRisingPhoton12ov0_02142264Ei
_ZN24CFieldEffectRisingPhoton12ov0_02142264Ei: ; 0x0216E650
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x1c
	mov sl, r0
	ldrb r0, [sl, #0x86]
	mov sb, r1
	mov r1, sb
	cmp r0, #2
	addlo r0, r0, #1
	strlob r0, [sl, #0x86]
	mov r0, sl
	bl _ZN12CFieldEffect12ov0_02142264Ei
	cmp r0, #0
	str r0, [sp, #4]
	cmpne r0, #4
	beq _0216E8F4
	ldr r0, _0216E900 ; =MAIN_BSS_0210CA40
	ldr r1, [sl, #0x18]
	ldr r0, [r0]
	mov r4, #0
	ldr r0, [r0, #8]
	str r4, [sp]
	cmp r1, #0
	str r0, [sp, #8]
	ble _0216E8D0
	mov r6, r4
	mov r7, r4
	mov r8, #1
	arm_func_end _ZN24CFieldEffectRisingPhoton12ov0_02142264Ei
_0216E6BC:
	ldr r0, [sl, #0x1c]
	add r5, r0, r6
	ldr r0, [r5, #0xc]
	cmp r0, #3
	beq _0216E8AC
	cmp r0, #0
	add r4, r4, #1
	beq _0216E6F0
	cmp r0, #1
	beq _0216E720
	cmp r0, #2
	beq _0216E7C0
	b _0216E8A8
_0216E6F0:
	ldr r0, [r5, #0x10]
	add r0, r0, sb
	str r0, [r5, #0x10]
	ldr r1, [r5, #8]
	cmp r0, r1
	blt _0216E8AC
	ldr r0, [r5, #0x10]
	sub r0, r0, r1
	str r0, [r5, #0x10]
	mov r0, #1
	str r0, [r5, #0xc]
	b _0216E8AC
_0216E720:
	ldr r1, [r5, #4]
	ldr r0, [sl, #0x28]
	sub r0, r1, r0
	str r0, [r5, #4]
	mov r0, #0x5c
	mul r0, r7, r0
	ldr r1, [r5, #0x10]
	ldr r2, [sl, #0x20]
	cmp r1, #0x1e
	movge r1, #0x1f
	add r2, r2, r0
	str r1, [r2, #0x14]
	ldr r2, [sl, #0x20]
	add r2, r2, r0
	str r1, [r2, #0x70]
	ldr r2, [sl, #0x20]
	ldr r1, [r5]
	add r2, r2, r0
	str r1, [r2, #0x3c]
	ldr r0, [r5, #4]
	str r0, [r2, #0x40]
	ldr r2, [sl, #0x20]
	mov r0, #0x5c
	mla r2, r8, r0, r2
	ldr r1, [r5]
	str r1, [r2, #0x3c]
	ldr r0, [r5, #4]
	str r0, [r2, #0x40]
	ldr r0, [r5, #0x10]
	add r0, r0, sb
	str r0, [r5, #0x10]
	ldr r1, [sl, #0x24]
	cmp r0, r1
	blt _0216E8AC
	ldr r0, [r5, #0x10]
	sub r0, r0, r1
	str r0, [r5, #0x10]
	mov r0, #2
	str r0, [r5, #0xc]
	b _0216E8AC
_0216E7C0:
	ldr r0, [sp, #8]
	ldr r2, [sl, #0x28]
	cmp r0, #0
	mov r0, #0x5c
	mul r1, r7, r0
	mov r0, #0xa000
	umull ip, r3, r2, r0
	mov fp, r2, asr #0x1f
	mov r0, #0xa000
	mla r3, fp, r0, r3
	mov r0, ip, lsr #0xc
	ldr lr, [r5, #4]
	orr r0, r0, r3, lsl #20
	sub r0, lr, r0
	str r0, [r5, #4]
	ldr r0, [sl, #0x20]
	add r2, r0, r1
	mov r0, #0x1f
	str r0, [r2, #0x14]
	ldr r0, [sl, #0x20]
	add r2, r0, r1
	mov r0, #0x1f
	str r0, [r2, #0x70]
	ldr r2, [sl, #0x20]
	ldr r0, [r5]
	add r1, r2, r1
	str r0, [r1, #0x3c]
	ldr r0, [r5, #4]
	str r0, [r1, #0x40]
	ldr r2, [sl, #0x20]
	mov r0, #0x5c
	mla r2, r8, r0, r2
	ldr r1, [r5]
	str r1, [r2, #0x3c]
	ldr r0, [r5, #4]
	str r0, [r2, #0x40]
	ldr r0, [r5, #0x10]
	add r0, r0, sb
	str r0, [r5, #0x10]
	beq _0216E8AC
	ldr r1, [r5]
	ldr r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, #4]
	add r1, sp, #0xc
	str r2, [sp, #0x10]
	mov r2, #0x10000
	str r2, [sp, #0x18]
	str r2, [sp, #0x14]
	ldr r2, _0216E904 ; =0x00001199
	bl _ZN8Camera2D13IsRectVisibleEP9Rectanglel
	cmp r0, #0
	bne _0216E8AC
	mov r0, #0
	str r0, [r5, #0x10]
	mov r0, #3
	str r0, [r5, #0xc]
	b _0216E8AC
_0216E8A8:
	sub r4, r4, #1
_0216E8AC:
	ldr r0, [sp]
	ldr r1, [sl, #0x18]
	add r0, r0, #1
	add r6, r6, #0x14
	add r7, r7, #2
	add r8, r8, #2
	str r0, [sp]
	cmp r0, r1
	blt _0216E6BC
_0216E8D0:
	cmp r4, #0
	bne _0216E8F4
	mov r0, sl
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x20]
	blx r2
	mov r0, #4
	str r0, [sp, #4]
_0216E8F4:
	ldr r0, [sp, #4]
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0216E900: .word MAIN_BSS_0210CA40
_0216E904: .word 0x00001199

	arm_func_start _ZN24CFieldEffectRisingPhoton12ov0_02142344EP8Camera2D
_ZN24CFieldEffectRisingPhoton12ov0_02142344EP8Camera2D: ; 0x0216E908
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xc
	mov r7, r0
	ldr r0, [r7, #0x14]
	str r1, [sp]
	cmp r0, #0
	cmpne r0, #4
	beq _0216EA48
	ldr r1, [r7, #0x18]
	mov r0, #0
	str r0, [sp, #4]
	cmp r1, #0
	ble _0216EA48
	mov r4, r0
	mov r5, r0
	mov r6, #1
	arm_func_end _ZN24CFieldEffectRisingPhoton12ov0_02142344EP8Camera2D
_0216E948:
	ldr r0, [r7, #0x1c]
	add r0, r0, r4
	ldr r0, [r0, #0xc]
	sub r0, r0, #1
	cmp r0, #1
	bhi _0216EA24
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r2, [r0, #0x448]
	ldmib r1, {fp, ip}
	umull r8, lr, ip, r2
	str r0, [sp, #8]
	mov r0, #0
	mla lr, ip, fp, lr
	ldr r3, [r1, #0xc]
	ldr sl, [r1, #0x10]
	mla lr, r3, r2, lr
	ldr sb, [r1, #0x14]
	ldr r2, [sp, #8]
	adds r3, sl, r8
	str r3, [r2, #0x448]
	adc r2, sb, lr
	mov r0, r0, lsl #1
	orrs r0, r0, r2, lsr #31
	mov r0, #0x5c
	str r2, [r1, #4]
	mul r8, r5, r0
	ldrne sb, _0216EA54 ; =0x00001333
	ldr r0, [r7, #0x20]
	moveq sb, #0x1000
	add r0, r0, r8
	str sb, [r0, #0x48]
	str sb, [r0, #0x44]
	ldr r0, [r7, #0x20]
	ldr r1, [sp]
	ldr r2, [r0, r8]!
	ldr r2, [r2, #8]
	blx r2
	mov r0, #0x5c
	mul r2, r6, r0
	ldr r1, [r7, #0x20]
	ldrh r3, [r7, #0x84]
	add r0, r1, r8
	ldr r1, [sp]
	strh r3, [r0, #0x64]
	ldr r0, [r7, #0x20]
	add r0, r0, r2
	str sb, [r0, #0x48]
	str sb, [r0, #0x44]
	ldr r0, [r7, #0x20]
	ldr r2, [r0, r2]!
	ldr r2, [r2, #8]
	blx r2
_0216EA24:
	ldr r0, [sp, #4]
	ldr r1, [r7, #0x18]
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, r1
	add r4, r4, #0x14
	add r5, r5, #2
	add r6, r6, #2
	blt _0216E948
_0216EA48:
	mov r0, #0
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0216EA54: .word 0x00001333

	arm_func_start ov0_0216EA58
ov0_0216EA58: ; 0x0216EA58
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x7c
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	mov r4, r0
	str ip, [sp, #8]
	ldr r1, _0216EAF4 ; =s_MEF_overlay_0_0217a7a0
	ldr r2, _0216EAF8 ; =s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217a7a4
	add r0, sp, #0x10
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r1, _0216EAFC ; =s_MEF_ef100_00_ntft_overlay_0_0217a7c4
	ldr r2, _0216EB00 ; =s_MEF_ef100_00_ntfp_overlay_0_0217a7d8
	add r0, r4, #0x2c
	mov r3, #0
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	mov r0, #6
	str r0, [r4, #0x48]
	mov r3, #3
	str r3, [r4, #0x4c]
	str r3, [r4, #0x50]
	ldr r1, _0216EB04 ; =s_MEF_ef100_02_ntft_overlay_0_0217a7ec
	ldr r2, _0216EB08 ; =s_MEF_ef100_02_ntfp_overlay_0_0217a800
	add r0, r4, #0x58
	mov r3, #0
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	mov r0, #6
	str r0, [r4, #0x74]
	mov r1, #3
	str r1, [r4, #0x78]
	str r1, [r4, #0x7c]
	mov r1, #0
	add r0, sp, #0x10
	strb r1, [r4, #0x86]
	bl _ZN13CArchiveGuardD1Ev
	add sp, sp, #0x7c
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0216EAF4: .word s_MEF_overlay_0_0217a7a0
_0216EAF8: .word s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217a7a4
_0216EAFC: .word s_MEF_ef100_00_ntft_overlay_0_0217a7c4
_0216EB00: .word s_MEF_ef100_00_ntfp_overlay_0_0217a7d8
_0216EB04: .word s_MEF_ef100_02_ntft_overlay_0_0217a7ec
_0216EB08: .word s_MEF_ef100_02_ntfp_overlay_0_0217a800
	arm_func_end ov0_0216EA58

	arm_func_start _ZN31CFieldEffectRisingPhotonFactory6CreateEi
_ZN31CFieldEffectRisingPhotonFactory6CreateEi: ; 0x0216EB0C
	stmdb sp!, {r3, lr}
	mov r0, #0x88
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov0_0216E128
	ldmia sp!, {r3, pc}
	arm_func_end _ZN31CFieldEffectRisingPhotonFactory6CreateEi

	arm_func_start _ZN24CFieldEffectRisingPhoton8SetColorEt
_ZN24CFieldEffectRisingPhoton8SetColorEt: ; 0x0216EB28
	strh r1, [r0, #0x84]
	bx lr
	arm_func_end _ZN24CFieldEffectRisingPhoton8SetColorEt

	arm_func_start _ZN24CFieldEffectRisingPhoton11GetEffectIdEv
_ZN24CFieldEffectRisingPhoton11GetEffectIdEv: ; 0x0216EB30
	mov r0, #0x18
	bx lr
	arm_func_end _ZN24CFieldEffectRisingPhoton11GetEffectIdEv

	arm_func_start ov0_0216EB38
ov0_0216EB38: ; 0x0216EB38
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216EB38

	arm_func_start ov0_0216EB4C
ov0_0216EB4C: ; 0x0216EB4C
	stmdb sp!, {r4, lr}
	mov r1, #3
	mov r4, r0
	bl ov0_0216EF08
	ldr r0, _0216EBA0 ; =ptr_FUN_overlay_0_0216ebbc_overlay_0_0217a9dc
	ldr r1, _0216EBA4 ; =PTR_LAB_overlay_0_0216ebb8_overlay_0_0217a858
	str r0, [r4]
	ldr r0, _0216EBA8 ; =_ZTV11CDrawObject+8
	str r1, [r4, #0x78]
	str r0, [r4, #0x7c]
	mov r2, #0
	ldr r0, _0216EBAC ; =PTR_LAB_overlay_0_0216ebb4_overlay_0_0217a86c
	str r2, [r4, #0x80]
	str r0, [r4, #0x7c]
	str r2, [r4, #0x88]
	str r2, [r4, #0x8c]
	ldr r1, _0216EBB0 ; =0xFFFFF556
	str r2, [r4, #0x6c]
	mov r0, r4
	str r1, [r4, #0x70]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216EBA0: .word ptr_FUN_overlay_0_0216ebbc_overlay_0_0217a9dc
_0216EBA4: .word PTR_LAB_overlay_0_0216ebb8_overlay_0_0217a858
_0216EBA8: .word _ZTV11CDrawObject+8
_0216EBAC: .word PTR_LAB_overlay_0_0216ebb4_overlay_0_0217a86c
_0216EBB0: .word 0xFFFFF556
	arm_func_end ov0_0216EB4C

	arm_func_start _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObjectD1Ev
_ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObjectD1Ev: ; 0x0216EBB4
	bx lr
	arm_func_end _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObjectD1Ev

	arm_func_start _ZN25CFieldEffectVolcanicSteam9CAnimatorD1Ev
_ZN25CFieldEffectVolcanicSteam9CAnimatorD1Ev: ; 0x0216EBB8
	bx lr
	arm_func_end _ZN25CFieldEffectVolcanicSteam9CAnimatorD1Ev

	arm_func_start _ZN25CFieldEffectVolcanicSteamD1Ev
_ZN25CFieldEffectVolcanicSteamD1Ev: ; 0x0216EBBC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov0_0216F300
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN25CFieldEffectVolcanicSteamD1Ev

	arm_func_start ov0_0216EBD0
ov0_0216EBD0: ; 0x0216EBD0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov0_0216F300
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216EBD0

	arm_func_start _ZN25CFieldEffectVolcanicSteam12ov0_02142398EP14DrawObjectList
_ZN25CFieldEffectVolcanicSteam12ov0_02142398EP14DrawObjectList: ; 0x0216EBEC
	ldr ip, _0216EBF8 ; =ov0_0216EC94
	add r0, r0, #0x78
	bx ip
	.align 2, 0
_0216EBF8: .word ov0_0216EC94
	arm_func_end _ZN25CFieldEffectVolcanicSteam12ov0_02142398EP14DrawObjectList

	arm_func_start _ZN25CFieldEffectVolcanicSteam8SetParamEii
_ZN25CFieldEffectVolcanicSteam8SetParamEii: ; 0x0216EBFC
	ldr ip, _0216EC10 ; =_ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE8SetParamEii
	cmp r1, #2
	moveq r3, r2, lsl #0xc
	streq r3, [r0, #0x80]
	bx ip
	.align 2, 0
_0216EC10: .word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE8SetParamEii
	arm_func_end _ZN25CFieldEffectVolcanicSteam8SetParamEii

	arm_func_start _ZN25CFieldEffectVolcanicSteam12ov0_02142344EP8Camera2D
_ZN25CFieldEffectVolcanicSteam12ov0_02142344EP8Camera2D: ; 0x0216EC14
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, [r0, #0x18]
	mov r6, r1
	str r2, [r0, #0x8c]
	ldr r5, [r0, #0x18]
	cmp r5, #0
	ldrne r4, [r5, #0x28]
	cmpne r4, #0
	beq _0216EC8C
	arm_func_end _ZN25CFieldEffectVolcanicSteam12ov0_02142344EP8Camera2D
_0216EC38:
	ldr r0, [r5, #0x30]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x5c]
	ldr r1, [r5]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x3c]
	ldr r3, [r4, #0x60]
	ldr r2, [r5, #4]
	mov r1, r6
	add r2, r3, r2
	str r2, [r4, #0x40]
	ldrsh r2, [r4, #0x6c]
	strh r2, [r4, #0x54]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x80]
	cmp r4, #0
	bne _0216EC38
_0216EC8C:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start ov0_0216EC94
ov0_0216EC94: ; 0x0216EC94
	ldr ip, _0216ECA8 ; =FUN_0200912C
	mov r2, r0
	mov r0, r1
	add r1, r2, #4
	bx ip
	.align 2, 0
_0216ECA8: .word _ZN14DrawObjectList6InsertEP11CDrawObject
	arm_func_end ov0_0216EC94

	arm_func_start _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject4DrawEP8Camera2Di
_ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject4DrawEP8Camera2Di: ; 0x0216ECAC
	str r2, [r0, #0xc]
	ldr r1, [r0, #0x10]
	cmp r1, #0
	ldrne r0, [r0, #0xc]
	strne r0, [r1, #0x30]
	mov r0, #1
	bx lr
	arm_func_end _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject4DrawEP8Camera2Di

	arm_func_start _ZN25CFieldEffectVolcanicSteam9CAnimator5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
_ZN25CFieldEffectVolcanicSteam9CAnimator5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi: ; 0x0216ECC8
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r1
	mov r0, #0
	str r0, [r6, #0x2c]
	str r0, [r6, #0x30]
	mov r0, #0x20000
	str r0, [r6, #0x34]
	str r0, [r6, #0x38]
	str r0, [r6, #0x4c]
	str r0, [r6, #0x50]
	ldr r5, [r6, #0x74]
	ldr r1, [r6, #0x70]
	ldr r0, _0216EDB4 ; =0x000014CD
	sub r4, r5, r1
	umull r3, r2, r4, r0
	mov r1, r4, asr #0x1f
	mla r2, r1, r0, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, r5
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r5, asr #0x1f
	bl _ll_div
	add r0, r0, #0x33
	add r2, r0, #0xb00
	mov r0, r2, asr #0x1f
	mov r0, r0, lsl #0xb
	mov r1, r2, lsl #0xb
	orr r0, r0, r2, lsr #21
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [r6, #0x44]
	str r1, [r6, #0x48]
	cmp r4, #0x1e000
	bge _0216ED84
	rsb r2, r4, r4, lsl #5
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r2, #0x1e000
	mov r3, #0
	bl _ll_div
	b _0216EDA8
	arm_func_end _ZN25CFieldEffectVolcanicSteam9CAnimator5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
_0216ED84:
	ldr r0, [r6, #0x70]
	sub r2, r5, #0x1e000
	rsb r3, r0, r0, lsl #5
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
_0216EDA8:
	mov r0, r0, asr #0xc
	str r0, [r6, #0x14]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0216EDB4: .word 0x000014CD

	arm_func_start _ZN32CFieldEffectVolcanicSteamFactoryD1Ev
_ZN32CFieldEffectVolcanicSteamFactoryD1Ev: ; 0x0216EDB8
	stmdb sp!, {r4, lr}
	ldr r1, _0216EDDC ; =ptr_FUN_overlay_0_0216edb8_overlay_0_0217a89c
	mov r4, r0
	str r1, [r4]
	bl ov0_0216EE9C
	add r0, r4, #4
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216EDDC: .word ptr_FUN_overlay_0_0216edb8_overlay_0_0217a89c
	arm_func_end _ZN32CFieldEffectVolcanicSteamFactoryD1Ev

	arm_func_start ov0_0216EDE0
ov0_0216EDE0: ; 0x0216EDE0
	stmdb sp!, {r4, lr}
	ldr r1, _0216EE0C ; =ptr_FUN_overlay_0_0216edb8_overlay_0_0217a89c
	mov r4, r0
	str r1, [r4]
	bl ov0_0216EE9C
	add r0, r4, #4
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216EE0C: .word ptr_FUN_overlay_0_0216edb8_overlay_0_0217a89c
	arm_func_end ov0_0216EDE0

	arm_func_start _ZN32CFieldEffectVolcanicSteamFactory5ResetEv
_ZN32CFieldEffectVolcanicSteamFactory5ResetEv: ; 0x0216EE10
	ldr ip, _0216EE18 ; =ov0_0216EE9C
	bx ip
	.align 2, 0
_0216EE18: .word ov0_0216EE9C
	arm_func_end _ZN32CFieldEffectVolcanicSteamFactory5ResetEv

	arm_func_start ov0_0216EE1C
ov0_0216EE1C: ; 0x0216EE1C
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x7c
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	mov r4, r0
	str ip, [sp, #8]
	ldr r1, _0216EE8C ; =DAT_overlay_0_0217aa44
	ldr r2, _0216EE90 ; =s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217aa48
	add r0, sp, #0x10
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r1, _0216EE94 ; =s_MEF_ef102_00_ntft_overlay_0_0217aa68
	ldr r2, _0216EE98 ; =s_MEF_ef102_00_ntfp_overlay_0_0217aa7c
	add r0, r4, #4
	mov r3, #0
	bl _ZN10NtfTexture4LoadEPKcS1_i
	mov r1, #2
	str r1, [r4, #0x24]
	str r1, [r4, #0x28]
	mov r1, #6
	add r0, sp, #0x10
	str r1, [r4, #0x20]
	bl _ZN13CArchiveGuardD1Ev
	mov r0, #0
	add sp, sp, #0x7c
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0216EE8C: .word DAT_overlay_0_0217aa44
_0216EE90: .word s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217aa48
_0216EE94: .word s_MEF_ef102_00_ntft_overlay_0_0217aa68
_0216EE98: .word s_MEF_ef102_00_ntfp_overlay_0_0217aa7c
	arm_func_end ov0_0216EE1C

	arm_func_start ov0_0216EE9C
ov0_0216EE9C: ; 0x0216EE9C
	ldr ip, _0216EEA8 ; =FUN_02036488
	add r0, r0, #4
	bx ip
	.align 2, 0
_0216EEA8: .word _ZN10NtfTexture7ReleaseEv
	arm_func_end ov0_0216EE9C

	arm_func_start _ZN32CFieldEffectVolcanicSteamFactory6CreateEi
_ZN32CFieldEffectVolcanicSteamFactory6CreateEi: ; 0x0216EEAC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r0, #0x90
	bl _Znwm
	movs r4, r0
	beq _0216EECC
	bl ov0_0216EB4C
	mov r4, r0
	arm_func_end _ZN32CFieldEffectVolcanicSteamFactory6CreateEi
_0216EECC:
	cmp r4, #0
	beq _0216EEF0
	add r1, r5, #4
	str r1, [sp]
	mov r0, r4
	ldr r2, [r0]
	add r1, sp, #0
	ldr r2, [r2, #0x5c]
	blx r2
_0216EEF0:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN25CFieldEffectVolcanicSteam13GetForceFieldEv
_ZN25CFieldEffectVolcanicSteam13GetForceFieldEv: ; 0x0216EEF8
	add r0, r0, #0x78
	bx lr
	arm_func_end _ZN25CFieldEffectVolcanicSteam13GetForceFieldEv

	arm_func_start _ZN25CFieldEffectVolcanicSteam11GetEffectIdEv
_ZN25CFieldEffectVolcanicSteam11GetEffectIdEv: ; 0x0216EF00
	mov r0, #0x19
	bx lr
	arm_func_end _ZN25CFieldEffectVolcanicSteam11GetEffectIdEv

	arm_func_start ov0_0216EF08
ov0_0216EF08: ; 0x0216EF08
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0216EFE4 ; =_ZTV12CFieldEffect+8
	mov r5, r0
	str r2, [r5]
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _0216EFE8 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r3, #0
	str r0, [r5]
	ldr r1, _0216EFEC ; =ptr_FUN_overlay_0_0216f490_overlay_0_0217a96c
	str r3, [r5, #0x1c]
	ldr r0, _0216EFF0 ; =PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c
	str r1, [r5]
	str r0, [r5, #0x20]
	str r3, [r5, #0x34]
	str r3, [r5, #0x24]
	str r3, [r5, #0x28]
	mov r1, #0x1000
	str r3, [r5, #0x2c]
	ldr r0, _0216EFF4 ; =PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4
	str r1, [r5, #0x30]
	str r0, [r5, #0x20]
	str r3, [r5, #0x48]
	str r3, [r5, #0x4c]
	str r1, [r5, #0x38]
	str r3, [r5, #0x3c]
	mov r0, #0x10
	str r3, [r5, #0x40]
	sub r2, r1, #0x2000
	ldr r1, _0216EFF8 ; =PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000
	str r2, [r5, #0x44]
	str r1, [r5, #0x20]
	str r3, [r5, #0x50]
	str r3, [r5, #0x54]
	str r4, [r5, #0x58]
	mov r1, #0xa
	str r1, [r5, #0x5c]
	mov r1, #0xf
	str r1, [r5, #0x60]
	str r0, [r5, #0x64]
	str r3, [r5, #0x68]
	str r3, [r5, #0x6c]
	sub r0, r0, #0x810
	str r0, [r5, #0x70]
	strb r3, [r5, #0x74]
	mov r0, #0x3c
	str r0, [r5, #0x5c]
	mov r0, #0x78
	str r0, [r5, #0x60]
	mov r1, #1
	mov r0, r5
	str r1, [r5, #0x68]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216EFE4: .word _ZTV12CFieldEffect+8
_0216EFE8: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216EFEC: .word ptr_FUN_overlay_0_0216f490_overlay_0_0217a96c
_0216EFF0: .word PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c
_0216EFF4: .word PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4
_0216EFF8: .word PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000
	arm_func_end ov0_0216EF08

	arm_func_start _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE8SetParamEii
_ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE8SetParamEii: ; 0x0216EFFC
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #8
	mov r0, #1
	addls pc, pc, r1, lsl #2
	b _0216F088
_0216F01C: ; jump table
	b _0216F088 ; case 0
	b _0216F088 ; case 1
	b _0216F088 ; case 2
	b _0216F058 ; case 3
	b _0216F068 ; case 4
	b _0216F040 ; case 5
	b _0216F04C ; case 6
	b _0216F088 ; case 7
	b _0216F078 ; case 8
	arm_func_end _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE8SetParamEii
_0216F040:
	add sp, sp, #4
	str r5, [r6, #0x54]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F04C:
	add sp, sp, #4
	str r5, [r6, #0x64]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F058:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x48]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F068:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x4c]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F078:
	str r5, [r6, #0x5c]
	add sp, sp, #4
	str r5, [r6, #0x60]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F088:
	cmp r1, #0
	mov r0, #0
	beq _0216F0AC
	cmp r1, #1
	beq _0216F2C0
	cmp r1, #2
	beq _0216F2D8
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F0AC:
	cmp r5, #0
	ble _0216F2B4
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _0216F128
	beq _0216F120
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0216F0DC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_0216F0DC:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0216F0F4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_0216F0F4:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0216F118
	ldr r3, _0216F2F0 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x20]
_0216F118:
	mov r0, r4
	bl _ZdlPv
_0216F120:
	mov r0, #0
	str r0, [r6, #0x18]
_0216F128:
	mov r0, #0x34
	bl _Znwm
	movs r4, r0
	beq _0216F258
	mov r0, #0x1000
	str r0, [r4, #8]
	mov r0, #1
	str r0, [r4, #0x14]
	mov r1, #0
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	str r5, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0216F1FC
	ldr r1, _0216F2F0 ; =ov0_0216AD48
	ldr r3, _0216F2F4 ; =ov0_0216AD5C
	str r1, [sp]
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _0216F1F0
	mov r1, lr
	mov ip, lr
	mov r2, #0x84
_0216F1A4:
	ldr r3, [r4, #0x20]
	add r5, r0, #1
	add r3, r3, r1
	str lr, [r3, #0x7c]
	ldr r3, [r4, #0x24]
	add r0, r0, #1
	cmp r5, r3
	ldrlo r3, [r4, #0x20]
	mlalo lr, r5, r2, r3
	ldr r3, [r4, #0x20]
	movhs lr, ip
	add r3, r3, r1
	str lr, [r3, #0x80]
	ldr r5, [r4, #0x20]
	ldr r3, [r4, #0x24]
	add lr, r5, r1
	cmp r0, r3
	add r1, r1, #0x84
	blo _0216F1A4
_0216F1F0:
	ldr r0, [r4, #0x20]
	str r0, [r4, #0x2c]
	b _0216F204
_0216F1FC:
	str r1, [r4, #0x20]
	str r1, [r4, #0x2c]
_0216F204:
	mov r1, #0
	str r1, [r4, #0x30]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _0216F24C
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x14]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x14]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x10]
_0216F24C:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_0216F258:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _0216F2B4
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0216F290
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0216F290:
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x60]
	blx r1
	ldr r1, [r6, #0x18]
	str r0, [r1, #0x1c]
	ldr r1, [r6, #0x1c]
	ldr r0, [r6, #0x18]
	str r1, [r0, #0x18]
_0216F2B4:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F2C0:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F2D8:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0216F2F0: .word ov0_0216AD48
_0216F2F4: .word ov0_0216AD5C

	arm_func_start _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE10GetEmitterEv
_ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE10GetEmitterEv: ; 0x0216F2F8
	add r0, r0, #0x20
	bx lr
	arm_func_end _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE10GetEmitterEv

	arm_func_start ov0_0216F300
ov0_0216F300: ; 0x0216F300
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216F3A4 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216F384
	beq _0216F37C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216F338
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end ov0_0216F300
_0216F338:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216F350
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216F350:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216F374
	ldr r3, _0216F3A8 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216F374:
	mov r0, r5
	bl _ZdlPv
_0216F37C:
	mov r0, #0
	str r0, [r4, #0x18]
_0216F384:
	ldr r1, _0216F3AC ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216F3A4: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216F3A8: .word ov0_0216AD48
_0216F3AC: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED0Ev
_ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED0Ev: ; 0x0216F3B0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216F45C ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216F434
	beq _0216F42C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216F3E8
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED0Ev
_0216F3E8:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216F400
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216F400:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216F424
	ldr r3, _0216F460 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216F424:
	mov r0, r5
	bl _ZdlPv
_0216F42C:
	mov r0, #0
	str r0, [r4, #0x18]
_0216F434:
	ldr r1, _0216F464 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216F45C: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216F460: .word ov0_0216AD48
_0216F464: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216F468
ov0_0216F468: ; 0x0216F468
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216F468

	arm_func_start ov0_0216F47C
ov0_0216F47C: ; 0x0216F47C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216F47C

	arm_func_start _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED1Ev
_ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED1Ev: ; 0x0216F490
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216F534 ; =ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216F514
	beq _0216F50C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216F4C8
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED1Ev
_0216F4C8:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216F4E0
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216F4E0:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	beq _0216F504
	ldr r3, _0216F538 ; =ov0_0216AD48
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x20]
_0216F504:
	mov r0, r5
	bl _ZdlPv
_0216F50C:
	mov r0, #0
	str r0, [r4, #0x18]
_0216F514:
	ldr r1, _0216F53C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216F534: .word ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
_0216F538: .word ov0_0216AD48
_0216F53C: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216F540
ov0_0216F540: ; 0x0216F540
	stmdb sp!, {r4, lr}
	ldr r1, _0216F620 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _0216F624 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r1, #0
	str r0, [r4]
	str r1, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r2, _0216F628 ; =ptr_FUN_overlay_0_0216f648_overlay_0_0217abac
	str r1, [r4, #0x24]
	ldr r0, _0216F62C ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r2, [r4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x3c]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	mov r2, #0x1000
	str r1, [r4, #0x34]
	ldr r0, _0216F630 ; =_ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
	str r2, [r4, #0x38]
	str r0, [r4, #0x28]
	str r1, [r4, #0x50]
	str r1, [r4, #0x54]
	str r2, [r4, #0x40]
	str r1, [r4, #0x44]
	mov r0, #0x10
	str r1, [r4, #0x48]
	sub r3, r2, #0x2000
	ldr r2, _0216F634 ; =_ZTV30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE+8
	str r3, [r4, #0x4c]
	str r2, [r4, #0x28]
	str r1, [r4, #0x58]
	str r1, [r4, #0x5c]
	str r1, [r4, #0x60]
	mov r2, #0xa
	str r2, [r4, #0x64]
	mov r2, #0xf
	str r2, [r4, #0x68]
	str r0, [r4, #0x6c]
	str r1, [r4, #0x70]
	str r1, [r4, #0x74]
	sub r0, r0, #0x810
	str r0, [r4, #0x78]
	ldr r2, _0216F638 ; =PTR_LAB_overlay_0_0216f640_overlay_0_0217ab18
	strb r1, [r4, #0x7c]
	ldr r0, _0216F63C ; =PTR_LAB_overlay_0_0216f644_overlay_0_0217aac8
	str r2, [r4, #0x28]
	str r0, [r4, #0x84]
	str r1, [r4, #0x88]
	mov r0, r4
	str r1, [r4, #0x8c]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216F620: .word _ZTV12CFieldEffect+8
_0216F624: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0216F628: .word ptr_FUN_overlay_0_0216f648_overlay_0_0217abac
_0216F62C: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_0216F630: .word _ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
_0216F634: .word _ZTV30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE+8
_0216F638: .word PTR_LAB_overlay_0_0216f640_overlay_0_0217ab18
_0216F63C: .word PTR_LAB_overlay_0_0216f644_overlay_0_0217aac8
	arm_func_end ov0_0216F540

	arm_func_start _ZN23CFieldEffectFuwanteWind8CEmitterD1Ev
_ZN23CFieldEffectFuwanteWind8CEmitterD1Ev: ; 0x0216F640
	bx lr
	arm_func_end _ZN23CFieldEffectFuwanteWind8CEmitterD1Ev

	arm_func_start _ZN23CFieldEffectFuwanteWind9CAnimatorD1Ev
_ZN23CFieldEffectFuwanteWind9CAnimatorD1Ev: ; 0x0216F644
	bx lr
	arm_func_end _ZN23CFieldEffectFuwanteWind9CAnimatorD1Ev

	arm_func_start _ZN23CFieldEffectFuwanteWindD1Ev
_ZN23CFieldEffectFuwanteWindD1Ev: ; 0x0216F648
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216F6EC ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216F6CC
	beq _0216F6C4
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216F680
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN23CFieldEffectFuwanteWindD1Ev
_0216F680:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216F698
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216F698:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _0216F6BC
	ldr r3, _0216F6F0 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_0216F6BC:
	mov r0, r5
	bl _ZdlPv
_0216F6C4:
	mov r0, #0
	str r0, [r4, #0x18]
_0216F6CC:
	ldr r1, _0216F6F4 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216F6EC: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0216F6F0: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0216F6F4: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0216F6F8
ov0_0216F6F8: ; 0x0216F6F8
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0216F7A4 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216F77C
	beq _0216F774
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216F730
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end ov0_0216F6F8
_0216F730:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0216F748
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0216F748:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _0216F76C
	ldr r3, _0216F7A8 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_0216F76C:
	mov r0, r5
	bl _ZdlPv
_0216F774:
	mov r0, #0
	str r0, [r4, #0x18]
_0216F77C:
	ldr r1, _0216F7AC ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216F7A4: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0216F7A8: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0216F7AC: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN23CFieldEffectFuwanteWind8SetParamEii
_ZN23CFieldEffectFuwanteWind8SetParamEii: ; 0x0216F7B0
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #8
	mov r0, #1
	bgt _0216F7FC
	cmp r1, #0
	addge pc, pc, r1, lsl #2
	b _0216F858
_0216F7D8: ; jump table
	b _0216F858 ; case 0
	b _0216F858 ; case 1
	b _0216F858 ; case 2
	b _0216F828 ; case 3
	b _0216F838 ; case 4
	b _0216F810 ; case 5
	b _0216F81C ; case 6
	b _0216F858 ; case 7
	b _0216F848 ; case 8
	arm_func_end _ZN23CFieldEffectFuwanteWind8SetParamEii
_0216F7FC:
	cmp r1, #0x17
	bne _0216F858
	add sp, sp, #4
	str r5, [r6, #0x80]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F810:
	add sp, sp, #4
	str r5, [r6, #0x5c]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F81C:
	add sp, sp, #4
	str r5, [r6, #0x6c]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F828:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x50]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F838:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x54]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F848:
	str r5, [r6, #0x64]
	add sp, sp, #4
	str r5, [r6, #0x68]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F858:
	cmp r1, #0
	mov r0, #0
	beq _0216F87C
	cmp r1, #1
	beq _0216FAA8
	cmp r1, #2
	beq _0216FAC0
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216F87C:
	cmp r5, #0
	ble _0216FA9C
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _0216F8F8
	beq _0216F8F0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0216F8AC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_0216F8AC:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0216F8C4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_0216F8C4:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _0216F8E8
	ldr r3, _0216FAD8 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x28]
_0216F8E8:
	mov r0, r4
	bl _ZdlPv
_0216F8F0:
	mov r0, #0
	str r0, [r6, #0x18]
_0216F8F8:
	mov r0, #0x3c
	bl _Znwm
	movs r4, r0
	beq _0216FA30
	mov r0, #0x1000
	str r0, [r4, #8]
	mov r0, #1
	str r0, [r4, #0x14]
	mov r1, #0
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	str r1, [r4, #0x20]
	str r1, [r4, #0x24]
	str r5, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0216F9D4
	ldr r1, _0216FAD8 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _0216FADC ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _0216F9C8
	mov r1, lr
	mov ip, lr
	mov r2, #0x74
_0216F97C:
	ldr r3, [r4, #0x28]
	add r5, r0, #1
	add r3, r3, r1
	str lr, [r3, #0x6c]
	ldr r3, [r4, #0x2c]
	add r0, r0, #1
	cmp r5, r3
	ldrlo r3, [r4, #0x28]
	mlalo lr, r5, r2, r3
	ldr r3, [r4, #0x28]
	movhs lr, ip
	add r3, r3, r1
	str lr, [r3, #0x70]
	ldr r5, [r4, #0x28]
	ldr r3, [r4, #0x2c]
	add lr, r5, r1
	cmp r0, r3
	add r1, r1, #0x74
	blo _0216F97C
_0216F9C8:
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x34]
	b _0216F9DC
_0216F9D4:
	str r1, [r4, #0x28]
	str r1, [r4, #0x34]
_0216F9DC:
	mov r1, #0
	str r1, [r4, #0x38]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _0216FA24
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x14]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x14]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x10]
_0216FA24:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_0216FA30:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _0216FA9C
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0216FA68
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0216FA68:
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x60]
	blx r1
	ldr r1, [r6, #0x18]
	str r0, [r1, #0x24]
	ldr r1, [r6, #0x18]
	ldr r0, [r6, #0x1c]
	str r0, [r1, #0x18]
	ldr r0, [r6, #0x20]
	str r0, [r1, #0x1c]
	ldr r0, [r6, #0x24]
	str r0, [r1, #0x20]
_0216FA9C:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216FAA8:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216FAC0:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0216FAD8: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0216FADC: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev

	arm_func_start _ZN23CFieldEffectFuwanteWind12ov0_02142344EP8Camera2D
_ZN23CFieldEffectFuwanteWind12ov0_02142344EP8Camera2D: ; 0x0216FAE0
	stmdb sp!, {r4, r5, r6, lr}
	ldr r5, [r0, #0x18]
	mov r6, r1
	cmp r5, #0
	ldrne r4, [r5, #0x30]
	cmpne r4, #0
	beq _0216FB50
	arm_func_end _ZN23CFieldEffectFuwanteWind12ov0_02142344EP8Camera2D
_0216FAFC:
	ldr r0, [r5, #0x38]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x4c]
	ldr r1, [r5]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x18]
	ldr r3, [r4, #0x50]
	ldr r2, [r5, #4]
	mov r1, r6
	add r2, r3, r2
	str r2, [r4, #0x1c]
	ldrsh r2, [r4, #0x5c]
	strh r2, [r4, #0x28]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x70]
	cmp r4, #0
	bne _0216FAFC
_0216FB50:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN23CFieldEffectFuwanteWind8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN23CFieldEffectFuwanteWind8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x0216FB58
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr lr, _0216FC6C ; =MAIN_BSS_0210CEC8
	ldr r3, [r0, #0x28]
	ldmia lr, {r2, r4, r5}
	mla r6, r4, r2, r5
	mla r5, r4, r6, r5
	mov r2, r6, lsr #0x10
	ldr ip, _0216FC70 ; =0x00007FFF
	mov r2, r2, lsl #0x10
	str r6, [lr]
	and r6, ip, r2, lsr #16
	mov r4, r5, lsr #0x10
	mov r2, r4, lsl #0x10
	and r4, ip, r2, lsr #16
	mov r6, r6, asr #3
	smull ip, r7, r6, r3
	ldr r2, [r0, #0x2c]
	mov r4, r4, asr #3
	adds r6, ip, #0x800
	str r5, [lr]
	smull lr, ip, r4, r2
	adc r4, r7, #0
	mov r5, r6, lsr #0xc
	orr r5, r5, r4, lsl #20
	adds lr, lr, #0x800
	adc r4, ip, #0
	mov ip, lr, lsr #0xc
	orr ip, ip, r4, lsl #20
	sub r5, r5, r3, asr #1
	sub r3, ip, r2, asr #1
	ldmib r0, {r4, lr}
	add r2, r4, r5
	str r2, [r1, #0x4c]
	add r2, lr, r3
	str r2, [r1, #0x50]
	ldr r3, [r0, #0x3c]
	mov r2, #0
	mov r3, r3, lsl #0xc
	str r3, [r1, #0x60]
	str r3, [r1, #0x64]
	ldrb r4, [r0, #0x54]
	mov ip, #0x18
	mov r3, #0x800
	add lr, r4, #1
	strb lr, [r0, #0x54]
	add lr, r4, #8
	str lr, [r1, #0x10]
	ldrb lr, [r0, #0x54]
	ldr r4, _0216FC74 ; =0x00000355
	and lr, lr, #0x1f
	strb lr, [r0, #0x54]
	strh r2, [r1, #0x5e]
	str ip, [r1, #0x14]
	str r3, [r1, #0x20]
	str r3, [r1, #0x24]
	ldr r3, [r0, #0x58]
	cmp r3, #0
	ldrb r3, [r0, #0x54]
	rsbeq r4, r4, #0
	ldr r0, _0216FC78 ; =0xFFFFF889
	str r4, [r1, #0x54]
	str r0, [r1, #0x58]
	movne r2, #2
	mov r3, r3, lsl #0x1e
	orr r2, r2, r3, lsr #14
	str r2, [r1, #0x68]
	mov r0, r0, asr #0xb
	str r0, [r1, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0216FC6C: .word MAIN_BSS_0210CEC8
_0216FC70: .word 0x00007FFF
_0216FC74: .word 0x00000355
_0216FC78: .word 0xFFFFF889
	arm_func_end _ZN23CFieldEffectFuwanteWind8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

	arm_func_start _ZN23CFieldEffectFuwanteWind9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN23CFieldEffectFuwanteWind9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x0216FC7C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r4, r1
	ldr r2, [r4, #0x64]
	ldr r1, [r4, #0x60]
	mov r5, r0
	sub r6, r2, r1
	mov r0, r6, asr #0x1f
	mov r0, r0, lsl #0xc
	mov r1, r6, lsl #0xc
	orr r0, r0, r6, lsr #20
	mov r3, r1, lsr #0xc
	orr r3, r3, r0, lsl #20
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	add r0, r0, #0x800
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	cmp r6, #0xd2000
	movlt r0, #0x18
	strlt r0, [r4, #0x14]
	blt _0216FD40
	cmp r6, #0xf0000
	movge r0, #0
	strge r0, [r4, #0x14]
	bge _0216FD40
	mov r0, #0x18000
	sub r2, r6, #0xd2000
	rsb r0, r0, #0
	mvn r1, #0
	umull r7, r3, r2, r0
	mla r3, r2, r1, r3
	mov r1, r2, asr #0x1f
	mla r3, r1, r0, r3
	mov r2, r7, lsr #0xc
	orr r2, r2, r3, lsl #20
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r2, #0x1e000
	mov r3, #0
	bl _ll_div
	add r0, r0, #0x18000
	mov r0, r0, asr #0xc
	str r0, [r4, #0x14]
	arm_func_end _ZN23CFieldEffectFuwanteWind9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_0216FD40:
	bl _ZN5CGame11GetInstanceEv
	ldr lr, [r4, #0x68]
	cmp r6, #0x78000
	mov r6, lr, lsr #0x10
	blt _0216FE10
	tst lr, #1
	bne _0216FE10
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr r7, [r2, #0x448]
	ldmib r1, {r3, r8}
	umull ip, sb, r8, r7
	mla sb, r8, r3, sb
	ldr r3, [r1, #0xc]
	ldr r8, [r1, #0x10]
	mla sb, r3, r7, sb
	ldr r3, [r1, #0x14]
	adds r8, r8, ip
	str r8, [r2, #0x448]
	adc r7, r3, sb
	ldr r2, _0216FE3C ; =0x00000333
	str r7, [r1, #4]
	umull r2, r3, r7, r2
	add r7, r0, #0x1000
	add r2, r3, #0x3bc
	add r1, r0, #0x48
	tst lr, #2
	add ip, r2, #0x800
	add r3, r1, #0x1400
	ldr r8, [r7, #0x448]
	ldmib r3, {r2, sb}
	umull r1, r0, sb, r8
	mla r0, sb, r2, r0
	ldr sb, [r3, #0xc]
	ldr r2, [r3, #0x10]
	mla r0, sb, r8, r0
	rsbeq ip, ip, #0
	ldr r8, [r3, #0x14]
	adds r1, r2, r1
	adc r2, r8, r0
	str r1, [r7, #0x448]
	ldr r0, _0216FE3C ; =0x00000333
	str r2, [r3, #4]
	umull r0, r1, r2, r0
	mvn r0, #0x198
	bic lr, lr, #1
	str ip, [r4, #0x54]
	add r0, r1, r0
	str r0, [r4, #0x58]
	orr r0, lr, #1
	str r0, [r4, #0x68]
_0216FE10:
	ldr r1, [r5, #8]
	cmp r1, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	cmp r6, #3
	ldmgeia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r0, r6, lsl #1
	ldrh r1, [r1, r0]
	ldr r0, [r5, #4]
	bl _ZN18CellAnimController7GetCellEt
	strh r0, [r4, #0x2a]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0216FE3C: .word 0x00000333

	arm_func_start _ZN30CFieldEffectFuwanteWindFactoryD1Ev
_ZN30CFieldEffectFuwanteWindFactoryD1Ev: ; 0x0216FE40
	stmdb sp!, {r4, lr}
	ldr r1, _0216FE64 ; =ptr_FUN_overlay_0_0216fe40_overlay_0_0217aaf8
	mov r4, r0
	str r1, [r4]
	bl ov0_0216FF58
	add r0, r4, #4
	bl _ZN16CEffectActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216FE64: .word ptr_FUN_overlay_0_0216fe40_overlay_0_0217aaf8
	arm_func_end _ZN30CFieldEffectFuwanteWindFactoryD1Ev

	arm_func_start ov0_0216FE68
ov0_0216FE68: ; 0x0216FE68
	stmdb sp!, {r4, lr}
	ldr r1, _0216FE94 ; =ptr_FUN_overlay_0_0216fe40_overlay_0_0217aaf8
	mov r4, r0
	str r1, [r4]
	bl ov0_0216FF58
	add r0, r4, #4
	bl _ZN16CEffectActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216FE94: .word ptr_FUN_overlay_0_0216fe40_overlay_0_0217aaf8
	arm_func_end ov0_0216FE68

	arm_func_start _ZN30CFieldEffectFuwanteWindFactory5ResetEv
_ZN30CFieldEffectFuwanteWindFactory5ResetEv: ; 0x0216FE98
	ldr ip, _0216FEA0 ; =ov0_0216FF58
	bx ip
	.align 2, 0
_0216FEA0: .word ov0_0216FF58
	arm_func_end _ZN30CFieldEffectFuwanteWindFactory5ResetEv

	arm_func_start ov0_0216FEA4
ov0_0216FEA4: ; 0x0216FEA4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	mov sb, r0
	add r0, sb, #4
	mov r1, #0x69
	mov r2, #1
	bl _ZN27CFieldEffectNormalActorData12ov0_021503B8Eii
	ldr r0, [sb, #0x38]
	cmp r0, #0
	beq _0216FED4
	bl _ZdaPv
	mov r0, #0
	str r0, [sb, #0x38]
	arm_func_end ov0_0216FEA4
_0216FED4:
	add r0, sb, #4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	movs r6, r0
	beq _0216FF50
	mov r0, #6
	bl _Znam
	str r0, [sb, #0x38]
	mov r7, #0
	mov r0, #6
	sub sl, r0, #1
	mov r5, #1
	mov r4, r7
_0216FF10:
	mov r0, r6
	mov r1, r5
	mov r2, r4
	bl _ZN18CellAnimController6CreateEmm
	ldr r2, [sb, #0x38]
	mov r1, r7, lsl #1
	mov r8, sl
	strh r0, [r2, r1]
_0216FF30:
	mov r0, r6
	bl _ZN18CellAnimController9UpdateAllEv
	cmp r8, #0
	sub r8, r8, #1
	bne _0216FF30
	add r7, r7, #1
	cmp r7, #3
	blt _0216FF10
_0216FF50:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start ov0_0216FF58
ov0_0216FF58: ; 0x0216FF58
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _0216FFB4
	add r0, r4, #4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	movs r5, r0
	beq _0216FFB4
	mov r6, #0
	arm_func_end ov0_0216FF58
_0216FF8C:
	ldr r1, [r4, #0x38]
	mov r0, r6, lsl #1
	ldrh r1, [r1, r0]
	cmp r1, #0
	beq _0216FFA8
	mov r0, r5
	bl _ZN18CellAnimController6RemoveEt
_0216FFA8:
	add r6, r6, #1
	cmp r6, #3
	blt _0216FF8C
_0216FFB4:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _0216FFCC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x38]
_0216FFCC:
	add r0, r4, #4
	bl _ZN16CEffectActorData7ReleaseEv
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN30CFieldEffectFuwanteWindFactory6CreateEi
_ZN30CFieldEffectFuwanteWindFactory6CreateEi: ; 0x0216FFD8
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	mov r5, r0
	mov r0, #0x90
	bl _Znwm
	movs r4, r0
	beq _0216FFFC
	bl ov0_0216F540
	mov r4, r0
	arm_func_end _ZN30CFieldEffectFuwanteWindFactory6CreateEi
_0216FFFC:
	cmp r4, #0
	beq _02170084
	add r0, r5, #4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r7, r0
	add r0, r5, #4
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r6, r0
	add r0, r5, #4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	str r0, [sp]
	mov r0, r4
	str r6, [sp, #4]
	str r7, [sp, #8]
	ldr r2, [r0]
	add r1, sp, #0
	ldr r2, [r2, #0x5c]
	blx r2
	add r0, r5, #4
	ldr r2, [r0]
	ldr r6, [r5, #0x38]
	ldr r2, [r2, #0x10]
	mov r1, #0
	blx r2
	str r0, [r4, #0x88]
	str r6, [r4, #0x8c]
_02170084:
	mov r0, r4
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}

	arm_func_start _ZN30CFieldEffectFuwanteWindFactory6UpdateEi
_ZN30CFieldEffectFuwanteWindFactory6UpdateEi: ; 0x02170090
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #4]!
	ldr r1, [r1, #0x18]
	blx r1
	ldmia sp!, {r3, pc}
	arm_func_end _ZN30CFieldEffectFuwanteWindFactory6UpdateEi

	arm_func_start _ZN23CFieldEffectFuwanteWind13GetForceFieldEv
_ZN23CFieldEffectFuwanteWind13GetForceFieldEv: ; 0x021700A4
	add r0, r0, #0x84
	bx lr
	arm_func_end _ZN23CFieldEffectFuwanteWind13GetForceFieldEv

	arm_func_start _ZN23CFieldEffectFuwanteWind10GetEmitterEv
_ZN23CFieldEffectFuwanteWind10GetEmitterEv: ; 0x021700AC
	add r0, r0, #0x28
	bx lr
	arm_func_end _ZN23CFieldEffectFuwanteWind10GetEmitterEv

	arm_func_start _ZN23CFieldEffectFuwanteWind11GetEffectIdEv
_ZN23CFieldEffectFuwanteWind11GetEffectIdEv: ; 0x021700B4
	mov r0, #0x1a
	bx lr
	arm_func_end _ZN23CFieldEffectFuwanteWind11GetEffectIdEv

	arm_func_start ov0_021700BC
ov0_021700BC: ; 0x021700BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_021700BC

	arm_func_start ov0_021700D0
ov0_021700D0: ; 0x021700D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_021700D0

	arm_func_start _ZN24CFieldEffectManpuDarkrieC1EPN18CFieldEffectManage17CResidentResourceEP12AnimSlotPoolii
_ZN24CFieldEffectManpuDarkrieC1EPN18CFieldEffectManage17CResidentResourceEP12AnimSlotPoolii: ; 0x021700E4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	ldr r4, _021702BC ; =_ZTV12CFieldEffect+8
	mov r6, r0
	str r4, [r6]
	ldr r5, [r0]
	mov r7, r1
	ldr r5, [r5, #0x14]
	mov r4, r2
	str r3, [sp, #4]
	blx r5
	ldr r0, _021702C0 ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [r6]
	ldr r0, _021702C4 ; =_ZTV17CFieldEffectManpu+8
	str r7, [r6, #0x18]
	str r0, [r6]
	str r1, [r6, #0x1c]
	strb r1, [r6, #0x20]
	sub r0, r1, #1
	str r0, [r6, #0x24]
	str r1, [r6, #0x28]
	ldr r0, _021702C8 ; =ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44
	ldr r1, _021702CC ; =_ZN15CSoftwareSpriteD1Ev
	str r0, [r6]
	str r1, [sp]
	ldr r3, _021702D0 ; =FUN_02005150
	add r0, r6, #0x2c
	mov r1, #5
	mov r2, #0x4c
	bl __cxa_vec_ctor
	ldr r0, _021702D4 ; =0x000002AA
	str r4, [r6, #0x1b4]
	str r0, [r6, #0x1c4]
	mov r0, #0
	strb r0, [r6, #0x1d2]
	mov r1, #0x10
	strb r1, [r6, #0x1d3]
	mov r1, #1
	str r1, [r6, #0x28]
	ldr r1, [sp, #4]
	mov r0, r6
	bl ov0_021706FC
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x48
	mov r4, #0
	add r5, r0, #0x1400
	mov fp, r4
	mov r7, #3
	arm_func_end _ZN24CFieldEffectManpuDarkrieC1EPN18CFieldEffectManage17CResidentResourceEP12AnimSlotPoolii
_021701A8:
	ldr r0, [r6, #0x1b4]
	bl _ZN12AnimSlotPool7AcquireEv
	add r1, r6, r4, lsl #1
	add r1, r1, #0x100
	strh r0, [r1, #0xa8]
	ldr r1, [r5]
	ldmib r5, {r0, r2}
	umull r8, r3, r2, r1
	mla r3, r2, r0, r3
	ldr r0, [r5, #0xc]
	ldr sb, [r5, #0x10]
	mla r3, r0, r1, r3
	add sl, r6, r4
	ldr r2, [r5, #0x14]
	adds r8, sb, r8
	adc r1, r2, r3
	str r8, [r5]
	mov r0, fp, lsl #4
	str r1, [r5, #4]
	orr r0, r0, r1, lsr #28
	strb r0, [sl, #0x1c8]
	ldr r1, [r5]
	ldmib r5, {r0, r3}
	umull lr, ip, r3, r1
	mla ip, r3, r0, ip
	ldr r2, [r5, #0xc]
	ldr sb, [r5, #0x10]
	mla ip, r2, r1, ip
	ldr r8, [r5, #0x14]
	adds r0, sb, lr
	adc r2, r8, ip
	stmia r5, {r0, r2}
	umull r0, r1, r2, r7
	add r4, r4, #1
	cmp r4, #5
	strb r1, [sl, #0x1cd]
	blt _021701A8
	ldr r0, [r6, #0x18]
	cmp r0, #0
	beq _021702A4
	ldr r2, [r0]
	ldr r1, [sp, #4]
	ldr r2, [r2, #0x10]
	blx r2
	movs r5, r0
	beq _021702A4
	mov r7, #0
	mov sb, r7
_02170268:
	cmp sb, #0
	sub r8, sb, #1
	beq _02170294
	add r0, r6, r7, lsl #1
	add r4, r0, #0x100
_0217027C:
	ldrh r1, [r4, #0xa8]
	mov r0, r5
	bl _ZN18CellAnimController6UpdateEt
	cmp r8, #0
	sub r8, r8, #1
	bne _0217027C
_02170294:
	add r7, r7, #1
	cmp r7, #5
	add sb, sb, #0x1e
	blt _02170268
_021702A4:
	mov r1, #0
	str r1, [r6, #0x1c0]
	mov r0, r6
	str r1, [r6, #0x1bc]
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_021702BC: .word _ZTV12CFieldEffect+8
_021702C0: .word _ZTV17CFieldEffectActor+8
_021702C4: .word _ZTV17CFieldEffectManpu+8
_021702C8: .word ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44
_021702CC: .word _ZN15CSoftwareSpriteD1Ev
_021702D0: .word _ZN15CSoftwareSpriteC1Ev
_021702D4: .word 0x000002AA

	arm_func_start _ZN24CFieldEffectManpuDarkrieD1Ev
_ZN24CFieldEffectManpuDarkrieD1Ev: ; 0x021702D8
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02170330 ; =ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44
	mov r5, r0
	str r1, [r5]
	mov r4, #0
	arm_func_end _ZN24CFieldEffectManpuDarkrieD1Ev
_021702EC:
	add r0, r5, r4, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0xa8]
	ldr r0, [r5, #0x1b4]
	bl _ZN12AnimSlotPool4FreeEt
	add r4, r4, #1
	cmp r4, #5
	blt _021702EC
	ldr r3, _02170334 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r5, #0x2c
	mov r1, #5
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	mov r0, r5
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02170330: .word ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44
_02170334: .word _ZN15CSoftwareSpriteD1Ev

	arm_func_start ov0_02170338
ov0_02170338: ; 0x02170338
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02170398 ; =ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44
	mov r5, r0
	str r1, [r5]
	mov r4, #0
	arm_func_end ov0_02170338
_0217034C:
	add r0, r5, r4, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0xa8]
	ldr r0, [r5, #0x1b4]
	bl _ZN12AnimSlotPool4FreeEt
	add r4, r4, #1
	cmp r4, #5
	blt _0217034C
	ldr r3, _0217039C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r5, #0x2c
	mov r1, #5
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	mov r0, r5
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r5
	bl _ZN17CFieldEffectManpudlEPv
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02170398: .word ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44
_0217039C: .word _ZN15CSoftwareSpriteD1Ev

	arm_func_start _ZN24CFieldEffectManpuDarkrie12ov0_02142264Ei
_ZN24CFieldEffectManpuDarkrie12ov0_02142264Ei: ; 0x021703A0
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	mov r7, r1
	bl ov0_02170438
	mov r0, r8
	mov r1, r7
	bl ov0_02170608
	ldr r0, [r8, #0x18]
	ldr r1, [r8, #0x1b8]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	mov r4, r0
	mov r6, r8
	mov r5, #0
	arm_func_end _ZN24CFieldEffectManpuDarkrie12ov0_02142264Ei
_021703DC:
	cmp r4, #0
	beq _02170418
	add r0, r8, r5, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0xa8]
	cmp r1, #0
	beq _02170418
	mov r0, r4
	bl _ZN18CellAnimController6UpdateEt
	add r0, r8, r5, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0xa8]
	mov r0, r4
	bl _ZN18CellAnimController7GetCellEt
	strh r0, [r6, #0x56]
_02170418:
	add r5, r5, #1
	cmp r5, #5
	add r6, r6, #0x4c
	blt _021703DC
	mov r0, r8
	mov r1, r7
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov0_02170438
ov0_02170438: ; 0x02170438
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x68
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	addeq sp, sp, #0x68
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r3, [r0, #0x1c0]
	ldr r2, [r0, #0x1c4]
	mla r3, r2, r1, r3
	str r3, [r0, #0x1c0]
	cmp r3, #0x2000
	mov r1, #0x2000
	blt _02170480
	str r1, [r0, #0x1c0]
	ldr r1, [r0, #0x1c4]
	rsb r1, r1, #0
	str r1, [r0, #0x1c4]
	b _0217049C
	arm_func_end ov0_02170438
_02170480:
	rsb r1, r1, #0
	cmp r3, r1
	bgt _0217049C
	str r1, [r0, #0x1c0]
	ldr r1, [r0, #0x1c4]
	rsb r1, r1, #0
	str r1, [r0, #0x1c4]
_0217049C:
	mov lr, #0
	ldr fp, _02170604 ; =DAT_overlay_0_02172f48
	mov r5, r0
	add ip, sp, #0x20
	mov r3, lr
	add r4, sp, #8
	add r2, sp, #0x28
	mov r1, lr
_021704BC:
	ldr sl, [r0, #0x1c]
	ldr r6, [sl, #8]
	cmp r6, #0
	beq _02170500
	ldr r6, [r6, #0xc]
	cmp r6, #0
	beq _021704EC
	ldr r7, [r6, #0x20]
	ldr r6, [r6, #0x24]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	b _02170510
_021704EC:
	str r3, [ip]
	str r3, [ip, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	b _02170510
_02170500:
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
_02170510:
	ldr sb, [r4]
	ldr r8, [r4, #4]
	str sb, [sp, #0x10]
	str r8, [sp, #0x14]
	ldr r7, [sl, #0x70]
	ldr r6, [sl, #0x74]
	add r7, r7, sb
	add r8, r6, r8
	ldr r6, [sl, #8]
	str r7, [sp, #0x18]
	str r7, [sp]
	str r8, [sp, #0x1c]
	str r8, [sp, #4]
	cmp r6, #0
	beq _02170574
	ldr r8, [r6, #0xc]
	cmp r8, #0
	moveq sl, #0
	beq _02170578
	ldr r7, [r8, #0x8c]
	ldr r6, [r8, #0xa0]
	ldr r8, [r8, #0xb0]
	add r6, r7, r6
	add sl, r8, r6
	b _02170578
_02170574:
	mov sl, #0
_02170578:
	add r6, fp, lr, lsl #3
	ldr r7, [fp, lr, lsl #3]
	ldr r6, [r6, #4]
	str r7, [sp, #0x50]
	str r6, [sp, #0x54]
	ldr sb, [sp, #4]
	ldr r8, [sp]
	sub sb, sb, sl
	add r7, r8, r7
	str r8, [sp, #0x58]
	add r6, sb, r6
	str sb, [sp, #4]
	str sb, [sp, #0x5c]
	ldr r8, [r0, #0x1bc]
	str r7, [sp, #0x48]
	str r8, [sp, #0x40]
	add r8, r7, r8
	str r7, [sp, #0x60]
	ldr r7, [r0, #0x1c0]
	str r6, [sp, #0x4c]
	str r7, [sp, #0x44]
	add r7, r6, r7
	str r6, [sp, #0x64]
	str r8, [r5, #0x44]
	add lr, lr, #1
	str r8, [sp, #0x38]
	str r8, [sp, #0x30]
	str r7, [r5, #0x48]
	str r7, [sp, #0x3c]
	str r7, [sp, #0x34]
	cmp lr, #5
	add r5, r5, #0x4c
	blt _021704BC
	add sp, sp, #0x68
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02170604: .word DAT_overlay_0_02172f48

	arm_func_start ov0_02170608
ov0_02170608: ; 0x02170608
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov ip, r0
	mov r8, #0
	arm_func_end ov0_02170608
_02170614:
	add r7, r0, r8
	ldrb r4, [r0, #0x1d2]
	ldrb r3, [r7, #0x1cd]
	ldrb r6, [r7, #0x1c8]
	add r2, r4, #3
	add r3, r4, r3
	and r5, r3, #0xff
	add r3, r5, #1
	and sb, r3, #0xff
	cmp sb, r2
	movge sb, r4
	add r3, r5, r5, lsl #1
	ldr r4, _021706F8 ; =DAT_overlay_0_02172f3c
	add r2, sb, sb, lsl #1
	add lr, r4, r3
	add r5, sp, #0
	add r4, r4, r2
	mov r3, #0
_0217065C:
	ldrb r2, [lr], #1
	ldrb sb, [r4], #1
	add r3, r3, #1
	cmp r3, #3
	sub sb, sb, r2
	mul sb, r6, sb
	add r2, r2, sb, asr #4
	strb r2, [r5], #1
	blt _0217065C
	ldrb r3, [sp]
	ldrb r2, [sp, #1]
	ldrb r5, [sp, #2]
	add r4, r0, r8
	orr r2, r3, r2, lsl #5
	orr r2, r2, r5, lsl #10
	strh r2, [ip, #0x34]
	ldrb r2, [r4, #0x1c8]
	add r3, r2, r1
	strb r3, [r4, #0x1c8]
	ldrb r2, [r0, #0x1d3]
	and r3, r3, #0xff
	cmp r3, r2
	blo _021706E4
	ldrb r2, [r4, #0x1cd]
	add r3, r2, #1
	and r2, r3, #0xff
	cmp r2, #3
	strb r3, [r4, #0x1cd]
	movhs r2, #0
	strcsb r2, [r7, #0x1cd]
	ldrb r3, [r7, #0x1c8]
	ldrb r2, [r0, #0x1d3]
	sub r2, r3, r2
	strb r2, [r7, #0x1c8]
_021706E4:
	add r8, r8, #1
	cmp r8, #5
	add ip, ip, #0x4c
	blt _02170614
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_021706F8: .word DAT_overlay_0_02172f3c

	arm_func_start ov0_021706FC
ov0_021706FC: ; 0x021706FC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	ldr r0, [sl, #0x18]
	mov sb, r1
	cmp r0, #0
	beq _021707DC
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	cmp r0, #0
	beq _021707DC
	ldr r0, [sl, #0x18]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	cmp r0, #0
	beq _021707DC
	ldr r0, [sl, #0x18]
	mov r1, sb
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	cmp r0, #0
	beq _021707DC
	mov r7, #0
	mov r8, sl
	mov r4, r7
	mov fp, #8
	arm_func_end ov0_021706FC
_0217076C:
	ldr r0, [sl, #0x18]
	mov r1, sb
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	mov r6, r0
	ldr r0, [sl, #0x18]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r5, r0
	ldr r0, [sl, #0x18]
	mov r1, sb
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	str r0, [r8, #0x58]
	str r4, [r8, #0x5c]
	str r5, [r8, #0x60]
	str r6, [r8, #0x64]
	strh r4, [r8, #0x56]
	str fp, [r8, #0x3c]
	mov r0, #1
	add r7, r7, #1
	strb r0, [sl, #0x20]
	add r8, r8, #0x4c
	cmp r7, #5
	blt _0217076C
_021707DC:
	str sb, [sl, #0x1b8]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN24CFieldEffectManpuDarkrie4DrawEP8Camera2D
_ZN24CFieldEffectManpuDarkrie4DrawEP8Camera2D: ; 0x021707E4
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r2, [r4, #0x1c]
	mov r6, r1
	cmp r2, #0
	ldrneb r1, [r4, #0x20]
	cmpne r1, #0
	beq _02170810
	bl _ZN17CFieldEffectManpu9IsVisibleEv
	cmp r0, #0
	bne _02170818
	arm_func_end _ZN24CFieldEffectManpuDarkrie4DrawEP8Camera2D
_02170810:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
_02170818:
	ldr r0, [r4, #0x18]
	ldr r1, [r4, #0x1b8]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	add r5, r4, #0x2c
	mov r4, #0
_02170834:
	mov r0, r5
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	add r4, r4, #1
	cmp r4, #5
	add r5, r5, #0x4c
	blt _02170834
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN24CFieldEffectManpuDarkrie8SetDepthEl
_ZN24CFieldEffectManpuDarkrie8SetDepthEl: ; 0x02170860
	mov r2, #0
	arm_func_end _ZN24CFieldEffectManpuDarkrie8SetDepthEl
_02170864:
	add r2, r2, #1
	str r1, [r0, #0x30]
	cmp r2, #5
	add r0, r0, #0x4c
	blt _02170864
	bx lr

	arm_func_start ov0_0217087C
ov0_0217087C: ; 0x0217087C
	stmdb sp!, {r4, lr}
	ldr r1, _02170944 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r1, _02170948 ; =ptr_FUN_overlay_0_02170954_overlay_0_0217ad24
	mov r0, #0
	str r1, [r4]
	str r0, [r4, #0x18]
	mov r1, #8
	add r0, r4, #0x28
	str r1, [r4, #0x24]
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _0217094C ; =_ZTV17CPrimitiveRectNTF+8
	mov r2, #0
	str r0, [r4, #0x28]
	ldr r0, _02170950 ; =_ZTV16CSimpleSpriteNTF+8
	str r2, [r4, #0x40]
	str r0, [r4, #0x28]
	str r2, [r4, #0x74]
	str r2, [r4, #0x78]
	strh r2, [r4, #0x7c]
	mov r1, #0x1000
	str r2, [r4, #0x80]
	str r1, [r4, #0x70]
	str r1, [r4, #0x6c]
	str r2, [r4, #0x84]
	strb r2, [r4, #0x88]
	strb r2, [r4, #0x89]
	strh r2, [r4, #0x8a]
	strh r2, [r4, #0x8c]
	mov r1, #0x1f
	strb r1, [r4, #0x8e]
	mov r1, #0x40000
	str r1, [r4, #0x74]
	mov r0, #8
	str r1, [r4, #0x78]
	str r0, [r4, #0x38]
	str r2, [r4, #0x54]
	str r2, [r4, #0x58]
	str r1, [r4, #0x5c]
	str r1, [r4, #0x60]
	sub r0, r0, #9
	str r0, [r4, #0x2c]
	str r2, [r4, #0x20]
	mov r0, r4
	str r2, [r4, #0x1c]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02170944: .word _ZTV12CFieldEffect+8
_02170948: .word ptr_FUN_overlay_0_02170954_overlay_0_0217ad24
_0217094C: .word _ZTV17CPrimitiveRectNTF+8
_02170950: .word _ZTV16CSimpleSpriteNTF+8
	arm_func_end ov0_0217087C

	arm_func_start _ZN19CFieldEffectGlitterD1Ev
_ZN19CFieldEffectGlitterD1Ev: ; 0x02170954
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x28
	bl _ZN10CPrimitiveD2Ev
	ldr r1, _02170984 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02170984: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN19CFieldEffectGlitterD1Ev

	arm_func_start ov0_02170988
ov0_02170988: ; 0x02170988
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x28
	bl _ZN10CPrimitiveD2Ev
	ldr r1, _021709C0 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021709C0: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_02170988

	arm_func_start ov0_021709C4
ov0_021709C4: ; 0x021709C4
	str r1, [r0, #0x40]
	str r1, [r0, #0x84]
	bx lr
	arm_func_end ov0_021709C4

	arm_func_start _ZN19CFieldEffectGlitter8SetParamEii
_ZN19CFieldEffectGlitter8SetParamEii: ; 0x021709D0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	cmp r1, #0x11
	mov r4, #1
	bgt _02170A0C
	cmp r1, #0x11
	bge _02170A60
	cmp r1, #4
	addls pc, pc, r1, lsl #2
	b _02170AA0
_021709F8: ; jump table
	b _02170AA0 ; case 0
	b _02170A28 ; case 1
	b _02170A38 ; case 2
	b _02170A48 ; case 3
	b _02170A54 ; case 4
	arm_func_end _ZN19CFieldEffectGlitter8SetParamEii
_02170A0C:
	cmp r1, #0x14
	bgt _02170A1C
	beq _02170A98
	b _02170AA0
_02170A1C:
	cmp r1, #0x1a
	beq _02170A80
	b _02170AA0
_02170A28:
	mov r0, r2, lsl #0xc
	str r0, [r5, #0x1c]
	str r0, [r5, #0x64]
	b _02170AA4
_02170A38:
	mov r0, r2, lsl #0xc
	str r0, [r5, #0x20]
	str r0, [r5, #0x68]
	b _02170AA4
_02170A48:
	mov r0, r2, lsl #0xc
	str r0, [r5, #0x74]
	b _02170AA4
_02170A54:
	mov r0, r2, lsl #0xc
	str r0, [r5, #0x78]
	b _02170AA4
_02170A60:
	ldr r0, _02170AAC ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02170AA4
	mov r1, r2
	bl _ZN11CFieldScene12ov0_02123060Em
	str r0, [r5, #0x18]
	b _02170AA4
_02170A80:
	and r0, r2, #0xff
	cmp r0, #0x1f
	strb r2, [r5, #0x8e]
	movhi r0, #0x1f
	strhib r0, [r5, #0x8e]
	b _02170AA4
_02170A98:
	str r2, [r5, #0x24]
	b _02170AA4
_02170AA0:
	mov r4, #0
_02170AA4:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02170AAC: .word MAIN_BSS_0210CA40

	arm_func_start _ZN19CFieldEffectGlitter12ov0_021421F0Eiii
_ZN19CFieldEffectGlitter12ov0_021421F0Eiii: ; 0x02170AB0
	stmdb sp!, {r3, lr}
	cmp r1, #0
	strgtb r1, [r0, #0x88]
	movgt ip, #0
	strgt ip, [r0, #0x3c]
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, pc}
	arm_func_end _ZN19CFieldEffectGlitter12ov0_021421F0Eiii

	arm_func_start _ZN19CFieldEffectGlitter12ov0_02142264Ei
_ZN19CFieldEffectGlitter12ov0_02142264Ei: ; 0x02170ACC
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x30
	mov r8, r0
	mov r7, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	mov r4, r0
	cmp r4, #2
	bne _02170BD4
	ldrsb r0, [r8, #0x88]
	cmp r0, #0
	ble _02170B60
	sub r0, r0, r7
	strb r0, [r8, #0x88]
	ldrsb r0, [r8, #0x88]
	cmp r0, #0
	bgt _02170BD4
	bl _ZN5CGame11GetInstanceEv
	add ip, r0, #0x1000
	add r1, r0, #0x48
	add r3, r1, #0x1400
	ldr sl, [ip, #0x448]
	ldmib r3, {sb, lr}
	umull r1, r0, lr, sl
	mla r0, lr, sb, r0
	ldr sb, [r3, #0xc]
	ldr r2, [r3, #0x10]
	mla r0, sb, sl, r0
	ldr lr, [r3, #0x14]
	adds r1, r2, r1
	adc r2, lr, r0
	str r1, [ip, #0x448]
	mov r0, #6
	umull r0, r1, r2, r0
	str r2, [r3, #4]
	add r0, r1, #0xa
	strb r0, [r8, #0x89]
	b _02170BD4
	arm_func_end _ZN19CFieldEffectGlitter12ov0_02142264Ei
_02170B60:
	ldrsb r0, [r8, #0x89]
	sub r0, r0, r7
	strb r0, [r8, #0x89]
	ldrsb r0, [r8, #0x89]
	cmp r0, #0
	bgt _02170BD4
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r3, r1, #0x1400
	add ip, r0, #0x1000
	ldr sl, [r3, #8]
	ldr sb, [ip, #0x448]
	ldr lr, [r3, #4]
	umull r1, r0, sl, sb
	mla r0, sl, lr, r0
	ldr lr, [r3, #0xc]
	ldr r2, [r3, #0x10]
	mla r0, lr, sb, r0
	ldr sl, [r3, #0x14]
	adds r1, r2, r1
	adc r2, sl, r0
	str r1, [ip, #0x448]
	mov r0, #0x33
	umull r0, r1, r2, r0
	str r2, [r3, #4]
	add r0, r1, #0xa
	strb r0, [r8, #0x88]
	mov r0, #0
	strh r0, [r8, #0x8c]
_02170BD4:
	ldrh r2, [r8, #0x8a]
	mov r0, r7, lsl #0x17
	mov r1, r7, lsl #0x19
	add r0, r2, r0, lsr #16
	strh r0, [r8, #0x8a]
	ldrh r0, [r8, #0x8c]
	add r0, r0, r1, lsr #16
	strh r0, [r8, #0x8c]
	ldr r0, [r8, #0x18]
	cmp r0, #0
	beq _02170CEC
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02170C4C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02170C2C
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	b _02170C44
_02170C2C:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_02170C44:
	add sb, sp, #0x20
	b _02170C68
_02170C4C:
	mov r0, #0
	add r1, sp, #0
	add sb, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_02170C68:
	ldr r0, [r8, #0x18]
	ldr r7, [r8, #0x1c]
	ldr r3, [r8, #0x20]
	ldr r2, [sb]
	ldr r1, [sb, #4]
	add r2, r2, r7
	add r1, r1, r3
	ldr r0, [r0, #8]
	str r7, [sp, #0x18]
	str r3, [sp, #0x1c]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	str r2, [sp, #0x28]
	str r1, [sp, #0x2c]
	cmp r0, #0
	beq _02170CD0
	ldr r2, [r0, #0xc]
	cmp r2, #0
	moveq r2, #0
	beq _02170CD4
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r2, r2, r0
	b _02170CD4
_02170CD0:
	mov r2, #0
_02170CD4:
	ldr r1, [sp, #0x2c]
	ldr r0, [sp, #0x28]
	sub r1, r1, r2
	str r0, [r8, #0x64]
	str r1, [sp, #0x2c]
	str r1, [r8, #0x68]
_02170CEC:
	cmp r4, #1
	beq _02170D08
	cmp r4, #2
	beq _02170D20
	cmp r4, #3
	beq _02170D28
	b _02170D40
_02170D08:
	ldr r0, [r8, #0x10]
	ldr r1, [r8, #4]
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	mov r5, r0
	b _02170D40
_02170D20:
	mov r5, #0x1000
	b _02170D40
_02170D28:
	ldr r1, [r8, #0xc]
	ldr r0, [r8, #0x10]
	sub r0, r1, r0
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	mov r5, r0
_02170D40:
	ldr r1, [r8, #0x24]
	cmp r1, #8
	beq _02170D68
	ldr r0, _02170DFC ; =0x00000199
	sub r1, r1, #8
	mul r0, r1, r0
	add r0, r0, #0x1000
	smull r1, r0, r5, r0
	mov r5, r1, lsr #0xc
	orr r5, r5, r0, lsl #20
_02170D68:
	str r5, [r8, #0x70]
	str r5, [r8, #0x6c]
	cmp r4, #1
	beq _02170D8C
	cmp r4, #2
	beq _02170DA8
	cmp r4, #3
	beq _02170DB0
	b _02170DCC
_02170D8C:
	ldrb r2, [r8, #0x8e]
	ldr r0, [r8, #0x10]
	ldr r1, [r8, #4]
	mul r0, r2, r0
	bl _s32_div_f
	mov r6, r0
	b _02170DCC
_02170DA8:
	ldrb r6, [r8, #0x8e]
	b _02170DCC
_02170DB0:
	ldr r1, [r8, #0xc]
	ldr r0, [r8, #0x10]
	ldrb r2, [r8, #0x8e]
	sub r0, r1, r0
	mul r0, r2, r0
	bl _s32_div_f
	mov r6, r0
_02170DCC:
	ldr r0, [r8, #0x24]
	ldr r1, _02170E00 ; =0x84210843
	add r0, r0, #0x10
	mul r2, r6, r0
	smull r0, r3, r1, r2
	add r3, r2, r3
	mov r0, r2, lsr #0x1f
	add r3, r0, r3, asr #4
	mov r0, r4
	str r3, [r8, #0x3c]
	add sp, sp, #0x30
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02170DFC: .word 0x00000199
_02170E00: .word 0x84210843

	arm_func_start _ZN19CFieldEffectGlitter12ov0_02142344EP8Camera2D
_ZN19CFieldEffectGlitter12ov0_02142344EP8Camera2D: ; 0x02170E04
	stmdb sp!, {r3, lr}
	ldrsb r2, [r0, #0x88]
	cmp r2, #0
	ble _02170E28
	ldrh r2, [r0, #0x8a]
	strh r2, [r0, #0x7c]
	ldr r2, [r0, #0x28]!
	ldr r2, [r2, #8]
	blx r2
	arm_func_end _ZN19CFieldEffectGlitter12ov0_02142344EP8Camera2D
_02170E28:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start _ZN19CFieldEffectGlitter8SetColorEt
_ZN19CFieldEffectGlitter8SetColorEt: ; 0x02170E30
	strh r1, [r0, #0x30]
	bx lr
	arm_func_end _ZN19CFieldEffectGlitter8SetColorEt

	arm_func_start ov0_02170E38
ov0_02170E38: ; 0x02170E38
	str r1, [r0, #0x38]
	mov r0, #1
	bx lr
	arm_func_end ov0_02170E38

	arm_func_start _ZN26CFieldEffectGlitterFactoryD1Ev
_ZN26CFieldEffectGlitterFactoryD1Ev: ; 0x02170E44
	stmdb sp!, {r4, lr}
	ldr r1, _02170E68 ; =ptr_FUN_overlay_0_02170e44_overlay_0_0217ad04
	mov r4, r0
	str r1, [r4]
	bl ov0_02171010
	add r0, r4, #4
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02170E68: .word ptr_FUN_overlay_0_02170e44_overlay_0_0217ad04
	arm_func_end _ZN26CFieldEffectGlitterFactoryD1Ev

	arm_func_start ov0_02170E6C
ov0_02170E6C: ; 0x02170E6C
	stmdb sp!, {r4, lr}
	ldr r1, _02170E98 ; =ptr_FUN_overlay_0_02170e44_overlay_0_0217ad04
	mov r4, r0
	str r1, [r4]
	bl ov0_02171010
	add r0, r4, #4
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02170E98: .word ptr_FUN_overlay_0_02170e44_overlay_0_0217ad04
	arm_func_end ov0_02170E6C

	arm_func_start _ZN26CFieldEffectGlitterFactory5ResetEv
_ZN26CFieldEffectGlitterFactory5ResetEv: ; 0x02170E9C
	ldr ip, _02170EA4 ; =ov0_02171010
	bx ip
	.align 2, 0
_02170EA4: .word ov0_02171010
	arm_func_end _ZN26CFieldEffectGlitterFactory5ResetEv

	arm_func_start _ZN26CFieldEffectGlitterFactory6CreateEi
_ZN26CFieldEffectGlitterFactory6CreateEi: ; 0x02170EA8
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0x7c
	mov r6, r0
	ldr r0, [r6, #0xc]
	mov r5, #1
	cmp r0, #0
	mov r4, #0
	bne _02170F04
	str r5, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	ldr r1, _02170F7C ; =DAT_overlay_0_0217ad80
	ldr r2, _02170F80 ; =s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217ad84
	add r0, sp, #0x10
	mov r3, r5
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r0, r6
	mov r1, r5
	bl ov0_02170F88
	mov r5, r0
	add r0, sp, #0x10
	bl _ZN13CArchiveGuardD1Ev
	arm_func_end _ZN26CFieldEffectGlitterFactory6CreateEi
_02170F04:
	cmp r5, #0
	beq _02170F70
	mov r0, #0x90
	bl _Znwm
	movs r4, r0
	beq _02170F24
	bl ov0_0217087C
	mov r4, r0
_02170F24:
	cmp r4, #0
	beq _02170F70
	mov r0, r4
	add r1, r6, #4
	bl ov0_021709C4
	ldr r1, _02170F84 ; =MAIN_BSS_0210CA60
	mov r0, r4
	ldr r1, [r1]
	ldrb r1, [r1, #0x87d]
	add r1, r1, #8
	bl ov0_02170E38
	ldr r1, _02170F84 ; =MAIN_BSS_0210CA60
	and r0, r0, #0xff
	ldr r2, [r1]
	ldrb r1, [r2, #0x87d]
	add r1, r1, r0
	and r0, r1, #0xff
	and r0, r0, #0x1f
	strb r0, [r2, #0x87d]
_02170F70:
	mov r0, r4
	add sp, sp, #0x7c
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02170F7C: .word DAT_overlay_0_0217ad80
_02170F80: .word s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217ad84
_02170F84: .word MAIN_BSS_0210CA60

	arm_func_start ov0_02170F88
ov0_02170F88: ; 0x02170F88
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0xc0
	mov r4, r1
	mov r5, r0
	ldr r1, _02171004 ; =s_MEF_ef100_02d_ntft_overlay_0_0217ada4
	add r0, sp, #0x60
	mov r2, r4
	bl OS_SPrintf
	ldr r1, _02171008 ; =s_MEF_ef100_02d_ntfp_overlay_0_0217adb8
	add r0, sp, #0
	mov r2, r4
	bl OS_SPrintf
	add r1, sp, #0x60
	add r2, sp, #0
	add r0, r5, #4
	mov r3, #0
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	cmp r0, #0
	moveq r0, #0
	beq _02170FE8
	ldr r1, _0217100C ; =0x027FFC3C
	mov r0, #1
	ldr r1, [r1]
	str r1, [r5, #0x2c]
	arm_func_end ov0_02170F88
_02170FE8:
	mov r1, #6
	str r1, [r5, #0x20]
	mov r1, #3
	str r1, [r5, #0x24]
	str r1, [r5, #0x28]
	add sp, sp, #0xc0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02171004: .word s_MEF_ef100_02d_ntft_overlay_0_0217ada4
_02171008: .word s_MEF_ef100_02d_ntfp_overlay_0_0217adb8
_0217100C: .word 0x027FFC3C

	arm_func_start ov0_02171010
ov0_02171010: ; 0x02171010
	ldr ip, _0217101C ; =FUN_02036488
	add r0, r0, #4
	bx ip
	.align 2, 0
_0217101C: .word _ZN10NtfTexture7ReleaseEv
	arm_func_end ov0_02171010

	arm_func_start _ZN19CFieldEffectGlitter7IsReadyEv
_ZN19CFieldEffectGlitter7IsReadyEv: ; 0x02171020
	ldr r1, [r0, #0x84]
	mov r0, #1
	cmp r1, #0
	bxeq lr
	ldr r2, _02171054 ; =0x027FFC3C
	ldr r1, [r1, #0x28]
	ldr r2, [r2]
	cmp r1, r2
	movne r1, r0
	moveq r1, #0
	cmp r1, #0
	moveq r0, #0
	bx lr
	.align 2, 0
_02171054: .word 0x027FFC3C
	arm_func_end _ZN19CFieldEffectGlitter7IsReadyEv

	arm_func_start _ZN19CFieldEffectGlitter11GetEffectIdEv
_ZN19CFieldEffectGlitter11GetEffectIdEv: ; 0x02171058
	mov r0, #0x1b
	bx lr
	arm_func_end _ZN19CFieldEffectGlitter11GetEffectIdEv

	arm_func_start ov0_02171060
ov0_02171060: ; 0x02171060
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	ldr r2, _02171188 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r2, [r4]
	ldr r2, [r0]
	mov r5, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r1, _0217118C ; =ptr_FUN_overlay_0_02171198_overlay_0_0217ae5c
	mov r0, #0
	str r1, [r4]
	str r5, [r4, #0x18]
	str r0, [r4, #0x1c]
	ldr ip, _02171190 ; =_ZN16CSimpleSpriteNTFD1Ev
	ldr r3, _02171194 ; =ov0_02166794
	add r0, r4, #0x28
	mov r1, #4
	mov r2, #0x5c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r0, #0
	strb r0, [r4, #0x19c]
	str r0, [r4, #0x1a0]
	add r1, r4, #0x100
	mov r3, #0x3c
	strh r3, [r1, #0xbc]
	strh r0, [r1, #0xbe]
	mov r2, #0x1000
	str r2, [r4, #0x1c0]
	mov r2, #0x2000
	str r2, [r4, #0x1c4]
	strb r0, [r4, #0x1c8]
	mov r2, #0x14
	strb r2, [r4, #0x1c9]
	strh r3, [r1, #0xca]
	mov r5, r4
	mov r6, r4
	strb r0, [r4, #0x1cc]
	mov lr, r0
	mov ip, #0x60000
	mov r3, #0x40000
	mvn r2, #0
	arm_func_end ov0_02171060
_0217110C:
	add r1, r5, #0x100
	strh lr, [r1, #0xa4]
	str lr, [r6, #0x3c]
	sub r1, r2, r0
	str r1, [r6, #0x2c]
	add r1, r0, #8
	str r1, [r6, #0x38]
	str ip, [r6, #0x74]
	str ip, [r6, #0x78]
	str lr, [r6, #0x54]
	str lr, [r6, #0x58]
	str r3, [r6, #0x5c]
	str r3, [r6, #0x60]
	add r1, r4, r0
	add r0, r0, #1
	strb r2, [r1, #0x198]
	cmp r0, #4
	add r5, r5, #6
	add r6, r6, #0x5c
	blt _0217110C
	mov r1, #0x1f
	strh r1, [r4, #0x30]
	mov r0, #0x7c00
	strh r0, [r4, #0x8c]
	add r0, r1, #0x3e0
	strh r0, [r4, #0xe8]
	str lr, [r4, #0x24]
	mov r0, r4
	str lr, [r4, #0x20]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02171188: .word _ZTV12CFieldEffect+8
_0217118C: .word ptr_FUN_overlay_0_02171198_overlay_0_0217ae5c
_02171190: .word _ZN16CSimpleSpriteNTFD1Ev
_02171194: .word ov0_02166794

	arm_func_start _ZN26CFieldEffectBlackStoneAuraD1Ev
_ZN26CFieldEffectBlackStoneAuraD1Ev: ; 0x02171198
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _021711D4 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0x28
	mov r1, #4
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	ldr r1, _021711D8 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021711D4: .word _ZN16CSimpleSpriteNTFD1Ev
_021711D8: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN26CFieldEffectBlackStoneAuraD1Ev

	arm_func_start ov0_021711DC
ov0_021711DC: ; 0x021711DC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02171220 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0x28
	mov r1, #4
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	ldr r1, _02171224 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02171220: .word _ZN16CSimpleSpriteNTFD1Ev
_02171224: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_021711DC

	arm_func_start _ZN26CFieldEffectBlackStoneAura8SetParamEii
_ZN26CFieldEffectBlackStoneAura8SetParamEii: ; 0x02171228
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	cmp r1, #4
	mov r4, #1
	bgt _0217125C
	cmp r1, #0
	addge pc, pc, r1, lsl #2
	b _02171320
_02171248: ; jump table
	b _02171320 ; case 0
	b _02171268 ; case 1
	b _02171294 ; case 2
	b _021712C0 ; case 3
	b _021712E0 ; case 4
	arm_func_end _ZN26CFieldEffectBlackStoneAura8SetParamEii
_0217125C:
	cmp r1, #0x11
	beq _02171300
	b _02171320
_02171268:
	mov r0, r2, lsl #0xc
	mov r2, r5
	str r0, [r5, #0x20]
	mov r1, #0
_02171278:
	ldr r0, [r5, #0x20]
	add r1, r1, #1
	str r0, [r2, #0x64]
	cmp r1, #4
	add r2, r2, #0x5c
	blt _02171278
	b _02171324
_02171294:
	mov r0, r2, lsl #0xc
	mov r2, r5
	str r0, [r5, #0x24]
	mov r1, #0
_021712A4:
	ldr r0, [r5, #0x24]
	add r1, r1, #1
	str r0, [r2, #0x68]
	cmp r1, #4
	add r2, r2, #0x5c
	blt _021712A4
	b _02171324
_021712C0:
	mov r1, r2, lsl #0xc
	mov r0, #0
_021712C8:
	add r0, r0, #1
	str r1, [r5, #0x74]
	cmp r0, #4
	add r5, r5, #0x5c
	blt _021712C8
	b _02171324
_021712E0:
	mov r1, r2, lsl #0xc
	mov r0, #0
_021712E8:
	add r0, r0, #1
	str r1, [r5, #0x78]
	cmp r0, #4
	add r5, r5, #0x5c
	blt _021712E8
	b _02171324
_02171300:
	ldr r0, _0217132C ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02171324
	mov r1, r2
	bl _ZN11CFieldScene12ov0_02123060Em
	str r0, [r5, #0x1c]
	b _02171324
_02171320:
	mov r4, #0
_02171324:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0217132C: .word MAIN_BSS_0210CA40

	arm_func_start ov0_02171330
ov0_02171330: ; 0x02171330
	mov r3, r0
	str r1, [r0, #0x1a0]
	mov r2, #0
	arm_func_end ov0_02171330
_0217133C:
	ldr r1, [r0, #0x1a0]
	add r2, r2, #1
	str r1, [r3, #0x40]
	cmp r2, #4
	add r3, r3, #0x5c
	blt _0217133C
	bx lr

	arm_func_start _ZN26CFieldEffectBlackStoneAura12ov0_021421F0Eiii
_ZN26CFieldEffectBlackStoneAura12ov0_021421F0Eiii: ; 0x02171358
	stmdb sp!, {r3, lr}
	add ip, r0, #0x100
	mov lr, #1
	strh lr, [ip, #0xbe]
	mov ip, #0
	strb ip, [r0, #0x1cc]
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, pc}
	arm_func_end _ZN26CFieldEffectBlackStoneAura12ov0_021421F0Eiii

	arm_func_start _ZN26CFieldEffectBlackStoneAura12ov0_02142264Ei
_ZN26CFieldEffectBlackStoneAura12ov0_02142264Ei: ; 0x02171378
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x10
	mov r8, r0
	mov r7, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	str r0, [sp, #8]
	cmp r0, #1
	beq _021713A4
	cmp r0, #3
	beq _021713B8
	b _021713D0
	arm_func_end _ZN26CFieldEffectBlackStoneAura12ov0_02142264Ei
_021713A4:
	ldr r0, [r8, #0x10]
	ldr r1, [r8, #4]
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	b _021713D4
_021713B8:
	ldr r1, [r8, #0xc]
	ldr r0, [r8, #0x10]
	sub r0, r1, r0
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	b _021713D4
_021713D0:
	mov r0, #0x1000
_021713D4:
	str r0, [sp]
	mov r0, r0, asr #0x1f
	str r0, [sp, #4]
	mvn r0, #0
	mov r5, r8
	mov r6, r8
	mov r4, #0
	add sb, r8, #0x100
	str r0, [sp, #0xc]
_021713F8:
	add r0, r5, #0x100
	ldrsh r1, [r0, #0xa4]
	cmp r1, #0
	ble _0217150C
	sub r1, r1, r7
	strh r1, [r0, #0xa4]
	ldrh r1, [r0, #0xa6]
	add r1, r1, r7
	strh r1, [r0, #0xa6]
	ldrh sl, [sb, #0xca]
	ldrh r0, [r0, #0xa6]
	mov r1, sl
	bl _s32_div_f
	mov r0, r1, lsl #0x10
	mov r3, r0, lsr #4
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, sl, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	cmp r0, #0x800
	ldrltb r1, [r8, #0x1c8]
	ldrltb r2, [r8, #0x1c9]
	ldrgeb r1, [r8, #0x1c9]
	ldrgeb r2, [r8, #0x1c8]
	sub r2, r2, r1
	mov r2, r2, lsl #0xc
	smull r3, r2, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	add r1, r0, r1, lsl #12
	ldr r0, [sp]
	umull r3, r2, r1, r0
	ldr r0, [sp, #4]
	mla r2, r1, r0, r2
	ldr r0, [sp]
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	mov r0, r0, asr #0xc
	str r0, [r6, #0x3c]
	add r0, r5, #0x100
	ldrsh r1, [r0, #0xa4]
	ldr sl, [r8, #0x1c4]
	ldr r2, [r8, #0x1c0]
	ldrsh r0, [sb, #0xbc]
	sub r2, sl, r2
	mul r3, r2, r1
	mov r2, r0, lsl #0xc
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	sub r0, sl, r0
	str r0, [r6, #0x70]
	str r0, [r6, #0x6c]
	add r0, r5, #0x100
	ldrsh r0, [r0, #0xa4]
	cmp r0, #0
	bgt _0217150C
	ldrb r0, [r5, #0x1a8]
	add r1, r8, r0
	ldr r0, [sp, #0xc]
	strb r0, [r1, #0x198]
_0217150C:
	add r4, r4, #1
	cmp r4, #4
	add r5, r5, #6
	add r6, r6, #0x5c
	blt _021713F8
	add r0, r8, #0x100
	ldrsh r1, [r0, #0xbe]
	cmp r1, #0
	ble _02171588
	sub r1, r1, r7
	strh r1, [r0, #0xbe]
	ldrsh r0, [r0, #0xbe]
	cmp r0, #0
	bgt _02171588
	mov r0, r8
	bl ov0_0217162C
	ldr r0, [r8, #0x18]
	cmp r0, #0
	bne _02171570
	add r1, r8, #0x100
	ldrsh r0, [r1, #0xbc]
	add r0, r0, r0, lsr #31
	mov r0, r0, asr #1
	strh r0, [r1, #0xbe]
	b _02171588
_02171570:
	add r2, r8, #0x100
	ldrsh r3, [r2, #0xbc]
	ldr r1, _02171594 ; =0x55555556
	smull r0, r4, r1, r3
	add r4, r4, r3, lsr #31
	strh r4, [r2, #0xbe]
_02171588:
	ldr r0, [sp, #8]
	add sp, sp, #0x10
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02171594: .word 0x55555556

	arm_func_start _ZN26CFieldEffectBlackStoneAura12ov0_02142344EP8Camera2D
_ZN26CFieldEffectBlackStoneAura12ov0_02142344EP8Camera2D: ; 0x02171598
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	ldrb r6, [sl, #0x19c]
	mov r7, #0
	mov sb, r1
	mov r8, r7
	add r5, sl, #0x28
	mov fp, #0x5c
	mov r4, #6
	arm_func_end _ZN26CFieldEffectBlackStoneAura12ov0_02142344EP8Camera2D
_021715BC:
	add r0, sl, r6
	add r0, r0, #0x100
	ldrsb r1, [r0, #0x98]
	cmp r1, #0
	blt _0217160C
	mla r0, r1, r4, sl
	add r0, r0, #0x100
	ldrsh r0, [r0, #0xa4]
	cmp r0, #0
	ble _0217160C
	mul r2, r1, fp
	sub r1, r7, #5
	add r0, sl, r2
	str r1, [r0, #0x2c]
	add r0, r5, r2
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
	add r7, r7, #1
_0217160C:
	add r6, r6, #1
	cmp r6, #4
	add r8, r8, #1
	movge r6, #0
	cmp r8, #4
	blt _021715BC
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov0_0217162C
ov0_0217162C: ; 0x0217162C
	stmdb sp!, {r4, lr}
	mov r3, r0
	mov r1, #0
	arm_func_end ov0_0217162C
_02171638:
	add r2, r3, #0x100
	ldrsh r2, [r2, #0xa4]
	cmp r2, #0
	bgt _02171714
	mov r2, #6
	mul r2, r1, r2
	add r3, r0, #0x100
	add lr, r0, r2
	ldrsh r4, [r3, #0xbc]
	add r3, lr, #0x100
	mov ip, #0x5c
	mla lr, r1, ip, r0
	strh r4, [r3, #0xa4]
	mov ip, #0
	strh ip, [r3, #0xa6]
	ldrb r3, [r0, #0x1c8]
	str r3, [lr, #0x3c]
	ldr r3, [r0, #0x18]
	ldrb ip, [r0, #0x1cc]
	cmp r3, #0
	ldreq r3, _02171728 ; =DAT_overlay_0_0217adcc
	mov ip, ip, lsl #1
	ldrne r3, _0217172C ; =DAT_overlay_0_0217add0
	ldrh r3, [r3, ip]
	strh r3, [lr, #0x30]
	ldrb r3, [r0, #0x1cc]
	add r3, r3, #1
	strb r3, [r0, #0x1cc]
	ldr r4, [r0, #0x18]
	cmp r4, #0
	bne _021716C0
	ldrb r3, [r0, #0x1cc]
	cmp r3, #2
	bhs _021716D4
_021716C0:
	cmp r4, #1
	bne _021716DC
	ldrb r3, [r0, #0x1cc]
	cmp r3, #3
	blo _021716DC
_021716D4:
	mov r3, #0
	strb r3, [r0, #0x1cc]
_021716DC:
	ldrb r3, [r0, #0x19c]
	add r2, r0, r2
	add r3, r0, r3
	strb r1, [r3, #0x198]
	ldrb r1, [r0, #0x19c]
	strb r1, [r2, #0x1a8]
	ldrb r1, [r0, #0x19c]
	add r2, r1, #1
	and r1, r2, #0xff
	cmp r1, #4
	strb r2, [r0, #0x19c]
	movhs r1, #0
	strcsb r1, [r0, #0x19c]
	ldmia sp!, {r4, pc}
_02171714:
	add r1, r1, #1
	cmp r1, #4
	add r3, r3, #6
	blt _02171638
	ldmia sp!, {r4, pc}
	.align 2, 0
_02171728: .word DAT_overlay_0_0217adcc
_0217172C: .word DAT_overlay_0_0217add0

	arm_func_start _ZN33CFieldEffectBlackStoneAuraFactoryD1Ev
_ZN33CFieldEffectBlackStoneAuraFactoryD1Ev: ; 0x02171730
	stmdb sp!, {r4, lr}
	ldr r1, _02171754 ; =ptr_FUN_overlay_0_02171730_overlay_0_0217ae18
	mov r4, r0
	str r1, [r4]
	bl ov0_02171890
	add r0, r4, #4
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02171754: .word ptr_FUN_overlay_0_02171730_overlay_0_0217ae18
	arm_func_end _ZN33CFieldEffectBlackStoneAuraFactoryD1Ev

	arm_func_start ov0_02171758
ov0_02171758: ; 0x02171758
	stmdb sp!, {r4, lr}
	ldr r1, _02171784 ; =ptr_FUN_overlay_0_02171730_overlay_0_0217ae18
	mov r4, r0
	str r1, [r4]
	bl ov0_02171890
	add r0, r4, #4
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02171784: .word ptr_FUN_overlay_0_02171730_overlay_0_0217ae18
	arm_func_end ov0_02171758

	arm_func_start _ZN33CFieldEffectBlackStoneAuraFactory6CreateEi
_ZN33CFieldEffectBlackStoneAuraFactory6CreateEi: ; 0x02171788
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r2, [r6, #0xc]
	mov r5, r1
	cmp r2, #0
	mov r4, #0
	mov r1, #1
	bne _021717B0
	bl ov0_021717FC
	mov r1, r0
	arm_func_end _ZN33CFieldEffectBlackStoneAuraFactory6CreateEi
_021717B0:
	cmp r1, #0
	beq _021717E8
	mov r0, #0x1d0
	bl _Znwm
	movs r4, r0
	beq _021717D4
	mov r1, r5
	bl ov0_02171060
	mov r4, r0
_021717D4:
	cmp r4, #0
	beq _021717E8
	mov r0, r4
	add r1, r6, #4
	bl ov0_02171330
_021717E8:
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN33CFieldEffectBlackStoneAuraFactory5ResetEv
_ZN33CFieldEffectBlackStoneAuraFactory5ResetEv: ; 0x021717F0
	ldr ip, _021717F8 ; =ov0_02171890
	bx ip
	.align 2, 0
_021717F8: .word ov0_02171890
	arm_func_end _ZN33CFieldEffectBlackStoneAuraFactory5ResetEv

	arm_func_start ov0_021717FC
ov0_021717FC: ; 0x021717FC
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x7c
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	mov r4, r0
	str ip, [sp, #8]
	ldr r1, _0217187C ; =DAT_overlay_0_0217aeb8
	ldr r2, _02171880 ; =s_data_field_effect_ef101_LZ_bin_overlay_0_0217aebc
	add r0, sp, #0x10
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r2, _02171884 ; =s_FEF_ef101_00_ntfp_overlay_0_0217aedc
	ldr r1, _02171888 ; =s_FEF_ef101_00_ntft_overlay_0_0217aef0
	add r0, r4, #4
	mov r3, #0
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	cmp r0, #0
	ldrne r0, _0217188C ; =0x027FFC3C
	mov r1, #3
	ldrne r0, [r0]
	strne r0, [r4, #0x2c]
	mov r0, #6
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
	add r0, sp, #0x10
	str r1, [r4, #0x28]
	bl _ZN13CArchiveGuardD1Ev
	mov r0, #1
	add sp, sp, #0x7c
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0217187C: .word DAT_overlay_0_0217aeb8
_02171880: .word s_data_field_effect_ef101_LZ_bin_overlay_0_0217aebc
_02171884: .word s_FEF_ef101_00_ntfp_overlay_0_0217aedc
_02171888: .word s_FEF_ef101_00_ntft_overlay_0_0217aef0
_0217188C: .word 0x027FFC3C
	arm_func_end ov0_021717FC

	arm_func_start ov0_02171890
ov0_02171890: ; 0x02171890
	ldr ip, _0217189C ; =FUN_02036488
	add r0, r0, #4
	bx ip
	.align 2, 0
_0217189C: .word _ZN10NtfTexture7ReleaseEv
	arm_func_end ov0_02171890

	arm_func_start _ZN26CFieldEffectBlackStoneAura7IsReadyEv
_ZN26CFieldEffectBlackStoneAura7IsReadyEv: ; 0x021718A0
	ldr r1, [r0, #0x1a0]
	mov r0, #1
	cmp r1, #0
	bxeq lr
	ldr r2, _021718D4 ; =0x027FFC3C
	ldr r1, [r1, #0x28]
	ldr r2, [r2]
	cmp r1, r2
	movne r1, r0
	moveq r1, #0
	cmp r1, #0
	moveq r0, #0
	bx lr
	.align 2, 0
_021718D4: .word 0x027FFC3C
	arm_func_end _ZN26CFieldEffectBlackStoneAura7IsReadyEv

	arm_func_start _ZN26CFieldEffectBlackStoneAura11GetEffectIdEv
_ZN26CFieldEffectBlackStoneAura11GetEffectIdEv: ; 0x021718D8
	mov r0, #0x1c
	bx lr
	arm_func_end _ZN26CFieldEffectBlackStoneAura11GetEffectIdEv

	arm_func_start ov0_021718E0
ov0_021718E0: ; 0x021718E0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _02171934 ; =ptr_FUN_overlay_0_02172638_overlay_0_0217af50
	mov r0, #0
	str r1, [r4]
	str r0, [r4, #0x28]
	str r0, [r4, #0x2c]
	str r0, [r4, #0x40]
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	str r0, [r4, #0x4c]
	str r0, [r4, #0x54]
	strh r0, [r4, #0x58]
	str r0, [r4, #0x5c]
	strb r0, [r4, #0x61]
	mov r1, #0x1000
	str r1, [r4, #0x24]
	mov r0, r4
	str r1, [r4, #0x20]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02171934: .word ptr_FUN_overlay_0_02172638_overlay_0_0217af50
	arm_func_end ov0_021718E0

	arm_func_start ov0_02171938
ov0_02171938: ; 0x02171938
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	ldr r1, _02171AFC ; =_ZTV12CFieldEffect+8
	mov sl, r0
	str r1, [sl]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _02171B00 ; =ptr_FUN_overlay_0_02171b1c_overlay_0_0217b00c
	ldr r4, _02171B04 ; =_ZN19CFEFRasterTransformD1Ev
	str r0, [sl]
	ldr r3, _02171B08 ; =ov0_021718E0
	add r0, sl, #0x20
	mov r1, #3
	mov r2, #0x64
	str r4, [sp]
	bl __cxa_vec_ctor
	mov r7, #0
	mov r4, #0x38000
	rsb r4, r4, #0
	add r0, sl, #0x100
	mov r1, #1
	strh r1, [r0, #0x64]
	mov r0, #0x1f
	strb r0, [sl, #0x166]
	strb r0, [sl, #0x167]
	str r7, [sl, #0x174]
	str r7, [sl, #0x178]
	ldr r0, _02171B0C ; =_ZTV11CDrawObject+8
	str r7, [sl, #0x17c]
	str r0, [sl, #0x180]
	ldr r0, _02171B10 ; =PTR_LAB_overlay_0_02171b18_overlay_0_0217af3c
	str r7, [sl, #0x184]
	str r0, [sl, #0x180]
	str r7, [sl, #0x18c]
	add r0, r4, #0x20000
	str sl, [sl, #0x190]
	str r0, [sp, #0x14]
	add r0, r4, #0x18000
	mov sb, r7
	strb r7, [sl, #0x194]
	add r5, sl, #0x20
	sub fp, r4, #0x18000
	str r0, [sp, #0x10]
	mov r8, r7
	mov r6, #0xa0000
	arm_func_end ov0_02171938
_021719F0:
	add r1, sl, sb
	str r6, [r1, #0x48]
	str r6, [r1, #0x4c]
	add r0, r7, #8
	str r0, [r1, #0x30]
	cmp r7, #2
	mov r1, #0x20
	bne _02171A3C
	ldr r0, [sp, #0x10]
	str fp, [sp]
	str r0, [sp, #4]
	mov r0, #0xd0000
	str r0, [sp, #8]
	add r0, r5, sb
	mov r2, r6
	mov r3, r6
	str r6, [sp, #0xc]
	bl ov0_02172690
	b _02171A68
_02171A3C:
	ldr r0, [sp, #0x14]
	str r4, [sp]
	str r0, [sp, #4]
	mov r0, #0xb8000
	str r0, [sp, #8]
	mov r0, #0x98000
	str r0, [sp, #0xc]
	add r0, r5, sb
	mov r2, r6
	mov r3, r6
	bl ov0_02172690
_02171A68:
	add r0, sl, r7, lsl #2
	str r8, [r0, #0x14c]
	add sb, sb, #0x64
	add r7, r7, #1
	cmp r7, #3
	blt _021719F0
	mvn r1, #2
	str r1, [sl, #0x24]
	add r0, r1, #1
	str r0, [sl, #0x88]
	add r0, r1, #2
	mov r2, sl
	str r0, [sl, #0xec]
	mov r1, #0
_02171AA0:
	add r0, r2, #0x100
	add r8, r8, #1
	strh r1, [r0, #0x58]
	cmp r8, #2
	add r2, r2, #6
	blt _02171AA0
	str r1, [sl, #0x34]
	str r1, [sl, #0x98]
	ldr r0, _02171B14 ; =0x0000211F
	str r1, [sl, #0xfc]
	strh r0, [sl, #0x28]
	sub r0, r0, #0x17
	strh r0, [sl, #0x8c]
	mov r0, #1
	strb r0, [sl, #0x81]
	strb r0, [sl, #0xe5]
	str r1, [sl, #0x1c]
	str r1, [sl, #0x18]
	mov r1, #0x80000000
	mov r0, sl
	str r1, [sl, #0x184]
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02171AFC: .word _ZTV12CFieldEffect+8
_02171B00: .word ptr_FUN_overlay_0_02171b1c_overlay_0_0217b00c
_02171B04: .word _ZN19CFEFRasterTransformD1Ev
_02171B08: .word ov0_021718E0
_02171B0C: .word _ZTV11CDrawObject+8
_02171B10: .word PTR_LAB_overlay_0_02171b18_overlay_0_0217af3c
_02171B14: .word 0x0000211F

	arm_func_start _ZN24CFieldEffectSpaceCrevice17CEffectDrawObjectD1Ev
_ZN24CFieldEffectSpaceCrevice17CEffectDrawObjectD1Ev: ; 0x02171B18
	bx lr
	arm_func_end _ZN24CFieldEffectSpaceCrevice17CEffectDrawObjectD1Ev

	arm_func_start _ZN24CFieldEffectSpaceCreviceD1Ev
_ZN24CFieldEffectSpaceCreviceD1Ev: ; 0x02171B1C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02171B58 ; =_ZN19CFEFRasterTransformD1Ev
	add r0, r4, #0x20
	mov r1, #3
	mov r2, #0x64
	bl __cxa_vec_cleanup
	ldr r1, _02171B5C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02171B58: .word _ZN19CFEFRasterTransformD1Ev
_02171B5C: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN24CFieldEffectSpaceCreviceD1Ev

	arm_func_start ov0_02171B60
ov0_02171B60: ; 0x02171B60
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02171BA4 ; =_ZN19CFEFRasterTransformD1Ev
	add r0, r4, #0x20
	mov r1, #3
	mov r2, #0x64
	bl __cxa_vec_cleanup
	ldr r1, _02171BA8 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02171BA4: .word _ZN19CFEFRasterTransformD1Ev
_02171BA8: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_02171B60

	arm_func_start ov0_02171BAC
ov0_02171BAC: ; 0x02171BAC
	cmp r1, #0
	bxlt lr
	cmp r1, #3
	bxge lr
	mov r3, #0x64
	mla r3, r1, r3, r0
	str r2, [r3, #0x60]
	add r0, r0, r1, lsl #2
	str r2, [r0, #0x14c]
	bx lr
	arm_func_end ov0_02171BAC

	arm_func_start _ZN24CFieldEffectSpaceCrevice6FadeToEii
_ZN24CFieldEffectSpaceCrevice6FadeToEii: ; 0x02171BD4
	ldrb ip, [r0, #0x166]
	mov r3, r1, lsl #0xc
	mov r1, #1
	mov ip, ip, lsl #0xc
	str ip, [r0, #0x168]
	str r3, [r0, #0x16c]
	str r2, [r0, #0x174]
	str r1, [r0, #0x17c]
	ldr r2, [r0, #0x168]
	mov r1, #0
	str r2, [r0, #0x170]
	str r1, [r0, #0x178]
	bx lr
	arm_func_end _ZN24CFieldEffectSpaceCrevice6FadeToEii

	arm_func_start _ZN24CFieldEffectSpaceCrevice8SetParamEii
_ZN24CFieldEffectSpaceCrevice8SetParamEii: ; 0x02171C08
	cmp r1, #4
	mov r3, #1
	bgt _02171C34
	cmp r1, #0
	addge pc, pc, r1, lsl #2
	b _02171CF0
_02171C20: ; jump table
	b _02171CF0 ; case 0
	b ov0_02171C40 ; case 1
	b ov0_02171C6C ; case 2
	b ov0_02171C98 ; case 3
	b ov0_02171CB8 ; case 4
	arm_func_end _ZN24CFieldEffectSpaceCrevice8SetParamEii
_02171C34:
	cmp r1, #0x1a
	beq _02171CD8
	b _02171CF0

	arm_func_start ov0_02171C40
ov0_02171C40: ; 0x02171C40
	mov r1, r2, lsl #0xc
	mov ip, r0
	str r1, [r0, #0x18]
	mov r2, #0
	arm_func_end ov0_02171C40
_02171C50:
	ldr r1, [r0, #0x18]
	add r2, r2, #1
	str r1, [ip, #0x38]
	cmp r2, #3
	add ip, ip, #0x64
	blt _02171C50
	b _02171CF4

	arm_func_start ov0_02171C6C
ov0_02171C6C: ; 0x02171C6C
	mov r1, r2, lsl #0xc
	mov ip, r0
	str r1, [r0, #0x1c]
	mov r2, #0
	arm_func_end ov0_02171C6C
_02171C7C:
	ldr r1, [r0, #0x1c]
	add r2, r2, #1
	str r1, [ip, #0x3c]
	cmp r2, #3
	add ip, ip, #0x64
	blt _02171C7C
	b _02171CF4

	arm_func_start ov0_02171C98
ov0_02171C98: ; 0x02171C98
	mov r2, r2, lsl #0xc
	mov r1, #0
	arm_func_end ov0_02171C98
_02171CA0:
	add r1, r1, #1
	str r2, [r0, #0x48]
	cmp r1, #3
	add r0, r0, #0x64
	blt _02171CA0
	b _02171CF4

	arm_func_start ov0_02171CB8
ov0_02171CB8: ; 0x02171CB8
	mov r2, r2, lsl #0xc
	mov r1, #0
	arm_func_end ov0_02171CB8
_02171CC0:
	add r1, r1, #1
	str r2, [r0, #0x4c]
	cmp r1, #3
	add r0, r0, #0x64
	blt _02171CC0
	b _02171CF4
_02171CD8:
	and r1, r2, #0xff
	cmp r1, #0x1f
	strb r2, [r0, #0x166]
	movhi r1, #0x1f
	strhib r1, [r0, #0x166]
	b _02171CF4
_02171CF0:
	mov r3, #0
_02171CF4:
	mov r0, r3
	bx lr

	arm_func_start _ZN24CFieldEffectSpaceCrevice12ov0_02142264Ei
_ZN24CFieldEffectSpaceCrevice12ov0_02142264Ei: ; 0x02171CFC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r6, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	movs r4, r0
	cmpne r4, #4
	moveq r0, r4
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	add r0, r7, #0x100
	ldrsh r1, [r0, #0x64]
	cmp r1, #0
	ble _02171D54
	sub r1, r1, r6
	strh r1, [r0, #0x64]
	ldrsh r0, [r0, #0x64]
	cmp r0, #0
	bgt _02171D54
	mov r0, r7
	bl ov0_021721AC
	add r0, r7, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0x64]
	arm_func_end _ZN24CFieldEffectSpaceCrevice12ov0_02142264Ei
_02171D54:
	ldr r0, [r7, #0x17c]
	cmp r0, #0
	moveq r0, #0
	beq _02171DD0
	ldr r0, [r7, #0x178]
	add r0, r0, r6
	str r0, [r7, #0x178]
	ldr r1, [r7, #0x174]
	cmp r1, #0
	movle r0, #0x1000
	ble _02171D98
	ldr r0, [r7, #0x178]
	cmp r0, r1
	movge r0, #0x1000
	bge _02171D98
	mov r0, r0, lsl #0xc
	bl _s32_div_f
_02171D98:
	ldr r3, [r7, #0x168]
	ldr r1, [r7, #0x16c]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r0, r3, r0
	str r0, [r7, #0x170]
	ldr r1, [r7, #0x178]
	ldr r0, [r7, #0x174]
	cmp r1, r0
	movge r0, #0
	strge r0, [r7, #0x17c]
	mov r0, #1
_02171DD0:
	cmp r0, #0
	beq _02171DF4
	ldr r0, [r7, #0x170]
	mov r1, r0, asr #0xc
	and r0, r1, #0xff
	cmp r0, #0x1f
	strb r1, [r7, #0x166]
	movhi r0, #0x1f
	strhib r0, [r7, #0x166]
_02171DF4:
	cmp r4, #1
	beq _02171E0C
	cmp r4, #2
	beq _02171E14
	cmp r4, #3
	beq _02171E1C
_02171E0C:
	ldrb r5, [r7, #0x166]
	b _02171EB8
_02171E14:
	ldrb r5, [r7, #0x166]
	b _02171EB8
_02171E1C:
	ldr r1, [r7, #0xc]
	ldrb r5, [r7, #0x166]
	cmp r1, #0x3c
	bgt _02171E44
	ldr r0, [r7, #0x10]
	mov r0, r0, lsl #0xc
	rsb r0, r0, #0
	bl _s32_div_f
	add r1, r0, #0x1000
	b _02171E94
_02171E44:
	ldr r2, [r7, #0x10]
	sub r0, r1, r2
	cmp r0, #0x3c
	bgt _02171E7C
	rsb r0, r0, #0x3c
	mov r0, r0, lsl #0xa
	rsb r3, r0, #0
	ldr r2, _02171F24 ; =0x88888889
	mov r0, r3, lsr #0x1f
	smull r1, ip, r2, r3
	add ip, r3, ip
	add ip, r0, ip, asr #5
	add r1, ip, #0x400
	b _02171E94
_02171E7C:
	mov r0, #0xc00
	rsb r0, r0, #0
	mul r0, r2, r0
	sub r1, r1, #0x3c
	bl _s32_div_f
	add r1, r0, #0x1000
_02171E94:
	mov r3, r7
	mov r2, #0
	mov r0, #0x1000
_02171EA0:
	str r1, [r3, #0x40]
	add r2, r2, #1
	str r0, [r3, #0x44]
	cmp r2, #3
	add r3, r3, #0x64
	blt _02171EA0
_02171EB8:
	mov ip, r7
	strb r5, [r7, #0x167]
	mov r3, #0
_02171EC4:
	add r0, ip, #0x100
	ldrsh r1, [r0, #0x58]
	cmp r1, #0
	ble _02171EEC
	sub r1, r1, r6
	strh r1, [r0, #0x58]
	ldrh r2, [r0, #0x5a]
	ldrsh r1, [r0, #0x5c]
	add r1, r2, r1
	strh r1, [r0, #0x5a]
_02171EEC:
	add r3, r3, #1
	cmp r3, #2
	add ip, ip, #6
	blt _02171EC4
	add r6, r7, #0x20
	mov r5, #0
_02171F04:
	mov r0, r6
	bl ov0_0217287C
	add r5, r5, #1
	cmp r5, #3
	add r6, r6, #0x64
	blt _02171F04
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02171F24: .word 0x88888889

	arm_func_start _ZN24CFieldEffectSpaceCrevice12ov0_02142344EP8Camera2D
_ZN24CFieldEffectSpaceCrevice12ov0_02142344EP8Camera2D: ; 0x02171F28
	mov r0, #0
	bx lr
	arm_func_end _ZN24CFieldEffectSpaceCrevice12ov0_02142344EP8Camera2D

	arm_func_start ov0_02171F30
ov0_02171F30: ; 0x02171F30
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x94
	mov fp, r0
	ldr r0, [fp, #0x14]
	str r1, [sp, #4]
	cmp r0, #0
	str r2, [sp, #8]
	cmpne r0, #4
	addeq sp, sp, #0x94
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, #0x1f000
	rsb r0, r0, #0
	mov sb, fp
	mov sl, fp
	add r8, fp, #0x20
	mov r5, #0
	str r0, [sp, #0x10]
	add r4, sp, #0x54
	arm_func_end ov0_02171F30
_02171F78:
	ldr r1, [r8, #0x30]
	ldr r0, [r8, #0x38]
	ldr r2, [r8, #0x34]
	sub r0, r0, r1
	add r6, r1, r0, asr #1
	add r0, sb, #0x100
	ldrsh r0, [r0, #0x58]
	ldr r1, [r8, #0x3c]
	mov r3, #0
	mov ip, r0, lsl #0xb
	sub r1, r1, r2
	add r7, r2, r1, asr #1
	mov r0, ip, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, #0x3c000
	orr r1, r1, ip, lsr #20
	mov r0, ip, lsl #0xc
	bl _ll_div
	rsb r0, r0, #0x1800
	bl FX_Inv
	str r0, [sp, #0xc]
	add r0, sb, #0x100
	ldrsh r1, [r0, #0x58]
	mov r3, #0
	cmp r1, #0x2d
	blt _02172008
	rsb r1, r1, #0x3c
	mov r0, #0x1f000
	mul r2, r1, r0
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r2, #0xf000
	bl _ll_div
	b _0217202C
_02172008:
	ldr r0, [sp, #0x10]
	mul r2, r1, r0
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r2, #0x2d000
	bl _ll_div
	rsb r0, r0, #0
_0217202C:
	ldrb r2, [fp, #0x167]
	ldr r1, [sp, #8]
	ldr r3, _02172194 ; =0x84210843
	mul r2, r0, r2
	smull ip, r0, r3, r2
	add r0, r2, r0
	mov r2, r2, lsr #0x1f
	add r0, r2, r0, asr #4
	mov r0, r0, asr #0xc
	str r0, [sl, #0x34]
	add r1, r1, r5
	mov r0, r4
	str r1, [sl, #0x24]
	bl MTX_Identity43_
	mov r0, #0
	str r0, [sp]
	mov r0, r4
	mov r1, r4
	mov r2, r6
	mov r3, r7
	bl MTX_TransApply44
	add r0, sb, #0x100
	ldrh r1, [r0, #0x5a]
	add r0, sp, #0x14
	mov r1, r1, asr #4
	mov r2, r1, lsl #1
	ldr r1, _02172198 ; =FX_SinCosTable_
	mov r3, r2, lsl #1
	ldrsh r1, [r1, r3]
	ldr r3, _02172198 ; =FX_SinCosTable_
	add r2, r3, r2, lsl #1
	ldrsh r2, [r2, #2]
	blx MTX_RotZ44_
	add r0, sp, #0x14
	mov r1, r4
	mov r2, r4
	bl MTX_Concat44
	ldr r2, [sp, #0xc]
	mov r0, #0x1000
	str r0, [sp]
	mov r0, r4
	mov r1, r4
	mov r3, r2
	bl MTX_ScaleApply44
	mov r0, #0
	str r0, [sp]
	rsb r2, r6, #0
	rsb r3, r7, #0
	mov r0, r4
	mov r1, r4
	bl MTX_TransApply44
	ldr r0, _0217219C ; =0x04000440
	mov r1, #3
	str r1, [r0]
	mov r1, #0
	str r1, [r0, #4]
	mov r0, r4
	bl G3_LoadTexMtxTexCoord
	ldr r0, _0217219C ; =0x04000440
	mov r1, #1
	str r1, [r0]
	mov r0, r8
	ldr r2, [r0]
	ldr r1, [sp, #4]
	ldr r2, [r2, #8]
	blx r2
	add r5, r5, #1
	ldr r0, _0217219C ; =0x04000440
	mov r1, #3
	str r1, [r0]
	mov r1, #1
	str r1, [r0, #8]
	str r1, [r0]
	add r8, r8, #0x64
	add sb, sb, #6
	add sl, sl, #0x64
	cmp r5, #2
	blt _02171F78
	ldrb r2, [fp, #0x167]
	ldr r0, [sp, #8]
	add r1, r0, #2
	str r2, [fp, #0xfc]
	str r1, [fp, #0xec]
	add r0, fp, #0xe8
	ldr r2, [r0]
	ldr r1, [sp, #4]
	ldr r2, [r2, #8]
	blx r2
	add sp, sp, #0x94
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02172194: .word 0x84210843
_02172198: .word FX_SinCosTable_
_0217219C: .word 0x04000440

	arm_func_start _ZN24CFieldEffectSpaceCrevice8SetColorEt
_ZN24CFieldEffectSpaceCrevice8SetColorEt: ; 0x021721A0
	strh r1, [r0, #0x28]
	strh r1, [r0, #0x8c]
	bx lr
	arm_func_end _ZN24CFieldEffectSpaceCrevice8SetColorEt

	arm_func_start ov0_021721AC
ov0_021721AC: ; 0x021721AC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r5, r0
	mov r1, r5
	mov r3, #0
	arm_func_end ov0_021721AC
_021721BC:
	add r0, r1, #0x100
	ldrsh r0, [r0, #0x58]
	cmp r0, #0
	bgt _021722C0
	mov r0, #6
	mul r4, r3, r0
	mov r0, #0x64
	mla r1, r3, r0, r5
	add r2, r5, r4
	add r0, r2, #0x100
	mov r2, #0x3c
	strh r2, [r0, #0x58]
	mov r0, #0x1f
	str r0, [r1, #0x34]
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr ip, [r2, #0x448]
	ldmib r1, {r7, lr}
	umull sb, r8, lr, ip
	mla r8, lr, r7, r8
	ldr r7, [r1, #0xc]
	ldr r0, [r1, #0x10]
	mla r8, r7, ip, r8
	ldr lr, [r1, #0x14]
	adds r7, r0, sb
	mov r6, #0
	str r7, [r2, #0x448]
	adc r0, lr, r8
	mov r2, r6, lsl #0x10
	add r3, r5, r4
	str r0, [r1, #4]
	orr r2, r2, r0, lsr #16
	add r0, r3, #0x100
	strh r2, [r0, #0x5a]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r0, r0, #0x1000
	add r1, r1, #0x1400
	mov r2, r6
	ldr ip, [r0, #0x448]
	ldmib r1, {r3, lr}
	umull r7, r6, lr, ip
	mla r6, lr, r3, r6
	ldr lr, [r1, #0xc]
	add r3, r5, #0x15c
	ldr r5, [r1, #0x10]
	mla r6, lr, ip, r6
	adds r7, r5, r7
	ldr r5, [r1, #0x14]
	mov r2, r2, lsl #8
	str r7, [r0, #0x448]
	adc r0, r5, r6
	orr r2, r2, r0, lsr #24
	str r0, [r1, #4]
	sub r0, r2, #0x80
	strh r0, [r3, r4]
	ldrsh r0, [r3, r4]
	cmp r0, #0
	addge r0, r0, #0x80
	strgeh r0, [r3, r4]
	sublt r0, r0, #0x80
	strlth r0, [r3, r4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
_021722C0:
	add r3, r3, #1
	cmp r3, #2
	add r1, r1, #6
	blt _021721BC
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN24CFieldEffectSpaceCrevice12ov0_02142398EP14DrawObjectList
_ZN24CFieldEffectSpaceCrevice12ov0_02142398EP14DrawObjectList: ; 0x021722D4
	ldr ip, _021722E8 ; =FUN_0200912C
	mov r2, r0
	mov r0, r1
	add r1, r2, #0x180
	bx ip
	.align 2, 0
_021722E8: .word _ZN14DrawObjectList6InsertEP11CDrawObject
	arm_func_end _ZN24CFieldEffectSpaceCrevice12ov0_02142398EP14DrawObjectList

	arm_func_start _ZN24CFieldEffectSpaceCrevice17CEffectDrawObject4DrawEP8Camera2Di
_ZN24CFieldEffectSpaceCrevice17CEffectDrawObject4DrawEP8Camera2Di: ; 0x021722EC
	stmdb sp!, {r3, lr}
	str r2, [r0, #0xc]
	ldr r0, [r0, #0x10]
	cmp r0, #0
	beq _02172304
	bl ov0_02171F30
	arm_func_end _ZN24CFieldEffectSpaceCrevice17CEffectDrawObject4DrawEP8Camera2Di
_02172304:
	mov r0, #3
	ldmia sp!, {r3, pc}

	arm_func_start _ZN31CFieldEffectSpaceCreviceFactoryD1Ev
_ZN31CFieldEffectSpaceCreviceFactoryD1Ev: ; 0x0217230C
	stmdb sp!, {r4, lr}
	ldr r1, _0217233C ; =ptr_FUN_overlay_0_0217230c_overlay_0_0217af98
	mov r4, r0
	str r1, [r4]
	bl ov0_02172610
	ldr r3, _02172340 ; =_ZN17UnkClass_02151244D1Ev
	add r0, r4, #4
	mov r1, #2
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0217233C: .word ptr_FUN_overlay_0_0217230c_overlay_0_0217af98
_02172340: .word _ZN17UnkClass_02151244D1Ev
	arm_func_end _ZN31CFieldEffectSpaceCreviceFactoryD1Ev

	arm_func_start ov0_02172344
ov0_02172344: ; 0x02172344
	stmdb sp!, {r4, lr}
	ldr r1, _0217237C ; =ptr_FUN_overlay_0_0217230c_overlay_0_0217af98
	mov r4, r0
	str r1, [r4]
	bl ov0_02172610
	ldr r3, _02172380 ; =_ZN17UnkClass_02151244D1Ev
	add r0, r4, #4
	mov r1, #2
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0217237C: .word ptr_FUN_overlay_0_0217230c_overlay_0_0217af98
_02172380: .word _ZN17UnkClass_02151244D1Ev
	arm_func_end ov0_02172344

	arm_func_start _ZN31CFieldEffectSpaceCreviceFactory6CreateEi
_ZN31CFieldEffectSpaceCreviceFactory6CreateEi: ; 0x02172384
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x7c
	mov r4, #1
	str r4, [sp]
	mov r5, #0
	str r5, [sp, #4]
	mov r6, r1
	str r5, [sp, #8]
	mov r7, r0
	ldr r1, _02172478 ; =s_MEF_overlay_0_0217b068
	ldr r2, _0217247C ; =s_data_Field_Effect_ef104_LZ_bin_overlay_0_0217b06c
	add r0, sp, #0x10
	mov r3, r4
	str r5, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bne _021723E4
	mov r1, r5
	mov r0, r7
	mov r2, r1
	mov r3, r4
	bl ov0_02172518
	mov r4, r0
	arm_func_end _ZN31CFieldEffectSpaceCreviceFactory6CreateEi
_021723E4:
	ldr r0, [r7, #0x38]
	cmp r0, #0
	bne _02172408
	mov r1, #1
	mov r0, r7
	mov r2, r1
	mov r3, r1
	bl ov0_02172518
	mov r4, r0
_02172408:
	add r0, sp, #0x10
	bl _ZN13CArchiveGuardD1Ev
	cmp r4, #0
	beq _0217246C
	mov r0, #0x198
	bl _Znwm
	movs r5, r0
	beq _02172434
	mov r1, r6
	bl ov0_02171938
	mov r5, r0
_02172434:
	cmp r5, #0
	beq _0217246C
	mov r0, r5
	add r2, r7, #4
	mov r1, #0
	bl ov0_02171BAC
	mov r0, r5
	add r2, r7, #4
	mov r1, #1
	bl ov0_02171BAC
	mov r0, r5
	add r2, r7, #0x30
	mov r1, #2
	bl ov0_02171BAC
_0217246C:
	mov r0, r5
	add sp, sp, #0x7c
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_02172478: .word s_MEF_overlay_0_0217b068
_0217247C: .word s_data_Field_Effect_ef104_LZ_bin_overlay_0_0217b06c

	arm_func_start _ZN31CFieldEffectSpaceCreviceFactory5ResetEv
_ZN31CFieldEffectSpaceCreviceFactory5ResetEv: ; 0x02172480
	ldr ip, _02172488 ; =ov0_02172610
	bx ip
	.align 2, 0
_02172488: .word ov0_02172610
	arm_func_end _ZN31CFieldEffectSpaceCreviceFactory5ResetEv

	arm_func_start ov0_0217248C
ov0_0217248C: ; 0x0217248C
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x7c
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	str ip, [sp, #8]
	mov r4, r0
	ldr r1, _02172510 ; =s_MEF_overlay_0_0217b068
	ldr r2, _02172514 ; =s_data_Field_Effect_ef104_LZ_bin_overlay_0_0217b06c
	add r0, sp, #0x10
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _021724E0
	mov r1, #0
	mov r0, r4
	mov r2, r1
	mov r3, r1
	bl ov0_02172518
	arm_func_end ov0_0217248C
_021724E0:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	bne _02172500
	mov r1, #1
	mov r0, r4
	mov r2, r1
	mov r3, #0
	bl ov0_02172518
_02172500:
	add r0, sp, #0x10
	bl _ZN13CArchiveGuardD1Ev
	add sp, sp, #0x7c
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02172510: .word s_MEF_overlay_0_0217b068
_02172514: .word s_data_Field_Effect_ef104_LZ_bin_overlay_0_0217b06c

	arm_func_start ov0_02172518
ov0_02172518: ; 0x02172518
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0xc8
	ldr r5, _02172600 ; =DAT_overlay_0_02172f70
	movs r4, r1
	ldr ip, [r5]
	ldr r1, [r5, #4]
	mov r5, r0
	mov r7, r2
	mov r6, r3
	str ip, [sp]
	str r1, [sp, #4]
	bmi _021725F4
	cmp r4, #2
	bge _021725F4
	ldr r1, _02172604 ; =s_MEF_ef104_02d_ntft_overlay_0_0217b08c
	add r0, sp, #0x68
	bl OS_SPrintf
	ldr r1, _02172608 ; =s_MEF_ef104_02d_ntfp_overlay_0_0217b0a0
	add r0, sp, #8
	mov r2, r7
	bl OS_SPrintf
	cmp r6, #0
	mov r0, #0x2c
	add r2, sp, #8
	beq _021725B8
	mul r6, r4, r0
	add r0, r5, #4
	add r1, sp, #0x68
	add r0, r0, r6
	mov r3, #0
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	cmp r0, #0
	moveq r0, #0
	beq _021725CC
	ldr r0, _0217260C ; =0x027FFC3C
	add r1, r5, r6
	ldr r2, [r0]
	mov r0, #1
	str r2, [r1, #0x2c]
	b _021725CC
	arm_func_end ov0_02172518
_021725B8:
	add r1, r5, #4
	mla r0, r4, r0, r1
	add r1, sp, #0x68
	mov r3, #0
	bl _ZN10NtfTexture4LoadEPKcS1_i
_021725CC:
	mov r1, #0x2c
	mla r2, r4, r1, r5
	add r3, sp, #0
	ldr r3, [r3, r4, lsl #2]
	mov r1, #4
	str r3, [r2, #0x20]
	str r1, [r2, #0x24]
	str r1, [r2, #0x28]
	add sp, sp, #0xc8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_021725F4:
	mov r0, #0
	add sp, sp, #0xc8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02172600: .word DAT_overlay_0_02172f70
_02172604: .word s_MEF_ef104_02d_ntft_overlay_0_0217b08c
_02172608: .word s_MEF_ef104_02d_ntfp_overlay_0_0217b0a0
_0217260C: .word 0x027FFC3C

	arm_func_start ov0_02172610
ov0_02172610: ; 0x02172610
	stmdb sp!, {r3, r4, r5, lr}
	add r5, r0, #4
	mov r4, #0
	arm_func_end ov0_02172610
_0217261C:
	mov r0, r5
	bl _ZN10NtfTexture7ReleaseEv
	add r4, r4, #1
	cmp r4, #2
	add r5, r5, #0x2c
	blt _0217261C
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN19CFEFRasterTransformD1Ev
_ZN19CFEFRasterTransformD1Ev: ; 0x02172638
	stmdb sp!, {r4, lr}
	ldr r1, _0217265C ; =ptr_FUN_overlay_0_02172638_overlay_0_0217af50
	mov r4, r0
	str r1, [r4]
	bl ov0_02172828
	mov r0, r4
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0217265C: .word ptr_FUN_overlay_0_02172638_overlay_0_0217af50
	arm_func_end _ZN19CFEFRasterTransformD1Ev

	arm_func_start ov0_02172660
ov0_02172660: ; 0x02172660
	stmdb sp!, {r4, lr}
	ldr r1, _0217268C ; =ptr_FUN_overlay_0_02172638_overlay_0_0217af50
	mov r4, r0
	str r1, [r4]
	bl ov0_02172828
	mov r0, r4
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0217268C: .word ptr_FUN_overlay_0_02172638_overlay_0_0217af50
	arm_func_end ov0_02172660

	arm_func_start ov0_02172690
ov0_02172690: ; 0x02172690
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	str r2, [r6, #0x28]
	ldr r5, [sp, #0x10]
	str r3, [r6, #0x2c]
	ldr r0, [sp, #0x14]
	str r5, [r6, #0x30]
	ldr r4, [sp, #0x18]
	str r0, [r6, #0x34]
	ldr r0, [sp, #0x1c]
	str r4, [r6, #0x38]
	str r0, [r6, #0x3c]
	strh r1, [r6, #0x52]
	ldrh r0, [r6, #0x52]
	add r0, r0, #2
	mov r0, r0, lsl #4
	bl _Znam
	str r0, [r6, #0x44]
	ldrh r0, [r6, #0x52]
	add r0, r0, #2
	mov r0, r0, lsl #4
	bl _Znam
	str r0, [r6, #0x48]
	ldrh r0, [r6, #0x52]
	add r0, r0, #2
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r6, #0x4c]
	ldrh r0, [r6, #0x52]
	ldr r2, [r6, #0x44]
	ldr r3, [r6, #0x48]
	add r0, r0, #2
	cmp r0, #0
	mov ip, #0
	ble _02172770
	mov r1, ip
	arm_func_end ov0_02172690
_02172720:
	mov lr, r1
_02172724:
	ldr r0, [r6, #0x28]
	cmp lr, #0
	moveq r0, r0, asr #1
	rsbeq r0, r0, #0
	movne r0, r0, asr #1
	str r0, [r2]
	cmp lr, #0
	moveq r0, r5
	movne r0, r4
	add lr, lr, #1
	cmp lr, #2
	str r0, [r3], #8
	add r2, r2, #8
	blt _02172724
	ldrh r0, [r6, #0x52]
	add ip, ip, #1
	add r0, r0, #2
	cmp ip, r0
	blt _02172720
_02172770:
	mov r0, #0
	str r0, [r6, #0x5c]
	ldrh r1, [r6, #0x52]
	ldr r0, [r6, #0x2c]
	bl _s32_div_f
	mov r3, #0
	str r0, [r6, #0x54]
	strb r3, [r6, #0x50]
	strh r3, [r6, #0x58]
	ldrh r0, [r6, #0x52]
	mov r1, r3
	ldrb r2, [r6, #0x50]
	add r0, r0, #2
	cmp r0, #0
	ble _02172818
	ldr r0, _02172824 ; =FX_SinCosTable_
_021727B0:
	mov r4, r1, asr #4
	mov r4, r4, lsl #2
	ldrsh ip, [r0, r4]
	ldr r4, [r6, #0x4c]
	cmp r3, #0
	mov r5, ip, asr #0x1f
	mov r5, r5, lsl #0x11
	mov lr, ip, lsl #0x11
	orr r5, r5, ip, lsr #15
	mov ip, lr, lsr #0xc
	orr ip, ip, r5, lsl #20
	str ip, [r4, r2, lsl #2]
	ble _021727F8
	ldr r4, [r6, #0x54]
	mov r4, r4, asr #0xc
	sub r1, r1, r4, lsl #10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
_021727F8:
	subs r2, r2, #1
	ldrh r4, [r6, #0x52]
	ldrmih r2, [r6, #0x52]
	add r3, r3, #1
	add r4, r4, #2
	addmi r2, r2, #1
	cmp r3, r4
	blt _021727B0
_02172818:
	mov r0, #1
	strb r0, [r6, #0x60]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02172824: .word FX_SinCosTable_

	arm_func_start ov0_02172828
ov0_02172828: ; 0x02172828
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x44]
	cmp r0, #0
	beq _02172848
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x44]
	arm_func_end ov0_02172828
_02172848:
	ldr r0, [r4, #0x48]
	cmp r0, #0
	beq _02172860
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x48]
_02172860:
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x4c]
	ldmia sp!, {r4, pc}

	arm_func_start ov0_0217287C
ov0_0217287C: ; 0x0217287C
	stmdb sp!, {r3, lr}
	ldrh r1, [r0, #0x58]
	add r1, r1, #0x400
	strh r1, [r0, #0x58]
	ldr r1, [r0, #0x5c]
	add r1, r1, #0x1000
	str r1, [r0, #0x5c]
	ldr r3, [r0, #0x54]
	cmp r1, r3
	blt _021728DC
	ldr r2, [r0, #0x5c]
	mov r1, #1
	sub r2, r2, r3
	str r2, [r0, #0x5c]
	strb r1, [r0, #0x60]
	ldrb r1, [r0, #0x50]
	add r2, r1, #1
	strb r2, [r0, #0x50]
	ldrh r1, [r0, #0x52]
	and r2, r2, #0xff
	add r1, r1, #2
	cmp r2, r1
	movge r1, #0
	strgeb r1, [r0, #0x50]
	arm_func_end ov0_0217287C
_021728DC:
	ldrh r3, [r0, #0x58]
	ldr r2, _02172948 ; =FX_SinCosTable_
	ldrb r1, [r0, #0x50]
	mov r3, r3, asr #4
	mov r3, r3, lsl #2
	ldrsh ip, [r2, r3]
	ldr r2, [r0, #0x4c]
	mov r3, ip, asr #0x1f
	mov r3, r3, lsl #0x11
	mov lr, ip, lsl #0x11
	orr r3, r3, ip, lsr #15
	mov ip, lr, lsr #0xc
	orr ip, ip, r3, lsl #20
	str ip, [r2, r1, lsl #2]
	ldrb r1, [r0, #0x60]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	ldrb r2, [r0, #0x50]
	ldr r3, [r0, #0x4c]
	subs ip, r2, #1
	ldrmih r1, [r0, #0x52]
	ldr r2, [r3, r2, lsl #2]
	addmi ip, r1, #1
	mov r1, #0
	str r2, [r3, ip, lsl #2]
	strb r1, [r0, #0x60]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02172948: .word FX_SinCosTable_

	arm_func_start _ZN19CFEFRasterTransform6RenderEP8Camera2D
_ZN19CFEFRasterTransform6RenderEP8Camera2D: ; 0x0217294C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	ldr r0, [sl, #0x14]
	mov r4, r1
	cmp r0, #0
	ble _02172B78
	ldr r0, [sl, #0x40]
	cmp r0, #0
	beq _02172994
	ldrb r1, [sl, #0x61]
	cmp r1, #0
	mov r1, #0
	beq _0217298C
	mov r2, #1
	bl _ZN15NtfTextureParam4BindE15GXTexPlttColor08GXTexGen
	b _02172994
	arm_func_end _ZN19CFEFRasterTransform6RenderEP8Camera2D
_0217298C:
	mov r2, r1
	bl _ZN15NtfTextureParam4BindE15GXTexPlttColor08GXTexGen
_02172994:
	ldr r0, _02172B80 ; =0x04000450
	mov r1, #0
	str r1, [r0]
	ldrh r3, [r4, #0x28]
	ldrh r2, [sl, #8]
	rsb sb, r3, #0xc
	str r2, [r0, #0x30]
	ldr r2, [sl, #0xc]
	ldr r3, [sl, #0x10]
	mov r2, r2, lsl #4
	orr r2, r2, #0xc0
	ldr r4, [sl, #0x14]
	orr r2, r2, r3, lsl #24
	orr r2, r2, r4, lsl #16
	str r2, [r0, #0x54]
	ldr r4, [sl, #0x44]
	ldr r5, [sl, #0x48]
	str r1, [r0, #-0xc]
	ldr r2, [sl, #0x18]
	ldr r3, [sl, #0x1c]
	mov r2, r2, asr sb
	mov r3, r3, asr sb
	str r2, [r0, #0x20]
	str r3, [r0, #0x20]
	str r1, [r0, #0x20]
	ldr r3, [sl, #0x20]
	cmp r3, #0x1000
	ldreq r0, [sl, #0x24]
	cmpeq r0, #0x1000
	beq _02172A24
	ldr r2, [sl, #0x24]
	ldr r1, _02172B84 ; =0x0400046C
	mov r0, #0x1000
	str r3, [r1]
	str r2, [r1]
	str r0, [r1]
_02172A24:
	ldr r0, _02172B88 ; =0x04000500
	mov r1, #3
	str r1, [r0]
	ldrh r0, [sl, #0x52]
	ldr r1, [sl, #0x2c]
	ldrb r7, [sl, #0x50]
	rsb r1, r1, #0
	add r0, r0, #2
	cmp r0, #0
	mov r6, r1, asr #1
	mov fp, #0
	ble _02172B64
_02172A54:
	mov r0, r6, asr #0x1f
	mov r1, r0, lsl #0xc
	ldr r2, [sl, #0x2c]
	ldr r8, [sl, #0x34]
	orr r1, r1, r6, lsr #20
	str r8, [sp]
	mov r0, r6, lsl #0xc
	mov r3, r2, asr #0x1f
	mov r8, #0
	bl _ll_div
	add r1, r0, #0x800
	ldr r2, [sl, #0x3c]
	ldr r0, [sp]
	sub r0, r2, r0
	smull r2, r1, r0, r1
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	ldr r0, [sp]
	mov r1, r6, asr sb
	add r0, r0, r2
	mov r0, r0, lsl #8
	mov r1, r1, lsl #0x10
	mov r0, r0, asr #0x10
	mov r1, r1, asr #0x10
	mov r0, r0, lsl #0x10
	mov r1, r1, lsl #0x10
	mov r2, r0, lsr #0x10
	ldr r0, _02172B8C ; =0x04000488
	mov r1, r1, lsr #0x10
_02172AC8:
	ldr ip, [sl, #0x4c]
	add r8, r8, #1
	ldr r3, [r5], #8
	ldr ip, [ip, r7, lsl #2]
	cmp r8, #2
	add r3, r3, ip
	mov r3, r3, lsl #8
	mov r3, r3, asr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	orr r3, r3, r2, lsl #16
	str r3, [r0]
	ldr r3, [r4], #8
	ldr ip, [sl, #4]
	mov r3, r3, asr sb
	mov ip, ip, lsl #0x10
	mov ip, ip, asr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, asr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	orr r3, r3, r1, lsl #16
	str r3, [r0, #4]
	mov r3, ip, lsl #0x10
	mov r3, r3, lsr #0x10
	str r3, [r0, #4]
	blt _02172AC8
	cmp fp, #0
	ldreq r0, [sl, #0x5c]
	add fp, fp, #1
	ldrne r0, [sl, #0x54]
	subs r7, r7, #1
	add r6, r6, r0
	ldrmih r0, [sl, #0x52]
	addmi r7, r0, #1
	ldrh r0, [sl, #0x52]
	add r0, r0, #2
	cmp fp, r0
	blt _02172A54
_02172B64:
	ldr r1, _02172B90 ; =0x04000504
	mov r0, #0
	str r0, [r1]
	mov r0, #1
	str r0, [r1, #-0xbc]
_02172B78:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02172B80: .word 0x04000450
_02172B84: .word 0x0400046C
_02172B88: .word 0x04000500
_02172B8C: .word 0x04000488
_02172B90: .word 0x04000504

	arm_func_start _ZN24CFieldEffectSpaceCrevice7IsReadyEv
_ZN24CFieldEffectSpaceCrevice7IsReadyEv: ; 0x02172B94
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, #1
	mov r5, #0
	ldr lr, _02172BF0 ; =0x027FFC3C
	mov r1, r5
	mov r2, r4
	arm_func_end _ZN24CFieldEffectSpaceCrevice7IsReadyEv
_02172BAC:
	add r3, r0, r5, lsl #2
	ldr r3, [r3, #0x14c]
	cmp r3, #0
	beq _02172BDC
	ldr ip, [lr]
	ldr r3, [r3, #0x28]
	cmp r3, ip
	movne r3, r2
	moveq r3, r1
	cmp r3, #0
	moveq r4, #0
	beq _02172BE8
_02172BDC:
	add r5, r5, #1
	cmp r5, #3
	blt _02172BAC
_02172BE8:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02172BF0: .word 0x027FFC3C

	arm_func_start _ZN24CFieldEffectSpaceCrevice11GetEffectIdEv
_ZN24CFieldEffectSpaceCrevice11GetEffectIdEv: ; 0x02172BF4
	mov r0, #0x1e
	bx lr
	arm_func_end _ZN24CFieldEffectSpaceCrevice11GetEffectIdEv

	arm_func_start ov0_02172BFC
ov0_02172BFC: ; 0x02172BFC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02172BFC
	; 0x02172C10

    .rodata


    .global DAT_overlay_0_02172f3c
DAT_overlay_0_02172f3c: ; 0x02172F3C
	.byte 0x0C

    .global DAT_overlay_0_02172f3d
DAT_overlay_0_02172f3d: ; 0x02172F3D
	.byte 0x00, 0x1F, 0x00
	.byte 0x00, 0x00, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172f48
DAT_overlay_0_02172f48: ; 0x02172F48
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172f4c
DAT_overlay_0_02172f4c: ; 0x02172F4C
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0xFE, 0xFF
	.byte 0x00, 0x80, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF

    .global DAT_overlay_0_02172f70
DAT_overlay_0_02172f70: ; 0x02172F70
	.byte 0x06, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172f74
DAT_overlay_0_02172f74: ; 0x02172F74
	.byte 0x01, 0x00, 0x00, 0x00

    .section .sinit,4 ; 0x02172F78

    .data

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ddc
PTR_ptr_FUN_020835bc_overlay_0_02179ddc: ; 0x02179DDC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_22CFieldEffectDarkShadow_overlay_0_02179df4
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_02179de8
PTR_ptr_FUN_020835bc_overlay_0_02179de8: ; 0x02179DE8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_29CFieldEffectDarkShadowFactory_overlay_0_02179e30
	.word _ZTI19CFieldEffectFactory

    .global s_22CFieldEffectDarkShadow_overlay_0_02179df4
s_22CFieldEffectDarkShadow_overlay_0_02179df4: ; 0x02179DF4
	.asciz "22CFieldEffectDarkShadow"

    .global DAT_overlay_0_02179E0D
DAT_overlay_0_02179E0D:
	.byte 0x00, 0x00, 0x00
	.global _ZTV29CFieldEffectDarkShadowFactory
_ZTV29CFieldEffectDarkShadowFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179de8

    .global PTR_LAB_overlay_0_021518a0_overlay_0_02179e18
PTR_LAB_overlay_0_021518a0_overlay_0_02179e18: ; 0x02179E18
	.word _ZN29CFieldEffectDarkShadowFactoryD1Ev

    .global ptr_FUN_overlay_0_0216a434_overlay_0_02179e1c
ptr_FUN_overlay_0_0216a434_overlay_0_02179e1c: ; 0x02179E1C
	.word ov0_0216A434

    .global ptr_FUN_overlay_0_0216a340_overlay_0_02179e20
ptr_FUN_overlay_0_0216a340_overlay_0_02179e20: ; 0x02179E20
	.word _ZN29CFieldEffectDarkShadowFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_29CFieldEffectDarkShadowFactory_overlay_0_02179e30
s_29CFieldEffectDarkShadowFactory_overlay_0_02179e30: ; 0x02179E30
	.asciz "29CFieldEffectDarkShadowFactory"

    .global DAT_overlay_0_02179E50
DAT_overlay_0_02179E50:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ddc

    .global ptr_FUN_overlay_0_02169b90_overlay_0_02179e58
ptr_FUN_overlay_0_02169b90_overlay_0_02179e58: ; 0x02179E58
	.word _ZN22CFieldEffectDarkShadowD1Ev

    .global ptr_FUN_overlay_0_02169bdc_overlay_0_02179e5c
ptr_FUN_overlay_0_02169bdc_overlay_0_02179e5c: ; 0x02179E5C
	.word ov0_02169BDC

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179e60
ptr_FUN_overlay_0_021423a4_overlay_0_02179e60: ; 0x02179E60
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN22CFieldEffectDarkShadow11GetEffectIdEv
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179e6c
ptr_FUN_overlay_0_021421d0_overlay_0_02179e6c: ; 0x02179E6C
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179e70
ptr_FUN_overlay_0_02142380_overlay_0_02179e70: ; 0x02179E70
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_02179e74
ptr_FUN_overlay_0_021421f0_overlay_0_02179e74: ; 0x02179E74
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02169dc4_overlay_0_02179e7c
ptr_FUN_overlay_0_02169dc4_overlay_0_02179e7c: ; 0x02179E7C
	.word _ZN22CFieldEffectDarkShadow12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216a06c_overlay_0_02179e80
ptr_FUN_overlay_0_0216a06c_overlay_0_02179e80: ; 0x02179E80
	.word _ZN22CFieldEffectDarkShadow12ov0_02142344EP8Camera2D
	.word _ZN22CFieldEffectDarkShadow12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_02169c30_overlay_0_02179e90
ptr_FUN_overlay_0_02169c30_overlay_0_02179e90: ; 0x02179E90
	.word _ZN22CFieldEffectDarkShadow8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt

    .global ptr_FUN_overlay_0_0216a2d4_overlay_0_02179e9c
ptr_FUN_overlay_0_0216a2d4_overlay_0_02179e9c: ; 0x02179E9C
	.word _ZN22CFieldEffectDarkShadow12sub_0203331CERK7Point2Di

    .global ptr_FUN_overlay_0_0216a270_overlay_0_02179ea0
ptr_FUN_overlay_0_0216a270_overlay_0_02179ea0: ; 0x02179EA0
	.word _ZN22CFieldEffectDarkShadow12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global PTR_ptr_FUN_02083578_overlay_0_02179eb4
PTR_ptr_FUN_02083578_overlay_0_02179eb4: ; 0x02179EB4
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_24TFieldParticleForceFieldI16CSi_overlay_0_0217a17c

    .global PTR_ptr_FUN_02083578_overlay_0_02179ebc
PTR_ptr_FUN_02083578_overlay_0_02179ebc: ; 0x02179EBC
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_21TFieldParticleEmitterI16CSimpl_overlay_0_0217a150

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ec4
PTR_ptr_FUN_020835bc_overlay_0_02179ec4: ; 0x02179EC4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_30TFieldParticleSmokeRectEmitter_overlay_0_0217a1dc
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ed0

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ed0
PTR_ptr_FUN_020835bc_overlay_0_02179ed0: ; 0x02179ED0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_25TFieldParticleRectEmitterI16CS_overlay_0_0217a1ac
	.word PTR_ptr_FUN_02083578_overlay_0_02179ebc

    .global PTR_ptr_FUN_020835bc_overlay_0_02179edc
PTR_ptr_FUN_020835bc_overlay_0_02179edc: ; 0x02179EDC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N25CFieldEffectDarknessClear11CF_overlay_0_0217a0f8
	.word PTR_ptr_FUN_02083578_overlay_0_02179eb4

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ee8
PTR_ptr_FUN_020835bc_overlay_0_02179ee8: ; 0x02179EE8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_32CFieldEffectDarknessClearFacto_overlay_0_0217a058
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ef4
PTR_ptr_FUN_020835bc_overlay_0_02179ef4: ; 0x02179EF4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N26CFieldEffectDarknessClear211C_overlay_0_0217a124
	.word PTR_ptr_FUN_02083578_overlay_0_02179eb4

    .global PTR_ptr_FUN_020835bc_overlay_0_02179f00
PTR_ptr_FUN_020835bc_overlay_0_02179f00: ; 0x02179F00
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_26CFieldEffectDarknessClear2_overlay_0_02179fb8
	.word PTR_ptr_FUN_020835bc_overlay_0_02179f18

    .global PTR_ptr_FUN_020835bc_overlay_0_02179f0c
PTR_ptr_FUN_020835bc_overlay_0_02179f0c: ; 0x02179F0C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_25CFieldEffectDarknessClear_overlay_0_02179f80
	.word PTR_ptr_FUN_020835bc_overlay_0_02179f18

    .global PTR_ptr_FUN_020835bc_overlay_0_02179f18
PTR_ptr_FUN_020835bc_overlay_0_02179f18: ; 0x02179F18
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_20TFieldEffectParticleI16CSimple_overlay_0_0217a0cc
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_02179f24
PTR_ptr_FUN_020835bc_overlay_0_02179f24: ; 0x02179F24
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N26CFieldEffectDarknessClear28CE_overlay_0_0217a0a4
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ec4

    .global PTR_ptr_FUN_020835bc_overlay_0_02179f30
PTR_ptr_FUN_020835bc_overlay_0_02179f30: ; 0x02179F30
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N25CFieldEffectDarknessClear8CEm_overlay_0_0217a07c
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ec4
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179edc

    .global PTR_LAB_overlay_0_0216a5d0_overlay_0_02179f44
PTR_LAB_overlay_0_0216a5d0_overlay_0_02179f44: ; 0x02179F44
	.word _ZN25CFieldEffectDarknessClear11CForceFieldD1Ev

    .global ptr_FUN_overlay_0_0216c658_overlay_0_02179f48
ptr_FUN_overlay_0_0216c658_overlay_0_02179f48: ; 0x02179F48
	.word ov0_0216C658

    .global ptr_FUN_overlay_0_0216af8c_overlay_0_02179f4c
ptr_FUN_overlay_0_0216af8c_overlay_0_02179f4c: ; 0x02179F4C
	.word _ZN25CFieldEffectDarknessClear11CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ef4

    .global PTR_LAB_overlay_0_0216b52c_overlay_0_02179f58
PTR_LAB_overlay_0_0216b52c_overlay_0_02179f58: ; 0x02179F58
	.word _ZN26CFieldEffectDarknessClear211CForceFieldD1Ev

    .global ptr_FUN_overlay_0_0216c680_overlay_0_02179f5c
ptr_FUN_overlay_0_0216c680_overlay_0_02179f5c: ; 0x02179F5C
	.word ov0_0216C680

    .global ptr_FUN_overlay_0_0216c0a0_overlay_0_02179f60
ptr_FUN_overlay_0_0216c0a0_overlay_0_02179f60: ; 0x02179F60
	.word _ZN26CFieldEffectDarknessClear211CForceField5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_02083578_overlay_0_02179ebc

    .global PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c
PTR_LAB_overlay_0_0216cb50_overlay_0_02179f6c: ; 0x02179F6C
	.word ov0_0216CB50

    .global ptr_FUN_overlay_0_0216c6bc_overlay_0_02179f70
ptr_FUN_overlay_0_0216c6bc_overlay_0_02179f70: ; 0x02179F70
	.word ov0_0216C6BC
	.word ov0_0216AE74
	.word ov0_0216BFFC
	.byte 0x00, 0x00, 0x00, 0x00

    .global s_25CFieldEffectDarknessClear_overlay_0_02179f80
s_25CFieldEffectDarknessClear_overlay_0_02179f80: ; 0x02179F80
	.asciz "25CFieldEffectDarknessClear"

    .global DAT_overlay_0_02179F9C
DAT_overlay_0_02179F9C:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ed0

    .global PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4
PTR_LAB_overlay_0_0216cb68_overlay_0_02179fa4: ; 0x02179FA4
	.word _ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED1Ev

    .global ptr_FUN_overlay_0_0216cb54_overlay_0_02179fa8
ptr_FUN_overlay_0_0216cb54_overlay_0_02179fa8: ; 0x02179FA8
	.word _ZN25TFieldParticleRectEmitterI16CSimpleSpriteNTFED0Ev
	.word ov0_0216AE74
	.word ov0_0216BFFC
	.byte 0x00, 0x00, 0x00, 0x00

    .global s_26CFieldEffectDarknessClear2_overlay_0_02179fb8
s_26CFieldEffectDarknessClear2_overlay_0_02179fb8: ; 0x02179FB8
	.asciz "26CFieldEffectDarknessClear2"

    .global DAT_overlay_0_02179FD5
DAT_overlay_0_02179FD5:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02179f30

    .global PTR_LAB_overlay_0_0216a5d4_overlay_0_02179fe0
PTR_LAB_overlay_0_0216a5d4_overlay_0_02179fe0: ; 0x02179FE0
	.word _ZN25CFieldEffectDarknessClear8CEmitterD1Ev

    .global ptr_FUN_overlay_0_0216c66c_overlay_0_02179fe4
ptr_FUN_overlay_0_0216c66c_overlay_0_02179fe4: ; 0x02179FE4
	.word ov0_0216C66C
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE5func2Ev
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE6UpdateEi

    .global ptr_FUN_overlay_0_0216b0a0_overlay_0_02179ff0
ptr_FUN_overlay_0_0216b0a0_overlay_0_02179ff0: ; 0x02179FF0
	.word _ZN25CFieldEffectDarknessClear8CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4StopEv
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ec4

    .global PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000
PTR_LAB_overlay_0_0216cb80_overlay_0_0217a000: ; 0x0217A000
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED1Ev

    .global ptr_FUN_overlay_0_0216cb6c_overlay_0_0217a004
ptr_FUN_overlay_0_0216cb6c_overlay_0_0217a004: ; 0x0217A004
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFED0Ev
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE5func2Ev
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE6UpdateEi

    .global ptr_FUN_overlay_0_0216c788_overlay_0_0217a010
ptr_FUN_overlay_0_0216c788_overlay_0_0217a010: ; 0x0217A010
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4EmitEP14TFieldParticleIS0_E
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4StopEv
	.global _ZTV32CFieldEffectDarknessClearFactory
_ZTV32CFieldEffectDarknessClearFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ee8

    .global PTR_LAB_overlay_0_021518a4_overlay_0_0217a020
PTR_LAB_overlay_0_021518a4_overlay_0_0217a020: ; 0x0217A020
	.word _ZN32CFieldEffectDarknessClearFactoryD1Ev

    .global ptr_FUN_overlay_0_0216c6a8_overlay_0_0217a024
ptr_FUN_overlay_0_0216c6a8_overlay_0_0217a024: ; 0x0217A024
	.word ov0_0216C6A8

    .global ptr_FUN_overlay_0_0216c590_overlay_0_0217a028
ptr_FUN_overlay_0_0216c590_overlay_0_0217a028: ; 0x0217A028
	.word _ZN32CFieldEffectDarknessClearFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179f24

    .global PTR_LAB_overlay_0_0216b530_overlay_0_0217a040
PTR_LAB_overlay_0_0216b530_overlay_0_0217a040: ; 0x0217A040
	.word _ZN26CFieldEffectDarknessClear28CEmitterD1Ev

    .global ptr_FUN_overlay_0_0216c694_overlay_0_0217a044
ptr_FUN_overlay_0_0216c694_overlay_0_0217a044: ; 0x0217A044
	.word ov0_0216C694
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE5func2Ev
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE6UpdateEi

    .global ptr_FUN_overlay_0_0216c320_overlay_0_0217a050
ptr_FUN_overlay_0_0216c320_overlay_0_0217a050: ; 0x0217A050
	.word _ZN26CFieldEffectDarknessClear28CEmitter4EmitEP14TFieldParticleI16CSimpleSpriteNTFE
	.word _ZN30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE4StopEv

    .global s_32CFieldEffectDarknessClearFacto_overlay_0_0217a058
s_32CFieldEffectDarknessClearFacto_overlay_0_0217a058: ; 0x0217A058
	.asciz "32CFieldEffectDarknessClearFactory"

    .global DAT_overlay_0_0217A07B
DAT_overlay_0_0217A07B:
	.byte 0x00

    .global s_N25CFieldEffectDarknessClear8CEm_overlay_0_0217a07c
s_N25CFieldEffectDarknessClear8CEm_overlay_0_0217a07c: ; 0x0217A07C
	.asciz "N25CFieldEffectDarknessClear8CEmitterE"

    .global DAT_overlay_0_0217A0A3
DAT_overlay_0_0217A0A3:
	.byte 0x00

    .global s_N26CFieldEffectDarknessClear28CE_overlay_0_0217a0a4
s_N26CFieldEffectDarknessClear28CE_overlay_0_0217a0a4: ; 0x0217A0A4
	.asciz "N26CFieldEffectDarknessClear28CEmitterE"

    .global s_20TFieldEffectParticleI16CSimple_overlay_0_0217a0cc
s_20TFieldEffectParticleI16CSimple_overlay_0_0217a0cc: ; 0x0217A0CC
	.asciz "20TFieldEffectParticleI16CSimpleSpriteNTFE"

    .global DAT_overlay_0_0217A0F7
DAT_overlay_0_0217A0F7:
	.byte 0x00

    .global s_N25CFieldEffectDarknessClear11CF_overlay_0_0217a0f8
s_N25CFieldEffectDarknessClear11CF_overlay_0_0217a0f8: ; 0x0217A0F8
	.asciz "N25CFieldEffectDarknessClear11CForceFieldE"

    .global DAT_overlay_0_0217A123
DAT_overlay_0_0217A123:
	.byte 0x00

    .global s_N26CFieldEffectDarknessClear211C_overlay_0_0217a124
s_N26CFieldEffectDarknessClear211C_overlay_0_0217a124: ; 0x0217A124
	.asciz "N26CFieldEffectDarknessClear211CForceFieldE"

    .global s_21TFieldParticleEmitterI16CSimpl_overlay_0_0217a150
s_21TFieldParticleEmitterI16CSimpl_overlay_0_0217a150: ; 0x0217A150
	.asciz "21TFieldParticleEmitterI16CSimpleSpriteNTFE"

    .global s_24TFieldParticleForceFieldI16CSi_overlay_0_0217a17c
s_24TFieldParticleForceFieldI16CSi_overlay_0_0217a17c: ; 0x0217A17C
	.asciz "24TFieldParticleForceFieldI16CSimpleSpriteNTFE"

    .global DAT_overlay_0_0217A1AB
DAT_overlay_0_0217A1AB:
	.byte 0x00

    .global s_25TFieldParticleRectEmitterI16CS_overlay_0_0217a1ac
s_25TFieldParticleRectEmitterI16CS_overlay_0_0217a1ac: ; 0x0217A1AC
	.asciz "25TFieldParticleRectEmitterI16CSimpleSpriteNTFE"

    .global s_30TFieldParticleSmokeRectEmitter_overlay_0_0217a1dc
s_30TFieldParticleSmokeRectEmitter_overlay_0_0217a1dc: ; 0x0217A1DC
	.asciz "30TFieldParticleSmokeRectEmitterI16CSimpleSpriteNTFE"

    .global DAT_overlay_0_0217A211
DAT_overlay_0_0217A211:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02179f0c

    .global ptr_FUN_overlay_0_0216a5d8_overlay_0_0217a21c
ptr_FUN_overlay_0_0216a5d8_overlay_0_0217a21c: ; 0x0217A21C
	.word _ZN25CFieldEffectDarknessClearD1Ev

    .global ptr_FUN_overlay_0_0216a690_overlay_0_0217a220
ptr_FUN_overlay_0_0216a690_overlay_0_0217a220: ; 0x0217A220
	.word ov0_0216A690

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a224
ptr_FUN_overlay_0_021423a4_overlay_0_0217a224: ; 0x0217A224
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN25CFieldEffectDarknessClear11GetEffectIdEv
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a230
ptr_FUN_overlay_0_021421d0_overlay_0_0217a230: ; 0x0217A230
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a234
ptr_FUN_overlay_0_02142380_overlay_0_0217a234: ; 0x0217A234
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0216adc4_overlay_0_0217a238
ptr_FUN_overlay_0_0216adc4_overlay_0_0217a238: ; 0x0217A238
	.word _ZN25CFieldEffectDarknessClear12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216bd40_overlay_0_0217a240
ptr_FUN_overlay_0_0216bd40_overlay_0_0217a240: ; 0x0217A240
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216ae78_overlay_0_0217a244
ptr_FUN_overlay_0_0216ae78_overlay_0_0217a244: ; 0x0217A244
	.word _ZN25CFieldEffectDarknessClear12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216a804_overlay_0_0217a254
ptr_FUN_overlay_0_0216a804_overlay_0_0217a254: ; 0x0217A254
	.word _ZN25CFieldEffectDarknessClear8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam
	.word _ZN25CFieldEffectDarknessClear13GetForceFieldEv
	.word _ZN25CFieldEffectDarknessClear10GetEmitterEv
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179f18

    .global ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c
ptr_FUN_overlay_0_0216caa0_overlay_0_0217a28c: ; 0x0217A28C
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFED1Ev

    .global ptr_FUN_overlay_0_0216c6d0_overlay_0_0217a290
ptr_FUN_overlay_0_0216c6d0_overlay_0_0217a290: ; 0x0217A290
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFED0Ev

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a294
ptr_FUN_overlay_0_021423a4_overlay_0_0217a294: ; 0x0217A294
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN12CFieldEffect11GetEffectIdEv
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a2a0
ptr_FUN_overlay_0_021421d0_overlay_0_0217a2a0: ; 0x0217A2A0
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a2a4
ptr_FUN_overlay_0_02142380_overlay_0_0217a2a4: ; 0x0217A2A4
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0216ae28_overlay_0_0217a2a8
ptr_FUN_overlay_0_0216ae28_overlay_0_0217a2a8: ; 0x0217A2A8
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216bd40_overlay_0_0217a2b0
ptr_FUN_overlay_0_0216bd40_overlay_0_0217a2b0: ; 0x0217A2B0
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216af14_overlay_0_0217a2b4
ptr_FUN_overlay_0_0216af14_overlay_0_0217a2b4: ; 0x0217A2B4
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216aac8_overlay_0_0217a2c4
ptr_FUN_overlay_0_0216aac8_overlay_0_0217a2c4: ; 0x0217A2C4
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179f00

    .global ptr_FUN_overlay_0_0216b534_overlay_0_0217a2fc
ptr_FUN_overlay_0_0216b534_overlay_0_0217a2fc: ; 0x0217A2FC
	.word _ZN26CFieldEffectDarknessClear2D1Ev

    .global ptr_FUN_overlay_0_0216b5ec_overlay_0_0217a300
ptr_FUN_overlay_0_0216b5ec_overlay_0_0217a300: ; 0x0217A300
	.word ov0_0216B5EC

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a304
ptr_FUN_overlay_0_021423a4_overlay_0_0217a304: ; 0x0217A304
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN26CFieldEffectDarknessClear212sub_02033028Ev
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a310
ptr_FUN_overlay_0_021421d0_overlay_0_0217a310: ; 0x0217A310
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a314
ptr_FUN_overlay_0_02142380_overlay_0_0217a314: ; 0x0217A314
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0216ba08_overlay_0_0217a318
ptr_FUN_overlay_0_0216ba08_overlay_0_0217a318: ; 0x0217A318
	.word _ZN26CFieldEffectDarknessClear212ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216ba7c_overlay_0_0217a320
ptr_FUN_overlay_0_0216ba7c_overlay_0_0217a320: ; 0x0217A320
	.word _ZN26CFieldEffectDarknessClear212ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216c004_overlay_0_0217a324
ptr_FUN_overlay_0_0216c004_overlay_0_0217a324: ; 0x0217A324
	.word _ZN26CFieldEffectDarknessClear212ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216b744_overlay_0_0217a334
ptr_FUN_overlay_0_0216b744_overlay_0_0217a334: ; 0x0217A334
	.word _ZN26CFieldEffectDarknessClear212sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam
	.word _ZN26CFieldEffectDarknessClear213GetForceFieldEv
	.word _ZN26CFieldEffectDarknessClear210GetEmitterEv

    .global DAT_overlay_0_0217a364
DAT_overlay_0_0217a364: ; 0x0217A364
	.byte 0x00, 0x6A, 0xFB, 0xFF

    .global DAT_overlay_0_0217a368
DAT_overlay_0_0217a368: ; 0x0217A368
	.byte 0x00, 0x96, 0xFA, 0xFF, 0x80, 0x96, 0xFC, 0xFF
	.byte 0x60, 0x26, 0xFB, 0xFF, 0x80, 0xAD, 0x01, 0x00, 0x10, 0xE9, 0xFA, 0xFF, 0x80, 0x00, 0x06, 0x00
	.byte 0xC0, 0xA9, 0xFC, 0xFF, 0x40, 0x46, 0xF8, 0xFF, 0xB0, 0x9E, 0xFF, 0xFF, 0xC0, 0x77, 0xFD, 0xFF
	.byte 0xF0, 0x69, 0xFD, 0xFF, 0x40, 0x21, 0x00, 0x00, 0x40, 0x30, 0xFF, 0xFF, 0x40, 0x51, 0x04, 0x00
	.byte 0x30, 0xA4, 0xFE, 0xFF, 0x00, 0xCD, 0xFB, 0xFF, 0x90, 0x51, 0x00, 0x00, 0xC0, 0xD3, 0xFC, 0xFF
	.byte 0x80, 0xCF, 0x01, 0x00, 0x80, 0xD0, 0x00, 0x00, 0x70, 0x85, 0x01, 0x00, 0xC0, 0x9F, 0x05, 0x00
	.byte 0x80, 0xE3, 0x02, 0x00, 0x80, 0xC9, 0xF8, 0xFF, 0xD0, 0x0A, 0x04, 0x00, 0x00, 0xEB, 0xFD, 0xFF
	.byte 0x50, 0x70, 0x03, 0x00, 0xC0, 0xEF, 0x01, 0x00, 0x80, 0xB6, 0x05, 0x00, 0x00, 0x33, 0x05, 0x00
	.byte 0xB0, 0x61, 0x03, 0x00, 0x00, 0x9F, 0xF8, 0xFF, 0xF0, 0xD4, 0xFB, 0xFF, 0x80, 0x06, 0xFF, 0xFF
	.byte 0xE0, 0xC3, 0xFB, 0xFF, 0x40, 0x86, 0x01, 0x00, 0x20, 0xA9, 0xFA, 0xFF, 0x00, 0x84, 0x05, 0x00
	.byte 0x50, 0x64, 0xFA, 0xFF, 0x40, 0x1D, 0xFA, 0xFF, 0x60, 0xA3, 0xFF, 0xFF, 0xC0, 0x2D, 0xFF, 0xFF
	.byte 0xC0, 0xA2, 0xFD, 0xFF, 0x40, 0x01, 0x03, 0x00, 0xD0, 0xE5, 0xFE, 0xFF, 0xC0, 0xB4, 0x06, 0x00
	.byte 0xB0, 0x4F, 0xFD, 0xFF, 0xC0, 0xD4, 0xF9, 0xFF, 0xA0, 0x2E, 0x01, 0x00, 0x00, 0x59, 0xFD, 0xFF
	.byte 0xF0, 0xE9, 0x01, 0x00, 0x80, 0x48, 0x02, 0x00, 0x10, 0xC3, 0x02, 0x00, 0x40, 0x81, 0x06, 0x00
	.byte 0xB0, 0x19, 0x00, 0x00, 0x40, 0xE9, 0xFB, 0xFF, 0x50, 0x6E, 0x05, 0x00, 0x00, 0x26, 0xFD, 0xFF
	.byte 0xF0, 0xBC, 0x04, 0x00, 0x80, 0x52, 0x00, 0x00, 0x90, 0x30, 0x03, 0x00, 0x80, 0xB5, 0x05, 0x00
	.byte 0x20, 0x5D, 0x04, 0x00

    .global DAT_overlay_0_0217a464
DAT_overlay_0_0217a464: ; 0x0217A464
	.byte 0x4D, 0x45, 0x46, 0x00

    .global s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217a468
s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217a468: ; 0x0217A468
	.asciz "data/Field/Effect/ef102_LZ.bin"

    .global DAT_overlay_0_0217A487
DAT_overlay_0_0217A487:
	.byte 0x00

    .global s_MEF_ef102_00_ntft_overlay_0_0217a488
s_MEF_ef102_00_ntft_overlay_0_0217a488: ; 0x0217A488
	.asciz "MEF:ef102_00.ntft"

    .global DAT_overlay_0_0217A49A
DAT_overlay_0_0217A49A:
	.byte 0x00, 0x00

    .global s_MEF_ef102_00_ntfp_overlay_0_0217a49c
s_MEF_ef102_00_ntfp_overlay_0_0217a49c: ; 0x0217A49C
	.asciz "MEF:ef102_00.ntfp"

    .global DAT_overlay_0_0217A4AE
DAT_overlay_0_0217A4AE:
	.byte 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a4b0
PTR_ptr_FUN_020835bc_overlay_0_0217a4b0: ; 0x0217A4B0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N22CFieldEffectAirBubbles14CBubb_overlay_0_0217a520
	.word _ZTI25TFieldParticleRectEmitterI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a4bc
PTR_ptr_FUN_020835bc_overlay_0_0217a4bc: ; 0x0217A4BC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N22CFieldEffectAirBubbles17CBubb_overlay_0_0217a54c
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a4c8
PTR_ptr_FUN_020835bc_overlay_0_0217a4c8: ; 0x0217A4C8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_22CFieldEffectAirBubbles_overlay_0_0217a4e8
	.word _ZTI20TFieldEffectParticleI15CSoftwareSpriteE
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a4bc

    .global PTR_LAB_overlay_0_0216cc48_overlay_0_0217a4dc
PTR_LAB_overlay_0_0216cc48_overlay_0_0217a4dc: ; 0x0217A4DC
	.word _ZN22CFieldEffectAirBubbles17CBubbleForceFieldD1Ev

    .global ptr_FUN_overlay_0_0216d2ac_overlay_0_0217a4e0
ptr_FUN_overlay_0_0216d2ac_overlay_0_0217a4e0: ; 0x0217A4E0
	.word ov0_0216D2AC
	.word _ZN22CFieldEffectAirBubbles17CBubbleForceField5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_22CFieldEffectAirBubbles_overlay_0_0217a4e8
s_22CFieldEffectAirBubbles_overlay_0_0217a4e8: ; 0x0217A4E8
	.asciz "22CFieldEffectAirBubbles"

    .global DAT_overlay_0_0217A501
DAT_overlay_0_0217A501:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_0217a4b0

    .global PTR_LAB_overlay_0_0216cc4c_overlay_0_0217a50c
PTR_LAB_overlay_0_0216cc4c_overlay_0_0217a50c: ; 0x0217A50C
	.word _ZN22CFieldEffectAirBubbles14CBubbleEmitterD1Ev

    .global ptr_FUN_overlay_0_0216d2c0_overlay_0_0217a510
ptr_FUN_overlay_0_0216d2c0_overlay_0_0217a510: ; 0x0217A510
	.word ov0_0216D2C0
	.word _ZN21TFieldParticleEmitterI15CSoftwareSpriteE5func2Ev
	.word _ZN22CFieldEffectAirBubbles14CBubbleEmitter6UpdateEi

    .global ptr_FUN_overlay_0_0216d198_overlay_0_0217a51c
ptr_FUN_overlay_0_0216d198_overlay_0_0217a51c: ; 0x0217A51C
	.word _ZN22CFieldEffectAirBubbles14CBubbleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

    .global s_N22CFieldEffectAirBubbles14CBubb_overlay_0_0217a520
s_N22CFieldEffectAirBubbles14CBubb_overlay_0_0217a520: ; 0x0217A520
	.asciz "N22CFieldEffectAirBubbles14CBubbleEmitterE"

    .global DAT_overlay_0_0217A54B
DAT_overlay_0_0217A54B:
	.byte 0x00

    .global s_N22CFieldEffectAirBubbles17CBubb_overlay_0_0217a54c
s_N22CFieldEffectAirBubbles17CBubb_overlay_0_0217a54c: ; 0x0217A54C
	.asciz "N22CFieldEffectAirBubbles17CBubbleForceFieldE"

    .global DAT_overlay_0_0217A57A
DAT_overlay_0_0217A57A:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a4c8

    .global ptr_FUN_overlay_0_0216cc50_overlay_0_0217a584
ptr_FUN_overlay_0_0216cc50_overlay_0_0217a584: ; 0x0217A584
	.word _ZN22CFieldEffectAirBubblesD1Ev

    .global ptr_FUN_overlay_0_0216cd00_overlay_0_0217a588
ptr_FUN_overlay_0_0216cd00_overlay_0_0217a588: ; 0x0217A588
	.word ov0_0216CD00

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a58c
ptr_FUN_overlay_0_021423a4_overlay_0_0217a58c: ; 0x0217A58C
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN22CFieldEffectAirBubbles11GetEffectIdEv
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a598
ptr_FUN_overlay_0_021421d0_overlay_0_0217a598: ; 0x0217A598
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a59c
ptr_FUN_overlay_0_02142380_overlay_0_0217a59c: ; 0x0217A59C
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0215b4a0_overlay_0_0217a5a0
ptr_FUN_overlay_0_0215b4a0_overlay_0_0217a5a0: ; 0x0217A5A0
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02142ab4_overlay_0_0217a5a8
ptr_FUN_overlay_0_02142ab4_overlay_0_0217a5a8: ; 0x0217A5A8
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0215b784_overlay_0_0217a5ac
ptr_FUN_overlay_0_0215b784_overlay_0_0217a5ac: ; 0x0217A5AC
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216cdb8_overlay_0_0217a5bc
ptr_FUN_overlay_0_0216cdb8_overlay_0_0217a5bc: ; 0x0217A5BC
	.word _ZN22CFieldEffectAirBubbles8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global ptr_FUN_overlay_0_021423e8_overlay_0_0217a5e0
ptr_FUN_overlay_0_021423e8_overlay_0_0217a5e0: ; 0x0217A5E0
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021423E8ERK20FieldEffectSpriteRes
	.word _ZN22CFieldEffectAirBubbles13GetForceFieldEv
	.word _ZN22CFieldEffectAirBubbles10GetEmitterEv

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a5ec
PTR_ptr_FUN_020835bc_overlay_0_0217a5ec: ; 0x0217A5EC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectLaserFactory_overlay_0_0217a618
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a5f8
PTR_ptr_FUN_020835bc_overlay_0_0217a5f8: ; 0x0217A5F8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldEffectLaser_overlay_0_0217a604
	.word _ZTI17CFieldEffectActor

    .global s_17CFieldEffectLaser_overlay_0_0217a604
s_17CFieldEffectLaser_overlay_0_0217a604: ; 0x0217A604
	.asciz "17CFieldEffectLaser"

    .global s_24CFieldEffectLaserFactory_overlay_0_0217a618
s_24CFieldEffectLaserFactory_overlay_0_0217a618: ; 0x0217A618
	.asciz "24CFieldEffectLaserFactory"

    .global DAT_overlay_0_0217A633
DAT_overlay_0_0217A633:
	.byte 0x00
	.global _ZTV24CFieldEffectLaserFactory
_ZTV24CFieldEffectLaserFactory:
	.byte 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_0217a5ec

    .global PTR_LAB_overlay_0_02151818_overlay_0_0217a63c
PTR_LAB_overlay_0_02151818_overlay_0_0217a63c: ; 0x0217A63C
	.word _ZN24CFieldEffectLaserFactoryD1Ev

    .global ptr_FUN_overlay_0_0216e114_overlay_0_0217a640
ptr_FUN_overlay_0_0216e114_overlay_0_0217a640: ; 0x0217A640
	.word ov0_0216E114
	.word _ZN24CFieldEffectLaserFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a5f8

    .global ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c
ptr_FUN_overlay_0_0216da38_overlay_0_0217a65c: ; 0x0217A65C
	.word _ZN17CFieldEffectLaserD1Ev

    .global ptr_FUN_overlay_0_0216dae0_overlay_0_0217a660
ptr_FUN_overlay_0_0216dae0_overlay_0_0217a660: ; 0x0217A660
	.word ov0_0216DAE0

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a664
ptr_FUN_overlay_0_021423a4_overlay_0_0217a664: ; 0x0217A664
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectLaser11GetEffectIdEv
	.word _ZN17CFieldEffectActor7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a670
ptr_FUN_overlay_0_021421d0_overlay_0_0217a670: ; 0x0217A670
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a674
ptr_FUN_overlay_0_02142380_overlay_0_0217a674: ; 0x0217A674
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0216deac_overlay_0_0217a678
ptr_FUN_overlay_0_0216deac_overlay_0_0217a678: ; 0x0217A678
	.word _ZN17CFieldEffectLaser12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216db90_overlay_0_0217a680
ptr_FUN_overlay_0_0216db90_overlay_0_0217a680: ; 0x0217A680
	.word _ZN17CFieldEffectLaser12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216dcb4_overlay_0_0217a684
ptr_FUN_overlay_0_0216dcb4_overlay_0_0217a684: ; 0x0217A684
	.word _ZN17CFieldEffectLaser12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN17CFieldEffectLaser8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global s_childid_d_overlay_0_0217a6b8
s_childid_d_overlay_0_0217a6b8: ; 0x0217A6B8
	.asciz "childid= %d"

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a6c4
PTR_ptr_FUN_020835bc_overlay_0_0217a6c4: ; 0x0217A6C4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_31CFieldEffectRisingPhotonFactor_overlay_0_0217a718
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a6d0
PTR_ptr_FUN_020835bc_overlay_0_0217a6d0: ; 0x0217A6D0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectRisingPhoton_overlay_0_0217a6dc
	.word _ZTI12CFieldEffect

    .global s_24CFieldEffectRisingPhoton_overlay_0_0217a6dc
s_24CFieldEffectRisingPhoton_overlay_0_0217a6dc: ; 0x0217A6DC
	.asciz "24CFieldEffectRisingPhoton"

    .global DAT_overlay_0_0217A6F7
DAT_overlay_0_0217A6F7:
	.byte 0x00
	.global _ZTV31CFieldEffectRisingPhotonFactory
_ZTV31CFieldEffectRisingPhotonFactory:
	.byte 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_0217a6c4

    .global PTR_LAB_overlay_0_021518a8_overlay_0_0217a700
PTR_LAB_overlay_0_021518a8_overlay_0_0217a700: ; 0x0217A700
	.word _ZN31CFieldEffectRisingPhotonFactoryD1Ev

    .global ptr_FUN_overlay_0_0216eb38_overlay_0_0217a704
ptr_FUN_overlay_0_0216eb38_overlay_0_0217a704: ; 0x0217A704
	.word ov0_0216EB38
	.word _ZN31CFieldEffectRisingPhotonFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_31CFieldEffectRisingPhotonFactor_overlay_0_0217a718
s_31CFieldEffectRisingPhotonFactor_overlay_0_0217a718: ; 0x0217A718
	.asciz "31CFieldEffectRisingPhotonFactory"

    .global DAT_overlay_0_0217A73A
DAT_overlay_0_0217A73A:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a6d0

    .global ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744
ptr_FUN_overlay_0_0216e1bc_overlay_0_0217a744: ; 0x0217A744
	.word _ZN24CFieldEffectRisingPhotonD1Ev

    .global ptr_FUN_overlay_0_0216e26c_overlay_0_0217a748
ptr_FUN_overlay_0_0216e26c_overlay_0_0217a748: ; 0x0217A748
	.word ov0_0216E26C

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a74c
ptr_FUN_overlay_0_021423a4_overlay_0_0217a74c: ; 0x0217A74C
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN24CFieldEffectRisingPhoton11GetEffectIdEv
	.word _ZN24CFieldEffectRisingPhoton7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a758
ptr_FUN_overlay_0_021421d0_overlay_0_0217a758: ; 0x0217A758
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a75c
ptr_FUN_overlay_0_02142380_overlay_0_0217a75c: ; 0x0217A75C
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0216e5e0_overlay_0_0217a760
ptr_FUN_overlay_0_0216e5e0_overlay_0_0217a760: ; 0x0217A760
	.word _ZN24CFieldEffectRisingPhoton12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216e650_overlay_0_0217a768
ptr_FUN_overlay_0_0216e650_overlay_0_0217a768: ; 0x0217A768
	.word _ZN24CFieldEffectRisingPhoton12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216e908_overlay_0_0217a76c
ptr_FUN_overlay_0_0216e908_overlay_0_0217a76c: ; 0x0217A76C
	.word _ZN24CFieldEffectRisingPhoton12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216e324_overlay_0_0217a77c
ptr_FUN_overlay_0_0216e324_overlay_0_0217a77c: ; 0x0217A77C
	.word _ZN24CFieldEffectRisingPhoton8SetParamEii

    .global ptr_FUN_overlay_0_0216e4e0_overlay_0_0217a780
ptr_FUN_overlay_0_0216e4e0_overlay_0_0217a780: ; 0x0217A780
	.word _ZN24CFieldEffectRisingPhoton12sub_02033244Eiii
	.word _ZN24CFieldEffectRisingPhoton8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global s_MEF_overlay_0_0217a7a0
s_MEF_overlay_0_0217a7a0: ; 0x0217A7A0
	.asciz "MEF"

    .global s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217a7a4
s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217a7a4: ; 0x0217A7A4
	.asciz "data/Field/Effect/ef100_LZ.bin"

    .global DAT_overlay_0_0217A7C3
DAT_overlay_0_0217A7C3:
	.byte 0x00

    .global s_MEF_ef100_00_ntft_overlay_0_0217a7c4
s_MEF_ef100_00_ntft_overlay_0_0217a7c4: ; 0x0217A7C4
	.asciz "MEF:ef100_00.ntft"

    .global DAT_overlay_0_0217A7D6
DAT_overlay_0_0217A7D6:
	.byte 0x00, 0x00

    .global s_MEF_ef100_00_ntfp_overlay_0_0217a7d8
s_MEF_ef100_00_ntfp_overlay_0_0217a7d8: ; 0x0217A7D8
	.asciz "MEF:ef100_00.ntfp"

    .global DAT_overlay_0_0217A7EA
DAT_overlay_0_0217A7EA:
	.byte 0x00, 0x00

    .global s_MEF_ef100_02_ntft_overlay_0_0217a7ec
s_MEF_ef100_02_ntft_overlay_0_0217a7ec: ; 0x0217A7EC
	.asciz "MEF:ef100_02.ntft"

    .global DAT_overlay_0_0217A7FE
DAT_overlay_0_0217A7FE:
	.byte 0x00, 0x00

    .global s_MEF_ef100_02_ntfp_overlay_0_0217a800
s_MEF_ef100_02_ntfp_overlay_0_0217a800: ; 0x0217A800
	.asciz "MEF:ef100_02.ntfp"

    .global DAT_overlay_0_0217A812
DAT_overlay_0_0217A812:
	.byte 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a814
PTR_ptr_FUN_020835bc_overlay_0_0217a814: ; 0x0217A814
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17TFieldEffectSmokeI16CSimpleSpr_overlay_0_0217a900
	.word PTR_ptr_FUN_020835bc_overlay_0_02179f18

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a820
PTR_ptr_FUN_020835bc_overlay_0_0217a820: ; 0x0217A820
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N25CFieldEffectVolcanicSteam9CAn_overlay_0_0217a928
	.word _ZTI11CDrawObject

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a82c
PTR_ptr_FUN_020835bc_overlay_0_0217a82c: ; 0x0217A82C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N25CFieldEffectVolcanicSteam9CAn_overlay_0_0217a8d8
	.word PTR_ptr_FUN_02083578_overlay_0_02179eb4

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a838
PTR_ptr_FUN_020835bc_overlay_0_0217a838: ; 0x0217A838
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_25CFieldEffectVolcanicSteam_overlay_0_0217a878
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a814

    .global PTR_ptr_FUN_020835bc_overlay_0_0217a844
PTR_ptr_FUN_020835bc_overlay_0_0217a844: ; 0x0217A844
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_32CFieldEffectVolcanicSteamFacto_overlay_0_0217a8b4
	.word _ZTI19CFieldEffectFactory
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a82c

    .global PTR_LAB_overlay_0_0216ebb8_overlay_0_0217a858
PTR_LAB_overlay_0_0216ebb8_overlay_0_0217a858: ; 0x0217A858
	.word _ZN25CFieldEffectVolcanicSteam9CAnimatorD1Ev

    .global ptr_FUN_overlay_0_0216f47c_overlay_0_0217a85c
ptr_FUN_overlay_0_0216f47c_overlay_0_0217a85c: ; 0x0217A85C
	.word ov0_0216F47C

    .global ptr_FUN_overlay_0_0216ecc8_overlay_0_0217a860
ptr_FUN_overlay_0_0216ecc8_overlay_0_0217a860: ; 0x0217A860
	.word _ZN25CFieldEffectVolcanicSteam9CAnimator5ApplyEP14TFieldParticleI16CSimpleSpriteNTFEi
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a820

    .global PTR_LAB_overlay_0_0216ebb4_overlay_0_0217a86c
PTR_LAB_overlay_0_0216ebb4_overlay_0_0217a86c: ; 0x0217A86C
	.word _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObjectD1Ev
	.word ov0_0216F468
	.word _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject4DrawEP8Camera2Di

    .global s_25CFieldEffectVolcanicSteam_overlay_0_0217a878
s_25CFieldEffectVolcanicSteam_overlay_0_0217a878: ; 0x0217A878
	.asciz "25CFieldEffectVolcanicSteam"

    .global DAT_overlay_0_0217A894
DAT_overlay_0_0217A894:
	.global _ZTV32CFieldEffectVolcanicSteamFactory
_ZTV32CFieldEffectVolcanicSteamFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a844

    .global ptr_FUN_overlay_0_0216edb8_overlay_0_0217a89c
ptr_FUN_overlay_0_0216edb8_overlay_0_0217a89c: ; 0x0217A89C
	.word _ZN32CFieldEffectVolcanicSteamFactoryD1Ev

    .global ptr_FUN_overlay_0_0216ede0_overlay_0_0217a8a0
ptr_FUN_overlay_0_0216ede0_overlay_0_0217a8a0: ; 0x0217A8A0
	.word ov0_0216EDE0

    .global ptr_FUN_overlay_0_0216eeac_overlay_0_0217a8a4
ptr_FUN_overlay_0_0216eeac_overlay_0_0217a8a4: ; 0x0217A8A4
	.word _ZN32CFieldEffectVolcanicSteamFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN32CFieldEffectVolcanicSteamFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_32CFieldEffectVolcanicSteamFacto_overlay_0_0217a8b4
s_32CFieldEffectVolcanicSteamFacto_overlay_0_0217a8b4: ; 0x0217A8B4
	.asciz "32CFieldEffectVolcanicSteamFactory"

    .global DAT_overlay_0_0217A8D7
DAT_overlay_0_0217A8D7:
	.byte 0x00

    .global s_N25CFieldEffectVolcanicSteam9CAn_overlay_0_0217a8d8
s_N25CFieldEffectVolcanicSteam9CAn_overlay_0_0217a8d8: ; 0x0217A8D8
	.asciz "N25CFieldEffectVolcanicSteam9CAnimatorE"

    .global s_17TFieldEffectSmokeI16CSimpleSpr_overlay_0_0217a900
s_17TFieldEffectSmokeI16CSimpleSpr_overlay_0_0217a900: ; 0x0217A900
	.asciz "17TFieldEffectSmokeI16CSimpleSpriteNTFE"

    .global s_N25CFieldEffectVolcanicSteam9CAn_overlay_0_0217a928
s_N25CFieldEffectVolcanicSteam9CAn_overlay_0_0217a928: ; 0x0217A928
	.asciz "N25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObjectE"

    .global DAT_overlay_0_0217A963
DAT_overlay_0_0217A963:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_0217a814

    .global ptr_FUN_overlay_0_0216f490_overlay_0_0217a96c
ptr_FUN_overlay_0_0216f490_overlay_0_0217a96c: ; 0x0217A96C
	.word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED1Ev

    .global ptr_FUN_overlay_0_0216f3b0_overlay_0_0217a970
ptr_FUN_overlay_0_0216f3b0_overlay_0_0217a970: ; 0x0217A970
	.word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFED0Ev

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a974
ptr_FUN_overlay_0_021423a4_overlay_0_0217a974: ; 0x0217A974
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN12CFieldEffect11GetEffectIdEv
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a980
ptr_FUN_overlay_0_021421d0_overlay_0_0217a980: ; 0x0217A980
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a984
ptr_FUN_overlay_0_02142380_overlay_0_0217a984: ; 0x0217A984
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0216ae28_overlay_0_0217a988
ptr_FUN_overlay_0_0216ae28_overlay_0_0217a988: ; 0x0217A988
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216bd40_overlay_0_0217a990
ptr_FUN_overlay_0_0216bd40_overlay_0_0217a990: ; 0x0217A990
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216af14_overlay_0_0217a994
ptr_FUN_overlay_0_0216af14_overlay_0_0217a994: ; 0x0217A994
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam
	.byte 0x00, 0x00, 0x00, 0x00
	.word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE10GetEmitterEv
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217a838

    .global ptr_FUN_overlay_0_0216ebbc_overlay_0_0217a9dc
ptr_FUN_overlay_0_0216ebbc_overlay_0_0217a9dc: ; 0x0217A9DC
	.word _ZN25CFieldEffectVolcanicSteamD1Ev

    .global ptr_FUN_overlay_0_0216ebd0_overlay_0_0217a9e0
ptr_FUN_overlay_0_0216ebd0_overlay_0_0217a9e0: ; 0x0217A9E0
	.word ov0_0216EBD0

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217a9e4
ptr_FUN_overlay_0_021423a4_overlay_0_0217a9e4: ; 0x0217A9E4
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN25CFieldEffectVolcanicSteam11GetEffectIdEv
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217a9f0
ptr_FUN_overlay_0_021421d0_overlay_0_0217a9f0: ; 0x0217A9F0
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217a9f4
ptr_FUN_overlay_0_02142380_overlay_0_0217a9f4: ; 0x0217A9F4
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0216ae28_overlay_0_0217a9f8
ptr_FUN_overlay_0_0216ae28_overlay_0_0217a9f8: ; 0x0217A9F8
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216bd40_overlay_0_0217aa00
ptr_FUN_overlay_0_0216bd40_overlay_0_0217aa00: ; 0x0217AA00
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216ec14_overlay_0_0217aa04
ptr_FUN_overlay_0_0216ec14_overlay_0_0217aa04: ; 0x0217AA04
	.word _ZN25CFieldEffectVolcanicSteam12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN25CFieldEffectVolcanicSteam12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN25CFieldEffectVolcanicSteam8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP15NtfTextureParam
	.word _ZN25CFieldEffectVolcanicSteam13GetForceFieldEv
	.word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE10GetEmitterEv

    .global DAT_overlay_0_0217aa44
DAT_overlay_0_0217aa44: ; 0x0217AA44
	.byte 0x4D, 0x45, 0x46, 0x00

    .global s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217aa48
s_data_Field_Effect_ef102_LZ_bin_overlay_0_0217aa48: ; 0x0217AA48
	.asciz "data/Field/Effect/ef102_LZ.bin"

    .global DAT_overlay_0_0217AA67
DAT_overlay_0_0217AA67:
	.byte 0x00

    .global s_MEF_ef102_00_ntft_overlay_0_0217aa68
s_MEF_ef102_00_ntft_overlay_0_0217aa68: ; 0x0217AA68
	.asciz "MEF:ef102_00.ntft"

    .global DAT_overlay_0_0217AA7A
DAT_overlay_0_0217AA7A:
	.byte 0x00, 0x00

    .global s_MEF_ef102_00_ntfp_overlay_0_0217aa7c
s_MEF_ef102_00_ntfp_overlay_0_0217aa7c: ; 0x0217AA7C
	.asciz "MEF:ef102_00.ntfp"

    .global DAT_overlay_0_0217AA8E
DAT_overlay_0_0217AA8E:
	.byte 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_0_0217aa90
PTR_ptr_FUN_020835bc_overlay_0_0217aa90: ; 0x0217AA90
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N23CFieldEffectFuwanteWind8CEmit_overlay_0_0217ab54
	.word _ZTI30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_0217aa9c
PTR_ptr_FUN_020835bc_overlay_0_0217aa9c: ; 0x0217AA9C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_30CFieldEffectFuwanteWindFactory_overlay_0_0217ab30
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_0217aaa8
PTR_ptr_FUN_020835bc_overlay_0_0217aaa8: ; 0x0217AAA8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_23CFieldEffectFuwanteWind_overlay_0_0217aad4
	.word _ZTI20TFieldEffectParticleI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_0217aab4
PTR_ptr_FUN_020835bc_overlay_0_0217aab4: ; 0x0217AAB4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N23CFieldEffectFuwanteWind9CAnim_overlay_0_0217ab7c
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217aab4

    .global PTR_LAB_overlay_0_0216f644_overlay_0_0217aac8
PTR_LAB_overlay_0_0216f644_overlay_0_0217aac8: ; 0x0217AAC8
	.word _ZN23CFieldEffectFuwanteWind9CAnimatorD1Ev

    .global ptr_FUN_overlay_0_021700d0_overlay_0_0217aacc
ptr_FUN_overlay_0_021700d0_overlay_0_0217aacc: ; 0x0217AACC
	.word ov0_021700D0

    .global ptr_FUN_overlay_0_0216fc7c_overlay_0_0217aad0
ptr_FUN_overlay_0_0216fc7c_overlay_0_0217aad0: ; 0x0217AAD0
	.word _ZN23CFieldEffectFuwanteWind9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_23CFieldEffectFuwanteWind_overlay_0_0217aad4
s_23CFieldEffectFuwanteWind_overlay_0_0217aad4: ; 0x0217AAD4
	.asciz "23CFieldEffectFuwanteWind"

    .global DAT_overlay_0_0217AAEE
DAT_overlay_0_0217AAEE:
	.byte 0x00, 0x00
	.global _ZTV30CFieldEffectFuwanteWindFactory
_ZTV30CFieldEffectFuwanteWindFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217aa9c

    .global ptr_FUN_overlay_0_0216fe40_overlay_0_0217aaf8
ptr_FUN_overlay_0_0216fe40_overlay_0_0217aaf8: ; 0x0217AAF8
	.word _ZN30CFieldEffectFuwanteWindFactoryD1Ev

    .global ptr_FUN_overlay_0_0216fe68_overlay_0_0217aafc
ptr_FUN_overlay_0_0216fe68_overlay_0_0217aafc: ; 0x0217AAFC
	.word ov0_0216FE68

    .global ptr_FUN_overlay_0_0216ffd8_overlay_0_0217ab00
ptr_FUN_overlay_0_0216ffd8_overlay_0_0217ab00: ; 0x0217AB00
	.word _ZN30CFieldEffectFuwanteWindFactory6CreateEi

    .global ptr_FUN_overlay_0_02170090_overlay_0_0217ab04
ptr_FUN_overlay_0_02170090_overlay_0_0217ab04: ; 0x0217AB04
	.word _ZN30CFieldEffectFuwanteWindFactory6UpdateEi
	.word _ZN30CFieldEffectFuwanteWindFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217aa90

    .global PTR_LAB_overlay_0_0216f640_overlay_0_0217ab18
PTR_LAB_overlay_0_0216f640_overlay_0_0217ab18: ; 0x0217AB18
	.word _ZN23CFieldEffectFuwanteWind8CEmitterD1Ev

    .global ptr_FUN_overlay_0_021700bc_overlay_0_0217ab1c
ptr_FUN_overlay_0_021700bc_overlay_0_0217ab1c: ; 0x0217AB1C
	.word ov0_021700BC
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE5func2Ev
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE6UpdateEi

    .global ptr_FUN_overlay_0_0216fb58_overlay_0_0217ab28
ptr_FUN_overlay_0_0216fb58_overlay_0_0217ab28: ; 0x0217AB28
	.word _ZN23CFieldEffectFuwanteWind8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE4StopEv

    .global s_30CFieldEffectFuwanteWindFactory_overlay_0_0217ab30
s_30CFieldEffectFuwanteWindFactory_overlay_0_0217ab30: ; 0x0217AB30
	.asciz "30CFieldEffectFuwanteWindFactory"

    .global DAT_overlay_0_0217AB51
DAT_overlay_0_0217AB51:
	.byte 0x00, 0x00, 0x00

    .global s_N23CFieldEffectFuwanteWind8CEmit_overlay_0_0217ab54
s_N23CFieldEffectFuwanteWind8CEmit_overlay_0_0217ab54: ; 0x0217AB54
	.asciz "N23CFieldEffectFuwanteWind8CEmitterE"

    .global DAT_overlay_0_0217AB79
DAT_overlay_0_0217AB79:
	.byte 0x00, 0x00, 0x00

    .global s_N23CFieldEffectFuwanteWind9CAnim_overlay_0_0217ab7c
s_N23CFieldEffectFuwanteWind9CAnim_overlay_0_0217ab7c: ; 0x0217AB7C
	.asciz "N23CFieldEffectFuwanteWind9CAnimatorE"

    .global DAT_overlay_0_0217ABA2
DAT_overlay_0_0217ABA2:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_0217aaa8

    .global ptr_FUN_overlay_0_0216f648_overlay_0_0217abac
ptr_FUN_overlay_0_0216f648_overlay_0_0217abac: ; 0x0217ABAC
	.word _ZN23CFieldEffectFuwanteWindD1Ev

    .global ptr_FUN_overlay_0_0216f6f8_overlay_0_0217abb0
ptr_FUN_overlay_0_0216f6f8_overlay_0_0217abb0: ; 0x0217ABB0
	.word ov0_0216F6F8

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217abb4
ptr_FUN_overlay_0_021423a4_overlay_0_0217abb4: ; 0x0217ABB4
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN23CFieldEffectFuwanteWind11GetEffectIdEv
	.word _ZN12CFieldEffect7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217abc0
ptr_FUN_overlay_0_021421d0_overlay_0_0217abc0: ; 0x0217ABC0
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217abc4
ptr_FUN_overlay_0_02142380_overlay_0_0217abc4: ; 0x0217ABC4
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0215b4a0_overlay_0_0217abc8
ptr_FUN_overlay_0_0215b4a0_overlay_0_0217abc8: ; 0x0217ABC8
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02142ab4_overlay_0_0217abd0
ptr_FUN_overlay_0_02142ab4_overlay_0_0217abd0: ; 0x0217ABD0
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0216fae0_overlay_0_0217abd4
ptr_FUN_overlay_0_0216fae0_overlay_0_0217abd4: ; 0x0217ABD4
	.word _ZN23CFieldEffectFuwanteWind12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216f7b0_overlay_0_0217abe4
ptr_FUN_overlay_0_0216f7b0_overlay_0_0217abe4: ; 0x0217ABE4
	.word _ZN23CFieldEffectFuwanteWind8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global ptr_FUN_overlay_0_021423e8_overlay_0_0217ac08
ptr_FUN_overlay_0_021423e8_overlay_0_0217ac08: ; 0x0217AC08
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021423E8ERK20FieldEffectSpriteRes
	.word _ZN23CFieldEffectFuwanteWind13GetForceFieldEv
	.word _ZN23CFieldEffectFuwanteWind10GetEmitterEv

    .global PTR_ptr_FUN_020835bc_overlay_0_0217ac14
PTR_ptr_FUN_020835bc_overlay_0_0217ac14: ; 0x0217AC14
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectManpuDarkrie_overlay_0_0217ac20
	.word _ZTI17CFieldEffectManpu

    .global s_24CFieldEffectManpuDarkrie_overlay_0_0217ac20
s_24CFieldEffectManpuDarkrie_overlay_0_0217ac20: ; 0x0217AC20
	.asciz "24CFieldEffectManpuDarkrie"

    .global DAT_overlay_0_0217AC3B
DAT_overlay_0_0217AC3B:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217ac14

    .global ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44
ptr_FUN_overlay_0_021702d8_overlay_0_0217ac44: ; 0x0217AC44
	.word _ZN24CFieldEffectManpuDarkrieD1Ev

    .global ptr_FUN_overlay_0_02170338_overlay_0_0217ac48
ptr_FUN_overlay_0_02170338_overlay_0_0217ac48: ; 0x0217AC48
	.word ov0_02170338

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217ac4c
ptr_FUN_overlay_0_021423a4_overlay_0_0217ac4c: ; 0x0217AC4C
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectManpu11GetEffectIdEv
	.word _ZN17CFieldEffectActor7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217ac58
ptr_FUN_overlay_0_021421d0_overlay_0_0217ac58: ; 0x0217AC58
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217ac5c
ptr_FUN_overlay_0_02142380_overlay_0_0217ac5c: ; 0x0217AC5C
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_0217ac60
ptr_FUN_overlay_0_021421f0_overlay_0_0217ac60: ; 0x0217AC60
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_021703a0_overlay_0_0217ac68
ptr_FUN_overlay_0_021703a0_overlay_0_0217ac68: ; 0x0217AC68
	.word _ZN24CFieldEffectManpuDarkrie12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02143bf0_overlay_0_0217ac6c
ptr_FUN_overlay_0_02143bf0_overlay_0_0217ac6c: ; 0x0217AC6C
	.word _ZN17CFieldEffectManpu12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN17CFieldEffectManpu7SetTypeEi

    .global ptr_FUN_overlay_0_021707e4_overlay_0_0217aca4
ptr_FUN_overlay_0_021707e4_overlay_0_0217aca4: ; 0x0217ACA4
	.word _ZN24CFieldEffectManpuDarkrie4DrawEP8Camera2D
	.word _ZN24CFieldEffectManpuDarkrie8SetDepthEl

    .global PTR_ptr_FUN_020835bc_overlay_0_0217acac
PTR_ptr_FUN_020835bc_overlay_0_0217acac: ; 0x0217ACAC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_19CFieldEffectGlitter_overlay_0_0217acc4
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_0217acb8
PTR_ptr_FUN_020835bc_overlay_0_0217acb8: ; 0x0217ACB8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_26CFieldEffectGlitterFactory_overlay_0_0217acdc
	.word _ZTI19CFieldEffectFactory

    .global s_19CFieldEffectGlitter_overlay_0_0217acc4
s_19CFieldEffectGlitter_overlay_0_0217acc4: ; 0x0217ACC4
	.asciz "19CFieldEffectGlitter"

    .global DAT_overlay_0_0217ACDA
DAT_overlay_0_0217ACDA:
	.byte 0x00, 0x00

    .global s_26CFieldEffectGlitterFactory_overlay_0_0217acdc
s_26CFieldEffectGlitterFactory_overlay_0_0217acdc: ; 0x0217ACDC
	.asciz "26CFieldEffectGlitterFactory"

    .global DAT_overlay_0_0217ACF9
DAT_overlay_0_0217ACF9:
	.byte 0x00, 0x00, 0x00
	.global _ZTV26CFieldEffectGlitterFactory
_ZTV26CFieldEffectGlitterFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217acb8

    .global ptr_FUN_overlay_0_02170e44_overlay_0_0217ad04
ptr_FUN_overlay_0_02170e44_overlay_0_0217ad04: ; 0x0217AD04
	.word _ZN26CFieldEffectGlitterFactoryD1Ev

    .global ptr_FUN_overlay_0_02170e6c_overlay_0_0217ad08
ptr_FUN_overlay_0_02170e6c_overlay_0_0217ad08: ; 0x0217AD08
	.word ov0_02170E6C

    .global ptr_FUN_overlay_0_02170ea8_overlay_0_0217ad0c
ptr_FUN_overlay_0_02170ea8_overlay_0_0217ad0c: ; 0x0217AD0C
	.word _ZN26CFieldEffectGlitterFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN26CFieldEffectGlitterFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217acac

    .global ptr_FUN_overlay_0_02170954_overlay_0_0217ad24
ptr_FUN_overlay_0_02170954_overlay_0_0217ad24: ; 0x0217AD24
	.word _ZN19CFieldEffectGlitterD1Ev

    .global ptr_FUN_overlay_0_02170988_overlay_0_0217ad28
ptr_FUN_overlay_0_02170988_overlay_0_0217ad28: ; 0x0217AD28
	.word ov0_02170988

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217ad2c
ptr_FUN_overlay_0_021423a4_overlay_0_0217ad2c: ; 0x0217AD2C
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN19CFieldEffectGlitter11GetEffectIdEv
	.word _ZN19CFieldEffectGlitter7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217ad38
ptr_FUN_overlay_0_021421d0_overlay_0_0217ad38: ; 0x0217AD38
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217ad3c
ptr_FUN_overlay_0_02142380_overlay_0_0217ad3c: ; 0x0217AD3C
	.word _ZN12CFieldEffect12ov0_02142380Ev
	.word _ZN19CFieldEffectGlitter12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02170acc_overlay_0_0217ad48
ptr_FUN_overlay_0_02170acc_overlay_0_0217ad48: ; 0x0217AD48
	.word _ZN19CFieldEffectGlitter12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02170e04_overlay_0_0217ad4c
ptr_FUN_overlay_0_02170e04_overlay_0_0217ad4c: ; 0x0217AD4C
	.word _ZN19CFieldEffectGlitter12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_021709d0_overlay_0_0217ad5c
ptr_FUN_overlay_0_021709d0_overlay_0_0217ad5c: ; 0x0217AD5C
	.word _ZN19CFieldEffectGlitter8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN19CFieldEffectGlitter8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global DAT_overlay_0_0217ad80
DAT_overlay_0_0217ad80: ; 0x0217AD80
	.byte 0x4D, 0x45, 0x46, 0x00

    .global s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217ad84
s_data_Field_Effect_ef100_LZ_bin_overlay_0_0217ad84: ; 0x0217AD84
	.asciz "data/Field/Effect/ef100_LZ.bin"

    .global DAT_overlay_0_0217ADA3
DAT_overlay_0_0217ADA3:
	.byte 0x00

    .global s_MEF_ef100_02d_ntft_overlay_0_0217ada4
s_MEF_ef100_02d_ntft_overlay_0_0217ada4: ; 0x0217ADA4
	.asciz "MEF:ef100_%02d.ntft"

    .global s_MEF_ef100_02d_ntfp_overlay_0_0217adb8
s_MEF_ef100_02d_ntfp_overlay_0_0217adb8: ; 0x0217ADB8
	.asciz "MEF:ef100_%02d.ntfp"

    .global DAT_overlay_0_0217adcc
DAT_overlay_0_0217adcc: ; 0x0217ADCC
	.byte 0x00, 0x00, 0x10, 0x60

    .global DAT_overlay_0_0217add0
DAT_overlay_0_0217add0: ; 0x0217ADD0
	.byte 0x1F, 0x21, 0xFF, 0x23, 0x08, 0x7D, 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_0_0217add8
PTR_ptr_FUN_020835bc_overlay_0_0217add8: ; 0x0217ADD8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_26CFieldEffectBlackStoneAura_overlay_0_0217adf0
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_0217ade4
PTR_ptr_FUN_020835bc_overlay_0_0217ade4: ; 0x0217ADE4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_33CFieldEffectBlackStoneAuraFact_overlay_0_0217ae30
	.word _ZTI19CFieldEffectFactory

    .global s_26CFieldEffectBlackStoneAura_overlay_0_0217adf0
s_26CFieldEffectBlackStoneAura_overlay_0_0217adf0: ; 0x0217ADF0
	.asciz "26CFieldEffectBlackStoneAura"

    .global DAT_overlay_0_0217AE0D
DAT_overlay_0_0217AE0D:
	.byte 0x00, 0x00, 0x00
	.global _ZTV33CFieldEffectBlackStoneAuraFactory
_ZTV33CFieldEffectBlackStoneAuraFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217ade4

    .global ptr_FUN_overlay_0_02171730_overlay_0_0217ae18
ptr_FUN_overlay_0_02171730_overlay_0_0217ae18: ; 0x0217AE18
	.word _ZN33CFieldEffectBlackStoneAuraFactoryD1Ev

    .global ptr_FUN_overlay_0_02171758_overlay_0_0217ae1c
ptr_FUN_overlay_0_02171758_overlay_0_0217ae1c: ; 0x0217AE1C
	.word ov0_02171758

    .global ptr_FUN_overlay_0_02171788_overlay_0_0217ae20
ptr_FUN_overlay_0_02171788_overlay_0_0217ae20: ; 0x0217AE20
	.word _ZN33CFieldEffectBlackStoneAuraFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN33CFieldEffectBlackStoneAuraFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_33CFieldEffectBlackStoneAuraFact_overlay_0_0217ae30
s_33CFieldEffectBlackStoneAuraFact_overlay_0_0217ae30: ; 0x0217AE30
	.asciz "33CFieldEffectBlackStoneAuraFactory"

    .global DAT_overlay_0_0217AE54
DAT_overlay_0_0217AE54:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217add8

    .global ptr_FUN_overlay_0_02171198_overlay_0_0217ae5c
ptr_FUN_overlay_0_02171198_overlay_0_0217ae5c: ; 0x0217AE5C
	.word _ZN26CFieldEffectBlackStoneAuraD1Ev

    .global ptr_FUN_overlay_0_021711dc_overlay_0_0217ae60
ptr_FUN_overlay_0_021711dc_overlay_0_0217ae60: ; 0x0217AE60
	.word ov0_021711DC

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217ae64
ptr_FUN_overlay_0_021423a4_overlay_0_0217ae64: ; 0x0217AE64
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN26CFieldEffectBlackStoneAura11GetEffectIdEv
	.word _ZN26CFieldEffectBlackStoneAura7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217ae70
ptr_FUN_overlay_0_021421d0_overlay_0_0217ae70: ; 0x0217AE70
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217ae74
ptr_FUN_overlay_0_02142380_overlay_0_0217ae74: ; 0x0217AE74
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_02171358_overlay_0_0217ae78
ptr_FUN_overlay_0_02171358_overlay_0_0217ae78: ; 0x0217AE78
	.word _ZN26CFieldEffectBlackStoneAura12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02171378_overlay_0_0217ae80
ptr_FUN_overlay_0_02171378_overlay_0_0217ae80: ; 0x0217AE80
	.word _ZN26CFieldEffectBlackStoneAura12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02171598_overlay_0_0217ae84
ptr_FUN_overlay_0_02171598_overlay_0_0217ae84: ; 0x0217AE84
	.word _ZN26CFieldEffectBlackStoneAura12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN26CFieldEffectBlackStoneAura8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global DAT_overlay_0_0217aeb8
DAT_overlay_0_0217aeb8: ; 0x0217AEB8
	.byte 0x46, 0x45, 0x46, 0x00

    .global s_data_field_effect_ef101_LZ_bin_overlay_0_0217aebc
s_data_field_effect_ef101_LZ_bin_overlay_0_0217aebc: ; 0x0217AEBC
	.asciz "data/field/effect/ef101_LZ.bin"

    .global DAT_overlay_0_0217AEDB
DAT_overlay_0_0217AEDB:
	.byte 0x00

    .global s_FEF_ef101_00_ntfp_overlay_0_0217aedc
s_FEF_ef101_00_ntfp_overlay_0_0217aedc: ; 0x0217AEDC
	.asciz "FEF:ef101_00.ntfp"

    .global DAT_overlay_0_0217AEEE
DAT_overlay_0_0217AEEE:
	.byte 0x00, 0x00

    .global s_FEF_ef101_00_ntft_overlay_0_0217aef0
s_FEF_ef101_00_ntft_overlay_0_0217aef0: ; 0x0217AEF0
	.asciz "FEF:ef101_00.ntft"

    .global DAT_overlay_0_0217AF02
DAT_overlay_0_0217AF02:
	.byte 0x00, 0x00

    .global DAT_overlay_0_0217af04
DAT_overlay_0_0217af04: ; 0x0217AF04
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
    .word s_N24CFieldEffectSpaceCrevice17CEf_overlay_0_0217afd4
    .word _ZTI11CDrawObject

    .global PTR_ptr_FUN_020835bc_overlay_0_0217af10
PTR_ptr_FUN_020835bc_overlay_0_0217af10: ; 0x0217AF10
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_31CFieldEffectSpaceCreviceFactor_overlay_0_0217afb0
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_0217af1c
PTR_ptr_FUN_020835bc_overlay_0_0217af1c: ; 0x0217AF1C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectSpaceCrevice_overlay_0_0217af74
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_0217af28
PTR_ptr_FUN_020835bc_overlay_0_0217af28: ; 0x0217AF28
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_19CFEFRasterTransform_overlay_0_0217af5c
	.word _ZTI10CPrimitive
	.byte 0x00, 0x00, 0x00, 0x00
	.word DAT_overlay_0_0217af04

    .global PTR_LAB_overlay_0_02171b18_overlay_0_0217af3c
PTR_LAB_overlay_0_02171b18_overlay_0_0217af3c: ; 0x0217AF3C
	.word _ZN24CFieldEffectSpaceCrevice17CEffectDrawObjectD1Ev

    .global ptr_FUN_overlay_0_02172bfc_overlay_0_0217af40
ptr_FUN_overlay_0_02172bfc_overlay_0_0217af40: ; 0x0217AF40
	.word ov0_02172BFC
	.word _ZN24CFieldEffectSpaceCrevice17CEffectDrawObject4DrawEP8Camera2Di
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217af28

    .global ptr_FUN_overlay_0_02172638_overlay_0_0217af50
ptr_FUN_overlay_0_02172638_overlay_0_0217af50: ; 0x0217AF50
	.word _ZN19CFEFRasterTransformD1Ev

    .global ptr_FUN_overlay_0_02172660_overlay_0_0217af54
ptr_FUN_overlay_0_02172660_overlay_0_0217af54: ; 0x0217AF54
	.word ov0_02172660

    .global ptr_FUN_overlay_0_0217294c_overlay_0_0217af58
ptr_FUN_overlay_0_0217294c_overlay_0_0217af58: ; 0x0217AF58
	.word _ZN19CFEFRasterTransform6RenderEP8Camera2D

    .global s_19CFEFRasterTransform_overlay_0_0217af5c
s_19CFEFRasterTransform_overlay_0_0217af5c: ; 0x0217AF5C
	.asciz "19CFEFRasterTransform"

    .global DAT_overlay_0_0217AF72
DAT_overlay_0_0217AF72:
	.byte 0x00, 0x00

    .global s_24CFieldEffectSpaceCrevice_overlay_0_0217af74
s_24CFieldEffectSpaceCrevice_overlay_0_0217af74: ; 0x0217AF74
	.asciz "24CFieldEffectSpaceCrevice"

    .global DAT_overlay_0_0217AF8F
DAT_overlay_0_0217AF8F:
	.byte 0x00
	.global _ZTV31CFieldEffectSpaceCreviceFactory
_ZTV31CFieldEffectSpaceCreviceFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217af10

    .global ptr_FUN_overlay_0_0217230c_overlay_0_0217af98
ptr_FUN_overlay_0_0217230c_overlay_0_0217af98: ; 0x0217AF98
	.word _ZN31CFieldEffectSpaceCreviceFactoryD1Ev

    .global ptr_FUN_overlay_0_02172344_overlay_0_0217af9c
ptr_FUN_overlay_0_02172344_overlay_0_0217af9c: ; 0x0217AF9C
	.word ov0_02172344

    .global ptr_FUN_overlay_0_02172384_overlay_0_0217afa0
ptr_FUN_overlay_0_02172384_overlay_0_0217afa0: ; 0x0217AFA0
	.word _ZN31CFieldEffectSpaceCreviceFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN31CFieldEffectSpaceCreviceFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_31CFieldEffectSpaceCreviceFactor_overlay_0_0217afb0
s_31CFieldEffectSpaceCreviceFactor_overlay_0_0217afb0: ; 0x0217AFB0
	.asciz "31CFieldEffectSpaceCreviceFactory"

    .global DAT_overlay_0_0217AFD2
DAT_overlay_0_0217AFD2:
	.byte 0x00, 0x00

    .global s_N24CFieldEffectSpaceCrevice17CEf_overlay_0_0217afd4
s_N24CFieldEffectSpaceCrevice17CEf_overlay_0_0217afd4: ; 0x0217AFD4
	.asciz "N24CFieldEffectSpaceCrevice17CEffectDrawObjectE"

    .global DAT_overlay_0_0217B004
DAT_overlay_0_0217B004:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217af1c

    .global ptr_FUN_overlay_0_02171b1c_overlay_0_0217b00c
ptr_FUN_overlay_0_02171b1c_overlay_0_0217b00c: ; 0x0217B00C
	.word _ZN24CFieldEffectSpaceCreviceD1Ev

    .global ptr_FUN_overlay_0_02171b60_overlay_0_0217b010
ptr_FUN_overlay_0_02171b60_overlay_0_0217b010: ; 0x0217B010
	.word ov0_02171B60

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217b014
ptr_FUN_overlay_0_021423a4_overlay_0_0217b014: ; 0x0217B014
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN24CFieldEffectSpaceCrevice11GetEffectIdEv

    .global ptr_FUN_overlay_0_02172b94_overlay_0_0217b01c
ptr_FUN_overlay_0_02172b94_overlay_0_0217b01c: ; 0x0217B01C
	.word _ZN24CFieldEffectSpaceCrevice7IsReadyEv

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217b020
ptr_FUN_overlay_0_021421d0_overlay_0_0217b020: ; 0x0217B020
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217b024
ptr_FUN_overlay_0_02142380_overlay_0_0217b024: ; 0x0217B024
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_0217b028
ptr_FUN_overlay_0_021421f0_overlay_0_0217b028: ; 0x0217B028
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02171cfc_overlay_0_0217b030
ptr_FUN_overlay_0_02171cfc_overlay_0_0217b030: ; 0x0217B030
	.word _ZN24CFieldEffectSpaceCrevice12ov0_02142264Ei
	.word _ZN24CFieldEffectSpaceCrevice12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN24CFieldEffectSpaceCrevice12ov0_02142398EP14DrawObjectList
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN24CFieldEffectSpaceCrevice8SetParamEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN24CFieldEffectSpaceCrevice8SetColorEt
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN24CFieldEffectSpaceCrevice6FadeToEii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global s_MEF_overlay_0_0217b068
s_MEF_overlay_0_0217b068: ; 0x0217B068
	.asciz "MEF"

    .global s_data_Field_Effect_ef104_LZ_bin_overlay_0_0217b06c
s_data_Field_Effect_ef104_LZ_bin_overlay_0_0217b06c: ; 0x0217B06C
	.asciz "data/Field/Effect/ef104_LZ.bin"

    .global DAT_overlay_0_0217B08B
DAT_overlay_0_0217B08B:
	.byte 0x00

    .global s_MEF_ef104_02d_ntft_overlay_0_0217b08c
s_MEF_ef104_02d_ntft_overlay_0_0217b08c: ; 0x0217B08C
	.asciz "MEF:ef104_%02d.ntft"

    .global s_MEF_ef104_02d_ntfp_overlay_0_0217b0a0
s_MEF_ef104_02d_ntfp_overlay_0_0217b0a0: ; 0x0217B0A0
	.asciz "MEF:ef104_%02d.ntfp"
	; 0x0217B0B4

    .bss
