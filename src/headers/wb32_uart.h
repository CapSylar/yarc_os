#pragma once

// for further reference
// https://github.com/ZipCPU/wbuart32/blob/master/doc/spec.pdf

#include <stdint.h>
typedef union
{
    struct
    {
        uint32_t baud_clks: 23;
        uint32_t parity_settings: 3;
        uint32_t parity_used: 1;
        uint32_t stop_bit: 1;
        uint32_t num_bits: 2;
        uint32_t disable_hw_flow_ctrl: 1;
        uint32_t unused: 1;
    } __attribute__((packed));

    uint32_t val;
} uart_setup_t;

// RO (Read Only) Register
typedef union
{
    struct
    {
        uint32_t rx_one : 1; // at least one value in there to be read
        uint32_t rx_fill_high : 1; // high order fill of rx
        uint32_t rx_fill : 10; // number of valid data in rx fifo
        uint32_t rx_fifo_size_log: 4; // log rx fifo size

        uint32_t tx_one: 1; // at least one available space to write into
        uint32_t tx_fill_high: 1; // high order fill of tx
        uint32_t tx_fill : 10; // number of available space in tx fifo
        uint32_t tx_fifo_len_log: 4; // log tx fifo size
    } __attribute__((packed));

    uint32_t val;
} uart_fifo_t;

// writing 1 to the error bits will clear them
typedef union
{
    struct
    {
        uint32_t rx_word: 8; // contains the received word
        uint32_t empty: 1; // if 0, rx_word contains something
        uint32_t parity_error: 1; // a parity error has occured
        uint32_t frame_error: 1; // a frame error has occured
        uint32_t rx_line_in_break: 1;
        uint32_t rx_ff_overflow: 1; // fifo has overflown since the last reset
        uint32_t zero: 19; // zero padding
    } __attribute__((packed));

    uint32_t val;
} uart_rx_data_t;

typedef union
{
    struct
    {
        uint32_t tx_word: 8; // contains the received word
        uint32_t tx_busy: 1; // if one, the transmitter is currently busy
        uint32_t transmit_break: 1; // when set, transmits a break condition
        uint32_t tx_line_state: 1;
        uint32_t rx_line_state: 1;
        uint32_t tx_fifo_overflow: 1;
        uint32_t tx_one: 1; // at least one space in tx fifo
        uint32_t tx_fill_high: 1; // high order fill of tx fifo
        uint32_t rts_line_state: 1; // state of the RTS line
        uint32_t zero: 16;
    } __attribute__((packed));

    uint32_t val;
} uart_tx_data_t;

typedef struct
{
    uart_setup_t setup_reg;
    uart_fifo_t fifo_reg;
    uart_rx_data_t rx_data_reg;
    uart_tx_data_t tx_data_reg;

} __attribute__((packed)) device_uart_t;

void init_uart_16550();