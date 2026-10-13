    .include "macros.inc"

; Main .bss before libwvr's (MAIN_BSS_0210CED4 onward: the fsc script VM)

    .bss
    .global MAIN_BSS_0210CAB0
MAIN_BSS_0210CAB0: ; 0x0210CAB0
    .space 0x4

    .global MAIN_BSS_0210CAB4
MAIN_BSS_0210CAB4: ; 0x0210CAB4
    .space 0x14

    .global MAIN_BSS_0210CAC8
MAIN_BSS_0210CAC8: ; 0x0210CAC8
    .space 0x400

    .global MAIN_BSS_0210CEC8
MAIN_BSS_0210CEC8: ; 0x0210CEC8
    .space 0xC

    .global MAIN_BSS_0210CED4
MAIN_BSS_0210CED4: ; 0x0210CED4
    .space 0x4

    .global MAIN_BSS_0210CED8
MAIN_BSS_0210CED8: ; 0x0210CED8
    .space 0x100
