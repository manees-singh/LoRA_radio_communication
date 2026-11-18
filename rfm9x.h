#ifndef RFM9X_H
#define RFM9X_H

#include <stdint.h>
#define RFM9X_REG_VERSION 0x42

uint8_t rfm9x_read_register(uint8_t address);
uint8_t rfm9x_write_register(uint8_t address, uint8_t value);



#endif
