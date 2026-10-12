    .include "macros.inc"
    .include "include/arm9_0208D58C.inc"

; Main .data of the objects before src/FieldActor.cpp (whose data comes from C++)

    .data
    .balign 4
	.global PTR_ptr_FUN_020835bc_0208dbd0
PTR_ptr_FUN_020835bc_0208dbd0: ; 0x0208DBD0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFDarkness_0208dbdc
	.word _ZTI28CFieldScreenEffectObjectBase

	.global s_17CFieldSEFDarkness_0208dbdc
s_17CFieldSEFDarkness_0208dbdc: ; 0x0208DBDC
	.asciz "17CFieldSEFDarkness"

	.global _0208DBF0
_0208DBF0:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208dbd0

	.global ptr_FUN_0203bcc4_0208dbf8
ptr_FUN_0203bcc4_0208dbf8: ; 0x0208DBF8
	.word sub_0203BCC4

	.global ptr_FUN_0203bc64_0208dbfc
ptr_FUN_0203bc64_0208dbfc: ; 0x0208DBFC
	.word sub_0203BC64
	.word sub_0203BCBC

	.global ptr_FUN_0203b4a0_0208dc04
ptr_FUN_0203b4a0_0208dc04: ; 0x0208DC04
	.word sub_0203B4A0

	.global ptr_FUN_0203b608_0208dc08
ptr_FUN_0203b608_0208dc08: ; 0x0208DC08
	.word sub_0203B608

	.global ptr_FUN_0203bc14_0208dc0c
ptr_FUN_0203bc14_0208dc0c: ; 0x0208DC0C
	.word sub_0203BC14
	.word _ZN28CFieldScreenEffectObjectBase4StopEi

	.global s_data_field_effect_dokarimo03_ntf_0208dc14
s_data_field_effect_dokarimo03_ntf_0208dc14: ; 0x0208DC14
	.asciz "data/field/effect/dokarimo03.ntft"

	.global _0208DC36
_0208DC36:
	.byte 0x00, 0x00

	.global s_data_field_effect_dokarimo03_ntf_0208dc38
s_data_field_effect_dokarimo03_ntf_0208dc38: ; 0x0208DC38
	.asciz "data/field/effect/dokarimo03.ntfp"

	.global _0208DC5A
_0208DC5A:
	.byte 0x00, 0x00
