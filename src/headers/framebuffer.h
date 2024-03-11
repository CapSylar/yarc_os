#pragma once

#include <stdint.h>

#define FRAMEBUFFER_WORDS 230313

typedef union
{
    uint32_t fb[230400];
} device_fb_t;