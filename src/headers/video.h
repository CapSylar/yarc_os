#pragma once

#include <stdint.h>

typedef union
{
    struct
    {
        uint32_t is_text_mode : 1;
        uint32_t is_enabled   : 1;
        uint32_t unused       : 30;
    } __attribute__((packed));
} video_core_ctrl_t;

typedef union
{
    struct
    {
        uint32_t fetch_address; // framebuffer fetch address
    } __attribute__((packed));
} video_core_address_t;

typedef struct
{
    video_core_ctrl_t ctrl_reg;
    video_core_address_t address_reg;
} __attribute__((packed)) device_video_t;

// function declarations
void init_video();