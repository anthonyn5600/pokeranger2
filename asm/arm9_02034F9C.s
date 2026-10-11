    .include "macros.inc"
    .include "include/arm9_02034F9C.inc"

    .text

	arm_func_start sub_02034F9C
sub_02034F9C: ; 0x02034F9C
	cmp r0, #0xb7
	bgt _02035020
	bge _02035078
	cmp r0, #0x63
	bgt _02034FD0
	bge _02035078
	cmp r0, #0x1f
	bgt _02034FC4
	beq _02035078
	b _02035080
	arm_func_end sub_02034F9C
_02034FC4:
	cmp r0, #0x5c
	beq _02035078
	b _02035080
_02034FD0:
	cmp r0, #0xaf
	bgt _02035014
	bge _02035078
	sub r1, r0, #0xa1
	cmp r1, #9
	addls pc, pc, r1, lsl #2
	b _02035080
_02034FEC: ; jump table
	b _02035078 ; case 0
	b _02035080 ; case 1
	b _02035080 ; case 2
	b _02035078 ; case 3
	b _02035080 ; case 4
	b _02035080 ; case 5
	b _02035078 ; case 6
	b _02035080 ; case 7
	b _02035080 ; case 8
	b _02035078 ; case 9
_02035014:
	cmp r0, #0xb6
	beq _02035078
	b _02035080
_02035020:
	cmp r0, #0xd5
	bgt _02035048
	bge _02035078
	cmp r0, #0xbc
	bgt _0203503C
	beq _02035078
	b _02035080
_0203503C:
	cmp r0, #0xd2
	beq _02035078
	b _02035080
_02035048:
	cmp r0, #0xdc
	bgt _02035070
	cmp r0, #0xd9
	blt _02035064
	cmpne r0, #0xdc
	beq _02035078
	b _02035080
_02035064:
	cmp r0, #0xd7
	beq _02035078
	b _02035080
_02035070:
	cmp r0, #0xe2
	bne _02035080
_02035078:
	mov r0, #1
	bx lr
_02035080:
	mov r0, #0
	bx lr

	arm_func_start sub_02035088
sub_02035088: ; 0x02035088
	stmdb sp!, {r3, lr}
	mov r1, r0
	cmp r1, #0xbc
	bgt _02035120
	bge _020351C0
	cmp r1, #0xaa
	bgt _020350FC
	subs r0, r1, #0xa1
	addpl pc, pc, r0, lsl #2
	b _020350D8
_020350B0: ; jump table
	b _020351B8 ; case 0
	b _02035228 ; case 1
	b _02035228 ; case 2
	b _020351A8 ; case 3
	b _02035228 ; case 4
	b _02035228 ; case 5
	b _020351B0 ; case 6
	b _02035228 ; case 7
	b _02035228 ; case 8
	b _020351E8 ; case 9
	arm_func_end sub_02035088
_020350D8:
	cmp r1, #0x5c
	bgt _020350F0
	bge _02035208
	cmp r1, #0x1f
	beq _020351D0
	b _02035228
_020350F0:
	cmp r1, #0x63
	beq _02035218
	b _02035228
_020350FC:
	cmp r1, #0xb6
	bgt _02035114
	bge _02035200
	cmp r1, #0xaf
	beq _020351F8
	b _02035228
_02035114:
	cmp r1, #0xb7
	beq _02035220
	b _02035228
_02035120:
	cmp r1, #0xdc
	bgt _02035164
	cmp r1, #0xd9
	blt _02035140
	beq _020351E0
	cmp r1, #0xdc
	beq _020351D8
	b _02035228
_02035140:
	cmp r1, #0xd5
	bgt _02035158
	bge _02035210
	cmp r1, #0xd2
	beq _020351F0
	b _02035228
_02035158:
	cmp r1, #0xd7
	beq _020351A0
	b _02035228
_02035164:
	ldr r2, _02035238 ; =0x00000101
	cmp r1, r2
	bgt _02035180
	bge _020351E8
	cmp r1, #0xe2
	beq _020351C8
	b _02035228
_02035180:
	add r0, r2, #1
	cmp r1, r0
	bgt _02035194
	beq _020351C0
	b _02035228
_02035194:
	add r0, r2, #2
	cmp r1, r0
	bne _02035228
_020351A0:
	mov r0, #0
	ldmia sp!, {r3, pc}
_020351A8:
	mov r0, #1
	ldmia sp!, {r3, pc}
_020351B0:
	mov r0, #2
	ldmia sp!, {r3, pc}
_020351B8:
	mov r0, #3
	ldmia sp!, {r3, pc}
_020351C0:
	mov r0, #4
	ldmia sp!, {r3, pc}
_020351C8:
	mov r0, #5
	ldmia sp!, {r3, pc}
_020351D0:
	mov r0, #6
	ldmia sp!, {r3, pc}
_020351D8:
	mov r0, #7
	ldmia sp!, {r3, pc}
_020351E0:
	mov r0, #8
	ldmia sp!, {r3, pc}
_020351E8:
	mov r0, #9
	ldmia sp!, {r3, pc}
_020351F0:
	mov r0, #0xa
	ldmia sp!, {r3, pc}
_020351F8:
	mov r0, #0xb
	ldmia sp!, {r3, pc}
_02035200:
	mov r0, #0xc
	ldmia sp!, {r3, pc}
_02035208:
	mov r0, #0xd
	ldmia sp!, {r3, pc}
_02035210:
	mov r0, #0xe
	ldmia sp!, {r3, pc}
_02035218:
	mov r0, #0xf
	ldmia sp!, {r3, pc}
_02035220:
	mov r0, #0x10
	ldmia sp!, {r3, pc}
_02035228:
	ldr r0, _0203523C ; =s_GetEnemyLabel2PartnerIndex_index_0208d590
	bl LogError
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02035238: .word 0x00000101
_0203523C: .word s_GetEnemyLabel2PartnerIndex_index_0208d590

	arm_func_start sub_02035240
sub_02035240: ; 0x02035240
	stmdb sp!, {r3, lr}
	mov r1, r0
	cmp r1, #0x10
	addls pc, pc, r1, lsl #2
	b _02035320
_02035254: ; jump table
	b _02035298 ; case 0
	b _020352A0 ; case 1
	b _020352A8 ; case 2
	b _020352B0 ; case 3
	b _020352B8 ; case 4
	b _020352C0 ; case 5
	b _020352C8 ; case 6
	b _020352D0 ; case 7
	b _020352D8 ; case 8
	b _020352E0 ; case 9
	b _020352E8 ; case 10
	b _020352F0 ; case 11
	b _020352F8 ; case 12
	b _02035300 ; case 13
	b _02035308 ; case 14
	b _02035310 ; case 15
	b _02035318 ; case 16
	arm_func_end sub_02035240
_02035298:
	mov r0, #0xd7
	ldmia sp!, {r3, pc}
_020352A0:
	mov r0, #0xa4
	ldmia sp!, {r3, pc}
_020352A8:
	mov r0, #0xa7
	ldmia sp!, {r3, pc}
_020352B0:
	mov r0, #0xa1
	ldmia sp!, {r3, pc}
_020352B8:
	mov r0, #0xbc
	ldmia sp!, {r3, pc}
_020352C0:
	mov r0, #0xe2
	ldmia sp!, {r3, pc}
_020352C8:
	mov r0, #0x1f
	ldmia sp!, {r3, pc}
_020352D0:
	mov r0, #0xdc
	ldmia sp!, {r3, pc}
_020352D8:
	mov r0, #0xd9
	ldmia sp!, {r3, pc}
_020352E0:
	mov r0, #0xaa
	ldmia sp!, {r3, pc}
_020352E8:
	mov r0, #0xd2
	ldmia sp!, {r3, pc}
_020352F0:
	mov r0, #0xaf
	ldmia sp!, {r3, pc}
_020352F8:
	mov r0, #0xb6
	ldmia sp!, {r3, pc}
_02035300:
	mov r0, #0x5c
	ldmia sp!, {r3, pc}
_02035308:
	mov r0, #0xd5
	ldmia sp!, {r3, pc}
_02035310:
	mov r0, #0x63
	ldmia sp!, {r3, pc}
_02035318:
	mov r0, #0xb7
	ldmia sp!, {r3, pc}
_02035320:
	ldr r0, _02035330 ; =s_GetPartnerIndex2EnemyLabel_index_0208d5b8
	bl LogError
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02035330: .word s_GetPartnerIndex2EnemyLabel_index_0208d5b8

	arm_func_start sub_02035334
sub_02035334: ; 0x02035334
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #4]
	cmp r0, #7
	addls pc, pc, r0, lsl #2
	b _02035478
_0203534C: ; jump table
	b _02035478 ; case 0
	b _02035478 ; case 1
	b _0203536C ; case 2
	b _020353C8 ; case 3
	b _020353FC ; case 4
	b _0203543C ; case 5
	b _02035470 ; case 6
	b _02035478 ; case 7
	arm_func_end sub_02035334
_0203536C:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	movgt r0, #3
	strgt r0, [r4, #4]
	bgt _020353C8
	mov r0, #4
	str r0, [r4, #4]
	ldr r0, [r4, #0x10]
	cmp r0, #0
	ble _02035478
	ldr r0, _020354DC ; =MAIN_BSS_0210CA84
	ldr r1, [r4, #8]
	ldr r0, [r0]
	add r1, r1, r0
	str r1, [r4, #8]
	ldr r0, [r4, #0x10]
	cmp r1, r0
	blt _02035478
	mov r0, #0
	str r0, [r4, #8]
	mov r0, #5
	str r0, [r4, #4]
	b _02035478
_020353C8:
	ldr r0, _020354DC ; =MAIN_BSS_0210CA84
	ldr r1, [r4, #8]
	ldr r0, [r0]
	add r1, r1, r0
	str r1, [r4, #8]
	ldr r0, [r4, #0xc]
	cmp r1, r0
	blt _02035478
	mov r0, #0
	str r0, [r4, #8]
	mov r0, #4
	str r0, [r4, #4]
	b _02035478
_020353FC:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	ble _02035478
	ldr r0, _020354DC ; =MAIN_BSS_0210CA84
	ldr r1, [r4, #8]
	ldr r0, [r0]
	add r1, r1, r0
	str r1, [r4, #8]
	ldr r0, [r4, #0x10]
	cmp r1, r0
	blt _02035478
	mov r0, #0
	str r0, [r4, #8]
	mov r0, #5
	str r0, [r4, #4]
	b _02035478
_0203543C:
	ldr r0, _020354DC ; =MAIN_BSS_0210CA84
	ldr r1, [r4, #8]
	ldr r0, [r0]
	add r1, r1, r0
	str r1, [r4, #8]
	ldr r0, [r4, #0x14]
	cmp r1, r0
	blt _02035478
	mov r0, #0
	str r0, [r4, #8]
	mov r0, #6
	str r0, [r4, #4]
	b _02035478
_02035470:
	mov r0, #7
	str r0, [r4, #4]
_02035478:
	ldr r0, [r4, #4]
	cmp r0, #4
	moveq r0, #0x1000
	streq r0, [r4, #0x18]
	beq _020354D4
	cmp r0, #3
	bne _020354AC
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	str r0, [r4, #0x18]
	b _020354D4
_020354AC:
	cmp r0, #5
	movne r0, #0
	strne r0, [r4, #0x18]
	bne _020354D4
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #8]
	sub r0, r1, r0
	mov r0, r0, lsl #0xc
	bl _s32_div_f
	str r0, [r4, #0x18]
_020354D4:
	ldr r0, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020354DC: .word MAIN_BSS_0210CA84

	arm_func_start sub_020354E0
sub_020354E0: ; 0x020354E0
	str r1, [r0, #0xc]
	str r2, [r0, #0x10]
	str r3, [r0, #0x14]
	ldr r2, [r0, #4]
	cmp r2, #3
	moveq r0, #1
	bxeq lr
	cmp r2, #4
	bne _02035514
	mov r1, #0
	str r1, [r0, #8]
	mov r0, #1
	bx lr
	arm_func_end sub_020354E0
_02035514:
	cmp r2, #5
	bne _0203555C
	cmp r1, #0
	ble _02035544
	mov r2, #3
	str r2, [r0, #4]
	str r1, [r0, #0xc]
	ldr r2, [r0, #0x18]
	mul r2, r1, r2
	mov r1, r2, asr #0xc
	str r1, [r0, #8]
	b _02035554
_02035544:
	mov r1, #4
	str r1, [r0, #4]
	mov r1, #0x1000
	str r1, [r0, #0x18]
_02035554:
	mov r0, #1
	bx lr
_0203555C:
	cmp r1, #0
	movle r1, #4
	strle r1, [r0, #4]
	movle r1, #0x1000
	ble _0203557C
	mov r1, #2
	str r1, [r0, #4]
	mov r1, #0
_0203557C:
	str r1, [r0, #0x18]
	mov r1, #0
	str r1, [r0, #8]
	mov r0, #1
	bx lr

	arm_func_start sub_02035590
sub_02035590: ; 0x02035590
	cmp r1, #0
	movgt r2, #5
	movle r2, #7
	str r2, [r0, #4]
	mov r2, #0
	str r2, [r0, #8]
	str r1, [r0, #0x14]
	mov r0, #1
	bx lr
	arm_func_end sub_02035590

	arm_func_start sub_020355B4
sub_020355B4: ; 0x020355B4
	ldr r2, _020355F4 ; =0x04000450
	mov r3, #0
	str r3, [r2]
	str r3, [r2, #4]
	mov r0, #0x80000
	str r0, [r2, #0x20]
	mov r0, #0x60000
	str r0, [r2, #0x20]
	str r3, [r2, #0x20]
	ldrh r0, [r1, #0x26]
	mov r1, #1
	mov r0, r1, lsl r0
	str r0, [r2, #0x1c]
	str r0, [r2, #0x1c]
	str r0, [r2, #0x1c]
	bx lr
	.align 2, 0
_020355F4: .word 0x04000450
	arm_func_end sub_020355B4

	arm_func_start sub_020355F8
sub_020355F8: ; 0x020355F8
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r1, [r0, #0x4b8]
	ldr r0, _0203565C ; =MAIN_BSS_0210CA84
	ldr r1, [r1]
	str r1, [r0, #4]
	cmp r1, #0
	beq _02035640
	ldr r2, [r1, #0x1c]
	ldr r1, [r1, #0x20]
	str r2, [sp]
	str r2, [r0, #0x10]
	str r1, [sp, #4]
	str r1, [r0, #0x14]
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	arm_func_end sub_020355F8
_02035640:
	mov r1, #0
	str r1, [r0, #0x10]
	str r1, [r0, #0x14]
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203565C: .word MAIN_BSS_0210CA84

	arm_func_start sub_02035660
sub_02035660: ; 0x02035660
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x20
	ldr r0, _0203571C ; =MAIN_BSS_0210CA84
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _020356B0
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r1, [r0, #0x4b8]
	ldr r0, _0203571C ; =MAIN_BSS_0210CA84
	ldr r1, [r1]
	str r1, [r0, #4]
	cmp r1, #0
	beq _020356B0
	ldr r2, [r1, #0x1c]
	ldr r1, [r1, #0x20]
	str r2, [sp, #0x18]
	str r2, [r0, #0x10]
	str r1, [sp, #0x1c]
	str r1, [r0, #0x14]
	arm_func_end sub_02035660
_020356B0:
	ldr r0, _0203571C ; =MAIN_BSS_0210CA84
	ldr r4, [r0, #4]
	cmp r4, #0
	addeq sp, sp, #0x20
	ldmeqia sp!, {r4, pc}
	ldr r1, [r4, #0x1c]
	ldr lr, [r4, #0x20]
	str r1, [sp, #0x10]
	str r1, [r0, #0x18]
	str lr, [r0, #0x1c]
	ldr ip, [r0, #0x10]
	ldr r3, [r0, #0x14]
	sub r1, r1, ip
	str r1, [r0, #0x18]
	sub r1, lr, r3
	str r1, [r0, #0x1c]
	ldr r2, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str lr, [sp, #0x14]
	str r2, [r0, #0x10]
	str ip, [sp]
	str r3, [sp, #4]
	str r2, [sp, #8]
	str r1, [sp, #0xc]
	str r1, [r0, #0x14]
	add sp, sp, #0x20
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203571C: .word MAIN_BSS_0210CA84

	arm_func_start sub_02035720
sub_02035720: ; 0x02035720
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	mov r5, r0
	bl sub_02035774
	str r4, [r5]
	mov r0, r4, lsl #2
	bl _Znam
	str r0, [r5, #4]
	ldr r0, [r5]
	mov r2, #0
	cmp r0, #0
	ble _0203576C
	mov r1, r2
	arm_func_end sub_02035720
_02035754:
	ldr r0, [r5, #4]
	str r1, [r0, r2, lsl #2]
	ldr r0, [r5]
	add r2, r2, #1
	cmp r2, r0
	blt _02035754
_0203576C:
	bl sub_020355F8
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02035774
sub_02035774: ; 0x02035774
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _020357EC
	ldr r0, [r5]
	mov r4, #0
	cmp r0, #0
	ble _020357D4
	mov r6, r4
	arm_func_end sub_02035774
_0203579C:
	ldr r0, [r5, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _020357C4
	beq _020357BC
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020357BC:
	ldr r0, [r5, #4]
	str r6, [r0, r4, lsl #2]
_020357C4:
	ldr r0, [r5]
	add r4, r4, #1
	cmp r4, r0
	blt _0203579C
_020357D4:
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _020357EC
	bl _ZdaPv
	mov r0, #0
	str r0, [r5, #4]
_020357EC:
	mov r0, #0
	str r0, [r5]
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_020357F8
sub_020357F8: ; 0x020357F8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020357F8

	arm_func_start sub_0203580C
sub_0203580C: ; 0x0203580C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r1
	mov r6, r0
	bl sub_02035660
	mov r1, r5
	mov r0, #0x3c
	bl _s32_div_f
	ldr r1, _020358A8 ; =MAIN_BSS_0210CA84
	mov r4, #0
	str r0, [r1]
	ldr r0, [r6]
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r7, r4
	arm_func_end sub_0203580C
_02035844:
	ldr r0, [r6, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _02035894
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #0xc]
	blx r2
	cmp r0, #7
	bne _02035894
	ldr r0, [r6, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _02035894
	beq _0203588C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203588C:
	ldr r0, [r6, #4]
	str r7, [r0, r4, lsl #2]
_02035894:
	ldr r0, [r6]
	add r4, r4, #1
	cmp r4, r0
	blt _02035844
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_020358A8: .word MAIN_BSS_0210CA84

	arm_func_start sub_020358AC
sub_020358AC: ; 0x020358AC
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldr r0, [r6]
	mov r5, r1
	mov r4, #0
	cmp r0, #0
	ldmleia sp!, {r4, r5, r6, pc}
	arm_func_end sub_020358AC
_020358C8:
	ldr r0, [r6, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _020358E8
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #0x10]
	blx r2
_020358E8:
	ldr r0, [r6]
	add r4, r4, #1
	cmp r4, r0
	blt _020358C8
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_020358FC
sub_020358FC: ; 0x020358FC
	bx lr
	arm_func_end sub_020358FC

	arm_func_start sub_02035900
sub_02035900: ; 0x02035900
	ldr r3, [r0, #4]
	cmp r3, #0
	beq _02035938
	ldr ip, [r0]
	mov r0, #1
	cmp ip, #1
	ble _02035938
	arm_func_end sub_02035900
_0203591C:
	ldr r2, [r3, r0, lsl #2]
	cmp r2, #0
	streq r1, [r3, r0, lsl #2]
	bxeq lr
	add r0, r0, #1
	cmp r0, ip
	blt _0203591C
_02035938:
	mvn r0, #0
	bx lr

	arm_func_start sub_02035940
sub_02035940: ; 0x02035940
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r1
	cmp r0, #0
	beq _02035990
	ldr r0, [r0]
	cmp r0, #0
	beq _02035980
	beq _02035974
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02035940
_02035974:
	ldr r0, [r5, #4]
	mov r1, #0
	str r1, [r0]
_02035980:
	ldr r1, [r5, #4]
	mov r0, #0
	str r4, [r1]
	ldmia sp!, {r3, r4, r5, pc}
_02035990:
	mvn r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02035998
sub_02035998: ; 0x02035998
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r5]
	mov r4, #1
	cmp r0, #1
	ldmleia sp!, {r4, r5, r6, pc}
	mov r6, #0
	arm_func_end sub_02035998
_020359C0:
	ldr r0, [r5, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _020359E8
	beq _020359E0
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020359E0:
	ldr r0, [r5, #4]
	str r6, [r0, r4, lsl #2]
_020359E8:
	ldr r0, [r5]
	add r4, r4, #1
	cmp r4, r0
	blt _020359C0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_020359FC
sub_020359FC: ; 0x020359FC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #4]
	cmp r0, #0
	ldrne r0, [r0]
	cmpne r0, #0
	ldmeqia sp!, {r4, pc}
	beq _02035A28
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_020359FC
_02035A28:
	ldr r0, [r4, #4]
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02035A38
sub_02035A38: ; 0x02035A38
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r1
	cmp r4, #0
	ble _02035C48
	cmp r4, #0x10
	addls pc, pc, r4, lsl #2
	b _02035C48
_02035A58: ; jump table
	b _02035C48 ; case 0
	b _02035A9C ; case 1
	b _02035AC0 ; case 2
	b _02035B18 ; case 3
	b _02035B38 ; case 4
	b _02035B38 ; case 5
	b _02035B38 ; case 6
	b _02035B38 ; case 7
	b _02035B5C ; case 8
	b _02035B7C ; case 9
	b _02035B9C ; case 10
	b _02035C24 ; case 11
	b _02035BC0 ; case 12
	b _02035BE4 ; case 13
	b _02035C04 ; case 14
	b _02035C24 ; case 15
	b _02035B38 ; case 16
	arm_func_end sub_02035A38
_02035A9C:
	ldr r0, _02035C54 ; =0x00000428
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r1, #1
	bl sub_02038D04
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035AC0:
	ldr r0, _02035C58 ; =0x00000678
	bl _Znwm
	movs r4, r0
	beq _02035B0C
	ldr r0, _02035C5C ; =PTR_LAB_0208d610
	mov r1, #4
	str r0, [r4]
	ldr r0, _02035C60 ; =ptr_FUN_0203a734_0208db24
	str r1, [r4, #0x1c]
	ldr ip, _02035C64 ; =sub_02035C8C
	str r0, [r4]
	ldr r3, _02035C68 ; =sub_02035C74
	add r0, r4, #0x20
	mov r1, #0x20
	mov r2, #0x2c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r0, r4
	bl sub_02039E20
_02035B0C:
	add sp, sp, #4
	mov r0, r4
	ldmia sp!, {r3, r4, pc}
_02035B18:
	mov r0, #0x110
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl sub_02036930
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035B38:
	mov r0, #0xb4
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r1, r4
	bl sub_02037388
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035B5C:
	mov r0, #0xd4
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl sub_020379C8
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035B7C:
	ldr r0, _02035C6C ; =0x0000066C
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl sub_02038018
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035B9C:
	mov r0, #0x80
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r1, r4
	bl sub_020389E8
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035BC0:
	ldr r0, _02035C54 ; =0x00000428
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r1, #0
	bl sub_02038D04
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035BE4:
	mov r0, #0x88
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl sub_0203A76C
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035C04:
	ldr r0, _02035C70 ; =0x0000059C
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl sub_0203AA44
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035C24:
	ldr r0, _02035C6C ; =0x0000066C
	bl _Znwm
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r1, r4
	bl sub_0203B34C
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_02035C48:
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02035C54: .word 0x00000428
_02035C58: .word 0x00000678
_02035C5C: .word PTR_LAB_0208d610
_02035C60: .word ptr_FUN_0203a734_0208db24
_02035C64: .word sub_02035C8C
_02035C68: .word sub_02035C74
_02035C6C: .word 0x0000066C
_02035C70: .word 0x0000059C

	arm_func_start sub_02035C74
sub_02035C74: ; 0x02035C74
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #4
	bl _ZN14CPrimitiveLINEC1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02035C74

	arm_func_start sub_02035C8C
sub_02035C8C: ; 0x02035C8C
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #4
	bl _ZN14CPrimitiveLINED1Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02035C8C

	arm_func_start sub_02035CA4
sub_02035CA4: ; 0x02035CA4
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r1
	mov r5, r0
	cmp r4, #0
	ble _02035D28
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _02035D28
	ldr r0, [r5]
	mov r6, #0
	cmp r0, #0
	ble _02035D0C
	arm_func_end sub_02035CA4
_02035CD4:
	ldr r0, [r5, #4]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	beq _02035CFC
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r4, r0
	moveq r0, r6
	ldmeqia sp!, {r4, r5, r6, pc}
_02035CFC:
	ldr r0, [r5]
	add r6, r6, #1
	cmp r6, r0
	blt _02035CD4
_02035D0C:
	mov r0, r5
	mov r1, r4
	bl sub_02035A38
	mov r1, r0
	mov r0, r5
	bl sub_02035900
	ldmia sp!, {r4, r5, r6, pc}
_02035D28:
	mvn r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_02035D30
sub_02035D30: ; 0x02035D30
	mov r0, #0
	bx lr
	arm_func_end sub_02035D30

	arm_func_start sub_02035D38
sub_02035D38: ; 0x02035D38
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	mov r5, r0
	cmp r4, #0
	ble _02035D98
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _02035D98
	ldr r0, [r0]
	cmp r0, #0
	beq _02035D7C
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r4, r0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	arm_func_end sub_02035D38
_02035D7C:
	mov r0, r5
	mov r1, r4
	bl sub_02035A38
	mov r1, r0
	mov r0, r5
	bl sub_02035940
	ldmia sp!, {r3, r4, r5, pc}
_02035D98:
	mvn r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02035DA0
sub_02035DA0: ; 0x02035DA0
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r7, r1
	mov r8, r0
	mov r6, r2
	mov r5, r3
	cmp r7, #0
	ble _02035E34
	ldr r0, [r8, #4]
	cmp r0, #0
	beq _02035E34
	ldr r0, [r8]
	mov r4, #0
	cmp r0, #0
	ble _02035E34
	arm_func_end sub_02035DA0
_02035DD8:
	ldr r0, [r8, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _02035E24
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r7, r0
	bne _02035E24
	ldr r0, [r8, #4]
	ldr r3, [sp, #0x18]
	ldr r0, [r0, r4, lsl #2]
	mov r1, r6
	ldr r4, [r0]
	mov r2, r5
	ldr r4, [r4, #0x14]
	blx r4
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
_02035E24:
	ldr r0, [r8]
	add r4, r4, #1
	cmp r4, r0
	blt _02035DD8
_02035E34:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start sub_02035E3C
sub_02035E3C: ; 0x02035E3C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, r1
	mov r7, r0
	mov r5, r2
	cmp r6, #0
	ble _02035EC4
	ldr r0, [r7, #4]
	cmp r0, #0
	beq _02035EC4
	ldr r0, [r7]
	mov r4, #0
	cmp r0, #0
	ble _02035EC4
	arm_func_end sub_02035E3C
_02035E70:
	ldr r0, [r7, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _02035EB4
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r6, r0
	bne _02035EB4
	ldr r0, [r7, #4]
	mov r1, r5
	ldr r0, [r0, r4, lsl #2]
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_02035EB4:
	ldr r0, [r7]
	add r4, r4, #1
	cmp r4, r0
	blt _02035E70
_02035EC4:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02035ECC
sub_02035ECC: ; 0x02035ECC
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r1
	mov r6, r0
	cmp r5, #0
	ble _02035F48
	ldr r0, [r6, #4]
	cmp r0, #0
	beq _02035F48
	ldr r0, [r6]
	mov r4, #0
	cmp r0, #0
	ble _02035F48
	arm_func_end sub_02035ECC
_02035EFC:
	ldr r0, [r6, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _02035F38
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r5, r0
	bne _02035F38
	ldr r0, [r6, #4]
	ldr r0, [r0, r4, lsl #2]
	ldr r0, [r0, #4]
	cmp r0, #7
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
_02035F38:
	ldr r0, [r6]
	add r4, r4, #1
	cmp r4, r0
	blt _02035EFC
_02035F48:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_02035F50
sub_02035F50: ; 0x02035F50
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, r1
	mov r7, r0
	cmp r6, #3
	mov r5, r2
	movne r0, #0
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
	cmp r6, #0
	ble _02035FDC
	ldr r0, [r7, #4]
	cmp r0, #0
	beq _02035FDC
	ldr r0, [r7]
	mov r4, #0
	cmp r0, #0
	ble _02035FDC
	arm_func_end sub_02035F50
_02035F90:
	ldr r0, [r7, #4]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _02035FCC
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r6, r0
	bne _02035FCC
	ldr r0, [r7, #4]
	mov r1, r5
	ldr r0, [r0, r4, lsl #2]
	bl sub_02037330
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_02035FCC:
	ldr r0, [r7]
	add r4, r4, #1
	cmp r4, r0
	blt _02035F90
_02035FDC:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02035FE4
sub_02035FE4: ; 0x02035FE4
	bx lr
	arm_func_end sub_02035FE4

	arm_func_start sub_02035FE8
sub_02035FE8: ; 0x02035FE8
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0xdc
	mov r5, r1
	mov r4, r0
	ldr r1, _0203614C ; =s_data_Field_Effect_ew_03d_LZ_bin_0208d73c
	add r0, sp, #0x7c
	mov r2, r5
	bl OS_SPrintf
	mov r3, #1
	str r3, [sp]
	mov ip, #0
	str ip, [sp, #4]
	str ip, [sp, #8]
	ldr r1, _02036150 ; =DAT_0208d75c
	add r0, sp, #0x10
	add r2, sp, #0x7c
	str ip, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	ldr r1, _02036154 ; =s_MEF_ew_03d_NCLR_0208d760
	add r0, sp, #0x7c
	mov r2, r5
	bl OS_SPrintf
	mov r2, #0
	add r0, r4, #4
	add r1, sp, #0x7c
	mov r3, r2
	bl sub_02007B60
	mov r0, #1
	ldr r3, _02036158 ; =sub_0203616C
	str r0, [r4, #0x30]
	mov r2, #0
	mov r1, #0x10
	str r2, [sp]
	bl __cxa_vec_new
	str r0, [r4, #0x2c]
	ldr r1, _0203615C ; =s_MEF_ew_03d_NCBR_0208d770
	add r0, sp, #0x7c
	mov r2, r5
	bl OS_SPrintf
	mov r0, #0x3c
	bl _Znwm
	cmp r0, #0
	beq _020360A8
	mov r2, #0
	add r1, sp, #0x7c
	mov r3, r2
	str r2, [sp]
	bl _ZN17UnkClass_020074D4C1EPKcmmm
	arm_func_end sub_02035FE8
_020360A8:
	ldr r2, [r4, #0x2c]
	ldr r1, _02036160 ; =s_MEF_ew_03d_NCER_0208d780
	str r0, [r2]
	add r0, sp, #0x7c
	mov r2, r5
	bl OS_SPrintf
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _020360E4
	mov r2, #0
	add r1, sp, #0x7c
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNCERFileC1EPKcmmm
_020360E4:
	ldr r2, [r4, #0x2c]
	ldr r1, _02036164 ; =s_MEF_ew_03d_cac_0208d790
	str r0, [r2, #4]
	add r0, sp, #0x7c
	mov r2, r5
	bl OS_SPrintf
	mov r0, #0x10
	bl _Znwm
	cmp r0, #0
	beq _02036114
	add r1, sp, #0x7c
	bl _ZN17UnkClass_02008788C1EPKc
_02036114:
	ldr r2, [r4, #0x2c]
	ldr r1, _02036168 ; =0x04000210
	str r0, [r2, #8]
	ldr r0, [r1]
	tst r0, #1
	moveq r1, #1
	movne r1, #0
	mov r0, r4
	bl sub_020295B0
	add r0, sp, #0x10
	bl _ZN13CArchiveGuardD1Ev
	mov r0, #1
	add sp, sp, #0xdc
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_0203614C: .word s_data_Field_Effect_ew_03d_LZ_bin_0208d73c
_02036150: .word DAT_0208d75c
_02036154: .word s_MEF_ew_03d_NCLR_0208d760
_02036158: .word sub_0203616C
_0203615C: .word s_MEF_ew_03d_NCBR_0208d770
_02036160: .word s_MEF_ew_03d_NCER_0208d780
_02036164: .word s_MEF_ew_03d_cac_0208d790
_02036168: .word 0x04000210

	arm_func_start sub_0203616C
sub_0203616C: ; 0x0203616C
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	bx lr
	arm_func_end sub_0203616C

	arm_func_start sub_02036184
sub_02036184: ; 0x02036184
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	ldr r5, _020362E8 ; =DAT_0208d694
	mov r4, #0x1c
	mla r4, r3, r4, r5
	mov r7, r0
	mov r0, #0xb8
	mov r5, r1
	mov r6, r2
	str r4, [r7, #0x10]
	bl _Znwm
	movs r4, r0
	beq _020361D8
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r5
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	mov r4, r0
	arm_func_end sub_02036184
_020361D8:
	mov r0, #0xb8
	bl _Znwm
	movs r5, r0
	beq _02036208
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r6
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	mov r5, r0
_02036208:
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
	beq _020362C4
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020362C4:
	cmp r5, #0
	beq _020362DC
	mov r0, r5
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020362DC:
	mov r0, #1
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_020362E8: .word DAT_0208d694

	arm_func_start sub_020362EC
sub_020362EC: ; 0x020362EC
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0xc
	ldr ip, _02036430 ; =DAT_0208d694
	mov r4, #0x1c
	mla ip, r3, r4, ip
	mov r4, r0
	mov r0, #0xb8
	mov r6, r1
	mov r5, r2
	str ip, [r4, #0x10]
	bl _Znwm
	cmp r0, #0
	beq _0203633C
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r6
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	arm_func_end sub_020362EC
_0203633C:
	str r0, [r4, #0x14]
	mov r0, #0xb8
	bl _Znwm
	cmp r0, #0
	beq _0203636C
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r1, r5
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
_0203636C:
	str r0, [r4, #0x18]
	ldr r2, [r4, #0x14]
	ldr r5, [r0, #0x50]
	mov r1, #0
	ldr r0, [r2, #0x50]
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r5, lsr #1
	add r2, r1, #7
	mov r1, #0
	bic r3, r2, #7
	str r0, [r4]
	mov r2, r1
	mov r0, r3, lsl #1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r4, #4]
	ldr r0, [r4]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0xd
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0xd
	str r0, [r4, #0xc]
	ldr r1, [r4, #0x18]
	ldr r0, [r1, #0x4c]
	ldr r1, [r1, #0x50]
	bl DC_FlushRange
	ldr r1, [r4, #0x14]
	ldr r0, [r1, #0x4c]
	ldr r1, [r1, #0x50]
	bl DC_FlushRange
	ldr r3, [r4, #0x18]
	ldr r1, [r4, #0xc]
	ldr r2, [r3, #0x4c]
	ldr r3, [r3, #0x50]
	mov r0, #1
	add r3, r3, #3
	bic r3, r3, #3
	bl NNS_GfdRegisterNewVramTransferTask
	ldr r3, [r4, #0x14]
	ldr r1, [r4, #8]
	ldr r2, [r3, #0x4c]
	ldr r3, [r3, #0x50]
	mov r0, #0
	bl NNS_GfdRegisterNewVramTransferTask
	mov r0, #1
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02036430: .word DAT_0208d694

	arm_func_start sub_02036434
sub_02036434: ; 0x02036434
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _02036460
	beq _02036458
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02036434
_02036458:
	mov r0, #0
	str r0, [r4, #0x14]
_02036460:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	beq _0203647C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203647C:
	mov r0, #0
	str r0, [r4, #0x18]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02036488
sub_02036488: ; 0x02036488
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _020364A8
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4]
	arm_func_end sub_02036488
_020364A8:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _020364C0
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #4]
_020364C0:
	mov r1, #0
	str r1, [r4, #8]
	mov r0, r4
	str r1, [r4, #0xc]
	bl sub_02036434
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_020364DC
sub_020364DC: ; 0x020364DC
	ldr r1, [r0, #0x10]
	ldr r3, [r0, #8]
	ldmia r1, {r2, ip}
	mov r2, r2, lsl #0x1a
	orr r2, r2, r3, lsr #3
	orr r2, r2, ip, lsl #30
	ldr r3, [r1, #8]
	ldr ip, [r1, #0xc]
	orr r2, r2, r3, lsl #20
	orr r2, r2, ip, lsl #23
	ldr r3, [r1, #0x10]
	ldr ip, [r1, #0x14]
	orr r2, r2, r3, lsl #16
	ldr r3, [r1, #0x18]
	orr r2, r2, ip, lsl #18
	ldr r1, _02036550 ; =0x040004A8
	orr r2, r2, r3, lsl #29
	str r2, [r1]
	ldr r1, [r0, #0x10]
	ldr r1, [r1]
	cmp r1, #2
	moveq r2, #1
	movne r2, #0
	ldr r1, [r0, #0xc]
	rsb r0, r2, #4
	mov r1, r1, lsr r0
	ldr r0, _02036554 ; =0x040004AC
	str r1, [r0]
	bx lr
	.align 2, 0
_02036550: .word 0x040004A8
_02036554: .word 0x040004AC
	arm_func_end sub_020364DC

	arm_func_start sub_02036558
sub_02036558: ; 0x02036558
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r2, [r0, #0x14]
	cmp r2, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldrh lr, [r1, #0x28]
	ldrh r4, [r0, #8]
	ldr ip, [r0, #0x24]
	ldr r3, [r0, #0x28]
	ldr r2, _020367B4 ; =0x04000480
	mov r1, #1
	str r4, [r2]
	ldr r4, [r0, #0xc]
	ldr r5, [r0, #0x10]
	mov r4, r4, lsl #4
	orr r4, r4, #0xc0
	ldr r6, [r0, #0x14]
	orr r4, r4, r5, lsl #24
	orr r4, r4, r6, lsl #16
	str r4, [r2, #0x24]
	str r1, [r2, #0x80]
	ldr r4, [r0, #0x30]
	ldr r6, [r0, #0x2c]
	mov r4, r4, lsl #8
	mov r5, r4, asr #0x10
	mov r4, r6, lsl #8
	mov r5, r5, lsl #0x10
	mov r4, r4, asr #0x10
	mov r5, r5, lsr #0x10
	mov r4, r4, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r4, r5, r4, lsr #16
	str r4, [r2, #8]
	ldr r4, [r0, #0x20]
	ldr r5, [r0, #0x1c]
	sub r4, r4, r3, asr #1
	mov r4, r4, asr #0xc
	sub r5, r5, ip, asr #1
	mov r4, r4, lsl lr
	mov r5, r5, asr #0xc
	mov r5, r5, lsl lr
	mov r4, r4, lsl #0x10
	mov r4, r4, asr #0x10
	ldr r7, [r0, #4]
	mov r5, r5, lsl #0x10
	mov r6, r4, lsl #0x10
	mov r4, r7, lsl #0x10
	mov r7, r5, asr #0x10
	mov r6, r6, lsr #0x10
	mov r4, r4, asr #0x10
	mov r5, r4, lsl #0x10
	mov r4, r7, lsl #0x10
	mov r6, r6, lsl #0x10
	orr r4, r6, r4, lsr #16
	str r4, [r2, #0xc]
	mov r4, r5, lsr #0x10
	str r4, [r2, #0xc]
	ldr r4, [r0, #0x38]
	ldr r6, [r0, #0x2c]
	mov r4, r4, lsl #8
	mov r5, r4, asr #0x10
	mov r4, r6, lsl #8
	mov r5, r5, lsl #0x10
	mov r4, r4, asr #0x10
	mov r5, r5, lsr #0x10
	mov r4, r4, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r4, r5, r4, lsr #16
	str r4, [r2, #8]
	ldr r4, [r0, #0x20]
	ldr r5, [r0, #0x1c]
	add r4, r4, r3, asr #1
	mov r4, r4, asr #0xc
	sub r5, r5, ip, asr #1
	mov r4, r4, lsl lr
	mov r5, r5, asr #0xc
	mov r6, r5, lsl lr
	mov r4, r4, lsl #0x10
	mov r5, r4, asr #0x10
	mov r4, r6, lsl #0x10
	mov r5, r5, lsl #0x10
	mov r4, r4, asr #0x10
	mov r5, r5, lsr #0x10
	mov r4, r4, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r4, r5, r4, lsr #16
	str r4, [r2, #0x14]
	ldr r4, [r0, #0x38]
	ldr r6, [r0, #0x34]
	mov r4, r4, lsl #8
	mov r5, r4, asr #0x10
	mov r4, r6, lsl #8
	mov r5, r5, lsl #0x10
	mov r4, r4, asr #0x10
	mov r5, r5, lsr #0x10
	mov r4, r4, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r4, r5, r4, lsr #16
	str r4, [r2, #8]
	ldr r4, [r0, #0x20]
	ldr r5, [r0, #0x1c]
	add r4, r4, r3, asr #1
	mov r4, r4, asr #0xc
	add r5, r5, ip, asr #1
	mov r4, r4, lsl lr
	mov r5, r5, asr #0xc
	mov r6, r5, lsl lr
	mov r4, r4, lsl #0x10
	mov r5, r4, asr #0x10
	mov r4, r6, lsl #0x10
	mov r5, r5, lsl #0x10
	mov r4, r4, asr #0x10
	mov r5, r5, lsr #0x10
	mov r4, r4, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r4, r5, r4, lsr #16
	str r4, [r2, #0x14]
	ldr r4, [r0, #0x30]
	ldr r6, [r0, #0x34]
	mov r4, r4, lsl #8
	mov r5, r4, asr #0x10
	mov r4, r6, lsl #8
	mov r5, r5, lsl #0x10
	mov r4, r4, asr #0x10
	mov r5, r5, lsr #0x10
	mov r4, r4, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r4, r5, r4, lsr #16
	str r4, [r2, #8]
	ldr r4, [r0, #0x20]
	ldr r5, [r0, #0x1c]
	sub r0, r4, r3, asr #1
	mov r0, r0, asr #0xc
	add r3, r5, ip, asr #1
	mov r0, r0, lsl lr
	mov r3, r3, asr #0xc
	mov r4, r3, lsl lr
	mov r0, r0, lsl #0x10
	mov r3, r0, asr #0x10
	mov r0, r4, lsl #0x10
	mov r3, r3, lsl #0x10
	mov r0, r0, asr #0x10
	mov r3, r3, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r3, r3, lsl #0x10
	orr r0, r3, r0, lsr #16
	str r0, [r2, #0x14]
	mov r3, #0
	mov r0, r1
	str r3, [r2, #0x84]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_020367B4: .word 0x04000480
	arm_func_end sub_02036558

	arm_func_start sub_020367B8
sub_020367B8: ; 0x020367B8
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, [r0, #0x14]
	cmp r2, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldrh ip, [r1, #0x28]
	ldrh r3, [r0, #8]
	ldr r2, _020368B4 ; =0x04000480
	mov r1, #1
	str r3, [r2]
	ldr r3, [r0, #0xc]
	ldr r4, [r0, #0x10]
	mov r3, r3, lsl #4
	orr r3, r3, #0xc0
	ldr r5, [r0, #0x14]
	orr r3, r3, r4, lsl #24
	orr r3, r3, r5, lsl #16
	str r3, [r2, #0x24]
	str r1, [r2, #0x80]
	mov r3, #0
	arm_func_end sub_020367B8
_02036808:
	add r1, r0, r3, lsl #3
	ldr r4, [r1, #0x40]
	ldr r5, [r1, #0x3c]
	mov lr, r4, lsl #8
	mov r4, lr, asr #0x10
	mov lr, r5, lsl #8
	mov r4, r4, lsl #0x10
	mov r5, lr, asr #0x10
	mov r4, r4, lsr #0x10
	mov lr, r5, lsl #0x10
	mov r4, r4, lsl #0x10
	orr r4, r4, lr, lsr #16
	str r4, [r2, #8]
	ldr r4, [r1, #0x20]
	ldr r5, [r1, #0x1c]
	mov r1, r4, asr #0xc
	mov r1, r1, lsl ip
	mov r4, r5, asr #0xc
	mov r4, r4, lsl ip
	mov r1, r1, lsl #0x10
	mov r1, r1, asr #0x10
	ldr r5, [r0, #4]
	mov r4, r4, lsl #0x10
	mov lr, r1, lsl #0x10
	mov r1, r5, lsl #0x10
	mov r5, r4, asr #0x10
	mov lr, lr, lsr #0x10
	mov r1, r1, asr #0x10
	mov r4, r1, lsl #0x10
	add r3, r3, #1
	mov r1, r5, lsl #0x10
	mov lr, lr, lsl #0x10
	orr r1, lr, r1, lsr #16
	str r1, [r2, #0xc]
	mov r1, r4, lsr #0x10
	str r1, [r2, #0xc]
	cmp r3, #4
	blt _02036808
	ldr r0, _020368B8 ; =0x04000504
	mov r1, #0
	str r1, [r0]
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020368B4: .word 0x04000480
_020368B8: .word 0x04000504

	arm_func_start sub_020368BC
sub_020368BC: ; 0x020368BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020368BC

	arm_func_start sub_020368D8
sub_020368D8: ; 0x020368D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020368D8

	arm_func_start sub_020368EC
sub_020368EC: ; 0x020368EC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020368EC

	arm_func_start sub_02036908
sub_02036908: ; 0x02036908
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02036908

	arm_func_start sub_0203691C
sub_0203691C: ; 0x0203691C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02036488
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_0203691C

	arm_func_start sub_02036930
sub_02036930: ; 0x02036930
	stmdb sp!, {r4, lr}
	ldr r1, _020369A4 ; =PTR_LAB_0208d610
	mov r4, r0
	str r1, [r4]
	mov r1, #4
	ldr r0, _020369A8 ; =ptr_FUN_020369b4_0208d7c8
	str r1, [r4, #0x1c]
	str r0, [r4]
	mov r1, #0
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	str r1, [r4, #0x34]
	ldr r0, _020369AC ; =DAT_0208d694
	str r1, [r4, #0x38]
	str r0, [r4, #0x3c]
	str r1, [r4, #0x40]
	add r0, r4, #0x48
	str r1, [r4, #0x44]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _020369B0 ; =ptr_FUN_020368d8_0208d688
	mov r0, r4
	str r1, [r4, #0x48]
	mov r1, #0
	str r1, [r4, #0x60]
	bl sub_0203724C
	mov r1, #0x1f
	mov r0, r4
	str r1, [r4, #0x20]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020369A4: .word PTR_LAB_0208d610
_020369A8: .word ptr_FUN_020369b4_0208d7c8
_020369AC: .word DAT_0208d694
_020369B0: .word ptr_FUN_020368d8_0208d688
	arm_func_end sub_02036930

	arm_func_start sub_020369B4
sub_020369B4: ; 0x020369B4
	stmdb sp!, {r4, lr}
	ldr r1, _020369E0 ; =ptr_FUN_020369b4_0208d7c8
	mov r4, r0
	str r1, [r4]
	bl sub_0203731C
	add r0, r4, #0x48
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x2c
	bl sub_02036488
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_020369E0: .word ptr_FUN_020369b4_0208d7c8
	arm_func_end sub_020369B4

	arm_func_start sub_020369E4
sub_020369E4: ; 0x020369E4
	stmdb sp!, {r4, lr}
	ldr r1, _02036A18 ; =ptr_FUN_020369b4_0208d7c8
	mov r4, r0
	str r1, [r4]
	bl sub_0203731C
	add r0, r4, #0x48
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x2c
	bl sub_02036488
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02036A18: .word ptr_FUN_020369b4_0208d7c8
	arm_func_end sub_020369E4

	arm_func_start sub_02036A1C
sub_02036A1C: ; 0x02036A1C
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #0x28]
	mov r5, r1
	cmp r0, #0
	beq _02036A48
	subs r0, r0, #1
	str r0, [r4, #0x28]
	bne _02036A48
	add r0, r4, #0x2c
	bl sub_02036434
	arm_func_end sub_02036A1C
_02036A48:
	mov r0, r4
	mov r1, r5
	bl sub_02035334
	ldr r3, _02036B18 ; =FX_SinCosTable_
	mov r1, r4
	mov r0, #0
_02036A60:
	ldrh ip, [r1, #0xaa]
	ldrh r2, [r1, #0xac]
	add r0, r0, #1
	add r2, ip, r2
	strh r2, [r1, #0xaa]
	ldrh r2, [r1, #0xaa]
	mov r2, r2, asr #4
	add r2, r3, r2, lsl #2
	ldrsh r2, [r2, #2]
	movs r2, r2, lsl #4
	rsbmi r2, r2, #0
	mov r2, r2, asr #0xc
	add r2, r2, #0xf
	strh r2, [r1, #0xa8]
	ldrh r2, [r1, #0xaa]
	mov r2, r2, asr #4
	add r2, r3, r2, lsl #2
	ldrsh r2, [r2, #2]
	cmp r2, #0
	rsblt r2, r2, #0
	rsb r2, r2, #0x1800
	str r2, [r1, #0xa4]
	cmp r0, #9
	add r1, r1, #0xc
	blt _02036A60
	ldr r0, [r4, #4]
	cmp r0, #3
	beq _02036AE4
	cmp r0, #4
	beq _02036AF0
	cmp r0, #5
	beq _02036AFC
	b _02036B08
_02036AE4:
	ldr r0, [r4, #0x18]
	str r0, [r4, #0x24]
	b _02036B10
_02036AF0:
	mov r0, #0x1000
	str r0, [r4, #0x24]
	b _02036B10
_02036AFC:
	ldr r0, [r4, #0x18]
	str r0, [r4, #0x24]
	b _02036B10
_02036B08:
	mov r0, #0
	str r0, [r4, #0x24]
_02036B10:
	ldr r0, [r4, #4]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02036B18: .word FX_SinCosTable_

	arm_func_start sub_02036B1C
sub_02036B1C: ; 0x02036B1C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r5, r0
	ldr r2, [r5, #0x24]
	mov r4, r1
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	bl sub_020355B4
	ldr r2, [r5, #0x1c]
	mov r1, #0
	str r2, [r5, #0x58]
	str r1, [r5, #0x8c]
	mov r0, #0x20000
	str r1, [r5, #0x84]
	str r0, [r5, #0x9c]
	str r0, [r5, #0x94]
	str r1, [r5, #0xa0]
	str r1, [r5, #0x88]
	str r0, [r5, #0x98]
	str r0, [r5, #0x90]
	add r0, r5, #0x2c
	bl sub_020364DC
	ldr r1, [r5, #0xa4]
	mov r0, #0x60000
	umull r3, r2, r1, r0
	mov r1, r1, asr #0x1f
	mov r6, #0x19000
	ldrh r7, [r5, #0xa8]
	ldr r8, [r5, #0x24]
	mla r2, r1, r0, r2
	mul r0, r8, r7
	mov r0, r0, lsl #4
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r1, [r5, #0xae]
	mov r0, r3, lsr #0xc
	rsb r6, r6, #0
	strh r1, [r5, #0x50]
	orr r0, r0, r2, lsl #20
	sub r1, r0, #0x60000
	str r6, [r5, #0x64]
	sub r2, r6, #0x47000
	str r2, [r5, #0x68]
	str r6, [r5, #0x6c]
	str r1, [r5, #0x70]
	mov r0, #0x19000
	str r0, [r5, #0x74]
	str r1, [r5, #0x78]
	str r0, [r5, #0x7c]
	add r0, r5, #0x48
	str r2, [r5, #0x80]
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r1, #0x4b000
	rsb r1, r1, #0
	ldr ip, [r5, #0xb0]
	mov lr, #0x58000
	ldrh r0, [r5, #0xb4]
	ldr r2, [r5, #0x24]
	mov r3, r1, asr #0x13
	mul r0, r2, r0
	add r2, r1, #0x41000
	umull sb, r8, ip, r2
	mov r0, r0, lsl #4
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r0, [r5, #0xba]
	mla r8, ip, r3, r8
	strh r0, [r5, #0x50]
	mov sl, ip, asr #0x1f
	mla r8, sl, r2, r8
	mov r2, sb, lsr #0xc
	orr r2, r2, r8, lsl #20
	sub fp, r1, #0x15000
	str r1, [r5, #0x64]
	str fp, [r5, #0x68]
	sub r2, r2, #0x4b000
	str r2, [r5, #0x6c]
	umull r3, r2, ip, lr
	mla r2, sl, lr, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	sub r2, r3, #0x60000
	mov r6, #0x60000
	str r2, [r5, #0x70]
	umull r3, r2, ip, r6
	sub r7, lr, #0x71000
	mla r2, sl, r6, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	str r7, [r5, #0x74]
	sub r2, r3, #0x60000
	str r2, [r5, #0x78]
	str r7, [r5, #0x7c]
	add r0, r5, #0x48
	str fp, [r5, #0x80]
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldrh r0, [r5, #0xc0]
	ldr r1, [r5, #0x24]
	mov r7, #0
	mul r3, r1, r0
	mov r1, #0x50000
	mov r3, r3, lsl #4
	mov sb, #0x7d000
	rsb sb, sb, #0
	ldr r2, [r5, #0xbc]
	mov r3, r3, lsr #0x10
	add r0, sb, #0x69000
	sub r1, r1, #0x5a000
	str r3, [r5, #0x5c]
	umull r8, r3, r2, r1
	sub r7, r7, #1
	mla r3, r2, r7, r3
	mov r7, r2, asr #0x1f
	mla r3, r7, r1, r3
	mov ip, r8, lsr #0xc
	orr ip, ip, r3, lsl #20
	umull sl, lr, r2, r0
	mov r6, sb, asr #0x13
	mla lr, r2, r6, lr
	mov r6, sl, lsr #0xc
	ldrh sl, [r5, #0xc6]
	mla lr, r7, r0, lr
	strh sl, [r5, #0x50]
	orr r6, r6, lr, lsl #20
	mov r3, #0x50000
	add r8, sb, #0x1d000
	str sb, [r5, #0x64]
	sub sb, ip, #0x4b000
	umull ip, sl, r2, r3
	mla sl, r7, r3, sl
	mov r3, ip, lsr #0xc
	orr r3, r3, sl, lsl #20
	sub r0, r6, #0x7d000
	str r8, [r5, #0x68]
	str r0, [r5, #0x6c]
	sub r3, r3, #0x60000
	mov fp, #0x58000
	str r3, [r5, #0x70]
	str sb, [r5, #0x74]
	umull sb, r3, r2, fp
	mla r3, r7, fp, r3
	mov r2, sb, lsr #0xc
	orr r2, r2, r3, lsl #20
	sub r2, r2, #0x60000
	sub r6, fp, #0xa3000
	str r2, [r5, #0x78]
	str r6, [r5, #0x7c]
	add r0, r5, #0x48
	str r8, [r5, #0x80]
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r1, #0x19000
	ldrh r0, [r5, #0xcc]
	ldr r2, [r5, #0x24]
	ldr r6, [r5, #0xc8]
	mul r0, r2, r0
	mov r0, r0, lsl #4
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r0, [r5, #0xd2]
	mov r7, #0x60000
	mov sb, fp
	strh r0, [r5, #0x50]
	umull ip, fp, r6, r7
	mov r2, r6, asr #0x1f
	mla fp, r2, r7, fp
	mov r7, ip, lsr #0xc
	orr r7, r7, fp, lsl #20
	sub r3, r1, #0x79000
	str r1, [r5, #0x64]
	str r3, [r5, #0x68]
	str r1, [r5, #0x6c]
	sub r7, r7, #0x60000
	mov r8, #0xa000
	str r7, [r5, #0x70]
	umull fp, r7, r6, r8
	mla r7, r2, r8, r7
	mov r8, fp, lsr #0xc
	orr r8, r8, r7, lsl #20
	add r7, r8, #0x4b000
	str r7, [r5, #0x74]
	umull r8, r7, r6, sb
	mla r7, r2, sb, r7
	mov r2, r8, lsr #0xc
	orr r2, r2, r7, lsl #20
	sub r2, r2, #0x60000
	mov sl, #0x4b000
	str r2, [r5, #0x78]
	str sl, [r5, #0x7c]
	add r0, r5, #0x48
	str r3, [r5, #0x80]
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r1, sl
	ldr ip, [r5, #0xd4]
	ldrh r0, [r5, #0xd8]
	ldr r2, [r5, #0x24]
	sub fp, r1, #0xab000
	mul r0, r2, r0
	mov r0, r0, lsl #4
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r0, [r5, #0xde]
	mov sl, ip, asr #0x1f
	strh r0, [r5, #0x50]
	str r1, [r5, #0x64]
	str fp, [r5, #0x68]
	mov r0, #0xa000
	umull sb, r8, ip, r0
	mov lr, #0x58000
	umull r7, r6, ip, lr
	mla r8, sl, r0, r8
	mov r0, sb, lsr #0xc
	orr r0, r0, r8, lsl #20
	mov r1, #0x14000
	add r0, r0, #0x4b000
	umull r3, r2, ip, r1
	str r0, [r5, #0x6c]
	mla r2, sl, r1, r2
	mov r1, r3, lsr #0xc
	orr r1, r1, r2, lsl #20
	mla r6, sl, lr, r6
	mov r7, r7, lsr #0xc
	orr r7, r7, r6, lsl #20
	sub r6, r7, #0x60000
	mov r0, #0x50000
	str r6, [r5, #0x70]
	umull r7, r6, ip, r0
	mla r6, sl, r0, r6
	mov r0, r7, lsr #0xc
	add r1, r1, #0x7d000
	orr r0, r0, r6, lsl #20
	str r1, [r5, #0x74]
	sub r0, r0, #0x60000
	str r0, [r5, #0x78]
	mov r0, #0x7d000
	str r0, [r5, #0x7c]
	str fp, [r5, #0x80]
	add r0, r5, #0x48
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r0, [r5, #0x1c]
	mov r1, #0x32000
	rsb r1, r1, #0
	add r0, r0, #1
	str r0, [r5, #0x58]
	ldr ip, [r5, #0xe0]
	ldrh r0, [r5, #0xe4]
	ldr r2, [r5, #0x24]
	mov r3, r1, asr #0x12
	mul r0, r2, r0
	add r2, r1, #0x2d000
	umull sb, r8, ip, r2
	mov r0, r0, lsl #4
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r0, [r5, #0xea]
	mla r8, ip, r3, r8
	strh r0, [r5, #0x50]
	mov sl, ip, asr #0x1f
	mla r8, sl, r2, r8
	mov r2, sb, lsr #0xc
	orr r2, r2, r8, lsl #20
	sub fp, r1, #0x2e000
	str r1, [r5, #0x64]
	str fp, [r5, #0x68]
	sub r2, r2, #0x32000
	mov lr, #0x5c000
	str r2, [r5, #0x6c]
	umull r3, r2, ip, lr
	mla r2, sl, lr, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	sub r2, r3, #0x60000
	mov r6, #0x60000
	str r2, [r5, #0x70]
	umull r3, r2, ip, r6
	mov r7, #0
	mla r2, sl, r6, r2
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	str r7, [r5, #0x74]
	sub r2, r3, #0x60000
	str r2, [r5, #0x78]
	str r7, [r5, #0x7c]
	add r0, r5, #0x48
	str fp, [r5, #0x80]
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r8, r7
	mov r3, #0x64000
	mov r7, #0x54000
	ldrh r0, [r5, #0xf0]
	ldr r1, [r5, #0x24]
	ldr r2, [r5, #0xec]
	mul r0, r1, r0
	mov r0, r0, lsl #4
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r6, [r5, #0xf6]
	rsb r3, r3, #0
	add r1, r3, #0x4000
	strh r6, [r5, #0x50]
	str r3, [r5, #0x64]
	mov r6, r3, asr #0x13
	add r3, r3, #0x55000
	umull ip, fp, r2, r3
	mla fp, r2, r6, fp
	mov r0, r2, asr #0x1f
	mla fp, r0, r3, fp
	mov r3, ip, lsr #0xc
	orr r3, r3, fp, lsl #20
	str r1, [r5, #0x68]
	sub r3, r3, #0x64000
	str r3, [r5, #0x6c]
	umull r6, r3, r2, r7
	mla r3, r0, r7, r3
	mov r6, r6, lsr #0xc
	orr r6, r6, r3, lsl #20
	sub r3, r6, #0x60000
	sub sl, r8, #1
	sub sb, r7, #0x59000
	str r3, [r5, #0x70]
	umull r6, r3, r2, sb
	mla r3, r2, sl, r3
	mla r3, r0, sb, r3
	mov r6, r6, lsr #0xc
	orr r6, r6, r3, lsl #20
	sub r3, r6, #0x32000
	str r3, [r5, #0x74]
	mov r3, #0x5c000
	umull r7, r6, r2, r3
	mla r6, r2, r8, r6
	mla r6, r0, r3, r6
	mov r0, r7, lsr #0xc
	orr r0, r0, r6, lsl #20
	sub r0, r0, #0x60000
	str r0, [r5, #0x78]
	sub r0, r3, #0x8e000
	str r0, [r5, #0x7c]
	str r1, [r5, #0x80]
	add r0, r5, #0x48
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r6, [r5, #0xf8]
	mov r0, #0x60000
	umull r3, r1, r6, r0
	mov r2, r6, asr #0x1f
	mla r1, r2, r0, r1
	mov r0, r3, lsr #0xc
	orr r0, r0, r1, lsl #20
	sub sb, r0, #0x60000
	mov sl, r8
	ldrh r0, [r5, #0xfc]
	ldr r3, [r5, #0x24]
	add r1, r5, #0x100
	mul r0, r3, r0
	mov r0, r0, lsl #4
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r0, [r1, #2]
	sub r3, sl, #0x60000
	mov r7, #0x5000
	strh r0, [r5, #0x50]
	str sl, [r5, #0x64]
	str r3, [r5, #0x68]
	str sl, [r5, #0x6c]
	umull fp, sl, r6, r7
	mla sl, r2, r7, sl
	mov r7, fp, lsr #0xc
	orr r7, r7, sl, lsl #20
	str sb, [r5, #0x70]
	add r7, r7, #0x32000
	mov r8, #0x5c000
	str r7, [r5, #0x74]
	umull sl, r7, r6, r8
	mla r7, r2, r8, r7
	mov r2, sl, lsr #0xc
	orr r2, r2, r7, lsl #20
	sub r2, r2, #0x60000
	mov sb, #0x32000
	str r2, [r5, #0x78]
	str sb, [r5, #0x7c]
	add r0, r5, #0x48
	str r3, [r5, #0x80]
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	mov r7, sb
	add r2, r5, #0x100
	mov r1, r4
	ldrh r0, [r2, #8]
	ldr r6, [r5, #0x24]
	ldr r4, [r5, #0x104]
	mul r0, r6, r0
	mov r0, r0, lsl #4
	mov r6, #0x5000
	mov r0, r0, lsr #0x10
	str r0, [r5, #0x5c]
	ldrh r0, [r2, #0xe]
	umull ip, fp, r4, r6
	strh r0, [r5, #0x50]
	mov r2, r4, asr #0x1f
	mla fp, r2, r6, fp
	mov r6, ip, lsr #0xc
	orr r6, r6, fp, lsl #20
	sub r3, r7, #0x92000
	str r7, [r5, #0x64]
	mov r7, r8
	str r3, [r5, #0x68]
	add r6, r6, #0x32000
	str r6, [r5, #0x6c]
	umull fp, r6, r4, r7
	mla r6, r2, r7, r6
	mov r7, fp, lsr #0xc
	orr r7, r7, r6, lsl #20
	sub r6, r7, #0x60000
	mov r8, #0xf000
	str r6, [r5, #0x70]
	umull r7, r6, r4, r8
	mla r6, r2, r8, r6
	mov r7, r7, lsr #0xc
	orr r7, r7, r6, lsl #20
	add r6, r7, #0x64000
	mov sb, #0x54000
	str r6, [r5, #0x74]
	umull r7, r6, r4, sb
	mla r6, r2, sb, r6
	mov r2, r7, lsr #0xc
	orr r2, r2, r6, lsl #20
	sub r2, r2, #0x60000
	mov sl, #0x64000
	str r2, [r5, #0x78]
	str sl, [r5, #0x7c]
	add r0, r5, #0x48
	str r3, [r5, #0x80]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldr r0, _02037248 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02037248: .word 0x04000448
	arm_func_end sub_02036B1C

	arm_func_start sub_0203724C
sub_0203724C: ; 0x0203724C
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r1, _0203730C ; =s_data_field_effect_komorebi_ntft_0208d7e4
	ldr r2, _02037310 ; =s_data_field_effect_komorebi_ntfp_0208d804
	add r0, r4, #0x2c
	mov r3, #3
	bl sub_020362EC
	mov r0, #2
	ldr ip, _02037314 ; =0x000053FF
	str r0, [r4, #0x28]
	mov r5, #0
	strh r5, [r4, #0xaa]
	mov lr, #0xc0
	strh lr, [r4, #0xac]
	strh ip, [r4, #0xae]
	strh r5, [r4, #0xb6]
	mov r3, #0x120
	ldr r2, _02037318 ; =0x000073FA
	strh r3, [r4, #0xb8]
	strh r2, [r4, #0xba]
	strh r5, [r4, #0xc2]
	mov r1, #0x180
	strh r1, [r4, #0xc4]
	add r0, ip, #0xf20
	strh r0, [r4, #0xc6]
	strh r5, [r4, #0xce]
	strh lr, [r4, #0xd0]
	strh r2, [r4, #0xd2]
	strh r5, [r4, #0xda]
	strh r1, [r4, #0xdc]
	strh r0, [r4, #0xde]
	mov r0, #0x2000
	strh r0, [r4, #0xe6]
	strh r3, [r4, #0xe8]
	strh ip, [r4, #0xea]
	mov r1, #0x4000
	strh r1, [r4, #0xf2]
	strh r3, [r4, #0xf4]
	strh ip, [r4, #0xf6]
	strh r0, [r4, #0xfe]
	add r0, r4, #0x100
	strh lr, [r0]
	strh ip, [r0, #2]
	strh r1, [r0, #0xa]
	strh r3, [r0, #0xc]
	strh ip, [r0, #0xe]
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203730C: .word s_data_field_effect_komorebi_ntft_0208d7e4
_02037310: .word s_data_field_effect_komorebi_ntfp_0208d804
_02037314: .word 0x000053FF
_02037318: .word 0x000073FA
	arm_func_end sub_0203724C

	arm_func_start sub_0203731C
sub_0203731C: ; 0x0203731C
	stmdb sp!, {r3, lr}
	add r0, r0, #0x2c
	bl sub_02036488
	mov r0, #1
	ldmia sp!, {r3, pc}
	arm_func_end sub_0203731C

	arm_func_start sub_02037330
sub_02037330: ; 0x02037330
	ldr r1, [r0, #0x18]
	str r1, [r0, #0x24]
	bx lr
	arm_func_end sub_02037330

	arm_func_start sub_0203733C
sub_0203733C: ; 0x0203733C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020354E0
	mov r1, #0
	str r1, [r4, #0x24]
	ldmia sp!, {r4, pc}
	arm_func_end sub_0203733C

	arm_func_start sub_02037354
sub_02037354: ; 0x02037354
	mov r0, #3
	bx lr
	arm_func_end sub_02037354

	arm_func_start sub_0203735C
sub_0203735C: ; 0x0203735C
	mov r2, #0
	str r2, [r0]
	str r2, [r0, #4]
	str r2, [r0, #8]
	ldr r1, _02037384 ; =DAT_0208d694
	str r2, [r0, #0xc]
	str r1, [r0, #0x10]
	str r2, [r0, #0x14]
	str r2, [r0, #0x18]
	bx lr
	.align 2, 0
_02037384: .word DAT_0208d694
	arm_func_end sub_0203735C

	arm_func_start sub_02037388
sub_02037388: ; 0x02037388
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0203751C ; =PTR_LAB_0208d610
	mov r5, r0
	str r2, [r5]
	mov r2, #4
	mov r4, r1
	ldr r0, _02037520 ; =ptr_FUN_02037988_0208d848
	str r2, [r5, #0x1c]
	ldr ip, _02037524 ; =sub_0203691C
	str r0, [r5]
	ldr r3, _02037528 ; =sub_0203735C
	add r0, r5, #0x24
	mov r1, #2
	mov r2, #0x1c
	str ip, [sp]
	bl __cxa_vec_ctor
	add r0, r5, #0x5c
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _0203752C ; =ptr_FUN_02036908_0208d660
	mov r0, #0
	str r1, [r5, #0x5c]
	str r0, [r5, #0x74]
	str r0, [r5, #0xb0]
	mov r0, r5
	str r4, [r5, #0xa8]
	bl sub_020378AC
	mov r0, #0
	str r0, [r5, #0x70]
	cmp r4, #7
	bgt _0203742C
	cmp r4, #0
	addge pc, pc, r4, lsl #2
	b _020374AC
_0203740C: ; jump table
	b _020374AC ; case 0
	b _020374AC ; case 1
	b _020374AC ; case 2
	b _020374AC ; case 3
	b _02037438 ; case 4
	b _02037450 ; case 5
	b _02037468 ; case 6
	b _02037480 ; case 7
	arm_func_end sub_02037388
_0203742C:
	cmp r4, #0x10
	beq _02037498
	b _020374AC
_02037438:
	ldr r0, _02037530 ; =DAT_0208d864
	ldrh r1, [r0]
	strh r1, [r5, #0x64]
	ldr r0, [r0, #4]
	str r0, [r5, #0xac]
	b _020374AC
_02037450:
	ldr r0, _02037530 ; =DAT_0208d864
	ldrh r1, [r0, #8]
	strh r1, [r5, #0x64]
	ldr r0, [r0, #0xc]
	str r0, [r5, #0xac]
	b _020374AC
_02037468:
	ldr r0, _02037530 ; =DAT_0208d864
	ldrh r1, [r0, #0x10]
	strh r1, [r5, #0x64]
	ldr r0, [r0, #0x14]
	str r0, [r5, #0xac]
	b _020374AC
_02037480:
	ldr r0, _02037530 ; =DAT_0208d864
	ldrh r1, [r0, #0x18]
	strh r1, [r5, #0x64]
	ldr r0, [r0, #0x1c]
	str r0, [r5, #0xac]
	b _020374AC
_02037498:
	ldr r0, _02037530 ; =DAT_0208d864
	ldrh r1, [r0, #0x20]
	strh r1, [r5, #0x64]
	ldr r0, [r0, #0x24]
	str r0, [r5, #0xac]
_020374AC:
	ldrh r3, [r5, #0x64]
	ldr r4, [r5, #0xac]
	ldr r0, _02037534 ; =MAIN_BSS_0210CAA4
	mov r2, r3, asr #5
	mov r1, r3, asr #0xa
	and r3, r3, #0x1f
	str r3, [r0]
	and r2, r2, #0x1f
	str r2, [r0, #4]
	and r2, r1, #0x1f
	str r2, [r0, #8]
	mov ip, #0
	ldr r1, _02037538 ; =MAIN_BSS_0210CA90
	ldr r0, _0203753C ; =MAIN_BSS_0210CA8C
	mov r2, ip
	mov r3, ip
	str r4, [r1]
	str ip, [r0]
_020374F4:
	add r0, r5, ip, lsl #2
	str r2, [r0, #0x98]
	add ip, ip, #1
	str r3, [r0, #0xa0]
	cmp ip, #2
	add r2, r2, #0x40000
	add r3, r3, #0x30000
	blt _020374F4
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203751C: .word PTR_LAB_0208d610
_02037520: .word ptr_FUN_02037988_0208d848
_02037524: .word sub_0203691C
_02037528: .word sub_0203735C
_0203752C: .word ptr_FUN_02036908_0208d660
_02037530: .word DAT_0208d864
_02037534: .word MAIN_BSS_0210CAA4
_02037538: .word MAIN_BSS_0210CA90
_0203753C: .word MAIN_BSS_0210CA8C

	arm_func_start sub_02037540
sub_02037540: ; 0x02037540
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x20]
	mov r4, r1
	cmp r0, #0
	beq _02037574
	subs r0, r0, #1
	str r0, [r5, #0x20]
	bne _02037574
	add r0, r5, #0x24
	bl sub_02036434
	add r0, r5, #0x40
	bl sub_02036434
	arm_func_end sub_02037540
_02037574:
	ldr r0, _0203779C ; =MAIN_BSS_0210CA84
	ldr r0, [r0]
	bl _f_itof
	mov r1, r0
	ldr r0, _020377A0 ; =0x3D23D70A
	bl _f_mul
	mov r1, r0
	ldr r0, _020377A4 ; =0x45800000
	bl _f_mul
	bl _f_ftoi
	ldr r1, _020377A8 ; =MAIN_BSS_0210CA9C
	ldr lr, [r5, #0x98]
	ldr r3, [r1]
	ldr r1, _0203779C ; =MAIN_BSS_0210CA84
	mov r2, r3, asr #0x1f
	mov r2, r2, lsl #0xb
	mov ip, r3, lsl #0xb
	orr r2, r2, r3, lsr #21
	mov r3, ip, lsr #0xc
	orr r3, r3, r2, lsl #20
	add r0, r0, r3
	sub r0, lr, r0
	str r0, [r5, #0x98]
	ldr r0, [r1]
	bl _f_itof
	mov r1, r0
	ldr r0, _020377AC ; =0x3D75C28F
	bl _f_mul
	mov r1, r0
	ldr r0, _020377A4 ; =0x45800000
	bl _f_mul
	bl _f_ftoi
	rsb ip, r0, #0
	ldr lr, [r5, #0x9c]
	ldr r1, _020377A8 ; =MAIN_BSS_0210CA9C
	ldr r0, _020377B0 ; =0x000FFFFF
	ldr r3, [r1]
	mov r2, r3, asr #0x1f
	mov r2, r2, lsl #0xb
	orr r2, r2, r3, lsr #21
	mov r3, r3, lsl #0xb
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	add r2, ip, r3
	sub r2, lr, r2
	str r2, [r5, #0x9c]
	ldr r2, [r5, #0x98]
	and r2, r2, r0
	str r2, [r5, #0x98]
	ldr r2, [r5, #0x9c]
	and r2, r2, r0
	str r2, [r5, #0x9c]
	ldr ip, [r5, #0xa0]
	ldr r3, [r1, #4]
	mov r2, r3, asr #0x1f
	mov r2, r2, lsl #0xb
	orr r2, r2, r3, lsr #21
	mov r3, r3, lsl #0xb
	mov r3, r3, lsr #0xc
	orr r3, r3, r2, lsl #20
	sub r2, ip, r3
	str r2, [r5, #0xa0]
	ldr r2, [r1, #4]
	ldr r3, [r5, #0xa4]
	mov r1, r2, asr #0x1f
	mov r1, r1, lsl #0xb
	orr r1, r1, r2, lsr #21
	mov r2, r2, lsl #0xb
	mov r2, r2, lsr #0xc
	orr r2, r2, r1, lsl #20
	sub r1, r3, r2
	str r1, [r5, #0xa4]
	ldr r1, [r5, #0xa0]
	and r1, r1, r0
	str r1, [r5, #0xa0]
	ldr r1, [r5, #0xa4]
	and r0, r1, r0
	str r0, [r5, #0xa4]
	mov r0, r5
	mov r1, r4
	bl sub_02035334
	ldr r2, _020377B4 ; =MAIN_BSS_0210CA8C
	ldr r0, [r2]
	cmp r0, #0
	beq _020376F4
	ldr r1, _020377B8 ; =MAIN_BSS_0210CAA4
	ldr r0, _020377BC ; =MAIN_BSS_0210CA90
	ldr r4, [r1]
	ldmib r1, {r3, ip}
	orr r1, r4, r3, lsl #5
	orr r1, r1, ip, lsl #10
	strh r1, [r5, #0x64]
	ldr r1, [r0]
	mov r0, #0
	str r1, [r5, #0xac]
	str r0, [r2]
_020376F4:
	ldr r0, [r5, #4]
	cmp r0, #3
	beq _02037714
	cmp r0, #4
	beq _0203772C
	cmp r0, #5
	beq _02037774
	b _0203778C
_02037714:
	ldr r1, [r5, #0xac]
	ldr r0, [r5, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r5, #0x70]
	b _02037794
_0203772C:
	ldr r0, [r5, #0xa8]
	cmp r0, #5
	bne _02037768
	ldr r0, [r5, #0xb0]
	add r1, r0, #1
	mov r0, r1, asr #2
	tst r0, #8
	andne r0, r0, #0xf
	str r1, [r5, #0xb0]
	rsbne r1, r0, #0xf
	andeq r1, r0, #0xf
	ldr r0, [r5, #0xac]
	add r0, r0, r1
	str r0, [r5, #0x70]
	b _02037794
_02037768:
	ldr r0, [r5, #0xac]
	str r0, [r5, #0x70]
	b _02037794
_02037774:
	ldr r1, [r5, #0xac]
	ldr r0, [r5, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r5, #0x70]
	b _02037794
_0203778C:
	mov r0, #0
	str r0, [r5, #0x70]
_02037794:
	ldr r0, [r5, #4]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203779C: .word MAIN_BSS_0210CA84
_020377A0: .word 0x3D23D70A
_020377A4: .word 0x45800000
_020377A8: .word MAIN_BSS_0210CA9C
_020377AC: .word 0x3D75C28F
_020377B0: .word 0x000FFFFF
_020377B4: .word MAIN_BSS_0210CA8C
_020377B8: .word MAIN_BSS_0210CAA4
_020377BC: .word MAIN_BSS_0210CA90

	arm_func_start sub_020377C0
sub_020377C0: ; 0x020377C0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r2, [r5, #0x70]
	mov r4, r1
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl sub_020355B4
	ldr r1, [r5, #0x1c]
	mov r0, #0
	str r1, [r5, #0x6c]
	str r0, [r5, #0x78]
	str r0, [r5, #0x7c]
	mov r0, #0x100000
	str r0, [r5, #0x80]
	str r0, [r5, #0x84]
	ldr r2, [r5, #0xa0]
	ldr r0, [r5, #0x98]
	add r1, r2, #0x80000
	str r0, [r5, #0x88]
	str r2, [r5, #0x8c]
	add r0, r0, #0x80000
	str r0, [r5, #0x90]
	add r0, r5, #0x24
	str r1, [r5, #0x94]
	bl sub_020364DC
	add r0, r5, #0x5c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r1, [r5, #0x1c]
	mov r0, #0
	add r1, r1, #1
	str r1, [r5, #0x6c]
	str r0, [r5, #0x78]
	str r0, [r5, #0x7c]
	mov r0, #0x100000
	str r0, [r5, #0x80]
	str r0, [r5, #0x84]
	ldr r2, [r5, #0xa4]
	ldr r0, [r5, #0x9c]
	add r1, r2, #0x80000
	str r0, [r5, #0x88]
	str r2, [r5, #0x8c]
	add r0, r0, #0x80000
	str r0, [r5, #0x90]
	add r0, r5, #0x40
	str r1, [r5, #0x94]
	bl sub_020364DC
	add r0, r5, #0x5c
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r0, _020378A8 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020378A8: .word 0x04000448
	arm_func_end sub_020377C0

	arm_func_start sub_020378AC
sub_020378AC: ; 0x020378AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, _020378EC ; =s_data_field_effect_kiri02_ntft_0208d88c
	ldr r2, _020378F0 ; =s_data_field_effect_kiri02_ntfp_0208d8ac
	add r0, r4, #0x24
	mov r3, #2
	bl sub_020362EC
	ldr r1, _020378EC ; =s_data_field_effect_kiri02_ntft_0208d88c
	ldr r2, _020378F0 ; =s_data_field_effect_kiri02_ntfp_0208d8ac
	add r0, r4, #0x40
	mov r3, #2
	bl sub_020362EC
	mov r0, #2
	str r0, [r4, #0x20]
	mov r0, #1
	ldmia sp!, {r4, pc}
	.align 2, 0
_020378EC: .word s_data_field_effect_kiri02_ntft_0208d88c
_020378F0: .word s_data_field_effect_kiri02_ntfp_0208d8ac
	arm_func_end sub_020378AC

	arm_func_start sub_020378F4
sub_020378F4: ; 0x020378F4
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x24
	bl sub_02036488
	add r0, r4, #0x40
	bl sub_02036488
	mov r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end sub_020378F4

	arm_func_start sub_02037914
sub_02037914: ; 0x02037914
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020354E0
	ldr r2, [r4, #0xac]
	ldr r1, [r4, #0x18]
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [r4, #0x70]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02037914

	arm_func_start sub_02037938
sub_02037938: ; 0x02037938
	stmdb sp!, {r4, lr}
	ldr r1, _02037978 ; =ptr_FUN_02037988_0208d848
	mov r4, r0
	str r1, [r4]
	bl sub_020378F4
	add r0, r4, #0x5c
	bl _ZN10CPrimitiveD2Ev
	ldr r3, _0203797C ; =sub_0203691C
	add r0, r4, #0x24
	mov r1, #2
	mov r2, #0x1c
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02037978: .word ptr_FUN_02037988_0208d848
_0203797C: .word sub_0203691C
	arm_func_end sub_02037938

	arm_func_start sub_02037980
sub_02037980: ; 0x02037980
	ldr r0, [r0, #0xa8]
	bx lr
	arm_func_end sub_02037980

	arm_func_start sub_02037988
sub_02037988: ; 0x02037988
	stmdb sp!, {r4, lr}
	ldr r1, _020379C0 ; =ptr_FUN_02037988_0208d848
	mov r4, r0
	str r1, [r4]
	bl sub_020378F4
	add r0, r4, #0x5c
	bl _ZN10CPrimitiveD2Ev
	ldr r3, _020379C4 ; =sub_0203691C
	add r0, r4, #0x24
	mov r1, #2
	mov r2, #0x1c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_020379C0: .word ptr_FUN_02037988_0208d848
_020379C4: .word sub_0203691C
	arm_func_end sub_02037988

	arm_func_start sub_020379C8
sub_020379C8: ; 0x020379C8
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02037ACC ; =PTR_LAB_0208d610
	mov r4, r0
	str r1, [r4]
	mov r1, #4
	str r1, [r4, #0x1c]
	ldr r0, _02037AD0 ; =ptr_FUN_02037fb0_0208d8f8
	ldr ip, _02037AD4 ; =sub_0203691C
	str r0, [r4]
	ldr r3, _02037AD8 ; =sub_0203735C
	add r0, r4, #0x20
	mov r1, #2
	mov r2, #0x1c
	str ip, [sp]
	bl __cxa_vec_ctor
	add r0, r4, #0x98
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _02037ADC ; =ptr_FUN_02036908_0208d660
	mov r0, r4
	str r1, [r4, #0x98]
	mov r1, #0
	str r1, [r4, #0xb0]
	bl sub_02037ED4
	ldr r1, _02037AE0 ; =0x000033DE
	mov r0, #0
	strh r1, [r4, #0xa0]
	str r0, [r4, #0xac]
	mov r1, #0x16
	str r1, [r4, #0x8c]
	str r0, [r4, #0x90]
	ldrh r2, [r4, #0xa0]
	ldr lr, [r4, #0x8c]
	ldr r1, _02037AE4 ; =MAIN_BSS_0210CAA4
	and ip, r2, #0x1f
	mov r3, r2, asr #5
	mov r2, r2, asr #0xa
	str ip, [r1]
	and r3, r3, #0x1f
	str r3, [r1, #4]
	and r3, r2, #0x1f
	str r3, [r1, #8]
	ldr r2, _02037AE8 ; =MAIN_BSS_0210CA90
	ldr r1, _02037AEC ; =MAIN_BSS_0210CA8C
	str lr, [r2]
	str r0, [r1]
	add r2, r4, #0x68
	mov r1, r0
	arm_func_end sub_020379C8
_02037A88:
	str r1, [r2]
	add r0, r0, #1
	str r1, [r2, #4]
	cmp r0, #2
	add r2, r2, #0x10
	blt _02037A88
	ldr r0, _02037AF0 ; =0x00000199
	mov r1, #0x51
	str r0, [r4, #0x70]
	str r1, [r4, #0x74]
	rsb r0, r0, #0xcd
	str r0, [r4, #0x80]
	sub r1, r1, #0x79
	mov r0, r4
	str r1, [r4, #0x84]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02037ACC: .word PTR_LAB_0208d610
_02037AD0: .word ptr_FUN_02037fb0_0208d8f8
_02037AD4: .word sub_0203691C
_02037AD8: .word sub_0203735C
_02037ADC: .word ptr_FUN_02036908_0208d660
_02037AE0: .word 0x000033DE
_02037AE4: .word MAIN_BSS_0210CAA4
_02037AE8: .word MAIN_BSS_0210CA90
_02037AEC: .word MAIN_BSS_0210CA8C
_02037AF0: .word 0x00000199

	arm_func_start sub_02037AF4
sub_02037AF4: ; 0x02037AF4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4, #0x90]
	str r1, [sp]
	add r0, r0, #1
	str r0, [r4, #0x90]
	ldr r0, [r4, #0x94]
	cmp r0, #0
	beq _02037B38
	subs r0, r0, #1
	str r0, [r4, #0x94]
	bne _02037B38
	add r0, r4, #0x20
	bl sub_02036434
	add r0, r4, #0x3c
	bl sub_02036434
	arm_func_end sub_02037AF4
_02037B38:
	mvn r5, #0
	add r2, r5, #0x100000
	add r3, r5, #0x334
	ldr r6, _02037DCC ; =MAIN_BSS_0210CEC8
	ldr lr, _02037DD0 ; =0x00000666
	add r1, r4, #0x68
	mov r0, #0
	mov ip, r3
	str r2, [sp, #4]
	mov fp, r2
_02037B60:
	ldr r7, _02037DD4 ; =MAIN_BSS_0210CA9C
	ldr r2, [r1]
	ldr r8, [r7]
	ldr r7, [r1, #8]
	mov sb, r8, asr #0x1f
	mov sb, sb, lsl #0xc
	orr sb, sb, r8, lsr #20
	mov r8, r8, lsl #0xc
	mov r8, r8, lsr #0xc
	orr r8, r8, sb, lsl #20
	ldr sb, _02037DD8 ; =MAIN_BSS_0210CA84
	ldr sb, [sb]
	mla r8, r7, sb, r8
	sub r7, r2, r8
	ldr r2, [sp, #4]
	and r2, r7, r2
	str r2, [r1]
	ldr r7, _02037DD4 ; =MAIN_BSS_0210CA9C
	ldr r2, [r1, #4]
	ldr r8, [r7, #4]
	ldr r7, [r1, #0xc]
	mov sb, r8, asr #0x1f
	mov sb, sb, lsl #0xc
	orr sb, sb, r8, lsr #20
	mov r8, r8, lsl #0xc
	mov r8, r8, lsr #0xc
	orr r8, r8, sb, lsl #20
	ldr sb, _02037DD8 ; =MAIN_BSS_0210CA84
	ldr sb, [sb]
	mla r8, r7, sb, r8
	sub r2, r2, r8
	and r2, r2, fp
	str r2, [r1, #4]
	ldr r2, [r4, #0x90]
	tst r2, #1
	bne _02037D04
	ldr r2, [r1, #8]
	cmp r2, #0
	ldmia r6, {r2, r7, r8}
	mla r2, r7, r2, r8
	ble _02037C40
	str r2, [r6]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #3
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	add r2, r2, #1
	mov r8, r2, lsl #0xc
	umull sl, sb, r8, lr
	mov r7, r8, asr #0x1f
	mla sb, r7, lr, sb
	mov r7, sl, lsr #0xc
	orr r7, r7, sb, lsl #20
	mul r2, r7, r5
	b _02037C74
_02037C40:
	str r2, [r6]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #3
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	add r2, r2, #1
	mov r8, r2, lsl #0xc
	umull sl, sb, r8, lr
	mov r7, r8, asr #0x1f
	mla sb, r7, lr, sb
	mov r2, sl, lsr #0xc
	orr r2, r2, sb, lsl #20
_02037C74:
	str r2, [r1, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	ldmia r6, {r2, r7, r8}
	mla r2, r7, r2, r8
	bge _02037CCC
	str r2, [r6]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #3
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	add r2, r2, #1
	mov r8, r2, lsl #0xc
	umull sl, sb, r8, ip
	mov r7, r8, asr #0x1f
	mla sb, r7, ip, sb
	mov r7, sl, lsr #0xc
	orr r7, r7, sb, lsl #20
	mul r2, r7, r5
	str r2, [r1, #0xc]
	b _02037D04
_02037CCC:
	str r2, [r6]
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #3
	mov r2, r2, lsr #0x10
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	add r2, r2, #1
	mov r8, r2, lsl #0xc
	umull sl, sb, r8, r3
	mov r7, r8, asr #0x1f
	mla sb, r7, r3, sb
	mov r2, sl, lsr #0xc
	orr r2, r2, sb, lsl #20
	str r2, [r1, #0xc]
_02037D04:
	add r1, r1, #0x10
	add r0, r0, #1
	cmp r0, #2
	blt _02037B60
	ldr r1, [sp]
	mov r0, r4
	bl sub_02035334
	ldr r2, _02037DDC ; =MAIN_BSS_0210CA8C
	ldr r0, [r2]
	cmp r0, #0
	beq _02037D5C
	ldr r1, _02037DE0 ; =MAIN_BSS_0210CAA4
	ldr r0, _02037DE4 ; =MAIN_BSS_0210CA90
	ldr r5, [r1]
	ldmib r1, {r3, r6}
	orr r1, r5, r3, lsl #5
	orr r1, r1, r6, lsl #10
	strh r1, [r4, #0xa0]
	ldr r1, [r0]
	mov r0, #0
	str r1, [r4, #0x8c]
	str r0, [r2]
_02037D5C:
	ldr r0, [r4, #4]
	cmp r0, #3
	beq _02037D7C
	cmp r0, #4
	beq _02037D94
	cmp r0, #5
	beq _02037DA0
	b _02037DB8
_02037D7C:
	ldr r1, [r4, #0x8c]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0xac]
	b _02037DC0
_02037D94:
	ldr r0, [r4, #0x8c]
	str r0, [r4, #0xac]
	b _02037DC0
_02037DA0:
	ldr r1, [r4, #0x8c]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0xac]
	b _02037DC0
_02037DB8:
	mov r0, #0
	str r0, [r4, #0xac]
_02037DC0:
	ldr r0, [r4, #4]
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02037DCC: .word MAIN_BSS_0210CEC8
_02037DD0: .word 0x00000666
_02037DD4: .word MAIN_BSS_0210CA9C
_02037DD8: .word MAIN_BSS_0210CA84
_02037DDC: .word MAIN_BSS_0210CA8C
_02037DE0: .word MAIN_BSS_0210CAA4
_02037DE4: .word MAIN_BSS_0210CA90

	arm_func_start sub_02037DE8
sub_02037DE8: ; 0x02037DE8
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r2, [r5, #0xac]
	mov r4, r1
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl sub_020355B4
	ldr r1, [r5, #0x1c]
	mov r0, #0
	str r1, [r5, #0xa8]
	str r0, [r5, #0xb4]
	str r0, [r5, #0xb8]
	mov r0, #0x100000
	str r0, [r5, #0xbc]
	str r0, [r5, #0xc0]
	ldr r2, [r5, #0x6c]
	ldr r0, [r5, #0x68]
	add r1, r2, #0xff000
	str r0, [r5, #0xc4]
	str r2, [r5, #0xc8]
	add r0, r0, #0xff000
	str r0, [r5, #0xcc]
	add r0, r5, #0x20
	str r1, [r5, #0xd0]
	bl sub_020364DC
	add r0, r5, #0x98
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r1, [r5, #0x1c]
	mov r0, #0
	add r1, r1, #1
	str r1, [r5, #0xa8]
	str r0, [r5, #0xb4]
	str r0, [r5, #0xb8]
	mov r0, #0x100000
	str r0, [r5, #0xbc]
	str r0, [r5, #0xc0]
	ldr r2, [r5, #0x7c]
	ldr r0, [r5, #0x78]
	add r1, r2, #0xff000
	str r0, [r5, #0xc4]
	str r2, [r5, #0xc8]
	add r0, r0, #0xff000
	str r0, [r5, #0xcc]
	add r0, r5, #0x3c
	str r1, [r5, #0xd0]
	bl sub_020364DC
	add r0, r5, #0x98
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #8]
	blx r2
	ldr r0, _02037ED0 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02037ED0: .word 0x04000448
	arm_func_end sub_02037DE8

	arm_func_start sub_02037ED4
sub_02037ED4: ; 0x02037ED4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, _02037F14 ; =s_data_field_effect_suna01_ntft_0208d914
	ldr r2, _02037F18 ; =s_data_field_effect_suna01_ntfp_0208d934
	add r0, r4, #0x20
	mov r3, #2
	bl sub_020362EC
	ldr r1, _02037F14 ; =s_data_field_effect_suna01_ntft_0208d914
	ldr r2, _02037F18 ; =s_data_field_effect_suna01_ntfp_0208d934
	add r0, r4, #0x3c
	mov r3, #2
	bl sub_020362EC
	mov r0, #2
	str r0, [r4, #0x94]
	mov r0, #1
	ldmia sp!, {r4, pc}
	.align 2, 0
_02037F14: .word s_data_field_effect_suna01_ntft_0208d914
_02037F18: .word s_data_field_effect_suna01_ntfp_0208d934
	arm_func_end sub_02037ED4

	arm_func_start sub_02037F1C
sub_02037F1C: ; 0x02037F1C
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x20
	bl sub_02036488
	add r0, r4, #0x3c
	bl sub_02036488
	mov r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end sub_02037F1C

	arm_func_start sub_02037F3C
sub_02037F3C: ; 0x02037F3C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020354E0
	ldr r2, [r4, #0x8c]
	ldr r1, [r4, #0x18]
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [r4, #0xac]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02037F3C

	arm_func_start sub_02037F60
sub_02037F60: ; 0x02037F60
	stmdb sp!, {r4, lr}
	ldr r1, _02037FA0 ; =ptr_FUN_02037fb0_0208d8f8
	mov r4, r0
	str r1, [r4]
	bl sub_02037F1C
	add r0, r4, #0x98
	bl _ZN10CPrimitiveD2Ev
	ldr r3, _02037FA4 ; =sub_0203691C
	add r0, r4, #0x20
	mov r1, #2
	mov r2, #0x1c
	bl __cxa_vec_cleanup
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02037FA0: .word ptr_FUN_02037fb0_0208d8f8
_02037FA4: .word sub_0203691C
	arm_func_end sub_02037F60

	arm_func_start sub_02037FA8
sub_02037FA8: ; 0x02037FA8
	mov r0, #8
	bx lr
	arm_func_end sub_02037FA8

	arm_func_start sub_02037FB0
sub_02037FB0: ; 0x02037FB0
	stmdb sp!, {r4, lr}
	ldr r1, _02037FE8 ; =ptr_FUN_02037fb0_0208d8f8
	mov r4, r0
	str r1, [r4]
	bl sub_02037F1C
	add r0, r4, #0x98
	bl _ZN10CPrimitiveD2Ev
	ldr r3, _02037FEC ; =sub_0203691C
	add r0, r4, #0x20
	mov r1, #2
	mov r2, #0x1c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02037FE8: .word ptr_FUN_02037fb0_0208d8f8
_02037FEC: .word sub_0203691C
	arm_func_end sub_02037FB0

	arm_func_start sub_02037FF0
sub_02037FF0: ; 0x02037FF0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _02038014 ; =ptr_FUN_020368d8_0208d688
	mov r1, #0
	str r0, [r4]
	mov r0, r4
	str r1, [r4, #0x18]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02038014: .word ptr_FUN_020368d8_0208d688
	arm_func_end sub_02037FF0

	arm_func_start sub_02038018
sub_02038018: ; 0x02038018
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _0203814C ; =PTR_LAB_0208d610
	mov r4, r0
	str r1, [r4]
	mov r1, #4
	str r1, [r4, #0x1c]
	ldr r0, _02038150 ; =ptr_FUN_02038998_0208d97c
	mov r1, #0
	str r0, [r4]
	str r1, [r4, #0x20]
	str r1, [r4, #0x24]
	str r1, [r4, #0x28]
	ldr r0, _02038154 ; =DAT_0208d694
	str r1, [r4, #0x2c]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	str r1, [r4, #0x38]
	str r1, [r4, #0x3c]
	str r1, [r4, #0x40]
	str r1, [r4, #0x44]
	str r1, [r4, #0x48]
	str r0, [r4, #0x4c]
	str r1, [r4, #0x50]
	add r0, r4, #0x68
	str r1, [r4, #0x54]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _02038158 ; =ptr_FUN_02036908_0208d660
	mov r0, #0
	str r1, [r4, #0x68]
	str r0, [r4, #0x80]
	ldr ip, _0203815C ; =sub_020368D8
	ldr r3, _02038160 ; =sub_02037FF0
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	str ip, [sp]
	bl __cxa_vec_ctor
	mov r0, r4
	bl sub_0203884C
	mov r1, #0
	ldr r0, _02038164 ; =0x00007C14
	mov r3, r4
	mov r2, r1
	arm_func_end sub_02038018
_020380C8:
	strh r0, [r3, #0xac]
	add r1, r1, #1
	str r2, [r3, #0xb8]
	cmp r1, #0x10
	add r3, r3, #0x5c
	blt _020380C8
	mov r1, r2
_020380E4:
	add r0, r4, r2, lsl #1
	add r0, r0, #0x600
	add r2, r2, #1
	strh r1, [r0, #0x64]
	cmp r2, #3
	add r1, r1, #0x300
	blt _020380E4
	ldr r0, _02038168 ; =0x00007C1F
	mov ip, #0
	strh r0, [r4, #0x70]
	str ip, [r4, #0x7c]
	mov r0, #0x14
	str r0, [r4, #0x5c]
	ldr r0, _0203816C ; =MAIN_BSS_0210CAA4
	str ip, [r4, #0x60]
	mov r3, #0x1f
	str r3, [r0]
	str r3, [r0, #4]
	ldr r2, _02038170 ; =MAIN_BSS_0210CA90
	str r3, [r0, #8]
	ldr r1, _02038174 ; =MAIN_BSS_0210CA8C
	mov r0, r4
	str r3, [r2]
	str ip, [r1]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0203814C: .word PTR_LAB_0208d610
_02038150: .word ptr_FUN_02038998_0208d97c
_02038154: .word DAT_0208d694
_02038158: .word ptr_FUN_02036908_0208d660
_0203815C: .word sub_020368D8
_02038160: .word sub_02037FF0
_02038164: .word 0x00007C14
_02038168: .word 0x00007C1F
_0203816C: .word MAIN_BSS_0210CAA4
_02038170: .word MAIN_BSS_0210CA90
_02038174: .word MAIN_BSS_0210CA8C

	arm_func_start sub_02038178
sub_02038178: ; 0x02038178
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r4, r0
	ldr r0, [r4, #0x64]
	mov r5, r1
	cmp r0, #0
	beq _020381A4
	subs r0, r0, #1
	str r0, [r4, #0x64]
	bne _020381A4
	add r0, r4, #0x20
	bl sub_02036434
	arm_func_end sub_02038178
_020381A4:
	mov r0, r4
	mov r1, r5
	bl sub_02035334
	mov r1, #0
	ldr ip, _020382D4 ; =MAIN_BSS_0210CAA4
	ldr r3, _020382D8 ; =MAIN_BSS_0210CA90
	ldr lr, _020382DC ; =MAIN_BSS_0210CA8C
	mov r2, r4
	mov r0, r1
	mov r5, r1
_020381CC:
	ldr r6, [lr]
	cmp r6, #0
	beq _020381F8
	ldr r7, [ip]
	ldmib ip, {r6, r8}
	orr r6, r7, r6, lsl #5
	orr r6, r6, r8, lsl #10
	strh r6, [r2, #0xac]
	ldr r6, [r3]
	str r6, [r4, #0x5c]
	str r0, [lr]
_020381F8:
	ldr r6, [r4, #4]
	cmp r6, #3
	beq _02038218
	cmp r6, #4
	beq _02038230
	cmp r6, #5
	beq _0203823C
	b _02038254
_02038218:
	ldr r7, [r4, #0x5c]
	ldr r6, [r4, #0x18]
	mul r6, r7, r6
	mov r6, r6, asr #0xc
	str r6, [r2, #0xb8]
	b _02038258
_02038230:
	ldr r6, [r4, #0x5c]
	str r6, [r2, #0xb8]
	b _02038258
_0203823C:
	ldr r7, [r4, #0x5c]
	ldr r6, [r4, #0x18]
	mul r6, r7, r6
	mov r6, r6, asr #0xc
	str r6, [r2, #0xb8]
	b _02038258
_02038254:
	str r5, [r2, #0xb8]
_02038258:
	add r1, r1, #1
	cmp r1, #0x10
	add r2, r2, #0x5c
	blt _020381CC
	ldr r0, [r4, #4]
	cmp r0, #3
	beq _02038288
	cmp r0, #4
	beq _020382A0
	cmp r0, #5
	beq _020382AC
	b _020382C4
_02038288:
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x7c]
	b _020382CC
_020382A0:
	ldr r0, [r4, #0x60]
	str r0, [r4, #0x7c]
	b _020382CC
_020382AC:
	ldr r1, [r4, #0x60]
	ldr r0, [r4, #0x18]
	mul r0, r1, r0
	mov r0, r0, asr #0xc
	str r0, [r4, #0x7c]
	b _020382CC
_020382C4:
	mov r0, #0
	str r0, [r4, #0x7c]
_020382CC:
	ldr r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_020382D4: .word MAIN_BSS_0210CAA4
_020382D8: .word MAIN_BSS_0210CA90
_020382DC: .word MAIN_BSS_0210CA8C

	arm_func_start sub_020382E0
sub_020382E0: ; 0x020382E0
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
	arm_func_end sub_020382E0
_02038320:
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
_0203835C:
	ldr r1, [sl, #0x1c]
	mov r0, r6, lsl #0xc
	add r1, r1, #2
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
	bl sub_020364DC
	add r4, r4, #1
	add r5, r5, #0x5c
	add r6, r6, #0x40
	add r7, r7, #0x10000
	add r8, r8, #0x10
	cmp r4, #4
	blt _0203835C
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
	blt _02038320
	add r2, sl, #0x600
	ldrh r0, [r2, #0x64]
	mov r3, #0x60000
	rsb r3, r3, #0
	add r0, r0, #0x800
	strh r0, [r2, #0x64]
	ldrh r0, [r2, #0x66]
	ldr r5, _02038844 ; =FX_SinCosTable_
	add r4, r3, #0x18000
	sub r0, r0, #0xc00
	strh r0, [r2, #0x66]
	ldrh r6, [r2, #0x68]
	mov r0, sl
	mov r1, #0
	sub r6, r6, #0x600
	strh r6, [r2, #0x68]
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
	bl sub_020388A0
	add r0, sl, #0x600
	ldrh r1, [r0, #0x68]
	mov r0, #0x60000
	ldr r2, _02038844 ; =FX_SinCosTable_
	mov r1, r1, asr #4
	mov r4, r1, lsl #1
	mov r1, r4, lsl #1
	ldrsh r3, [r2, r1]
	add r1, r4, #1
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
	bl sub_020388A0
	add r0, sl, #0x600
	ldrh r0, [r0, #0x64]
	ldr r2, _02038844 ; =FX_SinCosTable_
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
	bl sub_020388A0
	add r0, sl, #0x600
	ldrh r1, [r0, #0x66]
	ldr r2, _02038844 ; =FX_SinCosTable_
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
	bl sub_020388A0
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
	ldr r3, _02038844 ; =FX_SinCosTable_
	ldrsh r4, [r3, r4]
	mov r3, r4, asr #0x1f
	mov r3, r3, lsl #0xf
	orr r3, r3, r4, lsr #17
	mov r4, r4, lsl #0xf
	mov r4, r4, lsr #0xc
	orr r4, r4, r3, lsl #20
	sub r3, r4, #0x48000
	bl sub_020388A0
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
	ldr r3, _02038844 ; =FX_SinCosTable_
	ldrsh r4, [r3, r4]
	mov r3, r4, asr #0x1f
	mov r3, r3, lsl #0xf
	orr r3, r3, r4, lsr #17
	mov r4, r4, lsl #0xf
	mov r4, r4, lsr #0xc
	orr r4, r4, r3, lsl #20
	rsb r3, r4, #0x48000
	bl sub_020388A0
	mov r0, sl
	mov r1, #4
	add r2, sl, #0x600
	ldrh r2, [r2, #0x64]
	ldr r4, _02038844 ; =FX_SinCosTable_
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
	bl sub_020388A0
	add r0, sl, #0x600
	ldrh r1, [r0, #0x66]
	ldr r2, _02038844 ; =FX_SinCosTable_
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
	bl sub_020388A0
	ldr r1, [sp]
	mov r0, sl
	bl sub_020355B4
	add r5, sl, #0xa4
	mov r4, #0
_020387BC:
	mov r0, r5
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
	add r4, r4, #1
	cmp r4, #0x10
	add r5, r5, #0x5c
	blt _020387BC
	ldr r0, [sl, #0x7c]
	cmp r0, #0
	beq _02038830
	ldr r1, [sl, #0x1c]
	mov r0, #0
	add r1, r1, #3
	str r1, [sl, #0x78]
	str r0, [sl, #0x84]
	str r0, [sl, #0x88]
	mov r0, #0x104000
	str r0, [sl, #0x8c]
	mov r1, #0xc8000
	add r0, sl, #0x3c
	str r1, [sl, #0x90]
	bl sub_020364DC
	add r0, sl, #0x68
	ldr r2, [r0]
	ldr r1, [sp]
	ldr r2, [r2, #8]
	blx r2
_02038830:
	ldr r0, _02038848 ; =0x04000448
	mov r1, #0
	str r1, [r0]
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02038844: .word FX_SinCosTable_
_02038848: .word 0x04000448

	arm_func_start sub_0203884C
sub_0203884C: ; 0x0203884C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, _02038878 ; =s_data_field_effect_dokarimo03_ntf_0208d998
	ldr r2, _0203887C ; =s_data_field_effect_dokarimo03_ntf_0208d9bc
	add r0, r4, #0x20
	mov r3, #4
	bl sub_020362EC
	mov r0, #2
	str r0, [r4, #0x64]
	mov r0, #1
	ldmia sp!, {r4, pc}
	.align 2, 0
_02038878: .word s_data_field_effect_dokarimo03_ntf_0208d998
_0203887C: .word s_data_field_effect_dokarimo03_ntf_0208d9bc
	arm_func_end sub_0203884C

	arm_func_start sub_02038880
sub_02038880: ; 0x02038880
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #0x20
	bl sub_02036488
	add r0, r4, #0x3c
	bl sub_02036488
	mov r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end sub_02038880

	arm_func_start sub_020388A0
sub_020388A0: ; 0x020388A0
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
	arm_func_end sub_020388A0

	arm_func_start sub_020388E8
sub_020388E8: ; 0x020388E8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020354E0
	mov ip, r4
	mov r3, #0
	arm_func_end sub_020388E8
_020388FC:
	ldr r2, [r4, #0x5c]
	ldr r1, [r4, #0x18]
	add r3, r3, #1
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [ip, #0xb8]
	cmp r3, #0x10
	add ip, ip, #0x5c
	blt _020388FC
	ldr r2, [r4, #0x60]
	ldr r1, [r4, #0x18]
	mul r1, r2, r1
	mov r1, r1, asr #0xc
	str r1, [r4, #0x7c]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02038938
sub_02038938: ; 0x02038938
	stmdb sp!, {r4, lr}
	ldr r1, _02038988 ; =ptr_FUN_02038998_0208d97c
	mov r4, r0
	str r1, [r4]
	bl sub_02038880
	ldr r3, _0203898C ; =sub_020368D8
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	add r0, r4, #0x68
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c
	bl sub_02036488
	add r0, r4, #0x20
	bl sub_02036488
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02038988: .word ptr_FUN_02038998_0208d97c
_0203898C: .word sub_020368D8
	arm_func_end sub_02038938

	arm_func_start sub_02038990
sub_02038990: ; 0x02038990
	mov r0, #9
	bx lr
	arm_func_end sub_02038990

	arm_func_start sub_02038998
sub_02038998: ; 0x02038998
	stmdb sp!, {r4, lr}
	ldr r1, _020389E0 ; =ptr_FUN_02038998_0208d97c
	mov r4, r0
	str r1, [r4]
	bl sub_02038880
	ldr r3, _020389E4 ; =sub_020368D8
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	add r0, r4, #0x68
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c
	bl sub_02036488
	add r0, r4, #0x20
	bl sub_02036488
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_020389E0: .word ptr_FUN_02038998_0208d97c
_020389E4: .word sub_020368D8
	arm_func_end sub_02038998

	arm_func_start sub_020389E8
sub_020389E8: ; 0x020389E8
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, _02038AE4 ; =PTR_LAB_0208d610
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
	ldr r0, _02038AEC ; =DAT_0208d694
	str r2, [r5, #0x2c]
	str r0, [r5, #0x30]
	str r2, [r5, #0x34]
	add r0, r5, #0x44
	mov r6, r1
	str r2, [r5, #0x38]
	bl _ZN10CPrimitiveC2Ev
	ldr r0, _02038AF0 ; =ptr_FUN_02036908_0208d660
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
	arm_func_end sub_020389E8
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
	ldr r0, _02038AF8 ; =MAIN_BSS_0210CAA4
	and r3, r1, #0x1f
	mov r2, r1, asr #5
	mov r1, r1, asr #0xa
	str r3, [r0]
	and r2, r2, #0x1f
	str r2, [r0, #4]
	and r1, r1, #0x1f
	ldr r2, _02038AFC ; =MAIN_BSS_0210CA90
	str r1, [r0, #8]
	ldr r1, _02038B00 ; =MAIN_BSS_0210CA8C
	mov r0, r5
	str r4, [r2]
	str ip, [r1]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02038AE4: .word PTR_LAB_0208d610
_02038AE8: .word ptr_FUN_02038cd4_0208da08
_02038AEC: .word DAT_0208d694
_02038AF0: .word ptr_FUN_02036908_0208d660
_02038AF4: .word 0x00007FE0
_02038AF8: .word MAIN_BSS_0210CAA4
_02038AFC: .word MAIN_BSS_0210CA90
_02038B00: .word MAIN_BSS_0210CA8C

	arm_func_start sub_02038B04
sub_02038B04: ; 0x02038B04
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02035334
	ldr r2, _02038BB8 ; =MAIN_BSS_0210CA8C
	ldr r0, [r2]
	cmp r0, #0
	beq _02038B4C
	ldr r1, _02038BBC ; =MAIN_BSS_0210CAA4
	ldr r0, _02038BC0 ; =MAIN_BSS_0210CA90
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
_02038BB8: .word MAIN_BSS_0210CA8C
_02038BBC: .word MAIN_BSS_0210CAA4
_02038BC0: .word MAIN_BSS_0210CA90

	arm_func_start sub_02038BC4
sub_02038BC4: ; 0x02038BC4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r2, [r5, #0x58]
	mov r4, r1
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl sub_020355B4
	ldr r1, [r5, #0x1c]
	mov r0, #0
	str r1, [r5, #0x54]
	str r0, [r5, #0x60]
	str r0, [r5, #0x64]
	mov r0, #0x100000
	str r0, [r5, #0x68]
	str r0, [r5, #0x6c]
	add r0, r5, #0x20
	bl sub_020364DC
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
	bl sub_02036488
	mov r0, #1
	ldmia sp!, {r3, pc}
	arm_func_end sub_02038C5C

	arm_func_start sub_02038C70
sub_02038C70: ; 0x02038C70
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020354E0
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
	bl sub_02036488
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
	bl sub_02036488
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02038D00: .word ptr_FUN_02038cd4_0208da08
	arm_func_end sub_02038CD4

	arm_func_start sub_02038D04
sub_02038D04: ; 0x02038D04
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, _02038DCC ; =PTR_LAB_0208d610
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
	ldr r0, _02038DD4 ; =DAT_0208d694
	str r2, [r5, #0x3cc]
	str r0, [r5, #0x3d0]
	str r2, [r5, #0x3d4]
	add r0, r5, #0x3dc
	mov r4, r1
	str r2, [r5, #0x3d8]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _02038DD8 ; =ptr_FUN_02036908_0208d660
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
	ldr r2, _02038DE0 ; =MAIN_BSS_0210CAA4
	ldr r1, _02038DE4 ; =MAIN_BSS_0210CA90
	and ip, r0, #0x1f
	mov r3, r0, asr #5
	mov r0, r0, asr #0xa
	str ip, [r2]
	and r3, r3, #0x1f
	str r3, [r2, #4]
	and r3, r0, #0x1f
	str r3, [r2, #8]
	ldr r0, _02038DE8 ; =MAIN_BSS_0210CA8C
	str lr, [r1]
	str r6, [r0]
	mov r0, r5
	str r4, [r5, #0x41c]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02038DCC: .word PTR_LAB_0208d610
_02038DD0: .word ptr_FUN_02039ddc_0208da78
_02038DD4: .word DAT_0208d694
_02038DD8: .word ptr_FUN_02036908_0208d660
_02038DDC: .word 0x00002A52
_02038DE0: .word MAIN_BSS_0210CAA4
_02038DE4: .word MAIN_BSS_0210CA90
_02038DE8: .word MAIN_BSS_0210CA8C
	arm_func_end sub_02038D04

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
	bl sub_02036434
	arm_func_end sub_02038DEC
_02038E18:
	mov r0, r4
	mov r1, r5
	bl sub_02035334
	ldr r2, _020394B0 ; =MAIN_BSS_0210CA8C
	ldr r0, [r2]
	cmp r0, #0
	beq _02038E64
	ldr r1, _020394B4 ; =MAIN_BSS_0210CAA4
	add r0, r4, #0x300
	ldr r5, [r1]
	ldmib r1, {r3, r6}
	orr r1, r5, r3, lsl #5
	orr r3, r1, r6, lsl #10
	strh r3, [r0, #0xe4]
	ldr r1, _020394B8 ; =MAIN_BSS_0210CA90
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
	ldr r5, _020394C0 ; =MAIN_BSS_0210CA84
	ldr ip, _020394C4 ; =MAIN_BSS_0210CA9C
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
	ldr r7, _020394C0 ; =MAIN_BSS_0210CA84
	ldr r5, _020394C4 ; =MAIN_BSS_0210CA9C
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
	ldr r0, _020394C0 ; =MAIN_BSS_0210CA84
	ldr r0, [r0]
	bl _f_itof
	mov r1, r0
	ldr r0, _020394C8 ; =0xBDCCCCCD
	bl _f_mul
	mov r1, r0
	ldr r0, _020394CC ; =0x45800000
	bl _f_mul
	bl _f_ftoi
	ldr r2, _020394C4 ; =MAIN_BSS_0210CA9C
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
_020394B0: .word MAIN_BSS_0210CA8C
_020394B4: .word MAIN_BSS_0210CAA4
_020394B8: .word MAIN_BSS_0210CA90
_020394BC: .word MAIN_BSS_0210CEC8
_020394C0: .word MAIN_BSS_0210CA84
_020394C4: .word MAIN_BSS_0210CA9C
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
	bl sub_020355B4
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
	bl sub_020364DC
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
	bl sub_02007AA4
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
	bl sub_02035FE8
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
	bl sub_020362EC
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
	bl sub_02036488
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
	bl sub_020354E0
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
	bl sub_02036488
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
	bl sub_02036488
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

	arm_func_start sub_02039E20
sub_02039E20: ; 0x02039E20
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
	bl sub_02007AA4
	mov r1, #0
	str r1, [r4, #0x2c]
	ldr r0, _0203A008 ; =PTR_LAB_0208da9c
	str r1, [r4, #0x30]
	str r0, [r4]
	arm_func_end sub_02039E20
_02039E60:
	mov r0, r4
	mov r1, #0
	str r4, [sl, #0x660]
	bl sub_02035FE8
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
	bl sub_02035334
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
	ldr fp, _0203A600 ; =MAIN_BSS_0210CA9C
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
_0203A600: .word MAIN_BSS_0210CA9C

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
	ldr r3, _0203A708 ; =sub_02035C8C
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
_0203A708: .word sub_02035C8C
	arm_func_end sub_0203A6CC

	arm_func_start sub_0203A70C
sub_0203A70C: ; 0x0203A70C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	bl sub_020354E0
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
	ldr r3, _0203A768 ; =sub_02035C8C
	add r0, r4, #0x20
	mov r1, #0x20
	mov r2, #0x2c
	bl __cxa_vec_cleanup
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203A764: .word ptr_FUN_0203a734_0208db24
_0203A768: .word sub_02035C8C
	arm_func_end sub_0203A734

	arm_func_start sub_0203A76C
sub_0203A76C: ; 0x0203A76C
	stmdb sp!, {r4, lr}
	ldr r1, _0203A838 ; =PTR_LAB_0208d610
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
	ldr r0, _0203A840 ; =DAT_0208d694
	str r1, [r4, #0x2c]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	add r0, r4, #0x4c
	str r1, [r4, #0x38]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _0203A844 ; =ptr_FUN_02036908_0208d660
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
	ldr r0, _0203A848 ; =MAIN_BSS_0210CAA4
	and r3, r1, #0x1f
	mov r2, r1, asr #5
	mov r1, r1, asr #0xa
	str r3, [r0]
	and r2, r2, #0x1f
	str r2, [r0, #4]
	and r2, r1, #0x1f
	ldr r1, _0203A84C ; =MAIN_BSS_0210CA90
	str r2, [r0, #8]
	ldr r0, _0203A850 ; =MAIN_BSS_0210CA8C
	str ip, [r1]
	str lr, [r0]
	str lr, [r4, #0x44]
	mov r1, #0x1e
	mov r0, r4
	str r1, [r4, #0x48]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203A838: .word PTR_LAB_0208d610
_0203A83C: .word ptr_FUN_0203aa14_0208db68
_0203A840: .word DAT_0208d694
_0203A844: .word ptr_FUN_02036908_0208d660
_0203A848: .word MAIN_BSS_0210CAA4
_0203A84C: .word MAIN_BSS_0210CA90
_0203A850: .word MAIN_BSS_0210CA8C
	arm_func_end sub_0203A76C

	arm_func_start sub_0203A854
sub_0203A854: ; 0x0203A854
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl sub_02035334
	ldr r2, _0203A928 ; =MAIN_BSS_0210CA8C
	ldr r0, [r2]
	cmp r0, #0
	beq _0203A8A0
	ldr r1, _0203A92C ; =MAIN_BSS_0210CAA4
	ldr r0, _0203A930 ; =MAIN_BSS_0210CA90
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
_0203A928: .word MAIN_BSS_0210CA8C
_0203A92C: .word MAIN_BSS_0210CAA4
_0203A930: .word MAIN_BSS_0210CA90

	arm_func_start sub_0203A934
sub_0203A934: ; 0x0203A934
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r2, [r5, #0x60]
	mov r4, r1
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl sub_020355B4
	ldr r1, [r5, #0x1c]
	mov r0, #0
	str r1, [r5, #0x5c]
	str r0, [r5, #0x68]
	str r0, [r5, #0x6c]
	mov r0, #0x100000
	str r0, [r5, #0x70]
	str r0, [r5, #0x74]
	add r0, r5, #0x20
	bl sub_020364DC
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
	bl sub_02036488
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
	bl sub_02036488
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203AA40: .word ptr_FUN_0203aa14_0208db68
	arm_func_end sub_0203AA14

	arm_func_start sub_0203AA44
sub_0203AA44: ; 0x0203AA44
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0203AB08 ; =PTR_LAB_0208d610
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
	ldr r0, _0203AB10 ; =DAT_0208d694
	str r1, [r4, #0x544]
	str r0, [r4, #0x548]
	add r5, r4, #0x154
	str r1, [r4, #0x54c]
	add r0, r5, #0x400
	str r1, [r4, #0x550]
	bl _ZN10CPrimitiveC2Ev
	ldr r1, _0203AB14 ; =ptr_FUN_02036908_0208d660
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
	ldr r0, _0203AB1C ; =MAIN_BSS_0210CAA4
	ldr r2, _0203AB20 ; =MAIN_BSS_0210CA90
	and r5, r1, #0x1f
	mov r3, r1, asr #5
	mov r1, r1, asr #0xa
	str r5, [r0]
	and r3, r3, #0x1f
	str r3, [r0, #4]
	and r3, r1, #0x1f
	str r3, [r0, #8]
	ldr r1, _0203AB24 ; =MAIN_BSS_0210CA8C
	mov r0, r4
	str ip, [r2]
	str lr, [r1]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203AB08: .word PTR_LAB_0208d610
_0203AB0C: .word ptr_FUN_0203b314_0208dbb4
_0203AB10: .word DAT_0208d694
_0203AB14: .word ptr_FUN_02036908_0208d660
_0203AB18: .word 0x00007E10
_0203AB1C: .word MAIN_BSS_0210CAA4
_0203AB20: .word MAIN_BSS_0210CA90
_0203AB24: .word MAIN_BSS_0210CA8C
	arm_func_end sub_0203AA44

	arm_func_start sub_0203AB28
sub_0203AB28: ; 0x0203AB28
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	bl sub_02035334
	ldr r2, _0203ADBC ; =MAIN_BSS_0210CA8C
	ldr r0, [r2]
	cmp r0, #0
	beq _0203AB74
	ldr r1, _0203ADC0 ; =MAIN_BSS_0210CAA4
	add r0, r4, #0x500
	ldr r5, [r1]
	ldmib r1, {r3, r6}
	orr r1, r5, r3, lsl #5
	orr r3, r1, r6, lsl #10
	strh r3, [r0, #0x5c]
	ldr r1, _0203ADC4 ; =MAIN_BSS_0210CA90
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
	ldr lr, _0203ADCC ; =MAIN_BSS_0210CA84
	ldr ip, _0203ADD0 ; =MAIN_BSS_0210CEC8
	ldr r3, _0203ADD4 ; =MAIN_BSS_0210CA9C
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
_0203ADBC: .word MAIN_BSS_0210CA8C
_0203ADC0: .word MAIN_BSS_0210CAA4
_0203ADC4: .word MAIN_BSS_0210CA90
_0203ADC8: .word DAT_0208db84
_0203ADCC: .word MAIN_BSS_0210CA84
_0203ADD0: .word MAIN_BSS_0210CEC8
_0203ADD4: .word MAIN_BSS_0210CA9C

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
	bl sub_020355B4
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
	bl sub_020364DC
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
	bl sub_02007AA4
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
	bl sub_02035FE8
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
	bl sub_02036488
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
	bl sub_020354E0
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
	bl sub_02036488
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
	bl sub_02036488
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203B348: .word ptr_FUN_0203b314_0208dbb4
	arm_func_end sub_0203B314

	arm_func_start sub_0203B34C
sub_0203B34C: ; 0x0203B34C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0203B47C ; =PTR_LAB_0208d610
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
	ldr r0, _0203B484 ; =DAT_0208d694
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
	ldr r1, _0203B488 ; =ptr_FUN_02036908_0208d660
	mov r0, #0
	str r1, [r4, #0x68]
	str r0, [r4, #0x80]
	ldr ip, _0203B48C ; =sub_020368D8
	ldr r3, _0203B490 ; =sub_02037FF0
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
	arm_func_end sub_0203B34C
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
	ldr r0, _0203B494 ; =MAIN_BSS_0210CAA4
	str r1, [r4, #0x60]
	mov r3, #0x1f
	str r3, [r0]
	str r3, [r0, #4]
	ldr r2, _0203B498 ; =MAIN_BSS_0210CA90
	str r3, [r0, #8]
	ldr r1, _0203B49C ; =MAIN_BSS_0210CA8C
	mov r0, r4
	str r3, [r2]
	str ip, [r1]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203B47C: .word PTR_LAB_0208d610
_0203B480: .word ptr_FUN_0203bcc4_0208dbf8
_0203B484: .word DAT_0208d694
_0203B488: .word ptr_FUN_02036908_0208d660
_0203B48C: .word sub_020368D8
_0203B490: .word sub_02037FF0
_0203B494: .word MAIN_BSS_0210CAA4
_0203B498: .word MAIN_BSS_0210CA90
_0203B49C: .word MAIN_BSS_0210CA8C

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
	bl sub_02036434
	arm_func_end sub_0203B4A0
_0203B4CC:
	mov r0, r4
	mov r1, r5
	bl sub_02035334
	mov r1, #0
	ldr ip, _0203B5FC ; =MAIN_BSS_0210CAA4
	ldr r3, _0203B600 ; =MAIN_BSS_0210CA90
	ldr lr, _0203B604 ; =MAIN_BSS_0210CA8C
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
_0203B5FC: .word MAIN_BSS_0210CAA4
_0203B600: .word MAIN_BSS_0210CA90
_0203B604: .word MAIN_BSS_0210CA8C

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
	bl sub_020364DC
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
	bl sub_020355B4
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
	bl sub_020364DC
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
	bl sub_020362EC
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
	bl sub_02036488
	add r0, r4, #0x3c
	bl sub_02036488
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
	bl sub_020354E0
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
	ldr r3, _0203BCB8 ; =sub_020368D8
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	add r0, r4, #0x68
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c
	bl sub_02036488
	add r0, r4, #0x20
	bl sub_02036488
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BCB4: .word ptr_FUN_0203bcc4_0208dbf8
_0203BCB8: .word sub_020368D8
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
	ldr r3, _0203BD10 ; =sub_020368D8
	add r0, r4, #0xa4
	mov r1, #0x10
	mov r2, #0x5c
	bl __cxa_vec_cleanup
	add r0, r4, #0x68
	bl _ZN10CPrimitiveD2Ev
	add r0, r4, #0x3c
	bl sub_02036488
	add r0, r4, #0x20
	bl sub_02036488
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BD0C: .word ptr_FUN_0203bcc4_0208dbf8
_0203BD10: .word sub_020368D8
	arm_func_end sub_0203BCC4

	arm_func_start _ZN17CFieldActorScriptC2Ei
_ZN17CFieldActorScriptC2Ei: ; 0x0203BD14
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0203BD58 ; =ptr_FUN_0203bda4_0208dc98
	mov r5, r0
	str r2, [r5]
	mov r4, r1
	mov r0, #0
	str r0, [r5, #0x2c]
	str r0, [r5, #0x30]
	mov r2, #2
	mov r0, r4, lsl #2
	mov r1, #4
	str r2, [r5, #4]
	bl _Z23Heap_AllocWithAlignmentmm
	str r0, [r5, #0x30]
	mov r0, r5
	str r4, [r5, #0x34]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203BD58: .word ptr_FUN_0203bda4_0208dc98
	arm_func_end _ZN17CFieldActorScriptC2Ei

	arm_func_start _ZN17CFieldActorScriptC1Ei
_ZN17CFieldActorScriptC1Ei: ; 0x0203BD5C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, _0203BDA0 ; =ptr_FUN_0203bda4_0208dc98
	mov r5, r0
	str r2, [r5]
	mov r4, r1
	mov r0, #0
	str r0, [r5, #0x2c]
	str r0, [r5, #0x30]
	mov r2, #2
	mov r0, r4, lsl #2
	mov r1, #4
	str r2, [r5, #4]
	bl _Z23Heap_AllocWithAlignmentmm
	str r0, [r5, #0x30]
	mov r0, r5
	str r4, [r5, #0x34]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203BDA0: .word ptr_FUN_0203bda4_0208dc98
	arm_func_end _ZN17CFieldActorScriptC1Ei

	arm_func_start _ZN17CFieldActorScriptD1Ev
_ZN17CFieldActorScriptD1Ev: ; 0x0203BDA4
	stmdb sp!, {r4, lr}
	ldr r1, _0203BDD4 ; =ptr_FUN_0203bda4_0208dc98
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _0203BDCC
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r4, #0x30]
	arm_func_end _ZN17CFieldActorScriptD1Ev
_0203BDCC:
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BDD4: .word ptr_FUN_0203bda4_0208dc98

	arm_func_start _ZN17CFieldActorScriptD0Ev
_ZN17CFieldActorScriptD0Ev: ; 0x0203BDD8
	stmdb sp!, {r4, lr}
	ldr r1, _0203BE10 ; =ptr_FUN_0203bda4_0208dc98
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _0203BE00
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r4, #0x30]
	arm_func_end _ZN17CFieldActorScriptD0Ev
_0203BE00:
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BE10: .word ptr_FUN_0203bda4_0208dc98

	arm_func_start _ZN17CFieldActorScriptD2Ev
_ZN17CFieldActorScriptD2Ev: ; 0x0203BE14
	stmdb sp!, {r4, lr}
	ldr r1, _0203BE44 ; =ptr_FUN_0203bda4_0208dc98
	mov r4, r0
	str r1, [r4]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _0203BE3C
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r4, #0x30]
	arm_func_end _ZN17CFieldActorScriptD2Ev
_0203BE3C:
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BE44: .word ptr_FUN_0203bda4_0208dc98

	arm_func_start _ZN17CFieldActorScript12sub_0203BE48EP11CFieldActorPKc
_ZN17CFieldActorScript12sub_0203BE48EP11CFieldActorPKc: ; 0x0203BE48
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4, #0x2c]
	mov r6, r1
	mov r5, r2
	cmp r0, #0
	beq _0203BEDC
	ldr r1, [r4, #0x30]
	ldr r2, [r4, #0x34]
	add r0, r4, #8
	bl sub_02044B48
	cmp r6, #0
	beq _0203BE8C
	ldr r0, [r4, #0xc]
	sub r0, r0, #4
	str r0, [r4, #0xc]
	str r6, [r0]
	arm_func_end _ZN17CFieldActorScript12sub_0203BE48EP11CFieldActorPKc
_0203BE8C:
	cmp r5, #0
	beq _0203BEC0
	ldr r1, [r4, #0x2c]
	mov r2, r5
	add r0, r4, #8
	bl sub_02045A18
	mvn r1, #0
	cmp r0, r1
	bne _0203BED0
	ldr r0, _0203BEF4 ; =s_not_found_func_FieldActor_cpp_0208dcf0
	bl LogError
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
_0203BEC0:
	ldr r0, _0203BEF8 ; =s_null_func_name_FieldActor_cpp_0208dd10
	bl LogError
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
_0203BED0:
	mov r0, #8
	str r0, [r4, #4]
	b _0203BEEC
_0203BEDC:
	ldr r0, _0203BEFC ; =s_m_pScriptBlock_NULL_by_FieldA_0208dd30
	bl LogError
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
_0203BEEC:
	mov r0, #1
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0203BEF4: .word s_not_found_func_FieldActor_cpp_0208dcf0
_0203BEF8: .word s_null_func_name_FieldActor_cpp_0208dd10
_0203BEFC: .word s_m_pScriptBlock_NULL_by_FieldA_0208dd30

	arm_func_start _ZN17CFieldActorScript12sub_0203BF00Ev
_ZN17CFieldActorScript12sub_0203BF00Ev: ; 0x0203BF00
	stmdb sp!, {r4, lr}
	mov r4, r0
	add r0, r4, #8
	bl sub_02044B84
	mov r0, #2
	str r0, [r4, #4]
	mov r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17CFieldActorScript12sub_0203BF00Ev

	arm_func_start sub_0203BF20
sub_0203BF20: ; 0x0203BF20
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, _0203BF3C ; =0x000FFFFF
	add r0, r4, #8
	bl sub_02044C9C
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BF3C: .word 0x000FFFFF
	arm_func_end sub_0203BF20

	arm_func_start _ZN11CFieldActorC2Ev
_ZN11CFieldActorC2Ev: ; 0x0203BF40
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	ldr r1, _0203BFCC ; =ptr_FUN_0203c068_0208dcb0
	mov r4, r0
	str r1, [r4]
	mvn ip, #0
	str ip, [r4, #0x50]
	mov r3, #0
	str r3, [r4, #0xdc]
	str r3, [r4, #0xc]
	mov r1, #2
	strb r1, [r4, #0x20]
	str r3, [r4, #0x78]
	strb r3, [r4, #0x7c]
	mov r1, #0x10
	strb r1, [r4, #0x7d]
	strb r3, [r4, #0x7e]
	str r3, [r4, #0x94]
	mov r2, #6
	ldr r1, _0203BFD0 ; =DAT_02084d58
	str r2, [r4, #0x98]
	ldr r2, [r1]
	ldr r1, [r1, #4]
	str r2, [sp]
	str r2, [r4, #0x70]
	str r1, [r4, #0x74]
	str r3, [r4, #0xc8]
	str r3, [r4, #0x54]
	str ip, [r4, #0xd0]
	str r1, [sp, #4]
	strh r3, [r4, #0xd8]
	bl sub_0203C310
	mov r0, r4
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203BFCC: .word ptr_FUN_0203c068_0208dcb0
_0203BFD0: .word DAT_02084d58
	arm_func_end _ZN11CFieldActorC2Ev

	arm_func_start _ZN11CFieldActorC1Ev
_ZN11CFieldActorC1Ev: ; 0x0203BFD4
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	ldr r1, _0203C060 ; =ptr_FUN_0203c068_0208dcb0
	mov r4, r0
	str r1, [r4]
	mvn ip, #0
	str ip, [r4, #0x50]
	mov r3, #0
	str r3, [r4, #0xdc]
	str r3, [r4, #0xc]
	mov r1, #2
	strb r1, [r4, #0x20]
	str r3, [r4, #0x78]
	strb r3, [r4, #0x7c]
	mov r1, #0x10
	strb r1, [r4, #0x7d]
	strb r3, [r4, #0x7e]
	str r3, [r4, #0x94]
	mov r2, #6
	ldr r1, _0203C064 ; =DAT_02084d58
	str r2, [r4, #0x98]
	ldr r2, [r1]
	ldr r1, [r1, #4]
	str r2, [sp]
	str r2, [r4, #0x70]
	str r1, [r4, #0x74]
	str r3, [r4, #0xc8]
	str r3, [r4, #0x54]
	str ip, [r4, #0xd0]
	str r1, [sp, #4]
	strh r3, [r4, #0xd8]
	bl sub_0203C310
	mov r0, r4
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203C060: .word ptr_FUN_0203c068_0208dcb0
_0203C064: .word DAT_02084d58
	arm_func_end _ZN11CFieldActorC1Ev

	arm_func_start _ZN11CFieldActorD1Ev
_ZN11CFieldActorD1Ev: ; 0x0203C068
	stmdb sp!, {r4, lr}
	ldr r1, _0203C0CC ; =ptr_FUN_0203c068_0208dcb0
	mov r4, r0
	str r1, [r4]
	bl sub_0203C560
	ldr r0, [r4, #0xdc]
	cmp r0, #0
	beq _0203C0A0
	beq _0203C098
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end _ZN11CFieldActorD1Ev
_0203C098:
	mov r0, #0
	str r0, [r4, #0xdc]
_0203C0A0:
	ldrh r1, [r4, #0xd8]
	cmp r1, #0
	ldrne r0, _0203C0D0 ; =MAIN_BSS_0210CA60
	ldrne r0, [r0]
	cmpne r0, #0
	beq _0203C0BC
	bl ov0_021430D8
_0203C0BC:
	mov r0, r4
	bl sub_02041C1C
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203C0CC: .word ptr_FUN_0203c068_0208dcb0
_0203C0D0: .word MAIN_BSS_0210CA60

	arm_func_start _ZN11CFieldActorD0Ev
_ZN11CFieldActorD0Ev: ; 0x0203C0D4
	stmdb sp!, {r4, lr}
	ldr r1, _0203C140 ; =ptr_FUN_0203c068_0208dcb0
	mov r4, r0
	str r1, [r4]
	bl sub_0203C560
	ldr r0, [r4, #0xdc]
	cmp r0, #0
	beq _0203C10C
	beq _0203C104
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end _ZN11CFieldActorD0Ev
_0203C104:
	mov r0, #0
	str r0, [r4, #0xdc]
_0203C10C:
	ldrh r1, [r4, #0xd8]
	cmp r1, #0
	ldrne r0, _0203C144 ; =MAIN_BSS_0210CA60
	ldrne r0, [r0]
	cmpne r0, #0
	beq _0203C128
	bl ov0_021430D8
_0203C128:
	mov r0, r4
	bl sub_02041C1C
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203C140: .word ptr_FUN_0203c068_0208dcb0
_0203C144: .word MAIN_BSS_0210CA60

	arm_func_start _ZN11CFieldActorD2Ev
_ZN11CFieldActorD2Ev: ; 0x0203C148
	stmdb sp!, {r4, lr}
	ldr r1, _0203C1AC ; =ptr_FUN_0203c068_0208dcb0
	mov r4, r0
	str r1, [r4]
	bl sub_0203C560
	ldr r0, [r4, #0xdc]
	cmp r0, #0
	beq _0203C180
	beq _0203C178
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end _ZN11CFieldActorD2Ev
_0203C178:
	mov r0, #0
	str r0, [r4, #0xdc]
_0203C180:
	ldrh r1, [r4, #0xd8]
	cmp r1, #0
	ldrne r0, _0203C1B0 ; =MAIN_BSS_0210CA60
	ldrne r0, [r0]
	cmpne r0, #0
	beq _0203C19C
	bl ov0_021430D8
_0203C19C:
	mov r0, r4
	bl sub_02041C1C
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203C1AC: .word ptr_FUN_0203c068_0208dcb0
_0203C1B0: .word MAIN_BSS_0210CA60

	arm_func_start _ZN11CFieldActor12sub_0203C1B4EPv
_ZN11CFieldActor12sub_0203C1B4EPv: ; 0x0203C1B4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0xdc]
	mov r4, r1
	cmp r0, #0
	bne _0203C1F0
	mov r0, #0x38
	bl _Znwm
	cmp r0, #0
	beq _0203C1E4
	mov r1, #0x40
	bl _ZN17CFieldActorScriptC1Ei
	arm_func_end _ZN11CFieldActor12sub_0203C1B4EPv
_0203C1E4:
	str r0, [r5, #0xdc]
	str r4, [r0, #0x2c]
	b _0203C1F4
_0203C1F0:
	str r4, [r0, #0x2c]
_0203C1F4:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN11CFieldActor12sub_0203C1FCEP17CFieldActorScriptPv
_ZN11CFieldActor12sub_0203C1FCEP17CFieldActorScriptPv: ; 0x0203C1FC
	ldr r3, [r0, #0xdc]
	cmp r3, #0
	bne _0203C218
	cmp r1, #0
	strne r1, [r0, #0xdc]
	strne r2, [r1, #0x2c]
	bne _0203C224
	arm_func_end _ZN11CFieldActor12sub_0203C1FCEP17CFieldActorScriptPv
_0203C218:
	str r2, [r3, #0x2c]
	mov r0, #0
	bx lr
_0203C224:
	mov r0, #1
	bx lr

	arm_func_start _ZN11CFieldActor12sub_0203C22CEPKc
_ZN11CFieldActor12sub_0203C22CEPKc: ; 0x0203C22C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0xdc]
	mov r4, r1
	cmp r0, #0
	cmpne r4, #0
	beq _0203C280
	ldr r3, [r0]
	mov r1, r5
	ldr r3, [r3, #8]
	mov r2, r4
	blx r3
	cmp r0, #0
	beq _0203C278
	mov r1, r4
	add r0, r5, #0x7f
	bl strcpy
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN11CFieldActor12sub_0203C22CEPKc
_0203C278:
	mov r0, #0
	strb r0, [r5, #0x7f]
_0203C280:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN11CFieldActor12sub_0203C288Ev
_ZN11CFieldActor12sub_0203C288Ev: ; 0x0203C288
	stmdb sp!, {r3, lr}
	mov r1, #0
	strb r1, [r0, #0x7f]
	ldr r0, [r0, #0xdc]
	cmp r0, #0
	beq _0203C2B0
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r1, r0
	arm_func_end _ZN11CFieldActor12sub_0203C288Ev
_0203C2B0:
	mov r0, r1
	ldmia sp!, {r3, pc}

	arm_func_start sub_0203C2B8
sub_0203C2B8: ; 0x0203C2B8
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #0xc]
	cmp r1, #0
	ldrne r0, [r0, #0xdc]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	bl sub_0203BF20
	ldmia sp!, {r3, pc}
	arm_func_end sub_0203C2B8

	arm_func_start _ZN11CFieldActor12sub_0203C2D8Ev
_ZN11CFieldActor12sub_0203C2D8Ev: ; 0x0203C2D8
	stmdb sp!, {r3, lr}
	mov r1, r0
	ldr r0, [r1, #0xdc]
	cmp r0, #0
	ldrnesb r2, [r1, #0x7f]
	cmpne r2, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r3, [r0]
	add r2, r1, #0x7f
	ldr r3, [r3, #8]
	blx r3
	mov r0, #1
	ldmia sp!, {r3, pc}
	arm_func_end _ZN11CFieldActor12sub_0203C2D8Ev

	arm_func_start sub_0203C310
sub_0203C310: ; 0x0203C310
	stmdb sp!, {r4, r5, r6, lr}
	mov r1, #0
	mov r4, r0
	str r1, [r4, #4]
	movs r5, r1
	str r1, [r4, #8]
	ldrne r6, [r5, #0xc]
	cmpne r6, #0
	beq _0203C360
	add r0, r6, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	add r0, r6, #0xc
	mov r1, r5
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r5, #0xc]
	ldr r1, [r0, #0xc4]
	cmp r1, #0
	movne r0, r5
	strne r0, [r1, #0x18]
	strne r0, [r1, #0x1c]
	arm_func_end sub_0203C310
_0203C360:
	mov r1, #0
	str r1, [r4, #0x18]
	str r1, [r4, #0x1c]
	mov r0, r4
	str r1, [r4, #0x10]
	ldr r2, [r0]
	ldr r2, [r2, #0x30]
	blx r2
	mov r3, #0
	str r3, [r4, #0x5c]
	str r3, [r4, #0x60]
	sub r0, r3, #0x1000
	str r0, [r4, #0x64]
	str r0, [r4, #0x68]
	str r3, [r4, #0x6c]
	strb r3, [r4, #0x7f]
	str r3, [r4, #0x94]
	str r3, [r4, #0x9c]
	str r3, [r4, #0xa0]
	str r3, [r4, #0xa4]
	str r3, [r4, #0xa8]
	strh r3, [r4, #0xac]
	strh r3, [r4, #0xae]
	ldr r1, [r4, #4]
	ldr r0, _0203C414 ; =0x00000109
	orr r1, r1, #8
	str r1, [r4, #4]
	str r0, [r4, #0xb4]
	mov r0, #0x18
	str r0, [r4, #0xb8]
	mov r2, #0x10
	strb r2, [r4, #0x7d]
	mov r0, #4
	strb r3, [r4, #0x7e]
	mov r1, #1
	str r1, [r4, #0x90]
	strb r3, [r4, #0xbc]
	strb r3, [r4, #0xbd]
	strb r2, [r4, #0xbe]
	mov r1, #0xa
	strb r1, [r4, #0xbf]
	strb r0, [r4, #0xd4]
	sub r0, r0, #0xe
	strh r0, [r4, #0xd6]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0203C414: .word 0x00000109

	arm_func_start sub_0203C418
sub_0203C418: ; 0x0203C418
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #8
	mov r4, r0
	mov r8, r1
	mov r7, r2
	mov r5, r3
	ldr r6, [sp, #0x20]
	bl sub_0203C560
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0203C44C
	bl sub_020404BC
	arm_func_end sub_0203C418
_0203C44C:
	str r0, [r4, #8]
	ldr r0, [sp, #0x24]
	str r6, [sp]
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r1, r8
	mov r2, r7
	mov r3, r5
	bl sub_02040530
	movs r5, r0
	beq _0203C4B0
	mov r2, #0
	mov r0, #1
_0203C480:
	tst r6, r0, lsl r2
	mov r1, r0, lsl r2
	beq _0203C4A4
	mov r0, r4
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	b _0203C4B0
_0203C4A4:
	add r2, r2, #1
	cmp r2, #0x1d
	blt _0203C480
_0203C4B0:
	mov r0, r5
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start sub_0203C4BC
sub_0203C4BC: ; 0x0203C4BC
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #8
	mov r4, r0
	mov r8, r1
	mov r7, r2
	mov r5, r3
	ldr r6, [sp, #0x20]
	bl sub_0203C560
	mov r0, #0x18
	bl _Znwm
	cmp r0, #0
	beq _0203C4F0
	bl sub_020404BC
	arm_func_end sub_0203C4BC
_0203C4F0:
	str r0, [r4, #8]
	ldr r0, [sp, #0x24]
	str r6, [sp]
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r1, r8
	mov r2, r7
	mov r3, r5
	bl sub_020405B4
	movs r5, r0
	beq _0203C554
	mov r2, #0
	mov r0, #1
_0203C524:
	tst r6, r0, lsl r2
	mov r1, r0, lsl r2
	beq _0203C548
	mov r0, r4
	ldr r3, [r0]
	mov r2, #0
	ldr r3, [r3, #0x38]
	blx r3
	b _0203C554
_0203C548:
	add r2, r2, #1
	cmp r2, #0x1d
	blt _0203C524
_0203C554:
	mov r0, r5
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start sub_0203C560
sub_0203C560: ; 0x0203C560
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	beq _0203C584
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_0203C560
_0203C584:
	mov r0, #0
	str r0, [r4, #8]
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203C590
sub_0203C590: ; 0x0203C590
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x28
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r2
	tst r0, #1
	addne sp, sp, #0x28
	ldmneia sp!, {r3, r4, r5, pc}
	cmp r1, #0
	ldrne r2, [r5, #8]
	cmpne r2, #0
	beq _0203C64C
	ldr r0, [r2, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	str r0, [r2, #4]
	ldr r0, [r5, #4]
	tst r0, #0x100
	beq _0203C614
	tst r0, #0x1000
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	bne _0203C604
	add r0, r1, #0x10
	ldr r1, [r5, #8]
	bl _ZN17UnkClass_0211E3FC12sub_0200912CEP11CDrawObject
	b _0203C64C
	arm_func_end sub_0203C590
_0203C604:
	add r0, r1, #0x24
	ldr r1, [r5, #8]
	bl _ZN17UnkClass_0211E3FC12sub_0200912CEP11CDrawObject
	b _0203C64C
_0203C614:
	tst r0, #0x1000
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	ldr r0, [r5, #0x14]
	bne _0203C63C
	add r0, r1, r0, lsl #2
	ldr r1, [r5, #8]
	bl _ZN17UnkClass_0211E3FC12sub_0200912CEP11CDrawObject
	b _0203C64C
_0203C63C:
	add r0, r0, #5
	add r0, r1, r0, lsl #2
	ldr r1, [r5, #8]
	bl _ZN17UnkClass_0211E3FC12sub_0200912CEP11CDrawObject
_0203C64C:
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0203C680
	ldr r3, [r0, #0xc]
	cmp r3, #0
	moveq ip, #0
	beq _0203C684
	ldr r2, [r3, #0x8c]
	ldr r1, [r3, #0xa0]
	ldr r3, [r3, #0xb0]
	add r1, r2, r1
	add ip, r3, r1
	b _0203C684
_0203C680:
	mov ip, #0
_0203C684:
	ldr r1, [r5, #0x90]
	cmp r1, #0
	cmpne r4, #0
	addeq sp, sp, #0x28
	ldmeqia sp!, {r3, r4, r5, pc}
	cmp ip, #0
	addlt sp, sp, #0x28
	ldmltia sp!, {r3, r4, r5, pc}
	cmp ip, #0x60000
	addge sp, sp, #0x28
	ldmgeia sp!, {r3, r4, r5, pc}
	cmp r0, #0
	beq _0203C6CC
	ldr r1, [r0, #0xc]
	cmp r1, #0
	ldrne r3, [r1, #0x20]
	moveq r3, #0
	b _0203C6D0
_0203C6CC:
	mov r3, #0
_0203C6D0:
	cmp r0, #0
	beq _0203C718
	ldr r2, [r0, #0xc]
	cmp r2, #0
	beq _0203C710
	ldr r1, [r2, #0x1a8]
	tst r1, #4
	movne r1, #1
	moveq r1, #0
	cmp r1, #0
	addne r1, r2, #0x100
	ldrnesh r1, [r1, #0xd0]
	moveq r1, #0
	mov r1, r1, lsl #0x10
	mov r2, r1, asr #0x10
	b _0203C71C
_0203C710:
	mov r2, #0
	b _0203C71C
_0203C718:
	mov r2, #0
_0203C71C:
	ldrsb r1, [r5, #0xbc]
	cmp r0, #0
	add r1, r3, r1, lsl #12
	add r1, r1, r2, lsl #12
	str r1, [sp, #8]
	beq _0203C748
	ldr r1, [r0, #0xc]
	cmp r1, #0
	ldrne r3, [r1, #0x24]
	moveq r3, #0
	b _0203C74C
_0203C748:
	mov r3, #0
_0203C74C:
	cmp r0, #0
	beq _0203C794
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _0203C78C
	ldr r0, [r1, #0x1a8]
	tst r0, #4
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	addne r0, r1, #0x100
	ldrnesh r0, [r0, #0xd2]
	moveq r0, #0
	mov r0, r0, lsl #0x10
	mov lr, r0, asr #0x10
	b _0203C798
_0203C78C:
	mov lr, #0
	b _0203C798
_0203C794:
	mov lr, #0
_0203C798:
	ldrsb r2, [r5, #0xbd]
	ldrb r1, [r5, #0xbe]
	ldrb r0, [r5, #0xbf]
	add r2, r3, r2, lsl #12
	add r3, r2, lr, lsl #12
	mov r2, r1, lsl #0xc
	mov r1, r0, lsl #0xc
	add r0, sp, #8
	add lr, sp, #0x18
	str r3, [sp, #0xc]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	ldmia r0, {r0, r1, r2, r3}
	stmia lr, {r0, r1, r2, r3}
	cmp ip, #0
	ble _0203C820
	ldr r1, [sp, #0x20]
	rsb r2, ip, #0x60000
	ldr r0, [sp, #0x24]
	smull r3, ip, r1, r2
	smull r1, r2, r0, r2
	mov lr, r3, lsr #0xc
	mov r3, r1, lsr #0xc
	orr lr, lr, ip, lsl #20
	ldr r1, _0203C878 ; =0x2AAAAAAB
	orr r3, r3, r2, lsl #20
	smull r0, ip, r1, lr
	mov r0, lr, lsr #0x1f
	add ip, r0, ip, asr #4
	smull r0, r2, r1, r3
	mov r0, r3, lsr #0x1f
	add r2, r0, r2, asr #4
	str ip, [sp, #0x20]
	str r2, [sp, #0x24]
_0203C820:
	ldr r0, [r5, #4]
	tst r0, #0x100
	add r0, sp, #0x18
	beq _0203C854
	sub r5, sp, #8
	ldmia r0, {r0, r1, r2, r3}
	stmia r5, {r0, r1, r2, r3}
	mov r0, r4
	mov r1, #4
	ldmia r5, {r2, r3}
	bl sub_020419D8
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, pc}
_0203C854:
	sub ip, sp, #8
	ldmia r0, {r0, r1, r2, r3}
	stmia ip, {r0, r1, r2, r3}
	ldr r1, [r5, #0x14]
	mov r0, r4
	ldmia ip, {r2, r3}
	bl sub_020419D8
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203C878: .word 0x2AAAAAAB

	arm_func_start sub_0203C87C
sub_0203C87C: ; 0x0203C87C
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	sub sp, sp, #8
	mov r8, r0
	str r1, [r8, #0x6c]
	ldr r1, [r8, #8]
	cmp r1, #0
	addeq sp, sp, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	bl sub_0203D320
	mov r0, r8
	bl sub_0203D394
	mov r0, r8
	bl sub_0203CDB0
	mov r0, r8
	bl sub_0203CCD4
	ldr r0, [r8, #8]
	bl sub_02040740
	ldr r0, [r8, #0x54]
	cmp r0, #0
	ldrne r0, [r8, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0203C8E0
	bl _ZN6CActor12sub_02012C4CEv
	arm_func_end sub_0203C87C
_0203C8E0:
	ldr r1, [r8, #8]
	mov r4, #0
	cmp r1, #0
	beq _0203C904
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r6, [r0, #0x20]
	moveq r6, r4
	b _0203C908
_0203C904:
	mov r6, r4
_0203C908:
	cmp r1, #0
	beq _0203C924
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r7, [r0, #0x24]
	moveq r7, #0
	b _0203C928
_0203C924:
	mov r7, #0
_0203C928:
	ldr r2, [r8, #0x6c]
	cmp r2, #0
	beq _0203C964
	ldr r1, [r8, #0x14]
	ldr r0, [r2, #0x24]
	cmp r1, r0
	ldrlt r0, [r2, #0x30]
	ldrlt r0, [r0, r1, lsl #2]
	movge r0, #0
	cmp r0, #0
	beq _0203C964
	mov r1, r6
	mov r2, r7
	bl _ZN23CFieldMapLayerAttribute12GetCellAtPosEll
	mov r4, r0
_0203C964:
	ldr r0, [r8, #0xc8]
	cmp r0, #0
	movne r1, #0
	moveq r1, r4
	mov r0, r8
	bl sub_0203D890
	ldr r1, [r8, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	ldrne r0, [r2, #0x1d8]
	moveq r0, #3
	cmp r0, #1
	beq _0203CA34
	ldr r0, [r8, #0x58]
	mov r0, r0, asr #0x18
	tst r0, #0xff
	addne sp, sp, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, pc}
	cmp r1, #0
	beq _0203C9C4
	cmp r2, #0
	ldrneb r0, [r2, #0xc0]
	moveq r0, #0
	b _0203C9C8
_0203C9C4:
	mov r0, #0
_0203C9C8:
	cmp r0, #7
	beq _0203C9F8
	cmp r1, #0
	beq _0203C9E8
	cmp r2, #0
	ldrneb r0, [r2, #0xc0]
	moveq r0, #0
	b _0203C9EC
_0203C9E8:
	mov r0, #0
_0203C9EC:
	cmp r0, #8
	addne sp, sp, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, pc}
_0203C9F8:
	cmp r1, #0
	beq _0203CA24
	cmp r2, #0
	beq _0203CA1C
	ldrh r0, [r2, #4]
	tst r0, #8
	movne r0, #1
	moveq r0, #0
	b _0203CA28
_0203CA1C:
	mov r0, #0
	b _0203CA28
_0203CA24:
	mov r0, #0
_0203CA28:
	cmp r0, #0
	addeq sp, sp, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
_0203CA34:
	ldr r0, _0203CCB8 ; =MAIN_BSS_0210CA6C
	mov r5, #0
	ldr r0, [r0]
	cmp r0, #0
	beq _0203CA58
	ldr r1, _0203CCBC ; =MAIN_BSS_020B26A0
	ldrh r1, [r1, #0x1a]
	bl sub_02041D80
	mov r5, r0
_0203CA58:
	cmp r5, #0
	addeq sp, sp, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, [r8, #8]
	cmp r0, #0
	beq _0203CA98
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0203CA90
	ldrh r0, [r0, #4]
	tst r0, #8
	movne r0, #1
	moveq r0, #0
	b _0203CA9C
_0203CA90:
	mov r0, #0
	b _0203CA9C
_0203CA98:
	mov r0, #0
_0203CA9C:
	cmp r0, #0
	addeq sp, sp, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, [r8, #0x78]
	cmp r0, #0
	ldrneb r0, [r8, #0x7d]
	cmpne r0, #0
	beq _0203CB1C
	ldr r1, _0203CCC0 ; =DAT_0208d58c
	mov r0, #0x3c
	ldrh r1, [r1]
	bl _s32_div_f
	ldrb r1, [r8, #0x7e]
	add r1, r1, r0
	strb r1, [r8, #0x7e]
	ldrb r0, [r8, #0x7d]
	and r1, r1, #0xff
	cmp r1, r0
	blo _0203CB1C
	ldr r0, _0203CCC4 ; =MAIN_BSS_0210CA60
	ldr r0, [r0]
	cmp r0, #0
	beq _0203CB14
	ldr r2, [r8, #0x14]
	mov r1, r4
	str r2, [sp]
	mov r2, r6
	mov r3, r7
	str r5, [sp, #4]
	bl ov0_021431A4
_0203CB14:
	mov r0, #0
	strb r0, [r8, #0x7e]
_0203CB1C:
	ldr r0, [r8, #0xb8]
	cmp r0, #0
	addle sp, sp, #8
	ldmleia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r1, _0203CCC0 ; =DAT_0208d58c
	mov r0, #0x3c
	ldrh r1, [r1]
	bl _s32_div_f
	ldrb r1, [r8, #0x7c]
	add r1, r1, r0
	strb r1, [r8, #0x7c]
	ldr r0, [r8, #0xb8]
	and r1, r1, #0xff
	cmp r1, r0
	addlt sp, sp, #8
	ldmltia sp!, {r4, r5, r6, r7, r8, pc}
	mov r0, #0
	strb r0, [r8, #0x7c]
	ldr r0, [r8, #0x78]
	cmp r0, #0
	addeq sp, sp, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, _0203CCC8 ; =MAIN_BSS_0210CA74
	ldr r0, [r0]
	tst r0, #1
	addne sp, sp, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r1, [r8, #0xb4]
	cmp r1, #0
	addlt sp, sp, #8
	ldmltia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, _0203CCCC ; =0x00000109
	cmp r1, r0
	bne _0203CC90
	cmp r4, #0x16
	addls pc, pc, r4, lsl #2
	b _0203CC90
_0203CBB0: ; jump table
	b _0203CC0C ; case 0
	b _0203CC14 ; case 1
	b _0203CC1C ; case 2
	b _0203CC24 ; case 3
	b _0203CC2C ; case 4
	b _0203CC34 ; case 5
	b _0203CC3C ; case 6
	b _0203CC44 ; case 7
	b _0203CC4C ; case 8
	b _0203CC54 ; case 9
	b _0203CC5C ; case 10
	b _0203CC64 ; case 11
	b _0203CC6C ; case 12
	b _0203CC74 ; case 13
	b _0203CC7C ; case 14
	b _0203CC84 ; case 15
	b _0203CC84 ; case 16
	b _0203CC84 ; case 17
	b _0203CC84 ; case 18
	b _0203CC8C ; case 19
	b _0203CC8C ; case 20
	b _0203CC8C ; case 21
	b _0203CC8C ; case 22
_0203CC0C:
	ldrsh r1, [r5, #8]
	b _0203CC90
_0203CC14:
	ldrsh r1, [r5, #0xc]
	b _0203CC90
_0203CC1C:
	ldrsh r1, [r5, #0x10]
	b _0203CC90
_0203CC24:
	ldrsh r1, [r5, #0x14]
	b _0203CC90
_0203CC2C:
	ldrsh r1, [r5, #0x18]
	b _0203CC90
_0203CC34:
	ldrsh r1, [r5, #0x1c]
	b _0203CC90
_0203CC3C:
	ldrsh r1, [r5, #0x20]
	b _0203CC90
_0203CC44:
	ldrsh r1, [r5, #0x24]
	b _0203CC90
_0203CC4C:
	ldrsh r1, [r5, #0x28]
	b _0203CC90
_0203CC54:
	ldrsh r1, [r5, #0x2c]
	b _0203CC90
_0203CC5C:
	ldrsh r1, [r5, #0x30]
	b _0203CC90
_0203CC64:
	ldrsh r1, [r5, #0x34]
	b _0203CC90
_0203CC6C:
	ldrsh r1, [r5, #0x38]
	b _0203CC90
_0203CC74:
	ldrsh r1, [r5, #0x3c]
	b _0203CC90
_0203CC7C:
	ldrsh r1, [r5, #0x40]
	b _0203CC90
_0203CC84:
	ldrsh r1, [r5, #0x44]
	b _0203CC90
_0203CC8C:
	ldrsh r1, [r5, #0x48]
_0203CC90:
	cmp r1, #0
	addlt sp, sp, #8
	ldmltia sp!, {r4, r5, r6, r7, r8, pc}
	ldr r0, _0203CCD0 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0203CCB8: .word MAIN_BSS_0210CA6C
_0203CCBC: .word MAIN_BSS_020B26A0
_0203CCC0: .word DAT_0208d58c
_0203CCC4: .word MAIN_BSS_0210CA60
_0203CCC8: .word MAIN_BSS_0210CA74
_0203CCCC: .word 0x00000109
_0203CCD0: .word s_game

	arm_func_start sub_0203CCD4
sub_0203CCD4: ; 0x0203CCD4
	stmdb sp!, {r3, lr}
	ldr r1, [r0, #0x94]
	cmp r1, #0
	subgt r1, r1, #1
	strgt r1, [r0, #0x94]
	ldr r2, [r0, #8]
	cmp r2, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r0, #4]
	tst r1, #8
	ldmeqia sp!, {r3, pc}
	ldr r2, [r2, #0xc]
	cmp r2, #0
	ldrne r3, [r2, #0x1d8]
	moveq r3, #3
	cmp r2, #0
	beq _0203CD2C
	ldr r1, [r2, #0xc]
	cmp r1, #0
	movne r1, #1
	moveq r1, #0
	b _0203CD30
	arm_func_end sub_0203CCD4
_0203CD2C:
	mov r1, #0
_0203CD30:
	cmp r1, #0
	beq _0203CD80
	cmp r3, #1
	beq _0203CD78
	mov r3, #0
	strb r3, [r0, #0x7c]
	strb r3, [r0, #0x7e]
	ldr r1, [r0, #0x94]
	cmp r1, #0
	bgt _0203CD78
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #1
	strne r1, [r2, #0x1dc]
	strneb r3, [r2, #0x1e1]
	ldr r1, [r0, #0x98]
	str r1, [r0, #0x94]
_0203CD78:
	bl sub_0203D2F4
	ldmia sp!, {r3, pc}
_0203CD80:
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r0, #0x94]
	cmp r1, #0
	ldmgtia sp!, {r3, pc}
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1dc]
	strneb r1, [r2, #0x1e1]
	ldr r1, [r0, #0x98]
	str r1, [r0, #0x94]
	ldmia sp!, {r3, pc}

	arm_func_start sub_0203CDB0
sub_0203CDB0: ; 0x0203CDB0
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x20
	ldr r1, [r0, #0x5c]
	mov r2, #0
	cmp r1, #1
	addne sp, sp, #0x20
	mov r3, r2
	ldmneia sp!, {r4, pc}
	ldr lr, [r0, #0x60]
	mov r1, lr, asr #0x18
	and r1, r1, #0xff
	cmp r1, #6
	addls pc, pc, r1, lsl #2
	b _0203CE30
_0203CDE8: ; jump table
	b _0203CE04 ; case 0
	b _0203CE10 ; case 1
	b _0203CE1C ; case 2
	b _0203CE30 ; case 3
	b _0203CE28 ; case 4
	b _0203CE28 ; case 5
	b _0203CE28 ; case 6
	arm_func_end sub_0203CDB0
_0203CE04:
	ldr r1, _0203CF30 ; =MAIN_BSS_0210CA48
	ldr r3, [r1]
	b _0203CE30
_0203CE10:
	ldr r1, _0203CF34 ; =MAIN_BSS_0210CA5C
	ldr r2, [r1]
	b _0203CE30
_0203CE1C:
	ldr r1, _0203CF38 ; =MAIN_BSS_0210CA50
	ldr r2, [r1]
	b _0203CE30
_0203CE28:
	ldr r1, _0203CF3C ; =MAIN_BSS_0210CA4C
	ldr r2, [r1]
_0203CE30:
	cmp r2, #0
	beq _0203CE74
	ldr r4, [r2, #4]
	mov ip, #0
	cmp r4, #0
	ble _0203CE70
	ldr r2, [r2, #8]
_0203CE4C:
	ldr r3, [r2, ip, lsl #2]
	cmp r3, #0
	beq _0203CE64
	ldr r1, [r3, #0x58]
	cmp lr, r1
	beq _0203CE74
_0203CE64:
	add ip, ip, #1
	cmp ip, r4
	blt _0203CE4C
_0203CE70:
	mov r3, #0
_0203CE74:
	cmp r3, #0
	beq _0203CF20
	ldr r1, [r3, #8]
	cmp r1, #0
	beq _0203CEC8
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0203CEA8
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	b _0203CEC0
_0203CEA8:
	mov r1, #0
	add r2, sp, #8
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
_0203CEC0:
	add r3, sp, #0x10
	b _0203CEE4
_0203CEC8:
	mov r1, #0
	add r2, sp, #0
	add r3, sp, #0x10
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
_0203CEE4:
	ldr r0, [r0, #8]
	ldr r2, [r3]
	ldr r1, [r3, #4]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	str r1, [sp, #0x1c]
	str r2, [sp, #0x18]
	add r1, sp, #0x18
	cmpne r0, #0
	addeq sp, sp, #0x20
	ldmeqia sp!, {r4, pc}
	ldmia r1, {r1, r2}
	bl _ZN6CActor12sub_02012894E7Point2D
	add sp, sp, #0x20
	ldmia sp!, {r4, pc}
_0203CF20:
	mov r1, #0
	str r1, [r0, #0x5c]
	add sp, sp, #0x20
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203CF30: .word MAIN_BSS_0210CA48
_0203CF34: .word MAIN_BSS_0210CA5C
_0203CF38: .word MAIN_BSS_0210CA50
_0203CF3C: .word MAIN_BSS_0210CA4C

	arm_func_start sub_0203CF40
sub_0203CF40: ; 0x0203CF40
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x1c
	add ip, sp, #0xc
	mov r5, r3
	mov r7, r0
	mov r6, r2
	ldmia r1, {r0, r1, r2, r3}
	stmia ip, {r0, r1, r2, r3}
	tst r5, #0x10
	mov r4, #0
	bne _0203CFB0
	ldr r0, _0203D104 ; =MAIN_BSS_0210CA7C
	ldr r0, [r0]
	cmp r0, #0
	beq _0203CFB0
	add r2, sp, #4
	str r2, [sp]
	ldr r3, [r7, #0x14]
	mov r1, ip
	mov r2, r6
	bl sub_0203F7F4
	cmp r0, #0
	beq _0203CFB0
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	mov r4, #1
	arm_func_end sub_0203CF40
_0203CFB0:
	tst r5, #8
	bne _0203CFFC
	ldr r0, _0203D108 ; =MAIN_BSS_0210CA50
	ldr r0, [r0]
	cmp r0, #0
	beq _0203CFFC
	add r2, sp, #4
	str r2, [sp]
	ldr r3, [r7, #0x14]
	add r1, sp, #0xc
	mov r2, r6
	bl sub_0203F7F4
	cmp r0, #0
	beq _0203CFFC
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	mov r4, #1
_0203CFFC:
	ldr r2, [r7, #0x6c]
	cmp r2, #0
	beq _0203D0E0
	ldr r1, [r7, #0x14]
	ldr r0, [r2, #0x24]
	cmp r1, r0
	ldrlt r0, [r2, #0x2c]
	ldrlt r0, [r0, r1, lsl #2]
	movge r0, #0
	cmp r0, #0
	beq _0203D078
	mov ip, #3
	tst r5, #0x20
	orrne ip, ip, #4
	tst r5, #1
	add r1, sp, #0xc
	add r3, sp, #4
	mov r2, r6
	beq _0203D054
	str ip, [sp]
	bl _ZN23CFieldMapLayerCollision9SweepFineEP11PointPair2DlP7Point2Dm
	b _0203D05C
_0203D054:
	str ip, [sp]
	bl _ZN23CFieldMapLayerCollision5SweepEP11PointPair2DlP7Point2Dm
_0203D05C:
	cmp r0, #0
	beq _0203D078
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	mov r4, #1
_0203D078:
	tst r5, #2
	bne _0203D0E0
	tst r5, #4
	beq _0203D0E0
	ldr r1, [r7, #0x6c]
	ldr r2, [r7, #0x14]
	ldr r0, [r1, #0x24]
	cmp r2, r0
	ldrlt r0, [r1, #0x30]
	ldrlt r0, [r0, r2, lsl #2]
	movge r0, #0
	cmp r0, #0
	beq _0203D0E0
	ldr r3, _0203D10C ; =0x00804000
	add r5, sp, #4
	add r1, sp, #0xc
	mov r2, r6
	str r5, [sp]
	bl _ZN23CFieldMapLayerAttribute5SweepEP11PointPair2DlmP7Point2D
	cmp r0, #0
	beq _0203D0E0
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	str r1, [sp, #0x14]
	str r0, [sp, #0x18]
	mov r4, #1
_0203D0E0:
	cmp r4, #0
	beq _0203D0F8
	ldr r0, [sp, #0x14]
	str r0, [r7, #0x64]
	ldr r0, [sp, #0x18]
	str r0, [r7, #0x68]
_0203D0F8:
	mov r0, r4
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_0203D104: .word MAIN_BSS_0210CA7C
_0203D108: .word MAIN_BSS_0210CA50
_0203D10C: .word 0x00804000

	arm_func_start sub_0203D110
sub_0203D110: ; 0x0203D110
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	ldr r4, [sp, #0x28]
	mov r6, r0
	mov r5, r3
	tst r4, #0x10
	bne _0203D16C
	ldr r0, _0203D2E8 ; =MAIN_BSS_0210CA7C
	ldr r0, [r0]
	cmp r0, #0
	beq _0203D16C
	ldr r2, [r6, #0x14]
	add r1, sp, #0x1c
	str r2, [sp]
	ldmia r1, {r1, r2}
	bl sub_02040158
	cmp r0, #0
	addne sp, sp, #4
	movne r0, #1
	ldmneia sp!, {r3, r4, r5, r6, lr}
	addne sp, sp, #0x10
	bxne lr
	arm_func_end sub_0203D110
_0203D16C:
	tst r4, #8
	bne _0203D1B4
	ldr r0, _0203D2EC ; =MAIN_BSS_0210CA50
	ldr r0, [r0]
	cmp r0, #0
	beq _0203D1B4
	ldr r2, [r6, #0x14]
	add r1, sp, #0x1c
	str r2, [sp]
	mov r3, r5
	ldmia r1, {r1, r2}
	bl sub_02040158
	cmp r0, #0
	addne sp, sp, #4
	movne r0, #1
	ldmneia sp!, {r3, r4, r5, r6, lr}
	addne sp, sp, #0x10
	bxne lr
_0203D1B4:
	ldr r2, [r6, #0x6c]
	cmp r2, #0
	beq _0203D2D4
	ldr r1, [r6, #0x14]
	ldr r0, [r2, #0x24]
	cmp r1, r0
	ldrlt r0, [r2, #0x2c]
	ldrlt r0, [r0, r1, lsl #2]
	movge r0, #0
	cmp r0, #0
	beq _0203D248
	mov r2, #3
	tst r4, #0x20
	orrne r2, r2, #4
	tst r4, #1
	add r1, sp, #0x1c
	mov r3, r5
	beq _0203D224
	str r2, [sp]
	ldmia r1, {r1, r2}
	bl _ZN23CFieldMapLayerCollision19IsCircleBlockedFineE7Point2Dlm
	cmp r0, #0
	beq _0203D248
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, lr}
	add sp, sp, #0x10
	bx lr
_0203D224:
	str r2, [sp]
	ldmia r1, {r1, r2}
	bl _ZN23CFieldMapLayerCollision15IsCircleBlockedE7Point2Dlm
	cmp r0, #0
	addne sp, sp, #4
	movne r0, #1
	ldmneia sp!, {r3, r4, r5, r6, lr}
	addne sp, sp, #0x10
	bxne lr
_0203D248:
	tst r4, #4
	beq _0203D2D4
	ldr r1, [r6, #0x6c]
	ldr r2, [r6, #0x14]
	ldr r0, [r1, #0x24]
	cmp r2, r0
	ldrlt r0, [r1, #0x30]
	ldrlt r0, [r0, r2, lsl #2]
	movge r0, #0
	cmp r0, #0
	beq _0203D2D4
	tst r4, #1
	ldr r2, _0203D2F0 ; =0x00804000
	add r1, sp, #0x1c
	mov r3, r5
	beq _0203D2B0
	str r2, [sp]
	ldmia r1, {r1, r2}
	bl _ZN23CFieldMapLayerAttribute19IsCircleBlockedFineE7Point2Dlm
	cmp r0, #0
	beq _0203D2D4
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, lr}
	add sp, sp, #0x10
	bx lr
_0203D2B0:
	str r2, [sp]
	ldmia r1, {r1, r2}
	bl _ZN23CFieldMapLayerAttribute15IsCircleBlockedE7Point2Dlm
	cmp r0, #0
	addne sp, sp, #4
	movne r0, #1
	ldmneia sp!, {r3, r4, r5, r6, lr}
	addne sp, sp, #0x10
	bxne lr
_0203D2D4:
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, lr}
	add sp, sp, #0x10
	bx lr
	.align 2, 0
_0203D2E8: .word MAIN_BSS_0210CA7C
_0203D2EC: .word MAIN_BSS_0210CA50
_0203D2F0: .word 0x00804000

	arm_func_start sub_0203D2F4
sub_0203D2F4: ; 0x0203D2F4
	ldr r1, [r0, #4]
	tst r1, #2
	bxeq lr
	tst r1, #4
	bxeq lr
	ldr r1, [r0, #0xa0]
	str r1, [r0, #0xa4]
	ldr r1, [r0, #4]
	bic r1, r1, #4
	str r1, [r0, #4]
	bx lr
	arm_func_end sub_0203D2F4

	arm_func_start sub_0203D320
sub_0203D320: ; 0x0203D320
	ldr r1, [r0, #4]
	tst r1, #2
	bxeq lr
	ldr r2, [r0, #0xa4]
	ldr r1, [r0, #0x9c]
	sub r1, r2, r1
	str r1, [r0, #0xa4]
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0203D35C
	ldr r1, [r1, #0xc]
	cmp r1, #0
	ldrne r2, [r1, #0x8c]
	moveq r2, #0
	b _0203D360
	arm_func_end sub_0203D320
_0203D35C:
	mov r2, #0
_0203D360:
	ldr r1, [r0, #0xa4]
	adds r2, r2, r1
	bpl _0203D37C
	ldr r1, [r0, #4]
	mov r2, #0
	orr r1, r1, #4
	str r1, [r0, #4]
_0203D37C:
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r2, [r0, #0x8c]
	bx lr

	arm_func_start sub_0203D394
sub_0203D394: ; 0x0203D394
	stmdb sp!, {r4, lr}
	ldr r1, [r0, #4]
	tst r1, #0x40
	ldmeqia sp!, {r4, pc}
	ldrh ip, [r0, #0xac]
	ldrh r2, [r0, #0xb0]
	ldrh r1, [r0, #0xae]
	mov lr, ip, asr #4
	ldr r3, _0203D400 ; =FX_SinCosTable_
	mov lr, lr, lsl #2
	ldrsh r3, [r3, lr]
	mov r2, r2, lsl #0xc
	ldr r4, [r0, #0xa8]
	smull lr, r2, r3, r2
	add r1, ip, r1
	strh r1, [r0, #0xac]
	adds r3, lr, #0x800
	adc r1, r2, #0
	ldr r0, [r0, #8]
	mov r2, r3, lsr #0xc
	orr r2, r2, r1, lsl #20
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	add r1, r4, r2
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203D400: .word FX_SinCosTable_
	arm_func_end sub_0203D394

	arm_func_start sub_0203D404
sub_0203D404: ; 0x0203D404
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x2c
	ldr r1, [sp, #0x3c]
	mov r4, r0
	ldr r0, [sp, #0x40]
	str r1, [r4, #0xc0]
	str r0, [r4, #0xc4]
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203D470
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0203D450
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x1c]
	str r0, [sp, #0x20]
	b _0203D468
	arm_func_end sub_0203D404
_0203D450:
	mov r0, #0
	add r1, sp, #0x14
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
_0203D468:
	add r3, sp, #0x1c
	b _0203D48C
_0203D470:
	mov r0, #0
	add r1, sp, #0xc
	add r3, sp, #0x1c
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
_0203D48C:
	ldr r2, [r3]
	ldr r1, [r3, #4]
	ldr r0, [r4, #8]
	str r2, [sp, #0x24]
	str r1, [sp, #0x28]
	cmp r0, #0
	beq _0203D4BC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrne r1, [r0, #0x20]
	moveq r1, #0
	b _0203D4C0
_0203D4BC:
	mov r1, #0
_0203D4C0:
	ldr r0, [r4, #0xc0]
	cmp r1, r0
	bgt _0203D4E4
	ldr r0, [sp, #0x3c]
	mov r1, #1
	add r0, r0, #0x50000
	str r1, [r4, #0xc8]
	str r0, [sp, #0x24]
	b _0203D4F8
_0203D4E4:
	ldr r0, [sp, #0x3c]
	mov r1, #2
	sub r0, r0, #0x50000
	str r1, [r4, #0xc8]
	str r0, [sp, #0x24]
_0203D4F8:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0203D520
	add r1, sp, #0x24
	add r0, r0, #0xc
	mov r3, #0x2000
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011C20E7Point2Di
_0203D520:
	mov ip, #0
	str ip, [r4, #0xcc]
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203D564
	mov r3, #1
	str r3, [r4, #0x54]
	ldr r0, [r4, #8]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0203D564
	sub r1, r3, #3
	stmia sp, {r1, ip}
	mov r1, #2
	mov r2, #8
	str ip, [sp, #8]
	bl _ZN6CActor12sub_02012B68Eiiiihl
_0203D564:
	mov r0, #1
	add sp, sp, #0x2c
	ldmia sp!, {r3, r4, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start _ZN11CFieldActor12sub_0203D578EP9CFieldMap
_ZN11CFieldActor12sub_0203D578EP9CFieldMap: ; 0x0203D578
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x40
	mov r6, r0
	ldr r0, [r6, #0xc8]
	mov r5, r1
	cmp r0, #1
	mov r4, #0
	beq _0203D5A4
	cmp r0, #2
	beq _0203D710
	b _0203D878
	arm_func_end _ZN11CFieldActor12sub_0203D578EP9CFieldMap
_0203D5A4:
	ldr r1, [r6, #8]
	cmp r1, #0
	beq _0203D5D8
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq _0203D5D0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	movne r0, #1
	moveq r0, r4
	b _0203D5DC
_0203D5D0:
	mov r0, r4
	b _0203D5DC
_0203D5D8:
	mov r0, r4
_0203D5DC:
	cmp r0, #0
	bne _0203D878
	cmp r1, #0
	beq _0203D600
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0xa4]
	moveq r0, #0
	b _0203D604
_0203D600:
	mov r0, #0
_0203D604:
	cmp r0, #0
	bne _0203D878
	ldr r0, [r6, #0xcc]
	cmp r0, #0
	bne _0203D6E4
	cmp r1, #0
	beq _0203D660
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq _0203D640
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x28]
	str r0, [sp, #0x2c]
	b _0203D658
_0203D640:
	mov r0, #0
	add r1, sp, #0x18
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
_0203D658:
	add r2, sp, #0x28
	b _0203D67C
_0203D660:
	mov r0, #0
	add r1, sp, #0x10
	add r2, sp, #0x28
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
_0203D67C:
	ldmia r2, {r1, r2}
	mov r0, #1
	str r0, [r6, #0xcc]
	ldr r0, [r6, #8]
	add r1, r1, #0x78000
	str r2, [sp, #0x3c]
	str r1, [sp, #0x38]
	cmp r0, #0
	beq _0203D6DC
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0203D6B8
	mov r1, #0x1e000
	mov r2, #0x1e
	bl _ZN6CActor12sub_02012860Eli
_0203D6B8:
	ldr r0, [r6, #8]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0203D6DC
	add r1, sp, #0x38
	add r0, r0, #0xc
	mov r3, #0x1e
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011AB0E7Point2Dm
_0203D6DC:
	mov r4, #1
	b _0203D878
_0203D6E4:
	mov r0, #0
	str r0, [r6, #0x54]
	ldr r0, [r6, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0203D704
	bl _ZN6CActor12sub_02012C00Ev
_0203D704:
	mov r0, #0
	str r0, [r6, #0xc8]
	b _0203D878
_0203D710:
	ldr r1, [r6, #8]
	cmp r1, #0
	beq _0203D744
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq _0203D73C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	movne r0, #1
	moveq r0, r4
	b _0203D748
_0203D73C:
	mov r0, r4
	b _0203D748
_0203D744:
	mov r0, r4
_0203D748:
	cmp r0, #0
	bne _0203D878
	cmp r1, #0
	beq _0203D76C
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0xa4]
	moveq r0, #0
	b _0203D770
_0203D76C:
	mov r0, #0
_0203D770:
	cmp r0, #0
	bne _0203D878
	ldr r0, [r6, #0xcc]
	cmp r0, #0
	bne _0203D850
	cmp r1, #0
	beq _0203D7CC
	ldr r0, [r1, #0xc]
	cmp r0, #0
	beq _0203D7AC
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	b _0203D7C4
_0203D7AC:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_0203D7C4:
	add r2, sp, #0x20
	b _0203D7E8
_0203D7CC:
	mov r0, #0
	add r1, sp, #0
	add r2, sp, #0x20
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_0203D7E8:
	ldmia r2, {r1, r2}
	mov r0, #1
	str r0, [r6, #0xcc]
	ldr r0, [r6, #8]
	sub r1, r1, #0x78000
	str r2, [sp, #0x34]
	str r1, [sp, #0x30]
	cmp r0, #0
	beq _0203D848
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0203D824
	mov r1, #0x1e000
	mov r2, #0x1e
	bl _ZN6CActor12sub_02012860Eli
_0203D824:
	ldr r0, [r6, #8]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0203D848
	add r1, sp, #0x30
	add r0, r0, #0xc
	mov r3, #0x1e
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011AB0E7Point2Dm
_0203D848:
	mov r4, #1
	b _0203D878
_0203D850:
	mov r0, #0
	str r0, [r6, #0x54]
	ldr r0, [r6, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0203D870
	bl _ZN6CActor12sub_02012C00Ev
_0203D870:
	mov r0, #0
	str r0, [r6, #0xc8]
_0203D878:
	mov r0, r6
	mov r1, r5
	bl sub_0203C87C
	mov r0, r4
	add sp, sp, #0x40
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_0203D890
sub_0203D890: ; 0x0203D890
	stmdb sp!, {r3, lr}
	cmp r1, #6
	bne _0203D8FC
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0203D8D0
	ldr r3, [r1, #0xc]
	cmp r3, #0
	moveq r1, #0
	beq _0203D8D4
	ldr r2, [r3, #0x8c]
	ldr r1, [r3, #0xa0]
	ldr r3, [r3, #0xb0]
	add r1, r2, r1
	add r1, r3, r1
	b _0203D8D4
	arm_func_end sub_0203D890
_0203D8D0:
	mov r1, #0
_0203D8D4:
	cmp r1, #0
	bne _0203D8FC
	ldrb r1, [r0, #0xd4]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	ldrh r1, [r0, #0xd8]
	cmp r1, #0
	ldmneia sp!, {r3, pc}
	bl sub_0203D910
	ldmia sp!, {r3, pc}
_0203D8FC:
	ldrh r1, [r0, #0xd8]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	bl sub_0203DA10
	ldmia sp!, {r3, pc}

	arm_func_start sub_0203D910
sub_0203D910: ; 0x0203D910
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0203DA0C ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r5, [r1]
	cmp r5, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r5
	mov r1, #0x25
	mov r2, #0
	bl ov0_02142F6C
	strh r0, [r4, #0xd8]
	ldrh r1, [r4, #0xd8]
	cmp r1, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r5
	bl ov0_02143088
	cmp r0, #0
	beq _0203D964
	mov r1, r4
	mov r2, r5
	bl ov0_021652DC
	arm_func_end sub_0203D910
_0203D964:
	ldrh r0, [r4, #0xd8]
	cmp r0, #0
	ldrneb r0, [r4, #0xd4]
	cmpne r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	cmp r0, #1
	ldr r0, [r4, #8]
	bne _0203D9C4
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	ldrne r1, [r0, #0xc4]
	cmpne r1, #0
	beq _0203D9B8
	mvn r0, #0xff
	strh r0, [r1, #0x40]
	strh r0, [r1, #0x42]
	strh r0, [r1, #0x44]
	strh r0, [r1, #0x46]
	mov r0, #1
	str r0, [r1, #0x48]
_0203D9B8:
	mov r0, #0
	str r0, [r4, #0x90]
	ldmia sp!, {r3, r4, r5, pc}
_0203D9C4:
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	ldrsh r3, [r4, #0xd6]
	cmpne r0, #0
	ldrne r2, [r0, #0xc4]
	cmpne r2, #0
	beq _0203DA00
	mvn r1, #0xff
	strh r1, [r2, #0x40]
	mov r0, #0x100
	strh r0, [r2, #0x42]
	strh r1, [r2, #0x44]
	strh r3, [r2, #0x46]
	mov r0, #1
	str r0, [r2, #0x48]
_0203DA00:
	mov r0, #0
	str r0, [r4, #0x90]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0203DA0C: .word MAIN_BSS_0210CA60

	arm_func_start sub_0203DA10
sub_0203DA10: ; 0x0203DA10
	stmdb sp!, {r3, lr}
	ldrh r1, [r0, #0xd8]
	cmp r1, #0
	ldrne r0, _0203DA34 ; =MAIN_BSS_0210CA60
	ldrne r0, [r0]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov0_021430D8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203DA34: .word MAIN_BSS_0210CA60
	arm_func_end sub_0203DA10

	arm_func_start _ZN11CFieldActor12sub_0203DA38Ev
_ZN11CFieldActor12sub_0203DA38Ev: ; 0x0203DA38
	mov r0, #1
	bx lr
	arm_func_end _ZN11CFieldActor12sub_0203DA38Ev

	arm_func_start _ZN11CFieldActor12sub_0203DA40EP9CFieldMap
_ZN11CFieldActor12sub_0203DA40EP9CFieldMap: ; 0x0203DA40
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl sub_0203C2B8
	mov r0, r5
	mov r1, r4
	bl sub_0203C87C
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN11CFieldActor12sub_0203DA40EP9CFieldMap

	arm_func_start _ZN11CFieldActor12sub_0203DA60Em
_ZN11CFieldActor12sub_0203DA60Em: ; 0x0203DA60
	str r1, [r0, #0x58]
	bx lr
	arm_func_end _ZN11CFieldActor12sub_0203DA60Em

	arm_func_start sub_0203DA68
sub_0203DA68: ; 0x0203DA68
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	mov r4, r0
	bl _ZN6CActorC2Ev
	ldr r0, _0203DB58 ; =PTR_LAB_0208dd84
	mov ip, #0
	str r0, [r4]
	str ip, [r4, #0x184]
	str ip, [r4, #0x1f4]
	strb ip, [r4, #0x200]
	str ip, [r4, #0x1d8]
	str ip, [r4, #0x1dc]
	strb ip, [r4, #0x1e0]
	strb ip, [r4, #0x1e1]
	mov r1, #0x1000
	str r1, [r4, #0x19c]
	mov r1, #2
	str r1, [r4, #0x1a0]
	mov r1, #4
	mov r0, #0xff
	str r1, [r4, #0x1a4]
	strb r0, [r4, #0x1c9]
	add r1, r0, #0xff00
	add r0, r4, #0x100
	strh r1, [r0, #0xca]
	ldr r1, [r4, #0xc4]
	mov r3, #0x1f
	str ip, [r1, #0x10]
	ldr r2, [r4, #0xc4]
	ldr r1, _0203DB5C ; =DAT_02084d60
	str r3, [r2, #0x14]
	str ip, [r4, #0x1a8]
	strb ip, [r4, #0x1d4]
	strb ip, [r4, #0x1d5]
	str ip, [r4, #0x1cc]
	strh ip, [r0, #0xb8]
	strb ip, [r4, #0x1c6]
	str ip, [r4, #0x1bc]
	str ip, [r4, #0x1c0]
	strb ip, [r4, #0x1c7]
	add lr, sp, #0
	strb ip, [r4, #0x1c8]
	ldmia r1, {r0, r1, r2, r3}
	stmia lr, {r0, r1, r2, r3}
	ldr r0, [sp]
	mov r1, #1
	str r0, [r4, #0x1e4]
	ldr r2, [sp, #4]
	mov r0, r4
	str r2, [r4, #0x1e8]
	ldr r2, [sp, #8]
	str r2, [r4, #0x1ec]
	ldr r2, [sp, #0xc]
	str r2, [r4, #0x1f0]
	str ip, [r4, #0x1f8]
	str r1, [r4, #0x1fc]
	str ip, [r4, #0x194]
	str ip, [r4, #0x198]
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203DB58: .word PTR_LAB_0208dd84
_0203DB5C: .word DAT_02084d60
	arm_func_end sub_0203DA68

	arm_func_start sub_0203DB60
sub_0203DB60: ; 0x0203DB60
	stmdb sp!, {r4, lr}
	ldr r1, _0203DB84 ; =PTR_LAB_0208dd84
	mov r4, r0
	str r1, [r4]
	bl sub_0203E55C
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203DB84: .word PTR_LAB_0208dd84
	arm_func_end sub_0203DB60

	arm_func_start sub_0203DB88
sub_0203DB88: ; 0x0203DB88
	stmdb sp!, {r4, lr}
	ldr r1, _0203DBB4 ; =PTR_LAB_0208dd84
	mov r4, r0
	str r1, [r4]
	bl sub_0203E55C
	mov r0, r4
	bl _ZN6CActorD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203DBB4: .word PTR_LAB_0208dd84
	arm_func_end sub_0203DB88

	arm_func_start sub_0203DBB8
sub_0203DBB8: ; 0x0203DBB8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x20
	mov r6, r1
	str r0, [sp, #8]
	mov r5, r2
	mov r4, r3
	ldr r8, [sp, #0x4c]
	bl sub_0203E55C
	cmp r6, #4
	bne _0203DC44
	ldr r0, _0203E0E4 ; =MAIN_BSS_020B26A0
	mvn r1, #0
	bl sub_020176BC
	ldr r1, [sp, #8]
	str r0, [r1, #0x184]
	ldr r1, [r0]
	ldr r1, [r1, #0x1c]
	blx r1
	ldr r0, _0203E0E8 ; =0x04000210
	ldr r0, [r0]
	tst r0, #1
	beq _0203DC20
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x184]
	bl sub_02040EF8
	b _0203DC2C
	arm_func_end sub_0203DBB8
_0203DC20:
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x184]
	bl sub_02040EBC
_0203DC2C:
	ldr r0, [sp, #8]
	mov r1, #1
	str r1, [r0, #0x1f8]
	mov r1, #0
	str r1, [r0, #0x1fc]
	b _0203DD68
_0203DC44:
	cmp r6, #2
	cmpne r8, #0
	beq _0203DD24
	ldr r0, _0203E0EC ; =_0208F304
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	ldr r1, [r0]
	ldr r1, [r1, #0x28]
	blx r1
	cmp r0, #1
	bne _0203DD24
	cmp r6, #1
	mov r6, #1
	bne _0203DCA4
	ldr r0, [sp, #0x48]
	mov r1, r5
	mov r3, r0, lsl #0x10
	ldr r0, _0203E0E4 ; =MAIN_BSS_020B26A0
	mov r2, r4
	mov r3, r3, lsr #0x10
	str r6, [sp]
	bl sub_02017748
	ldr r1, [sp, #8]
	b _0203DCC8
_0203DCA4:
	ldr r0, [sp, #0x48]
	mov r1, r5
	mov r3, r0, lsl #0x10
	ldr r0, _0203E0E4 ; =MAIN_BSS_020B26A0
	mov r2, r4
	mov r3, r3, lsr #0x10
	str r6, [sp]
	bl sub_02017848
	ldr r1, [sp, #8]
_0203DCC8:
	str r0, [r1, #0x184]
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x184]
	ldr r1, [r0]
	ldr r1, [r1, #0x1c]
	blx r1
	ldr r0, _0203E0E8 ; =0x04000210
	ldr r0, [r0]
	tst r0, #1
	beq _0203DD00
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x184]
	bl sub_02040EF8
	b _0203DD0C
_0203DD00:
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x184]
	bl sub_02040EBC
_0203DD0C:
	ldr r0, [sp, #8]
	mov r1, #1
	str r1, [r0, #0x1f8]
	mov r1, #0
	str r1, [r0, #0x1fc]
	b _0203DD68
_0203DD24:
	ldr r0, [sp, #0x48]
	ldr r1, _0203E0F0 ; =MAIN_BSS_0210CA64
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	stmia sp, {r0, r8}
	ldr r0, [r1]
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl sub_02041008
	ldr r1, [sp, #8]
	str r0, [r1, #0x184]
	ldr r0, [sp, #8]
	mov r1, #0
	str r1, [r0, #0x1f8]
	mov r1, #1
	str r1, [r0, #0x1fc]
_0203DD68:
	ldr r0, [sp, #8]
	ldr r1, [r0, #0x184]
	ldr r2, [r1, #0x30]
	mov r1, r0
	str r2, [r1, #0x190]
	ldr r1, [r1, #0x184]
	bl _ZN6CActor12sub_02011FF4EP10CActorData
	cmp r8, #0
	beq _0203DEA0
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x184]
	ldrb r2, [r0, #0x14]
	cmp r2, #0
	beq _0203DEB4
	ldr r0, [sp, #8]
	ldr r1, _0203E0F4 ; =_ZN17UnkClass_02007770D2Ev
	str r2, [r0, #0x198]
	str r1, [sp]
	ldr r0, [r0, #0x198]
	ldr r3, _0203E0F8 ; =_ZN17UnkClass_02007770C1Ev
	mov r1, #0x18
	mov r2, #8
	bl __cxa_vec_new
	ldr r1, [sp, #8]
	mov r5, #0
	str r0, [r1, #0x194]
	mov r0, r1
	ldr r0, [r0, #0x198]
	mov r6, r5
	cmp r0, #0
	ble _0203DE6C
	mov r7, r5
_0203DDE8:
	ldr r0, [sp, #8]
	and r1, r6, #0xff
	ldr r0, [r0, #0x184]
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	movs r4, r0
	beq _0203DE54
	ldrb r0, [r4]
	tst r0, #1
	beq _0203DE54
	ldr r0, [sp, #8]
	ldr r1, [r4, #4]
	ldr r0, [r0, #0x194]
	add r0, r0, r7
	bl _ZN17UnkClass_0200777012sub_020077CCEP17UnkClass_020074D4
	ldr r0, [sp, #8]
	ldr r1, [r4, #8]
	ldr r0, [r0, #0x194]
	add r0, r0, r7
	bl _ZN17UnkClass_0200777012sub_020077E4EP9CNCERFile
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x194]
	add r0, r0, r7
	ldr r0, [r0, #0x10]
	cmp r5, r0
	movlo r5, r0
_0203DE54:
	ldr r0, [sp, #8]
	add r6, r6, #1
	ldr r0, [r0, #0x198]
	add r7, r7, #0x18
	cmp r6, r0
	blt _0203DDE8
_0203DE6C:
	mov r1, #0
	mov r0, r5
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	ldr r2, [sp, #8]
	mov r1, #0
	str r0, [r2, #0x188]
	mov r0, r5
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	ldr r1, [sp, #8]
	str r0, [r1, #0x18c]
	b _0203DEB4
_0203DEA0:
	ldr r0, [sp, #8]
	ldr r0, [r0, #0x184]
	ldr r1, [r0, #0x2c]
	ldr r0, [sp, #8]
	str r1, [r0, #0x188]
_0203DEB4:
	ldr r0, [sp, #8]
	mov r4, #0
	ldr r0, [r0, #0x184]
	mov r3, #0xff
	ldr r1, [r0, #0xc]
	ldr r0, [sp, #8]
	add r2, r3, #0xff00
	ldr r0, [r0, #0xc4]
	mov r5, r4
	str r1, [r0, #0x34]
	ldr r0, [sp, #8]
	mov r6, r4
	str r8, [r0, #0x1f4]
	strb r4, [r0, #0x200]
	strb r3, [r0, #0x1c9]
	add r1, r0, #0x100
	strh r2, [r1, #0xca]
	str r4, [r0, #0x1a8]
	mov r2, #2
	strb r2, [r0, #0x1c4]
	add r0, r3, #0x7f00
	strh r0, [r1, #0xac]
	ldr r0, [sp, #8]
	mov r1, #0x1f
	strb r1, [r0, #0x1c5]
	str r4, [r0, #0x1b0]
	mov r7, r4
	str r4, [sp, #0x14]
	str r4, [r0, #0x1b4]
_0203DF28:
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x14]
	ldr r0, [r0, #0x184]
	and r1, r1, #0xff
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	cmp r0, #0
	beq _0203E084
	ldrb r1, [r0]
	tst r1, #1
	beq _0203E084
	ldr r1, [r0, #8]
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [r1, #0xb8]
	str r0, [sp, #0xc]
	ldrh r0, [r0]
	cmp r0, #0
	ble _0203E084
	mvn r8, #0xff
_0203DF7C:
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #0xc]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl NNS_G2dGetCellDataByIdx
	ldrh fp, [r0]
	mov r3, #0
	cmp fp, #0
	ble _0203E064
	ldr sl, [r0, #4]
_0203DFA4:
	mov r0, r3, lsl #0x10
	mov r1, r0, lsr #0x10
	mov r0, #6
	mul r0, r1, r0
	add sb, sl, r0
	ldrh r2, [sl, r0]
	ldrh r1, [sb, #2]
	ldrh r0, [sb, #4]
	strh r2, [sp, #0x18]
	strh r1, [sp, #0x1a]
	strh r0, [sp, #0x1c]
	ldr r1, [sp, #0x18]
	ldr r0, _0203E0FC ; =0x01FF0000
	add r3, r3, #1
	and r0, r1, r0
	mov ip, r0, lsr #0x10
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x18]
	and lr, r0, #0xff
	ldr r0, _0203E100 ; =0xC000C000
	cmp ip, #0xff
	and r1, r1, r0
	and r0, r1, #0xc000
	mov r2, r0, asr #0xe
	and r0, r1, #0xc0000000
	mov r0, r0, lsr #0x1e
	mov r1, r0, lsl #1
	ldr r0, _0203E104 ; =NNSi_objSizeWTbl
	orrgt ip, ip, r8
	add r0, r0, r2, lsl #3
	ldrh sb, [r1, r0]
	ldr r0, _0203E108 ; =NNSi_objSizeHTbl
	cmp lr, #0x7f
	add r0, r0, r2, lsl #3
	ldrh r1, [r1, r0]
	orrgt lr, lr, r8
	cmp ip, r4
	movlt r4, ip
	cmp lr, r6
	add r0, ip, sb
	movlt r6, lr
	cmp r0, r5
	movgt r5, r0
	add r0, lr, r1
	cmp r0, r7
	movgt r7, r0
	cmp r3, fp
	blt _0203DFA4
_0203E064:
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	ldrh r1, [r0]
	ldr r0, [sp, #0x10]
	cmp r0, r1
	blt _0203DF7C
_0203E084:
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, #0x1d
	blt _0203DF28
	add r0, r4, r5
	add r0, r0, r0, lsr #31
	mov r2, r0, asr #1
	add r1, r6, r7
	add r0, r1, r1, lsr #31
	mov r3, r0, asr #1
	mov r8, r2, lsl #0xc
	ldr r0, [sp, #8]
	sub r2, r5, r4
	sub r1, r7, r6
	str r8, [r0, #0x1e4]
	mov r3, r3, lsl #0xc
	str r3, [r0, #0x1e8]
	mov r2, r2, lsl #0xc
	str r2, [r0, #0x1ec]
	mov r1, r1, lsl #0xc
	str r1, [r0, #0x1f0]
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203E0E4: .word MAIN_BSS_020B26A0
_0203E0E8: .word 0x04000210
_0203E0EC: .word s_game
_0203E0F0: .word MAIN_BSS_0210CA64
_0203E0F4: .word _ZN17UnkClass_02007770D2Ev
_0203E0F8: .word _ZN17UnkClass_02007770C1Ev
_0203E0FC: .word 0x01FF0000
_0203E100: .word 0xC000C000
_0203E104: .word NNSi_objSizeWTbl
_0203E108: .word NNSi_objSizeHTbl

	arm_func_start sub_0203E10C
sub_0203E10C: ; 0x0203E10C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x28
	mov r6, r1
	str r0, [sp, #0x10]
	mov r5, r2
	mov r4, r3
	ldr r8, [sp, #0x54]
	bl sub_0203E55C
	cmp r6, #4
	bne _0203E17C
	ldr r0, _0203E53C ; =0x00050838
	bl _Znwm
	cmp r0, #0
	beq _0203E148
	bl sub_020412A0
	arm_func_end sub_0203E10C
_0203E148:
	ldr r1, [sp, #0x10]
	ldr r2, _0203E540 ; =DAT_0208dd98
	str r0, [r1, #0x184]
	stmia sp, {r2, r8}
	mov r0, #1
	str r0, [sp, #8]
	mov r0, r1
	ldr r0, [r0, #0x184]
	ldr r3, [sp, #0x50]
	mov r1, r5
	mov r2, r4
	bl sub_02041344
	b _0203E1D0
_0203E17C:
	mov r0, #0x34
	bl _Znwm
	cmp r0, #0
	beq _0203E190
	bl sub_020407E0
_0203E190:
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x50]
	str r0, [r1, #0x184]
	mov r0, r2, lsl #0x10
	mov r0, r0, lsr #0x10
	stmia sp, {r0, r8}
	mov r0, #0
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	mov r0, r1
	ldr r0, [r0, #0x184]
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl sub_02040830
_0203E1D0:
	ldr r0, [sp, #0x10]
	ldr r1, [r0, #0x184]
	ldr r2, [r1, #0x30]
	mov r1, r0
	str r2, [r1, #0x190]
	ldr r1, [r1, #0x184]
	bl _ZN6CActor12sub_02011FF4EP10CActorData
	cmp r8, #0
	beq _0203E2F0
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x184]
	ldrb r2, [r0, #0x14]
	cmp r2, #0
	beq _0203E304
	ldr r0, [sp, #0x10]
	ldr r1, _0203E544 ; =_ZN17UnkClass_02007770D2Ev
	str r2, [r0, #0x198]
	str r1, [sp]
	ldr r0, [r0, #0x198]
	ldr r3, _0203E548 ; =_ZN17UnkClass_02007770C1Ev
	mov r1, #0x18
	mov r2, #8
	bl __cxa_vec_new
	mov r5, #0
	ldr r1, [sp, #0x10]
	mov r6, r5
	mov r7, r5
	str r0, [r1, #0x194]
_0203E240:
	ldr r0, [sp, #0x10]
	and r1, r6, #0xff
	ldr r0, [r0, #0x184]
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	movs r4, r0
	beq _0203E2AC
	ldrb r0, [r4]
	tst r0, #1
	beq _0203E2AC
	ldr r0, [sp, #0x10]
	ldr r1, [r4, #4]
	ldr r0, [r0, #0x194]
	add r0, r0, r7
	bl _ZN17UnkClass_0200777012sub_020077CCEP17UnkClass_020074D4
	ldr r0, [sp, #0x10]
	ldr r1, [r4, #8]
	ldr r0, [r0, #0x194]
	add r0, r0, r7
	bl _ZN17UnkClass_0200777012sub_020077E4EP9CNCERFile
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x194]
	add r0, r0, r7
	ldr r0, [r0, #0x10]
	cmp r5, r0
	movlo r5, r0
_0203E2AC:
	add r6, r6, #1
	cmp r6, #0x1d
	add r7, r7, #0x18
	blt _0203E240
	mov r1, #0
	mov r0, r5
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	ldr r2, [sp, #0x10]
	mov r1, #0
	str r0, [r2, #0x188]
	mov r0, r5
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	ldr r1, [sp, #0x10]
	str r0, [r1, #0x18c]
	b _0203E304
_0203E2F0:
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x184]
	ldr r1, [r0, #0x2c]
	ldr r0, [sp, #0x10]
	str r1, [r0, #0x188]
_0203E304:
	ldr r0, [sp, #0x10]
	mov r4, #0
	ldr r0, [r0, #0x184]
	mov r3, #0xff
	ldr r1, [r0, #0xc]
	ldr r0, [sp, #0x10]
	add r2, r3, #0xff00
	ldr r0, [r0, #0xc4]
	mov r5, r4
	str r1, [r0, #0x34]
	ldr r0, [sp, #0x10]
	mov r6, r4
	str r8, [r0, #0x1f4]
	strb r4, [r0, #0x200]
	strb r3, [r0, #0x1c9]
	add r1, r0, #0x100
	strh r2, [r1, #0xca]
	str r4, [r0, #0x1a8]
	mov r2, #2
	strb r2, [r0, #0x1c4]
	add r0, r3, #0x7f00
	strh r0, [r1, #0xac]
	ldr r0, [sp, #0x10]
	mov r1, #0x1f
	strb r1, [r0, #0x1c5]
	str r4, [r0, #0x1b0]
	mov r7, r4
	str r4, [sp, #0x1c]
	str r4, [r0, #0x1b4]
_0203E378:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x1c]
	ldr r0, [r0, #0x184]
	and r1, r1, #0xff
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	cmp r0, #0
	beq _0203E4D4
	ldrb r1, [r0]
	tst r1, #1
	beq _0203E4D4
	ldr r1, [r0, #8]
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r1, #0xb8]
	str r0, [sp, #0x14]
	ldrh r0, [r0]
	cmp r0, #0
	ble _0203E4D4
	mvn r8, #0xff
_0203E3CC:
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0x14]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl NNS_G2dGetCellDataByIdx
	ldrh fp, [r0]
	mov r3, #0
	cmp fp, #0
	ble _0203E4B4
	ldr sl, [r0, #4]
_0203E3F4:
	mov r0, r3, lsl #0x10
	mov r1, r0, lsr #0x10
	mov r0, #6
	mul r0, r1, r0
	add sb, sl, r0
	ldrh r2, [sl, r0]
	ldrh r1, [sb, #2]
	ldrh r0, [sb, #4]
	strh r2, [sp, #0x20]
	strh r1, [sp, #0x22]
	strh r0, [sp, #0x24]
	ldr r1, [sp, #0x20]
	ldr r0, _0203E54C ; =0x01FF0000
	add r3, r3, #1
	and r0, r1, r0
	mov ip, r0, lsr #0x10
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x20]
	and lr, r0, #0xff
	ldr r0, _0203E550 ; =0xC000C000
	cmp ip, #0xff
	and r1, r1, r0
	and r0, r1, #0xc000
	mov r2, r0, asr #0xe
	and r0, r1, #0xc0000000
	mov r0, r0, lsr #0x1e
	mov r1, r0, lsl #1
	ldr r0, _0203E554 ; =NNSi_objSizeWTbl
	orrgt ip, ip, r8
	add r0, r0, r2, lsl #3
	ldrh sb, [r1, r0]
	ldr r0, _0203E558 ; =NNSi_objSizeHTbl
	cmp lr, #0x7f
	add r0, r0, r2, lsl #3
	ldrh r1, [r1, r0]
	orrgt lr, lr, r8
	cmp ip, r4
	movlt r4, ip
	cmp lr, r6
	add r0, ip, sb
	movlt r6, lr
	cmp r0, r5
	movgt r5, r0
	add r0, lr, r1
	cmp r0, r7
	movgt r7, r0
	cmp r3, fp
	blt _0203E3F4
_0203E4B4:
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	ldrh r1, [r0]
	ldr r0, [sp, #0x18]
	cmp r0, r1
	blt _0203E3CC
_0203E4D4:
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	cmp r0, #0x1d
	blt _0203E378
	add r0, r4, r5
	add r0, r0, r0, lsr #31
	mov r2, r0, asr #1
	add r1, r6, r7
	add r0, r1, r1, lsr #31
	mov r3, r0, asr #1
	mov r8, r2, lsl #0xc
	ldr r0, [sp, #0x10]
	sub r2, r5, r4
	sub r1, r7, r6
	str r8, [r0, #0x1e4]
	mov r3, r3, lsl #0xc
	str r3, [r0, #0x1e8]
	mov r2, r2, lsl #0xc
	str r2, [r0, #0x1ec]
	mov r1, r1, lsl #0xc
	str r1, [r0, #0x1f0]
	mov r1, #1
	str r1, [r0, #0x1f8]
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203E53C: .word 0x00050838
_0203E540: .word DAT_0208dd98
_0203E544: .word _ZN17UnkClass_02007770D2Ev
_0203E548: .word _ZN17UnkClass_02007770C1Ev
_0203E54C: .word 0x01FF0000
_0203E550: .word 0xC000C000
_0203E554: .word NNSi_objSizeWTbl
_0203E558: .word NNSi_objSizeHTbl

	arm_func_start sub_0203E55C
sub_0203E55C: ; 0x0203E55C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x184]
	cmp r0, #0
	beq _0203E61C
	ldr r0, [r4, #0x1f4]
	cmp r0, #0
	beq _0203E58C
	ldr r0, [r4, #0x188]
	bl NNS_GfdFreeLnkTexVram
	ldr r0, [r4, #0x18c]
	bl NNS_GfdFreeLnkTexVram
	arm_func_end sub_0203E55C
_0203E58C:
	ldr r0, [r4, #0x1fc]
	cmp r0, #0
	beq _0203E5D8
	ldr r0, [r4, #0x184]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	ldr r0, [r4, #0x1f8]
	cmp r0, #0
	ldrne r0, [r4, #0x184]
	cmpne r0, #0
	beq _0203E5F0
	beq _0203E5CC
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203E5CC:
	mov r0, #0
	str r0, [r4, #0x184]
	b _0203E5F0
_0203E5D8:
	mov r0, r4
	bl _ZN6CActor12sub_020120B0Ev
	ldr r0, [r4, #0x184]
	ldr r1, [r0]
	ldr r1, [r1, #0x20]
	blx r1
_0203E5F0:
	mov r1, #0
	str r1, [r4, #0x1d8]
	str r1, [r4, #0x1dc]
	strb r1, [r4, #0x1e0]
	strb r1, [r4, #0x1e1]
	mov r0, #0x1000
	str r0, [r4, #0x19c]
	str r1, [r4, #0x1f8]
	str r1, [r4, #0x184]
	mov r0, #1
	str r0, [r4, #0x1fc]
_0203E61C:
	ldr r0, [r4, #0x194]
	cmp r0, #0
	beq _0203E640
	ldr r3, _0203E64C ; =_ZN17UnkClass_02007770D2Ev
	mov r1, #0x18
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #0x194]
_0203E640:
	mov r0, #0
	str r0, [r4, #0x198]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203E64C: .word _ZN17UnkClass_02007770D2Ev

	arm_func_start sub_0203E650
sub_0203E650: ; 0x0203E650
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_0203E650

	arm_func_start sub_0203E66C
sub_0203E66C: ; 0x0203E66C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x1d8]
	ldr r0, [r4, #0x1dc]
	cmp r1, r0
	ldreqb r1, [r4, #0x1e0]
	ldreqb r0, [r4, #0x1e1]
	cmpeq r1, r0
	beq _0203E6A8
	ldr r1, [r4, #0x1dc]
	mov r0, r4
	str r1, [r4, #0x1d8]
	ldrb r1, [r4, #0x1e1]
	strb r1, [r4, #0x1e0]
	bl sub_0203EE3C
	arm_func_end sub_0203E66C
_0203E6A8:
	ldr r0, [r4, #0x1a8]
	tst r0, #1
	beq _0203E734
	ldr r0, [r4, #0x1b4]
	cmp r0, #0
	blt _0203E6FC
	ldr r0, _0203E91C ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008E50Ev
	mov r1, r0
	mov r0, #0x3c
	bl _s32_div_f
	ldr r1, [r4, #0x1b4]
	sub r0, r1, r0
	str r0, [r4, #0x1b4]
	cmp r0, #0
	ldrle r0, [r4, #0x1a8]
	bicle r0, r0, #1
	strle r0, [r4, #0x1a8]
_0203E6FC:
	ldr r0, _0203E91C ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008E50Ev
	mov r1, r0
	mov r0, #0x12c
	bl _s32_div_f
	ldr r1, [r4, #0x1b0]
	add r0, r1, r0
	str r0, [r4, #0x1b0]
	cmp r0, #0x258
	subge r0, r0, #0x258
	strge r0, [r4, #0x1b0]
_0203E734:
	ldr r0, [r4, #0x1a8]
	tst r0, #4
	beq _0203E860
	ldr r0, [r4, #0x1cc]
	cmp r0, #0
	blt _0203E860
	sub r0, r0, #1
	str r0, [r4, #0x1cc]
	cmp r0, #0
	bgt _0203E77C
	ldr r1, [r4, #0x1a8]
	mov r0, #0
	bic r1, r1, #4
	str r1, [r4, #0x1a8]
	strb r0, [r4, #0x1d4]
	strb r0, [r4, #0x1d5]
	str r0, [r4, #0x1cc]
	b _0203E860
_0203E77C:
	ldrb r0, [r4, #0x1d4]
	cmp r0, #0
	beq _0203E7E0
	ldr r1, _0203E91C ; =_0208F304
	mov r0, r0, lsl #0x11
	ldr r1, [r1]
	movs lr, r0, lsr #0x10
	add r0, r1, #0x460
	add ip, r0, #0x1000
	add r0, r1, #0x1000
	ldr r1, [r0, #0x460]
	ldmib ip, {r2, r3}
	mla r1, r2, r1, r3
	str r1, [r0, #0x460]
	ldr r0, [ip]
	moveq r0, r0, lsr #0x10
	movne r0, r0, lsr #0x10
	mulne r1, r0, lr
	movne r0, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r2, r0, lsr #0x10
	ldrb r1, [r4, #0x1d4]
	add r0, r4, #0x100
	sub r1, r2, r1
	b _0203E7E8
_0203E7E0:
	add r0, r4, #0x100
	mov r1, #0
_0203E7E8:
	strh r1, [r0, #0xd0]
	ldrb r0, [r4, #0x1d5]
	cmp r0, #0
	beq _0203E854
	ldr r1, _0203E91C ; =_0208F304
	mov r0, r0, lsl #0x11
	ldr r1, [r1]
	movs lr, r0, lsr #0x10
	add r0, r1, #0x460
	add ip, r0, #0x1000
	add r0, r1, #0x1000
	ldr r1, [r0, #0x460]
	ldmib ip, {r2, r3}
	mla r1, r2, r1, r3
	str r1, [r0, #0x460]
	ldr r0, [ip]
	moveq r0, r0, lsr #0x10
	movne r0, r0, lsr #0x10
	mulne r1, r0, lr
	movne r0, r1, lsr #0x10
	mov r0, r0, lsl #0x10
	mov r2, r0, lsr #0x10
	ldrb r1, [r4, #0x1d5]
	add r0, r4, #0x100
	sub r1, r2, r1
	strh r1, [r0, #0xd2]
	b _0203E860
_0203E854:
	add r0, r4, #0x100
	mov r1, #0
	strh r1, [r0, #0xd2]
_0203E860:
	mov r0, r4
	bl _ZN6CActor12sub_020121F4Ev
	ldrb r2, [r4, #0x108]
	ldr r1, [r4, #0xc4]
	add r0, r4, #0x100
	str r2, [r1, #0x14]
	ldr r3, [r4, #0x134]
	ldr r2, [r4, #0xc4]
	ldr r1, [r4, #0x11c]
	str r1, [r2, #0x20]
	str r3, [r2, #0x24]
	ldrh r1, [r0, #0x4c]
	ldr r0, [r4, #0xc4]
	strh r1, [r0, #0x28]
	ldr r0, [r4, #0x1a8]
	tst r0, #2
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #0x1c0]
	cmp r0, #0
	ldmleia sp!, {r4, pc}
	ldr r0, [r4, #0x1bc]
	add r2, r0, #1
	str r2, [r4, #0x1bc]
	ldrb r0, [r4, #0x1c7]
	ldrb r1, [r4, #0x1c8]
	ldr r3, [r4, #0x1c0]
	mov r0, r0, lsl #0xc
	mov r1, r1, lsl #0xc
	bl _Z17LinearInterpolatellll
	mov r0, r0, asr #0xc
	strb r0, [r4, #0x1c6]
	ldr r1, [r4, #0x1bc]
	ldr r0, [r4, #0x1c0]
	cmp r1, r0
	ldmltia sp!, {r4, pc}
	mov r0, #0
	str r0, [r4, #0x1c0]
	str r0, [r4, #0x1bc]
	ldrb r0, [r4, #0x1c6]
	cmp r0, #0
	ldreq r0, [r4, #0x1a8]
	biceq r0, r0, #2
	streq r0, [r4, #0x1a8]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203E91C: .word s_game

	arm_func_start sub_0203E920
sub_0203E920: ; 0x0203E920
	ldr ip, _0203E92C ; =sub_0203E934
	mov r2, #0
	bx ip
	.align 2, 0
_0203E92C: .word sub_0203E934
	arm_func_end sub_0203E920

	arm_func_start sub_0203E930
sub_0203E930: ; 0x0203E930
	bx lr
	arm_func_end sub_0203E930

	arm_func_start sub_0203E934
sub_0203E934: ; 0x0203E934
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x40
	mov sb, r0
	ldr r0, [sb, #0x184]
	mov fp, r1
	mov sl, r2
	cmp r0, #0
	mov r6, #0
	beq _0203EE28
	ldr r2, [r0]
	ldrb r1, [sb, #0xc0]
	ldr r2, [r2, #0xc]
	blx r2
	str r0, [sp, #0xc]
	cmp r0, #0
	beq _0203EE28
	ldrb r0, [r0]
	tst r0, #1
	beq _0203EE28
	ldrb r1, [sb, #0xc0]
	ldr r0, [sp, #0xc]
	ldr r8, [sb, #0xc4]
	add r1, sb, r1, lsl #1
	ldrh r1, [r1, #0xc8]
	ldr r0, [r0, #0xc]
	bl _ZN17UnkClass_0200878812sub_02008828Et
	str sl, [r8, #4]
	ldr r1, [sb, #0x1f4]
	mov r4, r0
	cmp r1, #0
	beq _0203EA80
	ldr r0, [sp, #0xc]
	ldrb r0, [r0]
	tst r0, #1
	beq _0203EAC4
	ldrb r1, [sb, #0xc0]
	ldrb r0, [sb, #0x1c9]
	cmp r0, r1
	addeq r0, sb, #0x100
	ldreqh r0, [r0, #0xca]
	cmpeq r0, r4
	beq _0203EAC4
	ldr r0, [sb, #0x184]
	bl _ZN10CActorData12sub_02015070Eh
	ldr r2, [sb, #0x194]
	mov r1, #0x18
	mla r7, r0, r1, r2
	ldrb r2, [sb, #0x200]
	mov r0, r7
	mov r1, r4
	eor r2, r2, #1
	and r5, r2, #0xff
	bl _ZN17UnkClass_0200777012sub_020078E4Et
	mov r0, r7
	add r1, sb, r5, lsl #2
	ldr r1, [r1, #0x188]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_0200777012sub_02007A94Em
	mov r0, #0
	add r1, sb, r5, lsl #2
	ldr r1, [r1, #0x188]
	ldr r2, [r7, #0x14]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	ldr r3, [r7, #0x10]
	bl NNS_GfdRegisterNewVramTransferTask
	cmp r0, #0
	beq _0203EAC4
	strb r5, [sb, #0x200]
	str r7, [r8, #0x30]
	mov r0, #0
	str r0, [r8, #0x2c]
	ldr r0, [sp, #0xc]
	ldr r1, [r0, #8]
	add r0, sb, #0x100
	str r1, [r8, #0x38]
	strh r4, [r8, #0x2a]
	ldrb r1, [sb, #0xc0]
	strb r1, [sb, #0x1c9]
	strh r4, [r0, #0xca]
	bl NNS_GfdGetVramTransferTaskTotalSize
	b _0203EAC4
	arm_func_end sub_0203E934
_0203EA80:
	ldr r0, [sb, #0x184]
	ldrb r1, [sb, #0xc0]
	ldr r2, [r0]
	ldr r2, [r2, #0xc]
	blx r2
	ldr r1, [r0, #4]
	mov r0, r6
	str r1, [r8, #0x2c]
	str r0, [r8, #0x30]
	ldr r0, [sp, #0xc]
	ldr r1, [r0, #8]
	add r0, sb, #0x100
	str r1, [r8, #0x38]
	strh r4, [r8, #0x2a]
	ldrb r1, [sb, #0xc0]
	strb r1, [sb, #0x1c9]
	strh r4, [r0, #0xca]
_0203EAC4:
	ldr r2, [sb, #0x1a8]
	ldr r1, [r8, #0x18]
	tst r2, #4
	ldr r0, [r8, #0x1c]
	ldrh r2, [r8, #8]
	str r1, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r2, [sp, #8]
	ldr r2, [r8, #0x14]
	str r1, [sp, #0x38]
	str r2, [sp, #4]
	ldr r2, [r8, #0x3c]
	str r0, [sp, #0x3c]
	str r2, [sp]
	beq _0203EB1C
	add r2, sb, #0x100
	ldrsh r3, [r2, #0xd0]
	ldrsh r2, [r2, #0xd2]
	add r1, r1, r3, lsl #12
	add r0, r0, r2, lsl #12
	str r1, [sp, #0x38]
	str r0, [sp, #0x3c]
_0203EB1C:
	ldr r2, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	str r2, [r8, #0x18]
	str r1, [r8, #0x1c]
	ldr r0, [sb, #0x1a8]
	str r2, [sp, #0x20]
	str r1, [sp, #0x24]
	tst r0, #2
	beq _0203EBAC
	add r0, sb, #0x100
	ldrh r3, [r0, #0xb8]
	ldrb r1, [sb, #0x1c6]
	ldr r0, [sp, #4]
	ldr r2, _0203EE34 ; =0x84210843
	mul r4, r1, r0
	smull r1, r5, r2, r4
	mov r0, r4, lsr #0x1f
	add r5, r4, r5
	add r5, r0, r5, asr #4
	strh r3, [r8, #8]
	str r5, [r8, #0x14]
	mov r0, #1
	str r0, [r8, #0x3c]
	mov r0, r8
	str sl, [r8, #4]
	ldr r2, [r0]
	mov r1, fp
	ldr r2, [r2, #8]
	blx r2
	ldr r1, [sp, #8]
	add r6, r6, r0
	strh r1, [r8, #8]
	ldr r1, [sp, #4]
	str r1, [r8, #0x14]
	ldr r1, [sp]
	str r1, [r8, #0x3c]
_0203EBAC:
	sub r1, sl, r6
	mov r0, r8
	str r1, [r8, #4]
	ldr r2, [r0]
	mov r1, fp
	ldr r2, [r2, #8]
	blx r2
	ldr r1, [sb, #0x1a8]
	add r6, r6, r0
	tst r1, #1
	beq _0203ED44
	add r0, sb, #0x100
	ldrh r3, [r0, #0xac]
	ldr r2, [sb, #0x1b0]
	mov r7, #0
	and r1, r3, #0x3e0
	and r0, r3, #0x7c00
	and r4, r3, #0x1f
	cmp r2, #0x12c
	mov r3, r1, asr #5
	rsblt r1, r2, #0x12c
	rsblt r5, r1, r1, lsl #5
	subge r1, r2, #0x12c
	rsbge r5, r1, r1, lsl #5
	rsbge r2, r2, #0x258
	mla r1, r4, r2, r5
	mov r0, r0, asr #0xa
	mla r4, r3, r2, r5
	mla r3, r0, r2, r5
	ldr r2, _0203EE38 ; =0x1B4E81B5
	mov r5, r1, lsr #0x1f
	smull r1, r0, r2, r1
	add r0, r5, r0, asr #5
	smull r5, r1, r2, r4
	mov r4, r4, lsr #0x1f
	add r1, r4, r1, asr #5
	smull r5, r4, r2, r3
	mov r2, r3, lsr #0x1f
	add r4, r2, r4, asr #5
	orr r0, r0, r1, lsl #5
	orr r3, r0, r4, lsl #10
	ldrb r2, [sb, #0x1c5]
	ldr r0, [sp, #4]
	mul r4, r2, r0
	ldr r2, _0203EE34 ; =0x84210843
	mov r0, r4, lsr #0x1f
	smull r1, r5, r2, r4
	add r5, r4, r5
	add r5, r0, r5, asr #4
	strh r3, [r8, #8]
	str r5, [r8, #0x14]
	mov r0, #1
	ldr r5, [sp, #0x38]
	ldr r4, [sp, #0x3c]
	str r0, [r8, #0x3c]
_0203EC88:
	str r5, [sp, #0x30]
	str r4, [sp, #0x34]
	cmp r7, #3
	addls pc, pc, r7, lsl #2
	b _0203ECE8
_0203EC9C: ; jump table
	b _0203ECAC ; case 0
	b _0203ECBC ; case 1
	b _0203ECCC ; case 2
	b _0203ECDC ; case 3
_0203ECAC:
	ldrb r0, [sb, #0x1c4]
	add r0, r5, r0, lsl #12
	str r0, [sp, #0x30]
	b _0203ECE8
_0203ECBC:
	ldrb r0, [sb, #0x1c4]
	sub r0, r5, r0, lsl #12
	str r0, [sp, #0x30]
	b _0203ECE8
_0203ECCC:
	ldrb r0, [sb, #0x1c4]
	add r0, r4, r0, lsl #12
	str r0, [sp, #0x34]
	b _0203ECE8
_0203ECDC:
	ldrb r0, [sb, #0x1c4]
	sub r0, r4, r0, lsl #12
	str r0, [sp, #0x34]
_0203ECE8:
	ldr r1, [sp, #0x30]
	ldr r0, [sp, #0x34]
	str r1, [sp, #0x18]
	str r1, [r8, #0x18]
	str r0, [r8, #0x1c]
	sub r1, sl, r6
	str r0, [sp, #0x1c]
	mov r0, r8
	str r1, [r8, #4]
	ldr r2, [r0]
	mov r1, fp
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, r0
	add r7, r7, #1
	cmp r7, #4
	blt _0203EC88
	ldr r0, [sp, #8]
	strh r0, [r8, #8]
	ldr r0, [sp, #4]
	str r0, [r8, #0x14]
	ldr r0, [sp]
	str r0, [r8, #0x3c]
_0203ED44:
	ldr r2, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	str r2, [r8, #0x18]
	mov r0, sb
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [r8, #0x1c]
	bl _ZN6CActor12sub_02012D88Ev
	cmp r0, #0
	beq _0203EE28
	mov r0, sb
	bl _ZN6CActor12sub_02012DA8Ev
	mov r5, #0
	mov r4, r0
	mov r7, r5
_0203ED80:
	mov r0, sb
	mov r1, r5
	bl _ZN6CActor12sub_02012D9CEi
	cmp r0, #0
	beq _0203EE18
	sub r0, sl, r6
	str r0, [r4, #4]
	ldr r0, [sp, #0xc]
	ldr r1, [r0, #8]
	mov r0, sb
	str r1, [r4, #0x38]
	ldrh r2, [r8, #0x2a]
	mov r1, r5
	strh r2, [r4, #0x2a]
	bl _ZN6CActor12sub_02012DB0Ei
	str r0, [r4, #0x14]
	mov r0, sb
	mov r1, r5
	bl _ZN6CActor12sub_02012DC0Ei
	str r0, [r4, #0x20]
	str r0, [r4, #0x24]
	ldr r0, [sb, #0x1f4]
	cmp r0, #0
	beq _0203EDF0
	ldr r0, [r8, #0x30]
	str r0, [r4, #0x30]
	str r7, [r4, #0x2c]
	b _0203EE00
_0203EDF0:
	ldr r0, [r8, #0x2c]
	str r0, [r4, #0x2c]
	mov r0, #0
	str r0, [r4, #0x30]
_0203EE00:
	mov r0, r4
	ldr r2, [r0]
	mov r1, fp
	ldr r2, [r2, #8]
	blx r2
	add r6, r6, r0
_0203EE18:
	add r5, r5, #1
	cmp r5, #8
	add r4, r4, #0x4c
	blt _0203ED80
_0203EE28:
	mov r0, r6
	add sp, sp, #0x40
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0203EE34: .word 0x84210843
_0203EE38: .word 0x1B4E81B5

	arm_func_start sub_0203EE3C
sub_0203EE3C: ; 0x0203EE3C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x1d8]
	cmp r1, #0
	beq _0203EE60
	cmp r1, #1
	beq _0203EE84
	cmp r1, #3
	ldmia sp!, {r4, pc}
	arm_func_end sub_0203EE3C
_0203EE60:
	ldrb r2, [r4, #0x1e0]
	ldr r1, [r4, #0x1a0]
	ldr r3, [r4, #0x19c]
	bl _ZN6CActor12sub_02012184Eiil
	ldrb r2, [r4, #0x1e0]
	ldr r1, [r4, #0x1a0]
	mov r0, r4
	bl _ZN6CActor12sub_02012114Eii
	ldmia sp!, {r4, pc}
_0203EE84:
	ldrb r2, [r4, #0x1e0]
	ldr r1, [r4, #0x1a4]
	ldr r3, [r4, #0x19c]
	bl _ZN6CActor12sub_02012184Eiil
	ldrb r2, [r4, #0x1e0]
	ldr r1, [r4, #0x1a4]
	mov r0, r4
	bl _ZN6CActor12sub_02012114Eii
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203EEA8
sub_0203EEA8: ; 0x0203EEA8
	stmdb sp!, {r3, lr}
	ldr lr, [r0, #0x1a8]
	add ip, r0, #0x100
	orr lr, lr, #2
	str lr, [r0, #0x1a8]
	strh r1, [ip, #0xb8]
	mov r1, #0
	str r1, [r0, #0x1bc]
	cmp r3, #0
	strleb r2, [r0, #0x1c6]
	strle r1, [r0, #0x1c0]
	ldmleia sp!, {r3, pc}
	strb r1, [r0, #0x1c6]
	str r3, [r0, #0x1c0]
	strb r1, [r0, #0x1c7]
	strb r2, [r0, #0x1c8]
	ldmia sp!, {r3, pc}
	arm_func_end sub_0203EEA8

	arm_func_start sub_0203EEEC
sub_0203EEEC: ; 0x0203EEEC
	mov r2, #0
	str r2, [r0, #0x1bc]
	cmp r1, #0
	ldrle r1, [r0, #0x1a8]
	bicle r1, r1, #2
	strle r1, [r0, #0x1a8]
	bxle lr
	str r1, [r0, #0x1c0]
	ldrb r1, [r0, #0x1c6]
	strb r1, [r0, #0x1c7]
	strb r2, [r0, #0x1c8]
	bx lr
	arm_func_end sub_0203EEEC

	arm_func_start _ZN17CFieldActorManageC2Ev
_ZN17CFieldActorManageC2Ev: ; 0x0203EF1C
	ldr r2, _0203EF3C ; =PTR_LAB_0208ddc0
	mov r1, #0xff
	str r2, [r0]
	strb r1, [r0, #0xc]
	mov r1, #0
	str r1, [r0, #8]
	str r1, [r0, #4]
	bx lr
	.align 2, 0
_0203EF3C: .word PTR_LAB_0208ddc0
	arm_func_end _ZN17CFieldActorManageC2Ev

	arm_func_start sub_0203EF40
sub_0203EF40: ; 0x0203EF40
	ldr r2, _0203EF60 ; =PTR_LAB_0208ddc0
	mov r1, #0xff
	str r2, [r0]
	strb r1, [r0, #0xc]
	mov r1, #0
	str r1, [r0, #8]
	str r1, [r0, #4]
	bx lr
	.align 2, 0
_0203EF60: .word PTR_LAB_0208ddc0
	arm_func_end sub_0203EF40

	arm_func_start sub_0203EF64
sub_0203EF64: ; 0x0203EF64
	stmdb sp!, {r4, lr}
	ldr r1, _0203EF88 ; =PTR_LAB_0208ddc0
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203EF88: .word PTR_LAB_0208ddc0
	arm_func_end sub_0203EF64

	arm_func_start sub_0203EF8C
sub_0203EF8C: ; 0x0203EF8C
	stmdb sp!, {r4, lr}
	ldr r1, _0203EFB8 ; =PTR_LAB_0208ddc0
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
_0203EFB8: .word PTR_LAB_0208ddc0
	arm_func_end sub_0203EF8C

	arm_func_start _ZN17CFieldActorManageD2Ev
_ZN17CFieldActorManageD2Ev: ; 0x0203EFBC
	stmdb sp!, {r4, lr}
	ldr r1, _0203EFE0 ; =PTR_LAB_0208ddc0
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203EFE0: .word PTR_LAB_0208ddc0
	arm_func_end _ZN17CFieldActorManageD2Ev

	arm_func_start _ZN17CFieldActorManage12sub_0203EFE4Ei
_ZN17CFieldActorManage12sub_0203EFE4Ei: ; 0x0203EFE4
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, [r0]
	mov r5, r0
	ldr r2, [r2, #0xc]
	mov r4, r1
	blx r2
	str r4, [r5, #4]
	mov r0, r4, lsl #2
	bl _Znam
	str r0, [r5, #8]
	cmp r4, #0
	mov r2, #0
	ldmleia sp!, {r3, r4, r5, pc}
	mov r1, r2
	arm_func_end _ZN17CFieldActorManage12sub_0203EFE4Ei
_0203F01C:
	ldr r0, [r5, #8]
	str r1, [r0, r2, lsl #2]
	add r2, r2, #1
	cmp r2, r4
	blt _0203F01C
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F034Ev
_ZN17CFieldActorManage12sub_0203F034Ev: ; 0x0203F034
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r1, [r4, #4]
	cmp r1, #0
	ble _0203F09C
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203F09C
	cmp r1, #0
	mov r6, #0
	ble _0203F09C
	mov r5, r6
	arm_func_end _ZN17CFieldActorManage12sub_0203F034Ev
_0203F064:
	ldr r0, [r4, #8]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	beq _0203F08C
	beq _0203F084
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203F084:
	ldr r0, [r4, #8]
	str r5, [r0, r6, lsl #2]
_0203F08C:
	ldr r0, [r4, #4]
	add r6, r6, #1
	cmp r6, r0
	blt _0203F064
_0203F09C:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203F0B4
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #8]
_0203F0B4:
	mov r0, #0
	str r0, [r4, #4]
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F0C0Ev
_ZN17CFieldActorManage12sub_0203F0C0Ev: ; 0x0203F0C0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r3, [r5, #4]
	cmp r3, #0
	ble _0203F13C
	ldr ip, [r5, #8]
	cmp ip, #0
	beq _0203F13C
	cmp r3, #0
	mov r4, #0
	ble _0203F13C
	arm_func_end _ZN17CFieldActorManage12sub_0203F0C0Ev
_0203F0EC:
	ldr r0, [ip, r4, lsl #2]
	cmp r0, #0
	beq _0203F130
	ldr r2, [r0, #0x58]
	cmp r1, r2
	bne _0203F130
	cmp r0, #0
	beq _0203F128
	beq _0203F11C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203F11C:
	ldr r0, [r5, #8]
	mov r1, #0
	str r1, [r0, r4, lsl #2]
_0203F128:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_0203F130:
	add r4, r4, #1
	cmp r4, r3
	blt _0203F0EC
_0203F13C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F144Ei
_ZN17CFieldActorManage12sub_0203F144Ei: ; 0x0203F144
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	mov r4, r1
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _0203F188
	beq _0203F180
	beq _0203F174
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end _ZN17CFieldActorManage12sub_0203F144Ei
_0203F174:
	ldr r0, [r5, #8]
	mov r1, #0
	str r1, [r0, r4, lsl #2]
_0203F180:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_0203F188:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F190Ev
_ZN17CFieldActorManage12sub_0203F190Ev: ; 0x0203F190
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r1, [r4, #4]
	cmp r1, #0
	ble _0203F1F4
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0203F1F4
	subs r6, r1, #1
	bmi _0203F1EC
	mov r5, #0
	arm_func_end _ZN17CFieldActorManage12sub_0203F190Ev
_0203F1BC:
	ldr r0, [r4, #8]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	beq _0203F1E4
	beq _0203F1DC
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0203F1DC:
	ldr r0, [r4, #8]
	str r5, [r0, r6, lsl #2]
_0203F1E4:
	subs r6, r6, #1
	bpl _0203F1BC
_0203F1EC:
	mov r0, #1
	ldmia sp!, {r4, r5, r6, pc}
_0203F1F4:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F1FCEv
_ZN17CFieldActorManage12sub_0203F1FCEv: ; 0x0203F1FC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr ip, [r0, #4]
	mov r5, r2
	mov r4, r3
	cmp r1, ip
	bge _0203F270
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, r1, lsl #2]
	cmpne r0, #0
	beq _0203F270
	ldr r6, [r0, #8]
	cmp r6, #0
	ldrne r7, [r6, #0xc]
	cmpne r7, #0
	beq _0203F268
	mov r1, r5
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r4
	add r0, r7, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r6, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r5, [r0, #0x18]
	strne r4, [r0, #0x1c]
	arm_func_end _ZN17CFieldActorManage12sub_0203F1FCEv
_0203F268:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_0203F270:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F278Ev
_ZN17CFieldActorManage12sub_0203F278Ev: ; 0x0203F278
	ldr ip, [r0, #4]
	cmp r1, ip
	bge _0203F2A8
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, r1, lsl #2]
	cmpne r0, #0
	beq _0203F2A8
	str r2, [r0, #0x18]
	str r3, [r0, #0x1c]
	mov r0, #1
	bx lr
	arm_func_end _ZN17CFieldActorManage12sub_0203F278Ev
_0203F2A8:
	mov r0, #0
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_0203F2B0EP9CFieldMapi
_ZN17CFieldActorManage12sub_0203F2B0EP9CFieldMapi: ; 0x0203F2B0
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov sb, r0
	ldr r0, [sb, #8]
	mov r8, r1
	mov r7, r2
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	ldr r0, [sb, #4]
	mov r6, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r4, r6
	mov r5, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F2B0EP9CFieldMapi
_0203F2E4:
	ldr r0, [sb, #8]
	ldr r0, [r0, r6, lsl #2]
	cmp r0, #0
	beq _0203F334
	ldrb r1, [r0, #0x20]
	mov r2, r5
	cmp r1, #2
	cmpne r1, #3
	movne r2, r4
	cmp r2, #0
	beq _0203F334
	cmp r7, #0
	ldr r2, [r0]
	mov r1, r8
	beq _0203F32C
	ldr r2, [r2, #0x24]
	blx r2
	b _0203F334
_0203F32C:
	ldr r2, [r2, #0x28]
	blx r2
_0203F334:
	ldr r0, [sb, #4]
	add r6, r6, #1
	cmp r6, r0
	blt _0203F2E4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F348EP17UnkClass_0211E3FCP17UnkClass_020416AC
_ZN17CFieldActorManage12sub_0203F348EP17UnkClass_0211E3FCP17UnkClass_020416AC: ; 0x0203F348
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r8, r0
	ldr r0, [r8, #8]
	mov r7, r1
	mov r6, r2
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	ldr r0, [r8, #4]
	mov r5, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov sb, r5
	mov r4, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F348EP17UnkClass_0211E3FCP17UnkClass_020416AC
_0203F37C:
	ldr r0, [r8, #8]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	beq _0203F3B4
	ldrb r1, [r0, #0x20]
	mov r2, r4
	cmp r1, #2
	cmpne r1, #3
	movne r2, sb
	cmp r2, #0
	beq _0203F3B4
	mov r1, r7
	mov r2, r6
	bl sub_0203C590
_0203F3B4:
	ldr r0, [r8, #4]
	add r5, r5, #1
	cmp r5, r0
	blt _0203F37C
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start sub_0203F3C8
sub_0203F3C8: ; 0x0203F3C8
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r0, [r5, #4]
	mov r4, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r6, r4
	mov r7, #1
	arm_func_end sub_0203F3C8
_0203F3F4:
	ldr r0, [r5, #8]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _0203F42C
	ldrb r1, [r0, #0x20]
	mov r2, r7
	cmp r1, #2
	cmpne r1, #3
	movne r2, r6
	cmp r2, #0
	beq _0203F42C
	ldr r1, [r0]
	ldr r1, [r1, #0x34]
	blx r1
_0203F42C:
	ldr r0, [r5, #4]
	add r4, r4, #1
	cmp r4, r0
	blt _0203F3F4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_0203F440
sub_0203F440: ; 0x0203F440
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r5, r0
	ldr r0, [r5, #8]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r0, [r5, #4]
	mov r4, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r6, r4
	mov r7, #1
	arm_func_end sub_0203F440
_0203F46C:
	ldr r0, [r5, #8]
	ldr r0, [r0, r4, lsl #2]
	cmp r0, #0
	beq _0203F4A4
	ldrb r1, [r0, #0x20]
	mov r2, r7
	cmp r1, #2
	cmpne r1, #3
	movne r2, r6
	cmp r2, #0
	beq _0203F4A4
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
_0203F4A4:
	ldr r0, [r5, #4]
	add r4, r4, #1
	cmp r4, r0
	blt _0203F46C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F4B8Ev
_ZN17CFieldActorManage12sub_0203F4B8Ev: ; 0x0203F4B8
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	ldr r4, [r0, #8]
	cmp r4, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r4, [r0, #4]
	mov r6, #0
	cmp r4, #0
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	mov r4, r6
	mov r5, #1
	mov lr, r6
	mov ip, r6
	mov sb, r6
	arm_func_end _ZN17CFieldActorManage12sub_0203F4B8Ev
_0203F4EC:
	ldr r7, [r0, #8]
	ldr r7, [r7, r6, lsl #2]
	cmp r7, #0
	beq _0203F578
	ldrb r8, [r7, #0x20]
	mov sl, r5
	cmp r8, #2
	cmpne r8, #3
	movne sl, r4
	cmp sl, #0
	ldrne r8, [r7, #8]
	cmpne r8, #0
	beq _0203F578
	ldr r8, [r8, #0xc]
	cmp r8, #0
	strne lr, [r8, #0x1b0]
	ldr r8, [r7, #8]
	ldr sl, [r8, #0xc]
	cmp sl, #0
	addne r8, sl, #0x100
	strneh r1, [r8, #0xac]
	strne ip, [sl, #0x1b0]
	ldr r8, [r7, #8]
	ldr r8, [r8, #0xc]
	cmp r8, #0
	strneb r2, [r8, #0x1c4]
	ldr r7, [r7, #8]
	ldr r8, [r7, #0xc]
	cmp r8, #0
	beq _0203F578
	ldr r7, [r8, #0x1a8]
	orr r7, r7, #1
	str r7, [r8, #0x1a8]
	str r3, [r8, #0x1b4]
	str sb, [r8, #0x1b0]
_0203F578:
	ldr r7, [r0, #4]
	add r6, r6, #1
	cmp r6, r7
	blt _0203F4EC
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F58CEv
_ZN17CFieldActorManage12sub_0203F58CEv: ; 0x0203F58C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, [r0, #8]
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r2, [r0, #4]
	mov lr, #0
	cmp r2, #0
	ldmleia sp!, {r3, r4, r5, pc}
	mov r3, lr
	mov ip, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F58CEv
_0203F5B4:
	ldr r2, [r0, #8]
	ldr r5, [r2, lr, lsl #2]
	cmp r5, #0
	beq _0203F5F0
	ldrb r2, [r5, #0x20]
	mov r4, ip
	cmp r2, #2
	cmpne r2, #3
	movne r4, r3
	cmp r4, #0
	ldrne r2, [r5, #8]
	cmpne r2, #0
	ldrne r2, [r2, #0xc]
	cmpne r2, #0
	strneb r1, [r2, #0x1c4]
_0203F5F0:
	ldr r2, [r0, #4]
	add lr, lr, #1
	cmp lr, r2
	blt _0203F5B4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F604Ev
_ZN17CFieldActorManage12sub_0203F604Ev: ; 0x0203F604
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, [r0, #8]
	cmp r2, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r2, [r0, #4]
	mov r5, #0
	cmp r2, #0
	ldmleia sp!, {r4, r5, r6, pc}
	mov lr, r5
	mov r4, #1
	mov r3, r5
	arm_func_end _ZN17CFieldActorManage12sub_0203F604Ev
_0203F630:
	ldr r2, [r0, #8]
	ldr r6, [r2, r5, lsl #2]
	cmp r6, #0
	beq _0203F674
	ldrb r2, [r6, #0x20]
	mov ip, r4
	cmp r2, #2
	cmpne r2, #3
	movne ip, lr
	cmp ip, #0
	ldrne r2, [r6, #8]
	cmpne r2, #0
	ldrne ip, [r2, #0xc]
	cmpne ip, #0
	addne r2, ip, #0x100
	strneh r1, [r2, #0xac]
	strne r3, [ip, #0x1b0]
_0203F674:
	ldr r2, [r0, #4]
	add r5, r5, #1
	cmp r5, r2
	blt _0203F630
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F688Ev
_ZN17CFieldActorManage12sub_0203F688Ev: ; 0x0203F688
	stmdb sp!, {r3, r4, r5, lr}
	ldr r2, [r0, #8]
	cmp r2, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r2, [r0, #4]
	mov lr, #0
	cmp r2, #0
	ldmleia sp!, {r3, r4, r5, pc}
	mov r3, lr
	mov ip, #1
	arm_func_end _ZN17CFieldActorManage12sub_0203F688Ev
_0203F6B0:
	ldr r2, [r0, #8]
	ldr r5, [r2, lr, lsl #2]
	cmp r5, #0
	beq _0203F6EC
	ldrb r2, [r5, #0x20]
	mov r4, ip
	cmp r2, #2
	cmpne r2, #3
	movne r4, r3
	cmp r4, #0
	ldrne r2, [r5, #8]
	cmpne r2, #0
	ldrne r2, [r2, #0xc]
	cmpne r2, #0
	strneb r1, [r2, #0x1c5]
_0203F6EC:
	ldr r2, [r0, #4]
	add lr, lr, #1
	cmp lr, r2
	blt _0203F6B0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17CFieldActorManage12sub_0203F700Ev
_ZN17CFieldActorManage12sub_0203F700Ev: ; 0x0203F700
	ldr r1, [r0, #8]
	cmp r1, #0
	bxeq lr
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	mov r2, r3
	arm_func_end _ZN17CFieldActorManage12sub_0203F700Ev
_0203F720:
	ldr r1, [r0, #8]
	ldr r1, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r1, #0
	ldrne r1, [r1, #8]
	cmpne r1, #0
	ldrne r1, [r1, #0xc]
	cmpne r1, #0
	strne r2, [r1, #0x1b0]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0203F720
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_0203F754Ev
_ZN17CFieldActorManage12sub_0203F754Ev: ; 0x0203F754
	ldr r1, [r0, #8]
	cmp r1, #0
	bxeq lr
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	arm_func_end _ZN17CFieldActorManage12sub_0203F754Ev
_0203F770:
	ldr r1, [r0, #8]
	ldr r1, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r1, #0
	ldrne r1, [r1, #8]
	cmpne r1, #0
	ldrne r2, [r1, #0xc]
	cmpne r2, #0
	ldrne r1, [r2, #0x1a8]
	bicne r1, r1, #1
	strne r1, [r2, #0x1a8]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0203F770
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_0203F7ACEv
_ZN17CFieldActorManage12sub_0203F7ACEv: ; 0x0203F7AC
	ldr r1, [r0, #8]
	cmp r1, #0
	bxeq lr
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	arm_func_end _ZN17CFieldActorManage12sub_0203F7ACEv
_0203F7C8:
	ldr r1, [r0, #8]
	ldr r2, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r2, #0
	ldrne r1, [r2, #4]
	bicne r1, r1, #0x100
	strne r1, [r2, #4]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0203F7C8
	bx lr

	arm_func_start sub_0203F7F4
sub_0203F7F4: ; 0x0203F7F4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x348
	sub sp, sp, #0x800
	mov sl, r0
	ldr r5, [sl, #4]
	mov r0, #0x14
	mov r4, r2
	mul r2, r5, r0
	mov r6, #0
	mov sb, r3
	ldr r3, [sp, #0xb68]
	mov r5, r1
	add r1, sp, #0x148
	mov r0, r6
	str r6, [sp, #0x3c]
	str r3, [sp, #0xb68]
	bl MIi_CpuClear32
	ldr r0, [sl, #4]
	mov r7, r6
	cmp r0, #0
	ble _0203FB68
	arm_func_end sub_0203F7F4
_0203F848:
	ldr r0, [sl, #8]
	ldr r8, [r0, r7, lsl #2]
	cmp r8, #0
	beq _0203FB58
	ldr r0, [r8, #4]
	mov r1, #1
	tst r0, #0x80
	ldrb r0, [r8, #0x20]
	moveq r2, #1
	movne r2, #0
	cmp r0, #2
	cmpne r0, #3
	movne r1, #0
	tst r1, r2
	beq _0203FB58
	ldr r0, [r8, #0x14]
	cmp sb, r0
	bne _0203FB58
	ldr r0, [r8, #0x50]
	cmp r0, #0
	beq _0203F8A8
	cmp r0, #1
	beq _0203FA08
	b _0203FB58
_0203F8A8:
	add r0, r8, #0x34
	add ip, sp, #0x138
	ldmia r0, {r0, r1, r2, r3}
	stmia ip, {r0, r1, r2, r3}
	ldr r0, [sp, #0x140]
	cmp r0, #0
	ldrne r0, [sp, #0x144]
	cmpne r0, #0
	beq _0203FB58
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203F8EC
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203F8F0
_0203F8EC:
	mov r2, #0
_0203F8F0:
	ldr r0, [sp, #0x138]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x138]
	beq _0203F918
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r3, [r0, #0x24]
	moveq r3, #0
	b _0203F91C
_0203F918:
	mov r3, #0
_0203F91C:
	ldr r0, [sp, #0x13c]
	ldr r2, [sp, #0x140]
	add r0, r0, r3
	add r3, r2, r4, lsl #1
	ldr r1, [sp, #0x144]
	mov ip, sp
	add r2, r1, r4, lsl #1
	add r1, sp, #0x138
	str r0, [sp, #0x13c]
	str r3, [sp, #0x140]
	str r2, [sp, #0x144]
	ldmia r1, {r0, r1, r2, r3}
	stmia ip, {r0, r1, r2, r3}
	add r0, sp, #0xd8
	str r0, [sp, #0x10]
	ldmia r5, {r0, r1, r2, r3}
	bl _Z12sub_02006C0411PointPair2D9RectangleP7Point2D
	cmp r0, #0
	beq _0203FB58
	mov r0, #0x14
	mul r0, r6, r0
	add r2, sp, #0x148
	str r8, [r2, r0]
	add r8, r2, r0
	ldr r1, [sp, #0xd8]
	ldr r0, [sp, #0xdc]
	str r1, [r8, #8]
	str r0, [r8, #0xc]
	ldr r3, [sp, #0xd8]
	ldmia r5, {r0, r1}
	ldr r2, [sp, #0xdc]
	sub r0, r3, r0
	sub r1, r2, r1
	bl _Z12sub_02007254ll
	cmp r6, #0
	str r0, [r8, #4]
	streq r8, [sp, #0x3c]
	beq _0203FA00
	ldr r2, [sp, #0x3c]
	mov r1, #0
	movs r0, r2
	beq _0203F9F8
	ldr r3, [r8, #4]
_0203F9C8:
	ldr r0, [r2, #4]
	cmp r3, r0
	bge _0203F9E8
	cmp r1, #0
	strne r8, [r1, #0x10]
	streq r8, [sp, #0x3c]
	str r2, [r8, #0x10]
	b _0203F9F8
_0203F9E8:
	mov r1, r2
	ldr r2, [r2, #0x10]
	cmp r2, #0
	bne _0203F9C8
_0203F9F8:
	cmp r2, #0
	streq r8, [r1, #0x10]
_0203FA00:
	add r6, r6, #1
	b _0203FB58
_0203FA08:
	add r0, r8, #0x44
	add r3, sp, #0x12c
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldr r0, [sp, #0x134]
	cmp r0, #0
	beq _0203FB58
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203FA44
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203FA48
_0203FA44:
	mov r2, #0
_0203FA48:
	ldr r0, [sp, #0x12c]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x12c]
	beq _0203FA70
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x24]
	moveq r2, #0
	b _0203FA74
_0203FA70:
	mov r2, #0
_0203FA74:
	ldr r1, [sp, #0x130]
	ldr r0, [sp, #0x134]
	add r2, r1, r2
	add r1, r0, r4
	add r0, sp, #0x12c
	mov r3, sp
	str r2, [sp, #0x130]
	str r1, [sp, #0x134]
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	add r1, sp, #0xd8
	mov r0, #0
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	ldmia r5, {r0, r1, r2, r3}
	bl _Z12sub_0200676411PointPair2D6CircleP7Point2Dl
	cmp r0, #0
	beq _0203FB58
	mov r0, #0x14
	mul r0, r6, r0
	add r2, sp, #0x148
	str r8, [r2, r0]
	add r8, r2, r0
	ldr r1, [sp, #0xd8]
	ldr r0, [sp, #0xdc]
	str r1, [r8, #8]
	str r0, [r8, #0xc]
	ldr r3, [sp, #0xd8]
	ldmia r5, {r0, r1}
	ldr r2, [sp, #0xdc]
	sub r0, r3, r0
	sub r1, r2, r1
	bl _Z12sub_02007254ll
	cmp r6, #0
	str r0, [r8, #4]
	streq r8, [sp, #0x3c]
	beq _0203FB54
	ldr r2, [sp, #0x3c]
	mov r1, #0
	movs r0, r2
	beq _0203FB4C
	ldr r3, [r8, #4]
_0203FB1C:
	ldr r0, [r2, #4]
	cmp r3, r0
	bge _0203FB3C
	cmp r1, #0
	strne r8, [r1, #0x10]
	streq r8, [sp, #0x3c]
	str r2, [r8, #0x10]
	b _0203FB4C
_0203FB3C:
	mov r1, r2
	ldr r2, [r2, #0x10]
	cmp r2, #0
	bne _0203FB1C
_0203FB4C:
	cmp r2, #0
	streq r8, [r1, #0x10]
_0203FB54:
	add r6, r6, #1
_0203FB58:
	ldr r0, [sl, #4]
	add r7, r7, #1
	cmp r7, r0
	blt _0203F848
_0203FB68:
	cmp r6, #0
	beq _02040148
	ldr r1, [r5, #8]
	ldr r0, [r5]
	ldr r2, [r5, #0xc]
	subs r0, r1, r0
	ldr r1, [r5, #4]
	rsbmi r0, r0, #0
	subs r1, r2, r1
	rsbmi r1, r1, #0
	bl _Z12sub_02007254ll
	mov r6, #0
	str r0, [sp, #0x34]
	mov r0, r6
_0203FBA0:
	add r0, r0, #1
	cmp r0, #4
	add r6, r6, r4, asr r0
	blt _0203FBA0
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq _02040148
	ldr r0, [sp, #0x34]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x38]
_0203FBC8:
	ldr r0, [sp, #0x3c]
	ldr r8, [r0]
	ldr r0, [r8, #0x50]
	cmp r0, #0
	beq _0203FBE8
	cmp r0, #1
	beq _0203FE38
	b _02040134
_0203FBE8:
	add r0, r8, #0x34
	add r7, sp, #0x110
	ldmia r0, {r0, r1, r2, r3}
	stmia r7, {r0, r1, r2, r3}
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203FC18
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203FC1C
_0203FC18:
	mov r2, #0
_0203FC1C:
	ldr r0, [sp, #0x110]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x110]
	beq _0203FC44
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x24]
	moveq r2, #0
	b _0203FC48
_0203FC44:
	mov r2, #0
_0203FC48:
	ldr r1, [sp, #0x114]
	add r0, sp, #0xec
	mov r7, #0
	add r1, r1, r2
	str r1, [sp, #0x114]
	str r7, [r0]
	str r7, [r0, #4]
	str r7, [r0, #8]
	ldr r0, [sp, #0x34]
	ldr r2, [r5]
	ldr r1, [r5, #4]
	cmp r0, #0
	str r2, [sp, #0xec]
	str r1, [sp, #0xf0]
	str r4, [sp, #0xf4]
	str r2, [sp, #0x120]
	str r1, [sp, #0x124]
	str r4, [sp, #0x128]
	ldr r3, [r5]
	ldr r0, [r5, #8]
	ldr r2, [r5, #4]
	sub r0, r0, r3
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x1c]
	sub r0, r1, r2
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x1c]
	str r3, [sp, #0x98]
	str r0, [sp, #0x90]
	ldr r0, [sp, #0x14]
	str r2, [sp, #0x9c]
	str r0, [sp, #0x94]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0xc8]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0xcc]
	ble _02040134
	ldr r0, [sp, #0x1c]
	sub r8, sp, #4
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x14]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x18]
_0203FCF8:
	ldr r0, [sp, #0x34]
	add r7, r7, r6
	str r4, [sp, #0x128]
	cmp r7, r0
	bge _0203FDA4
	mov r0, r7, asr #0x1f
	mov r1, r0, lsl #0xc
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	orr r1, r1, r7, lsr #20
	mov r0, r7, lsl #0xc
	bl _ll_div
	ldr sb, [sp, #0x1c]
	mov sl, r0, asr #0x1f
	umull ip, r3, sb, r0
	mov sb, ip, lsr #0xc
	ldr ip, [sp, #0x1c]
	ldr r2, [r5]
	mla r3, ip, sl, r3
	ldr ip, [sp, #0x20]
	ldr r1, [r5, #4]
	mla r3, ip, r0, r3
	orr sb, sb, r3, lsl #20
	add r2, r2, sb
	str r2, [sp, #0x78]
	str r2, [sp, #0xc0]
	str r2, [sp, #0x120]
	ldr r2, [sp, #0x14]
	str sb, [sp, #0x88]
	str sb, [sp, #0x80]
	umull sb, r3, r2, r0
	mla r3, r2, sl, r3
	ldr r2, [sp, #0x18]
	mla r3, r2, r0, r3
	mov r2, sb, lsr #0xc
	orr r2, r2, r3, lsl #20
	add r0, r1, r2
	str r2, [sp, #0x8c]
	str r2, [sp, #0x84]
	str r0, [sp, #0x7c]
	str r0, [sp, #0xc4]
	str r0, [sp, #0x124]
	b _0203FDB4
_0203FDA4:
	ldr r0, [r5, #8]
	str r0, [sp, #0x120]
	ldr r0, [r5, #0xc]
	str r0, [sp, #0x124]
_0203FDB4:
	add r0, sp, #0xd0
	str r0, [sp, #0xc]
	mov r0, #4
	str r0, [sp, #0x10]
	add r0, sp, #0x110
	ldmia r0, {r0, r1, r2, r3}
	stmia r8, {r0, r1, r2, r3}
	add r0, sp, #0x120
	ldr r3, [r8]
	ldmia r0, {r0, r1, r2}
	bl _Z12sub_02006E306Circle9RectangleP7Point2Dl
	cmp r0, #0
	beq _0203FE28
	ldr r0, [sp, #0xb68]
	cmp r0, #0
	beq _0203FE18
	add r0, sp, #0xb8
	add r1, sp, #0x120
	add r2, sp, #0xd0
	bl _Z12sub_0200732CP6CircleP7Point2D
	ldr r1, [sp, #0xb8]
	ldr r0, [sp, #0xb68]
	str r1, [r0]
	ldr r1, [sp, #0xbc]
	str r1, [r0, #4]
_0203FE18:
	add sp, sp, #0x348
	add sp, sp, #0x800
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_0203FE28:
	ldr r0, [sp, #0x34]
	cmp r7, r0
	blt _0203FCF8
	b _02040134
_0203FE38:
	add r0, r8, #0x44
	add r3, sp, #0x104
	ldmia r0, {r0, r1, r2}
	stmia r3, {r0, r1, r2}
	ldr r1, [r8, #8]
	cmp r1, #0
	beq _0203FE68
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _0203FE6C
_0203FE68:
	mov r2, #0
_0203FE6C:
	ldr r0, [sp, #0x104]
	cmp r1, #0
	add r0, r0, r2
	str r0, [sp, #0x104]
	beq _0203FE94
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x24]
	moveq r2, #0
	b _0203FE98
_0203FE94:
	mov r2, #0
_0203FE98:
	ldr r1, [sp, #0x108]
	add r0, sp, #0xe0
	mov r7, #0
	add r1, r1, r2
	str r1, [sp, #0x108]
	str r7, [r0]
	str r7, [r0, #4]
	str r7, [r0, #8]
	ldr r0, [sp, #0x34]
	ldr r2, [r5]
	ldr r1, [r5, #4]
	cmp r0, #0
	str r2, [sp, #0xe0]
	str r1, [sp, #0xe4]
	str r4, [sp, #0xe8]
	str r2, [sp, #0x120]
	str r1, [sp, #0x124]
	str r4, [sp, #0x128]
	ldr r3, [r5]
	ldr r0, [r5, #8]
	ldr r2, [r5, #4]
	sub r0, r0, r3
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x2c]
	sub r0, r1, r2
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x2c]
	str r3, [sp, #0x70]
	str r0, [sp, #0x68]
	ldr r0, [sp, #0x24]
	str r2, [sp, #0x74]
	str r0, [sp, #0x6c]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0xb0]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xb4]
	ble _02040134
	ldr r0, [sp, #0x2c]
	sub r8, sp, #4
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x24]
	mov r0, r0, asr #0x1f
	str r0, [sp, #0x28]
_0203FF48:
	ldr r0, [sp, #0x34]
	add r7, r7, r6
	str r4, [sp, #0x100]
	cmp r7, r0
	bge _0203FFF4
	mov r0, r7, asr #0x1f
	mov r1, r0, lsl #0xc
	ldr r2, [sp, #0x34]
	ldr r3, [sp, #0x38]
	orr r1, r1, r7, lsr #20
	mov r0, r7, lsl #0xc
	bl _ll_div
	ldr sb, [sp, #0x2c]
	mov sl, r0, asr #0x1f
	umull ip, r3, sb, r0
	mov sb, ip, lsr #0xc
	ldr ip, [sp, #0x2c]
	ldr r2, [r5]
	mla r3, ip, sl, r3
	ldr ip, [sp, #0x30]
	ldr r1, [r5, #4]
	mla r3, ip, r0, r3
	orr sb, sb, r3, lsl #20
	add r2, r2, sb
	str r2, [sp, #0x50]
	str r2, [sp, #0xa8]
	str r2, [sp, #0xf8]
	ldr r2, [sp, #0x24]
	str sb, [sp, #0x60]
	str sb, [sp, #0x58]
	umull sb, r3, r2, r0
	mla r3, r2, sl, r3
	ldr r2, [sp, #0x28]
	mla r3, r2, r0, r3
	mov r2, sb, lsr #0xc
	orr r2, r2, r3, lsl #20
	add r0, r1, r2
	str r2, [sp, #0x64]
	str r2, [sp, #0x5c]
	str r0, [sp, #0x54]
	str r0, [sp, #0xac]
	str r0, [sp, #0xfc]
	b _02040004
_0203FFF4:
	ldr r0, [r5, #8]
	str r0, [sp, #0xf8]
	ldr r0, [r5, #0xc]
	str r0, [sp, #0xfc]
_02040004:
	add r0, sp, #0xd0
	str r0, [sp, #8]
	add r0, sp, #0x104
	ldmia r0, {r0, r1, r2}
	stmia r8, {r0, r1, r2}
	add r0, sp, #0xf8
	ldr r3, [r8]
	ldmia r0, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	beq _02040128
	ldr r3, [sp, #0x104]
	ldr r0, [sp, #0xd0]
	ldr r2, [sp, #0x108]
	ldr r1, [sp, #0xd4]
	sub r0, r0, r3
	sub r1, r1, r2
	str r0, [sp, #0xd0]
	str r3, [sp, #0x48]
	str r2, [sp, #0x4c]
	str r1, [sp, #0xd4]
	bl _Z12sub_02007254ll
	mov r5, r0
	ldr r4, [sp, #0x10c]
	ldr r1, [sp, #0xd0]
	mov r7, r5, asr #0x1f
	smull r2, r0, r1, r4
	mov r6, r2, lsr #0xc
	orr r6, r6, r0, lsl #20
	mov r0, r6, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r2, r5
	mov r3, r7
	orr r1, r1, r6, lsr #20
	mov r0, r6, lsl #0xc
	bl _ll_div
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0xd4]
	mov r2, r5
	smull r4, r1, r0, r4
	mov r4, r4, lsr #0xc
	orr r4, r4, r1, lsl #20
	mov r0, r4, asr #0x1f
	mov r1, r0, lsl #0xc
	mov r3, r7
	orr r1, r1, r4, lsr #20
	mov r0, r4, lsl #0xc
	bl _ll_div
	ldr r1, [sp, #0xb68]
	ldr r2, [sp, #0x104]
	cmp r1, #0
	ldr r1, [sp, #0x108]
	str r2, [sp, #0x40]
	add r0, r0, r1
	str r0, [sp, #0xd4]
	ldr r0, [sp, #0xd0]
	str r1, [sp, #0x44]
	add r0, r0, r2
	str r0, [sp, #0xd0]
	beq _02040118
	add r0, sp, #0xa0
	add r1, sp, #0xf8
	add r2, sp, #0xd0
	bl _Z12sub_0200732CP6CircleP7Point2D
	ldr r1, [sp, #0xa0]
	ldr r0, [sp, #0xb68]
	str r1, [r0]
	ldr r1, [sp, #0xa4]
	str r1, [r0, #4]
_02040118:
	add sp, sp, #0x348
	add sp, sp, #0x800
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_02040128:
	ldr r0, [sp, #0x34]
	cmp r7, r0
	blt _0203FF48
_02040134:
	ldr r0, [sp, #0x3c]
	ldr r0, [r0, #0x10]
	str r0, [sp, #0x3c]
	cmp r0, #0
	bne _0203FBC8
_02040148:
	mov r0, #0
	add sp, sp, #0x348
	add sp, sp, #0x800
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start sub_02040158
sub_02040158: ; 0x02040158
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x34
	add r7, sp, #0x28
	mov r8, #0
	str r8, [r7, #8]
	ldr r2, [sp, #0x5c]
	str r8, [r7]
	ldr r1, [sp, #0x60]
	str r8, [r7, #4]
	mov sl, r0
	str r2, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r3, [sp, #0x30]
	ldr r0, [sl, #4]
	ldr sb, [sp, #0x68]
	cmp r0, #0
	ble _02040370
	sub r5, sp, #4
	mov fp, r8
	add r4, sp, #0xc
	add r6, sp, #0x18
	arm_func_end sub_02040158
_020401B0:
	ldr r0, [sl, #8]
	ldr ip, [r0, r8, lsl #2]
	cmp ip, #0
	beq _02040360
	ldr r0, [ip, #4]
	mov r1, #1
	tst r0, #0x80
	ldrb r0, [ip, #0x20]
	moveq r2, #1
	movne r2, #0
	cmp r0, #2
	cmpne r0, #3
	movne r1, #0
	tst r1, r2
	beq _02040360
	ldr r0, [ip, #0x14]
	cmp sb, r0
	bne _02040360
	ldr r0, [ip, #0x50]
	cmp r0, #0
	beq _02040210
	cmp r0, #1
	beq _020402BC
	b _02040360
_02040210:
	add r0, ip, #0x34
	ldmia r0, {r0, r1, r2, r3}
	stmia r6, {r0, r1, r2, r3}
	ldr r0, [sp, #0x20]
	cmp r0, #0
	ldrne r0, [sp, #0x24]
	cmpne r0, #0
	beq _02040360
	ldr r1, [ip, #8]
	cmp r1, #0
	beq _02040250
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _02040254
_02040250:
	mov r2, #0
_02040254:
	cmp r1, #0
	ldr r0, [sp, #0x18]
	add r0, r0, r2
	str r0, [sp, #0x18]
	beq _0204027C
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r1, [r0, #0x24]
	moveq r1, #0
	b _02040280
_0204027C:
	mov r1, #0
_02040280:
	ldr r0, [sp, #0x1c]
	add r0, r0, r1
	str r0, [sp, #0x1c]
	ldmia r6, {r0, r1, r2, r3}
	stmia r5, {r0, r1, r2, r3}
	ldr r3, [r5]
	ldmia r7, {r0, r1, r2}
	bl _Z12sub_02006F806Circle9Rectangle
	cmp r0, #0
	beq _02040360
	add sp, sp, #0x34
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	add sp, sp, #0x10
	bx lr
_020402BC:
	add r0, ip, #0x44
	ldmia r0, {r0, r1, r2}
	stmia r4, {r0, r1, r2}
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02040360
	ldr r1, [ip, #8]
	cmp r1, #0
	beq _020402F4
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r2, [r0, #0x20]
	moveq r2, #0
	b _020402F8
_020402F4:
	mov r2, #0
_020402F8:
	cmp r1, #0
	ldr r0, [sp, #0xc]
	add r0, r0, r2
	str r0, [sp, #0xc]
	beq _02040320
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r1, [r0, #0x24]
	moveq r1, #0
	b _02040324
_02040320:
	mov r1, #0
_02040324:
	ldr r0, [sp, #0x10]
	add r0, r0, r1
	str r0, [sp, #0x10]
	str fp, [sp, #8]
	ldmia r4, {r0, r1, r2}
	stmia r5, {r0, r1, r2}
	ldr r3, [r5]
	ldmia r7, {r0, r1, r2}
	bl _Z12sub_020061646CircleS_P7Point2D
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	addne sp, sp, #0x10
	bxne lr
_02040360:
	add r8, r8, #1
	ldr r0, [sl, #4]
	cmp r8, r0
	blt _020401B0
_02040370:
	mov r0, #0
	add sp, sp, #0x34
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_02040384Ev
_ZN17CFieldActorManage12sub_02040384Ev: ; 0x02040384
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #8
	mov r6, r0
	ldr r0, [r6, #4]
	mov r5, #0
	cmp r0, #0
	addle sp, sp, #8
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	addle sp, sp, #0x10
	bxle lr
	ldr r8, [sp, #0x2c]
	ldr r7, [sp, #0x30]
	add r4, sp, #0x2c
	arm_func_end _ZN17CFieldActorManage12sub_02040384Ev
_020403BC:
	ldr r0, [r6, #8]
	ldr r0, [r0, r5, lsl #2]
	cmp r0, #0
	ldrne sb, [r0, #8]
	cmpne sb, #0
	ldrne r0, [sb, #0xc]
	cmpne r0, #0
	beq _02040408
	add r0, r0, #0xc
	ldmia r4, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	beq _02040408
	str r8, [r0, #0x18]
	str r8, [sp]
	str r7, [sp, #4]
	str r7, [r0, #0x1c]
_02040408:
	ldr r0, [r6, #4]
	add r5, r5, #1
	cmp r5, r0
	blt _020403BC
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	add sp, sp, #0x10
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_02040428Ev
_ZN17CFieldActorManage12sub_02040428Ev: ; 0x02040428
	ldr r1, [r0, #4]
	mov r3, #0
	cmp r1, #0
	bxle lr
	mov r2, #2
	arm_func_end _ZN17CFieldActorManage12sub_02040428Ev
_0204043C:
	ldr r1, [r0, #8]
	ldr r1, [r1, r3, lsl #2]
	add r3, r3, #1
	cmp r1, #0
	strneb r2, [r1, #0x20]
	ldr r1, [r0, #4]
	cmp r3, r1
	blt _0204043C
	bx lr

	arm_func_start _ZN17CFieldActorManage12sub_02040460Ev
_ZN17CFieldActorManage12sub_02040460Ev: ; 0x02040460
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	ldr r0, [r4, #4]
	mov r6, #0
	cmp r0, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, pc}
	mov r5, r6
	arm_func_end _ZN17CFieldActorManage12sub_02040460Ev
_0204047C:
	ldr r0, [r4, #8]
	ldr r7, [r0, r6, lsl #2]
	cmp r7, #0
	beq _020404A8
	mov r0, r7
	bl sub_02041C1C
	mov r0, r7
	strb r5, [r7, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x1c]
	blx r1
_020404A8:
	ldr r0, [r4, #4]
	add r6, r6, #1
	cmp r6, r0
	blt _0204047C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_020404BC
sub_020404BC: ; 0x020404BC
	ldr r1, _020404E0 ; =PTR_LAB_0208de68
	mov r2, #0
	str r1, [r0]
	ldr r1, _020404E4 ; =PTR_LAB_0208de54
	stmia r0, {r1, r2}
	str r2, [r0, #0xc]
	str r2, [r0, #0x10]
	str r2, [r0, #0x14]
	bx lr
	.align 2, 0
_020404E0: .word PTR_LAB_0208de68
_020404E4: .word PTR_LAB_0208de54
	arm_func_end sub_020404BC

	arm_func_start sub_020404E8
sub_020404E8: ; 0x020404E8
	stmdb sp!, {r4, lr}
	ldr r1, _02040504 ; =PTR_LAB_0208de54
	mov r4, r0
	str r1, [r4]
	bl sub_02040638
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02040504: .word PTR_LAB_0208de54
	arm_func_end sub_020404E8

	arm_func_start sub_02040508
sub_02040508: ; 0x02040508
	stmdb sp!, {r4, lr}
	ldr r1, _0204052C ; =PTR_LAB_0208de54
	mov r4, r0
	str r1, [r4]
	bl sub_02040638
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0204052C: .word PTR_LAB_0208de54
	arm_func_end sub_02040508

	arm_func_start sub_02040530
sub_02040530: ; 0x02040530
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #8
	mov r7, r0
	ldr r0, [r7, #0xc]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp r0, #0
	beq _0204056C
	beq _02040564
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02040530
_02040564:
	mov r0, #0
	str r0, [r7, #0xc]
_0204056C:
	mov r0, #0x204
	bl _Znwm
	cmp r0, #0
	beq _02040580
	bl sub_0203DA68
_02040580:
	ldr r1, [sp, #0x20]
	str r0, [r7, #0xc]
	ldr r0, [sp, #0x24]
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r7, #0xc]
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl sub_0203DBB8
	mov r0, #1
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_020405B4
sub_020405B4: ; 0x020405B4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #8
	mov r7, r0
	ldr r0, [r7, #0xc]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp r0, #0
	beq _020405F0
	beq _020405E8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_020405B4
_020405E8:
	mov r0, #0
	str r0, [r7, #0xc]
_020405F0:
	mov r0, #0x204
	bl _Znwm
	cmp r0, #0
	beq _02040604
	bl sub_0203DA68
_02040604:
	ldr r1, [sp, #0x20]
	str r0, [r7, #0xc]
	ldr r0, [sp, #0x24]
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r7, #0xc]
	mov r1, r6
	mov r2, r5
	mov r3, r4
	bl sub_0203E10C
	mov r0, #1
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02040638
sub_02040638: ; 0x02040638
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	beq _0204065C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02040638
_0204065C:
	mov r0, #0
	str r0, [r4, #0xc]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040668
sub_02040668: ; 0x02040668
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x10
	mov r7, r0
	mov r5, r2
	str r5, [r7, #0x10]
	ldr r0, [r7, #0xc]
	mov ip, #0
	mov r6, r1
	cmp r0, #0
	add r4, ip, #4
	beq _02040728
	add r0, r0, #0x1e4
	add lr, sp, #0
	ldmia r0, {r0, r1, r2, r3}
	stmia lr, {r0, r1, r2, r3}
	ldr r0, [r7, #0xc]
	cmp r0, #0
	ldrne ip, [r0, #0x20]
	ldr r0, [sp]
	add r0, r0, ip
	str r0, [sp]
	ldr r2, [r7, #0xc]
	cmp r2, #0
	ldrne r3, [r2, #0x24]
	moveq r3, #0
	cmp r2, #0
	moveq r0, #0
	beq _020406EC
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r0, r2, r0
	arm_func_end sub_02040668
_020406EC:
	ldr r1, [sp, #4]
	sub r0, r3, r0
	add r3, r1, r0
	ldr r2, _0204073C ; =0x00001199
	add r1, sp, #0
	mov r0, r6
	str r3, [sp, #4]
	bl _ZN17UnkClass_0200371812sub_020038A8EP9Rectanglel
	cmp r0, #0
	beq _02040728
	ldr r0, [r7, #0xc]
	mov r1, r6
	sub r2, r5, r4
	bl sub_0203E934
	add r4, r4, r0
_02040728:
	sub r0, r5, r4
	str r0, [r7, #0x14]
	add r0, r4, #4
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0204073C: .word 0x00001199

	arm_func_start sub_02040740
sub_02040740: ; 0x02040740
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _02040760
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end sub_02040740
_02040760:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	str r0, [r4, #4]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040778
sub_02040778: ; 0x02040778
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02040778

	arm_func_start sub_0204078C
sub_0204078C: ; 0x0204078C
	bx lr
	arm_func_end sub_0204078C

	arm_func_start sub_02040790
sub_02040790: ; 0x02040790
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CActorDataC2Ev
	ldr r1, _020407DC ; =ptr_FUN_02040f20_0208dec0
	mvn r0, #0
	str r1, [r4]
	str r0, [r4, #0x18]
	add r0, r0, #0x10000
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	mov r1, #0
	strh r1, [r4, #0x20]
	str r1, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	mov r0, r4
	str r1, [r4, #0x30]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020407DC: .word ptr_FUN_02040f20_0208dec0
	arm_func_end sub_02040790

	arm_func_start sub_020407E0
sub_020407E0: ; 0x020407E0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CActorDataC2Ev
	ldr r1, _0204082C ; =ptr_FUN_02040f20_0208dec0
	mvn r0, #0
	str r1, [r4]
	str r0, [r4, #0x18]
	add r0, r0, #0x10000
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	mov r1, #0
	strh r1, [r4, #0x20]
	str r1, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	mov r0, r4
	str r1, [r4, #0x30]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0204082C: .word ptr_FUN_02040f20_0208dec0
	arm_func_end sub_020407E0

	arm_func_start sub_02040830
sub_02040830: ; 0x02040830
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x14
	mov r8, r1
	mov sb, r0
	mov r7, r2
	mov r6, r3
	cmp r8, #2
	ldr r5, [sp, #0x30]
	ldr r4, [sp, #0x34]
	beq _020408A8
	cmp r4, #0
	beq _02040884
	str r5, [sp]
	mov lr, #1
	ldr ip, [sp, #0x38]
	str lr, [sp, #4]
	str ip, [sp, #8]
	mov ip, #0
	str ip, [sp, #0xc]
	bl _ZN10CActorData12sub_02013154EiiitiPKcm
	b _020408C8
	arm_func_end sub_02040830
_02040884:
	ldr ip, [sp, #0x38]
	stmia sp, {r5, ip}
	mov ip, #0
	str ip, [sp, #8]
	mov ip, #1
	str ip, [sp, #0xc]
	str r4, [sp, #0x10]
	bl _ZN10CActorData12sub_02014514EiiitPKcmmi
	b _020408C8
_020408A8:
	mov r1, #0
	ldr ip, [sp, #0x38]
	str r1, [sp]
	mov r1, r7
	mov r2, r6
	mov r3, r5
	str ip, [sp, #4]
	bl sub_020409B4
_020408C8:
	str r8, [sb, #0x18]
	strh r7, [sb, #0x1c]
	strh r6, [sb, #0x1e]
	ldr r0, [sp, #0x3c]
	str r4, [sb, #0x28]
	strh r5, [sb, #0x20]
	cmp r0, #0
	beq _02040980
	cmp r4, #0
	bne _02040924
	mov r0, sb
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	mov r1, r1, lsl #0x10
	str r0, [sb, #0x2c]
	mov r0, sb
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_020141ACEm
	mov r0, sb
	bl _ZN10CActorData12sub_020142B4Ev
_02040924:
	mov r0, sb
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [sb, #0x30]
	cmp r4, #0
	beq _02040964
	ldr r0, [sb, #0xc]
	cmp r0, #0
	beq _02040980
	ldr r1, [sb, #0x30]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl sub_02007C34
	b _02040980
_02040964:
	ldr r1, [sb, #0x30]
	mov r0, sb
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_0201429CEm
	mov r0, sb
	bl _ZN10CActorData12sub_020142F8Ev
_02040980:
	ldr r4, [sb, #8]
	cmp r4, #0
	addeq sp, sp, #0x14
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, pc}
	beq _020409A4
	mov r0, r4
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r4
	bl _ZdlPv
_020409A4:
	mov r0, #0
	str r0, [sb, #8]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}

	arm_func_start sub_020409B4
sub_020409B4: ; 0x020409B4
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #0x1f8
	ldr ip, [r0]
	mov r8, r0
	ldr ip, [ip, #8]
	mov r5, r1
	mov r4, r2
	mov r7, r3
	ldr r6, [sp, #0x218]
	blx ip
	mov sb, #0
	mov r1, sb
	mov r0, #1
	arm_func_end sub_020409B4
_020409E8:
	tst r7, r0, lsl r1
	add r1, r1, #1
	addne sb, sb, #1
	cmp r1, #0x1d
	blt _020409E8
	cmp sb, #0
	addeq sp, sp, #0x1f8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	mov sl, sb, lsl #4
	mov r0, sl
	mov r1, #4
	bl _Z23Heap_AllocWithAlignmentmm
	str r0, [r8, #0x10]
	mov r1, r0
	mov r2, sl
	mov r0, #0
	bl MIi_CpuClearFast
	strb sb, [r8, #0x14]
	mov r0, #1
	strb r0, [r8, #5]
	strb r0, [r8, #6]
	ldr r1, _02040D24 ; =s_t_03d_02d_0208df10
	mov r2, r5
	mov r3, r4
	add r0, sp, #0x198
	bl OS_SPrintf
	ldr r1, [sp, #0x21c]
	add r0, sp, #0x14
	cmp r1, #0
	beq _02040A68
	bl STD_CopyString
	b _02040A70
_02040A68:
	ldr r1, _02040D28 ; =DAT_0208df1c
	bl STD_CopyString
_02040A70:
	ldr r1, _02040D2C ; =s_data_target_s_LZ_bin_0208df20
	add r0, sp, #0x138
	add r2, sp, #0x198
	bl OS_SPrintf
	mov r0, #0x6c
	bl _Znwm
	cmp r0, #0
	beq _02040AC0
	mov r1, #1
	str r1, [sp]
	mov r4, #0
	cmp r6, #0
	moveq r3, #1
	str r4, [sp, #4]
	str r4, [sp, #8]
	movne r3, #0
	add r1, sp, #0x14
	add r2, sp, #0x138
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
_02040AC0:
	cmp r0, #0
	addeq sp, sp, #0x1f8
	str r0, [r8, #8]
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r1, _02040D30 ; =s_s_s_NCLR_0208df38
	add r0, sp, #0xd8
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	add r0, sp, #0xd8
	bl NNS_FndGetArchiveFileByName
	cmp r0, #0
	beq _02040B20
	add r1, sp, #0x10
	bl NNS_G2dGetUnpackedPaletteData
	cmp r0, #0
	beq _02040B20
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02040B1C
	ldr r1, [sp, #0x10]
	bl _ZN17UnkClass_02007AA4C1EP17NNSG2dPaletteData
_02040B1C:
	str r0, [r8, #0xc]
_02040B20:
	ldr r1, _02040D34 ; =s_s_s_0208df44
	add r0, sp, #0x18
	add r2, sp, #0x14
	add r3, sp, #0x198
	mov r4, #0
	bl OS_SPrintf
	tst r7, #1
	mov r5, r4
	beq _02040B84
	ldr r1, _02040D34 ; =s_s_s_0208df44
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	mov r0, r4
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
	ldr r0, [r8, #0x10]
	mov r1, r4
	strb r1, [r0, #1]
	add r5, r5, #1
_02040B84:
	tst r7, #2
	beq _02040C10
	ldr r1, _02040D38 ; =s_s_s_s_0208df4c
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x18
	add r3, sp, #0x78
	mov r0, r8
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014EA4EP10CActorAnimPKcS3_P17UnkClass_020074D4mi
	cmp r0, #0
	ldrne r0, [r8, #0x10]
	addne r0, r0, r5, lsl #4
	ldrne r4, [r0, #4]
	bne _02040BFC
	mov r0, #0
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
_02040BFC:
	ldr r0, [r8, #0x10]
	mov r1, #1
	add r0, r0, r5, lsl #4
	strb r1, [r0, #1]
	add r5, r5, #1
_02040C10:
	tst r7, #4
	beq _02040C9C
	ldr r1, _02040D3C ; =s_s_s_a_0208df54
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	str r4, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x18
	add r3, sp, #0x78
	mov r0, r8
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014EA4EP10CActorAnimPKcS3_P17UnkClass_020074D4mi
	cmp r0, #0
	ldrne r0, [r8, #0x10]
	addne r0, r0, r5, lsl #4
	ldrne r4, [r0, #4]
	bne _02040C88
	mov r0, #0
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
_02040C88:
	ldr r0, [r8, #0x10]
	mov r1, #2
	add r0, r0, r5, lsl #4
	strb r1, [r0, #1]
	add r5, r5, #1
_02040C9C:
	tst r7, #8
	addeq sp, sp, #0x1f8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r1, _02040D40 ; =s_s_s_c_0208df5c
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x198
	bl OS_SPrintf
	str r4, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x18
	add r3, sp, #0x78
	mov r0, r8
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014EA4EP10CActorAnimPKcS3_P17UnkClass_020074D4mi
	cmp r0, #0
	bne _02040D0C
	mov r0, #0
	str r0, [sp]
	ldr r1, [r8, #0x10]
	add r2, sp, #0x78
	mov r0, r8
	mov r3, r6
	add r1, r1, r5, lsl #4
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
_02040D0C:
	ldr r0, [r8, #0x10]
	mov r1, #3
	add r0, r0, r5, lsl #4
	strb r1, [r0, #1]
	add sp, sp, #0x1f8
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02040D24: .word s_t_03d_02d_0208df10
_02040D28: .word DAT_0208df1c
_02040D2C: .word s_data_target_s_LZ_bin_0208df20
_02040D30: .word s_s_s_NCLR_0208df38
_02040D34: .word s_s_s_0208df44
_02040D38: .word s_s_s_s_0208df4c
_02040D3C: .word s_s_s_a_0208df54
_02040D40: .word s_s_s_c_0208df5c

	arm_func_start sub_02040D44
sub_02040D44: ; 0x02040D44
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x24]
	cmp r0, #0
	ldmleia sp!, {r4, pc}
	subs r0, r0, #1
	str r0, [r4, #0x24]
	ldmneia sp!, {r4, pc}
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _02040D78
	ldr r0, [r4, #0x2c]
	bl NNS_GfdFreeLnkTexVram
	arm_func_end sub_02040D44
_02040D78:
	ldr r0, [r4, #0x30]
	bl NNS_GfdFreeLnkPlttVram
	mov r0, r4
	bl _ZN10CActorData7ReleaseEv
	mvn r0, #0
	str r0, [r4, #0x18]
	add r0, r0, #0x10000
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	mov r1, #0
	str r1, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040DB8
sub_02040DB8: ; 0x02040DB8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _02040DDC
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _02040DDC
	bl NNS_GfdFreeLnkTexVram
	arm_func_end sub_02040DB8
_02040DDC:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	beq _02040DEC
	bl NNS_GfdFreeLnkPlttVram
_02040DEC:
	mov r0, r4
	bl _ZN10CActorData7ReleaseEv
	mov r2, #0
	str r2, [r4, #0x24]
	sub r1, r2, #1
	ldr r0, _02040E28 ; =0x0000FFFF
	str r1, [r4, #0x18]
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	str r2, [r4, #0x24]
	mov r0, #1
	str r0, [r4, #0x28]
	str r2, [r4, #0x2c]
	str r2, [r4, #0x30]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02040E28: .word 0x0000FFFF

	arm_func_start sub_02040E2C
sub_02040E2C: ; 0x02040E2C
	stmdb sp!, {r4, lr}
	ldr r1, [r0]
	mov r4, r0
	ldr r1, [r1, #0x20]
	blx r1
	ldr r0, [r4, #0x28]
	cmp r0, #0
	bne _02040E64
	mov r0, r4
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	str r0, [r4, #0x2c]
	arm_func_end sub_02040E2C
_02040E64:
	mov r0, r4
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040E80
sub_02040E80: ; 0x02040E80
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _02040EA0
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4, #0x2c]
	arm_func_end sub_02040E80
_02040EA0:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040EBC
sub_02040EBC: ; 0x02040EBC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x28]
	cmp r1, #0
	bne _02040EE0
	ldr r1, [r4, #0x2c]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_020141ACEm
	arm_func_end sub_02040EBC
_02040EE0:
	ldr r1, [r4, #0x30]
	mov r0, r4
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_0201429CEm
	ldmia sp!, {r4, pc}

	arm_func_start sub_02040EF8
sub_02040EF8: ; 0x02040EF8
	stmdb sp!, {r3, lr}
	mov r1, r0
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r1, #0x30]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0xd
	bl sub_02007C34
	ldmia sp!, {r3, pc}
	arm_func_end sub_02040EF8

	arm_func_start sub_02040F20
sub_02040F20: ; 0x02040F20
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02040F20

	arm_func_start _ZN17UnkClass_02040F34C1Ev
_ZN17UnkClass_02040F34C1Ev: ; 0x02040F34
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02040F7C ; =MAIN_BSS_0210CA64
	mov r4, r0
	str r4, [r1]
	mov r1, #0x28
	ldr r0, _02040F80 ; =sub_02040F20
	str r1, [r4]
	str r0, [sp]
	ldr r0, [r4]
	ldr r3, _02040F84 ; =sub_020407E0
	mov r1, #0x34
	mov r2, #8
	bl __cxa_vec_new
	str r0, [r4, #4]
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02040F7C: .word MAIN_BSS_0210CA64
_02040F80: .word sub_02040F20
_02040F84: .word sub_020407E0
	arm_func_end _ZN17UnkClass_02040F34C1Ev

	arm_func_start _ZN17UnkClass_02040F34D1Ev
_ZN17UnkClass_02040F34D1Ev: ; 0x02040F88
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4]
	mov r5, #0
	cmp r0, #0
	ble _02040FC4
	mov r6, r5
	arm_func_end _ZN17UnkClass_02040F34D1Ev
_02040FA4:
	ldr r0, [r4, #4]
	add r0, r0, r6
	bl sub_02040DB8
	ldr r0, [r4]
	add r5, r5, #1
	cmp r5, r0
	add r6, r6, #0x34
	blt _02040FA4
_02040FC4:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _02040FE8
	ldr r3, _02041000 ; =sub_02040F20
	mov r1, #0x34
	mov r2, #8
	bl __cxa_vec_delete
	mov r0, #0
	str r0, [r4, #4]
_02040FE8:
	mov r2, #0
	ldr r1, _02041004 ; =MAIN_BSS_0210CA64
	str r2, [r4]
	mov r0, r4
	str r2, [r1]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02041000: .word sub_02040F20
_02041004: .word MAIN_BSS_0210CA64

	arm_func_start sub_02041008
sub_02041008: ; 0x02041008
	stmdb sp!, {r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x14
	mov r8, r1
	ldr r1, [r0]
	mov r7, r2
	mov r6, r3
	cmp r1, #0
	ldr r5, [sp, #0x30]
	ldr r4, [sp, #0x34]
	mov r3, #0
	ble _02041094
	ldr sb, [r0, #4]
	arm_func_end sub_02041008
_02041038:
	ldr r2, [sb, #0x24]
	cmp r2, #0
	ble _02041084
	ldr ip, [sb, #0x18]
	cmp r8, ip
	ldreqh ip, [sb, #0x1c]
	cmpeq r7, ip
	ldreqh ip, [sb, #0x1e]
	cmpeq r6, ip
	ldreqh ip, [sb, #0x20]
	cmpeq r5, ip
	ldreq ip, [sb, #0x28]
	cmpeq r4, ip
	bne _02041084
	add r1, r2, #1
	add sp, sp, #0x14
	mov r0, sb
	str r1, [sb, #0x24]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
_02041084:
	add r3, r3, #1
	cmp r3, r1
	add sb, sb, #0x34
	blt _02041038
_02041094:
	cmp r1, #0
	mov r2, #0
	ble _02041108
	ldr sb, [r0, #4]
_020410A4:
	ldr r0, [sb, #0x24]
	cmp r0, #0
	bne _020410F8
	ldr r1, _0204111C ; =s_F_02d_0208df64
	add r0, sp, #0x10
	bl OS_SPrintf
	str r5, [sp]
	add r5, sp, #0x10
	stmib sp, {r4, r5}
	mov r4, #1
	mov r0, sb
	mov r1, r8
	mov r2, r7
	mov r3, r6
	str r4, [sp, #0xc]
	bl sub_02040830
	mov r1, r4
	add sp, sp, #0x14
	mov r0, sb
	str r1, [sb, #0x24]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
_020410F8:
	add r2, r2, #1
	cmp r2, r1
	add sb, sb, #0x34
	blt _020410A4
_02041108:
	ldr r0, _02041120 ; =s_NO_EMPTY_m_nActorDataMax_d_0208df6c
	bl LogInfo
	mov r0, #0
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0204111C: .word s_F_02d_0208df64
_02041120: .word s_NO_EMPTY_m_nActorDataMax_d_0208df6c

	arm_func_start sub_02041124
sub_02041124: ; 0x02041124
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02040790
	ldr r0, _02041148 ; =ptr_FUN_0204114c_0208deec
	mov r1, #0
	str r0, [r4]
	mov r0, r4
	str r1, [r4, #0x34]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041148: .word ptr_FUN_0204114c_0208deec
	arm_func_end sub_02041124

	arm_func_start sub_0204114C
sub_0204114C: ; 0x0204114C
	stmdb sp!, {r4, lr}
	ldr r1, _02041178 ; =ptr_FUN_0204114c_0208deec
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041178: .word ptr_FUN_0204114c_0208deec
	arm_func_end sub_0204114C

	arm_func_start sub_0204117C
sub_0204117C: ; 0x0204117C
	stmdb sp!, {r4, lr}
	ldr r1, _020411B0 ; =ptr_FUN_0204114c_0208deec
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_020411B0: .word ptr_FUN_0204114c_0208deec
	arm_func_end sub_0204117C

	arm_func_start sub_020411B4
sub_020411B4: ; 0x020411B4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x34]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	bl sub_02040DB8
	mov r0, #0
	str r0, [r4, #0x34]
	ldmia sp!, {r4, pc}
	arm_func_end sub_020411B4

	arm_func_start sub_020411D8
sub_020411D8: ; 0x020411D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x28]
	cmp r1, #0
	ldreq r1, [r4, #0x2c]
	cmpeq r1, #0
	bne _02041208
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	str r0, [r4, #0x2c]
	arm_func_end sub_020411D8
_02041208:
	ldr r0, [r4, #0x30]
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, r4
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	str r0, [r4, #0x30]
	ldmia sp!, {r4, pc}

	arm_func_start sub_02041230
sub_02041230: ; 0x02041230
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x10
	mov r7, r0
	ldr ip, [r7, #0x34]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp ip, #0
	beq _02041260
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	arm_func_end sub_02041230
_02041260:
	ldrh r1, [sp, #0x28]
	mov r0, #1
	mov ip, #0
	str r1, [sp]
	stmib sp, {r0, ip}
	mov r0, r7
	mov r1, r6
	mov r2, r5
	mov r3, r4
	str ip, [sp, #0xc]
	bl sub_02040830
	mov r0, #1
	str r0, [r7, #0x34]
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_0204129C
sub_0204129C: ; 0x0204129C
	bx lr
	arm_func_end sub_0204129C

	arm_func_start sub_020412A0
sub_020412A0: ; 0x020412A0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02040790
	ldr r1, _020412D0 ; =ptr_FUN_020412dc_0208dfb4
	mov r0, r4
	str r1, [r4]
	bl _ZN10CActorData4InitEv
	ldr r2, _020412D4 ; =0x0000FFFF
	ldr r1, _020412D8 ; =0x00050834
	mov r0, r4
	strh r2, [r4, r1]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020412D0: .word ptr_FUN_020412dc_0208dfb4
_020412D4: .word 0x0000FFFF
_020412D8: .word 0x00050834
	arm_func_end sub_020412A0

	arm_func_start sub_020412DC
sub_020412DC: ; 0x020412DC
	stmdb sp!, {r4, lr}
	ldr r1, _02041308 ; =ptr_FUN_020412dc_0208dfb4
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041308: .word ptr_FUN_020412dc_0208dfb4
	arm_func_end sub_020412DC

	arm_func_start sub_0204130C
sub_0204130C: ; 0x0204130C
	stmdb sp!, {r4, lr}
	ldr r1, _02041340 ; =ptr_FUN_020412dc_0208dfb4
	mov r4, r0
	str r1, [r4]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, r4
	bl _ZN10CActorDataD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041340: .word ptr_FUN_020412dc_0208dfb4
	arm_func_end sub_0204130C

	arm_func_start sub_02041344
sub_02041344: ; 0x02041344
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x198
	ldr r2, _020415AC ; =0x00050834
	mov sl, r0
	ldrh r2, [sl, r2]
	mov sb, r1
	mov r8, r3
	cmp r2, sb
	addeq sp, sp, #0x198
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, #0x1d0
	mov r1, #4
	bl _Z23Heap_AllocWithAlignmentmm
	str r0, [sl, #0x10]
	mov r1, r0
	mov r0, #0
	mov r2, #0x1d0
	bl MIi_CpuClearFast
	mov r0, #0x1d
	strb r0, [sl, #0x14]
	mov r0, #0
	strb r0, [sl, #5]
	ldr r1, _020415B0 ; =s_player_1d_0208dfd8
	add r0, sp, #0x138
	mov r2, sb
	bl OS_SPrintf
	ldr r1, [sp, #0x1c0]
	add r0, sp, #0x14
	cmp r1, #0
	beq _020413D4
	mov r2, #4
	bl STD_CopyLString
	b _020413DC
	arm_func_end sub_02041344
_020413D4:
	ldr r1, _020415B4 ; =DAT_0208dfe4
	bl STD_CopyString
_020413DC:
	ldr r1, _020415B8 ; =s_data_player_s_LZ_bin_0208dfe8
	add r0, sp, #0xd8
	add r2, sp, #0x138
	bl OS_SPrintf
	mov r0, #0x6c
	bl _Znwm
	cmp r0, #0
	beq _02041428
	mov r1, #1
	str r1, [sp]
	mov r3, #0
	str r3, [sp, #4]
	add r1, sl, #0x34
	str r1, [sp, #8]
	ldr r4, _020415BC ; =0x00050800
	add r1, sp, #0x14
	add r2, sp, #0xd8
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
_02041428:
	cmp r0, #0
	addeq sp, sp, #0x198
	str r0, [sl, #8]
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r1, _020415C0 ; =s_s_s_NCLR_0208e000
	add r0, sp, #0x78
	add r2, sp, #0x14
	add r3, sp, #0x138
	bl OS_SPrintf
	add r0, sp, #0x78
	bl NNS_FndGetArchiveFileByName
	cmp r0, #0
	beq _02041488
	add r1, sp, #0x10
	bl NNS_G2dGetUnpackedPaletteData
	cmp r0, #0
	beq _02041488
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02041484
	ldr r1, [sp, #0x10]
	bl _ZN17UnkClass_02007AA4C1EP17NNSG2dPaletteData
_02041484:
	str r0, [sl, #0xc]
_02041488:
	mov r5, #0
	mov r6, r5
	mov r7, r5
	add r4, sp, #0x18
	mov fp, #1
_0204149C:
	add r0, r6, #1
	tst r8, fp, lsl r0
	beq _020414F8
	ldr r1, _020415C4 ; =s_s_s_02d_0208e00c
	mov r0, r4
	add r2, sp, #0x14
	add r3, sp, #0x138
	str r6, [sp]
	bl OS_SPrintf
	mov r0, #1
	str r0, [sp]
	ldr r1, [sl, #0x10]
	mov r0, sl
	mov r2, r4
	add r1, r1, r7
	mov r3, #0
	bl _ZN10CActorData12sub_02014CECEP10CActorAnimPKcmi
	ldr r0, [sl, #0x10]
	add r1, r6, #1
	add r0, r0, r5, lsl #4
	add r7, r7, #0x10
	strb r1, [r0, #1]
	add r5, r5, #1
_020414F8:
	add r6, r6, #1
	cmp r6, #0x1c
	blt _0204149C
	mov r0, #4
	str r0, [sl, #0x18]
	ldr r0, [sp, #0x1c8]
	strh sb, [sl, #0x1c]
	mov r2, #0
	ldr r1, [sp, #0x1c4]
	strh r2, [sl, #0x1e]
	str r1, [sl, #0x28]
	cmp r0, #0
	beq _0204159C
	cmp r1, #0
	bne _02041568
	mov r0, sl
	bl _ZN10CActorData12sub_02014310Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	mov r1, r1, lsl #0x10
	str r0, [sl, #0x2c]
	mov r0, sl
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_020141ACEm
	mov r0, sl
	bl _ZN10CActorData12sub_020142B4Ev
_02041568:
	mov r0, sl
	bl _ZN10CActorData12sub_02014364Ev
	mov r1, #0
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	mov r1, r0
	mov r1, r1, lsl #0x10
	str r0, [sl, #0x30]
	mov r0, sl
	mov r1, r1, lsr #0xd
	bl _ZN10CActorData12sub_0201429CEm
	mov r0, sl
	bl _ZN10CActorData12sub_020142F8Ev
_0204159C:
	ldr r0, _020415AC ; =0x00050834
	strh sb, [sl, r0]
	add sp, sp, #0x198
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_020415AC: .word 0x00050834
_020415B0: .word s_player_1d_0208dfd8
_020415B4: .word DAT_0208dfe4
_020415B8: .word s_data_player_s_LZ_bin_0208dfe8
_020415BC: .word 0x00050800
_020415C0: .word s_s_s_NCLR_0208e000
_020415C4: .word s_s_s_02d_0208e00c

	arm_func_start sub_020415C8
sub_020415C8: ; 0x020415C8
	stmdb sp!, {r3, lr}
	ldrb lr, [r0, #0x14]
	mov r3, #0
	cmp lr, #0
	ble _020415FC
	ldr ip, [r0, #0x10]
	arm_func_end sub_020415C8
_020415E0:
	add r0, ip, r3, lsl #4
	ldrb r2, [r0, #1]
	cmp r1, r2
	ldmeqia sp!, {r3, pc}
	add r3, r3, #1
	cmp r3, lr
	blt _020415E0
_020415FC:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_02041604
sub_02041604: ; 0x02041604
	stmdb sp!, {r4, lr}
	ldr r3, [r0]
	mov r4, r0
	ldr r3, [r3, #0x14]
	blx r3
	cmp r0, #0xff
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	ldrb lr, [r4, #0x14]
	mov r3, #0
	cmp lr, #0
	ble _02041658
	ldr ip, [r4, #0x10]
	arm_func_end sub_02041604
_02041638:
	add r2, ip, r3, lsl #4
	ldrb r1, [r2, #1]
	cmp r0, r1
	moveq r0, r2
	ldmeqia sp!, {r4, pc}
	add r3, r3, #1
	cmp r3, lr
	blt _02041638
_02041658:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_02041660
sub_02041660: ; 0x02041660
	mov r0, #0
	mov r3, r0
	arm_func_end sub_02041660
_02041668:
	mov r2, r1, asr r3
	tst r2, #1
	andne r0, r3, #0xff
	bxne lr
	add r3, r3, #1
	cmp r3, #0x1d
	blt _02041668
	bx lr

	arm_func_start sub_02041688
sub_02041688: ; 0x02041688
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02040DB8
	ldr r1, _020416A4 ; =0x0000FFFF
	ldr r0, _020416A8 ; =0x00050834
	strh r1, [r4, r0]
	ldmia sp!, {r4, pc}
	.align 2, 0
_020416A4: .word 0x0000FFFF
_020416A8: .word 0x00050834
	arm_func_end sub_02041688

	arm_func_start _ZN17UnkClass_020416ACC1Ei
_ZN17UnkClass_020416ACC1Ei: ; 0x020416AC
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r2, #0
	str r2, [r4]
	str r2, [r4, #4]
	str r2, [r4, #8]
	str r2, [r4, #0xc]
	str r2, [r4, #0x10]
	mov r3, r4
	str r1, [r4, #0x910]
	mvn r0, #0
	arm_func_end _ZN17UnkClass_020416ACC1Ei
_020416D8:
	add r2, r2, #1
	str r0, [r3, #0x24]
	cmp r2, #0x73
	add r3, r3, #0x14
	blt _020416D8
	mov r1, #0
	mov r0, r4
	str r1, [r4, #0x914]
	bl sub_02041718
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_020416ACD1Ev
_ZN17UnkClass_020416ACD1Ev: ; 0x02041704
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02041870
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_020416ACD1Ev

	arm_func_start sub_02041718
sub_02041718: ; 0x02041718
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	mov r0, #0x3c
	bl _Znwm
	cmp r0, #0
	beq _02041748
	mov r2, #0
	ldr r1, _02041864 ; =s_data_shadow_NCBR_0208e018
	mov r3, r2
	str r2, [sp]
	bl _ZN17UnkClass_020074D4C1EPKcmmm
	arm_func_end sub_02041718
_02041748:
	str r0, [r4]
	mov r1, #0
	ldr r0, [r0, #0x38]
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	str r0, [r4, #0xc]
	mov r1, r1, lsl #0x10
	ldr r0, [r4]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_020074D412sub_020076E8Em
	ldr r0, [r4]
	bl _ZN17UnkClass_020074D412sub_020076B0Ev
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _0204179C
	mov r2, #0
	ldr r1, _02041868 ; =s_data_shadow_NCLR_0208e02c
	mov r3, r2
	bl _ZN17UnkClass_02007AA4C1EPKcmm
_0204179C:
	str r0, [r4, #4]
	ldr r0, [r0, #4]
	mov r1, #0
	ldr r0, [r0, #8]
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	mov r1, r0
	str r0, [r4, #0x10]
	mov r1, r1, lsl #0x10
	ldr r0, [r4, #4]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007BFCEm
	ldr r0, [r4, #4]
	bl _ZN17UnkClass_02007AA412sub_02007BC4Ev
	mov r0, #0x40
	bl _Znwm
	cmp r0, #0
	beq _020417E8
	bl _ZN14CPrimitiveRECTC1Ev
_020417E8:
	mov r1, #0
	str r0, [r4, #8]
	ldr r0, _0204186C ; =0x000003FF
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r2, r1
	mov r3, r1
	bl _ZN14CPrimitiveRECT12SetRectangleElllll
	ldr r1, [r4, #8]
	mov r0, #0
	str r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	mov r0, #0x40000
	str r0, [r1, #0x30]
	mov r0, #0x20000
	str r0, [r1, #0x34]
	ldr r1, [r4]
	ldr r0, [r4, #8]
	mov r2, #2
	str r1, [r0, #0x38]
	ldr r3, [r4, #4]
	ldr r0, [r4, #8]
	mov r1, #8
	str r3, [r0, #0x3c]
	ldr r0, [r4, #8]
	str r2, [r0, #0x10]
	ldr r0, [r4, #8]
	str r1, [r0, #0x14]
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041864: .word s_data_shadow_NCBR_0208e018
_02041868: .word s_data_shadow_NCLR_0208e02c
_0204186C: .word 0x000003FF

	arm_func_start sub_02041870
sub_02041870: ; 0x02041870
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r5, [r4]
	cmp r5, #0
	beq _020418A0
	beq _02041898
	mov r0, r5
	bl _ZN17UnkClass_020074D4D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end sub_02041870
_02041898:
	mov r0, #0
	str r0, [r4]
_020418A0:
	ldr r5, [r4, #4]
	cmp r5, #0
	beq _020418C8
	beq _020418C0
	mov r0, r5
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r5
	bl _ZdlPv
_020418C0:
	mov r0, #0
	str r0, [r4, #4]
_020418C8:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _020418EC
	beq _020418E4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020418E4:
	mov r0, #0
	str r0, [r4, #8]
_020418EC:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _02041904
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4, #0xc]
_02041904:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #0x10]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02041920
sub_02041920: ; 0x02041920
	bx lr
	arm_func_end sub_02041920

	arm_func_start sub_02041924
sub_02041924: ; 0x02041924
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	sub sp, sp, #8
	mov sl, r0
	ldr r0, [sl, #0x914]
	mov sb, r1
	cmp r0, #0
	mov r8, r2
	mov r7, r3
	mov r4, #0
	addle sp, sp, #8
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	mov r5, sl
	add r6, sl, #0x14
	arm_func_end sub_02041924
_02041958:
	ldr r0, [r5, #0x24]
	cmp r8, r0
	bne _0204198C
	ldr r0, [r6, #0xc]
	stmia sp, {r0, r7}
	ldr r0, [sl, #8]
	ldmia r6, {r1, r2, r3}
	bl _ZN14CPrimitiveRECT12SetRectangleElllll
	ldr r0, [sl, #8]
	mov r1, sb
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
_0204198C:
	ldr r0, [sl, #0x914]
	add r4, r4, #1
	cmp r4, r0
	add r5, r5, #0x14
	add r6, r6, #0x14
	blt _02041958
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}

	arm_func_start sub_020419AC
sub_020419AC: ; 0x020419AC
	mov r3, r0
	mov r2, #0
	mvn r1, #0
	arm_func_end sub_020419AC
_020419B8:
	add r2, r2, #1
	str r1, [r3, #0x24]
	cmp r2, #0x73
	add r3, r3, #0x14
	blt _020419B8
	mov r1, #0
	str r1, [r0, #0x914]
	bx lr

	arm_func_start sub_020419D8
sub_020419D8: ; 0x020419D8
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, r4, r5, lr}
	ldr r3, [sp, #0x20]
	cmp r1, #0
	ldr ip, [sp, #0x1c]
	ldr r2, [sp, #0x24]
	ldmltia sp!, {r3, r4, r5, lr}
	addlt sp, sp, #0x10
	bxlt lr
	ldr r4, [r0, #0x910]
	cmp r1, r4
	ldrlt r5, [r0, #0x914]
	cmplt r5, #0x73
	ldmgeia sp!, {r3, r4, r5, lr}
	addge sp, sp, #0x10
	bxge lr
	mov lr, #0x14
	mla r4, r5, lr, r0
	str r1, [r4, #0x24]
	ldr r4, [r0, #0x914]
	ldr r1, [sp, #0x18]
	mul lr, r4, lr
	add r4, r0, #0x14
	str r1, [r4, lr]
	add r1, r4, lr
	str ip, [r1, #4]
	str r3, [r1, #8]
	str r2, [r1, #0xc]
	ldr r1, [r0, #0x914]
	add r1, r1, #1
	str r1, [r0, #0x914]
	ldmia sp!, {r3, r4, r5, lr}
	add sp, sp, #0x10
	bx lr
	arm_func_end sub_020419D8

	arm_func_start sub_02041A60
sub_02041A60: ; 0x02041A60
	ldr r0, [r0, #8]
	cmp r0, #0
	strne r1, [r0, #0x14]
	bx lr
	arm_func_end sub_02041A60

	arm_func_start sub_02041A70
sub_02041A70: ; 0x02041A70
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	movs r6, r0
	ldrne r0, _02041C10 ; =MAIN_BSS_0210CA60
	mov r5, r1
	ldrne r7, [r0]
	mov r4, r2
	mov r8, #0
	cmpne r7, #0
	beq _02041C08
	ldr r0, [r6, #0xd0]
	mov r0, r0, lsl #0x10
	movs r8, r0, lsr #0x10
	beq _02041AD8
	mov r0, r7
	mov r1, r8
	bl ov0_02143088
	cmp r0, #0
	beq _02041AD8
	ldr r0, [r0, #0x24]
	cmp r0, #0xd
	cmpne r0, #9
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r0, r7
	mov r1, r8
	bl ov0_021430D8
	arm_func_end sub_02041A70
_02041AD8:
	cmp r5, #0xe
	mvn r2, #0
	mov sb, #0
	addls pc, pc, r5, lsl #2
	b _02041B94
_02041AEC: ; jump table
	b _02041B28 ; case 0
	b _02041B28 ; case 1
	b _02041B28 ; case 2
	b _02041B30 ; case 3
	b _02041B38 ; case 4
	b _02041B44 ; case 5
	b _02041B50 ; case 6
	b _02041B58 ; case 7
	b _02041B60 ; case 8
	b _02041B78 ; case 9
	b _02041B88 ; case 10
	b _02041B90 ; case 11
	b _02041B68 ; case 12
	b _02041B70 ; case 13
	b _02041B80 ; case 14
_02041B28:
	mov r2, #0x24
	b _02041B94
_02041B30:
	mov r2, #0x25
	b _02041B94
_02041B38:
	mov r2, #0x26
	mov sb, #8
	b _02041B94
_02041B44:
	mov r2, #0x27
	mov sb, #8
	b _02041B94
_02041B50:
	mov r2, #0x28
	b _02041B94
_02041B58:
	mov r2, #0x29
	b _02041B94
_02041B60:
	mov r2, #0x2a
	b _02041B94
_02041B68:
	mov r2, #0x65
	b _02041B94
_02041B70:
	mov r2, #0x66
	b _02041B94
_02041B78:
	mov r2, #0x64
	b _02041B94
_02041B80:
	mov r2, #0x67
	b _02041B94
_02041B88:
	mov r2, #0x41
	b _02041B94
_02041B90:
	mov r2, #0x41
_02041B94:
	cmp r2, #0
	blt _02041C08
	mov r0, r7
	mov r1, #1
	bl ov0_02142F6C
	mov r8, r0
	mov r0, r7
	mov r1, r8
	str r8, [r6, #0xd0]
	bl ov0_02143088
	movs r7, r0
	beq _02041C08
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #0x5c]
	blx r2
	mov r0, r7
	str r6, [r7, #0x1c]
	ldr r5, [r0]
	mov r1, sb
	ldr r5, [r5, #0x1c]
	mov r2, r4
	mov r3, #0
	blx r5
	mov r0, r7
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x24]
	blx r2
_02041C08:
	mov r0, r8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02041C10: .word MAIN_BSS_0210CA60

	arm_func_start sub_02041C14
sub_02041C14: ; 0x02041C14
	str r1, [r0, #0x24]
	bx lr
	arm_func_end sub_02041C14

	arm_func_start sub_02041C1C
sub_02041C1C: ; 0x02041C1C
	stmdb sp!, {r4, r5, r6, lr}
	movs r4, r0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r4, #0xd0]
	ldr r1, _02041C7C ; =MAIN_BSS_0210CA60
	mov r0, r0, lsl #0x10
	ldr r6, [r1]
	movs r5, r0, lsr #0x10
	cmpne r6, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	mov r0, r6
	mov r1, r5
	bl ov0_02143088
	cmp r0, #0
	beq _02041C70
	ldr r0, [r0, #0x1c]
	cmp r0, r4
	bne _02041C70
	mov r0, r6
	mov r1, r5
	bl ov0_021430D8
	arm_func_end sub_02041C1C
_02041C70:
	mov r0, #0
	str r0, [r4, #0xd0]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02041C7C: .word MAIN_BSS_0210CA60

	arm_func_start _ZN17UnkClass_02041C80C1EPKci
_ZN17UnkClass_02041C80C1EPKci: ; 0x02041C80
	stmdb sp!, {r4, lr}
	ldr r3, _02041CB0 ; =MAIN_BSS_0210CA6C
	mov r4, r0
	str r4, [r3]
	mov r3, #0
	str r3, [r4]
	str r3, [r4, #4]
	str r3, [r4, #8]
	str r3, [r4, #0xc]
	bl sub_02041CB4
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02041CB0: .word MAIN_BSS_0210CA6C
	arm_func_end _ZN17UnkClass_02041C80C1EPKci

	arm_func_start sub_02041CB4
sub_02041CB4: ; 0x02041CB4
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0xc
	mov r4, r0
	mov r0, #0xb8
	mov r6, r1
	mov r5, r2
	bl _Znwm
	cmp r0, #0
	beq _02041CF4
	mov r2, #0
	str r5, [sp]
	str r2, [sp, #4]
	mov r1, r6
	mov r3, r2
	str r2, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	arm_func_end sub_02041CB4
_02041CF4:
	str r0, [r4]
	ldr r1, [r0, #0x4c]
	ldr r0, [r1, #8]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #8]
	ldr r0, [r1, #0xc]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #0xc]
	ldr r0, [r1, #0x10]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #4]
	ldr r0, [r1, #0x14]
	add r0, r1, r0
	add r0, r0, #8
	str r0, [r4, #0x10]
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, r5, r6, pc}

	arm_func_start sub_02041D44
sub_02041D44: ; 0x02041D44
	ldr r0, [r0, #4]
	cmp r0, #0
	addne r0, r0, r1, lsl #2
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D44

	arm_func_start sub_02041D58
sub_02041D58: ; 0x02041D58
	ldr r0, [r0, #8]
	cmp r0, #0
	addne r0, r0, r1, lsl #6
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D58

	arm_func_start sub_02041D6C
sub_02041D6C: ; 0x02041D6C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	addne r0, r0, r1, lsl #5
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D6C

	arm_func_start sub_02041D80
sub_02041D80: ; 0x02041D80
	ldr r2, [r0, #0x10]
	cmp r2, #0
	movne r0, #0x54
	mlane r0, r1, r0, r2
	moveq r0, #0
	bx lr
	arm_func_end sub_02041D80

	arm_func_start sub_02041D98
sub_02041D98: ; 0x02041D98
	ldr r3, [r0, #0x1c]
	ldr ip, [r0, #8]
	mov r3, r3, lsl #0x1a
	orr r3, r3, ip, lsr #3
	orr r2, r3, r2, lsl #30
	ldr ip, [r0, #0x20]
	ldr r3, [r0, #0x24]
	orr r2, r2, ip, lsl #20
	orr r3, r2, r3, lsl #23
	ldr r2, _02041DF0 ; =0x040004A8
	orr r1, r3, r1, lsl #29
	str r1, [r2]
	ldr r1, [r0, #0x1c]
	cmp r1, #2
	moveq r2, #1
	movne r2, #0
	ldr r1, [r0, #0xc]
	rsb r0, r2, #4
	mov r1, r1, lsr r0
	ldr r0, _02041DF4 ; =0x040004AC
	str r1, [r0]
	bx lr
	.align 2, 0
_02041DF0: .word 0x040004A8
_02041DF4: .word 0x040004AC
	arm_func_end sub_02041D98

	arm_func_start sub_02041DF8
sub_02041DF8: ; 0x02041DF8
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x24
	mov r7, r0
	ldr r2, [r7, #0x14]
	mov r6, r1
	cmp r2, #0
	addeq sp, sp, #0x24
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, pc}
	ldr r4, [r7, #0x50]
	ldr r3, [r7, #0x4c]
	ldr r2, [r7, #0x40]
	ldr r1, [r7, #0x3c]
	str r1, [r7, #0x1c]
	str r2, [r7, #0x20]
	str r3, [r7, #0x24]
	str r4, [r7, #0x28]
	bl sub_02041F50
	ldr r0, [r7, #0x40]
	ldr r1, [r7, #0x3c]
	mov r2, r0, asr #0xc
	mov r3, r1, asr #0xc
	ldrh r5, [r6, #0x28]
	ldr r0, _02041F3C ; =0x04000450
	mov r1, #0
	str r1, [r0]
	ldrh r0, [r7, #0x54]
	mov r4, r3, lsl r5
	cmp r0, #0
	ldreq r0, [r7, #0x44]
	mov r5, r2, lsl r5
	cmpeq r0, #0x1000
	ldreq r0, [r7, #0x48]
	cmpeq r0, #0x1000
	beq _02041F1C
	ldr r1, _02041F40 ; =0x04000470
	mov r0, #0
	str r4, [r1]
	str r5, [r1]
	str r0, [r1]
	ldrh r0, [r7, #0x54]
	cmp r0, #0
	beq _02041ED4
	mov r0, r0, asr #4
	mov r1, r0, lsl #1
	add r0, r1, #1
	ldr r2, _02041F44 ; =FX_SinCosTable_
	mov r1, r1, lsl #1
	mov r0, r0, lsl #1
	ldrsh r1, [r2, r1]
	ldrsh r2, [r2, r0]
	add r0, sp, #0
	blx MTX_RotZ33_
	add r0, sp, #0
	bl G3_MultMtx33
	arm_func_end sub_02041DF8
_02041ED4:
	ldr r3, [r7, #0x44]
	cmp r3, #0x1000
	ldreq r0, [r7, #0x48]
	cmpeq r0, #0x1000
	beq _02041F00
	ldr r2, [r7, #0x48]
	ldr r1, _02041F48 ; =0x0400046C
	mov r0, #0x1000
	str r3, [r1]
	str r2, [r1]
	str r0, [r1]
_02041F00:
	ldr r1, _02041F40 ; =0x04000470
	rsb r0, r4, #0
	str r0, [r1]
	rsb r0, r5, #0
	str r0, [r1]
	mov r0, #0
	str r0, [r1]
_02041F1C:
	mov r0, r7
	mov r1, r6
	bl sub_02036558
	ldr r1, _02041F4C ; =0x04000448
	mov r2, #0
	str r2, [r1]
	add sp, sp, #0x24
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_02041F3C: .word 0x04000450
_02041F40: .word 0x04000470
_02041F44: .word FX_SinCosTable_
_02041F48: .word 0x0400046C
_02041F4C: .word 0x04000448

	arm_func_start sub_02041F50
sub_02041F50: ; 0x02041F50
	stmdb sp!, {r3, lr}
	mov r1, r0
	ldr r0, [r1, #0x18]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r1, #0x58]
	mov r2, #0
	bl sub_02041D98
	ldmia sp!, {r3, pc}
	arm_func_end sub_02041F50

	arm_func_start sub_02041F74
sub_02041F74: ; 0x02041F74
	stmdb sp!, {r4, r5, r6, lr}
	mov r4, r0
	ldr r0, [r4, #0x18]
	mov r5, r1
	cmp r0, #0
	beq _02041F98
	mov r1, #0
	mov r2, r1
	bl sub_02041D98
	arm_func_end sub_02041F74
_02041F98:
	ldr r1, _020420A0 ; =0x04000450
	mov r2, #0
	str r2, [r1]
	ldrh r3, [r5, #0x28]
	ldrh r5, [r4, #8]
	mov r0, #1
	rsb r3, r3, #0xc
	str r5, [r1, #0x30]
	ldr r5, [r4, #0xc]
	ldr r6, [r4, #0x10]
	mov r5, r5, lsl #4
	orr r5, r5, #0xc0
	ldr ip, [r4, #0x14]
	orr r5, r5, r6, lsl #24
	orr r5, r5, ip, lsl #16
	str r5, [r1, #0x54]
	ldr r5, [r4, #0x1c]
	ldr r6, [r4, #0x20]
	mov r5, r5, asr r3
	mov r6, r6, asr r3
	str r5, [r1, #0x20]
	str r6, [r1, #0x20]
	str r2, [r1, #0x20]
	str r0, [r1, #0xb0]
_02041FF8:
	add r0, r4, r2, lsl #3
	ldr r5, [r0, #0x48]
	ldr r6, [r0, #0x44]
	mov ip, r5, lsl #8
	mov r5, ip, asr #0x10
	mov ip, r6, lsl #8
	mov lr, r5, lsl #0x10
	mov r6, ip, asr #0x10
	mov r5, lr, lsr #0x10
	mov ip, r6, lsl #0x10
	mov r5, r5, lsl #0x10
	orr r5, r5, ip, lsr #16
	str r5, [r1, #0x38]
	ldr ip, [r0, #0x28]
	ldr r5, [r0, #0x24]
	mov r0, ip, asr r3
	mov r5, r5, asr r3
	mov r0, r0, lsl #0x10
	mov r0, r0, asr #0x10
	ldr r6, [r4, #4]
	mov ip, r5, lsl #0x10
	mov lr, r0, lsl #0x10
	mov r0, r6, lsl #0x10
	mov r5, ip, asr #0x10
	mov lr, lr, lsr #0x10
	mov r0, r0, asr #0x10
	mov ip, r0, lsl #0x10
	add r2, r2, #1
	mov r0, r5, lsl #0x10
	mov lr, lr, lsl #0x10
	orr r0, lr, r0, lsr #16
	str r0, [r1, #0x3c]
	mov r0, ip, lsr #0x10
	str r0, [r1, #0x3c]
	cmp r2, #4
	blt _02041FF8
	ldr r0, _020420A4 ; =0x04000504
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #-0xbc]
	mov r0, #1
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_020420A0: .word 0x04000450
_020420A4: .word 0x04000504

	arm_func_start sub_020420A8
sub_020420A8: ; 0x020420A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420A8

	arm_func_start sub_020420BC
sub_020420BC: ; 0x020420BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420BC

	arm_func_start sub_020420D8
sub_020420D8: ; 0x020420D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420D8

	arm_func_start sub_020420EC
sub_020420EC: ; 0x020420EC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN10CPrimitiveD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020420EC

	arm_func_start sub_02042108
sub_02042108: ; 0x02042108
	stmdb sp!, {r4, lr}
	mov r4, r0
	strb r1, [r4]
	bl sub_02042134
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02042108

	arm_func_start sub_02042120
sub_02042120: ; 0x02042120
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02042318
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02042120

	arm_func_start sub_02042134
sub_02042134: ; 0x02042134
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x70
	mov r5, r0
	bl sub_02042318
	ldrb r2, [r5]
	ldr r1, _02042300 ; =s_data_battle_bg_capbg_03d_LZ_bin_0208e0b0
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x6c
	bl _Znwm
	movs r4, r0
	beq _0204218C
	mov r3, #1
	str r3, [sp]
	mov r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	ldr r1, _02042304 ; =DAT_0208e0d0
	add r2, sp, #0x10
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r4, r0
	arm_func_end sub_02042134
_0204218C:
	ldrb r2, [r5]
	ldr r1, _02042308 ; =s_BBG_capbg_03d_NCBR_0208e0d4
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x3c
	bl _Znwm
	cmp r0, #0
	beq _020421C0
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	str r2, [sp]
	bl _ZN17UnkClass_020074D4C1EPKcmmm
_020421C0:
	str r0, [r5, #8]
	mov r1, #0
	ldr r0, [r0, #0x38]
	mov r2, r1
	bl NNS_GfdAllocLnkTexVram
	mov r1, r0
	str r0, [r5, #0x14]
	mov r1, r1, lsl #0x10
	ldr r0, [r5, #8]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_020074D412sub_020076E8Em
	ldr r0, [r5, #8]
	bl _ZN17UnkClass_020074D412sub_020076B0Ev
	ldrb r2, [r5]
	ldr r1, _0204230C ; =s_BBG_capbg_03d_NCLR_0208e0e8
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0x24
	bl _Znwm
	cmp r0, #0
	beq _02042224
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	bl _ZN17UnkClass_02007AA4C1EPKcmm
_02042224:
	str r0, [r5, #0xc]
	ldr r0, [r0, #4]
	mov r1, #0
	ldr r0, [r0, #8]
	mov r2, r1
	bl NNS_GfdAllocLnkPlttVram
	mov r1, r0
	str r0, [r5, #0x18]
	mov r1, r1, lsl #0x10
	ldr r0, [r5, #0xc]
	mov r1, r1, lsr #0xd
	bl _ZN17UnkClass_02007AA412sub_02007BFCEm
	ldr r0, [r5, #0xc]
	bl _ZN17UnkClass_02007AA412sub_02007BC4Ev
	ldrb r2, [r5]
	ldr r1, _02042310 ; =s_BBG_capbg_03d_NCER_0208e0fc
	add r0, sp, #0x10
	bl OS_SPrintf
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02042290
	mov r2, #0
	add r1, sp, #0x10
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNCERFileC1EPKcmmm
_02042290:
	str r0, [r5, #0x10]
	mov r0, #0x4c
	bl _Znwm
	cmp r0, #0
	beq _020422A8
	bl _ZN15CSoftwareSpriteC1Ev
_020422A8:
	str r0, [r5, #4]
	ldr r3, [r5, #0x10]
	ldr r2, [r5, #0xc]
	ldr r1, [r5, #8]
	cmp r4, #0
	str r1, [r0, #0x2c]
	mov r1, #0
	str r1, [r0, #0x30]
	str r2, [r0, #0x34]
	str r3, [r0, #0x38]
	cmpne r4, #0
	ldr r0, [r5, #4]
	ldr r1, _02042314 ; =0xFFFFFC01
	addeq sp, sp, #0x70
	str r1, [r0, #4]
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r4
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r4
	bl _ZdlPv
	add sp, sp, #0x70
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02042300: .word s_data_battle_bg_capbg_03d_LZ_bin_0208e0b0
_02042304: .word DAT_0208e0d0
_02042308: .word s_BBG_capbg_03d_NCBR_0208e0d4
_0204230C: .word s_BBG_capbg_03d_NCLR_0208e0e8
_02042310: .word s_BBG_capbg_03d_NCER_0208e0fc
_02042314: .word 0xFFFFFC01

	arm_func_start sub_02042318
sub_02042318: ; 0x02042318
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _02042344
	beq _0204233C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02042318
_0204233C:
	mov r0, #0
	str r0, [r4, #4]
_02042344:
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _02042360
	ldr r0, [r4, #0x14]
	bl NNS_GfdFreeLnkTexVram
	mov r0, #0
	str r0, [r4, #0x14]
_02042360:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0204237C
	ldr r0, [r4, #0x18]
	bl NNS_GfdFreeLnkPlttVram
	mov r0, #0
	str r0, [r4, #0x18]
_0204237C:
	ldr r5, [r4, #8]
	cmp r5, #0
	beq _020423A4
	beq _0204239C
	mov r0, r5
	bl _ZN17UnkClass_020074D4D1Ev
	mov r0, r5
	bl _ZdlPv
_0204239C:
	mov r0, #0
	str r0, [r4, #8]
_020423A4:
	ldr r5, [r4, #0xc]
	cmp r5, #0
	beq _020423CC
	beq _020423C4
	mov r0, r5
	bl _ZN17UnkClass_02007AA4D1Ev
	mov r0, r5
	bl _ZdlPv
_020423C4:
	mov r0, #0
	str r0, [r4, #0xc]
_020423CC:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	beq _020423E8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020423E8:
	mov r0, #0
	str r0, [r4, #0x10]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_020423F4
sub_020423F4: ; 0x020423F4
	stmdb sp!, {r3, lr}
	ldr r0, [r0, #4]
	ldr r2, [r0]
	ldr r2, [r2, #8]
	blx r2
	ldmia sp!, {r3, pc}
	arm_func_end sub_020423F4

	arm_func_start sub_0204240C
sub_0204240C: ; 0x0204240C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r1
	ldrh r1, [r0, #0x2a]
	bl _ZN15CSoftwareSprite18GetCellNumOAMAttrsEt
	ldr r1, [r5, #4]
	add r0, r4, r0
	str r0, [r1, #4]
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_0204240C

	arm_func_start sub_02042434
sub_02042434: ; 0x02042434
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x18
	ldr r1, _020424F0 ; =MAIN_BSS_020BA6A0
	mov r4, r0
	ldr r1, [r1, #0x1ac]
	mov r0, #0x74
	str r1, [r4, #0x10]
	bl _Znwm
	cmp r0, #0
	beq _02042464
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
	arm_func_end sub_02042434
_02042464:
	str r0, [r4, #0xc]
	mov lr, #0
	str lr, [r4, #8]
	ldr ip, [r4, #4]
	mov r2, #0x10
	add r0, ip, #0x1000
	ldr r3, [r0, #0x4b0]
	add r1, ip, #0x24
	str r3, [sp]
	str r1, [sp, #4]
	ldr r3, [r0, #0x48c]
	mov r1, #0x4000
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp, #0x10]
	str lr, [sp, #0x14]
	ldr r3, [r0, #0x4ac]
	ldr r0, [r0, #0x490]
	ldr r1, [ip, #0x14]
	ldr r2, [ip, #0x18]
	add r3, r3, #0xc
	bl _ZN17UnkClass_020091E812sub_02009328EP17UnkClass_02001C04P11CTouchPanelP10NNSG2dFontPvP10CGame_0024S6_mmm
	bl _Z12sub_02007D68v
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	ldr r0, [r4, #4]
	mov r1, #0x3c
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	add sp, sp, #0x18
	ldmia sp!, {r4, pc}
	.align 2, 0
_020424F0: .word MAIN_BSS_020BA6A0

	arm_func_start sub_020424F4
sub_020424F4: ; 0x020424F4
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02042524
	beq _0204251C
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_020424F4
_0204251C:
	mov r0, #0
	str r0, [r5, #0xc]
_02042524:
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AC90Ev
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02042548
sub_02042548: ; 0x02042548
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x430
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0x13
	addls pc, pc, r0, lsl #2
	b _02042F54
_02042564: ; jump table
	b _020425B4 ; case 0
	b _020425D8 ; case 1
	b _02042660 ; case 2
	b _02042748 ; case 3
	b _02042760 ; case 4
	b _02042810 ; case 5
	b _02042B34 ; case 6
	b _02042BA4 ; case 7
	b _02042BE0 ; case 8
	b _02042C50 ; case 9
	b _02042C8C ; case 10
	b _02042CB0 ; case 11
	b _02042D30 ; case 12
	b _02042D88 ; case 13
	b _02042DC4 ; case 14
	b _02042E34 ; case 15
	b _02042E70 ; case 16
	b _02042F54 ; case 17
	b _02042EE0 ; case 18
	b _02042F1C ; case 19
	arm_func_end sub_02042548
_020425B4:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl sub_020282CC
	mov r0, #1
	str r0, [r4, #8]
	b _02042F54
_020425D8:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02042F54
	tst r0, #0x80
	beq _02042654
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02042F54
_02042600: ; jump table
	b _02042630 ; case 0
	b _02042630 ; case 1
	b _02042630 ; case 2
	b _02042648 ; case 3
	b _02042F54 ; case 4
	b _02042F54 ; case 5
	b _02042F54 ; case 6
	b _02042F54 ; case 7
	b _02042630 ; case 8
	b _02042648 ; case 9
	b _0204263C ; case 10
	b _02042648 ; case 11
_02042630:
	mov r0, #0x10
	str r0, [r4, #8]
	b _02042F54
_0204263C:
	mov r0, #0xa
	str r0, [r4, #8]
	b _02042F54
_02042648:
	mov r0, #0xa
	str r0, [r4, #8]
	b _02042F54
_02042654:
	mov r0, #2
	str r0, [r4, #8]
	b _02042F54
_02042660:
	ldr r1, [r4, #4]
	ldr r6, _02042F60 ; =MAIN_BSS_020AF624
	add r3, r1, #0x1000
	ldr r1, _02042F64 ; =DAT_0208e11c
	add r0, sp, #0x28
	mov r2, #0x10
	ldr r5, [r3, #0x49c]
	bl CRYPTO_RC4FastInit
	add r0, sp, #0x28
	mov r1, r6
	mov r3, r6
	mov r2, #0x3000
	bl CRYPTO_RC4FastEncrypt
	ldr r0, [r6]
	and r0, r0, #0xf0
	cmp r0, #0x20
	bgt _020426B4
	bge _020426E0
	cmp r0, #0x10
	beq _020426D0
	b _0204270C
_020426B4:
	cmp r0, #0x30
	bgt _020426C4
	beq _020426F0
	b _0204270C
_020426C4:
	cmp r0, #0x80
	beq _02042700
	b _0204270C
_020426D0:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UncompressLZ8
	b _0204270C
_020426E0:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UncompressHuffman
	b _0204270C
_020426F0:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UncompressRL8
	b _0204270C
_02042700:
	mov r0, r6
	add r1, r5, #0x1c
	bl MI_UnfilterDiff8
_0204270C:
	add r0, r5, #0x1c
	bl sub_02044AC8
	mov r0, #5
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldr r2, _02042F6C ; =MAIN_BSS_0210CA6C
	ldrh r1, [r0, #0x1a]
	ldr r0, [r2]
	bl sub_02041D80
	ldrb r1, [r0, #4]
	ldr r0, _02042F70 ; =MAIN_BSS_020BA6A0
	strb r1, [r0, #0xb64]
	b _02042F54
_02042748:
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl sub_020282CC
	mov r0, #4
	str r0, [r4, #8]
	b _02042F54
_02042760:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02042F54
	tst r0, #0x80
	beq _020427DC
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02042F54
_02042788: ; jump table
	b _020427B8 ; case 0
	b _020427B8 ; case 1
	b _020427B8 ; case 2
	b _020427D0 ; case 3
	b _02042F54 ; case 4
	b _02042F54 ; case 5
	b _02042F54 ; case 6
	b _02042F54 ; case 7
	b _020427B8 ; case 8
	b _020427D0 ; case 9
	b _020427C4 ; case 10
	b _020427D0 ; case 11
_020427B8:
	mov r0, #0x10
	str r0, [r4, #8]
	b _02042F54
_020427C4:
	mov r0, #8
	str r0, [r4, #8]
	b _02042F54
_020427D0:
	mov r0, #6
	str r0, [r4, #8]
	b _02042F54
_020427DC:
	mov r0, #5
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldr r2, _02042F6C ; =MAIN_BSS_0210CA6C
	ldrh r1, [r0, #0x1a]
	ldr r0, [r2]
	bl sub_02041D80
	ldrb r1, [r0, #4]
	ldr r0, _02042F70 ; =MAIN_BSS_020BA6A0
	strb r1, [r0, #0xb64]
	b _02042F54
_02042810:
	ldr r2, [r4, #0x10]
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	add r2, r2, #0x45
	mov r1, #0
	str r2, [sp, #8]
	bl sub_020162BC
	ldr r1, _02042F70 ; =MAIN_BSS_020BA6A0
	mov r3, #0
	strb r3, [r1, #0x802]
	ldr r2, [r4, #0x10]
	mov r0, #1
	str r2, [r1, #0x1ac]
	str r0, [r1, #0xb68]
	ldr r0, [sp, #8]
	ldr r2, _02042F68 ; =MAIN_BSS_020B26A0
	str r0, [r1, #0xb6c]
	mov r4, r3
_02042854:
	add r0, r2, #0x8000
	add r3, r3, #1
	str r4, [r0, #0xad4]
	cmp r3, #2
	add r2, r2, #0x38
	blt _02042854
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldr fp, _02042F68 ; =MAIN_BSS_020B26A0
	add r0, r0, #4
	mov r5, r4
	mov r6, r4
	add r8, r0, #0x8800
_02042884:
	mov r7, #0
	mov sb, fp
	mov sl, r8
_02042890:
	cmp r6, #0
	bne _020428B0
	add r0, sb, #0x8000
	ldr r0, [r0, #0x80c]
	tst r0, #2
	movne r4, sl
	movne r5, r7
	bne _020428B8
_020428B0:
	mov r0, sl
	bl sub_020150B8
_020428B8:
	add r7, r7, #1
	cmp r7, #0xa
	add sb, sb, #0x18
	add sl, sl, #0x18
	blt _02042890
	add r6, r6, #1
	cmp r6, #3
	add fp, fp, #0xf0
	add r8, r8, #0xf0
	blt _02042884
	cmp r4, #0
	cmpne r5, #0
	beq _02042954
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	ldrh r3, [r4]
	add r1, r0, #0x8800
	add r2, r0, #0x8000
	strh r3, [r1, #4]
	ldrh r5, [r4, #2]
	mov r3, #0
	mov r0, r4
	strh r5, [r1, #6]
	ldrh r5, [r4, #4]
	strh r5, [r1, #8]
	ldr r5, [r4, #8]
	str r5, [r2, #0x80c]
	ldr r6, [r4, #0xc]
	ldr r5, [r4, #0x10]
	str r6, [r2, #0x810]
	str r5, [r2, #0x814]
	ldrh r5, [r4, #0x14]
	strh r5, [r1, #0x18]
	ldrh r5, [r4, #0x16]
	str r3, [r2, #0x80c]
	strh r5, [r1, #0x1a]
	ldr r1, [r4, #8]
	orr r1, r1, #0
	str r1, [r2, #0x80c]
	bl sub_020150B8
_02042954:
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	bl sub_02016024
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	mov r2, #0x140
	add r0, r0, #0x1b4
	add r1, r0, #0x8000
	mov r0, #0
	bl MIi_CpuClearFast
	ldr r1, _02042F68 ; =MAIN_BSS_020B26A0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	add r2, r1, #0x8000
	mov r3, #0
	mov r1, #1
	strb r3, [r2, #0x434]
	str r3, [r2, #0xad4]
	str r3, [r2, #0xb0c]
	bl sub_02019278
	mov sl, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #2
	bl sub_02019278
	mov sb, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1b
	bl sub_02019278
	mov r8, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1c
	bl sub_02019278
	mov r7, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1d
	bl sub_02019278
	mov r6, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0x1e
	bl sub_02019278
	mov r5, r0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #4
	bl sub_02019278
	mov r4, r0
	ldr r0, _02042F78 ; =MAIN_BSS_020B2638
	bl sub_0201135C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	bl sub_02018E1C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	bl sub_02018E30
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r1, #0
	bl sub_02018E94
	ldr r1, [sp, #8]
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	bl sub_02018E94
	ldr r0, _02042F78 ; =MAIN_BSS_020B2638
	mov r1, #0
	bl sub_020116C0
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, sl
	mov r1, #1
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, sb
	mov r1, #2
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r8
	mov r1, #0x1b
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r7
	mov r1, #0x1c
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r6
	mov r1, #0x1d
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r5
	mov r1, #0x1e
	bl sub_0201926C
	ldr r0, _02042F74 ; =MAIN_BSS_0210C0B0
	mov r2, r4
	mov r1, #4
	bl sub_0201926C
	ldr r0, _02042F7C ; =MAIN_BSS_0210C1C0
	mov r1, #0
	mov r2, #0x60
	bl MI_CpuFill8
	ldr r0, _02042F80 ; =MAIN_BSS_0210C228
	mov r1, #0
	mov r2, #0x800
	bl MI_CpuFill8
	ldr r0, _02042F68 ; =MAIN_BSS_020B26A0
	mov r1, #0
	ldrb r2, [r0, #2]
	str r1, [r0, #4]
	strb r2, [r0, #1]
	add r0, sp, #0x1c
	bl RTC_GetTime
	add r0, sp, #0xc
	bl RTC_GetDate
	ldr r2, [sp, #0x1c]
	ldr r1, _02042F70 ; =MAIN_BSS_020BA6A0
	ldr r0, [sp, #0x20]
	str r2, [r1, #0xb94]
	str r0, [r1, #0xb98]
	ldr r2, [sp, #0x24]
	ldr r0, [sp, #0xc]
	str r2, [r1, #0xb9c]
	str r0, [r1, #0xb84]
	ldr r2, [sp, #0x10]
	ldr r0, [sp, #0x14]
	str r2, [r1, #0xb88]
	ldr r2, [sp, #0x18]
	str r0, [r1, #0xb8c]
	str r2, [r1, #0xb90]
	add sp, sp, #0x430
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02042B34:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x48
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #7
	str r0, [r4, #8]
	b _02042F54
_02042BA4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042BE0:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #9
	str r0, [r4, #8]
	b _02042F54
_02042C50:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042C8C:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl sub_02028374
	mov r0, #0xb
	str r0, [r4, #8]
	b _02042F54
_02042CB0:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02042F54
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x73
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0xc
	str r0, [r4, #8]
	b _02042F54
_02042D30:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x74
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0xd
	str r0, [r4, #8]
	b _02042F54
_02042D88:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042DC4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xf
	str r0, [r4, #8]
	b _02042F54
_02042E34:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0x12
	str r0, [r4, #8]
	b _02042F54
_02042E70:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0x11
	str r0, [r4, #8]
	b _02042F54
_02042EE0:
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0x13
	str r0, [r4, #8]
	b _02042F54
_02042F1C:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02042F54
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #0x430
	moveq r0, #0x11
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02042F54:
	mvn r0, #0
	add sp, sp, #0x430
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02042F60: .word MAIN_BSS_020AF624
_02042F64: .word DAT_0208e11c
_02042F68: .word MAIN_BSS_020B26A0
_02042F6C: .word MAIN_BSS_0210CA6C
_02042F70: .word MAIN_BSS_020BA6A0
_02042F74: .word MAIN_BSS_0210C0B0
_02042F78: .word MAIN_BSS_020B2638
_02042F7C: .word MAIN_BSS_0210C1C0
_02042F80: .word MAIN_BSS_0210C228

	arm_func_start sub_02042F84
sub_02042F84: ; 0x02042F84
	stmdb sp!, {r3, lr}
	bl GX_ResetBankForBG
	bl GX_ResetBankForOBJ
	bl GX_ResetBankForBGExtPltt
	bl GX_ResetBankForOBJExtPltt
	bl GX_ResetBankForTex
	bl GX_ResetBankForTexPltt
	bl GX_ResetBankForClearImage
	bl GX_ResetBankForSubBG
	bl GX_ResetBankForSubOBJ
	bl GX_ResetBankForSubBGExtPltt
	bl GX_ResetBankForSubOBJExtPltt
	bl GX_ResetBankForARM7
	mov r0, #0xf
	bl GX_SetBankForTex
	mov r0, #0x40
	bl GX_SetBankForTexPltt
	mov r0, #0x10
	bl GX_SetBankForOBJ
	mov r0, #0x20
	bl GX_SetBankForBG
	mov r0, #1
	mov r1, #0
	mov r2, r0
	bl GX_SetGraphicsMode
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #0x100
	bl GX_SetBankForSubOBJ
	mov r1, #0
	str r1, [sp]
	ldr r0, _020430C0 ; =0x04000050
	mov r2, r1
	mov r3, r1
	bl G2x_SetBlendAlpha_
	ldr lr, _020430C4 ; =0x04000060
	ldr r0, _020430C8 ; =0xFFFFFDF1
	ldrh r1, [lr]
	add ip, lr, #0x2a4
	mov r2, #0x4000000
	bic r1, r1, #0x3000
	orr r1, r1, #8
	strh r1, [lr]
	ldrh r3, [lr]
	mov r1, #0
	bic r3, r3, #0x3000
	orr r3, r3, #0x10
	strh r3, [lr]
	ldrh r3, [ip]
	and r0, r3, r0
	orr r0, r0, #0xe
	orr r0, r0, #0x200
	strh r0, [ip]
	ldrh r0, [ip]
	bic r0, r0, #0x8000
	strh r0, [ip]
	ldr r0, [r2]
	bic r0, r0, #0x38000000
	str r0, [r2]
	ldr r0, [r2]
	bic r0, r0, #0x7000000
	str r0, [r2]
	str r1, [r2, #0x10]
	str r1, [r2, #0x14]
	str r1, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldr r0, [r2]
	add r1, r2, #0x1000
	bic r0, r0, #0x1f00
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	str r0, [r1]
	bl GX_DispOn
	ldr r1, _020430CC ; =0x04001000
	ldr r0, [r1]
	orr r0, r0, #0x10000
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020430C0: .word 0x04000050
_020430C4: .word 0x04000060
_020430C8: .word 0xFFFFFDF1
_020430CC: .word 0x04001000
	arm_func_end sub_02042F84

	arm_func_start sub_020430D0
sub_020430D0: ; 0x020430D0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02043120 ; =ptr_FUN_02043134_0208e154
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02043108
	beq _02043100
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_020430D0
_02043100:
	mov r0, #0
	str r0, [r5, #0xc]
_02043108:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	bl _ZdlPv
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02043120: .word ptr_FUN_02043134_0208e154

	arm_func_start sub_02043124
sub_02043124: ; 0x02043124
	bx lr
	arm_func_end sub_02043124

	arm_func_start sub_02043128
sub_02043128: ; 0x02043128
	bx lr
	arm_func_end sub_02043128

	arm_func_start sub_0204312C
sub_0204312C: ; 0x0204312C
	mov r0, #0x1c
	bx lr
	arm_func_end sub_0204312C

	arm_func_start sub_02043134
sub_02043134: ; 0x02043134
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0204317C ; =ptr_FUN_02043134_0208e154
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _0204316C
	beq _02043164
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02043134
_02043164:
	mov r0, #0
	str r0, [r5, #0xc]
_0204316C:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0204317C: .word ptr_FUN_02043134_0208e154

	arm_func_start sub_02043180
sub_02043180: ; 0x02043180
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x18
	ldr r3, _0204331C ; =MAIN_BSS_020B26A0
	mov r4, r0
	ldrb r2, [r3, #2]
	ldr r1, _02043320 ; =MAIN_BSS_020BA6A0
	ldr r0, _02043324 ; =MAIN_BSS_020BA2DC
	strb r2, [r4, #0x10]
	ldrb r5, [r1, #0x7db]
	add r1, r4, #0x1c
	mov r2, #0x80
	strb r5, [r4, #0x11]
	ldr r5, [r3, #0x28]
	str r5, [r4, #0x14]
	ldr r3, [r3, #0x2c]
	str r3, [r4, #0x18]
	bl MIi_CpuCopyFast
	ldr r0, _02043328 ; =MAIN_BSS_020BA550
	add r1, r4, #0x9c
	mov r2, #0x80
	bl MIi_CpuCopyFast
	ldr r0, _0204332C ; =MAIN_BSS_020BA35C
	add r1, r4, #0x11c
	mov r2, #0x1f4
	bl MI_CpuCopy8
	ldr r3, _02043320 ; =MAIN_BSS_020BA6A0
	ldr r0, _02043330 ; =MAIN_BSS_020BAE0C
	ldr r2, [r3, #0x758]
	add r1, r4, #0x328
	str r2, [r4, #0x314]
	ldr r5, [r3, #0x75c]
	mov r2, #0x44
	str r5, [r4, #0x318]
	ldr r5, [r3, #0x760]
	str r5, [r4, #0x31c]
	ldr r5, [r3, #0x764]
	str r5, [r4, #0x320]
	ldr r3, [r3, #0x768]
	str r3, [r4, #0x324]
	bl MIi_CpuCopyFast
	ldr r2, _02043320 ; =MAIN_BSS_020BA6A0
	ldr r1, _02043334 ; =MAIN_BSS_020BADA0
	ldr r3, [r2, #0x7b0]
	add r0, r4, #0x300
	str r3, [r4, #0x36c]
	ldr r3, [r2, #0x7b4]
	mov lr, #0x10
	str r3, [r4, #0x370]
	ldrh r5, [r1, #0xb8]
	mov ip, #0x4000
	mov r3, #0
	strh r5, [r0, #0x74]
	ldrh r5, [r1, #0xba]
	strh r5, [r0, #0x76]
	ldrh r1, [r1, #0xbc]
	strh r1, [r0, #0x78]
	ldr r0, [r2, #0x7cc]
	str r0, [r4, #0x37c]
	ldrb r0, [r2, #0x7d0]
	strb r0, [r4, #0x380]
	ldr r0, [r2, #0x7d4]
	str r0, [r4, #0x384]
	ldrb r0, [r2, #0x7d8]
	strb r0, [r4, #0x388]
	ldrb r0, [r2, #0x7d9]
	strb r0, [r4, #0x389]
	ldrb r0, [r2, #0x7da]
	strb r0, [r4, #0x38a]
	ldrb r0, [r2, #0x803]
	strb r0, [r4, #0x310]
	ldr r0, [r2, #0x1ac]
	str r0, [r4, #0x38c]
	ldr r5, [r4, #4]
	add r1, r5, #0x1000
	ldr r2, [r1, #0x4b0]
	add r0, r5, #0x24
	str r2, [sp]
	str r0, [sp, #4]
	ldr r0, [r1, #0x48c]
	str r0, [sp, #8]
	str lr, [sp, #0xc]
	str ip, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r0, [r1, #0x490]
	ldr r3, [r1, #0x4ac]
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	add r3, r3, #0xc
	bl _ZN17UnkClass_020091E812sub_02009328EP17UnkClass_02001C04P11CTouchPanelP10NNSG2dFontPvP10CGame_0024S6_mmm
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	mov r0, #0
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	mov r1, #0x3c
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0204331C: .word MAIN_BSS_020B26A0
_02043320: .word MAIN_BSS_020BA6A0
_02043324: .word MAIN_BSS_020BA2DC
_02043328: .word MAIN_BSS_020BA550
_0204332C: .word MAIN_BSS_020BA35C
_02043330: .word MAIN_BSS_020BAE0C
_02043334: .word MAIN_BSS_020BADA0
	arm_func_end sub_02043180

	arm_func_start sub_02043338
sub_02043338: ; 0x02043338
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02043368
	beq _02043360
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02043338
_02043360:
	mov r0, #0
	str r0, [r5, #0xc]
_02043368:
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AC90Ev
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0204338C
sub_0204338C: ; 0x0204338C
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02043854
_020433A8: ; jump table
	b _020433D8 ; case 0
	b _02043408 ; case 1
	b _02043498 ; case 2
	b _0204360C ; case 3
	b _02043618 ; case 4
	b _02043688 ; case 5
	b _020436C4 ; case 6
	b _02043854 ; case 7
	b _02043734 ; case 8
	b _020437A4 ; case 9
	b _020437E0 ; case 10
	b _0204381C ; case 11
	arm_func_end sub_0204338C
_020433D8:
	mov r0, #0x74
	bl _Znwm
	cmp r0, #0
	beq _020433F0
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
_020433F0:
	mov r1, #0
	str r0, [r4, #0xc]
	bl sub_020282CC
	mov r0, #1
	str r0, [r4, #8]
	b _02043854
_02043408:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02043854
	tst r0, #0x80
	beq _02043484
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02043854
_02043430: ; jump table
	b _02043460 ; case 0
	b _02043460 ; case 1
	b _02043460 ; case 2
	b _02043478 ; case 3
	b _02043854 ; case 4
	b _02043854 ; case 5
	b _02043854 ; case 6
	b _02043854 ; case 7
	b _02043460 ; case 8
	b _02043478 ; case 9
	b _0204346C ; case 10
	b _02043478 ; case 11
_02043460:
	mov r0, #6
	str r0, [r4, #8]
	b _02043854
_0204346C:
	mov r0, #8
	str r0, [r4, #8]
	b _02043854
_02043478:
	mov r0, #4
	str r0, [r4, #8]
	b _02043854
_02043484:
	mov r0, #2
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	b _02043854
_02043498:
	ldrb r1, [r4, #0x10]
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	strb r1, [r0, #2]
	ldrb r1, [r4, #0x11]
	bl sub_020160B8
	ldr r1, [r4, #0x14]
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	str r1, [r0, #0x28]
	ldr r1, [r4, #0x18]
	bl sub_02016D4C
	ldr r1, _02043864 ; =MAIN_BSS_020BA2DC
	add r0, r4, #0x1c
	mov r2, #0x80
	bl MIi_CpuCopyFast
	ldr r1, _02043868 ; =MAIN_BSS_020BA550
	add r0, r4, #0x9c
	mov r2, #0x80
	bl MIi_CpuCopyFast
	ldr r1, _0204386C ; =MAIN_BSS_020BA35C
	add r0, r4, #0x11c
	mov r2, #0x1f4
	bl MI_CpuCopy8
	ldrb r2, [r4, #0x310]
	ldr r1, _02043870 ; =MAIN_BSS_020BA6A0
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	strb r2, [r1, #0x803]
	ldr r1, [r4, #0x314]
	bl sub_02016D88
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x318]
	bl sub_02016DD0
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x31c]
	bl sub_02016E18
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x320]
	bl sub_02016E60
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x324]
	bl sub_02016EA8
	add r0, r4, #0x328
	ldr r1, _02043874 ; =MAIN_BSS_020BAE0C
	mov r2, #0x44
	bl MIi_CpuCopyFast
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x36c]
	bl sub_02017020
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	ldr r1, [r4, #0x370]
	bl sub_02017068
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	add r1, r4, #0x300
	ldrh r1, [r1, #0x74]
	bl sub_020170B0
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	add r1, r4, #0x300
	ldrh r1, [r1, #0x76]
	bl sub_02017100
	ldr r0, _02043860 ; =MAIN_BSS_020B26A0
	add r1, r4, #0x300
	ldrh r1, [r1, #0x78]
	bl sub_02017150
	ldr r1, [r4, #0x37c]
	ldr r0, _02043870 ; =MAIN_BSS_020BA6A0
	str r1, [r0, #0x7cc]
	ldrb r1, [r4, #0x380]
	strb r1, [r0, #0x7d0]
	ldr r1, [r4, #0x384]
	str r1, [r0, #0x7d4]
	ldrb r1, [r4, #0x388]
	strb r1, [r0, #0x7d8]
	ldrb r1, [r4, #0x389]
	strb r1, [r0, #0x7d9]
	ldrb r1, [r4, #0x38a]
	strb r1, [r0, #0x7da]
	ldr r0, [r4, #0x38c]
	subs r5, r0, #1
	bmi _02043600
	cmp r5, #6
	bge _02043600
	ldr r0, _02043878 ; =MAIN_BSS_020AF598
	mov r1, r5
	bl sub_020112DC
	cmp r5, #3
	bge _02043600
	ldr r1, _0204387C ; =MAIN_BSS_020AF5E4
	mov r0, #0x14
	mla r0, r5, r0, r1
	mov r1, r5
	bl sub_02010F5C
_02043600:
	mov r0, #3
	str r0, [r4, #8]
	b _02043854
_0204360C:
	add sp, sp, #8
	mov r0, #0x15
	ldmia sp!, {r3, r4, r5, pc}
_02043618:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x48
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #5
	str r0, [r4, #8]
	b _02043854
_02043688:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043854
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xa
	str r0, [r4, #8]
	b _02043854
_020436C4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #7
	str r0, [r4, #8]
	b _02043854
_02043734:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #9
	str r0, [r4, #8]
	b _02043854
_020437A4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043854
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xa
	str r0, [r4, #8]
	b _02043854
_020437E0:
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xb
	str r0, [r4, #8]
	b _02043854
_0204381C:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02043854
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #8
	moveq r0, #0x11
	ldmeqia sp!, {r3, r4, r5, pc}
_02043854:
	mvn r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02043860: .word MAIN_BSS_020B26A0
_02043864: .word MAIN_BSS_020BA2DC
_02043868: .word MAIN_BSS_020BA550
_0204386C: .word MAIN_BSS_020BA35C
_02043870: .word MAIN_BSS_020BA6A0
_02043874: .word MAIN_BSS_020BAE0C
_02043878: .word MAIN_BSS_020AF598
_0204387C: .word MAIN_BSS_020AF5E4

	arm_func_start sub_02043880
sub_02043880: ; 0x02043880
	stmdb sp!, {r3, lr}
	bl GX_ResetBankForBG
	bl GX_ResetBankForOBJ
	bl GX_ResetBankForBGExtPltt
	bl GX_ResetBankForOBJExtPltt
	bl GX_ResetBankForTex
	bl GX_ResetBankForTexPltt
	bl GX_ResetBankForClearImage
	bl GX_ResetBankForSubBG
	bl GX_ResetBankForSubOBJ
	bl GX_ResetBankForSubBGExtPltt
	bl GX_ResetBankForSubOBJExtPltt
	bl GX_ResetBankForARM7
	mov r0, #0xf
	bl GX_SetBankForTex
	mov r0, #0x40
	bl GX_SetBankForTexPltt
	mov r0, #0x10
	bl GX_SetBankForOBJ
	mov r0, #0x20
	bl GX_SetBankForBG
	mov r0, #1
	mov r1, #0
	mov r2, r0
	bl GX_SetGraphicsMode
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #0x100
	bl GX_SetBankForSubOBJ
	mov r1, #0
	str r1, [sp]
	ldr r0, _02043998 ; =0x04000050
	mov r2, r1
	mov r3, r1
	bl G2x_SetBlendAlpha_
	ldr lr, _0204399C ; =0x04000060
	ldr r0, _020439A0 ; =0xFFFFFDF1
	ldrh r1, [lr]
	add ip, lr, #0x2a4
	mov r2, #0x4000000
	bic r1, r1, #0x3000
	orr r1, r1, #8
	strh r1, [lr]
	ldrh r3, [lr]
	add r1, r2, #0x1000
	bic r3, r3, #0x3000
	orr r3, r3, #0x10
	strh r3, [lr]
	ldrh r3, [ip]
	and r0, r3, r0
	orr r0, r0, #0xe
	orr r0, r0, #0x200
	strh r0, [ip]
	ldrh r0, [ip]
	bic r0, r0, #0x8000
	strh r0, [ip]
	ldr r0, [r2]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r1]
	bl GX_DispOn
	ldr r1, _020439A4 ; =0x04001000
	ldr r0, [r1]
	orr r0, r0, #0x10000
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02043998: .word 0x04000050
_0204399C: .word 0x04000060
_020439A0: .word 0xFFFFFDF1
_020439A4: .word 0x04001000
	arm_func_end sub_02043880

	arm_func_start sub_020439A8
sub_020439A8: ; 0x020439A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN6CSceneD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020439A8

	arm_func_start sub_020439C4
sub_020439C4: ; 0x020439C4
	bx lr
	arm_func_end sub_020439C4

	arm_func_start sub_020439C8
sub_020439C8: ; 0x020439C8
	bx lr
	arm_func_end sub_020439C8

	arm_func_start sub_020439CC
sub_020439CC: ; 0x020439CC
	mov r0, #0x1d
	bx lr
	arm_func_end sub_020439CC

	arm_func_start sub_020439D4
sub_020439D4: ; 0x020439D4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN6CSceneD2Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_020439D4

	arm_func_start sub_020439E8
sub_020439E8: ; 0x020439E8
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x18
	ldr r1, _02043AA4 ; =MAIN_BSS_020BA6A0
	mov r4, r0
	ldr r1, [r1, #0x1ac]
	mov r0, #0x74
	str r1, [r4, #0x10]
	bl _Znwm
	cmp r0, #0
	beq _02043A18
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
	arm_func_end sub_020439E8
_02043A18:
	str r0, [r4, #0xc]
	mov lr, #0
	str lr, [r4, #8]
	ldr ip, [r4, #4]
	mov r2, #0x10
	add r0, ip, #0x1000
	ldr r3, [r0, #0x4b0]
	add r1, ip, #0x24
	str r3, [sp]
	str r1, [sp, #4]
	ldr r3, [r0, #0x48c]
	mov r1, #0x4000
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	str r1, [sp, #0x10]
	str lr, [sp, #0x14]
	ldr r3, [r0, #0x4ac]
	ldr r0, [r0, #0x490]
	ldr r1, [ip, #0x14]
	ldr r2, [ip, #0x18]
	add r3, r3, #0xc
	bl _ZN17UnkClass_020091E812sub_02009328EP17UnkClass_02001C04P11CTouchPanelP10NNSG2dFontPvP10CGame_0024S6_mmm
	bl _Z12sub_02007D68v
	ldr r0, [r4, #4]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	ldr r0, [r4, #4]
	mov r1, #0x3c
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	add sp, sp, #0x18
	ldmia sp!, {r4, pc}
	.align 2, 0
_02043AA4: .word MAIN_BSS_020BA6A0

	arm_func_start sub_02043AA8
sub_02043AA8: ; 0x02043AA8
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02043AD8
	beq _02043AD0
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02043AA8
_02043AD0:
	mov r0, #0
	str r0, [r5, #0xc]
_02043AD8:
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AC90Ev
	ldr r0, [r5, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02043AFC
sub_02043AFC: ; 0x02043AFC
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x410
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0xc
	addls pc, pc, r0, lsl #2
	b _02043FA8
_02043B18: ; jump table
	b _02043B4C ; case 0
	b _02043B70 ; case 1
	b _02043C20 ; case 2
	b _02043CE0 ; case 3
	b _02043D04 ; case 4
	b _02043D84 ; case 5
	b _02043DDC ; case 6
	b _02043EC4 ; case 7
	b _02043FA8 ; case 8
	b _02043E18 ; case 9
	b _02043E88 ; case 10
	b _02043F34 ; case 11
	b _02043F70 ; case 12
	arm_func_end sub_02043AFC
_02043B4C:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl sub_020282CC
	mov r0, #1
	str r0, [r4, #8]
	b _02043FA8
_02043B70:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02043FA8
	tst r0, #0x80
	beq _02043BEC
	bic r0, r0, #0x80
	cmp r0, #0xb
	addls pc, pc, r0, lsl #2
	b _02043FA8
_02043B98: ; jump table
	b _02043BC8 ; case 0
	b _02043BC8 ; case 1
	b _02043BC8 ; case 2
	b _02043BE0 ; case 3
	b _02043FA8 ; case 4
	b _02043FA8 ; case 5
	b _02043FA8 ; case 6
	b _02043FA8 ; case 7
	b _02043BC8 ; case 8
	b _02043BE0 ; case 9
	b _02043BD4 ; case 10
	b _02043BE0 ; case 11
_02043BC8:
	mov r0, #7
	str r0, [r4, #8]
	b _02043FA8
_02043BD4:
	mov r0, #3
	str r0, [r4, #8]
	b _02043FA8
_02043BE0:
	mov r0, #3
	str r0, [r4, #8]
	b _02043FA8
_02043BEC:
	mov r0, #2
	str r0, [r4, #8]
	ldr r0, [r4, #4]
	bl _ZN5CGame12sub_0201024CEv
	ldr r0, _02043FB4 ; =MAIN_BSS_020B26A0
	ldr r2, _02043FB8 ; =MAIN_BSS_0210CA6C
	ldrh r1, [r0, #0x1a]
	ldr r0, [r2]
	bl sub_02041D80
	ldrb r1, [r0, #4]
	ldr r0, _02043FBC ; =MAIN_BSS_020BA6A0
	strb r1, [r0, #0xb64]
	b _02043FA8
_02043C20:
	ldr r1, [r4, #4]
	ldr r5, _02043FC0 ; =MAIN_BSS_020AF624
	add r3, r1, #0x1000
	ldr r1, _02043FC4 ; =DAT_0208e11c
	add r0, sp, #8
	mov r2, #0x10
	ldr r4, [r3, #0x49c]
	bl CRYPTO_RC4FastInit
	add r0, sp, #8
	mov r1, r5
	mov r3, r5
	mov r2, #0x3000
	bl CRYPTO_RC4FastEncrypt
	ldr r0, [r5]
	and r0, r0, #0xf0
	cmp r0, #0x20
	bgt _02043C74
	bge _02043CA0
	cmp r0, #0x10
	beq _02043C90
	b _02043CCC
_02043C74:
	cmp r0, #0x30
	bgt _02043C84
	beq _02043CB0
	b _02043CCC
_02043C84:
	cmp r0, #0x80
	beq _02043CC0
	b _02043CCC
_02043C90:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UncompressLZ8
	b _02043CCC
_02043CA0:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UncompressHuffman
	b _02043CCC
_02043CB0:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UncompressRL8
	b _02043CCC
_02043CC0:
	mov r0, r5
	add r1, r4, #0x1c
	bl MI_UnfilterDiff8
_02043CCC:
	add r0, r4, #0x1c
	bl sub_02044AC8
	add sp, sp, #0x410
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_02043CE0:
	ldr r1, [r4, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r1, #1
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl sub_02028374
	mov r0, #4
	str r0, [r4, #8]
	b _02043FA8
_02043D04:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02043FA8
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x73
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #5
	str r0, [r4, #8]
	b _02043FA8
_02043D84:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x74
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #6
	str r0, [r4, #8]
	b _02043FA8
_02043DDC:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xb
	str r0, [r4, #8]
	b _02043FA8
_02043E18:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x50
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xa
	str r0, [r4, #8]
	b _02043FA8
_02043E88:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0xb
	str r0, [r4, #8]
	b _02043FA8
_02043EC4:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #3
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #5
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #8
	str r0, [r4, #8]
	b _02043FA8
_02043F34:
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, [r4, #4]
	mov r1, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, #0x1e
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0xc
	str r0, [r4, #8]
	b _02043FA8
_02043F70:
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02043FA8
	ldr r0, [r4, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	addeq sp, sp, #0x410
	moveq r0, #0x11
	ldmeqia sp!, {r3, r4, r5, pc}
_02043FA8:
	mvn r0, #0
	add sp, sp, #0x410
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02043FB4: .word MAIN_BSS_020B26A0
_02043FB8: .word MAIN_BSS_0210CA6C
_02043FBC: .word MAIN_BSS_020BA6A0
_02043FC0: .word MAIN_BSS_020AF624
_02043FC4: .word DAT_0208e11c

	arm_func_start sub_02043FC8
sub_02043FC8: ; 0x02043FC8
	stmdb sp!, {r3, lr}
	bl GX_ResetBankForBG
	bl GX_ResetBankForOBJ
	bl GX_ResetBankForBGExtPltt
	bl GX_ResetBankForOBJExtPltt
	bl GX_ResetBankForTex
	bl GX_ResetBankForTexPltt
	bl GX_ResetBankForClearImage
	bl GX_ResetBankForSubBG
	bl GX_ResetBankForSubOBJ
	bl GX_ResetBankForSubBGExtPltt
	bl GX_ResetBankForSubOBJExtPltt
	bl GX_ResetBankForARM7
	mov r0, #0xf
	bl GX_SetBankForTex
	mov r0, #0x40
	bl GX_SetBankForTexPltt
	mov r0, #0x10
	bl GX_SetBankForOBJ
	mov r0, #0x20
	bl GX_SetBankForBG
	mov r0, #1
	mov r1, #0
	mov r2, r0
	bl GX_SetGraphicsMode
	mov r0, #0x80
	bl GX_SetBankForSubBG
	mov r0, #0x100
	bl GX_SetBankForSubOBJ
	mov r1, #0
	str r1, [sp]
	ldr r0, _020440E0 ; =0x04000050
	mov r2, r1
	mov r3, r1
	bl G2x_SetBlendAlpha_
	ldr lr, _020440E4 ; =0x04000060
	ldr r0, _020440E8 ; =0xFFFFFDF1
	ldrh r1, [lr]
	add ip, lr, #0x2a4
	mov r2, #0x4000000
	bic r1, r1, #0x3000
	orr r1, r1, #8
	strh r1, [lr]
	ldrh r3, [lr]
	add r1, r2, #0x1000
	bic r3, r3, #0x3000
	orr r3, r3, #0x10
	strh r3, [lr]
	ldrh r3, [ip]
	and r0, r3, r0
	orr r0, r0, #0xe
	orr r0, r0, #0x200
	strh r0, [ip]
	ldrh r0, [ip]
	bic r0, r0, #0x8000
	strh r0, [ip]
	ldr r0, [r2]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x800
	str r0, [r1]
	bl GX_DispOn
	ldr r1, _020440EC ; =0x04001000
	ldr r0, [r1]
	orr r0, r0, #0x10000
	str r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020440E0: .word 0x04000050
_020440E4: .word 0x04000060
_020440E8: .word 0xFFFFFDF1
_020440EC: .word 0x04001000
	arm_func_end sub_02043FC8

	arm_func_start sub_020440F0
sub_020440F0: ; 0x020440F0
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02044140 ; =ptr_FUN_02044154_0208e210
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _02044128
	beq _02044120
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_020440F0
_02044120:
	mov r0, #0
	str r0, [r5, #0xc]
_02044128:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	bl _ZdlPv
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02044140: .word ptr_FUN_02044154_0208e210

	arm_func_start sub_02044144
sub_02044144: ; 0x02044144
	bx lr
	arm_func_end sub_02044144

	arm_func_start sub_02044148
sub_02044148: ; 0x02044148
	bx lr
	arm_func_end sub_02044148

	arm_func_start sub_0204414C
sub_0204414C: ; 0x0204414C
	mov r0, #0x1e
	bx lr
	arm_func_end sub_0204414C

	arm_func_start sub_02044154
sub_02044154: ; 0x02044154
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0204419C ; =ptr_FUN_02044154_0208e210
	mov r5, r0
	str r1, [r5]
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _0204418C
	beq _02044184
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end sub_02044154
_02044184:
	mov r0, #0
	str r0, [r5, #0xc]
_0204418C:
	mov r0, r5
	bl _ZN6CSceneD2Ev
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0204419C: .word ptr_FUN_02044154_0208e210

	arm_func_start thunk_FUN_02064f9c
thunk_FUN_02064f9c: ; 0x020441A0
	ldr ip, _020441A8 ; =OS_Printf
	bx ip
	.align 2, 0
_020441A8: .word OS_Printf
	arm_func_end thunk_FUN_02064f9c

	arm_func_start sub_020441AC
sub_020441AC: ; 0x020441AC
	bx lr
	arm_func_end sub_020441AC

	arm_func_start sub_020441B0
sub_020441B0: ; 0x020441B0
	stmdb sp!, {r3, lr}
	ldr r0, _020441F8 ; =MAIN_BSS_0210CAB4
	ldr r3, [r0, #4]
	cmp r3, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, [r0]
	ldr r0, _020441FC ; =MAIN_BSS_0210CAC8
	subs r1, r1, r0
	beq _020441E8
	mov r2, #1
	bl fwrite
	ldr r0, _020441F8 ; =MAIN_BSS_0210CAB4
	ldr r0, [r0, #4]
	bl fflush
	arm_func_end sub_020441B0
_020441E8:
	ldr r1, _020441FC ; =MAIN_BSS_0210CAC8
	ldr r0, _020441F8 ; =MAIN_BSS_0210CAB4
	str r1, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020441F8: .word MAIN_BSS_0210CAB4
_020441FC: .word MAIN_BSS_0210CAC8

	arm_func_start sub_02044200
sub_02044200: ; 0x02044200
	stmdb sp!, {r4, r5, r6, lr}
	ldr r5, _02044258 ; =MAIN_BSS_0210CAB4
	mov r4, r0
	ldr r0, [r5, #4]
	cmp r0, #0
	ldrnesb r0, [r4]
	cmpne r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r6, _0204425C ; =MAIN_BSS_0210CEC8
	arm_func_end sub_02044200
_02044224:
	ldr r1, [r5]
	add r0, r1, #1
	str r0, [r5]
	ldrsb r0, [r4], #1
	strb r0, [r1]
	ldr r0, [r5]
	cmp r0, r6
	blo _02044248
	bl sub_020441B0
_02044248:
	ldrsb r0, [r4]
	cmp r0, #0
	bne _02044224
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02044258: .word MAIN_BSS_0210CAB4
_0204425C: .word MAIN_BSS_0210CEC8

	arm_func_start sub_02044260
sub_02044260: ; 0x02044260
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _020442C4 ; =DAT_0208e23c
	mov r5, r0
	ldr r4, [r1, #4]
	tst r4, #4
	beq _0204427C
	bl sub_02044200
	arm_func_end sub_02044260
_0204427C:
	tst r4, #2
	beq _0204428C
	mov r0, r5
	bl thunk_FUN_02064f9c
_0204428C:
	tst r4, #8
	beq _0204429C
	mov r0, r5
	bl sub_020441AC
_0204429C:
	tst r4, #0x10
	ldrne r0, _020442C8 ; =MAIN_BSS_0210CAB4
	ldrne r3, [r0, #0x10]
	cmpne r3, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r1, [r0, #0xc]
	ldr r2, [r0, #8]
	mov r0, r5
	blx r3
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020442C4: .word DAT_0208e23c
_020442C8: .word MAIN_BSS_0210CAB4

	arm_func_start sub_020442CC
sub_020442CC: ; 0x020442CC
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x200
	mov r3, r0
	mov r2, r1
	add r0, sp, #0
	mov r1, r3
	bl vsprintf
	ldr r1, _02044304 ; =DAT_0208e244
	add r0, sp, #0
	bl strcat
	add r0, sp, #0
	bl sub_02044260
	add sp, sp, #0x200
	ldmia sp!, {r3, pc}
	.align 2, 0
_02044304: .word DAT_0208e244
	arm_func_end sub_020442CC

	arm_func_start sub_02044308
sub_02044308: ; 0x02044308
	stmdb sp!, {r3, lr}
	sub sp, sp, #0x200
	mov r3, r0
	mov r2, r1
	add r0, sp, #0
	mov r1, r3
	bl vsprintf
	add r0, sp, #0
	bl sub_02044260
	add sp, sp, #0x200
	ldmia sp!, {r3, pc}
	arm_func_end sub_02044308

	arm_func_start thunk_FUN_020442cc
thunk_FUN_020442cc: ; 0x02044334
	ldr ip, _0204433C ; =sub_020442CC
	bx ip
	.align 2, 0
_0204433C: .word sub_020442CC
	arm_func_end thunk_FUN_020442cc

	arm_func_start sub_02044340
sub_02044340: ; 0x02044340
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, lr}
	ldr r0, [sp, #8]
	add r1, sp, #0xc
	bl sub_020442CC
	ldmia sp!, {r3, lr}
	add sp, sp, #0x10
	bx lr
	arm_func_end sub_02044340

	arm_func_start thunk_FUN_02044308
thunk_FUN_02044308: ; 0x02044360
	ldr ip, _02044368 ; =sub_02044308
	bx ip
	.align 2, 0
_02044368: .word sub_02044308
	arm_func_end thunk_FUN_02044308
