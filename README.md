# SaphireOS

A tiny 32-bit x86 hobby operating system written from scratch in C and Assembly.
It boots from a custom bootloader into protected mode, brings up a linear
VESA (VBE) framebuffer, and runs a double-buffered graphical desktop with a
mouse cursor, PS/2 keyboard input, a top taskbar, and a draggable shell window.

> Educational project. It is a freestanding kernel — no host OS, no libc.

## Features

- **Custom bootloader** (real mode → protected mode) with a GDT and a 32-bit flat memory model.
- **VBE graphics** in `640x480 @ 16bpp` (RGB565), accessed through a linear framebuffer.
- **Double buffering**: everything is drawn to an off-screen back buffer and flushed to the LFB each frame.
- **Graphics primitives**: pixels, rectangles, circles, bitmap text (bundled Arial-style font) and a mouse cursor.
- **PS/2 drivers**: keyboard and mouse handled through hardware interrupts (IDT + PIC + ISR stubs).
- **Cooperative task system**: a simple priority-based scheduler that runs registered tasks every frame.
- **UI widgets**: buttons and draggable/closable windows.
- **Desktop shell**: a taskbar button toggles a shell window that echoes typed text.

## Requirements

A Linux host with a 32-bit-capable toolchain:

- `gcc` (with 32-bit support / multilib)
- `nasm`
- `ld` (GNU binutils)
- `objcopy` (GNU binutils)
- `qemu-system-x86_64`

## Build & Run

```bash
make        # build os.img
make run    # build and boot it in QEMU
make clean  # remove build artifacts
```

`make run` launches:

```bash
qemu-system-x86_64 -m 64 -drive format=raw,file=os.img
```

## How It Works

1. **Boot** (`src/boot/boot.asm`) — the BIOS loads the 512-byte boot sector.
   It queries a VBE mode info block, switches to graphics mode `0x111`,
   loads the kernel from disk into memory, sets up a GDT, enables protected
   mode, and jumps to the kernel.
2. **Entry** (`src/boot/kernel_entry.asm`) — sets up segments and the stack,
   calls the C entry point `start()`, and provides the interrupt service
   routine stubs (`isr1` for the keyboard, `isr12` for the mouse) plus `LoadIDT`.
3. **Kernel** (`src/kernel/main.c`) — zeroes `.bss`, initializes the mouse and
   the IDT, registers the built-in tasks, and enters the main loop:

   ```c
   while (1) {
       ProcessTasks();  // run every registered task once
       Flush();         // copy the back buffer to the screen
   }
   ```

Hardware interrupts update global state (scancodes, mouse position, click
state) asynchronously; tasks read that state each frame to render the UI.

## Project Layout

```
.
├── Makefile              # build rules (gcc + nasm + ld + objcopy)
├── linker.ld             # kernel memory layout (.text/.rodata/.data/.bss)
├── include/              # public headers and configuration
│   ├── config.h          # load addresses, stack top, VBE/back-buffer addresses
│   ├── vbe.h             # VBE mode info block layout
│   ├── graphics.h        # framebuffer + primitives API
│   ├── text.h / font.h   # text rendering and font
│   ├── widgets.h         # buttons and windows
│   ├── task.h            # task system and parameters
│   ├── colors.h          # UI color constants
│   └── ...               # keyboard, mouse, idt, isr, pic, ports, ps2, ...
└── src/
    ├── boot/             # boot.asm (bootloader) + kernel_entry.asm
    ├── drivers/          # idt, isr, pic, ports, keyboard, mouse
    ├── graphics/         # framebuffer, primitives, text, font, cursor, widgets
    ├── kernel/           # main.c (entry point and main loop)
    └── tasks/            # task scheduler + built-in tasks (shell, taskbar, ...)
```

## Memory Map

| Region              | Address     |
| ------------------- | ----------- |
| VBE mode info block | `0x00000500`|
| Kernel image        | `0x00001000`|
| Stack top           | `0x00090000`|
| Back buffer         | `0x000FFFF0`|

## License

Personal educational project — use it however you like.
