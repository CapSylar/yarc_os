#include "master_include.h"

irq_handler irq_handlers[16];

void trap_table(void)
{
  asm volatile(".org trap_table + 0 * 4;"
               "j exception_handler;"
               ".org trap_table + %0 * 4;"
               "j software_handler;"
               ".org trap_table + %1 * 4;"
               "j timer_handler;"
               ".org trap_table + %2 * 4;"
               "j external_handler;"
               :
               : "I"(SOFTWARE_IRQ_INT), "I"(TIMER_IRQ_INT),
                 "I"(EXTERNAL_IRQ_INT));
}

void exception_handler(void) {}

void software_handler(void) {}

void timer_handler(void)
{
  if (irq_handlers[TIMER_IRQ_INT])
    irq_handlers[TIMER_IRQ_INT]();
}

void external_handler(void) {}

void register_irq_handler(uint32_t interrupt_num, irq_handler handler)
{
  if (interrupt_num >= 16)
    return;

  irq_handlers[interrupt_num] = handler;
}