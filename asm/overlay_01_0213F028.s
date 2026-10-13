    .include "macros.inc"
    .include "include/overlay_01_0213F028.inc"

    .text

	arm_func_start _ZN17UnkClass_0213F028C1Et
_ZN17UnkClass_0213F028C1Et: ; 0x0213F028
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x10
	mov r5, r0
	add r0, r5, #0x14
	mov r4, r1
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r5, #0x64
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r5, #0xb0
	bl _ZN15CSoftwareSpriteC1Ev
	add r0, r5, #0x100
	bl _ZN15CSoftwareSpriteC1Ev
	mov r0, r5
	mov r1, r4
	strh r4, [r5, #2]
	bl ov1_0213F0C8
	mov r0, #0
	mov r1, #0x18000
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r0, [sp]
	str r0, [r5, #8]
	mov r0, r5
	str r1, [r5, #0xc]
	str r1, [sp, #4]
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_0213F028C1Et

	arm_func_start _ZN17UnkClass_0213F028D1Ev
_ZN17UnkClass_0213F028D1Ev: ; 0x0213F094
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213F2B4
	add r0, r4, #0x100
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0xb0
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x64
	bl _ZN15CSoftwareSpriteD1Ev
	add r0, r4, #0x14
	bl _ZN15CSoftwareSpriteD1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F028D1Ev

	arm_func_start ov1_0213F0C8
ov1_0213F0C8: ; 0x0213F0C8
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x1ec
	cmp r1, #7
	mov r4, r0
	addeq sp, sp, #0x1ec
	ldmeqia sp!, {r4, r5, pc}
	addhi sp, sp, #0x1ec
	ldmhiia sp!, {r4, r5, pc}
	add r0, r1, #0x30
	and r5, r0, #0xff
	ldr r1, _0213F27C ; =s_data_interface_i_03d_LZ_bin_overlay_1_021420e0
	add r0, sp, #0x18c
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F280 ; =s_BCO_i_03d_00_NCBR_overlay_1_021420fc
	add r0, sp, #0x12c
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F284 ; =s_BCO_i_03d_NCLR_overlay_1_02142110
	add r0, sp, #0xcc
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F288 ; =s_BCO_i_03d_00_NCER_overlay_1_02142120
	add r0, sp, #0x6c
	mov r2, r5
	bl OS_SPrintf
	ldr r1, _0213F28C ; =s_BCO_i_03d_00_cac_overlay_1_02142134
	mov r2, r5
	add r0, sp, #0xc
	bl OS_SPrintf
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0213F178
	add r2, sp, #0xcc
	str r2, [sp]
	add r1, sp, #0x6c
	str r1, [sp, #4]
	add ip, sp, #0xc
	ldr r1, _0213F290 ; =s_BCO_overlay_1_02142148
	add r2, sp, #0x18c
	add r3, sp, #0x12c
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
	arm_func_end ov1_0213F0C8
_0213F178:
	str r0, [r4, #0x60]
	ldr r0, [r0, #0xc]
	mov r1, #1
	mov r2, #0
	str r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008A80Emm
	add r1, r4, #0x100
	strh r0, [r1, #0x54]
	ldr r0, [r4, #0x60]
	mov r1, #0
	ldmia r0, {r2, r3, ip}
	str r2, [r4, #0x40]
	str r1, [r4, #0x44]
	str r3, [r4, #0x48]
	mov r0, #0x18
	str ip, [r4, #0x4c]
	bl _Znwm
	cmp r0, #0
	beq _0213F1EC
	ldr r1, _0213F294 ; =s_BCO_i055_NCLR_overlay_1_0214217c
	ldr ip, _0213F298 ; =s_BCO_i055_00_NCER_overlay_1_0214218c
	str r1, [sp]
	ldr r1, _0213F290 ; =s_BCO_overlay_1_02142148
	ldr r2, _0213F29C ; =s_data_interface_i055_LZ_bin_overlay_1_0214214c
	ldr r3, _0213F2A0 ; =s_BCO_i055_00_NCBR_overlay_1_02142168
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213F1EC:
	str r0, [r4, #0xfc]
	ldmia r0, {r0, r1, r2}
	str r0, [r4, #0x90]
	mov ip, #0
	str ip, [r4, #0x94]
	str r1, [r4, #0x98]
	str r2, [r4, #0x9c]
	ldr r1, [r4, #0xfc]
	mov r0, #0x18
	ldmia r1, {r1, r2, r3}
	str r1, [r4, #0xdc]
	str ip, [r4, #0xe0]
	str r2, [r4, #0xe4]
	str r3, [r4, #0xe8]
	bl _Znwm
	cmp r0, #0
	beq _0213F258
	ldr r1, _0213F2A4 ; =s_BCO_i056_NCLR_overlay_1_021421d0
	ldr ip, _0213F2A8 ; =s_BCO_i056_00_NCER_overlay_1_021421e0
	str r1, [sp]
	ldr r1, _0213F290 ; =s_BCO_overlay_1_02142148
	ldr r2, _0213F2AC ; =s_data_interface_i056_LZ_bin_overlay_1_021421a0
	ldr r3, _0213F2B0 ; =s_BCO_i056_00_NCBR_overlay_1_021421bc
	str ip, [sp, #4]
	mov ip, #0
	str ip, [sp, #8]
	bl _ZN17UnkClass_0201AAE0C1EPKcS1_S1_S1_S1_S1_
_0213F258:
	str r0, [r4, #0x14c]
	ldmia r0, {r1, r2, r3}
	mov r0, #0
	str r1, [r4, #0x12c]
	str r0, [r4, #0x130]
	str r2, [r4, #0x134]
	str r3, [r4, #0x138]
	add sp, sp, #0x1ec
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_0213F27C: .word s_data_interface_i_03d_LZ_bin_overlay_1_021420e0
_0213F280: .word s_BCO_i_03d_00_NCBR_overlay_1_021420fc
_0213F284: .word s_BCO_i_03d_NCLR_overlay_1_02142110
_0213F288: .word s_BCO_i_03d_00_NCER_overlay_1_02142120
_0213F28C: .word s_BCO_i_03d_00_cac_overlay_1_02142134
_0213F290: .word s_BCO_overlay_1_02142148
_0213F294: .word s_BCO_i055_NCLR_overlay_1_0214217c
_0213F298: .word s_BCO_i055_00_NCER_overlay_1_0214218c
_0213F29C: .word s_data_interface_i055_LZ_bin_overlay_1_0214214c
_0213F2A0: .word s_BCO_i055_00_NCBR_overlay_1_02142168
_0213F2A4: .word s_BCO_i056_NCLR_overlay_1_021421d0
_0213F2A8: .word s_BCO_i056_00_NCER_overlay_1_021421e0
_0213F2AC: .word s_data_interface_i056_LZ_bin_overlay_1_021421a0
_0213F2B0: .word s_BCO_i056_00_NCBR_overlay_1_021421bc

	arm_func_start ov1_0213F2B4
ov1_0213F2B4: ; 0x0213F2B4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0x60]
	cmp r4, #0
	beq _0213F2E4
	beq _0213F2DC
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end ov1_0213F2B4
_0213F2DC:
	mov r0, #0
	str r0, [r5, #0x60]
_0213F2E4:
	ldr r4, [r5, #0xfc]
	cmp r4, #0
	beq _0213F30C
	beq _0213F304
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213F304:
	mov r0, #0
	str r0, [r5, #0xfc]
_0213F30C:
	ldr r4, [r5, #0x14c]
	cmp r4, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _0213F32C
	mov r0, r4
	bl _ZN17UnkClass_0201AAE0D1Ev
	mov r0, r4
	bl _ZdlPv
_0213F32C:
	mov r0, #0
	str r0, [r5, #0x14c]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F338Ev
_ZN17UnkClass_0213F02812ov1_0213F338Ev: ; 0x0213F338
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #4]
	cmp r1, #0xb
	addls pc, pc, r1, lsl #2
	ldmia sp!, {r3, pc}
_0213F34C: ; jump table
	ldmia sp!, {r3, pc} ; case 0
	b _0213F37C ; case 1
	b _0213F384 ; case 2
	b _0213F38C ; case 3
	b _0213F394 ; case 4
	b _0213F39C ; case 5
	b _0213F3A4 ; case 6
	b _0213F3AC ; case 7
	b _0213F3B4 ; case 8
	b _0213F3BC ; case 9
	b _0213F3C4 ; case 10
	b _0213F3CC ; case 11
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F338Ev
_0213F37C:
	bl ov1_0213F3D4
	ldmia sp!, {r3, pc}
_0213F384:
	bl ov1_0213F41C
	ldmia sp!, {r3, pc}
_0213F38C:
	bl ov1_0213F490
	ldmia sp!, {r3, pc}
_0213F394:
	bl ov1_0213F504
	ldmia sp!, {r3, pc}
_0213F39C:
	bl ov1_0213F578
	ldmia sp!, {r3, pc}
_0213F3A4:
	bl ov1_0213F5A0
	ldmia sp!, {r3, pc}
_0213F3AC:
	bl ov1_0213F608
	ldmia sp!, {r3, pc}
_0213F3B4:
	bl ov1_0213F688
	ldmia sp!, {r3, pc}
_0213F3BC:
	bl ov1_0213F6D0
	ldmia sp!, {r3, pc}
_0213F3C4:
	bl ov1_0213F794
	ldmia sp!, {r3, pc}
_0213F3CC:
	bl ov1_0213F7E4
	ldmia sp!, {r3, pc}

	arm_func_start ov1_0213F3D4
ov1_0213F3D4: ; 0x0213F3D4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #1
	ldmloia sp!, {r4, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	ldr r1, _0213F418 ; =s_system_000_overlay_1_021421f4
	bl sub_02034184
	mov r0, r4
	mov r1, #2
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213F418: .word s_system_000_overlay_1_021421f4
	arm_func_end ov1_0213F3D4

	arm_func_start ov1_0213F41C
ov1_0213F41C: ; 0x0213F41C
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x28
	mov r1, #0x1000
	mov r3, #6
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x120]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r0, [r4, #0x118]
	str r1, [r4, #0x11c]
	ldrh r0, [r4]
	str r1, [sp, #4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #6
	addls sp, sp, #8
	ldmlsia sp!, {r4, pc}
	mov r2, #0x1000
	mov r0, r4
	mov r1, #3
	str r2, [r4, #0x120]
	bl ov1_0213F960
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F41C

	arm_func_start ov1_0213F490
ov1_0213F490: ; 0x0213F490
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x28
	mov r1, #0x1000
	mov r3, #0xa
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x124]
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [sp]
	str r0, [r4, #0x118]
	str r1, [r4, #0x11c]
	ldrh r0, [r4]
	str r1, [sp, #4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0xa
	addlo sp, sp, #8
	ldmloia sp!, {r4, pc}
	mov r2, #0x1000
	mov r0, r4
	mov r1, #4
	str r2, [r4, #0x124]
	bl ov1_0213F960
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F490

	arm_func_start ov1_0213F504
ov1_0213F504: ; 0x0213F504
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x100000
	sub r1, r0, #0x160000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	ldr r2, [r4, #0xc]
	ldr r1, [r4, #8]
	str r2, [sp, #0xc]
	add r1, r1, r0
	str r1, [r4, #0x2c]
	str r2, [r4, #0x30]
	ldrh r0, [r4]
	str r1, [sp, #8]
	str r1, [sp]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	str r2, [sp, #4]
	cmp r0, #8
	addls sp, sp, #0x10
	ldmlsia sp!, {r4, pc}
	mov r0, r4
	mov r1, #5
	bl ov1_0213F960
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F504

	arm_func_start ov1_0213F578
ov1_0213F578: ; 0x0213F578
	stmdb sp!, {r3, lr}
	ldrh r1, [r0]
	add r1, r1, #1
	strh r1, [r0]
	ldrh r1, [r0]
	cmp r1, #0x30
	ldmlsia sp!, {r3, pc}
	mov r1, #6
	bl ov1_0213F960
	ldmia sp!, {r3, pc}
	arm_func_end ov1_0213F578

	arm_func_start ov1_0213F5A0
ov1_0213F5A0: ; 0x0213F5A0
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x3e]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0x20
	ldmlsia sp!, {r4, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0x3b
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, r4
	mov r1, #7
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F5A0

	arm_func_start ov1_0213F608
ov1_0213F608: ; 0x0213F608
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r2, [r4]
	cmp r2, #8
	bhi _0213F63C
	mov r0, #0x1f
	mov r1, #0
	mov r3, #8
	bl _Z17LinearInterpolatellll
	and r0, r0, #0xff
	str r0, [r4, #0xc4]
	mov r0, #0x1f
	str r0, [r4, #0x78]
	arm_func_end ov1_0213F608
_0213F63C:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008A38Et
	add r0, r4, #0x100
	ldrh r1, [r0, #0x54]
	ldr r0, [r4, #0x150]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	strh r0, [r4, #0x3e]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #8
	ldmloia sp!, {r4, pc}
	mov r0, r4
	mov r1, #8
	bl ov1_0213F960
	ldmia sp!, {r4, pc}

	arm_func_start ov1_0213F688
ov1_0213F688: ; 0x0213F688
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0x18
	ldmlsia sp!, {r4, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	mov r1, #1
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, r4
	mov r1, #9
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F688

	arm_func_start ov1_0213F6D0
ov1_0213F6D0: ; 0x0213F6D0
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x20
	mov r4, r0
	mov r0, #0x60000
	rsb r0, r0, #0
	ldrh r2, [r4]
	sub r1, r0, #0x120000
	mov r3, #8
	bl _Z17LinearInterpolatellll
	ldr lr, [r4, #0xc]
	ldr r2, [r4, #8]
	mov r1, #0x100000
	add ip, r2, r0
	str ip, [r4, #0x2c]
	str lr, [r4, #0x30]
	ldrh r2, [r4]
	mov r0, #0x3b000
	mov r3, #8
	str lr, [sp, #0x1c]
	str ip, [sp, #0x18]
	str ip, [sp, #0x10]
	str lr, [sp, #0x14]
	bl _Z17LinearInterpolatellll
	ldr r2, [r4, #8]
	ldr r1, [r4, #0xc]
	add r2, r2, r0
	add r1, r1, #0x5000
	str r2, [r4, #0x7c]
	str r1, [r4, #0x80]
	str r2, [r4, #0xc8]
	str r1, [r4, #0xcc]
	ldrh r0, [r4]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	str r2, [sp, #8]
	str r1, [sp, #0xc]
	str r2, [sp]
	str r1, [sp, #4]
	cmp r0, #8
	addls sp, sp, #0x20
	ldmlsia sp!, {r4, pc}
	mov r0, r4
	mov r1, #0xa
	bl ov1_0213F960
	add sp, sp, #0x20
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F6D0

	arm_func_start ov1_0213F794
ov1_0213F794: ; 0x0213F794
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x1000
	mov r1, #0x28
	mov r3, #0xa
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x124]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #0xa
	ldmlsia sp!, {r4, pc}
	mov r2, #0x28
	mov r0, r4
	mov r1, #0xb
	str r2, [r4, #0x124]
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F794

	arm_func_start ov1_0213F7E4
ov1_0213F7E4: ; 0x0213F7E4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r2, [r4]
	mov r0, #0x1000
	mov r1, #0x28
	mov r3, #6
	bl _Z17LinearInterpolatellll
	str r0, [r4, #0x120]
	ldrh r0, [r4]
	add r0, r0, #1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #6
	ldmlsia sp!, {r4, pc}
	mov r0, r4
	mov r1, #0
	bl ov1_0213F960
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213F7E4

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F82CEP8Camera2D
_ZN17UnkClass_0213F02812ov1_0213F82CEP8Camera2D: ; 0x0213F82C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r1
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r1, _0213F8B0 ; =0x00000406
	mov r0, r5
	bl _ZN17UnkClass_0213F02812ov1_0213F970Ei
	add r0, r5, #0x14
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x64
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0xb0
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	add r0, r5, #0x100
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0213F8B0: .word 0x00000406
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F82CEP8Camera2D

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F8B4Ev
_ZN17UnkClass_0213F02812ov1_0213F8B4Ev: ; 0x0213F8B4
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldrh r1, [r4, #2]
	cmp r1, #7
	addeq sp, sp, #8
	ldmeqia sp!, {r4, pc}
	mov r1, #1
	bl ov1_0213F960
	mov r0, #0x28
	str r0, [r4, #0x120]
	str r0, [r4, #0x124]
	ldr r1, [r4, #8]
	ldr r0, [r4, #0xc]
	mov ip, #0
	str r1, [r4, #0x118]
	str r0, [r4, #0x11c]
	strh ip, [r4, #0x8e]
	str ip, [r4, #0x78]
	ldr r2, [r4, #8]
	ldr r3, [r4, #0xc]
	add r2, r2, #0x3b000
	str r2, [r4, #0x7c]
	add r2, r3, #0x5000
	str r2, [r4, #0x80]
	mov r2, #1
	strh r2, [r4, #0xda]
	str ip, [r4, #0xc4]
	ldr r2, [r4, #8]
	ldr r3, [r4, #0xc]
	add r2, r2, #0x3b000
	str r2, [r4, #0xc8]
	add r2, r3, #0x5000
	str r2, [r4, #0xcc]
	ldr r2, [r4, #8]
	ldr r3, [r4, #0xc]
	add r2, r2, #0x100000
	str r2, [r4, #0x2c]
	str r1, [sp]
	str r0, [sp, #4]
	str r3, [r4, #0x30]
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F8B4Ev

	arm_func_start ov1_0213F960
ov1_0213F960: ; 0x0213F960
	mov r2, #0
	strh r2, [r0]
	str r1, [r0, #4]
	bx lr
	arm_func_end ov1_0213F960

	arm_func_start _ZN17UnkClass_0213F02812ov1_0213F970Ei
_ZN17UnkClass_0213F02812ov1_0213F970Ei: ; 0x0213F970
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	add r0, r5, #0x100
	mov r4, r1
	ldrh r1, [r0, #0x2a]
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r4, r4, r0
	str r4, [r5, #0x104]
	ldrh r1, [r5, #0x3e]
	add r0, r5, #0x14
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r4, r4, r0
	str r4, [r5, #0x18]
	ldrh r1, [r5, #0x8e]
	add r0, r5, #0x64
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r4, r4, r0
	str r4, [r5, #0x68]
	ldrh r1, [r5, #0xda]
	add r0, r5, #0xb0
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	add r0, r4, r0
	str r0, [r5, #0xb4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_0213F02812ov1_0213F970Ei

	arm_func_start _ZN17UnkClass_0213F9D0C1EPKcS1_
_ZN17UnkClass_0213F9D0C1EPKcS1_: ; 0x0213F9D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213F9F8
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F9D0C1EPKcS1_

	arm_func_start _ZN17UnkClass_0213F9D0D1Ev
_ZN17UnkClass_0213F9D0D1Ev: ; 0x0213F9E4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov1_0213FB4C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0213F9D0D1Ev

	arm_func_start ov1_0213F9F8
ov1_0213F9F8: ; 0x0213F9F8
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	mov r7, r0
	mov r0, #0xb8
	mov r5, r1
	mov r6, r2
	bl _Znwm
	movs r4, r0
	beq _0213FA3C
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r5
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	mov r4, r0
	arm_func_end ov1_0213F9F8
_0213FA3C:
	mov r0, #0xb8
	bl _Znwm
	movs r5, r0
	beq _0213FA6C
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r6
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	mov r5, r0
_0213FA6C:
	ldr r0, [r5, #0x50]
	mov r1, #0
	mov r0, r0, lsr #1
	bic r3, r0, #7
	ldr r0, [r4, #0x50]
	mov r2, r1
	add r6, r3, #8
	bl NNS_GfdAllocLnkTexVram
	mov r1, #0
	mov r6, r6, lsl #1
	str r0, [r7]
	mov r0, r6
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r7, #4]
	ldr r0, [r7]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0xd
	str r0, [r7, #8]
	ldr r0, [r7, #4]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0xd
	str r0, [r7, #0xc]
	ldr r0, [r5, #0x4c]
	ldr r1, [r5, #0x50]
	bl DC_FlushRange
	bl GX_BeginLoadTexPltt
	ldr r0, [r5, #0x4c]
	ldr r1, [r7, #0xc]
	mov r2, r6
	bl GX_LoadTexPltt
	bl GX_EndLoadTexPltt
	ldr r0, [r4, #0x4c]
	ldr r1, [r4, #0x50]
	bl DC_FlushRange
	bl GX_BeginLoadTex
	ldr r1, [r7, #8]
	ldr r0, [r4, #0x4c]
	ldr r2, [r4, #0x50]
	bl GX_LoadTex
	bl GX_EndLoadTex
	cmp r4, #0
	beq _0213FB28
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0213FB28:
	cmp r5, #0
	addeq sp, sp, #0xc
	ldmeqia sp!, {r4, r5, r6, r7, pc}
	mov r0, r5
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}

	arm_func_start ov1_0213FB4C
ov1_0213FB4C: ; 0x0213FB4C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl NNS_GfdFreeLnkTexVram
	ldr r0, [r4, #4]
	bl NNS_GfdFreeLnkPlttVram
	ldmia sp!, {r4, pc}
	arm_func_end ov1_0213FB4C

    .rodata

    .section .sinit,4 ; 0x02140734

    .data

    .global s_data_interface_i_03d_LZ_bin_overlay_1_021420e0
s_data_interface_i_03d_LZ_bin_overlay_1_021420e0: ; 0x021420E0
	.asciz "data/interface/i%03d_LZ.bin"

    .global s_BCO_i_03d_00_NCBR_overlay_1_021420fc
s_BCO_i_03d_00_NCBR_overlay_1_021420fc: ; 0x021420FC
	.asciz "BCO:i%03d_00.NCBR"

    .global DAT_overlay_1_0214210E
DAT_overlay_1_0214210E:
	.byte 0x00, 0x00

    .global s_BCO_i_03d_NCLR_overlay_1_02142110
s_BCO_i_03d_NCLR_overlay_1_02142110: ; 0x02142110
	.asciz "BCO:i%03d.NCLR"

    .global DAT_overlay_1_0214211F
DAT_overlay_1_0214211F:
	.byte 0x00

    .global s_BCO_i_03d_00_NCER_overlay_1_02142120
s_BCO_i_03d_00_NCER_overlay_1_02142120: ; 0x02142120
	.asciz "BCO:i%03d_00.NCER"

    .global DAT_overlay_1_02142132
DAT_overlay_1_02142132:
	.byte 0x00, 0x00

    .global s_BCO_i_03d_00_cac_overlay_1_02142134
s_BCO_i_03d_00_cac_overlay_1_02142134: ; 0x02142134
	.asciz "BCO:i%03d_00.cac"

    .global DAT_overlay_1_02142145
DAT_overlay_1_02142145:
	.byte 0x00, 0x00, 0x00

    .global s_BCO_overlay_1_02142148
s_BCO_overlay_1_02142148: ; 0x02142148
	.asciz "BCO"

    .global s_data_interface_i055_LZ_bin_overlay_1_0214214c
s_data_interface_i055_LZ_bin_overlay_1_0214214c: ; 0x0214214C
	.asciz "data/interface/i055_LZ.bin"

    .global DAT_overlay_1_02142167
DAT_overlay_1_02142167:
	.byte 0x00

    .global s_BCO_i055_00_NCBR_overlay_1_02142168
s_BCO_i055_00_NCBR_overlay_1_02142168: ; 0x02142168
	.asciz "BCO:i055_00.NCBR"

    .global DAT_overlay_1_02142179
DAT_overlay_1_02142179:
	.byte 0x00, 0x00, 0x00

    .global s_BCO_i055_NCLR_overlay_1_0214217c
s_BCO_i055_NCLR_overlay_1_0214217c: ; 0x0214217C
	.asciz "BCO:i055.NCLR"

    .global DAT_overlay_1_0214218A
DAT_overlay_1_0214218A:
	.byte 0x00, 0x00

    .global s_BCO_i055_00_NCER_overlay_1_0214218c
s_BCO_i055_00_NCER_overlay_1_0214218c: ; 0x0214218C
	.asciz "BCO:i055_00.NCER"

    .global DAT_overlay_1_0214219D
DAT_overlay_1_0214219D:
	.byte 0x00, 0x00, 0x00

    .global s_data_interface_i056_LZ_bin_overlay_1_021421a0
s_data_interface_i056_LZ_bin_overlay_1_021421a0: ; 0x021421A0
	.asciz "data/interface/i056_LZ.bin"

    .global DAT_overlay_1_021421BB
DAT_overlay_1_021421BB:
	.byte 0x00

    .global s_BCO_i056_00_NCBR_overlay_1_021421bc
s_BCO_i056_00_NCBR_overlay_1_021421bc: ; 0x021421BC
	.asciz "BCO:i056_00.NCBR"

    .global DAT_overlay_1_021421CD
DAT_overlay_1_021421CD:
	.byte 0x00, 0x00, 0x00

    .global s_BCO_i056_NCLR_overlay_1_021421d0
s_BCO_i056_NCLR_overlay_1_021421d0: ; 0x021421D0
	.asciz "BCO:i056.NCLR"

    .global DAT_overlay_1_021421DE
DAT_overlay_1_021421DE:
	.byte 0x00, 0x00

    .global s_BCO_i056_00_NCER_overlay_1_021421e0
s_BCO_i056_00_NCER_overlay_1_021421e0: ; 0x021421E0
	.asciz "BCO:i056_00.NCER"

    .global DAT_overlay_1_021421F1
DAT_overlay_1_021421F1:
	.byte 0x00, 0x00, 0x00

    .global s_system_000_overlay_1_021421f4
s_system_000_overlay_1_021421f4: ; 0x021421F4
	.asciz "system_000"
	; 0x021421FF

    .bss

	.global OVERLAY1_BSS_02142204
OVERLAY1_BSS_02142204: ; 0x02142204
    .space 0x1C
