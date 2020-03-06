#include "encoderE6B2.h"
#include "main.h"

//TIM_HandleTypeDef TIM4_Handler;      //��ʱ����� 
//TIM_Encoder_InitTypeDef TIM4_Encoder_Handler;

long Interupt_Num = 0;
long Pulse_Num = 0;
float Circle_NUm = 0;
long AAA = 0;
float speed = 0;

float last_cnt = 0;
float current_cnt = 0;
float LineSpeed = 0;
float current_LineSpeed = 0;
float last_LineSpeed = 0;

EncoderParameterStruct encoder_parameter = {
	//���������� 1000 ���ߣ�
	//������ֱ�� 0.05 ���ף�
	//��������ֱ�� 0.130���ף�
	.DiameterWheel_A = 50,
	.DiameterWheel_B = 130,
	.PerimeterWheel_A = 0,
	.PerimeterWheel_B = 0,
	.WheelDiameterRatio = 0,

};

EncoderMeasuredResultsStruct encoder_measured_results = {0};





//�ص���������ʱ���жϷ���������
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{


	if (htim == (&htim3))
	{
		last_cnt = current_cnt;
		if (Interupt_Num == 0)			//CNT��1000��ʼ���տ�ʼ��ʱ���������ķ���
			current_cnt = TIM4->CNT ;
		else
		{
			current_cnt =  (Interupt_Num - 1) * 1000 + TIM4->CNT; //�ڵ�һȦ���֮�󣬼�����������ķ���
		}

		current_LineSpeed = (current_cnt - last_cnt)*100.0 * ((encoder_parameter.DiameterWheel_A * PI)/1000)/100;

		Circle_NUm = current_cnt / 1000.0f; 		//�������������ϸ�����Ϳ��Եõ�ת��Ȧ��(����֮��)

		encoder_measured_results.LinearVelocityWheel_A = GetLinearVelocityWheel_A();
		encoder_measured_results.AngularVelocityWheel_A = GetAngularVelocityWheel_A();
		encoder_measured_results.CycleNumberWheel_A = GetCycleNumberWheel_A();
		encoder_measured_results.LineSpeed = encoder_measured_results.LinearVelocityWheel_A;
		encoder_measured_results.mileage = Get_mileage();
	}

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

float  GetLinearVelocityWheel_A(void)
{
	float  linear_velocity;
	linear_velocity = (current_cnt - last_cnt) * 100 * ((encoder_parameter.DiameterWheel_A * PI) / 1000)/10;

	return  linear_velocity;
}

float  GetAngularVelocityWheel_A(void)
{
	float  angular_velocity;
	angular_velocity = (current_cnt - last_cnt) * 100 *(2*PI)  /1000; //��λ ��/��

	return  angular_velocity;
}

float  GetCycleNumberWheel_A(void)
{
	float  cycle_number;
	cycle_number = current_cnt / 1000;

	return cycle_number;
}

float Get_mileage(void)
{
	float mileage;
	mileage = (current_cnt / 1000) *  (encoder_parameter.DiameterWheel_A * PI) / 1000; //��С1000������λ����

	return mileage;
}





