    .include "macros.inc"
    .include "include/overlay_11_021272F8.inc"

    .text

	arm_func_start ov11_021272F8
ov11_021272F8: ; 0x021272F8
	ldr r1, _0212730C ; =OVERLAY11_BSS_02169C44
	ldr r1, [r1]
	add r1, r1, #0x1000
	str r0, [r1, #0x330]
	bx lr
	.align 2, 0
_0212730C: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_021272F8

	arm_func_start ov11_02127310
ov11_02127310: ; 0x02127310
	ldr r1, _02127330 ; =OVERLAY11_BSS_02169C44
	ldr r1, [r1]
	add r1, r1, #0x1000
	ldr r2, [r1, #0x330]
	sub r2, r2, #9
	cmp r2, #1
	strhi r0, [r1, #0x34c]
	bx lr
	.align 2, 0
_02127330: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127310

	arm_func_start ov11_02127334
ov11_02127334: ; 0x02127334
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_021272F8
	ldr r1, _02127374 ; =OVERLAY11_BSS_02169C44
	ldr r0, _02127378 ; =ov11_0212737C
	ldr r1, [r1]
	add r1, r1, #0xf20
	bl WM_SetParentParameter
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127374: .word OVERLAY11_BSS_02169C44
_02127378: .word ov11_0212737C
	arm_func_end ov11_02127334

	arm_func_start ov11_0212737C
ov11_0212737C: ; 0x0212737C
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0212739C
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212737C
_0212739C:
	bl ov11_021273B4
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, pc}

	arm_func_start ov11_021273B4
ov11_021273B4: ; 0x021273B4
	stmdb sp!, {r4, lr}
	ldr r0, _02127444 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	sub r0, r0, #4
	cmp r0, #2
	movls r0, #1
	ldmlsia sp!, {r4, pc}
	bl WMi_GetStatusAddress
	mov r4, r0
	add r0, r4, #0x198
	mov r1, #4
	bl DC_InvalidateRange
	mov r2, #0
	add r0, r4, #0x198
	mov r1, #4
	str r2, [r4, #0x198]
	bl DC_FlushRange
	ldr r0, _02127448 ; =ov11_0212744C
	bl WM_StartParent
	cmp r0, #2
	beq _0212741C
	bl ov11_02127310
	mov r0, #0
	ldmia sp!, {r4, pc}
	arm_func_end ov11_021273B4
_0212741C:
	ldr r2, _02127444 ; =OVERLAY11_BSS_02169C44
	mov r3, #0
	ldr r1, [r2]
	mov r0, #1
	add r1, r1, #0x1300
	strh r3, [r1, #0x48]
	ldr r1, [r2]
	add r1, r1, #0x1300
	strh r0, [r1, #0x4a]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02127444: .word OVERLAY11_BSS_02169C44
_02127448: .word ov11_0212744C

	arm_func_start ov11_0212744C
ov11_0212744C: ; 0x0212744C
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldrh r1, [r4, #0x10]
	ldrh r0, [r4, #2]
	mov r2, #1
	mov r1, r2, lsl r1
	cmp r0, #0
	mov r5, r1, lsl #0x10
	beq _02127480
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov11_0212744C
_02127480:
	ldrh r0, [r4, #8]
	cmp r0, #7
	bgt _021274B0
	bge _021274E4
	cmp r0, #2
	ldmgtia sp!, {r3, r4, r5, pc}
	cmp r0, #0
	ldmltia sp!, {r3, r4, r5, pc}
	beq _021275C4
	cmp r0, #2
	beq _021274C8
	ldmia sp!, {r3, r4, r5, pc}
_021274B0:
	cmp r0, #9
	bgt _021274C0
	beq _02127588
	ldmia sp!, {r3, r4, r5, pc}
_021274C0:
	cmp r0, #0x1a
	ldmia sp!, {r3, r4, r5, pc}
_021274C8:
	ldr r0, _021275DC ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldrb r1, [r0, #0x361]
	add r1, r1, #1
	strb r1, [r0, #0x361]
	ldmia sp!, {r3, r4, r5, pc}
_021274E4:
	ldr r0, _021275DC ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldrb r1, [r0, #0x35f]
	cmp r1, #1
	ldrneb r0, [r0, #0x35e]
	cmpne r0, #1
	beq _02127548
	bl ov11_02127ABC
	ldr r1, _021275DC ; =OVERLAY11_BSS_02169C44
	ldr r1, [r1]
	add r1, r1, #0x1000
	ldrb r1, [r1, #0x350]
	cmp r0, r1
	bge _02127548
	bl ov11_02128EE0
	ldrb r1, [r4, #0x14]
	cmp r1, r0
	bne _02127548
	ldr r0, _021275E0 ; =s_DP_overlay_11_02166460
	add r1, r4, #0x15
	mov r2, #3
	bl memcmp
	cmp r0, #0
	beq _0212756C
_02127548:
	ldrh r1, [r4, #0x10]
	mov r0, #0
	bl WM_Disconnect
	cmp r0, #2
	ldmeqia sp!, {r3, r4, r5, pc}
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, r4, r5, pc}
_0212756C:
	ldr r0, _021275DC ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1300
	ldrh r1, [r0, #0x4a]
	orr r1, r1, r5, lsr #16
	strh r1, [r0, #0x4a]
	ldmia sp!, {r3, r4, r5, pc}
_02127588:
	ldr r1, _021275DC ; =OVERLAY11_BSS_02169C44
	mvn r2, r5, lsr #16
	ldr r0, [r1]
	add r0, r0, #0x1300
	ldrh r3, [r0, #0x4a]
	and r2, r3, r2
	strh r2, [r0, #0x4a]
	ldr r0, [r1]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x344]
	cmp r1, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldrh r0, [r4, #0x10]
	blx r1
	ldmia sp!, {r3, r4, r5, pc}
_021275C4:
	bl ov11_021275E4
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021275DC: .word OVERLAY11_BSS_02169C44
_021275E0: .word s_DP_overlay_11_02166460

	arm_func_start ov11_021275E4
ov11_021275E4: ; 0x021275E4
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	ldr r0, _02127674 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	sub r0, r0, #4
	cmp r0, #2
	addls sp, sp, #8
	movls r0, #1
	ldmlsia sp!, {r3, pc}
	mov r0, #4
	bl ov11_021272F8
	ldr r0, _02127674 ; =OVERLAY11_BSS_02169C44
	mov ip, #1
	ldr lr, [r0]
	ldr r0, _02127678 ; =ov11_0212767C
	add r3, lr, #0x1000
	ldr r2, [r3, #0x324]
	add r1, lr, #0x1040
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	stmia sp, {r2, ip}
	ldr r2, [r3, #0x328]
	add r3, lr, #0xf60
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	bl WM_StartMP
	cmp r0, #2
	addeq sp, sp, #8
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127674: .word OVERLAY11_BSS_02169C44
_02127678: .word ov11_0212767C
	arm_func_end ov11_021275E4

	arm_func_start ov11_0212767C
ov11_0212767C: ; 0x0212767C
	stmdb sp!, {r3, lr}
	ldrh r1, [r0, #2]
	cmp r1, #0
	beq _021276A0
	mov r0, r1
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212767C
_021276A0:
	ldrh r0, [r0, #4]
	sub r0, r0, #0xa
	cmp r0, #3
	addls pc, pc, r0, lsl #2
	ldmia sp!, {r3, pc}
_021276B4: ; jump table
	b _021276C4 ; case 0
	ldmia sp!, {r3, pc} ; case 1
	ldmia sp!, {r3, pc} ; case 2
	ldmia sp!, {r3, pc} ; case 3
_021276C4:
	ldr r0, _021276FC ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x334]
	cmp r1, #2
	bne _021276F0
	ldr r0, [r0, #0x330]
	cmp r0, #4
	beq _021276F0
	cmp r0, #6
	ldmeqia sp!, {r3, pc}
_021276F0:
	mov r0, #4
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	.align 2, 0
_021276FC: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_02127700
ov11_02127700: ; 0x02127700
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_021272F8
	ldr r0, _0212772C ; =ov11_02127730
	bl WM_EndMP
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212772C: .word ov11_02127730
	arm_func_end ov11_02127700

	arm_func_start ov11_02127730
ov11_02127730: ; 0x02127730
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0212774C
	bl ov11_02127310
	bl ov11_02128220
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127730
_0212774C:
	bl ov11_02127760
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	bl ov11_02128220
	ldmia sp!, {r3, pc}

	arm_func_start ov11_02127760
ov11_02127760: ; 0x02127760
	stmdb sp!, {r3, lr}
	ldr r0, _02127784 ; =ov11_02127788
	bl WM_EndParent
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127784: .word ov11_02127788
	arm_func_end ov11_02127760

	arm_func_start ov11_02127788
ov11_02127788: ; 0x02127788
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _021277A0
	bl ov11_02127310
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127788
_021277A0:
	mov r0, #1
	bl ov11_021272F8
	ldmia sp!, {r3, pc}

	arm_func_start ov11_021277AC
ov11_021277AC: ; 0x021277AC
	stmdb sp!, {r3, lr}
	ldr r0, _021277DC ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	cmp r0, #2
	movne r0, #0
	ldmneia sp!, {r3, pc}
	mov r0, #3
	bl ov11_021272F8
	mov r0, #1
	ldmia sp!, {r3, pc}
	.align 2, 0
_021277DC: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_021277AC

	arm_func_start ov11_021277E0
ov11_021277E0: ; 0x021277E0
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_021272F8
	ldr r0, _0212780C ; =ov11_02127810
	bl WM_EndMP
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212780C: .word ov11_02127810
	arm_func_end ov11_021277E0

	arm_func_start ov11_02127810
ov11_02127810: ; 0x02127810
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0212782C
	bl ov11_02127310
	bl ov11_0212825C
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127810
_0212782C:
	bl ov11_02127844
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, pc}

	arm_func_start ov11_02127844
ov11_02127844: ; 0x02127844
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_021272F8
	ldr r0, _02127878 ; =ov11_0212787C
	mov r1, #0
	bl WM_Disconnect
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	bl ov11_02128220
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127878: .word ov11_0212787C
	arm_func_end ov11_02127844

	arm_func_start ov11_0212787C
ov11_0212787C: ; 0x0212787C
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _02127894
	bl ov11_02127310
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212787C
_02127894:
	mov r0, #1
	bl ov11_021272F8
	ldmia sp!, {r3, pc}

	arm_func_start ov11_021278A0
ov11_021278A0: ; 0x021278A0
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_021272F8
	ldr r0, _021278CC ; =ov11_021278D0
	bl WM_Reset
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_021278CC: .word ov11_021278D0
	arm_func_end ov11_021278A0

	arm_func_start ov11_021278D0
ov11_021278D0: ; 0x021278D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _021278F8
	mov r0, #9
	bl ov11_021272F8
	ldrh r0, [r4, #2]
	bl ov11_02127310
	ldmia sp!, {r4, pc}
	arm_func_end ov11_021278D0
_021278F8:
	mov r0, #1
	bl ov11_021272F8
	ldmia sp!, {r4, pc}

	arm_func_start ov11_02127904
ov11_02127904: ; 0x02127904
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0xc
	ldr r5, _02127978 ; =OVERLAY11_BSS_02169C44
	mov r4, r1
	ldr ip, [r5]
	mov r5, r0
	add r0, ip, #0x1000
	ldr r1, [r0, #0x324]
	add r0, ip, #0xf60
	mov r7, r2
	mov r6, r3
	bl DC_FlushRange
	ldr r1, _0212797C ; =0x0000FFFF
	mov r0, r7, lsl #0x10
	str r1, [sp]
	mov ip, r0, lsr #0x10
	mov r3, r4
	ldr r0, _02127980 ; =ov11_02127984
	mov r1, r6
	mov r2, r5
	str ip, [sp, #4]
	mov r4, #2
	str r4, [sp, #8]
	bl WM_SetMPDataToPortEx
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	add sp, sp, #0xc
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_02127978: .word OVERLAY11_BSS_02169C44
_0212797C: .word 0x0000FFFF
_02127980: .word ov11_02127984
	arm_func_end ov11_02127904

	arm_func_start ov11_02127984
ov11_02127984: ; 0x02127984
	stmdb sp!, {r3, lr}
	ldrh r1, [r0, #2]
	cmp r1, #0
	cmpne r1, #0xf
	beq _021279A4
	mov r0, r1
	bl ov11_02127310
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127984
_021279A4:
	ldr r2, [r0, #0x20]
	cmp r2, #0
	ldmeqia sp!, {r3, pc}
	cmp r1, #0
	moveq r0, #1
	movne r0, #0
	blx r2
	ldmia sp!, {r3, pc}

	arm_func_start ov11_021279C4
ov11_021279C4: ; 0x021279C4
	stmdb sp!, {r3, lr}
	mov r1, r0
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq _021279E0
	bl ov11_02127310
	ldmia sp!, {r3, pc}
	arm_func_end ov11_021279C4
_021279E0:
	ldr r0, _02127A38 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r3, [r0, #0x338]
	cmp r3, #0
	ldrneh r0, [r1, #4]
	cmpne r0, #0x19
	ldmeqia sp!, {r3, pc}
	cmp r0, #0x15
	bne _02127A1C
	ldrh r0, [r1, #0x12]
	ldrh r2, [r1, #0x10]
	ldr r1, [r1, #0xc]
	blx r3
	ldmia sp!, {r3, pc}
_02127A1C:
	cmp r0, #9
	ldmneia sp!, {r3, pc}
	ldrh r0, [r1, #0x12]
	mov r1, #0
	mov r2, r1
	blx r3
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127A38: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_02127A3C
ov11_02127A3C: ; 0x02127A3C
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _02127A58
	mov r0, #0xa
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127A3C
_02127A58:
	mov r0, #0
	mov r1, r0
	bl WVR_TerminateAsync
	mov r0, #0
	bl ov11_021272F8
	ldmia sp!, {r3, pc}

	arm_func_start ov11_02127A70
ov11_02127A70: ; 0x02127A70
	ldr r1, _02127A80 ; =OVERLAY11_BSS_02169C44
	ldr r1, [r1]
	str r0, [r1, #0xf28]
	bx lr
	.align 2, 0
_02127A80: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127A70

	arm_func_start ov11_02127A84
ov11_02127A84: ; 0x02127A84
	ldr r2, _02127AA0 ; =OVERLAY11_BSS_02169C44
	ldr r3, [r2]
	str r0, [r3, #0xf20]
	ldr r0, [r2]
	add r0, r0, #0xf00
	strh r1, [r0, #0x24]
	bx lr
	.align 2, 0
_02127AA0: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127A84

	arm_func_start ov11_02127AA4
ov11_02127AA4: ; 0x02127AA4
	ldr r0, _02127AB8 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1300
	ldrh r0, [r0, #0x4a]
	bx lr
	.align 2, 0
_02127AB8: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127AA4

	arm_func_start ov11_02127ABC
ov11_02127ABC: ; 0x02127ABC
	ldr r1, _02127B04 ; =OVERLAY11_BSS_02169C44
	mov r0, #0
	ldr r1, [r1]
	mov r2, r0
	add r1, r1, #0x1300
	ldrh r3, [r1, #0x4a]
	arm_func_end ov11_02127ABC
_02127AD4:
	add r1, r2, #1
	mov r2, r1, lsl #0x10
	tst r3, #1
	addne r0, r0, #1
	movne r0, r0, lsl #0x10
	mov r1, r3, lsl #0xf
	mov r2, r2, lsr #0x10
	movne r0, r0, lsr #0x10
	cmp r2, #0x10
	mov r3, r1, lsr #0x10
	blo _02127AD4
	bx lr
	.align 2, 0
_02127B04: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_02127B08
ov11_02127B08: ; 0x02127B08
	ldr r0, _02127B1C ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	bx lr
	.align 2, 0
_02127B1C: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127B08

	arm_func_start ov11_02127B20
ov11_02127B20: ; 0x02127B20
	ldr r0, _02127B34 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x34c]
	bx lr
	.align 2, 0
_02127B34: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127B20

	arm_func_start ov11_02127B38
ov11_02127B38: ; 0x02127B38
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	add r0, sp, #0
	bl OS_GetMacAddress
	ldr r0, _02127C14 ; =0x027FFC3C
	ldrh r1, [sp]
	ldr ip, [r0]
	ldr r2, _02127C18 ; =OVERLAY11_BSS_02169C44
	add r1, r1, ip
	ldrh r3, [sp, #2]
	ldr r0, [r2]
	ldrh ip, [sp, #4]
	add r1, r3, r1
	add r0, r0, #0x1000
	add r1, ip, r1
	str r1, [r0, #0x354]
	ldr r1, [r2]
	ldr r0, _02127C1C ; =0x00010DCD
	add r1, r1, #0x1000
	ldr r3, [r1, #0x354]
	mov ip, #0
	mul r0, r3, r0
	add r0, r0, #0x39
	add r0, r0, #0x3000
	str r0, [r1, #0x354]
	ldr r0, [r2]
	mov r3, #0x65
	add r0, r0, #0x1300
	strh ip, [r0, #0x58]
	ldr r1, [r2]
	mov r0, #3
	add r1, r1, #0x1300
	strh r3, [r1, #0x5a]
	bl ov11_021272F8
	mov r0, #1
	bl ov11_02127C20
	cmp r0, #0x18
	bne _02127BEC
	mov r0, #0x18
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	add sp, sp, #8
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127B38
_02127BEC:
	cmp r0, #2
	addeq sp, sp, #8
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127C14: .word 0x027FFC3C
_02127C18: .word OVERLAY11_BSS_02169C44
_02127C1C: .word 0x00010DCD

	arm_func_start ov11_02127C20
ov11_02127C20: ; 0x02127C20
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl WM_GetAllowedChannel
	cmp r0, #0x8000
	bne _02127C4C
	mov r0, #3
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	mov r0, #3
	ldmia sp!, {r4, pc}
	arm_func_end ov11_02127C20
_02127C4C:
	cmp r0, #0
	bne _02127C6C
	mov r0, #0x16
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	mov r0, #0x18
	ldmia sp!, {r4, pc}
_02127C6C:
	sub r1, r4, #1
	mov r2, #1
	tst r0, r2, lsl r1
	bne _02127CA0
_02127C7C:
	add r1, r4, #1
	mov r1, r1, lsl #0x10
	mov r4, r1, lsr #0x10
	cmp r4, #0x10
	movhi r0, #0x18
	ldmhiia sp!, {r4, pc}
	sub r1, r4, #1
	tst r0, r2, lsl r1
	beq _02127C7C
_02127CA0:
	ldr r0, _02127CB8 ; =ov11_02127CBC
	mov r1, r4
	bl ov11_02127D7C
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	ldmia sp!, {r4, pc}
	.align 2, 0
_02127CB8: .word ov11_02127CBC

	arm_func_start ov11_02127CBC
ov11_02127CBC: ; 0x02127CBC
	stmdb sp!, {r3, lr}
	ldrh r1, [r0, #2]
	cmp r1, #0
	beq _02127CE0
	mov r0, r1
	bl ov11_02127310
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127CBC
_02127CE0:
	ldr r3, _02127D78 ; =OVERLAY11_BSS_02169C44
	ldrh lr, [r0, #0xa]
	ldr r1, [r3]
	ldrh r0, [r0, #8]
	add r2, r1, #0x1300
	ldrh ip, [r2, #0x5a]
	add r1, r1, #0x5a
	add r1, r1, #0x1300
	cmp ip, lr
	bls _02127D28
	strh lr, [r1]
	ldr r1, [r3]
	sub r2, r0, #1
	mov r3, #1
	mov r2, r3, lsl r2
	add r1, r1, #0x1300
	strh r2, [r1, #0x5c]
	b _02127D40
_02127D28:
	bne _02127D40
	ldrh ip, [r2, #0x5c]
	sub r1, r0, #1
	mov r3, #1
	orr r1, ip, r3, lsl r1
	strh r1, [r2, #0x5c]
_02127D40:
	add r0, r0, #1
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_02127C20
	cmp r0, #0x18
	bne _02127D64
	mov r0, #7
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
_02127D64:
	cmp r0, #2
	ldmeqia sp!, {r3, pc}
	mov r0, #9
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127D78: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_02127D7C
ov11_02127D7C: ; 0x02127D7C
	stmdb sp!, {r3, lr}
	mov r3, r1
	mov ip, #0x1e
	mov r1, #3
	mov r2, #0x11
	str ip, [sp]
	bl WM_MeasureChannel
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127D7C

	arm_func_start ov11_02127D9C
ov11_02127D9C: ; 0x02127D9C
	stmdb sp!, {r3, lr}
	mov r0, #1
	bl ov11_021272F8
	ldr r0, _02127DDC ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1300
	ldrh r0, [r0, #0x5c]
	bl ov11_02127DE0
	ldr r2, _02127DDC ; =OVERLAY11_BSS_02169C44
	ldr r1, [r2]
	add r1, r1, #0x1300
	strh r0, [r1, #0x58]
	ldr r0, [r2]
	add r0, r0, #0x1300
	ldrh r0, [r0, #0x58]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127DDC: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127D9C

	arm_func_start ov11_02127DE0
ov11_02127DE0: ; 0x02127DE0
	stmdb sp!, {r4, lr}
	mov r3, #0
	mov r1, r3
	mov ip, r3
	mov r4, #1
	arm_func_end ov11_02127DE0
_02127DF4:
	tst r0, r4, lsl ip
	beq _02127E14
	add r3, ip, #1
	add r2, r1, #1
	mov r1, r3, lsl #0x10
	mov r2, r2, lsl #0x10
	mov r3, r1, asr #0x10
	mov r1, r2, lsr #0x10
_02127E14:
	add r2, ip, #1
	mov r2, r2, lsl #0x10
	mov ip, r2, asr #0x10
	cmp ip, #0x10
	blt _02127DF4
	cmp r1, #1
	movls r0, r3
	ldmlsia sp!, {r4, pc}
	ldr lr, _02127EC8 ; =OVERLAY11_BSS_02169C44
	ldr r3, _02127ECC ; =0x00010DCD
	ldr r4, [lr]
	mov r2, #0
	add ip, r4, #0x1000
	ldr r4, [ip, #0x354]
	mul r3, r4, r3
	add r3, r3, #0x39
	add r3, r3, #0x3000
	str r3, [ip, #0x354]
	ldr r3, [lr]
	add r3, r3, #0x1000
	ldr r3, [r3, #0x354]
	and r3, r3, #0xff
	mul r3, r1, r3
	mov r1, r3, lsl #8
	mov r3, r1, lsr #0x10
_02127E78:
	tst r0, #1
	beq _02127EA4
	cmp r3, #0
	bne _02127E98
	add r0, r2, #1
	mov r0, r0, lsl #0x10
	mov r0, r0, asr #0x10
	ldmia sp!, {r4, pc}
_02127E98:
	sub r1, r3, #1
	mov r1, r1, lsl #0x10
	mov r3, r1, lsr #0x10
_02127EA4:
	add r1, r2, #1
	mov r1, r1, lsl #0x10
	mov r0, r0, lsl #0xf
	mov r2, r1, asr #0x10
	cmp r2, #0x10
	mov r0, r0, lsr #0x10
	blt _02127E78
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02127EC8: .word OVERLAY11_BSS_02169C44
_02127ECC: .word 0x00010DCD

	arm_func_start ov11_02127ED0
ov11_02127ED0: ; 0x02127ED0
	stmdb sp!, {r3, lr}
	ldr r0, _02127F9C ; =0x00001364
	mov r1, #0x20
	bl _Z23Heap_AllocWithAlignmentmm
	ldr r1, _02127FA0 ; =OVERLAY11_BSS_02169C44
	add r2, r0, #0x1000
	str r0, [r1]
	mov r0, #0
	str r0, [r2, #0x328]
	ldr r2, [r1]
	mov ip, #1
	add r2, r2, #0x1000
	str r0, [r2, #0x324]
	ldr r2, [r1]
	mov r3, #8
	add r2, r2, #0x1000
	str r0, [r2, #0x338]
	ldr r2, [r1]
	add r2, r2, #0x1300
	strh r0, [r2, #0x48]
	ldr r2, [r1]
	add r2, r2, #0x1300
	strh ip, [r2, #0x4a]
	ldr r2, [r1]
	add r2, r2, #0x1000
	str r0, [r2, #0x34c]
	ldr r2, [r1]
	add r2, r2, #0x1000
	str r0, [r2, #0x330]
	ldr r2, [r1]
	str r0, [r2, #0xf20]
	ldr r2, [r1]
	add r2, r2, #0xf00
	strh r0, [r2, #0x24]
	ldr r2, [r1]
	add r2, r2, #0x1000
	str r0, [r2, #0x33c]
	ldr r2, [r1]
	add r2, r2, #0x1000
	strb r3, [r2, #0x350]
	ldr r2, [r1]
	add r2, r2, #0x1000
	strb r0, [r2, #0x351]
	ldr r1, [r1]
	add r1, r1, #0x1000
	strb r0, [r1, #0x35e]
	bl ov11_02127FD4
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02127F9C: .word 0x00001364
_02127FA0: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02127ED0

	arm_func_start ov11_02127FA4
ov11_02127FA4: ; 0x02127FA4
	ldr r0, _02127FAC ; =0x00001384
	bx lr
	.align 2, 0
_02127FAC: .word 0x00001384
	arm_func_end ov11_02127FA4

	arm_func_start ov11_02127FB0
ov11_02127FB0: ; 0x02127FB0
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #8
	ldmneia sp!, {r3, pc}
	mov r0, #9
	bl ov11_021272F8
	mov r0, #0x19
	bl ov11_02127310
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02127FB0

	arm_func_start ov11_02127FD4
ov11_02127FD4: ; 0x02127FD4
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_021272F8
	ldr r0, _02128014 ; =OVERLAY11_BSS_02169C44
	ldr r1, _02128018 ; =ov11_0212801C
	ldr r0, [r0]
	mov r2, #2
	bl WM_Initialize
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_02127310
	mov r0, #0xa
	bl ov11_021272F8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128014: .word OVERLAY11_BSS_02169C44
_02128018: .word ov11_0212801C
	arm_func_end ov11_02127FD4

	arm_func_start ov11_0212801C
ov11_0212801C: ; 0x0212801C
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0212803C
	bl ov11_02127310
	mov r0, #0xa
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212801C
_0212803C:
	ldr r0, _02128068 ; =ov11_02127FB0
	bl WM_SetIndCallback
	cmp r0, #0
	beq _0212805C
	bl ov11_02127310
	mov r0, #0xa
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
_0212805C:
	mov r0, #1
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128068: .word ov11_02127FB0

	arm_func_start ov11_0212806C
ov11_0212806C: ; 0x0212806C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r4, _021281C8 ; =OVERLAY11_BSS_02169C44
	mov r7, r0
	ldr r0, [r4]
	mov r5, #0x1c0
	add r0, r0, #0x1000
	str r5, [r0, #0x328]
	ldr r0, [r4]
	mov r5, #0xe0
	add r0, r0, #0x1000
	str r5, [r0, #0x324]
	ldr r4, [r4]
	mov r0, #3
	add ip, r4, #0x1000
	mov r6, r1
	mov r5, r2
	mov r4, r3
	str r7, [ip, #0x334]
	bl ov11_021272F8
	ldr r1, _021281C8 ; =OVERLAY11_BSS_02169C44
	ldrh r2, [sp, #0x18]
	ldr r0, [r1]
	cmp r7, #0
	add r0, r0, #0xf00
	strh r6, [r0, #0x2c]
	ldr r0, [r1]
	add r0, r0, #0xf00
	strh r5, [r0, #0x52]
	ldr r0, [r1]
	add r0, r0, #0xf00
	strh r2, [r0, #0x38]
	beq _021280F8
	cmp r7, #4
	beq _02128134
	b _02128154
	arm_func_end ov11_0212806C
_021280F8:
	ldr r0, [r1]
	mov r2, #0xc0
	add r0, r0, #0xf00
	strh r2, [r0, #0x54]
	cmp r4, #5
	ldr r0, [r1]
	blo _02128124
	mov r1, #0xc
	add r0, r0, #0xf00
	strh r1, [r0, #0x56]
	b _02128154
_02128124:
	mov r1, #0x26
	add r0, r0, #0xf00
	strh r1, [r0, #0x56]
	b _02128154
_02128134:
	ldr r0, [r1]
	mov r2, #0x64
	add r0, r0, #0xf00
	strh r2, [r0, #0x54]
	ldr r0, [r1]
	mov r1, #0xc
	add r0, r0, #0xf00
	strh r1, [r0, #0x56]
_02128154:
	ldr r2, _021281C8 ; =OVERLAY11_BSS_02169C44
	mov r0, #0
	ldr r1, [r2]
	ldr r3, [sp, #0x1c]
	add r1, r1, #0xf00
	strh r4, [r1, #0x30]
	ldr r1, [r2]
	cmp r7, #2
	add r1, r1, #0xf00
	strh r0, [r1, #0x36]
	ldr r1, [r2]
	add r1, r1, #0xf00
	strh r0, [r1, #0x32]
	ldr r1, [r2]
	moveq r0, #1
	add r1, r1, #0xf00
	strh r3, [r1, #0x2e]
	ldr r1, _021281C8 ; =OVERLAY11_BSS_02169C44
	cmp r7, #0
	ldr r1, [r1]
	cmpne r7, #2
	add r1, r1, #0xf00
	strh r0, [r1, #0x34]
	cmpne r7, #4
	bne _021281C0
	bl ov11_02127334
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_021281C0:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_021281C8: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_021281CC
ov11_021281CC: ; 0x021281CC
	stmdb sp!, {r3, lr}
	ldr r2, _0212820C ; =OVERLAY11_BSS_02169C44
	mov r3, r1, lsl #0x10
	ldr r2, [r2]
	ldr r1, _02128210 ; =ov11_021279C4
	add r2, r2, #0x1000
	str r0, [r2, #0x338]
	mov r0, r3, lsr #0x10
	mov r2, #0
	bl WM_SetPortCallback
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	mov r0, #9
	bl ov11_021272F8
	arm_func_end ov11_021281CC
_02128204:
	b _02128204
_02128208:
	.byte 0x08, 0x80, 0xBD, 0xE8
_0212820C: .word OVERLAY11_BSS_02169C44
_02128210: .word ov11_021279C4

	arm_func_start thunk_FUN_overlay_11__02127904
thunk_FUN_overlay_11__02127904: ; 0x02128214
	ldr ip, _0212821C ; =ov11_02127904
	bx ip
	.align 2, 0
_0212821C: .word ov11_02127904
	arm_func_end thunk_FUN_overlay_11__02127904

	arm_func_start ov11_02128220
ov11_02128220: ; 0x02128220
	stmdb sp!, {r3, lr}
	ldr r0, _02128258 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	cmp r0, #2
	bne _02128240
	arm_func_end ov11_02128220
_0212823C:
	b _0212823C
_02128240:
	bl ov11_021278A0
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	mov r0, #0xa
	bl ov11_021272F8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128258: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_0212825C
ov11_0212825C: ; 0x0212825C
	stmdb sp!, {r3, lr}
	ldr r0, _021282F8 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	cmp r0, #1
	ldmeqia sp!, {r3, pc}
	cmp r0, #6
	cmpne r0, #5
	cmpne r0, #4
	mov r0, #3
	beq _02128298
	bl ov11_021272F8
	bl ov11_02128220
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212825C
_02128298:
	bl ov11_021272F8
	ldr r0, _021282F8 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x334]
	cmp r0, #5
	addls pc, pc, r0, lsl #2
	ldmia sp!, {r3, pc}
_021282B8: ; jump table
	b _021282E4 ; case 0
	b _021282D0 ; case 1
	ldmia sp!, {r3, pc} ; case 2
	ldmia sp!, {r3, pc} ; case 3
	b _021282E4 ; case 4
	b _021282D0 ; case 5
_021282D0:
	bl ov11_021277E0
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	bl ov11_02128220
	ldmia sp!, {r3, pc}
_021282E4:
	bl ov11_02127700
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	bl ov11_02128220
	ldmia sp!, {r3, pc}
	.align 2, 0
_021282F8: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_021282FC
ov11_021282FC: ; 0x021282FC
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_021272F8
	ldr r0, _0212832C ; =ov11_02127A3C
	bl WM_End
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	mov r0, #9
	bl ov11_021272F8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212832C: .word ov11_02127A3C
	arm_func_end ov11_021282FC

	arm_func_start ov11_02128330
ov11_02128330: ; 0x02128330
	ldr r0, _02128344 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1300
	ldrh r0, [r0, #0x48]
	bx lr
	.align 2, 0
_02128344: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02128330

	arm_func_start ov11_02128348
ov11_02128348: ; 0x02128348
	ldr r0, _02128368 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	bx lr
	.align 2, 0
_02128368: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02128348

	arm_func_start ov11_0212836C
ov11_0212836C: ; 0x0212836C
	ldr r0, _0212838C ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	cmp r0, #3
	moveq r0, #1
	movne r0, #0
	bx lr
	.align 2, 0
_0212838C: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_0212836C

	arm_func_start ov11_02128390
ov11_02128390: ; 0x02128390
	ldr r0, _021283B0 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	cmp r0, #9
	moveq r0, #1
	movne r0, #0
	bx lr
	.align 2, 0
_021283B0: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02128390

	arm_func_start ov11_021283B4
ov11_021283B4: ; 0x021283B4
	ldr r0, _021283E4 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	cmp r0, #0
	beq _021283DC
	add r0, r0, #0x1000
	ldr r0, [r0, #0x330]
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	bx lr
	arm_func_end ov11_021283B4
_021283DC:
	mov r0, #0
	bx lr
	.align 2, 0
_021283E4: .word OVERLAY11_BSS_02169C44

	arm_func_start ov11_021283E8
ov11_021283E8: ; 0x021283E8
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	ldr ip, _02128440 ; =OVERLAY11_BSS_02169C44
	ldr ip, [ip]
	add ip, ip, #0x1000
	ldr ip, [ip, #0x330]
	cmp ip, #4
	addne sp, sp, #8
	ldmneia sp!, {r3, pc}
	mov r3, r3, lsl #0x10
	mov lr, r3, lsr #0x10
	mov ip, r1, lsl #0x10
	mov r1, r0
	mov r3, r2
	str lr, [sp]
	mov lr, #1
	mov r2, ip, lsr #0x10
	mov r0, #0
	str lr, [sp, #4]
	bl WM_SetGameInfo
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128440: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_021283E8

	arm_func_start ov11_02128444
ov11_02128444: ; 0x02128444
	ldr r0, _0212845C ; =OVERLAY11_BSS_02169C44
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	strb r1, [r0, #0x361]
	bx lr
	.align 2, 0
_0212845C: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02128444

	arm_func_start ov11_02128460
ov11_02128460: ; 0x02128460
	ldr r0, _02128474 ; =OVERLAY11_BSS_02169C44
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldrb r0, [r0, #0x35e]
	bx lr
	.align 2, 0
_02128474: .word OVERLAY11_BSS_02169C44
	arm_func_end ov11_02128460

	arm_func_start ov11_02128478
ov11_02128478: ; 0x02128478
	stmdb sp!, {r4, lr}
	ldr r1, _021284D8 ; =OVERLAY11_BSS_02169C4C
	mov r4, r0
	ldr r1, [r1]
	cmp r1, #0
	ldmneia sp!, {r4, pc}
	bl ov11_0212CDF4
	mov r0, #0x3d0
	bl _Z10Heap_Allocm
	ldr r3, _021284D8 ; =OVERLAY11_BSS_02169C4C
	mov r1, #0
	mov r2, #0x3d0
	str r0, [r3]
	bl MI_CpuFill8
	ldr r0, _021284D8 ; =OVERLAY11_BSS_02169C4C
	mov r2, #0x32
	ldr r1, [r0]
	strh r2, [r1, #0x20]
	ldr r1, [r0]
	str r4, [r1]
	ldr r0, [r0]
	add r0, r0, #4
	bl ov11_0212C21C
	ldmia sp!, {r4, pc}
	.align 2, 0
_021284D8: .word OVERLAY11_BSS_02169C4C
	arm_func_end ov11_02128478

	arm_func_start ov11_021284DC
ov11_021284DC: ; 0x021284DC
	ldr r2, _021284F4 ; =OVERLAY11_BSS_02169C4C
	ldr r3, [r2]
	str r0, [r3, #0x1c]
	ldr r0, [r2]
	strh r1, [r0, #0x20]
	bx lr
	.align 2, 0
_021284F4: .word OVERLAY11_BSS_02169C4C
	arm_func_end ov11_021284DC

	arm_func_start ov11_021284F8
ov11_021284F8: ; 0x021284F8
	stmdb sp!, {r3, lr}
	bl ov11_0212C154
	bl ov11_0212BEA0
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	mov r3, #0
	ldr r0, _02128544 ; =OVERLAY11_BSS_02169C4C
	mov r2, r3
	arm_func_end ov11_021284F8
_02128518:
	ldr r1, [r0]
	add r1, r1, r3
	add r3, r3, #1
	strb r2, [r1, #0x3bd]
	cmp r3, #0x10
	blt _02128518
	bl ov11_021287A8
	ldr r0, _02128548 ; =ov11_0212854C
	mov r1, #0
	bl ov11_021284DC
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128544: .word OVERLAY11_BSS_02169C4C
_02128548: .word ov11_0212854C

	arm_func_start ov11_0212854C
ov11_0212854C: ; 0x0212854C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r4, _021285A8 ; =OVERLAY11_BSS_02169C4C
	mov r5, #0
	arm_func_end ov11_0212854C
_02128558:
	ldr r0, [r4]
	add r0, r0, r5, lsl #2
	ldr r0, [r0, #0x24]
	cmp r0, #0
	bne _02128590
	mov r0, r5
	bl ov11_0212BEA0
	cmp r0, #1
	bne _02128590
	mov r0, r5
	bl ov11_02128A30
	ldr r1, [r4]
	add r1, r1, r5, lsl #2
	str r0, [r1, #0x24]
_02128590:
	add r0, r5, #1
	mov r0, r0, lsl #0x10
	mov r5, r0, lsr #0x10
	cmp r5, #0x10
	blo _02128558
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021285A8: .word OVERLAY11_BSS_02169C4C

	arm_func_start ov11_021285AC
ov11_021285AC: ; 0x021285AC
	stmdb sp!, {r3, lr}
	ldr r0, _021285DC ; =OVERLAY11_BSS_02169C4C
	ldr r0, [r0]
	cmp r0, #0
	ldrne r1, [r0, #0x1c]
	cmpne r1, #0
	ldmeqia sp!, {r3, pc}
	ldrb r0, [r0, #0x22]
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	blx r1
	ldmia sp!, {r3, pc}
	.align 2, 0
_021285DC: .word OVERLAY11_BSS_02169C4C
	arm_func_end ov11_021285AC

	arm_func_start ov11_021285E0
ov11_021285E0: ; 0x021285E0
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl ov11_0212BF7C
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	mov r0, r4
	bl ov11_02128B9C
	mov r0, r5
	bl ov11_02128478
	ldr r0, _02128618 ; =ov11_021284F8
	mov r1, #0
	bl ov11_021284DC
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02128618: .word ov11_021284F8
	arm_func_end ov11_021285E0

	arm_func_start ov11_0212861C
ov11_0212861C: ; 0x0212861C
	ldr ip, _02128630 ; =ov11_0212B9CC
	mov r2, r1
	mov r1, r0
	mov r0, #0x16
	bx ip
	.align 2, 0
_02128630: .word ov11_0212B9CC
	arm_func_end ov11_0212861C

	arm_func_start ov11_02128634
ov11_02128634: ; 0x02128634
	ldr r1, _02128650 ; =OVERLAY11_BSS_02169C4C
	ldr r2, [r1]
	ldrb r1, [r2, #0x23]
	cmp r1, r0
	moveq r0, #1
	streqb r0, [r2, #0x3bc]
	bx lr
	.align 2, 0
_02128650: .word OVERLAY11_BSS_02169C4C
	arm_func_end ov11_02128634

	arm_func_start ov11_02128654
ov11_02128654: ; 0x02128654
	mov r0, #0x358
	bx lr
	arm_func_end ov11_02128654

	arm_func_start ov11_0212865C
ov11_0212865C: ; 0x0212865C
	ldr r0, _0212866C ; =OVERLAY11_BSS_02169C4C
	ldr r0, [r0]
	add r0, r0, #0x64
	bx lr
	.align 2, 0
_0212866C: .word OVERLAY11_BSS_02169C4C
	arm_func_end ov11_0212865C

	arm_func_start ov11_02128670
ov11_02128670: ; 0x02128670
	ldr r1, _02128688 ; =OVERLAY11_BSS_02169C4C
	mov r2, #1
	ldr r1, [r1]
	add r0, r1, r0
	strb r2, [r0, #0x3bd]
	bx lr
	.align 2, 0
_02128688: .word OVERLAY11_BSS_02169C4C
	arm_func_end ov11_02128670

	arm_func_start ov11_0212868C
ov11_0212868C: ; 0x0212868C
	stmdb sp!, {r3, lr}
	ldr r0, _021286B8 ; =OVERLAY11_BSS_02169C4C
	ldr r0, [r0]
	cmp r0, #0
	beq _021286A4
	bl _Z9Heap_FreePv
	arm_func_end ov11_0212868C
_021286A4:
	ldr r0, _021286B8 ; =OVERLAY11_BSS_02169C4C
	mov r1, #0
	str r1, [r0]
	bl ov11_02128BDC
	ldmia sp!, {r3, pc}
	.align 2, 0
_021286B8: .word OVERLAY11_BSS_02169C4C

	arm_func_start ov11_021286BC
ov11_021286BC: ; 0x021286BC
	stmdb sp!, {r4, r5, r6, lr}
	ldr r0, _02128748 ; =OVERLAY11_BSS_02169C50
	ldr r0, [r0]
	cmp r0, #0
	ldmneia sp!, {r4, r5, r6, pc}
	mov r0, #0x39c
	bl _Z10Heap_Allocm
	ldr r3, _02128748 ; =OVERLAY11_BSS_02169C50
	mov r1, #0
	mov r2, #0x39c
	str r0, [r3]
	bl MI_CpuFill8
	mov r5, #0
	ldr r4, _02128748 ; =OVERLAY11_BSS_02169C50
	mov r6, r5
	arm_func_end ov11_021286BC
_021286F8:
	ldr r3, [r4]
	mov r0, r5
	add r1, r3, r6
	add r2, r1, #0x20
	add r1, r3, r5, lsl #2
	str r2, [r1, #0x340]
	bl ov11_02128974
	add r5, r5, #1
	cmp r5, #8
	add r6, r6, #0x68
	blt _021286F8
	ldr r0, _02128748 ; =OVERLAY11_BSS_02169C50
	mov r2, #0
	ldr r1, [r0]
	strb r2, [r1, #0x398]
	ldr r1, [r0]
	strb r2, [r1, #0x399]
	ldr r0, [r0]
	strb r2, [r0, #0x39a]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02128748: .word OVERLAY11_BSS_02169C50

	arm_func_start ov11_0212874C
ov11_0212874C: ; 0x0212874C
	stmdb sp!, {r3, lr}
	ldr r0, _021287A4 ; =OVERLAY11_BSS_02169C50
	ldr r1, [r0]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	mov r3, #0
	mov r2, r3
	arm_func_end ov11_0212874C
_02128768:
	ldr r1, [r0]
	add r1, r1, r3, lsl #2
	add r3, r3, #1
	str r2, [r1, #0x340]
	cmp r3, #8
	blt _02128768
	ldr r0, _021287A4 ; =OVERLAY11_BSS_02169C50
	ldr r0, [r0]
	cmp r0, #0
	beq _02128794
	bl _Z9Heap_FreePv
_02128794:
	ldr r0, _021287A4 ; =OVERLAY11_BSS_02169C50
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_021287A4: .word OVERLAY11_BSS_02169C50

	arm_func_start ov11_021287A8
ov11_021287A8: ; 0x021287A8
	stmdb sp!, {r4, lr}
	bl ov11_0212C154
	mov r1, #0x68
	ldr r2, _021287E8 ; =OVERLAY11_BSS_02169C50
	mul r4, r0, r1
	ldr r0, [r2]
	add r0, r0, r4
	add r0, r0, #0x5c
	bl OS_GetMacAddress
	ldr r1, _021287E8 ; =OVERLAY11_BSS_02169C50
	mov r0, #3
	ldr r1, [r1]
	mov r2, #0x68
	add r1, r1, r4
	bl ov11_0212B938
	ldmia sp!, {r4, pc}
	.align 2, 0
_021287E8: .word OVERLAY11_BSS_02169C50
	arm_func_end ov11_021287A8

	arm_func_start ov11_021287EC
ov11_021287EC: ; 0x021287EC
	mov r0, #0x68
	bx lr
	arm_func_end ov11_021287EC

	arm_func_start ov11_021287F4
ov11_021287F4: ; 0x021287F4
	ldr r0, _0212880C ; =0x02169C50
	ldr r1, [r0]
	cmp r1, #0
	movne r0, #1
	strneb r0, [r1, #0x398]
	bx lr
	.align 2, 0
	arm_func_end ov11_021287F4
_0212880C: .word OVERLAY11_BSS_02169C50

	arm_func_start ov11_02128810
ov11_02128810: ; 0x02128810
	stmdb sp!, {r4, lr}
	ldr r1, _021288B8 ; =0x02169C50
	mov r4, r2
	ldr ip, [r1]
	cmp ip, #0
	ldmeqia sp!, {r4, pc}
	ldrb r1, [r4, #0x39]
	cmp r1, #2
	beq _02128848
    mov r0, r0, lsl #0x10
    mov r1, r0, lsr #0x10
	mov r0, #0
	bl WM_Disconnect
	ldmia sp!, {r4, pc}
	arm_func_end ov11_02128810
_02128848:
	ldrb r3, [r4, #0x62]
	mov r2, #0x68
	mov r0, r4
	mla r1, r3, r2, ip
	bl MI_CpuCopy8
	ldr r0, _021288B8 ; =0x02169C50
	ldrb r2, [r4, #0x62]
	ldr r1, [r0]
	strb r2, [r1, #0x39a]
	ldr r1, [r0]
	ldrb r2, [r1, #0x39a]
	add r3, r1, #0x390
	ldrb r1, [r3, r2]
	cmp r1, #2
	ldmhsia sp!, {r4, pc}
	mov r1, #1
	strb r1, [r3, r2]
	ldr r0, [r0]
	ldrb r4, [r0, #0x39a]
	bl ov11_0212C154
	cmp r4, r0
	ldmneia sp!, {r4, pc}
	ldr r0, _021288B8 ; =0x02169C50
	mov r1, #3
	ldr r0, [r0]
	add r0, r0, r4
	strb r1, [r0, #0x390]
	ldmia sp!, {r4, pc}
	.align 2, 0
_021288B8: .word OVERLAY11_BSS_02169C50

	arm_func_start ov11_021288BC
ov11_021288BC: ; 0x021288BC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02128970 ; =0x02169C50
	mov r4, r0
	ldr r3, [r1]
	cmp r3, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldrb r0, [r2, #0x39]
	cmp r0, #2
	beq _021288F4
    mov r0, r4, lsl #0x10
    mov r1, r0, lsr #0x10
	mov r0, #0
	bl WM_Disconnect
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov11_021288BC
_021288F4:
	mov r1, #0x68
	mul r5, r4, r1
	mov r0, r2
	mov r2, r1
	add r1, r3, r5
	bl MI_CpuCopy8
	ldr r0, _02128970 ; =0x02169C50
	mov r1, r4
	ldr r0, [r0]
	add r0, r0, r5
	add r0, r0, #0x5c
	bl ov11_02129800
	ldr r0, _02128970 ; =0x02169C50
	mov r1, #1
	ldr r0, [r0]
	add r0, r0, r4
	strb r1, [r0, #0x390]
	bl ov11_0212C154
	cmp r4, r0
	bne _0212895C
	ldr r0, _02128970 ; =0x02169C50
	mov r1, #3
	ldr r0, [r0]
	add r0, r0, r4
	strb r1, [r0, #0x390]
	ldmia sp!, {r3, r4, r5, pc}
_0212895C:
	ldr r0, _02128970 ; =0x02169C50
	mov r1, #1
	ldr r0, [r0]
	strb r1, [r0, #0x399]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02128970: .word OVERLAY11_BSS_02169C50

	arm_func_start ov11_02128974
ov11_02128974: ; 0x02128974
	stmdb sp!, {r4, lr}
	ldr r1, _021289A8 ; =OVERLAY11_BSS_02169C50
	mov r4, r0
	ldr r0, [r1]
	add r0, r0, r4, lsl #2
	ldr r0, [r0, #0x340]
	bl ov11_02128A74
	ldr r0, _021289A8 ; =OVERLAY11_BSS_02169C50
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, r4
	strb r1, [r0, #0x390]
	ldmia sp!, {r4, pc}
	.align 2, 0
_021289A8: .word OVERLAY11_BSS_02169C50
	arm_func_end ov11_02128974

	arm_func_start ov11_021289AC
ov11_021289AC: ; 0x021289AC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r0, _02128A2C ; =OVERLAY11_BSS_02169C50
	ldr r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	bl ov11_0212BF48
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r4, _02128A2C ; =OVERLAY11_BSS_02169C50
	mov r5, #0
	arm_func_end ov11_021289AC
_021289D4:
	mov r0, r5
	bl ov11_0212BEA0
	cmp r0, #0
	bne _02128A14
	cmp r5, #0
	bne _021289F8
	bl ov11_0212C1D0
	cmp r0, #0
	bne _02128A14
_021289F8:
	ldr r0, [r4]
	add r0, r0, r5
	ldrb r0, [r0, #0x390]
	cmp r0, #0
	beq _02128A14
	mov r0, r5
	bl ov11_02128974
_02128A14:
	add r0, r5, #1
	mov r0, r0, lsl #0x10
	mov r5, r0, lsr #0x10
	cmp r5, #8
	blo _021289D4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02128A2C: .word OVERLAY11_BSS_02169C50

	arm_func_start ov11_02128A30
ov11_02128A30: ; 0x02128A30
	ldr r1, _02128A70 ; =OVERLAY11_BSS_02169C50
	ldr r2, [r1]
	cmp r2, #0
	moveq r0, #0
	bxeq lr
	add r1, r2, r0
	ldrb r1, [r1, #0x390]
	cmp r1, #1
	cmpne r1, #2
	cmpne r1, #3
	bne _02128A68
	add r0, r2, r0, lsl #2
	ldr r0, [r0, #0x340]
	bx lr
	arm_func_end ov11_02128A30
_02128A68:
	mov r0, #0
	bx lr
	.align 2, 0
_02128A70: .word OVERLAY11_BSS_02169C50

	arm_func_start ov11_02128A74
ov11_02128A74: ; 0x02128A74
	stmdb sp!, {r4, lr}
	mov r1, #0
	mov r2, #0x20
	mov r4, r0
	bl memset
	mov r0, #2
	strb r0, [r4, #0x19]
	ldmia sp!, {r4, pc}
	arm_func_end ov11_02128A74

	arm_func_start ov11_02128A94
ov11_02128A94: ; 0x02128A94
	stmdb sp!, {r4, lr}
	ldr r1, _02128B38 ; =OVERLAY11_BSS_02169C54
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, #0x44
	bl _Z10Heap_Allocm
	ldr r3, _02128B38 ; =OVERLAY11_BSS_02169C54
	mov r1, #0
	mov r2, #0x44
	str r0, [r3]
	bl MI_CpuFill8
	ldr r0, _02128B38 ; =OVERLAY11_BSS_02169C54
	mov r2, #0x32
	ldr r1, [r0]
	mov r3, #1
	strh r2, [r1, #0x2e]
	ldr r1, [r0]
	ldr r2, _02128B3C ; =DAT_overlay_11_02166464
	strb r3, [r1, #0x37]
	ldr r1, [r0]
	mov r3, #2
	str r2, [r1, #0x24]
	ldr r1, [r0]
	mov r2, #0
	strb r3, [r1, #0x30]
	ldr r1, [r0]
	strb r2, [r1, #0x31]
	ldr r1, [r0]
	strb r2, [r1, #0x3c]
	ldr r1, [r0]
	strb r4, [r1, #0x33]
	ldr r0, [r0]
	add r0, r0, #8
	bl ov11_0212C21C
	mov r0, #0
	mov r1, r0
	mov r2, r0
	bl ov11_0212CA60
	ldmia sp!, {r4, pc}
	.align 2, 0
_02128B38: .word OVERLAY11_BSS_02169C54
_02128B3C: .word DAT_overlay_11_02166464
	arm_func_end ov11_02128A94

	arm_func_start ov11_02128B40
ov11_02128B40: ; 0x02128B40
	stmdb sp!, {r3, lr}
	ldr r0, _02128B7C ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov11_0212CAE0
	ldr r0, _02128B7C ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	cmp r0, #0
	beq _02128B6C
	bl _Z9Heap_FreePv
	arm_func_end ov11_02128B40
_02128B6C:
	ldr r0, _02128B7C ; =OVERLAY11_BSS_02169C54
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128B7C: .word OVERLAY11_BSS_02169C54

	arm_func_start ov11_02128B80
ov11_02128B80: ; 0x02128B80
	ldr r0, _02128B98 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	.align 2, 0
_02128B98: .word OVERLAY11_BSS_02169C54
	arm_func_end ov11_02128B80

	arm_func_start ov11_02128B9C
ov11_02128B9C: ; 0x02128B9C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov11_0212BF7C
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, r4
	bl ov11_02128A94
	ldr r1, _02128BD4 ; =OVERLAY11_BSS_02169C54
	ldr r0, _02128BD8 ; =ov11_02128E84
	ldr r2, [r1]
	mov r1, #0
	strb r4, [r2, #0x33]
	bl ov11_02128C3C
	ldmia sp!, {r4, pc}
	.align 2, 0
_02128BD4: .word OVERLAY11_BSS_02169C54
_02128BD8: .word ov11_02128E84
	arm_func_end ov11_02128B9C

	arm_func_start ov11_02128BDC
ov11_02128BDC: ; 0x02128BDC
	stmdb sp!, {r3, lr}
	ldr r0, _02128C00 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _02128C04 ; =ov11_02128C70
	mov r1, #5
	bl ov11_02128C3C
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128C00: .word OVERLAY11_BSS_02169C54
_02128C04: .word ov11_02128C70
	arm_func_end ov11_02128BDC

	arm_func_start thunk_FUN_overlay_11__02128b40
thunk_FUN_overlay_11__02128b40: ; 0x02128C08
	ldr ip, _02128C10 ; =ov11_02128B40
	bx ip
	.align 2, 0
_02128C10: .word ov11_02128B40
	arm_func_end thunk_FUN_overlay_11__02128b40

	arm_func_start ov11_02128C14
ov11_02128C14: ; 0x02128C14
	stmdb sp!, {r3, lr}
	ldr r0, _02128C38 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	cmp r0, #0
	ldrne r0, [r0, #0x20]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	blx r0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128C38: .word OVERLAY11_BSS_02169C54
	arm_func_end ov11_02128C14

	arm_func_start ov11_02128C3C
ov11_02128C3C: ; 0x02128C3C
	ldr r2, _02128C54 ; =OVERLAY11_BSS_02169C54
	ldr r3, [r2]
	str r0, [r3, #0x20]
	ldr r0, [r2]
	strh r1, [r0, #0x2e]
	bx lr
	.align 2, 0
_02128C54: .word OVERLAY11_BSS_02169C54
	arm_func_end ov11_02128C3C

	arm_func_start ov11_02128C58
ov11_02128C58: ; 0x02128C58
	stmdb sp!, {r3, lr}
	bl ov11_0212BF7C
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	bl ov11_02128B40
	ldmia sp!, {r3, pc}
	arm_func_end ov11_02128C58

	arm_func_start ov11_02128C70
ov11_02128C70: ; 0x02128C70
	stmdb sp!, {r3, lr}
	ldr r0, _02128CC0 ; =OVERLAY11_BSS_02169C54
	ldr r1, [r0]
	ldrh r0, [r1, #0x2e]
	cmp r0, #0
	subne r0, r0, #1
	strneh r0, [r1, #0x2e]
	bl ov11_021291DC
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _02128CC0 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	ldrh r0, [r0, #0x2e]
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	bl ov11_0212A668
	ldr r0, _02128CC4 ; =ov11_02128C58
	mov r1, #0
	bl ov11_02128C3C
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128CC0: .word OVERLAY11_BSS_02169C54
_02128CC4: .word ov11_02128C58
	arm_func_end ov11_02128C70

	arm_func_start ov11_02128CC8
ov11_02128CC8: ; 0x02128CC8
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	mov r5, r2
	bl ov11_0212C154
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	ldr ip, _02128D54 ; =s_FREAK_overlay_11_02166484
	mov r3, #1
	mov r2, #0
	arm_func_end ov11_02128CC8
_02128CEC:
	ldrb r1, [ip]
	ldrb r0, [r5, r2]
	cmp r1, r0
	movne r3, #0
	bne _02128D10
	add r2, r2, #1
	cmp r2, #6
	add ip, ip, #1
	blo _02128CEC
_02128D10:
	cmp r3, #0
	beq _02128D40
	ldr r0, _02128D58 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	ldrb r0, [r0, #0x3c]
	cmp r0, #0
	bne _02128D40
	ldr r1, _02128D5C ; =s_GAME_overlay_11_0216648c
	mov r0, #7
	strb r4, [r1]
	bl ov11_0212BB6C
	ldmia sp!, {r3, r4, r5, pc}
_02128D40:
	ldr r1, _02128D60 ; =s_FULL_overlay_11_02166494
	mov r0, #7
	strb r4, [r1]
	bl ov11_0212BB6C
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02128D54: .word s_FREAK_overlay_11_02166484
_02128D58: .word OVERLAY11_BSS_02169C54
_02128D5C: .word s_GAME_overlay_11_0216648c
_02128D60: .word s_FULL_overlay_11_02166494

	arm_func_start ov11_02128D64
ov11_02128D64: ; 0x02128D64
	stmdb sp!, {r4, lr}
	mov r4, #1
	ldr ip, _02128E24 ; =0x0216648D
	mov r3, r4
	arm_func_end ov11_02128D64
_02128D74:
	ldrb r1, [ip]
	ldrb r0, [r2, r3]
	cmp r1, r0
	movne r4, #0
	bne _02128D98
	add r3, r3, #1
	cmp r3, #6
	add ip, ip, #1
	blo _02128D74
_02128D98:
	cmp r4, #0
	beq _02128DC4
	ldrb r4, [r2]
	bl ov11_0212C154
	cmp r4, r0
	ldmneia sp!, {r4, pc}
	ldr r0, _02128E28 ; =OVERLAY11_BSS_02169C54
	mov r1, #1
	ldr r0, [r0]
	strb r1, [r0, #0x31]
	ldmia sp!, {r4, pc}
_02128DC4:
	mov r4, #1
	ldr r3, _02128E2C ; =0x02166495
	mov ip, r4
_02128DD0:
	ldrb r1, [r3]
	ldrb r0, [r2, ip]
	cmp r1, r0
	movne r4, #0
	bne _02128DF4
	add ip, ip, #1
	cmp ip, #6
	add r3, r3, #1
	blo _02128DD0
_02128DF4:
	cmp r4, #0
	ldmeqia sp!, {r4, pc}
	ldrb r4, [r2]
	bl ov11_0212C154
	and r0, r0, #0xff
	cmp r4, r0
	ldmneia sp!, {r4, pc}
	ldr r0, _02128E28 ; =OVERLAY11_BSS_02169C54
	mov r1, #2
	ldr r0, [r0]
	strb r1, [r0, #0x31]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02128E24: .word s_GAME_overlay_11_0216648c+1
_02128E28: .word OVERLAY11_BSS_02169C54
_02128E2C: .word s_FULL_overlay_11_02166494+1

    arm_func_start ov11_02128E30
ov11_02128E30: ; 0x02128E30
    mov r0, #6
    bx lr
    arm_func_end ov11_02128E30

	arm_func_start ov11_02128E38
ov11_02128E38: ; 0x02128E38
	stmdb sp!, {r3, lr}
	bl ov11_0212C154
	bl ov11_0212BEA0
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _02128E5C ; =ov11_02128E60
	mov r1, #0
	bl ov11_02128C3C
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128E5C: .word ov11_02128E60
	arm_func_end ov11_02128E38

	arm_func_start ov11_02128E60
ov11_02128E60: ; 0x02128E60
	stmdb sp!, {r3, lr}
	bl ov11_0212BF7C
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	ldr r0, _02128E80 ; =ov11_02128C58
	mov r1, #0
	bl ov11_02128C3C
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128E80: .word ov11_02128C58
	arm_func_end ov11_02128E60

	arm_func_start ov11_02128E84
ov11_02128E84: ; 0x02128E84
	stmdb sp!, {r3, lr}
	bl ov11_02129024
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _02128ED8 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	ldr r0, [r0, #0x24]
	bl ov11_02128F1C
	bl ov11_021286BC
	mov r0, #1
	mov r1, r0
	mov r3, r0
	mov r2, #0x200
	bl ov11_0212A524
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov11_0212A630
	ldr r0, _02128EDC ; =ov11_02128E38
	mov r1, #0
	bl ov11_02128C3C
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128ED8: .word OVERLAY11_BSS_02169C54
_02128EDC: .word ov11_02128E38
	arm_func_end ov11_02128E84

	arm_func_start ov11_02128EE0
ov11_02128EE0: ; 0x02128EE0
	ldr r0, _02128EF8 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	cmp r0, #0
	ldrneb r0, [r0, #0x33]
	moveq r0, #1
	bx lr
	.align 2, 0
_02128EF8: .word OVERLAY11_BSS_02169C54
	arm_func_end ov11_02128EE0

	arm_func_start ov11_02128EFC
ov11_02128EFC: ; 0x02128EFC
	ldr r0, _02128F14 ; =OVERLAY11_BSS_02169C54
	ldr r0, [r0]
	cmp r0, #0
	ldrneb r0, [r0, #0x34]
	moveq r0, #0
	bx lr
	.align 2, 0
_02128F14: .word OVERLAY11_BSS_02169C54
	arm_func_end ov11_02128EFC
_02128F18:
	b _02128F18

	arm_func_start ov11_02128F1C
ov11_02128F1C: ; 0x02128F1C
	stmdb sp!, {r4, lr}
	ldr r1, _02128FA8 ; =OVERLAY11_BSS_02169C58
	mov r4, r0
	ldr r0, [r1, #8]
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	ldr r0, _02128FAC ; =0x00000DA4
	mov r1, #0x20
	bl _Z23Heap_AllocWithAlignmentmm
	ldr r3, _02128FA8 ; =OVERLAY11_BSS_02169C58
	ldr r2, _02128FAC ; =0x00000DA4
	mov r1, #0
	str r0, [r3, #8]
	bl MI_CpuFill8
	bl ov11_02127FA4
	mov r1, #0x20
	bl _Z23Heap_AllocWithAlignmentmm
	ldr r1, _02128FA8 ; =OVERLAY11_BSS_02169C58
	ldr r1, [r1, #8]
	str r0, [r1, #0xd84]
	bl ov11_02127FA4
	mov r2, r0
	ldr r0, _02128FA8 ; =OVERLAY11_BSS_02169C58
	mov r1, #0
	ldr r0, [r0, #8]
	ldr r0, [r0, #0xd84]
	bl MI_CpuFill8
	ldr r2, _02128FB0 ; =0x00000333
	ldr r0, _02128FA8 ; =OVERLAY11_BSS_02169C58
	ldr r1, [r0, #8]
	str r2, [r1, #0xd94]
	ldr r0, [r0, #8]
	str r4, [r0, #0xd90]
	bl ov11_02129080
	ldmia sp!, {r4, pc}
	.align 2, 0
_02128FA8: .word OVERLAY11_BSS_02169C58
_02128FAC: .word 0x00000DA4
_02128FB0: .word 0x00000333
	arm_func_end ov11_02128F1C

	arm_func_start ov11_02128FB4
ov11_02128FB4: ; 0x02128FB4
	stmdb sp!, {r3, lr}
	cmp r1, #0
	beq _02128FC4
	bl OS_Terminate
	arm_func_end ov11_02128FB4
_02128FC4:
	ldr r0, _02128FD4 ; =OVERLAY11_BSS_02169C58
	mov r1, #2
	str r1, [r0, #4]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02128FD4: .word OVERLAY11_BSS_02169C58

    arm_func_start ov11_02128FD8
ov11_02128FD8: ; 0x02128FD8
	ldr r0, _02128FE8 ; =0x02169C58
	mov r1, #0
	str r1, [r0, #4]
	bx lr
	.align 2, 0
	arm_func_end ov11_02128FD8
_02128FE8: .word OVERLAY11_BSS_02169C58

	arm_func_start ov11_02128FEC
ov11_02128FEC: ; 0x02128FEC
	stmdb sp!, {r3, lr}
	ldr r3, _0212901C ; =OVERLAY11_BSS_02169C58
	mov ip, #1
	ldr r1, _02129020 ; =ov11_02128FB4
	mov r0, #4
	mov r2, #0
	str ip, [r3, #4]
	bl WVR_StartUpAsync
	cmp r0, #1
	ldmeqia sp!, {r3, pc}
	bl OS_Terminate
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212901C: .word OVERLAY11_BSS_02169C58
_02129020: .word ov11_02128FB4
	arm_func_end ov11_02128FEC

	arm_func_start ov11_02129024
ov11_02129024: ; 0x02129024
	ldr r0, _0212903C ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #4]
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	bx lr
	.align 2, 0
_0212903C: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129024

	arm_func_start ov11_02129040
ov11_02129040: ; 0x02129040
	ldr ip, _02129050 ; =FUN_02046B84
	ldr r0, _02129054 ; =0x02128FD8
	mov r1, #0
	bx ip
	.align 2, 0
_02129050: .word WVR_TerminateAsync
_02129054: .word ov11_02128FD8
	arm_func_end ov11_02129040

	arm_func_start ov11_02129058
ov11_02129058: ; 0x02129058
	ldrh r0, [r0, #4]
	cmp r0, #0x10
	bxne lr
	ldr r0, _0212907C ; =OVERLAY11_BSS_02169C58
	ldr r1, [r0, #8]
	cmp r1, #0
	movne r0, #2
	strne r0, [r1, #0xd88]
	bx lr
	.align 2, 0
_0212907C: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129058

	arm_func_start ov11_02129080
ov11_02129080: ; 0x02129080
	stmdb sp!, {r3, lr}
	ldr r0, _021290B4 ; =OVERLAY11_BSS_02169C58
	mov r1, #0
	ldr r0, [r0, #8]
	str r1, [r0, #0xd88]
	bl ov11_02127ED0
	ldr r0, _021290B8 ; =ov11_02129058
	bl WM_SetIndCallback
	ldr r0, _021290B4 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	ldr r0, [r0, #0xd94]
	bl ov11_02127A70
	ldmia sp!, {r3, pc}
	.align 2, 0
_021290B4: .word OVERLAY11_BSS_02169C58
_021290B8: .word ov11_02129058
	arm_func_end ov11_02129080

	arm_func_start ov11_021290BC
ov11_021290BC: ; 0x021290BC
	ldr r1, _021290E0 ; =OVERLAY11_BSS_02169C58
	and r0, r0, #0xff
	ldr r2, [r1, #8]
	mov r0, r0, lsl #0x1f
	ldrb r1, [r2, #0xda1]
	bic r1, r1, #8
	orr r0, r1, r0, lsr #28
	strb r0, [r2, #0xda1]
	bx lr
	.align 2, 0
_021290E0: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_021290BC

	arm_func_start ov11_021290E4
ov11_021290E4: ; 0x021290E4
	ldr r1, _02129140 ; =OVERLAY11_BSS_02169C58
	mov r0, #0
	ldr r2, [r1, #8]
	strb r0, [r2, #0xd8c]
	ldr r3, [r1, #8]
	ldrb r2, [r3, #0xda1]
	bic r2, r2, #1
	strb r2, [r3, #0xda1]
	ldr r3, [r1, #8]
	ldrb r2, [r3, #0xda1]
	bic r2, r2, #4
	strb r2, [r3, #0xda1]
	ldr r2, [r1, #8]
	strb r0, [r2, #0xd9e]
	ldr r3, [r1, #8]
	ldrb r2, [r3, #0xda1]
	bic r2, r2, #0x10
	strb r2, [r3, #0xda1]
	ldr r2, [r1, #8]
	strb r0, [r2, #0xda0]
	ldr r1, [r1, #8]
	strb r0, [r1, #0xd9f]
	bx lr
	.align 2, 0
_02129140: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_021290E4

	arm_func_start ov11_02129144
ov11_02129144: ; 0x02129144
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r1
	mov r4, r2
	bl ov11_021290E4
	mov r0, r5
	bl ov11_021290BC
	bl ov11_02128444
	ldr r0, _021291D4 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	ldrb r0, [r0, #0xd9f]
	cmp r0, #0
	bne _02129190
	ldr r0, _021291D8 ; =ov11_0212B0C0
	mov r1, #0xe
	bl ov11_021281CC
	ldr r0, _021291D4 ; =OVERLAY11_BSS_02169C58
	mov r1, #1
	ldr r0, [r0, #8]
	strb r1, [r0, #0xd9f]
	arm_func_end ov11_02129144
_02129190:
	ldr r0, _021291D4 ; =OVERLAY11_BSS_02169C58
	and r1, r4, #0xff
	ldr r2, [r0, #8]
	mov r0, r1, lsl #0x1f
	ldrb r1, [r2, #0xda1]
	bic r1, r1, #0x20
	orr r0, r1, r0, lsr #26
	strb r0, [r2, #0xda1]
	bl ov11_02127B08
	cmp r0, #1
	bne _021291CC
	bl ov11_02127B38
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, r4, r5, pc}
_021291CC:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021291D4: .word OVERLAY11_BSS_02169C58
_021291D8: .word ov11_0212B0C0

	arm_func_start ov11_021291DC
ov11_021291DC: ; 0x021291DC
	stmdb sp!, {r3, lr}
	ldr r0, _021292B4 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	cmp r0, #0
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	ldrb r0, [r0, #0xda0]
	cmp r0, #0
	beq _02129214
	cmp r0, #1
	beq _0212925C
	cmp r0, #2
	beq _02129280
	b _021292AC
	arm_func_end ov11_021291DC
_02129214:
	bl ov11_021283B4
	cmp r0, #0
	beq _02129238
	bl ov11_021277AC
	ldr r0, _021292B4 ; =OVERLAY11_BSS_02169C58
	mov r1, #1
	ldr r0, [r0, #8]
	strb r1, [r0, #0xda0]
	b _021292AC
_02129238:
	bl ov11_0212836C
	cmp r0, #0
	bne _021292AC
	bl ov11_0212825C
	ldr r0, _021292B4 ; =OVERLAY11_BSS_02169C58
	mov r1, #2
	ldr r0, [r0, #8]
	strb r1, [r0, #0xda0]
	b _021292AC
_0212925C:
	bl ov11_0212836C
	cmp r0, #0
	bne _021292AC
	bl ov11_0212825C
	ldr r0, _021292B4 ; =OVERLAY11_BSS_02169C58
	mov r1, #2
	ldr r0, [r0, #8]
	strb r1, [r0, #0xda0]
	b _021292AC
_02129280:
	bl ov11_02128348
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, pc}
	bl ov11_02128390
	cmp r0, #0
	beq _021292AC
	ldr r0, _021292B4 ; =OVERLAY11_BSS_02169C58
	mov r1, #1
	ldr r0, [r0, #8]
	strb r1, [r0, #0xda0]
_021292AC:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_021292B4: .word OVERLAY11_BSS_02169C58

	arm_func_start ov11_021292B8
ov11_021292B8: ; 0x021292B8
	stmdb sp!, {r3, lr}
	ldr r0, _021292F4 ; =OVERLAY11_BSS_02169C58
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _021292EC
	ldrb r0, [r1, #0xd9e]
	cmp r0, #0
	bne _021292EC
	mov r0, #1
	strb r0, [r1, #0xd9e]
	bl ov11_0212825C
	mov r0, #1
	ldmia sp!, {r3, pc}
	arm_func_end ov11_021292B8
_021292EC:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_021292F4: .word OVERLAY11_BSS_02169C58

	arm_func_start ov11_021292F8
ov11_021292F8: ; 0x021292F8
	stmdb sp!, {r3, lr}
	ldr r0, _02129348 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	ldr r0, [r0, #0xd84]
	cmp r0, #0
	beq _02129324
	bl _Z9Heap_FreePv
	ldr r0, _02129348 ; =OVERLAY11_BSS_02169C58
	mov r1, #0
	ldr r0, [r0, #8]
	str r1, [r0, #0xd84]
	arm_func_end ov11_021292F8
_02129324:
	ldr r0, _02129348 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02129338
	bl _Z9Heap_FreePv
_02129338:
	ldr r0, _02129348 ; =OVERLAY11_BSS_02169C58
	mov r1, #0
	str r1, [r0, #8]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02129348: .word OVERLAY11_BSS_02169C58

	arm_func_start ov11_0212934C
ov11_0212934C: ; 0x0212934C
	stmdb sp!, {r3, r4, r5, lr}
	bl ov11_02128EE0
	mov r5, r0
	bl ov11_021297EC
	mov r4, r0
	cmp r5, #0xf
	beq _021293A0
	ldr r0, _021293FC ; =OVERLAY11_BSS_02169C58
	ldr r5, [r0, #8]
	bl ov11_0212C2FC
	mov r2, r0
	mov r0, r4
	add r1, r5, #0x10
	bl MI_CpuCopy8
	ldr r0, [r4, #0x10]
	str r0, [r5]
	bl ov11_02128EE0
	strb r0, [r5, #4]
	bl ov11_02128460
	strb r0, [r5, #0x54]
	b _021293D8
	arm_func_end ov11_0212934C
_021293A0:
	ldr r0, _021293FC ; =OVERLAY11_BSS_02169C58
	ldr r1, [r4, #0x10]
	ldr r4, [r0, #8]
	str r1, [r4]
	bl ov11_02128EE0
	strb r0, [r4, #4]
	bl ov11_02128EFC
	ldr r1, _021293FC ; =OVERLAY11_BSS_02169C58
	strb r0, [r4, #5]
	ldr r0, [r1, #8]
	add r1, r4, #8
	add r0, r0, #0xe0
	mov r2, #0x54
	bl MI_CpuCopy8
_021293D8:
	ldr r0, _021293FC ; =OVERLAY11_BSS_02169C58
	mov r1, #0x5c
	ldr r0, [r0, #8]
	bl DC_FlushRange
	ldr r0, _021293FC ; =OVERLAY11_BSS_02169C58
	mov r1, #0x5c
	ldr r0, [r0, #8]
	bl ov11_02127A84
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021293FC: .word OVERLAY11_BSS_02169C58

	arm_func_start ov11_02129400
ov11_02129400: ; 0x02129400
	stmdb sp!, {r4, lr}
	ldr r0, _02129460 ; =OVERLAY11_BSS_02169C58
	ldr r4, [r0, #8]
	bl ov11_02129730
	ldrb r1, [r4, #6]
	cmp r1, r0
	ldmeqia sp!, {r4, pc}
	bl ov11_02129730
	ldr r1, _02129460 ; =OVERLAY11_BSS_02169C58
	strb r0, [r4, #6]
	ldr r0, [r1, #8]
	mov r1, #0x5c
	bl DC_FlushRange
	ldr r0, _02129460 ; =OVERLAY11_BSS_02169C58
	mov r1, #0x5c
	ldr r0, [r0, #8]
	bl ov11_02127A84
	ldr r2, _02129460 ; =OVERLAY11_BSS_02169C58
	mov r1, #0x5c
	ldr r0, [r2, #8]
	ldrh r3, [r2]
	ldr r2, [r0, #0xd94]
	bl ov11_021283E8
	ldmia sp!, {r4, pc}
	.align 2, 0
_02129460: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129400

	arm_func_start ov11_02129464
ov11_02129464: ; 0x02129464
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r5, r0
	bl ov11_02127B08
	mov r4, r0
	bl ov11_021289AC
	bl ov11_02129400
	bl ov11_02128330
	cmp r0, #0
	bne _021294B8
	bl ov11_0212978C
	cmp r0, #0
	bne _021294B8
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r2, [r0, #8]
	ldrb r0, [r2, #0xda1]
	mov r1, r0, lsl #0x1d
	movs r1, r1, lsr #0x1f
	bicne r0, r0, #1
	orrne r0, r0, #1
	strneb r0, [r2, #0xda1]
	arm_func_end ov11_02129464
_021294B8:
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r1, _021296C4 ; =0x0000FFFF
	ldr r0, [r0, #8]
	add r0, r0, #0xd00
	ldrh r2, [r0, #0x9a]
	cmp r2, r1
	streqh r5, [r0, #0x9a]
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r2, [r0, #8]
	ldrb r1, [r2, #0xda1]
	mov r0, r1, lsl #0x1e
	movs r0, r0, lsr #0x1f
	beq _02129504
	add r0, r2, #0xd00
	ldrh r0, [r0, #0x9a]
	cmp r0, r5
	bichi r0, r1, #1
	orrhi r0, r0, #1
	strhib r0, [r2, #0xda1]
_02129504:
	bl ov11_02127B20
	cmp r0, #0x19
	bne _02129518
	mov r0, #0
	bl _02128F18
_02129518:
	cmp r4, #9
	addls pc, pc, r4, lsl #2
	b _021296B8
_02129524: ; jump table
	b _0212954C ; case 0
	b _02129580 ; case 1
	b _021296B8 ; case 2
	b _021296B8 ; case 3
	b _021296B8 ; case 4
	b _021296B8 ; case 5
	b _021296B8 ; case 6
	b _021295F8 ; case 7
	b _021295CC ; case 8
	b _021295CC ; case 9
_0212954C:
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r1, [r0, #8]
	ldrb r0, [r1, #0xd9e]
	cmp r0, #1
	bne _0212956C
	bl ov11_021292F8
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
_0212956C:
	cmp r0, #2
	moveq r0, #3
	streqb r0, [r1, #0xd9e]
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
_02129580:
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	ldrb r0, [r0, #0xd9e]
	cmp r0, #1
	bne _021295A4
	bl ov11_021282FC
	cmp r0, #0
	addne sp, sp, #8
	ldmneia sp!, {r3, r4, r5, pc}
_021295A4:
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	ldrb r0, [r0, #0xd9e]
	cmp r0, #2
	addne sp, sp, #8
	ldmneia sp!, {r3, r4, r5, pc}
	bl ov11_021282FC
	add sp, sp, #8
	cmp r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_021295CC:
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r1, [r0, #8]
	cmp r1, #0
	addeq sp, sp, #8
	ldmeqia sp!, {r3, r4, r5, pc}
	ldrb r0, [r1, #0xda1]
	add sp, sp, #8
	bic r0, r0, #1
	orr r0, r0, #1
	strb r0, [r1, #0xda1]
	ldmia sp!, {r3, r4, r5, pc}
_021295F8:
	bl ov11_02127D9C
	ldr r2, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r3, [r2, #8]
	ldrb r1, [r3, #0xd9d]
	cmp r1, #0
	subne r0, r1, #1
	strneb r0, [r3, #0xd9d]
	bne _0212962C
	add r1, r3, #0xd00
	strh r0, [r1, #0x98]
	ldr r0, [r2, #8]
	mov r1, #5
	strb r1, [r0, #0xd9d]
_0212962C:
	ldr r1, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r1, #8]
	ldrb r2, [r0, #0xda1]
	add r0, r0, #0xd00
	ldrh r4, [r0, #0x98]
	mov r0, r2, lsl #0x1c
	movs r0, r0, lsr #0x1f
	ldrneh r0, [r1]
	addne r0, r0, #1
	strneh r0, [r1]
	bl ov11_0212934C
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	mov r5, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_021297BC
	str r0, [sp]
	ldr r1, _021296C0 ; =OVERLAY11_BSS_02169C58
	mov r3, r5
	ldr r5, [r1, #8]
	mov r0, #0
	ldrb r5, [r5, #0xda1]
	mov r2, r4
	mov r5, r5, lsl #0x1a
	mov r5, r5, lsr #0x1f
	str r5, [sp, #4]
	ldrh r1, [r1]
	bl ov11_0212806C
	ldr r0, _021296C0 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	strb r4, [r0, #0xd9c]
_021296B8:
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021296C0: .word OVERLAY11_BSS_02169C58
_021296C4: .word 0x0000FFFF

	arm_func_start ov11_021296C8
ov11_021296C8: ; 0x021296C8
	stmdb sp!, {r3, lr}
	ldr r1, _021296E4 ; =OVERLAY11_BSS_02169C58
	ldr r1, [r1, #8]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	bl ov11_02129464
	ldmia sp!, {r3, pc}
	.align 2, 0
_021296E4: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_021296C8

	arm_func_start ov11_021296E8
ov11_021296E8: ; 0x021296E8
	stmdb sp!, {r4, lr}
	ldr r1, _0212972C ; =OVERLAY11_BSS_02169C58
	mov r4, r0
	ldr r0, [r1, #8]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	bl ov11_02127B08
	cmp r0, #4
	movne r0, #0
	ldmneia sp!, {r4, pc}
	bl ov11_02127AA4
	mov r1, #1
	tst r0, r1, lsl r4
	moveq r1, #0
	mov r0, r1
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212972C: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_021296E8

	arm_func_start ov11_02129730
ov11_02129730: ; 0x02129730
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, #0
	mov r5, r4
	arm_func_end ov11_02129730
_0212973C:
	mov r0, r5
	bl ov11_021296E8
	cmp r0, #0
	addne r0, r4, #1
	movne r0, r0, lsl #0x10
	movne r4, r0, lsr #0x10
	add r0, r5, #1
	mov r0, r0, lsl #0x10
	mov r5, r0, lsr #0x10
	cmp r5, #8
	blo _0212973C
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov11_02129770
ov11_02129770: ; 0x02129770
	ldr r0, _02129788 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	.align 2, 0
_02129788: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129770

	arm_func_start ov11_0212978C
ov11_0212978C: ; 0x0212978C
	stmdb sp!, {r3, lr}
	ldr r0, _021297B4 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov11_02127AA4
	ldr r1, _021297B8 ; =0x0000FFFE
	and r0, r0, r1
	ldmia sp!, {r3, pc}
	.align 2, 0
_021297B4: .word OVERLAY11_BSS_02169C58
_021297B8: .word 0x0000FFFE
	arm_func_end ov11_0212978C

	arm_func_start ov11_021297BC
ov11_021297BC: ; 0x021297BC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl WM_GetDispersionBeaconPeriod
	cmp r4, #0xa
	moveq r0, r0, lsl #0xe
	moveq r0, r0, lsr #0x10
	ldmeqia sp!, {r4, pc}
	cmp r4, #9
	cmpne r4, #0xd
	moveq r0, r0, lsl #0xe
	moveq r0, r0, lsr #0x10
	ldmia sp!, {r4, pc}
	arm_func_end ov11_021297BC

	arm_func_start ov11_021297EC
ov11_021297EC: ; 0x021297EC
	ldr r0, _021297FC ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	ldr r0, [r0, #0xd90]
	bx lr
	.align 2, 0
_021297FC: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_021297EC

	arm_func_start ov11_02129800
ov11_02129800: ; 0x02129800
	stmdb sp!, {r3, lr}
	ldr r2, _0212982C ; =OVERLAY11_BSS_02169C58
	ldr r2, [r2, #8]
	cmp r2, #0
	ldmeqia sp!, {r3, pc}
	add r2, r2, #0x134
	add r3, r2, #0xc00
	mov r2, #6
	mla r1, r2, r1, r3
	bl MI_CpuCopy8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212982C: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129800

	arm_func_start ov11_02129830
ov11_02129830: ; 0x02129830
	ldr r0, _02129854 ; =OVERLAY11_BSS_02169C58
	ldr r0, [r0, #8]
	cmp r0, #0
	moveq r0, #0
	bxeq lr
	ldrb r0, [r0, #0xda1]
	mov r0, r0, lsl #0x1b
	mov r0, r0, lsr #0x1f
	bx lr
	.align 2, 0
_02129854: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129830

	arm_func_start ov11_02129858
ov11_02129858: ; 0x02129858
	ldr r0, _02129874 ; =OVERLAY11_BSS_02169C58
	ldr r1, [r0, #8]
	cmp r1, #0
	ldrneb r0, [r1, #0xda1]
	orrne r0, r0, #0x10
	strneb r0, [r1, #0xda1]
	bx lr
	.align 2, 0
_02129874: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129858

	arm_func_start ov11_02129878
ov11_02129878: ; 0x02129878
	stmdb sp!, {r3, lr}
	bl ov11_0212934C
	ldr r2, _0212989C ; =OVERLAY11_BSS_02169C58
	mov r1, #0x5c
	ldr r0, [r2, #8]
	ldrh r3, [r2]
	ldr r2, [r0, #0xd94]
	bl ov11_021283E8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212989C: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_02129878

	arm_func_start ov11_021298A0
ov11_021298A0: ; 0x021298A0
	stmdb sp!, {r3, lr}
	ldr r1, _021298C0 ; =OVERLAY11_BSS_02169C58
	mov r2, #0x54
	ldr r1, [r1, #8]
	add r1, r1, #0xe0
	bl MI_CpuCopy8
	bl ov11_02129878
	ldmia sp!, {r3, pc}
	.align 2, 0
_021298C0: .word OVERLAY11_BSS_02169C58
	arm_func_end ov11_021298A0

	arm_func_start ov11_021298C4
ov11_021298C4: ; 0x021298C4
	stmdb sp!, {r3, lr}
	ldr r0, _0212993C ; =OVERLAY11_BSS_02169C64
	ldr r0, [r0]
	cmp r0, #0
	bne _021298F4
	ldr r0, _02129940 ; =0x00000253
	bl _Z10Heap_Allocm
	ldr r3, _0212993C ; =OVERLAY11_BSS_02169C64
	ldr r2, _02129940 ; =0x00000253
	mov r1, #0
	str r0, [r3]
	bl MI_CpuFill8
	arm_func_end ov11_021298C4
_021298F4:
	ldr r0, _0212993C ; =OVERLAY11_BSS_02169C64
	mov r2, #0
	mov r3, #0xff
_02129900:
	ldr r1, [r0]
	add r1, r1, r2
	add r2, r2, #1
	strb r3, [r1, #0x10]
	cmp r2, #8
	blt _02129900
	ldr r0, _0212993C ; =OVERLAY11_BSS_02169C64
	mov r1, #0
	ldr r2, [r0]
	strb r3, [r2, #0x250]
	ldr r2, [r0]
	strb r3, [r2, #0x251]
	ldr r0, [r0]
	strb r1, [r0, #0x252]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212993C: .word OVERLAY11_BSS_02169C64
_02129940: .word 0x00000253

	arm_func_start ov11_02129944
ov11_02129944: ; 0x02129944
	stmdb sp!, {r3, lr}
	ldr r0, _0212996C ; =OVERLAY11_BSS_02169C64
	ldr r0, [r0]
	cmp r0, #0
	beq _0212995C
	bl _Z9Heap_FreePv
	arm_func_end ov11_02129944
_0212995C:
	ldr r0, _0212996C ; =OVERLAY11_BSS_02169C64
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212996C: .word OVERLAY11_BSS_02169C64

	arm_func_start ov11_02129970
ov11_02129970: ; 0x02129970
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	ldrb r1, [r2]
	mov r6, r0
	strb r1, [sp]
	bl ov11_0212C154
	cmp r0, #0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, r5, r6, pc}
	ldrb r2, [sp]
	add r1, sp, #1
	mov r0, #0x12
	strb r6, [sp, #1]
	strb r2, [sp, #2]
	bl ov11_0212BB6C
	ldr r5, _02129A18 ; =OVERLAY11_BSS_02169C64
	ldrb r1, [sp]
	ldr r0, [r5]
	mov r4, #0
	add r0, r0, r6
	strb r1, [r0, #0x10]
	arm_func_end ov11_02129970
_021299C4:
	mov r0, r4
	bl ov11_0212BEA0
	cmp r0, #0
	beq _021299F0
	ldr r0, [r5]
	ldrb r1, [sp]
	add r0, r0, r4
	ldrb r0, [r0, #0x10]
	cmp r1, r0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, r5, r6, pc}
_021299F0:
	add r0, r4, #1
	mov r0, r0, lsl #0x10
	mov r4, r0, lsr #0x10
	cmp r4, #8
	blo _021299C4
	add r1, sp, #0
	mov r0, #0x11
	bl ov11_0212BB6C
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02129A18: .word OVERLAY11_BSS_02169C64

	arm_func_start ov11_02129A1C
ov11_02129A1C: ; 0x02129A1C
	ldr r0, _02129A38 ; =0x02169C64
	ldrb r1, [r2]
	ldr r0, [r0]
	ldrb r2, [r2, #1]
	add r0, r0, r1
	strb r2, [r0, #0x10]
	bx lr
	.align 2, 0
	arm_func_end ov11_02129A1C
_02129A38: .word OVERLAY11_BSS_02169C64

	arm_func_start ov11_02129A3C
ov11_02129A3C: ; 0x02129A3C
	ldr r0, _02129A50 ; =0x02169C64
	ldrb r1, [r2]
	ldr r0, [r0]
	strb r1, [r0, #0x250]
	bx lr
	.align 2, 0
	arm_func_end ov11_02129A3C
_02129A50: .word OVERLAY11_BSS_02169C64

	arm_func_start ov11_02129A54
ov11_02129A54: ; 0x02129A54
	ldr r1, _02129A70 ; =OVERLAY11_BSS_02169C64
	mov r2, #1
	ldr r3, [r1]
	strb r0, [r3, #0x251]
	ldr r0, [r1]
	strb r2, [r0, #0x252]
	bx lr
	.align 2, 0
_02129A70: .word OVERLAY11_BSS_02169C64
	arm_func_end ov11_02129A54

	arm_func_start ov11_02129A74
ov11_02129A74: ; 0x02129A74
	stmdb sp!, {r3, lr}
	ldr r0, _02129ABC ; =OVERLAY11_BSS_02169C64
	ldr r1, [r0]
	cmp r1, #0
	ldrneb r0, [r1, #0x252]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	add r0, r1, #0x51
	add r1, r0, #0x200
	mov r0, #0x10
	bl ov11_0212C198
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _02129ABC ; =OVERLAY11_BSS_02169C64
	mov r1, #0
	ldr r0, [r0]
	strb r1, [r0, #0x252]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02129ABC: .word OVERLAY11_BSS_02169C64
	arm_func_end ov11_02129A74

	arm_func_start ov11_02129AC0
ov11_02129AC0: ; 0x02129AC0
	ldr r1, _02129AE8 ; =OVERLAY11_BSS_02169C64
	ldr r1, [r1]
	cmp r1, #0
	moveq r0, #1
	bxeq lr
	ldrb r1, [r1, #0x250]
	cmp r1, r0
	moveq r0, #1
	movne r0, #0
	bx lr
	.align 2, 0
_02129AE8: .word OVERLAY11_BSS_02169C64
	arm_func_end ov11_02129AC0

	arm_func_start ov11_02129AEC
ov11_02129AEC: ; 0x02129AEC
	ldr r1, _02129B10 ; =0x02169C64
	ldrb ip, [r2]
	ldr r3, [r1]
	strb ip, [r3, r0, lsl #1]
	ldr r1, [r1]
	ldrb r2, [r2, #1]
	add r0, r1, r0, lsl #1
	strb r2, [r0, #1]
	bx lr
	.align 2, 0
	arm_func_end ov11_02129AEC
_02129B10: .word OVERLAY11_BSS_02169C64

	arm_func_start ov11_02129B14
ov11_02129B14: ; 0x02129B14
	mov r0, #2
	bx lr
	arm_func_end ov11_02129B14

	arm_func_start ov11_02129B1C
ov11_02129B1C: ; 0x02129B1C
	stmdb sp!, {r3, lr}
	ldr r1, _02129B54 ; =OVERLAY11_BSS_02169C64
	mov ip, r0
	ldr r3, [r1]
	mov r0, r2
	add r2, r3, ip
	mov r3, #1
	strb r3, [r2, #0x248]
	ldr r1, [r1]
	mov r2, #0x46
	add r1, r1, #0x18
	mla r1, ip, r2, r1
	bl MI_CpuCopy8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02129B54: .word OVERLAY11_BSS_02169C64
	arm_func_end ov11_02129B1C

    arm_func_start ov11_02129B58
ov11_02129B58: ; 0x02129B58
    mov r0, #0x46
    bx lr
    arm_func_end ov11_02129B58

	arm_func_start ov11_02129B60
ov11_02129B60: ; 0x02129B60
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, _02129D5C ; =OVERLAY11_BSS_02169C68
	mov r4, #0
	mov r6, r1
	strb r4, [r2]
	cmp r0, #0
	beq _02129CF0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	ldr r1, _02129D5C ; =OVERLAY11_BSS_02169C68
	add r5, r0, #1
	ldr r0, [r1, #4]
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
	mov r0, r4
	bl ov11_021298C4
	ldr r0, _02129D60 ; =0x00000688
	bl _Z10Heap_Allocm
	ldr r3, _02129D5C ; =OVERLAY11_BSS_02169C68
	ldr r2, _02129D60 ; =0x00000688
	mov r1, r4
	str r0, [r3, #4]
	bl MI_CpuFill8
	ldr r0, _02129D5C ; =OVERLAY11_BSS_02169C68
	add r2, r6, #0x40
	ldr r1, [r0, #4]
	mov r3, r4
	str r2, [r1, #0x654]
	ldr r1, [r0, #4]
	mov r2, #0x1b
	strb r3, [r1, #0x679]
	ldr r1, [r0, #4]
	strb r2, [r1, #0x67a]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x654]
	mov r0, r0, lsl #1
	bl _Z10Heap_Allocm
	ldr r1, _02129D5C ; =OVERLAY11_BSS_02169C68
	ldr r2, [r1, #4]
	str r0, [r2, #0x45c]
	ldr r0, [r1, #4]
	ldr r0, [r0, #0x654]
	bl _Z10Heap_Allocm
	ldr r1, _02129D5C ; =OVERLAY11_BSS_02169C68
	ldr r2, [r1, #4]
	str r0, [r2, #0x460]
	ldr r0, [r1, #4]
	ldr r0, [r0, #0x654]
	mul r0, r5, r0
	bl _Z10Heap_Allocm
	ldr r1, _02129D5C ; =OVERLAY11_BSS_02169C68
	ldr r2, [r1, #4]
	str r0, [r2, #0x458]
	ldr r0, [r1, #4]
	ldr r0, [r0, #0x654]
	mul r0, r5, r0
	bl _Z10Heap_Allocm
	ldr r1, _02129D5C ; =OVERLAY11_BSS_02169C68
	ldr r1, [r1, #4]
	str r0, [r1, #0x454]
	bl ov11_02128EE0
	cmp r0, #0xa
	bne _02129CAC
	ldr r0, _02129D5C ; =OVERLAY11_BSS_02169C68
	mov r1, #0x64
	ldr r2, [r0, #4]
	add r0, r2, #0x148
	add r2, r2, #0x64
	add r0, r0, #0x400
	add r2, r2, #0x400
	bl ov11_0212C7FC
	ldr r0, _02129D5C ; =OVERLAY11_BSS_02169C68
	mov r1, #0x320
	ldr r2, [r0, #4]
	add r0, r2, #0x168
	add r2, r2, #0xdc
	add r0, r0, #0x400
	add r2, r2, #0x400
	bl ov11_0212C7FC
	b _02129CF4
	arm_func_end ov11_02129B60
_02129CAC:
	ldr r0, _02129D5C ; =OVERLAY11_BSS_02169C68
	mov r1, #0x14
	ldr r2, [r0, #4]
	add r0, r2, #0x148
	add r2, r2, #0x64
	add r0, r0, #0x400
	add r2, r2, #0x400
	bl ov11_0212C7FC
	ldr r0, _02129D5C ; =OVERLAY11_BSS_02169C68
	mov r1, #0x118
	ldr r2, [r0, #4]
	add r0, r2, #0x168
	add r2, r2, #0xdc
	add r0, r0, #0x400
	add r2, r2, #0x400
	bl ov11_0212C7FC
	b _02129CF4
_02129CF0:
	mov r4, #1
_02129CF4:
	ldr r1, _02129D5C ; =OVERLAY11_BSS_02169C68
	mov r3, #0
	ldr r0, [r1, #4]
	mov r2, #0xff
	add r0, r0, #0x600
	strh r3, [r0, #0x58]
_02129D0C:
	ldr r0, [r1, #4]
	add r0, r0, r3
	add r3, r3, #1
	strb r2, [r0, #0x673]
	cmp r3, #4
	blt _02129D0C
	cmp r4, #0
	bne _02129D30
	bl ov11_02129D64
_02129D30:
	ldr r0, _02129D5C ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	add r0, r0, #0x1f4
	add r0, r0, #0x400
	bl ov11_0212C21C
	ldr r0, _02129D5C ; =OVERLAY11_BSS_02169C68
	mov r2, #0
	ldr r1, [r0, #4]
	mov r0, #1
	strb r2, [r1, #0x683]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02129D5C: .word OVERLAY11_BSS_02169C68
_02129D60: .word 0x00000688

	arm_func_start ov11_02129D64
ov11_02129D64: ; 0x02129D64
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r2, #0
	ldr r1, [r0, #4]
	strb r2, [r1, #0x628]
	ldr r1, [r0, #4]
	strb r2, [r1, #0x629]
	ldr r1, [r0, #4]
	strb r2, [r1, #0x67b]
	ldr r0, [r0, #4]
	strb r2, [r0, #0x67c]
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	ldr r1, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	add r5, r0, #1
	ldr r0, [r1, #4]
	mov r1, #0
	ldr r3, [r0, #0x654]
	ldr r0, [r0, #0x458]
	mul r2, r3, r5
	bl MI_CpuFill8
	cmp r5, #0
	mov r4, #0
	ble _02129E04
	ldr r7, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r6, r4
	arm_func_end ov11_02129D64
_02129DD4:
	ldr r0, [r7, #4]
	ldr r2, [r0, #0x654]
	ldr r1, [r0, #0x458]
	add r0, r0, #0xe8
	mla r1, r4, r2, r1
	add r0, r0, #0x400
	add r0, r0, r6
	bl ov11_0212C89C
	add r4, r4, #1
	cmp r4, r5
	add r6, r6, #0xc
	blt _02129DD4
_02129E04:
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	ldr r3, [r0, #0x654]
	ldr r0, [r0, #0x454]
	mul r2, r3, r5
	bl MI_CpuFill8
	cmp r5, #0
	mov r6, #0
	ble _02129E64
	ldr r7, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r4, r6
_02129E34:
	ldr r0, [r7, #4]
	ldr r2, [r0, #0x654]
	ldr r1, [r0, #0x454]
	add r0, r0, #0x7c
	mla r1, r6, r2, r1
	add r0, r0, #0x400
	add r0, r0, r4
	bl ov11_0212C89C
	add r6, r6, #1
	cmp r6, r5
	add r4, r4, #0xc
	blt _02129E34
_02129E64:
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	mov r2, #0x180
	add r0, r0, #0x2d4
	bl MI_CpuFill8
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r2, #0x180
	ldr r1, [r0, #4]
	add r0, r1, #0xdc
	add r0, r0, #0x400
	add r1, r1, #0x2d4
	bl ov11_0212C89C
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r3, #0
	mov r2, #0xee
_02129EA4:
	ldr r1, [r0, #4]
	add r1, r1, r3
	strb r2, [r1, #0x154]
	ldr r1, [r0, #4]
	add r1, r1, r3
	add r3, r3, #1
	strb r2, [r1, #0x214]
	cmp r3, #0xc0
	blt _02129EA4
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	mov r2, #0x108
	add r0, r0, #0x4c
	bl MI_CpuFill8
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r2, #0x108
	ldr r1, [r0, #4]
	add r0, r1, #0x64
	add r0, r0, #0x400
	add r1, r1, #0x4c
	bl ov11_0212C89C
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r2, #0xff
	ldr r1, [r0, #4]
	mov r3, #1
	strb r2, [r1]
	ldr r1, [r0, #4]
	strb r2, [r1, #0x26]
	mov r2, #0xee
_02129F1C:
	ldr r1, [r0, #4]
	strb r2, [r1, r3]
	ldr r1, [r0, #4]
	add r1, r1, r3
	add r3, r3, #1
	strb r2, [r1, #0x26]
	cmp r3, #0x26
	blt _02129F1C
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	ldr r2, [r0, #0x654]
	ldr r0, [r0, #0x45c]
	mov r2, r2, lsl #1
	bl MI_CpuFill8
	ldr r0, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldr r2, [r0, #0x654]
	ldr r1, [r0, #0x45c]
	add r0, r0, #0x470
	mov r2, r2, lsl #1
	bl ov11_0212C89C
	mov r5, #0
	ldr ip, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	mov r4, r5
	ldr r0, [ip, #4]
	mov r3, r5
	strb r5, [r0, #0x680]
	ldr r0, [ip, #4]
	mov r2, #1
	strb r5, [r0, #0x681]
	ldr r0, _0212A0B8 ; =0x0000FFFF
	mov r1, #0xee
_02129FA0:
	ldr r6, [ip, #4]
	add r6, r6, r5
	strb r3, [r6, #0x65b]
	ldr r6, [ip, #4]
	add r6, r6, r5
	strb r2, [r6, #0x663]
	ldr r6, [ip, #4]
	add r6, r6, r5
	strb r2, [r6, #0x66b]
	ldr r6, [ip, #4]
	add r6, r6, r5, lsl #1
	add r6, r6, #0x600
	strh r3, [r6, #0xc]
	ldr r6, [ip, #4]
	add r6, r6, r4
	strb r1, [r6, #0x592]
	ldr r6, [ip, #4]
	add r6, r6, r4
	add r6, r6, #0x500
	strh r0, [r6, #0x90]
	ldr r6, [ip, #4]
	add r6, r6, r4
	str r3, [r6, #0x58c]
	ldr r6, [ip, #4]
	add r6, r6, r4
	str r3, [r6, #0x588]
	ldr r6, [ip, #4]
	add r4, r4, #0xc
	add r6, r6, r5, lsl #2
	add r5, r5, #1
	str r3, [r6, #0x634]
	cmp r5, #8
	blt _02129FA0
	ldr r5, _0212A0B4 ; =OVERLAY11_BSS_02169C68
	ldr r4, _0212A0BC ; =DAT_overlay_11_0216649c
	ldr r7, [r5, #4]
	mov r6, #4
	str r3, [r7, #0x630]
	ldr r7, [r5, #4]
	str r2, [r7, #0x62c]
	ldr r7, [r5, #4]
	strb r1, [r7, #0x5f2]
	ldr r1, [r5, #4]
	add r1, r1, #0x500
	strh r0, [r1, #0xf0]
	ldr r0, [r5, #4]
	str r3, [r0, #0x5ec]
	ldr r0, [r5, #4]
	str r3, [r0, #0x5e8]
	ldr r0, [r5, #4]
	strb r2, [r0, #0x67e]
	ldr r0, [r5, #4]
	strb r2, [r0, #0x67f]
	strb r6, [r4, #1]
	strb r6, [r4]
	ldr r0, [r5, #4]
	add r0, r0, #0x148
	add r0, r0, #0x400
	bl ov11_0212C840
	mov r0, r5
	ldr r0, [r0, #4]
	add r0, r0, #0x168
	add r0, r0, #0x400
	bl ov11_0212C840
	mov r0, r5
	ldr r0, [r0, #4]
	mov r1, #0
	strb r1, [r0, #0x684]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0212A0B4: .word OVERLAY11_BSS_02169C68
_0212A0B8: .word 0x0000FFFF
_0212A0BC: .word DAT_overlay_11_0216649c

	arm_func_start ov11_0212A0C0
ov11_0212A0C0: ; 0x0212A0C0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r2, #0
	ldr r1, [r0, #4]
	strb r2, [r1, #0x628]
	ldr r0, [r0, #4]
	strb r2, [r0, #0x629]
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	ldr r1, _0212A3DC ; =OVERLAY11_BSS_02169C68
	add r5, r0, #1
	ldr r0, [r1, #4]
	mov r1, #0
	ldr r3, [r0, #0x654]
	ldr r0, [r0, #0x458]
	mul r2, r3, r5
	bl MI_CpuFill8
	cmp r5, #0
	mov r4, #0
	ble _0212A150
	ldr r7, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r6, r4
	arm_func_end ov11_0212A0C0
_0212A120:
	ldr r0, [r7, #4]
	ldr r2, [r0, #0x654]
	ldr r1, [r0, #0x458]
	add r0, r0, #0xe8
	mla r1, r4, r2, r1
	add r0, r0, #0x400
	add r0, r0, r6
	bl ov11_0212C89C
	add r4, r4, #1
	cmp r4, r5
	add r6, r6, #0xc
	blt _0212A120
_0212A150:
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	ldr r3, [r0, #0x654]
	ldr r0, [r0, #0x454]
	mul r2, r3, r5
	bl MI_CpuFill8
	cmp r5, #0
	mov r6, #0
	ble _0212A1B0
	ldr r7, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r4, r6
_0212A180:
	ldr r0, [r7, #4]
	ldr r2, [r0, #0x654]
	ldr r1, [r0, #0x454]
	add r0, r0, #0x7c
	mla r1, r6, r2, r1
	add r0, r0, #0x400
	add r0, r0, r4
	bl ov11_0212C89C
	add r6, r6, #1
	cmp r6, r5
	add r4, r4, #0xc
	blt _0212A180
_0212A1B0:
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	mov r2, #0x180
	add r0, r0, #0x2d4
	bl MI_CpuFill8
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r2, #0x180
	ldr r1, [r0, #4]
	add r0, r1, #0xdc
	add r0, r0, #0x400
	add r1, r1, #0x2d4
	bl ov11_0212C89C
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r3, #0
	mov r2, #0xee
_0212A1F0:
	ldr r1, [r0, #4]
	add r1, r1, r3
	strb r2, [r1, #0x154]
	ldr r1, [r0, #4]
	add r1, r1, r3
	add r3, r3, #1
	strb r2, [r1, #0x214]
	cmp r3, #0xc0
	blt _0212A1F0
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	mov r2, #0x108
	add r0, r0, #0x4c
	bl MI_CpuFill8
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r2, #0x108
	ldr r1, [r0, #4]
	add r0, r1, #0x64
	add r0, r0, #0x400
	add r1, r1, #0x4c
	bl ov11_0212C89C
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r2, #0xff
	ldr r1, [r0, #4]
	mov r3, #1
	strb r2, [r1]
	ldr r1, [r0, #4]
	strb r2, [r1, #0x26]
	mov r2, #0xee
_0212A268:
	ldr r1, [r0, #4]
	strb r2, [r1, r3]
	ldr r1, [r0, #4]
	add r1, r1, r3
	add r3, r3, #1
	strb r2, [r1, #0x26]
	cmp r3, #0x26
	blt _0212A268
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	ldr r2, [r0, #0x654]
	ldr r0, [r0, #0x45c]
	mov r2, r2, lsl #1
	bl MI_CpuFill8
	ldr r0, _0212A3DC ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldr r2, [r0, #0x654]
	ldr r1, [r0, #0x45c]
	add r0, r0, #0x470
	mov r2, r2, lsl #1
	bl ov11_0212C89C
	mov r5, #0
	ldr ip, _0212A3DC ; =OVERLAY11_BSS_02169C68
	mov r4, r5
	ldr r0, [ip, #4]
	mov r3, r5
	strb r5, [r0, #0x680]
	ldr r0, [ip, #4]
	mov r2, #1
	strb r5, [r0, #0x681]
	ldr r0, _0212A3E0 ; =0x0000FFFF
	mov r1, #0xee
_0212A2EC:
	ldr r6, [ip, #4]
	add r6, r6, r5
	strb r3, [r6, #0x65b]
	ldr r6, [ip, #4]
	add r6, r6, r5
	strb r2, [r6, #0x663]
	ldr r6, [ip, #4]
	add r6, r6, r5
	strb r2, [r6, #0x66b]
	ldr r6, [ip, #4]
	add r6, r6, r5, lsl #1
	add r6, r6, #0x600
	strh r3, [r6, #0xc]
	ldr r6, [ip, #4]
	add r5, r5, #1
	add r6, r6, r4
	strb r1, [r6, #0x592]
	ldr r6, [ip, #4]
	cmp r5, #8
	add r6, r6, r4
	add r6, r6, #0x500
	strh r0, [r6, #0x90]
	ldr r6, [ip, #4]
	add r6, r6, r4
	str r3, [r6, #0x58c]
	ldr r6, [ip, #4]
	add r6, r6, r4
	str r3, [r6, #0x588]
	add r4, r4, #0xc
	blt _0212A2EC
	ldr r4, _0212A3DC ; =OVERLAY11_BSS_02169C68
	ldr r5, [r4, #4]
	str r2, [r5, #0x62c]
	ldr r5, [r4, #4]
	strb r1, [r5, #0x5f2]
	ldr r1, [r4, #4]
	add r1, r1, #0x500
	strh r0, [r1, #0xf0]
	ldr r0, [r4, #4]
	str r3, [r0, #0x5ec]
	ldr r0, [r4, #4]
	str r3, [r0, #0x5e8]
	ldr r0, [r4, #4]
	strb r2, [r0, #0x67e]
	ldr r0, [r4, #4]
	strb r2, [r0, #0x67f]
	ldr r0, [r4, #4]
	add r0, r0, #0x148
	add r0, r0, #0x400
	bl ov11_0212C840
	mov r0, r4
	ldr r0, [r0, #4]
	add r0, r0, #0x168
	add r0, r0, #0x400
	bl ov11_0212C840
	mov r0, r4
	ldr r0, [r0, #4]
	mov r1, #0
	strb r1, [r0, #0x684]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0212A3DC: .word OVERLAY11_BSS_02169C68
_0212A3E0: .word 0x0000FFFF

	arm_func_start ov11_0212A3E4
ov11_0212A3E4: ; 0x0212A3E4
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0212A4BC ; =OVERLAY11_BSS_02169C68
	mov r5, r0
	ldr r2, [r1, #4]
	mov r0, #0xc
	add r2, r2, r5
	mov ip, #0
	strb ip, [r2, #0x65b]
	ldr r2, [r1, #4]
	mov r3, #1
	add r2, r2, r5
	strb r3, [r2, #0x663]
	ldr r2, [r1, #4]
	mul r4, r5, r0
	add r0, r2, r5, lsl #2
	str ip, [r0, #0x634]
	ldr r0, [r1, #4]
	add r0, r0, r5
	strb r3, [r0, #0x66b]
	ldr r1, [r1, #4]
	add r0, r1, #0x7c
	add r0, r0, #0x400
	ldr r2, [r1, #0x654]
	ldr r1, [r1, #0x454]
	add r0, r0, r4
	mla r1, r5, r2, r1
	bl ov11_0212C89C
	ldr r0, _0212A4BC ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	add r0, r1, #0xe8
	add r0, r0, #0x400
	ldr r2, [r1, #0x654]
	ldr r1, [r1, #0x458]
	add r0, r0, r4
	mla r1, r5, r2, r1
	bl ov11_0212C89C
	ldr r1, _0212A4BC ; =OVERLAY11_BSS_02169C68
	mov r2, #0xee
	ldr r0, [r1, #4]
	ldr r3, _0212A4C0 ; =0x0000FFFF
	add r0, r0, r4
	strb r2, [r0, #0x592]
	ldr r0, [r1, #4]
	mov r2, #0
	add r0, r0, r4
	add r0, r0, #0x500
	strh r3, [r0, #0x90]
	ldr r0, [r1, #4]
	add r0, r0, r4
	str r2, [r0, #0x58c]
	ldr r0, [r1, #4]
	add r0, r0, r4
	str r2, [r0, #0x588]
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0212A4BC: .word OVERLAY11_BSS_02169C68
_0212A4C0: .word 0x0000FFFF
	arm_func_end ov11_0212A3E4

	arm_func_start ov11_0212A4C4
ov11_0212A4C4: ; 0x0212A4C4
	stmdb sp!, {r3, r4, r5, lr}
	ldr r4, _0212A520 ; =OVERLAY11_BSS_02169C68
	mov r5, #1
	arm_func_end ov11_0212A4C4
_0212A4D0:
	mov r0, r5
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212A508
	ldr r0, [r4, #4]
	add r0, r0, r5
	ldrb r0, [r0, #0x663]
	cmp r0, #0
	bne _0212A508
	bl ov11_0212C1D0
	cmp r0, #0
	bne _0212A508
	mov r0, r5
	bl ov11_0212A3E4
_0212A508:
	add r0, r5, #1
	mov r0, r0, lsl #0x10
	mov r5, r0, lsr #0x10
	cmp r5, #8
	blo _0212A4D0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0212A520: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212A524
ov11_0212A524: ; 0x0212A524
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	mov r7, r1
	mov r6, r2
	mov r5, r3
	mov r4, #1
	bl ov11_02128EE0
	cmp r0, #0x13
	bge _0212A55C
	mov r0, r8
	mov r1, r7
	mov r2, r5
	bl ov11_02129144
	mov r4, r0
	arm_func_end ov11_0212A524
_0212A55C:
	mov r0, r8
	mov r1, r6
	bl ov11_02129B60
	mov r0, r4
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov11_0212A570
ov11_0212A570: ; 0x0212A570
	stmdb sp!, {r4, lr}
	mov r4, #0
	bl ov11_0212C154
	cmp r0, #0
	bne _0212A598
	ldr r0, _0212A5F0 ; =DAT_overlay_11_0216649c
	ldrb r0, [r0, #1]
	cmp r0, #4
	beq _0212A5A8
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212A570
_0212A598:
	ldr r0, _0212A5F0 ; =DAT_overlay_11_0216649c
	ldrb r0, [r0]
	cmp r0, #4
	ldmneia sp!, {r4, pc}
_0212A5A8:
	ldr r0, _0212A5F4 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	ldrb r0, [r1, #0x679]
	cmp r0, #2
	moveq r0, #0
	streqb r0, [r1, #0x679]
	ldr r0, _0212A5F4 ; =OVERLAY11_BSS_02169C68
	moveq r4, #1
	ldr r1, [r0, #4]
	ldrb r0, [r1, #0x679]
	cmp r0, #3
	moveq r4, #1
	streqb r4, [r1, #0x679]
	cmp r4, #0
	beq _0212A5E8
	bl ov11_0212A0C0
_0212A5E8:
	bl ov11_0212BFD4
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212A5F0: .word DAT_overlay_11_0216649c
_0212A5F4: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212A5F8
ov11_0212A5F8: ; 0x0212A5F8
	ldr r1, _0212A62C ; =OVERLAY11_BSS_02169C68
	ldr r2, [r1, #4]
	ldrb r1, [r2, #0x679]
	cmp r1, #0
	cmpeq r0, #1
	moveq r0, #3
	streqb r0, [r2, #0x679]
	bxeq lr
	cmp r1, #1
	cmpeq r0, #0
	moveq r0, #2
	streqb r0, [r2, #0x679]
	bx lr
	.align 2, 0
_0212A62C: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212A5F8

	arm_func_start ov11_0212A630
ov11_0212A630: ; 0x0212A630
	ldr ip, _0212A63C ; =ov11_0212A5F8
	mov r0, #1
	bx ip
	.align 2, 0
_0212A63C: .word ov11_0212A5F8
	arm_func_end ov11_0212A630

	arm_func_start ov11_0212A640
ov11_0212A640: ; 0x0212A640
	ldr r0, _0212A664 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x679]
	cmp r0, #2
	moveq r0, #1
	bxeq lr
	cmp r0, #3
	moveq r0, #0
	bx lr
	.align 2, 0
_0212A664: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212A640

	arm_func_start ov11_0212A668
ov11_0212A668: ; 0x0212A668
	stmdb sp!, {r4, lr}
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	mov r4, #0
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0212A69C
	bl ov11_02128EE0
	cmp r0, #0x13
	movge r4, #1
	bge _0212A69C
	bl ov11_021292B8
	cmp r0, #0
	movne r4, #1
	arm_func_end ov11_0212A668
_0212A69C:
	cmp r4, #0
	ldmeqia sp!, {r4, pc}
	bl ov11_02129944
	bl ov11_0212874C
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	strb r1, [r0]
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x45c]
	cmp r0, #0
	beq _0212A6DC
	bl _Z9Heap_FreePv
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	str r1, [r0, #0x45c]
_0212A6DC:
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x460]
	cmp r0, #0
	beq _0212A704
	bl _Z9Heap_FreePv
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	str r1, [r0, #0x460]
_0212A704:
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x458]
	cmp r0, #0
	beq _0212A72C
	bl _Z9Heap_FreePv
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	str r1, [r0, #0x458]
_0212A72C:
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x454]
	cmp r0, #0
	beq _0212A754
	bl _Z9Heap_FreePv
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	str r1, [r0, #0x454]
_0212A754:
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	add r0, r0, #0x168
	add r0, r0, #0x400
	bl ov11_0212C878
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	add r0, r0, #0x148
	add r0, r0, #0x400
	bl ov11_0212C878
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0212A790
	bl _Z9Heap_FreePv
_0212A790:
	ldr r0, _0212A7A0 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	str r1, [r0, #4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212A7A0: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212A7A4
ov11_0212A7A4: ; 0x0212A7A4
	stmdb sp!, {r3, lr}
	ldr r0, _0212A800 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	cmp r1, #0
	ldrneb r0, [r0]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov11_0212B2A0
	bl ov11_0212C154
	cmp r0, #0
	bne _0212A7E0
	mov r0, #0
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212A7EC
	arm_func_end ov11_0212A7A4
_0212A7E0:
	bl ov11_0212C1D0
	cmp r0, #0
	beq _0212A7F0
_0212A7EC:
	bl ov11_0212AB58
_0212A7F0:
	ldr r0, _0212A800 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	strb r1, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212A800: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212A804
ov11_0212A804: ; 0x0212A804
	stmdb sp!, {r3, lr}
	bl ov11_02129830
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov11_0212C154
	cmp r0, #0
	bne _0212A834
	bl ov11_0212978C
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	bl ov11_0212A668
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212A804
_0212A834:
	bl ov11_0212A668
	ldmia sp!, {r3, pc}

	arm_func_start ov11_0212A83C
ov11_0212A83C: ; 0x0212A83C
	stmdb sp!, {r3, lr}
	bl ov11_021285AC
	bl ov11_02128C14
	ldr r0, _0212A940 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	cmp r1, #0
	beq _0212A928
	ldrb r1, [r1, #0x686]
	cmp r1, #0
	bne _0212A8FC
	mov r1, #0
	strb r1, [r0]
	bl ov11_0212A570
	bl ov11_0212A944
	ldr r0, _0212A940 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	add r0, r0, #0x600
	ldrh r1, [r0, #0x24]
	and r1, r1, #0x8000
	strh r1, [r0, #0x24]
	bl ov11_0212A640
	cmp r0, #0
	bne _0212A89C
	bl ov11_0212BD58
	arm_func_end ov11_0212A83C
_0212A89C:
	bl ov11_0212C154
	cmp r0, #0
	bne _0212A8B8
	mov r0, #0
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212A8C4
_0212A8B8:
	bl ov11_0212C1D0
	cmp r0, #0
	beq _0212A8C8
_0212A8C4:
	bl ov11_0212AD8C
_0212A8C8:
	bl ov11_0212C154
	cmp r0, #0
	beq _0212A8EC
	bl ov11_0212A640
	cmp r0, #1
	beq _0212A8EC
	bl ov11_0212C1D0
	cmp r0, #0
	beq _0212A8F0
_0212A8EC:
	bl ov11_0212BDC8
_0212A8F0:
	ldr r0, _0212A940 ; =OVERLAY11_BSS_02169C68
	mov r1, #1
	strb r1, [r0]
_0212A8FC:
	ldr r0, _0212A940 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	add r0, r0, #0x600
	ldrh r0, [r0, #0x58]
	bl ov11_021296C8
	bl ov11_0212C154
	cmp r0, #0
	bne _0212A920
	bl ov11_0212A4C4
_0212A920:
	bl ov11_0212A804
	b _0212A930
_0212A928:
	mov r0, #0
	bl ov11_021296C8
_0212A930:
	bl ov11_02129A74
	bl ov11_0212A7A4
	mov r0, #1
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212A940: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212A944
ov11_0212A944: ; 0x0212A944
	stmdb sp!, {r3, lr}
	ldr r0, _0212AA5C ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x67f]
	cmp r0, #0
	beq _0212A9C4
	bl ov11_02128EE0
	cmp r0, #0x13
	ldmgeia sp!, {r3, pc}
	bl ov11_02127B08
	cmp r0, #4
	bne _0212A984
	bl ov11_0212C154
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212A990
	arm_func_end ov11_0212A944
_0212A984:
	bl ov11_0212C1D0
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
_0212A990:
	ldr r0, _0212AA60 ; =DAT_overlay_11_0216649c
	mov r1, #0
	strb r1, [r0]
	bl ov11_0212B2A0
	ldr r0, _0212AA60 ; =DAT_overlay_11_0216649c
	ldrb r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _0212AA5C ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	strb r1, [r0, #0x67f]
	ldmia sp!, {r3, pc}
_0212A9C4:
	bl ov11_02128EE0
	cmp r0, #0x13
	ldmgeia sp!, {r3, pc}
	bl ov11_02127B08
	cmp r0, #4
	bne _0212A9EC
	bl ov11_0212C154
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212A9F8
_0212A9EC:
	bl ov11_0212C1D0
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
_0212A9F8:
	ldr r0, _0212AA60 ; =DAT_overlay_11_0216649c
	ldrb r0, [r0]
	cmp r0, #4
	ldmneia sp!, {r3, pc}
	ldr r0, _0212AA5C ; =OVERLAY11_BSS_02169C68
	ldr r2, [r0, #4]
	ldr r0, [r2, #0x630]
	cmp r0, #3
	ldmgtia sp!, {r3, pc}
	ldrb r1, [r2, #0x67b]
	mov r0, #0x26
	mla r0, r1, r0, r2
	bl ov11_0212B6AC
	ldr r1, _0212AA5C ; =OVERLAY11_BSS_02169C68
	mov r0, #0x26
	ldr r2, [r1, #4]
	ldrb r1, [r2, #0x67b]
	rsb r1, r1, #1
	mla r0, r1, r0, r2
	bl ov11_0212B6AC
	ldr r0, _0212AA60 ; =DAT_overlay_11_0216649c
	mov r1, #0
	strb r1, [r0]
	bl ov11_0212B2A0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212AA5C: .word OVERLAY11_BSS_02169C68
_0212AA60: .word DAT_overlay_11_0216649c

	arm_func_start ov11_0212AA64
ov11_0212AA64: ; 0x0212AA64
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r4, r0
	mov r7, #0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212C1A8
	mov r5, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	add fp, r0, #1
	cmp fp, #0
	mov r6, r7
	ble _0212AB44
	mov r0, #0xc0
	mul sl, r4, r0
	ldr r4, _0212AB54 ; =OVERLAY11_BSS_02169C68
	mov r8, r6
	mov sb, r6
	arm_func_end ov11_0212AA64
_0212AAB8:
	ldr r0, [r4, #4]
	add r0, r0, #0x7c
	add r0, r0, #0x400
	add r0, r0, r8
	bl ov11_0212CA54
	mov r0, r6, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212AAF4
	ldr r0, [r4, #4]
	add r0, sl, r0
	add r1, sb, r0
	mov r0, #0xe
	strb r0, [r1, #0x154]
_0212AAF4:
	ldr r1, [r4, #4]
	mov r2, r5
	add r0, r1, #0x7c
	add r1, r1, #0x154
	add r0, r0, #0x400
	add r1, r1, sl
	add r0, r0, r8
	add r1, r1, sb
	bl ov11_0212C938
	ldr r0, [r4, #4]
	add r6, r6, #1
	add r0, sl, r0
	add r0, sb, r0
	ldrb r0, [r0, #0x154]
	add r8, r8, #0xc
	add sb, sb, r5
	cmp r0, #0xe
	addeq r7, r7, #1
	cmp r6, fp
	blt _0212AAB8
_0212AB44:
	cmp r7, fp
	moveq r0, #0
	movne r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0212AB54: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212AB58
ov11_0212AB58: ; 0x0212AB58
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	ldr r0, _0212AD80 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	bl ov11_02128EE0
	cmp r0, #0x13
	ldmgeia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212C1A8
	mov r6, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	ldr r1, _0212AD84 ; =DAT_overlay_11_0216649c
	add r7, r0, #1
	ldrb r0, [r1, #1]
	cmp r0, #2
	ldrneb r0, [r1, #1]
	cmpne r0, #0
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r0, _0212AD84 ; =DAT_overlay_11_0216649c
	ldrb r1, [r0, #1]
	add r1, r1, #1
	strb r1, [r0, #1]
	bl ov11_0212A640
	cmp r0, #1
	bne _0212ABE4
	ldr r0, _0212AD80 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x67c]
	bl ov11_0212AA64
	arm_func_end ov11_0212AB58
_0212ABE4:
	bl ov11_02127B08
	cmp r0, #4
	bne _0212AC38
	bl ov11_0212C1D0
	cmp r0, #0
	bne _0212AC38
	ldr r0, _0212AD80 ; =OVERLAY11_BSS_02169C68
	mov r1, #0xc0
	ldr r0, [r0, #4]
	ldr r3, _0212AD88 ; =ov11_0212B280
	ldrb r4, [r0, #0x67c]
	add r0, r0, #0x154
	mov r2, #0xe
	mla r0, r4, r1, r0
	bl thunk_FUN_overlay_11__02127904
	cmp r0, #0
	bne _0212AC38
	ldr r0, _0212AD84 ; =DAT_overlay_11_0216649c
	ldrb r1, [r0, #1]
	sub r1, r1, #1
	strb r1, [r0, #1]
_0212AC38:
	ldr r0, _0212AD84 ; =DAT_overlay_11_0216649c
	ldrb r1, [r0, #1]
	cmp r1, #1
	ldrneb r0, [r0, #1]
	cmpne r0, #3
	bne _0212ACF4
	cmp r7, #0
	mov r4, #0
	ble _0212ACC0
	ldr r5, _0212AD80 ; =OVERLAY11_BSS_02169C68
_0212AC60:
	mov r0, r4, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212AC8C
	ldr r0, [r5, #4]
	add r1, r0, r4, lsl #2
	ldr r0, [r1, #0x634]
	add r0, r0, #1
	str r0, [r1, #0x634]
	b _0212ACB4
_0212AC8C:
	bl ov11_0212C1D0
	cmp r0, #0
	beq _0212ACB4
	cmp r4, #0
	bne _0212ACB4
	ldr r0, [r5, #4]
	add r1, r0, r4, lsl #2
	ldr r0, [r1, #0x634]
	add r0, r0, #1
	str r0, [r1, #0x634]
_0212ACB4:
	add r4, r4, #1
	cmp r4, r7
	blt _0212AC60
_0212ACC0:
	ldr r0, _0212AD80 ; =OVERLAY11_BSS_02169C68
	mov r2, #0xc0
	ldr r1, [r0, #4]
	mov r0, #0
	ldrb r3, [r1, #0x67c]
	add r1, r1, #0x154
	mla r1, r3, r2, r1
	bl ov11_0212AED4
	ldr r0, _0212AD80 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	ldrb r0, [r1, #0x67c]
	rsb r0, r0, #1
	strb r0, [r1, #0x67c]
_0212ACF4:
	cmp r7, #0
	mov sb, #0
	ble _0212AD54
	ldr r4, _0212AD80 ; =OVERLAY11_BSS_02169C68
	mov r8, sb
	mov r5, #0xff
	mov sl, #0xc0
_0212AD10:
	mov r0, sb, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212AD44
	bl ov11_0212A640
	cmp r0, #1
	bne _0212AD44
	ldr r0, [r4, #4]
	ldrb r1, [r0, #0x67c]
	mla r0, r1, sl, r0
	add r0, r8, r0
	strb r5, [r0, #0x154]
_0212AD44:
	add sb, sb, #1
	cmp sb, r7
	add r8, r8, r6
	blt _0212AD10
_0212AD54:
	bl ov11_02127B08
	cmp r0, #4
	bne _0212AD6C
	bl ov11_0212C1D0
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
_0212AD6C:
	ldr r0, _0212AD84 ; =DAT_overlay_11_0216649c
	ldrb r1, [r0, #1]
	add r1, r1, #1
	strb r1, [r0, #1]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_0212AD80: .word OVERLAY11_BSS_02169C68
_0212AD84: .word DAT_overlay_11_0216649c
_0212AD88: .word ov11_0212B280

	arm_func_start ov11_0212AD8C
ov11_0212AD8C: ; 0x0212AD8C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r0, _0212AECC ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x67f]
	cmp r0, #0
	beq _0212ADE4
	bl ov11_02127B08
	cmp r0, #4
	beq _0212ADBC
	bl ov11_0212C1D0
	cmp r0, #0
	beq _0212ADE4
	arm_func_end ov11_0212AD8C
_0212ADBC:
	bl ov11_0212AB58
	ldr r0, _0212AED0 ; =DAT_overlay_11_0216649c
	ldrb r0, [r0, #1]
	cmp r0, #2
	bne _0212ADE4
	ldr r0, _0212AECC ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	strb r1, [r0, #0x67f]
	ldmia sp!, {r3, r4, r5, pc}
_0212ADE4:
	bl ov11_02127B08
	cmp r0, #4
	beq _0212ADFC
	bl ov11_0212C1D0
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
_0212ADFC:
	ldr r0, _0212AED0 ; =DAT_overlay_11_0216649c
	ldrb r0, [r0, #1]
	cmp r0, #4
	ldmneia sp!, {r3, r4, r5, pc}
	ldr r5, _0212AECC ; =OVERLAY11_BSS_02169C68
	mov r4, #1
_0212AE14:
	mov r0, r4, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212AE40
	ldr r0, [r5, #4]
	add r0, r0, r4, lsl #2
	ldr r0, [r0, #0x634]
	cmp r0, #3
	ble _0212AE64
	ldmia sp!, {r3, r4, r5, pc}
_0212AE40:
	cmp r4, #0
	bne _0212AE64
	bl ov11_0212C1D0
	cmp r0, #0
	beq _0212AE64
	ldr r0, [r5, #4]
	ldr r0, [r0, #0x634]
	cmp r0, #3
	ldmgtia sp!, {r3, r4, r5, pc}
_0212AE64:
	add r4, r4, #1
	cmp r4, #8
	blt _0212AE14
	bl ov11_0212A640
	cmp r0, #0
	bne _0212AEB8
	ldr r1, _0212AECC ; =OVERLAY11_BSS_02169C68
	mov r0, #0xc0
	ldr r2, [r1, #4]
	ldrb r1, [r2, #0x67c]
	add r2, r2, #0x154
	mla r0, r1, r0, r2
	bl ov11_0212B7E4
	ldr r1, _0212AECC ; =OVERLAY11_BSS_02169C68
	mov r0, #0xc0
	ldr r2, [r1, #4]
	ldrb r1, [r2, #0x67c]
	add r2, r2, #0x154
	rsb r1, r1, #1
	mla r0, r1, r0, r2
	bl ov11_0212B7E4
_0212AEB8:
	ldr r0, _0212AED0 ; =DAT_overlay_11_0216649c
	mov r1, #0
	strb r1, [r0, #1]
	bl ov11_0212AB58
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0212AECC: .word OVERLAY11_BSS_02169C68
_0212AED0: .word DAT_overlay_11_0216649c

	arm_func_start ov11_0212AED4
ov11_0212AED4: ; 0x0212AED4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr r0, _0212B0B4 ; =OVERLAY11_BSS_02169C68
	movs sl, r1
	ldr r1, [r0, #4]
	ldr r0, [r1, #0x630]
	sub r0, r0, #1
	str r0, [r1, #0x630]
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldrb r0, [sl]
	cmp r0, #0xb
	bne _0212AF14
	bl ov11_0212A640
	cmp r0, #1
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add sl, sl, #1
	b _0212AF20
	arm_func_end ov11_0212AED4
_0212AF14:
	bl ov11_0212A640
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0212AF20:
	ldr r0, _0212B0B4 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	ldrb r0, [r1, #0x67e]
	cmp r0, #0
	beq _0212AF40
	ldrb r0, [sl]
	tst r0, #1
	ldmneia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0212AF40:
	mov r0, #0
	strb r0, [r1, #0x67e]
	bl ov11_0212A640
	cmp r0, #1
	bne _0212B058
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212C1A8
	mov r7, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	add r5, r0, #1
	mov sb, #0
	cmp r5, #0
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r4, _0212B0B4 ; =OVERLAY11_BSS_02169C68
	mov r6, sb
	sub r8, r7, #1
	mov fp, #1
_0212AF98:
	ldrb r0, [sl]
	cmp r0, #0xff
	ldr r0, [r4, #4]
	bne _0212AFC0
	add r0, r0, #0x600
	ldrh r2, [r0, #0x58]
	mvn r1, fp, lsl sb
	and r1, r2, r1
	strh r1, [r0, #0x58]
	b _0212AFD4
_0212AFC0:
	add r1, r0, #0x600
	ldrh r2, [r1, #0x58]
	mov r0, #1
	orr r0, r2, r0, lsl sb
	strh r0, [r1, #0x58]
_0212AFD4:
	ldrb r1, [sl]
	cmp r1, #0xff
	addeq sl, sl, r7
	beq _0212B044
	cmp r1, #0xe
	addeq sl, sl, r7
	beq _0212B044
	ldr r2, [r4, #4]
	add r0, r2, sb
	ldrb r0, [r0, #0x663]
	cmp r0, #0
	beq _0212B010
	tst r1, #1
	addne sl, sl, r7
	bne _0212B044
_0212B010:
	add r0, r2, #0xe8
	add sl, sl, #1
	add r0, r0, #0x400
	ldr r3, _0212B0B8 ; =0x000005E6
	mov r1, sl
	add r0, r0, r6
	mov r2, r8
	bl ov11_0212C8B8
	ldr r0, [r4, #4]
	add sl, sl, r8
	add r1, r0, sb
	mov r0, #0
	strb r0, [r1, #0x663]
_0212B044:
	add sb, sb, #1
	cmp sb, r5
	add r6, r6, #0xc
	blt _0212AF98
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0212B058:
	ldr r2, _0212B0B4 ; =OVERLAY11_BSS_02169C68
	ldrb r1, [sl, #1]
	ldr r0, [r2, #4]
	ldr r3, _0212B0BC ; =0x000005FF
	add r0, r0, #0x600
	strh r1, [r0, #0x58]
	ldr r0, [r2, #4]
	add r1, sl, #4
	add r0, r0, #0x600
	ldrh r4, [r0, #0x58]
	mov r4, r4, lsl #8
	strh r4, [r0, #0x58]
	ldr r0, [r2, #4]
	ldrb r4, [sl, #2]
	add r0, r0, #0x600
	ldrh r5, [r0, #0x58]
	add r4, r5, r4
	strh r4, [r0, #0x58]
	ldr r0, [r2, #4]
	ldrb r2, [sl, #3]
	add r0, r0, #0x470
	bl ov11_0212C8B8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0212B0B4: .word OVERLAY11_BSS_02169C68
_0212B0B8: .word 0x000005E6
_0212B0BC: .word 0x000005FF

	arm_func_start ov11_0212B0C0
ov11_0212B0C0: ; 0x0212B0C0
	stmdb sp!, {r3, lr}
	ldr r3, _0212B10C ; =OVERLAY11_BSS_02169C68
	ldr lr, [r3, #4]
	add ip, lr, r0
	ldrb ip, [ip, #0x66b]
	cmp ip, #0
	beq _0212B104
	add r1, lr, #0x234
	add ip, r1, #0x400
	ldr r1, [ip, r0, lsl #2]
	mov r2, #0
	sub r1, r1, #1
	str r1, [ip, r0, lsl #2]
	ldr r1, [r3, #4]
	add r0, r1, r0
	strb r2, [r0, #0x66b]
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212B0C0
_0212B104:
	bl ov11_0212B110
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212B10C: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212B110
ov11_0212B110: ; 0x0212B110
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, _0212B254 ; =OVERLAY11_BSS_02169C68
	movs r5, r1
	ldr r1, [r2, #4]
	mov r6, r0
	add r0, r1, #0x234
	add r1, r0, #0x400
	ldr r0, [r1, r6, lsl #2]
	sub r0, r0, #1
	str r0, [r1, r6, lsl #2]
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r2, #4]
	add r0, r0, #0x63
	add r1, r0, #0x600
	ldrb r0, [r1, r6]
	cmp r0, #0
	beq _0212B160
	ldrb r0, [r5]
	tst r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
	arm_func_end ov11_0212B110
_0212B160:
	mov r0, #0
	strb r0, [r1, r6]
	bl ov11_0212A640
	cmp r0, #1
	bne _0212B1EC
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212C1A8
	mov r4, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	ldrb r0, [r5]
	tst r0, #2
	bne _0212B1CC
	ldr r0, _0212B254 ; =OVERLAY11_BSS_02169C68
	mov r1, #0xc
	ldr r0, [r0, #4]
	ldr r3, _0212B258 ; =0x0000065E
	add r0, r0, #0x7c
	add r0, r0, #0x400
	mla r0, r6, r1, r0
	mov r1, r5
	mov r2, r4
	bl ov11_0212C8B8
_0212B1CC:
	ldr r0, _0212B254 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	add r0, r0, #0x5b
	add r1, r0, #0x600
	ldrb r0, [r1, r6]
	add r0, r0, #1
	strb r0, [r1, r6]
	ldmia sp!, {r4, r5, r6, pc}
_0212B1EC:
	mov r0, r5
	mov r1, r6
	bl ov11_0212B4B4
	ldrb r0, [r5]
	tst r0, #2
	ldmneia sp!, {r4, r5, r6, pc}
	mov r0, #0xc
	ldr r1, _0212B254 ; =OVERLAY11_BSS_02169C68
	mul r4, r6, r0
	ldr r0, [r1, #4]
	add r0, r0, #0xe8
	add r0, r0, #0x400
	add r0, r0, r4
	bl ov11_0212CA20
	cmp r0, #0xb
	ldmltia sp!, {r4, r5, r6, pc}
	ldr r0, _0212B254 ; =OVERLAY11_BSS_02169C68
	ldr r3, _0212B25C ; =0x0000066E
	ldr r0, [r0, #4]
	add r1, r5, #1
	add r0, r0, #0xe8
	add r0, r0, #0x400
	add r0, r0, r4
	mov r2, #0xb
	bl ov11_0212C8B8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212B254: .word OVERLAY11_BSS_02169C68
_0212B258: .word 0x0000065E
_0212B25C: .word 0x0000066E

	arm_func_start ov11_0212B260
ov11_0212B260: ; 0x0212B260
	cmp r0, #0
	bxeq lr
	ldr r0, _0212B27C ; =DAT_overlay_11_0216649c
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_0212B27C: .word DAT_overlay_11_0216649c
	arm_func_end ov11_0212B260

	arm_func_start ov11_0212B280
ov11_0212B280: ; 0x0212B280
	cmp r0, #0
	bxeq lr
	ldr r0, _0212B29C ; =DAT_overlay_11_0216649c
	ldrb r1, [r0, #1]
	add r1, r1, #1
	strb r1, [r0, #1]
	bx lr
	.align 2, 0
_0212B29C: .word DAT_overlay_11_0216649c
	arm_func_end ov11_0212B280

	arm_func_start ov11_0212B2A0
ov11_0212B2A0: ; 0x0212B2A0
	stmdb sp!, {r4, lr}
	ldr r0, _0212B4A4 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl ov11_02128EE0
	cmp r0, #0x13
	ldmgeia sp!, {r4, pc}
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212C1A8
	mov r4, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	bl ov11_0212C1D0
	cmp r0, #0
	beq _0212B36C
	ldr r0, _0212B4A8 ; =DAT_overlay_11_0216649c
	ldrb r1, [r0]
	cmp r1, #2
	ldrneb r0, [r0]
	cmpne r0, #0
	bne _0212B36C
	ldr r1, _0212B4A8 ; =DAT_overlay_11_0216649c
	mov r0, #1
	ldrb r2, [r1]
	add r2, r2, #1
	strb r2, [r1]
	bl ov11_0212B260
	mov r0, r4, lsl #0x10
	ldr r1, _0212B4A4 ; =OVERLAY11_BSS_02169C68
	mov r2, r0, lsr #0x10
	ldr r4, [r1, #4]
	mov r1, #0x26
	ldrb r3, [r4, #0x67b]
	mov r0, #0
	mla r1, r3, r1, r4
	bl ov11_0212B110
	ldr r0, _0212B4A4 ; =OVERLAY11_BSS_02169C68
	ldr r2, [r0, #4]
	ldrb r1, [r2, #0x67b]
	rsb r1, r1, #1
	strb r1, [r2, #0x67b]
	ldr r1, [r0, #4]
	ldr r0, [r1, #0x630]
	add r0, r0, #1
	str r0, [r1, #0x630]
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212B2A0
_0212B36C:
	bl ov11_02127B08
	cmp r0, #4
	ldmneia sp!, {r4, pc}
	bl ov11_0212C154
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212B390
	bl ov11_0212C154
	ldmia sp!, {r4, pc}
_0212B390:
	ldr r0, _0212B4A8 ; =DAT_overlay_11_0216649c
	ldrb r1, [r0]
	cmp r1, #2
	ldrneb r0, [r0]
	cmpne r0, #0
	ldmneia sp!, {r4, pc}
	bl ov11_0212C154
	cmp r0, #0
	beq _0212B430
	ldr r2, _0212B4A8 ; =DAT_overlay_11_0216649c
	ldr r0, _0212B4A4 ; =OVERLAY11_BSS_02169C68
	ldrb r3, [r2]
	mov r1, r4, lsl #0x10
	ldr r4, [r0, #4]
	add r0, r3, #1
	strb r0, [r2]
	ldrb r2, [r4, #0x67b]
	mov r0, #0x26
	ldr r3, _0212B4AC ; =ov11_0212B260
	mla r0, r2, r0, r4
	mov r1, r1, lsr #0x10
	mov r2, #0xe
	bl thunk_FUN_overlay_11__02127904
	cmp r0, #0
	bne _0212B408
	ldr r0, _0212B4A8 ; =DAT_overlay_11_0216649c
	ldrb r1, [r0]
	sub r1, r1, #1
	strb r1, [r0]
	ldmia sp!, {r4, pc}
_0212B408:
	ldr r0, _0212B4A4 ; =OVERLAY11_BSS_02169C68
	ldr r2, [r0, #4]
	ldrb r1, [r2, #0x67b]
	rsb r1, r1, #1
	strb r1, [r2, #0x67b]
	ldr r1, [r0, #4]
	ldr r0, [r1, #0x630]
	add r0, r0, #1
	str r0, [r1, #0x630]
	ldmia sp!, {r4, pc}
_0212B430:
	bl ov11_02127AA4
	ldr r1, _0212B4B0 ; =0x0000FFFE
	tst r0, r1
	ldmeqia sp!, {r4, pc}
	ldr r1, _0212B4A8 ; =DAT_overlay_11_0216649c
	mov r0, #1
	ldrb r2, [r1]
	add r2, r2, #1
	strb r2, [r1]
	bl ov11_0212B260
	ldr r1, _0212B4A4 ; =OVERLAY11_BSS_02169C68
	mov r0, r4, lsl #0x10
	ldr r4, [r1, #4]
	mov r1, #0x26
	ldrb r3, [r4, #0x67b]
	mov r2, r0, lsr #0x10
	mov r0, #0
	mla r1, r3, r1, r4
	bl ov11_0212B110
	ldr r0, _0212B4A4 ; =OVERLAY11_BSS_02169C68
	ldr r2, [r0, #4]
	ldrb r1, [r2, #0x67b]
	rsb r1, r1, #1
	strb r1, [r2, #0x67b]
	ldr r1, [r0, #4]
	ldr r0, [r1, #0x630]
	add r0, r0, #1
	str r0, [r1, #0x630]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212B4A4: .word OVERLAY11_BSS_02169C68
_0212B4A8: .word DAT_overlay_11_0216649c
_0212B4AC: .word ov11_0212B260
_0212B4B0: .word 0x0000FFFE

	arm_func_start ov11_0212B4B4
ov11_0212B4B4: ; 0x0212B4B4
	stmdb sp!, {r3, lr}
	ldr ip, _0212B598 ; =OVERLAY11_BSS_02169C68
	mov lr, #0
	ldr r3, [ip, #4]
	mov r2, r1, lsl #1
	add r3, r3, r1, lsl #1
	add r3, r3, #0x600
	strh lr, [r3, #0xc]
	ldrb lr, [r0]
	and r3, lr, #0x10
	cmp r3, #0x10
	bne _0212B590
	and r3, lr, #0xc
	ands r3, r3, #0xff
	bne _0212B50C
	ldr r3, [ip, #4]
	add r3, r3, #0x20c
	add ip, r3, #0x400
	ldrh r3, [ip, r2]
	orr r3, r3, #0x40
	strh r3, [ip, r2]
	b _0212B574
	arm_func_end ov11_0212B4B4
_0212B50C:
	cmp r3, #4
	bne _0212B530
	ldr r3, [ip, #4]
	add r3, r3, #0x20c
	add ip, r3, #0x400
	ldrh r3, [ip, r2]
	orr r3, r3, #0x80
	strh r3, [ip, r2]
	b _0212B574
_0212B530:
	cmp r3, #8
	bne _0212B554
	ldr r3, [ip, #4]
	add r3, r3, #0x20c
	add ip, r3, #0x400
	ldrh r3, [ip, r2]
	orr r3, r3, #0x20
	strh r3, [ip, r2]
	b _0212B574
_0212B554:
	cmp r3, #0xc
	bne _0212B574
	ldr r3, [ip, #4]
	add r3, r3, #0x20c
	add ip, r3, #0x400
	ldrh r3, [ip, r2]
	orr r3, r3, #0x10
	strh r3, [ip, r2]
_0212B574:
	ldrb r2, [r0]
	ldr r0, _0212B598 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	mov r2, r2, asr #5
	and r2, r2, #7
	add r0, r0, r1
	strb r2, [r0, #0x61c]
_0212B590:
	mov r0, #1
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212B598: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212B59C
ov11_0212B59C: ; 0x0212B59C
	stmdb sp!, {r4, lr}
	ldr r1, _0212B6A8 ; =OVERLAY11_BSS_02169C68
	mov r4, r0
	ldr r0, [r1, #4]
	ldrb r0, [r0, #0x626]
	cmp r0, #0
	movne r0, #0
	ldmneia sp!, {r4, pc}
	bl ov11_0212BFAC
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, _0212B6A8 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	ldrb r0, [r1, #0x67d]
	cmp r0, #0
	subne r0, r0, #1
	strneb r0, [r1, #0x67d]
	ldr r1, _0212B6A8 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r1, #4]
	add r0, r0, #0x600
	ldrh r0, [r0, #0x24]
	tst r0, #0x40
	beq _0212B618
	ldrb r0, [r4]
	mov r2, #8
	orr r0, r0, #0x10
	strb r0, [r4]
	ldr r0, [r1, #4]
	strb r2, [r0, #0x67d]
	b _0212B680
	arm_func_end ov11_0212B59C
_0212B618:
	tst r0, #0x80
	beq _0212B63C
	ldrb r0, [r4]
	mov r2, #8
	orr r0, r0, #0x14
	strb r0, [r4]
	ldr r0, [r1, #4]
	strb r2, [r0, #0x67d]
	b _0212B680
_0212B63C:
	tst r0, #0x20
	beq _0212B660
	ldrb r0, [r4]
	mov r2, #8
	orr r0, r0, #0x18
	strb r0, [r4]
	ldr r0, [r1, #4]
	strb r2, [r0, #0x67d]
	b _0212B680
_0212B660:
	tst r0, #0x10
	beq _0212B680
	ldrb r0, [r4]
	mov r2, #8
	orr r0, r0, #0x1c
	strb r0, [r4]
	ldr r0, [r1, #4]
	strb r2, [r0, #0x67d]
_0212B680:
	ldr r0, _0212B6A8 ; =OVERLAY11_BSS_02169C68
	ldrb r2, [r4]
	ldr r1, [r0, #4]
	mov r0, #0
	ldrb r1, [r1, #0x627]
	mov r1, r1, lsl #5
	and r1, r1, #0xff
	orr r1, r2, r1
	strb r1, [r4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212B6A8: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212B6AC
ov11_0212B6AC: ; 0x0212B6AC
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r5, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212C1A8
	mov r4, r0
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	ldr r0, _0212B7E0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x680]
	cmp r0, #0
	moveq r0, #0
	movne r0, #1
	strb r0, [r5]
	bl ov11_0212A640
	cmp r0, #0
	bne _0212B70C
	mov r0, r5
	bl ov11_0212B59C
	arm_func_end ov11_0212B6AC
_0212B70C:
	ldr r0, _0212B7E0 ; =OVERLAY11_BSS_02169C68
	mov r2, #0
	ldr r1, [r0, #4]
	strb r2, [r1, #0x680]
	ldr r0, [r0, #4]
	add r0, r0, #0x148
	add r0, r0, #0x400
	bl ov11_0212C33C
	cmp r0, #0
	beq _0212B754
	ldrb r0, [r5]
	orr r0, r0, #2
	strb r0, [r5]
	cmp r0, #2
	bne _0212B7D4
	add sp, sp, #8
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_0212B754:
	ldr r0, _0212B7E0 ; =OVERLAY11_BSS_02169C68
	sub r4, r4, #1
	ldr r0, [r0, #4]
	add r3, r5, #1
	add r0, r0, #0x148
	add r1, sp, #0
	add r0, r0, #0x400
	mov r2, #1
	str r4, [sp, #4]
	str r3, [sp]
	bl ov11_0212C724
	cmp r0, #0
	bne _0212B798
	ldr r0, _0212B7E0 ; =OVERLAY11_BSS_02169C68
	mov r1, #1
	ldr r0, [r0, #4]
	strb r1, [r0, #0x680]
_0212B798:
	bl ov11_0212A640
	cmp r0, #1
	bne _0212B7D4
	ldr r0, _0212B7E0 ; =OVERLAY11_BSS_02169C68
	ldr r2, [r0, #4]
	ldrb r1, [r2, #0x65a]
	add r1, r1, #1
	strb r1, [r2, #0x65a]
	ldr r0, [r0, #4]
	ldrb r1, [r5]
	ldrb r0, [r0, #0x65a]
	mov r0, r0, lsl #4
	and r0, r0, #0xf0
	orr r0, r1, r0
	strb r0, [r5]
_0212B7D4:
	mov r0, #1
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0212B7E0: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212B7E4
ov11_0212B7E4: ; 0x0212B7E4
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	mov r1, #0xb
	ldr r0, _0212B89C ; =OVERLAY11_BSS_02169C68
	strb r1, [r4]
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x681]
	cmp r0, #0
	moveq r0, #0
	movne r0, #1
	strb r0, [r4, #1]
	bl ov11_02127AA4
	mov r1, r0, asr #8
	strb r1, [r4, #2]
	ldr r1, _0212B89C ; =OVERLAY11_BSS_02169C68
	strb r0, [r4, #3]
	ldr r0, [r1, #4]
	add r3, r4, #5
	add r0, r0, #0x168
	mov ip, #0xbb
	add r1, sp, #0
	add r0, r0, #0x400
	mov r2, #0
	str ip, [sp, #4]
	str r3, [sp]
	bl ov11_0212C724
	cmp r0, #0
	beq _0212B87C
	ldr r0, _0212B89C ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	strb r1, [r0, #0x681]
	ldr r0, [sp, #4]
	add sp, sp, #8
	rsb r0, r0, #0xbb
	strb r0, [r4, #4]
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212B7E4
_0212B87C:
	ldr r0, _0212B89C ; =OVERLAY11_BSS_02169C68
	mov r2, #1
	ldr r1, [r0, #4]
	mov r0, #0xbb
	strb r2, [r1, #0x681]
	strb r0, [r4, #4]
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212B89C: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212B8A0
ov11_0212B8A0: ; 0x0212B8A0
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl ov11_0212C154
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212B8D8
	bl ov11_0212C1D0
	cmp r0, #0
	addeq sp, sp, #8
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	arm_func_end ov11_0212B8A0
_0212B8D8:
	mov r0, #1
	str r0, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, _0212B934 ; =OVERLAY11_BSS_02169C68
	mov r1, r6
	ldr r0, [r0, #4]
	mov r2, r5
	add r0, r0, #0x148
	mov r3, r4
	add r0, r0, #0x400
	bl ov11_0212C5FC
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
	bl ov11_02128EE0
	cmp r0, #0xa
	bne _0212B928
	bl ov11_0212C2E4
_0212B928:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212B934: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212B938
ov11_0212B938: ; 0x0212B938
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl ov11_0212C154
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212B970
	bl ov11_0212C1D0
	cmp r0, #0
	addeq sp, sp, #8
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	arm_func_end ov11_0212B938
_0212B970:
	mov r1, #1
	str r1, [sp]
	str r1, [sp, #4]
	ldr r0, _0212B9C8 ; =OVERLAY11_BSS_02169C68
	mov r1, r6
	ldr r0, [r0, #4]
	mov r2, r5
	add r0, r0, #0x148
	mov r3, r4
	add r0, r0, #0x400
	bl ov11_0212C5FC
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
	bl ov11_02128EE0
	cmp r0, #0xa
	bne _0212B9BC
	bl ov11_0212C2E4
_0212B9BC:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212B9C8: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212B9CC
ov11_0212B9CC: ; 0x0212B9CC
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl ov11_0212C154
	cmp r0, #0
	addne sp, sp, #8
	mov r0, #0
	ldmneia sp!, {r4, r5, r6, pc}
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212BA14
	bl ov11_0212C1D0
	cmp r0, #0
	addeq sp, sp, #8
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	arm_func_end ov11_0212B9CC
_0212BA14:
	bl ov11_0212A640
	cmp r0, #1
	bne _0212BA38
	mov r0, r6
	mov r1, r5
	mov r2, r4
	bl ov11_0212B8A0
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
_0212BA38:
	mov r0, #1
	str r0, [sp]
	mov r1, #0
	str r1, [sp, #4]
	ldr r0, _0212BA94 ; =OVERLAY11_BSS_02169C68
	mov r1, r6
	ldr r0, [r0, #4]
	mov r2, r5
	add r0, r0, #0x168
	mov r3, r4
	add r0, r0, #0x400
	bl ov11_0212C5FC
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
	bl ov11_02128EE0
	cmp r0, #0xa
	bne _0212BA88
	bl ov11_0212C2E4
_0212BA88:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212BA94: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212BA98
ov11_0212BA98: ; 0x0212BA98
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl ov11_0212C154
	cmp r0, #0
	beq _0212BAC8
	bl ov11_0212C2E4
	add sp, sp, #8
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end ov11_0212BA98
_0212BAC8:
	mov r0, #0
	bl ov11_0212BEA0
	cmp r0, #0
	bne _0212BAEC
	bl ov11_0212C1D0
	cmp r0, #0
	addeq sp, sp, #8
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
_0212BAEC:
	bl ov11_0212A640
	cmp r0, #1
	bne _0212BB10
	mov r0, r6
	mov r1, r5
	mov r2, r4
	bl ov11_0212B938
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
_0212BB10:
	mov r1, #1
	str r1, [sp]
	str r1, [sp, #4]
	ldr r0, _0212BB68 ; =OVERLAY11_BSS_02169C68
	mov r1, r6
	ldr r0, [r0, #4]
	mov r2, r5
	add r0, r0, #0x168
	mov r3, r4
	add r0, r0, #0x400
	bl ov11_0212C5FC
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r4, r5, r6, pc}
	bl ov11_02128EE0
	cmp r0, #0xa
	bne _0212BB5C
	bl ov11_0212C2E4
_0212BB5C:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212BB68: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212BB6C
ov11_0212BB6C: ; 0x0212BB6C
	ldr ip, _0212BB78 ; =ov11_0212BA98
	mov r2, #0
	bx ip
	.align 2, 0
_0212BB78: .word ov11_0212BA98
	arm_func_end ov11_0212BB6C

	arm_func_start ov11_0212BB7C
ov11_0212BB7C: ; 0x0212BB7C
	stmdb sp!, {r4, lr}
	ldr r4, [sp, #8]
	bl ov11_0212CB10
	mov r1, #0xee
	ldr r0, _0212BBA8 ; =0x0000FFFF
	strb r1, [r4, #0xa]
	strh r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #4]
	str r0, [r4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212BBA8: .word 0x0000FFFF
	arm_func_end ov11_0212BB7C

	arm_func_start ov11_0212BBAC
ov11_0212BBAC: ; 0x0212BBAC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr r6, [sp, #0x28]
	mov sb, r0
	mov r8, r1
	mov r7, r2
	bl ov11_0212C9F4
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr fp, _0212BD50 ; =0x0000FFFF
	arm_func_end ov11_0212BBAC
_0212BBD0:
	ldrb r5, [r6, #0xa]
	cmp r5, #0xee
	bne _0212BBF0
	mov r0, sb
	bl ov11_0212C964
	mov r5, r0
	cmp r5, #0xee
	beq _0212BD3C
_0212BBF0:
	ldrsh r4, [sb, #4]
	strb r5, [r6, #0xa]
	ldrh sl, [r6, #8]
	cmp sl, fp
	bne _0212BC60
	mov r0, r5
	bl ov11_0212CBA4
	ldr r1, _0212BD54 ; =OVERLAY11_BSS_02169C68
	mov sl, r0
	ldr r1, [r1, #4]
	ldrb r0, [r1, #0x685]
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	cmp sl, fp
	bne _0212BC5C
	mov r0, sb
	bl ov11_0212C9F4
	cmp r0, #1
	strlth r4, [sb, #4]
	ldmltia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, sb
	bl ov11_0212C964
	mov sl, r0
	mov r0, sb
	bl ov11_0212C964
	ldrsh r4, [sb, #4]
	add sl, r0, sl, lsl #8
_0212BC5C:
	strh sl, [r6, #8]
_0212BC60:
	mov r0, r5
	bl ov11_0212CC34
	cmp r0, #0
	beq _0212BCF8
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _0212BC90
	ldrh r2, [r6, #8]
	mov r0, r5
	mov r1, r8
	bl ov11_0212CC90
	str r0, [r6, #4]
_0212BC90:
	ldr r2, [r6]
	mov r0, sb
	mov r1, r7
	sub r2, sl, r2
	bl ov11_0212C938
	ldr r3, [r6, #4]
	mov r4, r0
	cmp r3, #0
	beq _0212BCC8
	ldr r1, [r6]
	mov r0, r7
	mov r2, r4
	add r1, r3, r1
	bl MI_CpuCopy8
_0212BCC8:
	ldr r0, [r6]
	add r0, r0, r4
	str r0, [r6]
	cmp r0, sl
	blt _0212BD3C
	str r6, [sp]
	ldr r3, [r6, #4]
	mov r0, r8
	mov r1, r5
	mov r2, sl
	bl ov11_0212BB7C
	b _0212BD3C
_0212BCF8:
	mov r0, sb
	bl ov11_0212C9F4
	cmp r0, sl
	blt _0212BD34
	mov r0, sb
	mov r1, r7
	mov r2, sl
	bl ov11_0212C938
	mov r0, r8
	mov r1, r5
	mov r2, sl
	mov r3, r7
	str r6, [sp]
	bl ov11_0212BB7C
	b _0212BD3C
_0212BD34:
	strh r4, [sb, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0212BD3C:
	mov r0, sb
	bl ov11_0212C9F4
	cmp r0, #0
	bne _0212BBD0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0212BD50: .word 0x0000FFFF
_0212BD54: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212BD58
ov11_0212BD58: ; 0x0212BD58
	stmdb sp!, {r3, lr}
	ldr r0, _0212BDC4 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	ldrb r0, [r1, #0x687]
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	add r0, r1, #0x470
	bl ov11_0212CA54
	ldr r0, _0212BDC4 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	add r0, r0, #0x470
	bl ov11_0212C9F4
	cmp r0, #0
	ldmleia sp!, {r3, pc}
	ldr r0, _0212BDC4 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr ip, [r0, #4]
	mov r3, #1
	add r0, ip, #0x1e8
	add r0, r0, #0x400
	str r0, [sp]
	ldr r2, [ip, #0x460]
	add r0, ip, #0x470
	bl ov11_0212BBAC
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212BDC4: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212BD58

	arm_func_start ov11_0212BDC8
ov11_0212BDC8: ; 0x0212BDC8
	stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
	sub sp, sp, #4
	ldr r0, _0212BE9C ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, pc}
	ldrb r0, [r0, #0x687]
	cmp r0, #0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, r5, r6, r7, r8, pc}
	bl ov11_02128EE0
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212CE10
	add r7, r0, #1
	cmp r7, #0
	mov r6, #0
	addle sp, sp, #4
	ldmleia sp!, {r3, r4, r5, r6, r7, r8, pc}
	ldr r4, _0212BE9C ; =OVERLAY11_BSS_02169C68
	mov r8, r6
	mov r5, r6
	arm_func_end ov11_0212BDC8
_0212BE24:
	ldr r0, [r4, #4]
	add r0, r0, #0xe8
	add r0, r0, #0x400
	add r0, r0, r8
	bl ov11_0212CA54
	ldr r0, [r4, #4]
	add r0, r0, #0xe8
	add r0, r0, #0x400
	add r0, r0, r8
	bl ov11_0212C9F4
	cmp r0, #0
	ble _0212BE84
	ldr r2, [r4, #4]
	mov r1, r6
	add r0, r2, #0x188
	add r0, r0, #0x400
	add r0, r0, r8
	str r0, [sp]
	add r0, r2, #0xe8
	add r0, r0, #0x400
	ldr r2, [r2, #0x460]
	mov r3, r5
	add r0, r0, r8
	bl ov11_0212BBAC
_0212BE84:
	add r6, r6, #1
	cmp r6, r7
	add r8, r8, #0xc
	blt _0212BE24
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
	.align 2, 0
_0212BE9C: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212BEA0
ov11_0212BEA0: ; 0x0212BEA0
	stmdb sp!, {r4, lr}
	ldr r1, _0212BF44 ; =OVERLAY11_BSS_02169C68
	mov r4, r0
	ldr r0, [r1, #4]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	bl ov11_02128EE0
	cmp r0, #0x13
	movge r0, #0
	ldmgeia sp!, {r4, pc}
	bl ov11_0212BF7C
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r4, pc}
	bl ov11_02127B08
	cmp r0, #4
	movne r0, #0
	ldmneia sp!, {r4, pc}
	bl ov11_0212C154
	cmp r4, r0
	moveq r0, #1
	ldmeqia sp!, {r4, pc}
	bl ov11_0212C154
	cmp r0, #0
	bne _0212BF20
	bl ov11_02127AA4
	mov r1, #1
	tst r0, r1, lsl r4
	beq _0212BF3C
	mov r0, r1
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212BEA0
_0212BF20:
	ldr r1, _0212BF44 ; =OVERLAY11_BSS_02169C68
	mov r0, #1
	ldr r1, [r1, #4]
	add r1, r1, #0x600
	ldrh r1, [r1, #0x58]
	tst r1, r0, lsl r4
	ldmneia sp!, {r4, pc}
_0212BF3C:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212BF44: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212BF48
ov11_0212BF48: ; 0x0212BF48
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, #0
	mov r5, r4
	arm_func_end ov11_0212BF48
_0212BF54:
	mov r0, r5, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212BEA0
	cmp r0, #0
	add r5, r5, #1
	addne r4, r4, #1
	cmp r5, #8
	blt _0212BF54
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start ov11_0212BF7C
ov11_0212BF7C: ; 0x0212BF7C
	stmdb sp!, {r3, lr}
	ldr r0, _0212BFA8 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0212BFA0
	bl ov11_02128EE0
	cmp r0, #0x13
	movge r0, #1
	ldmgeia sp!, {r3, pc}
	arm_func_end ov11_0212BF7C
_0212BFA0:
	bl ov11_02129770
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212BFA8: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212BFAC
ov11_0212BFAC: ; 0x0212BFAC
	ldr r0, _0212BFD0 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	moveq r0, #1
	bxeq lr
	add r0, r0, #0x600
	ldrh r0, [r0, #0x24]
	and r0, r0, #0x8000
	bx lr
	.align 2, 0
_0212BFD0: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212BFAC

	arm_func_start ov11_0212BFD4
ov11_0212BFD4: ; 0x0212BFD4
	stmdb sp!, {r3, lr}
	ldr r0, _0212C098 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r0, #4]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	ldrb r0, [r1, #0x677]
	cmp r0, #1
	beq _0212C000
	cmp r0, #3
	beq _0212C05C
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212BFD4
_0212C000:
	bl ov11_0212A640
	cmp r0, #1
	mov r0, #0xb
	bne _0212C028
	ldr r1, _0212C098 ; =OVERLAY11_BSS_02169C68
	ldr r1, [r1, #4]
	add r1, r1, #0x278
	add r1, r1, #0x400
	bl ov11_0212C198
	b _0212C040
_0212C028:
	ldr r1, _0212C098 ; =OVERLAY11_BSS_02169C68
	mov r2, #1
	ldr r1, [r1, #4]
	add r1, r1, #0x278
	add r1, r1, #0x400
	bl ov11_0212BA98
_0212C040:
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _0212C098 ; =OVERLAY11_BSS_02169C68
	mov r1, #2
	ldr r0, [r0, #4]
	strb r1, [r0, #0x677]
	ldmia sp!, {r3, pc}
_0212C05C:
	add r0, r1, #0x278
	add r1, r0, #0x400
	mov r0, #0xc
	bl ov11_0212C198
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, _0212C098 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x678]
	bl ov11_0212A5F8
	ldr r0, _0212C098 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	strb r1, [r0, #0x677]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212C098: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212C09C
ov11_0212C09C: ; 0x0212C09C
	stmdb sp!, {r4, lr}
	mov r4, r2
	bl ov11_0212C154
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	ldr r0, _0212C0D0 ; =OVERLAY11_BSS_02169C68
	mov r2, #1
	ldr r1, [r0, #4]
	strb r2, [r1, #0x677]
	ldrb r1, [r4]
	ldr r0, [r0, #4]
	strb r1, [r0, #0x678]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212C0D0: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212C09C

	arm_func_start ov11_0212C0D4
ov11_0212C0D4: ; 0x0212C0D4
	stmdb sp!, {r4, lr}
	mov r4, r2
	bl ov11_0212C154
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, _0212C108 ; =OVERLAY11_BSS_02169C68
	ldrb r3, [r4]
	ldr r2, [r0, #4]
	mov r1, #3
	strb r3, [r2, #0x678]
	ldr r0, [r0, #4]
	strb r1, [r0, #0x677]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212C108: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212C0D4

	arm_func_start ov11_0212C10C
ov11_0212C10C: ; 0x0212C10C
	stmdb sp!, {r4, lr}
	mov r4, r2
	bl ov11_0212C154
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	ldr r0, _0212C150 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	ldrb r0, [r0, #0x677]
	cmp r0, #2
	ldmneia sp!, {r4, pc}
	ldrb r0, [r4]
	bl ov11_0212A5F8
	ldr r0, _0212C150 ; =OVERLAY11_BSS_02169C68
	mov r1, #0
	ldr r0, [r0, #4]
	strb r1, [r0, #0x677]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212C150: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212C10C

	arm_func_start ov11_0212C154
ov11_0212C154: ; 0x0212C154
	stmdb sp!, {r3, lr}
	ldr r0, _0212C194 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _0212C18C
	bl ov11_02128EE0
	cmp r0, #0x13
	bge _0212C18C
	bl ov11_0212C1D0
	cmp r0, #0
	movne r0, #0
	ldmneia sp!, {r3, pc}
	bl ov11_02128330
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212C154
_0212C18C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212C194: .word OVERLAY11_BSS_02169C68

	arm_func_start ov11_0212C198
ov11_0212C198: ; 0x0212C198
	ldr ip, _0212C1A4 ; =ov11_0212B938
	mov r2, #0
	bx ip
	.align 2, 0
_0212C1A4: .word ov11_0212B938
	arm_func_end ov11_0212C198

	arm_func_start ov11_0212C1A8
ov11_0212C1A8: ; 0x0212C1A8
	stmdb sp!, {r3, lr}
	bl ov11_0212CE10
	cmp r0, #5
	movhs r0, #0xc
	ldmhsia sp!, {r3, pc}
	bl ov11_0212A640
	cmp r0, #0
	moveq r0, #0xc
	movne r0, #0x26
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212C1A8

	arm_func_start ov11_0212C1D0
ov11_0212C1D0: ; 0x0212C1D0
	ldr r0, _0212C1E8 ; =OVERLAY11_BSS_02169C68
	ldr r0, [r0, #4]
	cmp r0, #0
	ldrneb r0, [r0, #0x682]
	moveq r0, #0
	bx lr
	.align 2, 0
_0212C1E8: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212C1D0

	arm_func_start ov11_0212C1EC
ov11_0212C1EC: ; 0x0212C1EC
	stmdb sp!, {r3, lr}
	bl ov11_02129830
	cmp r0, #0
	bne _0212C214
	bl ov11_0212C154
	cmp r0, #0
	bne _0212C214
	add r1, sp, #0
	mov r0, #2
	bl ov11_0212BB6C
	arm_func_end ov11_0212C1EC
_0212C214:
	bl ov11_02129858
	ldmia sp!, {r3, pc}

	arm_func_start ov11_0212C21C
ov11_0212C21C: ; 0x0212C21C
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x1c
	mov r4, r0
	add r0, sp, #0xc
	bl RTC_GetDate
	add r0, sp, #0
	bl RTC_GetTime
	mov r0, #0
	mov r2, r0, lsl #4
	ldr r1, [sp, #0xc]
	ldr r3, [sp, #0x10]
	orr r2, r2, r1, lsr #28
	adds r3, r3, r1, lsl #4
	adc r1, r2, #0
	mov r1, r1, lsl #5
	ldr r2, [sp, #0x14]
	orr r1, r1, r3, lsr #27
	adds r2, r2, r3, lsl #5
	adc r1, r1, #0
	mov r1, r1, lsl #5
	ldr r3, [sp]
	orr r1, r1, r2, lsr #27
	adds r2, r3, r2, lsl #5
	adc r1, r1, #0
	mov r1, r1, lsl #6
	ldr r3, [sp, #4]
	orr r1, r1, r2, lsr #26
	adds r2, r3, r2, lsl #6
	ldr r0, [sp, #8]
	adc r1, r1, #0
	add r3, r0, #0x25
	mov r0, r1, lsl #6
	adds r1, r3, r2, lsl #6
	orr r0, r0, r2, lsr #26
	str r1, [r4]
	adc r1, r0, #0
	str r1, [r4, #4]
	ldr r0, _0212C2D8 ; =0x6C078965
	ldr r1, _0212C2DC ; =0x5D588B65
	str r0, [r4, #8]
	ldr r0, _0212C2E0 ; =0x00269EC3
	str r1, [r4, #0xc]
	str r0, [r4, #0x10]
	mov r0, #0
	str r0, [r4, #0x14]
	add sp, sp, #0x1c
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0212C2D8: .word 0x6C078965
_0212C2DC: .word 0x5D588B65
_0212C2E0: .word 0x00269EC3
	arm_func_end ov11_0212C21C

	arm_func_start ov11_0212C2E4
ov11_0212C2E4: ; 0x0212C2E4
	ldr r0, _0212C2F8 ; =OVERLAY11_BSS_02169C68
	mov r1, #1
	ldr r0, [r0, #4]
	strb r1, [r0, #0x685]
	bx lr
	.align 2, 0
_0212C2F8: .word OVERLAY11_BSS_02169C68
	arm_func_end ov11_0212C2E4

	arm_func_start ov11_0212C2FC
ov11_0212C2FC: ; 0x0212C2FC
	mov r0, #0x20
	bx lr
	arm_func_end ov11_0212C2FC

	arm_func_start ov11_0212C304
ov11_0212C304: ; 0x0212C304
	ldr r3, [r0, #0x1c]
	ldr r0, [r0, #0x18]
	cmp r3, #0
	mov r2, #0
	ble _0212C334
	arm_func_end ov11_0212C304
_0212C318:
	ldrb r1, [r0, #0xe]
	cmp r1, #0
	bxeq lr
	add r2, r2, #1
	cmp r2, r3
	add r0, r0, #0x10
	blt _0212C318
_0212C334:
	mov r0, #0
	bx lr

	arm_func_start ov11_0212C33C
ov11_0212C33C: ; 0x0212C33C
	ldr r3, [r0, #0x1c]
	ldr r1, [r0, #0x18]
	cmp r3, #0
	mov r2, #0
	ble _0212C370
	arm_func_end ov11_0212C33C
_0212C350:
	ldrb r0, [r1, #0xe]
	cmp r0, #0
	movne r0, #0
	bxne lr
	add r2, r2, #1
	cmp r2, r3
	add r1, r1, #0x10
	blt _0212C350
_0212C370:
	mov r0, #1
	bx lr

	arm_func_start ov11_0212C378
ov11_0212C378: ; 0x0212C378
	ldr r1, [r0]
	cmp r1, #0
	beq _0212C3B0
	ldr r1, [r1, #8]
	cmp r1, #0
	moveq r1, #0
	streq r1, [r0]
	streq r1, [r0, #4]
	beq _0212C3A8
	str r1, [r0]
	mov r0, #0
	str r0, [r1, #4]
	arm_func_end ov11_0212C378
_0212C3A8:
	mov r0, #1
	bx lr
_0212C3B0:
	mov r0, #0
	bx lr

	arm_func_start ov11_0212C3B8
ov11_0212C3B8: ; 0x0212C3B8
	ldr r2, [r0]
	strb r1, [r2]
	ldr r1, [r0]
	add r1, r1, #1
	str r1, [r0]
	ldr r1, [r0, #4]
	subs r1, r1, #1
	str r1, [r0, #4]
	moveq r0, #1
	movne r0, #0
	bx lr
	arm_func_end ov11_0212C3B8

	arm_func_start ov11_0212C3E4
ov11_0212C3E4: ; 0x0212C3E4
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	ldrb r0, [r5, #0xe]
	mov r4, r1
	bl ov11_0212CBA4
	mov r6, r0
	ldr r1, _0212C49C ; =0x0000FFFF
	ldr r0, [r4, #4]
	cmp r6, r1
	bne _0212C428
	cmp r0, #3
	bge _0212C444
	ldrb r1, [r5, #0xf]
	mov r0, #1
	bic r1, r1, #1
	strb r1, [r5, #0xf]
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end ov11_0212C3E4
_0212C428:
	cmp r0, #1
	bge _0212C444
	ldrb r1, [r5, #0xf]
	mov r0, #1
	bic r1, r1, #1
	strb r1, [r5, #0xf]
	ldmia sp!, {r4, r5, r6, pc}
_0212C444:
	ldrb r1, [r5, #0xe]
	mov r0, r4
	bl ov11_0212C3B8
	ldr r0, _0212C49C ; =0x0000FFFF
	cmp r6, r0
	strneh r6, [r5, #0xc]
	bne _0212C484
	ldrh r1, [r5, #0xc]
	mov r0, r4
	mov r1, r1, asr #8
	and r1, r1, #0xff
	bl ov11_0212C3B8
	ldrh r1, [r5, #0xc]
	mov r0, r4
	and r1, r1, #0xff
	bl ov11_0212C3B8
_0212C484:
	ldrb r1, [r5, #0xf]
	mov r0, #0
	bic r1, r1, #1
	orr r1, r1, #1
	strb r1, [r5, #0xf]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212C49C: .word 0x0000FFFF

	arm_func_start ov11_0212C4A0
ov11_0212C4A0: ; 0x0212C4A0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldrb r0, [r7, #0xe]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	bl ov11_0212CBA4
	ldr r1, _0212C5F8 ; =0x0000FFFF
	cmp r0, r1
	moveq r2, #3
	ldrh r0, [r7, #0xc]
	movne r2, #1
	ldr r1, [r6, #4]
	add r0, r0, r2
	cmp r1, r0
	bge _0212C4EC
	cmp r4, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end ov11_0212C4A0
_0212C4EC:
	ldrb r0, [r7, #0xf]
	mov r0, r0, lsl #0x1f
	mov r0, r0, lsr #0x1f
	cmp r0, #1
	beq _0212C518
	mov r0, r7
	mov r1, r6
	bl ov11_0212C3E4
	cmp r0, #0
	movne r0, #0
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
_0212C518:
	ldrb r0, [r7, #0xf]
	ldrh r3, [r7, #0xc]
	ldr r2, [r6, #4]
	mov r0, r0, lsl #0x1e
	cmp r2, r3
	bge _0212C5A4
	movs r0, r0, lsr #0x1f
	beq _0212C548
	ldr r1, [r6]
	mov r0, r5
	bl ov11_0212C938
	b _0212C574
_0212C548:
	cmp r2, #0
	mov r2, #0
	ble _0212C574
_0212C554:
	ldr r1, [r7]
	ldr r0, [r6]
	ldrb r1, [r1, r2]
	strb r1, [r0, r2]
	ldr r0, [r6, #4]
	add r2, r2, #1
	cmp r2, r0
	blt _0212C554
_0212C574:
	ldr r2, [r7]
	ldr r0, [r6, #4]
	mvn r1, #0
	add r0, r2, r0
	str r0, [r7]
	ldrh r3, [r7, #0xc]
	ldr r2, [r6, #4]
	mov r0, #1
	sub r2, r3, r2
	strh r2, [r7, #0xc]
	str r1, [r6, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
_0212C5A4:
	movs r0, r0, lsr #0x1f
	beq _0212C5C0
	ldr r1, [r6]
	mov r0, r5
	mov r2, r3
	bl ov11_0212C938
	b _0212C5D0
_0212C5C0:
	ldr r0, [r7]
	ldr r1, [r6]
	mov r2, r3
	bl MI_CpuCopy8
_0212C5D0:
	ldrh r1, [r7, #0xc]
	ldr r2, [r6]
	mov r0, #1
	add r1, r2, r1
	str r1, [r6]
	ldrh r1, [r7, #0xc]
	ldr r2, [r6, #4]
	sub r1, r2, r1
	str r1, [r6, #4]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0212C5F8: .word 0x0000FFFF

	arm_func_start ov11_0212C5FC
ov11_0212C5FC: ; 0x0212C5FC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	mov r8, r0
	mov r7, r1
	mov r6, r2
	mov sb, r3
	bl ov11_0212C304
	movs r4, r0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r0, r7
	bl ov11_0212CBA4
	mov r5, r0
	ldr r1, _0212C6BC ; =0x0000FFFF
	ldr r0, [sp, #0x24]
	cmp r5, r1
	moveq r5, sb
	cmp r0, #0
	beq _0212C684
	ldr r0, [r8, #0x14]
	bl ov11_0212CA20
	add r1, r5, #3
	cmp r1, r0
	movge r0, #0
	ldmgeia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	ldr r0, [r8, #0x14]
	mov r1, r6
	mov r2, r5
	mov r3, #0x108
	bl ov11_0212C8B8
	ldr r0, [r8, #0x14]
	bl ov11_0212CA54
	ldrb r0, [r4, #0xf]
	orr r0, r0, #2
	strb r0, [r4, #0xf]
	arm_func_end ov11_0212C5FC
_0212C684:
	strh r5, [r4, #0xc]
	strb r7, [r4, #0xe]
	str r6, [r4]
	ldr r0, [r8, #4]
	cmp r0, #0
	streq r4, [r8, #4]
	streq r4, [r8]
	beq _0212C6B4
	str r4, [r0, #8]
	ldr r0, [r8, #4]
	str r0, [r4, #4]
	str r4, [r8, #4]
_0212C6B4:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_0212C6BC: .word 0x0000FFFF

	arm_func_start ov11_0212C6C0
ov11_0212C6C0: ; 0x0212C6C0
	ldr r1, [r0, #0x10]
	cmp r1, #0
	movne r0, r1
	bxne lr
	ldr r1, [r0]
	cmp r1, #0
	movne r0, r1
	bxne lr
	ldr r0, [r0, #8]
	cmp r0, #0
	moveq r0, #0
	bx lr
	arm_func_end ov11_0212C6C0

	arm_func_start ov11_0212C6F0
ov11_0212C6F0: ; 0x0212C6F0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x10]
	cmp r1, #0
	movne r0, #0
	strne r0, [r4, #0x10]
	ldmneia sp!, {r4, pc}
	bl ov11_0212C378
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	add r0, r4, #8
	bl ov11_0212C378
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212C6F0

	arm_func_start ov11_0212C724
ov11_0212C724: ; 0x0212C724
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sb, r1
	ldr r1, [sb, #4]
	mov sl, r0
	mov r8, r2
	cmp r1, #0
	mov r7, #1
	ble _0212C7BC
	mov r5, #0
	mov fp, #0x10
	mvn r4, #0
	arm_func_end ov11_0212C724
_0212C750:
	mov r0, sl
	bl ov11_0212C6C0
	movs r6, r0
	beq _0212C7BC
	mov r0, sl
	bl ov11_0212C6F0
	ldr r2, [sl, #0x14]
	mov r0, r6
	mov r3, r7
	mov r1, sb
	bl ov11_0212C4A0
	cmp r0, #0
	streq r6, [sl, #0x10]
	beq _0212C7BC
	ldr r0, [sb, #4]
	cmp r0, r4
	streq r6, [sl, #0x10]
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, r6
	mov r1, r5
	mov r2, fp
	bl MI_CpuFill8
	ldr r0, [sb, #4]
	mov r7, r8
	cmp r0, #0
	bgt _0212C750
_0212C7BC:
	ldr r0, [sb, #4]
	mov r2, #0
	cmp r0, #0
	ble _0212C7F4
	mov r1, #0xee
_0212C7D0:
	ldr r0, [sb]
	add r2, r2, #1
	strb r1, [r0]
	ldr r0, [sb]
	add r0, r0, #1
	str r0, [sb]
	ldr r0, [sb, #4]
	cmp r2, r0
	blt _0212C7D0
_0212C7F4:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}

	arm_func_start ov11_0212C7FC
ov11_0212C7FC: ; 0x0212C7FC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, r1
	mov r5, r2
	mov r1, #0
	mov r2, #0x20
	mov r7, r0
	bl MI_CpuFill8
	mov r4, r6, lsl #4
	mov r0, r4
	bl _Z10Heap_Allocm
	mov r2, r4
	mov r1, #0
	str r0, [r7, #0x18]
	bl MI_CpuFill8
	str r6, [r7, #0x1c]
	str r5, [r7, #0x14]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end ov11_0212C7FC

	arm_func_start ov11_0212C840
ov11_0212C840: ; 0x0212C840
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4, #0x1c]
	ldr r0, [r4, #0x18]
	mov r2, r1, lsl #4
	mov r1, #0
	bl MI_CpuFill8
	mov r0, #0
	str r0, [r4]
	str r0, [r4, #4]
	str r0, [r4, #8]
	str r0, [r4, #0xc]
	str r0, [r4, #0x10]
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212C840

	arm_func_start ov11_0212C878
ov11_0212C878: ; 0x0212C878
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x18]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r4, #0x18]
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212C878

	arm_func_start ov11_0212C89C
ov11_0212C89C: ; 0x0212C89C
	str r1, [r0]
	strh r2, [r0, #0xa]
	mov r1, #0
	strh r1, [r0, #4]
	strh r1, [r0, #6]
	strh r1, [r0, #8]
	bx lr
	arm_func_end ov11_0212C89C

	arm_func_start ov11_0212C8B8
ov11_0212C8B8: ; 0x0212C8B8
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r6, r2
	mov r8, r0
	mov r7, r1
	bl ov11_0212CA20
	cmp r0, r6
	bgt _0212C8DC
	bl ov11_0212C2E4
	ldmia sp!, {r4, r5, r6, r7, r8, pc}
	arm_func_end ov11_0212C8B8
_0212C8DC:
	ldrsh r4, [r8, #8]
	ldrsh r0, [r8, #8]
	mov r5, #0
	add r0, r0, r6
	cmp r4, r0
	bge _0212C924
_0212C8F4:
	mov r0, r8
	mov r1, r4
	bl ov11_0212CA38
	ldrb r2, [r7, r5]
	ldr r1, [r8]
	add r4, r4, #1
	strb r2, [r1, r0]
	ldrsh r0, [r8, #8]
	add r5, r5, #1
	add r0, r0, r6
	cmp r4, r0
	blt _0212C8F4
_0212C924:
	mov r0, r8
	mov r1, r4
	bl ov11_0212CA38
	strh r0, [r8, #8]
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov11_0212C938
ov11_0212C938: ; 0x0212C938
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	bl ov11_0212C97C
	mov r4, r0
	ldrsh r1, [r5, #4]
	mov r0, r5
	add r1, r1, r4
	bl ov11_0212CA38
	strh r0, [r5, #4]
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov11_0212C938

	arm_func_start ov11_0212C964
ov11_0212C964: ; 0x0212C964
	stmdb sp!, {r3, lr}
	add r1, sp, #0
	mov r2, #1
	bl ov11_0212C938
	ldrb r0, [sp]
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212C964

	arm_func_start ov11_0212C97C
ov11_0212C97C: ; 0x0212C97C
	stmdb sp!, {r4, r5, r6, r7, r8, lr}
	mov r8, r0
	ldrsh r4, [r8, #4]
	mov r6, r2
	mov r7, r1
	add r0, r4, r6
	cmp r4, r0
	mov r5, #0
	bge _0212C9EC
	arm_func_end ov11_0212C97C
_0212C9A0:
	mov r0, r8
	mov r1, r4
	bl ov11_0212CA38
	ldrsh r1, [r8, #6]
	cmp r1, r0
	moveq r0, r5
	ldmeqia sp!, {r4, r5, r6, r7, r8, pc}
	mov r0, r8
	mov r1, r4
	bl ov11_0212CA38
	ldr r1, [r8]
	add r4, r4, #1
	ldrb r0, [r1, r0]
	strb r0, [r7, r5]
	ldrsh r0, [r8, #4]
	add r5, r5, #1
	add r0, r0, r6
	cmp r4, r0
	blt _0212C9A0
_0212C9EC:
	mov r0, r5
	ldmia sp!, {r4, r5, r6, r7, r8, pc}

	arm_func_start ov11_0212C9F4
ov11_0212C9F4: ; 0x0212C9F4
	ldrsh r2, [r0, #4]
	ldrsh r1, [r0, #6]
	cmp r2, r1
	ldrlesh r0, [r0, #6]
	suble r0, r0, r2
	bxle lr
	ldrsh r1, [r0, #0xa]
	ldrsh r0, [r0, #6]
	add r0, r1, r0
	sub r0, r0, r2
	bx lr
	arm_func_end ov11_0212C9F4

	arm_func_start ov11_0212CA20
ov11_0212CA20: ; 0x0212CA20
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov11_0212C9F4
	ldrsh r1, [r4, #0xa]
	sub r0, r1, r0
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212CA20

	arm_func_start ov11_0212CA38
ov11_0212CA38: ; 0x0212CA38
	stmdb sp!, {r3, lr}
	mov r2, r0
	mov r0, r1
	ldrsh r1, [r2, #0xa]
	bl _s32_div_f
	mov r0, r1
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212CA38

	arm_func_start ov11_0212CA54
ov11_0212CA54: ; 0x0212CA54
	ldrsh r1, [r0, #8]
	strh r1, [r0, #6]
	bx lr
	arm_func_end ov11_0212CA54

	arm_func_start ov11_0212CA60
ov11_0212CA60: ; 0x0212CA60
	stmdb sp!, {r4, r5, r6, lr}
	ldr r3, _0212CADC ; =OVERLAY11_BSS_02169C70
	mov r6, r0
	ldr r0, [r3]
	mov r5, r1
	mov r4, r2
	cmp r0, #0
	bne _0212CA90
	mov r0, #0x18
	bl _Z10Heap_Allocm
	ldr r1, _0212CADC ; =OVERLAY11_BSS_02169C70
	str r0, [r1]
	arm_func_end ov11_0212CA60
_0212CA90:
	ldr r0, _0212CADC ; =OVERLAY11_BSS_02169C70
	mov r3, #0
	ldr r1, [r0]
	mov r2, r3
	str r6, [r1]
	ldr r1, [r0]
	str r5, [r1, #4]
	ldr r1, [r0]
	str r4, [r1, #8]
_0212CAB4:
	ldr r1, [r0]
	add r1, r1, r3
	add r3, r3, #1
	strb r2, [r1, #0xc]
	cmp r3, #8
	blt _0212CAB4
	ldr r0, _0212CADC ; =OVERLAY11_BSS_02169C70
	ldr r0, [r0]
	strb r2, [r0, #0x14]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212CADC: .word OVERLAY11_BSS_02169C70

	arm_func_start ov11_0212CAE0
ov11_0212CAE0: ; 0x0212CAE0
	stmdb sp!, {r3, lr}
	ldr r0, _0212CB0C ; =OVERLAY11_BSS_02169C70
	ldr r0, [r0]
	cmp r0, #0
	ldmeqia sp!, {r3, pc}
	beq _0212CAFC
	bl _Z9Heap_FreePv
	arm_func_end ov11_0212CAE0
_0212CAFC:
	ldr r0, _0212CB0C ; =OVERLAY11_BSS_02169C70
	mov r1, #0
	str r1, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212CB0C: .word OVERLAY11_BSS_02169C70

	arm_func_start ov11_0212CB10
ov11_0212CB10: ; 0x0212CB10
	stmdb sp!, {r3, lr}
	cmp r1, #0x16
	bge _0212CB30
	mov ip, #0xc
	mul ip, r1, ip
	ldr r1, _0212CB9C ; =DAT_overlay_11_021629b4
	ldr lr, [r1, ip]
	b _0212CB64
	arm_func_end ov11_0212CB10
_0212CB30:
	ldr ip, _0212CBA0 ; =OVERLAY11_BSS_02169C70
	ldr lr, [ip]
	ldr ip, [lr, #4]
	add ip, ip, #0x16
	cmp r1, ip
	ble _0212CB50
	bl ov11_0212C2E4
	ldmia sp!, {r3, pc}
_0212CB50:
	sub ip, r1, #0x16
	mov r1, #0xc
	mul r1, ip, r1
	ldr ip, [lr]
	ldr lr, [ip, r1]
_0212CB64:
	cmp lr, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, _0212CBA0 ; =OVERLAY11_BSS_02169C70
	ldr ip, [r1]
	mov r1, r2
	cmp ip, #0
	mov r2, r3
	beq _0212CB90
	ldr r3, [ip, #8]
	blx lr
	ldmia sp!, {r3, pc}
_0212CB90:
	mov r3, #0
	blx lr
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212CB9C: .word DAT_overlay_11_021629b4
_0212CBA0: .word OVERLAY11_BSS_02169C70

	arm_func_start ov11_0212CBA4
ov11_0212CBA4: ; 0x0212CBA4
	stmdb sp!, {r3, lr}
	cmp r0, #0x16
	mov r3, #0
	bge _0212CBC8
	mov r1, #0xc
	mul r1, r0, r1
	ldr r0, _0212CC2C ; =PTR_LAB_overlay_11_0212ccf0_overlay_11_021629b8
	ldr r0, [r0, r1]
	b _0212CC14
	arm_func_end ov11_0212CBA4
_0212CBC8:
	ldr r1, _0212CC30 ; =OVERLAY11_BSS_02169C70
	ldr r2, [r1]
	cmp r2, #0
	bne _0212CBE4
	bl ov11_0212C2E4
	mov r0, #0
	ldmia sp!, {r3, pc}
_0212CBE4:
	ldr r1, [r2, #4]
	add r1, r1, #0x16
	cmp r0, r1
	ble _0212CC00
	bl ov11_0212C2E4
	mov r0, #0
	ldmia sp!, {r3, pc}
_0212CC00:
	ldr r2, [r2]
	sub r1, r0, #0x16
	mov r0, #0xc
	mla r0, r1, r0, r2
	ldr r0, [r0, #4]
_0212CC14:
	cmp r0, #0
	beq _0212CC24
	blx r0
	mov r3, r0
_0212CC24:
	mov r0, r3
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212CC2C: .word PTR_LAB_overlay_11_0212ccf0_overlay_11_021629b8
_0212CC30: .word OVERLAY11_BSS_02169C70

	arm_func_start ov11_0212CC34
ov11_0212CC34: ; 0x0212CC34
	cmp r0, #0x16
	bge _0212CC5C
	mov r1, #0xc
	mul r1, r0, r1
	ldr r0, _0212CC88 ; =DAT_overlay_11_021629bc
	ldr r0, [r0, r1]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end ov11_0212CC34
_0212CC5C:
	ldr r1, _0212CC8C ; =OVERLAY11_BSS_02169C70
	sub r2, r0, #0x16
	ldr r1, [r1]
	mov r0, #0xc
	ldr r1, [r1]
	mla r0, r2, r0, r1
	ldr r0, [r0, #8]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	.align 2, 0
_0212CC88: .word DAT_overlay_11_021629bc
_0212CC8C: .word OVERLAY11_BSS_02169C70

	arm_func_start ov11_0212CC90
ov11_0212CC90: ; 0x0212CC90
	stmdb sp!, {r3, lr}
	cmp r0, #0x16
	bge _0212CCBC
	mov r3, #0xc
	mul ip, r0, r3
	ldr r3, _0212CCE8 ; =DAT_overlay_11_021629bc
	mov r0, r1
	ldr r3, [r3, ip]
	mov r1, #0
	blx r3
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212CC90
_0212CCBC:
	ldr r3, _0212CCEC ; =OVERLAY11_BSS_02169C70
	sub ip, r0, #0x16
	ldr lr, [r3]
	mov r0, r1
	ldr r3, [lr]
	mov r1, #0xc
	mla r3, ip, r1, r3
	ldr r1, [lr, #8]
	ldr r3, [r3, #8]
	blx r3
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212CCE8: .word DAT_overlay_11_021629bc
_0212CCEC: .word OVERLAY11_BSS_02169C70

	arm_func_start ov11_0212CCF0
ov11_0212CCF0: ; 0x0212CCF0
	mov r0, #0
	bx lr
	arm_func_end ov11_0212CCF0

    arm_func_start ov11_0212CCF8
ov11_0212CCF8: ; 0x0212CCF8
	mov r0, #1
	bx lr
    arm_func_end ov11_0212CCF8

    arm_func_start ov11_0212CD00
ov11_0212CD00: ; 0x0212CD00
	mov r0, #2
	bx lr
    arm_func_end ov11_0212CD00

	arm_func_start ov11_0212CD08
ov11_0212CD08: ; 0x0212CD08
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	bl ov11_0212C154
	cmp r0, #0
	ldmneia sp!, {r4, r5, r6, pc}
	ldr r5, _0212CD7C ; =OVERLAY11_BSS_02169C70
	mov r1, #1
	ldr r0, [r5]
	mov r4, #0
	add r0, r0, r6
	strb r1, [r0, #0xc]
	arm_func_end ov11_0212CD08
_0212CD34:
	mov r0, r4, lsl #0x10
	mov r0, r0, lsr #0x10
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212CD5C
	ldr r0, [r5]
	add r0, r0, r4
	ldrb r0, [r0, #0xc]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
_0212CD5C:
	add r4, r4, #1
	cmp r4, #8
	blt _0212CD34
	mov r1, #0
	mov r2, r1
	mov r0, #0xe
	bl ov11_0212BA98
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212CD7C: .word OVERLAY11_BSS_02169C70

	arm_func_start ov11_0212CD80
ov11_0212CD80: ; 0x0212CD80
	stmdb sp!, {r3, lr}
	ldr r3, _0212CDC0 ; =OVERLAY11_BSS_02169C70
	mov lr, #0
	ldr r0, [r3]
	mov r1, r2
	str lr, [r0]
	ldr r0, [r3]
	mov ip, #1
	str lr, [r0, #4]
	ldr r2, [r3]
	mov r0, #0xf
	str lr, [r2, #8]
	ldr r2, [r3]
	strb ip, [r2, #0x14]
	bl ov11_0212C198
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212CDC0: .word OVERLAY11_BSS_02169C70
	arm_func_end ov11_0212CD80

	arm_func_start ov11_0212CDC4
ov11_0212CDC4: ; 0x0212CDC4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov11_0212C154
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	ldr r0, _0212CDF0 ; =OVERLAY11_BSS_02169C70
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, r4
	strb r1, [r0, #0xc]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212CDF0: .word OVERLAY11_BSS_02169C70
	arm_func_end ov11_0212CDC4

	arm_func_start ov11_0212CDF4
ov11_0212CDF4: ; 0x0212CDF4
	ldr ip, _0212CE08 ; =ov11_0212CA60
	mov r2, r0
	ldr r0, _0212CE0C ; =PTR_LAB_overlay_11_02128634_overlay_11_02162ab0
	mov r1, #2
	bx ip
	.align 2, 0
_0212CE08: .word ov11_0212CA60
_0212CE0C: .word PTR_LAB_overlay_11_02128634_overlay_11_02162ab0
	arm_func_end ov11_0212CDF4

	arm_func_start ov11_0212CE10
ov11_0212CE10: ; 0x0212CE10
	stmdb sp!, {lr}
	sub sp, sp, #0x1c
	ldr lr, _0212CE54 ; =DAT_overlay_11_02162ac8
	add ip, sp, #0
	mov r3, #0xd
	arm_func_end ov11_0212CE10
_0212CE24:
	ldrb r2, [lr]
	ldrb r1, [lr, #1]
	add lr, lr, #2
	strb r2, [ip]
	strb r1, [ip, #1]
	add ip, ip, #2
	subs r3, r3, #1
	bne _0212CE24
	add r1, sp, #0
	ldrb r0, [r1, r0]
	add sp, sp, #0x1c
	ldmia sp!, {pc}
	.align 2, 0
_0212CE54: .word DAT_overlay_11_02162ac8

	arm_func_start _ZN17UnkClass_0212CE58C1EP5CGameP17UnkClass_0211E05C
_ZN17UnkClass_0212CE58C1EP5CGameP17UnkClass_0211E05C: ; 0x0212CE58
	stmdb sp!, {r3, r4, r5, lr}
	ldr r3, [r2, #8]
	mov r4, r0
	str r3, [r4, #0x3bc]
	ldr r3, [r2, #0xc]
	add lr, r2, #2
	str r3, [r4, #0x3c0]
	ldr r3, [r2, #0x10]
	add ip, r2, #4
	str r3, [r4, #0x3c4]
	ldr r5, [r2, #0x14]
	add r3, r2, #6
	str r5, [r4, #0x3c8]
	ldr r5, [r2, #0x18]
	str r5, [r4, #0x3cc]
	ldr r5, [r2, #0x1c]
	str r5, [r4, #0x3d0]
	str r2, [r4, #0x3d8]
	str lr, [r4, #0x3dc]
	str ip, [r4, #0x3e0]
	str r3, [r4, #0x3e4]
	str r2, [r4, #0x3b4]
	str r1, [r4, #0x3e8]
	bl ov11_0212CFD4
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_0212CE58C1EP5CGameP17UnkClass_0211E05C

	arm_func_start _ZN17UnkClass_0212CE58D1Ev
_ZN17UnkClass_0212CE58D1Ev: ; 0x0212CEC0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0212CEE0
	bl _ZdlPv
	mov r0, #0
	str r0, [r4]
	arm_func_end _ZN17UnkClass_0212CE58D1Ev
_0212CEE0:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start ov11_0212CEE8
ov11_0212CEE8: ; 0x0212CEE8
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0x24
	sub sp, sp, #0x400
	mov r5, r0
	mov r6, r1
	add r0, r5, #4
	mov r1, #0
	mov r2, #0x3a8
	bl MI_CpuFill8
	mov r0, #0xb8
	bl _Znwm
	movs r4, r0
	beq _0212CF48
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a8]
	mov r3, #0
	stmia sp, {r0, r3}
	mov r0, r4
	mov r1, r6
	mov r2, #1
	str r3, [sp, #8]
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	mov r4, r0
	arm_func_end ov11_0212CEE8
_0212CF48:
	ldr r1, [r4, #0x4c]
	add r0, r5, #4
	mov r2, #0x3a8
	bl memcpy
	ldr ip, _0212CFD0 ; =DAT_overlay_11_02162afc
	add r3, sp, #0xc
	mov r2, #8
_0212CF64:
	ldrb r1, [ip]
	ldrb r0, [ip, #1]
	add ip, ip, #2
	strb r1, [r3]
	strb r0, [r3, #1]
	add r3, r3, #2
	subs r2, r2, #1
	bne _0212CF64
	add r0, sp, #0x1c
	add r1, sp, #0xc
	mov r2, #0x10
	bl CRYPTO_RC4FastInit
	add r1, r5, #4
	add r0, sp, #0x1c
	mov r3, r1
	mov r2, #0x3a8
	bl CRYPTO_RC4FastEncrypt
	cmp r4, #0
	beq _0212CFC0
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0212CFC0:
	add r0, r5, #4
	add sp, sp, #0x24
	add sp, sp, #0x400
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_0212CFD0: .word DAT_overlay_11_02162afc

	arm_func_start ov11_0212CFD4
ov11_0212CFD4: ; 0x0212CFD4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, _0212D014 ; =0x00001E24
	bl _Z10Heap_Allocm
	ldr r2, _0212D014 ; =0x00001E24
	str r0, [r4]
	mov r1, #0
	bl memset
	ldr r0, [r4]
	mov r1, #1
	add r0, r0, #0x1000
	str r1, [r0, #0xac0]
	ldr r0, [r4]
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212D014: .word 0x00001E24
	arm_func_end ov11_0212CFD4

	arm_func_start _ZN17UnkClass_0212CE5813ov11_0212D018Ei
_ZN17UnkClass_0212CE5813ov11_0212D018Ei: ; 0x0212D018
	ldr r2, [r0]
	mov r3, #4
	add r2, r2, #0x1000
	str r3, [r2, #0xac4]
	str r1, [r0, #0x3ac]
	bx lr
	arm_func_end _ZN17UnkClass_0212CE5813ov11_0212D018Ei

	arm_func_start _ZN17UnkClass_0212CE5813ov11_0212D030Ev
_ZN17UnkClass_0212CE5813ov11_0212D030Ev: ; 0x0212D030
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5]
	cmp r4, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_0212247CEv
	cmp r0, #0
	bge _0212D068
	ldr r0, [r5]
	mov r1, #0x13
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	arm_func_end _ZN17UnkClass_0212CE5813ov11_0212D030Ev
_0212D068:
	bl ov11_0212A83C
	ldr r2, [r5]
	add r0, r2, #0x1000
	ldr r1, [r0, #0xac4]
	add r0, r2, #0x2c4
	cmp r1, #0x15
	add r2, r0, #0x1800
	addls pc, pc, r1, lsl #2
	b _0212D83C
_0212D08C: ; jump table
	b _0212D0E4 ; case 0
	b _0212D83C ; case 1
	b _0212D83C ; case 2
	b _0212D83C ; case 3
	b _0212D0F0 ; case 4
	b _0212D130 ; case 5
	b _0212D370 ; case 6
	b _0212D240 ; case 7
	b _0212D4EC ; case 8
	b _0212D510 ; case 9
	b _0212D4D8 ; case 10
	b _0212D59C ; case 11
	b _0212D600 ; case 12
	b _0212D660 ; case 13
	b _0212D710 ; case 14
	b _0212D728 ; case 15
	b _0212D75C ; case 16
	b _0212D790 ; case 17
	b _0212D7C4 ; case 18
	b _0212D7F8 ; case 19
	b _0212D828 ; case 20
	b _0212D83C ; case 21
_0212D0E4:
	mov r0, #1
	str r0, [r2]
	b _0212D83C
_0212D0F0:
	ldr r2, [r5, #0x3ac]
	mov r0, r5
	mov r1, r4
	bl ov11_0212D854
	ldr r0, [r5]
	mov r2, #5
	add r0, r0, #0x1000
	ldr r1, _0212D844 ; =0x00004650
	str r2, [r0, #0xac4]
	str r1, [r5, #0x3b0]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _0212D83C
_0212D130:
	ldr r0, [r5, #0x3b4]
	mov r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	mov r0, #0
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212D218
	add r0, r5, #4
	bl ov11_021298A0
	mov r0, r5
	mov r1, r4
	bl ov11_0212D880
	cmp r0, #0
	ble _0212D218
	mov r0, #1
	bl ov11_02128A30
	str r0, [r5, #0x3b8]
	ldr r0, [r5]
	mov r1, #7
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #0xd
	mov r2, #4
	mov r3, #5
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	ldr r2, [r5, #0x3b8]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122BF8Eii
	ldr r1, [r5, #0x3b8]
	ldr r0, [r5, #0x3b4]
	ldr r2, [r1, #0x10]
	mov r1, #0
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	bl _ZN17UnkClass_0211E05C13ov11_02122C08Eii
	ldr r0, [r5, #0x3b4]
	mov r1, #0x10
	bl _ZN17UnkClass_0211E05C13ov11_021217C0Ei
	ldr r0, [r5, #0x3b4]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd2
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, _0212D848 ; =0x00001C20
	str r0, [r5, #0x3b0]
	b _0212D83C
_0212D218:
	ldr r0, [r5, #0x3b0]
	sub r0, r0, #1
	str r0, [r5, #0x3b0]
	cmp r0, #0
	bgt _0212D83C
	ldr r0, [r5]
	mov r1, #0xf
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D240:
	ldr r1, [r5, #0x3b0]
	mov r0, #0
	sub r1, r1, #1
	str r1, [r5, #0x3b0]
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212D35C
	add r0, r5, #4
	bl ov11_021298A0
	mov r0, r5
	mov r1, r4
	bl ov11_0212D880
	cmp r0, #0
	ble _0212D35C
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02121168Ev
	cmp r0, #0
	bge _0212D2A8
	ldr r0, [r5, #0x3b0]
	cmp r0, #0
	bgt _0212D83C
	ldr r0, [r5]
	mov r1, #0x13
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D2A8:
	cmp r0, #0x12
	bne _0212D348
	mov r0, #1
	bl ov11_02128A30
	str r0, [r5, #0x3b8]
	ldr r0, [r5]
	mov r1, #7
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #0xe
	mov r2, #4
	mov r3, #5
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	ldr r2, [r5, #0x3b8]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122BF8Eii
	ldr r1, [r5, #0x3b8]
	ldr r0, [r5, #0x3b4]
	ldr r2, [r1, #0x10]
	mov r1, #0
	mov r2, r2, lsl #0x10
	mov r2, r2, lsr #0x10
	bl _ZN17UnkClass_0211E05C13ov11_02122C08Eii
	ldr r0, [r5, #0x3b4]
	mov r1, #8
	mov r2, #4
	mov r3, #1
	bl _ZN17UnkClass_0211E05C13ov11_02122C18Eiii
	ldr r0, [r5, #0x3b4]
	mov r1, #0xb
	bl _ZN17UnkClass_0211E05C13ov11_021217C0Ei
	ldr r0, [r5]
	mov r1, #6
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D348:
	ldr r0, [r5]
	mov r1, #0x13
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D35C:
	ldr r0, [r5]
	mov r1, #0x10
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D370:
	mov r0, #0
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212D4C4
	add r0, r5, #4
	bl ov11_021298A0
	mov r0, r5
	mov r1, r4
	bl ov11_0212D880
	cmp r0, #0
	ble _0212D4C4
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02121168Ev
	cmp r0, #0
	blt _0212D83C
	cmp r0, #0xe
	bne _0212D4B0
	mov r0, #0xab
	bl ov11_02129A54
	add r0, r4, #0x1000
	mov r1, #1
	str r1, [r0, #0xabc]
	ldr r0, [r5]
	mov r1, #9
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #0x13
	mov r2, #4
	mov r3, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	mov r1, #0x14
	bl _ZN17UnkClass_0211E05C13ov11_02122BD4Ei
	mov r2, #4
	ldr r0, [r5, #0x3b4]
	mov r1, #9
	mov r3, r2
	bl _ZN17UnkClass_0211E05C13ov11_02122C18Eiii
	ldr r0, [r5, #0x3b4]
	mov r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FBE4Ei
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [r5, #0x3ac]
	cmp r0, #0
	beq _0212D44C
	cmp r0, #1
	beq _0212D468
	b _0212D484
_0212D44C:
	ldr r0, _0212D84C ; =MAIN_BSS_020AF5E4+20
	mov r1, #1
	bl sub_02010FAC
	ldr r0, [r5, #0x3b4]
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_0211F008Ei
	b _0212D49C
_0212D468:
	ldr r0, _0212D850 ; =MAIN_BSS_020AF5E4+40
	mov r1, #2
	bl sub_02010FAC
	ldr r0, [r5, #0x3b4]
	mov r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_0211F008Ei
	b _0212D49C
_0212D484:
	ldr r0, [r5]
	mov r1, #0x10
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_0212D49C:
	ldr r0, [r5, #0x3b4]
	mov r1, #0
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE812sub_020292CCEt
	b _0212D83C
_0212D4B0:
	ldr r0, [r5]
	mov r1, #0x13
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D4C4:
	ldr r0, [r5]
	mov r1, #0x10
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D4D8:
	bl ov11_02128B80
	cmp r0, #0
	bne _0212D83C
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_0212D4EC:
	mov r0, #0xab
	bl ov11_02129AC0
	cmp r0, #1
	bne _0212D83C
	ldr r0, [r5]
	mov r1, #9
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D510:
	ldr r0, [r5, #0x3b4]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816UpdateWriteStepsEv
	tst r0, #0x80
	beq _0212D534
	ldr r0, [r5]
	mov r1, #0x12
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
_0212D534:
	mov r0, #0
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212D83C
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_0211F0FCEv
	cmp r0, #0
	bne _0212D83C
	add r2, r4, #0x2c8
	mov r0, r5
	add r1, r5, #4
	add r2, r2, #0x1800
	bl ov11_0212D8A0
	add r0, r4, #0x2c8
	add r0, r0, #0x1800
	mov r1, #0x358
	bl ov11_0212861C
	ldr r0, [r5]
	mov r1, #0xb
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_0211F32CEv
	ldr r0, _0212D844 ; =0x00004650
	str r0, [r5, #0x3b0]
	b _0212D83C
_0212D59C:
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	mov r0, #0
	bl ov11_0212BEA0
	cmp r0, #0
	beq _0212D83C
	ldr r0, [r5, #0x3b4]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816UpdateWriteStepsEv
	cmp r0, #2
	bne _0212D5E4
	mov r0, #0x93
	bl ov11_02129A54
	ldr r0, [r5]
	mov r1, #0xc
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D5E4:
	tst r0, #0x80
	beq _0212D83C
	ldr r0, [r5]
	mov r1, #0x12
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D600:
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	mov r0, r5
	mov r1, r4
	bl ov11_0212D880
	cmp r0, #0
	bne _0212D630
	ldr r0, [r5]
	mov r1, #0x11
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D630:
	mov r0, #0x93
	bl ov11_02129AC0
	cmp r0, #1
	bne _0212D83C
	ldr r0, [r5]
	mov r1, #0xd
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	ldr r0, [r5, #0x3b4]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816FinishWriteStepsEv
	b _0212D83C
_0212D660:
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	ldr r0, [r5, #0x3b4]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816UpdateWriteStepsEv
	cmp r0, #0
	beq _0212D83C
	tst r0, #0x80
	beq _0212D698
	ldr r0, [r5]
	mov r1, #0x12
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	b _0212D83C
_0212D698:
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #0x15
	mov r2, #4
	mov r3, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	mov r1, #0x17
	bl _ZN17UnkClass_0211E05C13ov11_02122BD4Ei
	ldr r0, [r5]
	mov r1, #0xe
	add r0, r0, #0x1000
	str r1, [r0, #0xac4]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd2
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [r5, #0x3b4]
	mov r1, #0
	sub r2, r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	bl ov11_0212868C
	b _0212D83C
_0212D710:
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	beq _0212D83C
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_0212D728:
	mov r0, #0x14
	str r0, [r2]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #5
	mov r2, #4
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	bl ov11_0212868C
	b _0212D83C
_0212D75C:
	mov r0, #0x14
	str r0, [r2]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #7
	mov r2, #4
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	bl ov11_0212868C
	b _0212D83C
_0212D790:
	mov r0, #0x14
	str r0, [r2]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #0x16
	mov r2, #4
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	bl ov11_0212868C
	b _0212D83C
_0212D7C4:
	mov r0, #0x15
	str r0, [r2]
	mov r0, #1
	str r0, [sp]
	mov r1, #5
	ldr r0, [r5, #0x3b4]
	mov r2, r1
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	bl ov11_0212868C
	b _0212D83C
_0212D7F8:
	mov r0, #0x14
	str r0, [r2]
	mov r2, #1
	str r2, [sp]
	ldr r0, [r5, #0x3b4]
	mov r1, #0xf
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	bl ov11_0212868C
	b _0212D83C
_0212D828:
	ldr r0, [r5, #0x3b4]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	movne r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
_0212D83C:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0212D844: .word 0x00004650
_0212D848: .word 0x00001C20
_0212D84C: .word MAIN_BSS_020AF5E4+20
_0212D850: .word MAIN_BSS_020AF5E4+40

	arm_func_start ov11_0212D854
ov11_0212D854: ; 0x0212D854
	stmdb sp!, {r4, lr}
	ldr r3, _0212D87C ; =ptr_null_overlay_11_021664a0
	mov r4, r1
	ldr r1, [r3, r2, lsl #2]
	bl ov11_0212CEE8
	add r0, r4, #4
	mov r1, #0xf
	bl ov11_021285E0
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212D87C: .word ptr_null_overlay_11_021664a0
	arm_func_end ov11_0212D854

	arm_func_start ov11_0212D880
ov11_0212D880: ; 0x0212D880
	stmdb sp!, {r4, lr}
	mov r0, #1
	mov r4, #0
	bl ov11_02128A30
	cmp r0, #0
	addne r4, r4, #1
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212D880

	arm_func_start ov11_0212D8A0
ov11_0212D8A0: ; 0x0212D8A0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #8
	mov r0, #0x200
	mov r5, r1
	mov r4, r2
	bl _Z10Heap_Allocm
	ldr r1, _0212D970 ; =0x0000A001
	mov r6, r0
	bl MATHi_CRC16InitTableRev
	mov r0, r6
	mov r1, r5
	mov r2, #0x50
	bl MATH_CalcCRC16
	mov r7, r0
	cmp r6, #0
	beq _0212D8E8
	mov r0, r6
	bl _Z9Heap_FreePv
	arm_func_end ov11_0212D8A0
_0212D8E8:
	add r0, sp, #0
	bl OS_GetMacAddress
	ldrh r0, [sp, #2]
	ldr r3, _0212D974 ; =0x0000D679
	mov r6, #0
	strh r0, [sp, #6]
	strh r7, [sp, #2]
	add r1, sp, #0
_0212D908:
	mov r2, r6, lsl #1
	ldrh r0, [r1, r2]
	add r6, r6, #1
	cmp r6, #4
	eor r0, r3, r0
	strh r0, [r1, r2]
	ldrh r3, [r1, r2]
	blt _0212D908
	mov r0, #0x104
	bl _Z10Heap_Allocm
	add r1, sp, #0
	mov r6, r0
	mov r2, #8
	bl CRYPTO_RC4Init
	mov r0, r6
	mov r3, r4
	add r1, r5, #0x50
	mov r2, #0x358
	bl CRYPTO_RC4Encrypt
	cmp r6, #0
	addeq sp, sp, #8
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mov r0, r6
	bl _Z9Heap_FreePv
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0212D970: .word 0x0000A001
_0212D974: .word 0x0000D679

	arm_func_start ov11_0212D978
ov11_0212D978: ; 0x0212D978
	bx lr
	arm_func_end ov11_0212D978

	arm_func_start _ZN17UnkClass_0212D97CC1EP17UnkClass_0211E05C
_ZN17UnkClass_0212D97CC1EP17UnkClass_0211E05C: ; 0x0212D97C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl ov11_0212D978
	str r4, [r5, #0x194]
	bl _Z13ov11_02125FECv
	bl _Znam
	str r0, [r5, #0x5c]
	mov r0, #0x30
	bl _Znwm
	str r0, [r5, #0x60]
	mov r0, #0x30
	bl _Znwm
	str r0, [r5, #0x64]
	bl ov11_021301D4
	rsb r0, r0, r0, lsl #1
	bl _Znam
	str r0, [r5, #0x4c]
	mov r0, #0xf000
	bl _Znam
	str r0, [r5, #0x50]
	mov r1, #0
	strb r1, [r5, #0x150]
	mov r0, r5
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_0212D97CC1EP17UnkClass_0211E05C

	arm_func_start _ZN17UnkClass_0212D97CD1Ev
_ZN17UnkClass_0212D97CD1Ev: ; 0x0212D9E8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x5c]
	cmp r0, #0
	beq _0212DA00
	bl _ZdaPv
	arm_func_end _ZN17UnkClass_0212D97CD1Ev
_0212DA00:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	beq _0212DA10
	bl _ZdlPv
_0212DA10:
	ldr r0, [r4, #0x64]
	cmp r0, #0
	beq _0212DA20
	bl _ZdlPv
_0212DA20:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	beq _0212DA30
	bl _ZdaPv
_0212DA30:
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	beq _0212DA40
	bl _ZdaPv
_0212DA40:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_0212D97C13ov11_0212DA48Ev
_ZN17UnkClass_0212D97C13ov11_0212DA48Ev: ; 0x0212DA48
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0212247CEv
	cmp r0, #0
	bge _0212DAD4
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0xf
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldrb r0, [r4, #0x150]
	cmp r0, #2
	cmpne r0, #3
	cmpne r0, #4
	bne _0212DAAC
	bl ov11_0212FD74
	mov r0, r4
	mov r1, #0x14
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	b _0212DAC8
	arm_func_end _ZN17UnkClass_0212D97C13ov11_0212DA48Ev
_0212DAAC:
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212DABC
	bl _Z13ov11_021268F8v
_0212DABC:
	mov r0, r4
	mov r1, #0x12
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
_0212DAC8:
	add sp, sp, #4
	ldrb r0, [r4, #0x150]
	ldmia sp!, {r3, r4, pc}
_0212DAD4:
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212DAF4
	bl _Z13ov11_0212641Cv
	bl _Z13ov11_02126954v
	cmp r0, #0
	movne r0, #0
	strneb r0, [r4, #0x6c]
_0212DAF4:
	ldrb r0, [r4, #0x150]
	cmp r0, #0x14
	addls pc, pc, r0, lsl #2
	b _0212DC78
_0212DB04: ; jump table
	b _0212DC78 ; case 0
	b _0212DC78 ; case 1
	b _0212DBE4 ; case 2
	b _0212DBF0 ; case 3
	b _0212DC10 ; case 4
	b _0212DC78 ; case 5
	b _0212DC78 ; case 6
	b _0212DC30 ; case 7
	b _0212DC78 ; case 8
	b _0212DC78 ; case 9
	b _0212DC78 ; case 10
	b _0212DC78 ; case 11
	b _0212DC78 ; case 12
	b _0212DC78 ; case 13
	b _0212DB58 ; case 14
	b _0212DC78 ; case 15
	b _0212DB74 ; case 16
	b _0212DB90 ; case 17
	b _0212DBAC ; case 18
	b _0212DC3C ; case 19
	b _0212DC50 ; case 20
_0212DB58:
	mov r0, r4
	bl ov11_0212DC84
	mov r1, #2
	ldr r0, [r4, #0x194]
	sub r2, r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	b _0212DC78
_0212DB74:
	mov r0, r4
	bl ov11_0212E128
	mov r1, #2
	ldr r0, [r4, #0x194]
	sub r2, r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	b _0212DC78
_0212DB90:
	mov r0, r4
	bl ov11_0212E518
	mov r1, #2
	ldr r0, [r4, #0x194]
	sub r2, r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	b _0212DC78
_0212DBAC:
	mov r1, #2
	ldr r0, [r4, #0x194]
	sub r2, r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	bl _Z13ov11_02126954v
	cmp r0, #0
	beq _0212DC78
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	beq _0212DC78
	add sp, sp, #4
	mov r0, #0xa
	ldmia sp!, {r3, r4, pc}
_0212DBE4:
	mov r0, r4
	bl ov11_0212EBCC
	b _0212DC78
_0212DBF0:
	bl ov11_021301BC
	mov r2, r0
	ldr r0, [r4, #0x194]
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	mov r0, r4
	bl ov11_0212EE24
	b _0212DC78
_0212DC10:
	bl ov11_021301BC
	mov r2, r0
	ldr r0, [r4, #0x194]
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	mov r0, r4
	bl ov11_0212EF94
	b _0212DC78
_0212DC30:
	mov r0, r4
	bl ov11_0212F158
	b _0212DC78
_0212DC3C:
	mov r1, #2
	ldr r0, [r4, #0x194]
	sub r2, r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	b _0212DC78
_0212DC50:
	mov r1, #2
	ldr r0, [r4, #0x194]
	sub r2, r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	addne sp, sp, #4
	movne r0, #0xa
	ldmneia sp!, {r3, r4, pc}
_0212DC78:
	ldrb r0, [r4, #0x150]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}

	arm_func_start ov11_0212DC84
ov11_0212DC84: ; 0x0212DC84
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	ldrb r1, [r4, #0x152]
	cmp r1, #0xc
	addls pc, pc, r1, lsl #2
	b _0212E11C
_0212DCA0: ; jump table
	b _0212DCD4 ; case 0
	b _0212DD08 ; case 1
	b _0212E11C ; case 2
	b _0212E11C ; case 3
	b _0212DD34 ; case 4
	b _0212DD44 ; case 5
	b _0212DD60 ; case 6
	b _0212DDC4 ; case 7
	b _0212E0B0 ; case 8
	b _0212E11C ; case 9
	b _0212E0EC ; case 10
	b _0212E0FC ; case 11
	b _0212E118 ; case 12
	arm_func_end ov11_0212DC84
_0212DCD4:
	ldrb r0, [r4, #0x151]
	cmp r0, #0x10
	moveq r0, #1
	addeq sp, sp, #4
	streqb r0, [r4, #0x152]
	ldmeqia sp!, {r3, r4, pc}
	add r0, r4, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0x44]
	mov r0, #4
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212DD08:
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
	add r0, r4, #0x100
	mov r1, #0xa
	strh r1, [r0, #0x44]
	mov r0, #6
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212DD34:
	mov r0, #5
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212DD44:
	add r0, r4, #0x100
	mov r1, #0xa
	strh r1, [r0, #0x44]
	mov r0, #6
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212DD60:
	add r1, r4, #0x100
	ldrh r2, [r1, #0x44]
	sub r2, r2, #1
	strh r2, [r1, #0x44]
	ldrh r2, [r1, #0x44]
	cmp r2, #0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
	mov r3, #7
	ldr r2, _0212E124 ; =0x00001C20
	strb r3, [r4, #0x152]
	strh r2, [r1, #0x44]
	mov r1, #1
	strb r1, [r4, #0x153]
	bl ov11_0212EA38
	bl _Z13ov11_02126480v
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #1
	add sp, sp, #4
	strb r0, [r4, #0x6c]
	ldmia sp!, {r3, r4, pc}
_0212DDC4:
	ldrb r0, [r4, #0x153]
	cmp r0, #7
	addls pc, pc, r0, lsl #2
	b _0212E11C
_0212DDD4: ; jump table
	b _0212E11C ; case 0
	b _0212DDF4 ; case 1
	b _0212E11C ; case 2
	b _0212E11C ; case 3
	b _0212DE80 ; case 4
	b _0212DF28 ; case 5
	b _0212DFF4 ; case 6
	b _0212E04C ; case 7
_0212DDF4:
	ldr r0, [r4, #0x194]
	mov r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	bl _Z13ov11_02126668v
	cmp r0, #0
	beq _0212DE34
	mov r0, #2
	strb r0, [r4, #0x153]
	bl _Z13ov11_02126770v
	ldr r1, _0212E124 ; =0x00001C20
	add r0, r4, #0x100
	strh r1, [r0, #0x44]
	mov r0, #4
	add sp, sp, #4
	strb r0, [r4, #0x153]
	ldmia sp!, {r3, r4, pc}
_0212DE34:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r1, [r0, #0x44]
	cmp r1, #0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
	mov r1, #6
	strb r1, [r4, #0x153]
	mov r1, #0x3c
	strh r1, [r0, #0x44]
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl _Z13ov11_021268F8v
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212DE80:
	ldr r0, [r4, #0x194]
	mov r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	beq _0212DEB4
	bl _Z13ov11_02126890v
	cmp r0, #0
	bne _0212DEF0
_0212DEB4:
	mov r0, #7
	strb r0, [r4, #0x153]
	add r0, r4, #0x100
	mov r1, #0x3c
	strh r1, [r0, #0x44]
	ldr r0, [r4, #0x194]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl _Z13ov11_021268F8v
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212DEF0:
	bl _Z13ov11_0212669Cv
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	add r0, r4, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0x44]
	mov r0, #5
	strb r0, [r4, #0x153]
	ldr r0, [r4, #0x194]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212DF28:
	bl _Z13ov11_021268E0v
	cmp r0, #0
	beq _0212DFC4
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	cmp r1, #0
	subne r1, r1, #1
	strneh r1, [r0, #0x44]
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
	bl _Z13ov11_0212669Cv
	cmp r0, #1
	addlt sp, sp, #4
	ldmltia sp!, {r3, r4, pc}
	mov r0, #0
	str r0, [r4, #0x68]
	bl _Z13ov11_02126710i
	bl _Z13ov11_02126620m
	mov r0, #8
	strb r0, [r4, #0x152]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #6
	mov r2, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd2
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212DFC4:
	mov r0, #7
	strb r0, [r4, #0x153]
	add r0, r4, #0x100
	mov r1, #0x3c
	strh r1, [r0, #0x44]
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bl _Z13ov11_021268F8v
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212DFF4:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	cmp r1, #0
	subne r1, r1, #1
	strneh r1, [r0, #0x44]
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #5
	mov r2, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F96CEv
	mov r0, #0xb
	strb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212E04C:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	cmp r1, #0
	subne r1, r1, #1
	strneh r1, [r0, #0x44]
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #7
	mov r2, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F96CEv
	ldr r0, [r4, #0x194]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	mov r0, #0xb
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E0B0:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	ldr r1, [r4, #0x60]
	mov r0, #0
	mov r2, #4
	bl MIi_CpuClear16
	ldr r0, [r4, #0x60]
	bl _Z13ov11_021267C4Pv
	mov r0, #0xa
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E0EC:
	mov r1, #0x10
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212E0FC:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	movne r0, #0xc
	add sp, sp, #4
	strneb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E118:
	bl ov11_0212E9D8
_0212E11C:
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0212E124: .word 0x00001C20

	arm_func_start ov11_0212E128
ov11_0212E128: ; 0x0212E128
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0xc
	mov r4, r0
	ldrb r1, [r4, #0x152]
	cmp r1, #0x19
	addls pc, pc, r1, lsl #2
	b _0212E510
_0212E144: ; jump table
	b _0212E1AC ; case 0
	b _0212E1F4 ; case 1
	b _0212E510 ; case 2
	b _0212E510 ; case 3
	b _0212E21C ; case 4
	b _0212E23C ; case 5
	b _0212E510 ; case 6
	b _0212E510 ; case 7
	b _0212E34C ; case 8
	b _0212E404 ; case 9
	b _0212E4DC ; case 10
	b _0212E4EC ; case 11
	b _0212E50C ; case 12
	b _0212E510 ; case 13
	b _0212E510 ; case 14
	b _0212E510 ; case 15
	b _0212E510 ; case 16
	b _0212E510 ; case 17
	b _0212E510 ; case 18
	b _0212E510 ; case 19
	b _0212E2D4 ; case 20
	b _0212E320 ; case 21
	b _0212E510 ; case 22
	b _0212E33C ; case 23
	b _0212E510 ; case 24
	b _0212E50C ; case 25
	arm_func_end ov11_0212E128
_0212E1AC:
	bl _Z13ov11_021268E0v
	cmp r0, #0
	beq _0212E1E4
	bl _Z13ov11_02126850v
	cmp r0, #0
	addeq sp, sp, #0xc
	ldmeqia sp!, {r3, r4, pc}
	add r0, r4, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0x44]
	mov r0, #1
	add sp, sp, #0xc
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E1E4:
	mov r0, #0x14
	add sp, sp, #0xc
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E1F4:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	add sp, sp, #0xc
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	moveq r0, #4
	streqb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E21C:
	bl _Z13ov11_021268E0v
	cmp r0, #0
	moveq r0, #0x14
	streqb r0, [r4, #0x152]
	movne r0, #5
	add sp, sp, #0xc
	strneb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E23C:
	mov r1, #8
	mov r0, #0
	strb r1, [r4, #0x152]
	bl _Z13ov11_02126710i
	add r1, sp, #8
	add r2, sp, #4
	bl _Z13ov11_02126FE4mPmS_
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0xd
	mov r2, #3
	mov r3, #4
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r1, [r4, #0x60]
	mov r0, r4
	add r1, r1, #0x18
	bl ov11_0212EBA4
	mov r2, r0
	ldr r0, [r4, #0x194]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122C08Eii
	ldr r0, [r4, #0x194]
	ldr r2, [sp, #8]
	mov r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_02122C08Eii
	ldr r0, [r4, #0x194]
	ldr r2, [sp, #4]
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122C08Eii
	ldr r0, [r4, #0x194]
	mov r1, #0x10
	bl _ZN17UnkClass_0211E05C13ov11_021217C0Ei
	add r0, r4, #0x100
	mov r1, #0xe10
	strh r1, [r0, #0x44]
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
_0212E2D4:
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212E2E4
	bl _Z13ov11_021268F8v
_0212E2E4:
	mov r0, #0x15
	strb r0, [r4, #0x152]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #7
	mov r2, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F96CEv
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
_0212E320:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	movne r0, #0x17
	add sp, sp, #0xc
	strneb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E33C:
	mov r0, #0x19
	add sp, sp, #0xc
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E34C:
	bl _Z13ov11_021268E0v
	cmp r0, #0
	moveq r0, #0x14
	addeq sp, sp, #0xc
	streqb r0, [r4, #0x152]
	ldmeqia sp!, {r3, r4, pc}
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	moveq r0, #0x14
	addeq sp, sp, #0xc
	streqb r0, [r4, #0x152]
	ldmeqia sp!, {r3, r4, pc}
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02121168Ev
	cmp r0, #0
	addlt sp, sp, #0xc
	ldmltia sp!, {r3, r4, pc}
	cmp r0, #0x12
	addne sp, sp, #0xc
	ldmneia sp!, {r3, r4, pc}
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0xe
	mov r2, #3
	mov r3, #4
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	mov r1, #8
	mov r2, #3
	mov r3, #1
	bl _ZN17UnkClass_0211E05C13ov11_02122C18Eiii
	ldr r0, [r4, #0x194]
	mov r1, #0xb
	bl _ZN17UnkClass_0211E05C13ov11_021217C0Ei
	mov r0, #9
	strb r0, [r4, #0x152]
	add r0, r4, #0x100
	mov r1, #0xe10
	strh r1, [r0, #0x44]
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
_0212E404:
	bl _Z13ov11_021268E0v
	cmp r0, #0
	moveq r0, #0x14
	addeq sp, sp, #0xc
	streqb r0, [r4, #0x152]
	ldmeqia sp!, {r3, r4, pc}
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	moveq r0, #0x14
	addeq sp, sp, #0xc
	streqb r0, [r4, #0x152]
	ldmeqia sp!, {r3, r4, pc}
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02121168Ev
	cmp r0, #0
	addlt sp, sp, #0xc
	ldmltia sp!, {r3, r4, pc}
	cmp r0, #0xe
	bne _0212E4CC
	mov r0, #0
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0x14
	mov r2, #3
	mov r3, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	mov r1, #0x15
	bl _ZN17UnkClass_0211E05C13ov11_02122BD4Ei
	mov r2, #3
	ldr r0, [r4, #0x194]
	mov r3, r2
	mov r1, #9
	bl _ZN17UnkClass_0211E05C13ov11_02122C18Eiii
	mov r0, #0xa
	strb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	mov r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FBE4Ei
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
_0212E4CC:
	mov r0, r4
	bl ov11_0212E9E8
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
_0212E4DC:
	mov r1, #0x11
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}
_0212E4EC:
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212E4FC
	bl _Z13ov11_021268F8v
_0212E4FC:
	mov r0, #0xc
	add sp, sp, #0xc
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212E50C:
	bl ov11_0212E9D8
_0212E510:
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, pc}

	arm_func_start ov11_0212E518
ov11_0212E518: ; 0x0212E518
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldrb r1, [r4, #0x152]
	cmp r1, #0x19
	addls pc, pc, r1, lsl #2
	ldmia sp!, {r3, r4, r5, pc}
_0212E530: ; jump table
	b _0212E598 ; case 0
	b _0212E5BC ; case 1
	ldmia sp!, {r3, r4, r5, pc} ; case 2
	ldmia sp!, {r3, r4, r5, pc} ; case 3
	b _0212E6AC ; case 4
	ldmia sp!, {r3, r4, r5, pc} ; case 5
	ldmia sp!, {r3, r4, r5, pc} ; case 6
	ldmia sp!, {r3, r4, r5, pc} ; case 7
	ldmia sp!, {r3, r4, r5, pc} ; case 8
	ldmia sp!, {r3, r4, r5, pc} ; case 9
	ldmia sp!, {r3, r4, r5, pc} ; case 10
	b _0212E97C ; case 11
	b _0212E994 ; case 12
	b _0212E728 ; case 13
	ldmia sp!, {r3, r4, r5, pc} ; case 14
	ldmia sp!, {r3, r4, r5, pc} ; case 15
	b _0212E754 ; case 16
	b _0212E7B0 ; case 17
	b _0212E824 ; case 18
	ldmia sp!, {r3, r4, r5, pc} ; case 19
	b _0212E8D0 ; case 20
	b _0212E958 ; case 21
	b _0212E914 ; case 22
	b _0212E964 ; case 23
	ldmia sp!, {r3, r4, r5, pc} ; case 24
	b _0212E99C ; case 25
	arm_func_end ov11_0212E518
_0212E598:
	add r0, r4, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0x44]
	mov r0, #1
	strb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_0211F008Ei
	ldmia sp!, {r3, r4, r5, pc}
_0212E5BC:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F0FCEv
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	ldr r1, [r4, #0x64]
	mov r0, #0
	mov r2, #4
	bl MIi_CpuClear16
	ldr ip, _0212E9A4 ; =DAT_overlay_11_021664e0
	ldr r0, _0212E9A8 ; =0x00000457
	ldrh r1, [ip]
	mov r5, #0
	cmp r1, #0
	beq _0212E618
_0212E5F4:
	mov r3, r5, lsl #1
	ldrh r2, [ip, r3]
	ldr r1, [r4, #0x64]
	add r5, r5, #1
	strh r2, [r1, r3]
	mov r1, r5, lsl #1
	ldrh r1, [ip, r1]
	cmp r1, #0
	bne _0212E5F4
_0212E618:
	ldr lr, _0212E9AC ; =0xCCCCCCCD
	mov r1, #0
	mov ip, #0xa
_0212E624:
	umull r2, r5, r0, lr
	mov r5, r5, lsr #3
	umull r2, r3, ip, r5
	sub r5, r0, r2
	mov r3, r0
	umull r2, r0, r3, lr
	rsb r2, r1, #7
	ldr r3, [r4, #0x64]
	add r1, r1, #1
	add r5, r5, #0xa2
	add r2, r3, r2, lsl #1
	strh r5, [r2, #0x18]
	cmp r1, #8
	mov r0, r0, lsr #3
	blt _0212E624
	ldr r0, [r4, #0x64]
	mov r1, #4
	mov r2, #1
	bl _Z13ov11_02126720Pvii
	add r0, r4, #0x100
	mov r1, #0xe10
	strh r1, [r0, #0x44]
	mov r0, #4
	strb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F32CEv
	ldr r0, _0212E9B0 ; =MAIN_BSS_020AF5E4
	mov r1, #0
	bl sub_02010FAC
	ldr r0, [r4, #0x194]
	mov r1, #0
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE812sub_020292CCEt
	ldmia sp!, {r3, r4, r5, pc}
_0212E6AC:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	ldr r0, [r4, #0x194]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816UpdateWriteStepsEv
	tst r0, #0x80
	movne r0, #0x14
	strneb r0, [r4, #0x152]
	ldmneia sp!, {r3, r4, r5, pc}
	bl _Z13ov11_02126810v
	cmp r0, #0
	movne r0, #0xd
	strneb r0, [r4, #0x152]
	ldmneia sp!, {r3, r4, r5, pc}
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	beq _0212E70C
	bl _Z13ov11_021268E0v
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
_0212E70C:
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212E71C
	bl _Z13ov11_021268F8v
_0212E71C:
	mov r0, #0x14
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212E728:
	ldr r0, [r4, #0x194]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816UpdateWriteStepsEv
	tst r0, #0x80
	movne r0, #0x14
	strneb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	mov r0, #0x10
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212E754:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	ldr r0, [r4, #0x194]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816UpdateWriteStepsEv
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	cmp r0, #2
	bne _0212E7A0
	ldr r0, [r4, #0x64]
	mov r1, #4
	mov r2, #2
	bl _Z13ov11_02126720Pvii
	mov r0, #0x11
	strb r0, [r4, #0x152]
	add r0, r4, #0x100
	mov r1, #0xe10
	strh r1, [r0, #0x44]
	ldmia sp!, {r3, r4, r5, pc}
_0212E7A0:
	tst r0, #0x80
	movne r0, #0x14
	strneb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212E7B0:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	bl _Z13ov11_02126810v
	cmp r0, #0
	beq _0212E7EC
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212E7D4
	bl _Z13ov11_021268F8v
_0212E7D4:
	mov r0, #0x12
	strb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816FinishWriteStepsEv
	ldmia sp!, {r3, r4, r5, pc}
_0212E7EC:
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	ldmneia sp!, {r3, r4, r5, pc}
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212E818
	bl _Z13ov11_021268F8v
_0212E818:
	mov r0, #0x14
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212E824:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F338Ev
	ldr r0, [r4, #0x194]
	ldr r0, [r0, #0x728]
	bl _ZN17UnkClass_02027FE816UpdateWriteStepsEv
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	tst r0, #0x80
	movne r0, #0x14
	strneb r0, [r4, #0x152]
	ldmneia sp!, {r3, r4, r5, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd2
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0x16
	mov r2, #3
	mov r3, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	mov r1, #0x18
	bl _ZN17UnkClass_0211E05C13ov11_02122BD4Ei
	mov r0, #0xa
	strb r0, [r4, #0x152]
	mov r1, #0x1e
	add r0, r4, #0x100
	strh r1, [r0, #0x44]
	mov r0, #0xb
	strb r0, [r4, #0x152]
	mov r1, #0
	ldr r0, [r4, #0x194]
	sub r2, r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	ldmia sp!, {r3, r4, r5, pc}
_0212E8D0:
	add r0, r4, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0x44]
	mov r0, #0x15
	strb r0, [r4, #0x152]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0x17
	mov r2, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F96CEv
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldmia sp!, {r3, r4, r5, pc}
_0212E914:
	add r0, r4, #0x100
	mov r1, #0x1e
	strh r1, [r0, #0x44]
	mov r0, #0x15
	strb r0, [r4, #0x152]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0x17
	mov r2, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F96CEv
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldmia sp!, {r3, r4, r5, pc}
_0212E958:
	mov r0, #0x17
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212E964:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	movne r0, #0xc
	strneb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212E97C:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	movne r0, #0x19
	strneb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212E994:
	bl ov11_0212E9D8
	ldmia sp!, {r3, r4, r5, pc}
_0212E99C:
	bl ov11_0212E9D8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0212E9A4: .word DAT_overlay_11_021664e0
_0212E9A8: .word 0x00000457
_0212E9AC: .word 0xCCCCCCCD
_0212E9B0: .word MAIN_BSS_020AF5E4

	arm_func_start _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
_ZN17UnkClass_0212D97C13ov11_0212E9B4Ei: ; 0x0212E9B4
	ldrb ip, [r0, #0x150]
	mov r3, #0
	add r2, r0, #0x100
	strb ip, [r0, #0x151]
	strb r1, [r0, #0x150]
	strb r3, [r0, #0x152]
	strh r3, [r2, #0x44]
	strh r3, [r2, #0x46]
	bx lr
	arm_func_end _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei

	arm_func_start ov11_0212E9D8
ov11_0212E9D8: ; 0x0212E9D8
	ldr ip, _0212E9E4 ; =_ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	mov r1, #8
	bx ip
	.align 2, 0
_0212E9E4: .word _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	arm_func_end ov11_0212E9D8

	arm_func_start ov11_0212E9E8
ov11_0212E9E8: ; 0x0212E9E8
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r2, #1
	mov r4, r0
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0xf
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldrb r0, [r4, #0x6c]
	cmp r0, #0
	beq _0212EA24
	bl _Z13ov11_021268F8v
	arm_func_end ov11_0212E9E8
_0212EA24:
	mov r0, r4
	mov r1, #0x12
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}

	arm_func_start ov11_0212EA38
ov11_0212EA38: ; 0x0212EA38
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x28
	mov r5, r0
	ldr r0, _0212EB4C ; =0x00000458
	add r4, sp, #0x14
	mov r3, #0
	add r1, sp, #4
	add r2, sp, #0
	strh r3, [r4]
	strh r3, [r4, #2]
	strh r3, [r4, #4]
	strh r3, [r4, #6]
	strh r3, [r4, #8]
	strh r3, [r4, #0xa]
	strh r3, [r4, #0xc]
	strh r3, [r4, #0xe]
	strh r3, [r4, #0x10]
	strh r3, [r4, #0x12]
	ldr r4, _0212EB50 ; =DAT_overlay_11_021664ec
	bl ov11_0212EB5C
	ldr r1, [sp, #4]
	ldr ip, _0212EB54 ; =0xCCCCCCCD
	mov r0, #3
	add r7, sp, #0x14
	mov r6, #0xa
	arm_func_end ov11_0212EA38
_0212EA9C:
	umull r2, lr, r1, ip
	mov lr, lr, lsr #3
	umull r2, r3, r6, lr
	sub lr, r1, r2
	mov r3, r1
	umull r2, r1, r3, ip
	mov r2, r0, lsl #1
	add r3, lr, #0xa2
	strh r3, [r7, r2]
	mov r1, r1, lsr #3
	subs r0, r0, #1
	bpl _0212EA9C
	mov r0, #0xf1
	strh r0, [sp, #0x1c]
	ldr ip, [sp]
	ldr r6, _0212EB54 ; =0xCCCCCCCD
	str r1, [sp, #4]
	mov r0, #3
	add r3, sp, #0x14
	mov lr, #0xa
_0212EAEC:
	umull r1, r7, ip, r6
	mov r7, r7, lsr #3
	umull r1, r2, lr, r7
	sub r7, ip, r1
	mov r2, ip
	umull r1, ip, r2, r6
	add r1, r3, r0, lsl #1
	add r2, r7, #0xa2
	strh r2, [r1, #0xa]
	mov ip, ip, lsr #3
	subs r0, r0, #1
	bpl _0212EAEC
	ldr r0, _0212EB58 ; =DAT_overlay_11_02162b0c
	add r6, sp, #8
	ldmia r0, {r0, r1, r2}
	stmia r6, {r0, r1, r2}
	str ip, [sp]
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	ldr r1, [r5, #0x5c]
	mov r0, r6
	bl _Z13ov11_0212600CP11WhInitParamm
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_0212EB4C: .word 0x00000458
_0212EB50: .word DAT_overlay_11_021664ec
_0212EB54: .word 0xCCCCCCCD
_0212EB58: .word DAT_overlay_11_02162b0c

	arm_func_start ov11_0212EB5C
ov11_0212EB5C: ; 0x0212EB5C
	stmdb sp!, {r4, r5, r6, lr}
	ldr lr, _0212EB9C ; =0xD1B71759
	ldr r4, _0212EBA0 ; =0x00002710
	umull r3, r6, r0, lr
	mov r6, r6, lsr #0xd
	umull r3, r5, r0, lr
	mov r5, r5, lsr #0xd
	umull r3, ip, r4, r6
	umull ip, lr, r5, lr
	mov lr, lr, lsr #0xd
	umull ip, lr, r4, lr
	sub r6, r0, r3
	str r6, [r1]
	rsb lr, ip, r5
	str lr, [r2]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212EB9C: .word 0xD1B71759
_0212EBA0: .word 0x00002710
	arm_func_end ov11_0212EB5C

	arm_func_start ov11_0212EBA4
ov11_0212EBA4: ; 0x0212EBA4
	mov r0, #0
	mov r2, #0xa
	arm_func_end ov11_0212EBA4
_0212EBAC:
	ldrh r3, [r1], #2
	cmp r3, #0x30
	bxlo lr
	cmp r3, #0x39
	subls r3, r3, #0x30
	mlals r0, r2, r0, r3
	bls _0212EBAC
	bx lr

	arm_func_start ov11_0212EBCC
ov11_0212EBCC: ; 0x0212EBCC
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	ldrb r0, [r4, #0x152]
	cmp r0, #0x14
	bgt _0212EC28
	bge _0212EDF0
	cmp r0, #0xc
	addls pc, pc, r0, lsl #2
	b _0212EE10
_0212EBF4: ; jump table
	b _0212EC34 ; case 0
	b _0212EC50 ; case 1
	b _0212EE10 ; case 2
	b _0212ECE4 ; case 3
	b _0212ED08 ; case 4
	b _0212EE10 ; case 5
	b _0212EE10 ; case 6
	b _0212EE10 ; case 7
	b _0212EE10 ; case 8
	b _0212EE10 ; case 9
	b _0212EE10 ; case 10
	b _0212EDCC ; case 11
	b _0212EDDC ; case 12
	arm_func_end ov11_0212EBCC
_0212EC28:
	add sp, sp, #4
	cmp r0, #0x19
	ldmia sp!, {r3, r4, pc}
_0212EC34:
	ldr r0, _0212EE18 ; =OVERLAY11_BSS_02169C74
	mov r1, #0
	str r1, [r0, #4]
	mov r0, #1
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212EC50:
	ldr r0, [r4, #0x194]
	mov r1, #1
	str r1, [r0, #0x710]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #2
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x50]
	ldr r2, [r4, #0x4c]
	ldr r1, _0212EE1C ; =ov11_0212F32C
	bl ov11_0212FE30
	cmp r0, #0
	bne _0212ECC8
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, r4
	bl ov11_0212F3B0
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212ECC8:
	mov r0, #3
	strb r0, [r4, #0x152]
	ldr r1, _0212EE20 ; =0x00001C20
	add r0, r4, #0x100
	strh r1, [r0, #0x44]
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212ECE4:
	bl ov11_02130200
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	ldr r0, [r4, #0x194]
	mov r1, #5
	bl _ZN17UnkClass_0211E05C13ov11_0211FBE4Ei
	mov r0, #4
	strb r0, [r4, #0x152]
_0212ED08:
	bl ov11_021301BC
	mov r2, r0
	ldr r0, [r4, #0x194]
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	ldr r0, _0212EE18 ; =OVERLAY11_BSS_02169C74
	ldr r0, [r0, #4]
	cmp r0, #2
	cmpne r0, #4
	bne _0212ED7C
	bl ov11_021301DC
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r0, r4
	mov r1, #3
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd2
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212ED7C:
	cmp r0, #5
	beq _0212EDA4
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
_0212EDA4:
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #3
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, r4
	bl ov11_0212F3B0
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212EDCC:
	mov r0, #0xc
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212EDDC:
	mov r0, #0x19
	strb r0, [r4, #0x152]
	bl ov11_0212FD74
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212EDF0:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r0, r4
	mov r1, #8
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
_0212EE10:
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_0212EE18: .word OVERLAY11_BSS_02169C74
_0212EE1C: .word ov11_0212F32C
_0212EE20: .word 0x00001C20

	arm_func_start ov11_0212EE24
ov11_0212EE24: ; 0x0212EE24
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	bl ov11_021301DC
	ldrb r2, [r4, #0x152]
	mov r1, r0
	cmp r2, #0x14
	bgt _0212EE80
	bge _0212EF6C
	cmp r2, #0xa
	addls pc, pc, r2, lsl #2
	b _0212EF8C
_0212EE54: ; jump table
	b _0212EE8C ; case 0
	b _0212EF8C ; case 1
	b _0212EF8C ; case 2
	b _0212EE9C ; case 3
	b _0212EEAC ; case 4
	b _0212EF14 ; case 5
	b _0212EF8C ; case 6
	b _0212EF8C ; case 7
	b _0212EF8C ; case 8
	b _0212EF8C ; case 9
	b _0212EF58 ; case 10
	arm_func_end ov11_0212EE24
_0212EE80:
	add sp, sp, #4
	cmp r2, #0x19
	ldmia sp!, {r3, r4, pc}
_0212EE8C:
	mov r0, #4
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212EE9C:
	mov r0, #4
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212EEAC:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02123C8CEPKc
	str r0, [r4, #0x188]
	mov r2, #0
	mvn r1, #0
_0212EEC0:
	add r0, r4, r2, lsl #2
	add r2, r2, #1
	str r1, [r0, #0x15c]
	cmp r2, #0xb
	blt _0212EEC0
	ldr r0, [r4, #0x188]
	mov r2, #1
	cmp r0, #0
	movlt r0, #0xa
	strlt r0, [r4, #0x188]
	ldr r0, [r4, #0x188]
	add r1, r4, #0x15c
	add r0, r4, r0, lsl #2
	str r2, [r0, #0x15c]
	ldr r0, [r4, #0x194]
	mov r3, #7
	bl _ZN17UnkClass_0211E05C13ov11_021217D4EPKiii
	mov r0, #5
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212EF14:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_021212B4Ev
	cmp r0, #0
	addlt sp, sp, #4
	ldmltia sp!, {r3, r4, pc}
	sub r0, r0, #0xb
	mov r2, #1
	str r0, [r4, #0x188]
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r3, r2
	mov r1, #4
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #0xa
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212EF58:
	mov r0, r4
	mov r1, #4
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212EF6C:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r0, r4
	mov r1, #8
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
_0212EF8C:
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}

	arm_func_start ov11_0212EF94
ov11_0212EF94: ; 0x0212EF94
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4, #0x48]
	cmp r0, #0
	subne r0, r0, #1
	strne r0, [r4, #0x48]
	ldrb r0, [r4, #0x152]
	cmp r0, #0xc
	bgt _0212EFF4
	cmp r0, #0xb
	blt _0212EFCC
	beq _0212F0F8
	cmp r0, #0xc
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end ov11_0212EF94
_0212EFCC:
	cmp r0, #4
	ldmgtia sp!, {r3, r4, r5, pc}
	cmp r0, #0
	ldmltia sp!, {r3, r4, r5, pc}
	beq _0212F00C
	cmp r0, #3
	beq _0212F050
	cmp r0, #4
	beq _0212F05C
	ldmia sp!, {r3, r4, r5, pc}
_0212EFF4:
	cmp r0, #0x14
	bgt _0212F004
	beq _0212F130
	ldmia sp!, {r3, r4, r5, pc}
_0212F004:
	cmp r0, #0x19
	ldmia sp!, {r3, r4, r5, pc}
_0212F00C:
	ldr r1, _0212F150 ; =0x00001C20
	mov r0, #4
	str r1, [r4, #0x48]
	strb r0, [r4, #0x152]
	mov r0, #0
	str r0, [r4, #0x154]
	add r0, r4, #0x100
	mov r1, #0xf
	strh r1, [r0, #0x44]
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211EF5CEv
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldmia sp!, {r3, r4, r5, pc}
_0212F050:
	mov r0, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, r5, pc}
_0212F05C:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	bl ov11_0213018C
	mov r5, r0
	bl ov11_021301A4
	cmp r5, r0
	ldreq r0, _0212F154 ; =OVERLAY11_BSS_02169C74
	ldreq r0, [r0, #4]
	cmpeq r0, #3
	bne _0212F094
	mov r0, #0xb
	strb r0, [r4, #0x152]
	bl ov11_0212FD74
	ldmia sp!, {r3, r4, r5, pc}
_0212F094:
	ldr r0, _0212F154 ; =OVERLAY11_BSS_02169C74
	ldr r0, [r0, #4]
	cmp r0, #5
	ldrne r0, [r4, #0x48]
	cmpne r0, #0
	bne _0212F0D0
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0x10
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, r4
	bl ov11_0212F3B0
	ldmia sp!, {r3, r4, r5, pc}
_0212F0D0:
	bl ov11_021301BC
	cmp r0, #1
	ldmgtia sp!, {r3, r4, r5, pc}
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r3, r2
	mov r1, #0xe
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldmia sp!, {r3, r4, r5, pc}
_0212F0F8:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r0, _0212F154 ; =OVERLAY11_BSS_02169C74
	ldr r0, [r0, #4]
	cmp r0, #4
	cmpne r0, #6
	ldmneia sp!, {r3, r4, r5, pc}
	ldr r0, [r4, #0x50]
	mov r1, r0
	bl ov11_02130210
	mov r0, r4
	mov r1, #7
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	ldmia sp!, {r3, r4, r5, pc}
_0212F130:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r4
	mov r1, #8
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0212F150: .word 0x00001C20
_0212F154: .word OVERLAY11_BSS_02169C74

	arm_func_start ov11_0212F158
ov11_0212F158: ; 0x0212F158
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	ldrb r1, [r4, #0x152]
	cmp r1, #0x14
	bgt _0212F1AC
	subs r0, r1, #0xd
	addpl pc, pc, r0, lsl #2
	b _0212F19C
_0212F17C: ; jump table
	b _0212F220 ; case 0
	b _0212F324 ; case 1
	b _0212F324 ; case 2
	b _0212F27C ; case 3
	b _0212F324 ; case 4
	b _0212F324 ; case 5
	b _0212F324 ; case 6
	b _0212F304 ; case 7
	arm_func_end ov11_0212F158
_0212F19C:
	cmp r1, #0
	beq _0212F1BC
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212F1AC:
	cmp r1, #0x19
	beq _0212F2DC
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212F1BC:
	ldr r0, [r4, #0x194]
	mov r1, #0
	str r1, [r0, #0x710]
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	mov r2, #1
	add r0, r4, #0x100
	mov r1, #0x78
	strh r1, [r0, #0x44]
	mov r0, #0xd
	strb r0, [r4, #0x152]
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r3, r2
	mov r1, #5
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x194]
	mov r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FBE4Ei
	mov r1, #0
	ldr r0, [r4, #0x194]
	sub r2, r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212F220:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	add r0, r4, #0x100
	ldrh r1, [r0, #0x44]
	sub r1, r1, #1
	strh r1, [r0, #0x44]
	ldrh r0, [r0, #0x44]
	cmp r0, #0
	addne sp, sp, #4
	ldmneia sp!, {r3, r4, pc}
	mov r0, #0x10
	strb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	ldr r1, [r4, #0x50]
	bl _ZN17UnkClass_0211E05C13ov11_02121000EPv
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r3, r2
	mov r1, #6
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212F27C:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02121010Ev
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	bge _0212F2BC
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x194]
	mov r1, #0xd
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #0x13
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212F2BC:
	ldr r0, [r4, #0x194]
	ldr r1, [r4, #0x188]
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_0212374CEii
	mov r0, #0x19
	add sp, sp, #4
	strb r0, [r4, #0x152]
	ldmia sp!, {r3, r4, pc}
_0212F2DC:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r0, r4
	mov r1, #8
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
_0212F304:
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	addeq sp, sp, #4
	ldmeqia sp!, {r3, r4, pc}
	mov r0, r4
	mov r1, #8
	bl _ZN17UnkClass_0212D97C13ov11_0212E9B4Ei
_0212F324:
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}

	arm_func_start ov11_0212F32C
ov11_0212F32C: ; 0x0212F32C
	cmp r0, #4
	addls pc, pc, r0, lsl #2
	bx lr
_0212F338: ; jump table
	b _0212F34C ; case 0
	b _0212F35C ; case 1
	b _0212F36C ; case 2
	b _0212F37C ; case 3
	b _0212F39C ; case 4
	arm_func_end ov11_0212F32C
_0212F34C:
	ldr r0, _0212F3AC ; =OVERLAY11_BSS_02169C74
	mov r1, #1
	str r1, [r0, #4]
	bx lr
_0212F35C:
	ldr r0, _0212F3AC ; =OVERLAY11_BSS_02169C74
	mov r1, #2
	str r1, [r0, #4]
	bx lr
_0212F36C:
	ldr r0, _0212F3AC ; =OVERLAY11_BSS_02169C74
	mov r1, #3
	str r1, [r0, #4]
	bx lr
_0212F37C:
	ldr r0, _0212F3AC ; =OVERLAY11_BSS_02169C74
	ldr r1, [r0, #4]
	cmp r1, #3
	moveq r1, #4
	streq r1, [r0, #4]
	movne r1, #6
	strne r1, [r0, #4]
	bx lr
_0212F39C:
	ldr r0, _0212F3AC ; =OVERLAY11_BSS_02169C74
	mov r1, #5
	str r1, [r0, #4]
	bx lr
	.align 2, 0
_0212F3AC: .word OVERLAY11_BSS_02169C74

	arm_func_start ov11_0212F3B0
ov11_0212F3B0: ; 0x0212F3B0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov11_0212FD74
	mov r0, #0x14
	strb r0, [r4, #0x152]
	ldr r0, [r4, #0x194]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldr r0, [r4, #0x194]
	mov r1, #0
	str r1, [r0, #0x710]
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212F3B0

	arm_func_start _ZN17UnkClass_0212F3DCC1Ev
_ZN17UnkClass_0212F3DCC1Ev: ; 0x0212F3DC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl ov11_021301D4
	rsb r0, r0, r0, lsl #1
	bl _Znam
	str r0, [r4]
	mov r0, #0xf000
	bl _Znam
	str r0, [r4, #4]
	mov r1, #0
	ldr r0, _0212F428 ; =OVERLAY11_BSS_02169C74
	strb r1, [r4, #8]
	str r1, [r0]
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x1000
	mov r2, #0
	mov r0, r4
	str r2, [r1, #0x5dc]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212F428: .word OVERLAY11_BSS_02169C74
	arm_func_end _ZN17UnkClass_0212F3DCC1Ev

	arm_func_start _ZN17UnkClass_0212F3DCD1Ev
_ZN17UnkClass_0212F3DCD1Ev: ; 0x0212F42C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0212F44C
	bl _ZdaPv
	mov r0, #0
	str r0, [r4]
	arm_func_end _ZN17UnkClass_0212F3DCD1Ev
_0212F44C:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0212F464
	bl _ZdaPv
	mov r0, #0
	str r0, [r4, #4]
_0212F464:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_0212F3DC13ov11_0212F46CEv
_ZN17UnkClass_0212F3DC13ov11_0212F46CEv: ; 0x0212F46C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrb r0, [r4, #8]
	cmp r0, #0x18
	bgt _0212F4A4
	bge _0212F588
	cmp r0, #4
	addls pc, pc, r0, lsl #2
	b _0212F5B8
_0212F490: ; jump table
	b _0212F4C0 ; case 0
	b _0212F4D0 ; case 1
	b _0212F5B8 ; case 2
	b _0212F504 ; case 3
	b _0212F51C ; case 4
	arm_func_end _ZN17UnkClass_0212F3DC13ov11_0212F46CEv
_0212F4A4:
	cmp r0, #0x19
	bgt _0212F4B4
	beq _0212F578
	b _0212F5B8
_0212F4B4:
	cmp r0, #0x1a
	beq _0212F5B0
	b _0212F5B8
_0212F4C0:
	mov r0, #1
	strb r0, [r4, #8]
	bl ov11_02128FEC
	b _0212F5B8
_0212F4D0:
	ldr r0, [r4, #4]
	ldr r2, [r4]
	ldr r1, _0212F5C0 ; =ov11_0212F5C8
	bl ov11_0212FE30
	cmp r0, #0
	moveq r0, #0x19
	streqb r0, [r4, #8]
	beq _0212F5B8
	mov r0, #3
	strb r0, [r4, #8]
	mov r0, #0x1e
	strh r0, [r4, #0xa]
	b _0212F5B8
_0212F504:
	ldr r0, _0212F5C4 ; =OVERLAY11_BSS_02169C74
	ldr r0, [r0]
	cmp r0, #1
	bne _0212F5B8
	mov r0, #4
	strb r0, [r4, #8]
_0212F51C:
	ldr r0, _0212F5C4 ; =OVERLAY11_BSS_02169C74
	ldr r1, [r0]
	sub r0, r1, #2
	cmp r0, #1
	bhi _0212F54C
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	mov r1, #1
	str r1, [r0, #0x5dc]
	mov r0, #0x19
	strb r0, [r4, #8]
	b _0212F5B8
_0212F54C:
	cmp r1, #5
	beq _0212F56C
	ldrh r0, [r4, #0xa]
	sub r0, r0, #1
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	bne _0212F5B8
_0212F56C:
	mov r0, #0x19
	strb r0, [r4, #8]
	b _0212F5B8
_0212F578:
	bl ov11_0212FD74
	mov r0, #0x18
	strb r0, [r4, #8]
	b _0212F5B8
_0212F588:
	ldr r0, _0212F5C4 ; =OVERLAY11_BSS_02169C74
	ldr r0, [r0]
	cmp r0, #4
	cmpne r0, #5
	cmpne r0, #6
	bne _0212F5B8
	bl ov11_02129040
	mov r0, #0x1a
	strb r0, [r4, #8]
	b _0212F5B8
_0212F5B0:
	mov r0, #0
	ldmia sp!, {r4, pc}
_0212F5B8:
	mov r0, #1
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212F5C0: .word ov11_0212F5C8
_0212F5C4: .word OVERLAY11_BSS_02169C74

	arm_func_start ov11_0212F5C8
ov11_0212F5C8: ; 0x0212F5C8
	cmp r0, #4
	addls pc, pc, r0, lsl #2
	bx lr
_0212F5D4: ; jump table
	b _0212F5E8 ; case 0
	b _0212F5F8 ; case 1
	b _0212F608 ; case 2
	b _0212F618 ; case 3
	b _0212F638 ; case 4
	arm_func_end ov11_0212F5C8
_0212F5E8:
	ldr r0, _0212F648 ; =OVERLAY11_BSS_02169C74
	mov r1, #1
	str r1, [r0]
	bx lr
_0212F5F8:
	ldr r0, _0212F648 ; =OVERLAY11_BSS_02169C74
	mov r1, #2
	str r1, [r0]
	bx lr
_0212F608:
	ldr r0, _0212F648 ; =OVERLAY11_BSS_02169C74
	mov r1, #3
	str r1, [r0]
	bx lr
_0212F618:
	ldr r0, _0212F648 ; =OVERLAY11_BSS_02169C74
	ldr r1, [r0]
	cmp r1, #3
	moveq r1, #4
	streq r1, [r0]
	movne r1, #6
	strne r1, [r0]
	bx lr
_0212F638:
	ldr r0, _0212F648 ; =OVERLAY11_BSS_02169C74
	mov r1, #5
	str r1, [r0]
	bx lr
	.align 2, 0
_0212F648: .word OVERLAY11_BSS_02169C74

	arm_func_start ov11_0212F64C
ov11_0212F64C: ; 0x0212F64C
	stmdb sp!, {r4, lr}
	ldr r1, _0212F6BC ; =OVERLAY11_BSS_02169C7C
	mov r4, r0
	ldr r3, [r1]
	cmp r3, #0
	beq _0212F680
	ldr r0, [r1, #4]
	ldr r1, _0212F6C0 ; =ptr_s_mywh_SYSSTATE_STOP_overlay_11_0216650c_overlay_11_021665ec
	add r0, r0, #0x1000
	ldr r2, [r0, #0x150]
	ldr r0, _0212F6C4 ; =s_s_overlay_11_02166614
	ldr r1, [r1, r2, lsl #2]
	blx r3
	arm_func_end ov11_0212F64C
_0212F680:
	ldr r1, _0212F6BC ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r1, #4]
	add r0, r0, #0x1000
	str r4, [r0, #0x150]
	ldr r3, [r1]
	cmp r3, #0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r1, #4]
	ldr r1, _0212F6C0 ; =ptr_s_mywh_SYSSTATE_STOP_overlay_11_0216650c_overlay_11_021665ec
	add r0, r0, #0x1000
	ldr r2, [r0, #0x150]
	ldr r0, _0212F6C8 ; =s_s_overlay_11_0216661c
	ldr r1, [r1, r2, lsl #2]
	blx r3
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212F6BC: .word OVERLAY11_BSS_02169C7C
_0212F6C0: .word ptr_s_mywh_SYSSTATE_STOP_overlay_11_0216650c_overlay_11_021665ec
_0212F6C4: .word s_s_overlay_11_02166614
_0212F6C8: .word s_s_overlay_11_0216661c

	arm_func_start ov11_0212F6CC
ov11_0212F6CC: ; 0x0212F6CC
	ldr r1, _0212F6EC ; =OVERLAY11_BSS_02169C7C
	ldr r1, [r1, #4]
	add r1, r1, #0x1000
	ldr r2, [r1, #0x150]
	sub r2, r2, #9
	cmp r2, #1
	strhi r0, [r1, #0x154]
	bx lr
	.align 2, 0
_0212F6EC: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_0212F6CC

	arm_func_start ov11_0212F6F0
ov11_0212F6F0: ; 0x0212F6F0
	stmdb sp!, {r3, lr}
	ldr r0, _0212F7B8 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x150]
	cmp r0, #4
	bne _0212F710
	bl OS_Terminate
	arm_func_end ov11_0212F6F0
_0212F710:
	mov r0, #2
	bl ov11_0212F64C
	ldr r1, _0212F7B8 ; =OVERLAY11_BSS_02169C7C
	ldr r2, _0212F7BC ; =0x0000FFFF
	ldr r0, [r1, #4]
	add r0, r0, #0xf00
	strh r2, [r0, #0xcc]
	ldr r0, [r1, #4]
	add r0, r0, #0xf00
	strh r2, [r0, #0xca]
	ldr r0, [r1, #4]
	add r0, r0, #0xf00
	strh r2, [r0, #0xc8]
	bl ov11_0212F7C0
	cmp r0, #0
	bne _0212F780
	mov r0, #9
	bl ov11_0212F64C
	ldr r0, _0212F7B8 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _0212F778
	mov r0, #4
	blx r1
_0212F778:
	mov r0, #0
	ldmia sp!, {r3, pc}
_0212F780:
	ldr r1, _0212F7B8 ; =OVERLAY11_BSS_02169C7C
	mov r2, #2
	ldr r0, [r1, #4]
	add r0, r0, #0x1100
	strh r2, [r0, #0x58]
	ldr r0, [r1, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _0212F7B0
	mov r0, #0
	blx r1
_0212F7B0:
	mov r0, #1
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212F7B8: .word OVERLAY11_BSS_02169C7C
_0212F7BC: .word 0x0000FFFF

	arm_func_start ov11_0212F7C0
ov11_0212F7C0: ; 0x0212F7C0
	stmdb sp!, {r4, r5, r6, lr}
	ldr r0, _0212F92C ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x150]
	cmp r0, #2
	beq _0212F7E4
	bl OS_Terminate
	movs r0, #0
	arm_func_end ov11_0212F7C0
_0212F7E4:
	bl WM_GetAllowedChannel
	cmp r0, #0x8000
	bne _0212F800
	mov r0, #3
	bl ov11_0212F6CC
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
_0212F800:
	cmp r0, #0
	bne _0212F818
	mov r0, #0x16
	bl ov11_0212F6CC
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
_0212F818:
	ldr r1, _0212F92C ; =OVERLAY11_BSS_02169C7C
	ldr r2, [r1, #4]
	add r1, r2, #0x1100
	ldrh r1, [r1, #0x76]
	cmp r1, #0x10
	blo _0212F89C
	sub r5, r1, #0x10
	mov r6, #0
	mov lr, #1
	ldr ip, _0212F930 ; =0x4EC4EC4F
	mov r3, #0xd
	b _0212F86C
_0212F848:
	add r4, r5, #1
	mov r1, r4, lsr #0x1f
	smull r2, r5, ip, r4
	add r5, r1, r5, asr #2
	smull r1, r2, r3, r5
	sub r5, r4, r1
	tst r0, lr, lsl r5
	bne _0212F874
	add r6, r6, #1
_0212F86C:
	cmp r6, #0xd
	blt _0212F848
_0212F874:
	ldr r1, _0212F92C ; =OVERLAY11_BSS_02169C7C
	add r3, r5, #0x10
	ldr r0, [r1, #4]
	add r2, r5, #1
	add r0, r0, #0x1100
	strh r3, [r0, #0x76]
	ldr r0, [r1, #4]
	add r0, r0, #0xf00
	strh r2, [r0, #0xc4]
	b _0212F8A4
_0212F89C:
	add r0, r2, #0xf00
	strh r1, [r0, #0xc4]
_0212F8A4:
	ldr r1, _0212F92C ; =OVERLAY11_BSS_02169C7C
	mov r2, #0xdc
	ldr r0, [r1, #4]
	add r0, r0, #0xf00
	strh r2, [r0, #0xc6]
	ldr r0, [r1, #4]
	add r2, r0, #0xf00
	str r2, [r0, #0xfc0]
	ldr r0, [r1, #4]
	add r0, r0, #0x1100
	ldrh r0, [r0, #0x58]
	cmp r0, #3
	bne _0212F900
	mov r3, #0
	b _0212F8F8
_0212F8E0:
	ldr r0, [r1, #4]
	add r2, r0, r3
	add r0, r2, #0x1000
	ldrb r0, [r0, #0x170]
	add r3, r3, #1
	strb r0, [r2, #0xfc8]
_0212F8F8:
	cmp r3, #6
	blt _0212F8E0
_0212F900:
	ldr r1, _0212F92C ; =OVERLAY11_BSS_02169C7C
	ldr r0, _0212F934 ; =ov11_0212F938
	ldr r1, [r1, #4]
	add r1, r1, #0xfc0
	bl WM_StartScan
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r4, r5, r6, pc}
	bl ov11_0212F6CC
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0212F92C: .word OVERLAY11_BSS_02169C7C
_0212F930: .word 0x4EC4EC4F
_0212F934: .word ov11_0212F938

	arm_func_start ov11_0212F938
ov11_0212F938: ; 0x0212F938
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _0212F97C
	bl ov11_0212F6CC
	mov r0, #9
	bl ov11_0212F64C
	ldr r0, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	mov r0, #4
	blx r1
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212F938
_0212F97C:
	ldr r0, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	ldr r2, [r0, #4]
	add r0, r2, #0x1000
	ldr r1, [r0, #0x150]
	cmp r1, #2
	beq _0212F9CC
	bl ov11_0212FB40
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, #9
	bl ov11_0212F64C
	ldr r0, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	mov r0, #4
	blx r1
	ldmia sp!, {r4, pc}
_0212F9CC:
	ldrh r1, [r4, #8]
	cmp r1, #3
	ldmeqia sp!, {r4, pc}
	cmp r1, #4
	beq _0212F9EC
	cmp r1, #5
	beq _0212F9F8
	b _0212FAFC
_0212F9EC:
	mov r1, #0
	str r1, [r0, #0x16c]
	b _0212FAFC
_0212F9F8:
	add r0, r2, #0xf00
	mov r1, #0xc0
	bl DC_InvalidateRange
	ldrh r0, [r4, #0x36]
	cmp r0, #8
	blo _0212FA20
	ldr r1, [r4, #0x3c]
	ldr r0, _0212FB38 ; =0x00400643
	cmp r1, r0
	beq _0212FA44
_0212FA20:
	ldr r0, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	ldr r3, [r0]
	cmp r3, #0
	beq _0212FAFC
	ldr r1, [r4, #0x3c]
	ldr r0, _0212FB3C ; =s_not_my_parent_ggid_d_d_overlay_11_02166620
	ldr r2, _0212FB38 ; =0x00400643
	blx r3
	b _0212FAFC
_0212FA44:
	ldr r1, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	ldrh r2, [r4, #0x12]
	ldr r0, [r1, #4]
	add r0, r0, #0x1000
	str r2, [r0, #0x16c]
	ldr r0, [r1, #4]
	add r0, r0, #0x1100
	ldrh r0, [r0, #0x58]
	cmp r0, #2
	bne _0212FAD4
	add r0, r4, #0x48
	bl ov11_0212FEC8
	ldr r1, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	mov r3, #0
_0212FA7C:
	add r2, r4, r3
	ldr r0, [r1, #4]
	ldrb r2, [r2, #0xa]
	add r0, r0, r3
	add r0, r0, #0x1000
	add r3, r3, #1
	strb r2, [r0, #0x170]
	cmp r3, #6
	blt _0212FA7C
	ldr r1, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r1, #4]
	add r0, r0, #0x1100
	ldrh r2, [r0, #0x76]
	sub r2, r2, #0xf
	strh r2, [r0, #0x76]
	ldr r0, [r1, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _0212FAD4
	mov r0, #1
	blx r1
_0212FAD4:
	add r0, r4, #0x48
	bl ov11_0212FF98
	cmp r0, #0
	beq _0212FAFC
	ldr r0, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	mov r1, #4
	ldr r0, [r0, #4]
	add r0, r0, #0x1100
	strh r1, [r0, #0x58]
	ldmia sp!, {r4, pc}
_0212FAFC:
	bl ov11_0212F7C0
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, #9
	bl ov11_0212F64C
	ldr r0, _0212FB34 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	mov r0, #4
	blx r1
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212FB34: .word OVERLAY11_BSS_02169C7C
_0212FB38: .word 0x00400643
_0212FB3C: .word s_not_my_parent_ggid_d_d_overlay_11_02166620

	arm_func_start ov11_0212FB40
ov11_0212FB40: ; 0x0212FB40
	stmdb sp!, {r3, lr}
	ldr r0, _0212FB64 ; =ov11_0212FB68
	bl WM_EndScan
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_0212F6CC
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FB64: .word ov11_0212FB68
	arm_func_end ov11_0212FB40

	arm_func_start ov11_0212FB68
ov11_0212FB68: ; 0x0212FB68
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0212FB80
	bl ov11_0212F6CC
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212FB68
_0212FB80:
	mov r0, #1
	bl ov11_0212F64C
	ldmia sp!, {r3, pc}

	arm_func_start ov11_0212FB8C
ov11_0212FB8C: ; 0x0212FB8C
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0212FBA8
	mov r0, #0xa
	bl ov11_0212F64C
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212FB8C
_0212FBA8:
	mov r0, #0
	bl ov11_0212F64C
	ldr r0, _0212FBD4 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	mov r0, #3
	blx r1
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FBD4: .word OVERLAY11_BSS_02169C7C

	arm_func_start ov11_0212FBD8
ov11_0212FBD8: ; 0x0212FBD8
	stmdb sp!, {r3, lr}
	ldr r1, _0212FC08 ; =OVERLAY11_BSS_02169C7C
	mov r2, #0
	ldr r0, [r1, #4]
	add r0, r0, #0x1000
	str r2, [r0, #0x154]
	str r2, [r1, #8]
	bl ov11_0212FC50
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FC08: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_0212FBD8

	arm_func_start ov11_0212FC0C
ov11_0212FC0C: ; 0x0212FC0C
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #8
	ldmneia sp!, {r3, pc}
	mov r0, #9
	bl ov11_0212F64C
	ldr r0, _0212FC4C ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _0212FC44
	mov r0, #4
	blx r1
	arm_func_end ov11_0212FC0C
_0212FC44:
	bl OS_Terminate
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FC4C: .word OVERLAY11_BSS_02169C7C

	arm_func_start ov11_0212FC50
ov11_0212FC50: ; 0x0212FC50
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_0212F64C
	ldr r0, _0212FC90 ; =OVERLAY11_BSS_02169C7C
	ldr r1, _0212FC94 ; =ov11_0212FC98
	ldr r0, [r0, #4]
	mov r2, #2
	bl WM_Initialize
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_0212F6CC
	mov r0, #0xa
	bl ov11_0212F64C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FC90: .word OVERLAY11_BSS_02169C7C
_0212FC94: .word ov11_0212FC98
	arm_func_end ov11_0212FC50

	arm_func_start ov11_0212FC98
ov11_0212FC98: ; 0x0212FC98
	stmdb sp!, {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0212FCB8
	bl ov11_0212F6CC
	mov r0, #0xa
	bl ov11_0212F64C
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212FC98
_0212FCB8:
	ldr r0, _0212FCF4 ; =ov11_0212FC0C
	bl WM_SetIndCallback
	cmp r0, #0
	beq _0212FCD8
	bl ov11_0212F6CC
	mov r0, #0xa
	bl ov11_0212F64C
	ldmia sp!, {r3, pc}
_0212FCD8:
	mov r0, #1
	bl ov11_0212F64C
	ldr r0, _0212FCF8 ; =OVERLAY11_BSS_02169C7C
	mov r1, #1
	str r1, [r0, #8]
	bl ov11_0212F6F0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FCF4: .word ov11_0212FC0C
_0212FCF8: .word OVERLAY11_BSS_02169C7C

	arm_func_start ov11_0212FCFC
ov11_0212FCFC: ; 0x0212FCFC
	stmdb sp!, {r3, lr}
	ldr r0, _0212FD6C ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x150]
	cmp r0, #1
	beq _0212FD1C
	bl OS_Terminate
	arm_func_end ov11_0212FCFC
_0212FD1C:
	mov r0, #3
	bl ov11_0212F64C
	ldr r0, _0212FD70 ; =ov11_0212FB8C
	bl WM_End
	cmp r0, #2
	beq _0212FD64
	mov r0, #9
	bl ov11_0212F64C
	ldr r0, _0212FD6C ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _0212FD5C
	mov r0, #4
	blx r1
_0212FD5C:
	mov r0, #0
	ldmia sp!, {r3, pc}
_0212FD64:
	mov r0, #1
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FD6C: .word OVERLAY11_BSS_02169C7C
_0212FD70: .word ov11_0212FB8C

	arm_func_start ov11_0212FD74
ov11_0212FD74: ; 0x0212FD74
	stmdb sp!, {r3, lr}
	ldr r0, _0212FDA0 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x150]
	cmp r0, #1
	bne _0212FD98
	bl ov11_0212FCFC
	ldmia sp!, {r3, pc}
	arm_func_end ov11_0212FD74
_0212FD98:
	bl ov11_0212FDA4
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FDA0: .word OVERLAY11_BSS_02169C7C

	arm_func_start ov11_0212FDA4
ov11_0212FDA4: ; 0x0212FDA4
	stmdb sp!, {r3, lr}
	mov r0, #3
	bl ov11_0212F64C
	ldr r0, _0212FDD0 ; =ov11_0212FDD4
	bl WM_Reset
	cmp r0, #2
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	bl ov11_0212F6CC
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FDD0: .word ov11_0212FDD4
	arm_func_end ov11_0212FDA4

	arm_func_start ov11_0212FDD4
ov11_0212FDD4: ; 0x0212FDD4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _0212FE1C
	mov r0, #9
	bl ov11_0212F64C
	ldrh r0, [r4, #2]
	bl ov11_0212F6CC
	ldr r0, _0212FE2C ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	mov r0, #4
	blx r1
	ldmia sp!, {r4, pc}
	arm_func_end ov11_0212FDD4
_0212FE1C:
	mov r0, #1
	bl ov11_0212F64C
	bl ov11_0212FCFC
	ldmia sp!, {r4, pc}
	.align 2, 0
_0212FE2C: .word OVERLAY11_BSS_02169C7C

	arm_func_start ov11_0212FE30
ov11_0212FE30: ; 0x0212FE30
	stmdb sp!, {r3, lr}
	add r2, r2, #0x1f
	bic r2, r2, #0x1f
	ldr ip, _0212FEC4 ; =OVERLAY11_BSS_02169C7C
	add r3, r2, #0x1000
	str r2, [ip, #4]
	mov r2, #0
	str r2, [r3, #0x150]
	ldr r3, [ip, #4]
	mov lr, #1
	add r3, r3, #0x1100
	strh lr, [r3, #0x58]
	ldr r3, [ip, #4]
	mov lr, #0x10
	add r3, r3, #0x1000
	str r0, [r3, #0x178]
	ldr r0, [ip, #4]
	sub r3, lr, #0x11
	add r0, r0, #0x1100
	strh r2, [r0, #0x5c]
	ldr r0, [ip, #4]
	add r0, r0, #0x1100
	strh r2, [r0, #0x5e]
	ldr r0, [ip, #4]
	add r0, r0, #0x1000
	str r1, [r0, #0x17c]
	ldr r0, [ip, #4]
	add r0, r0, #0x1100
	strh lr, [r0, #0x76]
	ldr r0, [ip, #4]
	add r0, r0, #0x1000
	str r2, [r0, #0x48]
	ldr r0, [ip, #4]
	add r0, r0, #0x1000
	str r3, [r0, #0x16c]
	bl ov11_0212FBD8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FEC4: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_0212FE30

	arm_func_start ov11_0212FEC8
ov11_0212FEC8: ; 0x0212FEC8
	stmdb sp!, {r3, lr}
	ldr r1, _0212FF90 ; =OVERLAY11_BSS_02169C7C
	mov r2, #0
	ldr r3, [r1, #4]
	mov lr, #3
	add r3, r3, #0x1000
	str r2, [r3, #0x48]
	ldr r3, [r1, #4]
	ldr ip, _0212FF94 ; =0x4EC4EC4F
	add r3, r3, #0x1100
	strh lr, [r3, #0x58]
	ldr r3, [r1, #4]
	ldrh lr, [r0]
	add r3, r3, #0x1100
	strh lr, [r3, #0x5a]
	ldr r3, [r1, #4]
	ldr lr, [r0, #4]
	add r0, r3, #0x1000
	str lr, [r0, #0x160]
	ldr r3, [r1, #4]
	add r0, r3, #0x1000
	ldr r0, [r0, #0x160]
	add r3, r3, #0x1100
	sub lr, r0, #1
	umull r0, ip, lr, ip
	mov ip, ip, lsr #5
	add r0, ip, #1
	strh r0, [r3, #0x5c]
	ldr r0, [r1, #4]
	add r0, r0, #0x1100
	strh r2, [r0, #0x5e]
	ldr r0, [r1, #4]
	add r0, r0, #0x1000
	str r2, [r0, #0x164]
	ldr ip, [r1, #4]
	add r0, ip, #0x1100
	ldrh r0, [r0, #0x5c]
	cmp r0, #0
	ldmleia sp!, {r3, pc}
	mov r3, r2
	arm_func_end ov11_0212FEC8
_0212FF68:
	add r0, ip, r2
	add r0, r0, #0x1000
	strb r3, [r0, #0x180]
	ldr ip, [r1, #4]
	add r2, r2, #1
	add r0, ip, #0x1100
	ldrh r0, [r0, #0x5c]
	cmp r2, r0
	blt _0212FF68
	ldmia sp!, {r3, pc}
	.align 2, 0
_0212FF90: .word OVERLAY11_BSS_02169C7C
_0212FF94: .word 0x4EC4EC4F

	arm_func_start ov11_0212FF98
ov11_0212FF98: ; 0x0212FF98
	stmdb sp!, {r4, lr}
	ldr r1, _02130184 ; =OVERLAY11_BSS_02169C7C
	mov r4, r0
	ldr r2, [r1, #4]
	ldrh r1, [r4]
	add r0, r2, #0x1100
	ldrh r0, [r0, #0x5a]
	cmp r0, r1
	bne _0212FFD0
	add r0, r2, #0x1000
	ldr r1, [r0, #0x160]
	ldr r0, [r4, #4]
	cmp r1, r0
	beq _0213001C
	arm_func_end ov11_0212FF98
_0212FFD0:
	add r0, r2, #0x1000
	ldr r2, [r0, #0x164]
	add r1, r2, #1
	str r1, [r0, #0x164]
	cmp r2, #0x10
	blo _02130014
	mov r0, r4
	bl ov11_0212FEC8
	ldr r0, _02130184 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _0213001C
	mov r0, #5
	blx r1
	b _0213001C
_02130014:
	mov r0, #0
	ldmia sp!, {r4, pc}
_0213001C:
	ldrh r2, [r4, #2]
	ldr r0, _02130188 ; =0x0000FFFF
	cmp r2, r0
	bne _0213005C
	ldr r1, _02130184 ; =OVERLAY11_BSS_02169C7C
	add r0, r4, #8
	ldr r1, [r1, #4]
	mov r2, #0x68
	add r1, r1, #0xfe0
	bl MIi_CpuCopy32
	ldr r0, _02130184 ; =OVERLAY11_BSS_02169C7C
	mov r1, #1
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	str r1, [r0, #0x48]
	b _0213017C
_0213005C:
	ldr r1, _02130184 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r1, #4]
	add r0, r0, #0x1000
	str r2, [r0, #0x168]
	ldr r2, [r1, #4]
	ldrh r1, [r4, #2]
	add r0, r2, #0x1100
	ldrh r0, [r0, #0x5c]
	cmp r1, r0
	blo _021300A4
	add r0, r2, #0x1000
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _0213009C
	mov r0, #4
	blx r1
_0213009C:
	mov r0, #9
	bl ov11_0212F64C
_021300A4:
	ldr r0, _02130184 ; =OVERLAY11_BSS_02169C7C
	ldrh r2, [r4, #2]
	ldr r1, [r0, #4]
	add r3, r1, #0x1180
	ldrb r1, [r3, r2]
	cmp r1, #0
	bne _0213017C
	mov r1, #1
	strb r1, [r3, r2]
	ldr r1, [r0, #4]
	ldrh ip, [r4, #2]
	add r0, r1, #0x1100
	ldrh r0, [r0, #0x5c]
	sub r0, r0, #1
	cmp ip, r0
	bne _0213010C
	mov r0, #0x68
	mul r3, ip, r0
	add r0, r1, #0x1000
	ldr r1, [r0, #0x178]
	ldr r2, [r0, #0x160]
	add r0, r4, #8
	add r1, r1, r3
	sub r2, r2, r3
	bl MIi_CpuCopy32
	b _02130124
_0213010C:
	add r0, r1, #0x1000
	ldr r0, [r0, #0x178]
	mov r2, #0x68
	mla r1, ip, r2, r0
	add r0, r4, #8
	bl MIi_CpuCopy32
_02130124:
	ldr r1, _02130184 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r1, #4]
	add r0, r0, #0x1100
	ldrh r2, [r0, #0x5e]
	add r2, r2, #1
	strh r2, [r0, #0x5e]
	ldr r2, [r1, #4]
	add r0, r2, #0x1100
	ldrh r1, [r0, #0x5e]
	ldrh r0, [r0, #0x5c]
	cmp r1, r0
	addeq r0, r2, #0x1000
	ldreq r1, [r0, #0x48]
	cmpeq r1, #1
	bne _0213017C
	ldr r1, [r0, #0x17c]
	cmp r1, #0
	beq _02130174
	mov r0, #2
	blx r1
_02130174:
	mov r0, #1
	ldmia sp!, {r4, pc}
_0213017C:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02130184: .word OVERLAY11_BSS_02169C7C
_02130188: .word 0x0000FFFF

	arm_func_start ov11_0213018C
ov11_0213018C: ; 0x0213018C
	ldr r0, _021301A0 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1100
	ldrh r0, [r0, #0x5e]
	bx lr
	.align 2, 0
_021301A0: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_0213018C

	arm_func_start ov11_021301A4
ov11_021301A4: ; 0x021301A4
	ldr r0, _021301B8 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1100
	ldrh r0, [r0, #0x5c]
	bx lr
	.align 2, 0
_021301B8: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_021301A4

	arm_func_start ov11_021301BC
ov11_021301BC: ; 0x021301BC
	ldr r0, _021301D0 ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x16c]
	bx lr
	.align 2, 0
_021301D0: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_021301BC

	arm_func_start ov11_021301D4
ov11_021301D4: ; 0x021301D4
	mov r0, #0x1400
	bx lr
	arm_func_end ov11_021301D4

	arm_func_start ov11_021301DC
ov11_021301DC: ; 0x021301DC
	ldr r0, _021301FC ; =OVERLAY11_BSS_02169C7C
	ldr r1, [r0, #4]
	add r0, r1, #0x1000
	ldr r0, [r0, #0x48]
	cmp r0, #0
	addne r0, r1, #0xfe0
	moveq r0, #0
	bx lr
	.align 2, 0
_021301FC: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_021301DC

	arm_func_start ov11_02130200
ov11_02130200: ; 0x02130200
	ldr r0, _0213020C ; =OVERLAY11_BSS_02169C7C
	ldr r0, [r0, #8]
	bx lr
	.align 2, 0
_0213020C: .word OVERLAY11_BSS_02169C7C
	arm_func_end ov11_02130200

	arm_func_start ov11_02130210
ov11_02130210: ; 0x02130210
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #8
	mov r5, r0
	ldr r0, _021302D0 ; =OVERLAY11_BSS_02169C7C
	mov r4, r1
	ldr r1, [r0, #4]
	add r3, sp, #0
	mov r2, #0
	arm_func_end ov11_02130210
_02130230:
	add r0, r1, r2
	add r0, r0, #0x1000
	ldrb r0, [r0, #0x170]
	add r2, r2, #1
	cmp r2, #6
	strb r0, [r3], #1
	blt _02130230
	ldr r0, _021302D0 ; =OVERLAY11_BSS_02169C7C
	ldrh r1, [sp, #2]
	ldr lr, [r0, #4]
	ldr ip, _021302D4 ; =0x00005FA2
	strh r1, [sp, #6]
	add r0, lr, #0x1100
	ldrh r0, [r0, #0x5a]
	mov r3, #0
	add r1, sp, #0
	strh r0, [sp, #2]
_02130274:
	mov r2, r3, lsl #1
	ldrh r0, [r1, r2]
	add r3, r3, #1
	cmp r3, #4
	eor r0, ip, r0
	strh r0, [r1, r2]
	ldrh ip, [r1, r2]
	blt _02130274
	add r0, lr, #0x4c
	add r0, r0, #0x1000
	mov r2, #8
	bl CRYPTO_RC4Init
	ldr r0, _021302D0 ; =OVERLAY11_BSS_02169C7C
	mov r1, r5
	ldr r0, [r0, #4]
	mov r3, r4
	add r2, r0, #0x1000
	add r0, r0, #0x4c
	ldr r2, [r2, #0x160]
	add r0, r0, #0x1000
	bl CRYPTO_RC4Encrypt
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_021302D0: .word OVERLAY11_BSS_02169C7C
_021302D4: .word 0x00005FA2

	arm_func_start _ZN17UnkClass_021302D8C1EP5CGame
_ZN17UnkClass_021302D8C1EP5CGame: ; 0x021302D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r1, [r4, #0x10]
	bl ov11_02130310
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021302D8C1EP5CGame

	arm_func_start _ZN17UnkClass_021302D8D1Ev
_ZN17UnkClass_021302D8D1Ev: ; 0x021302F0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x14]
	cmp r0, #0
	beq _02130308
	bl _Z9Heap_FreePv
	arm_func_end _ZN17UnkClass_021302D8D1Ev
_02130308:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start ov11_02130310
ov11_02130310: ; 0x02130310
	mov r1, #0
	str r1, [r0, #0x14]
	bx lr
	arm_func_end ov11_02130310

	arm_func_start ov11_0213031C
ov11_0213031C: ; 0x0213031C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq _0213033C
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r5, #0x14]
	arm_func_end ov11_0213031C
_0213033C:
	mov r0, #0x700
	mov r1, #0x20
	bl _Z23Heap_AllocWithAlignmentmm
	str r0, [r5, #0x14]
	bl DWC_Init
	mov r4, r0
	bl DWC_ClearError
	ldr r0, [r5, #0x14]
	cmp r0, #0
	beq _02130370
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r5, #0x14]
_02130370:
	ldr r0, _02130384 ; =ov11_02130470
	ldr r1, _02130388 ; =ov11_021304A4
	bl DWC_SetMemFunc
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02130384: .word ov11_02130470
_02130388: .word ov11_021304A4

	arm_func_start ov11_0213038C
ov11_0213038C: ; 0x0213038C
	mov r1, #0
	strh r1, [r0]
	bx lr
	arm_func_end ov11_0213038C

	arm_func_start ov11_02130398
ov11_02130398: ; 0x02130398
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #0x3c
	mov r4, r0
	ldrh r1, [r4]
	cmp r1, #0
	beq _021303C4
	cmp r1, #1
	beq _021303FC
	cmp r1, #2
	beq _02130418
	b _02130464
	arm_func_end ov11_02130398
_021303C4:
	bl ov11_0213031C
	cmp r0, #3
	addeq sp, sp, #0x3c
	moveq r0, #1
	ldmeqia sp!, {r3, r4, pc}
	bl _Z15SetupInterruptsv
	add r0, r4, #4
	bl DWC_InitInet
	mov r0, #2
	bl DWC_SetAuthServer
	bl DWC_ConnectInetAsync
	mov r0, #1
	strh r0, [r4]
	b _02130464
_021303FC:
	bl DWC_ProcessInet
	bl DWC_GetInetStatus
	bl DWC_CheckInet
	cmp r0, #0
	beq _02130464
	mov r0, #2
	strh r0, [r4]
_02130418:
	bl DWC_GetInetStatus
	cmp r0, #4
	beq _02130450
	cmp r0, #7
	beq _02130438
	cmp r0, #8
	beq _02130444
	b _02130464
_02130438:
	add sp, sp, #0x3c
	mov r0, #2
	ldmia sp!, {r3, r4, pc}
_02130444:
	add sp, sp, #0x3c
	mov r0, #2
	ldmia sp!, {r3, r4, pc}
_02130450:
	add r0, sp, #0
	bl DWC_GetApInfo
	add sp, sp, #0x3c
	mov r0, #0
	ldmia sp!, {r3, r4, pc}
_02130464:
	mov r0, #3
	add sp, sp, #0x3c
	ldmia sp!, {r3, r4, pc}

	arm_func_start ov11_02130470
ov11_02130470: ; 0x02130470
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r1
	mov r4, r2
	bl OS_DisableInterrupts
	mov r5, r0
	mov r0, r6
	mov r1, r4
	bl _Z23Heap_AllocWithAlignmentmm
	mov r4, r0
	mov r0, r5
	bl OS_RestoreInterrupts
	mov r0, r4
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end ov11_02130470

	arm_func_start ov11_021304A4
ov11_021304A4: ; 0x021304A4
	ldr ip, _021304B0 ; =FUN_020022F4
	mov r0, r1
	bx ip
	.align 2, 0
_021304B0: .word _Z9Heap_FreePv
	arm_func_end ov11_021304A4

	arm_func_start _ZN17UnkClass_021302D813ov11_021304B4Ev
_ZN17UnkClass_021302D813ov11_021304B4Ev: ; 0x021304B4
	stmdb sp!, {r4, lr}
	mov r0, #0x40000
	bl _Z10Heap_Allocm
	mov r4, r0
	mov r1, #1
	mov r2, #0
	bl DWC_StartUtility
	mov r0, r4
	bl _Z9Heap_FreePv
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021302D813ov11_021304B4Ev

	arm_func_start _ZN17UnkClass_021304DCC1EP5CGameP17UnkClass_021302D8P17UnkClass_0211E05C
_ZN17UnkClass_021304DCC1EP5CGameP17UnkClass_021302D8P17UnkClass_0211E05C: ; 0x021304DC
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r1, [r4, #0x4dc]
	str r2, [r4, #0x4d8]
	str r3, [r4, #0x4e0]
	bl ov11_02130B14
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_021304DCC1EP5CGameP17UnkClass_021302D8P17UnkClass_0211E05C

	arm_func_start _ZN17UnkClass_021304DCD1Ev
_ZN17UnkClass_021304DCD1Ev: ; 0x021304FC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x4c0]
	cmp r0, #0
	beq _02130514
	bl _Z9Heap_FreePv
	arm_func_end _ZN17UnkClass_021304DCD1Ev
_02130514:
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_021304DC13ov11_0213051CEv
_ZN17UnkClass_021304DC13ov11_0213051CEv: ; 0x0213051C
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	mov r4, r0
	ldrh r1, [r4, #0x2c]
	cmp r1, #0xe
	addls pc, pc, r1, lsl #2
	b _02130AF8
_02130538: ; jump table
	b _02130AF8 ; case 0
	b _02130574 ; case 1
	b _021305AC ; case 2
	b _02130678 ; case 3
	b _021307B8 ; case 4
	b _021307C8 ; case 5
	b _021307E4 ; case 6
	b _02130AF8 ; case 7
	b _02130AF8 ; case 8
	b _02130854 ; case 9
	b _0213087C ; case 10
	b _021309C0 ; case 11
	b _021309F4 ; case 12
	b _02130A8C ; case 13
	b _02130AA4 ; case 14
	arm_func_end _ZN17UnkClass_021304DC13ov11_0213051CEv
_02130574:
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	ldr r0, [r4, #0x4d8]
	bl ov11_0213038C
	mov r0, #2
	strh r0, [r4, #0x2c]
	mov r0, #0
	str r0, [r4, #0x4b8]
	ldr r0, [r4, #0x4e0]
	mov r1, #1
	str r1, [r0, #0x710]
_021305AC:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0212247CEv
	cmp r0, #0
	bge _021305D8
	ldr r0, _02130B04 ; =DAT_overlay_11_02166640
	mov r1, #6
	str r1, [r0]
	strh r1, [r4, #0x2c]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	b _02130AF8
_021305D8:
	ldr r0, [r4, #0x4d8]
	bl ov11_02130398
	cmp r0, #3
	beq _02130AF8
	cmp r0, #1
	bne _02130634
	ldr r0, _02130B04 ; =DAT_overlay_11_02166640
	mov r1, #9
	str r1, [r0]
	mov r1, #6
	ldr r0, _02130B08 ; =0x00001C20
	strh r1, [r4, #0x2c]
	str r0, [r4, #0x4c4]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #0xf
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	b _02130AF8
_02130634:
	cmp r0, #2
	bne _0213065C
	ldr r0, _02130B04 ; =DAT_overlay_11_02166640
	mov r1, #8
	str r1, [r0]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	mov r0, #6
	strh r0, [r4, #0x2c]
	b _02130AF8
_0213065C:
	mov r0, #3
	strh r0, [r4, #0x2c]
	add r0, r4, #0x400
	mov r1, #0x18
	strh r1, [r0, #0xb4]
	mov r0, #0
	str r0, [r4, #0x4b8]
_02130678:
	mov r0, r4
	bl ov11_02130B48
	ldr r1, _02130B04 ; =DAT_overlay_11_02166640
	cmp r0, #8
	str r0, [r1]
	addls pc, pc, r0, lsl #2
	b _02130AF8
_02130694: ; jump table
	b _0213072C ; case 0
	b _021306F4 ; case 1
	b _02130AF8 ; case 2
	b _02130AF8 ; case 3
	b _02130740 ; case 4
	b _0213075C ; case 5
	b _021306B8 ; case 6
	b _02130794 ; case 7
	b _02130710 ; case 8
_021306B8:
	mov r0, #6
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldr r0, [r4, #0x4b8]
	cmp r0, #0
	beq _02130AF8
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #0x18
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	b _02130AF8
_021306F4:
	mov r0, #1
	str r0, [r1]
	mov r0, #6
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	b _02130AF8
_02130710:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211EFB4Ev
	mov r0, #6
	strh r0, [r4, #0x2c]
	b _02130AF8
_0213072C:
	mov r0, #0xc
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	b _02130AF8
_02130740:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	mov r0, #6
	strh r0, [r4, #0x2c]
	mov r0, #0
	str r0, [r4, #0x4c4]
	b _02130AF8
_0213075C:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #0x18
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #4
	strh r0, [r4, #0x2c]
	mov r0, #0
	str r0, [r4, #0x4c4]
	b _02130AF8
_02130794:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211EFB4Ev
	mov r0, #6
	strh r0, [r4, #0x2c]
	mov r0, #0
	str r0, [r4, #0x4c4]
	b _02130AF8
_021307B8:
	mov r0, #0x78
	str r0, [r4, #0x4c4]
	mov r0, #5
	strh r0, [r4, #0x2c]
_021307C8:
	ldr r0, [r4, #0x4c4]
	sub r0, r0, #1
	str r0, [r4, #0x4c4]
	cmp r0, #0
	movle r0, #6
	strleh r0, [r4, #0x2c]
	b _02130AF8
_021307E4:
	mov r1, #0x78
	ldr r0, _02130B04 ; =DAT_overlay_11_02166640
	str r1, [r4, #0x4c4]
	ldr r0, [r0]
	cmp r0, #5
	beq _02130810
	cmp r0, #6
	bne _02130818
	ldr r0, [r4, #0x4b8]
	cmp r0, #0
	beq _02130818
_02130810:
	mov r0, #0
	str r0, [r4, #0x4c4]
_02130818:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	ldr r1, _02130B0C ; =OVERLAY11_BSS_02169C88
	mov r2, #0
	ldr r0, _02130B10 ; =ov11_021316C4
	str r2, [r1, #4]
	bl DWC_NdCleanupAsync
	cmp r0, #0
	movne r0, #9
	strneh r0, [r4, #0x2c]
	bne _02130AF8
	bl DWC_CleanupInet
	mov r0, #0xa
	strh r0, [r4, #0x2c]
	b _02130AF8
_02130854:
	ldr r1, [r4, #0x4c4]
	ldr r0, _02130B0C ; =OVERLAY11_BSS_02169C88
	add r1, r1, #1
	str r1, [r4, #0x4c4]
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02130AF8
	bl DWC_CleanupInet
	mov r0, #0xa
	strh r0, [r4, #0x2c]
_0213087C:
	ldr r0, [r4, #0x4c4]
	add r0, r0, #1
	str r0, [r4, #0x4c4]
	cmp r0, #0x78
	blt _02130AF8
	mov r0, #0xc
	strh r0, [r4, #0x2c]
	mov r2, #0
	ldr r0, _02130B04 ; =DAT_overlay_11_02166640
	str r2, [r4, #0x4c4]
	ldr r0, [r0]
	cmp r0, #8
	addls pc, pc, r0, lsl #2
	b _02130AF8
_021308B4: ; jump table
	b _02130AF8 ; case 0
	b _021308D8 ; case 1
	b _02130AF8 ; case 2
	b _02130AF8 ; case 3
	b _0213095C ; case 4
	b _02130988 ; case 5
	b _0213091C ; case 6
	b _021308F4 ; case 7
	b _021309B4 ; case 8
_021308D8:
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	b _02130AF8
_021308F4:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211EFB4Ev
	mov r0, #1
	str r0, [sp]
	mov r1, #5
	ldr r0, [r4, #0x4e0]
	mov r2, r1
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	b _02130AF8
_0213091C:
	ldr r0, [r4, #0x4b8]
	cmp r0, #0
	moveq r0, #0xb
	streqh r0, [r4, #0x2c]
	beq _02130AF8
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #0x19
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #0x78
	str r0, [r4, #0x4c4]
	mov r0, #0xb
	strh r0, [r4, #0x2c]
	b _02130AF8
_0213095C:
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #0x31
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #0
	str r0, [r4, #0x4c4]
	mov r0, #0xc
	strh r0, [r4, #0x2c]
	b _02130AF8
_02130988:
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #0x30
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #0
	str r0, [r4, #0x4c4]
	mov r0, #0xc
	strh r0, [r4, #0x2c]
	b _02130AF8
_021309B4:
	mov r0, r4
	bl ov11_02131710
	b _02130AF8
_021309C0:
	ldr r0, [r4, #0x4c4]
	sub r0, r0, #1
	str r0, [r4, #0x4c4]
	cmp r0, #0
	bgt _02130AF8
	mov r2, #1
	str r2, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #0xf
	mov r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #0xc
	strh r0, [r4, #0x2c]
_021309F4:
	ldr r0, _02130B04 ; =DAT_overlay_11_02166640
	ldr r0, [r0]
	cmp r0, #9
	addls pc, pc, r0, lsl #2
	b _02130A80
_02130A08: ; jump table
	b _02130A80 ; case 0
	b _02130A30 ; case 1
	b _02130A80 ; case 2
	b _02130A80 ; case 3
	b _02130A30 ; case 4
	b _02130A30 ; case 5
	b _02130A4C ; case 6
	b _02130AF8 ; case 7
	b _02130A30 ; case 8
	b _02130A30 ; case 9
_02130A30:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	beq _02130AF8
	add sp, sp, #4
	mov r0, #1
	ldmia sp!, {r3, r4, pc}
_02130A4C:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	beq _02130AF8
	mov r1, #0
	ldr r0, [r4, #0x4e0]
	sub r2, r1, #1
	bl _ZN17UnkClass_0211E05C13ov11_0211FB08Eii
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02124520Ev
	add sp, sp, #4
	mov r0, #3
	ldmia sp!, {r3, r4, pc}
_02130A80:
	add sp, sp, #4
	mov r0, #0
	ldmia sp!, {r3, r4, pc}
_02130A8C:
	bl ov11_02131710
	mov r1, #0xe
	ldr r0, _02130B08 ; =0x00001C20
	strh r1, [r4, #0x2c]
	str r0, [r4, #0x4c4]
	b _02130AF8
_02130AA4:
	ldr r0, [r4, #0x4c4]
	sub r0, r0, #1
	str r0, [r4, #0x4c4]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	bne _02130ACC
	ldr r0, [r4, #0x4c4]
	cmp r0, #0
	bgt _02130AF8
_02130ACC:
	mov r1, #0
	ldr r0, _02130B04 ; =DAT_overlay_11_02166640
	str r1, [r4, #0x4c4]
	ldr r0, [r0]
	cmp r0, #9
	bne _02130AF0
	mov r0, #6
	strh r0, [r4, #0x2c]
	b _02130AF8
_02130AF0:
	mov r0, #5
	strh r0, [r4, #0x2c]
_02130AF8:
	mov r0, #2
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02130B04: .word DAT_overlay_11_02166640
_02130B08: .word 0x00001C20
_02130B0C: .word OVERLAY11_BSS_02169C88
_02130B10: .word ov11_021316C4

	arm_func_start ov11_02130B14
ov11_02130B14: ; 0x02130B14
	mov r1, #0
	str r1, [r0, #0x4c0]
	strh r1, [r0, #0x2c]
	add r0, r0, #0x400
	mov r1, #0x18
	strh r1, [r0, #0xb4]
	bx lr
	arm_func_end ov11_02130B14

	arm_func_start _ZN17UnkClass_021304DC13ov11_02130B30Ev
_ZN17UnkClass_021304DC13ov11_02130B30Ev: ; 0x02130B30
	mov r1, #1
	strh r1, [r0, #0x2c]
	add r0, r0, #0x400
	mov r1, #0x18
	strh r1, [r0, #0xb4]
	bx lr
	arm_func_end _ZN17UnkClass_021304DC13ov11_02130B30Ev

	arm_func_start ov11_02130B48
ov11_02130B48: ; 0x02130B48
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x34
	mov r4, r0
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0212247CEv
	cmp r0, #0
	bge _02130BE8
	ldr r0, [r4, #0x4b8]
	cmp r0, #0
	addeq sp, sp, #0x34
	moveq r0, #6
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F96CEv
	ldr r0, [r4, #0x4e0]
	mov r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FBE4Ei
	ldr r0, [r4, #0x4e0]
	mov r1, #0
	bl _ZN17UnkClass_0211E05C13ov11_02124438Ei
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F904Ev
	ldr r0, [r4, #0x4e0]
	mov r1, #0xb
	bl _ZN17UnkClass_0211E05C13ov11_021217C0Ei
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211EFB4Ev
	mov r2, #0
	mov r1, #0xa
	add r0, r4, #0x400
	strh r1, [r0, #0xb4]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #0x17
	mov r3, r2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add sp, sp, #0x34
	mov r0, #3
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	arm_func_end ov11_02130B48
_02130BE8:
	add r0, r4, #0x400
	ldrh r1, [r0, #0xb4]
	cmp r1, #0x19
	addls pc, pc, r1, lsl #2
	b _02131668
_02130BFC: ; jump table
	b _02130CEC ; case 0
	b _02130D2C ; case 1
	b _02130DF4 ; case 2
	b _02130ED4 ; case 3
	b _02130D9C ; case 4
	b _02130E1C ; case 5
	b _02130E80 ; case 6
	b _02130EFC ; case 7
	b _0213103C ; case 8
	b _02131068 ; case 9
	b _0213158C ; case 10
	b _0213110C ; case 11
	b _021311CC ; case 12
	b _02131200 ; case 13
	b _0213151C ; case 14
	b _02131558 ; case 15
	b _021312C4 ; case 16
	b _02131340 ; case 17
	b _02131380 ; case 18
	b _02131668 ; case 19
	b _021313CC ; case 20
	b _02131418 ; case 21
	b _021314CC ; case 22
	b _02131574 ; case 23
	b _02130C64 ; case 24
	b _02130CAC ; case 25
_02130C64:
	mov r3, #0
	str r3, [r4, #0x4b8]
	mov r2, #0x18
	ldr r1, _02131684 ; =OVERLAY11_BSS_02169C88
	strh r2, [r0, #0xb6]
	str r3, [r1]
	str r3, [r1, #8]
	bl DWC_NASLoginAsync
	cmp r0, #0
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r0, r4, #0x400
	mov r2, #0x19
	ldr r1, _02131688 ; =0x00001C20
	strh r2, [r0, #0xb4]
	str r1, [r4, #0x4c8]
	b _02131668
_02130CAC:
	bl DWC_NASLoginProcess
	cmp r0, #2
	beq _02130CC4
	cmp r0, #3
	beq _02130CD0
	b _02130CE0
_02130CC4:
	add sp, sp, #0x34
	mov r0, #3
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02130CD0:
	add r0, r4, #0x400
	mov r1, #0
	strh r1, [r0, #0xb4]
	b _02131668
_02130CE0:
	add sp, sp, #0x34
	mov r0, #8
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02130CEC:
	ldr r3, _02131684 ; =OVERLAY11_BSS_02169C88
	mov r5, #0
	str r5, [r3]
	ldr r0, _0213168C ; =ov11_021316A8
	ldr r1, _02131690 ; =s_YP2E_overlay_11_02166644
	ldr r2, _02131694 ; =s_griUBMRWtExs4ZNS_overlay_11_0216664c
	str r5, [r3, #8]
	bl DWC_NdInitAsync
	cmp r0, #0
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r0, r4, #0x400
	mov r1, #1
	strh r1, [r0, #0xb4]
	b _02131668
_02130D2C:
	bl DWC_UpdateConnection
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	bl ov11_021316D8
	cmp r0, #0
	beq _02131668
	ldr r0, _02131684 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0]
	cmp r0, #1
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	mov r0, #1
	str r0, [r4, #0x4b8]
	add r0, r4, #0x400
	mov r1, #2
	strh r1, [r0, #0xb6]
	mov r1, #4
	strh r1, [r0, #0xb4]
_02130D9C:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r0, r4
	bl ov11_021316E8
	ldr r1, _02131684 ; =OVERLAY11_BSS_02169C88
	mov r2, #0
	str r2, [r1]
	add r0, r4, #0x4b0
	str r2, [r1, #8]
	bl DWC_NdGetFileListNumAsync
	cmp r0, #0
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r0, r4, #0x400
	mov r1, #5
	strh r1, [r0, #0xb4]
	b _02131668
_02130DF4:
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add r0, r4, #0x400
	mov r1, #5
	strh r1, [r0, #0xb4]
_02130E1C:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	bl ov11_021316D8
	cmp r0, #0
	beq _02131668
	ldr r0, _02131684 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0]
	cmp r0, #1
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r4, #0x4b0]
	cmp r0, #0
	addeq sp, sp, #0x34
	moveq r0, #1
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r0, r4, #0x400
	mov r1, #6
	strh r1, [r0, #0xb4]
	mov r1, #3
	strh r1, [r0, #0xb6]
_02130E80:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r3, _02131684 ; =OVERLAY11_BSS_02169C88
	mov r1, #0
	str r1, [r3]
	add r0, r4, #0x38
	mov r2, #6
	str r1, [r3, #8]
	bl DWC_NdGetFileListAsync
	cmp r0, #0
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	add r0, r4, #0x400
	mov r1, #7
	strh r1, [r0, #0xb4]
	b _02131668
_02130ED4:
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r0, [r4, #0x4e0]
	mov r3, r2
	mov r1, #2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add r0, r4, #0x400
	mov r1, #7
	strh r1, [r0, #0xb4]
_02130EFC:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	bl ov11_021316D8
	cmp r0, #0
	beq _02131668
	ldr r0, _02131684 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0]
	cmp r0, #1
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r4, #0x4b0]
	cmp r0, #0
	beq _02130F4C
	cmp r0, #6
	ble _02130F58
_02130F4C:
	add sp, sp, #0x34
	mov r0, #1
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02130F58:
	mov fp, #0
	mov r2, fp
	mvn r1, #0
_02130F64:
	add r0, r4, r2, lsl #2
	add r2, r2, #1
	str r1, [r0, #0x484]
	cmp r2, #0xb
	blt _02130F64
	mov r7, #0
	add r6, sp, #0xc
	mvn r5, #0
_02130F84:
	ldr r1, _02131698 ; =s_PRS_MISSION_02d_prs_overlay_11_02166660
	mov r0, r6
	add r2, r7, #1
	bl OS_SPrintf
	ldr sl, [r4, #0x4b0]
	mov r8, #0
	cmp sl, #0
	ble _02130FD4
	add sb, r4, #0x38
_02130FA8:
	mov r0, r6
	mov r1, sb
	bl strcmp
	cmp r0, #0
	addeq r0, r4, r8, lsl #2
	streq r7, [r0, #0x484]
	beq _02130FD4
	add r8, r8, #1
	cmp r8, sl
	add sb, sb, #0xb0
	blt _02130FA8
_02130FD4:
	ldr r0, [r4, #0x4b0]
	cmp r8, r0
	addge r0, r4, r7, lsl #2
	strge r5, [r0, #0x458]
	bge _02130FF8
	mov fp, #1
	add r1, r4, r7, lsl #2
	mov r0, fp
	str r0, [r1, #0x458]
_02130FF8:
	add r7, r7, #1
	cmp r7, #0xb
	blt _02130F84
	cmp fp, #0
	addeq sp, sp, #0x34
	moveq r0, #1
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd2
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
_0213103C:
	add r1, r4, #0x58
	ldr r0, [r4, #0x4e0]
	add r1, r1, #0x400
	mov r2, #1
	mov r3, #6
	bl _ZN17UnkClass_0211E05C13ov11_021217D4EPKiii
	add r0, r4, #0x400
	mov r1, #8
	strh r1, [r0, #0xb6]
	mov r1, #9
	strh r1, [r0, #0xb4]
_02131068:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_021212B4Ev
	cmp r0, #0
	bge _021310C8
	ldr r0, [r4, #0x4e0]
	ldr r0, [r0, #0x70c]
	cmp r0, #0
	ldrne r0, _02131688 ; =0x00001C20
	strne r0, [r4, #0x4c8]
	bne _02131668
	ldr r0, [r4, #0x4c8]
	sub r0, r0, #1
	str r0, [r4, #0x4c8]
	cmp r0, #0
	bgt _02131668
	add sp, sp, #0x34
	mov r0, #5
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_021310C8:
	ldr r3, [r4, #0x4b0]
	mov r2, #0
	cmp r3, #0
	ble _021310F8
	sub r1, r0, #0xb
_021310DC:
	add r0, r4, r2, lsl #2
	ldr r0, [r0, #0x484]
	cmp r1, r0
	beq _021310F8
	add r2, r2, #1
	cmp r2, r3
	blt _021310DC
_021310F8:
	cmp r2, r3
	strlt r2, [r4, #0x4bc]
	add r0, r4, #0x400
	mov r1, #0xb
	strh r1, [r0, #0xb4]
_0213110C:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r4, #0x4c0]
	cmp r0, #0
	beq _0213113C
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r4, #0x4c0]
_0213113C:
	ldr r1, [r4, #0x4bc]
	mov r0, #0xb0
	mla r0, r1, r0, r4
	ldr r0, [r0, #0xe4]
	bl _Z10Heap_Allocm
	cmp r0, #0
	str r0, [r4, #0x4c0]
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, _02131684 ; =OVERLAY11_BSS_02169C88
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #8]
	ldr r1, [r4, #0x4bc]
	mov r0, #0xb0
	mul r5, r1, r0
	add r0, r4, r5
	add r3, r4, #0x38
	ldr r2, [r0, #0xe4]
	ldr r1, [r4, #0x4c0]
	add r0, r3, r5
	bl DWC_NdGetFileAsync
	cmp r0, #0
	addeq sp, sp, #0x34
	moveq r0, #8
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #0
	str r0, [r4, #0x34]
	str r0, [r4, #0x4d0]
	str r0, [r4, #0x4d4]
_021311CC:
	mov r3, #1
	str r3, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #4
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211EF5CEv
	add r0, r4, #0x400
	mov r1, #0xd
	strh r1, [r0, #0xb4]
	mov r1, #0xc
	strh r1, [r0, #0xb6]
_02131200:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r0, _02131684 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _02131288
	add r0, sp, #8
	add r1, sp, #4
	bl DWC_NdGetProgress
	cmp r0, #1
	bne _02131264
	ldr r1, [sp, #8]
	ldr r0, [r4, #0x4d4]
	cmp r0, r1
	beq _02131264
	str r1, [r4, #0x4d4]
	mov r0, #0
	str r0, [r4, #0x4d0]
	b _02131668
_02131264:
	ldr r1, [r4, #0x4d0]
	ldr r0, _0213169C ; =0x00000708
	add r1, r1, #1
	str r1, [r4, #0x4d0]
	cmp r1, r0
	blt _02131668
	add sp, sp, #0x34
	mov r0, #4
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02131288:
	ldr r0, [r4, #0x4e0]
	mov r1, #3
	bl _ZN17UnkClass_0211E05C13ov11_0211FBE4Ei
	mov r3, #1
	str r3, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #0x2d
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add r0, r4, #0x400
	mov r1, #0x10
	strh r1, [r0, #0xb4]
	mov r0, #0x78
	str r0, [r4, #0x4c4]
	b _02131668
_021312C4:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r0, [r4, #0x4c4]
	sub r0, r0, #1
	str r0, [r4, #0x4c4]
	cmp r0, #0
	bgt _02131668
	mov r3, #1
	str r3, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #0x2e
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add r0, r4, #0x400
	mov r1, #0x11
	strh r1, [r0, #0xb4]
	mov r2, #0x78
	str r2, [r4, #0x4c4]
	ldr r1, _02131684 ; =OVERLAY11_BSS_02169C88
	mov r2, #0
	ldr r0, _021316A0 ; =ov11_021316C4
	str r2, [r1, #4]
	bl DWC_NdCleanupAsync
	cmp r0, #0
	ldreq r0, _02131684 ; =OVERLAY11_BSS_02169C88
	moveq r1, #1
	streq r1, [r0, #4]
	ldr r0, [r4, #0x4e0]
	mov r1, #0
	str r1, [r0, #0x710]
	b _02131668
_02131340:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r0, _02131684 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02131668
	ldr r0, [r4, #0x4c4]
	cmp r0, #0
	subgt r0, r0, #1
	strgt r0, [r4, #0x4c4]
	bl DWC_CleanupInetAsync
	cmp r0, #0
	beq _02131668
	add r0, r4, #0x400
	mov r1, #0x12
	strh r1, [r0, #0xb4]
_02131380:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r0, [r4, #0x4c4]
	cmp r0, #0
	subgt r0, r0, #1
	strgt r0, [r4, #0x4c4]
	bgt _02131668
	mov r3, #1
	str r3, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #0x2f
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add r0, r4, #0x400
	mov r1, #0x14
	strh r1, [r0, #0xb4]
	mov r0, #0x78
	str r0, [r4, #0x4c4]
	b _02131668
_021313CC:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r0, [r4, #0x4c4]
	sub r0, r0, #1
	str r0, [r4, #0x4c4]
	cmp r0, #0
	bgt _02131668
	mov r3, #1
	str r3, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #6
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add r0, r4, #0x400
	mov r1, #0x15
	strh r1, [r0, #0xb4]
	mov r0, #0
	str r0, [r4, #0x4cc]
	b _02131668
_02131418:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r1, [r4, #0x4cc]
	cmp r1, #6
	bge _02131478
	ldr r5, _021316A4 ; =MAIN_BSS_020AF620+4
_02131430:
	ldr r0, [r4, #0x4e0]
	ldr r2, [r4, #0x4c0]
	mov r3, r5
	bl _ZN17UnkClass_0211E05C13ov11_02123D20EiPvPh
	cmp r0, #0
	beq _02131464
	add r0, r4, #0x400
	mov r1, #0x16
	strh r1, [r0, #0xb4]
	ldr r0, [r4, #0x4e0]
	ldr r0, [r0, #0x620]
	bl sub_020110E8
	b _02131478
_02131464:
	ldr r0, [r4, #0x4cc]
	add r1, r0, #1
	str r1, [r4, #0x4cc]
	cmp r1, #6
	blt _02131430
_02131478:
	ldr r0, [r4, #0x4cc]
	cmp r0, #6
	blt _02131668
	add r0, r4, #0x400
	mov r1, #0xe
	strh r1, [r0, #0xb4]
	mov r0, #0
	str r0, [r4, #0x4c4]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F0BCEv
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xd1
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0xf0
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	b _02131668
_021314CC:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F06CEv
	ldr r0, [r4, #0x4e0]
	ldr r1, [r4, #0x4cc]
	ldr r0, [r0, #0x620]
	bl sub_020110F8
	cmp r0, #0
	beq _02131668
	cmp r0, #1
	bne _02131510
	ldr r1, [r4, #0x4cc]
	add r0, r4, #0x400
	add r1, r1, #1
	str r1, [r4, #0x4cc]
	mov r1, #0x15
	strh r1, [r0, #0xb4]
	b _02131668
_02131510:
	add sp, sp, #0x34
	mov r0, #7
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0213151C:
	ldr r0, [r4, #0x4c4]
	add r0, r0, #1
	str r0, [r4, #0x4c4]
	cmp r0, #0xb4
	blt _02131668
	ldr r1, [r4, #0x4bc]
	ldr r0, [r4, #0x4e0]
	add r1, r4, r1, lsl #2
	ldr r1, [r1, #0x484]
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_0212374CEii
	add r0, r4, #0x400
	mov r1, #0xf
	strh r1, [r0, #0xb4]
	b _02131668
_02131558:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02122428Ev
	cmp r0, #0
	beq _02131668
	add sp, sp, #0x34
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02131574:
	bl ov11_021316D8
	cmp r0, #0
	beq _02131668
	add sp, sp, #0x34
	mov r0, #2
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0213158C:
	mov r0, r4
	bl ov11_02131980
	cmp r0, #0
	addne sp, sp, #0x34
	movne r0, #8
	ldmneia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_02121168Ev
	mvn r1, #1
	cmp r0, r1
	beq _021315C4
	cmp r0, #0xe
	beq _021315FC
	b _02131624
_021315C4:
	ldr r0, [r4, #0x4e0]
	ldr r0, [r0, #0x70c]
	cmp r0, #0
	ldrne r0, _02131688 ; =0x00001C20
	strne r0, [r4, #0x4c8]
	bne _02131668
	ldr r0, [r4, #0x4c8]
	sub r0, r0, #1
	str r0, [r4, #0x4c8]
	cmp r0, #0
	bgt _02131668
	add sp, sp, #0x34
	mov r0, #5
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_021315FC:
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #0
	mov r2, #5
	mov r3, #3
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add sp, sp, #0x34
	mov r0, #6
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
_02131624:
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F904Ev
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211F96CEv
	add r0, r4, #0x400
	ldrh r2, [r0, #0xb6]
	mov r1, #5
	strh r2, [r0, #0xb4]
	ldr r0, [r4, #0x4e0]
	bl _ZN17UnkClass_0211E05C13ov11_0211FBE4Ei
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4, #0x4e0]
	mov r1, #0
	mov r2, #5
	mov r3, #3
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
_02131668:
	ldr r0, _02131684 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0]
	cmp r0, #1
	moveq r0, #8
	movne r0, #3
	add sp, sp, #0x34
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02131684: .word OVERLAY11_BSS_02169C88
_02131688: .word 0x00001C20
_0213168C: .word ov11_021316A8
_02131690: .word s_YP2E_overlay_11_02166644
_02131694: .word s_griUBMRWtExs4ZNS_overlay_11_0216664c
_02131698: .word s_PRS_MISSION_02d_prs_overlay_11_02166660
_0213169C: .word 0x00000708
_021316A0: .word ov11_021316C4
_021316A4: .word MAIN_BSS_020AF620+4

	arm_func_start ov11_021316A8
ov11_021316A8: ; 0x021316A8
	ldr r0, _021316C0 ; =OVERLAY11_BSS_02169C88
	mov r2, #1
	str r2, [r0, #8]
	cmp r1, #0
	strne r2, [r0]
	bx lr
	.align 2, 0
_021316C0: .word OVERLAY11_BSS_02169C88
	arm_func_end ov11_021316A8

	arm_func_start ov11_021316C4
ov11_021316C4: ; 0x021316C4
	ldr r0, _021316D4 ; =OVERLAY11_BSS_02169C88
	mov r1, #1
	str r1, [r0, #4]
	bx lr
	.align 2, 0
_021316D4: .word OVERLAY11_BSS_02169C88
	arm_func_end ov11_021316C4

	arm_func_start ov11_021316D8
ov11_021316D8: ; 0x021316D8
	ldr r0, _021316E4 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0, #8]
	bx lr
	.align 2, 0
_021316E4: .word OVERLAY11_BSS_02169C88
	arm_func_end ov11_021316D8

	arm_func_start ov11_021316E8
ov11_021316E8: ; 0x021316E8
	stmdb sp!, {r3, lr}
	ldr r0, _0213170C ; =DAT_overlay_11_02166678
	mov r1, r0
	mov r2, r0
	bl DWC_NdSetAttr
	cmp r0, #0
	ldmneia sp!, {r3, pc}
	bl OS_Terminate
	ldmia sp!, {r3, pc}
	.align 2, 0
_0213170C: .word DAT_overlay_11_02166678
	arm_func_end ov11_021316E8

	arm_func_start ov11_02131710
ov11_02131710: ; 0x02131710
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x48
	mov r5, r0
	add r0, sp, #4
	mov r4, #0x1a
	bl DWC_GetLastError
	ldr r1, [sp, #4]
	mvn r0, #0
	mul r2, r1, r0
	ldr r1, _02131950 ; =0x00004E20
	str r2, [sp, #4]
	cmp r2, r1
	blt _02131788
	ldr r0, _02131954 ; =0x00005207
	cmp r2, r0
	bgt _02131788
	add r0, r1, #0x65
	cmp r2, r0
	beq _02131778
	add r0, r1, #0x6c
	cmp r2, r0
	beq _02131780
	add r0, r1, #0x6e
	cmp r2, r0
	moveq r4, #0x1d
	b _0213190C
	arm_func_end ov11_02131710
_02131778:
	mov r4, #0x1b
	b _0213190C
_02131780:
	mov r4, #0x1c
	b _0213190C
_02131788:
	ldr r0, _02131958 ; =0x000059D8
	cmp r2, r0
	blt _021317A4
	ldr r0, _0213195C ; =0x00005DBF
	cmp r2, r0
	movle r4, #0x1b
	ble _0213190C
_021317A4:
	ldr r1, _02131960 ; =0x0000CB20
	cmp r2, r1
	blt _02131868
	ldr r0, _02131964 ; =0x0000D033
	cmp r2, r0
	bgt _02131868
	add r0, r1, #0x68
	cmp r2, r0
	bgt _02131820
	bge _02131860
	add r0, r1, #0x64
	cmp r2, r0
	bgt _021317FC
	bge _02131860
	sub r0, r2, r1
	cmp r0, #3
	addls pc, pc, r0, lsl #2
	b _0213190C
_021317EC: ; jump table
	b _02131860 ; case 0
	b _02131860 ; case 1
	b _02131860 ; case 2
	b _02131860 ; case 3
_021317FC:
	ldr r0, _02131968 ; =0x0000CB86
	cmp r2, r0
	bgt _02131810
	beq _02131860
	b _0213190C
_02131810:
	add r0, r0, #1
	cmp r2, r0
	beq _02131860
	b _0213190C
_02131820:
	add r0, r1, #0xc9
	cmp r2, r0
	bgt _02131840
	bge _02131860
	add r0, r1, #0xc8
	cmp r2, r0
	beq _02131860
	b _0213190C
_02131840:
	add r0, r1, #0xca
	cmp r2, r0
	bgt _02131854
	beq _02131860
	b _0213190C
_02131854:
	add r0, r1, #0xcb
	cmp r2, r0
	bne _0213190C
_02131860:
	mov r4, #0x27
	b _0213190C
_02131868:
	cmp r2, #0xc800
	blt _02131880
	ldr r0, _0213196C ; =0x0000C863
	cmp r2, r0
	movle r4, #0x1e
	ble _0213190C
_02131880:
	ldr r0, _02131970 ; =0x0000C350
	cmp r2, r0
	blt _0213189C
	add r0, r0, #0x63
	cmp r2, r0
	movle r4, #0x1f
	ble _0213190C
_0213189C:
	ldr r0, _02131974 ; =0x0000C738
	cmp r2, r0
	blt _021318B8
	add r0, r0, #0x63
	cmp r2, r0
	movle r4, #0x20
	ble _0213190C
_021318B8:
	ldr r1, _02131978 ; =0x0000C79C
	cmp r2, r1
	blt _021318EC
	add r0, r1, #0x63
	cmp r2, r0
	bgt _021318EC
	add r0, r1, #3
	cmp r2, r0
	bne _021318E4
	mov r4, #0x21
	b _0213190C
_021318E4:
	mov r4, #0x20
	b _0213190C
_021318EC:
	ldr r0, _0213197C ; =0x0000C864
	cmp r2, r0
	blt _02131908
	add r0, r0, #0x63
	cmp r2, r0
	movle r4, #0x20
	ble _0213190C
_02131908:
	mov r4, #0x22
_0213190C:
	ldr r0, [r5, #0x4e0]
	add r1, sp, #8
	mvn r3, #0
	bl _ZN17UnkClass_0211E05C13ov11_021234A8EPcii
	ldr r0, [r5, #0x4e0]
	add r1, sp, #8
	mov r2, #0
	bl _ZN17UnkClass_0211E05C13ov11_02122BA8EPKci
	mov r0, #1
	str r0, [sp]
	mov r2, #0
	ldr r0, [r5, #0x4e0]
	mov r1, r4
	mov r3, r2
	bl _ZN17UnkClass_0211E05C13ov11_02122B7CEiiii
	add sp, sp, #0x48
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02131950: .word 0x00004E20
_02131954: .word 0x00005207
_02131958: .word 0x000059D8
_0213195C: .word 0x00005DBF
_02131960: .word 0x0000CB20
_02131964: .word 0x0000D033
_02131968: .word 0x0000CB86
_0213196C: .word 0x0000C863
_02131970: .word 0x0000C350
_02131974: .word 0x0000C738
_02131978: .word 0x0000C79C
_0213197C: .word 0x0000C864

	arm_func_start ov11_02131980
ov11_02131980: ; 0x02131980
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	ldr r0, _021319E8 ; =OVERLAY11_BSS_02169C88
	ldr r0, [r0]
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r3, pc}
	bl DWC_UpdateConnection
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r3, pc}
	add r0, sp, #4
	add r1, sp, #0
	bl DWC_GetLastErrorEx
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r3, pc}
	ldr r0, [sp]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_021319E8: .word OVERLAY11_BSS_02169C88
	arm_func_end ov11_02131980

	arm_func_start _ZN17CCompanyLogoSceneC1Ev
_ZN17CCompanyLogoSceneC1Ev: ; 0x021319EC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN6CSceneC2Ev
	mov r2, #0
	ldr r0, _02131A38 ; =ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4
	mov r1, r2
	stmia r4, {r0, r2}
	str r2, [r4, #8]
	str r2, [r4, #0xc]
	str r2, [r4, #0x24]
	str r2, [r4, #0x1c]
	str r2, [r4, #0x20]
	arm_func_end _ZN17CCompanyLogoSceneC1Ev
_02131A1C:
	add r0, r4, r2, lsl #2
	add r2, r2, #1
	str r1, [r0, #0x10]
	cmp r2, #3
	blt _02131A1C
	mov r0, r4
	ldmia sp!, {r4, pc}
	.align 2, 0
_02131A38: .word ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4

	arm_func_start ov11_02131A3C
ov11_02131A3C: ; 0x02131A3C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r1, _02131AEC ; =ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x1c]
	cmp r5, #0
	beq _02131A74
	beq _02131A6C
	mov r0, r5
	bl _ZN17UnkClass_0212F3DCD1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov11_02131A3C
_02131A6C:
	mov r0, #0
	str r0, [r4, #0x1c]
_02131A74:
	ldr r5, [r4, #0xc]
	cmp r5, #0
	beq _02131A9C
	beq _02131A94
	mov r0, r5
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r5
	bl _ZdlPv
_02131A94:
	mov r0, #0
	str r0, [r4, #0xc]
_02131A9C:
	mov r6, #0
	mov r5, r6
_02131AA4:
	add r0, r4, r6, lsl #2
	ldr r7, [r0, #0x10]
	cmp r7, #0
	beq _02131AD0
	beq _02131AC8
	mov r0, r7
	bl _ZN17UnkClass_0201FC80D1Ev
	mov r0, r7
	bl _ZdlPv
_02131AC8:
	add r0, r4, r6, lsl #2
	str r5, [r0, #0x10]
_02131AD0:
	add r6, r6, #1
	cmp r6, #3
	blt _02131AA4
	mov r0, r4
	bl _ZN6CSceneD2Ev
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02131AEC: .word ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4

	arm_func_start ov11_02131AF0
ov11_02131AF0: ; 0x02131AF0
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r1, _02131BA8 ; =ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4
	mov r4, r0
	str r1, [r4]
	ldr r5, [r4, #0x1c]
	cmp r5, #0
	beq _02131B28
	beq _02131B20
	mov r0, r5
	bl _ZN17UnkClass_0212F3DCD1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end ov11_02131AF0
_02131B20:
	mov r0, #0
	str r0, [r4, #0x1c]
_02131B28:
	ldr r5, [r4, #0xc]
	cmp r5, #0
	beq _02131B50
	beq _02131B48
	mov r0, r5
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r5
	bl _ZdlPv
_02131B48:
	mov r0, #0
	str r0, [r4, #0xc]
_02131B50:
	mov r6, #0
	mov r5, r6
_02131B58:
	add r0, r4, r6, lsl #2
	ldr r7, [r0, #0x10]
	cmp r7, #0
	beq _02131B84
	beq _02131B7C
	mov r0, r7
	bl _ZN17UnkClass_0201FC80D1Ev
	mov r0, r7
	bl _ZdlPv
_02131B7C:
	add r0, r4, r6, lsl #2
	str r5, [r0, #0x10]
_02131B84:
	add r6, r6, #1
	cmp r6, #3
	blt _02131B58
	mov r0, r4
	bl _ZN6CSceneD2Ev
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02131BA8: .word ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4

	arm_func_start ov11_02131BAC
ov11_02131BAC: ; 0x02131BAC
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _02131BD0
	ldr r0, [r4, #0x1c]
	bl _ZN17UnkClass_0212F3DC13ov11_0212F46CEv
	str r0, [r4, #0x20]
	arm_func_end ov11_02131BAC
_02131BD0:
	ldr r0, [r4, #8]
	cmp r0, #0xe
	addls pc, pc, r0, lsl #2
	b _02132000
_02131BE0: ; jump table
	b _02131C1C ; case 0
	b _02131C30 ; case 1
	b _02131CB8 ; case 2
	b _02131CD0 ; case 3
	b _02131D58 ; case 4
	b _02131D9C ; case 5
	b _02131DE8 ; case 6
	b _02131E10 ; case 7
	b _02131E84 ; case 8
	b _02131EE4 ; case 9
	b _02131F38 ; case 10
	b _02132000 ; case 11
	b _02131F8C ; case 12
	b _02131FA4 ; case 13
	b _02132000 ; case 14
_02131C1C:
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl _ZN17UnkClass_02027FE812sub_02028408Et
	mov r0, #1
	str r0, [r4, #8]
_02131C30:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02132000
	tst r0, #0x80
	bne _02131C5C
	mov r0, #2
	str r0, [r4, #0x24]
	mov r0, #4
	str r0, [r4, #8]
	b _02132000
_02131C5C:
	and r0, r0, #0x7f
	cmp r0, #8
	addls pc, pc, r0, lsl #2
	b _02131CA4
_02131C6C: ; jump table
	b _02131CA4 ; case 0
	b _02131C90 ; case 1
	b _02131C90 ; case 2
	b _02131CA4 ; case 3
	b _02131C90 ; case 4
	b _02131CA4 ; case 5
	b _02131C90 ; case 6
	b _02131CA4 ; case 7
	b _02131C90 ; case 8
_02131C90:
	mov r0, #3
	str r0, [r4, #0x24]
	mov r0, #4
	str r0, [r4, #8]
	b _02132000
_02131CA4:
	mov r0, #1
	str r0, [r4, #0x24]
	mov r0, #2
	str r0, [r4, #8]
	b _02132000
_02131CB8:
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl _ZN17UnkClass_02027FE812sub_02028408Et
	mov r0, #3
	str r0, [r4, #8]
	b _02132000
_02131CD0:
	ldr r0, [r4, #0xc]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02132000
	tst r0, #0x80
	bne _02131CFC
	mov r0, #2
	str r0, [r4, #0x24]
	mov r0, #4
	str r0, [r4, #8]
	b _02132000
_02131CFC:
	and r0, r0, #0x7f
	cmp r0, #8
	addls pc, pc, r0, lsl #2
	b _02131D44
_02131D0C: ; jump table
	b _02131D44 ; case 0
	b _02131D30 ; case 1
	b _02131D30 ; case 2
	b _02131D44 ; case 3
	b _02131D30 ; case 4
	b _02131D44 ; case 5
	b _02131D30 ; case 6
	b _02131D44 ; case 7
	b _02131D30 ; case 8
_02131D30:
	mov r0, #3
	str r0, [r4, #0x24]
	mov r0, #4
	str r0, [r4, #8]
	b _02132000
_02131D44:
	mov r0, #1
	str r0, [r4, #0x24]
	mov r0, #4
	str r0, [r4, #8]
	b _02132000
_02131D58:
	ldr r0, _0213200C ; =s_game
	mov r1, #1
	ldr r0, [r0]
	mov r2, #0xa
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, _0213200C ; =s_game
	mov r1, #1
	ldr r0, [r0]
	mov r2, #0xa
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #5
	str r0, [r4, #8]
	b _02132000
_02131D9C:
	ldr r0, _0213200C ; =s_game
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02132000
	ldr r0, _0213200C ; =s_game
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02132000
	mov r0, #6
	str r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #4]
	b _02132000
_02131DE8:
	ldr r0, [r4, #4]
	add r0, r0, #1
	str r0, [r4, #4]
	cmp r0, #0x3c
	ble _02132000
	mov r0, #7
	str r0, [r4, #8]
	mov r0, #0
	str r0, [r4, #4]
	b _02132000
_02131E10:
	ldr r0, [r4, #4]
	add r0, r0, #1
	str r0, [r4, #4]
	cmp r0, #0xa
	ble _02131E58
	mov r0, #0
	str r0, [r4, #4]
	mov r0, #8
	str r0, [r4, #8]
	ldr r0, [r4, #0x18]
	bl _ZN17UnkClass_0201FC8014LoadCharToVramEv
	ldr r0, [r4, #0x18]
	mov r1, #0
	bl _ZN17UnkClass_0201FC8014LoadPlttToVramEi
	ldr r0, [r4, #0x18]
	bl _ZN17UnkClass_0201FC8013LoadScrToVramEv
	ldr r2, _02132010 ; =0x001F001F
	b _02131E70
_02131E58:
	ldr r1, _02132014 ; =0x66666667
	rsb r3, r0, r0, lsl #5
	smull r0, r2, r1, r3
	mov r0, r3, lsr #0x1f
	add r2, r0, r2, asr #2
	orr r2, r2, r2, lsl #16
_02131E70:
	ldr r0, _0213200C ; =s_game
	ldr r1, _02132018 ; =ov11_0213251C
	ldr r0, [r0]
	bl _ZN5CGame12sub_020100E4EPFvPvES0_
	b _02132000
_02131E84:
	ldr r0, [r4, #4]
	add r0, r0, #1
	str r0, [r4, #4]
	cmp r0, #0xa
	ble _02131EB0
	mov r0, #0
	str r0, [r4, #4]
	mov r0, #9
	str r0, [r4, #8]
	mov r2, #0x1f
	b _02131ED0
_02131EB0:
	rsb r0, r0, #0xa
	rsb r1, r0, r0, lsl #5
	ldr r2, _02132014 ; =0x66666667
	mov r0, r1, lsr #0x1f
	smull r1, r3, r2, r1
	add r3, r0, r3, asr #2
	mov r0, r3, lsl #0x10
	orr r2, r0, #0x1f
_02131ED0:
	ldr r0, _0213200C ; =s_game
	ldr r1, _02132018 ; =ov11_0213251C
	ldr r0, [r0]
	bl _ZN5CGame12sub_020100E4EPFvPvES0_
	b _02132000
_02131EE4:
	ldr r0, [r4, #4]
	add r0, r0, #1
	str r0, [r4, #4]
	cmp r0, #0x3c
	ble _02132000
	mov r2, #0xa
	ldr r0, _0213200C ; =s_game
	str r2, [r4, #8]
	ldr r0, [r0]
	mov r1, #4
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, _0213200C ; =s_game
	mov r1, #4
	ldr r0, [r0]
	mov r2, #0xa
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	b _02132000
_02131F38:
	ldr r0, _0213200C ; =s_game
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02132000
	ldr r0, _0213200C ; =s_game
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02132000
	ldr r0, [r4, #0x24]
	cmp r0, #3
	moveq r0, #0xd
	streq r0, [r4, #8]
	movne r0, #0xc
	strne r0, [r4, #8]
	b _02132000
_02131F8C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bne _02132000
	add sp, sp, #8
	mov r0, #0x12
	ldmia sp!, {r4, pc}
_02131FA4:
	ldr r0, _0213200C ; =s_game
	mov r1, #3
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r1, #0x4000000
	ldr r0, [r1]
	mov r3, #1
	bic r0, r0, #0x1f00
	str r0, [r1]
	str r3, [sp]
	mov r1, #0
	ldr r0, _0213200C ; =s_game
	str r1, [sp, #4]
	ldr r0, [r0]
	mov r2, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0xe
	str r0, [r4, #8]
_02132000:
	mvn r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213200C: .word s_game
_02132010: .word 0x001F001F
_02132014: .word 0x66666667
_02132018: .word ov11_0213251C

	arm_func_start ov11_0213201C
ov11_0213201C: ; 0x0213201C
	bx lr
	arm_func_end ov11_0213201C

	arm_func_start ov11_02132020
ov11_02132020: ; 0x02132020
	bx lr
	arm_func_end ov11_02132020

	arm_func_start ov11_02132024
ov11_02132024: ; 0x02132024
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
	mov r0, #3
	bl GX_SetBankForBG
	mov r0, #0
	bl GX_SetBankForOBJ
	mov r0, #0
	bl GX_SetBankForTex
	mov r0, #0
	bl GX_SetBankForTexPltt
	mov r0, #1
	mov r1, #0
	mov r2, r1
	bl GX_SetGraphicsMode
	mov r0, #4
	bl GX_SetBankForSubBG
	bl GX_DisableBankForSubBG
	mov r0, #0x180
	bl GX_SetBankForSubBG
	mov r0, #0
	bl GX_SetBankForSubOBJ
	mov r1, #0
	str r1, [sp]
	ldr r0, _02132170 ; =0x04000050
	mov r2, r1
	mov r3, r1
	bl G2x_SetBlendAlpha_
	ldr lr, _02132174 ; =0x04000060
	ldr r0, _02132178 ; =0xFFFFFDF1
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
	orr r0, r0, #0x100
	str r0, [r2]
	ldr r0, [r1]
	bic r0, r0, #0x1f00
	orr r0, r0, #0x100
	str r0, [r1]
	bl GX_DispOn
	ldr r2, _0213217C ; =0x04001000
	ldr r1, _02132180 ; =0x04000008
	ldr r0, [r2]
	orr r0, r0, #0x10000
	str r0, [r2]
	ldrh r0, [r2, #8]
	and r0, r0, #0x43
	orr r0, r0, #8
	strh r0, [r2, #8]
	ldrh r0, [r1]
	and r0, r0, #0x43
	orr r0, r0, #0x10
	orr r0, r0, #0x1000
	strh r0, [r1]
	ldmia sp!, {r3, pc}
	.align 2, 0
_02132170: .word 0x04000050
_02132174: .word 0x04000060
_02132178: .word 0xFFFFFDF1
_0213217C: .word 0x04001000
_02132180: .word 0x04000008
	arm_func_end ov11_02132024

	arm_func_start ov11_02132184
ov11_02132184: ; 0x02132184
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x18
	ldr r1, _0213245C ; =s_game
	mov r4, r0
	ldr r0, [r1]
	mov r1, #0x3c
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	mov r1, #0
	str r1, [r4, #8]
	str r1, [r4, #4]
	mov r0, #0x74
	str r1, [r4, #0x24]
	bl _Znwm
	cmp r0, #0
	beq _021321D0
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
	arm_func_end ov11_02132184
_021321D0:
	ldr r1, _0213245C ; =s_game
	str r0, [r4, #0xc]
	ldr ip, [r1]
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
	mov r1, #0
	str r1, [sp, #0x14]
	ldr r3, [r0, #0x4ac]
	ldr r0, [r0, #0x490]
	ldr r1, [ip, #0x14]
	ldr r2, [ip, #0x18]
	add r3, r3, #0xc
	bl _ZN17UnkClass_020091E812sub_02009328EP17UnkClass_02001C04P11CTouchPanelP10NNSG2dFontPvP10CGame_0024S6_mmm
	ldr r0, _0213245C ; =s_game
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	mov r0, #0x64
	bl _Znwm
	cmp r0, #0
	beq _0213225C
	ldr r1, _0213245C ; =s_game
	ldr r1, [r1]
	bl _ZN17UnkClass_0201FC80C1Ei
_0213225C:
	str r0, [r4, #0x10]
	mov r0, #0x64
	bl _Znwm
	cmp r0, #0
	beq _0213227C
	ldr r1, _0213245C ; =s_game
	ldr r1, [r1]
	bl _ZN17UnkClass_0201FC80C1Ei
_0213227C:
	str r0, [r4, #0x14]
	mov r0, #0x64
	bl _Znwm
	cmp r0, #0
	beq _0213229C
	ldr r1, _0213245C ; =s_game
	ldr r1, [r1]
	bl _ZN17UnkClass_0201FC80C1Ei
_0213229C:
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x10]
	mov r1, #4
	bl _ZN17UnkClass_0201FC805SetBGEi
	ldr r0, [r4, #0x14]
	mov r1, #0
	bl _ZN17UnkClass_0201FC805SetBGEi
	ldr r0, [r4, #0x18]
	mov r1, #4
	bl _ZN17UnkClass_0201FC805SetBGEi
	ldr r0, [r4, #0x10]
	ldr r1, _02132460 ; =s_title_overlay_11_021666d0
	ldr r2, _02132464 ; =s_copyright000_overlay_11_021666d8
	bl _ZN17UnkClass_0201FC8011LoadArchiveEPKcS1_
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x10]
	ldr r1, _02132468 ; =s_copyright000_overlay_11_021666e8
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadCharEPKcimm
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x10]
	ldr r1, _02132468 ; =s_copyright000_overlay_11_021666e8
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadPlttEPKcimm
	mov r2, #0
	strh r2, [r0]
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #0x10]
	ldr r1, _02132468 ; =s_copyright000_overlay_11_021666e8
	mov r3, r2
	bl _ZN17UnkClass_0201FC807LoadScrEPKcimmmm
	ldr r0, [r4, #0x10]
	bl _ZN17UnkClass_0201FC8014ReleaseArchiveEv
	ldr r0, [r4, #0x14]
	ldr r1, _02132460 ; =s_title_overlay_11_021666d0
	ldr r2, _0213246C ; =s_copyright001_overlay_11_021666f8
	bl _ZN17UnkClass_0201FC8011LoadArchiveEPKcS1_
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x14]
	ldr r1, _02132470 ; =s_copyright001_overlay_11_02166708
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadCharEPKcimm
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x14]
	ldr r1, _02132470 ; =s_copyright001_overlay_11_02166708
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadPlttEPKcimm
	mov r2, #0
	strh r2, [r0]
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #0x14]
	ldr r1, _02132470 ; =s_copyright001_overlay_11_02166708
	mov r3, r2
	bl _ZN17UnkClass_0201FC807LoadScrEPKcimmmm
	ldr r0, [r4, #0x14]
	bl _ZN17UnkClass_0201FC8014ReleaseArchiveEv
	ldr r0, [r4, #0x18]
	ldr r1, _02132460 ; =s_title_overlay_11_021666d0
	ldr r2, _02132474 ; =s_copyright002_overlay_11_02166718
	bl _ZN17UnkClass_0201FC8011LoadArchiveEPKcS1_
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x18]
	ldr r1, _02132478 ; =s_copyright002_overlay_11_02166728
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadCharEPKcimm
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x18]
	ldr r1, _02132478 ; =s_copyright002_overlay_11_02166728
	mov r3, r2
	bl _ZN17UnkClass_0201FC808LoadPlttEPKcimm
	mov r2, #0
	strh r2, [r0]
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	ldr r0, [r4, #0x18]
	ldr r1, _02132478 ; =s_copyright002_overlay_11_02166728
	mov r3, r2
	bl _ZN17UnkClass_0201FC807LoadScrEPKcimmmm
	ldr r0, [r4, #0x18]
	bl _ZN17UnkClass_0201FC8014ReleaseArchiveEv
	ldr r0, [r4, #0x10]
	bl _ZN17UnkClass_0201FC8014LoadCharToVramEv
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl _ZN17UnkClass_0201FC8014LoadPlttToVramEi
	ldr r0, [r4, #0x10]
	bl _ZN17UnkClass_0201FC8013LoadScrToVramEv
	ldr r0, [r4, #0x14]
	bl _ZN17UnkClass_0201FC8014LoadCharToVramEv
	ldr r0, [r4, #0x14]
	mov r1, #0
	bl _ZN17UnkClass_0201FC8014LoadPlttToVramEi
	ldr r0, [r4, #0x14]
	bl _ZN17UnkClass_0201FC8013LoadScrToVramEv
	ldr r0, _0213245C ; =s_game
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_020345D4Ev
	add sp, sp, #0x18
	ldmia sp!, {r4, pc}
	.align 2, 0
_0213245C: .word s_game
_02132460: .word s_title_overlay_11_021666d0
_02132464: .word s_copyright000_overlay_11_021666d8
_02132468: .word s_copyright000_overlay_11_021666e8
_0213246C: .word s_copyright001_overlay_11_021666f8
_02132470: .word s_copyright001_overlay_11_02166708
_02132474: .word s_copyright002_overlay_11_02166718
_02132478: .word s_copyright002_overlay_11_02166728

	arm_func_start ov11_0213247C
ov11_0213247C: ; 0x0213247C
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r4, [r5, #0xc]
	cmp r4, #0
	beq _021324AC
	beq _021324A4
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end ov11_0213247C
_021324A4:
	mov r0, #0
	str r0, [r5, #0xc]
_021324AC:
	ldr r0, _02132510 ; =s_game
	mov r1, #0x1e
	ldr r0, [r0]
	add r0, r0, #0x6c
	add r0, r0, #0x1400
	bl _ZN17UnkClass_02008D5012sub_02008DB4Et
	ldr r0, _02132510 ; =s_game
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AC90Ev
	ldr r0, _02132514 ; =0x04000050
	mov r1, #1
	mov r2, #0
	bl G2x_SetBlendBrightness_
	ldr r0, _02132518 ; =0x04001050
	mov r1, #1
	mov r2, #0
	bl G2x_SetBlendBrightness_
	ldr r0, _02132510 ; =s_game
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020092D4Ev
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02132510: .word s_game
_02132514: .word 0x04000050
_02132518: .word 0x04001050

	arm_func_start ov11_0213251C
ov11_0213251C: ; 0x0213251C
	stmdb sp!, {r4, lr}
	mov r4, r0
	mov r1, r4, lsl #0x10
	ldr r0, _02132554 ; =0x04000050
	mov r2, r1, lsr #0x10
	mov r1, #1
	bl G2x_SetBlendBrightness_
	mov r0, r4, asr #0x10
	mov r1, r0, lsl #0x10
	ldr r0, _02132558 ; =0x04001050
	mov r2, r1, lsr #0x10
	mov r1, #1
	bl G2x_SetBlendBrightness_
	ldmia sp!, {r4, pc}
	.align 2, 0
_02132554: .word 0x04000050
_02132558: .word 0x04001050
	arm_func_end ov11_0213251C

	arm_func_start ov11_0213255C
ov11_0213255C: ; 0x0213255C
	mov r0, #0x11
	bx lr
	arm_func_end ov11_0213255C

    .rodata

    .global DAT_overlay_11_021629b4
DAT_overlay_11_021629b4: ; 0x021629B4
	.byte 0x00, 0x00, 0x00, 0x00

    .global PTR_LAB_overlay_11_0212ccf0_overlay_11_021629b8
PTR_LAB_overlay_11_0212ccf0_overlay_11_021629b8: ; 0x021629B8
	.word ov11_0212CCF0

    .global DAT_overlay_11_021629bc
DAT_overlay_11_021629bc: ; 0x021629BC
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov11_0212CCF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212c1ec_overlay_11_021629cc
ptr_FUN_overlay_11_0212c1ec_overlay_11_021629cc: ; 0x021629CC
	.word ov11_0212C1EC
	.word ov11_0212CCF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_021288bc_overlay_11_021629d8
ptr_FUN_overlay_11_021288bc_overlay_11_021629d8: ; 0x021629D8
	.word ov11_021288BC
	.word ov11_021287EC
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_02128810_overlay_11_021629e4
ptr_FUN_overlay_11_02128810_overlay_11_021629e4: ; 0x021629E4
	.word ov11_02128810
	.word ov11_021287EC
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov11_021287F4
	.word ov11_0212CCF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_02128cc8_overlay_11_021629fc
ptr_FUN_overlay_11_02128cc8_overlay_11_021629fc: ; 0x021629FC
	.word ov11_02128CC8

    .global ptr_FUN_overlay_3_02128e30_overlay_11_02162a00
ptr_FUN_overlay_3_02128e30_overlay_11_02162a00: ; 0x02162A00
	.word ov11_02128E30
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_02128d64_overlay_11_02162a08
ptr_FUN_overlay_11_02128d64_overlay_11_02162a08: ; 0x02162A08
	.word ov11_02128D64

    .global ptr_FUN_overlay_3_02128e30_overlay_11_02162a0c
ptr_FUN_overlay_3_02128e30_overlay_11_02162a0c: ; 0x02162A0C
	.word ov11_02128E30
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212c09c_overlay_11_02162a2c
ptr_FUN_overlay_11_0212c09c_overlay_11_02162a2c: ; 0x02162A2C
	.word ov11_0212C09C
	.word ov11_0212CCF8
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212c0d4_overlay_11_02162a38
ptr_FUN_overlay_11_0212c0d4_overlay_11_02162a38: ; 0x02162A38
	.word ov11_0212C0D4
	.word ov11_0212CCF8
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212c10c_overlay_11_02162a44
ptr_FUN_overlay_11_0212c10c_overlay_11_02162a44: ; 0x02162A44
	.word ov11_0212C10C
	.word ov11_0212CCF8
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212cd08_overlay_11_02162a50
ptr_FUN_overlay_11_0212cd08_overlay_11_02162a50: ; 0x02162A50
	.word ov11_0212CD08
	.word ov11_0212CCF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212cd80_overlay_11_02162a5c
ptr_FUN_overlay_11_0212cd80_overlay_11_02162a5c: ; 0x02162A5C
	.word ov11_0212CD80
	.word ov11_0212CCF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_0212cdc4_overlay_11_02162a68
ptr_FUN_overlay_11_0212cdc4_overlay_11_02162a68: ; 0x02162A68
	.word ov11_0212CDC4
	.word ov11_0212CCF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_02129970_overlay_11_02162a74
ptr_FUN_overlay_11_02129970_overlay_11_02162a74: ; 0x02162A74
	.word ov11_02129970
	.word ov11_0212CCF8
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov11_02129A3C
	.word ov11_0212CCF8
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov11_02129A1C
	.word ov11_0212CD00
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov11_02129AEC
	.word ov11_02129B14
	.byte 0x00, 0x00, 0x00, 0x00

    .global ptr_FUN_overlay_11_02129b1c_overlay_11_02162aa4
ptr_FUN_overlay_11_02129b1c_overlay_11_02162aa4: ; 0x02162AA4
	.word ov11_02129B1C
	.word ov11_02129B58
	.byte 0x00, 0x00, 0x00, 0x00

    .global PTR_LAB_overlay_11_02128634_overlay_11_02162ab0
PTR_LAB_overlay_11_02128634_overlay_11_02162ab0: ; 0x02162AB0
	.word ov11_02128634
	.word ov11_02128654
	.word ov11_0212865C
	.word ov11_02128670
	.word ov11_0212CCF0
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_11_02162ac8
DAT_overlay_11_02162ac8: ; 0x02162AC8
	.byte 0x01

    .global DAT_overlay_11_02162ac9
DAT_overlay_11_02162ac9: ; 0x02162AC9
	.byte 0x01

    .global DAT_overlay_11_02162aca
DAT_overlay_11_02162aca: ; 0x02162ACA
	.byte 0x01

    .global DAT_overlay_11_02162acb
DAT_overlay_11_02162acb: ; 0x02162ACB
	.byte 0x01, 0x03, 0x03, 0x03, 0x04
	.byte 0x03, 0x04, 0x07, 0x03, 0x07, 0x04, 0x01, 0x01, 0x01, 0x01, 0x04, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00

    .global DAT_overlay_11_02162afc
DAT_overlay_11_02162afc: ; 0x02162AFC
	.byte 0xF9

    .global DAT_overlay_11_02162afd
DAT_overlay_11_02162afd: ; 0x02162AFD
	.byte 0x7D

    .global DAT_overlay_11_02162afe
DAT_overlay_11_02162afe: ; 0x02162AFE
	.byte 0x80

    .global DAT_overlay_11_02162aff
DAT_overlay_11_02162aff: ; 0x02162AFF
	.byte 0xC3
	.byte 0x79, 0x4B, 0x2E, 0xA0, 0x95, 0x18, 0x73, 0x85, 0x99, 0x6A, 0x1C, 0x32

    .global DAT_overlay_11_02162b0c
DAT_overlay_11_02162b0c: ; 0x02162B0C
	.byte 0x16, 0x01, 0x15, 0x00

    .global DAT_overlay_11_02162b10
DAT_overlay_11_02162b10: ; 0x02162B10
	.byte 0x00, 0x00, 0x00, 0x00

    .global DAT_overlay_11_02162b14
DAT_overlay_11_02162b14: ; 0x02162B14
	.byte 0x00, 0x00, 0x00, 0x00

    .section .sinit,4 ; 0x021660AC

    .data

    .global s_DP_overlay_11_02166460
s_DP_overlay_11_02166460: ; 0x02166460
	.asciz "DP"

    .global DAT_overlay_11_02166463
DAT_overlay_11_02166463:
	.byte 0x00

    .global DAT_overlay_11_02166464
DAT_overlay_11_02166464: ; 0x02166464
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

    .global s_FREAK_overlay_11_02166484
s_FREAK_overlay_11_02166484: ; 0x02166484
	.asciz "FREAK"

    .global DAT_overlay_11_0216648A
DAT_overlay_11_0216648A:
	.byte 0x00, 0x00

    .global s_GAME_overlay_11_0216648c
s_GAME_overlay_11_0216648c: ; 0x0216648C
	.asciz " GAME"

    .global DAT_overlay_11_02166492
DAT_overlay_11_02166492:
	.byte 0x00, 0x00

    .global s_FULL_overlay_11_02166494
s_FULL_overlay_11_02166494: ; 0x02166494
	.asciz " FULL"

    .global DAT_overlay_11_0216649A
DAT_overlay_11_0216649A:
	.byte 0x00, 0x00

    .global DAT_overlay_11_0216649c
DAT_overlay_11_0216649c: ; 0x0216649C
	.byte 0x04

    .global DAT_overlay_11_0216649d
DAT_overlay_11_0216649d: ; 0x0216649D
	.byte 0x04, 0x00, 0x00

    .global ptr_null_overlay_11_021664a0
ptr_null_overlay_11_021664a0: ; 0x021664A0
	.word s_data_sendbin_sendbin1_bin_overlay_11_021664a8
	.word s_data_sendbin_sendbin2_bin_overlay_11_021664c4

    .global s_data_sendbin_sendbin1_bin_overlay_11_021664a8
s_data_sendbin_sendbin1_bin_overlay_11_021664a8: ; 0x021664A8
	.asciz "data/sendbin/sendbin1.bin"

    .global DAT_overlay_11_021664C2
DAT_overlay_11_021664C2:
	.byte 0x00, 0x00

    .global s_data_sendbin_sendbin2_bin_overlay_11_021664c4
s_data_sendbin_sendbin2_bin_overlay_11_021664c4: ; 0x021664C4
	.asciz "data/sendbin/sendbin2.bin"

    .global DAT_overlay_11_021664DE
DAT_overlay_11_021664DE:
	.byte 0x00, 0x00

    .global DAT_overlay_11_021664e0
DAT_overlay_11_021664e0: ; 0x021664E0
	.byte 0x82, 0xA0

    .global DAT_overlay_11_021664e2
DAT_overlay_11_021664e2: ; 0x021664E2
	.byte 0x82, 0xA2

    .global DAT_overlay_11_021664e4
DAT_overlay_11_021664e4: ; 0x021664E4
	.byte 0x82, 0xA4, 0x82, 0xA6, 0x82, 0xA8, 0x00, 0x00

    .global DAT_overlay_11_021664ec
DAT_overlay_11_021664ec: ; 0x021664EC
	.byte 0x82, 0xA9, 0x82, 0xAB
	.byte 0x82, 0xAD, 0x82, 0xAF, 0x82, 0xB1, 0x00, 0x00

    .global s_mywh_SYSSTATE_IDLE_overlay_11_021664f8
s_mywh_SYSSTATE_IDLE_overlay_11_021664f8: ; 0x021664F8
	.asciz "mywh_SYSSTATE_IDLE"

    .global DAT_overlay_11_0216650B
DAT_overlay_11_0216650B:
	.byte 0x00

    .global s_mywh_SYSSTATE_STOP_overlay_11_0216650c
s_mywh_SYSSTATE_STOP_overlay_11_0216650c: ; 0x0216650C
	.asciz "mywh_SYSSTATE_STOP"

    .global DAT_overlay_11_0216651F
DAT_overlay_11_0216651F:
	.byte 0x00

    .global s_mywh_SYSSTATE_BUSY_overlay_11_02166520
s_mywh_SYSSTATE_BUSY_overlay_11_02166520: ; 0x02166520
	.asciz "mywh_SYSSTATE_BUSY"

    .global DAT_overlay_11_02166533
DAT_overlay_11_02166533:
	.byte 0x00

    .global s_mywh_SYSSTATE_ERROR_overlay_11_02166534
s_mywh_SYSSTATE_ERROR_overlay_11_02166534: ; 0x02166534
	.asciz "mywh_SYSSTATE_ERROR"

    .global s_mywh_SYSSTATE_SCANNING_overlay_11_02166548
s_mywh_SYSSTATE_SCANNING_overlay_11_02166548: ; 0x02166548
	.asciz "mywh_SYSSTATE_SCANNING"

    .global DAT_overlay_11_0216655F
DAT_overlay_11_0216655F:
	.byte 0x00

    .global s_mywh_SYSSTATE_CONNECTED_overlay_11_02166560
s_mywh_SYSSTATE_CONNECTED_overlay_11_02166560: ; 0x02166560
	.asciz "mywh_SYSSTATE_CONNECTED"

    .global s_mywh_SYSSTATE_KEYSHARING_overlay_11_02166578
s_mywh_SYSSTATE_KEYSHARING_overlay_11_02166578: ; 0x02166578
	.asciz "mywh_SYSSTATE_KEYSHARING"

    .global DAT_overlay_11_02166591
DAT_overlay_11_02166591:
	.byte 0x00, 0x00, 0x00

    .global s_mywh_SYSSTATE_DATASHARING_overlay_11_02166594
s_mywh_SYSSTATE_DATASHARING_overlay_11_02166594: ; 0x02166594
	.asciz "mywh_SYSSTATE_DATASHARING"

    .global DAT_overlay_11_021665AE
DAT_overlay_11_021665AE:
	.byte 0x00, 0x00

    .global s_mywh_SYSSTATE_CONNECT_FAIL_overlay_11_021665b0
s_mywh_SYSSTATE_CONNECT_FAIL_overlay_11_021665b0: ; 0x021665B0
	.asciz "mywh_SYSSTATE_CONNECT_FAIL"

    .global DAT_overlay_11_021665CB
DAT_overlay_11_021665CB:
	.byte 0x00

    .global s_mywh_SYSSTATE_MEASURECHANNEL_overlay_11_021665cc
s_mywh_SYSSTATE_MEASURECHANNEL_overlay_11_021665cc: ; 0x021665CC
	.asciz "mywh_SYSSTATE_MEASURECHANNEL"

    .global DAT_overlay_11_021665E9
DAT_overlay_11_021665E9:
	.byte 0x00, 0x00, 0x00

    .global ptr_s_mywh_SYSSTATE_STOP_overlay_11_0216650c_overlay_11_021665ec
ptr_s_mywh_SYSSTATE_STOP_overlay_11_0216650c_overlay_11_021665ec: ; 0x021665EC
	.word s_mywh_SYSSTATE_STOP_overlay_11_0216650c
	.word s_mywh_SYSSTATE_IDLE_overlay_11_021664f8
	.word s_mywh_SYSSTATE_SCANNING_overlay_11_02166548
	.word s_mywh_SYSSTATE_BUSY_overlay_11_02166520
	.word s_mywh_SYSSTATE_CONNECTED_overlay_11_02166560
	.word s_mywh_SYSSTATE_DATASHARING_overlay_11_02166594
	.word s_mywh_SYSSTATE_KEYSHARING_overlay_11_02166578
	.word s_mywh_SYSSTATE_MEASURECHANNEL_overlay_11_021665cc
	.word s_mywh_SYSSTATE_CONNECT_FAIL_overlay_11_021665b0
	.word s_mywh_SYSSTATE_ERROR_overlay_11_02166534

    .global s_s_overlay_11_02166614
s_s_overlay_11_02166614: ; 0x02166614
	.asciz "%s -> "

    .global DAT_overlay_11_0216661B
DAT_overlay_11_0216661B:
	.byte 0x00

    .global s_s_overlay_11_0216661c
s_s_overlay_11_0216661c: ; 0x0216661C
	.asciz "%s\n"

    .global s_not_my_parent_ggid_d_d_overlay_11_02166620
s_not_my_parent_ggid_d_d_overlay_11_02166620: ; 0x02166620
	.asciz "not my parent ggid (%d != %d)\n"

    .global DAT_overlay_11_0216663F
DAT_overlay_11_0216663F:
	.byte 0x00

    .global DAT_overlay_11_02166640
DAT_overlay_11_02166640: ; 0x02166640
	.byte 0x03, 0x00, 0x00, 0x00

    .global s_YP2E_overlay_11_02166644
s_YP2E_overlay_11_02166644: ; 0x02166644
	.asciz "YP2E"

    .global DAT_overlay_11_02166649
DAT_overlay_11_02166649:
	.byte 0x00, 0x00, 0x00

    .global s_griUBMRWtExs4ZNS_overlay_11_0216664c
s_griUBMRWtExs4ZNS_overlay_11_0216664c: ; 0x0216664C
	.asciz "griUBMRWtExs4ZNS"

    .global DAT_overlay_11_0216665D
DAT_overlay_11_0216665D:
	.byte 0x00, 0x00, 0x00

    .global s_PRS_MISSION_02d_prs_overlay_11_02166660
s_PRS_MISSION_02d_prs_overlay_11_02166660: ; 0x02166660
	.asciz "PRS_MISSION_%02d.prs"

    .global DAT_overlay_11_02166675
DAT_overlay_11_02166675:
	.byte 0x00, 0x00, 0x00

    .global DAT_overlay_11_02166678
DAT_overlay_11_02166678: ; 0x02166678
	.byte 0x00, 0x00, 0x00, 0x00

    .global PTR_ptr_FUN_020835bc_overlay_11_0216667c
PTR_ptr_FUN_020835bc_overlay_11_0216667c: ; 0x0216667C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CCompanyLogoScene_overlay_11_02166688
	.word _ZTI6CScene

    .global s_17CCompanyLogoScene_overlay_11_02166688
s_17CCompanyLogoScene_overlay_11_02166688: ; 0x02166688
	.asciz "17CCompanyLogoScene"

    .global DAT_overlay_11_0216669C
DAT_overlay_11_0216669C:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_11_0216667c

    .global ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4
ptr_FUN_overlay_11_02131a3c_overlay_11_021666a4: ; 0x021666A4
	.word ov11_02131A3C

    .global ptr_FUN_overlay_11_02131af0_overlay_11_021666a8
ptr_FUN_overlay_11_02131af0_overlay_11_021666a8: ; 0x021666A8
	.word ov11_02131AF0

    .global ptr_FUN_overlay_11_02131bac_overlay_11_021666ac
ptr_FUN_overlay_11_02131bac_overlay_11_021666ac: ; 0x021666AC
	.word ov11_02131BAC
	.word ov11_0213201C
	.word ov11_02132020

    .global ptr_FUN_02007ce0_overlay_11_021666b8
ptr_FUN_02007ce0_overlay_11_021666b8: ; 0x021666B8
	.word _ZN6CScene5func3Ev

    .global ptr_FUN_02007cc4_overlay_11_021666bc
ptr_FUN_02007cc4_overlay_11_021666bc: ; 0x021666BC
	.word _ZN6CScene5func4Ev

    .global ptr_FUN_overlay_11_02132024_overlay_11_021666c0
ptr_FUN_overlay_11_02132024_overlay_11_021666c0: ; 0x021666C0
	.word ov11_02132024

    .global ptr_FUN_overlay_11_02132184_overlay_11_021666c4
ptr_FUN_overlay_11_02132184_overlay_11_021666c4: ; 0x021666C4
	.word ov11_02132184

    .global ptr_FUN_overlay_11_0213247c_overlay_11_021666c8
ptr_FUN_overlay_11_0213247c_overlay_11_021666c8: ; 0x021666C8
	.word ov11_0213247C
	.word ov11_0213255C

    .global s_title_overlay_11_021666d0
s_title_overlay_11_021666d0: ; 0x021666D0
	.asciz "title/"

    .global DAT_overlay_11_021666D7
DAT_overlay_11_021666D7:
	.byte 0x00

    .global s_copyright000_overlay_11_021666d8
s_copyright000_overlay_11_021666d8: ; 0x021666D8
	.asciz "copyright000_"

    .global DAT_overlay_11_021666E6
DAT_overlay_11_021666E6:
	.byte 0x00, 0x00

    .global s_copyright000_overlay_11_021666e8
s_copyright000_overlay_11_021666e8: ; 0x021666E8
	.asciz "copyright000"

    .global DAT_overlay_11_021666F5
DAT_overlay_11_021666F5:
	.byte 0x00, 0x00, 0x00

    .global s_copyright001_overlay_11_021666f8
s_copyright001_overlay_11_021666f8: ; 0x021666F8
	.asciz "copyright001_"

    .global DAT_overlay_11_02166706
DAT_overlay_11_02166706:
	.byte 0x00, 0x00

    .global s_copyright001_overlay_11_02166708
s_copyright001_overlay_11_02166708: ; 0x02166708
	.asciz "copyright001"

    .global DAT_overlay_11_02166715
DAT_overlay_11_02166715:
	.byte 0x00, 0x00, 0x00

    .global s_copyright002_overlay_11_02166718
s_copyright002_overlay_11_02166718: ; 0x02166718
	.asciz "copyright002_"

    .global DAT_overlay_11_02166726
DAT_overlay_11_02166726:
	.byte 0x00, 0x00

    .global s_copyright002_overlay_11_02166728
s_copyright002_overlay_11_02166728: ; 0x02166728
	.asciz "copyright002"

    .bss

    .global OVERLAY11_BSS_02169C44
OVERLAY11_BSS_02169C44: ; 0x02169C44
    .space 0x8

    .global OVERLAY11_BSS_02169C4C
OVERLAY11_BSS_02169C4C: ; 0x02169C4C
    .space 0x4

    .global OVERLAY11_BSS_02169C50
OVERLAY11_BSS_02169C50: ; 0x02169C50
    .space 0x4

    .global OVERLAY11_BSS_02169C54
OVERLAY11_BSS_02169C54: ; 0x02169C54
    .space 0x4

    .global OVERLAY11_BSS_02169C58
OVERLAY11_BSS_02169C58: ; 0x02169C58
    .space 0xC

    .global OVERLAY11_BSS_02169C64
OVERLAY11_BSS_02169C64: ; 0x02169C64
    .space 0x4

    .global OVERLAY11_BSS_02169C68
OVERLAY11_BSS_02169C68: ; 0x02169C68
    .space 0x8

    .global OVERLAY11_BSS_02169C70
OVERLAY11_BSS_02169C70: ; 0x02169C70
    .space 0x4

    .global OVERLAY11_BSS_02169C74
OVERLAY11_BSS_02169C74: ; 0x02169C74
    .space 0x8

    .global OVERLAY11_BSS_02169C7C
OVERLAY11_BSS_02169C7C: ; 0x02169C7C
    .space 0xC

    .global OVERLAY11_BSS_02169C88
OVERLAY11_BSS_02169C88: ; 0x02169C88
    .space 0xC
