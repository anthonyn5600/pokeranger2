    .include "macros.inc"
    .include "include/overlay_00_021785A4.inc"

; Data of the objects before src/CFieldEffectSpreadSmoke.cpp (split off overlay_00_0215CDC4.s when it landed)

    .data

    .global PTR_ptr_FUN_020835bc_overlay_0_021785a4
PTR_ptr_FUN_020835bc_overlay_0_021785a4: ; 0x021785A4
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_32CFieldEffectScatterLeavesFacto_overlay_0_02178690
	.word _ZTI19CFieldEffectFactory

    .global PTR_ptr_FUN_020835bc_overlay_0_021785b0
PTR_ptr_FUN_020835bc_overlay_0_021785b0: ; 0x021785B0
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_25CFieldEffectScatterLeaves_overlay_0_021785f8
	.word _ZTI20TFieldEffectParticleI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_021785bc
PTR_ptr_FUN_020835bc_overlay_0_021785bc: ; 0x021785BC
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_28CFieldParticleLeavesAnimator_overlay_0_02178650
	.word _ZTI24TFieldParticleForceFieldI15CSoftwareSpriteE

    .global PTR_ptr_FUN_020835bc_overlay_0_021785c8
PTR_ptr_FUN_020835bc_overlay_0_021785c8: ; 0x021785C8
	.word _ZTVN10__cxxabiv120__si_class_type_infoE+8
	.word s_27CFieldParticleLeavesEmitter_overlay_0_02178630
	.word _ZTI25TFieldParticleRectEmitterI15CSoftwareSpriteE

    .global DAT_overlay_0_021785d4
DAT_overlay_0_021785d4: ; 0x021785D4
	.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021785bc

    .global PTR_LAB_overlay_0_0215be88_overlay_0_021785ec
PTR_LAB_overlay_0_0215be88_overlay_0_021785ec: ; 0x021785EC
	.word _ZN28CFieldParticleLeavesAnimatorD1Ev

    .global ptr_FUN_overlay_0_0215c5cc_overlay_0_021785f0
ptr_FUN_overlay_0_0215c5cc_overlay_0_021785f0: ; 0x021785F0
	.word ov0_0215C5CC

    .global ptr_FUN_overlay_0_0215c4ac_overlay_0_021785f4
ptr_FUN_overlay_0_0215c4ac_overlay_0_021785f4: ; 0x021785F4
	.word _ZN28CFieldParticleLeavesAnimator5ApplyEP14TFieldParticleI15CSoftwareSpriteEi

    .global s_25CFieldEffectScatterLeaves_overlay_0_021785f8
s_25CFieldEffectScatterLeaves_overlay_0_021785f8: ; 0x021785F8
	.asciz "25CFieldEffectScatterLeaves"

    .global DAT_overlay_0_02178614
DAT_overlay_0_02178614:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021785c8

    .global PTR_LAB_overlay_0_0215be8c_overlay_0_0217861c
PTR_LAB_overlay_0_0215be8c_overlay_0_0217861c: ; 0x0217861C
	.word _ZN27CFieldParticleLeavesEmitterD1Ev

    .global ptr_FUN_overlay_0_0215c5b8_overlay_0_02178620
ptr_FUN_overlay_0_0215c5b8_overlay_0_02178620: ; 0x02178620
	.word ov0_0215C5B8
	.word _ZN27CFieldParticleLeavesEmitter5func2Ev

    .global ptr_FUN_overlay_0_0215c1a4_overlay_0_02178628
ptr_FUN_overlay_0_0215c1a4_overlay_0_02178628: ; 0x02178628
	.word _ZN27CFieldParticleLeavesEmitter6UpdateEi

    .global ptr_FUN_overlay_0_0215c22c_overlay_0_0217862c
ptr_FUN_overlay_0_0215c22c_overlay_0_0217862c: ; 0x0217862C
	.word _ZN27CFieldParticleLeavesEmitter4EmitEP14TFieldParticleI15CSoftwareSpriteE

    .global s_27CFieldParticleLeavesEmitter_overlay_0_02178630
s_27CFieldParticleLeavesEmitter_overlay_0_02178630: ; 0x02178630
	.asciz "27CFieldParticleLeavesEmitter"

    .global DAT_overlay_0_0217864E
DAT_overlay_0_0217864E:
	.byte 0x00, 0x00

    .global s_28CFieldParticleLeavesAnimator_overlay_0_02178650
s_28CFieldParticleLeavesAnimator_overlay_0_02178650: ; 0x02178650
	.asciz "28CFieldParticleLeavesAnimator"

    .global DAT_overlay_0_0217866F
DAT_overlay_0_0217866F:
	.byte 0x00
	.global _ZTV32CFieldEffectScatterLeavesFactory
_ZTV32CFieldEffectScatterLeavesFactory:
	.byte 0x00, 0x00, 0x00, 0x00
	.word PTR_ptr_FUN_020835bc_overlay_0_021785a4

    .global PTR_LAB_overlay_0_02151824_overlay_0_02178678
PTR_LAB_overlay_0_02151824_overlay_0_02178678: ; 0x02178678
	.word _ZN32CFieldEffectScatterLeavesFactoryD1Ev
	.word ov0_0215C748

    .global ptr_FUN_overlay_0_0215c4dc_overlay_0_02178680
ptr_FUN_overlay_0_0215c4dc_overlay_0_02178680: ; 0x02178680
	.word _ZN32CFieldEffectScatterLeavesFactory6CreateEi
	.word _ZN19CFieldEffectFactory6UpdateEi
	.word _ZN19CFieldEffectFactory5ResetEv
	.word _ZN19CFieldEffectFactory7ReleaseEP18CFieldEffectManage

    .global s_32CFieldEffectScatterLeavesFacto_overlay_0_02178690
s_32CFieldEffectScatterLeavesFacto_overlay_0_02178690: ; 0x02178690
	.asciz "32CFieldEffectScatterLeavesFactory"

    .global DAT_overlay_0_021786B3
DAT_overlay_0_021786B3:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00
    .word PTR_ptr_FUN_020835bc_overlay_0_021785b0

    .global ptr_FUN_overlay_0_0215c5e0_overlay_0_021786bc
ptr_FUN_overlay_0_0215c5e0_overlay_0_021786bc: ; 0x021786BC
	.word _ZN25CFieldEffectScatterLeavesD1Ev

    .global ptr_FUN_overlay_0_0215c690_overlay_0_021786c0
ptr_FUN_overlay_0_0215c690_overlay_0_021786c0: ; 0x021786C0
	.word ov0_0215C690

    .global ptr_FUN_overlay_0_021423a4_overlay_0_021786c4
ptr_FUN_overlay_0_021423a4_overlay_0_021786c4: ; 0x021786C4
	.word _ZN12CFieldEffect12ov0_021423A4Ev
	.word _ZN25CFieldEffectScatterLeaves12sub_02033028Ev
	.word _ZN12CFieldEffect12sub_020332A4Ev

    .global ptr_FUN_overlay_0_021421d0_overlay_0_021786d0
ptr_FUN_overlay_0_021421d0_overlay_0_021786d0: ; 0x021786D0
	.word _ZN12CFieldEffect12ov0_021421D0Ev

    .global ptr_FUN_overlay_0_02142380_overlay_0_021786d4
ptr_FUN_overlay_0_02142380_overlay_0_021786d4: ; 0x021786D4
	.word _ZN12CFieldEffect12ov0_02142380Ev

    .global ptr_FUN_overlay_0_0215b4a0_overlay_0_021786d8
ptr_FUN_overlay_0_0215b4a0_overlay_0_021786d8: ; 0x021786D8
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021421F0Eiii
	.word _ZN12CFieldEffect12ov0_02142240Ei

    .global ptr_FUN_overlay_0_02142ab4_overlay_0_021786e0
ptr_FUN_overlay_0_02142ab4_overlay_0_021786e0: ; 0x021786E0
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_02142264Ei

    .global ptr_FUN_overlay_0_0215b784_overlay_0_021786e4
ptr_FUN_overlay_0_0215b784_overlay_0_021786e4: ; 0x021786E4
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_02142344EP8Camera2D
	.word _ZN12CFieldEffect12ov0_0214239CEi
	.word _ZN12CFieldEffect12ov0_02142398EP17UnkClass_0211E3FC
	.word _ZN12CFieldEffect12ov0_0214234CE7Point2Diiii

    .global ptr_FUN_overlay_0_0215be90_overlay_0_021786f4
ptr_FUN_overlay_0_0215be90_overlay_0_021786f4: ; 0x021786F4
	.word _ZN25CFieldEffectScatterLeaves12sub_0203312CEii
	.word _ZN12CFieldEffect12sub_02033244Eiii
	.word _ZN12CFieldEffect12sub_02033440Et
	.word _ZN12CFieldEffect12sub_0203331CERK7Point2Di
	.word _ZN12CFieldEffect12sub_02033388ERK7Point2Di
	.word _ZN12CFieldEffect12sub_020333D8Eii
	.word _ZN12CFieldEffect12sub_0203365CEi
	.word _ZN12CFieldEffect12ov0_02142390EPvS0_
	.word _ZN12CFieldEffect12ov0_02142388EPKv

    .global ptr_FUN_overlay_0_021423e8_overlay_0_02178718
ptr_FUN_overlay_0_021423e8_overlay_0_02178718: ; 0x02178718
	.word _ZN20TFieldEffectParticleI15CSoftwareSpriteE12ov0_021423E8ERK20FieldEffectSpriteRes
	.word _ZN25CFieldEffectScatterLeaves13GetForceFieldEv
	.word _ZN25CFieldEffectScatterLeaves10GetEmitterEv
