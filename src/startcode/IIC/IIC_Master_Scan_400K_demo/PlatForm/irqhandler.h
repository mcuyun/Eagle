
#ifndef __IRQHANDLER_H__
#define __IRQHANDLER_H__

#include "ES8P508x.h"

extern uint32_t SysCount;

extern uint8_t g_2ms_flag;        //2ms��־
extern uint8_t g_10ms_flag;        //10ms��־
extern uint16_t g_10ms_cnt;        //10ms����

/************�жϺ�������***********/
void    NMI_IRQHandler(void);
void    HardFault_IRQHandler(void);
void    SVC_IRQHandler(void);
void    PendSV_IRQHandler(void);
void    SysTick_IRQHandler(void);


#endif
