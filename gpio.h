#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include <stm32f446xx.h>

void gpio_config();
void cs_enable();
void cs_disable();

#endif
