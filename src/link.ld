MEMORY
{
    CODE_MEM : ORIGIN = 0x80004000, LENGTH = 0x8000
    DATA_MEM : ORIGIN = 0x90001000, LENGTH = 0x8000
}

STACK_SIZE = 4K;

ENTRY(_start);

SECTIONS
{
    .text.init :
    {
        *(.text.init)
    } > CODE_MEM

    .text :
    {
        *(.text)
    } > CODE_MEM

    .data :
    {
        *(.sdata)
        *(.data)
    } > DATA_MEM

    .rodata :
    {
        *(.rodata)
        *(.rodata.str1.4)
    } > DATA_MEM

    .bss :
    {
        _bss_start = .;
        *(.bss)
        _bss_end = .;
    } > DATA_MEM

    .stack :
    {
        . = . + STACK_SIZE;
        _stack_start = .;
    } > DATA_MEM

    .tohost :
    {
        *(.tohost)
    } > DATA_MEM
}