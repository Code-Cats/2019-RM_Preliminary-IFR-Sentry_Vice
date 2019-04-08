#include "bsp.h"

void BSP_Init(void)
{
	LED_Init();

	USART2_Mainboard_Init(256000);
	//TIM3_PWM_Init(ESC_CYCLE-1,72-1);	//5.11重启//ESC_CYCLE=20000,20ms
	//	pwm_init();	//董陪伦的
	TIM1_Int_Init(2000-1,72-1);	//	72MHZ频率，分频720(不知道为什么频率异常，故换成了72)，100khz计数频率，计数100次为1ms,计数200次为2ms
	//  Switch_Init();

	T1_7_IN_Init();	//T1-T7输入
	P5_8_IN_Init();
	EXTIX_Encoder_Init();
}



