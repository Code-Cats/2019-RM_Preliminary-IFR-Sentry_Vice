#ifndef __GPIO_LED_H
#define __GPIO_LED_H
#include "sys.h"

void LED_Init(void);

#define LED1 PAout(0)
#define LED2 PAout(5)

#endif
