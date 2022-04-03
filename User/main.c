#include "stm32f10x.h"                  // Device header
#include "usart.h"
#include "mlx90614.h"
#include "delay.h"
#include "max30102.h"
#include "algorithm.h"
#include "blood.h"
#include "Lcd_Driver.h"
#include "GUI.h"
#include "led.h"


int main(void)
{
	
	
	

	u8 i;
//	u8 data[6];
	USART_Config();
	Lcd_Init();
	LCD_LED_SET;//通过IO控制背光亮
	printf("这是串口调试助手\r\n");
	MLX_ConfigGpio();
	//MLX_Init();

	LED_GPIO_Config();
		
	BT_GPIO_Config();
	
	MAX_GPIO_INIT();
	Max30102_reset();
	MAX30102_Config();
	
	Lcd_Clear(BLACK);
	tft_draw_frame();
	
	
	
	for(i = 0;i < 128;i++) 
	{
		while(MAX30102_INTPin_Read()==0)
		{
			//读取FIFO
		
			max30102_read_fifo();
		}
	}
	
	
	while(1)
	{	
		BT_check();
		 blood_Loop();
		tft_TT_display();
		printf("%f",Tbody());
		
	}

	
}
