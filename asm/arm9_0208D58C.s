    .include "macros.inc"
    .include "include/arm9_0208D58C.inc"

; Main .data of the objects before src/FieldActor.cpp (whose data comes from C++)

    .data
    .balign 4
	.global DAT_0208d58c
DAT_0208d58c: ; 0x0208D58C
	.byte 0x3C, 0x00, 0x00, 0x00

	.global s_GetEnemyLabel2PartnerIndex_index_0208d590
s_GetEnemyLabel2PartnerIndex_index_0208d590: ; 0x0208D590
	.asciz "GetEnemyLabel2PartnerIndex(index= %d)"

	.global _0208D5B6
_0208D5B6:
	.byte 0x00, 0x00

	.global s_GetPartnerIndex2EnemyLabel_index_0208d5b8
s_GetPartnerIndex2EnemyLabel_index_0208d5b8: ; 0x0208D5B8
	.asciz "GetPartnerIndex2EnemyLabel(index= %d)"

	.global _0208D5DE
_0208D5DE:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_02083578_0208d5e0
PTR_ptr_FUN_02083578_0208d5e0: ; 0x0208D5E0
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_28CFieldScreenEffectObjectBase_0208d5e8

	.global s_28CFieldScreenEffectObjectBase_0208d5e8
s_28CFieldScreenEffectObjectBase_0208d5e8: ; 0x0208D5E8
	.asciz "28CFieldScreenEffectObjectBase"

	.global _0208D607
_0208D607:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_02083578_0208d5e0

	.global PTR_LAB_0208d610
PTR_LAB_0208d610: ; 0x0208D610
	.word sub_02035FE4

	.global ptr_FUN_020357f8_0208d614
ptr_FUN_020357f8_0208d614: ; 0x0208D614
	.word sub_020357F8
	.word sub_02035D30

	.global ptr_FUN_02035334_0208d61c
ptr_FUN_02035334_0208d61c: ; 0x0208D61C
	.word sub_02035334
	.word sub_020358FC

	.global ptr_FUN_020354e0_0208d624
ptr_FUN_020354e0_0208d624: ; 0x0208D624
	.word sub_020354E0
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208d62c
PTR_ptr_FUN_020835bc_0208d62c: ; 0x0208D62C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CPrimitiveQuadNTF_0208d644
	.word _ZTI10CPrimitive

	.global PTR_ptr_FUN_020835bc_0208d638
PTR_ptr_FUN_020835bc_0208d638: ; 0x0208D638
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CPrimitiveRectNTF_0208d66c
	.word _ZTI10CPrimitive

	.global s_17CPrimitiveQuadNTF_0208d644
s_17CPrimitiveQuadNTF_0208d644: ; 0x0208D644
	.asciz "17CPrimitiveQuadNTF"

	.global _0208D658
_0208D658:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d638

	.global ptr_FUN_02036908_0208d660
ptr_FUN_02036908_0208d660: ; 0x0208D660
	.word sub_02036908

	.global ptr_FUN_020368ec_0208d664
ptr_FUN_020368ec_0208d664: ; 0x0208D664
	.word sub_020368EC

	.global ptr_FUN_02036558_0208d668
ptr_FUN_02036558_0208d668: ; 0x0208D668
	.word sub_02036558

	.global s_17CPrimitiveRectNTF_0208d66c
s_17CPrimitiveRectNTF_0208d66c: ; 0x0208D66C
	.asciz "17CPrimitiveRectNTF"

	.global _0208D680
_0208D680:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d62c

	.global ptr_FUN_020368d8_0208d688
ptr_FUN_020368d8_0208d688: ; 0x0208D688
	.word sub_020368D8
	.word sub_020368BC

	.global ptr_FUN_020367b8_0208d690
ptr_FUN_020367b8_0208d690: ; 0x0208D690
	.word sub_020367B8

	.global DAT_0208d694
DAT_0208d694: ; 0x0208D694
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global s_data_Field_Effect_ew_03d_LZ_bin_0208d73c
s_data_Field_Effect_ew_03d_LZ_bin_0208d73c: ; 0x0208D73C
	.asciz "data/Field/Effect/ew%03d_LZ.bin"

	.global DAT_0208d75c
DAT_0208d75c: ; 0x0208D75C
	.byte 0x4D, 0x45, 0x46, 0x00

	.global s_MEF_ew_03d_NCLR_0208d760
s_MEF_ew_03d_NCLR_0208d760: ; 0x0208D760
	.asciz "MEF:ew%03d.NCLR"

	.global s_MEF_ew_03d_NCBR_0208d770
s_MEF_ew_03d_NCBR_0208d770: ; 0x0208D770
	.asciz "MEF:ew%03d.NCBR"

	.global s_MEF_ew_03d_NCER_0208d780
s_MEF_ew_03d_NCER_0208d780: ; 0x0208D780
	.asciz "MEF:ew%03d.NCER"

	.global s_MEF_ew_03d_cac_0208d790
s_MEF_ew_03d_cac_0208d790: ; 0x0208D790
	.asciz "MEF:ew%03d.cac"

	.global _0208D79F
_0208D79F:
	.byte 0x00

	.global PTR_ptr_FUN_020835bc_0208d7a0
PTR_ptr_FUN_020835bc_0208d7a0: ; 0x0208D7A0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFKomorebi_0208d7ac
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_17CFieldSEFKomorebi_0208d7ac
s_17CFieldSEFKomorebi_0208d7ac: ; 0x0208D7AC
	.asciz "17CFieldSEFKomorebi"

	.global _0208D7C0
_0208D7C0:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d7a0

	.global ptr_FUN_020369b4_0208d7c8
ptr_FUN_020369b4_0208d7c8: ; 0x0208D7C8
	.word sub_020369B4

	.global ptr_FUN_020369e4_0208d7cc
ptr_FUN_020369e4_0208d7cc: ; 0x0208D7CC
	.word sub_020369E4
	.word sub_02037354

	.global ptr_FUN_02036a1c_0208d7d4
ptr_FUN_02036a1c_0208d7d4: ; 0x0208D7D4
	.word sub_02036A1C

	.global ptr_FUN_02036b1c_0208d7d8
ptr_FUN_02036b1c_0208d7d8: ; 0x0208D7D8
	.word sub_02036B1C

	.global ptr_FUN_0203733c_0208d7dc
ptr_FUN_0203733c_0208d7dc: ; 0x0208D7DC
	.word sub_0203733C
	.word sub_02035590

	.global s_data_field_effect_komorebi_ntft_0208d7e4
s_data_field_effect_komorebi_ntft_0208d7e4: ; 0x0208D7E4
	.asciz "data/field/effect/komorebi.ntft"

	.global s_data_field_effect_komorebi_ntfp_0208d804
s_data_field_effect_komorebi_ntfp_0208d804: ; 0x0208D804
	.asciz "data/field/effect/komorebi.ntfp"

	.global PTR_ptr_FUN_020835bc_0208d824
PTR_ptr_FUN_020835bc_0208d824: ; 0x0208D824
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_12CFieldSEFFog_0208d830
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_12CFieldSEFFog_0208d830
s_12CFieldSEFFog_0208d830: ; 0x0208D830
	.asciz "12CFieldSEFFog"

	.global _0208D83F
_0208D83F:
	.byte 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d824

	.global ptr_FUN_02037988_0208d848
ptr_FUN_02037988_0208d848: ; 0x0208D848
	.word sub_02037988

	.global ptr_FUN_02037938_0208d84c
ptr_FUN_02037938_0208d84c: ; 0x0208D84C
	.word sub_02037938
	.word sub_02037980

	.global ptr_FUN_02037540_0208d854
ptr_FUN_02037540_0208d854: ; 0x0208D854
	.word sub_02037540

	.global ptr_FUN_020377c0_0208d858
ptr_FUN_020377c0_0208d858: ; 0x0208D858
	.word sub_020377C0

	.global ptr_FUN_02037914_0208d85c
ptr_FUN_02037914_0208d85c: ; 0x0208D85C
	.word sub_02037914
	.word sub_02035590

	.global DAT_0208d864
DAT_0208d864: ; 0x0208D864
	.byte 0xDE, 0x7B, 0x00, 0x00

	.global DAT_0208d868
DAT_0208d868: ; 0x0208D868
	.byte 0x18, 0x00, 0x00, 0x00

	.global DAT_0208d86c
DAT_0208d86c: ; 0x0208D86C
	.byte 0x08, 0x21, 0x00, 0x00

	.global DAT_0208d870
DAT_0208d870: ; 0x0208D870
	.byte 0x0E, 0x00, 0x00, 0x00

	.global DAT_0208d874
DAT_0208d874: ; 0x0208D874
	.byte 0x1E, 0x78, 0x00, 0x00

	.global DAT_0208d878
DAT_0208d878: ; 0x0208D878
	.byte 0x10, 0x00, 0x00, 0x00

	.global DAT_0208d87c
DAT_0208d87c: ; 0x0208D87C
	.byte 0xDE, 0x03, 0x00, 0x00

	.global DAT_0208d880
DAT_0208d880: ; 0x0208D880
	.byte 0x18, 0x00, 0x00, 0x00

	.global DAT_0208d884
DAT_0208d884: ; 0x0208D884
	.byte 0xDE, 0x7B, 0x00, 0x00

	.global DAT_0208d888
DAT_0208d888: ; 0x0208D888
	.byte 0x08, 0x00, 0x00, 0x00

	.global s_data_field_effect_kiri02_ntft_0208d88c
s_data_field_effect_kiri02_ntft_0208d88c: ; 0x0208D88C
	.asciz "data/field/effect/kiri02.ntft"

	.global _0208D8AA
_0208D8AA:
	.byte 0x00, 0x00

	.global s_data_field_effect_kiri02_ntfp_0208d8ac
s_data_field_effect_kiri02_ntfp_0208d8ac: ; 0x0208D8AC
	.asciz "data/field/effect/kiri02.ntfp"

	.global _0208D8CA
_0208D8CA:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208d8cc
PTR_ptr_FUN_020835bc_0208d8cc: ; 0x0208D8CC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_18CFieldSEFSandStorm_0208d8d8
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_18CFieldSEFSandStorm_0208d8d8
s_18CFieldSEFSandStorm_0208d8d8: ; 0x0208D8D8
	.asciz "18CFieldSEFSandStorm"

	.global _0208D8ED
_0208D8ED:
	.byte 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d8cc

	.global ptr_FUN_02037fb0_0208d8f8
ptr_FUN_02037fb0_0208d8f8: ; 0x0208D8F8
	.word sub_02037FB0

	.global ptr_FUN_02037f60_0208d8fc
ptr_FUN_02037f60_0208d8fc: ; 0x0208D8FC
	.word sub_02037F60
	.word sub_02037FA8

	.global ptr_FUN_02037af4_0208d904
ptr_FUN_02037af4_0208d904: ; 0x0208D904
	.word sub_02037AF4

	.global ptr_FUN_02037de8_0208d908
ptr_FUN_02037de8_0208d908: ; 0x0208D908
	.word sub_02037DE8

	.global ptr_FUN_02037f3c_0208d90c
ptr_FUN_02037f3c_0208d90c: ; 0x0208D90C
	.word sub_02037F3C
	.word sub_02035590

	.global s_data_field_effect_suna01_ntft_0208d914
s_data_field_effect_suna01_ntft_0208d914: ; 0x0208D914
	.asciz "data/field/effect/suna01.ntft"

	.global _0208D932
_0208D932:
	.byte 0x00, 0x00

	.global s_data_field_effect_suna01_ntfp_0208d934
s_data_field_effect_suna01_ntfp_0208d934: ; 0x0208D934
	.asciz "data/field/effect/suna01.ntfp"

	.global _0208D952
_0208D952:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208d954
PTR_ptr_FUN_020835bc_0208d954: ; 0x0208D954
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFDokarimo_0208d960
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_17CFieldSEFDokarimo_0208d960
s_17CFieldSEFDokarimo_0208d960: ; 0x0208D960
	.asciz "17CFieldSEFDokarimo"

	.global _0208D974
_0208D974:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d954

	.global ptr_FUN_02038998_0208d97c
ptr_FUN_02038998_0208d97c: ; 0x0208D97C
	.word sub_02038998

	.global ptr_FUN_02038938_0208d980
ptr_FUN_02038938_0208d980: ; 0x0208D980
	.word sub_02038938
	.word sub_02038990

	.global ptr_FUN_02038178_0208d988
ptr_FUN_02038178_0208d988: ; 0x0208D988
	.word sub_02038178

	.global ptr_FUN_020382e0_0208d98c
ptr_FUN_020382e0_0208d98c: ; 0x0208D98C
	.word sub_020382E0

	.global ptr_FUN_020388e8_0208d990
ptr_FUN_020388e8_0208d990: ; 0x0208D990
	.word sub_020388E8
	.word sub_02035590

	.global s_data_field_effect_dokarimo03_ntf_0208d998
s_data_field_effect_dokarimo03_ntf_0208d998: ; 0x0208D998
	.asciz "data/field/effect/dokarimo03.ntft"

	.global _0208D9BA
_0208D9BA:
	.byte 0x00, 0x00

	.global s_data_field_effect_dokarimo03_ntf_0208d9bc
s_data_field_effect_dokarimo03_ntf_0208d9bc: ; 0x0208D9BC
	.asciz "data/field/effect/dokarimo03.ntfp"

	.global _0208D9DE
_0208D9DE:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208d9e0
PTR_ptr_FUN_020835bc_0208d9e0: ; 0x0208D9E0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFTheWater_0208d9ec
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_17CFieldSEFTheWater_0208d9ec
s_17CFieldSEFTheWater_0208d9ec: ; 0x0208D9EC
	.asciz "17CFieldSEFTheWater"

	.global _0208DA00
_0208DA00:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208d9e0

	.global ptr_FUN_02038cd4_0208da08
ptr_FUN_02038cd4_0208da08: ; 0x0208DA08
	.word sub_02038CD4

	.global ptr_FUN_02038c94_0208da0c
ptr_FUN_02038c94_0208da0c: ; 0x0208DA0C
	.word sub_02038C94
	.word sub_02038CCC

	.global ptr_FUN_02038b04_0208da14
ptr_FUN_02038b04_0208da14: ; 0x0208DA14
	.word sub_02038B04

	.global ptr_FUN_02038bc4_0208da18
ptr_FUN_02038bc4_0208da18: ; 0x0208DA18
	.word sub_02038BC4

	.global ptr_FUN_02038c70_0208da1c
ptr_FUN_02038c70_0208da1c: ; 0x0208DA1C
	.word sub_02038C70
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208da24
PTR_ptr_FUN_020835bc_0208da24: ; 0x0208DA24
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_15CFieldSEFHinoko_0208da3c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global PTR_ptr_FUN_020835bc_0208da30
PTR_ptr_FUN_020835bc_0208da30: ; 0x0208DA30
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_27CFieldScreenEffectActorData_0208da50
	.word PTR_ptr_FUN_020835bc_0208c468

	.global s_15CFieldSEFHinoko_0208da3c
s_15CFieldSEFHinoko_0208da3c: ; 0x0208DA3C
	.asciz "15CFieldSEFHinoko"

	.global _0208DA4E
_0208DA4E:
	.byte 0x00, 0x00

	.global s_27CFieldScreenEffectActorData_0208da50
s_27CFieldScreenEffectActorData_0208da50: ; 0x0208DA50
	.asciz "27CFieldScreenEffectActorData"

	.global _0208DA6E
_0208DA6E:
	.byte 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208da24

	.global ptr_FUN_02039ddc_0208da78
ptr_FUN_02039ddc_0208da78: ; 0x0208DA78
	.word sub_02039DDC

	.global ptr_FUN_02039d90_0208da7c
ptr_FUN_02039d90_0208da7c: ; 0x0208DA7C
	.word sub_02039D90
	.word sub_02039DC8

	.global ptr_FUN_02038dec_0208da84
ptr_FUN_02038dec_0208da84: ; 0x0208DA84
	.word sub_02038DEC

	.global ptr_FUN_02039510_0208da88
ptr_FUN_02039510_0208da88: ; 0x0208DA88
	.word sub_02039510

	.global ptr_FUN_02039d6c_0208da8c
ptr_FUN_02039d6c_0208da8c: ; 0x0208DA8C
	.word sub_02039D6C
	.word sub_02035590
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208da30

	.global PTR_LAB_0208da9c
PTR_LAB_0208da9c: ; 0x0208DA9C
	.word sub_02039E0C

	.global ptr_FUN_02039d50_0208daa0
ptr_FUN_02039d50_0208daa0: ; 0x0208DAA0
	.word sub_02039D50

	.global ptr_FUN_020297dc_0208daa4
ptr_FUN_020297dc_0208daa4: ; 0x0208DAA4
	.word sub_020297DC

	.global ptr_FUN_020297b0_0208daa8
ptr_FUN_020297b0_0208daa8: ; 0x0208DAA8
	.word sub_020297B0

	.global ptr_FUN_02029784_0208daac
ptr_FUN_02029784_0208daac: ; 0x0208DAAC
	.word sub_02029784

	.global ptr_FUN_0202977c_0208dab0
ptr_FUN_0202977c_0208dab0: ; 0x0208DAB0
	.word sub_0202977C

	.global ptr_FUN_020394d4_0208dab4
ptr_FUN_020394d4_0208dab4: ; 0x0208DAB4
	.word sub_020394D4
	.word sub_02029770
	.word sub_02029704

	.global s_data_field_effect_kiri02_ntft_0208dac0
s_data_field_effect_kiri02_ntft_0208dac0: ; 0x0208DAC0
	.asciz "data/field/effect/kiri02.ntft"

	.global _0208DADE
_0208DADE:
	.byte 0x00, 0x00

	.global s_data_field_effect_kiri02_ntfp_0208dae0
s_data_field_effect_kiri02_ntfp_0208dae0: ; 0x0208DAE0
	.asciz "data/field/effect/kiri02.ntfp"

	.global _0208DAFE
_0208DAFE:
	.byte 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208db00
PTR_ptr_FUN_020835bc_0208db00: ; 0x0208DB00
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_13CFieldSEFRain_0208db0c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_13CFieldSEFRain_0208db0c
s_13CFieldSEFRain_0208db0c: ; 0x0208DB0C
	.asciz "13CFieldSEFRain"

	.global _0208DB1C
_0208DB1C:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208db00

	.global ptr_FUN_0203a734_0208db24
ptr_FUN_0203a734_0208db24: ; 0x0208DB24
	.word sub_0203A734

	.global ptr_FUN_0203a6cc_0208db28
ptr_FUN_0203a6cc_0208db28: ; 0x0208DB28
	.word sub_0203A6CC
	.word sub_0203A72C

	.global ptr_FUN_0203a068_0208db30
ptr_FUN_0203a068_0208db30: ; 0x0208DB30
	.word sub_0203A068

	.global ptr_FUN_0203a3cc_0208db34
ptr_FUN_0203a3cc_0208db34: ; 0x0208DB34
	.word sub_0203A3CC
	.word sub_0203A70C
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208db40
PTR_ptr_FUN_020835bc_0208db40: ; 0x0208DB40
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CFieldSEFWarning_0208db4c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_16CFieldSEFWarning_0208db4c
s_16CFieldSEFWarning_0208db4c: ; 0x0208DB4C
	.asciz "16CFieldSEFWarning"

	.global _0208DB5F
_0208DB5F:
	.byte 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208db40

	.global ptr_FUN_0203aa14_0208db68
ptr_FUN_0203aa14_0208db68: ; 0x0208DB68
	.word sub_0203AA14

	.global ptr_FUN_0203a9d4_0208db6c
ptr_FUN_0203a9d4_0208db6c: ; 0x0208DB6C
	.word sub_0203A9D4
	.word sub_0203AA0C

	.global ptr_FUN_0203a854_0208db74
ptr_FUN_0203a854_0208db74: ; 0x0208DB74
	.word sub_0203A854

	.global ptr_FUN_0203a934_0208db78
ptr_FUN_0203a934_0208db78: ; 0x0208DB78
	.word sub_0203A934

	.global ptr_FUN_020354e0_0208db7c
ptr_FUN_020354e0_0208db7c: ; 0x0208DB7C
	.word sub_020354E0
	.word sub_02035590

	.global DAT_0208db84
DAT_0208db84: ; 0x0208DB84
	.byte 0xCC, 0x04, 0x00, 0x00

	.global DAT_0208db88
DAT_0208db88: ; 0x0208DB88
	.byte 0x00, 0x08, 0x00, 0x00

	.global DAT_0208db8c
DAT_0208db8c: ; 0x0208DB8C
	.byte 0x33, 0x0B, 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208db90
PTR_ptr_FUN_020835bc_0208db90: ; 0x0208DB90
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_13CFieldSEFSnow_0208db9c
	.word PTR_ptr_FUN_02083578_0208d5e0

	.global s_13CFieldSEFSnow_0208db9c
s_13CFieldSEFSnow_0208db9c: ; 0x0208DB9C
	.asciz "13CFieldSEFSnow"

	.global _0208DBAC
_0208DBAC:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208db90

	.global ptr_FUN_0203b314_0208dbb4
ptr_FUN_0203b314_0208dbb4: ; 0x0208DBB4
	.word sub_0203B314

	.global ptr_FUN_0203b2cc_0208dbb8
ptr_FUN_0203b2cc_0208dbb8: ; 0x0208DBB8
	.word sub_0203B2CC
	.word sub_0203B30C

	.global ptr_FUN_0203ab28_0208dbc0
ptr_FUN_0203ab28_0208dbc0: ; 0x0208DBC0
	.word sub_0203AB28

	.global ptr_FUN_0203add8_0208dbc4
ptr_FUN_0203add8_0208dbc4: ; 0x0208DBC4
	.word sub_0203ADD8

	.global ptr_FUN_0203b2a8_0208dbc8
ptr_FUN_0203b2a8_0208dbc8: ; 0x0208DBC8
	.word sub_0203B2A8
	.word sub_02035590

	.global PTR_ptr_FUN_020835bc_0208dbd0
PTR_ptr_FUN_020835bc_0208dbd0: ; 0x0208DBD0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CFieldSEFDarkness_0208dbdc
	.word PTR_ptr_FUN_02083578_0208d5e0

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
	.word sub_02035590

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
