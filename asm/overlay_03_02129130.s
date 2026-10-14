    .include "macros.inc"
    .include "include/overlay_03_02129130.inc"

    .text

	arm_func_start _ZN15COPDCaptureLineD1Ev
_ZN15COPDCaptureLineD1Ev: ; 0x02129130
	stmdb sp!, {r4, lr}
	ldr r1, _0212915C ; =ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	mov r4, r0
	str r1, [r4]
	bl _ZN15COPDCaptureLine12ov3_02129280Ev
	add r0, r4, #0x30
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212915C: .word ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	arm_func_end _ZN15COPDCaptureLineD1Ev

	arm_func_start ov3_02129160
ov3_02129160: ; 0x02129160
	stmdb sp!, {r4, lr}
	ldr r1, _02129194 ; =ptr_FUN_overlay_3_02129130_overlay_3_0212b458
	mov r4, r0
	str r1, [r4]
	bl _ZN15COPDCaptureLine12ov3_02129280Ev
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

	arm_func_start _ZN15COPDCaptureLine12ov3_02129198Ei
_ZN15COPDCaptureLine12ov3_02129198Ei: ; 0x02129198
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
	arm_func_end _ZN15COPDCaptureLine12ov3_02129198Ei
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

	arm_func_start _ZN15COPDCaptureLine12ov3_02129280Ev
_ZN15COPDCaptureLine12ov3_02129280Ev: ; 0x02129280
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
	arm_func_end _ZN15COPDCaptureLine12ov3_02129280Ev
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
	.global _ZTV15COPDCaptureLine
_ZTV15COPDCaptureLine:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_3_0212b430

    .global ptr_FUN_overlay_3_02129130_overlay_3_0212b458
ptr_FUN_overlay_3_02129130_overlay_3_0212b458: ; 0x0212B458
	.word _ZN15COPDCaptureLineD1Ev

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
