#include "stm32g4xx.h"

void initialize_gpio(void);
void initialize_spi(void);

int main(void)
{
    initialize_gpio();
    initialize_spi();

    while(1)
    {
        GPIOA->ODR |= 0x20;
        for(unsigned int timer = 0; timer < 2000000; ++timer);
        GPIOA->ODR &= ~0x20;
        for(unsigned int timer = 0; timer < 2000000; ++timer);
    }
}

void initialize_gpio(void)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; // enable Port A
    GPIOA->MODER &= ~GPIO_MODER_MODE5_Msk; GPIOA->MODER |= GPIO_MODER_MODE5_0; // PA5 output
}

void initialize_spi(void)
{
    
}
