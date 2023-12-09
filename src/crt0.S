.global _start

.section .text.init

_start:

    // load stack into sp
    la x2, _stack_start

    // clear BSS elf section
    la x26, _bss_start
    la x27, _bss_end

    // check if section has zero size
    bge x26, x27, clear_bss_end

clear_bss:
    // clear the bss, 32-bit words at a time
    sw x0, 0(x26)
    addi x26, x26, 4
    ble x26, x27, clear_bss
clear_bss_end:

    // setup C's main() arguments
    mv x10, x0
    mv x11, x0
    j main

exit_iss:
    li x1, 1
    la x2, tohost
    sw x1, 0(x2)
1:  j 1b


.global tohost
.section .tohost
.align 4
tohost: .dword 0
.globl fromhost
.align 4
fromhost: .dword 0