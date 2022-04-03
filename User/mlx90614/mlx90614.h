#ifndef __MLX90614_H
#define __MLX90614_H

#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "bluetooth.h"


#define SUCCESS 1
#define WR   0
#define RD   1
#define ACK	 0
#define	NACK 1               //不应答或否定的应答
#define SA				0x00 //从机地址，单个MLX90614时地址为0x00,多个时地址默认为0x5a
#define RAM_ACCESS		0x00 //RAM access command
#define EEPROM_ACCESS	0x20 //EEPROM access command

#define body            0xf332 //人体发射率0.98


/*RAM寄存器地址*/
#define AMBITEMPADDR    0x03  //周围温度
#define Ta              0x06  //环境温度
#define TOBJ1           0x07  //目标1温度
#define TOBJ2           0x08 //目标2温度

/*EEPROM寄存器地址*/
#define EEPROM_EMI      0x04 //发射率校准地址

/*IIC GPIO引脚配置*/
#define MLX_GPIO_PORT   GPIOC
#define MLX_RCC_PORT    RCC_APB2Periph_GPIOC
#define MLX_SCL         GPIO_Pin_11
#define MLX_SDA         GPIO_Pin_10


#define MLX_SCL_1()	    MLX_GPIO_PORT->BSRR = MLX_SCL
#define MLX_SCL_0()	    MLX_GPIO_PORT->BRR = MLX_SCL
#define MLX_SDA_1()	    MLX_GPIO_PORT->BSRR = MLX_SDA
#define MLX_SDA_0()	    MLX_GPIO_PORT->BRR = MLX_SDA

#define MLX_SDA_READ()  (MLX_GPIO_PORT->IDR & MLX_SDA)  //读SDA数据


/*iic基本操作函数 */
static void i2c_Delay(void); 		//延时函数
void MLX_Start(void);       		//起始信号
void MLX_Stop(void)	;				//停止信号
void MLX_SendByte(uint8_t _ucByte); // 
uint8_t MLX_ReadByte(void);
uint8_t MLX_WaitAck(void) ;        //读取从机应答信号
void MLX_Ack(void);          		//主机产生应答信号
void MLX_NAck(void);				//主机产生非应答信号
void MLX_ConfigGpio(void);          //SCL,SDA引脚配置


/* MLX90614 操作函数 */

uint16_t MLX_RE(u8 Addr,u8 cmd);
u8 PEC_Calculation(u8 pec[]);
uint8_t MLX_WriteEE(u8 Addr,u8 cmd,u8 DL,u8 DH);
void MLX_Init(void); //校准发射率
float MLX_ReadTemp(void);
float MLX_EnvironTemp(void);
float Tbody(void);

void tft_TT_display(void);
#endif /*__MLX90614_H*/




