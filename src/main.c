#include "stm32g4xx.h"
int main(void)
{
    RCC->AHB2ENR |= 0x01; // enable Port A
    GPIOA->MODER &= ~0x0C00; GPIOA->MODER |= 0x0400; // PA5 output

    while(1)
    {
        GPIOA->ODR |= 0x20;
        for(unsigned int timer = 0; timer < 2000000; ++timer);
        GPIOA->ODR &= ~0x20;
        for(unsigned int timer = 0; timer < 2000000; ++timer);
    }
}
