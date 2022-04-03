/**
  ******************************************************************************
  * @file    MLX90614.c
  * @version V1.0
  * @date    2022.03.08
  * @brief   MLX90614 IIC�������������
  ******************************************************************************
  * @attention
  
  ******************************************************************************
  */ 






#include "mlx90614.h"
#include "GUI.h"
#include "Lcd_Driver.h"

float TT; //��������

/*
*********************************************************************************************************
*	�� �� ��: i2c_Delay
*	����˵��: I2C����λ�ӳ٣����400KHz
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void i2c_Delay(void)
{
	uint8_t i;

	/*��
	 	�����ʱ����ͨ���߼������ǲ��Եõ��ġ�
    ����������CPU��Ƶ72MHz ��MDK���뻷����1���Ż�
  
		ѭ������Ϊ10ʱ��SCLƵ�� = 205KHz 
		ѭ������Ϊ7ʱ��SCLƵ�� = 347KHz�� SCL�ߵ�ƽʱ��1.5us��SCL�͵�ƽʱ��2.87us 
	 	ѭ������Ϊ5ʱ��SCLƵ�� = 421KHz�� SCL�ߵ�ƽʱ��1.25us��SCL�͵�ƽʱ��2.375us 
	*/
	for (i = 0; i < 20; i++);
}

/*
*********************************************************************************************************
*	�� �� ��: MLX_Start
*	����˵��: CPU����I2C���������ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MLX_Start(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C���������ź� */
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
*	�� �� ��: MLX_Stop
*	����˵��: CPU����I2C����ֹͣ�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MLX_Stop(void)
{
	/* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾI2C����ֹͣ�ź� */
	MLX_SDA_0();
	MLX_SCL_1();
	i2c_Delay();
	MLX_SDA_1();
}

/*
*********************************************************************************************************
*	�� �� ��: MLX_SendByte
*	����˵��: CPU��MLX90614�豸����8bit����
*	��    �Σ�_ucByte �� �ȴ����͵��ֽ�
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MLX_SendByte(uint8_t _ucByte)
{
	uint8_t i;

	/* �ȷ����ֽڵĸ�λbit7 */
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
			 MLX_SDA_1(); // �ͷ�����
		}
		_ucByte <<= 1;	/* ����һ��bit */
		i2c_Delay();
	}
}


/*
*********************************************************************************************************
*	�� �� ��: MLX_ReadByte
*	����˵��: CPU��I2C�����豸MLX90614��ȡ8bit����
*	��    �Σ���
*	�� �� ֵ: ����������
*********************************************************************************************************
*/
uint8_t MLX_ReadByte(void)
{
	uint8_t i;
	uint8_t value;

	/* ������1��bitΪ���ݵ�bit7 */
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
*	�� �� ��: MLX_WaitAck
*	����˵��: CPU����һ��ʱ�ӣ�����ȡ������ACKӦ���ź�
*	��    �Σ���
*	�� �� ֵ: ����0��ʾ��ȷӦ��1��ʾ��������Ӧ
*********************************************************************************************************
*/
uint8_t MLX_WaitAck(void)
{
	uint8_t re;

	MLX_SDA_1();	/* CPU�ͷ�SDA���� */
	i2c_Delay();
	MLX_SCL_1();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
	i2c_Delay();
	if (MLX_SDA_READ())	/* CPU��ȡSDA����״̬ */
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
*	�� �� ��: MLX_Ack
*	����˵��: CPU����һ��ACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MLX_Ack(void)
{
	MLX_SDA_0();	/* CPU����SDA = 0 */
	i2c_Delay();
	MLX_SCL_1();	/* CPU����1��ʱ�� */
	i2c_Delay();
	MLX_SCL_0();
	i2c_Delay();
	MLX_SDA_1();	/* CPU�ͷ�SDA���� */
}

/*
*********************************************************************************************************
*	�� �� ��: MLX_NAck
*	����˵��: CPU����1��NACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MLX_NAck(void)
{
	MLX_SDA_1();	/* CPU����SDA = 1 */
	i2c_Delay();
	MLX_SCL_1();	/* CPU����1��ʱ�� */
	i2c_Delay();
	MLX_SCL_0();
	i2c_Delay();	
}


/*
*********************************************************************************************************
*	�� �� ��: MLX_ConfigGpio
*	����˵��: ����MLX I2C���ߵ�GPIO������ģ��IO�ķ�ʽʵ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void MLX_ConfigGpio(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(MLX_RCC_PORT, ENABLE);	/* ��GPIOʱ�� */

	GPIO_InitStructure.GPIO_Pin = MLX_SCL  | MLX_SDA ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  	/* ��©��� */
	GPIO_Init(MLX_GPIO_PORT , &GPIO_InitStructure);

	/* ��һ��ֹͣ�ź�, ��λI2C�����ϵ������豸������ģʽ */
	MLX_Stop();
}

/*
*********************************************************************************************************
*	�� �� ��: MLX_RB
*	����˵��: ��RAM/EEPROM
*	��    �Σ�Addr:�ӻ���ַ�� cmd��RAM/EEPROM accesss addr + �Ĵ�����ַ  W_R: WR/RD             
*	�� �� ֵ: ��
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
		
		MLX_Start();    //������ʼ�ź�
		
		MLX_SendByte((Addr<<1) | WR);  //���ʹӻ���ַ+д
		
		if(MLX_WaitAck() !=0)         //�ȴ��ӻ�Ӧ��
		{
			goto repeat;
		}
		
		MLX_SendByte(cmd);          //���������RAM/EEPROM ��ȡ����
		
		if(MLX_WaitAck() !=0)  //�ȴ�Ӧ��
		{
			goto repeat;
		}
		
		MLX_Start();   
		
		MLX_SendByte((Addr<<1) | RD);  //���ʹӻ���ַ+��
		
		if(MLX_WaitAck() !=0)  //�ȴ�Ӧ��
		{
			goto repeat;
		}
		
		DL=MLX_ReadByte();//���յ�λ����
		
		MLX_Ack(); //����Ӧ���������ͨ��
		
		DH=MLX_ReadByte(); //���ո�λ����
		
		MLX_Ack(); 
		
		PEC=MLX_ReadByte(); //����CRCУ����
		
		MLX_NAck();
		
		MLX_Stop()	;   //����ֹͣ�ź�
		i2c_Delay();
	
		arr[5]= (Addr<<1) | WR;
		arr[4]= cmd;
		arr[3]= (Addr<<1) | RD;
		arr[2]= DL;
		arr[1]= DH;
		arr[0]= 0;
	
	    PecReg=PEC_Calculation(arr);//Calculate CRC ����У��
		
	  } while(PecReg != PEC);//If received and calculated CRC are equal go out from do-while{}
	
   

	data = (DH<<8) | DL;	//data=DataH:DataL
	  
    return data;
}


/*
*********************************************************************************************************
*	�� �� ��: MLX_WriteEE
*	����˵��: дEEPROM
*	��    �Σ�Addr:�ӻ���ַ�� cmd��RAM/EEPROM accesss addr + �Ĵ�����ַ  W_R: WR/RD             
*	�� �� ֵ: ��
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
		
		MLX_Start();    //������ʼ�ź�
		
		MLX_SendByte((Addr<<1) | WR);  //���ʹӻ���ַ+д
		
		if(MLX_WaitAck() !=0)         //�ȴ��ӻ�Ӧ��
		{
			goto repeat;
		}
		
		MLX_SendByte(cmd);          //�������EEPROM д����
		
		if(MLX_WaitAck() !=0)  //�ȴ�Ӧ��
		{
			goto repeat;
		}
		
		MLX_SendByte(DL);  //���͵�λ�ֽ�
		
		if(MLX_WaitAck() !=0)  //�ȴ�Ӧ��
		{
			goto repeat;
		}
		
		MLX_SendByte(DH);  //���͸�λ�ֽ�
		
		if(MLX_WaitAck() !=0)  //�ȴ�Ӧ��
		{
			goto repeat;
		}
		
		MLX_SendByte(PEC);  //����CRCУ����
		
		if(MLX_WaitAck() !=0)  //�ȴ�Ӧ��
		{
			goto repeat;
		}
		
		
		MLX_Stop()	;   //����ֹͣ�ź�
		
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
* ������: PEC_calculation
* ���� : ����У��
* Input          : pec[]
* Output         : None
* Return         : pec[0]-this byte contains calculated crc value
*******************************************************************************/
u8 PEC_Calculation(u8 pec[])
{
    u8 	crc[6];//��Ŷ���ʽ
    u8	BitPosition=47;//��������������λ��6*8=48 ���λ����47λ
    u8	shift;
    u8	i;
    u8	j;
    u8	temp;

    do
    {
        /*CRC ����ʽд������ 0x00 00 00 00 01 07*/
        crc[5]=0;
        crc[4]=0;
        crc[3]=0;
        crc[2]=0;
        crc[1]=0x01;
        crc[0]=0x07;

        /*У�����ݵ����λ*/
        BitPosition=47;

        /*Set shift position at 0*/
        shift=0;

        /*�ҳ�У�����ݵĵ�һ��1*/
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

        /*CRC��ֵ��ƫ��ֵ�����ƻ�����*/
        shift=BitPosition-8;

        /*��CRC��ֵ����shiftλ */
        while(shift)
        {
            for(i=5; i<0xFF; i--)
            {
                if((crc[i-1]&0x80) && (i>0)) //��Ϊ����Ϊ8λ�����ƺ����λ�����ʧ���ж���һ�ֽ����λ�Ƿ�Ϊ1
                {
                    temp=1;   //�����crc[i]��1
                }
                else
                {
                    temp=0;
                }
                crc[i]<<=1;
                crc[i]+=temp;
            }/*����һλ����*/
            shift--;
        }/*����shift����*/

        /*��pec��crc OR���*/
        for(i=0; i<=5; i++)
        {
            pec[i] ^=crc[i];
        }/*end*/
    }
    while(BitPosition>8); /*CRC8��ѭ�������8λ����*/

    return pec[0];
}

	

/*
*********************************************************************************************************
*	�� �� ��: MLX_Init
*	����˵��: MLX90614У׼������
*	��    �Σ�Addr:�ӻ���ַ�� cmd��RAM/EEPROM accesss addr + �Ĵ�����ַ  W_R: WR/RD             
*	�� �� ֵ: ��
*********************************************************************************************************
*/

void MLX_Init()
{
//	u8 DL;
//	u8 DH;
	
//	DL=data & 0xFF;
//	DH = (data & 0xFF00) >>8;
	
	MLX_WriteEE(SA,EEPROM_ACCESS| EEPROM_EMI,0x00,0x00); //�Ȳ���0x04����
	printf("�����ɹ�");
	delay_ms(5);
	
	MLX_WriteEE(SA,EEPROM_ACCESS| EEPROM_EMI,0xe0,0xfa);
	printf("ϵ��У׼�ɹ�");
	delay_ms(5);

}	


/*******************************************************************************
 * ������: MLX_ReadTemp
 * ����: ���㲢�����¶�ֵ
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
 * ������: MLX_EnvironTemp
 * ����: ���㲢�����¶�ֵ
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
 * ������: Tbody
 * ����: ����ת����
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
	
/*LCD�����ʾ ����������*/
void tft_TT_display()
{
	uint8_t str[50];
	TT=Tbody();
	sprintf((char *)str,"%2.2f��",TT);
	Gui_DrawFont_GBK16(2, 102, RED, BLACK, str); //����д����
	BT_SendString("T : ");
	BT_SendString(str); //��������
	//BT_SendString("\r\n");


}	
	
	
	
	
	
	
	
	
	
	
	
	
	
