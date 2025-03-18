#include <stddef.h>
#include <stdint.h>

// Определения для чтения системной информации по адресу 0x68
#define RAM_SIZE_PTR ((volatile unsigned int *)0x68000008)  // доступная оперативная память (в байтах)

// Базовый адрес консоли (байковая матрица 80x24)
static volatile unsigned char *console_ptr = (volatile unsigned char *)0x40000000;
static volatile unsigned int y_cursor = 0;

// Функция для вывода одного символа в консоль
void console_putc(char c) {
    *console_ptr = c;
    if (c == '\n') {
        y_cursor += 1;
        console_ptr = (volatile unsigned char *)(0x40000000 + y_cursor * 80);
    } else {
        console_ptr++;
    }
}

// Функция для вывода строки в консоль
void console_puts(const char *s) {
    while (*s) {
        console_putc(*s++);
    }
}

// Функция для вывода 32-битного числа в 16-ричном виде (без операций деления)
void print_hex(uint32_t value) {
    for (int shift = 28; shift >= 0; shift -= 4) {
        uint8_t nibble = (value >> shift) & 0xF;
        char c = (nibble < 10) ? ('0' + nibble) : ('A' + (nibble - 10));
        console_putc(c);
    }
}

// Массив с hex-кодами второй программы (заготовка; замените на реальные данные)
const unsigned int bootloader2[] = {
    0x680007B7, 0x0047A683, 0x02068263, 0x00000793, 0x68000637, 0x00062703, 0x00478793, 0xFEE7AE23, 0xFED7EAE3, 0x00000793, 0x00078067, 0x00008067, 0xFF010113, 0x00112623, 0xFC9FF0EF, 0x00C12083, 0x00000513, 0x01010113, 0x00008067
};

#define BOOTLOADER2_SIZE (sizeof(bootloader2))

// Функция копирования второго загрузчика в верхнюю часть оперативной памяти и передача управления
void copy_and_jump(void) {
    // Логирование старта программы
    console_puts("Instanalization.\r\n");
    
    // Чтение объёма оперативной памяти
    unsigned int ram_size = *RAM_SIZE_PTR;
    console_puts("RAM: 0x");
    print_hex(ram_size);
    console_puts("\r\n");
    
    // Вычисляем адрес для копирования второго загрузчика:
    // верх памяти минус размер загрузчика
    unsigned int dest_addr = ram_size - BOOTLOADER2_SIZE;
    volatile unsigned int *dest = (volatile unsigned int *)dest_addr;
    
    // Копирование по 4 байта (одно слово за раз)
    size_t num_words = BOOTLOADER2_SIZE / sizeof(unsigned int);
    for (size_t i = 0; i < num_words; i++) {
        dest[i] = bootloader2[i];
    }
    
    console_puts("Start loader...\r\n");
    
    // Передача управления: вызов функции по адресу копии загрузчика.
    // Важно: вторая программа должна быть собрана как позиционно-независимый код (PIC)
    void (*bootloader2_entry)(void) = (void (*)(void))dest_addr;
    bootloader2_entry();
    
    console_puts("Error: boot file is empty.\r\n");
    while (1);
}

__attribute__((section(".start")))
int main(void) {
    copy_and_jump();
    while (1);
    return 0;
}