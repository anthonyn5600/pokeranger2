    .include "macros.inc"
    .include "include/arm9_02046D5C.inc"

    .section .init, 4
	arm_func_start sub_020841E4
sub_020841E4: ; 0x020841E4
	stmdb sp!, {r3, lr}
	ldr ip, _0208422C ; =MAIN_BSS_0210C1C0
	ldr r0, _02084230 ; =sSaveMagic
	mov r3, #0x60
	str ip, [r0, #0x12c]
	ldr r2, _02084234 ; =MAIN_BSS_0210C228
	str r3, [r0, #0x130]
	str r2, [r0, #0x134]
	mov r1, #0x800
	str r1, [r0, #0x138]
	str ip, [r0, #0x254]
	str r3, [r0, #0x258]
	str r2, [r0, #0x25c]
	str r1, [r0, #0x260]
	bl sub_02010CC0
	ldr r1, _02084230 ; =sSaveMagic
	str r0, [r1, #0x14]
	ldmia sp!, {r3, pc}
	.align 2, 0
_0208422C: .word MAIN_BSS_0210C1C0
_02084230: .word sSaveMagic
_02084234: .word MAIN_BSS_0210C228
	arm_func_end sub_020841E4

	arm_func_start sub_02084238
sub_02084238: ; 0x02084238
	ldr r3, _02084254 ; =MAIN_BSS_0210C1C0
	mov r1, #0
	ldr ip, _02084258 ; =MI_CpuFill8
	ldr r0, _0208425C ; =MAIN_BSS_0210C1C0
	mov r2, #0x60
	str r1, [r3, #0x64]
	bx ip
	.align 2, 0
_02084254: .word MAIN_BSS_0210C1C0
_02084258: .word MI_CpuFill8
_0208425C: .word MAIN_BSS_0210C1C0
	arm_func_end sub_02084238

	arm_func_start sub_02084260
sub_02084260: ; 0x02084260
	ldr r3, _0208427C ; =MAIN_BSS_0210C228
	mov r1, #0
	ldr ip, _02084280 ; =MI_CpuFill8
	ldr r0, _02084284 ; =MAIN_BSS_0210C228
	mov r2, #0x800
	str r1, [r3, #0x804]
	bx ip
	.align 2, 0
_0208427C: .word MAIN_BSS_0210C228
_02084280: .word MI_CpuFill8
_02084284: .word MAIN_BSS_0210C228
	arm_func_end sub_02084260

    .section .ctor, 4
; mwld keeps a .ctor section only through an object named .p__sinit_* (like mwcc's), .sinit is KEEP_SECTION
; but comes after every object's .ctor
	.type .p__sinit_arm9_02046D5C, @object
	.size .p__sinit_arm9_02046D5C, 0xC
.p__sinit_arm9_02046D5C:

	.global ptr_FUN_020841e4_0208a36c
ptr_FUN_020841e4_0208a36c: ; 0x0208A36C
	.word sub_020841E4
	.word sub_02084238
	.word sub_02084260

    .bss
    .global sHeapAllocFunc
sHeapAllocFunc: ; 0x0210CFE4
    .space 0x4

    .global sHeapFreeFunc
sHeapFreeFunc: ; 0x0210CFE8
    .space 0x4
