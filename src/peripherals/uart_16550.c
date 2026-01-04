#include "uart.h"
#include "master_include.h"
#include "platform.h"
#include "uart_16550.h"

// need to call this before interracting with the uart module
void init_uart_16550(void)
{
  // disable interrupts
  *UART_16550_IE = 0;

  *UART_16550_LCR = (uart_16550_lcr_t) {.divisor_latch_access = 1}.val;

  // set diviors
  // write 10
  *UART_16550_DIVISOR_HIGH = 0;
  *UART_16550_DIVISOR_LOW  = 10;

  // no parity, 8 bits per character, 1 stop bit
  *UART_16550_LCR = (uart_16550_lcr_t) {
    .divisor_latch_access = 0,
    .num_bits_char = 3,
    .num_stop_bits = 0,
    .parity_enable = 0
  }.val;

  // clear fifos
  *UART_16550_FFC = (uart_16550_fifo_ctrl_t) {.clear_rxff = 1, .clear_txff = 1}.val;
}