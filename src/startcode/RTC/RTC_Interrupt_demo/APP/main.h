/*********************************************************
*Copyright (C), 2017, Shanghai Eastsoft Microelectronics Co., Ltd.
*文件名:  main.h
*作  者:  Liut
*版  本:  V1.00
*日  期:  2017/06/26
*描  述:  
*备  注:  适用于HRSDK-GDB-ES8P508x V1.0
          本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#ifndef   __MAIN_H__
#define   __MAIN_H__

#include "lib_config.h"
#include "lib_rtc.h"
#include "systick.h"
#include "light.h"

uint32_t SecondCount = 0;
uint32_t MinuteCount = 0;
uint8_t g_2ms_flag;
uint8_t g_1s_flag;
uint32_t g_1s_cnt;

uint8_t g_sec_flag;
uint8_t g_min_flag;
uint8_t g_hour_flag;
uint8_t g_day_flag;
uint8_t g_month_flag;

#endif
