#include "console.h"
#include "csr.h"
#include "framebuffer.h"
#include "master_include.h"
#include "printf.h"
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include "greeting.h"
#include "video.h"
#include "graphic_effects.h"

uint8_t num_times;

void handle_timer_irq()
{
  *REG_MTIMEH = 0x0;
  *REG_MTIME = 0x0;
  *REG_MTIMECMPH = 0x0;
  *REG_MTIMECMP = 0x1000;

  // display on the leds, the number of times this interrupt happened
  // *FPGA_LED_STATUS = ++num_times;
}

int main(void)
{
  // printf("hello, world\n");

  // uint64_t cycle_before =  (uint64_t) read_csr(CSR_MCYCLEH) << 32 | read_csr(CSR_MCYCLE);
  // uint64_t instret_before = (uint64_t) read_csr(CSR_MINSTRETH) << 32 | read_csr(CSR_MINSTRET);

  // // disable interrupts
  // write_csr(CSR_MIE, 0);

  // // set up mtvec and trap table
  // write_csr(CSR_MTVEC, ((uint32_t)trap_table) | 0x1); // vectored mode

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

  // for (size_t i = 0; i < 1; ++i) {
    printf("hello, world\n");
  // }

  // volatile uint32_t *fb = FRAMEBUFFER_START_ADDRESS + 0x20000;

  // for (size_t i = 0 ; i < 0x800; ++i) {
  //   fb[i];
  // }

  // for (size_t i = 0; i < 0x800; ++i) {
  //   fb[i] = i;
  // }

  // for (size_t i = 0 ; i < 0x800; ++i) {
  //   if (fb[i] != i) {
  //     printf("error data %d\n", i);
  //   } else {
  //     printf("success at data %d\n", i);
  //   }
  // }

  video_dev_t video_device;
  init_video(&video_device);

  void *fb_address = FRAMEBUFFER_START_ADDRESS;

  video_device_set_mode(&video_device, VIDEO_TEXT_MODE);
  video_device_set_fb_address(&video_device, fb_address);
  text_mode_clear_screen(&video_device);
  // raw_mode_clear_screen(&video_device);

  // video_device_set_fb_address(&video_device, fb_address + RAW_MODE_FRAME_SIZE_BYTES);
  // raw_mode_clear_screen(&video_device);
  
  // // switch back to first framebuffer
  // video_device_set_fb_address(&video_device, fb_address);

  // volatile uint8_t *fb = video_device.fb_address;

  // draw_checker_pattern(fb, 16, false);
  // draw_checker_pattern(fb + RAW_MODE_FRAME_SIZE_BYTES, 16, true);

  video_device_set_enable(&video_device, true);

  volatile uint16_t *fb = (void *) fb_address;

  char *str = "hello, world                        ";

  for (int i = 0; i < strlen(str); ++i) {
    printf("char at %c\n", str[i]);
  }

  for (int i = 0; i < strlen(str); ++i) {
    text_mode_char_t video_char = {.code_point = str[i], .blink = 0, .bg_color = 0, .fg_color = 2};
    fb[i] = video_char.val;
    printf("wrote\n");
  }



  // int current_fb = 0;

  // for (;;) {

  //   for (size_t i = 0; i < 10000000; ++i) {
  //     asm volatile ("nop");
  //   }

  //   current_fb = (current_fb + 1) % 2;
  //   volatile uint32_t *fb = FRAMEBUFFER_START_ADDRESS + current_fb * RAW_MODE_FRAME_SIZE_BYTES;
  //   video_device_set_fb_address(&video_device, (void *) fb);
  // }

  // uint64_t cycle_after =  (uint64_t) read_csr(CSR_MCYCLEH) << 32 | read_csr(CSR_MCYCLE);
  // uint64_t instret_after = (uint64_t) read_csr(CSR_MINSTRETH) << 32 | read_csr(CSR_MINSTRET);

  // uint64_t cycles_taken = cycle_after - cycle_before;
  // uint64_t instr_taken = instret_after - instret_before;

  // printf("cycles taken upper: %d\n", (uint32_t) (cycles_taken >> 32));
  // printf("cycles taken lower: %d\n", (uint32_t) cycles_taken);

  // printf("instr taken upper: %d\n", (uint32_t) (instr_taken >> 32));
  // printf("instr taken lower: %d\n", (uint32_t) instr_taken);

  for (;;) {} // parking loop
}