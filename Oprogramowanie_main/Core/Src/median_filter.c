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

/* Private includes ----------------------------------------------------------*/
#include "median_filter.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Public function prototypes ------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/
void MEDIAN_FILTER_InsertionSort(float* arr, int size) {
    int i, j;
    float key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* Public functions ----------------------------------------------------------*/
float MEDIAN_FILTER(MEDIAN_FILTER_TypeDef* filter, float input)
{
	for(short int i = filter->window_size-2; i >= 0; i--)
		filter->buffer[i+1] = filter->buffer[i];
	filter->buffer[0] = input;

	float tmp[filter->window_size];
	for(unsigned short int i = 0; i < filter->window_size;  i++)
		tmp[i] = filter->buffer[i];

	MEDIAN_FILTER_InsertionSort(tmp, filter->window_size);

	if(filter->window_size % 2)
		return tmp[ filter->window_size/2 ];
	else
		return tmp[ filter->window_size/2 - 1 ];
}
