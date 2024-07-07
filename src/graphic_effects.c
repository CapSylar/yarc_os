#include "graphic_effects.h"
#include <stdint.h>

void draw_checker_pattern(volatile void *fb, int cube_size, bool offset) {

  volatile uint32_t *fb_ptr = fb;
  for (size_t i = 0; i < (RAW_MODE_H * RAW_MODE_W) ; ++i) {

    bool draw = ((i / cube_size) % 2) == 0;
    bool pixel_offset = (i / (640 * cube_size) % 2) != 0;

    if (offset) {
      pixel_offset = !pixel_offset;
    }

    fb_ptr[i + pixel_offset * cube_size] = draw ? 0x00FF0000 : 0;
  }
}