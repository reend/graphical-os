CC      := gcc
LD      := ld
AS      := nasm
OBJCOPY := objcopy

CFLAGS  := -m32 -ffreestanding -Iinclude
LDFLAGS := -m elf_i386 -T linker.ld

BUILD := build
SRC   := $(shell find src -name '*.c')
OBJ   := $(patsubst src/%.c,$(BUILD)/%.o,$(SRC))

KERNEL_ENTRY := $(BUILD)/boot/kernel_entry.o
BOOT_BIN     := $(BUILD)/boot/boot.bin

all: os.img

$(BUILD)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL_ENTRY): src/boot/kernel_entry.asm
	@mkdir -p $(dir $@)
	$(AS) $< -f elf -o $@

$(BOOT_BIN): src/boot/boot.asm
	@mkdir -p $(dir $@)
	$(AS) $< -f bin -o $@

$(BUILD)/kernel.img: $(KERNEL_ENTRY) $(OBJ) linker.ld
	$(LD) $(LDFLAGS) -o $@ $(KERNEL_ENTRY) $(OBJ)

$(BUILD)/kernel.bin: $(BUILD)/kernel.img
	$(OBJCOPY) -O binary $< $@

os.img: $(BOOT_BIN) $(BUILD)/kernel.bin
	cat $(BOOT_BIN) $(BUILD)/kernel.bin > os.img

clean:
	rm -rf $(BUILD) os.img

run: os.img
	qemu-system-x86_64 -m 64 -drive format=raw,file=os.img

.PHONY: all clean run
