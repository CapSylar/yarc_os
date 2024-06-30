#pragma once

#include <stdint.h>

typedef struct
{
    uint8_t led_state;
} __attribute__((packed)) device_led_t;