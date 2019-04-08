#ifndef PWM_H
#define PWM_H
#include "sys.h"

#define ESC_CYCLE 2000

#define PWM3_1  TIM3->CCR1    //
#define PWM3_2  TIM3->CCR2    //
#define PWM3_3  TIM3->CCR3    //

#define AV_CUT1 PWM3_1
#define AV_CUT2 PWM3_2

void TIM3_PWM_Init(u16 arr,u16 psc);
void pwm_init(void);	//¶­ÅãÂ×µÄ

#endif
