//
// Created by sabbir on 11/27/17.
//

#ifndef ADC_CONTROLLER_H
#define ADC_CONTROLLER_H


void adc_init();

void adc_start_flag();

void adc_clear_flag();

int adc_is_set_flag();

uint16_t get_adc();

int adc_acquire();

#endif // ADC_CONTROLLER_H
