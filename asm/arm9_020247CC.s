    .include "macros.inc"
    .include "include/arm9_020247CC.inc"

    .text

	arm_func_start _ZN17UnkClass_020247CCC1Ev
_ZN17UnkClass_020247CCC1Ev: ; 0x020247CC
	stmdb sp!, {r4, lr}
	mov r3, #0
	mov r4, r0
	str r3, [r4, #0x20]
	str r3, [r4, #0x24]
	str r3, [r4, #0x28]
	str r3, [r4, #0x2c]
	mov r2, r3
	arm_func_end _ZN17UnkClass_020247CCC1Ev
_020247EC:
	str r2, [r4, r3, lsl #2]
	add r1, r4, r3, lsl #1
	add r0, r4, r3
	strh r2, [r1, #0x30]
	strb r2, [r0, #0x40]
	add r3, r3, #1
	strb r2, [r0, #0x48]
	cmp r3, #8
	blt _020247EC
	str r2, [r4, #0x50]
	str r2, [r4, #0x54]
	str r2, [r4, #0x58]
	str r2, [r4, #0x74]
	str r2, [r4, #0x68]
	str r2, [r4, #0x6c]
	str r2, [r4, #0x70]
	str r2, [r4, #0x60]
	mov r0, r4
	str r2, [r4, #0x64]
	bl sub_02024D00
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start _ZN17UnkClass_020247CCD1Ev
_ZN17UnkClass_020247CCD1Ev: ; 0x02024844
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	bl _ZN17UnkClass_020247CC12sub_02024A2CEv
	ldr r0, [r5, #0x50]
	bl _ZN17UnkClass_0200ECD012sub_0200F4A8Ev
	ldr r0, [r5, #0x54]
	bl _ZN17UnkClass_0200ECD012sub_0200F4A8Ev
	ldr r0, [r5, #0x58]
	bl _ZN17UnkClass_0200ECD012sub_0200F4A8Ev
	ldr r4, [r5, #0x50]
	cmp r4, #0
	beq _02024890
	beq _02024888
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end _ZN17UnkClass_020247CCD1Ev
_02024888:
	mov r0, #0
	str r0, [r5, #0x50]
_02024890:
	ldr r4, [r5, #0x54]
	cmp r4, #0
	beq _020248B8
	beq _020248B0
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_020248B0:
	mov r0, #0
	str r0, [r5, #0x54]
_020248B8:
	ldr r4, [r5, #0x58]
	cmp r4, #0
	beq _020248E0
	beq _020248D8
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_020248D8:
	mov r0, #0
	str r0, [r5, #0x58]
_020248E0:
	ldr r1, [r5, #0x74]
	cmp r1, #0
	beq _02024970
	ldr r0, [r1, #4]
	mov r4, #0
	cmp r0, #0
	bls _0202493C
	mov r6, r4
_02024900:
	ldr r0, [r1, #8]
	add r0, r0, r4, lsl #3
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _02024928
	bl _ZdaPv
	ldr r0, [r5, #0x74]
	ldr r0, [r0, #8]
	add r0, r0, r4, lsl #3
	str r6, [r0, #4]
_02024928:
	ldr r1, [r5, #0x74]
	add r4, r4, #1
	ldr r0, [r1, #4]
	cmp r4, r0
	blo _02024900
_0202493C:
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02024958
	bl _ZdaPv
	ldr r0, [r5, #0x74]
	mov r1, #0
	str r1, [r0, #8]
_02024958:
	ldr r0, [r5, #0x74]
	cmp r0, #0
	beq _02024970
	bl _ZdlPv
	mov r0, #0
	str r0, [r5, #0x74]
_02024970:
	ldr r0, [r5, #0x68]
	cmp r0, #0
	beq _02024994
	beq _0202498C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_0202498C:
	mov r0, #0
	str r0, [r5, #0x68]
_02024994:
	ldr r0, [r5, #0x6c]
	cmp r0, #0
	beq _020249B8
	beq _020249B0
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020249B0:
	mov r0, #0
	str r0, [r5, #0x6c]
_020249B8:
	ldr r0, [r5, #0x70]
	cmp r0, #0
	beq _020249DC
	beq _020249D4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020249D4:
	mov r0, #0
	str r0, [r5, #0x70]
_020249DC:
	ldr r0, [r5, #0x60]
	cmp r0, #0
	beq _02024A00
	beq _020249F8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_020249F8:
	mov r0, #0
	str r0, [r5, #0x60]
_02024A00:
	ldr r0, [r5, #0x64]
	cmp r0, #0
	beq _02024A24
	beq _02024A1C
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02024A1C:
	mov r0, #0
	str r0, [r5, #0x64]
_02024A24:
	mov r0, r5
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17UnkClass_020247CC12sub_02024A2CEv
_ZN17UnkClass_020247CC12sub_02024A2CEv: ; 0x02024A2C
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CAE0Ev
	ldr r0, [r4, #0x50]
	bl _ZN17UnkClass_0200ECD012sub_0200F6C4Ev
	ldr r0, [r4, #0x54]
	bl _ZN17UnkClass_0200ECD012sub_0200F6C4Ev
	ldr r0, [r4, #0x58]
	bl _ZN17UnkClass_0200ECD012sub_0200F6C4Ev
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_020247CC12sub_02024A2CEv

	arm_func_start _ZN17UnkClass_020247CC12sub_02024A60Ev
_ZN17UnkClass_020247CC12sub_02024A60Ev: ; 0x02024A60
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x14
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	mov lr, #0
	str lr, [r4, #0x20]
	ldr r1, _02024CF4 ; =MAIN_BSS_0210CA4C
	str lr, [r4, #0x24]
	ldr r8, [r1]
	str r0, [sp, #4]
	cmp r8, #0
	beq _02024B3C
	ldr r0, [r8, #0x88]
	mov r5, #1
	str r0, [r4, #0x28]
	cmp r0, #0
	ldr ip, [r8, #0x84]
	ble _02024B3C
	mov r2, lr
	mov fp, lr
	mov r0, r5
	mov r3, lr
	arm_func_end _ZN17UnkClass_020247CC12sub_02024A60Ev
_02024AB8:
	ldr sb, [r8, #4]
	mov r6, r3
	cmp sb, #0
	ble _02024AFC
	add r7, ip, lr
_02024ACC:
	cmp sb, r6
	ldrgt r1, [r8, #8]
	movle sl, r2
	ldrgt sl, [r1, r6, lsl #2]
	cmp sl, #0
	beq _02024AF0
	ldr r1, [sl, #0x1e8]
	cmp r7, r1
	beq _02024B00
_02024AF0:
	add r6, r6, #1
	cmp r6, sb
	blt _02024ACC
_02024AFC:
	mov sl, fp
_02024B00:
	cmp sl, #0
	beq _02024B2C
	ldr r1, [sl, #4]
	tst r1, #0x20
	ldreq r1, [sl, #0x200]
	streq r1, [r4, r5, lsl #2]
	addeq r5, r5, #1
	beq _02024B2C
	str r0, [r4, #0x20]
	ldr r1, [sl, #0x200]
	str r1, [r4]
_02024B2C:
	ldr r1, [r4, #0x28]
	add lr, lr, #1
	cmp lr, r1
	blt _02024AB8
_02024B3C:
	ldr r5, _02024CF8 ; =MAIN_BSS_020B26A0
	ldrb r1, [r5, #3]
	mov r0, r5
	and r1, r1, #0xf
	bl sub_02015658
	str r0, [r4, #0x2c]
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _02024B78
	ldr r0, [r4]
	bl sub_02035088
	add r0, r5, r0
	ldrb r0, [r0, #9]
	add r0, r0, #1
	str r0, [r4, #0x24]
_02024B78:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _02024BC4
	ldr r1, [r4, #0x28]
	ldr r0, [sp, #4]
	sub r1, r1, #1
	str r1, [r4, #0x28]
	ldr r1, [r4]
	add r0, r0, #0x1000
	mov r1, r1, lsl #0x10
	ldr r0, [r0, #0x434]
	mov r1, r1, lsr #0x10
	bl sub_020107A8
	ldrh r1, [r0]
	strh r1, [r4, #0x30]
	ldrb r1, [r0, #5]
	strb r1, [r4, #0x40]
	ldrb r0, [r0, #6]
	strb r0, [r4, #0x48]
_02024BC4:
	ldr r0, [r4, #0x28]
	mov r5, #1
	cmp r0, #1
	blt _02024C20
	ldr r0, [sp, #4]
	add r6, r0, #0x1000
_02024BDC:
	ldr r1, [r4, r5, lsl #2]
	ldr r0, [r6, #0x434]
	mov r1, r1, lsl #0x10
	mov r1, r1, lsr #0x10
	bl sub_020107A8
	ldrh r3, [r0]
	add r1, r4, r5, lsl #1
	add r2, r4, r5
	strh r3, [r1, #0x30]
	ldrb r1, [r0, #5]
	add r5, r5, #1
	strb r1, [r2, #0x40]
	ldrb r0, [r0, #6]
	strb r0, [r2, #0x48]
	ldr r0, [r4, #0x28]
	cmp r5, r0
	ble _02024BDC
_02024C20:
	ldrh r2, [r4, #0x30]
	ldr r1, _02024CFC ; =s_bp_03d_0208bf0c
	add r0, sp, #8
	bl OS_SPrintf
	ldr r0, [r4, #0x50]
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
	ldr r0, [r4, #0x54]
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
	ldr r0, [r4, #0x28]
	mov r8, #1
	cmp r0, #1
	blt _02024CAC
	mov r7, #0
	mov sb, #0x40
	mov r6, #0xd0
	mov r5, r7
	mov fp, #0xdc
_02024C64:
	str r7, [sp]
	add sl, r4, r8
	ldrb r1, [sl, #0x40]
	ldr r0, [r4, #0x50]
	mov r2, r6
	mov r3, sb
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r5, [sp]
	ldrb r1, [sl, #0x48]
	ldr r0, [r4, #0x54]
	mov r2, fp
	mov r3, sb
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	ldr r0, [r4, #0x28]
	add r8, r8, #1
	cmp r8, r0
	add sb, sb, #0x10
	ble _02024C64
_02024CAC:
	ldr r0, [r4, #0x58]
	bl _ZN17UnkClass_0200ECD012sub_0200F398Ev
	mov r0, #3
	str r0, [sp]
	mov r2, #0x80
	ldr r0, [r4, #0x58]
	sub r3, r2, #0x88
	mov r1, #0
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [r4, #0x5c]
	mov r0, r4
	bl sub_02025068
	mov r0, r4
	bl sub_0202510C
	mov r0, r4
	bl sub_0202524C
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02024CF4: .word MAIN_BSS_0210CA4C
_02024CF8: .word MAIN_BSS_020B26A0
_02024CFC: .word s_bp_03d_0208bf0c

	arm_func_start sub_02024D00
sub_02024D00: ; 0x02024D00
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	sub sp, sp, #0x10
	mov r7, r0
	mov r0, #0xb8
	bl _Znwm
	movs r6, r0
	beq _02024D2C
	ldr r1, _02025038 ; =s_data_message_etc_menu_mes_0208bf14
	mov r2, #1
	bl _ZN14CBinaryFileMesC1EPKcm
	mov r6, r0
	arm_func_end sub_02024D00
_02024D2C:
	mov r0, #0xc
	bl _Znwm
	str r0, [r7, #0x74]
	ldr r1, [r6, #0x4c]
	mov r4, #2
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r6, #0x4c]
	ldr r0, [r7, #0x74]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	ldr r0, [r7, #0x74]
	ldr r0, [r0, #4]
	mov r0, r0, lsl #3
	bl _Znam
	ldr r1, [r7, #0x74]
	mov r5, #0
	str r0, [r1, #8]
	ldr r2, [r7, #0x74]
	ldr r0, [r2, #4]
	cmp r0, #0
	bls _02024DF4
_02024D84:
	ldr r1, [r6, #0x4c]
	ldr r0, [r2, #8]
	ldr r1, [r1, r4, lsl #2]
	add r4, r4, #1
	str r1, [r0, r5, lsl #3]
	ldr r0, [r7, #0x74]
	ldr r0, [r0, #8]
	ldr r0, [r0, r5, lsl #3]
	bl _Znam
	ldr r1, [r7, #0x74]
	ldr r1, [r1, #8]
	add r1, r1, r5, lsl #3
	str r0, [r1, #4]
	ldr r1, [r7, #0x74]
	ldr r0, [r6, #0x4c]
	ldr r2, [r1, #8]
	add r0, r0, r4, lsl #2
	add r1, r2, r5, lsl #3
	ldr r1, [r1, #4]
	ldr r2, [r2, r5, lsl #3]
	bl MIi_CpuCopyFast
	ldr r2, [r7, #0x74]
	ldmib r2, {r0, r1}
	ldr r1, [r1, r5, lsl #3]
	add r5, r5, #1
	cmp r5, r0
	add r4, r4, r1, lsr #2
	blo _02024D84
_02024DF4:
	cmp r6, #0
	beq _02024E0C
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02024E0C:
	mov r0, #0x6c
	bl _Znwm
	movs r4, r0
	beq _02024E44
	mov r3, #1
	str r3, [sp]
	mov r4, #0
	str r4, [sp, #4]
	str r4, [sp, #8]
	ldr r1, _0202503C ; =s_BGS_0208bf30
	ldr r2, _02025040 ; =s_data_menu_mc000_bg_LZ_bin_0208bf34
	str r4, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r4, r0
_02024E44:
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02024E68
	mov r2, #0
	ldr r1, _02025044 ; =s_BGS_mc000_NCGR_0208bf50
	mov r3, r2
	str r2, [sp]
	bl _ZN11CBGNCGRFileC1EPKcmmm
_02024E68:
	str r0, [r7, #0x60]
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02024E90
	mov r2, #0
	ldr r1, _02025048 ; =s_BGS_mc000_NCLR_0208bf60
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNCLRFileC1EPKcmmm
_02024E90:
	str r0, [r7, #0x64]
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02024EB8
	mov r2, #0
	ldr r1, _0202504C ; =s_BGS_mc000_01_NSCR_0208bf70
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
_02024EB8:
	str r0, [r7, #0x68]
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02024EE0
	mov r2, #0
	ldr r1, _02025050 ; =s_BGS_mc000_02_NSCR_0208bf84
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
_02024EE0:
	str r0, [r7, #0x6c]
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02024F08
	mov r2, #0
	ldr r1, _02025054 ; =s_BGS_mc000_03_NSCR_0208bf98
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
_02024F08:
	str r0, [r7, #0x70]
	cmp r4, #0
	beq _02024F24
	mov r0, r4
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r4
	bl _ZdlPv
_02024F24:
	mov r5, #0
	bl _ZN5CGame11GetInstanceEv
	mov r6, r0
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02024F60
	mov r1, #0x40
	str r1, [sp]
	add r2, r6, #0x1000
	add r1, r6, #0x24
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02024F60:
	str r0, [r7, #0x50]
	mov r3, #0
	str r3, [sp]
	ldr r0, [r7, #0x50]
	ldr r1, _02025058 ; =s_data_menu_0208bfac
	ldr r2, _0202505C ; =s_ma000_00_0208bfb8
	bl _ZN17UnkClass_0200ECD012sub_0200F168EPKcS1_mm
	ldr r1, [r7, #0x50]
	mov r0, #0x44
	ldr r1, [r1, #0x28]
	add r5, r5, r1
	bl _Znwm
	cmp r0, #0
	beq _02024FB8
	mov r1, #0x40
	str r1, [sp]
	add r2, r6, #0x1000
	add r1, r6, #0xa4
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02024FB8:
	str r0, [r7, #0x54]
	mov r0, #3
	str r0, [sp]
	ldr r0, [r7, #0x54]
	ldr r1, _02025058 ; =s_data_menu_0208bfac
	ldr r2, _02025060 ; =s_ma001_00_0208bfc4
	mov r3, r5
	bl _ZN17UnkClass_0200ECD012sub_0200F168EPKcS1_mm
	ldr r1, [r7, #0x54]
	mov r0, #0x44
	ldr r4, [r1, #0x28]
	bl _Znwm
	cmp r0, #0
	beq _02025010
	mov r1, #0x40
	str r1, [sp]
	add r2, r6, #0x1000
	add r1, r6, #0x2a4
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02025010:
	str r0, [r7, #0x58]
	mov r0, #8
	str r0, [sp]
	ldr r0, [r7, #0x58]
	ldr r1, _02025058 ; =s_data_menu_0208bfac
	ldr r2, _02025064 ; =s_ma004_00_0208bfd0
	add r3, r5, r4
	bl _ZN17UnkClass_0200ECD012sub_0200F168EPKcS1_mm
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02025038: .word s_data_message_etc_menu_mes_0208bf14
_0202503C: .word s_BGS_0208bf30
_02025040: .word s_data_menu_mc000_bg_LZ_bin_0208bf34
_02025044: .word s_BGS_mc000_NCGR_0208bf50
_02025048: .word s_BGS_mc000_NCLR_0208bf60
_0202504C: .word s_BGS_mc000_01_NSCR_0208bf70
_02025050: .word s_BGS_mc000_02_NSCR_0208bf84
_02025054: .word s_BGS_mc000_03_NSCR_0208bf98
_02025058: .word s_data_menu_0208bfac
_0202505C: .word s_ma000_00_0208bfb8
_02025060: .word s_ma001_00_0208bfc4
_02025064: .word s_ma004_00_0208bfd0

	arm_func_start sub_02025068
sub_02025068: ; 0x02025068
	stmdb sp!, {r4, lr}
	sub sp, sp, #0x10
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r1, #0xd
	str r1, [sp, #8]
	mov r4, r0
	str r2, [sp, #0xc]
	ldr r1, [r4, #0x68]
	ldr r2, [r4, #0x60]
	ldr r0, [r4, #0x64]
	ldr r1, [r1, #0xb8]
	ldr r2, [r2, #0xb8]
	ldr r3, [r0, #0xb8]
	mov r0, #5
	bl NNS_G2dBGSetupEx
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r0, #0xe
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r4, #0x6c]
	mov r3, r2
	ldr r1, [r0, #0xb8]
	mov r0, #6
	bl NNS_G2dBGSetupEx
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r0, #0xf
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r4, #0x70]
	mov r3, r2
	ldr r1, [r0, #0xb8]
	mov r0, #7
	bl NNS_G2dBGSetupEx
	add sp, sp, #0x10
	ldmia sp!, {r4, pc}
	arm_func_end sub_02025068

	arm_func_start sub_0202510C
sub_0202510C: ; 0x0202510C
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov r7, r0
	ldr r0, [r7, #0x20]
	cmp r0, #1
	bne _0202513C
	bl G2S_GetBG1ScrPtr
	mov r4, r0
	bl G2S_GetBG1ScrPtr
	add r0, r0, #0x600
	add r1, r4, #0xc0
	mov r2, #0x100
	bl MIi_CpuCopyFast
	arm_func_end sub_0202510C
_0202513C:
	ldr r1, [r7, #0x2c]
	ldr r0, [r7, #0x20]
	sub r0, r1, r0
	cmp r0, #2
	ble _020251D8
	mov sl, #0x34
	mov r4, #0
	mov r5, #0xb
	mov r6, #0xc
	mov fp, sl
_02025164:
	bl G2S_GetBG1ScrPtr
	mov r1, r5, lsl #6
	mov sb, r0
	add r8, r1, #6
	bl G2S_GetBG1ScrPtr
	add r1, sb, r8
	mov r2, sl
	add r0, r0, #0x700
	bl MIi_CpuCopy16
	bl G2S_GetBG1ScrPtr
	mov sb, r0
	mov r0, r6, lsl #6
	add r8, r0, #6
	bl G2S_GetBG1ScrPtr
	add r1, sb, r8
	add r0, r0, #0x740
	mov r2, fp
	bl MIi_CpuCopy16
	add r2, r4, #3
	ldr r1, [r7, #0x2c]
	ldr r0, [r7, #0x20]
	sub r0, r1, r0
	cmp r2, r0
	bge _020251D8
	add r4, r4, #1
	cmp r4, #5
	add r5, r5, #2
	add r6, r6, #2
	blt _02025164
_020251D8:
	ldr r4, _02025248 ; =0x04001000
	mov r3, #8
	ldr r1, [r4]
	ldr r0, [r4]
	and r1, r1, #0x1f00
	mov r2, r1, lsr #8
	bic r1, r0, #0x1f00
	orr r0, r2, #0x1e
	orr r0, r1, r0, lsl #8
	str r0, [r4]
	ldrh r2, [r4, #0xa]
	add r0, r4, #0x50
	mov r1, #2
	bic r2, r2, #3
	orr r2, r2, #1
	strh r2, [r4, #0xa]
	ldrh r5, [r4, #0xc]
	mov r2, #0x1c
	bic r5, r5, #3
	orr r5, r5, #2
	strh r5, [r4, #0xc]
	ldrh r5, [r4, #0xe]
	bic r5, r5, #3
	orr r5, r5, #3
	strh r5, [r4, #0xe]
	str r3, [sp]
	bl G2x_SetBlendAlpha_
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02025248: .word 0x04001000

	arm_func_start sub_0202524C
sub_0202524C: ; 0x0202524C
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0x22c
	ldr r6, _020255EC ; =DAT_020849dc
	add r5, sp, #0x34
	mov sl, r0
	mov r4, #0x1f
	arm_func_end sub_0202524C
_02025264:
	ldmia r6!, {r0, r1, r2, r3}
	stmia r5!, {r0, r1, r2, r3}
	subs r4, r4, #1
	bne _02025264
	ldmia r6, {r0, r1}
	stmia r5, {r0, r1}
	bl _ZN5CGame11GetInstanceEv
	mov r6, r0
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CAE0Ev
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CB14Ev
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #0x12
	bl _ZN17UnkClass_0200CAB412sub_0200CC88Ei
	mov r8, #0
	add sb, sp, #0x34
	mov r7, #0x60
	add r4, r6, #0x1000
	mov r5, r8
	mov fp, #2
_020252C4:
	ldr r0, [sb, #8]
	mov r1, r8
	str r0, [sp]
	ldr r0, [sb, #0xc]
	stmib sp, {r0, r7}
	str r5, [sp, #0xc]
	str fp, [sp, #0x10]
	ldr r0, [r4, #0x498]
	ldmia sb, {r2, r3}
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	add r8, r8, #1
	ldr r1, [sb]
	ldr r0, [sb, #4]
	cmp r8, #0x12
	mla r7, r1, r0, r7
	add sb, sb, #0x1c
	blt _020252C4
	ldr r0, [sp, #0x4c]
	mov r2, #1
	str r0, [sp]
	ldr r0, [sl, #0x74]
	mov r1, #0
	ldr r3, [r0, #8]
	add r0, r6, #0x1000
	ldr r3, [r3, #0x9c]
	str r3, [sp, #4]
	str r2, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x44]
	ldr r3, [sp, #0x48]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x68]
	mov r2, #0
	str r0, [sp]
	ldr r1, [sl, #0x74]
	add r0, r6, #0x1000
	ldr r3, [r1, #8]
	mov r1, #1
	ldr r3, [r3, #0xa4]
	str r3, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x60]
	ldr r3, [sp, #0x64]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x68]
	mov r1, #0
	str r0, [sp]
	ldr r2, [sl, #0x74]
	ldr r0, [sl, #0x28]
	ldr r2, [r2, #8]
	add r0, r0, #8
	add r0, r2, r0, lsl #3
	ldr r2, [r0, #4]
	add r0, r6, #0x1000
	str r2, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r3, [sp, #0x64]
	mov r1, #1
	mov r2, #0x33
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x68]
	mov r3, #0
	str r0, [sp]
	ldr r1, [sl, #0x74]
	add r0, r6, #0x1000
	ldr r2, [r1, #8]
	mov r1, #1
	ldr r4, [r2, #0xf4]
	mov r2, #0x3d
	str r4, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r3, [sp, #0x64]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x68]
	mov r2, #0
	str r0, [sp]
	ldr r1, [sl, #0x74]
	ldr r0, [sl, #0x2c]
	ldr r4, [r1, #8]
	add r3, r0, #8
	ldr r1, [sl, #0x20]
	add r0, r6, #0x1000
	sub r1, r3, r1
	add r1, r4, r1, lsl #3
	ldr r3, [r1, #4]
	mov r1, #1
	str r3, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r0, #0x498]
	mov r2, #0x47
	ldr r3, [sp, #0x64]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sl, #0x20]
	cmp r0, #0
	beq _02025500
	add r0, r6, #0x1000
	ldrh r1, [sl, #0x30]
	ldr r0, [r0, #0x4b0]
	bl sub_02018B10
	add r1, sp, #0x14
	mov r2, #0x1f
	bl sub_0202BC74
	ldr r1, [sp, #0x84]
	add r0, sp, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x7c]
	ldr r3, [sp, #0x80]
	mov r1, #2
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xa0]
	mov r1, #1
	str r0, [sp]
	ldr r2, [sl, #0x74]
	ldr r0, [sl, #0x24]
	ldr r2, [r2, #8]
	add r0, r0, #0x15
	add r0, r2, r0, lsl #3
	ldr r2, [r0, #4]
	mov r0, #0
	str r2, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x98]
	ldr r3, [sp, #0x9c]
	mov r1, #3
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
_02025500:
	ldr r0, [sl, #0x28]
	mov r5, #0
	cmp r0, #0
	addle sp, sp, #0x22c
	ldmleia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	mov r7, #4
	mov r8, #5
	add r4, r6, #0x1000
	add fp, sp, #0x34
_02025524:
	add r6, r5, #1
	add r1, sl, r6, lsl #1
	ldrh r1, [r1, #0x30]
	ldr r0, [r4, #0x4b0]
	bl sub_02018B10
	add r1, sp, #0x14
	mov r2, #0x1f
	bl sub_0202BC74
	mov r0, #0x1c
	mla r3, r7, r0, fp
	ldr r0, [r3, #0x18]
	mov r1, r7
	str r0, [sp]
	add r0, sp, #0x14
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r2, [r3, #0x10]
	ldr r0, [r4, #0x498]
	ldr r3, [r3, #0x14]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	add r0, sl, r6
	ldrb r1, [r0, #0x40]
	mov r0, #0x1c
	mla sb, r8, r0, fp
	ldr r0, [r4, #0x4b0]
	ldr r6, [r4, #0x498]
	bl sub_02018B80
	ldr r2, [sb, #0x18]
	mov r1, r8
	str r2, [sp]
	str r0, [sp, #4]
	mov r2, #1
	str r2, [sp, #8]
	mov r2, #0
	str r2, [sp, #0xc]
	ldr r2, [sb, #0x10]
	ldr r3, [sb, #0x14]
	mov r0, r6
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sl, #0x28]
	add r5, r5, #1
	add r7, r7, #2
	add r8, r8, #2
	cmp r5, r0
	blt _02025524
	add sp, sp, #0x22c
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_020255EC: .word DAT_020849dc

	arm_func_start _ZN17UnkClass_020247CC12sub_020255F0Ev
_ZN17UnkClass_020247CC12sub_020255F0Ev: ; 0x020255F0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	mov r1, r0
	ldr r0, [r4, #0x5c]
	add r1, r1, #0x1000
	ldr r2, [r1, #0x5d0]
	ldrsh r1, [r0, #0xc]
	mov r2, r2, asr #0xc
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [r4, #0x58]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_020247CC12sub_020255F0Ev

	arm_func_start _ZN17UnkClass_020247CC12sub_02025624Ev
_ZN17UnkClass_020247CC12sub_02025624Ev: ; 0x02025624
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x50]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x54]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x58]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_020247CC12sub_02025624Ev

	arm_func_start _ZN17UnkClass_02025648C1Ev
_ZN17UnkClass_02025648C1Ev: ; 0x02025648
	mov r1, #0
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	str r1, [r0, #0xc]
	str r1, [r0, #0x10]
	str r1, [r0, #0x14]
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	str r1, [r0, #0x20]
	str r1, [r0, #0x24]
	str r1, [r0, #0x28]
	str r1, [r0, #0x2c]
	str r1, [r0, #0x30]
	str r1, [r0, #0x34]
	str r1, [r0, #0x38]
	str r1, [r0, #0x3c]
	bx lr
	arm_func_end _ZN17UnkClass_02025648C1Ev

	arm_func_start _ZN17UnkClass_02025648D1Ev
_ZN17UnkClass_02025648D1Ev: ; 0x02025690
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN17UnkClass_0202564812sub_020256A4Ev
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_02025648D1Ev

	arm_func_start _ZN17UnkClass_0202564812sub_020256A4Ev
_ZN17UnkClass_0202564812sub_020256A4Ev: ; 0x020256A4
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r7, r0
	bl _ZN5CGame11GetInstanceEv
	ldr r1, [r7, #0x3c]
	mov r5, r0
	cmp r1, #0
	beq _02025744
	ldr r0, [r1, #4]
	mov r6, #0
	cmp r0, #0
	bls _02025710
	mov r4, r6
	arm_func_end _ZN17UnkClass_0202564812sub_020256A4Ev
_020256D4:
	ldr r0, [r1, #8]
	add r0, r0, r6, lsl #3
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _020256FC
	bl _ZdaPv
	ldr r0, [r7, #0x3c]
	ldr r0, [r0, #8]
	add r0, r0, r6, lsl #3
	str r4, [r0, #4]
_020256FC:
	ldr r1, [r7, #0x3c]
	add r6, r6, #1
	ldr r0, [r1, #4]
	cmp r6, r0
	blo _020256D4
_02025710:
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _0202572C
	bl _ZdaPv
	ldr r0, [r7, #0x3c]
	mov r1, #0
	str r1, [r0, #8]
_0202572C:
	ldr r0, [r7, #0x3c]
	cmp r0, #0
	beq _02025744
	bl _ZdlPv
	mov r0, #0
	str r0, [r7, #0x3c]
_02025744:
	ldr r4, [r7, #0x28]
	cmp r4, #0
	beq _0202576C
	beq _02025764
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_02025764:
	mov r0, #0
	str r0, [r7, #0x28]
_0202576C:
	ldr r4, [r7, #0x2c]
	cmp r4, #0
	beq _02025794
	beq _0202578C
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_0202578C:
	mov r0, #0
	str r0, [r7, #0x2c]
_02025794:
	ldr r4, [r7, #0x30]
	cmp r4, #0
	beq _020257BC
	beq _020257B4
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_020257B4:
	mov r0, #0
	str r0, [r7, #0x30]
_020257BC:
	ldr r4, [r7, #0x34]
	cmp r4, #0
	beq _020257E4
	beq _020257DC
	mov r0, r4
	bl _ZN17UnkClass_0200ECD0D1Ev
	mov r0, r4
	bl _ZdlPv
_020257DC:
	mov r0, #0
	str r0, [r7, #0x34]
_020257E4:
	add r0, r5, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CAE0Ev
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start _ZN17UnkClass_0202564812sub_020257F4Ei
_ZN17UnkClass_0202564812sub_020257F4Ei: ; 0x020257F4
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #8
	mov r5, r1
	mov sb, r0
	add r0, r5, #1
	str r0, [sp, #4]
	bl _ZN5CGame11GetInstanceEv
	mov r4, r0
	cmp r5, #6
	addls pc, pc, r5, lsl #2
	b _02026108
_02025820: ; jump table
	b _0202583C ; case 0
	b _02025A78 ; case 1
	b _02025C38 ; case 2
	b _02025E34 ; case 3
	b _02026030 ; case 4
	b _020260C4 ; case 5
	b _020260E8 ; case 6
	arm_func_end _ZN17UnkClass_0202564812sub_020257F4Ei
_0202583C:
	mov r0, #0
	str r0, [sb, #4]
	str r0, [sb, #8]
	add r0, r4, #0x1000
	ldr r1, [r0, #0x4a0]
	ldr r5, _02026114 ; =MAIN_BSS_020B26A0
	ldrb r2, [r1]
	ldr r1, _02026118 ; =MAIN_BSS_020B26A0+32768
	str r2, [sb, #0x20]
	ldr r2, [r0, #0x4a0]
	ldrb r2, [r2, #1]
	str r2, [sb, #0x24]
	ldrb r2, [r5]
	str r2, [sb]
	ldrb r2, [r5, #3]
	and r2, r2, #0xf
	str r2, [sb, #0xc]
	ldrb r2, [r5, #3]
	mov r2, r2, asr #4
	and r2, r2, #0xf
	str r2, [sb, #0x10]
	ldrb r1, [r1, #0x7db]
	str r1, [sb, #0x14]
	ldr r1, [r5, #0x28]
	str r1, [sb, #0x1c]
	ldr r1, [sb, #0x14]
	ldr r0, [r0, #0x438]
	and r1, r1, #0xff
	bl sub_02010EAC
	mov r2, #0
	mov r1, r2
	str r0, [sb, #0x18]
	mov r3, r2
_020258C0:
	cmp r1, #0
	blt _020258F4
	cmp r1, #0x1f4
	bge _020258F4
	mov r0, r1, asr #4
	add r0, r5, r0, lsl #2
	add r0, r0, #0x7000
	mov r6, r1, lsl #0x1c
	ldr r7, [r0, #0xc3c]
	mov r0, r6, lsr #0x1b
	mov r0, r7, lsr r0
	and r0, r0, #3
	b _020258F8
_020258F4:
	mov r0, r3
_020258F8:
	add r1, r1, #1
	cmp r0, #2
	addhs r2, r2, #1
	cmp r1, #0x1f4
	blt _020258C0
	add r0, r5, #0x7000
	ldr r1, [r0, #0xcb4]
	mov r0, r1, lsr #6
	and r0, r0, #3
	cmp r0, #2
	mov r0, r1, lsr #8
	and r0, r0, #3
	subeq r2, r2, #1
	cmp r0, #2
	mov r0, r1, lsr #0x18
	and r0, r0, #3
	subeq r2, r2, #1
	cmp r0, #2
	ldr r0, _0202611C ; =0x0000010B
	subeq r2, r2, #1
	cmp r2, r0
	moveq r0, #1
	movne r0, #0
	str r0, [sb, #8]
	add r0, r4, #0x1000
	ldr r0, [r0, #0x4b4]
	mov r1, #0x1e
	bl sub_02019278
	mov r0, r0, asr #3
	and r1, r0, #1
	mov r0, #0xb8
	str r1, [sb, #4]
	bl _Znwm
	movs r6, r0
	beq _02025994
	ldr r1, _02026120 ; =s_data_message_etc_menu_mes_0208bfdc
	mov r2, #1
	bl _ZN14CBinaryFileMesC1EPKcm
	mov r6, r0
_02025994:
	mov r0, #0xc
	bl _Znwm
	str r0, [sb, #0x3c]
	ldr r1, [r6, #0x4c]
	mov r4, #2
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r6, #0x4c]
	ldr r0, [sb, #0x3c]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	ldr r0, [sb, #0x3c]
	ldr r0, [r0, #4]
	mov r0, r0, lsl #3
	bl _Znam
	ldr r1, [sb, #0x3c]
	mov r5, #0
	str r0, [r1, #8]
	ldr r2, [sb, #0x3c]
	ldr r0, [r2, #4]
	cmp r0, #0
	bls _02025A5C
_020259EC:
	ldr r1, [r6, #0x4c]
	ldr r0, [r2, #8]
	ldr r1, [r1, r4, lsl #2]
	add r4, r4, #1
	str r1, [r0, r5, lsl #3]
	ldr r0, [sb, #0x3c]
	ldr r0, [r0, #8]
	ldr r0, [r0, r5, lsl #3]
	bl _Znam
	ldr r1, [sb, #0x3c]
	ldr r1, [r1, #8]
	add r1, r1, r5, lsl #3
	str r0, [r1, #4]
	ldr r1, [sb, #0x3c]
	ldr r0, [r6, #0x4c]
	ldr r2, [r1, #8]
	add r0, r0, r4, lsl #2
	add r1, r2, r5, lsl #3
	ldr r1, [r1, #4]
	ldr r2, [r2, r5, lsl #3]
	bl MIi_CpuCopyFast
	ldr r2, [sb, #0x3c]
	ldmib r2, {r0, r1}
	ldr r1, [r1, r5, lsl #3]
	add r5, r5, #1
	cmp r5, r0
	add r4, r4, r1, lsr #2
	blo _020259EC
_02025A5C:
	cmp r6, #0
	beq _02026108
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	b _02026108
_02025A78:
	mov r1, #0
	mov r0, #0x44
	str r1, [sb, #0x40]
	bl _Znwm
	cmp r0, #0
	beq _02025AB0
	mov r1, #0x40
	str r1, [sp]
	add r2, r4, #0x1000
	add r1, r4, #0x24
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02025AB0:
	str r0, [sb, #0x28]
	ldr r0, [sb, #0x10]
	cmp r0, #0
	bne _02025B34
	ldr r0, [sb]
	cmp r0, #0
	mov r0, #0
	str r0, [sp]
	bne _02025B04
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x28]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _02026128 ; =s_mp003_00_0208c004
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	add r0, r1, r0
	str r0, [sb, #0x40]
	b _02025C1C
_02025B04:
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x28]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _0202612C ; =s_mp004_00_0208c010
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	add r0, r1, r0
	str r0, [sb, #0x40]
	b _02025C1C
_02025B34:
	cmp r0, #1
	ldr r0, [sb]
	bne _02025BB0
	cmp r0, #0
	mov r0, #0
	str r0, [sp]
	bne _02025B80
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x28]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _02026130 ; =s_mp005_00_0208c01c
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	add r0, r1, r0
	str r0, [sb, #0x40]
	b _02025C1C
_02025B80:
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x28]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _02026134 ; =s_mp006_00_0208c028
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	add r0, r1, r0
	str r0, [sb, #0x40]
	b _02025C1C
_02025BB0:
	cmp r0, #0
	mov r0, #0
	str r0, [sp]
	bne _02025BF0
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x28]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _02026138 ; =s_mp007_00_0208c034
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	add r0, r1, r0
	str r0, [sb, #0x40]
	b _02025C1C
_02025BF0:
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x28]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _0202613C ; =s_mp008_00_0208c040
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	add r0, r1, r0
	str r0, [sb, #0x40]
_02025C1C:
	mov r1, #0
	str r1, [sp]
	ldr r0, [sb, #0x28]
	mov r2, #0xd0
	mov r3, #0x5b
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026108
_02025C38:
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02025C68
	mov r1, #0x40
	str r1, [sp]
	add r2, r4, #0x1000
	add r1, r4, #0xa4
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02025C68:
	str r0, [sb, #0x2c]
	mov r0, #2
	str r0, [sp]
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x2c]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _02026140 ; =s_mp001_00_0208c04c
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	add r0, r1, r0
	str r0, [sb, #0x40]
	ldr r0, [sb, #4]
	cmp r0, #0
	beq _02025CC8
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xc
	mov r2, #0x10
	mov r3, #0x11
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_02025CC8:
	ldr r0, [sb, #8]
	cmp r0, #0
	beq _02025CF0
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xd
	mov r2, #0x23
	mov r3, #0x11
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_02025CF0:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x14]
	ldr r3, _02026144 ; =0x66666667
	mov r2, r0, lsr #0x1f
	smull r0, r1, r3, r0
	ldr r0, [sb, #0x2c]
	add r1, r2, r1, asr #2
	mov r2, #0x78
	mov r3, #0x80
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #0
	str r0, [sp]
	ldr r4, [sb, #0x14]
	ldr r3, _02026144 ; =0x66666667
	mov r0, r4, lsr #0x1f
	smull r2, r1, r3, r4
	add r1, r0, r1, asr #2
	mov r2, #0xa
	smull r1, r0, r2, r1
	ldr r0, [sb, #0x2c]
	sub r1, r4, r1
	mov r2, #0x88
	mov r3, #0x80
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0x11
	mov r2, #0x50
	mov r3, #0x88
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	ldr r0, [sb, #0x20]
	cmp r0, #0
	beq _02025D98
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xa
	mov r2, #0x72
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_02025D98:
	ldr r0, [sb, #0x24]
	cmp r0, #0
	beq _02025DC0
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xb
	mov r2, #0x8e
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_02025DC0:
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xf
	mov r2, #0x40
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xe
	mov r2, #0xc0
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0x10
	mov r2, #0x38
	mov r3, #0x27
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0x10
	mov r2, #0x38
	mov r3, #0x80
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026108
_02025E34:
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02025E64
	mov r1, #0x40
	str r1, [sp]
	add r2, r4, #0x1000
	add r1, r4, #0x204
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02025E64:
	str r0, [sb, #0x30]
	mov r0, #7
	str r0, [sp]
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x30]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _02026148 ; =s_ma003_00_0208c058
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	mov r8, #0
	add r0, r1, r0
	str r0, [sb, #0x40]
	ldr r0, [sb, #0xc]
	cmp r0, #0
	ble _02026108
	mov fp, r8
	mov sl, r8
	mov r4, r8
	mov r5, r8
	mov r6, r8
	mov r7, r8
_02025EC4:
	cmp r8, #9
	addls pc, pc, r8, lsl #2
	b _0202601C
_02025ED0: ; jump table
	b _02025EF8 ; case 0
	b _02025F18 ; case 1
	b _02025F34 ; case 2
	b _02025F50 ; case 3
	b _02025F6C ; case 4
	b _02025F88 ; case 5
	b _02025FA4 ; case 6
	b _02025FC0 ; case 7
	b _02025FE0 ; case 8
	b _02026000 ; case 9
_02025EF8:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #0
	mov r2, #0x14
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025F18:
	str r7, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #1
	mov r2, #0x2c
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025F34:
	str r6, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #2
	mov r2, #0x44
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025F50:
	str r5, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #3
	mov r2, #0x5c
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025F6C:
	str r4, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #4
	mov r2, #0x74
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025F88:
	str sl, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #5
	mov r2, #0x24
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025FA4:
	str fp, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #6
	mov r2, #0x3c
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025FC0:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #7
	mov r2, #0x54
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02025FE0:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #8
	mov r2, #0x6c
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _0202601C
_02026000:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #9
	mov r2, #0x84
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_0202601C:
	add r8, r8, #1
	ldr r0, [sb, #0xc]
	cmp r8, r0
	blt _02025EC4
	b _02026108
_02026030:
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _02026060
	mov r1, #0x40
	str r1, [sp]
	add r2, r4, #0x1000
	add r1, r4, #0x394
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_02026060:
	str r0, [sb, #0x34]
	mov r0, #8
	str r0, [sp]
	ldr r2, [sb, #0x40]
	ldr r0, [sb, #0x34]
	mov r1, r2, asr #4
	add r3, r2, r1, lsr #27
	ldr r1, _02026124 ; =s_data_menu_0208bff8
	ldr r2, _0202614C ; =s_ma004_00_0208c064
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0x40]
	mov r2, #0x80
	add r0, r1, r0
	str r0, [sb, #0x40]
	mov r0, #3
	str r0, [sp]
	ldr r0, [sb, #0x34]
	sub r3, r2, #0x88
	mov r1, #0
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sb, #0x38]
	mov r0, #0
	str r0, [sb, #0x44]
	b _02026108
_020260C4:
	ldr r1, [sb, #0x44]
	mov r0, sb
	bl sub_02026968
	mvn r1, #0
	str r0, [sb, #0x44]
	cmp r0, r1
	movne r0, #5
	strne r0, [sp, #4]
	b _02026108
_020260E8:
	mov r0, sb
	bl sub_02026E54
	mov r0, sb
	bl sub_02026ECC
	mov r0, sb
	bl sub_02027550
	mvn r0, #0
	str r0, [sp, #4]
_02026108:
	ldr r0, [sp, #4]
	add sp, sp, #8
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02026114: .word MAIN_BSS_020B26A0
_02026118: .word MAIN_BSS_020B26A0+32768
_0202611C: .word 0x0000010B
_02026120: .word s_data_message_etc_menu_mes_0208bfdc
_02026124: .word s_data_menu_0208bff8
_02026128: .word s_mp003_00_0208c004
_0202612C: .word s_mp004_00_0208c010
_02026130: .word s_mp005_00_0208c01c
_02026134: .word s_mp006_00_0208c028
_02026138: .word s_mp007_00_0208c034
_0202613C: .word s_mp008_00_0208c040
_02026140: .word s_mp001_00_0208c04c
_02026144: .word 0x66666667
_02026148: .word s_ma003_00_0208c058
_0202614C: .word s_ma004_00_0208c064

	arm_func_start sub_02026150
sub_02026150: ; 0x02026150
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr}
	mov sb, r0
	bl _ZN5CGame11GetInstanceEv
	mov r1, #0
	mov r6, r0
	str r1, [sb, #4]
	add r0, r6, #0x1000
	str r1, [sb, #8]
	ldr r1, [r0, #0x4a0]
	ldr r4, _0202692C ; =MAIN_BSS_020B26A0
	ldrb r2, [r1]
	ldr r1, _02026930 ; =MAIN_BSS_020B26A0+32768
	str r2, [sb, #0x20]
	ldr r2, [r0, #0x4a0]
	ldrb r2, [r2, #1]
	str r2, [sb, #0x24]
	ldrb r2, [r4]
	str r2, [sb]
	ldrb r2, [r4, #3]
	and r2, r2, #0xf
	str r2, [sb, #0xc]
	ldrb r2, [r4, #3]
	mov r2, r2, asr #4
	and r2, r2, #0xf
	str r2, [sb, #0x10]
	ldrb r1, [r1, #0x7db]
	str r1, [sb, #0x14]
	ldr r1, [r4, #0x28]
	str r1, [sb, #0x1c]
	ldr r1, [sb, #0x14]
	ldr r0, [r0, #0x438]
	and r1, r1, #0xff
	bl sub_02010EAC
	mov r2, #0
	mov r1, r2
	str r0, [sb, #0x18]
	mov r3, r2
	arm_func_end sub_02026150
_020261E4:
	cmp r1, #0
	blt _02026218
	cmp r1, #0x1f4
	bge _02026218
	mov r0, r1, asr #4
	add r0, r4, r0, lsl #2
	add r0, r0, #0x7000
	mov r5, r1, lsl #0x1c
	ldr r7, [r0, #0xc3c]
	mov r0, r5, lsr #0x1b
	mov r0, r7, lsr r0
	and r0, r0, #3
	b _0202621C
_02026218:
	mov r0, r3
_0202621C:
	add r1, r1, #1
	cmp r0, #2
	addhs r2, r2, #1
	cmp r1, #0x1f4
	blt _020261E4
	add r0, r4, #0x7000
	ldr r1, [r0, #0xcb4]
	mov r0, r1, lsr #6
	and r0, r0, #3
	cmp r0, #2
	mov r0, r1, lsr #8
	and r0, r0, #3
	subeq r2, r2, #1
	cmp r0, #2
	mov r0, r1, lsr #0x18
	and r0, r0, #3
	subeq r2, r2, #1
	cmp r0, #2
	ldr r0, _02026934 ; =0x0000010B
	subeq r2, r2, #1
	cmp r2, r0
	moveq r0, #1
	movne r0, #0
	str r0, [sb, #8]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x4b4]
	mov r1, #0x1e
	bl sub_02019278
	mov r0, r0, asr #3
	and r1, r0, #1
	mov r0, #0xb8
	str r1, [sb, #4]
	bl _Znwm
	movs r7, r0
	beq _020262B8
	ldr r1, _02026938 ; =s_data_message_etc_menu_mes_0208bfdc
	mov r2, #1
	bl _ZN14CBinaryFileMesC1EPKcm
	mov r7, r0
_020262B8:
	mov r0, #0xc
	bl _Znwm
	str r0, [sb, #0x3c]
	ldr r1, [r7, #0x4c]
	mov r4, #2
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, [r7, #0x4c]
	ldr r0, [sb, #0x3c]
	ldr r1, [r1, #4]
	str r1, [r0, #4]
	ldr r0, [sb, #0x3c]
	ldr r0, [r0, #4]
	mov r0, r0, lsl #3
	bl _Znam
	ldr r1, [sb, #0x3c]
	mov r5, #0
	str r0, [r1, #8]
	ldr r2, [sb, #0x3c]
	ldr r0, [r2, #4]
	cmp r0, #0
	bls _02026380
_02026310:
	ldr r1, [r7, #0x4c]
	ldr r0, [r2, #8]
	ldr r1, [r1, r4, lsl #2]
	add r4, r4, #1
	str r1, [r0, r5, lsl #3]
	ldr r0, [sb, #0x3c]
	ldr r0, [r0, #8]
	ldr r0, [r0, r5, lsl #3]
	bl _Znam
	ldr r1, [sb, #0x3c]
	ldr r1, [r1, #8]
	add r1, r1, r5, lsl #3
	str r0, [r1, #4]
	ldr r1, [sb, #0x3c]
	ldr r0, [r7, #0x4c]
	ldr r2, [r1, #8]
	add r0, r0, r4, lsl #2
	add r1, r2, r5, lsl #3
	ldr r1, [r1, #4]
	ldr r2, [r2, r5, lsl #3]
	bl MIi_CpuCopyFast
	ldr r2, [sb, #0x3c]
	ldmib r2, {r0, r1}
	ldr r1, [r1, r5, lsl #3]
	add r5, r5, #1
	cmp r5, r0
	add r4, r4, r1, lsr #2
	blo _02026310
_02026380:
	cmp r7, #0
	beq _02026398
	mov r0, r7
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026398:
	mov r0, #0x44
	mov r7, #0
	bl _Znwm
	cmp r0, #0
	beq _020263CC
	mov r1, #0x40
	str r1, [sp]
	add r2, r6, #0x1000
	add r1, r6, #0x24
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_020263CC:
	str r0, [sb, #0x28]
	ldr r0, [sb, #0x10]
	mov r3, #0
	cmp r0, #0
	bne _02026420
	ldr r0, [sb]
	cmp r0, #0
	str r3, [sp]
	bne _02026408
	ldr r0, [sb, #0x28]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026940 ; =s_mp003_00_0208c004
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r7, r7, r0
	b _020264A0
_02026408:
	ldr r0, [sb, #0x28]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026944 ; =s_mp004_00_0208c010
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r7, r7, r0
	b _020264A0
_02026420:
	cmp r0, #1
	ldr r0, [sb]
	bne _02026468
	cmp r0, #0
	str r3, [sp]
	bne _02026450
	ldr r0, [sb, #0x28]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026948 ; =s_mp005_00_0208c01c
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r7, r7, r0
	b _020264A0
_02026450:
	ldr r0, [sb, #0x28]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _0202694C ; =s_mp006_00_0208c028
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r7, r7, r0
	b _020264A0
_02026468:
	cmp r0, #0
	str r3, [sp]
	bne _0202648C
	ldr r0, [sb, #0x28]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026950 ; =s_mp007_00_0208c034
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r7, r7, r0
	b _020264A0
_0202648C:
	ldr r0, [sb, #0x28]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026954 ; =s_mp008_00_0208c040
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	add r7, r7, r0
_020264A0:
	mov r1, #0
	str r1, [sp]
	ldr r0, [sb, #0x28]
	mov r2, #0xd0
	mov r3, #0x5b
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _020264E8
	mov r1, #0x40
	str r1, [sp]
	add r2, r6, #0x1000
	add r1, r6, #0xa4
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_020264E8:
	str r0, [sb, #0x2c]
	mov r0, #2
	str r0, [sp]
	mov r0, r7, asr #4
	add r3, r7, r0, lsr #27
	ldr r0, [sb, #0x2c]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026958 ; =s_mp001_00_0208c04c
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #4]
	add r7, r7, r0
	cmp r1, #0
	beq _0202653C
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xc
	mov r2, #0x10
	mov r3, #0x11
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_0202653C:
	ldr r0, [sb, #8]
	cmp r0, #0
	beq _02026564
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xd
	mov r2, #0x23
	mov r3, #0x11
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_02026564:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x14]
	ldr r3, _0202695C ; =0x66666667
	mov r2, r0, lsr #0x1f
	smull r0, r1, r3, r0
	ldr r0, [sb, #0x2c]
	add r1, r2, r1, asr #2
	mov r2, #0x78
	mov r3, #0x80
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #0
	str r0, [sp]
	ldr r4, [sb, #0x14]
	ldr r3, _0202695C ; =0x66666667
	mov r0, r4, lsr #0x1f
	smull r2, r1, r3, r4
	add r1, r0, r1, asr #2
	mov r2, #0xa
	smull r1, r0, r2, r1
	ldr r0, [sb, #0x2c]
	sub r1, r4, r1
	mov r2, #0x88
	mov r3, #0x80
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0x11
	mov r2, #0x50
	mov r3, #0x88
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	ldr r0, [sb, #0x20]
	cmp r0, #0
	beq _0202660C
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xa
	mov r2, #0x72
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_0202660C:
	ldr r0, [sb, #0x24]
	cmp r0, #0
	beq _02026634
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xb
	mov r2, #0x8e
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_02026634:
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xf
	mov r2, #0x40
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0xe
	mov r2, #0xc0
	mov r3, #0xab
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0x10
	mov r2, #0x38
	mov r3, #0x27
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #1
	str r0, [sp]
	ldr r0, [sb, #0x2c]
	mov r1, #0x10
	mov r2, #0x38
	mov r3, #0x80
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _020266D4
	mov r1, #0x40
	str r1, [sp]
	add r2, r6, #0x1000
	add r1, r6, #0x204
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_020266D4:
	str r0, [sb, #0x30]
	mov r0, #7
	str r0, [sp]
	mov r0, r7, asr #4
	add r3, r7, r0, lsr #27
	ldr r0, [sb, #0x30]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026960 ; =s_ma003_00_0208c058
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	ldr r1, [sb, #0xc]
	add r7, r7, r0
	cmp r1, #0
	mov r8, #0
	ble _02026890
	mov fp, r8
	mov sl, r8
	mov r4, r8
	mov r5, r8
_02026720:
	cmp r8, #9
	addls pc, pc, r8, lsl #2
	b _02026880
_0202672C: ; jump table
	b _02026754 ; case 0
	b _02026774 ; case 1
	b _02026790 ; case 2
	b _020267AC ; case 3
	b _020267C8 ; case 4
	b _020267E4 ; case 5
	b _02026804 ; case 6
	b _02026824 ; case 7
	b _02026844 ; case 8
	b _02026864 ; case 9
_02026754:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #0
	mov r2, #0x14
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_02026774:
	str r5, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #1
	mov r2, #0x2c
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_02026790:
	str r4, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #2
	mov r2, #0x44
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_020267AC:
	str sl, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #3
	mov r2, #0x5c
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_020267C8:
	str fp, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #4
	mov r2, #0x74
	mov r3, #0x40
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_020267E4:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #5
	mov r2, #0x24
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_02026804:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #6
	mov r2, #0x3c
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_02026824:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #7
	mov r2, #0x54
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_02026844:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #8
	mov r2, #0x6c
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	b _02026880
_02026864:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sb, #0x30]
	mov r1, #9
	mov r2, #0x84
	mov r3, #0x60
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
_02026880:
	add r8, r8, #1
	ldr r0, [sb, #0xc]
	cmp r8, r0
	blt _02026720
_02026890:
	mov r0, #0x44
	bl _Znwm
	cmp r0, #0
	beq _020268C0
	mov r1, #0x40
	str r1, [sp]
	add r2, r6, #0x1000
	add r1, r6, #0x394
	ldr r2, [r2, #0x4a8]
	add r1, r1, #0x400
	mov r3, #1
	bl _ZN17UnkClass_0200ECD0C1EP9GXOamAttrmii
_020268C0:
	str r0, [sb, #0x34]
	mov r0, #8
	str r0, [sp]
	mov r0, r7, asr #4
	add r3, r7, r0, lsr #27
	ldr r0, [sb, #0x34]
	ldr r1, _0202693C ; =s_data_menu_0208bff8
	ldr r2, _02026964 ; =s_ma004_00_0208c064
	mov r3, r3, asr #5
	bl _ZN17UnkClass_0200ECD012sub_0200EE14EPKcS1_mm
	mov r0, #3
	str r0, [sp]
	mov r2, #0x80
	ldr r0, [sb, #0x34]
	sub r3, r2, #0x88
	mov r1, #0
	bl _ZN17UnkClass_0200ECD012sub_0200F4FCEiiii
	str r0, [sb, #0x38]
	mov r0, sb
	bl sub_02026C18
	mov r0, sb
	bl sub_02026E54
	mov r0, sb
	bl sub_02026ECC
	mov r0, sb
	bl sub_02027550
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_0202692C: .word MAIN_BSS_020B26A0
_02026930: .word MAIN_BSS_020B26A0+32768
_02026934: .word 0x0000010B
_02026938: .word s_data_message_etc_menu_mes_0208bfdc
_0202693C: .word s_data_menu_0208bff8
_02026940: .word s_mp003_00_0208c004
_02026944: .word s_mp004_00_0208c010
_02026948: .word s_mp005_00_0208c01c
_0202694C: .word s_mp006_00_0208c028
_02026950: .word s_mp007_00_0208c034
_02026954: .word s_mp008_00_0208c040
_02026958: .word s_mp001_00_0208c04c
_0202695C: .word 0x66666667
_02026960: .word s_ma003_00_0208c058
_02026964: .word s_ma004_00_0208c064

	arm_func_start sub_02026968
sub_02026968: ; 0x02026968
	stmdb sp!, {r4, r5, r6, lr}
	sub sp, sp, #0x10
	mov r5, r0
	cmp r1, #5
	add r4, r1, #1
	addls pc, pc, r1, lsl #2
	b _02026BF0
_02026984: ; jump table
	b _0202699C ; case 0
	b _020269D8 ; case 1
	b _02026A04 ; case 2
	b _02026A30 ; case 3
	b _02026AA8 ; case 4
	b _02026B14 ; case 5
	arm_func_end sub_02026968
_0202699C:
	mov r0, #0x6c
	bl _Znwm
	cmp r0, #0
	beq _020269D0
	mov r1, #1
	str r1, [sp]
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r1, _02026BFC ; =s_BGS_0208c070
	ldr r2, _02026C00 ; =s_data_menu_mp000_bg_LZ_bin_0208c074
	str r3, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
_020269D0:
	str r0, [r5, #0x48]
	b _02026BF0
_020269D8:
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _020269FC
	mov r2, #0
	ldr r1, _02026C04 ; =s_BGS_mp000_NCGR_0208c090
	mov r3, r2
	str r2, [sp]
	bl _ZN11CBGNCGRFileC1EPKcmmm
_020269FC:
	str r0, [r5, #0x4c]
	b _02026BF0
_02026A04:
	mov r0, #0xbc
	bl _Znwm
	cmp r0, #0
	beq _02026A28
	mov r2, #0
	ldr r1, _02026C08 ; =s_BGS_mp000_NCLR_0208c0a0
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNCLRFileC1EPKcmmm
_02026A28:
	str r0, [r5, #0x50]
	b _02026BF0
_02026A30:
	mov r0, #0xbc
	bl _Znwm
	movs r6, r0
	beq _02026A58
	mov r2, #0
	ldr r1, _02026C0C ; =s_BGS_mp000_00_NSCR_0208c0b0
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r6, r0
_02026A58:
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, #0xd
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, #0x4c]
	ldr r0, [r5, #0x50]
	ldr r1, [r6, #0xb8]
	ldr r3, [r0, #0xb8]
	ldr r2, [r2, #0xb8]
	mov r0, #5
	bl NNS_G2dBGSetupEx
	cmp r6, #0
	beq _02026BF0
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	b _02026BF0
_02026AA8:
	mov r0, #0xbc
	bl _Znwm
	movs r5, r0
	beq _02026AD0
	mov r2, #0
	ldr r1, _02026C10 ; =s_BGS_mp000_01_NSCR_0208c0c4
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r5, r0
_02026AD0:
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r0, #0xe
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r1, [r5, #0xb8]
	mov r3, r2
	mov r0, #6
	bl NNS_G2dBGSetupEx
	cmp r5, #0
	beq _02026BF0
	mov r0, r5
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
	b _02026BF0
_02026B14:
	mov r0, #0xbc
	bl _Znwm
	movs r4, r0
	beq _02026B3C
	mov r2, #0
	ldr r1, _02026C14 ; =s_BGS_mp000_02_NSCR_0208c0d8
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r4, r0
_02026B3C:
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r0, #0xf
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r1, [r4, #0xb8]
	mov r3, r2
	mov r0, #7
	bl NNS_G2dBGSetupEx
	cmp r4, #0
	beq _02026B7C
	mov r0, r4
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026B7C:
	ldr r0, [r5, #0x4c]
	cmp r0, #0
	beq _02026BA0
	beq _02026B98
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026B98:
	mov r0, #0
	str r0, [r5, #0x4c]
_02026BA0:
	ldr r0, [r5, #0x50]
	cmp r0, #0
	beq _02026BC4
	beq _02026BBC
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026BBC:
	mov r0, #0
	str r0, [r5, #0x50]
_02026BC4:
	ldr r4, [r5, #0x48]
	cmp r4, #0
	beq _02026BEC
	beq _02026BE4
	mov r0, r4
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r4
	bl _ZdlPv
_02026BE4:
	mov r0, #0
	str r0, [r5, #0x48]
_02026BEC:
	mvn r4, #0
_02026BF0:
	mov r0, r4
	add sp, sp, #0x10
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_02026BFC: .word s_BGS_0208c070
_02026C00: .word s_data_menu_mp000_bg_LZ_bin_0208c074
_02026C04: .word s_BGS_mp000_NCGR_0208c090
_02026C08: .word s_BGS_mp000_NCLR_0208c0a0
_02026C0C: .word s_BGS_mp000_00_NSCR_0208c0b0
_02026C10: .word s_BGS_mp000_01_NSCR_0208c0c4
_02026C14: .word s_BGS_mp000_02_NSCR_0208c0d8

	arm_func_start sub_02026C18
sub_02026C18: ; 0x02026C18
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	sub sp, sp, #0x10
	mov r0, #0x6c
	bl _Znwm
	movs r4, r0
	beq _02026C58
	mov r1, #1
	str r1, [sp]
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r1, _02026E38 ; =s_BGS_0208c070
	ldr r2, _02026E3C ; =s_data_menu_mp000_bg_LZ_bin_0208c074
	str r3, [sp, #0xc]
	bl _ZN13CArchiveGuardC1EPKcS1_mmmPvm
	mov r4, r0
	arm_func_end sub_02026C18
_02026C58:
	mov r0, #0xbc
	bl _Znwm
	movs r5, r0
	beq _02026C80
	mov r2, #0
	ldr r1, _02026E40 ; =s_BGS_mp000_NCGR_0208c090
	mov r3, r2
	str r2, [sp]
	bl _ZN11CBGNCGRFileC1EPKcmmm
	mov r5, r0
_02026C80:
	mov r0, #0xbc
	bl _Znwm
	movs r6, r0
	beq _02026CA8
	mov r2, #0
	ldr r1, _02026E44 ; =s_BGS_mp000_NCLR_0208c0a0
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNCLRFileC1EPKcmmm
	mov r6, r0
_02026CA8:
	mov r0, #0xbc
	bl _Znwm
	movs r7, r0
	beq _02026CD0
	mov r2, #0
	ldr r1, _02026E48 ; =s_BGS_mp000_00_NSCR_0208c0b0
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r7, r0
_02026CD0:
	mov r0, #0xbc
	bl _Znwm
	movs r8, r0
	beq _02026CF8
	mov r2, #0
	ldr r1, _02026E4C ; =s_BGS_mp000_01_NSCR_0208c0c4
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov r8, r0
_02026CF8:
	mov r0, #0xbc
	bl _Znwm
	movs sb, r0
	beq _02026D20
	mov r2, #0
	ldr r1, _02026E50 ; =s_BGS_mp000_02_NSCR_0208c0d8
	mov r3, r2
	str r2, [sp]
	bl _ZN9CNSCRFileC1EPKcmmm
	mov sb, r0
_02026D20:
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, #0xd
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r1, [r7, #0xb8]
	ldr r2, [r5, #0xb8]
	ldr r3, [r6, #0xb8]
	mov r0, #5
	bl NNS_G2dBGSetupEx
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r0, #0xe
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r1, [r8, #0xb8]
	mov r3, r2
	mov r0, #6
	bl NNS_G2dBGSetupEx
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r0, #0xf
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	ldr r1, [sb, #0xb8]
	mov r0, #7
	mov r3, r2
	bl NNS_G2dBGSetupEx
	cmp r7, #0
	beq _02026DB4
	mov r0, r7
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026DB4:
	cmp r8, #0
	beq _02026DCC
	mov r0, r8
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026DCC:
	cmp sb, #0
	beq _02026DE4
	mov r0, sb
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026DE4:
	cmp r5, #0
	beq _02026DFC
	mov r0, r5
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026DFC:
	cmp r6, #0
	beq _02026E14
	mov r0, r6
	ldr r1, [r0]
	ldr r1, [r1, #4]
	blx r1
_02026E14:
	cmp r4, #0
	addeq sp, sp, #0x10
	ldmeqia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	mov r0, r4
	bl _ZN13CArchiveGuardD1Ev
	mov r0, r4
	bl _ZdlPv
	add sp, sp, #0x10
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
	.align 2, 0
_02026E38: .word s_BGS_0208c070
_02026E3C: .word s_data_menu_mp000_bg_LZ_bin_0208c074
_02026E40: .word s_BGS_mp000_NCGR_0208c090
_02026E44: .word s_BGS_mp000_NCLR_0208c0a0
_02026E48: .word s_BGS_mp000_00_NSCR_0208c0b0
_02026E4C: .word s_BGS_mp000_01_NSCR_0208c0c4
_02026E50: .word s_BGS_mp000_02_NSCR_0208c0d8

	arm_func_start sub_02026E54
sub_02026E54: ; 0x02026E54
	stmdb sp!, {r3, lr}
	ldr ip, _02026EC8 ; =0x04001000
	mov r3, #8
	ldr r1, [ip]
	ldr r0, [ip]
	and r1, r1, #0x1f00
	mov r2, r1, lsr #8
	bic r1, r0, #0x1f00
	orr r0, r2, #0x1e
	orr r0, r1, r0, lsl #8
	str r0, [ip]
	ldrh r2, [ip, #0xa]
	add r0, ip, #0x50
	mov r1, #2
	bic r2, r2, #3
	orr r2, r2, #1
	strh r2, [ip, #0xa]
	ldrh lr, [ip, #0xc]
	mov r2, #0x1c
	bic lr, lr, #3
	orr lr, lr, #2
	strh lr, [ip, #0xc]
	ldrh lr, [ip, #0xe]
	bic lr, lr, #3
	orr lr, lr, #3
	strh lr, [ip, #0xe]
	str r3, [sp]
	bl G2x_SetBlendAlpha_
	ldmia sp!, {r3, pc}
	.align 2, 0
_02026EC8: .word 0x04001000
	arm_func_end sub_02026E54

	arm_func_start sub_02026ECC
sub_02026ECC: ; 0x02026ECC
	stmdb sp!, {r4, r5, r6, r7, r8, sb, sl, fp, lr}
	sub sp, sp, #0xbc
	ldr r6, _02027538 ; =DAT_02084bd4
	add r5, sp, #0x14
	mov sl, r0
	mov r4, #0xa
	arm_func_end sub_02026ECC
_02026EE4:
	ldmia r6!, {r0, r1, r2, r3}
	stmia r5!, {r0, r1, r2, r3}
	subs r4, r4, #1
	bne _02026EE4
	ldmia r6, {r0, r1}
	stmia r5, {r0, r1}
	bl _ZN5CGame11GetInstanceEv
	mov r6, r0
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CAE0Ev
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	bl _ZN17UnkClass_0200CAB412sub_0200CB14Ev
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #6
	bl _ZN17UnkClass_0200CAB412sub_0200CC88Ei
	mov r8, #0
	add sb, sp, #0x14
	mov r7, #0x60
	add r4, r6, #0x1000
	mov r5, r8
	mov fp, #2
_02026F44:
	ldr r0, [sb, #8]
	mov r1, r8
	str r0, [sp]
	ldr r0, [sb, #0xc]
	stmib sp, {r0, r7}
	str r5, [sp, #0xc]
	str fp, [sp, #0x10]
	ldr r0, [r4, #0x498]
	ldmia sb, {r2, r3}
	bl _ZN17UnkClass_0200CAB412sub_0200CCD0Eiiiiiiii
	add r8, r8, #1
	ldr r1, [sb]
	ldr r0, [sb, #4]
	cmp r8, #6
	mla r7, r1, r0, r7
	add sb, sb, #0x1c
	blt _02026F44
	ldr r1, [sp, #0x2c]
	ldr r0, _0202753C ; =MAIN_BSS_020B26A0+34787
	str r1, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	mov r1, #0
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x48]
	mov r1, #1
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	mov r2, #0
	ldr r3, [r0, #8]
	add r0, r6, #0x1000
	ldr r3, [r3, #0xd4]
	str r3, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x64]
	mov r3, #1
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	mov r2, #0
	ldr r1, [r0, #8]
	add r0, r6, #0x1000
	ldr r4, [r1, #0xdc]
	mov r1, #2
	str r4, [sp, #4]
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x5c]
	ldr r3, [sp, #0x60]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x80]
	mov r3, #1
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	mov r2, #0
	ldr r1, [r0, #8]
	add r0, r6, #0x1000
	ldr r4, [r1, #0xe4]
	mov r1, #3
	str r4, [sp, #4]
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x78]
	ldr r3, [sp, #0x7c]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0x9c]
	mov r3, #1
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	mov r2, #0
	ldr r1, [r0, #8]
	add r0, r6, #0x1000
	ldr r4, [r1, #0xec]
	mov r1, #4
	str r4, [sp, #4]
	str r3, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0x94]
	ldr r3, [sp, #0x98]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sl, #0x18]
	cmp r0, #0
	addeq sp, sp, #0xbc
	ldmeqia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	ldr r0, [sp, #0xb8]
	mov r2, #0
	str r0, [sp]
	ldr r1, [sl, #0x3c]
	add r0, r6, #0x1000
	ldr r3, [r1, #8]
	mov r1, #5
	ldr r3, [r3, #0xf4]
	str r3, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	ldr r0, [r0, #0x498]
	ldr r2, [sp, #0xb0]
	ldr r3, [sp, #0xb4]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r2, _02027540 ; =0x68DB8BAD
	str r0, [sp]
	ldr r1, [sl, #0x1c]
	ldr r4, [sl, #0x3c]
	mov r0, r1, lsr #0x1f
	smull r1, r3, r2, r1
	add r3, r0, r3, asr #12
	ldr r1, [r4, #8]
	add r0, r3, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	ldr r3, [sp, #0xb4]
	mov r1, #5
	mov r2, #0xa
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r2, _02027544 ; =0x10624DD3
	str r0, [sp]
	ldr r3, [sl, #0x1c]
	ldr r4, [sl, #0x3c]
	smull r1, r0, r2, r3
	ldr r1, [r4, #8]
	mov r2, r3, lsr #0x1f
	add r0, r2, r0, asr #6
	ldr r4, _02027548 ; =0x66666667
	mov r2, r0, lsr #0x1f
	smull r3, r5, r4, r0
	add r5, r2, r5, asr #2
	mov r4, #0xa
	smull r2, r3, r4, r5
	sub r5, r0, r2
	add r0, r5, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #5
	mov r2, #0x14
	ldr r3, [sp, #0xb4]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r3, _0202754C ; =0x51EB851F
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	ldr r4, [sl, #0x1c]
	ldr r1, [r0, #8]
	smull r2, r0, r3, r4
	mov r2, r4, lsr #0x1f
	add r0, r2, r0, asr #5
	ldr r4, _02027548 ; =0x66666667
	mov r2, r0, lsr #0x1f
	smull r3, r5, r4, r0
	add r5, r2, r5, asr #2
	mov r4, #0xa
	smull r2, r3, r4, r5
	sub r5, r0, r2
	add r0, r5, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #5
	mov r2, #0x1e
	ldr r3, [sp, #0xb4]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r2, _02027548 ; =0x66666667
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	ldr r3, [sl, #0x1c]
	ldr r0, [r0, #8]
	smull r1, r4, r2, r3
	mov r1, r3, lsr #0x1f
	add r4, r1, r4, asr #2
	smull r1, r5, r2, r4
	mov r1, r4, lsr #0x1f
	add r5, r1, r5, asr #2
	mov r3, #0xa
	smull r1, r2, r3, r5
	sub r5, r4, r1
	add r1, r5, #8
	add r0, r0, r1, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #5
	mov r2, #0x28
	ldr r3, [sp, #0xb4]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r2, _02027548 ; =0x66666667
	str r0, [sp]
	ldr r3, [sl, #0x1c]
	ldr r5, [sl, #0x3c]
	mov r0, r3, lsr #0x1f
	smull r1, r4, r2, r3
	add r4, r0, r4, asr #2
	mov r2, #0xa
	smull r0, r1, r2, r4
	sub r4, r3, r0
	ldr r1, [r5, #8]
	add r0, r4, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	ldr r3, [sp, #0xb4]
	mov r1, #5
	mov r2, #0x32
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r2, _02027540 ; =0x68DB8BAD
	str r0, [sp]
	ldr r1, [sl, #0x18]
	ldr r4, [sl, #0x3c]
	mov r0, r1, lsr #0x1f
	smull r1, r3, r2, r1
	add r3, r0, r3, asr #12
	ldr r1, [r4, #8]
	add r0, r3, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	ldr r3, [sp, #0xb4]
	mov r1, #5
	mov r2, #0x46
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r3, _02027544 ; =0x10624DD3
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	ldr r4, [sl, #0x18]
	ldr r1, [r0, #8]
	smull r2, r0, r3, r4
	mov r2, r4, lsr #0x1f
	add r0, r2, r0, asr #6
	ldr r4, _02027548 ; =0x66666667
	mov r2, r0, lsr #0x1f
	smull r3, r5, r4, r0
	add r5, r2, r5, asr #2
	mov r4, #0xa
	smull r2, r3, r4, r5
	sub r5, r0, r2
	add r0, r5, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #5
	mov r2, #0x50
	ldr r3, [sp, #0xb4]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r3, _0202754C ; =0x51EB851F
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	ldr r4, [sl, #0x18]
	ldr r1, [r0, #8]
	smull r2, r0, r3, r4
	mov r2, r4, lsr #0x1f
	add r0, r2, r0, asr #5
	ldr r4, _02027548 ; =0x66666667
	mov r2, r0, lsr #0x1f
	smull r3, r5, r4, r0
	add r5, r2, r5, asr #2
	mov r4, #0xa
	smull r2, r3, r4, r5
	sub r5, r0, r2
	add r0, r5, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #5
	mov r2, #0x5a
	ldr r3, [sp, #0xb4]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r2, _02027548 ; =0x66666667
	str r0, [sp]
	ldr r0, [sl, #0x3c]
	ldr r3, [sl, #0x18]
	ldr r0, [r0, #8]
	smull r1, r4, r2, r3
	mov r1, r3, lsr #0x1f
	add r4, r1, r4, asr #2
	smull r1, r5, r2, r4
	mov r1, r4, lsr #0x1f
	add r5, r1, r5, asr #2
	mov r3, #0xa
	smull r1, r2, r3, r5
	sub r5, r4, r1
	add r1, r5, #8
	add r0, r0, r1, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	mov r1, #5
	mov r2, #0x64
	ldr r3, [sp, #0xb4]
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	ldr r0, [sp, #0xb8]
	ldr r2, _02027548 ; =0x66666667
	str r0, [sp]
	ldr r3, [sl, #0x18]
	ldr r5, [sl, #0x3c]
	mov r0, r3, lsr #0x1f
	smull r1, r4, r2, r3
	add r4, r0, r4, asr #2
	mov r2, #0xa
	smull r0, r1, r2, r4
	sub r4, r3, r0
	ldr r1, [r5, #8]
	add r0, r4, #8
	add r0, r1, r0, lsl #3
	ldr r1, [r0, #4]
	mov r0, #0
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r6, #0x1000
	ldr r0, [r0, #0x498]
	ldr r3, [sp, #0xb4]
	mov r1, #5
	mov r2, #0x6e
	bl _ZN17UnkClass_0200CAB412sub_0200CDA0EiiiiPhii
	add sp, sp, #0xbc
	ldmia sp!, {r4, r5, r6, r7, r8, sb, sl, fp, pc}
	.align 2, 0
_02027538: .word DAT_02084bd4
_0202753C: .word MAIN_BSS_020B26A0+34787
_02027540: .word 0x68DB8BAD
_02027544: .word 0x10624DD3
_02027548: .word 0x66666667
_0202754C: .word 0x51EB851F

	arm_func_start sub_02027550
sub_02027550: ; 0x02027550
	stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
	ldr r4, [r0, #0x18]
	ldr r0, [r0, #0x1c]
	mov r1, r4
	mov r0, r0, lsl #7
	bl _s32_div_f
	mov r1, r0, asr #2
	mov r2, r0, lsr #0x1f
	add r1, r0, r1, lsr #29
	rsb r0, r2, r0, lsl #29
	cmp r4, #0
	mov r4, r1, asr #3
	add r5, r2, r0, ror #29
	beq _02027600
	cmp r4, #0
	mov r6, #0
	ble _020275CC
	mov r7, #2
	arm_func_end sub_02027550
_02027598:
	bl G2S_GetBG0ScrPtr
	add r1, r6, #2
	mov r1, r1, lsl #1
	mov sb, r0
	add r8, r1, #0x440
	bl G2S_GetBG1ScrPtr
	mov r2, r7
	add r0, r0, #0x610
	add r1, sb, r8
	bl MIi_CpuCopy16
	add r6, r6, #1
	cmp r6, r4
	blt _02027598
_020275CC:
	bl G2S_GetBG0ScrPtr
	add r1, r6, #2
	mov r1, r1, lsl #1
	mov r6, r0
	add r4, r1, #0x440
	bl G2S_GetBG1ScrPtr
	mov r1, r5, lsl #1
	add r1, r1, #0x600
	add r0, r0, r1
	add r1, r6, r4
	mov r2, #2
	bl MIi_CpuCopy16
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
_02027600:
	mov r7, #0
	mov r4, #2
_02027608:
	bl G2S_GetBG0ScrPtr
	add r1, r7, #2
	mov r1, r1, lsl #1
	mov r6, r0
	add r5, r1, #0x440
	bl G2S_GetBG1ScrPtr
	mov r2, r4
	add r0, r0, #0x610
	add r1, r6, r5
	bl MIi_CpuCopy16
	add r7, r7, #1
	cmp r7, #0x10
	blt _02027608
	ldmia sp!, {r3, r4, r5, r6, r7, r8, sb, pc}

	arm_func_start _ZN17UnkClass_0202564812sub_02027640Ev
_ZN17UnkClass_0202564812sub_02027640Ev: ; 0x02027640
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl _ZN5CGame11GetInstanceEv
	mov r1, r0
	ldr r0, [r4, #0x38]
	add r1, r1, #0x1000
	ldr r2, [r1, #0x5d0]
	ldrsh r1, [r0, #0xc]
	mov r2, r2, asr #0xc
	bl _ZN17UnkClass_0200E96012sub_0200EB28Eii
	ldr r0, [r4, #0x34]
	bl _ZN17UnkClass_0200ECD012sub_0200F64CEv
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0202564812sub_02027640Ev

	arm_func_start _ZN17UnkClass_0202564812sub_02027674Ev
_ZN17UnkClass_0202564812sub_02027674Ev: ; 0x02027674
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x28]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x2c]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x30]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldr r0, [r4, #0x34]
	bl _ZN17UnkClass_0200ECD012sub_0200F71CEv
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0202564812sub_02027674Ev

	arm_func_start _ZN17UnkClass_0202564812sub_020276A0Ev
_ZN17UnkClass_0202564812sub_020276A0Ev: ; 0x020276A0
	stmdb sp!, {r4, r5, r6, lr}
	mov r5, r0
	ldr r1, [r5, #0x3c]
	cmp r1, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r0, [r1, #4]
	mov r4, #0
	cmp r0, #0
	bls _02027704
	mov r6, r4
	arm_func_end _ZN17UnkClass_0202564812sub_020276A0Ev
_020276C8:
	ldr r0, [r1, #8]
	add r0, r0, r4, lsl #3
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _020276F0
	bl _ZdaPv
	ldr r0, [r5, #0x3c]
	ldr r0, [r0, #8]
	add r0, r0, r4, lsl #3
	str r6, [r0, #4]
_020276F0:
	ldr r1, [r5, #0x3c]
	add r4, r4, #1
	ldr r0, [r1, #4]
	cmp r4, r0
	blo _020276C8
_02027704:
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _02027720
	bl _ZdaPv
	ldr r0, [r5, #0x3c]
	mov r1, #0
	str r1, [r0, #8]
_02027720:
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	ldmeqia sp!, {r4, r5, r6, pc}
	bl _ZdlPv
	mov r0, #0
	str r0, [r5, #0x3c]
	ldmia sp!, {r4, r5, r6, pc}

	arm_func_start _ZN17UnkClass_0202773CC1EP5CGame
_ZN17UnkClass_0202773CC1EP5CGame: ; 0x0202773C
	stmdb sp!, {r4, lr}
	mov r4, r0
	str r1, [r4, #0x14]
	bl sub_0202798C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end _ZN17UnkClass_0202773CC1EP5CGame

	arm_func_start sub_02027754
sub_02027754: ; 0x02027754
	stmdb sp!, {r4, lr}
	ldr r0, _02027798 ; =MAIN_BSS_0210C1BC
	ldr r0, [r0]
	cmp r0, #0
	ldmneia sp!, {r4, pc}
	mov r0, #0x18
	bl _Znwm
	movs r4, r0
	beq _0202778C
	bl _ZN5CGame11GetInstanceEv
	mov r1, r0
	mov r0, r4
	bl _ZN17UnkClass_0202773CC1EP5CGame
	mov r4, r0
	arm_func_end sub_02027754
_0202778C:
	ldr r0, _02027798 ; =MAIN_BSS_0210C1BC
	str r4, [r0]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02027798: .word MAIN_BSS_0210C1BC

	arm_func_start sub_0202779C
sub_0202779C: ; 0x0202779C
	ldr r0, _020277A8 ; =MAIN_BSS_0210C1BC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_020277A8: .word MAIN_BSS_0210C1BC
	arm_func_end sub_0202779C

	arm_func_start _ZN17UnkClass_0202773CD1Ev
_ZN17UnkClass_0202773CD1Ev: ; 0x020277AC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	ldr r0, [r5, #0x14]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	ldr r0, [r5, #0x14]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	ldr r4, [r5, #8]
	cmp r4, #0
	beq _02027804
	beq _020277FC
	mov r0, r4
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r4
	bl _ZdlPv
	arm_func_end _ZN17UnkClass_0202773CD1Ev
_020277FC:
	mov r0, #0
	str r0, [r5, #8]
_02027804:
	mov r0, r5
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start _ZN17UnkClass_0202773C12sub_0202780CEv
_ZN17UnkClass_0202773C12sub_0202780CEv: ; 0x0202780C
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	ldrh r1, [r4]
	cmp r1, #7
	addls pc, pc, r1, lsl #2
	b _02027978
_02027824: ; jump table
	b _02027978 ; case 0
	b _02027968 ; case 1
	b _02027844 ; case 2
	b _020278C0 ; case 3
	b _020278E0 ; case 4
	b _02027978 ; case 5
	b _02027978 ; case 6
	b _02027970 ; case 7
	arm_func_end _ZN17UnkClass_0202773C12sub_0202780CEv
_02027844:
	ldr r0, [r4, #0x14]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	bne _02027978
	ldr r0, [r4, #0x14]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200B6A4Em
	cmp r0, #0
	bne _02027978
	ldr r0, [r4, #0x14]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200B6D4Ev
	cmp r0, #0
	moveq r0, #1
	streqh r0, [r4]
	beq _02027978
	mov r3, #0x4000000
	ldr r2, [r3]
	ldr r0, _02027984 ; =0xFFCFFFEF
	mov r1, #5
	and r0, r2, r0
	orr r0, r0, #0x10
	orr r0, r0, #0x100000
	str r0, [r3]
	strh r1, [r4]
	b _02027978
_020278C0:
	ldr r0, [r4, #0x14]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_02009ECCEv
	cmp r0, #0
	moveq r0, #1
	streqh r0, [r4]
	b _02027978
_020278E0:
	ldr r0, [r4, #8]
	bl _ZN17UnkClass_02027FE812sub_0202841CEv
	cmp r0, #0
	beq _02027978
	tst r0, #0x80
	moveq r0, #1
	streqh r0, [r4]
	beq _0202793C
	ldr r1, _02027988 ; =DAT_0208c0ec
	mov r0, r4
	mov r2, #1
	mov r3, #0
	bl sub_02027A94
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B58Ei
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034E38Ei
_0202793C:
	ldr r5, [r4, #8]
	cmp r5, #0
	beq _02027978
	beq _0202795C
	mov r0, r5
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r5
	bl _ZdlPv
_0202795C:
	mov r0, #0
	str r0, [r4, #8]
	b _02027978
_02027968:
	bl sub_02027B34
	b _02027978
_02027970:
	mov r0, #1
	strh r0, [r4]
_02027978:
	mov r0, r4
	bl sub_02027CB4
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02027984: .word 0xFFCFFFEF
_02027988: .word DAT_0208c0ec

	arm_func_start sub_0202798C
sub_0202798C: ; 0x0202798C
	mov r2, #0
	strh r2, [r0]
	sub r1, r2, #1
	stmib r0, {r1, r2}
	str r2, [r0, #0xc]
	bx lr
	arm_func_end sub_0202798C

	arm_func_start _ZN17UnkClass_0202773C12sub_020279A4Ev
_ZN17UnkClass_0202773C12sub_020279A4Ev: ; 0x020279A4
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034DC8Ei
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034DD8Ei
	mov r0, #7
	strh r0, [r4]
	mov r1, #0
	ldr r0, _02027A24 ; =DAT_0208c12c
	str r1, [r4, #4]
	str r0, [r4, #0xc]
	mov r0, #1
	strh r0, [r4, #0x10]
	mov r3, #0x4000000
	ldr r2, [r3]
	ldr r0, _02027A28 ; =0xFFCFFFEF
	mov r1, #0x45
	and r0, r2, r0
	orr r0, r0, #0x10
	str r0, [r3]
	ldr r0, [r4, #0x14]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_020349E8Ei
	ldmia sp!, {r4, pc}
	.align 2, 0
_02027A24: .word DAT_0208c12c
_02027A28: .word 0xFFCFFFEF
	arm_func_end _ZN17UnkClass_0202773C12sub_020279A4Ev

	arm_func_start sub_02027A2C
sub_02027A2C: ; 0x02027A2C
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034DC8Ei
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034DD8Ei
	mov r0, #7
	strh r0, [r4]
	mov r1, #0
	ldr r0, _02027A90 ; =DAT_0208c0fc
	str r1, [r4, #4]
	str r0, [r4, #0xc]
	strh r1, [r4, #0x10]
	ldr r0, [r4, #0x14]
	mov r1, #0x45
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_020349E8Ei
	ldmia sp!, {r4, pc}
	.align 2, 0
_02027A90: .word DAT_0208c0fc
	arm_func_end sub_02027A2C

	arm_func_start sub_02027A94
sub_02027A94: ; 0x02027A94
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, r1
	ldrh r1, [r6, #4]
	mov r7, r0
	mov r5, r2
	strh r1, [r7]
	ldr r0, [r6]
	mov r4, r3
	cmp r0, #0
	ldr r0, [r7, #0x14]
	bge _02027AE8
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA14Ev
	ldr r0, [r7, #0x14]
	mov r1, #1
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	arm_func_end sub_02027A94
_02027AE8:
	add r0, r0, #0x1000
	mov r1, #1
	ldr r0, [r0, #0x490]
	mov r2, r1
	bl _ZN17UnkClass_020091E812sub_02009FB0Emm
	ldr r0, [r7, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	bl _ZN17UnkClass_020091E812sub_0200AA04El
	str r4, [sp]
	ldr r0, [r7, #0x14]
	ldr r1, [r6]
	add r0, r0, #0x1000
	ldr r0, [r0, #0x490]
	ldr r3, [r6, #8]
	mov r2, r5
	bl _ZN17UnkClass_020091E812sub_0200AD34Emmmm
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02027B34
sub_02027B34: ; 0x02027B34
	stmdb sp!, {r4, r5, lr}
	sub sp, sp, #0x1c
	mov r4, r0
	ldr r3, [r4, #4]
	cmp r3, #0
	addlt sp, sp, #0x1c
	ldmltia sp!, {r4, r5, pc}
	ldr r1, [r4, #0xc]
	mov r2, #1
	add r1, r1, r3, lsl #4
	mov r3, #0
	bl sub_02027A94
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #4]
	add r0, r1, r0, lsl #4
	ldrh r0, [r0, #4]
	cmp r0, #4
	bne _02027C04
	add r0, sp, #0x10
	bl RTC_GetTime
	add r0, sp, #0
	bl RTC_GetDate
	ldr r0, _02027CA8 ; =MAIN_BSS_020B26A0
	add r1, sp, #0x10
	add r2, sp, #0
	bl _ZN17UnkClass_020B26A012sub_0201630CEP7RTCTimeP7RTCDate
	ldr r0, [r4, #0x14]
	bl _ZN5CGame12sub_02010324Ev
	ldr r5, [r4, #8]
	cmp r5, #0
	beq _02027BCC
	beq _02027BC4
	mov r0, r5
	bl _ZN17UnkClass_02027FE8D1Ev
	mov r0, r5
	bl _ZdlPv
	arm_func_end sub_02027B34
_02027BC4:
	mov r0, #0
	str r0, [r4, #8]
_02027BCC:
	mov r0, #0x74
	bl _Znwm
	cmp r0, #0
	beq _02027BE4
	mov r1, #1
	bl _ZN17UnkClass_02027FE8C1Em
_02027BE4:
	str r0, [r4, #8]
	ldr r0, _02027CAC ; =MAIN_BSS_0210C1C0
	bl sub_0202A4A0
	ldr r0, _02027CB0 ; =MAIN_BSS_0210C228
	bl sub_0202A4D8
	ldrh r1, [r4, #0x10]
	ldr r0, [r4, #8]
	bl _ZN17UnkClass_02027FE812sub_02028220Em
_02027C04:
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #4]
	add r0, r1, r0, lsl #4
	ldr r1, [r0, #0xc]
	cmp r1, #0
	beq _02027C94
	cmp r1, #0
	ldr r0, [r4, #0x14]
	bge _02027C6C
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r1, #0
	bl _ZN17UnkClass_0203447812sub_02034E38Ei
	ldr r2, [r4, #0xc]
	ldr r1, [r4, #4]
	mvn r0, #1
	add r1, r2, r1, lsl #4
	ldr r1, [r1, #0xc]
	cmp r1, r0
	beq _02027C94
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B68Ei
	b _02027C94
_02027C6C:
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	mov r2, #0
	mov r3, #0x100
	bl _ZN17UnkClass_0203447812sub_02034DE8Eiii
	ldr r0, [r4, #0x14]
	mov r1, #0
	add r0, r0, #0x1000
	ldr r0, [r0, #0x48c]
	bl _ZN17UnkClass_0203447812sub_02034B58Ei
_02027C94:
	ldr r0, [r4, #4]
	add r0, r0, #1
	str r0, [r4, #4]
	add sp, sp, #0x1c
	ldmia sp!, {r4, r5, pc}
	.align 2, 0
_02027CA8: .word MAIN_BSS_020B26A0
_02027CAC: .word MAIN_BSS_0210C1C0
_02027CB0: .word MAIN_BSS_0210C228

	arm_func_start sub_02027CB4
sub_02027CB4: ; 0x02027CB4
	ldrh r0, [r0]
	cmp r0, #5
	movne r0, #1
	moveq r0, #0
	bx lr
	arm_func_end sub_02027CB4

	arm_func_start sub_02027CC8
sub_02027CC8: ; 0x02027CC8
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202B5D0
	ldr r0, _02027CEC ; =ptr_FUN_02027cf0_0208c1a4
	mov r1, #0
	str r0, [r4]
	mov r0, r4
	str r1, [r4, #0x10]
	ldmia sp!, {r4, pc}
	.align 2, 0
_02027CEC: .word ptr_FUN_02027cf0_0208c1a4
	arm_func_end sub_02027CC8

	arm_func_start sub_02027CF0
sub_02027CF0: ; 0x02027CF0
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202B64C
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02027CF0

	arm_func_start sub_02027D04
sub_02027D04: ; 0x02027D04
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_0202B64C
	mov r0, r4
	bl _ZdlPv
	mov r0, r4
	ldmia sp!, {r4, pc}
	arm_func_end sub_02027D04

	arm_func_start sub_02027D20
sub_02027D20: ; 0x02027D20
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x14
	mov r7, r0
	mov r4, #0
	str r4, [r7, #0x10]
	ldr ip, [r7, #4]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp ip, #0
	bne _02027D68
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r0, #0
	addeq sp, sp, #0x14
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, pc}
	arm_func_end sub_02027D20
_02027D68:
	bl CARD_GetBackupPageSize
	bl CARD_GetBackupTotalSize
	ldr r0, [r7, #8]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl CARD_LockBackup
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02027DD8
	str r7, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	mov ip, #0xa
	ldr r3, _02027E50 ; =sub_02027FB4
	mov r0, r5
	mov r1, r6
	mov r2, r4
	str ip, [sp, #0xc]
	mov r4, #2
	str r4, [sp, #0x10]
	bl CARDi_RequestStreamCommand
	b _02027E2C
_02027DD8:
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02027E2C
	str r7, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #7
	str r0, [sp, #8]
	mov ip, #0xa
	ldr r3, _02027E50 ; =sub_02027FB4
	mov r0, r5
	mov r1, r6
	mov r2, r4
	str ip, [sp, #0xc]
	mov r4, #2
	str r4, [sp, #0x10]
	bl CARDi_RequestStreamCommand
_02027E2C:
	bl CARD_GetResultCode
	cmp r0, #0
	str r0, [r7, #0xc]
	ldreq r1, [sp, #0x28]
	movne r0, #0
	moveq r0, #1
	streq r1, [r7, #0x10]
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_02027E50: .word sub_02027FB4

	arm_func_start sub_02027E54
sub_02027E54: ; 0x02027E54
	stmdb sp!, {r4, r5, r6, r7, lr}
	sub sp, sp, #0x14
	mov r7, r0
	ldr ip, [r7, #4]
	mov r6, r1
	mov r5, r2
	mov r4, r3
	cmp ip, #0
	bne _02027E94
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r0, #0
	addeq sp, sp, #0x14
	moveq r0, #0
	ldmeqia sp!, {r4, r5, r6, r7, pc}
	arm_func_end sub_02027E54
_02027E94:
	bl CARD_GetBackupPageSize
	bl CARD_GetBackupTotalSize
	ldr r0, [r7, #8]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl CARD_LockBackup
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #1
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02027F00
	str r7, [sp]
	mov ip, #1
	str ip, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	ldr r3, _02027F6C ; =sub_02027FB4
	mov r0, r6
	mov r1, r5
	mov r2, r4
	str ip, [sp, #0xc]
	mov r4, #0
	str r4, [sp, #0x10]
	bl CARDi_RequestStreamCommand
	b _02027F50
_02027F00:
	bl CARD_GetCurrentBackupType
	and r0, r0, #0xff
	cmp r0, #2
	moveq r0, #1
	movne r0, #0
	cmp r0, #0
	beq _02027F50
	str r7, [sp]
	mov ip, #1
	str ip, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	ldr r3, _02027F6C ; =sub_02027FB4
	mov r0, r6
	mov r1, r5
	mov r2, r4
	str ip, [sp, #0xc]
	mov r4, #0
	str r4, [sp, #0x10]
	bl CARDi_RequestStreamCommand
_02027F50:
	bl CARD_GetResultCode
	str r0, [r7, #0xc]
	cmp r0, #0
	moveq r0, #1
	movne r0, #0
	add sp, sp, #0x14
	ldmia sp!, {r4, r5, r6, r7, pc}
	.align 2, 0
_02027F6C: .word sub_02027FB4

	arm_func_start sub_02027F70
sub_02027F70: ; 0x02027F70
	stmdb sp!, {r4, lr}
	mov r4, r0
	cmp r1, #0
	beq _02027F94
	bl CARD_WaitBackupAsync
	bl CARD_GetResultCode
	str r0, [r4, #0xc]
	mov r0, #1
	ldmia sp!, {r4, pc}
	arm_func_end sub_02027F70
_02027F94:
	bl CARD_TryWaitBackupAsync
	cmp r0, #1
	movne r0, #0
	ldmneia sp!, {r4, pc}
	bl CARD_GetResultCode
	str r0, [r4, #0xc]
	mov r0, #1
	ldmia sp!, {r4, pc}

	arm_func_start sub_02027FB4
sub_02027FB4: ; 0x02027FB4
	stmdb sp!, {r4, lr}
	movs r4, r0
	ldmeqia sp!, {r4, pc}
	ldr r0, [r4, #8]
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	bl CARD_UnlockBackup
	ldr r1, [r4, #0x10]
	cmp r1, #0
	ldmeqia sp!, {r4, pc}
	mov r0, #0
	blx r1
	ldmia sp!, {r4, pc}
	arm_func_end sub_02027FB4

	arm_func_start _ZN17UnkClass_02027FE8C1Em
_ZN17UnkClass_02027FE8C1Em: ; 0x02027FE8
	stmdb sp!, {r3, r4, r5, lr}
	mov r4, r0
	add r0, r4, #4
	mov r5, r1
	bl sub_02027CC8
	add r0, r4, #0x18
	bl sub_0202B8A4
	mov r0, #0
	str r0, [r4, #0x54]
	strb r0, [r4, #0x64]
	str r0, [r4, #0x68]
	str r0, [r4, #0x58]
	str r0, [r4, #0x5c]
	str r0, [r4, #0x6c]
	str r0, [r4, #0x70]
	mov r0, #8
	strh r0, [r4, #0x66]
	bl _ZN5CGame11GetInstanceEv
	add r0, r0, #0x1000
	mov r1, #0
	str r1, [r0, #0x5d4]
	cmp r5, #0
	addne r0, r4, #4
	addeq r0, r4, #0x18
	str r0, [r4]
	mov r0, r4
	ldmia sp!, {r3, r4, r5, pc}
	arm_func_end _ZN17UnkClass_02027FE8C1Em

	arm_func_start _ZN17UnkClass_02027FE8D1Ev
_ZN17UnkClass_02027FE8D1Ev: ; 0x02028054
	stmdb sp!, {r4, lr}
	mov r4, r0
	ldr r0, [r4, #0x58]
	cmp r0, #0
	beq _02028074
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r4, #0x58]
	arm_func_end _ZN17UnkClass_02027FE8D1Ev
_02028074:
	bl _ZN5CGame11GetInstanceEv
	add r1, r0, #0x1000
	mov r2, #1
	add r0, r4, #0x18
	str r2, [r1, #0x5d4]
	bl sub_0202B8D8
	add r0, r4, #4
	bl sub_02027CF0
	mov r0, r4
	ldmia sp!, {r4, pc}

	arm_func_start sub_0202809C
sub_0202809C: ; 0x0202809C
	cmp r1, #0
	beq _020280B4
	cmp r1, #1
	add r1, r0, #4
	str r1, [r0]
	bx lr
	arm_func_end sub_0202809C
_020280B4:
	add r1, r0, #0x18
	str r1, [r0]
	bx lr

	arm_func_start sub_020280C0
sub_020280C0: ; 0x020280C0
	ldr r0, _020280E8 ; =PTR_PTR_LAB_0208c1e4
	ldr r1, [r0, r1, lsl #2]
	ldr r0, [r1]
	cmp r0, #0
	beq _020280E0
	arm_func_end sub_020280C0
_020280D4:
	ldr r0, [r1, #8]!
	cmp r0, #0
	bne _020280D4
_020280E0:
	ldr r0, [r1, #4]
	bx lr
	.align 2, 0
_020280E8: .word PTR_PTR_LAB_0208c1e4

	arm_func_start sub_020280EC
sub_020280EC: ; 0x020280EC
	ldr r2, _0202811C ; =PTR_PTR_LAB_0208c1e4
	mov r0, #0
	ldr r3, [r2, r1, lsl #2]
	ldr r1, [r3]
	cmp r1, #0
	bxeq lr
	arm_func_end sub_020280EC
_02028104:
	ldr r2, [r3, #4]
	ldr r1, [r3, #8]!
	add r0, r0, r2
	cmp r1, #0
	bne _02028104
	bx lr
	.align 2, 0
_0202811C: .word PTR_PTR_LAB_0208c1e4

	arm_func_start sub_02028120
sub_02028120: ; 0x02028120
	ldr ip, _02028128 ; =sub_0202812C
	bx ip
	.align 2, 0
_02028128: .word sub_0202812C
	arm_func_end sub_02028120

	arm_func_start sub_0202812C
sub_0202812C: ; 0x0202812C
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	movs r6, r1
	mov r7, r0
	mov r5, r4
	beq _02028168
	arm_func_end sub_0202812C
_02028144:
	mov r0, r7
	mov r1, r5
	bl sub_02028184
	add r1, r5, #1
	mov r1, r1, lsl #0x10
	cmp r6, r1, lsr #16
	add r4, r4, r0
	mov r5, r1, lsr #0x10
	bhi _02028144
_02028168:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02028170
sub_02028170: ; 0x02028170
	ldr r2, [r0, #0x60]
	ldr r0, [r0, #0x5c]
	add r2, r2, #0x1c
	mla r0, r1, r0, r2
	bx lr
	arm_func_end sub_02028170

	arm_func_start sub_02028184
sub_02028184: ; 0x02028184
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	mov r5, r1
	bl sub_020280EC
	mov r4, r0
	mov r0, r6
	mov r1, r5
	bl sub_020280C0
	mul r0, r4, r0
	add r0, r0, #0x1c
	ldmia sp!, {r4, r5, r6, pc}
	arm_func_end sub_02028184

	arm_func_start sub_020281B0
sub_020281B0: ; 0x020281B0
	stmdb sp!, {r4, r5, r6, lr}
	mov r6, r0
	ldrh r2, [r6, #0x66]
	mov r5, r1
	cmp r2, r5
	ldmeqia sp!, {r4, r5, r6, pc}
	ldr r2, _0202821C ; =PTR_PTR_LAB_0208c1e4
	ldr r2, [r2, r5, lsl #2]
	str r2, [r6, #0x68]
	bl sub_020280EC
	mov r4, r0
	ldr r0, [r6, #0x58]
	cmp r0, #0
	beq _020281F4
	bl _Z9Heap_FreePv
	mov r0, #0
	str r0, [r6, #0x58]
	arm_func_end sub_020281B0
_020281F4:
	mov r0, r4
	bl _Z10Heap_Allocm
	str r0, [r6, #0x58]
	mov r0, r6
	mov r1, r5
	str r4, [r6, #0x5c]
	bl sub_02028120
	str r0, [r6, #0x60]
	strh r5, [r6, #0x66]
	ldmia sp!, {r4, r5, r6, pc}
	.align 2, 0
_0202821C: .word PTR_PTR_LAB_0208c1e4

	arm_func_start _ZN17UnkClass_02027FE812sub_02028220Em
_ZN17UnkClass_02027FE812sub_02028220Em: ; 0x02028220
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl sub_020281B0
	ldr r0, [r5, #0x54]
	cmp r0, #0xd
	bgt _0202825C
	cmp r0, #0xb
	blt _02028250
	cmpne r0, #0xd
	beq _02028288
	b _020282C0
	arm_func_end _ZN17UnkClass_02027FE812sub_02028220Em
_02028250:
	cmp r0, #0
	beq _02028288
	b _020282C0
_0202825C:
	cmp r0, #0x14
	bgt _0202826C
	beq _02028288
	b _020282C0
_0202826C:
	cmp r0, #0x19
	bgt _020282C0
	cmp r0, #0x15
	blt _020282C0
	cmpne r0, #0x18
	cmpne r0, #0x19
	bne _020282C0
_02028288:
	mov r1, #1
	strb r1, [r5, #0x65]
	mov r0, #0
	strb r0, [r5, #0x64]
	str r1, [r5, #0x54]
	strb r0, [r5, #0x64]
	bl _ZN12CPowerManage12sub_0200FA2CEm
	cmp r4, #0
	bne _020282B8
	ldr r0, _020282C8 ; =MAIN_BSS_020B26A0
	mov r1, #1
	bl sub_02016E7C
_020282B8:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_020282C0:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_020282C8: .word MAIN_BSS_020B26A0

	arm_func_start sub_020282CC
sub_020282CC: ; 0x020282CC
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020281B0
	ldr r0, [r4, #0x54]
	cmp r0, #0xd
	bgt _02028304
	cmp r0, #0xb
	blt _020282F8
	cmpne r0, #0xd
	beq _02028330
	b _02028358
	arm_func_end sub_020282CC
_020282F8:
	cmp r0, #0
	beq _02028330
	b _02028358
_02028304:
	cmp r0, #0x14
	bgt _02028314
	beq _02028330
	b _02028358
_02028314:
	cmp r0, #0x19
	bgt _02028358
	cmp r0, #0x15
	blt _02028358
	cmpne r0, #0x18
	cmpne r0, #0x19
	bne _02028358
_02028330:
	mov r0, #2
	strb r0, [r4, #0x65]
	mov r0, #0
	strb r0, [r4, #0x64]
	mov r1, #0xe
	str r1, [r4, #0x54]
	strb r0, [r4, #0x64]
	bl _ZN12CPowerManage12sub_0200FA2CEm
	mov r0, #1
	ldmia sp!, {r4, pc}
_02028358:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_02028360
sub_02028360: ; 0x02028360
	ldr ip, _02028370 ; =sub_020282CC
	mov r2, #1
	str r2, [r0, #0x70]
	bx ip
	.align 2, 0
_02028370: .word sub_020282CC
	arm_func_end sub_02028360

	arm_func_start sub_02028374
sub_02028374: ; 0x02028374
	stmdb sp!, {r4, lr}
	mov r4, r0
	bl sub_020281B0
	ldr r0, [r4, #0x54]
	cmp r0, #0xd
	bgt _020283AC
	cmp r0, #0xb
	blt _020283A0
	cmpne r0, #0xd
	beq _020283D8
	b _02028400
	arm_func_end sub_02028374
_020283A0:
	cmp r0, #0
	beq _020283D8
	b _02028400
_020283AC:
	cmp r0, #0x14
	bgt _020283BC
	beq _020283D8
	b _02028400
_020283BC:
	cmp r0, #0x19
	bgt _02028400
	cmp r0, #0x15
	blt _02028400
	cmpne r0, #0x18
	cmpne r0, #0x19
	bne _02028400
_020283D8:
	mov r0, #3
	strb r0, [r4, #0x65]
	mov r0, #0
	strb r0, [r4, #0x64]
	mov r1, #1
	str r1, [r4, #0x54]
	strb r0, [r4, #0x64]
	bl _ZN12CPowerManage12sub_0200FA2CEm
	mov r0, #1
	ldmia sp!, {r4, pc}
_02028400:
	mov r0, #0
	ldmia sp!, {r4, pc}

	arm_func_start sub_02028408
sub_02028408: ; 0x02028408
	ldr ip, _02028418 ; =sub_020282CC
	mov r2, #1
	str r2, [r0, #0x6c]
	bx ip
	.align 2, 0
_02028418: .word sub_020282CC
	arm_func_end sub_02028408

	arm_func_start _ZN17UnkClass_02027FE812sub_0202841CEv
_ZN17UnkClass_02027FE812sub_0202841CEv: ; 0x0202841C
	stmdb sp!, {r3, lr}
	ldrb r1, [r0, #0x65]
	cmp r1, #1
	beq _02028440
	cmp r1, #2
	beq _0202844C
	cmp r1, #3
	beq _02028454
	b _0202845C
	arm_func_end _ZN17UnkClass_02027FE812sub_0202841CEv
_02028440:
	mov r1, #0
	bl sub_02028464
	ldmia sp!, {r3, pc}
_0202844C:
	bl sub_0202899C
	ldmia sp!, {r3, pc}
_02028454:
	bl sub_02028CEC
	ldmia sp!, {r3, pc}
_0202845C:
	mov r0, #0x80
	ldmia sp!, {r3, pc}

	arm_func_start sub_02028464
sub_02028464: ; 0x02028464
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	mov r6, r0
	ldr r2, [r6, #0x54]
	mov r5, r1
	cmp r2, #0xd
	mov r4, #0
	addls pc, pc, r2, lsl #2
	b _02028980
_02028484: ; jump table
	b _02028980 ; case 0
	b _020284BC ; case 1
	b _02028564 ; case 2
	b _020286F4 ; case 3
	b _02028754 ; case 4
	b _02028980 ; case 5
	b _02028980 ; case 6
	b _020287A8 ; case 7
	b _02028980 ; case 8
	b _020288E4 ; case 9
	b _02028980 ; case 10
	b _02028938 ; case 11
	b _02028980 ; case 12
	b _02028958 ; case 13
	arm_func_end sub_02028464
_020284BC:
	ldr r0, [r6]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r0, #0
	bne _020284E8
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #1
	strb r0, [r6, #0x64]
	b _0202898C
_020284E8:
	ldr r0, _02028994 ; =MAIN_BSS_0210CA38
	ldr r1, [r6, #0x5c]
	ldr r0, [r0]
	add r1, r1, #0x1c
	cmp r1, r0
	bls _02028514
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, r4
	strb r0, [r6, #0x64]
	b _0202898C
_02028514:
	mov r0, r4
	str r0, [sp]
	ldr r0, [r6]
	ldr r1, [r6, #0x60]
	ldr ip, [r0]
	add r2, r6, #0x38
	ldr ip, [ip, #0x14]
	mov r3, #0x1c
	blx ip
	cmp r0, #0
	bne _02028554
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #2
	strb r0, [r6, #0x64]
	b _0202898C
_02028554:
	mov r0, #2
	str r0, [r6, #0x54]
	mov r0, r4
	strb r0, [r6, #0x64]
_02028564:
	ldr r0, [r6]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _0202898C
	ldr r0, [r6]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _020286E0
	mov r0, r6
	bl sub_02028D94
	cmp r0, #0
	beq _02028608
	ldrh r3, [r6, #0x50]
	mov r0, r6
	add r1, r6, #0x38
	mov r2, #0x18
	bl sub_02028E04
	cmp r0, #0
	beq _020285CC
	ldr r0, [r6, #0x60]
	add r0, r0, #0x1c
	str r0, [r6, #0x40]
	b _020285DC
_020285CC:
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #3
	strb r0, [r6, #0x64]
_020285DC:
	cmp r5, #0
	bne _02028678
	ldrh r1, [r6, #0x66]
	mov r0, r6
	bl sub_020280C0
	ldrh r2, [r6, #0x4c]
	mov r1, r0
	add r0, r2, #1
	bl _u32_div_f
	strh r1, [r6, #0x4c]
	b _02028678
_02028608:
	ldr r0, _02028998 ; =PTR_LAB_0208c1c0
	mov r3, #0
_02028610:
	ldr r2, [r0]
	add r1, r6, r3
	ldrsb r2, [r2, r3]
	add r3, r3, #1
	cmp r3, #8
	strb r2, [r1, #0x38]
	blt _02028610
	ldrh r1, [r6, #0x66]
	mov r0, r6
	bl sub_020280C0
	cmp r0, #0
	mov r7, #0
	bls _02028668
	mvn ip, #1
	mov r2, r7
_0202864C:
	add r3, r6, r7, lsl #2
	add r1, r6, r7, lsl #1
	str ip, [r3, #0x40]
	add r7, r7, #1
	strh r2, [r1, #0x48]
	cmp r7, r0
	blo _0202864C
_02028668:
	mov r0, #0
	strh r0, [r6, #0x4c]
	strh r0, [r6, #0x4e]
	strh r0, [r6, #0x52]
_02028678:
	ldrh r1, [r6, #0x4c]
	ldr r2, _02028994 ; =MAIN_BSS_0210CA38
	mov r0, r6
	ldr r7, [r2]
	bl sub_02028170
	ldr r1, [r6, #0x5c]
	add r0, r1, r0
	cmp r0, r7
	bls _020286B0
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #0
	strb r0, [r6, #0x64]
	b _0202898C
_020286B0:
	cmp r5, #0
	beq _020286CC
	mov r0, #7
	str r0, [r6, #0x54]
	mov r0, #0
	strb r0, [r6, #0x64]
	b _0202898C
_020286CC:
	mov r0, #3
	str r0, [r6, #0x54]
	mov r0, #0
	strb r0, [r6, #0x64]
	b _0202898C
_020286E0:
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #3
	strb r0, [r6, #0x64]
	b _0202898C
_020286F4:
	bl sub_02028CFC
	ldrh r1, [r6, #0x4c]
	mov r0, r6
	bl sub_02028170
	mov r1, r4
	str r1, [sp]
	mov r1, r0
	ldr r0, [r6]
	ldr r2, [r6, #0x58]
	ldr r5, [r0]
	ldr r3, [r6, #0x5c]
	ldr r5, [r5, #0x10]
	blx r5
	cmp r0, #0
	bne _02028744
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #4
	strb r0, [r6, #0x64]
	b _0202898C
_02028744:
	mov r0, #4
	str r0, [r6, #0x54]
	mov r0, r4
	strb r0, [r6, #0x64]
_02028754:
	ldr r0, [r6]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _0202898C
	ldr r0, [r6]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _02028794
	mov r0, #7
	str r0, [r6, #0x54]
	mov r0, #0
	strb r0, [r6, #0x64]
	b _0202898C
_02028794:
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #5
	strb r0, [r6, #0x64]
	b _0202898C
_020287A8:
	cmp r5, #0
	ldrh r1, [r6, #0x4c]
	beq _02028854
	add r1, r6, r1, lsl #1
	strh r4, [r1, #0x48]
	ldrh r1, [r6, #0x4c]
	sub r2, r4, #2
	add r1, r6, r1, lsl #2
	str r2, [r1, #0x40]
	ldrh r1, [r6, #0x66]
	bl sub_020280C0
	mov r1, r0
	cmp r1, #1
	movlt r1, #1
	cmp r1, #0
	mov r3, #0
	ble _0202880C
	mvn r0, #1
_020287F0:
	add r2, r6, r3, lsl #2
	ldr r2, [r2, #0x40]
	cmp r2, r0
	bne _0202880C
	add r3, r3, #1
	cmp r3, r1
	blt _020287F0
_0202880C:
	cmp r3, r1
	blt _02028828
	add r0, r6, #0x38
	mov r1, #0
	mov r2, #0x1c
	bl MI_CpuFill8
	b _02028894
_02028828:
	ldrh r2, [r6, #0x4c]
	sub r0, r1, #1
	add r0, r2, r0
	bl _s32_div_f
	strh r1, [r6, #0x4c]
	mov r0, r6
	add r1, r6, #0x38
	mov r2, #0x18
	bl sub_02028DD4
	strh r0, [r6, #0x50]
	b _02028894
_02028854:
	bl sub_02028170
	ldrh r1, [r6, #0x4c]
	add r1, r6, r1, lsl #2
	str r0, [r1, #0x40]
	ldr r1, [r6, #0x58]
	ldr r2, [r6, #0x5c]
	mov r0, r6
	bl sub_02028DD4
	ldrh r3, [r6, #0x4c]
	add r1, r6, #0x38
	mov r2, #0x18
	add r3, r6, r3, lsl #1
	strh r0, [r3, #0x48]
	mov r0, r6
	bl sub_02028DD4
	strh r0, [r6, #0x50]
_02028894:
	mov r0, #0
	str r0, [sp]
	ldr r0, [r6]
	ldr r1, [r6, #0x60]
	ldr r5, [r0]
	add r2, r6, #0x38
	ldr r5, [r5, #0x10]
	mov r3, #0x1c
	blx r5
	cmp r0, #0
	bne _020288D4
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #6
	strb r0, [r6, #0x64]
	b _0202898C
_020288D4:
	mov r0, #9
	str r0, [r6, #0x54]
	mov r0, #0
	strb r0, [r6, #0x64]
_020288E4:
	ldr r0, [r6]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _0202898C
	ldr r0, [r6]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _02028924
	mov r0, #0xb
	str r0, [r6, #0x54]
	mov r0, #0
	strb r0, [r6, #0x64]
	b _0202898C
_02028924:
	mov r0, #0xd
	str r0, [r6, #0x54]
	mov r0, #7
	strb r0, [r6, #0x64]
	b _0202898C
_02028938:
	ldr r0, [r6]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	bl _ZN12CPowerManage12sub_0200FA0CEm
	mov r4, #1
	b _0202898C
_02028958:
	ldr r0, [r6]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	bl _ZN12CPowerManage12sub_0200FA0CEm
	ldrb r0, [r6, #0x64]
	orr r0, r0, #0x80
	and r4, r0, #0xff
	b _0202898C
_02028980:
	mov r0, #0
	mov r4, #0x80
	bl _ZN12CPowerManage12sub_0200FA0CEm
_0202898C:
	mov r0, r4
	ldmia sp!, {r3, r4, r5, r6, r7, pc}
	.align 2, 0
_02028994: .word MAIN_BSS_0210CA38
_02028998: .word PTR_LAB_0208c1c0

	arm_func_start sub_0202899C
sub_0202899C: ; 0x0202899C
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r5, r0
	ldr r1, [r5, #0x54]
	mov r4, #0
	sub r1, r1, #0xe
	cmp r1, #7
	addls pc, pc, r1, lsl #2
	b _02028CD0
_020289C0: ; jump table
	b _020289E0 ; case 0
	b _02028A8C ; case 1
	b _02028B58 ; case 2
	b _02028BF4 ; case 3
	b _02028CD0 ; case 4
	b _02028CD0 ; case 5
	b _02028C88 ; case 6
	b _02028CA8 ; case 7
	arm_func_end sub_0202899C
_020289E0:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r0, #0
	bne _02028A0C
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #1
	strb r0, [r5, #0x64]
	b _02028CDC
_02028A0C:
	ldr r1, [r5, #0x60]
	ldr r0, _02028CE8 ; =MAIN_BSS_0210CA38
	ldr r2, [r5, #0x5c]
	add r3, r1, #0x1c
	ldr r0, [r0]
	add r2, r3, r2, lsl #1
	cmp r2, r0
	bls _02028A40
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
	b _02028CDC
_02028A40:
	mov r0, r4
	str r0, [sp]
	ldr r0, [r5]
	add r2, r5, #0x38
	ldr r6, [r0]
	mov r3, #0x1c
	ldr r6, [r6, #0x14]
	blx r6
	cmp r0, #0
	bne _02028A7C
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #2
	strb r0, [r5, #0x64]
	b _02028CDC
_02028A7C:
	mov r0, #0xf
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
_02028A8C:
	ldr r0, [r5]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _02028CDC
	ldr r0, [r5]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _02028B44
	mov r0, r5
	bl sub_02028D94
	cmp r0, #0
	beq _02028B30
	ldrh r3, [r5, #0x50]
	mov r0, r5
	add r1, r5, #0x38
	mov r2, #0x18
	bl sub_02028E04
	cmp r0, #0
	beq _02028B1C
	ldr r0, [r5, #0x6c]
	cmp r0, #0
	beq _02028B08
	mov r1, #0
	str r1, [r5, #0x6c]
	mov r0, #0x14
	str r0, [r5, #0x54]
	strb r1, [r5, #0x64]
	b _02028CDC
_02028B08:
	mov r0, #0x10
	str r0, [r5, #0x54]
	mov r0, #0
	strb r0, [r5, #0x64]
	b _02028CDC
_02028B1C:
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #3
	strb r0, [r5, #0x64]
	b _02028CDC
_02028B30:
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #0xa
	strb r0, [r5, #0x64]
	b _02028CDC
_02028B44:
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #3
	strb r0, [r5, #0x64]
	b _02028CDC
_02028B58:
	ldr r1, [r5, #0x70]
	cmp r1, #0
	beq _02028B9C
	ldrh r1, [r5, #0x66]
	bl sub_020280C0
	mov r6, r0
	ldrh r1, [r5, #0x66]
	mov r0, r5
	bl sub_020280C0
	ldrh r3, [r5, #0x4c]
	sub r2, r6, #1
	mov r1, r0
	add r0, r3, r2
	bl _u32_div_f
	strh r1, [r5, #0x4c]
	mov r0, r4
	str r0, [r5, #0x70]
_02028B9C:
	mov r0, #0
	str r0, [sp]
	ldr r0, [r5]
	ldrh r1, [r5, #0x4c]
	ldr ip, [r0]
	ldr r2, [r5, #0x58]
	add r1, r5, r1, lsl #2
	ldr r1, [r1, #0x40]
	ldr r3, [r5, #0x5c]
	ldr ip, [ip, #0x14]
	blx ip
	cmp r0, #0
	bne _02028BE4
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #8
	strb r0, [r5, #0x64]
	b _02028CDC
_02028BE4:
	mov r0, #0x11
	str r0, [r5, #0x54]
	mov r0, #0
	strb r0, [r5, #0x64]
_02028BF4:
	ldr r0, [r5]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _02028CDC
	ldr r0, [r5]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _02028C74
	ldrh r0, [r5, #0x4c]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x5c]
	add r0, r5, r0, lsl #1
	ldrh r3, [r0, #0x48]
	mov r0, r5
	bl sub_02028E04
	cmp r0, #0
	beq _02028C60
	mov r0, r5
	bl sub_02028D58
	mov r0, #0x14
	str r0, [r5, #0x54]
	mov r0, #0
	strb r0, [r5, #0x64]
	b _02028CDC
_02028C60:
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #0xb
	strb r0, [r5, #0x64]
	b _02028CDC
_02028C74:
	mov r0, #0x15
	str r0, [r5, #0x54]
	mov r0, #9
	strb r0, [r5, #0x64]
	b _02028CDC
_02028C88:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	mov r4, #1
	bl _ZN12CPowerManage12sub_0200FA0CEm
	b _02028CDC
_02028CA8:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	ldrb r1, [r5, #0x64]
	mov r0, r4
	orr r1, r1, #0x80
	and r4, r1, #0xff
	bl _ZN12CPowerManage12sub_0200FA0CEm
	b _02028CDC
_02028CD0:
	mov r0, #0
	mov r4, #0x80
	bl _ZN12CPowerManage12sub_0200FA0CEm
_02028CDC:
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_02028CE8: .word MAIN_BSS_0210CA38

	arm_func_start sub_02028CEC
sub_02028CEC: ; 0x02028CEC
	ldr ip, _02028CF8 ; =sub_02028464
	mov r1, #1
	bx ip
	.align 2, 0
_02028CF8: .word sub_02028464
	arm_func_end sub_02028CEC

	arm_func_start sub_02028CFC
sub_02028CFC: ; 0x02028CFC
	stmdb sp!, {r3, r4, r5, r6, r7, lr}
	ldr r5, [r0, #0x68]
	ldr r6, [r0, #0x58]
	ldr r0, [r5]
	mov r7, r1
	cmp r0, #0
	ldmeqia sp!, {r3, r4, r5, r6, r7, pc}
	mov r4, #0
	arm_func_end sub_02028CFC
_02028D1C:
	cmp r7, #0
	ldr r2, [r5, #4]
	beq _02028D38
	mov r0, r6
	mov r1, r4
	bl MI_CpuFill8
	b _02028D40
_02028D38:
	mov r1, r6
	bl MI_CpuCopy8
_02028D40:
	ldr r1, [r5, #4]
	ldr r0, [r5, #8]!
	add r6, r6, r1
	cmp r0, #0
	bne _02028D1C
	ldmia sp!, {r3, r4, r5, r6, r7, pc}

	arm_func_start sub_02028D58
sub_02028D58: ; 0x02028D58
	stmdb sp!, {r3, r4, r5, lr}
	ldr r4, [r0, #0x68]
	ldr r5, [r0, #0x58]
	ldr r1, [r4]
	cmp r1, #0
	ldmeqia sp!, {r3, r4, r5, pc}
	arm_func_end sub_02028D58
_02028D70:
	ldr r2, [r4, #4]
	mov r0, r5
	bl MI_CpuCopy8
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]!
	add r5, r5, r0
	cmp r1, #0
	bne _02028D70
	ldmia sp!, {r3, r4, r5, pc}

	arm_func_start sub_02028D94
sub_02028D94: ; 0x02028D94
	ldr r1, _02028DD0 ; =PTR_LAB_0208c1c0
	mov r3, #0
	ldr ip, [r1]
	arm_func_end sub_02028D94
_02028DA0:
	add r1, r0, r3
	ldrsb r2, [r1, #0x38]
	ldrsb r1, [ip]
	cmp r2, r1
	movne r0, #0
	bxne lr
	add r3, r3, #1
	cmp r3, #8
	add ip, ip, #1
	blt _02028DA0
	mov r0, #1
	bx lr
	.align 2, 0
_02028DD0: .word PTR_LAB_0208c1c0

	arm_func_start sub_02028DD4
sub_02028DD4: ; 0x02028DD4
	mov r0, #0
	mov ip, r0
	cmp r2, #0
	bxle lr
	arm_func_end sub_02028DD4
_02028DE4:
	ldrb r3, [r1], #1
	add ip, ip, #1
	cmp ip, r2
	add r0, r0, r3
	mov r0, r0, lsl #0x10
	mov r0, r0, lsr #0x10
	blt _02028DE4
	bx lr

	arm_func_start sub_02028E04
sub_02028E04: ; 0x02028E04
	stmdb sp!, {r4, lr}
	mov r4, r3
	bl sub_02028DD4
	cmp r4, r0
	moveq r0, #1
	movne r0, #0
	ldmia sp!, {r4, pc}
	arm_func_end sub_02028E04

	arm_func_start sub_02028E20
sub_02028E20: ; 0x02028E20
	stmdb sp!, {r3, r4, r5, r6, lr}
	sub sp, sp, #4
	mov r5, r0
	ldr r1, [r5, #0x54]
	mov r4, #0
	cmp r1, #0xd
	addls pc, pc, r1, lsl #2
	b _020292AC
_02028E40: ; jump table
	b _020292AC ; case 0
	b _02028E78 ; case 1
	b _02028F24 ; case 2
	b _02029090 ; case 3
	b _020290F4 ; case 4
	b _020292AC ; case 5
	b _020292AC ; case 6
	b _02029148 ; case 7
	b _020291A4 ; case 8
	b _020291F0 ; case 9
	b _02029244 ; case 10
	b _0202924C ; case 11
	b _0202927C ; case 12
	b _02029284 ; case 13
	arm_func_end sub_02028E20
_02028E78:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #8]
	blx r1
	cmp r0, #0
	bne _02028EA4
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #1
	strb r0, [r5, #0x64]
	b _020292B8
_02028EA4:
	ldr r0, _020292C4 ; =MAIN_BSS_0210CA38
	ldr r1, [r5, #0x5c]
	ldr r0, [r0]
	add r1, r1, #0x1c
	cmp r1, r0
	bls _02028ED0
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
	b _020292B8
_02028ED0:
	mov r0, r4
	str r0, [sp]
	ldr r0, [r5]
	ldr r1, [r5, #0x60]
	ldr ip, [r0]
	add r2, r5, #0x38
	ldr ip, [ip, #0x14]
	mov r3, #0x1c
	blx ip
	cmp r0, #0
	bne _02028F10
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #2
	strb r0, [r5, #0x64]
	b _020292B8
_02028F10:
	mov r0, #2
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
	b _020292B8
_02028F24:
	ldr r0, [r5]
	mov r1, r4
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _020292B8
	ldr r0, [r5]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _0202907C
	mov r0, r5
	bl sub_02028D94
	cmp r0, #0
	beq _02028FC0
	ldrh r3, [r5, #0x50]
	mov r0, r5
	add r1, r5, #0x38
	mov r2, #0x18
	bl sub_02028E04
	cmp r0, #0
	beq _02028F8C
	ldr r0, [r5, #0x60]
	add r0, r0, #0x1c
	str r0, [r5, #0x40]
	b _02028F9C
_02028F8C:
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #3
	strb r0, [r5, #0x64]
_02028F9C:
	ldrh r1, [r5, #0x66]
	mov r0, r5
	bl sub_020280C0
	ldrh r2, [r5, #0x4c]
	mov r1, r0
	add r0, r2, #1
	bl _u32_div_f
	strh r1, [r5, #0x4c]
	b _02029030
_02028FC0:
	ldr r0, _020292C8 ; =PTR_LAB_0208c1c0
	mov r3, r4
_02028FC8:
	ldr r2, [r0]
	add r1, r5, r3
	ldrsb r2, [r2, r3]
	add r3, r3, #1
	cmp r3, #8
	strb r2, [r1, #0x38]
	blt _02028FC8
	ldrh r1, [r5, #0x66]
	mov r0, r5
	bl sub_020280C0
	cmp r0, #0
	mov r6, #0
	bls _02029020
	mvn ip, #1
	mov r2, r6
_02029004:
	add r3, r5, r6, lsl #2
	add r1, r5, r6, lsl #1
	str ip, [r3, #0x40]
	add r6, r6, #1
	strh r2, [r1, #0x48]
	cmp r6, r0
	blo _02029004
_02029020:
	mov r0, #0
	strh r0, [r5, #0x4c]
	strh r0, [r5, #0x4e]
	strh r0, [r5, #0x52]
_02029030:
	ldrh r1, [r5, #0x4c]
	ldr r2, _020292C4 ; =MAIN_BSS_0210CA38
	mov r0, r5
	ldr r6, [r2]
	bl sub_02028170
	ldr r1, [r5, #0x5c]
	add r0, r1, r0
	cmp r0, r6
	bls _02029068
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #0
	strb r0, [r5, #0x64]
	b _020292B8
_02029068:
	mov r0, #3
	str r0, [r5, #0x54]
	mov r0, #0
	strb r0, [r5, #0x64]
	b _020292B8
_0202907C:
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #3
	strb r0, [r5, #0x64]
	b _020292B8
_02029090:
	mov r1, r4
	bl sub_02028CFC
	ldrh r1, [r5, #0x4c]
	mov r0, r5
	bl sub_02028170
	mov r1, r4
	str r1, [sp]
	mov r1, r0
	ldr r0, [r5]
	ldr r2, [r5, #0x58]
	ldr ip, [r0]
	ldr r3, [r5, #0x5c]
	ldr ip, [ip, #0x10]
	blx ip
	cmp r0, #0
	bne _020290E4
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #4
	strb r0, [r5, #0x64]
	b _020292B8
_020290E4:
	mov r0, #4
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
_020290F4:
	ldr r0, [r5]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _020292B8
	ldr r0, [r5]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _02029134
	mov r0, #7
	str r0, [r5, #0x54]
	mov r0, #0
	strb r0, [r5, #0x64]
	b _020292B8
_02029134:
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #5
	strb r0, [r5, #0x64]
	b _020292B8
_02029148:
	ldrh r1, [r5, #0x4c]
	bl sub_02028170
	ldrh r1, [r5, #0x4c]
	add r1, r5, r1, lsl #2
	str r0, [r1, #0x40]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x5c]
	mov r0, r5
	bl sub_02028DD4
	ldrh r3, [r5, #0x4c]
	add r1, r5, #0x38
	mov r2, #0x18
	add r3, r5, r3, lsl #1
	strh r0, [r3, #0x48]
	mov r0, r5
	bl sub_02028DD4
	strh r0, [r5, #0x50]
	mov r0, #0xa
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
	mov r4, #2
	b _020292B8
_020291A4:
	str r4, [sp]
	ldr r0, [r5]
	ldr r1, [r5, #0x60]
	ldr ip, [r0]
	add r2, r5, #0x38
	ldr ip, [ip, #0x10]
	mov r3, #0x1c
	blx ip
	cmp r0, #0
	bne _020291E0
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #6
	strb r0, [r5, #0x64]
	b _020292B8
_020291E0:
	mov r0, #9
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
_020291F0:
	ldr r0, [r5]
	mov r1, #0
	ldr r2, [r0]
	ldr r2, [r2, #0x18]
	blx r2
	cmp r0, #0
	beq _020292B8
	ldr r0, [r5]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _02029230
	mov r0, #0xb
	str r0, [r5, #0x54]
	mov r0, #0
	strb r0, [r5, #0x64]
	b _020292B8
_02029230:
	mov r0, #0xd
	str r0, [r5, #0x54]
	mov r0, #7
	strb r0, [r5, #0x64]
	b _020292B8
_02029244:
	mov r4, #2
	b _020292B8
_0202924C:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	bl _ZN12CPowerManage12sub_0200FA0CEm
	mov r0, #0xc
	str r0, [r5, #0x54]
	mov r0, r4
	strb r0, [r5, #0x64]
	mov r4, #1
	b _020292B8
_0202927C:
	mov r4, #1
	b _020292B8
_02029284:
	ldr r0, [r5]
	ldr r1, [r0]
	ldr r1, [r1, #0xc]
	blx r1
	mov r0, r4
	bl _ZN12CPowerManage12sub_0200FA0CEm
	ldrb r0, [r5, #0x64]
	orr r0, r0, #0x80
	and r4, r0, #0xff
	b _020292B8
_020292AC:
	mov r0, #0
	mov r4, #0x80
	bl _ZN12CPowerManage12sub_0200FA0CEm
_020292B8:
	mov r0, r4
	add sp, sp, #4
	ldmia sp!, {r3, r4, r5, r6, pc}
	.align 2, 0
_020292C4: .word MAIN_BSS_0210CA38
_020292C8: .word PTR_LAB_0208c1c0

	arm_func_start sub_020292CC
sub_020292CC: ; 0x020292CC
	stmdb sp!, {r3, r4, r5, lr}
	mov r5, r0
	mov r4, r1
	bl sub_020281B0
	ldr r0, [r5, #0x54]
	cmp r0, #0xd
	bgt _02029308
	cmp r0, #0xb
	blt _020292FC
	cmpne r0, #0xd
	beq _02029334
	b _0202936C
	arm_func_end sub_020292CC
_020292FC:
	cmp r0, #0
	beq _02029334
	b _0202936C
_02029308:
	cmp r0, #0x14
	bgt _02029318
	beq _02029334
	b _0202936C
_02029318:
	cmp r0, #0x19
	bgt _0202936C
	cmp r0, #0x15
	blt _0202936C
	cmpne r0, #0x18
	cmpne r0, #0x19
	bne _0202936C
_02029334:
	mov r1, #1
	strb r1, [r5, #0x65]
	mov r0, #0
	strb r0, [r5, #0x64]
	str r1, [r5, #0x54]
	strb r0, [r5, #0x64]
	bl _ZN12CPowerManage12sub_0200FA2CEm
	cmp r4, #0
	bne _02029364
	ldr r0, _02029374 ; =MAIN_BSS_020B26A0
	mov r1, #1
	bl sub_02016E7C
_02029364:
	mov r0, #1
	ldmia sp!, {r3, r4, r5, pc}
_0202936C:
	mov r0, #0
	ldmia sp!, {r3, r4, r5, pc}
	.align 2, 0
_02029374: .word MAIN_BSS_020B26A0

	arm_func_start sub_02029378
sub_02029378: ; 0x02029378
	ldr r1, [r0, #0x54]
	cmp r1, #0xa
	movne r0, #0
	bxne lr
	mov r1, #8
	str r1, [r0, #0x54]
	mov r1, #0
	strb r1, [r0, #0x64]
	mov r0, #1
	bx lr
	arm_func_end sub_02029378

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

	arm_func_start sub_0202B5D0
sub_0202B5D0: ; 0x0202B5D0
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
	arm_func_end sub_0202B5D0

	arm_func_start sub_0202B5F4
sub_0202B5F4: ; 0x0202B5F4
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
	arm_func_end sub_0202B5F4

	arm_func_start sub_0202B61C
sub_0202B61C: ; 0x0202B61C
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
	arm_func_end sub_0202B61C

	arm_func_start sub_0202B64C
sub_0202B64C: ; 0x0202B64C
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
	arm_func_end sub_0202B64C

	arm_func_start sub_0202B674
sub_0202B674: ; 0x0202B674
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
	arm_func_end sub_0202B674
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

	arm_func_start sub_0202B6F0
sub_0202B6F0: ; 0x0202B6F0
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
	arm_func_end sub_0202B6F0
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
