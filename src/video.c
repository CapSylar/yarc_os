
#include "master_include.h"

void init_video() {
    // wait for the DDR3 memory to become ready

    volatile uint16_t *fb = FRAMEBUFFER_START_ADDRESS;

    *fb; // this load will block until the DDR3 memory is ready

    device_video->ctrl_reg.is_enabled = 1;
    device_video->ctrl_reg.is_text_mode = 1;

    device_video->address_reg.fetch_address = 0; // w.r.t start of framebuffer
}