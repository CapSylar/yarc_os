#pragma once

#include <stdint.h>

#define FRAMEBUFFER_WORDS 230313

typedef union
{
    uint32_t buffer[230400];
} device_framebuffer_t;