/**
  ******************************************************************************
  * @file    MLX90614.c
  * @version V1.0
  * @date    2022.03.08
  * @brief   MLX90614 IIC及相关驱动函数
  ******************************************************************************
  * @attention
  
  ******************************************************************************
  */ 






#include "mlx90614.h"
#include "GUI.h"
#include "Lcd_Driver.h"

float TT; //体温数据

/*
*********************************************************************************************************
*	函 数 名: i2c_Delay
*	功能说明: I2C总线位延迟，最快400KHz
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void i2c_Delay(void)
{
	uint8_t i;

	/*　
	 	下面的时间是通过逻辑分析仪测试得到的。
    工作条件：CPU主频72MHz ，MDK编译环境，1级优化
  
		循环次数为10时，SCL频率 = 205KHz 
		循环次数为7时，SCL频率 = 347KHz， SCL高电平时间1.5us，SCL低电平时间2.87us 
	 	循环次数为5时，SCL频率 = 421KHz， SCL高电平时间1.25us，SCL低电平时间2.375us 
	*/
	for (i = 0; i < 20; i++);
}

/*
*********************************************************************************************************
*	函 数 名: MLX_Start
*	功能说明: CPU发起I2C总线启动信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void MLX_Start(void)
{
	/* 当SCL高电平时，SDA出现一个下跳沿表示I2C总线启动信号 */
	MLX_SDA_1();
	MLX_SCL_1();
	i2c_Delay();
	MLX_SDA_0();
	i2c_Delay();
	MLX_SCL_0();
	i2c_Delay();
}

/*
*********************************************************************************************************
*	函 数 名: MLX_Stop
*	功能说明: CPU发起I2C总线停止信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void MLX_Stop(void)
{
	/* 当SCL高电平时，SDA出现一个上跳沿表示I2C总线停止信号 */
	MLX_SDA_0();
	MLX_SCL_1();
	i2c_Delay();
	MLX_SDA_1();
}

/*
*********************************************************************************************************
*	函 数 名: MLX_SendByte
*	功能说明: CPU向MLX90614设备发送8bit数据
*	形    参：_ucByte ： 等待发送的字节
*	返 回 值: 无
*********************************************************************************************************
*/
void MLX_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	/* 先发送字节的高位bit7 */
	for (i = 0; i < 8; i++)
	{		
		if (_ucByte & 0x80)
		{
			MLX_SDA_1();
		}
		else
		{
			MLX_SDA_0();
		}
		i2c_Delay();
		MLX_SCL_1();
		i2c_Delay();	
		MLX_SCL_0();
		if (i == 7)
		{
			 MLX_SDA_1(); // 释放总线
		}
		_ucByte <<= 1;	/* 左移一个bit */
		i2c_Delay();
	}
}


/*
*********************************************************************************************************
*	函 数 名: MLX_ReadByte
*	功能说明: CPU从I2C总线设备MLX90614读取8bit数据
*	形    参：无
*	返 回 值: 读到的数据
*********************************************************************************************************
*/
uint8_t MLX_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	/* 读到第1个bit为数据的bit7 */
	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		MLX_SCL_1();
		i2c_Delay();
		if (MLX_SDA_READ())
		{
			value++;
		}
		MLX_SCL_0();
		i2c_Delay();
	}
	return value;
}

/*
*********************************************************************************************************
*	函 数 名: MLX_WaitAck
*	功能说明: CPU产生一个时钟，并读取器件的ACK应答信号
*	形    参：无
*	返 回 值: 返回0表示正确应答，1表示无器件响应
*********************************************************************************************************
*/
uint8_t MLX_WaitAck(void)
{
	uint8_t re;

	MLX_SDA_1();	/* CPU释放SDA总线 */
	i2c_Delay();
	MLX_SCL_1();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
	i2c_Delay();
	if (MLX_SDA_READ())	/* CPU读取SDA口线状态 */
	{
		re = 1;
	}
	else
	{
		re = 0;
	}
	MLX_SCL_0();
	i2c_Delay();
	return re;
}

/*
*********************************************************************************************************
*	函 数 名: MLX_Ack
*	功能说明: CPU产生一个ACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void MLX_Ack(void)
{
	MLX_SDA_0();	/* CPU驱动SDA = 0 */
	i2c_Delay();
	MLX_SCL_1();	/* CPU产生1个时钟 */
	i2c_Delay();
	MLX_SCL_0();
	i2c_Delay();
	MLX_SDA_1();	/* CPU释放SDA总线 */
}

/*
*********************************************************************************************************
*	函 数 名: MLX_NAck
*	功能说明: CPU产生1个NACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void MLX_NAck(void)
{
	MLX_SDA_1();	/* CPU驱动SDA = 1 */
	i2c_Delay();
	MLX_SCL_1();	/* CPU产生1个时钟 */
	i2c_Delay();
	MLX_SCL_0();
	i2c_Delay();	
}


/*
*********************************************************************************************************
*	函 数 名: MLX_ConfigGpio
*	功能说明: 配置MLX I2C总线的GPIO，采用模拟IO的方式实现
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void MLX_ConfigGpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(MLX_RCC_PORT, ENABLE);	/* 打开GPIO时钟 */

	GPIO_InitStructure.GPIO_Pin = MLX_SCL  | MLX_SDA ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	/* 开漏输出 */
	GPIO_Init(MLX_GPIO_PORT , &GPIO_InitStructure);

	/* 给一个停止信号, 复位I2C总线上的所有设备到待机模式 */
	MLX_Stop();
}

/*
*********************************************************************************************************
*	函 数 名: MLX_RB
*	功能说明: 读RAM/EEPROM
*	形    参：Addr:从机地址； cmd；RAM/EEPROM accesss addr + 寄存器地址  W_R: WR/RD             
*	返 回 值: 无
*********************************************************************************************************
*/
uint16_t MLX_RE(u8 Addr,u8 cmd)
{
	u16 data;
	u8 DL;
	u8 DH;
	u8 PEC;
	u8 ErrorCounter=0x00;
	u8 arr[6];
	u8 PecReg;
	
	 do
    {
repeat:
         MLX_Stop()	;			    //If slave send NACK stop comunication
        --ErrorCounter;				    //Pre-decrement ErrorCounter
        if(!ErrorCounter) 			    //ErrorCounter=0?
        {
            break;					    //Yes,go out from do-while{}
        }
		
		MLX_Start();    //发送起始信号
		
		MLX_SendByte((Addr<<1) | WR);  //发送从机地址+写
		
		if(MLX_WaitAck() !=0)         //等待从机应答
		{
			goto repeat;
		}
		
		MLX_SendByte(cmd);          //发送命令，从RAM/EEPROM 读取数据
		
		if(MLX_WaitAck() !=0)  //等待应答
		{
			goto repeat;
		}
		
		MLX_Start();   
		
		MLX_SendByte((Addr<<1) | RD);  //发送从机地址+读
		
		if(MLX_WaitAck() !=0)  //等待应答
		{
			goto repeat;
		}
		
		DL=MLX_ReadByte();//接收低位数据
		
		MLX_Ack(); //发送应答，请求继续通信
		
		DH=MLX_ReadByte(); //接收高位数据
		
		MLX_Ack(); 
		
		PEC=MLX_ReadByte(); //接收CRC校验结果
		
		MLX_NAck();
		
		MLX_Stop()	;   //发送停止信号
		i2c_Delay();
	
		arr[5]= (Addr<<1) | WR;
		arr[4]= cmd;
		arr[3]= (Addr<<1) | RD;
		arr[2]= DL;
		arr[1]= DH;
		arr[0]= 0;
	
	    PecReg=PEC_Calculation(arr);//Calculate CRC 数据校验
		
	  } while(PecReg != PEC);//If received and calculated CRC are equal go out from do-while{}
	
   

	data = (DH<<8) | DL;	//data=DataH:DataL
	  
    return data;
}


/*
*********************************************************************************************************
*	函 数 名: MLX_WriteEE
*	功能说明: 写EEPROM
*	形    参：Addr:从机地址； cmd；RAM/EEPROM accesss addr + 寄存器地址  W_R: WR/RD             
*	返 回 值: 无
*********************************************************************************************************
*/
uint8_t MLX_WriteEE(u8 Addr,u8 cmd,u8 DL,u8 DH)
{
	
	u8 PEC;
	u8 ErrorCounter=0xFF;
	u8 arr[6];
	u8 Mark;
	
	   arr[5]= 0;
	   arr[4]= (Addr<<1) | WR;
	   arr[3]= cmd;
	   arr[2]= DL;
	   arr[1]= DH;
	   arr[0]= 0;
	
	 PEC=PEC_Calculation(arr);
	
	 do
    {
repeat:
         MLX_Stop()	;			    //If slave send NACK stop comunication
		
		MLX_Start();    //发送起始信号
		
		MLX_SendByte((Addr<<1) | WR);  //发送从机地址+写
		
		if(MLX_WaitAck() !=0)         //等待从机应答
		{
			goto repeat;
		}
		
		MLX_SendByte(cmd);          //发送命令，EEPROM 写数据
		
		if(MLX_WaitAck() !=0)  //等待应答
		{
			goto repeat;
		}
		
		MLX_SendByte(DL);  //发送低位字节
		
		if(MLX_WaitAck() !=0)  //等待应答
		{
			goto repeat;
		}
		
		MLX_SendByte(DH);  //发送高位字节
		
		if(MLX_WaitAck() !=0)  //等待应答
		{
			goto repeat;
		}
		
		MLX_SendByte(PEC);  //发送CRC校验码
		
		if(MLX_WaitAck() !=0)  //等待应答
		{
			goto repeat;
		}
		
		
		MLX_Stop()	;   //发送停止信号
		
		break;
		
	  } while(--ErrorCounter);//If received and calculated CRC are equal go out from do-while{}
	
	  if (ErrorCounter!=0)
	  {
		  Mark=SUCCESS;
	  }
	  else
		  Mark=!SUCCESS;
	  
	  return Mark;
   
}







/*******************************************************************************
* 函数名: PEC_calculation
* 功能 : 数据校验
* Input          : pec[]
* Output         : None
* Return         : pec[0]-this byte contains calculated crc value
*******************************************************************************/
u8 PEC_Calculation(u8 pec[])
{
    u8 	crc[6];//存放多项式
    u8	BitPosition=47;//存放所有数据最高位，6*8=48 最高位就是47位
    u8	shift;
    u8	i;
    u8	j;
    u8	temp;

    do
    {
        /*CRC 多项式写入数组 0x00 00 00 00 01 07*/
        crc[5]=0;
        crc[4]=0;
        crc[3]=0;
        crc[2]=0;
        crc[1]=0x01;
        crc[0]=0x07;

        /*校验数据的最高位*/
        BitPosition=47;

        /*Set shift position at 0*/
        shift=0;

        /*找出校验数据的第一个1*/
        i=5;
        j=0;
        while((pec[i]&(0x80>>j))==0 && i>0)
        {
            BitPosition--;
            if(j<7)
            {
                j++;
            }
            else
            {
                j=0x00;
                i--;
            }
        }/*End of while */

        /*CRC数值的偏移值，左移或右移*/
        shift=BitPosition-8;

        /*将CRC数值左移shift位 */
        while(shift)
        {
            for(i=5; i<0xFF; i--)
            {
                if((crc[i-1]&0x80) && (i>0)) //因为数组为8位，左移后最高位溢出丢失，判断下一字节最高位是否为1
                {
                    temp=1;   //是则该crc[i]加1
                }
                else
                {
                    temp=0;
                }
                crc[i]<<=1;
                crc[i]+=temp;
            }/*左移一位结束*/
            shift--;
        }/*左移shift结束*/

        /*将pec和crc OR异或*/
        for(i=0; i<=5; i++)
        {
            pec[i] ^=crc[i];
        }/*end*/
    }
    while(BitPosition>8); /*CRC8，循环异或至8位数据*/

    return pec[0];
}

	

/*
*********************************************************************************************************
*	函 数 名: MLX_Init
*	功能说明: MLX90614校准发射率
*	形    参：Addr:从机地址； cmd；RAM/EEPROM accesss addr + 寄存器地址  W_R: WR/RD             
*	返 回 值: 无
*********************************************************************************************************
*/

void MLX_Init()
{
//	u8 DL;
//	u8 DH;
	
//	DL=data & 0xFF;
//	DH = (data & 0xFF00) >>8;
	
	MLX_WriteEE(SA,EEPROM_ACCESS| EEPROM_EMI,0x00,0x00); //先擦除0x04内容
	printf("擦除成功");
	delay_ms(5);
	
	MLX_WriteEE(SA,EEPROM_ACCESS| EEPROM_EMI,0xe0,0xfa);
	printf("系数校准成功");
	delay_ms(5);

}	


/*******************************************************************************
 * 函数名: MLX_ReadTemp
 * 功能: 计算并返回温度值
 * Return  : SMBus_ReadMemory(0x00, 0x07)*0.02-273.15
*******************************************************************************/
float MLX_ReadTemp(void)
{
	float temp;
	temp= MLX_RE( SA,0x07);
	temp=temp*0.02-273.15;
	return temp;
	
}
	
	
/*******************************************************************************
 * 函数名: MLX_EnvironTemp
 * 功能: 计算并返回温度值
 * Return  : SMBus_ReadMemory(0x00, 0x07)*0.02-273.15
*******************************************************************************/
float MLX_EnvironTemp(void)
{
	float temp;
	temp= MLX_RE( SA,RAM_ACCESS|Ta);
	temp=temp*0.02-273.15;
	
	return temp;
	
}	
	
/*******************************************************************************
 * 函数名: Tbody
 * 功能: 额温转体温
 * Return  : Tbody
*******************************************************************************/
float Tbody(void)
{
	float ta,tf,tbody=0;
	float tf_low,tf_high = 0;
	float TA_LEVEL = 25;
	ta=MLX_EnvironTemp();
	tf=MLX_ReadTemp();
	
	
	if(ta<= TA_LEVEL)
	{
		tf_low = 32.66 + 0.186 * (ta-TA_LEVEL);
		tf_high = 34.84 + 0.148 * (ta-TA_LEVEL);
	}
	else
	{
		tf_low = 32.66 + 0.086 * (ta-TA_LEVEL);
		tf_high = 34.84 + 0.1 * (ta-TA_LEVEL);
	}
	
	if((tf_low <= tf) && (tf <= tf_high))
	{
		tbody = 36.3 + 0.5/(tf_high - tf_low)*(tf - tf_low);
	}
	else if (tf > tf_high)
	{
		tbody = 36.8 + (0.829321 + 0.002364*ta)*(tf - tf_high);
	}
	else if (tf < tf_low)
	{
		tbody = 36.3 + (0.551658 + 0.021525*ta)*(tf-tf_low);
	}
	return tbody;
	
	
}	
	
/*LCD输出显示 及蓝牙发送*/
void tft_TT_display()
{
	uint8_t str[50];
	TT=Tbody();
	sprintf((char *)str,"%2.2f℃",TT);
	Gui_DrawFont_GBK16(2, 102, RED, BLACK, str); //数据写入行
	BT_SendString("T : ");
	BT_SendString(str); //蓝牙发送
	//BT_SendString("\r\n");


}	
	
	
	
	
	
	
	
	
	
	
	
	
	
