    .include "macros.inc"
    .include "include/arm9_02010470.inc"

    .text

	arm_func_start _ZN17UnkClass_02010470C1Em
_ZN17UnkClass_02010470C1Em: ; 0x02010470
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	mov r0, #0x20
	mov r4, r1
	bl _Znwm
	movs r8, r0
	beq _02010498
	mov r1, r4
	bl _ZN17UnkClass_0200D114C1Em
	mov r8, r0
	arm_func_end _ZN17UnkClass_02010470C1Em
_02010498:
	ldr r1, _020107A4 ; =s_data_param_PokeID_bin_0208ab84
	mov r0, r8
	bl _ZN17UnkClass_0200D11412sub_0200D148EPKc
	mov r0, r8
	bl _ZN17UnkClass_0200D11412sub_0200D390Ev
	strh r0, [sl]
	ldrh r1, [sl]
	mov r0, #0x18
	mul r0, r1, r0
	bl _Znam
	str r0, [sl, #4]
	mov r7, #0
	str r7, [sp]
	ldrh r0, [sl]
	cmp r0, #0
	ble _02010784
	mov sb, r7
	add r5, sp, #0
	mov r6, #1
	mov r4, #2
	mov fp, #4
_020104EC:
	mov r0, r8
	mov r1, r7
	mov r2, r6
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r2, [sp]
	ldr r1, [sl, #4]
	mov r0, r8
	strh r2, [r1, sb]
	mov r1, r7
	mov r2, r4
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #2]
	mov r0, r8
	mov r1, r7
	mov r2, fp
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #3]
	mov r0, r8
	mov r1, r7
	mov r2, #5
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #4]
	mov r0, r8
	mov r1, r7
	mov r2, #6
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #5]
	mov r0, r8
	mov r1, r7
	mov r2, #7
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #6]
	mov r0, r8
	mov r1, r7
	mov r2, #8
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #7]
	mov r0, r8
	mov r1, r7
	mov r2, #9
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r0, [sl, #4]
	ldr r1, [sp]
	add r0, r0, sb
	strb r1, [r0, #8]
	mov r0, r8
	mov r1, r7
	mov r2, #0xa
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #9]
	mov r0, r8
	mov r1, r7
	mov r2, #0xb
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #0xa]
	mov r0, r8
	mov r1, r7
	mov r2, #0xc
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #0xb]
	mov r0, r8
	mov r1, r7
	mov r2, #0xd
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #0xc]
	mov r0, r8
	mov r1, r7
	mov r2, #0xe
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #0xd]
	mov r0, r8
	mov r1, r7
	mov r2, #0xf
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #0xe]
	mov r0, r8
	mov r1, r7
	mov r2, #0x10
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strb r2, [r1, #0xf]
	mov r0, r8
	mov r1, r7
	mov r2, #0x15
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strh r2, [r1, #0x10]
	mov r0, r8
	mov r1, r7
	mov r2, #0x16
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r1, [sl, #4]
	ldr r2, [sp]
	add r1, r1, sb
	strh r2, [r1, #0x12]
	mov r0, r8
	mov r1, r7
	mov r2, #0x17
	mov r3, r5
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r0, [sl, #4]
	ldr r1, [sp]
	add r0, r0, sb
	str r1, [r0, #0x14]
	ldrh r0, [sl]
	add r7, r7, #1
	add sb, sb, #0x18
	cmp r7, r0
	blt _020104EC
_02010784:
	cmp r8, #0
	beq _0201079C
	mov r0, r8
	bl _ZN17UnkClass_0200D114D1Ev
	mov r0, r8
	bl _ZdlPv
_0201079C:
	mov r0, sl
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_020107A4: .word s_data_param_PokeID_bin_0208ab84

	arm_func_start sub_020107A8
sub_020107A8: ; 0x020107A8
	ldrh r2, [r0]
	cmp r1, r2
	movhs r0, #0
	ldrlo r2, [r0, #4]
	movlo r0, #0x18
	mlalo r0, r1, r0, r2
	bx lr
	arm_func_end sub_020107A8

	arm_func_start sub_020107C4
sub_020107C4: ; 0x020107C4
	cmp r0, #0x18
	addls pc, pc, r0, lsl #2
	b _0201084C
_020107D0: ; jump table
	b _0201084C ; case 0
	b _02010834 ; case 1
	b _02010834 ; case 2
	b _02010834 ; case 3
	b _02010834 ; case 4
	b _02010834 ; case 5
	b _02010834 ; case 6
	b _02010834 ; case 7
	b _02010834 ; case 8
	b _0201083C ; case 9
	b _0201083C ; case 10
	b _0201083C ; case 11
	b _0201083C ; case 12
	b _02010844 ; case 13
	b _02010844 ; case 14
	b _02010844 ; case 15
	b _02010844 ; case 16
	b _02010844 ; case 17
	b _02010844 ; case 18
	b _02010844 ; case 19
	b _02010844 ; case 20
	b _02010844 ; case 21
	b _02010844 ; case 22
	b _02010844 ; case 23
	b _02010844 ; case 24
	arm_func_end sub_020107C4
_02010834:
	mov r0, #1
	bx lr
_0201083C:
	mov r0, #2
	bx lr
_02010844:
	mov r0, #3
	bx lr
_0201084C:
	mov r0, #0
	bx lr

	arm_func_start _ZN17UnkClass_02010854C1Ev
_ZN17UnkClass_02010854C1Ev: ; 0x02010854
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02010868
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_02010854C1Ev

	arm_func_start sub_02010868
sub_02010868: ; 0x02010868
	stmdb sp!, {r3, lr}
	mov r1, #0x22
	str r1, [r0]
	mov r1, #0xa
	strb r1, [r0, #4]
	mov r1, #1
	mov ip, #0
	strb r1, [r0, #5]
	strb ip, [r0, #6]
	str ip, [r0, #8]
	str ip, [r0, #0xc]
	str ip, [r0, #0x10]
	strb ip, [r0, #0x14]
	mov r3, #0xff
	mov lr, ip
	arm_func_end sub_02010868
_020108A4:
	add r2, r0, ip, lsl #1
	add r1, r0, ip
	strh r3, [r2, #0x16]
	add ip, ip, #1
	strb lr, [r1, #0x26]
	cmp ip, #8
	blt _020108A4
	strb lr, [r0, #0x40]
	mov r2, #0xff
_020108C8:
	add r1, r0, lr
	add lr, lr, #1
	strb r2, [r1, #0x41]
	cmp lr, #8
	blt _020108C8
	mov lr, #0
	ldr ip, _02010948 ; =0x0000FFFF
	strb lr, [r0, #0x2e]
	mov r2, lr
_020108EC:
	add r3, r0, lr, lsl #1
	add r1, r0, lr
	strh ip, [r3, #0x30]
	strb r2, [r1, #0x38]
	add lr, lr, #1
	strb r2, [r1, #0x3c]
	cmp lr, #4
	blt _020108EC
	strb r2, [r0, #0x49]
	strb r2, [r0, #0x4a]
	strb r2, [r0, #0x4b]
	strb r2, [r0, #0x4c]
	strb r2, [r0, #0x4d]
	strb r2, [r0, #0x4e]
	mov r1, #1
	strb r1, [r0, #0x4f]
	strb r1, [r0, #0x50]
	strb r2, [r0, #0x51]
	strb r2, [r0, #0x52]
	strb r2, [r0, #0x54]
	strh r2, [r0, #0x56]
	strb r2, [r0, #0x58]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02010948: .word 0x0000FFFF

	arm_func_start sub_0201094C
sub_0201094C: ; 0x0201094C
	str r1, [r0]
	bx lr
	arm_func_end sub_0201094C

	arm_func_start sub_02010954
sub_02010954: ; 0x02010954
	strb r1, [r0, #4]
	bx lr
	arm_func_end sub_02010954

	arm_func_start sub_0201095C
sub_0201095C: ; 0x0201095C
	strb r1, [r0, #5]
	bx lr
	arm_func_end sub_0201095C

	arm_func_start sub_02010964
sub_02010964: ; 0x02010964
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	strb r1, [r0, #6]
	bx lr
	arm_func_end sub_02010964

	arm_func_start sub_02010978
sub_02010978: ; 0x02010978
	str r1, [r0, #8]
	bx lr
	arm_func_end sub_02010978

	arm_func_start sub_02010980
sub_02010980: ; 0x02010980
	str r1, [r0, #0xc]
	bx lr
	arm_func_end sub_02010980

	arm_func_start sub_02010988
sub_02010988: ; 0x02010988
	str r1, [r0, #0x10]
	bx lr
	arm_func_end sub_02010988

	arm_func_start sub_02010990
sub_02010990: ; 0x02010990
	ldrb r3, [r0, #0x14]
	cmp r3, #8
	bxhs lr
	add r3, r0, r3, lsl #1
	strh r1, [r3, #0x16]
	ldrb r1, [r0, #0x14]
	add r1, r0, r1
	strb r2, [r1, #0x26]
	ldrb r1, [r0, #0x14]
	add r1, r1, #1
	strb r1, [r0, #0x14]
	bx lr
	arm_func_end sub_02010990

	arm_func_start sub_020109C0
sub_020109C0: ; 0x020109C0
	stmdb sp!, {r4, lr}
	ldrb r3, [r0, #0x40]
	cmp r3, #8
	ldmhsia sp!, {r4, pc}
	ldrb r4, [r0, #0x2e]
	mov r3, #0xff
	mov lr, #0
	cmp r4, #0
	bls _02010A14
	arm_func_end sub_020109C0
_020109E4:
	add ip, r0, lr, lsl #1
	ldrh ip, [ip, #0x30]
	cmp r1, ip
	addeq ip, r0, lr
	ldreqb ip, [ip, #0x38]
	cmpeq r2, ip
	moveq r3, lr
	beq _02010A14
	add ip, lr, #1
	and lr, ip, #0xff
	cmp lr, r4
	blo _020109E4
_02010A14:
	cmp r3, #0xff
	bne _02010A44
	cmp r4, #4
	ldmhsia sp!, {r4, pc}
	add r3, r0, r4, lsl #1
	strh r1, [r3, #0x30]
	add r1, r0, r4
	strb r2, [r1, #0x38]
	ldrb r1, [r0, #0x2e]
	mov r3, r4
	add r1, r1, #1
	strb r1, [r0, #0x2e]
_02010A44:
	add r2, r0, #0x3c
	ldrb r1, [r2, r3]
	add r1, r1, #1
	strb r1, [r2, r3]
	ldrb r1, [r0, #0x40]
	add r1, r0, r1
	strb r3, [r1, #0x41]
	ldrb r1, [r0, #0x40]
	add r1, r1, #1
	strb r1, [r0, #0x40]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02010A70
sub_02010A70: ; 0x02010A70
	strb r1, [r0, #0x49]
	ldrb r1, [r0, #0x58]
	orr r1, r1, #1
	strb r1, [r0, #0x58]
	bx lr
	arm_func_end sub_02010A70

	arm_func_start sub_02010A84
sub_02010A84: ; 0x02010A84
	strb r1, [r0, #0x4a]
	ldrb r1, [r0, #0x58]
	orr r1, r1, #2
	strb r1, [r0, #0x58]
	bx lr
	arm_func_end sub_02010A84

	arm_func_start sub_02010A98
sub_02010A98: ; 0x02010A98
	strb r1, [r0, #0x4b]
	bx lr
	arm_func_end sub_02010A98

	arm_func_start sub_02010AA0
sub_02010AA0: ; 0x02010AA0
	strb r1, [r0, #0x4c]
	bx lr
	arm_func_end sub_02010AA0

	arm_func_start sub_02010AA8
sub_02010AA8: ; 0x02010AA8
	strb r1, [r0, #0x4d]
	bx lr
	arm_func_end sub_02010AA8

	arm_func_start sub_02010AB0
sub_02010AB0: ; 0x02010AB0
	strb r1, [r0, #0x4e]
	ldrb r1, [r0, #0x58]
	orr r1, r1, #4
	strb r1, [r0, #0x58]
	bx lr
	arm_func_end sub_02010AB0

	arm_func_start sub_02010AC4
sub_02010AC4: ; 0x02010AC4
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	strb r1, [r0, #0x4f]
	bx lr
	arm_func_end sub_02010AC4

	arm_func_start sub_02010AD8
sub_02010AD8: ; 0x02010AD8
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	strb r1, [r0, #0x50]
	bx lr
	arm_func_end sub_02010AD8

	arm_func_start sub_02010AEC
sub_02010AEC: ; 0x02010AEC
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	strb r1, [r0, #0x51]
	bx lr
	arm_func_end sub_02010AEC

	arm_func_start sub_02010B00
sub_02010B00: ; 0x02010B00
	strb r1, [r0, #0x52]
	bx lr
	arm_func_end sub_02010B00

	arm_func_start sub_02010B08
sub_02010B08: ; 0x02010B08
	strb r1, [r0, #0x54]
	bx lr
	arm_func_end sub_02010B08

	arm_func_start sub_02010B10
sub_02010B10: ; 0x02010B10
	strh r1, [r0, #0x56]
	ldrb r1, [r0, #0x58]
	orr r1, r1, #8
	strb r1, [r0, #0x58]
	bx lr
	arm_func_end sub_02010B10

	arm_func_start sub_02010B24
sub_02010B24: ; 0x02010B24
	ldr r0, [r0]
	bx lr
	arm_func_end sub_02010B24

	arm_func_start sub_02010B2C
sub_02010B2C: ; 0x02010B2C
	ldrb r0, [r0, #4]
	bx lr
	arm_func_end sub_02010B2C

	arm_func_start sub_02010B34
sub_02010B34: ; 0x02010B34
	ldrb r0, [r0, #5]
	bx lr
	arm_func_end sub_02010B34

	arm_func_start sub_02010B3C
sub_02010B3C: ; 0x02010B3C
	ldrb r0, [r0, #6]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end sub_02010B3C

	arm_func_start sub_02010B50
sub_02010B50: ; 0x02010B50
	ldr r0, [r0, #8]
	bx lr
	arm_func_end sub_02010B50

	arm_func_start sub_02010B58
sub_02010B58: ; 0x02010B58
	ldr r0, [r0, #0xc]
	bx lr
	arm_func_end sub_02010B58

	arm_func_start sub_02010B60
sub_02010B60: ; 0x02010B60
	ldr r0, [r0, #0x10]
	bx lr
	arm_func_end sub_02010B60

	arm_func_start sub_02010B68
sub_02010B68: ; 0x02010B68
	ldrb r0, [r0, #0x2e]
	bx lr
	arm_func_end sub_02010B68

	arm_func_start sub_02010B70
sub_02010B70: ; 0x02010B70
	add r0, r0, r1, lsl #1
	ldrh r0, [r0, #0x30]
	bx lr
	arm_func_end sub_02010B70

	arm_func_start sub_02010B7C
sub_02010B7C: ; 0x02010B7C
	ldrb r0, [r0, #0x40]
	bx lr
	arm_func_end sub_02010B7C

	arm_func_start sub_02010B84
sub_02010B84: ; 0x02010B84
	add r0, r0, r1
	ldrb r0, [r0, #0x41]
	bx lr
	arm_func_end sub_02010B84

	arm_func_start sub_02010B90
sub_02010B90: ; 0x02010B90
	ldrb r0, [r0, #0x14]
	bx lr
	arm_func_end sub_02010B90

	arm_func_start sub_02010B98
sub_02010B98: ; 0x02010B98
	add r0, r0, r1, lsl #1
	ldrh r0, [r0, #0x16]
	bx lr
	arm_func_end sub_02010B98

	arm_func_start sub_02010BA4
sub_02010BA4: ; 0x02010BA4
	add r0, r0, r1
	ldrb r0, [r0, #0x26]
	bx lr
	arm_func_end sub_02010BA4

	arm_func_start sub_02010BB0
sub_02010BB0: ; 0x02010BB0
	ldrb r0, [r0, #0x49]
	bx lr
	arm_func_end sub_02010BB0

	arm_func_start sub_02010BB8
sub_02010BB8: ; 0x02010BB8
	ldrb r0, [r0, #0x4a]
	bx lr
	arm_func_end sub_02010BB8

	arm_func_start sub_02010BC0
sub_02010BC0: ; 0x02010BC0
	ldrb r0, [r0, #0x4b]
	bx lr
	arm_func_end sub_02010BC0

	arm_func_start sub_02010BC8
sub_02010BC8: ; 0x02010BC8
	ldrb r0, [r0, #0x4c]
	bx lr
	arm_func_end sub_02010BC8

	arm_func_start sub_02010BD0
sub_02010BD0: ; 0x02010BD0
	ldrb r0, [r0, #0x4d]
	bx lr
	arm_func_end sub_02010BD0

	arm_func_start sub_02010BD8
sub_02010BD8: ; 0x02010BD8
	ldrb r0, [r0, #0x4e]
	bx lr
	arm_func_end sub_02010BD8

	arm_func_start sub_02010BE0
sub_02010BE0: ; 0x02010BE0
	ldrb r0, [r0, #0x4f]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end sub_02010BE0

	arm_func_start sub_02010BF4
sub_02010BF4: ; 0x02010BF4
	ldrb r0, [r0, #0x50]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end sub_02010BF4

	arm_func_start sub_02010C08
sub_02010C08: ; 0x02010C08
	ldrb r0, [r0, #0x51]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end sub_02010C08

	arm_func_start sub_02010C1C
sub_02010C1C: ; 0x02010C1C
	ldrb r0, [r0, #0x52]
	bx lr
	arm_func_end sub_02010C1C

	arm_func_start sub_02010C24
sub_02010C24: ; 0x02010C24
	ldrb r0, [r0, #0x58]
	bx lr
	arm_func_end sub_02010C24

	arm_func_start sub_02010C2C
sub_02010C2C: ; 0x02010C2C
	ldrb r0, [r0, #0x54]
	bx lr
	arm_func_end sub_02010C2C

	arm_func_start sub_02010C34
sub_02010C34: ; 0x02010C34
	ldrh r0, [r0, #0x56]
	bx lr
	arm_func_end sub_02010C34

	arm_func_start _ZN17UnkClass_02010C3CC1Ev
_ZN17UnkClass_02010C3CC1Ev: ; 0x02010C3C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02010C50
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_02010C3CC1Ev

	arm_func_start sub_02010C50
sub_02010C50: ; 0x02010C50
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r1, _02010C8C ; =MAIN_BSS_020AF35C
	mov r7, r0
	bl sub_02010C94
	ldr r5, _02010C90 ; =MAIN_BSS_020AF3CE
	mov r6, #0
	mov r4, #0x72
	arm_func_end sub_02010C50
_02010C6C:
	mla r1, r6, r4, r5
	mov r0, r7
	bl sub_02010C94
	add r0, r6, #1
	and r6, r0, #0xff
	cmp r6, #4
	blo _02010C6C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02010C8C: .word MAIN_BSS_020AF35C
_02010C90: .word MAIN_BSS_020AF3CE

	arm_func_start sub_02010C94
sub_02010C94: ; 0x02010C94
	stmdb sp!, {r4, lr}
	mov r4, r1
	mov r0, r4
	mov r1, #0
	mov r2, #0x72
	bl MI_CpuFill8
	mov r0, #1
	strh r0, [r4, #0x4c]
	strh r0, [r4, #0x6c]
	strh r0, [r4, #0x6e]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02010C94

	arm_func_start sub_02010CC0
sub_02010CC0: ; 0x02010CC0
	ldr r0, _02010CC8 ; =MAIN_BSS_020AF3CE
	bx lr
	.align 2, 0
_02010CC8: .word MAIN_BSS_020AF3CE
	arm_func_end sub_02010CC0

	arm_func_start _ZN22CBattleResultParameterC1Ev
_ZN22CBattleResultParameterC1Ev: ; 0x02010CCC
	stmdb sp!, {r4, lr}
	ldr r1, _02010CE8 ; =PTR_LAB_0208abac
	mov r4, r0
	str r1, [r4]
	bl sub_02010D04
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02010CE8: .word PTR_LAB_0208abac
	arm_func_end _ZN22CBattleResultParameterC1Ev

	arm_func_start CBattleResultParameter_complete_obj_dtor
CBattleResultParameter_complete_obj_dtor: ; 0x02010CEC
	bx lr
	arm_func_end CBattleResultParameter_complete_obj_dtor

	arm_func_start CBattleResultParameter_deleting_obj_dtor
CBattleResultParameter_deleting_obj_dtor: ; 0x02010CF0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end CBattleResultParameter_deleting_obj_dtor

	arm_func_start sub_02010D04
sub_02010D04: ; 0x02010D04
	stmdb sp!, {r4, lr}
	mov r1, #0
	mov r2, #0x80
	mov r4, r0
	bl MI_CpuFill8
	mov r0, #0xff
	strb r0, [r4, #4]
	mov r0, #0
	str r0, [r4, #8]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02010D04

	arm_func_start _ZN17UnkClass_02010D2CC1Ei
_ZN17UnkClass_02010D2CC1Ei: ; 0x02010D2C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #4
	mov sl, r0
	mov r0, #0x20
	mov r4, r1
	bl _Znwm
	movs sb, r0
	beq _02010D58
	mov r1, r4
	bl _ZN17UnkClass_0200D114C1Em
	mov sb, r0
	arm_func_end _ZN17UnkClass_02010D2CC1Ei
_02010D58:
	ldr r1, _02010E5C ; =s_data_param_DiskHP_bin_0208ac04
	mov r0, sb
	bl _ZN17UnkClass_0200D11412sub_0200D148EPKc
	mov r0, sb
	bl _ZN17UnkClass_0200D11412sub_0200D390Ev
	strb r0, [sl]
	and r0, r0, #0xff
	bl _Znam
	str r0, [sl, #4]
	ldrb r0, [sl]
	mov r0, r0, lsl #1
	bl _Znam
	str r0, [sl, #8]
	ldrb r0, [sl]
	mov r0, r0, lsl #1
	bl _Znam
	str r0, [sl, #0xc]
	mov r8, #0
	str r8, [sp]
	ldrb r0, [sl]
	cmp r0, #0
	ble _02010E38
	mov r7, #1
	add r6, sp, #0
	mov r5, #2
	mov r4, #3
_02010DC0:
	mov r0, sb
	mov r1, r8
	mov r2, r7
	mov r3, r6
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r2, [sp]
	ldr r1, [sl, #4]
	mov r0, sb
	strb r2, [r1, r8]
	mov r1, r8
	mov r2, r5
	mov r3, r6
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r2, [sp]
	ldr r1, [sl, #8]
	mov r0, r8, lsl #1
	strh r2, [r1, r0]
	mov r0, sb
	mov r1, r8
	mov r2, r4
	mov r3, r6
	bl _ZN17UnkClass_0200D11412sub_0200D3B8EiiPm
	ldr r2, [sp]
	ldr r1, [sl, #0xc]
	mov r0, r8, lsl #1
	strh r2, [r1, r0]
	add r8, r8, #1
	ldrb r0, [sl]
	cmp r8, r0
	blt _02010DC0
_02010E38:
	cmp sb, #0
	beq _02010E50
	mov r0, sb
	bl _ZN17UnkClass_0200D114D1Ev
	mov r0, sb
	bl _ZdlPv
_02010E50:
	mov r0, sl
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02010E5C: .word s_data_param_DiskHP_bin_0208ac04

	arm_func_start sub_02010E60
sub_02010E60: ; 0x02010E60
	ldrb r0, [r0]
	cmp r0, #0
	moveq r0, #0
	subne r0, r0, #1
	andne r0, r0, #0xff
	bx lr
	arm_func_end sub_02010E60

	arm_func_start sub_02010E78
sub_02010E78: ; 0x02010E78
	ldrb r2, [r0]
	cmp r1, r2
	movhi r0, #0
	ldrls r0, [r0, #4]
	ldrlsb r0, [r0, r1]
	bx lr
	arm_func_end sub_02010E78

	arm_func_start sub_02010E90
sub_02010E90: ; 0x02010E90
	ldrb r2, [r0]
	cmp r1, r2
	movhi r0, #0
    ldrls r2, [r0, #8]
    movls r0, r1, lsl #1
	ldrlsh r0, [r2, r0]
	bx lr
	arm_func_end sub_02010E90

	arm_func_start sub_02010EAC
sub_02010EAC: ; 0x02010EAC
	ldrb r2, [r0]
	cmp r1, r2
	movhi r0, #0
	ldrls r2, [r0, #0xc]
    movls r0, r1, lsl #1
	ldrlsh r0, [r2, r0]
	bx lr
	arm_func_end sub_02010EAC

	arm_func_start sub_02010EC8
sub_02010EC8: ; 0x02010EC8
	mov r1, #0
	str r1, [r0, #0x10]
	bx lr
	arm_func_end sub_02010EC8

	arm_func_start sub_02010ED4
sub_02010ED4: ; 0x02010ED4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0x10]
	cmp r4, #0
	beq _02010F04
	beq _02010EFC
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02010ED4
_02010EFC:
	mov r0, #0
	str r0, [r5, #0x10]
_02010F04:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02010F0C
sub_02010F0C: ; 0x02010F0C
	mov r1, #0
	strh r1, [r0, #8]
	bx lr
	arm_func_end sub_02010F0C

	arm_func_start sub_02010F18
sub_02010F18: ; 0x02010F18
	stmdb sp!, {r4, lr}
	mov r1, #0
	mov r2, #8
	mov r4, r0
	bl MI_CpuFill8
	ldr r1, _02010F54 ; =0x0000C68F
	mov r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _02010F58 ; =0x0000E97C
	strh r0, [r4, #4]
	mov r0, r4
	strh r1, [r4, #6]
	bl sub_02010F0C
	ldmia sp!, {r4, pc}
	.align 2, 0
_02010F54: .word 0x0000C68F
_02010F58: .word 0x0000E97C
	arm_func_end sub_02010F18

	arm_func_start sub_02010F5C
sub_02010F5C: ; 0x02010F5C
	mov r2, #1
	mov r1, r2, lsl r1
	ldrh r2, [r0, #2]
	mov r1, r1, lsl #0x10
	orr r1, r2, r1, lsr #16
	strh r1, [r0, #2]
	bx lr
	arm_func_end sub_02010F5C

	arm_func_start sub_02010F78
sub_02010F78: ; 0x02010F78
	cmp r1, #0
	movne r0, r1
	ldrh r2, [r0]
	ldr r1, _02010FA4 ; =0x0000C68F
	cmp r2, r1
	ldreqh r1, [r0, #6]
	ldreq r0, _02010FA8 ; =0x0000E97C
	cmpeq r1, r0
	moveq r0, #1
	movne r0, #0
	bx lr
	.align 2, 0
_02010FA4: .word 0x0000C68F
_02010FA8: .word 0x0000E97C
	arm_func_end sub_02010F78

	arm_func_start sub_02010FAC
sub_02010FAC: ; 0x02010FAC
	mov r2, #1
	mov r1, r2, lsl r1
	ldrh r2, [r0, #4]
	mov r1, r1, lsl #0x10
	orr r1, r2, r1, lsr #16
	strh r1, [r0, #4]
	bx lr
	arm_func_end sub_02010FAC

	arm_func_start sub_02010FC8
sub_02010FC8: ; 0x02010FC8
	mov r3, #1
	mov r1, r3, lsl r1
	ldrh r2, [r0, #2]
	mov r1, r1, lsl #0x10
	ldrh r0, [r0, #4]
	tst r2, r1, lsr #16
	moveq r3, #0
	tst r0, r1, lsr #16
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	movne r0, #2
	bxne lr
	cmp r3, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end sub_02010FC8

	arm_func_start sub_0201100C
sub_0201100C: ; 0x0201100C
	add r1, r0, #0x3000
	mov r2, #0
	str r2, [r1, #8]
	bx lr
	arm_func_end sub_0201100C

	arm_func_start sub_0201101C
sub_0201101C: ; 0x0201101C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #0x3000
	ldr r4, [r0, #8]
	cmp r4, #0
	beq _02011054
	beq _02011048
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_0201101C
_02011048:
	add r0, r5, #0x3000
	mov r1, #0
	str r1, [r0, #8]
_02011054:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0201105C
sub_0201105C: ; 0x0201105C
	stmdb sp!, {r3, r4, r5, lr}
	mov r1, #0
	mov r5, r0
	bl sub_020110E0
	ldr r0, _020110D8 ; =MAIN_BSS_020AF620
	ldr r2, _020110DC ; =0x00003004
	mov r1, #0
	bl MI_CpuFill8
	add r0, r5, #0x3000
	ldr r4, [r0, #8]
	cmp r4, #0
	beq _020110AC
	beq _020110A0
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_0201105C
_020110A0:
	add r0, r5, #0x3000
	mov r1, #0
	str r1, [r0, #8]
_020110AC:
	mov r0, #0x74
	bl _Znwm
	cmp r0, #0
	beq _020110C4
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
_020110C4:
	add r1, r5, #0x3000
	str r0, [r1, #8]
	mov r0, r5
	bl sub_020110E8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020110D8: .word MAIN_BSS_020AF620
_020110DC: .word 0x00003004

	arm_func_start sub_020110E0
sub_020110E0: ; 0x020110E0
	str r1, [r0]
	bx lr
	arm_func_end sub_020110E0

	arm_func_start sub_020110E8
sub_020110E8: ; 0x020110E8
	add r0, r0, #0x3000
	mov r1, #0
	strh r1, [r0, #4]
	bx lr
	arm_func_end sub_020110E8

	arm_func_start sub_020110F8
sub_020110F8: ; 0x020110F8
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x3000
	ldrh r2, [r0, #4]
	cmp r2, #0
	beq _0201111C
	cmp r2, #1
	beq _02011140
	b _02011180
	arm_func_end sub_020110F8
_0201111C:
	add r1, r1, #2
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #8]
	mov r1, r1, lsr #0x10
	bl _ZN17UnkClass_02027FE812sub_02028220Et
	add r0, r4, #0x3000
	mov r1, #1
	strh r1, [r0, #4]
	b _02011180
_02011140:
	ldr r0, [r0, #8]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02011180
	tst r0, #0x80
	bne _0201116C
	add r0, r4, #0x3000
	mov r1, #3
	strh r1, [r0, #4]
	mov r0, #1
	ldmia sp!, {r4, pc}
_0201116C:
	mov r1, #4
	add r0, r4, #0x3000
	strh r1, [r0, #4]
	sub r0, r1, #5
	ldmia sp!, {r4, pc}
_02011180:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_02011188
sub_02011188: ; 0x02011188
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #0x3000
	ldrh r2, [r0, #4]
	cmp r2, #0
	beq _020111AC
	cmp r2, #1
	beq _020111D0
	b _02011240
	arm_func_end sub_02011188
_020111AC:
	add r1, r1, #2
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #8]
	mov r1, r1, lsr #0x10
	bl _ZN17UnkClass_02027FE812sub_02028408Et
	add r0, r5, #0x3000
	mov r1, #1
	strh r1, [r0, #4]
	b _02011240
_020111D0:
	ldr r0, [r0, #8]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	movs r4, r0
	beq _02011240
	tst r4, #0x80
	mov r0, r5
	bne _020111F8
	bl sub_020110E8
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_020111F8:
	bl sub_020110E8
	and r0, r4, #0x7f
	cmp r0, #8
	addls pc, pc, r0, lsl #2
	b _02011238
_0201120C: ; jump table
	b _02011238 ; case 0
	b _02011230 ; case 1
	b _02011230 ; case 2
	b _02011238 ; case 3
	b _02011230 ; case 4
	b _02011238 ; case 5
	b _02011230 ; case 6
	b _02011238 ; case 7
	b _02011230 ; case 8
_02011230:
	mvn r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_02011238:
	mvn r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_02011240:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02011248
sub_02011248: ; 0x02011248
	mov r1, #0
	str r1, [r0, #4]
	bx lr
	arm_func_end sub_02011248

	arm_func_start sub_02011254
sub_02011254: ; 0x02011254
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #4]
	cmp r4, #0
	beq _02011284
	beq _0201127C
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02011254
_0201127C:
	mov r0, #0
	str r0, [r5, #4]
_02011284:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0201128C
sub_0201128C: ; 0x0201128C
	stmdb sp!, {r3, r4, r5, lr}
	mvn r1, #0
	mov r5, r0
	bl sub_020112DC
	ldr r0, _020112D8 ; =MAIN_BSS_020AF598
	mov r1, #0
	mov r2, #2
	bl MI_CpuFill8
	ldr r4, [r5, #4]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _020112CC
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_0201128C
_020112CC:
	mov r0, #0
	str r0, [r5, #4]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020112D8: .word MAIN_BSS_020AF598

	arm_func_start sub_020112DC
sub_020112DC: ; 0x020112DC
	cmp r1, #0
	bge _020112F4
	ldr r0, _02011314 ; =MAIN_BSS_020AF598
	mov r1, #0
	strh r1, [r0]
	bx lr
	arm_func_end sub_020112DC
_020112F4:
	ldr r2, _02011314 ; =MAIN_BSS_020AF598
	mov r0, #1
	mov r0, r0, lsl r1
	ldrh r1, [r2]
	mov r0, r0, lsl #0x10
	orr r0, r1, r0, lsr #16
	strh r0, [r2]
	bx lr
	.align 2, 0
_02011314: .word MAIN_BSS_020AF598

	arm_func_start sub_02011318
sub_02011318: ; 0x02011318
	ldr r0, _02011334 ; =MAIN_BSS_020AF598
	mov r2, #1
	mov r2, r2, lsl r1
	ldrh r1, [r0]
	mov r0, r2, lsl #0x10
	and r0, r1, r0, lsr #16
	bx lr
	.align 2, 0
_02011334: .word MAIN_BSS_020AF598
	arm_func_end sub_02011318

	arm_func_start sub_02011338
sub_02011338: ; 0x02011338
	ldr ip, _02011350 ; =__cxa_vec_cleanup
	ldr r0, _02011354 ; =MAIN_BSS_020AF5E4
	ldr r3, _02011358 ; =sub_02010ED4
	mov r1, #3
	mov r2, #0x14
	bx ip
	.align 2, 0
_02011350: .word __cxa_vec_cleanup
_02011354: .word MAIN_BSS_020AF5E4
_02011358: .word sub_02010ED4
	arm_func_end sub_02011338

	arm_func_start sub_0201135C
sub_0201135C: ; 0x0201135C
	ldr ip, _0201136C ; =MI_CpuFill8
	mov r1, #0
	mov r2, #0x54
	bx ip
	.align 2, 0
_0201136C: .word MI_CpuFill8
	arm_func_end sub_0201135C

	arm_func_start sub_02011370
sub_02011370: ; 0x02011370
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0201135C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02011370

	arm_func_start sub_02011384
sub_02011384: ; 0x02011384
	mov r1, #0
	str r1, [r0, #0x58]
	str r1, [r0, #0x54]
	bx lr
	arm_func_end sub_02011384

	arm_func_start sub_02011394
sub_02011394: ; 0x02011394
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl sub_0201135C
	str r5, [r6, #0x58]
	str r4, [r6, #0x54]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end sub_02011394

	arm_func_start sub_020113B4
sub_020113B4: ; 0x020113B4
	stmdb sp!, {r3, r4, r5, lr}
	movs r4, r1
	mov r5, r0
	streqb r4, [r5, #2]
	ldmeqia sp!, {r3, r4, r5, pc}
	cmp r4, #0x4c
	bgt _02011404
	ldrb r0, [r5]
	cmp r0, #0
	beq _020113E0
	bl OS_Terminate
	arm_func_end sub_020113B4
_020113E0:
	cmp r4, #0x32
	movlt r0, #1
	strltb r0, [r5]
	blt _020113FC
	cmp r4, #0x46
	movge r0, #1
	strgeb r0, [r5]
_020113FC:
	strb r4, [r5, #2]
	ldmia sp!, {r3, r4, r5, pc}
_02011404:
	bl OS_Terminate
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0201140C
sub_0201140C: ; 0x0201140C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #2]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	cmp r0, #0x4c
	bhi _0201145C
	cmp r0, #0x32
	bhs _0201144C
	ldrb r0, [r4]
	cmp r0, #1
	beq _02011440
	bl OS_Terminate
	arm_func_end sub_0201140C
_02011440:
	mov r0, #2
	strb r0, [r4]
	ldmia sp!, {r4, pc}
_0201144C:
	cmp r0, #0x46
	movhs r0, #2
	strcsb r0, [r4]
	ldmia sp!, {r4, pc}
_0201145C:
	bl OS_Terminate
	ldmia sp!, {r4, pc}

	arm_func_start sub_02011464
sub_02011464: ; 0x02011464
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #2]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	cmp r0, #0x4c
	bhi _020114BC
	cmp r0, #0x32
	bhs _020114AC
	ldrb r0, [r4]
	cmp r0, #2
	beq _02011498
	bl OS_Terminate
	arm_func_end sub_02011464
_02011498:
	mov r0, #0
	strb r0, [r4]
	ldrb r0, [r4, #2]
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}
_020114AC:
	cmp r0, #0x46
	movhs r0, #0
	strcsb r0, [r4]
	ldmia sp!, {r4, pc}
_020114BC:
	bl OS_Terminate
	ldmia sp!, {r4, pc}

	arm_func_start sub_020114C4
sub_020114C4: ; 0x020114C4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r1
	add r4, r0, #0x14
	ldrb r0, [r4, r5]
	and r0, r0, #0xf
	cmp r0, #2
	bne _020114E4
	bl OS_Terminate
	arm_func_end sub_020114C4
_020114E4:
	ldrb r0, [r4, r5]
	bic r0, r0, #0xf
	orr r0, r0, #1
	strb r0, [r4, r5]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_020114F8
sub_020114F8: ; 0x020114F8
	add r0, r0, r1
	ldrb r0, [r0, #0x14]
	and r0, r0, #0xf
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	bx lr
	arm_func_end sub_020114F8

	arm_func_start sub_02011514
sub_02011514: ; 0x02011514
	add r2, r0, #0x14
	ldrb r0, [r2, r1]
	orr r0, r0, #0x10
	strb r0, [r2, r1]
	bx lr
	arm_func_end sub_02011514

	arm_func_start sub_02011528
sub_02011528: ; 0x02011528
	add r0, r0, r1
	ldrb r0, [r0, #0x14]
	tst r0, #0x10
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end sub_02011528

	arm_func_start sub_02011540
sub_02011540: ; 0x02011540
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldrb r0, [r5, #1]
	mov r4, r1
	cmp r0, #0
	beq _0201155C
	bl OS_Terminate
	arm_func_end sub_02011540
_0201155C:
	add r0, r5, r4
	ldrb r0, [r0, #0x14]
	and r0, r0, #0xf
	cmp r0, #2
	bne _02011574
	bl OS_Terminate
_02011574:
	mov r0, #1
	strb r0, [r5, #1]
	mov r0, r5
	mov r1, r4
	strb r4, [r5, #3]
	bl sub_02011514
	ldr r0, [r5, #0x58]
	mov r1, r4
	bl sub_02034120
	ldr r0, [r5, #0x54]
	mov r1, r4
	bl _ZN17UnkClass_020091E812sub_0200B21CEl
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_020115A8
sub_020115A8: ; 0x020115A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #1]
	cmp r0, #1
	beq _020115C0
	bl OS_Terminate
	arm_func_end sub_020115A8
_020115C0:
	mov r3, #0
	strb r3, [r4, #1]
	ldrb r1, [r4, #3]
	add r2, r4, #0x14
	ldrb r0, [r2, r1]
	bic r0, r0, #0xf
	orr r0, r0, #2
	strb r0, [r2, r1]
	strb r3, [r4, #3]
	ldr r0, [r4, #0x58]
	bl sub_020342C0
	ldr r0, [r4, #0x54]
	bl _ZN17UnkClass_020091E812sub_0200B36CEv
	ldmia sp!, {r4, pc}

	arm_func_start sub_020115F8
sub_020115F8: ; 0x020115F8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #1]
	cmp r0, #1
	beq _02011610
	bl OS_Terminate
	arm_func_end sub_020115F8
_02011610:
	mov r0, #0
	strb r0, [r4, #1]
	strb r0, [r4, #3]
	ldr r0, [r4, #0x58]
	bl sub_020342C0
	ldr r0, [r4, #0x54]
	bl _ZN17UnkClass_020091E812sub_0200B36CEv
	ldmia sp!, {r4, pc}

	arm_func_start sub_02011630
sub_02011630: ; 0x02011630
	add r0, r0, r1
	ldrb r0, [r0, #0x14]
	and r0, r0, #0xf
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	bx lr
	arm_func_end sub_02011630

	arm_func_start sub_0201164C
sub_0201164C: ; 0x0201164C
	stmdb sp!, {r4, lr}
	mov r4, r0
	cmp r1, #0x4c
	ldmgtia sp!, {r4, pc}
	str r1, [r4, #8]
	ldr r0, [r4, #0x58]
	bl sub_02034084
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #8]
	bl _ZN17UnkClass_020091E812sub_0200AFC0Elm
	ldmia sp!, {r4, pc}
	arm_func_end sub_0201164C

	arm_func_start sub_02011678
sub_02011678: ; 0x02011678
	mov r2, #0
	mov r3, r2
	arm_func_end sub_02011678
_02011680:
	add r1, r0, r3
	ldrb r1, [r1, #0x14]
	add r3, r3, #1
	and r1, r1, #0xf
	cmp r1, #2
	addeq r2, r2, #1
	cmp r3, #0x3e
	blt _02011680
	mov r0, r2
	bx lr

	arm_func_start sub_020116A8
sub_020116A8: ; 0x020116A8
	stmdb sp!, {r3, lr}
	cmp r1, #0x4c
	ldmgtia sp!, {r3, pc}
	ldr r0, [r0, #0x54]
	bl _ZN17UnkClass_020091E812sub_0200AFC0Elm
	ldmia sp!, {r3, pc}
	arm_func_end sub_020116A8

	arm_func_start sub_020116C0
sub_020116C0: ; 0x020116C0
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0xf8
	mov ip, r1
	mov lr, r0
	cmp ip, #0x45
	ble _02011700
	mov r2, #0
	arm_func_end sub_020116C0
_020116DC:
	add r1, lr, r2
	ldrb r0, [r1, #0x14]
	add r2, r2, #1
	cmp r2, #0x3e
	bic r0, r0, #0xf
	strb r0, [r1, #0x14]
	blt _020116DC
	add sp, sp, #0xf8
	ldmia sp!, {r4, r5, r6, pc}
_02011700:
	cmp ip, #0
	bne _02011730
	mov r2, #0
_0201170C:
	add r1, lr, r2
	ldrb r0, [r1, #0x14]
	add r2, r2, #1
	cmp r2, #0x3e
	bic r0, r0, #0xf
	strb r0, [r1, #0x14]
	blt _0201170C
	add sp, sp, #0xf8
	ldmia sp!, {r4, r5, r6, pc}
_02011730:
	ldr r6, _02011798 ; =DAT_02084428
	add r5, sp, #0
	mov r4, #0xf
_0201173C:
	ldmia r6!, {r0, r1, r2, r3}
	stmia r5!, {r0, r1, r2, r3}
	subs r4, r4, #1
	bne _0201173C
	ldmia r6, {r0, r1}
	stmia r5, {r0, r1}
	mov r4, #0
	add r3, sp, #0
_0201175C:
	ldr r0, [r3, r4, lsl #2]
	cmp r0, ip
	bgt _02011784
	add r2, lr, r4
	ldrb r1, [r2, #0x14]
	and r0, r1, #0xf
	cmp r0, #2
	bicne r0, r1, #0xf
	orrne r0, r0, #1
	strneb r0, [r2, #0x14]
_02011784:
	add r4, r4, #1
	cmp r4, #0x3e
	blt _0201175C
	add sp, sp, #0xf8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02011798: .word DAT_02084428
