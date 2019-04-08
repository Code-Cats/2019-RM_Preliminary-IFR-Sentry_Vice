#ifndef USART2_MAINBOARD_ANALYSIS_H
#define USART2_MAINBOARD_ANALYSIS_H

#include "sys.h"

typedef struct
{
	u8 statu;
	u8 data[5];
	u8 count;
}MainBoardSendTypeDef;

#define MAINBOARD_SENDDATA_DEFAULT \
{\
	0,\
	{0x5A,0,0,0,0xA5},\
	0,\
}\

typedef struct
{
	u8 headOK_state;
	u8 valid_state;	//数据帧有效标志位
	u8 databuffer[5];
	u8 count;
}ReceiveDataTypeDef;

typedef struct
{
	u8 valve[6];
	u8 servo[2];	//暂定舵机位
	u8 image_cut[2];
}MainControlDataTypeDef;

extern MainBoardSendTypeDef SendData;
extern ReceiveDataTypeDef ReceiveData;
extern MainControlDataTypeDef MainControlData;

void Data_Receive(u8 data);	//从主板传过来的数据解析（主副板通用）
void MainControlData_Deal(u8 *pData);	//除了帧头的第一帧为控制帧，前4位为VALVE，5-6位为保留位；7-8为舵机位
void MainBoard_SendData(void);

#endif

