    .include "macros.inc"
    .include "include/arm9_0203A76C.inc"

    .text

	arm_func_start _ZN16CFieldSEFWarningC1Ev
_ZN16CFieldSEFWarningC1Ev: ; 0x0203A76C
	stmdb sp!, {r4, lr}
	ldr r1, _0203A838 ; =_ZTV28CFieldScreenEffectObjectBase+8
	mov r4, r0
	str r1, [r4]
	mov r1, #4
	ldr r0, _0203A83C ; =ptr_FUN_0203aa14_0208db68
	str r1, [r4, #0x1c]
	str r0, [r4]
	mov r1, #0
	str r1, [r4, #0x20]
	str r1, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r0, _0203A840 ; =g_ntfTextureFormats
	str r1, [r4, #0x2c]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	add r0, r4, #0x4c
	str r1, [r4, #0x38]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _0203A844 ; =_ZTV17CPrimitiveRectNTF+8
	mov r0, r4
	str r1, [r4, #0x4c]
	mov r1, #0
	str r1, [r4, #0x64]
	bl sub_0203A9C4
	mov r0, #0x10
	str r0, [r4, #0x40]
	mov r0, #0x1f
	strh r0, [r4, #0x54]
	mov lr, #0
	str lr, [r4, #0x60]
	ldrh r1, [r4, #0x54]
	ldr ip, [r4, #0x40]
	ldr r0, _0203A848 ; =_ZN12CFieldSEFFog7s_colorE
	and r3, r1, #0x1f
	mov r2, r1, asr #5
	mov r1, r1, asr #0xa
	str r3, [r0]
	and r2, r2, #0x1f
	str r2, [r0, #4]
	and r2, r1, #0x1f
	ldr r1, _0203A84C ; =_ZN12CFieldSEFFog9s_densityE
	str r2, [r0, #8]
	ldr r0, _0203A850 ; =_ZN12CFieldSEFFog7s_dirtyE
	str ip, [r1]
	str lr, [r0]
	str lr, [r4, #0x44]
	mov r1, #0x1e
	mov r0, r4
	str r1, [r4, #0x48]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203A838: .word _ZTV28CFieldScreenEffectObjectBase+8
_0203A83C: .word ptr_FUN_0203aa14_0208db68
_0203A840: .word g_ntfTextureFormats
_0203A844: .word _ZTV17CPrimitiveRectNTF+8
_0203A848: .word _ZN12CFieldSEFFog7s_colorE
_0203A84C: .word _ZN12CFieldSEFFog9s_densityE
_0203A850: .word _ZN12CFieldSEFFog7s_dirtyE
	arm_func_end _ZN16CFieldSEFWarningC1Ev

	arm_func_start sub_0203A854
sub_0203A854: ; 0x0203A854
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _ZN28CFieldScreenEffectObjectBase6UpdateEi
	ldr r2, _0203A928 ; =_ZN12CFieldSEFFog7s_dirtyE
	ldr r0, [r2]
	cmp r0, #0
	beq _0203A8A0
	ldr r1, _0203A92C ; =_ZN12CFieldSEFFog7s_colorE
	ldr r0, _0203A930 ; =_ZN12CFieldSEFFog9s_densityE
	ldr ip, [r1]
	ldmib r1, {r3, lr}
	orr r1, ip, r3, lsl #5
	orr r1, r1, lr, lsl #10
	strh r1, [r5, #0x54]
	ldr r1, [r0]
	mov r0, #0
	str r1, [r5, #0x40]
	str r0, [r2]
	arm_func_end sub_0203A854
_0203A8A0:
	ldr r0, [r5, #4]
	cmp r0, #3
	cmpne r0, #4
	cmpne r0, #5
	movne r0, #0
	strne r0, [r5, #0x60]
	ldr r0, [r5, #0x44]
	cmp r4, #0x3c
	addeq r0, r0, #1
	addne r0, r0, #2
	str r0, [r5, #0x44]
	ldr r1, [r5, #0x44]
	ldr r0, [r5, #0x48]
	cmp r1, r0
	movge r0, #0
	strge r0, [r5, #0x44]
	ldr r3, [r5, #0x48]
	ldr r2, [r5, #0x44]
	add r0, r3, r3, lsr #31
	cmp r2, r0, asr #1
	mov r1, r0, asr #1
	bge _0203A904
	mov r0, r2, lsl #0xc
	bl _s32_div_f
	b _0203A910
_0203A904:
	sub r0, r3, r2
	mov r0, r0, lsl #0xc
	bl _s32_div_f
_0203A910:
	ldr r1, [r5, #0x40]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r5, #0x60]
	ldr r0, [r5, #4]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203A928: .word _ZN12CFieldSEFFog7s_dirtyE
_0203A92C: .word _ZN12CFieldSEFFog7s_colorE
_0203A930: .word _ZN12CFieldSEFFog9s_densityE

	arm_func_start sub_0203A934
sub_0203A934: ; 0x0203A934
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r2, [r5, #0x60]
	mov r4, r1
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl _ZN28CFieldScreenEffectObjectBase11SetupMatrixEP17UnkClass_02003718
	ldr r1, [r5, #0x1c]
	mov r0, #0
	str r1, [r5, #0x5c]
	str r0, [r5, #0x68]
	str r0, [r5, #0x6c]
	mov r0, #0x100000
	str r0, [r5, #0x70]
	str r0, [r5, #0x74]
	add r0, r5, #0x20
	bl _ZN10NtfTexture4BindEv
	ldr r0, [r5, #0x1c]
	ldr r2, [r5, #0x60]
	add r0, r0, #3
	mov r0, r0, lsl #0x18
	orr r1, r0, #0xc0
	ldr r0, _0203A9BC ; =0x040004A4
	orr r1, r1, r2, lsl #16
	str r1, [r0]
	add r0, r5, #0x4c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r0, _0203A9C0 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203A9BC: .word 0x040004A4
_0203A9C0: .word 0x04000448
	arm_func_end sub_0203A934

	arm_func_start sub_0203A9C4
sub_0203A9C4: ; 0x0203A9C4
	mov r0, #1
	bx lr
	arm_func_end sub_0203A9C4

	arm_func_start sub_0203A9CC
sub_0203A9CC: ; 0x0203A9CC
	mov r0, #1
	bx lr
	arm_func_end sub_0203A9CC

	arm_func_start sub_0203A9D4
sub_0203A9D4: ; 0x0203A9D4
	stmdb sp!, {r4, lr}
	ldr r1, _0203AA08 ; =ptr_FUN_0203aa14_0208db68
	mov r4, r0
	str r1, [r4]
	bl sub_0203A9CC
	add r0, r4, #0x4c
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203AA08: .word ptr_FUN_0203aa14_0208db68
	arm_func_end sub_0203A9D4

	arm_func_start sub_0203AA0C
sub_0203AA0C: ; 0x0203AA0C
	mov r0, #0xd
	bx lr
	arm_func_end sub_0203AA0C

	arm_func_start sub_0203AA14
sub_0203AA14: ; 0x0203AA14
	stmdb sp!, {r4, lr}
	ldr r1, _0203AA40 ; =ptr_FUN_0203aa14_0208db68
	mov r4, r0
	str r1, [r4]
	bl sub_0203A9CC
	add r0, r4, #0x4c
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203AA40: .word ptr_FUN_0203aa14_0208db68
	arm_func_end sub_0203AA14

	arm_func_start _ZN13CFieldSEFSnowC1Ev
_ZN13CFieldSEFSnowC1Ev: ; 0x0203AA44
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0203AB08 ; =_ZTV28CFieldScreenEffectObjectBase+8
	mov r4, r0
	str r1, [r4]
	mov r1, #4
	str r1, [r4, #0x1c]
	ldr r0, _0203AB0C ; =ptr_FUN_0203b314_0208dbb4
	mov r1, #0
	str r0, [r4]
	str r1, [r4, #0x538]
	str r1, [r4, #0x53c]
	str r1, [r4, #0x540]
	ldr r0, _0203AB10 ; =g_ntfTextureFormats
	str r1, [r4, #0x544]
	str r0, [r4, #0x548]
	add r5, r4, #0x154
	str r1, [r4, #0x54c]
	add r0, r5, #0x400
	str r1, [r4, #0x550]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _0203AB14 ; =_ZTV17CPrimitiveRectNTF+8
	mov r0, r4
	str r1, [r4, #0x554]
	mov r1, #0
	str r1, [r5, #0x418]
	bl sub_0203AFBC
	ldr r1, _0203AB18 ; =0x00007E10
	add r0, r4, #0x500
	strh r1, [r0, #0x5c]
	mov lr, #0
	mov ip, #0xc
	str lr, [r4, #0x568]
	str ip, [r4, #0x590]
	ldrh r1, [r0, #0x5c]
	ldr r0, _0203AB1C ; =_ZN12CFieldSEFFog7s_colorE
	ldr r2, _0203AB20 ; =_ZN12CFieldSEFFog9s_densityE
	and r5, r1, #0x1f
	mov r3, r1, asr #5
	mov r1, r1, asr #0xa
	str r5, [r0]
	and r3, r3, #0x1f
	str r3, [r0, #4]
	and r3, r1, #0x1f
	str r3, [r0, #8]
	ldr r1, _0203AB24 ; =_ZN12CFieldSEFFog7s_dirtyE
	mov r0, r4
	str ip, [r2]
	str lr, [r1]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203AB08: .word _ZTV28CFieldScreenEffectObjectBase+8
_0203AB0C: .word ptr_FUN_0203b314_0208dbb4
_0203AB10: .word g_ntfTextureFormats
_0203AB14: .word _ZTV17CPrimitiveRectNTF+8
_0203AB18: .word 0x00007E10
_0203AB1C: .word _ZN12CFieldSEFFog7s_colorE
_0203AB20: .word _ZN12CFieldSEFFog9s_densityE
_0203AB24: .word _ZN12CFieldSEFFog7s_dirtyE
	arm_func_end _ZN13CFieldSEFSnowC1Ev

	arm_func_start sub_0203AB28
sub_0203AB28: ; 0x0203AB28
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	bl _ZN28CFieldScreenEffectObjectBase6UpdateEi
	ldr r2, _0203ADBC ; =_ZN12CFieldSEFFog7s_dirtyE
	ldr r0, [r2]
	cmp r0, #0
	beq _0203AB74
	ldr r1, _0203ADC0 ; =_ZN12CFieldSEFFog7s_colorE
	add r0, r4, #0x500
	ldr r5, [r1]
	ldmib r1, {r3, r6}
	orr r1, r5, r3, lsl #5
	orr r3, r1, r6, lsl #10
	strh r3, [r0, #0x5c]
	ldr r1, _0203ADC4 ; =_ZN12CFieldSEFFog9s_densityE
	mov r0, #0
	ldr r1, [r1]
	str r1, [r4, #0x590]
	str r0, [r2]
	arm_func_end sub_0203AB28
_0203AB74:
	ldr r0, [r4, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	mov r7, #0
	ldr r6, _0203ADC8 ; =DAT_0208db84
	ldr lr, _0203ADCC ; =_ZN28CFieldScreenEffectObjectBase11s_frameStepE
	ldr ip, _0203ADD0 ; =MAIN_BSS_0210CEC8
	ldr r3, _0203ADD4 ; =_ZN28CFieldScreenEffectObjectBase8s_scrollE
	add r8, r4, #0x38
	mov r0, #0xc
	mov r2, r7
	mov r1, #0xcc
_0203ABA8:
	ldrb sb, [r8, #0x20]
	ldr r5, [lr]
	add r5, sb, r5
	strb r5, [r8, #0x20]
	ldr r5, [r8]
	cmp r5, #0
	addlt r5, r5, #0x140000
	strlt r5, [r8]
	blt _0203ABD8
	cmp r5, #0x140000
	subgt r5, r5, #0x140000
	strgt r5, [r8]
_0203ABD8:
	ldr sl, [r8, #0x14]
	ldr sb, [lr]
	ldr r5, [r8, #4]
	mul fp, sl, sb
	mov sb, fp, asr #0x1f
	mov sb, sb, lsl #0xc
	mov sl, fp, lsl #0xc
	orr sb, sb, fp, lsr #20
	mov sl, sl, lsr #0xc
	orr sl, sl, sb, lsl #20
	adds r5, r5, sl
	str r5, [r8, #4]
	bpl _0203AC1C
	ldr r5, [r8, #4]
	add r5, r5, #0x100000
	str r5, [r8, #4]
	b _0203AC68
_0203AC1C:
	cmp r5, #0x100000
	ble _0203AC68
	ldr r5, [r8, #4]
	sub r5, r5, #0x100000
	str r5, [r8, #4]
	ldmia ip, {r5, sb, sl}
	mla sl, sb, r5, sl
	mov r5, sl, lsr #0x10
	str sl, [ip]
	mov r5, r5, lsl #6
	mov r5, r5, lsr #0x10
	ldr sb, [r8, #8]
	mov r5, r5, lsl #0x10
	add r5, sb, r5, lsr #4
	str r5, [r8]
	ldrb r5, [r8, #0x22]
	ldr r5, [r6, r5, lsl #2]
	str r5, [r8, #0x1c]
	str r5, [r8, #0x14]
_0203AC68:
	ldr sb, [r8]
	ldr r5, [r3]
	add r5, sb, r5
	str r5, [r8]
	ldr sb, [r8, #4]
	ldr r5, [r3, #4]
	add r5, sb, r5
	str r5, [r8, #4]
	ldrh sb, [r8, #0x24]
	ldr r5, [lr]
	add r5, sb, r5, lsl #8
	strh r5, [r8, #0x24]
	ldrb sb, [r8, #0x21]
	sub r5, sb, #1
	strb r5, [r8, #0x21]
	cmp sb, #0
	bne _0203AD40
	ldmia ip, {r5, sb, sl}
	mla r5, sb, r5, sl
	mov sl, r5, lsr #0x10
	mov sb, #0xa
	mul sb, sl, sb
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #0x10
	mov sb, sb, lsr #0x10
	str r5, [ip]
	add r5, sb, #0xa
	strb r5, [r8, #0x21]
	ldmia ip, {r5, sb, sl}
	mla r5, sb, r5, sl
	mov sb, r5, lsr #0x10
	mul sl, sb, r0
	mov sb, sl, lsr #0x10
	mov sb, sb, lsl #0x10
	mov sb, sb, lsr #4
	umull fp, sl, sb, r1
	str r5, [ip]
	mla sl, sb, r2, sl
	mov r5, sb, asr #0x1f
	mla sl, r5, r1, sl
	mov fp, fp, lsr #0xc
	orr fp, fp, sl, lsl #20
	add r5, fp, #0x33
	ldr sb, [r8, #0x18]
	add r5, r5, #0xb00
	smull fp, sl, sb, r5
	mov sb, fp, lsr #0xc
	orr sb, sb, sl, lsl #20
	str sb, [r8, #0x10]
	ldr sb, [r8, #0x1c]
	smull sl, r5, sb, r5
	mov sb, sl, lsr #0xc
	orr sb, sb, r5, lsl #20
	str sb, [r8, #0x14]
_0203AD40:
	add r7, r7, #1
	cmp r7, #0x20
	add r8, r8, #0x28
	blt _0203ABA8
	ldr r0, [r4, #4]
	cmp r0, #3
	beq _0203AD70
	cmp r0, #4
	beq _0203AD88
	cmp r0, #5
	beq _0203AD94
	b _0203ADAC
_0203AD70:
	ldr r1, [r4, #0x590]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x568]
	b _0203ADB4
_0203AD88:
	ldr r0, [r4, #0x590]
	str r0, [r4, #0x568]
	b _0203ADB4
_0203AD94:
	ldr r1, [r4, #0x590]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x568]
	b _0203ADB4
_0203ADAC:
	mov r0, #0
	str r0, [r4, #0x568]
_0203ADB4:
	ldr r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203ADBC: .word _ZN12CFieldSEFFog7s_dirtyE
_0203ADC0: .word _ZN12CFieldSEFFog7s_colorE
_0203ADC4: .word _ZN12CFieldSEFFog9s_densityE
_0203ADC8: .word DAT_0208db84
_0203ADCC: .word _ZN28CFieldScreenEffectObjectBase11s_frameStepE
_0203ADD0: .word MAIN_BSS_0210CEC8
_0203ADD4: .word _ZN28CFieldScreenEffectObjectBase8s_scrollE

	arm_func_start sub_0203ADD8
sub_0203ADD8: ; 0x0203ADD8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x30
	mov r7, r0
	ldr r0, [r7, #0x20]
	mov fp, r1
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	ldr r2, [fp, #0x1c]
	ldr r1, [fp, #0x20]
	ldr r0, [r7, #4]
	str r2, [sp, #0x20]
	str r1, [sp, #0x24]
	cmp r0, #3
	beq _0203AE2C
	cmp r0, #4
	beq _0203AE3C
	cmp r0, #5
	beq _0203AE44
	b _0203AE54
	arm_func_end sub_0203ADD8
_0203AE2C:
	ldr r0, [r7, #0x18]
	rsb r0, r0, r0, lsl #5
	mov r6, r0, asr #0xc
	b _0203AE58
_0203AE3C:
	mov r6, #0x1f
	b _0203AE58
_0203AE44:
	ldr r0, [r7, #0x18]
	rsb r0, r0, r0, lsl #5
	mov r6, r0, asr #0xc
	b _0203AE58
_0203AE54:
	mov r6, #0
_0203AE58:
	ldr r0, [sp, #0x20]
	add r5, r7, #0x38
	str r0, [sp]
	ldr r0, [sp, #0x24]
	mov r4, #0
	str r0, [sp, #4]
	ldr r0, [sp]
	str r0, [sp, #0x18]
	ldr r0, [sp, #4]
	str r0, [sp, #0x1c]
_0203AE80:
	ldr r2, [r7, #0x24]
	ldr r0, _0203AFB0 ; =0x00007FFF
	mov r1, fp
	strh r0, [r2, #8]
	ldr r0, [r7, #0x24]
	str r6, [r0, #0x14]
	ldrb r2, [r5, #0x22]
	ldr r0, [r7, #0x24]
	strh r2, [r0, #0x2a]
	ldr r8, [r5]
	ldr r0, [sp]
	ldrh r2, [r5, #0x24]
	sub sl, r8, r0
	ldr r3, [r5, #4]
	ldr r0, [sp, #4]
	str sl, [sp, #0x10]
	sub r3, r3, r0
	mov r0, r2, asr #4
	mov r2, r0, lsl #2
	ldr r0, _0203AFB4 ; =FX_SinCosTable_
	str r3, [sp, #0x14]
	ldrsh lr, [r0, r2]
	mov r0, #0x6000
	sub r3, r3, #0x80000
	umull sb, r8, lr, r0
	mov ip, lr, asr #0x1f
	mov r0, #0x6000
	mla r8, ip, r0, r8
	mov r0, sb, lsr #0xc
	orr r0, r0, r8, lsl #20
	add r0, r0, #0xa0000
	sub r0, sl, r0
	ldr r2, [r7, #0x24]
	str r0, [sp, #0x28]
	str r0, [r2, #0x18]
	str r3, [r2, #0x1c]
	str r0, [sp, #8]
	ldr r0, [r7, #0x24]
	str r3, [sp, #0x2c]
	ldr r2, [r0]
	str r3, [sp, #0xc]
	ldr r2, [r2, #8]
	blx r2
	add r4, r4, #1
	add r5, r5, #0x28
	cmp r4, #0x20
	blt _0203AE80
	ldr r0, [r7, #0x568]
	cmp r0, #0
	addeq sp, sp, #0x30
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, r7
	mov r1, fp
	bl _ZN28CFieldScreenEffectObjectBase11SetupMatrixEP17UnkClass_02003718
	ldr r1, [r7, #0x1c]
	add r0, r7, #0x138
	str r1, [r7, #0x564]
	mov r1, #0
	str r1, [r7, #0x570]
	str r1, [r7, #0x574]
	mov r1, #0x100000
	str r1, [r7, #0x578]
	add r0, r0, #0x400
	str r1, [r7, #0x57c]
	bl _ZN10NtfTexture4BindEv
	add r0, r7, #0x154
	add r0, r0, #0x400
	ldr r2, [r0]
	mov r1, fp
	ldr r2, [r2, #8]
	blx r2
	ldr r0, _0203AFB8 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	add sp, sp, #0x30
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203AFB0: .word 0x00007FFF
_0203AFB4: .word FX_SinCosTable_
_0203AFB8: .word 0x04000448

	arm_func_start sub_0203AFBC
sub_0203AFBC: ; 0x0203AFBC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	mov r0, #0x34
	bl _Znwm
	movs r5, r0
	beq _0203AFF8
	ldr r1, _0203B230 ; =ptr_FUN_020294c0_0208c4a4
	add r0, r5, #4
	str r1, [r5]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r1, #0
	str r1, [r5, #0x2c]
	ldr r0, _0203B234 ; =_ZTV27CFieldScreenEffectActorData+8
	str r1, [r5, #0x30]
	str r0, [r5]
	arm_func_end sub_0203AFBC
_0203AFF8:
	mov r0, r5
	mov r1, #4
	str r5, [r4, #0x20]
	bl _ZN27CFieldScreenEffectActorData4LoadEi
	mov r0, #0x4c
	bl _Znwm
	cmp r0, #0
	beq _0203B01C
	bl _ZN15CSoftwareSpriteC1Ev
_0203B01C:
	str r0, [r4, #0x24]
	mov r1, #1
	str r1, [r0, #4]
	ldr r1, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	str r1, [r0, #0x10]
	ldr r0, [r4, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r2, [r4, #0x24]
	mov r1, #0
	str r0, [r2, #0x34]
	ldr r0, [r4, #0x20]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r2, [r4, #0x24]
	mov r1, #0
	str r0, [r2, #0x2c]
	str r1, [r2, #0x30]
	ldr r0, [r4, #0x20]
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	ldr r2, [r4, #0x24]
	mov r1, #0
	str r0, [r2, #0x38]
	ldr r0, [r4, #0x20]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	mov sb, #0
	mov r8, r0
	mov r7, #1
	mov r6, sb
	mov r5, sb
_0203B0B0:
	mov r0, r8
	mov r1, r7
	mov r2, r6
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, sb, lsl #1
	strh r0, [r1, #0x28]
	ldrh r1, [r1, #0x28]
	mov r0, r8
	mov r2, r5
	bl _ZN17UnkClass_0200878812sub_02008990Ett
	add sb, sb, #1
	cmp sb, #8
	blt _0203B0B0
	mov lr, #0
	mov r5, lr
	add ip, r4, #0x38
_0203B0F0:
	ldr r1, _0203B238 ; =0x55555556
	mov r4, #0
	smull r0, r3, r1, lr
	add r3, r3, lr, lsr #31
	mov r2, #3
	smull r0, r1, r2, r3
	sub r3, lr, r0
	rsb r0, r3, #2
	and r3, r0, #0xff
	ldr r1, _0203B23C ; =DAT_0208db84
	ldr r0, _0203B240 ; =MAIN_BSS_0210CEC8
	mov r6, r4
	mov r2, r4
	mov r8, #0x18
	mov sb, #0xa
_0203B12C:
	ldmia r0, {r7, sl, fp}
	mla r7, sl, r7, fp
	str r7, [r0]
	strb r3, [ip, #0x22]
	ldmia r0, {r7, sl, fp}
	mla fp, sl, r7, fp
	mov r7, fp, lsr #0x10
	mov r7, r7, lsl #6
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	str fp, [r0]
	add r7, r6, r7, lsr #4
	str r7, [ip]
	ldmia r0, {r7, sl, fp}
	mla fp, sl, r7, fp
	mov r7, fp, lsr #0x10
	mul sl, r7, r8
	mov r7, sl, lsr #0x10
	mov r7, r7, lsl #0x10
	str fp, [r0]
	add r7, r5, r7, lsr #4
	str r7, [ip, #4]
	str r6, [ip, #8]
	ldmia r0, {r7, sl, fp}
	mla r7, sl, r7, fp
	str r7, [r0]
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #4
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r7, r7, lsr #4
	strh r7, [ip, #0x24]
	ldmia r0, {r7, sl, fp}
	mla r7, sl, r7, fp
	str r7, [r0]
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #8
	mov r7, r7, lsr #0x10
	strb r7, [ip, #0x20]
	str r2, [ip, #0x10]
	ldrb r7, [ip, #0x22]
	add r4, r4, #1
	add r6, r6, #0x40000
	ldr r7, [r1, r7, lsl #2]
	cmp r4, #4
	str r7, [ip, #0x1c]
	str r7, [ip, #0x14]
	ldmia r0, {r7, sl, fp}
	mla r7, sl, r7, fp
	str r7, [r0]
	mov r7, r7, lsr #0x10
	mul sl, r7, sb
	mov r7, sl, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r7, r7, lsr #0x10
	add r7, r7, #0xa
	strb r7, [ip, #0x21]
	add ip, ip, #0x28
	blt _0203B12C
	add lr, lr, #1
	cmp lr, #8
	add r5, r5, #0x18000
	blt _0203B0F0
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203B230: .word ptr_FUN_020294c0_0208c4a4
_0203B234: .word _ZTV27CFieldScreenEffectActorData+8
_0203B238: .word 0x55555556
_0203B23C: .word DAT_0208db84
_0203B240: .word MAIN_BSS_0210CEC8

	arm_func_start sub_0203B244
sub_0203B244: ; 0x0203B244
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x138
	add r0, r0, #0x400
	bl _ZN10NtfTexture7ReleaseEv
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _0203B27C
	beq _0203B274
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_0203B244
_0203B274:
	mov r0, #0
	str r0, [r4, #0x24]
_0203B27C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0203B2A0
	beq _0203B298
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203B298:
	mov r0, #0
	str r0, [r4, #0x20]
_0203B2A0:
	mov r0, #1
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203B2A8
sub_0203B2A8: ; 0x0203B2A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN28CFieldScreenEffectObjectBase5StartEiii
	ldr r2, [r4, #0x590]
	ldr r1, [r4, #0x18]
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [r4, #0x568]
	ldmia sp!, {r4, pc}
	arm_func_end sub_0203B2A8

	arm_func_start sub_0203B2CC
sub_0203B2CC: ; 0x0203B2CC
	stmdb sp!, {r4, lr}
	ldr r1, _0203B308 ; =ptr_FUN_0203b314_0208dbb4
	mov r4, r0
	str r1, [r4]
	bl sub_0203B244
	add r0, r4, #0x154
	add r0, r0, #0x400
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x138
	add r0, r0, #0x400
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203B308: .word ptr_FUN_0203b314_0208dbb4
	arm_func_end sub_0203B2CC

	arm_func_start sub_0203B30C
sub_0203B30C: ; 0x0203B30C
	mov r0, #0xe
	bx lr
	arm_func_end sub_0203B30C

	arm_func_start sub_0203B314
sub_0203B314: ; 0x0203B314
	stmdb sp!, {r4, lr}
	ldr r1, _0203B348 ; =ptr_FUN_0203b314_0208dbb4
	mov r4, r0
	str r1, [r4]
	bl sub_0203B244
	add r0, r4, #0x154
	add r0, r0, #0x400
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x138
	add r0, r0, #0x400
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203B348: .word ptr_FUN_0203b314_0208dbb4
	arm_func_end sub_0203B314

	arm_func_start _ZN17CFieldSEFDarknessC1Ei
_ZN17CFieldSEFDarknessC1Ei: ; 0x0203B34C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0203B47C ; =_ZTV28CFieldScreenEffectObjectBase+8
	mov r4, r0
	str r2, [r4]
	mov r2, #4
	str r2, [r4, #0x1c]
	ldr r0, _0203B480 ; =ptr_FUN_0203bcc4_0208dbf8
	mov r2, #0
	str r0, [r4]
	str r2, [r4, #0x20]
	str r2, [r4, #0x24]
	str r2, [r4, #0x28]
	ldr r0, _0203B484 ; =g_ntfTextureFormats
	str r2, [r4, #0x2c]
	str r0, [r4, #0x30]
	str r2, [r4, #0x34]
	str r2, [r4, #0x38]
	str r2, [r4, #0x3c]
	str r2, [r4, #0x40]
	str r2, [r4, #0x44]
	str r2, [r4, #0x48]
	str r0, [r4, #0x4c]
	str r2, [r4, #0x50]
	add r0, r4, #0x68
	mov r5, r1
	str r2, [r4, #0x54]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _0203B488 ; =_ZTV17CPrimitiveRectNTF+8
	mov r0, #0
	str r1, [r4, #0x68]
	str r0, [r4, #0x80]
	ldr ip, _0203B48C ; =_ZN17CPrimitiveQuadNTFD1Ev
	ldr r3, _0203B490 ; =_ZN17CPrimitiveQuadNTFC1Ev
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r0, r4
	str r5, [r4, #0x58]
	bl sub_0203BB78
	mov r0, #0
	mov r2, r4
	mov r1, r0
	arm_func_end _ZN17CFieldSEFDarknessC1Ei
_0203B3FC:
	strh r1, [r2, #0xac]
	add r0, r0, #1
	str r1, [r2, #0xb8]
	cmp r0, #0x10
	add r2, r2, #0x5c
	blt _0203B3FC
	mov r2, r1
_0203B418:
	add r0, r4, r1, lsl #1
	add r0, r0, #0x600
	add r1, r1, #1
	strh r2, [r0, #0x64]
	cmp r1, #3
	add r2, r2, #0x300
	blt _0203B418
	mov ip, #0
	strh ip, [r4, #0x70]
	str ip, [r4, #0x7c]
	mov r0, #0xa
	str r0, [r4, #0x5c]
	mov r1, #8
	ldr r0, _0203B494 ; =_ZN12CFieldSEFFog7s_colorE
	str r1, [r4, #0x60]
	mov r3, #0x1f
	str r3, [r0]
	str r3, [r0, #4]
	ldr r2, _0203B498 ; =_ZN12CFieldSEFFog9s_densityE
	str r3, [r0, #8]
	ldr r1, _0203B49C ; =_ZN12CFieldSEFFog7s_dirtyE
	mov r0, r4
	str r3, [r2]
	str ip, [r1]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203B47C: .word _ZTV28CFieldScreenEffectObjectBase+8
_0203B480: .word ptr_FUN_0203bcc4_0208dbf8
_0203B484: .word g_ntfTextureFormats
_0203B488: .word _ZTV17CPrimitiveRectNTF+8
_0203B48C: .word _ZN17CPrimitiveQuadNTFD1Ev
_0203B490: .word _ZN17CPrimitiveQuadNTFC1Ev
_0203B494: .word _ZN12CFieldSEFFog7s_colorE
_0203B498: .word _ZN12CFieldSEFFog9s_densityE
_0203B49C: .word _ZN12CFieldSEFFog7s_dirtyE

	arm_func_start sub_0203B4A0
sub_0203B4A0: ; 0x0203B4A0
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r4, r0
	ldr r0, [r4, #0x64]
	mov r5, r1
	cmp r0, #0
	beq _0203B4CC
	subs r0, r0, #1
	str r0, [r4, #0x64]
	bne _0203B4CC
	add r0, r4, #0x20
	bl _ZN10NtfTexture12ReleaseFilesEv
	arm_func_end sub_0203B4A0
_0203B4CC:
	mov r0, r4
	mov r1, r5
	bl _ZN28CFieldScreenEffectObjectBase6UpdateEi
	mov r1, #0
	ldr ip, _0203B5FC ; =_ZN12CFieldSEFFog7s_colorE
	ldr r3, _0203B600 ; =_ZN12CFieldSEFFog9s_densityE
	ldr lr, _0203B604 ; =_ZN12CFieldSEFFog7s_dirtyE
	mov r2, r4
	mov r0, r1
	mov r5, r1
_0203B4F4:
	ldr r6, [lr]
	cmp r6, #0
	beq _0203B520
	ldr r7, [ip]
	ldmib ip, {r6, r8}
	orr r6, r7, r6, lsl #5
	orr r6, r6, r8, lsl #10
	strh r6, [r2, #0xac]
	ldr r6, [r3]
	str r6, [r4, #0x5c]
	str r0, [lr]
_0203B520:
	ldr r6, [r4, #4]
	cmp r6, #3
	beq _0203B540
	cmp r6, #4
	beq _0203B558
	cmp r6, #5
	beq _0203B564
	b _0203B57C
_0203B540:
	ldr r7, [r4, #0x5c]
	ldr r6, [r4, #0x18]
	mul r6, r7, r6
	mov r6, r6, asr #0xc
	str r6, [r2, #0xb8]
	b _0203B580
_0203B558:
	ldr r6, [r4, #0x5c]
	str r6, [r2, #0xb8]
	b _0203B580
_0203B564:
	ldr r7, [r4, #0x5c]
	ldr r6, [r4, #0x18]
	mul r6, r7, r6
	mov r6, r6, asr #0xc
	str r6, [r2, #0xb8]
	b _0203B580
_0203B57C:
	str r5, [r2, #0xb8]
_0203B580:
	add r1, r1, #1
	cmp r1, #0x10
	add r2, r2, #0x5c
	blt _0203B4F4
	ldr r0, [r4, #4]
	cmp r0, #3
	beq _0203B5B0
	cmp r0, #4
	beq _0203B5C8
	cmp r0, #5
	beq _0203B5D4
	b _0203B5EC
_0203B5B0:
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x7c]
	b _0203B5F4
_0203B5C8:
	ldr r0, [r4, #0x60]
	str r0, [r4, #0x7c]
	b _0203B5F4
_0203B5D4:
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x7c]
	b _0203B5F4
_0203B5EC:
	mov r0, #0
	str r0, [r4, #0x7c]
_0203B5F4:
	ldr r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0203B5FC: .word _ZN12CFieldSEFFog7s_colorE
_0203B600: .word _ZN12CFieldSEFFog9s_densityE
_0203B604: .word _ZN12CFieldSEFFog7s_dirtyE

	arm_func_start sub_0203B608
sub_0203B608: ; 0x0203B608
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x1c
	mov sl, r0
	ldr r0, [sl, #0xb8]
	str r1, [sp]
	cmp r0, #0
	addeq sp, sp, #0x1c
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, #0
	str r0, [sp, #0x18]
	str r0, [sp, #0x14]
	mov sb, r0
	sub r0, r0, #0x48
	str r0, [sp, #0x10]
	mov r0, #0x10
	str r0, [sp, #0xc]
	arm_func_end sub_0203B608
_0203B648:
	ldr r0, [sp, #0x14]
	mov r1, #0x5c
	mla r5, r0, r1, sl
	ldr r0, [sp, #0x10]
	mov r4, #0
	mov r2, r0, lsl #0xc
	sub r0, r2, #0x18000
	str r0, [sp, #8]
	add r0, r2, #0x18000
	str r0, [sp, #4]
	ldr r0, [sp, #0xc]
	mov r7, r4
	sub r6, r1, #0xbc
	mov fp, r0, lsl #0xc
	mov r8, #0x10
_0203B684:
	ldr r1, [sl, #0x1c]
	mov r0, r6, lsl #0xc
	str r1, [r5, #0xb4]
	sub r1, r0, #0x20000
	str r1, [r5, #0xc8]
	add r0, r0, #0x20000
	str r1, [r5, #0xc0]
	str r0, [r5, #0xd8]
	str r0, [r5, #0xd0]
	ldr r0, [sp, #8]
	str r0, [r5, #0xdc]
	str r0, [r5, #0xc4]
	ldr r0, [sp, #4]
	str r0, [r5, #0xd4]
	str r0, [r5, #0xcc]
	str r7, [r5, #0xe8]
	str r7, [r5, #0xe0]
	mov r0, r8, lsl #0xc
	str r0, [r5, #0xf8]
	str r0, [r5, #0xf0]
	str sb, [r5, #0xfc]
	str sb, [r5, #0xe4]
	str fp, [r5, #0xf4]
	add r0, sl, #0x20
	str fp, [r5, #0xec]
	bl _ZN10NtfTexture4BindEv
	add r4, r4, #1
	add r5, r5, #0x5c
	add r6, r6, #0x40
	add r7, r7, #0x10000
	add r8, r8, #0x10
	cmp r4, #4
	blt _0203B684
	ldr r0, [sp, #0x18]
	add sb, sb, #0x10000
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #4
	ldr r0, [sp, #0x14]
	add r0, r0, #4
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, r0, #0x30
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r0, r0, #0x10
	str r0, [sp, #0xc]
	blt _0203B648
	add r2, sl, #0x600
	ldrh r0, [r2, #0x64]
	mov r1, #0
	ldr r5, _0203BB70 ; =FX_SinCosTable_
	add r0, r0, #0x800
	strh r0, [r2, #0x64]
	ldrh r0, [r2, #0x66]
	sub r3, r1, #0x60000
	sub r4, r1, #0x48000
	sub r0, r0, #0xc00
	strh r0, [r2, #0x66]
	ldrh r6, [r2, #0x68]
	mov r0, sl
	sub r6, r6, #0x600
	strh r6, [r2, #0x68]
	strh r1, [r2, #0x64]
	strh r1, [r2, #0x66]
	strh r1, [r2, #0x68]
	ldrh r2, [r2, #0x64]
	mov r2, r2, asr #4
	mov r6, r2, lsl #1
	add r2, r6, #1
	mov r6, r6, lsl #1
	ldrsh r7, [r5, r6]
	mov r2, r2, lsl #1
	ldrsh r5, [r5, r2]
	mov r2, r7, asr #0x1f
	mov r8, r2, lsl #0xf
	mov r2, r5, asr #0x1f
	mov sb, r7, lsl #0xf
	mov r2, r2, lsl #0xf
	mov r6, r5, lsl #0xf
	orr r8, r8, r7, lsr #17
	mov r7, sb, lsr #0xc
	orr r7, r7, r8, lsl #20
	orr r2, r2, r5, lsr #17
	mov r5, r6, lsr #0xc
	orr r5, r5, r2, lsl #20
	sub r2, r3, r7
	sub r3, r4, r5
	bl sub_0203BBCC
	add r0, sl, #0x600
	ldrh r1, [r0, #0x68]
	mov r0, #0x60000
	ldr r2, _0203BB70 ; =FX_SinCosTable_
	mov r1, r1, asr #4
	mov r3, r1, lsl #1
	add r1, r3, #1
	mov r3, r3, lsl #1
	ldrsh r3, [r2, r3]
	mov r1, r1, lsl #1
	ldrsh r1, [r2, r1]
	mov r2, r3, asr #0x1f
	mov r2, r2, lsl #0xf
	orr r2, r2, r3, lsr #17
	mov r3, r3, lsl #0xf
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	rsb r0, r0, #0
	sub r2, r0, r3
	mov r0, r1, asr #0x1f
	mov r0, r0, lsl #0xf
	orr r0, r0, r1, lsr #17
	mov r1, r1, lsl #0xf
	mov r1, r1, lsr #0xc
	orr r1, r1, r0, lsl #20
	add r3, r1, #0x48000
	mov r0, sl
	mov r1, #8
	bl sub_0203BBCC
	add r0, sl, #0x600
	ldrh r0, [r0, #0x64]
	ldr r2, _0203BB70 ; =FX_SinCosTable_
	mov r1, #0x48000
	add r0, r0, #0x400
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	mov r0, r0, asr #4
	mov r4, r0, lsl #1
	mov r0, r4, lsl #1
	ldrsh r3, [r2, r0]
	add r0, r4, #1
	mov r0, r0, lsl #1
	ldrsh r2, [r2, r0]
	mov r0, r3, asr #0x1f
	mov r0, r0, lsl #0xf
	orr r0, r0, r3, lsr #17
	mov r3, r3, lsl #0xf
	mov r4, r3, lsr #0xc
	orr r4, r4, r0, lsl #20
	mov r0, r2, asr #0x1f
	mov r0, r0, lsl #0xf
	orr r0, r0, r2, lsr #17
	mov r2, r2, lsl #0xf
	mov r2, r2, lsr #0xc
	orr r2, r2, r0, lsl #20
	rsb r1, r1, #0
	sub r3, r1, r2
	mov r0, sl
	add r2, r4, #0x60000
	mov r1, #2
	bl sub_0203BBCC
	add r0, sl, #0x600
	ldrh r1, [r0, #0x66]
	ldr r2, _0203BB70 ; =FX_SinCosTable_
	mov r0, sl
	add r1, r1, #0x800
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	mov r1, r1, asr #4
	mov r3, r1, lsl #1
	add r1, r3, #1
	mov r3, r3, lsl #1
	ldrsh r4, [r2, r3]
	mov r1, r1, lsl #1
	ldrsh r2, [r2, r1]
	mov r1, r4, asr #0x1f
	mov r5, r1, lsl #0xf
	mov r1, r2, asr #0x1f
	mov r6, r4, lsl #0xf
	mov r1, r1, lsl #0xf
	mov r3, r2, lsl #0xf
	orr r5, r5, r4, lsr #17
	mov r4, r6, lsr #0xc
	orr r4, r4, r5, lsl #20
	orr r1, r1, r2, lsr #17
	mov r3, r3, lsr #0xc
	orr r3, r3, r1, lsl #20
	add r2, r4, #0x60000
	add r3, r3, #0x48000
	mov r1, #0xa
	bl sub_0203BBCC
	add r0, sl, #0x600
	ldrh r2, [r0, #0x66]
	mov r0, sl
	mov r1, #1
	add r2, r2, #0x800
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	mov r2, r2, asr #4
	mov r2, r2, lsl #1
	add r2, r2, #1
	mov r4, r2, lsl #1
	mov r2, #0
	ldr r3, _0203BB70 ; =FX_SinCosTable_
	ldrsh r4, [r3, r4]
	mov r3, r4, asr #0x1f
	mov r3, r3, lsl #0xf
	orr r3, r3, r4, lsr #17
	mov r4, r4, lsl #0xf
	mov r4, r4, lsr #0xc
	orr r4, r4, r3, lsl #20
	sub r3, r4, #0x48000
	bl sub_0203BBCC
	add r0, sl, #0x600
	ldrh r2, [r0, #0x68]
	mov r0, sl
	mov r1, #9
	add r2, r2, #0x600
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	mov r2, r2, asr #4
	mov r2, r2, lsl #1
	add r2, r2, #1
	mov r4, r2, lsl #1
	mov r2, #0
	ldr r3, _0203BB70 ; =FX_SinCosTable_
	ldrsh r4, [r3, r4]
	mov r3, r4, asr #0x1f
	mov r3, r3, lsl #0xf
	orr r3, r3, r4, lsr #17
	mov r4, r4, lsl #0xf
	mov r4, r4, lsr #0xc
	orr r4, r4, r3, lsl #20
	rsb r3, r4, #0x48000
	bl sub_0203BBCC
	mov r0, sl
	mov r1, #4
	add r2, sl, #0x600
	ldrh r2, [r2, #0x64]
	ldr r4, _0203BB70 ; =FX_SinCosTable_
	mov r3, #0
	add r2, r2, #0xc00
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	mov r2, r2, asr #4
	mov r2, r2, lsl #2
	ldrsh r4, [r4, r2]
	mov r2, r4, asr #0x1f
	mov r2, r2, lsl #0xf
	orr r2, r2, r4, lsr #17
	mov r4, r4, lsl #0xf
	mov r4, r4, lsr #0xc
	orr r4, r4, r2, lsl #20
	sub r2, r4, #0x60000
	bl sub_0203BBCC
	add r0, sl, #0x600
	ldrh r1, [r0, #0x66]
	ldr r2, _0203BB70 ; =FX_SinCosTable_
	mov r0, sl
	add r1, r1, #0xa00
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	mov r1, r1, asr #4
	mov r1, r1, lsl #2
	ldrsh r4, [r2, r1]
	mov r1, #6
	mov r3, #0
	mov r2, r4, asr #0x1f
	mov r2, r2, lsl #0xf
	mov r5, r4, lsl #0xf
	orr r2, r2, r4, lsr #17
	mov r4, r5, lsr #0xc
	orr r4, r4, r2, lsl #20
	rsb r2, r4, #0x60000
	bl sub_0203BBCC
	ldr r1, [sp]
	mov r0, sl
	bl _ZN28CFieldScreenEffectObjectBase11SetupMatrixEP17UnkClass_02003718
	add r5, sl, #0xa4
	mov r4, #0
_0203BAE8:
	mov r0, r5
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
	add r4, r4, #1
	cmp r4, #0x10
	add r5, r5, #0x5c
	blt _0203BAE8
	ldr r0, [sl, #0x7c]
	cmp r0, #0
	beq _0203BB5C
	ldr r1, [sl, #0x1c]
	mov r0, #0
	add r1, r1, #1
	str r1, [sl, #0x78]
	str r0, [sl, #0x84]
	str r0, [sl, #0x88]
	mov r0, #0x104000
	str r0, [sl, #0x8c]
	mov r1, #0xc8000
	add r0, sl, #0x3c
	str r1, [sl, #0x90]
	bl _ZN10NtfTexture4BindEv
	add r0, sl, #0x68
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
_0203BB5C:
	ldr r0, _0203BB74 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203BB70: .word FX_SinCosTable_
_0203BB74: .word 0x04000448

	arm_func_start sub_0203BB78
sub_0203BB78: ; 0x0203BB78
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, _0203BBA4 ; =s_data_field_effect_dokarimo03_ntf_0208dc14
	ldr r2, _0203BBA8 ; =s_data_field_effect_dokarimo03_ntf_0208dc38
	add r0, r4, #0x20
	mov r3, #4
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	mov r0, #2
	str r0, [r4, #0x64]
	mov r0, #1
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BBA4: .word s_data_field_effect_dokarimo03_ntf_0208dc14
_0203BBA8: .word s_data_field_effect_dokarimo03_ntf_0208dc38
	arm_func_end sub_0203BB78

	arm_func_start sub_0203BBAC
sub_0203BBAC: ; 0x0203BBAC
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	add r0, r4, #0x3c
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end sub_0203BBAC

	arm_func_start sub_0203BBCC
sub_0203BBCC: ; 0x0203BBCC
	stmdb sp!, {r4, r5, r6, lr}
	mov ip, #0x5c
	mla r6, r1, ip, r0
	add lr, r1, #1
	add r4, r1, #4
	add r1, r1, #5
	str r2, [r6, #0xd0]
	mla r5, lr, ip, r0
	str r3, [r6, #0xd4]
	str r2, [r5, #0xc8]
	mla lr, r4, ip, r0
	str r3, [r5, #0xcc]
	str r2, [lr, #0xd8]
	mla r0, r1, ip, r0
	str r3, [lr, #0xdc]
	str r2, [r0, #0xc0]
	str r3, [r0, #0xc4]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end sub_0203BBCC

	arm_func_start sub_0203BC14
sub_0203BC14: ; 0x0203BC14
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN28CFieldScreenEffectObjectBase5StartEiii
	mov ip, r4
	mov r3, #0
	arm_func_end sub_0203BC14
_0203BC28:
	ldr r2, [r4, #0x5c]
	ldr r1, [r4, #0x18]
	add r3, r3, #1
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [ip, #0xb8]
	cmp r3, #0x10
	add ip, ip, #0x5c
	blt _0203BC28
	ldr r2, [r4, #0x60]
	ldr r1, [r4, #0x18]
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [r4, #0x7c]
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203BC64
sub_0203BC64: ; 0x0203BC64
	stmdb sp!, {r4, lr}
	ldr r1, _0203BCB4 ; =ptr_FUN_0203bcc4_0208dbf8
	mov r4, r0
	str r1, [r4]
	bl sub_0203BBAC
	ldr r3, _0203BCB8 ; =_ZN17CPrimitiveQuadNTFD1Ev
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	add r0, r4, #0x68
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c
	bl _ZN10NtfTexture7ReleaseEv
	add r0, r4, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BCB4: .word ptr_FUN_0203bcc4_0208dbf8
_0203BCB8: .word _ZN17CPrimitiveQuadNTFD1Ev
	arm_func_end sub_0203BC64

	arm_func_start sub_0203BCBC
sub_0203BCBC: ; 0x0203BCBC
	ldr r0, [r0, #0x58]
	bx lr
	arm_func_end sub_0203BCBC

	arm_func_start sub_0203BCC4
sub_0203BCC4: ; 0x0203BCC4
	stmdb sp!, {r4, lr}
	ldr r1, _0203BD0C ; =ptr_FUN_0203bcc4_0208dbf8
	mov r4, r0
	str r1, [r4]
	bl sub_0203BBAC
	ldr r3, _0203BD10 ; =_ZN17CPrimitiveQuadNTFD1Ev
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	add r0, r4, #0x68
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c
	bl _ZN10NtfTexture7ReleaseEv
	add r0, r4, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BD0C: .word ptr_FUN_0203bcc4_0208dbf8
_0203BD10: .word _ZN17CPrimitiveQuadNTFD1Ev
	arm_func_end sub_0203BCC4
