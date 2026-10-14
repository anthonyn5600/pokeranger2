    .include "macros.inc"
    .include "include/overlay_00_0215BDCC.inc"

    .text

	arm_func_start ov0_0215BDCC
ov0_0215BDCC: ; 0x0215BDCC
	stmdb sp!, {r4, lr}
	ldr r1, _0215BE6C ; =_ZTV12CFieldEffect+8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r0, _0215BE70 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r3, #0
	str r0, [r4]
	str r3, [r4, #0x1c]
	str r3, [r4, #0x20]
	ldr r0, _0215BE74 ; =ptr_FUN_overlay_0_0215c5e0_overlay_0_021786bc
	str r3, [r4, #0x24]
	ldr r2, _0215BE78 ; =PTR_LAB_overlay_0_0215be88_overlay_0_021785ec
	str r0, [r4]
	mov r1, #0x1000
	ldr r0, _0215BE7C ; =_ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
	str r2, [r4, #0x28]
	str r0, [r4, #0x2c]
	str r3, [r4, #0x40]
	str r3, [r4, #0x30]
	str r3, [r4, #0x34]
	str r3, [r4, #0x38]
	ldr r0, _0215BE80 ; =_ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
	str r1, [r4, #0x3c]
	str r0, [r4, #0x2c]
	str r3, [r4, #0x54]
	str r3, [r4, #0x58]
	str r1, [r4, #0x44]
	str r3, [r4, #0x48]
	str r3, [r4, #0x4c]
	sub r1, r1, #0x2000
	ldr r0, _0215BE84 ; =PTR_LAB_overlay_0_0215be8c_overlay_0_0217861c
	str r1, [r4, #0x50]
	str r0, [r4, #0x2c]
	mov r1, #0x28000
	mov r0, r4
	str r1, [r4, #0x68]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0215BE6C: .word _ZTV12CFieldEffect+8
_0215BE70: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0215BE74: .word ptr_FUN_overlay_0_0215c5e0_overlay_0_021786bc
_0215BE78: .word PTR_LAB_overlay_0_0215be88_overlay_0_021785ec
_0215BE7C: .word _ZTV21TFieldParticleEmitterI15CSoftwareSpriteE+8
_0215BE80: .word _ZTV25TFieldParticleRectEmitterI15CSoftwareSpriteE+8
_0215BE84: .word PTR_LAB_overlay_0_0215be8c_overlay_0_0217861c
	arm_func_end ov0_0215BDCC

	arm_func_start _ZN28CFieldParticleLeavesAnimatorD1Ev
_ZN28CFieldParticleLeavesAnimatorD1Ev: ; 0x0215BE88
	bx lr
	arm_func_end _ZN28CFieldParticleLeavesAnimatorD1Ev

	arm_func_start _ZN27CFieldParticleLeavesEmitterD1Ev
_ZN27CFieldParticleLeavesEmitterD1Ev: ; 0x0215BE8C
	bx lr
	arm_func_end _ZN27CFieldParticleLeavesEmitterD1Ev

	arm_func_start _ZN25CFieldEffectScatterLeaves12sub_0203312CEii
_ZN25CFieldEffectScatterLeaves12sub_0203312CEii: ; 0x0215BE90
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r5, r2
	cmp r1, #8
	mov r0, #1
	addls pc, pc, r1, lsl #2
	b _0215BF1C
_0215BEB0: ; jump table
	b _0215BF1C ; case 0
	b _0215BF1C ; case 1
	b _0215BF1C ; case 2
	b _0215BEE0 ; case 3
	b _0215BEF0 ; case 4
	b _0215BF00 ; case 5
	b _0215BED4 ; case 6
	b _0215BF1C ; case 7
	b _0215BF0C ; case 8
	arm_func_end _ZN25CFieldEffectScatterLeaves12sub_0203312CEii
_0215BED4:
	add sp, sp, #4
	str r5, [r6, #0x64]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215BEE0:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x54]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215BEF0:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x58]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215BF00:
	add sp, sp, #4
	str r5, [r6, #0x5c]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215BF0C:
	mov r1, r5, lsl #0xc
	add sp, sp, #4
	str r1, [r6, #0x68]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215BF1C:
	cmp r1, #0
	mov r0, #0
	beq _0215BF40
	cmp r1, #1
	beq _0215C16C
	cmp r1, #2
	beq _0215C184
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215BF40:
	cmp r5, #0
	ble _0215C160
	ldr r4, [r6, #0x18]
	cmp r4, #0
	beq _0215BFBC
	beq _0215BFB4
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0215BF70
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x10]
_0215BF70:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0215BF88
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0xc]
_0215BF88:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _0215BFAC
	ldr r3, _0215C19C ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x28]
_0215BFAC:
	mov r0, r4
	bl _ZdlPv
_0215BFB4:
	mov r0, #0
	str r0, [r6, #0x18]
_0215BFBC:
	mov r0, #0x3c
	bl _Znwm
	movs r4, r0
	beq _0215C0F4
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
	beq _0215C098
	ldr r1, _0215C19C ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	ldr r3, _0215C1A0 ; =_ZN14TFieldParticleI15CSoftwareSpriteEC1Ev
	str r1, [sp]
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x28]
	ldr r1, [r4, #0x2c]
	mov lr, #0
	mov r0, lr
	cmp r1, #0
	bls _0215C08C
	mov r1, lr
	mov ip, lr
	mov r2, #0x74
_0215C040:
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
	blo _0215C040
_0215C08C:
	ldr r0, [r4, #0x28]
	str r0, [r4, #0x34]
	b _0215C0A0
_0215C098:
	str r1, [r4, #0x28]
	str r1, [r4, #0x34]
_0215C0A0:
	mov r1, #0
	str r1, [r4, #0x38]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	streq r1, [r4, #0xc]
	streq r1, [r4, #0x10]
	beq _0215C0E8
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
_0215C0E8:
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
_0215C0F4:
	str r4, [r6, #0x18]
	cmp r4, #0
	beq _0215C160
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #0x64]
	blx r1
	ldr r2, [r6, #0x18]
	ldr r1, [r2, #0x14]
	cmp r1, #0
	bls _0215C12C
	ldr r1, [r2, #0xc]
	cmp r1, #0
	strne r0, [r1]
_0215C12C:
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
_0215C160:
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215C16C:
	ldr r2, [r6, #0x18]
	add sp, sp, #4
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2]
	ldmia sp!, {r3, r4, r5, r6, pc}
_0215C184:
	ldr r2, [r6, #0x18]
	cmp r2, #0
	movne r1, r5, lsl #0xc
	strne r1, [r2, #4]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0215C19C: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0215C1A0: .word _ZN14TFieldParticleI15CSoftwareSpriteEC1Ev

	arm_func_start _ZN27CFieldParticleLeavesEmitter6UpdateEi
_ZN27CFieldParticleLeavesEmitter6UpdateEi: ; 0x0215C1A4
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r2, [r4, #0x34]
	mov r0, #0
	cmp r2, #0
	ldmleia sp!, {r4, r5, r6, pc}
	sub r1, r2, r1
	str r1, [r4, #0x34]
	cmp r1, #0
	ldmgtia sp!, {r4, r5, r6, pc}
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r6, r1, #0x1400
	add r0, r0, #0x1000
	ldr r2, [r0, #0x448]
	ldmib r6, {r1, r3}
	umull lr, ip, r3, r2
	mla ip, r3, r1, ip
	ldr r1, [r6, #0xc]
	ldr r5, [r6, #0x10]
	mla ip, r1, r2, ip
	ldr r3, [r6, #0x14]
	adds r5, r5, lr
	str r5, [r0, #0x448]
	adc r3, r3, ip
	mov r0, #5
	umull r0, r2, r3, r0
	str r3, [r6, #4]
	ldr r1, [r4, #0x30]
	add r0, r2, #8
	cmp r1, #0
	movgt r1, r1, lsl #0xc
	strgt r1, [r4, #0x34]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end _ZN27CFieldParticleLeavesEmitter6UpdateEi

	arm_func_start _ZN27CFieldParticleLeavesEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_ZN27CFieldParticleLeavesEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE: ; 0x0215C22C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN5CGame11GetInstanceEv
	ldr r3, _0215C49C ; =MAIN_BSS_0210CEC8
	ldr ip, _0215C4A0 ; =0x00007FFF
	ldmia r3, {r1, r2, r6}
	mla r1, r2, r1, r6
	mla r7, r2, r1, r6
	ldr r2, [r5, #0x28]
	mov r8, r1, lsr #0x10
	str r1, [r3]
	ldr r1, [r5, #0x2c]
	mov r6, r7, lsr #0x10
	str r7, [r3]
	mov r3, r8, lsl #0x10
	and r7, ip, r3, lsr #16
	mov r3, r6, lsl #0x10
	and r3, ip, r3, lsr #16
	mov r6, r7, asr #3
	smull r7, r8, r6, r2
	mov r3, r3, asr #3
	adds sb, r7, #0x800
	smull r7, r6, r3, r1
	adc r3, r8, #0
	mov r8, sb, lsr #0xc
	orr r8, r8, r3, lsl #20
	adds r7, r7, #0x800
	adc r3, r6, #0
	mov r6, r7, lsr #0xc
	orr r6, r6, r3, lsl #20
	sub r8, r8, r2, asr #1
	ldmib r5, {r3, r7}
	sub r2, r6, r1, asr #1
	add r1, r3, r8
	str r1, [r4, #0x4c]
	add r1, r7, r2
	str r1, [r4, #0x50]
	ldr r1, [r5, #0x3c]
	add lr, r0, #0x48
	str r1, [r4, #0x60]
	str r1, [r4, #0x64]
	add r3, lr, #0x1400
	add ip, r0, #0x1000
	ldr r2, [ip, #0x448]
	ldmib r3, {r1, r5}
	umull r7, r6, r5, r2
	mla r6, r5, r1, r6
	ldr r1, [r3, #0xc]
	ldr r8, [r3, #0x10]
	mla r6, r1, r2, r6
	mov r1, #0
	mov r2, r1, lsl #2
	ldr r5, [r3, #0x14]
	adds r7, r8, r7
	adc r5, r5, r6
	str r7, [ip, #0x448]
	ldr r1, _0215C4A4 ; =DAT_overlay_0_021785d4
	orr r2, r2, r5, lsr #30
	ldr r2, [r1, r2, lsl #2]
	str r5, [r3, #4]
	strh r2, [r4, #0x2a]
	mov r1, #0
	mov r6, r1, lsl #0xe
	ldr r2, [ip, #0x448]
	ldmib r3, {r1, r8}
	umull lr, sb, r8, r2
	mla sb, r8, r1, sb
	ldr r7, [r3, #0xc]
	ldr fp, [r3, #0x10]
	mla sb, r7, r2, sb
	ldr sl, [r3, #0x14]
	adds r1, fp, lr
	adc r2, sl, sb
	orr r6, r6, r2, lsr #18
	str r1, [ip, #0x448]
	mov r6, r6, asr #4
	str r2, [r3, #4]
	mov r6, r6, lsl #1
	ldr r1, [ip, #0x448]
	add r6, r6, #1
	ldr ip, _0215C4A8 ; =FX_SinCosTable_
	mov r6, r6, lsl #1
	ldrsh r6, [ip, r6]
	mov r5, #0xb6
	mov ip, r6, lsl #1
	ldr r6, [r4, #0x4c]
	cmp r6, #0
	bne _0215C3D4
	ldr r7, [r3, #8]
	ldr r6, [r3, #0xc]
	umull sb, r8, r7, r1
	mla r8, r7, r2, r8
	mla r8, r6, r1, r8
	ldr r2, [r3, #0x10]
	ldr r1, [r3, #0x14]
	adds r6, r2, sb
	adc r2, r1, r8
	mov r1, #0
	str r6, [r3]
	mov r1, r1, lsl #1
	orrs r1, r1, r2, lsr #31
	str r2, [r3, #4]
	subeq r5, r5, #0x16c
	rsbeq ip, ip, #0
	b _0215C3DC
	arm_func_end _ZN27CFieldParticleLeavesEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE
_0215C3D4:
	sublt r5, r5, #0x16c
	rsblt ip, ip, #0
_0215C3DC:
	add r1, r0, #0x48
	add r0, r0, #0x1000
	add r3, r1, #0x1400
	ldr r2, [r0, #0x448]
	ldmib r3, {r1, r6}
	umull r8, r7, r6, r2
	mla r7, r6, r1, r7
	ldr r6, [r3, #0xc]
	ldr sb, [r3, #0x10]
	mla r7, r6, r2, r7
	ldr r2, [r3, #0x14]
	adds r6, sb, r8
	mov r1, #0
	adc r2, r2, r7
	mov r7, r1, lsl #0xe
	orr r7, r7, r2, lsr #18
	mov r8, r7, asr #4
	str r6, [r0, #0x448]
	str r2, [r3, #4]
	ldr r6, [r4, #0x50]
	ldr r7, _0215C4A8 ; =FX_SinCosTable_
	mov r8, r8, lsl #2
	ldrsh r7, [r7, r8]
	cmp r6, #0
	ldr r0, [r0, #0x448]
	mov lr, r7, lsl #1
	bne _0215C484
	ldr r7, [r3, #8]
	ldr r6, [r3, #0xc]
	umull sb, r8, r7, r0
	mla r8, r7, r2, r8
	mla r8, r6, r0, r8
	ldr r2, [r3, #0x10]
	ldr r0, [r3, #0x14]
	adds r6, r2, sb
	adc r2, r0, r8
	str r6, [r3]
	mov r0, r1, lsl #1
	orrs r0, r0, r2, lsr #31
	str r2, [r3, #4]
	rsbeq lr, lr, #0
	b _0215C48C
_0215C484:
	cmp r6, #0
	rsblt lr, lr, #0
_0215C48C:
	str ip, [r4, #0x54]
	str lr, [r4, #0x58]
	strh r5, [r4, #0x5e]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0215C49C: .word MAIN_BSS_0210CEC8
_0215C4A0: .word 0x00007FFF
_0215C4A4: .word DAT_overlay_0_021785d4
_0215C4A8: .word FX_SinCosTable_

	arm_func_start _ZN28CFieldParticleLeavesAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi
_ZN28CFieldParticleLeavesAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi: ; 0x0215C4AC
	stmdb sp!, {r3, lr}
	ldr r0, _0215C4D8 ; =0x00000199
	mov r3, r2, asr #0x1f
	umull lr, ip, r2, r0
	mla ip, r3, r0, ip
	mov r0, lr, lsr #0xc
	ldr r2, [r1, #0x58]
	orr r0, r0, ip, lsl #20
	add r0, r2, r0
	str r0, [r1, #0x58]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0215C4D8: .word 0x00000199
	arm_func_end _ZN28CFieldParticleLeavesAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

	arm_func_start _ZN32CFieldEffectScatterLeavesFactory6CreateEi
_ZN32CFieldEffectScatterLeavesFactory6CreateEi: ; 0x0215C4DC
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0xc
	mov r0, #0x6c
	mov r5, r1
	bl _Znwm
	movs r4, r0
	beq _0215C504
	mov r1, r5
	bl ov0_0215BDCC
	mov r4, r0
	arm_func_end _ZN32CFieldEffectScatterLeavesFactory6CreateEi
_0215C504:
	cmp r4, #0
	ldrne r0, _0215C590 ; =MAIN_BSS_0210CA60
	ldrne r5, [r0]
	cmpne r5, #0
	beq _0215C584
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
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #8]
	blx r2
	str r0, [sp]
	mov r0, r4
	str r5, [sp, #4]
	str r6, [sp, #8]
	ldr r2, [r0]
	add r1, sp, #0
	ldr r2, [r2, #0x5c]
	blx r2
_0215C584:
	mov r0, r4
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0215C590: .word MAIN_BSS_0210CA60

	arm_func_start _ZN25CFieldEffectScatterLeaves10GetEmitterEv
_ZN25CFieldEffectScatterLeaves10GetEmitterEv: ; 0x0215C594
	add r0, r0, #0x2c
	bx lr
	arm_func_end _ZN25CFieldEffectScatterLeaves10GetEmitterEv

	arm_func_start _ZN25CFieldEffectScatterLeaves13GetForceFieldEv
_ZN25CFieldEffectScatterLeaves13GetForceFieldEv: ; 0x0215C59C
	add r0, r0, #0x28
	bx lr
	arm_func_end _ZN25CFieldEffectScatterLeaves13GetForceFieldEv

	arm_func_start _ZN25CFieldEffectScatterLeaves12sub_02033028Ev
_ZN25CFieldEffectScatterLeaves12sub_02033028Ev: ; 0x0215C5A4
	mov r0, #0xb
	bx lr
	arm_func_end _ZN25CFieldEffectScatterLeaves12sub_02033028Ev

	arm_func_start _ZN27CFieldParticleLeavesEmitter5func2Ev
_ZN27CFieldParticleLeavesEmitter5func2Ev: ; 0x0215C5AC
	mov r1, #0x1000
	str r1, [r0, #0x34]
	bx lr
	arm_func_end _ZN27CFieldParticleLeavesEmitter5func2Ev

	arm_func_start ov0_0215C5B8
ov0_0215C5B8: ; 0x0215C5B8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0215C5B8

	arm_func_start ov0_0215C5CC
ov0_0215C5CC: ; 0x0215C5CC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0215C5CC

	arm_func_start _ZN25CFieldEffectScatterLeavesD1Ev
_ZN25CFieldEffectScatterLeavesD1Ev: ; 0x0215C5E0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0215C684 ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0215C664
	beq _0215C65C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0215C618
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end _ZN25CFieldEffectScatterLeavesD1Ev
_0215C618:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0215C630
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0215C630:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _0215C654
	ldr r3, _0215C688 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_0215C654:
	mov r0, r5
	bl _ZdlPv
_0215C65C:
	mov r0, #0
	str r0, [r4, #0x18]
_0215C664:
	ldr r1, _0215C68C ; =_ZTV12CFieldEffect+8
	mov r0, r4
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0215C684: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0215C688: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0215C68C: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0215C690
ov0_0215C690: ; 0x0215C690
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0215C73C ; =_ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0215C714
	beq _0215C70C
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0215C6C8
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x10]
	arm_func_end ov0_0215C690
_0215C6C8:
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _0215C6E0
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0xc]
_0215C6E0:
	ldr r0, [r5, #0x28]
	cmp r0, #0
	beq _0215C704
	ldr r3, _0215C740 ; =_ZN14TFieldParticleI15CSoftwareSpriteED1Ev
	mov r1, #0x74
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r5, #0x28]
_0215C704:
	mov r0, r5
	bl _ZdlPv
_0215C70C:
	mov r0, #0
	str r0, [r4, #0x18]
_0215C714:
	ldr r1, _0215C744 ; =_ZTV12CFieldEffect+8
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
_0215C73C: .word _ZTV20TFieldEffectParticleI15CSoftwareSpriteE+8
_0215C740: .word _ZN14TFieldParticleI15CSoftwareSpriteED1Ev
_0215C744: .word _ZTV12CFieldEffect+8

	arm_func_start ov0_0215C748
ov0_0215C748: ; 0x0215C748
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0215C748
