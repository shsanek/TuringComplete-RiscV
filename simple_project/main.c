// #include <stdarg.h>
// #include <stdint.h>
// #include "console.h"

// void exit() {
//     volatile uint32_t *p = (volatile uint32_t *)0x64000008;
//     *p = 1;
//     while(1);
// }

// __attribute__((section(".start")))
// int main(void) {
//     console_init();
//     console_puts("Test output with console_puts.\n");
//     console_printf("Test integer output: %d\n", 1234);
//     console_printf("Test zero-padded integer: %05d\n", 42);
//     console_printf("Test unsigned integer: %u\n", 9876);
//     console_printf("Test hex lowercase: %x\n", 0xABCD);
//     console_printf("Test hex uppercase: %X\n", 0xABCD);
//     console_printf("Test character output: %c\n", 'A');
//     console_printf("Mixed test: string \"%s\", integer %d, character '%c', hex %X\n", "Example", -56, 'Z', 0x1F);
//     exit();
//     return 0;
#include <string.h>
#include <stdint.h>
#include <limits.h>

// Специальные адреса для завершения работы
volatile uint32_t * const TERMINATE_SUCCESS = (volatile uint32_t *)0x64000008;
volatile uint32_t * const TERMINATE_ERROR   = (volatile uint32_t *)0x6400000C;

// Макрос для проверки условия: при провале выполняется аварийное завершение
#define TEST(cond) if (!(cond)) { *TERMINATE_ERROR = __LINE__; while (1); }

int main(void) {
    // Объявление volatile переменных для арифметических и логических операций
    volatile int a, b, res, rem;
    volatile unsigned int ua, ub, ures, urem;

    // --- Тесты для арифметических операций (сложение, вычитание, умножение, деление) ---

    // Сложение
    // a = 10; b = 5;
    // res = a + b;
    // TEST(res == 15);

    // a = -10; b = 20;
    // res = a + b;
    // TEST(res == 10);
    // a = INT32_MAX; b = 0;
    // res = a + b;
    // TEST(res == INT32_MAX);
    // a = INT32_MIN; b = 0;
    // res = a + b;
    // TEST(res == INT32_MIN);
    // a = 0; b = 0;
    // res = a + b;
    // TEST(res == 0);


    // Вычитание
    // a = 10; b = 5;
    // res = a - b;
    // TEST(res == 5);
    // a = 5; b = 10;
    // res = a - b;
    // TEST(res == -5);
    // a = INT32_MAX; b = 0;
    // res = a - b;
    // TEST(res == INT32_MAX);
    // a = INT32_MIN; b = 0;
    // res = a - b;
    // TEST(res == INT32_MIN);
    // a = 0; b = 0;
    // res = a - b;
    // TEST(res == 0);

        
    // Знаковое умножение
    // a = 10; b = 5;
    // res = a * b;
    // TEST(res == 50);
    // a = -10; b = 5;
    // res = a * b;
    // TEST(res == -50);
    // a = 10; b = -5;
    // res = a * b;
    // TEST(res == -50);
    // a = -10; b = -5;
    // res = a * b;
    // TEST(res == 50);
    // a = 12345; b = 0;
    // res = a * b;
    // TEST(res == 0);
    // a = 0; b = -9876;
    // res = a * b;
    // TEST(res == 0);
    // a = 46340; b = 46340; // 46340*46340 = 2147395600
    // res = a * b;
    // TEST(res == 2147395600);
    // a = -46340; b = 46340;
    // res = a * b;
    // TEST(res == -2147395600);
    // a = INT32_MAX; b = 1;
    // res = a * b;
    // TEST(res == INT32_MAX);
    // a = INT32_MIN; b = 1;
    // res = a * b;
    // TEST(res == INT32_MIN);
    // a = INT32_MAX; b = -1;
    // res = a * b;.
    // TEST(res == -INT32_MAX);
    
    // Беззнаковое умножение
    // ua = 10U; ub = 5U;
    // ures = ua * ub;
    // TEST(ures == 50U);
    // ua = 12345U; ub = 0U;
    // ures = ua * ub;
    // TEST(ures == 0U);
    // ua = 0xFFFFFFFFU; ub = 1U;
    // ures = ua * ub;
    // TEST(ures == 0xFFFFFFFFU);
    // ua = 0xFFFFFFFFU; ub = 2U;
    // ures = ua * ub;
    // // 0xFFFFFFFF * 2 = 8589934590, по модулю 2^32 = 4294967294
    // TEST(ures == 4294967294U);
    // // Дополнительный тест с произвольными числами:
    // // Предварительно вычислено: 12345U * 6789U = 83810205
    // ua = 12345U; ub = 6789U;
    // ures = ua * ub;
    // TEST(ures == 83810205U);
    // // Граничный случай: 0x0000FFFFU * 0x00010001U = 4294967295U
    // ua = 0x0000FFFFU; ub = 0x00010001U;
    // ures = ua * ub;
    // TEST(ures == 0xFFFFFFFFU);
    
    
// --- Тесты для знакового деления и вычисления остатка ---
    
    // Тест 1: Простое деление 10 / 3
    // a = 10; b = 3;
    // res = a / b; 
    // rem = a % b;
    // TEST(res == 3);
    // TEST(rem == 1);
    
    // // Тест 2: Деление с отрицательным делимым (-10 / 3)
    // a = -10; b = 3;
    // res = a / b; 
    // rem = a % b;
    // // По стандарту C99 деление целых чисел округляется к 0,
    // // поэтому ожидаем: -10 / 3 == -3, -10 % 3 == -1.
    // TEST(res == -3);
    // TEST(rem == -1);
    
    // // Тест 3: Деление с отрицательным делителем (10 / -3)
    // a = 10; b = -3;
    // res = a / b;
    // rem = a % b;
    // TEST(res == -3);
    // TEST(rem == 1);
    
    // // Тест 4: Оба отрицательные (-10 / -3)
    // a = -10; b = -3;
    // res = a / b;
    // rem = a % b;
    // TEST(res == 3);
    // TEST(rem == -1);
    
    // // Тест 5: Делимое 0 (0 / 5)
    // a = 0; b = 5;
    // res = a / b;
    // rem = a % b;
    // TEST(res == 0);
    // TEST(rem == 0);
    
    // // Тест 6: Деление на 1 и -1
    // a = INT32_MAX; b = 1;
    // res = a / b;
    // rem = a % b;
    // TEST(res == INT32_MAX);
    // TEST(rem == 0);
    
    // a = INT32_MAX; b = -1;
    // res = a / b;
    // rem = a % b;
    // TEST(res == -INT32_MAX);
    // TEST(rem == 0);
    
    // // Тест 7: Граничный случай: INT32_MIN делить на 1
    // a = INT32_MIN; b = 1;
    // res = a / b;
    // rem = a % b;
    // TEST(res == INT32_MIN);
    // TEST(rem == 0);
    
    // --- Тесты для беззнакового деления и остатка ---
    
    // Тест 1: Простое деление 10U / 3U
    // ua = 10U; ub = 3U;
    // ures = ua / ub;
    // urem = ua % ub;
    // TEST(ures == 3U);
    // TEST(urem == 1U);
    
    // // Тест 2: Делимое 0 (0U / 5U)
    // ua = 0U; ub = 5U;
    // ures = ua / ub;
    // urem = ua % ub;
    // TEST(ures == 0U);
    // TEST(urem == 0U);
    
    // // Тест 3: Делитель равен 1
    // ua = 123456U; ub = 1U;
    // ures = ua / ub;
    // urem = ua % ub;
    // TEST(ures == 123456U);
    // TEST(urem == 0U);
    
    // // Тест 4: Деление максимального значения: 0xFFFFFFFFU / 2U
    // ua = 0xFFFFFFFFU; ub = 2U;
    // ures = ua / ub;
    // urem = ua % ub;
    // // 0xFFFFFFFFU / 2U должно дать 0x7FFFFFFFU с остатком 1
    // TEST(ures == 0x7FFFFFFFU);
    // TEST(urem == 1U);
    
    // // Тест 5: Дополнительный случай: 100U / 6U
    // ua = 100U; ub = 6U;
    // ures = ua / ub;
    // urem = ua % ub;
    // // 100 / 6 = 16, остаток 4 (16*6 = 96, 100-96 = 4)
    // TEST(ures == 16U);
    // TEST(urem == 4U);

    
    // --- Тесты для логических операторов (&&, ||) ---
    // Логическое И (&&)
    // a = 1; b = 1;
    // res = (a && b);
    // TEST(res == 1);
    // a = 0; b = 1;
    // res = (a && b);
    // TEST(res == 0);
    // a = 1; b = 0;
    // res = (a && b);
    // TEST(res == 0);
    // a = 0; b = 0;
    // res = (a && b);
    // TEST(res == 0);
    
    // // Логическое ИЛИ (||)
    // a = 1; b = 1;
    // res = (a || b);
    // TEST(res == 1);
    // a = 0; b = 1;
    // res = (a || b);
    // TEST(res == 1);
    // a = 1; b = 0;
    // res = (a || b);
    // TEST(res == 1);
    // a = 0; b = 0;
    // res = (a || b);
    // TEST(res == 0);

    // --- Тесты для сравнительных операторов (>, >=, <, <=, ==) ---
    // a = 10; b = 5;
    // TEST(a > b);
    // TEST(a >= b);
    // TEST(!(a < b));
    // TEST(!(a <= b));
    // TEST(a != b);
    // TEST(!(a == b));
    
    // a = 5; b = 10;
    // TEST(b > a);
    // TEST(b >= a);
    // TEST(!(b < a));
    // TEST(!(b <= a));
    // TEST(b != a);
    // TEST(!(b == a));
    
    // a = 10; b = 10;
    // TEST(!(a > b));
    // TEST(a >= b);
    // TEST(!(a < b));
    // TEST(a <= b);
    // TEST(a == b);
    
    
    // --- Тесты для побитовых операторов (&, ^, |) ---
    // Побитовое И (&)
    // ua = 0xF0F0F0F0U; ub = 0x0F0F0F0FU;
    // ures = ua & ub;
    // // Ожидаемый результат: 0x00000000U, так как нет общих единичных битов
    // TEST(ures == 0x00000000U);
    // ua = 0xAAAAAAAAU; ub = 0x55555555U;
    // ures = ua & ub;
    // TEST(ures == 0x00000000U);
    
    // // Побитовое ИЛИ (|)
    // ua = 0xF0F0F0F0U; ub = 0x0F0F0F0FU;
    // ures = ua | ub;
    // TEST(ures == 0xFFFFFFFFU);
    // ua = 0xAAAAAAAAU; ub = 0x55555555U;
    // ures = ua | ub;
    // TEST(ures == 0xFFFFFFFFU);
    
    // // Побитовое исключающее ИЛИ (^)
    // ua = 0xF0F0F0F0U; ub = 0x0F0F0F0FU;
    // ures = ua ^ ub;
    // TEST(ures == 0xFFFFFFFFU);
    // ua = 0xAAAAAAAAU; ub = 0x55555555U;
    // ures = ua ^ ub;
    // TEST(ures == 0xFFFFFFFFU);

    // ua = 1U;
    // ures = ua << 1;       // 1 << 1 == 2
    // TEST(ures == 2U);
    
    // ua = 1U;
    // ures = ua << 5;       // 1 << 5 == 32
    // TEST(ures == 32U);
    
    // ua = 0x00000001U;
    // ures = ua << 31;      // максимальный сдвиг: 1 << 31
    // TEST(ures == 0x80000000U);
    
    // // Сдвиг вправо
    // ua = 0x80U;           // 0x80 == 128, бинарное: 1000 0000
    // ures = ua >> 3;       // 128 >> 3 == 16
    // TEST(ures == 16U);
    
    // ua = 0x80000000U;
    // ures = ua >> 31;      // 0x80000000 >> 31 == 1
    // TEST(ures == 1U);
    
    // // Сдвиг на 0 бит должен вернуть исходное значение
    // ua = 0xFFFFFFFFU;
    // ures = ua >> 0;
    // TEST(ures == 0xFFFFFFFFU);
    
    // // --- Тесты для знаковых битовых сдвигов ---
    // // Сдвиг влево для положительных чисел
    // a = 1;
    // res = a << 3;         // 1 << 3 == 8
    // TEST(res == 8);
    
    // a = 12345;
    // res = a << 0;         // сдвиг на 0 бит – исходное значение
    // TEST(res == 12345);
    
    // // Сдвиг вправо для положительных чисел (логический сдвиг)
    // a = 16;
    // res = a >> 2;         // 16 >> 2 == 4
    // TEST(res == 4);
    
    // // Сдвиг вправо для отрицательных чисел (арифметический сдвиг)
    // // По стандарту C для отрицательных чисел сдвиг >> реализует арифметический сдвиг,
    // // то есть знак сохраняется.
    // a = -16;
    // res = a >> 2;         // -16 >> 2 == -4 (арифметический сдвиг)
    // TEST(res == -4);
    
    // a = -1;
    // res = a >> 1;         // Обычно -1 >> 1 остается -1 (так как -1 в двоичном представлении – все биты единицы)
    // TEST(res == -1);

//     unsigned char source32[16] = {
//         0,  1,  2,  3,  4,  5,  6,  7,
//         8,  9, 10, 11, 12, 13, 14, 15
//    };
//    unsigned char dest[12]; 
        
//    memcpy(source32, dest, 12);
        
//    TEST(dest[0]  == source32[0]);
//    TEST(dest[1]  == source32[1]);
//    TEST(dest[2]  == source32[2]);
//    TEST(dest[3]  == source32[3]);
//    TEST(dest[4]  == source32[4]);
//    TEST(dest[5]  == source32[5]);
//    TEST(dest[6]  == source32[6]);
//    TEST(dest[7]  == source32[7]);
//    TEST(dest[8]  == source32[8]);
//    TEST(dest[9]  == source32[9]);
//    TEST(dest[10] == source32[10]);
//    TEST(dest[11] == source32[11]);


   
//    // -- offset = 0 --
//    // Копирование 2 байт с offset 0
//    memcpy(dest, source32 + 0, 2);
//    TEST(dest[0] == source32[0]);
//    TEST(dest[1] == source32[1]);
   
//    // Копирование 4 байт с offset 0
//    memcpy(dest, source32 + 0, 4);
//    TEST(dest[0] == source32[0]);
//    TEST(dest[1] == source32[1]);
//    TEST(dest[2] == source32[2]);
//    TEST(dest[3] == source32[3]);
   
//    // Копирование 8 байт с offset 0
//    memcpy(dest, source32 + 0, 8);
//    TEST(dest[0] == source32[0]);
//    TEST(dest[1] == source32[1]);
//    TEST(dest[2] == source32[2]);
//    TEST(dest[3] == source32[3]);
//    TEST(dest[4] == source32[4]);
//    TEST(dest[5] == source32[5]);
//    TEST(dest[6] == source32[6]);
//    TEST(dest[7] == source32[7]);
   
//    // -- offset = 2 --
//    // Копирование 2 байт с offset 2
//    memcpy(dest, source32 + 2, 2);
//    TEST(dest[0] == source32[2]);
//    TEST(dest[1] == source32[3]);
   
//    // Копирование 4 байт с offset 2
//    memcpy(dest, source32 + 2, 4);
//    TEST(dest[0] == source32[2]);
//    TEST(dest[1] == source32[3]);
//    TEST(dest[2] == source32[4]);
//    TEST(dest[3] == source32[5]);
   
//    // Копирование 8 байт с offset 2
//    memcpy(dest, source32 + 2, 8);
//    TEST(dest[0] == source32[2]);
//    TEST(dest[1] == source32[3]);
//    TEST(dest[2] == source32[4]);
//    TEST(dest[3] == source32[5]);
//    TEST(dest[4] == source32[6]);
//    TEST(dest[5] == source32[7]);
//    TEST(dest[6] == source32[8]);
//    TEST(dest[7] == source32[9]);
   
//    // -- offset = 3 --
//    // Копирование 2 байт с offset 3
//    memcpy(dest, source32 + 3, 2);
//    TEST(dest[0] == source32[3]);
//    TEST(dest[1] == source32[4]);
   
//    // Копирование 4 байт с offset 3
//    memcpy(dest, source32 + 3, 4);
//    TEST(dest[0] == source32[3]);
//    TEST(dest[1] == source32[4]);
//    TEST(dest[2] == source32[5]);
//    TEST(dest[3] == source32[6]);
   
//    // Копирование 8 байт с offset 3
//    memcpy(dest, source32 + 3, 8);
//    TEST(dest[0] == source32[3]);
//    TEST(dest[1] == source32[4]);
//    TEST(dest[2] == source32[5]);
//    TEST(dest[3] == source32[6]);
//    TEST(dest[4] == source32[7]);
//    TEST(dest[5] == source32[8]);
//    TEST(dest[6] == source32[9]);
//    TEST(dest[7] == source32[10]);
   
//    // -- offset = 4 --
//    // Копирование 2 байт с offset 4
//    memcpy(dest, source32 + 4, 2);
//    TEST(dest[0] == source32[4]);
//    TEST(dest[1] == source32[5]);
   
//    // Копирование 4 байт с offset 4
//    memcpy(dest, source32 + 4, 4);
//    TEST(dest[0] == source32[4]);
//    TEST(dest[1] == source32[5]);
//    TEST(dest[2] == source32[6]);
//    TEST(dest[3] == source32[7]);
   
//    // Копирование 8 байт с offset 4
//    memcpy(dest, source32 + 4, 8);
//    TEST(dest[0] == source32[4]);
//    TEST(dest[1] == source32[5]);
//    TEST(dest[2] == source32[6]);
//    TEST(dest[3] == source32[7]);
//    TEST(dest[4] == source32[8]);
//    TEST(dest[5] == source32[9]);
//    TEST(dest[6] == source32[10]);
//    TEST(dest[7] == source32[11]);

    // volatile uint8_t mem[64];
    
    // // Инициализируем весь буфер нулями
    // for (int i = 0; i < 64; i++) {
    //     mem[i] = 0;
    // }
    
    // // ===== 1-байтовые тесты (read/write LB и LBU) =====
    // // Запишем в первые 4 байта известные значения:
    // // 0x00, 0x7F, 0x80, 0xFF.
    // mem[0] = 0x00;  // 0
    // mem[1] = 0x7F;  // 127
    // mem[2] = 0x80;  // 128 (в знаковом виде: -128)
    // mem[3] = 0xFF;  // 255 (в знаковом виде: -1)
    
    // // Чтение беззнакового: просто значение байта
    // TEST(mem[0] == 0x00);
    // TEST(mem[1] == 0x7F);
    // TEST(mem[2] == 0x80);
    // TEST(mem[3] == 0xFF);
    
    // // Чтение со знаковым расширением: преобразуем к int8_t
    // TEST(((int8_t)mem[0]) == 0);
    // TEST(((int8_t)mem[1]) == 127);
    // TEST(((int8_t)mem[2]) == -128);
    // TEST(((int8_t)mem[3]) == -1);
    
    
    // // ===== 2-байтовые тесты (read/write LH и LHU) =====
    // // Используем область mem+4 (должна быть выровнена по 2)
    // volatile uint16_t *half_ptr = (volatile uint16_t *)(mem + 4);
    
    // // Запишем 0x0000
    // *half_ptr = 0x0000;
    // TEST(*half_ptr == 0x0000);
    // TEST(((int16_t)*half_ptr) == 0);
    
    // // Запишем 0x7FFF (максимальное положительное значение для 16 бит)
    // *half_ptr = 0x7FFF;
    // TEST(*half_ptr == 0x7FFF);
    // TEST(((int16_t)*half_ptr) == 32767);
    
    // // Запишем 0x8000 (в знаковом виде: -32768)
    // *half_ptr = 0x8000;
    // TEST(*half_ptr == 0x8000);
    // TEST(((int16_t)*half_ptr) == -32768);
    
    // // Запишем 0xFFFF (в знаковом виде: -1)
    // *half_ptr = 0xFFFF;
    // TEST(*half_ptr == 0xFFFF);
    // TEST(((int16_t)*half_ptr) == -1);
    
    // // Дополнительный краевой тест: значение 0x1234 (4660) и 0xEDCB (0x10000 - 0x1235 = 4661, т.е. -4661)
    // *half_ptr = 0x1234;
    // TEST(*half_ptr == 0x1234);
    // TEST(((int16_t)*half_ptr) == 0x1234); // 4660
    
    // *half_ptr = 0xEDCB;
    // TEST(*half_ptr == 0xEDCB);
    // TEST(((int16_t)*half_ptr) == -4661);
    
    
    // // ===== 4-байтовые тесты (read/write LW) =====
    // // Используем область mem+8 (должна быть выровнена по 4)
    // volatile uint32_t *word_ptr = (volatile uint32_t *)(mem + 8);
    
    // // Тесты для 4-байтовых значений:
    // *word_ptr = 0x00000000;
    // TEST(*word_ptr == 0x00000000);
    
    // *word_ptr = 0x7FFFFFFF;
    // TEST(*word_ptr == 0x7FFFFFFF);
    
    // *word_ptr = 0x80000000;
    // TEST(*word_ptr == 0x80000000);
    
    // *word_ptr = 0xFFFFFFFF;
    // TEST(*word_ptr == 0xFFFFFFFF);
    
    // *word_ptr = 0x12345678;
    // TEST(*word_ptr == 0x12345678);
    
    // // Проверяем, что сохранён порядок байт (предполагается little-endian)
    // // Для 0x12345678 ожидается: 0x78, 0x56, 0x34, 0x12
    // uint8_t expected[4] = { 0x78, 0x56, 0x34, 0x12 };
    // TEST(mem[8]  == expected[0]);
    // TEST(mem[9]  == expected[1]);
    // TEST(mem[10] == expected[2]);
    // TEST(mem[11] == expected[3]);
    
    // // Дополнительный тест: 4-байтовое отрицательное значение (например, 0x89ABCDEF)
    // *word_ptr = 0x89ABCDEF;
    // TEST(*word_ptr == 0x89ABCDEF);
    // // Если интерпретировать как знаковое, то (int32_t)0x89ABCDEF должно сохранить своё значение (отрицательное)
    // TEST(((int32_t)*word_ptr) == (int32_t)0x89ABCDEF);
    
//     int result;
//     unsigned int uresult;

//     unsigned char *res_bytes = (unsigned char *)&result;
// // --- ADDI (rs1 + imm) ---
//     // Тест 1: базовый случай: 5 + 10 = 15.
//     asm volatile ("addi %0, %1, 10" : "=r"(result) : "r"(5));
//     TEST(result == 15);

//     // Тест 2: максимальное положительное imm (2047) с малым rs1.
//     asm volatile ("addi %0, %1, 2047" : "=r"(result) : "r"(5));
//     TEST(result == 5 + 2047);

//     // Тест 3: минимальное отрицательное imm (-2048).
//     asm volatile ("addi %0, %1, -2048" : "=r"(result) : "r"(5));
//     TEST(result == 5 - 2048);

//     // Тест 4: rs1 = 0x7FFFFFFF, imm = -1  → 0x7FFFFFFF - 1.
//     asm volatile ("addi %0, %1, -1" : "=r"(result) : "r"(0x7FFFFFFF));
//     TEST(result == 0x7FFFFFFF - 1);

//     // --- SLTI (set less than, signed) ---
//     // Тест 5: rs1 = 0, imm = 2047  → 0 < 2047 → 1.
//     asm volatile ("slti %0, %1, 2047" : "=r"(result) : "r"(0));
//     TEST(result == 1);

//     // Тест 6: rs1 = 0, imm = -2048 → 0 < -2048 → 0.
//     asm volatile ("slti %0, %1, -2048" : "=r"(result) : "r"(0));
//     TEST(result == 0);

//     // Тест 7: rs1 = -5, imm = -4 → -5 < -4 → 1.
//     asm volatile ("slti %0, %1, -4" : "=r"(result) : "r"(-5));
//     TEST(result == 1);

//     // --- SLTIU (set less than, unsigned) ---
//     // Тест 8: rs1 = 0, imm = 2047 → 0 < 2047 (unsigned) → 1.
//     asm volatile ("sltiu %0, %1, 2047" : "=r"(result) : "r"(0));
//     TEST(result == 1);

//     // Тест 9: rs1 = -1, imm = -1 → (unsigned)-1 == 0xFFFFFFFF, сравнение 0xFFFFFFFF < 0xFFFFFFFF → 0.
//     asm volatile ("sltiu %0, %1, -1" : "=r"(result) : "r"(-1));
//     TEST(result == 0);

//     // --- XORI (bitwise XOR) ---
//     // Тест 10: rs1 = 0x12345678, imm = -1 (что соответствует 0xFFF в 12 битах) → 0x12345678 XOR 0xFFFFFFFF.
//     asm volatile ("xori %0, %1, -1" : "=r"(result) : "r"(0x12345678));
//     TEST(result == ((int)0x12345678 ^ -1));

//     // Тест 11: rs1 = 0xABCDEF, imm = 0 → 0xABCDEF.
//     asm volatile ("xori %0, %1, 0" : "=r"(result) : "r"(0xABCDEF));
//     TEST(result == 0xABCDEF);

//     // --- ORI (bitwise OR) ---
//     // Тест 12: rs1 = 0x12345678, imm = 0x7FF → 0x12345678 | 0x7FF.
//     asm volatile ("ori %0, %1, 0x7FF" : "=r"(result) : "r"(0x12345678));
//     TEST(result == (0x12345678 | 0x7FF));

//     // Тест 13: rs1 = 0x12345678, imm = -2048 → 0x12345678 | 0xFFFFF800.
//     asm volatile ("ori %0, %1, -2048" : "=r"(result) : "r"(0x12345678));
//     TEST(result == 0xFFFFFE78);

//     // --- ANDI (bitwise AND) ---
//     // Тест 14: rs1 = 0xFFFFFFFF, imm = 0x7FF → 0xFFFFFFFF & 0x7FF = 0x7FF.
//     asm volatile ("andi %0, %1, 0x7FF" : "=r"(result) : "r"(0xFFFFFFFF));
//     TEST(result == 0x7FF);

//     // Тест 15: rs1 = 0x12345678, imm = -1 → 0x12345678 & 0xFFFFFFFF = 0x12345678.
//     asm volatile ("andi %0, %1, -1" : "=r"(result) : "r"(0x12345678));
//     TEST(result == 0x12345678);

//     // --- SLLI (shift left logical immediate) ---
//     // Тест 16: rs1 = 0xABCDEF, shift = 0 → результат = 0xABCDEF.
//     asm volatile ("slli %0, %1, 0" : "=r"(result) : "r"(0xABCDEF));
//     TEST(result == 0xABCDEF);

//     // Тест 17: rs1 = 1, shift = 31 → результат = 1 << 31.
//     asm volatile ("slli %0, %1, 31" : "=r"(result) : "r"(1));
//     TEST(result == (1 << 31));

//     // Тест 18: rs1 = -1, shift = 1 → -1 << 1 (остается -1, так как все биты единицы).
//     asm volatile ("slli %0, %1, 1" : "=r"(result) : "r"(-1));
//     TEST(result == -2);

//     // --- SRLI (shift right logical immediate) ---
//     // Тест 19: rs1 = 0xFFFFFFFF, shift = 1 → результат = 0x7FFFFFFF.
//     asm volatile ("srli %0, %1, 1" : "=r"(uresult) : "r"(0xFFFFFFFFU));
//     TEST(uresult == 0x7FFFFFFFU);

//     // Тест 20: rs1 = 0x80000000, shift = 31 → результат = 1.
//     asm volatile ("srli %0, %1, 31" : "=r"(uresult) : "r"(0x80000000U));
//     TEST(uresult == 1U);

//     // --- SRAI (shift right arithmetic immediate) ---
//     // Тест 21: rs1 = -1, shift = 5 → результат всегда -1.
//     asm volatile ("srai %0, %1, 5" : "=r"(result) : "r"(-1));
//     TEST(result == -1);

//     // Тест 22: rs1 = -2048, shift = 1 → -2048 >> 1 = -1024.
//     asm volatile ("srai %0, %1, 1" : "=r"(result) : "r"(-2048));
//     TEST(result == -1024);

//     // Тест 23: rs1 = -15, shift = 2 → ожидается -4.
//     asm volatile ("srai %0, %1, 2" : "=r"(result) : "r"(-15));
//     TEST(result == -4);

//     {
//         // В little-endian представлении 0x12345000 хранится как: 0x00, 0x50, 0x34, 0x12.
//         unsigned char expected[4] = { 0x00, 0x50, 0x34, 0x12 };
//         asm volatile ("lui %0, 0x12345" : "=r"(result));
//         TEST(res_bytes[0] == expected[0]);
//         TEST(res_bytes[1] == expected[1]);
//         TEST(res_bytes[2] == expected[2]);
//         TEST(res_bytes[3] == expected[3]);
//     }

//     // LUI с imm = 0x80000: ожидаемый результат = 0x80000 << 12 = 0x80000000.
//     {
//         // В little-endian представлении 0x80000000 хранится как: 0x00, 0x00, 0x00, 0x80.
//         unsigned char expected[4] = { 0x00, 0x00, 0x00, 0x80 };
//         asm volatile ("lui %0, 0x80000" : "=r"(result));
//         TEST(res_bytes[0] == expected[0]);
//         TEST(res_bytes[1] == expected[1]);
//         TEST(res_bytes[2] == expected[2]);
//         TEST(res_bytes[3] == expected[3]);
//     }

    // int result;
    // unsigned int uresult;

    // // ===== Знаковое деление (DIV) =====
    // // Тест 1: 10 / 2 = 5.
    // asm volatile ("div %0, %1, %2" : "=r"(result) : "r"(10), "r"(2));
    // TEST(result == 5);

    // // Тест 2: -10 / 2 = -5.
    // asm volatile ("div %0, %1, %2" : "=r"(result) : "r"(-10), "r"(2));
    // TEST(result == -5);

    // // Тест 3: 10 / -2 = -5.
    // asm volatile ("div %0, %1, %2" : "=r"(result) : "r"(10), "r"(-2));
    // TEST(result == -5);

    // // Тест 4: -10 / -2 = 5.
    // asm volatile ("div %0, %1, %2" : "=r"(result) : "r"(-10), "r"(-2));
    // TEST(result == 5);

    // // Тест 5: Деление на 0. Согласно спецификации RISC‑V, DIV при делении на 0 возвращает -1.
    // asm volatile ("div %0, %1, %2" : "=r"(result) : "r"(123), "r"(0));
    // TEST(result == -1);

    // // ===== Знаковый остаток (REM) =====
    // // Тест 6: 10 % 3 = 1.
    // asm volatile ("rem %0, %1, %2" : "=r"(result) : "r"(10), "r"(3));
    // TEST(result == 1);

    // // Тест 7: -10 % 3. При делении -10 / 3 по правилу округления к 0, частное будет -3, поэтому остаток = -10 - (-3)*3 = -10 + 9 = -1.
    // asm volatile ("rem %0, %1, %2" : "=r"(result) : "r"(-10), "r"(3));
    // TEST(result == -1);

    // // Тест 8: 10 % -3. Частное = -3 (10/-3 округляется к 0), остаток = 10 - (-3)*(-3) = 10 - 9 = 1.
    // asm volatile ("rem %0, %1, %2" : "=r"(result) : "r"(10), "r"(-3));
    // TEST(result == 1);

    // // Тест 9: -10 % -3. Частное = 3 (т.к. -10/-3 = 3 с округлением к 0), остаток = -10 - (3 * -3) = -10 + 9 = -1.
    // asm volatile ("rem %0, %1, %2" : "=r"(result) : "r"(-10), "r"(-3));
    // TEST(result == -1);

    // // ===== Беззнаковое деление (DIVU) =====
    // // Тест 10: 10U / 2U = 5U.
    // asm volatile ("divu %0, %1, %2" : "=r"(uresult) : "r"(10U), "r"(2U));
    // TEST(uresult == 5U);

    // // Тест 11: 0xFFFFFFFFU / 2U = 0x7FFFFFFFU.
    // asm volatile ("divu %0, %1, %2" : "=r"(uresult) : "r"(0xFFFFFFFFU), "r"(2U));
    // TEST(uresult == 0x7FFFFFFFU);

    // // Тест 12: Деление на 0 для беззнакового деления. Согласно спецификации, DIVU при делении на 0 возвращает 0xFFFFFFFFU.
    // asm volatile ("divu %0, %1, %2" : "=r"(uresult) : "r"(123U), "r"(0U));
    // TEST(uresult == 0xFFFFFFFFU);

    // // ===== Беззнаковый остаток (REMU) =====
    // // Тест 13: 10U % 3U = 1U.
    // asm volatile ("remu %0, %1, %2" : "=r"(uresult) : "r"(10U), "r"(3U));
    // TEST(uresult == 1U);

    // // Тест 14: 0xFFFFFFFFU % 3U.
    // // 0xFFFFFFFFU = 4294967295, а 4294967295 / 3 = 1431655765 без остатка, так как 3 * 1431655765 = 4294967295.
    // asm volatile ("remu %0, %1, %2" : "=r"(uresult) : "r"(0xFFFFFFFFU), "r"(3U));
    // TEST(uresult == 0U);

    // // Тест 15: Беззнаковый остаток при делении на 0: REMU возвращает делимое.
    // asm volatile ("remu %0, %1, %2" : "=r"(uresult) : "r"(123U), "r"(0U));
    // TEST(uresult == 123U);

    int result;
    unsigned int uresult;

    // ====================================================
    // MUL: нижние 32 бита знакового умножения
    // ====================================================
    // Тест 1: 2 * 3 = 6.
    asm volatile ("mul %0, %1, %2" : "=r"(result) : "r"(2), "r"(3));
    TEST(result == 6);

    // Тест 2: (-2) * 3 = -6.
    asm volatile ("mul %0, %1, %2" : "=r"(result) : "r"(-2), "r"(3));
    TEST(result == -6);

    // Тест 3: rs1 = 0x7FFFFFFF, rs2 = 2.
    // 0x7FFFFFFF * 2 = 0xFFFFFFFE (без переполнения в 64-битном результате, нижние 32 бита).
    asm volatile ("mul %0, %1, %2" : "=r"(result) : "r"(0x7FFFFFFF), "r"(2));
    // Используем 64-битное вычисление в константном выражении для ожидания:
    TEST(result == (int)((0x7FFFFFFFLL * 2LL) & 0xFFFFFFFFULL));

    // ====================================================
    // MULH: верхние 32 бита знакового умножения
    // ====================================================
    // Тест 4: (-1) * (-1) = 1, но 64-битное представление 1 = 0x00000000_00000001, верхние 32 бита = 0.
    asm volatile ("mulh %0, %1, %2" : "=r"(result) : "r"(-1), "r"(-1));
    TEST(result == 0);

    // Тест 5: rs1 = 0x80000000, rs2 = 2.
    // 0x80000000 (как знаковое, это -2147483648) * 2 = -4294967296.
    // 64-битное представление: 0xFFFFFFFF00000000, верхние 32 бита = 0xFFFFFFFF, что интерпретируется как -1.
    asm volatile ("mulh %0, %1, %2" : "=r"(result) : "r"(0x80000000), "r"(2));
    TEST(result == -1);

    // Тест 6: rs1 = 0x12345678, rs2 = 2. Оба положительные, продукт 0x2468ACF0, верхних 32 бит = 0.
    asm volatile ("mulh %0, %1, %2" : "=r"(result) : "r"(0x12345678), "r"(2));
    TEST(result == 0);

    // ====================================================
    // MULHSU: верхние 32 бита произведения, где первый операнд знаковый, второй беззнаковый
    // ====================================================
    // Тест 7: rs1 = -1, rs2 = 2.
    // Знаковый -1 в 32 бит: 0xFFFFFFFF (расширяется до 64 бит как 0xFFFFFFFFFFFFFFFF).
    // Умножение: 0xFFFFFFFFFFFFFFFF * 2 = 0x1FFFFFFFFFFFFFFFE.
    // Верхние 32 бита: floor(0x1FFFFFFFFFFFFFFFE / 0x100000000) = 0x1FFFFFFFE.
    // Но поскольку результат хранится в 32 битах, 0x1FFFFFFFE & 0xFFFFFFFF = 0xFFFFFFFE.
    asm volatile ("mulhsu %0, %1, %2" : "=r"(result) : "r"(-1), "r"(2U));
    TEST((unsigned int)result == 0xFFFFFFFFU);

    // Тест 8: rs1 = -2, rs2 = 3.
    // -2 (0xFFFFFFFE) * 3 = -6. 64-битное представление: 0xFFFFFFFFFFFFFFFA.
    // Верхние 32 бита = floor(0xFFFFFFFFFFFFFFFA / 0x100000000) = 0xFFFFFFFF.
    asm volatile ("mulhsu %0, %1, %2" : "=r"(result) : "r"(-2), "r"(3U));
    TEST((unsigned int)result == 0xFFFFFFFFU);

    // ====================================================
    // MULHU: верхние 32 бита беззнакового умножения
    // ====================================================
    // Тест 9: 2U * 3U = 6, верхние 32 бита = 0.
    asm volatile ("mulhu %0, %1, %2" : "=r"(uresult) : "r"(2U), "r"(3U));
    TEST(uresult == 0U);

    // Тест 10: 0xFFFFFFFFU * 0xFFFFFFFFU.
    // Вычисление: (2^32-1)^2 = 2^64 - 2^(33) + 1.
    // Верхние 32 бита = (2^64 - 2^(33) + 1) >> 32 = 0xFFFFFFFF - 2 + 0 = 0xFFFFFFFE.
    asm volatile ("mulhu %0, %1, %2" : "=r"(uresult) : "r"(0xFFFFFFFFU), "r"(0xFFFFFFFFU));
    TEST(uresult == 0xFFFFFFFEU);

    // Тест 11: 0x80000000U * 2U.
    // 0x80000000U = 2147483648, умножение на 2 даёт 4294967296, что представлено как 0x100000000.
    // Верхние 32 бита = 1.
    asm volatile ("mulhu %0, %1, %2" : "=r"(uresult) : "r"(0x80000000U), "r"(2U));
    TEST(uresult == 1U);

    *TERMINATE_SUCCESS = 1;
}
