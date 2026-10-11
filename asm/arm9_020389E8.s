    .include "macros.inc"
    .include "include/arm9_020389E8.inc"

    .text

	arm_func_start _ZN17CFieldSEFTheWaterC1Ei
_ZN17CFieldSEFTheWaterC1Ei: ; 0x020389E8
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, _02038AE4 ; =_ZTV28CFieldScreenEffectObjectBase+8
	mov r5, r0
	str r2, [r5]
	mov r2, #4
	ldr r0, _02038AE8 ; =ptr_FUN_02038cd4_0208da08
	str r2, [r5, #0x1c]
	str r0, [r5]
	mov r2, #0
	str r2, [r5, #0x20]
	str r2, [r5, #0x24]
	str r2, [r5, #0x28]
	ldr r0, _02038AEC ; =g_ntfTextureFormats
	str r2, [r5, #0x2c]
	str r0, [r5, #0x30]
	str r2, [r5, #0x34]
	add r0, r5, #0x44
	mov r6, r1
	str r2, [r5, #0x38]
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _02038AF0 ; =_ZTV17CPrimitiveRectNTF+8
	mov r1, #0
	str r0, [r5, #0x44]
	mov r0, r5
	str r1, [r5, #0x5c]
	bl sub_02038C54
	str r6, [r5, #0x3c]
	cmp r6, #0xa
	beq _02038A78
	cmp r6, #0xb
	beq _02038A88
	cmp r6, #0xf
	moveq r0, #0xa
	streq r0, [r5, #0x40]
	moveq r4, #0
	b _02038A94
	arm_func_end _ZN17CFieldSEFTheWaterC1Ei
_02038A78:
	mov r0, #0x10
	str r0, [r5, #0x40]
	ldr r4, _02038AF4 ; =0x00007FE0
	b _02038A94
_02038A88:
	mov r0, #0xa
	str r0, [r5, #0x40]
	mov r4, #0
_02038A94:
	strh r4, [r5, #0x4c]
	mov ip, #0
	str ip, [r5, #0x58]
	ldrh r1, [r5, #0x4c]
	ldr r4, [r5, #0x40]
	ldr r0, _02038AF8 ; =_ZN12CFieldSEFFog7s_colorE
	and r3, r1, #0x1f
	mov r2, r1, asr #5
	mov r1, r1, asr #0xa
	str r3, [r0]
	and r2, r2, #0x1f
	str r2, [r0, #4]
	and r1, r1, #0x1f
	ldr r2, _02038AFC ; =_ZN12CFieldSEFFog9s_densityE
	str r1, [r0, #8]
	ldr r1, _02038B00 ; =_ZN12CFieldSEFFog7s_dirtyE
	mov r0, r5
	str r4, [r2]
	str ip, [r1]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02038AE4: .word _ZTV28CFieldScreenEffectObjectBase+8
_02038AE8: .word ptr_FUN_02038cd4_0208da08
_02038AEC: .word g_ntfTextureFormats
_02038AF0: .word _ZTV17CPrimitiveRectNTF+8
_02038AF4: .word 0x00007FE0
_02038AF8: .word _ZN12CFieldSEFFog7s_colorE
_02038AFC: .word _ZN12CFieldSEFFog9s_densityE
_02038B00: .word _ZN12CFieldSEFFog7s_dirtyE

	arm_func_start sub_02038B04
sub_02038B04: ; 0x02038B04
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN28CFieldScreenEffectObjectBase6UpdateEi
	ldr r2, _02038BB8 ; =_ZN12CFieldSEFFog7s_dirtyE
	ldr r0, [r2]
	cmp r0, #0
	beq _02038B4C
	ldr r1, _02038BBC ; =_ZN12CFieldSEFFog7s_colorE
	ldr r0, _02038BC0 ; =_ZN12CFieldSEFFog9s_densityE
	ldr ip, [r1]
	ldmib r1, {r3, lr}
	orr r1, ip, r3, lsl #5
	orr r1, r1, lr, lsl #10
	strh r1, [r4, #0x4c]
	ldr r1, [r0]
	mov r0, #0
	str r1, [r4, #0x40]
	str r0, [r2]
	arm_func_end sub_02038B04
_02038B4C:
	ldr r0, [r4, #4]
	cmp r0, #3
	beq _02038B6C
	cmp r0, #4
	beq _02038B84
	cmp r0, #5
	beq _02038B90
	b _02038BA8
_02038B6C:
	ldr r1, [r4, #0x40]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x58]
	b _02038BB0
_02038B84:
	ldr r0, [r4, #0x40]
	str r0, [r4, #0x58]
	b _02038BB0
_02038B90:
	ldr r1, [r4, #0x40]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x58]
	b _02038BB0
_02038BA8:
	mov r0, #0
	str r0, [r4, #0x58]
_02038BB0:
	ldr r0, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02038BB8: .word _ZN12CFieldSEFFog7s_dirtyE
_02038BBC: .word _ZN12CFieldSEFFog7s_colorE
_02038BC0: .word _ZN12CFieldSEFFog9s_densityE

	arm_func_start sub_02038BC4
sub_02038BC4: ; 0x02038BC4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r2, [r5, #0x58]
	mov r4, r1
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl _ZN28CFieldScreenEffectObjectBase11SetupMatrixEP17UnkClass_02003718
	ldr r1, [r5, #0x1c]
	mov r0, #0
	str r1, [r5, #0x54]
	str r0, [r5, #0x60]
	str r0, [r5, #0x64]
	mov r0, #0x100000
	str r0, [r5, #0x68]
	str r0, [r5, #0x6c]
	add r0, r5, #0x20
	bl _ZN10NtfTexture4BindEv
	ldr r0, [r5, #0x1c]
	ldr r2, [r5, #0x58]
	add r0, r0, #3
	mov r0, r0, lsl #0x18
	orr r1, r0, #0xc0
	ldr r0, _02038C4C ; =0x040004A4
	orr r1, r1, r2, lsl #16
	str r1, [r0]
	add r0, r5, #0x44
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r0, _02038C50 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02038C4C: .word 0x040004A4
_02038C50: .word 0x04000448
	arm_func_end sub_02038BC4

	arm_func_start sub_02038C54
sub_02038C54: ; 0x02038C54
	mov r0, #1
	bx lr
	arm_func_end sub_02038C54

	arm_func_start sub_02038C5C
sub_02038C5C: ; 0x02038C5C
	stmdb sp!, {r3, lr}
	add r0, r0, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, #1
	ldmia sp!, {r3, pc}
	arm_func_end sub_02038C5C

	arm_func_start sub_02038C70
sub_02038C70: ; 0x02038C70
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN28CFieldScreenEffectObjectBase5StartEiii
	ldr r2, [r4, #0x40]
	ldr r1, [r4, #0x18]
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [r4, #0x58]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02038C70

	arm_func_start sub_02038C94
sub_02038C94: ; 0x02038C94
	stmdb sp!, {r4, lr}
	ldr r1, _02038CC8 ; =ptr_FUN_02038cd4_0208da08
	mov r4, r0
	str r1, [r4]
	bl sub_02038C5C
	add r0, r4, #0x44
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02038CC8: .word ptr_FUN_02038cd4_0208da08
	arm_func_end sub_02038C94

	arm_func_start sub_02038CCC
sub_02038CCC: ; 0x02038CCC
	ldr r0, [r0, #0x3c]
	bx lr
	arm_func_end sub_02038CCC

	arm_func_start sub_02038CD4
sub_02038CD4: ; 0x02038CD4
	stmdb sp!, {r4, lr}
	ldr r1, _02038D00 ; =ptr_FUN_02038cd4_0208da08
	mov r4, r0
	str r1, [r4]
	bl sub_02038C5C
	add r0, r4, #0x44
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x20
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02038D00: .word ptr_FUN_02038cd4_0208da08
	arm_func_end sub_02038CD4

	arm_func_start _ZN15CFieldSEFHinokoC1Ei
_ZN15CFieldSEFHinokoC1Ei: ; 0x02038D04
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, _02038DCC ; =_ZTV28CFieldScreenEffectObjectBase+8
	mov r5, r0
	str r2, [r5]
	mov r2, #4
	str r2, [r5, #0x1c]
	ldr r0, _02038DD0 ; =ptr_FUN_02039ddc_0208da78
	mov r2, #0
	str r0, [r5]
	str r2, [r5, #0x3c0]
	str r2, [r5, #0x3c4]
	str r2, [r5, #0x3c8]
	ldr r0, _02038DD4 ; =g_ntfTextureFormats
	str r2, [r5, #0x3cc]
	str r0, [r5, #0x3d0]
	str r2, [r5, #0x3d4]
	add r0, r5, #0x3dc
	mov r4, r1
	str r2, [r5, #0x3d8]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _02038DD8 ; =_ZTV17CPrimitiveRectNTF+8
	mov r0, r5
	str r1, [r5, #0x3dc]
	mov r1, #0
	str r1, [r5, #0x3f4]
	bl sub_02039818
	ldr r1, _02038DDC ; =0x00002A52
	add r0, r5, #0x300
	strh r1, [r0, #0xe4]
	mov r6, #0
	mov lr, #0x15
	str r6, [r5, #0x3f0]
	str lr, [r5, #0x418]
	ldrh r0, [r0, #0xe4]
	ldr r2, _02038DE0 ; =_ZN12CFieldSEFFog7s_colorE
	ldr r1, _02038DE4 ; =_ZN12CFieldSEFFog9s_densityE
	and ip, r0, #0x1f
	mov r3, r0, asr #5
	mov r0, r0, asr #0xa
	str ip, [r2]
	and r3, r3, #0x1f
	str r3, [r2, #4]
	and r3, r0, #0x1f
	str r3, [r2, #8]
	ldr r0, _02038DE8 ; =_ZN12CFieldSEFFog7s_dirtyE
	str lr, [r1]
	str r6, [r0]
	mov r0, r5
	str r4, [r5, #0x41c]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02038DCC: .word _ZTV28CFieldScreenEffectObjectBase+8
_02038DD0: .word ptr_FUN_02039ddc_0208da78
_02038DD4: .word g_ntfTextureFormats
_02038DD8: .word _ZTV17CPrimitiveRectNTF+8
_02038DDC: .word 0x00002A52
_02038DE0: .word _ZN12CFieldSEFFog7s_colorE
_02038DE4: .word _ZN12CFieldSEFFog9s_densityE
_02038DE8: .word _ZN12CFieldSEFFog7s_dirtyE
	arm_func_end _ZN15CFieldSEFHinokoC1Ei

	arm_func_start sub_02038DEC
sub_02038DEC: ; 0x02038DEC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	ldr r0, [r4, #0x3bc]
	mov r5, r1
	cmp r0, #0
	beq _02038E18
	subs r0, r0, #1
	str r0, [r4, #0x3bc]
	bne _02038E18
	add r0, r4, #0x3c0
	bl _ZN10NtfTexture12ReleaseFilesEv
	arm_func_end sub_02038DEC
_02038E18:
	mov r0, r4
	mov r1, r5
	bl _ZN28CFieldScreenEffectObjectBase6UpdateEi
	ldr r2, _020394B0 ; =_ZN12CFieldSEFFog7s_dirtyE
	ldr r0, [r2]
	cmp r0, #0
	beq _02038E64
	ldr r1, _020394B4 ; =_ZN12CFieldSEFFog7s_colorE
	add r0, r4, #0x300
	ldr r5, [r1]
	ldmib r1, {r3, r6}
	orr r1, r5, r3, lsl #5
	orr r3, r1, r6, lsl #10
	strh r3, [r0, #0xe4]
	ldr r1, _020394B8 ; =_ZN12CFieldSEFFog9s_densityE
	mov r0, #0
	ldr r1, [r1]
	str r1, [r4, #0x418]
	str r0, [r2]
_02038E64:
	ldr r0, [r4, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	ldr r0, [r4, #0x41c]
	cmp r0, #0
	beq _020393B8
	mov r3, #0xa3
	ldr lr, _020394BC ; =MAIN_BSS_0210CEC8
	ldr r5, _020394C0 ; =_ZN28CFieldScreenEffectObjectBase11s_frameStepE
	ldr ip, _020394C4 ; =_ZN28CFieldScreenEffectObjectBase8s_scrollE
	add r1, r4, #0x3c
	mov r0, #0
	mov fp, r3
_02038E9C:
	ldrb r6, [r1, #0x18]
	ldr r2, [r5]
	add r2, r6, r2
	strb r2, [r1, #0x18]
	ldr r7, [r1, #8]
	ldr r6, [r5]
	ldr r2, [r1]
	mul r8, r7, r6
	mov r6, r8, asr #0x1f
	mov r6, r6, lsl #0xc
	mov r7, r8, lsl #0xc
	orr r6, r6, r8, lsr #20
	mov r7, r7, lsr #0xc
	orr r7, r7, r6, lsl #20
	adds r2, r2, r7
	str r2, [r1]
	bpl _02038F2C
	add r2, r2, #0x140000
	str r2, [r1]
	ldmia lr, {r2, r6, r7}
	mla r2, r6, r2, r7
	str r2, [lr]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #4
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r7, r2, lsr #4
	umull sb, r8, r7, r3
	mov r6, r7, asr #0x1f
	mla r8, r6, r3, r8
	mov r2, sb, lsr #0xc
	orr r2, r2, r8, lsl #20
	add r2, r2, #0x66
	add r2, r2, #0x600
	str r2, [r1, #0xc]
	b _02038F38
_02038F2C:
	cmp r2, #0x140000
	subgt r2, r2, #0x140000
	strgt r2, [r1]
_02038F38:
	ldr r7, [r1, #0xc]
	ldr r6, [r5]
	ldr r2, [r1, #4]
	mul r8, r7, r6
	mov r6, r8, asr #0x1f
	mov r6, r6, lsl #0xc
	mov r7, r8, lsl #0xc
	orr r6, r6, r8, lsr #20
	mov r7, r7, lsr #0xc
	orr r7, r7, r6, lsl #20
	adds r2, r2, r7
	str r2, [r1, #4]
	bpl _02038F7C
	ldr r2, [r1, #4]
	add r2, r2, #0x100000
	str r2, [r1, #4]
	b _02038FD0
_02038F7C:
	cmp r2, #0x100000
	ble _02038FD0
	ldr r2, [r1, #4]
	sub r2, r2, #0x100000
	str r2, [r1, #4]
	ldmia lr, {r2, r6, r7}
	mla r2, r6, r2, r7
	str r2, [lr]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #4
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r7, r2, lsr #4
	umull sb, r8, r7, fp
	mov r6, r7, asr #0x1f
	mla r8, r6, fp, r8
	mov r2, sb, lsr #0xc
	orr r2, r2, r8, lsl #20
	add r2, r2, #0x66
	add r2, r2, #0x600
	str r2, [r1, #0xc]
_02038FD0:
	ldr r7, [lr]
	ldmib lr, {r2, r6}
	mla r7, r2, r7, r6
	mov r8, r7, lsr #0x10
	mov r8, r8, lsl #3
	mov r8, r8, lsr #0x10
	mov r8, r8, lsl #0x10
	str r7, [lr]
	movs r8, r8, lsr #0x10
	bne _0203903C
	mla r6, r2, r7, r6
	mov r2, r6, lsr #0x10
	mov r2, r2, lsl #1
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r7, r2, lsr #4
	mov r2, #0xa3
	str r6, [lr]
	umull sb, r8, r7, r2
	mov r6, r7, asr #0x1f
	mov r2, #0xa3
	mla r8, r6, r2, r8
	mov r2, sb, lsr #0xc
	ldr sl, [r1, #0xc]
	orr r2, r2, r8, lsl #20
	add r2, sl, r2
	str r2, [r1, #0xc]
_0203903C:
	ldr r6, [r1]
	ldr r2, [ip]
	add r2, r6, r2
	str r2, [r1]
	ldr r6, [r1, #4]
	ldr r2, [ip, #4]
	add r2, r6, r2
	str r2, [r1, #4]
	ldrb r2, [r1, #0x19]
	cmp r2, #0
	sub r2, r2, #1
	strb r2, [r1, #0x19]
	bne _0203910C
	ldmia lr, {r2, r6, r7}
	mla r2, r6, r2, r7
	str r2, [lr]
	mov r6, r2, lsr #0x10
	mov r2, #0xa
	mul r2, r6, r2
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	add r2, r2, #0xa
	strb r2, [r1, #0x19]
	ldmia lr, {r2, r6, r7}
	mla r2, r6, r2, r7
	str r2, [lr]
	mov r6, r2, lsr #0x10
	mov r2, #0xc
	mul r2, r6, r2
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r8, r2, lsr #4
	mov r2, #0xcc
	umull sl, sb, r8, r2
	mov r7, r8, asr #0x1f
	mov r2, #0xcc
	mla sb, r7, r2, sb
	mov r2, sl, lsr #0xc
	orr r2, r2, sb, lsl #20
	add r2, r2, #0x33
	ldr r6, [r1, #0x10]
	add r2, r2, #0xb00
	smull r8, r7, r6, r2
	mov r6, r8, lsr #0xc
	orr r6, r6, r7, lsl #20
	str r6, [r1, #8]
	ldr r6, [r1, #0x14]
	smull r7, r2, r6, r2
	mov r6, r7, lsr #0xc
	orr r6, r6, r2, lsl #20
	str r6, [r1, #0xc]
_0203910C:
	add r1, r1, #0x1c
	add r0, r0, #1
	cmp r0, #0x10
	blt _02038E9C
	mov r3, #0xa3
	ldr r6, _020394BC ; =MAIN_BSS_0210CEC8
	ldr r7, _020394C0 ; =_ZN28CFieldScreenEffectObjectBase11s_frameStepE
	ldr r5, _020394C4 ; =_ZN28CFieldScreenEffectObjectBase8s_scrollE
	add r1, r4, #0x1fc
	mov r0, #0
	mov lr, r3
_02039138:
	ldrb r8, [r1, #0x18]
	ldr r2, [r7]
	add r2, r8, r2
	strb r2, [r1, #0x18]
	ldr sb, [r1, #8]
	ldr r8, [r7]
	ldr r2, [r1]
	mul sl, sb, r8
	mov r8, sl, asr #0x1f
	mov r8, r8, lsl #0xc
	mov sb, sl, lsl #0xc
	orr r8, r8, sl, lsr #20
	mov sb, sb, lsr #0xc
	orr sb, sb, r8, lsl #20
	adds r2, r2, sb
	str r2, [r1]
	bpl _020391C8
	add r2, r2, #0x140000
	str r2, [r1]
	ldmia r6, {r2, r8, sb}
	mla r2, r8, r2, sb
	str r2, [r6]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #4
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov sb, r2, lsr #4
	umull fp, sl, sb, r3
	mov r8, sb, asr #0x1f
	mla sl, r8, r3, sl
	mov r2, fp, lsr #0xc
	orr r2, r2, sl, lsl #20
	add r2, r2, #0x66
	add r2, r2, #0x600
	str r2, [r1, #0xc]
	b _020391D4
_020391C8:
	cmp r2, #0x140000
	subgt r2, r2, #0x140000
	strgt r2, [r1]
_020391D4:
	ldr sb, [r1, #0xc]
	ldr r8, [r7]
	ldr r2, [r1, #4]
	mul sl, sb, r8
	mov r8, sl, asr #0x1f
	mov r8, r8, lsl #0xc
	mov sb, sl, lsl #0xc
	orr r8, r8, sl, lsr #20
	mov sb, sb, lsr #0xc
	orr sb, sb, r8, lsl #20
	adds r2, r2, sb
	str r2, [r1, #4]
	bpl _02039218
	ldr r2, [r1, #4]
	add r2, r2, #0x100000
	str r2, [r1, #4]
	b _0203926C
_02039218:
	cmp r2, #0x100000
	ble _0203926C
	ldr r2, [r1, #4]
	sub r2, r2, #0x100000
	str r2, [r1, #4]
	ldmia r6, {r2, r8, sb}
	mla r2, r8, r2, sb
	str r2, [r6]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #4
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov sb, r2, lsr #4
	umull fp, sl, sb, lr
	mov r8, sb, asr #0x1f
	mla sl, r8, lr, sl
	mov r2, fp, lsr #0xc
	orr r2, r2, sl, lsl #20
	add r2, r2, #0x66
	add r2, r2, #0x600
	str r2, [r1, #0xc]
_0203926C:
	ldr sb, [r6]
	ldmib r6, {r2, r8}
	mla sb, r2, sb, r8
	mov sl, sb, lsr #0x10
	mov sl, sl, lsl #3
	mov sl, sl, lsr #0x10
	mov sl, sl, lsl #0x10
	str sb, [r6]
	movs sl, sl, lsr #0x10
	bne _020392D8
	mla r8, r2, sb, r8
	mov r2, r8, lsr #0x10
	mov r2, r2, lsl #1
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov sb, r2, lsr #4
	mov r2, #0xa3
	str r8, [r6]
	umull fp, sl, sb, r2
	mov r8, sb, asr #0x1f
	mov r2, #0xa3
	mla sl, r8, r2, sl
	mov r2, fp, lsr #0xc
	ldr ip, [r1, #0xc]
	orr r2, r2, sl, lsl #20
	add r2, ip, r2
	str r2, [r1, #0xc]
_020392D8:
	ldr r8, [r1]
	ldr r2, [r5]
	add r2, r8, r2
	str r2, [r1]
	ldr r8, [r1, #4]
	ldr r2, [r5, #4]
	add r2, r8, r2
	str r2, [r1, #4]
	ldrb r2, [r1, #0x19]
	cmp r2, #0
	sub r2, r2, #1
	strb r2, [r1, #0x19]
	bne _020393A8
	ldmia r6, {r2, r8, sb}
	mla r2, r8, r2, sb
	str r2, [r6]
	mov r8, r2, lsr #0x10
	mov r2, #0xa
	mul r2, r8, r2
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	add r2, r2, #0xa
	strb r2, [r1, #0x19]
	ldmia r6, {r2, r8, sb}
	mla r2, r8, r2, sb
	str r2, [r6]
	mov r8, r2, lsr #0x10
	mov r2, #0xc
	mul r2, r8, r2
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov sl, r2, lsr #4
	mov r2, #0xcc
	umull ip, fp, sl, r2
	mov sb, sl, asr #0x1f
	mov r2, #0xcc
	mla fp, sb, r2, fp
	mov r2, ip, lsr #0xc
	orr r2, r2, fp, lsl #20
	add r2, r2, #0x33
	ldr r8, [r1, #0x10]
	add r2, r2, #0xb00
	smull sl, sb, r8, r2
	mov r8, sl, lsr #0xc
	orr r8, r8, sb, lsl #20
	str r8, [r1, #8]
	ldr r8, [r1, #0x14]
	smull sb, r2, r8, r2
	mov r8, sb, lsr #0xc
	orr r8, r8, r2, lsl #20
	str r8, [r1, #0xc]
_020393A8:
	add r1, r1, #0x1c
	add r0, r0, #1
	cmp r0, #0x10
	blt _02039138
_020393B8:
	ldr r0, _020394C0 ; =_ZN28CFieldScreenEffectObjectBase11s_frameStepE
	ldr r0, [r0]
	bl _f_itof
	mov r1, r0
	ldr r0, _020394C8 ; =0xBDCCCCCD
	bl _f_mul
	mov r1, r0
	ldr r0, _020394CC ; =0x45800000
	bl _f_mul
	bl _f_ftoi
	ldr r2, _020394C4 ; =_ZN28CFieldScreenEffectObjectBase8s_scrollE
	ldr r7, [r4, #0x420]
	ldr r5, [r2]
	ldr r1, _020394D0 ; =0x000FFFFF
	mov r3, r5, asr #0x1f
	mov r3, r3, lsl #0xb
	mov r6, r5, lsl #0xb
	orr r3, r3, r5, lsr #21
	mov r5, r6, lsr #0xc
	orr r5, r5, r3, lsl #20
	add r0, r0, r5
	sub r0, r7, r0
	and r0, r0, r1
	str r0, [r4, #0x420]
	ldr r2, [r2, #4]
	ldr r5, [r4, #0x424]
	mov r0, r2, asr #0x1f
	mov r0, r0, lsl #0xb
	mov r3, r2, lsl #0xb
	orr r0, r0, r2, lsr #21
	mov r2, r3, lsr #0xc
	orr r2, r2, r0, lsl #20
	sub r0, r5, r2
	and r0, r0, r1
	str r0, [r4, #0x424]
	ldr r0, [r4, #4]
	cmp r0, #3
	beq _02039464
	cmp r0, #4
	beq _0203947C
	cmp r0, #5
	beq _02039488
	b _020394A0
_02039464:
	ldr r1, [r4, #0x418]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x3f0]
	b _020394A8
_0203947C:
	ldr r0, [r4, #0x418]
	str r0, [r4, #0x3f0]
	b _020394A8
_02039488:
	ldr r1, [r4, #0x418]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x3f0]
	b _020394A8
_020394A0:
	mov r0, #0
	str r0, [r4, #0x3f0]
_020394A8:
	ldr r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_020394B0: .word _ZN12CFieldSEFFog7s_dirtyE
_020394B4: .word _ZN12CFieldSEFFog7s_colorE
_020394B8: .word _ZN12CFieldSEFFog9s_densityE
_020394BC: .word MAIN_BSS_0210CEC8
_020394C0: .word _ZN28CFieldScreenEffectObjectBase11s_frameStepE
_020394C4: .word _ZN28CFieldScreenEffectObjectBase8s_scrollE
_020394C8: .word 0xBDCCCCCD
_020394CC: .word 0x45800000
_020394D0: .word 0x000FFFFF

	arm_func_start sub_020394D4
sub_020394D4: ; 0x020394D4
	stmdb sp!, {r4, lr}
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	mov r4, r0
	blx r2
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	bl _ZN17UnkClass_0200878812sub_020089ECEv
	ldmia sp!, {r4, pc}
	arm_func_end sub_020394D4

	arm_func_start sub_02039510
sub_02039510: ; 0x02039510
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x48
	mov sb, r0
	ldr r0, [sb, #0x20]
	mov r8, r1
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x10]
	blx r2
	ldr sl, [r8, #0x1c]
	ldr r4, [r8, #0x20]
	ldr r1, [sb, #0x41c]
	mov r5, r0
	str sl, [sp, #0x30]
	str r4, [sp, #0x34]
	cmp r1, #0
	beq _02039784
	ldr fp, _02039810 ; =0x00007FFF
	add r7, sb, #0x3c
	mov r6, #0
	arm_func_end sub_02039510
_02039560:
	ldrb r1, [r7, #0x18]
	mov r0, r1, asr #6
	and r0, r0, #3
	cmp r0, #3
	addls pc, pc, r0, lsl #2
	b _020395C8
_02039578: ; jump table
	b _02039588 ; case 0
	b _02039598 ; case 1
	b _020395A4 ; case 2
	b _020395C8 ; case 3
_02039588:
	mov r0, r1, asr #1
	mov r1, fp
	and r0, r0, #0xff
	b _020395D0
_02039598:
	mov r0, #0x1f
	mov r1, fp
	b _020395D0
_020395A4:
	mov r0, r1, asr #1
	and r0, r0, #0x1f
	rsb r0, r0, #0x1f
	and r0, r0, #0xff
	orr r1, r0, r0, lsl #5
	orr r1, r1, r0, lsl #10
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	b _020395D0
_020395C8:
	mov r0, #0
	mov r1, r0
_020395D0:
	cmp r0, #0
	beq _0203965C
	ldr r3, [sb, #0x24]
	mov r2, r6, lsl #0x1d
	strh r1, [r3, #8]
	ldr r3, [sb, #0x24]
	add r1, sb, r2, lsr #28
	str r0, [r3, #0x14]
	ldrh r1, [r1, #0x28]
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_02008828Et
	ldr r2, [sb, #0x24]
	mov r1, r8
	strh r0, [r2, #0x2a]
	ldr r0, [r7]
	str sl, [sp, #0x28]
	sub r0, r0, sl
	str r4, [sp, #0x2c]
	str r0, [sp, #0x20]
	sub r2, r0, #0xa0000
	str r2, [sp, #0x40]
	str r2, [sp, #0x18]
	ldr r3, [r7, #4]
	ldr r0, [sb, #0x24]
	sub r3, r3, r4
	str r2, [r0, #0x18]
	str r3, [sp, #0x24]
	sub r2, r3, #0x80000
	str r2, [r0, #0x1c]
	str r2, [sp, #0x44]
	str r2, [sp, #0x1c]
	ldr r0, [sb, #0x24]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
_0203965C:
	add r6, r6, #1
	cmp r6, #0x10
	add r7, r7, #0x1c
	blt _02039560
	ldr sl, [sp, #0x30]
	ldr r4, [sp, #0x34]
	ldr fp, _02039810 ; =0x00007FFF
	add r7, sb, #0x1fc
	mov r6, #0
_02039680:
	ldrb r1, [r7, #0x18]
	mov r0, r1, asr #6
	and r0, r0, #3
	cmp r0, #3
	addls pc, pc, r0, lsl #2
	b _020396E8
_02039698: ; jump table
	b _020396A8 ; case 0
	b _020396B8 ; case 1
	b _020396C4 ; case 2
	b _020396E8 ; case 3
_020396A8:
	mov r0, r1, asr #1
	mov r2, fp
	and r1, r0, #0xff
	b _020396F0
_020396B8:
	mov r1, #0x1f
	mov r2, fp
	b _020396F0
_020396C4:
	mov r0, r1, asr #1
	and r0, r0, #0x1f
	rsb r0, r0, #0x1f
	and r1, r0, #0xff
	orr r0, r1, r1, lsl #5
	orr r0, r0, r1, lsl #10
	mov r0, r0, lsl #0x10
	mov r2, r0, lsr #0x10
	b _020396F0
_020396E8:
	mov r1, #0
	mov r2, r1
_020396F0:
	cmp r1, #0
	beq _02039774
	ldr r3, [sb, #0x24]
	mov r0, r5
	strh r2, [r3, #8]
	ldr r2, [sb, #0x24]
	str r1, [r2, #0x14]
	ldrh r1, [sb, #0x38]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	ldr r2, [sb, #0x24]
	mov r1, r8
	strh r0, [r2, #0x2a]
	ldr r0, [r7]
	str sl, [sp, #0x10]
	sub r0, r0, sl
	str r4, [sp, #0x14]
	str r0, [sp, #8]
	sub r2, r0, #0xa0000
	str r2, [sp, #0x38]
	str r2, [sp]
	ldr r3, [r7, #4]
	ldr r0, [sb, #0x24]
	sub r3, r3, r4
	str r2, [r0, #0x18]
	str r3, [sp, #0xc]
	sub r2, r3, #0x80000
	str r2, [r0, #0x1c]
	str r2, [sp, #0x3c]
	str r2, [sp, #4]
	ldr r0, [sb, #0x24]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
_02039774:
	add r6, r6, #1
	cmp r6, #0x10
	add r7, r7, #0x1c
	blt _02039680
_02039784:
	ldr r0, [sb, #0x3f0]
	cmp r0, #0
	addeq sp, sp, #0x48
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, sb
	mov r1, r8
	bl _ZN28CFieldScreenEffectObjectBase11SetupMatrixEP17UnkClass_02003718
	ldr r1, [sb, #0x1c]
	mov r0, #0
	str r1, [sb, #0x3ec]
	str r0, [sb, #0x3f8]
	str r0, [sb, #0x3fc]
	mov r0, #0x100000
	str r0, [sb, #0x400]
	str r0, [sb, #0x404]
	ldr r2, [sb, #0x424]
	ldr r0, [sb, #0x420]
	add r1, r2, #0x80000
	str r0, [sb, #0x408]
	str r2, [sb, #0x40c]
	add r0, r0, #0x80000
	str r0, [sb, #0x410]
	add r0, sb, #0x3c0
	str r1, [sb, #0x414]
	bl _ZN10NtfTexture4BindEv
	add r0, sb, #0x3dc
	ldr r2, [r0]
	mov r1, r8
	ldr r2, [r2, #8]
	blx r2
	ldr r0, _02039814 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	add sp, sp, #0x48
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02039810: .word 0x00007FFF
_02039814: .word 0x04000448

	arm_func_start sub_02039818
sub_02039818: ; 0x02039818
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x10
	str r0, [sp]
	mov r0, #0x34
	bl _Znwm
	movs r4, r0
	beq _02039858
	ldr r1, _02039CD4 ; =ptr_FUN_020294c0_0208c4a4
	add r0, r4, #4
	str r1, [r4]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r1, #0
	str r1, [r4, #0x2c]
	ldr r0, _02039CD8 ; =PTR_LAB_0208da9c
	str r1, [r4, #0x30]
	str r0, [r4]
	arm_func_end sub_02039818
_02039858:
	ldr r2, [sp]
	mov r0, r4
	mov r1, #8
	str r4, [r2, #0x20]
	bl _ZN27CFieldScreenEffectActorData4LoadEi
	mov r0, #0x4c
	bl _Znwm
	cmp r0, #0
	beq _02039880
	bl _ZN15CSoftwareSpriteC1Ev
_02039880:
	ldr r1, [sp]
	str r0, [r1, #0x24]
	mov r1, #1
	str r1, [r0, #4]
	ldr r0, [sp]
	ldr r1, [r0, #0x1c]
	ldr r0, [r0, #0x24]
	str r1, [r0, #0x10]
	ldr r0, [sp]
	ldr r0, [r0, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r1, [sp]
	ldr r2, [r1, #0x24]
	mov r1, #0
	str r0, [r2, #0x34]
	ldr r0, [sp]
	ldr r0, [r0, #0x20]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r1, [sp]
	ldr r2, [r1, #0x24]
	mov r1, #0
	str r0, [r2, #0x2c]
	ldr r0, [sp]
	str r1, [r2, #0x30]
	ldr r0, [r0, #0x20]
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [sp]
	ldr r2, [r1, #0x24]
	mov r1, #0
	str r0, [r2, #0x38]
	ldr r0, [sp]
	ldr r0, [r0, #0x20]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	mov r8, #0
	ldr r5, _02039CDC ; =0x55555556
	str r0, [sp, #0xc]
	mov r7, #1
	mov r6, r8
	mov r4, #3
_0203993C:
	ldr r0, [sp, #0xc]
	mov r1, r7
	mov r2, r6
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	smull r1, r2, r5, r8
	add r2, r2, r8, lsr #31
	smull r2, r1, r4, r2
	ldr r1, [sp]
	sub r2, r8, r2
	add r3, r1, r8, lsl #1
	mov r1, r2, lsl #0x10
	strh r0, [r3, #0x28]
	mov r2, r1, lsr #0x10
	ldrh r1, [r3, #0x28]
	ldr r0, [sp, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008990Ett
	add r8, r8, #1
	cmp r8, #8
	blt _0203993C
	ldr r0, [sp]
	mov r2, #0
	str r2, [sp, #8]
	add r0, r0, #0x3c
_02039998:
	mov r1, #0
	ldr r6, _02039CE0 ; =MAIN_BSS_0210CEC8
	ldr ip, _02039CE4 ; =0xFFFFFEB9
	mov r3, r1
	mvn lr, #0
	mov fp, r1
	mov r4, #0xa3
	mov r5, #0xa
_020399B8:
	ldmia r6, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [r6]
	mov r8, r7, lsr #0x10
	mov r7, #0x50
	mul r7, r8, r7
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	add r7, r3, r7, lsr #4
	str r7, [r0]
	ldmia r6, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [r6]
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #6
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	add r7, r2, r7, lsr #4
	str r7, [r0, #4]
	ldmia r6, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [r6]
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #8
	mov r7, r7, lsr #0x10
	strb r7, [r0, #0x18]
	ldmia r6, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [r6]
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #3
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r8, r7, lsr #4
	umull sl, sb, r8, ip
	mla sb, r8, lr, sb
	mov r7, r8, asr #0x1f
	mla sb, r7, ip, sb
	mov r7, sl, lsr #0xc
	orr r7, r7, sb, lsl #20
	sub r7, r7, #0x2000
	str r7, [r0, #0x10]
	str r7, [r0, #8]
	ldmia r6, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [r6]
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #3
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r8, r7, lsr #4
	umull sl, sb, r8, r4
	add r1, r1, #1
	mla sb, r8, fp, sb
	mov r7, r8, asr #0x1f
	mla sb, r7, r4, sb
	mov r7, sl, lsr #0xc
	orr r7, r7, sb, lsl #20
	add r7, r7, #0x66
	add r7, r7, #0x600
	str r7, [r0, #0x14]
	str r7, [r0, #0xc]
	ldmia r6, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [r6]
	mov r7, r7, lsr #0x10
	mul r8, r7, r5
	mov r7, r8, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r7, r7, lsr #0x10
	add r7, r7, #0xa
	strb r7, [r0, #0x19]
	cmp r1, #4
	add r3, r3, #0x50000
	add r0, r0, #0x1c
	blt _020399B8
	ldr r1, [sp, #8]
	add r2, r2, #0x40000
	add r1, r1, #1
	str r1, [sp, #8]
	cmp r1, #4
	blt _02039998
	ldr r0, [sp, #0xc]
	mov r1, #1
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	ldr r1, [sp]
	mov r2, #3
	strh r0, [r1, #0x38]
	mov r0, r1
	ldrh r1, [r0, #0x38]
	ldr r0, [sp, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008990Ett
	ldr r0, [sp]
	mov r1, #0
	str r1, [sp, #4]
	add r3, r0, #0x1fc
_02039B3C:
	mov r0, #0
	ldr r8, _02039CE0 ; =MAIN_BSS_0210CEC8
	ldr r4, _02039CE4 ; =0xFFFFFEB9
	mov r2, r0
	mvn r5, #0
	mov lr, r0
	mov r6, #0xa3
	mov r7, #0xa
_02039B5C:
	ldmia r8, {sb, sl, fp}
	mla sb, sl, sb, fp
	str sb, [r8]
	mov sl, sb, lsr #0x10
	mov sb, #0x50
	mul sb, sl, sb
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #0x10
	add sb, r2, sb, lsr #4
	str sb, [r3]
	ldmia r8, {sb, sl, fp}
	mla sb, sl, sb, fp
	str sb, [r8]
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #6
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #0x10
	add sb, r1, sb, lsr #4
	str sb, [r3, #4]
	ldmia r8, {sb, sl, fp}
	mla sb, sl, sb, fp
	str sb, [r8]
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #8
	mov sb, sb, lsr #0x10
	strb sb, [r3, #0x18]
	ldmia r8, {sb, sl, fp}
	mla sb, sl, sb, fp
	str sb, [r8]
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #3
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #0x10
	mov sl, sb, lsr #4
	umull ip, fp, sl, r4
	mla fp, sl, r5, fp
	mov sb, sl, asr #0x1f
	mla fp, sb, r4, fp
	mov sb, ip, lsr #0xc
	orr sb, sb, fp, lsl #20
	sub sb, sb, #0x2000
	str sb, [r3, #0x10]
	str sb, [r3, #8]
	ldmia r8, {sb, sl, fp}
	mla sb, sl, sb, fp
	str sb, [r8]
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #3
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #0x10
	mov sl, sb, lsr #4
	umull ip, fp, sl, r6
	add r0, r0, #1
	mla fp, sl, lr, fp
	mov sb, sl, asr #0x1f
	mla fp, sb, r6, fp
	mov sb, ip, lsr #0xc
	orr sb, sb, fp, lsl #20
	add sb, sb, #0x66
	add sb, sb, #0x600
	str sb, [r3, #0x14]
	str sb, [r3, #0xc]
	ldmia r8, {sb, sl, fp}
	mla sb, sl, sb, fp
	str sb, [r8]
	mov sb, sb, lsr #0x10
	mul sl, sb, r7
	mov sb, sl, lsr #0x10
	mov sb, sb, lsl #0x10
	mov sb, sb, lsr #0x10
	add sb, sb, #0xa
	strb sb, [r3, #0x19]
	cmp r0, #4
	add r2, r2, #0x50000
	add r3, r3, #0x1c
	blt _02039B5C
	ldr r0, [sp, #4]
	add r1, r1, #0x40000
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #4
	blt _02039B3C
	ldr r0, [sp]
	ldr r1, _02039CE8 ; =s_data_field_effect_kiri02_ntft_0208dac0
	ldr r2, _02039CEC ; =s_data_field_effect_kiri02_ntfp_0208dae0
	add r0, r0, #0x3c0
	mov r3, #2
	bl _ZN10NtfTexture12LoadDeferredEPKcS1_i
	ldr r0, [sp]
	mov r1, #2
	str r1, [r0, #0x3bc]
	mov r0, #1
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02039CD4: .word ptr_FUN_020294c0_0208c4a4
_02039CD8: .word PTR_LAB_0208da9c
_02039CDC: .word 0x55555556
_02039CE0: .word MAIN_BSS_0210CEC8
_02039CE4: .word 0xFFFFFEB9
_02039CE8: .word s_data_field_effect_kiri02_ntft_0208dac0
_02039CEC: .word s_data_field_effect_kiri02_ntfp_0208dae0

	arm_func_start sub_02039CF0
sub_02039CF0: ; 0x02039CF0
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x3c0
	bl _ZN10NtfTexture7ReleaseEv
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _02039D24
	beq _02039D1C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02039CF0
_02039D1C:
	mov r0, #0
	str r0, [r4, #0x24]
_02039D24:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _02039D48
	beq _02039D40
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02039D40:
	mov r0, #0
	str r0, [r4, #0x20]
_02039D48:
	mov r0, #1
	ldmia sp!, {r4, pc}

	arm_func_start sub_02039D50
sub_02039D50: ; 0x02039D50
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02029518
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02039D50

	arm_func_start sub_02039D6C
sub_02039D6C: ; 0x02039D6C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN28CFieldScreenEffectObjectBase5StartEiii
	ldr r2, [r4, #0x418]
	ldr r1, [r4, #0x18]
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [r4, #0x3f0]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02039D6C

	arm_func_start sub_02039D90
sub_02039D90: ; 0x02039D90
	stmdb sp!, {r4, lr}
	ldr r1, _02039DC4 ; =ptr_FUN_02039ddc_0208da78
	mov r4, r0
	str r1, [r4]
	bl sub_02039CF0
	add r0, r4, #0x3dc
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c0
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02039DC4: .word ptr_FUN_02039ddc_0208da78
	arm_func_end sub_02039D90

	arm_func_start sub_02039DC8
sub_02039DC8: ; 0x02039DC8
	ldr r0, [r0, #0x41c]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0xc
	bx lr
	arm_func_end sub_02039DC8

	arm_func_start sub_02039DDC
sub_02039DDC: ; 0x02039DDC
	stmdb sp!, {r4, lr}
	ldr r1, _02039E08 ; =ptr_FUN_02039ddc_0208da78
	mov r4, r0
	str r1, [r4]
	bl sub_02039CF0
	add r0, r4, #0x3dc
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c0
	bl _ZN10NtfTexture7ReleaseEv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02039E08: .word ptr_FUN_02039ddc_0208da78
	arm_func_end sub_02039DDC

	arm_func_start sub_02039E0C
sub_02039E0C: ; 0x02039E0C
    stmdb sp!, {r4, lr}
    mov r4, r0
    bl sub_02029518
    mov r0, r4
    ldmia sp!, {r4, pc}
    arm_func_end sub_02039E0C

	arm_func_start _ZN13CFieldSEFRain12sub_02039E20Ev
_ZN13CFieldSEFRain12sub_02039E20Ev: ; 0x02039E20
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sl, r0
	bl sub_0203A604
	mov r0, #0x34
	bl _Znwm
	movs r4, r0
	beq _02039E60
	ldr r1, _0203A004 ; =ptr_FUN_020294c0_0208c4a4
	add r0, r4, #4
	str r1, [r4]
	bl _ZN17UnkClass_02007AA4C1Ev
	mov r1, #0
	str r1, [r4, #0x2c]
	ldr r0, _0203A008 ; =PTR_LAB_0208da9c
	str r1, [r4, #0x30]
	str r0, [r4]
	arm_func_end _ZN13CFieldSEFRain12sub_02039E20Ev
_02039E60:
	mov r0, r4
	mov r1, #0
	str r4, [sl, #0x660]
	bl _ZN27CFieldScreenEffectActorData4LoadEi
	mov r1, #0
	mov r0, #0x4c
	str r1, [sl, #0x664]
	bl _Znwm
	cmp r0, #0
	beq _02039E8C
	bl _ZN15CSoftwareSpriteC1Ev
_02039E8C:
	str r0, [sl, #0x664]
	mov r1, #1
	str r1, [r0, #4]
	ldr r1, [sl, #0x1c]
	ldr r0, [sl, #0x664]
	str r1, [r0, #0x10]
	ldr r0, [sl, #0x660]
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	blx r1
	ldr r2, [sl, #0x664]
	mov r1, #0
	str r0, [r2, #0x34]
	ldr r0, [sl, #0x660]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r2, [sl, #0x664]
	mov r1, #0
	str r0, [r2, #0x2c]
	str r1, [r2, #0x30]
	ldr r0, [sl, #0x660]
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	ldr r2, [sl, #0x664]
	mov r1, #0
	str r0, [r2, #0x38]
	ldr r0, [sl, #0x660]
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	mov r7, #0
	mov r6, r0
	mov sb, r7
	mov r5, #1
	mov fp, r7
_02039F20:
	mov r0, r6
	mov r1, r5
	mov r2, fp
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, sl, r7, lsl #1
	add r1, r1, #0x600
	strh r0, [r1, #0x68]
	ldrh r1, [r1, #0x68]
	mov r0, r6
	mov r2, #0
	bl _ZN17UnkClass_0200878812sub_02008990Ett
	mov r8, #0
	cmp sb, #0
	ble _02039F78
	add r0, sl, r7, lsl #1
	add r4, r0, #0x600
_02039F60:
	ldrh r1, [r4, #0x68]
	mov r0, r6
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	add r8, r8, #1
	cmp r8, sb
	blt _02039F60
_02039F78:
	add r7, r7, #1
	cmp r7, #8
	add sb, sb, #3
	blt _02039F20
	ldr r4, _0203A00C ; =MAIN_BSS_0210CEC8
	add r0, sl, #0x5a0
	mov r1, #0
	mov r3, #0xc0
_02039F98:
	ldmia r4, {r2, r5, r6}
	mla r6, r5, r2, r6
	mov r2, r6, lsr #0x10
	mov r2, r2, lsl #8
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	str r6, [r4]
	mov r2, r2, lsr #4
	str r2, [r0, #4]
	ldmia r4, {r2, r5, r6}
	mla r6, r5, r2, r6
	mov r2, r6, lsr #0x10
	mul r5, r2, r3
	mov r2, r5, lsr #0x10
	mov r2, r2, lsl #0x10
	add r1, r1, #1
	str r6, [r4]
	mov r2, r2, lsr #4
	str r2, [r0, #8]
	cmp r1, #0x10
	add r0, r0, #0xc
	blt _02039F98
	mov r0, #1
	str r0, [sl, #4]
	mov r1, #0
	str r1, [sl, #8]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203A004: .word ptr_FUN_020294c0_0208c4a4
_0203A008: .word PTR_LAB_0208da9c
_0203A00C: .word MAIN_BSS_0210CEC8

	arm_func_start sub_0203A010
sub_0203A010: ; 0x0203A010
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x664]
	cmp r0, #0
	beq _0203A03C
	beq _0203A034
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_0203A010
_0203A034:
	mov r0, #0
	str r0, [r4, #0x664]
_0203A03C:
	ldr r0, [r4, #0x660]
	cmp r0, #0
	beq _0203A060
	beq _0203A058
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203A058:
	mov r0, #0
	str r0, [r4, #0x660]
_0203A060:
	mov r0, #1
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203A068
sub_0203A068: ; 0x0203A068
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	ldr r2, [r4, #4]
	mov r5, #0
	str r1, [sp]
	mov r6, r5
	mov r0, r5
	cmp r2, #6
	addls pc, pc, r2, lsl #2
	b _0203A168
_0203A090: ; jump table
	b _0203A168 ; case 0
	b _0203A168 ; case 1
	b _0203A0AC ; case 2
	b _0203A0AC ; case 3
	b _0203A100 ; case 4
	b _0203A110 ; case 5
	b _0203A168 ; case 6
	arm_func_end sub_0203A068
_0203A0AC:
	ldr r7, [r4, #0xc]
	cmp r7, #0
	beq _0203A168
	ldr r8, [r4, #8]
	mov r1, r7
	mov r0, r8, lsl #5
	bl _s32_div_f
	add r1, r7, r7, lsr #31
	mov r5, r0
	cmp r8, r1, asr #1
	mov r1, r1, asr #1
	ble _0203A0EC
	sub r0, r8, r1
	mul r0, r5, r0
	bl _s32_div_f
	mov r6, r0
_0203A0EC:
	mov r0, r8, lsl #4
	mul r0, r8, r0
	mul r1, r7, r7
	bl _s32_div_f
	b _0203A168
_0203A100:
	mov r5, #0x20
	mov r6, r5
	mov r0, #0x10
	b _0203A168
_0203A110:
	ldr r7, [r4, #0x14]
	cmp r7, #0
	beq _0203A168
	ldr r8, [r4, #8]
	mov r1, r7
	sub r0, r7, r8
	mov r0, r0, lsl #5
	bl _s32_div_f
	add r1, r7, r7, lsr #31
	mov r5, r0
	cmp r8, r1, asr #1
	mov r1, r1, asr #1
	bge _0203A154
	sub r0, r1, r8
	mul r0, r5, r0
	bl _s32_div_f
	mov r6, r0
_0203A154:
	sub r1, r7, r8
	mov r0, r1, lsl #4
	mul r0, r1, r0
	mul r1, r7, r7
	bl _s32_div_f
_0203A168:
	mov r3, #0
	ldr lr, _0203A3C8 ; =MAIN_BSS_0210CEC8
	mov ip, r4
	mov r2, #2
	mov r1, r3
	mov fp, #0x100000
_0203A180:
	cmp r3, r6
	bgt _0203A218
	str r2, [ip, #0x20]
	ldmia lr, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [lr]
	mov r7, r7, lsr #0x10
	add r7, r7, r7, lsl #2
	mov r7, r7, lsl #6
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov sl, r7, lsr #4
	str sl, [ip, #0x3c]
	str r1, [ip, #0x40]
	ldmia lr, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [lr]
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #4
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r7, r7, lsr #0x10
	add r7, r7, #0x10
	sub r7, sl, r7, lsl #12
	str r7, [ip, #0x44]
	str fp, [ip, #0x48]
	ldmia lr, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [lr]
	mov r8, r7, lsr #0x10
	mov r7, #0x14
	mul r7, r8, r7
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov r7, r7, lsr #0x10
	add r7, r7, #8
	str r7, [ip, #0x38]
	b _0203A294
_0203A218:
	cmp r3, r5
	bgt _0203A28C
	mov r7, #1
	str r7, [ip, #0x20]
	ldr r7, [ip, #0x40]
	ldr r8, [ip, #0x3c]
	add sl, r7, #0x18000
	sub r8, r8, #0x4000
	cmp sl, #0x100000
	bgt _0203A248
	cmp r8, #0
	bge _0203A270
_0203A248:
	ldmia lr, {r7, r8, sb}
	mla r7, r8, r7, sb
	str r7, [lr]
	mov r7, r7, lsr #0x10
	add r7, r7, r7, lsl #2
	mov r7, r7, lsl #6
	mov r7, r7, lsr #0x10
	mov r7, r7, lsl #0x10
	mov sl, #0
	mov r8, r7, lsr #4
_0203A270:
	str r8, [ip, #0x3c]
	sub r7, r8, #0xc000
	str sl, [ip, #0x40]
	str r7, [ip, #0x44]
	add r7, sl, #0x48000
	str r7, [ip, #0x48]
	b _0203A294
_0203A28C:
	mov r7, #0
	str r7, [ip, #0x20]
_0203A294:
	add ip, ip, #0x2c
	add r3, r3, #1
	cmp r3, #0x20
	blt _0203A180
	mov r3, #0
	mov r5, r4
	mov r1, r3
	mov r2, #1
_0203A2B4:
	cmp r3, r0
	strle r2, [r5, #0x5a0]
	strgt r1, [r5, #0x5a0]
	add r3, r3, #1
	cmp r3, #0x10
	add r5, r5, #0xc
	blt _0203A2B4
	ldr r0, [r4, #0x660]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	mov r5, r0
	mov r6, #0
_0203A2EC:
	add r0, r4, r6, lsl #1
	add r0, r0, #0x600
	ldrh r1, [r0, #0x68]
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	add r0, r4, r6, lsl #1
	add r0, r0, #0x600
	ldrh r1, [r0, #0x68]
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_02008860Et
	cmp r0, #0
	bne _0203A3A8
	add r0, r4, r6, lsl #1
	add r0, r0, #0x600
	ldrh r1, [r0, #0x68]
	mov r0, r5
	bl _ZN17UnkClass_0200878812sub_020089B8Et
	mov r0, #0xc
	mla r7, r6, r0, r4
	mov r2, #0
	ldr fp, _0203A3C8 ; =MAIN_BSS_0210CEC8
	mov r3, r2
	mov r8, r0
	mov sl, #0xc0
_0203A34C:
	ldmia fp, {r1, sb, ip}
	mla r1, sb, r1, ip
	mla r0, r3, r8, r7
	mov sb, r1, lsr #0x10
	mov sb, sb, lsl #8
	mov sb, sb, lsr #0x10
	mov sb, sb, lsl #0x10
	str r1, [fp]
	mov r1, sb, lsr #4
	str r1, [r0, #0x5a4]
	ldmia fp, {r1, sb, ip}
	mla ip, sb, r1, ip
	mov r1, ip, lsr #0x10
	mul sb, r1, sl
	mov r1, sb, lsr #0x10
	mov r1, r1, lsl #0x10
	add r2, r2, #1
	str ip, [fp]
	mov r1, r1, lsr #4
	add r3, r3, #8
	str r1, [r0, #0x5a8]
	cmp r2, #2
	blt _0203A34C
_0203A3A8:
	add r6, r6, #1
	cmp r6, #8
	blt _0203A2EC
	ldr r1, [sp]
	mov r0, r4
	bl _ZN28CFieldScreenEffectObjectBase6UpdateEi
	ldr r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203A3C8: .word MAIN_BSS_0210CEC8

	arm_func_start sub_0203A3CC
sub_0203A3CC: ; 0x0203A3CC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xb0
	mov sb, r1
	ldr r5, [sb, #0x1c]
	mov sl, r0
	ldr r4, [sb, #0x20]
	ldr fp, _0203A600 ; =_ZN28CFieldScreenEffectObjectBase8s_scrollE
	mov r7, sl
	str r5, [sp, #0x80]
	str r4, [sp, #0x84]
	add r8, sl, #0x24
	mov r6, #0
	arm_func_end sub_0203A3CC
_0203A3FC:
	ldr r0, [r7, #0x20]
	cmp r0, #0
	beq _0203A528
	ldr lr, [r7, #0x3c]
	ldr r1, [r7, #0x40]
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #0x48]
	ldr ip, [fp]
	ldr r3, [fp, #4]
	str lr, [sp, #0x78]
	str r1, [sp, #0x7c]
	str lr, [sp, #0xa8]
	sub lr, lr, r5
	str r1, [sp, #0xac]
	sub r1, r1, r4
	str r2, [sp, #0x70]
	str r0, [sp, #0x74]
	str r2, [sp, #0xa0]
	sub r2, r2, r5
	str r0, [sp, #0xa4]
	sub r0, r0, r4
	str r5, [sp, #0x68]
	str r4, [sp, #0x6c]
	str lr, [sp, #0x60]
	add lr, lr, ip
	sub lr, lr, #0xa0000
	str r1, [sp, #0x64]
	add r1, r1, r3
	str r5, [sp, #0x58]
	str r4, [sp, #0x5c]
	str r2, [sp, #0x50]
	add r2, r2, ip
	str r0, [sp, #0x54]
	add r0, r0, r3
	str ip, [sp]
	str r3, [sp, #4]
	str ip, [sp, #0x48]
	str ip, [sp, #0x40]
	str r3, [sp, #0x4c]
	str r1, [sp, #0x9c]
	str r3, [sp, #0x44]
	str r2, [sp, #0x90]
	str r0, [sp, #0x94]
	str lr, [sp, #0x98]
	sub r1, r1, #0x80000
	sub ip, r2, #0xa0000
	sub r3, r0, #0x80000
	str lr, [r7, #0x3c]
	str r1, [r7, #0x40]
	str ip, [r7, #0x44]
	mov r0, r8
	str r3, [r7, #0x48]
	ldr r2, [r0]
	str lr, [sp, #0x38]
	ldr r2, [r2, #8]
	str r1, [sp, #0x9c]
	str r1, [sp, #0x3c]
	mov r1, sb
	str ip, [sp, #0x90]
	str ip, [sp, #0x30]
	str r3, [sp, #0x94]
	str r3, [sp, #0x34]
	blx r2
	ldr r3, [sp, #0x78]
	ldr r2, [sp, #0x7c]
	str r3, [r7, #0x3c]
	ldr r1, [sp, #0x70]
	str r2, [r7, #0x40]
	ldr r0, [sp, #0x74]
	str r1, [r7, #0x44]
	str r3, [sp, #0x28]
	str r2, [sp, #0x2c]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [r7, #0x48]
_0203A528:
	add r6, r6, #1
	cmp r6, #0x20
	add r7, r7, #0x2c
	add r8, r8, #0x2c
	blt _0203A3FC
	ldr r0, [sl, #0x660]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r5, [sp, #0x80]
	ldr r4, [sp, #0x84]
	mov r6, r0
	mov r8, sl
	mov r7, #0
_0203A564:
	ldr r0, [r8, #0x5a0]
	cmp r0, #0
	beq _0203A5E8
	mov r0, r7, lsl #0x1d
	add r0, sl, r0, lsr #28
	add r0, r0, #0x600
	ldrh r1, [r0, #0x68]
	mov r0, r6
	bl _ZN17UnkClass_0200878812sub_02008828Et
	ldr r2, [sl, #0x664]
	mov r1, sb
	strh r0, [r2, #0x2a]
	ldr r2, [r8, #0x5a4]
	ldr r0, [r8, #0x5a8]
	sub ip, r2, r5
	sub r2, r0, r4
	sub fp, ip, #0x80000
	sub r3, r2, #0x60000
	str ip, [sp, #0x10]
	ldr r0, [sl, #0x664]
	str r2, [sp, #0x14]
	str fp, [r0, #0x18]
	str r3, [r0, #0x1c]
	ldr r0, [sl, #0x664]
	str r5, [sp, #0x18]
	ldr r2, [r0]
	str r4, [sp, #0x1c]
	str fp, [sp, #0x88]
	str fp, [sp, #8]
	ldr r2, [r2, #8]
	str r3, [sp, #0x8c]
	str r3, [sp, #0xc]
	blx r2
_0203A5E8:
	add r7, r7, #1
	cmp r7, #0x10
	add r8, r8, #0xc
	blt _0203A564
	add sp, sp, #0xb0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203A600: .word _ZN28CFieldScreenEffectObjectBase8s_scrollE

	arm_func_start sub_0203A604
sub_0203A604: ; 0x0203A604
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x18
	mov r3, #0
	mov lr, r3
	add r2, r0, #0x20
	arm_func_end sub_0203A604
_0203A618:
	mov ip, #0
	ldr r5, _0203A6C8 ; =MAIN_BSS_0210CEC8
	mov r7, #0xc
	mov r6, ip
	mov r4, #0x28
_0203A62C:
	ldr r8, [r5, #8]
	ldmia r5, {r1, sl}
	mla r1, sl, r1, r8
	mla r8, sl, r1, r8
	mov sb, r1, lsr #0x10
	mul sl, sb, r4
	mov sb, r8, lsr #0x10
	mov r1, sl, lsr #0x10
	mov sb, sb, lsl #8
	mov r1, r1, lsl #0x10
	add r1, lr, r1, lsr #4
	str r8, [r5]
	mov sb, sb, lsr #0x10
	mov r8, sb, lsl #0x10
	mov sl, r8, lsr #4
	add sb, sl, #0x20000
	str r1, [r2, #0x1c]
	str sl, [r2, #0x20]
	str r1, [r2, #0x24]
	str sb, [r2, #0x28]
	str r7, [r2, #0x18]
	ldr r8, [r0, #0x1c]
	add ip, ip, #1
	str r8, [r2, #0x14]
	str r1, [sp, #0x10]
	str r1, [sp, #8]
	str sl, [sp, #0xc]
	str sb, [sp, #0x14]
	str r1, [sp]
	str sb, [sp, #4]
	cmp ip, #4
	str r6, [r2], #0x2c
	blt _0203A62C
	add r3, r3, #1
	cmp r3, #8
	add lr, lr, #0x28000
	blt _0203A618
	add sp, sp, #0x18
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_0203A6C8: .word MAIN_BSS_0210CEC8

	arm_func_start sub_0203A6CC
sub_0203A6CC: ; 0x0203A6CC
	stmdb sp!, {r4, lr}
	ldr r1, _0203A704 ; =ptr_FUN_0203a734_0208db24
	mov r4, r0
	str r1, [r4]
	bl sub_0203A010
	ldr r3, _0203A708 ; =_ZN17CFieldSEFRainDropD1Ev
	add r0, r4, #0x20
	mov r1, #0x20
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203A704: .word ptr_FUN_0203a734_0208db24
_0203A708: .word _ZN17CFieldSEFRainDropD1Ev
	arm_func_end sub_0203A6CC

	arm_func_start sub_0203A70C
sub_0203A70C: ; 0x0203A70C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	bl _ZN28CFieldScreenEffectObjectBase5StartEiii
	mov r4, r0
	mov r0, r5
	bl sub_0203A604
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_0203A70C

	arm_func_start sub_0203A72C
sub_0203A72C: ; 0x0203A72C
	mov r0, #2
	bx lr
	arm_func_end sub_0203A72C

	arm_func_start sub_0203A734
sub_0203A734: ; 0x0203A734
	stmdb sp!, {r4, lr}
	ldr r1, _0203A764 ; =ptr_FUN_0203a734_0208db24
	mov r4, r0
	str r1, [r4]
	bl sub_0203A010
	ldr r3, _0203A768 ; =_ZN17CFieldSEFRainDropD1Ev
	add r0, r4, #0x20
	mov r1, #0x20
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203A764: .word ptr_FUN_0203a734_0208db24
_0203A768: .word _ZN17CFieldSEFRainDropD1Ev
	arm_func_end sub_0203A734

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
	ldr r0, _0203B234 ; =PTR_LAB_0208da9c
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
_0203B234: .word PTR_LAB_0208da9c
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
