#include "console.h"
#include "framebuffer.h"
#include "master_include.h"
#include "printf.h"
#include <stdint.h>
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

  video_dev_t video_device;
  init_video(&video_device);

  void *fb_address = FRAMEBUFFER_START_ADDRESS;

  video_device_set_mode(&video_device, VIDEO_RAW_MODE);
  video_device_set_fb_address(&video_device, fb_address);
  raw_mode_clear_screen(&video_device);

  video_device_set_fb_address(&video_device, fb_address + RAW_MODE_FRAME_SIZE_BYTES);
  raw_mode_clear_screen(&video_device);
  
  // switch back to first framebuffer
  video_device_set_fb_address(&video_device, fb_address);

  volatile uint8_t *fb = video_device.fb_address;

  draw_checker_pattern(fb, 16, false);
  draw_checker_pattern(fb + RAW_MODE_FRAME_SIZE_BYTES, 16, true);

  video_device_set_enable(&video_device, true);

  int current_fb = 0;

  for (;;) {

    for (size_t i = 0; i < 10000000; ++i) {
      asm volatile ("nop");
    }

    current_fb = (current_fb + 1) % 2;
    volatile uint32_t *fb = FRAMEBUFFER_START_ADDRESS + current_fb * RAW_MODE_FRAME_SIZE_BYTES;
    video_device_set_fb_address(&video_device, (void *) fb);
  }

  for (;;) {} // parking loop
}