/* MATLAB GENERATED  HEADER FILE: enc1_lowpass_filter_biquad_df1.h */
#ifndef INC_ENC1_LOWPASS_FILTER_H_
#define INC_ENC1_LOWPASS_FILTER_H_

#include "arm_math.h"

#define ENC1_LOWPASS_FILTER_NUM_STAGES  1
// Filter state
extern uint32_t enc1_lowpass_filter_STATE_UINT[4*ENC1_LOWPASS_FILTER_NUM_STAGES];
// Filter coefficients
extern uint32_t enc1_lowpass_filter_COEFFS_UINT[5*ENC1_LOWPASS_FILTER_NUM_STAGES];
// Filter instance
extern arm_biquad_casd_df1_inst_f32 enc1_lowpass_filter;
#endif // INC_ENC1_LOWPASS_FILTER_H_
