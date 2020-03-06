#ifndef ENCODERE6B2_H
#define ENCODERE6B2_H
#include "main.h"

#define PI  3.141592f

typedef struct 
{
	//Wheel_A �Ǳ��������ϵ���
	//Wheel_B ���˶��������ϵ���
	float DiameterWheel_A;
	float DiameterWheel_B;
	float PerimeterWheel_A;
	float PerimeterWheel_B;
	
	float WheelDiameterRatio; //A����B�ֵ�ֱ����
}EncoderParameterStruct;

typedef struct 
{
	float LinearVelocityWheel_A;  //
	float LinearVelocityWheel_B;
	float AngularVelocityWheel_A;
	float AngularVelocityWheel_B;
	
	float CycleNumberWheel_A;
	float CycleNumberWheel_B;
	
	float LineSpeed;
	float mileage;
}EncoderMeasuredResultsStruct;


extern TIM_HandleTypeDef TIM4_Handler;      //��ʱ����� 
extern TIM_Encoder_InitTypeDef TIM4_Encoder_Handler;

extern EncoderParameterStruct encoder_parameter;
extern EncoderMeasuredResultsStruct encoder_measured_results;

void Circle_Print();
float GetLinearVelocityWheel_A(void);
float GetAngularVelocityWheel_A(void);
float GetCycleNumberWheel_A(void);
float Get_mileage(void);

#endif // !ENCODERE6B2_H

