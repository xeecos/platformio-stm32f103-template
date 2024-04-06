#include "delay.h"
#include "stm32f10x.h"
#include "usart.h"
int main()
{
    SystemCoreClockUpdate();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  
    GPIO_InitTypeDef GPIO_InitStruct;  
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;  
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
    GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);

    Delay_Init();
    Usart_Init(115200);

    while (1) 
    {
        GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_SET);
        Delay_Ms(1000);
        GPIO_WriteBit(GPIOA, GPIO_Pin_4, Bit_RESET);
        Delay_Ms(1000);
    }
}