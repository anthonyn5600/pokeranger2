    .include "macros.inc"
    .include "include/arm9_0208DDB8.inc"

; Main .data after CFieldActorManage's typeinfo (which comes from src/CFieldActorManage.cpp)

    .data
    .balign 4

	.global _0208DDB8
_0208DDB8:
	.byte 0x00, 0x00, 0x00, 0x00
	.word _ZTI17CFieldActorManage

	.global PTR_LAB_0208ddc0
PTR_LAB_0208ddc0: ; 0x0208DDC0
	.word sub_0203EF64

	.global ptr_FUN_0203ef8c_0208ddc4
ptr_FUN_0203ef8c_0208ddc4: ; 0x0208DDC4
	.word sub_0203EF8C

	.global ptr_FUN_0203efe4_0208ddc8
ptr_FUN_0203efe4_0208ddc8: ; 0x0208DDC8
	.word _ZN17CFieldActorManage12sub_0203EFE4Ei

	.global ptr_FUN_0203f034_0208ddcc
ptr_FUN_0203f034_0208ddcc: ; 0x0208DDCC
	.word _ZN17CFieldActorManage12sub_0203F034Ev

	.global ptr_FUN_0203f0c0_0208ddd0
ptr_FUN_0203f0c0_0208ddd0: ; 0x0208DDD0
	.word _ZN17CFieldActorManage12sub_0203F0C0Ev

	.global ptr_FUN_0203f144_0208ddd4
ptr_FUN_0203f144_0208ddd4: ; 0x0208DDD4
	.word _ZN17CFieldActorManage12sub_0203F144Ei

	.global ptr_FUN_0203f190_0208ddd8
ptr_FUN_0203f190_0208ddd8: ; 0x0208DDD8
	.word _ZN17CFieldActorManage12sub_0203F190Ev

	.global ptr_FUN_0203f2b0_0208dddc
ptr_FUN_0203f2b0_0208dddc: ; 0x0208DDDC
	.word _ZN17CFieldActorManage12sub_0203F2B0EP9CFieldMapi

	.global ptr_FUN_0203f1fc_0208dde0
ptr_FUN_0203f1fc_0208dde0: ; 0x0208DDE0
	.word _ZN17CFieldActorManage12sub_0203F1FCEv
	.word _ZN17CFieldActorManage12sub_0203F278Ev

	.global ptr_FUN_02040460_0208dde8
ptr_FUN_02040460_0208dde8: ; 0x0208DDE8
	.word _ZN17CFieldActorManage12sub_02040460Ev
	.word _ZN17CFieldActorManage12sub_02040428Ev
	.word _ZN17CFieldActorManage12sub_02040384Ev

	.global ptr_FUN_0203f348_0208ddf4
ptr_FUN_0203f348_0208ddf4: ; 0x0208DDF4
	.word _ZN17CFieldActorManage12sub_0203F348EP17UnkClass_0211E3FCP17UnkClass_020416AC

	.global ptr_FUN_0203f4b8_0208ddf8
ptr_FUN_0203f4b8_0208ddf8: ; 0x0208DDF8
	.word _ZN17CFieldActorManage12sub_0203F4B8Ethi

	.global ptr_FUN_0203f58c_0208ddfc
ptr_FUN_0203f58c_0208ddfc: ; 0x0208DDFC
	.word _ZN17CFieldActorManage12sub_0203F58CEv

	.global ptr_FUN_0203f604_0208de00
ptr_FUN_0203f604_0208de00: ; 0x0208DE00
	.word _ZN17CFieldActorManage12sub_0203F604Ev

	.global ptr_FUN_0203f688_0208de04
ptr_FUN_0203f688_0208de04: ; 0x0208DE04
	.word _ZN17CFieldActorManage12sub_0203F688Ev
	.word _ZN17CFieldActorManage12sub_0203F700Ev
	.word _ZN17CFieldActorManage12sub_0203F754Ev
	.word _ZN17CFieldActorManage12sub_0203F7ACEv

	.global PTR_ptr_FUN_02083578_0208de14
PTR_ptr_FUN_02083578_0208de14: ; 0x0208DE14
	.word _ZTVN10__cxxabiv117__class_type_infoE+8
	.word s_11CDrawObject_0208de28

	.global PTR_ptr_FUN_020835bc_0208de1c
PTR_ptr_FUN_020835bc_0208de1c: ; 0x0208DE1C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CFieldDrawObject_0208de38
	.word PTR_ptr_FUN_02083578_0208de14

	.global s_11CDrawObject_0208de28
s_11CDrawObject_0208de28: ; 0x0208DE28
	.asciz "11CDrawObject"

	.global _0208DE36
_0208DE36:
	.byte 0x00, 0x00

	.global s_16CFieldDrawObject_0208de38
s_16CFieldDrawObject_0208de38: ; 0x0208DE38
	.asciz "16CFieldDrawObject"

	.global _0208DE4B
_0208DE4B:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208de1c

	.global PTR_LAB_0208de54
PTR_LAB_0208de54: ; 0x0208DE54
	.word sub_020404E8
	.word sub_02040508

	.global ptr_FUN_02040668_0208de5c
ptr_FUN_02040668_0208de5c: ; 0x0208DE5C
	.word sub_02040668
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_02083578_0208de14

	.global PTR_LAB_0208de68
PTR_LAB_0208de68: ; 0x0208DE68
	.word sub_0204078C

	.global ptr_FUN_02040778_0208de6c
ptr_FUN_02040778_0208de6c: ; 0x0208DE6C
	.word sub_02040778
	.word _ZN11CDrawObject12sub_020091D4EP8Camera2Di

	.global PTR_ptr_FUN_020835bc_0208de74
PTR_ptr_FUN_020835bc_0208de74: ; 0x0208DE74
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_17CActorDataPartner_0208de8c
	.word PTR_ptr_FUN_020835bc_0208de80

	.global PTR_ptr_FUN_020835bc_0208de80
PTR_ptr_FUN_020835bc_0208de80: ; 0x0208DE80
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_19CFieldDrawActorData_0208dea0
	.word _ZTI10CActorData

	.global s_17CActorDataPartner_0208de8c
s_17CActorDataPartner_0208de8c: ; 0x0208DE8C
	.asciz "17CActorDataPartner"

	.global s_19CFieldDrawActorData_0208dea0
s_19CFieldDrawActorData_0208dea0: ; 0x0208DEA0
	.asciz "19CFieldDrawActorData"

	.global _0208DEB6
_0208DEB6:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_0208de80

	.global ptr_FUN_02040f20_0208dec0
ptr_FUN_02040f20_0208dec0: ; 0x0208DEC0
	.word sub_02040F20
	.word _ZN19CFieldDrawActorDataD0Ev

	.global ptr_FUN_02040d44_0208dec8
ptr_FUN_02040d44_0208dec8: ; 0x0208DEC8
	.word sub_02040D44

	.global ptr_FUN_0201437c_0208decc
ptr_FUN_0201437c_0208decc: ; 0x0208DECC
	.word _ZN10CActorData7GetAnimEh

	.global ptr_FUN_020143b8_0208ded0
ptr_FUN_020143b8_0208ded0: ; 0x0208DED0
	.word _ZN10CActorData12sub_020143B8Eim
	.word _ZN10CActorData9GetAnimIdEim
	.word _ZN10CActorData9GetAnimAtEi

	.global ptr_FUN_02040e2c_0208dedc
ptr_FUN_02040e2c_0208dedc: ; 0x0208DEDC
	.word sub_02040E2C

	.global ptr_FUN_02040e80_0208dee0
ptr_FUN_02040e80_0208dee0: ; 0x0208DEE0
	.word _ZN19CFieldDrawActorData12sub_02040E80Ev
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208de74

	.global ptr_FUN_0204114c_0208deec
ptr_FUN_0204114c_0208deec: ; 0x0208DEEC
	.word _ZN17CActorDataPartnerD1Ev

	.global ptr_FUN_0204117c_0208def0
ptr_FUN_0204117c_0208def0: ; 0x0208DEF0
	.word sub_0204117C

	.global ptr_FUN_020411b4_0208def4
ptr_FUN_020411b4_0208def4: ; 0x0208DEF4
	.word sub_020411B4

	.global ptr_FUN_0201437c_0208def8
ptr_FUN_0201437c_0208def8: ; 0x0208DEF8
	.word _ZN10CActorData7GetAnimEh

	.global ptr_FUN_020143b8_0208defc
ptr_FUN_020143b8_0208defc: ; 0x0208DEFC
	.word _ZN10CActorData12sub_020143B8Eim
	.word _ZN10CActorData9GetAnimIdEim
	.word _ZN10CActorData9GetAnimAtEi

	.global ptr_FUN_020411d8_0208df08
ptr_FUN_020411d8_0208df08: ; 0x0208DF08
	.word sub_020411D8
	.word sub_0204129C

	.global s_t_03d_02d_0208df10
s_t_03d_02d_0208df10: ; 0x0208DF10
	.asciz "t%03d_%02d"

	.global _0208DF1B
_0208DF1B:
	.byte 0x00

	.global DAT_0208df1c
DAT_0208df1c: ; 0x0208DF1C
	.byte 0x41, 0x43, 0x54, 0x00

	.global s_data_target_s_LZ_bin_0208df20
s_data_target_s_LZ_bin_0208df20: ; 0x0208DF20
	.asciz "data/target/%s_LZ.bin"

	.global _0208DF36
_0208DF36:
	.byte 0x00, 0x00

	.global s_s_s_NCLR_0208df38
s_s_s_NCLR_0208df38: ; 0x0208DF38
	.asciz "%s:%s.NCLR"

	.global _0208DF43
_0208DF43:
	.byte 0x00

	.global s_s_s_0208df44
s_s_s_0208df44: ; 0x0208DF44
	.asciz "%s:%s"

	.global _0208DF4A
_0208DF4A:
	.byte 0x00, 0x00

	.global s_s_s_s_0208df4c
s_s_s_s_0208df4c: ; 0x0208DF4C
	.asciz "%s:%s_s"

	.global s_s_s_a_0208df54
s_s_s_a_0208df54: ; 0x0208DF54
	.asciz "%s:%s_a"

	.global s_s_s_c_0208df5c
s_s_s_c_0208df5c: ; 0x0208DF5C
	.asciz "%s:%s_c"

	.global s_F_02d_0208df64
s_F_02d_0208df64: ; 0x0208DF64
	.asciz "F%02d"

	.global _0208DF6A
_0208DF6A:
	.byte 0x00, 0x00

	.global s_NO_EMPTY_m_nActorDataMax_d_0208df6c
s_NO_EMPTY_m_nActorDataMax_d_0208df6c: ; 0x0208DF6C
	.asciz "NO EMPTY!! m_nActorDataMax = %d"

	.global PTR_ptr_FUN_020835bc_0208df8c
PTR_ptr_FUN_020835bc_0208df8c: ; 0x0208DF8C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CActorDataPlayer_0208df98
	.word PTR_ptr_FUN_020835bc_0208de80

	.global s_16CActorDataPlayer_0208df98
s_16CActorDataPlayer_0208df98: ; 0x0208DF98
	.asciz "16CActorDataPlayer"

	.global _0208DFAB
_0208DFAB:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208df8c

	.global ptr_FUN_020412dc_0208dfb4
ptr_FUN_020412dc_0208dfb4: ; 0x0208DFB4
	.word _ZN17UnkClass_020412A0D1Ev

	.global ptr_FUN_0204130c_0208dfb8
ptr_FUN_0204130c_0208dfb8: ; 0x0208DFB8
	.word sub_0204130C

	.global ptr_FUN_02041688_0208dfbc
ptr_FUN_02041688_0208dfbc: ; 0x0208DFBC
	.word sub_02041688

	.global ptr_FUN_020415c8_0208dfc0
ptr_FUN_020415c8_0208dfc0: ; 0x0208DFC0
	.word sub_020415C8

	.global ptr_FUN_02041604_0208dfc4
ptr_FUN_02041604_0208dfc4: ; 0x0208DFC4
	.word sub_02041604
	.word sub_02041660
	.word _ZN10CActorData9GetAnimAtEi

	.global ptr_FUN_02040e2c_0208dfd0
ptr_FUN_02040e2c_0208dfd0: ; 0x0208DFD0
	.word sub_02040E2C

	.global ptr_FUN_02040e80_0208dfd4
ptr_FUN_02040e80_0208dfd4: ; 0x0208DFD4
	.word _ZN19CFieldDrawActorData12sub_02040E80Ev

	.global s_player_1d_0208dfd8
s_player_1d_0208dfd8: ; 0x0208DFD8
	.asciz "player%1d"

	.global _0208DFE2
_0208DFE2:
	.byte 0x00, 0x00

	.global DAT_0208dfe4
DAT_0208dfe4: ; 0x0208DFE4
	.byte 0x50, 0x4C, 0x52, 0x00

	.global s_data_player_s_LZ_bin_0208dfe8
s_data_player_s_LZ_bin_0208dfe8: ; 0x0208DFE8
	.asciz "data/player/%s_LZ.bin"

	.global _0208DFFE
_0208DFFE:
	.byte 0x00, 0x00

	.global s_s_s_NCLR_0208e000
s_s_s_NCLR_0208e000: ; 0x0208E000
	.asciz "%s:%s.NCLR"

	.global _0208E00B
_0208E00B:
	.byte 0x00

	.global s_s_s_02d_0208e00c
s_s_s_02d_0208e00c: ; 0x0208E00C
	.asciz "%s:%s_%02d"

	.global _0208E017
_0208E017:
	.byte 0x00

	.global s_data_shadow_NCBR_0208e018
s_data_shadow_NCBR_0208e018: ; 0x0208E018
	.asciz "data/shadow.NCBR"

	.global _0208E029
_0208E029:
	.byte 0x00, 0x00, 0x00

	.global s_data_shadow_NCLR_0208e02c
s_data_shadow_NCLR_0208e02c: ; 0x0208E02C
	.asciz "data/shadow.NCLR"

	.global _0208E03D
_0208E03D:
	.byte 0x00, 0x00, 0x00

	.global PTR_ptr_FUN_020835bc_0208e040
PTR_ptr_FUN_020835bc_0208e040: ; 0x0208E040
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_23CSimplePrimitiveQuadNTF_0208e094
	.word _ZTI10CPrimitive

	.global PTR_ptr_FUN_020835bc_0208e04c
PTR_ptr_FUN_020835bc_0208e04c: ; 0x0208E04C
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_16CSimpleSpriteNTF_0208e058
	.word _ZTI17CPrimitiveRectNTF

	.global s_16CSimpleSpriteNTF_0208e058
s_16CSimpleSpriteNTF_0208e058: ; 0x0208E058
	.asciz "16CSimpleSpriteNTF"

	.global _0208E06B
_0208E06B:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208e04c

	.global PTR_LAB_0208e074
PTR_LAB_0208e074: ; 0x0208E074
	.word sub_020420A8

	.global ptr_FUN_020420bc_0208e078
ptr_FUN_020420bc_0208e078: ; 0x0208E078
	.word sub_020420BC

	.global ptr_FUN_02041df8_0208e07c
ptr_FUN_02041df8_0208e07c: ; 0x0208E07C
	.word sub_02041DF8
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208e040

	.global ptr_FUN_020420d8_0208e088
ptr_FUN_020420d8_0208e088: ; 0x0208E088
	.word sub_020420D8

	.global ptr_FUN_020420ec_0208e08c
ptr_FUN_020420ec_0208e08c: ; 0x0208E08C
	.word sub_020420EC

	.global ptr_FUN_02041f74_0208e090
ptr_FUN_02041f74_0208e090: ; 0x0208E090
	.word sub_02041F74

	.global s_23CSimplePrimitiveQuadNTF_0208e094
s_23CSimplePrimitiveQuadNTF_0208e094: ; 0x0208E094
	.asciz "23CSimplePrimitiveQuadNTF"

	.global _0208E0AE
_0208E0AE:
	.byte 0x00, 0x00

	.global s_data_battle_bg_capbg_03d_LZ_bin_0208e0b0
s_data_battle_bg_capbg_03d_LZ_bin_0208e0b0: ; 0x0208E0B0
	.asciz "data/battle/bg/capbg%03d_LZ.bin"

	.global DAT_0208e0d0
DAT_0208e0d0: ; 0x0208E0D0
	.byte 0x42, 0x42, 0x47, 0x00

	.global s_BBG_capbg_03d_NCBR_0208e0d4
s_BBG_capbg_03d_NCBR_0208e0d4: ; 0x0208E0D4
	.asciz "BBG:capbg%03d.NCBR"

	.global _0208E0E7
_0208E0E7:
	.byte 0x00

	.global s_BBG_capbg_03d_NCLR_0208e0e8
s_BBG_capbg_03d_NCLR_0208e0e8: ; 0x0208E0E8
	.asciz "BBG:capbg%03d.NCLR"

	.global _0208E0FB
_0208E0FB:
	.byte 0x00

	.global s_BBG_capbg_03d_NCER_0208e0fc
s_BBG_capbg_03d_NCER_0208e0fc: ; 0x0208E0FC
	.asciz "BBG:capbg%03d.NCER"

	.global _0208E10F
_0208E10F:
	.byte 0x00

	.global PTR_ptr_FUN_020835bc_0208e110
PTR_ptr_FUN_020835bc_0208e110: ; 0x0208E110
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_26CDownloadMissionStartScene_0208e12c
	.word _ZTI6CScene

	.global DAT_0208e11c
DAT_0208e11c: ; 0x0208E11C
	.byte 0x00, 0x01, 0x02, 0x03
	.byte 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F

	.global s_26CDownloadMissionStartScene_0208e12c
s_26CDownloadMissionStartScene_0208e12c: ; 0x0208E12C
	.asciz "26CDownloadMissionStartScene"

	.global _0208E149
_0208E149:
	.byte 0x00, 0x00, 0x00

	.global _ZTV26CDownloadMissionStartScene
_ZTV26CDownloadMissionStartScene: ; 0x0208E14C
    .byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_0208e110

	.global ptr_FUN_02043134_0208e154
ptr_FUN_02043134_0208e154: ; 0x0208E154
	.word sub_02043134

	.global ptr_FUN_020430d0_0208e158
ptr_FUN_020430d0_0208e158: ; 0x0208E158
	.word sub_020430D0

	.global ptr_FUN_02042548_0208e15c
ptr_FUN_02042548_0208e15c: ; 0x0208E15C
	.word sub_02042548
	.word sub_02043128
	.word sub_02043124

	.global ptr_FUN_02007ce0_0208e168
ptr_FUN_02007ce0_0208e168: ; 0x0208E168
	.word _ZN6CScene5func3Ev

	.global ptr_FUN_02007cc4_0208e16c
ptr_FUN_02007cc4_0208e16c: ; 0x0208E16C
	.word _ZN6CScene5func4Ev

	.global ptr_FUN_02042f84_0208e170
ptr_FUN_02042f84_0208e170: ; 0x0208E170
	.word sub_02042F84

	.global ptr_FUN_02042434_0208e174
ptr_FUN_02042434_0208e174: ; 0x0208E174
	.word sub_02042434

	.global ptr_FUN_020424f4_0208e178
ptr_FUN_020424f4_0208e178: ; 0x0208E178
	.word sub_020424F4
	.word sub_0204312C

	.global PTR_ptr_FUN_020835bc_0208e180
PTR_ptr_FUN_020835bc_0208e180: ; 0x0208E180
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_24CDownloadMissionEndScene_0208e18c
	.word _ZTI6CScene

	.global s_24CDownloadMissionEndScene_0208e18c
s_24CDownloadMissionEndScene_0208e18c: ; 0x0208E18C
	.asciz "24CDownloadMissionEndScene"

	.global _0208E1A7
_0208E1A7:
	.byte 0x00

	.global _ZTV24CDownloadMissionEndScene
_ZTV24CDownloadMissionEndScene: ; 0x0208E1A8
    .byte 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_0208e180

	.global ptr_FUN_020439d4_0208e1b0
ptr_FUN_020439d4_0208e1b0: ; 0x0208E1B0
	.word sub_020439D4
	.word sub_020439A8

	.global ptr_FUN_0204338c_0208e1b8
ptr_FUN_0204338c_0208e1b8: ; 0x0208E1B8
	.word sub_0204338C
	.word sub_020439C8
	.word sub_020439C4

	.global ptr_FUN_02007ce0_0208e1c4
ptr_FUN_02007ce0_0208e1c4: ; 0x0208E1C4
	.word _ZN6CScene5func3Ev

	.global ptr_FUN_02007cc4_0208e1c8
ptr_FUN_02007cc4_0208e1c8: ; 0x0208E1C8
	.word _ZN6CScene5func4Ev

	.global ptr_FUN_02043880_0208e1cc
ptr_FUN_02043880_0208e1cc: ; 0x0208E1CC
	.word sub_02043880

	.global ptr_FUN_02043180_0208e1d0
ptr_FUN_02043180_0208e1d0: ; 0x0208E1D0
	.word sub_02043180

	.global ptr_FUN_02043338_0208e1d4
ptr_FUN_02043338_0208e1d4: ; 0x0208E1D4
	.word sub_02043338
	.word sub_020439CC

	.global PTR_ptr_FUN_020835bc_0208e1dc
PTR_ptr_FUN_020835bc_0208e1dc: ; 0x0208E1DC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_28CDownloadMissionRestartScene_0208e1e8
	.word _ZTI6CScene

	.global s_28CDownloadMissionRestartScene_0208e1e8
s_28CDownloadMissionRestartScene_0208e1e8: ; 0x0208E1E8
	.asciz "28CDownloadMissionRestartScene"

	.global _0208E207
_0208E207:
	.byte 0x00

	.global _ZTV28CDownloadMissionRestartScene
_ZTV28CDownloadMissionRestartScene: ; 0x0208E208
    .byte 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_0208e1dc

	.global ptr_FUN_02044154_0208e210
ptr_FUN_02044154_0208e210: ; 0x0208E210
	.word sub_02044154

	.global ptr_FUN_020440f0_0208e214
ptr_FUN_020440f0_0208e214: ; 0x0208E214
	.word sub_020440F0

	.global ptr_FUN_02043afc_0208e218
ptr_FUN_02043afc_0208e218: ; 0x0208E218
	.word sub_02043AFC
	.word sub_02044148
	.word sub_02044144

	.global ptr_FUN_02007ce0_0208e224
ptr_FUN_02007ce0_0208e224: ; 0x0208E224
	.word _ZN6CScene5func3Ev

	.global ptr_FUN_02007cc4_0208e228
ptr_FUN_02007cc4_0208e228: ; 0x0208E228
	.word _ZN6CScene5func4Ev

	.global ptr_FUN_02043fc8_0208e22c
ptr_FUN_02043fc8_0208e22c: ; 0x0208E22C
	.word sub_02043FC8

	.global ptr_FUN_020439e8_0208e230
ptr_FUN_020439e8_0208e230: ; 0x0208E230
	.word sub_020439E8

	.global ptr_FUN_02043aa8_0208e234
ptr_FUN_02043aa8_0208e234: ; 0x0208E234
	.word sub_02043AA8
	.word sub_0204414C

	.global DAT_0208e23c
DAT_0208e23c: ; 0x0208E23C
	.byte 0x00, 0x00, 0x00, 0x00

	.global DAT_0208e240
DAT_0208e240: ; 0x0208E240
	.byte 0x03, 0x00, 0x00, 0x00

	.global DAT_0208e244
DAT_0208e244: ; 0x0208E244
	.byte 0x0A, 0x00, 0x00, 0x00

	.global DAT_0208e248
DAT_0208e248: ; 0x0208E248
	.byte 0x00, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36
	.byte 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D
	.byte 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5F, 0x2D, 0x2F

	.global s_fsc_symbol_not_found_s_0208e270
s_fsc_symbol_not_found_s_0208e270: ; 0x0208E270
	.byte 0x66, 0x73, 0x63, 0x3A, 0x73, 0x79, 0x6D, 0x62, 0x6F, 0x6C, 0x20, 0x6E, 0x6F, 0x74, 0x20, 0x66
	.byte 0x6F, 0x75, 0x6E, 0x64, 0x20, 0x25, 0x73, 0x0A, 0x00, 0x00, 0x00, 0x00

	.global s_fsc_undef_syscall_page_d_0208e28c
s_fsc_undef_syscall_page_d_0208e28c: ; 0x0208E28C
	.asciz "fsc:undef syscall page=%d\n"

	.global _0208E2A7
_0208E2A7:
	.byte 0x00

	.global s_fsc_undef_syscall_function_page_0208e2a8
s_fsc_undef_syscall_function_page_0208e2a8: ; 0x0208E2A8
	.asciz "fsc:undef syscall function page=%d id=%x\n"

	.global _0208E2D2
_0208E2D2:
	.byte 0x00, 0x00

	.global s_fsc_float_operator_not_imprement_0208e2d4
s_fsc_float_operator_not_imprement_0208e2d4: ; 0x0208E2D4
	.asciz "fsc:float operator not imprement\n"

	.global _0208E2F6
_0208E2F6:
	.byte 0x00, 0x00

	.global s_fsc_unknown_opcode_x_0208e2f8
s_fsc_unknown_opcode_x_0208e2f8: ; 0x0208E2F8
	.asciz "fsc:unknown opcode %x\n"

	.global _0208E30F
_0208E30F:
	.byte 0x00

	.global s_fsc_stack_overflow_stacksize_d_0208e310
s_fsc_stack_overflow_stacksize_d_0208e310: ; 0x0208E310
	.asciz "fsc:stack overflow stacksize=%d\n"

	.global _0208E331
_0208E331:
	.byte 0x00, 0x00, 0x00

	.global PTR_LAB_0208e334
PTR_LAB_0208e334: ; 0x0208E334
	.word sub_02046618

	.global ptr_FUN_02046620_0208e338
ptr_FUN_02046620_0208e338: ; 0x0208E338
	.word sub_02046620
	.word sub_0204663C

	.global ptr_FUN_02046654_0208e340
ptr_FUN_02046654_0208e340: ; 0x0208E340
	.word sub_02046654
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word sub_0204666C
	.word sub_0204668C
	.word sub_020466F0

	.global ptr_FUN_02046708_0208e3c0
ptr_FUN_02046708_0208e3c0: ; 0x0208E3C0
	.word sub_02046708
	.word sub_02046720
	.word sub_020467F4
	.word sub_02046804
	.word sub_02046814
	.word sub_020466A0
	.word sub_020466C4

	.global ptr_FUN_02046758_0208e3dc
ptr_FUN_02046758_0208e3dc: ; 0x0208E3DC
	.word sub_02046758

	.global ptr_FUN_020467a4_0208e3e0
ptr_FUN_020467a4_0208e3e0: ; 0x0208E3E0
	.word sub_020467A4
	.word sub_02046824
	.word sub_02046840
	.word sub_02046874
	.word sub_0204688C
	.word sub_02046894
	.word sub_0204689C
	.word sub_020468A4
	.word sub_020468AC
	.word sub_020468B4
	.word sub_020468C4
	.word sub_020468D8
	.word sub_020468E0
	.word sub_020468E8
	.word sub_020468F0
	.word sub_02046904
	.word sub_02046914
	.word sub_02046920
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.global ptr_FUN_0204692c_0208e4f4
ptr_FUN_0204692c_0208e4f4: ; 0x0208E4F4
	.word sub_0204692C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.global DAT_0208e534
DAT_0208e534: ; 0x0208E534
	.byte 0x25, 0x73, 0x00, 0x00

