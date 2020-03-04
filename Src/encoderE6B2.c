#include "encoderE6B2.h"

TIM_HandleTypeDef TIM4_Handler;      //定时器句柄 
TIM_Encoder_InitTypeDef TIM4_Encoder_Handler;

long Interupt_Num = 0;
long Pulse_Num = 0;
float Circle_NUm = 0;
long AAA = 0;
float speed = 0;


//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	//if (htim == (&TIM4_Handler))
	//{
	//	if ((TIM4->CR1 & 0x0010) == 0)  //向上计数溢出
	//	{
	//		Interupt_Num++;
	//	}
	//	else //向下计数溢出
	//	{
	//		Interupt_Num--;
	//	}
	//}
}

