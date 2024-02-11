#ifndef __CONSOLE_H_GUARD__
#define __CONSOLE_H_GUARD__

#define PRINT_BUFFER_SIZE 128
#define PRINTF_DISABLE_SUPPORT_FLOAT
#define PRINTF_DISABLE_SUPPORT_EXPONENTIAL

void init_console();
void console_putchar(char c);

#endif // __CONSOLE_H_GUARD__