#include "spi.h"
#include "stm32f446xx.h"


void spi_config(){
	//enable clock that is connected to spi1
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;


	//configure your spi1 CPOL & CPHA, for LoRA it's mode 0
	SPI1->CR1 &= ~(SPI_CR1_CPHA  | SPI_CR1_CPOL);

	//configure whether master or slave
	SPI1->CR1 |= SPI_CR1_MSTR;

	//Baud rate configuration
	SPI1->CR1 &= ~(SPI_CR1_BR);
	SPI1->CR1 |= (3U<<3);

	//MSB or LSB, MSB for LoRA
	SPI1->CR1 &= ~(SPI_CR1_LSBFIRST);

	//setting software controlled ssm
	SPI1->CR1 |= (SPI_CR1_SSM | SPI_CR1_SSI);

	//setting up the full duplex mode
	SPI1->CR1 &= ~(SPI_CR1_RXONLY);

	//we set data to be sent as format for 1 byte
	SPI1->CR1 &= ~(SPI_CR1_DFF );

	//setting CR2
	SPI1->CR2 = 0;

}


void spi_enable(){
	SPI1->CR1 |= SPI_CR1_SPE;
}

void spi_disable(){
	SPI1->CR1 &= ~(SPI_CR1_SPE);
}

uint8_t spi_transfer(uint8_t data){
	//wait while transmit buffer is empty
	while(!(SPI1->SR & SPI_SR_TXE)); //txe = transmit buffer empty


	*(volatile uint8_t*)&SPI1->DR= data;
	while(!(SPI1->SR & SPI_SR_RXNE)); //rxne = receive buffer not empty
	return *(volatile uint8_t*)&SPI1->DR;

}

