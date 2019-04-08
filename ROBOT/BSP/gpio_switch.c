#include "gpio_switch.h"

//void Limit_Init(void)
//{
//	B1_Init();
//	B2_Init();
//	B3_Init();
//	B4_Init();	//对位
//	L1_4_Init();
//}

//void B1_Init(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 ////////////更改接口需改此处  
//	 
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;			////////////更改接口需改此处      
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
//	GPIO_Init(GPIOB, &GPIO_InitStructure);			     		////////////更改接口需改此处  
//	GPIO_SetBits(GPIOB,GPIO_Pin_10 | GPIO_Pin_11);				////////////更改接口需改此处  
//}

//void B2_Init(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);	    
//	 
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;		
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
//  GPIO_Init(GPIOA, &GPIO_InitStructure);			    
//  GPIO_SetBits(GPIOA,GPIO_Pin_1);	

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;		
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
//  GPIO_Init(GPIOB, &GPIO_InitStructure);			    
//  GPIO_SetBits(GPIOB,GPIO_Pin_1);	
//}

//void B3_Init(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	   
//	 
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;			   
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
//  GPIO_Init(GPIOC, &GPIO_InitStructure);			     
//  GPIO_SetBits(GPIOC,GPIO_Pin_10 | GPIO_Pin_11);			
//}

//void B4_Init(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);	   

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;			    
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
//	GPIO_Init(GPIOC, &GPIO_InitStructure);			     
//	GPIO_SetBits(GPIOC,GPIO_Pin_12);					//输出高

//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;			    
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
//	GPIO_Init(GPIOD, &GPIO_InitStructure);			     
//	GPIO_SetBits(GPIOD,GPIO_Pin_2);					//输出高
//}

//void L1_4_Init(void)
//{ 
//	GPIO_InitTypeDef  GPIO_InitStructure;

//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	    //使能PC端口时钟
//	 
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//调用GPIO重映射函数
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;			   
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	
////  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
//  GPIO_Init(GPIOC, &GPIO_InitStructure);			    
// // GPIO_ResetBits(GPIOC,GPIO_Pin_14 | GPIO_Pin_15);		
//}

void T1_7_IN_Init(void)	//T1-T7输入
{ 
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	    //使能PC端口时钟

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//调用GPIO重映射函数

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;			   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 	
	//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);			    
	// GPIO_ResetBits(GPIOC,GPIO_Pin_14 | GPIO_Pin_15);		
}

void P5_8_IN_Init(void)	//PWM_1-4输入
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);	   

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;			    
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);			     
	GPIO_SetBits(GPIOA,GPIO_Pin_6 | GPIO_Pin_7);					//输出高

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;			    
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 	 //上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);			     
	GPIO_SetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1);					//输出高
}

