#ifndef __EXTI_H
#define	__EXTI_H


#include "stm32f10x.h"


//Òý½Å¶¨Òå



#define KEY2_INT_GPIO_PORT         GPIOC
#define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
#define KEY2_INT_GPIO_PIN          GPIO_Pin_0
#define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
#define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource0
#define KEY2_INT_EXTI_LINE         EXTI_Line0
#define KEY2_INT_EXTI_IRQ          EXTI0_IRQn

#define KEY2_IRQHandler            EXTI10_IRQHandler


#define KEY3_INT_GPIO_PORT         GPIOC
#define KEY3_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
#define KEY3_INT_GPIO_PIN          GPIO_Pin_1
#define KEY3_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
#define KEY3_INT_EXTI_PINSOURCE    GPIO_PinSource1
#define KEY3_INT_EXTI_LINE         EXTI_Line1
#define KEY3_INT_EXTI_IRQ          EXTI1_IRQn

#define KEY3_IRQHandler            EXTI11_IRQHandler



#define KEY4_INT_GPIO_PORT         GPIOA
#define KEY4_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY4_INT_GPIO_PIN          GPIO_Pin_0
#define KEY4_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define KEY4_INT_EXTI_PINSOURCE    GPIO_PinSource0
#define KEY4_INT_EXTI_LINE         EXTI_Line0
#define KEY4_INT_EXTI_IRQ          EXTI0_IRQn

#define KEY4_IRQHandler            EXTI0_IRQHandler



void EXTI_Key_Config(void);


#endif /* __EXTI_H */
