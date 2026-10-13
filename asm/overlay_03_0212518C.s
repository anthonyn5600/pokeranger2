    .include "macros.inc"
    .include "include/overlay_03_0212518C.inc"

    .text

	arm_func_start ov3_0212518C
ov3_0212518C: ; 0x0212518C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _021251D4 ; =_ZTV17CPrimitiveRectNTF+8
	mov r2, #0
	str r0, [r4]
	ldr r0, _021251D8 ; =_ZTV16CSimpleSpriteNTF+8
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
_021251D4: .word _ZTV17CPrimitiveRectNTF+8
_021251D8: .word _ZTV16CSimpleSpriteNTF+8
	arm_func_end ov3_0212518C

	arm_func_start _ZN15COPDTitleScreenC1Ev
_ZN15COPDTitleScreenC1Ev: ; 0x021251DC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02125500 ; =ptr_FUN_overlay_3_021255b8_overlay_3_0212aee8
	mov r4, r0
	ldr ip, _02125504 ; =_ZN16CSimpleSpriteNTFD1Ev
	str r1, [r4]
	ldr r3, _02125508 ; =ov3_0212518C
	add r0, r4, #0xc
	mov r1, #7
	mov r2, #0x5c
	str ip, [sp]
	bl __cxa_vec_ctor
	add r0, r4, #0x290
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _0212550C ; =ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0
	add r0, r4, #0x2b8
	str r1, [r4, #0x290]
	mov r1, #0
	str r1, [r4, #0x2a8]
	bl ov3_02129E98
	mov r0, #0x1000
	str r0, [r4, #0x524]
	mov r0, #1
	str r0, [r4, #0x530]
	mov r1, #0
	str r1, [r4, #0x534]
	str r1, [r4, #0x538]
	mov r0, #0x40
	str r0, [r4, #0x540]
	str r1, [r4, #0x544]
	ldr r0, [r4, #0x540]
	cmp r0, #0
	beq _021252F0
	ldr r1, _02125510 ; =ov3_02125594
	ldr r3, _02125514 ; =ov3_0212552C
	str r1, [sp]
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x53c]
	ldr r1, [r4, #0x540]
	mov r5, #0
	mov r0, r5
	cmp r1, #0
	bls _021252E4
	mov r1, r5
	mov lr, r5
	mov r2, #0x84
	arm_func_end _ZN15COPDTitleScreenC1Ev
_02125298:
	ldr r3, [r4, #0x53c]
	add ip, r0, #1
	add r3, r3, r1
	str r5, [r3, #0x7c]
	ldr r3, [r4, #0x540]
	add r0, r0, #1
	cmp ip, r3
	ldrlo r3, [r4, #0x53c]
	mlalo r5, ip, r2, r3
	ldr r3, [r4, #0x53c]
	movhs r5, lr
	add r3, r3, r1
	str r5, [r3, #0x80]
	ldr ip, [r4, #0x53c]
	ldr r3, [r4, #0x540]
	add r5, ip, r1
	cmp r0, r3
	add r1, r1, #0x84
	blo _02125298
_021252E4:
	ldr r0, [r4, #0x53c]
	str r0, [r4, #0x548]
	b _021252F8
_021252F0:
	str r1, [r4, #0x53c]
	str r1, [r4, #0x548]
_021252F8:
	mov r1, #0
	str r1, [r4, #0x54c]
	ldr r0, [r4, #0x530]
	cmp r0, #0
	streq r1, [r4, #0x528]
	streq r1, [r4, #0x52c]
	beq _02125340
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x528]
	ldr r1, [r4, #0x530]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x530]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x52c]
_02125340:
	mov r1, #0
	str r1, [r4, #0x520]
	str r1, [r4, #0x51c]
	mov r0, #0x1000
	str r0, [r4, #0x558]
	mov r0, #1
	str r0, [r4, #0x564]
	str r1, [r4, #0x568]
	str r1, [r4, #0x56c]
	mov r0, #0x10
	str r0, [r4, #0x574]
	str r1, [r4, #0x578]
	ldr r0, [r4, #0x574]
	cmp r0, #0
	beq _02125410
	ldr r1, _02125510 ; =ov3_02125594
	ldr r3, _02125514 ; =ov3_0212552C
	str r1, [sp]
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #0x570]
	ldr r1, [r4, #0x574]
	mov r5, #0
	mov r0, r5
	cmp r1, #0
	bls _02125404
	mov r1, r5
	mov lr, r5
	mov r2, #0x84
_021253B8:
	ldr r3, [r4, #0x570]
	add ip, r0, #1
	add r3, r3, r1
	str r5, [r3, #0x7c]
	ldr r3, [r4, #0x574]
	add r0, r0, #1
	cmp ip, r3
	ldrlo r3, [r4, #0x570]
	mlalo r5, ip, r2, r3
	ldr r3, [r4, #0x570]
	movhs r5, lr
	add r3, r3, r1
	str r5, [r3, #0x80]
	ldr ip, [r4, #0x570]
	ldr r3, [r4, #0x574]
	add r5, ip, r1
	cmp r0, r3
	add r1, r1, #0x84
	blo _021253B8
_02125404:
	ldr r0, [r4, #0x570]
	str r0, [r4, #0x57c]
	b _02125418
_02125410:
	str r1, [r4, #0x570]
	str r1, [r4, #0x57c]
_02125418:
	mov r1, #0
	str r1, [r4, #0x580]
	ldr r0, [r4, #0x564]
	cmp r0, #0
	streq r1, [r4, #0x55c]
	streq r1, [r4, #0x560]
	beq _02125460
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x55c]
	ldr r1, [r4, #0x564]
	mov r2, r1, lsl #2
	mov r1, #0
	bl MI_CpuFill8
	ldr r0, [r4, #0x564]
	mov r0, r0, lsl #2
	bl _Znam
	str r0, [r4, #0x560]
_02125460:
	mov ip, #0
	str ip, [r4, #0x554]
	str ip, [r4, #0x550]
	mov r0, #0xa
	str r0, [r4, #0x584]
	ldr r3, _02125518 ; =PTR_LAB_overlay_3_02126e94_overlay_3_0212ae04
	mov r2, #0x1000
	str r3, [r4, #0x588]
	str ip, [r4, #0x59c]
	str ip, [r4, #0x58c]
	str ip, [r4, #0x590]
	str ip, [r4, #0x594]
	ldr r1, _0212551C ; =PTR_LAB_overlay_3_021255a8_overlay_3_0212ae3c
	str r2, [r4, #0x598]
	str r1, [r4, #0x588]
	add r0, r4, #0x184
	add r1, r0, #0x400
	str ip, [r4, #0x5a0]
	ldr r0, _02125520 ; =PTR_LAB_overlay_3_021255ac_overlay_3_0212addc
	str r1, [r4, #0x5a4]
	str r0, [r4, #0x5a8]
	str r3, [r4, #0x5ac]
	str ip, [r4, #0x5c0]
	str ip, [r4, #0x5b0]
	str ip, [r4, #0x5b4]
	str ip, [r4, #0x5b8]
	ldr r0, _02125524 ; =PTR_LAB_overlay_3_021255b0_overlay_3_0212ae20
	str r2, [r4, #0x5bc]
	str r0, [r4, #0x5ac]
	str ip, [r4, #0x5c4]
	ldr r0, _02125528 ; =PTR_LAB_overlay_3_021255b4_overlay_3_0212adf0
	str r1, [r4, #0x5c8]
	str r0, [r4, #0x5cc]
	strb ip, [r4, #0x5d0]
	strb ip, [r4, #0x612]
	strb ip, [r4, #0x613]
	str ip, [r4, #4]
	mov r0, r4
	str ip, [r4, #8]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02125500: .word ptr_FUN_overlay_3_021255b8_overlay_3_0212aee8
_02125504: .word _ZN16CSimpleSpriteNTFD1Ev
_02125508: .word ov3_0212518C
_0212550C: .word ptr_FUN_overlay_3_02129a68_overlay_3_0212b4e0
_02125510: .word ov3_02125594
_02125514: .word ov3_0212552C
_02125518: .word PTR_LAB_overlay_3_02126e94_overlay_3_0212ae04
_0212551C: .word PTR_LAB_overlay_3_021255a8_overlay_3_0212ae3c
_02125520: .word PTR_LAB_overlay_3_021255ac_overlay_3_0212addc
_02125524: .word PTR_LAB_overlay_3_021255b0_overlay_3_0212ae20
_02125528: .word PTR_LAB_overlay_3_021255b4_overlay_3_0212adf0

	arm_func_start ov3_0212552C
ov3_0212552C: ; 0x0212552C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _02125588 ; =_ZTV17CPrimitiveRectNTF+8
	mov r1, #0
	str r0, [r4]
	ldr r0, _0212558C ; =_ZTV16CSimpleSpriteNTF+8
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
	ldr r1, _02125590 ; =0x00000622
	mov r0, r4
	str r1, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02125588: .word _ZTV17CPrimitiveRectNTF+8
_0212558C: .word _ZTV16CSimpleSpriteNTF+8
_02125590: .word 0x00000622
	arm_func_end ov3_0212552C

	arm_func_start ov3_02125594
ov3_02125594: ; 0x02125594
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_02125594

	arm_func_start ov3_021255A8
ov3_021255A8: ; 0x021255A8
	bx lr
	arm_func_end ov3_021255A8

	arm_func_start ov3_021255AC
ov3_021255AC: ; 0x021255AC
	bx lr
	arm_func_end ov3_021255AC

	arm_func_start ov3_021255B0
ov3_021255B0: ; 0x021255B0
	bx lr
	arm_func_end ov3_021255B0

	arm_func_start ov3_021255B4
ov3_021255B4: ; 0x021255B4
	bx lr
	arm_func_end ov3_021255B4

	arm_func_start _ZN15COPDTitleScreenD1Ev
_ZN15COPDTitleScreenD1Ev: ; 0x021255B8
	stmdb sp!, {r4, lr}
	ldr r1, _021256B8 ; =ptr_FUN_overlay_3_021255b8_overlay_3_0212aee8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	ldr r0, [r4, #0x560]
	cmp r0, #0
	beq _021255FC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x560]
	arm_func_end _ZN15COPDTitleScreenD1Ev
_021255FC:
	ldr r0, [r4, #0x55c]
	cmp r0, #0
	beq _02125614
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x55c]
_02125614:
	ldr r0, [r4, #0x570]
	cmp r0, #0
	beq _02125638
	ldr r3, _021256BC ; =ov3_02125594
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x570]
_02125638:
	ldr r0, [r4, #0x52c]
	cmp r0, #0
	beq _02125650
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x52c]
_02125650:
	ldr r0, [r4, #0x528]
	cmp r0, #0
	beq _02125668
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x528]
_02125668:
	ldr r0, [r4, #0x53c]
	cmp r0, #0
	beq _0212568C
	ldr r3, _021256BC ; =ov3_02125594
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x53c]
_0212568C:
	add r0, r4, #0x2b8
	bl ov3_02129F54
	add r0, r4, #0x290
	bl ov3_02129A68
	ldr r3, _021256C0 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0xc
	mov r1, #7
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021256B8: .word ptr_FUN_overlay_3_021255b8_overlay_3_0212aee8
_021256BC: .word ov3_02125594
_021256C0: .word _ZN16CSimpleSpriteNTFD1Ev

	arm_func_start ov3_021256C4
ov3_021256C4: ; 0x021256C4
	stmdb sp!, {r4, lr}
	ldr r1, _021257CC ; =ptr_FUN_overlay_3_021255b8_overlay_3_0212aee8
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	ldr r0, [r4, #0x560]
	cmp r0, #0
	beq _02125708
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x560]
	arm_func_end ov3_021256C4
_02125708:
	ldr r0, [r4, #0x55c]
	cmp r0, #0
	beq _02125720
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x55c]
_02125720:
	ldr r0, [r4, #0x570]
	cmp r0, #0
	beq _02125744
	ldr r3, _021257D0 ; =ov3_02125594
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x570]
_02125744:
	ldr r0, [r4, #0x52c]
	cmp r0, #0
	beq _0212575C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x52c]
_0212575C:
	ldr r0, [r4, #0x528]
	cmp r0, #0
	beq _02125774
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x528]
_02125774:
	ldr r0, [r4, #0x53c]
	cmp r0, #0
	beq _02125798
	ldr r3, _021257D0 ; =ov3_02125594
	mov r1, #0x84
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x53c]
_02125798:
	add r0, r4, #0x2b8
	bl ov3_02129F54
	add r0, r4, #0x290
	bl ov3_02129A68
	ldr r3, _021257D4 ; =_ZN16CSimpleSpriteNTFD1Ev
	add r0, r4, #0xc
	mov r1, #7
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_021257CC: .word ptr_FUN_overlay_3_021255b8_overlay_3_0212aee8
_021257D0: .word ov3_02125594
_021257D4: .word _ZN16CSimpleSpriteNTFD1Ev

	arm_func_start ov3_021257D8
ov3_021257D8: ; 0x021257D8
	stmdb sp!, {lr}
	sub sp, sp, #0x14
	mov r1, #0xc0000
	rsb r1, r1, #0
	str r1, [sp]
	mov r2, #0
	str r2, [sp, #4]
	mov ip, #0xc0000
	mov r1, #4
	str r2, [sp, #8]
	mov r2, #0x100000
	str r2, [sp, #0xc]
	mov r2, r1
	add r0, r0, #0x290
	sub r3, ip, #0x140000
	str ip, [sp, #0x10]
	bl ov3_02129AC0
	add sp, sp, #0x14
	ldmia sp!, {pc}
	arm_func_end ov3_021257D8

	arm_func_start ov3_02125824
ov3_02125824: ; 0x02125824
	ldr ip, _02125830 ; =ov3_02129C54
	add r0, r0, #0x290
	bx ip
	.align 2, 0
_02125830: .word ov3_02129C54
	arm_func_end ov3_02125824

	arm_func_start ov3_02125834
ov3_02125834: ; 0x02125834
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x28
	str r0, [sp, #4]
	mov r5, r1
	bl _ZN5CGame11GetInstanceEv
	str r0, [sp, #0x14]
	mov r4, #0
	ldr r0, _02125C84 ; =0x0000089F
	ldr r2, _02125C88 ; =0x00007FFF
	mov r1, #0x1f
	mov r3, #0x3f
	str r4, [sp]
	bl G3X_SetClearColor
	ldr r1, _02125C8C ; =DAT_overlay_3_0212af64
	ldr r2, [sp, #4]
	mov r0, r4
	mov r3, #0x2c
	arm_func_end ov3_02125834
_02125878:
	ldr r6, [r1, #0x20]
	add r0, r0, #1
	cmp r6, #0
	mlage r4, r6, r3, r5
	strge r4, [r2, #0x24]
	ldr r8, [r1, #0x1c]
	ldr r7, [r1, #0x18]
	ldr r6, [r1, #0x14]
	ldr r4, [r1, #0x10]
	cmp r0, #7
	str r4, [r2, #0x38]
	str r6, [r2, #0x3c]
	str r7, [r2, #0x40]
	str r8, [r2, #0x44]
	ldr r4, [r1]
	str r4, [r2, #0x48]
	ldr r4, [r1, #4]
	str r4, [r2, #0x4c]
	ldr r4, [r1, #8]
	str r4, [r2, #0x58]
	ldr r4, [r1, #0xc]
	str r4, [r2, #0x5c]
	ldr r4, [r1, #0x24]
	add r1, r1, #0x28
	str r4, [r2, #0x10]
	add r2, r2, #0x5c
	blt _02125878
	ldr r0, [sp, #4]
	add r1, r5, #0x84
	str r1, [r0, #0x2a8]
	mov r1, #0x5a
	str r1, [r0, #0x294]
	mov r2, #1
	str r2, [r0, #0x230]
	mov r4, #2
	str r4, [r0, #0x1c]
	mov r1, #3
	str r1, [r0, #0x78]
	str r1, [r0, #0xd4]
	ldr r3, [sp, #4]
	mov r0, #4
	str r0, [r3, #0x130]
	str r4, [r3, #0x12c]
	add r3, r3, #0x100
	mov r6, #0
	strh r6, [r3, #0x28]
	ldr r3, [sp, #4]
	mov r4, #5
	str r6, [r3, #0x134]
	str r4, [r3, #0x18c]
	str r6, [r3, #0x244]
	str r2, [r3, #0x28c]
	str r1, [r3, #0x240]
	ldr r1, [sp, #4]
	mov r3, #8
	str r3, [r1, #0x248]
	ldr r3, _02125C90 ; =DAT_overlay_3_0212af64
	str r2, [r1, #0x2a0]
	mov r4, #0x2c
	ldr r3, [r3, #0xc0]
	sub r1, r4, #0x30
	mla r2, r3, r4, r5
	ldr r6, [r2, #0xc]
	bl _Z23Heap_AllocWithAlignmentmm
	mov r4, r0
	mov r0, #0
	strh r0, [r4]
	bl GX_BeginLoadTexPltt
	mov r0, r4
	mov r1, #4
	bl DC_FlushRange
	mov r1, r6
	mov r0, r4
	mov r2, #4
	bl GX_LoadTexPltt
	bl GX_EndLoadTexPltt
	mov r0, r4
	bl _Z9Heap_FreePv
	ldr r0, _02125C94 ; =DAT_overlay_3_0212a680
	ldmia r0, {r1, r4}
	ldr r0, [sp, #4]
	str r1, [sp, #0x20]
	str r1, [r0, #0x58c]
	str r4, [r0, #0x590]
	ldr r0, [r0, #0x530]
	str r4, [sp, #0x24]
	cmp r0, #0
	bls _021259F0
	ldr r0, [sp, #4]
	ldr r1, [r0, #0x528]
	cmp r1, #0
	addne r0, r0, #0x188
	addne r0, r0, #0x400
	strne r0, [r1]
_021259F0:
	ldr r0, [sp, #4]
	add r0, r0, #0x1a8
	add r2, r0, #0x400
	ldr r0, [sp, #4]
	str r2, [r0, #0x538]
	add r2, r5, #0xb0
	add r1, r0, #0x188
	str r2, [r0, #0x534]
	add r0, r1, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #4]
	str r1, [r0, #0x5b0]
	str r4, [r0, #0x5b4]
	ldr r0, [r0, #0x564]
	cmp r0, #0
	bls _02125A54
	ldr r0, [sp, #4]
	ldr r1, [r0, #0x55c]
	cmp r1, #0
	addne r0, r0, #0x1ac
	addne r0, r0, #0x400
	strne r0, [r1]
_02125A54:
	ldr r0, [sp, #4]
	add r0, r0, #0x1cc
	add r2, r0, #0x400
	ldr r0, [sp, #4]
	str r2, [r0, #0x56c]
	add r2, r5, #0x210
	add r1, r0, #0x1ac
	str r2, [r0, #0x568]
	add r0, r1, #0x400
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, #0x40000
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [sp, #0x10]
	rsb r0, r0, #0
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0xc]
_02125AA8:
	ldr r0, [sp, #0x14]
	mov r8, #0x90000
	add r0, r0, #0x48
	rsb r8, r8, #0
	add sl, r0, #0x1400
	mov sb, #0
_02125AC0:
	mov r4, #0
	mov r4, r4, lsl #9
	str r4, [sp, #0x18]
	mov r4, #0
	mov r4, r4, lsl #2
	ldmia sl, {r3, fp, lr}
	str r4, [sp, #0x1c]
	umull r5, r4, lr, r3
	ldr r7, [sl, #0x10]
	mov r0, #0
	mov r2, r0, lsl #0x10
	ldr r0, [sp, #8]
	mla r4, lr, fp, r4
	add r1, r0, sb, lsl #4
	ldr ip, [sl, #0xc]
	ldr r6, [sl, #0x14]
	adds r5, r7, r5
	mla r4, ip, r3, r4
	adc r3, r6, r4
	str r5, [sl]
	add r0, r1, #0x400
	str r3, [sl, #4]
	orr r2, r2, r3, lsr #16
	strh r2, [r0, #0x94]
	ldr r3, [sl]
	ldmib sl, {r2, r5}
	umull r7, r6, r5, r3
	mla r6, r5, r2, r6
	ldr r4, [sl, #0xc]
	ldr ip, [sl, #0x10]
	mla r6, r4, r3, r6
	ldr fp, [sl, #0x14]
	adds r2, ip, r7
	adc r3, fp, r6
	stmia sl, {r2, r3}
	ldr r2, [sp, #0x18]
	add sb, sb, #1
	orr r2, r2, r3, lsr #23
	str r2, [sp, #0x18]
	add r2, r2, #0x100
	strh r2, [r0, #0x96]
	ldr r2, [sl]
	ldmib sl, {r0, r4}
	umull r6, r5, r4, r2
	mla r5, r4, r0, r5
	ldr r3, [sl, #0xc]
	ldr fp, [sl, #0x10]
	mla r5, r3, r2, r5
	ldr r7, [sl, #0x14]
	adds r0, fp, r6
	adc r2, r7, r5
	stmia sl, {r0, r2}
	ldr r0, [sp, #0x1c]
	cmp sb, #3
	orr r0, r0, r2, lsr #30
	str r0, [sp, #0x1c]
	add r0, r0, #2
	mov r0, r0, lsl #0xc
	str r0, [r1, #0x498]
	ldr r0, [sp, #0x10]
	str r0, [r1, #0x48c]
	str r8, [r1, #0x490]
	add r8, r8, #0x30000
	blt _02125AC0
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #3
	ldr r0, [sp, #0x10]
	add r0, r0, #0x40000
	str r0, [sp, #0x10]
	ldr r0, [sp, #8]
	add r0, r0, #0x30
	str r0, [sp, #8]
	blt _02125AA8
	ldr r0, [sp, #4]
	mov r2, #0
	mov r1, r0
	strb r2, [r1, #0x5d0]
	bl ov3_02125CB0
	ldr r0, [sp, #4]
	mov r2, #0
	str r2, [r0, #8]
	str r2, [r0, #4]
	ldrb r0, [r0, #0x613]
	cmp r0, #0
	beq _02125C34
	ldr r0, [sp, #0x14]
	mov r1, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	b _02125C4C
_02125C34:
	ldr r0, [sp, #0x14]
	mov r1, #0x200
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r2, #0x40
	bl _ZN17UnkClass_0203447812sub_02034D54Eii
_02125C4C:
	ldr r0, [sp, #0x14]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [sp, #0x14]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02125C84: .word 0x0000089F
_02125C88: .word 0x00007FFF
_02125C8C: .word DAT_overlay_3_0212af64
_02125C90: .word DAT_overlay_3_0212af64
_02125C94: .word DAT_overlay_3_0212a680

	arm_func_start ov3_02125C98
ov3_02125C98: ; 0x02125C98
	mov r1, #0x1000
	str r1, [r0, #0x18]
	bx lr
	arm_func_end ov3_02125C98

	arm_func_start ov3_02125CA4
ov3_02125CA4: ; 0x02125CA4
	mov r1, #0x1000
	str r1, [r0, #0x18]
	bx lr
	arm_func_end ov3_02125CA4

	arm_func_start ov3_02125CB0
ov3_02125CB0: ; 0x02125CB0
	stmdb sp!, {r3, lr}
	mov ip, #0
	arm_func_end ov3_02125CB0
_02125CB8:
	rsb r3, ip, #0x1f
	add r1, r0, ip, lsl #1
	orr r2, r3, r3, lsl #5
	add ip, ip, #1
	orr r2, r2, r3, lsl #10
	add r1, r1, #0x500
	strh r2, [r1, #0xd2]
	cmp ip, #0x20
	blt _02125CB8
	add r0, r0, #0xd2
	add r0, r0, #0x500
	bl G3X_SetToonTable
	ldr r2, _02125D04 ; =0x04000060
	ldr r0, _02125D08 ; =0xFFFFCFFD
	ldrh r1, [r2]
	and r0, r1, r0
	orr r0, r0, #2
	strh r0, [r2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02125D04: .word 0x04000060
_02125D08: .word 0xFFFFCFFD

	arm_func_start ov3_02125D0C
ov3_02125D0C: ; 0x02125D0C
	bx lr
	arm_func_end ov3_02125D0C

	arm_func_start ov3_02125D10
ov3_02125D10: ; 0x02125D10
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x20
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	mov r5, r0
	ldrb r0, [r4, #0x613]
	ldr r2, [r5, #0x14]
	ldr r1, [r5, #0x18]
	cmp r0, #0
	bne _02125DA0
	ldr r0, [r4, #8]
	cmp r0, #1
	bgt _02125DA0
	ldrh r0, [r2, #2]
	and r0, r0, #1
	mov r0, r0, lsl #0x10
	movs r0, r0, lsr #0x10
	ldreqb r0, [r1, #4]
	cmpeq r0, #0
	beq _02125DA0
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xfa
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r1, #2
	mov r2, #0x3c
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r1, #2
	mov r2, #0x3c
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #2
	str r0, [r4, #8]
	arm_func_end ov3_02125D10
_02125DA0:
	ldr r0, [r4, #8]
	cmp r0, #4
	addls pc, pc, r0, lsl #2
	b _02125F0C
_02125DB0: ; jump table
	b _02125DC4 ; case 0
	b _02125E14 ; case 1
	b _02125EDC ; case 2
	b _02125E84 ; case 3
	b _02125EC0 ; case 4
_02125DC4:
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02125F0C
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02125F0C
	mov r0, #1
	str r0, [r4, #8]
	ldrb r0, [r4, #0x613]
	cmp r0, #0
	movne r0, #0x258
	ldreq r0, _021264CC ; =0x00000CA8
	str r0, [r4, #4]
	mov r0, #0x40
	strb r0, [r4, #0x612]
	b _02125F0C
_02125E14:
	ldr r0, [r4, #4]
	subs r0, r0, #1
	str r0, [r4, #4]
	bpl _02125F0C
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r1, #4
	mov r2, #0x3c
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r1, #4
	mov r2, #0x3c
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldrb r0, [r4, #0x613]
	mov r1, #0x3c
	cmp r0, #0
	add r0, r5, #0x1000
	ldr r0, [r0, #0x48c]
	beq _02125E74
	bl _ZN17UnkClass_0203447812sub_02034B58Ei
	mov r0, #2
	str r0, [r4, #8]
	b _02125F0C
_02125E74:
	bl _ZN17UnkClass_0203447812sub_02034DC8Ei
	mov r0, #3
	str r0, [r4, #8]
	b _02125F0C
_02125E84:
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02125F0C
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02125F0C
	mov r0, #0x3c
	str r0, [r4, #4]
	mov r0, #4
	str r0, [r4, #8]
	b _02125F0C
_02125EC0:
	ldr r0, [r4, #4]
	subs r0, r0, #1
	str r0, [r4, #4]
	bpl _02125F0C
	add sp, sp, #0x20
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_02125EDC:
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02125F0C
	add r0, r5, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #0x20
	mvneq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_02125F0C:
	add r0, r4, #0x2b8
	bl ov3_02129F78
	ldr r5, [r4, #0x544]
	ldr r8, [r4, #0x524]
	cmp r5, #0
	beq _02126044
	mov sb, #0
	mov r7, r8, asr #0x1f
	mov sl, sb
_02125F30:
	ldr r0, [r5, #0x70]
	ldr r6, [r5, #0x80]
	cmp r0, #0
	beq _02125FF4
	ldr r0, [r4, #0x538]
	cmp r0, #0
	beq _02125F60
	ldr r3, [r0]
	mov r1, r5
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_02125F60:
	ldr r0, [r5, #0x70]
	cmp r0, #0
	ble _02126038
	ldr lr, [r5, #0x64]
	ldr r0, [r5, #0x68]
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
	ldr r0, [r5, #0x5c]
	str r2, [sp, #0x1c]
	add r0, r0, r3
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	str r2, [sp, #0x14]
	add r0, r0, r2
	str r0, [r5, #0x60]
	ldrsh r0, [r5, #0x6e]
	ldrsh r2, [r5, #0x6c]
	str r3, [sp, #0x18]
	mul r1, r0, r8
	add r0, r2, r1, asr #12
	strh r0, [r5, #0x6c]
	ldr r0, [r5, #0x70]
	str r3, [sp, #0x10]
	subs r0, r0, r8
	str r0, [r5, #0x70]
	strmi sl, [r5, #0x70]
	b _02126038
_02125FF4:
	cmp r5, #0
	beq _02126038
	cmp r6, #0
	ldrne r0, [r5, #0x7c]
	strne r0, [r6, #0x7c]
	ldr r1, [r5, #0x7c]
	ldr r0, [r5, #0x80]
	cmp r1, #0
	strne r0, [r1, #0x80]
	streq r0, [r4, #0x544]
	ldr r0, [r4, #0x548]
	str r0, [r5, #0x80]
	str sb, [r5, #0x7c]
	ldr r0, [r4, #0x548]
	cmp r0, #0
	strne r5, [r0, #0x7c]
	str r5, [r4, #0x548]
_02126038:
	mov r5, r6
	cmp r6, #0
	bne _02125F30
_02126044:
	ldr r0, [r4, #0x530]
	mov r6, #0
	mov r5, r6
	cmp r0, #0
	bls _021260A8
	mov r7, r6
_0212605C:
	ldr r0, [r4, #0x528]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [r4, #0x52c]
	streq r7, [r0, r5, lsl #2]
	beq _02126098
	ldr r2, [r0]
	mov r1, r8
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [r4, #0x52c]
	str r0, [r1, r5, lsl #2]
	ldr r0, [r4, #0x52c]
	ldr r0, [r0, r5, lsl #2]
	add r6, r6, r0
_02126098:
	ldr r0, [r4, #0x530]
	add r5, r5, #1
	cmp r5, r0
	blo _0212605C
_021260A8:
	cmp r6, #0
	beq _02126198
	cmp r0, #0
	mov sl, #0
	bls _02126198
_021260BC:
	ldr r0, [r4, #0x528]
	ldr r0, [r0, sl, lsl #2]
	cmp r0, #0
	ldrne r0, [r4, #0x52c]
	ldrne r0, [r0, sl, lsl #2]
	cmpne r0, #0
	beq _02126188
	cmp r0, #0
	mov sb, #0
	bls _02126188
	mov r5, sb
	mov r6, sb
_021260EC:
	ldr r1, [r4, #0x548]
	mov r7, r6
	cmp r1, #0
	beq _0212612C
	ldr r0, [r1, #0x80]
	mov r7, r1
	str r0, [r4, #0x548]
	cmp r0, #0
	strne r6, [r0, #0x7c]
	ldr r0, [r4, #0x544]
	str r0, [r1, #0x80]
	str r5, [r1, #0x7c]
	ldr r0, [r4, #0x544]
	cmp r0, #0
	strne r1, [r0, #0x7c]
	str r1, [r4, #0x544]
_0212612C:
	cmp r7, #0
	beq _02126174
	ldr r0, [r4, #0x534]
	mov r1, r7
	str r0, [r7, #0x18]
	ldr r0, [r4, #0x528]
	ldr r0, [r0, sl, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [r4, #0x538]
	cmp r0, #0
	beq _02126174
	ldr r3, [r0]
	mov r1, r7
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_02126174:
	ldr r0, [r4, #0x52c]
	add sb, sb, #1
	ldr r0, [r0, sl, lsl #2]
	cmp sb, r0
	blo _021260EC
_02126188:
	ldr r0, [r4, #0x530]
	add sl, sl, #1
	cmp sl, r0
	blo _021260BC
_02126198:
	ldr r5, [r4, #0x578]
	ldr r8, [r4, #0x558]
	cmp r5, #0
	beq _021262C8
	mov sb, #0
	mov r7, r8, asr #0x1f
	mov sl, sb
_021261B4:
	ldr r0, [r5, #0x70]
	ldr r6, [r5, #0x80]
	cmp r0, #0
	beq _02126278
	ldr r0, [r4, #0x56c]
	cmp r0, #0
	beq _021261E4
	ldr r3, [r0]
	mov r1, r5
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_021261E4:
	ldr r0, [r5, #0x70]
	cmp r0, #0
	ble _021262BC
	ldr lr, [r5, #0x64]
	ldr r0, [r5, #0x68]
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
	ldr r0, [r5, #0x5c]
	str r2, [sp, #0xc]
	add r0, r0, r3
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	str r2, [sp, #4]
	add r0, r0, r2
	str r0, [r5, #0x60]
	ldrsh r0, [r5, #0x6e]
	ldrsh r2, [r5, #0x6c]
	str r3, [sp, #8]
	mul r1, r0, r8
	add r0, r2, r1, asr #12
	strh r0, [r5, #0x6c]
	ldr r0, [r5, #0x70]
	str r3, [sp]
	subs r0, r0, r8
	str r0, [r5, #0x70]
	strmi sl, [r5, #0x70]
	b _021262BC
_02126278:
	cmp r5, #0
	beq _021262BC
	cmp r6, #0
	ldrne r0, [r5, #0x7c]
	strne r0, [r6, #0x7c]
	ldr r1, [r5, #0x7c]
	ldr r0, [r5, #0x80]
	cmp r1, #0
	strne r0, [r1, #0x80]
	streq r0, [r4, #0x578]
	ldr r0, [r4, #0x57c]
	str r0, [r5, #0x80]
	str sb, [r5, #0x7c]
	ldr r0, [r4, #0x57c]
	cmp r0, #0
	strne r5, [r0, #0x7c]
	str r5, [r4, #0x57c]
_021262BC:
	mov r5, r6
	cmp r6, #0
	bne _021261B4
_021262C8:
	ldr r0, [r4, #0x564]
	mov r6, #0
	mov r5, r6
	cmp r0, #0
	bls _0212632C
	mov r7, r6
_021262E0:
	ldr r0, [r4, #0x55c]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldreq r0, [r4, #0x560]
	streq r7, [r0, r5, lsl #2]
	beq _0212631C
	ldr r2, [r0]
	mov r1, r8
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [r4, #0x560]
	str r0, [r1, r5, lsl #2]
	ldr r0, [r4, #0x560]
	ldr r0, [r0, r5, lsl #2]
	add r6, r6, r0
_0212631C:
	ldr r0, [r4, #0x564]
	add r5, r5, #1
	cmp r5, r0
	blo _021262E0
_0212632C:
	cmp r6, #0
	beq _0212641C
	cmp r0, #0
	mov sl, #0
	bls _0212641C
_02126340:
	ldr r0, [r4, #0x55c]
	ldr r0, [r0, sl, lsl #2]
	cmp r0, #0
	ldrne r0, [r4, #0x560]
	ldrne r0, [r0, sl, lsl #2]
	cmpne r0, #0
	beq _0212640C
	cmp r0, #0
	mov sb, #0
	bls _0212640C
	mov r5, sb
	mov r6, sb
_02126370:
	ldr r1, [r4, #0x57c]
	mov r7, r6
	cmp r1, #0
	beq _021263B0
	ldr r0, [r1, #0x80]
	mov r7, r1
	str r0, [r4, #0x57c]
	cmp r0, #0
	strne r6, [r0, #0x7c]
	ldr r0, [r4, #0x578]
	str r0, [r1, #0x80]
	str r5, [r1, #0x7c]
	ldr r0, [r4, #0x578]
	cmp r0, #0
	strne r1, [r0, #0x7c]
	str r1, [r4, #0x578]
_021263B0:
	cmp r7, #0
	beq _021263F8
	ldr r0, [r4, #0x568]
	mov r1, r7
	str r0, [r7, #0x18]
	ldr r0, [r4, #0x55c]
	ldr r0, [r0, sl, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, [r4, #0x56c]
	cmp r0, #0
	beq _021263F8
	ldr r3, [r0]
	mov r1, r7
	ldr r3, [r3, #8]
	mov r2, r8
	blx r3
_021263F8:
	ldr r0, [r4, #0x560]
	add sb, sb, #1
	ldr r0, [r0, sl, lsl #2]
	cmp sb, r0
	blo _02126370
_0212640C:
	ldr r0, [r4, #0x564]
	add sl, sl, #1
	cmp sl, r0
	blo _02126340
_0212641C:
	mov r5, #0
	mov r7, r4
	mov r3, r5
_02126428:
	mov r6, r3
_0212642C:
	add r0, r7, r6, lsl #4
	add r0, r0, #0x400
	ldrh r2, [r0, #0x94]
	ldrh r1, [r0, #0x96]
	add r6, r6, #1
	cmp r6, #3
	add r1, r2, r1
	strh r1, [r0, #0x94]
	blt _0212642C
	add r5, r5, #1
	cmp r5, #3
	add r7, r7, #0x30
	blt _02126428
	ldrb r0, [r4, #0x613]
	cmp r0, #0
	ldreqb r0, [r4, #0x5d0]
	addeq r0, r0, #1
	streqb r0, [r4, #0x5d0]
	ldrb r0, [r4, #0x612]
	cmp r0, #0
	beq _021264C0
	sub r1, r0, #1
	and r0, r1, #0xff
	strb r1, [r4, #0x612]
	cmp r0, #0x20
	blo _021264B0
	sub r0, r0, #0x20
	rsb r0, r0, #0x1f
	mov r0, r0, lsl #0x18
	movs r0, r0, asr #0x18
	movmi r0, #0
	str r0, [r4, #0x134]
	b _021264C0
_021264B0:
	rsb r0, r0, #0x1f
	and r1, r0, #0xff
	add r0, r4, #0x100
	strh r1, [r0, #0x28]
_021264C0:
	mov r0, #1
	add sp, sp, #0x20
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_021264CC: .word 0x00000CA8

	arm_func_start ov3_021264D0
ov3_021264D0: ; 0x021264D0
	mov r0, #0
	bx lr
	arm_func_end ov3_021264D0

	arm_func_start ov3_021264D8
ov3_021264D8: ; 0x021264D8
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xc
	mov r4, r0
	ldr r5, [r4, #0x544]
	str r1, [sp]
	str r2, [sp, #4]
	cmp r5, #0
	beq _0212654C
	arm_func_end ov3_021264D8
_021264F8:
	ldr r0, [r4, #0x54c]
	cmp r0, #0
	strlt r0, [r5, #4]
	ldr r2, [r5, #0x5c]
	ldr r1, [r4, #0x51c]
	mov r0, r5
	add r1, r2, r1
	str r1, [r5, #0x3c]
	ldr r3, [r5, #0x60]
	ldr r2, [r4, #0x520]
	ldr r1, [sp]
	add r2, r3, r2
	str r2, [r5, #0x40]
	ldrsh r2, [r5, #0x6c]
	strh r2, [r5, #0x54]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r5, [r5, #0x80]
	cmp r5, #0
	bne _021264F8
_0212654C:
	ldr r5, [r4, #0x578]
	cmp r5, #0
	beq _021265AC
_02126558:
	ldr r0, [r4, #0x580]
	cmp r0, #0
	strlt r0, [r5, #4]
	ldr r2, [r5, #0x5c]
	ldr r1, [r4, #0x550]
	mov r0, r5
	add r1, r2, r1
	str r1, [r5, #0x3c]
	ldr r3, [r5, #0x60]
	ldr r2, [r4, #0x554]
	ldr r1, [sp]
	add r2, r3, r2
	str r2, [r5, #0x40]
	ldrsh r2, [r5, #0x6c]
	strh r2, [r5, #0x54]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r5, [r5, #0x80]
	cmp r5, #0
	bne _02126558
_021265AC:
	mov r0, #0
	str r0, [sp, #8]
_021265B4:
	add r0, r4, #0x8c
	add r2, r0, #0x400
	ldr r0, [sp, #8]
	mov r1, #0x30
	mla sl, r0, r1, r2
	add r0, r0, #1
	mov r0, r0, lsl #0x10
	mov r8, r0, lsr #0x10
	ldr fp, _02126744 ; =FX_SinCosTable_
	mov sb, #0
	add r0, r4, #0x200
_021265E0:
	add r5, sl, sb, lsl #4
	ldrh r1, [r5, #8]
	ldrh r6, [r0, #0xb4]
	add r3, sb, #1
	mov r1, r1, asr #4
	mov r2, r1, lsl #1
	add r1, fp, r2, lsl #1
	mov r2, r2, lsl #1
	ldrsh r2, [fp, r2]
	mov r3, r3, lsl #0x10
	add r6, r6, #1
	ldrsh r1, [r1, #2]
	mov r7, sb, lsl #4
	mov sb, r3, lsr #0x10
	mul ip, sb, r6
	ldr r3, [sl, r7]
	cmp sb, #3
	ldr r7, [r5, #0xc]
	ldr r6, [r5, #4]
	smull r5, lr, r7, r2
	smull r2, r1, r7, r1
	mov r5, r5, lsr #0xc
	orr r5, r5, lr, lsl #20
	add r5, r6, r5
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	add r1, r3, r2
	ldr r2, [r4, #0x2ac]
	add r2, r2, ip, lsl #3
	str r1, [r2, r8, lsl #3]
	add r1, r2, r8, lsl #3
	str r5, [r1, #4]
	blo _021265E0
	ldr r0, [sp, #8]
	add r0, r0, #1
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	str r0, [sp, #8]
	cmp r0, #3
	blo _021265B4
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _021266FC
	add r0, r4, #0x290
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
	add r0, r4, #0xc
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
	add r0, r4, #0x68
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
	add r0, r4, #0x234
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
	ldr r1, [sp]
	add r0, r4, #0x2b8
	bl ov3_02129FE0
	add r0, r4, #0x120
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
_021266FC:
	ldrb r0, [r4, #0x613]
	cmp r0, #0
	bne _02126728
	ldrb r0, [r4, #0x5d0]
	tst r0, #0x20
	bne _02126728
	add r0, r4, #0x17c
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
_02126728:
	add r0, r4, #0x1d8
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02126744: .word FX_SinCosTable_

	arm_func_start ov3_02126748
ov3_02126748: ; 0x02126748
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	ldr r0, [r4, #0x18]
	mov r6, r1
	cmp r0, #0
	mov r5, #0
	ble _0212680C
	bl _ZN5CGame11GetInstanceEv
	ldr r1, [r4, #0x18]
	sub r1, r1, r6
	str r1, [r4, #0x18]
	cmp r1, #0
	bgt _0212680C
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
	mov r2, #0x19
	umull r2, r3, r5, r2
	str r5, [r1, #4]
	add r2, r3, #5
	mov r1, r2, lsl #0xc
	str r1, [r4, #0x18]
	add r5, r0, #1
	arm_func_end ov3_02126748
_0212680C:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov3_02126814
ov3_02126814: ; 0x02126814
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	str r0, [sp]
	mov r5, r1
	bl _ZN5CGame11GetInstanceEv
	ldr r1, [sp]
	mov r4, r0
	ldmib r1, {r2, r3}
	str r2, [r5, #0x5c]
	mov r1, #0x12c000
	str r3, [r5, #0x60]
	str r1, [r5, #0x70]
	str r1, [r5, #0x74]
	bl _ZN5CGame11GetInstanceEv
	add r2, r0, #0x1000
	add r1, r0, #0x48
	add r1, r1, #0x1400
	ldr r6, [r2, #0x448]
	ldmib r1, {r0, r7}
	umull sb, r8, r7, r6
	mla r8, r7, r0, r8
	ldr r0, [r1, #0xc]
	ldr sl, [r1, #0x10]
	mla r8, r0, r6, r8
	ldr r7, [r1, #0x14]
	adds sb, sl, sb
	add r3, r4, #0x48
	adc r0, r7, r8
	str sb, [r2, #0x448]
	str r0, [r1, #4]
	add sl, r3, #0x1400
	add r1, r4, #0x1000
	mov r6, #0
	str r1, [sp, #4]
	ldr r3, [r1, #0x448]
	mov r1, r6, lsl #0x10
	orr r1, r1, r0, lsr #16
	mov r0, r1, lsl #0x10
	mov r1, r0, lsr #0x10
	mov r0, r1, asr #4
	mov r6, r0, lsl #1
	add r0, r6, #1
	add fp, r1, #0x4000
	mov r1, r0, lsl #1
	mov r0, r6, lsl #1
	ldr r6, _02126A1C ; =FX_SinCosTable_
	ldmib sl, {r2, lr}
	ldrsh r1, [r6, r1]
	ldrsh r0, [r6, r0]
	umull r7, r6, lr, r3
	mla r6, lr, r2, r6
	ldr ip, [sl, #0xc]
	ldr sb, [sl, #0x10]
	mla r6, ip, r3, r6
	ldr r8, [sl, #0x14]
	adds r3, sb, r7
	ldr r2, [sp, #4]
	adc r6, r8, r6
	str r3, [r2, #0x448]
	mov r2, #0x3000
	umull r2, r3, r6, r2
	str r6, [sl, #4]
	add r6, r3, #0x3000
	smull r3, r2, r6, r1
	smull r1, r0, r6, r0
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	str r3, [r5, #0x64]
	str r1, [r5, #0x68]
	strh fp, [r5, #0x6c]
	mov r0, #0x50
	str r0, [r5, #4]
	ldr r0, [sp]
	ldr r1, [r0, #0x1c]
	ldr r2, [r1]
	add r0, r2, #1
	str r0, [r1]
	cmp r0, #0x40
	movge r0, #0xa
	strge r0, [r1]
	str r2, [r5, #0x10]
	add r2, r4, #0x1000
	add r0, r4, #0x48
	add r0, r0, #0x1400
	ldr r3, [r2, #0x448]
	ldmib r0, {r1, r4}
	umull r7, r6, r4, r3
	mla r6, r4, r1, r6
	ldr r1, [r0, #0xc]
	ldr r8, [r0, #0x10]
	mla r6, r1, r3, r6
	ldr r4, [r0, #0x14]
	adds r7, r8, r7
	adc r4, r4, r6
	mov r1, #0xb
	umull r1, r3, r4, r1
	str r7, [r2, #0x448]
	str r4, [r0, #4]
	add r1, r3, #7
	str r1, [r5, #0x14]
	mov r1, #0
	str r1, [r5, #0x2c]
	str r1, [r5, #0x30]
	mov r1, #0x20000
	str r1, [r5, #0x34]
	mov r1, #0x40000
	str r1, [r5, #0x38]
	mov r1, #0x4000
	str r1, [r5, #0x4c]
	ldr r3, [r2, #0x448]
	ldmib r0, {r1, r4}
	umull r7, r6, r4, r3
	mla r6, r4, r1, r6
	ldr r1, [r0, #0xc]
	ldr r8, [r0, #0x10]
	mla r6, r1, r3, r6
	ldr r4, [r0, #0x14]
	adds r7, r8, r7
	adc r3, r4, r6
	str r7, [r2, #0x448]
	mov r1, #0x60
	umull r1, r2, r3, r1
	add r1, r2, #0x20
	str r3, [r0, #4]
	mov r0, r1, lsl #0xc
	str r0, [r5, #0x50]
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02126A1C: .word FX_SinCosTable_
	arm_func_end ov3_02126814

	arm_func_start ov3_02126A20
ov3_02126A20: ; 0x02126A20
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x5c]
	add r1, r1, #0x60000
	bl _Z12sub_02007254ll
	sub r5, r0, #0x32000
	mov r0, #0x41
	umull r2, r1, r5, r0
	mov lr, r5, asr #0x1f
	mov r3, lr, lsl #4
	mov ip, r5, lsl #4
	mla r1, lr, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	add r0, r0, #0x1000
	orr r3, r3, r5, lsr #28
	mov r1, ip, lsr #0xc
	orr r1, r1, r3, lsl #20
	str r0, [r4, #0x44]
	add r3, r1, #0x1000
	str r3, [r4, #0x48]
	ldr r1, [r4, #0x50]
	ldr r0, [r4, #0x64]
	mov r1, r1, asr #1
	smull r2, r1, r3, r1
	mov r3, r2, lsr #0xc
	cmp r0, #0
	orr r3, r3, r1, lsl #20
	mov r2, #0
	bge _02126AB4
	ldr r1, [r4, #0x5c]
	sub r0, r2, #0x80000
	add r1, r3, r1
	cmp r1, r0
	movlt r2, #1
	b _02126AC4
	arm_func_end ov3_02126A20
_02126AB4:
	ldr r0, [r4, #0x5c]
	sub r0, r0, r3
	cmp r0, #0x80000
	movgt r2, #1
_02126AC4:
	cmp r2, #0
	bne _02126B04
	ldr r0, [r4, #0x68]
	cmp r0, #0
	bge _02126AF4
	ldr r1, [r4, #0x60]
	mov r0, #0xc0000
	add r1, r3, r1
	rsb r0, r0, #0
	cmp r1, r0
	movlt r2, #1
	b _02126B04
_02126AF4:
	ldr r0, [r4, #0x60]
	sub r0, r0, r3
	cmp r0, #0xc0000
	movgt r2, #1
_02126B04:
	cmp r2, #0
	movne r0, #0
	strne r0, [r4, #0x70]
	strne r0, [r4, #0x74]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov3_02126B18
ov3_02126B18: ; 0x02126B18
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	ldr r0, [r4, #0x18]
	mov r6, r1
	cmp r0, #0
	mov r5, #0
	ble _02126BDC
	bl _ZN5CGame11GetInstanceEv
	ldr r1, [r4, #0x18]
	sub r1, r1, r6
	str r1, [r4, #0x18]
	cmp r1, #0
	bgt _02126BDC
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
	mov r0, r0, lsl #1
	ldr r7, [r2, #0x448]
	ldr r3, [r1, #8]
	ldr r6, [r1, #0x10]
	umull lr, ip, r3, r7
	mla ip, r3, r5, ip
	ldr r3, [r1, #0xc]
	orr r0, r0, r5, lsr #31
	mla ip, r3, r7, ip
	ldr r5, [r1, #0x14]
	adds r3, r6, lr
	str r3, [r2, #0x448]
	adc r5, r5, ip
	mov r2, #0x14
	umull r2, r3, r5, r2
	str r5, [r1, #4]
	add r2, r3, #0xa
	mov r1, r2, lsl #0xc
	str r1, [r4, #0x18]
	add r5, r0, #1
	arm_func_end ov3_02126B18
_02126BDC:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start ov3_02126BE4
ov3_02126BE4: ; 0x02126BE4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN5CGame11GetInstanceEv
	ldmib r5, {r2, r3}
	str r2, [r4, #0x5c]
	mov r1, #0x12c000
	str r3, [r4, #0x60]
	str r1, [r4, #0x70]
	mov r6, r0
	str r1, [r4, #0x74]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x48
	add r1, r1, #0x1400
	add r0, r0, #0x1000
	ldr r7, [r0, #0x448]
	ldmib r1, {r2, r8}
	umull ip, sb, r8, r7
	mla sb, r8, r2, sb
	ldr r2, [r1, #0xc]
	ldr lr, [r1, #0x10]
	mla sb, r2, r7, sb
	ldr r8, [r1, #0x14]
	adds ip, lr, ip
	str ip, [r0, #0x448]
	adc r2, r8, sb
	add r0, r6, #0x48
	str r2, [r1, #4]
	add r1, r0, #0x1400
	add r6, r6, #0x1000
	ldr r7, [r1, #8]
	ldr lr, [r6, #0x448]
	ldr ip, [r1, #4]
	umull r8, r0, r7, lr
	mov r3, #0
	mla r0, r7, ip, r0
	mov r7, r3, lsl #0x10
	orr r7, r7, r2, lsr #16
	mov r2, r7, lsl #0x10
	ldr r7, [r1, #0x10]
	mov r2, r2, lsr #0x10
	mov ip, r2, asr #4
	adds r8, r7, r8
	ldr r7, [r1, #0xc]
	ldr sb, [r1, #0x14]
	mla r0, r7, lr, r0
	mov r3, r3, lsl #0xd
	adc r0, sb, r0
	str r8, [r6, #0x448]
	mov ip, ip, lsl #1
	str r0, [r1, #4]
	orr r3, r3, r0, lsr #19
	add r1, ip, #1
	add r0, r3, #0x2000
	mov r3, ip, lsl #1
	ldr ip, _02126D58 ; =FX_SinCosTable_
	mov r6, r1, lsl #1
	ldrsh r6, [ip, r6]
	ldrsh r3, [ip, r3]
	add r2, r2, #0x4000
	smull lr, ip, r0, r6
	smull r6, r3, r0, r3
	mov r0, lr, lsr #0xc
	orr r0, r0, ip, lsl #20
	str r0, [r4, #0x64]
	mov r0, r6, lsr #0xc
	orr r0, r0, r3, lsl #20
	str r0, [r4, #0x68]
	mov r1, #0x51
	strh r2, [r4, #0x6c]
	str r1, [r4, #4]
	ldr r1, [r5, #0x1c]
	ldr r2, [r1]
	add r0, r2, #1
	str r0, [r1]
	cmp r0, #0x40
	movge r0, #0xa
	strge r0, [r1]
	ldr r0, _02126D5C ; =0x00000444
	str r2, [r4, #0x10]
	strh r0, [r4, #0x6e]
	mov r0, #0
	str r0, [r4, #0x2c]
	str r0, [r4, #0x30]
	mov r0, #0x20000
	str r0, [r4, #0x34]
	str r0, [r4, #0x38]
	str r0, [r4, #0x4c]
	str r0, [r4, #0x50]
	mov r0, #0x800
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02126D58: .word FX_SinCosTable_
_02126D5C: .word 0x00000444
	arm_func_end ov3_02126BE4

	arm_func_start ov3_02126D60
ov3_02126D60: ; 0x02126D60
	stmdb sp!, {r4, lr}
	mov r4, r1
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x5c]
	add r1, r1, #0x60000
	bl _Z12sub_02007254ll
	sub r1, r0, #0x32000
	mov r0, #0x18
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mla r2, r1, r0, r2
	mov r0, r3, lsr #0xc
	orr r0, r0, r2, lsl #20
	add r0, r0, #0x800
	str r0, [r4, #0x44]
	str r0, [r4, #0x48]
	ldr r0, [r4, #0x64]
	ldr r2, [r4, #0x50]
	cmp r0, #0
	mov r3, #0
	bge _02126DCC
	ldr r1, [r4, #0x5c]
	sub r0, r3, #0x80000
	add r1, r1, r2, asr #1
	cmp r1, r0
	movlt r3, #1
	b _02126DDC
	arm_func_end ov3_02126D60
_02126DCC:
	ldr r0, [r4, #0x5c]
	sub r0, r0, r2, asr #1
	cmp r0, #0x80000
	movgt r3, #1
_02126DDC:
	cmp r3, #0
	bne _02126E1C
	ldr r0, [r4, #0x68]
	cmp r0, #0
	bge _02126E0C
	ldr r1, [r4, #0x60]
	mov r0, #0xc0000
	add r1, r1, r2, asr #1
	rsb r0, r0, #0
	cmp r1, r0
	movlt r3, #1
	b _02126E1C
_02126E0C:
	ldr r0, [r4, #0x60]
	sub r0, r0, r2, asr #1
	cmp r0, #0xc0000
	movgt r3, #1
_02126E1C:
	cmp r3, #0
	movne r0, #0
	strne r0, [r4, #0x70]
	strne r0, [r4, #0x74]
	ldmia sp!, {r4, pc}

	arm_func_start ov3_02126E30
ov3_02126E30: ; 0x02126E30
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_02126E30

	arm_func_start ov3_02126E44
ov3_02126E44: ; 0x02126E44
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_02126E44

	arm_func_start ov3_02126E58
ov3_02126E58: ; 0x02126E58
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_02126E58

	arm_func_start ov3_02126E6C
ov3_02126E6C: ; 0x02126E6C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_02126E6C

	arm_func_start ov3_02126E80
ov3_02126E80: ; 0x02126E80
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov3_02126E80

	arm_func_start ov3_02126E94
ov3_02126E94: ; 0x02126E94
	bx lr
	arm_func_end ov3_02126E94

	arm_func_start ov3_02126E98
ov3_02126E98: ; 0x02126E98
	bx lr
	arm_func_end ov3_02126E98

    .rodata

    .global DAT_overlay_3_0212a680
DAT_overlay_3_0212a680: ; 0x0212A680
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_3_0212a684
DAT_overlay_3_0212a684: ; 0x0212A684
	.byte 0x00, 0x00, 0xFA, 0xFF
