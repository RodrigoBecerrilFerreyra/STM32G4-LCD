#include <stdint.h>
#include <stdbool.h>
#include "stm32g4xx.h"
int main(void)
{
    RCC->AHB2ENR |= 0x02; // enable Port B
    GPIOB->MODER &= ~0x00000003; GPIOB->MODER |= 0x00000001; // PB0 output

    while(1)
    {
        GPIOB->ODR |= 0x01;
        for(unsigned int timer = 0; timer < 2000000; ++timer);
        GPIOB->ODR &= ~0x01;
        for(unsigned int timer = 0; timer < 2000000; ++timer);
    }
}
