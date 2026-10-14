    .include "macros.inc"
    .include "include/overlay_03_02126E9C.inc"

    .text

	arm_func_start _ZN23CSimplePrimitiveQuadNTFC1Ev
_ZN23CSimplePrimitiveQuadNTFC1Ev: ; 0x02126E9C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _02126EC8 ; =_ZTV23CSimplePrimitiveQuadNTF+8
	mov r1, #0
	str r0, [r4]
	str r1, [r4, #0x18]
	str r1, [r4, #0x20]
	mov r0, r4
	str r1, [r4, #0x1c]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02126EC8: .word _ZTV23CSimplePrimitiveQuadNTF+8
	arm_func_end _ZN23CSimplePrimitiveQuadNTFC1Ev

	arm_func_start _ZN21COPDCaptureDiscScreenC1Ev
_ZN21COPDCaptureDiscScreenC1Ev: ; 0x02126ECC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02127230 ; =ptr_FUN_overlay_3_02127350_overlay_3_0212b218
	mov r4, r0
	ldr ip, _02127234 ; =_ZN15CSoftwareSpriteD1Ev
	str r1, [r4]
	ldr r3, _02127238 ; =FUN_02005150
	add r0, r4, #0xc
	mov r1, #1
	mov r2, #0x4c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r0, #0
	ldr ip, _0212723C ; =_ZN16CSimpleSpriteNTFD1Ev
	strh r0, [r4, #0x5c]
	ldr r3, _02127240 ; =_ZN16CSimpleSpriteNTFC1Ev
	add r0, r4, #0x60
	mov r1, #2
	mov r2, #0x5c
	str ip, [sp]
	bl __cxa_vec_ctor
	add r0, r4, #0x138
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _02127244 ; =ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	mov r1, #0
	str r0, [r4, #0x138]
	str r1, [r4, #0x150]
	str r1, [r4, #0x158]
	str r1, [r4, #0x15c]
	add r0, r4, #0x168
	str r1, [r4, #0x160]
	bl _ZN15CSoftwareSpriteC1Ev
	mov r1, #0
	str r1, [r4, #0x1b8]
	str r1, [r4, #0x1bc]
	str r1, [r4, #0x2bc]
	mov r0, #0x1000
	str r0, [r4, #0x2cc]
	mov r0, #1
	str r0, [r4, #0x2d8]
	str r1, [r4, #0x2e0]
	mov r2, #8
	str r2, [r4, #0x2e8]
	str r1, [r4, #0x2ec]
	ldr r0, [r4, #0x2e8]
	cmp r0, #0
	beq _02127014
	ldr r1, _02127248 ; =_ZN14TFieldParticleI10CSparkLineED1Ev
	ldr r3, _0212724C ; =_ZN14TFieldParticleI10CSparkLineEC1Ev
	str r1, [sp]
	mov r1, #0x58
	bl __cxa_vec_new
	str r0, [r4, #0x2e4]
	ldr r1, [r4, #0x2e8]
	mov r5, #0
	mov r0, r5
	cmp r1, #0
	bls _02127008
	mov r1, r5
	mov lr, r5
	mov r2, #0x58
	arm_func_end _ZN21COPDCaptureDiscScreenC1Ev
_02126FBC:
	ldr r3, [r4, #0x2e4]
	add ip, r0, #1
	add r3, r3, r1
	str r5, [r3, #0x50]
	ldr r3, [r4, #0x2e8]
	add r0, r0, #1
	cmp ip, r3
	ldrlo r3, [r4, #0x2e4]
	mlalo r5, ip, r2, r3
	ldr r3, [r4, #0x2e4]
	movhs r5, lr
	add r3, r3, r1
	str r5, [r3, #0x54]
	ldr ip, [r4, #0x2e4]
	ldr r3, [r4, #0x2e8]
	add r5, ip, r1
	cmp r0, r3
	add r1, r1, #0x58
	blo _02126FBC
_02127008:
	ldr r0, [r4, #0x2e4]
	str r0, [r4, #0x2f0]
	b _0212701C
_02127014:
	str r1, [r4, #0x2e4]
	str r1, [r4, #0x2f0]
_0212701C:
	mov r1, #0
	str r1, [r4, #0x2f4]
	ldr r0, [r4, #0x2d8]
	cmp r0, #0
	streq r1, [r4, #0x2d0]
	streq r1, [r4, #0x2d4]
	beq _02127064
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x2d0]
	ldr r1, [r4, #0x2d8]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x2d8]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x2d4]
_02127064:
	mov r1, #0
	str r1, [r4, #0x2c8]
	str r1, [r4, #0x2c4]
	mov r0, #0x1000
	str r0, [r4, #0x300]
	mov r0, #1
	str r0, [r4, #0x30c]
	str r1, [r4, #0x314]
	mov r0, #0x40
	str r0, [r4, #0x31c]
	str r1, [r4, #0x320]
	ldr r0, [r4, #0x31c]
	cmp r0, #0
	beq _02127130
	ldr r1, _02127250 ; =_ZN14TFieldParticleI13CLineParticleED1Ev
	ldr r3, _02127254 ; =_ZN14TFieldParticleI13CLineParticleEC1Ev
	str r1, [sp]
	mov r1, #0x8c
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x318]
	ldr r1, [r4, #0x31c]
	mov r5, #0
	mov r0, r5
	cmp r1, #0
	bls _02127124
	mov r1, r5
	mov lr, r5
	mov r2, #0x8c
_021270D8:
	ldr r3, [r4, #0x318]
	add ip, r0, #1
	add r3, r3, r1
	str r5, [r3, #0x84]
	ldr r3, [r4, #0x31c]
	add r0, r0, #1
	cmp ip, r3
	ldrlo r3, [r4, #0x318]
	mlalo r5, ip, r2, r3
	ldr r3, [r4, #0x318]
	movhs r5, lr
	add r3, r3, r1
	str r5, [r3, #0x88]
	ldr ip, [r4, #0x318]
	ldr r3, [r4, #0x31c]
	add r5, ip, r1
	cmp r0, r3
	add r1, r1, #0x8c
	blo _021270D8
_02127124:
	ldr r0, [r4, #0x318]
	str r0, [r4, #0x324]
	b _02127138
_02127130:
	str r1, [r4, #0x318]
	str r1, [r4, #0x324]
_02127138:
	mov r1, #0
	str r1, [r4, #0x328]
	ldr r0, [r4, #0x30c]
	cmp r0, #0
	streq r1, [r4, #0x304]
	streq r1, [r4, #0x308]
	beq _02127180
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x304]
	ldr r1, [r4, #0x30c]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x30c]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x308]
_02127180:
	mov r3, #0
	str r3, [r4, #0x2fc]
	ldr r0, _02127258 ; =PTR_LAB_overlay_3_02129124_overlay_3_0212b19c
	str r3, [r4, #0x2f8]
	str r0, [r4, #0x32c]
	str r3, [r4, #0x340]
	str r3, [r4, #0x330]
	str r3, [r4, #0x334]
	str r3, [r4, #0x338]
	mov r2, #0x1000
	ldr r0, _0212725C ; =PTR_LAB_overlay_3_02127340_overlay_3_0212b1d4
	str r2, [r4, #0x33c]
	str r0, [r4, #0x32c]
	str r3, [r4, #0x344]
	str r3, [r4, #0x348]
	ldr r1, _02127260 ; =PTR_LAB_overlay_3_02127344_overlay_3_0212b118
	str r3, [r4, #0x34c]
	str r1, [r4, #0x350]
	ldr r0, _02127264 ; =PTR_LAB_overlay_3_02129128_overlay_3_0212b1b8
	ldr ip, _02127268 ; =_ZN23CSimplePrimitiveQuadNTFD1Ev
	str r0, [r4, #0x354]
	str r3, [r4, #0x368]
	str r3, [r4, #0x358]
	str r3, [r4, #0x35c]
	str r3, [r4, #0x360]
	str r2, [r4, #0x364]
	ldr r0, _0212726C ; =PTR_LAB_overlay_3_02127348_overlay_3_0212b180
	mov r1, #0xa
	str r0, [r4, #0x354]
	str r3, [r4, #0x36c]
	ldr r0, _02127270 ; =PTR_LAB_overlay_3_0212734c_overlay_3_0212b154
	ldr r3, _02127274 ; =_ZN23CSimplePrimitiveQuadNTFC1Ev
	str r0, [r4, #0x370]
	add r0, r4, #0x374
	mov r2, #0x64
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r1, #0
	add r0, r4, #0x58
	mov r2, #4
	strb r1, [r4, #0x804]
	bl MI_CpuFill8
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02127230: .word ptr_FUN_overlay_3_02127350_overlay_3_0212b218
_02127234: .word _ZN15CSoftwareSpriteD1Ev
_02127238: .word _ZN15CSoftwareSpriteC1Ev
_0212723C: .word _ZN16CSimpleSpriteNTFD1Ev
_02127240: .word _ZN16CSimpleSpriteNTFC1Ev
_02127244: .word ptr_FUN_overlay_3_02129130_overlay_3_0212b458
_02127248: .word _ZN14TFieldParticleI10CSparkLineED1Ev
_0212724C: .word _ZN14TFieldParticleI10CSparkLineEC1Ev
_02127250: .word _ZN14TFieldParticleI13CLineParticleED1Ev
_02127254: .word _ZN14TFieldParticleI13CLineParticleEC1Ev
_02127258: .word PTR_LAB_overlay_3_02129124_overlay_3_0212b19c
_0212725C: .word PTR_LAB_overlay_3_02127340_overlay_3_0212b1d4
_02127260: .word PTR_LAB_overlay_3_02127344_overlay_3_0212b118
_02127264: .word PTR_LAB_overlay_3_02129128_overlay_3_0212b1b8
_02127268: .word _ZN23CSimplePrimitiveQuadNTFD1Ev
_0212726C: .word PTR_LAB_overlay_3_02127348_overlay_3_0212b180
_02127270: .word PTR_LAB_overlay_3_0212734c_overlay_3_0212b154
_02127274: .word _ZN23CSimplePrimitiveQuadNTFC1Ev

	arm_func_start _ZN14TFieldParticleI10CSparkLineEC1Ev
_ZN14TFieldParticleI10CSparkLineEC1Ev: ; 0x02127278
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveLINEC2Ev
	ldr r1, _021272AC ; =PTR_LAB_overlay_3_021272b4_overlay_3_0212b12c
	mov r0, #0
	str r1, [r4]
	str r0, [r4, #0x4c]
	mov r0, #8
	ldr r1, _021272B0 ; =0x00000622
	str r0, [r4, #0x10]
	mov r0, r4
	str r1, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_021272AC: .word PTR_LAB_overlay_3_021272b4_overlay_3_0212b12c
_021272B0: .word 0x00000622
	arm_func_end _ZN14TFieldParticleI10CSparkLineEC1Ev

	arm_func_start _ZN10CSparkLineD1Ev
_ZN10CSparkLineD1Ev: ; 0x021272B4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveLINED2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN10CSparkLineD1Ev

	arm_func_start _ZN14TFieldParticleI10CSparkLineED1Ev
_ZN14TFieldParticleI10CSparkLineED1Ev: ; 0x021272C8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveLINED2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN14TFieldParticleI10CSparkLineED1Ev

	arm_func_start _ZN14TFieldParticleI13CLineParticleEC1Ev
_ZN14TFieldParticleI13CLineParticleEC1Ev: ; 0x021272DC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveQUADC2Ev
	ldr r1, _02127310 ; =PTR_LAB_overlay_3_02127318_overlay_3_0212b140
	mov r0, #0
	str r1, [r4]
	str r0, [r4, #0x80]
	mov r0, #8
	ldr r1, _02127314 ; =0x00000622
	str r0, [r4, #0x10]
	mov r0, r4
	str r1, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02127310: .word PTR_LAB_overlay_3_02127318_overlay_3_0212b140
_02127314: .word 0x00000622
	arm_func_end _ZN14TFieldParticleI13CLineParticleEC1Ev

	arm_func_start _ZN13CLineParticleD1Ev
_ZN13CLineParticleD1Ev: ; 0x02127318
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveQUADD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN13CLineParticleD1Ev

	arm_func_start _ZN14TFieldParticleI13CLineParticleED1Ev
_ZN14TFieldParticleI13CLineParticleED1Ev: ; 0x0212732C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveQUADD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN14TFieldParticleI13CLineParticleED1Ev

	arm_func_start _ZN21COPDCaptureDiscScreen20CLineParticleEmitterD1Ev
_ZN21COPDCaptureDiscScreen20CLineParticleEmitterD1Ev: ; 0x02127340
	bx lr
	arm_func_end _ZN21COPDCaptureDiscScreen20CLineParticleEmitterD1Ev

	arm_func_start _ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD1Ev
_ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD1Ev: ; 0x02127344
	bx lr
	arm_func_end _ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD1Ev

	arm_func_start _ZN21COPDCaptureDiscScreen13CSparkEmitterD1Ev
_ZN21COPDCaptureDiscScreen13CSparkEmitterD1Ev: ; 0x02127348
	bx lr
	arm_func_end _ZN21COPDCaptureDiscScreen13CSparkEmitterD1Ev

	arm_func_start _ZN21COPDCaptureDiscScreen14CSparkAnimatorD1Ev
_ZN21COPDCaptureDiscScreen14CSparkAnimatorD1Ev: ; 0x0212734C
	bx lr
	arm_func_end _ZN21COPDCaptureDiscScreen14CSparkAnimatorD1Ev

	arm_func_start _ZN21COPDCaptureDiscScreenD1Ev
_ZN21COPDCaptureDiscScreenD1Ev: ; 0x02127350
	stmdb sp!, {r4, lr}
	ldr r1, _02127470 ; =ptr_FUN_overlay_3_02127350_overlay_3_0212b218
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	ldr r3, _02127474 ; =_ZN23CSimplePrimitiveQuadNTFD1Ev
	add r0, r4, #0x374
	mov r1, #0xa
	mov r2, #0x64
	bl __cxa_vec_cleanup
	ldr r0, [r4, #0x308]
	cmp r0, #0
	beq _021273A8
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x308]
	arm_func_end _ZN21COPDCaptureDiscScreenD1Ev
_021273A8:
	ldr r0, [r4, #0x304]
	cmp r0, #0
	beq _021273C0
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x304]
_021273C0:
	ldr r0, [r4, #0x318]
	cmp r0, #0
	beq _021273E4
	ldr r3, _02127478 ; =_ZN14TFieldParticleI13CLineParticleED1Ev
	mov r1, #0x8c
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x318]
_021273E4:
	ldr r0, [r4, #0x2d4]
	cmp r0, #0
	beq _021273FC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x2d4]
_021273FC:
	ldr r0, [r4, #0x2d0]
	cmp r0, #0
	beq _02127414
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x2d0]
_02127414:
	ldr r0, [r4, #0x2e4]
	cmp r0, #0
	beq _02127438
	ldr r3, _0212747C ; =_ZN14TFieldParticleI10CSparkLineED1Ev
	mov r1, #0x58
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x2e4]
_02127438:
	add r0, r4, #0x138
	bl ov3_02129130
	ldr r3, _02127480 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0x60
	mov r1, #2
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	ldr r3, _02127484 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0xc
	mov r1, #1
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02127470: .word ptr_FUN_overlay_3_02127350_overlay_3_0212b218
_02127474: .word _ZN23CSimplePrimitiveQuadNTFD1Ev
_02127478: .word _ZN14TFieldParticleI13CLineParticleED1Ev
_0212747C: .word _ZN14TFieldParticleI10CSparkLineED1Ev
_02127480: .word _ZN16CSimpleSpriteNTFD1Ev
_02127484: .word _ZN15CSoftwareSpriteD1Ev

	arm_func_start _ZN21COPDCaptureDiscScreenD0Ev
_ZN21COPDCaptureDiscScreenD0Ev: ; 0x02127488
	stmdb sp!, {r4, lr}
	ldr r1, _021275B0 ; =ptr_FUN_overlay_3_02127350_overlay_3_0212b218
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	ldr r3, _021275B4 ; =_ZN23CSimplePrimitiveQuadNTFD1Ev
	add r0, r4, #0x374
	mov r1, #0xa
	mov r2, #0x64
	bl __cxa_vec_cleanup
	ldr r0, [r4, #0x308]
	cmp r0, #0
	beq _021274E0
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x308]
	arm_func_end _ZN21COPDCaptureDiscScreenD0Ev
_021274E0:
	ldr r0, [r4, #0x304]
	cmp r0, #0
	beq _021274F8
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x304]
_021274F8:
	ldr r0, [r4, #0x318]
	cmp r0, #0
	beq _0212751C
	ldr r3, _021275B8 ; =_ZN14TFieldParticleI13CLineParticleED1Ev
	mov r1, #0x8c
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x318]
_0212751C:
	ldr r0, [r4, #0x2d4]
	cmp r0, #0
	beq _02127534
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x2d4]
_02127534:
	ldr r0, [r4, #0x2d0]
	cmp r0, #0
	beq _0212754C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x2d0]
_0212754C:
	ldr r0, [r4, #0x2e4]
	cmp r0, #0
	beq _02127570
	ldr r3, _021275BC ; =_ZN14TFieldParticleI10CSparkLineED1Ev
	mov r1, #0x58
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x2e4]
_02127570:
	add r0, r4, #0x138
	bl ov3_02129130
	ldr r3, _021275C0 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0x60
	mov r1, #2
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	ldr r3, _021275C4 ; =_ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0xc
	mov r1, #1
	mov r2, #0x4c
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021275B0: .word ptr_FUN_overlay_3_02127350_overlay_3_0212b218
_021275B4: .word _ZN23CSimplePrimitiveQuadNTFD1Ev
_021275B8: .word _ZN14TFieldParticleI13CLineParticleED1Ev
_021275BC: .word _ZN14TFieldParticleI10CSparkLineED1Ev
_021275C0: .word _ZN16CSimpleSpriteNTFD1Ev
_021275C4: .word _ZN15CSoftwareSpriteD1Ev

	arm_func_start _ZN21COPDCaptureDiscScreen4InitEv
_ZN21COPDCaptureDiscScreen4InitEv: ; 0x021275C8
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0xc
	mov r4, r0
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0212760C
	ldr r2, _02127648 ; =s_OPD_i019_NCLR_overlay_3_0212b3fc
	ldr r1, _0212764C ; =s_OPD_i019_00_NCER_overlay_3_0212b40c
	str r2, [sp]
	ldr ip, _02127650 ; =s_OPD_i019_00_cac_overlay_3_0212b420
	str r1, [sp, #4]
	ldr r1, _02127654 ; =s_OPD_overlay_3_0212b3c8
	ldr r2, _02127658 ; =s_data_interface_i019_LZ_bin_overlay_3_0212b3cc
	ldr r3, _0212765C ; =s_OPD_i019_00_NCBR_overlay_3_0212b3e8
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
	arm_func_end _ZN21COPDCaptureDiscScreen4InitEv
_0212760C:
	str r0, [r4, #0x58]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0212762C
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	strh r0, [r4, #0x5c]
_0212762C:
	mov r0, r4
	bl _ZN21COPDCaptureDiscScreen12ov3_02127B34Ev
	add r0, r4, #0x138
	mov r1, #0x400
	bl ov3_02129198
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02127648: .word s_OPD_i019_NCLR_overlay_3_0212b3fc
_0212764C: .word s_OPD_i019_00_NCER_overlay_3_0212b40c
_02127650: .word s_OPD_i019_00_cac_overlay_3_0212b420
_02127654: .word s_OPD_overlay_3_0212b3c8
_02127658: .word s_data_interface_i019_LZ_bin_overlay_3_0212b3cc
_0212765C: .word s_OPD_i019_00_NCBR_overlay_3_0212b3e8

	arm_func_start _ZN21COPDCaptureDiscScreen7ReleaseEv
_ZN21COPDCaptureDiscScreen7ReleaseEv: ; 0x02127660
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #0x138
	bl ov3_02129280
	ldr r0, [r5, #0x1b8]
	cmp r0, #0
	beq _02127688
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #0x1b8]
	arm_func_end _ZN21COPDCaptureDiscScreen7ReleaseEv
_02127688:
	ldrh r1, [r5, #0x5c]
	cmp r1, #0
	ldrne r0, [r5, #0x58]
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021276AC
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	mov r0, #0
	strh r0, [r5, #0x5c]
_021276AC:
	ldr r4, [r5, #0x58]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _021276CC
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_021276CC:
	mov r0, #0
	str r0, [r5, #0x58]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN21COPDCaptureDiscScreen5StartEP11COPDTexture
_ZN21COPDCaptureDiscScreen5StartEP11COPDTexture: ; 0x021276D8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x20
	mov r4, r0
	mov r0, #0
	str r0, [r4, #8]
	str r0, [r4, #4]
	mov r5, r1
	ldr r2, _02127B1C ; =0x00007FFF
	str r0, [sp]
	mov r1, #0x1f
	mov r3, #0x3f
	bl G3X_SetClearColor
	ldr r1, [r4, #0x58]
	mov r0, #0
	ldmia r1, {r2, r3, r6}
	str r2, [r4, #0x38]
	str r0, [r4, #0x3c]
	str r3, [r4, #0x40]
	str r6, [r4, #0x44]
	str r0, [r4, #0x24]
	mov r1, #0x64
	str r0, [r4, #0x28]
	str r1, [r4, #0x10]
	ldr r1, _02127B20 ; =DAT_overlay_3_0212b378
	mov r2, r4
	str r0, [r4, #0x20]
	mov r3, #0x2c
	arm_func_end _ZN21COPDCaptureDiscScreen5StartEP11COPDTexture
_02127744:
	ldr r6, [r1, #0x20]
	add r0, r0, #1
	mla r7, r6, r3, r5
	str r7, [r2, #0x78]
	ldr sb, [r1, #0x1c]
	ldr r8, [r1, #0x18]
	ldr r7, [r1, #0x14]
	ldr r6, [r1, #0x10]
	cmp r0, #2
	str r6, [r2, #0x8c]
	str r7, [r2, #0x90]
	str r8, [r2, #0x94]
	str sb, [r2, #0x98]
	ldr r6, [r1]
	str r6, [r2, #0x9c]
	ldr r6, [r1, #4]
	str r6, [r2, #0xa0]
	ldr r6, [r1, #8]
	str r6, [r2, #0xac]
	ldr r6, [r1, #0xc]
	str r6, [r2, #0xb0]
	ldr r6, [r1, #0x24]
	add r1, r1, #0x28
	str r6, [r2, #0x64]
	add r2, r2, #0x5c
	blt _02127744
	ldr r0, _02127B24 ; =DAT_overlay_3_0212b378
	mov r1, #0
	str r1, [r4, #0x74]
	ldr r1, [r0, #0x48]
	mov r0, #0x2c
	mla r2, r1, r0, r5
	mov r0, #4
	sub r1, r0, #8
	ldr r7, [r2, #0xc]
	bl _Z23Heap_AllocWithAlignmentmm
	ldr r1, _02127B1C ; =0x00007FFF
	mov r6, r0
	strh r1, [r6]
	bl GX_BeginLoadTexPltt
	mov r0, r6
	mov r1, #4
	bl DC_FlushRange
	mov r0, r6
	mov r1, r7
	mov r2, #4
	bl GX_LoadTexPltt
	bl GX_EndLoadTexPltt
	mov r0, r6
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r4, #0x160]
	add r0, r5, #0x1e4
	str r0, [r4, #0x150]
	ldr r1, [r4, #0x1b8]
	ldr r2, [r4, #0x1bc]
	add r0, r4, #0x138
	bl _ZN15COPDCaptureLine12ov3_021292FCEP7Point2Di
	ldr r0, _02127B28 ; =DAT_overlay_3_0212a688
	ldmia r0, {r1, r2}
	str r1, [r4, #0x330]
	str r2, [r4, #0x334]
	ldr r0, [r4, #0x30c]
	str r1, [sp, #0x18]
	str r2, [sp, #0x1c]
	cmp r0, #0
	bls _02127860
	ldr r1, [r4, #0x304]
	cmp r1, #0
	addne r0, r4, #0x32c
	strne r0, [r1]
_02127860:
	add r1, r4, #0x350
	ldr r0, [sp, #0x18]
	str r1, [r4, #0x314]
	str r0, [r4, #0x358]
	str r2, [r4, #0x35c]
	ldr r0, [r4, #0x2d8]
	cmp r0, #0
	bls _02127890
	ldr r1, [r4, #0x2d0]
	cmp r1, #0
	addne r0, r4, #0x354
	strne r0, [r1]
_02127890:
	add r0, r4, #0x370
	str r0, [r4, #0x2e0]
	bl _ZN5CGame11GetInstanceEv
	add r1, r4, #0x35c
	str r0, [sp, #4]
	add r0, r1, #0x400
	mov r1, #0
	mov r2, #0xa0
	bl MI_CpuFill8
	ldr r0, [sp, #4]
	mov r7, #0
	add r0, r0, #0x48
	add r8, r0, #0x1400
	mov r0, #0x70000
	str r0, [sp, #0xc]
	add r0, r5, #0x58
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	mov sb, r4
	rsb r0, r0, #0
	mov sl, r7
	str r0, [sp, #0xc]
_021278E8:
	ldr r0, [sp, #8]
	mov ip, #0
	str r0, [sb, #0x38c]
	mov r0, #0
	str r0, [sb, #0x3c0]
	str r0, [sb, #0x3b8]
	str r0, [sb, #0x3d4]
	str r0, [sb, #0x3bc]
	mov r0, #0x20000
	str r0, [sb, #0x3d0]
	str r0, [sb, #0x3c8]
	mov r0, #0x40000
	str r0, [sb, #0x3cc]
	str r0, [sb, #0x3c4]
	mov r0, #0
	str r0, [sb, #0x398]
	ldr r0, [sp, #0xc]
	mov ip, ip, lsl #5
	str r0, [sb, #0x39c]
	mov r0, #0
	str r0, [sb, #0x3b0]
	ldr r0, [sp, #0xc]
	str ip, [sp, #0x10]
	str r0, [sb, #0x3b4]
	rsb r0, r7, #0x3f
	str r0, [sb, #0x384]
	add r0, r4, r7, lsl #4
	add ip, r0, #0x700
	ldr r3, [r8, #8]
	ldmia r8, {r1, fp}
	str ip, [sp, #0x14]
	umull lr, ip, r3, r1
	mla ip, r3, fp, ip
	ldr r2, [r8, #0xc]
	ldr r6, [r8, #0x10]
	mla ip, r2, r1, ip
	ldr r5, [r8, #0x14]
	adds r1, r6, lr
	adc r2, r5, ip
	stmia r8, {r1, r2}
	mov r1, #0x32
	umull r1, r3, r2, r1
	mov r1, #0
	mov r2, r1
	mov r1, #0x32
	mla r3, r2, r1, r3
	add r1, r3, #0x32
	mov r1, r1, lsl #0xc
	str r1, [r0, #0x768]
	mov r1, #0x8000
	str r1, [r0, #0x760]
	ldr lr, [r8]
	ldmib r8, {r1, r3}
	umull r6, r5, r3, lr
	mla r5, r3, r1, r5
	ldr r2, [r8, #0xc]
	ldr ip, [r8, #0x10]
	mla r5, r2, lr, r5
	ldr fp, [r8, #0x14]
	adds r1, ip, r6
	adc r2, fp, r5
	stmia r8, {r1, r2}
	ldr r1, [sp, #0x10]
	orr r1, r1, r2, lsr #27
	ldr r2, [r0, #0x760]
	str r1, [sp, #0x10]
	add r1, r2, r1, lsl #12
	str r1, [r0, #0x764]
	ldr r1, [r8]
	ldmib r8, {r0, r3}
	umull r6, r5, r3, r1
	mla r5, r3, r0, r5
	ldr r2, [r8, #0xc]
	ldr ip, [r8, #0x10]
	mla r5, r2, r1, r5
	ldr fp, [r8, #0x14]
	adds r0, ip, r6
	adc r1, fp, r5
	stmia r8, {r0, r1}
	mov r0, #0x24
	umull r0, r2, r1, r0
	mov r0, #0
	mov r1, r0
	mov r0, #0x24
	mla r2, r1, r0, r2
	add r0, sl, r2
	sub r2, r0, #0x12
	ldr r0, _02127B2C ; =0xB60B60B7
	mov r3, r2, lsl #0x10
	smull r1, r5, r0, r3
	add r5, r5, r2, lsl #16
	mov r0, r3, lsr #0x1f
	add r5, r0, r5, asr #8
	ldr r0, [sp, #0x14]
	strh r5, [r0, #0x5c]
	ldr r1, [r8]
	ldmib r8, {r0, r3}
	umull r6, r5, r3, r1
	mla r5, r3, r0, r5
	ldr r2, [r8, #0xc]
	ldr ip, [r8, #0x10]
	mla r5, r2, r1, r5
	ldr fp, [r8, #0x14]
	adds r1, ip, r6
	adc r0, fp, r5
	str r1, [r8]
	str r0, [r8, #4]
	mov r0, #0
	ldr r1, [r8, #4]
	mov r0, r0, lsl #0xe
	orr r0, r0, r1, lsr #18
	add r1, r0, #0x4000
	ldr r0, _02127B30 ; =0x6C16C16D
	add r7, r7, #1
	umull r0, r2, r1, r0
	sub r0, r1, r2
	add r2, r2, r0, lsr #1
	ldr r0, [sp, #0x14]
	mov r2, r2, lsr #8
	strh r2, [r0, #0x5e]
	add sb, sb, #0x64
	add sl, sl, #0x24
	cmp r7, #0xa
	blt _021278E8
	mov r0, #0
	str r0, [r4, #0x7fc]
	strb r0, [r4, #0x804]
	ldr r0, [sp, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [sp, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02127B1C: .word 0x00007FFF
_02127B20: .word DAT_overlay_3_0212b378
_02127B24: .word DAT_overlay_3_0212b378
_02127B28: .word DAT_overlay_3_0212a688
_02127B2C: .word 0xB60B60B7
_02127B30: .word 0x6C16C16D

	arm_func_start _ZN21COPDCaptureDiscScreen12ov3_02127B34Ev
_ZN21COPDCaptureDiscScreen12ov3_02127B34Ev: ; 0x02127B34
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x30
	str r0, [sp]
	bl _ZN5CGame11GetInstanceEv
	str r0, [sp, #0x2c]
	mov r0, #0x2000
	bl _Znam
	ldr r1, [sp, #0x2c]
	mov r3, #0
	add r2, r1, #0x48
	ldr r1, [sp]
	str r0, [r1, #0x1b8]
	add r1, r2, #0x1400
	str r1, [sp, #0x1c]
	ldr r1, [sp, #0x2c]
	add r2, r1, #0x1000
	ldr r1, [sp, #0x1c]
	ldr r5, [r2, #0x448]
	ldmib r1, {r4, r6}
	umull r8, r7, r6, r5
	mla r7, r6, r4, r7
	ldr r4, [r1, #0xc]
	ldr sb, [r1, #0x10]
	mla r7, r4, r5, r7
	ldr r1, [r1, #0x14]
	adds r6, sb, r8
	adc r4, r1, r7
	str r6, [r2, #0x448]
	ldr r1, [sp, #0x1c]
	ldr r2, _02127EDC ; =FX_SinCosTable_+0x3800
	str r4, [r1, #4]
	mov r1, r3, lsl #4
	orr r1, r1, r4, lsr #28
	add r3, r1, #0x1c
	ldrsh r1, [r2, #2]
	mov r4, r0
	ldr r0, [sp]
	str r1, [sp, #4]
	ldrsh r1, [r2]
	str r0, [sp, #0x18]
	add r0, r0, #0x18
	str r0, [sp, #0x14]
	mov r0, #0
	str r1, [sp, #0xc]
	mov ip, r3, lsl #0xc
	str r0, [sp, #0x28]
	arm_func_end _ZN21COPDCaptureDiscScreen12ov3_02127B34Ev
_02127BEC:
	ldr r0, [sp, #0x18]
	mov r1, #0xe000
	add r0, r0, #0x100
	strh r1, [r0, #0xc0]
	ldr r0, [sp, #0x1c]
	mov lr, #0xc000
	ldr r1, [r0, #8]
	ldr r2, [r0]
	ldr r0, [r0, #4]
	umull r5, r3, r1, r2
	mla r3, r1, r0, r3
	ldr r0, [sp, #0x1c]
	ldr r1, [r0, #0x10]
	ldr r6, [r0, #0x14]
	ldr r0, [r0, #0xc]
	adds r5, r1, r5
	mla r3, r0, r2, r3
	mov r1, #0
	ldr r0, [sp, #0x1c]
	adc r2, r6, r3
	mov r1, r1, lsl #4
	str r5, [r0]
	orr r1, r1, r2, lsr #28
	str r2, [r0, #4]
	add r0, r1, #0x26
	mov r5, r0, lsl #0xc
	ldr r0, [sp, #0x14]
	str r5, [r0, #0x1c4]
	str ip, [r0, #0x1c8]
	mov r0, #0
	str r0, [sp, #0x24]
	ldr r0, [sp, #0xc]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	mov r0, r0, asr #0x1f
	str r0, [sp, #8]
	ldr r0, [sp, #0x2c]
	add r0, r0, #0x48
	add r6, r0, #0x1400
_02127C8C:
	mov r0, lr, asr #4
	mov r2, r0, lsl #1
	ldr r0, _02127EE0 ; =FX_SinCosTable_
	mov r1, r2, lsl #1
	ldrsh r1, [r0, r1]
	add r0, r0, r2, lsl #1
	sub r7, lr, #0x200
	smull r2, r1, ip, r1
	mov r3, r2, lsr #0xc
	orr r3, r3, r1, lsl #20
	ldrsh r0, [r0, #2]
	mov r7, r7, lsl #0x10
	mov lr, r7, lsr #0x10
	smull r1, r0, r5, r0
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	ldr r7, _02127EE4 ; =0x00003FFF
	ldr r8, [sp, #4]
	tst lr, r7
	umull sb, r7, r8, r1
	mov r0, r1, asr #0x1f
	mla r7, r8, r0, r7
	ldr r8, [sp, #8]
	mov sb, sb, lsr #0xc
	mla r7, r8, r1, r7
	ldr r8, [sp, #0xc]
	orr sb, sb, r7, lsl #20
	umull sl, r7, r8, r3
	mov r8, sl, lsr #0xc
	ldr sl, [sp, #0xc]
	mov r2, r3, asr #0x1f
	mla r7, sl, r2, r7
	ldr sl, [sp, #0x10]
	mla r7, sl, r3, r7
	orr r8, r8, r7, lsl #20
	sub r7, sb, r8
	ldr sb, [sp, #0xc]
	str r7, [r4]
	umull r8, r7, sb, r1
	mla r7, sb, r0, r7
	mov r0, sl
	mla r7, r0, r1, r7
	mov r0, r8, lsr #0xc
	ldr r1, [sp, #4]
	orr r0, r0, r7, lsl #20
	umull r8, r7, r1, r3
	mla r7, r1, r2, r7
	ldr r1, [sp, #8]
	mla r7, r1, r3, r7
	mov r1, r8, lsr #0xc
	orr r1, r1, r7, lsl #20
	add r0, r0, r1
	sub r0, r0, #0x70000
	str r0, [r4, #4]
	bne _02127E1C
	ldr r0, [sp, #0x24]
	cmp r0, #0x7f
	beq _02127E1C
	mov r0, lr, asr #0xe
	and r0, r0, #3
	str r0, [sp, #0x20]
	tst r0, #1
	ldr r1, [r6, #0x10]
	mov r2, #0
	ldr r0, [r6, #0x14]
	beq _02127DD0
	ldr r5, [r6]
	ldmib r6, {r3, r8}
	umull sl, sb, r8, r5
	mla sb, r8, r3, sb
	ldr r7, [r6, #0xc]
	adds r1, r1, sl
	mla sb, r7, r5, sb
	mov r2, r2, lsl #4
	adc r0, r0, sb
	str r1, [r6]
	orr r2, r2, r0, lsr #28
	str r0, [r6, #4]
	add r0, r2, #0x26
	mov r5, r0, lsl #0xc
	b _02127E08
_02127DD0:
	ldr r7, [r6]
	ldmib r6, {r3, sb}
	umull ip, sl, sb, r7
	mla sl, sb, r3, sl
	ldr r8, [r6, #0xc]
	adds r1, r1, ip
	mla sl, r8, r7, sl
	mov r2, r2, lsl #4
	adc r0, r0, sl
	str r1, [r6]
	orr r2, r2, r0, lsr #28
	str r0, [r6, #4]
	add r0, r2, #0x1c
	mov ip, r0, lsl #0xc
_02127E08:
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r0, r1, r0, lsl #3
	str r5, [r0, #0x1c4]
	str ip, [r0, #0x1c8]
_02127E1C:
	ldr r0, [sp, #0x24]
	add r4, r4, #8
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, #0x80
	blt _02127C8C
	ldr r0, [sp, #0x28]
	add r0, r0, #1
	str r0, [sp, #0x28]
	cmp r0, #6
	ldr r0, [sp, #0x18]
	add r0, r0, #0x24
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, r0, #0x24
	str r0, [sp, #0x14]
	blt _02127BEC
	mov r0, #0xa0000
	ldr r5, [r4, #-8]
	rsb r0, r0, #0
	sub r2, r0, r5
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r2, #0x1e000
	mov r3, #0
	ldr r6, [r4, #-4]
	bl _ll_div
	mov r1, #0
_02127E94:
	add r5, r5, r0
	add r1, r1, #0x1000
	str r5, [r4]
	sub r6, r6, r0
	str r6, [r4, #4]
	cmp r1, #0x1e000
	add r4, r4, #8
	blt _02127E94
	ldr r0, [sp]
	ldr r0, [r0, #0x1b8]
	sub r1, r4, r0
	mov r0, r1, asr #2
	add r0, r1, r0, lsr #29
	mov r1, r0, asr #3
	ldr r0, [sp]
	str r1, [r0, #0x1bc]
	add sp, sp, #0x30
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02127EDC: .word FX_SinCosTable_+0x3800
_02127EE0: .word FX_SinCosTable_
_02127EE4: .word 0x00003FFF

	arm_func_start _ZN21COPDCaptureDiscScreen4StopEv
_ZN21COPDCaptureDiscScreen4StopEv: ; 0x02127EE8
	stmdb sp!, {r3, lr}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0
	bl _ZN17UnkClass_0203447812sub_02034ED8Ei
	ldmia sp!, {r3, pc}
	arm_func_end _ZN21COPDCaptureDiscScreen4StopEv

	arm_func_start _ZN21COPDCaptureDiscScreen6UpdateEv
_ZN21COPDCaptureDiscScreen6UpdateEv: ; 0x02127F04
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x28
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	mov r5, r0
	ldr r0, [r4, #8]
	ldr r2, [r5, #0x14]
	cmp r0, #3
	ldr r1, [r5, #0x18]
	bgt _02127F88
	ldrh r0, [r2, #2]
	and r0, r0, #1
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	ldreqb r0, [r1, #4]
	cmpeq r0, #0
	beq _02127F88
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xfa
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r1, #2
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r1, #2
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #6
	str r0, [r4, #8]
	arm_func_end _ZN21COPDCaptureDiscScreen6UpdateEv
_02127F88:
	ldr r0, [r4, #8]
	cmp r0, #6
	addls pc, pc, r0, lsl #2
	b _02128428
_02127F98: ; jump table
	b _02127FB4 ; case 0
	b _02128000 ; case 1
	b _02128090 ; case 2
	b _021281FC ; case 3
	b _021281FC ; case 4
	b _021283C8 ; case 5
	b _021283E4 ; case 6
_02127FB4:
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02128428
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02128428
	mov r0, #1
	str r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #4]
	add r0, r4, #0x354
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	b _02128428
_02128000:
	ldr r0, [r4, #4]
	add r0, r0, #1
	str r0, [r4, #4]
	cmp r0, #0x3c
	ble _02128428
	mov r0, #2
	str r0, [r4, #8]
	mov r3, #0
	str r3, [r4, #4]
	mov r0, #0x90000
	str r0, [r4, #0x118]
	ldr r0, [r4, #0x1b8]
	mov r1, #0x30000
	ldr r2, [r0, #4]
	sub r0, r1, #0x36000
	str r2, [r4, #0x11c]
	str r1, [r4, #0x120]
	str r0, [r4, #0x124]
	str r3, [r4, #0x128]
	ldr r0, _021289A4 ; =0xFFFFFB34
	str r3, [r4, #0x12c]
	str r0, [r4, #0x130]
	str r3, [r4, #0x134]
	ldr r2, [r4, #0x11c]
	ldr r1, [r4, #0x120]
	ldr r0, [r4, #0x118]
	sub r1, r2, r1
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	mov r0, #0x1f
	str r0, [r4, #0x20]
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xa1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _02128428
_02128090:
	ldr r2, [r4, #0x11c]
	ldr r1, [r4, #0x120]
	ldr r0, [r4, #0x118]
	sub r1, r2, r1
	str r0, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r1, [r4, #0x134]
	cmp r1, #2
	bhs _02128160
	ldr r0, [r4, #0x120]
	cmp r0, #0
	bgt _02128180
	add r0, r1, #1
	str r0, [r4, #0x134]
	cmp r0, #1
	bne _02128124
	mov r0, #0
	str r0, [r4, #0x120]
	ldr r2, [r4, #0x124]
	mov r0, #0x2800
	mov r1, r2, asr #0x1f
	mov r1, r1, lsl #0xb
	mov r3, r2, lsl #0xb
	orr r1, r1, r2, lsr #21
	mov r2, r3, lsr #0xc
	orr r2, r2, r1, lsl #20
	str r2, [r4, #0x124]
	ldr r2, [r4, #0x128]
	mov r1, r2, asr #0x1f
	mov r1, r1, lsl #0xb
	mov r3, r2, lsl #0xb
	orr r1, r1, r2, lsr #21
	mov r2, r3, lsr #0xc
	orr r2, r2, r1, lsl #20
	str r2, [r4, #0x128]
	str r0, [r4, #0x12c]
	b _0212814C
_02128124:
	cmp r0, #2
	bne _0212814C
	mov r0, #0
	str r0, [r4, #0x120]
	str r0, [r4, #0x124]
	str r0, [r4, #0x128]
	str r0, [r4, #0x12c]
	str r0, [r4, #0x130]
	mov r0, #0x2d
	str r0, [r4, #4]
_0212814C:
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0x99
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _02128180
_02128160:
	bne _02128180
	ldr r0, [r4, #4]
	sub r0, r0, #1
	str r0, [r4, #4]
	cmp r0, #0
	ldrle r0, [r4, #0x134]
	addle r0, r0, #1
	strle r0, [r4, #0x134]
_02128180:
	ldr r0, [r4, #0x134]
	cmp r0, #3
	bhs _021281D0
	ldr r1, [r4, #0x118]
	ldr r0, [r4, #0x124]
	add r0, r1, r0
	str r0, [r4, #0x118]
	ldr r1, [r4, #0x11c]
	ldr r0, [r4, #0x128]
	add r0, r1, r0
	str r0, [r4, #0x11c]
	ldr r1, [r4, #0x120]
	ldr r0, [r4, #0x12c]
	add r0, r1, r0
	str r0, [r4, #0x120]
	ldr r1, [r4, #0x12c]
	ldr r0, [r4, #0x130]
	add r0, r1, r0
	str r0, [r4, #0x12c]
	b _02128428
_021281D0:
	mov r0, #3
	str r0, [r4, #8]
	mov r1, #0
	str r1, [r4, #4]
	str r1, [r4, #0x2bc]
	strb r1, [r4, #0x2c0]
	str r1, [r4, #0x800]
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034E48Ei
	b _02128428
_021281FC:
	ldr r0, [r4, #0x58]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02128210
	bl _ZN17UnkClass_0200878812sub_020089ECEv
_02128210:
	ldr r0, [r4, #0x2bc]
	str r0, [r4, #0x160]
	ldr r1, [r4, #0x2bc]
	cmp r1, #0
	beq _02128264
	ldr r0, [r4, #0x1bc]
	cmp r1, r0
	bhi _02128264
	mov r0, #0x1f
	str r0, [r4, #0x20]
	ldr r0, [r4, #0x2bc]
	ldr r2, [r4, #0x1b8]
	sub r1, r0, #1
	add r0, r2, r1, lsl #3
	ldr r1, [r2, r1, lsl #3]
	ldr r0, [r0, #4]
	str r1, [sp, #0x20]
	str r1, [r4, #0x24]
	str r0, [sp, #0x24]
	str r0, [r4, #0x28]
	b _0212826C
_02128264:
	mov r0, #0
	str r0, [r4, #0x20]
_0212826C:
	ldr r0, [r4, #0x2bc]
	add r1, r0, #8
	str r1, [r4, #0x2bc]
	ldr r0, [r4, #0x1bc]
	cmp r1, r0
	bhi _0212833C
	tst r1, #0x7f
	bne _0212833C
	ldrb r2, [r4, #0x2c0]
	mov r1, #0x14
	add r3, r4, #0x1c0
	mov r0, #0x24
	mla r0, r2, r0, r3
	str r1, [r4, #0x344]
	str r0, [r4, #0x348]
	ldrb r1, [r4, #0x2c0]
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	cmp r1, #5
	bhi _021282C8
	add r1, r1, #0x1a
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _021282D0
_021282C8:
	mov r1, #0x1f
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
_021282D0:
	ldrb r0, [r4, #0x2c0]
	add r1, r0, #1
	and r0, r1, #0xff
	strb r1, [r4, #0x2c0]
	cmp r0, #2
	bne _021282F8
	mov r0, #0x1f
	str r0, [r4, #0x74]
	mov r0, #0x40
	str r0, [r4, #0x800]
_021282F8:
	ldrb r0, [r4, #0x2c0]
	cmp r0, #5
	bne _0212833C
	mov r0, #0x800
	str r0, [r4, #0x7fc]
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r1, #2
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r1, #2
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #4
	str r0, [r4, #8]
_0212833C:
	ldr r0, [r4, #0x800]
	str r0, [r4, #0xa8]
	str r0, [r4, #0xa4]
	ldrb r0, [r4, #0x2c0]
	cmp r0, #5
	ldr r0, [r4, #0x800]
	addlo r0, r0, #0x40
	addhs r0, r0, #0x800
	str r0, [r4, #0x800]
	ldr r0, [r4, #8]
	cmp r0, #4
	bne _02128428
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02128428
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02128428
	ldr r1, [r4, #0x2bc]
	ldr r0, [r4, #0x1bc]
	cmp r1, r0
	bls _02128428
	mov r0, #0x5a
	str r0, [r4, #4]
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xb
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	mov r0, #5
	str r0, [r4, #8]
	b _02128428
_021283C8:
	ldr r0, [r4, #4]
	subs r0, r0, #1
	str r0, [r4, #4]
	bpl _02128428
	add sp, sp, #0x28
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_021283E4:
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02128428
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02128428
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xb
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	add sp, sp, #0x28
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_02128428:
	ldr r5, [r4, #0x320]
	ldr r8, [r4, #0x300]
	cmp r5, #0
	beq _02128558
	mov sb, #0
	mov r7, r8, asr #0x1f
	mov sl, sb
_02128444:
	ldr r0, [r5, #0x78]
	ldr r6, [r5, #0x88]
	cmp r0, #0
	beq _02128508
	ldr r0, [r4, #0x314]
	cmp r0, #0
	beq _02128474
	ldr r3, [r0]
	mov r1, r5
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_02128474:
	ldr r0, [r5, #0x78]
	cmp r0, #0
	ble _0212854C
	ldr lr, [r5, #0x6c]
	ldr r0, [r5, #0x70]
	umull r3, r2, lr, r8
	mla r2, lr, r7, r2
	umull ip, r1, r0, r8
	mov lr, lr, asr #0x1f
	mla r2, lr, r8, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	mov r2, ip, lsr #0xc
	mla r1, r0, r7, r1
	mov ip, r0, asr #0x1f
	mla r1, ip, r8, r1
	orr r2, r2, r1, lsl #20
	ldr r0, [r5, #0x64]
	str r2, [sp, #0x1c]
	add r0, r0, r3
	str r0, [r5, #0x64]
	ldr r0, [r5, #0x68]
	str r2, [sp, #0x14]
	add r0, r0, r2
	str r0, [r5, #0x68]
	ldrsh r0, [r5, #0x76]
	ldrsh r2, [r5, #0x74]
	str r3, [sp, #0x18]
	mul r1, r0, r8
	add r0, r2, r1, asr #12
	strh r0, [r5, #0x74]
	ldr r0, [r5, #0x78]
	str r3, [sp, #0x10]
	subs r0, r0, r8
	str r0, [r5, #0x78]
	strmi sl, [r5, #0x78]
	b _0212854C
_02128508:
	cmp r5, #0
	beq _0212854C
	cmp r6, #0
	ldrne r0, [r5, #0x84]
	strne r0, [r6, #0x84]
	ldr r1, [r5, #0x84]
	ldr r0, [r5, #0x88]
	cmp r1, #0
	strne r0, [r1, #0x88]
	streq r0, [r4, #0x320]
	ldr r0, [r4, #0x324]
	str r0, [r5, #0x88]
	str sb, [r5, #0x84]
	ldr r0, [r4, #0x324]
	cmp r0, #0
	strne r5, [r0, #0x84]
	str r5, [r4, #0x324]
_0212854C:
	mov r5, r6
	cmp r6, #0
	bne _02128444
_02128558:
	ldr r0, [r4, #0x30c]
	mov r6, #0
	mov r5, r6
	cmp r0, #0
	bls _021285BC
	mov r7, r6
_02128570:
	ldr r0, [r4, #0x304]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [r4, #0x308]
	streq r7, [r0, r5, lsl #2]
	beq _021285AC
	ldr r2, [r0]
	mov r1, r8
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [r4, #0x308]
	str r0, [r1, r5, lsl #2]
	ldr r0, [r4, #0x308]
	ldr r0, [r0, r5, lsl #2]
	add r6, r6, r0
_021285AC:
	ldr r0, [r4, #0x30c]
	add r5, r5, #1
	cmp r5, r0
	blo _02128570
_021285BC:
	cmp r6, #0
	beq _021286A4
	cmp r0, #0
	mov sl, #0
	bls _021286A4
_021285D0:
	ldr r0, [r4, #0x304]
	ldr r0, [r0, sl, lsl #2]
	cmp r0, #0
	ldrne r0, [r4, #0x308]
	ldrne r0, [r0, sl, lsl #2]
	cmpne r0, #0
	beq _02128694
	cmp r0, #0
	mov sb, #0
	bls _02128694
	mov r5, sb
	mov r6, sb
_02128600:
	ldr r1, [r4, #0x324]
	mov r7, r6
	cmp r1, #0
	beq _02128640
	ldr r0, [r1, #0x88]
	mov r7, r1
	str r0, [r4, #0x324]
	cmp r0, #0
	strne r6, [r0, #0x84]
	ldr r0, [r4, #0x320]
	str r0, [r1, #0x88]
	str r5, [r1, #0x84]
	ldr r0, [r4, #0x320]
	cmp r0, #0
	strne r1, [r0, #0x84]
	str r1, [r4, #0x320]
_02128640:
	cmp r7, #0
	beq _02128680
	ldr r0, [r4, #0x304]
	mov r1, r7
	ldr r0, [r0, sl, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [r4, #0x314]
	cmp r0, #0
	beq _02128680
	ldr r3, [r0]
	mov r1, r7
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_02128680:
	ldr r0, [r4, #0x308]
	add sb, sb, #1
	ldr r0, [r0, sl, lsl #2]
	cmp sb, r0
	blo _02128600
_02128694:
	ldr r0, [r4, #0x30c]
	add sl, sl, #1
	cmp sl, r0
	blo _021285D0
_021286A4:
	ldr r5, [r4, #0x2ec]
	ldr r8, [r4, #0x2cc]
	cmp r5, #0
	beq _021287D4
	mov sb, #0
	mov r7, r8, asr #0x1f
	mov sl, sb
_021286C0:
	ldr r0, [r5, #0x44]
	ldr r6, [r5, #0x54]
	cmp r0, #0
	beq _02128784
	ldr r0, [r4, #0x2e0]
	cmp r0, #0
	beq _021286F0
	ldr r3, [r0]
	mov r1, r5
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_021286F0:
	ldr r0, [r5, #0x44]
	cmp r0, #0
	ble _021287C8
	ldr lr, [r5, #0x38]
	ldr r0, [r5, #0x3c]
	umull r3, r2, lr, r8
	mla r2, lr, r7, r2
	umull ip, r1, r0, r8
	mov lr, lr, asr #0x1f
	mla r2, lr, r8, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	mov r2, ip, lsr #0xc
	mla r1, r0, r7, r1
	mov ip, r0, asr #0x1f
	mla r1, ip, r8, r1
	orr r2, r2, r1, lsl #20
	ldr r0, [r5, #0x30]
	str r2, [sp, #0xc]
	add r0, r0, r3
	str r0, [r5, #0x30]
	ldr r0, [r5, #0x34]
	str r2, [sp, #4]
	add r0, r0, r2
	str r0, [r5, #0x34]
	ldrsh r0, [r5, #0x42]
	ldrsh r2, [r5, #0x40]
	str r3, [sp, #8]
	mul r1, r0, r8
	add r0, r2, r1, asr #12
	strh r0, [r5, #0x40]
	ldr r0, [r5, #0x44]
	str r3, [sp]
	subs r0, r0, r8
	str r0, [r5, #0x44]
	strmi sl, [r5, #0x44]
	b _021287C8
_02128784:
	cmp r5, #0
	beq _021287C8
	cmp r6, #0
	ldrne r0, [r5, #0x50]
	strne r0, [r6, #0x50]
	ldr r1, [r5, #0x50]
	ldr r0, [r5, #0x54]
	cmp r1, #0
	strne r0, [r1, #0x54]
	streq r0, [r4, #0x2ec]
	ldr r0, [r4, #0x2f0]
	str r0, [r5, #0x54]
	str sb, [r5, #0x50]
	ldr r0, [r4, #0x2f0]
	cmp r0, #0
	strne r5, [r0, #0x50]
	str r5, [r4, #0x2f0]
_021287C8:
	mov r5, r6
	cmp r6, #0
	bne _021286C0
_021287D4:
	ldr r0, [r4, #0x2d8]
	mov r6, #0
	mov r5, r6
	cmp r0, #0
	bls _02128838
	mov r7, r6
_021287EC:
	ldr r0, [r4, #0x2d0]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [r4, #0x2d4]
	streq r7, [r0, r5, lsl #2]
	beq _02128828
	ldr r2, [r0]
	mov r1, r8
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [r4, #0x2d4]
	str r0, [r1, r5, lsl #2]
	ldr r0, [r4, #0x2d4]
	ldr r0, [r0, r5, lsl #2]
	add r6, r6, r0
_02128828:
	ldr r0, [r4, #0x2d8]
	add r5, r5, #1
	cmp r5, r0
	blo _021287EC
_02128838:
	cmp r6, #0
	beq _02128920
	cmp r0, #0
	mov sl, #0
	bls _02128920
_0212884C:
	ldr r0, [r4, #0x2d0]
	ldr r0, [r0, sl, lsl #2]
	cmp r0, #0
	ldrne r0, [r4, #0x2d4]
	ldrne r0, [r0, sl, lsl #2]
	cmpne r0, #0
	beq _02128910
	cmp r0, #0
	mov sb, #0
	bls _02128910
	mov r5, sb
	mov r6, sb
_0212887C:
	ldr r1, [r4, #0x2f0]
	mov r7, r6
	cmp r1, #0
	beq _021288BC
	ldr r0, [r1, #0x54]
	mov r7, r1
	str r0, [r4, #0x2f0]
	cmp r0, #0
	strne r6, [r0, #0x50]
	ldr r0, [r4, #0x2ec]
	str r0, [r1, #0x54]
	str r5, [r1, #0x50]
	ldr r0, [r4, #0x2ec]
	cmp r0, #0
	strne r1, [r0, #0x50]
	str r1, [r4, #0x2ec]
_021288BC:
	cmp r7, #0
	beq _021288FC
	ldr r0, [r4, #0x2d0]
	mov r1, r7
	ldr r0, [r0, sl, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [r4, #0x2e0]
	cmp r0, #0
	beq _021288FC
	ldr r3, [r0]
	mov r1, r7
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_021288FC:
	ldr r0, [r4, #0x2d4]
	add sb, sb, #1
	ldr r0, [r0, sl, lsl #2]
	cmp sb, r0
	blo _0212887C
_02128910:
	ldr r0, [r4, #0x2d8]
	add sl, sl, #1
	cmp sl, r0
	blo _0212884C
_02128920:
	add r0, r4, #0x138
	bl _ZN15COPDCaptureLine12ov3_02129A4CEv
	ldr r0, [r4, #0x7fc]
	cmp r0, #0
	beq _0212898C
	add r0, r4, #0x35c
	add r3, r0, #0x400
	mov r2, #0
_02128940:
	ldr r0, [r3, #4]
	cmp r0, #0
	beq _02128970
	ldrh r1, [r3]
	ldrsh r0, [r3, #2]
	add r0, r1, r0
	strh r0, [r3]
	ldr r1, [r3, #4]
	ldr r0, [r3, #8]
	cmp r1, r0
	addlt r0, r1, #0x1000
	strlt r0, [r3, #4]
_02128970:
	add r2, r2, #1
	cmp r2, #0xa
	add r3, r3, #0x10
	blt _02128940
	ldr r0, [r4, #0x7fc]
	add r0, r0, #0x400
	str r0, [r4, #0x7fc]
_0212898C:
	ldrb r1, [r4, #0x804]
	mov r0, #0
	add r1, r1, #1
	strb r1, [r4, #0x804]
	add sp, sp, #0x28
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_021289A4: .word 0xFFFFFB34

	arm_func_start _ZN21COPDCaptureDiscScreen13CSparkEmitter5func2Ev
_ZN21COPDCaptureDiscScreen13CSparkEmitter5func2Ev: ; 0x021289A8
	mov r1, #0x1000
	str r1, [r0, #0x18]
	bx lr
	arm_func_end _ZN21COPDCaptureDiscScreen13CSparkEmitter5func2Ev

	arm_func_start _ZN21TFieldParticleEmitterI13CLineParticleE6UpdateEi
_ZN21TFieldParticleEmitterI13CLineParticleE6UpdateEi: ; 0x021289B4
	mov r0, #0
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI13CLineParticleE6UpdateEi

	arm_func_start _ZN21TFieldParticleEmitterI10CSparkLineE6UpdateEi
_ZN21TFieldParticleEmitterI10CSparkLineE6UpdateEi: ; 0x021289BC
	mov r0, #0
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI10CSparkLineE6UpdateEi

	arm_func_start _ZN21COPDCaptureDiscScreen6RenderEP8Camera2Di
_ZN21COPDCaptureDiscScreen6RenderEP8Camera2Di: ; 0x021289C4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x28
	mov r7, r0
	ldr r4, [r7, #0x320]
	mov r6, r1
	cmp r4, #0
	beq _02128A80
	ldr r5, _02128C98 ; =0x04000450
	mov r8, #0
	arm_func_end _ZN21COPDCaptureDiscScreen6RenderEP8Camera2Di
_021289E8:
	ldr r0, [r7, #0x328]
	cmp r0, #0
	strlt r0, [r4, #4]
	ldr r3, [r4, #0x60]
	ldr r1, [r4, #0x68]
	mov r2, r3, asr #0x1f
	mov fp, r2, lsl #0xb
	ldr r0, [r7, #0x2fc]
	mov ip, r3, lsl #0xb
	orr fp, fp, r3, lsr #21
	mov r3, ip, lsr #0xc
	ldr sl, [r4, #0x64]
	ldr r2, [r7, #0x2f8]
	add sb, r1, r0
	orr r3, r3, fp, lsl #20
	add r1, sl, r2
	str sb, [sp]
	str r1, [sp, #4]
	add r0, sb, r3
	str r0, [sp, #8]
	sub r0, r1, r3
	str r0, [sp, #0xc]
	str sb, [sp, #0x10]
	ldr r2, [r4, #4]
	mov r0, r4
	str r2, [sp, #0x14]
	sub r2, sb, r3
	add r3, r1, r3
	bl _ZN14CPrimitiveQUAD20SetVertexCoordinatesElllllllll
	mov r0, r4
	str r8, [r5]
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	ldr r4, [r4, #0x88]
	cmp r4, #0
	bne _021289E8
_02128A80:
	ldr r8, [r7, #0x2ec]
	cmp r8, #0
	beq _02128AC4
	ldr r4, _02128C98 ; =0x04000450
	mov r5, #0
_02128A94:
	ldr r0, [r7, #0x2f4]
	mov r1, r6
	cmp r0, #0
	strlt r0, [r8, #4]
	mov r0, r8
	str r5, [r4]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r8, [r8, #0x54]
	cmp r8, #0
	bne _02128A94
_02128AC4:
	add r0, r7, #0x60
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	ldrb r0, [r7, #0x804]
	tst r0, #0x20
	bne _02128AF8
	add r0, r7, #0xbc
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
_02128AF8:
	bl OS_GetTick
	add r0, r7, #0x138
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	bl OS_GetTick
	ldr r0, [r7, #0x7fc]
	cmp r0, #0
	beq _02128C5C
	add r0, r7, #0x35c
	add r4, r0, #0x400
	add r0, r7, #0x374
	str r0, [sp, #0x24]
	mov r0, #0
	mov r5, r7
	str r0, [sp, #0x18]
_02128B3C:
	ldr r2, [r4, #4]
	cmp r2, #0
	beq _02128C34
	ldrh r3, [r4]
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xb
	mov r0, r2, lsl #0xb
	orr r1, r1, r2, lsr #21
	mov r2, r0, lsr #0xc
	mov r0, r3, asr #4
	mov r3, r0, lsl #1
	ldr r0, _02128C9C ; =FX_SinCosTable_
	mov r8, r3, lsl #1
	add r3, r0, r3, lsl #1
	ldrsh sb, [r0, r8]
	ldrsh sl, [r3, #2]
	ldr r0, [r7, #0x7fc]
	ldr r3, [r4, #0xc]
	orr r2, r2, r1, lsl #20
	smull r8, fp, r3, r0
	smull r2, r1, r0, r2
	mov r8, r8, lsr #0xc
	mov lr, r2, lsr #0xc
	orr r8, r8, fp, lsl #20
	smull r3, r2, r8, sl
	orr lr, lr, r1, lsl #20
	rsb r0, sb, #0
	smull r1, r0, lr, r0
	mov ip, r1, lsr #0xc
	orr ip, ip, r0, lsl #20
	rsb r0, sl, #0
	smull r1, r0, lr, r0
	mov fp, r1, lsr #0xc
	orr fp, fp, r0, lsl #20
	mov r3, r3, lsr #0xc
	str r2, [sp, #0x20]
	orr r2, r3, r2, lsl #20
	str r2, [sp, #0x1c]
	add r2, r2, ip
	str r2, [r5, #0x3a0]
	smull r3, r2, r8, sb
	mov r3, r3, lsr #0xc
	smull sl, r8, lr, sl
	orr r3, r3, r2, lsl #20
	sub r2, r3, #0x70000
	add r3, r2, fp
	mov sl, sl, lsr #0xc
	orr sl, sl, r8, lsl #20
	smull fp, sb, lr, sb
	add r2, r2, sl
	str r2, [r5, #0x3a4]
	mov r8, fp, lsr #0xc
	ldr r2, [sp, #0x1c]
	orr r8, r8, sb, lsl #20
	add r2, r2, r8
	str r2, [r5, #0x3a8]
	ldr r0, [sp, #0x24]
	str r3, [r5, #0x3ac]
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
_02128C34:
	ldr r0, [sp, #0x18]
	add r4, r4, #0x10
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0xa
	ldr r0, [sp, #0x24]
	add r5, r5, #0x64
	add r0, r0, #0x64
	str r0, [sp, #0x24]
	blt _02128B3C
_02128C5C:
	ldrh r1, [r7, #0x5c]
	cmp r1, #0
	ldrne r0, [r7, #0x58]
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02128C7C
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r7, #0x36]
_02128C7C:
	add r0, r7, #0xc
	ldr r2, [r0]
	mov r1, r6
	ldr r2, [r2, #8]
	blx r2
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02128C98: .word 0x04000450
_02128C9C: .word FX_SinCosTable_

	arm_func_start _ZN21COPDCaptureDiscScreen20CLineParticleEmitter6UpdateEi
_ZN21COPDCaptureDiscScreen20CLineParticleEmitter6UpdateEi: ; 0x02128CA0
	ldr r2, [r0, #0x18]
	mov r1, #0
	str r1, [r0, #0x18]
	str r1, [r0, #0x20]
	mov r0, r2
	bx lr
	arm_func_end _ZN21COPDCaptureDiscScreen20CLineParticleEmitter6UpdateEi

	arm_func_start _ZN21COPDCaptureDiscScreen20CLineParticleEmitter4EmitEP14TFieldParticleI13CLineParticleE
_ZN21COPDCaptureDiscScreen20CLineParticleEmitter4EmitEP14TFieldParticleI13CLineParticleE: ; 0x02128CB8
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	ldr r5, [r4, #0x1c]
	mov r2, r0, lsl #0x10
	ldr r3, _02128E28 ; =0x66666667
	mov r0, r2, lsr #0x1f
	smull r2, r6, r3, r2
	add r6, r0, r6, asr #3
	mov r0, r6, lsl #0x10
	mov r2, r0, lsr #0x10
	add r0, r2, #0xff
	mov r2, r2, asr #4
	mov r3, r2, lsl #1
	add r0, r0, #0x3f00
	mov r0, r0, asr #0xe
	and r0, r0, #3
	add r2, r3, #1
	mov r0, r0, lsl #0x10
	add ip, r5, r0, lsr #13
	ldrh r0, [r5]
	ldr r5, _02128E2C ; =FX_SinCosTable_
	mov r6, r3, lsl #1
	mov r2, r2, lsl #1
	mov r0, r0, asr #4
	mov r3, r0, lsl #1
	add r0, r3, #1
	mov r3, r3, lsl #1
	mov r7, r0, lsl #1
	ldrsh r6, [r5, r6]
	ldr r8, [ip, #8]
	ldrsh r0, [r5, r2]
	ldr r2, [ip, #4]
	smull lr, r6, r8, r6
	smull r8, ip, r2, r0
	mov r0, lr, lsr #0xc
	mov r2, r8, lsr #0xc
	ldrsh r8, [r5, r3]
	orr r0, r0, r6, lsl #20
	ldrsh r7, [r5, r7]
	orr r2, r2, ip, lsl #20
	smull lr, ip, r8, r0
	smull r6, r5, r7, r2
	smull r3, r2, r8, r2
	smull r8, r0, r7, r0
	mov r6, r6, lsr #0xc
	orr r6, r6, r5, lsl #20
	mov r5, lr, lsr #0xc
	orr r5, r5, ip, lsl #20
	sub ip, r6, r5
	rsb r7, ip, #0
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	mov r2, r8, lsr #0xc
	orr r2, r2, r0, lsl #20
	add r5, r3, r2
	ldr r0, [r4, #4]
	mov r6, r1
	add r0, ip, r0
	ldr r1, [r4, #8]
	mov r2, #0xc000
	str r0, [r6, #0x64]
	add r0, r5, r1
	str r0, [r6, #0x68]
	str r2, [r6, #0x78]
	str r2, [r6, #0x7c]
	mov r0, #1
	str r0, [r6, #4]
	mov r0, r7, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r7, lsr #20
	mov r0, r7, lsl #0xc
	mov r3, #0
	bl _ll_div
	str r0, [r6, #0x6c]
	rsb r2, r5, #0
	mov r0, r2, asr #0x1f
	mov r1, r0, lsl #0xc
	orr r1, r1, r2, lsr #20
	mov r0, r2, lsl #0xc
	mov r2, #0xc000
	mov r3, #0
	bl _ll_div
	str r0, [r6, #0x70]
	mov r0, #0x1f
	str r0, [r6, #0x14]
	mov r0, #0x8000
	str r0, [r6, #0x60]
	ldr r0, [r4, #0x20]
	add r0, r0, #1
	str r0, [r4, #0x20]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02128E28: .word 0x66666667
_02128E2C: .word FX_SinCosTable_
	arm_func_end _ZN21COPDCaptureDiscScreen20CLineParticleEmitter4EmitEP14TFieldParticleI13CLineParticleE

	arm_func_start _ZN21COPDCaptureDiscScreen21CLineParticleAnimator5ApplyEP14TFieldParticleI13CLineParticleEi
_ZN21COPDCaptureDiscScreen21CLineParticleAnimator5ApplyEP14TFieldParticleI13CLineParticleEi: ; 0x02128E30
	stmdb sp!, {r3, lr}
	ldr r3, [r1, #0x78]
	ldr r0, _02128E80 ; =0x00002955
	mov r2, r3, asr #0x1f
	umull lr, ip, r3, r0
	mla ip, r2, r0, ip
	mov r0, lr, lsr #0xc
	orr r0, r0, ip, lsl #20
	mov r0, r0, asr #0xc
	str r0, [r1, #0x14]
	ldr r2, [r1, #0x78]
	mov r0, r2, asr #0x1f
	mov r0, r0, lsl #0xb
	mov r3, r2, lsl #0xb
	orr r0, r0, r2, lsr #21
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	add r0, r2, #0x2000
	str r0, [r1, #0x60]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128E80: .word 0x00002955
	arm_func_end _ZN21COPDCaptureDiscScreen21CLineParticleAnimator5ApplyEP14TFieldParticleI13CLineParticleEi

	arm_func_start _ZN21COPDCaptureDiscScreen13CSparkEmitter6UpdateEi
_ZN21COPDCaptureDiscScreen13CSparkEmitter6UpdateEi: ; 0x02128E84
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	ldr r0, [r4, #0x18]
	mov r6, r1
	cmp r0, #0
	mov r5, #0
	ble _02128F48
	bl _ZN5CGame11GetInstanceEv
	ldr r1, [r4, #0x18]
	sub r1, r1, r6
	str r1, [r4, #0x18]
	cmp r1, #0
	bgt _02128F48
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr r3, [r2, #0x448]
	ldmib r1, {r0, r5}
	umull r7, r6, r5, r3
	mla r6, r5, r0, r6
	ldr r0, [r1, #0xc]
	ldr ip, [r1, #0x10]
	mla r6, r0, r3, r6
	mov r0, #0
	ldr r5, [r1, #0x14]
	adds r7, ip, r7
	adc r5, r5, r6
	str r7, [r2, #0x448]
	str r5, [r1, #4]
	mov r0, r0, lsl #3
	ldr r7, [r2, #0x448]
	ldr r3, [r1, #8]
	ldr r6, [r1, #0x10]
	umull lr, ip, r3, r7
	mla ip, r3, r5, ip
	ldr r3, [r1, #0xc]
	orr r0, r0, r5, lsr #29
	mla ip, r3, r7, ip
	ldr r5, [r1, #0x14]
	adds r3, r6, lr
	str r3, [r2, #0x448]
	adc r5, r5, ip
	mov r2, #5
	umull r2, r3, r5, r2
	str r5, [r1, #4]
	add r2, r3, #5
	mov r1, r2, lsl #0xc
	str r1, [r4, #0x18]
	add r5, r0, #1
	arm_func_end _ZN21COPDCaptureDiscScreen13CSparkEmitter6UpdateEi
_02128F48:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN21COPDCaptureDiscScreen13CSparkEmitter4EmitEP14TFieldParticleI10CSparkLineE
_ZN21COPDCaptureDiscScreen13CSparkEmitter4EmitEP14TFieldParticleI10CSparkLineE: ; 0x02128F50
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r2, [r0, #8]
	ldr r0, [r0, #4]
	mov r4, r1
	str r0, [r4, #0x30]
	str r2, [r4, #0x34]
	mov r0, #0xa000
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	mov r0, #0
	str r0, [r4, #4]
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr ip, [r2, #0x448]
	ldmib r1, {r0, lr}
	umull r6, r5, lr, ip
	mla r5, lr, r0, r5
	ldr r0, [r1, #0xc]
	ldr r7, [r1, #0x10]
	mla r5, r0, ip, r5
	ldr lr, [r1, #0x14]
	adds r6, r7, r6
	mov r3, #0
	str r6, [r2, #0x448]
	adc r0, lr, r5
	mov r2, r3, lsl #0x10
	orr r2, r2, r0, lsr #16
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	mov r2, r2, asr #4
	mov lr, r2, lsl #1
	add r2, lr, #1
	mov r3, r2, lsl #1
	ldr ip, _0212900C ; =FX_SinCosTable_
	mov r2, lr, lsl #1
	ldrsh r3, [ip, r3]
	str r0, [r1, #4]
	ldrsh r2, [ip, r2]
	mov r0, r3, lsl #1
	str r0, [r4, #0x38]
	mov r0, r2, lsl #1
	str r0, [r4, #0x3c]
	mov r0, #0x1f
	str r0, [r4, #0x14]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0212900C: .word FX_SinCosTable_
	arm_func_end _ZN21COPDCaptureDiscScreen13CSparkEmitter4EmitEP14TFieldParticleI10CSparkLineE

	arm_func_start _ZN21COPDCaptureDiscScreen14CSparkAnimator5ApplyEP14TFieldParticleI10CSparkLineEi
_ZN21COPDCaptureDiscScreen14CSparkAnimator5ApplyEP14TFieldParticleI10CSparkLineEi: ; 0x02129010
	stmdb sp!, {r3, lr}
	ldr r3, [r1, #0x34]
	ldr r2, [r1, #0x30]
	mov r0, #6
	str r2, [r1, #0x18]
	str r3, [r1, #0x1c]
	ldr r3, [r1, #0x30]
	ldr r2, [r1, #0x38]
	ldr lr, [r1, #0x34]
	ldr ip, [r1, #0x3c]
	mla r3, r2, r0, r3
	mla r0, ip, r0, lr
	str r3, [r1, #0x20]
	str r0, [r1, #0x24]
	ldr r0, [r1, #0x30]
	str r0, [r1, #0x28]
	ldr r0, [r1, #0x34]
	str r0, [r1, #0x2c]
	ldr r0, [r1, #0x44]
	cmp r0, #0x4000
	movle r0, r0, lsl #2
	movle r0, r0, asr #0xc
	strle r0, [r1, #0x14]
	ldmia sp!, {r3, pc}
	arm_func_end _ZN21COPDCaptureDiscScreen14CSparkAnimator5ApplyEP14TFieldParticleI10CSparkLineEi

	arm_func_start _ZN21TFieldParticleEmitterI13CLineParticleE5func2Ev
_ZN21TFieldParticleEmitterI13CLineParticleE5func2Ev: ; 0x02129070
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI13CLineParticleE5func2Ev

	arm_func_start _ZN21COPDCaptureDiscScreen20CLineParticleEmitterD0Ev
_ZN21COPDCaptureDiscScreen20CLineParticleEmitterD0Ev: ; 0x02129074
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21COPDCaptureDiscScreen20CLineParticleEmitterD0Ev

	arm_func_start _ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD0Ev
_ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD0Ev: ; 0x02129088
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD0Ev

	arm_func_start _ZN21COPDCaptureDiscScreen13CSparkEmitterD0Ev
_ZN21COPDCaptureDiscScreen13CSparkEmitterD0Ev: ; 0x0212909C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21COPDCaptureDiscScreen13CSparkEmitterD0Ev

	arm_func_start _ZN21COPDCaptureDiscScreen14CSparkAnimatorD0Ev
_ZN21COPDCaptureDiscScreen14CSparkAnimatorD0Ev: ; 0x021290B0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21COPDCaptureDiscScreen14CSparkAnimatorD0Ev

	arm_func_start _ZN13CLineParticleD0Ev
_ZN13CLineParticleD0Ev: ; 0x021290C4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveQUADD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN13CLineParticleD0Ev

	arm_func_start _ZN10CSparkLineD0Ev
_ZN10CSparkLineD0Ev: ; 0x021290E0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN14CPrimitiveLINED2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN10CSparkLineD0Ev

	arm_func_start _ZN21TFieldParticleEmitterI10CSparkLineED0Ev
_ZN21TFieldParticleEmitterI10CSparkLineED0Ev: ; 0x021290FC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21TFieldParticleEmitterI10CSparkLineED0Ev

	arm_func_start _ZN21TFieldParticleEmitterI13CLineParticleED0Ev
_ZN21TFieldParticleEmitterI13CLineParticleED0Ev: ; 0x02129110
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN21TFieldParticleEmitterI13CLineParticleED0Ev

	arm_func_start _ZN21TFieldParticleEmitterI13CLineParticleED1Ev
_ZN21TFieldParticleEmitterI13CLineParticleED1Ev: ; 0x02129124
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI13CLineParticleED1Ev

	arm_func_start _ZN21TFieldParticleEmitterI10CSparkLineED1Ev
_ZN21TFieldParticleEmitterI10CSparkLineED1Ev: ; 0x02129128
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI10CSparkLineED1Ev

	arm_func_start _ZN21TFieldParticleEmitterI10CSparkLineE5func2Ev
_ZN21TFieldParticleEmitterI10CSparkLineE5func2Ev: ; 0x0212912C
	bx lr
	arm_func_end _ZN21TFieldParticleEmitterI10CSparkLineE5func2Ev

	arm_func_start ov3_02129130
ov3_02129130: ; 0x02129130
	stmdb sp!, {r4, lr}
	ldr r1, _0212915C ; =ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	mov r4, r0
	str r1, [r4]
	bl ov3_02129280
	add r0, r4, #0x30
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212915C: .word ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	arm_func_end ov3_02129130

	arm_func_start ov3_02129160
ov3_02129160: ; 0x02129160
	stmdb sp!, {r4, lr}
	ldr r1, _02129194 ; =ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	mov r4, r0
	str r1, [r4]
	bl ov3_02129280
	add r0, r4, #0x30
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02129194: .word ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	arm_func_end ov3_02129160

	arm_func_start ov3_02129198
ov3_02129198: ; 0x02129198
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0xc
	mov r4, r0
	ldr r0, [r4, #0x1c]
	mov r5, r1
	cmp r0, #0
	beq _021291C0
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x1c]
	arm_func_end ov3_02129198
_021291C0:
	mov r0, r5, lsl #1
	str r0, [r4, #0x20]
	cmp r0, #0
	ble _021291DC
	mov r0, r0, lsl #3
	bl _Znam
	str r0, [r4, #0x1c]
_021291DC:
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _02129214
	ldr r2, _02129268 ; =s_OPD_i001_NCLR_overlay_3_0212b498
	ldr r1, _0212926C ; =s_OPD_i001_00_NCER_overlay_3_0212b4a8
	str r2, [sp]
	ldr ip, _02129270 ; =s_OPD_i001_00_cac_overlay_3_0212b4bc
	str r1, [sp, #4]
	ldr r1, _02129274 ; =s_OPD_overlay_3_0212b464
	ldr r2, _02129278 ; =s_data_interface_i001_LZ_bin_overlay_3_0212b468
	ldr r3, _0212927C ; =s_OPD_i001_00_NCBR_overlay_3_0212b484
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_02129214:
	str r0, [r4, #0x2c]
	ldmia r0, {r0, r1, r3}
	mov r2, #0
	str r0, [r4, #0x5c]
	str r2, [r4, #0x60]
	str r1, [r4, #0x64]
	str r3, [r4, #0x68]
	str r2, [r4, #0x48]
	str r2, [r4, #0x4c]
	ldr r0, [r4, #0x2c]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02129254
	mov r1, #1
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	strh r0, [r4, #0x7c]
_02129254:
	mov r0, #0
	str r0, [r4, #0x28]
	str r0, [r4, #0x24]
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02129268: .word s_OPD_i001_NCLR_overlay_3_0212b498
_0212926C: .word s_OPD_i001_00_NCER_overlay_3_0212b4a8
_02129270: .word s_OPD_i001_00_cac_overlay_3_0212b4bc
_02129274: .word s_OPD_overlay_3_0212b464
_02129278: .word s_data_interface_i001_LZ_bin_overlay_3_0212b468
_0212927C: .word s_OPD_i001_00_NCBR_overlay_3_0212b484

	arm_func_start ov3_02129280
ov3_02129280: ; 0x02129280
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	ldrneh r1, [r5, #0x7c]
	cmpne r1, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _021292B0
	bl _ZN17UnkClass_0200878812sub_02008B80Et
	mov r0, #0
	strh r0, [r5, #0x7c]
	arm_func_end ov3_02129280
_021292B0:
	ldr r4, [r5, #0x2c]
	cmp r4, #0
	beq _021292D8
	beq _021292D0
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_021292D0:
	mov r0, #0
	str r0, [r5, #0x2c]
_021292D8:
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	beq _021292F0
	bl _ZdlPv
	mov r0, #0
	str r0, [r5, #0x1c]
_021292F0:
	mov r0, #0
	str r0, [r5, #0x20]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN15COPDCaptureLine12ov3_021292FCEP7Point2Di
_ZN15COPDCaptureLine12ov3_021292FCEP7Point2Di: ; 0x021292FC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x68
	mov r8, r0
	mov r0, r2
	str r2, [sp, #4]
	str r1, [sp]
	cmp r0, #2
	addlo sp, sp, #0x68
	ldmloia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	cmp r0, #1
	mov r0, r1
	add r6, r0, #8
	mov r7, #1
	bls _021295C8
	arm_func_end _ZN15COPDCaptureLine12ov3_021292FCEP7Point2Di
_02129334:
	cmp r7, #2
	bge _02129418
	ldr sl, [r6, #-8]
	ldr sb, [r6, #-4]
	ldr r1, [r6]
	ldr r0, [r6, #4]
	sub r4, r1, sl
	sub r5, r0, sb
	smull r3, r2, r4, r4
	smull r1, r0, r5, r5
	str sl, [sp, #0x40]
	str sb, [sp, #0x44]
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	str r4, [sp, #0x38]
	str r5, [sp, #0x3c]
	str r4, [sp, #0x60]
	str r5, [sp, #0x64]
	bl FX_InvSqrt
	mov r1, r0, asr #0x1f
	mov r2, r1, lsl #0xe
	mov r3, r0, lsl #0xe
	sub r1, r7, #1
	orr r2, r2, r0, lsr #18
	mov r5, r3, lsr #0xc
	orr r5, r5, r2, lsl #20
	mov r0, r1, lsl #1
	smull r1, r2, r4, r5
	mov r1, r1, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [sp, #0x60]
	ldr r3, [sp, #0x64]
	ldr r2, [r6, #-8]
	smull r5, r4, r3, r5
	mov r3, r5, lsr #0xc
	orr r3, r3, r4, lsl #20
	str r3, [sp, #0x64]
	ldr sb, [r6, #-4]
	add r5, r2, r3
	sub r3, r2, r3
	ldr r2, [r8, #0x1c]
	sub r4, sb, r1
	str r5, [r2, r0, lsl #3]
	add r2, sb, r1
	ldr r1, [r8, #0x1c]
	add r1, r1, r0, lsl #3
	str r4, [r1, #4]
	ldr r1, [r8, #0x1c]
	add r1, r1, r0, lsl #3
	str r3, [r1, #8]
	ldr r1, [r8, #0x1c]
	add r0, r1, r0, lsl #3
	str r2, [r0, #0xc]
	b _021295B4
_02129418:
	ldr sl, [r6, #-0x10]
	ldr sb, [r6, #-0xc]
	ldr r1, [r6]
	ldr r0, [r6, #4]
	sub r4, r1, sl
	sub r5, r0, sb
	smull r3, r2, r4, r4
	smull r1, r0, r5, r5
	str sl, [sp, #0x30]
	str sb, [sp, #0x34]
	mov r3, r3, lsr #0xc
	mov r1, r1, lsr #0xc
	orr r3, r3, r2, lsl #20
	orr r1, r1, r0, lsl #20
	add r0, r3, r1
	str r4, [sp, #0x28]
	str r5, [sp, #0x2c]
	str r4, [sp, #0x58]
	str r5, [sp, #0x5c]
	bl FX_InvSqrt
	ldr r3, [r6, #-0x10]
	ldr r2, [r6, #-0xc]
	ldr r1, [r6, #-8]
	smull sb, r5, r4, r0
	mov r4, sb, lsr #0xc
	orr r4, r4, r5, lsl #20
	str r4, [sp, #0x58]
	sub r4, r1, r3
	str r3, [sp, #0x20]
	ldr r1, [r6, #-4]
	str r2, [sp, #0x24]
	sub r2, r1, r2
	ldr r1, [sp, #0x5c]
	str r4, [sp, #0x18]
	smull r3, r0, r1, r0
	mov r1, r3, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r1, [sp, #0x5c]
	str r2, [sp, #0x1c]
	str r4, [sp, #0x50]
	str r2, [sp, #0x54]
	smull r1, r0, r2, r2
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	smull r2, r0, r4, r4
	mov r2, r2, lsr #0xc
	orr r2, r2, r0, lsl #20
	add r0, r2, r1
	bl FX_InvSqrt
	smull r1, r2, r4, r0
	mov r1, r1, lsr #0xc
	orr r1, r1, r2, lsl #20
	str r1, [sp, #0x50]
	ldr r2, [sp, #0x54]
	ldr r5, [sp, #0x5c]
	smull r3, r0, r2, r0
	mov sb, r3, lsr #0xc
	orr sb, sb, r0, lsl #20
	str sb, [sp, #0x54]
	mov r4, r5, asr #0x1f
	mov r0, sb, asr #0x1f
	umull r3, r2, r5, sb
	mla r2, r5, r0, r2
	mla r2, r4, sb, r2
	mov r3, r3, lsr #0xc
	ldr sb, [sp, #0x58]
	orr r3, r3, r2, lsl #20
	smull r2, r1, sb, r1
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	add r2, r2, r3
	mov r0, #0x4000000
	mov r1, #0
	mov r3, r2, asr #0x1f
	bl _ll_div
	smull r2, r1, sb, r0
	mov fp, r2, lsr #0xc
	orr fp, fp, r1, lsl #20
	sub r1, r7, #1
	ldr sb, [r6, #-4]
	mov r3, r1, lsl #1
	sub r1, sb, fp
	add fp, sb, fp
	mov sl, r0, asr #0x1f
	umull sb, lr, r5, r0
	mla lr, r5, sl, lr
	mla lr, r4, r0, lr
	mov r4, sb, lsr #0xc
	ldr ip, [r6, #-8]
	orr r4, r4, lr, lsl #20
	ldr r2, [r8, #0x1c]
	add r0, ip, r4
	str r0, [r2, r3, lsl #3]
	ldr r0, [r8, #0x1c]
	sub r2, ip, r4
	add r0, r0, r3, lsl #3
	str r1, [r0, #4]
	ldr r0, [r8, #0x1c]
	add r0, r0, r3, lsl #3
	str r2, [r0, #8]
	ldr r0, [r8, #0x1c]
	add r0, r0, r3, lsl #3
	str fp, [r0, #0xc]
_021295B4:
	ldr r0, [sp, #4]
	add r7, r7, #1
	cmp r7, r0
	add r6, r6, #8
	blo _02129334
_021295C8:
	ldr r1, [sp]
	ldr r0, [sp, #4]
	add r4, r1, r0, lsl #3
	sub r5, r4, #8
	ldr r3, [r5, #-8]
	ldr r2, [r5, #-4]
	ldr r1, [r4, #-8]
	ldr r0, [r5, #4]
	sub r6, r1, r3
	sub r1, r0, r2
	smull sl, sb, r6, r6
	smull r7, r0, r1, r1
	mov sl, sl, lsr #0xc
	mov r7, r7, lsr #0xc
	orr sl, sl, sb, lsl #20
	orr r7, r7, r0, lsl #20
	add r0, sl, r7
	str r3, [sp, #0x10]
	str r2, [sp, #0x14]
	str r6, [sp, #8]
	str r1, [sp, #0xc]
	str r6, [sp, #0x48]
	str r1, [sp, #0x4c]
	bl FX_InvSqrt
	mov r1, r0, asr #0x1f
	mov r2, r1, lsl #0xe
	mov r3, r0, lsl #0xe
	orr r2, r2, r0, lsr #18
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	smull sb, r7, r6, r3
	ldr r0, [sp, #0x4c]
	ldr r1, [sp, #4]
	smull r3, r2, r0, r3
	mov r6, r3, lsr #0xc
	sub r1, r1, #1
	orr r6, r6, r2, lsl #20
	ldr r3, [r4, #-8]
	mov sb, sb, lsr #0xc
	add r2, r3, r6
	orr sb, sb, r7, lsl #20
	ldr r5, [r5, #4]
	ldr r0, [r8, #0x1c]
	mov r1, r1, lsl #1
	str r2, [r0, r1, lsl #3]
	ldr r0, [r8, #0x1c]
	sub r4, r5, sb
	add r0, r0, r1, lsl #3
	str r4, [r0, #4]
	ldr r0, [r8, #0x1c]
	sub r3, r3, r6
	add r1, r1, #1
	str r3, [r0, r1, lsl #3]
	ldr r0, [r8, #0x1c]
	add r2, r5, sb
	add r0, r0, r1, lsl #3
	str r2, [r0, #4]
	ldr r0, [sp, #4]
	str sb, [sp, #0x48]
	str r6, [sp, #0x4c]
	str r0, [r8, #0x24]
	add sp, sp, #0x68
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov3_021296C4
ov3_021296C4: ; 0x021296C4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x20
	mov r8, r0
	ldr r0, [r8, #0x24]
	ldr r2, [r8, #0x28]
	mov r7, r1
	cmp r2, r0
	movhi r6, r0
	movls r6, r2
	ldr r5, [r8, #0x1c]
	cmp r2, #0xc0
	bls _0212972C
	cmp r2, r0
	bls _02129720
	sub r0, r2, r0
	rsb r6, r0, #0xc0
	cmp r6, #0
	addle sp, sp, #0x20
	movle r0, #0
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	sub r0, r2, #0xc0
	add r5, r5, r0, lsl #4
	b _0212972C
	arm_func_end ov3_021296C4
_02129720:
	sub r0, r6, #0xc0
	add r5, r5, r0, lsl #4
	mov r6, #0xc0
_0212972C:
	cmp r6, #2
	addlt sp, sp, #0x20
	movlt r0, #0
	ldmltia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr sl, [r5]
	ldr r1, [r5, #0xc]
	add r4, r5, r6, lsl #4
	ldmib r5, {r2, sb}
	sub r3, r4, #0x10
	sub r0, r4, #8
	add r1, r2, r1
	add sb, sl, sb
	mov r2, sb, asr #1
	ldr sb, [r4, #-0x10]
	ldr r4, [r4, #-8]
	mov r1, r1, asr #1
	add r4, sb, r4
	mov ip, r4, asr #1
	ldr r3, [r3, #4]
	ldr r0, [r0, #4]
	ldrsh r4, [r7, #0x28]
	add r0, r3, r0
	mov sl, r0, asr #1
	ldr r3, _021299C8 ; =0x04000450
	mov sb, #0
	mov r0, r8
	str sb, [r3]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	str ip, [sp, #0x10]
	str sl, [sp, #0x14]
	bl ov3_021299E0
	rsb r0, r4, #0xc
	mov r0, r0, lsl #0x10
	ldrh r2, [r8, #8]
	ldr r1, _021299CC ; =0x04000480
	cmp r6, #2
	str r2, [r1]
	mov lr, r0, asr #0x10
	mov r4, sb
	blt _02129924
_021297D0:
	ldr r0, [r8, #0xc]
	ldr r1, [r8, #0x10]
	mov r0, r0, lsl #4
	add r2, r4, r1
	orr r1, r0, #0xc0
	orr r1, r1, r2, lsl #24
	ldr r3, [r8, #0x14]
	ldr r0, _021299D0 ; =0x040004A4
	orr r1, r1, r3, lsl #16
	str r1, [r0]
	mov r1, #3
	str r1, [r0, #0x5c]
	mov r2, #0
	str r2, [r0, #-0x1c]
	ldr r1, [r5, #4]
	ldr r3, [r5], #8
	mov r1, r1, asr lr
	ldr sb, [r8, #4]
	mov r3, r3, asr lr
	mov r1, r1, lsl #0x10
	mov r1, r1, asr #0x10
	add sl, sb, r4
	mov sb, r1, lsl #0x10
	mov r1, sl, lsl #0x10
	mov r3, r3, lsl #0x10
	mov sb, sb, lsr #0x10
	mov sl, r3, asr #0x10
	mov r1, r1, asr #0x10
	mov r3, r1, lsl #0x10
	mov r1, sl, lsl #0x10
	mov sb, sb, lsl #0x10
	orr sb, sb, r1, lsr #16
	sub r1, r0, #0x18
	str sb, [r1]
	mov r0, r3, lsr #0x10
	str r0, [r1]
	ldr r1, [r8, #0x1c]
	ldr r0, [r8, #0x20]
	mov ip, #1
	add r0, r1, r0, lsl #3
	cmp r5, r0
	movhs r5, r1
	cmp r6, #0x40
	movlt r0, r6
	movge r0, #0x40
	mov r3, r0, lsl #1
	cmp r3, #1
	bls _02129904
	ldr r1, _021299D4 ; =0x04000488
_02129894:
	rsb r2, r2, #0x20000
	mov r0, r2, lsl #8
	mov r0, r0, asr #0x10
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	str r0, [r1]
	ldr r0, [r5, #4]
	ldr sl, [r5], #8
	mov sb, r0, asr lr
	mov r0, sl, asr lr
	mov sb, sb, lsl #0x10
	mov sb, sb, asr #0x10
	mov r0, r0, lsl #0x10
	mov sb, sb, lsl #0x10
	mov r0, r0, asr #0x10
	mov sb, sb, lsr #0x10
	mov r0, r0, lsl #0x10
	mov sb, sb, lsl #0x10
	orr r0, sb, r0, lsr #16
	str r0, [r1, #0xc]
	ldr sb, [r8, #0x1c]
	ldr r0, [r8, #0x20]
	add ip, ip, #1
	add r0, sb, r0, lsl #3
	cmp r5, r0
	movhs r5, sb
	cmp ip, r3
	blo _02129894
_02129904:
	ldr r0, _021299D8 ; =0x04000504
	sub r6, r6, #0x3f
	mov r1, #0
	str r1, [r0]
	cmp r6, #2
	sub r5, r5, #0x10
	add r4, r4, #1
	bge _021297D0
_02129924:
	ldr r0, _021299DC ; =0x04000448
	mov r1, #0
	str r1, [r0]
	ldrh r1, [r8, #0x7c]
	cmp r1, #0
	ldrne r0, [r8, #0x2c]
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _02129950
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r8, #0x5a]
_02129950:
	ldr r5, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	str r5, [r8, #0x48]
	str r3, [r8, #0x4c]
	ldr r1, [r8, #4]
	add r0, r8, #0x30
	str r1, [r8, #0x34]
	ldr r2, [r0]
	mov r1, r7
	ldr r2, [r2, #8]
	str r5, [sp, #8]
	str r3, [sp, #0xc]
	blx r2
	ldr r5, [sp, #0x10]
	ldr r3, [sp, #0x14]
	str r5, [r8, #0x48]
	str r3, [r8, #0x4c]
	ldr r1, [r8, #4]
	add r0, r8, #0x30
	add r1, r1, r4
	str r1, [r8, #0x34]
	ldr r2, [r0]
	mov r1, r7
	ldr r2, [r2, #8]
	str r5, [sp]
	str r3, [sp, #4]
	blx r2
	mov r0, #1
	add sp, sp, #0x20
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_021299C8: .word 0x04000450
_021299CC: .word 0x04000480
_021299D0: .word 0x040004A4
_021299D4: .word 0x04000488
_021299D8: .word 0x04000504
_021299DC: .word 0x04000448

	arm_func_start ov3_021299E0
ov3_021299E0: ; 0x021299E0
	ldr r3, [r0, #0x18]
	cmp r3, #0
	bxeq lr
	ldr r0, [r3, #0x1c]
	ldr r1, [r3, #8]
	mov r0, r0, lsl #0x1a
	orr r0, r0, r1, lsr #3
	ldr r1, [r3, #0x20]
	orr r0, r0, #0x40000000
	ldr r2, [r3, #0x24]
	orr r0, r0, r1, lsl #20
	orr r1, r0, r2, lsl #23
	ldr r0, _02129A44 ; =0x040004A8
	orr r1, r1, #0x30000
	str r1, [r0]
	ldr r0, [r3, #0x1c]
	ldr r1, [r3, #0xc]
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	rsb r0, r0, #4
	mov r1, r1, lsr r0
	ldr r0, _02129A48 ; =0x040004AC
	str r1, [r0]
	bx lr
	.align 2, 0
_02129A44: .word 0x040004A8
_02129A48: .word 0x040004AC
	arm_func_end ov3_021299E0

	arm_func_start _ZN15COPDCaptureLine12ov3_02129A4CEv
_ZN15COPDCaptureLine12ov3_02129A4CEv: ; 0x02129A4C
	stmdb sp!, {r3, lr}
	ldr r0, [r0, #0x2c]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	ldmia sp!, {r3, pc}
	arm_func_end _ZN15COPDCaptureLine12ov3_02129A4CEv

	arm_func_start _ZN17COPDScreenMeshNTFD1Ev
_ZN17COPDScreenMeshNTFD1Ev: ; 0x02129A68
	stmdb sp!, {r4, lr}
	ldr r1, _02129A8C ; =ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0
	mov r4, r0
	str r1, [r4]
	bl _ZN17COPDScreenMeshNTF12ov3_02129C54Ev
	mov r0, r4
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02129A8C: .word ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0
	arm_func_end _ZN17COPDScreenMeshNTFD1Ev

	arm_func_start ov3_02129A90
ov3_02129A90: ; 0x02129A90
	stmdb sp!, {r4, lr}
	ldr r1, _02129ABC ; =ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0
	mov r4, r0
	str r1, [r4]
	bl _ZN17COPDScreenMeshNTF12ov3_02129C54Ev
	mov r0, r4
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02129ABC: .word ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0
	arm_func_end ov3_02129A90

	arm_func_start _ZN17COPDScreenMeshNTF12ov3_02129AC0Eiillllll
_ZN17COPDScreenMeshNTF12ov3_02129AC0Eiillllll: ; 0x02129AC0
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	mov sl, r0
	strh r1, [sl, #0x24]
	strh r2, [sl, #0x26]
	ldrh r1, [sl, #0x24]
	ldrh r0, [sl, #0x26]
	str r3, [sp]
	add r1, r1, #1
	add r0, r0, #1
	mul r0, r1, r0
	ldr r1, [sp, #0x40]
	mov r0, r0, lsl #3
	str r1, [sp, #0x40]
	ldr r1, [sp, #0x44]
	str r1, [sp, #0x44]
	ldr r1, [sp, #0x48]
	str r1, [sp, #0x48]
	bl _Znam
	str r0, [sl, #0x1c]
	ldrh r1, [sl, #0x24]
	ldrh r0, [sl, #0x26]
	add r1, r1, #1
	add r0, r0, #1
	mul r0, r1, r0
	mov r0, r0, lsl #3
	bl _Znam
	str r0, [sl, #0x20]
	ldrh r6, [sl, #0x26]
	mov r5, r0
	ldr r4, [sl, #0x1c]
	add r0, r6, #1
	cmp r0, #0
	mov r0, #0
	str r0, [sp, #0x14]
	addle sp, sp, #0x18
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r2, [sp, #0x50]
	str r0, [sp, #0x10]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x48]
	ldr r1, [sp, #0x4c]
	sub r0, r2, r0
	str r0, [sp, #4]
	ldr r0, [sp, #0x44]
	sub r0, r1, r0
	str r0, [sp, #8]
	arm_func_end _ZN17COPDScreenMeshNTF12ov3_02129AC0Eiillllll
_02129B7C:
	ldr r0, [sp, #0x10]
	mov r1, r6
	bl _s32_div_f
	ldr r2, [sp, #0x40]
	mov r1, r6
	add fp, r2, r0
	ldr r0, [sp, #0xc]
	bl _s32_div_f
	ldr r1, [sp, #0x48]
	mov r7, #0
	add r6, r1, r0
	ldrh r1, [sl, #0x24]
	add r0, r1, #1
	cmp r0, #0
	ble _02129C14
	mov r8, r7
	mov sb, r7
_02129BC0:
	mov r0, r8
	bl _s32_div_f
	ldr r1, [sp]
	add r0, r1, r0
	stmia r4, {r0, fp}
	ldrh r1, [sl, #0x24]
	mov r0, sb
	bl _s32_div_f
	ldr r1, [sp, #0x44]
	add r7, r7, #1
	add r0, r1, r0
	stmia r5, {r0, r6}
	ldr r0, [sp, #8]
	ldrh r1, [sl, #0x24]
	add sb, sb, r0
	add r4, r4, #8
	add r0, r1, #1
	add r5, r5, #8
	add r8, r8, #0x100000
	cmp r7, r0
	blt _02129BC0
_02129C14:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0xc]
	add r0, r0, #0xc0000
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	ldrh r6, [sl, #0x26]
	add r0, r1, r0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	add r1, r6, #1
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, r1
	blt _02129B7C
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start _ZN17COPDScreenMeshNTF12ov3_02129C54Ev
_ZN17COPDScreenMeshNTF12ov3_02129C54Ev: ; 0x02129C54
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _02129C74
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x1c]
	arm_func_end _ZN17COPDScreenMeshNTF12ov3_02129C54Ev
_02129C74:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x20]
	ldmia sp!, {r4, pc}

	arm_func_start ov3_02129C90
ov3_02129C90: ; 0x02129C90
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r4, r0
	ldr r0, [r4, #0x18]
	mov r5, r1
	cmp r0, #0
	beq _02129CB4
	mov r1, #0
	mov r2, r1
	bl _ZN17UnkClass_02041D984BindE15GXTexPlttColor08GXTexGen
	arm_func_end ov3_02129C90
_02129CB4:
	ldr r3, _02129E88 ; =0x04000450
	mov lr, #0
	str lr, [r3]
	ldrh r5, [r5, #0x28]
	ldrh r0, [r4, #8]
	str r0, [r3, #0x30]
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	mov r0, r0, lsl #4
	orr r0, r0, #0xc0
	ldr r2, [r4, #0x14]
	orr r0, r0, r1, lsl #24
	orr r0, r0, r2, lsl #16
	str r0, [r3, #0x54]
	ldrh r0, [r4, #0x26]
	ldr r3, [r4, #0x1c]
	ldr ip, [r4, #0x20]
	cmp r0, #0
	ble _02129E74
	rsb r6, r5, #0xc
_02129D04:
	ldr r1, _02129E8C ; =0x04000500
	mov r0, #3
	str r0, [r1]
	ldrh r0, [r4, #0x24]
	mov r5, #0
	add r0, r0, #1
	cmp r0, #0
	ble _02129E58
	sub r2, r1, #0x78
	sub r1, r1, #0x74
_02129D2C:
	ldr r0, [ip, #4]
	ldr r8, [ip]
	mov r0, r0, lsl #8
	mov r7, r0, asr #0x10
	mov r0, r8, lsl #8
	mov r7, r7, lsl #0x10
	mov r0, r0, asr #0x10
	mov r7, r7, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r7, r7, lsl #0x10
	orr r0, r7, r0, lsr #16
	str r0, [r2]
	ldr r0, [r3, #4]
	ldr r7, [r3]
	mov r0, r0, asr r6
	mov r7, r7, asr r6
	mov r0, r0, lsl #0x10
	mov r0, r0, asr #0x10
	ldr sb, [r4, #4]
	mov r7, r7, lsl #0x10
	mov r8, r0, lsl #0x10
	mov r0, sb, lsl #0x10
	mov sb, r7, asr #0x10
	mov r8, r8, lsr #0x10
	mov r0, r0, asr #0x10
	mov r7, r0, lsl #0x10
	mov r0, sb, lsl #0x10
	mov r8, r8, lsl #0x10
	orr r0, r8, r0, lsr #16
	str r0, [r1]
	mov r0, r7, lsr #0x10
	str r0, [r1]
	ldrh r0, [r4, #0x24]
	add r5, r5, #1
	add r7, ip, r0, lsl #3
	ldr r0, [r7, #0xc]
	ldr r8, [r7, #8]
	mov r0, r0, lsl #8
	mov r7, r0, asr #0x10
	mov r0, r8, lsl #8
	mov r7, r7, lsl #0x10
	mov r0, r0, asr #0x10
	mov r7, r7, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r7, r7, lsl #0x10
	orr r0, r7, r0, lsr #16
	str r0, [r2]
	ldrh r7, [r4, #0x24]
	ldr r0, [r4, #4]
	add ip, ip, #8
	add r8, r3, r7, lsl #3
	ldr r7, [r8, #0xc]
	ldr r8, [r8, #8]
	mov r7, r7, asr r6
	mov sb, r8, asr r6
	mov r7, r7, lsl #0x10
	mov r8, r7, asr #0x10
	mov r7, sb, lsl #0x10
	mov r8, r8, lsl #0x10
	mov r0, r0, lsl #0x10
	mov sb, r7, asr #0x10
	mov r8, r8, lsr #0x10
	mov r0, r0, asr #0x10
	mov r7, r0, lsl #0x10
	mov r0, sb, lsl #0x10
	mov r8, r8, lsl #0x10
	orr r0, r8, r0, lsr #16
	str r0, [r1]
	mov r0, r7, lsr #0x10
	str r0, [r1]
	ldrh r0, [r4, #0x24]
	add r3, r3, #8
	add r0, r0, #1
	cmp r5, r0
	blt _02129D2C
_02129E58:
	ldr r0, _02129E90 ; =0x04000504
	mov r1, #0
	str r1, [r0]
	ldrh r0, [r4, #0x26]
	add lr, lr, #1
	cmp lr, r0
	blt _02129D04
_02129E74:
	ldr r0, _02129E94 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02129E88: .word 0x04000450
_02129E8C: .word 0x04000500
_02129E90: .word 0x04000504
_02129E94: .word 0x04000448

	arm_func_start _ZN17UnkClass_02129E98C1Ev
_ZN17UnkClass_02129E98C1Ev: ; 0x02129E98
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #4
	ldr r5, _02129F44 ; =_ZN14CPrimitiveRECTD1Ev
	ldr r3, _02129F48 ; =FUN_02003B64
	mov r1, #7
	mov r2, #0x40
	mov r4, r0
	str r5, [sp]
	bl __cxa_vec_ctor
	mov r0, #0
	str r0, [r4, #0x1c0]
	str r0, [r4, #0x1c4]
	str r0, [r4, #0x1c8]
	str r0, [r4, #0x1cc]
	sub r1, r0, #0x70000
	ldr r6, _02129F4C ; =DAT_overlay_3_0212a6ac
	ldr r2, _02129F50 ; =DAT_overlay_3_0212a690
	str r1, [r4, #0x1d0]
	sub sl, r0, #0x10000
	mov sb, #6
	mov r7, #0x68
	mov lr, #0x64000
	mov ip, r0
	mov r3, #3
	arm_func_end _ZN17UnkClass_02129E98C1Ev
_02129EF8:
	add r8, r4, r0, lsl #6
	str sb, [r8, #0x10]
	ldr r5, [r6, r0, lsl #2]
	str r7, [r8, #4]
	str r5, [r8, #0x20]
	add r1, sl, r5, asr #1
	str lr, [r8, #0x24]
	str r1, [r8, #0x18]
	str ip, [r8, #0x1c]
	ldr r1, [r2, r0, lsl #2]
	str r3, [r8, #0xc]
	add r0, r0, #1
	str r1, [r8, #0x14]
	cmp r0, #7
	add sl, sl, r5
	blt _02129EF8
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02129F44: .word _ZN14CPrimitiveRECTD1Ev
_02129F48: .word _ZN14CPrimitiveRECTC1Ev
_02129F4C: .word DAT_overlay_3_0212a6ac
_02129F50: .word DAT_overlay_3_0212a690

	arm_func_start _ZN17UnkClass_02129E98D1Ev
_ZN17UnkClass_02129E98D1Ev: ; 0x02129F54
	stmdb sp!, {r4, lr}
	ldr r3, _02129F74 ; =_ZN14CPrimitiveRECTD1Ev
	mov r1, #7
	mov r2, #0x40
	mov r4, r0
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02129F74: .word _ZN14CPrimitiveRECTD1Ev
	arm_func_end _ZN17UnkClass_02129E98D1Ev

	arm_func_start _ZN17UnkClass_02129E9812ov3_02129F78Ev
_ZN17UnkClass_02129E9812ov3_02129F78Ev: ; 0x02129F78
	ldr r2, [r0, #0x1c4]
	cmp r2, #0
	beq _02129FB4
	ldr r1, [r0, #0x1c0]
	add r1, r1, r2
	str r1, [r0, #0x1c0]
	str r1, [r0, #0x1cc]
	ldr r1, [r0, #0x1c0]
	cmp r1, #0x80000
	bxlt lr
	mov r1, #0
	str r1, [r0, #0x1c4]
	mov r1, #0x168
	str r1, [r0, #0x1c8]
	bx lr
	arm_func_end _ZN17UnkClass_02129E9812ov3_02129F78Ev
_02129FB4:
	ldr r1, [r0, #0x1c8]
	cmp r1, #0
	subne r1, r1, #1
	strne r1, [r0, #0x1c8]
	bxne lr
	mov r2, #0x8000
	sub r1, r2, #0xc8000
	str r2, [r0, #0x1c4]
	str r1, [r0, #0x1c0]
	str r1, [r0, #0x1cc]
	bx lr

	arm_func_start _ZN17UnkClass_02129E9812ov3_02129FE0EP8Camera2D
_ZN17UnkClass_02129E9812ov3_02129FE0EP8Camera2D: ; 0x02129FE0
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x24
	mov sl, r0
	ldr r0, [sl, #0x1c4]
	mov sb, r1
	cmp r0, #0
	addeq sp, sp, #0x24
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r2, #0x4000000
	ldr r1, [r2]
	ldr r0, _0212A0A4 ; =FX_SinCosTable_+0x400
	bic r1, r1, #0xe000
	orr r1, r1, #0x2000
	str r1, [r2]
	ldrsh r1, [r0, #0x70]
	ldrsh r2, [r0, #0x72]
	ldrh r4, [sb, #0x28]
	add r0, sp, #0
	blx MTX_RotZ33_
	rsb r2, r4, #0xc
	ldr r1, [sl, #0x1cc]
	ldr r0, [sl, #0x1d0]
	mov r8, #0
	mov r6, r1, asr r2
	mov r7, r0, asr r2
	ldr r4, _0212A0A8 ; =0x04000450
	mov r5, r8
	add fp, sp, #0
	arm_func_end _ZN17UnkClass_02129E9812ov3_02129FE0EP8Camera2D
_0212A050:
	str r5, [r4]
	str r6, [r4, #0x20]
	str r7, [r4, #0x20]
	mov r0, fp
	str r5, [r4, #0x20]
	bl G3_MultMtx33
	mov r0, sl
	ldr r2, [r0]
	mov r1, sb
	ldr r2, [r2, #8]
	blx r2
	add r8, r8, #1
	cmp r8, #7
	add sl, sl, #0x40
	blt _0212A050
	mov r1, #0x4000000
	ldr r0, [r1]
	bic r0, r0, #0xe000
	str r0, [r1]
	add sp, sp, #0x24
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0212A0A4: .word FX_SinCosTable_+0x400
_0212A0A8: .word 0x04000450

    .rodata

    .global DAT_overlay_3_0212a688
DAT_overlay_3_0212a688: ; 0x0212A688
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212a68c
DAT_overlay_3_0212a68c: ; 0x0212A68C
	.byte 0x00, 0x00, 0xF9, 0xFF

    .global DAT_overlay_3_0212a690
DAT_overlay_3_0212a690: ; 0x0212A690
	.byte 0x05, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212a694
DAT_overlay_3_0212a694: ; 0x0212A694
	.byte 0x0D, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00
	.byte 0x18, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212a6ac
DAT_overlay_3_0212a6ac: ; 0x0212A6AC
	.byte 0x00, 0x10, 0x00, 0x00

    .global DAT_overlay_3_0212a6b0
DAT_overlay_3_0212a6b0: ; 0x0212A6B0
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00
	.byte 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00

    .section .sinit,4 ; 0x0212A6C8

    .data

    .global PTR_ptr_FUN_02083578_overlay_3_0212b07c
PTR_ptr_FUN_02083578_overlay_3_0212b07c: ; 0x0212B07C
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_24TFieldParticleForceFieldI13CLi_overlay_3_0212b2e8

    .global PTR_ptr_FUN_02083578_overlay_3_0212b084
PTR_ptr_FUN_02083578_overlay_3_0212b084: ; 0x0212B084
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_24TFieldParticleForceFieldI10CSp_overlay_3_0212b238

    .global PTR_ptr_FUN_02083578_overlay_3_0212b08c
PTR_ptr_FUN_02083578_overlay_3_0212b08c: ; 0x0212B08C
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_21TFieldParticleEmitterI13CLineP_overlay_3_0212b290

    .global PTR_ptr_FUN_02083578_overlay_3_0212b094
PTR_ptr_FUN_02083578_overlay_3_0212b094: ; 0x0212B094
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_21TFieldParticleEmitterI10CSpark_overlay_3_0212b1e8

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b09c
PTR_ptr_FUN_020835bc_overlay_3_0212b09c: ; 0x0212B09C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21COPDCaptureDiscScreen20CLineP_overlay_3_0212b314
	.word PTR_ptr_FUN_02083578_overlay_3_0212b08c

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b0a8
PTR_ptr_FUN_020835bc_overlay_3_0212b0a8: ; 0x0212B0A8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_10CSparkLine_overlay_3_0212b0f0
	.word _ZTI14CPrimitiveLINE

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b0b4
PTR_ptr_FUN_020835bc_overlay_3_0212b0b4: ; 0x0212B0B4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_21COPDCaptureDiscScreen_overlay_3_0212b160
	.word _ZTI10COPDScreen

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b0c0
PTR_ptr_FUN_020835bc_overlay_3_0212b0c0: ; 0x0212B0C0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_13CLineParticle_overlay_3_0212b100
	.word _ZTI14CPrimitiveQUAD

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b0cc
PTR_ptr_FUN_020835bc_overlay_3_0212b0cc: ; 0x0212B0CC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21COPDCaptureDiscScreen13CSpark_overlay_3_0212b264
	.word PTR_ptr_FUN_02083578_overlay_3_0212b094

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b0d8
PTR_ptr_FUN_020835bc_overlay_3_0212b0d8: ; 0x0212B0D8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21COPDCaptureDiscScreen21CLineP_overlay_3_0212b344
	.word PTR_ptr_FUN_02083578_overlay_3_0212b07c

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b0e4
PTR_ptr_FUN_020835bc_overlay_3_0212b0e4: ; 0x0212B0E4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_N21COPDCaptureDiscScreen14CSpark_overlay_3_0212b2bc
	.word PTR_ptr_FUN_02083578_overlay_3_0212b084

    .global s_10CSparkLine_overlay_3_0212b0f0
s_10CSparkLine_overlay_3_0212b0f0: ; 0x0212B0F0
	.asciz "10CSparkLine"

    .global DAT_overlay_3_0212B0FD
DAT_overlay_3_0212B0FD:
	.byte 0x00, 0x00, 0x00

    .global s_13CLineParticle_overlay_3_0212b100
s_13CLineParticle_overlay_3_0212b100: ; 0x0212B100
	.asciz "13CLineParticle"

    .global DAT_overlay_3_0212B110
DAT_overlay_3_0212B110:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b0d8

    .global PTR_LAB_overlay_3_02127344_overlay_3_0212b118
PTR_LAB_overlay_3_02127344_overlay_3_0212b118: ; 0x0212B118
	.word _ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD1Ev

    .global ptr_FUN_overlay_3_02129088_overlay_3_0212b11c
ptr_FUN_overlay_3_02129088_overlay_3_0212b11c: ; 0x0212B11C
	.word _ZN21COPDCaptureDiscScreen21CLineParticleAnimatorD0Ev

    .global ptr_FUN_overlay_3_02128e30_overlay_3_0212b120
ptr_FUN_overlay_3_02128e30_overlay_3_0212b120: ; 0x0212B120
	.word _ZN21COPDCaptureDiscScreen21CLineParticleAnimator5ApplyEP14TFieldParticleI13CLineParticleEi
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_1_0212b0a8_overlay_3_0212b128
ptr_FUN_overlay_1_0212b0a8_overlay_3_0212b128: ; 0x0212B128
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b0a8

    .global PTR_LAB_overlay_3_021272b4_overlay_3_0212b12c
PTR_LAB_overlay_3_021272b4_overlay_3_0212b12c: ; 0x0212B12C
	.word _ZN10CSparkLineD1Ev

    .global ptr_FUN_overlay_3_021290e0_overlay_3_0212b130
ptr_FUN_overlay_3_021290e0_overlay_3_0212b130: ; 0x0212B130
	.word _ZN10CSparkLineD0Ev

    .global ptr_FUN_02003a2c_overlay_3_0212b134
ptr_FUN_02003a2c_overlay_3_0212b134: ; 0x0212B134
	.word _ZN14CPrimitiveLINE6RenderEP8Camera2D
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212b0c0_overlay_3_0212b13c
ptr_FUN_overlay_11_0212b0c0_overlay_3_0212b13c: ; 0x0212B13C
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b0c0

    .global PTR_LAB_overlay_3_02127318_overlay_3_0212b140
PTR_LAB_overlay_3_02127318_overlay_3_0212b140: ; 0x0212B140
	.word _ZN13CLineParticleD1Ev

    .global ptr_FUN_overlay_3_021290c4_overlay_3_0212b144
ptr_FUN_overlay_3_021290c4_overlay_3_0212b144: ; 0x0212B144
	.word _ZN13CLineParticleD0Ev

    .global ptr_FUN_020041e4_overlay_3_0212b148
ptr_FUN_020041e4_overlay_3_0212b148: ; 0x0212B148
	.word _ZN14CPrimitiveQUAD6RenderEP8Camera2D
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b0e4

    .global PTR_LAB_overlay_3_0212734c_overlay_3_0212b154
PTR_LAB_overlay_3_0212734c_overlay_3_0212b154: ; 0x0212B154
	.word _ZN21COPDCaptureDiscScreen14CSparkAnimatorD1Ev

    .global ptr_FUN_overlay_3_021290b0_overlay_3_0212b158
ptr_FUN_overlay_3_021290b0_overlay_3_0212b158: ; 0x0212B158
	.word _ZN21COPDCaptureDiscScreen14CSparkAnimatorD0Ev

    .global ptr_FUN_overlay_3_02129010_overlay_3_0212b15c
ptr_FUN_overlay_3_02129010_overlay_3_0212b15c: ; 0x0212B15C
	.word _ZN21COPDCaptureDiscScreen14CSparkAnimator5ApplyEP14TFieldParticleI10CSparkLineEi

    .global s_21COPDCaptureDiscScreen_overlay_3_0212b160
s_21COPDCaptureDiscScreen_overlay_3_0212b160: ; 0x0212B160
	.asciz "21COPDCaptureDiscScreen"

    .global DAT_overlay_3_0212B178
DAT_overlay_3_0212B178:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b0cc

    .global PTR_LAB_overlay_3_02127348_overlay_3_0212b180
PTR_LAB_overlay_3_02127348_overlay_3_0212b180: ; 0x0212B180
	.word _ZN21COPDCaptureDiscScreen13CSparkEmitterD1Ev

    .global ptr_FUN_overlay_3_0212909c_overlay_3_0212b184
ptr_FUN_overlay_3_0212909c_overlay_3_0212b184: ; 0x0212B184
	.word _ZN21COPDCaptureDiscScreen13CSparkEmitterD0Ev
	.word _ZN21COPDCaptureDiscScreen13CSparkEmitter5func2Ev

    .global ptr_FUN_overlay_11_02128e84_overlay_3_0212b18c
ptr_FUN_overlay_11_02128e84_overlay_3_0212b18c: ; 0x0212B18C
	.word _ZN21COPDCaptureDiscScreen13CSparkEmitter6UpdateEi

    .global ptr_FUN_overlay_3_02128f50_overlay_3_0212b190
ptr_FUN_overlay_3_02128f50_overlay_3_0212b190: ; 0x0212B190
	.word _ZN21COPDCaptureDiscScreen13CSparkEmitter4EmitEP14TFieldParticleI10CSparkLineE
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_02083578_overlay_3_0212b08c

    .global PTR_LAB_overlay_3_02129124_overlay_3_0212b19c
PTR_LAB_overlay_3_02129124_overlay_3_0212b19c: ; 0x0212B19C
	.word _ZN21TFieldParticleEmitterI13CLineParticleED1Ev

    .global ptr_FUN_overlay_3_02129110_overlay_3_0212b1a0
ptr_FUN_overlay_3_02129110_overlay_3_0212b1a0: ; 0x0212B1A0
	.word _ZN21TFieldParticleEmitterI13CLineParticleED0Ev
	.word _ZN21TFieldParticleEmitterI13CLineParticleE5func2Ev
	.word _ZN21TFieldParticleEmitterI13CLineParticleE6UpdateEi
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_02083578_overlay_3_0212b094

    .global PTR_LAB_overlay_3_02129128_overlay_3_0212b1b8
PTR_LAB_overlay_3_02129128_overlay_3_0212b1b8: ; 0x0212B1B8
	.word _ZN21TFieldParticleEmitterI10CSparkLineED1Ev

    .global ptr_FUN_overlay_3_021290fc_overlay_3_0212b1bc
ptr_FUN_overlay_3_021290fc_overlay_3_0212b1bc: ; 0x0212B1BC
	.word _ZN21TFieldParticleEmitterI10CSparkLineED0Ev
	.word _ZN21TFieldParticleEmitterI10CSparkLineE5func2Ev
	.word _ZN21TFieldParticleEmitterI10CSparkLineE6UpdateEi
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b09c

    .global PTR_LAB_overlay_3_02127340_overlay_3_0212b1d4
PTR_LAB_overlay_3_02127340_overlay_3_0212b1d4: ; 0x0212B1D4
	.word _ZN21COPDCaptureDiscScreen20CLineParticleEmitterD1Ev

    .global ptr_FUN_overlay_3_02129074_overlay_3_0212b1d8
ptr_FUN_overlay_3_02129074_overlay_3_0212b1d8: ; 0x0212B1D8
	.word _ZN21COPDCaptureDiscScreen20CLineParticleEmitterD0Ev
	.word _ZN21TFieldParticleEmitterI13CLineParticleE5func2Ev
	.word _ZN21COPDCaptureDiscScreen20CLineParticleEmitter6UpdateEi

    .global ptr_FUN_overlay_3_02128cb8_overlay_3_0212b1e4
ptr_FUN_overlay_3_02128cb8_overlay_3_0212b1e4: ; 0x0212B1E4
	.word _ZN21COPDCaptureDiscScreen20CLineParticleEmitter4EmitEP14TFieldParticleI13CLineParticleE

    .global s_21TFieldParticleEmitterI10CSpark_overlay_3_0212b1e8
s_21TFieldParticleEmitterI10CSpark_overlay_3_0212b1e8: ; 0x0212B1E8
	.asciz "21TFieldParticleEmitterI10CSparkLineE"

    .global DAT_overlay_3_0212B20E
DAT_overlay_3_0212B20E:
	.byte 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b0b4

    .global ptr_FUN_overlay_3_02127350_overlay_3_0212b218
ptr_FUN_overlay_3_02127350_overlay_3_0212b218: ; 0x0212B218
	.word _ZN21COPDCaptureDiscScreenD1Ev

    .global ptr_FUN_overlay_3_02127488_overlay_3_0212b21c
ptr_FUN_overlay_3_02127488_overlay_3_0212b21c: ; 0x0212B21C
	.word _ZN21COPDCaptureDiscScreenD0Ev

    .global ptr_FUN_overlay_3_021275c8_overlay_3_0212b220
ptr_FUN_overlay_3_021275c8_overlay_3_0212b220: ; 0x0212B220
	.word _ZN21COPDCaptureDiscScreen4InitEv

    .global ptr_FUN_overlay_3_02127660_overlay_3_0212b224
ptr_FUN_overlay_3_02127660_overlay_3_0212b224: ; 0x0212B224
	.word _ZN21COPDCaptureDiscScreen7ReleaseEv

    .global ptr_FUN_overlay_3_021276d8_overlay_3_0212b228
ptr_FUN_overlay_3_021276d8_overlay_3_0212b228: ; 0x0212B228
	.word _ZN21COPDCaptureDiscScreen5StartEP11COPDTexture

    .global ptr_FUN_overlay_3_02127ee8_overlay_3_0212b22c
ptr_FUN_overlay_3_02127ee8_overlay_3_0212b22c: ; 0x0212B22C
	.word _ZN21COPDCaptureDiscScreen4StopEv

    .global ptr_FUN_overlay_3_02127f04_overlay_3_0212b230
ptr_FUN_overlay_3_02127f04_overlay_3_0212b230: ; 0x0212B230
	.word _ZN21COPDCaptureDiscScreen6UpdateEv

    .global ptr_FUN_overlay_3_021289c4_overlay_3_0212b234
ptr_FUN_overlay_3_021289c4_overlay_3_0212b234: ; 0x0212B234
	.word _ZN21COPDCaptureDiscScreen6RenderEP8Camera2Di

    .global s_24TFieldParticleForceFieldI10CSp_overlay_3_0212b238
s_24TFieldParticleForceFieldI10CSp_overlay_3_0212b238: ; 0x0212B238
	.asciz "24TFieldParticleForceFieldI10CSparkLineE"

    .global DAT_overlay_3_0212B261
DAT_overlay_3_0212B261:
	.byte 0x00, 0x00, 0x00

    .global s_N21COPDCaptureDiscScreen13CSpark_overlay_3_0212b264
s_N21COPDCaptureDiscScreen13CSpark_overlay_3_0212b264: ; 0x0212B264
	.asciz "N21COPDCaptureDiscScreen13CSparkEmitterE"

    .global DAT_overlay_3_0212B28D
DAT_overlay_3_0212B28D:
	.byte 0x00, 0x00, 0x00

    .global s_21TFieldParticleEmitterI13CLineP_overlay_3_0212b290
s_21TFieldParticleEmitterI13CLineP_overlay_3_0212b290: ; 0x0212B290
	.asciz "21TFieldParticleEmitterI13CLineParticleE"

    .global DAT_overlay_3_0212B2B9
DAT_overlay_3_0212B2B9:
	.byte 0x00, 0x00, 0x00

    .global s_N21COPDCaptureDiscScreen14CSpark_overlay_3_0212b2bc
s_N21COPDCaptureDiscScreen14CSpark_overlay_3_0212b2bc: ; 0x0212B2BC
	.asciz "N21COPDCaptureDiscScreen14CSparkAnimatorE"

    .global DAT_overlay_3_0212B2E6
DAT_overlay_3_0212B2E6:
	.byte 0x00, 0x00

    .global s_24TFieldParticleForceFieldI13CLi_overlay_3_0212b2e8
s_24TFieldParticleForceFieldI13CLi_overlay_3_0212b2e8: ; 0x0212B2E8
	.asciz "24TFieldParticleForceFieldI13CLineParticleE"

    .global s_N21COPDCaptureDiscScreen20CLineP_overlay_3_0212b314
s_N21COPDCaptureDiscScreen20CLineP_overlay_3_0212b314: ; 0x0212B314
	.asciz "N21COPDCaptureDiscScreen20CLineParticleEmitterE"

    .global s_N21COPDCaptureDiscScreen21CLineP_overlay_3_0212b344
s_N21COPDCaptureDiscScreen21CLineP_overlay_3_0212b344: ; 0x0212B344
	.asciz "N21COPDCaptureDiscScreen21CLineParticleAnimatorE"

    .global DAT_overlay_3_0212B375
DAT_overlay_3_0212B375:
	.byte 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b378
DAT_overlay_3_0212b378: ; 0x0212B378
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b37c
DAT_overlay_3_0212b37c: ; 0x0212B37C
	.byte 0x00, 0x00, 0xF9, 0xFF

    .global DAT_overlay_3_0212b380
DAT_overlay_3_0212b380: ; 0x0212B380
	.byte 0x00, 0x80, 0x00, 0x00

    .global DAT_overlay_3_0212b384
DAT_overlay_3_0212b384: ; 0x0212B384
	.byte 0x00, 0x80, 0x00, 0x00

    .global DAT_overlay_3_0212b388
DAT_overlay_3_0212b388: ; 0x0212B388
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b38c
DAT_overlay_3_0212b38c: ; 0x0212B38C
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b390
DAT_overlay_3_0212b390: ; 0x0212B390
	.byte 0x00, 0x00, 0x04, 0x00

    .global DAT_overlay_3_0212b394
DAT_overlay_3_0212b394: ; 0x0212B394
	.byte 0x00, 0x00, 0x04, 0x00

    .global DAT_overlay_3_0212b398
DAT_overlay_3_0212b398: ; 0x0212B398
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b39c
DAT_overlay_3_0212b39c: ; 0x0212B39C
	.byte 0x02, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b3a0
DAT_overlay_3_0212b3a0: ; 0x0212B3A0
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b3a4
DAT_overlay_3_0212b3a4: ; 0x0212B3A4
	.byte 0x00, 0x00, 0x06, 0x00

    .global DAT_overlay_3_0212b3a8
DAT_overlay_3_0212b3a8: ; 0x0212B3A8
	.byte 0x00, 0x00, 0x10, 0x00

    .global DAT_overlay_3_0212b3ac
DAT_overlay_3_0212b3ac: ; 0x0212B3AC
	.byte 0x00, 0x00, 0x01, 0x00

    .global DAT_overlay_3_0212b3b0
DAT_overlay_3_0212b3b0: ; 0x0212B3B0
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b3b4
DAT_overlay_3_0212b3b4: ; 0x0212B3B4
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b3b8
DAT_overlay_3_0212b3b8: ; 0x0212B3B8
	.byte 0x00, 0x00, 0x10, 0x00

    .global DAT_overlay_3_0212b3bc
DAT_overlay_3_0212b3bc: ; 0x0212B3BC
	.byte 0x00, 0x00, 0x01, 0x00

    .global DAT_overlay_3_0212b3c0
DAT_overlay_3_0212b3c0: ; 0x0212B3C0
	.byte 0x09, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212b3c4
DAT_overlay_3_0212b3c4: ; 0x0212B3C4
	.byte 0x00, 0x00, 0x00, 0x00

    .global s_OPD_overlay_3_0212b3c8
s_OPD_overlay_3_0212b3c8: ; 0x0212B3C8
	.asciz "OPD"

    .global s_data_interface_i019_LZ_bin_overlay_3_0212b3cc
s_data_interface_i019_LZ_bin_overlay_3_0212b3cc: ; 0x0212B3CC
	.asciz "data/interface/i019_LZ.bin"

    .global DAT_overlay_3_0212B3E7
DAT_overlay_3_0212B3E7:
	.byte 0x00

    .global s_OPD_i019_00_NCBR_overlay_3_0212b3e8
s_OPD_i019_00_NCBR_overlay_3_0212b3e8: ; 0x0212B3E8
	.asciz "OPD:i019_00.NCBR"

    .global DAT_overlay_3_0212B3F9
DAT_overlay_3_0212B3F9:
	.byte 0x00, 0x00, 0x00

    .global s_OPD_i019_NCLR_overlay_3_0212b3fc
s_OPD_i019_NCLR_overlay_3_0212b3fc: ; 0x0212B3FC
	.asciz "OPD:i019.NCLR"

    .global DAT_overlay_3_0212B40A
DAT_overlay_3_0212B40A:
	.byte 0x00, 0x00

    .global s_OPD_i019_00_NCER_overlay_3_0212b40c
s_OPD_i019_00_NCER_overlay_3_0212b40c: ; 0x0212B40C
	.asciz "OPD:i019_00.NCER"

    .global DAT_overlay_3_0212B41D
DAT_overlay_3_0212B41D:
	.byte 0x00, 0x00, 0x00

    .global s_OPD_i019_00_cac_overlay_3_0212b420
s_OPD_i019_00_cac_overlay_3_0212b420: ; 0x0212B420
	.asciz "OPD:i019_00.cac"

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b430
PTR_ptr_FUN_020835bc_overlay_3_0212b430: ; 0x0212B430
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_15COPDCaptureLine_overlay_3_0212b43c
	.word _ZTI10CPrimitive

    .global s_15COPDCaptureLine_overlay_3_0212b43c
s_15COPDCaptureLine_overlay_3_0212b43c: ; 0x0212B43C
	.asciz "15COPDCaptureLine"

    .global DAT_overlay_3_0212B44E
DAT_overlay_3_0212B44E:
	.byte 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b430

    .global ptr_FUN_overlay_3_02129130_overlay_3_0212b458
ptr_FUN_overlay_3_02129130_overlay_3_0212b458: ; 0x0212B458
	.word ov3_02129130

    .global ptr_FUN_overlay_3_02129160_overlay_3_0212b45c
ptr_FUN_overlay_3_02129160_overlay_3_0212b45c: ; 0x0212B45C
	.word ov3_02129160

    .global ptr_FUN_overlay_3_021296c4_overlay_3_0212b460
ptr_FUN_overlay_3_021296c4_overlay_3_0212b460: ; 0x0212B460
	.word ov3_021296C4

    .global s_OPD_overlay_3_0212b464
s_OPD_overlay_3_0212b464: ; 0x0212B464
	.asciz "OPD"

    .global s_data_interface_i001_LZ_bin_overlay_3_0212b468
s_data_interface_i001_LZ_bin_overlay_3_0212b468: ; 0x0212B468
	.asciz "data/interface/i001_LZ.bin"

    .global DAT_overlay_3_0212B483
DAT_overlay_3_0212B483:
	.byte 0x00

    .global s_OPD_i001_00_NCBR_overlay_3_0212b484
s_OPD_i001_00_NCBR_overlay_3_0212b484: ; 0x0212B484
	.asciz "OPD:i001_00.NCBR"

    .global DAT_overlay_3_0212B495
DAT_overlay_3_0212B495:
	.byte 0x00, 0x00, 0x00

    .global s_OPD_i001_NCLR_overlay_3_0212b498
s_OPD_i001_NCLR_overlay_3_0212b498: ; 0x0212B498
	.asciz "OPD:i001.NCLR"

    .global DAT_overlay_3_0212B4A6
DAT_overlay_3_0212B4A6:
	.byte 0x00, 0x00

    .global s_OPD_i001_00_NCER_overlay_3_0212b4a8
s_OPD_i001_00_NCER_overlay_3_0212b4a8: ; 0x0212B4A8
	.asciz "OPD:i001_00.NCER"

    .global DAT_overlay_3_0212B4B9
DAT_overlay_3_0212B4B9:
	.byte 0x00, 0x00, 0x00

    .global s_OPD_i001_00_cac_overlay_3_0212b4bc
s_OPD_i001_00_cac_overlay_3_0212b4bc: ; 0x0212B4BC
	.asciz "OPD:i001_00.cac"

    .global PTR_ptr_FUN_020835bc_overlay_3_0212b4cc
PTR_ptr_FUN_020835bc_overlay_3_0212b4cc: ; 0x0212B4CC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17COPDScreenMeshNTF_overlay_3_0212b4ec
	.word _ZTI10CPrimitive
	.global _ZTV17COPDScreenMeshNTF
_ZTV17COPDScreenMeshNTF:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b4cc

    .global ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0
ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0: ; 0x0212B4E0
	.word _ZN17COPDScreenMeshNTFD1Ev

    .global ptr_FUN_overlay_3_02129a90_overlay_3_0212b4e4
ptr_FUN_overlay_3_02129a90_overlay_3_0212b4e4: ; 0x0212B4E4
	.word ov3_02129A90

    .global ptr_FUN_overlay_3_02129c90_overlay_3_0212b4e8
ptr_FUN_overlay_3_02129c90_overlay_3_0212b4e8: ; 0x0212B4E8
	.word ov3_02129C90

    .global s_17COPDScreenMeshNTF_overlay_3_0212b4ec
s_17COPDScreenMeshNTF_overlay_3_0212b4ec: ; 0x0212B4EC
    .asciz "17COPDScreenMeshNTF"

    .bss

	.global OVERLAY3_BSS_0212B504
OVERLAY3_BSS_0212B504: ; 0x0212B504
    .space 0x1C
