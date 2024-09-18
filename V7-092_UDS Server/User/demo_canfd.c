/*
*********************************************************************************************************
*
*	ģ������ : CAN FDӦ�á�
*	�ļ����� : demo_canfd.c
*	��    �� : V1.0
*	˵    �� : J1939Ӧ��
*
*	�޸ļ�¼ :
*		�汾��   ����         ����        ˵��
*		V1.0    2024-01-07   Eric2013    ��ʽ����
*
*	Copyright (C), 2021-2030, ���������� www.armfly.com
*
*********************************************************************************************************
*/
#include "bsp.h"
#include "can_network.h"
#include "uds/uds_types.h"
#include "uds/uds.h"
#include <stdbool.h>

/*
	����CANFD2��Ӳ���������ߣ���̫��������Ҫ���Σ������Ÿ��ã���
*/
extern FDCAN_HandleTypeDef hfdcan2;

// required, this must send a single CAN message with the given arbitration
// ID (i.e. the CAN message ID) and data. The size will never be more than 8
// bytes.
bool send_can(const uint32_t arbitration_id, const uint8_t* data,
        const uint8_t size) {
    
}

// optional, provide to receive debugging log messages
void debug(const char* format, ...) {

}


// not used in the current version
void set_timer(uint16_t time_ms, void (*callback)) {
 
}

// Optional: This is your callback that will be called the response to your
// diagnostic request is received.
void response_received_handler(const DiagnosticResponse* response) {
    // You received a response! Do something with it.
}

/*
*********************************************************************************************************
*	�� �� ��: DemoCANFD
*	����˵��: CAN����
*	��    ��: ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
//DiagnosticShims shims;
void DemoCANFD(void)
{
	uint8_t ucKeyCode;		/* �������� */

	bsp_StartAutoTimer(0, 500);	          /* ����1��500ms���Զ���װ�Ķ�ʱ�� */

//	shims = diagnostic_init_shims(debug, send_can, set_timer);
//	
//	DiagnosticRequestHandle handle = diagnostic_request_pid(&shims,
//        DIAGNOSTIC_STANDARD_PID, // this is a standard PID request, not an extended or enhanced one
//        OBD2_FUNCTIONAL_BROADCAST_ID, // the request is going out to the broadcast arbitration ID
//        0x2, // we want PID 0x2
//        response_received_handler); // our callback (optional, use NULL if you don't have one)
	
	while (1)
	{
		
		/* �ж϶�ʱ����ʱʱ�� */
		if (bsp_CheckTimer(0))	
		{            
			/* ÿ��500ms ����һ�� */  
			bsp_LedToggle(2);
		}
		
        /* �����˲��ͼ���ɺ�̨systick�жϷ������ʵ�֣�����ֻ��Ҫ����bsp_GetKey��ȡ��ֵ���ɡ� */
		ucKeyCode = bsp_GetKey();	/* ��ȡ��ֵ, �޼�����ʱ���� KEY_NONE = 0 */
		if (ucKeyCode != KEY_NONE)
		{
			switch (ucKeyCode)
			{
				case KEY_DOWN_K1:			/* K1������ */
					break;

				case KEY_DOWN_K2:			/* K2������ */
					break;

				default:
					/* �����ļ�ֵ������ */
					break;
			}
		
		}
	}
}

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
