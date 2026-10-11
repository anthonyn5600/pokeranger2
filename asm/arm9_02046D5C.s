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

    .rodata
	.global DAT_02084d58
DAT_02084d58: ; 0x02084D58
	.byte 0x00, 0x00, 0x00, 0x00

	.global DAT_02084d5c
DAT_02084d5c: ; 0x02084D5C
	.byte 0x00, 0x00, 0xFE, 0xFF

	.global DAT_02084d60
DAT_02084d60: ; 0x02084D60
	.byte 0x00, 0x00, 0x00, 0x00

	.global DAT_02084d64
DAT_02084d64: ; 0x02084D64
	.byte 0x00, 0x00, 0x00, 0x00

	.global DAT_02084d68
DAT_02084d68: ; 0x02084D68
	.byte 0x00, 0x00, 0x04, 0x00

	.global DAT_02084d6c
DAT_02084d6c: ; 0x02084D6C
	.byte 0x00, 0x00, 0x04, 0x00

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

    .data
	.global DAT_0208d58c
DAT_0208d58c: ; 0x0208D58C
	.byte 0x3C, 0x00, 0x00, 0x00

	.global s_GetEnemyLabel2PartnerIndex_index_0208d590
s_GetEnemyLabel2PartnerIndex_index_0208d590: ; 0x0208D590
	.asciz "GetEnemyLabel2PartnerIndex(index= %d)"

	.global _0208D5B6
_0208D5B6:
	.byte 0x00, 0x00

	.global s_GetPartnerIndex2EnemyLabel_index_0208d5b8
s_GetPartnerIndex2EnemyLabel_index_0208d5b8: ; 0x0208D5B8
	.asciz "GetPartnerIndex2EnemyLabel(index= %d)"

	.global _0208D5DE
_0208D5DE:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_02083578_0208d5e0
PTR_ptr_FUN_02083578_0208d5e0: ; 0x0208D5E0
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_28CFieldScreenEffectObjectBase_0208d5e8

	.global s_28CFieldScreenEffectObjectBase_0208d5e8
s_28CFieldScreenEffectObjectBase_0208d5e8: ; 0x0208D5E8
	.asciz "28CFieldScreenEffectObjectBase"

	.global _0208D607
_0208D607:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_02083578_0208d5e0

	.global PTR_LAB_0208d610
PTR_LAB_0208d610: ; 0x0208D610
	.word sub_02035FE4

	.global ptr_FUN_020357f8_0208d614
ptr_FUN_020357f8_0208d614: ; 0x0208D614
	.word sub_020357F8
	.word sub_02035D30

	.global ptr_FUN_02035334_0208d61c
ptr_FUN_02035334_0208d61c: ; 0x0208D61C
	.word sub_02035334
	.word sub_020358FC

	.global ptr_FUN_020354e0_0208d624
ptr_FUN_020354e0_0208d624: ; 0x0208D624
	.word sub_020354E0
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208d62c
PTR_ptr_FUN_020835bc_0208d62c: ; 0x0208D62C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CPrimitiveQuadNTF_0208d644
	.word _ZTI10CPrimitive

	.global PTR_ptr_FUN_020835bc_0208d638
PTR_ptr_FUN_020835bc_0208d638: ; 0x0208D638
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CPrimitiveRectNTF_0208d66c
	.word _ZTI10CPrimitive

	.global s_17CPrimitiveQuadNTF_0208d644
s_17CPrimitiveQuadNTF_0208d644: ; 0x0208D644
	.asciz "17CPrimitiveQuadNTF"

	.global _0208D658
_0208D658:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d638

	.global ptr_FUN_02036908_0208d660
ptr_FUN_02036908_0208d660: ; 0x0208D660
	.word sub_02036908

	.global ptr_FUN_020368ec_0208d664
ptr_FUN_020368ec_0208d664: ; 0x0208D664
	.word sub_020368EC

	.global ptr_FUN_02036558_0208d668
ptr_FUN_02036558_0208d668: ; 0x0208D668
	.word sub_02036558

	.global s_17CPrimitiveRectNTF_0208d66c
s_17CPrimitiveRectNTF_0208d66c: ; 0x0208D66C
	.asciz "17CPrimitiveRectNTF"

	.global _0208D680
_0208D680:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d62c

	.global ptr_FUN_020368d8_0208d688
ptr_FUN_020368d8_0208d688: ; 0x0208D688
	.word sub_020368D8
	.word sub_020368BC

	.global ptr_FUN_020367b8_0208d690
ptr_FUN_020367b8_0208d690: ; 0x0208D690
	.word sub_020367B8

	.global DAT_0208d694
DAT_0208d694: ; 0x0208D694
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global s_data_Field_Effect_ew_03d_LZ_bin_0208d73c
s_data_Field_Effect_ew_03d_LZ_bin_0208d73c: ; 0x0208D73C
	.asciz "data/Field/Effect/ew%03d_LZ.bin"

	.global DAT_0208d75c
DAT_0208d75c: ; 0x0208D75C
	.byte 0x4D, 0x45, 0x46, 0x00

	.global s_MEF_ew_03d_NCLR_0208d760
s_MEF_ew_03d_NCLR_0208d760: ; 0x0208D760
	.asciz "MEF:ew%03d.NCLR"

	.global s_MEF_ew_03d_NCBR_0208d770
s_MEF_ew_03d_NCBR_0208d770: ; 0x0208D770
	.asciz "MEF:ew%03d.NCBR"

	.global s_MEF_ew_03d_NCER_0208d780
s_MEF_ew_03d_NCER_0208d780: ; 0x0208D780
	.asciz "MEF:ew%03d.NCER"

	.global s_MEF_ew_03d_cac_0208d790
s_MEF_ew_03d_cac_0208d790: ; 0x0208D790
	.asciz "MEF:ew%03d.cac"

	.global _0208D79F
_0208D79F:
	.byte 0x00

	.global PTR_ptr_FUN_020835bc_0208d7a0
PTR_ptr_FUN_020835bc_0208d7a0: ; 0x0208D7A0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFKomorebi_0208d7ac
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_17CFieldSEFKomorebi_0208d7ac
s_17CFieldSEFKomorebi_0208d7ac: ; 0x0208D7AC
	.asciz "17CFieldSEFKomorebi"

	.global _0208D7C0
_0208D7C0:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d7a0

	.global ptr_FUN_020369b4_0208d7c8
ptr_FUN_020369b4_0208d7c8: ; 0x0208D7C8
	.word sub_020369B4

	.global ptr_FUN_020369e4_0208d7cc
ptr_FUN_020369e4_0208d7cc: ; 0x0208D7CC
	.word sub_020369E4
	.word sub_02037354

	.global ptr_FUN_02036a1c_0208d7d4
ptr_FUN_02036a1c_0208d7d4: ; 0x0208D7D4
	.word sub_02036A1C

	.global ptr_FUN_02036b1c_0208d7d8
ptr_FUN_02036b1c_0208d7d8: ; 0x0208D7D8
	.word sub_02036B1C

	.global ptr_FUN_0203733c_0208d7dc
ptr_FUN_0203733c_0208d7dc: ; 0x0208D7DC
	.word sub_0203733C
	.word sub_02035590

	.global s_data_field_effect_komorebi_ntft_0208d7e4
s_data_field_effect_komorebi_ntft_0208d7e4: ; 0x0208D7E4
	.asciz "data/field/effect/komorebi.ntft"

	.global s_data_field_effect_komorebi_ntfp_0208d804
s_data_field_effect_komorebi_ntfp_0208d804: ; 0x0208D804
	.asciz "data/field/effect/komorebi.ntfp"

	.global PTR_ptr_FUN_020835bc_0208d824
PTR_ptr_FUN_020835bc_0208d824: ; 0x0208D824
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_12CFieldSEFFog_0208d830
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_12CFieldSEFFog_0208d830
s_12CFieldSEFFog_0208d830: ; 0x0208D830
	.asciz "12CFieldSEFFog"

	.global _0208D83F
_0208D83F:
	.byte 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d824

	.global ptr_FUN_02037988_0208d848
ptr_FUN_02037988_0208d848: ; 0x0208D848
	.word sub_02037988

	.global ptr_FUN_02037938_0208d84c
ptr_FUN_02037938_0208d84c: ; 0x0208D84C
	.word sub_02037938
	.word sub_02037980

	.global ptr_FUN_02037540_0208d854
ptr_FUN_02037540_0208d854: ; 0x0208D854
	.word sub_02037540

	.global ptr_FUN_020377c0_0208d858
ptr_FUN_020377c0_0208d858: ; 0x0208D858
	.word sub_020377C0

	.global ptr_FUN_02037914_0208d85c
ptr_FUN_02037914_0208d85c: ; 0x0208D85C
	.word sub_02037914
	.word sub_02035590

	.global DAT_0208d864
DAT_0208d864: ; 0x0208D864
	.byte 0xDE, 0x7B, 0x00, 0x00

	.global DAT_0208d868
DAT_0208d868: ; 0x0208D868
	.byte 0x18, 0x00, 0x00, 0x00

	.global DAT_0208d86c
DAT_0208d86c: ; 0x0208D86C
	.byte 0x08, 0x21, 0x00, 0x00

	.global DAT_0208d870
DAT_0208d870: ; 0x0208D870
	.byte 0x0E, 0x00, 0x00, 0x00

	.global DAT_0208d874
DAT_0208d874: ; 0x0208D874
	.byte 0x1E, 0x78, 0x00, 0x00

	.global DAT_0208d878
DAT_0208d878: ; 0x0208D878
	.byte 0x10, 0x00, 0x00, 0x00

	.global DAT_0208d87c
DAT_0208d87c: ; 0x0208D87C
	.byte 0xDE, 0x03, 0x00, 0x00

	.global DAT_0208d880
DAT_0208d880: ; 0x0208D880
	.byte 0x18, 0x00, 0x00, 0x00

	.global DAT_0208d884
DAT_0208d884: ; 0x0208D884
	.byte 0xDE, 0x7B, 0x00, 0x00

	.global DAT_0208d888
DAT_0208d888: ; 0x0208D888
	.byte 0x08, 0x00, 0x00, 0x00

	.global s_data_field_effect_kiri02_ntft_0208d88c
s_data_field_effect_kiri02_ntft_0208d88c: ; 0x0208D88C
	.asciz "data/field/effect/kiri02.ntft"

	.global _0208D8AA
_0208D8AA:
	.byte 0x00, 0x00

	.global s_data_field_effect_kiri02_ntfp_0208d8ac
s_data_field_effect_kiri02_ntfp_0208d8ac: ; 0x0208D8AC
	.asciz "data/field/effect/kiri02.ntfp"

	.global _0208D8CA
_0208D8CA:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208d8cc
PTR_ptr_FUN_020835bc_0208d8cc: ; 0x0208D8CC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_18CFieldSEFSandStorm_0208d8d8
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_18CFieldSEFSandStorm_0208d8d8
s_18CFieldSEFSandStorm_0208d8d8: ; 0x0208D8D8
	.asciz "18CFieldSEFSandStorm"

	.global _0208D8ED
_0208D8ED:
	.byte 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d8cc

	.global ptr_FUN_02037fb0_0208d8f8
ptr_FUN_02037fb0_0208d8f8: ; 0x0208D8F8
	.word sub_02037FB0

	.global ptr_FUN_02037f60_0208d8fc
ptr_FUN_02037f60_0208d8fc: ; 0x0208D8FC
	.word sub_02037F60
	.word sub_02037FA8

	.global ptr_FUN_02037af4_0208d904
ptr_FUN_02037af4_0208d904: ; 0x0208D904
	.word sub_02037AF4

	.global ptr_FUN_02037de8_0208d908
ptr_FUN_02037de8_0208d908: ; 0x0208D908
	.word sub_02037DE8

	.global ptr_FUN_02037f3c_0208d90c
ptr_FUN_02037f3c_0208d90c: ; 0x0208D90C
	.word sub_02037F3C
	.word sub_02035590

	.global s_data_field_effect_suna01_ntft_0208d914
s_data_field_effect_suna01_ntft_0208d914: ; 0x0208D914
	.asciz "data/field/effect/suna01.ntft"

	.global _0208D932
_0208D932:
	.byte 0x00, 0x00

	.global s_data_field_effect_suna01_ntfp_0208d934
s_data_field_effect_suna01_ntfp_0208d934: ; 0x0208D934
	.asciz "data/field/effect/suna01.ntfp"

	.global _0208D952
_0208D952:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208d954
PTR_ptr_FUN_020835bc_0208d954: ; 0x0208D954
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFDokarimo_0208d960
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_17CFieldSEFDokarimo_0208d960
s_17CFieldSEFDokarimo_0208d960: ; 0x0208D960
	.asciz "17CFieldSEFDokarimo"

	.global _0208D974
_0208D974:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d954

	.global ptr_FUN_02038998_0208d97c
ptr_FUN_02038998_0208d97c: ; 0x0208D97C
	.word sub_02038998

	.global ptr_FUN_02038938_0208d980
ptr_FUN_02038938_0208d980: ; 0x0208D980
	.word sub_02038938
	.word sub_02038990

	.global ptr_FUN_02038178_0208d988
ptr_FUN_02038178_0208d988: ; 0x0208D988
	.word sub_02038178

	.global ptr_FUN_020382e0_0208d98c
ptr_FUN_020382e0_0208d98c: ; 0x0208D98C
	.word sub_020382E0

	.global ptr_FUN_020388e8_0208d990
ptr_FUN_020388e8_0208d990: ; 0x0208D990
	.word sub_020388E8
	.word sub_02035590

	.global s_data_field_effect_dokarimo03_ntf_0208d998
s_data_field_effect_dokarimo03_ntf_0208d998: ; 0x0208D998
	.asciz "data/field/effect/dokarimo03.ntft"

	.global _0208D9BA
_0208D9BA:
	.byte 0x00, 0x00

	.global s_data_field_effect_dokarimo03_ntf_0208d9bc
s_data_field_effect_dokarimo03_ntf_0208d9bc: ; 0x0208D9BC
	.asciz "data/field/effect/dokarimo03.ntfp"

	.global _0208D9DE
_0208D9DE:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208d9e0
PTR_ptr_FUN_020835bc_0208d9e0: ; 0x0208D9E0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFTheWater_0208d9ec
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_17CFieldSEFTheWater_0208d9ec
s_17CFieldSEFTheWater_0208d9ec: ; 0x0208D9EC
	.asciz "17CFieldSEFTheWater"

	.global _0208DA00
_0208DA00:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d9e0

	.global ptr_FUN_02038cd4_0208da08
ptr_FUN_02038cd4_0208da08: ; 0x0208DA08
	.word sub_02038CD4

	.global ptr_FUN_02038c94_0208da0c
ptr_FUN_02038c94_0208da0c: ; 0x0208DA0C
	.word sub_02038C94
	.word sub_02038CCC

	.global ptr_FUN_02038b04_0208da14
ptr_FUN_02038b04_0208da14: ; 0x0208DA14
	.word sub_02038B04

	.global ptr_FUN_02038bc4_0208da18
ptr_FUN_02038bc4_0208da18: ; 0x0208DA18
	.word sub_02038BC4

	.global ptr_FUN_02038c70_0208da1c
ptr_FUN_02038c70_0208da1c: ; 0x0208DA1C
	.word sub_02038C70
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208da24
PTR_ptr_FUN_020835bc_0208da24: ; 0x0208DA24
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_15CFieldSEFHinoko_0208da3c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global PTR_ptr_FUN_020835bc_0208da30
PTR_ptr_FUN_020835bc_0208da30: ; 0x0208DA30
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_27CFieldScreenEffectActorData_0208da50
	.word PTR_ptr_FUN_020835bc_0208c468

	.global s_15CFieldSEFHinoko_0208da3c
s_15CFieldSEFHinoko_0208da3c: ; 0x0208DA3C
	.asciz "15CFieldSEFHinoko"

	.global _0208DA4E
_0208DA4E:
	.byte 0x00, 0x00

	.global s_27CFieldScreenEffectActorData_0208da50
s_27CFieldScreenEffectActorData_0208da50: ; 0x0208DA50
	.asciz "27CFieldScreenEffectActorData"

	.global _0208DA6E
_0208DA6E:
	.byte 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208da24

	.global ptr_FUN_02039ddc_0208da78
ptr_FUN_02039ddc_0208da78: ; 0x0208DA78
	.word sub_02039DDC

	.global ptr_FUN_02039d90_0208da7c
ptr_FUN_02039d90_0208da7c: ; 0x0208DA7C
	.word sub_02039D90
	.word sub_02039DC8

	.global ptr_FUN_02038dec_0208da84
ptr_FUN_02038dec_0208da84: ; 0x0208DA84
	.word sub_02038DEC

	.global ptr_FUN_02039510_0208da88
ptr_FUN_02039510_0208da88: ; 0x0208DA88
	.word sub_02039510

	.global ptr_FUN_02039d6c_0208da8c
ptr_FUN_02039d6c_0208da8c: ; 0x0208DA8C
	.word sub_02039D6C
	.word sub_02035590
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208da30

	.global PTR_LAB_0208da9c
PTR_LAB_0208da9c: ; 0x0208DA9C
	.word sub_02039E0C

	.global ptr_FUN_02039d50_0208daa0
ptr_FUN_02039d50_0208daa0: ; 0x0208DAA0
	.word sub_02039D50

	.global ptr_FUN_020297dc_0208daa4
ptr_FUN_020297dc_0208daa4: ; 0x0208DAA4
	.word sub_020297DC

	.global ptr_FUN_020297b0_0208daa8
ptr_FUN_020297b0_0208daa8: ; 0x0208DAA8
	.word sub_020297B0

	.global ptr_FUN_02029784_0208daac
ptr_FUN_02029784_0208daac: ; 0x0208DAAC
	.word sub_02029784

	.global ptr_FUN_0202977c_0208dab0
ptr_FUN_0202977c_0208dab0: ; 0x0208DAB0
	.word sub_0202977C

	.global ptr_FUN_020394d4_0208dab4
ptr_FUN_020394d4_0208dab4: ; 0x0208DAB4
	.word sub_020394D4
	.word sub_02029770
	.word sub_02029704

	.global s_data_field_effect_kiri02_ntft_0208dac0
s_data_field_effect_kiri02_ntft_0208dac0: ; 0x0208DAC0
	.asciz "data/field/effect/kiri02.ntft"

	.global _0208DADE
_0208DADE:
	.byte 0x00, 0x00

	.global s_data_field_effect_kiri02_ntfp_0208dae0
s_data_field_effect_kiri02_ntfp_0208dae0: ; 0x0208DAE0
	.asciz "data/field/effect/kiri02.ntfp"

	.global _0208DAFE
_0208DAFE:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208db00
PTR_ptr_FUN_020835bc_0208db00: ; 0x0208DB00
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_13CFieldSEFRain_0208db0c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_13CFieldSEFRain_0208db0c
s_13CFieldSEFRain_0208db0c: ; 0x0208DB0C
	.asciz "13CFieldSEFRain"

	.global _0208DB1C
_0208DB1C:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208db00

	.global ptr_FUN_0203a734_0208db24
ptr_FUN_0203a734_0208db24: ; 0x0208DB24
	.word sub_0203A734

	.global ptr_FUN_0203a6cc_0208db28
ptr_FUN_0203a6cc_0208db28: ; 0x0208DB28
	.word sub_0203A6CC
	.word sub_0203A72C

	.global ptr_FUN_0203a068_0208db30
ptr_FUN_0203a068_0208db30: ; 0x0208DB30
	.word sub_0203A068

	.global ptr_FUN_0203a3cc_0208db34
ptr_FUN_0203a3cc_0208db34: ; 0x0208DB34
	.word sub_0203A3CC
	.word sub_0203A70C
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208db40
PTR_ptr_FUN_020835bc_0208db40: ; 0x0208DB40
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CFieldSEFWarning_0208db4c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_16CFieldSEFWarning_0208db4c
s_16CFieldSEFWarning_0208db4c: ; 0x0208DB4C
	.asciz "16CFieldSEFWarning"

	.global _0208DB5F
_0208DB5F:
	.byte 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208db40

	.global ptr_FUN_0203aa14_0208db68
ptr_FUN_0203aa14_0208db68: ; 0x0208DB68
	.word sub_0203AA14

	.global ptr_FUN_0203a9d4_0208db6c
ptr_FUN_0203a9d4_0208db6c: ; 0x0208DB6C
	.word sub_0203A9D4
	.word sub_0203AA0C

	.global ptr_FUN_0203a854_0208db74
ptr_FUN_0203a854_0208db74: ; 0x0208DB74
	.word sub_0203A854

	.global ptr_FUN_0203a934_0208db78
ptr_FUN_0203a934_0208db78: ; 0x0208DB78
	.word sub_0203A934

	.global ptr_FUN_020354e0_0208db7c
ptr_FUN_020354e0_0208db7c: ; 0x0208DB7C
	.word sub_020354E0
	.word sub_02035590

	.global DAT_0208db84
DAT_0208db84: ; 0x0208DB84
	.byte 0xCC, 0x04, 0x00, 0x00

	.global DAT_0208db88
DAT_0208db88: ; 0x0208DB88
	.byte 0x00, 0x08, 0x00, 0x00

	.global DAT_0208db8c
DAT_0208db8c: ; 0x0208DB8C
	.byte 0x33, 0x0B, 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208db90
PTR_ptr_FUN_020835bc_0208db90: ; 0x0208DB90
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_13CFieldSEFSnow_0208db9c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_13CFieldSEFSnow_0208db9c
s_13CFieldSEFSnow_0208db9c: ; 0x0208DB9C
	.asciz "13CFieldSEFSnow"

	.global _0208DBAC
_0208DBAC:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208db90

	.global ptr_FUN_0203b314_0208dbb4
ptr_FUN_0203b314_0208dbb4: ; 0x0208DBB4
	.word sub_0203B314

	.global ptr_FUN_0203b2cc_0208dbb8
ptr_FUN_0203b2cc_0208dbb8: ; 0x0208DBB8
	.word sub_0203B2CC
	.word sub_0203B30C

	.global ptr_FUN_0203ab28_0208dbc0
ptr_FUN_0203ab28_0208dbc0: ; 0x0208DBC0
	.word sub_0203AB28

	.global ptr_FUN_0203add8_0208dbc4
ptr_FUN_0203add8_0208dbc4: ; 0x0208DBC4
	.word sub_0203ADD8

	.global ptr_FUN_0203b2a8_0208dbc8
ptr_FUN_0203b2a8_0208dbc8: ; 0x0208DBC8
	.word sub_0203B2A8
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208dbd0
PTR_ptr_FUN_020835bc_0208dbd0: ; 0x0208DBD0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFDarkness_0208dbdc
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_17CFieldSEFDarkness_0208dbdc
s_17CFieldSEFDarkness_0208dbdc: ; 0x0208DBDC
	.asciz "17CFieldSEFDarkness"

	.global _0208DBF0
_0208DBF0:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208dbd0

	.global ptr_FUN_0203bcc4_0208dbf8
ptr_FUN_0203bcc4_0208dbf8: ; 0x0208DBF8
	.word sub_0203BCC4

	.global ptr_FUN_0203bc64_0208dbfc
ptr_FUN_0203bc64_0208dbfc: ; 0x0208DBFC
	.word sub_0203BC64
	.word sub_0203BCBC

	.global ptr_FUN_0203b4a0_0208dc04
ptr_FUN_0203b4a0_0208dc04: ; 0x0208DC04
	.word sub_0203B4A0

	.global ptr_FUN_0203b608_0208dc08
ptr_FUN_0203b608_0208dc08: ; 0x0208DC08
	.word sub_0203B608

	.global ptr_FUN_0203bc14_0208dc0c
ptr_FUN_0203bc14_0208dc0c: ; 0x0208DC0C
	.word sub_0203BC14
	.word sub_02035590

	.global s_data_field_effect_dokarimo03_ntf_0208dc14
s_data_field_effect_dokarimo03_ntf_0208dc14: ; 0x0208DC14
	.asciz "data/field/effect/dokarimo03.ntft"

	.global _0208DC36
_0208DC36:
	.byte 0x00, 0x00

	.global s_data_field_effect_dokarimo03_ntf_0208dc38
s_data_field_effect_dokarimo03_ntf_0208dc38: ; 0x0208DC38
	.asciz "data/field/effect/dokarimo03.ntfp"

	.global _0208DC5A
_0208DC5A:
	.byte 0x00, 0x00

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
