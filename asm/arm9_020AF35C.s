    .include "macros.inc"
    .include "include/arm9_020AF35C.inc"

; Data of the objects before src/UnkClass_020B26A0.cpp (split off arm9_0210C0A4.s when it landed)

    .section .init, 4
	arm_func_start sub_020840B0
sub_020840B0: ; 0x020840B0
	stmdb sp!, {r3, lr}
	ldr r0, _0208412C ; =MAIN_BSS_020AF5D0
	bl sub_02010EC8
	ldr r0, _0208412C ; =MAIN_BSS_020AF5D0
	ldr r1, _02084130 ; =sub_02010ED4
	ldr r2, _02084134 ; =MAIN_BSS_020AF5B8
	bl __register_global_object
	ldr ip, _02084130 ; =sub_02010ED4
	ldr r0, _02084138 ; =MAIN_BSS_020AF5E4
	ldr r3, _0208413C ; =sub_02010EC8
	mov r1, #3
	mov r2, #0x14
	str ip, [sp]
	bl __cxa_vec_ctor
	ldr r1, _02084140 ; =sub_02011338
	ldr r2, _02084144 ; =MAIN_BSS_020AF5C4
	mov r0, #0
	bl __register_global_object
	ldr r0, _02084148 ; =MAIN_BSS_020AF620
	bl sub_0201100C
	ldr r0, _02084148 ; =MAIN_BSS_020AF620
	ldr r1, _0208414C ; =sub_0201101C
	ldr r2, _02084150 ; =MAIN_BSS_020AF5AC
	bl __register_global_object
	ldr r0, _02084154 ; =MAIN_BSS_020AF598
	bl sub_02011248
	ldr r0, _02084154 ; =MAIN_BSS_020AF598
	ldr r1, _02084158 ; =sub_02011254
	ldr r2, _0208415C ; =MAIN_BSS_020AF5A0
	bl __register_global_object
	ldmia sp!, {r3, pc}
	.align 2, 0
_0208412C: .word MAIN_BSS_020AF5D0
_02084130: .word sub_02010ED4
_02084134: .word MAIN_BSS_020AF5B8
_02084138: .word MAIN_BSS_020AF5E4
_0208413C: .word sub_02010EC8
_02084140: .word sub_02011338
_02084144: .word MAIN_BSS_020AF5C4
_02084148: .word MAIN_BSS_020AF620
_0208414C: .word sub_0201101C
_02084150: .word MAIN_BSS_020AF5AC
_02084154: .word MAIN_BSS_020AF598
_02084158: .word sub_02011254
_0208415C: .word MAIN_BSS_020AF5A0
	arm_func_end sub_020840B0

	arm_func_start sub_02084160
sub_02084160: ; 0x02084160
	stmdb sp!, {r3, lr}
	ldr r0, _02084180 ; =MAIN_BSS_020B2638
	bl sub_02011370
	ldr r0, _02084180 ; =MAIN_BSS_020B2638
	ldr r1, _02084184 ; =sub_02011384
	ldr r2, _02084188 ; =MAIN_BSS_020B262C
	bl __register_global_object
	ldmia sp!, {r3, pc}
	.align 2, 0
_02084180: .word MAIN_BSS_020B2638
_02084184: .word sub_02011384
_02084188: .word MAIN_BSS_020B262C
	arm_func_end sub_02084160


    .section .ctor, 4
; mwld keeps a .ctor section only through an object named .p__sinit_* (like mwcc's)
	.type .p__sinit_arm9_020AF35C, @object
	.size .p__sinit_arm9_020AF35C, 0x8
.p__sinit_arm9_020AF35C:
	.word sub_020840B0
	.word sub_02084160

    .bss

    .global MAIN_BSS_020AF35C
MAIN_BSS_020AF35C: ; 0x020AF35C
    .space 0x72

    .global MAIN_BSS_020AF3CE
MAIN_BSS_020AF3CE: ; 0x020AF3CE
    .space 0x1CA

    .global MAIN_BSS_020AF598
MAIN_BSS_020AF598: ; 0x020AF598
    .space 0x8

    .global MAIN_BSS_020AF5A0
MAIN_BSS_020AF5A0: ; 0x020AF5A0
    .space 0xC

    .global MAIN_BSS_020AF5AC
MAIN_BSS_020AF5AC: ; 0x020AF5AC
    .space 0xC

    .global MAIN_BSS_020AF5B8
MAIN_BSS_020AF5B8: ; 0x020AF5B8
    .space 0xC

    .global MAIN_BSS_020AF5C4
MAIN_BSS_020AF5C4: ; 0x020AF5C4
    .space 0xC

    .global MAIN_BSS_020AF5D0
MAIN_BSS_020AF5D0: ; 0x020AF5D0
    .space 0x14

    .global MAIN_BSS_020AF5E4
MAIN_BSS_020AF5E4: ; 0x020AF5E4
    .space 0x14

    .global MAIN_BSS_020AF5F8
MAIN_BSS_020AF5F8: ; 0x020AF5F8
    .space 0x14

    .global MAIN_BSS_020AF60C
MAIN_BSS_020AF60C: ; 0x020AF60C
    .space 0x14

    .global MAIN_BSS_020AF620
MAIN_BSS_020AF620: ; 0x020AF620
    .space 0x4

    .global MAIN_BSS_020AF624
MAIN_BSS_020AF624: ; 0x020AF624
    .space 0xA05

    .global MAIN_BSS_020B0029
MAIN_BSS_020B0029: ; 0x020B0029
    .space 0x1

    .global MAIN_BSS_020B002A
MAIN_BSS_020B002A: ; 0x020B002A
    .space 0x1

    .global MAIN_BSS_020B002B
MAIN_BSS_020B002B: ; 0x020B002B
    .space 0x1

    .global MAIN_BSS_020B002C
MAIN_BSS_020B002C: ; 0x020B002C
    .space 0x2600

    .global MAIN_BSS_020B262C
MAIN_BSS_020B262C: ; 0x020B262C
    .space 0xC

    .global MAIN_BSS_020B2638
MAIN_BSS_020B2638: ; 0x020B2638
    .space 0x5C
