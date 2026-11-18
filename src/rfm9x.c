#include "rfm9x.h"
#include "stm32f446xx.h"
#include "spi.h"
#include "gpio.h"

uint8_t rfm9x_read_register(uint8_t address){

			cs_enable();

			spi_transfer(address & 0x7F); //wait while LoRa module decode what value to send, address phase
			// & 0x7F ensures that we bitmask for reading the register
			uint8_t value= spi_transfer(0x00); //data phase

			while(SPI1->SR & SPI_SR_BSY);
			cs_disable();
			return value;

}


uint8_t rfm9x_write_register(uint8_t address, uint8_t value){

			cs_enable();

			spi_transfer(address | 0x80); //wait while LoRa module decode what value to send, address phase
			// & 0x80 ensures that we bitmask for reading the register as bit[7] has to be 1 for write
			spi_transfer(value); //data phase

			while(SPI1->SR & SPI_SR_BSY);
			cs_disable();
			;

}

