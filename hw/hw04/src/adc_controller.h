//
// Created by sabbir on 11/27/17.
//

#ifndef ADC_CONTROLLER_H
#define ADC_CONTROLLER_H


void adc_init();

void ADCStartConversion();

void ADCClearConversionFlag();

int ADCIsConversionCompleteFlagSet();

uint16_t ADCGet();

int ADCAquire();

#endif // ADC_CONTROLLER_H
