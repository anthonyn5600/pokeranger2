# ntros: the PC port's own DS system layer (stage 2 of replacing libntr). Linked whole: libntr's remaining parts call
# into it (OS_Init -> OS_InitIrqTable, ...), which a plain static library ahead of them on the link line can't serve.
ntros_lib = static_library('ntros',
    files(
        'alarm.cpp',
        'card.cpp',
        'input.cpp',
        'interrupts.cpp',
        'pm.cpp',
        'romfs.cpp',
        'rtc.cpp',
        'thread.cpp',
        'timeline.cpp',
        'tp.cpp',
        'valarm.cpp',
    ),
    dependencies: nitrosdk_dep.partial_dependency(compile_args: true, includes: true),
    override_options: ['cpp_std=c++17'],
    native: true,
)

ntros_dep = declare_dependency(
    link_whole: ntros_lib,
    include_directories: include_directories('.'),
)
