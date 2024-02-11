#include "master_include.h"
#include "uart.h"

volatile device_uart_t *device_uart =
    (volatile device_uart_t *)UART_START_ADDRESS;