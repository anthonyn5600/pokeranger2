project('pokeranger2', ['c', 'cpp', 'nasm'],
    version: '1.0',
    meson_version: '>=1.11.0',
    default_options : [
        'buildtype=plain',
        'warning_level=0'
    ]
)

fs = import('fs')

############################################################
###                    INCLUDE PATHS                     ###
############################################################
public_includes = include_directories('include', 'asm', 'res')
toplevel_includes = include_directories('.')


############################################################
###                    COMPILER FLAGS                    ###
############################################################
cpp_args = [
    '-proc', 'arm946e',
    '-enum', 'int',
    '-Cpp_exceptions', 'off',
    '-gccext,on',
    '-msgstyle', 'gcc',
    '-ipa', 'file',
    '-interworking',
    '-inline', 'on,noauto',
    '-char', 'signed',
    '-nosyspath',
    '-stdinc',
    '-sym', 'on',
    '-D_MSL_RESTRICT=',
]

if get_option('gdb_debugging')
    cpp_args += [
        '-O1,p',
        '-inline', 'off'
    ]
else
    cpp_args += '-O4,p'
endif

c_args = [
    cpp_args,
    '-lang', 'c99',
]

cxx_args = [
    cpp_args,
    '-lang', 'c++',
]

add_global_arguments(c_args,
    language: 'c',
    native: false
)

add_global_arguments(cxx_args,
    language: 'cpp',
    native: false
)

pokeranger2_args = [
    '-DPM_KEEP_ASSERTS',
    '-DGAME_LANGUAGE=ENGLISH'
]

if get_option('gdb_debugging')
    pokeranger2_args += '-DGDB_DEBUGGING'
endif

if get_option('logging_enabled')
    pokeranger2_args += '-DLOGGING_ENABLED'
endif

asm_args = [
    '-proc', 'arm5TE',
    '-16',
    '-gccinc'
]

link_args = [
    '-w', 'off',
    '-proc', 'arm946e',
    '-nopic',
    '-nopid',
    '-interworking',
    '-map', 'closure,unused',
    '-symtab', 'sort',
    '-msgstyle' ,'gcc',
    '-m', '_start',
    '-force_active', 'DGTi_hash2_arm4_small',
    '-sym', 'on'
]

############################################################
###                     DEPENDENCIES                     ###
############################################################
nitrosdk_dep = dependency('NitroSDK',
    default_options: {
        'mwrap_sdk': '2.0/sp1p2',
        'sp1p3_conditionals': true
    }
)

nitrosystem_dep = dependency('NitroSystem',
    default_options: {
        'mwrap_sdk': '2.0/sp2'
    }
)

nitrowifi_dep = dependency('NitroWiFi',
    default_options: {
        'mwrap_sdk': '2.0/sp1p2',
        'sp1p3_conditionals': true
    }
)

nitrodwc_dep = dependency('NitroDWC',
    default_options: {
        'mwrap_sdk': '2.0/sp2p2'
    }
)

libsyscall_dep = dependency('libsyscall')


############################################################
###                        TOOLS                         ###
############################################################
subdir('tools')


############################################################
###                      SPEC FILES                      ###
############################################################
subdir('ranger2.us')


############################################################
###                  INTERNAL LIBRARIES                  ###
############################################################
subdir('lib')


############################################################
###                     FILE SYSTEM                      ###
############################################################
subdir('res')

# Phony-like target to build all generated data files
alias_target('data', nitrofs_files)

############################################################
###                     ARM9 BINARY                      ###
############################################################
subdir('src')
subdir('asm')

# fsc builtin syscalls: built with the SDK 2.0/sp2 compiler (mwccarm 3.0-136) like the original; linked as plain
# objects so they keep their place in main.lsf
pokeranger2_sp2 = static_library('pokeranger2_sp2',
    files('src/ScriptBuiltin.cpp'),
    cpp_args: [pokeranger2_args, '-wrap:sdk', '2.0/sp2'],
    cpp_pch: 'include/pch/global_pch.hpp',
    include_directories: public_includes,
    dependencies: [
        nitrosdk_dep,
        nitrosystem_dep,
    ],
    pic: false,
    native: false
)

# NitroSDK libcrypto RC4: the SDK built it with the SDK 1.2 compiler (mwccarm 2.0-87, which has no -ipa) for
# ARMv4T (-proc arm9tdmi: `ldmia {..., lr}; bx lr` returns); linked as plain objects to keep its place in main.lsf
pokeranger2_crypto = static_library('pokeranger2_crypto',
    files('src/sub_02046D40.cpp', 'src/CryptoRC4.cpp', 'src/CryptoRC4Asm.cpp'),
    cpp_args: [pokeranger2_args, '-wrap:noipa', '-wrap:sdk', '1.2/sp4', '-proc', 'arm9tdmi'],
    include_directories: public_includes,
    dependencies: [
        nitrosdk_dep,
    ],
    pic: false,
    native: false
)

# Fake (linker): overlay 0 has its own copy of CSimpleSpriteNTF's inline ctor (the effects' sprite-array ctor,
# ov0_02166794), but mwld keeps one copy of a weak function for the whole link and ov3's COPDTitleScreen emits it
# first. The array also needs CSimpleSpriteNTF's real dtor, so a layout-twin class (as in ov7) can't stand in:
# the ov0 objects that emit the ctor (Bloom, RisingPhoton, BlackStoneAura) are renamed to the ov0 name after compiling instead
# (in place: objcopy would turn every weak copy into a local symbol).
pokeranger2_ov0_sprite = static_library('pokeranger2_ov0_sprite',
    files('src/CFieldEffectBloom.cpp', 'src/CFieldEffectRisingPhoton.cpp', 'src/CFieldEffectBlackStoneAura.cpp'),
    cpp_args: pokeranger2_args,
    cpp_pch: 'include/pch/global_pch.hpp',
    include_directories: public_includes,
    dependencies: [
        nitrosdk_dep,
        nitrosystem_dep,
    ],
    pic: false,
    native: false
)
pokeranger2_ov0_sprite_objs = custom_target('ov0_sprite_objs',
    input: pokeranger2_ov0_sprite.extract_objects('src/CFieldEffectBloom.cpp'),
    output: ['src_CFieldEffectBloom.cpp.o'],
    command: [elfrename_py, '@INPUT@', '@OUTPUT@', '_ZN16CSimpleSpriteNTFC1Ev=ov0_02166794'],
)
pokeranger2_ov0_sprite_objs2 = custom_target('ov0_sprite_objs2',
    input: pokeranger2_ov0_sprite.extract_objects('src/CFieldEffectRisingPhoton.cpp'),
    output: ['src_CFieldEffectRisingPhoton.cpp.o'],
    command: [elfrename_py, '@INPUT@', '@OUTPUT@', '_ZN16CSimpleSpriteNTFC1Ev=ov0_02166794'],
)
pokeranger2_ov0_sprite_objs3 = custom_target('ov0_sprite_objs3',
    input: pokeranger2_ov0_sprite.extract_objects('src/CFieldEffectBlackStoneAura.cpp'),
    output: ['src_CFieldEffectBlackStoneAura.cpp.o'],
    command: [elfrename_py, '@INPUT@', '@OUTPUT@', '_ZN16CSimpleSpriteNTFC1Ev=ov0_02166794'],
)

# Fake (compiler + linker): CFieldEffectDarknessClear's .data. Two objects of the original TU took part in its size
# sort but were dropped at link time, which left equal-size typeinfos/vtables in an order no source layout of ours
# reproduces; the object's data sections are put in the original order after compiling. Its <CSimpleSpriteNTF>
# template copies are also emitted by ov3's COPDTitleScreen and mwld keeps one weak copy per link, so overlay 0's
# copies get their own (address) names, like ov0_02166794 above.
pokeranger2_ov0_darkness = static_library('pokeranger2_ov0_darkness',
    files('src/CFieldEffectDarknessClear.cpp'),
    cpp_args: pokeranger2_args,
    cpp_pch: 'include/pch/global_pch.hpp',
    include_directories: public_includes,
    dependencies: [
        nitrosdk_dep,
        nitrosystem_dep,
    ],
    pic: false,
    native: false
)
pokeranger2_ov0_darkness_ordered = custom_target('ov0_darkness_ordered',
    input: pokeranger2_ov0_darkness.extract_all_objects(recursive: false),
    output: ['CFieldEffectDarknessClear.ordered.o'],
    command: [elfdataorder_py, '@INPUT@', '@OUTPUT@', files('tools/elfdataorder/CFieldEffectDarknessClear.txt')],
)
pokeranger2_ov0_darkness_objs = custom_target('ov0_darkness_objs',
    input: pokeranger2_ov0_darkness_ordered,
    output: ['src_CFieldEffectDarknessClear.cpp.o'],
    command: [elfrename_py, '@INPUT@', '@OUTPUT@',
        '_ZN14TFieldParticleI16CSimpleSpriteNTFED1Ev=ov0_0216AD48',
        '_ZN14TFieldParticleI16CSimpleSpriteNTFEC1Ev=ov0_0216AD5C',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE5func2Ev=ov0_0216AE74',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE6UpdateEi=ov0_0216BFFC',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED0Ev=ov0_0216C6BC',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED1Ev=ov0_0216CB50',
        '_ZTI24TFieldParticleForceFieldI16CSimpleSpriteNTFE=ov0_02179EB4',
        '_ZTI21TFieldParticleEmitterI16CSimpleSpriteNTFE=ov0_02179EBC',
        '_ZTV21TFieldParticleEmitterI16CSimpleSpriteNTFE=ov0_02179F64',
        '_ZTS21TFieldParticleEmitterI16CSimpleSpriteNTFE=ov0_0217A150',
        '_ZTS24TFieldParticleForceFieldI16CSimpleSpriteNTFE=ov0_0217A17C',
    ],
)

# CFieldEffectVolcanicSteam emits the same TFieldEffectParticle<CSimpleSpriteNTF> (and emitter/particle) weak copies as
# CFieldEffectDarknessClear, whose copies the original kept (its TU links first). Loaded after DC so DC's copies win,
# with the copies DC renames to their ov0 names renamed the same way (its references then reach DC's copies).
pokeranger2_ov0_steam = static_library('pokeranger2_ov0_steam',
    files('src/CFieldEffectVolcanicSteam.cpp'),
    cpp_args: pokeranger2_args,
    cpp_pch: 'include/pch/global_pch.hpp',
    include_directories: public_includes,
    dependencies: [
        nitrosdk_dep,
        nitrosystem_dep,
    ],
    pic: false,
    native: false
)
pokeranger2_ov0_steam_objs = custom_target('ov0_steam_objs',
    input: pokeranger2_ov0_steam.extract_all_objects(recursive: false),
    output: ['src_CFieldEffectVolcanicSteam.cpp.o'],
    command: [elfrename_py, '@INPUT@', '@OUTPUT@',
        '_ZN14TFieldParticleI16CSimpleSpriteNTFED1Ev=ov0_0216AD48',
        '_ZN14TFieldParticleI16CSimpleSpriteNTFEC1Ev=ov0_0216AD5C',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE5func2Ev=ov0_0216AE74',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFE6UpdateEi=ov0_0216BFFC',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED0Ev=ov0_0216C6BC',
        '_ZN21TFieldParticleEmitterI16CSimpleSpriteNTFED1Ev=ov0_0216CB50',
        '_ZTI24TFieldParticleForceFieldI16CSimpleSpriteNTFE=ov0_02179EB4',
        '_ZTI21TFieldParticleEmitterI16CSimpleSpriteNTFE=ov0_02179EBC',
        '_ZTV21TFieldParticleEmitterI16CSimpleSpriteNTFE=ov0_02179F64',
        '_ZTS21TFieldParticleEmitterI16CSimpleSpriteNTFE=ov0_0217A150',
        '_ZTS24TFieldParticleForceFieldI16CSimpleSpriteNTFE=ov0_0217A17C',
    ],
)

# Fake (compiler): CFieldEffectFuwanteWind's .data, like CFieldEffectDarknessClear's: the original TU's size sort held
# objects the linker later dropped, so its equal-size typeinfos/vtables are put in the original order after compiling.
# Loaded last like the objects above, so its <CSoftwareSprite> template copies never win over the earlier TUs' ones.
pokeranger2_ov0_wind = static_library('pokeranger2_ov0_wind',
    files('src/CFieldEffectFuwanteWind.cpp'),
    cpp_args: pokeranger2_args,
    cpp_pch: 'include/pch/global_pch.hpp',
    include_directories: public_includes,
    dependencies: [
        nitrosdk_dep,
        nitrosystem_dep,
    ],
    pic: false,
    native: false
)
pokeranger2_ov0_wind_objs = custom_target('ov0_wind_objs',
    input: pokeranger2_ov0_wind.extract_all_objects(recursive: false),
    output: ['src_CFieldEffectFuwanteWind.cpp.o'],
    command: [elfdataorder_py, '@INPUT@', '@OUTPUT@', files('tools/elfdataorder/CFieldEffectFuwanteWind.txt')],
)

main = executable('main',
    sources: [
        pokeranger2_cxx,
        pokeranger2_asm,
    ],
    objects: [
        pokeranger2_sp2.extract_all_objects(recursive: false),
        pokeranger2_crypto.extract_all_objects(recursive: false),
    ],
    c_args: pokeranger2_args,
    cpp_args: pokeranger2_args,
    nasm_args: asm_args,
    cpp_pch: 'include/pch/global_pch.hpp',
    include_directories: public_includes,
    dependencies: [
        nitrosdk_dep,
        nitrosystem_dep,
        nitrowifi_dep,
        nitrodwc_ranger2_dep, # Needs to be before `nitrodwc_dep`
        nitrodwc_dep,
        libsyscall_dep,
    ],
    link_args: [
        link_args,
        'ranger2.us/main.lcf',
        # Loaded after every other object, so its weak copies never win over the ones the other TUs provide.
        pokeranger2_ov0_sprite_objs.full_path(),
        pokeranger2_ov0_sprite_objs2.full_path(),
        pokeranger2_ov0_sprite_objs3.full_path(),
        pokeranger2_ov0_darkness_objs.full_path(),
        pokeranger2_ov0_steam_objs.full_path(),
        pokeranger2_ov0_wind_objs.full_path(),
    ],
    link_depends: [main_lcf, pokeranger2_ov0_sprite_objs, pokeranger2_ov0_sprite_objs2, pokeranger2_ov0_sprite_objs3, pokeranger2_ov0_darkness_objs, pokeranger2_ov0_steam_objs, pokeranger2_ov0_wind_objs],
    native: false
)


############################################################
###                    ARM7 BINARIES                     ###
############################################################
subdir('sub')


############################################################
###                        DS ROM                        ###
############################################################
pokeranger2_nds = custom_target('pokeranger2.us.nds',
    output: 'pokeranger2.us.nds',
    input: [
        main,
        rom_header_template,
        icon_png,
        arm7_bin,
        arm7_defs_bin,
        nitrofs_files
    ],
    command : [
        nitrorom_exe,
        'pack',
        '-DHEADER_TEMPLATE=@INPUT1@', # rom_header_template
        '-DICON_PNG=@INPUT2@',        # icon_png
        '-DARM7_STATIC=@INPUT3@',     # ichneumon_sub
        '-DARM7_DEFINE=@INPUT4@',     # ichneumon_sub_defs
        '--output=@OUTPUT0@',         # pokeranger2.us.nds
        rom_ini,
        filesys_csv,
    ],
    build_by_default: true
)

############################################################
###                   GDB HELPERS                        ###
############################################################
nef_fixer = custom_target('debug.nef',
    output: [
        'debug.nef'
    ],
    input: [
        main
    ],
    command : [
        nef_fixer_py, '@INPUT@', '@OUTPUT@'
    ]
)

ovly_mapper = custom_target('overlay.map',
    output: [
        'overlay.map'
    ],
    input: [
        main_lsf
    ],
    command : [
        overlay_mapper_py, '@INPUT@', '@OUTPUT@'
    ]
)


############################################################
###                        TESTS                         ###
############################################################
sha1sum = find_program(['sha1sum', 'shasum'], native: true)

test('SBIN Checksums',
    sha1sum,
    args: ['-c', '--quiet', sbins_sha1]
)

test('Filesystem Checksums',
    sha1sum,
    args: ['-c', '--quiet', filesys_sha1]
)

test('ROM Checksum',
    sha1sum,
    args: ['-c', '--quiet', rom_sha1]
)


############################################################
###                       POSTCONF                       ###
############################################################
meson.add_postconf_script(postconf_py)
