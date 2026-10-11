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
	bl _ZN17UnkClass_02007AA412sub_02007B60EPKcmm
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
	bl _ZN17UnkClass_02007AA4C1Ev
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
