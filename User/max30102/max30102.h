#ifndef _MAX_H
#define _MAX_H
#include "stm32f10x.h"                  // Device header
#include "delay.h"
#include "stdbool.h"
#define MAX30102_Device_address 			0xAE

//register addresses
#define REG_INTR_STATUS_1 			0x00
#define REG_INTR_STATUS_2 		 	0x01
#define REG_INTR_ENABLE_1 			0x02
#define REG_INTR_ENABLE_2 			0x03
#define REG_FIFO_WR_PTR 			0x04
#define REG_OVF_COUNTER 			0x05
#define REG_FIFO_RD_PTR 			0x06
#define REG_FIFO_DATA 				0x07
#define REG_FIFO_CONFIG 			0x08
#define REG_MODE_CONFIG 			0x09
#define REG_SPO2_CONFIG 			0x0A
#define REG_LED1_PA 				0x0C
#define REG_LED2_PA 				0x0D
#define REG_PILOT_PA 				0x10
#define REG_MULTI_LED_CTRL1 		0x11
#define REG_MULTI_LED_CTRL2 		0x12
#define REG_TEMP_INTR 				0x1F
#define REG_TEMP_FRAC 				0x20
#define REG_TEMP_CONFIG 			0x21
#define REG_PROX_INT_THRESH		 	0x30
#define REG_REV_ID 					0xFE
#define REG_PART_ID 				0xFF

#define MAX30102_INTPin_CLK 						RCC_APB2Periph_GPIOC
#define MAX30102_INTPin_PORT 						GPIOC
#define MAX30102_INTPin_Pin 						GPIO_Pin_7
#define MAX30102_INTPin_Read() 					GPIO_ReadInputDataBit(MAX30102_INTPin_PORT,MAX30102_INTPin_Pin)

#define Led_CLK 						RCC_APB2Periph_GPIOC
#define Led_PORT 						GPIOC
#define Led_Pin 						GPIO_Pin_9

#define SAMPLES_PER_SECOND 					100	//检测频率





#define MAX_SCL_CLK 						RCC_APB2Periph_GPIOC
#define MAX_SCL_PORT 						GPIOC
#define MAX_SCL_GPIO_Pin 				GPIO_Pin_6
#define MAX_SDA_CLK 						RCC_APB2Periph_GPIOB
#define MAX_SDA_PORT 						GPIOB
#define MAX_SDA_GPIO_Pin 				GPIO_Pin_15

#define MAX_SCL_1 			GPIO_SetBits(MAX_SCL_PORT,MAX_SCL_GPIO_Pin)
#define MAX_SCL_0 			GPIO_ResetBits(MAX_SCL_PORT,MAX_SCL_GPIO_Pin)
#define MAX_SDA_1 			GPIO_SetBits(MAX_SDA_PORT,MAX_SDA_GPIO_Pin)
#define MAX_SDA_0 			GPIO_ResetBits(MAX_SDA_PORT,MAX_SDA_GPIO_Pin)
#define	MAX_SDA_READ		GPIO_ReadInputDataBit(MAX_SDA_PORT,MAX_SDA_GPIO_Pin)


/*MAX30102 IIC基础通信函数 */
void MAX_GPIO_INIT(void); //GPIO初始化
void MAX_Start(void); //起始信号
void MAX_Stop(void); //停止信号
void MAX_Send_Byte(uint8_t byte);  //发送一个字节
void I2C_Ack(uint8_t a);  //发送应答信号/非应答
uint8_t MAX_Receive_Byte(void); //接收一个字节


uint8_t MAX_Read_Byte(uint8_t device_addr,uint8_t register_addr); //读取一个字节数据
uint8_t MAX_Write_Byte(uint8_t device_addr,uint8_t register_addr,uint8_t data); //写一个字节数据


uint8_t MAX_Read_Array(uint8_t device_addr,u16 register_addr,uint8_t *Data,u16 Num); //读数组
uint8_t MAX_Write_Array(uint8_t device_addr,u16 register_addr,u8 *Data,u16 Num); //写数组

extern uint8_t ack; //应答信号


extern uint16_t fifo_red;
extern uint16_t fifo_ir;


uint8_t Max30102_reset(void);
void MAX30102_Config(void);
void max30102_read_fifo(void);




#endif

