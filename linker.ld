ENTRY(_start)

SECTIONS
{
    . = 0x1000;

    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(.bss*)
        *(COMMON)
    }

    _kernel_end = .;

    ASSERT(_kernel_end < 0x90000, "Kernel image overlaps the stack at 0x90000")
}
