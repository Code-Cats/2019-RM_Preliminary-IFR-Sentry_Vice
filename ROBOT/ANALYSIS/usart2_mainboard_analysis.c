#include "usart2_mainboard_analysis.h"

MainBoardSendTypeDef SendData=MAINBOARD_SENDDATA_DEFAULT;
//副板给主板串口发送函数	//2ms执行一次，10ms更新一次结果，14400的波特率，一个字节最多传输11位，11/14400=0.76ms
void MainBoard_SendData(void)
{
	if(USART_GetFlagStatus(USART2,USART_FLAG_TC)== SET)	//如果上一帧发送完成
	{
		if(SendData.statu==1)
		{
			SendData.data[0]=0x5A;	//防止帧头帧尾被破坏
			SendData.data[4]=0xA5;	//防止帧头帧尾被破坏
			USART_SendData(USART2,SendData.data[SendData.count]);
			SendData.count++;
			if(SendData.count>4)
			{
				SendData.statu=0;
				SendData.count=0;
			}
		}
	}
	
}


ReceiveDataTypeDef ReceiveData={0};
u16 t_usart1_count=0;
void Data_Receive(u8 data)	//从主板传过来的数据解析（主副板通用）
{
	t_usart1_count++;
	if(data==0x5A&&ReceiveData.headOK_state==0)
	{
		ReceiveData.valid_state=0;	//数据接受期间不进行数据解析
		ReceiveData.headOK_state=1;	
		ReceiveData.count=0;	//重置count
	}
	
	if(ReceiveData.headOK_state==1)	//帧头已找到
	{
		ReceiveData.databuffer[ReceiveData.count]=data;
		ReceiveData.count++;
		if((data==0xA5&&ReceiveData.count!=5)||(ReceiveData.count>5))	//失效
		{
			ReceiveData.valid_state=0;
			ReceiveData.headOK_state=0;
			ReceiveData.count=0;	//重置count
		}
		else if(data==0xA5&&ReceiveData.count==5)
		{
			ReceiveData.valid_state=1;
			ReceiveData.headOK_state=0;
			ReceiveData.count=0;	//重置count
		}
	}
	
	MainControlData_Deal(ReceiveData.databuffer);
	//////////////////////////////这里放数据解析函数-->解析为真实数据
	
}


MainControlDataTypeDef MainControlData={0};

void MainControlData_Deal(u8 *pData)	//除了帧头的第一帧为控制帧，前4位为VALVE，5-6位为保留位；7-8为舵机位
{
	for(int i=0;i<6;i++)
	{
		MainControlData.valve[i]=*(pData+1)>>(7-i)&0x01;
	}
	
	for(int i=0;i<2;i++)
	{
		MainControlData.servo[i]=*(pData+1)>>(1-i)&0x01;
	}
	
	for(int i=0;i<2;i++)
	{
		MainControlData.image_cut[i]=*(pData+2)>>(7-i)&0x01;		//[4]为上下岛加速保护，[5]为拖车检测
	}
}


