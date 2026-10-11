    .include "macros.inc"
    .include "include/overlay_00_0213A96C.inc"

    .text

	arm_func_start ov0_0213A96C
ov0_0213A96C: ; 0x0213A96C
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x9c
	mov sl, r0
	ldr r0, [sl, #0x90]
	mov sb, r1
	mov r1, #0
	mov r6, r2
	str r3, [sp, #4]
	bl _ZN11CFieldScene12ov0_02123060Em
	mov fp, r0
	ldr r0, [fp, #8]
	cmp r0, #0
	beq _0213A9DC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0213A9C0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x40]
	str r0, [sp, #0x44]
	b _0213A9F4
	arm_func_end ov0_0213A96C
_0213A9C0:
	mov r0, #0
	add r1, sp, #0x30
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x40]
	str r0, [sp, #0x44]
	b _0213A9F4
_0213A9DC:
	mov r0, #0
	add r1, sp, #0x28
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x40]
	str r0, [sp, #0x44]
_0213A9F4:
	ldr r1, [sp, #0x40]
	ldr r0, [sp, #0x44]
	mov r4, #0
	mov r5, r4
	str r1, [sp, #0x48]
	str r0, [sp, #0x4c]
	cmp r6, #0
	beq _0213AA20
	mov r0, sl
	mov r1, r6
	bl ov0_0213B150
_0213AA20:
	add r0, sp, #0x70
	mov r1, #0
	mov r2, #0x2c
	bl MI_CpuFill8
	ldr r0, [sl, #0x80]
	ldr r3, [sl, #4]
	cmp r0, #0
	mov r2, #0
	bne _0213AAD0
	cmp r3, #0
	ble _0213AB58
	mov r1, r2
	mov r0, #1
	add r8, sp, #0x70
	mov r7, r2
	mov r6, r2
_0213AA60:
	cmp r3, r2
	movle r3, r1
	ldrgt r3, [sl, #8]
	ldrgt r3, [r3, r2, lsl #2]
	cmp r3, #0
	beq _0213AABC
	ldr ip, [r3, #0x1e8]
	add ip, sl, ip, lsl #1
	ldrh ip, [ip, #0x54]
	cmp ip, #0
	bne _0213AAB8
	str r0, [r3, #0x1c8]
	ldr ip, [r3, #0x1e8]
	str r3, [r8, ip, lsl #2]
	ldr r3, [r3, #0x1fc]
	cmp r3, #0
	moveq r3, r0
	movne r3, r7
	cmp r3, #0
	addne r4, r4, #1
	addeq r5, r5, #1
	b _0213AABC
_0213AAB8:
	str r6, [r3, #0x1c8]
_0213AABC:
	ldr r3, [sl, #4]
	add r2, r2, #1
	cmp r2, r3
	blt _0213AA60
	b _0213AB58
_0213AAD0:
	cmp r3, #0
	ble _0213AB58
	mov r1, r2
	mov r0, #1
	add r8, sp, #0x70
	mov r7, r2
	mov r6, r2
_0213AAEC:
	cmp r3, r2
	movle r3, r1
	ldrgt r3, [sl, #8]
	ldrgt r3, [r3, r2, lsl #2]
	cmp r3, #0
	beq _0213AB48
	ldr ip, [r3, #0x1e8]
	add ip, sl, ip, lsl #1
	ldrh ip, [ip, #0x6a]
	cmp ip, #1
	bne _0213AB44
	str r0, [r3, #0x1c8]
	ldr ip, [r3, #0x1e8]
	str r3, [r8, ip, lsl #2]
	ldr r3, [r3, #0x1fc]
	cmp r3, #0
	moveq r3, r0
	movne r3, r7
	cmp r3, #0
	addne r4, r4, #1
	addeq r5, r5, #1
	b _0213AB48
_0213AB44:
	str r6, [r3, #0x1c8]
_0213AB48:
	ldr r3, [sl, #4]
	add r2, r2, #1
	cmp r2, r3
	blt _0213AAEC
_0213AB58:
	cmp sb, #0
	mov r0, sl
	beq _0213ABB0
	mov r1, #2
	bl _ZN19CFieldPartnerManage12ov0_02139E14Ei
	mov r8, #0
	mov r6, #0x1e
	add r5, sp, #0x48
	mov r4, r8
	add r7, sp, #0x70
_0213AB80:
	ldr r0, [r7, r8, lsl #2]
	cmp r0, #0
	beq _0213ABA0
	mov r1, sb
	str r6, [sp]
	ldmia r5, {r2, r3}
	bl _ZN13CFieldPartner12ov0_02136CFCEi7Point2Di
	str r4, [r7, r8, lsl #2]
_0213ABA0:
	add r8, r8, #1
	cmp r8, #0xb
	blt _0213AB80
	b _0213AD60
_0213ABB0:
	mov r1, #3
	bl _ZN19CFieldPartnerManage12ov0_02139E14Ei
	mov r0, sl
	mov r1, r4
	bl ov0_0213B410
	add r1, sp, #0x50
	mov r0, sl
	mov r2, r5
	bl ov0_0213BB54
	mov r5, #0
	mov r6, r5
	mov r8, r5
_0213ABE0:
	add r0, sp, #0x70
	ldr r4, [r0, r8, lsl #2]
	cmp r4, #0
	beq _0213AD54
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _0213ACC4
	ldr r0, [fp, #8]
	cmp r0, #0
	beq _0213AC48
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0213AC28
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x38]
	str r0, [sp, #0x3c]
	b _0213AC64
_0213AC28:
	mov r1, #0
	add r0, sp, #0x20
	str r1, [r0]
	str r1, [r0, #4]
	mov r0, r1
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
	b _0213AC64
_0213AC48:
	mov r1, #0
	add r0, sp, #0x18
	str r1, [r0]
	str r1, [r0, #4]
	mov r0, r1
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
_0213AC64:
	add r0, sp, #0x38
	ldr r1, [r0]
	ldr r0, [r0, #4]
	ldr r7, [r4, #8]
	str r0, [sp, #0x14]
	cmp r7, #0
	ldrne r0, [r7, #0xc]
	str r1, [sp, #0x10]
	cmpne r0, #0
	beq _0213ACC4
	add r1, sp, #0x10
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl sub_02011D3C
	ldr r0, [r7, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	beq _0213ACC4
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	str r1, [sp, #8]
	str r1, [r2, #0x18]
	str r0, [r2, #0x1c]
	str r0, [sp, #0xc]
_0213ACC4:
	ldr r0, [r4, #0x1fc]
	cmp r0, #0
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	mov r0, #0x1e
	str r0, [sp]
	beq _0213AD04
	add r2, sl, r5, lsl #3
	add r2, r2, #0x14
	mov r0, r4
	mov r1, sb
	ldmia r2, {r2, r3}
	add r5, r5, #1
	bl _ZN13CFieldPartner12ov0_02136CFCEi7Point2Di
	b _0213AD20
_0213AD04:
	add r2, sp, #0x50
	add r2, r2, r6, lsl #3
	mov r0, r4
	mov r1, sb
	ldmia r2, {r2, r3}
	add r6, r6, #1
	bl _ZN13CFieldPartner12ov0_02136CFCEi7Point2Di
_0213AD20:
	mov r0, r4
	ldr r2, [r0]
	ldr r1, [fp, #0x14]
	ldr r2, [r2, #0x30]
	blx r2
	mov r0, r4
	ldr r2, [r0]
	mov r1, #1
	ldr r2, [r2, #0x3c]
	blx r2
	mov r1, #0
	add r0, sp, #0x70
	str r1, [r0, r8, lsl #2]
_0213AD54:
	add r8, r8, #1
	cmp r8, #0xb
	blt _0213ABE0
_0213AD60:
	mov r2, #0
	mov r1, r2
_0213AD68:
	add r0, sl, r2, lsl #1
	strh r1, [r0, #0x54]
	add r2, r2, #1
	strh r1, [r0, #0x6a]
	cmp r2, #0xb
	blt _0213AD68
	str r1, [sl, #0x80]
	add sp, sp, #0x9c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov0_0213AD8C
ov0_0213AD8C: ; 0x0213AD8C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x88
	mov sl, r0
	ldr r0, [sl, #0x90]
	mov fp, r1
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0213ADD8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _0213ADE8
	add r1, sp, #0x2c
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	b _0213ADE8
	arm_func_end ov0_0213AD8C
_0213ADD8:
	add r1, sp, #0x24
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
_0213ADE8:
	mov r5, #0
	add r0, sp, #0x5c
	mov r1, r5
	mov r2, #0x2c
	mov r6, r5
	bl MI_CpuFill8
	ldr r1, [sl, #4]
	mov r8, r5
	cmp r1, #0
	ble _0213AE70
	mov r7, r5
	mov r3, #1
	add r2, sp, #0x5c
	mov r0, r5
_0213AE20:
	cmp r1, r8
	ldrgt r1, [sl, #8]
	movle sb, r7
	ldrgt sb, [r1, r8, lsl #2]
	cmp sb, #0
	beq _0213AE60
	str r3, [sb, #0x1c8]
	ldr r1, [sb, #0x1e8]
	str sb, [r2, r1, lsl #2]
	ldr r1, [sb, #0x1fc]
	cmp r1, #0
	moveq r1, r3
	movne r1, r0
	cmp r1, #0
	addne r5, r5, #1
	addeq r6, r6, #1
_0213AE60:
	ldr r1, [sl, #4]
	add r8, r8, #1
	cmp r8, r1
	blt _0213AE20
_0213AE70:
	mov r0, sl
	mov r1, #3
	bl _ZN19CFieldPartnerManage12ov0_02139E14Ei
	mov r0, sl
	mov r1, r5
	bl ov0_0213BDE8
	add r1, sp, #0x3c
	mov r0, sl
	mov r2, r6
	bl ov0_0213BE94
	mov r6, #0
	mov r7, r6
	mov sb, r6
_0213AEA4:
	add r0, sp, #0x5c
	ldr r5, [r0, sb, lsl #2]
	cmp r5, #0
	beq _0213B010
	cmp fp, #0
	beq _0213AF84
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0213AF08
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0213AEE8
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x34]
	str r0, [sp, #0x38]
	b _0213AF24
_0213AEE8:
	mov r1, #0
	add r0, sp, #0x1c
	str r1, [r0]
	str r1, [r0, #4]
	mov r0, r1
	str r0, [sp, #0x34]
	str r0, [sp, #0x38]
	b _0213AF24
_0213AF08:
	mov r1, #0
	add r0, sp, #0x14
	str r1, [r0]
	str r1, [r0, #4]
	mov r0, r1
	str r0, [sp, #0x34]
	str r0, [sp, #0x38]
_0213AF24:
	add r0, sp, #0x34
	ldr r1, [r0]
	ldr r0, [r0, #4]
	ldr r8, [r5, #8]
	str r0, [sp, #0x10]
	cmp r8, #0
	ldrne r0, [r8, #0xc]
	str r1, [sp, #0xc]
	cmpne r0, #0
	beq _0213AF84
	add r1, sp, #0xc
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl sub_02011D3C
	ldr r0, [r8, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	beq _0213AF84
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	str r1, [sp, #4]
	str r1, [r2, #0x18]
	str r0, [r2, #0x1c]
	str r0, [sp, #8]
_0213AF84:
	ldr r0, [r5, #0x1fc]
	mov r1, #0
	cmp r0, #0
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	mov r0, #0x1e
	str r0, [sp]
	beq _0213AFC4
	add r2, sl, r6, lsl #3
	add r2, r2, #0x14
	mov r0, r5
	ldmia r2, {r2, r3}
	add r6, r6, #1
	bl _ZN13CFieldPartner12ov0_02136CFCEi7Point2Di
	b _0213AFDC
_0213AFC4:
	add r2, sp, #0x3c
	add r2, r2, r7, lsl #3
	mov r0, r5
	ldmia r2, {r2, r3}
	add r7, r7, #1
	bl _ZN13CFieldPartner12ov0_02136CFCEi7Point2Di
_0213AFDC:
	mov r0, r5
	ldr r2, [r0]
	ldr r1, [r4, #0x14]
	ldr r2, [r2, #0x30]
	blx r2
	mov r0, r5
	ldr r2, [r0]
	mov r1, #1
	ldr r2, [r2, #0x3c]
	blx r2
	mov r1, #0
	add r0, sp, #0x5c
	str r1, [r0, sb, lsl #2]
_0213B010:
	add sb, sb, #1
	cmp sb, #0xb
	blt _0213AEA4
	mov r2, #0
	mov r1, r2
_0213B024:
	add r0, sl, r2, lsl #1
	strh r1, [r0, #0x54]
	add r2, r2, #1
	strh r1, [r0, #0x6a]
	cmp r2, #0xb
	blt _0213B024
	str r1, [sl, #0x80]
	add sp, sp, #0x88
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov0_0213B048
ov0_0213B048: ; 0x0213B048
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r6, [r0, #4]
	mov r5, #0
	cmp r6, #0
	ble _0213B0E8
	mov r4, r5
	mov ip, r5
	mov lr, #1
	mov r3, r5
	mov r2, r5
	arm_func_end ov0_0213B048
_0213B070:
	cmp r6, r5
	ldrgt r1, [r0, #8]
	movle r7, r4
	ldrgt r7, [r1, r5, lsl #2]
	cmp r7, #0
	beq _0213B0DC
	ldr r1, [r7, #8]
	cmp r1, #0
	beq _0213B0BC
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0213B0B4
	ldr r1, [r1, #0xc]
	cmp r1, #0
	movne r1, lr
	moveq r1, ip
	b _0213B0C0
_0213B0B4:
	mov r1, r3
	b _0213B0C0
_0213B0BC:
	mov r1, r2
_0213B0C0:
	cmp r1, #0
	beq _0213B0DC
	ldr r1, [r7, #0x1ec]
	sub r1, r1, #2
	cmp r1, #1
	movls r0, #1
	ldmlsia sp!, {r3, r4, r5, r6, r7, pc}
_0213B0DC:
	add r5, r5, #1
	cmp r5, r6
	blt _0213B070
_0213B0E8:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN19CFieldPartnerManage12ov0_0213B0F0Ev
_ZN19CFieldPartnerManage12ov0_0213B0F0Ev: ; 0x0213B0F0
	ldr ip, [r0, #4]
	mov r3, #0
	cmp ip, #0
	ble _0213B148
	mov r2, r3
	arm_func_end _ZN19CFieldPartnerManage12ov0_0213B0F0Ev
_0213B104:
	cmp ip, r3
	movle r1, r2
	ldrgt r1, [r0, #8]
	ldrgt r1, [r1, r3, lsl #2]
	cmp r1, #0
	beq _0213B13C
	ldr r0, [r1, #4]
	tst r0, #1
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
_0213B13C:
	add r3, r3, #1
	cmp r3, ip
	blt _0213B104
_0213B148:
	mov r0, #0
	bx lr

	arm_func_start ov0_0213B150
ov0_0213B150: ; 0x0213B150
	stmdb sp!, {r4, lr}
	mov r4, r0
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x90]
	bl _ZN11CFieldScene12ov0_02123060Em
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r0, #0x1e8]
	mov r1, #1
	add r0, r4, r0, lsl #1
	strh r1, [r0, #0x54]
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0213B150

	arm_func_start ov0_0213B184
ov0_0213B184: ; 0x0213B184
	stmdb sp!, {r4, lr}
	mov r4, r0
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x90]
	bl _ZN11CFieldScene12ov0_02123060Em
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r0, #0x1e8]
	mov r1, #1
	add r0, r4, r0, lsl #1
	strh r1, [r0, #0x6a]
	str r1, [r4, #0x80]
	ldmia sp!, {r4, pc}
	arm_func_end ov0_0213B184

	arm_func_start _ZN19CFieldPartnerManage12ov0_0213B1BCEv
_ZN19CFieldPartnerManage12ov0_0213B1BCEv: ; 0x0213B1BC
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x2c
	mov r4, r0
	ldr r5, [r4, #0x88]
	cmp r5, #0
	addeq sp, sp, #0x2c
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, pc}
	ldr r0, [r4, #0x90]
	mov r1, #0
	cmp r5, #8
	movgt r5, #8
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0213B238
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0213B218
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x24]
	str r1, [sp, #0x28]
	b _0213B230
	arm_func_end _ZN19CFieldPartnerManage12ov0_0213B1BCEv
_0213B218:
	mov r1, #0
	add r2, sp, #0x1c
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
_0213B230:
	add r6, sp, #0x24
	b _0213B254
_0213B238:
	mov r1, #0
	add r2, sp, #0x14
	add r6, sp, #0x24
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
_0213B254:
	ldr r0, [r0, #0x14]
	mov r3, r5
	str r0, [sp]
	add r0, r4, #0x14
	ldmia r6, {r1, r2}
	bl ov0_0213EF68
	ldr r6, [r4, #4]
	mov r5, #0
	cmp r6, #0
	addle sp, sp, #0x2c
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, pc}
	mov ip, #1
	mov lr, r5
	mov r3, r5
	mov r2, #7
	mov sb, ip
	mov r1, r5
_0213B298:
	cmp r6, r5
	movle r6, lr
	ldrgt r6, [r4, #8]
	ldrgt r6, [r6, r5, lsl #2]
	cmp r6, #0
	beq _0213B328
	ldr r7, [r6, #0x1fc]
	cmp r7, #0
	moveq r7, ip
	movne r7, r3
	cmp r7, #0
	beq _0213B328
	ldr r8, [r6, #0x1e8]
	ldr r7, [r4, #0x84]
	sub r7, r8, r7
	cmp r7, #8
	movge r7, r2
	cmp r7, r0
	bge _0213B308
	str r1, [r6, #0x1d0]
	add r7, r4, r7, lsl #3
	ldr r8, [r7, #0x14]
	ldr r7, [r7, #0x18]
	str r8, [sp, #0xc]
	str r8, [r6, #0x1d8]
	str r7, [sp, #0x10]
	str r7, [r6, #0x1dc]
	b _0213B328
_0213B308:
	str sb, [r6, #0x1d0]
	add r7, r4, r7, lsl #3
	ldr r8, [r7, #0x14]
	ldr r7, [r7, #0x18]
	str r8, [sp, #4]
	str r8, [r6, #0x1d8]
	str r7, [sp, #8]
	str r7, [r6, #0x1dc]
_0213B328:
	ldr r6, [r4, #4]
	add r5, r5, #1
	cmp r5, r6
	blt _0213B298
	add sp, sp, #0x2c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN19CFieldPartnerManage12ov0_0213B340Ev
_ZN19CFieldPartnerManage12ov0_0213B340Ev: ; 0x0213B340
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #0x10
	mov r4, r0
	ldr r0, [r4, #0x84]
	cmp r0, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, [r4, #0x90]
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0213B394
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _0213B3A4
	add r1, sp, #8
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	b _0213B3A4
	arm_func_end _ZN19CFieldPartnerManage12ov0_0213B340Ev
_0213B394:
	add r1, sp, #0
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
_0213B3A4:
	ldr r0, [r4, #4]
	mov r8, #0
	cmp r0, #0
	addle sp, sp, #0x10
	ldmleia sp!, {r4, r5, r6, r7, r8, pc}
	mov r7, r8
	mov r5, r8
	mov r6, #1
_0213B3C4:
	cmp r0, r8
	movle r0, r7
	ldrgt r0, [r4, #8]
	ldrgt r0, [r0, r8, lsl #2]
	cmp r0, #0
	beq _0213B3F8
	ldr r1, [r0, #0x1fc]
	cmp r1, #1
	moveq r1, r6
	movne r1, r5
	cmp r1, #0
	beq _0213B3F8
	bl _ZN13CFieldPartner12ov0_0213889CEv
_0213B3F8:
	ldr r0, [r4, #4]
	add r8, r8, #1
	cmp r8, r0
	blt _0213B3C4
	add sp, sp, #0x10
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov0_0213B410
ov0_0213B410: ; 0x0213B410
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x110
	mov sl, r0
	mov sb, r1
	mov r0, #0x12c0000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xec]
	mov r0, #0xb40000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xf0]
	mov r0, #0x780000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xf4]
	mov r0, #0x5a0000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xf8]
	mov r0, #0x480000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xfc]
	mov r0, #0x3c0000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0x100]
	mov r0, #0x330000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0x104]
	mov r0, #0x2d0000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0x108]
	mov r0, #0x280000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0x10c]
	mov r0, #0x12c0000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xc8]
	mov r0, #0x5a0000
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xcc]
	mov r0, #0
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xd0]
	mov r0, #0
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xd4]
	mov r0, #0
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xd8]
	mov r0, #0
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xdc]
	mov r0, #0
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xe0]
	mov r0, #0
	mov r1, #0x168000
	bl FX_Div
	str r0, [sp, #0xe4]
	mov r0, #0
	mov r1, #0x168000
	bl FX_Div
	ldr r5, _0213BB4C ; =DAT_overlay_0_02172ca8
	str r0, [sp, #0xe8]
	ldmia r5!, {r0, r1, r2, r3}
	add r4, sp, #0xa4
	stmia r4!, {r0, r1, r2, r3}
	ldmia r5!, {r0, r1, r2, r3}
	stmia r4!, {r0, r1, r2, r3}
	ldr r0, [r5]
	cmp sb, #0
	addeq sp, sp, #0x110
	str r0, [r4]
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [sl, #0x90]
	mov r1, #0
	cmp sb, #8
	movgt sb, #8
	bl _ZN11CFieldScene12ov0_02123060Em
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0213B5D0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0213B5B0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x74]
	str r0, [sp, #0x78]
	b _0213B5C8
	arm_func_end ov0_0213B410
_0213B5B0:
	mov r0, #0
	add r1, sp, #0x6c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x74]
	str r0, [sp, #0x78]
_0213B5C8:
	add r3, sp, #0x74
	b _0213B5EC
_0213B5D0:
	mov r0, #0
	add r1, sp, #0x64
	add r3, sp, #0x74
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x74]
	str r0, [sp, #0x78]
_0213B5EC:
	ldr r1, [r3]
	mov r6, #0
	str r1, [sp, #0x3c]
	ldr r1, [r3, #4]
	add r2, sp, #0xc8
	sub r0, sb, #1
	str r1, [sp, #0x18]
	ldr r1, [r2, r0, lsl #2]
	add r3, sp, #0xec
	str r1, [sp, #0x10]
	str r1, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	add r2, sp, #0xa4
	str r1, [sp, #0x9c]
	ldr r1, [sp, #0x18]
	mov fp, r6
	str r1, [sp, #0xa0]
	ldr r1, [r3, r0, lsl #2]
	ldr r0, [r2, r0, lsl #2]
	cmp sb, #0
	str r1, [sp, #0x34]
	str r0, [sp, #0x14]
	ble _0213B724
	mov r5, r6
	mov r7, r0, asr #0x1f
_0213B650:
	ldr r0, [sp, #0x10]
	ldr ip, [sp, #0x14]
	add r0, r0, r5
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r3, r0, lsl #1
	ldr r0, _0213BB50 ; =FX_SinCosTable_
	mov r1, r3, lsl #1
	ldrsh r2, [r0, r1]
	add r0, r0, r3, lsl #1
	ldrsh r0, [r0, #2]
	mov r1, r2, asr #0x1f
	umull r8, r3, ip, r2
	mla r3, ip, r1, r3
	mla r3, r7, r2, r3
	mov r2, r8, lsr #0xc
	ldr r1, [sp, #0x3c]
	orr r2, r2, r3, lsl #20
	sub r1, r1, r2
	str r1, [sp, #0x94]
	cmp r1, #0x14000
	mov r1, ip
	mov r2, r0, asr #0x1f
	umull r8, r3, r1, r0
	mla r3, r1, r2, r3
	mla r3, r7, r0, r3
	mov r1, r8, lsr #0xc
	ldr r0, [sp, #0x18]
	orr r1, r1, r3, lsl #20
	sub r8, r0, r1
	str r8, [sp, #0x98]
	cmpgt r8, #0x14000
	ble _0213B710
	mov r0, #0
	str r0, [sp]
	ldr r3, [r4, #0x14]
	add r0, sp, #0x94
	mov r2, #0x14000
	ldmia r0, {r0, r1}
	bl ov0_0213E668
	cmp r0, #0
	bne _0213B710
	ldr r1, [sp, #0x94]
	add r0, sl, r6, lsl #3
	str r1, [r0, #0x14]
	str r8, [r0, #0x18]
	add r6, r6, #1
_0213B710:
	ldr r0, [sp, #0x34]
	add fp, fp, #1
	add r5, r5, r0
	cmp fp, sb
	blt _0213B650
_0213B724:
	ldr r0, [sp, #0x34]
	mov r5, #0
	mov r0, r0, asr #0x1f
	mov r1, r0, lsl #0xb
	ldr r0, [sp, #0x34]
	mov fp, r5
	mov r2, r0, lsl #0xb
	ldr r0, [sp, #0x14]
	ldr r8, [sp, #0xa0]
	add r0, r0, #0x10000
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x34]
	orr r1, r1, r0, lsr #21
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	ldr r1, [sp, #0x38]
	str r0, [sp, #0xc]
	add r0, r1, r0
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x1c]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x20]
	sub r0, sp, #4
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x9c]
	str r0, [sp, #0x48]
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0x4c]
	ldr r0, [sp, #0x9c]
	str r0, [sp, #0x40]
	b _0213B8B0
_0213B7A0:
	ldr r0, [sp, #0x38]
	ldr ip, [sp, #0x1c]
	add r0, r0, fp
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r3, r0, lsl #1
	ldr r0, _0213BB50 ; =FX_SinCosTable_
	mov r1, r3, lsl #1
	ldrsh r2, [r0, r1]
	add r0, r0, r3, lsl #1
	ldrsh r0, [r0, #2]
	mov r1, r2, asr #0x1f
	umull r7, r3, ip, r2
	mla r3, ip, r1, r3
	ldr r1, [sp, #0x20]
	mla r3, r1, r2, r3
	mov r2, r7, lsr #0xc
	orr r2, r2, r3, lsl #20
	ldr r1, [sp, #0x40]
	mov r7, r0, asr #0x1f
	sub r1, r1, r2
	mov r3, ip
	str r1, [sp, #0x8c]
	cmp r1, #0x14000
	umull r2, r1, r3, r0
	mla r1, r3, r7, r1
	ldr r3, [sp, #0x20]
	mla r1, r3, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	sub r7, r8, r0
	str r7, [sp, #0x90]
	cmpgt r7, #0x14000
	ble _0213B8A4
	mov r0, #0
	str r0, [sp]
	ldr r3, [r4, #0x14]
	add r0, sp, #0x8c
	mov r2, #0x14000
	ldmia r0, {r0, r1}
	bl ov0_0213E668
	cmp r0, #0
	bne _0213B8A4
	ldr r0, [r4, #0x14]
	ldr r1, [sp, #0x48]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x44]
	mov r2, #0x14000
	str r1, [r0]
	ldr r1, [sp, #0x4c]
	str r1, [r0, #4]
	ldr r3, [r0]
	add r0, sp, #0x8c
	ldmia r0, {r0, r1}
	bl ov0_0213E7C4
	cmp r0, #0
	bne _0213B8A4
	ldr r1, [sp, #0x8c]
	add r0, sl, r6, lsl #3
	str r1, [r0, #0x14]
	str r7, [r0, #0x18]
	add r6, r6, #1
_0213B8A4:
	ldr r0, [sp, #0x34]
	add r5, r5, #1
	add fp, fp, r0
_0213B8B0:
	cmp r5, sb
	cmplt r6, sb
	blt _0213B7A0
	ldr r0, [sp, #0x14]
	mov fp, #0
	sub r0, r0, #0x10000
	str r0, [sp, #0x24]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x9c]
	mov r5, fp
	str r0, [sp, #0x50]
	b _0213B9B4
_0213B8E4:
	ldr r0, [sp, #0x38]
	ldr ip, [sp, #0x24]
	add r0, r0, r5
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r3, r0, lsl #1
	ldr r0, _0213BB50 ; =FX_SinCosTable_
	mov r1, r3, lsl #1
	ldrsh r2, [r0, r1]
	add r0, r0, r3, lsl #1
	ldrsh r0, [r0, #2]
	mov r1, r2, asr #0x1f
	umull r7, r3, ip, r2
	mla r3, ip, r1, r3
	ldr r1, [sp, #0x28]
	mla r3, r1, r2, r3
	mov r2, r7, lsr #0xc
	orr r2, r2, r3, lsl #20
	ldr r1, [sp, #0x50]
	mov r7, r0, asr #0x1f
	sub r1, r1, r2
	mov r3, ip
	str r1, [sp, #0x84]
	cmp r1, #0x14000
	umull r2, r1, r3, r0
	mla r1, r3, r7, r1
	ldr r3, [sp, #0x28]
	mla r1, r3, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	sub r7, r8, r0
	str r7, [sp, #0x88]
	cmpgt r7, #0x14000
	ble _0213B9A8
	mov r0, #0
	str r0, [sp]
	ldr r3, [r4, #0x14]
	add r0, sp, #0x84
	mov r2, #0x14000
	ldmia r0, {r0, r1}
	bl ov0_0213E668
	cmp r0, #0
	bne _0213B9A8
	ldr r1, [sp, #0x84]
	add r0, sl, r6, lsl #3
	str r1, [r0, #0x14]
	str r7, [r0, #0x18]
	add r6, r6, #1
_0213B9A8:
	ldr r0, [sp, #0x34]
	add fp, fp, #1
	add r5, r5, r0
_0213B9B4:
	cmp fp, sb
	cmplt r6, sb
	blt _0213B8E4
	ldr r0, [sp, #0x14]
	mov fp, #0
	add r0, r0, #0x20000
	str r0, [sp, #0x2c]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x30]
	sub r0, sp, #4
	str r0, [sp, #0x58]
	ldr r0, [sp, #0x9c]
	mov r5, fp
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0xa0]
	str r0, [sp, #0x60]
	ldr r0, [sp, #0x9c]
	str r0, [sp, #0x54]
	b _0213BB10
_0213BA00:
	ldr r0, [sp, #0x10]
	ldr ip, [sp, #0x2c]
	add r0, r0, r5
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r3, r0, lsl #1
	ldr r0, _0213BB50 ; =FX_SinCosTable_
	mov r1, r3, lsl #1
	ldrsh r2, [r0, r1]
	add r0, r0, r3, lsl #1
	ldrsh r0, [r0, #2]
	mov r1, r2, asr #0x1f
	umull r7, r3, ip, r2
	mla r3, ip, r1, r3
	ldr r1, [sp, #0x30]
	mla r3, r1, r2, r3
	mov r2, r7, lsr #0xc
	orr r2, r2, r3, lsl #20
	ldr r1, [sp, #0x54]
	mov r7, r0, asr #0x1f
	sub r1, r1, r2
	mov r3, ip
	str r1, [sp, #0x7c]
	cmp r1, #0x14000
	umull r2, r1, r3, r0
	mla r1, r3, r7, r1
	ldr r3, [sp, #0x30]
	mla r1, r3, r0, r1
	mov r0, r2, lsr #0xc
	orr r0, r0, r1, lsl #20
	sub r7, r8, r0
	str r7, [sp, #0x80]
	cmpgt r7, #0x14000
	ble _0213BB04
	mov r0, #0
	str r0, [sp]
	ldr r3, [r4, #0x14]
	add r0, sp, #0x7c
	mov r2, #0x14000
	ldmia r0, {r0, r1}
	bl ov0_0213E668
	cmp r0, #0
	bne _0213BB04
	ldr r0, [r4, #0x14]
	ldr r1, [sp, #0x5c]
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x58]
	mov r2, #0x14000
	str r1, [r0]
	ldr r1, [sp, #0x60]
	str r1, [r0, #4]
	ldr r3, [r0]
	add r0, sp, #0x7c
	ldmia r0, {r0, r1}
	bl ov0_0213E7C4
	cmp r0, #0
	bne _0213BB04
	ldr r1, [sp, #0x7c]
	add r0, sl, r6, lsl #3
	str r1, [r0, #0x14]
	str r7, [r0, #0x18]
	add r6, r6, #1
_0213BB04:
	ldr r0, [sp, #0xc]
	add fp, fp, #1
	add r5, r5, r0
_0213BB10:
	cmp fp, sb, lsl #1
	cmplt r6, sb
	blt _0213BA00
	cmp r6, sb
	addge sp, sp, #0x110
	ldmgeia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r1, [sp, #0x9c]
_0213BB2C:
	add r0, sl, r6, lsl #3
	str r1, [r0, #0x14]
	add r6, r6, #1
	str r8, [r0, #0x18]
	cmp r6, sb
	blt _0213BB2C
	add sp, sp, #0x110
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0213BB4C: .word DAT_overlay_0_02172ca8
_0213BB50: .word FX_SinCosTable_

	arm_func_start ov0_0213BB54
ov0_0213BB54: ; 0x0213BB54
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xb0
	ldr r5, _0213BDE4 ; =DAT_overlay_0_02172ccc
	add r4, sp, #0x70
	movs sb, r2
	mov r6, r0
	mov sl, r1
	ldmia r5!, {r0, r1, r2, r3}
	stmia r4!, {r0, r1, r2, r3}
	ldmia r5!, {r0, r1, r2, r3}
	stmia r4!, {r0, r1, r2, r3}
	ldmia r5!, {r0, r1, r2, r3}
	stmia r4!, {r0, r1, r2, r3}
	ldmia r5, {r0, r1, r2, r3}
	addeq sp, sp, #0xb0
	stmia r4, {r0, r1, r2, r3}
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r6, #0x90]
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0213BBF0
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0213BBD0
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x28]
	str r1, [sp, #0x2c]
	b _0213BBE8
	arm_func_end ov0_0213BB54
_0213BBD0:
	mov r1, #0
	add r2, sp, #0x20
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
_0213BBE8:
	add r3, sp, #0x28
	b _0213BC0C
_0213BBF0:
	mov r1, #0
	add r2, sp, #0x18
	add r3, sp, #0x28
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
_0213BC0C:
	ldr r8, [r3]
	ldr r7, [r3, #4]
	ldr r6, [r0, #0x14]
	add r1, r8, #0x8000
	mov r5, r1, asr #0x10
	add r0, r7, #0x8000
	mov r4, r0, asr #0x10
	mov r2, #0
	add r0, sp, #0x38
	add r1, sp, #0x40
	mov r3, r6
	str r5, [sp, #0x40]
	str r4, [sp, #0x44]
	str r2, [sp]
	str r8, [sp, #0x48]
	str r7, [sp, #0x4c]
	ldmia r1, {r1, r2}
	bl ov0_0213EA6C
	cmp r0, #0
	beq _0213BC6C
	ldr r1, [sp, #0x38]
	ldr r0, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r0, [sp, #0x44]
_0213BC6C:
	ldr r0, [sp, #0x40]
	ldr r7, [sp, #0x44]
	mov r4, #0
	mov r5, r4
	mov r8, r7
	str r0, [sp, #4]
	mov fp, r0
	b _0213BD14
_0213BC8C:
	add r0, sp, #0x70
	add r0, r0, r5, lsl #3
	ldr r1, [r0, #4]
	add r0, sp, #0x70
	ldr r2, [r0, r5, lsl #3]
	add r0, r7, r1
	str r0, [sp, #0xc]
	add r0, fp, r2
	str r0, [sp, #8]
	mov r0, #0
	str r1, [sp, #0x14]
	str r0, [sp]
	add r0, sp, #0x30
	mov r3, r6
	add r1, sp, #8
	str r2, [sp, #0x10]
	ldmia r1, {r1, r2}
	bl ov0_0213EA6C
	cmp r0, #0
	beq _0213BD10
	ldr r1, [sp, #0x30]
	ldr r0, [sp, #4]
	cmp r0, r1
	ldreq r0, [sp, #0x34]
	cmpeq r8, r0
	beq _0213BD10
	ldr r2, [sp, #0x30]
	add r0, sp, #0x50
	str r2, [r0, r4, lsl #3]
	add r0, r0, r4, lsl #3
	ldr r1, [sp, #0x34]
	add r4, r4, #1
	str r1, [r0, #4]
_0213BD10:
	add r5, r5, #1
_0213BD14:
	cmp r5, #8
	cmplt r4, sb
	blt _0213BC8C
	cmp r4, sb
	bne _0213BD70
	cmp sb, #0
	mov r3, #0
	addle sp, sp, #0xb0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r2, sp, #0x50
_0213BD3C:
	ldr r1, [r2, r3, lsl #3]
	add r0, r2, r3, lsl #3
	mov r1, r1, lsl #0x10
	str r1, [sl, r3, lsl #3]
	ldr r1, [r0, #4]
	add r0, sl, r3, lsl #3
	mov r1, r1, lsl #0x10
	add r3, r3, #1
	str r1, [r0, #4]
	cmp r3, sb
	blt _0213BD3C
	add sp, sp, #0xb0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0213BD70:
	mov r3, r4
	bge _0213BD9C
	ldr r5, [sp, #0x44]
	ldr r2, [sp, #0x40]
	add r1, sp, #0x50
_0213BD84:
	str r2, [r1, r3, lsl #3]
	add r0, r1, r3, lsl #3
	add r3, r3, #1
	str r5, [r0, #4]
	cmp r3, sb
	blt _0213BD84
_0213BD9C:
	cmp r4, #0
	mov r3, #0
	addle sp, sp, #0xb0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r2, sp, #0x50
_0213BDB0:
	ldr r1, [r2, r3, lsl #3]
	add r0, r2, r3, lsl #3
	mov r1, r1, lsl #0x10
	str r1, [sl, r3, lsl #3]
	ldr r1, [r0, #4]
	add r0, sl, r3, lsl #3
	mov r1, r1, lsl #0x10
	add r3, r3, #1
	str r1, [r0, #4]
	cmp r3, r4
	blt _0213BDB0
	add sp, sp, #0xb0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0213BDE4: .word DAT_overlay_0_02172ccc

	arm_func_start ov0_0213BDE8
ov0_0213BDE8: ; 0x0213BDE8
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x1c
	movs r4, r1
	mov r5, r0
	addeq sp, sp, #0x1c
	ldmeqia sp!, {r4, r5, pc}
	ldr r0, [r5, #0x90]
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0213BE58
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0213BE38
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x14]
	str r1, [sp, #0x18]
	b _0213BE50
	arm_func_end ov0_0213BDE8
_0213BE38:
	mov r1, #0
	add r2, sp, #0xc
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
_0213BE50:
	add ip, sp, #0x14
	b _0213BE74
_0213BE58:
	mov r1, #0
	add r2, sp, #4
	add ip, sp, #0x14
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
_0213BE74:
	ldr r1, [r0, #0x14]
	mov r3, r4
	add r0, r5, #0x14
	str r1, [sp]
	ldmia ip, {r1, r2}
	bl ov0_0213EF68
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, pc}

	arm_func_start ov0_0213BE94
ov0_0213BE94: ; 0x0213BE94
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xbc
	ldr r5, _0213C1B8 ; =DAT_overlay_0_02172d0c
	add r4, sp, #0x7c
	movs sb, r2
	mov r6, r0
	mov sl, r1
	ldmia r5!, {r0, r1, r2, r3}
	stmia r4!, {r0, r1, r2, r3}
	ldmia r5!, {r0, r1, r2, r3}
	stmia r4!, {r0, r1, r2, r3}
	ldmia r5!, {r0, r1, r2, r3}
	stmia r4!, {r0, r1, r2, r3}
	ldmia r5, {r0, r1, r2, r3}
	addeq sp, sp, #0xbc
	stmia r4, {r0, r1, r2, r3}
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r6, #0x90]
	mov r1, #0
	bl _ZN11CFieldScene12ov0_02123060Em
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0213BF30
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0213BF10
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x2c]
	str r1, [sp, #0x30]
	b _0213BF28
	arm_func_end ov0_0213BE94
_0213BF10:
	mov r1, #0
	add r2, sp, #0x24
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
_0213BF28:
	add r4, sp, #0x2c
	b _0213BF4C
_0213BF30:
	mov r1, #0
	add r2, sp, #0x1c
	add r4, sp, #0x2c
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
_0213BF4C:
	ldr r1, _0213C1BC ; =MAIN_BSS_0210CA40
	ldr r3, [r4]
	ldr r1, [r1]
	ldr r2, [r4, #4]
	ldr r1, [r1, #0x10]
	str r3, [sp, #0x54]
	str r2, [sp, #0x58]
	cmp r1, #0
	ldr r6, [r0, #0x14]
	mov r8, #0
	beq _0213BF88
	ldr r0, [r1, #0x24]
	cmp r6, r0
	ldrlt r0, [r1, #0x2c]
	ldrlt r8, [r0, r6, lsl #2]
_0213BF88:
	ldr r1, [sp, #0x54]
	ldr r0, [sp, #0x58]
	add r1, r1, #0x8000
	mov r5, r1, asr #0x10
	add r0, r0, #0x8000
	mov r4, r0, asr #0x10
	mov r2, #0
	add r0, sp, #0x44
	add r1, sp, #0x4c
	mov r3, r6
	str r5, [sp, #0x4c]
	str r4, [sp, #0x50]
	str r2, [sp]
	ldmia r1, {r1, r2}
	bl ov0_0213EA6C
	cmp r0, #0
	beq _0213BFDC
	ldr r1, [sp, #0x44]
	ldr r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	str r0, [sp, #0x50]
_0213BFDC:
	ldr r0, [sp, #0x4c]
	ldr fp, [sp, #0x50]
	mov r5, #0
	mov r4, r5
	mov r7, fp
	str r0, [sp, #8]
	str r0, [sp, #4]
	b _0213C0EC
_0213BFFC:
	add r0, sp, #0x7c
	add r0, r0, r4, lsl #3
	ldr r1, [r0, #4]
	add r0, sp, #0x7c
	ldr r2, [r0, r4, lsl #3]
	add r0, fp, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	str r1, [sp, #0x18]
	add r0, r0, r2
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp]
	add r0, sp, #0x3c
	mov r3, r6
	add r1, sp, #0xc
	str r2, [sp, #0x14]
	ldmia r1, {r1, r2}
	bl ov0_0213EA6C
	cmp r0, #0
	beq _0213C0E8
	ldr r1, [sp, #0x3c]
	ldr r0, [sp, #8]
	cmp r0, r1
	ldreq r0, [sp, #0x40]
	cmpeq r7, r0
	beq _0213C0E8
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0x40]
	mov r0, r0, lsl #0x10
	str r0, [sp, #0x34]
	mov r0, r1, lsl #0x10
	str r0, [sp, #0x38]
	mov r0, #0
	str r0, [sp]
	add r0, sp, #0x34
	mov r2, #0x7000
	mov r3, r6
	ldmia r0, {r0, r1}
	bl ov0_0213E668
	cmp r0, #0
	bne _0213C0E8
	cmp r8, #0
	beq _0213C0CC
	add r2, sp, #0x4c
	str r8, [sp]
	add r0, sp, #0x3c
	ldmia r0, {r0, r1}
	ldmia r2, {r2, r3}
	bl ov0_0213ED7C
	cmp r0, #0
	beq _0213C0E8
_0213C0CC:
	ldr r2, [sp, #0x3c]
	add r0, sp, #0x5c
	str r2, [r0, r5, lsl #3]
	add r0, r0, r5, lsl #3
	ldr r1, [sp, #0x40]
	add r5, r5, #1
	str r1, [r0, #4]
_0213C0E8:
	add r4, r4, #1
_0213C0EC:
	cmp r4, #8
	cmplt r5, sb
	blt _0213BFFC
	cmp r5, sb
	bne _0213C148
	cmp sb, #0
	addle sp, sp, #0xbc
	mov r3, #0
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r2, sp, #0x5c
_0213C114:
	ldr r1, [r2, r3, lsl #3]
	add r0, r2, r3, lsl #3
	mov r1, r1, lsl #0x10
	str r1, [sl, r3, lsl #3]
	ldr r1, [r0, #4]
	add r0, sl, r3, lsl #3
	mov r1, r1, lsl #0x10
	add r3, r3, #1
	str r1, [r0, #4]
	cmp r3, sb
	blt _0213C114
	add sp, sp, #0xbc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0213C148:
	bge _0213C170
	ldr r3, [sp, #0x50]
	ldr r2, [sp, #0x4c]
	add r1, sp, #0x5c
_0213C158:
	str r2, [r1, r5, lsl #3]
	add r0, r1, r5, lsl #3
	add r5, r5, #1
	str r3, [r0, #4]
	cmp r5, sb
	blt _0213C158
_0213C170:
	cmp sb, #0
	addle sp, sp, #0xbc
	mov r3, #0
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r2, sp, #0x5c
_0213C184:
	ldr r1, [r2, r3, lsl #3]
	add r0, r2, r3, lsl #3
	mov r1, r1, lsl #0x10
	str r1, [sl, r3, lsl #3]
	ldr r1, [r0, #4]
	add r0, sl, r3, lsl #3
	mov r1, r1, lsl #0x10
	add r3, r3, #1
	str r1, [r0, #4]
	cmp r3, sb
	blt _0213C184
	add sp, sp, #0xbc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0213C1B8: .word DAT_overlay_0_02172d0c
_0213C1BC: .word MAIN_BSS_0210CA40

    .rodata


    .global DAT_overlay_0_02172ca8
DAT_overlay_0_02172ca8: ; 0x02172CA8
	.byte 0x00, 0x00, 0x02, 0x00

    .global DAT_overlay_0_02172cac
DAT_overlay_0_02172cac: ; 0x02172CAC
	.byte 0x00, 0x00, 0x02, 0x00

    .global DAT_overlay_0_02172cb0
DAT_overlay_0_02172cb0: ; 0x02172CB0
	.byte 0x00, 0x00, 0x02, 0x00

    .global DAT_overlay_0_02172cb4
DAT_overlay_0_02172cb4: ; 0x02172CB4
	.byte 0x00, 0x00, 0x02, 0x00

    .global DAT_overlay_0_02172cb8
DAT_overlay_0_02172cb8: ; 0x02172CB8
	.byte 0x00, 0x80, 0x02, 0x00

    .global DAT_overlay_0_02172cbc
DAT_overlay_0_02172cbc: ; 0x02172CBC
	.byte 0x00, 0x80, 0x02, 0x00

    .global DAT_overlay_0_02172cc0
DAT_overlay_0_02172cc0: ; 0x02172CC0
	.byte 0x00, 0x80, 0x02, 0x00

    .global DAT_overlay_0_02172cc4
DAT_overlay_0_02172cc4: ; 0x02172CC4
	.byte 0x00, 0x00, 0x03, 0x00

    .global DAT_overlay_0_02172cc8
DAT_overlay_0_02172cc8: ; 0x02172CC8
	.byte 0x00, 0x00, 0x03, 0x00

    .global DAT_overlay_0_02172ccc
DAT_overlay_0_02172ccc: ; 0x02172CCC
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172cd0
DAT_overlay_0_02172cd0: ; 0x02172CD0
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172cd4
DAT_overlay_0_02172cd4: ; 0x02172CD4
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172cd8
DAT_overlay_0_02172cd8: ; 0x02172CD8
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172cdc
DAT_overlay_0_02172cdc: ; 0x02172CDC
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172ce0
DAT_overlay_0_02172ce0: ; 0x02172CE0
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172ce4
DAT_overlay_0_02172ce4: ; 0x02172CE4
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172ce8
DAT_overlay_0_02172ce8: ; 0x02172CE8
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172cec
DAT_overlay_0_02172cec: ; 0x02172CEC
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172cf0
DAT_overlay_0_02172cf0: ; 0x02172CF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172cf4
DAT_overlay_0_02172cf4: ; 0x02172CF4
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172cf8
DAT_overlay_0_02172cf8: ; 0x02172CF8
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172cfc
DAT_overlay_0_02172cfc: ; 0x02172CFC
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d00
DAT_overlay_0_02172d00: ; 0x02172D00
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172d04
DAT_overlay_0_02172d04: ; 0x02172D04
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d08
DAT_overlay_0_02172d08: ; 0x02172D08
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d0c
DAT_overlay_0_02172d0c: ; 0x02172D0C
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172d10
DAT_overlay_0_02172d10: ; 0x02172D10
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172d14
DAT_overlay_0_02172d14: ; 0x02172D14
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172d18
DAT_overlay_0_02172d18: ; 0x02172D18
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d1c
DAT_overlay_0_02172d1c: ; 0x02172D1C
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d20
DAT_overlay_0_02172d20: ; 0x02172D20
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d24
DAT_overlay_0_02172d24: ; 0x02172D24
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d28
DAT_overlay_0_02172d28: ; 0x02172D28
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172d2c
DAT_overlay_0_02172d2c: ; 0x02172D2C
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172d30
DAT_overlay_0_02172d30: ; 0x02172D30
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d34
DAT_overlay_0_02172d34: ; 0x02172D34
	.byte 0x01, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d38
DAT_overlay_0_02172d38: ; 0x02172D38
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d3c
DAT_overlay_0_02172d3c: ; 0x02172D3C
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d40
DAT_overlay_0_02172d40: ; 0x02172D40
	.byte 0xFF, 0xFF, 0xFF, 0xFF

    .global DAT_overlay_0_02172d44
DAT_overlay_0_02172d44: ; 0x02172D44
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_0_02172d48
DAT_overlay_0_02172d48: ; 0x02172D48
	.byte 0x01, 0x00, 0x00, 0x00
