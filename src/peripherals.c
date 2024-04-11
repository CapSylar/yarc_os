#include "master_include.h"
#include "uart.h"

volatile device_uart_t *device_uart =
    (volatile device_uart_t *)UART_START_ADDRESS;

// volatile device_fb_t *device_fb =
//     (volatile device_fb_t *)FB_START_ADDRESS;