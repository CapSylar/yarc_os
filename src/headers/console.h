#ifndef __CONSOLE_H_GUARD__
#define __CONSOLE_H_GUARD__

#include <stdint.h>
#define PRINT_BUFFER_SIZE 128
#define PRINTF_DISABLE_SUPPORT_FLOAT
#define PRINTF_DISABLE_SUPPORT_EXPONENTIAL

void init_console();
void console_putchar(char c);
uint8_t console_getc(void);

#endif // __CONSOLE_H_GUARD__