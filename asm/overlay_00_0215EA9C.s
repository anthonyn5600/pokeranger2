    .include "macros.inc"
    .include "include/overlay_00_0215EA9C.inc"

    .text

	arm_func_start ov0_0215EA9C
ov0_0215EA9C: ; 0x0215EA9C
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _0215EB14 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _0215EB18 ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [r4]
	ldr r0, _0215EB1C ; =ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38
	str r1, [r4, #0x18]
	ldr ip, _0215EB20 ; =_ZN15CSoftwareSpriteD1Ev
	str r0, [r4]
	ldr r3, _0215EB24 ; =FUN_02005150
	add r0, r4, #0x94
	mov r1, #4
	mov r2, #0x4c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r1, #0
	str r1, [r4, #0x1c4]
	add r0, r4, #0x100
	strh r1, [r0, #0xc8]
	str r1, [r4, #0x1cc]
	mov r0, r4
	strb r1, [r4, #0x1d0]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0215EB14: .word _ZTV12CFieldEffect+8
_0215EB18: .word _ZTV17CFieldEffectActor+8
_0215EB1C: .word ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38
_0215EB20: .word _ZN15CSoftwareSpriteD1Ev
_0215EB24: .word _ZN15CSoftwareSpriteC1Ev
	arm_func_end ov0_0215EA9C

	arm_func_start _ZN21CFieldEffectPoisonGasD1Ev
_ZN21CFieldEffectPoisonGasD1Ev: ; 0x0215EB28
	stmdb sp!, {r4, lr}
	ldr r1, _0215EB9C ; =ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0215EB68
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0215EB68
	add r1, r4, #0x100
	ldrh r1, [r1, #0xc8]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end _ZN21CFieldEffectPoisonGasD1Ev
_0215EB68:
	ldr r3, _0215EBA0 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x94
	mov r1, #4
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _0215EBA4 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215EB9C: .word ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38
_0215EBA0: .word _ZN15CSoftwareSpriteD1Ev
_0215EBA4: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0215EBA8
ov0_0215EBA8: ; 0x0215EBA8
	stmdb sp!, {r4, lr}
	ldr r1, _0215EC24 ; =ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0215EBE8
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0215EBE8
	add r1, r4, #0x100
	ldrh r1, [r1, #0xc8]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end ov0_0215EBA8
_0215EBE8:
	ldr r3, _0215EC28 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x94
	mov r1, #4
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _0215EC2C ; =_ZTV12CFieldEffect+8
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
_0215EC24: .word ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38
_0215EC28: .word _ZN15CSoftwareSpriteD1Ev
_0215EC2C: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0215EC30
ov0_0215EC30: ; 0x0215EC30
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r2, [r4, #0x1c4]
	mov r3, #0
	str r3, [r4, #0x1cc]
	mov r0, r1
	str r1, [r4, #0x18]
	ldr r2, [r0]
	mov r1, r3
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0215EC78
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, #0x100
	strh r0, [r1, #0xc8]
	arm_func_end ov0_0215EC30
_0215EC78:
	mov r0, r4
	bl ov0_0215EFB4
	add r0, r4, #0x24
	mov r1, #0
	mov r2, #0x70
	bl MI_CpuFill8
	ldmia sp!, {r4, pc}

	arm_func_start _ZN21CFieldEffectPoisonGas12ov0_02142264Ei
_ZN21CFieldEffectPoisonGas12ov0_02142264Ei: ; 0x0215EC94
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xc
	mov sl, r0
	mov sb, r1
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	cmp r0, #0
	str r0, [sp, #8]
	cmpne r0, #4
	beq _0215EDC0
	mov r4, #0
	mov r5, r4
	mov r6, sl
	add r7, sl, #0x24
	mov fp, r4
	arm_func_end _ZN21CFieldEffectPoisonGas12ov0_02142264Ei
_0215ECCC:
	ldrsh r0, [r6, #0x3c]
	cmp r0, #0
	ble _0215ED90
	ldr r1, [r6, #0x24]
	ldr r0, [r6, #0x2c]
	mla r0, sb, r0, r1
	str r0, [r6, #0x24]
	ldr r1, [r6, #0x28]
	ldr r0, [r6, #0x30]
	mla r0, sb, r0, r1
	str r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	ldr r0, [r6, #0x34]
	mla r0, sb, r0, r1
	str r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	ldr r0, [r6, #0x38]
	mla r0, sb, r0, r1
	str r0, [r6, #0x30]
	ldrsh r0, [r6, #0x3c]
	sub r0, r0, sb
	strh r0, [r6, #0x3c]
	ldrsh r0, [r6, #0x3c]
	cmp r0, #0x1e
	strltb r0, [r6, #0x3e]
	blt _0215ED8C
	ldr r0, _0215EDCC ; =MAIN_BSS_0210CA60
	ldr r8, [r0]
	ldrb r0, [r8, #0x87c]
	cmp r0, #0
	bne _0215ED8C
	mov r0, sl
	mov r1, r7
	bl ov0_0215F044
	cmp r0, #0
	beq _0215ED8C
	ldr r0, [r6, #0x28]
	mov r2, #0
	mov r0, r0, asr #0xc
	str r0, [sp]
	ldr r1, [sl, #0x1cc]
	add r0, r8, #0x7b0
	str r1, [sp, #4]
	ldr r3, [r6, #0x24]
	ldr r1, [sl, #0x1c4]
	mov r3, r3, asr #0xc
	bl ov0_02163A08
	strh fp, [r6, #0x3c]
_0215ED8C:
	add r4, r4, #1
_0215ED90:
	add r5, r5, #1
	cmp r5, #4
	add r6, r6, #0x1c
	add r7, r7, #0x1c
	blt _0215ECCC
	cmp r4, #0
	bne _0215EDC0
	mov r0, sl
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x20]
	blx r2
_0215EDC0:
	ldr r0, [sp, #8]
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0215EDCC: .word MAIN_BSS_0210CA60

	arm_func_start _ZN21CFieldEffectPoisonGas12ov0_02142344EP8Camera2D
_ZN21CFieldEffectPoisonGas12ov0_02142344EP8Camera2D: ; 0x0215EDD0
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #8
	mov sb, r0
	ldr r0, [sb, #0x14]
	mov r8, r1
	cmp r0, #0
	cmpne r0, #4
	beq _0215EE88
	ldr r0, [sb, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	mov r7, #0
	beq _0215EE20
	add r1, sb, #0x100
	ldrh r1, [r1, #0xc8]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	mov r7, r0
	arm_func_end _ZN21CFieldEffectPoisonGas12ov0_02142344EP8Camera2D
_0215EE20:
	mov r5, sb
	add r6, sb, #0x94
	mov r4, #0
_0215EE2C:
	ldrsh r0, [sb, #0x3c]
	cmp r0, #0
	ble _0215EE70
	strh r7, [r5, #0xbe]
	ldr ip, [sb, #0x24]
	ldr r3, [sb, #0x28]
	mov r0, r6
	str ip, [r5, #0xac]
	str r3, [r5, #0xb0]
	ldrb r2, [sb, #0x3e]
	mov r1, r8
	str ip, [sp]
	str r2, [r5, #0xa8]
	ldr r2, [r0]
	str r3, [sp, #4]
	ldr r2, [r2, #8]
	blx r2
_0215EE70:
	add r4, r4, #1
	cmp r4, #4
	add sb, sb, #0x1c
	add r5, r5, #0x4c
	add r6, r6, #0x4c
	blt _0215EE2C
_0215EE88:
	mov r0, #1
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN21CFieldEffectPoisonGas12sub_0203312CEii
_ZN21CFieldEffectPoisonGas12sub_0203312CEii: ; 0x0215EE94
	cmp r1, #1
	mov r3, #1
	beq _0215EEB4
	cmp r1, #2
	beq _0215EEE0
	cmp r1, #0x12
	beq _0215EF0C
	b _0215EF14
	arm_func_end _ZN21CFieldEffectPoisonGas12sub_0203312CEii
_0215EEB4:
	mov r1, r2, lsl #0xc
	mov ip, r0
	str r1, [r0, #0x1c]
	mov r2, #0
_0215EEC4:
	ldr r1, [r0, #0x1c]
	add r2, r2, #1
	str r1, [ip, #0x24]
	cmp r2, #4
	add ip, ip, #0x1c
	blt _0215EEC4
	b _0215EF18
_0215EEE0:
	mov r1, r2, lsl #0xc
	mov ip, r0
	str r1, [r0, #0x20]
	mov r2, #0
_0215EEF0:
	ldr r1, [r0, #0x20]
	add r2, r2, #1
	str r1, [ip, #0x28]
	cmp r2, #4
	add ip, ip, #0x1c
	blt _0215EEF0
	b _0215EF18
_0215EF0C:
	str r2, [r0, #0x1cc]
	b _0215EF18
_0215EF14:
	mov r3, #0
_0215EF18:
	mov r0, r3
	bx lr

	arm_func_start _ZN21CFieldEffectPoisonGas12ov0_021421F0Eiii
_ZN21CFieldEffectPoisonGas12ov0_021421F0Eiii: ; 0x0215EF20
	stmdb sp!, {r3, lr}
	mov ip, r0
	mov r3, #0
	mov r2, #0x5a
	mov r1, #0x1f
	arm_func_end _ZN21CFieldEffectPoisonGas12ov0_021421F0Eiii
_0215EF34:
	strh r2, [ip, #0x3c]
	add r3, r3, #1
	strb r1, [ip, #0x3e]
	cmp r3, #4
	add ip, ip, #0x1c
	blt _0215EF34
	ldr r3, _0215EFB0 ; =0x00000E66
	mov r1, #0
	str r3, [r0, #0x2c]
	str r3, [r0, #0x30]
	rsb r2, r3, #0
	str r2, [r0, #0x48]
	str r3, [r0, #0x4c]
	str r3, [r0, #0x64]
	str r2, [r0, #0x68]
	str r2, [r0, #0x80]
	str r2, [r0, #0x84]
	mvn r2, #0x20
	str r2, [r0, #0x34]
	str r2, [r0, #0x38]
	mov ip, #0x21
	str ip, [r0, #0x50]
	str r2, [r0, #0x54]
	str r2, [r0, #0x6c]
	str ip, [r0, #0x70]
	str ip, [r0, #0x88]
	mov r3, r1
	sub r2, r1, #1
	str ip, [r0, #0x8c]
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, pc}
	.align 2, 0
_0215EFB0: .word 0x00000E66

	arm_func_start ov0_0215EFB4
ov0_0215EFB4: ; 0x0215EFB4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r8, #0
	mov sl, r0
	mov sb, sl
	mov fp, r8
	mov r5, r8
	mvn r4, #0
	arm_func_end ov0_0215EFB4
_0215EFD0:
	ldr r0, [sl, #0x18]
	mov r1, fp
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	mov r7, r0
	ldr r0, [sl, #0x18]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r6, r0
	ldr r0, [sl, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	str r0, [sb, #0xc0]
	str r5, [sb, #0xc4]
	str r6, [sb, #0xc8]
	str r7, [sb, #0xcc]
	add r0, r8, #8
	strh r5, [sb, #0xbe]
	str r0, [sb, #0xa4]
	add r8, r8, #1
	str r4, [sb, #0x98]
	add sb, sb, #0x4c
	cmp r8, #4
	blt _0215EFD0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov0_0215F044
ov0_0215F044: ; 0x0215F044
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x30
	ldr r0, _0215F114 ; =MAIN_BSS_0210CA40
	mov r5, r1
	ldr r0, [r0]
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r1, [r0, #0xe0]
	ldr r0, [r0, #8]
	add r4, r1, #0xb000
	cmp r0, #0
	beq _0215F0B4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0215F094
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	b _0215F0AC
	arm_func_end ov0_0215F044
_0215F094:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_0215F0AC:
	add ip, sp, #0x20
	b _0215F0D0
_0215F0B4:
	mov r0, #0
	add r1, sp, #0
	add ip, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_0215F0D0:
	ldr r3, [r5]
	ldr r2, [r5, #4]
	ldmia ip, {r0, r1}
	sub r0, r0, r3
	sub r1, r1, r2
	str r3, [sp, #0x18]
	str r2, [sp, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	bl _Z12sub_02007254ll
	cmp r0, r4
	movlt r0, #1
	movge r0, #0
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0215F114: .word MAIN_BSS_0210CA40

	arm_func_start _ZN21CFieldEffectPoisonGas12ov0_02142390EPvS0_
_ZN21CFieldEffectPoisonGas12ov0_02142390EPvS0_: ; 0x0215F118
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x20
	mov r4, #0
	mov r7, r0
	mov r5, r2
	mov r6, r1
	add r0, sp, #0
	mov r1, r4
	mov r2, #0x20
	bl MI_CpuFill8
	mov r1, #0xc
	sub r0, r1, #0xd
	strb r1, [sp]
	str r0, [sp, #0x1c]
	ldr r0, [r7, #0x1cc]
	add r2, sp, #0
	strb r0, [sp, #2]
	mov r1, r4
	mov lr, r2
	mov r0, #1
	arm_func_end _ZN21CFieldEffectPoisonGas12ov0_02142390EPvS0_
_0215F168:
	ldrsh r3, [r7, #0x3c]
	cmp r3, #0
	ble _0215F1A4
	ldr r3, [r7, #0x24]
	orr r4, r4, r0, lsl r1
	mov r3, r3, asr #0xc
	add ip, lr, r1, lsl #2
	strh r3, [ip, #8]
	ldr r3, [r7, #0x28]
	and r4, r4, #0xff
	mov r3, r3, asr #0xc
	strh r3, [ip, #0xa]
	ldrsh r3, [r7, #0x3c]
	rsb r3, r3, #0x5a
	strb r3, [r2, #3]
_0215F1A4:
	add r1, r1, #1
	cmp r1, #4
	add r7, r7, #0x1c
	add r2, r2, #1
	blt _0215F168
	add r0, r6, #0x20
	cmp r0, r5
	strb r4, [sp, #1]
	addhi sp, sp, #0x20
	movhi r0, #0
	ldmhiia sp!, {r3, r4, r5, r6, r7, pc}
	add r0, sp, #0
	mov r1, r6
	mov r2, #0x20
	bl MI_CpuCopy8
	mov r0, #0x20
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN21CFieldEffectPoisonGas12ov0_02142388EPKv
_ZN21CFieldEffectPoisonGas12ov0_02142388EPKv: ; 0x0215F1EC
	stmdb sp!, {r4, r5, r6, lr}
	mov r3, #0
	mov ip, r3
	mov lr, r0
	mov r4, #0x1f
	mov r2, #1
	arm_func_end _ZN21CFieldEffectPoisonGas12ov0_02142388EPKv
_0215F204:
	ldrb r5, [r1, #2]
	str r5, [r0, #0x1cc]
	ldrb r5, [r1, #1]
	tst r5, r2, lsl ip
	beq _0215F258
	add r5, r1, ip
	ldrb r5, [r5, #3]
	add r6, r1, ip, lsl #2
	add r3, r3, #1
	rsb r5, r5, #0x5a
	strh r5, [lr, #0x3c]
	ldrsh r5, [r6, #8]
	mov r5, r5, lsl #0xc
	str r5, [lr, #0x24]
	ldrsh r5, [r6, #0xa]
	mov r5, r5, lsl #0xc
	str r5, [lr, #0x28]
	ldrsh r5, [lr, #0x3c]
	cmp r5, #0x1e
	strltb r5, [lr, #0x3e]
	strgeb r4, [lr, #0x3e]
_0215F258:
	add ip, ip, #1
	cmp ip, #5
	add lr, lr, #0x1c
	blt _0215F204
	cmp r3, #0
	movle r0, #0
	ldmleia sp!, {r4, r5, r6, pc}
	ldr lr, _0215F2DC ; =0x00000E66
	mvn r3, #0x20
	str lr, [r0, #0x2c]
	str lr, [r0, #0x30]
	str r3, [r0, #0x34]
	str r3, [r0, #0x38]
	rsb r2, lr, #0
	str r2, [r0, #0x48]
	str lr, [r0, #0x4c]
	mov ip, #0x21
	str ip, [r0, #0x50]
	str r3, [r0, #0x54]
	str lr, [r0, #0x64]
	str r2, [r0, #0x68]
	str r3, [r0, #0x6c]
	str ip, [r0, #0x70]
	str r2, [r0, #0x80]
	mov r1, #0
	str r2, [r0, #0x84]
	str ip, [r0, #0x88]
	mov r3, r1
	sub r2, r1, #1
	str ip, [r0, #0x8c]
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	mov r0, #1
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0215F2DC: .word 0x00000E66

	arm_func_start _ZN28CFieldEffectPoisonGasFactoryC1EP18CFieldEffectManage
_ZN28CFieldEffectPoisonGasFactoryC1EP18CFieldEffectManage: ; 0x0215F2E0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r3, _0215F340 ; =ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18
	mov r5, r0
	ldr r2, _0215F344 ; =_ZTV16CEffectActorData+8
	str r3, [r5]
	add r0, r5, #8
	mov r4, r1
	str r2, [r5, #4]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r1, #0
	str r1, [r5, #0x30]
	ldr r0, _0215F348 ; =_ZTV27CFieldEffectAttackActorData+8
	str r1, [r5, #0x34]
	str r0, [r5, #4]
	sub r0, r1, #1
	str r0, [r5, #0x38]
	str r1, [r5, #0x3c]
	cmp r4, #0
	beq _0215F338
	add r0, r4, #0x7b0
	bl ov0_02163904
	str r0, [r5, #0x38]
	arm_func_end _ZN28CFieldEffectPoisonGasFactoryC1EP18CFieldEffectManage
_0215F338:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0215F340: .word ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18
_0215F344: .word _ZTV16CEffectActorData+8
_0215F348: .word _ZTV27CFieldEffectAttackActorData+8

	arm_func_start _ZN28CFieldEffectPoisonGasFactoryD1Ev
_ZN28CFieldEffectPoisonGasFactoryD1Ev: ; 0x0215F34C
	stmdb sp!, {r4, lr}
	ldr r1, _0215F370 ; =ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18
	mov r4, r0
	str r1, [r4]
	bl ov0_0215F4C8
	add r0, r4, #4
	bl _ZN16CEffectActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215F370: .word ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18
	arm_func_end _ZN28CFieldEffectPoisonGasFactoryD1Ev

	arm_func_start ov0_0215F374
ov0_0215F374: ; 0x0215F374
	stmdb sp!, {r4, lr}
	ldr r1, _0215F3A0 ; =ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18
	mov r4, r0
	str r1, [r4]
	bl ov0_0215F4C8
	add r0, r4, #4
	bl _ZN16CEffectActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215F3A0: .word ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18
	arm_func_end ov0_0215F374

	arm_func_start _ZN28CFieldEffectPoisonGasFactory6CreateEi
_ZN28CFieldEffectPoisonGasFactory6CreateEi: ; 0x0215F3A4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #4
	ldr r1, [r0]
	mov r4, #0
	ldr r1, [r1, #0x20]
	blx r1
	cmp r0, #0
	ldrne r3, [r5, #0x3c]
	cmpne r3, #0
	beq _0215F408
	mov r2, r3
	mov r1, r4
	arm_func_end _ZN28CFieldEffectPoisonGasFactory6CreateEi
_0215F3D8:
	ldrb r0, [r2, #0x1d0]
	cmp r0, #0
	bne _0215F3F8
	mov r0, #0x1d4
	mla r4, r1, r0, r3
	mov r0, #1
	strb r0, [r4, #0x1d0]
	b _0215F408
_0215F3F8:
	add r1, r1, #1
	cmp r1, #3
	add r2, r2, #0x1d4
	blt _0215F3D8
_0215F408:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov0_0215F410
ov0_0215F410: ; 0x0215F410
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r2, #1
	mov r3, r2
	add r0, r6, #4
	mov r1, #0x13
	bl _ZN27CFieldEffectAttackActorData12ov0_0214FFF0Eiii
	cmp r0, #0
	beq _0215F4B4
	ldr r0, [r6, #0x3c]
	cmp r0, #0
	beq _0215F45C
	ldr r3, _0215F4C0 ; =_ZN21CFieldEffectPoisonGasD1Ev
	mov r1, #0x1d4
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r6, #0x3c]
	arm_func_end ov0_0215F410
_0215F45C:
	ldr ip, _0215F4C0 ; =_ZN21CFieldEffectPoisonGasD1Ev
	ldr r3, _0215F4C4 ; =ov0_0215EA9C
	mov r0, #3
	mov r1, #0x1d4
	mov r2, #8
	str ip, [sp]
	bl __cxa_vec_new
	mov r4, #0
	mov r5, r4
	str r0, [r6, #0x3c]
_0215F484:
	ldr r0, [r6, #0x3c]
	ldr r2, [r6, #0x38]
	add r0, r0, r5
	add r1, r6, #4
	bl ov0_0215EC30
	add r4, r4, #1
	cmp r4, #3
	add r5, r5, #0x1d4
	blt _0215F484
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215F4B4:
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0215F4C0: .word _ZN21CFieldEffectPoisonGasD1Ev
_0215F4C4: .word ov0_0215EA9C

	arm_func_start ov0_0215F4C8
ov0_0215F4C8: ; 0x0215F4C8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq _0215F4F4
	ldr r3, _0215F500 ; =_ZN21CFieldEffectPoisonGasD1Ev
	mov r1, #0x1d4
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x3c]
	arm_func_end ov0_0215F4C8
_0215F4F4:
	add r0, r4, #4
	bl _ZN16CEffectActorData7ReleaseEv
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215F500: .word _ZN21CFieldEffectPoisonGasD1Ev

	arm_func_start _ZN28CFieldEffectPoisonGasFactory6UpdateEi
_ZN28CFieldEffectPoisonGasFactory6UpdateEi: ; 0x0215F504
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #4]!
	ldr r1, [r1, #0x18]
	blx r1
	ldmia sp!, {r3, pc}
	arm_func_end _ZN28CFieldEffectPoisonGasFactory6UpdateEi

	arm_func_start _ZN28CFieldEffectPoisonGasFactory5ResetEv
_ZN28CFieldEffectPoisonGasFactory5ResetEv: ; 0x0215F518
	ldr ip, _0215F520 ; =ov0_0215F4C8
	bx ip
	.align 2, 0
_0215F520: .word ov0_0215F4C8
	arm_func_end _ZN28CFieldEffectPoisonGasFactory5ResetEv

	arm_func_start _ZN21CFieldEffectPoisonGas12ov0_021423A4Ev
_ZN21CFieldEffectPoisonGas12ov0_021423A4Ev: ; 0x0215F524
	mov r1, #0
	strb r1, [r0, #0x1d0]
	bx lr
	arm_func_end _ZN21CFieldEffectPoisonGas12ov0_021423A4Ev

	arm_func_start _ZN21CFieldEffectPoisonGas12sub_02033028Ev
_ZN21CFieldEffectPoisonGas12sub_02033028Ev: ; 0x0215F530
	mov r0, #0xc
	bx lr
	arm_func_end _ZN21CFieldEffectPoisonGas12sub_02033028Ev

	arm_func_start ov0_0215F538
ov0_0215F538: ; 0x0215F538
	stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
	sub sp, sp, #4
	ldr r2, _0215F828 ; =_ZTV12CFieldEffect+8
	mov r6, r0
	str r2, [r6]
	ldr r2, [r0]
	mov r5, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _0215F82C ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [r6]
	ldr r0, _0215F830 ; =ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8
	str r1, [r6, #0x18]
	str r0, [r6]
	str r5, [r6, #0x1c]
	mov r0, #0x1000
	str r0, [r6, #0x2c]
	mov r0, #1
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	str r1, [r6, #0x40]
	str r1, [r6, #0x44]
	str r1, [r6, #0x48]
	mov r0, #0x20
	str r0, [r6, #0x50]
	str r1, [r6, #0x54]
	ldr r0, [r6, #0x50]
	cmp r0, #0
	beq _0215F644
	ldr r1, _0215F834 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _0215F838 ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r6, #0x4c]
	ldr r1, [r6, #0x50]
	mov r8, #0
	mov r0, r8
	cmp r1, #0
	bls _0215F638
	mov r1, r8
	mov r7, r8
	mov r2, #0x74
	arm_func_end ov0_0215F538
_0215F5EC:
	ldr r3, [r6, #0x4c]
	add r4, r0, #1
	add r3, r3, r1
	str r8, [r3, #0x6c]
	ldr r3, [r6, #0x50]
	add r0, r0, #1
	cmp r4, r3
	ldrlo r3, [r6, #0x4c]
	mlalo r8, r4, r2, r3
	ldr r3, [r6, #0x4c]
	movhs r8, r7
	add r3, r3, r1
	str r8, [r3, #0x70]
	ldr r4, [r6, #0x4c]
	ldr r3, [r6, #0x50]
	add r8, r4, r1
	cmp r0, r3
	add r1, r1, #0x74
	blo _0215F5EC
_0215F638:
	ldr r0, [r6, #0x4c]
	str r0, [r6, #0x58]
	b _0215F64C
_0215F644:
	str r1, [r6, #0x4c]
	str r1, [r6, #0x58]
_0215F64C:
	mov r1, #0
	str r1, [r6, #0x5c]
	ldr r0, [r6, #0x38]
	cmp r0, #0
	streq r1, [r6, #0x30]
	streq r1, [r6, #0x34]
	beq _0215F694
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r6, #0x30]
	ldr r1, [r6, #0x38]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r6, #0x38]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r6, #0x34]
_0215F694:
	mov r2, #0
	str r2, [r6, #0x28]
	ldr r0, _0215F83C ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r2, [r6, #0x24]
	str r0, [r6, #0x60]
	str r2, [r6, #0x74]
	str r2, [r6, #0x64]
	str r2, [r6, #0x68]
	str r2, [r6, #0x6c]
	mov r1, #0x1000
	ldr r0, _0215F840 ; =PTR_LAB_overlay_0_0215f854_overlay_0_02178d10
	str r1, [r6, #0x70]
	str r0, [r6, #0x60]
	str r2, [r6, #0x80]
	str r2, [r6, #0x84]
	str r1, [r6, #0x88]
	str r2, [r6, #0x8c]
	str r2, [r6, #0x90]
	mov r0, #0x3c000
	str r0, [r6, #0x94]
	strh r2, [r6, #0x98]
	ldr r0, _0215F844 ; =PTR_LAB_overlay_0_0215f858_overlay_0_02178ce0
	strh r2, [r6, #0x9a]
	str r0, [r6, #0xac]
	strh r2, [r6, #0xb0]
	str r1, [r6, #0xb4]
	mov r0, #0x34
	str r1, [r6, #0xb8]
	bl _Znwm
	movs r4, r0
	beq _0215F734
	ldr r1, _0215F848 ; =_ZTV16CEffectActorData+8
	add r0, r4, #4
	str r1, [r4]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r1, #0
	str r1, [r4, #0x2c]
	ldr r0, _0215F84C ; =_ZTV27CFieldEffectAttackActorData+8
	str r1, [r4, #0x30]
	str r0, [r4]
_0215F734:
	cmp r4, #0
	beq _0215F750
	mov r2, #1
	mov r0, r4
	mov r1, r5
	mov r3, r2
	bl _ZN27CFieldEffectAttackActorData12ov0_0214FFF0Eiii
_0215F750:
	mov r0, r4
	str r4, [r6, #0x18]
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0215F784
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	strh r0, [r6, #0x20]
	b _0215F78C
_0215F784:
	ldr r0, _0215F850 ; =s_effect_anime_data_is_null_overlay_0_02178e04
	bl LogError
_0215F78C:
	ldr r0, [r6, #0x38]
	cmp r0, #0
	bls _0215F7A8
	ldr r1, [r6, #0x30]
	cmp r1, #0
	addne r0, r6, #0x60
	strne r0, [r1]
_0215F7A8:
	add r0, r6, #0xac
	str r0, [r6, #0x48]
	cmp r4, #0
	beq _0215F804
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r8, r0
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r7, r0
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	str r0, [r6, #0x3c]
	str r7, [r6, #0x40]
	str r8, [r6, #0x44]
_0215F804:
	cmp r5, #0x5b
	bne _0215F81C
	mov r0, #0x800
	str r0, [r6, #0xb4]
	mov r0, #0x2000
	str r0, [r6, #0xb8]
_0215F81C:
	mov r0, r6
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0215F828: .word _ZTV12CFieldEffect+8
_0215F82C: .word _ZTV17CFieldEffectActor+8
_0215F830: .word ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8
_0215F834: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0215F838: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
_0215F83C: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_0215F840: .word PTR_LAB_overlay_0_0215f854_overlay_0_02178d10
_0215F844: .word PTR_LAB_overlay_0_0215f858_overlay_0_02178ce0
_0215F848: .word _ZTV16CEffectActorData+8
_0215F84C: .word _ZTV27CFieldEffectAttackActorData+8
_0215F850: .word s_effect_anime_data_is_null_overlay_0_02178e04

	arm_func_start _ZN17CFieldEffectSpray20CWaveParticleEmitterD1Ev
_ZN17CFieldEffectSpray20CWaveParticleEmitterD1Ev: ; 0x0215F854
	bx lr
	arm_func_end _ZN17CFieldEffectSpray20CWaveParticleEmitterD1Ev

	arm_func_start _ZN17CFieldEffectSpray21CWaveParticleAnimatorD1Ev
_ZN17CFieldEffectSpray21CWaveParticleAnimatorD1Ev: ; 0x0215F858
	bx lr
	arm_func_end _ZN17CFieldEffectSpray21CWaveParticleAnimatorD1Ev

	arm_func_start _ZN17CFieldEffectSprayD1Ev
_ZN17CFieldEffectSprayD1Ev: ; 0x0215F85C
	stmdb sp!, {r4, lr}
	ldr r1, _0215F930 ; =ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0215F898
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0215F898
	ldrh r1, [r4, #0x20]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end _ZN17CFieldEffectSprayD1Ev
_0215F898:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0215F8BC
	beq _0215F8B4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0215F8B4:
	mov r0, #0
	str r0, [r4, #0x18]
_0215F8BC:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _0215F8D4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x34]
_0215F8D4:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _0215F8EC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x30]
_0215F8EC:
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq _0215F910
	ldr r3, _0215F934 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x4c]
_0215F910:
	ldr r1, _0215F938 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215F930: .word ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8
_0215F934: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0215F938: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0215F93C
ov0_0215F93C: ; 0x0215F93C
	stmdb sp!, {r4, lr}
	ldr r1, _0215FA18 ; =ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0215F978
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0215F978
	ldrh r1, [r4, #0x20]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end ov0_0215F93C
_0215F978:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0215F99C
	beq _0215F994
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0215F994:
	mov r0, #0
	str r0, [r4, #0x18]
_0215F99C:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _0215F9B4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x34]
_0215F9B4:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _0215F9CC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x30]
_0215F9CC:
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq _0215F9F0
	ldr r3, _0215FA1C ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x4c]
_0215F9F0:
	ldr r1, _0215FA20 ; =_ZTV12CFieldEffect+8
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
_0215FA18: .word ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8
_0215FA1C: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0215FA20: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN17CFieldEffectSpray12ov0_02142264Ei
_ZN17CFieldEffectSpray12ov0_02142264Ei: ; 0x0215FA24
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov sl, r0
	mov r5, r1
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	cmp r0, #4
	str r0, [sp]
	cmpne r0, #0
	beq _0215FD28
	ldr r0, [sl, #0x18]
	cmp r0, #0
	beq _0215FA60
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	arm_func_end _ZN17CFieldEffectSpray12ov0_02142264Ei
_0215FA60:
	ldr r0, [sl, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0215FA88
	ldrh r1, [sl, #0x20]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [sl, #0xb0]
_0215FA88:
	ldr r0, [sl, #0x2c]
	ldr r4, [sl, #0x54]
	mul sb, r5, r0
	cmp r4, #0
	beq _0215FBBC
	mov r6, sb, asr #0x1f
	mov r7, #0
_0215FAA4:
	ldr r0, [r4, #0x60]
	ldr r5, [r4, #0x70]
	cmp r0, #0
	beq _0215FB68
	ldr r0, [sl, #0x48]
	cmp r0, #0
	beq _0215FAD4
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_0215FAD4:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _0215FBB0
	ldr r1, [r4, #0x54]
	ldr r8, [r4, #0x58]
	umull r3, r2, r1, sb
	umull r0, fp, r8, sb
	mla r2, r1, r6, r2
	mov ip, r1, asr #0x1f
	mla fp, r8, r6, fp
	mov r1, r8, asr #0x1f
	mla fp, r1, sb, fp
	mov r0, r0, lsr #0xc
	orr r0, r0, fp, lsl #20
	mla r2, ip, sb, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	ldr r1, [r4, #0x4c]
	str r0, [sp, #0x10]
	add r1, r1, r3
	str r1, [r4, #0x4c]
	ldr r1, [r4, #0x50]
	str r0, [sp, #8]
	add r0, r1, r0
	str r0, [r4, #0x50]
	ldrsh r0, [r4, #0x5e]
	ldrsh r2, [r4, #0x5c]
	str r3, [sp, #0xc]
	mul r1, r0, sb
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	str r3, [sp, #4]
	subs r0, r0, sb
	str r0, [r4, #0x60]
	strmi r7, [r4, #0x60]
	b _0215FBB0
_0215FB68:
	cmp r4, #0
	beq _0215FBB0
	cmp r5, #0
	ldrne r0, [r4, #0x6c]
	strne r0, [r5, #0x6c]
	ldr r1, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	cmp r1, #0
	strne r0, [r1, #0x70]
	streq r0, [sl, #0x54]
	ldr r0, [sl, #0x58]
	str r0, [r4, #0x70]
	mov r0, #0
	str r0, [r4, #0x6c]
	ldr r0, [sl, #0x58]
	cmp r0, #0
	strne r4, [r0, #0x6c]
	str r4, [sl, #0x58]
_0215FBB0:
	mov r4, r5
	cmp r5, #0
	bne _0215FAA4
_0215FBBC:
	ldr r0, [sl, #0x38]
	mov r5, #0
	mov r4, r5
	cmp r0, #0
	bls _0215FC20
	mov r6, r5
_0215FBD4:
	ldr r0, [sl, #0x30]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	ldreq r0, [sl, #0x34]
	streq r6, [r0, r4, lsl #2]
	beq _0215FC10
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sl, #0x34]
	str r0, [r1, r4, lsl #2]
	ldr r0, [sl, #0x34]
	ldr r0, [r0, r4, lsl #2]
	add r5, r5, r0
_0215FC10:
	ldr r0, [sl, #0x38]
	add r4, r4, #1
	cmp r4, r0
	blo _0215FBD4
_0215FC20:
	cmp r5, #0
	beq _0215FD28
	cmp r0, #0
	mov r8, #0
	bls _0215FD28
_0215FC34:
	ldr r0, [sl, #0x30]
	ldr r0, [r0, r8, lsl #2]
	cmp r0, #0
	ldrne r0, [sl, #0x34]
	ldrne r0, [r0, r8, lsl #2]
	cmpne r0, #0
	beq _0215FD18
	cmp r0, #0
	mov r7, #0
	bls _0215FD18
	mov r4, r7
	mov fp, r7
	mov r5, r7
_0215FC68:
	ldr r1, [sl, #0x58]
	mov r6, r5
	cmp r1, #0
	beq _0215FCA8
	ldr r0, [r1, #0x70]
	mov r6, r1
	str r0, [sl, #0x58]
	cmp r0, #0
	strne r5, [r0, #0x6c]
	ldr r0, [sl, #0x54]
	str r0, [r1, #0x70]
	str r4, [r1, #0x6c]
	ldr r0, [sl, #0x54]
	cmp r0, #0
	strne r1, [r0, #0x6c]
	str r1, [sl, #0x54]
_0215FCA8:
	cmp r6, #0
	beq _0215FD04
	ldr r3, [sl, #0x44]
	ldr r2, [sl, #0x40]
	ldr r0, [sl, #0x3c]
	mov r1, r6
	str r0, [r6, #0x2c]
	str fp, [r6, #0x30]
	str r2, [r6, #0x34]
	str r3, [r6, #0x38]
	ldr r0, [sl, #0x30]
	ldr r0, [r0, r8, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [sl, #0x48]
	cmp r0, #0
	beq _0215FD04
	ldr r3, [r0]
	mov r1, r6
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_0215FD04:
	ldr r0, [sl, #0x34]
	add r7, r7, #1
	ldr r0, [r0, r8, lsl #2]
	cmp r7, r0
	blo _0215FC68
_0215FD18:
	ldr r0, [sl, #0x38]
	add r8, r8, #1
	cmp r8, r0
	blo _0215FC34
_0215FD28:
	ldr r0, [sp]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN17CFieldEffectSpray12ov0_02142344EP8Camera2D
_ZN17CFieldEffectSpray12ov0_02142344EP8Camera2D: ; 0x0215FD34
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r0, [r6, #0x14]
	mov r5, r1
	cmp r0, #4
	cmpne r0, #0
	beq _0215FDBC
	cmp r0, #3
	moveq r0, #0
	streq r0, [r6, #0x90]
	ldr r4, [r6, #0x54]
	cmp r4, #0
	beq _0215FDBC
	arm_func_end _ZN17CFieldEffectSpray12ov0_02142344EP8Camera2D
_0215FD68:
	ldr r0, [r6, #0x5c]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x4c]
	ldr r1, [r6, #0x24]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x18]
	ldr r3, [r4, #0x50]
	ldr r2, [r6, #0x28]
	mov r1, r5
	add r2, r3, r2
	str r2, [r4, #0x1c]
	ldrsh r2, [r4, #0x5c]
	strh r2, [r4, #0x28]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x70]
	cmp r4, #0
	bne _0215FD68
_0215FDBC:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17CFieldEffectSpray12sub_0203312CEii
_ZN17CFieldEffectSpray12sub_0203312CEii: ; 0x0215FDC4
	stmdb sp!, {r4, lr}
	cmp r1, #0xf
	mov r3, #1
	addls pc, pc, r1, lsl #2
	b _0215FE9C
_0215FDD8: ; jump table
	b _0215FE9C ; case 0
	b _0215FE18 ; case 1
	b _0215FE24 ; case 2
	b _0215FE9C ; case 3
	b _0215FE9C ; case 4
	b _0215FE9C ; case 5
	b _0215FE9C ; case 6
	b _0215FE9C ; case 7
	b _0215FE70 ; case 8
	b _0215FE30 ; case 9
	b _0215FE3C ; case 10
	b _0215FE9C ; case 11
	b _0215FE9C ; case 12
	b _0215FE48 ; case 13
	b _0215FE50 ; case 14
	b _0215FE7C ; case 15
	arm_func_end _ZN17CFieldEffectSpray12sub_0203312CEii
_0215FE18:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x64]
	b _0215FEA0
_0215FE24:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x68]
	b _0215FEA0
_0215FE30:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x78]
	b _0215FEA0
_0215FE3C:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x7c]
	b _0215FEA0
_0215FE48:
	str r2, [r0, #0x8c]
	b _0215FEA0
_0215FE50:
	ldr ip, _0215FEA8 ; =0x88888889
	mov r4, r2, lsl #0xc
	smull r1, lr, ip, r4
	add lr, lr, r2, lsl #12
	mov r1, r4, lsr #0x1f
	add lr, r1, lr, asr #5
	str lr, [r0, #0x88]
	b _0215FEA0
_0215FE70:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x94]
	b _0215FEA0
_0215FE7C:
	ldr ip, _0215FEAC ; =0xC22E4507
	mov lr, r2, lsl #0x10
	smull r1, r4, ip, lr
	add r4, r4, r2, lsl #16
	mov r1, lr, lsr #0x1f
	add r4, r1, r4, asr #14
	strh r4, [r0, #0x98]
	b _0215FEA0
_0215FE9C:
	mov r3, #0
_0215FEA0:
	mov r0, r3
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215FEA8: .word 0x88888889
_0215FEAC: .word 0xC22E4507

	arm_func_start _ZN17CFieldEffectSpray12ov0_021421F0Eiii
_ZN17CFieldEffectSpray12ov0_021421F0Eiii: ; 0x0215FEB0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	add r0, r7, #0x60
	ldr ip, [r0]
	mov r6, r1
	ldr ip, [ip, #8]
	mov r5, r2
	mov r4, r3
	blx ip
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end _ZN17CFieldEffectSpray12ov0_021421F0Eiii

	arm_func_start _ZN17CFieldEffectSpray20CWaveParticleEmitter6UpdateEi
_ZN17CFieldEffectSpray20CWaveParticleEmitter6UpdateEi: ; 0x0215FEEC
	stmdb sp!, {r4, r5, r6, lr}
	ldr r3, [r0, #0x30]
	mov r2, #0
	cmp r3, #0
	ble _0215FFEC
	sub r1, r3, r1
	str r1, [r0, #0x30]
	cmp r1, #0
	bgt _0215FFEC
	ldrh r1, [r0, #0x3a]
	cmp r1, #0
	streq r2, [r0, #0x40]
	streq r2, [r0, #0x3c]
	moveq r2, #1
	beq _0215FFC8
	ldr r4, _0215FFF4 ; =MAIN_BSS_0210CEC8
	ldr lr, _0215FFF8 ; =0x00007FFF
	ldmia r4, {r1, r3, r5}
	mla r1, r3, r1, r5
	mov r3, r1, lsr #0x10
	mov r3, r3, lsl #0x10
	and r3, lr, r3, lsr #16
	mov ip, #0x7d0
	mov r3, r3, asr #3
	umull r6, r5, r3, ip
	mla r5, r3, r2, r5
	mov r3, r3, asr #0x1f
	mla r5, r3, ip, r5
	adds r6, r6, #0x800
	adc r3, r5, r2
	mov r5, r6, lsr #0xc
	orr r5, r5, r3, lsl #20
	str r1, [r4]
	sub r1, r5, #0x3e8
	str r1, [r0, #0x3c]
	ldmia r4, {r1, r3, r5}
	mla r1, r3, r1, r5
	mov r3, r1, lsr #0x10
	mov r3, r3, lsl #0x10
	and r3, lr, r3, lsr #16
	ldr ip, _0215FFFC ; =0x00001388
	mov r3, r3, asr #3
	umull r5, lr, r3, ip
	mla lr, r3, r2, lr
	mov r3, r3, asr #0x1f
	adds r5, r5, #0x800
	mla lr, r3, ip, lr
	adc r3, lr, r2
	mov r5, r5, lsr #0xc
	ldr r2, _02160000 ; =0xFFFFF63C
	orr r5, r5, r3, lsl #20
	str r1, [r4]
	add r1, r5, r2
	str r1, [r0, #0x40]
	mov r2, #2
	arm_func_end _ZN17CFieldEffectSpray20CWaveParticleEmitter6UpdateEi
_0215FFC8:
	mov r1, #0
	str r1, [r0, #0x48]
	ldrh r1, [r0, #0x3a]
	eor r1, r1, #1
	strh r1, [r0, #0x3a]
	ldr r1, [r0, #0x2c]
	cmp r1, #0
	movgt r1, r1, lsl #0xc
	strgt r1, [r0, #0x30]
_0215FFEC:
	mov r0, r2
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0215FFF4: .word MAIN_BSS_0210CEC8
_0215FFF8: .word 0x00007FFF
_0215FFFC: .word 0x00001388
_02160000: .word 0xFFFFF63C

	arm_func_start _ZN17CFieldEffectSpray20CWaveParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN17CFieldEffectSpray20CWaveParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x02160004
	stmdb sp!, {r3, r4, r5, lr}
	ldmib r0, {r3, r4}
	str r3, [r1, #0x4c]
	str r4, [r1, #0x50]
	ldr r3, [r0, #0x34]
	mov r2, #0
	str r3, [r1, #0x60]
	str r3, [r1, #0x64]
	strh r2, [r1, #0x2a]
	ldr r2, [r0, #0x24]
	ldr r4, _021600B8 ; =FX_SinCosTable_
	add r2, r2, #0x2000
	strh r2, [r1, #0x5c]
	ldr r2, [r0, #0x48]
	ldr r5, [r0, #0x24]
	add r2, r0, r2, lsl #2
	ldr r3, [r2, #0x3c]
	ldr r2, [r0, #0x28]
	add r3, r5, r3
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	mov r3, r3, asr #4
	mov r5, r3, lsl #1
	add r3, r5, #1
	mov lr, r3, lsl #1
	mov r3, r5, lsl #1
	ldrsh lr, [r4, lr]
	ldrsh r3, [r4, r3]
	mov ip, #0x1f
	smull r5, r4, r2, lr
	smull lr, r3, r2, r3
	mov r5, r5, lsr #0xc
	orr r5, r5, r4, lsl #20
	mov r2, lr, lsr #0xc
	str r5, [r1, #0x54]
	orr r2, r2, r3, lsl #20
	str r2, [r1, #0x58]
	ldrh r2, [r0, #0x38]
	strh r2, [r1, #0x5e]
	str ip, [r1, #0x14]
	ldr r1, [r0, #0x48]
	add r1, r1, #1
	cmp r1, #3
	strlt r1, [r0, #0x48]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021600B8: .word FX_SinCosTable_
	arm_func_end _ZN17CFieldEffectSpray20CWaveParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

	arm_func_start _ZN17CFieldEffectSpray20CWaveParticleEmitter5func2Ev
_ZN17CFieldEffectSpray20CWaveParticleEmitter5func2Ev: ; 0x021600BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, [r4, #0x1c]
	ldr r0, [r4, #8]
	ldr r2, [r4, #0x18]
	ldr r1, [r4, #4]
	sub r0, r3, r0
	sub r1, r2, r1
	bl FX_Atan2Idx
	str r0, [r4, #0x24]
	mov r0, #0x1000
	str r0, [r4, #0x30]
	mov r0, #0
	strh r0, [r4, #0x3a]
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17CFieldEffectSpray20CWaveParticleEmitter5func2Ev

	arm_func_start _ZN17CFieldEffectSpray21CWaveParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN17CFieldEffectSpray21CWaveParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x021600F8
	stmdb sp!, {r4, r5, r6, lr}
	ldrh r2, [r0, #4]
	mov r6, r1
	strh r2, [r6, #0x2a]
	ldr r1, [r0, #0xc]
	ldr r5, [r0, #8]
	ldr r4, [r6, #0x60]
	cmp r5, r1
	beq _02160158
	ldr r2, [r6, #0x64]
	sub r0, r1, r5
	sub r1, r2, r4
	smull r3, r0, r1, r0
	mov r3, r3, lsr #0xc
	orr r3, r3, r0, lsl #20
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	add r0, r5, r0
	str r0, [r6, #0x20]
	str r0, [r6, #0x24]
	arm_func_end _ZN17CFieldEffectSpray21CWaveParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_02160158:
	cmp r4, #0x10000
	movlt r0, r4, asr #0xc
	movlt r0, r0, lsl #1
	strlt r0, [r6, #0x14]
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN24CFieldEffectSprayFactory6CreateEi
_ZN24CFieldEffectSprayFactory6CreateEi: ; 0x0216016C
	stmdb sp!, {r4, lr}
	mov r0, #0xbc
	mov r4, r1
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r1, r4
	bl ov0_0215F538
	ldmia sp!, {r4, pc}
	arm_func_end _ZN24CFieldEffectSprayFactory6CreateEi

	arm_func_start _ZN17CFieldEffectSpray12sub_02033028Ev
_ZN17CFieldEffectSpray12sub_02033028Ev: ; 0x02160190
	mov r0, #7
	bx lr
	arm_func_end _ZN17CFieldEffectSpray12sub_02033028Ev

	arm_func_start ov0_02160198
ov0_02160198: ; 0x02160198
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02160198

	arm_func_start ov0_021601AC
ov0_021601AC: ; 0x021601AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_021601AC

	arm_func_start ov0_021601C0
ov0_021601C0: ; 0x021601C0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_021601C0

	arm_func_start ov0_021601D4
ov0_021601D4: ; 0x021601D4
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	ldr r2, _02160384 ; =_ZTV12CFieldEffect+8
	mov r6, r0
	str r2, [r6]
	ldr r2, [r0]
	mov r5, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _02160388 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r2, #0
	str r0, [r6]
	str r2, [r6, #0x1c]
	str r2, [r6, #0x20]
	ldr r1, _0216038C ; =ptr_FUN_overlay_0_021603b0_overlay_0_02178f28
	str r2, [r6, #0x24]
	str r1, [r6]
	ldr r0, _02160390 ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	mov r1, #0x1000
	str r0, [r6, #0x28]
	str r2, [r6, #0x3c]
	str r2, [r6, #0x2c]
	str r2, [r6, #0x30]
	str r2, [r6, #0x34]
	ldr r0, _02160394 ; =_ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
	str r1, [r6, #0x38]
	str r0, [r6, #0x28]
	str r2, [r6, #0x50]
	str r2, [r6, #0x54]
	str r1, [r6, #0x40]
	str r2, [r6, #0x44]
	str r2, [r6, #0x48]
	sub r1, r1, #0x2000
	str r1, [r6, #0x4c]
	ldr r0, _02160398 ; =PTR_LAB_overlay_0_021603a8_overlay_0_02178e9c
	mov r1, #0x10
	str r0, [r6, #0x28]
	str r2, [r6, #0x58]
	str r2, [r6, #0x5c]
	str r2, [r6, #0x60]
	str r2, [r6, #0x64]
	ldr r0, _0216039C ; =PTR_LAB_overlay_0_021603ac_overlay_0_02178e6c
	str r1, [r6, #0x68]
	str r0, [r6, #0x6c]
	strh r2, [r6, #0x70]
	str r2, [r6, #0x74]
	mov r0, #0x34
	strh r2, [r6, #0x78]
	bl _Znwm
	movs r4, r0
	beq _021602C4
	ldr r1, _021603A0 ; =_ZTV16CEffectActorData+8
	add r0, r4, #4
	str r1, [r4]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r1, #0
	str r1, [r4, #0x2c]
	ldr r0, _021603A4 ; =_ZTV27CFieldEffectNormalActorData+8
	str r1, [r4, #0x30]
	str r0, [r4]
	arm_func_end ov0_021601D4
_021602C4:
	cmp r4, #0
	beq _02160368
	mov r0, r4
	mov r1, r5
	mov r2, #0
	bl _ZN27CFieldEffectNormalActorData12ov0_021503B8Eii
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _02160308
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	strh r0, [r6, #0x78]
_02160308:
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r7, r0
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r5, r0
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	str r0, [sp]
	mov r0, r6
	str r5, [sp, #4]
	str r7, [sp, #8]
	ldr r2, [r0]
	add r1, sp, #0
	ldr r2, [r2, #0x5c]
	blx r2
_02160368:
	str r4, [r6, #0x74]
	mov r1, #0x12c
	str r1, [r6, #0x60]
	mov r0, r6
	str r1, [r6, #0x64]
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_02160384: .word _ZTV12CFieldEffect+8
_02160388: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0216038C: .word ptr_FUN_overlay_0_021603b0_overlay_0_02178f28
_02160390: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_02160394: .word _ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
_02160398: .word PTR_LAB_overlay_0_021603a8_overlay_0_02178e9c
_0216039C: .word PTR_LAB_overlay_0_021603ac_overlay_0_02178e6c
_021603A0: .word _ZTV16CEffectActorData+8
_021603A4: .word _ZTV27CFieldEffectNormalActorData+8

	arm_func_start _ZN16CFieldEffectFire16CParticleEmitterD1Ev
_ZN16CFieldEffectFire16CParticleEmitterD1Ev: ; 0x021603A8
	bx lr
	arm_func_end _ZN16CFieldEffectFire16CParticleEmitterD1Ev

	arm_func_start _ZN16CFieldEffectFire17CParticleAnimatorD1Ev
_ZN16CFieldEffectFire17CParticleAnimatorD1Ev: ; 0x021603AC
	bx lr
	arm_func_end _ZN16CFieldEffectFire17CParticleAnimatorD1Ev

	arm_func_start _ZN16CFieldEffectFireD1Ev
_ZN16CFieldEffectFireD1Ev: ; 0x021603B0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _021604AC ; =ptr_FUN_overlay_0_021603b0_overlay_0_02178f28
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _021603EC
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _021603EC
	ldrh r1, [r4, #0x78]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end _ZN16CFieldEffectFireD1Ev
_021603EC:
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _02160410
	beq _02160408
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02160408:
	mov r0, #0
	str r0, [r4, #0x74]
_02160410:
	ldr r0, _021604B0 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0216048C
	beq _02160484
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _02160440
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
_02160440:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _02160458
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_02160458:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _0216047C
	ldr r3, _021604B4 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_0216047C:
	mov r0, r5
	bl _ZdlPv
_02160484:
	mov r0, #0
	str r0, [r4, #0x18]
_0216048C:
	ldr r1, _021604B8 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021604AC: .word ptr_FUN_overlay_0_021603b0_overlay_0_02178f28
_021604B0: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_021604B4: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_021604B8: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_021604BC
ov0_021604BC: ; 0x021604BC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _021605C0 ; =ptr_FUN_overlay_0_021603b0_overlay_0_02178f28
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _021604F8
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _021604F8
	ldrh r1, [r4, #0x78]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end ov0_021604BC
_021604F8:
	ldr r0, [r4, #0x74]
	cmp r0, #0
	beq _0216051C
	beq _02160514
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02160514:
	mov r0, #0
	str r0, [r4, #0x74]
_0216051C:
	ldr r0, _021605C4 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _02160598
	beq _02160590
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0216054C
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
_0216054C:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _02160564
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_02160564:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _02160588
	ldr r3, _021605C8 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_02160588:
	mov r0, r5
	bl _ZdlPv
_02160590:
	mov r0, #0
	str r0, [r4, #0x18]
_02160598:
	ldr r1, _021605CC ; =_ZTV12CFieldEffect+8
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
_021605C0: .word ptr_FUN_overlay_0_021603b0_overlay_0_02178f28
_021605C4: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_021605C8: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_021605CC: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN16CFieldEffectFire12sub_0203312CEii
_ZN16CFieldEffectFire12sub_0203312CEii: ; 0x021605D0
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #8
	mov r0, #1
	addls pc, pc, r1, lsl #2
	b _0216065C
_021605F0: ; jump table
	b _0216065C ; case 0
	b _0216065C ; case 1
	b _0216065C ; case 2
	b _0216062C ; case 3
	b _0216063C ; case 4
	b _02160614 ; case 5
	b _02160620 ; case 6
	b _021608D4 ; case 7
	b _0216064C ; case 8
	arm_func_end _ZN16CFieldEffectFire12sub_0203312CEii
_02160614:
	add sp, sp, #4
	str r5, [r6, #0x5c]
	ldmia sp!, {r3, r4, r5, r6, pc}
_02160620:
	add sp, sp, #4
	str r5, [r6, #0x68]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216062C:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x50]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216063C:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x54]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216064C:
	str r5, [r6, #0x60]
	add sp, sp, #4
	str r5, [r6, #0x64]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0216065C:
	cmp r1, #0
	mov r0, #0
	beq _02160680
	cmp r1, #1
	beq _021608AC
	cmp r1, #2
	beq _021608C4
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_02160680:
	cmp r5, #0
	ble _021608A0
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _021606FC
	beq _021606F4
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _021606B0
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_021606B0:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _021606C8
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_021606C8:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _021606EC
	ldr r3, _021608DC ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x28]
_021606EC:
	mov r0, r4
	bl _ZdlPv
_021606F4:
	mov r0, #0
	str r0, [r6, #0x18]
_021606FC:
	mov r0, #0x3c
	bl _Znwm
	movs r4, r0
	beq _02160834
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
	beq _021607D8
	ldr r1, _021608DC ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _021608E0 ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _021607CC
	mov r1, lr
	mov ip, lr
	mov r2, #0x74
_02160780:
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
	blo _02160780
_021607CC:
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x34]
	b _021607E0
_021607D8:
	str r1, [r4, #0x28]
	str r1, [r4, #0x34]
_021607E0:
	mov r1, #0
	str r1, [r4, #0x38]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _02160828
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
_02160828:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_02160834:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _021608A0
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0216086C
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0216086C:
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
_021608A0:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_021608AC:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_021608C4:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
_021608D4:
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_021608DC: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_021608E0: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev

	arm_func_start _ZN16CFieldEffectFire12ov0_02142264Ei
_ZN16CFieldEffectFire12ov0_02142264Ei: ; 0x021608E4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	str r0, [sp]
	mov r5, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	str r0, [sp, #4]
	cmp r0, #4
	ldrne r0, [sp]
	ldrne sl, [r0, #0x18]
	cmpne sl, #0
	beq _02160BB0
	ldr r0, [sl, #8]
	ldr r4, [sl, #0x30]
	mul sb, r5, r0
	cmp r4, #0
	beq _02160A44
	mov r6, sb, asr #0x1f
	arm_func_end _ZN16CFieldEffectFire12ov0_02142264Ei
_02160928:
	ldr r0, [r4, #0x60]
	ldr r5, [r4, #0x70]
	cmp r0, #0
	beq _021609F0
	ldr r0, [sl, #0x24]
	cmp r0, #0
	beq _02160958
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_02160958:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _02160A38
	ldr r2, [r4, #0x58]
	ldr r8, [r4, #0x54]
	umull r1, r3, r2, sb
	umull r0, fp, r8, sb
	mov r7, r1, lsr #0xc
	mla fp, r8, r6, fp
	mov r1, r8, asr #0x1f
	mla fp, r1, sb, fp
	mov r0, r0, lsr #0xc
	orr r0, r0, fp, lsl #20
	mla r3, r2, r6, r3
	mov r1, r2, asr #0x1f
	mla r3, r1, sb, r3
	orr r7, r7, r3, lsl #20
	ldr r1, [r4, #0x4c]
	str r0, [sp, #8]
	str r0, [sp, #0x10]
	add r0, r1, r0
	str r0, [r4, #0x4c]
	ldr r0, [r4, #0x50]
	str r7, [sp, #0xc]
	add r0, r0, r7
	str r0, [r4, #0x50]
	ldrsh r0, [r4, #0x5e]
	ldrsh r2, [r4, #0x5c]
	str r7, [sp, #0x14]
	mul r1, r0, sb
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	subs r0, r0, sb
	str r0, [r4, #0x60]
	movmi r0, #0
	strmi r0, [r4, #0x60]
	b _02160A38
_021609F0:
	cmp r4, #0
	beq _02160A38
	cmp r5, #0
	ldrne r0, [r4, #0x6c]
	strne r0, [r5, #0x6c]
	ldr r1, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	cmp r1, #0
	strne r0, [r1, #0x70]
	streq r0, [sl, #0x30]
	ldr r0, [sl, #0x34]
	str r0, [r4, #0x70]
	mov r0, #0
	str r0, [r4, #0x6c]
	ldr r0, [sl, #0x34]
	cmp r0, #0
	strne r4, [r0, #0x6c]
	str r4, [sl, #0x34]
_02160A38:
	mov r4, r5
	cmp r5, #0
	bne _02160928
_02160A44:
	ldr r0, [sl, #0x14]
	mov r4, #0
	mov r5, r4
	cmp r0, #0
	bls _02160AA8
	mov r6, r4
_02160A5C:
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [sl, #0x10]
	streq r6, [r0, r5, lsl #2]
	beq _02160A98
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sl, #0x10]
	str r0, [r1, r5, lsl #2]
	ldr r0, [sl, #0x10]
	ldr r0, [r0, r5, lsl #2]
	add r4, r4, r0
_02160A98:
	ldr r0, [sl, #0x14]
	add r5, r5, #1
	cmp r5, r0
	blo _02160A5C
_02160AA8:
	cmp r4, #0
	beq _02160BB0
	cmp r0, #0
	mov r6, #0
	bls _02160BB0
_02160ABC:
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	ldrne r0, [sl, #0x10]
	ldrne r0, [r0, r6, lsl #2]
	cmpne r0, #0
	beq _02160BA0
	cmp r0, #0
	mov r7, #0
	bls _02160BA0
	mov r4, r7
	mov fp, r7
	mov r5, r7
_02160AF0:
	ldr r1, [sl, #0x34]
	mov r8, r5
	cmp r1, #0
	beq _02160B30
	ldr r0, [r1, #0x70]
	mov r8, r1
	str r0, [sl, #0x34]
	cmp r0, #0
	strne r5, [r0, #0x6c]
	ldr r0, [sl, #0x30]
	str r0, [r1, #0x70]
	str r4, [r1, #0x6c]
	ldr r0, [sl, #0x30]
	cmp r0, #0
	strne r1, [r0, #0x6c]
	str r1, [sl, #0x30]
_02160B30:
	cmp r8, #0
	beq _02160B8C
	ldr r3, [sl, #0x20]
	ldr r2, [sl, #0x1c]
	ldr r0, [sl, #0x18]
	mov r1, r8
	str r0, [r8, #0x2c]
	str fp, [r8, #0x30]
	str r2, [r8, #0x34]
	str r3, [r8, #0x38]
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r6, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [sl, #0x24]
	cmp r0, #0
	beq _02160B8C
	ldr r3, [r0]
	mov r1, r8
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_02160B8C:
	ldr r0, [sl, #0x10]
	add r7, r7, #1
	ldr r0, [r0, r6, lsl #2]
	cmp r7, r0
	blo _02160AF0
_02160BA0:
	ldr r0, [sl, #0x14]
	add r6, r6, #1
	cmp r6, r0
	blo _02160ABC
_02160BB0:
	ldr r0, [sp, #4]
	cmp r0, #0
	cmpne r0, #4
	ldrne r0, [sp]
	ldrne r0, [r0, #0x74]
	cmpne r0, #0
	beq _02160C0C
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	ldr r0, [sp]
	mov r1, #0
	ldr r0, [r0, #0x74]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _02160C0C
	ldr r1, [sp]
	ldrh r1, [r1, #0x78]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	ldr r1, [sp]
	strh r0, [r1, #0x70]
_02160C0C:
	ldr r0, [sp, #4]
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN16CFieldEffectFire16CParticleEmitter6UpdateEi
_ZN16CFieldEffectFire16CParticleEmitter6UpdateEi: ; 0x02160C18
	ldr r2, [r0, #0x30]
	mov r3, #0
	cmp r2, #0
	ble _02160C4C
	sub r1, r2, r1
	str r1, [r0, #0x30]
	cmp r1, #0
	bgt _02160C4C
	ldr r1, [r0, #0x34]
	ldr r3, [r0, #0x40]
	cmp r1, #0
	movgt r1, r1, lsl #0xc
	strgt r1, [r0, #0x30]
	arm_func_end _ZN16CFieldEffectFire16CParticleEmitter6UpdateEi
_02160C4C:
	mov r0, r3
	bx lr

	arm_func_start _ZN16CFieldEffectFire16CParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN16CFieldEffectFire16CParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x02160C54
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r5, r0
	mov r4, r1
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
	adds r3, ip, r8
	ldr lr, [r5, #0x3c]
	ldr r6, [r5, #0x38]
	ldr r2, [r1, #0x14]
	sub r6, lr, r6
	str r3, [r0, #0x448]
	adc r0, r2, r7
	str r0, [r1, #4]
	adds r2, r6, #1
	ldreq r6, [r1, #4]
	ldrne r0, [r1, #4]
	ldr lr, _02160D88 ; =MAIN_BSS_0210CEC8
	umullne r1, r6, r0, r2
	ldmia lr, {r0, r1, r3}
	mla r0, r1, r0, r3
	mla r7, r1, r0, r3
	ldr r2, [r5, #0x38]
	mov r3, r0, lsr #0x10
	ldr r1, [r5, #0x28]
	add r2, r2, r6
	str r0, [lr]
	ldr r0, [r5, #0x2c]
	ldr ip, _02160D8C ; =0x00007FFF
	mov r3, r3, lsl #0x10
	mov r6, r7, lsr #0x10
	and r8, ip, r3, lsr #16
	mov r3, r6, lsl #0x10
	and r3, ip, r3, lsr #16
	mov r6, r8, asr #3
	str r7, [lr]
	smull r8, r7, r6, r1
	mov r3, r3, asr #3
	smull ip, r6, r3, r0
	adds r8, r8, #0x800
	adc r3, r7, #0
	mov r7, r8, lsr #0xc
	orr r7, r7, r3, lsl #20
	adds ip, ip, #0x800
	adc r3, r6, #0
	mov r6, ip, lsr #0xc
	orr r6, r6, r3, lsl #20
	sub r7, r7, r1, asr #1
	ldmib r5, {r3, ip}
	sub r1, r6, r0, asr #1
	add r0, r3, r7
	str r0, [r4, #0x4c]
	add r0, ip, r1
	str r0, [r4, #0x50]
	mov r0, r2, lsl #0xc
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	mov r0, #0
	str r0, [r4, #0x54]
	str r0, [r4, #0x58]
	strh r0, [r4, #0x5e]
	ldr r1, [r5, #0x28]
	ldr r0, [r4, #0x50]
	add r0, r0, r1, asr #1
	mov r0, r0, asr #0xc
	add r0, r0, #0x22
	add r0, r0, #0x600
	str r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02160D88: .word MAIN_BSS_0210CEC8
_02160D8C: .word 0x00007FFF
	arm_func_end _ZN16CFieldEffectFire16CParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

	arm_func_start _ZN16CFieldEffectFire17CParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN16CFieldEffectFire17CParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x02160D90
	ldrh r0, [r0, #4]
	strh r0, [r1, #0x2a]
	bx lr
	arm_func_end _ZN16CFieldEffectFire17CParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

	arm_func_start _ZN23CFieldEffectFireFactory6CreateEi
_ZN23CFieldEffectFireFactory6CreateEi: ; 0x02160D9C
	stmdb sp!, {r4, lr}
	mov r0, #0x7c
	mov r4, r1
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r1, r4
	bl ov0_021601D4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN23CFieldEffectFireFactory6CreateEi

	arm_func_start _ZN16CFieldEffectFire13GetForceFieldEv
_ZN16CFieldEffectFire13GetForceFieldEv: ; 0x02160DC0
	add r0, r0, #0x6c
	bx lr
	arm_func_end _ZN16CFieldEffectFire13GetForceFieldEv

	arm_func_start _ZN16CFieldEffectFire10GetEmitterEv
_ZN16CFieldEffectFire10GetEmitterEv: ; 0x02160DC8
	add r0, r0, #0x28
	bx lr
	arm_func_end _ZN16CFieldEffectFire10GetEmitterEv

	arm_func_start _ZN16CFieldEffectFire12sub_020332A4Ev
_ZN16CFieldEffectFire12sub_020332A4Ev: ; 0x02160DD0
	stmdb sp!, {r4, lr}
	ldr r0, [r0, #0x74]
	mov r4, #1
	cmp r0, #0
	beq _02160DF8
	ldr r1, [r0]
	ldr r1, [r1, #0x20]
	blx r1
	cmp r0, #0
	moveq r4, #0
	arm_func_end _ZN16CFieldEffectFire12sub_020332A4Ev
_02160DF8:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN16CFieldEffectFire12sub_02033028Ev
_ZN16CFieldEffectFire12sub_02033028Ev: ; 0x02160E00
	mov r0, #0x11
	bx lr
	arm_func_end _ZN16CFieldEffectFire12sub_02033028Ev

	arm_func_start _ZN16CFieldEffectFire16CParticleEmitter5func2Ev
_ZN16CFieldEffectFire16CParticleEmitter5func2Ev: ; 0x02160E08
	mov r1, #0x1000
	str r1, [r0, #0x30]
	bx lr
	arm_func_end _ZN16CFieldEffectFire16CParticleEmitter5func2Ev

	arm_func_start ov0_02160E14
ov0_02160E14: ; 0x02160E14
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02160E14

	arm_func_start ov0_02160E28
ov0_02160E28: ; 0x02160E28
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02160E28

	arm_func_start ov0_02160E3C
ov0_02160E3C: ; 0x02160E3C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02160E3C

	arm_func_start ov0_02160E50
ov0_02160E50: ; 0x02160E50
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x1c
	ldr r2, _02161144 ; =_ZTV12CFieldEffect+8
	mov sl, r0
	str r2, [sl]
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _02161148 ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [sl]
	str r1, [sl, #0x18]
	ldr r0, _0216114C ; =ptr_FUN_overlay_0_0216116c_overlay_0_02179000
	ldr r5, _02161150 ; =_ZN15CSoftwareSpriteD1Ev
	str r0, [sl]
	ldr r3, _02161154 ; =FUN_02005150
	add r0, sl, #0x2c
	mov r1, #3
	mov r2, #0x4c
	str r5, [sp]
	bl __cxa_vec_ctor
	ldr r0, _02161158 ; =FUN_02007B28
	ldr r3, _0216115C ; =FUN_02007AA4
	str r0, [sp]
	add r0, sl, #0x118
	mov r1, #6
	mov r2, #0x24
	bl __cxa_vec_ctor
	mov r0, #0x34
	bl _Znwm
	str r0, [sp, #0x14]
	cmp r0, #0
	beq _02160F04
	ldr r2, _02161160 ; =_ZTV16CEffectActorData+8
	ldr r1, [sp, #0x14]
	add r0, r0, #4
	str r2, [r1]
	bl _ZN17UnkClass_02007AA4C1Ev
	ldr r0, [sp, #0x14]
	mov r2, #0
	str r2, [r0, #0x2c]
	ldr r1, _02161164 ; =_ZTV27CFieldEffectNormalActorData+8
	str r2, [r0, #0x30]
	str r1, [r0]
	arm_func_end ov0_02160E50
_02160F04:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02161094
	mov r1, r4
	mov r2, #0
	bl _ZN27CFieldEffectNormalActorData12ov0_021503B8Eii
	ldr r0, [sp, #0x14]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	cmp r0, #0
	beq _02161094
	ldr r0, [r0, #4]
	add r1, sl, #0x2cc
	str r0, [sp, #0x10]
	ldr r0, [r0, #0xc]
	mov r2, #0xe
	str r0, [sp, #0x18]
	add r0, r0, #4
	bl MI_CpuCopy8
	ldr r0, [sp, #0x18]
	add r1, sl, #0x2dc
	add r0, r0, #0x12
	mov r2, #0xe
	bl MI_CpuCopy8
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #0xc]
	mov r8, r0
	str r0, [sp, #8]
_02160F7C:
	ldr r1, [sp, #0xc]
	add r2, sl, #0x220
	add r1, r2, r1
	ldr r0, [sp, #0x18]
	mov r2, #4
	bl MI_CpuCopy8
	ldr r0, [sp, #0x10]
	mov r7, #0
	ldr r1, [r0]
	ldr r0, [sp, #4]
	mov sb, r7
	add r2, sl, r0, lsl #4
	str r1, [r2, #0x1f0]
	ldr r0, [sp, #0x10]
	add r1, sl, #0x220
	ldr r0, [r0, #4]
	add r5, sl, #0x1f0
	str r0, [r2, #0x1f4]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #8]
	str r0, [r2, #0x1f8]
	ldr r0, [sp, #0xc]
	add r0, r1, r0
	str r0, [r2, #0x1fc]
	ldr r0, [sp, #8]
	add r1, sl, #0x118
	add r6, r1, r0
	add r4, r0, sl
	ldr r0, [sp, #4]
	add fp, sl, r0, lsl #3
_02160FF4:
	add r0, r6, sb
	add r1, r5, r8
	bl _ZN17UnkClass_02007AA412sub_02007BACEP17NNSG2dPaletteData
	add r0, sb, r4
	ldr r0, [r0, #0x11c]
	mov r1, #0
	ldr r0, [r0, #8]
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	add r1, fp, r7, lsl #2
	add r7, r7, #1
	str r0, [r1, #0x280]
	add sb, sb, #0x24
	cmp r7, #2
	blt _02160FF4
	ldr r0, [sp, #4]
	add r2, sl, #0x13c
	add r0, sl, r0, lsl #3
	ldr r0, [r0, #0x284]
	mov r1, r0, lsl #0x10
	ldr r0, [sp, #8]
	mov r1, r1, lsr #0xd
	add r0, r2, r0
	bl _ZN17UnkClass_02007AA412sub_02007C34Em
	ldr r0, [sp, #4]
	add r8, r8, #0x10
	add r1, sl, r0
	add r0, r0, #1
	str r0, [sp, #4]
	mov r0, #0
	strb r0, [r1, #0x2c8]
	ldr r0, [sp, #4]
	cmp r0, #3
	ldr r0, [sp, #0xc]
	add r0, r0, #0x20
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r0, r0, #0x48
	str r0, [sp, #8]
	blt _02160F7C
_02161094:
	ldr r0, [sp, #0x14]
	mov r1, r0
	str r1, [sl, #0x18]
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	mov r7, r0
	mov r8, #0
	mov r0, #6
	ldr r4, _02161168 ; =0x0000FFFF
	sub r5, r0, #1
	mov r6, #1
	mov fp, r8
_021610CC:
	cmp r7, #0
	beq _0216110C
	mov r0, r7
	mov r1, r6
	mov r2, fp
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, sl, r8, lsl #1
	add r1, r1, #0x100
	mov sb, r5
	strh r0, [r1, #0x10]
_021610F4:
	mov r0, r7
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	cmp sb, #0
	sub sb, sb, #1
	bne _021610F4
	b _02161118
_0216110C:
	add r0, sl, r8, lsl #1
	add r0, r0, #0x100
	strh r4, [r0, #0x10]
_02161118:
	add r8, r8, #1
	cmp r8, #3
	blt _021610CC
	mov r0, sl
	bl ov0_021617A8
	mov r1, #0
	str r1, [sl, #0x1c]
	mov r0, sl
	str r1, [sl, #0x20]
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02161144: .word _ZTV12CFieldEffect+8
_02161148: .word _ZTV17CFieldEffectActor+8
_0216114C: .word ptr_FUN_overlay_0_0216116c_overlay_0_02179000
_02161150: .word _ZN15CSoftwareSpriteD1Ev
_02161154: .word _ZN15CSoftwareSpriteC1Ev
_02161158: .word _ZN17UnkClass_02007AA4D1Ev
_0216115C: .word _ZN17UnkClass_02007AA4C1Ev
_02161160: .word _ZTV16CEffectActorData+8
_02161164: .word _ZTV27CFieldEffectNormalActorData+8
_02161168: .word 0x0000FFFF

	arm_func_start _ZN17CFieldEffectSparkD1Ev
_ZN17CFieldEffectSparkD1Ev: ; 0x0216116C
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	ldr r1, _02161268 ; =ptr_FUN_overlay_0_0216116c_overlay_0_02179000
	mov r4, r0
	mov r7, #0
	str r1, [r4]
	mov r6, r7
	arm_func_end _ZN17CFieldEffectSparkD1Ev
_02161184:
	mov r8, r6
	add r5, r4, r7, lsl #3
_0216118C:
	add r0, r5, r8, lsl #2
	ldr r0, [r0, #0x280]
	cmp r0, #0
	beq _021611A0
	bl NNS_GfdFreeLnkPlttVram
_021611A0:
	add r8, r8, #1
	cmp r8, #2
	blt _0216118C
	add r7, r7, #1
	cmp r7, #3
	blt _02161184
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _021611FC
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	mov r5, r0
	mov r6, #0
_021611DC:
	add r0, r4, r6, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0x10]
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	add r6, r6, #1
	cmp r6, #3
	blt _021611DC
_021611FC:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _02161220
	beq _02161218
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02161218:
	mov r0, #0
	str r0, [r4, #0x18]
_02161220:
	ldr r3, _0216126C ; =FUN_02007B28
	add r0, r4, #0x118
	mov r1, #6
	mov r2, #0x24
	bl __cxa_vec_cleanup
	ldr r3, _02161270 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x2c
	mov r1, #3
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _02161274 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02161268: .word ptr_FUN_overlay_0_0216116c_overlay_0_02179000
_0216126C: .word _ZN17UnkClass_02007AA4D1Ev
_02161270: .word _ZN15CSoftwareSpriteD1Ev
_02161274: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_02161278
ov0_02161278: ; 0x02161278
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	ldr r1, _0216137C ; =ptr_FUN_overlay_0_0216116c_overlay_0_02179000
	mov r4, r0
	mov r7, #0
	str r1, [r4]
	mov r6, r7
	arm_func_end ov0_02161278
_02161290:
	mov r8, r6
	add r5, r4, r7, lsl #3
_02161298:
	add r0, r5, r8, lsl #2
	ldr r0, [r0, #0x280]
	cmp r0, #0
	beq _021612AC
	bl NNS_GfdFreeLnkPlttVram
_021612AC:
	add r8, r8, #1
	cmp r8, #2
	blt _02161298
	add r7, r7, #1
	cmp r7, #3
	blt _02161290
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _02161308
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	mov r5, r0
	mov r6, #0
_021612E8:
	add r0, r4, r6, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0x10]
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	add r6, r6, #1
	cmp r6, #3
	blt _021612E8
_02161308:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0216132C
	beq _02161324
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02161324:
	mov r0, #0
	str r0, [r4, #0x18]
_0216132C:
	ldr r3, _02161380 ; =FUN_02007B28
	add r0, r4, #0x118
	mov r1, #6
	mov r2, #0x24
	bl __cxa_vec_cleanup
	ldr r3, _02161384 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x2c
	mov r1, #3
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _02161388 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0216137C: .word ptr_FUN_overlay_0_0216116c_overlay_0_02179000
_02161380: .word _ZN17UnkClass_02007AA4D1Ev
_02161384: .word _ZN15CSoftwareSpriteD1Ev
_02161388: .word _ZTV12CFieldEffect+8

	arm_func_start _ZN17CFieldEffectSpark12ov0_02142264Ei
_ZN17CFieldEffectSpark12ov0_02142264Ei: ; 0x0216138C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	mov r7, r0
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	cmp r0, #0
	str r0, [sp, #4]
	cmpne r0, #4
	ldrne r0, [r7, #0x18]
	cmpne r0, #0
	beq _021613C0
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	arm_func_end _ZN17CFieldEffectSpark12ov0_02142264Ei
_021613C0:
	ldr r0, [sp, #4]
	cmp r0, #0
	cmpne r0, #4
	beq _0216155C
	mov fp, r7
	add r5, r7, #0x118
	mov r6, #0
_021613DC:
	add r3, r7, r6
	ldrb r2, [r3, #0x2c8]
	mov r0, #0
	mov r1, #0x24
	str r0, [sp]
	eor r0, r2, #1
	and r4, r0, #0xff
	mla r0, r4, r1, fp
	ldrb r0, [r0, #0x138]
	cmp r0, #0
	beq _0216141C
	eor r0, r4, #1
	strb r4, [r3, #0x2c8]
	and r4, r0, #0xff
	mov r0, #1
	str r0, [sp]
_0216141C:
	add r0, r7, r6, lsl #4
	ldr lr, [r0, #0x2a0]
	mov r8, #0
	add sb, sp, #8
_0216142C:
	add r0, r7, r8, lsl #1
	add r1, r0, #0x200
	ldrh r0, [r1, #0xcc]
	ldrh r3, [r1, #0xdc]
	mov ip, r8, lsl #1
	mov r1, r0, asr #5
	and r1, r1, #0x1f
	mov r2, r0, asr #0xa
	and r2, r2, #0x1f
	and r0, r0, #0x1f
	and sl, r3, #0x1f
	sub sl, sl, r0
	mul sl, lr, sl
	add r0, r0, sl, asr #12
	mov sl, r3, asr #0xa
	and sl, sl, #0x1f
	sub sl, sl, r2
	mul sl, lr, sl
	add r2, r2, sl, asr #12
	mov r3, r3, asr #5
	and r3, r3, #0x1f
	sub r3, r3, r1
	mul r3, lr, r3
	add r1, r1, r3, asr #12
	mov r1, r1, lsl #5
	orr r1, r1, r2, lsl #10
	orr r0, r0, r1
	add r8, r8, #1
	strh r0, [sb, ip]
	cmp r8, #7
	blt _0216142C
	add r0, r7, r6, lsl #4
	ldr r2, [r0, #0x2a0]
	ldr r1, [r0, #0x2a4]
	add r1, r2, r1
	str r1, [r0, #0x2a0]
	cmp r1, #0x1000
	blt _021614DC
	mov r1, #0x1000
	str r1, [r0, #0x2a0]
	ldr r1, [r0, #0x2a4]
	rsb r1, r1, #0
	str r1, [r0, #0x2a4]
	b _021614F8
_021614DC:
	cmp r1, #0
	bgt _021614F8
	mov r1, #0
	str r1, [r0, #0x2a0]
	ldr r1, [r0, #0x2a4]
	rsb r1, r1, #0
	str r1, [r0, #0x2a4]
_021614F8:
	ldr r0, [sp]
	cmp r0, #0
	beq _02161548
	mov r0, #0x24
	mla r8, r4, r0, r5
	ldr r1, [r8, #4]
	add r0, sp, #8
	ldr r1, [r1, #0xc]
	mov r2, #0xe
	add r1, r1, #4
	bl MI_CpuCopy8
	add r0, r7, r6, lsl #3
	add r0, r0, r4, lsl #2
	ldr r0, [r0, #0x280]
	cmp r0, #0
	beq _02161548
	mov r1, r0, lsl #0x10
	mov r0, r8
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007C34Em
_02161548:
	add r6, r6, #1
	cmp r6, #3
	add fp, fp, #0x48
	add r5, r5, #0x48
	blt _021613DC
_0216155C:
	ldr r0, [sp, #4]
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN17CFieldEffectSpark12ov0_02142344EP8Camera2D
_ZN17CFieldEffectSpark12ov0_02142344EP8Camera2D: ; 0x02161568
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x10
	mov sl, r0
	ldr r0, [sl, #0x14]
	mov sb, r1
	cmp r0, #4
	cmpne r0, #0
	beq _021616A8
	mov r4, sl
	mov r6, sl
	add r5, sl, #0x118
	add r7, sl, #0x2c
	mov r8, #0
	mov fp, #0x24
	arm_func_end _ZN17CFieldEffectSpark12ov0_02142344EP8Camera2D
_021615A0:
	add r0, sl, r8, lsl #4
	ldr r3, [r0, #0x298]
	ldr r1, [r0, #0x29c]
	ldr ip, [sl, #0x1c]
	add r2, r3, r1
	ldr r1, [sl, #0x20]
	str ip, [sp, #8]
	add r1, r1, r3
	str r2, [r0, #0x298]
	str r1, [sp, #0xc]
	ldr r1, [sl, #0x28]
	cmp r2, r1, asr #1
	mov r1, r1, asr #1
	blt _021615EC
	str r1, [r0, #0x298]
	ldr r1, [r0, #0x29c]
	rsb r1, r1, #0
	str r1, [r0, #0x29c]
	b _02161608
_021615EC:
	rsb r1, r1, #0
	cmp r2, r1
	bgt _02161608
	str r1, [r0, #0x298]
	ldr r1, [r0, #0x29c]
	rsb r1, r1, #0
	str r1, [r0, #0x29c]
_02161608:
	ldr r2, [sp, #8]
	ldr r3, [sp, #0xc]
	str r2, [r4, #0x44]
	str r3, [r4, #0x48]
	ldr r0, [sl, #0x18]
	str r2, [sp]
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	str r3, [sp, #4]
	blx r2
	cmp r0, #0
	beq _02161650
	add r1, sl, r8, lsl #1
	add r1, r1, #0x100
	ldrh r1, [r1, #0x10]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x56]
_02161650:
	add r2, sl, r8
	ldrb r1, [r2, #0x2c8]
	mov r0, #0x24
	mla r0, r1, r0, r5
	str r0, [r4, #0x60]
	ldrb r1, [r2, #0x2c8]
	mla r0, r1, fp, r6
	ldrb r0, [r0, #0x138]
	cmp r0, #0
	beq _0216168C
	mov r0, r7
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
_0216168C:
	add r8, r8, #1
	cmp r8, #3
	add r4, r4, #0x4c
	add r5, r5, #0x48
	add r6, r6, #0x48
	add r7, r7, #0x4c
	blt _021615A0
_021616A8:
	mov r0, #0
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN17CFieldEffectSpark12sub_0203312CEii
_ZN17CFieldEffectSpark12sub_0203312CEii: ; 0x021616B4
	cmp r1, #4
	mov r3, #1
	addls pc, pc, r1, lsl #2
	b _02161708
_021616C4: ; jump table
	b _02161708 ; case 0
	b _021616D8 ; case 1
	b _021616E4 ; case 2
	b _021616F0 ; case 3
	b _021616FC ; case 4
	arm_func_end _ZN17CFieldEffectSpark12sub_0203312CEii
_021616D8:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x1c]
	b _0216170C
_021616E4:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x20]
	b _0216170C
_021616F0:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x24]
	b _0216170C
_021616FC:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x28]
	b _0216170C
_02161708:
	mov r3, #0
_0216170C:
	mov r0, r3
	bx lr

	arm_func_start _ZN17CFieldEffectSpark12ov0_021421F0Eiii
_ZN17CFieldEffectSpark12ov0_021421F0Eiii: ; 0x02161714
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r5, #0x1000
	str r5, [r0, #0x29c]
	mov r4, #0x2000
	str r4, [r0, #0x2ac]
	mov r4, #0x4000
	str r4, [r0, #0x2bc]
	mov ip, #0
	str ip, [r0, #0x2a0]
	mov r4, #0x800
	str r4, [r0, #0x2b0]
	str r5, [r0, #0x2c0]
	ldr r5, _021617A4 ; =MAIN_BSS_0210CEC8
	add lr, r0, #0x298
	mov r6, #0xcc
	arm_func_end _ZN17CFieldEffectSpark12ov0_021421F0Eiii
_02161750:
	ldmia r5, {r4, r7, r8}
	mla r8, r7, r4, r8
	ldr sb, [r0, #0x28]
	mov r4, sb, lsl #0x10
	movs r7, r4, lsr #0x10
	mov r4, r8, lsr #0x10
	mulne r7, r4, r7
	movne r4, r7, lsr #0x10
	str r8, [r5]
	mov r4, r4, lsl #0x10
	mov r8, r4, lsr #0x10
	ldr r7, [r0, #0x28]
	add r4, r0, ip, lsl #4
	sub r7, r8, r7, asr #1
	str r7, [lr], #0x10
	add ip, ip, #1
	str r6, [r4, #0x2a4]
	cmp ip, #3
	blt _02161750
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_021617A4: .word MAIN_BSS_0210CEC8

	arm_func_start ov0_021617A8
ov0_021617A8: ; 0x021617A8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r7, #0
	mov sl, r0
	mov r8, sl
	add sb, sl, #0x118
	mov r6, r7
	mov fp, r7
	mov r4, r7
	arm_func_end ov0_021617A8
_021617C8:
	ldr r0, [sl, #0x18]
	mov r1, r6
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	mov r5, r0
	ldr r0, [sl, #0x18]
	mov r1, fp
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	str r0, [r8, #0x58]
	str r4, [r8, #0x5c]
	str sb, [r8, #0x60]
	str r5, [r8, #0x64]
	add r0, r7, #0x22
	add r1, r7, #8
	strh r4, [r8, #0x56]
	add r7, r7, #1
	str r1, [r8, #0x3c]
	add r0, r0, #0x600
	str r0, [r8, #0x30]
	cmp r7, #3
	add r8, r8, #0x4c
	add sb, sb, #0x48
	blt _021617C8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN17CFieldEffectSpark12sub_020332A4Ev
_ZN17CFieldEffectSpark12sub_020332A4Ev: ; 0x02161834
	stmdb sp!, {r3, lr}
	ldr r3, [r0, #0x18]
	cmp r3, #0
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	mov r2, #0
	arm_func_end _ZN17CFieldEffectSpark12sub_020332A4Ev
_0216184C:
	ldrb r1, [r0, #0x15c]
	cmp r1, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	add r2, r2, #1
	cmp r2, #3
	add r0, r0, #0x48
	blt _0216184C
	mov r0, r3
	ldr r1, [r0]
	ldr r1, [r1, #0x20]
	blx r1
	ldmia sp!, {r3, pc}

	arm_func_start _ZN24CFieldEffectSparkFactory6CreateEi
_ZN24CFieldEffectSparkFactory6CreateEi: ; 0x02161880
	stmdb sp!, {r4, lr}
	mov r0, #0x2ec
	mov r4, r1
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r1, r4
	bl ov0_02160E50
	ldmia sp!, {r4, pc}
	arm_func_end _ZN24CFieldEffectSparkFactory6CreateEi

	arm_func_start _ZN17CFieldEffectSpark12sub_02033028Ev
_ZN17CFieldEffectSpark12sub_02033028Ev: ; 0x021618A4
	mov r0, #0xf
	bx lr
	arm_func_end _ZN17CFieldEffectSpark12sub_02033028Ev

	arm_func_start ov0_021618AC
ov0_021618AC: ; 0x021618AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_021618AC

	arm_func_start ov0_021618C0
ov0_021618C0: ; 0x021618C0
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02161924 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _02161928 ; =ptr_FUN_overlay_0_02161934_overlay_0_021790cc
	ldr ip, _0216192C ; =_ZN15CSoftwareSpriteD1Ev
	str r0, [r4]
	ldr r3, _02161930 ; =FUN_02005150
	add r0, r4, #0x28
	mov r1, #9
	mov r2, #0x4c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r0, r4
	bl ov0_02161DA4
	mov r1, #0
	str r1, [r4, #0x18]
	mov r0, r4
	str r1, [r4, #0x1c]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02161924: .word _ZTV12CFieldEffect+8
_02161928: .word ptr_FUN_overlay_0_02161934_overlay_0_021790cc
_0216192C: .word _ZN15CSoftwareSpriteD1Ev
_02161930: .word _ZN15CSoftwareSpriteC1Ev
	arm_func_end ov0_021618C0

	arm_func_start _ZN17CFieldEffectJumonD1Ev
_ZN17CFieldEffectJumonD1Ev: ; 0x02161934
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02161970 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x28
	mov r1, #9
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _02161974 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02161970: .word _ZN15CSoftwareSpriteD1Ev
_02161974: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN17CFieldEffectJumonD1Ev

	arm_func_start ov0_02161978
ov0_02161978: ; 0x02161978
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _021619BC ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x28
	mov r1, #9
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _021619C0 ; =_ZTV12CFieldEffect+8
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
_021619BC: .word _ZN15CSoftwareSpriteD1Ev
_021619C0: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_02161978

	arm_func_start _ZN17CFieldEffectJumon12ov0_02142264Ei
_ZN17CFieldEffectJumon12ov0_02142264Ei: ; 0x021619C4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	cmp r0, #0
	cmpne r0, #4
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mov r2, r5
	mov r1, #0
	arm_func_end _ZN17CFieldEffectJumon12ov0_02142264Ei
_021619E8:
	mov ip, #0
_021619EC:
	rsb r3, ip, #1
	add r7, r2, r3, lsl #3
	rsb r6, ip, #2
	ldr r3, [r7, #0x2e0]
	add r6, r2, r6, lsl #3
	str r3, [r6, #0x2e0]
	ldr r3, [r7, #0x2e4]
	add ip, ip, #1
	str r3, [r6, #0x2e4]
	cmp ip, #2
	blt _021619EC
	add ip, r2, #0x200
	ldrsh r3, [ip, #0xdc]
	sub r3, r3, r4
	strh r3, [ip, #0xdc]
	ldrsh r3, [ip, #0xdc]
	cmp r3, #0
	bge _02161AA0
	ldrsh r3, [ip, #0xde]
	cmp r1, #2
	strh r3, [ip, #0xdc]
	bne _02161A74
	ldr lr, _02161B20 ; =MAIN_BSS_0210CEC8
	ldmia lr, {r3, r6, r7}
	mla r7, r6, r3, r7
	mov r3, r7, lsr #0x10
	add r3, r3, r3, lsl #3
	mov r3, r3, lsr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	str r7, [lr]
	add r3, r3, #0x18
	strh r3, [ip, #0xda]
	b _02161AA0
_02161A74:
	ldr lr, _02161B20 ; =MAIN_BSS_0210CEC8
	ldmia lr, {r3, r6, r7}
	mla r7, r6, r3, r7
	mov r3, r7, lsr #0x10
	add r3, r3, r3, lsl #3
	mov r3, r3, lsr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	str r7, [lr]
	add r3, r3, #8
	strh r3, [ip, #0xda]
_02161AA0:
	add r3, r2, #0x200
	ldrh r7, [r3, #0xd4]
	ldrh r6, [r3, #0xd6]
	add r1, r1, #1
	add r6, r7, r6
	strh r6, [r3, #0xd4]
	ldrh r7, [r3, #0xda]
	ldrh r6, [r3, #0xd8]
	cmp r6, r7
	strneh r7, [r3, #0xd8]
	add r3, r2, #0x200
	ldrh r6, [r3, #0xd4]
	ldr r7, _02161B24 ; =FX_SinCosTable_
	ldrh ip, [r3, #0xd8]
	mov r6, r6, asr #4
	add r6, r7, r6, lsl #2
	ldrsh r6, [r6, #2]
	ldr lr, [r5, #0x18]
	cmp r1, #3
	mla r6, ip, r6, lr
	str r6, [r2, #0x2e0]
	ldrh ip, [r3, #0xd4]
	ldrh lr, [r3, #0xd8]
	ldr r6, [r5, #0x1c]
	mov r3, ip, asr #4
	mov r3, r3, lsl #2
	ldrsh r3, [r7, r3]
	mla r3, lr, r3, r6
	str r3, [r2, #0x2e4]
	add r2, r2, #0x24
	blt _021619E8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02161B20: .word MAIN_BSS_0210CEC8
_02161B24: .word FX_SinCosTable_

	arm_func_start _ZN17CFieldEffectJumon12ov0_02142344EP8Camera2D
_ZN17CFieldEffectJumon12ov0_02142344EP8Camera2D: ; 0x02161B28
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	mov sl, r0
	ldr r0, [sl, #0x14]
	mov sb, r1
	cmp r0, #4
	cmpne r0, #0
	beq _02161BBC
	mov r5, sl
	add r6, sl, #0x28
	mov fp, #0
	arm_func_end _ZN17CFieldEffectJumon12ov0_02142344EP8Camera2D
_02161B54:
	mov r4, #0
	mov r7, r5
	mov r8, r6
_02161B60:
	add r0, sl, r4, lsl #3
	ldr ip, [r0, #0x2e0]
	ldr r3, [r0, #0x2e4]
	mov r0, r8
	str ip, [r7, #0x40]
	str r3, [r7, #0x44]
	ldr r2, [r0]
	mov r1, sb
	str ip, [sp]
	ldr r2, [r2, #8]
	str r3, [sp, #4]
	blx r2
	add r4, r4, #1
	cmp r4, #3
	add r7, r7, #0x4c
	add r8, r8, #0x4c
	blt _02161B60
	add fp, fp, #1
	cmp fp, #3
	add sl, sl, #0x24
	add r5, r5, #0xe4
	add r6, r6, #0xe4
	blt _02161B54
_02161BBC:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN17CFieldEffectJumon12sub_0203312CEii
_ZN17CFieldEffectJumon12sub_0203312CEii: ; 0x02161BC8
	cmp r1, #4
	mov r3, #1
	addls pc, pc, r1, lsl #2
	b _02161C1C
_02161BD8: ; jump table
	b _02161C1C ; case 0
	b _02161BEC ; case 1
	b _02161BF8 ; case 2
	b _02161C04 ; case 3
	b _02161C10 ; case 4
	arm_func_end _ZN17CFieldEffectJumon12sub_0203312CEii
_02161BEC:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x18]
	b _02161C20
_02161BF8:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x1c]
	b _02161C20
_02161C04:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x20]
	b _02161C20
_02161C10:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x24]
	b _02161C20
_02161C1C:
	mov r3, #0
_02161C20:
	mov r0, r3
	bx lr

	arm_func_start _ZN17CFieldEffectJumon12ov0_021421F0Eiii
_ZN17CFieldEffectJumon12ov0_021421F0Eiii: ; 0x02161C28
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	add r8, r0, #0x200
	mov ip, #0
	ldr r4, _02161D90 ; =MAIN_BSS_0210CEC8
	strh ip, [r8, #0xf8]
	mov r5, #0x2000
	strh r5, [r8, #0xfa]
	ldmia r4, {r5, r6, sb}
	mla r5, r6, r5, sb
	mov r6, r5, lsr #0x10
	add r6, r6, r6, lsl #3
	mov r6, r6, lsr #0x10
	mov r6, r6, lsl #0x10
	mov r6, r6, lsr #0x10
	str r5, [r4]
	add r5, r6, #8
	strh r5, [r8, #0xfc]
	ldrh r5, [r8, #0xfc]
	mov r7, #8
	add lr, r0, #0x300
	strh r5, [r8, #0xfe]
	strh r7, [lr]
	ldr r6, _02161D94 ; =0x00005555
	strh r7, [lr, #2]
	strh r6, [r8, #0xd4]
	ldr r5, _02161D98 ; =0x0000F334
	mov sb, #0x14
	strh r5, [r8, #0xd6]
	ldmia r4, {r5, r7, sl}
	mla r5, r7, r5, sl
	mov r7, r5, lsr #0x10
	add r7, r7, r7, lsl #3
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r7, r7, lsr #0x10
	str r5, [r4]
	add r5, r7, #8
	strh r5, [r8, #0xd8]
	ldrh r5, [r8, #0xd8]
	mov r6, r6, lsl #1
	strh r5, [r8, #0xda]
	strh sb, [r8, #0xdc]
	strh sb, [r8, #0xde]
	ldr r5, _02161D9C ; =0x00001999
	strh r6, [lr, #0x1c]
	strh r5, [lr, #0x1e]
	ldmia r4, {r5, r6, r7}
	mla r5, r6, r5, r7
	mov r6, r5, lsr #0x10
	add r6, r6, r6, lsl #3
	mov r6, r6, lsr #0x10
	mov r6, r6, lsl #0x10
	mov r6, r6, lsr #0x10
	str r5, [r4]
	add r4, r6, #0x18
	strh r4, [lr, #0x20]
	ldrh r4, [lr, #0x20]
	mov r8, #0xa
	mov r7, r0
	strh r4, [lr, #0x22]
	strh r8, [lr, #0x24]
	strh r8, [lr, #0x26]
	ldr r4, _02161DA0 ; =FX_SinCosTable_
	mov r8, ip
	arm_func_end _ZN17CFieldEffectJumon12ov0_021421F0Eiii
_02161D28:
	add r5, r7, #0x200
	ldrh r6, [r5, #0xd4]
	ldrh r5, [r5, #0xd8]
	ldr lr, [r0, #0x18]
	mov r6, r6, asr #4
	mov r6, r6, lsl #1
	mov sb, r6, lsl #1
	add r6, r4, r6, lsl #1
	ldrsh r6, [r6, #2]
	ldrsh sb, [r4, sb]
	ldr sl, [r0, #0x1c]
	mla r6, r5, r6, lr
	mla sl, r5, sb, sl
	mov sb, r8
_02161D60:
	add r5, r7, sb, lsl #3
	str r6, [r5, #0x2e0]
	add sb, sb, #1
	str sl, [r5, #0x2e4]
	cmp sb, #3
	blt _02161D60
	add ip, ip, #1
	cmp ip, #3
	add r7, r7, #0x24
	blt _02161D28
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02161D90: .word MAIN_BSS_0210CEC8
_02161D94: .word 0x00005555
_02161D98: .word 0x0000F334
_02161D9C: .word 0x00001999
_02161DA0: .word FX_SinCosTable_

	arm_func_start ov0_02161DA4
ov0_02161DA4: ; 0x02161DA4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	ldr r1, _02161EE4 ; =DAT_overlay_0_02172ee8
	ldr r2, _02161EE8 ; =MAIN_BSS_0210CA60
	ldrh r8, [r1, #0x12]
	ldrh r7, [r1, #0x14]
	ldrh r6, [r1, #0x16]
	ldrh r5, [r1, #0xc]
	ldrh r4, [r1, #0xe]
	ldrh r3, [r1, #0x10]
	ldr r1, [r2]
	strh r7, [sp, #0x14]
	str r1, [sp, #8]
	str r0, [sp]
	strh r8, [sp, #0x12]
	strh r6, [sp, #0x16]
	strh r5, [sp, #0xc]
	strh r4, [sp, #0xe]
	strh r3, [sp, #0x10]
	mov r7, #0
	mov sb, #8
	arm_func_end ov0_02161DA4
_02161DF8:
	add r0, sp, #0x12
	mov r1, r7, lsl #1
	ldrh fp, [r0, r1]
	add r0, r7, #0x22
	add r0, r0, #0x600
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ldr sl, [sp]
	mov r8, #0
	add r4, r0, #0x27c
_02161E20:
	add r0, r4, #0x400
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r6, r0
	add r0, r4, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r5, r0
	add r0, r4, #0x400
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	str r0, [sl, #0x54]
	mov r0, #0
	str r0, [sl, #0x58]
	str r5, [sl, #0x5c]
	str r6, [sl, #0x60]
	mov r0, #1
	strh r0, [sl, #0x52]
	add r0, r8, sb
	str r0, [sl, #0x38]
	ldr r0, [sp, #4]
	mov r1, r8, lsl #1
	str r0, [sl, #0x2c]
	add r0, sp, #0xc
	ldrh r0, [r0, r1]
	strh fp, [sl, #0x30]
	cmp r7, #2
	str r0, [sl, #0x3c]
	moveq r0, #0x2000
	streq r0, [sl, #0x48]
	streq r0, [sl, #0x4c]
	add r8, r8, #1
	add sl, sl, #0x4c
	cmp r8, #3
	blt _02161E20
	ldr r0, [sp]
	add r7, r7, #1
	add r0, r0, #0xe4
	cmp r7, #3
	str r0, [sp]
	add sb, sb, #3
	blt _02161DF8
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02161EE4: .word DAT_overlay_0_02172ee8
_02161EE8: .word MAIN_BSS_0210CA60

	arm_func_start _ZN24CFieldEffectJumonFactory6CreateEi
_ZN24CFieldEffectJumonFactory6CreateEi: ; 0x02161EEC
	stmdb sp!, {r4, lr}
	mov r0, #0x340
	mov r4, r1
	bl _Znwm
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r1, r4
	bl ov0_021618C0
	ldmia sp!, {r4, pc}
	arm_func_end _ZN24CFieldEffectJumonFactory6CreateEi

	arm_func_start _ZN17CFieldEffectJumon12sub_02033028Ev
_ZN17CFieldEffectJumon12sub_02033028Ev: ; 0x02161F10
	mov r0, #0x10
	bx lr
	arm_func_end _ZN17CFieldEffectJumon12sub_02033028Ev

	arm_func_start ov0_02161F18
ov0_02161F18: ; 0x02161F18
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02161F18

	arm_func_start ov0_02161F2C
ov0_02161F2C: ; 0x02161F2C
	ldr r1, _02161F80 ; =DAT_overlay_0_02179128
	mov r3, #0
	ldr r2, [r1]
	sub r1, r3, #1
	cmp r2, r1
	beq _02161F78
	ldr ip, _02161F84 ; =DAT_overlay_0_02179128
	mvn r1, #0
	arm_func_end ov0_02161F2C
_02161F4C:
	ldr r2, [ip]
	cmp r0, r2
	bne _02161F68
	ldr r1, _02161F84 ; =DAT_overlay_0_02179128
	mov r0, #0xc
	mla r0, r3, r0, r1
	bx lr
_02161F68:
	ldr r2, [ip, #0xc]!
	add r3, r3, #1
	cmp r2, r1
	bne _02161F4C
_02161F78:
	ldr r0, _02161F84 ; =DAT_overlay_0_02179128
	bx lr
	.align 2, 0
_02161F80: .word DAT_overlay_0_02179128
_02161F84: .word DAT_overlay_0_02179128

	arm_func_start ov0_02161F88
ov0_02161F88: ; 0x02161F88
	stmdb sp!, {r3, lr}
	ldr r0, _02161FC8 ; =MAIN_BSS_020B26A0
	ldr r2, _02161FCC ; =MAIN_BSS_0210CA6C
	ldrh r1, [r0, #0x1a]
	ldr r0, [r2]
	bl sub_02041D80
	ldrb r0, [r0]
	bl ov0_02161F2C
	ldrh r3, [r0, #8]
	ldrh r2, [r0, #6]
	ldrh r1, [r0, #4]
	ldr r0, _02161FD0 ; =MAIN_BSS_020B26A0+35584
	strh r1, [r0, #0x78]
	strh r2, [r0, #0x7a]
	strh r3, [r0, #0x7c]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02161FC8: .word MAIN_BSS_020B26A0
_02161FCC: .word MAIN_BSS_0210CA6C
_02161FD0: .word MAIN_BSS_020B26A0+35584
	arm_func_end ov0_02161F88

    arm_func_start ov0_02161FD4
ov0_02161FD4: ; 0x02161FD4
    mov r0, #0
    bx lr
    arm_func_end ov0_02161FD4

	arm_func_start _ZN21CFieldEffectExplosionD1Ev
_ZN21CFieldEffectExplosionD1Ev: ; 0x02161FDC
	stmdb sp!, {r4, r5, r6, lr}
	ldr r1, _02162068 ; =ptr_FUN_overlay_0_02161fdc_overlay_0_02179230
	mov r4, r0
	mov r6, #0
	str r1, [r4]
	mov r5, r6
	arm_func_end _ZN21CFieldEffectExplosionD1Ev
_02161FF4:
	add r0, r4, r6, lsl #2
	ldr r0, [r0, #0xc0]
	cmp r0, #0
	beq _02162028
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _02162028
	add r1, r4, r6, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
_02162028:
	add r6, r6, #1
	cmp r6, #2
	blt _02161FF4
	ldr r3, _0216206C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x24
	mov r1, #2
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _02162070 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02162068: .word ptr_FUN_overlay_0_02161fdc_overlay_0_02179230
_0216206C: .word _ZN15CSoftwareSpriteD1Ev
_02162070: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_02162074
ov0_02162074: ; 0x02162074
	stmdb sp!, {r4, r5, r6, lr}
	ldr r1, _02162108 ; =ptr_FUN_overlay_0_02161fdc_overlay_0_02179230
	mov r4, r0
	mov r6, #0
	str r1, [r4]
	mov r5, r6
	arm_func_end ov0_02162074
_0216208C:
	add r0, r4, r6, lsl #2
	ldr r0, [r0, #0xc0]
	cmp r0, #0
	beq _021620C0
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _021620C0
	add r1, r4, r6, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
_021620C0:
	add r6, r6, #1
	cmp r6, #2
	blt _0216208C
	ldr r3, _0216210C ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x24
	mov r1, #2
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _02162110 ; =_ZTV12CFieldEffect+8
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
_02162108: .word ptr_FUN_overlay_0_02161fdc_overlay_0_02179230
_0216210C: .word _ZN15CSoftwareSpriteD1Ev
_02162110: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_02162114
ov0_02162114: ; 0x02162114
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r5, r0
	mov r4, #0
	str r3, [r5, #0xd0]
	str r4, [r5, #0xd4]
	str r4, [r5, #0xd8]
	str r1, [r5, #0xc0]
	str r2, [r5, #0xc4]
	ldr r0, [r5, #0xc0]
	mov r7, #1
	str r0, [r5, #0x18]
	mov r6, r4
	mov r8, r4
	arm_func_end ov0_02162114
_02162148:
	add r0, r5, r4, lsl #2
	ldr r0, [r0, #0xc0]
	mov r1, r8
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _0216217C
	mov r1, r7
	mov r2, r6
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r5, r4, lsl #1
	strh r0, [r1, #0xbc]
_0216217C:
	add r4, r4, #1
	cmp r4, #2
	blt _02162148
	mov r0, r5
	bl ov0_02162464
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start _ZN21CFieldEffectExplosion12ov0_02142264Ei
_ZN21CFieldEffectExplosion12ov0_02142264Ei: ; 0x02162194
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #8
	mov r6, r0
	mov r5, r1
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	movs r4, r0
	cmpne r4, #4
	beq _021622F4
	ldr r0, [r6, #0xcc]
	cmp r0, #0
	blt _02162208
	str r0, [r6, #0xc8]
	mvn r0, #0
	str r0, [r6, #0xcc]
	ldr r0, [r6, #0xc8]
	mov r1, #0
	add r0, r6, r0, lsl #2
	ldr r0, [r0, #0xc0]
	str r0, [r6, #0x18]
	ldr r0, [r6, #0xc8]
	add r0, r6, r0, lsl #2
	ldr r0, [r0, #0xc0]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r1, [r6, #0xc8]
	add r1, r6, r1, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	arm_func_end _ZN21CFieldEffectExplosion12ov0_02142264Ei
_02162208:
	ldr r0, [r6, #0xc8]
	mov r1, #0
	add r0, r6, r0, lsl #2
	ldr r0, [r0, #0xc0]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _021622F4
	ldr r1, [r6, #0xc8]
	add r1, r6, r1, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_02008860Et
	cmp r0, #0
	ldr r0, [r6, #0xc8]
	bne _02162284
	cmp r0, #0
	bne _02162264
	mov r0, #1
	str r0, [r6, #0xcc]
	mov r0, #0
	str r0, [r6, #0xd4]
	b _021622F4
_02162264:
	cmp r0, #1
	bne _021622F4
	mov r0, r6
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x20]
	blx r2
	b _021622F4
_02162284:
	cmp r0, #1
	bne _021622F4
	ldr r0, [r6, #0xd4]
	cmp r0, #0x2e
	bge _021622F4
	ldr r0, _02162300 ; =MAIN_BSS_0210CA60
	ldr r7, [r0]
	ldrb r0, [r7, #0x87c]
	cmp r0, #0
	bne _021622E8
	mov r0, r6
	bl ov0_02162508
	cmp r0, #0
	beq _021622E8
	ldr r1, [r6, #0x20]
	add r0, r7, #0x7b0
	mov r1, r1, asr #0xc
	str r1, [sp]
	ldr r1, [r6, #0xd8]
	mov r2, #0
	str r1, [sp, #4]
	ldr r3, [r6, #0x1c]
	ldr r1, [r6, #0xd0]
	mov r3, r3, asr #0xc
	bl ov0_02163A08
_021622E8:
	ldr r0, [r6, #0xd4]
	add r0, r0, r5
	str r0, [r6, #0xd4]
_021622F4:
	mov r0, r4
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02162300: .word MAIN_BSS_0210CA60

	arm_func_start _ZN21CFieldEffectExplosion12ov0_02142344EP8Camera2D
_ZN21CFieldEffectExplosion12ov0_02142344EP8Camera2D: ; 0x02162304
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r5, r0
	ldr r0, [r5, #0x14]
	mov r4, r1
	cmp r0, #0
	cmpne r0, #4
	beq _021623AC
	ldr r0, [r5, #0xc8]
	mov r1, #0
	add r0, r5, r0, lsl #2
	ldr r0, [r0, #0xc0]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	mov r3, #0
	beq _02162360
	ldr r1, [r5, #0xc8]
	add r1, r5, r1, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	mov r3, r0
	arm_func_end _ZN21CFieldEffectExplosion12ov0_02142344EP8Camera2D
_02162360:
	ldr r2, [r5, #0xc8]
	mov r0, #0x4c
	mla r1, r2, r0, r5
	strh r3, [r1, #0x4e]
	ldr r1, [r5, #0xc8]
	add r3, r5, #0x24
	mla r2, r1, r0, r3
	ldr lr, [r5, #0x1c]
	ldr ip, [r5, #0x20]
	mov r1, r4
	str lr, [r2, #0x18]
	str ip, [r2, #0x1c]
	ldr r2, [r5, #0xc8]
	str lr, [sp]
	mla r0, r2, r0, r3
	ldr r2, [r0]
	str ip, [sp, #4]
	ldr r2, [r2, #8]
	blx r2
_021623AC:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN21CFieldEffectExplosion12sub_0203312CEii
_ZN21CFieldEffectExplosion12sub_0203312CEii: ; 0x021623B8
	cmp r1, #1
	mov r3, #1
	beq _021623D8
	cmp r1, #2
	beq _021623E4
	cmp r1, #0x12
	beq _021623F0
	b _021623F8
	arm_func_end _ZN21CFieldEffectExplosion12sub_0203312CEii
_021623D8:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x1c]
	b _021623FC
_021623E4:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x20]
	b _021623FC
_021623F0:
	str r2, [r0, #0xd8]
	b _021623FC
_021623F8:
	mov r3, #0
_021623FC:
	mov r0, r3
	bx lr

	arm_func_start _ZN21CFieldEffectExplosion12ov0_021421F0Eiii
_ZN21CFieldEffectExplosion12ov0_021421F0Eiii: ; 0x02162404
	stmdb sp!, {r4, lr}
	mov r1, #0
	mov r4, r0
	str r1, [r4, #0xc8]
	sub r0, r1, #1
	str r0, [r4, #0xcc]
	ldr r0, [r4, #0xc0]
	str r0, [r4, #0x18]
	ldr r0, [r4, #0xc8]
	add r0, r4, r0, lsl #2
	ldr r0, [r0, #0xc0]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r1, [r4, #0xc8]
	add r1, r4, r1, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	mov r1, #0
	mov r0, r4
	mov r3, r1
	sub r2, r1, #1
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21CFieldEffectExplosion12ov0_021421F0Eiii

	arm_func_start ov0_02162464
ov0_02162464: ; 0x02162464
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	mov r8, #0
	mov sb, sl
	mov r5, r8
	mov fp, #8
	mvn r4, #0
	arm_func_end ov0_02162464
_02162480:
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0xc0]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	add r1, sl, r8, lsl #2
	mov r7, r0
	ldr r0, [r1, #0xc0]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r6, r0
	add r0, sl, r8, lsl #2
	ldr r0, [r0, #0xc0]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	str r0, [sb, #0x50]
	str r5, [sb, #0x54]
	str r6, [sb, #0x58]
	str r7, [sb, #0x5c]
	strh r5, [sb, #0x4e]
	str fp, [sb, #0x34]
	add r8, r8, #1
	str r4, [sb, #0x28]
	mov r0, #0x2000
	str r0, [sb, #0x44]
	str r0, [sb, #0x48]
	add sb, sb, #0x4c
	cmp r8, #2
	blt _02162480
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov0_02162508
ov0_02162508: ; 0x02162508
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x30
	ldr r1, _021625D8 ; =MAIN_BSS_0210CA40
	mov r5, r0
	ldr r0, [r1]
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r1, [r0, #0xe0]
	ldr r0, [r0, #8]
	add r4, r1, #0x20800
	cmp r0, #0
	beq _02162578
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02162558
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	b _02162570
	arm_func_end ov0_02162508
_02162558:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_02162570:
	add ip, sp, #0x20
	b _02162594
_02162578:
	mov r0, #0
	add r1, sp, #0
	add ip, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_02162594:
	ldr r3, [r5, #0x1c]
	ldr r2, [r5, #0x20]
	ldmia ip, {r0, r1}
	sub r0, r0, r3
	sub r1, r1, r2
	str r3, [sp, #0x18]
	str r2, [sp, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	bl _Z12sub_02007254ll
	cmp r0, r4
	movlt r0, #1
	movge r0, #0
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021625D8: .word MAIN_BSS_0210CA40

	arm_func_start _ZN21CFieldEffectExplosion12ov0_02142390EPvS0_
_ZN21CFieldEffectExplosion12ov0_02142390EPvS0_: ; 0x021625DC
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x20
	mov r6, r0
	ldr r0, [r6, #0xc8]
	mov r5, r1
	add r0, r6, r0, lsl #2
	ldr r0, [r0, #0xc0]
	mov r1, #0
	ldr r3, [r0]
	mov r4, r2
	ldr r3, [r3, #0x10]
	blx r3
	ldr r1, [r6, #0xc8]
	add r1, r6, r1, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	mov r1, r0
	ldr r0, _021626D0 ; =s_cell_d_overlay_0_0217928c
	bl LogInfo
	add r0, sp, #0
	mov r1, #0
	mov r2, #0x20
	bl MI_CpuFill8
	ldr r0, [r6, #0xc8]
	cmp r0, #1
	bhi _021626C4
	ldr r0, [r6, #0xd4]
	cmp r0, #0x80
	bge _021626C4
	mov r1, #0xd
	sub r0, r1, #0xe
	strb r1, [sp]
	str r0, [sp, #0x1c]
	ldr r1, [r6, #0xd8]
	mov r0, #1
	strb r1, [sp, #2]
	strb r0, [sp, #1]
	ldr r1, [r6, #0x1c]
	add r0, r5, #0x20
	mov r1, r1, asr #0xc
	strh r1, [sp, #8]
	ldr r1, [r6, #0x20]
	cmp r0, r4
	mov r0, r1, asr #0xc
	strh r0, [sp, #0xa]
	ldr r0, [r6, #0xd4]
	ldr r1, [r6, #0xc8]
	and r0, r0, #0x7f
	orr r0, r0, r1, lsl #7
	strb r0, [sp, #3]
	bhi _021626C4
	add r0, sp, #0
	mov r1, r5
	mov r2, #0x20
	bl MI_CpuCopy8
	add sp, sp, #0x20
	mov r0, #0x20
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end _ZN21CFieldEffectExplosion12ov0_02142390EPvS0_
_021626C4:
	mov r0, #0
	add sp, sp, #0x20
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_021626D0: .word s_cell_d_overlay_0_0217928c

	arm_func_start _ZN21CFieldEffectExplosion12ov0_02142388EPKv
_ZN21CFieldEffectExplosion12ov0_02142388EPKv: ; 0x021626D4
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r1
	ldrb r1, [r4, #1]
	mov r5, r0
	tst r1, #1
	beq _021627D8
	ldrb ip, [r4, #3]
	mvn r2, #0
	mov r1, #1
	mov r3, ip, asr #7
	and r3, r3, #1
	str r3, [r5, #0xc8]
	str r2, [r5, #0xcc]
	and r2, ip, #0x7f
	str r2, [r5, #0xd4]
	ldrb r2, [r4, #2]
	str r2, [r5, #0xd8]
	ldr r2, [r5, #0xc8]
	add r2, r5, r2, lsl #2
	ldr r2, [r2, #0xc0]
	str r2, [r5, #0x18]
	ldr r3, [r0]
	ldrsh r2, [r4, #8]
	ldr r3, [r3, #0x38]
	blx r3
	mov r0, r5
	ldr r3, [r0]
	ldrsh r2, [r4, #0xa]
	ldr r3, [r3, #0x38]
	mov r1, #2
	blx r3
	ldr r0, [r5, #0xc8]
	mov r1, #0
	add r0, r5, r0, lsl #2
	ldr r0, [r0, #0xc0]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r1, [r5, #0xc8]
	mov r4, r0
	add r1, r5, r1, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	ldr r6, [r5, #0xd4]
	cmp r6, #0
	blt _0216279C
	arm_func_end _ZN21CFieldEffectExplosion12ov0_02142388EPKv
_0216278C:
	mov r0, r4
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	subs r6, r6, #2
	bpl _0216278C
_0216279C:
	ldr r1, [r5, #0xc8]
	mov r0, r4
	add r1, r5, r1, lsl #1
	ldrh r1, [r1, #0xbc]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	mov r1, r0
	ldr r0, _021627E0 ; =s_cell_d_overlay_0_0217928c
	bl LogInfo
	mov r1, #0
	mov r0, r5
	mov r3, r1
	sub r2, r1, #1
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	mov r0, #1
	ldmia sp!, {r4, r5, r6, pc}
_021627D8:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_021627E0: .word s_cell_d_overlay_0_0217928c

	arm_func_start _ZN28CFieldEffectExplosionFactoryC1EP18CFieldEffectManage
_ZN28CFieldEffectExplosionFactoryC1EP18CFieldEffectManage: ; 0x021627E4
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _02162844 ; =ptr_FUN_overlay_0_0216288c_overlay_0_02179210
	mov r5, r0
	mov r4, r1
	ldr ip, _02162848 ; =_ZN27CFieldEffectAttackActorDataD1Ev
	str r2, [r5]
	ldr r3, _0216284C ; =ov0_02162850
	add r0, r5, #4
	mov r1, #2
	mov r2, #0x34
	str ip, [sp]
	bl __cxa_vec_ctor
	mvn r0, #0
	str r0, [r5, #0x6c]
	mov r0, #0
	str r0, [r5, #0x70]
	cmp r4, #0
	beq _0216283C
	add r0, r4, #0x7b0
	mov r1, #1
	bl ov0_02163904
	str r0, [r5, #0x6c]
	arm_func_end _ZN28CFieldEffectExplosionFactoryC1EP18CFieldEffectManage
_0216283C:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02162844: .word ptr_FUN_overlay_0_0216288c_overlay_0_02179210
_02162848: .word _ZN27CFieldEffectAttackActorDataD1Ev
_0216284C: .word ov0_02162850

	arm_func_start ov0_02162850
ov0_02162850: ; 0x02162850
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, _02162884 ; =_ZTV16CEffectActorData+8
	add r0, r4, #4
	str r1, [r4]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r0, #0
	str r0, [r4, #0x2c]
	ldr r1, _02162888 ; =_ZTV27CFieldEffectAttackActorData+8
	str r0, [r4, #0x30]
	mov r0, r4
	str r1, [r4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02162884: .word _ZTV16CEffectActorData+8
_02162888: .word _ZTV27CFieldEffectAttackActorData+8
	arm_func_end ov0_02162850

	arm_func_start _ZN28CFieldEffectExplosionFactoryD1Ev
_ZN28CFieldEffectExplosionFactoryD1Ev: ; 0x0216288C
	stmdb sp!, {r4, lr}
	ldr r1, _021628BC ; =ptr_FUN_overlay_0_0216288c_overlay_0_02179210
	mov r4, r0
	str r1, [r4]
	bl ov0_02162B08
	ldr r3, _021628C0 ; =_ZN27CFieldEffectAttackActorDataD1Ev
	add r0, r4, #4
	mov r1, #2
	mov r2, #0x34
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021628BC: .word ptr_FUN_overlay_0_0216288c_overlay_0_02179210
_021628C0: .word _ZN27CFieldEffectAttackActorDataD1Ev
	arm_func_end _ZN28CFieldEffectExplosionFactoryD1Ev

	arm_func_start ov0_021628C4
ov0_021628C4: ; 0x021628C4
	stmdb sp!, {r4, lr}
	ldr r1, _021628FC ; =ptr_FUN_overlay_0_0216288c_overlay_0_02179210
	mov r4, r0
	str r1, [r4]
	bl ov0_02162B08
	ldr r3, _02162900 ; =_ZN27CFieldEffectAttackActorDataD1Ev
	add r0, r4, #4
	mov r1, #2
	mov r2, #0x34
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021628FC: .word ptr_FUN_overlay_0_0216288c_overlay_0_02179210
_02162900: .word _ZN27CFieldEffectAttackActorDataD1Ev
	arm_func_end ov0_021628C4

	arm_func_start _ZN28CFieldEffectExplosionFactory6CreateEi
_ZN28CFieldEffectExplosionFactory6CreateEi: ; 0x02162904
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #4
	ldr r1, [r0]
	mov r4, #0
	ldr r1, [r1, #0x20]
	blx r1
	cmp r0, #0
	beq _02162980
	add r0, r5, #0x38
	ldr r1, [r0]
	ldr r1, [r1, #0x20]
	blx r1
	cmp r0, #0
	ldrne r3, [r5, #0x70]
	cmpne r3, #0
	beq _02162980
	mov r2, r3
	mov r1, r4
	arm_func_end _ZN28CFieldEffectExplosionFactory6CreateEi
_02162950:
	ldrb r0, [r2, #0xdc]
	cmp r0, #0
	bne _02162970
	mov r0, #0xe0
	mla r4, r1, r0, r3
	mov r0, #1
	strb r0, [r4, #0xdc]
	b _02162980
_02162970:
	add r1, r1, #1
	cmp r1, #3
	add r2, r2, #0xe0
	blt _02162950
_02162980:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov0_02162988
ov0_02162988: ; 0x02162988
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r2, #1
	mov r3, r2
	add r0, r6, #4
	mov r1, #0x1c
	bl _ZN27CFieldEffectAttackActorData12ov0_0214FFF0Eiii
	cmp r0, #0
	beq _02162A54
	mov r2, #1
	mov r3, r2
	add r0, r6, #0x38
	mov r1, #0x1d
	bl _ZN27CFieldEffectAttackActorData12ov0_0214FFF0Eiii
	cmp r0, #0
	beq _02162A4C
	ldr r0, [r6, #0x70]
	cmp r0, #0
	beq _021629F0
	ldr r3, _02162A60 ; =_ZN21CFieldEffectExplosionD1Ev
	mov r1, #0xe0
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r6, #0x70]
	arm_func_end ov0_02162988
_021629F0:
	ldr ip, _02162A60 ; =_ZN21CFieldEffectExplosionD1Ev
	ldr r3, _02162A64 ; =ov0_02162A68
	mov r0, #3
	mov r1, #0xe0
	mov r2, #8
	str ip, [sp]
	bl __cxa_vec_new
	mov r4, #0
	mov r5, r4
	str r0, [r6, #0x70]
_02162A18:
	ldr r0, [r6, #0x70]
	ldr r3, [r6, #0x6c]
	add r0, r0, r5
	add r1, r6, #4
	add r2, r6, #0x38
	bl ov0_02162114
	add r4, r4, #1
	cmp r4, #3
	add r5, r5, #0xe0
	blt _02162A18
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_02162A4C:
	add r0, r6, #4
	bl _ZN16CEffectActorData7ReleaseEv
_02162A54:
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02162A60: .word _ZN21CFieldEffectExplosionD1Ev
_02162A64: .word ov0_02162A68

	arm_func_start ov0_02162A68
ov0_02162A68: ; 0x02162A68
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02162AF4 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _02162AF8 ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [r4]
	str r1, [r4, #0x18]
	ldr r0, _02162AFC ; =ptr_FUN_overlay_0_02161fdc_overlay_0_02179230
	ldr ip, _02162B00 ; =_ZN15CSoftwareSpriteD1Ev
	str r0, [r4]
	ldr r3, _02162B04 ; =FUN_02005150
	add r0, r4, #0x24
	mov r1, #2
	mov r2, #0x4c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r1, #0
	str r1, [r4, #0xc8]
	str r1, [r4, #0xcc]
	str r1, [r4, #0xd0]
	str r1, [r4, #0xd4]
	str r1, [r4, #0xd8]
	strb r1, [r4, #0xdc]
	strh r1, [r4, #0xc0]
	strh r1, [r4, #0xbc]
	str r1, [r4, #0xc4]
	mov r0, r4
	str r1, [r4, #0xc0]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02162AF4: .word _ZTV12CFieldEffect+8
_02162AF8: .word _ZTV17CFieldEffectActor+8
_02162AFC: .word ptr_FUN_overlay_0_02161fdc_overlay_0_02179230
_02162B00: .word _ZN15CSoftwareSpriteD1Ev
_02162B04: .word _ZN15CSoftwareSpriteC1Ev
	arm_func_end ov0_02162A68

	arm_func_start ov0_02162B08
ov0_02162B08: ; 0x02162B08
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x70]
	cmp r0, #0
	beq _02162B34
	ldr r3, _02162B48 ; =_ZN21CFieldEffectExplosionD1Ev
	mov r1, #0xe0
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x70]
	arm_func_end ov0_02162B08
_02162B34:
	add r0, r4, #4
	bl _ZN16CEffectActorData7ReleaseEv
	add r0, r4, #0x38
	bl _ZN16CEffectActorData7ReleaseEv
	ldmia sp!, {r4, pc}
	.align 2, 0
_02162B48: .word _ZN21CFieldEffectExplosionD1Ev

	arm_func_start _ZN28CFieldEffectExplosionFactory6UpdateEi
_ZN28CFieldEffectExplosionFactory6UpdateEi: ; 0x02162B4C
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #4
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	add r0, r4, #0x38
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	ldmia sp!, {r4, pc}
	arm_func_end _ZN28CFieldEffectExplosionFactory6UpdateEi

	arm_func_start _ZN28CFieldEffectExplosionFactory5ResetEv
_ZN28CFieldEffectExplosionFactory5ResetEv: ; 0x02162B78
	ldr ip, _02162B80 ; =ov0_02162B08
	bx ip
	.align 2, 0
_02162B80: .word ov0_02162B08
	arm_func_end _ZN28CFieldEffectExplosionFactory5ResetEv

	arm_func_start _ZN21CFieldEffectExplosion12ov0_021423A4Ev
_ZN21CFieldEffectExplosion12ov0_021423A4Ev: ; 0x02162B84
	mov r1, #0
	strb r1, [r0, #0xdc]
	bx lr
	arm_func_end _ZN21CFieldEffectExplosion12ov0_021423A4Ev

	arm_func_start _ZN21CFieldEffectExplosion12sub_02033028Ev
_ZN21CFieldEffectExplosion12sub_02033028Ev: ; 0x02162B90
	mov r0, #0xd
	bx lr
	arm_func_end _ZN21CFieldEffectExplosion12sub_02033028Ev

	arm_func_start ov0_02162B98
ov0_02162B98: ; 0x02162B98
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02162C20 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _02162C24 ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [r4]
	ldr r0, _02162C28 ; =ptr_FUN_overlay_0_02162c34_overlay_0_02179304
	str r1, [r4, #0x18]
	ldr ip, _02162C2C ; =_ZN15CSoftwareSpriteD1Ev
	str r0, [r4]
	ldr r3, _02162C30 ; =FUN_02005150
	add r0, r4, #0x6c
	mov r1, #5
	mov r2, #0x4c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r2, #0
	add r1, r4, #0x100
	strh r2, [r1, #0xe8]
	strh r2, [r1, #0xea]
	str r2, [r4, #0x1ec]
	str r2, [r4, #0x1f0]
	str r2, [r4, #0x1f4]
	sub r0, r2, #1
	str r0, [r4, #0x1f8]
	mov r0, r4
	strh r2, [r1, #0xfc]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02162C20: .word _ZTV12CFieldEffect+8
_02162C24: .word _ZTV17CFieldEffectActor+8
_02162C28: .word ptr_FUN_overlay_0_02162c34_overlay_0_02179304
_02162C2C: .word _ZN15CSoftwareSpriteD1Ev
_02162C30: .word _ZN15CSoftwareSpriteC1Ev
	arm_func_end ov0_02162B98

	arm_func_start _ZN17CFieldEffectSlimeD1Ev
_ZN17CFieldEffectSlimeD1Ev: ; 0x02162C34
	stmdb sp!, {r4, lr}
	ldr r1, _02162CA8 ; =ptr_FUN_overlay_0_02162c34_overlay_0_02179304
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _02162C74
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _02162C74
	add r1, r4, #0x100
	ldrh r1, [r1, #0xe8]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end _ZN17CFieldEffectSlimeD1Ev
_02162C74:
	ldr r3, _02162CAC ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x6c
	mov r1, #5
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _02162CB0 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02162CA8: .word ptr_FUN_overlay_0_02162c34_overlay_0_02179304
_02162CAC: .word _ZN15CSoftwareSpriteD1Ev
_02162CB0: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_02162CB4
ov0_02162CB4: ; 0x02162CB4
	stmdb sp!, {r4, lr}
	ldr r1, _02162D30 ; =ptr_FUN_overlay_0_02162c34_overlay_0_02179304
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _02162CF4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _02162CF4
	add r1, r4, #0x100
	ldrh r1, [r1, #0xe8]
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	arm_func_end ov0_02162CB4
_02162CF4:
	ldr r3, _02162D34 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x6c
	mov r1, #5
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	ldr r1, _02162D38 ; =_ZTV12CFieldEffect+8
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
_02162D30: .word ptr_FUN_overlay_0_02162c34_overlay_0_02179304
_02162D34: .word _ZN15CSoftwareSpriteD1Ev
_02162D38: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_02162D3C
ov0_02162D3C: ; 0x02162D3C
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r1, [r4, #0x1f8]
	mov r1, #0
	str r1, [r4, #0x1ec]
	str r3, [r4, #0x1f0]
	str r1, [r4, #0x1f4]
	add r3, r4, #0x100
	ldrh ip, [r3, #0xfc]
	mov r0, r2
	orr ip, ip, #2
	strh ip, [r3, #0xfc]
	str r2, [r4, #0x18]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	beq _02162D98
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, #0x100
	strh r0, [r1, #0xe8]
	arm_func_end ov0_02162D3C
_02162D98:
	mov r0, r4
	bl ov0_02163250
	add r0, r4, #0x1c
	mov r1, #0
	mov r2, #0x50
	bl MI_CpuFill8
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17CFieldEffectSlime12ov0_02142264Ei
_ZN17CFieldEffectSlime12ov0_02142264Ei: ; 0x02162DB4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	mov sl, r0
	mov sb, r1
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	movs fp, r0
	cmpne fp, #4
	beq _02162EAC
	add r0, sl, #0x100
	ldrsh r1, [r0, #0xea]
	sub r1, r1, sb
	strh r1, [r0, #0xea]
	ldrsh r1, [r0, #0xea]
	cmp r1, #0
	bgt _02162E10
	ldrh r0, [r0, #0xfc]
	tst r0, #2
	beq _02162E04
	mov r0, sl
	bl ov0_02163124
	arm_func_end _ZN17CFieldEffectSlime12ov0_02142264Ei
_02162E04:
	add r0, sl, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0xea]
_02162E10:
	mov r6, #0
	ldr r4, _02162EB8 ; =MAIN_BSS_0210CA60
	add r7, sl, #0x1c
	mov r5, r6
_02162E20:
	add r3, sl, r6, lsl #4
	ldrsh r0, [r3, #0x28]
	cmp r0, #0
	ble _02162E9C
	sub r2, r0, sb
	mov r0, sl
	mov r1, r6
	strh r2, [r3, #0x28]
	bl ov0_021631E8
	ldr r8, [r4]
	ldrb r0, [r8, #0x87c]
	cmp r0, #0
	bne _02162E9C
	mov r0, sl
	mov r1, r7
	bl ov0_021632E4
	cmp r0, #0
	beq _02162E9C
	ldr r3, [sl, #0x1f4]
	cmp r3, #0
	ble _02162E9C
	add r1, sl, r6, lsl #4
	ldr r0, [r1, #0x20]
	mov r2, r5
	mov r0, r0, asr #0xc
	stmia sp, {r0, r3}
	ldr r3, [r1, #0x1c]
	ldr r1, [sl, #0x1f0]
	add r0, r8, #0x7b0
	mov r3, r3, asr #0xc
	bl ov0_02163A08
_02162E9C:
	add r6, r6, #1
	cmp r6, #5
	add r7, r7, #0x10
	blt _02162E20
_02162EAC:
	mov r0, fp
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02162EB8: .word MAIN_BSS_0210CA60

	arm_func_start _ZN17CFieldEffectSlime12ov0_02142344EP8Camera2D
_ZN17CFieldEffectSlime12ov0_02142344EP8Camera2D: ; 0x02162EBC
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #8
	mov sl, r0
	ldr r0, [sl, #0x14]
	mov sb, r1
	cmp r0, #0
	cmpne r0, #4
	beq _02162FA4
	ldr r0, [sl, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	cmp r0, #0
	mov r7, #0
	beq _02162F0C
	add r1, sl, #0x100
	ldrh r1, [r1, #0xe8]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	mov r7, r0
	arm_func_end _ZN17CFieldEffectSlime12ov0_02142344EP8Camera2D
_02162F0C:
	ldr r1, [sl, #0x1ec]
	ldr r0, _02162FB0 ; =MAIN_BSS_0210CA60
	ldr r1, [r1, #0x14]
	ldr r0, [r0]
	cmp r1, #0
	movlt r1, #0
	add r0, r0, r1, lsl #2
	ldr r8, [r0, #0x790]
	mov r5, sl
	add r6, sl, #0x6c
	mov r4, #0
_02162F38:
	add r2, sl, r4, lsl #4
	ldrsh r0, [r2, #0x28]
	cmp r0, #0
	ble _02162F90
	strh r7, [r5, #0x96]
	ldr lr, [r2, #0x1c]
	ldr ip, [r2, #0x20]
	mov r0, r6
	str lr, [r5, #0x84]
	str ip, [r5, #0x88]
	ldrb r3, [r2, #0x2a]
	mov r1, sb
	str lr, [sp]
	str r3, [r5, #0x80]
	ldr r2, [r2, #0x24]
	str ip, [sp, #4]
	str r2, [r5, #0x8c]
	str r2, [r5, #0x90]
	str r8, [r5, #0x70]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
_02162F90:
	add r4, r4, #1
	cmp r4, #5
	add r5, r5, #0x4c
	add r6, r6, #0x4c
	blt _02162F38
_02162FA4:
	mov r0, #1
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02162FB0: .word MAIN_BSS_0210CA60

	arm_func_start _ZN17CFieldEffectSlime12sub_0203312CEii
_ZN17CFieldEffectSlime12sub_0203312CEii: ; 0x02162FB4
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	mov r6, r2
	cmp r1, #0x11
	mov r4, #1
	bgt _02162FF4
	cmp r1, #0x11
	bge _02163040
	cmp r1, #2
	bgt _021630A8
	cmp r1, #1
	blt _021630A8
	beq _02163000
	cmp r1, #2
	beq _02163020
	b _021630A8
	arm_func_end _ZN17CFieldEffectSlime12sub_0203312CEii
_02162FF4:
	cmp r1, #0x12
	beq _021630A0
	b _021630A8
_02163000:
	mov r2, r6, lsl #0xc
	mov r1, #0
_02163008:
	add r0, r5, r1, lsl #4
	add r1, r1, #1
	str r2, [r0, #0x1c]
	cmp r1, #5
	blt _02163008
	b _021630AC
_02163020:
	mov r2, r6, lsl #0xc
	mov r1, #0
_02163028:
	add r0, r5, r1, lsl #4
	add r1, r1, #1
	str r2, [r0, #0x20]
	cmp r1, #5
	blt _02163028
	b _021630AC
_02163040:
	ldr r0, _021630B4 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _021630AC
	mov r1, r6
	bl _ZN11CFieldScene12ov0_02123060Em
	str r0, [r5, #0x1ec]
	cmp r0, #0
	beq _021630AC
	add r1, r5, #0x100
	ldrh r1, [r1, #0xfc]
	tst r1, #0x8000
	beq _021630AC
	mov r1, r6, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	moveq r1, r4
	movne r1, #0
	cmp r1, #0
	beq _021630AC
	add r0, r0, #0x100
	ldrh r0, [r0, #0x30]
	str r0, [r5, #0x1f4]
	b _021630AC
_021630A0:
	str r6, [r5, #0x1f4]
	b _021630AC
_021630A8:
	mov r4, #0
_021630AC:
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_021630B4: .word MAIN_BSS_0210CA40

	arm_func_start _ZN17CFieldEffectSlime12ov0_021421F0Eiii
_ZN17CFieldEffectSlime12ov0_021421F0Eiii: ; 0x021630B8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x1ec]
	cmp r1, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZN17CFieldEffectSlime12ov0_021633B8Ev
	mov r1, #0
	mov r0, r4
	mov r3, r1
	sub r2, r1, #1
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17CFieldEffectSlime12ov0_021421F0Eiii

	arm_func_start ov0_021630EC
ov0_021630EC: ; 0x021630EC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	add r0, r5, #0x1c
	mov r1, #0
	mov r2, #0x50
	bl MI_CpuFill8
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	add r0, r5, #0x100
	ldrh r1, [r0, #0xfc]
	orr r1, r1, #0x8000
	strh r1, [r0, #0xfc]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov0_021630EC

	arm_func_start ov0_02163124
ov0_02163124: ; 0x02163124
	sub sp, sp, #0x18
	mov r1, #0
	arm_func_end ov0_02163124
_0216312C:
	add r2, r0, r1, lsl #4
	ldrsh r2, [r2, #0x28]
	cmp r2, #0
	bne _021631D4
	ldr r2, [r0, #0x1ec]
	ldr r2, [r2, #8]
	cmp r2, #0
	beq _02163188
	ldr r2, [r2, #0xc]
	cmp r2, #0
	beq _0216316C
	ldr r3, [r2, #0x20]
	ldr r2, [r2, #0x24]
	str r3, [sp, #0x10]
	str r2, [sp, #0x14]
	b _021631A0
_0216316C:
	mov r2, #0
	add r3, sp, #8
	str r2, [r3]
	str r2, [r3, #4]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
	b _021631A0
_02163188:
	mov r2, #0
	add r3, sp, #0
	str r2, [r3]
	str r2, [r3, #4]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
_021631A0:
	ldr r2, [sp, #0x10]
	add r1, r0, r1, lsl #4
	ldr r0, [sp, #0x14]
	str r2, [r1, #0x1c]
	str r0, [r1, #0x20]
	mov r0, #0x800
	str r0, [r1, #0x24]
	mov r0, #0x96
	strh r0, [r1, #0x28]
	mov r0, #0x1f
	strb r0, [r1, #0x2a]
	add sp, sp, #0x18
	bx lr
_021631D4:
	add r1, r1, #1
	cmp r1, #5
	blt _0216312C
	add sp, sp, #0x18
	bx lr

	arm_func_start ov0_021631E8
ov0_021631E8: ; 0x021631E8
	add r1, r0, r1, lsl #4
	ldrsh r0, [r1, #0x28]
	cmp r0, #0
	bgt _02163208
	mov r0, #0
	strh r0, [r1, #0x28]
	strb r0, [r1, #0x2a]
	bx lr
	arm_func_end ov0_021631E8
_02163208:
	cmp r0, #0x5a
	ble _02163230
	rsb r0, r0, #0x96
	mov r0, r0, lsl #0xc
	mov r0, r0, asr #7
	add r0, r0, #0x800
	str r0, [r1, #0x24]
	mov r0, #0x1f
	strb r0, [r1, #0x2a]
	bx lr
_02163230:
	mov r0, #0x1000
	str r0, [r1, #0x24]
	ldrsh r0, [r1, #0x28]
	cmp r0, #0x1e
	strltb r0, [r1, #0x2a]
	movge r0, #0x1f
	strgeb r0, [r1, #0x2a]
	bx lr

	arm_func_start ov0_02163250
ov0_02163250: ; 0x02163250
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r8, #0
	mov sl, r0
	mov sb, sl
	mov r7, r8
	mov fp, r8
	mov r4, r8
	arm_func_end ov0_02163250
_0216326C:
	ldr r0, [sl, #0x18]
	mov r1, r7
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
	mov r1, fp
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	str r0, [sb, #0x98]
	str r4, [sb, #0x9c]
	str r5, [sb, #0xa0]
	str r6, [sb, #0xa4]
	add r0, r8, #8
	strh r4, [sb, #0x96]
	str r0, [sb, #0x7c]
	add r8, r8, #1
	cmp r8, #5
	add sb, sb, #0x4c
	blt _0216326C
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN17CFieldEffectSlime12ov0_0214239CEi
_ZN17CFieldEffectSlime12ov0_0214239CEi: ; 0x021632DC
	mov r0, #0xa
	bx lr
	arm_func_end _ZN17CFieldEffectSlime12ov0_0214239CEi

	arm_func_start ov0_021632E4
ov0_021632E4: ; 0x021632E4
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x30
	ldr r0, _021633B4 ; =MAIN_BSS_0210CA40
	mov r5, r1
	ldr r0, [r0]
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r1, [r0, #0xe0]
	ldr r0, [r0, #8]
	add r4, r1, #0x9000
	cmp r0, #0
	beq _02163354
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02163334
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	b _0216334C
	arm_func_end ov0_021632E4
_02163334:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_0216334C:
	add ip, sp, #0x20
	b _02163370
_02163354:
	mov r0, #0
	add r1, sp, #0
	add ip, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_02163370:
	ldr r3, [r5]
	ldr r2, [r5, #4]
	ldmia ip, {r0, r1}
	sub r0, r0, r3
	sub r1, r1, r2
	str r3, [sp, #0x18]
	str r2, [sp, #0x1c]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	bl _Z12sub_02007254ll
	cmp r0, r4
	movlt r0, #1
	movge r0, #0
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021633B4: .word MAIN_BSS_0210CA40

	arm_func_start _ZN17CFieldEffectSlime12ov0_021633B8Ev
_ZN17CFieldEffectSlime12ov0_021633B8Ev: ; 0x021633B8
	add r0, r0, #0x100
	ldrh r1, [r0, #0xfc]
	bic r1, r1, #2
	strh r1, [r0, #0xfc]
	bx lr
	arm_func_end _ZN17CFieldEffectSlime12ov0_021633B8Ev

	arm_func_start _ZN17CFieldEffectSlime12ov0_021633CCEv
_ZN17CFieldEffectSlime12ov0_021633CCEv: ; 0x021633CC
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r1, r4, #0x100
	ldrh r1, [r1, #0xfc]
	tst r1, #2
	ldmneia sp!, {r4, pc}
	bl ov0_02163124
	add r0, r4, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0xea]
	ldrh r1, [r0, #0xfc]
	orr r1, r1, #2
	strh r1, [r0, #0xfc]
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17CFieldEffectSlime12ov0_021633CCEv

	arm_func_start _ZN17CFieldEffectSlime12ov0_02142390EPvS0_
_ZN17CFieldEffectSlime12ov0_02142390EPvS0_: ; 0x02163404
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x20
	mov r7, #0
	mov r6, r0
	mov r4, r2
	mov r5, r1
	add r0, sp, #0
	mov r1, r7
	mov r2, #0x20
	bl MI_CpuFill8
	ldr r0, [r6, #0x1f8]
	mvn r1, #0
	cmp r0, #0x84
	beq _02163450
	cmp r0, #0x85
	beq _02163458
	cmp r0, #0x86
	beq _02163460
	b _02163474
	arm_func_end _ZN17CFieldEffectSlime12ov0_02142390EPvS0_
_02163450:
	mov r1, r7
	b _02163474
_02163458:
	mov r1, #1
	b _02163474
_02163460:
	add r0, r6, #0x100
	ldrh r0, [r0, #0xfc]
	tst r0, #0x8000
	movne r1, #3
	moveq r1, #2
_02163474:
	cmp r1, #0
	blt _02163538
	mov r0, r1, lsl #6
	orr r0, r0, #0x12
	strb r0, [sp]
	ldr r0, [r6, #0x1ec]
	add ip, sp, #0
	ldr r0, [r0, #0x58]
	mov r3, #0
	str r0, [sp, #0x1c]
	ldr r0, [r6, #0x1f4]
	mov r1, #1
	strb r0, [sp, #2]
	mov r0, ip
_021634AC:
	add r2, r6, r3, lsl #4
	ldrsh r8, [r2, #0x28]
	cmp r8, #0
	ble _021634EC
	ldr r8, [r2, #0x1c]
	orr sb, r7, r1, lsl r3
	mov r7, r8, asr #0xc
	add r8, r0, r3, lsl #2
	strh r7, [r8, #8]
	ldr lr, [r2, #0x20]
	and r7, sb, #0xff
	mov lr, lr, asr #0xc
	strh lr, [r8, #0xa]
	ldrsh r2, [r2, #0x28]
	rsb r2, r2, #0x96
	strb r2, [ip, #3]
_021634EC:
	add r3, r3, #1
	cmp r3, #5
	add ip, ip, #1
	blt _021634AC
	ldr r0, [r6, #0x14]
	cmp r0, #3
	orreq r0, r7, #0x80
	andeq r7, r0, #0xff
	add r0, r5, #0x20
	strb r7, [sp, #1]
	cmp r0, r4
	bhi _02163538
	add r0, sp, #0
	mov r1, r5
	mov r2, #0x20
	bl MI_CpuCopy8
	add sp, sp, #0x20
	mov r0, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
_02163538:
	mov r0, #0
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN17CFieldEffectSlime12ov0_02142388EPKv
_ZN17CFieldEffectSlime12ov0_02142388EPKv: ; 0x02163544
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r6, r1
	mov r5, #0
	mov r4, #1
	arm_func_end _ZN17CFieldEffectSlime12ov0_02142388EPKv
_02163558:
	ldrb r0, [r6, #2]
	str r0, [r7, #0x1f4]
	ldrb r0, [r6, #1]
	tst r0, r4, lsl r5
	beq _021635A8
	add r0, r6, r5
	ldrb r0, [r0, #3]
	add ip, r7, r5, lsl #4
	add r3, r6, r5, lsl #2
	rsb r0, r0, #0x96
	strh r0, [ip, #0x28]
	ldrsh r2, [r3, #8]
	mov r0, r7
	mov r1, r5
	mov r2, r2, lsl #0xc
	str r2, [ip, #0x1c]
	ldrsh r2, [r3, #0xa]
	mov r2, r2, lsl #0xc
	str r2, [ip, #0x20]
	bl ov0_021631E8
_021635A8:
	add r5, r5, #1
	cmp r5, #5
	blt _02163558
	ldr r1, [r6, #0x1c]
	cmp r1, #0
	beq _02163610
	ldr r0, _02163618 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _021635D8
	bl _ZN11CFieldScene12ov0_02123060Em
	str r0, [r7, #0x1ec]
_021635D8:
	ldrb r0, [r6, #1]
	mov r1, #0
	tst r0, #0x80
	mov r0, r7
	beq _021635FC
	mov r2, r1
	mov r3, #0x96
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	b _02163608
_021635FC:
	mov r3, r1
	sub r2, r1, #1
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
_02163608:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_02163610:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02163618: .word MAIN_BSS_0210CA40

	arm_func_start _ZN24CFieldEffectSlimeFactoryC1EP18CFieldEffectManage
_ZN24CFieldEffectSlimeFactoryC1EP18CFieldEffectManage: ; 0x0216361C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r3, _02163684 ; =ptr_FUN_overlay_0_02163690_overlay_0_021792e4
	mov r5, r0
	ldr r2, _02163688 ; =_ZTV16CEffectActorData+8
	str r3, [r5]
	add r0, r5, #8
	mov r4, r1
	str r2, [r5, #4]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r1, #0
	str r1, [r5, #0x30]
	ldr r0, _0216368C ; =_ZTV27CFieldEffectAttackActorData+8
	str r1, [r5, #0x34]
	str r0, [r5, #4]
	sub r0, r1, #1
	str r0, [r5, #0x38]
	str r0, [r5, #0x3c]
	str r1, [r5, #0x40]
	cmp r4, #0
	beq _0216367C
	add r0, r4, #0x7b0
	mov r1, #2
	bl ov0_02163904
	str r0, [r5, #0x3c]
	arm_func_end _ZN24CFieldEffectSlimeFactoryC1EP18CFieldEffectManage
_0216367C:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02163684: .word ptr_FUN_overlay_0_02163690_overlay_0_021792e4
_02163688: .word _ZTV16CEffectActorData+8
_0216368C: .word _ZTV27CFieldEffectAttackActorData+8

	arm_func_start _ZN24CFieldEffectSlimeFactoryD1Ev
_ZN24CFieldEffectSlimeFactoryD1Ev: ; 0x02163690
	stmdb sp!, {r4, lr}
	ldr r1, _021636B4 ; =ptr_FUN_overlay_0_02163690_overlay_0_021792e4
	mov r4, r0
	str r1, [r4]
	bl ov0_0216383C
	add r0, r4, #4
	bl _ZN16CEffectActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021636B4: .word ptr_FUN_overlay_0_02163690_overlay_0_021792e4
	arm_func_end _ZN24CFieldEffectSlimeFactoryD1Ev

	arm_func_start ov0_021636B8
ov0_021636B8: ; 0x021636B8
	stmdb sp!, {r4, lr}
	ldr r1, _021636E4 ; =ptr_FUN_overlay_0_02163690_overlay_0_021792e4
	mov r4, r0
	str r1, [r4]
	bl ov0_0216383C
	add r0, r4, #4
	bl _ZN16CEffectActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021636E4: .word ptr_FUN_overlay_0_02163690_overlay_0_021792e4
	arm_func_end ov0_021636B8

	arm_func_start _ZN24CFieldEffectSlimeFactory6CreateEi
_ZN24CFieldEffectSlimeFactory6CreateEi: ; 0x021636E8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r6, r1
	ldr r1, [r7, #0x38]
	and r0, r6, #0xff
	cmp r1, r0
	mov r4, #0
	bne _02163780
	add r0, r7, #4
	ldr r1, [r0]
	ldr r1, [r1, #0x20]
	blx r1
	cmp r0, #0
	ldrne r2, [r7, #0x40]
	cmpne r2, #0
	beq _02163780
	mov r5, r4
	arm_func_end _ZN24CFieldEffectSlimeFactory6CreateEi
_0216372C:
	add r1, r2, r5, lsl #9
	add r0, r1, #0x100
	ldrh r0, [r0, #0xfc]
	tst r0, #1
	bne _02163774
	mov r4, r1
	cmp r6, #0x400
	movge r1, #1
	movlt r1, #0
	mov r0, r4
	bl ov0_021630EC
	ldr r0, [r7, #0x40]
	add r0, r0, r5, lsl #9
	add r0, r0, #0x100
	ldrh r1, [r0, #0xfc]
	orr r1, r1, #1
	strh r1, [r0, #0xfc]
	b _02163780
_02163774:
	add r5, r5, #1
	cmp r5, #4
	blt _0216372C
_02163780:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov0_02163788
ov0_02163788: ; 0x02163788
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r2, #1
	mov r3, r2
	add r0, r7, #4
	mov r6, r1
	bl _ZN27CFieldEffectAttackActorData12ov0_0214FFF0Eiii
	cmp r0, #0
	beq _0216382C
	ldr r0, [r7, #0x40]
	cmp r0, #0
	beq _021637D0
	ldr r3, _02163834 ; =_ZN17CFieldEffectSlimeD1Ev
	mov r1, #0x200
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r7, #0x40]
	arm_func_end ov0_02163788
_021637D0:
	ldr ip, _02163834 ; =_ZN17CFieldEffectSlimeD1Ev
	ldr r3, _02163838 ; =ov0_02162B98
	mov r0, #4
	mov r1, #0x200
	mov r2, #8
	str ip, [sp]
	bl __cxa_vec_new
	mov r4, #0
	mov r5, r4
	str r0, [r7, #0x40]
_021637F8:
	ldr r0, [r7, #0x40]
	ldr r3, [r7, #0x3c]
	mov r1, r6
	add r0, r0, r5
	add r2, r7, #4
	bl ov0_02162D3C
	add r4, r4, #1
	cmp r4, #4
	add r5, r5, #0x200
	blt _021637F8
	str r6, [r7, #0x38]
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_0216382C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02163834: .word _ZN17CFieldEffectSlimeD1Ev
_02163838: .word ov0_02162B98

	arm_func_start ov0_0216383C
ov0_0216383C: ; 0x0216383C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x40]
	cmp r0, #0
	beq _02163868
	ldr r3, _0216387C ; =_ZN17CFieldEffectSlimeD1Ev
	mov r1, #0x200
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x40]
	arm_func_end ov0_0216383C
_02163868:
	add r0, r4, #4
	bl _ZN16CEffectActorData7ReleaseEv
	mvn r0, #0
	str r0, [r4, #0x38]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0216387C: .word _ZN17CFieldEffectSlimeD1Ev

	arm_func_start _ZN24CFieldEffectSlimeFactory6UpdateEi
_ZN24CFieldEffectSlimeFactory6UpdateEi: ; 0x02163880
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #4]!
	ldr r1, [r1, #0x18]
	blx r1
	ldmia sp!, {r3, pc}
	arm_func_end _ZN24CFieldEffectSlimeFactory6UpdateEi

	arm_func_start _ZN24CFieldEffectSlimeFactory5ResetEv
_ZN24CFieldEffectSlimeFactory5ResetEv: ; 0x02163894
	ldr ip, _0216389C ; =ov0_0216383C
	bx ip
	.align 2, 0
_0216389C: .word ov0_0216383C
	arm_func_end _ZN24CFieldEffectSlimeFactory5ResetEv

	arm_func_start _ZN17CFieldEffectSlime12ov0_021423A4Ev
_ZN17CFieldEffectSlime12ov0_021423A4Ev: ; 0x021638A0
	add r0, r0, #0x100
	mov r1, #0
	strh r1, [r0, #0xfc]
	bx lr
	arm_func_end _ZN17CFieldEffectSlime12ov0_021423A4Ev

	arm_func_start _ZN17CFieldEffectSlime12sub_02033028Ev
_ZN17CFieldEffectSlime12sub_02033028Ev: ; 0x021638B0
	mov r0, #0x12
	bx lr
	arm_func_end _ZN17CFieldEffectSlime12sub_02033028Ev

	arm_func_start _ZN17UnkClass_021638B8C1Ev
_ZN17UnkClass_021638B8C1Ev: ; 0x021638B8
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x24
	mov r1, #0
	mov r2, #0x24
	bl MI_CpuFill8
	mov r0, r4
	add r1, r4, #0x48
	mov r2, #0x20
	bl sub_02044B48
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021638B8C1Ev

	arm_func_start _ZN17UnkClass_021638B8D1Ev
_ZN17UnkClass_021638B8D1Ev: ; 0x021638E8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov0_021639BC
	mov r0, r4
	bl sub_02044B78
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021638B8D1Ev

	arm_func_start ov0_02163904
ov0_02163904: ; 0x02163904
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x110
	mov r2, r1
	mov r5, r0
	ldr r1, _021639B8 ; =s_data_Script_field_effect_ef_03d_overlay_0_02179360
	add r0, sp, #0xc
	bl OS_SPrintf
	mov r1, r5
	mov r4, #0
	arm_func_end ov0_02163904
_02163928:
	ldr r0, [r1, #0x2c]
	cmp r0, #0
	beq _02163944
	add r4, r4, #1
	cmp r4, #3
	add r1, r1, #0xc
	blt _02163928
_02163944:
	cmp r4, #3
	addge sp, sp, #0x110
	mvnge r0, #0
	ldmgeia sp!, {r4, r5, r6, pc}
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x1000
	mov r0, #0xb8
	ldr r6, [r1, #0x4a8]
	bl _Znwm
	cmp r0, #0
	beq _0216398C
	mov r2, #0
	str r6, [sp]
	str r2, [sp, #4]
	add r1, sp, #0xc
	mov r3, r2
	str r2, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
_0216398C:
	mov r1, #0xc
	mul r2, r4, r1
	add r1, r5, #0x28
	str r0, [r1, r2]
	ldr r0, [r0, #0x4c]
	add r1, r5, #0x2c
	str r0, [r1, r2]
	bl sub_02044AC8
	mov r0, r4
	add sp, sp, #0x110
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_021639B8: .word s_data_Script_field_effect_ef_03d_overlay_0_02179360

	arm_func_start ov0_021639BC
ov0_021639BC: ; 0x021639BC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, #0
	mov r7, r0
	mov r5, r6
	mov r4, r6
	arm_func_end ov0_021639BC
_021639D0:
	ldr r0, [r7, #0x28]
	cmp r0, #0
	beq _021639F0
	beq _021639EC
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_021639EC:
	str r5, [r7, #0x28]
_021639F0:
	add r6, r6, #1
	str r4, [r7, #0x2c]
	cmp r6, #3
	add r7, r7, #0xc
	blt _021639D0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov0_02163A08
ov0_02163A08: ; 0x02163A08
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	mov r7, r2
	mov r6, r3
	cmp r1, #0
	blt _02163A7C
	cmp r1, #3
	bge _02163A7C
	mov r2, #0xc
	mul r4, r1, r2
	add r5, r8, #0x2c
	ldr r1, [r5, r4]
	cmp r1, #0
	beq _02163A7C
	bl sub_02044B84
	ldr r0, [r8, #4]
	ldr r1, [sp, #0x18]
	sub r2, r0, #0x10
	str r2, [r8, #4]
	str r7, [r2]
	str r6, [r2, #4]
	ldr r0, [sp, #0x1c]
	str r1, [r2, #8]
	str r0, [r2, #0xc]
	ldr r1, [r5, r4]
	ldr r2, _02163A84 ; =s_EventHandle_overlay_0_02179384
	mov r0, r8
	mov r3, #4
	bl sub_02046040
	arm_func_end ov0_02163A08
_02163A7C:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02163A84: .word s_EventHandle_overlay_0_02179384

	arm_func_start _ZN22CFieldEffectManpuAngerC1EP16CEffectActorData
_ZN22CFieldEffectManpuAngerC1EP16CEffectActorData: ; 0x02163A88
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r2, _02163CD0 ; =_ZTV12CFieldEffect+8
	mov r5, r0
	str r2, [r5]
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _02163CD4 ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [r5]
	ldr r0, _02163CD8 ; =_ZTV17CFieldEffectManpu+8
	str r4, [r5, #0x18]
	str r0, [r5]
	str r1, [r5, #0x1c]
	strb r1, [r5, #0x20]
	sub r0, r1, #1
	str r0, [r5, #0x24]
	ldr r0, _02163CDC ; =ptr_FUN_overlay_0_02163cfc_overlay_0_02179454
	str r1, [r5, #0x28]
	str r0, [r5]
	mov r0, #0x1000
	str r0, [r5, #0x34]
	mov r0, #1
	str r0, [r5, #0x40]
	str r1, [r5, #0x44]
	str r1, [r5, #0x48]
	str r1, [r5, #0x4c]
	str r1, [r5, #0x50]
	mov r0, #3
	str r0, [r5, #0x58]
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	cmp r0, #0
	beq _02163BA8
	ldr r1, _02163CE0 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _02163CE4 ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	mov ip, #0
	mov r0, ip
	cmp r1, #0
	bls _02163B9C
	mov r1, ip
	mov r7, ip
	mov r2, #0x74
	arm_func_end _ZN22CFieldEffectManpuAngerC1EP16CEffectActorData
_02163B50:
	ldr r3, [r5, #0x54]
	add r6, r0, #1
	add r3, r3, r1
	str ip, [r3, #0x6c]
	ldr r3, [r5, #0x58]
	add r0, r0, #1
	cmp r6, r3
	ldrlo r3, [r5, #0x54]
	mlalo ip, r6, r2, r3
	ldr r3, [r5, #0x54]
	movhs ip, r7
	add r3, r3, r1
	str ip, [r3, #0x70]
	ldr r6, [r5, #0x54]
	ldr r3, [r5, #0x58]
	add ip, r6, r1
	cmp r0, r3
	add r1, r1, #0x74
	blo _02163B50
_02163B9C:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x60]
	b _02163BB0
_02163BA8:
	str r1, [r5, #0x54]
	str r1, [r5, #0x60]
_02163BB0:
	mov r1, #0
	str r1, [r5, #0x64]
	ldr r0, [r5, #0x40]
	cmp r0, #0
	streq r1, [r5, #0x38]
	streq r1, [r5, #0x3c]
	beq _02163BF8
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r5, #0x38]
	ldr r1, [r5, #0x40]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r5, #0x40]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r5, #0x3c]
_02163BF8:
	mov r3, #0
	str r3, [r5, #0x30]
	ldr r0, _02163CE8 ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r3, [r5, #0x2c]
	str r0, [r5, #0x68]
	add r2, r5, #0x68
	str r3, [r2, #0x14]
	str r3, [r2, #4]
	str r3, [r2, #8]
	str r3, [r2, #0xc]
	mov r1, #0x1000
	ldr r0, _02163CEC ; =PTR_LAB_overlay_0_02163cf4_overlay_0_021793ec
	str r1, [r2, #0x10]
	str r0, [r5, #0x68]
	str r3, [r2, #0x18]
	mov r0, #0x14
	str r0, [r2, #0x1c]
	str r3, [r2, #0x20]
	ldr r0, _02163CF0 ; =PTR_LAB_overlay_0_02163cf8_overlay_0_021793bc
	strb r3, [r2, #0x24]
	str r0, [r5, #0x90]
	mov r0, #1
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x40]
	cmp r0, #0
	bls _02163C6C
	ldr r0, [r5, #0x38]
	cmp r0, #0
	strne r2, [r0]
_02163C6C:
	add r1, r5, #0x90
	mov r0, r4
	str r1, [r5, #0x50]
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r7, r0
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r6, r0
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	str r0, [r5, #0x44]
	str r6, [r5, #0x48]
	str r7, [r5, #0x4c]
	mov r1, #0x14
	mov r0, r5
	str r1, [r5, #0x84]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02163CD0: .word _ZTV12CFieldEffect+8
_02163CD4: .word _ZTV17CFieldEffectActor+8
_02163CD8: .word _ZTV17CFieldEffectManpu+8
_02163CDC: .word ptr_FUN_overlay_0_02163cfc_overlay_0_02179454
_02163CE0: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_02163CE4: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
_02163CE8: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_02163CEC: .word PTR_LAB_overlay_0_02163cf4_overlay_0_021793ec
_02163CF0: .word PTR_LAB_overlay_0_02163cf8_overlay_0_021793bc

	arm_func_start _ZN22CFieldEffectManpuAnger8CEmitterD1Ev
_ZN22CFieldEffectManpuAnger8CEmitterD1Ev: ; 0x02163CF4
	bx lr
	arm_func_end _ZN22CFieldEffectManpuAnger8CEmitterD1Ev

	arm_func_start _ZN22CFieldEffectManpuAnger9CAnimatorD1Ev
_ZN22CFieldEffectManpuAnger9CAnimatorD1Ev: ; 0x02163CF8
	bx lr
	arm_func_end _ZN22CFieldEffectManpuAnger9CAnimatorD1Ev

	arm_func_start _ZN22CFieldEffectManpuAngerD1Ev
_ZN22CFieldEffectManpuAngerD1Ev: ; 0x02163CFC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq _02163D1C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x3c]
	arm_func_end _ZN22CFieldEffectManpuAngerD1Ev
_02163D1C:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _02163D34
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x38]
_02163D34:
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq _02163D58
	ldr r3, _02163D68 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x54]
_02163D58:
	mov r0, r4
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02163D68: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev

	arm_func_start ov0_02163D6C
ov0_02163D6C: ; 0x02163D6C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq _02163D8C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x3c]
	arm_func_end ov0_02163D6C
_02163D8C:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _02163DA4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x38]
_02163DA4:
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq _02163DC8
	ldr r3, _02163DE0 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x54]
_02163DC8:
	mov r0, r4
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r4
	bl _ZN17CFieldEffectManpudlEPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02163DE0: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev

	arm_func_start _ZN22CFieldEffectManpuAnger12ov0_021421F0Eiii
_ZN22CFieldEffectManpuAnger12ov0_021421F0Eiii: ; 0x02163DE4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldr ip, [r7, #0x1c]
	add r0, r7, #0x68
	str ip, [r7, #0x80]
	ldr ip, [r0]
	mov r6, r1
	ldr ip, [ip, #8]
	mov r5, r2
	mov r4, r3
	blx ip
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end _ZN22CFieldEffectManpuAnger12ov0_021421F0Eiii

	arm_func_start _ZN22CFieldEffectManpuAnger12ov0_02142264Ei
_ZN22CFieldEffectManpuAnger12ov0_02142264Ei: ; 0x02163E28
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov sl, r0
	mov r5, r1
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	cmp r0, #0
	str r0, [sp]
	cmpne r0, #4
	beq _021640EC
	ldr r0, [sl, #0x34]
	ldr r4, [sl, #0x5c]
	mul sb, r5, r0
	cmp r4, #0
	beq _02163F80
	mov r6, sb, asr #0x1f
	mov r7, #0
	arm_func_end _ZN22CFieldEffectManpuAnger12ov0_02142264Ei
_02163E68:
	ldr r0, [r4, #0x60]
	ldr r5, [r4, #0x70]
	cmp r0, #0
	beq _02163F2C
	ldr r0, [sl, #0x50]
	cmp r0, #0
	beq _02163E98
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_02163E98:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _02163F74
	ldr r1, [r4, #0x54]
	ldr r8, [r4, #0x58]
	umull r3, r2, r1, sb
	umull r0, fp, r8, sb
	mla r2, r1, r6, r2
	mov ip, r1, asr #0x1f
	mla fp, r8, r6, fp
	mov r1, r8, asr #0x1f
	mla fp, r1, sb, fp
	mov r0, r0, lsr #0xc
	orr r0, r0, fp, lsl #20
	mla r2, ip, sb, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	ldr r1, [r4, #0x4c]
	str r0, [sp, #0x10]
	add r1, r1, r3
	str r1, [r4, #0x4c]
	ldr r1, [r4, #0x50]
	str r0, [sp, #8]
	add r0, r1, r0
	str r0, [r4, #0x50]
	ldrsh r0, [r4, #0x5e]
	ldrsh r2, [r4, #0x5c]
	str r3, [sp, #0xc]
	mul r1, r0, sb
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	str r3, [sp, #4]
	subs r0, r0, sb
	str r0, [r4, #0x60]
	strmi r7, [r4, #0x60]
	b _02163F74
_02163F2C:
	cmp r4, #0
	beq _02163F74
	cmp r5, #0
	ldrne r0, [r4, #0x6c]
	strne r0, [r5, #0x6c]
	ldr r1, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	cmp r1, #0
	strne r0, [r1, #0x70]
	streq r0, [sl, #0x5c]
	ldr r0, [sl, #0x60]
	str r0, [r4, #0x70]
	mov r0, #0
	str r0, [r4, #0x6c]
	ldr r0, [sl, #0x60]
	cmp r0, #0
	strne r4, [r0, #0x6c]
	str r4, [sl, #0x60]
_02163F74:
	mov r4, r5
	cmp r5, #0
	bne _02163E68
_02163F80:
	ldr r0, [sl, #0x40]
	mov r5, #0
	mov r4, r5
	cmp r0, #0
	bls _02163FE4
	mov r6, r5
_02163F98:
	ldr r0, [sl, #0x38]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	ldreq r0, [sl, #0x3c]
	streq r6, [r0, r4, lsl #2]
	beq _02163FD4
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sl, #0x3c]
	str r0, [r1, r4, lsl #2]
	ldr r0, [sl, #0x3c]
	ldr r0, [r0, r4, lsl #2]
	add r5, r5, r0
_02163FD4:
	ldr r0, [sl, #0x40]
	add r4, r4, #1
	cmp r4, r0
	blo _02163F98
_02163FE4:
	cmp r5, #0
	beq _021640EC
	cmp r0, #0
	mov r8, #0
	bls _021640EC
_02163FF8:
	ldr r0, [sl, #0x38]
	ldr r0, [r0, r8, lsl #2]
	cmp r0, #0
	ldrne r0, [sl, #0x3c]
	ldrne r0, [r0, r8, lsl #2]
	cmpne r0, #0
	beq _021640DC
	cmp r0, #0
	mov r7, #0
	bls _021640DC
	mov r4, r7
	mov fp, r7
	mov r5, r7
_0216402C:
	ldr r1, [sl, #0x60]
	mov r6, r5
	cmp r1, #0
	beq _0216406C
	ldr r0, [r1, #0x70]
	mov r6, r1
	str r0, [sl, #0x60]
	cmp r0, #0
	strne r5, [r0, #0x6c]
	ldr r0, [sl, #0x5c]
	str r0, [r1, #0x70]
	str r4, [r1, #0x6c]
	ldr r0, [sl, #0x5c]
	cmp r0, #0
	strne r1, [r0, #0x6c]
	str r1, [sl, #0x5c]
_0216406C:
	cmp r6, #0
	beq _021640C8
	ldr r3, [sl, #0x4c]
	ldr r2, [sl, #0x48]
	ldr r0, [sl, #0x44]
	mov r1, r6
	str r0, [r6, #0x2c]
	str fp, [r6, #0x30]
	str r2, [r6, #0x34]
	str r3, [r6, #0x38]
	ldr r0, [sl, #0x38]
	ldr r0, [r0, r8, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [sl, #0x50]
	cmp r0, #0
	beq _021640C8
	ldr r3, [r0]
	mov r1, r6
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_021640C8:
	ldr r0, [sl, #0x3c]
	add r7, r7, #1
	ldr r0, [r0, r8, lsl #2]
	cmp r7, r0
	blo _0216402C
_021640DC:
	ldr r0, [sl, #0x40]
	add r8, r8, #1
	cmp r8, r0
	blo _02163FF8
_021640EC:
	ldr r0, [sp]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN22CFieldEffectManpuAnger8SetDepthEl
_ZN22CFieldEffectManpuAnger8SetDepthEl: ; 0x021640F8
	str r1, [r0, #0x64]
	bx lr
	arm_func_end _ZN22CFieldEffectManpuAnger8SetDepthEl

	arm_func_start _ZN22CFieldEffectManpuAnger4DrawEP8Camera2D
_ZN22CFieldEffectManpuAnger4DrawEP8Camera2D: ; 0x02164100
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r0, [r6, #0x14]
	mov r5, r1
	cmp r0, #0
	cmpne r0, #4
	ldrne r4, [r6, #0x5c]
	cmpne r4, #0
	beq _02164178
	arm_func_end _ZN22CFieldEffectManpuAnger4DrawEP8Camera2D
_02164124:
	ldr r0, [r6, #0x64]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x4c]
	ldr r1, [r6, #0x2c]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x18]
	ldr r3, [r4, #0x50]
	ldr r2, [r6, #0x30]
	mov r1, r5
	add r2, r3, r2
	str r2, [r4, #0x1c]
	ldrsh r2, [r4, #0x5c]
	strh r2, [r4, #0x28]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x70]
	cmp r4, #0
	bne _02164124
_02164178:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN22CFieldEffectManpuAnger8CEmitter5func2Ev
_ZN22CFieldEffectManpuAnger8CEmitter5func2Ev: ; 0x02164180
	mov r1, #0x1000
	str r1, [r0, #0x20]
	bx lr
	arm_func_end _ZN22CFieldEffectManpuAnger8CEmitter5func2Ev

	arm_func_start _ZN22CFieldEffectManpuAnger8CEmitter6UpdateEi
_ZN22CFieldEffectManpuAnger8CEmitter6UpdateEi: ; 0x0216418C
	ldr r2, [r0, #0x20]
	mov r3, #0
	cmp r2, #0
	ble _021641C0
	sub r1, r2, r1
	str r1, [r0, #0x20]
	cmp r1, #0
	bgt _021641C0
	ldr r1, [r0, #0x1c]
	mov r3, #1
	cmp r1, #0
	movgt r1, r1, lsl #0xc
	strgt r1, [r0, #0x20]
	arm_func_end _ZN22CFieldEffectManpuAnger8CEmitter6UpdateEi
_021641C0:
	mov r0, r3
	bx lr

	arm_func_start _ZN22CFieldEffectManpuAnger8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN22CFieldEffectManpuAnger8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x021641C8
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x38
	mov r5, r0
	ldr r0, [r5, #0x18]
	mov r4, r1
	cmp r0, #0
	addeq sp, sp, #0x38
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _02164234
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _02164214
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #8]
	str r1, [sp, #0xc]
	b _0216422C
	arm_func_end _ZN22CFieldEffectManpuAnger8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_02164214:
	mov r1, #0
	add r2, sp, #0x20
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
_0216422C:
	add r3, sp, #8
	b _02164250
_02164234:
	mov r1, #0
	add r2, sp, #0x28
	add r3, sp, #8
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
_02164250:
	ldr r6, [r3]
	ldr r3, [r3, #4]
	ldr r2, [r0, #0x70]
	ldr r1, [r0, #0x74]
	add r2, r2, r6
	add r1, r1, r3
	ldr r0, [r0, #8]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r2, [sp]
	str r1, [sp, #4]
	cmp r0, #0
	beq _021642B4
	ldr r2, [r0, #0xc]
	cmp r2, #0
	moveq r3, #0
	beq _021642B8
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r3, r2, r0
	b _021642B8
_021642B4:
	mov r3, #0
_021642B8:
	mov r0, #0x14000
	str r0, [r4, #0x60]
	ldr r2, [sp, #4]
	ldr r1, [sp]
	sub r2, r2, r3
	str r0, [r4, #0x64]
	mov r0, #0
	strh r0, [r4, #0x5e]
	mov r0, #0x1f
	str r2, [sp, #4]
	str r1, [sp, #0x30]
	str r2, [sp, #0x34]
	str r0, [r4, #0x14]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr ip, [r0, #0x448]
	ldmib r1, {r3, lr}
	umull r7, r6, lr, ip
	mla r6, lr, r3, r6
	ldr r3, [r1, #0xc]
	ldr r8, [r1, #0x10]
	mla r6, r3, ip, r6
	ldr lr, [r1, #0x14]
	adds r7, r8, r7
	adc r3, lr, r6
	str r7, [r0, #0x448]
	str r3, [r1, #4]
	ldrb r1, [r5, #0x24]
	mov r2, #0
	mov r0, r2, lsl #1
	add r1, r1, #1
	orr r0, r0, r3, lsr #31
	add r1, r1, r0
	and r0, r1, #0xff
	cmp r0, #3
	strb r1, [r5, #0x24]
	subhs r0, r0, #3
	strcsb r0, [r5, #0x24]
	ldrb r0, [r5, #0x24]
	cmp r0, #0
	beq _02164370
	cmp r0, #1
	beq _021643A4
	b _021643D8
_02164370:
	ldr r1, [sp, #0x30]
	mov r0, #0x1c00
	sub r2, r1, #0x4000
	ldr r1, [sp, #0x34]
	str r2, [r4, #0x4c]
	str r1, [r4, #0x50]
	rsb r0, r0, #0
	str r0, [r4, #0x54]
	str r0, [r4, #0x58]
	mov r0, #1
	add sp, sp, #0x38
	str r0, [r4, #0x68]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
_021643A4:
	ldr r1, [sp, #0x30]
	mov r0, #0x1c00
	add r2, r1, #0x4000
	ldr r1, [sp, #0x34]
	str r2, [r4, #0x4c]
	str r1, [r4, #0x50]
	str r0, [r4, #0x54]
	sub r0, r0, #0x3800
	str r0, [r4, #0x58]
	mov r0, #0
	add sp, sp, #0x38
	str r0, [r4, #0x68]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
_021643D8:
	ldr r1, [sp, #0x30]
	ldr r0, [sp, #0x34]
	str r1, [r4, #0x4c]
	mov r1, #0
	str r0, [r4, #0x50]
	str r1, [r4, #0x54]
	sub r0, r1, #0x1c00
	str r0, [r4, #0x58]
	str r1, [r4, #0x68]
	add sp, sp, #0x38
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start _ZN22CFieldEffectManpuAnger9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN22CFieldEffectManpuAnger9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x02164404
	stmdb sp!, {r4, lr}
	mov r4, r1
	ldr r2, [r4, #0x64]
	ldr r0, [r4, #0x60]
	sub r0, r2, r0
	cmp r0, #0x4000
	movlt r1, #0x800
	blt _0216446C
	sub r3, r0, #0x4000
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	sub r2, r2, #0x4000
	mov ip, #0
	str ip, [r4, #0x54]
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	str ip, [r4, #0x58]
	bl _ll_div
	mov r1, r0, asr #0x1f
	mov r1, r1, lsl #0xc
	mov r2, r0, lsl #0xc
	orr r1, r1, r0, lsr #20
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r1, r0, #0x800
	arm_func_end _ZN22CFieldEffectManpuAnger9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_0216446C:
	ldr r0, [r4, #0x68]
	tst r0, #1
	rsbne r0, r1, #0
	strne r0, [r4, #0x20]
	streq r1, [r4, #0x20]
	str r1, [r4, #0x24]
	ldmia sp!, {r4, pc}

	arm_func_start ov0_02164488
ov0_02164488: ; 0x02164488
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02164488

	arm_func_start ov0_0216449C
ov0_0216449C: ; 0x0216449C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216449C

	arm_func_start _ZN20CFieldEffectManpuAseC1EP16CEffectActorDataP17UnkClass_0216D420
_ZN20CFieldEffectManpuAseC1EP16CEffectActorDataP17UnkClass_0216D420: ; 0x021644B0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r3, _021645B0 ; =_ZTV12CFieldEffect+8
	mov r5, r0
	str r3, [r5]
	ldr r3, [r0]
	mov r6, r1
	ldr r3, [r3, #0x14]
	mov r4, r2
	blx r3
	ldr r0, _021645B4 ; =_ZTV17CFieldEffectActor+8
	mov r2, #0
	str r0, [r5]
	ldr r0, _021645B8 ; =_ZTV17CFieldEffectManpu+8
	str r6, [r5, #0x18]
	str r0, [r5]
	str r2, [r5, #0x1c]
	strb r2, [r5, #0x20]
	sub r0, r2, #1
	str r0, [r5, #0x24]
	ldr r1, _021645BC ; =ptr_FUN_overlay_0_021645c8_overlay_0_021794e8
	str r2, [r5, #0x28]
	ldr r0, _021645C0 ; =_ZN15CSoftwareSpriteD1Ev
	str r1, [r5]
	ldr r3, _021645C4 ; =FUN_02005150
	str r0, [sp]
	add r0, r5, #0x2c
	mov r1, #2
	mov r2, #0x4c
	bl __cxa_vec_ctor
	str r4, [r5, #0xc8]
	mov r1, #1
	mov r0, r5
	str r1, [r5, #0x28]
	bl ov0_02164930
	ldr r0, [r5, #0x18]
	cmp r0, #0
	beq _021645A8
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	movs r6, r0
	beq _021645A8
	mov r7, #0
	arm_func_end _ZN20CFieldEffectManpuAseC1EP16CEffectActorDataP17UnkClass_0216D420
_02164560:
	mov r0, r4
	bl _ZN17UnkClass_0216D4207AcquireEv
	add r1, r5, r7, lsl #1
	strh r0, [r1, #0xc4]
	ldrh r1, [r1, #0xc4]
	mov r0, r6
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	add r7, r7, #1
	cmp r7, #2
	blt _02164560
	mov r0, #5
	sub r4, r0, #1
_02164590:
	ldrh r1, [r5, #0xc4]
	mov r0, r6
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	cmp r4, #0
	sub r4, r4, #1
	bne _02164590
_021645A8:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_021645B0: .word _ZTV12CFieldEffect+8
_021645B4: .word _ZTV17CFieldEffectActor+8
_021645B8: .word _ZTV17CFieldEffectManpu+8
_021645BC: .word ptr_FUN_overlay_0_021645c8_overlay_0_021794e8
_021645C0: .word _ZN15CSoftwareSpriteD1Ev
_021645C4: .word _ZN15CSoftwareSpriteC1Ev

	arm_func_start _ZN20CFieldEffectManpuAseD1Ev
_ZN20CFieldEffectManpuAseD1Ev: ; 0x021645C8
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02164624 ; =ptr_FUN_overlay_0_021645c8_overlay_0_021794e8
	mov r5, r0
	str r1, [r5]
	mov r4, #0
	arm_func_end _ZN20CFieldEffectManpuAseD1Ev
_021645DC:
	add r0, r5, r4, lsl #1
	ldrh r1, [r0, #0xc4]
	cmp r1, #0
	beq _021645F4
	ldr r0, [r5, #0xc8]
	bl _ZN17UnkClass_0216D4204FreeEt
_021645F4:
	add r4, r4, #1
	cmp r4, #2
	blt _021645DC
	ldr r3, _02164628 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r5, #0x2c
	mov r1, #2
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	mov r0, r5
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02164624: .word ptr_FUN_overlay_0_021645c8_overlay_0_021794e8
_02164628: .word _ZN15CSoftwareSpriteD1Ev

	arm_func_start ov0_0216462C
ov0_0216462C: ; 0x0216462C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02164690 ; =ptr_FUN_overlay_0_021645c8_overlay_0_021794e8
	mov r5, r0
	str r1, [r5]
	mov r4, #0
	arm_func_end ov0_0216462C
_02164640:
	add r0, r5, r4, lsl #1
	ldrh r1, [r0, #0xc4]
	cmp r1, #0
	beq _02164658
	ldr r0, [r5, #0xc8]
	bl _ZN17UnkClass_0216D4204FreeEt
_02164658:
	add r4, r4, #1
	cmp r4, #2
	blt _02164640
	ldr r3, _02164694 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r5, #0x2c
	mov r1, #2
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	mov r0, r5
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r5
	bl _ZN17CFieldEffectManpudlEPv
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02164690: .word ptr_FUN_overlay_0_021645c8_overlay_0_021794e8
_02164694: .word _ZN15CSoftwareSpriteD1Ev

	arm_func_start _ZN20CFieldEffectManpuAse12ov0_02142264Ei
_ZN20CFieldEffectManpuAse12ov0_02142264Ei: ; 0x02164698
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	movs r4, r0
	cmpne r4, #4
	beq _02164704
	ldr r0, [r7, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	mov r5, r0
	mov r0, r7
	bl _ZN17CFieldEffectManpu9IsVisibleEv
	cmp r0, #0
	cmpne r5, #0
	beq _02164704
	mov r6, #0
	arm_func_end _ZN20CFieldEffectManpuAse12ov0_02142264Ei
_021646E0:
	add r0, r7, r6, lsl #1
	ldrh r1, [r0, #0xc4]
	cmp r1, #0
	beq _021646F8
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_02008A38Et
_021646F8:
	add r6, r6, #1
	cmp r6, #2
	blt _021646E0
_02164704:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN20CFieldEffectManpuAse8SetDepthEl
_ZN20CFieldEffectManpuAse8SetDepthEl: ; 0x0216470C
	mov r2, #0
	arm_func_end _ZN20CFieldEffectManpuAse8SetDepthEl
_02164710:
	add r2, r2, #1
	str r1, [r0, #0x30]
	cmp r2, #2
	add r0, r0, #0x4c
	blt _02164710
	bx lr

	arm_func_start _ZN20CFieldEffectManpuAse4DrawEP8Camera2D
_ZN20CFieldEffectManpuAse4DrawEP8Camera2D: ; 0x02164728
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x70
	mov r5, r0
	ldr r0, [r5, #0x1c]
	mov r4, r1
	cmp r0, #0
	ldrneb r0, [r5, #0x20]
	cmpne r0, #0
	addeq sp, sp, #0x70
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, [r5, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	movs r6, r0
	beq _021647A4
	mov r8, r5
	mov r7, #0
	arm_func_end _ZN20CFieldEffectManpuAse4DrawEP8Camera2D
_02164778:
	add r0, r5, r7, lsl #1
	ldrh r1, [r0, #0xc4]
	cmp r1, #0
	beq _02164794
	mov r0, r6
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r8, #0x56]
_02164794:
	add r7, r7, #1
	cmp r7, #2
	add r8, r8, #0x4c
	blt _02164778
_021647A4:
	ldr r0, [r5, #0x1c]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _021647F4
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _021647D4
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x40]
	str r1, [sp, #0x44]
	b _021647EC
_021647D4:
	mov r1, #0
	add r2, sp, #0x58
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
_021647EC:
	add r3, sp, #0x40
	b _02164810
_021647F4:
	mov r1, #0
	add r2, sp, #0x60
	add r3, sp, #0x40
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
_02164810:
	ldr r6, [r3]
	ldr r3, [r3, #4]
	ldr r2, [r0, #0x70]
	ldr r1, [r0, #0x74]
	add r2, r2, r6
	add r1, r1, r3
	ldr r0, [r0, #8]
	str r6, [sp, #0x48]
	str r3, [sp, #0x4c]
	str r2, [sp, #0x50]
	str r1, [sp, #0x54]
	str r2, [sp, #0x38]
	str r1, [sp, #0x3c]
	cmp r0, #0
	beq _02164874
	ldr r2, [r0, #0xc]
	cmp r2, #0
	moveq r2, #0
	beq _02164878
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r2, r2, r0
	b _02164878
_02164874:
	mov r2, #0
_02164878:
	ldr r0, _0216492C ; =DAT_overlay_0_02172f00
	ldr r1, [sp, #0x3c]
	ldr lr, [r0]
	ldr ip, [r0, #4]
	sub r7, r1, r2
	ldr r6, [sp, #0x38]
	add r2, r7, ip
	add r3, r6, lr
	sub r1, r6, lr
	sub r0, r7, ip
	str r3, [r5, #0x44]
	str r2, [r5, #0x48]
	str r1, [r5, #0x90]
	str r6, [sp, #0x68]
	str r7, [sp, #0x3c]
	str r7, [sp, #0x6c]
	str lr, [sp]
	str ip, [sp, #4]
	str lr, [sp, #0x30]
	str ip, [sp, #0x34]
	str r3, [sp, #0x28]
	str r2, [sp, #0x2c]
	str r3, [sp, #0x20]
	str r2, [sp, #0x24]
	str lr, [sp, #0x18]
	str ip, [sp, #0x1c]
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	str r0, [r5, #0x94]
	add r6, r5, #0x2c
	mov r5, #0
_021648FC:
	mov r0, r6
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r5, r5, #1
	cmp r5, #2
	add r6, r6, #0x4c
	blt _021648FC
	mov r0, #0
	add sp, sp, #0x70
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0216492C: .word DAT_overlay_0_02172f00

	arm_func_start ov0_02164930
ov0_02164930: ; 0x02164930
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	ldr r0, [sl, #0x18]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r8, #0
	mov sb, sl
	mov r5, r8
	mov r4, #8
	mov fp, #1
	arm_func_end ov0_02164930
_02164958:
	ldr r0, [sl, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	mov r7, r0
	ldr r0, [sl, #0x18]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r6, r0
	ldr r0, [sl, #0x18]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	str r0, [sb, #0x58]
	str r5, [sb, #0x5c]
	str r6, [sb, #0x60]
	str r7, [sb, #0x64]
	str r4, [sb, #0x3c]
	add r8, r8, #1
	strb fp, [sl, #0x20]
	add sb, sb, #0x4c
	cmp r8, #2
	blt _02164958
	mov r0, #0x1000
	rsb r0, r0, #0
	str r0, [sl, #0x98]
	mov r0, #0x1000
	str r0, [sl, #0x9c]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN25CFieldEffectManpuDokarimoC1EPN18CFieldEffectManage17CResidentResourceEP17UnkClass_0216D420ii
_ZN25CFieldEffectManpuDokarimoC1EPN18CFieldEffectManage17CResidentResourceEP17UnkClass_0216D420ii: ; 0x021649D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN22CFieldEffectManpuAnimeC2EP16CEffectActorDataP17UnkClass_0216D420i
	ldr r1, _02164A30 ; =PTR_LAB_overlay_0_02164ce4_overlay_0_02179580
	ldr r0, _02164A34 ; =0x000002AA
	str r1, [r4]
	str r0, [r4, #0x8c]
	mov r2, #0
	strb r2, [r4, #0x90]
	strb r2, [r4, #0x91]
	strb r2, [r4, #0x92]
	mov r0, #0x10
	strb r0, [r4, #0x93]
	mov r0, #1
	str r0, [r4, #0x28]
	str r2, [r4, #0x88]
	ldr r1, [sp, #8]
	mov r0, r4
	str r2, [r4, #0x84]
	bl ov0_02164A38
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02164A30: .word PTR_LAB_overlay_0_02164ce4_overlay_0_02179580
_02164A34: .word 0x000002AA
	arm_func_end _ZN25CFieldEffectManpuDokarimoC1EPN18CFieldEffectManage17CResidentResourceEP17UnkClass_0216D420ii

	arm_func_start ov0_02164A38
ov0_02164A38: ; 0x02164A38
	cmp r1, #9
	beq _02164A50
	cmp r1, #0xc
	beq _02164A64
	cmp r1, #0xd
	beq _02164A78
	arm_func_end ov0_02164A38
_02164A50:
	mov r1, #0
	strb r1, [r0, #0x91]
	mov r1, #0x10
	strb r1, [r0, #0x93]
	bx lr
_02164A64:
	mov r1, #3
	strb r1, [r0, #0x91]
	mov r1, #0x10
	strb r1, [r0, #0x93]
	bx lr
_02164A78:
	mov r1, #6
	strb r1, [r0, #0x91]
	mov r1, #8
	strb r1, [r0, #0x93]
	bx lr

	arm_func_start _ZN25CFieldEffectManpuDokarimo9UpdatePosEv
_ZN25CFieldEffectManpuDokarimo9UpdatePosEv: ; 0x02164A8C
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x54
	ldr r2, [r0, #0x1c]
	cmp r2, #0
	addeq sp, sp, #0x54
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, pc}
	ldr r3, [r0, #0x88]
	ldr r2, [r0, #0x8c]
	mla r3, r2, r1, r3
	str r3, [r0, #0x88]
	cmp r3, #0x2000
	mov r2, #0x2000
	blt _02164AD4
	str r2, [r0, #0x88]
	ldr r2, [r0, #0x8c]
	rsb r2, r2, #0
	str r2, [r0, #0x8c]
	b _02164AF0
	arm_func_end _ZN25CFieldEffectManpuDokarimo9UpdatePosEv
_02164AD4:
	rsb r2, r2, #0
	cmp r3, r2
	bgt _02164AF0
	str r2, [r0, #0x88]
	ldr r2, [r0, #0x8c]
	rsb r2, r2, #0
	str r2, [r0, #0x8c]
_02164AF0:
	ldr r2, [r0, #0x1c]
	ldr r3, [r2, #8]
	cmp r3, #0
	beq _02164B40
	ldr r3, [r3, #0xc]
	cmp r3, #0
	beq _02164B20
	ldr r4, [r3, #0x20]
	ldr r3, [r3, #0x24]
	str r4, [sp, #8]
	str r3, [sp, #0xc]
	b _02164B38
_02164B20:
	mov r3, #0
	add r4, sp, #0x20
	str r3, [r4]
	str r3, [r4, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
_02164B38:
	add r5, sp, #8
	b _02164B5C
_02164B40:
	mov r3, #0
	add r4, sp, #0x28
	add r5, sp, #8
	str r3, [r4]
	str r3, [r4, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
_02164B5C:
	ldr r6, [r5]
	ldr r5, [r5, #4]
	ldr r4, [r2, #0x70]
	ldr r3, [r2, #0x74]
	add r4, r4, r6
	add r3, r3, r5
	ldr r2, [r2, #8]
	str r6, [sp, #0x10]
	str r5, [sp, #0x14]
	str r4, [sp, #0x18]
	str r3, [sp, #0x1c]
	str r4, [sp]
	str r3, [sp, #4]
	cmp r2, #0
	beq _02164BC0
	ldr r4, [r2, #0xc]
	cmp r4, #0
	moveq r3, #0
	beq _02164BC4
	ldr r3, [r4, #0x8c]
	ldr r2, [r4, #0xa0]
	ldr r4, [r4, #0xb0]
	add r2, r3, r2
	add r3, r4, r2
	b _02164BC4
_02164BC0:
	mov r3, #0
_02164BC4:
	ldr r2, [sp, #4]
	ldr r5, [sp]
	ldr r4, [r0, #0x84]
	sub r6, r2, r3
	ldr lr, [r0, #0x88]
	add ip, r5, r4
	add r3, r6, lr
	str ip, [r0, #0x44]
	str r3, [r0, #0x48]
	ldrb r2, [r0, #0x91]
	ldrb r7, [r0, #0x92]
	str r6, [sp, #4]
	str r6, [sp, #0x4c]
	add r7, r2, r7
	and r7, r7, #0xff
	add r8, r7, #1
	str r5, [sp, #0x48]
	add sb, r2, #3
	and r8, r8, #0xff
	cmp r8, sb
	movge r8, r2
	str r4, [sp, #0x40]
	str r3, [sp, #0x3c]
	str r3, [sp, #0x34]
	ldrb r3, [r0, #0x90]
	ldr r6, _02164CE0 ; =DAT_overlay_0_02172f08
	add r5, r7, r7, lsl #1
	add r4, r8, r8, lsl #1
	str lr, [sp, #0x44]
	str ip, [sp, #0x38]
	str ip, [sp, #0x30]
	add r2, sp, #0x50
	add r7, r6, r5
	add r8, r6, r4
	mov r6, #0
_02164C50:
	ldrb r5, [r7], #1
	ldrb r4, [r8], #1
	add r6, r6, #1
	cmp r6, #3
	sub r4, r4, r5
	mul r4, r3, r4
	add r4, r5, r4, asr #4
	strb r4, [r2], #1
	blt _02164C50
	ldrb r3, [sp, #0x50]
	ldrb r2, [sp, #0x51]
	ldrb r4, [sp, #0x52]
	orr r2, r3, r2, lsl #5
	orr r2, r2, r4, lsl #10
	strh r2, [r0, #0x34]
	ldrb r2, [r0, #0x90]
	add r2, r2, r1
	strb r2, [r0, #0x90]
	ldrb r1, [r0, #0x93]
	and r2, r2, #0xff
	cmp r2, r1
	addlo sp, sp, #0x54
	ldmloia sp!, {r4, r5, r6, r7, r8, sb, pc}
	ldrb r1, [r0, #0x92]
	add r2, r1, #1
	and r1, r2, #0xff
	cmp r1, #3
	strb r2, [r0, #0x92]
	movhs r1, #0
	strcsb r1, [r0, #0x92]
	ldrb r2, [r0, #0x90]
	ldrb r1, [r0, #0x93]
	sub r1, r2, r1
	strb r1, [r0, #0x90]
	add sp, sp, #0x54
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02164CE0: .word DAT_overlay_0_02172f08

	arm_func_start _ZN25CFieldEffectManpuDokarimoD1Ev
_ZN25CFieldEffectManpuDokarimoD1Ev: ; 0x02164CE4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN22CFieldEffectManpuAnimeD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN25CFieldEffectManpuDokarimoD1Ev

	arm_func_start ov0_02164CF8
ov0_02164CF8: ; 0x02164CF8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN22CFieldEffectManpuAnimeD2Ev
	mov r0, r4
	bl _ZN17CFieldEffectManpudlEPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02164CF8

	arm_func_start _ZN28CFieldEffectDamageIndicationC1Ev
_ZN28CFieldEffectDamageIndicationC1Ev: ; 0x02164D14
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02164DA4 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _02164DA8 ; =ptr_FUN_overlay_0_021426a0_overlay_0_02179620
	ldr ip, _02164DAC ; =FUN_02003BB0
	str r0, [r4]
	ldr r3, _02164DB0 ; =FUN_02003B64
	add r0, r4, #0x18
	mov r1, #2
	mov r2, #0x40
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r1, #0
	ldr r0, _02164DB4 ; =MAIN_BSS_0210CA40
	str r1, [r4, #0xa4]
	ldr r0, [r0]
	cmp r0, #0
	ldrne r0, [r0, #0xd8]
	cmpne r0, #0
	beq _02164D8C
	mov r1, #2
	bl _ZN14CPlayerHPGauge7GetPartEi
	mov r1, r0
	mov r0, r4
	bl ov0_02165120
	arm_func_end _ZN28CFieldEffectDamageIndicationC1Ev
_02164D8C:
	mov r1, #0
	str r1, [r4, #0xa0]
	mov r0, r4
	str r1, [r4, #0x9c]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02164DA4: .word _ZTV12CFieldEffect+8
_02164DA8: .word ptr_FUN_overlay_0_021426a0_overlay_0_02179620
_02164DAC: .word _ZN14CPrimitiveRECTD1Ev
_02164DB0: .word _ZN14CPrimitiveRECTC1Ev
_02164DB4: .word MAIN_BSS_0210CA40

	arm_func_start _ZN28CFieldEffectDamageIndication12ov0_02164DB8EiiP12CFieldPlayer
_ZN28CFieldEffectDamageIndication12ov0_02164DB8EiiP12CFieldPlayer: ; 0x02164DB8
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x10
	cmp r3, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r3, r4, r5, pc}
	cmp r1, #0
	addlt sp, sp, #0x10
	str r3, [r0, #0xa4]
	ldmltia sp!, {r3, r4, r5, pc}
	cmp r1, #0x64
	addge sp, sp, #0x10
	ldmgeia sp!, {r3, r4, r5, pc}
	ldr r3, [r3, #8]
	cmp r3, #0
	beq _02164E14
	ldr r3, [r3, #0xc]
	cmp r3, #0
	bne _02164E24
	add r4, sp, #0
	mov r3, #0
	str r3, [r4]
	str r3, [r4, #4]
	b _02164E24
	arm_func_end _ZN28CFieldEffectDamageIndication12ov0_02164DB8EiiP12CFieldPlayer
_02164E14:
	add r4, sp, #8
	mov r3, #0
	str r3, [r4]
	str r3, [r4, #4]
_02164E24:
	mov r3, #0
	str r3, [r0, #0x9c]
	sub r4, r3, #0x3000
	str r4, [r0, #0xa0]
	str r3, [r0, #0xac]
	str r3, [r0, #0xa8]
	cmp r1, #0xa
	bge _02164E70
	mov r4, #1
	str r4, [r0, #0x98]
	mov r4, r1, lsl #0xf
	str r4, [r0, #0x40]
	add r1, r1, #1
	str r3, [r0, #0x44]
	mov r1, r1, lsl #0xf
	str r1, [r0, #0x48]
	mov r1, #0x10000
	str r1, [r0, #0x4c]
	b _02164ED0
_02164E70:
	ldr r4, _02164EF0 ; =0x66666667
	mov ip, r1, lsr #0x1f
	smull lr, r5, r4, r1
	add r5, ip, r5, asr #2
	mov r4, #0xa
	mul r4, r5, r4
	sub r4, r1, r4
	mov lr, #2
	add ip, r5, #1
	add r1, r4, #1
	str lr, [r0, #0x98]
	mov lr, r5, lsl #0xf
	str lr, [r0, #0x40]
	str r3, [r0, #0x44]
	mov ip, ip, lsl #0xf
	str ip, [r0, #0x48]
	mov ip, #0x10000
	str ip, [r0, #0x4c]
	mov r4, r4, lsl #0xf
	str r4, [r0, #0x80]
	str r3, [r0, #0x84]
	mov r1, r1, lsl #0xf
	str r1, [r0, #0x88]
	str ip, [r0, #0x8c]
_02164ED0:
	ldr r4, [r0]
	sub r2, r2, #0xf
	ldr r4, [r4, #0x1c]
	mov r1, #0xf
	mov r3, #0
	blx r4
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02164EF0: .word 0x66666667

	arm_func_start ov0_02164EF4
ov0_02164EF4: ; 0x02164EF4
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x48
	mov r5, r0
	mov r4, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	cmp r0, #4
	cmpne r0, #0
	moveq r1, #0
	addeq sp, sp, #0x48
	streq r1, [r5, #0x98]
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r1, [r5, #0xa4]
	cmp r1, #0
	addeq sp, sp, #0x48
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r2, [r1, #8]
	cmp r2, #0
	beq _02164F7C
	ldr r2, [r2, #0xc]
	cmp r2, #0
	beq _02164F5C
	ldr r3, [r2, #0x20]
	ldr r2, [r2, #0x24]
	str r3, [sp, #0x18]
	str r2, [sp, #0x1c]
	b _02164F74
	arm_func_end ov0_02164EF4
_02164F5C:
	mov r2, #0
	add r3, sp, #0x30
	str r2, [r3]
	str r2, [r3, #4]
	str r2, [sp, #0x18]
	str r2, [sp, #0x1c]
_02164F74:
	add ip, sp, #0x18
	b _02164F98
_02164F7C:
	mov r2, #0
	add r3, sp, #0x38
	add ip, sp, #0x18
	str r2, [r3]
	str r2, [r3, #4]
	str r2, [sp, #0x18]
	str r2, [sp, #0x1c]
_02164F98:
	ldr lr, [ip]
	ldr ip, [ip, #4]
	ldr r3, [r1, #0x70]
	ldr r2, [r1, #0x74]
	add r3, r3, lr
	add r2, r2, ip
	ldr r1, [r1, #8]
	str lr, [sp, #0x20]
	str ip, [sp, #0x24]
	str r3, [sp, #0x28]
	str r2, [sp, #0x2c]
	str r3, [sp, #0x10]
	str r2, [sp, #0x14]
	cmp r1, #0
	beq _02164FFC
	ldr r3, [r1, #0xc]
	cmp r3, #0
	moveq r2, #0
	beq _02165000
	ldr r2, [r3, #0x8c]
	ldr r1, [r3, #0xa0]
	ldr r3, [r3, #0xb0]
	add r1, r2, r1
	add r2, r3, r1
	b _02165000
_02164FFC:
	mov r2, #0
_02165000:
	ldr r1, [sp, #0x14]
	ldr ip, [sp, #0x10]
	sub lr, r1, r2
	ldr r3, [r5, #0xa8]
	ldr r2, [r5, #0xac]
	ldr r1, [r5, #0x98]
	add r3, ip, r3
	cmp r1, #1
	add r2, lr, r2
	streq r3, [r5, #0x30]
	str lr, [sp, #0x14]
	str ip, [sp, #0x40]
	str lr, [sp, #0x44]
	streq r2, [r5, #0x34]
	beq _0216505C
	cmp r1, #2
	bne _0216505C
	sub r1, r3, #0x4000
	str r1, [r5, #0x30]
	str r2, [r5, #0x34]
	add r1, r3, #0x4000
	str r1, [r5, #0x70]
	str r2, [r5, #0x74]
_0216505C:
	cmp r0, #1
	addne sp, sp, #0x48
	ldmneia sp!, {r3, r4, r5, pc}
	ldr r1, [r5, #0x9c]
	mov lr, r4, lsl #0xc
	smull ip, r3, r1, lr
	ldr r2, [r5, #0xa0]
	mov r1, ip, lsr #0xc
	orr r1, r1, r3, lsl #20
	smull ip, r3, r2, lr
	ldr r2, [r5, #0xa8]
	mov ip, ip, lsr #0xc
	orr ip, ip, r3, lsl #20
	add r2, r2, r1
	str r2, [r5, #0xa8]
	ldr r3, [r5, #0xac]
	ldr r2, _021650CC ; =0x000006DB
	add r3, r3, ip
	str r3, [r5, #0xac]
	ldr r3, [r5, #0xa0]
	str r1, [sp, #8]
	mla r2, r4, r2, r3
	str ip, [sp, #0xc]
	str r1, [sp]
	str ip, [sp, #4]
	str r2, [r5, #0xa0]
	add sp, sp, #0x48
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021650CC: .word 0x000006DB

	arm_func_start ov0_021650D0
ov0_021650D0: ; 0x021650D0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldr r0, [r7, #0x98]
	mov r6, r1
	cmp r0, #0
	mov r4, #0
	ble _02165118
	add r5, r7, #0x18
	arm_func_end ov0_021650D0
_021650F0:
	mov r0, r5
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	ldr r0, [r7, #0x98]
	add r4, r4, #1
	cmp r4, r0
	add r5, r5, #0x40
	blt _021650F0
_02165118:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov0_02165120
ov0_02165120: ; 0x02165120
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, #0
	mov r4, #0x1f
	mov lr, #0x11
	mov ip, #8
	mov r3, #0x8000
	mov r2, #0x10000
	arm_func_end ov0_02165120
_0216513C:
	ldr r5, [r1]
	add r6, r0, r7, lsl #6
	str r5, [r6, #0x50]
	ldr r5, [r1, #4]
	add r7, r7, #1
	str r5, [r6, #0x54]
	strh r4, [r6, #0x20]
	str lr, [r6, #0x1c]
	str ip, [r6, #0x28]
	str r3, [r6, #0x38]
	str r2, [r6, #0x3c]
	cmp r7, #2
	blt _0216513C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov0_02165174
ov0_02165174: ; 0x02165174
	mov r0, #0x24
	bx lr
	arm_func_end ov0_02165174

	arm_func_start ov0_0216517C
ov0_0216517C: ; 0x0216517C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _021651C0 ; =FUN_02003BB0
	add r0, r4, #0x18
	mov r1, #2
	mov r2, #0x40
	bl __cxa_vec_cleanup
	ldr r1, _021651C4 ; =_ZTV12CFieldEffect+8
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
_021651C0: .word _ZN14CPrimitiveRECTD1Ev
_021651C4: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_0216517C

	arm_func_start ov0_021651C8
ov0_021651C8: ; 0x021651C8
	stmdb sp!, {r4, lr}
	ldr r1, _02165214 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _02165218 ; =ptr_FUN_overlay_0_0216521c_overlay_0_021796ec
	mov r1, #0
	str r0, [r4]
	strb r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	add r0, r4, #0x24
	str r1, [r4, #0x20]
	bl _ZN15CSoftwareSpriteC1Ev
	mov r1, #0
	mov r0, r4
	strh r1, [r4, #0x70]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02165214: .word _ZTV12CFieldEffect+8
_02165218: .word ptr_FUN_overlay_0_0216521c_overlay_0_021796ec
	arm_func_end ov0_021651C8

	arm_func_start _ZN16CFieldEffectBushD1Ev
_ZN16CFieldEffectBushD1Ev: ; 0x0216521C
	stmdb sp!, {r4, lr}
	ldr r1, _02165260 ; =ptr_FUN_overlay_0_0216521c_overlay_0_021796ec
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	add r0, r4, #0x24
	bl _ZN15CSoftwareSpriteD1Ev
	ldr r1, _02165264 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02165260: .word ptr_FUN_overlay_0_0216521c_overlay_0_021796ec
_02165264: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN16CFieldEffectBushD1Ev

	arm_func_start ov0_02165268
ov0_02165268: ; 0x02165268
	stmdb sp!, {r4, lr}
	ldr r1, _021652B4 ; =ptr_FUN_overlay_0_0216521c_overlay_0_021796ec
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	add r0, r4, #0x24
	bl _ZN15CSoftwareSpriteD1Ev
	ldr r1, _021652B8 ; =_ZTV12CFieldEffect+8
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
_021652B4: .word ptr_FUN_overlay_0_0216521c_overlay_0_021796ec
_021652B8: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_02165268

	arm_func_start thunk_FUN_overlay_0__02165410
thunk_FUN_overlay_0__02165410: ; 0x021652BC
	ldr ip, _021652C4 ; =ov0_02165410
	bx ip
	.align 2, 0
_021652C4: .word ov0_02165410
	arm_func_end thunk_FUN_overlay_0__02165410

	arm_func_start ov0_021652C8
ov0_021652C8: ; 0x021652C8
	str r1, [r0, #0x50]
	mov r1, #0
	str r1, [r0, #0x54]
	str r2, [r0, #0x58]
	bx lr
	arm_func_end ov0_021652C8

	arm_func_start ov0_021652DC
ov0_021652DC: ; 0x021652DC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r2
	str r1, [r5, #0x1c]
	cmp r1, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldrb r0, [r1, #0xd4]
	cmp r0, #4
	addls pc, pc, r0, lsl #2
	b _02165318
_02165304: ; jump table
	b _02165318 ; case 0
	b _02165324 ; case 1
	b _02165330 ; case 2
	b _0216533C ; case 3
	b _02165348 ; case 4
_02165318:
	mvn r0, #0
	strb r0, [r5, #0x72]
	b _02165350
	arm_func_end ov0_021652DC
_02165324:
	mov r0, #1
	strb r0, [r5, #0x72]
	b _02165350
_02165330:
	mov r0, #3
	strb r0, [r5, #0x72]
	b _02165350
_0216533C:
	mov r0, #4
	strb r0, [r5, #0x72]
	b _02165350
_02165348:
	mov r0, #2
	strb r0, [r5, #0x72]
_02165350:
	ldrsb r0, [r5, #0x72]
	cmp r0, #0
	blt _021653E8
	ldr r1, [r5, #0x1c]
	mov r0, r5
	bl ov0_02165578
	cmp r0, #0
	beq _021653E8
	add r0, r4, #0x27c
	add r0, r0, #0x400
	ldr r2, [r0]
	ldrsb r1, [r5, #0x72]
	ldr r2, [r2, #0xc]
	blx r2
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x20]
	cmp r0, #0
	ldrneh r1, [r5, #0x70]
	cmpne r1, #0
	beq _021653B0
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	mov r0, #0
	strh r0, [r5, #0x70]
	str r0, [r5, #0x20]
_021653B0:
	add r0, r4, #0x27c
	add r0, r0, #0x400
	ldr r2, [r0]
	ldrsb r1, [r5, #0x72]
	ldr r2, [r2, #0x10]
	blx r2
	str r0, [r5, #0x20]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	strh r0, [r5, #0x70]
	ldmia sp!, {r3, r4, r5, pc}
_021653E8:
	ldr r0, [r5, #0x1c]
	bl _ZN11CFieldActor12sub_0203DA10Ev
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov0_021653F4
ov0_021653F4: ; 0x021653F4
	mov r1, #0
	strh r1, [r0, #0x4e]
	sub r1, r1, #1
	strb r1, [r0, #0x72]
	mov r1, #1
	strb r1, [r0, #0x18]
	bx lr
	arm_func_end ov0_021653F4

	arm_func_start ov0_02165410
ov0_02165410: ; 0x02165410
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r0, #0
	strb r0, [r4, #0x18]
	ldr r0, [r4, #0x20]
	cmp r0, #0
	ldrneh r1, [r4, #0x70]
	cmpne r1, #0
	beq _02165444
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	mov r0, #0
	strh r0, [r4, #0x70]
	str r0, [r4, #0x20]
	arm_func_end ov0_02165410
_02165444:
	ldr r2, [r4, #0x1c]
	cmp r2, #0
	ldmeqia sp!, {r4, pc}
	mov r1, #0
	strh r1, [r2, #0xd8]
	ldrb r0, [r2, #0xd4]
	cmp r0, #0
	beq _02165488
	ldr r0, [r2, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	ldrne r0, [r0, #0xc4]
	cmpne r0, #0
	strne r1, [r0, #0x48]
	mov r0, #1
	str r0, [r2, #0x90]
_02165488:
	mov r0, #0
	str r0, [r4, #0x1c]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN16CFieldEffectBush12ov0_02142344EP8Camera2D
_ZN16CFieldEffectBush12ov0_02142344EP8Camera2D: ; 0x02165494
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	beq _02165570
	bl ov0_02165578
	cmp r0, #0
	bne _021654C8
	ldr r0, [r5, #0x1c]
	bl _ZN11CFieldActor12sub_0203DA10Ev
	mvn r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN16CFieldEffectBush12ov0_02142344EP8Camera2D
_021654C8:
	ldr r0, [r5, #0x20]
	cmp r0, #0
	ldrneh r1, [r5, #0x70]
	cmpne r1, #0
	beq _021654E4
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r5, #0x4e]
_021654E4:
	ldr r1, [r5, #0x1c]
	ldrsh r0, [r1, #0xd6]
	ldr r2, [r1, #8]
	cmp r2, #0
	add r1, r0, #8
	beq _02165510
	ldr r0, [r2, #0xc]
	cmp r0, #0
	ldrne r3, [r0, #0x20]
	moveq r3, #0
	b _02165514
_02165510:
	mov r3, #0
_02165514:
	cmp r2, #0
	beq _02165530
	ldr r0, [r2, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	b _02165534
_02165530:
	mov r0, #0
_02165534:
	add r0, r0, r1, lsl #12
	str r3, [r5, #0x3c]
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x1c]
	mov r1, r4
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0x10]
	moveq r0, #0x4000
	rsbeq r0, r0, #0
	str r0, [r5, #0x28]
	add r0, r5, #0x24
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
_02165570:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov0_02165578
ov0_02165578: ; 0x02165578
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x10
	ldrb r2, [r1, #0x20]
	mov ip, #0
	mov r3, #1
	cmp r2, #2
	cmpne r2, #3
	movne r3, ip
	cmp r3, #0
	beq _021655B8
	ldr r2, [r1, #4]
	tst r2, #1
	movne r2, #1
	moveq r2, #0
	cmp r2, #0
	beq _021655C4
	arm_func_end ov0_02165578
_021655B8:
	add sp, sp, #0x10
	mov r0, #0
	ldmia sp!, {r3, pc}
_021655C4:
	ldrsb r3, [r0, #0x72]
	ldr r2, _021656B4 ; =MAIN_BSS_0210CA40
	cmp r3, #0
	ldr r2, [r2]
	blt _021656A8
	cmp r2, #0
	ldrne r3, [r2, #8]
	cmpne r3, #0
	beq _021656A8
	ldr r2, [r1, #8]
	cmp r2, #0
	beq _02165608
	ldr r2, [r2, #0xc]
	cmp r2, #0
	ldrne r2, [r2, #0x20]
	moveq r2, #0
	b _0216560C
_02165608:
	mov r2, #0
_0216560C:
	str r2, [sp]
	ldr r2, [r1, #8]
	cmp r2, #0
	beq _02165630
	ldr r2, [r2, #0xc]
	cmp r2, #0
	ldrne ip, [r2, #0x24]
	moveq ip, #0
	b _02165634
_02165630:
	mov ip, #0
_02165634:
	ldrsh r2, [r1, #0xd6]
	mov r1, #0x10000
	add r2, r2, #8
	add r2, ip, r2, lsl #12
	str r2, [sp, #4]
	str r1, [sp, #0xc]
	ldrsb r0, [r0, #0x72]
	cmp r0, #4
	addls pc, pc, r0, lsl #2
	b _02165694
_0216565C: ; jump table
	b _02165694 ; case 0
	b _02165670 ; case 1
	b _02165690 ; case 2
	b _02165678 ; case 3
	b _02165684 ; case 4
_02165670:
	str r1, [sp, #8]
	b _02165694
_02165678:
	mov r0, #0x20000
	str r0, [sp, #8]
	b _02165694
_02165684:
	mov r0, #0x30000
	str r0, [sp, #8]
	b _02165694
_02165690:
	str r1, [sp, #8]
_02165694:
	ldr r2, _021656B8 ; =0x00001199
	add r1, sp, #0
	mov r0, r3
	bl _ZN8Camera2D12sub_020038A8EP9Rectanglel
	mov ip, r0
_021656A8:
	mov r0, ip
	add sp, sp, #0x10
	ldmia sp!, {r3, pc}
	.align 2, 0
_021656B4: .word MAIN_BSS_0210CA40
_021656B8: .word 0x00001199

	arm_func_start _ZN23CFieldEffectBushFactoryC1EP18CFieldEffectManage
_ZN23CFieldEffectBushFactoryC1EP18CFieldEffectManage: ; 0x021656BC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #4
	ldr r2, _02165760 ; =ptr_FUN_overlay_0_02151848_overlay_0_021796cc
	mov r8, r0
	mov r5, r1
	ldr r4, _02165764 ; =_ZN16CFieldEffectBushD1Ev
	str r2, [r8]
	ldr r3, _02165768 ; =ov0_021651C8
	add r0, r8, #4
	mov r1, #0x10
	mov r2, #0x74
	str r4, [sp]
	bl __cxa_vec_ctor
	cmp r5, #0
	beq _02165754
	mov r6, #0
	mov r7, r6
	add sb, r5, #0x27c
	add sl, r8, #4
	mov r4, r6
	arm_func_end _ZN23CFieldEffectBushFactoryC1EP18CFieldEffectManage
_0216570C:
	add r0, sb, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r5, r0
	add r0, sb, #0x400
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r2, r5
	mov r1, r0
	add r0, sl, r7
	bl ov0_021652C8
	add r7, r7, #0x74
	add r6, r6, #1
	cmp r6, #0x10
	blt _0216570C
_02165754:
	mov r0, r8
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02165760: .word ptr_FUN_overlay_0_02151848_overlay_0_021796cc
_02165764: .word _ZN16CFieldEffectBushD1Ev
_02165768: .word ov0_021651C8

	arm_func_start _ZN23CFieldEffectBushFactory6CreateEi
_ZN23CFieldEffectBushFactory6CreateEi: ; 0x0216576C
	stmdb sp!, {r4, lr}
	mov r4, #0
	mov r2, r4
	mov r3, r0
	arm_func_end _ZN23CFieldEffectBushFactory6CreateEi
_0216577C:
	ldrb r1, [r3, #0x1c]
	cmp r1, #0
	bne _021657A0
	add r1, r0, #4
	mov r0, #0x74
	mla r4, r2, r0, r1
	mov r0, r4
	bl ov0_021653F4
	b _021657B0
_021657A0:
	add r2, r2, #1
	cmp r2, #0x10
	add r3, r3, #0x74
	blt _0216577C
_021657B0:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN16CFieldEffectBush12sub_02033028Ev
_ZN16CFieldEffectBush12sub_02033028Ev: ; 0x021657B8
	mov r0, #0x25
	bx lr
	arm_func_end _ZN16CFieldEffectBush12sub_02033028Ev

	arm_func_start ov0_021657C0
ov0_021657C0: ; 0x021657C0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _021657EC ; =_ZN16CFieldEffectBushD1Ev
	add r0, r4, #4
	mov r1, #0x10
	mov r2, #0x74
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021657EC: .word _ZN16CFieldEffectBushD1Ev
	arm_func_end ov0_021657C0

	arm_func_start ov0_021657F0
ov0_021657F0: ; 0x021657F0
	stmdb sp!, {r4, lr}
	ldr r1, _02165858 ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _0216585C ; =ptr_FUN_overlay_0_0216586c_overlay_0_02179818
	mov r1, #0
	str r0, [r4]
	strb r1, [r4, #0x18]
	add r0, r4, #0x20
	str r1, [r4, #0x1c]
	bl _ZN15CSoftwareSpriteC1Ev
	mov r1, #0
	ldr r0, _02165860 ; =_ZTV11CDrawObject+8
	strh r1, [r4, #0x6c]
	str r0, [r4, #0x70]
	ldr r0, _02165864 ; =PTR_LAB_overlay_0_02165868_overlay_0_02179774
	str r1, [r4, #0x74]
	str r0, [r4, #0x70]
	str r1, [r4, #0x7c]
	sub r1, r1, #1
	mov r0, r4
	str r1, [r4, #0x24]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02165858: .word _ZTV12CFieldEffect+8
_0216585C: .word ptr_FUN_overlay_0_0216586c_overlay_0_02179818
_02165860: .word _ZTV11CDrawObject+8
_02165864: .word PTR_LAB_overlay_0_02165868_overlay_0_02179774
	arm_func_end ov0_021657F0

	arm_func_start _ZN23CFieldEffectWaterSplash17CEffectDrawObjectD1Ev
_ZN23CFieldEffectWaterSplash17CEffectDrawObjectD1Ev: ; 0x02165868
	bx lr
	arm_func_end _ZN23CFieldEffectWaterSplash17CEffectDrawObjectD1Ev

	arm_func_start _ZN23CFieldEffectWaterSplashD1Ev
_ZN23CFieldEffectWaterSplashD1Ev: ; 0x0216586C
	stmdb sp!, {r4, lr}
	ldr r1, _021658B0 ; =ptr_FUN_overlay_0_0216586c_overlay_0_02179818
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	add r0, r4, #0x20
	bl _ZN15CSoftwareSpriteD1Ev
	ldr r1, _021658B4 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021658B0: .word ptr_FUN_overlay_0_0216586c_overlay_0_02179818
_021658B4: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN23CFieldEffectWaterSplashD1Ev

	arm_func_start ov0_021658B8
ov0_021658B8: ; 0x021658B8
	stmdb sp!, {r4, lr}
	ldr r1, _02165904 ; =ptr_FUN_overlay_0_0216586c_overlay_0_02179818
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	add r0, r4, #0x20
	bl _ZN15CSoftwareSpriteD1Ev
	ldr r1, _02165908 ; =_ZTV12CFieldEffect+8
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
_02165904: .word ptr_FUN_overlay_0_0216586c_overlay_0_02179818
_02165908: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_021658B8

	arm_func_start thunk_FUN_overlay_0__0216596c
thunk_FUN_overlay_0__0216596c: ; 0x0216590C
	ldr ip, _02165914 ; =ov0_0216596C
	bx ip
	.align 2, 0
_02165914: .word ov0_0216596C
	arm_func_end thunk_FUN_overlay_0__0216596c

	arm_func_start ov0_02165918
ov0_02165918: ; 0x02165918
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r1, [r4, #0x4c]
	mov r1, #0
	str r1, [r4, #0x50]
	ldr r0, [sp, #8]
	str r2, [r4, #0x54]
	str r3, [r4, #0x58]
	str r0, [r4, #0x1c]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r2, r1
	mov r1, #1
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	strh r0, [r4, #0x6c]
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02165918

	arm_func_start ov0_02165958
ov0_02165958: ; 0x02165958
	mov r1, #0
	strh r1, [r0, #0x4a]
	mov r1, #1
	strb r1, [r0, #0x18]
	bx lr
	arm_func_end ov0_02165958

	arm_func_start ov0_0216596C
ov0_0216596C: ; 0x0216596C
	mov r1, #0
	strb r1, [r0, #0x18]
	bx lr
	arm_func_end ov0_0216596C

	arm_func_start _ZN23CFieldEffectWaterSplash12sub_0203312CEii
_ZN23CFieldEffectWaterSplash12sub_0203312CEii: ; 0x02165978
	cmp r1, #1
	mov r3, #1
	beq _02165990
	cmp r1, #2
	beq _0216599C
	b _021659AC
	arm_func_end _ZN23CFieldEffectWaterSplash12sub_0203312CEii
_02165990:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x38]
	b _021659B0
_0216599C:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x3c]
	str r1, [r0, #0x74]
	b _021659B0
_021659AC:
	mov r3, #0
_021659B0:
	mov r0, r3
	bx lr

	arm_func_start _ZN23CFieldEffectWaterSplash12ov0_021421F0Eiii
_ZN23CFieldEffectWaterSplash12ov0_021421F0Eiii: ; 0x021659B8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldr r0, [r7, #0x1c]
	mov r6, r1
	cmp r0, #0
	ldrneh r1, [r7, #0x6c]
	mov r5, r2
	mov r4, r3
	cmpne r1, #0
	beq _021659E4
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	arm_func_end _ZN23CFieldEffectWaterSplash12ov0_021421F0Eiii
_021659E4:
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN23CFieldEffectWaterSplash12ov0_02142264Ei
_ZN23CFieldEffectWaterSplash12ov0_02142264Ei: ; 0x021659FC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	bl _ZN12CFieldEffect12ov0_02142264Ei
	movs r4, r0
	cmpne r4, #4
	ldrne r0, [r5, #0x1c]
	cmpne r0, #0
	ldrneh r1, [r5, #0x6c]
	cmpne r1, #0
	beq _02165A50
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	ldrh r1, [r5, #0x6c]
	ldr r0, [r5, #0x1c]
	bl _ZN17UnkClass_0200878812sub_02008860Et
	cmp r0, #0
	bne _02165A50
	mov r0, r5
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x20]
	blx r2
	arm_func_end _ZN23CFieldEffectWaterSplash12ov0_02142264Ei
_02165A50:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN23CFieldEffectWaterSplash12ov0_02142344EP8Camera2D
_ZN23CFieldEffectWaterSplash12ov0_02142344EP8Camera2D: ; 0x02165A58
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x1c]
	mov r4, r1
	cmp r0, #0
	ldrneh r1, [r5, #0x6c]
	cmpne r1, #0
	beq _02165A80
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r5, #0x4a]
	arm_func_end _ZN23CFieldEffectWaterSplash12ov0_02142344EP8Camera2D
_02165A80:
	ldr r1, [r5, #0x7c]
	add r0, r5, #0x20
	str r1, [r5, #0x24]
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN23CFieldEffectWaterSplash12ov0_02142398EP17UnkClass_0211E3FC
_ZN23CFieldEffectWaterSplash12ov0_02142398EP17UnkClass_0211E3FC: ; 0x02165AA4
	ldr ip, _02165AB8 ; =FUN_0200912C
	mov r2, r0
	mov r0, r1
	add r1, r2, #0x70
	bx ip
	.align 2, 0
_02165AB8: .word _ZN17UnkClass_0211E3FC12sub_0200912CEP11CDrawObject
	arm_func_end _ZN23CFieldEffectWaterSplash12ov0_02142398EP17UnkClass_0211E3FC

	arm_func_start _ZN23CFieldEffectWaterSplash17CEffectDrawObject12sub_020091D4EP8Camera2Di
_ZN23CFieldEffectWaterSplash17CEffectDrawObject12sub_020091D4EP8Camera2Di: ; 0x02165ABC
	str r2, [r0, #0xc]
	mov r0, #0xa
	bx lr
	arm_func_end _ZN23CFieldEffectWaterSplash17CEffectDrawObject12sub_020091D4EP8Camera2Di

	arm_func_start _ZN30CFieldEffectWaterSplashFactoryC1EP18CFieldEffectManage
_ZN30CFieldEffectWaterSplashFactoryC1EP18CFieldEffectManage: ; 0x02165AC8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr r2, _02165B98 ; =PTR_LAB_overlay_0_02151870_overlay_0_021797a4
	mov fp, r0
	mov r5, r1
	ldr r4, _02165B9C ; =_ZN23CFieldEffectWaterSplashD1Ev
	str r2, [fp]
	ldr r3, _02165BA0 ; =ov0_021657F0
	add r0, fp, #4
	mov r1, #0x10
	mov r2, #0x80
	str r4, [sp]
	bl __cxa_vec_ctor
	cmp r5, #0
	beq _02165B90
	mov sb, #0
	add r4, r5, #0x27c
	mov sl, sb
	add r5, fp, #4
	arm_func_end _ZN30CFieldEffectWaterSplashFactoryC1EP18CFieldEffectManage
_02165B10:
	add r0, r4, #0x400
	ldr r2, [r0]
	mov r1, #8
	ldr r2, [r2, #0x10]
	blx r2
	mov r8, r0
	add r0, r4, #0x400
	ldr r2, [r0]
	mov r1, #8
	ldr r2, [r2, #0xc]
	blx r2
	mov r7, r0
	add r0, r4, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r6, r0
	add r0, r4, #0x400
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	mov r1, r0
	mov r2, r6
	mov r3, r7
	add r0, r5, sl
	str r8, [sp]
	bl ov0_02165918
	add sb, sb, #1
	add sl, sl, #0x80
	cmp sb, #0x10
	blt _02165B10
_02165B90:
	mov r0, fp
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02165B98: .word PTR_LAB_overlay_0_02151870_overlay_0_021797a4
_02165B9C: .word _ZN23CFieldEffectWaterSplashD1Ev
_02165BA0: .word ov0_021657F0

	arm_func_start _ZN30CFieldEffectWaterSplashFactory6CreateEi
_ZN30CFieldEffectWaterSplashFactory6CreateEi: ; 0x02165BA4
	stmdb sp!, {r4, lr}
	mov r4, #0
	mov r2, r4
	arm_func_end _ZN30CFieldEffectWaterSplashFactory6CreateEi
_02165BB0:
	add r1, r0, r2, lsl #7
	ldrb r1, [r1, #0x1c]
	cmp r1, #0
	bne _02165BD4
	add r0, r0, #4
	add r4, r0, r2, lsl #7
	mov r0, r4
	bl ov0_02165958
	b _02165BE0
_02165BD4:
	add r2, r2, #1
	cmp r2, #0x10
	blt _02165BB0
_02165BE0:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN23CFieldEffectWaterSplash12sub_02033028Ev
_ZN23CFieldEffectWaterSplash12sub_02033028Ev: ; 0x02165BE8
	mov r0, #0x26
	bx lr
	arm_func_end _ZN23CFieldEffectWaterSplash12sub_02033028Ev

	arm_func_start ov0_02165BF0
ov0_02165BF0: ; 0x02165BF0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02165BF0

	arm_func_start ov0_02165C04
ov0_02165C04: ; 0x02165C04
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02165C30 ; =_ZN23CFieldEffectWaterSplashD1Ev
	add r0, r4, #4
	mov r1, #0x10
	mov r2, #0x80
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02165C30: .word _ZN23CFieldEffectWaterSplashD1Ev
	arm_func_end ov0_02165C04

	arm_func_start _ZN24CFieldEffectManpuGokigenC1EP16CEffectActorData
_ZN24CFieldEffectManpuGokigenC1EP16CEffectActorData: ; 0x02165C34
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r2, _02165E88 ; =_ZTV12CFieldEffect+8
	mov r5, r0
	str r2, [r5]
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _02165E8C ; =_ZTV17CFieldEffectActor+8
	mov r1, #0
	str r0, [r5]
	ldr r0, _02165E90 ; =_ZTV17CFieldEffectManpu+8
	str r4, [r5, #0x18]
	str r0, [r5]
	str r1, [r5, #0x1c]
	strb r1, [r5, #0x20]
	sub r0, r1, #1
	str r0, [r5, #0x24]
	ldr r0, _02165E94 ; =ptr_FUN_overlay_0_02165eb4_overlay_0_0217993c
	str r1, [r5, #0x28]
	str r0, [r5]
	mov r0, #0x1000
	str r0, [r5, #0x34]
	mov r0, #1
	str r0, [r5, #0x40]
	str r1, [r5, #0x44]
	str r1, [r5, #0x48]
	str r1, [r5, #0x4c]
	str r1, [r5, #0x50]
	mov r0, #3
	str r0, [r5, #0x58]
	str r1, [r5, #0x5c]
	ldr r0, [r5, #0x58]
	cmp r0, #0
	beq _02165D54
	ldr r1, _02165E98 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _02165E9C ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	mov ip, #0
	mov r0, ip
	cmp r1, #0
	bls _02165D48
	mov r1, ip
	mov r7, ip
	mov r2, #0x74
	arm_func_end _ZN24CFieldEffectManpuGokigenC1EP16CEffectActorData
_02165CFC:
	ldr r3, [r5, #0x54]
	add r6, r0, #1
	add r3, r3, r1
	str ip, [r3, #0x6c]
	ldr r3, [r5, #0x58]
	add r0, r0, #1
	cmp r6, r3
	ldrlo r3, [r5, #0x54]
	mlalo ip, r6, r2, r3
	ldr r3, [r5, #0x54]
	movhs ip, r7
	add r3, r3, r1
	str ip, [r3, #0x70]
	ldr r6, [r5, #0x54]
	ldr r3, [r5, #0x58]
	add ip, r6, r1
	cmp r0, r3
	add r1, r1, #0x74
	blo _02165CFC
_02165D48:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x60]
	b _02165D5C
_02165D54:
	str r1, [r5, #0x54]
	str r1, [r5, #0x60]
_02165D5C:
	mov r1, #0
	str r1, [r5, #0x64]
	ldr r0, [r5, #0x40]
	cmp r0, #0
	streq r1, [r5, #0x38]
	streq r1, [r5, #0x3c]
	beq _02165DA4
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r5, #0x38]
	ldr r1, [r5, #0x40]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r5, #0x40]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r5, #0x3c]
_02165DA4:
	mov r3, #0
	str r3, [r5, #0x30]
	ldr r0, _02165EA0 ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r3, [r5, #0x2c]
	str r0, [r5, #0x68]
	add r2, r5, #0x68
	str r3, [r2, #0x14]
	str r3, [r2, #4]
	str r3, [r2, #8]
	str r3, [r2, #0xc]
	mov r1, #0x1000
	ldr r0, _02165EA4 ; =PTR_LAB_overlay_0_02165eac_overlay_0_021798d0
	str r1, [r2, #0x10]
	str r0, [r5, #0x68]
	str r3, [r2, #0x18]
	mov r0, #0x14
	str r0, [r2, #0x1c]
	str r3, [r2, #0x20]
	ldr r0, _02165EA8 ; =PTR_LAB_overlay_0_02165eb0_overlay_0_021798a0
	strb r3, [r2, #0x24]
	str r0, [r5, #0x90]
	str r3, [r5, #0x94]
	str r3, [r5, #0x98]
	str r3, [r5, #0x9c]
	mov r0, #1
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x40]
	cmp r0, #0
	bls _02165E24
	ldr r0, [r5, #0x38]
	cmp r0, #0
	strne r2, [r0]
_02165E24:
	add r1, r5, #0x90
	mov r0, r4
	str r1, [r5, #0x50]
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	mov r7, r0
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r6, r0
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	str r0, [r5, #0x44]
	str r6, [r5, #0x48]
	str r7, [r5, #0x4c]
	mov r1, #0x1e
	mov r0, r5
	str r1, [r5, #0x84]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02165E88: .word _ZTV12CFieldEffect+8
_02165E8C: .word _ZTV17CFieldEffectActor+8
_02165E90: .word _ZTV17CFieldEffectManpu+8
_02165E94: .word ptr_FUN_overlay_0_02165eb4_overlay_0_0217993c
_02165E98: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_02165E9C: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
_02165EA0: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_02165EA4: .word PTR_LAB_overlay_0_02165eac_overlay_0_021798d0
_02165EA8: .word PTR_LAB_overlay_0_02165eb0_overlay_0_021798a0

	arm_func_start _ZN24CFieldEffectManpuGokigen8CEmitterD1Ev
_ZN24CFieldEffectManpuGokigen8CEmitterD1Ev: ; 0x02165EAC
	bx lr
	arm_func_end _ZN24CFieldEffectManpuGokigen8CEmitterD1Ev

	arm_func_start _ZN24CFieldEffectManpuGokigen9CAnimatorD1Ev
_ZN24CFieldEffectManpuGokigen9CAnimatorD1Ev: ; 0x02165EB0
	bx lr
	arm_func_end _ZN24CFieldEffectManpuGokigen9CAnimatorD1Ev

	arm_func_start _ZN24CFieldEffectManpuGokigenD1Ev
_ZN24CFieldEffectManpuGokigenD1Ev: ; 0x02165EB4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq _02165ED4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x3c]
	arm_func_end _ZN24CFieldEffectManpuGokigenD1Ev
_02165ED4:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _02165EEC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x38]
_02165EEC:
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq _02165F10
	ldr r3, _02165F20 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x54]
_02165F10:
	mov r0, r4
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02165F20: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev

	arm_func_start ov0_02165F24
ov0_02165F24: ; 0x02165F24
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq _02165F44
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x3c]
	arm_func_end ov0_02165F24
_02165F44:
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _02165F5C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x38]
_02165F5C:
	ldr r0, [r4, #0x54]
	cmp r0, #0
	beq _02165F80
	ldr r3, _02165F98 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x54]
_02165F80:
	mov r0, r4
	bl _ZN17CFieldEffectManpuD2Ev
	mov r0, r4
	bl _ZN17CFieldEffectManpudlEPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02165F98: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev

	arm_func_start _ZN24CFieldEffectManpuGokigen7SetTypeEi
_ZN24CFieldEffectManpuGokigen7SetTypeEi: ; 0x02165F9C
	cmp r1, #0xb
	moveq r2, #0x1e
	str r1, [r0, #0x94]
	movne r2, #0x3c
	str r2, [r0, #0x84]
	str r1, [r0, #0x24]
	bx lr
	arm_func_end _ZN24CFieldEffectManpuGokigen7SetTypeEi

	arm_func_start _ZN24CFieldEffectManpuGokigen12ov0_021421F0Eiii
_ZN24CFieldEffectManpuGokigen12ov0_021421F0Eiii: ; 0x02165FB8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldr ip, [r7, #0x1c]
	add r0, r7, #0x68
	str ip, [r7, #0x80]
	ldr ip, [r0]
	mov r6, r1
	ldr ip, [ip, #8]
	mov r5, r2
	mov r4, r3
	blx ip
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end _ZN24CFieldEffectManpuGokigen12ov0_021421F0Eiii

	arm_func_start _ZN24CFieldEffectManpuGokigen12ov0_02142264Ei
_ZN24CFieldEffectManpuGokigen12ov0_02142264Ei: ; 0x02165FFC
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov sl, r0
	mov r5, r1
	bl _ZN17CFieldEffectActor12ov0_02142264Ei
	cmp r0, #0
	str r0, [sp]
	cmpne r0, #4
	beq _021662CC
	mov r1, r5
	add r0, sl, #0x90
	bl ov0_021665F4
	ldr r0, [sl, #0x34]
	ldr r4, [sl, #0x5c]
	mul sb, r5, r0
	cmp r4, #0
	beq _02166160
	mov r6, sb, asr #0x1f
	mov r7, #0
	arm_func_end _ZN24CFieldEffectManpuGokigen12ov0_02142264Ei
_02166048:
	ldr r0, [r4, #0x60]
	ldr r5, [r4, #0x70]
	cmp r0, #0
	beq _0216610C
	ldr r0, [sl, #0x50]
	cmp r0, #0
	beq _02166078
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_02166078:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _02166154
	ldr r1, [r4, #0x54]
	ldr r8, [r4, #0x58]
	umull r3, r2, r1, sb
	umull r0, fp, r8, sb
	mla r2, r1, r6, r2
	mov ip, r1, asr #0x1f
	mla fp, r8, r6, fp
	mov r1, r8, asr #0x1f
	mla fp, r1, sb, fp
	mov r0, r0, lsr #0xc
	orr r0, r0, fp, lsl #20
	mla r2, ip, sb, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	ldr r1, [r4, #0x4c]
	str r0, [sp, #0x10]
	add r1, r1, r3
	str r1, [r4, #0x4c]
	ldr r1, [r4, #0x50]
	str r0, [sp, #8]
	add r0, r1, r0
	str r0, [r4, #0x50]
	ldrsh r0, [r4, #0x5e]
	ldrsh r2, [r4, #0x5c]
	str r3, [sp, #0xc]
	mul r1, r0, sb
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	str r3, [sp, #4]
	subs r0, r0, sb
	str r0, [r4, #0x60]
	strmi r7, [r4, #0x60]
	b _02166154
_0216610C:
	cmp r4, #0
	beq _02166154
	cmp r5, #0
	ldrne r0, [r4, #0x6c]
	strne r0, [r5, #0x6c]
	ldr r1, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	cmp r1, #0
	strne r0, [r1, #0x70]
	streq r0, [sl, #0x5c]
	ldr r0, [sl, #0x60]
	str r0, [r4, #0x70]
	mov r0, #0
	str r0, [r4, #0x6c]
	ldr r0, [sl, #0x60]
	cmp r0, #0
	strne r4, [r0, #0x6c]
	str r4, [sl, #0x60]
_02166154:
	mov r4, r5
	cmp r5, #0
	bne _02166048
_02166160:
	ldr r0, [sl, #0x40]
	mov r5, #0
	mov r4, r5
	cmp r0, #0
	bls _021661C4
	mov r6, r5
_02166178:
	ldr r0, [sl, #0x38]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	ldreq r0, [sl, #0x3c]
	streq r6, [r0, r4, lsl #2]
	beq _021661B4
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sl, #0x3c]
	str r0, [r1, r4, lsl #2]
	ldr r0, [sl, #0x3c]
	ldr r0, [r0, r4, lsl #2]
	add r5, r5, r0
_021661B4:
	ldr r0, [sl, #0x40]
	add r4, r4, #1
	cmp r4, r0
	blo _02166178
_021661C4:
	cmp r5, #0
	beq _021662CC
	cmp r0, #0
	mov r8, #0
	bls _021662CC
_021661D8:
	ldr r0, [sl, #0x38]
	ldr r0, [r0, r8, lsl #2]
	cmp r0, #0
	ldrne r0, [sl, #0x3c]
	ldrne r0, [r0, r8, lsl #2]
	cmpne r0, #0
	beq _021662BC
	cmp r0, #0
	mov r7, #0
	bls _021662BC
	mov r4, r7
	mov fp, r7
	mov r5, r7
_0216620C:
	ldr r1, [sl, #0x60]
	mov r6, r5
	cmp r1, #0
	beq _0216624C
	ldr r0, [r1, #0x70]
	mov r6, r1
	str r0, [sl, #0x60]
	cmp r0, #0
	strne r5, [r0, #0x6c]
	ldr r0, [sl, #0x5c]
	str r0, [r1, #0x70]
	str r4, [r1, #0x6c]
	ldr r0, [sl, #0x5c]
	cmp r0, #0
	strne r1, [r0, #0x6c]
	str r1, [sl, #0x5c]
_0216624C:
	cmp r6, #0
	beq _021662A8
	ldr r3, [sl, #0x4c]
	ldr r2, [sl, #0x48]
	ldr r0, [sl, #0x44]
	mov r1, r6
	str r0, [r6, #0x2c]
	str fp, [r6, #0x30]
	str r2, [r6, #0x34]
	str r3, [r6, #0x38]
	ldr r0, [sl, #0x38]
	ldr r0, [r0, r8, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [sl, #0x50]
	cmp r0, #0
	beq _021662A8
	ldr r3, [r0]
	mov r1, r6
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_021662A8:
	ldr r0, [sl, #0x3c]
	add r7, r7, #1
	ldr r0, [r0, r8, lsl #2]
	cmp r7, r0
	blo _0216620C
_021662BC:
	ldr r0, [sl, #0x40]
	add r8, r8, #1
	cmp r8, r0
	blo _021661D8
_021662CC:
	ldr r0, [sp]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN24CFieldEffectManpuGokigen8SetDepthEl
_ZN24CFieldEffectManpuGokigen8SetDepthEl: ; 0x021662D8
	str r1, [r0, #0x64]
	bx lr
	arm_func_end _ZN24CFieldEffectManpuGokigen8SetDepthEl

	arm_func_start _ZN24CFieldEffectManpuGokigen4DrawEP8Camera2D
_ZN24CFieldEffectManpuGokigen4DrawEP8Camera2D: ; 0x021662E0
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r0, [r6, #0x14]
	mov r5, r1
	cmp r0, #0
	cmpne r0, #4
	ldrne r4, [r6, #0x5c]
	cmpne r4, #0
	beq _02166358
	arm_func_end _ZN24CFieldEffectManpuGokigen4DrawEP8Camera2D
_02166304:
	ldr r0, [r6, #0x64]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x4c]
	ldr r1, [r6, #0x2c]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x18]
	ldr r3, [r4, #0x50]
	ldr r2, [r6, #0x30]
	mov r1, r5
	add r2, r3, r2
	str r2, [r4, #0x1c]
	ldrsh r2, [r4, #0x5c]
	strh r2, [r4, #0x28]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x70]
	cmp r4, #0
	bne _02166304
_02166358:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN24CFieldEffectManpuGokigen8CEmitter5func2Ev
_ZN24CFieldEffectManpuGokigen8CEmitter5func2Ev: ; 0x02166360
	mov r1, #0x1000
	str r1, [r0, #0x20]
	bx lr
	arm_func_end _ZN24CFieldEffectManpuGokigen8CEmitter5func2Ev

	arm_func_start _ZN24CFieldEffectManpuGokigen8CEmitter6UpdateEi
_ZN24CFieldEffectManpuGokigen8CEmitter6UpdateEi: ; 0x0216636C
	ldr r2, [r0, #0x20]
	mov r3, #0
	cmp r2, #0
	ble _021663A0
	sub r1, r2, r1
	str r1, [r0, #0x20]
	cmp r1, #0
	bgt _021663A0
	ldr r1, [r0, #0x1c]
	mov r3, #1
	cmp r1, #0
	movgt r1, r1, lsl #0xc
	strgt r1, [r0, #0x20]
	arm_func_end _ZN24CFieldEffectManpuGokigen8CEmitter6UpdateEi
_021663A0:
	mov r0, r3
	bx lr

	arm_func_start _ZN24CFieldEffectManpuGokigen8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN24CFieldEffectManpuGokigen8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x021663A8
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x38
	mov r5, r0
	ldr r0, [r5, #0x18]
	mov r4, r1
	cmp r0, #0
	addeq sp, sp, #0x38
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _02166414
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _021663F4
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #8]
	str r1, [sp, #0xc]
	b _0216640C
	arm_func_end _ZN24CFieldEffectManpuGokigen8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_021663F4:
	mov r1, #0
	add r2, sp, #0x20
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
_0216640C:
	add r3, sp, #8
	b _02166430
_02166414:
	mov r1, #0
	add r2, sp, #0x28
	add r3, sp, #8
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
_02166430:
	ldr r6, [r3]
	ldr r3, [r3, #4]
	ldr r2, [r0, #0x70]
	ldr r1, [r0, #0x74]
	add r2, r2, r6
	add r1, r1, r3
	ldr r0, [r0, #8]
	str r6, [sp, #0x10]
	str r3, [sp, #0x14]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r2, [sp]
	str r1, [sp, #4]
	cmp r0, #0
	beq _02166494
	ldr r2, [r0, #0xc]
	cmp r2, #0
	moveq r3, #0
	beq _02166498
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r3, r2, r0
	b _02166498
_02166494:
	mov r3, #0
_02166498:
	mov r0, #0x3c000
	ldr r1, [sp, #4]
	str r0, [r4, #0x60]
	sub r3, r1, r3
	str r0, [r4, #0x64]
	mov r1, #0
	ldr r2, [sp]
	strh r1, [r4, #0x5e]
	mov r0, #0x1f
	str r0, [r4, #0x14]
	str r3, [sp, #4]
	str r2, [sp, #0x30]
	str r3, [sp, #0x34]
	strh r1, [r4, #8]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r6, [r0, #0x448]
	ldmib r1, {r3, r7}
	umull lr, ip, r7, r6
	mla ip, r7, r3, ip
	ldr r3, [r1, #0xc]
	ldr r8, [r1, #0x10]
	mla ip, r3, r6, ip
	ldr r7, [r1, #0x14]
	adds r8, r8, lr
	adc r3, r7, ip
	str r8, [r0, #0x448]
	str r3, [r1, #4]
	ldrb r1, [r5, #0x24]
	mov r2, #0
	mov r0, r2, lsl #1
	add r1, r1, #1
	orr r0, r0, r3, lsr #31
	add r1, r1, r0
	and r0, r1, #0xff
	cmp r0, #3
	strb r1, [r5, #0x24]
	subhs r0, r0, #3
	strcsb r0, [r5, #0x24]
	ldrb r0, [r5, #0x24]
	cmp r0, #0
	beq _02166554
	cmp r0, #1
	beq _0216656C
	b _02166584
_02166554:
	ldr r1, [sp, #0x30]
	ldr r0, [sp, #0x34]
	sub r1, r1, #0x8000
	str r1, [r4, #0x4c]
	str r0, [r4, #0x50]
	b _02166594
_0216656C:
	ldr r1, [sp, #0x30]
	ldr r0, [sp, #0x34]
	add r1, r1, #0x8000
	str r1, [r4, #0x4c]
	str r0, [r4, #0x50]
	b _02166594
_02166584:
	ldr r1, [sp, #0x30]
	ldr r0, [sp, #0x34]
	str r1, [r4, #0x4c]
	str r0, [r4, #0x50]
_02166594:
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, ip}
	umull r6, lr, ip, r3
	mla lr, ip, r2, lr
	ldr r2, [r1, #0xc]
	ldr r7, [r1, #0x10]
	mla lr, r2, r3, lr
	ldr ip, [r1, #0x14]
	adds r6, r7, r6
	str r6, [r0, #0x448]
	adc r2, ip, lr
	ldr r0, _021665F0 ; =0x0000FFFF
	str r2, [r1, #4]
	umull r0, r1, r2, r0
	ldrb r0, [r5, #0x24]
	orr r0, r1, r0, lsl #16
	str r0, [r4, #0x68]
	add sp, sp, #0x38
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_021665F0: .word 0x0000FFFF

	arm_func_start ov0_021665F4
ov0_021665F4: ; 0x021665F4
	ldr r2, [r0, #4]
	cmp r2, #0xb
	bxne lr
	ldr r2, [r0, #0xc]
	add r1, r2, r1
	str r1, [r0, #0xc]
	cmp r1, #0xc
	bxlt lr
	ldr r1, [r0, #8]
	add r1, r1, #1
	str r1, [r0, #8]
	cmp r1, #6
	movge r1, #0
	strge r1, [r0, #8]
	ldr r1, [r0, #0xc]
	sub r1, r1, #0xc
	str r1, [r0, #0xc]
	bx lr
	arm_func_end ov0_021665F4

	arm_func_start _ZN24CFieldEffectManpuGokigen9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN24CFieldEffectManpuGokigen9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x0216663C
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	ldr r2, [r1, #0x60]
	ldr r3, [r1, #0x64]
	ldr ip, _02166760 ; =0x00000666
	sub r3, r3, r2
	umull lr, r4, r3, ip
	ldr r6, [r1, #0x68]
	mov r3, r3, asr #0x1f
	mla r4, r3, ip, r4
	mov r5, lr, lsr #0xc
	mov r3, r6, lsr #0x10
	mov lr, r3, lsl #0x10
	mov r3, r6, lsl #0x10
	orr r5, r5, r4, lsl #20
	add r3, r5, r3, lsr #16
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	mov r3, r3, asr #4
	mov r3, r3, lsl #1
	add r3, r3, #1
	ldr r4, _02166764 ; =FX_SinCosTable_
	mov r5, r3, lsl #1
	movs r3, lr, lsr #0x10
	ldrsh r4, [r4, r5]
	beq _021666B4
	cmp r3, #1
	addeq r3, r4, #0x33
	addeq r4, r3, #0x300
	b _021666B8
	arm_func_end _ZN24CFieldEffectManpuGokigen9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_021666B4:
	sub r4, r4, ip, lsr #1
_021666B8:
	mov r3, #0x1000
	str r4, [r1, #0x54]
	rsb r3, r3, #0
	str r3, [r1, #0x58]
	ldr r3, [r0, #4]
	cmp r3, #0xa
	beq _0216674C
	cmp r3, #0xb
	bne _0216674C
	ldr r5, [r0, #8]
	ldr r4, _02166768 ; =DAT_overlay_0_02172f28
	add r3, r5, #1
	and r3, r3, #0xff
	cmp r3, #6
	movge r3, #0
	add ip, r3, r3, lsl #1
	add lr, r5, r5, lsl #1
	ldr r3, [r0, #0xc]
	add r0, sp, #0
	add r5, r4, lr
	add r6, r4, ip
	mov r4, #0
_02166710:
	ldrb lr, [r5], #1
	ldrb ip, [r6], #1
	add r4, r4, #1
	cmp r4, #3
	sub ip, ip, lr
	mul ip, r3, ip
	add ip, lr, ip, asr #5
	strb ip, [r0], #1
	blt _02166710
	ldrb r3, [sp]
	ldrb r0, [sp, #1]
	ldrb ip, [sp, #2]
	orr r0, r3, r0, lsl #5
	orr r0, r0, ip, lsl #10
	strh r0, [r1, #8]
_0216674C:
	cmp r2, #0x20000
	movlt r0, r2, asr #0xc
	strlt r0, [r1, #0x14]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02166760: .word 0x00000666
_02166764: .word FX_SinCosTable_
_02166768: .word DAT_overlay_0_02172f28

	arm_func_start ov0_0216676C
ov0_0216676C: ; 0x0216676C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216676C

	arm_func_start ov0_02166780
ov0_02166780: ; 0x02166780
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02166780

	arm_func_start ov0_02166794
ov0_02166794: ; 0x02166794
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _021667DC ; =_ZTV17CPrimitiveRectNTF+8
	mov r2, #0
	str r0, [r4]
	ldr r0, _021667E0 ; =_ZTV16CSimpleSpriteNTF+8
	str r2, [r4, #0x18]
	str r0, [r4]
	str r2, [r4, #0x4c]
	str r2, [r4, #0x50]
	strh r2, [r4, #0x54]
	mov r1, #0x1000
	str r2, [r4, #0x58]
	str r1, [r4, #0x48]
	mov r0, r4
	str r1, [r4, #0x44]
	ldmia sp!, {r4, pc}
	.align 2, 0
_021667DC: .word _ZTV17CPrimitiveRectNTF+8
_021667E0: .word _ZTV16CSimpleSpriteNTF+8
	arm_func_end ov0_02166794

	arm_func_start ov0_021667E4
ov0_021667E4: ; 0x021667E4
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0216690C ; =_ZTV12CFieldEffect+8
	mov r5, r0
	str r2, [r5]
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r1, _02166910 ; =ptr_FUN_overlay_0_0216691c_overlay_0_02179a14
	mov r0, #0
	str r1, [r5]
	str r0, [r5, #0x18]
	mov r0, #8
	str r0, [r5, #0x24]
	ldr ip, _02166914 ; =_ZN16CSimpleSpriteNTFD1Ev
	ldr r3, _02166918 ; =ov0_02166794
	add r0, r5, #0x28
	mov r1, #4
	mov r2, #0x5c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r2, #0
	strb r2, [r5, #0x1a8]
	strb r2, [r5, #0x1a9]
	add r0, r5, #0x100
	strh r2, [r0, #0xaa]
	strh r2, [r0, #0xac]
	mov r1, #1
	strh r1, [r0, #0xb2]
	strb r4, [r5, #0x1b4]
	mov r0, #0x1f
	strb r0, [r5, #0x1b5]
	str r2, [r5, #0x1c4]
	str r2, [r5, #0x1c8]
	mov r4, r5
	str r2, [r5, #0x1cc]
	mov r1, #0x40000
	mov r3, r2
	arm_func_end ov0_021667E4
_0216687C:
	str r1, [r4, #0x74]
	str r1, [r4, #0x78]
	add r0, r2, #8
	str r0, [r4, #0x38]
	str r3, [r4, #0x54]
	str r3, [r4, #0x58]
	str r1, [r4, #0x5c]
	str r1, [r4, #0x60]
	add r0, r5, r2, lsl #2
	add r2, r2, #1
	str r3, [r0, #0x198]
	cmp r2, #4
	add r4, r4, #0x5c
	blt _0216687C
	mvn r1, #3
	str r1, [r5, #0x140]
	add r0, r1, #1
	str r0, [r5, #0x2c]
	add r0, r1, #2
	str r0, [r5, #0x88]
	add r0, r1, #3
	mov r2, r5
	str r0, [r5, #0xe4]
	mov r1, #0
_021668DC:
	add r0, r5, r3, lsl #1
	add r0, r0, #0x100
	strh r1, [r0, #0xae]
	add r3, r3, #1
	str r1, [r2, #0x3c]
	cmp r3, #2
	add r2, r2, #0x5c
	blt _021668DC
	str r1, [r5, #0x20]
	mov r0, r5
	str r1, [r5, #0x1c]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216690C: .word _ZTV12CFieldEffect+8
_02166910: .word ptr_FUN_overlay_0_0216691c_overlay_0_02179a14
_02166914: .word _ZN16CSimpleSpriteNTFD1Ev
_02166918: .word ov0_02166794

	arm_func_start _ZN17CFieldEffectBloomD1Ev
_ZN17CFieldEffectBloomD1Ev: ; 0x0216691C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _02166958 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0x28
	mov r1, #4
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	ldr r1, _0216695C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02166958: .word _ZN16CSimpleSpriteNTFD1Ev
_0216695C: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN17CFieldEffectBloomD1Ev

	arm_func_start ov0_02166960
ov0_02166960: ; 0x02166960
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r3, _021669A4 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0x28
	mov r1, #4
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	ldr r1, _021669A8 ; =_ZTV12CFieldEffect+8
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
_021669A4: .word _ZN16CSimpleSpriteNTFD1Ev
_021669A8: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_02166960

	arm_func_start ov0_021669AC
ov0_021669AC: ; 0x021669AC
	cmp r1, #0
	bxlt lr
	cmp r1, #4
	bxge lr
	mov r3, #0x5c
	mla r3, r1, r3, r0
	str r2, [r3, #0x40]
	add r0, r0, r1, lsl #2
	str r2, [r0, #0x198]
	bx lr
	arm_func_end ov0_021669AC

	arm_func_start ov0_021669D4
ov0_021669D4: ; 0x021669D4
	mov r3, #0
	arm_func_end ov0_021669D4
_021669D8:
	add r2, r1, r3
	add r3, r3, #1
	str r2, [r0, #0x38]
	cmp r3, #4
	add r0, r0, #0x5c
	blt _021669D8
	mov r0, #4
	bx lr

	arm_func_start _ZN17CFieldEffectBloom12sub_020333D8Eii
_ZN17CFieldEffectBloom12sub_020333D8Eii: ; 0x021669F8
	ldrb ip, [r0, #0x1b5]
	mov r3, r1, lsl #0xc
	mov r1, #1
	mov ip, ip, lsl #0xc
	str ip, [r0, #0x1b8]
	str r3, [r0, #0x1bc]
	str r2, [r0, #0x1c4]
	str r1, [r0, #0x1cc]
	ldr r2, [r0, #0x1b8]
	mov r1, #0
	str r2, [r0, #0x1c0]
	str r1, [r0, #0x1c8]
	bx lr
	arm_func_end _ZN17CFieldEffectBloom12sub_020333D8Eii

	arm_func_start _ZN17CFieldEffectBloom12sub_0203312CEii
_ZN17CFieldEffectBloom12sub_0203312CEii: ; 0x02166A2C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	cmp r1, #0x11
	mov r4, #1
	bgt _02166A68
	cmp r1, #0x11
	bge _02166B1C
	cmp r1, #4
	addls pc, pc, r1, lsl #2
	b _02166B5C
_02166A54: ; jump table
	b _02166B5C ; case 0
	b _02166A84 ; case 1
	b _02166AB0 ; case 2
	b _02166ADC ; case 3
	b _02166AFC ; case 4
	arm_func_end _ZN17CFieldEffectBloom12sub_0203312CEii
_02166A68:
	cmp r1, #0x14
	bgt _02166A78
	beq _02166B54
	b _02166B5C
_02166A78:
	cmp r1, #0x1a
	beq _02166B3C
	b _02166B5C
_02166A84:
	mov r0, r2, lsl #0xc
	mov r2, r5
	str r0, [r5, #0x1c]
	mov r1, #0
_02166A94:
	ldr r0, [r5, #0x1c]
	add r1, r1, #1
	str r0, [r2, #0x64]
	cmp r1, #4
	add r2, r2, #0x5c
	blt _02166A94
	b _02166B60
_02166AB0:
	mov r0, r2, lsl #0xc
	mov r2, r5
	str r0, [r5, #0x20]
	mov r1, #0
_02166AC0:
	ldr r0, [r5, #0x20]
	add r1, r1, #1
	str r0, [r2, #0x68]
	cmp r1, #4
	add r2, r2, #0x5c
	blt _02166AC0
	b _02166B60
_02166ADC:
	mov r1, r2, lsl #0xc
	mov r0, #0
_02166AE4:
	add r0, r0, #1
	str r1, [r5, #0x74]
	cmp r0, #4
	add r5, r5, #0x5c
	blt _02166AE4
	b _02166B60
_02166AFC:
	mov r1, r2, lsl #0xc
	mov r0, #0
_02166B04:
	add r0, r0, #1
	str r1, [r5, #0x78]
	cmp r0, #4
	add r5, r5, #0x5c
	blt _02166B04
	b _02166B60
_02166B1C:
	ldr r0, _02166B68 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02166B60
	mov r1, r2
	bl _ZN11CFieldScene12ov0_02123060Em
	str r0, [r5, #0x18]
	b _02166B60
_02166B3C:
	and r0, r2, #0xff
	cmp r0, #0x1f
	strb r2, [r5, #0x1b5]
	movhi r0, #0x1f
	strhib r0, [r5, #0x1b5]
	b _02166B60
_02166B54:
	str r2, [r5, #0x24]
	b _02166B60
_02166B5C:
	mov r4, #0
_02166B60:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02166B68: .word MAIN_BSS_0210CA40

	arm_func_start _ZN17CFieldEffectBloom12ov0_02142264Ei
_ZN17CFieldEffectBloom12ov0_02142264Ei: ; 0x02166B6C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x30
	mov r7, r0
	mov r6, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	add r1, r7, #0x100
	ldrsb r2, [r1, #0xa8]
	mov r4, r0
	cmp r2, #0
	ble _02166BFC
	sub r0, r2, r6
	strb r0, [r7, #0x1a8]
	ldrsb r0, [r1, #0xa8]
	cmp r0, #0
	bgt _02166C70
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr r8, [r2, #0x448]
	ldmib r1, {r3, sb}
	umull lr, ip, sb, r8
	mla ip, sb, r3, ip
	ldr r3, [r1, #0xc]
	ldr r0, [r1, #0x10]
	mla ip, r3, r8, ip
	ldr sb, [r1, #0x14]
	adds r0, r0, lr
	str r0, [r2, #0x448]
	adc r3, sb, ip
	mov r0, #6
	umull r0, r2, r3, r0
	str r3, [r1, #4]
	add r0, r2, #0xa
	strb r0, [r7, #0x1a9]
	b _02166C70
	arm_func_end _ZN17CFieldEffectBloom12ov0_02142264Ei
_02166BFC:
	ldrsb r0, [r1, #0xa9]
	sub r0, r0, r6
	strb r0, [r7, #0x1a9]
	ldrsb r0, [r1, #0xa9]
	cmp r0, #0
	bgt _02166C70
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr ip, [r2, #0x448]
	ldmib r1, {r3, lr}
	umull sb, r8, lr, ip
	mla r8, lr, r3, r8
	ldr r3, [r1, #0xc]
	ldr r0, [r1, #0x10]
	mla r8, r3, ip, r8
	ldr lr, [r1, #0x14]
	adds r0, r0, sb
	str r0, [r2, #0x448]
	adc r3, lr, r8
	mov r0, #0x33
	umull r0, r2, r3, r0
	str r3, [r1, #4]
	add r0, r2, #0xa
	strb r0, [r7, #0x1a8]
	add r0, r7, #0x100
	mov r1, #0
	strh r1, [r0, #0xac]
_02166C70:
	add r2, r7, #0x100
	ldrh r3, [r2, #0xaa]
	mov r0, r6, lsl #0x17
	mov r1, r6, lsl #0x19
	add r0, r3, r0, lsr #16
	strh r0, [r2, #0xaa]
	ldrh r0, [r2, #0xac]
	add r0, r0, r1, lsr #16
	strh r0, [r2, #0xac]
	ldrb r0, [r7, #0x1b4]
	cmp r0, #0
	beq _02166CC8
	mov r2, #0
_02166CA4:
	add r0, r7, r2, lsl #1
	add r0, r0, #0x100
	ldrsh r1, [r0, #0xae]
	add r2, r2, #1
	cmp r1, #0
	subgt r1, r1, r6
	strgth r1, [r0, #0xae]
	cmp r2, #2
	blt _02166CA4
_02166CC8:
	add r0, r7, #0x100
	ldrsh r1, [r0, #0xb2]
	cmp r1, #0
	ble _02166D20
	sub r1, r1, r6
	strh r1, [r0, #0xb2]
	ldrsh r0, [r0, #0xb2]
	cmp r0, #0
	bgt _02166D20
	mov r0, r7
	bl ov0_02167270
	ldrb r0, [r7, #0x1b4]
	cmp r0, #1
	beq _02166D14
	cmp r0, #2
	addeq r0, r7, #0x100
	moveq r1, #0x3c
	streqh r1, [r0, #0xb2]
	b _02166D20
_02166D14:
	add r0, r7, #0x100
	mov r1, #0x3c
	strh r1, [r0, #0xb2]
_02166D20:
	ldr r0, [r7, #0x18]
	cmp r0, #0
	beq _02166E30
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02166D78
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02166D58
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	b _02166D70
_02166D58:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_02166D70:
	add r8, sp, #0x20
	b _02166D94
_02166D78:
	mov r0, #0
	add r1, sp, #0
	add r8, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_02166D94:
	ldr r0, [r7, #0x18]
	ldr ip, [r7, #0x1c]
	ldr r3, [r7, #0x20]
	ldr r2, [r8]
	ldr r1, [r8, #4]
	add r2, r2, ip
	add r1, r1, r3
	ldr r0, [r0, #8]
	str ip, [sp, #0x18]
	str r3, [sp, #0x1c]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	str r2, [sp, #0x28]
	str r1, [sp, #0x2c]
	cmp r0, #0
	beq _02166DFC
	ldr r2, [r0, #0xc]
	cmp r2, #0
	moveq r1, #0
	beq _02166E00
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r1, r2, r0
	b _02166E00
_02166DFC:
	mov r1, #0
_02166E00:
	ldr r0, [sp, #0x2c]
	mov r2, r7
	sub r3, r0, r1
	ldr r0, [sp, #0x28]
	str r3, [sp, #0x2c]
	mov r1, #0
_02166E18:
	str r0, [r2, #0x64]
	add r1, r1, #1
	str r3, [r2, #0x68]
	cmp r1, #4
	add r2, r2, #0x5c
	blt _02166E18
_02166E30:
	ldr r0, [r7, #0x1cc]
	cmp r0, #0
	moveq r0, #0
	beq _02166EAC
	ldr r0, [r7, #0x1c8]
	add r0, r0, r6
	str r0, [r7, #0x1c8]
	ldr r1, [r7, #0x1c4]
	cmp r1, #0
	movle r0, #0x1000
	ble _02166E74
	ldr r0, [r7, #0x1c8]
	cmp r0, r1
	movge r0, #0x1000
	bge _02166E74
	mov r0, r0, lsl #0xc
	bl _s32_div_f
_02166E74:
	ldr r3, [r7, #0x1b8]
	ldr r1, [r7, #0x1bc]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r0, r3, r0
	str r0, [r7, #0x1c0]
	ldr r1, [r7, #0x1c8]
	ldr r0, [r7, #0x1c4]
	cmp r1, r0
	movge r0, #0
	strge r0, [r7, #0x1cc]
	mov r0, #1
_02166EAC:
	cmp r0, #0
	beq _02166ED0
	ldr r0, [r7, #0x1c0]
	mov r1, r0, asr #0xc
	and r0, r1, #0xff
	cmp r0, #0x1f
	strb r1, [r7, #0x1b5]
	movhi r0, #0x1f
	strhib r0, [r7, #0x1b5]
_02166ED0:
	cmp r4, #1
	beq _02166EEC
	cmp r4, #2
	beq _02166F08
	cmp r4, #3
	beq _02166F10
	b _02166F2C
_02166EEC:
	ldrb r2, [r7, #0x1b5]
	ldr r0, [r7, #0x10]
	ldr r1, [r7, #4]
	mul r0, r2, r0
	bl _s32_div_f
	mov r5, r0
	b _02166F2C
_02166F08:
	ldrb r5, [r7, #0x1b5]
	b _02166F2C
_02166F10:
	ldr r1, [r7, #0xc]
	ldr r0, [r7, #0x10]
	ldrb r2, [r7, #0x1b5]
	sub r0, r1, r0
	mul r0, r2, r0
	bl _s32_div_f
	mov r5, r0
_02166F2C:
	ldr r0, [r7, #0x24]
	ldr r1, _02166F70 ; =0x84210843
	add r0, r0, #0x10
	mul r2, r5, r0
	smull r0, r3, r1, r2
	add r3, r2, r3
	mov r0, r2, lsr #0x1f
	add r3, r0, r3, asr #4
	mov r0, #0
_02166F50:
	add r0, r0, #1
	str r3, [r7, #0x3c]
	cmp r0, #4
	add r7, r7, #0x5c
	blt _02166F50
	mov r0, r4
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02166F70: .word 0x84210843

	arm_func_start _ZN17CFieldEffectBloom12ov0_02142344EP8Camera2D
_ZN17CFieldEffectBloom12ov0_02142344EP8Camera2D: ; 0x02166F74
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r5, r0
	ldrb r0, [r5, #0x1b4]
	mov r4, r1
	cmp r0, #0
	beq _02166FA0
	cmp r0, #1
	beq _02167030
	cmp r0, #2
	beq _021670C0
	b _021671B4
	arm_func_end _ZN17CFieldEffectBloom12ov0_02142344EP8Camera2D
_02166FA0:
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r6, [r0, #0x448]
	ldmib r1, {r3, r7}
	umull sb, r8, r7, r6
	mla r8, r7, r3, r8
	ldr r3, [r1, #0xc]
	ldr ip, [r1, #0x10]
	mla r8, r3, r6, r8
	ldr r7, [r1, #0x14]
	adds sb, ip, sb
	mov r2, #0
	str sb, [r0, #0x448]
	adc r3, r7, r8
	mov r0, r2, lsl #1
	orrs r0, r0, r3, lsr #31
	ldrne r0, _0216724C ; =0x000014CC
	str r3, [r1, #4]
	moveq r0, #0x1000
	str r0, [r5, #0x70]
	str r0, [r5, #0x6c]
	str r0, [r5, #0x184]
	str r0, [r5, #0x180]
	add r0, r5, #0x28
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x13c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	b _021671B4
_02167030:
	add r0, r5, #0x100
	ldrsh r0, [r0, #0xae]
	ldr r2, _02167250 ; =0x88888889
	ldr r3, _02167254 ; =0x00000B33
	rsb r6, r0, #0x3c
	mov r7, r6, lsl #0xc
	smull r1, r8, r2, r7
	add r8, r8, r6, lsl #12
	mov r1, r7, lsr #0x1f
	add r8, r1, r8, asr #5
	umull r6, r2, r8, r3
	mov r1, r8, asr #0x1f
	mla r2, r1, r3, r2
	mov r1, r6, lsr #0xc
	cmp r0, #0x10
	movgt r0, #0x1f
	orr r1, r1, r2, lsl #20
	movle r0, r0, asr #1
	add r1, r1, #0x800
	str r0, [r5, #0x3c]
	str r1, [r5, #0x70]
	str r1, [r5, #0x6c]
	str r0, [r5, #0x150]
	str r1, [r5, #0x184]
	str r1, [r5, #0x180]
	add r0, r5, #0x28
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x13c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	b _021671B4
_021670C0:
	add r0, r5, #0x100
	ldrsh r0, [r0, #0xae]
	ldr r2, _02167250 ; =0x88888889
	ldr r3, _02167254 ; =0x00000B33
	rsb r6, r0, #0x3c
	mov r7, r6, lsl #0xc
	smull r1, r8, r2, r7
	add r8, r8, r6, lsl #12
	mov r1, r7, lsr #0x1f
	add r8, r1, r8, asr #5
	umull r6, r2, r8, r3
	mov r1, r8, asr #0x1f
	mla r2, r1, r3, r2
	mov r1, r6, lsr #0xc
	cmp r0, #0x10
	movgt r0, #0x1f
	orr r1, r1, r2, lsl #20
	movle r0, r0, asr #1
	add r6, r1, #0x800
	str r0, [r5, #0x150]
	str r6, [r5, #0x184]
	str r6, [r5, #0x180]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r2, r0, #0x1000
	ldr r7, [r1, #8]
	ldr lr, [r2, #0x448]
	ldr ip, [r1, #4]
	umull sb, r8, r7, lr
	mla r8, r7, ip, r8
	ldr ip, [r1, #0xc]
	ldr r0, [r1, #0x10]
	mla r8, ip, lr, r8
	ldr r7, [r1, #0x14]
	adds r0, r0, sb
	mov r3, #0
	str r0, [r2, #0x448]
	adc r7, r7, r8
	mov r0, r3, lsl #1
	str r7, [r1, #4]
	orrs r0, r0, r7, lsr #31
	beq _02167184
	ldr r0, _02167254 ; =0x00000B33
	mov r1, r6, asr #0x1f
	umull r3, r2, r6, r0
	mla r2, r1, r0, r2
	mov r6, r3, lsr #0xc
	orr r6, r6, r2, lsl #20
_02167184:
	str r6, [r5, #0x70]
	str r6, [r5, #0x6c]
	add r0, r5, #0x28
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x13c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
_021671B4:
	add r0, r5, #0x100
	ldrsb r1, [r0, #0xa8]
	cmp r1, #0
	ble _02167244
	ldrh r2, [r0, #0xac]
	ldr r1, [r5, #0x24]
	ldr r0, _02167258 ; =FX_SinCosTable_
	mov r2, r2, asr #4
	mov r2, r2, lsl #2
	ldrsh r2, [r0, r2]
	ldr r0, _0216725C ; =0x000004CC
	cmp r1, #8
	umull r6, r3, r2, r0
	mov r2, r2, asr #0x1f
	mla r3, r2, r0, r3
	mov r0, r6, lsr #0xc
	orr r0, r0, r3, lsl #20
	add r2, r0, #0x1000
	beq _0216721C
	ldr r0, _02167260 ; =0x00000199
	sub r1, r1, #8
	mul r0, r1, r0
	add r0, r0, #0x1000
	smull r1, r0, r2, r0
	mov r2, r1, lsr #0xc
	orr r2, r2, r0, lsl #20
_0216721C:
	str r2, [r5, #0x128]
	str r2, [r5, #0x124]
	add r2, r5, #0x100
	ldrh r3, [r2, #0xaa]
	add r0, r5, #0xe0
	mov r1, r4
	strh r3, [r2, #0x34]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
_02167244:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0216724C: .word 0x000014CC
_02167250: .word 0x88888889
_02167254: .word 0x00000B33
_02167258: .word FX_SinCosTable_
_0216725C: .word 0x000004CC
_02167260: .word 0x00000199

	arm_func_start _ZN17CFieldEffectBloom12sub_02033440Et
_ZN17CFieldEffectBloom12sub_02033440Et: ; 0x02167264
	add r0, r0, #0x100
	strh r1, [r0, #0x44]
	bx lr
	arm_func_end _ZN17CFieldEffectBloom12sub_02033440Et

	arm_func_start ov0_02167270
ov0_02167270: ; 0x02167270
	mov r3, #0
	arm_func_end ov0_02167270
_02167274:
	add r1, r0, r3, lsl #1
	add r1, r1, #0x100
	ldrsh r2, [r1, #0xae]
	cmp r2, #0
	movle r0, #0x3c
	strleh r0, [r1, #0xae]
	bxle lr
	add r3, r3, #1
	cmp r3, #2
	blt _02167274
	bx lr

	arm_func_start _ZN24CFieldEffectBloomFactoryD1Ev
_ZN24CFieldEffectBloomFactoryD1Ev: ; 0x021672A0
	stmdb sp!, {r4, lr}
	ldr r1, _021672D0 ; =ptr_FUN_overlay_0_021672a0_overlay_0_021799f4
	mov r4, r0
	str r1, [r4]
	bl ov0_0216753C
	ldr r3, _021672D4 ; =_ZN17UnkClass_02151244D1Ev
	add r0, r4, #4
	mov r1, #3
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021672D0: .word ptr_FUN_overlay_0_021672a0_overlay_0_021799f4
_021672D4: .word _ZN17UnkClass_02151244D1Ev
	arm_func_end _ZN24CFieldEffectBloomFactoryD1Ev

	arm_func_start ov0_021672D8
ov0_021672D8: ; 0x021672D8
	stmdb sp!, {r4, lr}
	ldr r1, _02167310 ; =ptr_FUN_overlay_0_021672a0_overlay_0_021799f4
	mov r4, r0
	str r1, [r4]
	bl ov0_0216753C
	ldr r3, _02167314 ; =_ZN17UnkClass_02151244D1Ev
	add r0, r4, #4
	mov r1, #3
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02167310: .word ptr_FUN_overlay_0_021672a0_overlay_0_021799f4
_02167314: .word _ZN17UnkClass_02151244D1Ev
	arm_func_end ov0_021672D8

	arm_func_start _ZN24CFieldEffectBloomFactory5ResetEv
_ZN24CFieldEffectBloomFactory5ResetEv: ; 0x02167318
	ldr ip, _02167320 ; =ov0_0216753C
	bx ip
	.align 2, 0
_02167320: .word ov0_0216753C
	arm_func_end _ZN24CFieldEffectBloomFactory5ResetEv

	arm_func_start _ZN24CFieldEffectBloomFactory6CreateEi
_ZN24CFieldEffectBloomFactory6CreateEi: ; 0x02167324
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x7c
	mov r5, #1
	str r5, [sp]
	mov r4, #0
	str r4, [sp, #4]
	mov r6, r1
	str r4, [sp, #8]
	mov r7, r0
	ldr r1, _0216747C ; =s_MEF_overlay_0_02179a70
	ldr r2, _02167480 ; =s_data_Field_Effect_ef100_LZ_bin_overlay_0_02179a74
	add r0, sp, #0x10
	mov r3, r5
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r0, [r7, #0xc]
	cmp r0, #0
	bne _02167380
	mov r1, r4
	mov r0, r7
	mov r2, r1
	bl ov0_02167488
	mov r5, r0
	arm_func_end _ZN24CFieldEffectBloomFactory6CreateEi
_02167380:
	ldr r0, [r7, #0x38]
	cmp r0, #0
	bne _021673A0
	mov r1, #1
	mov r0, r7
	mov r2, r1
	bl ov0_02167488
	mov r5, r0
_021673A0:
	ldr r0, [r7, #0x64]
	cmp r0, #0
	bne _021673C0
	mov r1, #2
	mov r0, r7
	mov r2, r1
	bl ov0_02167488
	mov r5, r0
_021673C0:
	add r0, sp, #0x10
	bl _ZN13CArchiveGuardD1Ev
	cmp r5, #0
	beq _02167470
	mov r0, #0x1d0
	bl _Znwm
	movs r4, r0
	beq _021673EC
	mov r1, r6
	bl ov0_021667E4
	mov r4, r0
_021673EC:
	cmp r4, #0
	beq _02167470
	mov r0, r4
	add r2, r7, #4
	mov r1, #0
	bl ov0_021669AC
	mov r0, r4
	add r2, r7, #4
	mov r1, #1
	bl ov0_021669AC
	mov r0, r4
	add r2, r7, #0x30
	mov r1, #2
	bl ov0_021669AC
	mov r0, r4
	add r2, r7, #0x5c
	mov r1, #3
	bl ov0_021669AC
	ldr r1, _02167484 ; =MAIN_BSS_0210CA60
	mov r0, r4
	ldr r1, [r1]
	ldrb r1, [r1, #0x87d]
	add r1, r1, #8
	bl ov0_021669D4
	ldr r1, _02167484 ; =MAIN_BSS_0210CA60
	and r0, r0, #0xff
	ldr r2, [r1]
	ldrb r1, [r2, #0x87d]
	add r0, r1, r0
	strb r0, [r2, #0x87d]
	and r0, r0, #0xff
	and r0, r0, #0x1f
	strb r0, [r2, #0x87d]
_02167470:
	mov r0, r4
	add sp, sp, #0x7c
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_0216747C: .word s_MEF_overlay_0_02179a70
_02167480: .word s_data_Field_Effect_ef100_LZ_bin_overlay_0_02179a74
_02167484: .word MAIN_BSS_0210CA60

	arm_func_start ov0_02167488
ov0_02167488: ; 0x02167488
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0xc0
	movs r6, r1
	mov r4, r0
	mov r5, r2
	bmi _02167524
	cmp r6, #3
	bge _02167524
	ldr r1, _02167530 ; =s_MEF_ef100_02d_ntft_overlay_0_02179a94
	add r0, sp, #0x60
	bl OS_SPrintf
	ldr r1, _02167534 ; =s_MEF_ef100_02d_ntfp_overlay_0_02179aa8
	add r0, sp, #0
	mov r2, r5
	bl OS_SPrintf
	mov r0, #0x2c
	mul r5, r6, r0
	add r0, r4, #4
	add r1, sp, #0x60
	add r2, sp, #0
	add r0, r0, r5
	mov r3, #0
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	cmp r0, #0
	moveq r0, #0
	beq _02167504
	ldr r0, _02167538 ; =0x027FFC3C
	add r1, r4, r5
	ldr r2, [r0]
	mov r0, #1
	str r2, [r1, #0x2c]
	arm_func_end ov0_02167488
_02167504:
	add r2, r4, r5
	mov r1, #6
	str r1, [r2, #0x20]
	mov r1, #3
	str r1, [r2, #0x24]
	str r1, [r2, #0x28]
	add sp, sp, #0xc0
	ldmia sp!, {r4, r5, r6, pc}
_02167524:
	mov r0, #0
	add sp, sp, #0xc0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02167530: .word s_MEF_ef100_02d_ntft_overlay_0_02179a94
_02167534: .word s_MEF_ef100_02d_ntfp_overlay_0_02179aa8
_02167538: .word 0x027FFC3C

	arm_func_start ov0_0216753C
ov0_0216753C: ; 0x0216753C
	stmdb sp!, {r3, r4, r5, lr}
	add r5, r0, #4
	mov r4, #0
	arm_func_end ov0_0216753C
_02167548:
	mov r0, r5
	bl _ZN10NtfTexture7ReleaseEv
	add r4, r4, #1
	cmp r4, #3
	add r5, r5, #0x2c
	blt _02167548
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldEffectBloom12sub_020332A4Ev
_ZN17CFieldEffectBloom12sub_020332A4Ev: ; 0x02167564
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, #1
	mov r5, #0
	ldr lr, _021675C0 ; =0x027FFC3C
	mov r1, r5
	mov r2, r4
	arm_func_end _ZN17CFieldEffectBloom12sub_020332A4Ev
_0216757C:
	add r3, r0, r5, lsl #2
	ldr r3, [r3, #0x198]
	cmp r3, #0
	beq _021675AC
	ldr ip, [lr]
	ldr r3, [r3, #0x28]
	cmp r3, ip
	movne r3, r2
	moveq r3, r1
	cmp r3, #0
	moveq r4, #0
	beq _021675B8
_021675AC:
	add r5, r5, #1
	cmp r5, #4
	blt _0216757C
_021675B8:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021675C0: .word 0x027FFC3C

	arm_func_start _ZN17CFieldEffectBloom12sub_02033028Ev
_ZN17CFieldEffectBloom12sub_02033028Ev: ; 0x021675C4
	mov r0, #0x13
	bx lr
	arm_func_end _ZN17CFieldEffectBloom12sub_02033028Ev

	arm_func_start ov0_021675CC
ov0_021675CC: ; 0x021675CC
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	ldr r2, _02167948 ; =_ZTV12CFieldEffect+8
	mov r5, r0
	str r2, [r5]
	ldr r2, [r0]
	mov r4, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r0, _0216794C ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r1, #0
	str r0, [r5]
	str r1, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldr r0, _02167950 ; =ptr_FUN_overlay_0_02167994_overlay_0_02179c6c
	str r1, [r5, #0x24]
	str r0, [r5]
	ldr r2, _02167954 ; =PTR_LAB_overlay_0_02167984_overlay_0_02179b0c
	strb r1, [r5, #0x28]
	ldr r0, _02167958 ; =0x00000CCC
	str r2, [r5, #0x2c]
	mov ip, #0x1000
	str r0, [r5, #0x30]
	mov r2, #0x2000
	ldr r0, _0216795C ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r2, [r5, #0x34]
	str r0, [r5, #0x38]
	str r1, [r5, #0x4c]
	str r1, [r5, #0x3c]
	str r1, [r5, #0x40]
	str r1, [r5, #0x44]
	ldr r0, _02167960 ; =_ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
	str ip, [r5, #0x48]
	str r0, [r5, #0x38]
	str r1, [r5, #0x60]
	str r1, [r5, #0x64]
	str ip, [r5, #0x50]
	str r1, [r5, #0x54]
	mov r2, #0x10
	str r1, [r5, #0x58]
	sub r3, ip, #0x2000
	ldr r0, _02167964 ; =_ZTV30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE+8
	str r3, [r5, #0x5c]
	str r0, [r5, #0x38]
	str r1, [r5, #0x68]
	str r1, [r5, #0x6c]
	str r1, [r5, #0x70]
	mov r0, #0xa
	str r0, [r5, #0x74]
	mov r0, #0xf
	str r0, [r5, #0x78]
	str r2, [r5, #0x7c]
	str r1, [r5, #0x80]
	str r1, [r5, #0x84]
	sub r0, r2, #0x810
	str r0, [r5, #0x88]
	ldr r0, _02167968 ; =PTR_LAB_overlay_0_02167988_overlay_0_02179b8c
	strb r1, [r5, #0x8c]
	str r0, [r5, #0x38]
	add r0, r5, #0x28
	str r0, [r5, #0x90]
	str r1, [r5, #0xac]
	str r1, [r5, #0xb0]
	str r1, [r5, #0xb4]
	str ip, [r5, #0xc0]
	mov r0, #1
	str r0, [r5, #0xcc]
	str r1, [r5, #0xd0]
	str r1, [r5, #0xd4]
	str r1, [r5, #0xd8]
	str r1, [r5, #0xdc]
	str r2, [r5, #0xe4]
	str r1, [r5, #0xe8]
	ldr r0, [r5, #0xe4]
	cmp r0, #0
	beq _02167790
	ldr r1, _0216796C ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _02167970 ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r5, #0xe0]
	ldr r1, [r5, #0xe4]
	mov r6, #0
	mov r0, r6
	cmp r1, #0
	bls _02167784
	mov r1, r6
	mov lr, r6
	mov r2, #0x74
	arm_func_end ov0_021675CC
_02167738:
	ldr r3, [r5, #0xe0]
	add ip, r0, #1
	add r3, r3, r1
	str r6, [r3, #0x6c]
	ldr r3, [r5, #0xe4]
	add r0, r0, #1
	cmp ip, r3
	ldrlo r3, [r5, #0xe0]
	mlalo r6, ip, r2, r3
	ldr r3, [r5, #0xe0]
	movhs r6, lr
	add r3, r3, r1
	str r6, [r3, #0x70]
	ldr ip, [r5, #0xe0]
	ldr r3, [r5, #0xe4]
	add r6, ip, r1
	cmp r0, r3
	add r1, r1, #0x74
	blo _02167738
_02167784:
	ldr r0, [r5, #0xe0]
	str r0, [r5, #0xec]
	b _02167798
_02167790:
	str r1, [r5, #0xe0]
	str r1, [r5, #0xec]
_02167798:
	mov r1, #0
	str r1, [r5, #0xf0]
	ldr r0, [r5, #0xcc]
	cmp r0, #0
	streq r1, [r5, #0xc4]
	streq r1, [r5, #0xc8]
	beq _021677E0
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r5, #0xc4]
	ldr r1, [r5, #0xcc]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r5, #0xcc]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r5, #0xc8]
_021677E0:
	mov r1, #0
	str r1, [r5, #0xbc]
	ldr r0, _0216795C ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r1, [r5, #0xb8]
	str r0, [r5, #0xf4]
	str r1, [r5, #0x108]
	str r1, [r5, #0xf8]
	str r1, [r5, #0xfc]
	mov r2, #0x1000
	str r1, [r5, #0x100]
	ldr r0, _02167960 ; =_ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
	str r2, [r5, #0x104]
	str r0, [r5, #0xf4]
	str r1, [r5, #0x11c]
	str r1, [r5, #0x120]
	str r2, [r5, #0x10c]
	str r1, [r5, #0x110]
	str r1, [r5, #0x114]
	sub r2, r2, #0x2000
	str r2, [r5, #0x118]
	ldr r0, _02167964 ; =_ZTV30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE+8
	mov ip, #0xf
	str r0, [r5, #0xf4]
	str r1, [r5, #0x124]
	str r1, [r5, #0x128]
	str r1, [r5, #0x12c]
	mov r0, #0xa
	str r0, [r5, #0x130]
	mov r2, #0x10
	str ip, [r5, #0x134]
	str r2, [r5, #0x138]
	str r1, [r5, #0x13c]
	str r1, [r5, #0x140]
	sub r0, r2, #0x810
	str r0, [r5, #0x144]
	ldr r0, _02167974 ; =PTR_LAB_overlay_0_0216798c_overlay_0_02179b6c
	strb r1, [r5, #0x148]
	str r0, [r5, #0xf4]
	add r3, r5, #0x28
	ldr r0, _02167978 ; =PTR_LAB_overlay_0_02167990_overlay_0_02179b20
	str r3, [r5, #0x14c]
	str r0, [r5, #0x150]
	mov r0, #0x20000
	str r0, [r5, #0x60]
	str r0, [r5, #0x64]
	str ip, [r5, #0x6c]
	mov r0, #2
	str r0, [r5, #0x7c]
	cmp r4, #0
	beq _021678B0
	cmp r4, #1
	beq _021678DC
_021678B0:
	mov r0, r5
	ldr r3, [r0]
	mov r1, #0
	ldr r3, [r3, #0x38]
	mov r2, #0x20
	blx r3
	ldr r1, _0216797C ; =0x00001333
	mov r0, #0x2000
	str r1, [r5, #0x30]
	str r0, [r5, #0x34]
	b _021678FC
_021678DC:
	mov r0, r5
	ldr r3, [r0]
	ldr r3, [r3, #0x38]
	blx r3
	ldr r1, _02167980 ; =0x00001999
	mov r0, #0x2000
	str r1, [r5, #0x30]
	str r0, [r5, #0x34]
_021678FC:
	mov r0, #0x20000
	str r0, [r5, #0x11c]
	str r0, [r5, #0x120]
	mov r0, #0x14
	str r0, [r5, #0x128]
	mov r0, #1
	str r0, [r5, #0x138]
	ldr r0, [r5, #0xcc]
	cmp r0, #0
	bls _02167934
	ldr r1, [r5, #0xc4]
	cmp r1, #0
	addne r0, r5, #0xf4
	strne r0, [r1]
_02167934:
	add r1, r5, #0x150
	mov r0, r5
	str r1, [r5, #0xdc]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02167948: .word _ZTV12CFieldEffect+8
_0216794C: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_02167950: .word ptr_FUN_overlay_0_02167994_overlay_0_02179c6c
_02167954: .word PTR_LAB_overlay_0_02167984_overlay_0_02179b0c
_02167958: .word 0x00000CCC
_0216795C: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_02167960: .word _ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
_02167964: .word _ZTV30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE+8
_02167968: .word PTR_LAB_overlay_0_02167988_overlay_0_02179b8c
_0216796C: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_02167970: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
_02167974: .word PTR_LAB_overlay_0_0216798c_overlay_0_02179b6c
_02167978: .word PTR_LAB_overlay_0_02167990_overlay_0_02179b20
_0216797C: .word 0x00001333
_02167980: .word 0x00001999

	arm_func_start _ZN21CFieldEffectDarkCloud9CAnimatorD1Ev
_ZN21CFieldEffectDarkCloud9CAnimatorD1Ev: ; 0x02167984
	bx lr
	arm_func_end _ZN21CFieldEffectDarkCloud9CAnimatorD1Ev

	arm_func_start _ZN21CFieldEffectDarkCloud8CEmitterD1Ev
_ZN21CFieldEffectDarkCloud8CEmitterD1Ev: ; 0x02167988
	bx lr
	arm_func_end _ZN21CFieldEffectDarkCloud8CEmitterD1Ev

	arm_func_start _ZN21CFieldEffectDarkCloud15CRemainsEmitterD1Ev
_ZN21CFieldEffectDarkCloud15CRemainsEmitterD1Ev: ; 0x0216798C
	bx lr
	arm_func_end _ZN21CFieldEffectDarkCloud15CRemainsEmitterD1Ev

	arm_func_start _ZN21CFieldEffectDarkCloud16CRemainsAnimatorD1Ev
_ZN21CFieldEffectDarkCloud16CRemainsAnimatorD1Ev: ; 0x02167990
	bx lr
	arm_func_end _ZN21CFieldEffectDarkCloud16CRemainsAnimatorD1Ev

	arm_func_start _ZN21CFieldEffectDarkCloudD1Ev
_ZN21CFieldEffectDarkCloudD1Ev: ; 0x02167994
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #0xc8]
	cmp r0, #0
	beq _021679B4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc8]
	arm_func_end _ZN21CFieldEffectDarkCloudD1Ev
_021679B4:
	ldr r0, [r4, #0xc4]
	cmp r0, #0
	beq _021679CC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc4]
_021679CC:
	ldr r0, [r4, #0xe0]
	cmp r0, #0
	beq _021679F0
	ldr r3, _02167A8C ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0xe0]
_021679F0:
	ldr r0, _02167A90 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _02167A6C
	beq _02167A64
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _02167A20
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
_02167A20:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _02167A38
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_02167A38:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _02167A5C
	ldr r3, _02167A8C ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_02167A5C:
	mov r0, r5
	bl _ZdlPv
_02167A64:
	mov r0, #0
	str r0, [r4, #0x18]
_02167A6C:
	ldr r1, _02167A94 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02167A8C: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_02167A90: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_02167A94: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_02167A98
ov0_02167A98: ; 0x02167A98
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #0xc8]
	cmp r0, #0
	beq _02167AB8
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc8]
	arm_func_end ov0_02167A98
_02167AB8:
	ldr r0, [r4, #0xc4]
	cmp r0, #0
	beq _02167AD0
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc4]
_02167AD0:
	ldr r0, [r4, #0xe0]
	cmp r0, #0
	beq _02167AF4
	ldr r3, _02167B98 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0xe0]
_02167AF4:
	ldr r0, _02167B9C ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	str r0, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _02167B70
	beq _02167B68
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _02167B24
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
_02167B24:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _02167B3C
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_02167B3C:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _02167B60
	ldr r3, _02167B98 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_02167B60:
	mov r0, r5
	bl _ZdlPv
_02167B68:
	mov r0, #0
	str r0, [r4, #0x18]
_02167B70:
	ldr r1, _02167BA0 ; =_ZTV12CFieldEffect+8
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
_02167B98: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_02167B9C: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_02167BA0: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_02167BA4
ov0_02167BA4: ; 0x02167BA4
	stmdb sp!, {lr}
	sub sp, sp, #0xc
	str r1, [r0, #0xd0]
	str r2, [r0, #0xd4]
	str r3, [r0, #0xd8]
	str r1, [sp]
	str r3, [sp, #8]
	str r2, [sp, #4]
	ldr r2, [r0]
	add r1, sp, #0
	ldr r2, [r2, #0x5c]
	blx r2
	add sp, sp, #0xc
	ldmia sp!, {pc}
	arm_func_end ov0_02167BA4

	arm_func_start _ZN21CFieldEffectDarkCloud12sub_0203312CEii
_ZN21CFieldEffectDarkCloud12sub_0203312CEii: ; 0x02167BDC
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #3
	mov r0, #1
	beq _02167C0C
	cmp r1, #4
	beq _02167C1C
	cmp r1, #0x14
	beq _02167C2C
	b _02167C40
	arm_func_end _ZN21CFieldEffectDarkCloud12sub_0203312CEii
_02167C0C:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x60]
	ldmia sp!, {r3, r4, r5, r6, pc}
_02167C1C:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x64]
	ldmia sp!, {r3, r4, r5, r6, pc}
_02167C2C:
	ldr r1, [r6, #0x18]
	mov r2, r5, lsl #0xc
	str r2, [r1, #8]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_02167C40:
	cmp r1, #0
	mov r0, #0
	beq _02167C64
	cmp r1, #1
	beq _02167E90
	cmp r1, #2
	beq _02167EA8
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_02167C64:
	cmp r5, #0
	ble _02167E84
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _02167CE0
	beq _02167CD8
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _02167C94
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_02167C94:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _02167CAC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_02167CAC:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _02167CD0
	ldr r3, _02167EC0 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x28]
_02167CD0:
	mov r0, r4
	bl _ZdlPv
_02167CD8:
	mov r0, #0
	str r0, [r6, #0x18]
_02167CE0:
	mov r0, #0x3c
	bl _Znwm
	movs r4, r0
	beq _02167E18
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
	beq _02167DBC
	ldr r1, _02167EC0 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _02167EC4 ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _02167DB0
	mov r1, lr
	mov ip, lr
	mov r2, #0x74
_02167D64:
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
	blo _02167D64
_02167DB0:
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x34]
	b _02167DC4
_02167DBC:
	str r1, [r4, #0x28]
	str r1, [r4, #0x34]
_02167DC4:
	mov r1, #0
	str r1, [r4, #0x38]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _02167E0C
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
_02167E0C:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_02167E18:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _02167E84
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _02167E50
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_02167E50:
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
_02167E84:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_02167E90:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_02167EA8:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02167EC0: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_02167EC4: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev

	arm_func_start _ZN21CFieldEffectDarkCloud12ov0_021421F0Eiii
_ZN21CFieldEffectDarkCloud12ov0_021421F0Eiii: ; 0x02167EC8
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x1c
	ldr r4, [r0]
	str r0, [sp]
	ldr r4, [r4, #0x64]
	mov r7, r1
	mov r6, r2
	mov r5, r3
	blx r4
	cmp r0, #0
	beq _02167F00
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end _ZN21CFieldEffectDarkCloud12ov0_021421F0Eiii
_02167F00:
	ldr r0, [sp]
	mov r1, r7
	mov r2, r6
	mov r3, r5
	bl _ZN12CFieldEffect12ov0_021421F0Eiii
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
_02167F20:
	ldr r0, [sp]
	mov r1, #3
	bl _ZN12CFieldEffect12ov0_02142264Ei
	cmp r0, #4
	ldrne r0, [sp]
	ldrne sl, [r0, #0x18]
	cmpne sl, #0
	beq _021681DC
	ldr r0, [sl, #8]
	ldr r4, [sl, #0x30]
	add sb, r0, r0, lsl #1
	cmp r4, #0
	beq _02168074
	mov r7, #0
	mov r6, sb, asr #0x1f
	mov r8, r7
_02167F60:
	ldr r0, [r4, #0x60]
	ldr r5, [r4, #0x70]
	cmp r0, #0
	beq _02168024
	ldr r0, [sl, #0x24]
	cmp r0, #0
	beq _02167F90
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_02167F90:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _02168068
	ldr r2, [r4, #0x54]
	ldr r1, [r4, #0x58]
	umull r0, r3, r2, sb
	mov fp, r0, lsr #0xc
	mla r3, r2, r6, r3
	mov r0, r2, asr #0x1f
	mla r3, r0, sb, r3
	orr fp, fp, r3, lsl #20
	umull r3, r2, r1, sb
	mla r2, r1, r6, r2
	mov r0, r1, asr #0x1f
	mla r2, r0, sb, r2
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	ldr ip, [r4, #0x4c]
	str fp, [sp, #0xc]
	str fp, [sp, #0x14]
	add fp, ip, fp
	str fp, [r4, #0x4c]
	ldr r0, [r4, #0x50]
	str r1, [sp, #0x10]
	add r0, r0, r1
	str r0, [r4, #0x50]
	ldrsh r0, [r4, #0x5e]
	str r1, [sp, #0x18]
	ldrsh r2, [r4, #0x5c]
	mul r1, r0, sb
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	subs r0, r0, sb
	str r0, [r4, #0x60]
	strmi r8, [r4, #0x60]
	b _02168068
_02168024:
	cmp r4, #0
	beq _02168068
	cmp r5, #0
	ldrne r0, [r4, #0x6c]
	strne r0, [r5, #0x6c]
	ldr r1, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	cmp r1, #0
	strne r0, [r1, #0x70]
	streq r0, [sl, #0x30]
	ldr r0, [sl, #0x34]
	str r0, [r4, #0x70]
	str r7, [r4, #0x6c]
	ldr r0, [sl, #0x34]
	cmp r0, #0
	strne r4, [r0, #0x6c]
	str r4, [sl, #0x34]
_02168068:
	mov r4, r5
	cmp r5, #0
	bne _02167F60
_02168074:
	ldr r0, [sl, #0x14]
	mov r4, #0
	mov r5, r4
	cmp r0, #0
	bls _021680D8
	mov r6, r4
_0216808C:
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [sl, #0x10]
	streq r6, [r0, r5, lsl #2]
	beq _021680C8
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sl, #0x10]
	str r0, [r1, r5, lsl #2]
	ldr r0, [sl, #0x10]
	ldr r0, [r0, r5, lsl #2]
	add r4, r4, r0
_021680C8:
	ldr r0, [sl, #0x14]
	add r5, r5, #1
	cmp r5, r0
	blo _0216808C
_021680D8:
	cmp r4, #0
	beq _021681DC
	cmp r0, #0
	mov r6, #0
	bls _021681DC
	mov r4, r6
	mov fp, r6
	mov r5, r6
_021680F8:
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	ldrne r0, [sl, #0x10]
	ldrne r0, [r0, r6, lsl #2]
	cmpne r0, #0
	beq _021681CC
	mov r7, #0
	bls _021681CC
_0216811C:
	ldr r1, [sl, #0x34]
	mov r8, r5
	cmp r1, #0
	beq _0216815C
	ldr r0, [r1, #0x70]
	mov r8, r1
	str r0, [sl, #0x34]
	cmp r0, #0
	strne r5, [r0, #0x6c]
	ldr r0, [sl, #0x30]
	str r0, [r1, #0x70]
	str r4, [r1, #0x6c]
	ldr r0, [sl, #0x30]
	cmp r0, #0
	strne r1, [r0, #0x6c]
	str r1, [sl, #0x30]
_0216815C:
	cmp r8, #0
	beq _021681B8
	ldr r3, [sl, #0x20]
	ldr r2, [sl, #0x1c]
	ldr r0, [sl, #0x18]
	mov r1, r8
	str r0, [r8, #0x2c]
	str fp, [r8, #0x30]
	str r2, [r8, #0x34]
	str r3, [r8, #0x38]
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r6, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [sl, #0x24]
	cmp r0, #0
	beq _021681B8
	ldr r3, [r0]
	mov r1, r8
	mov r2, sb
	ldr r3, [r3, #8]
	blx r3
_021681B8:
	ldr r0, [sl, #0x10]
	add r7, r7, #1
	ldr r0, [r0, r6, lsl #2]
	cmp r7, r0
	blo _0216811C
_021681CC:
	ldr r0, [sl, #0x14]
	add r6, r6, #1
	cmp r6, r0
	blo _021680F8
_021681DC:
	ldr r0, [sp, #8]
	add r0, r0, #1
	str r0, [sp, #8]
	cmp r0, #0x64
	blt _02167F20
	ldr r0, [sp, #4]
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN21CFieldEffectDarkCloud12ov0_02142264Ei
_ZN21CFieldEffectDarkCloud12ov0_02142264Ei: ; 0x021681FC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x28
	mov sl, r0
	ldr r0, [sl, #0xb4]
	str r1, [sp]
	cmp r0, #0
	moveq r0, #0
	beq _021682AC
	ldr r1, [sl, #0xb0]
	ldr r0, [sp]
	add r0, r1, r0
	str r0, [sl, #0xb0]
	ldr r1, [sl, #0xac]
	cmp r1, #0
	movle r0, #0x1000
	ble _02168254
	ldr r0, [sl, #0xb0]
	cmp r0, r1
	movge r0, #0x1000
	bge _02168254
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	arm_func_end _ZN21CFieldEffectDarkCloud12ov0_02142264Ei
_02168254:
	ldr r3, [sl, #0x94]
	ldr r1, [sl, #0x9c]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	add r1, r3, r2
	str r1, [sl, #0xa4]
	ldr r3, [sl, #0x98]
	ldr r1, [sl, #0xa0]
	sub r1, r1, r3
	smull r2, r1, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r0, r3, r0
	str r0, [sl, #0xa8]
	ldr r1, [sl, #0xb0]
	ldr r0, [sl, #0xac]
	cmp r1, r0
	movge r0, #0
	strge r0, [sl, #0xb4]
	mov r0, #1
_021682AC:
	cmp r0, #0
	beq _021682DC
	ldr r1, [sl, #0x18]
	ldr r0, [sl, #0xa4]
	str r0, [r1]
	ldr r0, [sl, #0xa8]
	str r0, [r1, #4]
	ldr r0, [sl, #0xa4]
	str r0, [sl, #0xf8]
	ldr r0, [sl, #0xa8]
	str r0, [sl, #0xfc]
	b _021682EC
_021682DC:
	add r0, sl, #0xf4
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
_021682EC:
	ldr r1, [sl, #0xc0]
	ldr r0, [sp]
	ldr r4, [sl, #0xe8]
	mul sb, r0, r1
	cmp r4, #0
	beq _02168424
	mov r6, sb, asr #0x1f
	mov r7, #0
_0216830C:
	ldr r0, [r4, #0x60]
	ldr r5, [r4, #0x70]
	cmp r0, #0
	beq _021683D0
	ldr r0, [sl, #0xdc]
	cmp r0, #0
	beq _0216833C
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_0216833C:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _02168418
	ldr r1, [r4, #0x54]
	ldr r8, [r4, #0x58]
	umull r3, r2, r1, sb
	umull r0, fp, r8, sb
	mla r2, r1, r6, r2
	mov ip, r1, asr #0x1f
	mla fp, r8, r6, fp
	mov r1, r8, asr #0x1f
	mla fp, r1, sb, fp
	mov r0, r0, lsr #0xc
	orr r0, r0, fp, lsl #20
	mla r2, ip, sb, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	ldr r1, [r4, #0x4c]
	str r0, [sp, #0x24]
	add r1, r1, r3
	str r1, [r4, #0x4c]
	ldr r1, [r4, #0x50]
	str r0, [sp, #0x1c]
	add r0, r1, r0
	str r0, [r4, #0x50]
	ldrsh r0, [r4, #0x5e]
	ldrsh r2, [r4, #0x5c]
	str r3, [sp, #0x20]
	mul r1, r0, sb
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	str r3, [sp, #0x18]
	subs r0, r0, sb
	str r0, [r4, #0x60]
	strmi r7, [r4, #0x60]
	b _02168418
_021683D0:
	cmp r4, #0
	beq _02168418
	cmp r5, #0
	ldrne r0, [r4, #0x6c]
	strne r0, [r5, #0x6c]
	ldr r1, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	cmp r1, #0
	strne r0, [r1, #0x70]
	streq r0, [sl, #0xe8]
	ldr r0, [sl, #0xec]
	str r0, [r4, #0x70]
	mov r0, #0
	str r0, [r4, #0x6c]
	ldr r0, [sl, #0xec]
	cmp r0, #0
	strne r4, [r0, #0x6c]
	str r4, [sl, #0xec]
_02168418:
	mov r4, r5
	cmp r5, #0
	bne _0216830C
_02168424:
	ldr r0, [sl, #0xcc]
	mov r5, #0
	mov r4, r5
	cmp r0, #0
	bls _02168488
	mov r6, r5
_0216843C:
	ldr r0, [sl, #0xc4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	ldreq r0, [sl, #0xc8]
	streq r6, [r0, r4, lsl #2]
	beq _02168478
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sl, #0xc8]
	str r0, [r1, r4, lsl #2]
	ldr r0, [sl, #0xc8]
	ldr r0, [r0, r4, lsl #2]
	add r5, r5, r0
_02168478:
	ldr r0, [sl, #0xcc]
	add r4, r4, #1
	cmp r4, r0
	blo _0216843C
_02168488:
	cmp r5, #0
	beq _02168590
	cmp r0, #0
	mov r8, #0
	bls _02168590
_0216849C:
	ldr r0, [sl, #0xc4]
	ldr r0, [r0, r8, lsl #2]
	cmp r0, #0
	ldrne r0, [sl, #0xc8]
	ldrne r0, [r0, r8, lsl #2]
	cmpne r0, #0
	beq _02168580
	cmp r0, #0
	mov r7, #0
	bls _02168580
	mov r4, r7
	mov fp, r7
	mov r5, r7
_021684D0:
	ldr r1, [sl, #0xec]
	mov r6, r5
	cmp r1, #0
	beq _02168510
	ldr r0, [r1, #0x70]
	mov r6, r1
	str r0, [sl, #0xec]
	cmp r0, #0
	strne r5, [r0, #0x6c]
	ldr r0, [sl, #0xe8]
	str r0, [r1, #0x70]
	str r4, [r1, #0x6c]
	ldr r0, [sl, #0xe8]
	cmp r0, #0
	strne r1, [r0, #0x6c]
	str r1, [sl, #0xe8]
_02168510:
	cmp r6, #0
	beq _0216856C
	ldr r3, [sl, #0xd8]
	ldr r2, [sl, #0xd4]
	ldr r0, [sl, #0xd0]
	mov r1, r6
	str r0, [r6, #0x2c]
	str fp, [r6, #0x30]
	str r2, [r6, #0x34]
	str r3, [r6, #0x38]
	ldr r0, [sl, #0xc4]
	ldr r0, [r0, r8, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [sl, #0xdc]
	cmp r0, #0
	beq _0216856C
	ldr r3, [r0]
	mov r1, r6
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_0216856C:
	ldr r0, [sl, #0xc8]
	add r7, r7, #1
	ldr r0, [r0, r8, lsl #2]
	cmp r7, r0
	blo _021684D0
_02168580:
	ldr r0, [sl, #0xcc]
	add r8, r8, #1
	cmp r8, r0
	blo _0216849C
_02168590:
	ldr r1, [sp]
	mov r0, sl
	bl _ZN12CFieldEffect12ov0_02142264Ei
	cmp r0, #4
	ldrne sl, [sl, #0x18]
	str r0, [sp, #4]
	cmpne sl, #0
	beq _02168854
	ldr r1, [sl, #8]
	ldr r0, [sp]
	ldr r4, [sl, #0x30]
	mul sb, r0, r1
	cmp r4, #0
	beq _021686E8
	mov r6, sb, asr #0x1f
	mov r7, #0
_021685D0:
	ldr r0, [r4, #0x60]
	ldr r5, [r4, #0x70]
	cmp r0, #0
	beq _02168694
	ldr r0, [sl, #0x24]
	cmp r0, #0
	beq _02168600
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_02168600:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	ble _021686DC
	ldr r1, [r4, #0x54]
	ldr r8, [r4, #0x58]
	umull r3, r2, r1, sb
	umull r0, fp, r8, sb
	mla r2, r1, r6, r2
	mov ip, r1, asr #0x1f
	mla fp, r8, r6, fp
	mov r1, r8, asr #0x1f
	mla fp, r1, sb, fp
	mov r0, r0, lsr #0xc
	orr r0, r0, fp, lsl #20
	mla r2, ip, sb, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	ldr r1, [r4, #0x4c]
	str r0, [sp, #0xc]
	add r1, r1, r3
	str r1, [r4, #0x4c]
	ldr r1, [r4, #0x50]
	str r0, [sp, #0x14]
	add r0, r1, r0
	str r0, [r4, #0x50]
	ldrsh r0, [r4, #0x5e]
	ldrsh r2, [r4, #0x5c]
	str r3, [sp, #8]
	mul r1, r0, sb
	add r0, r2, r1, asr #12
	strh r0, [r4, #0x5c]
	ldr r0, [r4, #0x60]
	str r3, [sp, #0x10]
	subs r0, r0, sb
	str r0, [r4, #0x60]
	strmi r7, [r4, #0x60]
	b _021686DC
_02168694:
	cmp r4, #0
	beq _021686DC
	cmp r5, #0
	ldrne r0, [r4, #0x6c]
	strne r0, [r5, #0x6c]
	ldr r1, [r4, #0x6c]
	ldr r0, [r4, #0x70]
	cmp r1, #0
	strne r0, [r1, #0x70]
	streq r0, [sl, #0x30]
	ldr r0, [sl, #0x34]
	str r0, [r4, #0x70]
	mov r0, #0
	str r0, [r4, #0x6c]
	ldr r0, [sl, #0x34]
	cmp r0, #0
	strne r4, [r0, #0x6c]
	str r4, [sl, #0x34]
_021686DC:
	mov r4, r5
	cmp r5, #0
	bne _021685D0
_021686E8:
	ldr r0, [sl, #0x14]
	mov r4, #0
	mov r5, r4
	cmp r0, #0
	bls _0216874C
	mov r6, r4
_02168700:
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [sl, #0x10]
	streq r6, [r0, r5, lsl #2]
	beq _0216873C
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sl, #0x10]
	str r0, [r1, r5, lsl #2]
	ldr r0, [sl, #0x10]
	ldr r0, [r0, r5, lsl #2]
	add r4, r4, r0
_0216873C:
	ldr r0, [sl, #0x14]
	add r5, r5, #1
	cmp r5, r0
	blo _02168700
_0216874C:
	cmp r4, #0
	beq _02168854
	cmp r0, #0
	mov r6, #0
	bls _02168854
_02168760:
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	ldrne r0, [sl, #0x10]
	ldrne r0, [r0, r6, lsl #2]
	cmpne r0, #0
	beq _02168844
	cmp r0, #0
	mov r7, #0
	bls _02168844
	mov r4, r7
	mov fp, r7
	mov r5, r7
_02168794:
	ldr r1, [sl, #0x34]
	mov r8, r5
	cmp r1, #0
	beq _021687D4
	ldr r0, [r1, #0x70]
	mov r8, r1
	str r0, [sl, #0x34]
	cmp r0, #0
	strne r5, [r0, #0x6c]
	ldr r0, [sl, #0x30]
	str r0, [r1, #0x70]
	str r4, [r1, #0x6c]
	ldr r0, [sl, #0x30]
	cmp r0, #0
	strne r1, [r0, #0x6c]
	str r1, [sl, #0x30]
_021687D4:
	cmp r8, #0
	beq _02168830
	ldr r3, [sl, #0x20]
	ldr r2, [sl, #0x1c]
	ldr r0, [sl, #0x18]
	mov r1, r8
	str r0, [r8, #0x2c]
	str fp, [r8, #0x30]
	str r2, [r8, #0x34]
	str r3, [r8, #0x38]
	ldr r0, [sl, #0xc]
	ldr r0, [r0, r6, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [sl, #0x24]
	cmp r0, #0
	beq _02168830
	ldr r3, [r0]
	mov r1, r8
	ldr r3, [r3, #8]
	mov r2, sb
	blx r3
_02168830:
	ldr r0, [sl, #0x10]
	add r7, r7, #1
	ldr r0, [r0, r6, lsl #2]
	cmp r7, r0
	blo _02168794
_02168844:
	ldr r0, [sl, #0x14]
	add r6, r6, #1
	cmp r6, r0
	blo _02168760
_02168854:
	ldr r0, [sp, #4]
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN21CFieldEffectDarkCloud12ov0_02142344EP8Camera2D
_ZN21CFieldEffectDarkCloud12ov0_02142344EP8Camera2D: ; 0x02168860
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	ldr r4, [r5, #0xe8]
	mov r6, r1
	cmp r4, #0
	beq _021688CC
	arm_func_end _ZN21CFieldEffectDarkCloud12ov0_02142344EP8Camera2D
_02168878:
	ldr r0, [r5, #0xf0]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r2, [r4, #0x4c]
	ldr r1, [r5, #0xb8]
	mov r0, r4
	add r1, r2, r1
	str r1, [r4, #0x18]
	ldr r3, [r4, #0x50]
	ldr r2, [r5, #0xbc]
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
	bne _02168878
_021688CC:
	ldr r5, [r5, #0x18]
	cmp r5, #0
	ldrne r4, [r5, #0x30]
	cmpne r4, #0
	beq _02168934
_021688E0:
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
	bne _021688E0
_02168934:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN21CFieldEffectDarkCloud12sub_0203331CERK7Point2Di
_ZN21CFieldEffectDarkCloud12sub_0203331CERK7Point2Di: ; 0x0216893C
	stmdb sp!, {r4, lr}
	ldr r4, [r0, #0x18]
	mov ip, #1
	ldr lr, [r4]
	mov r3, #0
	str lr, [r0, #0x94]
	ldr lr, [r4, #4]
	str lr, [r0, #0x98]
	ldr lr, [r1]
	str lr, [r0, #0x9c]
	ldr r1, [r1, #4]
	str r1, [r0, #0xa0]
	str r2, [r0, #0xac]
	str ip, [r0, #0xb4]
	ldr r1, [r0, #0x94]
	str r1, [r0, #0xa4]
	ldr r1, [r0, #0x98]
	str r1, [r0, #0xa8]
	str r3, [r0, #0xb0]
	ldr r1, [r0, #0xf4]!
	ldr r1, [r1, #8]
	blx r1
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21CFieldEffectDarkCloud12sub_0203331CERK7Point2Di

	arm_func_start _ZN21CFieldEffectDarkCloud9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN21CFieldEffectDarkCloud9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x02168998
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r1
	mov r7, r2
	ldr r2, [r8, #0x64]
	ldr r1, [r8, #0x60]
	ldr r6, [r0, #4]
	ldr r0, [r0, #8]
	sub r5, r2, r1
	sub r0, r0, r6
	smull r3, r1, r0, r5
	mov r3, r3, lsr #0xc
	orr r3, r3, r1, lsl #20
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, r2, asr #0x1f
	mov r4, r5, asr #0x1f
	bl _ll_div
	cmp r5, #0x3c000
	add r6, r6, r0
	ble _02168A74
	mov r0, #0x14
	umull r4, r3, r7, r0
	mov r2, r7, asr #0x1f
	mla r3, r2, r0, r3
	ldr r1, [r8, #0x4c]
	mov r0, r4, lsr #0xc
	cmp r1, #0
	ldr r2, [r8, #0x54]
	orr r0, r0, r3, lsl #20
	addlt r0, r2, r0
	ldr r1, [r8, #0x58]
	subge r0, r2, r0
	str r0, [r8, #0x54]
	str r1, [r8, #0x58]
	ldr r1, [r8, #0x60]
	cmp r1, #0x1e000
	bge _02168AAC
	mov r0, #0x14000
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, #0
	mov r2, #0x1e000
	bl _ll_div
	mov r0, r0, asr #0xc
	str r0, [r8, #0x14]
	b _02168AAC
	arm_func_end _ZN21CFieldEffectDarkCloud9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_02168A74:
	mov r0, #0x14000
	umull r2, r1, r5, r0
	mla r1, r4, r0, r1
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r3, #0
	mov r2, #0x3c000
	bl _ll_div
	mov r0, r0, asr #0xc
	str r0, [r8, #0x14]
_02168AAC:
	str r6, [r8, #0x20]
	str r6, [r8, #0x24]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start _ZN21CFieldEffectDarkCloud8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN21CFieldEffectDarkCloud8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x02168AB8
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	ldr lr, _02168C20 ; =MAIN_BSS_0210CEC8
	ldr r3, [r0, #0x28]
	ldmia lr, {r2, r4, r6}
	mla r2, r4, r2, r6
	mla r7, r4, r2, r6
	mov r4, r2, lsr #0x10
	str r2, [lr]
	ldr r2, [r0, #0x2c]
	ldr ip, _02168C24 ; =0x00007FFF
	mov r4, r4, lsl #0x10
	mov r6, r7, lsr #0x10
	and r8, ip, r4, lsr #16
	mov r4, r6, lsl #0x10
	and r4, ip, r4, lsr #16
	mov r6, r8, asr #3
	str r7, [lr]
	smull r8, r7, r6, r3
	mov r4, r4, asr #3
	smull ip, r6, r4, r2
	adds r8, r8, #0x800
	adc r4, r7, #0
	adds ip, ip, #0x800
	mov r7, r8, lsr #0xc
	orr r7, r7, r4, lsl #20
	adc r4, r6, #0
	mov ip, ip, lsr #0xc
	orr ip, ip, r4, lsl #20
	sub r7, r7, r3, asr #1
	ldr r6, [r0, #4]
	mov r4, r1
	ldr r3, [r0, #8]
	add r1, r6, r7
	sub r2, ip, r2, asr #1
	str r1, [r4, #0x4c]
	add r1, r3, r2
	str r1, [r4, #0x50]
	mov r1, #0x12c000
	str r1, [r4, #0x60]
	str r1, [r4, #0x64]
	mov r5, #6
	strh r5, [r4, #0x2a]
	mov r1, #0
	strh r1, [r4, #8]
	ldr r6, [r0, #0x58]
	sub r0, r5, #7
	ldrb r5, [r6]
	mov r1, #0x14
	add r3, r5, #1
	and r2, r3, #0xff
	and r2, r2, #0x1f
	strb r2, [r6]
	add r2, r5, #8
	str r2, [r4, #0x10]
	str r0, [r4, #4]
	str r1, [r4, #0x14]
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	movge r0, #0xcc
	sublt r0, r1, #0xe0
	str r0, [r4, #0x54]
	mvn r0, #0xcb
	str r0, [r4, #0x58]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, ip}
	umull r5, lr, ip, r3
	mla lr, ip, r2, lr
	ldr r2, [r1, #0xc]
	ldr r6, [r1, #0x10]
	mla lr, r2, r3, lr
	ldr ip, [r1, #0x14]
	adds r6, r6, r5
	str r6, [r0, #0x448]
	adc r5, ip, lr
	mov r0, #7
	umull r0, r2, r5, r0
	sub lr, r2, #3
	mov r2, lr, lsl #0x10
	ldr r3, _02168C28 ; =0xB60B60B7
	mov r0, r2, lsr #0x1f
	smull r2, ip, r3, r2
	add ip, ip, lr, lsl #16
	str r5, [r1, #4]
	add ip, r0, ip, asr #8
	strh ip, [r4, #0x5e]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02168C20: .word MAIN_BSS_0210CEC8
_02168C24: .word 0x00007FFF
_02168C28: .word 0xB60B60B7
	arm_func_end _ZN21CFieldEffectDarkCloud8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

	arm_func_start _ZN21CFieldEffectDarkCloud15CRemainsEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN21CFieldEffectDarkCloud15CRemainsEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x02168C2C
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	ldr lr, _02168D84 ; =MAIN_BSS_0210CEC8
	ldr r3, [r0, #0x28]
	ldmia lr, {r2, r4, r6}
	mla r2, r4, r2, r6
	mla r7, r4, r2, r6
	mov r4, r2, lsr #0x10
	str r2, [lr]
	ldr r2, [r0, #0x2c]
	ldr ip, _02168D88 ; =0x00007FFF
	mov r4, r4, lsl #0x10
	str r7, [lr]
	mov r6, r7, lsr #0x10
	and r8, ip, r4, lsr #16
	mov r4, r6, lsl #0x10
	mov r6, r8, asr #3
	and r4, ip, r4, lsr #16
	smull r8, r7, r6, r3
	mov r4, r4, asr #3
	smull ip, r6, r4, r2
	adds r8, r8, #0x800
	adc r4, r7, #0
	adds ip, ip, #0x800
	mov r7, r8, lsr #0xc
	orr r7, r7, r4, lsl #20
	adc r4, r6, #0
	mov ip, ip, lsr #0xc
	orr ip, ip, r4, lsl #20
	sub r7, r7, r3, asr #1
	ldr r6, [r0, #4]
	mov r4, r1
	ldr r3, [r0, #8]
	add r1, r6, r7
	sub r2, ip, r2, asr #1
	str r1, [r4, #0x4c]
	add r1, r3, r2
	str r1, [r4, #0x50]
	mov r1, #0x78000
	str r1, [r4, #0x60]
	str r1, [r4, #0x64]
	mov r1, #6
	strh r1, [r4, #0x2a]
	mov lr, #0
	strh lr, [r4, #8]
	ldr ip, [r0, #0x58]
	mov r5, #0x14
	ldrb r6, [ip]
	sub r1, r5, #0x15
	ldr r0, _02168D8C ; =0x00000333
	add r3, r6, #1
	and r2, r3, #0xff
	and r2, r2, #0x1f
	strb r2, [ip]
	add r2, r6, #8
	str r2, [r4, #0x10]
	str r5, [r4, #0x14]
	str r1, [r4, #4]
	str lr, [r4, #0x54]
	str r0, [r4, #0x58]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, ip}
	umull r5, lr, ip, r3
	mla lr, ip, r2, lr
	ldr r2, [r1, #0xc]
	ldr r6, [r1, #0x10]
	mla lr, r2, r3, lr
	ldr ip, [r1, #0x14]
	adds r5, r6, r5
	str r5, [r0, #0x448]
	adc r3, ip, lr
	mov r0, #7
	umull r0, r2, r3, r0
	str r3, [r1, #4]
	sub ip, r2, #3
	ldr r1, _02168D90 ; =0xB60B60B7
	mov r2, ip, lsl #0x10
	smull r0, r3, r1, r2
	add r3, r3, ip, lsl #16
	mov r0, r2, lsr #0x1f
	add r3, r0, r3, asr #8
	strh r3, [r4, #0x5e]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02168D84: .word MAIN_BSS_0210CEC8
_02168D88: .word 0x00007FFF
_02168D8C: .word 0x00000333
_02168D90: .word 0xB60B60B7
	arm_func_end _ZN21CFieldEffectDarkCloud15CRemainsEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

	arm_func_start _ZN21CFieldEffectDarkCloud16CRemainsAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN21CFieldEffectDarkCloud16CRemainsAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x02168D94
	stmdb sp!, {r4, lr}
	mov r4, r1
	ldr r2, [r4, #0x64]
	ldr r1, [r4, #0x60]
	ldr r0, _02168E34 ; =0x00000667
	sub r1, r2, r1
	umull ip, r3, r1, r0
	mov r1, r1, asr #0x1f
	mla r3, r1, r0, r3
	mov ip, ip, lsr #0xc
	orr ip, ip, r3, lsl #20
	mov r0, ip, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, ip, lsr #20
	mov r0, ip, lsl #0xc
	mov r3, r2, asr #0x1f
	bl _ll_div
	add r0, r0, #0x99
	add r0, r0, #0x1900
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	ldr r1, [r4, #0x60]
	cmp r1, #0x1e000
	ldmgeia sp!, {r4, pc}
	mov r0, #0x14000
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	mov r0, r3, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r3, lsr #20
	mov r0, r3, lsl #0xc
	mov r3, #0
	mov r2, #0x1e000
	bl _ll_div
	mov r0, r0, asr #0xc
	str r0, [r4, #0x14]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02168E34: .word 0x00000667
	arm_func_end _ZN21CFieldEffectDarkCloud16CRemainsAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

	arm_func_start _ZN28CFieldEffectDarkCloudFactory6CreateEi
_ZN28CFieldEffectDarkCloudFactory6CreateEi: ; 0x02168E38
	stmdb sp!, {r4, r5, r6, lr}
	mov r0, #0x154
	mov r5, r1
	bl _Znwm
	movs r4, r0
	beq _02168E5C
	mov r1, r5
	bl ov0_021675CC
	mov r4, r0
	arm_func_end _ZN28CFieldEffectDarkCloudFactory6CreateEi
_02168E5C:
	cmp r4, #0
	ldrne r0, _02168EE0 ; =MAIN_BSS_0210CA60
	ldrne r5, [r0]
	cmpne r5, #0
	beq _02168ED8
	add r0, r5, #0x27c
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0xc]
	blx r2
	add r1, r5, #0x27c
	mov r6, r0
	add r0, r1, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	add r1, r5, #0x27c
	mov r5, r0
	add r0, r1, #0x400
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	mov r2, r5
	mov r3, r6
	mov r1, r0
	mov r0, r4
	ldr ip, [r0]
	ldr ip, [ip, #0x68]
	blx ip
_02168ED8:
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02168EE0: .word MAIN_BSS_0210CA60

	arm_func_start _ZN21CFieldEffectDarkCloud10GetEmitterEv
_ZN21CFieldEffectDarkCloud10GetEmitterEv: ; 0x02168EE4
	add r0, r0, #0x38
	bx lr
	arm_func_end _ZN21CFieldEffectDarkCloud10GetEmitterEv

	arm_func_start _ZN21CFieldEffectDarkCloud13GetForceFieldEv
_ZN21CFieldEffectDarkCloud13GetForceFieldEv: ; 0x02168EEC
	add r0, r0, #0x2c
	bx lr
	arm_func_end _ZN21CFieldEffectDarkCloud13GetForceFieldEv

	arm_func_start _ZN21CFieldEffectDarkCloud12sub_02033028Ev
_ZN21CFieldEffectDarkCloud12sub_02033028Ev: ; 0x02168EF4
	mov r0, #0x14
	bx lr
	arm_func_end _ZN21CFieldEffectDarkCloud12sub_02033028Ev

	arm_func_start ov0_02168EFC
ov0_02168EFC: ; 0x02168EFC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02168EFC

	arm_func_start ov0_02168F10
ov0_02168F10: ; 0x02168F10
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02168F10

	arm_func_start ov0_02168F24
ov0_02168F24: ; 0x02168F24
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02168F24

	arm_func_start ov0_02168F38
ov0_02168F38: ; 0x02168F38
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02168F38

	arm_func_start ov0_02168F4C
ov0_02168F4C: ; 0x02168F4C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02168F4C

	arm_func_start ov0_02168F60
ov0_02168F60: ; 0x02168F60
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _02168FE0 ; =ptr_s_DWCi_MOV_WH_StepDataSharing_Wa_overlay_11_02169738_overlay_0_02179d14
	mov r1, #0
	str r0, [r5]
	strh r1, [r5, #0x38]
	strh r1, [r5, #0x3a]
	strh r1, [r5, #0x3c]
	strh r1, [r5, #0x3e]
	strh r1, [r5, #0x40]
	strh r1, [r5, #0x42]
	str r1, [r5, #0x60]
	str r1, [r5, #0x64]
	str r1, [r5, #0x68]
	str r1, [r5, #0x6c]
	strb r4, [r5, #0x70]
	str r1, [r5, #0x1c]
	mov r3, #0x1000
	str r1, [r5, #0x18]
	str r3, [r5, #0x24]
	str r3, [r5, #0x20]
	str r1, [r5, #0x2c]
	str r1, [r5, #0x28]
	str r3, [r5, #0x34]
	add r0, r5, #0x54
	mov r2, #0xa
	str r3, [r5, #0x30]
	bl MI_CpuFill8
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02168FE0: .word ptr_s_DWCi_MOV_WH_StepDataSharing_Wa_overlay_11_02169738_overlay_0_02179d14
	arm_func_end ov0_02168F60

	arm_func_start ov0_02168FE4
ov0_02168FE4: ; 0x02168FE4
	str r1, [r0, #0x60]
	str r2, [r0, #0x64]
	str r3, [r0, #0x68]
	bx lr
	arm_func_end ov0_02168FE4

	arm_func_start ov0_02168FF4
ov0_02168FF4: ; 0x02168FF4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #8
	mov r5, r0
	ldr r0, [r5, #0x68]
	mov r4, r1
	ldr r0, [r0, #0xb8]
	mov r6, r2
	bl NNS_G2dGetCellDataByIdx
	cmp r0, #0
	beq _02169028
	ldrh r1, [r0]
	cmp r1, r6
	bhi _02169034
	arm_func_end ov0_02168FF4
_02169028:
	add sp, sp, #8
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_02169034:
	mov r1, #6
	mul r1, r6, r1
	ldr r2, [r0, #4]
	ldr r0, _0216919C ; =0xC000C000
	ldrh r3, [r2, r1]
	add r6, r2, r1
	ldrh r1, [r6, #2]
	strh r3, [sp]
	ldrh r2, [r6, #4]
	strh r1, [sp, #2]
	ldr r1, [sp]
	strh r2, [sp, #4]
	and r1, r1, r0
	and r0, r1, #0xc0000000
	and ip, r1, #0xc000
	ldr r1, [sp]
	ldr r2, [sp, #4]
	mov lr, r1, lsl #3
	mov r2, r2, lsl #0x16
	mov r2, r2, lsr #0x16
	mov r6, r2, lsl #0x1b
	ldr r3, _021691A0 ; =NNSi_objSizeWTbl
	mov r7, ip, asr #0xe
	mov r0, r0, lsr #0x1e
	ldr r1, _021691A4 ; =NNSi_objSizeHTbl
	mov ip, r0, lsl #1
	add r3, r3, r7, lsl #3
	add r0, r1, r7, lsl #3
	ldrh r3, [ip, r3]
	ldrh ip, [ip, r0]
	mov r0, r6, lsr #0x18
	mov r2, r2, asr #5
	movs lr, lr, lsr #0x1f
	moveq r0, r0, lsl #0xc
	mov r1, r2, lsl #3
	add r6, r3, r6, lsr #24
	streq r0, [r5, #0x44]
	add r2, ip, r2, lsl #3
	moveq r0, r6, lsl #0xc
	beq _021690E8
	sub lr, r6, #1
	mov lr, lr, lsl #0xc
	sub r0, r0, #1
	str lr, [r5, #0x44]
	mov r0, r0, lsl #0xc
_021690E8:
	str r0, [r5, #0x4c]
	ldr r0, [sp]
	mov r0, r0, lsl #2
	movs r0, r0, lsr #0x1f
	moveq r0, r1, lsl #0xc
	streq r0, [r5, #0x48]
	moveq r0, r2, lsl #0xc
	beq _0216911C
	sub r0, r2, #1
	mov r2, r0, lsl #0xc
	sub r0, r1, #1
	str r2, [r5, #0x48]
	mov r0, r0, lsl #0xc
_0216911C:
	str r0, [r5, #0x50]
	ldr r0, [sp]
	mov r0, r0, lsl #7
	mov r1, r0, lsr #0x17
	cmp r1, #0xff
	orrgt r0, r1, #0xff00
	movgt r0, r0, lsl #0x10
	movgt r1, r0, asr #0x10
	ldr r0, [sp]
	strh r1, [r5, #0x3c]
	mov r0, r0, lsl #0x18
	mov r0, r0, lsr #0x18
	cmp r0, #0x7f
	orrgt r0, r0, #0xff00
	movgt r0, r0, lsl #0x10
	movgt r0, r0, asr #0x10
	strh r0, [r5, #0x3e]
	ldrsh r2, [r5, #0x3c]
	ldr r1, [sp, #4]
	mov r0, #1
	add r2, r2, r3
	strh r2, [r5, #0x40]
	ldrsh r2, [r5, #0x3e]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x1c
	add r2, r2, ip
	strh r2, [r5, #0x42]
	mov r1, r1, lsl #5
	strh r1, [r5, #0x3a]
	str r4, [r5, #0x6c]
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0216919C: .word 0xC000C000
_021691A0: .word NNSi_objSizeWTbl
_021691A4: .word NNSi_objSizeHTbl

	arm_func_start _ZN11CMeshSprite6RenderEP8Camera2D
_ZN11CMeshSprite6RenderEP8Camera2D: ; 0x021691A8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x48
	mov sl, r0
	ldr r0, [sl, #0x60]
	cmp r0, #0
	ldrne r0, [sl, #0x64]
	cmpne r0, #0
	addeq sp, sp, #0x48
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldrh r5, [r1, #0x28]
	ldr r2, _02169654 ; =0x04000450
	mov r3, #0
	str r3, [r2]
	ldr r0, [sl, #0x18]
	ldr r1, [sl, #0x1c]
	mov r0, r0, asr #0xc
	mov r1, r1, asr #0xc
	mov r0, r0, lsl r5
	mov r1, r1, lsl r5
	str r0, [r2, #0x20]
	str r1, [r2, #0x20]
	str r3, [r2, #0x20]
	ldr r3, [sl, #0x30]
	cmp r3, #0x1000
	ldreq r0, [sl, #0x34]
	cmpeq r0, #0x1000
	beq _02169230
	ldr r2, [sl, #0x34]
	ldr r1, _02169658 ; =0x0400046C
	mov r0, #0x1000
	str r3, [r1]
	str r2, [r1]
	str r0, [r1]
	arm_func_end _ZN11CMeshSprite6RenderEP8Camera2D
_02169230:
	ldr r0, [sl, #0x28]
	cmp r0, #0
	ldreq r0, [sl, #0x2c]
	cmpeq r0, #0
	beq _02169264
	add r0, sp, #0x24
	bl MTX_Identity33_
	ldr r1, [sl, #0x2c]
	add r0, sp, #0x24
	str r1, [sp, #0x28]
	ldr r1, [sl, #0x28]
	str r1, [sp, #0x30]
	bl G3_MultMtx33
_02169264:
	ldrsh r0, [sl, #0x38]
	cmp r0, #0
	beq _021692A0
	mov r0, r0, asr #4
	mov r1, r0, lsl #1
	add r0, r1, #1
	ldr r2, _0216965C ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	mov r0, r0, lsl #1
	ldrsh r1, [r2, r1]
	ldrsh r2, [r2, r0]
	add r0, sp, #0
	blx MTX_RotZ33_
	add r0, sp, #0
	bl G3_MultMtx33
_021692A0:
	ldr r3, [sl, #0x20]
	cmp r3, #0x1000
	ldreq r0, [sl, #0x24]
	cmpeq r0, #0x1000
	beq _021692CC
	ldr r2, [sl, #0x24]
	ldr r1, _02169658 ; =0x0400046C
	mov r0, #0x1000
	str r3, [r1]
	str r2, [r1]
	str r0, [r1]
_021692CC:
	ldrh r0, [sl, #8]
	ldr r4, _02169660 ; =0x04000480
	mov r1, #0
	str r0, [r4]
	ldr r0, [sl, #0xc]
	ldr r2, [sl, #0x10]
	mov r0, r0, lsl #4
	orr r0, r0, #0xc0
	ldr r3, [sl, #0x14]
	orr r0, r0, r2, lsl #24
	orr r0, r0, r3, lsl #16
	str r0, [r4, #0x24]
	ldr r4, [sl, #0x60]
	add r0, r4, #8
	bl NNS_G2dGetImageLocation
	ldr r1, [r4, #0x1c]
	ldr r2, [r4, #0x14]
	mov r1, r1, lsl #0x1a
	orr r0, r1, r0, lsr #3
	orr r0, r0, #0x40000000
	orr r0, r0, r2, lsl #20
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x24]
	orr r1, r0, r1, lsl #23
	ldr r0, _02169664 ; =0x040004A8
	orr r1, r1, r2, lsl #29
	str r1, [r0]
	ldr r0, [sl, #0x64]
	mov r1, #0
	add r0, r0, #8
	ldr r4, [r4, #0x1c]
	bl NNS_G2dGetImagePaletteLocation
	ldrh r1, [sl, #0x3a]
	cmp r4, #2
	add r1, r1, r0
	moveq r0, #1
	movne r0, #0
	rsb r0, r0, #4
	mov r2, r1, lsr r0
	ldr r1, _02169668 ; =0x040004AC
	mov r0, #3
	str r2, [r1]
	str r0, [r1, #0x54]
	ldrsh r1, [sl, #0x42]
	ldrsh r2, [sl, #0x3e]
	ldrb r0, [sl, #0x70]
	mov r1, r1, lsl r5
	mov r2, r2, lsl r5
	mov r6, r0, lsl #0xc
	mov r0, r1, lsl #0x10
	mov r7, r2, lsl #0x10
	mov r8, r0, asr #0x10
	sub sb, r8, r7, asr #16
	ldrsh r2, [sl, #0x3c]
	ldrsh r1, [sl, #0x40]
	mov r0, sb, asr #0x1f
	mov r4, r2, lsl r5
	mov r5, r1, lsl r5
	mov fp, r6, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, r6
	mov r3, fp
	orr r1, r1, sb, lsr #20
	mov r0, sb, lsl #0xc
	mov r4, r4, lsl #0x10
	mov r7, r7, asr #0x10
	mov r5, r5, lsl #0x10
	bl _ll_div
	ldr sb, [sl, #0x48]
	ldr r1, [sl, #0x50]
	mov r2, r6
	sub ip, r1, sb
	mov r3, fp
	mov r6, r0, lsl #0x10
	mov r0, ip, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, ip, lsr #20
	mov r0, ip, lsl #0xc
	bl _ll_div
	mov r1, sb, lsl #8
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r2, r1, lsr #0x10
	ldr r1, [sl, #0x4c]
	ldr fp, _0216966C ; =0x04000488
	mov r1, r1, lsl #8
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	orr r1, r1, r2, lsl #16
	str r1, [fp]
	ldr r1, [sl, #4]
	mov r3, r7, lsl #0x10
	mov r1, r1, lsl #0x10
	mov ip, r1, asr #0x10
	mov r1, r3, lsr #0x10
	mov r3, ip, lsl #0x10
	mov ip, r3, lsr #0x10
	ldrsh r3, [sl, #0x54]
	add r3, r3, r5, asr #16
	mov r3, r3, lsl #0x10
	mov r3, r3, asr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	orr r3, r3, r1, lsl #16
	str r3, [fp, #4]
	str ip, [fp, #4]
	ldr r3, [sl, #0x44]
	mov r3, r3, lsl #8
	mov r3, r3, asr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	orr r2, r3, r2, lsl #16
	str r2, [fp]
	ldrsh r2, [sl, #0x54]
	add r2, r2, r4, asr #16
	mov r2, r2, lsl #0x10
	mov r2, r2, asr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	orr r1, r2, r1, lsl #16
	str r1, [fp, #0xc]
	ldrb r2, [sl, #0x70]
	add r1, r7, r6, asr #16
	mov r1, r1, lsl #0x10
	sub r2, r2, #1
	cmp r2, #0
	mov r7, r1, asr #0x10
	add ip, sb, r0
	mov lr, #0
	ble _02169590
_021694D8:
	ldr r2, [sl, #0x4c]
	mov r1, ip, lsl #8
	mov r2, r2, lsl #8
	mov r1, r1, asr #0x10
	mov r2, r2, asr #0x10
	mov r1, r1, lsl #0x10
	mov r3, r2, lsl #0x10
	add r2, sl, lr, lsl #1
	mov sb, r1, lsr #0x10
	mov r1, r3, lsr #0x10
	orr r1, r1, sb, lsl #16
	str r1, [fp]
	ldrsh r1, [r2, #0x56]
	mov r3, r7, lsl #0x10
	mov r3, r3, lsr #0x10
	add r1, r1, r5, asr #16
	mov r1, r1, lsl #0x10
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	orr r1, r1, r3, lsl #16
	str r1, [fp, #0xc]
	ldr r1, [sl, #0x44]
	add r7, r7, r6, asr #16
	mov r1, r1, lsl #8
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	orr r1, r1, sb, lsl #16
	str r1, [fp]
	ldrsh r1, [r2, #0x56]
	mov r2, r7, lsl #0x10
	add lr, lr, #1
	add r1, r1, r4, asr #16
	mov r1, r1, lsl #0x10
	mov r1, r1, asr #0x10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	orr r1, r1, r3, lsl #16
	str r1, [fp, #0xc]
	ldrb r1, [sl, #0x70]
	mov r7, r2, asr #0x10
	add ip, ip, r0
	sub r1, r1, #1
	cmp lr, r1
	blt _021694D8
_02169590:
	ldr r0, [sl, #0x50]
	ldr r2, [sl, #0x4c]
	mov r0, r0, lsl #8
	mov r1, r0, asr #0x10
	mov r0, r2, lsl #8
	mov r1, r1, lsl #0x10
	mov r0, r0, asr #0x10
	mov r1, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r1, r1, lsl #0x10
	ldr r2, _0216966C ; =0x04000488
	orr r0, r1, r0, lsr #16
	str r0, [r2]
	ldrsh r3, [sl, #0x5c]
	mov r0, r8, lsl #0x10
	mov r1, r0, lsr #0x10
	add r0, r3, r5, asr #16
	mov r0, r0, lsl #0x10
	mov r0, r0, asr #0x10
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	orr r0, r0, r1, lsl #16
	str r0, [r2, #0xc]
	ldr r0, [sl, #0x50]
	ldr r5, [sl, #0x44]
	mov r0, r0, lsl #8
	mov r3, r0, asr #0x10
	mov r0, r5, lsl #8
	mov r3, r3, lsl #0x10
	mov r0, r0, asr #0x10
	mov r3, r3, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r3, r3, lsl #0x10
	orr r0, r3, r0, lsr #16
	str r0, [r2]
	ldrsh r3, [sl, #0x5c]
	mov r5, #0
	mov r0, #1
	add r3, r3, r4, asr #16
	mov r3, r3, lsl #0x10
	mov r3, r3, asr #0x10
	mov r3, r3, lsl #0x10
	mov r3, r3, lsr #0x10
	orr r1, r3, r1, lsl #16
	str r1, [r2, #0xc]
	str r5, [r2, #0x7c]
	str r5, [r2, #-0x40]
	add sp, sp, #0x48
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02169654: .word 0x04000450
_02169658: .word 0x0400046C
_0216965C: .word FX_SinCosTable_
_02169660: .word 0x04000480
_02169664: .word 0x040004A8
_02169668: .word 0x040004AC
_0216966C: .word 0x04000488

	arm_func_start ov0_02169670
ov0_02169670: ; 0x02169670
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0216972C ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r2, [r4]
	ldr r2, [r0]
	mov r5, r1
	ldr r2, [r2, #0x14]
	blx r2
	ldr r1, _02169730 ; =ptr_FUN_overlay_0_02169984_overlay_0_02179d80
	add r0, r4, #0x20
	str r1, [r4]
	str r5, [r4, #0x18]
	mov r2, #0
	mov r1, #1
	str r2, [r4, #0x1c]
	bl ov0_02168F60
	mov r0, #0
	str r0, [r4, #0x40]
	str r0, [r4, #0x44]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r0, r0, #0x1000
	add r1, r1, #0x1400
	ldr r3, [r0, #0x448]
	ldmib r1, {r2, ip}
	umull r5, lr, ip, r3
	mla lr, ip, r2, lr
	ldr r2, [r1, #0xc]
	ldr ip, [r1, #0x10]
	mla lr, r2, r3, lr
	ldr r3, [r1, #0x14]
	adds r5, ip, r5
	str r5, [r0, #0x448]
	adc r3, r3, lr
	mov r2, #9
	str r3, [r1, #4]
	umull r1, r2, r3, r2
	mov r0, #0xa0000
	mul r3, r2, r0
	ldr r1, _02169734 ; =0x6C16C16D
	mov r0, r4
	umull r1, r2, r3, r1
	sub r1, r3, r2
	add r2, r2, r1, lsr #1
	mov r2, r2, lsr #8
	strh r2, [r4, #0x58]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0216972C: .word _ZTV12CFieldEffect+8
_02169730: .word ptr_FUN_overlay_0_02169984_overlay_0_02179d80
_02169734: .word 0x6C16C16D
	arm_func_end ov0_02169670

	arm_func_start _ZN11CMeshSpriteD1Ev
_ZN11CMeshSpriteD1Ev: ; 0x02169738
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN11CMeshSpriteD1Ev

	arm_func_start ov0_0216974C
ov0_0216974C: ; 0x0216974C
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x20
	bl ov0_02168FE4
	add r0, r4, #0x20
	mov r1, #6
	mov r2, #0
	bl ov0_02168FF4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0216974C

	arm_func_start _ZN21CFieldEffectFireworks12sub_0203312CEii
_ZN21CFieldEffectFireworks12sub_0203312CEii: ; 0x02169770
	cmp r1, #1
	mov r3, #1
	beq _02169788
	cmp r1, #2
	beq _02169794
	b _021697A0
	arm_func_end _ZN21CFieldEffectFireworks12sub_0203312CEii
_02169788:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x38]
	b _021697A4
_02169794:
	mov r1, r2, lsl #0xc
	str r1, [r0, #0x3c]
	b _021697A4
_021697A0:
	mov r3, #0
_021697A4:
	mov r0, r3
	bx lr

	arm_func_start _ZN21CFieldEffectFireworks12ov0_02142264Ei
_ZN21CFieldEffectFireworks12ov0_02142264Ei: ; 0x021697AC
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	bl _ZN12CFieldEffect12ov0_02142264Ei
	mov r4, r0
	cmp r4, #1
	beq _021697DC
	cmp r4, #2
	beq _0216981C
	cmp r4, #3
	beq _0216982C
	b _02169868
	arm_func_end _ZN21CFieldEffectFireworks12ov0_02142264Ei
_021697DC:
	ldr r1, [r6, #4]
	cmp r1, #0
	movle r0, #0x2000
	ble _02169810
	ldr r0, [r6, #0x1c]
	mov r2, r0, lsl #0xc
	mov r0, r2, asr #0x1f
	mov r3, r0, lsl #0xd
	mov r0, r2, lsl #0xd
	orr r3, r3, r2, lsr #19
	mov r0, r0, lsr #0xc
	orr r0, r0, r3, lsl #20
	bl _s32_div_f
_02169810:
	str r0, [r6, #0x40]
	str r0, [r6, #0x44]
	b _02169868
_0216981C:
	mov r0, #0x2000
	str r0, [r6, #0x40]
	str r0, [r6, #0x44]
	b _02169868
_0216982C:
	ldr r1, [r6, #0xc]
	cmp r1, #0
	ble _02169868
	ldr r0, [r6, #0x10]
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	add r0, r0, #0x2000
	str r0, [r6, #0x40]
	str r0, [r6, #0x44]
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0xc]
	rsb r0, r0, r0, lsl #5
	bl _s32_div_f
	rsb r0, r0, #0x1f
	str r0, [r6, #0x34]
_02169868:
	cmp r4, #4
	cmpne r4, #0
	ldrne r0, [r6, #0x1c]
	addne r0, r0, r5
	strne r0, [r6, #0x1c]
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN21CFieldEffectFireworks12ov0_02142344EP8Camera2D
_ZN21CFieldEffectFireworks12ov0_02142344EP8Camera2D: ; 0x02169884
	stmdb sp!, {r3, lr}
	ldr r2, [r0, #0x14]
	cmp r2, #4
	cmpne r2, #0
	beq _021698B0
	ldr r2, [r0, #0x34]
	cmp r2, #0
	ble _021698B0
	ldr r2, [r0, #0x20]!
	ldr r2, [r2, #8]
	blx r2
	arm_func_end _ZN21CFieldEffectFireworks12ov0_02142344EP8Camera2D
_021698B0:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start _ZN21CFieldEffectFireworks12sub_02033440Et
_ZN21CFieldEffectFireworks12sub_02033440Et: ; 0x021698B8
	strh r1, [r0, #0x28]
	bx lr
	arm_func_end _ZN21CFieldEffectFireworks12sub_02033440Et

	arm_func_start _ZN28CFieldEffectFireworksFactory6CreateEi
_ZN28CFieldEffectFireworksFactory6CreateEi: ; 0x021698C0
	stmdb sp!, {r4, r5, r6, lr}
	mov r0, #0x94
	mov r5, r1
	bl _Znwm
	movs r4, r0
	beq _021698E4
	mov r1, r5
	bl ov0_02169670
	mov r4, r0
	arm_func_end _ZN28CFieldEffectFireworksFactory6CreateEi
_021698E4:
	cmp r4, #0
	beq _02169954
	ldr r0, _0216995C ; =MAIN_BSS_0210CA60
	mov r1, #0
	ldr r5, [r0]
	add r0, r5, #0x27c
	add r0, r0, #0x400
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	add r1, r5, #0x27c
	mov r6, r0
	add r0, r1, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	add r1, r5, #0x27c
	mov r5, r0
	add r0, r1, #0x400
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	mov r2, r5
	mov r3, r6
	mov r1, r0
	mov r0, r4
	bl ov0_0216974C
_02169954:
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0216995C: .word MAIN_BSS_0210CA60

	arm_func_start _ZN21CFieldEffectFireworks12sub_02033028Ev
_ZN21CFieldEffectFireworks12sub_02033028Ev: ; 0x02169960
	mov r0, #0x15
	bx lr
	arm_func_end _ZN21CFieldEffectFireworks12sub_02033028Ev

	arm_func_start ov0_02169968
ov0_02169968: ; 0x02169968
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_02169968

	arm_func_start _ZN21CFieldEffectFireworksD1Ev
_ZN21CFieldEffectFireworksD1Ev: ; 0x02169984
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x20
	bl _ZN10CPrimitiveD2Ev
	ldr r1, _021699B4 ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021699B4: .word _ZTV12CFieldEffect+8
	arm_func_end _ZN21CFieldEffectFireworksD1Ev

	arm_func_start ov0_021699B8
ov0_021699B8: ; 0x021699B8
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x20
	bl _ZN10CPrimitiveD2Ev
	ldr r1, _021699F0 ; =_ZTV12CFieldEffect+8
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
_021699F0: .word _ZTV12CFieldEffect+8
	arm_func_end ov0_021699B8

	arm_func_start ov0_021699F4
ov0_021699F4: ; 0x021699F4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_021699F4

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

	arm_func_start _ZN22CFieldEffectDarkShadow12sub_0203312CEii
_ZN22CFieldEffectDarkShadow12sub_0203312CEii: ; 0x02169C30
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
	arm_func_end _ZN22CFieldEffectDarkShadow12sub_0203312CEii
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

	arm_func_start _ZN22CFieldEffectDarkShadow12sub_02033028Ev
_ZN22CFieldEffectDarkShadow12sub_02033028Ev: ; 0x0216A42C
	mov r0, #0x16
	bx lr
	arm_func_end _ZN22CFieldEffectDarkShadow12sub_02033028Ev

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

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98: ; 0x0216A7E8
	ldr r1, [r1]
	str r1, [r0, #0x1c]
	ldr r1, [r0, #0x18]
	cmp r1, #0
	ldrne r0, [r0, #0x1c]
	strne r0, [r1, #0x18]
	bx lr
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98

	arm_func_start _ZN25CFieldEffectDarknessClear12sub_0203312CEii
_ZN25CFieldEffectDarknessClear12sub_0203312CEii: ; 0x0216A804
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
	arm_func_end _ZN25CFieldEffectDarknessClear12sub_0203312CEii
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

	arm_func_start _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12sub_0203312CEii
_ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12sub_0203312CEii: ; 0x0216AAC8
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
	arm_func_end _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12sub_0203312CEii
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

	arm_func_start _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE5func2Ev
_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE5func2Ev: ; 0x0216AE74
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE5func2Ev

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

	arm_func_start _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE6UpdateEi
_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE6UpdateEi: ; 0x0216BFFC
	mov r0, #0
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE6UpdateEi

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
	bl _Z12sub_02007254ll
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
	bl _Z12sub_02007254ll
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

	arm_func_start _ZN25CFieldEffectDarknessClear12sub_02033028Ev
_ZN25CFieldEffectDarknessClear12sub_02033028Ev: ; 0x0216C5FC
	mov r0, #0x17
	bx lr
	arm_func_end _ZN25CFieldEffectDarknessClear12sub_02033028Ev

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

	arm_func_start _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED0Ev
_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED0Ev: ; 0x0216C6BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED0Ev

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

	arm_func_start _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED1Ev
_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED1Ev: ; 0x0216CB50
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED1Ev

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

	arm_func_start _ZN22CFieldEffectAirBubbles12sub_0203312CEii
_ZN22CFieldEffectAirBubbles12sub_0203312CEii: ; 0x0216CDB8
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
	arm_func_end _ZN22CFieldEffectAirBubbles12sub_0203312CEii
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

	arm_func_start _ZN22CFieldEffectAirBubbles12sub_02033028Ev
_ZN22CFieldEffectAirBubbles12sub_02033028Ev: ; 0x0216D2A4
	mov r0, #0x28
	bx lr
	arm_func_end _ZN22CFieldEffectAirBubbles12sub_02033028Ev

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

	arm_func_start _ZN17UnkClass_0216D2D4C1Ev
_ZN17UnkClass_0216D2D4C1Ev: ; 0x0216D2D4
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	bx lr
	arm_func_end _ZN17UnkClass_0216D2D4C1Ev

	arm_func_start _ZN17UnkClass_0216D2D45AllocEm
_ZN17UnkClass_0216D2D45AllocEm: ; 0x0216D2E4
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r2, #0
	add r1, r1, #0xff
	ldr r8, [r0]
	mov lr, #1
	mov r6, r1, lsr #8
	mov r3, r2
	mov r5, r2
	mov r1, lr
	arm_func_end _ZN17UnkClass_0216D2D45AllocEm
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

	arm_func_start _ZN17UnkClass_0216D2D44FreeEPv
_ZN17UnkClass_0216D2D44FreeEPv: ; 0x0216D3D0
	add r2, r0, #8
	sub r1, r1, r2
	mov r1, r1, asr #8
	mov r2, #1
	movs ip, r2, lsl r1
	bxeq lr
	mov r1, #0
	arm_func_end _ZN17UnkClass_0216D2D44FreeEPv
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

	arm_func_start _ZN17UnkClass_0216D420C1Ev
_ZN17UnkClass_0216D420C1Ev: ; 0x0216D420
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	bx lr
	arm_func_end _ZN17UnkClass_0216D420C1Ev

	arm_func_start _ZN17UnkClass_0216D420D1Ev
_ZN17UnkClass_0216D420D1Ev: ; 0x0216D430
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0216D450
	bl _ZdaPv
	mov r0, #0
	str r0, [r4]
	arm_func_end _ZN17UnkClass_0216D420D1Ev
_0216D450:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_0216D4204InitEP17UnkClass_02008788m
_ZN17UnkClass_0216D4204InitEP17UnkClass_02008788m: ; 0x0216D458
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
	arm_func_end _ZN17UnkClass_0216D4204InitEP17UnkClass_02008788m
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
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	ldr r1, [r8]
	add r1, r1, r6, lsl #2
	strh r0, [r1, #2]
	ldr r0, [r8, #4]
	add r6, r6, #1
	cmp r6, r0
	blo _0216D4D8
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start _ZN17UnkClass_0216D4207ReleaseEP17UnkClass_02008788
_ZN17UnkClass_0216D4207ReleaseEP17UnkClass_02008788: ; 0x0216D508
	stmdb sp!, {r4, lr}
	mov r4, r0
	cmp r1, #0
	beq _0216D520
	mov r0, r1
	bl _ZN17UnkClass_0200878812sub_02008BF0Ev
	arm_func_end _ZN17UnkClass_0216D4207ReleaseEP17UnkClass_02008788
_0216D520:
	ldr r0, [r4]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZdaPv
	mov r0, #0
	str r0, [r4]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_0216D4207AcquireEv
_ZN17UnkClass_0216D4207AcquireEv: ; 0x0216D53C
	stmdb sp!, {r3, lr}
	ldr lr, [r0]
	mov r2, #0
	cmp lr, #0
	beq _0216D590
	ldr ip, [r0, #4]
	mov r3, r2
	cmp ip, #0
	bls _0216D590
	arm_func_end _ZN17UnkClass_0216D4207AcquireEv
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

	arm_func_start _ZN17UnkClass_0216D4204FreeEt
_ZN17UnkClass_0216D4204FreeEt: ; 0x0216D598
	stmdb sp!, {r4, lr}
	ldr r2, [r0]
	cmp r2, #0
	ldmeqia sp!, {r4, pc}
	ldr r2, [r0, #4]
	mov r4, #0
	cmp r2, #0
	ldmlsia sp!, {r4, pc}
	mov r3, r4
	arm_func_end _ZN17UnkClass_0216D4204FreeEt
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
	bl _ZN17UnkClass_02007AA4C1Ev
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
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
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
	bl _ZN17UnkClass_0200878812sub_02008B80Et
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
	bl _ZN17UnkClass_0200878812sub_02008B80Et
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
	bl _ZN17UnkClass_0200878812sub_02008828Et
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

	arm_func_start _ZN17CFieldEffectLaser12sub_0203312CEii
_ZN17CFieldEffectLaser12sub_0203312CEii: ; 0x0216DE30
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
	arm_func_end _ZN17CFieldEffectLaser12sub_0203312CEii
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

	arm_func_start _ZN17CFieldEffectLaser12sub_02033028Ev
_ZN17CFieldEffectLaser12sub_02033028Ev: ; 0x0216E10C
	mov r0, #3
	bx lr
	arm_func_end _ZN17CFieldEffectLaser12sub_02033028Ev

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

	arm_func_start _ZN24CFieldEffectRisingPhoton12sub_0203312CEii
_ZN24CFieldEffectRisingPhoton12sub_0203312CEii: ; 0x0216E324
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
	arm_func_end _ZN24CFieldEffectRisingPhoton12sub_0203312CEii
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

	arm_func_start _ZN24CFieldEffectRisingPhoton12sub_020332A4Ev
_ZN24CFieldEffectRisingPhoton12sub_020332A4Ev: ; 0x0216E5CC
	ldrb r0, [r0, #0x86]
	cmp r0, #2
	movhs r0, #1
	movlo r0, #0
	bx lr
	arm_func_end _ZN24CFieldEffectRisingPhoton12sub_020332A4Ev

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
	bl _ZN8Camera2D12sub_020038A8EP9Rectanglel
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

	arm_func_start _ZN24CFieldEffectRisingPhoton12sub_02033440Et
_ZN24CFieldEffectRisingPhoton12sub_02033440Et: ; 0x0216EB28
	strh r1, [r0, #0x84]
	bx lr
	arm_func_end _ZN24CFieldEffectRisingPhoton12sub_02033440Et

	arm_func_start _ZN24CFieldEffectRisingPhoton12sub_02033028Ev
_ZN24CFieldEffectRisingPhoton12sub_02033028Ev: ; 0x0216EB30
	mov r0, #0x18
	bx lr
	arm_func_end _ZN24CFieldEffectRisingPhoton12sub_02033028Ev

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

	arm_func_start _ZN25CFieldEffectVolcanicSteam12ov0_02142398EP17UnkClass_0211E3FC
_ZN25CFieldEffectVolcanicSteam12ov0_02142398EP17UnkClass_0211E3FC: ; 0x0216EBEC
	ldr ip, _0216EBF8 ; =ov0_0216EC94
	add r0, r0, #0x78
	bx ip
	.align 2, 0
_0216EBF8: .word ov0_0216EC94
	arm_func_end _ZN25CFieldEffectVolcanicSteam12ov0_02142398EP17UnkClass_0211E3FC

	arm_func_start _ZN25CFieldEffectVolcanicSteam12sub_0203312CEii
_ZN25CFieldEffectVolcanicSteam12sub_0203312CEii: ; 0x0216EBFC
	ldr ip, _0216EC10 ; =_ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE12sub_0203312CEii
	cmp r1, #2
	moveq r3, r2, lsl #0xc
	streq r3, [r0, #0x80]
	bx ip
	.align 2, 0
_0216EC10: .word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE12sub_0203312CEii
	arm_func_end _ZN25CFieldEffectVolcanicSteam12sub_0203312CEii

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
_0216ECA8: .word _ZN17UnkClass_0211E3FC12sub_0200912CEP11CDrawObject
	arm_func_end ov0_0216EC94

	arm_func_start _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject12sub_020091D4EP8Camera2Di
_ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject12sub_020091D4EP8Camera2Di: ; 0x0216ECAC
	str r2, [r0, #0xc]
	ldr r1, [r0, #0x10]
	cmp r1, #0
	ldrne r0, [r0, #0xc]
	strne r0, [r1, #0x30]
	mov r0, #1
	bx lr
	arm_func_end _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject12sub_020091D4EP8Camera2Di

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

	arm_func_start _ZN25CFieldEffectVolcanicSteam12sub_02033028Ev
_ZN25CFieldEffectVolcanicSteam12sub_02033028Ev: ; 0x0216EF00
	mov r0, #0x19
	bx lr
	arm_func_end _ZN25CFieldEffectVolcanicSteam12sub_02033028Ev

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

	arm_func_start _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE12sub_0203312CEii
_ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE12sub_0203312CEii: ; 0x0216EFFC
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
	arm_func_end _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE12sub_0203312CEii
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

	arm_func_start _ZN23CFieldEffectFuwanteWind12sub_0203312CEii
_ZN23CFieldEffectFuwanteWind12sub_0203312CEii: ; 0x0216F7B0
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
	arm_func_end _ZN23CFieldEffectFuwanteWind12sub_0203312CEii
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
	bl _ZN17UnkClass_0200878812sub_02008828Et
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
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	ldr r2, [sb, #0x38]
	mov r1, r7, lsl #1
	mov r8, sl
	strh r0, [r2, r1]
_0216FF30:
	mov r0, r6
	bl _ZN17UnkClass_0200878812sub_020089ECEv
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
	bl _ZN17UnkClass_0200878812sub_02008B80Et
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

	arm_func_start _ZN23CFieldEffectFuwanteWind12sub_02033028Ev
_ZN23CFieldEffectFuwanteWind12sub_02033028Ev: ; 0x021700B4
	mov r0, #0x1a
	bx lr
	arm_func_end _ZN23CFieldEffectFuwanteWind12sub_02033028Ev

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

	arm_func_start _ZN24CFieldEffectManpuDarkrieC1EPN18CFieldEffectManage17CResidentResourceEP17UnkClass_0216D420ii
_ZN24CFieldEffectManpuDarkrieC1EPN18CFieldEffectManage17CResidentResourceEP17UnkClass_0216D420ii: ; 0x021700E4
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
	arm_func_end _ZN24CFieldEffectManpuDarkrieC1EPN18CFieldEffectManage17CResidentResourceEP17UnkClass_0216D420ii
_021701A8:
	ldr r0, [r6, #0x1b4]
	bl _ZN17UnkClass_0216D4207AcquireEv
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
	bl _ZN17UnkClass_0200878812sub_02008A38Et
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
	bl _ZN17UnkClass_0216D4204FreeEt
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
	bl _ZN17UnkClass_0216D4204FreeEt
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
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	add r0, r8, r5, lsl #1
	add r0, r0, #0x100
	ldrh r1, [r0, #0xa8]
	mov r0, r4
	bl _ZN17UnkClass_0200878812sub_02008828Et
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

	arm_func_start _ZN19CFieldEffectGlitter12sub_0203312CEii
_ZN19CFieldEffectGlitter12sub_0203312CEii: ; 0x021709D0
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
	arm_func_end _ZN19CFieldEffectGlitter12sub_0203312CEii
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

	arm_func_start _ZN19CFieldEffectGlitter12sub_02033440Et
_ZN19CFieldEffectGlitter12sub_02033440Et: ; 0x02170E30
	strh r1, [r0, #0x30]
	bx lr
	arm_func_end _ZN19CFieldEffectGlitter12sub_02033440Et

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

	arm_func_start _ZN19CFieldEffectGlitter12sub_020332A4Ev
_ZN19CFieldEffectGlitter12sub_020332A4Ev: ; 0x02171020
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
	arm_func_end _ZN19CFieldEffectGlitter12sub_020332A4Ev

	arm_func_start _ZN19CFieldEffectGlitter12sub_02033028Ev
_ZN19CFieldEffectGlitter12sub_02033028Ev: ; 0x02171058
	mov r0, #0x1b
	bx lr
	arm_func_end _ZN19CFieldEffectGlitter12sub_02033028Ev

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

	arm_func_start _ZN26CFieldEffectBlackStoneAura12sub_0203312CEii
_ZN26CFieldEffectBlackStoneAura12sub_0203312CEii: ; 0x02171228
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
	arm_func_end _ZN26CFieldEffectBlackStoneAura12sub_0203312CEii
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

	arm_func_start _ZN26CFieldEffectBlackStoneAura12sub_020332A4Ev
_ZN26CFieldEffectBlackStoneAura12sub_020332A4Ev: ; 0x021718A0
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
	arm_func_end _ZN26CFieldEffectBlackStoneAura12sub_020332A4Ev

	arm_func_start _ZN26CFieldEffectBlackStoneAura12sub_02033028Ev
_ZN26CFieldEffectBlackStoneAura12sub_02033028Ev: ; 0x021718D8
	mov r0, #0x1c
	bx lr
	arm_func_end _ZN26CFieldEffectBlackStoneAura12sub_02033028Ev

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

	arm_func_start _ZN24CFieldEffectSpaceCrevice12sub_020333D8Eii
_ZN24CFieldEffectSpaceCrevice12sub_020333D8Eii: ; 0x02171BD4
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
	arm_func_end _ZN24CFieldEffectSpaceCrevice12sub_020333D8Eii

	arm_func_start _ZN24CFieldEffectSpaceCrevice12sub_0203312CEii
_ZN24CFieldEffectSpaceCrevice12sub_0203312CEii: ; 0x02171C08
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
	arm_func_end _ZN24CFieldEffectSpaceCrevice12sub_0203312CEii
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

	arm_func_start _ZN24CFieldEffectSpaceCrevice12sub_02033440Et
_ZN24CFieldEffectSpaceCrevice12sub_02033440Et: ; 0x021721A0
	strh r1, [r0, #0x28]
	strh r1, [r0, #0x8c]
	bx lr
	arm_func_end _ZN24CFieldEffectSpaceCrevice12sub_02033440Et

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

	arm_func_start _ZN24CFieldEffectSpaceCrevice12ov0_02142398EP17UnkClass_0211E3FC
_ZN24CFieldEffectSpaceCrevice12ov0_02142398EP17UnkClass_0211E3FC: ; 0x021722D4
	ldr ip, _021722E8 ; =FUN_0200912C
	mov r2, r0
	mov r0, r1
	add r1, r2, #0x180
	bx ip
	.align 2, 0
_021722E8: .word _ZN17UnkClass_0211E3FC12sub_0200912CEP11CDrawObject
	arm_func_end _ZN24CFieldEffectSpaceCrevice12ov0_02142398EP17UnkClass_0211E3FC

	arm_func_start _ZN24CFieldEffectSpaceCrevice17CEffectDrawObject12sub_020091D4EP8Camera2Di
_ZN24CFieldEffectSpaceCrevice17CEffectDrawObject12sub_020091D4EP8Camera2Di: ; 0x021722EC
	stmdb sp!, {r3, lr}
	str r2, [r0, #0xc]
	ldr r0, [r0, #0x10]
	cmp r0, #0
	beq _02172304
	bl ov0_02171F30
	arm_func_end _ZN24CFieldEffectSpaceCrevice17CEffectDrawObject12sub_020091D4EP8Camera2Di
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
	bl _ZN17UnkClass_02041D984BindE15GXTexPlttColor08GXTexGen
	b _02172994
	arm_func_end _ZN19CFEFRasterTransform6RenderEP8Camera2D
_0217298C:
	mov r2, r1
	bl _ZN17UnkClass_02041D984BindE15GXTexPlttColor08GXTexGen
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

	arm_func_start _ZN24CFieldEffectSpaceCrevice12sub_020332A4Ev
_ZN24CFieldEffectSpaceCrevice12sub_020332A4Ev: ; 0x02172B94
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, #1
	mov r5, #0
	ldr lr, _02172BF0 ; =0x027FFC3C
	mov r1, r5
	mov r2, r4
	arm_func_end _ZN24CFieldEffectSpaceCrevice12sub_020332A4Ev
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

	arm_func_start _ZN24CFieldEffectSpaceCrevice12sub_02033028Ev
_ZN24CFieldEffectSpaceCrevice12sub_02033028Ev: ; 0x02172BF4
	mov r0, #0x1e
	bx lr
	arm_func_end _ZN24CFieldEffectSpaceCrevice12sub_02033028Ev

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


    .global DAT_overlay_0_02172ee8
DAT_overlay_0_02172ee8: ; 0x02172EE8
	.byte 0x0A, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172ef4
DAT_overlay_0_02172ef4: ; 0x02172EF4
	.byte 0x1F, 0x00

    .global DAT_overlay_0_02172ef6
DAT_overlay_0_02172ef6: ; 0x02172EF6
	.byte 0x14, 0x00

    .global DAT_overlay_0_02172ef8
DAT_overlay_0_02172ef8: ; 0x02172EF8
	.byte 0x0A, 0x00

    .global DAT_overlay_0_02172efa
DAT_overlay_0_02172efa: ; 0x02172EFA
	.byte 0x00, 0x00

    .global DAT_overlay_0_02172efc
DAT_overlay_0_02172efc: ; 0x02172EFC
	.byte 0x1F, 0x00

    .global DAT_overlay_0_02172efe
DAT_overlay_0_02172efe: ; 0x02172EFE
	.byte 0x1F, 0x7C

    .global DAT_overlay_0_02172f00
DAT_overlay_0_02172f00: ; 0x02172F00
	.byte 0x00, 0x20, 0x00, 0x00

    .global DAT_overlay_0_02172f04
DAT_overlay_0_02172f04: ; 0x02172F04
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172f08
DAT_overlay_0_02172f08: ; 0x02172F08
	.byte 0x1F

    .global DAT_overlay_0_02172f09
DAT_overlay_0_02172f09: ; 0x02172F09
	.byte 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x1F
	.byte 0x1F, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x1F, 0x1F, 0x1F, 0x1F, 0x0C, 0x00, 0x1F, 0x00, 0x00, 0x00
	.byte 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x80, 0x00, 0x00

    .global DAT_overlay_0_02172f28
DAT_overlay_0_02172f28: ; 0x02172F28
	.byte 0x1F

    .global DAT_overlay_0_02172f29
DAT_overlay_0_02172f29: ; 0x02172F29
	.byte 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x1F
	.byte 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x1F, 0x00, 0x00

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

    .global PTR_ptr_FUN_020835bc_overlay_0_02178bc0
PTR_ptr_FUN_020835bc_overlay_0_02178bc0: ; 0x02178BC0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_21CFieldEffectPoisonGas_overlay_0_02178bd8
	.word _ZTI17CFieldEffectActor

    .global PTR_ptr_FUN_020835bc_overlay_0_02178bcc
PTR_ptr_FUN_020835bc_overlay_0_02178bcc: ; 0x02178BCC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_28CFieldEffectPoisonGasFactory_overlay_0_02178bf0
	.word _ZTI19CFieldEffectFactory

    .global s_21CFieldEffectPoisonGas_overlay_0_02178bd8
s_21CFieldEffectPoisonGas_overlay_0_02178bd8: ; 0x02178BD8
	.asciz "21CFieldEffectPoisonGas"

    .global s_28CFieldEffectPoisonGasFactory_overlay_0_02178bf0
s_28CFieldEffectPoisonGasFactory_overlay_0_02178bf0: ; 0x02178BF0
	.asciz "28CFieldEffectPoisonGasFactory"

    .global DAT_overlay_0_02178C0F
DAT_overlay_0_02178C0F:
	.byte 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178bcc

    .global ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18
ptr_FUN_overlay_0_0215f34c_overlay_0_02178c18: ; 0x02178C18
	.word _ZN28CFieldEffectPoisonGasFactoryD1Ev

    .global ptr_FUN_overlay_0_0215f374_overlay_0_02178c1c
ptr_FUN_overlay_0_0215f374_overlay_0_02178c1c: ; 0x02178C1C
	.word ov0_0215F374

    .global ptr_FUN_overlay_0_0215f3a4_overlay_0_02178c20
ptr_FUN_overlay_0_0215f3a4_overlay_0_02178c20: ; 0x02178C20
	.word _ZN28CFieldEffectPoisonGasFactory6CreateEi
	.word _ZN28CFieldEffectPoisonGasFactory6UpdateEi
	.word _ZN28CFieldEffectPoisonGasFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178bc0

    .global ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38
ptr_FUN_overlay_0_0215eb28_overlay_0_02178c38: ; 0x02178C38
	.word _ZN21CFieldEffectPoisonGasD1Ev

    .global ptr_FUN_overlay_0_0215eba8_overlay_0_02178c3c
ptr_FUN_overlay_0_0215eba8_overlay_0_02178c3c: ; 0x02178C3C
	.word ov0_0215EBA8
	.word _ZN21CFieldEffectPoisonGas12ov0_021423A4Ev
	.word _ZN21CFieldEffectPoisonGas12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02178c4c
ptr_FUN_overlay_0_021421d0_overlay_0_02178c4c: ; 0x02178C4C
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02178c50
ptr_FUN_overlay_0_02142380_overlay_0_02178c50: ; 0x02178C50
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0215ef20_overlay_0_02178c54
ptr_FUN_overlay_0_0215ef20_overlay_0_02178c54: ; 0x02178C54
	.word _ZN21CFieldEffectPoisonGas12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0215ec94_overlay_0_02178c5c
ptr_FUN_overlay_0_0215ec94_overlay_0_02178c5c: ; 0x02178C5C
	.word _ZN21CFieldEffectPoisonGas12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0215edd0_overlay_0_02178c60
ptr_FUN_overlay_0_0215edd0_overlay_0_02178c60: ; 0x02178C60
	.word _ZN21CFieldEffectPoisonGas12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN21CFieldEffectPoisonGas12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi

    .global ptr_FUN_overlay_0_0215f118_overlay_0_02178c8c
ptr_FUN_overlay_0_0215f118_overlay_0_02178c8c: ; 0x02178C8C
	.word _ZN21CFieldEffectPoisonGas12ov0_02142390EPvS0_

    .global ptr_FUN_overlay_0_0215f1ec_overlay_0_02178c90
ptr_FUN_overlay_0_0215f1ec_overlay_0_02178c90: ; 0x02178C90
	.word _ZN21CFieldEffectPoisonGas12ov0_02142388EPKv

    .global PTR_ptr_FUN_020835bc_overlay_0_02178c94
PTR_ptr_FUN_020835bc_overlay_0_02178c94: ; 0x02178C94
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N17CFieldEffectSpray20CWaveParti_overlay_0_02178d44
	.word _ZTI21TFieldParticleEmitterI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02178ca0
PTR_ptr_FUN_020835bc_overlay_0_02178ca0: ; 0x02178CA0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldEffectSpray_overlay_0_02178cc4
	.word _ZTI17CFieldEffectActor

    .global PTR_ptr_FUN_020835bc_overlay_0_02178cac
PTR_ptr_FUN_020835bc_overlay_0_02178cac: ; 0x02178CAC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N17CFieldEffectSpray21CWaveParti_overlay_0_02178d70
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02178cb8
PTR_ptr_FUN_020835bc_overlay_0_02178cb8: ; 0x02178CB8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectSprayFactory_overlay_0_02178cec
	.word _ZTI19CFieldEffectFactory

    .global s_17CFieldEffectSpray_overlay_0_02178cc4
s_17CFieldEffectSpray_overlay_0_02178cc4: ; 0x02178CC4
	.asciz "17CFieldEffectSpray"

    .global DAT_overlay_0_02178CD8
DAT_overlay_0_02178CD8:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178cac

    .global PTR_LAB_overlay_0_0215f858_overlay_0_02178ce0
PTR_LAB_overlay_0_0215f858_overlay_0_02178ce0: ; 0x02178CE0
	.word _ZN17CFieldEffectSpray21CWaveParticleAnimatorD1Ev

    .global ptr_FUN_overlay_0_021601ac_overlay_0_02178ce4
ptr_FUN_overlay_0_021601ac_overlay_0_02178ce4: ; 0x02178CE4
	.word ov0_021601AC

    .global ptr_FUN_overlay_0_021600f8_overlay_0_02178ce8
ptr_FUN_overlay_0_021600f8_overlay_0_02178ce8: ; 0x02178CE8
	.word _ZN17CFieldEffectSpray21CWaveParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_24CFieldEffectSprayFactory_overlay_0_02178cec
s_24CFieldEffectSprayFactory_overlay_0_02178cec: ; 0x02178CEC
	.asciz "24CFieldEffectSprayFactory"

    .global DAT_overlay_0_02178D07
DAT_overlay_0_02178D07:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02178c94

    .global PTR_LAB_overlay_0_0215f854_overlay_0_02178d10
PTR_LAB_overlay_0_0215f854_overlay_0_02178d10: ; 0x02178D10
	.word _ZN17CFieldEffectSpray20CWaveParticleEmitterD1Ev

    .global ptr_FUN_overlay_0_02160198_overlay_0_02178d14
ptr_FUN_overlay_0_02160198_overlay_0_02178d14: ; 0x02178D14
	.word ov0_02160198

    .global ptr_FUN_overlay_0_021600bc_overlay_0_02178d18
ptr_FUN_overlay_0_021600bc_overlay_0_02178d18: ; 0x02178D18
	.word _ZN17CFieldEffectSpray20CWaveParticleEmitter5func2Ev

    .global ptr_FUN_overlay_0_0215feec_overlay_0_02178d1c
ptr_FUN_overlay_0_0215feec_overlay_0_02178d1c: ; 0x02178D1C
	.word _ZN17CFieldEffectSpray20CWaveParticleEmitter6UpdateEi

    .global ptr_FUN_overlay_0_02160004_overlay_0_02178d20
ptr_FUN_overlay_0_02160004_overlay_0_02178d20: ; 0x02178D20
	.word _ZN17CFieldEffectSpray20CWaveParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
	.global _ZTV24CFieldEffectSprayFactory
_ZTV24CFieldEffectSprayFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178cb8

    .global PTR_LAB_overlay_0_02151834_overlay_0_02178d2c
PTR_LAB_overlay_0_02151834_overlay_0_02178d2c: ; 0x02178D2C
	.word _ZN24CFieldEffectSprayFactoryD1Ev

    .global ptr_FUN_overlay_0_021601c0_overlay_0_02178d30
ptr_FUN_overlay_0_021601c0_overlay_0_02178d30: ; 0x02178D30
	.word ov0_021601C0

    .global ptr_FUN_overlay_0_0216016c_overlay_0_02178d34
ptr_FUN_overlay_0_0216016c_overlay_0_02178d34: ; 0x02178D34
	.word _ZN24CFieldEffectSprayFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_N17CFieldEffectSpray20CWaveParti_overlay_0_02178d44
s_N17CFieldEffectSpray20CWaveParti_overlay_0_02178d44: ; 0x02178D44
	.asciz "N17CFieldEffectSpray20CWaveParticleEmitterE"

    .global s_N17CFieldEffectSpray21CWaveParti_overlay_0_02178d70
s_N17CFieldEffectSpray21CWaveParti_overlay_0_02178d70: ; 0x02178D70
	.asciz "N17CFieldEffectSpray21CWaveParticleAnimatorE"

    .global DAT_overlay_0_02178D9D
DAT_overlay_0_02178D9D:
	.byte 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178ca0

    .global ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8
ptr_FUN_overlay_0_0215f85c_overlay_0_02178da8: ; 0x02178DA8
	.word _ZN17CFieldEffectSprayD1Ev

    .global ptr_FUN_overlay_0_0215f93c_overlay_0_02178dac
ptr_FUN_overlay_0_0215f93c_overlay_0_02178dac: ; 0x02178DAC
	.word ov0_0215F93C

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02178db0
ptr_FUN_overlay_0_021423a4_overlay_0_02178db0: ; 0x02178DB0
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectSpray12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02178dbc
ptr_FUN_overlay_0_021421d0_overlay_0_02178dbc: ; 0x02178DBC
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02178dc0
ptr_FUN_overlay_0_02142380_overlay_0_02178dc0: ; 0x02178DC0
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0215feb0_overlay_0_02178dc4
ptr_FUN_overlay_0_0215feb0_overlay_0_02178dc4: ; 0x02178DC4
	.word _ZN17CFieldEffectSpray12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0215fa24_overlay_0_02178dcc
ptr_FUN_overlay_0_0215fa24_overlay_0_02178dcc: ; 0x02178DCC
	.word _ZN17CFieldEffectSpray12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0215fd34_overlay_0_02178dd0
ptr_FUN_overlay_0_0215fd34_overlay_0_02178dd0: ; 0x02178DD0
	.word _ZN17CFieldEffectSpray12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0215fdc4_overlay_0_02178de0
ptr_FUN_overlay_0_0215fdc4_overlay_0_02178de0: ; 0x02178DE0
	.word _ZN17CFieldEffectSpray12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global s_effect_anime_data_is_null_overlay_0_02178e04
s_effect_anime_data_is_null_overlay_0_02178e04: ; 0x02178E04
	.asciz "effect anime data is null"

    .global DAT_overlay_0_02178E1E
DAT_overlay_0_02178E1E:
	.byte 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_0_02178e20
PTR_ptr_FUN_020835bc_overlay_0_02178e20: ; 0x02178E20
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_23CFieldEffectFireFactory_overlay_0_02178e78
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_02178e2c
PTR_ptr_FUN_020835bc_overlay_0_02178e2c: ; 0x02178E2C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N16CFieldEffectFire17CParticleAn_overlay_0_02178ef8
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02178e38
PTR_ptr_FUN_020835bc_overlay_0_02178e38: ; 0x02178E38
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CFieldEffectFire_overlay_0_02178e50
	.word _ZTI20TFieldEffectParticleI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02178e44
PTR_ptr_FUN_020835bc_overlay_0_02178e44: ; 0x02178E44
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N16CFieldEffectFire16CParticleEm_overlay_0_02178ed0
	.word _ZTI25TFieldParticleRectEmitterI15CSoftwareSpriteE

    .global s_16CFieldEffectFire_overlay_0_02178e50
s_16CFieldEffectFire_overlay_0_02178e50: ; 0x02178E50
	.asciz "16CFieldEffectFire"

    .global DAT_overlay_0_02178E63
DAT_overlay_0_02178E63:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02178e2c

    .global PTR_LAB_overlay_0_021603ac_overlay_0_02178e6c
PTR_LAB_overlay_0_021603ac_overlay_0_02178e6c: ; 0x02178E6C
	.word _ZN16CFieldEffectFire17CParticleAnimatorD1Ev

    .global ptr_FUN_overlay_0_02160e28_overlay_0_02178e70
ptr_FUN_overlay_0_02160e28_overlay_0_02178e70: ; 0x02178E70
	.word ov0_02160E28
	.word _ZN16CFieldEffectFire17CParticleAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_23CFieldEffectFireFactory_overlay_0_02178e78
s_23CFieldEffectFireFactory_overlay_0_02178e78: ; 0x02178E78
	.asciz "23CFieldEffectFireFactory"

    .global DAT_overlay_0_02178E92
DAT_overlay_0_02178E92:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02178e44

    .global PTR_LAB_overlay_0_021603a8_overlay_0_02178e9c
PTR_LAB_overlay_0_021603a8_overlay_0_02178e9c: ; 0x02178E9C
	.word _ZN16CFieldEffectFire16CParticleEmitterD1Ev

    .global ptr_FUN_overlay_0_02160e14_overlay_0_02178ea0
ptr_FUN_overlay_0_02160e14_overlay_0_02178ea0: ; 0x02178EA0
	.word ov0_02160E14
	.word _ZN16CFieldEffectFire16CParticleEmitter5func2Ev
	.word _ZN16CFieldEffectFire16CParticleEmitter6UpdateEi

    .global ptr_FUN_overlay_0_02160c54_overlay_0_02178eac
ptr_FUN_overlay_0_02160c54_overlay_0_02178eac: ; 0x02178EAC
	.word _ZN16CFieldEffectFire16CParticleEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
	.global _ZTV23CFieldEffectFireFactory
_ZTV23CFieldEffectFireFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178e20

    .global PTR_LAB_overlay_0_0215183c_overlay_0_02178eb8
PTR_LAB_overlay_0_0215183c_overlay_0_02178eb8: ; 0x02178EB8
	.word _ZN23CFieldEffectFireFactoryD1Ev

    .global ptr_FUN_overlay_0_02160e3c_overlay_0_02178ebc
ptr_FUN_overlay_0_02160e3c_overlay_0_02178ebc: ; 0x02178EBC
	.word ov0_02160E3C

    .global ptr_FUN_overlay_0_02160d9c_overlay_0_02178ec0
ptr_FUN_overlay_0_02160d9c_overlay_0_02178ec0: ; 0x02178EC0
	.word _ZN23CFieldEffectFireFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_N16CFieldEffectFire16CParticleEm_overlay_0_02178ed0
s_N16CFieldEffectFire16CParticleEm_overlay_0_02178ed0: ; 0x02178ED0
	.asciz "N16CFieldEffectFire16CParticleEmitterE"

    .global DAT_overlay_0_02178EF7
DAT_overlay_0_02178EF7:
	.byte 0x00

    .global s_N16CFieldEffectFire17CParticleAn_overlay_0_02178ef8
s_N16CFieldEffectFire17CParticleAn_overlay_0_02178ef8: ; 0x02178EF8
	.asciz "N16CFieldEffectFire17CParticleAnimatorE"

    .global DAT_overlay_0_02178F20
DAT_overlay_0_02178F20:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178e38

    .global ptr_FUN_overlay_0_021603b0_overlay_0_02178f28
ptr_FUN_overlay_0_021603b0_overlay_0_02178f28: ; 0x02178F28
	.word _ZN16CFieldEffectFireD1Ev

    .global ptr_FUN_overlay_0_021604bc_overlay_0_02178f2c
ptr_FUN_overlay_0_021604bc_overlay_0_02178f2c: ; 0x02178F2C
	.word ov0_021604BC

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02178f30
ptr_FUN_overlay_0_021423a4_overlay_0_02178f30: ; 0x02178F30
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN16CFieldEffectFire12sub_02033028Ev

    .global ptr_FUN_overlay_0_02160dd0_overlay_0_02178f38
ptr_FUN_overlay_0_02160dd0_overlay_0_02178f38: ; 0x02178F38
	.word _ZN16CFieldEffectFire12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02178f3c
ptr_FUN_overlay_0_021421d0_overlay_0_02178f3c: ; 0x02178F3C
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02178f40
ptr_FUN_overlay_0_02142380_overlay_0_02178f40: ; 0x02178F40
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0215b4a0_overlay_0_02178f44
ptr_FUN_overlay_0_0215b4a0_overlay_0_02178f44: ; 0x02178F44
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_021608e4_overlay_0_02178f4c
ptr_FUN_overlay_0_021608e4_overlay_0_02178f4c: ; 0x02178F4C
	.word _ZN16CFieldEffectFire12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0215b784_overlay_0_02178f50
ptr_FUN_overlay_0_0215b784_overlay_0_02178f50: ; 0x02178F50
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN16CFieldEffectFire12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global ptr_FUN_overlay_0_021423e8_overlay_0_02178f84
ptr_FUN_overlay_0_021423e8_overlay_0_02178f84: ; 0x02178F84
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021423E8ERK20FieldEffectSpriteRes
	.word _ZN16CFieldEffectFire13GetForceFieldEv
	.word _ZN16CFieldEffectFire10GetEmitterEv

    .global PTR_ptr_FUN_020835bc_overlay_0_02178f90
PTR_ptr_FUN_020835bc_overlay_0_02178f90: ; 0x02178F90
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectSparkFactory_overlay_0_02178fbc
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_02178f9c
PTR_ptr_FUN_020835bc_overlay_0_02178f9c: ; 0x02178F9C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldEffectSpark_overlay_0_02178fa8
	.word _ZTI17CFieldEffectActor

    .global s_17CFieldEffectSpark_overlay_0_02178fa8
s_17CFieldEffectSpark_overlay_0_02178fa8: ; 0x02178FA8
	.asciz "17CFieldEffectSpark"

    .global s_24CFieldEffectSparkFactory_overlay_0_02178fbc
s_24CFieldEffectSparkFactory_overlay_0_02178fbc: ; 0x02178FBC
	.asciz "24CFieldEffectSparkFactory"

    .global DAT_overlay_0_02178FD7
DAT_overlay_0_02178FD7:
	.byte 0x00
	.global _ZTV24CFieldEffectSparkFactory
_ZTV24CFieldEffectSparkFactory:
	.byte 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02178f90

    .global PTR_LAB_overlay_0_02151840_overlay_0_02178fe0
PTR_LAB_overlay_0_02151840_overlay_0_02178fe0: ; 0x02178FE0
	.word _ZN24CFieldEffectSparkFactoryD1Ev

    .global ptr_FUN_overlay_0_021618ac_overlay_0_02178fe4
ptr_FUN_overlay_0_021618ac_overlay_0_02178fe4: ; 0x02178FE4
	.word ov0_021618AC

    .global ptr_FUN_overlay_0_02161880_overlay_0_02178fe8
ptr_FUN_overlay_0_02161880_overlay_0_02178fe8: ; 0x02178FE8
	.word _ZN24CFieldEffectSparkFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02178f9c

    .global ptr_FUN_overlay_0_0216116c_overlay_0_02179000
ptr_FUN_overlay_0_0216116c_overlay_0_02179000: ; 0x02179000
	.word _ZN17CFieldEffectSparkD1Ev

    .global ptr_FUN_overlay_0_02161278_overlay_0_02179004
ptr_FUN_overlay_0_02161278_overlay_0_02179004: ; 0x02179004
	.word ov0_02161278

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179008
ptr_FUN_overlay_0_021423a4_overlay_0_02179008: ; 0x02179008
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectSpark12sub_02033028Ev

    .global ptr_FUN_overlay_0_02161834_overlay_0_02179010
ptr_FUN_overlay_0_02161834_overlay_0_02179010: ; 0x02179010
	.word _ZN17CFieldEffectSpark12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179014
ptr_FUN_overlay_0_021421d0_overlay_0_02179014: ; 0x02179014
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179018
ptr_FUN_overlay_0_02142380_overlay_0_02179018: ; 0x02179018
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_02161714_overlay_0_0217901c
ptr_FUN_overlay_0_02161714_overlay_0_0217901c: ; 0x0217901C
	.word _ZN17CFieldEffectSpark12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_0216138c_overlay_0_02179024
ptr_FUN_overlay_0_0216138c_overlay_0_02179024: ; 0x02179024
	.word _ZN17CFieldEffectSpark12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02161568_overlay_0_02179028
ptr_FUN_overlay_0_02161568_overlay_0_02179028: ; 0x02179028
	.word _ZN17CFieldEffectSpark12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN17CFieldEffectSpark12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global PTR_ptr_FUN_020835bc_overlay_0_0217905c
PTR_ptr_FUN_020835bc_overlay_0_0217905c: ; 0x0217905C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectJumonFactory_overlay_0_02179088
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_02179068
PTR_ptr_FUN_020835bc_overlay_0_02179068: ; 0x02179068
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldEffectJumon_overlay_0_02179074
	.word _ZTI12CFieldEffect

    .global s_17CFieldEffectJumon_overlay_0_02179074
s_17CFieldEffectJumon_overlay_0_02179074: ; 0x02179074
	.asciz "17CFieldEffectJumon"

    .global s_24CFieldEffectJumonFactory_overlay_0_02179088
s_24CFieldEffectJumonFactory_overlay_0_02179088: ; 0x02179088
	.asciz "24CFieldEffectJumonFactory"

    .global DAT_overlay_0_021790A3
DAT_overlay_0_021790A3:
	.byte 0x00
	.global _ZTV24CFieldEffectJumonFactory
_ZTV24CFieldEffectJumonFactory:
	.byte 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_0217905c

    .global PTR_LAB_overlay_0_02151844_overlay_0_021790ac
PTR_LAB_overlay_0_02151844_overlay_0_021790ac: ; 0x021790AC
	.word _ZN24CFieldEffectJumonFactoryD1Ev

    .global ptr_FUN_overlay_0_02161f18_overlay_0_021790b0
ptr_FUN_overlay_0_02161f18_overlay_0_021790b0: ; 0x021790B0
	.word ov0_02161F18
	.word _ZN24CFieldEffectJumonFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179068

    .global ptr_FUN_overlay_0_02161934_overlay_0_021790cc
ptr_FUN_overlay_0_02161934_overlay_0_021790cc: ; 0x021790CC
	.word _ZN17CFieldEffectJumonD1Ev

    .global ptr_FUN_overlay_0_02161978_overlay_0_021790d0
ptr_FUN_overlay_0_02161978_overlay_0_021790d0: ; 0x021790D0
	.word ov0_02161978

    .global ptr_FUN_overlay_0_021423a4_overlay_0_021790d4
ptr_FUN_overlay_0_021423a4_overlay_0_021790d4: ; 0x021790D4
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectJumon12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_021790e0
ptr_FUN_overlay_0_021421d0_overlay_0_021790e0: ; 0x021790E0
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_021790e4
ptr_FUN_overlay_0_02142380_overlay_0_021790e4: ; 0x021790E4
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_02161c28_overlay_0_021790e8
ptr_FUN_overlay_0_02161c28_overlay_0_021790e8: ; 0x021790E8
	.word _ZN17CFieldEffectJumon12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_021619c4_overlay_0_021790f0
ptr_FUN_overlay_0_021619c4_overlay_0_021790f0: ; 0x021790F0
	.word _ZN17CFieldEffectJumon12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02161b28_overlay_0_021790f4
ptr_FUN_overlay_0_02161b28_overlay_0_021790f4: ; 0x021790F4
	.word _ZN17CFieldEffectJumon12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN17CFieldEffectJumon12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global DAT_overlay_0_02179128
DAT_overlay_0_02179128: ; 0x02179128
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x01
	.byte 0xCC, 0x01, 0x00, 0x00

    .global DAT_overlay_0_02179134
DAT_overlay_0_02179134: ; 0x02179134
	.byte 0x06, 0x00, 0x00, 0x00, 0x28, 0x00, 0xE0, 0x00, 0x24, 0x03, 0x00, 0x00
	.byte 0x10, 0x00, 0x00, 0x00, 0x73, 0x00, 0x20, 0x01, 0x60, 0x03, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00
	.byte 0x8C, 0x00, 0x90, 0x01, 0xD0, 0x02, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0xB5, 0x00, 0x90, 0x01
	.byte 0x90, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x18, 0x03, 0xF0, 0x00, 0x00, 0x00
	.byte 0x1C, 0x00, 0x00, 0x00, 0xE1, 0x00, 0x60, 0x01, 0x50, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00
	.byte 0x0C, 0x01, 0xF0, 0x00, 0xB0, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x31, 0x01, 0x40, 0x01
	.byte 0x10, 0x03, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x48, 0x01, 0x90, 0x01, 0xB0, 0x01, 0x00, 0x00
	.byte 0x27, 0x00, 0x00, 0x00, 0x48, 0x01, 0x90, 0x01, 0xB0, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_0_021791b8
PTR_ptr_FUN_020835bc_overlay_0_021791b8: ; 0x021791B8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_21CFieldEffectExplosion_overlay_0_021791d0
	.word _ZTI17CFieldEffectActor

    .global PTR_ptr_FUN_020835bc_overlay_0_021791c4
PTR_ptr_FUN_020835bc_overlay_0_021791c4: ; 0x021791C4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_28CFieldEffectExplosionFactory_overlay_0_021791e8
	.word _ZTI19CFieldEffectFactory

    .global s_21CFieldEffectExplosion_overlay_0_021791d0
s_21CFieldEffectExplosion_overlay_0_021791d0: ; 0x021791D0
	.asciz "21CFieldEffectExplosion"

    .global s_28CFieldEffectExplosionFactory_overlay_0_021791e8
s_28CFieldEffectExplosionFactory_overlay_0_021791e8: ; 0x021791E8
	.asciz "28CFieldEffectExplosionFactory"

    .global DAT_overlay_0_02179207
DAT_overlay_0_02179207:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_021791c4

    .global ptr_FUN_overlay_0_0216288c_overlay_0_02179210
ptr_FUN_overlay_0_0216288c_overlay_0_02179210: ; 0x02179210
	.word _ZN28CFieldEffectExplosionFactoryD1Ev

    .global ptr_FUN_overlay_0_021628c4_overlay_0_02179214
ptr_FUN_overlay_0_021628c4_overlay_0_02179214: ; 0x02179214
	.word ov0_021628C4

    .global ptr_FUN_overlay_0_02162904_overlay_0_02179218
ptr_FUN_overlay_0_02162904_overlay_0_02179218: ; 0x02179218
	.word _ZN28CFieldEffectExplosionFactory6CreateEi

    .global ptr_FUN_overlay_0_02162b4c_overlay_0_0217921c
ptr_FUN_overlay_0_02162b4c_overlay_0_0217921c: ; 0x0217921C
	.word _ZN28CFieldEffectExplosionFactory6UpdateEi
	.word _ZN28CFieldEffectExplosionFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021791b8

    .global ptr_FUN_overlay_0_02161fdc_overlay_0_02179230
ptr_FUN_overlay_0_02161fdc_overlay_0_02179230: ; 0x02179230
	.word _ZN21CFieldEffectExplosionD1Ev

    .global ptr_FUN_overlay_0_02162074_overlay_0_02179234
ptr_FUN_overlay_0_02162074_overlay_0_02179234: ; 0x02179234
	.word ov0_02162074
	.word _ZN21CFieldEffectExplosion12ov0_021423A4Ev
	.word _ZN21CFieldEffectExplosion12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179244
ptr_FUN_overlay_0_021421d0_overlay_0_02179244: ; 0x02179244
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179248
ptr_FUN_overlay_0_02142380_overlay_0_02179248: ; 0x02179248
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_02162404_overlay_0_0217924c
ptr_FUN_overlay_0_02162404_overlay_0_0217924c: ; 0x0217924C
	.word _ZN21CFieldEffectExplosion12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02162194_overlay_0_02179254
ptr_FUN_overlay_0_02162194_overlay_0_02179254: ; 0x02179254
	.word _ZN21CFieldEffectExplosion12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02162304_overlay_0_02179258
ptr_FUN_overlay_0_02162304_overlay_0_02179258: ; 0x02179258
	.word _ZN21CFieldEffectExplosion12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN21CFieldEffectExplosion12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi

    .global ptr_FUN_overlay_0_021625dc_overlay_0_02179284
ptr_FUN_overlay_0_021625dc_overlay_0_02179284: ; 0x02179284
	.word _ZN21CFieldEffectExplosion12ov0_02142390EPvS0_

    .global ptr_FUN_overlay_0_021626d4_overlay_0_02179288
ptr_FUN_overlay_0_021626d4_overlay_0_02179288: ; 0x02179288
	.word _ZN21CFieldEffectExplosion12ov0_02142388EPKv

    .global s_cell_d_overlay_0_0217928c
s_cell_d_overlay_0_0217928c: ; 0x0217928C
	.asciz "cell %d"

    .global PTR_ptr_FUN_020835bc_overlay_0_02179294
PTR_ptr_FUN_020835bc_overlay_0_02179294: ; 0x02179294
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldEffectSlime_overlay_0_021792ac
	.word _ZTI17CFieldEffectActor

    .global PTR_ptr_FUN_020835bc_overlay_0_021792a0
PTR_ptr_FUN_020835bc_overlay_0_021792a0: ; 0x021792A0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectSlimeFactory_overlay_0_021792c0
	.word _ZTI19CFieldEffectFactory

    .global s_17CFieldEffectSlime_overlay_0_021792ac
s_17CFieldEffectSlime_overlay_0_021792ac: ; 0x021792AC
	.asciz "17CFieldEffectSlime"

    .global s_24CFieldEffectSlimeFactory_overlay_0_021792c0
s_24CFieldEffectSlimeFactory_overlay_0_021792c0: ; 0x021792C0
	.asciz "24CFieldEffectSlimeFactory"

    .global DAT_overlay_0_021792DB
DAT_overlay_0_021792DB:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021792a0

    .global ptr_FUN_overlay_0_02163690_overlay_0_021792e4
ptr_FUN_overlay_0_02163690_overlay_0_021792e4: ; 0x021792E4
	.word _ZN24CFieldEffectSlimeFactoryD1Ev

    .global ptr_FUN_overlay_0_021636b8_overlay_0_021792e8
ptr_FUN_overlay_0_021636b8_overlay_0_021792e8: ; 0x021792E8
	.word ov0_021636B8

    .global ptr_FUN_overlay_0_021636e8_overlay_0_021792ec
ptr_FUN_overlay_0_021636e8_overlay_0_021792ec: ; 0x021792EC
	.word _ZN24CFieldEffectSlimeFactory6CreateEi
	.word _ZN24CFieldEffectSlimeFactory6UpdateEi
	.word _ZN24CFieldEffectSlimeFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179294

    .global ptr_FUN_overlay_0_02162c34_overlay_0_02179304
ptr_FUN_overlay_0_02162c34_overlay_0_02179304: ; 0x02179304
	.word _ZN17CFieldEffectSlimeD1Ev

    .global ptr_FUN_overlay_0_02162cb4_overlay_0_02179308
ptr_FUN_overlay_0_02162cb4_overlay_0_02179308: ; 0x02179308
	.word ov0_02162CB4
	.word _ZN17CFieldEffectSlime12ov0_021423A4Ev
	.word _ZN17CFieldEffectSlime12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179318
ptr_FUN_overlay_0_021421d0_overlay_0_02179318: ; 0x02179318
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217931c
ptr_FUN_overlay_0_02142380_overlay_0_0217931c: ; 0x0217931C
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021630b8_overlay_0_02179320
ptr_FUN_overlay_0_021630b8_overlay_0_02179320: ; 0x02179320
	.word _ZN17CFieldEffectSlime12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02162db4_overlay_0_02179328
ptr_FUN_overlay_0_02162db4_overlay_0_02179328: ; 0x02179328
	.word _ZN17CFieldEffectSlime12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02162ebc_overlay_0_0217932c
ptr_FUN_overlay_0_02162ebc_overlay_0_0217932c: ; 0x0217932C
	.word _ZN17CFieldEffectSlime12ov0_02142344EP8Camera2D
	.word _ZN17CFieldEffectSlime12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_02162fb4_overlay_0_0217933c
ptr_FUN_overlay_0_02162fb4_overlay_0_0217933c: ; 0x0217933C
	.word _ZN17CFieldEffectSlime12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi

    .global ptr_FUN_overlay_0_02163404_overlay_0_02179358
ptr_FUN_overlay_0_02163404_overlay_0_02179358: ; 0x02179358
	.word _ZN17CFieldEffectSlime12ov0_02142390EPvS0_

    .global ptr_FUN_overlay_0_02163544_overlay_0_0217935c
ptr_FUN_overlay_0_02163544_overlay_0_0217935c: ; 0x0217935C
	.word _ZN17CFieldEffectSlime12ov0_02142388EPKv

    .global s_data_Script_field_effect_ef_03d_overlay_0_02179360
s_data_Script_field_effect_ef_03d_overlay_0_02179360: ; 0x02179360
	.asciz "data/Script/field/effect/ef%03d.fsb"

    .global s_EventHandle_overlay_0_02179384
s_EventHandle_overlay_0_02179384: ; 0x02179384
	.asciz "EventHandle"

    .global PTR_ptr_FUN_020835bc_overlay_0_02179390
PTR_ptr_FUN_020835bc_overlay_0_02179390: ; 0x02179390
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N22CFieldEffectManpuAnger9CAnima_overlay_0_02179424
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_0217939c
PTR_ptr_FUN_020835bc_overlay_0_0217939c: ; 0x0217939C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N22CFieldEffectManpuAnger8CEmitt_overlay_0_02179400
	.word _ZTI21TFieldParticleEmitterI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_021793a8
PTR_ptr_FUN_020835bc_overlay_0_021793a8: ; 0x021793A8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_22CFieldEffectManpuAnger_overlay_0_021793c8
	.word _ZTI17CFieldEffectManpu
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179390

    .global PTR_LAB_overlay_0_02163cf8_overlay_0_021793bc
PTR_LAB_overlay_0_02163cf8_overlay_0_021793bc: ; 0x021793BC
	.word _ZN22CFieldEffectManpuAnger9CAnimatorD1Ev

    .global ptr_FUN_overlay_0_0216449c_overlay_0_021793c0
ptr_FUN_overlay_0_0216449c_overlay_0_021793c0: ; 0x021793C0
	.word ov0_0216449C

    .global ptr_FUN_overlay_0_02164404_overlay_0_021793c4
ptr_FUN_overlay_0_02164404_overlay_0_021793c4: ; 0x021793C4
	.word _ZN22CFieldEffectManpuAnger9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_22CFieldEffectManpuAnger_overlay_0_021793c8
s_22CFieldEffectManpuAnger_overlay_0_021793c8: ; 0x021793C8
	.asciz "22CFieldEffectManpuAnger"

    .global DAT_overlay_0_021793E1
DAT_overlay_0_021793E1:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_0217939c

    .global PTR_LAB_overlay_0_02163cf4_overlay_0_021793ec
PTR_LAB_overlay_0_02163cf4_overlay_0_021793ec: ; 0x021793EC
	.word _ZN22CFieldEffectManpuAnger8CEmitterD1Ev

    .global ptr_FUN_overlay_0_02164488_overlay_0_021793f0
ptr_FUN_overlay_0_02164488_overlay_0_021793f0: ; 0x021793F0
	.word ov0_02164488
	.word _ZN22CFieldEffectManpuAnger8CEmitter5func2Ev
	.word _ZN22CFieldEffectManpuAnger8CEmitter6UpdateEi

    .global ptr_FUN_overlay_0_021641c8_overlay_0_021793fc
ptr_FUN_overlay_0_021641c8_overlay_0_021793fc: ; 0x021793FC
	.word _ZN22CFieldEffectManpuAnger8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

    .global s_N22CFieldEffectManpuAnger8CEmitt_overlay_0_02179400
s_N22CFieldEffectManpuAnger8CEmitt_overlay_0_02179400: ; 0x02179400
	.asciz "N22CFieldEffectManpuAnger8CEmitterE"

    .global s_N22CFieldEffectManpuAnger9CAnima_overlay_0_02179424
s_N22CFieldEffectManpuAnger9CAnima_overlay_0_02179424: ; 0x02179424
	.asciz "N22CFieldEffectManpuAnger9CAnimatorE"

    .global DAT_overlay_0_02179449
DAT_overlay_0_02179449:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021793a8

    .global ptr_FUN_overlay_0_02163cfc_overlay_0_02179454
ptr_FUN_overlay_0_02163cfc_overlay_0_02179454: ; 0x02179454
	.word _ZN22CFieldEffectManpuAngerD1Ev

    .global ptr_FUN_overlay_0_02163d6c_overlay_0_02179458
ptr_FUN_overlay_0_02163d6c_overlay_0_02179458: ; 0x02179458
	.word ov0_02163D6C

    .global ptr_FUN_overlay_0_021423a4_overlay_0_0217945c
ptr_FUN_overlay_0_021423a4_overlay_0_0217945c: ; 0x0217945C
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectManpu12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179468
ptr_FUN_overlay_0_021421d0_overlay_0_02179468: ; 0x02179468
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_0217946c
ptr_FUN_overlay_0_02142380_overlay_0_0217946c: ; 0x0217946C
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_02163de4_overlay_0_02179470
ptr_FUN_overlay_0_02163de4_overlay_0_02179470: ; 0x02179470
	.word _ZN22CFieldEffectManpuAnger12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02163e28_overlay_0_02179478
ptr_FUN_overlay_0_02163e28_overlay_0_02179478: ; 0x02179478
	.word _ZN22CFieldEffectManpuAnger12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02143bf0_overlay_0_0217947c
ptr_FUN_overlay_0_02143bf0_overlay_0_0217947c: ; 0x0217947C
	.word _ZN17CFieldEffectManpu12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN17CFieldEffectManpu7SetTypeEi

    .global ptr_FUN_overlay_0_02164100_overlay_0_021794b4
ptr_FUN_overlay_0_02164100_overlay_0_021794b4: ; 0x021794B4
	.word _ZN22CFieldEffectManpuAnger4DrawEP8Camera2D
	.word _ZN22CFieldEffectManpuAnger8SetDepthEl

    .global PTR_ptr_FUN_020835bc_overlay_0_021794bc
PTR_ptr_FUN_020835bc_overlay_0_021794bc: ; 0x021794BC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_20CFieldEffectManpuAse_overlay_0_021794c8
	.word _ZTI17CFieldEffectManpu

    .global s_20CFieldEffectManpuAse_overlay_0_021794c8
s_20CFieldEffectManpuAse_overlay_0_021794c8: ; 0x021794C8
	.asciz "20CFieldEffectManpuAse"

    .global DAT_overlay_0_021794DF
DAT_overlay_0_021794DF:
	.byte 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021794bc

    .global ptr_FUN_overlay_0_021645c8_overlay_0_021794e8
ptr_FUN_overlay_0_021645c8_overlay_0_021794e8: ; 0x021794E8
	.word _ZN20CFieldEffectManpuAseD1Ev

    .global ptr_FUN_overlay_0_0216462c_overlay_0_021794ec
ptr_FUN_overlay_0_0216462c_overlay_0_021794ec: ; 0x021794EC
	.word ov0_0216462C

    .global ptr_FUN_overlay_0_021423a4_overlay_0_021794f0
ptr_FUN_overlay_0_021423a4_overlay_0_021794f0: ; 0x021794F0
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectManpu12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_021794fc
ptr_FUN_overlay_0_021421d0_overlay_0_021794fc: ; 0x021794FC
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179500
ptr_FUN_overlay_0_02142380_overlay_0_02179500: ; 0x02179500
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_02179504
ptr_FUN_overlay_0_021421f0_overlay_0_02179504: ; 0x02179504
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02164698_overlay_0_0217950c
ptr_FUN_overlay_0_02164698_overlay_0_0217950c: ; 0x0217950C
	.word _ZN20CFieldEffectManpuAse12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02143bf0_overlay_0_02179510
ptr_FUN_overlay_0_02143bf0_overlay_0_02179510: ; 0x02179510
	.word _ZN17CFieldEffectManpu12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN17CFieldEffectManpu7SetTypeEi

    .global ptr_FUN_overlay_0_02164728_overlay_0_02179548
ptr_FUN_overlay_0_02164728_overlay_0_02179548: ; 0x02179548
	.word _ZN20CFieldEffectManpuAse4DrawEP8Camera2D
	.word _ZN20CFieldEffectManpuAse8SetDepthEl

    .global PTR_ptr_FUN_020835bc_overlay_0_02179550
PTR_ptr_FUN_020835bc_overlay_0_02179550: ; 0x02179550
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_25CFieldEffectManpuDokarimo_overlay_0_0217955c
	.word _ZTI22CFieldEffectManpuAnime

    .global s_25CFieldEffectManpuDokarimo_overlay_0_0217955c
s_25CFieldEffectManpuDokarimo_overlay_0_0217955c: ; 0x0217955C
	.asciz "25CFieldEffectManpuDokarimo"

    .global DAT_overlay_0_02179578
DAT_overlay_0_02179578:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179550

    .global PTR_LAB_overlay_0_02164ce4_overlay_0_02179580
PTR_LAB_overlay_0_02164ce4_overlay_0_02179580: ; 0x02179580
	.word _ZN25CFieldEffectManpuDokarimoD1Ev

    .global ptr_FUN_overlay_0_02164cf8_overlay_0_02179584
ptr_FUN_overlay_0_02164cf8_overlay_0_02179584: ; 0x02179584
	.word ov0_02164CF8

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179588
ptr_FUN_overlay_0_021423a4_overlay_0_02179588: ; 0x02179588
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectManpu12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179594
ptr_FUN_overlay_0_021421d0_overlay_0_02179594: ; 0x02179594
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179598
ptr_FUN_overlay_0_02142380_overlay_0_02179598: ; 0x02179598
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_0217959c
ptr_FUN_overlay_0_021421f0_overlay_0_0217959c: ; 0x0217959C
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02152854_overlay_0_021795a4
ptr_FUN_overlay_0_02152854_overlay_0_021795a4: ; 0x021795A4
	.word _ZN22CFieldEffectManpuAnime12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02143bf0_overlay_0_021795a8
ptr_FUN_overlay_0_02143bf0_overlay_0_021795a8: ; 0x021795A8
	.word _ZN17CFieldEffectManpu12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN17CFieldEffectManpu7SetTypeEi

    .global ptr_FUN_overlay_0_021529c4_overlay_0_021795e0
ptr_FUN_overlay_0_021529c4_overlay_0_021795e0: ; 0x021795E0
	.word _ZN22CFieldEffectManpuAnime4DrawEP8Camera2D
	.word _ZN23CFieldEffectManpuSimple8SetDepthEl

    .global ptr_FUN_overlay_0_02164a8c_overlay_0_021795e8
ptr_FUN_overlay_0_02164a8c_overlay_0_021795e8: ; 0x021795E8
	.word _ZN25CFieldEffectManpuDokarimo9UpdatePosEv

    .global PTR_ptr_FUN_020835bc_overlay_0_021795ec
PTR_ptr_FUN_020835bc_overlay_0_021795ec: ; 0x021795EC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_28CFieldEffectDamageIndication_overlay_0_021795f8
	.word _ZTI12CFieldEffect

    .global s_28CFieldEffectDamageIndication_overlay_0_021795f8
s_28CFieldEffectDamageIndication_overlay_0_021795f8: ; 0x021795F8
	.asciz "28CFieldEffectDamageIndication"

    .global DAT_overlay_0_02179617
DAT_overlay_0_02179617:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_021795ec

    .global ptr_FUN_overlay_0_021426a0_overlay_0_02179620
ptr_FUN_overlay_0_021426a0_overlay_0_02179620: ; 0x02179620
	.word _ZN28CFieldEffectDamageIndicationD1Ev

    .global ptr_FUN_overlay_0_0216517c_overlay_0_02179624
ptr_FUN_overlay_0_0216517c_overlay_0_02179624: ; 0x02179624
	.word ov0_0216517C

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179628
ptr_FUN_overlay_0_021423a4_overlay_0_02179628: ; 0x02179628
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word ov0_02165174
	.word _ZN12CFieldEffect12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179634
ptr_FUN_overlay_0_021421d0_overlay_0_02179634: ; 0x02179634
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179638
ptr_FUN_overlay_0_02142380_overlay_0_02179638: ; 0x02179638
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_0217963c
ptr_FUN_overlay_0_021421f0_overlay_0_0217963c: ; 0x0217963C
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02164ef4_overlay_0_02179644
ptr_FUN_overlay_0_02164ef4_overlay_0_02179644: ; 0x02179644
	.word ov0_02164EF4

    .global ptr_FUN_overlay_0_021650d0_overlay_0_02179648
ptr_FUN_overlay_0_021650d0_overlay_0_02179648: ; 0x02179648
	.word ov0_021650D0
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global PTR_ptr_FUN_020835bc_overlay_0_0217967c
PTR_ptr_FUN_020835bc_overlay_0_0217967c: ; 0x0217967C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CFieldEffectBush_overlay_0_02179694
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_02179688
PTR_ptr_FUN_020835bc_overlay_0_02179688: ; 0x02179688
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_23CFieldEffectBushFactory_overlay_0_021796a8
	.word _ZTI19CFieldEffectFactory

    .global s_16CFieldEffectBush_overlay_0_02179694
s_16CFieldEffectBush_overlay_0_02179694: ; 0x02179694
	.asciz "16CFieldEffectBush"

    .global DAT_overlay_0_021796A7
DAT_overlay_0_021796A7:
	.byte 0x00

    .global s_23CFieldEffectBushFactory_overlay_0_021796a8
s_23CFieldEffectBushFactory_overlay_0_021796a8: ; 0x021796A8
	.asciz "23CFieldEffectBushFactory"

    .global DAT_overlay_0_021796C2
DAT_overlay_0_021796C2:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02179688

    .global ptr_FUN_overlay_0_02151848_overlay_0_021796cc
ptr_FUN_overlay_0_02151848_overlay_0_021796cc: ; 0x021796CC
	.word _ZN23CFieldEffectBushFactoryD1Ev

    .global ptr_FUN_overlay_0_021657c0_overlay_0_021796d0
ptr_FUN_overlay_0_021657c0_overlay_0_021796d0: ; 0x021796D0
	.word ov0_021657C0

    .global ptr_FUN_overlay_0_0216576c_overlay_0_021796d4
ptr_FUN_overlay_0_0216576c_overlay_0_021796d4: ; 0x021796D4
	.word _ZN23CFieldEffectBushFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217967c

    .global ptr_FUN_overlay_0_0216521c_overlay_0_021796ec
ptr_FUN_overlay_0_0216521c_overlay_0_021796ec: ; 0x021796EC
	.word _ZN16CFieldEffectBushD1Ev

    .global ptr_FUN_overlay_0_02165268_overlay_0_021796f0
ptr_FUN_overlay_0_02165268_overlay_0_021796f0: ; 0x021796F0
	.word ov0_02165268

    .global ptr_thunk_FUN_overlay_0_02165410_overlay_0_021796f4
ptr_thunk_FUN_overlay_0_02165410_overlay_0_021796f4: ; 0x021796F4
	.word thunk_FUN_overlay_0__02165410
	.word _ZN16CFieldEffectBush12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179700
ptr_FUN_overlay_0_021421d0_overlay_0_02179700: ; 0x02179700
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179704
ptr_FUN_overlay_0_02142380_overlay_0_02179704: ; 0x02179704
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_02179708
ptr_FUN_overlay_0_021421f0_overlay_0_02179708: ; 0x02179708
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02142264_overlay_0_02179710
ptr_FUN_overlay_0_02142264_overlay_0_02179710: ; 0x02179710
	.word _ZN12CFieldEffect12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02165494_overlay_0_02179714
ptr_FUN_overlay_0_02165494_overlay_0_02179714: ; 0x02179714
	.word _ZN16CFieldEffectBush12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global PTR_ptr_FUN_020835bc_overlay_0_02179748
PTR_ptr_FUN_020835bc_overlay_0_02179748: ; 0x02179748
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_23CFieldEffectWaterSplash_overlay_0_02179780
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_02179754
PTR_ptr_FUN_020835bc_overlay_0_02179754: ; 0x02179754
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_30CFieldEffectWaterSplashFactory_overlay_0_021797bc
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_02179760
PTR_ptr_FUN_020835bc_overlay_0_02179760: ; 0x02179760
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N23CFieldEffectWaterSplash17CEff_overlay_0_021797e0
	.word _ZTI11CDrawObject
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179760

    .global PTR_LAB_overlay_0_02165868_overlay_0_02179774
PTR_LAB_overlay_0_02165868_overlay_0_02179774: ; 0x02179774
	.word _ZN23CFieldEffectWaterSplash17CEffectDrawObjectD1Ev

    .global ptr_FUN_overlay_0_02165bf0_overlay_0_02179778
ptr_FUN_overlay_0_02165bf0_overlay_0_02179778: ; 0x02179778
	.word ov0_02165BF0
	.word _ZN23CFieldEffectWaterSplash17CEffectDrawObject12sub_020091D4EP8Camera2Di

    .global s_23CFieldEffectWaterSplash_overlay_0_02179780
s_23CFieldEffectWaterSplash_overlay_0_02179780: ; 0x02179780
	.asciz "23CFieldEffectWaterSplash"

    .global DAT_overlay_0_0217979A
DAT_overlay_0_0217979A:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179754

    .global PTR_LAB_overlay_0_02151870_overlay_0_021797a4
PTR_LAB_overlay_0_02151870_overlay_0_021797a4: ; 0x021797A4
	.word _ZN30CFieldEffectWaterSplashFactoryD1Ev

    .global ptr_FUN_overlay_0_02165c04_overlay_0_021797a8
ptr_FUN_overlay_0_02165c04_overlay_0_021797a8: ; 0x021797A8
	.word ov0_02165C04

    .global ptr_FUN_overlay_0_02165ba4_overlay_0_021797ac
ptr_FUN_overlay_0_02165ba4_overlay_0_021797ac: ; 0x021797AC
	.word _ZN30CFieldEffectWaterSplashFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_30CFieldEffectWaterSplashFactory_overlay_0_021797bc
s_30CFieldEffectWaterSplashFactory_overlay_0_021797bc: ; 0x021797BC
	.asciz "30CFieldEffectWaterSplashFactory"

    .global DAT_overlay_0_021797DD
DAT_overlay_0_021797DD:
	.byte 0x00, 0x00, 0x00

    .global s_N23CFieldEffectWaterSplash17CEff_overlay_0_021797e0
s_N23CFieldEffectWaterSplash17CEff_overlay_0_021797e0: ; 0x021797E0
	.asciz "N23CFieldEffectWaterSplash17CEffectDrawObjectE"

    .global DAT_overlay_0_0217980F
DAT_overlay_0_0217980F:
	.byte 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179748

    .global ptr_FUN_overlay_0_0216586c_overlay_0_02179818
ptr_FUN_overlay_0_0216586c_overlay_0_02179818: ; 0x02179818
	.word _ZN23CFieldEffectWaterSplashD1Ev

    .global ptr_FUN_overlay_0_021658b8_overlay_0_0217981c
ptr_FUN_overlay_0_021658b8_overlay_0_0217981c: ; 0x0217981C
	.word ov0_021658B8

    .global ptr_thunk_FUN_overlay_0_0216596c_overlay_0_02179820
ptr_thunk_FUN_overlay_0_0216596c_overlay_0_02179820: ; 0x02179820
	.word thunk_FUN_overlay_0__0216596c
	.word _ZN23CFieldEffectWaterSplash12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_0217982c
ptr_FUN_overlay_0_021421d0_overlay_0_0217982c: ; 0x0217982C
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179830
ptr_FUN_overlay_0_02142380_overlay_0_02179830: ; 0x02179830
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021659b8_overlay_0_02179834
ptr_FUN_overlay_0_021659b8_overlay_0_02179834: ; 0x02179834
	.word _ZN23CFieldEffectWaterSplash12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_021659fc_overlay_0_0217983c
ptr_FUN_overlay_0_021659fc_overlay_0_0217983c: ; 0x0217983C
	.word _ZN23CFieldEffectWaterSplash12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02165a58_overlay_0_02179840
ptr_FUN_overlay_0_02165a58_overlay_0_02179840: ; 0x02179840
	.word _ZN23CFieldEffectWaterSplash12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN23CFieldEffectWaterSplash12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN23CFieldEffectWaterSplash12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global PTR_ptr_FUN_020835bc_overlay_0_02179874
PTR_ptr_FUN_020835bc_overlay_0_02179874: ; 0x02179874
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectManpuGokigen_overlay_0_021798ac
	.word _ZTI17CFieldEffectManpu

    .global PTR_ptr_FUN_020835bc_overlay_0_02179880
PTR_ptr_FUN_020835bc_overlay_0_02179880: ; 0x02179880
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N24CFieldEffectManpuGokigen8CEmi_overlay_0_021798e4
	.word _ZTI21TFieldParticleEmitterI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_0217988c
PTR_ptr_FUN_020835bc_overlay_0_0217988c: ; 0x0217988C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N24CFieldEffectManpuGokigen9CAni_overlay_0_0217990c
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_0217988c

    .global PTR_LAB_overlay_0_02165eb0_overlay_0_021798a0
PTR_LAB_overlay_0_02165eb0_overlay_0_021798a0: ; 0x021798A0
	.word _ZN24CFieldEffectManpuGokigen9CAnimatorD1Ev

    .global ptr_FUN_overlay_0_02166780_overlay_0_021798a4
ptr_FUN_overlay_0_02166780_overlay_0_021798a4: ; 0x021798A4
	.word ov0_02166780

    .global ptr_FUN_overlay_0_0216663c_overlay_0_021798a8
ptr_FUN_overlay_0_0216663c_overlay_0_021798a8: ; 0x021798A8
	.word _ZN24CFieldEffectManpuGokigen9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_24CFieldEffectManpuGokigen_overlay_0_021798ac
s_24CFieldEffectManpuGokigen_overlay_0_021798ac: ; 0x021798AC
	.asciz "24CFieldEffectManpuGokigen"

    .global DAT_overlay_0_021798C7
DAT_overlay_0_021798C7:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02179880

    .global PTR_LAB_overlay_0_02165eac_overlay_0_021798d0
PTR_LAB_overlay_0_02165eac_overlay_0_021798d0: ; 0x021798D0
	.word _ZN24CFieldEffectManpuGokigen8CEmitterD1Ev
	.word ov0_0216676C
	.word _ZN24CFieldEffectManpuGokigen8CEmitter5func2Ev
	.word _ZN24CFieldEffectManpuGokigen8CEmitter6UpdateEi

    .global ptr_FUN_overlay_0_021663a8_overlay_0_021798e0
ptr_FUN_overlay_0_021663a8_overlay_0_021798e0: ; 0x021798E0
	.word _ZN24CFieldEffectManpuGokigen8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

    .global s_N24CFieldEffectManpuGokigen8CEmi_overlay_0_021798e4
s_N24CFieldEffectManpuGokigen8CEmi_overlay_0_021798e4: ; 0x021798E4
	.asciz "N24CFieldEffectManpuGokigen8CEmitterE"

    .global DAT_overlay_0_0217990A
DAT_overlay_0_0217990A:
	.byte 0x00, 0x00

    .global s_N24CFieldEffectManpuGokigen9CAni_overlay_0_0217990c
s_N24CFieldEffectManpuGokigen9CAni_overlay_0_0217990c: ; 0x0217990C
	.asciz "N24CFieldEffectManpuGokigen9CAnimatorE"

    .global DAT_overlay_0_02179933
DAT_overlay_0_02179933:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02179874

    .global ptr_FUN_overlay_0_02165eb4_overlay_0_0217993c
ptr_FUN_overlay_0_02165eb4_overlay_0_0217993c: ; 0x0217993C
	.word _ZN24CFieldEffectManpuGokigenD1Ev

    .global ptr_FUN_overlay_0_02165f24_overlay_0_02179940
ptr_FUN_overlay_0_02165f24_overlay_0_02179940: ; 0x02179940
	.word ov0_02165F24

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179944
ptr_FUN_overlay_0_021423a4_overlay_0_02179944: ; 0x02179944
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectManpu12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179950
ptr_FUN_overlay_0_021421d0_overlay_0_02179950: ; 0x02179950
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179954
ptr_FUN_overlay_0_02142380_overlay_0_02179954: ; 0x02179954
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_02165fb8_overlay_0_02179958
ptr_FUN_overlay_0_02165fb8_overlay_0_02179958: ; 0x02179958
	.word _ZN24CFieldEffectManpuGokigen12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02165ffc_overlay_0_02179960
ptr_FUN_overlay_0_02165ffc_overlay_0_02179960: ; 0x02179960
	.word _ZN24CFieldEffectManpuGokigen12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02143bf0_overlay_0_02179964
ptr_FUN_overlay_0_02143bf0_overlay_0_02179964: ; 0x02179964
	.word _ZN17CFieldEffectManpu12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN24CFieldEffectManpuGokigen7SetTypeEi

    .global ptr_FUN_overlay_0_021662e0_overlay_0_0217999c
ptr_FUN_overlay_0_021662e0_overlay_0_0217999c: ; 0x0217999C
	.word _ZN24CFieldEffectManpuGokigen4DrawEP8Camera2D
	.word _ZN24CFieldEffectManpuGokigen8SetDepthEl

    .global PTR_ptr_FUN_020835bc_overlay_0_021799a4
PTR_ptr_FUN_020835bc_overlay_0_021799a4: ; 0x021799A4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldEffectBloom_overlay_0_021799bc
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_021799b0
PTR_ptr_FUN_020835bc_overlay_0_021799b0: ; 0x021799B0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CFieldEffectBloomFactory_overlay_0_021799d0
	.word _ZTI19CFieldEffectFactory

    .global s_17CFieldEffectBloom_overlay_0_021799bc
s_17CFieldEffectBloom_overlay_0_021799bc: ; 0x021799BC
	.asciz "17CFieldEffectBloom"

    .global s_24CFieldEffectBloomFactory_overlay_0_021799d0
s_24CFieldEffectBloomFactory_overlay_0_021799d0: ; 0x021799D0
	.asciz "24CFieldEffectBloomFactory"

    .global DAT_overlay_0_021799EB
DAT_overlay_0_021799EB:
	.byte 0x00
	.global _ZTV24CFieldEffectBloomFactory
_ZTV24CFieldEffectBloomFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021799b0

    .global ptr_FUN_overlay_0_021672a0_overlay_0_021799f4
ptr_FUN_overlay_0_021672a0_overlay_0_021799f4: ; 0x021799F4
	.word _ZN24CFieldEffectBloomFactoryD1Ev

    .global ptr_FUN_overlay_0_021672d8_overlay_0_021799f8
ptr_FUN_overlay_0_021672d8_overlay_0_021799f8: ; 0x021799F8
	.word ov0_021672D8

    .global ptr_FUN_overlay_0_02167324_overlay_0_021799fc
ptr_FUN_overlay_0_02167324_overlay_0_021799fc: ; 0x021799FC
	.word _ZN24CFieldEffectBloomFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN24CFieldEffectBloomFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021799a4

    .global ptr_FUN_overlay_0_0216691c_overlay_0_02179a14
ptr_FUN_overlay_0_0216691c_overlay_0_02179a14: ; 0x02179A14
	.word _ZN17CFieldEffectBloomD1Ev

    .global ptr_FUN_overlay_0_02166960_overlay_0_02179a18
ptr_FUN_overlay_0_02166960_overlay_0_02179a18: ; 0x02179A18
	.word ov0_02166960

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179a1c
ptr_FUN_overlay_0_021423a4_overlay_0_02179a1c: ; 0x02179A1C
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN17CFieldEffectBloom12sub_02033028Ev

    .global ptr_FUN_overlay_0_02167564_overlay_0_02179a24
ptr_FUN_overlay_0_02167564_overlay_0_02179a24: ; 0x02179A24
	.word _ZN17CFieldEffectBloom12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179a28
ptr_FUN_overlay_0_021421d0_overlay_0_02179a28: ; 0x02179A28
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179a2c
ptr_FUN_overlay_0_02142380_overlay_0_02179a2c: ; 0x02179A2C
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_02179a30
ptr_FUN_overlay_0_021421f0_overlay_0_02179a30: ; 0x02179A30
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02166b6c_overlay_0_02179a38
ptr_FUN_overlay_0_02166b6c_overlay_0_02179a38: ; 0x02179A38
	.word _ZN17CFieldEffectBloom12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02166f74_overlay_0_02179a3c
ptr_FUN_overlay_0_02166f74_overlay_0_02179a3c: ; 0x02179A3C
	.word _ZN17CFieldEffectBloom12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_02166a2c_overlay_0_02179a4c
ptr_FUN_overlay_0_02166a2c_overlay_0_02179a4c: ; 0x02179A4C
	.word _ZN17CFieldEffectBloom12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN17CFieldEffectBloom12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN17CFieldEffectBloom12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global s_MEF_overlay_0_02179a70
s_MEF_overlay_0_02179a70: ; 0x02179A70
	.asciz "MEF"

    .global s_data_Field_Effect_ef100_LZ_bin_overlay_0_02179a74
s_data_Field_Effect_ef100_LZ_bin_overlay_0_02179a74: ; 0x02179A74
	.asciz "data/Field/Effect/ef100_LZ.bin"

    .global DAT_overlay_0_02179A93
DAT_overlay_0_02179A93:
	.byte 0x00

    .global s_MEF_ef100_02d_ntft_overlay_0_02179a94
s_MEF_ef100_02d_ntft_overlay_0_02179a94: ; 0x02179A94
	.asciz "MEF:ef100_%02d.ntft"

    .global s_MEF_ef100_02d_ntfp_overlay_0_02179aa8
s_MEF_ef100_02d_ntfp_overlay_0_02179aa8: ; 0x02179AA8
	.asciz "MEF:ef100_%02d.ntfp"

    .global PTR_ptr_FUN_020835bc_overlay_0_02179abc
PTR_ptr_FUN_020835bc_overlay_0_02179abc: ; 0x02179ABC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21CFieldEffectDarkCloud9CAnimat_overlay_0_02179be8
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ac8
PTR_ptr_FUN_020835bc_overlay_0_02179ac8: ; 0x02179AC8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21CFieldEffectDarkCloud8CEmitte_overlay_0_02179bc4
	.word _ZTI30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ad4
PTR_ptr_FUN_020835bc_overlay_0_02179ad4: ; 0x02179AD4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21CFieldEffectDarkCloud16CRemai_overlay_0_02179c38
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ae0
PTR_ptr_FUN_020835bc_overlay_0_02179ae0: ; 0x02179AE0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_21CFieldEffectDarkCloud_overlay_0_02179b2c
	.word _ZTI20TFieldEffectParticleI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02179aec
PTR_ptr_FUN_020835bc_overlay_0_02179aec: ; 0x02179AEC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21CFieldEffectDarkCloud15CRemai_overlay_0_02179c0c
	.word _ZTI30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_02179af8
PTR_ptr_FUN_020835bc_overlay_0_02179af8: ; 0x02179AF8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_28CFieldEffectDarkCloudFactory_overlay_0_02179b44
	.word _ZTI19CFieldEffectFactory
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179abc

    .global PTR_LAB_overlay_0_02167984_overlay_0_02179b0c
PTR_LAB_overlay_0_02167984_overlay_0_02179b0c: ; 0x02179B0C
	.word _ZN21CFieldEffectDarkCloud9CAnimatorD1Ev

    .global ptr_FUN_overlay_0_02168efc_overlay_0_02179b10
ptr_FUN_overlay_0_02168efc_overlay_0_02179b10: ; 0x02179B10
	.word ov0_02168EFC

    .global ptr_FUN_overlay_0_02168998_overlay_0_02179b14
ptr_FUN_overlay_0_02168998_overlay_0_02179b14: ; 0x02179B14
	.word _ZN21CFieldEffectDarkCloud9CAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ad4

    .global PTR_LAB_overlay_0_02167990_overlay_0_02179b20
PTR_LAB_overlay_0_02167990_overlay_0_02179b20: ; 0x02179B20
	.word _ZN21CFieldEffectDarkCloud16CRemainsAnimatorD1Ev

    .global ptr_FUN_overlay_0_02168f38_overlay_0_02179b24
ptr_FUN_overlay_0_02168f38_overlay_0_02179b24: ; 0x02179B24
	.word ov0_02168F38

    .global ptr_FUN_overlay_0_02168d94_overlay_0_02179b28
ptr_FUN_overlay_0_02168d94_overlay_0_02179b28: ; 0x02179B28
	.word _ZN21CFieldEffectDarkCloud16CRemainsAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_21CFieldEffectDarkCloud_overlay_0_02179b2c
s_21CFieldEffectDarkCloud_overlay_0_02179b2c: ; 0x02179B2C
	.asciz "21CFieldEffectDarkCloud"

    .global s_28CFieldEffectDarkCloudFactory_overlay_0_02179b44
s_28CFieldEffectDarkCloudFactory_overlay_0_02179b44: ; 0x02179B44
	.asciz "28CFieldEffectDarkCloudFactory"

    .global DAT_overlay_0_02179B63
DAT_overlay_0_02179B63:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02179aec

    .global PTR_LAB_overlay_0_0216798c_overlay_0_02179b6c
PTR_LAB_overlay_0_0216798c_overlay_0_02179b6c: ; 0x02179B6C
	.word _ZN21CFieldEffectDarkCloud15CRemainsEmitterD1Ev

    .global ptr_FUN_overlay_0_02168f24_overlay_0_02179b70
ptr_FUN_overlay_0_02168f24_overlay_0_02179b70: ; 0x02179B70
	.word ov0_02168F24
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE5func2Ev
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE6UpdateEi

    .global ptr_FUN_overlay_0_02168c2c_overlay_0_02179b7c
ptr_FUN_overlay_0_02168c2c_overlay_0_02179b7c: ; 0x02179B7C
	.word _ZN21CFieldEffectDarkCloud15CRemainsEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE4StopEv
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ac8

    .global PTR_LAB_overlay_0_02167988_overlay_0_02179b8c
PTR_LAB_overlay_0_02167988_overlay_0_02179b8c: ; 0x02179B8C
	.word _ZN21CFieldEffectDarkCloud8CEmitterD1Ev

    .global ptr_FUN_overlay_0_02168f10_overlay_0_02179b90
ptr_FUN_overlay_0_02168f10_overlay_0_02179b90: ; 0x02179B90
	.word ov0_02168F10
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE5func2Ev
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE6UpdateEi

    .global ptr_FUN_overlay_0_02168ab8_overlay_0_02179b9c
ptr_FUN_overlay_0_02168ab8_overlay_0_02179b9c: ; 0x02179B9C
	.word _ZN21CFieldEffectDarkCloud8CEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
	.word _ZN30TFieldParticleSmokeRectEmitterI15CSoftwareSpriteE4StopEv
	.global _ZTV28CFieldEffectDarkCloudFactory
_ZTV28CFieldEffectDarkCloudFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179af8

    .global PTR_LAB_overlay_0_02151898_overlay_0_02179bac
PTR_LAB_overlay_0_02151898_overlay_0_02179bac: ; 0x02179BAC
	.word _ZN28CFieldEffectDarkCloudFactoryD1Ev

    .global ptr_FUN_overlay_0_02168f4c_overlay_0_02179bb0
ptr_FUN_overlay_0_02168f4c_overlay_0_02179bb0: ; 0x02179BB0
	.word ov0_02168F4C

    .global ptr_FUN_overlay_0_02168e38_overlay_0_02179bb4
ptr_FUN_overlay_0_02168e38_overlay_0_02179bb4: ; 0x02179BB4
	.word _ZN28CFieldEffectDarkCloudFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_N21CFieldEffectDarkCloud8CEmitte_overlay_0_02179bc4
s_N21CFieldEffectDarkCloud8CEmitte_overlay_0_02179bc4: ; 0x02179BC4
	.asciz "N21CFieldEffectDarkCloud8CEmitterE"

    .global DAT_overlay_0_02179BE7
DAT_overlay_0_02179BE7:
	.byte 0x00

    .global s_N21CFieldEffectDarkCloud9CAnimat_overlay_0_02179be8
s_N21CFieldEffectDarkCloud9CAnimat_overlay_0_02179be8: ; 0x02179BE8
	.asciz "N21CFieldEffectDarkCloud9CAnimatorE"

    .global s_N21CFieldEffectDarkCloud15CRemai_overlay_0_02179c0c
s_N21CFieldEffectDarkCloud15CRemai_overlay_0_02179c0c: ; 0x02179C0C
	.asciz "N21CFieldEffectDarkCloud15CRemainsEmitterE"

    .global DAT_overlay_0_02179C37
DAT_overlay_0_02179C37:
	.byte 0x00

    .global s_N21CFieldEffectDarkCloud16CRemai_overlay_0_02179c38
s_N21CFieldEffectDarkCloud16CRemai_overlay_0_02179c38: ; 0x02179C38
	.asciz "N21CFieldEffectDarkCloud16CRemainsAnimatorE"

    .global DAT_overlay_0_02179C64
DAT_overlay_0_02179C64:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ae0

    .global ptr_FUN_overlay_0_02167994_overlay_0_02179c6c
ptr_FUN_overlay_0_02167994_overlay_0_02179c6c: ; 0x02179C6C
	.word _ZN21CFieldEffectDarkCloudD1Ev

    .global ptr_FUN_overlay_0_02167a98_overlay_0_02179c70
ptr_FUN_overlay_0_02167a98_overlay_0_02179c70: ; 0x02179C70
	.word ov0_02167A98

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179c74
ptr_FUN_overlay_0_021423a4_overlay_0_02179c74: ; 0x02179C74
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN21CFieldEffectDarkCloud12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179c80
ptr_FUN_overlay_0_021421d0_overlay_0_02179c80: ; 0x02179C80
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179c84
ptr_FUN_overlay_0_02142380_overlay_0_02179c84: ; 0x02179C84
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_02167ec8_overlay_0_02179c88
ptr_FUN_overlay_0_02167ec8_overlay_0_02179c88: ; 0x02179C88
	.word _ZN21CFieldEffectDarkCloud12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_021681fc_overlay_0_02179c90
ptr_FUN_overlay_0_021681fc_overlay_0_02179c90: ; 0x02179C90
	.word _ZN21CFieldEffectDarkCloud12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02168860_overlay_0_02179c94
ptr_FUN_overlay_0_02168860_overlay_0_02179c94: ; 0x02179C94
	.word _ZN21CFieldEffectDarkCloud12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_02167bdc_overlay_0_02179ca4
ptr_FUN_overlay_0_02167bdc_overlay_0_02179ca4: ; 0x02179CA4
	.word _ZN21CFieldEffectDarkCloud12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et

    .global ptr_FUN_overlay_0_0216893c_overlay_0_02179cb0
ptr_FUN_overlay_0_0216893c_overlay_0_02179cb0: ; 0x02179CB0
	.word _ZN21CFieldEffectDarkCloud12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global ptr_FUN_overlay_0_021423e8_overlay_0_02179cc8
ptr_FUN_overlay_0_021423e8_overlay_0_02179cc8: ; 0x02179CC8
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021423E8ERK20FieldEffectSpriteRes
	.word _ZN21CFieldEffectDarkCloud13GetForceFieldEv
	.word _ZN21CFieldEffectDarkCloud10GetEmitterEv

    .global ptr_FUN_overlay_0_02167ba4_overlay_0_02179cd4
ptr_FUN_overlay_0_02167ba4_overlay_0_02179cd4: ; 0x02179CD4
	.word ov0_02167BA4

    .global PTR_ptr_FUN_020835bc_overlay_0_02179cd8
PTR_ptr_FUN_020835bc_overlay_0_02179cd8: ; 0x02179CD8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_28CFieldEffectFireworksFactory_overlay_0_02179d38
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_02179ce4
PTR_ptr_FUN_020835bc_overlay_0_02179ce4: ; 0x02179CE4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_21CFieldEffectFireworks_overlay_0_02179d20
	.word _ZTI12CFieldEffect

    .global PTR_ptr_FUN_020835bc_overlay_0_02179cf0
PTR_ptr_FUN_020835bc_overlay_0_02179cf0: ; 0x02179CF0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_11CMeshSprite_overlay_0_02179cfc
	.word _ZTI10CPrimitive

    .global s_11CMeshSprite_overlay_0_02179cfc
s_11CMeshSprite_overlay_0_02179cfc: ; 0x02179CFC
	.asciz "11CMeshSprite"

    .global DAT_overlay_0_02179D0A
DAT_overlay_0_02179D0A:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179cf0

    .global ptr_s_DWCi_MOV_WH_StepDataSharing_Wa_overlay_11_02169738_overlay_0_02179d14
ptr_s_DWCi_MOV_WH_StepDataSharing_Wa_overlay_11_02169738_overlay_0_02179d14: ; 0x02179D14
	.word _ZN11CMeshSpriteD1Ev

    .global ptr_FUN_overlay_0_02169968_overlay_0_02179d18
ptr_FUN_overlay_0_02169968_overlay_0_02179d18: ; 0x02179D18
	.word ov0_02169968

    .global ptr_FUN_overlay_0_021691a8_overlay_0_02179d1c
ptr_FUN_overlay_0_021691a8_overlay_0_02179d1c: ; 0x02179D1C
	.word _ZN11CMeshSprite6RenderEP8Camera2D

    .global s_21CFieldEffectFireworks_overlay_0_02179d20
s_21CFieldEffectFireworks_overlay_0_02179d20: ; 0x02179D20
	.asciz "21CFieldEffectFireworks"

    .global s_28CFieldEffectFireworksFactory_overlay_0_02179d38
s_28CFieldEffectFireworksFactory_overlay_0_02179d38: ; 0x02179D38
	.asciz "28CFieldEffectFireworksFactory"

    .global DAT_overlay_0_02179D57
DAT_overlay_0_02179D57:
	.byte 0x00
	.global _ZTV28CFieldEffectFireworksFactory
_ZTV28CFieldEffectFireworksFactory:
	.byte 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_02179cd8

    .global PTR_LAB_overlay_0_0215189c_overlay_0_02179d60
PTR_LAB_overlay_0_0215189c_overlay_0_02179d60: ; 0x02179D60
	.word _ZN28CFieldEffectFireworksFactoryD1Ev
	.word ov0_021699F4

    .global ptr_FUN_overlay_0_021698c0_overlay_0_02179d68
ptr_FUN_overlay_0_021698c0_overlay_0_02179d68: ; 0x02179D68
	.word _ZN28CFieldEffectFireworksFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_02179ce4

    .global ptr_FUN_overlay_0_02169984_overlay_0_02179d80
ptr_FUN_overlay_0_02169984_overlay_0_02179d80: ; 0x02179D80
	.word _ZN21CFieldEffectFireworksD1Ev

    .global ptr_FUN_overlay_0_021699b8_overlay_0_02179d84
ptr_FUN_overlay_0_021699b8_overlay_0_02179d84: ; 0x02179D84
	.word ov0_021699B8

    .global ptr_FUN_overlay_0_021423a4_overlay_0_02179d88
ptr_FUN_overlay_0_021423a4_overlay_0_02179d88: ; 0x02179D88
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN21CFieldEffectFireworks12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_02179d94
ptr_FUN_overlay_0_021421d0_overlay_0_02179d94: ; 0x02179D94
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_02179d98
ptr_FUN_overlay_0_02142380_overlay_0_02179d98: ; 0x02179D98
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_021421f0_overlay_0_02179d9c
ptr_FUN_overlay_0_021421f0_overlay_0_02179d9c: ; 0x02179D9C
	.word _ZN12CFieldEffect12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_021697ac_overlay_0_02179da4
ptr_FUN_overlay_0_021697ac_overlay_0_02179da4: ; 0x02179DA4
	.word _ZN21CFieldEffectFireworks12ov0_02142264Ei

    .global ptr_FUN_overlay_0_02169884_overlay_0_02179da8
ptr_FUN_overlay_0_02169884_overlay_0_02179da8: ; 0x02179DA8
	.word _ZN21CFieldEffectFireworks12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN21CFieldEffectFireworks12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN21CFieldEffectFireworks12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

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
	.word _ZN22CFieldEffectDarkShadow12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_02169c30_overlay_0_02179e90
ptr_FUN_overlay_0_02169c30_overlay_0_02179e90: ; 0x02179E90
	.word _ZN22CFieldEffectDarkShadow12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et

    .global ptr_FUN_overlay_0_0216a2d4_overlay_0_02179e9c
ptr_FUN_overlay_0_0216a2d4_overlay_0_02179e9c: ; 0x02179E9C
	.word _ZN22CFieldEffectDarkShadow12sub_0203331CERK7Point2Di

    .global ptr_FUN_overlay_0_0216a270_overlay_0_02179ea0
ptr_FUN_overlay_0_0216a270_overlay_0_02179ea0: ; 0x02179EA0
	.word _ZN22CFieldEffectDarkShadow12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED1Ev

    .global ptr_FUN_overlay_0_0216c6bc_overlay_0_02179f70
ptr_FUN_overlay_0_0216c6bc_overlay_0_02179f70: ; 0x02179F70
	.word _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED0Ev
	.word _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE5func2Ev
	.word _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE6UpdateEi
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
	.word _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE5func2Ev
	.word _ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE6UpdateEi
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
	.word _ZN25CFieldEffectDarknessClear12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216a804_overlay_0_0217a254
ptr_FUN_overlay_0_0216a804_overlay_0_0217a254: ; 0x0217A254
	.word _ZN25CFieldEffectDarknessClear12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98
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
	.word _ZN12CFieldEffect12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216aac8_overlay_0_0217a2c4
ptr_FUN_overlay_0_0216aac8_overlay_0_0217a2c4: ; 0x0217A2C4
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98
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
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216b744_overlay_0_0217a334
ptr_FUN_overlay_0_0216b744_overlay_0_0217a334: ; 0x0217A334
	.word _ZN26CFieldEffectDarknessClear212sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98
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
	.word _ZN22CFieldEffectAirBubbles12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216cdb8_overlay_0_0217a5bc
ptr_FUN_overlay_0_0216cdb8_overlay_0_0217a5bc: ; 0x0217A5BC
	.word _ZN22CFieldEffectAirBubbles12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN17CFieldEffectLaser12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN17CFieldEffectLaser12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN24CFieldEffectRisingPhoton12sub_02033028Ev
	.word _ZN24CFieldEffectRisingPhoton12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216e324_overlay_0_0217a77c
ptr_FUN_overlay_0_0216e324_overlay_0_0217a77c: ; 0x0217A77C
	.word _ZN24CFieldEffectRisingPhoton12sub_0203312CEii

    .global ptr_FUN_overlay_0_0216e4e0_overlay_0_0217a780
ptr_FUN_overlay_0_0216e4e0_overlay_0_0217a780: ; 0x0217A780
	.word _ZN24CFieldEffectRisingPhoton12sub_02033244Eiii
	.word _ZN24CFieldEffectRisingPhoton12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN25CFieldEffectVolcanicSteam9CAnimator17CEffectDrawObject12sub_020091D4EP8Camera2Di

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
	.word _ZN12CFieldEffect12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN17TFieldEffectSmokeI16CSimpleSpriteNTFE12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98
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
	.word _ZN25CFieldEffectVolcanicSteam12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN25CFieldEffectVolcanicSteam12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN25CFieldEffectVolcanicSteam12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv
	.word _ZN20TFieldEffectParticleI16CSimpleSpriteNTFE12ov0_021423E8ERKP17UnkClass_02041D98
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
	.word _ZN23CFieldEffectFuwanteWind12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0216f7b0_overlay_0_0217abe4
ptr_FUN_overlay_0_0216f7b0_overlay_0_0217abe4: ; 0x0217ABE4
	.word _ZN23CFieldEffectFuwanteWind12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN17CFieldEffectManpu12sub_02033028Ev
	.word _ZN17CFieldEffectActor12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN12CFieldEffect12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN19CFieldEffectGlitter12sub_02033028Ev
	.word _ZN19CFieldEffectGlitter12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_021709d0_overlay_0_0217ad5c
ptr_FUN_overlay_0_021709d0_overlay_0_0217ad5c: ; 0x0217AD5C
	.word _ZN19CFieldEffectGlitter12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN19CFieldEffectGlitter12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN26CFieldEffectBlackStoneAura12sub_02033028Ev
	.word _ZN26CFieldEffectBlackStoneAura12sub_020332A4Ev

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
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN26CFieldEffectBlackStoneAura12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
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
	.word _ZN24CFieldEffectSpaceCrevice17CEffectDrawObject12sub_020091D4EP8Camera2Di
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
	.word _ZN24CFieldEffectSpaceCrevice12sub_02033028Ev

    .global ptr_FUN_overlay_0_02172b94_overlay_0_0217b01c
ptr_FUN_overlay_0_02172b94_overlay_0_0217b01c: ; 0x0217B01C
	.word _ZN24CFieldEffectSpaceCrevice12sub_020332A4Ev

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
	.word _ZN24CFieldEffectSpaceCrevice12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii
	.word _ZN24CFieldEffectSpaceCrevice12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN24CFieldEffectSpaceCrevice12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN24CFieldEffectSpaceCrevice12sub_020333D8Eii
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
