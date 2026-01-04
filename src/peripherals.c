#include "framebuffer.h"
#include "master_include.h"
#include "uart.h"
#include "led.h"

// volatile device_uart_t *device_uart =
//     (volatile device_uart_t *)UART_START_ADDRESS;

volatile device_video_t *device_video =
    (volatile device_video_t *)VIDEO_START_ADDRESS;

volatile device_led_t *device_led = 
    (volatile device_led_t *) LED_DRIVER_ADDRESS;

volatile void *device_framebuffer = 
    (volatile void *) FRAMEBUFFER_START_ADDRESS;