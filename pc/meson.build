# PC port of Pokémon Ranger: Shadows of Almia, built on the libntr suite (NitroSDK/NitroSystem/NitroWiFi/NitroDWC
# replacements for PC). A separate project so the DS matching build (top-level meson.build) is never affected:
# both provide the dependency names NitroSDK/NitroSystem/NitroWiFi/NitroDWC. `src` and `include` are symlinks to
# the repo's own directories.
project('pokeranger2-pc', ['c', 'cpp'],
    version: '1.0',
    meson_version: '>=1.3.0',
    default_options: [
        'buildtype=debug',
        'warning_level=0',
        'cpp_std=gnu++14',
    ]
)

build_target = get_option('build_target')

public_includes = include_directories('include')

pokeranger2_args = [
    '-DPC_PORT',
    '-DPM_KEEP_ASSERTS',
    '-DGAME_LANGUAGE=ENGLISH',
    # The DS build compiles every TU with the global prefix header (cpp_pch)
    '-include', 'pch/global_pch.hpp',
    '-fno-exceptions',
    '-fshort-wchar',
    '-fno-strict-aliasing',
    '-fwrapv',
    # The game keeps pointers in 32-bit integers (include/PtrCast.hpp): link it at a fixed low address
    '-fno-pie',
]

pokeranger2_link_args = ['-no-pie', '-Wl,--version-script=' + meson.current_source_dir() / 'exe.map']

# "Who wrote this?" tracking of display memory (pc/glue/vramtrack.cpp): every SDK copy/fill goes through a wrapper
vramtrack_wraps = [
    'MI_DmaCopy32',
    'MI_DmaCopy16',
    'MI_DmaFill32',
    'MI_DmaFill16',
    'MI_DmaCopy32Async',
    'MI_DmaCopy16Async',
    'MI_DmaFill32Async',
    'MI_DmaFill16Async',
    'MIi_CpuCopy16',
    'MIi_CpuCopy32',
    'MIi_CpuCopyFast',
    'MIi_CpuClear16',
    'MIi_CpuClear32',
    'MIi_CpuClearFast',
    'MI_CpuCopy8',
    'MI_CpuFill8',
    'MI_Copy16B',
    'MI_Copy32B',
    'MI_Copy36B',
    'MI_Copy48B',
    'MI_Copy64B',
    'MI_Copy128B',
    'MI_Zero36B',
]
foreach w : vramtrack_wraps
    pokeranger2_link_args += '-Wl,--wrap=' + w
endforeach

############################################################
###                     DEPENDENCIES                     ###
############################################################
libntr_prj = subproject('libntr',
    default_options: [
        'build_target=' + build_target,
        'sdk_version_major=4',
        'card_game_code=YP2E',
        'card_maker_code=01',
    ]
)

nitrosdk_dep = dependency('NitroSDK')
nitrosystem_dep = dependency('NitroSystem')
nitrowifi_dep = dependency('NitroWiFi')
nitrodwc_dep = dependency('NitroDWC')

############################################################
###                       SOURCES                        ###
############################################################
subdir('src') # pokeranger2_cxx
subdir('ntrgfx') # ntrgfx_dep
subdir('ntros') # ntros_dep

pokeranger2_pc_cxx = [
    pokeranger2_cxx,
    # Built as separate libraries in the DS build (other compiler versions / post-link object edits)
    files(
        'src/ScriptBuiltin.cpp',
        'src/sub_02046D40.cpp',
        'src/CryptoRC4.cpp',
        'src/CryptoRC4Asm.cpp',
        'src/CFieldEffectBloom.cpp',
        'src/CFieldEffectRisingPhoton.cpp',
        'src/CFieldEffectBlackStoneAura.cpp',
        'src/CFieldEffectDarknessClear.cpp',
        'src/CFieldEffectVolcanicSteam.cpp',
        'src/CFieldEffectFuwanteWind.cpp',
        # The data-only asm files of the DS build
        'src/pc/AsmData.cpp',
        # PC-only helpers
        'src/pc/PtrCast.cpp',
        'src/pc/SdkCompat.cpp',
        'src/pc/LayoutChecks.cpp',
        'src/pc/PcDebug.cpp',
        # Our renderer, controls and game card inside libntr's window
        'glue/cartridge.cpp',
        'glue/input_libntr.cpp',
        'glue/ntrgfx_libntr.cpp',
        'glue/vramtrack.cpp',
    ),
]

main = executable('pokeranger2',
    sources: pokeranger2_pc_cxx,
    cpp_args: pokeranger2_args,
    include_directories: public_includes,
    dependencies: [
        ntrgfx_dep,
        ntros_dep,
        nitrosdk_dep,
        nitrosystem_dep,
        nitrowifi_dep,
        nitrodwc_dep,
    ],
    link_args: pokeranger2_link_args,
    native: true,
)
