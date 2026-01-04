#pragma once

#include "peripherals.h"
#include "uart.h"

#define UART_16550_START_ADDRESS ((volatile uint8_t *)UART_START_ADDRESS)

#define UART_16550_RCV (UART_16550_START_ADDRESS)
#define UART_16550_TXH (UART_16550_START_ADDRESS)

#define UART_16550_IE (UART_16550_START_ADDRESS + 1)

#define UART_16550_ID  (UART_16550_START_ADDRESS + 2)
#define UART_16550_FFC (UART_16550_START_ADDRESS + 2)

#define UART_16550_LCR (UART_16550_START_ADDRESS + 3)
#define UART_16550_MC  (UART_16550_START_ADDRESS + 4)
#define UART_16550_LS  (UART_16550_START_ADDRESS + 5)
#define UART_16550_MS  (UART_16550_START_ADDRESS + 6)

// 16-bit register
#define UART_16550_DIVISOR_LOW  (UART_16550_START_ADDRESS + 0)
#define UART_16550_DIVISOR_HIGH (UART_16550_START_ADDRESS + 1)

typedef union
{
    struct
    {
        uint8_t rcv_data_available   : 1;
        uint8_t tx_holding_reg_empty : 1;
        uint8_t receive_line_status  : 1;
        uint8_t modem_status         : 1;
    } __attribute__((packed));

    uint8_t val;
} uart_16550_ie_t;

typedef union
{
    struct
    {
        uint8_t                : 1;
        uint8_t clear_rxff     : 1;
        uint8_t clear_txff     : 1;
        uint8_t                : 3;
        uint8_t ff_trigger_lvl : 2;
    } __attribute__((packed));

    uint8_t val;
} uart_16550_fifo_ctrl_t;

typedef union
{
    struct
    {
        uint8_t num_bits_char        : 2;
        uint8_t num_stop_bits        : 1;
        uint8_t parity_enable        : 1;
        uint8_t even_parity_select   : 1;
        uint8_t stick_parity_bit     : 1;
        uint8_t break_control_bit    : 1;
        uint8_t divisor_latch_access : 1;
    } __attribute__((packed));

    uint8_t val;
} uart_16550_lcr_t;

typedef union
{
    struct
    {
        uint8_t dtr_control   : 1;
        uint8_t rts_control   : 1;
        uint8_t out1          : 1;
        uint8_t out2          : 1;
        uint8_t loopback_mode : 1;
    } __attribute__((packed));

    uint8_t val;
} uart_16550_mcr_t;

typedef union
{
    struct
    {
        uint8_t data_ready      : 1;
        uint8_t overrun_error   : 1;
        uint8_t parity_error    : 1;
        uint8_t framing_error   : 1;
        uint8_t break_indicator : 1;
        uint8_t txff_empty      : 1;
        uint8_t tx_empty        : 1;
        uint8_t some_error      : 1;
    } __attribute__((packed));

    uint8_t val;
} uart_16550_lsr_t;

typedef union
{
    struct
    {
        uint8_t data_ready    : 1;
        uint8_t overrun_error : 1;
        uint8_t parity_error  : 1;
        uint8_t framing_error : 1;
        uint8_t txff_empty    : 1;
        uint8_t tx_empty      : 1;
        uint8_t some_error    : 1;
    } __attribute__((packed));

    uint8_t val;
} uart_16550_msr_t;

void init_uart_16550(void);