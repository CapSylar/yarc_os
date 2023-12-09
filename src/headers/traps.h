#ifndef TRAPS_H_GUARD
#define TRAPS_H_GUARD

#include "master_include.h"

typedef void (*irq_handler)(void);

void trap_table(void) __attribute__((naked, aligned(16), used));

void exception_handler(void) __attribute__((interrupt(), used));
void software_handler(void) __attribute__((interrupt(), used));
void timer_handler(void) __attribute__((interrupt(), used));
void external_handler(void) __attribute__((interrupt(), used));

void register_irq_handler (uint32_t interrupt_num, irq_handler handler);

#define SOFTWARE_IRQ_INT 3
#define TIMER_IRQ_INT 7
#define EXTERNAL_IRQ_INT 11

#endif // TRAPS_H_GUARD