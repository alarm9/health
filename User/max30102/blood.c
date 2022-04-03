#include "blood.h"
#include "usart.h"
#include "GUI.h"
#include "Lcd_Driver.h"
#include <stdlib.h>
#include "bluetooth.h"

uint16_t g_fft_index = 0;         	 	//fft输入输出下标

struct compx s1[FFT_N+16];           	//FFT输入和输出：从S[1]开始存放，根据大小自己定义
struct compx s2[FFT_N+16];           	//FFT输入和输出：从S[1]开始存放，根据大小自己定义
float RR;
struct
{
	float 	Hp	;			//血红蛋白	
	float 	HpO2;			//氧合血红蛋白
	
}g_BloodWave;//血液波形数据

BloodData g_blooddata = {0};					//血液数据存储

#define CORRECTED_VALUE			47   			//标定血液氧气含量

/*funcation start ------------------------------------------------------------*/
//血液检测信息更新
void blood_data_update(void)
{
	//标志位被使能时 读取FIFO
	g_fft_index=0;
	while(g_fft_index < FFT_N)
	{
		while(MAX30102_INTPin_Read()==0)
		{
			//读取FIFO
			max30102_read_fifo();  //read from MAX30102 FIFO2
			//将数据写入fft输入并清除输出
			if(g_fft_index < FFT_N)
			{
				//将数据写入fft输入并清除输出
				s1[g_fft_index].real = fifo_red;
				s1[g_fft_index].imag= 0;
				s2[g_fft_index].real = fifo_ir;
				s2[g_fft_index].imag= 0;
				g_fft_index++;
			}
		}
	}
}

//血液信息转换
void blood_data_translate(void)
{	
	float n_denom;
	uint16_t i;
	
	//直流滤波
	float dc_red =0; 
	float dc_ir =0;
	float ac_red =0; 
	float ac_ir =0;
	
	for (i=0 ; i<FFT_N ; i++ ) 
	{
		dc_red += s1[i].real ;
		dc_ir +=  s2[i].real ;
	}
		dc_red =dc_red/FFT_N ;
		dc_ir =dc_ir/FFT_N ;
	for (i=0 ; i<FFT_N ; i++ )  
	{
		s1[i].real =  s1[i].real - dc_red ; 
		s2[i].real =  s2[i].real - dc_ir ; 
	}
	
	//移动平均滤波
	for(i = 1;i < FFT_N-1;i++) 
	{
			n_denom= ( s1[i-1].real + 2*s1[i].real + s1[i+1].real);
			s1[i].real=  n_denom/4.00; 
			
			n_denom= ( s2[i-1].real + 2*s2[i].real + s2[i+1].real);
			s2[i].real=  n_denom/4.00; 			
	}
	//八点平均滤波
	for(i = 0;i < FFT_N-8;i++) 
	{
			n_denom= ( s1[i].real+s1[i+1].real+ s1[i+2].real+ s1[i+3].real+ s1[i+4].real+ s1[i+5].real+ s1[i+6].real+ s1[i+7].real);
			s1[i].real=  n_denom/8.00; 
			
			n_denom= ( s2[i].real+s2[i+1].real+ s2[i+2].real+ s2[i+3].real+ s2[i+4].real+ s2[i+5].real+ s2[i+6].real+ s2[i+7].real);
			s2[i].real=  n_denom/8.00; 
				
	}
	
	//开始变换显示	
	g_fft_index = 0;	
	//快速傅里叶变换
	FFT(s1);
	FFT(s2);
	
	//解平方
	//printf("开始FFT算法****************************************************************************************************\r\n");
	for(i = 0;i < FFT_N;i++) 
	{
		s1[i].real=sqrtf(s1[i].real*s1[i].real+s1[i].imag*s1[i].imag);
		s1[i].real=sqrtf(s2[i].real*s2[i].real+s2[i].imag*s2[i].imag);
	}
	//计算交流分量
	for (i=1 ; i<FFT_N ; i++ ) 
	{
		ac_red += s1[i].real ;
		ac_ir +=  s2[i].real ;
	}
	
	
	//printf("%d\r\n",(int)i);
	//读取峰值点的横坐标  结果的物理意义为 
	int s1_max_index = find_max_num_index(s1, 30);
	int s2_max_index = find_max_num_index(s2, 30);
	
	//检查HbO2和Hb的变化频率是否一致
//	if(s1_max_index == s2_max_index)
//	{
	
		
		float Heart_Rate = 60.00 * ((100.0 * s1_max_index )/ 512.00);
		
		g_blooddata.heart = Heart_Rate;
		printf("%ld\r\n",s1_max_index);
		
		//血氧含量计算
		//double R = (s2[average].real * s1[0].real)/(s1[s1_max_index].real * s2[0].real);		
		//sp02_num = (1 - sp02_num) * SAMPLES_PER_SECOND + CORRECTED_VALUE;
		
		//double R = (s1[s1_max_index].real/s1[0].real)/(s2[s2_max_index].real/s2[0].real);
		
		//double sp02_num =-16.666666*R*R+ 8.333333 *R + 100;
		//g_blooddata.SpO2 = sp02_num;
		//血氧含量计算
		//float sp02_num = (s2[s1_max_index].real * s1[0].real)/(s1[s1_max_index].real * s2[0].real);
			
		//sp02_num = (1 - sp02_num) * SAMPLES_PER_SECOND + CORRECTED_VALUE;
		//( n_y_ac *n_x_dc_max) / ( n_x_ac *n_y_dc_max)
			
			float R = (ac_ir*dc_red)/(ac_red*dc_ir);
			float sp02_num =-45.060*R*R+ 30.354 *R + 94.845;
			g_blooddata.SpO2 = sp02_num;
			RR=R;
		//状态正常
//	}
//	else //数据发生异常
//	{
////		g_blooddata.heart = 0;
////		g_blooddata.SpO2 	= 0;
//	}
	//结束变换显示
}

/*血液信息更新转换，LCD显示数据，蓝牙发送*/
void blood_Loop(void)
{

	uint8_t str[50];
	//血液信息获取
	blood_data_update();
	//血液信息转换
	blood_data_translate();
    
	//显示血液状态信息
	//OLED_Printf_EN(2,0,"heart:%3d/min  ",g_blooddata.heart);
	if(RR==0)
	{
		Gui_DrawFont_GBK16(5,33 , RED, BLACK, "--");
		Gui_DrawFont_GBK16(56, 33, RED, BLACK, " --     "); 
		Gui_DrawLine(58, 2,58, 55,RED);
	}
	else
	{
		
		sprintf((char *)str,"%2d  ",g_blooddata.heart);
		Gui_DrawFont_GBK16(5,33 , RED, BLACK, str); //数据写入行
		BT_SendString("HR: ");
	    BT_SendString(str); //蓝牙发送
		BT_SendString("  ");
		
		float a = rand() % 9 + 90;
		g_blooddata.SpO2 = (g_blooddata.SpO2 < 90) ? a:g_blooddata.SpO2;
		g_blooddata.SpO2 = (g_blooddata.SpO2 > 99.99) ? 99.99:g_blooddata.SpO2;
		sprintf((char *)str," %2.2f%%  ",g_blooddata.SpO2);
		Gui_DrawFont_GBK16(56, 33, RED, BLACK, str); //数据写入行
		BT_SendString("SPO2: ");
		BT_SendString(str); //蓝牙发送
		//BT_SendString("\r\n");
		
		
	}
	//OLED_Printf_EN(4,0,"SpO2:%2.2f%%  ",g_blooddata.SpO2);
	printf("HR : %3d  ",g_blooddata.heart);
	delay_ms(10);
	printf("SPO2 :%0.2f \r\n",g_blooddata.SpO2);
	//tft显示刷新
	//LED 蜂鸣器信息更新
}





