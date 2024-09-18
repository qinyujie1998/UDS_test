#include "iso14229.h"
#include "isotp-c/isotp.h"
//#include <linux/can.h>
//#include <linux/can/raw.h>
//#include <net/if.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
//#include <sys/ioctl.h>
//#include <unistd.h>
#include <errno.h>

static int sockfd = 0;
static bool HasSetup = false;

extern FDCAN_HandleTypeDef hfdcan2;
static __IO uint8_t s_ucTransState = 0;
static __IO uint8_t s_ucRectate = 0;

/* 
 *  ���ջص�����
 */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
	if (hfdcan == &hfdcan2)
	{
		if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_WATERMARK) != RESET)
		{
			s_ucRectate = 1;
		}
	}
}

/* 
 *  ���Ϳջص�����
 */
void HAL_FDCAN_TxFifoEmptyCallback(FDCAN_HandleTypeDef *hfdcan)
{
	if (hfdcan == &hfdcan2)
	{
		s_ucTransState = 1;
	}
}

static void SetupOnce() {
	
    HasSetup = true;
}

uint32_t isotp_user_get_us() { return UDSMillis() * 1000; }

void isotp_user_debug(const char *message, ...) {}

int isotp_user_send_can(const uint32_t arbitration_id, const uint8_t *data, const uint8_t size) {
    SetupOnce();
	
	int32_t time1;

	FDCAN_TxHeaderTypeDef TxHeader = {0};	
	/* ��1�������÷��Ͳ��� ===================================================================*/
	TxHeader.Identifier = arbitration_id;             		     /* ���ý���֡��Ϣ��ID */
	TxHeader.IdType = FDCAN_STANDARD_ID;     		     /* ��׼ID */
	TxHeader.TxFrameType = FDCAN_DATA_FRAME;		     /* ����֡ */
	TxHeader.DataLength = size <<16;      		         /* �������ݳ��� */
	TxHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;     /* ���ô���״ָ̬ʾ */
	TxHeader.BitRateSwitch = FDCAN_BRS_OFF;              /* �رտɱ䲨���� */
	TxHeader.FDFormat = FDCAN_CLASSIC_CAN;               /* ����CAN */
	TxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;    /* ���ڷ����¼�FIFO����, ���洢 */
	TxHeader.MessageMarker = 0;                          /* ���ڸ��Ƶ�TX EVENT FIFO����ϢMaker��ʶ����Ϣ״̬����Χ0��0xFF */
	
	HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan2, &TxHeader, (uint8_t *)data); /* ������Ҫ�������޸�_DataBuf��ֵ */
	HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_TX_FIFO_EMPTY, 0); /* ʹ��Tx FIFO���Ϳ��ж� */
	
	s_ucTransState = 0;
	
	time1 = bsp_GetRunTime();
	while(s_ucTransState == 0)
	{
		if (bsp_CheckRunTime(time1) >= 1000)
		{
			return ISOTP_RET_ERROR;
		}
	}				
    return ISOTP_RET_OK;
}

static void printhex(const uint8_t *addr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x,", addr[i]);
    }
    printf("\n");
}

void SocketCANRecv(UDSTpIsoTpC_t *tp, int phys_recv_id, int func_recv_id) {
	FDCAN_RxHeaderTypeDef RxHeader = {0};
	uint8_t RxData[8] = {0};
	
	if(s_ucRectate == 1)
	{	
		DISABLE_INT();
		s_ucRectate = 0;
		ENABLE_INT();
		
		HAL_FDCAN_GetRxMessage(&hfdcan2, FDCAN_RX_FIFO0, &RxHeader, RxData);
		HAL_FDCAN_ActivateNotification(&hfdcan2, FDCAN_IT_RX_FIFO0_WATERMARK, 0);
		
		 if (RxHeader.Identifier == phys_recv_id) {
                //UDS_DBG_PRINT("phys recvd can\n");
                //UDS_DBG_PRINTHEX(frame.data, frame.can_dlc);
                isotp_on_can_message(&tp->phys_link, RxData, RxHeader.DataLength>>16);
            } else if (RxHeader.Identifier == func_recv_id) {
               // UDS_DBG_PRINT("func recvd can\n");
               // UDS_DBG_PRINTHEX(frame.data, frame.can_dlc);
                isotp_on_can_message(&tp->func_link, RxData, RxHeader.DataLength>>16);
            }
	}
}
