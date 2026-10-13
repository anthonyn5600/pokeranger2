    .include "macros.inc"
    .include "include/overlay_01_0213F9D0.inc"

    .text

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

    .section .sinit,4 ; 0x02140734

    .data

    .bss

	.global OVERLAY1_BSS_02142204
OVERLAY1_BSS_02142204: ; 0x02142204
    .space 0x1C
