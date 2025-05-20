#include "debug.h"

void debug_init(void) {
    // Configure UART GPIO
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
    GPIOD->MODER |= (GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1);
    GPIOD->AFR[1] |= (7 | (7 << 4));

    // Configure UART
    RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    USART3->BRR = 16000000 / 115200;
    USART3->CR1 = (USART_CR1_MME | USART_CR1_RE | USART_CR1_TE | USART_CR1_UE);
}

void debug_write(char* msg, size_t len) {
    while (len-- > 0) {
        USART3->TDR = *msg++;
        while (!(USART3->ISR & USART_ISR_TXE));
    }
}

int _write(int fd, char *ptr, int len) {
    if (fd == 1) {
        debug_write(ptr, len);
    }
    return -1;
}