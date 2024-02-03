#include "csr.h"
#include "master_include.h"
#include "uart.h"
#include <stdint.h>

uint8_t num_times;

void handle_timer_irq()
{
  *REG_MTIMEH = 0x0;
  *REG_MTIME = 0x0;
  *REG_MTIMECMPH = 0x0;
  *REG_MTIMECMP = 0x1000;

  // display on the leds, the number of times this interrupt happened
  *FPGA_LED_STATUS = ++num_times;
}

volatile uint8_t hello [10] = {};
volatile uint8_t *vol_ptr = hello;

int main(void)
{
  // disable interrupts
  write_csr(CSR_MIE, 0);

  // set up mtvec and trap table
  write_csr(CSR_MTVEC, ((uint32_t)trap_table) | 0x1); // vectored mode

  // register_irq_handler(TIMER_IRQ_INT, handle_timer_irq);
  // small test sequence for mtimer

  // clear the fpga leds
  // *FPGA_LED_STATUS = 0;

  // *REG_MTIMEH = 0x0;
  // *REG_MTIME = 0x0;
  // *REG_MTIMECMPH = 0x0;
  // *REG_MTIMECMP = 0x1000;

  // // enable interrupts
  // csr_mstatus_t mstatus_reg = {.val = read_csr(CSR_MSTATUS)};
  // // in mstatus
  // mstatus_reg.mie = 1;
  // write_csr(CSR_MSTATUS, mstatus_reg.val);

  // // enable interrupts in mie
  // csr_mie_t mie_reg = {.mtip = 1};
  // write_csr(CSR_MIE, mie_reg.val);

  // setup uart
  uart_tx_data_t tx_reg = {.val = *UART_TX_DATA_REG};
  tx_reg.tx_word = 'y';
  *UART_TX_DATA_REG = tx_reg.val;
  tx_reg.tx_word = 'a';
  *UART_TX_DATA_REG = tx_reg.val;
  tx_reg.tx_word = 'r';
  *UART_TX_DATA_REG = tx_reg.val;
  tx_reg.tx_word = 'c';
  *UART_TX_DATA_REG = tx_reg.val;
  for (;;) {} // parking loop
}