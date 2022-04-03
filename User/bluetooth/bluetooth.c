#include "bluetooth.h"
#include "usart.h"
#include "led.h"
#include "GUI.h"
#include "Lcd_Driver.h"
//#include "Picture.h"



/**
  * @brief  蓝牙串口中断配置
  * @param  None
  * @retval None
  */
  
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* 嵌套向量中断控制器组选择 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* 配置USART2为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = BT_USART_IRQ ;
  /* 抢断优先级*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 子优先级 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* 使能中断 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* 初始化配置NVIC */
  NVIC_Init(&NVIC_InitStructure);
	
}

/**
  * @brief  蓝牙模块引脚配置 
  * @param  None
  * @retval None
  */

void BT_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// 打开串口GPIO的时钟
	BT_USART_GPIO_APBxClkCmd( BT_USART_GPIO_CLK , ENABLE);
	
	// 打开串口外设的时钟
	BT_USART_APBxClkCmd( BT_USART_CLK , ENABLE);
	
	//蓝牙连接STATE引脚
	
	GPIO_InitStructure.GPIO_Mode	=	GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin	=	BT_STATE_PIN;
	GPIO_Init(BT_STATE_GPIO_PORT,&GPIO_InitStructure);
		
	
	// 将USART Tx的GPIO配置为推挽复用模式
	GPIO_InitStructure.GPIO_Pin = BT_USART_TX_GPIO_PIN  ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BT_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  // 将USART Rx的GPIO配置为浮空输入模式
	GPIO_InitStructure.GPIO_Pin = BT_USART_RX_GPIO_PIN ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(BT_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	
	
	// 配置串口的工作参数
	// 配置波特率
	USART_InitStructure.USART_BaudRate = BT_USART_BAUDRATE ;
	// 配置 针数据字长
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// 配置停止位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// 配置校验位
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// 配置硬件流控制
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// 配置工作模式，收发一起
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// 完成串口的初始化配置
	USART_Init(BT_USART , &USART_InitStructure);
	
	
	// 串口中断优先级配置
	NVIC_Configuration();
	
	// 使能串口接收中断
	USART_ITConfig(BT_USART , USART_IT_RXNE , ENABLE);
	
	// 使能串口
	
	USART_Cmd(BT_USART , ENABLE);	
}


/**
  * @brief  检测蓝牙是否连接。是：LCD显示蓝牙图标；否:不显示
  * @param  None
  * @retval None
  */
void BT_check(void)
{
	if(BT_STATE_READ==1)
		{
			showimage_bt(1);
		}
	else
		showimage_bt(0);
		
	


}

/**
  * @brief  蓝牙发送字符串
  * @param  None
  * @retval None
  */

void BT_SendString( u8 *str)
{
	Usart_SendString( BT_USART, str);
}



/**
  * @brief  蓝牙串口接收中断函数
  * @param  None
  * @retval None
  */
void BT_USART_IRQHandler(void)
{

	uint8_t ucTemp;
	if(USART_GetITStatus(BT_USART,USART_IT_RXNE)!=RESET)
	{		
	
		ucTemp = USART_ReceiveData(BT_USART);
		if(ucTemp=='a')
		{
			LED1_OFF;
		}
		else
			LED1_ON;
    USART_SendData(DEBUG_USARTx,ucTemp);      
	}
	

}



