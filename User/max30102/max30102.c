#include "max30102.h"
#include "delay.h"
#include "usart.h"
uint16_t fifo_red;
uint16_t fifo_ir;


uint8_t ack;

void MAX_GPIO_INIT(void)
{

	RCC_APB2PeriphClockCmd(MAX_SCL_CLK | MAX_SDA_CLK | MAX30102_INTPin_CLK,ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode	=	GPIO_Mode_Out_OD ;
	GPIO_InitStruct.GPIO_Pin	=	MAX_SCL_GPIO_Pin;
	GPIO_InitStruct.GPIO_Speed	=	GPIO_Speed_50MHz;
	GPIO_Init(MAX_SCL_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin	=	MAX_SDA_GPIO_Pin;
	GPIO_Init(MAX_SDA_PORT,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode	=	GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin	=	MAX30102_INTPin_Pin;
	GPIO_Init(MAX30102_INTPin_PORT,&GPIO_InitStruct);

}




void MAX_Delay(void)
{
	uint8_t i=6; //i=10延时1.5us//这里可以优化速度 ，经测试最低到5还能写入
   while(i--);
}


void MAX_Start(void)
{
	MAX_SCL_1;
	MAX_SDA_1;//启始信号建立时间 0.6us 400KHz
	MAX_Delay();
	MAX_SDA_0;
	MAX_Delay();//启始信号保持时间0.6us
	MAX_SCL_0;
	MAX_Delay();//时钟低电平时间1.3us
}
 
void MAX_Stop(void)
{	
	MAX_SDA_0;
	MAX_SCL_1;
	MAX_Delay();//结束信号建立时间0.6us
	MAX_SDA_1;
	MAX_Delay();//总线空闲时间时间1.3us
}

void MAX_Send_Byte(uint8_t byte)
{
	uint8_t i;//先发送高位
	for(i=0;i<8;i++)
	{
		if(byte & 0x80)
		{
			MAX_SDA_1;
		}
		else
		{
			MAX_SDA_0;
		}
		MAX_Delay();
		MAX_SCL_1;
		MAX_Delay();
		MAX_SCL_0;
		MAX_Delay();
		byte<<=1;
	}
	MAX_SDA_1;  
	MAX_Delay();
	MAX_SCL_1;
	MAX_Delay();
	if(MAX_SDA_READ)
	{
		ack=1;
	}
	else
	{
		ack=0;
	}
	MAX_SCL_0;
	MAX_Delay();
}

uint8_t MAX_Receive_Byte(void)
{
   uint8_t receive=0;
   uint8_t i;//置数据线为输入方式
   for(i=0;i<8;i++)
   {     		
			receive<<=1;
			MAX_SCL_1;//置时钟线为高使数据线上数据有效
			MAX_Delay();
			if(MAX_SDA_READ)
			{
				receive++;//读数据位,接收的数据位放入retc中
			}
			MAX_SCL_0;  
			MAX_Delay();
   }
   return receive;
}

uint8_t MAX_Write_Byte(uint8_t device_addr,uint8_t register_addr,uint8_t data)
{
	MAX_Start();
	MAX_Send_Byte(device_addr+0);
	if (ack == 1)return 0;
	MAX_Send_Byte(register_addr);   
	if (ack == 1)return 0;
	MAX_Send_Byte(data);
	if (ack == 1)return 0; 
	MAX_Stop();
	return 1;
}

void I2C_Ack(uint8_t a)
{ 
	if(a)
	{
		MAX_SDA_1;            //非应答
		MAX_Delay(); 
		MAX_SCL_1;  	
		MAX_Delay();  
		MAX_SCL_0; 	
		MAX_Delay();  		
	}
	else
	{
		MAX_SDA_0; 						//应答
		MAX_Delay(); 
		MAX_SCL_1;  
		MAX_Delay(); 
		MAX_SCL_0; 
		MAX_Delay(); 
		MAX_SDA_1; 
	}
}

uint8_t MAX_Read_Byte(uint8_t device_addr,uint8_t register_addr)
{
	uint8_t read_data;
	MAX_Start();
	MAX_Send_Byte(device_addr+0);
	if (ack == 1)return 0;
	MAX_Send_Byte(register_addr);
	if (ack == 1)return 0;
	MAX_Start();
	MAX_Send_Byte(device_addr+1);
	if (ack == 1)return 0;
	read_data = MAX_Receive_Byte();
	I2C_Ack(1);
	MAX_Stop();
	return read_data;
}

uint8_t MAX_Write_Array(uint8_t device_addr,uint16_t register_addr,u8 *Data,uint16_t Num)
{
	uint16_t i;
	MAX_Start();
	MAX_Send_Byte(device_addr+0);
	if (ack == 1)return 0;
	MAX_Send_Byte(register_addr);
	if (ack == 1)return 0;
	MAX_Start();
	MAX_Send_Byte(device_addr+1);
	if (ack == 1)return 0;
	for(i=0;i<Num;i++)
	{
		MAX_Send_Byte(*Data++);
		if (ack == 1)return 0;
	}
	MAX_Stop();
	return 1;
}

uint8_t MAX_Read_Array(uint8_t device_addr,uint16_t register_addr,uint8_t *Data,uint16_t Num)
{
	uint16_t i;
	MAX_Start();
	MAX_Send_Byte(device_addr+0);
	if (ack == 1)return 0;
	MAX_Send_Byte(register_addr);
	if (ack == 1)return 0;
	MAX_Start();
	MAX_Send_Byte(device_addr+1);
	if (ack == 1)return 0;
	for(i=0;i<Num;i++)
	{
		*Data++ = MAX_Receive_Byte();
		if(i==Num-1)
			I2C_Ack(1);
		else
			I2C_Ack(0);
	}
	MAX_Stop();
	return 1;
}



uint8_t Max30102_reset(void)
{
	if(MAX_Write_Byte(MAX30102_Device_address,REG_MODE_CONFIG, 0x40))
        return 1;
    else
        return 0;    
}

void MAX30102_Config(void)
{
	MAX_Write_Byte(MAX30102_Device_address,REG_INTR_ENABLE_1,0xD0);//// INTR setting 
	MAX_Write_Byte(MAX30102_Device_address,REG_INTR_ENABLE_2,0x00);//
	MAX_Write_Byte(MAX30102_Device_address,REG_FIFO_WR_PTR,0x00);//FIFO_WR_PTR[4:0]
	MAX_Write_Byte(MAX30102_Device_address,REG_OVF_COUNTER,0x00);//OVF_COUNTER[4:0]
	MAX_Write_Byte(MAX30102_Device_address,REG_FIFO_RD_PTR,0x00);//FIFO_RD_PTR[4:0]
	
	MAX_Write_Byte(MAX30102_Device_address,REG_FIFO_CONFIG,0x0f);//sample avg = 1, fifo rollover=false, fifo almost full = 17
	MAX_Write_Byte(MAX30102_Device_address,REG_MODE_CONFIG,0x03);//0x02 for Red only, 0x03 for SpO2 mode 0x07 multimode LED
	MAX_Write_Byte(MAX30102_Device_address,REG_SPO2_CONFIG,0x2f);	// SPO2_ADC range = 4096nA, SPO2 sample rate (400 Hz), LED pulseWidth (400uS)  
	MAX_Write_Byte(MAX30102_Device_address,REG_LED1_PA,0x32);//Choose value for ~ 10mA for LED1
	MAX_Write_Byte(MAX30102_Device_address,REG_LED2_PA,0x32);// Choose value for ~ 10mA for LED2
	MAX_Write_Byte(MAX30102_Device_address,REG_PILOT_PA,0x7f);// Choose value for ~ 25mA for Pilot LED
	
	MAX_Write_Byte(MAX30102_Device_address,REG_PROX_INT_THRESH	,0x05);// 接近模式阈值
	
	MAX_Write_Byte(MAX30102_Device_address,REG_PILOT_PA,0x7f);// Choose value for ~ 25mA for Pilot LED
	
	MAX_Read_Byte(MAX30102_Device_address,REG_INTR_STATUS_1);//清除中断标志位
	MAX_Read_Byte(MAX30102_Device_address,REG_INTR_STATUS_2);
	
	
	
}

void max30102_read_fifo(void)
{
  uint16_t un_temp;
  fifo_red=0;
  fifo_ir=0;
  uint8_t ach_i2c_data[6];
  
  //read and clear status register
  MAX_Read_Byte(MAX30102_Device_address,REG_INTR_STATUS_1);
  MAX_Read_Byte(MAX30102_Device_address,REG_INTR_STATUS_2);
  
  ach_i2c_data[0]=REG_FIFO_DATA;
	
	MAX_Read_Array(MAX30102_Device_address,REG_FIFO_DATA,ach_i2c_data,6);
	
  un_temp=ach_i2c_data[0];
  un_temp<<=14;
  fifo_red+=un_temp;
  un_temp=ach_i2c_data[1];
  un_temp<<=6;
  fifo_red+=un_temp;
  un_temp=ach_i2c_data[2];
	un_temp>>=2;
  fifo_red+=un_temp;
  
  un_temp=ach_i2c_data[3];
  un_temp<<=14;
  fifo_ir+=un_temp;
  un_temp=ach_i2c_data[4];
  un_temp<<=6;
  fifo_ir+=un_temp;
  un_temp=ach_i2c_data[5];
	un_temp>>=2;
  fifo_ir+=un_temp;
	
	if(fifo_ir<=10000)
	{
		fifo_ir=0;
	}
	if(fifo_red<=10000)
	{
		fifo_red=0;
	}
}


