#include "framebuffer.h"
#include "master_include.h"
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

char * hello_str =    
"    __   __                    ______  _         _     __                         \n"
"    \\ \\ / /                    | ___ \\| |       | |   / _|                        \n"
"     \\ V /   __ _  _ __   ___  | |_/ /| |  __ _ | |_ | |_   ___   _ __  _ __ ___  \n"
"      \\ /   / _` || '__| / __| |  __/ | | / _` || __||  _| / _ \\ | '__|| '_ ` _ \\ \n"
"      | |  | (_| || |   | (__  | |    | || (_| || |_ | |  | (_) || |   | | | | | |\n"
"      \\_/   \\__,_||_|    \\___| \\_|    |_| \\__,_| \\__||_|   \\___/ |_|   |_| |_| |_|\n";

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

  init_console();
  printf("hello world\n");

  // printf(hello_str);

  // write to frambuffer
  for(size_t j = 0;; ++j)
  {
    printf(hello_str);
    for (size_t i = 0; i < 100000; ++i)
    {
      asm volatile ("nop");
    }

    for (size_t i = 0; i < FRAMEBUFFER_WORDS; ++i)
    {
      uint8_t red = j > 0x1000;
      uint8_t green = j > 0x5000 & j < 0x10000;
      uint8_t blue = j > 0x10000 & j < 0x20000;
      device_fb->fb[i] = (red << 24) | (blue << 16) | (green << 8) | (red);
    }
  }

  printf("done writing to fb");

  for (;;) {} // parking loop
}