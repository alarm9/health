#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

/************************************************
*           蓝牙模块配置，USART3				*
*												*
*************************************************/

#include "stm32f10x.h"  // Device header


// 串口3-USART3
#define  BT_USART                    	 USART3
#define  BT_USART_CLK               	 RCC_APB1Periph_USART3
#define  BT_USART_APBxClkCmd        	 RCC_APB1PeriphClockCmd
#define  BT_USART_BAUDRATE          	 115200

// USART GPIO 引脚宏定义
#define  BT_USART_GPIO_CLK           	 RCC_APB2Periph_GPIOB
#define  BT_USART_GPIO_APBxClkCmd    	 RCC_APB2PeriphClockCmd
    
#define  BT_USART_TX_GPIO_PORT       	 GPIOB   
#define  BT_USART_TX_GPIO_PIN        	 GPIO_Pin_10

#define  BT_USART_RX_GPIO_PORT       	 GPIOB
#define  BT_USART_RX_GPIO_PIN            GPIO_Pin_11

#define  BT_USART_IRQ                  	 USART3_IRQn   //USART3 中断源
#define  BT_USART_IRQHandler         	 USART3_IRQHandler //USART3 中断函数名

#define  BT_PWRC_GPIO_PORT               GPIOB
#define  BT_PWRC_CLK                     RCC_APB2Periph_GPIOB
#define  BT_PWRC_PIN					 GPIO_Pin_1


#define  BT_STATE_GPIO_PORT               GPIOB
#define  BT_STATE_CLK                     RCC_APB2Periph_GPIOB
#define  BT_STATE_PIN					  GPIO_Pin_12
#define  BT_STATE_READ   				  GPIO_ReadInputDataBit(BT_STATE_GPIO_PORT ,BT_STATE_PIN)


static void NVIC_Configuration(void);
void BT_check(void);
void BT_GPIO_Config(void);
void BT_SendString( u8 *str);

#endif /*__BLUETOOTH_H*/
