#include "uart.h"
#include "master_include.h"
#include "platform.h"

// need to call this before interracting with the uart module
void init_uart()
{
  // write the uart config reg
  uart_setup_t uart_setup_reg = {.baud_clks = (MAIN_CLK_FREQ / UART_BAUD_RATE),
                                 .parity_used = 0, // not parity
                                 .parity_settings =
                                     0,         // since parity is not used
                                 .stop_bit = 0, // 1 stop bit
                                 .num_bits = 0, // 8 bits per word
                                 .disable_hw_flow_ctrl = 1};

  *UART_SETUP_REG = uart_setup_reg.val;
}