// contains the addresses of all memory mapped peripherals

#include "led.h"
#include "uart.h"
#include "video.h"
#include "framebuffer.h"

#define PERIPH_BASE_ADDR 0xA1000000

#define UART_PERIPH_START ((PERIPH_BASE_ADDR))
#define VIDEO_CORE_START ((PERIPH_BASE_ADDR + 0x40))

// fpga board led driver
#define LED_DRIVER_ADDRESS (((volatile uint32_t *) (PERIPH_BASE_ADDR + 0x20) ))

// uart driver
#define UART_START_ADDRESS (((volatile uint32_t *) (UART_PERIPH_START + 4 * 0)))
#define UART_SETUP_REG  (((volatile uint32_t *) (UART_PERIPH_START + 4 * 0)))
#define UART_FIFO_REG (((volatile uint32_t *) (UART_PERIPH_START + 4 * 1)))
#define UART_RX_DATA_REG (((volatile uint32_t *) (UART_PERIPH_START + 4 * 2)))
#define UART_TX_DATA_REG (((volatile uint32_t *) (UART_PERIPH_START + 4 * 3)))

// video core
#define VIDEO_START_ADDRESS (((volatile uint32_t *) (VIDEO_CORE_START + 4 * 0)))

// ddr3 framebuffer
#define FRAMEBUFFER_START_ADDRESS (void *) (0xC0000000)

// DEVICES
// extern volatile device_uart_t* device_uart;
extern volatile device_video_t* device_video;
extern volatile device_led_t* device_led;
extern volatile void *device_framebuffer;