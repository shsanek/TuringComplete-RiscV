#include <stdarg.h>
#include <stdint.h>
#include "console.h"

void exit() {
    volatile uint32_t *p = (volatile uint32_t *)0x64000008;
    *p = 1;
    while(1);
}

__attribute__((section(".start")))
int main(void) {
    console_init();
    console_puts("Test output with console_puts.\n");
    // console_printf("Test integer output: %d\n", 1234);
    // console_printf("Test zero-padded integer: %05d\n", 42);
    // console_printf("Test unsigned integer: %u\n", 9876);
    // console_printf("Test hex lowercase: %x\n", 0xABCD);
    // console_printf("Test hex uppercase: %X\n", 0xABCD);
    // console_printf("Test character output: %c\n", 'A');
    // console_printf("Mixed test: string \"%s\", integer %d, character '%c', hex %X\n", "Example", -56, 'Z', 0x1F);
    exit();
    return 0;
}