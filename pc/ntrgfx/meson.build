# ntrgfx: the PC port's DS graphics renderer. No libntr or game dependencies, so the replay tool builds standalone.
ntrgfx_lib = static_library('ntrgfx',
    files(
        'debug.cpp',
        'engine2d.cpp',
        'geometry.cpp',
        'ntrgfx.cpp',
        'render3d.cpp',
    ),
    override_options: ['cpp_std=c++17', 'optimization=2'],
    native: true,
)

ntrgfx_dep = declare_dependency(
    link_with: ntrgfx_lib,
    include_directories: include_directories('.'),
)

# Renders a saved display-state snapshot to a PPM image: ntrgfx_replay SNAPSHOT OUT.ppm [HIDE]
executable('ntrgfx_replay',
    files('tools/replay.cpp'),
    dependencies: ntrgfx_dep,
    override_options: ['cpp_std=c++17'],
    native: true,
)
