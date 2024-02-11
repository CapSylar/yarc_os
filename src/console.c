#include "master_include.h"

static char print_buffer[PRINT_BUFFER_SIZE];

void init_q();
int push_q(char c);
char pop_q();

static size_t size_q;

void init_console()
{
    // first initialize the print buffer
    init_q();

    // init uart
    init_uart();
}

void console_putchar(char c)
{
    // while (push_q(c)) {} // will block if no place in print buffer

    // if (size_q >= PLATFORM_UART_BUFFER_SIZE) {

    // }
    while (!(device_uart->fifo_reg.tx_one)) {}
    device_uart->tx_data_reg.tx_word = c;
}

static size_t head_i, tail_i;

bool is_q_full();
bool is_q_empty();

void init_q() { head_i = tail_i = size_q = 0; }

int push_q(char c)
{
    if (is_q_full())
        return 1;

    print_buffer[tail_i] = c;
    tail_i = (tail_i + 1) % PRINT_BUFFER_SIZE;
    ++size_q;
    return 0;
}

char pop_q()
{
    if (is_q_empty())
        return 0; // null character

    char c = print_buffer[head_i];
    head_i = (head_i + 1) % PRINT_BUFFER_SIZE;
    --size_q;
    return c;
}

bool is_q_full() { return (size_q == PRINT_BUFFER_SIZE); }
bool is_q_empty() { return !size_q; }

// this function is required by tinyprintf
void _putchar(char character)
{
    // send character to console (uart in our case)
    console_putchar(character);
}