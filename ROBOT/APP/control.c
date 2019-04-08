#include "control.h"
#include "gpio_led.h"
#include "timer.h"
#include "base_deal.h"
#include "usart2_mainboard_analysis.h"	


void LED_Runing(void)
{
	if(time_2ms_count%250==0)
	{
		LED2=!LED2;
	}
}
extern s16 Encoder_Postion;
u8 Valve_Value[6]={0};	//��ŷ�����
u16 Servo_Value[3]={0};
void Control_Task(void)
{
	Switch_Scanf();
	Switch_Filter(); 
	if(SendData.statu==0)
	{
		SendData.data[1]=(u8)Encoder_Postion>>8;
		SendData.data[2]=(u8)Encoder_Postion;	//[4]Ϊ���µ����ٱ�����[5]Ϊ�ϳ����	//[6]Ϊ���λ [7]Ϊ�Ҷ�λ
		SendData.statu=1;
	}
	
	MainBoard_SendData();
	Valve_Set(Valve_Value);
	Servo_Set(MainControlData.image_cut);
}


