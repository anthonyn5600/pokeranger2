    .include "macros.inc"
    .include "include/arm9_020150B8.inc"

    .text

	arm_func_start sub_020150B8
sub_020150B8: ; 0x020150B8
	sub sp, sp, #8
	mov r2, #0
	str r2, [r0, #8]
	strh r2, [r0]
	strh r2, [r0, #2]
	add r1, sp, #0
	strh r2, [r0, #4]
	str r2, [r1]
	str r2, [r1, #4]
	str r2, [r0, #0xc]
	ldr r1, [sp, #4]
	str r1, [r0, #0x10]
	strh r2, [r0, #0x14]
	add sp, sp, #8
	bx lr
	arm_func_end sub_020150B8

	arm_func_start sub_020150F4
sub_020150F4: ; 0x020150F4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020150B8
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020150F4

    arm_func_start sub_02015108
sub_02015108: ; 0x02015108
    bx lr
	arm_func_end sub_02015108

	arm_func_start sub_0201510C
sub_0201510C: ; 0x0201510C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02015124
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_0201510C

    arm_func_start sub_02015120
sub_02015120: ; 0x02015120
    bx lr
	arm_func_end sub_02015120

	arm_func_start sub_02015124
sub_02015124: ; 0x02015124
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	mov r2, #0
	str r2, [r0]
	str r2, [r0, #4]
	add r1, sp, #0
	strh r2, [r0, #8]
	str r2, [r1]
	str r2, [r1, #4]
	str r2, [r0, #0xc]
	ldr r1, [sp, #4]
	str r1, [r0, #0x10]
	strh r2, [r0, #0xa]
	bl sub_0201518C
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	arm_func_end sub_02015124

	arm_func_start sub_02015164
sub_02015164: ; 0x02015164
	stmdb sp!, {r3, lr}
	cmp r1, #0
	ldrnesb r2, [r1]
	cmpne r2, #0
	beq _02015184
	add r0, r0, #0x14
	bl strcpy
	ldmia sp!, {r3, pc}
	arm_func_end sub_02015164
_02015184:
	bl sub_0201518C
	ldmia sp!, {r3, pc}

	arm_func_start sub_0201518C
sub_0201518C: ; 0x0201518C
	mov r1, #0
	strb r1, [r0, #0x14]
	bx lr
	arm_func_end sub_0201518C

	arm_func_start sub_02015198
sub_02015198: ; 0x02015198
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	ldr r2, _020152C4 ; =0x00008804
	mov r4, r0
	mov r1, #0
	bl MI_CpuFill8
	add r0, r4, #0xeb0
	add r1, r0, #0x7000
	mvn r0, #0
	mov r2, #0x80
	bl MIi_CpuClearFast
	add r1, r4, #0x8000
	mov ip, #0
	strb ip, [r1, #0xb44]
	strb ip, [r1, #0xb64]
	mov r0, #0x3b
	strh r0, [r4, #0x1a]
	ldr r2, _020152C8 ; =0x0000060F
	ldr r0, _020152CC ; =0x0000042E
	strh r2, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	mov r0, #0x4000
	strh r0, [r4, #0x24]
	strb ip, [r4]
	ldrb r3, [r4, #3]
	add r2, r4, #0x7000
	mov r0, r4
	and r5, r3, #0xf0
	and r3, r5, #0xff
	and r3, r3, #0xf
	strb r3, [r4, #3]
	strb ip, [r1, #0x802]
	str ip, [r2, #0xc38]
	mov r1, #1
	bl sub_020160B8
	ldrb r1, [r4, #2]
	add r0, r4, #4
	mov r6, #0
	add r8, r0, #0x8800
	strb r1, [r4, #1]
	mov r5, r6
	arm_func_end sub_02015198
_02015238:
	mov r7, r5
	mov sb, r8
_02015240:
	mov r0, sb
	bl sub_020150B8
	add r7, r7, #1
	cmp r7, #0xa
	add sb, sb, #0x18
	blt _02015240
	add r6, r6, #1
	cmp r6, #3
	add r8, r8, #0xf0
	blt _02015238
	mov r1, #0
	mov r3, r4
	mov r2, r1
_02015274:
	add r0, r3, #0x8000
	add r1, r1, #1
	str r2, [r0, #0xad4]
	cmp r1, #2
	add r3, r3, #0x38
	blt _02015274
	add r1, r4, #0x8000
	str r2, [r1, #0xb68]
	str r2, [r1, #0xb6c]
	mov r0, #1
	str r0, [r1, #0xb70]
	str r2, [r1, #0xb74]
	str r2, [r1, #0x7c8]
	str r2, [r1, #0x1ac]
	mov r0, r4
	str r2, [r1, #0xbc0]
	bl sub_02017E44
	mov r0, r4
	bl sub_0201772C
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_020152C4: .word 0x00008804
_020152C8: .word 0x0000060F
_020152CC: .word 0x0000042E

	arm_func_start sub_020152D0
sub_020152D0: ; 0x020152D0
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	add r0, r4, #4
	ldr ip, _02015394 ; =0x02015108
	ldr r3, _02015398 ; =sub_020150F4
	add r0, r0, #0x8800
	mov r1, #0x1e
	mov r2, #0x18
	str ip, [sp]
	bl __cxa_vec_ctor
	add r0, r4, #0x2d4
	ldr ip, _0201539C ; =0x02015120
	ldr r3, _020153A0 ; =sub_0201510C
	add r0, r0, #0x8800
	mov r1, #2
	mov r2, #0x38
	str ip, [sp]
	bl __cxa_vec_ctor
	add r0, r4, #0x328
	add r0, r0, #0x8c00
	bl _ZN17UnkClass_020412A0C1Ev
	ldr r1, _020153A4 ; =sub_0204114C
	add r0, r4, #0x760
	str r1, [sp]
	add r0, r0, #0x59000
	mov r1, #2
	mov r2, #0x38
	ldr r3, _020153A8 ; =sub_02041124
	bl __cxa_vec_ctor
	ldr r1, _020153A4 ; =sub_0204114C
	add r0, r4, #0x7d0
	str r1, [sp]
	add r0, r0, #0x59000
	mov r1, #0xa
	mov r2, #0x38
	ldr r3, _020153A8 ; =sub_02041124
	bl __cxa_vec_ctor
	mov r0, r4
	bl sub_02015198
	mov r2, #0
	add r0, r4, #0x59000
	str r2, [r0, #0xa00]
	add r1, r4, #0x8000
	mov r0, r4
	str r2, [r1, #0xb8c]
	str r2, [r1, #0xb88]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02015394: .word sub_02015108
_02015398: .word sub_020150F4
_0201539C: .word sub_02015120
_020153A0: .word sub_0201510C
_020153A4: .word sub_0204114C
_020153A8: .word sub_02041124
	arm_func_end sub_020152D0

	arm_func_start sub_020153AC
sub_020153AC: ; 0x020153AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x7d0
	ldr r3, _02015428 ; =sub_0204114C
	add r0, r0, #0x59000
	mov r1, #0xa
	mov r2, #0x38
	bl __cxa_vec_cleanup
	add r0, r4, #0x760
	ldr r3, _02015428 ; =sub_0204114C
	add r0, r0, #0x59000
	mov r1, #2
	mov r2, #0x38
	bl __cxa_vec_cleanup
	add r0, r4, #0x328
	add r0, r0, #0x8c00
	bl sub_020412DC
	add r0, r4, #0x2d4
	add r0, r0, #0x8800
	mov r1, #2
	mov r2, #0x38
	ldr r3, _0201542C ; =0x02015120
	bl __cxa_vec_cleanup
	add r0, r4, #4
	add r0, r0, #0x8800
	mov r1, #0x1e
	mov r2, #0x18
	ldr r3, _02015430 ; =0x02015108
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02015428: .word sub_0204114C
_0201542C: .word sub_02015120
_02015430: .word sub_02015108
	arm_func_end sub_020153AC

	arm_func_start sub_02015434
sub_02015434: ; 0x02015434
	stmdb sp!, {r3, r4, r5, lr}
	add r0, r0, #4
	mov ip, #0
	add r4, r0, #0x8800
	mov r3, ip
	arm_func_end sub_02015434
_02015448:
	mov lr, r3
	mov r5, r4
_02015450:
	ldr r0, [r5, #8]
	tst r0, #1
	beq _02015474
	ldrh r0, [r5, #2]
	cmp r1, r0
	ldreqh r0, [r5, #4]
	cmpeq r2, r0
	moveq r0, #1
	ldmeqia sp!, {r3, r4, r5, pc}
_02015474:
	add lr, lr, #1
	cmp lr, #0xa
	add r5, r5, #0x18
	blt _02015450
	add ip, ip, #1
	cmp ip, #3
	add r4, r4, #0xf0
	blt _02015448
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0201549C
sub_0201549C: ; 0x0201549C
	stmdb sp!, {r3, r4, r5, lr}
	mov r2, r1, asr #0x18
	and r2, r2, #0xff
	cmp r2, #5
	cmpne r2, #2
	bne _02015514
	ldr r2, _0201551C ; =0x00000FFF
	mov lr, r0
	and r4, r2, r1, asr #12
	and r5, r1, r2
	mov ip, #0
	arm_func_end sub_0201549C
_020154C8:
	add r1, lr, #0x8000
	ldr r3, [r1, #0xad4]
	cmp r3, #0
	beq _02015504
	ldr r3, [r1, #0xad8]
	and r1, r2, r3, asr #12
	cmp r1, r4
	andeq r1, r3, r2
	cmpeq r1, r5
	bne _02015504
	add r0, r0, #0x2d4
	add r1, r0, #0x8800
	mov r0, #0x38
	mla r0, ip, r0, r1
	ldmia sp!, {r3, r4, r5, pc}
_02015504:
	add ip, ip, #1
	cmp ip, #2
	add lr, lr, #0x38
	blt _020154C8
_02015514:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0201551C: .word 0x00000FFF

	arm_func_start sub_02015520
sub_02015520: ; 0x02015520
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r2, r1, asr #0x18
	and r2, r2, #0xff
	cmp r2, #6
	cmpne r2, #1
	bne _020155F0
	add r2, r0, #0x8000
	ldrb r2, [r2, #0xb64]
	cmp r2, #1
	beq _02015554
	cmp r2, #5
	beq _0201555C
	b _02015564
	arm_func_end sub_02015520
_02015554:
	mov ip, #1
	b _02015568
_0201555C:
	mov ip, #2
	b _02015568
_02015564:
	mov ip, #0
_02015568:
	ldr r3, _020155F8 ; =0x00000FFF
	mov r2, #0
	and lr, r3, r1, asr #12
	and r4, r1, r3
	mov r1, r2
	mov r8, #0xf0
_02015580:
	add r3, ip, r2
	and r3, r3, #3
	mul r6, r3, r8
	mov r3, r1
	add r5, r0, r6
_02015594:
	add r7, r5, #0x8000
	ldr r7, [r7, #0x80c]
	tst r7, #1
	beq _020155D4
	add r7, r5, #0x8800
	ldrh sb, [r7, #6]
	cmp sb, lr
	ldreqh r7, [r7, #8]
	cmpeq r7, r4
	bne _020155D4
	add r0, r0, #4
	add r0, r0, #0x8800
	add r1, r0, r6
	mov r0, #0x18
	mla r0, r3, r0, r1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
_020155D4:
	add r3, r3, #1
	cmp r3, #0xa
	add r5, r5, #0x18
	blt _02015594
	add r2, r2, #1
	cmp r2, #3
	blt _02015580
_020155F0:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_020155F8: .word 0x00000FFF

	arm_func_start sub_020155FC
sub_020155FC: ; 0x020155FC
	cmp r1, #0xa
	bge _02015650
	add r2, r0, #0x8000
	ldrb r2, [r2, #0xb64]
	cmp r2, #1
	beq _02015620
	cmp r2, #5
	beq _02015628
	b _02015630
	arm_func_end sub_020155FC
_02015620:
	mov r3, #1
	b _02015634
_02015628:
	mov r3, #2
	b _02015634
_02015630:
	mov r3, #0
_02015634:
	add r0, r0, #4
	add r2, r0, #0x8800
	mov r0, #0xf0
	mla r2, r3, r0, r2
	mov r0, #0x18
	mla r0, r1, r0, r2
	bx lr
_02015650:
	mov r0, #0
	bx lr

	arm_func_start sub_02015658
sub_02015658: ; 0x02015658
	stmdb sp!, {r4, lr}
	cmp r1, #0xb
	ldrhsb r1, [r0, #3]
	ldr r2, _0201568C ; =DAT_0208b664
	andhs r1, r1, #0xf
	ldrb r4, [r2, r1]
	mvn r1, #0
	bl sub_0201621C
	cmp r0, #0
	addne r0, r4, #1
	andne r4, r0, #0xff
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0201568C: .word DAT_0208b664
	arm_func_end sub_02015658

	arm_func_start sub_02015690
sub_02015690: ; 0x02015690
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _02015710 ; =0x000001B9
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	cmp r2, r3
	cmplt r1, #0x30
	movge r0, #0
	bge _020156E0
	mov r3, #0x18
	mla r3, r2, r3, r0
	mov r0, r1, asr #2
	add r0, r1, r0, lsr #29
	mov r0, r0, asr #3
	add r2, r3, r0, lsl #2
	mov r0, r1, lsl #0x1d
	ldr r1, [r2, #0x30]
	mov r0, r0, lsr #0x1b
	mov r0, r1, lsr r0
	and r0, r0, #0xf
	arm_func_end sub_02015690
_020156E0:
	cmp r0, #4
	addls pc, pc, r0, lsl #2
	b _02015708
_020156EC: ; jump table
	b _02015708 ; case 0
	b _02015708 ; case 1
	b _02015708 ; case 2
	b _02015700 ; case 3
	b _02015700 ; case 4
_02015700:
	mov r0, #1
	bx lr
_02015708:
	mov r0, #0
	bx lr
	.align 2, 0
_02015710: .word 0x000001B9

	arm_func_start sub_02015714
sub_02015714: ; 0x02015714
	stmdb sp!, {r3, lr}
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _02015778 ; =0x000001B9
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	cmp r2, r3
	cmplt r1, #0x30
	ldmgeia sp!, {r3, pc}
	add r3, r0, #0x30
	mov r0, #0x18
	mla r3, r2, r0, r3
	mov r0, r1, asr #2
	mov r2, r1, lsl #0x1d
	add r0, r1, r0, lsr #29
	mov ip, r0, asr #3
	mov lr, r2, lsr #0x1b
	mov r0, #0xf
	mvn r1, r0, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #3
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02015778: .word 0x000001B9
	arm_func_end sub_02015714

	arm_func_start sub_0201577C
sub_0201577C: ; 0x0201577C
	stmdb sp!, {r3, lr}
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _020157E0 ; =0x000001B9
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	cmp r2, r3
	cmplt r1, #0x30
	ldmgeia sp!, {r3, pc}
	add r3, r0, #0x30
	mov r0, #0x18
	mla r3, r2, r0, r3
	mov r0, r1, asr #2
	mov r2, r1, lsl #0x1d
	add r0, r1, r0, lsr #29
	mov ip, r0, asr #3
	mov lr, r2, lsr #0x1b
	mov r0, #0xf
	mvn r1, r0, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #1
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020157E0: .word 0x000001B9
	arm_func_end sub_0201577C

	arm_func_start sub_020157E4
sub_020157E4: ; 0x020157E4
	stmdb sp!, {r3, lr}
	mov r2, r1, asr #0x18
	and ip, r2, #0xff
	cmp ip, #4
	addls pc, pc, ip, lsl #2
	b _020158A8
_020157FC: ; jump table
	b _02015810 ; case 0
	b _02015818 ; case 1
	b _02015818 ; case 2
	b _02015818 ; case 3
	b _020158A8 ; case 4
	arm_func_end sub_020157E4
_02015810:
	mov r0, #1
	ldmia sp!, {r3, pc}
_02015818:
	ldr r3, _020158B0 ; =0x00000FFF
	sub r2, ip, #1
	cmp r2, #3
	and r2, r1, r3
	and lr, r3, r1, asr #12
	movlt r3, #1
	ldr r1, _020158B4 ; =0x000001B9
	movge r3, #0
	cmp lr, r1
	movlt r1, #1
	movge r1, #0
	tst r3, r1
	beq _02015890
	cmp r2, #0x30
	bge _02015890
	ldr r1, _020158B8 ; =0x00001B90
	sub r3, ip, #1
	mla r1, r3, r1, r0
	mov r0, r2, asr #2
	add r0, r2, r0, lsr #29
	add r1, r1, lr, lsl #4
	mov r0, r0, asr #3
	add r0, r1, r0, lsl #2
	add r0, r0, #0x2000
	mov r1, r2, lsl #0x1d
	ldr r2, [r0, #0x988]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #0xf
	b _02015894
_02015890:
	mov r0, #0
_02015894:
	cmp r0, #3
	cmpne r0, #4
	bne _020158A8
	mov r0, #1
	ldmia sp!, {r3, pc}
_020158A8:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020158B0: .word 0x00000FFF
_020158B4: .word 0x000001B9
_020158B8: .word 0x00001B90

	arm_func_start sub_020158BC
sub_020158BC: ; 0x020158BC
	stmdb sp!, {r3, lr}
	mov r2, r1, asr #0x18
	and ip, r2, #0xff
	cmp ip, #4
	addls pc, pc, ip, lsl #2
	ldmia sp!, {r3, pc}
_020158D4: ; jump table
	ldmia sp!, {r3, pc} ; case 0
	b _020158E8 ; case 1
	b _020158E8 ; case 2
	b _020158E8 ; case 3
	ldmia sp!, {r3, pc} ; case 4
	arm_func_end sub_020158BC
_020158E8:
	ldr r2, _02015970 ; =0x00000FFF
	sub r3, ip, #1
	and lr, r1, r2
	and r1, r2, r1, asr #12
	cmp r3, #3
	movlt r3, #1
	ldr r2, _02015974 ; =0x000001B9
	movge r3, #0
	cmp r1, r2
	movlt r2, #1
	movge r2, #0
	tst r3, r2
	ldmeqia sp!, {r3, pc}
	cmp lr, #0x30
	ldmgeia sp!, {r3, pc}
	add r0, r0, #0x188
	add r3, r0, #0x2800
	ldr r2, _02015978 ; =0x00001B90
	sub r0, ip, #1
	mla r3, r0, r2, r3
	mov r0, lr, asr #2
	add r0, lr, r0, lsr #29
	mov r2, lr, lsl #0x1d
	mov lr, r2, lsr #0x1b
	mov ip, r0, asr #3
	mov r2, #0xf
	add r3, r3, r1, lsl #4
	mvn r1, r2, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #3
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02015970: .word 0x00000FFF
_02015974: .word 0x000001B9
_02015978: .word 0x00001B90

	arm_func_start sub_0201597C
sub_0201597C: ; 0x0201597C
	stmdb sp!, {r3, lr}
	mov r2, r1, asr #0x18
	and ip, r2, #0xff
	cmp ip, #4
	addls pc, pc, ip, lsl #2
	ldmia sp!, {r3, pc}
_02015994: ; jump table
	ldmia sp!, {r3, pc} ; case 0
	b _020159A8 ; case 1
	b _020159A8 ; case 2
	b _020159A8 ; case 3
	ldmia sp!, {r3, pc} ; case 4
	arm_func_end sub_0201597C
_020159A8:
	ldr r2, _02015A30 ; =0x00000FFF
	sub r3, ip, #1
	and lr, r1, r2
	and r1, r2, r1, asr #12
	cmp r3, #3
	movlt r3, #1
	ldr r2, _02015A34 ; =0x000001B9
	movge r3, #0
	cmp r1, r2
	movlt r2, #1
	movge r2, #0
	tst r3, r2
	ldmeqia sp!, {r3, pc}
	cmp lr, #0x30
	ldmgeia sp!, {r3, pc}
	add r0, r0, #0x188
	add r3, r0, #0x2800
	ldr r2, _02015A38 ; =0x00001B90
	sub r0, ip, #1
	mla r3, r0, r2, r3
	mov r0, lr, asr #2
	add r0, lr, r0, lsr #29
	mov r2, lr, lsl #0x1d
	mov lr, r2, lsr #0x1b
	mov ip, r0, asr #3
	mov r2, #0xf
	add r3, r3, r1, lsl #4
	mvn r1, r2, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #1
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02015A30: .word 0x00000FFF
_02015A34: .word 0x000001B9
_02015A38: .word 0x00001B90

	arm_func_start sub_02015A3C
sub_02015A3C: ; 0x02015A3C
	stmdb sp!, {r3, lr}
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _02015AA8 ; =0x000001B9
	cmp r2, r3
	movlt r3, #1
	movge r3, #0
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	cmp r1, #0x30
	ldmgeia sp!, {r3, pc}
	mov r3, r1, asr #2
	add ip, r0, #0x188
	mov lr, r1, lsl #0x1d
	add r0, r1, r3, lsr #29
	add r3, ip, #0x2800
	mov ip, r0, asr #3
	add r3, r3, r2, lsl #4
	mov lr, lr, lsr #0x1b
	mov r1, #0xf
	mvn r1, r1, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #3
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02015AA8: .word 0x000001B9
	arm_func_end sub_02015A3C

	arm_func_start sub_02015AAC
sub_02015AAC: ; 0x02015AAC
	stmdb sp!, {r3, lr}
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _02015B18 ; =0x000001B9
	cmp r2, r3
	movlt r3, #1
	movge r3, #0
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	cmp r1, #0x30
	ldmgeia sp!, {r3, pc}
	mov r3, r1, asr #2
	add ip, r0, #0x188
	mov lr, r1, lsl #0x1d
	add r0, r1, r3, lsr #29
	add r3, ip, #0x2800
	mov ip, r0, asr #3
	add r3, r3, r2, lsl #4
	mov lr, lr, lsr #0x1b
	mov r1, #0xf
	mvn r1, r1, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #1
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02015B18: .word 0x000001B9
	arm_func_end sub_02015AAC

	arm_func_start sub_02015B1C
sub_02015B1C: ; 0x02015B1C
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _02015B94 ; =0x000001B9
	cmp r2, r3
	movlt r3, #1
	movge r3, #0
	cmp r3, #0
	beq _02015B74
	cmp r1, #0x30
	bge _02015B74
	mov r3, r1, asr #2
	add r3, r1, r3, lsr #29
	add r2, r0, r2, lsl #4
	mov r0, r3, asr #3
	add r0, r2, r0, lsl #2
	add r0, r0, #0x4000
	mov r1, r1, lsl #0x1d
	ldr r2, [r0, #0x518]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #0xf
	b _02015B78
	arm_func_end sub_02015B1C
_02015B74:
	mov r0, #0
_02015B78:
	cmp r0, #3
	cmpne r0, #4
	bne _02015B8C
	mov r0, #1
	bx lr
_02015B8C:
	mov r0, #0
	bx lr
	.align 2, 0
_02015B94: .word 0x000001B9

	arm_func_start sub_02015B98
sub_02015B98: ; 0x02015B98
	stmdb sp!, {r3, lr}
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _02015C04 ; =0x000001B9
	cmp r2, r3
	movlt r3, #1
	movge r3, #0
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	cmp r1, #0x30
	ldmgeia sp!, {r3, pc}
	mov r3, r1, asr #2
	add ip, r0, #0x118
	mov lr, r1, lsl #0x1d
	add r0, r1, r3, lsr #29
	add r3, ip, #0x4400
	mov ip, r0, asr #3
	add r3, r3, r2, lsl #4
	mov lr, lr, lsr #0x1b
	mov r1, #0xf
	mvn r1, r1, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #3
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02015C04: .word 0x000001B9
	arm_func_end sub_02015B98

	arm_func_start sub_02015C08
sub_02015C08: ; 0x02015C08
	stmdb sp!, {r3, lr}
	cmp r2, #0
	ldrlth r2, [r0, #0x1a]
	ldr r3, _02015C74 ; =0x000001B9
	cmp r2, r3
	movlt r3, #1
	movge r3, #0
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	cmp r1, #0x30
	ldmgeia sp!, {r3, pc}
	mov r3, r1, asr #2
	add ip, r0, #0x118
	mov lr, r1, lsl #0x1d
	add r0, r1, r3, lsr #29
	add r3, ip, #0x4400
	mov ip, r0, asr #3
	add r3, r3, r2, lsl #4
	mov lr, lr, lsr #0x1b
	mov r1, #0xf
	mvn r1, r1, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #1
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02015C74: .word 0x000001B9
	arm_func_end sub_02015C08

	arm_func_start sub_02015C78
sub_02015C78: ; 0x02015C78
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0xdc
	mov sb, r1
	mov r1, sb, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	mov r5, r0
	mov r8, r2
	addne sp, sp, #0xdc
	movne r0, #0
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, pc}
	cmp r3, #0
	addlt r0, r5, #0x8000
	ldrltb r3, [r0, #0xb64]
	cmp r3, #1
	beq _02015CC4
	cmp r3, #5
	beq _02015CCC
	b _02015CD4
	arm_func_end sub_02015C78
_02015CC4:
	mov r1, #1
	b _02015CD8
_02015CCC:
	mov r1, #2
	b _02015CD8
_02015CD4:
	mov r1, #0
_02015CD8:
	mov r0, #0xf0
	mul r4, r1, r0
	add r0, r5, #4
	add r0, r0, #0x8800
	add r7, r0, r4
	mov r6, #0
_02015CF0:
	ldr r0, [r7, #8]
	tst r0, #1
	bne _02015E2C
	mov r0, r7
	bl sub_020150B8
	ldr r1, _02015E48 ; =0x00000FFF
	ldr r2, [r7, #8]
	mov r0, r8, lsl #0x10
	orr r2, r2, #1
	str r2, [r7, #8]
	mov r0, r0, lsr #0x10
	strh r0, [r7]
	and r2, r1, sb, asr #12
	strh r2, [r7, #2]
	and r1, sb, r1
	strh r1, [r7, #4]
	ldrsh r1, [r5, #0x26]
	strh r1, [r7, #0x16]
	bl sub_02034F9C
	cmp r0, #0
	beq _02015E20
	ldr r0, [r7, #8]
	cmp r6, #0
	orr r0, r0, #6
	str r0, [r7, #8]
	ble _02015E20
	ldr r8, _02015E4C ; =0x02015108
	ldr r3, _02015E50 ; =sub_020150F4
	add r0, sp, #4
	mov r1, #9
	mov r2, #0x18
	str r8, [sp]
	bl __cxa_vec_ctor
	mov r0, #0x18
	mul sb, r6, r0
	add r0, r5, #4
	add r6, r0, #0x8800
	add r8, r6, r4
	add r1, sp, #4
	mov r0, r8
	mov r2, sb
	bl MI_CpuCopy8
	ldrh r1, [r7]
	add r0, r5, #0xc
	add r3, r0, #0x8800
	add r0, r5, #0x1c
	strh r1, [r6, r4]
	add r0, r0, #0x8800
	add r1, r0, r4
	ldrh r0, [r7, #2]
	mov r2, sb
	mov r6, #0
	strh r0, [r8, #2]
	ldrh r5, [r7, #4]
	add r0, sp, #4
	strh r5, [r8, #4]
	ldr r5, [r7, #8]
	str r5, [r8, #8]
	ldr sb, [r7, #0xc]
	ldr r5, [r7, #0x10]
	str sb, [r8, #0xc]
	str r5, [r8, #0x10]
	ldrh r5, [r7, #0x14]
	strh r5, [r8, #0x14]
	ldrh r5, [r7, #0x16]
	strh r5, [r8, #0x16]
	str r6, [r3, r4]
	ldr r5, [r7, #8]
	orr r5, r5, #0
	str r5, [r3, r4]
	bl MI_CpuCopy8
	ldr r3, _02015E4C ; =0x02015108
	add r0, sp, #4
	mov r1, #9
	mov r2, #0x18
	bl __cxa_vec_cleanup
_02015E20:
	add sp, sp, #0xdc
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
_02015E2C:
	add r6, r6, #1
	cmp r6, #0xa
	add r7, r7, #0x18
	blt _02015CF0
	mov r0, #0
	add sp, sp, #0xdc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02015E48: .word 0x00000FFF
_02015E4C: .word sub_02015108
_02015E50: .word sub_020150F4

	arm_func_start sub_02015E54
sub_02015E54: ; 0x02015E54
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r2, r1, asr #0x18
	and r2, r2, #0xff
	cmp r2, #5
	cmpne r2, #2
	bne _02015EC8
	add r0, r0, #0x2d4
	mov r4, #0
	add r6, r0, #0x8800
	mov r3, r4
	mov r0, r4
	arm_func_end sub_02015E54
_02015E80:
	cmp r4, #0
	blt _02015E94
	cmp r4, #2
	movlt r5, r6
	blt _02015E98
_02015E94:
	mov r5, r3
_02015E98:
	cmp r5, #0
	ldrne r2, [r5]
	cmpne r2, #0
	beq _02015EB4
	ldr r2, [r5, #4]
	cmp r1, r2
	streq r0, [r5]
_02015EB4:
	add r4, r4, #1
	cmp r4, #2
	add r6, r6, #0x38
	blt _02015E80
	b _0201601C
_02015EC8:
	cmp r2, #6
	cmpne r2, #1
	bne _0201601C
	mvn r2, #0
	add r3, r2, #0x1000
	mov r4, r3
	mov r6, #0
	and ip, r1, r4
	mov r5, r2
	mov r8, r0
	and sb, r3, r1, asr #12
	mov r4, r6
_02015EF8:
	mov r7, r4
	mov lr, r8
_02015F00:
	add r1, lr, #0x8800
	ldrh r3, [r1, #6]
	cmp r3, sb
	ldreqh r1, [r1, #8]
	cmpeq r1, ip
	moveq r2, r6
	moveq r5, r7
	beq _02015F30
	add r7, r7, #1
	cmp r7, #0xa
	add lr, lr, #0x18
	blt _02015F00
_02015F30:
	cmp r2, #0
	bge _02015F48
	add r6, r6, #1
	cmp r6, #3
	add r8, r8, #0xf0
	blt _02015EF8
_02015F48:
	cmp r5, #9
	bne _02015F68
	add r0, r0, #0xdc
	add r1, r0, #0x8800
	mov r0, #0xf0
	mla r0, r2, r0, r1
	bl sub_020150B8
	b _0201601C
_02015F68:
	cmp r5, #0
	blt _0201601C
	cmp r5, #9
	bge _0201601C
	add r0, r0, #4
	add r1, r0, #0x8800
	mov r0, #0xf0
	mla r8, r2, r0, r1
	mov r0, #0x18
	mla r7, r5, r0, r8
	mov r4, #0
	mov sb, r0
_02015F98:
	add r0, r5, #1
	mla r6, r0, sb, r8
	mov r0, r7
	bl sub_020150B8
	ldr r0, [r6, #8]
	tst r0, #1
	beq _02016004
	ldrh r0, [r6]
	strh r0, [r7]
	ldrh r0, [r6, #2]
	strh r0, [r7, #2]
	ldrh r0, [r6, #4]
	strh r0, [r7, #4]
	ldr r0, [r6, #8]
	str r0, [r7, #8]
	ldr r1, [r6, #0xc]
	ldr r0, [r6, #0x10]
	str r1, [r7, #0xc]
	str r0, [r7, #0x10]
	ldrh r0, [r6, #0x14]
	strh r0, [r7, #0x14]
	ldrh r0, [r6, #0x16]
	strh r0, [r7, #0x16]
	str r4, [r7, #8]
	ldr r0, [r6, #8]
	orr r0, r4, r0
	str r0, [r7, #8]
_02016004:
	mov r0, r6
	bl sub_020150B8
	add r5, r5, #1
	cmp r5, #9
	add r7, r7, #0x18
	blt _02015F98
_0201601C:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start sub_02016024
sub_02016024: ; 0x02016024
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r3, r4, #0x7000
	ldr r1, [r3, #0xf60]
	add r0, r4, #0x36c
	bic ip, r1, #1
	add r1, r0, #0x7c00
	mov r0, #0
	mov r2, #0x80
	str ip, [r3, #0xf60]
	bl MIi_CpuClearFast
	add r0, r4, #0x3ec
	add r1, r0, #0x7c00
	mov r0, #0
	mov r2, #0x80
	bl MIi_CpuClearFast
	add r0, r4, #0x6c
	add r1, r0, #0x8000
	mov r0, #0
	mov r2, #0x80
	bl MIi_CpuClearFast
	add r0, r4, #0xec
	add r1, r0, #0x8000
	mov r0, #0
	mov r2, #0x40
	bl MIi_CpuClearFast
	mov r0, #0
	add r1, r4, #0x12c
	add r1, r1, #0x8000
	mov r2, #0x40
	bl MIi_CpuClearFast
	add r0, r4, #0x16c
	add r1, r0, #0x8000
	mov r0, #0
	mov r2, #0x40
	bl MIi_CpuClearFast
	ldmia sp!, {r4, pc}
	arm_func_end sub_02016024

	arm_func_start sub_020160B8
sub_020160B8: ; 0x020160B8
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	add r0, r4, #0x8000
	ldrb r2, [r0, #0x7db]
	mov r5, r1
	cmp r2, r5
	ldmeqia sp!, {r3, r4, r5, pc}
	strb r5, [r0, #0x7db]
	bl _ZN5CGame11GetInstanceEv
	cmp r0, #0
	moveq r0, #0
	beq _020160FC
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x438]
	mov r1, r5
	bl sub_02010E78
	arm_func_end sub_020160B8
_020160FC:
	strb r0, [r4, #2]
	mov r0, r4
	mov r1, #0x15
	bl sub_02016C14
	cmp r0, #1
	bne _02016124
	ldrb r0, [r4, #2]
	add r0, r0, #5
	strb r0, [r4, #2]
	ldmia sp!, {r3, r4, r5, pc}
_02016124:
	cmp r0, #2
	ldrgeb r0, [r4, #2]
	addge r0, r0, #0xf
	strgeb r0, [r4, #2]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02016138
sub_02016138: ; 0x02016138
	cmp r1, #0
	blt _02016148
	cmp r1, #3
	blt _02016178
	arm_func_end sub_02016138
_02016148:
	add r1, r0, #0x8000
	ldrb r1, [r1, #0xb64]
	cmp r1, #1
	beq _02016164
	cmp r1, #5
	beq _0201616C
	b _02016174
_02016164:
	mov r1, #1
	b _02016178
_0201616C:
	mov r1, #2
	b _02016178
_02016174:
	mov r1, #0
_02016178:
	mov r2, #0xf0
	mla r3, r1, r2, r0
	mov r0, #0
	mov r2, r0
_02016188:
	add r1, r3, #0x8000
	ldr r1, [r1, #0x80c]
	add r2, r2, #1
	tst r1, #1
	addne r0, r0, #1
	cmp r2, #0xa
	add r3, r3, #0x18
	blt _02016188
	bx lr

	arm_func_start sub_020161AC
sub_020161AC: ; 0x020161AC
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r2
	bl sub_02015658
	mov r4, r0
	mov r0, r6
	mov r1, r5
	bl sub_0201621C
	cmp r0, #0
	subne r4, r4, #1
	cmp r4, #0
	movlt r4, #0
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end sub_020161AC

	arm_func_start sub_020161E4
sub_020161E4: ; 0x020161E4
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	bl sub_02016138
	mov r4, r0
	mov r0, r6
	mov r1, r5
	bl sub_0201621C
	cmp r0, #0
	subne r4, r4, #1
	cmp r4, #0
	movlt r4, #0
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end sub_020161E4

	arm_func_start sub_0201621C
sub_0201621C: ; 0x0201621C
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	bl sub_02016138
	mov r4, r0
	cmp r4, #0
	mov r5, #0
	ble _02016260
	arm_func_end sub_0201621C
_02016238:
	mov r0, r6
	mov r1, r5
	bl sub_020155FC
	ldr r0, [r0, #8]
	tst r0, #2
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
	add r5, r5, #1
	cmp r5, r4
	blt _02016238
_02016260:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_02016268
sub_02016268: ; 0x02016268
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	bl sub_02016138
	mov r4, r0
	cmp r4, #0
	mov r5, #0
	ble _020162B4
	arm_func_end sub_02016268
_02016284:
	mov r0, r6
	mov r1, r5
	bl sub_020155FC
	ldr r1, [r0, #8]
	tst r1, #2
	beq _020162A8
	ldrh r0, [r0]
	bl sub_02035088
	ldmia sp!, {r4, r5, r6, pc}
_020162A8:
	add r5, r5, #1
	cmp r5, r4
	blt _02016284
_020162B4:
	mvn r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_020162BC
sub_020162BC: ; 0x020162BC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r2, r5, #0x7000
	mov r4, r1
	ldr r1, [r2, #0xc38]
	bl sub_02015520
	cmp r0, #0
	ldrne r1, [r0, #8]
	add r2, r5, #0x7000
	bicne r1, r1, #4
	strne r1, [r0, #8]
	mov r0, r5
	mov r1, r4
	str r4, [r2, #0xc38]
	bl sub_02015520
	cmp r0, #0
	ldrne r1, [r0, #8]
	orrne r1, r1, #4
	strne r1, [r0, #8]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_020162BC
