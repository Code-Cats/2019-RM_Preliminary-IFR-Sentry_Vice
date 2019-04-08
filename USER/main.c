#include "stm32f10x.h"
#include "timer.h"
#include "gpio_led.h"
#include "pwm.h"
#include "base_deal.h"
#include "gpio_switch.h"
#include "gpio_valve.h"
#include "delay.h"
#include "bsp.h"

extern SwitchTypeDef Switch;
/************************************************
STM32F103C8T6小绿板
************************************************/


 u32 trigger_count=0;
// u16 pwm_tem=500;
 int main(void)
 {
	delay_init();
	delay_ms(200);
//	//AFIO->MAPR|=AFIO_MAPR_SWJ_CFG_JTAGDISABLE;	//	禁用JTAG，只启用SWD方式调试,貌似这条语句没有起到该有的作用
	BSP_Init();

  while(1)
	{
		
//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//调用GPIO重映射函数		
//		PWM_PB4_Set(pwm_tem);
//		PWM_PB5_Set(pwm_tem);

////		if(Switch.Limit.rawdata[0]==1||Switch.Limit.rawdata[1]==1)
////		{
////			trigger_count++;
////			LED1=1;
////		}
////		else
////		{
////			LED1=0;
////		}
////		
////		if(Switch.Limit.rawdata[2]==1||Switch.Limit.rawdata[3]==1)
////		{
////			trigger_count++;
////			LED2=1;
////		}
////		else
////		{
////			LED2=0;
////		}
	}
 }
