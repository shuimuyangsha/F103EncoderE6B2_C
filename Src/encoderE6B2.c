#include "encoderE6B2.h"
#include "main.h"

//TIM_HandleTypeDef TIM4_Handler;      //��ʱ����� 
//TIM_Encoder_InitTypeDef TIM4_Encoder_Handler;

long Interupt_Num = 0;
long Pulse_Num = 0;
float Circle_NUm = 0;
long AAA = 0;
float speed = 0;


//�ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{

	if (htim == (&htim4))
	{
		if ((TIM4->CR1 & 0x0010) == 0)  //���ϼ������  __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim4) 
		{
			Interupt_Num++;
		}
		else //���¼������
		{
			Interupt_Num--;
		}
	}
}

void Circle_Print()
{
	AAA = Pulse_Num;
	if (Interupt_Num == 0)			//CNT��1000��ʼ���տ�ʼ��ʱ���������ķ���
		Pulse_Num = TIM4->CNT - 1000;
	else
	{
		Pulse_Num = 1000 + (Interupt_Num - 1) * 2000 + TIM4->CNT; //�ڵ�һȦ���֮�󣬼�����������ķ���
	}

	speed = (Pulse_Num - AAA);
	Circle_NUm = Pulse_Num / 1560.0f; 		//�������������ϸ�����Ϳ��Եõ�ת��Ȧ��(����֮��)
	//printf("Interupt_Num��ֵ��:%ld--���񵽵�������%ld*****ת����Ȧ����%f*****��������Ϊ%f\r\n", Interupt_Num, Pulse_Num, Circle_NUm, speed);
}

