//
// Created by sabbir on 11/18/17.
//

#include <stdint.h>

void ADCSetup() {
    // AVR Butteryfly Board Info:
    // The Neg. Temp. Coeff. resistor (NTC)      is on ADC channel 0
    // The Board Edge Voltage Input Reading (VR) is on ADC channel 1
    // The Light Dependant Resistor (LDR)        is on ADC channel 2


    // Disable Digital Input Buffer on pins being used for analog input to save
    // power using the Digital Input Disable Register
    DIDR0 |= 0b00000001; //disable PF0 (ADC0) digital input buffer


    //Select Voltage Reference, Set Left-Ship Option, Set Input Channel
    int refSel_2b = 1;    //select avcc, change to 3 for 1.1V reference
    int adlar_1b = 0;     //no need to left shift
    int muxSel_5b = XYZ;  //select ADC0 with single-ended conversion
    ADMUX = (refSel_2b << REFS0) + (adlar_1b << ADLAR) + (muxSel_5b << MUX0);

    //enable adc and with interrupt disabled
    ADCSRA = (1 << ADEN) + (0 << ADSC) + (0 << ADATE) + (0 << ADIF) + (0
            << ADIE) + (0 << ADPS0);

    //Set auto conversion source
    //ADCSRB &= 0b11111000; //autoconversion (ADATAE) not set so trigger
    // source is not used
}

//Call this function to start an ADC conversion
void ADCStartConversion() {

    ADCSRA |= 1 << ADSC; //this is automatically cleared

}


void ADCClearConversionFlag() {

    ADCSRA |= (1 << ADIF); //all interrupt flags are cleared by writing a one

}

int ADCIsConversionCompleteFlagSet() {

    return (ADCSRA & (1 << ADIF));

}

// modify this command to return ADC, value.  Hint: you can access it by using
// the macro symbol ADC.  Note, if accessing the high and low bytes
// individually, access ADCL first then ADCH
uint16_t ADCGet() {

    return ADC;

}


int ADCAquire() {

    ADCClearConversionFlag();
    ADCStartConversion();
    while (!ADCIsConversionCompleteFlagSet());
    return ADCGet();

}