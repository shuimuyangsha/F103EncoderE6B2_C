#include "encoderE6B2.h"

TIM_HandleTypeDef TIM4_Handler;      //��ʱ����� 
TIM_Encoder_InitTypeDef TIM4_Encoder_Handler;

long Interupt_Num = 0;
long Pulse_Num = 0;
float Circle_NUm = 0;
long AAA = 0;
float speed = 0;


//�ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	//if (htim == (&TIM4_Handler))
	//{
	//	if ((TIM4->CR1 & 0x0010) == 0)  //���ϼ������
	//	{
	//		Interupt_Num++;
	//	}
	//	else //���¼������
	//	{
	//		Interupt_Num--;
	//	}
	//}
}

