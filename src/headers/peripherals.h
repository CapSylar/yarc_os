// contains the addresses of all memory mapped peripherals

#include "led.h"
#include "uart.h"
#include "video.h"
#include "framebuffer.h"

#define PERIPH_BASE_ADDR 0xA0000000

#define UART_PERIPH_START ((PERIPH_BASE_ADDR + 0x20))
#define VIDEO_CORE_START ((PERIPH_BASE_ADDR + 0x40))

// RISCV TIMER
#define REG_MTIME (((volatile uint32_t *) (PERIPH_BASE_ADDR + 0 * 4) ))
#define REG_MTIMEH (((volatile uint32_t *) (PERIPH_BASE_ADDR + 1 * 4)))

#define REG_MTIMECMP (((volatile uint32_t *) (PERIPH_BASE_ADDR + 2 * 4) ))
#define REG_MTIMECMPH (((volatile uint32_t *) (PERIPH_BASE_ADDR + 3 * 4)))

// fpga board led driver
#define LED_DRIVER_ADDRESS (((volatile uint32_t *) (PERIPH_BASE_ADDR + 4 * 4) ))

// uart driver
#define UART_START_ADDRESS (((volatile uint32_t *) (UART_PERIPH_START + 4 * 0)))
#define UART_SETUP_REG  (((volatile uint32_t *) (UART_PERIPH_START + 4 * 0)))
#define UART_FIFO_REG (((volatile uint32_t *) (UART_PERIPH_START + 4 * 1)))
#define UART_RX_DATA_REG (((volatile uint32_t *) (UART_PERIPH_START + 4 * 2)))
#define UART_TX_DATA_REG (((volatile uint32_t *) (UART_PERIPH_START + 4 * 3)))

// video core
#define VIDEO_START_ADDRESS (((volatile uint32_t *) (VIDEO_CORE_START + 4 * 0)))

// ddr3 framebuffer
#define FRAMEBUFFER_START_ADDRESS (volatile void *) (0xC0000000);

// DEVICES
extern volatile device_uart_t* device_uart;
extern volatile device_video_t* device_video;
extern volatile device_led_t* device_led;
extern volatile void *device_framebuffer;