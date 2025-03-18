CROSS = /Users/alexander/Documents/Project/risc/comp/bin/riscv32-unknown-elf-

CC = $(CROSS)gcc
OBJCOPY = $(CROSS)objcopy
SIZE = $(CROSS)size
ICEPROG = iceprog

CFLAGS=-Wall -O2 -march=rv32im -mabi=ilp32 -ffreestanding -flto -nostartfiles -fomit-frame-pointer -Wl,--gc-section --specs=nano.specs -I..

CFLAGS += \
	-DNORMALUNIX \
	$(NULL)

SOURCES_doom_arch := $(wildcard *.s *.c)

all: main.bin

main.elf: riscv.lds $(SOURCES_doom_arch)
	$(CC) $(CFLAGS) -Wl,-Bstatic,-T,riscv.lds,--strip-debug -o $@  $(SOURCES_doom_arch)
	$(SIZE) $@

clean:
	rm -f *.bin *.hex *.elf *.o *.gen.h


%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

prog: main.bin
	$(ICEPROG) -o 1M $<


.PHONY: all clean prog prog_wad
.PRECIOUS: *.elf

