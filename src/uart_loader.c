#include "console.h"
#include "master_include.h"
#include "printf.h"
#include <stdint.h>

static uint32_t read_4_bytes();

void uart_loader(void) {

    // load the program coming in via uart

    // the stream should be formatted as follows:
    // 4 bytes: IMEM byte address lsbfirst
    // 4 bytes: IMEM length in bytes lsbfirst
    // the IMEM content

    // 4 bytes: DMEM byte address lsbfirst
    // 4 bytes: DMEM length in bytes lsbfirst
    // the DMEM content

    uint32_t imem_address = read_4_bytes();
    uint32_t imem_length = read_4_bytes();

    // store the incoming imem bytes
    volatile uint8_t *imem_ptr = (void *) imem_address;

    while (imem_ptr < (uint8_t *) (imem_address + imem_length)) {
        *imem_ptr++ = console_getc();
    }

    uint32_t dmem_address = read_4_bytes();
    uint32_t dmem_length = read_4_bytes();

    // store the incoming dmem bytes
    volatile uint8_t *dmem_ptr = (void *) dmem_address;

    while (dmem_ptr < (uint8_t *) (dmem_address + dmem_length)) {
        *dmem_ptr++ = console_getc();
    }

    // printf("Written %d bytes at address %x\n", imem_length, imem_address);
    // printf("Written %d bytes at address %x\n", dmem_length, dmem_address);

    // printf("first 16 bytes of the loaded imem image:\n");
    // for (size_t i = 0 ;i < 16; ++i) {
    //     printf("0x%02x ", imem_ptr[i]);
    // }
    // printf("\n");

    // printf("last 16 bytes of the loaded imem image: \n");

    // for (size_t i = imem_length - 16; i < imem_length; ++i) {
    //     printf("0x%02x ", imem_ptr[i]);
    // }
    // printf("\n");

    // printf("first 16 bytes of the loaded dmem image:\n");
    // for (size_t i = 0 ;i < 16; ++i) {
    //     printf("0x%02x ", dmem_ptr[i]);
    // }
    // printf("\n");

    // printf("last 16 bytes of the loaded dmem image: \n");

    // for (size_t i = dmem_length - 16; i < dmem_length; ++i) {
    //     printf("0x%02x ", dmem_ptr[i]);
    // }
    printf("\n");

    printf("jumping to address: 0x%x", imem_address);
    __attribute__((noreturn)) void (* goodbye)(void) = (void *) imem_address;

    goodbye(); // jump to loaded program
}

// read 4 bytes from the uart stream lbsfirst
static uint32_t read_4_bytes(void) {

    uint32_t read = 0;
    for (size_t i = 0; i < 4; ++i) {
        read = read | (console_getc() << (8*i));
        device_led->led_state++;
    }

    return read;
}