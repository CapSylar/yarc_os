#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef union
{
    struct
    {
        uint32_t is_enabled   : 1;
        uint32_t is_text_mode : 1;
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

typedef struct
{
    bool is_enabled;
    bool is_text_mode;
    void *fb_address; // set in the address register
} video_dev_t;

// text mode structs
#define CHARACTER_MODE_W ((80)) // max 80 characters on a single line
#define CHARACTER_MODE_H ((30)) // max 30 characters in a single column
#define CHARACTER_COUNT ((CHARACTER_MODE_W * CHARACTER_MODE_H))

#define RAW_MODE_W ((640))
#define RAW_MODE_H ((480))
#define RAW_MODE_FRAME_SIZE_BYTES ((RAW_MODE_H * RAW_MODE_W * 4))
typedef union
{
    struct {
        uint16_t code_point: 8;
        uint16_t fg_color : 4;
        uint16_t bg_color : 3;
        uint16_t blink : 1;
    } __attribute__((packed));
    
    uint16_t val;
 } text_mode_char_t;

typedef enum {
    VIDEO_RAW_MODE = 0,
    VIDEO_TEXT_MODE = 1
} video_mode_t;

// function declarations
void init_video(video_dev_t *device);
void video_device_set_mode (video_dev_t *device, video_mode_t video_mode);
void video_device_set_fb_address(video_dev_t *device, void *fb_byte_address);
void text_mode_clear_screen(const video_dev_t *device);
void raw_mode_clear_screen(const video_dev_t *device);
void video_device_set_enable(video_dev_t *device, bool state);