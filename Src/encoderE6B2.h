#ifndef ENCODERE6B2_H
#define ENCODERE6B2_H
#include "main.h"

#define PI  3.141592f

typedef struct 
{
	//Wheel_A 是编码器轴上的轮
	//Wheel_B 是运动底盘轴上的轮
	float DiameterWheel_A;
	float DiameterWheel_B;
	float PerimeterWheel_A;
	float PerimeterWheel_B;
	
	float WheelDiameterRatio; //A轮与B轮的直径比
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


extern TIM_HandleTypeDef TIM4_Handler;      //定时器句柄 
extern TIM_Encoder_InitTypeDef TIM4_Encoder_Handler;

extern EncoderParameterStruct encoder_parameter;
extern EncoderMeasuredResultsStruct encoder_measured_results;

void Circle_Print();
float GetLinearVelocityWheel_A(void);
float GetAngularVelocityWheel_A(void);
float GetCycleNumberWheel_A(void);
float Get_mileage(void);

#endif // !ENCODERE6B2_H

