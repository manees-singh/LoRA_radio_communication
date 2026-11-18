#include "gpio.h"
#include "stm32f446xx.h"


void gpio_config(){
	//enable clock for peripheral pins, ahb1 for gpioA port
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN ;

	//set alternate mode for pin PA5/6/7
	GPIOA->MODER &= ~(3U<<10);
	GPIOA->MODER |= (2U<<10);

	GPIOA->MODER &= ~(3U<<12);
	GPIOA->MODER |= (2U<<12);

	GPIOA->MODER &= ~(3U<<14);
	GPIOA->MODER |= (2U<<14);

	GPIOA->MODER &= ~(3U<<18); // this is for the chip select
	GPIOA->MODER |=(1U<<18);

	//set the speed of transition for the pins, this controls the sharpness of high-low transition on pins
	GPIOA->OSPEEDR &= ~(3U<<10);
	GPIOA->OSPEEDR |= (3U<<10);

	GPIOA->OSPEEDR &= ~(3U<<12);
	GPIOA->OSPEEDR |= (3U<<12);

	GPIOA->OSPEEDR &= ~(3U<<14);
	GPIOA->OSPEEDR |= (3U<<14);

	GPIOA->OSPEEDR &= ~(3U<<18);
	GPIOA->OSPEEDR |= (3U<<18);

	//selecting the alternate functions, for our MCU, use AFRL part of the data sheet
	GPIOA->AFR[0] &= ~(0xFU<<20);
	GPIOA->AFR[0] |= (5U<<20);

	GPIOA->AFR[0] &= ~(0xFU<<24);
	GPIOA->AFR[0] |= (5U<<24);

	GPIOA->AFR[0] &= ~(0xFU<<28);
	GPIOA->AFR[0] |= (5U<<28);
}

void cs_enable(){
	GPIOA->BSRR = (1U<<25);
	 //because setting low to the pin selects the slave
}

void cs_disable(){
	GPIOA->BSRR = (1U<<9);
}

