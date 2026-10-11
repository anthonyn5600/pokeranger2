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
	arm_func_start sub_020840B0
sub_020840B0: ; 0x020840B0
	stmdb sp!, {r3, lr}
	ldr r0, _0208412C ; =MAIN_BSS_020AF5D0
	bl sub_02010EC8
	ldr r0, _0208412C ; =MAIN_BSS_020AF5D0
	ldr r1, _02084130 ; =sub_02010ED4
	ldr r2, _02084134 ; =MAIN_BSS_020AF5B8
	bl __register_global_object
	ldr ip, _02084130 ; =sub_02010ED4
	ldr r0, _02084138 ; =MAIN_BSS_020AF5E4
	ldr r3, _0208413C ; =sub_02010EC8
	mov r1, #3
	mov r2, #0x14
	str ip, [sp]
	bl __cxa_vec_ctor
	ldr r1, _02084140 ; =sub_02011338
	ldr r2, _02084144 ; =MAIN_BSS_020AF5C4
	mov r0, #0
	bl __register_global_object
	ldr r0, _02084148 ; =MAIN_BSS_020AF620
	bl sub_0201100C
	ldr r0, _02084148 ; =MAIN_BSS_020AF620
	ldr r1, _0208414C ; =sub_0201101C
	ldr r2, _02084150 ; =MAIN_BSS_020AF5AC
	bl __register_global_object
	ldr r0, _02084154 ; =MAIN_BSS_020AF598
	bl sub_02011248
	ldr r0, _02084154 ; =MAIN_BSS_020AF598
	ldr r1, _02084158 ; =sub_02011254
	ldr r2, _0208415C ; =MAIN_BSS_020AF5A0
	bl __register_global_object
	ldmia sp!, {r3, pc}
	.align 2, 0
_0208412C: .word MAIN_BSS_020AF5D0
_02084130: .word sub_02010ED4
_02084134: .word MAIN_BSS_020AF5B8
_02084138: .word MAIN_BSS_020AF5E4
_0208413C: .word sub_02010EC8
_02084140: .word sub_02011338
_02084144: .word MAIN_BSS_020AF5C4
_02084148: .word MAIN_BSS_020AF620
_0208414C: .word sub_0201101C
_02084150: .word MAIN_BSS_020AF5AC
_02084154: .word MAIN_BSS_020AF598
_02084158: .word sub_02011254
_0208415C: .word MAIN_BSS_020AF5A0
	arm_func_end sub_020840B0

	arm_func_start sub_02084160
sub_02084160: ; 0x02084160
	stmdb sp!, {r3, lr}
	ldr r0, _02084180 ; =MAIN_BSS_020B2638
	bl sub_02011370
	ldr r0, _02084180 ; =MAIN_BSS_020B2638
	ldr r1, _02084184 ; =sub_02011384
	ldr r2, _02084188 ; =MAIN_BSS_020B262C
	bl __register_global_object
	ldmia sp!, {r3, pc}
	.align 2, 0
_02084180: .word MAIN_BSS_020B2638
_02084184: .word sub_02011384
_02084188: .word MAIN_BSS_020B262C
	arm_func_end sub_02084160

	arm_func_start sub_0208418C
sub_0208418C: ; 0x0208418C
	stmdb sp!, {r3, lr}
	ldr r0, _020841AC ; =MAIN_BSS_020B26A0
	bl sub_020152D0
	ldr r0, _020841AC ; =MAIN_BSS_020B26A0
	ldr r1, _020841B0 ; =sub_020153AC
	ldr r2, _020841B4 ; =MAIN_BSS_020B2694
	bl __register_global_object
	ldmia sp!, {r3, pc}
	.align 2, 0
_020841AC: .word MAIN_BSS_020B26A0
_020841B0: .word sub_020153AC
_020841B4: .word MAIN_BSS_020B2694
	arm_func_end sub_0208418C

	arm_func_start sub_020841B8
sub_020841B8: ; 0x020841B8
	stmdb sp!, {r3, lr}
	ldr r0, _020841D8 ; =MAIN_BSS_0210C0B0
	bl sub_02018DF4
	ldr r0, _020841D8 ; =MAIN_BSS_0210C0B0
	ldr r1, _020841DC ; =sub_02018E08
	ldr r2, _020841E0 ; =MAIN_BSS_0210C0A4
	bl __register_global_object
	ldmia sp!, {r3, pc}
	.align 2, 0
_020841D8: .word MAIN_BSS_0210C0B0
_020841DC: .word sub_02018E08
_020841E0: .word MAIN_BSS_0210C0A4
	arm_func_end sub_020841B8

	arm_func_start sub_020841E4
sub_020841E4: ; 0x020841E4
	stmdb sp!, {r3, lr}
	ldr ip, _0208422C ; =MAIN_BSS_0210C1C0
	ldr r0, _02084230 ; =PTR_LAB_0208c1c0
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
	ldr r1, _02084230 ; =PTR_LAB_0208c1c0
	str r0, [r1, #0x14]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0208422C: .word MAIN_BSS_0210C1C0
_02084230: .word PTR_LAB_0208c1c0
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
	.global ptr_FUN_020840b0_0208a35c
ptr_FUN_020840b0_0208a35c: ; 0x0208A35C
	.type .p__sinit_arm9_02046D5C, @object
	.size .p__sinit_arm9_02046D5C, 0x1C
.p__sinit_arm9_02046D5C:
	.word sub_020840B0
	.word sub_02084160
	.word sub_0208418C
	.word sub_020841B8

	.global ptr_FUN_020841e4_0208a36c
ptr_FUN_020841e4_0208a36c: ; 0x0208A36C
	.word sub_020841E4
	.word sub_02084238
	.word sub_02084260

    .bss
    .global MAIN_BSS_020AF35C
MAIN_BSS_020AF35C: ; 0x020AF35C
    .space 0x72

    .global MAIN_BSS_020AF3CE
MAIN_BSS_020AF3CE: ; 0x020AF3CE
    .space 0x1CA

    .global MAIN_BSS_020AF598
MAIN_BSS_020AF598: ; 0x020AF598
    .space 0x8

    .global MAIN_BSS_020AF5A0
MAIN_BSS_020AF5A0: ; 0x020AF5A0
    .space 0xC

    .global MAIN_BSS_020AF5AC
MAIN_BSS_020AF5AC: ; 0x020AF5AC
    .space 0xC

    .global MAIN_BSS_020AF5B8
MAIN_BSS_020AF5B8: ; 0x020AF5B8
    .space 0xC

    .global MAIN_BSS_020AF5C4
MAIN_BSS_020AF5C4: ; 0x020AF5C4
    .space 0xC

    .global MAIN_BSS_020AF5D0
MAIN_BSS_020AF5D0: ; 0x020AF5D0
    .space 0x14

    .global MAIN_BSS_020AF5E4
MAIN_BSS_020AF5E4: ; 0x020AF5E4
    .space 0x14

    .global MAIN_BSS_020AF5F8
MAIN_BSS_020AF5F8: ; 0x020AF5F8
    .space 0x14

    .global MAIN_BSS_020AF60C
MAIN_BSS_020AF60C: ; 0x020AF60C
    .space 0x14

    .global MAIN_BSS_020AF620
MAIN_BSS_020AF620: ; 0x020AF620
    .space 0x4

    .global MAIN_BSS_020AF624
MAIN_BSS_020AF624: ; 0x020AF624
    .space 0xA05

    .global MAIN_BSS_020B0029
MAIN_BSS_020B0029: ; 0x020B0029
    .space 0x1

    .global MAIN_BSS_020B002A
MAIN_BSS_020B002A: ; 0x020B002A
    .space 0x1

    .global MAIN_BSS_020B002B
MAIN_BSS_020B002B: ; 0x020B002B
    .space 0x1

    .global MAIN_BSS_020B002C
MAIN_BSS_020B002C: ; 0x020B002C
    .space 0x2600

    .global MAIN_BSS_020B262C
MAIN_BSS_020B262C: ; 0x020B262C
    .space 0xC

    .global MAIN_BSS_020B2638
MAIN_BSS_020B2638: ; 0x020B2638
    .space 0x5C

    .global MAIN_BSS_020B2694
MAIN_BSS_020B2694: ; 0x020B2694
    .space 0xC

    .global MAIN_BSS_020B26A0
MAIN_BSS_020B26A0: ; 0x020B26A0
    .space 0x7C3C

    .global MAIN_BSS_020BA2DC
MAIN_BSS_020BA2DC: ; 0x020BA2DC
    .space 0x80

    .global MAIN_BSS_020BA35C
MAIN_BSS_020BA35C: ; 0x020BA35C
    .space 0x1F4

    .global MAIN_BSS_020BA550
MAIN_BSS_020BA550: ; 0x020BA550
    .space 0xB4

    .global MAIN_BSS_020BA604
MAIN_BSS_020BA604: ; 0x020BA604
    .space 0x9C

    .global MAIN_BSS_020BA6A0
MAIN_BSS_020BA6A0: ; 0x020BA6A0
    .space 0x1B4

    .global MAIN_BSS_020BA854
MAIN_BSS_020BA854: ; 0x020BA854
    .space 0x140

    .global MAIN_BSS_020BA994
MAIN_BSS_020BA994: ; 0x020BA994
    .space 0x40C

    .global MAIN_BSS_020BADA0
MAIN_BSS_020BADA0: ; 0x020BADA0
    .space 0x6C

    .global MAIN_BSS_020BAE0C
MAIN_BSS_020BAE0C: ; 0x020BAE0C
    .space 0x6F

    .global MAIN_BSS_020BAE7B
MAIN_BSS_020BAE7B: ; 0x020BAE7B
    .space 0x8

    .global MAIN_BSS_020BAE83
MAIN_BSS_020BAE83: ; 0x020BAE83
    .space 0x21

    .global MAIN_BSS_020BAEA4
MAIN_BSS_020BAEA4: ; 0x020BAEA4
    .space 0x18

    .global MAIN_BSS_020BAEBC
MAIN_BSS_020BAEBC: ; 0x020BAEBC
    .space 0x18

    .global MAIN_BSS_020BAED4
MAIN_BSS_020BAED4: ; 0x020BAED4
    .space 0x18

    .global MAIN_BSS_020BAEEC
MAIN_BSS_020BAEEC: ; 0x020BAEEC
    .space 0x18

    .global MAIN_BSS_020BAF04
MAIN_BSS_020BAF04: ; 0x020BAF04
    .space 0x18

    .global MAIN_BSS_020BAF1C
MAIN_BSS_020BAF1C: ; 0x020BAF1C
    .space 0x18

    .global MAIN_BSS_020BAF34
MAIN_BSS_020BAF34: ; 0x020BAF34
    .space 0x18

    .global MAIN_BSS_020BAF4C
MAIN_BSS_020BAF4C: ; 0x020BAF4C
    .space 0x48

    .global MAIN_BSS_020BAF94
MAIN_BSS_020BAF94: ; 0x020BAF94
    .space 0x18

    .global MAIN_BSS_020BAFAC
MAIN_BSS_020BAFAC: ; 0x020BAFAC
    .space 0x18

    .global MAIN_BSS_020BAFC4
MAIN_BSS_020BAFC4: ; 0x020BAFC4
    .space 0x18

    .global MAIN_BSS_020BAFDC
MAIN_BSS_020BAFDC: ; 0x020BAFDC
    .space 0x18

    .global MAIN_BSS_020BAFF4
MAIN_BSS_020BAFF4: ; 0x020BAFF4
    .space 0x18

    .global MAIN_BSS_020BB00C
MAIN_BSS_020BB00C: ; 0x020BB00C
    .space 0x18

    .global MAIN_BSS_020BB024
MAIN_BSS_020BB024: ; 0x020BB024
    .space 0x18

    .global MAIN_BSS_020BB03C
MAIN_BSS_020BB03C: ; 0x020BB03C
    .space 0x48

    .global MAIN_BSS_020BB084
MAIN_BSS_020BB084: ; 0x020BB084
    .space 0x18

    .global MAIN_BSS_020BB09C
MAIN_BSS_020BB09C: ; 0x020BB09C
    .space 0x18

    .global MAIN_BSS_020BB0B4
MAIN_BSS_020BB0B4: ; 0x020BB0B4
    .space 0x18

    .global MAIN_BSS_020BB0CC
MAIN_BSS_020BB0CC: ; 0x020BB0CC
    .space 0x18

    .global MAIN_BSS_020BB0E4
MAIN_BSS_020BB0E4: ; 0x020BB0E4
    .space 0x18

    .global MAIN_BSS_020BB0FC
MAIN_BSS_020BB0FC: ; 0x020BB0FC
    .space 0x18

    .global MAIN_BSS_020BB114
MAIN_BSS_020BB114: ; 0x020BB114
    .space 0x18

    .global MAIN_BSS_020BB12C
MAIN_BSS_020BB12C: ; 0x020BB12C
    .space 0x48

    .global MAIN_BSS_020BB174
MAIN_BSS_020BB174: ; 0x020BB174
    .space 0x2C

    .global MAIN_BSS_020BB1A0
MAIN_BSS_020BB1A0: ; 0x020BB1A0
    .space 0xC

    .global MAIN_BSS_020BB1AC
MAIN_BSS_020BB1AC: ; 0x020BB1AC
    .space 0x64

    .global MAIN_BSS_020BB210
MAIN_BSS_020BB210: ; 0x020BB210
    .space 0x25DCE

    .global MAIN_BSS_020E0FDE
MAIN_BSS_020E0FDE: ; 0x020E0FDE
    .space 0xE044

    .global MAIN_BSS_020EF022
MAIN_BSS_020EF022: ; 0x020EF022
    .space 0x1BE7

    .global MAIN_BSS_020F0C09
MAIN_BSS_020F0C09: ; 0x020F0C09
    .space 0x1B49B

    .global MAIN_BSS_0210C0A4
MAIN_BSS_0210C0A4: ; 0x0210C0A4
    .space 0xC

    .global MAIN_BSS_0210C0B0
MAIN_BSS_0210C0B0: ; 0x0210C0B0
    .space 0xFC

    .global MAIN_BSS_0210C1AC
MAIN_BSS_0210C1AC: ; 0x0210C1AC
    .space 0x4

    .global MAIN_BSS_0210C1B0
MAIN_BSS_0210C1B0: ; 0x0210C1B0
    .space 0x8

    .global MAIN_BSS_0210C1B8
MAIN_BSS_0210C1B8: ; 0x0210C1B8
    .space 0x4

    .global MAIN_BSS_0210C1BC
MAIN_BSS_0210C1BC: ; 0x0210C1BC
    .space 0x4

    .global MAIN_BSS_0210C1C0
MAIN_BSS_0210C1C0: ; 0x0210C1C0
    .space 0x60

    .global MAIN_BSS_0210C220
MAIN_BSS_0210C220: ; 0x0210C220
    .space 0x8

    .global MAIN_BSS_0210C228
MAIN_BSS_0210C228: ; 0x0210C228
    .space 0x800

    .global MAIN_BSS_0210CA28
MAIN_BSS_0210CA28: ; 0x0210CA28
    .space 0x8

    .global sCardBackupInfo
sCardBackupInfo: ; 0x0210CA30
    .space 0x8

    .global MAIN_BSS_0210CA38
MAIN_BSS_0210CA38: ; 0x0210CA38
    .space 0x4

    .global MAIN_BSS_0210CA3C
MAIN_BSS_0210CA3C: ; 0x0210CA3C
    .space 0x4

    .global MAIN_BSS_0210CA40
MAIN_BSS_0210CA40: ; 0x0210CA40
    .space 0x4

    .global MAIN_BSS_0210CA44
MAIN_BSS_0210CA44: ; 0x0210CA44
    .space 0x4

    .global MAIN_BSS_0210CA48
MAIN_BSS_0210CA48: ; 0x0210CA48
    .space 0x4

    .global MAIN_BSS_0210CA4C
MAIN_BSS_0210CA4C: ; 0x0210CA4C
    .space 0x4

    .global MAIN_BSS_0210CA50
MAIN_BSS_0210CA50: ; 0x0210CA50
    .space 0x4

    .global MAIN_BSS_0210CA54
MAIN_BSS_0210CA54: ; 0x0210CA54
    .space 0x4

    .global MAIN_BSS_0210CA58
MAIN_BSS_0210CA58: ; 0x0210CA58
    .space 0x4

    .global MAIN_BSS_0210CA5C
MAIN_BSS_0210CA5C: ; 0x0210CA5C
    .space 0x4

    .global MAIN_BSS_0210CA60
MAIN_BSS_0210CA60: ; 0x0210CA60
    .space 0x4

    .global MAIN_BSS_0210CA64
MAIN_BSS_0210CA64: ; 0x0210CA64
    .space 0x4

    .global MAIN_BSS_0210CA68
MAIN_BSS_0210CA68: ; 0x0210CA68
    .space 0x4

    .global MAIN_BSS_0210CA6C
MAIN_BSS_0210CA6C: ; 0x0210CA6C
    .space 0x4

    .global MAIN_BSS_0210CA70
MAIN_BSS_0210CA70: ; 0x0210CA70
    .space 0x4

    .global MAIN_BSS_0210CA74
MAIN_BSS_0210CA74: ; 0x0210CA74
    .space 0x4

    .global MAIN_BSS_0210CA78
MAIN_BSS_0210CA78: ; 0x0210CA78
    .space 0x4

    .global MAIN_BSS_0210CA7C
MAIN_BSS_0210CA7C: ; 0x0210CA7C
    .space 0x4

    .global MAIN_BSS_0210CA80
MAIN_BSS_0210CA80: ; 0x0210CA80
    .space 0x4

    .global MAIN_BSS_0210CA84
MAIN_BSS_0210CA84: ; 0x0210CA84
    .space 0x8

    .global MAIN_BSS_0210CA8C
MAIN_BSS_0210CA8C: ; 0x0210CA8C
    .space 0x4

    .global MAIN_BSS_0210CA90
MAIN_BSS_0210CA90: ; 0x0210CA90
    .space 0xC

    .global MAIN_BSS_0210CA9C
MAIN_BSS_0210CA9C: ; 0x0210CA9C
    .space 0x8

    .global MAIN_BSS_0210CAA4
MAIN_BSS_0210CAA4: ; 0x0210CAA4
    .space 0xC

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
