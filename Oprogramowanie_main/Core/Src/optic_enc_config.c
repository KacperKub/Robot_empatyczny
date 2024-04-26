/**
  ******************************************************************************
  * @file		: optic_enc_config.c
  * @author  	: AW		Adrian.Wojcik@put.poznan.pl
  * @version 	: 1.0.0
  * @date    	: 18 May 2023
  * @brief   	: TODO
  *
  ******************************************************************************
  */

/* Private includes ----------------------------------------------------------*/
#include "optic_enc.h"
#include "tim.h"
#include "enc1_lowpass_filter_biquad_df1.h"

/* Public variables ----------------------------------------------------------*/
OPTIC_ENC_TypeDef enc1 = {
	.Timer = &htim4,
	.Channel = TIM_CHANNEL_1,
	.N = 20, //!< TODO
	.position = 0.0f,   //!< TODO [unit]
	.velocity = 0.0f,   //!< TODO [unit]
	.previous_time = 0, //!< TODO [unit]
	.time = 0,
	.is_running = 0,
	.state = (float*)enc1_lowpass_filter_STATE_UINT,
	.coeff = (float*)enc1_lowpass_filter_COEFFS_UINT,
	.num_stages = ENC1_LOWPASS_FILTER_NUM_STAGES,
	.lowpass_filter = &enc1_lowpass_filter
};

