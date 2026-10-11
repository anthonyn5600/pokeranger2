    .include "macros.inc"
    .include "include/arm9_0202B8A4.inc"

    .text

	arm_func_start sub_0202B8A4
sub_0202B8A4: ; 0x0202B8A4
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202B5D0
	ldr r0, _0202B8D4 ; =ptr_FUN_0202b8d8_0208ccac
	mov r1, #0
	str r0, [r4]
	str r1, [r4, #0x10]
	str r1, [r4, #0x14]
	str r1, [r4, #0x18]
	mov r0, r4
	str r1, [r4, #0x1c]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202B8D4: .word ptr_FUN_0202b8d8_0208ccac
	arm_func_end sub_0202B8A4

	arm_func_start sub_0202B8D8
sub_0202B8D8: ; 0x0202B8D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202B64C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202B8D8

	arm_func_start sub_0202B8EC
sub_0202B8EC: ; 0x0202B8EC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202B64C
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202B8EC

	arm_func_start sub_0202B908
sub_0202B908: ; 0x0202B908
	mov r1, #0
	str r1, [r0, #0x14]
	str r1, [r0, #0x18]
	str r1, [r0, #0x10]
	ldr ip, _0202B924 ; =sub_0202B674
	str r1, [r0, #0x1c]
	bx ip
	.align 2, 0
_0202B924: .word sub_0202B674
	arm_func_end sub_0202B908

	arm_func_start sub_0202B928
sub_0202B928: ; 0x0202B928
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldr ip, [r7, #4]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp ip, #0
	bne _0202B960
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end sub_0202B928
_0202B960:
	ldr r0, [r7, #0x1c]
	cmp r0, #0
	movne r0, #0
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
	mov r0, #2
	str r0, [r7, #0x1c]
	str r5, [r7, #0x14]
	str r6, [r7, #0x18]
	str r4, [r7, #0x10]
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_0202B98C
sub_0202B98C: ; 0x0202B98C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	ldr ip, [r7, #4]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp ip, #0
	bne _0202B9C4
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end sub_0202B98C
_0202B9C4:
	ldr r0, [r7, #0x1c]
	cmp r0, #0
	movne r0, #0
	ldmneia sp!, {r3, r4, r5, r6, r7, pc}
	mov r0, #1
	str r0, [r7, #0x1c]
	str r5, [r7, #0x14]
	str r6, [r7, #0x18]
	str r4, [r7, #0x10]
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_0202B9EC
sub_0202B9EC: ; 0x0202B9EC
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x14
	mov r7, r0
	ldr r0, [r7, #0x1c]
	mov r4, #0
	mov r5, r4
	cmp r0, #1
	beq _0202BA18
	cmp r0, #2
	beq _0202BB34
	b _0202BC58
	arm_func_end sub_0202B9EC
_0202BA18:
	ldr r0, [r7, #8]
	ldr r6, [r7, #0x10]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	cmp r6, #0x800
	movhs r6, #0x800
	bl CARD_LockBackup
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _0202BA88
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x14]
	mov r2, r6
	bl CARDi_RequestStreamCommand
	mov r5, r0
	b _0202BAD8
_0202BA88:
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _0202BAD8
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [r7, #0x18]
	ldr r1, [r7, #0x14]
	mov r2, r6
	bl CARDi_RequestStreamCommand
	mov r5, r0
_0202BAD8:
	bl CARD_GetResultCode
	str r0, [r7, #0xc]
	ldr r0, [r7, #8]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl CARD_UnlockBackup
	cmp r5, #0
	beq _0202BB2C
	ldr r0, [r7, #0x10]
	sub r0, r0, r6
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x18]
	add r0, r0, r6
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x14]
	add r0, r0, r6
	str r0, [r7, #0x14]
	ldr r0, [r7, #0x10]
	cmp r0, #0
	moveq r4, #1
	b _0202BC5C
_0202BB2C:
	mov r4, #1
	b _0202BC5C
_0202BB34:
	ldr r0, [r7, #8]
	ldr r6, [r7, #0x10]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	cmp r6, #0x800
	movhs r6, #0x800
	bl CARD_LockBackup
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _0202BBA8
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	mov r0, #0xa
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x18]
	mov r2, r6
	bl CARDi_RequestStreamCommand
	mov r5, r0
	b _0202BBFC
_0202BBA8:
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _0202BBFC
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	mov r0, #7
	str r0, [sp, #8]
	mov r0, #0xa
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, [r7, #0x14]
	ldr r1, [r7, #0x18]
	mov r2, r6
	bl CARDi_RequestStreamCommand
	mov r5, r0
_0202BBFC:
	bl CARD_GetResultCode
	str r0, [r7, #0xc]
	ldr r0, [r7, #8]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl CARD_UnlockBackup
	cmp r5, #0
	beq _0202BC50
	ldr r0, [r7, #0x10]
	sub r0, r0, r6
	str r0, [r7, #0x10]
	ldr r0, [r7, #0x18]
	add r0, r0, r6
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x14]
	add r0, r0, r6
	str r0, [r7, #0x14]
	ldr r0, [r7, #0x10]
	cmp r0, #0
	moveq r4, #1
	b _0202BC5C
_0202BC50:
	mov r4, #1
	b _0202BC5C
_0202BC58:
	mov r4, #1
_0202BC5C:
	cmp r4, #0
	movne r0, #0
	strne r0, [r7, #0x1c]
	mov r0, r4
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, pc}

	arm_func_start sub_0202BC74
sub_0202BC74: ; 0x0202BC74
	stmdb sp!, {r3, lr}
	cmp r0, #0
	cmpne r1, #0
	mov ip, #0
	cmpne r2, #0
	beq _0202BCCC
	mov lr, ip
	ble _0202BCCC
	arm_func_end sub_0202BC74
_0202BC94:
	ldrsb r3, [r0, lr]
	strb r3, [r1, lr]
	cmp r3, #0x61
	blt _0202BCB0
	cmp r3, #0x7a
	suble r3, r3, #0x20
	strleb r3, [r1, lr]
_0202BCB0:
	ldrsb r3, [r1, lr]
	cmp r3, #0
	beq _0202BCCC
	add lr, lr, #1
	cmp lr, r2
	add ip, ip, #1
	blt _0202BC94
_0202BCCC:
	mov r0, ip
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202BCD4
sub_0202BCD4: ; 0x0202BCD4
	stmdb sp!, {r3, lr}
	ldr r2, _0202BCF8 ; =MAIN_BSS_0210CA40
	mov r1, r0
	ldr r0, [r2]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN11CFieldScene12ov0_02123060Em
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BCF8: .word MAIN_BSS_0210CA40
	arm_func_end sub_0202BCD4

	arm_func_start sub_0202BCFC
sub_0202BCFC: ; 0x0202BCFC
	ldr r1, _0202BD58 ; =MAIN_BSS_0210CA5C
	ldr r1, [r1]
	cmp r1, #0
	beq _0202BD50
	ldr r3, [r1, #4]
	mov r2, #0
	cmp r3, #0
	ble _0202BD48
	ldr ip, [r1, #8]
	arm_func_end sub_0202BCFC
_0202BD20:
	ldr r1, [ip, r2, lsl #2]
	cmp r1, #0
	beq _0202BD3C
	ldr r1, [r1, #0x58]
	cmp r0, r1
	ldreq r0, [ip, r2, lsl #2]
	bxeq lr
_0202BD3C:
	add r2, r2, #1
	cmp r2, r3
	blt _0202BD20
_0202BD48:
	mov r0, #0
	bx lr
_0202BD50:
	mov r0, #0
	bx lr
	.align 2, 0
_0202BD58: .word MAIN_BSS_0210CA5C

	arm_func_start sub_0202BD5C
sub_0202BD5C: ; 0x0202BD5C
	ldr r1, _0202BDB8 ; =MAIN_BSS_0210CA50
	ldr r1, [r1]
	cmp r1, #0
	beq _0202BDB0
	ldr r3, [r1, #4]
	mov r2, #0
	cmp r3, #0
	ble _0202BDA8
	ldr ip, [r1, #8]
	arm_func_end sub_0202BD5C
_0202BD80:
	ldr r1, [ip, r2, lsl #2]
	cmp r1, #0
	beq _0202BD9C
	ldr r1, [r1, #0x58]
	cmp r0, r1
	ldreq r0, [ip, r2, lsl #2]
	bxeq lr
_0202BD9C:
	add r2, r2, #1
	cmp r2, r3
	blt _0202BD80
_0202BDA8:
	mov r0, #0
	bx lr
_0202BDB0:
	mov r0, #0
	bx lr
	.align 2, 0
_0202BDB8: .word MAIN_BSS_0210CA50

	arm_func_start sub_0202BDBC
sub_0202BDBC: ; 0x0202BDBC
	stmdb sp!, {r3, lr}
	ldr r1, _0202BDE0 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034604Em
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BDE0: .word s_game
	arm_func_end sub_0202BDBC

	arm_func_start sub_0202BDE4
sub_0202BDE4: ; 0x0202BDE4
	stmdb sp!, {r3, lr}
	ldr r0, _0202BE08 ; =_0208F304
	mov r1, #1
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F4CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BE08: .word s_game
	arm_func_end sub_0202BDE4

	arm_func_start sub_0202BE0C
sub_0202BE0C: ; 0x0202BE0C
	stmdb sp!, {r3, lr}
	ldr r0, _0202BE30 ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F4CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BE30: .word s_game
	arm_func_end sub_0202BE0C

	arm_func_start sub_0202BE34
sub_0202BE34: ; 0x0202BE34
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	cmp r1, #0xb1
	ldreq r0, _0202BE70 ; =MAIN_BSS_020B26A0
	ldreqb r0, [r0, #1]
	cmpeq r0, #0
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	ldr r0, _0202BE74 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BE70: .word MAIN_BSS_020B26A0
_0202BE74: .word s_game
	arm_func_end sub_0202BE34

	arm_func_start sub_0202BE78
sub_0202BE78: ; 0x0202BE78
	stmdb sp!, {r3, lr}
	ldr r1, _0202BE9C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A08Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BE9C: .word s_game
	arm_func_end sub_0202BE78

	arm_func_start sub_0202BEA0
sub_0202BEA0: ; 0x0202BEA0
	mov r0, #0
	bx lr
	arm_func_end sub_0202BEA0

	arm_func_start sub_0202BEA8
sub_0202BEA8: ; 0x0202BEA8
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	cmp r1, #0x1a
	ldreq r2, _0202BEE8 ; =MAIN_BSS_020B26A0
	ldreqb r2, [r2, #1]
	cmpeq r2, #0
	moveq r0, #1
	ldmeqia sp!, {r3, pc}
	ldr r3, _0202BEEC ; =_0208F304
	ldr r2, [r0, #4]
	ldr r0, [r3]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BEE8: .word MAIN_BSS_020B26A0
_0202BEEC: .word s_game
	arm_func_end sub_0202BEA8

	arm_func_start sub_0202BEF0
sub_0202BEF0: ; 0x0202BEF0
	stmdb sp!, {r3, lr}
	ldr r1, _0202BF14 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B58Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BF14: .word s_game
	arm_func_end sub_0202BEF0

	arm_func_start sub_0202BF18
sub_0202BF18: ; 0x0202BF18
	stmdb sp!, {r3, lr}
	ldr r1, _0202BF3C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B9CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BF3C: .word s_game
	arm_func_end sub_0202BF18

	arm_func_start sub_0202BF40
sub_0202BF40: ; 0x0202BF40
	stmdb sp!, {r3, lr}
	ldr r1, _0202BF64 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034BB8Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BF64: .word s_game
	arm_func_end sub_0202BF40

	arm_func_start sub_0202BF68
sub_0202BF68: ; 0x0202BF68
	stmdb sp!, {r3, lr}
	ldr r1, _0202BF8C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F10Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BF8C: .word s_game
	arm_func_end sub_0202BF68

	arm_func_start sub_0202BF90
sub_0202BF90: ; 0x0202BF90
	stmdb sp!, {r3, lr}
	ldr r1, _0202BFB4 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034BCCEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BFB4: .word s_game
	arm_func_end sub_0202BF90

	arm_func_start sub_0202BFB8
sub_0202BFB8: ; 0x0202BFB8
	stmdb sp!, {r3, lr}
	ldr r1, _0202BFDC ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034BF8Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202BFDC: .word s_game
	arm_func_end sub_0202BFB8

	arm_func_start sub_0202BFE0
sub_0202BFE0: ; 0x0202BFE0
	stmdb sp!, {r3, lr}
	ldr r1, _0202C004 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C2CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C004: .word s_game
	arm_func_end sub_0202BFE0

	arm_func_start sub_0202C008
sub_0202C008: ; 0x0202C008
	stmdb sp!, {r3, lr}
	ldr r1, _0202C02C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F20Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C02C: .word s_game
	arm_func_end sub_0202C008

	arm_func_start sub_0202C030
sub_0202C030: ; 0x0202C030
	stmdb sp!, {r3, lr}
	ldr r1, _0202C054 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C44Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C054: .word s_game
	arm_func_end sub_0202C030

	arm_func_start sub_0202C058
sub_0202C058: ; 0x0202C058
	stmdb sp!, {r3, lr}
	ldr r1, _0202C07C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C5CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C07C: .word s_game
	arm_func_end sub_0202C058

	arm_func_start sub_0202C080
sub_0202C080: ; 0x0202C080
	stmdb sp!, {r3, lr}
	ldr r1, _0202C0A4 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F3CEi
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C0A4: .word s_game
	arm_func_end sub_0202C080

	arm_func_start sub_0202C0A8
sub_0202C0A8: ; 0x0202C0A8
	stmdb sp!, {r3, lr}
	ldr r1, _0202C0D4 ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	mov r3, #0x100
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	ldmia r2, {r1, r2}
	bl _ZN17UnkClass_0203447812sub_02034DE8Eiii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C0D4: .word s_game
	arm_func_end sub_0202C0A8

	arm_func_start sub_0202C0D8
sub_0202C0D8: ; 0x0202C0D8
	stmdb sp!, {r3, lr}
	ldr r1, _0202C0FC ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034E38Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C0FC: .word s_game
	arm_func_end sub_0202C0D8

	arm_func_start sub_0202C100
sub_0202C100: ; 0x0202C100
	stmdb sp!, {r3, lr}
	ldr r1, _0202C128 ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	ldmia r2, {r1, r2}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034CF4Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C128: .word s_game
	arm_func_end sub_0202C100

	arm_func_start sub_0202C12C
sub_0202C12C: ; 0x0202C12C
	stmdb sp!, {r3, lr}
	ldr r1, _0202C154 ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	ldmia r2, {r1, r2}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034D54Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C154: .word s_game
	arm_func_end sub_0202C12C

	arm_func_start sub_0202C158
sub_0202C158: ; 0x0202C158
	stmdb sp!, {r3, lr}
	ldr r1, _0202C17C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034DC8Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C17C: .word s_game
	arm_func_end sub_0202C158

	arm_func_start sub_0202C180
sub_0202C180: ; 0x0202C180
	stmdb sp!, {r3, lr}
	ldr r0, _0202C1C0 ; =_0208F304
	mov r1, #0x2b
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _0202C1C0 ; =_0208F304
	mov r1, #8
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C1C0: .word s_game
	arm_func_end sub_0202C180

	arm_func_start sub_0202C1C4
sub_0202C1C4: ; 0x0202C1C4
	stmdb sp!, {r3, lr}
	ldr r0, _0202C204 ; =_0208F304
	mov r1, #0x2c
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _0202C204 ; =_0208F304
	mov r1, #9
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C204: .word s_game
	arm_func_end sub_0202C1C4

	arm_func_start sub_0202C208
sub_0202C208: ; 0x0202C208
	ldr r1, _0202C228 ; =_0208F304
	ldr r2, [r0]
	ldr r1, [r1]
	mov r0, #0
	add r1, r1, #0x1000
	ldr r1, [r1, #0x48c]
	str r2, [r1, #0x1a4]
	bx lr
	.align 2, 0
_0202C228: .word s_game
	arm_func_end sub_0202C208

	arm_func_start sub_0202C22C
sub_0202C22C: ; 0x0202C22C
	ldr r0, _0202C244 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	ldr r0, [r0, #0x1a4]
	bx lr
	.align 2, 0
_0202C244: .word s_game
	arm_func_end sub_0202C22C

	arm_func_start sub_0202C248
sub_0202C248: ; 0x0202C248
	stmdb sp!, {r3, lr}
	ldr r0, _0202C268 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_020345D4Ev
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C268: .word s_game
	arm_func_end sub_0202C248

	arm_func_start sub_0202C26C
sub_0202C26C: ; 0x0202C26C
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _0202C364 ; =MAIN_BSS_0210CA78
	mov r5, r0
	ldr r0, [r1]
	mov r4, #0
	cmp r0, #0
	beq _0202C2E0
	mov r1, #9
	bl sub_02035ECC
	ldr r1, _0202C368 ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	mov r1, #0x18
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02019278
	cmp r0, #0
	ldr r0, _0202C36C ; =MAIN_BSS_0210CA6C
	moveq r4, #0
	ldr r0, [r0]
	cmp r0, #0
	beq _0202C2E0
	ldr r1, _0202C370 ; =MAIN_BSS_020B26A0
	ldrh r1, [r1, #0x1a]
	bl sub_02041D80
	ldrb r0, [r0]
	sub r0, r0, #0x26
	cmp r0, #1
	movls r4, #0
	arm_func_end sub_0202C26C
_0202C2E0:
	cmp r4, #0
	beq _0202C320
	ldr r0, _0202C368 ; =_0208F304
	mov r1, #0xb1
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _0202C368 ; =_0208F304
	mov r1, #0x1a
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	b _0202C35C
_0202C320:
	ldr r1, _0202C368 ; =_0208F304
	ldr r0, _0202C370 ; =MAIN_BSS_020B26A0
	ldr r2, [r1]
	ldrh r1, [r0, #0x1a]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	ldr r2, [r5]
	mov r3, #1
	bl _ZN17UnkClass_0203447812sub_020346CCEmii
	ldr r0, _0202C368 ; =_0208F304
	mov r1, #0x100
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F20Ei
_0202C35C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202C364: .word MAIN_BSS_0210CA78
_0202C368: .word s_game
_0202C36C: .word MAIN_BSS_0210CA6C
_0202C370: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202C374
sub_0202C374: ; 0x0202C374
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0xa0
	mov r0, #1
	bl sub_0202BCD4
	cmp r0, #0
	addeq sp, sp, #0xa0
	moveq r0, #1
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, _0202C43C ; =MAIN_BSS_0210CA4C
	ldr r4, [r0]
	cmp r4, #0
	beq _0202C430
	ldr lr, _0202C440 ; =DAT_02084c80
	add ip, sp, #0x50
	mov r5, #5
	arm_func_end sub_0202C374
_0202C3B0:
	ldmia lr!, {r0, r1, r2, r3}
	stmia ip!, {r0, r1, r2, r3}
	subs r5, r5, #1
	bne _0202C3B0
	ldr lr, _0202C444 ; =DAT_02084cd0
	add ip, sp, #0
	mov r5, #5
_0202C3CC:
	ldmia lr!, {r0, r1, r2, r3}
	stmia ip!, {r0, r1, r2, r3}
	subs r5, r5, #1
	bne _0202C3CC
	mov r6, #0
	add r5, sp, #0x50
_0202C3E4:
	ldr r1, [r5, r6, lsl #2]
	mov r0, r4
	bl _ZN19CFieldPartnerManage12ov0_0213A520Em
	cmp r0, #0
	beq _0202C424
	ldr r0, _0202C448 ; =_0208F304
	add r1, sp, #0
	ldr r0, [r0]
	ldr r1, [r1, r6, lsl #2]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r2, #0x40
	bl _ZN17UnkClass_0203447812sub_02034CF4Eii
	add sp, sp, #0xa0
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
_0202C424:
	add r6, r6, #1
	cmp r6, #0x14
	blt _0202C3E4
_0202C430:
	mov r0, #1
	add sp, sp, #0xa0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0202C43C: .word MAIN_BSS_0210CA4C
_0202C440: .word DAT_02084c80
_0202C444: .word DAT_02084cd0
_0202C448: .word s_game

	arm_func_start sub_0202C44C
sub_0202C44C: ; 0x0202C44C
	stmdb sp!, {r3, lr}
	ldr r1, _0202C474 ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	ldmia r2, {r1, r2}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034CA0Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C474: .word s_game
	arm_func_end sub_0202C44C

	arm_func_start sub_0202C478
sub_0202C478: ; 0x0202C478
	stmdb sp!, {r3, lr}
	ldr ip, [r0]
	ldr r3, _0202C50C ; =MAIN_BSS_020B26A0
	cmp ip, #0
	blt _0202C504
	cmp ip, #0x1f4
	bge _0202C504
	cmp ip, #0
	blt _0202C4C8
	cmp ip, #0x1f4
	bge _0202C4C8
	mov r0, ip, asr #4
	add r0, r3, r0, lsl #2
	add r0, r0, #0x7000
	mov r1, ip, lsl #0x1c
	ldr r2, [r0, #0xc3c]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #3
	b _0202C4CC
	arm_func_end sub_0202C478
_0202C4C8:
	mov r0, #0
_0202C4CC:
	cmp r0, #1
	bhs _0202C504
	mov r1, ip, lsl #0x1c
	add r0, r3, #0x3c
	mov lr, r1, lsr #0x1b
	mov r1, #3
	add r3, r0, #0x7c00
	mov ip, ip, asr #4
	mvn r1, r1, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #1
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
_0202C504:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C50C: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202C510
sub_0202C510: ; 0x0202C510
	stmdb sp!, {r3, lr}
	ldr ip, [r0]
	ldr r3, _0202C5A4 ; =MAIN_BSS_020B26A0
	cmp ip, #0
	blt _0202C59C
	cmp ip, #0x1f4
	bge _0202C59C
	cmp ip, #0
	blt _0202C560
	cmp ip, #0x1f4
	bge _0202C560
	mov r0, ip, asr #4
	add r0, r3, r0, lsl #2
	add r0, r0, #0x7000
	mov r1, ip, lsl #0x1c
	ldr r2, [r0, #0xc3c]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #3
	b _0202C564
	arm_func_end sub_0202C510
_0202C560:
	mov r0, #0
_0202C564:
	cmp r0, #2
	bhs _0202C59C
	mov r1, ip, lsl #0x1c
	add r0, r3, #0x3c
	mov lr, r1, lsr #0x1b
	mov r1, #3
	add r3, r0, #0x7c00
	mov ip, ip, asr #4
	mvn r1, r1, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #2
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
_0202C59C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C5A4: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202C5A8
sub_0202C5A8: ; 0x0202C5A8
	ldr r1, [r0]
	ldr r2, _0202C5EC ; =MAIN_BSS_020B26A0
	cmp r1, #0
	blt _0202C5E4
	cmp r1, #0x1f4
	bge _0202C5E4
	mov r0, r1, asr #4
	add r0, r2, r0, lsl #2
	add r0, r0, #0x7000
	mov r1, r1, lsl #0x1c
	ldr r2, [r0, #0xc3c]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #3
	bx lr
	arm_func_end sub_0202C5A8
_0202C5E4:
	mov r0, #0
	bx lr
	.align 2, 0
_0202C5EC: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202C5F0
sub_0202C5F0: ; 0x0202C5F0
	stmdb sp!, {r4, lr}
	mov r0, #0
	ldr lr, _0202C654 ; =MAIN_BSS_020B26A0
	mov r4, r0
	mov r2, r0
	arm_func_end sub_0202C5F0
_0202C604:
	cmp r4, #0
	blt _0202C638
	cmp r4, #0x1f4
	bge _0202C638
	mov r1, r4, asr #4
	add r1, lr, r1, lsl #2
	add r1, r1, #0x7000
	mov r3, r4, lsl #0x1c
	ldr ip, [r1, #0xc3c]
	mov r1, r3, lsr #0x1b
	mov r1, ip, lsr r1
	and r1, r1, #3
	b _0202C63C
_0202C638:
	mov r1, r2
_0202C63C:
	add r4, r4, #1
	cmp r1, #2
	addhs r0, r0, #1
	cmp r4, #0x1f4
	blt _0202C604
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202C654: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202C658
sub_0202C658: ; 0x0202C658
	ldr r2, [r0]
	ldr r0, _0202C6A0 ; =MAIN_BSS_020B26A0
	cmp r2, #0
	blt _0202C698
	cmp r2, #0x1f4
	bge _0202C698
	add r0, r0, #0x3c
	mov r1, r2, lsl #0x1c
	add r3, r0, #0x7c00
	mov r2, r2, asr #4
	mov r0, r1, lsr #0x1b
	mov r1, #3
	mvn r0, r1, lsl r0
	ldr r1, [r3, r2, lsl #2]
	and r0, r1, r0
	str r0, [r3, r2, lsl #2]
	arm_func_end sub_0202C658
_0202C698:
	mov r0, #0
	bx lr
	.align 2, 0
_0202C6A0: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202C6A4
sub_0202C6A4: ; 0x0202C6A4
	stmdb sp!, {r4, lr}
	mov r0, #0
	ldr lr, _0202C760 ; =MAIN_BSS_020B26A0
	mov r4, r0
	mov r2, r0
	arm_func_end sub_0202C6A4
_0202C6B8:
	cmp r4, #0
	blt _0202C6EC
	cmp r4, #0x1f4
	bge _0202C6EC
	mov r1, r4, asr #4
	add r1, lr, r1, lsl #2
	add r1, r1, #0x7000
	mov r3, r4, lsl #0x1c
	ldr ip, [r1, #0xc3c]
	mov r1, r3, lsr #0x1b
	mov r1, ip, lsr r1
	and r1, r1, #3
	b _0202C6F0
_0202C6EC:
	mov r1, r2
_0202C6F0:
	add r4, r4, #1
	cmp r1, #2
	addhs r0, r0, #1
	cmp r4, #0x1f4
	blt _0202C6B8
	add r1, lr, #0x7000
	ldr r2, [r1, #0xcb4]
	mov r1, r2, lsr #6
	and r1, r1, #3
	cmp r1, #2
	mov r1, r2, lsr #8
	and r1, r1, #3
	subeq r0, r0, #1
	cmp r1, #2
	mov r1, r2, lsr #0x18
	and r1, r1, #3
	subeq r0, r0, #1
	cmp r1, #2
	ldr r1, _0202C764 ; =0x0000010A
	subeq r0, r0, #1
	cmp r0, r1
	moveq r0, #1
	ldmeqia sp!, {r4, pc}
	add r1, r1, #1
	cmp r0, r1
	moveq r0, #2
	movne r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202C760: .word MAIN_BSS_020B26A0
_0202C764: .word 0x0000010A

	arm_func_start sub_0202C768
sub_0202C768: ; 0x0202C768
	stmdb sp!, {r3, r4, r5, lr}
	mov r3, r0
	ldr r1, [r3, #4]
	ldr r0, _0202C864 ; =MAIN_BSS_020B26A0
	cmp r1, #0
	blt _0202C7F8
	cmp r1, #0x1f4
	bge _0202C7F8
	cmp r1, #0
	blt _0202C7BC
	cmp r1, #0x1f4
	bge _0202C7BC
	mov r2, r1, asr #4
	add r2, r0, r2, lsl #2
	add r2, r2, #0x7000
	mov r4, r1, lsl #0x1c
	ldr r5, [r2, #0xc3c]
	mov r2, r4, lsr #0x1b
	mov r2, r5, lsr r2
	and r2, r2, #3
	b _0202C7C0
	arm_func_end sub_0202C768
_0202C7BC:
	mov r2, #0
_0202C7C0:
	cmp r2, #1
	bhs _0202C7F8
	mov r4, r1, lsl #0x1c
	add r2, r0, #0x3c
	mov r5, r4, lsr #0x1b
	mov r4, r1, asr #4
	mov ip, #3
	add lr, r2, #0x7c00
	mvn r2, ip, lsl r5
	ldr ip, [lr, r4, lsl #2]
	mov r1, #1
	and r2, ip, r2
	orr r1, r2, r1, lsl r5
	str r1, [lr, r4, lsl #2]
_0202C7F8:
	ldr ip, [r3, #4]
	mov r2, #0
	cmp ip, #0
	blt _0202C834
	cmp ip, #0x1f4
	bge _0202C834
	mov r1, ip, asr #4
	add r0, r0, r1, lsl #2
	add r0, r0, #0x7000
	mov r1, ip, lsl #0x1c
	ldr ip, [r0, #0xc3c]
	mov r0, r1, lsr #0x1b
	mov r0, ip, lsr r0
	and r0, r0, #3
	b _0202C838
_0202C834:
	mov r0, #0
_0202C838:
	cmp r0, #2
	ldr r0, _0202C868 ; =MAIN_BSS_0210CA40
	movne r2, #1
	ldr r0, [r0]
	cmp r0, #0
	beq _0202C85C
	ldr r0, [r0, #0x54]
	ldr r1, [r3]
	bl sub_02022B60
_0202C85C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202C864: .word MAIN_BSS_020B26A0
_0202C868: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202C86C
sub_0202C86C: ; 0x0202C86C
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	mov r3, r0
	ldr r1, [r3, #0xc]
	mov r0, #0
	str r1, [sp]
	str r0, [sp, #4]
	ldr r0, _0202C8AC ; =_0208F304
	ldmia r3, {r1, r2, r3}
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C8AC: .word s_game
	arm_func_end sub_0202C86C

	arm_func_start sub_0202C8B0
sub_0202C8B0: ; 0x0202C8B0
	ldr r0, _0202C8C8 ; =_0208F304
	ldr ip, _0202C8CC ; =_ZN17UnkClass_020091E812sub_02009ECCEv
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bx ip
	.align 2, 0
_0202C8C8: .word s_game
_0202C8CC: .word _ZN17UnkClass_020091E812sub_02009ECCEv
	arm_func_end sub_0202C8B0

	arm_func_start sub_0202C8D0
sub_0202C8D0: ; 0x0202C8D0
	stmdb sp!, {r3, lr}
	ldr r0, _0202C8F8 ; =_0208F304
	mov r1, #1
	ldr r0, [r0]
	mov r2, r1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C8F8: .word s_game
	arm_func_end sub_0202C8D0

	arm_func_start sub_0202C8FC
sub_0202C8FC: ; 0x0202C8FC
	stmdb sp!, {r3, lr}
	ldr r1, _0202C924 ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	ldmia r2, {r1, r2}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_020097FCEmm
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C924: .word s_game
	arm_func_end sub_0202C8FC

	arm_func_start sub_0202C928
sub_0202C928: ; 0x0202C928
	stmdb sp!, {r3, lr}
	ldr r1, _0202C94C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA04El
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C94C: .word s_game
	arm_func_end sub_0202C928

	arm_func_start sub_0202C950
sub_0202C950: ; 0x0202C950
	stmdb sp!, {r3, lr}
	ldr r0, _0202C970 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C970: .word s_game
	arm_func_end sub_0202C950

	arm_func_start sub_0202C974
sub_0202C974: ; 0x0202C974
	stmdb sp!, {r3, lr}
	ldr r1, _0202C998 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA28El
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C998: .word s_game
	arm_func_end sub_0202C974

	arm_func_start sub_0202C99C
sub_0202C99C: ; 0x0202C99C
	stmdb sp!, {r3, lr}
	ldr r0, _0202C9BC ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA38Ev
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C9BC: .word s_game
	arm_func_end sub_0202C99C

	arm_func_start sub_0202C9C0
sub_0202C9C0: ; 0x0202C9C0
	stmdb sp!, {r3, lr}
	ldr r1, _0202C9E4 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA48El
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202C9E4: .word s_game
	arm_func_end sub_0202C9C0

	arm_func_start sub_0202C9E8
sub_0202C9E8: ; 0x0202C9E8
	stmdb sp!, {r3, lr}
	ldr r0, _0202CA08 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA58Ev
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202CA08: .word s_game
	arm_func_end sub_0202C9E8

	arm_func_start sub_0202CA0C
sub_0202CA0C: ; 0x0202CA0C
	stmdb sp!, {r3, lr}
	ldr r0, _0202CA2C ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200B68CEv
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202CA2C: .word s_game
	arm_func_end sub_0202CA0C

	arm_func_start sub_0202CA30
sub_0202CA30: ; 0x0202CA30
	ldr r0, _0202CA4C ; =_0208F304
	ldr ip, _0202CA50 ; =_ZN17UnkClass_020091E812sub_0200B6A4Em
	ldr r0, [r0]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bx ip
	.align 2, 0
_0202CA4C: .word s_game
_0202CA50: .word _ZN17UnkClass_020091E812sub_0200B6A4Em
	arm_func_end sub_0202CA30

	arm_func_start sub_0202CA54
sub_0202CA54: ; 0x0202CA54
	ldr r0, _0202CA6C ; =_0208F304
	ldr ip, _0202CA70 ; =_ZN17UnkClass_020091E812sub_0200B6D4Ev
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bx ip
	.align 2, 0
_0202CA6C: .word s_game
_0202CA70: .word _ZN17UnkClass_020091E812sub_0200B6D4Ev
	arm_func_end sub_0202CA54

	arm_func_start sub_0202CA74
sub_0202CA74: ; 0x0202CA74
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	mov r3, r0
	ldr r1, [r3, #0xc]
	ldr r0, _0202CAB4 ; =_0208F304
	str r1, [sp]
	ldr r1, [r3, #0x10]
	str r1, [sp, #4]
	ldr r0, [r0]
	ldmia r3, {r1, r2, r3}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202CAB4: .word s_game
	arm_func_end sub_0202CA74

	arm_func_start sub_0202CAB8
sub_0202CAB8: ; 0x0202CAB8
	stmdb sp!, {r3, lr}
	ldr r1, _0202CB10 ; =MAIN_BSS_0210CA40
	ldr r2, [r1]
	cmp r2, #0
	mvnne r1, #0
	strne r1, [r2, #0x8c]
	ldr r1, _0202CB14 ; =_0208F304
	ldr r2, [r0, #4]
	ldr ip, [r1]
	mov r2, r2, lsl #0xc
	ldr r3, [r0]
	ldr r1, [r0, #8]
	add r0, ip, #0x1000
	mov ip, r3, lsl #0xc
	mov r3, r1, lsl #0x10
	ldr r0, [r0, #0x4b8]
	rsb r1, ip, #0
	rsb r2, r2, #0
	mov r3, r3, lsr #0x10
	bl _ZN17UnkClass_0200D3F812sub_0200D5FCEllt
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202CB10: .word MAIN_BSS_0210CA40
_0202CB14: .word s_game
	arm_func_end sub_0202CAB8

	arm_func_start sub_0202CB18
sub_0202CB18: ; 0x0202CB18
	ldr r1, _0202CB34 ; =MAIN_BSS_0210CA40
	ldr r1, [r1]
	cmp r1, #0
	ldrne r0, [r0]
	strne r0, [r1, #0x8c]
	mov r0, #0
	bx lr
	.align 2, 0
_0202CB34: .word MAIN_BSS_0210CA40
	arm_func_end sub_0202CB18

	arm_func_start sub_0202CB38
sub_0202CB38: ; 0x0202CB38
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	mov r5, r0
	ldr r0, [r4, #4]
	bl sub_0202BCD4
	ldr r1, _0202CC50 ; =MAIN_BSS_0210CA40
	ldr r2, [r1]
	cmp r2, #0
	mvnne r1, #0
	strne r1, [r2, #0x8c]
	mov r1, #0
	cmp r5, #0
	mov r3, r1
	cmpne r0, #0
	beq _0202CC18
	ldr r3, [r5, #8]
	cmp r3, #0
	beq _0202CB94
	ldr r2, [r3, #0xc]
	cmp r2, #0
	ldrne r1, [r2, #0x20]
	arm_func_end sub_0202CB38
_0202CB94:
	ldr r2, [r0, #8]
	cmp r2, #0
	beq _0202CBB4
	ldr r0, [r2, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x20]
	moveq r0, #0
	b _0202CBB8
_0202CBB4:
	mov r0, #0
_0202CBB8:
	mov r0, r0, asr #0xc
	add r0, r0, r1, asr #12
	add r0, r0, r0, lsr #31
	cmp r3, #0
	mov r1, r0, asr #1
	beq _0202CBE4
	ldr r0, [r3, #0xc]
	cmp r0, #0
	ldrne r3, [r0, #0x24]
	moveq r3, #0
	b _0202CBE8
_0202CBE4:
	mov r3, #0
_0202CBE8:
	cmp r2, #0
	beq _0202CC04
	ldr r0, [r2, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	b _0202CC08
_0202CC04:
	mov r0, #0
_0202CC08:
	mov r0, r0, asr #0xc
	add r0, r0, r3, asr #12
	add r0, r0, r0, lsr #31
	mov r3, r0, asr #1
_0202CC18:
	ldr r0, _0202CC54 ; =_0208F304
	ldr r2, [r4, #8]
	ldr r0, [r0]
	mov r1, r1, lsl #0xc
	add r0, r0, #0x1000
	mov r4, r3, lsl #0xc
	mov r3, r2, lsl #0x10
	ldr r0, [r0, #0x4b8]
	rsb r1, r1, #0
	rsb r2, r4, #0
	mov r3, r3, lsr #0x10
	bl _ZN17UnkClass_0200D3F812sub_0200D5FCEllt
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202CC50: .word MAIN_BSS_0210CA40
_0202CC54: .word s_game

	arm_func_start sub_0202CC58
sub_0202CC58: ; 0x0202CC58
	stmdb sp!, {r3, lr}
	ldr r0, _0202CC80 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b8]
	bl _ZN17UnkClass_0200D3F812sub_0200D9B8Ev
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202CC80: .word s_game
	arm_func_end sub_0202CC58

	arm_func_start sub_0202CC84
sub_0202CC84: ; 0x0202CC84
	ldr r0, _0202CCA0 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x8c]
	mov r0, #0
	bx lr
	.align 2, 0
_0202CCA0: .word MAIN_BSS_0210CA40
	arm_func_end sub_0202CC84

	arm_func_start sub_0202CCA4
sub_0202CCA4: ; 0x0202CCA4
	ldr r0, _0202CCC0 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	mvnne r0, #0
	strne r0, [r1, #0x8c]
	mov r0, #0
	bx lr
	.align 2, 0
_0202CCC0: .word MAIN_BSS_0210CA40
	arm_func_end sub_0202CCA4

	arm_func_start sub_0202CCC4
sub_0202CCC4: ; 0x0202CCC4
	ldr r0, _0202CCF4 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b8]
	ldr r0, [r0]
	cmp r0, #0
	moveq r0, #0
	bxeq lr
	ldr r0, [r0, #0x1c]
	mov r0, r0, asr #0xc
	rsb r0, r0, #0
	bx lr
	.align 2, 0
_0202CCF4: .word s_game
	arm_func_end sub_0202CCC4

	arm_func_start sub_0202CCF8
sub_0202CCF8: ; 0x0202CCF8
	ldr r0, _0202CD28 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b8]
	ldr r0, [r0]
	cmp r0, #0
	moveq r0, #0
	bxeq lr
	ldr r0, [r0, #0x20]
	mov r0, r0, asr #0xc
	rsb r0, r0, #0
	bx lr
	.align 2, 0
_0202CD28: .word s_game
	arm_func_end sub_0202CCF8

	arm_func_start sub_0202CD2C
sub_0202CD2C: ; 0x0202CD2C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202CD54
	bl _ZN6CActor12sub_020128D8Ev
	arm_func_end sub_0202CD2C
_0202CD54:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202CD5C
sub_0202CD5C: ; 0x0202CD5C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202CD84
	bl _ZN6CActor12sub_0201287CEv
	arm_func_end sub_0202CD5C
_0202CD84:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202CD8C
sub_0202CD8C: ; 0x0202CD8C
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x20
	mov r5, r0
	ldr r0, [r5]
	bl sub_0202BCD4
	mov r4, r0
	ldr r0, [r5, #4]
	bl sub_0202BCD4
	mov r1, #0
	cmp r4, #0
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	cmpne r0, #0
	beq _0202CE64
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202CE08
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202CDF0
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x10]
	str r0, [sp, #0x14]
	b _0202CE1C
	arm_func_end sub_0202CD8C
_0202CDF0:
	add r0, sp, #8
	str r1, [sp, #0x10]
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [sp, #0x14]
	b _0202CE1C
_0202CE08:
	add r0, sp, #0
	str r1, [sp, #0x10]
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [sp, #0x14]
_0202CE1C:
	ldr r0, [r4, #8]
	ldr r2, [sp, #0x10]
	ldr r1, [sp, #0x14]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	str r2, [sp, #0x18]
	str r1, [sp, #0x1c]
	cmpne r0, #0
	beq _0202CE4C
	add r1, sp, #0x18
	ldmia r1, {r1, r2}
	bl _ZN6CActor12sub_02012948E7Point2D
_0202CE4C:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202CE64
	bl _ZN6CActor12sub_0201287CEv
_0202CE64:
	mov r0, #0
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202CE70
sub_0202CE70: ; 0x0202CE70
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202CE98
	ldr r2, [r4, #4]
	mov r1, #1
	str r1, [r0, #0x5c]
	str r2, [r0, #0x60]
	arm_func_end sub_0202CE70
_0202CE98:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202CEA0
sub_0202CEA0: ; 0x0202CEA0
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202CED4
	mov r1, #0
	str r1, [r0, #0x5c]
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202CED4
	bl _ZN6CActor12sub_0201287CEv
	arm_func_end sub_0202CEA0
_0202CED4:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202CEDC
sub_0202CEDC: ; 0x0202CEDC
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x40
	mov r5, r0
	ldr r0, [r5]
	bl sub_0202BCD4
	mov r4, r0
	ldr r0, [r5, #4]
	bl sub_0202BCD4
	mov r1, #0
	mov r5, r0
	cmp r4, #0
	str r1, [sp, #0x38]
	str r1, [sp, #0x3c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	cmpne r5, #0
	beq _0202D068
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0202CF64
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202CF4C
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x28]
	str r0, [sp, #0x2c]
	b _0202CF78
	arm_func_end sub_0202CEDC
_0202CF4C:
	add r0, sp, #0x18
	str r1, [sp, #0x28]
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [sp, #0x2c]
	b _0202CF78
_0202CF64:
	add r0, sp, #0x10
	str r1, [sp, #0x28]
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [sp, #0x2c]
_0202CF78:
	ldr r2, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	ldr r0, [r5, #8]
	str r2, [sp, #0x38]
	str r1, [sp, #0x3c]
	cmp r0, #0
	beq _0202CFD0
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202CFB4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	b _0202CFE8
_0202CFB4:
	mov r0, #0
	add r1, sp, #8
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	b _0202CFE8
_0202CFD0:
	mov r0, #0
	add r1, sp, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
_0202CFE8:
	ldr r0, [r4, #8]
	ldr r2, [sp, #0x20]
	ldr r1, [sp, #0x24]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	str r2, [sp, #0x30]
	str r1, [sp, #0x34]
	cmpne r0, #0
	beq _0202D018
	add r1, sp, #0x30
	ldmia r1, {r1, r2}
	bl _ZN6CActor12sub_02012948E7Point2D
_0202D018:
	ldr r0, [r5, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D038
	add r1, sp, #0x38
	ldmia r1, {r1, r2}
	bl _ZN6CActor12sub_02012948E7Point2D
_0202D038:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D050
	bl _ZN6CActor12sub_0201287CEv
_0202D050:
	ldr r0, [r5, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D068
	bl _ZN6CActor12sub_0201287CEv
_0202D068:
	mov r0, #0
	add sp, sp, #0x40
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202D074
sub_0202D074: ; 0x0202D074
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	ldr r1, [r4, #4]
	movs r4, r0
	mov r0, r1, lsl #0x10
	mov r1, r0, lsr #0x10
	beq _0202D0C8
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D0B0
	bl _ZN6CActor12sub_020128ECEt
	arm_func_end sub_0202D074
_0202D0B0:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D0C8
	bl _ZN6CActor12sub_0201287CEv
_0202D0C8:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202D0D0
sub_0202D0D0: ; 0x0202D0D0
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	ldr r2, [r4, #4]
	ldr r1, [r4, #8]
	movs r4, r0
	mov r2, r2, lsl #0xc
	mov r0, r1, lsl #0xc
	str r2, [sp]
	str r0, [sp, #4]
	beq _0202D13C
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D124
	add r1, sp, #0
	ldmia r1, {r1, r2}
	bl _ZN6CActor12sub_02012948E7Point2D
	arm_func_end sub_0202D0D0
_0202D124:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D13C
	bl _ZN6CActor12sub_0201287CEv
_0202D13C:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202D148
sub_0202D148: ; 0x0202D148
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D188
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202D17C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x20]
	moveq r0, #0
	b _0202D180
	arm_func_end sub_0202D148
_0202D17C:
	mov r0, #0
_0202D180:
	mov r0, r0, asr #0xc
	ldmia sp!, {r3, pc}
_0202D188:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202D190
sub_0202D190: ; 0x0202D190
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D1D0
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202D1C4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	b _0202D1C8
	arm_func_end sub_0202D190
_0202D1C4:
	mov r0, #0
_0202D1C8:
	mov r0, r0, asr #0xc
	ldmia sp!, {r3, pc}
_0202D1D0:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202D1D8
sub_0202D1D8: ; 0x0202D1D8
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D22C
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202D220
	ldr r2, [r0, #0xc]
	cmp r2, #0
	moveq r0, #0
	beq _0202D224
	ldr r1, [r2, #0x8c]
	ldr r0, [r2, #0xa0]
	ldr r2, [r2, #0xb0]
	add r0, r1, r0
	add r0, r2, r0
	b _0202D224
	arm_func_end sub_0202D1D8
_0202D220:
	mov r0, #0
_0202D224:
	mov r0, r0, asr #0xc
	ldmia sp!, {r3, pc}
_0202D22C:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202D234
sub_0202D234: ; 0x0202D234
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D2D8
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202D268
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrneh r0, [r0, #0x72]
	moveq r0, #0
	b _0202D26C
	arm_func_end sub_0202D234
_0202D268:
	mov r0, #0
_0202D26C:
	cmp r0, #0x1000
	blt _0202D27C
	cmp r0, #0xf000
	blt _0202D284
_0202D27C:
	mov r0, #0
	ldmia sp!, {r3, pc}
_0202D284:
	cmp r0, #0x3000
	movlt r0, #0x2000
	ldmltia sp!, {r3, pc}
	cmp r0, #0x5000
	movlt r0, #0x4000
	ldmltia sp!, {r3, pc}
	cmp r0, #0x7000
	movlt r0, #0x6000
	ldmltia sp!, {r3, pc}
	cmp r0, #0x9000
	movlt r0, #0x8000
	ldmltia sp!, {r3, pc}
	cmp r0, #0xb000
	movlt r0, #0xa000
	ldmltia sp!, {r3, pc}
	cmp r0, #0xd000
	movlt r0, #0xc000
	ldmltia sp!, {r3, pc}
	cmp r0, #0xf000
	movlt r0, #0xe000
	ldmltia sp!, {r3, pc}
_0202D2D8:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202D2E0
sub_0202D2E0: ; 0x0202D2E0
	stmdb sp!, {r3, r4, r5, lr}
	cmp r1, #1
	ldr r4, _0202D38C ; =MAIN_BSS_020B26A0
	blt _0202D384
	ldr r5, [r0]
	mov r0, r4
	mov r1, r5
	bl sub_0201597C
	ldr r0, _0202D390 ; =0x00000FFF
	ldrh r1, [r4, #0x1a]
	and r0, r0, r5, asr #12
	cmp r1, r0
	bne _0202D384
	mov r0, r5, asr #0x18
	and r0, r0, #0xff
	cmp r0, #1
	beq _0202D330
	cmp r0, #2
	beq _0202D340
	b _0202D350
	arm_func_end sub_0202D2E0
_0202D330:
	mov r0, r5
	bl sub_0202BCFC
	mov r4, r0
	b _0202D35C
_0202D340:
	mov r0, r5
	bl sub_0202BD5C
	mov r4, r0
	b _0202D35C
_0202D350:
	mov r0, r5
	bl sub_0202BCD4
	mov r4, r0
_0202D35C:
	cmp r4, #0
	beq _0202D384
	mov r0, r4
	bl sub_02041C1C
	mov r1, #0
	mov r0, r4
	strb r1, [r4, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x1c]
	blx r1
_0202D384:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202D38C: .word MAIN_BSS_020B26A0
_0202D390: .word 0x00000FFF

	arm_func_start _ZN11CFieldActor12sub_0202D394Ev
_ZN11CFieldActor12sub_0202D394Ev: ; 0x0202D394
	bx lr
	arm_func_end _ZN11CFieldActor12sub_0202D394Ev

	arm_func_start sub_0202D398
sub_0202D398: ; 0x0202D398
	stmdb sp!, {r3, r4, r5, lr}
	cmp r1, #1
	ldr r4, _0202D440 ; =MAIN_BSS_020B26A0
	blt _0202D438
	ldr r5, [r0]
	mov r0, r4
	mov r1, r5
	bl sub_020158BC
	ldr r0, _0202D444 ; =0x00000FFF
	ldrh r1, [r4, #0x1a]
	and r0, r0, r5, asr #12
	cmp r1, r0
	bne _0202D438
	mov r0, r5
	bl sub_0202BCD4
	mov r1, r5, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	beq _0202D3F0
	cmp r1, #2
	beq _0202D410
	b _0202D42C
	arm_func_end sub_0202D398
_0202D3F0:
	cmp r0, #0
	beq _0202D42C
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	movne r0, #0
	b _0202D42C
_0202D410:
	cmp r0, #0
	beq _0202D42C
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #2
	movne r0, #0
_0202D42C:
	cmp r0, #0
	movne r1, #2
	strneb r1, [r0, #0x20]
_0202D438:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202D440: .word MAIN_BSS_020B26A0
_0202D444: .word 0x00000FFF

	arm_func_start sub_0202D448
sub_0202D448: ; 0x0202D448
	stmdb sp!, {r3, r4, r5, lr}
	cmp r1, #2
	ldr r4, _0202D4F4 ; =MAIN_BSS_020B26A0
	blt _0202D4EC
	ldr r5, [r0, #4]
	mov r0, r4
	mov r1, r5
	bl sub_0201597C
	ldr r0, _0202D4F8 ; =0x00000FFF
	ldrh r1, [r4, #0x1a]
	and r0, r0, r5, asr #12
	cmp r1, r0
	bne _0202D4EC
	mov r0, r5, asr #0x18
	and r0, r0, #0xff
	cmp r0, #1
	beq _0202D498
	cmp r0, #2
	beq _0202D4A8
	b _0202D4B8
	arm_func_end sub_0202D448
_0202D498:
	mov r0, r5
	bl sub_0202BCFC
	mov r4, r0
	b _0202D4C4
_0202D4A8:
	mov r0, r5
	bl sub_0202BD5C
	mov r4, r0
	b _0202D4C4
_0202D4B8:
	mov r0, r5
	bl sub_0202BCD4
	mov r4, r0
_0202D4C4:
	cmp r4, #0
	beq _0202D4EC
	mov r0, r4
	bl sub_02041C1C
	mov r1, #0
	mov r0, r4
	strb r1, [r4, #0x20]
	ldr r1, [r0]
	ldr r1, [r1, #0x1c]
	blx r1
_0202D4EC:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202D4F4: .word MAIN_BSS_020B26A0
_0202D4F8: .word 0x00000FFF

	arm_func_start sub_0202D4FC
sub_0202D4FC: ; 0x0202D4FC
	stmdb sp!, {r3, r4, r5, lr}
	cmp r1, #2
	ldr r4, _0202D5A4 ; =MAIN_BSS_020B26A0
	blt _0202D59C
	ldr r5, [r0, #4]
	mov r0, r4
	mov r1, r5
	bl sub_020158BC
	ldr r0, _0202D5A8 ; =0x00000FFF
	ldrh r1, [r4, #0x1a]
	and r0, r0, r5, asr #12
	cmp r1, r0
	bne _0202D59C
	mov r0, r5
	bl sub_0202BCD4
	mov r1, r5, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	beq _0202D554
	cmp r1, #2
	beq _0202D574
	b _0202D590
	arm_func_end sub_0202D4FC
_0202D554:
	cmp r0, #0
	beq _0202D590
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	movne r0, #0
	b _0202D590
_0202D574:
	cmp r0, #0
	beq _0202D590
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #2
	movne r0, #0
_0202D590:
	cmp r0, #0
	movne r1, #2
	strneb r1, [r0, #0x20]
_0202D59C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202D5A4: .word MAIN_BSS_020B26A0
_0202D5A8: .word 0x00000FFF

	arm_func_start sub_0202D5AC
sub_0202D5AC: ; 0x0202D5AC
	stmdb sp!, {r3, lr}
	mov r2, r0
	ldr r0, _0202D5D0 ; =MAIN_BSS_020B26A0
	cmp r1, #1
	movlt r0, #0
	ldmltia sp!, {r3, pc}
	ldr r1, [r2]
	bl sub_020157E4
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202D5D0: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202D5AC

	arm_func_start sub_0202D5D4
sub_0202D5D4: ; 0x0202D5D4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	ldmib r4, {r1, r2}
	bl sub_02041A70
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202D5D4

	arm_func_start sub_0202D5F0
sub_0202D5F0: ; 0x0202D5F0
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	bl sub_02041C1C
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202D5F0

	arm_func_start sub_0202D608
sub_0202D608: ; 0x0202D608
	stmdb sp!, {r4, lr}
	ldr r1, _0202D67C ; =MAIN_BSS_0210CA5C
	ldr lr, [r0]
	ldr r3, [r1]
	ldmib r0, {r1, r2}
	cmp r3, #0
	beq _0202D674
	ldr r4, [r3, #4]
	mov ip, #0
	cmp r4, #0
	ble _0202D660
	ldr r3, [r3, #8]
	arm_func_end sub_0202D608
_0202D638:
	ldr r0, [r3, ip, lsl #2]
	cmp r0, #0
	beq _0202D654
	ldr r0, [r0, #0x58]
	cmp lr, r0
	ldreq r0, [r3, ip, lsl #2]
	beq _0202D664
_0202D654:
	add ip, ip, #1
	cmp ip, r4
	blt _0202D638
_0202D660:
	mov r0, #0
_0202D664:
	cmp r0, #0
	beq _0202D674
	bl sub_02041A70
	ldmia sp!, {r4, pc}
_0202D674:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202D67C: .word MAIN_BSS_0210CA5C

	arm_func_start sub_0202D680
sub_0202D680: ; 0x0202D680
	stmdb sp!, {r3, lr}
	ldr r1, _0202D6EC ; =MAIN_BSS_0210CA5C
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r0, #0
	beq _0202D6E4
	ldr r3, [r0, #4]
	mov r1, #0
	cmp r3, #0
	ble _0202D6D4
	ldr ip, [r0, #8]
	arm_func_end sub_0202D680
_0202D6AC:
	ldr r0, [ip, r1, lsl #2]
	cmp r0, #0
	beq _0202D6C8
	ldr r0, [r0, #0x58]
	cmp r2, r0
	ldreq r0, [ip, r1, lsl #2]
	beq _0202D6D8
_0202D6C8:
	add r1, r1, #1
	cmp r1, r3
	blt _0202D6AC
_0202D6D4:
	mov r0, #0
_0202D6D8:
	cmp r0, #0
	beq _0202D6E4
	bl sub_02041C1C
_0202D6E4:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202D6EC: .word MAIN_BSS_0210CA5C

	arm_func_start sub_0202D6F0
sub_0202D6F0: ; 0x0202D6F0
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	ldr r2, [r4, #4]
	ldr r1, [r4, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	mov r2, r2, lsl #0xc
	mov r1, r1, lsl #0xc
	str r2, [sp]
	str r1, [sp, #4]
	cmpne r0, #0
	beq _0202D748
	add r1, sp, #0
	add r0, r0, #0xc
	mov r3, #0x1000
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011C20E7Point2Di
	arm_func_end sub_0202D6F0
_0202D748:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202D754
sub_0202D754: ; 0x0202D754
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	ldr r2, [r4, #4]
	ldr r1, [r4, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	mov r2, r2, lsl #0xc
	mov r1, r1, lsl #0xc
	str r2, [sp]
	str r1, [sp, #4]
	cmpne r0, #0
	beq _0202D7AC
	add r1, sp, #0
	add r0, r0, #0xc
	mov r3, #0x2000
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011C20E7Point2Di
	arm_func_end sub_0202D754
_0202D7AC:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202D7B8
sub_0202D7B8: ; 0x0202D7B8
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D7D8
	ldr r1, [r0]
	ldr r1, [r1, #0x34]
	blx r1
	arm_func_end sub_0202D7B8
_0202D7D8:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start _ZN11CFieldActor12sub_0202D7E0Ev
_ZN11CFieldActor12sub_0202D7E0Ev: ; 0x0202D7E0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #8]
	cmp r0, #0
	beq _0202D828
	ldr r0, [r4, #4]
	tst r0, #8
	bne _0202D828
	orr r0, r0, #8
	str r0, [r4, #4]
	ldr r0, [r4, #8]
	ldr r1, [r0, #0xc]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x1dc]
	strneb r0, [r1, #0x1e1]
	mov r0, #0
	str r0, [r4, #0x94]
	arm_func_end _ZN11CFieldActor12sub_0202D7E0Ev
_0202D828:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D840
	bl _ZN6CActor12sub_0201287CEv
_0202D840:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r1, [r0, #0xc]
	cmpne r1, #0
	movne r0, #0
	strne r0, [r1, #0xc]
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202D85C
sub_0202D85C: ; 0x0202D85C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D8B4
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202D8A4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202D89C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	b _0202D8A8
	arm_func_end sub_0202D85C
_0202D89C:
	mov r0, #0
	b _0202D8A8
_0202D8A4:
	mov r0, #0
_0202D8A8:
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, pc}
_0202D8B4:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202D8BC
sub_0202D8BC: ; 0x0202D8BC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D920
	ldr r5, [r0, #8]
	ldmib r4, {r1, r2}
	cmp r5, #0
	ldrne r6, [r5, #0xc]
	mov r4, r2, lsl #0xc
	mov r7, r1, lsl #0xc
	cmpne r6, #0
	beq _0202D920
	mov r1, r7
	add r0, r6, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D1CEl
	mov r1, r4
	add r0, r6, #0xc
	bl _ZN17UnkClass_0201179C12sub_02011D2CEl
	ldr r0, [r5, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	strne r7, [r0, #0x18]
	strne r4, [r0, #0x1c]
	arm_func_end sub_0202D8BC
_0202D920:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_0202D928
sub_0202D928: ; 0x0202D928
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202D95C
	ldr r0, [r0, #8]
	ldr r1, [r4, #4]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	mov r1, r1, lsl #0xc
	cmpne r0, #0
	strne r1, [r0, #0x8c]
	arm_func_end sub_0202D928
_0202D95C:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202D964
sub_0202D964: ; 0x0202D964
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	ldr r1, [r4, #4]
	movs r4, r0
	mov r0, r1, lsl #0x10
	mov r1, r0, lsr #0x10
	beq _0202D9B8
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D9A0
	bl _ZN6CActor12sub_020128ECEt
	arm_func_end sub_0202D964
_0202D9A0:
	ldr r0, [r4, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202D9B8
	bl _ZN6CActor12sub_0201287CEv
_0202D9B8:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202D9C0
sub_0202D9C0: ; 0x0202D9C0
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202DA10
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202DA08
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202DA00
	ldr r0, [r0, #0xc]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202D9C0
_0202DA00:
	mov r0, #0
	ldmia sp!, {r3, pc}
_0202DA08:
	mov r0, #0
	ldmia sp!, {r3, pc}
_0202DA10:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202DA18
sub_0202DA18: ; 0x0202DA18
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5]
	bl sub_0202BCD4
	mov r4, r0
	ldr r0, [r5, #4]
	bl sub_0202BCD4
	cmp r4, #0
	cmpne r0, #0
	beq _0202DAF8
	ldr r4, [r4, #8]
	ldr r2, [r5, #8]
	cmp r4, #0
	beq _0202DA64
	ldr r1, [r4, #0xc]
	cmp r1, #0
	ldrne r3, [r1, #0x20]
	moveq r3, #0
	b _0202DA68
	arm_func_end sub_0202DA18
_0202DA64:
	mov r3, #0
_0202DA68:
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0202DA88
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x20]
	moveq r0, #0
	b _0202DA8C
_0202DA88:
	mov r0, #0
_0202DA8C:
	sub r0, r3, r0
	cmp r4, #0
	mov r3, r0, asr #0xc
	beq _0202DAB0
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ldrne r4, [r0, #0x24]
	moveq r4, #0
	b _0202DAB4
_0202DAB0:
	mov r4, #0
_0202DAB4:
	cmp r1, #0
	beq _0202DAD0
	ldr r0, [r1, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0x24]
	moveq r0, #0
	b _0202DAD4
_0202DAD0:
	mov r0, #0
_0202DAD4:
	sub r0, r4, r0
	mov r1, r0, asr #0xc
	mul r0, r1, r1
	mul r1, r2, r2
	mla r0, r3, r3, r0
	cmp r1, r0
	movgt r0, #0
	movle r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_0202DAF8:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202DB00
sub_0202DB00: ; 0x0202DB00
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202DB68
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0202DB4C
	ldr r1, [r0, #4]
	bic r1, r1, #8
	str r1, [r0, #4]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	beq _0202DB4C
	mov r1, #3
	str r1, [r2, #0x1dc]
	mov r1, #0
	strb r1, [r2, #0x1e1]
	arm_func_end sub_0202DB00
_0202DB4C:
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r1, [r0, #0xc]
	cmpne r1, #0
	ldrneh r0, [r1, #4]
	bicne r0, r0, #8
	strneh r0, [r1, #4]
_0202DB68:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202DB70
sub_0202DB70: ; 0x0202DB70
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202DBE0
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0202DBC4
	ldr r1, [r0, #4]
	tst r1, #8
	bne _0202DBC4
	orr r1, r1, #8
	str r1, [r0, #4]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1dc]
	strneb r1, [r2, #0x1e1]
	mov r1, #0
	str r1, [r0, #0x94]
	arm_func_end sub_0202DB70
_0202DBC4:
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r1, [r0, #0xc]
	cmpne r1, #0
	ldrneh r0, [r1, #4]
	orrne r0, r0, #8
	strneh r0, [r1, #4]
_0202DBE0:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202DBE8
sub_0202DBE8: ; 0x0202DBE8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202DC4C
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0202DC38
	ldr r1, [r0, #4]
	bic r1, r1, #8
	str r1, [r0, #4]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	beq _0202DC38
	mov r1, #3
	str r1, [r2, #0x1dc]
	mov r1, #0
	strb r1, [r2, #0x1e1]
	arm_func_end sub_0202DBE8
_0202DC38:
	ldr r3, [r0]
	ldr r1, [r4, #4]
	ldr r3, [r3, #0x38]
	mov r2, #0
	blx r3
_0202DC4C:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start _ZN11CFieldActor12sub_0202DC54Eii
_ZN11CFieldActor12sub_0202DC54Eii: ; 0x0202DC54
	stmdb sp!, {r3, lr}
	ldr r0, [r0, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN6CActor12sub_02012114Eii
	ldmia sp!, {r3, pc}
	arm_func_end _ZN11CFieldActor12sub_0202DC54Eii

	arm_func_start sub_0202DC74
sub_0202DC74: ; 0x0202DC74
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #8]
	cmpne r1, #0
	beq _0202DCC4
	ldr r1, [r0, #4]
	tst r1, #8
	bne _0202DCC4
	orr r1, r1, #8
	str r1, [r0, #4]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1dc]
	strneb r1, [r2, #0x1e1]
	mov r1, #0
	str r1, [r0, #0x94]
	arm_func_end sub_0202DC74
_0202DCC4:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202DCCC
sub_0202DCCC: ; 0x0202DCCC
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202DD0C
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202DD04
	ldr r0, [r0, #0xc]
	cmp r0, #0
	moveq r0, #2
	ldmeqia sp!, {r3, pc}
	bl _ZN6CActor12sub_02012AFCEv
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202DCCC
_0202DD04:
	mov r0, #2
	ldmia sp!, {r3, pc}
_0202DD0C:
	mov r0, #2
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202DD14
sub_0202DD14: ; 0x0202DD14
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	ldrne r1, [r4, #4]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	strne r1, [r0, #0x19c]
	mov r0, #0
	ldmia sp!, {r4, pc}
	arm_func_end sub_0202DD14

	arm_func_start sub_0202DD48
sub_0202DD48: ; 0x0202DD48
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	ldr r1, [r4, #4]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	mov r2, r1, lsl #0xc
	cmpne r0, #0
	beq _0202DD80
	mov r1, #0
	bl _ZN6CActor12sub_02012808Ell
	arm_func_end sub_0202DD48
_0202DD80:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202DD88
sub_0202DD88: ; 0x0202DD88
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x20
	mov r5, r0
	ldr r0, [r5]
	bl sub_0202BCD4
	movs r4, r0
	beq _0202DED8
	ldr r0, [r5, #8]
	ldr r1, [r4, #8]
	mov r0, r0, lsl #0xc
	cmp r1, #0
	beq _0202DDF8
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0202DDD8
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	b _0202DDF0
	arm_func_end sub_0202DD88
_0202DDD8:
	mov r1, #0
	add r2, sp, #8
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
_0202DDF0:
	add r1, sp, #0x10
	b _0202DE14
_0202DDF8:
	mov r2, #0
	add r3, sp, #0
	add r1, sp, #0x10
	str r2, [r3]
	str r2, [r3, #4]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
_0202DE14:
	ldr r2, [r5, #4]
	ldr lr, [r1]
	mov r2, r2, asr #4
	mov ip, r2, lsl #1
	add r2, ip, #1
	mov r3, r2, lsl #1
	ldr r5, _0202DEE4 ; =FX_SinCosTable_
	mov r2, ip, lsl #1
	ldrsh r3, [r5, r3]
	ldrsh r2, [r5, r2]
	ldr r1, [r1, #4]
	smull ip, r5, r0, r3
	smull r3, r2, r0, r2
	mov ip, ip, lsr #0xc
	mov r3, r3, lsr #0xc
	orr ip, ip, r5, lsl #20
	orr r3, r3, r2, lsl #20
	add r5, lr, ip
	add r1, r1, r3
	cmp r0, #0
	str r5, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r4, #8]
	bne _0202DE94
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202DED8
	mov r1, #0xf000
	mov r2, #0x1e
	bl _ZN6CActor12sub_02012860Eli
	b _0202DED8
_0202DE94:
	cmp r0, #0
	beq _0202DED8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202DEB4
	mov r1, #0xa000
	mov r2, #0x1e
	bl _ZN6CActor12sub_02012860Eli
_0202DEB4:
	ldr r0, [r4, #8]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202DED8
	add r1, sp, #0x18
	add r0, r0, #0xc
	mov r3, #0x1e
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011AB0E7Point2Dm
_0202DED8:
	mov r0, #0
	add sp, sp, #0x20
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202DEE4: .word FX_SinCosTable_

	arm_func_start sub_0202DEE8
sub_0202DEE8: ; 0x0202DEE8
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x20
	mov r5, r0
	ldr r0, [r5]
	bl sub_0202BCD4
	movs r4, r0
	beq _0202E050
	ldr r0, [r5, #8]
	ldr r1, [r4, #8]
	mov r0, r0, lsl #0xc
	cmp r1, #0
	beq _0202DF58
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0202DF38
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x10]
	str r1, [sp, #0x14]
	b _0202DF50
	arm_func_end sub_0202DEE8
_0202DF38:
	mov r1, #0
	add r2, sp, #8
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
_0202DF50:
	add r1, sp, #0x10
	b _0202DF74
_0202DF58:
	mov r2, #0
	add r3, sp, #0
	add r1, sp, #0x10
	str r2, [r3]
	str r2, [r3, #4]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
_0202DF74:
	ldr r2, [r5, #4]
	ldr r6, [r1]
	mov r2, r2, asr #4
	mov lr, r2, lsl #1
	add r2, lr, #1
	mov r3, r2, lsl #1
	ldr ip, _0202E05C ; =FX_SinCosTable_
	mov r2, lr, lsl #1
	ldrsh r3, [ip, r3]
	ldrsh r2, [ip, r2]
	ldr r1, [r1, #4]
	smull lr, ip, r0, r3
	smull r3, r2, r0, r2
	mov lr, lr, lsr #0xc
	mov r3, r3, lsr #0xc
	orr lr, lr, ip, lsl #20
	orr r3, r3, r2, lsl #20
	add ip, r6, lr
	add r1, r1, r3
	str r1, [sp, #0x1c]
	cmp r0, #0
	str ip, [sp, #0x18]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x10]
	bne _0202E000
	ldr r3, [r4, #8]
	mov r0, r0, lsl #0x10
	cmp r3, #0
	mov r2, r0, lsr #0x10
	ldrne r0, [r3, #0xc]
	mov r1, r1, lsl #0xc
	cmpne r0, #0
	beq _0202E050
	bl _ZN6CActor12sub_02012860Eli
	b _0202E050
_0202E000:
	ldr r2, [r4, #8]
	mov r0, r0, lsl #0x10
	cmp r2, #0
	mov r5, r0, lsr #0x10
	mov r1, r1, lsl #0xc
	beq _0202E050
	ldr r0, [r2, #0xc]
	cmp r0, #0
	beq _0202E02C
	mov r2, r5
	bl _ZN6CActor12sub_02012860Eli
_0202E02C:
	ldr r0, [r4, #8]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202E050
	add r1, sp, #0x18
	mov r3, r5
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011AB0E7Point2Dm
_0202E050:
	mov r0, #0
	add sp, sp, #0x20
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0202E05C: .word FX_SinCosTable_

	arm_func_start sub_0202E060
sub_0202E060: ; 0x0202E060
	mov r0, #0
	bx lr
	arm_func_end sub_0202E060

	arm_func_start sub_0202E068
sub_0202E068: ; 0x0202E068
	mov r0, #0
	bx lr
	arm_func_end sub_0202E068

	arm_func_start sub_0202E070
sub_0202E070: ; 0x0202E070
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #8
	ldr r1, [r0]
	mvn r0, #0
	mov r2, r1, asr #0x18
	and r3, r2, #0xff
	cmp r3, #1
	mov r2, #0
	beq _0202E0A0
	cmp r3, #2
	beq _0202E110
	b _0202E16C
	arm_func_end sub_0202E070
_0202E0A0:
	ldr r3, _0202E1DC ; =MAIN_BSS_0210CA5C
	ldr lr, [r3]
	cmp lr, #0
	beq _0202E16C
	ldr r5, [lr, #4]
	mov r4, r2
	cmp r5, #0
	ble _0202E16C
	mov ip, r2
_0202E0C4:
	cmp r5, r4
	ldrgt r3, [lr, #8]
	movle r6, ip
	ldrgt r6, [r3, r4, lsl #2]
	cmp r6, #0
	beq _0202E100
	ldr r3, [r6, #0x58]
	cmp r1, r3
	bne _0202E100
	ldr r2, [r6, #0xe8]
	mov r0, #1
	mov r2, r2, lsl #0x10
	strb r0, [r6, #0x20]
	mov r2, r2, lsr #0x10
	b _0202E16C
_0202E100:
	add r4, r4, #1
	cmp r4, r5
	blt _0202E0C4
	b _0202E16C
_0202E110:
	ldr r3, _0202E1E0 ; =MAIN_BSS_0210CA50
	ldr r5, [r3]
	cmp r5, #0
	beq _0202E16C
	ldr lr, [r5, #4]
	mov r4, r2
	cmp lr, #0
	ble _0202E16C
	mov ip, r2
_0202E134:
	cmp lr, r4
	ldrgt r3, [r5, #8]
	movle r6, ip
	ldrgt r6, [r3, r4, lsl #2]
	cmp r6, #0
	beq _0202E160
	ldr r3, [r6, #0x58]
	cmp r1, r3
	ldreq r0, [r6, #0xe8]
	ldreqh r2, [r6, #0xec]
	beq _0202E16C
_0202E160:
	add r4, r4, #1
	cmp r4, lr
	blt _0202E134
_0202E16C:
	mvn r3, #0
	cmp r0, r3
	beq _0202E1C8
	cmp r0, #0
	ldr r0, _0202E1E4 ; =MAIN_BSS_0210CA4C
	ldreq r3, _0202E1E8 ; =0x00001E16
	moveq r4, #1
	ldr r0, [r0]
	movne r4, #0
	movne r3, #0xe
	cmp r0, #0
	beq _0202E1AC
	str r4, [sp]
	mov ip, #1
	str ip, [sp, #4]
	bl _ZN19CFieldPartnerManage12ov0_0213A360Emttii
_0202E1AC:
	cmp r4, #0
	bne _0202E1D0
	bl sub_020233A4
	cmp r0, #0
	beq _0202E1D0
	bl sub_02022B20
	b _0202E1D0
_0202E1C8:
	ldr r0, _0202E1EC ; =s_syscall_actor_party_add_error_0208d3f8
	bl LogError
_0202E1D0:
	mvn r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0202E1DC: .word MAIN_BSS_0210CA5C
_0202E1E0: .word MAIN_BSS_0210CA50
_0202E1E4: .word MAIN_BSS_0210CA4C
_0202E1E8: .word 0x00001E16
_0202E1EC: .word s_syscall_actor_party_add_error_0208d3f8

	arm_func_start LogError
LogError: ; 0x0202E1F0
	stmdb sp!, {r0, r1, r2, r3}
	stmdb sp!, {r3, lr}
	ldr r0, [sp, #8]
	add r1, sp, #0xc
	bl thunk_FUN_020442cc
	ldmia sp!, {r3, lr}
	add sp, sp, #0x10
	bx lr
	arm_func_end LogError

	arm_func_start sub_0202E210
sub_0202E210: ; 0x0202E210
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	mov r0, #1
	bl sub_0202BCD4
	cmp r0, #0
	addne sp, sp, #8
	movne r0, #1
	ldmneia sp!, {r4, pc}
	ldr r0, [r4]
	cmp r0, #7
	addls pc, pc, r0, lsl #2
	b _0202E2C4
_0202E244: ; jump table
	b _0202E264 ; case 0
	b _0202E270 ; case 1
	b _0202E27C ; case 2
	b _0202E288 ; case 3
	b _0202E294 ; case 4
	b _0202E2A0 ; case 5
	b _0202E2AC ; case 6
	b _0202E2B8 ; case 7
	arm_func_end sub_0202E210
_0202E264:
	ldr r1, _0202E308 ; =0x02032003
	mov r2, #0x63
	b _0202E2CC
_0202E270:
	ldr r1, _0202E30C ; =sub_02032004
	mov r2, #0xbc
	b _0202E2CC
_0202E27C:
	ldr r1, _0202E310 ; =0x02032005
	mov r2, #0xaa
	b _0202E2CC
_0202E288:
	ldr r1, _0202E314 ; =0x02032006
	mov r2, #0xb6
	b _0202E2CC
_0202E294:
	ldr r1, _0202E318 ; =0x02032007
	mov r2, #0x5c
	b _0202E2CC
_0202E2A0:
	ldr r1, _0202E31C ; =sub_02032008
	mov r2, #0xaf
	b _0202E2CC
_0202E2AC:
	ldr r1, _0202E320 ; =0x02032009
	mov r2, #0xb7
	b _0202E2CC
_0202E2B8:
	ldr r1, _0202E324 ; =0x0203200A
	mov r2, #0xd7
	b _0202E2CC
_0202E2C4:
	ldr r1, _0202E328 ; =0x0203200B
	mov r2, #0x1f
_0202E2CC:
	ldr r0, _0202E32C ; =MAIN_BSS_0210CA4C
	ldr r0, [r0]
	cmp r0, #0
	addeq sp, sp, #8
	mvneq r0, #0
	ldmeqia sp!, {r4, pc}
	mov r3, #0
	str r3, [sp]
	mov ip, #1
	mov r3, #0xe
	str ip, [sp, #4]
	bl _ZN19CFieldPartnerManage12ov0_0213A360Emttii
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202E308: .word 0x02032003
_0202E30C: .word 0x02032004
_0202E310: .word 0x02032005
_0202E314: .word 0x02032006
_0202E318: .word 0x02032007
_0202E31C: .word 0x02032008
_0202E320: .word 0x02032009
_0202E324: .word 0x0203200A
_0202E328: .word 0x0203200B
_0202E32C: .word MAIN_BSS_0210CA4C

	arm_func_start sub_0202E330
sub_0202E330: ; 0x0202E330
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr r1, _0202E418 ; =MAIN_BSS_0210CA4C
	ldr r0, [r0, #4]
	ldr sb, [r1]
	str r0, [sp]
	cmp sb, #0
	beq _0202E404
	ldr r0, [sb, #4]
	mov r8, #0
	cmp r0, #0
	ble _0202E3D8
	ldr r6, _0202E41C ; =s_0208d418
	ldr r5, _0202E420 ; =s_NPC_d_0208d428
	ldr r4, _0202E424 ; =s_Id_x_0208d430
	ldr fp, _0202E428 ; =s_partnertype_d_0208d438
	mov r7, r8
	arm_func_end sub_0202E330
_0202E370:
	cmp r0, r8
	ldrgt r0, [sb, #8]
	movle sl, r7
	ldrgt sl, [r0, r8, lsl #2]
	cmp sl, #0
	beq _0202E3C8
	mov r0, r6
	bl LogInfo
	mov r0, r5
	mov r1, r8
	bl LogInfo
	ldr r1, [sl, #0x58]
	mov r0, r4
	bl LogInfo
	ldr r1, [sl, #0x1fc]
	mov r0, fp
	bl LogInfo
	ldr r1, [sl, #0x1e8]
	ldr r0, _0202E42C ; =s_linenumber_d_0208d448
	bl LogInfo
	mov r0, r6
	bl LogInfo
_0202E3C8:
	ldr r0, [sb, #4]
	add r8, r8, #1
	cmp r8, r0
	blt _0202E370
_0202E3D8:
	ldr r1, [sp]
	mov r0, sb
	bl _ZN19CFieldPartnerManage12ov0_0213A050Em
	ldr r0, _0202E430 ; =MAIN_BSS_020B26A0
	ldr r1, [sp]
	bl sub_02015E54
	ldr r0, _0202E434 ; =s_party_leave_x_0208d458
	ldr r1, [sp]
	bl LogInfo
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0202E404:
	ldr r0, _0202E438 ; =s_error_actor_party_add_id_x_0208d46c
	ldr r1, [sp]
	bl LogInfo
	mvn r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202E418: .word MAIN_BSS_0210CA4C
_0202E41C: .word s_0208d418
_0202E420: .word s_NPC_d_0208d428
_0202E424: .word s_Id_x_0208d430
_0202E428: .word s_partnertype_d_0208d438
_0202E42C: .word s_linenumber_d_0208d448
_0202E430: .word MAIN_BSS_020B26A0
_0202E434: .word s_party_leave_x_0208d458
_0202E438: .word s_error_actor_party_add_id_x_0208d46c

	arm_func_start sub_0202E43C
sub_0202E43C: ; 0x0202E43C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	ldr r1, _0202E524 ; =MAIN_BSS_0210CA4C
	ldr r0, [r0, #4]
	ldr sb, [r1]
	str r0, [sp]
	cmp sb, #0
	beq _0202E510
	ldr r0, [sb, #4]
	mov r8, #0
	cmp r0, #0
	ble _0202E4E4
	ldr r6, _0202E528 ; =s_0208d418
	ldr r5, _0202E52C ; =s_NPC_d_0208d428
	ldr r4, _0202E530 ; =s_Id_x_0208d430
	ldr fp, _0202E534 ; =s_partnertype_d_0208d438
	mov r7, r8
	arm_func_end sub_0202E43C
_0202E47C:
	cmp r0, r8
	ldrgt r0, [sb, #8]
	movle sl, r7
	ldrgt sl, [r0, r8, lsl #2]
	cmp sl, #0
	beq _0202E4D4
	mov r0, r6
	bl LogInfo
	mov r0, r5
	mov r1, r8
	bl LogInfo
	ldr r1, [sl, #0x58]
	mov r0, r4
	bl LogInfo
	ldr r1, [sl, #0x1fc]
	mov r0, fp
	bl LogInfo
	ldr r1, [sl, #0x1e8]
	ldr r0, _0202E538 ; =s_linenumber_d_0208d448
	bl LogInfo
	mov r0, r6
	bl LogInfo
_0202E4D4:
	ldr r0, [sb, #4]
	add r8, r8, #1
	cmp r8, r0
	blt _0202E47C
_0202E4E4:
	ldr r1, [sp]
	mov r0, sb
	bl _ZN19CFieldPartnerManage12ov0_0213A084Em
	ldr r0, _0202E53C ; =MAIN_BSS_020B26A0
	ldr r1, [sp]
	bl sub_02015E54
	ldr r0, _0202E540 ; =s_party_leave_x_0208d458
	ldr r1, [sp]
	bl LogInfo
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
_0202E510:
	ldr r0, _0202E544 ; =s_error_actor_party_add_id_x_0208d46c
	ldr r1, [sp]
	bl LogInfo
	mvn r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202E524: .word MAIN_BSS_0210CA4C
_0202E528: .word s_0208d418
_0202E52C: .word s_NPC_d_0208d428
_0202E530: .word s_Id_x_0208d430
_0202E534: .word s_partnertype_d_0208d438
_0202E538: .word s_linenumber_d_0208d448
_0202E53C: .word MAIN_BSS_020B26A0
_0202E540: .word s_party_leave_x_0208d458
_0202E544: .word s_error_actor_party_add_id_x_0208d46c

	arm_func_start sub_0202E548
sub_0202E548: ; 0x0202E548
	mov r0, #0
	bx lr
	arm_func_end sub_0202E548

	arm_func_start sub_0202E550
sub_0202E550: ; 0x0202E550
	mov r0, #0
	bx lr
	arm_func_end sub_0202E550

	arm_func_start sub_0202E558
sub_0202E558: ; 0x0202E558
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202E60C
	ldr r1, _0202E618 ; =_0208F304
	ldr r1, [r1]
	add r1, r1, #0x1000
	ldr r1, [r1, #0x4b8]
	ldr r1, [r1]
	cmp r1, #0
	beq _0202E5A8
	ldr r2, [r1, #0x1c]
	ldr r1, [r1, #0x20]
	rsb r2, r2, #0
	rsb r1, r1, #0
	str r2, [sp]
	str r1, [sp, #4]
	b _0202E5F4
	arm_func_end sub_0202E558
_0202E5A8:
	ldr r2, [r0, #8]
	cmp r2, #0
	beq _0202E5C8
	ldr r1, [r2, #0xc]
	cmp r1, #0
	ldrne r1, [r1, #0x20]
	moveq r1, #0
	b _0202E5CC
_0202E5C8:
	mov r1, #0
_0202E5CC:
	str r1, [sp]
	cmp r2, #0
	beq _0202E5EC
	ldr r1, [r2, #0xc]
	cmp r1, #0
	ldrne r1, [r1, #0x24]
	moveq r1, #0
	b _0202E5F0
_0202E5EC:
	mov r1, #0
_0202E5F0:
	str r1, [sp, #4]
_0202E5F4:
	ldr r2, [r0, #4]
	add r1, sp, #0
	orr r2, r2, #0x100
	str r2, [r0, #4]
	ldmia r1, {r1, r2}
	bl _ZN11CFieldActor12sub_0203D404E7Point2D
_0202E60C:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202E618: .word s_game

	arm_func_start sub_0202E61C
sub_0202E61C: ; 0x0202E61C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202E644
	ldr r0, [r0, #0xc8]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202E61C
_0202E644:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202E64C
sub_0202E64C: ; 0x0202E64C
	stmdb sp!, {r3, r4, r5, lr}
	ldmia r0, {r4, r5}
	mov r0, r4
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202E674
	ldr r2, [r0]
	mov r1, r5
	ldr r2, [r2, #0x30]
	blx r2
	arm_func_end sub_0202E64C
_0202E674:
	cmp r4, #0
	ldreq r0, _0202E688 ; =MAIN_BSS_020B26A0
	streqh r5, [r0, #0x26]
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202E688: .word MAIN_BSS_020B26A0

	arm_func_start _ZN11CFieldActor12sub_0202E68CEi
_ZN11CFieldActor12sub_0202E68CEi: ; 0x0202E68C
	str r1, [r0, #0x14]
	bx lr
	arm_func_end _ZN11CFieldActor12sub_0202E68CEi

	arm_func_start sub_0202E694
sub_0202E694: ; 0x0202E694
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #4]
	orrne r1, r1, #0x80
	strne r1, [r0, #4]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202E694

	arm_func_start sub_0202E6B8
sub_0202E6B8: ; 0x0202E6B8
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #4]
	bicne r1, r1, #0x80
	strne r1, [r0, #4]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202E6B8

	arm_func_start sub_0202E6DC
sub_0202E6DC: ; 0x0202E6DC
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	ldr r2, [r4, #4]
	ldr r1, [r4, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	mov r2, r2, lsl #0xc
	mov r1, r1, lsl #0xc
	str r2, [sp]
	str r1, [sp, #4]
	cmpne r0, #0
	beq _0202E734
	add r1, sp, #0
	add r0, r0, #0xc
	mov r3, #0x800
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011C20E7Point2Di
	arm_func_end sub_0202E6DC
_0202E734:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202E740
sub_0202E740: ; 0x0202E740
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x18
	mov r5, r0
	ldr r0, [r5]
	bl sub_0202BCD4
	ldmib r5, {r4, lr}
	cmp r0, #0
	ldrne r0, [r0, #8]
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	ldr r3, [r5, #0xc]
	ldr ip, [r5, #0x10]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	mov r4, r4, lsl #0xc
	mov lr, lr, lsl #0xc
	mov r1, r1, lsl #0x10
	mov r2, r2, lsl #0x10
	str r4, [sp, #0x10]
	str lr, [sp, #0x14]
	mov r3, r3, lsl #0xc
	mov ip, ip, lsl #0xc
	mov r1, r1, lsr #0x10
	mov r2, r2, lsr #0x10
	cmpne r0, #0
	beq _0202E7CC
	str ip, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	mov r2, #0
	add r1, sp, #0x10
	str r2, [sp, #0xc]
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011CB4E7Point2Dllttt
	arm_func_end sub_0202E740
_0202E7CC:
	mov r0, #0
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202E7D8
sub_0202E7D8: ; 0x0202E7D8
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202E814
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0202E80C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	ldrne r0, [r0, #0xa4]
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202E7D8
_0202E80C:
	mov r0, #0
	ldmia sp!, {r3, pc}
_0202E814:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202E81C
sub_0202E81C: ; 0x0202E81C
	stmdb sp!, {r4, lr}
	ldr r4, [r0]
	mov r0, r4
	bl sub_0202BCD4
	cmp r0, #0
	ldrneb r0, [r0, #0x20]
	ldmneia sp!, {r4, pc}
	mov r0, r4, asr #0x18
	and r1, r0, #0xff
	cmp r1, #1
	ldr r0, _0202E9B4 ; =MAIN_BSS_020B26A0
	beq _0202E860
	cmp r1, #2
	beq _0202E8D0
	cmp r1, #3
	beq _0202E940
	b _0202E9AC
	arm_func_end sub_0202E81C
_0202E860:
	ldr r1, _0202E9B8 ; =0x00000FFF
	ldr r2, _0202E9BC ; =0x000001B9
	and ip, r1, r4, asr #12
	cmp ip, r2
	and r3, r4, r1
	movlt r1, #1
	movge r1, #0
	cmp r1, #0
	beq _0202E8BC
	cmp r3, #0x30
	bge _0202E8BC
	mov r1, r3, asr #2
	add r1, r3, r1, lsr #29
	add r2, r0, ip, lsl #4
	mov r0, r1, asr #3
	add r0, r2, r0, lsl #2
	add r0, r0, #0x2000
	mov r1, r3, lsl #0x1d
	ldr r2, [r0, #0x988]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #0xf
	b _0202E8C0
_0202E8BC:
	mov r0, #0
_0202E8C0:
	cmp r0, #0
	ble _0202E9AC
	sub r0, r0, #1
	ldmia sp!, {r4, pc}
_0202E8D0:
	ldr r1, _0202E9B8 ; =0x00000FFF
	ldr r2, _0202E9BC ; =0x000001B9
	and ip, r1, r4, asr #12
	cmp ip, r2
	and r3, r4, r1
	movlt r1, #1
	movge r1, #0
	cmp r1, #0
	beq _0202E92C
	cmp r3, #0x30
	bge _0202E92C
	mov r1, r3, asr #2
	add r1, r3, r1, lsr #29
	add r2, r0, ip, lsl #4
	mov r0, r1, asr #3
	add r0, r2, r0, lsl #2
	add r0, r0, #0x4000
	mov r1, r3, lsl #0x1d
	ldr r2, [r0, #0x518]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #0xf
	b _0202E930
_0202E92C:
	mov r0, #0
_0202E930:
	cmp r0, #0
	ble _0202E9AC
	sub r0, r0, #1
	ldmia sp!, {r4, pc}
_0202E940:
	ldr r1, _0202E9B8 ; =0x00000FFF
	ldr r2, _0202E9BC ; =0x000001B9
	and ip, r1, r4, asr #12
	cmp ip, r2
	and r3, r4, r1
	movlt r1, #1
	movge r1, #0
	cmp r1, #0
	beq _0202E99C
	cmp r3, #0x30
	bge _0202E99C
	mov r1, r3, asr #2
	add r1, r3, r1, lsr #29
	add r2, r0, ip, lsl #4
	mov r0, r1, asr #3
	add r0, r2, r0, lsl #2
	add r0, r0, #0x6000
	mov r1, r3, lsl #0x1d
	ldr r2, [r0, #0xa8]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #0xf
	b _0202E9A0
_0202E99C:
	mov r0, #0
_0202E9A0:
	cmp r0, #0
	subgt r0, r0, #1
	ldmgtia sp!, {r4, pc}
_0202E9AC:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202E9B4: .word MAIN_BSS_020B26A0
_0202E9B8: .word 0x00000FFF
_0202E9BC: .word 0x000001B9

	arm_func_start sub_0202E9C0
sub_0202E9C0: ; 0x0202E9C0
	stmdb sp!, {r4, lr}
	ldr r4, [r0]
	mov r0, r4
	bl sub_0202BCFC
	cmp r0, #0
	ldrneb r0, [r0, #0x20]
	ldmneia sp!, {r4, pc}
	ldr r0, _0202EA50 ; =0x00000FFF
	ldr r1, _0202EA54 ; =0x000001B9
	and r3, r0, r4, asr #12
	cmp r3, r1
	and r2, r4, r0
	movlt r0, #1
	movge r0, #0
	ldr r1, _0202EA58 ; =MAIN_BSS_020B26A0
	cmp r0, #0
	beq _0202EA3C
	cmp r2, #0x30
	bge _0202EA3C
	mov r0, r2, asr #2
	add r0, r2, r0, lsr #29
	add r1, r1, r3, lsl #4
	mov r0, r0, asr #3
	add r0, r1, r0, lsl #2
	add r0, r0, #0x2000
	mov r1, r2, lsl #0x1d
	ldr r2, [r0, #0x988]
	mov r0, r1, lsr #0x1b
	mov r0, r2, lsr r0
	and r0, r0, #0xf
	b _0202EA40
	arm_func_end sub_0202E9C0
_0202EA3C:
	mov r0, #0
_0202EA40:
	cmp r0, #0
	subgt r0, r0, #1
	movle r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202EA50: .word 0x00000FFF
_0202EA54: .word 0x000001B9
_0202EA58: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202EA5C
sub_0202EA5C: ; 0x0202EA5C
	stmdb sp!, {r3, r4, r5, lr}
	ldmia r0, {r4, r5}
	mov r0, r4
	bl sub_0202BCD4
	cmp r0, #0
	strneb r5, [r0, #0x20]
	mov r0, r4, asr #0x18
	and r1, r0, #0xff
	cmp r1, #1
	ldr r0, _0202EBFC ; =MAIN_BSS_020B26A0
	beq _0202EA9C
	cmp r1, #2
	beq _0202EB10
	cmp r1, #3
	beq _0202EB84
	b _0202EBF4
	arm_func_end sub_0202EA5C
_0202EA9C:
	ldr r2, _0202EC00 ; =0x00000FFF
	ldr r3, _0202EC04 ; =0x000001B9
	and r1, r2, r4, asr #12
	cmp r1, r3
	and r4, r4, r2
	movlt r2, #1
	movge r2, #0
	cmp r2, #0
	beq _0202EBF4
	cmp r4, #0x30
	bge _0202EBF4
	mov r2, r4, asr #2
	add r3, r0, #0x188
	mov ip, r4, lsl #0x1d
	add r0, r4, r2, lsr #29
	add r4, r3, #0x2800
	add r2, r5, #1
	mov ip, ip, lsr #0x1b
	mov r3, #0xf
	add r4, r4, r1, lsl #4
	mov r5, r0, asr #3
	mvn r1, r3, lsl ip
	ldr r3, [r4, r5, lsl #2]
	and r2, r2, #0xff
	and r0, r2, #0xf
	and r1, r3, r1
	orr r0, r1, r0, lsl ip
	str r0, [r4, r5, lsl #2]
	b _0202EBF4
_0202EB10:
	ldr r2, _0202EC00 ; =0x00000FFF
	ldr r3, _0202EC04 ; =0x000001B9
	and r1, r2, r4, asr #12
	cmp r1, r3
	and r4, r4, r2
	movlt r2, #1
	movge r2, #0
	cmp r2, #0
	beq _0202EBF4
	cmp r4, #0x30
	bge _0202EBF4
	mov r2, r4, asr #2
	add r3, r0, #0x118
	mov ip, r4, lsl #0x1d
	add r0, r4, r2, lsr #29
	add r4, r3, #0x4400
	add r2, r5, #1
	mov ip, ip, lsr #0x1b
	mov r3, #0xf
	add r4, r4, r1, lsl #4
	mov r5, r0, asr #3
	mvn r1, r3, lsl ip
	ldr r3, [r4, r5, lsl #2]
	and r2, r2, #0xff
	and r0, r2, #0xf
	and r1, r3, r1
	orr r0, r1, r0, lsl ip
	str r0, [r4, r5, lsl #2]
	b _0202EBF4
_0202EB84:
	ldr r2, _0202EC00 ; =0x00000FFF
	ldr r3, _0202EC04 ; =0x000001B9
	and r1, r2, r4, asr #12
	cmp r1, r3
	and r4, r4, r2
	movlt r2, #1
	movge r2, #0
	cmp r2, #0
	beq _0202EBF4
	cmp r4, #0x30
	bge _0202EBF4
	mov r2, r4, asr #2
	add r3, r0, #0xa8
	mov ip, r4, lsl #0x1d
	add r0, r4, r2, lsr #29
	add r4, r3, #0x6000
	add r2, r5, #1
	mov ip, ip, lsr #0x1b
	mov r3, #0xf
	add r4, r4, r1, lsl #4
	mov r5, r0, asr #3
	mvn r1, r3, lsl ip
	ldr r3, [r4, r5, lsl #2]
	and r2, r2, #0xff
	and r0, r2, #0xf
	and r1, r3, r1
	orr r0, r1, r0, lsl ip
	str r0, [r4, r5, lsl #2]
_0202EBF4:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202EBFC: .word MAIN_BSS_020B26A0
_0202EC00: .word 0x00000FFF
_0202EC04: .word 0x000001B9

	arm_func_start sub_0202EC08
sub_0202EC08: ; 0x0202EC08
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202ED04
	ldr r1, [r0, #0x58]
	ldr r3, _0202ED0C ; =0x00007FFF
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #6
	addls pc, pc, r1, lsl #2
	b _0202EC88
_0202EC38: ; jump table
	b _0202EC54 ; case 0
	b _0202EC5C ; case 1
	b _0202EC64 ; case 2
	b _0202EC6C ; case 3
	b _0202EC74 ; case 4
	b _0202EC7C ; case 5
	b _0202EC84 ; case 6
	arm_func_end sub_0202EC08
_0202EC54:
	sub r3, r3, #0x1f
	b _0202EC88
_0202EC5C:
	mov r3, #0x1f
	b _0202EC88
_0202EC64:
	mov r3, #0x3f0
	b _0202EC88
_0202EC6C:
	mov r3, #0x3f0
	b _0202EC88
_0202EC74:
	sub r3, r3, #0x1f
	b _0202EC88
_0202EC7C:
	sub r3, r3, #0x1f
	b _0202EC88
_0202EC84:
	sub r3, r3, #0x1f
_0202EC88:
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0202ED04
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1b0]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	beq _0202ECC4
	add r1, r2, #0x100
	strh r3, [r1, #0xac]
	mov r1, #0
	str r1, [r2, #0x1b0]
_0202ECC4:
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #2
	strneb r1, [r2, #0x1c4]
	ldr r0, [r0, #8]
	ldr r2, [r0, #0xc]
	cmp r2, #0
	beq _0202ED04
	ldr r1, [r2, #0x1a8]
	mvn r0, #0
	orr r1, r1, #1
	str r1, [r2, #0x1a8]
	str r0, [r2, #0x1b4]
	mov r0, #0
	str r0, [r2, #0x1b0]
_0202ED04:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202ED0C: .word 0x00007FFF

	arm_func_start sub_0202ED10
sub_0202ED10: ; 0x0202ED10
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202EDC0
	ldr r2, [r4, #4]
	ldr r1, [r4, #8]
	ldr r3, [r4, #0xc]
	orr r1, r2, r1, lsl #5
	orr r1, r1, r3, lsl #10
	ldr r2, [r0, #8]
	mov r1, r1, lsl #0x10
	cmp r2, #0
	mov ip, r1, lsr #0x10
	ldr r1, [r4, #0x10]
	beq _0202EDC0
	ldr r3, [r2, #0xc]
	cmp r3, #0
	movne r2, #0
	strne r2, [r3, #0x1b0]
	ldr r2, [r0, #8]
	ldr r3, [r2, #0xc]
	cmp r3, #0
	beq _0202ED84
	add r2, r3, #0x100
	strh ip, [r2, #0xac]
	mov r2, #0
	str r2, [r3, #0x1b0]
	arm_func_end sub_0202ED10
_0202ED84:
	ldr r2, [r0, #8]
	ldr r3, [r2, #0xc]
	cmp r3, #0
	movne r2, #2
	strneb r2, [r3, #0x1c4]
	ldr r0, [r0, #8]
	ldr r3, [r0, #0xc]
	cmp r3, #0
	beq _0202EDC0
	ldr r2, [r3, #0x1a8]
	mov r0, #0
	orr r2, r2, #1
	str r2, [r3, #0x1a8]
	str r1, [r3, #0x1b4]
	str r0, [r3, #0x1b0]
_0202EDC0:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202EDC8
sub_0202EDC8: ; 0x0202EDC8
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r1, [r0, #0xc]
	cmpne r1, #0
	ldrne r0, [r1, #0x1a8]
	bicne r0, r0, #1
	strne r0, [r1, #0x1a8]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202EDC8

	arm_func_start sub_0202EDFC
sub_0202EDFC: ; 0x0202EDFC
	stmdb sp!, {r3, lr}
	ldr r0, _0202EE1C ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _0202EE14
	bl _ZN11CFieldScene12ov0_0212451CEv
	arm_func_end sub_0202EDFC
_0202EE14:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202EE1C: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202EE20
sub_0202EE20: ; 0x0202EE20
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #4]
	orrne r1, r1, #1
	strne r1, [r0, #4]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202EE20

	arm_func_start sub_0202EE44
sub_0202EE44: ; 0x0202EE44
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #4]
	bicne r1, r1, #1
	strne r1, [r0, #4]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202EE44

	arm_func_start sub_0202EE68
sub_0202EE68: ; 0x0202EE68
	stmdb sp!, {r3, r4, r5, lr}
	ldmia r0, {r0, r4, r5}
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202EE98
	mov r1, r5
	and r2, r4, #0xff
	bl _ZN6CActor12sub_020129F4Eih
	arm_func_end sub_0202EE68
_0202EE98:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202EEA0
sub_0202EEA0: ; 0x0202EEA0
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, [r0, #8]
	ldr r1, [r0, #0xc]
	ldr r4, [r0, #4]
	ldr r0, [r0]
	and r5, r2, #0xff
	and r6, r1, #0xff
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r1, [r0, #0xc]
	cmpne r1, #0
	beq _0202EEF8
	ldr r0, [r1, #0x1a8]
	cmp r4, #0
	orr r0, r0, #4
	str r0, [r1, #0x1a8]
	strb r5, [r1, #0x1d4]
	strb r6, [r1, #0x1d5]
	mvnle r4, #0
	str r4, [r1, #0x1cc]
	arm_func_end sub_0202EEA0
_0202EEF8:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_0202EF00
sub_0202EF00: ; 0x0202EF00
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r2, [r0, #0xc]
	cmpne r2, #0
	beq _0202EF40
	ldr r1, [r2, #0x1a8]
	mov r0, #0
	bic r1, r1, #4
	str r1, [r2, #0x1a8]
	strb r0, [r2, #0x1d4]
	strb r0, [r2, #0x1d5]
	str r0, [r2, #0x1cc]
	arm_func_end sub_0202EF00
_0202EF40:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0202EF48
sub_0202EF48: ; 0x0202EF48
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #4]
	orrne r1, r1, #0x100
	strne r1, [r0, #4]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202EF48

	arm_func_start sub_0202EF6C
sub_0202EF6C: ; 0x0202EF6C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #4]
	bicne r1, r1, #0x100
	strne r1, [r0, #4]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202EF6C

	arm_func_start sub_0202EF90
sub_0202EF90: ; 0x0202EF90
	stmdb sp!, {r3, r4, r5, lr}
	ldmia r0, {r0, r4, r5}
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202EFC4
	mov r2, r4, lsl #0x10
	mov r1, r5
	mov r2, r2, lsr #0x10
	bl _ZN6CActor12sub_02012AA8Eit
	arm_func_end sub_0202EF90
_0202EFC4:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_0202EFCC
sub_0202EFCC: ; 0x0202EFCC
	stmdb sp!, {r4, r5, r6, lr}
	ldr r2, [r0, #4]
	ldr r1, [r0, #8]
	ldr r3, [r0, #0xc]
	orr r1, r2, r1, lsl #5
	orr r1, r1, r3, lsl #10
	ldr r2, [r0, #0x10]
	ldr r6, [r0, #0x14]
	mov r1, r1, lsl #0x10
	ldr r0, [r0]
	mov r4, r1, lsr #0x10
	and r5, r2, #0xff
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202F028
	mov r1, r4
	mov r2, r5
	mov r3, r6
	bl _ZN15CFieldDrawActor12sub_0203EEA8Ethi
	arm_func_end sub_0202EFCC
_0202F028:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_0202F030
sub_0202F030: ; 0x0202F030
	stmdb sp!, {r4, lr}
	ldr r4, [r0, #4]
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r0, [r0, #8]
	cmpne r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202F060
	mov r1, r4
	bl _ZN15CFieldDrawActor12sub_0203EEECEi
	arm_func_end sub_0202F030
_0202F060:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202F068
sub_0202F068: ; 0x0202F068
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	movne r1, #0
	strne r1, [r0, #0x90]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202F068

	arm_func_start sub_0202F088
sub_0202F088: ; 0x0202F088
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	movne r1, #1
	strne r1, [r0, #0x90]
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202F088

	arm_func_start sub_0202F0A8
sub_0202F0A8: ; 0x0202F0A8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202F0DC
	ldr r3, [r4, #0xc]
	ldr r2, [r4, #0x10]
	ldmib r4, {r1, ip}
	strb r1, [r0, #0xbc]
	strb ip, [r0, #0xbd]
	strb r3, [r0, #0xbe]
	strb r2, [r0, #0xbf]
	arm_func_end sub_0202F0A8
_0202F0DC:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202F0E4
sub_0202F0E4: ; 0x0202F0E4
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #6
	bne _0202F130
	ldr r1, _0202F138 ; =_0208F304
	ldr r0, [r0, #0x200]
	ldr r2, [r1]
	mov r1, r0, lsl #0x10
	add r0, r2, #0x1000
	ldr r0, [r0, #0x434]
	mov r1, r1, lsr #0x10
	bl sub_020107A8
	cmp r0, #0
	ldrneb r0, [r0, #6]
	ldmneia sp!, {r3, pc}
	arm_func_end sub_0202F0E4
_0202F130:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F138: .word s_game

	arm_func_start sub_0202F13C
sub_0202F13C: ; 0x0202F13C
	stmdb sp!, {r3, lr}
	ldr r0, _0202F170 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x43c]
	bl sub_02010868
	ldr r0, _0202F170 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x444]
	bl sub_02010D04
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F170: .word s_game
	arm_func_end sub_0202F13C

	arm_func_start sub_0202F174
sub_0202F174: ; 0x0202F174
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _0202F1A8 ; =MAIN_BSS_020B26A0
	cmp r1, #0
	addeq r0, r0, #0x8000
	moveq r1, #0
	streqb r1, [r0, #0xb44]
	beq _0202F1A0
	add r0, r0, #0x344
	add r0, r0, #0x8800
	bl strcpy
	arm_func_end sub_0202F174
_0202F1A0:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F1A8: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202F1AC
sub_0202F1AC: ; 0x0202F1AC
	ldr r1, _0202F1BC ; =MAIN_BSS_020BA6A0
	mov r0, #0
	strb r0, [r1, #0xb44]
	bx lr
	.align 2, 0
_0202F1BC: .word MAIN_BSS_020BA6A0
	arm_func_end sub_0202F1AC

	arm_func_start sub_0202F1C0
sub_0202F1C0: ; 0x0202F1C0
	ldr r0, _0202F200 ; =_0208F304
	ldr r1, _0202F204 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	ldr r2, [r1]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x444]
	cmp r2, #0
	cmpne r1, #0
	beq _0202F1F8
	mov r0, #1
	strb r0, [r1, #0xc]
	ldr r0, [r2, #0xd0]
	orr r0, r0, #1
	str r0, [r2, #0xd0]
	arm_func_end sub_0202F1C0
_0202F1F8:
	mov r0, #0
	bx lr
	.align 2, 0
_0202F200: .word s_game
_0202F204: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202F208
sub_0202F208: ; 0x0202F208
	stmdb sp!, {r3, lr}
	ldr r1, _0202F238 ; =MAIN_BSS_0210CA40
	mov r3, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _0202F230
	mvn r2, #0
	ldr r1, [r3]
	mov r3, r2
	bl _ZN11CFieldScene12ov0_02122FECEmmm
	arm_func_end sub_0202F208
_0202F230:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F238: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202F23C
sub_0202F23C: ; 0x0202F23C
	stmdb sp!, {r3, lr}
	ldr r1, _0202F264 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_02010AB0
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F264: .word s_game
	arm_func_end sub_0202F23C

	arm_func_start sub_0202F268
sub_0202F268: ; 0x0202F268
	stmdb sp!, {r3, lr}
	ldr r1, _0202F290 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_02010A70
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F290: .word s_game
	arm_func_end sub_0202F268

	arm_func_start sub_0202F294
sub_0202F294: ; 0x0202F294
	mov r0, #0
	bx lr
	arm_func_end sub_0202F294

	arm_func_start sub_0202F29C
sub_0202F29C: ; 0x0202F29C
	mov r0, #0
	bx lr
	arm_func_end sub_0202F29C

	arm_func_start sub_0202F2A4
sub_0202F2A4: ; 0x0202F2A4
	mov r0, #0
	bx lr
	arm_func_end sub_0202F2A4

	arm_func_start sub_0202F2AC
sub_0202F2AC: ; 0x0202F2AC
	mov r0, #0
	bx lr
	arm_func_end sub_0202F2AC

	arm_func_start sub_0202F2B4
sub_0202F2B4: ; 0x0202F2B4
	ldr r0, _0202F2D4 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x444]
	cmp r0, #0
	ldrne r0, [r0, #8]
	moveq r0, #0
	bx lr
	.align 2, 0
_0202F2D4: .word s_game
	arm_func_end sub_0202F2B4

	arm_func_start sub_0202F2D8
sub_0202F2D8: ; 0x0202F2D8
	stmdb sp!, {r3, lr}
	ldr r0, _0202F2FC ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x43c]
	bl sub_02010AD8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F2FC: .word s_game
	arm_func_end sub_0202F2D8

	arm_func_start sub_0202F300
sub_0202F300: ; 0x0202F300
	ldr r0, _0202F340 ; =_0208F304
	ldr r1, _0202F344 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	ldr r2, [r1]
	add r0, r0, #0x1000
	ldr r1, [r0, #0x444]
	cmp r2, #0
	cmpne r1, #0
	beq _0202F338
	mov r0, #1
	strb r0, [r1, #0xc]
	ldr r0, [r2, #0xd0]
	orr r0, r0, #1
	str r0, [r2, #0xd0]
	arm_func_end sub_0202F300
_0202F338:
	mov r0, #0
	bx lr
	.align 2, 0
_0202F340: .word s_game
_0202F344: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202F348
sub_0202F348: ; 0x0202F348
	stmdb sp!, {r3, lr}
	ldr r1, _0202F370 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_02010B08
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F370: .word s_game
	arm_func_end sub_0202F348

	arm_func_start sub_0202F374
sub_0202F374: ; 0x0202F374
	stmdb sp!, {r3, lr}
	ldr r1, _0202F39C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_02010A98
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F39C: .word s_game
	arm_func_end sub_0202F374

	arm_func_start sub_0202F3A0
sub_0202F3A0: ; 0x0202F3A0
	stmdb sp!, {r3, lr}
	ldr r1, _0202F3C8 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_02010AA0
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F3C8: .word s_game
	arm_func_end sub_0202F3A0

	arm_func_start sub_0202F3CC
sub_0202F3CC: ; 0x0202F3CC
	stmdb sp!, {r3, lr}
	ldr r1, _0202F3F4 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_02010AA8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F3F4: .word s_game
	arm_func_end sub_0202F3CC

	arm_func_start sub_0202F3F8
sub_0202F3F8: ; 0x0202F3F8
	stmdb sp!, {r3, lr}
	ldr r1, _0202F420 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_0201095C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F420: .word s_game
	arm_func_end sub_0202F3F8

	arm_func_start sub_0202F424
sub_0202F424: ; 0x0202F424
	stmdb sp!, {r3, lr}
	ldr r1, _0202F454 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x43c]
	mov r1, r1, lsr #0x10
	mov r2, #1
	bl sub_02010990
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F454: .word s_game
	arm_func_end sub_0202F424

	arm_func_start sub_0202F458
sub_0202F458: ; 0x0202F458
	stmdb sp!, {r4, lr}
	ldr r1, _0202F4B8 ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	ldmia r4, {r1, r2}
	add r0, r0, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x43c]
	mov r1, r1, lsr #0x10
	and r2, r2, #0xff
	bl sub_020109C0
	ldr r1, _0202F4B8 ; =_0208F304
	mov r0, #0
	ldr r1, [r1]
	add r1, r1, #0x1000
	ldr r3, [r1, #0x444]
	ldrb r2, [r3, #0x14]
	add r1, r2, #1
	strb r1, [r3, #0x14]
	add r2, r3, r2, lsl #2
	str r0, [r2, #0x18]
	ldr r1, [r4]
	str r1, [r2, #0x38]
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202F4B8: .word s_game
	arm_func_end sub_0202F458

	arm_func_start sub_0202F4BC
sub_0202F4BC: ; 0x0202F4BC
	stmdb sp!, {r3, lr}
	ldr r1, _0202F4E4 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	and r1, r1, #0xff
	bl sub_02010B10
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F4E4: .word s_game
	arm_func_end sub_0202F4BC

	arm_func_start sub_0202F4E8
sub_0202F4E8: ; 0x0202F4E8
	stmdb sp!, {r3, lr}
	ldr r0, _0202F50C ; =_0208F304
	mov r1, #1
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x43c]
	bl sub_02010AEC
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F50C: .word s_game
	arm_func_end sub_0202F4E8

	arm_func_start sub_0202F510
sub_0202F510: ; 0x0202F510
	stmdb sp!, {r3, lr}
	ldr r0, _0202F524 ; =MAIN_BSS_020B26A0
	bl sub_020172D4
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202F524: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202F510

	arm_func_start sub_0202F528
sub_0202F528: ; 0x0202F528
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x18
	ldr r4, _0202F750 ; =MAIN_BSS_020B26A0
	mov r0, r4
	bl sub_02017520
	ldr r0, _0202F754 ; =MAIN_BSS_0210CA4C
	ldr r8, [r0]
	cmp r8, #0
	beq _0202F6F4
	mov r0, r8
	ldr r1, [r0]
	ldr r1, [r1, #0x18]
	blx r1
	add r0, r4, #0x2d4
	add r7, r0, #0x8800
	mov r5, #0
	mov fp, #1
	arm_func_end sub_0202F528
_0202F56C:
	cmp r5, #0
	blt _0202F580
	cmp r5, #2
	movlt r6, r7
	blt _0202F584
_0202F580:
	mov r6, #0
_0202F584:
	cmp r6, #0
	ldrne r0, [r6]
	cmpne r0, #0
	beq _0202F670
	str fp, [sp]
	str fp, [sp, #4]
	ldrh r2, [r6, #8]
	ldr r1, [r6, #4]
	ldr r3, _0202F758 ; =0x00001E16
	mov r0, r8
	bl _ZN19CFieldPartnerManage12ov0_02139920Emttii
	cmp r0, #0
	blt _0202F670
	ldr r1, [r8, #4]
	cmp r1, r0
	ldrgt r1, [r8, #8]
	movle sl, #0
	ldrgt sl, [r1, r0, lsl #2]
	cmp sl, #0
	beq _0202F670
	ldr r0, [r6, #0x10]
	ldr sb, [sl, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #0x14]
	cmp sb, #0
	ldrne r0, [sb, #0xc]
	str r1, [sp, #0x10]
	cmpne r0, #0
	beq _0202F630
	add r1, sp, #0x10
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [sb, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	beq _0202F630
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	str r1, [sp, #8]
	str r1, [r2, #0x18]
	str r0, [sp, #0xc]
	str r0, [r2, #0x1c]
_0202F630:
	ldr r0, [sl, #8]
	ldrh r1, [r6, #0xa]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202F64C
	bl _ZN6CActor12sub_020128ECEt
_0202F64C:
	ldr r0, [sl, #8]
	cmp r0, #0
	ldrne r0, [r0, #0xc]
	cmpne r0, #0
	beq _0202F664
	bl _ZN6CActor12sub_0201287CEv
_0202F664:
	mov r0, sl
	add r1, r6, #0x14
	bl ov0_0213E158
_0202F670:
	add r5, r5, #1
	cmp r5, #2
	add r7, r7, #0x38
	blt _0202F56C
	mov r7, #0
	ldr sb, _0202F75C ; =0x00000FFF
	mov r6, r7
	mov r5, #1
	mov sl, #0xe
_0202F694:
	mov r0, r4
	mov r1, r7
	bl sub_020155FC
	cmp r0, #0
	beq _0202F6E8
	ldr r1, [r0, #8]
	tst r1, #1
	beq _0202F6E8
	str r6, [sp]
	str r5, [sp, #4]
	ldrh r1, [r0, #2]
	ldrh r3, [r0, #4]
	ldrh r2, [r0]
	mov r0, r1, lsl #0x14
	mov r0, r0, lsr #8
	and fp, r3, sb
	orr r1, r0, #0x6000000
	mov r0, r8
	mov r3, sl
	orr r1, fp, r1
	bl _ZN19CFieldPartnerManage12ov0_02139920Emttii
_0202F6E8:
	add r7, r7, #1
	cmp r7, #0xa
	blt _0202F694
_0202F6F4:
	ldr r0, _0202F760 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	ldrne r5, [r0, #0xd8]
	cmpne r5, #0
	beq _0202F734
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	mov r0, r5
	bl sub_0201A000
	ldr r0, [r4, #4]
	ldrb r2, [r4, #8]
	mov r1, r0, lsl #4
	mov r0, r5
	mov r1, r1, lsr #0x10
	bl sub_0201A220
_0202F734:
	bl sub_020233A4
	cmp r0, #0
	beq _0202F744
	bl sub_02022B20
_0202F744:
	mov r0, #0
	add sp, sp, #0x18
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202F750: .word MAIN_BSS_020B26A0
_0202F754: .word MAIN_BSS_0210CA4C
_0202F758: .word 0x00001E16
_0202F75C: .word 0x00000FFF
_0202F760: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202F764
sub_0202F764: ; 0x0202F764
	ldr r0, _0202F77C ; =_0208F304
	ldr ip, _0202F780 ; =sub_0203437C
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	bx ip
	.align 2, 0
_0202F77C: .word s_game
_0202F780: .word sub_0203437C
	arm_func_end sub_0202F764

	arm_func_start sub_0202F784
sub_0202F784: ; 0x0202F784
	mov r0, #0
	bx lr
	arm_func_end sub_0202F784

	arm_func_start sub_0202F78C
sub_0202F78C: ; 0x0202F78C
	mov r0, #0
	bx lr
	arm_func_end sub_0202F78C

	arm_func_start sub_0202F794
sub_0202F794: ; 0x0202F794
	mov r0, #0
	bx lr
	arm_func_end sub_0202F794

	arm_func_start sub_0202F79C
sub_0202F79C: ; 0x0202F79C
	mov r0, #0
	bx lr
	arm_func_end sub_0202F79C

	arm_func_start sub_0202F7A4
sub_0202F7A4: ; 0x0202F7A4
	mov r0, #0
	bx lr
	arm_func_end sub_0202F7A4

	arm_func_start sub_0202F7AC
sub_0202F7AC: ; 0x0202F7AC
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x38
	ldr r2, _0202F974 ; =MAIN_BSS_0210CA40
	ldr r3, [r2]
	cmp r3, #0
	ldrne r2, [r3, #0xd0]
	orrne r2, r2, #0x200000
	strne r2, [r3, #0xd0]
	bl sub_0202F764
	cmp r0, #0
	beq _0202F95C
	bl sub_0202BCD4
	ldr r8, _0202F978 ; =MAIN_BSS_020B26A0
	cmp r0, #0
	cmpne r8, #0
	beq _0202F95C
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0202F838
	ldr r1, [r1, #0xc]
	cmp r1, #0
	beq _0202F818
	ldr r2, [r1, #0x20]
	ldr r1, [r1, #0x24]
	str r2, [sp, #0x28]
	str r1, [sp, #0x2c]
	b _0202F830
	arm_func_end sub_0202F7AC
_0202F818:
	mov r1, #0
	add r2, sp, #0x20
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
_0202F830:
	add r3, sp, #0x28
	b _0202F854
_0202F838:
	mov r1, #0
	add r2, sp, #0x18
	add r3, sp, #0x28
	str r1, [r2]
	str r1, [r2, #4]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
_0202F854:
	ldr r1, [r3, #4]
	ldr r7, [r3]
	add r6, r1, #0x2c000
	ldr r1, _0202F97C ; =MAIN_BSS_0210CA4C
	ldr r3, [r0, #0x14]
	ldr sl, [r1]
	mov r2, r7, asr #0xc
	mov r1, r6, asr #0xc
	mov r0, #0x4000
	str r7, [sp, #0x30]
	str r6, [sp, #0x34]
	str r7, [sp, #0x10]
	str r6, [sp, #0x14]
	strh r2, [r8, #0x1c]
	strh r1, [r8, #0x1e]
	strh r0, [r8, #0x24]
	strh r3, [r8, #0x26]
	cmp sl, #0
	beq _0202F95C
	ldr r1, [sl, #4]
	mov sb, #0
	cmp r1, #0
	ble _0202F95C
	mov r0, r3, lsl #0x10
	mov fp, #0x4000
	mov r5, r0, lsr #0x10
	mov r4, fp
_0202F8C0:
	cmp r1, sb
	movle r0, #0
	ldrgt r0, [sl, #8]
	ldrgt r0, [r0, sb, lsl #2]
	cmp r0, #0
	beq _0202F94C
	ldr r1, [r0, #0x58]
	mov r0, r1, asr #0x18
	and r0, r0, #0xff
	cmp r0, #5
	beq _0202F8F8
	cmp r0, #6
	beq _0202F924
	b _0202F94C
_0202F8F8:
	mov r0, r8
	bl sub_0201549C
	cmp r0, #0
	beq _0202F94C
	str r7, [r0, #0xc]
	str r6, [r0, #0x10]
	strh r5, [r0, #0x34]
	str r7, [sp, #8]
	str r6, [sp, #0xc]
	strh r4, [r0, #0xa]
	b _0202F94C
_0202F924:
	mov r0, r8
	bl sub_02015520
	cmp r0, #0
	beq _0202F94C
	str r7, [r0, #0xc]
	str r6, [r0, #0x10]
	strh r5, [r0, #0x16]
	str r7, [sp]
	str r6, [sp, #4]
	strh fp, [r0, #0x14]
_0202F94C:
	ldr r1, [sl, #4]
	add sb, sb, #1
	cmp sb, r1
	blt _0202F8C0
_0202F95C:
	bl sub_02027754
	bl sub_0202779C
	bl sub_02027A2C
	mov r0, #0
	add sp, sp, #0x38
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202F974: .word MAIN_BSS_0210CA40
_0202F978: .word MAIN_BSS_020B26A0
_0202F97C: .word MAIN_BSS_0210CA4C

	arm_func_start sub_0202F980
sub_0202F980: ; 0x0202F980
	stmdb sp!, {r3, r4, r5, lr}
	bl sub_0202779C
	cmp r0, #0
	mov r4, #0
	beq _0202F9EC
	bl sub_0202779C
	bl sub_0202780C
	movs r4, r0
	bne _0202F9EC
	ldr r0, _0202F9F4 ; =MAIN_BSS_0210C1BC
	ldr r5, [r0]
	cmp r5, #0
	beq _0202F9D4
	beq _0202F9C8
	mov r0, r5
	bl sub_020277AC
	mov r0, r5
	bl _ZdlPv
	arm_func_end sub_0202F980
_0202F9C8:
	ldr r0, _0202F9F4 ; =MAIN_BSS_0210C1BC
	mov r1, #0
	str r1, [r0]
_0202F9D4:
	ldr r0, _0202F9F8 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	bicne r0, r0, #0x200000
	strne r0, [r1, #0xd0]
_0202F9EC:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202F9F4: .word MAIN_BSS_0210C1BC
_0202F9F8: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202F9FC
sub_0202F9FC: ; 0x0202F9FC
	stmdb sp!, {r3, lr}
	ldr r1, _0202FA20 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x49c]
	bl sub_0203421C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202FA20: .word s_game
	arm_func_end sub_0202F9FC

	arm_func_start sub_0202FA24
sub_0202FA24: ; 0x0202FA24
	ldr r0, _0202FA3C ; =MAIN_BSS_0210CA70
	ldr r0, [r0]
	cmp r0, #0
	ldrneh r0, [r0, #4]
	ldreq r0, _0202FA40 ; =0x0000FFFF
	bx lr
	.align 2, 0
_0202FA3C: .word MAIN_BSS_0210CA70
_0202FA40: .word 0x0000FFFF
	arm_func_end sub_0202FA24

	arm_func_start sub_0202FA44
sub_0202FA44: ; 0x0202FA44
	ldr r0, _0202FA50 ; =MAIN_BSS_020B26A0
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0202FA50: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202FA44

	arm_func_start sub_0202FA54
sub_0202FA54: ; 0x0202FA54
	ldr r0, _0202FA64 ; =MAIN_BSS_020B26A0
	ldrb r0, [r0, #3]
	and r0, r0, #0xf
	bx lr
	.align 2, 0
_0202FA64: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202FA54

	arm_func_start sub_0202FA68
sub_0202FA68: ; 0x0202FA68
	ldr r0, _0202FA7C ; =MAIN_BSS_020B26A0
	ldrb r0, [r0, #3]
	mov r0, r0, asr #4
	and r0, r0, #0xf
	bx lr
	.align 2, 0
_0202FA7C: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202FA68

	arm_func_start sub_0202FA80
sub_0202FA80: ; 0x0202FA80
	stmdb sp!, {r4, lr}
	ldr r1, _0202FB2C ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	mov r1, #0x1e
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B9CEi
	ldr r0, _0202FB2C ; =_0208F304
	mov r1, #0x1e
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C2CEi
	ldr r1, [r4, #4]
	ldr r0, _0202FB30 ; =MAIN_BSS_020B26A0
	cmp r1, #0
	addeq r0, r0, #0x8000
	moveq r1, #0
	streqb r1, [r0, #0xb44]
	beq _0202FAE0
	add r0, r0, #0x344
	add r0, r0, #0x8800
	bl strcpy
	arm_func_end sub_0202FA80
_0202FAE0:
	ldr r2, _0202FB2C ; =_0208F304
	mov r3, #1
	ldr r0, [r2]
	ldr r1, _0202FB34 ; =MAIN_BSS_0210CA40
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	str r3, [r0, #0x18]
	ldr r0, [r2]
	ldr r2, [r4]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	str r2, [r0, #0x10]
	ldr r1, [r1]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x20
	strne r0, [r1, #0xd0]
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202FB2C: .word s_game
_0202FB30: .word MAIN_BSS_020B26A0
_0202FB34: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202FB38
sub_0202FB38: ; 0x0202FB38
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x28
	ldr r4, _0202FC6C ; =MAIN_BSS_020B26A0
	ldr r0, [r0]
	ldrb r1, [r4]
	and r0, r0, #0xff
	and r0, r0, #1
	strb r0, [r4]
	cmp r0, r1
	ldrne r0, _0202FC70 ; =MAIN_BSS_0210CA48
	ldrne r5, [r0]
	cmpne r5, #0
	beq _0202FC60
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0202FBB8
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202FB98
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	b _0202FBB0
	arm_func_end sub_0202FB38
_0202FB98:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_0202FBB0:
	add r3, sp, #0x18
	b _0202FBD4
_0202FBB8:
	mov r0, #0
	add r1, sp, #8
	add r3, sp, #0x18
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_0202FBD4:
	ldrb r1, [r4, #3]
	ldr lr, [r3]
	ldr ip, [r3, #4]
	add r0, r4, #0x8000
	mov r1, r1, asr #4
	and r2, r1, #0xf
	ldrb r3, [r0, #0xb64]
	ldrb r1, [r4]
	mov r0, r5
	str lr, [sp, #0x20]
	str ip, [sp, #0x24]
	bl _ZN12CFieldPlayer12ov0_02132F14Ehih
	add r0, r4, #0x8000
	ldrb r1, [r0, #0x802]
	mov r0, r5
	bl _ZN12CFieldPlayer12ov0_02132FA0Eh
	ldr r4, [r5, #8]
	cmp r4, #0
	ldrne r0, [r4, #0xc]
	cmpne r0, #0
	beq _0202FC60
	add r1, sp, #0x20
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [r4, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	beq _0202FC60
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0x24]
	str r1, [r2, #0x18]
	str r1, [sp]
	str r0, [sp, #4]
	str r0, [r2, #0x1c]
_0202FC60:
	mov r0, #0
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202FC6C: .word MAIN_BSS_020B26A0
_0202FC70: .word MAIN_BSS_0210CA48

	arm_func_start sub_0202FC74
sub_0202FC74: ; 0x0202FC74
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, _0202FCD0 ; =MAIN_BSS_020B26A0
	mov r1, #0xff
	bl sub_02015658
	mov r4, r0
	ldr r0, _0202FCD0 ; =MAIN_BSS_020B26A0
	ldr r1, [r5]
	ldrb r3, [r0, #3]
	and r2, r1, #0xff
	mov r1, #0xff
	and r3, r3, #0xf0
	orr r2, r3, r2
	strb r2, [r0, #3]
	bl sub_02015658
	cmp r4, r0
	beq _0202FCC8
	bl sub_020233A4
	cmp r0, #0
	beq _0202FCC8
	bl sub_02022B20
	arm_func_end sub_0202FC74
_0202FCC8:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202FCD0: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202FCD4
sub_0202FCD4: ; 0x0202FCD4
	stmdb sp!, {r3, r4, r5, lr}
	sub sp, sp, #0x28
	ldr r4, _0202FE20 ; =MAIN_BSS_020B26A0
	ldr r0, [r0]
	ldrb r3, [r4, #3]
	and r0, r0, #0xff
	and r1, r3, #0xf
	orr r2, r1, r0, lsl #4
	and r0, r2, #0xff
	mov r1, r0, asr #4
	mov r0, r3, asr #4
	and r1, r1, #0xf
	and r0, r0, #0xf
	cmp r1, r0
	ldrne r0, _0202FE24 ; =MAIN_BSS_0210CA48
	strb r2, [r4, #3]
	ldrne r5, [r0]
	cmpne r5, #0
	beq _0202FE14
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0202FD6C
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0202FD4C
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	b _0202FD64
	arm_func_end sub_0202FCD4
_0202FD4C:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_0202FD64:
	add r3, sp, #0x18
	b _0202FD88
_0202FD6C:
	mov r0, #0
	add r1, sp, #8
	add r3, sp, #0x18
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_0202FD88:
	ldrb r1, [r4, #3]
	ldr lr, [r3]
	ldr ip, [r3, #4]
	add r0, r4, #0x8000
	mov r1, r1, asr #4
	and r2, r1, #0xf
	ldrb r3, [r0, #0xb64]
	ldrb r1, [r4]
	mov r0, r5
	str lr, [sp, #0x20]
	str ip, [sp, #0x24]
	bl _ZN12CFieldPlayer12ov0_02132F14Ehih
	add r0, r4, #0x8000
	ldrb r1, [r0, #0x802]
	mov r0, r5
	bl _ZN12CFieldPlayer12ov0_02132FA0Eh
	ldr r4, [r5, #8]
	cmp r4, #0
	ldrne r0, [r4, #0xc]
	cmpne r0, #0
	beq _0202FE14
	add r1, sp, #0x20
	add r0, r0, #0xc
	ldmia r1, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [r4, #0xc]
	ldr r2, [r0, #0xc4]
	cmp r2, #0
	beq _0202FE14
	ldr r1, [sp, #0x20]
	ldr r0, [sp, #0x24]
	str r1, [r2, #0x18]
	str r1, [sp]
	str r0, [sp, #4]
	str r0, [r2, #0x1c]
_0202FE14:
	mov r0, #0
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_0202FE20: .word MAIN_BSS_020B26A0
_0202FE24: .word MAIN_BSS_0210CA48

	arm_func_start sub_0202FE28
sub_0202FE28: ; 0x0202FE28
	mov r0, #0
	bx lr
	arm_func_end sub_0202FE28

	arm_func_start sub_0202FE30
sub_0202FE30: ; 0x0202FE30
	stmdb sp!, {r4, lr}
	ldr r0, [r0]
	ldr r4, _0202FE9C ; =MAIN_BSS_020B26A0
	and r1, r0, #0xff
	mov r0, r4
	bl sub_020160B8
	ldr r0, _0202FEA0 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _0202FE94
	ldr r0, [r0, #0xd8]
	ldrb r2, [r4, #2]
	cmp r0, #0
	ldrb r1, [r4, #1]
	beq _0202FE94
	cmp r2, #0
	mov r1, r1, lsl #0x10
	bne _0202FE84
	mov r1, r1, lsr #0x10
	bl sub_0201A018
	b _0202FE94
	arm_func_end sub_0202FE30
_0202FE84:
	mov r2, r2, lsl #0x10
	mov r1, r1, lsr #0x10
	mov r2, r2, lsr #0x10
	bl sub_0201A000
_0202FE94:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0202FE9C: .word MAIN_BSS_020B26A0
_0202FEA0: .word MAIN_BSS_0210CA40

	arm_func_start sub_0202FEA4
sub_0202FEA4: ; 0x0202FEA4
	ldr r0, _0202FEBC ; =MAIN_BSS_020B26A0
	cmp r0, #0
	addne r0, r0, #0x8000
	ldrneb r0, [r0, #0x7db]
	moveq r0, #0
	bx lr
	.align 2, 0
_0202FEBC: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202FEA4

	arm_func_start sub_0202FEC0
sub_0202FEC0: ; 0x0202FEC0
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _0202FF00 ; =MAIN_BSS_0210CA40
	ldr r2, _0202FF04 ; =MAIN_BSS_020B26A0
	cmp r1, #0
	ldreqb r1, [r2, #2]
	ldr r0, [r0]
	strb r1, [r2, #1]
	cmp r0, #0
	beq _0202FEF8
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0xd8]
	mov r1, r1, lsr #0x10
	bl sub_0201A018
	arm_func_end sub_0202FEC0
_0202FEF8:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202FF00: .word MAIN_BSS_0210CA40
_0202FF04: .word MAIN_BSS_020B26A0

	arm_func_start sub_0202FF08
sub_0202FF08: ; 0x0202FF08
	ldr r0, _0202FF1C ; =MAIN_BSS_020B26A0
	cmp r0, #0
	ldrneb r0, [r0, #2]
	moveq r0, #0
	bx lr
	.align 2, 0
_0202FF1C: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202FF08

	arm_func_start sub_0202FF20
sub_0202FF20: ; 0x0202FF20
	ldr r0, _0202FF34 ; =MAIN_BSS_020B26A0
	cmp r0, #0
	ldrneb r0, [r0, #1]
	moveq r0, #0
	bx lr
	.align 2, 0
_0202FF34: .word MAIN_BSS_020B26A0
	arm_func_end sub_0202FF20

	arm_func_start sub_0202FF38
sub_0202FF38: ; 0x0202FF38
	stmdb sp!, {r3, lr}
	bl _Z12sub_020010E4v
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0202FF38

	arm_func_start sub_0202FF48
sub_0202FF48: ; 0x0202FF48
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _0202FFD8
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	beq _0202FF7C
	cmp r1, #6
	beq _0202FFAC
	b _0202FFD8
	arm_func_end sub_0202FF48
_0202FF7C:
	ldr r1, _0202FFE0 ; =_0208F304
	ldr r0, [r0, #0xe8]
	ldr r2, [r1]
	mov r1, r0, lsl #0x10
	add r0, r2, #0x1000
	ldr r0, [r0, #0x434]
	mov r1, r1, lsr #0x10
	bl sub_020107A8
	cmp r0, #0
	beq _0202FFD8
	ldrh r0, [r0]
	ldmia sp!, {r3, pc}
_0202FFAC:
	ldr r1, _0202FFE0 ; =_0208F304
	ldr r0, [r0, #0x200]
	ldr r2, [r1]
	mov r1, r0, lsl #0x10
	add r0, r2, #0x1000
	ldr r0, [r0, #0x434]
	mov r1, r1, lsr #0x10
	bl sub_020107A8
	cmp r0, #0
	ldrneh r0, [r0]
	ldmneia sp!, {r3, pc}
_0202FFD8:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0202FFE0: .word s_game

	arm_func_start sub_0202FFE4
sub_0202FFE4: ; 0x0202FFE4
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	ldr r1, _0203003C ; =MAIN_BSS_0210CA6C
	cmp r0, #0
	ldr r1, [r1]
	cmpne r1, #0
	beq _02030034
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #1
	beq _02030024
	cmp r1, #6
	beq _0203002C
	b _02030034
	arm_func_end sub_0202FFE4
_02030024:
	ldr r0, [r0, #0xe8]
	ldmia sp!, {r3, pc}
_0203002C:
	ldr r0, [r0, #0x200]
	ldmia sp!, {r3, pc}
_02030034:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203003C: .word MAIN_BSS_0210CA6C

	arm_func_start sub_02030040
sub_02030040: ; 0x02030040
	stmdb sp!, {r3, lr}
	ldr r1, _02030064 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x49c]
	bl sub_02034374
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030064: .word s_game
	arm_func_end sub_02030040

	arm_func_start sub_02030068
sub_02030068: ; 0x02030068
	ldr r0, _02030090 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a4]
	add r0, r0, #0x8000
	ldrb r0, [r0, #0x802]
	cmp r0, #1
	movls r0, #0
	subhi r0, r0, #1
	bx lr
	.align 2, 0
_02030090: .word s_game
	arm_func_end sub_02030068

	arm_func_start sub_02030094
sub_02030094: ; 0x02030094
	ldr r0, _020300B4 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x2000
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_020300B4: .word MAIN_BSS_0210CA40
	arm_func_end sub_02030094

	arm_func_start sub_020300B8
sub_020300B8: ; 0x020300B8
	stmdb sp!, {r3, lr}
	ldr r1, _020300F8 ; =_0208F304
	ldr r2, [r0]
	ldr r1, [r1]
	add r0, r1, #0x1000
	ldr r0, [r0, #0x4b4]
	mov r1, #3
	bl sub_0201926C
	ldr r0, _020300F8 ; =_0208F304
	mov r1, #3
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AB28El
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020300F8: .word s_game
	arm_func_end sub_020300B8

	arm_func_start sub_020300FC
sub_020300FC: ; 0x020300FC
	ldr r0, _0203011C ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x800
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_0203011C: .word MAIN_BSS_0210CA40
	arm_func_end sub_020300FC

	arm_func_start sub_02030120
sub_02030120: ; 0x02030120
	ldr r0, _02030140 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	bicne r0, r0, #0x800
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_02030140: .word MAIN_BSS_0210CA40
	arm_func_end sub_02030120

	arm_func_start sub_02030144
sub_02030144: ; 0x02030144
	ldr r0, _02030164 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x1000
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_02030164: .word MAIN_BSS_0210CA40
	arm_func_end sub_02030144

	arm_func_start sub_02030168
sub_02030168: ; 0x02030168
	ldr r0, _02030188 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	bicne r0, r0, #0x1000
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_02030188: .word MAIN_BSS_0210CA40
	arm_func_end sub_02030168

	arm_func_start sub_0203018C
sub_0203018C: ; 0x0203018C
	ldr r0, _020301AC ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x4000
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_020301AC: .word MAIN_BSS_0210CA40
	arm_func_end sub_0203018C

	arm_func_start sub_020301B0
sub_020301B0: ; 0x020301B0
	ldr r0, _020301D0 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x8000
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_020301D0: .word MAIN_BSS_0210CA40
	arm_func_end sub_020301B0

	arm_func_start sub_020301D4
sub_020301D4: ; 0x020301D4
	ldr r1, _02030204 ; =MAIN_BSS_0210CA40
	ldr r2, [r0]
	ldr r1, [r1]
	cmp r1, #0
	beq _020301FC
	ldr r0, _02030208 ; =MAIN_BSS_0210CAB0
	str r2, [r0]
	ldr r0, [r1, #0xd0]
	orr r0, r0, #0x10000
	str r0, [r1, #0xd0]
	arm_func_end sub_020301D4
_020301FC:
	mov r0, #0
	bx lr
	.align 2, 0
_02030204: .word MAIN_BSS_0210CA40
_02030208: .word MAIN_BSS_0210CAB0

	arm_func_start sub_0203020C
sub_0203020C: ; 0x0203020C
	ldr r0, _0203022C ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x20000
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_0203022C: .word MAIN_BSS_0210CA40
	arm_func_end sub_0203020C

	arm_func_start sub_02030230
sub_02030230: ; 0x02030230
	stmdb sp!, {r4, lr}
	ldr r1, _02030318 ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	mov r1, #0x1e
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B9CEi
	ldr r0, _02030318 ; =_0208F304
	mov r1, #0x1e
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C2CEi
	ldr r0, _02030318 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E30
	ldr r0, _02030318 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E94
	ldr r0, _02030318 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_0201164C
	ldr r1, [r4]
	mov r0, #0x1c
	mul r0, r1, r0
	ldr r1, _0203031C ; =s_c000First_0208ac1c
	ldr r2, _02030320 ; =MAIN_BSS_020B26A0
	adds r1, r1, r0
	addeq r0, r2, #0x8000
	moveq r1, #0
	streqb r1, [r0, #0xb44]
	beq _020302E0
	add r0, r2, #0x344
	add r0, r0, #0x8800
	bl strcpy
	arm_func_end sub_02030230
_020302E0:
	ldr r0, _02030318 ; =_0208F304
	mov r2, #1
	ldr r0, [r0]
	ldr r1, _02030324 ; =MAIN_BSS_0210CA40
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	str r2, [r0, #0x18]
	ldr r1, [r1]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x40000
	strne r0, [r1, #0xd0]
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02030318: .word s_game
_0203031C: .word s_c000First_0208ac1c
_02030320: .word MAIN_BSS_020B26A0
_02030324: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030328
sub_02030328: ; 0x02030328
	stmdb sp!, {r3, lr}
	ldr r0, _02030418 ; =_0208F304
	mov r1, #0x1e
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B9CEi
	ldr r0, _02030418 ; =_0208F304
	mov r1, #0x1e
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C2CEi
	ldr r0, _02030418 ; =_0208F304
	mov r1, #1
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F4CEi
	ldr r0, _02030418 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E30
	ldr r0, _02030418 ; =_0208F304
	mov r1, #4
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E94
	ldr r0, _02030418 ; =_0208F304
	mov r1, #4
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_0201164C
	ldr r1, _0203041C ; =s_c004First_0208ac8c
	ldr r0, _02030420 ; =MAIN_BSS_020B26A0
	cmp r1, #0
	addeq r0, r0, #0x8000
	moveq r1, #0
	streqb r1, [r0, #0xb44]
	beq _020303E0
	add r0, r0, #0x344
	add r0, r0, #0x8800
	bl strcpy
	arm_func_end sub_02030328
_020303E0:
	ldr r0, _02030418 ; =_0208F304
	mov r2, #1
	ldr r0, [r0]
	ldr r1, _02030424 ; =MAIN_BSS_0210CA40
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	str r2, [r0, #0x18]
	ldr r1, [r1]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x100000
	strne r0, [r1, #0xd0]
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030418: .word s_game
_0203041C: .word s_c004First_0208ac8c
_02030420: .word MAIN_BSS_020B26A0
_02030424: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030428
sub_02030428: ; 0x02030428
	ldr r0, _02030448 ; =MAIN_BSS_0210CA40
	ldr r1, [r0]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x80000
	strne r0, [r1, #0xd0]
	mov r0, #0
	bx lr
	.align 2, 0
_02030448: .word MAIN_BSS_0210CA40
	arm_func_end sub_02030428

	arm_func_start sub_0203044C
sub_0203044C: ; 0x0203044C
	ldr r0, _02030464 ; =MAIN_BSS_020B26A0
	cmp r0, #0
	addne r0, r0, #0x8000
	ldrne r0, [r0, #0x1ac]
	moveq r0, #0
	bx lr
	.align 2, 0
_02030464: .word MAIN_BSS_020B26A0
	arm_func_end sub_0203044C

	arm_func_start sub_02030468
sub_02030468: ; 0x02030468
	stmdb sp!, {r3, lr}
	ldr r0, _02030490 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02030488
	ldr r0, [r0, #0x60]
	mov r1, #0xc8
	bl sub_0202982C
	arm_func_end sub_02030468
_02030488:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030490: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030494
sub_02030494: ; 0x02030494
	stmdb sp!, {r3, lr}
	ldr r0, _020304C8 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _020304C0
	ldr r0, [r0, #0x60]
	bl sub_0202A1AC
	cmp r0, #8
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_02030494
_020304C0:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020304C8: .word MAIN_BSS_0210CA40

	arm_func_start sub_020304CC
sub_020304CC: ; 0x020304CC
	stmdb sp!, {r3, lr}
	ldr r0, _020304F0 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _020304E8
	ldr r0, [r0, #0x60]
	bl sub_0202A1B4
	arm_func_end sub_020304CC
_020304E8:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020304F0: .word MAIN_BSS_0210CA40

	arm_func_start sub_020304F4
sub_020304F4: ; 0x020304F4
	stmdb sp!, {r3, lr}
	ldr r0, _02030524 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _0203051C
	ldr r0, [r0, #0xd8]
	bl sub_0201A0F4
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, pc}
	arm_func_end sub_020304F4
_0203051C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030524: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030528
sub_02030528: ; 0x02030528
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020233A4
	cmp r0, #0
	beq _02030544
	ldr r1, [r4]
	bl sub_02022E48
	arm_func_end sub_02030528
_02030544:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203054C
sub_0203054C: ; 0x0203054C
	stmdb sp!, {r4, lr}
	bl sub_020233A4
	movs r4, r0
	beq _02030568
	bl sub_02022EC4
	mov r0, r4
	bl sub_02022DD4
	arm_func_end sub_0203054C
_02030568:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_02030570
sub_02030570: ; 0x02030570
	stmdb sp!, {r3, lr}
	bl sub_020233A4
	cmp r0, #0
	beq _02030594
	mov r1, #0x3e8
	rsb r1, r1, #0
	mov r2, r1
	mov r3, r1
	bl sub_020229F4
	arm_func_end sub_02030570
_02030594:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0203059C
sub_0203059C: ; 0x0203059C
	stmdb sp!, {r3, lr}
	ldr r0, _020305C0 ; =_0208F304
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020305C0: .word s_game
	arm_func_end sub_0203059C

	arm_func_start sub_020305C4
sub_020305C4: ; 0x020305C4
	stmdb sp!, {r3, lr}
	ldr r1, _020305EC ; =_0208F304
	ldr r3, [r1]
	ldmia r0, {r1, r2}
	ldr r0, [r3, #0x1c]
	mov r1, r1, lsl #0xc
	mov r2, r2, lsl #0xc
	bl _ZN11CTPEmulator12sub_0200215CEll
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020305EC: .word s_game
	arm_func_end sub_020305C4

	arm_func_start sub_020305F0
sub_020305F0: ; 0x020305F0
	stmdb sp!, {r3, lr}
	ldr r0, _0203060C ; =_0208F304
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	bl _ZN11CTPEmulator12sub_02002178Ev
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203060C: .word s_game
	arm_func_end sub_020305F0

	arm_func_start sub_02030610
sub_02030610: ; 0x02030610
	stmdb sp!, {r3, lr}
	ldr r1, _02030648 ; =_0208F304
	ldr r2, [r0, #4]
	ldr lr, [r1]
	ldr r1, [r0, #8]
	ldr ip, [r0]
	mov r3, r1, lsl #0x10
	ldr r0, [lr, #0x1c]
	mov r1, ip, lsl #0xc
	mov r2, r2, lsl #0xc
	mov r3, r3, lsr #0x10
	bl _ZN11CTPEmulator12sub_02002198Ellt
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030648: .word s_game
	arm_func_end sub_02030610

	arm_func_start sub_0203064C
sub_0203064C: ; 0x0203064C
	ldr r0, _02030660 ; =_0208F304
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	ldr r0, [r0, #0x30]
	bx lr
	.align 2, 0
_02030660: .word s_game
	arm_func_end sub_0203064C

	arm_func_start sub_02030664
sub_02030664: ; 0x02030664
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	cmp r0, #0
	bne _02030690
	ldr r0, _020306DC ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	bl _ZN5CGame12sub_02010178Ei
	ldr r0, _020306DC ; =_0208F304
	mov r2, #0
	b _020306A8
	arm_func_end sub_02030664
_02030690:
	ldr r0, _020306DC ; =_0208F304
	mov r1, #1
	ldr r0, [r0]
	bl _ZN5CGame12sub_02010178Ei
	ldr r0, _020306DC ; =_0208F304
	mov r2, #1
_020306A8:
	ldr r1, [r0]
	ldr r1, [r1, #0x14]
	strb r2, [r1, #0x2a]
	ldr r1, [r0]
	add r0, r1, #0x1000
	ldr r1, [r1, #0x20]
	ldr r0, [r0, #0x490]
	str r1, [r0, #0x8c]
	ldr r0, [r0, #0x14c]
	add r0, r0, #0x1000
	str r1, [r0, #0x618]
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020306DC: .word s_game

	arm_func_start sub_020306E0
sub_020306E0: ; 0x020306E0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020233A4
	cmp r0, #0
	beq _02030714
	ldr r1, [r4]
	cmp r1, #0
	bne _0203070C
	mov r1, #1
	bl sub_02023198
	b _02030714
	arm_func_end sub_020306E0
_0203070C:
	mov r1, #0
	bl sub_02023198
_02030714:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203071C
sub_0203071C: ; 0x0203071C
	stmdb sp!, {r4, lr}
	ldr r1, _02030750 ; =MAIN_BSS_0210CA40
	mov r2, r0
	ldr r4, [r1]
	cmp r4, #0
	beq _02030748
	ldr r0, [r4, #0x58]
	ldr r1, [r2]
	bl sub_0202350C
	ldr r0, [r4, #0x54]
	bl sub_02022C1C
	arm_func_end sub_0203071C
_02030748:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02030750: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030754
sub_02030754: ; 0x02030754
	stmdb sp!, {r4, lr}
	ldr r1, _020307DC ; =MAIN_BSS_0210CA40
	mov r3, #1
	ldr r2, [r1]
	ldr r1, _020307E0 ; =_0208F304
	ldr r2, [r2, #0x54]
	mov r4, r0
	str r3, [r2, #0x60]
	ldr r0, [r1]
	ldr r1, [r4]
	add r0, r0, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x4bc]
	mov r2, r1, lsr #0x10
	mov r1, #4
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, _020307E0 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E324Ev
	cmp r0, #4
	beq _020307D4
	ldr r0, _020307E0 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	mov r1, r1, lsl #0x10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, r1, lsr #0x10
	mov r1, #4
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	arm_func_end sub_02030754
_020307D4:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_020307DC: .word MAIN_BSS_0210CA40
_020307E0: .word s_game

	arm_func_start sub_020307E4
sub_020307E4: ; 0x020307E4
	stmdb sp!, {r4, lr}
	ldr r1, _02030850 ; =MAIN_BSS_0210CA40
	mov r3, #1
	ldr r2, [r1]
	ldr r1, _02030854 ; =_0208F304
	ldr r2, [r2, #0x54]
	mov r4, r0
	str r3, [r2, #0x60]
	ldr r0, [r1]
	ldr r1, [r4]
	add r0, r0, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x4bc]
	mov r2, r1, lsr #0x10
	mov r1, #2
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, _02030854 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	mov r1, r1, lsl #0x10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, r1, lsr #0x10
	mov r1, #2
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02030850: .word MAIN_BSS_0210CA40
_02030854: .word s_game
	arm_func_end sub_020307E4

	arm_func_start sub_02030858
sub_02030858: ; 0x02030858
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _020308F4 ; =MAIN_BSS_0210CA40
	mov r3, #1
	ldr r2, [r1]
	ldr r1, _020308F8 ; =_0208F304
	ldr r2, [r2, #0x54]
	mov r4, r0
	str r3, [r2, #0x60]
	ldr r0, [r1]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E324Ev
	cmp r0, #4
	beq _020308B8
	ldr r0, _020308F8 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	mov r1, r1, lsl #0x10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, r1, lsr #0x10
	mov r1, #4
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	arm_func_end sub_02030858
_020308B8:
	mov r0, #2
	str r0, [sp]
	ldr r0, _020308F8 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	mov r1, r1, lsl #0x10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c4]
	mov r3, r1, lsr #0x10
	mov r1, #0x7f
	mov r2, #0x5f
	bl _ZN17UnkClass_0200E33012sub_0200E378Eiitt
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_020308F4: .word MAIN_BSS_0210CA40
_020308F8: .word s_game

	arm_func_start sub_020308FC
sub_020308FC: ; 0x020308FC
	stmdb sp!, {r4, lr}
	ldr r1, _02030954 ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	ldr r1, [r4]
	add r0, r0, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x4bc]
	mov r2, r1, lsr #0x10
	mov r1, #3
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, _02030954 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	mov r1, r1, lsl #0x10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, r1, lsr #0x10
	mov r1, #3
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02030954: .word s_game
	arm_func_end sub_020308FC

	arm_func_start sub_02030958
sub_02030958: ; 0x02030958
	stmdb sp!, {r4, lr}
	ldr r1, _020309B0 ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	ldr r1, [r4]
	add r0, r0, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x4bc]
	mov r2, r1, lsr #0x10
	mov r1, #1
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	ldr r0, _020309B0 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	mov r1, r1, lsl #0x10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	mov r2, r1, lsr #0x10
	mov r1, #1
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_020309B0: .word s_game
	arm_func_end sub_02030958

	arm_func_start sub_020309B4
sub_020309B4: ; 0x020309B4
	stmdb sp!, {r3, r4, lr}
	sub sp, sp, #4
	ldr r1, _02030A3C ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	ldr r1, [r4]
	add r0, r0, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x4c0]
	mov r2, r1, lsr #0x10
	mov r1, #3
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #1
	str r0, [sp]
	ldr r0, _02030A3C ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	mov r1, r1, lsl #0x10
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c4]
	mov r3, r1, lsr #0x10
	mov r1, #0x7f
	mov r2, #0x5f
	bl _ZN17UnkClass_0200E33012sub_0200E378Eiitt
	ldr r0, _02030A3C ; =_0208F304
	mov r1, #3
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E0E0Ett
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, pc}
	.align 2, 0
_02030A3C: .word s_game
	arm_func_end sub_020309B4

	arm_func_start sub_02030A40
sub_02030A40: ; 0x02030A40
	stmdb sp!, {r3, lr}
	ldr r0, _02030ACC ; =_0208F304
	ldr r1, [r0]
	add r0, r1, #0x1000
	ldr r0, [r0, #0x4c4]
	ldrh r0, [r0]
	tst r0, #8
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	bne _02030ABC
	add r0, r1, #0x1000
	ldr r0, [r0, #0x4c8]
	ldrh r0, [r0]
	tst r0, #8
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	bne _02030ABC
	add r0, r1, #0x1000
	ldr r0, [r0, #0x4bc]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	bne _02030ABC
	ldr r0, _02030ACC ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4c0]
	bl _ZN17UnkClass_0200E0B412sub_0200E310Ev
	cmp r0, #0
	beq _02030AC4
	arm_func_end sub_02030A40
_02030ABC:
	mov r0, #1
	ldmia sp!, {r3, pc}
_02030AC4:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030ACC: .word s_game

	arm_func_start sub_02030AD0
sub_02030AD0: ; 0x02030AD0
	mov r0, #0
	bx lr
	arm_func_end sub_02030AD0

	arm_func_start sub_02030AD8
sub_02030AD8: ; 0x02030AD8
	stmdb sp!, {r3, lr}
	ldr r1, _02030B14 ; =MAIN_BSS_0210CA40
	ldr r2, [r1]
	cmp r2, #0
	mvnne r1, #0
	strne r1, [r2, #0x8c]
	ldr r1, _02030B18 ; =_0208F304
	ldr r0, [r0]
	ldr r2, [r1]
	mov r1, r0, lsl #0xc
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4b8]
	bl _ZN17UnkClass_0200D3F812sub_0200D8C8El
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030B14: .word MAIN_BSS_0210CA40
_02030B18: .word s_game
	arm_func_end sub_02030AD8

	arm_func_start sub_02030B1C
sub_02030B1C: ; 0x02030B1C
	stmdb sp!, {r3, lr}
	ldr r0, _02030B3C ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b8]
	bl _ZN17UnkClass_0200D3F812sub_0200D980Ev
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030B3C: .word s_game
	arm_func_end sub_02030B1C

	arm_func_start sub_02030B40
sub_02030B40: ; 0x02030B40
	stmdb sp!, {r4, lr}
	ldr r2, _02030BB4 ; =MAIN_BSS_0210CA40
	ldr r4, [r2]
	cmp r4, #0
	beq _02030BAC
	mov r2, #0
	mov r3, r2
	mov ip, r2
	cmp r1, #0
	sub lr, r2, #1
	ble _02030B90
	cmp r1, #1
	ldr r2, [r0]
	ble _02030B90
	cmp r1, #2
	ldr r3, [r0, #4]
	ble _02030B90
	cmp r1, #3
	ldr ip, [r0, #8]
	ldrgt lr, [r0, #0xc]
	arm_func_end sub_02030B40
_02030B90:
	ldr r0, [r4, #0xd0]
	orr r0, r0, #2
	str r0, [r4, #0xd0]
	str r2, [r4, #0x68]
	str r3, [r4, #0x6c]
	str ip, [r4, #0x70]
	str lr, [r4, #0x74]
_02030BAC:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02030BB4: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030BB8
sub_02030BB8: ; 0x02030BB8
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _02030BEC ; =MAIN_BSS_020B26A0
	cmp r1, #0
	addeq r0, r0, #0x8000
	moveq r1, #0
	streqb r1, [r0, #0xb44]
	beq _02030BE4
	add r0, r0, #0x344
	add r0, r0, #0x8800
	bl strcpy
	arm_func_end sub_02030BB8
_02030BE4:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030BEC: .word MAIN_BSS_020B26A0

	arm_func_start sub_02030BF0
sub_02030BF0: ; 0x02030BF0
	ldr r0, _02030C18 ; =MAIN_BSS_020BA6A0
	add r0, r0, #0xb00
	ldrsb r0, [r0, #0x44]
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	bx lr
	.align 2, 0
_02030C18: .word MAIN_BSS_020BA6A0
	arm_func_end sub_02030BF0

	arm_func_start sub_02030C1C
sub_02030C1C: ; 0x02030C1C
	stmdb sp!, {r4, r5, r6, lr}
	cmp r1, #1
	ldr r5, _02030C94 ; =MAIN_BSS_020B26A0
	blt _02030C8C
	ldr r1, _02030C98 ; =0x00000FFF
	ldr r2, [r0]
	add r0, r1, #0xff000
	and r6, r1, r2, asr #20
	and r4, r2, r0
	mov r0, r5
	mov r1, r4
	mov r2, r6
	bl sub_02015714
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bne _02030C8C
	ldr r0, _02030C9C ; =MAIN_BSS_0210CA58
	ldr r1, [r0]
	cmp r1, #0
	beq _02030C8C
	ldr r0, [r1]
	cmp r0, r4
	movlt r1, #0
	ldrge r0, [r1, #4]
	ldrge r1, [r0, r4, lsl #2]
	cmp r1, #0
	movne r0, #1
	strne r0, [r1, #0x18]
	arm_func_end sub_02030C1C
_02030C8C:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02030C94: .word MAIN_BSS_020B26A0
_02030C98: .word 0x00000FFF
_02030C9C: .word MAIN_BSS_0210CA58

	arm_func_start sub_02030CA0
sub_02030CA0: ; 0x02030CA0
	stmdb sp!, {r4, r5, r6, lr}
	cmp r1, #1
	ldr r5, _02030D18 ; =MAIN_BSS_020B26A0
	blt _02030D10
	ldr r1, _02030D1C ; =0x00000FFF
	ldr r2, [r0]
	add r0, r1, #0xff000
	and r6, r1, r2, asr #20
	and r4, r2, r0
	mov r0, r5
	mov r1, r4
	mov r2, r6
	bl sub_0201577C
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bne _02030D10
	ldr r0, _02030D20 ; =MAIN_BSS_0210CA58
	ldr r1, [r0]
	cmp r1, #0
	beq _02030D10
	ldr r0, [r1]
	cmp r0, r4
	movlt r1, #0
	ldrge r0, [r1, #4]
	ldrge r1, [r0, r4, lsl #2]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x18]
	arm_func_end sub_02030CA0
_02030D10:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02030D18: .word MAIN_BSS_020B26A0
_02030D1C: .word 0x00000FFF
_02030D20: .word MAIN_BSS_0210CA58

	arm_func_start sub_02030D24
sub_02030D24: ; 0x02030D24
	stmdb sp!, {r4, r5, r6, lr}
	cmp r1, #2
	ldr r5, _02030D9C ; =MAIN_BSS_020B26A0
	blt _02030D94
	ldr r1, _02030DA0 ; =0x00000FFF
	ldr r2, [r0, #4]
	add r0, r1, #0xff000
	and r6, r1, r2, asr #20
	and r4, r2, r0
	mov r0, r5
	mov r1, r4
	mov r2, r6
	bl sub_02015714
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bne _02030D94
	ldr r0, _02030DA4 ; =MAIN_BSS_0210CA58
	ldr r1, [r0]
	cmp r1, #0
	beq _02030D94
	ldr r0, [r1]
	cmp r0, r4
	movlt r1, #0
	ldrge r0, [r1, #4]
	ldrge r1, [r0, r4, lsl #2]
	cmp r1, #0
	movne r0, #1
	strne r0, [r1, #0x18]
	arm_func_end sub_02030D24
_02030D94:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02030D9C: .word MAIN_BSS_020B26A0
_02030DA0: .word 0x00000FFF
_02030DA4: .word MAIN_BSS_0210CA58

	arm_func_start sub_02030DA8
sub_02030DA8: ; 0x02030DA8
	stmdb sp!, {r4, r5, r6, lr}
	cmp r1, #2
	ldr r5, _02030E20 ; =MAIN_BSS_020B26A0
	blt _02030E18
	ldr r1, _02030E24 ; =0x00000FFF
	ldr r2, [r0, #4]
	add r0, r1, #0xff000
	and r6, r1, r2, asr #20
	and r4, r2, r0
	mov r0, r5
	mov r1, r4
	mov r2, r6
	bl sub_0201577C
	ldrh r0, [r5, #0x1a]
	cmp r6, r0
	bne _02030E18
	ldr r0, _02030E28 ; =MAIN_BSS_0210CA58
	ldr r1, [r0]
	cmp r1, #0
	beq _02030E18
	ldr r0, [r1]
	cmp r0, r4
	movlt r1, #0
	ldrge r0, [r1, #4]
	ldrge r1, [r0, r4, lsl #2]
	cmp r1, #0
	movne r0, #0
	strne r0, [r1, #0x18]
	arm_func_end sub_02030DA8
_02030E18:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02030E20: .word MAIN_BSS_020B26A0
_02030E24: .word 0x00000FFF
_02030E28: .word MAIN_BSS_0210CA58

	arm_func_start sub_02030E2C
sub_02030E2C: ; 0x02030E2C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl ov0_02161FD4
	mov r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_02030E2C

	arm_func_start sub_02030E40
sub_02030E40: ; 0x02030E40
	stmdb sp!, {r3, r4, r5, r6, r7, r8, lr}
	sub sp, sp, #4
	ldr r1, _02030E8C ; =MAIN_BSS_0210CA78
	ldmia r0, {r4, r5, r6, r7}
	ldr r8, [r1]
	cmp r8, #0
	beq _02030E80
	mov r0, r8
	mov r1, r4
	bl sub_02035CA4
	mov r0, r8
	mov r1, r4
	mov r2, r5
	mov r3, r6
	str r7, [sp]
	bl sub_02035DA0
	arm_func_end sub_02030E40
_02030E80:
	mov r0, #0
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, r7, r8, pc}
	.align 2, 0
_02030E8C: .word MAIN_BSS_0210CA78

	arm_func_start sub_02030E90
sub_02030E90: ; 0x02030E90
	stmdb sp!, {r3, lr}
	ldr r3, _02030EB4 ; =MAIN_BSS_0210CA78
	ldmia r0, {r1, r2}
	ldr r0, [r3]
	cmp r0, #0
	beq _02030EAC
	bl sub_02035E3C
	arm_func_end sub_02030E90
_02030EAC:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030EB4: .word MAIN_BSS_0210CA78

	arm_func_start sub_02030EB8
sub_02030EB8: ; 0x02030EB8
	stmdb sp!, {r3, lr}
	ldr r2, _02030EDC ; =MAIN_BSS_0210CA78
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl sub_02035ECC
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030EDC: .word MAIN_BSS_0210CA78
	arm_func_end sub_02030EB8

	arm_func_start sub_02030EE0
sub_02030EE0: ; 0x02030EE0
	stmdb sp!, {r3, lr}
	ldr r3, _02030F04 ; =MAIN_BSS_0210CA78
	ldmia r0, {r1, r2}
	ldr r0, [r3]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl sub_02035F50
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030F04: .word MAIN_BSS_0210CA78
	arm_func_end sub_02030EE0

	arm_func_start sub_02030F08
sub_02030F08: ; 0x02030F08
	stmdb sp!, {r3, lr}
	ldr r1, _02030F34 ; =MAIN_BSS_0210CA40
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02030F2C
	ldmia r2, {r1, r2}
	and r1, r1, #0xff
	bl _ZN11CFieldScene12ov0_02124588Eii
	arm_func_end sub_02030F08
_02030F2C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030F34: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030F38
sub_02030F38: ; 0x02030F38
	stmdb sp!, {r3, lr}
	ldr r1, _02030F64 ; =MAIN_BSS_0210CA40
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02030F5C
	ldr r1, [r2]
	and r1, r1, #0xff
	bl _ZN11CFieldScene12ov0_021245C4Ei
	arm_func_end sub_02030F38
_02030F5C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030F64: .word MAIN_BSS_0210CA40

	arm_func_start sub_02030F68
sub_02030F68: ; 0x02030F68
	stmdb sp!, {r3, lr}
	ldr r0, _02030F88 ; =MAIN_BSS_0210CA7C
	ldr r0, [r0]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN24CFieldTargetObjectManage12ov0_0213D564Ev
	ldmia sp!, {r3, pc}
	.align 2, 0
_02030F88: .word MAIN_BSS_0210CA7C
	arm_func_end sub_02030F68

	arm_func_start sub_02030F8C
sub_02030F8C: ; 0x02030F8C
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	ldr r1, _02031074 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_020113B4
	ldr r0, _02031074 ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B9CEi
	ldr r0, _02031074 ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C2CEi
	ldr r0, _02031074 ; =_0208F304
	mov r1, #0x28
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _02031074 ; =_0208F304
	mov r1, #0x12
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	ldr r0, _02031074 ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA04El
	ldr r0, _02031074 ; =_0208F304
	mov r1, #0xb4
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA48El
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	ldr r0, _02031074 ; =_0208F304
	str r1, [sp, #4]
	ldr r0, [r0]
	mov r2, #2
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031074: .word s_game
	arm_func_end sub_02030F8C

	arm_func_start sub_02031078
sub_02031078: ; 0x02031078
	stmdb sp!, {r4, lr}
	ldr r0, _0203116C ; =MAIN_BSS_0210CA78
	mov r4, #0
	ldr r0, [r0]
	cmp r0, #0
	beq _020310E8
	mov r1, #9
	bl sub_02035ECC
	ldr r1, _02031170 ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	mov r1, #0x18
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02019278
	cmp r0, #0
	ldr r0, _02031174 ; =MAIN_BSS_0210CA6C
	moveq r4, #0
	ldr r0, [r0]
	cmp r0, #0
	beq _020310E8
	ldr r1, _02031178 ; =MAIN_BSS_020B26A0
	ldrh r1, [r1, #0x1a]
	bl sub_02041D80
	ldrb r0, [r0]
	sub r0, r0, #0x26
	cmp r0, #1
	movls r4, #0
	arm_func_end sub_02031078
_020310E8:
	cmp r4, #0
	beq _02031128
	ldr r0, _02031170 ; =_0208F304
	mov r1, #0xb1
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _02031170 ; =_0208F304
	mov r1, #0x1a
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	b _02031164
_02031128:
	ldr r1, _02031170 ; =_0208F304
	ldr r0, _02031178 ; =MAIN_BSS_020B26A0
	ldr r2, [r1]
	ldrh r1, [r0, #0x1a]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	mov r2, #0x3c
	mov r3, #1
	bl _ZN17UnkClass_0203447812sub_020346CCEmii
	ldr r0, _02031170 ; =_0208F304
	mov r1, #0x100
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F20Ei
_02031164:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203116C: .word MAIN_BSS_0210CA78
_02031170: .word s_game
_02031174: .word MAIN_BSS_0210CA6C
_02031178: .word MAIN_BSS_020B26A0

	arm_func_start sub_0203117C
sub_0203117C: ; 0x0203117C
	stmdb sp!, {r3, lr}
	ldr r1, _02031200 ; =MAIN_BSS_0210CA40
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _020311A0
	ldr r0, [r0, #0x60]
	ldr r1, [r2]
	bl sub_0202982C
	arm_func_end sub_0203117C
_020311A0:
	mov r1, #1
	ldr r0, _02031204 ; =0x04000050
	sub r2, r1, #9
	bl G2x_SetBlendBrightness_
	ldr r0, _02031208 ; =_0208F304
	mov r1, #0x29
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _02031208 ; =_0208F304
	mov r1, #6
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	ldr r0, _02031208 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_0201140C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031200: .word MAIN_BSS_0210CA40
_02031204: .word 0x04000050
_02031208: .word s_game

	arm_func_start sub_0203120C
sub_0203120C: ; 0x0203120C
	stmdb sp!, {r3, lr}
	ldr r0, _02031240 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02031238
	ldr r0, [r0, #0x60]
	bl sub_0202A1AC
	cmp r0, #2
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0203120C
_02031238:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031240: .word MAIN_BSS_0210CA40

	arm_func_start sub_02031244
sub_02031244: ; 0x02031244
	stmdb sp!, {r3, lr}
	ldr r0, _020312B4 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02031260
	ldr r0, [r0, #0x60]
	bl sub_0202A1B4
	arm_func_end sub_02031244
_02031260:
	ldr r0, _020312B8 ; =0x04000050
	mov r1, #1
	mov r2, #0
	bl G2x_SetBlendBrightness_
	ldr r1, _020312BC ; =_0208F304
	ldr r0, _020312C0 ; =MAIN_BSS_020B26A0
	ldr r2, [r1]
	ldrh r1, [r0, #0x1a]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x48c]
	mov r2, #0x3c
	mov r3, #0
	bl _ZN17UnkClass_0203447812sub_020346CCEmii
	ldr r0, _020312BC ; =_0208F304
	mov r1, #0x100
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F20Ei
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020312B4: .word MAIN_BSS_0210CA40
_020312B8: .word 0x04000050
_020312BC: .word s_game
_020312C0: .word MAIN_BSS_020B26A0

	arm_func_start sub_020312C4
sub_020312C4: ; 0x020312C4
	stmdb sp!, {r3, lr}
	ldr r0, _02031334 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _020312E4
	ldr r0, [r0, #0x60]
	mov r1, #0x64
	bl sub_0202982C
	arm_func_end sub_020312C4
_020312E4:
	ldr r0, _02031338 ; =_0208F304
	mov r1, #0x2a
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _02031338 ; =_0208F304
	mov r1, #7
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	ldr r0, _02031338 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_02011464
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031334: .word MAIN_BSS_0210CA40
_02031338: .word s_game

	arm_func_start sub_0203133C
sub_0203133C: ; 0x0203133C
	stmdb sp!, {r3, lr}
	ldr r0, _02031370 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02031368
	ldr r0, [r0, #0x60]
	bl sub_0202A1AC
	cmp r0, #9
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0203133C
_02031368:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031370: .word MAIN_BSS_0210CA40

	arm_func_start sub_02031374
sub_02031374: ; 0x02031374
	stmdb sp!, {r3, lr}
	ldr r0, _020313E4 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02031390
	ldr r0, [r0, #0x60]
	bl sub_0202A1B4
	arm_func_end sub_02031374
_02031390:
	mov r0, #0
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #8]
	cmpne r1, #0
	beq _020313DC
	ldr r1, [r0, #4]
	tst r1, #8
	bne _020313DC
	orr r1, r1, #8
	str r1, [r0, #4]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1dc]
	strneb r1, [r2, #0x1e1]
	mov r1, #0
	str r1, [r0, #0x94]
_020313DC:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020313E4: .word MAIN_BSS_0210CA40

	arm_func_start sub_020313E8
sub_020313E8: ; 0x020313E8
	ldr r0, _02031400 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	ldrb r0, [r0, #2]
	bx lr
	.align 2, 0
_02031400: .word s_game
	arm_func_end sub_020313E8

	arm_func_start sub_02031404
sub_02031404: ; 0x02031404
	stmdb sp!, {r3, lr}
	ldr r0, _02031424 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_0201140C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031424: .word s_game
	arm_func_end sub_02031404

	arm_func_start sub_02031428
sub_02031428: ; 0x02031428
	stmdb sp!, {r3, lr}
	ldr r1, _0203144C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_020113B4
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203144C: .word s_game
	arm_func_end sub_02031428

	arm_func_start sub_02031450
sub_02031450: ; 0x02031450
	stmdb sp!, {r3, lr}
	ldr r0, _02031470 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_02011464
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031470: .word s_game
	arm_func_end sub_02031450

	arm_func_start sub_02031474
sub_02031474: ; 0x02031474
	stmdb sp!, {r3, lr}
	sub sp, sp, #8
	ldr r1, _02031570 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_02011540
	ldr r0, _02031570 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E5C
	ldr r0, _02031570 ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B9CEi
	ldr r0, _02031570 ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C2CEi
	ldr r0, _02031570 ; =_0208F304
	mov r1, #0x28
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _02031570 ; =_0208F304
	mov r1, #0x12
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	ldr r0, _02031570 ; =_0208F304
	mov r1, #0
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA04El
	ldr r0, _02031570 ; =_0208F304
	mov r1, #0xb4
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA48El
	mov r3, #1
	str r3, [sp]
	mov r1, #0
	ldr r0, _02031570 ; =_0208F304
	str r1, [sp, #4]
	ldr r0, [r0]
	mov r2, #0x1c
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA84Emmmmm
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031570: .word s_game
	arm_func_end sub_02031474

	arm_func_start sub_02031574
sub_02031574: ; 0x02031574
	stmdb sp!, {r3, lr}
	ldr r0, _020315D0 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02031594
	ldr r0, [r0, #0x60]
	mov r1, #0x65
	bl sub_0202982C
	arm_func_end sub_02031574
_02031594:
	ldr r0, _020315D4 ; =_0208F304
	mov r1, #0x2a
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _020315D4 ; =_0208F304
	mov r1, #7
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020315D0: .word MAIN_BSS_0210CA40
_020315D4: .word s_game

	arm_func_start sub_020315D8
sub_020315D8: ; 0x020315D8
	stmdb sp!, {r3, lr}
	ldr r0, _0203160C ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02031604
	ldr r0, [r0, #0x60]
	bl sub_0202A1AC
	cmp r0, #9
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_020315D8
_02031604:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203160C: .word MAIN_BSS_0210CA40

	arm_func_start sub_02031610
sub_02031610: ; 0x02031610
	stmdb sp!, {r3, lr}
	ldr r0, _02031680 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _0203162C
	ldr r0, [r0, #0x60]
	bl sub_0202A1B4
	arm_func_end sub_02031610
_0203162C:
	mov r0, #0
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #8]
	cmpne r1, #0
	beq _02031678
	ldr r1, [r0, #4]
	tst r1, #8
	bne _02031678
	orr r1, r1, #8
	str r1, [r0, #4]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1dc]
	strneb r1, [r2, #0x1e1]
	mov r1, #0
	str r1, [r0, #0x94]
_02031678:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031680: .word MAIN_BSS_0210CA40

	arm_func_start sub_02031684
sub_02031684: ; 0x02031684
	stmdb sp!, {r3, lr}
	ldr r0, _020316A4 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_020115A8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020316A4: .word s_game
	arm_func_end sub_02031684

	arm_func_start sub_020316A8
sub_020316A8: ; 0x020316A8
	ldr r1, _020316C4 ; =_0208F304
	ldr ip, _020316C8 ; =sub_02011630
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bx ip
	.align 2, 0
_020316C4: .word s_game
_020316C8: .word sub_02011630
	arm_func_end sub_020316A8

	arm_func_start sub_020316CC
sub_020316CC: ; 0x020316CC
	ldr r0, _020316E4 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	ldrb r0, [r0, #3]
	bx lr
	.align 2, 0
_020316E4: .word s_game
	arm_func_end sub_020316CC

	arm_func_start sub_020316E8
sub_020316E8: ; 0x020316E8
	stmdb sp!, {r3, lr}
	ldr r0, _02031708 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_020115F8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031708: .word s_game
	arm_func_end sub_020316E8

	arm_func_start sub_0203170C
sub_0203170C: ; 0x0203170C
	stmdb sp!, {r3, lr}
	ldr r1, _02031730 ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_020114C4
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031730: .word s_game
	arm_func_end sub_0203170C

	arm_func_start sub_02031734
sub_02031734: ; 0x02031734
	ldr r1, _02031750 ; =_0208F304
	ldr ip, _02031754 ; =sub_020114F8
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bx ip
	.align 2, 0
_02031750: .word s_game
_02031754: .word sub_020114F8
	arm_func_end sub_02031734

	arm_func_start sub_02031758
sub_02031758: ; 0x02031758
	stmdb sp!, {r3, lr}
	ldr r1, _0203177C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_02011514
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203177C: .word s_game
	arm_func_end sub_02031758

	arm_func_start sub_02031780
sub_02031780: ; 0x02031780
	ldr r1, _0203179C ; =_0208F304
	ldr ip, _020317A0 ; =sub_02011528
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bx ip
	.align 2, 0
_0203179C: .word s_game
_020317A0: .word sub_02011528
	arm_func_end sub_02031780

	arm_func_start sub_020317A4
sub_020317A4: ; 0x020317A4
	stmdb sp!, {r3, lr}
	ldr r0, _02031800 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _020317C4
	ldr r0, [r0, #0x60]
	mov r1, #0x66
	bl sub_0202982C
	arm_func_end sub_020317A4
_020317C4:
	ldr r0, _02031804 ; =_0208F304
	mov r1, #0x32
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_0203499CEi
	ldr r0, _02031804 ; =_0208F304
	mov r1, #0x34
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034A40Eii
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031800: .word MAIN_BSS_0210CA40
_02031804: .word s_game

	arm_func_start sub_02031808
sub_02031808: ; 0x02031808
	stmdb sp!, {r3, lr}
	ldr r0, _0203183C ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _02031834
	ldr r0, [r0, #0x60]
	bl sub_0202A1AC
	cmp r0, #9
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_02031808
_02031834:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203183C: .word MAIN_BSS_0210CA40

	arm_func_start sub_02031840
sub_02031840: ; 0x02031840
	stmdb sp!, {r3, lr}
	ldr r0, _020318B0 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	beq _0203185C
	ldr r0, [r0, #0x60]
	bl sub_0202A1B4
	arm_func_end sub_02031840
_0203185C:
	mov r0, #0
	bl sub_0202BCD4
	cmp r0, #0
	ldrne r1, [r0, #8]
	cmpne r1, #0
	beq _020318A8
	ldr r1, [r0, #4]
	tst r1, #8
	bne _020318A8
	orr r1, r1, #8
	str r1, [r0, #4]
	ldr r1, [r0, #8]
	ldr r2, [r1, #0xc]
	cmp r2, #0
	movne r1, #0
	strne r1, [r2, #0x1dc]
	strneb r1, [r2, #0x1e1]
	mov r1, #0
	str r1, [r0, #0x94]
_020318A8:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020318B0: .word MAIN_BSS_0210CA40

	arm_func_start sub_020318B4
sub_020318B4: ; 0x020318B4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4]
	mov r0, #0x1c
	mul r0, r1, r0
	ldr r1, _020319A8 ; =s_c000First_0208ac1c
	ldr r2, _020319AC ; =MAIN_BSS_020B26A0
	adds r1, r1, r0
	addeq r0, r2, #0x8000
	moveq r1, #0
	streqb r1, [r0, #0xb44]
	beq _020318F0
	add r0, r2, #0x344
	add r0, r0, #0x8800
	bl strcpy
	arm_func_end sub_020318B4
_020318F0:
	ldr r0, _020319B0 ; =_0208F304
	mov r2, #1
	ldr r0, [r0]
	ldr r1, _020319B4 ; =MAIN_BSS_0210CA40
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	str r2, [r0, #0x18]
	ldr r0, [r1]
	cmp r0, #0
	beq _0203195C
	ldr r2, [r4]
	mov r1, #0x1c
	mul r3, r2, r1
	ldr r2, [r0, #0xd0]
	ldr r1, _020319B8 ; =DAT_0208ac2c
	orr r2, r2, #2
	str r2, [r0, #0xd0]
	ldr r2, [r1, r3]
	ldr r1, _020319BC ; =DAT_0208ac30
	str r2, [r0, #0x68]
	ldr r2, [r1, r3]
	ldr r1, _020319C0 ; =DAT_0208ac34
	str r2, [r0, #0x6c]
	ldr r2, [r1, r3]
	mov r1, #0
	str r2, [r0, #0x70]
	str r1, [r0, #0x74]
_0203195C:
	ldr r0, _020319B0 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E30
	ldr r0, _020319B0 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E94
	ldr r0, _020319B0 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_0201164C
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_020319A8: .word s_c000First_0208ac1c
_020319AC: .word MAIN_BSS_020B26A0
_020319B0: .word s_game
_020319B4: .word MAIN_BSS_0210CA40
_020319B8: .word DAT_0208ac2c
_020319BC: .word DAT_0208ac30
_020319C0: .word DAT_0208ac34

	arm_func_start sub_020319C4
sub_020319C4: ; 0x020319C4
	mov r0, #0
	bx lr
	arm_func_end sub_020319C4

	arm_func_start sub_020319CC
sub_020319CC: ; 0x020319CC
	ldr r0, _020319E4 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	ldr r0, [r0, #8]
	bx lr
	.align 2, 0
_020319E4: .word s_game
	arm_func_end sub_020319CC

	arm_func_start sub_020319E8
sub_020319E8: ; 0x020319E8
	stmdb sp!, {r4, lr}
	ldr r1, _02031B28 ; =_0208F304
	mov r4, r0
	ldr r0, [r1]
	mov r1, #0x1e
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B9CEi
	ldr r0, _02031B28 ; =_0208F304
	mov r1, #0x1e
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034C2CEi
	ldr r0, _02031B28 ; =_0208F304
	mov r1, #1
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034F4CEi
	ldr r2, _02031B2C ; =MAIN_BSS_020B26A0
	ldr r0, _02031B30 ; =MAIN_BSS_0210CA40
	ldrb r1, [r2, #2]
	ldr r0, [r0]
	strb r1, [r2, #1]
	cmp r0, #0
	beq _02031A64
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0xd8]
	mov r1, r1, lsr #0x10
	bl sub_0201A018
	arm_func_end sub_020319E8
_02031A64:
	ldr r0, _02031B28 ; =_0208F304
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E30
	ldr r0, _02031B28 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E94
	ldr r0, _02031B28 ; =_0208F304
	ldr r1, [r4]
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_0201164C
	ldr r1, [r4]
	mov r0, #0x1c
	mul r0, r1, r0
	ldr r1, _02031B34 ; =s_c000First_0208ac1c
	ldr r2, _02031B2C ; =MAIN_BSS_020B26A0
	adds r1, r1, r0
	addeq r0, r2, #0x8000
	moveq r1, #0
	streqb r1, [r0, #0xb44]
	beq _02031ADC
	add r0, r2, #0x344
	add r0, r0, #0x8800
	bl strcpy
_02031ADC:
	ldr r2, _02031B28 ; =_0208F304
	mov r3, #1
	ldr r0, [r2]
	ldr r1, _02031B30 ; =MAIN_BSS_0210CA40
	add r0, r0, #0x1000
	ldr r0, [r0, #0x49c]
	str r3, [r0, #0x18]
	ldr r0, [r2]
	add r0, r0, #0x1000
	ldr r2, [r0, #0x4a0]
	ldr r0, [r2, #8]
	str r0, [r2, #0x10]
	ldr r1, [r1]
	cmp r1, #0
	ldrne r0, [r1, #0xd0]
	orrne r0, r0, #0x20
	strne r0, [r1, #0xd0]
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02031B28: .word s_game
_02031B2C: .word MAIN_BSS_020B26A0
_02031B30: .word MAIN_BSS_0210CA40
_02031B34: .word s_c000First_0208ac1c

	arm_func_start sub_02031B38
sub_02031B38: ; 0x02031B38
	stmdb sp!, {r3, lr}
	ldr r1, _02031B5C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4a0]
	bl sub_020116A8
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031B5C: .word s_game
	arm_func_end sub_02031B38

	arm_func_start sub_02031B60
sub_02031B60: ; 0x02031B60
	ldr r1, _02031B7C ; =_0208F304
	ldr ip, _02031B80 ; =sub_02018E54
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4b4]
	bx ip
	.align 2, 0
_02031B7C: .word s_game
_02031B80: .word sub_02018E54
	arm_func_end sub_02031B60

	arm_func_start sub_02031B84
sub_02031B84: ; 0x02031B84
	stmdb sp!, {r3, lr}
	ldr r1, _02031BAC ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	ldmia r2, {r1, r2}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E4C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031BAC: .word s_game
	arm_func_end sub_02031B84

	arm_func_start sub_02031BB0
sub_02031BB0: ; 0x02031BB0
	ldr r1, _02031BCC ; =_0208F304
	ldr ip, _02031BD0 ; =sub_02019278
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4b4]
	bx ip
	.align 2, 0
_02031BCC: .word s_game
_02031BD0: .word sub_02019278
	arm_func_end sub_02031BB0

	arm_func_start sub_02031BD4
sub_02031BD4: ; 0x02031BD4
	stmdb sp!, {r3, lr}
	ldr r1, _02031BFC ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	ldmia r2, {r1, r2}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_0201926C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031BFC: .word s_game
	arm_func_end sub_02031BD4

	arm_func_start sub_02031C00
sub_02031C00: ; 0x02031C00
	ldr r1, _02031C1C ; =_0208F304
	ldr ip, _02031C20 ; =sub_02018E88
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x4b4]
	bx ip
	.align 2, 0
_02031C1C: .word s_game
_02031C20: .word sub_02018E88
	arm_func_end sub_02031C00

	arm_func_start sub_02031C24
sub_02031C24: ; 0x02031C24
	stmdb sp!, {r3, lr}
	ldr r1, _02031C4C ; =_0208F304
	mov r2, r0
	ldr r0, [r1]
	ldmia r2, {r1, r2}
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02018E7C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031C4C: .word s_game
	arm_func_end sub_02031C24

	arm_func_start sub_02031C50
sub_02031C50: ; 0x02031C50
	stmdb sp!, {r3, lr}
	ldr r0, _02031CB0 ; =MAIN_BSS_0210CA4C
	ldr ip, [r0]
	cmp ip, #0
	beq _02031CA8
	ldr r2, [ip, #4]
	mov r3, #0
	cmp r2, #0
	ble _02031CA8
	mov r1, r3
	arm_func_end sub_02031C50
_02031C78:
	ldr r0, [ip, #4]
	cmp r0, r3
	ldrgt r0, [ip, #8]
	movle lr, r1
	ldrgt lr, [r0, r3, lsl #2]
	add r3, r3, #1
	cmp lr, #0
	ldrne r0, [lr, #4]
	orrne r0, r0, #1
	strne r0, [lr, #4]
	cmp r3, r2
	blt _02031C78
_02031CA8:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031CB0: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031CB4
sub_02031CB4: ; 0x02031CB4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x28
	ldr r0, _02031DF8 ; =MAIN_BSS_0210CA4C
	ldr r8, [r0]
	cmp r8, #0
	beq _02031DEC
	ldr r0, _02031DFC ; =MAIN_BSS_0210CA48
	ldr r6, [r8, #4]
	ldr r0, [r0]
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _02031D24
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02031D04
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x24]
	str r1, [sp, #0x18]
	str r0, [sp, #0x1c]
	b _02031D1C
	arm_func_end sub_02031CB4
_02031D04:
	mov r0, #0
	add r1, sp, #0x10
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_02031D1C:
	add r2, sp, #0x18
	b _02031D40
_02031D24:
	mov r0, #0
	add r1, sp, #8
	add r2, sp, #0x18
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
_02031D40:
	ldr r5, [r2]
	ldr r4, [r2, #4]
	str r5, [sp, #0x20]
	str r4, [sp, #0x24]
	cmp r6, #0
	add fp, sp, #0x20
	mov r7, #0
	ble _02031DEC
_02031D60:
	ldr r0, [r8, #4]
	cmp r0, r7
	ldrgt r0, [r8, #8]
	movle sl, #0
	ldrgt sl, [r0, r7, lsl #2]
	cmp sl, #0
	beq _02031DE0
	ldr r0, [sl, #4]
	tst r0, #1
	movne r0, #1
	moveq r0, #0
	cmp r0, #0
	beq _02031DE0
	ldr sb, [sl, #8]
	cmp sb, #0
	ldrne r0, [sb, #0xc]
	cmpne r0, #0
	beq _02031DD4
	add r0, r0, #0xc
	ldmia fp, {r1, r2}
	bl _ZN17UnkClass_0201179C12sub_02011D3CE7Point2D
	ldr r0, [sb, #0xc]
	ldr r0, [r0, #0xc4]
	cmp r0, #0
	beq _02031DD4
	str r5, [r0, #0x18]
	str r5, [sp]
	str r4, [sp, #4]
	str r4, [r0, #0x1c]
_02031DD4:
	ldr r0, [sl, #4]
	bic r0, r0, #1
	str r0, [sl, #4]
_02031DE0:
	add r7, r7, #1
	cmp r7, r6
	blt _02031D60
_02031DEC:
	mov r0, #0
	add sp, sp, #0x28
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02031DF8: .word MAIN_BSS_0210CA4C
_02031DFC: .word MAIN_BSS_0210CA48

	arm_func_start sub_02031E00
sub_02031E00: ; 0x02031E00
	stmdb sp!, {r3, lr}
	ldr r1, _02031E2C ; =MAIN_BSS_0210CA4C
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r0, #0
	beq _02031E24
	mov r1, #1
	mov r3, r1
	bl _ZN19CFieldPartnerManage12ov0_0213A96CEimi
	arm_func_end sub_02031E00
_02031E24:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031E2C: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031E30
sub_02031E30: ; 0x02031E30
	stmdb sp!, {r3, lr}
	ldr r0, _02031E50 ; =MAIN_BSS_0210CA4C
	ldr r0, [r0]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN19CFieldPartnerManage12ov0_0213B048Ev
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031E50: .word MAIN_BSS_0210CA4C
	arm_func_end sub_02031E30

	arm_func_start sub_02031E54
sub_02031E54: ; 0x02031E54
	stmdb sp!, {r3, lr}
	ldr r0, _02031E74 ; =MAIN_BSS_0210CA4C
	ldr r0, [r0]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN19CFieldPartnerManage12ov0_0213B0F0Ev
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031E74: .word MAIN_BSS_0210CA4C
	arm_func_end sub_02031E54

	arm_func_start sub_02031E78
sub_02031E78: ; 0x02031E78
	stmdb sp!, {r3, lr}
	ldr r1, _02031EA4 ; =MAIN_BSS_0210CA4C
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r0, #0
	beq _02031E9C
	mov r1, #0
	mov r3, #1
	bl _ZN19CFieldPartnerManage12ov0_0213A96CEimi
	arm_func_end sub_02031E78
_02031E9C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031EA4: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031EA8
sub_02031EA8: ; 0x02031EA8
	stmdb sp!, {r3, lr}
	ldr r1, _02031ED4 ; =MAIN_BSS_0210CA4C
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r0, #0
	beq _02031ECC
	mov r1, #0
	mov r3, r1
	bl _ZN19CFieldPartnerManage12ov0_0213A96CEimi
	arm_func_end sub_02031EA8
_02031ECC:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031ED4: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031ED8
sub_02031ED8: ; 0x02031ED8
	stmdb sp!, {r3, lr}
	ldr r2, _02031EFC ; =MAIN_BSS_0210CA4C
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	beq _02031EF4
	bl _ZN19CFieldPartnerManage12ov0_0213AD8CEi
	arm_func_end sub_02031ED8
_02031EF4:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031EFC: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031F00
sub_02031F00: ; 0x02031F00
	stmdb sp!, {r3, lr}
	ldr r2, _02031F24 ; =MAIN_BSS_0210CA4C
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	beq _02031F1C
	bl _ZN19CFieldPartnerManage12ov0_0213B150Em
	arm_func_end sub_02031F00
_02031F1C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031F24: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031F28
sub_02031F28: ; 0x02031F28
	stmdb sp!, {r3, lr}
	ldr r2, _02031F4C ; =MAIN_BSS_0210CA4C
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	beq _02031F44
	bl _ZN19CFieldPartnerManage12ov0_0213B184Em
	arm_func_end sub_02031F28
_02031F44:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02031F4C: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031F50
sub_02031F50: ; 0x02031F50
	ldr r0, _02031F60 ; =MAIN_BSS_0210CA4C
	ldr r0, [r0]
	ldr r0, [r0, #0x88]
	bx lr
	.align 2, 0
_02031F60: .word MAIN_BSS_0210CA4C
	arm_func_end sub_02031F50

	arm_func_start sub_02031F64
sub_02031F64: ; 0x02031F64
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02031FD0 ; =MAIN_BSS_0210CA4C
	ldr r3, [r0]
	ldr lr, [r1]
	mov r0, #0
	cmp lr, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	ldr r4, [lr, #4]
	mov ip, r0
	cmp r4, #0
	ldmleia sp!, {r3, r4, r5, pc}
	mov r2, r0
	arm_func_end sub_02031F64
_02031F94:
	cmp r4, ip
	ldrgt r1, [lr, #8]
	movle r5, r2
	ldrgt r5, [r1, ip, lsl #2]
	cmp r5, #0
	beq _02031FC0
	ldr r1, [r5, #0x200]
	cmp r3, r1
	ldreq r1, [r5, #0x1fc]
	cmpeq r1, #0
	addeq r0, r0, #1
_02031FC0:
	add ip, ip, #1
	cmp ip, r4
	blt _02031F94
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02031FD0: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02031FD4
sub_02031FD4: ; 0x02031FD4
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	mov r0, r1, asr #0x18
	and r0, r0, #0xff
	cmp r0, #2
	moveq r2, #5
	beq _0203200C
	cmp r0, #1
	moveq r2, #6
	beq _0203200C
	ldr r0, _02032078 ; =s_error_actorid_x_is_not_enemy_o_0208d48c
	bl LogError
	arm_func_end sub_02031FD4

	arm_func_start sub_02032004
sub_02032004: ; 0x02032004
	mov r0, #0
	arm_func_end sub_02032004

	arm_func_start sub_02032008
sub_02032008: ; 0x02032008
	ldmia sp!, {r3, pc}
	arm_func_end sub_02032008
_0203200C:
	ldr r0, _0203207C ; =MAIN_BSS_0210CA4C
	bic r1, r1, #0xff000000
	ldr r0, [r0]
	orr r2, r1, r2, lsl #24
	cmp r0, #0
	beq _02032070
	ldr r3, [r0, #4]
	mov r1, #0
	cmp r3, #0
	ble _02032060
	ldr ip, [r0, #8]
_02032038:
	ldr r0, [ip, r1, lsl #2]
	cmp r0, #0
	beq _02032054
	ldr r0, [r0, #0x58]
	cmp r2, r0
	ldreq r0, [ip, r1, lsl #2]
	beq _02032064
_02032054:
	add r1, r1, #1
	cmp r1, r3
	blt _02032038
_02032060:
	mov r0, #0
_02032064:
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, pc}
_02032070:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032078: .word s_error_actorid_x_is_not_enemy_o_0208d48c
_0203207C: .word MAIN_BSS_0210CA4C

	arm_func_start sub_02032080
sub_02032080: ; 0x02032080
	stmdb sp!, {r3, lr}
	ldr r2, _020320A4 ; =MAIN_BSS_0210CA4C
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN19CFieldPartnerManage12ov0_0213A4C4Em
	ldmia sp!, {r3, pc}
	.align 2, 0
_020320A4: .word MAIN_BSS_0210CA4C
	arm_func_end sub_02032080

	arm_func_start sub_020320A8
sub_020320A8: ; 0x020320A8
	stmdb sp!, {r3, lr}
	mov r0, #1
	bl sub_0202BCD4
	cmp r0, #0
	movne r0, #1
	moveq r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_020320A8

	arm_func_start sub_020320C4
sub_020320C4: ; 0x020320C4
	stmdb sp!, {r3, lr}
	ldr r2, _020320E8 ; =MAIN_BSS_0210CA4C
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl _ZN19CFieldPartnerManage12ov0_0213A520Em
	ldmia sp!, {r3, pc}
	.align 2, 0
_020320E8: .word MAIN_BSS_0210CA4C
	arm_func_end sub_020320C4

	arm_func_start sub_020320EC
sub_020320EC: ; 0x020320EC
	stmdb sp!, {r3, r4, r5, lr}
	ldmia r0, {r4, r5}
	mov r0, r4
	bl sub_0202BCD4
	cmp r0, #0
	beq _02032120
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #5
	bne _02032120
	mov r1, r5
	bl ov0_0213E158
	arm_func_end sub_020320EC
_02032120:
	ldr r0, _02032144 ; =MAIN_BSS_020B26A0
	mov r1, r4
	bl sub_0201549C
	cmp r0, #0
	beq _0203213C
	mov r1, r5
	bl sub_02015164
_0203213C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02032144: .word MAIN_BSS_020B26A0

	arm_func_start sub_02032148
sub_02032148: ; 0x02032148
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _02032170 ; =MAIN_BSS_020B26A0
	bl sub_02015520
	cmp r0, #0
	ldrne r1, [r0, #8]
	orrne r1, r1, #4
	strne r1, [r0, #8]
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032170: .word MAIN_BSS_020B26A0
	arm_func_end sub_02032148

	arm_func_start sub_02032174
sub_02032174: ; 0x02032174
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _0203219C ; =MAIN_BSS_020B26A0
	bl sub_02015520
	cmp r0, #0
	ldrne r1, [r0, #8]
	bicne r1, r1, #4
	strne r1, [r0, #8]
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203219C: .word MAIN_BSS_020B26A0
	arm_func_end sub_02032174

	arm_func_start sub_020321A0
sub_020321A0: ; 0x020321A0
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _020321C8 ; =MAIN_BSS_020B26A0
	bl sub_02015520
	cmp r0, #0
	ldrne r1, [r0, #8]
	orrne r1, r1, #2
	strne r1, [r0, #8]
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020321C8: .word MAIN_BSS_020B26A0
	arm_func_end sub_020321A0

	arm_func_start sub_020321CC
sub_020321CC: ; 0x020321CC
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _020321F4 ; =MAIN_BSS_020B26A0
	bl sub_02015520
	cmp r0, #0
	ldrne r1, [r0, #8]
	bicne r1, r1, #2
	strne r1, [r0, #8]
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020321F4: .word MAIN_BSS_020B26A0
	arm_func_end sub_020321CC

	arm_func_start sub_020321F8
sub_020321F8: ; 0x020321F8
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	ldr r0, _020322A4 ; =MAIN_BSS_0210CA4C
	ldr r4, _020322A8 ; =MAIN_BSS_020B26A0
	ldr r8, [r0]
	cmp r8, #0
	cmpne r4, #0
	beq _0203229C
	mov r0, r4
	mvn r1, #0
	bl sub_02016138
	mov r5, r0
	mov r6, #0
	mov r7, r6
	cmp r5, #0
	ble _0203229C
	ldr sb, _020322AC ; =0x00000FFF
	arm_func_end sub_020321F8
_02032238:
	mov r0, r4
	mov r1, r6
	bl sub_020155FC
	cmp r0, #0
	beq _02032290
	ldr r1, [r0, #8]
	tst r1, #2
	addne r6, r6, #1
	bne _02032290
	ldrh r1, [r0, #2]
	ldrh r2, [r0, #4]
	mov r0, r8
	mov r1, r1, lsl #0x14
	mov r1, r1, lsr #8
	and r2, r2, sb
	orr r1, r1, #0x6000000
	orr sl, r2, r1
	mov r1, sl
	bl _ZN19CFieldPartnerManage12ov0_0213A050Em
	mov r0, r4
	mov r1, sl
	bl sub_02015E54
_02032290:
	add r7, r7, #1
	cmp r7, r5
	blt _02032238
_0203229C:
	mov r0, #0
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_020322A4: .word MAIN_BSS_0210CA4C
_020322A8: .word MAIN_BSS_020B26A0
_020322AC: .word 0x00000FFF

	arm_func_start sub_020322B0
sub_020322B0: ; 0x020322B0
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, lr}
	ldr r0, _02032384 ; =MAIN_BSS_0210CA4C
	mov r2, #0
	ldr r6, [r0]
	cmp r6, #0
	beq _02032354
	ldr r3, [r6, #0x88]
	mov lr, r2
	cmp r3, #0
	ldr ip, [r6, #0x84]
	ble _02032354
	ldr r7, [r6, #4]
	mov r0, r2
	mov sb, r2
	mov r1, r2
	arm_func_end sub_020322B0
_020322EC:
	mov r4, r1
	cmp r7, #0
	ble _0203232C
	add r5, ip, lr
_020322FC:
	cmp r7, r4
	movle r8, r0
	ldrgt r8, [r6, #8]
	ldrgt r8, [r8, r4, lsl #2]
	cmp r8, #0
	beq _02032320
	ldr sl, [r8, #0x1e8]
	cmp r5, sl
	beq _02032330
_02032320:
	add r4, r4, #1
	cmp r4, r7
	blt _020322FC
_0203232C:
	mov r8, sb
_02032330:
	cmp r8, #0
	beq _02032348
	ldr r4, [r8, #4]
	tst r4, #0x20
	ldrne r2, [r8, #0x200]
	bne _02032354
_02032348:
	add lr, lr, #1
	cmp lr, r3
	blt _020322EC
_02032354:
	cmp r2, #0
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	ldr r1, _02032388 ; =_0208F304
	mov r0, r2, lsl #0x10
	ldr r2, [r1]
	mov r1, r0, lsr #0x10
	add r0, r2, #0x1000
	ldr r0, [r0, #0x434]
	bl sub_020107A8
	ldrh r0, [r0]
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, pc}
	.align 2, 0
_02032384: .word MAIN_BSS_0210CA4C
_02032388: .word s_game

	arm_func_start sub_0203238C
sub_0203238C: ; 0x0203238C
	stmdb sp!, {r3, lr}
	ldr r2, _020323B0 ; =MAIN_BSS_0210CA4C
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r0, #0
	beq _020323A8
	bl _ZN19CFieldPartnerManage12ov0_02139F10Ei
	arm_func_end sub_0203238C
_020323A8:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020323B0: .word MAIN_BSS_0210CA4C

	arm_func_start sub_020323B4
sub_020323B4: ; 0x020323B4
	ldr r0, _020323C4 ; =MAIN_BSS_0210CA4C
	ldr r0, [r0]
	ldr r0, [r0, #0x84]
	bx lr
	.align 2, 0
_020323C4: .word MAIN_BSS_0210CA4C
	arm_func_end sub_020323B4

	arm_func_start sub_020323C8
sub_020323C8: ; 0x020323C8
	stmdb sp!, {r3, lr}
	ldr r1, _020324A0 ; =MAIN_BSS_0210CA4C
	ldr r3, [r0]
	ldr r0, [r1]
	ldr r1, _020324A4 ; =MAIN_BSS_020B26A0
	cmp r0, #0
	cmpne r1, #0
	beq _02032498
	ldr ip, [r0, #4]
	mov r2, #0
	cmp ip, #0
	ble _02032424
	ldr lr, [r0, #8]
	arm_func_end sub_020323C8
_020323FC:
	ldr r0, [lr, r2, lsl #2]
	cmp r0, #0
	beq _02032418
	ldr r0, [r0, #0x58]
	cmp r3, r0
	ldreq r2, [lr, r2, lsl #2]
	beq _02032428
_02032418:
	add r2, r2, #1
	cmp r2, ip
	blt _020323FC
_02032424:
	mov r2, #0
_02032428:
	cmp r2, #0
	beq _02032498
	ldrb r0, [r2, #0x20]
	mov r3, #1
	cmp r0, #2
	cmpne r0, #3
	movne r3, #0
	cmp r3, #0
	beq _02032498
	ldr r0, [r2, #4]
	tst r0, #1
	movne r3, #1
	moveq r3, #0
	cmp r3, #0
	bne _02032498
	tst r0, #0x20
	bne _02032490
	ldr r0, [r2, #0x1fc]
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	addeq r0, r1, #0x8000
	ldreqb r0, [r0, #0xb64]
	cmpeq r0, #4
	beq _02032498
_02032490:
	mov r0, #1
	ldmia sp!, {r3, pc}
_02032498:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020324A0: .word MAIN_BSS_0210CA4C
_020324A4: .word MAIN_BSS_020B26A0

	arm_func_start sub_020324A8
sub_020324A8: ; 0x020324A8
	stmdb sp!, {r3, lr}
	ldr r0, _020324D4 ; =MAIN_BSS_0210CA6C
	ldr r0, [r0]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r1, _020324D8 ; =MAIN_BSS_020B26A0
	ldrh r1, [r1, #0x1a]
	bl sub_02041D80
	ldrb r0, [r0]
	ldmia sp!, {r3, pc}
	.align 2, 0
_020324D4: .word MAIN_BSS_0210CA6C
_020324D8: .word MAIN_BSS_020B26A0
	arm_func_end sub_020324A8

	arm_func_start sub_020324DC
sub_020324DC: ; 0x020324DC
	stmdb sp!, {r3, lr}
	ldr r1, _0203252C ; =MAIN_BSS_0210CA60
	ldr r3, [r1]
	cmp r3, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r2, [r0]
	cmp r2, #0
	blt _02032524
	cmp r2, #0x29
	bhs _02032524
	ldr r1, _02032530 ; =DAT_0208ccc8
	ldr r0, _02032534 ; =DAT_0208cccc
	ldr r1, [r1, r2, lsl #3]
	ldr r2, [r0, r2, lsl #3]
	mov r0, r3
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
	arm_func_end sub_020324DC
_02032524:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203252C: .word MAIN_BSS_0210CA60
_02032530: .word DAT_0208ccc8
_02032534: .word DAT_0208cccc

	arm_func_start sub_02032538
sub_02032538: ; 0x02032538
	stmdb sp!, {r4, lr}
	ldr r1, _02032580 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02032578
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02032578
	ldr ip, [r0]
	ldmib r4, {r1, r2, r3}
	ldr ip, [ip, #0x1c]
	blx ip
	arm_func_end sub_02032538
_02032578:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02032580: .word MAIN_BSS_0210CA60

	arm_func_start sub_02032584
sub_02032584: ; 0x02032584
	stmdb sp!, {r3, lr}
	ldr r1, _020325BC ; =MAIN_BSS_0210CA60
	ldr r2, [r0]
	ldr r0, [r1]
	mov r1, r2, lsl #0x10
	cmp r0, #0
	mov r1, r1, lsr #0x10
	beq _020325B4
	bl ov0_02143088
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, pc}
	arm_func_end sub_02032584
_020325B4:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020325BC: .word MAIN_BSS_0210CA60

	arm_func_start sub_020325C0
sub_020325C0: ; 0x020325C0
	stmdb sp!, {r3, lr}
	ldr r1, _020325EC ; =MAIN_BSS_0210CA60
	ldr r2, [r0]
	ldr r0, [r1]
	mov r1, r2, lsl #0x10
	cmp r0, #0
	mov r1, r1, lsr #0x10
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov0_021430D8
	ldmia sp!, {r3, pc}
	.align 2, 0
_020325EC: .word MAIN_BSS_0210CA60
	arm_func_end sub_020325C0

	arm_func_start sub_020325F0
sub_020325F0: ; 0x020325F0
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, _02032620 ; =MAIN_BSS_0210CA60
	cmp r1, #1
	ldr r0, [r0]
	bne _02032618
	mov r1, #0x1f
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
	arm_func_end sub_020325F0
_02032618:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032620: .word MAIN_BSS_0210CA60

	arm_func_start sub_02032624
sub_02032624: ; 0x02032624
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x14
	ldr r1, _020326C8 ; =MAIN_BSS_0210CA60
	ldr r4, [r0]
	ldr r3, [r0, #4]
	ldr r2, [r0, #8]
	ldr r7, [r1]
	mov r1, r4, lsl #0x10
	mov r3, r3, lsl #0xc
	mov r2, r2, lsl #0xc
	str r3, [sp, #0xc]
	str r2, [sp, #0x10]
	cmp r7, #0
	mov r1, r1, lsr #0x10
	ldr r4, [r0, #0xc]
	ldr r5, [r0, #0x10]
	ldr r6, [r0, #0x14]
	beq _020326BC
	mov r0, r7
	bl ov0_02143088
	movs r7, r0
	beq _020326BC
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr ip, [r0]
	add r1, sp, #0xc
	ldr ip, [ip, #0x34]
	ldmia r1, {r1, r2}
	blx ip
	mov r0, r7
	ldr ip, [r0]
	mov r1, r4
	ldr ip, [ip, #0x1c]
	mov r2, r5
	mov r3, r6
	blx ip
	arm_func_end sub_02032624
_020326BC:
	mov r0, #0
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_020326C8: .word MAIN_BSS_0210CA60

	arm_func_start sub_020326CC
sub_020326CC: ; 0x020326CC
	stmdb sp!, {r3, lr}
	ldr r1, _02032704 ; =MAIN_BSS_0210CA60
	ldr r2, [r0]
	ldr r0, [r1]
	mov r1, r2, lsl #0x10
	cmp r0, #0
	mov r1, r1, lsr #0x10
	beq _020326FC
	bl ov0_02143088
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, pc}
	arm_func_end sub_020326CC
_020326FC:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032704: .word MAIN_BSS_0210CA60

	arm_func_start sub_02032708
sub_02032708: ; 0x02032708
	stmdb sp!, {r4, lr}
	ldr r1, _02032764 ; =MAIN_BSS_0210CA60
	ldmia r0, {r2, r4}
	ldr r0, [r1]
	mov r1, r2, lsl #0x10
	cmp r0, #0
	mov r1, r1, lsr #0x10
	beq _0203275C
	mvn r2, #0
	cmp r4, r2
	bne _0203273C
	bl ov0_021430D8
	ldmia sp!, {r4, pc}
	arm_func_end sub_02032708
_0203273C:
	bl ov0_02143088
	cmp r0, #0
	beq _0203275C
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #0x20]
	blx r2
	ldmia sp!, {r4, pc}
_0203275C:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02032764: .word MAIN_BSS_0210CA60

	arm_func_start sub_02032768
sub_02032768: ; 0x02032768
	stmdb sp!, {r3, lr}
	ldr r1, _02032790 ; =MAIN_BSS_0210CA5C
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02032788
	ldmia r2, {r1, r2}
	bl _ZN17CFieldEnemyManage12ov0_0213690CEii
	arm_func_end sub_02032768
_02032788:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032790: .word MAIN_BSS_0210CA5C

	arm_func_start sub_02032794
sub_02032794: ; 0x02032794
	stmdb sp!, {r3, lr}
	ldr r0, _020327B4 ; =MAIN_BSS_0210CA5C
	ldr r0, [r0]
	cmp r0, #0
	beq _020327AC
	bl _ZN17CFieldEnemyManage12ov0_02136968Ev
	arm_func_end sub_02032794
_020327AC:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020327B4: .word MAIN_BSS_0210CA5C

	arm_func_start sub_020327B8
sub_020327B8: ; 0x020327B8
	ldr r1, _020327D8 ; =MAIN_BSS_020B26A0
	ldr r2, [r0]
	add r1, r1, #0x8000
	ldr r3, [r1, #0x7c8]
	mov r0, #0
	orr r2, r3, r2
	str r2, [r1, #0x7c8]
	bx lr
	.align 2, 0
_020327D8: .word MAIN_BSS_020B26A0
	arm_func_end sub_020327B8

	arm_func_start sub_020327DC
sub_020327DC: ; 0x020327DC
	ldr r1, _02032800 ; =MAIN_BSS_020B26A0
	cmp r1, #0
	moveq r0, #0
	bxeq lr
	add r1, r1, #0x8000
	ldr r1, [r1, #0x7c8]
	ldr r0, [r0]
	and r0, r1, r0
	bx lr
	.align 2, 0
_02032800: .word MAIN_BSS_020B26A0
	arm_func_end sub_020327DC

	arm_func_start sub_02032804
sub_02032804: ; 0x02032804
	ldr r1, _02032824 ; =MAIN_BSS_020B26A0
	cmp r1, #0
	moveq r0, #0
	bxeq lr
	ldr r0, [r0]
	add r0, r1, r0
	ldrb r0, [r0, #9]
	bx lr
	.align 2, 0
_02032824: .word MAIN_BSS_020B26A0
	arm_func_end sub_02032804

	arm_func_start sub_02032828
sub_02032828: ; 0x02032828
	stmdb sp!, {r3, lr}
	ldr r1, _0203284C ; =_0208F304
	ldr r2, [r1]
	ldr r1, [r0]
	add r0, r2, #0x1000
	ldr r0, [r0, #0x43c]
	bl sub_02010988
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203284C: .word s_game
	arm_func_end sub_02032828

	arm_func_start sub_02032850
sub_02032850: ; 0x02032850
	mov r0, #0
	bx lr
	arm_func_end sub_02032850

	arm_func_start sub_02032858
sub_02032858: ; 0x02032858
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _02032894
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #3
	bne _02032894
	ldr r1, [r4, #4]
	str r1, [r0, #0xec]
	mov r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end sub_02032858
_02032894:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_0203289C
sub_0203289C: ; 0x0203289C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _020328C8
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #3
	ldreq r0, [r0, #0xec]
	ldmeqia sp!, {r3, pc}
	arm_func_end sub_0203289C
_020328C8:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_020328D0
sub_020328D0: ; 0x020328D0
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	bl sub_0202BCD4
	cmp r0, #0
	beq _02032910
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #3
	bne _02032910
	ldmib r4, {r1, r2}
	mov r1, r1, lsl #0xc
	str r1, [r0, #0xf0]
	mov r1, r2, lsl #0xc
	str r1, [r0, #0xf4]
	arm_func_end sub_020328D0
_02032910:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_02032918
sub_02032918: ; 0x02032918
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _02032974
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #3
	bne _02032974
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _02032960
	ldr r1, [r1, #0xc]
	cmp r1, #0
	ldrne r1, [r1, #0x20]
	moveq r1, #0
	b _02032964
	arm_func_end sub_02032918
_02032960:
	mov r1, #0
_02032964:
	ldr r0, [r0, #0xf0]
	add r0, r1, r0
	mov r0, r0, asr #0xc
	ldmia sp!, {r3, pc}
_02032974:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_0203297C
sub_0203297C: ; 0x0203297C
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _020329D8
	ldr r1, [r0, #0x58]
	mov r1, r1, asr #0x18
	and r1, r1, #0xff
	cmp r1, #3
	bne _020329D8
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _020329C4
	ldr r1, [r1, #0xc]
	cmp r1, #0
	ldrne r1, [r1, #0x24]
	moveq r1, #0
	b _020329C8
	arm_func_end sub_0203297C
_020329C4:
	mov r1, #0
_020329C8:
	ldr r0, [r0, #0xf4]
	add r0, r1, r0
	mov r0, r0, asr #0xc
	ldmia sp!, {r3, pc}
_020329D8:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_020329E0
sub_020329E0: ; 0x020329E0
	ldr r1, _020329F8 ; =MAIN_BSS_0210CA74
	mov r0, #0
	ldr r2, [r1]
	orr r2, r2, #1
	str r2, [r1]
	bx lr
	.align 2, 0
_020329F8: .word MAIN_BSS_0210CA74
	arm_func_end sub_020329E0

	arm_func_start sub_020329FC
sub_020329FC: ; 0x020329FC
	ldr r1, _02032A14 ; =MAIN_BSS_0210CA74
	mov r0, #0
	ldr r2, [r1]
	bic r2, r2, #1
	str r2, [r1]
	bx lr
	.align 2, 0
_02032A14: .word MAIN_BSS_0210CA74
	arm_func_end sub_020329FC

	arm_func_start sub_02032A18
sub_02032A18: ; 0x02032A18
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _02032A3C
	ldr r2, [r0]
	mov r1, #0x10
	ldr r2, [r2, #0x3c]
	blx r2
	arm_func_end sub_02032A18
_02032A3C:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start _ZN11CFieldActor12sub_02032A44Ei
_ZN11CFieldActor12sub_02032A44Ei: ; 0x02032A44
	bx lr
	arm_func_end _ZN11CFieldActor12sub_02032A44Ei

	arm_func_start sub_02032A48
sub_02032A48: ; 0x02032A48
	stmdb sp!, {r3, lr}
	ldr r0, [r0]
	bl sub_0202BCD4
	cmp r0, #0
	beq _02032A6C
	ldr r2, [r0]
	mov r1, #1
	ldr r2, [r2, #0x3c]
	blx r2
	arm_func_end sub_02032A48
_02032A6C:
	mov r0, #0
	ldmia sp!, {r3, pc}

	arm_func_start sub_02032A74
sub_02032A74: ; 0x02032A74
	stmdb sp!, {r3, lr}
	ldr r1, _02032BA8 ; =MAIN_BSS_0210CA60
	ldr r1, [r1]
	cmp r1, #0
	beq _02032BA0
	ldr r0, [r0]
	cmp r0, #0xc8
	bgt _02032AC0
	bge _02032AF8
	cmp r0, #0x16
	bgt _02032BA0
	cmp r0, #0x10
	blt _02032BA0
	beq _02032B68
	cmp r0, #0x11
	beq _02032B7C
	cmp r0, #0x16
	beq _02032B90
	b _02032BA0
	arm_func_end sub_02032A74
_02032AC0:
	cmp r0, #0xc9
	bgt _02032AD0
	beq _02032B0C
	b _02032BA0
_02032AD0:
	cmp r0, #0xcc
	bgt _02032BA0
	cmp r0, #0xca
	blt _02032BA0
	beq _02032B20
	cmp r0, #0xcb
	beq _02032B38
	cmp r0, #0xcc
	beq _02032B50
	b _02032BA0
_02032AF8:
	ldr r0, [r1, #0x608]
	cmp r0, #0
	beq _02032BA0
	bl ov0_0215F410
	b _02032BA0
_02032B0C:
	ldr r0, [r1, #0x60c]
	cmp r0, #0
	beq _02032BA0
	bl ov0_02162988
	b _02032BA0
_02032B20:
	ldr r0, [r1, #0x620]
	cmp r0, #0
	beq _02032BA0
	mov r1, #0x84
	bl ov0_02163788
	b _02032BA0
_02032B38:
	ldr r0, [r1, #0x620]
	cmp r0, #0
	beq _02032BA0
	mov r1, #0x85
	bl ov0_02163788
	b _02032BA0
_02032B50:
	ldr r0, [r1, #0x620]
	cmp r0, #0
	beq _02032BA0
	mov r1, #0x86
	bl ov0_02163788
	b _02032BA0
_02032B68:
	ldr r0, [r1, #0x63c]
	cmp r0, #0
	beq _02032BA0
	bl ov0_0216EE1C
	b _02032BA0
_02032B7C:
	ldr r0, [r1, #0x640]
	cmp r0, #0
	beq _02032BA0
	bl ov0_0216FEA4
	b _02032BA0
_02032B90:
	ldr r0, [r1, #0x650]
	cmp r0, #0
	beq _02032BA0
	bl ov0_0217248C
_02032BA0:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032BA8: .word MAIN_BSS_0210CA60

	arm_func_start sub_02032BAC
sub_02032BAC: ; 0x02032BAC
	stmdb sp!, {r3, lr}
	ldr r1, _02032F54 ; =MAIN_BSS_0210CA60
	ldr r3, [r1]
	cmp r3, #0
	beq _02032F4C
	ldr r0, [r0]
	cmp r0, #0x69
	bgt _02032C74
	bge _02032F38
	cmp r0, #0x66
	bgt _02032C58
	bge _02032E34
	cmp r0, #0x16
	bgt _02032C4C
	cmp r0, #0
	addge pc, pc, r0, lsl #2
	b _02032F4C
_02032BF0: ; jump table
	b _02032CB8 ; case 0
	b _02032CCC ; case 1
	b _02032CE0 ; case 2
	b _02032E5C ; case 3
	b _02032E70 ; case 4
	b _02032E84 ; case 5
	b _02032E98 ; case 6
	b _02032EAC ; case 7
	b _02032CF4 ; case 8
	b _02032D08 ; case 9
	b _02032D1C ; case 10
	b _02032D30 ; case 11
	b _02032D44 ; case 12
	b _02032D58 ; case 13
	b _02032D6C ; case 14
	b _02032D80 ; case 15
	b _02032D94 ; case 16
	b _02032DA8 ; case 17
	b _02032DBC ; case 18
	b _02032E0C ; case 19
	b _02032DD0 ; case 20
	b _02032DE4 ; case 21
	b _02032DF8 ; case 22
	arm_func_end sub_02032BAC
_02032C4C:
	cmp r0, #0x64
	beq _02032E20
	b _02032F4C
_02032C58:
	cmp r0, #0x67
	bgt _02032C68
	beq _02032E48
	b _02032F4C
_02032C68:
	cmp r0, #0x68
	beq _02032F24
	b _02032F4C
_02032C74:
	cmp r0, #0xca
	bgt _02032C9C
	bge _02032EE8
	cmp r0, #0xc8
	bgt _02032C90
	beq _02032EC0
	b _02032F4C
_02032C90:
	cmp r0, #0xc9
	beq _02032ED4
	b _02032F4C
_02032C9C:
	cmp r0, #0xcb
	bgt _02032CAC
	beq _02032EFC
	b _02032F4C
_02032CAC:
	cmp r0, #0xcc
	beq _02032F10
	b _02032F4C
_02032CB8:
	mov r0, r3
	mov r1, #9
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032CCC:
	mov r0, r3
	mov r1, #0xb
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032CE0:
	mov r0, r3
	mov r1, #0xa
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032CF4:
	mov r0, r3
	mov r1, #0x26
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D08:
	mov r0, r3
	mov r1, #0x13
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D1C:
	mov r0, r3
	mov r1, #0x14
	mov r2, #1
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D30:
	mov r0, r3
	mov r1, #0x15
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D44:
	mov r0, r3
	mov r1, #0x16
	mov r2, #2
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D58:
	mov r0, r3
	mov r1, #0x17
	mov r2, #1
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D6C:
	mov r1, #0xe
	mov r0, r3
	sub r2, r1, #0x1a
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D80:
	mov r0, r3
	mov r1, #0x18
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032D94:
	mov r0, r3
	mov r1, #0x19
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032DA8:
	mov r0, r3
	mov r1, #0x1a
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032DBC:
	mov r0, r3
	mov r1, #0x1b
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032DD0:
	mov r0, r3
	mov r1, #0x1c
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032DE4:
	mov r0, r3
	mov r1, #0x1c
	mov r2, #1
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032DF8:
	mov r0, r3
	mov r1, #0x1e
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E0C:
	mov r0, r3
	mov r1, #9
	mov r2, #1
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E20:
	mov r0, r3
	mov r1, #0x22
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E34:
	mov r0, r3
	mov r1, #0x20
	mov r2, #0x79
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E48:
	mov r0, r3
	mov r1, #0x20
	mov r2, #0x78
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E5C:
	mov r0, r3
	mov r1, #0xe
	mov r2, #0xa
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E70:
	mov r0, r3
	mov r1, #0xf
	mov r2, #0xc
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E84:
	mov r0, r3
	mov r1, #0x10
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032E98:
	mov r0, r3
	mov r1, #0x11
	mov r2, #0xd
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032EAC:
	mov r1, #0xe
	mov r0, r3
	mov r2, r1
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032EC0:
	mov r0, r3
	mov r1, #0xc
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032ED4:
	mov r0, r3
	mov r1, #0xd
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032EE8:
	mov r0, r3
	mov r1, #0x12
	mov r2, #0x84
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032EFC:
	mov r0, r3
	mov r1, #0x12
	mov r2, #0x85
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032F10:
	ldr r2, _02032F58 ; =0x00000486
	mov r0, r3
	mov r1, #0x12
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032F24:
	mov r0, r3
	mov r1, #0x21
	mov r2, #0x6e
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032F38:
	mov r0, r3
	mov r1, #0x1d
	mov r2, #0
	bl ov0_02142F6C
	ldmia sp!, {r3, pc}
_02032F4C:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032F54: .word MAIN_BSS_0210CA60
_02032F58: .word 0x00000486

	arm_func_start sub_02032F5C
sub_02032F5C: ; 0x02032F5C
	stmdb sp!, {r3, lr}
	ldr r1, _02032F88 ; =MAIN_BSS_0210CA60
	ldr r2, [r0]
	ldr r0, [r1]
	mov r1, r2, lsl #0x10
	cmp r0, #0
	mov r1, r1, lsr #0x10
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl ov0_021430D8
	ldmia sp!, {r3, pc}
	.align 2, 0
_02032F88: .word MAIN_BSS_0210CA60
	arm_func_end sub_02032F5C

	arm_func_start sub_02032F8C
sub_02032F8C: ; 0x02032F8C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r1, _02033024 ; =MAIN_BSS_0210CA60
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _0203301C
	ldr r1, [r2]
	ldmib r2, {r5, r6, r7}
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	movs r4, r0
	beq _0203301C
	ldr ip, [r0]
	mov r1, r5
	ldr ip, [ip, #0x1c]
	mov r2, r6
	mov r3, r7
	blx ip
	mov r0, r4
	ldr r2, [r0]
	mov r1, #0
	ldr r2, [r2, #0x24]
	blx r2
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	cmp r0, #0x12
	bne _0203301C
	ldr r0, [r4, #0x1ec]
	ldr r1, [r0]
	ldr r1, [r1, #0x1c]
	blx r1
	mov r0, r4
	bl ov0_021633CC
	arm_func_end sub_02032F8C
_0203301C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02033024: .word MAIN_BSS_0210CA60

	arm_func_start sub_02033028
sub_02033028: ; 0x02033028
	mov r0, #0
	bx lr
	arm_func_end sub_02033028

	arm_func_start sub_02033030
sub_02033030: ; 0x02033030
	stmdb sp!, {r4, lr}
	ldr r1, _02033078 ; =MAIN_BSS_0210CA60
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033070
	ldmia r2, {r1, r4}
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033070
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #0x20]
	blx r2
	arm_func_end sub_02033030
_02033070:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033078: .word MAIN_BSS_0210CA60

	arm_func_start sub_0203307C
sub_0203307C: ; 0x0203307C
	stmdb sp!, {r3, lr}
	ldr r1, _020330B8 ; =MAIN_BSS_0210CA60
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _020330B0
	ldr r1, [r2]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	movne r0, #1
	ldmneia sp!, {r3, pc}
	arm_func_end sub_0203307C
_020330B0:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020330B8: .word MAIN_BSS_0210CA60

	arm_func_start sub_020330BC
sub_020330BC: ; 0x020330BC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02033128 ; =MAIN_BSS_0210CA60
	mov r5, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033120
	ldr r1, [r5]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	movs r4, r0
	beq _02033120
	ldr r3, [r0]
	ldr r2, [r5, #4]
	ldr r3, [r3, #0x38]
	mov r1, #1
	blx r3
	mov r0, r4
	ldr r3, [r0]
	ldr r2, [r5, #8]
	ldr r3, [r3, #0x38]
	mov r1, #2
	blx r3
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_020330BC
_02033120:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02033128: .word MAIN_BSS_0210CA60

	arm_func_start sub_0203312C
sub_0203312C: ; 0x0203312C
	mov r0, #0
	bx lr
	arm_func_end sub_0203312C

	arm_func_start sub_02033134
sub_02033134: ; 0x02033134
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _020331A0 ; =MAIN_BSS_0210CA60
	mov r5, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033198
	ldr r1, [r5]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	movs r4, r0
	beq _02033198
	ldr r3, [r0]
	ldr r2, [r5, #4]
	ldr r3, [r3, #0x38]
	mov r1, #3
	blx r3
	mov r0, r4
	ldr r3, [r0]
	ldr r2, [r5, #8]
	ldr r3, [r3, #0x38]
	mov r1, #4
	blx r3
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_02033134
_02033198:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020331A0: .word MAIN_BSS_0210CA60

	arm_func_start sub_020331A4
sub_020331A4: ; 0x020331A4
	stmdb sp!, {r4, lr}
	ldr r1, _020331F0 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _020331E8
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _020331E8
	ldr r3, [r0]
	ldmib r4, {r1, r2}
	ldr r3, [r3, #0x38]
	blx r3
	ldmia sp!, {r4, pc}
	arm_func_end sub_020331A4
_020331E8:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_020331F0: .word MAIN_BSS_0210CA60

	arm_func_start sub_020331F4
sub_020331F4: ; 0x020331F4
	stmdb sp!, {r4, lr}
	ldr r1, _02033240 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033238
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033238
	ldr ip, [r0]
	ldmib r4, {r1, r2, r3}
	ldr ip, [ip, #0x3c]
	blx ip
	ldmia sp!, {r4, pc}
	arm_func_end sub_020331F4
_02033238:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033240: .word MAIN_BSS_0210CA60

	arm_func_start sub_02033244
sub_02033244: ; 0x02033244
	mov r0, #0
	bx lr
	arm_func_end sub_02033244

	arm_func_start sub_0203324C
sub_0203324C: ; 0x0203324C
	stmdb sp!, {r3, lr}
	ldr r1, _020332A0 ; =MAIN_BSS_0210CA60
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033298
	ldr r1, [r2]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033298
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	cmp r0, #0
	moveq r0, #1
	movne r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_0203324C
_02033298:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020332A0: .word MAIN_BSS_0210CA60

	arm_func_start sub_020332A4
sub_020332A4: ; 0x020332A4
	mov r0, #1
	bx lr
	arm_func_end sub_020332A4

	arm_func_start sub_020332AC
sub_020332AC: ; 0x020332AC
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	ldr r1, _02033318 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _0203330C
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _0203330C
	ldr r2, [r4, #4]
	add r1, sp, #0
	mov r2, r2, lsl #0xc
	str r2, [sp]
	ldr r2, [r4, #8]
	mov r2, r2, lsl #0xc
	str r2, [sp, #4]
	ldr r3, [r0]
	ldr r2, [r4, #0xc]
	ldr r3, [r3, #0x44]
	blx r3
	arm_func_end sub_020332AC
_0203330C:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033318: .word MAIN_BSS_0210CA60

	arm_func_start sub_0203331C
sub_0203331C: ; 0x0203331C
	bx lr
	arm_func_end sub_0203331C

	arm_func_start sub_02033320
sub_02033320: ; 0x02033320
	stmdb sp!, {r4, lr}
	sub sp, sp, #8
	ldr r1, _02033384 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033378
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033378
	ldr r2, [r4, #4]
	add r1, sp, #0
	str r2, [sp]
	ldr r2, [r4, #8]
	str r2, [sp, #4]
	ldr r3, [r0]
	ldr r2, [r4, #0xc]
	ldr r3, [r3, #0x48]
	blx r3
	arm_func_end sub_02033320
_02033378:
	mov r0, #0
	add sp, sp, #8
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033384: .word MAIN_BSS_0210CA60

	arm_func_start sub_02033388
sub_02033388: ; 0x02033388
	bx lr
	arm_func_end sub_02033388

	arm_func_start sub_0203338C
sub_0203338C: ; 0x0203338C
	stmdb sp!, {r4, lr}
	ldr r1, _020333D4 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _020333CC
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _020333CC
	ldr r3, [r0]
	ldmib r4, {r1, r2}
	ldr r3, [r3, #0x4c]
	blx r3
	arm_func_end sub_0203338C
_020333CC:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_020333D4: .word MAIN_BSS_0210CA60

	arm_func_start sub_020333D8
sub_020333D8: ; 0x020333D8
	bx lr
	arm_func_end sub_020333D8

	arm_func_start sub_020333DC
sub_020333DC: ; 0x020333DC
	stmdb sp!, {r4, lr}
	ldr r1, _0203343C ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033434
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033434
	ldr r3, [r4, #4]
	ldr r1, [r4, #8]
	ldr r2, [r0]
	ldr ip, [r4, #0xc]
	orr r1, r3, r1, lsl #5
	orr r1, r1, ip, lsl #10
	mov r1, r1, lsl #0x10
	ldr r2, [r2, #0x40]
	mov r1, r1, lsr #0x10
	blx r2
	arm_func_end sub_020333DC
_02033434:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_0203343C: .word MAIN_BSS_0210CA60

	arm_func_start sub_02033440
sub_02033440: ; 0x02033440
	bx lr
	arm_func_end sub_02033440

	arm_func_start sub_02033444
sub_02033444: ; 0x02033444
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _020334B0 ; =MAIN_BSS_0210CA60
	mov r5, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _020334A8
	ldr r1, [r5]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	movs r4, r0
	beq _020334A8
	ldr r3, [r0]
	ldr r2, [r5, #4]
	ldr r3, [r3, #0x38]
	mov r1, #1
	blx r3
	mov r0, r4
	ldr r3, [r0]
	ldr r2, [r5, #8]
	ldr r3, [r3, #0x38]
	mov r1, #2
	blx r3
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end sub_02033444
_020334A8:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020334B0: .word MAIN_BSS_0210CA60

	arm_func_start sub_020334B4
sub_020334B4: ; 0x020334B4
	stmdb sp!, {r3, r4, r5, lr}
	ldr r1, _02033518 ; =MAIN_BSS_0210CA60
	mov r5, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033510
	ldr r1, [r5]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	movs r4, r0
	beq _02033510
	ldr r3, [r0]
	ldr r2, [r5, #4]
	ldr r3, [r3, #0x38]
	mov r1, #9
	blx r3
	mov r0, r4
	ldr r3, [r0]
	ldr r2, [r5, #8]
	ldr r3, [r3, #0x38]
	mov r1, #0xa
	blx r3
	arm_func_end sub_020334B4
_02033510:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02033518: .word MAIN_BSS_0210CA60

	arm_func_start sub_0203351C
sub_0203351C: ; 0x0203351C
	stmdb sp!, {r4, lr}
	ldr r1, _02033568 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033560
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033560
	ldr r3, [r0]
	ldmib r4, {r1, r2}
	ldr r3, [r3, #0x38]
	blx r3
	ldmia sp!, {r4, pc}
	arm_func_end sub_0203351C
_02033560:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033568: .word MAIN_BSS_0210CA60

	arm_func_start sub_0203356C
sub_0203356C: ; 0x0203356C
	stmdb sp!, {r4, lr}
	ldr r1, _020335B4 ; =MAIN_BSS_0210CA60
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _020335AC
	ldmia r2, {r1, r4}
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _020335AC
	ldr r2, [r0]
	mov r1, r4
	ldr r2, [r2, #0x20]
	blx r2
	arm_func_end sub_0203356C
_020335AC:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_020335B4: .word MAIN_BSS_0210CA60

	arm_func_start sub_020335B8
sub_020335B8: ; 0x020335B8
	stmdb sp!, {r3, lr}
	ldr r1, _0203360C ; =MAIN_BSS_0210CA60
	mov r2, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033604
	ldr r1, [r2]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033604
	ldr r1, [r0]
	ldr r1, [r1, #0x10]
	blx r1
	cmp r0, #0
	moveq r0, #1
	movne r0, #0
	ldmia sp!, {r3, pc}
	arm_func_end sub_020335B8
_02033604:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_0203360C: .word MAIN_BSS_0210CA60

	arm_func_start sub_02033610
sub_02033610: ; 0x02033610
	stmdb sp!, {r4, lr}
	ldr r1, _02033658 ; =MAIN_BSS_0210CA60
	mov r4, r0
	ldr r0, [r1]
	cmp r0, #0
	beq _02033650
	ldr r1, [r4]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl ov0_02143088
	cmp r0, #0
	beq _02033650
	ldr r2, [r0]
	ldr r1, [r4, #4]
	ldr r2, [r2, #0x50]
	blx r2
	arm_func_end sub_02033610
_02033650:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033658: .word MAIN_BSS_0210CA60

	arm_func_start sub_0203365C
sub_0203365C: ; 0x0203365C
	bx lr
	arm_func_end sub_0203365C

	arm_func_start sub_02033660
sub_02033660: ; 0x02033660
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r1, _020336DC ; =MAIN_BSS_0210CA40
	ldr r4, _020336E0 ; =MAIN_BSS_020B26A0
	ldr r1, [r1]
	cmp r1, #0
	cmpne r4, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldr r5, [r1, #0xd8]
	cmp r5, #0
	moveq r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	ldrb r2, [r4, #1]
	ldr r1, [r0]
	ldrb r3, [r4, #2]
	add r6, r2, r1
	ldr r0, [r0, #4]
	cmp r6, r3
	mov r1, r0, lsl #0x10
	movgt r6, r3
	mov r2, r6, lsl #0x10
	mov r7, r1, lsr #0x10
	mov r0, r5
	mov r1, r2, lsr #0x10
	bl sub_0201A018
	mov r0, r5
	mov r1, r7
	strb r6, [r4, #1]
	bl sub_0201A024
	mov r0, #0
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_020336DC: .word MAIN_BSS_0210CA40
_020336E0: .word MAIN_BSS_020B26A0
	arm_func_end sub_02033660

	arm_func_start sub_020336E4
sub_020336E4: ; 0x020336E4
	stmdb sp!, {r3, lr}
	ldr r0, _02033714 ; =MAIN_BSS_0210CA40
	ldr r0, [r0]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	ldr r0, [r0, #0xd8]
	cmp r0, #0
	moveq r0, #0
	ldmeqia sp!, {r3, pc}
	bl sub_0201A0DC
	ldmia sp!, {r3, pc}
	.align 2, 0
_02033714: .word MAIN_BSS_0210CA40
	arm_func_end sub_020336E4

	arm_func_start sub_02033718
sub_02033718: ; 0x02033718
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	ldr r0, [r0, #4]
	cmp r1, #0
	ldr lr, _020337E8 ; =MAIN_BSS_020B26A0
	blt _02033778
	cmp r1, #3
	bge _02033778
	cmp r0, #0
	blt _02033778
	cmp r0, #0x40
	bge _02033778
	mov r2, r0, asr #3
	add r2, r0, r2, lsr #28
	add r3, lr, r1, lsl #4
	mov r2, r2, asr #4
	add r2, r3, r2, lsl #2
	add r2, r2, #0x7000
	mov r3, r0, lsl #0x1c
	ldr ip, [r2, #0xf30]
	mov r2, r3, lsr #0x1b
	mov r2, ip, lsr r2
	and r2, r2, #3
	b _0203377C
	arm_func_end sub_02033718
_02033778:
	mov r2, #0
_0203377C:
	cmp r2, #0
	bne _020337E0
	cmp r1, #0
	blt _020337E0
	cmp r1, #3
	bge _020337E0
	cmp r0, #0
	blt _020337E0
	cmp r0, #0x40
	bge _020337E0
	add r3, lr, #0xf30
	mov ip, r0, lsl #0x1c
	mov r2, r0, asr #3
	add r0, r0, r2, lsr #28
	add r3, r3, #0x7000
	mov lr, ip, lsr #0x1b
	mov ip, r0, asr #4
	mov r2, #3
	add r3, r3, r1, lsl #4
	mvn r1, r2, lsl lr
	ldr r2, [r3, ip, lsl #2]
	mov r0, #1
	and r1, r2, r1
	orr r0, r1, r0, lsl lr
	str r0, [r3, ip, lsl #2]
_020337E0:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_020337E8: .word MAIN_BSS_020B26A0

	arm_func_start sub_020337EC
sub_020337EC: ; 0x020337EC
	ldr r1, _02033818 ; =MAIN_BSS_020B26A0
	mov r0, #0
	add r2, r1, #0x7000
	ldr r3, [r2, #0xf60]
	add r1, r1, #0x8000
	bic r3, r3, #2
	str r0, [r1, #0x7c0]
	strb r0, [r1, #0x7bf]
	str r0, [r1, #0x7c4]
	str r3, [r2, #0xf60]
	bx lr
	.align 2, 0
_02033818: .word MAIN_BSS_020B26A0
	arm_func_end sub_020337EC

	arm_func_start sub_0203381C
sub_0203381C: ; 0x0203381C
	ldr r1, _02033840 ; =MAIN_BSS_020B26A0
	ldr r3, [r0]
	add r1, r1, #0x8000
	mov r2, #1
	mov r0, #0
	str r3, [r1, #0x7c0]
	strb r2, [r1, #0x7bf]
	str r0, [r1, #0x7c4]
	bx lr
	.align 2, 0
_02033840: .word MAIN_BSS_020B26A0
	arm_func_end sub_0203381C

	arm_func_start sub_02033844
sub_02033844: ; 0x02033844
	ldr r1, _02033868 ; =MAIN_BSS_020B26A0
	ldr r3, [r0]
	add r1, r1, #0x8000
	mov r0, #0
	mov r2, #2
	str r0, [r1, #0x7c0]
	strb r2, [r1, #0x7bf]
	str r3, [r1, #0x7c4]
	bx lr
	.align 2, 0
_02033868: .word MAIN_BSS_020B26A0
	arm_func_end sub_02033844

	arm_func_start sub_0203386C
sub_0203386C: ; 0x0203386C
	ldr r1, _02033880 ; =MAIN_BSS_020B26A0
	mov r0, #0
	add r1, r1, #0x8000
	strb r0, [r1, #0x7bf]
	bx lr
	.align 2, 0
_02033880: .word MAIN_BSS_020B26A0
	arm_func_end sub_0203386C

	arm_func_start sub_02033884
sub_02033884: ; 0x02033884
	ldr r0, _0203389C ; =MAIN_BSS_020B26A0
	mov r1, #1
	add r0, r0, #0x8000
	strb r1, [r0, #0x7bf]
	mov r0, #0
	bx lr
	.align 2, 0
_0203389C: .word MAIN_BSS_020B26A0
	arm_func_end sub_02033884

	arm_func_start sub_020338A0
sub_020338A0: ; 0x020338A0
	ldr r0, _020338B8 ; =MAIN_BSS_020B26A0
	mov r1, #2
	add r0, r0, #0x8000
	strb r1, [r0, #0x7bf]
	mov r0, #0
	bx lr
	.align 2, 0
_020338B8: .word MAIN_BSS_020B26A0
	arm_func_end sub_020338A0

	arm_func_start sub_020338BC
sub_020338BC: ; 0x020338BC
	ldr r1, _020338D8 ; =MAIN_BSS_020B26A0
	mov r0, #0
	add r1, r1, #0x7000
	ldr r2, [r1, #0xf60]
	orr r2, r2, #2
	str r2, [r1, #0xf60]
	bx lr
	.align 2, 0
_020338D8: .word MAIN_BSS_020B26A0
	arm_func_end sub_020338BC

	arm_func_start sub_020338DC
sub_020338DC: ; 0x020338DC
	ldr r1, _020338F8 ; =MAIN_BSS_020B26A0
	mov r0, #0
	add r1, r1, #0x7000
	ldr r2, [r1, #0xf60]
	bic r2, r2, #2
	str r2, [r1, #0xf60]
	bx lr
	.align 2, 0
_020338F8: .word MAIN_BSS_020B26A0
	arm_func_end sub_020338DC

	arm_func_start sub_020338FC
sub_020338FC: ; 0x020338FC
	ldr r0, _02033914 ; =MAIN_BSS_020B26A0
	cmp r0, #0
	addne r0, r0, #0x8000
	ldrne r0, [r0, #0x7c0]
	moveq r0, #0
	bx lr
	.align 2, 0
_02033914: .word MAIN_BSS_020B26A0
	arm_func_end sub_020338FC

	arm_func_start sub_02033918
sub_02033918: ; 0x02033918
	ldr r2, _02033930 ; =MAIN_BSS_020B26A0
	ldr r1, [r0]
	add r0, r2, #0x8000
	str r1, [r0, #0x7c0]
	mov r0, #0
	bx lr
	.align 2, 0
_02033930: .word MAIN_BSS_020B26A0
	arm_func_end sub_02033918

	arm_func_start sub_02033934
sub_02033934: ; 0x02033934
	ldr r0, _02033964 ; =MAIN_BSS_020B26A0
	add r0, r0, #0x8000
	ldrb r0, [r0, #0x7bf]
	cmp r0, #0
	beq _02033954
	cmp r0, #1
	cmpne r0, #2
	beq _0203395C
	arm_func_end sub_02033934
_02033954:
	mov r0, #0
	bx lr
_0203395C:
	mov r0, #1
	bx lr
	.align 2, 0
_02033964: .word MAIN_BSS_020B26A0

	arm_func_start sub_02033968
sub_02033968: ; 0x02033968
	stmdb sp!, {r3, lr}
	ldr r0, _02033990 ; =_0208F304
	mov r1, #0x1b
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_0201926C
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02033990: .word s_game
	arm_func_end sub_02033968

	arm_func_start sub_02033994
sub_02033994: ; 0x02033994
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #7
	movgt r0, #1
	ldmgtia sp!, {r4, pc}
	ldr r0, _020339D4 ; =_0208F304
	mov r1, #0x1b
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02019278
	ldr r1, [r4]
	mov r0, r0, asr r1
	and r0, r0, #1
	ldmia sp!, {r4, pc}
	.align 2, 0
_020339D4: .word s_game
	arm_func_end sub_02033994

	arm_func_start sub_020339D8
sub_020339D8: ; 0x020339D8
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4]
	cmp r0, #7
	movgt r0, #1
	ldmgtia sp!, {r4, pc}
	ldr r0, _02033A34 ; =_0208F304
	mov r1, #0x1b
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02019278
	ldr r1, _02033A34 ; =_0208F304
	ldr r2, [r4]
	ldr r1, [r1]
	mov r3, #1
	add r1, r1, #0x1000
	orr r2, r0, r3, lsl r2
	ldr r0, [r1, #0x4b4]
	mov r1, #0x1b
	bl sub_0201926C
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033A34: .word s_game
	arm_func_end sub_020339D8

	arm_func_start sub_02033A38
sub_02033A38: ; 0x02033A38
	stmdb sp!, {r3, lr}
	ldr r1, [r0]
	cmp r1, #3
	bge _02033A68
	ldr r0, _02033A78 ; =_0208F304
	add r1, r1, #0x1c
	ldr r0, [r0]
	mov r2, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_0201926C
	b _02033A70
	arm_func_end sub_02033A38
_02033A68:
	mov r0, #1
	ldmia sp!, {r3, pc}
_02033A70:
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02033A78: .word s_game

	arm_func_start sub_02033A7C
sub_02033A7C: ; 0x02033A7C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4]
	cmp r1, #3
	bge _02033AC8
	ldr r0, [r4, #4]
	cmp r0, #7
	movgt r0, #1
	ldmgtia sp!, {r4, pc}
	ldr r0, _02033AD0 ; =_0208F304
	add r1, r1, #0x1c
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02019278
	ldr r1, [r4, #4]
	mov r0, r0, asr r1
	and r0, r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end sub_02033A7C
_02033AC8:
	mov r0, #1
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033AD0: .word s_game

	arm_func_start sub_02033AD4
sub_02033AD4: ; 0x02033AD4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r1, [r4]
	cmp r1, #3
	bge _02033B3C
	ldr r0, [r4, #4]
	cmp r0, #7
	movgt r0, #1
	ldmgtia sp!, {r4, pc}
	ldr r0, _02033B4C ; =_0208F304
	add r1, r1, #0x1c
	ldr r0, [r0]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x4b4]
	bl sub_02019278
	ldr r1, _02033B4C ; =_0208F304
	ldr r3, [r4]
	ldr r1, [r1]
	ldr r2, [r4, #4]
	mov r4, #1
	add r1, r1, #0x1000
	orr r2, r0, r4, lsl r2
	ldr r0, [r1, #0x4b4]
	add r1, r3, #0x1c
	bl sub_0201926C
	b _02033B44
	arm_func_end sub_02033AD4
_02033B3C:
	mov r0, #1
	ldmia sp!, {r4, pc}
_02033B44:
	mov r0, #0
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033B4C: .word s_game

	arm_func_start sub_02033B50
sub_02033B50: ; 0x02033B50
	stmdb sp!, {r3, lr}
	ldr r0, _02033B68 ; =MAIN_BSS_020B26A0
	mov r1, #1
	bl sub_02016EC4
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02033B68: .word MAIN_BSS_020B26A0
	arm_func_end sub_02033B50

	arm_func_start sub_02033B6C
sub_02033B6C: ; 0x02033B6C
	stmdb sp!, {r3, lr}
	ldr r0, _02033BB8 ; =MAIN_BSS_0210CA3C
	ldr r0, [r0]
	cmp r0, #0
	bne _02033BA0
	mov r0, #0x74
	bl _Znwm
	cmp r0, #0
	beq _02033B98
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
	arm_func_end sub_02033B6C
_02033B98:
	ldr r1, _02033BB8 ; =MAIN_BSS_0210CA3C
	str r0, [r1]
_02033BA0:
	ldr r0, _02033BB8 ; =MAIN_BSS_0210CA3C
	mov r1, #0
	ldr r0, [r0]
	bl sub_02028408
	mov r0, #0
	ldmia sp!, {r3, pc}
	.align 2, 0
_02033BB8: .word MAIN_BSS_0210CA3C

	arm_func_start sub_02033BBC
sub_02033BBC: ; 0x02033BBC
	stmdb sp!, {r3, r4, r5, lr}
	ldr r0, _02033C2C ; =MAIN_BSS_0210CA3C
	ldr r0, [r0]
	cmp r0, #0
	beq _02033C24
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	movs r4, r0
	beq _02033C1C
	ldr r0, _02033C2C ; =MAIN_BSS_0210CA3C
	ldr r5, [r0]
	cmp r5, #0
	beq _02033C0C
	beq _02033C00
	mov r0, r5
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end sub_02033BBC
_02033C00:
	ldr r0, _02033C2C ; =MAIN_BSS_0210CA3C
	mov r1, #0
	str r1, [r0]
_02033C0C:
	tst r4, #0x80
	moveq r0, #1
	movne r0, #2
	ldmia sp!, {r3, r4, r5, pc}
_02033C1C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
_02033C24:
	mov r0, #2
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02033C2C: .word MAIN_BSS_0210CA3C

	arm_func_start sub_02033C30
sub_02033C30: ; 0x02033C30
	ldr r0, _02033C48 ; =MAIN_BSS_020B26A0
	cmp r0, #0
	addne r0, r0, #0x8000
	ldrne r0, [r0, #0x764]
	moveq r0, #0
	bx lr
	.align 2, 0
_02033C48: .word MAIN_BSS_020B26A0
	arm_func_end sub_02033C30

	arm_func_start sub_02033C4C
sub_02033C4C: ; 0x02033C4C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02033EB0
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02033C4C

	arm_func_start sub_02033C60
sub_02033C60: ; 0x02033C60
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #0xc
	mov r6, r0
	mov r5, r2
	mov r4, r3
	bl OS_SPrintf
	mov r0, r6
	bl sub_02033ED4
	mov r0, r6
	bl sub_02033EB0
	mov r0, #0xb8
	bl _Znwm
	cmp r0, #0
	beq _02033CB4
	mov r2, #0
	ldr ip, [sp, #0x20]
	str r5, [sp]
	mov r1, r6
	mov r3, r2
	stmib sp, {r4, ip}
	bl _ZN11CBinaryFileC1EPKcmmmPvm
	arm_func_end sub_02033C60
_02033CB4:
	str r0, [r6, #0x28]
	ldr r0, [r0, #0x4c]
	str r0, [r6, #0x20]
	cmp r0, #0
	bne _02033CDC
	mov r0, r6
	bl sub_02033ED4
	add sp, sp, #0xc
	mov r0, #1
	ldmia sp!, {r3, r4, r5, r6, pc}
_02033CDC:
	str r0, [r6, #0x24]
	bl sub_02044AC8
	add r0, r6, #0x3c
	add r1, r6, #0x60
	mov r2, #0x80
	bl sub_02044B48
	mov r0, #0
	add sp, sp, #0xc
	ldmia sp!, {r3, r4, r5, r6, pc}

	arm_func_start sub_02033D00
sub_02033D00: ; 0x02033D00
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	mov r4, r2
	bl sub_02033ED4
	mov r0, r6
	bl sub_02033EB0
	cmp r5, #0
	moveq r0, #1
	ldmeqia sp!, {r4, r5, r6, pc}
	str r5, [r6, #0x20]
	str r5, [r6, #0x24]
	cmp r4, #0
	bne _02033D40
	ldr r0, [r6, #0x24]
	bl sub_02044AC8
	arm_func_end sub_02033D00
_02033D40:
	add r0, r6, #0x3c
	add r1, r6, #0x60
	mov r2, #0x80
	bl sub_02044B48
	mov r0, #0
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start sub_02033D58
sub_02033D58: ; 0x02033D58
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x20]
	mov r4, r1
	cmp r0, #0
	moveq r0, #1
	ldmeqia sp!, {r3, r4, r5, pc}
	mov r0, r4
	bl strlen
	cmp r0, #0xc
	bls _02033D88
	bl OS_Terminate
	arm_func_end sub_02033D58
_02033D88:
	mov r1, r4
	add r0, r5, #0x2c
	mov r2, #0xd
	bl OS_SPrintf
	add r0, r5, #0x3c
	bl sub_02044B84
	ldr r1, [r5, #0x24]
	add r0, r5, #0x3c
	add r2, r5, #0x2c
	bl sub_02045A18
	mov r0, #1
	str r0, [r5, #0x260]
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02033DC0
sub_02033DC0: ; 0x02033DC0
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r1
	mov r5, r0
	mov r0, r4
	bl strlen
	cmp r0, #0xc
	bls _02033DE0
	bl OS_Terminate
	arm_func_end sub_02033DC0
_02033DE0:
	mov r1, r4
	add r0, r5, #0x264
	mov r2, #0xd
	bl OS_SPrintf
	mov r0, #1
	str r0, [r5, #0x274]
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02033DFC
sub_02033DFC: ; 0x02033DFC
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x20]
	cmp r0, #0
	moveq r0, #1
	ldmeqia sp!, {r4, pc}
	add r0, r4, #0x2c
	add r1, r4, #0x264
	mov r2, #0xd
	bl OS_SPrintf
	add r0, r4, #0x3c
	bl sub_02044B84
	ldr r1, [r4, #0x24]
	add r0, r4, #0x3c
	add r2, r4, #0x2c
	bl sub_02045A18
	mov r0, #1
	str r0, [r4, #0x260]
	mov r0, #0
	str r0, [r4, #0x274]
	ldmia sp!, {r4, pc}
	arm_func_end sub_02033DFC

	arm_func_start sub_02033E50
sub_02033E50: ; 0x02033E50
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02033ED4
	mov r0, r4
	bl sub_02033EB0
	ldmia sp!, {r4, pc}
	arm_func_end sub_02033E50

	arm_func_start sub_02033E68
sub_02033E68: ; 0x02033E68
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x260]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	ldr r1, _02033EAC ; =0x000FFFFF
	add r0, r4, #0x3c
	bl sub_02044C9C
	tst r0, #2
	movne r0, #0
	strne r0, [r4, #0x260]
	ldmneia sp!, {r4, pc}
	ldr r0, [r4, #0x260]
	cmp r0, #1
	moveq r0, #2
	streq r0, [r4, #0x260]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02033EAC: .word 0x000FFFFF
	arm_func_end sub_02033E68

	arm_func_start sub_02033EB0
sub_02033EB0: ; 0x02033EB0
	mov r1, #0
	str r1, [r0, #0x20]
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	str r1, [r0, #0x260]
	str r1, [r0, #0x274]
	sub r1, r1, #1
	str r1, [r0, #0x278]
	bx lr
	arm_func_end sub_02033EB0

	arm_func_start sub_02033ED4
sub_02033ED4: ; 0x02033ED4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x28]
	cmp r0, #0
	ldmeqia sp!, {r4, pc}
	beq _02033EF8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	arm_func_end sub_02033ED4
_02033EF8:
	mov r0, #0
	str r0, [r4, #0x28]
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_02033F04C1Em
_ZN17UnkClass_02033F04C1Em: ; 0x02033F04
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl _Z12sub_02044440v
	ldr r1, _02033F8C ; =PTR_LAB_0208ce10
	mov r0, #2
	str r4, [r5]
	bl sub_02044B38
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F38
	bl sub_02033C4C
	arm_func_end _ZN17UnkClass_02033F04C1Em
_02033F38:
	str r0, [r5, #4]
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F50
	bl sub_02033C4C
_02033F50:
	str r0, [r5, #8]
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F68
	bl sub_02033C4C
_02033F68:
	str r0, [r5, #0xc]
	mov r0, #0x27c
	bl _Znwm
	cmp r0, #0
	beq _02033F80
	bl sub_02033C4C
_02033F80:
	str r0, [r5, #0x10]
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02033F8C: .word PTR_LAB_0208ce10

	arm_func_start sub_02033F90
sub_02033F90: ; 0x02033F90
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #4]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r3, #0
	cmp r4, r1
	beq _02034008
	cmp r4, #0
	ble _02033FE8
	ldr r1, _02034014 ; =s_data_Script_system_system_03d_fs_0208d4b4
	add r0, sp, #4
	mov r2, r4
	bl OS_SPrintf
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #4]
	ldr r2, [r5]
	add r1, sp, #4
	bl sub_02033C60
	b _02033FF8
	arm_func_end sub_02033F90
_02033FE8:
	str r3, [sp]
	ldr r2, [r5]
	ldr r1, _02034018 ; =s_data_Script_system_system_fsb_0208d4d8
	bl sub_02033C60
_02033FF8:
	mov r3, r0
	cmp r3, #0
	ldreq r0, [r5, #4]
	streq r4, [r0, #0x278]
_02034008:
	mov r0, r3
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034014: .word s_data_Script_system_system_03d_fs_0208d4b4
_02034018: .word s_data_Script_system_system_fsb_0208d4d8

	arm_func_start sub_0203401C
sub_0203401C: ; 0x0203401C
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #8]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r0, #0
	cmp r4, r1
	addeq sp, sp, #0x44
	ldmeqia sp!, {r4, r5, pc}
	ldr r1, _02034080 ; =s_data_Script_area_m_03d_fsb_0208d4f8
	add r0, sp, #4
	mov r2, r4
	bl OS_SPrintf
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #8]
	ldr r2, [r5]
	add r1, sp, #4
	bl sub_02033C60
	cmp r0, #0
	ldreq r1, [r5, #8]
	streq r4, [r1, #0x278]
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034080: .word s_data_Script_area_m_03d_fsb_0208d4f8
	arm_func_end sub_0203401C

	arm_func_start sub_02034084
sub_02034084: ; 0x02034084
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #0xc]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r0, #0
	cmp r4, r1
	addeq sp, sp, #0x44
	ldmeqia sp!, {r4, r5, pc}
	cmp r4, #0x46
	add r0, sp, #4
	bge _020340F4
	ldr r1, _02034118 ; =s_data_Script_chapter_c_03d_fsb_0208d514
	mov r2, r4
	bl OS_SPrintf
	mov r0, #0x18800
	str r0, [sp]
	ldr r0, [r5, #0xc]
	ldr r2, [r5]
	add r1, sp, #4
	add r3, r5, #0x1c
	bl sub_02033C60
	cmp r0, #0
	ldreq r1, [r5, #0xc]
	add sp, sp, #0x44
	streq r4, [r1, #0x278]
	ldmia sp!, {r4, r5, pc}
	arm_func_end sub_02034084
_020340F4:
	ldr r1, _0203411C ; =s_data_Script_chapter_cx_02d_fsb_0208d534
	sub r2, r4, #0x45
	bl OS_SPrintf
	ldr r0, [r5, #0xc]
	add r1, r5, #0x1c
	mov r2, #1
	bl sub_02033D00
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034118: .word s_data_Script_chapter_c_03d_fsb_0208d514
_0203411C: .word s_data_Script_chapter_cx_02d_fsb_0208d534

	arm_func_start sub_02034120
sub_02034120: ; 0x02034120
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x44
	mov r5, r0
	ldr r0, [r5, #0x10]
	mov r4, r1
	ldr r1, [r0, #0x278]
	mov r0, #0
	cmp r4, r1
	beq _0203416C
	ldr r1, _02034180 ; =s_data_Script_quest_q_03d_fsb_0208d554
	add r0, sp, #4
	mov r2, r4
	bl OS_SPrintf
	mov r3, #0
	str r3, [sp]
	ldr r0, [r5, #0x10]
	ldr r2, [r5]
	add r1, sp, #4
	bl sub_02033C60
	arm_func_end sub_02034120
_0203416C:
	cmp r0, #0
	ldreq r1, [r5, #0x10]
	streq r4, [r1, #0x278]
	add sp, sp, #0x44
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02034180: .word s_data_Script_quest_q_03d_fsb_0208d554

	arm_func_start sub_02034184
sub_02034184: ; 0x02034184
	stmdb sp!, {r3, lr}
	ldrsb r2, [r1]
	cmp r2, #0x71
	bgt _020341B8
	bge _020341FC
	cmp r2, #0x63
	bgt _02034210
	cmp r2, #0x61
	blt _02034210
	beq _020341D4
	cmp r2, #0x63
	beq _020341E8
	b _02034210
	arm_func_end sub_02034184
_020341B8:
	cmp r2, #0x73
	bne _02034210
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #4]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_020341D4:
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #8]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_020341E8:
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #0xc]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_020341FC:
	mov r2, #0
	str r2, [r0, #0x18]
	ldr r0, [r0, #0x10]
	bl sub_02033D58
	ldmia sp!, {r3, pc}
_02034210:
	bl OS_Terminate
	mov r0, #1
	ldmia sp!, {r3, pc}

	arm_func_start sub_0203421C
sub_0203421C: ; 0x0203421C
	stmdb sp!, {r3, lr}
	ldrsb r2, [r1]
	cmp r2, #0x71
	bgt _02034250
	bge _0203427C
	cmp r2, #0x63
	bgt _02034288
	cmp r2, #0x61
	blt _02034288
	beq _02034264
	cmp r2, #0x63
	beq _02034270
	b _02034288
	arm_func_end sub_0203421C
_02034250:
	cmp r2, #0x73
	bne _02034288
	ldr r0, [r0, #4]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_02034264:
	ldr r0, [r0, #8]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_02034270:
	ldr r0, [r0, #0xc]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_0203427C:
	ldr r0, [r0, #0x10]
	bl sub_02033DC0
	ldmia sp!, {r3, pc}
_02034288:
	bl OS_Terminate
	ldmia sp!, {r3, pc}

	arm_func_start sub_02034290
sub_02034290: ; 0x02034290
	ldr ip, _0203429C ; =sub_02033E50
	ldr r0, [r0, #4]
	bx ip
	.align 2, 0
_0203429C: .word sub_02033E50
	arm_func_end sub_02034290

	arm_func_start sub_020342A0
sub_020342A0: ; 0x020342A0
	ldr ip, _020342AC ; =sub_02033E50
	ldr r0, [r0, #8]
	bx ip
	.align 2, 0
_020342AC: .word sub_02033E50
	arm_func_end sub_020342A0

	arm_func_start sub_020342B0
sub_020342B0: ; 0x020342B0
	ldr ip, _020342BC ; =sub_02033E50
	ldr r0, [r0, #0xc]
	bx ip
	.align 2, 0
_020342BC: .word sub_02033E50
	arm_func_end sub_020342B0

	arm_func_start sub_020342C0
sub_020342C0: ; 0x020342C0
	ldr ip, _020342CC ; =sub_02033E50
	ldr r0, [r0, #0x10]
	bx ip
	.align 2, 0
_020342CC: .word sub_02033E50
	arm_func_end sub_020342C0

	arm_func_start sub_020342D0
sub_020342D0: ; 0x020342D0
	stmdb sp!, {r3, lr}
	ldmib r0, {r1, lr}
	ldr r2, [r1, #0x260]
	ldr r3, [r0, #0x18]
	ldr ip, [r0, #0xc]
	orr r2, r3, r2
	ldr r1, [r1, #0x274]
	ldr r3, [lr, #0x260]
	orr r1, r2, r1
	orr r1, r3, r1
	ldr r2, [lr, #0x274]
	ldr r0, [r0, #0x10]
	orr r1, r2, r1
	ldr r3, [ip, #0x260]
	ldr r2, [ip, #0x274]
	orr r1, r3, r1
	orr r1, r2, r1
	ldr r3, [r0, #0x260]
	ldr r2, [r0, #0x274]
	orr r0, r3, r1
	orr r0, r2, r0
	ldmia sp!, {r3, pc}
	arm_func_end sub_020342D0

	arm_func_start sub_02034328
sub_02034328: ; 0x02034328
	stmdb sp!, {r4, lr}
	ldmib r0, {r1, r4, lr}
	ldr r2, [r1, #0x260]
	ldr r1, [r1, #0x274]
	ldr ip, [r0, #0x10]
	orr r0, r2, r1
	ldr r3, [r4, #0x260]
	ldr r1, [r4, #0x274]
	orr r0, r3, r0
	orr r0, r1, r0
	ldr r2, [lr, #0x260]
	ldr r1, [lr, #0x274]
	orr r0, r2, r0
	orr r0, r1, r0
	ldr r2, [ip, #0x260]
	ldr r1, [ip, #0x274]
	orr r0, r2, r0
	orr r0, r1, r0
	ldmia sp!, {r4, pc}
	arm_func_end sub_02034328

	arm_func_start sub_02034374
sub_02034374: ; 0x02034374
	str r1, [r0, #0x14]
	bx lr
	arm_func_end sub_02034374

	arm_func_start sub_0203437C
sub_0203437C: ; 0x0203437C
	ldr r0, [r0, #0x14]
	bx lr
	arm_func_end sub_0203437C

	arm_func_start sub_02034384
sub_02034384: ; 0x02034384
	stmdb sp!, {r3, lr}
	ldr ip, [r0, #4]
	ldr r1, [ip, #0x260]
	cmp r1, #0
	beq _020343A4
	mov r0, ip
	bl sub_02033E68
	ldmia sp!, {r3, pc}
	arm_func_end sub_02034384
_020343A4:
	ldr r3, [r0, #8]
	ldr r1, [r3, #0x260]
	cmp r1, #0
	beq _020343C0
	mov r0, r3
	bl sub_02033E68
	ldmia sp!, {r3, pc}
_020343C0:
	ldr r2, [r0, #0xc]
	ldr r1, [r2, #0x260]
	cmp r1, #0
	beq _020343DC
	mov r0, r2
	bl sub_02033E68
	ldmia sp!, {r3, pc}
_020343DC:
	ldr r0, [r0, #0x10]
	ldr r1, [r0, #0x260]
	cmp r1, #0
	beq _020343F4
	bl sub_02033E68
	ldmia sp!, {r3, pc}
_020343F4:
	ldr r1, [ip, #0x274]
	cmp r1, #0
	beq _0203440C
	mov r0, ip
	bl sub_02033DFC
	ldmia sp!, {r3, pc}
_0203440C:
	ldr r1, [r3, #0x274]
	cmp r1, #0
	beq _02034424
	mov r0, r3
	bl sub_02033DFC
	ldmia sp!, {r3, pc}
_02034424:
	ldr r1, [r2, #0x274]
	cmp r1, #0
	beq _0203443C
	mov r0, r2
	bl sub_02033DFC
	ldmia sp!, {r3, pc}
_0203443C:
	ldr r1, [r0, #0x274]
	cmp r1, #0
	ldmeqia sp!, {r3, pc}
	bl sub_02033DFC
	ldmia sp!, {r3, pc}

	arm_func_start sub_02034450
sub_02034450: ; 0x02034450
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_02034290
	mov r0, r4
	bl sub_020342A0
	mov r0, r4
	bl sub_020342B0
	mov r0, r4
	bl sub_020342C0
	ldmia sp!, {r4, pc}
	arm_func_end sub_02034450
