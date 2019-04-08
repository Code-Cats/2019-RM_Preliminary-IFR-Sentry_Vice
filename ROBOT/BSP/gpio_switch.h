#ifndef __GPIO_SWITCH_H
#define __GPIO_SWITCH_H
#include "sys.h"

//void Limit_Init(void);
//void B1_Init(void);
//void B2_Init(void);
//void B3_Init(void);
//void B4_Init(void);
//void L1_4_Init(void);


//#define PB10 PBin(10)
//#define PB11 PBin(11)
//#define PA1 PAin(1)
//#define PB1 PBin(1)
//#define PC10 PCin(10)
//#define PC11 PCin(11)
//#define PC12 PCin(12)
//#define PD2 PDin(2)

//#define PC4 PCin(4)
//#define PC5 PCin(5)
//#define PC6 PCin(6)
//#define PC7 PCin(7)

//#define S1 PA15
#define T1_IN PCin(6)
#define T2_IN PCin(7)
#define T3_IN PCin(8)
#define T4_IN PCin(9)
#define T5_IN PCin(10)
#define T6_IN PCin(11)
#define T7_IN PCin(12)

#define P5_IN PAin(6)
#define P6_IN PAin(7)
#define P7_IN PBin(0)
#define P8_IN PBin(1)


void T1_7_IN_Init(void);	//T1-T7 ‰»Î
void P5_8_IN_Init(void);	//PWM_1-4 ‰»Î

#endif
