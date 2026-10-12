    .include "macros.inc"
    .include "include/arm9_020293A0.inc"

    .text

	arm_func_start sub_020293A0
sub_020293A0: ; 0x020293A0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	bl sub_02029484
	ldr r4, [r5]
	cmp r4, #0
	beq _020293D4
	beq _020293CC
	mov r0, r4
	bl _ZN17UnkClass_020074D4D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_020293A0
_020293CC:
	mov r0, #0
	str r0, [r5]
_020293D4:
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _020293F8
	beq _020293F0
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020293F0:
	mov r0, #0
	str r0, [r5, #4]
_020293F8:
	ldr r4, [r5, #8]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _02029418
	mov r0, r4
	bl _ZN17UnkClass_02008788D1Ev
	mov r0, r4
	bl _ZdlPv
_02029418:
	mov r0, #0
	str r0, [r5, #8]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02029424
sub_02029424: ; 0x02029424
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0xc]
	mov r4, r1
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	ldr r0, [r5]
	mov r1, #0
	ldr r0, [r0, #0x38]
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	str r0, [r5, #0xc]
	cmp r4, #0
	ldr r1, [r5, #0xc]
	ldr r0, [r5]
	beq _02029474
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_020074D412sub_020076E8Em
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_02029424
_02029474:
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_020074D412sub_02007714Em
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02029484
sub_02029484: ; 0x02029484
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4, #0xc]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02029484

	arm_func_start sub_020294A8
sub_020294A8: ; 0x020294A8
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN17UnkClass_020074D412sub_020076B0Ev
	ldmia sp!, {r3, pc}
	arm_func_end sub_020294A8

	arm_func_start _ZN16CEffectActorDataD1Ev
_ZN16CEffectActorDataD1Ev: ; 0x020294C0
	stmdb sp!, {r4, lr}
	ldr r1, _020294E4 ; =ptr_FUN_020294c0_0208c4a4
	mov r4, r0
	str r1, [r4]
	bl sub_02029540
	add r0, r4, #4
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_020294E4: .word ptr_FUN_020294c0_0208c4a4
	arm_func_end _ZN16CEffectActorDataD1Ev

	arm_func_start _ZN16CEffectActorDataD0Ev
_ZN16CEffectActorDataD0Ev: ; 0x020294E8
	stmdb sp!, {r4, lr}
	ldr r1, _02029514 ; =ptr_FUN_020294c0_0208c4a4
	mov r4, r0
	str r1, [r4]
	bl sub_02029540
	add r0, r4, #4
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02029514: .word ptr_FUN_020294c0_0208c4a4
	arm_func_end _ZN16CEffectActorDataD0Ev

	arm_func_start _ZN16CEffectActorDataD2Ev
_ZN16CEffectActorDataD2Ev: ; 0x02029518
	stmdb sp!, {r4, lr}
	ldr r1, _0202953C ; =ptr_FUN_020294c0_0208c4a4
	mov r4, r0
	str r1, [r4]
	bl sub_02029540
	add r0, r4, #4
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202953C: .word ptr_FUN_020294c0_0208c4a4
	arm_func_end _ZN16CEffectActorDataD2Ev

	arm_func_start sub_02029540
sub_02029540: ; 0x02029540
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r4, [r6, #0x2c]
	cmp r4, #0
	beq _02029594
	ldr r0, [r6, #0x30]
	cmp r0, #0
	sub r5, r0, #1
	beq _0202957C
	arm_func_end sub_02029540
_02029564:
	mov r0, r4
	bl sub_020293A0
	cmp r5, #0
	add r4, r4, #0x10
	sub r5, r5, #1
	bne _02029564
_0202957C:
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	beq _02029594
	bl _ZdaPv
	mov r0, #0
	str r0, [r6, #0x2c]
_02029594:
	add r0, r6, #4
	bl _ZN17UnkClass_02007AA412sub_02007BC4Ev
	mov r0, r6
	bl sub_02029648
	mov r0, #0
	str r0, [r6, #0x30]
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN16CEffectActorData12sub_020295B0Ei
_ZN16CEffectActorData12sub_020295B0Ei: ; 0x020295B0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r0
	ldr r0, [r5, #0x28]
	mov r4, r1
	cmp r0, #0
	bne _0202960C
	ldr r0, [r5, #8]
	mov r1, #0
	ldr r0, [r0, #8]
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r5, #0x28]
	cmp r4, #0
	ldr r1, [r5, #0x28]
	add r0, r5, #4
	beq _02029600
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007BFCEm
	b _0202960C
	arm_func_end _ZN16CEffectActorData12sub_020295B0Ei
_02029600:
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007C34Em
_0202960C:
	ldr r0, [r5, #0x30]
	mov r6, #0
	cmp r0, #0
	ldmlsia sp!, {r3, r4, r5, r6, r7, pc}
	mov r7, r6
_02029620:
	ldr r0, [r5, #0x2c]
	mov r1, r4
	add r0, r0, r7
	bl sub_02029424
	ldr r0, [r5, #0x30]
	add r6, r6, #1
	cmp r6, r0
	add r7, r7, #0x10
	blo _02029620
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02029648
sub_02029648: ; 0x02029648
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _02029690
	ldr r0, [r4, #0x30]
	mov r5, #0
	cmp r0, #0
	bls _02029690
	mov r6, r5
	arm_func_end sub_02029648
_02029670:
	ldr r0, [r4, #0x2c]
	add r0, r0, r6
	bl sub_02029484
	ldr r0, [r4, #0x30]
	add r5, r5, #1
	cmp r5, r0
	add r6, r6, #0x10
	blo _02029670
_02029690:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #0x28]
	strb r0, [r4, #0x24]
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_020296B0
sub_020296B0: ; 0x020296B0
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	add r0, r6, #4
	bl _ZN17UnkClass_02007AA412sub_02007BC4Ev
	ldr r0, [r6, #0x2c]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r6, #0x30]
	mov r4, #0
	cmp r0, #0
	ldmlsia sp!, {r4, r5, r6, pc}
	mov r5, r4
	arm_func_end sub_020296B0
_020296E0:
	ldr r0, [r6, #0x2c]
	add r0, r0, r5
	bl sub_020294A8
	ldr r0, [r6, #0x30]
	add r4, r4, #1
	cmp r4, r0
	add r5, r5, #0x10
	blo _020296E0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN16CEffectActorData8IsLoadedEv
_ZN16CEffectActorData8IsLoadedEv: ; 0x02029704
	ldrb r1, [r0, #0x24]
	cmp r1, #0
	beq _02029764
	ldr r1, [r0, #0x30]
	cmp r1, #0
	beq _0202975C
	cmp r1, #0
	mov r2, #1
	mov r3, #0
	bls _02029768
	ldr ip, [r0, #0x2c]
	arm_func_end _ZN16CEffectActorData8IsLoadedEv
_02029730:
	ldr r1, [ip, r3, lsl #4]
	cmp r1, #0
	ldrneb r1, [r1, #0x30]
	cmpne r1, #0
	moveq r2, #0
	beq _02029768
	ldr r1, [r0, #0x30]
	add r3, r3, #1
	cmp r3, r1
	blo _02029730
	b _02029768
_0202975C:
	mov r2, #0
	b _02029768
_02029764:
	mov r2, #0
_02029768:
	mov r0, r2
	bx lr

	arm_func_start _ZN16CEffectActorData8GetCountEv
_ZN16CEffectActorData8GetCountEv: ; 0x02029770
	ldr r0, [r0, #0x30]
	bx lr
	arm_func_end _ZN16CEffectActorData8GetCountEv

	arm_func_start _ZN16CEffectActorData6UpdateEv
_ZN16CEffectActorData6UpdateEv: ; 0x02029778
	bx lr
	arm_func_end _ZN16CEffectActorData6UpdateEv

	arm_func_start _ZN16CEffectActorData10GetPaletteEv
_ZN16CEffectActorData10GetPaletteEv: ; 0x0202977C
	add r0, r0, #4
	bx lr
	arm_func_end _ZN16CEffectActorData10GetPaletteEv

	arm_func_start _ZN16CEffectActorData6GetCacEi
_ZN16CEffectActorData6GetCacEi: ; 0x02029784
	cmp r1, #0
	blt _020297A8
	ldr r2, [r0, #0x30]
	cmp r1, r2
	bhs _020297A8
	ldr r0, [r0, #0x2c]
	add r0, r0, r1, lsl #4
	ldr r0, [r0, #8]
	bx lr
	arm_func_end _ZN16CEffectActorData6GetCacEi
_020297A8:
	mov r0, #0
	bx lr

	arm_func_start _ZN16CEffectActorData7GetNcerEi
_ZN16CEffectActorData7GetNcerEi: ; 0x020297B0
	cmp r1, #0
	blt _020297D4
	ldr r2, [r0, #0x30]
	cmp r1, r2
	bhs _020297D4
	ldr r0, [r0, #0x2c]
	add r0, r0, r1, lsl #4
	ldr r0, [r0, #4]
	bx lr
	arm_func_end _ZN16CEffectActorData7GetNcerEi
_020297D4:
	mov r0, #0
	bx lr

	arm_func_start _ZN16CEffectActorData7GetNcbrEi
_ZN16CEffectActorData7GetNcbrEi: ; 0x020297DC
	cmp r1, #0
	blt _020297F8
	ldr r2, [r0, #0x30]
	cmp r1, r2
	ldrlo r0, [r0, #0x2c]
	ldrlo r0, [r0, r1, lsl #4]
	bxlo lr
	arm_func_end _ZN16CEffectActorData7GetNcbrEi
_020297F8:
	mov r0, #0
	bx lr

	arm_func_start _ZN17UnkClass_02029800C1Ev
_ZN17UnkClass_02029800C1Ev: ; 0x02029800
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0x20]
	bx lr
	arm_func_end _ZN17UnkClass_02029800C1Ev

	arm_func_start _ZN17UnkClass_02029800D1Ev
_ZN17UnkClass_02029800D1Ev: ; 0x02029818
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202A1B4
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_02029800D1Ev

	arm_func_start sub_0202982C
sub_0202982C: ; 0x0202982C
	stmdb sp!, {r3, lr}
	str r1, [r0, #0x24]
	mov r3, #0x4000000
	ldr r2, [r3]
	ldr r1, [r3]
	and r2, r2, #0x1f00
	mov ip, r2, lsr #8
	bic r2, r1, #0x1f00
	orr r1, ip, #0x10
	orr r1, r2, r1, lsl #8
	str r1, [r3]
	ldr r1, [r0, #0x24]
	cmp r1, #0x64
	bge _0202986C
	bl sub_02029A34
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202982C
_0202986C:
	cmp r1, #0xc8
	bge _0202987C
	bl sub_02029B70
	ldmia sp!, {r3, pc}
_0202987C:
	bl sub_02029884
	ldmia sp!, {r3, pc}

	arm_func_start sub_02029884
sub_02029884: ; 0x02029884
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r4, #0
	bl _ZN5CGame11GetInstanceEv
	mov r5, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _020298C8
	mov r1, #0x40
	str r1, [sp]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r5, #0x224
	mov r3, r4
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end sub_02029884
_020298C8:
	str r0, [r6]
	mov r0, #4
	str r0, [sp]
	ldr r0, [r6]
	ldr r1, _02029A24 ; =s_data_menu_0208c4c8
	ldr r2, _02029A28 ; =s_title100_01_0208c4d4
	mov r3, #0
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0
	str r1, [sp]
	add r4, r4, r0
	ldr r0, [r6]
	sub r2, r1, #0x40
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r1, #0
	mov r2, #1
	str r0, [r6, #0xc]
	bl _ZN17UnkClass_0200E96012sub_0200EB34Eii
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02029940
	mov r1, #0x40
	str r1, [sp]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r5, #0x2a4
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02029940:
	str r0, [r6, #4]
	mov r0, #5
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [r6, #4]
	ldr r1, _02029A24 ; =s_data_menu_0208c4c8
	ldr r2, _02029A2C ; =s_title100_00_0208c4e0
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0
	str r1, [sp]
	add r4, r4, r0
	ldr r0, [r6, #4]
	mov r2, #0x80
	mov r3, #0x30
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r6, #0x10]
	ldr r1, [r6, #4]
	mov r0, #0x44
	ldr r1, [r1, #0x24]
	str r1, [r6, #0x28]
	bl _Znwm
	cmp r0, #0
	beq _020299C0
	mov r1, #0x40
	str r1, [sp]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r5, #0x324
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_020299C0:
	str r0, [r6, #8]
	mov r0, #0xd
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [r6, #8]
	ldr r1, _02029A24 ; =s_data_menu_0208c4c8
	ldr r2, _02029A30 ; =s_title100_02_0208c4ec
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0
	str r1, [sp]
	ldr r0, [r6, #8]
	mov r2, #0x180
	mov r3, #0x30
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r6, #0x14]
	mov r0, #1
	str r0, [r6, #0x20]
	mov r0, #0x46
	str r0, [r6, #0x18]
	mov r0, #0
	str r0, [r6, #0x1c]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02029A24: .word s_data_menu_0208c4c8
_02029A28: .word s_title100_01_0208c4d4
_02029A2C: .word s_title100_00_0208c4e0
_02029A30: .word s_title100_02_0208c4ec

	arm_func_start sub_02029A34
sub_02029A34: ; 0x02029A34
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0x14
	mov r6, r0
	mov r4, #0
	bl _ZN5CGame11GetInstanceEv
	mov r5, r0
	ldr r2, [r6, #0x24]
	ldr r1, _02029B64 ; =s_mit_03d_0208c4f8
	add r0, sp, #4
	bl OS_SPrintf
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02029A88
	mov r1, #0x40
	str r1, [sp]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r5, #0x224
	mov r3, r4
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end sub_02029A34
_02029A88:
	str r0, [r6]
	mov r0, #4
	str r0, [sp]
	ldr r0, [r6]
	ldr r1, _02029B68 ; =s_data_menu_0208c4c8
	add r2, sp, #4
	mov r3, #0
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0
	str r1, [sp]
	add r4, r4, r0
	ldr r0, [r6]
	mov r2, #0x80
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r6, #0xc]
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02029AF4
	mov r1, #0x40
	str r1, [sp]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r5, #0x244
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02029AF4:
	str r0, [r6, #4]
	mov r0, #5
	str r0, [sp]
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [r6, #4]
	ldr r1, _02029B68 ; =s_data_menu_0208c4c8
	ldr r2, _02029B6C ; =s_mit104_0208c500
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0
	str r1, [sp]
	ldr r0, [r6, #4]
	mov r2, #0x80
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r6, #0x10]
	ldr r0, [r6, #4]
	mov r1, #1
	ldr r2, [r0, #0x24]
	mov r0, #0
	str r2, [r6, #0x28]
	str r1, [r6, #0x20]
	str r0, [r6, #0x18]
	mov r0, #0xf0
	str r0, [r6, #0x1c]
	add sp, sp, #0x14
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02029B64: .word s_mit_03d_0208c4f8
_02029B68: .word s_data_menu_0208c4c8
_02029B6C: .word s_mit104_0208c500

	arm_func_start sub_02029B70
sub_02029B70: ; 0x02029B70
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r6, r0
	mov r4, #0
	bl _ZN5CGame11GetInstanceEv
	mov r5, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02029BB4
	mov r1, #0x40
	str r1, [sp]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r5, #0x224
	mov r3, r4
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end sub_02029B70
_02029BB4:
	str r0, [r6]
	ldr r0, [r6, #0x24]
	cmp r0, #0x64
	beq _02029BD8
	cmp r0, #0x65
	beq _02029C04
	cmp r0, #0x66
	beq _02029C30
	b _02029C58
_02029BD8:
	mov r0, #4
	str r0, [sp]
	ldr r0, [r6]
	ldr r1, _02029D34 ; =s_data_menu_0208c4c8
	ldr r2, _02029D38 ; =s_title101_00_0208c508
	mov r3, #0
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0xf0
	str r1, [r6, #0x1c]
	add r4, r4, r0
	b _02029C58
_02029C04:
	mov r0, #4
	str r0, [sp]
	ldr r0, [r6]
	ldr r1, _02029D34 ; =s_data_menu_0208c4c8
	ldr r2, _02029D3C ; =s_title101_02_0208c514
	mov r3, #0
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0xf0
	str r1, [r6, #0x1c]
	add r4, r4, r0
	b _02029C58
_02029C30:
	mov r0, #4
	str r0, [sp]
	ldr r0, [r6]
	ldr r1, _02029D34 ; =s_data_menu_0208c4c8
	ldr r2, _02029D40 ; =s_title101_03_0208c520
	mov r3, #0
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, #0x1a4
	str r1, [r6, #0x1c]
	add r4, r4, r0
_02029C58:
	mov r1, #0
	str r1, [sp]
	mov r2, #0x80
	ldr r0, [r6]
	sub r3, r2, #0xb0
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r6, #0xc]
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02029CA0
	mov r1, #0x40
	str r1, [sp]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r5, #0x244
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02029CA0:
	str r0, [r6, #4]
	ldr r0, [r6, #0x24]
	cmp r0, #0x66
	mov r0, #0xc
	str r0, [sp]
	bne _02029CD8
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [r6, #4]
	ldr r1, _02029D34 ; =s_data_menu_0208c4c8
	ldr r2, _02029D44 ; =s_title101_04_0208c52c
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	b _02029CF4
_02029CD8:
	mov r0, r4, asr #4
	add r3, r4, r0, lsr #27
	ldr r0, [r6, #4]
	ldr r1, _02029D34 ; =s_data_menu_0208c4c8
	ldr r2, _02029D48 ; =s_title101_01_0208c538
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
_02029CF4:
	mov r1, #0
	str r1, [sp]
	mov r2, #0x80
	ldr r0, [r6, #4]
	sub r3, r2, #0xb0
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r6, #0x10]
	ldr r0, [r6, #4]
	mov r1, #1
	ldr r2, [r0, #0x24]
	mov r0, #0
	str r2, [r6, #0x28]
	str r1, [r6, #0x20]
	str r0, [r6, #0x18]
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02029D34: .word s_data_menu_0208c4c8
_02029D38: .word s_title101_00_0208c508
_02029D3C: .word s_title101_02_0208c514
_02029D40: .word s_title101_03_0208c520
_02029D44: .word s_title101_04_0208c52c
_02029D48: .word s_title101_01_0208c538

	arm_func_start sub_02029D4C
sub_02029D4C: ; 0x02029D4C
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #0x24]
	cmp r1, #0x64
	bge _02029D64
	bl sub_02029F34
	ldmia sp!, {r3, pc}
	arm_func_end sub_02029D4C
_02029D64:
	cmp r1, #0xc8
	bge _02029D74
	bl sub_02029F74
	ldmia sp!, {r3, pc}
_02029D74:
	bl sub_02029D7C
	ldmia sp!, {r3, pc}

	arm_func_start sub_02029D7C
sub_02029D7C: ; 0x02029D7C
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	bl _ZN5CGame11GetInstanceEv
	ldr r1, [r6, #0x20]
	mov r4, r0
	cmp r1, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r6, #0xc]
	cmp r1, #4
	ldrsh r5, [r0, #0xc]
	addls pc, pc, r1, lsl #2
	b _02029E2C
_02029DAC: ; jump table
	b _02029E2C ; case 0
	b _02029DC0 ; case 1
	b _02029DF0 ; case 2
	b _02029E08 ; case 3
	b _02029E1C ; case 4
	arm_func_end sub_02029D7C
_02029DC0:
	add r5, r5, #0x20
	cmp r5, #0x140
	bne _02029E2C
	mov r0, #2
	str r0, [r6, #0x20]
	mov r0, #0xa
	str r0, [r6, #0x1c]
	ldr r0, [r6, #0xc]
	mov r1, r5
	mov r2, #0x10
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	b _02029E2C
_02029DF0:
	ldr r0, [r6, #0x1c]
	subs r0, r0, #1
	str r0, [r6, #0x1c]
	moveq r0, #3
	streq r0, [r6, #0x20]
	b _02029E2C
_02029E08:
	sub r5, r5, #0x10
	cmp r5, #0xd0
	moveq r0, #4
	streq r0, [r6, #0x20]
	b _02029E2C
_02029E1C:
	sub r5, r5, #0x10
	cmp r5, #0x10
	moveq r0, #5
	streq r0, [r6, #0x20]
_02029E2C:
	ldr r0, [r6, #0xc]
	mov r1, r5
	ldrsh r2, [r0, #0xe]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r1, [r6, #0x14]
	ldr r0, [r6, #0x20]
	ldrsh r5, [r1, #0xc]
	cmp r0, #4
	cmpne r0, #5
	beq _02029E60
	cmp r0, #6
	beq _02029E80
	b _02029EBC
_02029E60:
	cmp r5, #0x80
	subgt r5, r5, #0x10
	bgt _02029EBC
	mov r0, #6
	str r0, [r6, #0x20]
	mov r0, #0xf
	str r0, [r6, #0x1c]
	b _02029EBC
_02029E80:
	ldr r0, [r6, #0x1c]
	subs r0, r0, #1
	str r0, [r6, #0x1c]
	bne _02029EBC
	mov r0, #7
	str r0, [r6, #0x20]
	add r0, r4, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0x2f
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	add r0, r4, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0x15
	mov r2, #0
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
_02029EBC:
	ldr r0, [r6, #0x14]
	mov r1, r5
	ldrsh r2, [r0, #0xe]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [r6, #0x20]
	cmp r0, #7
	bne _02029F00
	ldr r2, [r6, #4]
	ldr r0, [r6, #0x28]
	ldr r1, [r2, #8]
	mov r0, r0, lsl #1
	ldrh r1, [r1, r0]
	ldr r0, [r2, #0x38]
	bl _ZN17UnkClass_0200878812sub_02008860Et
	cmp r0, #0
	moveq r0, #8
	streq r0, [r6, #0x20]
_02029F00:
	ldr r0, [r6, #0x18]
	add r0, r0, #1
	str r0, [r6, #0x18]
	ldr r0, [r6]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldr r0, [r6, #0x20]
	cmp r0, #7
	blt _02029F28
	ldr r0, [r6, #4]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
_02029F28:
	ldr r0, [r6, #8]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_02029F34
sub_02029F34: ; 0x02029F34
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	subne r0, r0, #1
	strne r0, [r4, #0x1c]
	moveq r0, #2
	streq r0, [r4, #0x20]
	ldr r0, [r4]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldr r0, [r4, #4]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r4, pc}
	arm_func_end sub_02029F34

	arm_func_start sub_02029F74
sub_02029F74: ; 0x02029F74
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r1, [r5, #0x20]
	cmp r1, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r0, [r5, #0xc]
	cmp r1, #8
	ldrsh r4, [r0, #0xe]
	addls pc, pc, r1, lsl #2
	b _0202A04C
_02029F9C: ; jump table
	b _0202A04C ; case 0
	b _02029FC0 ; case 1
	b _02029FD4 ; case 2
	b _02029FE8 ; case 3
	b _02029FFC ; case 4
	b _0202A010 ; case 5
	b _0202A024 ; case 6
	b _0202A038 ; case 7
	b _0202A04C ; case 8
	arm_func_end sub_02029F74
_02029FC0:
	add r4, r4, #8
	cmp r4, #0x30
	moveq r0, #2
	streq r0, [r5, #0x20]
	b _0202A04C
_02029FD4:
	add r4, r4, #4
	cmp r4, #0x38
	moveq r0, #3
	streq r0, [r5, #0x20]
	b _0202A04C
_02029FE8:
	sub r4, r4, #2
	cmp r4, #0x30
	moveq r0, #4
	streq r0, [r5, #0x20]
	b _0202A04C
_02029FFC:
	ldr r0, [r5, #0x1c]
	cmp r0, #0x10
	moveq r0, #5
	streq r0, [r5, #0x20]
	b _0202A04C
_0202A010:
	add r4, r4, #1
	cmp r4, #0x38
	moveq r0, #6
	streq r0, [r5, #0x20]
	b _0202A04C
_0202A024:
	sub r4, r4, #4
	cmp r4, #0x30
	moveq r0, #7
	streq r0, [r5, #0x20]
	b _0202A04C
_0202A038:
	sub r4, r4, #8
	mvn r0, #0x2f
	cmp r4, r0
	moveq r0, #8
	streq r0, [r5, #0x20]
_0202A04C:
	ldr r0, [r5, #0xc]
	mov r2, r4
	ldrsh r1, [r0, #0xc]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [r5, #0x10]
	mov r2, r4
	ldrsh r1, [r0, #0xc]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [r5, #0x1c]
	cmp r0, #0
	subne r0, r0, #1
	strne r0, [r5, #0x1c]
	moveq r0, #9
	streq r0, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #0xbe
	bge _0202A098
	ldr r0, [r5]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
_0202A098:
	ldr r0, [r5, #4]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202A0A4
sub_0202A0A4: ; 0x0202A0A4
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #0x24]
	cmp r1, #0x64
	bge _0202A0BC
	bl sub_0202A150
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202A0A4
_0202A0BC:
	cmp r1, #0xc8
	bge _0202A0CC
	bl sub_0202A184
	ldmia sp!, {r3, pc}
_0202A0CC:
	bl sub_0202A0D4
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202A0D4
sub_0202A0D4: ; 0x0202A0D4
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #3
	movlt r6, #2
	movge r6, #1
	bl _ZN5CGame11GetInstanceEv
	mov r5, r0
	mov r1, r6
	mov r0, #0x1000
	bl _s32_div_f
	mov r0, r0, lsl #0xc
	mov r1, r0, asr #0x10
	strh r1, [r5, #0x2a]
	mov r0, #0
	strh r0, [r5, #0x32]
	strh r0, [r5, #0x3a]
	strh r1, [r5, #0x42]
	ldr r0, [r4, #0x20]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r4]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x20]
	cmp r0, #7
	blt _0202A144
	ldr r0, [r4, #4]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	arm_func_end sub_0202A0D4
_0202A144:
	ldr r0, [r4, #8]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_0202A150
sub_0202A150: ; 0x0202A150
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x1c]
	cmp r0, #0x8c
	bge _0202A178
	ldr r0, [r4]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	arm_func_end sub_0202A150
_0202A178:
	ldr r0, [r4, #4]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202A184
sub_0202A184: ; 0x0202A184
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #4]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202A184

	arm_func_start sub_0202A1AC
sub_0202A1AC: ; 0x0202A1AC
	ldr r0, [r0, #0x20]
	bx lr
	arm_func_end sub_0202A1AC

	arm_func_start sub_0202A1B4
sub_0202A1B4: ; 0x0202A1B4
	stmdb sp!, {r3, r4, r5, lr}
	mov r3, #0x4000000
	ldr r2, [r3]
	ldr r1, [r3]
	and r2, r2, #0x1f00
	mov r4, r2, lsr #8
	bic r2, r1, #0x1f00
	eor r1, r4, #0x10
	orr r1, r2, r1, lsl #8
	mov r4, r0
	str r1, [r3]
	ldr r0, [r4]
	cmp r0, #0
	beq _0202A1F8
	bl _ZN17UnkClass_0200ECD012sub_0200F6C4Ev
	ldr r0, [r4]
	bl _ZN17UnkClass_0200ECD012sub_0200F4A8Ev
	arm_func_end sub_0202A1B4
_0202A1F8:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0202A210
	bl _ZN17UnkClass_0200ECD012sub_0200F6C4Ev
	ldr r0, [r4, #4]
	bl _ZN17UnkClass_0200ECD012sub_0200F4A8Ev
_0202A210:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0202A228
	bl _ZN17UnkClass_0200ECD012sub_0200F6C4Ev
	ldr r0, [r4, #8]
	bl _ZN17UnkClass_0200ECD012sub_0200F4A8Ev
_0202A228:
	ldr r5, [r4]
	cmp r5, #0
	beq _0202A250
	beq _0202A248
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_0202A248:
	mov r0, #0
	str r0, [r4]
_0202A250:
	ldr r5, [r4, #4]
	cmp r5, #0
	beq _0202A278
	beq _0202A270
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_0202A270:
	mov r0, #0
	str r0, [r4, #4]
_0202A278:
	ldr r5, [r4, #8]
	cmp r5, #0
	beq _0202A2A0
	beq _0202A298
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_0202A298:
	mov r0, #0
	str r0, [r4, #8]
_0202A2A0:
	mov r0, #0
	str r0, [r4, #0x20]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202A2AC
sub_0202A2AC: ; 0x0202A2AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	str r0, [r4]
	mov r1, #0
	str r1, [r4, #4]
	str r1, [r4, #8]
	str r1, [r4, #0xc]
	str r1, [r4, #0x10]
	str r1, [r4, #0x14]
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	str r1, [r4, #0x20]
	mov r0, r4
	str r1, [r4, #0x24]
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202A2AC

	arm_func_start sub_0202A2EC
sub_0202A2EC: ; 0x0202A2EC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r0, #0
	str r0, [r5, #4]
	ldr r4, [r5, #8]
	cmp r4, #0
	beq _0202A324
	beq _0202A31C
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_0202A2EC
_0202A31C:
	mov r0, #0
	str r0, [r5, #8]
_0202A324:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202A32C
sub_0202A32C: ; 0x0202A32C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	mov r6, r1
	mov r5, r2
	str r6, [r7, #0xc]
	mov r4, r3
	str r5, [r7, #0x14]
	mov r0, #0x44
	str r4, [r7, #0x1c]
	bl _Znwm
	cmp r0, #0
	beq _0202A384
	ldr r2, [r7]
	mov r1, #0x40
	str r1, [sp]
	add r1, r2, #0x1000
	add ip, r2, #0x24
	and r3, r5, #0xff
	ldr r2, [r1, #0x4a8]
	add r1, ip, r3, lsl #3
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
	arm_func_end sub_0202A32C
_0202A384:
	str r0, [r7, #8]
	str r4, [sp]
	ldr r0, [r7, #8]
	ldr r1, _0202A3FC ; =s_data_menu_0208c544
	ldr r2, _0202A400 ; =s_ma005_00_0208c550
	mov r3, r6
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r1, r0, asr #4
	add r0, r0, r1, lsr #27
	mov r0, r0, asr #5
	str r0, [r7, #0x10]
	mov r1, #0
	str r1, [sp]
	ldr r0, [r7, #8]
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r1, #0x20
	str r0, [r7, #4]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r7, #4]
	mov r2, r1
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	ldr r1, [r7, #8]
	mov r0, #1
	ldr r1, [r1, #0x30]
	str r1, [r7, #0x18]
	str r0, [r7, #0x20]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0202A3FC: .word s_data_menu_0208c544
_0202A400: .word s_ma005_00_0208c550

	arm_func_start sub_0202A404
sub_0202A404: ; 0x0202A404
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r0, #0
	str r0, [r4, #0x24]
	ldr r0, [r4, #4]
	cmp r0, #0
	ldrne r1, [r4, #0x20]
	cmpne r1, #0
	beq _0202A470
	ldr r1, [r4]
	ldr r1, [r1, #0x14]
	ldrh r1, [r1, #2]
	and r1, r1, #2
	mov r1, r1, lsl #0x10
	movs r1, r1, lsr #0x10
	bne _0202A450
	bl _ZN17UnkClass_0200E96012sub_0200EB84Ev
	cmp r0, #0
	beq _0202A470
	arm_func_end sub_0202A404
_0202A450:
	ldr r0, [r4]
	ldr r1, _0202A478 ; =0x00000103
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #1
	str r0, [r4, #0x24]
	ldmia sp!, {r4, pc}
_0202A470:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202A478: .word 0x00000103

	arm_func_start sub_0202A47C
sub_0202A47C: ; 0x0202A47C
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #8]
	cmp r1, #0
	ldrne r0, [r0, #0x20]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	mov r0, r1
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202A47C

	arm_func_start sub_0202A4A0
sub_0202A4A0: ; 0x0202A4A0
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	mov r2, #0x60
	bl MI_CpuFill8
	ldr r0, [r4, #0x64]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3]
	mov r2, #0x60
	blx r3
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202A4A0

	arm_func_start sub_0202A4D8
sub_0202A4D8: ; 0x0202A4D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, #0
	mov r2, #0x800
	bl MI_CpuFill8
	ldr r0, [r4, #0x804]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r3, [r0]
	mov r1, r4
	ldr r3, [r3]
	mov r2, #0x800
	blx r3
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202A4D8

	arm_func_start sub_0202A510
sub_0202A510: ; 0x0202A510
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r1, [r4, #0x64]
	bl sub_0202A53C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202A510

	arm_func_start sub_0202A528
sub_0202A528: ; 0x0202A528
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202A5FC
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202A528

	arm_func_start sub_0202A53C
sub_0202A53C: ; 0x0202A53C
	stmdb sp!, {r4, lr}
	mov r1, #0
	mov r4, r0
	strh r1, [r4]
	str r1, [r4, #0x10]
	str r1, [r4, #0x14]
	str r1, [r4, #0x18]
	str r1, [r4, #8]
	str r1, [r4, #0xc]
	str r1, [r4, #0x20]
	mov r2, r1
	arm_func_end sub_0202A53C
_0202A568:
	add r0, r4, r1, lsl #2
	add r1, r1, #1
	str r2, [r0, #0x28]
	cmp r1, #5
	blt _0202A568
	mov r1, #0x25
	mov r0, #0xc
	str r2, [r4, #4]
	str r2, [r4, #0x5c]
	smulbb r0, r1, r0
	str r1, [r4, #0x24]
	bl _Znam
	str r0, [r4, #0x1c]
	mov r0, #1
	str r0, [r4, #0x60]
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202A5A8
sub_0202A5A8: ; 0x0202A5A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0202A5C0
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	arm_func_end sub_0202A5A8
_0202A5C0:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _0202A5D0
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
_0202A5D0:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _0202A5E0
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
_0202A5E0:
	mov r0, r4
	bl sub_0202AE7C
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202A5EC
sub_0202A5EC: ; 0x0202A5EC
	ldr ip, _0202A5F4 ; =sub_0202A6E8
	bx ip
	.align 2, 0
_0202A5F4: .word sub_0202A6E8
	arm_func_end sub_0202A5EC

	arm_func_start sub_0202A5F8
sub_0202A5F8: ; 0x0202A5F8
	bx lr
	arm_func_end sub_0202A5F8

	arm_func_start sub_0202A5FC
sub_0202A5FC: ; 0x0202A5FC
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r5, [r4, #0xc]
	cmp r5, #0
	beq _0202A62C
	beq _0202A624
	mov r0, r5
	bl _ZN17UnkClass_02021404D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end sub_0202A5FC
_0202A624:
	mov r0, #0
	str r0, [r4, #0xc]
_0202A62C:
	ldr r5, [r4, #0x10]
	cmp r5, #0
	beq _0202A654
	beq _0202A64C
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_0202A64C:
	mov r0, #0
	str r0, [r4, #0x10]
_0202A654:
	ldr r5, [r4, #0x14]
	cmp r5, #0
	beq _0202A67C
	beq _0202A674
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_0202A674:
	mov r0, #0
	str r0, [r4, #0x14]
_0202A67C:
	ldr r5, [r4, #0x18]
	cmp r5, #0
	beq _0202A6A4
	beq _0202A69C
	mov r0, r5
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r5
	bl _ZdlPv
_0202A69C:
	mov r0, #0
	str r0, [r4, #0x18]
_0202A6A4:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0202A6BC
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #0x1c]
_0202A6BC:
	ldr r5, [r4, #0x20]
	cmp r5, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _0202A6DC
	mov r0, r5
	bl _ZN17UnkClass_0201FC80D1Ev
	mov r0, r5
	bl _ZdlPv
_0202A6DC:
	mov r0, #0
	str r0, [r4, #0x20]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202A6E8
sub_0202A6E8: ; 0x0202A6E8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0202A700
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	arm_func_end sub_0202A6E8
_0202A700:
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _0202A710
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
_0202A710:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202A724
sub_0202A724: ; 0x0202A724
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov r5, r0
	ldr r6, [r5, #0x20]
	mov r7, r1
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	cmp r6, #0
	ldr r4, [sp, #0x38]
	beq _0202A76C
	cmp r6, #0
	beq _0202A764
	mov r0, r6
	bl _ZN17UnkClass_0201FC80D1Ev
	mov r0, r6
	bl _ZdlPv
	arm_func_end sub_0202A724
_0202A764:
	mov r0, #0
	str r0, [r5, #0x20]
_0202A76C:
	mov r0, #0x64
	bl _Znwm
	cmp r0, #0
	beq _0202A784
	ldr r1, [r5, #0x64]
	bl _ZN17UnkClass_0201FC80C1Ei
_0202A784:
	str r0, [r5, #0x20]
	mov r1, r7
	bl _ZN17UnkClass_0201FC805SetBGEi
	ldr r0, [r5, #0x20]
	ldr r1, _0202ACDC ; =s_menu_0208cc1c
	ldr r2, _0202ACE0 ; =s_map000_0208cc24
	bl _ZN17UnkClass_0201FC8011LoadArchiveEPKcS1_
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5, #0x20]
	ldr r1, _0202ACE4 ; =s_map000_0208cc2c
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadCharEPKcimm
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5, #0x20]
	ldr r1, _0202ACE4 ; =s_map000_0208cc2c
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadPlttEPKcimm
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r5, #0x20]
	ldr r1, _0202ACE4 ; =s_map000_0208cc2c
	mov r3, r2
	bl _ZN17UnkClass_0201FC807LoadScrEPKcimmmm
	ldr r0, [r5, #0x20]
	bl _ZN17UnkClass_0201FC8014ReleaseArchiveEv
	ldr r0, [r5, #0x20]
	bl _ZN17UnkClass_0201FC8014LoadCharToVramEv
	ldr r0, [r5, #0x20]
	ldr r1, [sp, #0x3c]
	bl _ZN17UnkClass_0201FC8014LoadPlttToVramEi
	ldr r0, [r5, #0x20]
	bl _ZN17UnkClass_0201FC8013LoadScrToVramEv
	cmp r7, #3
	addls pc, pc, r7, lsl #2
	b _0202A838
_0202A820: ; jump table
	b _0202A830 ; case 0
	b _0202A830 ; case 1
	b _0202A830 ; case 2
	b _0202A830 ; case 3
_0202A830:
	mov fp, #1
	b _0202A83C
_0202A838:
	mov fp, #0
_0202A83C:
	ldr r0, [r4]
	str r0, [r5, #0x50]
	ldr r0, [sp, #0x10]
	ldr r6, [r5, #0x10]
	ldr r8, [r0]
	ldr r0, [sp, #0xc]
	cmp r6, #0
	ldrb sb, [r0]
	beq _0202A880
	cmp r6, #0
	beq _0202A878
	mov r0, r6
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r6
	bl _ZdlPv
_0202A878:
	mov r0, #0
	str r0, [r5, #0x10]
_0202A880:
	cmp fp, #0
	mov r0, #0x44
	beq _0202A8C4
	bl _Znwm
	cmp r0, #0
	beq _0202A8BC
	ldr r2, [r5, #0x64]
	mov r1, #0x40
	str r1, [sp]
	add r1, r2, #0x1000
	add r3, r2, #0x24
	ldr r2, [r1, #0x4a8]
	add r1, r3, sb, lsl #3
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0202A8BC:
	str r0, [r5, #0x10]
	b _0202A8FC
_0202A8C4:
	bl _Znwm
	cmp r0, #0
	beq _0202A8F8
	ldr r6, [r5, #0x64]
	mov r2, #0x40
	add r1, r6, #0x24
	add r3, r1, #0x400
	str r2, [sp]
	add r1, r6, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r3, sb, lsl #3
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0202A8F8:
	str r0, [r5, #0x10]
_0202A8FC:
	ldr r1, [r4]
	mov r0, r8, asr #4
	str r1, [sp]
	add r3, r8, r0, lsr #27
	ldr r0, [r5, #0x10]
	ldr r1, _0202ACE8 ; =s_data_menu_0208cc34
	ldr r2, _0202ACEC ; =s_map000_00_0208cc40
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200F168EPKcS1_mm
	add r8, r8, r0
	ldr r0, [r5, #0x10]
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
	ldr r0, [r5, #0x24]
	mov r7, #0
	cmp r0, #0
	ble _0202AA04
	mov sl, r7
	mov r6, #0x10
_0202A944:
	mov r0, #3
	str r0, [sp]
	ldr r0, [r5, #0x10]
	mov r1, r7
	mov r2, #0x80
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	ldr r2, [r5, #0x1c]
	mov r1, r6
	str r0, [r2, sl]
	ldr r2, [r5, #0x10]
	ldr r0, [r5, #0x1c]
	ldr r2, [r2, #0x24]
	add r0, r0, sl
	str r2, [r0, #4]
	ldr r0, [r5, #0x1c]
	mov r2, r6
	ldr r0, [r0, sl]
	ldr r3, [r0, #4]
	ldr r3, [r3, #4]
	ldrh ip, [r3]
	and ip, ip, #0xff
	add ip, ip, #0x68
	mov ip, ip, lsl #0x10
	mov ip, ip, asr #0x10
	and ip, ip, #0xff
	sub ip, ip, #0x60
	mov ip, ip, lsl #0x10
	mov ip, ip, asr #0x10
	str ip, [sp]
	ldrh ip, [r3, #2]
	ldr r3, _0202ACF0 ; =0x000001FF
	and r3, ip, r3
	mov r3, r3, lsl #0x10
	mov r3, r3, asr #0x10
	add r3, r3, #0x88
	mov r3, r3, lsl #0x10
	mov r3, r3, asr #0x10
	and r3, r3, #0xff
	sub r3, r3, #0x80
	mov r3, r3, lsl #0x10
	mov r3, r3, asr #0x10
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	ldr r0, [r5, #0x24]
	add r7, r7, #1
	add sl, sl, #0xc
	cmp r7, r0
	blt _0202A944
_0202AA04:
	ldr r0, [r5, #0x10]
	ldr r6, [r5, #0x14]
	ldr r0, [r0, #0x30]
	cmp r6, #0
	add r0, sb, r0
	and sb, r0, #0xff
	beq _0202AA40
	cmp r6, #0
	beq _0202AA38
	mov r0, r6
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r6
	bl _ZdlPv
_0202AA38:
	mov r0, #0
	str r0, [r5, #0x14]
_0202AA40:
	cmp fp, #0
	mov r0, #0x44
	beq _0202AA84
	bl _Znwm
	cmp r0, #0
	beq _0202AA7C
	ldr r2, [r5, #0x64]
	mov r1, #0x40
	str r1, [sp]
	add r1, r2, #0x1000
	add r3, r2, #0x24
	ldr r2, [r1, #0x4a8]
	add r1, r3, sb, lsl #3
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0202AA7C:
	str r0, [r5, #0x14]
	b _0202AABC
_0202AA84:
	bl _Znwm
	cmp r0, #0
	beq _0202AAB8
	ldr r6, [r5, #0x64]
	mov r2, #0x40
	add r1, r6, #0x24
	add r3, r1, #0x400
	str r2, [sp]
	add r1, r6, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r3, sb, lsl #3
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0202AAB8:
	str r0, [r5, #0x14]
_0202AABC:
	ldr r1, [r4]
	mov r0, r8, asr #4
	add r1, r1, #2
	str r1, [r4]
	str r1, [sp]
	add r3, r8, r0, lsr #27
	ldr r0, [r5, #0x14]
	ldr r1, _0202ACE8 ; =s_data_menu_0208cc34
	ldr r2, _0202ACF4 ; =s_map000_01_0208cc4c
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200F168EPKcS1_mm
	add r8, r8, r0
	ldr r0, [r5, #0x14]
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
	ldr r0, _0202ACF8 ; =MAIN_BSS_020B26A0
	mov r2, #0
	ldrb r0, [r0]
	mov r1, #0
	mov r3, r2
	cmp r0, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x14]
	movne r1, #1
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r1, #0x18
	str r0, [r5, #0x2c]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #0x2c]
	mov r2, r1
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	ldr r0, [r5, #0x14]
	ldr r6, [r5, #0x18]
	ldr r0, [r0, #0x30]
	cmp r6, #0
	add r0, sb, r0
	and sb, r0, #0xff
	beq _0202AB78
	cmp r6, #0
	beq _0202AB70
	mov r0, r6
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r6
	bl _ZdlPv
_0202AB70:
	mov r0, #0
	str r0, [r5, #0x18]
_0202AB78:
	cmp fp, #0
	mov r0, #0x44
	beq _0202ABBC
	bl _Znwm
	cmp r0, #0
	beq _0202ABB4
	ldr r2, [r5, #0x64]
	mov r1, #0x40
	str r1, [sp]
	add r1, r2, #0x1000
	add r3, r2, #0x24
	ldr r2, [r1, #0x4a8]
	add r1, r3, sb, lsl #3
	mov r3, #0
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0202ABB4:
	str r0, [r5, #0x18]
	b _0202ABF4
_0202ABBC:
	bl _Znwm
	cmp r0, #0
	beq _0202ABF0
	ldr r6, [r5, #0x64]
	mov r2, #0x40
	add r1, r6, #0x24
	add r3, r1, #0x400
	str r2, [sp]
	add r1, r6, #0x1000
	ldr r2, [r1, #0x4a8]
	add r1, r3, sb, lsl #3
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_0202ABF0:
	str r0, [r5, #0x18]
_0202ABF4:
	ldr r1, [r4]
	mov r0, r8, asr #4
	add r1, r1, #1
	str r1, [r4]
	str r1, [sp]
	add r3, r8, r0, lsr #27
	ldr r0, [r5, #0x18]
	ldr r1, _0202ACE8 ; =s_data_menu_0208cc34
	ldr r2, _0202ACFC ; =s_map000_02_0208cc58
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200F168EPKcS1_mm
	add r8, r8, r0
	ldr r0, [r5, #0x18]
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
	mov r1, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x18]
	mov r2, r1
	mov r3, r1
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r1, #0x20
	str r0, [r5, #0x38]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #0x38]
	mov r2, r1
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	mov r1, #0
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x18]
	mov r2, r1
	mov r3, r1
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r1, #0x18
	str r0, [r5, #0x34]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #0x34]
	mov r2, r1
	bl _ZN17UnkClass_0200E96012sub_0200EBF4Essss
	ldr r1, [r5, #0x18]
	ldr r0, _0202AD00 ; =MAIN_BSS_0210CA6C
	ldr r1, [r1, #0x30]
	ldr r0, [r0]
	add r1, sb, r1
	str r0, [r5, #8]
	ldr r0, [sp, #0x10]
	str r8, [r0]
	ldr r0, [sp, #0xc]
	strb r1, [r0]
	mov r0, r5
	bl sub_0202B2CC
	mov r0, r5
	bl sub_0202AED4
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202ACDC: .word s_menu_0208cc1c
_0202ACE0: .word s_map000_0208cc24
_0202ACE4: .word s_map000_0208cc2c
_0202ACE8: .word s_data_menu_0208cc34
_0202ACEC: .word s_map000_00_0208cc40
_0202ACF0: .word 0x000001FF
_0202ACF4: .word s_map000_01_0208cc4c
_0202ACF8: .word MAIN_BSS_020B26A0
_0202ACFC: .word s_map000_02_0208cc58
_0202AD00: .word MAIN_BSS_0210CA6C

	arm_func_start sub_0202AD04
sub_0202AD04: ; 0x0202AD04
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x20]
	mov r4, r1
	cmp r0, #0
	beq _0202AD34
	bl _ZN17UnkClass_0201FC8014LoadCharToVramEv
	ldr r0, [r5, #0x20]
	mov r1, r4
	bl _ZN17UnkClass_0201FC8014LoadPlttToVramEi
	ldr r0, [r5, #0x20]
	bl _ZN17UnkClass_0201FC8013LoadScrToVramEv
	arm_func_end sub_0202AD04
_0202AD34:
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0202AD44
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
_0202AD44:
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq _0202AD54
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
_0202AD54:
	ldr r0, [r5, #0x18]
	cmp r0, #0
	beq _0202AD64
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
_0202AD64:
	mov r0, r5
	bl sub_0202B2CC
	mov r0, r5
	bl sub_0202AED4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202AD78
sub_0202AD78: ; 0x0202AD78
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldr r0, [r7, #0x60]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mvn r0, #0
	strh r0, [r7, #0x58]
	add r0, r0, #0x10000
	strh r0, [r7, #0x54]
	mov r4, #0
	arm_func_end sub_0202AD78
_0202ADA0:
	add r0, r7, r4, lsl #2
	ldr r0, [r0, #0x28]
	cmp r0, #0
	beq _0202ADD4
	cmp r4, #1
	beq _0202ADC4
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq _0202ADD4
_0202ADC4:
	bl _ZN17UnkClass_0200E96012sub_0200EB84Ev
	cmp r0, #0
	strneh r4, [r7, #0x58]
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
_0202ADD4:
	add r4, r4, #1
	cmp r4, #1
	ble _0202ADA0
	ldr r0, [r7, #0x24]
	mov r6, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r5, _0202AE78 ; =DAT_0208c938
	mov r4, r6
_0202ADF8:
	ldr r0, [r7, #0x1c]
	ldr r0, [r0, r4]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq _0202AE5C
	bl _ZN17UnkClass_0200E96012sub_0200EB84Ev
	cmp r0, #0
	beq _0202AE5C
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x50]
	ldr r0, [r0, r4]
	ldrh r0, [r0, #0x1a]
	cmp r1, r0
	bne _0202AE5C
	ldrh r0, [r5, #0xc]
	cmp r0, #2
	beq _0202AE5C
	mov r0, #0x14
	mul r2, r6, r0
	ldr r1, _0202AE78 ; =DAT_0208c938
	mov r0, #6
	ldrh r1, [r1, r2]
	strh r1, [r7, #0x54]
	strh r0, [r7, #0x58]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_0202AE5C:
	ldr r0, [r7, #0x24]
	add r6, r6, #1
	cmp r6, r0
	add r4, r4, #0xc
	add r5, r5, #0x14
	blt _0202ADF8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0202AE78: .word DAT_0208c938

	arm_func_start sub_0202AE7C
sub_0202AE7C: ; 0x0202AE7C
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #0x5c]
	ldr r2, _0202AED0 ; =0x88888889
	add ip, r1, #1
	smull r1, lr, r2, ip
	add lr, ip, lr
	mov r1, ip, lsr #0x1f
	add lr, r1, lr, asr #4
	mov r3, #0x1e
	smull r1, r2, r3, lr
	sub lr, ip, r1
	cmp lr, #0xf
	movlt r1, #1
	movge r1, #0
	str lr, [r0, #0x5c]
	cmp r1, #0
	movne r1, #1
	ldr r0, [r0, #0x2c]
	moveq r1, #0
	str r1, [r0, #0x14]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202AED0: .word 0x88888889
	arm_func_end sub_0202AE7C

	arm_func_start sub_0202AED4
sub_0202AED4: ; 0x0202AED4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #8
	ldr r1, _0202AF58 ; =MAIN_BSS_020B26A0+32612
	add r6, sp, #0
	ldmia r1, {r2, r3}
	stmia r6, {r2, r3}
	mov sb, r0
	ldr r0, [sb, #0x24]
	mov r7, #0
	cmp r0, #0
	addle sp, sp, #8
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r8, r7
	mov r4, #1
	mov r5, r7
	arm_func_end sub_0202AED4
_0202AF10:
	ldr r1, [sb, #0x1c]
	mov r0, sb
	ldr r3, [r1, r8]
	mov r1, r7
	mov r2, r6
	str r5, [r3, #0x14]
	bl sub_0202B244
	cmp r0, #0
	ldrne r0, [sb, #0x1c]
	add r7, r7, #1
	ldrne r0, [r0, r8]
	add r8, r8, #0xc
	strne r4, [r0, #0x14]
	ldr r0, [sb, #0x24]
	cmp r7, r0
	blt _0202AF10
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0202AF58: .word MAIN_BSS_020B26A0+32612

	arm_func_start sub_0202AF5C
sub_0202AF5C: ; 0x0202AF5C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	mov r5, r0
	ldr r0, [r5, #0x24]
	mov fp, #0
	mov r4, r1
	mov r2, fp
	cmp r0, #0
	ldr r3, _0202B138 ; =MAIN_BSS_020B26A0
	ble _0202AFAC
	mov r6, fp
	mov r1, fp
	arm_func_end sub_0202AF5C
_0202AF8C:
	ldr r0, [r5, #0x1c]
	add r2, r2, #1
	ldr r0, [r0, r6]
	add r6, r6, #0xc
	str r1, [r0, #0x14]
	ldr r0, [r5, #0x24]
	cmp r2, r0
	blt _0202AF8C
_0202AFAC:
	add r0, r3, #0x364
	add r1, r0, #0x7c00
	add r0, sp, #0
	ldmia r1, {r2, r3}
	stmia r0, {r2, r3}
	ldr r1, [r4, #4]
	mov r0, #0xf
	and r0, r0, r1, lsr #28
	mov r0, r0, lsl #0x10
	mov r1, r0, lsr #0x10
	cmp r1, #3
	mov r0, #0
	addls pc, pc, r1, lsl #2
	b _0202B038
_0202AFE4: ; jump table
	b _0202AFF4 ; case 0
	b _0202B038 ; case 1
	b _0202AFFC ; case 2
	b _0202B01C ; case 3
_0202AFF4:
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0202AFFC:
	ldr r1, [r5, #0x64]
	add r1, r1, #0x1000
	ldr r1, [r1, #0x4a0]
	ldr r1, [r1, #8]
	cmp r1, #0x45
	bge _0202B038
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0202B01C:
	ldr r1, [r5, #0x64]
	add r1, r1, #0x1000
	ldr r1, [r1, #0x4a0]
	ldr r1, [r1, #8]
	cmp r1, #0x37
	addlt sp, sp, #8
	ldmltia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0202B038:
	ldr r0, [r5, #0x24]
	mov sl, #0
	cmp r0, #0
	ble _0202B0F0
	ldr r8, _0202B13C ; =DAT_0208c938
	mov sb, sl
	mov r7, #1
	mov r6, sl
_0202B058:
	mov r0, r5
	mov r1, sl
	add r2, sp, #0
	bl sub_0202B244
	cmp r0, #0
	beq _0202B0D8
	ldrh r2, [r8]
	ldr r1, [r8, #4]
	ldr r0, [r8, #8]
	cmp r2, #0xc8
	ldr r2, [r5, #0x1c]
	movhs r1, #0
	ldr r2, [r2, sb]
	movhs r0, r1
	str r7, [r2, #0x14]
	ldr r3, [r4]
	ldr r2, [r4, #4]
	and r3, r1, r3
	and r1, r0, r2
	mov r0, #0
	cmp r1, r0
	cmpeq r3, r6
	ldr r0, [r5, #0x1c]
	ldr r1, [r5, #0x50]
	beq _0202B0CC
	ldr r0, [r0, sb]
	mov fp, r7
	strh r1, [r0, #0x1a]
	b _0202B0D8
_0202B0CC:
	ldr r0, [r0, sb]
	add r1, r1, #1
	strh r1, [r0, #0x1a]
_0202B0D8:
	ldr r0, [r5, #0x24]
	add sl, sl, #1
	cmp sl, r0
	add r8, r8, #0x14
	add sb, sb, #0xc
	blt _0202B058
_0202B0F0:
	cmp fp, #0
	bne _0202B12C
	cmp r0, #0
	mov r3, #0
	ble _0202B12C
	mov r2, r3
	mov r1, r3
_0202B10C:
	ldr r0, [r5, #0x1c]
	add r3, r3, #1
	ldr r0, [r0, r2]
	add r2, r2, #0xc
	str r1, [r0, #0x14]
	ldr r0, [r5, #0x24]
	cmp r3, r0
	blt _0202B10C
_0202B12C:
	mov r0, fp
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202B138: .word MAIN_BSS_020B26A0
_0202B13C: .word DAT_0208c938

	arm_func_start sub_0202B140
sub_0202B140: ; 0x0202B140
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	ldr r2, _0202B23C ; =MAIN_BSS_020B26A0+32612
	add r4, sp, #0
	ldmia r2, {r2, r3}
	stmia r4, {r2, r3}
	mov sl, r0
	ldr r0, [sl, #0x24]
	mov fp, #0
	mov sb, r1
	mov r6, fp
	cmp r0, #0
	ble _0202B230
	ldr r8, _0202B240 ; =DAT_0208c938
	mov r7, fp
	mov r5, #1
	mov r4, fp
	arm_func_end sub_0202B140
_0202B184:
	ldr r1, [sl, #0x1c]
	mov r2, #0
	ldr r3, [r1, r7]
	mov r0, sl
	str r2, [r3, #0x14]
	mov r1, r6
	add r2, sp, #0
	bl sub_0202B244
	cmp r0, #0
	beq _0202B218
	ldr r0, [sl, #0x1c]
	ldr r0, [r0, r7]
	str r5, [r0, #0x14]
	ldrh r1, [r8]
	ldr r2, [sb]
	ldr r0, [sb, #4]
	and r3, r2, r5, lsl r1
	mov r2, #0
	mov r2, r2, lsl r1
	rsb ip, r1, #0x20
	orr r2, r2, r5, lsr ip
	sub r1, r1, #0x20
	orr r2, r2, r5, lsl r1
	and r1, r2, r0
	mov r0, #0
	cmp r1, r0
	cmpeq r3, r4
	ldr r0, [sl, #0x1c]
	ldr r1, [sl, #0x50]
	beq _0202B20C
	ldr r0, [r0, r7]
	mov fp, r5
	strh r1, [r0, #0x1a]
	b _0202B218
_0202B20C:
	ldr r0, [r0, r7]
	add r1, r1, #1
	strh r1, [r0, #0x1a]
_0202B218:
	ldr r0, [sl, #0x24]
	add r6, r6, #1
	cmp r6, r0
	add r7, r7, #0xc
	add r8, r8, #0x14
	blt _0202B184
_0202B230:
	mov r0, fp
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202B23C: .word MAIN_BSS_020B26A0+32612
_0202B240: .word DAT_0208c938

	arm_func_start sub_0202B244
sub_0202B244: ; 0x0202B244
	ldr r0, [r0, #0x64]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	ldr r0, [r0, #8]
	cmp r0, #0x28
	mov r0, #0x14
	mul ip, r1, r0
	blt _0202B27C
	ldr r0, _0202B2C4 ; =DAT_0208c938
	ldrh r0, [r0, ip]
	cmp r0, #0x14
	bne _0202B290
	mov r0, #0
	bx lr
	arm_func_end sub_0202B244
_0202B27C:
	ldr r0, _0202B2C4 ; =DAT_0208c938
	ldrh r0, [r0, ip]
	cmp r0, #0x78
	moveq r0, #0
	bxeq lr
_0202B290:
	ldr r1, _0202B2C8 ; =DAT_0208c93c
	ldr r3, [r2]
	add r0, r1, ip
	ldr r1, [r1, ip]
	ldr r2, [r2, #4]
	ldr r0, [r0, #4]
	and r3, r3, r1
	and r1, r2, r0
	mov r0, #0
	cmp r1, r0
	cmpeq r3, r0
	movne r0, #1
	bx lr
	.align 2, 0
_0202B2C4: .word DAT_0208c938
_0202B2C8: .word DAT_0208c93c

	arm_func_start sub_0202B2CC
sub_0202B2CC: ; 0x0202B2CC
	stmdb sp!, {r4, lr}
	ldr r1, _0202B2F8 ; =MAIN_BSS_020B26A0
	mov r4, r0
	ldrh r1, [r1, #0x1a]
	bl sub_0202B338
	strh r0, [r4, #0x56]
	ldrh r2, [r4, #0x56]
	mov r0, r4
	mov r1, #1
	bl sub_0202B2FC
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202B2F8: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202B2CC

	arm_func_start sub_0202B2FC
sub_0202B2FC: ; 0x0202B2FC
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r4, r1
	mov r1, r2
	add r2, sp, #4
	add r3, sp, #0
	mov r5, r0
	bl sub_0202B370
	add r0, r5, r4, lsl #2
	ldr r0, [r0, #0x28]
	ldr r1, [sp, #4]
	ldr r2, [sp]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_0202B2FC

	arm_func_start sub_0202B338
sub_0202B338: ; 0x0202B338
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #8]
	bl sub_02041D80
	ldr r1, [r4, #0x64]
	ldrb r0, [r0]
	add r1, r1, #0x1000
	ldr r1, [r1, #0x4a0]
	ldr r1, [r1, #8]
	cmp r1, #0x28
	ldmltia sp!, {r4, pc}
	cmp r0, #0x14
	moveq r0, #0x78
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202B338

	arm_func_start sub_0202B370
sub_0202B370: ; 0x0202B370
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr ip, [r6, #0x10]
	mov r5, r2
	mov r4, r3
	cmp ip, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	mov r2, #0
	str r2, [r5]
	mov r2, #0xe0
	str r2, [r4]
	bl sub_0202B458
	cmp r0, #0
	ldmltia sp!, {r4, r5, r6, pc}
	mov r1, #0x14
	mul r3, r0, r1
	ldr r1, _0202B448 ; =DAT_0208c944
	ldrh r1, [r1, r3]
	cmp r1, #2
	movne r1, #8
	movne r2, r1
	bne _0202B3D8
	ldr r1, _0202B44C ; =DAT_0208c946
	ldr r2, _0202B450 ; =DAT_0208c948
	ldrsh r1, [r1, r3]
	ldrsh r2, [r2, r3]
	arm_func_end sub_0202B370
_0202B3D8:
	mov r3, #0xc
	mul r3, r0, r3
	ldr r6, [r6, #0x1c]
	ldr r0, _0202B454 ; =0x000001FF
	ldr ip, [r6, r3]
	ldr r3, [ip, #4]
	ldrsh r6, [ip, #0xc]
	ldr lr, [r3, #4]
	ldrsh ip, [ip, #0xe]
	ldrh r3, [lr, #2]
	ldrh lr, [lr]
	and r0, r3, r0
	mov r3, r0, lsl #0x10
	and lr, lr, #0xff
	mov r0, lr, lsl #0x10
	add r2, r2, r0, asr #16
	add r1, r1, r3, asr #16
	add r0, r1, r6
	mov r1, r0, lsl #0x10
	add r2, r2, ip
	mov r0, r2, lsl #0x10
	mov r1, r1, asr #0x10
	mov r0, r0, asr #0x10
	and r1, r1, #0xff
	and r0, r0, #0xff
	str r1, [r5]
	str r0, [r4]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0202B448: .word DAT_0208c944
_0202B44C: .word DAT_0208c946
_0202B450: .word DAT_0208c948
_0202B454: .word 0x000001FF

	arm_func_start sub_0202B458
sub_0202B458: ; 0x0202B458
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r3, [r0, #0x24]
	mov r0, #0
	cmp r3, #0
	ble _0202B48C
	ldr r4, _0202B508 ; =DAT_0208c938
	arm_func_end sub_0202B458
_0202B470:
	ldrh r2, [r4]
	cmp r1, r2
	beq _0202B48C
	add r0, r0, #1
	cmp r0, r3
	add r4, r4, #0x14
	blt _0202B470
_0202B48C:
	cmp r0, r3
	ldmltia sp!, {r3, r4, r5, r6, r7, pc}
	cmp r3, #0
	mov r0, #0
	ble _0202B4FC
	mov r2, r0, lsl r1
	rsb ip, r1, #0x20
	mov r6, #1
	orr r2, r2, r6, lsr ip
	sub ip, r1, #0x20
	orr r2, r2, r6, lsl ip
	ldr r7, _0202B508 ; =DAT_0208c938
	mov lr, r0
	mov ip, r0
_0202B4C4:
	ldrh r4, [r7]
	cmp r4, #0xc8
	bhs _0202B4EC
	ldr r5, [r7, #4]
	ldr r4, [r7, #8]
	and r5, r5, r6, lsl r1
	and r4, r2, r4
	cmp r4, lr
	cmpeq r5, ip
	bne _0202B4FC
_0202B4EC:
	add r0, r0, #1
	cmp r0, r3
	add r7, r7, #0x14
	blt _0202B4C4
_0202B4FC:
	cmp r0, r3
	mvnge r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0202B508: .word DAT_0208c938

	arm_func_start sub_0202B50C
sub_0202B50C: ; 0x0202B50C
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r4, r0
	cmp r2, #0
	mov r5, #3
	beq _0202B550
	cmp r2, #3
	beq _0202B554
	cmp r2, #4
	bne _0202B554
	ldr r0, [r4, #0x38]
	mov r1, #0
	str r1, [r0, #0x14]
	ldr r0, [r4, #0x34]
	add sp, sp, #8
	str r1, [r0, #0x14]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_0202B50C
_0202B550:
	mov r5, #4
_0202B554:
	add r2, sp, #4
	add r3, sp, #0
	mov r0, r4
	bl sub_0202B370
	cmp r5, #4
	moveq r0, #3
	movne r0, #4
	add r0, r4, r0, lsl #2
	ldr r0, [r0, #0x28]
	mov r1, #0
	str r1, [r0, #0x14]
	add r1, r4, r5, lsl #2
	ldr r0, [r1, #0x28]
	mov r2, #1
	str r2, [r0, #0x14]
	ldr r0, [r1, #0x28]
	ldr r1, [sp, #4]
	ldr r2, [sp]
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202B5A8
sub_0202B5A8: ; 0x0202B5A8
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl sub_0202AD78
	ldrsh r0, [r6, #0x58]
	strh r0, [r5]
	ldrh r0, [r6, #0x54]
	strh r0, [r4]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end sub_0202B5A8

	arm_func_start _ZN11CBackupBaseC2Ev
_ZN11CBackupBaseC2Ev: ; 0x0202B5D0
	ldr r2, _0202B5F0 ; =PTR_LAB_0208cc6c
	mov r1, #0
	str r2, [r0]
	str r1, [r0, #4]
	str r1, [r0, #0xc]
	sub r1, r1, #3
	str r1, [r0, #8]
	bx lr
	.align 2, 0
_0202B5F0: .word PTR_LAB_0208cc6c
	arm_func_end _ZN11CBackupBaseC2Ev

	arm_func_start _ZN11CBackupBaseD1Ev
_ZN11CBackupBaseD1Ev: ; 0x0202B5F4
	stmdb sp!, {r4, lr}
	ldr r1, _0202B618 ; =PTR_LAB_0208cc6c
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202B618: .word PTR_LAB_0208cc6c
	arm_func_end _ZN11CBackupBaseD1Ev

	arm_func_start _ZN11CBackupBaseD0Ev
_ZN11CBackupBaseD0Ev: ; 0x0202B61C
	stmdb sp!, {r4, lr}
	ldr r1, _0202B648 ; =PTR_LAB_0208cc6c
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202B648: .word PTR_LAB_0208cc6c
	arm_func_end _ZN11CBackupBaseD0Ev

	arm_func_start _ZN11CBackupBaseD2Ev
_ZN11CBackupBaseD2Ev: ; 0x0202B64C
	stmdb sp!, {r4, lr}
	ldr r1, _0202B670 ; =PTR_LAB_0208cc6c
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202B670: .word PTR_LAB_0208cc6c
	arm_func_end _ZN11CBackupBaseD2Ev

	arm_func_start _ZN11CBackupBase4InitEv
_ZN11CBackupBase4InitEv: ; 0x0202B674
	stmdb sp!, {r4, lr}
	ldr r1, _0202B6EC ; =sCardBackupInfo
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _0202B6C0
	bl CARD_Init
	bl OS_GetLockID
	mvn r1, #2
	str r0, [r4, #8]
	cmp r0, r1
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	mov r0, #1
	str r0, [r4, #4]
	arm_func_end _ZN11CBackupBase4InitEv
_0202B6C0:
	mov r0, r4
	bl sub_0202B72C
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r4, pc}
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202B6EC: .word sCardBackupInfo

	arm_func_start _ZN11CBackupBase8FinalizeEv
_ZN11CBackupBase8FinalizeEv: ; 0x0202B6F0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0202B724
	ldr r0, [r4, #8]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl OS_ReleaseLockID
	mov r0, #0
	str r0, [r4, #4]
	sub r0, r0, #3
	str r0, [r4, #8]
	arm_func_end _ZN11CBackupBase8FinalizeEv
_0202B724:
	mov r0, #1
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202B72C
sub_0202B72C: ; 0x0202B72C
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x18
	mov r5, r0
	ldr r0, [r5, #8]
	mov r4, #0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl CARD_LockBackup
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #1
	moveq r0, #1
	movne r0, r4
	cmp r0, #0
	beq _0202B79C
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r1, #6
	str r1, [sp, #8]
	mov r2, #1
	str r2, [sp, #0xc]
	add r1, sp, #0x14
	mov r3, r0
	str r0, [sp, #0x10]
	bl CARDi_RequestStreamCommand
	mov r4, r0
	b _0202B7E8
	arm_func_end sub_0202B72C
_0202B79C:
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _0202B7E8
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r1, #6
	str r1, [sp, #8]
	mov r2, #1
	str r2, [sp, #0xc]
	add r1, sp, #0x14
	mov r3, r0
	str r0, [sp, #0x10]
	bl CARDi_RequestStreamCommand
	mov r4, r0
_0202B7E8:
	bl CARD_GetResultCode
	str r0, [r5, #0xc]
	ldr r0, [r5, #8]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl CARD_UnlockBackup
	mov r0, r4
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, pc}
