// Sifive compatible CLINT

#define CLINT_BASE_ADDR  0xA0000000

#define MSIP_OFFSET ((0))
#define MTIMECMP_OFFSET ((0x4000))
#define MTIMECMPH_OFFSET ((0x4004))
#define MTIME_OFFSET ((0xBFF8))
#define MTIMEH_OFFSET ((0xBFFC))

#define REG_MSIP (((volatile uint32_t *) (CLINT_BASE_ADDR + MSIP_OFFSET)))

#define REG_MTIME (((volatile uint32_t *) (CLINT_BASE_ADDR + MTIME_OFFSET)))
#define REG_MTIMEH (((volatile uint32_t *) (CLINT_BASE_ADDR + MTIMEH_OFFSET)))

#define REG_MTIMECMP (((volatile uint32_t *) (CLINT_BASE_ADDR + MTIMECMP_OFFSET) ))
#define REG_MTIMECMPH (((volatile uint32_t *) (CLINT_BASE_ADDR + MTIMECMPH_OFFSET)))
