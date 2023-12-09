// contains the addresses of all memory mapped peripherals

#define PERIPH_BASE_ADDR 0xA0000000

// RISCV TIMER
#define REG_MTIME (((volatile uint32_t *) (PERIPH_BASE_ADDR + 0 * 4) ))
#define REG_MTIMEH (((volatile uint32_t *) (PERIPH_BASE_ADDR + 1 * 4)))

#define REG_MTIMECMP (((volatile uint32_t *) (PERIPH_BASE_ADDR + 2 * 4) ))
#define REG_MTIMECMPH (((volatile uint32_t *) (PERIPH_BASE_ADDR + 3 * 4)))