    .include "macros.inc"
    .include "include/arm9_02007AA4.inc"

    .text

	arm_func_start sub_02007AA4
sub_02007AA4: ; 0x02007AA4
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	strb r1, [r4, #0x20]
	bl sub_02007B3C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02007AA4

	arm_func_start sub_02007AC0
sub_02007AC0: ; 0x02007AC0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov ip, #0
	mov r6, r1
	mov r5, r2
	mov r4, r3
	strb ip, [r7, #0x20]
	bl sub_02007B3C
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl sub_02007B60
	mov r0, r7
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end sub_02007AC0

	arm_func_start _ZN17UnkClass_02007AA4C1EP17NNSG2dPaletteData
_ZN17UnkClass_02007AA4C1EP17NNSG2dPaletteData: ; 0x02007AFC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r2, #0
	mov r4, r1
	strb r2, [r5, #0x20]
	bl sub_02007B3C
	mov r0, r5
	mov r1, r4
	bl sub_02007BAC
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_02007AA4C1EP17NNSG2dPaletteData

	arm_func_start sub_02007B28
sub_02007B28: ; 0x02007B28
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02007BC4
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02007B28

	arm_func_start sub_02007B3C
sub_02007B3C: ; 0x02007B3C
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	add r0, r4, #8
	str r1, [r4]
	bl NNS_G2dInitImagePaletteProxy
	mov r0, #0
	strb r0, [r4, #0x20]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02007B3C

	arm_func_start sub_02007B60
sub_02007B60: ; 0x02007B60
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r6, r1
	mov r5, r2
	mov r4, r3
	bl sub_02007BC4
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02007B9C
	mov r1, r6
	mov r3, r5
	mov r2, #0
	str r4, [sp]
	bl _ZN9CNCLRFileC1EPKcmmm
	arm_func_end sub_02007B60
_02007B9C:
	str r0, [r7]
	ldr r0, [r0, #0xb8]
	str r0, [r7, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02007BAC
sub_02007BAC: ; 0x02007BAC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl sub_02007BC4
	str r4, [r5, #4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_02007BAC

	arm_func_start sub_02007BC4
sub_02007BC4: ; 0x02007BC4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _02007BF0
	beq _02007BE8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02007BC4
_02007BE8:
	mov r0, #0
	str r0, [r4]
_02007BF0:
	mov r0, #0
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_02007AA412sub_02007BFCEm
_ZN17UnkClass_02007AA412sub_02007BFCEm: ; 0x02007BFC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #8
	mov r4, r1
	bl NNS_G2dInitImagePaletteProxy
	ldr r0, [r5, #4]
	mov r1, r4
	add r3, r5, #8
	mov r2, #0
	bl NNS_G2dLoadPalette
	str r4, [r5, #0x1c]
	mov r0, #1
	strb r0, [r5, #0x20]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_02007AA412sub_02007BFCEm

	arm_func_start sub_02007C34
sub_02007C34: ; 0x02007C34
	mov r2, r0
	str r1, [r2, #0x1c]
	mov r1, #0
	strb r1, [r2, #0x20]
	ldr r0, _02007C58 ; =_0208F304
	ldr ip, _02007C5C ; =_ZN5CGame12sub_020100E4EPFvPvES0_
	ldr r0, [r0]
	ldr r1, _02007C60 ; =sub_02007C64
	bx ip
	.align 2, 0
_02007C58: .word s_game
_02007C5C: .word _ZN5CGame12sub_020100E4EPFvPvES0_
_02007C60: .word sub_02007C64
	arm_func_end sub_02007C34

	arm_func_start sub_02007C64
sub_02007C64: ; 0x02007C64
	stmdb sp!, {r4, lr}
	movs r4, r0
	ldmeqia sp!, {r4, pc}
	add r0, r4, #8
	bl NNS_G2dInitImagePaletteProxy
	ldr r0, [r4, #4]
	ldr r1, [r4, #0x1c]
	add r3, r4, #8
	mov r2, #0
	bl NNS_G2dLoadPalette
	mov r0, #1
	strb r0, [r4, #0x20]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02007C64
