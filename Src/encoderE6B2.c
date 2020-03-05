#include "encoderE6B2.h"
#include "main.h"

//TIM_HandleTypeDef TIM4_Handler;      //定时器句柄 
//TIM_Encoder_InitTypeDef TIM4_Encoder_Handler;

long Interupt_Num = 0;
long Pulse_Num = 0;
float Circle_NUm = 0;
long AAA = 0;
float speed = 0;


//回调函数，定时器中断服务函数调用
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim == (&htim4))
	{
		if ((TIM4->CR1 & 0x0010) == 0)  //向上计数溢出  __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim4) 
		{
			Interupt_Num++;
		}
		else //向下计数溢出
		{
			Interupt_Num--;
		}
	}
}

void Circle_Print()
{
	AAA = Pulse_Num;
	if (Interupt_Num == 0)			//CNT从1000开始，刚开始的时候计算脉冲的方法
		Pulse_Num = TIM4->CNT - 1000;
	else
	{
		Pulse_Num = 1000 + (Interupt_Num - 1) * 2000 + TIM4->CNT; //在第一圈完成之后，计算脉冲数多的方法
	}

	speed = (Pulse_Num - AAA);
	Circle_NUm = Pulse_Num / 1560.0f; 		//所有人脉冲除以细分数就可以得到转的圈数(正负之分)
	//printf("Interupt_Num的值是:%ld--捕获到的总数是%ld*****转过的圈数是%f*****本次脉冲为%f\r\n", Interupt_Num, Pulse_Num, Circle_NUm, speed);
}

