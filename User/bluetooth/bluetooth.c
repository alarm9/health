#include "bluetooth.h"
#include "usart.h"
#include "led.h"
#include "GUI.h"
#include "Lcd_Driver.h"
//#include "Picture.h"



/**
  * @brief  ���������ж�����
  * @param  None
  * @retval None
  */
  
static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Ƕ�������жϿ�������ѡ�� */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* ����USART2Ϊ�ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannel = BT_USART_IRQ ;
  /* �������ȼ�*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* �����ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ʹ���ж� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ��ʼ������NVIC */
  NVIC_Init(&NVIC_InitStructure);
	
}

/**
  * @brief  ����ģ���������� 
  * @param  None
  * @retval None
  */

void BT_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// �򿪴���GPIO��ʱ��
	BT_USART_GPIO_APBxClkCmd( BT_USART_GPIO_CLK , ENABLE);
	
	// �򿪴��������ʱ��
	BT_USART_APBxClkCmd( BT_USART_CLK , ENABLE);
	
	//��������STATE����
	
	GPIO_InitStructure.GPIO_Mode	=	GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin	=	BT_STATE_PIN;
	GPIO_Init(BT_STATE_GPIO_PORT,&GPIO_InitStructure);
		
	
	// ��USART Tx��GPIO����Ϊ���츴��ģʽ
	GPIO_InitStructure.GPIO_Pin = BT_USART_TX_GPIO_PIN  ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BT_USART_TX_GPIO_PORT, &GPIO_InitStructure);

  // ��USART Rx��GPIO����Ϊ��������ģʽ
	GPIO_InitStructure.GPIO_Pin = BT_USART_RX_GPIO_PIN ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(BT_USART_RX_GPIO_PORT, &GPIO_InitStructure);
	
	
	// ���ô��ڵĹ�������
	// ���ò�����
	USART_InitStructure.USART_BaudRate = BT_USART_BAUDRATE ;
	// ���� �������ֳ�
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	// ����ֹͣλ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	// ����У��λ
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	// ����Ӳ��������
	USART_InitStructure.USART_HardwareFlowControl = 
	USART_HardwareFlowControl_None;
	// ���ù���ģʽ���շ�һ��
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	// ��ɴ��ڵĳ�ʼ������
	USART_Init(BT_USART , &USART_InitStructure);
	
	
	// �����ж����ȼ�����
	NVIC_Configuration();
	
	// ʹ�ܴ��ڽ����ж�
	USART_ITConfig(BT_USART , USART_IT_RXNE , ENABLE);
	
	// ʹ�ܴ���
	
	USART_Cmd(BT_USART , ENABLE);	
}


/**
  * @brief  ��������Ƿ����ӡ��ǣ�LCD��ʾ����ͼ�ꣻ��:����ʾ
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
  * @brief  ���������ַ���
  * @param  None
  * @retval None
  */

void BT_SendString( u8 *str)
{
	Usart_SendString( BT_USART, str);
}



/**
  * @brief  �������ڽ����жϺ���
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



