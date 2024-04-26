/* MATLAB GENERATED SOURCE FILE: enc1_lowpass_filter_biquad_df1.c */
#include "enc1_lowpass_filter_biquad_df1.h"
// Filter state
uint32_t enc1_lowpass_filter_STATE_UINT[4*ENC1_LOWPASS_FILTER_NUM_STAGES] = {
  #include "enc1_lowpass_filter_state_init.csv"
};
// Filter coefficients
uint32_t enc1_lowpass_filter_COEFFS_UINT[5*ENC1_LOWPASS_FILTER_NUM_STAGES] = {
  #include "enc1_lowpass_filter_coeffs.csv"
};
// Filter instance
arm_biquad_casd_df1_inst_f32 enc1_lowpass_filter;
