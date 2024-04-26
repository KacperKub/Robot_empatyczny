/**
  ******************************************************************************
  * @file		: median_filter.h
  * @author  	: AW		Adrian.Wojcik@put.poznan.pl
  * @version 	: 1.0.0
  * @date    	: 18 May 2023
  * @brief   	: TODO
  *
  ******************************************************************************
  */

#ifndef INC_MEDIAN_FILTER_H_
#define INC_MEDIAN_FILTER_H_

/* Public includes -----------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/

/* Public define -------------------------------------------------------------*/
typedef struct {
	float* buffer;
	unsigned short int window_size;
} MEDIAN_FILTER_TypeDef;

/* Public macro --------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/
float MEDIAN_FILTER(MEDIAN_FILTER_TypeDef* filter, float input);


#endif /* INC_MEDIAN_FILTER_H_ */
