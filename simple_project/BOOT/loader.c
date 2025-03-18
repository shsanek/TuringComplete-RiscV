#include <stdint.h>

// Определения для чтения загрузочного файла (адреса 0x68)
#define FILE_DATA ((volatile unsigned int *)0x68000000)  // чтение 4 байт из загрузочного файла
#define FILE_SIZE ((volatile unsigned int *)0x68000004)  // размер загрузочного файла (в байтах)

// Функция загрузки программы из файла в начало оперативной памяти.
// Важно: эта программа должна быть собрана как позиционно-независимый код (PIC),
// так как неизвестно, где она будет размещена, и переходы должны быть относительными.
void file_loader(void) {
    // Начало загрузки – адрес 0 оперативной памяти
    volatile unsigned int *dest = (volatile unsigned int *)0;
    
    // Получаем размер загрузочного файла (в байтах)
    unsigned int file_size = *FILE_SIZE;
    
    // Если файл пустой, возвращаем управление
    if (file_size == 0) {
        return;
    }
    
    // Читаем данные по 4 байта (предполагается, что размер выровнен до 4)
    for (unsigned int offset = 0; offset < file_size; offset += 4) {
        unsigned int word = *FILE_DATA;
        dest[offset / 4] = word;
    }
    
    // Передача управления загруженной программе (по адресу 0)
    void (*loaded_program)(void) = (void (*)(void))0;
    loaded_program();
    
    // Если управление вернулось, возвращаемся
    return;
}

int main(void) {
    file_loader();
    return 0;
}