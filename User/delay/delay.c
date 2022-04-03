#include "delay.h"

void delay_us(u32 nus)
{
	 u32 temp;
	 SysTick->LOAD = 9*nus;
	 SysTick->VAL  = 0X00;			//��ռ�������ͬʱ�����־λ
	 SysTick->CTRL = 0X01;			//ʹ�ܣ����������޶����������ⲿʱ��Դ
	 do
	{
		temp = SysTick->CTRL;			//��ȡ��ǰ������־λ
	}while( (temp & 0x01) && (!( temp & (1<<16) )) );	  //�ȴ�ʱ�䵽��
		SysTick->CTRL = 0x00; 														//�رռ�����
		SysTick->VAL  = 0X00; 														//��ռ�������ͬʱ�����־λ
}

void delay_ms(u16 nms)
{
	 u32 temp;
	 SysTick->LOAD = 9000*nms;
	 SysTick->VAL  = 0X00;			//��ռ�������ͬʱ�����־λ
	 SysTick->CTRL = 0X01;			//ʹ�ܣ����������޶����������ⲿʱ��Դ
	 do
	{
		temp = SysTick->CTRL;			//��ȡ��ǰ������־λ
	}while( (temp & 0x01) && (!( temp & (1<<16) )) );	  //�ȴ�ʱ�䵽��
		SysTick->CTRL = 0x00; 														//�رռ�����
		SysTick->VAL  = 0X00; 														//��ռ�������ͬʱ�����־λ
}