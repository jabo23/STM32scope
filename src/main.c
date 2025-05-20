#include "stm32f7xx.h"
#include "debug.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int main (void) {

    // Config timer
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    TIM2->PSC = 15999;
    TIM2->ARR = 999;
    TIM2->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM2_IRQn);
    TIM2->CR1 |= TIM_CR1_CEN;

    // Confing user LEDS
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    GPIOB->MODER |= (GPIO_MODER_MODER0_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER14_0);

    debug_init();

    while (1) {

    }

    return 0;
}

uint16_t seconds = 0;

void TIM2_IRQHandler(void) {
    GPIOB->ODR ^= GPIO_ODR_ODR_7;
    printf("Time elapsed: %d minutes, %d seconds\r\n", seconds / 60, seconds % 60);
    printf("Date: %d\r\n", (int) RTC->DR);
    printf("Time: %d\r\n", (int) RTC->TR);
    TIM2->SR &= ~TIM_SR_UIF;
    seconds++;
}