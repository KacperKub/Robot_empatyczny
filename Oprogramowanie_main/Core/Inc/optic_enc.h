/**
  ******************************************************************************
  * @file		: optic_enc.h
  * @author  	: AW		Adrian.Wojcik@put.poznan.pl
  * @version 	: 1.0.0
  * @date    	: 18 May 2023
  * @brief   	: TODO
  *
  ******************************************************************************
  */

#ifndef INC_OPTIC_ENC_H_
#define INC_OPTIC_ENC_H_

/* Public includes -----------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "arm_math.h"

/* Public typedef ------------------------------------------------------------*/
#ifdef USE_HAL_DRIVER
typedef TIM_HandleTypeDef* OPTIC_ENC_TIM_TypeDef ;
typedef uint16_t OPTIC_ENC_TIM_CH_TypeDef ;
typedef arm_biquad_casd_df1_inst_f32* OPTIC_ENC_LOWPASS_FILTER_TypeDef;
#endif

typedef struct { 
	OPTIC_ENC_TIM_TypeDef Timer;
	OPTIC_ENC_TIM_CH_TypeDef Channel;
	const uint16_t N;  //!< TODO
	float position;    //!< TODO [unit]
	float velocity;    //!< TODO [unit]
	uint32_t previous_time; //!< TODO [unit] 
	float time;
	// low pass filter
	float* state;
	float* coeff;
	uint8_t num_stages;
	float velocity_filter;
	_Bool is_running;
	OPTIC_ENC_LOWPASS_FILTER_TypeDef lowpass_filter;
	// median filter
	//OPTIC_ENC_MEDIAN_FILTER_TypeDef median_filter;

} OPTIC_ENC_TypeDef;

/* Public define -------------------------------------------------------------*/

/* Public macro --------------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief TODO 
 * @param[inout] enc : Optic encoder handler
 * @retval 0 if successes 
 *		   !=0 otherwise
 */
int OPTIC_ENC_Init(OPTIC_ENC_TypeDef* enc);

/**
 * @brief TODO 
 * @param[inout] enc : Optic encoder handler
 * @retval 0 if successes 
 *		   !=0 otherwise
 */
int OPTIC_ENC_Update(OPTIC_ENC_TypeDef* enc);

/**
 * @brief TODO 
 * @param[in] enc : Optic encoder handler
 * @retval Velocity [unit]
 */
float OPTIC_ENC_GetVelocity(/*const*/ OPTIC_ENC_TypeDef* enc);

/**
 * @brief TODO 
 * @param[in] enc : Optic encoder handler
 * @retval Position [unit]
 */
float OPTIC_ENC_GetPosition(/*const*/ OPTIC_ENC_TypeDef* enc);

#endif /* INC_OPTIC_ENC_H_ */
