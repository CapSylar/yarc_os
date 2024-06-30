
#include "master_include.h"

void init_video() {
    // wait for the DDR3 memory to become ready

    volatile uint16_t *fb = FRAMEBUFFER_START_ADDRESS;

    *fb; // this load will block until the DDR3 memory is ready

    device_video->ctrl_reg.is_enabled = 1;
    device_video->ctrl_reg.is_text_mode = 1;

    device_video->address_reg.fetch_address = 0; // w.r.t start of framebuffer

    for (size_t i = 0;;) {
      uint8_t c = console_getc();
      fb[i++] = c;
      printf("got %c\n", c);
      if (i > (80  * 30)) {
        i = 0;
      }
    }
}