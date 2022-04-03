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
#define	NACK 1               //��Ӧ���񶨵�Ӧ��
#define SA				0x00 //�ӻ���ַ������MLX90614ʱ��ַΪ0x00,���ʱ��ַĬ��Ϊ0x5a
#define RAM_ACCESS		0x00 //RAM access command
#define EEPROM_ACCESS	0x20 //EEPROM access command

#define body            0xf332 //���巢����0.98


/*RAM�Ĵ�����ַ*/
#define AMBITEMPADDR    0x03  //��Χ�¶�
#define Ta              0x06  //�����¶�
#define TOBJ1           0x07  //Ŀ��1�¶�
#define TOBJ2           0x08 //Ŀ��2�¶�

/*EEPROM�Ĵ�����ַ*/
#define EEPROM_EMI      0x04 //������У׼��ַ

/*IIC GPIO��������*/
#define MLX_GPIO_PORT   GPIOC
#define MLX_RCC_PORT    RCC_APB2Periph_GPIOC
#define MLX_SCL         GPIO_Pin_11
#define MLX_SDA         GPIO_Pin_10


#define MLX_SCL_1()	    MLX_GPIO_PORT->BSRR = MLX_SCL
#define MLX_SCL_0()	    MLX_GPIO_PORT->BRR = MLX_SCL
#define MLX_SDA_1()	    MLX_GPIO_PORT->BSRR = MLX_SDA
#define MLX_SDA_0()	    MLX_GPIO_PORT->BRR = MLX_SDA

#define MLX_SDA_READ()  (MLX_GPIO_PORT->IDR & MLX_SDA)  //��SDA����


/*iic������������ */
static void i2c_Delay(void); 		//��ʱ����
void MLX_Start(void);       		//��ʼ�ź�
void MLX_Stop(void)	;				//ֹͣ�ź�
void MLX_SendByte(uint8_t _ucByte); // 
uint8_t MLX_ReadByte(void);
uint8_t MLX_WaitAck(void) ;        //��ȡ�ӻ�Ӧ���ź�
void MLX_Ack(void);          		//��������Ӧ���ź�
void MLX_NAck(void);				//����������Ӧ���ź�
void MLX_ConfigGpio(void);          //SCL,SDA��������


/* MLX90614 �������� */

uint16_t MLX_RE(u8 Addr,u8 cmd);
u8 PEC_Calculation(u8 pec[]);
uint8_t MLX_WriteEE(u8 Addr,u8 cmd,u8 DL,u8 DH);
void MLX_Init(void); //У׼������
float MLX_ReadTemp(void);
float MLX_EnvironTemp(void);
float Tbody(void);

void tft_TT_display(void);
#endif /*__MLX90614_H*/




