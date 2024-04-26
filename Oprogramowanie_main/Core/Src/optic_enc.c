/**
  ******************************************************************************
  * @file		: optic_enc.c
  * @author  	: AW		Adrian.Wojcik@put.poznan.pl
  * @version 	: 1.0.0
  * @date    	: 18 May 2023
  * @brief   	: TODO
  *
  ******************************************************************************
  */

/* Private includes ----------------------------------------------------------*/
#include "optic_enc.h"

#define _USE_MATH_DEFINES
#include <math.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
/**
 * @brief TODO 
 * @param[inout] enc : Optic encoder handler
 * @retval 0 if successes 
 *		   !=0 otherwise
 */
int OPTIC_ENC_Init(OPTIC_ENC_TypeDef* enc)
{
	arm_biquad_cascade_df1_init_f32(enc->lowpass_filter, enc->num_stages, enc->coeff, enc->state);
	return HAL_TIM_IC_Start_IT(enc->Timer, enc->Channel) == HAL_OK ? 0 : -1;

}

/**
 * @brief TODO 
 * @param[inout] enc : Optic encoder handler
 * @retval 0 if successes 
 *		   !=0 otherwise
 */
int OPTIC_ENC_Update(OPTIC_ENC_TypeDef* enc)
{

	uint32_t curr_time;
	float time = 0;

	curr_time = HAL_TIM_ReadCapturedValue(enc->Timer, enc->Channel);
	uint32_t diff = curr_time - enc->previous_time;
	if(curr_time < enc->previous_time)
		diff = 0xffff - enc->previous_time + curr_time;
	time = (float) diff/HAL_RCC_GetPCLK2Freq() * enc->Timer->Init.Prescaler;

	enc->position = enc->position + 360.0f/enc->N;
	if (enc->position > 360)
		enc->position -= 360;
	enc->velocity = 360/enc->N / (time);
	enc->velocity *=  (M_PI/180) * 60 / (2*M_PI);
//	arm_biquad_cascade_df1_f32(enc->lowpass_filter, &(enc->velocity), &(enc->velocity_filter), 1);

	enc->previous_time = curr_time;

	enc->time = time;
	return 0;
}

/**
 * @brief TODO 
 * @param[in] enc : Optic encoder handler
 * @retval Velocity [unit]
 */
float OPTIC_ENC_GetVelocity(/*const*/ OPTIC_ENC_TypeDef* enc)
{
	return enc->velocity;
}

/**
 * @brief TODO 
 * @param[in] enc : Optic encoder handler
 * @retval Position [unit]
 */
float OPTIC_ENC_GetPosition(/*const*/ OPTIC_ENC_TypeDef* enc)
{
	return enc->position;
}
