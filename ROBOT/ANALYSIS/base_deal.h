#ifndef BASE_DEAL_H
#define BASE_DEAL_H

#include "sys.h"

#define VALVE_ISLAND 0		//电磁阀控制位定义
#define VALVE_BULLET_PROTRACT 1
#define VALVE_BULLET_CLAMP 2
#define VALVE_BULLET_STORAGE 3	//弹药舱补弹
#define VALVE_TRAILER 5	//拖车

void PWM_PB4_Set(u16 pwm_set);
void PWM_PB5_Set(u16 pwm_set);
void Valve_Set(u8 valve_value[]);
void Servo_Set(u8 image_cut[]);	//图传切换

void Switch_Scanf(void);
void Switch_Filter(void);


#define FILTER_ORDER 16
#define INFRARE_NUMS 8	//红外传感器数量//7.7新增两个自动对位
typedef struct
{
	struct
	{
		u8 rawdata[INFRARE_NUMS];	//新增2个红外上下岛保护与拖车	7.7新增两个红外对位	6左 7右
		u8 count;
		u8 lastdata[INFRARE_NUMS][FILTER_ORDER];
		u8 dealdata[INFRARE_NUMS];
	}Infrare;
	struct
	{
		u8 rawdata[4];
		u8 count;
		u8 lastdata[4][FILTER_ORDER];
		u8 dealdata[4];
	}Limit;
}SwitchTypeDef;


extern SwitchTypeDef Switch;


#endif

