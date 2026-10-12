    .include "macros.inc"
    .include "include/arm9_02046D5C.inc"

    .text

	arm_func_start CRYPTO_RC4FastInit
CRYPTO_RC4FastInit: ; 0x02046D5C
	stmdb sp!, {r4, r5, r6, lr}
	mov r3, #0
	str r3, [r0]
	cmp r2, #0x10
	str r3, [r0, #4]
	movhi r2, #0x10
	add r0, r0, #8
	arm_func_end CRYPTO_RC4FastInit
_02046D78:
	str r3, [r0, r3, lsl #2]
	add r3, r3, #1
	cmp r3, #0x100
	blt _02046D78
	mov r5, #0
	mov r6, r5
	mov lr, r5
	mov ip, r5
_02046D98:
	ldrb r3, [r1, r6]
	ldr r4, [r0, lr, lsl #2]
	add r6, r6, #1
	add r3, r4, r3
	add r3, r5, r3
	and r5, r3, #0xff
	ldr r3, [r0, r5, lsl #2]
	cmp r6, r2
	str r3, [r0, lr, lsl #2]
	add lr, lr, #1
	moveq r6, ip
	str r4, [r0, r5, lsl #2]
	cmp lr, #0x100
	blt _02046D98
	mov r2, #0
_02046DD4:
	ldr r1, [r0, r2, lsl #2]
	mov r1, r1, lsl #0x18
	str r1, [r0, r2, lsl #2]
	add r2, r2, #1
	cmp r2, #0x100
	blt _02046DD4
	ldmia sp!, {r4, r5, r6, lr}
	bx lr

	arm_func_start CRYPTO_RC4Init
CRYPTO_RC4Init: ; 0x02046DF4
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #4
	mov r3, #0
	strb r3, [r0]
	cmp r2, #0x10
	strb r3, [r0, #1]
	movhi r2, #0x10
	add r0, r0, #4
	arm_func_end CRYPTO_RC4Init
_02046E14:
	strb r3, [r0, r3]
	add r3, r3, #1
	cmp r3, #0x100
	blt _02046E14
	mov r6, #0
	mov r7, r6
	mov r4, r6
	mov r3, r6
	and ip, r2, #0xff
_02046E38:
	ldrb r5, [r0, r4]
	ldrb lr, [r1, r7]
	add r2, r7, #1
	and r7, r2, #0xff
	add r2, r5, lr
	add r2, r6, r2
	and r6, r2, #0xff
	ldrb r2, [r0, r6]
	add lr, r0, r4
	add r4, r4, #1
	strb r2, [lr]
	cmp r7, ip
	moveq r7, r3
	cmp r4, #0x100
	strb r5, [r0, r6]
	blt _02046E38
	add sp, sp, #4
	ldmia sp!, {r4, r5, r6, r7, lr}
	bx lr

	arm_func_start CRYPTO_RC4FastEncrypt
CRYPTO_RC4FastEncrypt: ; 0x02046E84
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	ldr r7, [r0]
	ldr r6, [r0, #4]
	add r0, r0, #8
	mov lr, #0x1000000
	add r7, r7, lr
	subs r2, r2, #8
	ldr sb, [r0, r7, lsr #22]
	bmi _02047010
	arm_func_end CRYPTO_RC4FastEncrypt
_02046EA8:
	add r6, r6, sb
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	add r6, r6, sb
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	add r6, r6, sb
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	add r6, r6, sb
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	add r6, r6, sb
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	add r6, r6, sb
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	add r6, r6, sb
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	add r6, r6, sb
	subs r2, r2, #8
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	bpl _02046EA8
_02047010:
	adds r2, r2, #8
	ble _0204704C
_02047018:
	add r6, r6, sb
	subs r2, r2, #1
	ldr r8, [r0, r6, lsr #22]
	ldrb r5, [r1], #1
	str r8, [r0, r7, lsr #22]
	str sb, [r0, r6, lsr #22]
	add r4, sb, r8
	add r7, r7, lr
	ldr r4, [r0, r4, lsr #22]
	ldr sb, [r0, r7, lsr #22]
	eor r5, r5, r4, lsr #24
	strb r5, [r3], #1
	bgt _02047018
_0204704C:
	sub r7, r7, lr
	and r7, r7, #0xff000000
	str r6, [r0, #-4]
	str r7, [r0, #-8]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

	arm_func_start CRYPTO_RC4Encrypt
CRYPTO_RC4Encrypt: ; 0x02047060
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	ldrb r7, [r0]
	ldrb r6, [r0, #1]
	add r0, r0, #4
	mov lr, #0x1000000
	add r7, lr, r7, lsl #24
	mov r6, r6, lsl #0x18
	ldrb sb, [r0, r7, lsr #24]
	subs r2, r2, #1
	bmi _020470C0
	arm_func_end CRYPTO_RC4Encrypt
_02047088:
	add r6, r6, sb, lsl #24
	subs r2, r2, #1
	ldrb r8, [r0, r6, lsr #24]
	ldrb r5, [r1], #1
	strb r8, [r0, r7, lsr #24]
	strb sb, [r0, r6, lsr #24]
	add r4, sb, r8
	and r4, r4, #0xff
	add r7, r7, lr
	ldrb r4, [r0, r4]
	ldrb sb, [r0, r7, lsr #24]
	eor r5, r5, r4
	strb r5, [r3], #1
	bge _02047088
_020470C0:
	sub r7, r7, lr
	mov r7, r7, lsr #0x18
	mov r6, r6, lsr #0x18
	strb r7, [r0, #-4]
	strb r6, [r0, #-3]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

    .section .init, 4
	arm_func_start sub_020841E4
sub_020841E4: ; 0x020841E4
	stmdb sp!, {r3, lr}
	ldr ip, _0208422C ; =MAIN_BSS_0210C1C0
	ldr r0, _02084230 ; =sSaveMagic
	mov r3, #0x60
	str ip, [r0, #0x12c]
	ldr r2, _02084234 ; =MAIN_BSS_0210C228
	str r3, [r0, #0x130]
	str r2, [r0, #0x134]
	mov r1, #0x800
	str r1, [r0, #0x138]
	str ip, [r0, #0x254]
	str r3, [r0, #0x258]
	str r2, [r0, #0x25c]
	str r1, [r0, #0x260]
	bl sub_02010CC0
	ldr r1, _02084230 ; =sSaveMagic
	str r0, [r1, #0x14]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0208422C: .word MAIN_BSS_0210C1C0
_02084230: .word sSaveMagic
_02084234: .word MAIN_BSS_0210C228
	arm_func_end sub_020841E4

	arm_func_start sub_02084238
sub_02084238: ; 0x02084238
	ldr r3, _02084254 ; =MAIN_BSS_0210C1C0
	mov r1, #0
	ldr ip, _02084258 ; =MI_CpuFill8
	ldr r0, _0208425C ; =MAIN_BSS_0210C1C0
	mov r2, #0x60
	str r1, [r3, #0x64]
	bx ip
	.align 2, 0
_02084254: .word MAIN_BSS_0210C1C0
_02084258: .word MI_CpuFill8
_0208425C: .word MAIN_BSS_0210C1C0
	arm_func_end sub_02084238

	arm_func_start sub_02084260
sub_02084260: ; 0x02084260
	ldr r3, _0208427C ; =MAIN_BSS_0210C228
	mov r1, #0
	ldr ip, _02084280 ; =MI_CpuFill8
	ldr r0, _02084284 ; =MAIN_BSS_0210C228
	mov r2, #0x800
	str r1, [r3, #0x804]
	bx ip
	.align 2, 0
_0208427C: .word MAIN_BSS_0210C228
_02084280: .word MI_CpuFill8
_02084284: .word MAIN_BSS_0210C228
	arm_func_end sub_02084260

    .section .ctor, 4
; mwld keeps a .ctor section only through an object named .p__sinit_* (like mwcc's), .sinit is KEEP_SECTION
; but comes after every object's .ctor
	.type .p__sinit_arm9_02046D5C, @object
	.size .p__sinit_arm9_02046D5C, 0xC
.p__sinit_arm9_02046D5C:

	.global ptr_FUN_020841e4_0208a36c
ptr_FUN_020841e4_0208a36c: ; 0x0208A36C
	.word sub_020841E4
	.word sub_02084238
	.word sub_02084260

    .bss
    .global MAIN_BSS_0210CAB0
MAIN_BSS_0210CAB0: ; 0x0210CAB0
    .space 0x4

    .global MAIN_BSS_0210CAB4
MAIN_BSS_0210CAB4: ; 0x0210CAB4
    .space 0x14

    .global MAIN_BSS_0210CAC8
MAIN_BSS_0210CAC8: ; 0x0210CAC8
    .space 0x400

    .global MAIN_BSS_0210CEC8
MAIN_BSS_0210CEC8: ; 0x0210CEC8
    .space 0xC

    .global MAIN_BSS_0210CED4
MAIN_BSS_0210CED4: ; 0x0210CED4
    .space 0x4

    .global MAIN_BSS_0210CED8
MAIN_BSS_0210CED8: ; 0x0210CED8
    .space 0x100

    .global MAIN_BSS_0210CFD8
MAIN_BSS_0210CFD8: ; 0x0210CFD8
    .space 0xC

    .global sHeapAllocFunc
sHeapAllocFunc: ; 0x0210CFE4
    .space 0x4

    .global sHeapFreeFunc
sHeapFreeFunc: ; 0x0210CFE8
    .space 0x4
