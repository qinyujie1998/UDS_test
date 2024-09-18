/*
*********************************************************************************************************
*
*	ģ������ : FDCAN����ģ��
*	�ļ����� : bsp_can.c
*	��    �� : V1.1
*	˵    �� : CAN����. 
*
*	�޸ļ�¼ :
*		�汾��  ����        ����      ˵��
*		V1.0    2018-11-14  armfly   ��ʽ����
*		V1.1    2021-01-23  armfly   ����
*		V1.2    2023-05-12  Eric2013 ����
*
*	Copyright (C), 2021-2030, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#include "bsp.h"


/*
	����CAN1����Ҫ��V7�����ϵ�J12����ñ�̽�PA11��J13����ñ�̽�PA12��
	����CNA2��Ӳ���������ߣ���̫��������Ҫ���Σ������Ÿ��ã���
*/

/*
*********************************************************************************************************
*                                             FDCAN2����
*********************************************************************************************************
*/
/* FDCAN2 GPIO���� */
#define FDCAN2_TX_PIN       GPIO_PIN_13
#define FDCAN2_TX_GPIO_PORT GPIOB
#define FDCAN2_TX_AF        GPIO_AF9_FDCAN2
#define FDCAN2_TX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()

#define FDCAN2_RX_PIN       GPIO_PIN_12
#define FDCAN2_RX_GPIO_PORT GPIOB
#define FDCAN2_RX_AF        GPIO_AF9_FDCAN2
#define FDCAN2_RX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()

FDCAN_HandleTypeDef hfdcan2;
FDCAN_FilterTypeDef sFilterConfig2;

FDCAN_RxHeaderTypeDef g_Can2RxHeader;
uint8_t g_Can2RxData[64];

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitCan2
*	����˵��: ��ʼCAN2
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_InitCan2(void)
{	
	/* ��1������������ ==================================================================================*/
	hfdcan2.Instance = FDCAN2;                      /* ����FDCAN2 */             
	hfdcan2.Init.FrameFormat = FDCAN_FRAME_CLASSIC; /* ����ʹ�þ���CAN */  
	hfdcan2.Init.Mode = FDCAN_MODE_NORMAL;          /* ����ʹ������ģʽ */ 
	hfdcan2.Init.AutoRetransmission = ENABLE;       /* ʹ���Զ��ط� */ 
	hfdcan2.Init.TransmitPause = DISABLE;           /* ���ý�ֹ������ͣ���� */
	hfdcan2.Init.ProtocolException = ENABLE;        /* Э���쳣����ʹ�� */
	
	/* ��2�������������� ==================================================================================*/
	/* 
		�����ٲý׶β����� 
		CANʱ��20MHzʱ���ٲý׶εĲ����ʾ���
		CAN FD Freq / (Sync_Seg + Pro_Seg + Phase_Seg1 + Phase_Seg2) = 20MHz / 2/��1+0x1F + 8�� = 250Kbps	
		
		����Sync_Seg�ǹ̶�ֵ = 1 �� Pro_Seg + Phase_Seg1 = NominalTimeSeg1�� Phase_Seg2 = NominalTimeSeg2
	*/
	hfdcan2.Init.NominalPrescaler = 0x02; 	  /* CANʱ�ӷ������ã�һ������Ϊ1���ɣ�ȫ����PLL���úã�tq = NominalPrescaler x (1/ fdcan_ker_ck) */
	hfdcan2.Init.NominalSyncJumpWidth = 0x08; /* ���ڶ�̬����  Phase_Seg1�� Phase_Seg1�����Բ����Ա�Phase_Seg1�� Phase_Seg1�� */
	hfdcan2.Init.NominalTimeSeg1 = 0x1F; 	  /* �ر�ע�������Seg1����������������֮�ͣ���Ӧλʱ������ͼ�� Pro_Seg + Phase_Seg1 */
	hfdcan2.Init.NominalTimeSeg2 = 0x08;      /* ��Ӧλʱ������ͼ�� Phase_Seg2 */

	/* 
		�������ݽ׶β����� 
		CANʱ��20MHzʱ�����ݽ׶εĲ����ʾ���
		CAN FD Freq / (Sync_Seg + Pro_Seg + Phase_Seg1 + Phase_Seg2) = 20MHz / 2 / ��1+5+ 4�� = 1Mbps
		
		����Sync_Seg�ǹ̶�ֵ = 1 �� Pro_Seg + Phase_Seg1 = DataTimeSeg1�� Phase_Seg2 = DataTimeSeg2
	*/
	hfdcan2.Init.DataPrescaler = 0x01;      /* CANʱ�ӷ������ã�һ������Ϊ1���ɣ�ȫ����PLL���úã�tq = NominalPrescaler x (1/ fdcan_ker_ck)����Χ1-32 */
	hfdcan2.Init.DataSyncJumpWidth = 0x04;  /* ���ڶ�̬����  Phase_Seg1�� Phase_Seg1�����Բ����Ա�Phase_Seg1�� Phase_Seg1�󣬷�Χ1-16 */
	hfdcan2.Init.DataTimeSeg1 = 0x05; 		/* �ر�ע�������Seg1����������������֮�ͣ���Ӧλʱ������ͼ�� Pro_Seg + Phase_Seg1����Χ */
	hfdcan2.Init.DataTimeSeg2 = 0x04;       /* ��Ӧλʱ������ͼ�� Phase_Seg2 */    
	
	/* ��3����RAM���������� ==================================================================================*/
	hfdcan2.Init.MessageRAMOffset = 1280;      			/* CAN1��CAN2����2560����, ����CAN1�����1280�� */
	hfdcan2.Init.StdFiltersNbr = 4;         			/* ���ñ�׼ID��������������Χ0-128 */       
	hfdcan2.Init.ExtFiltersNbr = 4;         			/* ������չID��������������Χ0-64 */   
	hfdcan2.Init.RxFifo0ElmtsNbr = 64;                  /* ����Rx FIFO0��Ԫ�ظ�������Χ0-64 */  
	hfdcan2.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8; 	/* ����Rx FIFO0��ÿ��Ԫ�ش�С��֧��8,12,16,20,24,32,48����64�ֽ� */   
	hfdcan2.Init.RxFifo1ElmtsNbr = 3;                   /* ����Rx FIFO1��Ԫ�ظ�������Χ0-64 */
	hfdcan2.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;  /* ����Rx FIFO1��ÿ��Ԫ�ش�С��֧��8,12,16,20,24,32,48����64�ֽ� */	
	hfdcan2.Init.RxBuffersNbr = 2;                      /* ����Rx Buffer��������Χ0-64 */
	hfdcan2.Init.RxBufferSize = FDCAN_DATA_BYTES_8;     /* ����Rx Buffer��ÿ��Ԫ�ش�С��֧��8,12,16,20,24,32,48����64�ֽ� */	

	hfdcan2.Init.TxEventsNbr = 16;							/* ����Tx Event FIFO��Ԫ�ظ�������Χ0-32 */	
	hfdcan2.Init.TxBuffersNbr = 16;							/* ����Tx Buffer��Ԫ�ظ�������Χ0-32 */
	hfdcan2.Init.TxFifoQueueElmtsNbr = 16;                  /* ��������Tx FIFO/Queue��Tx Buffers��������Χ0��32 */
	hfdcan2.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION; /* ����FIFOģʽ����QUEUE����ģʽ */
	hfdcan2.Init.TxElmtSize = FDCAN_DATA_BYTES_8;           /* ����Tx Element�е��������С��֧��8,12,16,20,24,32,48����64�ֽ� */
	HAL_FDCAN_Init(&hfdcan2);

	HAL_FDCAN_ConfigGlobalFilter(&hfdcan2,                  /* ȫ�ֹ������� */
	                              FDCAN_ACCEPT_IN_RX_FIFO0, /* ���յ���ϢID���׼ID���˲�ƥ�䣬���� */
								  FDCAN_ACCEPT_IN_RX_FIFO0, /* ���յ���ϢID����չID���˲�ƥ�䣬���� */
								  FDCAN_FILTER_REMOTE,      /* ���˱�׼IDԶ��֡ */ 
								  FDCAN_FILTER_REMOTE);     /* ������չIDԶ��֡ */ 
	

	/* ��4����Rx FIFO0�ж����� ===================================================================*/	
	/* ����Rx FIFO0����ֵΪ1 ---------------------------------------*/
	HAL_FDCAN_ConfigFifoWatermark(&hfdcan2, FDCAN_CFG_RX_FIFO0, 1);

	/* ����RX FIFO0����ֵ�ж� */
	HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_WATERMARK, 0);
	
	/* ����FDCAN */
	HAL_FDCAN_Start(&hfdcan2);	
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_DeInitCan2
*	����˵��: �ͷ�CAN2
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_DeInitCan2(void)
{
	HAL_FDCAN_MspDeInit(&hfdcan2);
}

/*
*********************************************************************************************************
*	�� �� ��: HAL_FDCAN_MspInit
*	����˵��: ����CAN gpio
*	��    ��: hfdcan
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* hfdcan)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
	
	if (hfdcan == &hfdcan2)
	{
		/* ѡ��PLL2Q��ΪFDCANxʱ�� */
		FDCAN2_TX_GPIO_CLK_ENABLE();
		FDCAN2_RX_GPIO_CLK_ENABLE();

        PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
        PeriphClkInitStruct.PLL2.PLL2M = 5;
        PeriphClkInitStruct.PLL2.PLL2N = 80;
        PeriphClkInitStruct.PLL2.PLL2P = 2;
        PeriphClkInitStruct.PLL2.PLL2Q = 20;
        PeriphClkInitStruct.PLL2.PLL2R = 2;
        PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_2;
        PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOWIDE;
        PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
        PeriphClkInitStruct.FdcanClockSelection = RCC_FDCANCLKSOURCE_PLL2;
        if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
        {
            Error_Handler(__FILE__, __LINE__);
        }

		__HAL_RCC_FDCAN_CLK_ENABLE();

		GPIO_InitStruct.Pin       = FDCAN2_TX_PIN;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_PULLUP;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = FDCAN2_TX_AF;
		HAL_GPIO_Init(FDCAN2_TX_GPIO_PORT, &GPIO_InitStruct);

		GPIO_InitStruct.Pin       = FDCAN2_RX_PIN;
		GPIO_InitStruct.Alternate = FDCAN2_RX_AF;
		HAL_GPIO_Init(FDCAN2_RX_GPIO_PORT, &GPIO_InitStruct);

		
		HAL_NVIC_SetPriority(FDCAN2_IT0_IRQn, 2, 0);
		HAL_NVIC_SetPriority(FDCAN2_IT1_IRQn, 2, 0);
		HAL_NVIC_SetPriority(FDCAN_CAL_IRQn, 2, 0);
		
		HAL_NVIC_EnableIRQ(FDCAN2_IT0_IRQn);
		HAL_NVIC_EnableIRQ(FDCAN2_IT1_IRQn);
		HAL_NVIC_EnableIRQ(FDCAN_CAL_IRQn);
	}	
}

/*
*********************************************************************************************************
*	�� �� ��: HAL_FDCAN_MspInit
*	����˵��: ����CAN gpio, �ָ�Ϊ��ͨGPIO��ȡ���ж�
*	��    ��: hfdcan
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* hfdcan)
{
	if (hfdcan == &hfdcan2)
	{	
		__HAL_RCC_FDCAN_FORCE_RESET();
		__HAL_RCC_FDCAN_RELEASE_RESET();

		HAL_GPIO_DeInit(FDCAN2_TX_GPIO_PORT, FDCAN2_TX_PIN);

		HAL_GPIO_DeInit(FDCAN2_RX_GPIO_PORT, FDCAN2_RX_PIN);

		HAL_NVIC_DisableIRQ(FDCAN2_IT0_IRQn);
		HAL_NVIC_DisableIRQ(FDCAN2_IT1_IRQn);
		HAL_NVIC_DisableIRQ(FDCAN_CAL_IRQn);
	}	
}

/*
*********************************************************************************************************
*	�� �� ��: FDCAN1_IT0_IRQHandler
*	����˵��: CAN�жϷ������
*	��    ��: hfdcan
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void FDCAN2_IT0_IRQHandler(void)
{
	HAL_FDCAN_IRQHandler(&hfdcan2);
}

void FDCAN2_IT1_IRQHandler(void)
{
	HAL_FDCAN_IRQHandler(&hfdcan2);
}

void FDCAN_CAL_IRQHandler(void)
{
	HAL_FDCAN_IRQHandler(&hfdcan2);
}

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
