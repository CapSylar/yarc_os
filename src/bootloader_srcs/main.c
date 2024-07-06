#include "master_include.h"
#include <stdint.h>
#include "greeting.h"

int main(void)
{
  // disable interrupts
  write_csr(CSR_MIE, 0);

  // set up mtvec and trap table
  write_csr(CSR_MTVEC, ((uint32_t)trap_table) | 0x1); // vectored mode

  // setup uart
  init_console();

  print_greeting();
  uart_loader();

  for (;;) {} // parking loop
}