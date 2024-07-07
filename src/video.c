
#include "video.h"
#include "master_include.h"
#include <stdint.h>

void init_video(video_dev_t *device) {
    // wait for the DDR3 memory to become ready

    volatile uint16_t *fb = (void *) FRAMEBUFFER_START_ADDRESS;
    *fb; // this load will block until the DDR3 memory is ready

    device_video->ctrl_reg.is_enabled = 0;
    device_video->ctrl_reg.is_text_mode = 0;

    // the video core sees the framebuffer in a different address space
    // in this space the fb starts at 0
    device_video->address_reg.fetch_address = 0;
}

void video_device_set_mode (video_dev_t *device, video_mode_t video_mode) {
    device->is_text_mode = video_mode;
    device_video->ctrl_reg.is_text_mode = (video_mode == VIDEO_TEXT_MODE);
}

void video_device_set_fb_address(video_dev_t *device, void *fb_byte_address) {
    device->fb_address = fb_byte_address;

    // the address must be divided by 16 because the video core reads using "16 byte word" addresses
    device_video->address_reg.fetch_address = (fb_byte_address - FRAMEBUFFER_START_ADDRESS) / 16;
}

void text_mode_clear_screen(const video_dev_t *device) {
    volatile uint16_t *fb = device->fb_address;

    for (size_t i = 0; i < CHARACTER_COUNT; ++i) {
        fb[i] = ' ';
    }
}

void raw_mode_clear_screen(const video_dev_t *device) {
    volatile uint32_t *fb = device->fb_address;

    for (size_t i = 0; i < RAW_MODE_H * RAW_MODE_W; ++i) {
        fb[i] = 0;
    }
}

void video_device_set_enable(video_dev_t *device, bool state) {
    device->is_enabled = state;
    device_video->ctrl_reg.is_enabled = state;
}