/*********************************************************
 *Copyright (C), 2015, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ���:  RTC.c
 *��  ��:  yuzr
 *��  ��:  V1.00
 *��  ��:  2017/10/23
 *��  ��:  �û�RTCģ�����
 *��  ע:  ������ES8P508x
 ����������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 **********************************************************/
 
#include "rtc.h"
 
/***************************************************************
  ��������GPIO_RTC0_Init
  ��  ����RTC0���ų�ʼ������ʼ��RTC��ʹ��RTC0�������
  ����ֵ����
  ���ֵ����
  ����ֵ����
***************************************************************/
void MyRTC_Init(void)
{
	GPIO_InitStruType x; 

	x.GPIO_Signal = GPIO_Pin_Signal_Digital;
	x.GPIO_Direction = GPIO_Dir_Out;
	x.GPIO_Func = GPIO_Func_2;
	x.GPIO_OD = GPIO_ODE_Output_Disable;
	x.GPIO_DS = GPIO_DS_Output_Strong;
	x.GPIO_PDEN = GPIO_PDE_Input_Disable;
	x.GPIO_PUEN = GPIO_PUE_Input_Disable;
	GPIO_Init(GPIOA,GPIO_Pin_21,&x);
	
	RTC->WP.Word = 0X55AAAA55;     //�ر�RTCд����
	RTC->CON.PON = 0X0;            //ʱ�Ӹ�λ��������
	RTC->CON.CLKS = 0X0;           //ѡ��32.768Ϊʱ��Դ
	RTC->CAL.CLKC = 0x1;           //ʹ��RTC0ʱ�����
	RTC->CAL.COCR = 0X3;           //����֮ǰ����Ƶ������0x3,
																 //����֮�������ѡ��0x4
	RTC->WP.Word = 0X00000000;     //д����
}
/***************************************************************
  ��������MY_RTC_Init
  ��  ���������������ʱ��ÿ���x�룬��ôÿ��RTC�����
	����(x/(24Сʱ*60����*60��))*10^6  = x*11.574 ppm
	RTC->CAL.CALFд����ֵΪ��
	���CALF<7>=0���������У������Ϊ((CALF<6:0>) - 1) x 2��
	��������Ϊ1������Ϊ(1/32768/20)*10^6 = 1.525ppm����Ҫ������Ϊ
	��x*11.574��/1.525����((CALF<6:0>) - 1) x 2 = ��x*11.574��/1.525��
	���CALF<7>=1����ݼ���У������Ϊ((~CALF<6:0>) + 1) x 2��
	��������Ϊ1������Ϊ(1/32768/20)*10^6 = 1.525ppm����Ҫ������Ϊ
	��x*11.574��/1.525����((~CALF<6:0>) + 1) x 2 =��x*11.574��/1.525��
  ����ֵ��uint8_t error
  ���ֵ����
  ����ֵ����
***************************************************************/
void Error_Offset( uint8_t error )
{
	RTC->WP.Word = 0X55AAAA55;     //�ر�RTCд����
	RTC->CON.PON = 0X0;            //���PON��RTC��������
	RTC->CON.CLKS = 0X0;           //ѡ��32.768ʱ����Ϊʱ��Դ
	RTC->CAL.COCR = 0X4;           //У����1Hzʱ�����, ����ѡ����������Ż���Ч
	RTC->CAL.DEV = 0X0;            //ÿ20S����һ��
	RTC->CAL.CALF = error;         //��д����ֵ
	RTC->WP.Word = 0X00000000;     //д����
}