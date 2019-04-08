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
u8 Valve_Value[6]={0};	//电磁阀控制
u16 Servo_Value[3]={0};
void Control_Task(void)
{
	Switch_Scanf();
	Switch_Filter(); 
	if(SendData.statu==0)
	{
		SendData.data[1]=(u8)Encoder_Postion>>8;
		SendData.data[2]=(u8)Encoder_Postion;	//[4]为上下岛加速保护，[5]为拖车检测	//[6]为左对位 [7]为右对位
		SendData.statu=1;
	}
	
	MainBoard_SendData();
	Valve_Set(Valve_Value);
	Servo_Set(MainControlData.image_cut);
}


