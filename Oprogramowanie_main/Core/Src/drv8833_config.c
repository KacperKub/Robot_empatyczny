/*
 * drv8848_config.c
 *
 *  Created on: Jan 5, 2024
 *      Author: Kacper
 */
#include <drv8833_config.h>
#include "tim.h"


DRV8833_TypeDef drv8833 = {
    .AIN_1 = PWM_INIT_HANDLE(&htim3, TIM_CHANNEL_1),
    .AIN_2 = PWM_INIT_HANDLE(&htim3, TIM_CHANNEL_2),
    .BIN_1 = PWM_INIT_HANDLE(&htim3, TIM_CHANNEL_3),
    .BIN_2 = PWM_INIT_HANDLE(&htim3, TIM_CHANNEL_4)
};
