	.section .text.start
	.global _start
_start:

	la a0, _sbss
	la a1, _ebss
	bge a0, a1, end_init_bss
loop_init_bss:
	sw zero, 0(a0)
	addi a0, a0, 4
	blt a0, a1, loop_init_bss
end_init_bss:

	la sp, __stacktop

	call main

.global _exit
_exit:
	j _exit
