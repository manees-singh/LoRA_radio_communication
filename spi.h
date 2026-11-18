#ifndef SPI_H
#define SPI_H

#include <stdint.h>


void spi_config();
void spi_enable();
void spi_disable();
uint8_t spi_transfer(uint8_t data);

#endif
